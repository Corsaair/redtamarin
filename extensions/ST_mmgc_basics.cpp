// Generated from ST_mmgc_basics.st
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

#include "avmshell.h"
#ifdef VMCFG_SELFTEST
namespace avmplus {
class ST_mmgc_basics : public Selftest {
public:
ST_mmgc_basics(AvmCore* core);
virtual void run(int n);
virtual void prologue();
virtual void epilogue();
private:
static const char* ST_names[];
static const bool ST_explicits[];
void test0();
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();
void test8();
void test9();
void test10();
void test11();
void test12();
void test13();
void test14();
private:
    MMgc::GC *gc;
    MMgc::FixedAlloc *fa;
    MMgc::FixedMalloc *fm;

};
ST_mmgc_basics::ST_mmgc_basics(AvmCore* core)
    : Selftest(core, "mmgc", "basics", ST_mmgc_basics::ST_names,ST_mmgc_basics::ST_explicits)
{}
const char* ST_mmgc_basics::ST_names[] = {"create_gc_instance","create_gc_object","get_bytesinuse","collect","getgcheap","fixedAlloc","fixedMalloc","gcheap","gcheapAlign","gcmethods","finalizerAlloc","finalizerDelete","nestedGCs","collectDormantGC","regression_551169", NULL };
const bool ST_mmgc_basics::ST_explicits[] = {false,false,false,false,false,false,false,false,false,false,false,false,false,false,false, false };
void ST_mmgc_basics::run(int n) {
switch(n) {
case 0: test0(); return;
case 1: test1(); return;
case 2: test2(); return;
case 3: test3(); return;
case 4: test4(); return;
case 5: test5(); return;
case 6: test6(); return;
case 7: test7(); return;
case 8: test8(); return;
case 9: test9(); return;
case 10: test10(); return;
case 11: test11(); return;
case 12: test12(); return;
case 13: test13(); return;
case 14: test14(); return;
}
}
void ST_mmgc_basics::prologue() {
    gc=new MMgc::GC(MMgc::GCHeap::GetGCHeap(), MMgc::GC::kIncrementalGC);
    if (gc==NULL) {
        MMgc::GCHeap::Init();
        gc=new MMgc::GC(MMgc::GCHeap::GetGCHeap(), MMgc::GC::kIncrementalGC);
    }

}
void ST_mmgc_basics::epilogue() {
delete gc;

}
using namespace MMgc;
class DeleteInFinalizer : public GCFinalizedObject {
 public:
  // note "small" is a reserved identifier in Visual C++ for Windows Mobile (#defined to be 'char')
  DeleteInFinalizer(GCFinalizedObject *big, GCFinalizedObject *small_) : big(big), small_(small_) {};
  ~DeleteInFinalizer() { delete big; delete small_; }
 private:
  GCFinalizedObject *big;
  GCFinalizedObject *small_;
};

// Any small object would do
class AllocInFinalizer2 : public GCObject {
public:
    void* dummy;
};

class AllocInFinalizer : public GCFinalizedObject {
public:
    AllocInFinalizer() {}
    ~AllocInFinalizer() { new (GC::GetGC(this)) AllocInFinalizer2(); }
};

void ST_mmgc_basics::test0() {
#line 85 "ST_mmgc_basics.st"
verifyPass(gc != NULL, "gc != NULL", __FILE__, __LINE__);

}
void ST_mmgc_basics::test1() {
    MMGC_GCENTER(gc);
    MyGCObject *mygcobject;
    mygcobject = (MyGCObject *)new (gc) MyGCObject();
#line 91 "ST_mmgc_basics.st"
verifyPass(mygcobject!=NULL, "mygcobject!=NULL", __FILE__, __LINE__);
    mygcobject->i=10;
#line 93 "ST_mmgc_basics.st"
verifyPass(mygcobject->i==10, "mygcobject->i==10", __FILE__, __LINE__);

}
void ST_mmgc_basics::test2() {
    MMGC_GCENTER(gc);
    MyGCObject *mygcobject;
    int inuse=(int)gc->GetBytesInUse();
    mygcobject = (MyGCObject *)new (gc) MyGCObject();
//    AvmLog("bytes in use before %d after %d\n",inuse,(int)gc->GetBytesInUse());
#line 101 "ST_mmgc_basics.st"
verifyPass(gc->GetBytesInUse()==inuse + sizeof(MyGCObject) + DebugSize(), "gc->GetBytesInUse()==inuse + sizeof(MyGCObject) + DebugSize()", __FILE__, __LINE__);
    delete mygcobject;

}
void ST_mmgc_basics::test3() {
    MMGC_GCENTER(gc);
    MyGCObject *mygcobject;
    int inuse=(int)gc->GetBytesInUse();
    mygcobject = (MyGCObject *)new (gc) MyGCObject();
#line 109 "ST_mmgc_basics.st"
verifyPass((int)gc->GetBytesInUse()>inuse, "(int)gc->GetBytesInUse()>inuse", __FILE__, __LINE__);
    delete mygcobject;
//    AvmLog("collect: inuse=%d current=%d\n",inuse,(int)gc->GetBytesInUse());
    gc->Collect();
//    AvmLog("collect: inuse=%d current=%d\n",inuse,(int)gc->GetBytesInUse());
#line 114 "ST_mmgc_basics.st"
verifyPass((int)gc->GetBytesInUse()<=inuse, "(int)gc->GetBytesInUse()<=inuse", __FILE__, __LINE__);

}
void ST_mmgc_basics::test4() {
#line 117 "ST_mmgc_basics.st"
verifyPass(gc->GetGCHeap()!=NULL, "gc->GetGCHeap()!=NULL", __FILE__, __LINE__);

}
void ST_mmgc_basics::test5() {
    MMgc::FixedAlloc *fa;
    fa=new MMgc::FixedAlloc(2048,MMgc::GCHeap::GetGCHeap());
#line 122 "ST_mmgc_basics.st"
verifyPass((int)fa->GetMaxAlloc()==0, "(int)fa->GetMaxAlloc()==0", __FILE__, __LINE__);
#line 123 "ST_mmgc_basics.st"
verifyPass((int)fa->GetNumBlocks()==0, "(int)fa->GetNumBlocks()==0", __FILE__, __LINE__);
    void *data1=fa->Alloc(2048);
#line 125 "ST_mmgc_basics.st"
verifyPass(MMgc::FixedAlloc::GetFixedAlloc(data1)==fa, "MMgc::FixedAlloc::GetFixedAlloc(data1)==fa", __FILE__, __LINE__);
#line 126 "ST_mmgc_basics.st"
verifyPass(fa->GetBytesInUse()==DebugSize()+2048, "fa->GetBytesInUse()==DebugSize()+2048", __FILE__, __LINE__);
#line 127 "ST_mmgc_basics.st"
verifyPass(fa->GetItemSize()==2048, "fa->GetItemSize()==2048", __FILE__, __LINE__);
    void *data2=fa->Alloc(2048);
#line 129 "ST_mmgc_basics.st"
verifyPass(MMgc::FixedAlloc::GetFixedAlloc(data2)==fa, "MMgc::FixedAlloc::GetFixedAlloc(data2)==fa", __FILE__, __LINE__);
//    AvmLog("fa->GetItemSize=%d\n",(int)fa->GetItemSize());
#line 131 "ST_mmgc_basics.st"
verifyPass((int)fa->GetItemSize()==2048, "(int)fa->GetItemSize()==2048", __FILE__, __LINE__);
    fa->Free(data1);
#line 133 "ST_mmgc_basics.st"
verifyPass((int)fa->GetItemSize()==2048, "(int)fa->GetItemSize()==2048", __FILE__, __LINE__);
#line 134 "ST_mmgc_basics.st"
verifyPass((int)fa->GetMaxAlloc()==1, "(int)fa->GetMaxAlloc()==1", __FILE__, __LINE__);
#line 135 "ST_mmgc_basics.st"
verifyPass((int)fa->GetNumBlocks()==1, "(int)fa->GetNumBlocks()==1", __FILE__, __LINE__);
    fa->Free(data2);
    delete fa;

}
void ST_mmgc_basics::test6() {
    fm=MMgc::FixedMalloc::GetFixedMalloc();
    int start=(int)fm->GetBytesInUse();
    int starttotal=(int)fm->GetTotalSize();
//    AvmLog("fm->GetBytesInUse()=%d\n",(int)fm->GetBytesInUse());
#line 144 "ST_mmgc_basics.st"
verifyPass((int)fm->GetBytesInUse()==start, "(int)fm->GetBytesInUse()==start", __FILE__, __LINE__);
//    AvmLog("fm->GetTotalSize()=%d\n",(int)fm->GetTotalSize());
#line 146 "ST_mmgc_basics.st"
verifyPass((int)fm->GetTotalSize()==starttotal, "(int)fm->GetTotalSize()==starttotal", __FILE__, __LINE__);
    void *obj=fm->Alloc(8192);
//    AvmLog("fm->GetBytesInUse()=%d\n",(int)fm->GetBytesInUse());
//    %%verify fm->GetBytesInUse()==start + 8192 + MMgc::DebugSize()
//    AvmLog("fm->GetTotalSize()=%d\n",(int)fm->GetTotalSize());
//    %%verify (int)fm->GetTotalSize()==starttotal+2
    fm->Free(obj);
//    AvmLog("fm->GetBytesInUse()=%d\n",(int)fm->GetBytesInUse());
#line 154 "ST_mmgc_basics.st"
verifyPass((int)fm->GetBytesInUse()==start, "(int)fm->GetBytesInUse()==start", __FILE__, __LINE__);
//    AvmLog("fm->GetTotalSize()=%d\n",(int)fm->GetTotalSize());
#line 156 "ST_mmgc_basics.st"
verifyPass((int)fm->GetTotalSize()==starttotal, "(int)fm->GetTotalSize()==starttotal", __FILE__, __LINE__);
    obj=fm->Calloc(1024,10);
//    AvmLog("fm->GetBytesInUse()=%d\n",(int)fm->GetBytesInUse());
// FixedMalloc is currently (as of redux 3229) tracking large allocs using a list of
// small objects, in some debug modes.  So we can't have a precise test here.
#line 161 "ST_mmgc_basics.st"
verifyPass((int)fm->GetBytesInUse()>=start+1024*12 && (int)fm->GetBytesInUse()<=start+1024*12+64, "(int)fm->GetBytesInUse()>=start+1024*12 && (int)fm->GetBytesInUse()<=start+1024*12+64", __FILE__, __LINE__);
//    AvmLog("fm->GetTotalSize()=%d\n",(int)fm->GetTotalSize());
#line 163 "ST_mmgc_basics.st"
verifyPass((int)fm->GetTotalSize()==starttotal+3, "(int)fm->GetTotalSize()==starttotal+3", __FILE__, __LINE__);
    fm->Free(obj);
#line 165 "ST_mmgc_basics.st"
verifyPass((int)fm->GetBytesInUse()==start, "(int)fm->GetBytesInUse()==start", __FILE__, __LINE__);
#line 166 "ST_mmgc_basics.st"
verifyPass((int)fm->GetTotalSize()==starttotal, "(int)fm->GetTotalSize()==starttotal", __FILE__, __LINE__);

}
void ST_mmgc_basics::test7() {
    MMgc::GCHeap *gh=MMgc::GCHeap::GetGCHeap();
    int startfreeheap=(int)gh->GetFreeHeapSize();
//    %%verify (int)gh->GetTotalHeapSize()==128
//    AvmLog("gh->GetFreeHeapSize()=%d\n",(int)gh->GetFreeHeapSize());
#line 173 "ST_mmgc_basics.st"
verifyPass((int)gh->GetFreeHeapSize()==startfreeheap, "(int)gh->GetFreeHeapSize()==startfreeheap", __FILE__, __LINE__);
//gh->Config().heapLimit = 1024;
//    %%verify (int)gh->GetTotalHeapSize()==128
//    AvmLog("gh->GetFreeHeapSize()=%d\n",(int)gh->GetFreeHeapSize());
#line 177 "ST_mmgc_basics.st"
verifyPass((int)gh->GetFreeHeapSize()==startfreeheap, "(int)gh->GetFreeHeapSize()==startfreeheap", __FILE__, __LINE__);
       void *data = gh->Alloc(10,MMgc::GCHeap::kExpand | MMgc::GCHeap::kZero);
#line 179 "ST_mmgc_basics.st"
verifyPass((int)gh->GetTotalHeapSize()>startfreeheap, "(int)gh->GetTotalHeapSize()>startfreeheap", __FILE__, __LINE__);
//    AvmLog("gh->GetFreeHeapSize()=%d\n",(int)gh->GetFreeHeapSize());
	   gh->FreeNoProfile(data);
       
}
void ST_mmgc_basics::test8() {
    MMgc::GCHeap *gh=MMgc::GCHeap::GetGCHeap();

    // Tricky: try to provoke some internal asserts
    void *d[1000];
    for ( unsigned i=0 ; i < ARRAY_SIZE(d) ; i++ ) {
        d[i] = gh->Alloc(1);
        void *data = gh->Alloc(10,MMgc::GCHeap::flags_Alloc, 4);
        gh->Free(data);
    }
    for ( unsigned i=0 ; i < ARRAY_SIZE(d) ; i++ )
        gh->Free(d[i]);

    // 
    for ( size_t k=2 ; k <= 256 ; k *= 2 ) {
        void *data = gh->Alloc(10,MMgc::GCHeap::flags_Alloc, k);
#line 199 "ST_mmgc_basics.st"
verifyPass(((uintptr_t)data & (k*MMgc::GCHeap::kBlockSize - 1)) == 0, "((uintptr_t)data & (k*MMgc::GCHeap::kBlockSize - 1)) == 0", __FILE__, __LINE__);
#line 200 "ST_mmgc_basics.st"
verifyPass(gh->Size(data) == 10, "gh->Size(data) == 10", __FILE__, __LINE__);
        gh->Free(data);
    }

}
void ST_mmgc_basics::test9() {
    MMGC_GCENTER(gc);
    MyGCObject *mygcobject;
    mygcobject = (MyGCObject *)new (gc) MyGCObject();
#line 208 "ST_mmgc_basics.st"
verifyPass((MyGCObject *)gc->FindBeginningGuarded(mygcobject)==mygcobject, "(MyGCObject *)gc->FindBeginningGuarded(mygcobject)==mygcobject", __FILE__, __LINE__);
#line 209 "ST_mmgc_basics.st"
verifyPass((MyGCObject *)gc->FindBeginningFast(mygcobject)==mygcobject, "(MyGCObject *)gc->FindBeginningFast(mygcobject)==mygcobject", __FILE__, __LINE__);

// Bugzilla 542529 - in debug mode we would assert here due to logic flaws in the allocatr
}
void ST_mmgc_basics::test10() {
    MMGC_GCENTER(gc);
    new (gc) AllocInFinalizer();
    gc->Collect(false);
#line 216 "ST_mmgc_basics.st"
verifyPass(true, "true", __FILE__, __LINE__);

}
void ST_mmgc_basics::test11() {
    MMGC_GCENTER(gc);
    new (gc) DeleteInFinalizer(new (gc, 100) GCFinalizedObject(), new (gc) GCFinalizedObject());
    //delete m; delete m; // this verifies we crash, it does
    gc->Collect(false);
#line 223 "ST_mmgc_basics.st"
verifyPass(true, "true", __FILE__, __LINE__);
    GCFinalizedObject *gcfo = new (gc) GCFinalizedObject();
    gcfo->~GCFinalizedObject();
    gcfo->~GCFinalizedObject(); // this used to be a deleteing dtor and would crash, not anymore



}
void ST_mmgc_basics::test12() {
    GC *gcb = new GC(GCHeap::GetGCHeap(), GC::kIncrementalGC);
    MMGC_GCENTER(gc);
    void *a = gc->Alloc(8);
    {
        MMGC_GCENTER(gcb);
        a = gcb->Alloc(8);
        {
            MMGC_GCENTER(gc);
            a = gc->Alloc(8);
        }
        a = gcb->Alloc(8);
    }
    a = gc->Alloc(8);
    // just fishing for asserts/hangs/crashes
#line 245 "ST_mmgc_basics.st"
verifyPass(true, "true", __FILE__, __LINE__);
    delete gcb;

}
void ST_mmgc_basics::test13() {
    {
        GC *gcb = new GC(GCHeap::GetGCHeap(), GC::kIncrementalGC);
        {
            MMGC_GCENTER(gcb);
            gcb->Alloc(8);
        }

        // this will cause a Collection in gcb
        GCHeap::SignalExternalFreeMemory();
        delete gcb;

        // just fishing for asserts/hangs/crashes
#line 261 "ST_mmgc_basics.st"
verifyPass(true, "true", __FILE__, __LINE__);
    }

}
void ST_mmgc_basics::test14() {
    {
        GC *testGC = new GC(GCHeap::GetGCHeap(), GC::kIncrementalGC);
        {
            MMGC_GCENTER(testGC);
            testGC->StartIncrementalMark();
            // self test for tricky GCRoot deletion logic
            // do this a bunch, idea is to try to hit GetItemAbove border edge cases
            for(int i=0;i<10000;i++) {
                GCRoot *fauxRoot = new GCRoot(testGC, new char[GC::kMarkItemSplitThreshold*2], GC::kMarkItemSplitThreshold*2);
                testGC->MarkAllRoots();
                // tail of fauxRoot is on stack
                GCWorkItem *sentinel = fauxRoot->GetMarkStackSentinelPointer();
                if(sentinel) {
#line 278 "ST_mmgc_basics.st"
verifyPass(sentinel->GetSentinelPointer() == fauxRoot, "sentinel->GetSentinelPointer() == fauxRoot", __FILE__, __LINE__);
                    GCWorkItem *tail = testGC->m_incrementalWork.GetItemAbove(sentinel);
#line 280 "ST_mmgc_basics.st"
verifyPass(tail->iptr + tail->GetSize() == (uintptr_t) fauxRoot->End(), "tail->iptr + tail->GetSize() == (uintptr_t) fauxRoot->End()", __FILE__, __LINE__);
#line 281 "ST_mmgc_basics.st"
verifyPass(sentinel != NULL, "sentinel != NULL", __FILE__, __LINE__);
                }
                delete [] (char*)fauxRoot->Get();
                delete fauxRoot;
                if(sentinel) {
#line 286 "ST_mmgc_basics.st"
verifyPass(sentinel->GetSentinel1Type() == GCWorkItem::kDeadItem, "sentinel->GetSentinel1Type() == GCWorkItem::kDeadItem", __FILE__, __LINE__);
#line 287 "ST_mmgc_basics.st"
verifyPass(testGC->m_incrementalWork.GetItemAbove(sentinel)->GetSentinel1Type() == GCWorkItem::kDeadItem, "testGC->m_incrementalWork.GetItemAbove(sentinel)->GetSentinel1Type() == GCWorkItem::kDeadItem", __FILE__, __LINE__);
                }
            }
            testGC->Mark();
            testGC->ClearMarkStack();
            testGC->ClearMarks();
        }
        delete testGC;
    }

}
void create_mmgc_basics(AvmCore* core) { new ST_mmgc_basics(core); }
}
#endif
