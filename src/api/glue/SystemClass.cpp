/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "avmshell.h"

namespace avmshell
{

    SystemClass::SystemClass(VTable *cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    SystemClass::~SystemClass()
    {
        
    }

    double SystemClass::get_totalMemory()
    {
        MMgc::GCHeap* gcheap = MMgc::GCHeap::GetGCHeap();
        // Bugzilla 678975: use GetUsedHeapSize for compatibility with Player
        return double(gcheap->GetUsedHeapSize() * MMgc::GCHeap::kBlockSize);
    }

    double SystemClass::get_freeMemory()
    {
        MMgc::GCHeap* gcheap = MMgc::GCHeap::GetGCHeap();
        return double(gcheap->GetFreeHeapSize() * MMgc::GCHeap::kBlockSize);
    }

    double SystemClass::get_privateMemory()
    {
        return double(AVMPI_getPrivateResidentPageCount() * VMPI_getVMPageSize());
    }


}
