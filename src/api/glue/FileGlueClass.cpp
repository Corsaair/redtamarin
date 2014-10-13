/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "avmshell.h"

namespace avmshell
{

    FileGlueClass::FileGlueClass(VTable* cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    FileGlueClass::~FileGlueClass()
    {
        
    }

    bool FileGlueClass::isDummy()
    {
        return true;
    }




    FileGlueObject::FileGlueObject(VTable* vtable, ScriptObject* prototype)
        : ScriptObject(vtable, prototype)
    {}

    FileGlueObject::~FileGlueObject()
    {
        //nothing to destroy
    }

    bool FileGlueObject::isLocalDummy()
    {
        return true;
    }

}
