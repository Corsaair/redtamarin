// Generated from ST_mmgc_543560.st
// -*- mode: c; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*-
// vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
//
// ***** BEGIN LICENSE BLOCK *****
// Version: MPL 1.1/GPL 2.0/LGPL 2.1
//
// The contents of this file are subject to the Mozilla Public License Version
// 1.1 (the "License"); you may not use this file except in compliance with
// the License. You may obtain a copy of the License at
// http://www.mozilla.org/MPL/
//
// Software distributed under the License is distributed on an "AS IS" basis,
// WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
// for the specific language governing rights and limitations under the
// License.
//
// The Original Code is [Open Source Virtual Machine.].
//
// The Initial Developer of the Original Code is
// Adobe System Incorporated.
// Portions created by the Initial Developer are Copyright (C) 2004-2006
// the Initial Developer. All Rights Reserved.
//
// Contributor(s):
//   Adobe AS3 Team
//
// Alternatively, the contents of this file may be used under the terms of
// either the GNU General Public License Version 2 or later (the "GPL"), or
// the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
// in which case the provisions of the GPL or the LGPL are applicable instead
// of those above. If you wish to allow use of your version of this file only
// under the terms of either the GPL or the LGPL, and not to allow others to
// use your version of this file under the terms of the MPL, indicate your
// decision by deleting the provisions above and replace them with the notice
// and other provisions required by the GPL or the LGPL. If you do not delete
// the provisions above, a recipient may use your version of this file under
// the terms of any one of the MPL, the GPL or the LGPL.
//
// ***** END LICENSE BLOCK ***** */

// Bugzilla 543560 - here we risk deleting an object that is still on the mark stack because
// of how we perform large-object splitting.  The setup is that user code that deletes the object
// gets to run after the first part of the large object has been popped off the mark stack
// but before the rest has been handled.

#include "avmshell.h"
#ifdef VMCFG_SELFTEST
#if defined AVMPLUS_WIN32
#if !defined VMCFG_ARM
namespace avmplus {
class ST_mmgc_bugzilla_543560 : public Selftest {
public:
ST_mmgc_bugzilla_543560(AvmCore* core);
virtual void run(int n);
virtual void prologue();
virtual void epilogue();
private:
static const char* ST_names[];
static const bool ST_explicits[];
void test0();
private:
    MMgc::GC *gc;

};
ST_mmgc_bugzilla_543560::ST_mmgc_bugzilla_543560(AvmCore* core)
    : Selftest(core, "mmgc", "bugzilla_543560", ST_mmgc_bugzilla_543560::ST_names,ST_mmgc_bugzilla_543560::ST_explicits)
{}
const char* ST_mmgc_bugzilla_543560::ST_names[] = {"bugzilla_543560", NULL };
const bool ST_mmgc_bugzilla_543560::ST_explicits[] = {false, false };
void ST_mmgc_bugzilla_543560::run(int n) {
switch(n) {
case 0: test0(); return;
}
}
void ST_mmgc_bugzilla_543560::prologue() {
    gc = new MMgc::GC(MMgc::GCHeap::GetGCHeap(), MMgc::GC::kIncrementalGC);

}
void ST_mmgc_bugzilla_543560::epilogue() {
    delete gc;

}
using namespace MMgc;

// allocate a bunch big things
// allocate a bunch of small things  ( to pump incremental mark.... )
// explicitly free one of the big things
// ... crash

struct BigThing;

static inline unsigned getSerial()
{
    static unsigned g_counter = 0;
    unsigned result = g_counter;
    ++g_counter;
    return result;
}

struct BigThing : public MMgc::GCFinalizedObject
{
    BigThing() : m_next(0), m_prev(0), m_serial(getSerial())
    {
        VMPI_memset(&m_data, 0, sizeof(m_data));
    }

    virtual ~BigThing()
    {
        //printf("~BigThing: %u 0x%08X 0x%08X\n", m_serial, this, this + 1);
    }
    DWB(BigThing*) m_next;
    DWB(BigThing*) m_prev;
    unsigned m_serial;
    char m_data[512 * 1024];
};

BigThing* makeBigThings(MMgc::GC* gc, size_t howMany)
{
    BigThing* first = 0;
    BigThing* curr = 0;
    for (unsigned i = 0; i < howMany; ++i) {
        BigThing* newThing = new (gc) BigThing();
        if (!first) {
            first = newThing;
        }
        else {
            curr->m_next = newThing;
            newThing->m_prev = curr;
        }
        curr = newThing;
    }
    return first;
}

struct SmallThing : public MMgc::GCFinalizedObject
{
    char m_data[200];
    virtual ~SmallThing()
    {
    }
};

struct MyRoot : public MMgc::GCRoot
{
    MyRoot(MMgc::GC* gc) : MMgc::GCRoot(gc) {}
    BigThing* m_bigThings;
};

void ST_mmgc_bugzilla_543560::test0() {
    MMGC_GCENTER(gc);

    MyRoot* theRoot = 0;
    {
        BigThing* volatile bigThings = makeBigThings(gc, 400);
        theRoot = new MyRoot(gc);
        theRoot->m_bigThings = bigThings;
    }
    BigThing* volatile middle = theRoot->m_bigThings;
    for (int j = 0 ; j < 150; ++j)
        middle = middle->m_next;

    middle->m_prev->m_next = 0;
    for (int j = 0; j < 50; ++j)
        middle = middle->m_next;

    middle->m_prev = 0;
    gc->Collect();
    gc->Collect();

    for (int j = 0; j < 100000; ++j) {
        //printf("j: %d\n", j);
        for (int i = 0; i < 500; ++i) {
            new (gc) SmallThing();
            if ((theRoot->m_bigThings) && (MMgc::GC::GetMark(theRoot->m_bigThings))) {
                while (theRoot->m_bigThings != 0) {
                    BigThing* curr = theRoot->m_bigThings;
                    theRoot->m_bigThings = theRoot->m_bigThings->m_next;
                    delete curr;
                }
                MMgc::GCHeap::GetGCHeap()->Decommit();
            }
        }

    }
    delete theRoot;

    // Will crash if it fails so the %%verify is just token
#line 167 "ST_mmgc_543560.st"
verifyPass(true, "true", __FILE__, __LINE__);

}
void create_mmgc_bugzilla_543560(AvmCore* core) { new ST_mmgc_bugzilla_543560(core); }
}
#endif
#endif
#endif
