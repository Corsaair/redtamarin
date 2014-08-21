/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is [Open Source Virtual Machine.].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2004-2006
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Zwetan Kjukov <zwetan@gmail.com>.
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

#include "avmshell.h"

namespace avmshell
{

    CUnistdClass::CUnistdClass(avmplus::VTable *cvtable)
        : avmplus::ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    CUnistdClass::~CUnistdClass()
    {
        
    }

    int CUnistdClass::get_F_OK() { return F_OK; }
    
    int CUnistdClass::get_X_OK() { return X_OK; }
    
    int CUnistdClass::get_W_OK() { return W_OK; }
    
    int CUnistdClass::get_R_OK() { return R_OK; }






    /*static*/ int CUnistdClass::access(ScriptObject* self, Stringp path, int mode)
    {
        Toplevel* toplevel = self->toplevel();
        (void)mode;

        if (!path) {
            toplevel->throwArgumentError(kNullArgumentError, "path");
        }

        #ifdef AVMSYSTEM_WIN32
            StUTF16String pathUTF16(path);
            return VMPI_access16( pathUTF16.c_str(), mode );
        #else
            StUTF8String pathUTF8(path);
            return VMPI_access( pathUTF8.c_str(), mode );
        #endif
    }

    /*static*/ int CUnistdClass::chdir(ScriptObject* self, Stringp path)
    {
        Toplevel* toplevel = self->toplevel();

        if (!path) {
            toplevel->throwArgumentError(kNullArgumentError, "path");
        }

        #ifdef AVMSYSTEM_WIN32
            StUTF16String pathUTF16(path);
            return VMPI_chdir16( pathUTF16.c_str() );
        #else
            StUTF8String pathUTF8(path);
            return VMPI_chdir( pathUTF8.c_str() );
        #endif
    }

    /*static*/ int CUnistdClass::close(ScriptObject*, int fildes)
    {
        return VMPI_close( fildes );
    }

    /*static*/ int CUnistdClass::dup(ScriptObject*, int fildes)
    {
        return VMPI_dup( fildes );
    }

    /*static*/ int CUnistdClass::dup2(ScriptObject*, int fildes, int fildes2)
    {
        return VMPI_dup2( fildes, fildes2 );
    }

    /*static*/ int CUnistdClass::execl(ScriptObject* self, Stringp path, Atom* argv, int argc)
    {
        AvmCore *core = self->core();
        Toplevel* toplevel = self->toplevel();

        if (!path) {
            toplevel->throwArgumentError(kNullArgumentError, "path");
        }

        const char* execargs[ ARG_MAX ]; //ARG_MAX = 4096

        if (argc > 0)
        {
            for(int i=0; i < argc; i++ )
            {
                /* note:
                   first we transform the Atom to a Stringp
                   then we make this string a UTF8String
                */
                //Stringp strarg = self->core()->string( argv[i] );
                Stringp strarg = core->string( argv[i] );
                StUTF8String strargUTF8(strarg);
                
                /* note:
                   here we need to duplicate the string into the char array
                */
                execargs[i] = strdup( strargUTF8.c_str() ); //use VMPI_strdup ?
            }
        }
        
        /* note:
           always terminate with NULL
           for ex:
           const char* args[4096];
           args[0] = "1";
           args[1] = "2";
           args[2] = "3";
           args[3] = NULL;
           //or args[3] = (char *)0;
        */
        execargs[argc] = NULL;
        
        StUTF8String pathUTF8(path);
        
        return VMPI_execv( pathUTF8.c_str(), const_cast<char * const *>(execargs) );
    }

