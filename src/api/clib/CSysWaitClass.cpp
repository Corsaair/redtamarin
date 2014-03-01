/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "avmshell.h"

namespace avmshell
{

    CSysWaitClass::CSysWaitClass(VTable *cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    CSysWaitClass::~CSysWaitClass()
    {
        
    }

    int CSysWaitClass::get_WCONTINUED() { return WCONTINUED; }
    int CSysWaitClass::get_WNOHANG() { return WNOHANG; }
    int CSysWaitClass::get_WUNTRACED() { return WUNTRACED; }

    int CSysWaitClass::get_WEXITED() { return WEXITED; }
    int CSysWaitClass::get_WNOWAIT() { return WNOWAIT; }
    int CSysWaitClass::get_WSTOPPED() { return WSTOPPED; }

    int CSysWaitClass::get_P_ALL() { return P_ALL; }
    int CSysWaitClass::get_P_PGID() { return P_PGID; }
    int CSysWaitClass::get_P_PID() { return P_PID; }


    int CSysWaitClass::_WEXITSTATUS(int status)
    {
        return VMPI_WEXITSTATUS( status );
    }

    int CSysWaitClass::_WIFCONTINUED(int status)
    {
        return VMPI_WIFCONTINUED( status );
    }

    int CSysWaitClass::_WIFEXITED(int status)
    {
        return VMPI_WIFEXITED( status );
    }

    int CSysWaitClass::_WIFSIGNALED(int status)
    {
        return VMPI_WIFSIGNALED( status );
    }

    int CSysWaitClass::_WIFSTOPPED(int status)
    {
        return VMPI_WIFSTOPPED( status );
    }

    int CSysWaitClass::_WSTOPSIG(int status)
    {
        return VMPI_WSTOPSIG( status );
    }

    int CSysWaitClass::_WTERMSIG(int status)
    {
        return VMPI_WTERMSIG( status );
    }

    /*static*/ int CSysWaitClass::wait(ScriptObject*, CWaitStatusObject* waitstat)
    {
        int status;
        int result = VMPI_wait( &status );

        if( waitstat )
        {
            waitstat->set_stat_loc( status );
        }
        
        return result;
    }

    /*static*/ int CSysWaitClass::waitid(ScriptObject*, int idtype, int id, Csiginfo_tObject* infop, int options)
    {
        siginfo_t signalInfo;
        int result = VMPI_waitid( idtype, id, &signalInfo, options );
        infop->write( signalInfo );
        
        /*
        infop->set_si_signo( signalInfo.si_signo );
        infop->set_si_code( signalInfo.si_code );
        infop->set_si_errno( signalInfo.si_errno );
        infop->set_si_pid( signalInfo.si_pid );
        infop->set_si_uid( signalInfo.si_uid );
        //infop->set_si_addr( signalInfo.si_addr );
        infop->set_si_status( signalInfo.si_status );
        infop->set_si_band( signalInfo.si_band );
        //infop->set_si_value( signalInfo.si_value );
        */

        return result;
    }

    /*static*/ int CSysWaitClass::waitpid(ScriptObject*, int pid, CWaitStatusObject* waitstat, int options)
    {
        int status;
        int result = VMPI_waitpid( pid, &status, options );

        if( waitstat )
        {
            waitstat->set_stat_loc( status );
        }
        
        return result;
    }



    CWaitStatusClass::CWaitStatusClass(VTable *vtable)
        : ClassClosure(vtable)
    {
        createVanillaPrototype();
    }

    CWaitStatusClass::~CWaitStatusClass()
    {
        //nothing to destroy
    }

    void CWaitStatusClass::dummy()
    {
        //does strictly nothing
    }


    CWaitStatusObject::CWaitStatusObject(VTable *vtable, ScriptObject *delegate)
        : ScriptObject(vtable, delegate)
    {}

    CWaitStatusObject::~CWaitStatusObject()
    {
        //nothing to destroy
    }

    void CWaitStatusObject::dummy()
    {
        //does strictly nothing
    }

}
