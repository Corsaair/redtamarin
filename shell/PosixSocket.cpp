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
*   Adobe AS3 Team
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

#include "PosixSocket.h"

namespace avmshell
{
    
    bool PosixSocket::Bind(const int port)
    {
        if(!IsValid()) {
            return false;
        }

        sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
        addr.sin_port = htons(port);
        int status = bind(_socket,
                          reinterpret_cast<struct sockaddr *>(&addr),
                          sizeof(addr));
        return status == 0;
    }

    bool PosixSocket::Listen(int backlog) const
    {
        if(!IsValid()) {
            return false;
        }

        int status = listen(_socket, backlog);
        return status == 0;
    }

    int PosixSocket::Accept() const
    {
        if(!IsValid()) {
            return NULL;
        }
        
        int socket = accept(_socket, NULL, NULL);
        return socket;
    }
    
    /*
    bool PosixSocket::Connect(const char* host, const char* port)
    {
        if(!IsValid()) {
            return false;
        }

        // Lookup host and port.
        struct addrinfo *result = NULL;
        struct addrinfo hints;
        memset(&hints, 0, sizeof(addrinfo));
        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_protocol = IPPROTO_TCP;
        int status = getaddrinfo(host, port, &hints, &result);
        if(status != 0) {
            return false;
        }

        // Connect.
        status = connect(_socket, result->ai_addr, result->ai_addrlen);
        freeaddrinfo(result);
        return status == 0;
    }
    */

    bool PosixSocket::Connect(const char* host, const char* port)
    {
        if(!IsValid()) {
            return false;
        }

        int type = GetType();
        // Lookup host and port.
        struct addrinfo *result = NULL;
        struct addrinfo hints;
        memset(&hints, 0, sizeof(addrinfo));
        hints.ai_family = AF_INET;

        switch(type)
        {
            case SOCK_STREAM:
            hints.ai_socktype = SOCK_STREAM;
            hints.ai_protocol = IPPROTO_TCP;
            break;

            case SOCK_DGRAM:
            hints.ai_socktype = SOCK_DGRAM;
            hints.ai_protocol = IPPROTO_UDP;
            break;
        }

        int status = getaddrinfo(host, port, &hints, &result);
        if(status != 0) {
            return false;
        }

        // Connect.
        status = connect(_socket, result->ai_addr, result->ai_addrlen);
        freeaddrinfo(result);
        return status == 0;
    }

    bool PosixSocket::Shutdown()
    {
        if(IsValid()) {
            // Shutdown socket for both read and write.
            int status = shutdown(_socket, SHUT_RDWR);
            //printf( "PosixSocket::Shutdown status = %d\n", status );
            close(_socket);
            _socket = -1;
            return status == 0;
        }
        
        return true;
    }

    int PosixSocket::Send(const char* data, int len, int flags) const
    {
        int status = send(_socket, data, len, flags);
        return status;
    }
    
    int PosixSocket::Receive(char* data, int len, int flags) const
    {
        int status = recv(_socket, data, len, flags);
        return status;
    }


    int PosixSocket::GetType()
    {
        int type;
        socklen_t len = sizeof(type);
        int status = getsockopt(_socket, SOL_SOCKET, SO_TYPE, &type, &len);
        if(status != 0) {
            printf( "GetType status = %i", status );
        }
        return type;
    }

    bool PosixSocket::GetReuseAddress()
    {
        int on;
        socklen_t len = sizeof(on);
        int status = getsockopt(_socket, SOL_SOCKET, SO_REUSEADDR, &on, &len);
        if(status == 0)
        {
            return (bool)on;
        }

        return false;
    }

    void PosixSocket::SetReuseAddress(bool reuse_address)
    {
        int on = reuse_address ? 1 : 0;
        setsockopt(_socket, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
    }

    bool PosixSocket::GetBroadcast()
    {
        int on;
        socklen_t len = sizeof(on);
        int status = getsockopt(_socket, SOL_SOCKET, SO_BROADCAST, &on, &len);
        if(status == 0)
        {
            return (bool)on;
        }

        return false;
    }
    
    void PosixSocket::SetBroadcast(bool broadcast)
    {
        int on = broadcast ? 1 : 0;
        setsockopt(_socket, SOL_SOCKET, SO_BROADCAST, &on, sizeof(on));
    }

    bool PosixSocket::Setup()
    {
        //nothing to do on POSIX
        return true;
    }

    int PosixSocket::LastError()
    {
        return errno;
    }


}


