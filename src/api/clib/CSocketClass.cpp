/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is [Open Source Virtual Machine.].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2004-2006
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Zwetan Kjukov <zwetan@gmail.com>.
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

#include "avmshell.h"

namespace avmshell
{

    CSocketClass::CSocketClass(avmplus::VTable *cvtable)
        : avmplus::ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    CSocketClass::~CSocketClass()
    {
        
    }

    int CSocketClass::get_SOCK_RAW()
    {
        return SOCK_RAW;
    }

    int CSocketClass::get_SOCK_STREAM()
    {
        return SOCK_STREAM;
    }
    
    int CSocketClass::get_SOCK_DGRAM()
    {
        return SOCK_DGRAM;
    }


    int CSocketClass::get_SO_ACCEPTCONN()
    {
        return SO_ACCEPTCONN;
    }
    
    int CSocketClass::get_SO_BROADCAST()
    {
        return SO_BROADCAST;
    }
    
    int CSocketClass::get_SO_DONTROUTE()
    {
        return SO_DONTROUTE;
    }
    
    int CSocketClass::get_SO_KEEPALIVE()
    {
        return SO_KEEPALIVE;
    }
    
    int CSocketClass::get_SO_OOBINLINE()
    {
        return SO_OOBINLINE;
    }
    
    int CSocketClass::get_SO_RCVBUF()
    {
        return SO_RCVBUF;
    }
    
    int CSocketClass::get_SO_RCVTIMEO()
    {
        return SO_RCVTIMEO;
    }
    
    int CSocketClass::get_SO_REUSEADDR()
    {
        return SO_REUSEADDR;
    }
    
    int CSocketClass::get_SO_SNDBUF()
    {
        return SO_SNDBUF;
    }
    
    int CSocketClass::get_SO_SNDTIMEO()
    {
        return SO_SNDTIMEO;
    }
    
    int CSocketClass::get_SO_TYPE()
    {
        return SO_TYPE;
    }
    
    
    int CSocketClass::get_MSG_CTRUNC()
    {
        return MSG_CTRUNC;
    }
    
    int CSocketClass::get_MSG_DONTROUTE()
    {
        return MSG_DONTROUTE;
    }
    
    int CSocketClass::get_MSG_OOB()
    {
        return MSG_OOB;
    }
    
    int CSocketClass::get_MSG_PEEK()
    {
        return MSG_PEEK;
    }
    
    int CSocketClass::get_MSG_TRUNC()
    {
        return MSG_TRUNC;
    }
    
    int CSocketClass::get_MSG_WAITALL()
    {
        return MSG_WAITALL;
    }

    int CSocketClass::get_MSG_DONTWAIT()
    {
        return MSG_DONTWAIT;
    }
    

    int CSocketClass::get_AF_INET()
    {
        return AF_INET;
    }
    
    int CSocketClass::get_AF_INET6()
    {
        return AF_INET6;
    }
    
    int CSocketClass::get_AF_UNSPEC()
    {
        return AF_UNSPEC;
    }
    

    int CSocketClass::get_SHUT_RD()
    {
        return SHUT_RD;
    }
    
    int CSocketClass::get_SHUT_RDWR()
    {
        return SHUT_RDWR;
    }
    
    int CSocketClass::get_SHUT_WR()
    {
        return SHUT_WR;
    }


    int CSocketClass::get_IPPROTO_IP()
    {
        return IPPROTO_IP;
    }
    
    int CSocketClass::get_IPPROTO_IPV6()
    {
        return IPPROTO_IPV6;
    }
    
    int CSocketClass::get_IPPROTO_ICMP()
    {
        return IPPROTO_ICMP;
    }
    
    int CSocketClass::get_IPPROTO_RAW()
    {
        return IPPROTO_RAW;
    }
    
    int CSocketClass::get_IPPROTO_TCP()
    {
        return IPPROTO_TCP;
    }
    
    int CSocketClass::get_IPPROTO_UDP()
    {
        return IPPROTO_UDP;
    }


    int CSocketClass::get_SOMAXCONN()
    {
        return SOMAXCONN;
    }

