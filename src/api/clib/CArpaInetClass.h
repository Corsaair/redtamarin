/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_CArpaInetClass__
#define __avmshell_CArpaInetClass__

namespace avmshell
{
    using namespace avmplus;

    class CArpaInetClass : public ClassClosure
    {
    public:
        CArpaInetClass(VTable* cvtable);
        ~CArpaInetClass();

        uint32_t _htonl(uint32_t hostlong);
        uint32_t _htons(uint32_t hostshort);
        uint32_t _ntohl(uint32_t netlong);
        uint32_t _ntohs(uint32_t netshort);

        uint32_t _inet_addr(Stringp cp);
        uint32_t _inet_network(Stringp cp);
        Stringp _inet_ntoa(CIn_AddrObject* inaddr);
        int _inet_aton(Stringp cp, CIn_AddrObject* inp);
        Stringp _inet_ntop4(int af, CSockaddr_inObject* src);
        Stringp _inet_ntop6(int af, CSockaddr_in6Object* src);
        int _inet_pton4(int af, Stringp src, CSockaddr_inObject* dst);
        int _inet_pton6(int af, Stringp src, CSockaddr_in6Object* dst);

        DECLARE_SLOTS_CArpaInetClass;
    };


}

#endif /* __avmshell_CArpaInetClass__ */

