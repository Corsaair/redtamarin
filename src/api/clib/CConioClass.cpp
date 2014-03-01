/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "avmshell.h"

namespace avmshell
{

    CConioClass::CConioClass(VTable *cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    CConioClass::~CConioClass()
    {
        
    }
    

    /*static*/ void CConioClass::canonical(ScriptObject*, bool status)
    {
        VMPI_canonical( status );
    }

    /*static*/ void CConioClass::echo(ScriptObject*, bool status)
    {
        VMPI_echo( status );
    }

    /*static*/ /*int CConioClass::getch(ScriptObject*)
    {
        return VMPI_getch();
    }*/

    /*static*/ /*int CConioClass::getche(ScriptObject*)
    {
        return VMPI_getche();
    }*/

    /*static*/ int CConioClass::kbhit(ScriptObject*)
    {
        return VMPI_kbhit();
    }

}
