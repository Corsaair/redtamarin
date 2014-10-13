/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_CNetinetInClass__
#define __avmshell_CNetinetInClass__

namespace avmshell
{
    using namespace avmplus;

    class CNetinetInClass : public ClassClosure
    {
    public:
        CNetinetInClass(VTable* cvtable);
        ~CNetinetInClass();

        int get_IPPROTO_IP();
        int get_IPPROTO_IPV6();
        int get_IPPROTO_ICMP();
        int get_IPPROTO_RAW();
        int get_IPPROTO_TCP();
        int get_IPPROTO_UDP();

        //int get_INADDR_ANY();
        //int get_INADDR_BROADCAST();

        int get_INET_ADDRSTRLEN();
        int get_INET6_ADDRSTRLEN();

        int get_IPV6_JOIN_GROUP();
        int get_IPV6_LEAVE_GROUP();
        int get_IPV6_MULTICAST_HOPS();
        int get_IPV6_MULTICAST_IF();
        int get_IPV6_MULTICAST_LOOP();
        int get_IPV6_UNICAST_HOPS();
        int get_IPV6_V6ONLY();
        


        DECLARE_SLOTS_CNetinetInClass;
    };

    //in_addr
    class CIn_AddrClass : public ClassClosure
    {
    public:
        CIn_AddrClass(VTable* vtable);
        ~CIn_AddrClass();

        void dummy();

    private:
        DECLARE_SLOTS_CIn_AddrClass;
    };

    class CIn_AddrObject : public ScriptObject
    {
    public:
        CIn_AddrObject(VTable *vtable, ScriptObject *delegate);
        ~CIn_AddrObject();

        void dummy();

    private:
        DECLARE_SLOTS_CIn_AddrObject;
    };

    //sockaddr_in
    class CSockaddr_inClass : public ClassClosure
    {
    public:
        CSockaddr_inClass(VTable* vtable);
        ~CSockaddr_inClass();

        void dummy();

    private:
        DECLARE_SLOTS_CSockaddr_inClass;
    };

    class CSockaddr_inObject : public ScriptObject
    {
    public:
        CSockaddr_inObject(VTable *vtable, ScriptObject *delegate);
        ~CSockaddr_inObject();

        void fromStruct(struct sockaddr_in sockaddr4);
        struct sockaddr_in toStruct();

    private:
        DECLARE_SLOTS_CSockaddr_inObject;
    };

    //in6_addr
    class CIn6_AddrClass : public ClassClosure
    {
    public:
        CIn6_AddrClass(VTable* vtable);
        ~CIn6_AddrClass();

        void dummy();

    private:
        DECLARE_SLOTS_CIn6_AddrClass;
    };

    class CIn6_AddrObject : public ScriptObject
    {
    public:
        CIn6_AddrObject(VTable *vtable, ScriptObject *delegate);
        ~CIn6_AddrObject();

        void dummy();
        void fromStruct(struct in6_addr in6addr);
        struct in6_addr toStruct();

    private:
        DECLARE_SLOTS_CIn6_AddrObject;
    };

    //sockaddr_in6
    class CSockaddr_in6Class : public ClassClosure
    {
    public:
        CSockaddr_in6Class(VTable* vtable);
        ~CSockaddr_in6Class();

        void dummy();

    private:
        DECLARE_SLOTS_CSockaddr_in6Class;
    };

    class CSockaddr_in6Object : public ScriptObject
    {
    public:
        CSockaddr_in6Object(VTable *vtable, ScriptObject *delegate);
        ~CSockaddr_in6Object();

        void fromStruct(struct sockaddr_in6 sockaddr6);
        struct sockaddr_in6 toStruct();

    private:
        DECLARE_SLOTS_CSockaddr_in6Object;
    };

}

#endif /* __avmshell_CNetinetInClass__ */

