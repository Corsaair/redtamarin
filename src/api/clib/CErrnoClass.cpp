/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "avmshell.h"

namespace avmshell
{

    CErrnoClass::CErrnoClass(VTable *cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    CErrnoClass::~CErrnoClass()
    {
        
    }

    /*void CErrnoClass::dummy()
    {
        //do nothing, create a dummy slot
    }*/

    /*static*/ int CErrnoClass::_GetErrno(ScriptObject*)
    {
        //return errno;
        return VMPI_get_errno();
    }
    
    /*static*/ void CErrnoClass::_SetErrno(ScriptObject*, int value)
    {
        //errno = value;
        VMPI_set_errno( value );
    }

}
