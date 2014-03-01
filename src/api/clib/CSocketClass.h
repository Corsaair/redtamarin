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

#ifndef __avmshell_CSocketClass__
#define __avmshell_CSocketClass__

namespace avmshell
{

    class CSocketClass : public avmplus::ClassClosure
    {
    public:
        CSocketClass(avmplus::VTable* cvtable);
        ~CSocketClass();

        int get_SOCK_RAW();
        int get_SOCK_STREAM();
        int get_SOCK_DGRAM();

        int get_SO_ACCEPTCONN();
        int get_SO_BROADCAST();
        int get_SO_DONTROUTE();
        int get_SO_KEEPALIVE();
        int get_SO_OOBINLINE();
        int get_SO_RCVBUF();
        int get_SO_RCVTIMEO();
        int get_SO_REUSEADDR();
        int get_SO_SNDBUF();
        int get_SO_SNDTIMEO();
        int get_SO_TYPE();

        int get_MSG_CTRUNC();
        int get_MSG_DONTROUTE();
        int get_MSG_OOB();
        int get_MSG_PEEK();
        int get_MSG_TRUNC();
        int get_MSG_WAITALL();
        int get_MSG_DONTWAIT();

        int get_AF_INET();
        int get_AF_INET6();
        int get_AF_UNSPEC();

        int get_SHUT_RD();
        int get_SHUT_RDWR();
        int get_SHUT_WR();

        int get_IPPROTO_IP();
        int get_IPPROTO_IPV6();
        int get_IPPROTO_ICMP();
        int get_IPPROTO_RAW();
        int get_IPPROTO_TCP();
        int get_IPPROTO_UDP();

        int get_SOMAXCONN();

        avmplus::ArrayObject * __gethostbyaddr(avmplus::Stringp addr, bool numeric);
        avmplus::ArrayObject * __gethostbyname(avmplus::Stringp hostname, bool numeric);
        avmplus::Stringp __getpeername(int descriptor);
        avmplus::Stringp __getsockname(int descriptor);
        
        DECLARE_SLOTS_CSocketClass;
    };

}

#endif /* __avmshell_CSocketClass__ */
