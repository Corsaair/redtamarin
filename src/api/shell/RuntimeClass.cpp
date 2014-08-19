/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "avmshell.h"

namespace avmshell
{

    RuntimeClass::RuntimeClass(VTable *cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    RuntimeClass::~RuntimeClass()
    {
        
    }

    int32_t RuntimeClass::get_apiVersion()
    {
        ShellCore* core = (ShellCore*)this->core();
        return core->defaultAPIVersion;
    }

    int32_t RuntimeClass::get_swfVersion()
    {
        ShellCore* core = (ShellCore*)this->core();
        avmplus::BugCompatibility::Version v = core->getDefaultBugCompatibilityVersion();
        AvmAssert(v >= 0 && v < avmplus::BugCompatibility::VersionCount);
        return avmplus::BugCompatibility::kNames[v];
    }

    Stringp RuntimeClass::_getAvmplusPlatform()
    {
        #if AVMSYSTEM_UNIX
            return core()->newConstantStringLatin1( "linux" );
        #endif

        #if AVMSYSTEM_MAC
            return core()->newConstantStringLatin1( "macintosh" );
        #endif

        #if AVMSYSTEM_WIN32
            return core()->newConstantStringLatin1( "windows" );
        #endif
    }

    Stringp RuntimeClass::_getAvmplusArchitecture()
    {
        /*
        #if AVMSYSTEM_IA32
            return core()->newConstantStringLatin1( "x86-32" );
        #endif

        #if AVMSYSTEM_AMD64
            return core()->newConstantStringLatin1( "x86-64" );
        #endif

        #if AVMSYSTEM_ARM
            return core()->newConstantStringLatin1( "ARM" );
        #endif

        #if AVMSYSTEM_PPC
            return core()->newConstantStringLatin1( "PowerPC" );
        #endif

        #if AVMSYSTEM_SPARC
            return core()->newConstantStringLatin1( "SPARC" );
        #endif

        #if AVMSYSTEM_MIPS
            return core()->newConstantStringLatin1( "MIPS" );
        #endif

        #if AVMSYSTEM_SH4
            return core()->newConstantStringLatin1( "SH4" );
        #endif

            return core()->newConstantStringLatin1( "unknown" );
        */

        ShellCore* core = (ShellCore*)this->core();

        #if AVMSYSTEM_IA32
            return core->newConstantStringLatin1( "x86-32" );
        #elif AVMSYSTEM_AMD64
            return core->newConstantStringLatin1( "x86-64" );
        #elif AVMSYSTEM_ARM
            return core->newConstantStringLatin1( "ARM" );
        #elif AVMSYSTEM_PPC
            return core->newConstantStringLatin1( "PowerPC" );
        #elif AVMSYSTEM_SPARC
            return core->newConstantStringLatin1( "SPARC" );
        #elif AVMSYSTEM_MIPS
            return core->newConstantStringLatin1( "MIPS" );
        #elif AVMSYSTEM_SH4
            return core->newConstantStringLatin1( "SH4" );
        #else
            return core->newConstantStringLatin1( "unknown" );
        #endif

    }

    Stringp RuntimeClass::_getAvmplusVersion()
    {
        return core()->newConstantStringLatin1(AVMPLUS_VERSION_USER " " AVMPLUS_BUILD_CODE);
    }

    Stringp RuntimeClass::_getAvmplusDescription()
    {
        #ifdef AVMPLUS_DESC_STRING
            return core()->newConstantStringLatin1(AVMPLUS_DESC_STRING);
        #else
            return core()->newConstantStringLatin1("");
        #endif
    }

    Stringp RuntimeClass::_getFeatures()
    {
        return core()->newConstantStringLatin1(avmfeatures);
    }
    
    Stringp RuntimeClass::_getRunmode()
    {
        ShellCore* core = (ShellCore*)this->core();
        if (core->config.runmode == avmplus::RM_mixed)
            return core->newConstantStringLatin1("mixed");
        if (core->config.runmode == avmplus::RM_jit_all)
        {
            if (core->config.jitordie)
                return core->newConstantStringLatin1("jitordie");
            return core->newConstantStringLatin1("jit");
        }
        if (core->config.runmode == avmplus::RM_interp_all)
            return core->newConstantStringLatin1("interp");
        return core->newConstantStringLatin1("unknown");
    }

    Stringp RuntimeClass::_getEndian()
    {
        ShellCore* core = (ShellCore*)this->core();
        #ifdef VMCFG_BIG_ENDIAN
            return core->newConstantStringLatin1("bigEndian");
        #else
            return core->newConstantStringLatin1("littleEndian");
        #endif
    }



    void RuntimeClass::eval(Stringp source)
    {
        if (!source) {
            toplevel()->throwArgumentError(kNullArgumentError, "source");
        }
        
        #ifdef VMCFG_EVAL
        	ShellCore* core = (ShellCore*)this->core();
        	core->evaluateString( source, false );
        #endif // VMCFG_EVAL
    }

    Stringp RuntimeClass::returnEval(Stringp source, bool recordTime)
    {
        if (!source) {
            toplevel()->throwArgumentError(kNullArgumentError, "source");
        }
        
        ShellCore* core = (ShellCore*)this->core();
        Stringp result = core->kEmptyString;

        #ifdef VMCFG_EVAL
            result = core->evaluateStringToOutput( source, recordTime );
        #endif // VMCFG_EVAL

        return result;
    }
    
    bool RuntimeClass::is64bit()
    {
        #ifdef AVMPLUS_64BIT
            return true;
        #else
            return false;
        #endif
    }

}
