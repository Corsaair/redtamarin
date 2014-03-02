/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "avmshell.h"

namespace avmshell
{

    CFcntlClass::CFcntlClass(VTable *cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    CFcntlClass::~CFcntlClass()
    {
        
    }


    int CFcntlClass::get_O_RDONLY() { return O_RDONLY; }
    int CFcntlClass::get_O_WRONLY() { return O_WRONLY; }
    int CFcntlClass::get_O_RDWR() { return O_RDWR; }
    int CFcntlClass::get_O_ACCMODE() { return O_ACCMODE; }

    int CFcntlClass::get_O_APPEND() { return O_APPEND; }
    int CFcntlClass::get_O_CREAT() { return O_CREAT; }
    int CFcntlClass::get_O_TRUNC() { return O_TRUNC; }
    int CFcntlClass::get_O_EXCL() { return O_EXCL; }

    int CFcntlClass::get_O_TEXT() { return O_TEXT; }
    int CFcntlClass::get_O_BINARY() { return O_BINARY; }


    /*static*/ int CFcntlClass::creat(ScriptObject* self, Stringp path, int mode)
    {
        Toplevel* toplevel = self->toplevel();

        if( !path )
        {
            toplevel->throwArgumentError(kNullArgumentError, "path");
        }
        
        StUTF8String pathUTF8(path);
        return VMPI_creat( pathUTF8.c_str(), mode );
    }

    /*static*/ int CFcntlClass::open(ScriptObject* self, Stringp path, int oflag, int mode)
    {
        Toplevel* toplevel = self->toplevel();

        if( !path )
        {
            toplevel->throwArgumentError(kNullArgumentError, "path");
        }
        
        StUTF8String pathUTF8(path);
        return VMPI_open( pathUTF8.c_str(), oflag, mode );
    }

}
