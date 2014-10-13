/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_CSysSelectClass__
#define __avmshell_CSysSelectClass__

namespace avmshell
{
    using namespace avmplus;

    class CSysSelectClass : public ClassClosure
    {
    public:
        CSysSelectClass(VTable* cvtable);
        ~CSysSelectClass();

        int get_FD_SETSIZE();

        static void __FD_CLR(ScriptObject* self, int fd, Cfd_setObject* fdsetp);
        static int __FD_ISSET(ScriptObject* self, int fd, Cfd_setObject* fdsetp);
        static void __FD_SET(ScriptObject* self, int fd, Cfd_setObject* fdsetp);
        static void __FD_ZERO(ScriptObject* self, Cfd_setObject* fdsetp);

        static int select(ScriptObject* self, int nfds, Cfd_setObject* readfds, Cfd_setObject* writefds, Cfd_setObject* errorfds, CtimevalObject* timeout);

        static bool isReadable(ScriptObject*, int nfds, CErrorObject* err);
        static bool isWritable(ScriptObject*, int nfds, CErrorObject* err);
        static bool isExceptional(ScriptObject*, int nfds, CErrorObject* err);
        

        DECLARE_SLOTS_CSysSelectClass;
    };




    class CtimevalClass : public ClassClosure
    {
    public:
        CtimevalClass(VTable* vtable);
        ~CtimevalClass();

        void dummy();

    private:
        DECLARE_SLOTS_CtimevalClass;
    };

    class CtimevalObject : public ScriptObject
    {
    public:
        CtimevalObject(VTable *vtable, ScriptObject *delegate);
        ~CtimevalObject();
        void fromStruct(struct timeval tv);

        struct timeval toStruct();

    private:
        DECLARE_SLOTS_CtimevalObject;
    };


    class Cfd_setClass : public ClassClosure
    {
    public:
        Cfd_setClass(VTable* vtable);
        ~Cfd_setClass();

        void dummy();

    private:
        DECLARE_SLOTS_Cfd_setClass;
    };

    class Cfd_setObject : public ScriptObject
    {
    public:
        Cfd_setObject(VTable *vtable, ScriptObject *delegate);
        ~Cfd_setObject();

        fd_set fds;
        void dummy();

    private:
        DECLARE_SLOTS_Cfd_setObject;
    };



}

#endif /* __avmshell_CSysSelectClass__ */

