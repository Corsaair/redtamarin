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

%%component mmgc
%%category weakref

%%prefix
using namespace MMgc;

class C : public GCFinalizedObject
{
public:
    C(int key) : key(key) {}
    ~C() { key = -1; }
    int key;
    DWB(C*) next;
};

class MyCallback : public GCCallback
{
public:
    MyCallback(GC* gc, GCWeakRef** refs, C** objs, int n)
        : GCCallback(gc)
        , refs(refs)
        , objs(objs)
        , n(n)
    {
    }

    virtual void presweep() {
	for ( int i=1 ; i < 1000 ; i+=2 )
        objs[i]->next = (C*)(void *)(refs[i-1]->get());
    }

private:
    GCWeakRef** refs;
    C** objs;
    int n;
};

%%test unmarked_object

  // Bugzilla 572331 - it's possible for a weak reference to yield up a pointer to an unmarked
  // object in a presweep handler, and for that pointer to be stored into the heap even with
  // a WB macro, without the barrier triggering.

{
    GC* gc = core->gc;

    // Stack allocated storage, so automatically these arrays are roots

    GCWeakRef* refs[1000];
    C* objs[1000];

    // Create weak and strong references to 1000 objects

    for ( int i=0 ; i < 1000 ; i++ ) {
        objs[i] = new (gc) C(i);
        refs[i] = objs[i]->GetWeakRef();
    }

    // Get the collector into a reasonable state.

    gc->Collect();
    gc->Collect();

    // Remove the even-numbered strong refs.

    for ( int i=0 ; i < 1000 ; i+=2 )
        objs[i] = NULL;

    // Introduce mischief.  The presweep callback will extract
    // pointers from the even-numbered weak refs and insert them into
    // the objects in the odd-numbered slots (which are strongly
    // held).  Most of the objects referenced from the even-numbered
    // weak refs should be weakly held and unmarked.  We hope to catch
    // the collector picking up an unmarked object.

    MyCallback* cb = new MyCallback(gc, refs, objs, 1000);

    // Now trigger the collector again.

    gc->Collect();

    // Prevent more mischief from happening.

    delete cb;

    // Now reference all the odd-numbered objects and check the
    // integrity of their 'next' objects.  There's a chance this may
    // crash.

    for ( int i=1 ; i < 1000 ; i+= 2 ) {
        %%verify objs[i]->next->key == i-1
    }

    // Clean up
    VMPI_memset(refs, 0, sizeof(refs));
    VMPI_memset(objs, 0, sizeof(objs));
}
