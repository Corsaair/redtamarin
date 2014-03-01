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
        
    }

    CTypeClass::~CTypeClass()
    {
        
    }

    /*static*/ int CTypeClass::isalnum(ScriptObject*, int c)
    {
        return VMPI_isalnum( c );
    }

    /*static*/ int CTypeClass::isalpha(ScriptObject*, int c)
    {
        return VMPI_isalpha( c );
    }

    /*static*/ int CTypeClass::isascii(ScriptObject*, int c)
    {
        return VMPI_isascii( c );
    }

    /*static*/ int CTypeClass::isblank(ScriptObject*, int c)
    {
        return VMPI_isblank( c );
    }

    /*static*/ int CTypeClass::iscntrl(ScriptObject*, int c)
    {
        return VMPI_iscntrl( c );
    }

    /*static*/ int CTypeClass::isdigit(ScriptObject*, int c)
    {
        return VMPI_isdigit( c );
    }

    /*static*/ int CTypeClass::isgraph(ScriptObject*, int c)
    {
        return VMPI_isgraph( c );
    }

    /*static*/ int CTypeClass::islower(ScriptObject*, int c)
    {
        return VMPI_islower( c );
    }

    /*static*/ int CTypeClass::isprint(ScriptObject*, int c)
    {
        return VMPI_isprint( c );
    }

    /*static*/ int CTypeClass::ispunct(ScriptObject*, int c)
    {
        return VMPI_ispunct( c );
    }

    /*static*/ int CTypeClass::isspace(ScriptObject*, int c)
    {
        return VMPI_isspace( c );
    }

    /*static*/ int CTypeClass::isupper(ScriptObject*, int c)
    {
        return VMPI_isupper( c );
    }

    /*static*/ int CTypeClass::isxdigit(ScriptObject*, int c)
    {
        return VMPI_isxdigit( c );
    }

    /*static*/ int CTypeClass::toascii(ScriptObject*, int c)
    {
        return VMPI_toascii( c );
    }

    /*static*/ int CTypeClass::tolower(ScriptObject*, int c)
    {
        return VMPI_tolower( c );
    }

    /*static*/ int CTypeClass::toupper(ScriptObject*, int c)
    {
        return VMPI_toupper( c );
    }

}
