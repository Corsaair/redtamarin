// Generated from ST_mmgc_dependent.st
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
namespace avmplus {
using namespace MMgc;

static const size_t nbytes = 16*1024*1024;

class DependentAllocHolder : public GCFinalizedObject {
public:

  DependentAllocHolder() {
    memory = (char*)FixedMalloc::GetFixedMalloc()->Alloc(nbytes);
    GC::GetGC(this)->SignalDependentAllocation(nbytes);
  }

  virtual ~DependentAllocHolder() {
    FixedMalloc::GetFixedMalloc()->Free(memory);
    memory = NULL;
    GC::GetGC(this)->SignalDependentDeallocation(nbytes);
  }
  private:
    char* memory;
};

class ST_mmgc_dependent : public Selftest {
public:
ST_mmgc_dependent(AvmCore* core);
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
ST_mmgc_dependent::ST_mmgc_dependent(AvmCore* core)
    : Selftest(core, "mmgc", "dependent", ST_mmgc_dependent::ST_names,ST_mmgc_dependent::ST_explicits)
{}
const char* ST_mmgc_dependent::ST_names[] = {"dependent_alloc", NULL };
const bool ST_mmgc_dependent::ST_explicits[] = {false, false };
void ST_mmgc_dependent::run(int n) {
switch(n) {
case 0: test0(); return;
}
}
void ST_mmgc_dependent::prologue() {
    gc = new GC(GCHeap::GetGCHeap(), GC::kIncrementalGC);

}
void ST_mmgc_dependent::epilogue() {
    delete gc;

}
void ST_mmgc_dependent::test0() {
    size_t maxheap = 0;
    {
        MMGC_GCENTER(gc);

        int count = 100;
        for (int c=0; c<count; c++) {
            (void)(new (gc) DependentAllocHolder());
            size_t heapsize = gc->policy.blocksOwnedByGC() * GCHeap::kBlockSize;
            // printf("%lu\n", (unsigned long)heapsize);
            if (heapsize > maxheap)
                maxheap = heapsize;
        }
    }

    // This is tricky to get right but for this test the 16MB blocks will dominate
    // completely.  So assume that heap size must stay below L*2*16MB for the
    // L that applies at 32MB.

#line 100 "ST_mmgc_dependent.st"
verifyPass(size_t(gc->policy.queryLoadForHeapsize(double(2*nbytes)) * 2.0 * double(nbytes)) >= maxheap, "size_t(gc->policy.queryLoadForHeapsize(double(2*nbytes)) * 2.0 * double(nbytes)) >= maxheap", __FILE__, __LINE__);


}
void create_mmgc_dependent(AvmCore* core) { new ST_mmgc_dependent(core); }
}
#endif
