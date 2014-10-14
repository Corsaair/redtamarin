/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "avmshell.h"

namespace avmshell
{

    CArpaInetClass::CArpaInetClass(VTable *cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    CArpaInetClass::~CArpaInetClass()
    {
        
    }


    uint32_t CArpaInetClass::_htonl(uint32_t hostlong)
    {
        return VMPI_htonl( hostlong );
    }

    uint32_t CArpaInetClass::_htons(uint32_t hostshort)
    {
        return VMPI_htons( hostshort );
    }

    uint32_t CArpaInetClass::_ntohl(uint32_t netlong)
    {
        return VMPI_ntohl( netlong );
    }

    uint32_t CArpaInetClass::_ntohs(uint32_t netshort)
    {
        return VMPI_ntohs( netshort );
    }


    uint32_t CArpaInetClass::_inet_addr(Stringp cp)
    {
        if( !cp )
        {
            toplevel()->throwArgumentError(kNullArgumentError, "cp");
        }

        StUTF8String cpUTF8(cp);
        return VMPI_inet_addr( cpUTF8.c_str() );
    }

    uint32_t CArpaInetClass::_inet_network(Stringp cp)
    {
        if( !cp )
        {
            toplevel()->throwArgumentError(kNullArgumentError, "cp");
        }

        StUTF8String cpUTF8(cp);
        return VMPI_inet_network( cpUTF8.c_str() );
    }

    Stringp CArpaInetClass::_inet_ntoa(CIn_AddrObject* inaddr)
    {
        if( !inaddr )
        {
            toplevel()->throwArgumentError(kNullArgumentError, "inaddr");
        }

        struct in_addr inaddrEntry;
        inaddrEntry.s_addr = inaddr->get_s_addr();
        char *straddr = VMPI_inet_ntoa( inaddrEntry );
        Stringp value = core()->newStringUTF8( straddr );
        return value;
    }

    int CArpaInetClass::_inet_aton(Stringp cp, CIn_AddrObject* inp)
    {
        //POSIX only
        
        if( !cp )
        {
            toplevel()->throwArgumentError(kNullArgumentError, "cp");
        }

        if( !inp )
        {
            toplevel()->throwArgumentError(kNullArgumentError, "inp");
        }

        StUTF8String cpUTF8(cp);
        struct in_addr inaddrEntry;
        //inaddrEntry.s_addr = inp->get_s_addr();

        int result = VMPI_inet_aton( cpUTF8.c_str(), &inaddrEntry );
        
        if( result > 0 )
        {
            inp->set_s_addr( inaddrEntry.s_addr );
        }

        return result;
    }

    Stringp CArpaInetClass::_inet_ntop4(int af, CSockaddr_inObject* src)
    {
        if( !src )
        {
            toplevel()->throwArgumentError(kNullArgumentError, "src");
        }

        char ip4[INET_ADDRSTRLEN];
        struct sockaddr_in sa;
        CIn_AddrObject* inaddr = src->get_sin_addr();
        struct in_addr inaddrEntry;
        inaddrEntry.s_addr = inaddr->get_s_addr(); //uint

        if( inaddr->call_isValid() == false )
        {
            return NULL;
        }

        sa.sin_addr = inaddrEntry;
        VMPI_inet_ntop( af, &(sa.sin_addr), ip4, INET_ADDRSTRLEN );
        Stringp value = core()->newStringUTF8( ip4 );
        return value;
    }

    Stringp CArpaInetClass::_inet_ntop6(int af, CSockaddr_in6Object* src)
    {
        if( !src )
        {
            toplevel()->throwArgumentError(kNullArgumentError, "src");
        }

        char ip6[INET6_ADDRSTRLEN];
        CIn6_AddrObject* inaddr = src->get_sin6_addr();

        //*(__uint8_t*)(& in6addrEntry.in6_addr::__u6_addr.in6_addr::<anonymous union>::__u6_addr8)
        struct in6_addr in6addrEntry;
        in6addrEntry = inaddr->toStruct(); //Vector.<uint> to struct

        if( (in6addrEntry.s6_addr == NULL) ||
            (inaddr->call_isValid() == false) )
        {
            return NULL;
        }
        
        VMPI_inet_ntop( af, &(in6addrEntry), ip6, INET6_ADDRSTRLEN );
        Stringp value = core()->newStringUTF8( ip6 );
        return value;
    }

    int CArpaInetClass::_inet_pton4(int af, Stringp src, CSockaddr_inObject* dst)
    {
        if( !src )
        {
            toplevel()->throwArgumentError(kNullArgumentError, "src");
        }

        if( !dst )
        {
            toplevel()->throwArgumentError(kNullArgumentError, "dst");
        }
        
        StUTF8String srcUTF8(src);
        struct sockaddr_in sa;

        int result = VMPI_inet_pton( af, srcUTF8.c_str(), &(sa.sin_addr) );

        if( result < 1 )
        {
            return result;
        }

        CIn_AddrObject* inaddr = dst->get_sin_addr();
        inaddr->set_s_addr( sa.sin_addr.s_addr );
        
        return result;
    }

    int CArpaInetClass::_inet_pton6(int af, Stringp src, CSockaddr_in6Object* dst)
    {
        if( !src )
        {
            toplevel()->throwArgumentError(kNullArgumentError, "src");
        }

        if( !dst )
        {
            toplevel()->throwArgumentError(kNullArgumentError, "dst");
        }
        
        StUTF8String srcUTF8(src);
        struct sockaddr_in6 sa6;

        int result = VMPI_inet_pton( af, srcUTF8.c_str(), &(sa6.sin6_addr) );

        if( result < 1 )
        {
            return result;
        }

        CIn6_AddrObject* inaddr = dst->get_sin6_addr();
        inaddr->fromStruct( sa6.sin6_addr );

        return result;
    }
    
}
