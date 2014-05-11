/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "avmshell.h"

namespace avmshell
{

    CTypeClass::CTypeClass(VTable *cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    CTypeClass::~CTypeClass()
    {
        
    }

    int CTypeClass::_avm_isalnum(int c)
    {
        return VMPI_isalnum( c );
    }

    int CTypeClass::_avm_isalpha(int c)
    {
        return VMPI_isalpha( c );
    }

    int CTypeClass::_avm_isascii(int c)
    {
        return VMPI_isascii( c );
    }

    int CTypeClass::_avm_isblank(int c)
    {
        return VMPI_isblank( c );
    }

    int CTypeClass::_avm_iscntrl(int c)
    {
        return VMPI_iscntrl( c );
    }

    int CTypeClass::_avm_isdigit(int c)
    {
        return VMPI_isdigit( c );
    }

    int CTypeClass::_avm_isgraph(int c)
    {
        return VMPI_isgraph( c );
    }

    int CTypeClass::_avm_islower(int c)
    {
        return VMPI_islower( c );
    }

    int CTypeClass::_avm_isprint(int c)
    {
        return VMPI_isprint( c );
    }

    int CTypeClass::_avm_ispunct(int c)
    {
        return VMPI_ispunct( c );
    }

    int CTypeClass::_avm_isspace(int c)
    {
        return VMPI_isspace( c );
    }

    int CTypeClass::_avm_isupper(int c)
    {
        return VMPI_isupper( c );
    }

    int CTypeClass::_avm_isxdigit(int c)
    {
        return VMPI_isxdigit( c );
    }

    int CTypeClass::_avm_toascii(int c)
    {
        return VMPI_toascii( c );
    }

    int CTypeClass::_avm_tolower(int c)
    {
        return VMPI_tolower( c );
    }

    int CTypeClass::_avm_toupper(int c)
    {
        return VMPI_toupper( c );
    }

}