    avmplus::ArrayObject * CSocketClass::__gethostbyaddr(avmplus::Stringp addr, bool numeric)
    {
        if (!addr) {
            toplevel()->throwArgumentError(kNullArgumentError, "addr");
        }
        
        avmplus::StUTF8String addrUTF8(addr);
        avmplus::ArrayObject *list = toplevel()->arrayClass()->newArray();
        
        int count = 0;
        struct in_addr **addr_list;
        struct hostent *host;
        host = VMPI_gethostbyaddr( addrUTF8.c_str() );
        
        if(host != NULL) {
            if(numeric) {
                addr_list = (struct in_addr **)host->h_addr_list;
                int i;
                for(i = 0; addr_list[i] != NULL; i++) {
                    list->setUintProperty(i, core()->newStringUTF8( inet_ntoa(*addr_list[i]) )->atom());
                }
            }
            else {
                list->setUintProperty(count++, core()->newStringUTF8( host->h_name )->atom());
                if(host->h_aliases) {
                    int x;
                    for(x=0; host->h_aliases[x]; ++x) {
                        list->setUintProperty(count++, core()->newStringUTF8( host->h_aliases[x] )->atom());
                    }
                }
            }
        }
        
        return list;
    }

    avmplus::ArrayObject * CSocketClass::__gethostbyname(avmplus::Stringp hostname, bool numeric)
    {
        if (!hostname) {
            toplevel()->throwArgumentError(kNullArgumentError, "hostname");
        }
        
        avmplus::StUTF8String hostnameUTF8(hostname);
        avmplus::ArrayObject *list = toplevel()->arrayClass()->newArray();
        
        int count = 0;
        
        struct in_addr **addr_list;
        struct hostent *host;
        
        host = gethostbyname(hostnameUTF8.c_str());
        
        if(host != NULL) {
            if(numeric) {
                addr_list = (struct in_addr **)host->h_addr_list;
                int i;
                for(i = 0; addr_list[i] != NULL; i++) {
                    list->setUintProperty(i, core()->newStringUTF8( inet_ntoa(*addr_list[i]) )->atom());
                }
            }
            else {
                list->setUintProperty(count++, core()->newStringUTF8( host->h_name )->atom());
                if(host->h_aliases) {
                    int x;
                    for(x=0; host->h_aliases[x]; ++x) {
                        list->setUintProperty(count++, core()->newStringUTF8( host->h_aliases[x] )->atom());
                    }
                }
            }
        }
        
        return list;
    }

    avmplus::Stringp CSocketClass::__getpeername(int descriptor)
    {
        socklen_t len;
        struct sockaddr_storage addr;
        char ipstr[INET6_ADDRSTRLEN];
        int port;

        len = sizeof addr;
        getpeername(descriptor, (struct sockaddr*)&addr, &len);

        // deal only with IPv4
        struct sockaddr_in *s = (struct sockaddr_in *)&addr;
        port = ntohs(s->sin_port);
        VMPI_inet_ntop(AF_INET, &s->sin_addr, ipstr, sizeof ipstr);
        
        //printf("Peer IP address: %s\n", ipstr);
        //printf("Peer port      : %d\n", port);

        avmplus::Stringp peer = core()->newStringUTF8( "" );
                         peer = peer->appendLatin1( ipstr );
                         peer = peer->appendLatin1( ":" );
                         peer = peer->appendLatin1( VMPI_int2char(port) );
        
        return peer;
    }

    avmplus::Stringp CSocketClass::__getsockname(int descriptor)
    {
        socklen_t len;
        struct sockaddr_storage addr;
        char ipstr[INET6_ADDRSTRLEN];
        int port;

        len = sizeof addr;
        getsockname(descriptor, (struct sockaddr*)&addr, &len);

        // deal only with IPv4
        struct sockaddr_in *s = (struct sockaddr_in *)&addr;
        port = ntohs(s->sin_port);
        VMPI_inet_ntop(AF_INET, &s->sin_addr, ipstr, sizeof ipstr);
        
        //printf("Local IP address: %s\n", ipstr);
        //printf("Local port      : %d\n", port);

        avmplus::Stringp local = core()->newStringUTF8( "" );
                         local = local->appendLatin1( ipstr );
                         local = local->appendLatin1( ":" );
                         local = local->appendLatin1( VMPI_int2char(port) );
        
        return local;
    }

}
