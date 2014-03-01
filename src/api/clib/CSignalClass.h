/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_CSignalClass__
#define __avmshell_CSignalClass__

namespace avmshell
{
    using namespace avmplus;

    class CSignalClass : public ClassClosure
    {
    public:
        CSignalClass(VTable* cvtable);
        ~CSignalClass();

        int get_SIGEV_NONE();
        int get_SIGEV_SIGNAL();
        int get_SIGEV_THREAD();

        static int kill(ScriptObject*, int pid, int sig);
        
        DECLARE_SLOTS_CSignalClass;
    };

    class CsigvalClass : public ClassClosure
    {
    public:
        CsigvalClass(VTable* vtable);
        ~CsigvalClass();

        void dummy();

    private:
        DECLARE_SLOTS_CsigvalClass;
    };

    class CsigvalObject : public ScriptObject
    {
    public:
        CsigvalObject(VTable *vtable, ScriptObject *delegate);
        ~CsigvalObject();

        union sigval read();
        void write(union sigval value);

    private:
        union sigval _sigval;

        DECLARE_SLOTS_CsigvalObject;
    };

    class Csiginfo_tClass : public ClassClosure
    {
    public:
        Csiginfo_tClass(VTable* vtable);
        ~Csiginfo_tClass();

        void dummy();

    private:
        DECLARE_SLOTS_Csiginfo_tClass;
    };

    class Csiginfo_tObject : public ScriptObject
    {
    public:
        Csiginfo_tObject(VTable *vtable, ScriptObject *delegate);
        ~Csiginfo_tObject();

        siginfo_t read();
        void write(siginfo_t value);

    private:
        siginfo_t _siginfo;

        DECLARE_SLOTS_Csiginfo_tObject;
    };


}

#endif /* __avmshell_CSignalClass__ */