    /*static*/ int CUnistdClass::execle(ScriptObject* self, Stringp path, Atom* argv, int argc)
    {
        AvmCore *core = self->core();
        Toplevel* toplevel = self->toplevel();

        if (!path) {
            toplevel->throwArgumentError(kNullArgumentError, "path");
        }

        int cmdc = 0;
        int envc = 0;
        const char* execargs[ ARG_MAX ]; //ARG_MAX = 4096
        const char* execenvs[ ARG_MAX ]; //ARG_MAX = 4096

        if( argc > 0 )
        {
            bool isarg = true;
            for(int i=0; i < argc; i++ )
            {
                if( core->isNull( argv[i] ) )
                {
                    isarg = false;
                    continue;
                }

                Stringp strarg = core->string( argv[i] );
                StUTF8String strargUTF8(strarg);

                if( isarg )
                {

                    execargs[cmdc] = strdup( strargUTF8.c_str() );
                    cmdc++;
                }
                else
                {
                    execenvs[envc] = strdup( strargUTF8.c_str() );
                    envc++;
                }
            }
        }

        /* note:
           do not free() after strdup() or the string ref will be lost
           so yeah it create a small memory leak
           but in this case it is not a big deal as exec() will
           replace the current process
        */

        execargs[cmdc] = NULL;
        execenvs[envc] = NULL;
        
        StUTF8String pathUTF8(path);
        
        return VMPI_execve( pathUTF8.c_str(), const_cast<char * const *>(execargs), const_cast<char * const *>(execenvs) );
    }

    /*static*/ int CUnistdClass::execlp(ScriptObject* self, Stringp file, Atom* argv, int argc)
    {
        AvmCore *core = self->core();
        Toplevel* toplevel = self->toplevel();

        if (!file) {
            toplevel->throwArgumentError(kNullArgumentError, "file");
        }

        const char* execargs[4096];

        if (argc > 0)
        {
            for(int i=0; i < argc; i++ )
            {
                Stringp strarg = core->string( argv[i] );
                StUTF8String strargUTF8(strarg);
                execargs[i] = strdup( strargUTF8.c_str() );
            }
        }
        
        execargs[argc] = NULL;
        
        StUTF8String fileUTF8(file);
        
        return VMPI_execvp( fileUTF8.c_str(), const_cast<char * const *>(execargs) );
    }

    /*static*/ int CUnistdClass::execv(ScriptObject* self, Stringp path, ArrayObject* argv)
    {
        AvmCore *core = self->core();
        Toplevel* toplevel = self->toplevel();

        if (!path) {
            toplevel->throwArgumentError(kNullArgumentError, "path");
        }

        if (!argv) {
            argv = toplevel->arrayClass()->newArray();
        }

        const char* execargs[4096]; //ARG_MAX = 4096
        int argc = argv->get_length();

        if (argc > 0)
        {
            for(int i=0; i < argc; i++ )
            {
                Stringp strarg = core->string( argv->getUintProperty(i) );
                StUTF8String strargUTF8(strarg);
                execargs[i] = strdup( strargUTF8.c_str() ); //use VMPI_strdup ?
            }
        }

        execargs[argc] = NULL;
        
        StUTF8String pathUTF8(path);
        
        return VMPI_execv( pathUTF8.c_str(), const_cast<char * const *>(execargs) );
    }

    /*static*/ int CUnistdClass::execve(ScriptObject* self, Stringp path, ArrayObject* argv, ArrayObject* envp)
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

        const char* execargs[ ARG_MAX ]; //ARG_MAX = 4096
        const char* execenvs[ ARG_MAX ]; //ARG_MAX = 4096
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
        
