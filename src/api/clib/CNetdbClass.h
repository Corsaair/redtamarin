/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_CNetdbClass__
#define __avmshell_CNetdbClass__

namespace avmshell
{
    using namespace avmplus;

    class CNetdbClass : public ClassClosure
    {
    public:
        CNetdbClass(VTable* cvtable);
        ~CNetdbClass();

        int get_AI_PASSIVE();
        int get_AI_CANONNAME();
        int get_AI_NUMERICHOST();
        int get_AI_NUMERICSERV();
        int get_AI_V4MAPPED();
        int get_AI_ALL();
        int get_AI_ADDRCONFIG();

        int get_NI_NOFQDN();
        int get_NI_NUMERICHOST();
        int get_NI_NAMEREQD();
        int get_NI_NUMERICSERV();
        int get_NI_NUMERICSCOPE();
        int get_NI_DGRAM();

        int get_EAI_AGAIN();
        int get_EAI_BADFLAGS();
        int get_EAI_FAIL();
        int get_EAI_FAMILY();
        int get_EAI_MEMORY();
        int get_EAI_NONAME();
        int get_EAI_SERVICE();
        int get_EAI_SOCKTYPE();
        int get_EAI_SYSTEM();
        int get_EAI_OVERFLOW();

        ChostentObject* gethostbyaddr4(CIn_AddrObject* addr, int type);
        ChostentObject* gethostbyaddr6(CIn6_AddrObject* addr, int type);
        
        //endhostent()
        //endnetent()
        //endprotoent()
        //endservent()
        //freeaddrinfo()
        static Stringp gai_strerror(ScriptObject* self, int ecode);
        static ArrayObject* getaddrinfo(ScriptObject* self, Stringp nodename, Stringp servname, CaddrinfoObject* hints, CEAIrrorObject* eaierr);
        //gethostbyaddr()
        static ChostentObject* gethostbyname(ScriptObject* self, Stringp name);
        static ChostentObject* gethostent(ScriptObject* self);
        //getnameinfo()
        //getnetbyaddr()
        //getnetbyname()
        //getnetent()
        //getprotobyname()
        static CprotoentObject* getprotobynumber(ScriptObject* self, int proto);
        static CprotoentObject* getprotoent(ScriptObject* self);
        //getservbyname()
        //getservbyport()
        //getservent()
        //sethostent()
        //setnetent()
        //setprotoent()
        //setservent()
        

        
        
        

        

        DECLARE_SLOTS_CNetdbClass;
    };

    class ChostentClass : public ClassClosure
    {
    public:
        ChostentClass(VTable* vtable);
        ~ChostentClass();

        void dummy();

    private:
        DECLARE_SLOTS_ChostentClass;
    };

    class ChostentObject : public ScriptObject
    {
    public:
        ChostentObject(VTable *vtable, ScriptObject *delegate);
        ~ChostentObject();

        void dummy();

    private:
        DECLARE_SLOTS_ChostentObject;
    };

    class CprotoentClass : public ClassClosure
    {
    public:
        CprotoentClass(VTable* vtable);
        ~CprotoentClass();

        void dummy();

    private:
        DECLARE_SLOTS_CprotoentClass;
    };

    class CprotoentObject : public ScriptObject
    {
    public:
        CprotoentObject(VTable *vtable, ScriptObject *delegate);
        ~CprotoentObject();

        void dummy();

    private:
        DECLARE_SLOTS_CprotoentObject;
    };


    class CaddrinfoClass : public ClassClosure
    {
    public:
        CaddrinfoClass(VTable* vtable);
        ~CaddrinfoClass();

        void dummy();

    private:
        DECLARE_SLOTS_CaddrinfoClass;
    };

    class CaddrinfoObject : public ScriptObject
    {
    public:
        CaddrinfoObject(VTable *vtable, ScriptObject *delegate);
        ~CaddrinfoObject();

        void dummy();

    private:
        DECLARE_SLOTS_CaddrinfoObject;
    };






    class CEAIrrorClass : public NativeErrorClass
    {
    public:
        CEAIrrorClass(VTable* vtable) : NativeErrorClass(vtable) {};
        /*~CEAIrrorClass();*/

        /*void dummy();*/

    private:
        DECLARE_SLOTS_CEAIrrorClass;
    };

    class CEAIrrorObject : public ErrorObject
    {
    public:
        CEAIrrorObject(VTable *vtable, ScriptObject *delegate) : ErrorObject(vtable, delegate) {};
        /*~CEAIrrorObject();*/

        /*void dummy();*/

    private:
        DECLARE_SLOTS_CEAIrrorObject;
    };

}

#endif /* __avmshell_CNetdbClass__ */

