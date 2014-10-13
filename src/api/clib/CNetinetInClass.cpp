/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "avmshell.h"

namespace avmshell
{

    CNetinetInClass::CNetinetInClass(VTable *cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    CNetinetInClass::~CNetinetInClass()
    {
        
    }


    int CNetinetInClass::get_IPPROTO_IP() { return IPPROTO_IP; }
    int CNetinetInClass::get_IPPROTO_IPV6() { return IPPROTO_IPV6; }
    int CNetinetInClass::get_IPPROTO_ICMP() { return IPPROTO_ICMP; }
    int CNetinetInClass::get_IPPROTO_RAW() { return IPPROTO_RAW; }
    int CNetinetInClass::get_IPPROTO_TCP() { return IPPROTO_TCP; }
    int CNetinetInClass::get_IPPROTO_UDP() { return IPPROTO_UDP; }


    //int CNetinetInClass::get_INADDR_ANY() { return INADDR_ANY; }
    //int CNetinetInClass::get_INADDR_BROADCAST() { return INADDR_BROADCAST; }

    int CNetinetInClass::get_INET_ADDRSTRLEN() { return INET_ADDRSTRLEN; }
    int CNetinetInClass::get_INET6_ADDRSTRLEN() { return INET6_ADDRSTRLEN; }

    int CNetinetInClass::get_IPV6_JOIN_GROUP() { return IPV6_JOIN_GROUP; }
    int CNetinetInClass::get_IPV6_LEAVE_GROUP() { return IPV6_LEAVE_GROUP; }
    int CNetinetInClass::get_IPV6_MULTICAST_HOPS() { return IPV6_MULTICAST_HOPS; }
    int CNetinetInClass::get_IPV6_MULTICAST_IF() { return IPV6_MULTICAST_IF; }
    int CNetinetInClass::get_IPV6_MULTICAST_LOOP() { return IPV6_MULTICAST_LOOP; }
    int CNetinetInClass::get_IPV6_UNICAST_HOPS() { return IPV6_UNICAST_HOPS; }
    int CNetinetInClass::get_IPV6_V6ONLY() { return IPV6_V6ONLY; }


    //in_addr
    CIn_AddrClass::CIn_AddrClass(VTable *vtable)
        : ClassClosure(vtable)
    {
        createVanillaPrototype();
    }

    CIn_AddrClass::~CIn_AddrClass()
    {
        //nothing to destroy
    }

    void CIn_AddrClass::dummy()
    {
        //does strictly nothing
    }


    CIn_AddrObject::CIn_AddrObject(VTable *vtable, ScriptObject *delegate)
        : ScriptObject(vtable, delegate)
    {}

    CIn_AddrObject::~CIn_AddrObject()
    {
        //nothing to destroy
    }

    void CIn_AddrObject::dummy()
    {
        //does strictly nothing
    }


    //sockaddr_in
    CSockaddr_inClass::CSockaddr_inClass(VTable *vtable)
        : ClassClosure(vtable)
    {
        createVanillaPrototype();
    }

    CSockaddr_inClass::~CSockaddr_inClass()
    {
        //nothing to destroy
    }

    void CSockaddr_inClass::dummy()
    {
        //does strictly nothing
    }


    CSockaddr_inObject::CSockaddr_inObject(VTable *vtable, ScriptObject *delegate)
        : ScriptObject(vtable, delegate)
    {}

    CSockaddr_inObject::~CSockaddr_inObject()
    {
        //nothing to destroy
    }

    void CSockaddr_inObject::fromStruct(struct sockaddr_in sockaddr4)
    {
        this->set_sin_family( sockaddr4.sin_family );
        this->set_sin_port( sockaddr4.sin_port );

        CIn_AddrObject* inaddr = this->get_sin_addr();
        inaddr->set_s_addr( sockaddr4.sin_addr.s_addr );

        this->set_sin_addr( inaddr );
    }

    struct sockaddr_in CSockaddr_inObject::toStruct()
    {
         struct sockaddr_in sockaddr4;
         sockaddr4.sin_family = this->get_sin_family();
         sockaddr4.sin_port   = this->get_sin_port();

         CIn_AddrObject* inaddr = this->get_sin_addr();
         struct in_addr inaddr4;
         inaddr4.s_addr = inaddr->get_s_addr();

         sockaddr4.sin_addr = inaddr4;

         return sockaddr4;
    }

    //in6_addr
    CIn6_AddrClass::CIn6_AddrClass(VTable *vtable)
        : ClassClosure(vtable)
    {
        createVanillaPrototype();
    }

    CIn6_AddrClass::~CIn6_AddrClass()
    {
        //nothing to destroy
    }

    void CIn6_AddrClass::dummy()
    {
        //does strictly nothing
    }


    CIn6_AddrObject::CIn6_AddrObject(VTable *vtable, ScriptObject *delegate)
        : ScriptObject(vtable, delegate)
    {}

    CIn6_AddrObject::~CIn6_AddrObject()
    {
        //nothing to destroy
    }

    void CIn6_AddrObject::dummy()
    {
        //does strictly nothing
    }

    void CIn6_AddrObject::fromStruct(struct in6_addr in6addr)
    {
        Toplevel* toplevel = this->toplevel();
        AvmCore* core = toplevel->core();
        //core->console << "fromStruct()\n";

        //static uint8_t s6addr[16] = {};
        //VMPI_memcpy( s6addr, in6addr.s6_addr, sizeof in6addr.s6_addr );

        uint32_t len = 16;
        UIntVectorObject* v = toplevel->uintVectorClass()->newVector(len);
        uint32_t c;
        for( c=0; c<len; c++ )
        {
            v->setUintProperty( c, core->uintToAtom(in6addr.s6_addr[c]) );
            //v->setUintProperty( c, core->uintToAtom( s6addr[c] ) );
            //core->console << "1.index= " << c << " value= " << (uint32_t) s6addr[c] << "\n";
            //core->console << "2.index= " << c << " value= " << v->getUintProperty( c ) << "\n";
        }

        this->set_s6_addr( v );
    }

    struct in6_addr CIn6_AddrObject::toStruct()
    {
        //GCRef<UIntVectorObject> v = toplevel->uintVectorClass()->newVector();

        //Toplevel* toplevel = this->toplevel();
        //AvmCore* core = toplevel->core();
        //core->console << "this = " << this << "\n";
        //core->console << "toStruct()\n";

        struct in6_addr in6addr;
        static uint8_t s6addr[16] = {};

        UIntVectorObject* v = this->get_s6_addr();

        if(!v)
        {
            return in6addr;
        }

        uint32_t len = v->get_length();
        uint32_t c;
        for( c=0; c<len; c++ )
        {
            s6addr[c] = (uint8_t) AvmCore::integer_u( v->getUintProperty( c ) );
            //s6addr[c] = AvmCore::integer_u( v->getUintProperty( c ) );
            //core->console << "1.index= " << c << " value= " << v->getUintProperty( c ) << "\n";
            //core->console << "2.index= " << c << " value= " << AvmCore::integer_u( v->getUintProperty( c ) ) << "\n";
        }

        VMPI_memcpy( in6addr.s6_addr, s6addr, sizeof s6addr );

        return in6addr;
    }


    

    //sockaddr_in6
    CSockaddr_in6Class::CSockaddr_in6Class(VTable *vtable)
        : ClassClosure(vtable)
    {
        createVanillaPrototype();
    }

    CSockaddr_in6Class::~CSockaddr_in6Class()
    {
        //nothing to destroy
    }

    void CSockaddr_in6Class::dummy()
    {
        //does strictly nothing
    }


    CSockaddr_in6Object::CSockaddr_in6Object(VTable *vtable, ScriptObject *delegate)
        : ScriptObject(vtable, delegate)
    {}

    CSockaddr_in6Object::~CSockaddr_in6Object()
    {
        //nothing to destroy
    }

    void CSockaddr_in6Object::fromStruct(struct sockaddr_in6 sockaddr6)
    {
        this->set_sin6_family( sockaddr6.sin6_family );
        this->set_sin6_port( sockaddr6.sin6_port );
        this->set_sin6_flowinfo( sockaddr6.sin6_flowinfo );
        this->set_sin6_scope_id( sockaddr6.sin6_scope_id );

        CIn6_AddrObject* inaddr = this->get_sin6_addr();
        inaddr->fromStruct( sockaddr6.sin6_addr );

        this->set_sin6_addr( inaddr );
    }

    struct sockaddr_in6 CSockaddr_in6Object::toStruct()
    {
        struct sockaddr_in6 sockaddr6;
        sockaddr6.sin6_family   = this->get_sin6_family();
        sockaddr6.sin6_port     = this->get_sin6_port();
        sockaddr6.sin6_flowinfo = this->get_sin6_flowinfo();
        sockaddr6.sin6_scope_id = this->get_sin6_scope_id();

        CIn6_AddrObject* inaddr = this->get_sin6_addr();
        struct in6_addr inaddr6;
        inaddr6 = inaddr->toStruct();

        sockaddr6.sin6_addr = inaddr6;

        return sockaddr6;
    }

}
