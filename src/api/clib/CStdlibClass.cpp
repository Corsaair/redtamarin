/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "avmshell.h"

namespace avmshell
{

    CStdlibClass::CStdlibClass(VTable *cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    CStdlibClass::~CStdlibClass()
    {
        
    }

    int CStdlibClass::get_EXIT_SUCCESS()
    {
        return EXIT_SUCCESS;
    }
    
    int CStdlibClass::get_EXIT_FAILURE()
    {
        return EXIT_FAILURE;
    }

    int CStdlibClass::get_RAND_MAX()
    {
        return RAND_MAX;
    }

    int CStdlibClass::get_MB_CUR_MAX()
    {
        return MB_CUR_MAX;
    }



    /*static*/ double CStdlibClass::atof(ScriptObject* self, Stringp str)
    {
        Toplevel* toplevel = self->toplevel();

        if (!str) {
            toplevel->throwArgumentError(kNullArgumentError, "str");
        }

        StUTF8String strUTF8(str);

        return VMPI_atof( strUTF8.c_str() );
    }

    /*static*/ int CStdlibClass::atoi(ScriptObject* self, Stringp str)
    {
        Toplevel* toplevel = self->toplevel();

        if (!str) {
            toplevel->throwArgumentError(kNullArgumentError, "str");
        }

        StUTF8String strUTF8(str);

        return VMPI_atoi( strUTF8.c_str() );
    }

    /*static*/ double CStdlibClass::atol(ScriptObject* self, Stringp str)
    {
        Toplevel* toplevel = self->toplevel();

        if (!str) {
            toplevel->throwArgumentError(kNullArgumentError, "str");
        }

        StUTF8String strUTF8(str);

        return VMPI_atol( strUTF8.c_str() );
    }

    /*static*/ Cdiv_tObject* CStdlibClass::div(ScriptObject* self, int numer, int denom)
    {
        div_t result = VMPI_div( numer, denom );

        ShellToplevel* shelltop = (ShellToplevel*)self->toplevel();
        Cdiv_tClass *d_c = shelltop->getShellClasses()->get_div_tClass();
        Cdiv_tObject *d_o = d_c->constructObject();

        d_o->set_quot( result.quot );
        d_o->set_rem( result.rem );

        return d_o;
    }

    /*static*/ Stringp CStdlibClass::getenv(ScriptObject* self, Stringp name)
    {
        AvmCore *core = self->core();
        Toplevel* toplevel = self->toplevel();

        if( !name )
        {
            toplevel->throwArgumentError(kNullArgumentError, "name");
        }
        
        #if AVMSYSTEM_WIN32
            StUTF16String nameUTF16(name);
            const wchar * str = VMPI_getenv16( nameUTF16.c_str() );
            
            Stringp value = core->newStringUTF16( str );
            StUTF8String valueUTF8(value);
            return core->newStringUTF8( valueUTF8.c_str() );
        #else
            StUTF8String nameUTF8(name);
            const char * str = VMPI_getenv( nameUTF8.c_str() );
            return core->newStringUTF8( str );
        #endif
    }

    /*static*/ Cldiv_tObject* CStdlibClass::ldiv(ScriptObject* self, double numer, double denom)
    {
        ldiv_t result = VMPI_ldiv( numer, denom );

        ShellToplevel* shelltop = (ShellToplevel*)self->toplevel();
        Cldiv_tClass *ld_c = shelltop->getShellClasses()->get_ldiv_tClass();
        Cldiv_tObject *ld_o = ld_c->constructObject();

        ld_o->set_quot( result.quot );
        ld_o->set_rem( result.rem );

        return ld_o;
    }

    /*static*/ Clldiv_tObject* CStdlibClass::lldiv(ScriptObject* self, double numer, double denom)
    {
        lldiv_t result = VMPI_lldiv( numer, denom );

        ShellToplevel* shelltop = (ShellToplevel*)self->toplevel();
        Clldiv_tClass *lld_c = shelltop->getShellClasses()->get_lldiv_tClass();
        Clldiv_tObject *lld_o = lld_c->constructObject();

        lld_o->set_quot( (double) result.quot );
        lld_o->set_rem( (double) result.rem );

        return lld_o;
    }

    /*static*/ int CStdlibClass::mblen(ScriptObject* self, Stringp s, int i)
    {
        Toplevel* toplevel = self->toplevel();

        if( !s )
        {
            toplevel->throwArgumentError(kNullArgumentError, "s");
        }

        StUTF8String sUTF8(s);
        return VMPI_mblen( sUTF8.c_str(), i );
    }

    /*static*/ Stringp CStdlibClass::mkdtemp(ScriptObject* self, Stringp templ)
    {
        Toplevel* toplevel = self->toplevel();

        if( !templ )
        {
            toplevel->throwArgumentError(kNullArgumentError, "template");
        }

        StUTF8String templateUTF8(templ);
        char * str = VMPI_mkdtemp( (char*)templateUTF8.c_str() );

        if( str )
        {
            AvmCore *core = self->core();
            return core->newStringUTF8( str );
        }

        return NULL;
    }

    /*static*/ int CStdlibClass::mkstemp(ScriptObject* self, Stringp templ)
    {
        Toplevel* toplevel = self->toplevel();

        if( !templ )
        {
            toplevel->throwArgumentError(kNullArgumentError, "template");
        }

        StUTF8String templateUTF8(templ);
        return VMPI_mkstemp( (char*)templateUTF8.c_str() );
    }

    /*static*/ int CStdlibClass::putenv(ScriptObject* self, Stringp name)
    {
        Toplevel* toplevel = self->toplevel();

        if( !name )
        {
            toplevel->throwArgumentError(kNullArgumentError, "name");
        }
        
        #if AVMSYSTEM_WIN32
            StUTF16String nameUTF16(name);
            
            wchar * str = VMPI_strdup16( nameUTF16.c_str() );
            int result  = VMPI_putenv16( str );
        #else
            StUTF8String nameUTF8(name);
            
            char * str = VMPI_strdup( nameUTF8.c_str() );
            int result = VMPI_putenv( str );
        #endif

        /* note:
           do not free() after strdup() or the string ref will be lost
           so yeah it create a small memory leak
           need to investigate if AVM2 intern string can solve this
           or maybe create a special string pool to save such ref
           that we could clean before the VM exit
        */
        //VMPI_free(str);
        return result;
    }

    /*static*/ int CStdlibClass::rand(ScriptObject*)
    {
        return VMPI_rand();
    }

    /*static*/ Stringp CStdlibClass::realpath(ScriptObject* self, Stringp path)
    {
        AvmCore *core = self->core();
        Toplevel* toplevel = self->toplevel();

        if( !path )
        {
            toplevel->throwArgumentError(kNullArgumentError, "path");
        }
        
        #if AVMSYSTEM_WIN32
            StUTF16String pathUTF16(path);
            wchar * str = VMPI_realpath16( pathUTF16.c_str() );
            
            Stringp value = core->newStringUTF16( str );
            StUTF8String valueUTF8(value);
            return core->newStringUTF8( valueUTF8.c_str() );
        #else
            StUTF8String pathUTF8(path);
            char * str = VMPI_realpath( pathUTF8.c_str() );

            return core->newStringUTF8( str );
        #endif
    }

    /*static*/ int CStdlibClass::setenv(ScriptObject* self, Stringp name, Stringp value, bool overwrite)
    {
        Toplevel* toplevel = self->toplevel();

        if( !name )
        {
            toplevel->throwArgumentError(kNullArgumentError, "name");
        }
        
        if( !value )
        {
            toplevel->throwArgumentError(kNullArgumentError, "value");
        }

        int writeover = 0;
        if( overwrite ) { writeover = 1; }
        
        #if AVMSYSTEM_WIN32
            StUTF16String nameUTF16(name);
            StUTF16String valueUTF16(value);
            return VMPI_setenv16( nameUTF16.c_str(), valueUTF16.c_str(), writeover );
        #else
            StUTF8String nameUTF8(name);
            StUTF8String valueUTF8(value);
            return VMPI_setenv( nameUTF8.c_str(), valueUTF8.c_str(), writeover );
        #endif
    }

    /*static*/ void CStdlibClass::srand(ScriptObject*, unsigned seed)
    {
        VMPI_srand( seed );
    }

    /*static*/ int CStdlibClass::system(ScriptObject*, Stringp command)
    {
        #if AVMSYSTEM_WIN32
            if( !command )
            {
                return VMPI_system16( NULL );
            }
            
            StUTF16String commandUTF16(command);
            return VMPI_system16( commandUTF16.c_str() );
        #else
            if( !command )
            {
                return VMPI_system( NULL );
            }
            
            StUTF8String commandUTF8(command);
            return VMPI_system( commandUTF8.c_str() );
        #endif
    }

    /*static*/ int CStdlibClass::unsetenv(ScriptObject* self, Stringp name)
    {
        Toplevel* toplevel = self->toplevel();

        if( !name )
        {
            toplevel->throwArgumentError(kNullArgumentError, "name");
        }
        
        #if AVMSYSTEM_WIN32
            StUTF16String nameUTF16(name);
            return VMPI_unsetenv16( nameUTF16.c_str() );
        #else
            StUTF8String nameUTF8(name);
            return VMPI_unsetenv( nameUTF8.c_str() );
        #endif
    }






    Cdiv_tClass::Cdiv_tClass(VTable *vtable)
        : ClassClosure(vtable)
    {
        createVanillaPrototype();
    }

    Cdiv_tClass::~Cdiv_tClass()
    {
        //nothing to destroy
    }

    void Cdiv_tClass::dummy()
    {
        //does strictly nothing
    }


    Cdiv_tObject::Cdiv_tObject(VTable *vtable, ScriptObject *delegate)
        : ScriptObject(vtable, delegate)
    {

    }

    Cdiv_tObject::~Cdiv_tObject()
    {
        //nothing to destroy
    }

    void Cdiv_tObject::dummy()
    {
        //does strictly nothing
    }



    Cldiv_tClass::Cldiv_tClass(VTable *vtable)
        : ClassClosure(vtable)
    {
        createVanillaPrototype();
    }

    Cldiv_tClass::~Cldiv_tClass()
    {
        //nothing to destroy
    }

    void Cldiv_tClass::dummy()
    {
        //does strictly nothing
    }


    Cldiv_tObject::Cldiv_tObject(VTable *vtable, ScriptObject *delegate)
        : ScriptObject(vtable, delegate)
    {

    }

    Cldiv_tObject::~Cldiv_tObject()
    {
        //nothing to destroy
    }

    void Cldiv_tObject::dummy()
    {
        //does strictly nothing
    }


    Clldiv_tClass::Clldiv_tClass(VTable *vtable)
        : ClassClosure(vtable)
    {
        createVanillaPrototype();
    }

    Clldiv_tClass::~Clldiv_tClass()
    {
        //nothing to destroy
    }

    void Clldiv_tClass::dummy()
    {
        //does strictly nothing
    }


    Clldiv_tObject::Clldiv_tObject(VTable *vtable, ScriptObject *delegate)
        : ScriptObject(vtable, delegate)
    {

    }

    Clldiv_tObject::~Clldiv_tObject()
    {
        //nothing to destroy
    }

    void Clldiv_tObject::dummy()
    {
        //does strictly nothing
    }

}
