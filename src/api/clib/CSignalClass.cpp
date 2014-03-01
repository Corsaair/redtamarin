/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "avmshell.h"

namespace avmshell
{

    CSignalClass::CSignalClass(VTable *cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    CSignalClass::~CSignalClass()
    {
        
    }


    int CSignalClass::get_SIGEV_NONE() { return SIGEV_NONE; }
    int CSignalClass::get_SIGEV_SIGNAL() { return SIGEV_SIGNAL; }
    int CSignalClass::get_SIGEV_THREAD() { return SIGEV_THREAD; }

    /*static*/ int CSignalClass::kill(ScriptObject*, int pid, int sig)
    {
        return VMPI_kill( pid, sig );
    }




    CsigvalClass::CsigvalClass(VTable *vtable)
        : ClassClosure(vtable)
    {
        createVanillaPrototype();
    }

    CsigvalClass::~CsigvalClass()
    {
        //nothing to destroy
    }

    void CsigvalClass::dummy()
    {
        //does strictly nothing
    }


    CsigvalObject::CsigvalObject(VTable *vtable, ScriptObject *delegate)
        : ScriptObject(vtable, delegate)
    {}

    CsigvalObject::~CsigvalObject()
    {
        //nothing to destroy
    }

    union sigval CsigvalObject::read()
    {
        return _sigval;
    }

    void CsigvalObject::write(union sigval value)
    {
        _sigval = value;

        this->set_sival_int( value.sival_int );
    }


    Csiginfo_tClass::Csiginfo_tClass(VTable *vtable)
        : ClassClosure(vtable)
    {
        createVanillaPrototype();
    }

    Csiginfo_tClass::~Csiginfo_tClass()
    {
        //nothing to destroy
    }

    void Csiginfo_tClass::dummy()
    {
        //does strictly nothing
    }

    Csiginfo_tObject::Csiginfo_tObject(VTable *vtable, ScriptObject *delegate)
        : ScriptObject(vtable, delegate)
    {}

    Csiginfo_tObject::~Csiginfo_tObject()
    {
        //nothing to destroy
    }

    siginfo_t Csiginfo_tObject::read()
    {
        return _siginfo;
    }

    void Csiginfo_tObject::write(siginfo_t value)
    {
        _siginfo = value;

        this->set_si_signo( _siginfo.si_signo );
        this->set_si_code( _siginfo.si_code );
        this->set_si_errno( _siginfo.si_errno );
        this->set_si_pid( _siginfo.si_pid );
        this->set_si_uid( _siginfo.si_uid );
        //this->set_si_addr( _siginfo.si_addr );
        this->set_si_status( _siginfo.si_status );
        this->set_si_band( _siginfo.si_band );
        //this->set_si_value( _siginfo.si_value );
    }


}
