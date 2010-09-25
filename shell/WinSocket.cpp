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

#include "WinSocket.h"

namespace avmshell
{
    
    bool WinSocket::Bind(const int port)
    {
        if(!IsValid()) {
            return false;
        }

        sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
        addr.sin_port = htons( (u_short)port );
        int status = bind(_socket,
                          reinterpret_cast<struct sockaddr *>(&addr),
                          sizeof(addr));
        return status == 0;
    }

    bool WinSocket::Listen(int backlog) const
    {
        if(!IsValid()) {
            return false;
        }

        int status = listen(_socket, backlog);
        return status == 0;
    }

    int WinSocket::Accept() const
    {
        if(!IsValid()) {
            return NULL;
        }
        
        SOCKET socket = accept(_socket, NULL, NULL);
        
        /* note:
           see: http://stackoverflow.com/questions/1953639/is-it-safe-to-cast-socket-to-int-under-win64
           ----
           Even though sizeof(SOCKET) is 8, it's safe to cast it to int, because
           the value constitutes an index in per-process table of limited size
           and not a real pointer.
           ----
        */
        return (int)socket;
    }
    
    bool WinSocket::Connect(const char* host, const char* port)
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
        //status = connect(_socket, result->ai_addr, result->ai_addrlen);
        status = connect(_socket, result->ai_addr, static_cast<int>(result->ai_addrlen));
        freeaddrinfo(result);
        return status == 0;
    }

    bool WinSocket::Shutdown()
    {
        if(IsValid()) {
            // Shutdown socket for both read and write.
            /*
            int status = shutdown(_socket, SHUT_RDWR);
            //printf( "PosixSocket::Shutdown status = %d\n", status );
            close(_socket);
            _socket = -1;
            return status == 0;
            */
            int status = shutdown(_socket, SD_BOTH);
            closesocket(_socket);
            _socket = INVALID_SOCKET;
            return status == SOCKET_ERROR;
        }
        
        return true;
    }

    int WinSocket::Send(const char* data, int len, int flags) const
    {
        int status = send(_socket, data, len, flags);
        return status;
    }
    
    int WinSocket::Receive(char* data, int len, int flags) const
    {
        int status = recv(_socket, data, len, flags);
        return status;
    }
    
    int WinSocket::GetType()
    {
        int val;
        int len = sizeof(val);
        int status = getsockopt(_socket, SOL_SOCKET, SO_TYPE, (char*)&val, &len);
        if(status != 0) {
            printf( "GetType status = %i", status );
        }
        return val;
    }

    bool WinSocket::GetReuseAddress()
    {
        int val;
        int len = sizeof(val);
        int status = getsockopt(_socket, SOL_SOCKET, SO_REUSEADDR, (char*)&val, &len);
        if(status == 0) {
            //return (bool)val;
            return val != 0;
        }
        return false;
    }

    void WinSocket::SetReuseAddress(bool reuse_address)
    {
        int val = reuse_address ? 1 : 0;
        int len = sizeof(val);
        setsockopt(_socket, SOL_SOCKET, SO_REUSEADDR, (char*)&val, len);
    }

    bool WinSocket::GetBroadcast()
    {
        int val;
        int len = sizeof(val);
        int status = getsockopt(_socket, SOL_SOCKET, SO_BROADCAST, (char*)&val, &len);
        if(status == 0) {
            //return (bool)val;
            return val != 0;
        }
        return false;
    }
    
    void WinSocket::SetBroadcast(bool broadcast)
    {
        int val = broadcast ? 1 : 0;
        int len = sizeof(val);
        setsockopt(_socket, SOL_SOCKET, SO_BROADCAST, (char*)&val, len);
    }

    bool WinSocket::Setup()
    {
        //initialize Winsock32
        WSADATA winsock_data;
        WORD version_requested;
        int err;
        
        version_requested = MAKEWORD(1, 0);
        err = WSAStartup(version_requested, &winsock_data);
        
        if(err != 0) {
            printf( "Unable to initialize Winsock, err = %d\n", WinSocket::LastError() );
        }
        
        return err == 0;
    }

    int WinSocket::LastError()
    {
        return WSAGetLastError();
    }


}


