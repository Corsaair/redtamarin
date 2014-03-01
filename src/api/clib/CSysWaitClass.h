/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_CSysWaitClass__
#define __avmshell_CSysWaitClass__

namespace avmshell
{
    using namespace avmplus;

    class CSysWaitClass : public ClassClosure
    {
    public:
        CSysWaitClass(VTable* cvtable);
        ~CSysWaitClass();

        int get_WCONTINUED();
        int get_WNOHANG();
        int get_WUNTRACED();

        int get_WEXITED();
        int get_WNOWAIT();
        int get_WSTOPPED();

        int get_P_ALL();
        int get_P_PGID();
        int get_P_PID();

        int _WEXITSTATUS(int status);
        int _WIFCONTINUED(int status);
        int _WIFEXITED(int status);
        int _WIFSIGNALED(int status);
        int _WIFSTOPPED(int status);
        int _WSTOPSIG(int status);
        int _WTERMSIG(int status);

        static int wait(ScriptObject*, CWaitStatusObject* waitstat);
        static int waitid(ScriptObject*, int idtype, int id, Csiginfo_tObject* infop, int options);
        static int waitpid(ScriptObject*, int pid, CWaitStatusObject* waitstat, int options);


        DECLARE_SLOTS_CSysWaitClass;
    };

    class CWaitStatusClass : public ClassClosure
    {
    public:
        CWaitStatusClass(VTable* vtable);
        ~CWaitStatusClass();

        void dummy();

    private:
        DECLARE_SLOTS_CWaitStatusClass;
    };

    class CWaitStatusObject : public ScriptObject
    {
    public:
        CWaitStatusObject(VTable *vtable, ScriptObject *delegate);
        ~CWaitStatusObject();

        void dummy();

    private:
        DECLARE_SLOTS_CWaitStatusObject;
    };


}

#endif /* __avmshell_CSysWaitClass__ */

