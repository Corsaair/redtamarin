// Generated from ST_mmgc_575631.st
// -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*-
// vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5)
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

// Bugzilla 565631 - We occasionally interleave invoking finalizers
// and clearing mark bits in GCAlloc::Finalize; so a finalizer can
// observe a live object that does not have its mark bit set.
//
// This complicates things because we want to ensure that unmarked
// weakly-referenced objects are resurrected by the GC if the weak
// reference is dereferenced during presweep, but we do not want to
// schedule collection work (or set bits that are supposed to be
// unmarked) during finalization.
//
// (Long term we might want to get rid of the interleaving of
// finalization and mark-bit clearing.  Short term, lets just
// try to detect this on our own.)

#include "avmshell.h"
#ifdef VMCFG_SELFTEST
namespace avmplus {
using namespace MMgc;

// Upon destruction, start reading weak refs of "friends" near and far
class Snoopy : public GCFinalizedObject
{
public:
    Snoopy(int key, GCWeakRef** refs, int len)
        : key(key), friends(refs), len(len)
    {
        ++alive_count;
    }
    ~Snoopy();
    static int alive_count;
private:
    int key;
    GCWeakRef** friends;
    int len;
};

// To take D samples from an array of N elems, walk thru by floor(N/D)
// steps (but avoid the pathological case when the floor is zero).
int compute_stride(int numerator, int denominator)
{
    int delta = numerator / denominator;
    return (delta > 0) ? delta : 1;
}

class ST_mmgc_bugzilla_575631 : public Selftest {
public:
ST_mmgc_bugzilla_575631(AvmCore* core);
virtual void run(int n);
private:
static const char* ST_names[];
static const bool ST_explicits[];
void test0();
// collecting twice is only "sure" way to gc in presence of incrementality
void collect2() { core->gc->Collect(); core->gc->Collect(); }

};
ST_mmgc_bugzilla_575631::ST_mmgc_bugzilla_575631(AvmCore* core)
    : Selftest(core, "mmgc", "bugzilla_575631", ST_mmgc_bugzilla_575631::ST_names,ST_mmgc_bugzilla_575631::ST_explicits)
{}
const char* ST_mmgc_bugzilla_575631::ST_names[] = {"drizzle", NULL };
const bool ST_mmgc_bugzilla_575631::ST_explicits[] = {false, false };
void ST_mmgc_bugzilla_575631::run(int n) {
switch(n) {
case 0: test0(); return;
}
}

/*static*/ int Snoopy::alive_count = 0;

const int arr_len = 1000;
const int lookups_per_destruct = 10;
const int destructs = 10;
Snoopy::~Snoopy()
{
    int delta = compute_stride(arr_len, lookups_per_destruct);

    for ( int i = 1 ; i < arr_len ; i += delta ) {
        int idx = (key + i) % len;
        // printf("referencing ref[%d] from Snoopy(%d)\n", idx, key);
        friends[idx]->get();
    }
    --alive_count;
}

void ST_mmgc_bugzilla_575631::test0() {
{
    GC* gc = core->gc;

    Snoopy* objs[arr_len];
    GCWeakRef* refs[arr_len];

    // initial setup:
    for (int i=0 ; i < arr_len; ++i ) {
        objs[i] = new (gc) Snoopy(i, refs, arr_len);
        refs[i] = objs[i]->GetWeakRef();
    }

    collect2();

    int delta = compute_stride(arr_len, destructs);

    for (int i=0; i < arr_len; i += delta) {
        objs[i] = NULL;
        collect2();
    }

    // not assert failing within get() is passing the test.
#line 132 "ST_mmgc_575631.st"
verifyPass(1, "1", __FILE__, __LINE__);
          ; // (make my auto-indenter happy)

    // cleanup code; letting ~Snoopy occur outside test extent is big no-no.
    {
        for (int i=0; i < arr_len; ++i ) {
            if (! refs[i]->isNull())
                delete objs[i];
        }

        // if something went wrong above and some Snoopy's are still alive,
        // we'll get burned during their destructors.  Make sure that
        // does not happen.
#line 145 "ST_mmgc_575631.st"
verifyPass((Snoopy::alive_count == 0), "(Snoopy::alive_count == 0)", __FILE__, __LINE__);
              ;
    }
}

}
void create_mmgc_bugzilla_575631(AvmCore* core) { new ST_mmgc_bugzilla_575631(core); }
}
#endif
