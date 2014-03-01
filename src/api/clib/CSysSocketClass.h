/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_CSysSocketClass__
#define __avmshell_CSysSocketClass__

namespace avmshell
{
    using namespace avmplus;

    class CSysSocketClass : public ClassClosure
    {
    public:
        CSysSocketClass(VTable* cvtable);
        ~CSysSocketClass();

        int get_SOCK_DGRAM();
        int get_SOCK_RAW();
        int get_SOCK_SEQPACKET();
        int get_SOCK_STREAM();
        

        DECLARE_SLOTS_CSysSocketClass;
    };

    /*
    class CsockaddrClass : public ClassClosure
    {
    public:
        CsockaddrClass(VTable* vtable);
        ~CsockaddrClass();

        void dummy();

    private:
        DECLARE_SLOTS_CsockaddrClass;
    };

    class CsockaddrObject : public ScriptObject
    {
    public:
        CsockaddrObject(VTable *vtable, ScriptObject *delegate);
        ~CsockaddrObject();

        sockaddr* read();
        void write(sockaddr* value);

    private:
        sockaddr* _sockaddr;
        DECLARE_SLOTS_CsockaddrObject;
    };

    class Cfpos_tClass : public ClassClosure
    {
    public:
        Cfpos_tClass(VTable* vtable);
        ~Cfpos_tClass();

        void dummy();

    private:
        DECLARE_SLOTS_Cfpos_tClass;
    };

    class Cfpos_tObject : public ScriptObject
    {
    public:
        Cfpos_tObject(VTable *vtable, ScriptObject *delegate);
        ~Cfpos_tObject();

        fpos_t read();
        void write(fpos_t value);

    private:
        fpos_t _pos;

        DECLARE_SLOTS_Cfpos_tObject;
    };
    */



}

#endif /* __avmshell_CSysSocketClass__ */

