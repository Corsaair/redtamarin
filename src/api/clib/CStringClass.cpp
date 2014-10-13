/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "avmshell.h"

namespace avmshell
{

    CStringClass::CStringClass(VTable *cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    CStringClass::~CStringClass()
    {
        
    }

    /*static*/ int CStringClass::strcmp(ScriptObject* self, Stringp s1, Stringp s2)
    {
        Toplevel* toplevel = self->toplevel();

        if( !s1 )
        {
            toplevel->throwArgumentError(kNullArgumentError, "s1");
        }

        if( !s2 )
        {
            toplevel->throwArgumentError(kNullArgumentError, "s2");
        }
        
        #if AVMSYSTEM_WIN32
            StUTF16String s1UTF16(s1);
            StUTF16String s2UTF16(s2);
            return VMPI_strcmp16( s1UTF16.c_str(), s2UTF16.c_str() );
        #else
            StUTF8String s1UTF8(s1);
            StUTF8String s2UTF8(s2);
            return VMPI_strcmp( s1UTF8.c_str(), s2UTF8.c_str() );
        #endif
    }

    /*static*/ int CStringClass::strcoll(ScriptObject* self, Stringp s1, Stringp s2)
    {
        Toplevel* toplevel = self->toplevel();

        if( !s1 )
        {
            toplevel->throwArgumentError(kNullArgumentError, "s1");
        }

        if( !s2 )
        {
            toplevel->throwArgumentError(kNullArgumentError, "s2");
        }
        
        #if AVMSYSTEM_WIN32
            StUTF16String s1UTF16(s1);
            StUTF16String s2UTF16(s2);
            return VMPI_strcoll16( s1UTF16.c_str(), s2UTF16.c_str() );
        #else
            StUTF8String s1UTF8(s1);
            StUTF8String s2UTF8(s2);
            return VMPI_strcoll( s1UTF8.c_str(), s2UTF8.c_str() );
        #endif
    }

    /*static*/ Stringp CStringClass::strerror(ScriptObject* self, int errnum)
    {
        AvmCore *core = self->core();
        (void)errnum;

        #if AVMSYSTEM_WIN32
            wchar *str = VMPI_strerror16( errnum );

            Stringp value = core->newStringUTF16( str );
            StUTF8String valueUTF8(value);
            return core->newStringUTF8( valueUTF8.c_str() );
        #else
            char *str = VMPI_strerror( errnum );
            return core->newStringUTF8( str );
        #endif
    }

    /*static unsigned CStringClass::strlen(ScriptObject* self, Stringp str)
    {
        Toplevel* toplevel = self->toplevel();

        if( !str )
        {
            toplevel->throwArgumentError(kNullArgumentError, "str");
        }
        
        StUTF8String strUTF8(str);
        return (unsigned)VMPI_strlen( strUTF8.c_str() );
    }*/

    /*static*/ int CStringClass::strspn(ScriptObject* self, Stringp s1, Stringp s2)
    {
        Toplevel* toplevel = self->toplevel();

        if( !s1 )
        {
            toplevel->throwArgumentError(kNullArgumentError, "s1");
        }

        if( !s2 )
        {
            toplevel->throwArgumentError(kNullArgumentError, "s2");
        }
        
        #if AVMSYSTEM_WIN32
            StUTF16String s1UTF16(s1);
            StUTF16String s2UTF16(s2);
            return VMPI_strspn16( s1UTF16.c_str(), s2UTF16.c_str() );
        #else
            StUTF8String s1UTF8(s1);
            StUTF8String s2UTF8(s2);
            return VMPI_strspn( s1UTF8.c_str(), s2UTF8.c_str() );
        #endif
    }
    

}
