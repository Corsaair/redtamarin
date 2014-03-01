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


    int CNetinetInClass::get_INADDR_ANY() { return INADDR_ANY; }
    int CNetinetInClass::get_INADDR_BROADCAST() { return INADDR_BROADCAST; }

    int CNetinetInClass::get_INET_ADDRSTRLEN() { return INET_ADDRSTRLEN; }
    int CNetinetInClass::get_INET6_ADDRSTRLEN() { return INET6_ADDRSTRLEN; }

    int CNetinetInClass::get_IPV6_JOIN_GROUP() { return IPV6_JOIN_GROUP; }
    int CNetinetInClass::get_IPV6_LEAVE_GROUP() { return IPV6_LEAVE_GROUP; }
    int CNetinetInClass::get_IPV6_MULTICAST_HOPS() { return IPV6_MULTICAST_HOPS; }
    int CNetinetInClass::get_IPV6_MULTICAST_IF() { return IPV6_MULTICAST_IF; }
    int CNetinetInClass::get_IPV6_MULTICAST_LOOP() { return IPV6_MULTICAST_LOOP; }
    int CNetinetInClass::get_IPV6_UNICAST_HOPS() { return IPV6_UNICAST_HOPS; }
    int CNetinetInClass::get_IPV6_V6ONLY() { return IPV6_V6ONLY; }



}
