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

        int get_INADDR_ANY();
        int get_INADDR_BROADCAST();

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



}

#endif /* __avmshell_CNetinetInClass__ */