        return VMPI_execve( pathUTF8.c_str(), const_cast<char * const *>(execargs), const_cast<char * const *>(execenvs) );
    }

    /*static*/ int CUnistdClass::execvp(ScriptObject* self, Stringp file, ArrayObject* argv)
    {
        AvmCore *core = self->core();
        Toplevel* toplevel = self->toplevel();

        if (!file) {
            toplevel->throwArgumentError(kNullArgumentError, "file");
        }

        if (!argv) {
            argv = toplevel->arrayClass()->newArray();
        }

        const char* execargs[4096]; //ARG_MAX = 4096
        int argc = argv->get_length();

        if (argc > 0)
        {
            for(int i=0; i < argc; i++ )
            {
                Stringp strarg = core->string( argv->getUintProperty(i) );
                StUTF8String strargUTF8(strarg);
                execargs[i] = strdup( strargUTF8.c_str() );
            }
        }
        
        execargs[argc] = NULL;
        
        StUTF8String fileUTF8(file);
        
        return VMPI_execvp( fileUTF8.c_str(), const_cast<char * const *>(execargs) );
    }

    /*static*/ int CUnistdClass::fsync(ScriptObject*, int fildes)
    {
        return VMPI_fsync( fildes );
    }

    /*static*/ int CUnistdClass::ftruncate(ScriptObject*, int fildes, uint32_t length)
    {
        return VMPI_ftruncate( fildes, length );
    }







    /*int CUnistdClass::chdir(avmplus::Stringp path)
    {
        if (!path) {
            toplevel()->throwArgumentError(kNullArgumentError, "path");
        }

        avmplus::StUTF8String pathUTF8(path);
        return VMPI_chdir(pathUTF8.c_str());
    }*/
    
    /*int CUnistdClass::chmod(avmplus::Stringp path, int mode)
    {
        if (!path) {
            toplevel()->throwArgumentError(kNullArgumentError, "path");
        }
        
        avmplus::StUTF8String pathUTF8(path);
        return VMPI_chmod(pathUTF8.c_str(), mode);
    }*/

    Stringp CUnistdClass::getcwd()
    {
        #ifdef AVMSYSTEM_WIN32
            wchar path[ PATH_MAX ];
            VMPI_getcwd16( path, (size_t) PATH_MAX );

            Stringp value = core()->newStringUTF16( path );
            StUTF8String valueUTF8(value);
            return core()->newStringUTF8( valueUTF8.c_str() );
        #else
            char path[ PATH_MAX ];
            VMPI_getcwd( path, (size_t) PATH_MAX );
            return core()->newStringUTF8( path );
        #endif
    }

    Stringp CUnistdClass::gethostname()
    {
        char hostname[ HOST_NAME_MAX ];
        VMPI_gethostname( hostname, (size_t) HOST_NAME_MAX );
        return core()->newStringUTF8( hostname );
    }

    Stringp CUnistdClass::getlogin()
    {
        #ifdef AVMSYSTEM_WIN32
            wchar username[ LOGIN_NAME_MAX ];
            VMPI_getUserName16( username );

            Stringp value = core()->newStringUTF16( username );
            StUTF8String valueUTF8(value);
            return core()->newStringUTF8( valueUTF8.c_str() );
        #else
            char username[ LOGIN_NAME_MAX ];
            VMPI_getUserName( username );
            return core()->newStringUTF8( username );
        #endif
    }

    int CUnistdClass::getpid()
    {
        return VMPI_getpid();
    }

    /*int CUnistdClass::mkdir(avmplus::Stringp path)
    {
        if (!path) {
            toplevel()->throwArgumentError(kNullArgumentError, "path");
        }
        
        avmplus::StUTF8String pathUTF8(path);
        return VMPI_mkdir(pathUTF8.c_str());
    }*/
    
    int CUnistdClass::rmdir(Stringp path)
    {
        if (!path) {
            toplevel()->throwArgumentError(kNullArgumentError, "path");
        }

        #ifdef AVMSYSTEM_WIN32
            StUTF16String pathUTF16(path);
            return VMPI_rmdir16( pathUTF16.c_str() );
        #else
            StUTF8String pathUTF8(path);
            return VMPI_rmdir( pathUTF8.c_str() );
        #endif
    }

    /* note
       void sleep(int milliseconds);
       but apparetnly we change to int32_t
       investigate what is the difference, more precision ?
    */
    void CUnistdClass::sleep(int32_t milliseconds)
    {
        /* before workers
        */
        //VMPI_sleep(milliseconds);

        /* with workers
        */
        // Or do we try to make the all the isolate threads sleep? In a safepoint? and interruptibly?
        if (milliseconds < 0) 
            milliseconds = 0;
        vmbase::VMThread::sleep( milliseconds );
    }

    int CUnistdClass::unlink(Stringp path)
    {
        if (!path) {
            toplevel()->throwArgumentError(kNullArgumentError, "path");
        }
        
        #ifdef AVMSYSTEM_WIN32
            StUTF16String pathUTF16(path);
            return VMPI_unlink16( pathUTF16.c_str() );
        #else
            StUTF8String pathUTF8(path);
            return VMPI_unlink( pathUTF8.c_str() );
        #endif
    }

}
