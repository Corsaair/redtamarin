/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "avmshell.h"

namespace avmshell
{

    CNetdbClass::CNetdbClass(VTable *cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    CNetdbClass::~CNetdbClass()
    {
        
    }


    int CNetdbClass::get_AI_PASSIVE() { return AI_PASSIVE; }
    int CNetdbClass::get_AI_CANONNAME() { return AI_CANONNAME; }
    int CNetdbClass::get_AI_NUMERICHOST() { return AI_NUMERICHOST; }
    int CNetdbClass::get_AI_NUMERICSERV() { return AI_NUMERICSERV; }
    int CNetdbClass::get_AI_V4MAPPED() { return AI_V4MAPPED; }
    int CNetdbClass::get_AI_ALL() { return AI_ALL; }
    int CNetdbClass::get_AI_ADDRCONFIG() { return AI_ADDRCONFIG; }

    int CNetdbClass::get_NI_NOFQDN() { return NI_NOFQDN; }
    int CNetdbClass::get_NI_NUMERICHOST() { return NI_NUMERICHOST; }
    int CNetdbClass::get_NI_NAMEREQD() { return NI_NAMEREQD; }
    int CNetdbClass::get_NI_NUMERICSERV() { return NI_NUMERICSERV; }
    int CNetdbClass::get_NI_NUMERICSCOPE() { return NI_NUMERICSCOPE; }
    int CNetdbClass::get_NI_DGRAM() { return NI_DGRAM; }

    int CNetdbClass::get_EAI_AGAIN() { return EAI_AGAIN; }
    int CNetdbClass::get_EAI_BADFLAGS() { return EAI_BADFLAGS; }
    int CNetdbClass::get_EAI_FAIL() { return EAI_FAIL; }
    int CNetdbClass::get_EAI_FAMILY() { return EAI_FAMILY; }
    int CNetdbClass::get_EAI_MEMORY() { return EAI_MEMORY; }
    int CNetdbClass::get_EAI_NONAME() { return EAI_NONAME; }
    int CNetdbClass::get_EAI_SERVICE() { return EAI_SERVICE; }
    int CNetdbClass::get_EAI_SOCKTYPE() { return EAI_SOCKTYPE; }
    int CNetdbClass::get_EAI_SYSTEM() { return EAI_SYSTEM; }
    int CNetdbClass::get_EAI_OVERFLOW() { return EAI_OVERFLOW; }

    /* TODO:
       define convert functions

       struct protoent* toProtoent( CprotoentObject* as3obj )
       CprotoentObject* fromProtoent( struct protoent* obj )
    */

    ChostentObject* CNetdbClass::gethostbyaddr4(CIn_AddrObject* addr, int type)
    {
        Toplevel* toplevel = this->toplevel();
        AvmCore* core = toplevel->core();

        if( !addr )
        {
            toplevel->throwArgumentError(kNullArgumentError, "addr");
        }

        struct hostent *he;
        struct in_addr ipv4addr;
        ipv4addr.s_addr = addr->get_s_addr(); //uint

        if( addr->call_isValid() == false )
        {
            return NULL;
        }

        he = VMPI_gethostbyaddr( (char *)&ipv4addr, sizeof ipv4addr, type );

        if( he )
        {
            ShellToplevel* shelltop = (ShellToplevel*)this->toplevel();
            ChostentClass *hc = shelltop->getShellClasses()->get_hostentClass();
            ChostentObject *ho = hc->constructObject();

            ho->set_h_name( core->newStringUTF8( he->h_name ) );
            
            ArrayObject *aliases = toplevel->arrayClass()->newArray();
            int count = 0;
            int i;
            for( i=0; he->h_aliases[i] != NULL; ++i )
            {
                aliases->setUintProperty( count++, core->newStringUTF8( he->h_aliases[i] )->atom() );
            }
            ho->set_h_aliases( aliases );

            ho->set_h_addrtype( he->h_addrtype );
            ho->set_h_length( he->h_length );

            ArrayObject *addrlist = toplevel->arrayClass()->newArray();
            count = 0;
            for( i=0; he->h_addr_list[i] != NULL; ++i )
            {
                struct in_addr in;
                memcpy(&in.s_addr, he->h_addr_list[i], sizeof (in.s_addr));

                CIn_AddrClass *ac = shelltop->getShellClasses()->get_in_addrClass();
                CIn_AddrObject *ao = ac->constructObject();

                ao->set_s_addr( in.s_addr );
                addrlist->setUintProperty( count++, ao->toAtom() );
            }
            ho->set_h_addr_list( addrlist );

            return ho;
        }

        return NULL;
    }

    ChostentObject* CNetdbClass::gethostbyaddr6(CIn6_AddrObject* addr, int type)
    {
        Toplevel* toplevel = this->toplevel();
        AvmCore* core = toplevel->core();

        if( !addr )
        {
            toplevel->throwArgumentError(kNullArgumentError, "addr");
        }

        struct hostent *he;
        struct in6_addr ipv6addr;
        ipv6addr = addr->toStruct(); //Vector.<uint> to struct

        if( (ipv6addr.s6_addr == NULL) ||
            (addr->call_isValid() == false) )
        {
            return NULL;
        }

        he = VMPI_gethostbyaddr( (char *)&ipv6addr, sizeof ipv6addr, type );

        if( he )
        {
            ShellToplevel* shelltop = (ShellToplevel*)this->toplevel();
            ChostentClass *hc = shelltop->getShellClasses()->get_hostentClass();
            ChostentObject *ho = hc->constructObject();

            ho->set_h_name( core->newStringUTF8( he->h_name ) );
            
            ArrayObject *aliases = toplevel->arrayClass()->newArray();
            int count = 0;
            int i;
            for( i=0; he->h_aliases[i] != NULL; ++i )
            {
                aliases->setUintProperty( count++, core->newStringUTF8( he->h_aliases[i] )->atom() );
            }
            ho->set_h_aliases( aliases );

            ho->set_h_addrtype( he->h_addrtype );
            ho->set_h_length( he->h_length );


            ArrayObject *addrlist = toplevel->arrayClass()->newArray();
            count = 0;
            for( i=0; he->h_addr_list[i] != NULL; ++i )
            {
                struct in_addr in;
                memcpy(&in.s_addr, he->h_addr_list[i], sizeof (in.s_addr));

                CIn_AddrClass *ac = shelltop->getShellClasses()->get_in_addrClass();
                CIn_AddrObject *ao = ac->constructObject();

                ao->set_s_addr( in.s_addr );
                addrlist->setUintProperty( count++, ao->toAtom() );
            }
            ho->set_h_addr_list( addrlist );

            return ho;
        }

        return NULL;
    }



    /*static*/ Stringp CNetdbClass::gai_strerror(ScriptObject* self, int ecode)
    {
        AvmCore *core = self->core();
        return core->newStringUTF8( VMPI_gai_strerror( ecode ) );
    }

    /*static*/ ChostentObject* CNetdbClass::gethostbyname(ScriptObject* self, Stringp name)
    {
        AvmCore *core = self->core();
        Toplevel* toplevel = self->toplevel();

        if( !name )
        {
            toplevel->throwArgumentError(kNullArgumentError, "name");
        }

        struct hostent *he;
        StUTF8String nameUTF8(name);

        he = VMPI_gethostbyname( nameUTF8.c_str() );

        if( he )
        {
            ShellToplevel* shelltop = (ShellToplevel*)self->toplevel();
            ChostentClass *hc = shelltop->getShellClasses()->get_hostentClass();
            ChostentObject *ho = hc->constructObject();

            ho->set_h_name( core->newStringUTF8( he->h_name ) );
            
            ArrayObject *aliases = toplevel->arrayClass()->newArray();
            int count = 0;
            int i;
            for( i=0; he->h_aliases[i] != NULL; ++i )
            {
                aliases->setUintProperty( count++, core->newStringUTF8( he->h_aliases[i] )->atom() );
            }
            ho->set_h_aliases( aliases );

            ho->set_h_addrtype( he->h_addrtype );
            ho->set_h_length( he->h_length );

            ArrayObject *addrlist = toplevel->arrayClass()->newArray();
            count = 0;
            for( i=0; he->h_addr_list[i] != NULL; ++i )
            {
                struct in_addr in;
                memcpy(&in.s_addr, he->h_addr_list[i], sizeof (in.s_addr));

                CIn_AddrClass *ac = shelltop->getShellClasses()->get_in_addrClass();
                CIn_AddrObject *ao = ac->constructObject();

                ao->set_s_addr( in.s_addr );
                addrlist->setUintProperty( count++, ao->toAtom() );                

                //addrlist->setUintProperty( count++, core->newStringUTF8( inet_ntoa(in) )->atom() );
            }
            ho->set_h_addr_list( addrlist );

            return ho;
        }

        return NULL;
    }

    /*static*/ CprotoentObject* CNetdbClass::getprotobynumber(ScriptObject* self, int proto)
    {
        struct protoent *pp;

        pp = VMPI_getprotobynumber( proto );

        if( pp )
        {
            ShellToplevel* shelltop = (ShellToplevel*)self->toplevel();
            CprotoentClass *pc = shelltop->getShellClasses()->get_protoentClass();
            CprotoentObject *po = pc->constructObject();

            po->set_p_name( self->core()->newStringUTF8( pp->p_name ) );
            po->set_p_proto( pp->p_proto );

            Toplevel* toplevel = self->toplevel();
            ArrayObject *aliases = toplevel->arrayClass()->newArray();
            int count = 0;
            int i;
            for( i=0; pp->p_aliases[i] != NULL; ++i )
            {
                aliases->setUintProperty( count++, self->core()->newStringUTF8( pp->p_aliases[i] )->atom());
            }
            po->set_p_aliases( aliases );

            return po;
        }

        return NULL;
    }

    /*static*/ CprotoentObject* CNetdbClass::getprotoent(ScriptObject* self)
    {
        struct protoent *pp;

        pp = VMPI_getprotoent();

        if( pp )
        {
            ShellToplevel* shelltop = (ShellToplevel*)self->toplevel();
            CprotoentClass *pc = shelltop->getShellClasses()->get_protoentClass();
            CprotoentObject *po = pc->constructObject();

            po->set_p_name( self->core()->newStringUTF8( pp->p_name ) );
            po->set_p_proto( pp->p_proto );

            Toplevel* toplevel = self->toplevel();
            ArrayObject *aliases = toplevel->arrayClass()->newArray();
            int count = 0;
            int i;
            for( i=0; pp->p_aliases[i] != NULL; ++i )
            {
                aliases->setUintProperty( count++, self->core()->newStringUTF8( pp->p_aliases[i] )->atom());
            }
            po->set_p_aliases( aliases );

            return po;
        }

        return NULL;
    }

    /*static*/ ChostentObject* CNetdbClass::gethostent(ScriptObject* self)
    {
        struct hostent *hh;

        hh = VMPI_gethostent();

        if( hh )
        {
            ShellToplevel* shelltop = (ShellToplevel*)self->toplevel();
            ChostentClass *hc = shelltop->getShellClasses()->get_hostentClass();
            ChostentObject *ho = hc->constructObject();

            ho->set_h_name( self->core()->newStringUTF8( hh->h_name ) );
            
            Toplevel* toplevel = self->toplevel();
            ArrayObject *aliases = toplevel->arrayClass()->newArray();
            int count = 0;
            int i;
            for( i=0; hh->h_aliases[i] != NULL; ++i )
            {
                aliases->setUintProperty( count++, self->core()->newStringUTF8( hh->h_aliases[i] )->atom());
            }
            ho->set_h_aliases( aliases );

            ho->set_h_addrtype( hh->h_addrtype );
            ho->set_h_length( hh->h_length );

            ArrayObject *addrlist = toplevel->arrayClass()->newArray();
            count = 0;
            for( i=0; hh->h_addr_list[i] != NULL; ++i )
            {
                struct in_addr in;
                memcpy(&in.s_addr, hh->h_addr_list[i], sizeof (in.s_addr));
                addrlist->setUintProperty( count++, self->core()->newStringUTF8( inet_ntoa(in) )->atom());
            }
            ho->set_h_addr_list( addrlist );

            return ho;
        }

        return NULL;
    }

    /*static*/ ArrayObject* CNetdbClass::getaddrinfo(ScriptObject* self, Stringp nodename, Stringp servname, CaddrinfoObject* hints, CEAIrrorObject* eaierr)
    {
        AvmCore *core = self->core();
        Toplevel* toplevel = self->toplevel();
        ShellToplevel* shelltop = (ShellToplevel*)self->toplevel();

        if( !hints )
        {
            CaddrinfoClass *ai_c = shelltop->getShellClasses()->get_addrinfoClass();
            CaddrinfoObject *hints = ai_c->constructObject();

            //default properties
            hints->set_ai_family( AF_UNSPEC );
            hints->set_ai_socktype( SOCK_STREAM );
        }

        StUTF8String nodenameUTF8(nodename);
        StUTF8String servnameUTF8(servname);

        //(void)hints;

        struct addrinfo h;
        VMPI_memset(&h, 0, sizeof h);
        
        h.ai_flags    = hints->get_ai_flags();
        h.ai_family   = hints->get_ai_family();
        h.ai_socktype = hints->get_ai_socktype();
        h.ai_protocol = hints->get_ai_protocol();
        //ignore other propertiess
        
        struct addrinfo *res, *p;

        int result = VMPI_getaddrinfo( nodenameUTF8.c_str(), servnameUTF8.c_str(), &h, &res );

        if( result != 0 )
        {
            //printf( "getaddrinfo: %s\n", gai_strerror(result));
            if( eaierr )
            {
                eaierr->call_apply( result );
            }

            return NULL;
        }

        ArrayObject *infolist = toplevel->arrayClass()->newArray();
        int count = 0;
        for( p = res; p != NULL; p = p->ai_next )
        {
            CaddrinfoClass *infoc = shelltop->getShellClasses()->get_addrinfoClass();
            CaddrinfoObject *info = infoc->constructObject();

            info->set_ai_flags( p->ai_flags );
            info->set_ai_family( p->ai_family );
            info->set_ai_socktype( p->ai_socktype );
            info->set_ai_protocol( p->ai_protocol );
            info->set_ai_addrlen( (int) p->ai_addrlen );
            info->set_ai_canonname( core->newStringUTF8( p->ai_canonname ) );

            if( p->ai_family == AF_INET )
            {
                struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
                CSockaddr_inClass *addr4c = shelltop->getShellClasses()->get_sockaddr_inClass();
                CSockaddr_inObject *addr4o = addr4c->constructObject();

                addr4o->set_sin_family( ipv4->sin_family );
                addr4o->set_sin_port( ipv4->sin_port );

                CIn_AddrClass *ac = shelltop->getShellClasses()->get_in_addrClass();
                CIn_AddrObject *ao = ac->constructObject();

                ao->set_s_addr( ipv4->sin_addr.s_addr );
                addr4o->set_sin_addr( ao );

                info->set_ai_addr( addr4o->toAtom() );
            }
            else if( p->ai_family == AF_INET6 )
            {
                struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
                CSockaddr_in6Class *addr6c = shelltop->getShellClasses()->get_sockaddr_in6Class();
                CSockaddr_in6Object *addr6o = addr6c->constructObject();

                addr6o->set_sin6_family( ipv6->sin6_family );
                addr6o->set_sin6_port( ipv6->sin6_port );
                addr6o->set_sin6_flowinfo( ipv6->sin6_flowinfo );
                addr6o->set_sin6_scope_id( ipv6->sin6_scope_id );

                CIn6_AddrClass *ac6 = shelltop->getShellClasses()->get_in6_addrClass();
                CIn6_AddrObject *ao6 = ac6->constructObject();

                ao6->fromStruct( ipv6->sin6_addr );
                addr6o->set_sin6_addr( ao6 );

                info->set_ai_addr( addr6o->toAtom() );
            }

            infolist->setUintProperty( count++, info->toAtom() );
        }

        VMPI_freeaddrinfo( res );

        return infolist;
    }





    ChostentClass::ChostentClass(VTable *vtable)
        : ClassClosure(vtable)
    {
        createVanillaPrototype();
    }

    ChostentClass::~ChostentClass()
    {
        //nothing to destroy
    }

    void ChostentClass::dummy()
    {
        //does strictly nothing
    }


    ChostentObject::ChostentObject(VTable *vtable, ScriptObject *delegate)
        : ScriptObject(vtable, delegate)
    {}

    ChostentObject::~ChostentObject()
    {
        //nothing to destroy
    }

    void ChostentObject::dummy()
    {
        //does strictly nothing
    }


    CprotoentClass::CprotoentClass(VTable *vtable)
        : ClassClosure(vtable)
    {
        createVanillaPrototype();
    }

    CprotoentClass::~CprotoentClass()
    {
        //nothing to destroy
    }

    void CprotoentClass::dummy()
    {
        //does strictly nothing
    }


    CprotoentObject::CprotoentObject(VTable *vtable, ScriptObject *delegate)
        : ScriptObject(vtable, delegate)
    {}

    CprotoentObject::~CprotoentObject()
    {
        //nothing to destroy
    }

    void CprotoentObject::dummy()
    {
        //does strictly nothing
    }


    CaddrinfoClass::CaddrinfoClass(VTable *vtable)
        : ClassClosure(vtable)
    {
        createVanillaPrototype();
    }

    CaddrinfoClass::~CaddrinfoClass()
    {
        //nothing to destroy
    }

    void CaddrinfoClass::dummy()
    {
        //does strictly nothing
    }


    CaddrinfoObject::CaddrinfoObject(VTable *vtable, ScriptObject *delegate)
        : ScriptObject(vtable, delegate)
    {}

    CaddrinfoObject::~CaddrinfoObject()
    {
        //nothing to destroy
    }

    void CaddrinfoObject::dummy()
    {
        //does strictly nothing
    }









    /*CEAIrrorClass::CEAIrrorClass(VTable *vtable)
        : NativeErrorClass(vtable)
    {
        createVanillaPrototype();
    }*/

    /*CEAIrrorClass::~CEAIrrorClass()
    {
        //nothing to destroy
    }*/

    /*void CEAIrrorClass::dummy()
    {
        //does strictly nothing
    }*/


    /*CEAIrrorObject::CEAIrrorObject(VTable *vtable, ScriptObject *delegate)
        : ErrorObject(vtable, delegate)
    {}*/

    /*CEAIrrorObject::~CEAIrrorObject()
    {
        //nothing to destroy
    }*/

    /*void CEAIrrorObject::dummy()
    {
        //does strictly nothing
    }*/


}
