/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "avmshell.h"

namespace avmshell
{

    CSpawnClass::CSpawnClass(VTable *cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    CSpawnClass::~CSpawnClass()
    {
        
    }

    /*void CSpawnClass::dummy()
    {
        //do nothing
    }*/

    /*static*/ int CSpawnClass::spawn(ScriptObject* self, Cpid_tObject* pid, Stringp path, ArrayObject* argv, ArrayObject* envp)
    {
        AvmCore *core = self->core();
        Toplevel* toplevel = self->toplevel();

        if (!path) {
            toplevel->throwArgumentError(kNullArgumentError, "path");
        }

        if (!argv) {
            argv = toplevel->arrayClass()->newArray();
        }

        if (!envp) {
            envp = toplevel->arrayClass()->newArray();
        }

        const char* execargs[4096]; //ARG_MAX = 4096
        const char* execenvs[4096]; //ARG_MAX = 4096
        int cmdc = argv->get_length();
        int envc = envp->get_length();

        if (cmdc > 0)
        {
            for(int i=0; i < cmdc; i++ )
            {
                Stringp strarg = core->string( argv->getUintProperty(i) );
                StUTF8String strargUTF8(strarg);
                execargs[i] = strdup( strargUTF8.c_str() ); //use VMPI_strdup ?
            }
        }

        if (envc > 0)
        {
            for(int j=0; j < envc; j++ )
            {
                Stringp strarg = core->string( envp->getUintProperty(j) );
                StUTF8String strargUTF8(strarg);
                execenvs[j] = strdup( strargUTF8.c_str() ); //use VMPI_strdup ?
            }
        }

        execargs[cmdc] = NULL;
        execenvs[envc] = NULL;
        
        StUTF8String pathUTF8(path);
        
        int newpid;
        int result = VMPI_spawn( &newpid, pathUTF8.c_str(), const_cast<char * const *>(execargs), const_cast<char * const *>(execenvs) );
        pid->set_value( newpid );
        
        return result;
    }

    /*static*/ int CSpawnClass::spawnp(ScriptObject* self, Cpid_tObject* pid, Stringp file, ArrayObject* argv, ArrayObject* envp)
    {
        AvmCore *core = self->core();
        Toplevel* toplevel = self->toplevel();

        if (!file) {
            toplevel->throwArgumentError(kNullArgumentError, "file");
        }

        if (!argv) {
            argv = toplevel->arrayClass()->newArray();
        }

        if (!envp) {
            envp = toplevel->arrayClass()->newArray();
        }

        const char* execargs[4096]; //ARG_MAX = 4096
        const char* execenvs[4096]; //ARG_MAX = 4096
        int cmdc = argv->get_length();
        int envc = envp->get_length();

        if (cmdc > 0)
        {
            for(int i=0; i < cmdc; i++ )
            {
                Stringp strarg = core->string( argv->getUintProperty(i) );
                StUTF8String strargUTF8(strarg);
                execargs[i] = strdup( strargUTF8.c_str() ); //use VMPI_strdup ?
            }
        }

        if (envc > 0)
        {
            for(int j=0; j < envc; j++ )
            {
                Stringp strarg = core->string( envp->getUintProperty(j) );
                StUTF8String strargUTF8(strarg);
                execenvs[j] = strdup( strargUTF8.c_str() ); //use VMPI_strdup ?
            }
        }

        execargs[cmdc] = NULL;
        execenvs[envc] = NULL;
        
        StUTF8String fileUTF8(file);
        
        int newpid;
        int result = VMPI_spawnp( &newpid, fileUTF8.c_str(), const_cast<char * const *>(execargs), const_cast<char * const *>(execenvs) );
        pid->set_value( newpid );
        
        return result;
    }


    Cpid_tClass::Cpid_tClass(VTable *vtable)
        : ClassClosure(vtable)
    {
        createVanillaPrototype();
    }

    Cpid_tClass::~Cpid_tClass()
    {
        //nothing to destroy
    }

    void Cpid_tClass::dummy()
    {
        //does strictly nothing
    }


    Cpid_tObject::Cpid_tObject(VTable *vtable, ScriptObject *delegate)
        : ScriptObject(vtable, delegate)
    {

    }

    Cpid_tObject::~Cpid_tObject()
    {
        //nothing to destroy
    }

    void Cpid_tObject::dummy()
    {
        //does strictly nothing
    }

}
