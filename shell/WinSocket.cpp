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
    
    bool WinSocket::Bind(const char* host, const int port)
    {
        if(!IsValid()) {
            return false;
        }

        sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        //addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
        addr.sin_addr.s_addr = inet_addr(host);
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

    int WinSocket::SendTo(const char* host, const char* port, const char* data, int len, int flags) const
    {
        if(!IsValid()) {
            return -1;
        }
        
        //inline GetType()
        int type;
        int tlen = sizeof(type);
        int tstatus = getsockopt(_socket, SOL_SOCKET, SO_TYPE, (char*)&type, &tlen);
        if(tstatus != 0) {
            //printf( "GetType status = %i", tstatus );
            return tstatus;
        }
        
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
            return -1;
        }
        
        status = sendto(_socket, data, len, flags, result->ai_addr, result->ai_addrlen);
        return status;
    }

    
    int WinSocket::Receive(char* data, int len, int flags) const
    {
        int status = recv(_socket, data, len, flags);
        return status;
    }

    int WinSocket::ReceiveFrom(char* data, int len, int flags) const
    {
        if(!IsValid()) {
            return -1;
        }
        
        struct sockaddr_storage their_addr;
        socklen_t addr_len;
        addr_len = sizeof their_addr;
        
        int status = recvfrom(_socket, data, len, flags, (struct sockaddr *)&their_addr, &addr_len);
        //TODO: save the received address and port
        return status;
    }


    int WinSocket::GetDescriptor()
    {
        if(IsValid()) {
            return (int)_socket;
        }
        return -1; //we don't want to return INVALID_SOCKET
    }
    
    int WinSocket::GetType()
    {
        int val;
        int len = sizeof(val);
        int status = getsockopt(_socket, SOL_SOCKET, SO_TYPE, (char*)&val, &len);
        if(status != 0) {
            //printf( "GetType status = %i", status );
            return status; //we want to return -1 in case of problem
        }
        return val;
    }

    bool WinSocket::GetBlocking()
    {
        return _blocking;
    }
    
    void WinSocket::SetBlocking(bool is_blocking)
    {
        unsigned long flags = is_blocking ? 0 : 1;
        
        int status = ioctlsocket(_socket, FIONBIO, &flags);
        if(status != 0) {
            printf( "Could not change blocking status = %i\n", status );
        }
        
        _blocking = is_blocking;
    }

    bool WinSocket::GetReuseAddress()
    {
        int val;
        int len = sizeof(val);
        int status = getsockopt(_socket, SOL_SOCKET, SO_REUSEADDR, (char*)&val, &len);
        if(status == 0) {
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

    int WinSocket::GetReceiveTimeout()
    {
        int timeout;
        int len = sizeof(timeout);
        int status = getsockopt(_socket, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout, &len);
        if(status == 0)
        {
            return (int)timeout/1000;
        }

        return 0;
    }

    void WinSocket::SetReceiveTimeout(int sec)
    {
        int timeout = sec * 1000;
        int len = sizeof(timeout);
        setsockopt(_socket, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout, len);
    }

    int WinSocket::GetSendTimeout()
    {
        int timeout;
        int len = sizeof(timeout);
        int status = getsockopt(_socket, SOL_SOCKET, SO_SNDTIMEO, (char*)&timeout, &len);
        if(status == 0)
        {
            return (int)timeout/1000;
        }

        return 0;
    }
    
    void WinSocket::SetSendTimeout(int sec)
    {
        int timeout = sec * 1000;
        int len = sizeof(timeout);
        setsockopt(_socket, SOL_SOCKET, SO_SNDTIMEO, (char*)&timeout, len);
    }

    void WinSocket::SetNoSigPipe()
    {
        /*
        Under Unix, if you’re blocking on send() and your program is ignoring the SIGPIPE signal,
        it will return with a -1 when the remote peer disconnects, and errno will be EPIPE.
        Otherwise, your program will be sent the SIGPIPE signal,
        which will terminate your program if you don’t handle it.

        Under Winsock, the SIGPIPE/EPIPE functionality does not exist at all:
        send() will either return 0 for a normal disconnect or -1 for an abnormal disconnect,
        with WSAGetLastError() returning the same errors as in the recv() discussion above.
        */
    }

    int WinSocket::isReadable(int sec)
    {
        if(!IsValid()) {
            return -1;
        }
        
        int status;
        fd_set fds;
        struct timeval tv;
        
        FD_ZERO(&fds);
        FD_SET(_socket,&fds);
        tv.tv_sec  = sec;
        tv.tv_usec = 0;
        
        status = select(_socket+1, &fds, NULL, NULL, &tv);
        
        if( status < 0 ) {
            return -1;
        }
        
        return FD_ISSET(_socket,&fds) ? 1 : 0;
    }
    
    int WinSocket::isWritable(int sec)
    {
        if(!IsValid()) {
            return -1;
        }
        
        int status;
        fd_set fds;
        struct timeval tv;
        
        FD_ZERO(&fds);
        FD_SET(_socket,&fds);
        tv.tv_sec  = sec;
        tv.tv_usec = 0;

        status = select(_socket+1, NULL, &fds, NULL, &tv);

        if( status < 0 ) {
            return -1;
        }

        return FD_ISSET(_socket,&fds) ? 1 : 0;
    }
    
    int WinSocket::isExceptional(int sec)
    {
        if(!IsValid()) {
            return -1;
        }
        
        int status;
        fd_set fds;
        struct timeval tv;
        
        FD_ZERO(&fds);
        FD_SET(_socket,&fds);
        tv.tv_sec  = sec;
        tv.tv_usec = 0;
        
        status = select(_socket+1, NULL, NULL, &fds, &tv);

        if( status < 0 ) {
            return -1;
        }

        return FD_ISSET(_socket,&fds) ? 1 : 0;
    }

    bool WinSocket::_available = false;

    bool WinSocket::Setup()
    {
        /*
        //initialize Winsock32
        WSADATA winsock_data;
        WORD version_requested;
        int err;
        
        //version_requested = MAKEWORD(1, 1); //Winsock 1.1
        //version_requested = MAKEWORD(2, 0); //Winsock 2.0
        version_requested = MAKEWORD(2, 2); //Winsock 2.2
        err = WSAStartup(version_requested, &winsock_data);
        
        if(err != 0) {
            printf( "Unable to initialize Winsock, err = %d\n", WinSocket::getLastError() );
        }
        
        return err == 0;
        */
        
        bool available = false;
        WSADATA winsock_data;
        
        /* note:
           Here we initialize Winsock trying the highest version first
           then falling back to older versions until we get one which works
        */
        if( WSAStartup(MAKEWORD(2,2), &winsock_data) == 0 ) {
            //printf( "Winsock 2.2\n" );
            WinSocket::_version = "Winsock 2.2";
            available = true;
        }
        else if( WSAStartup(MAKEWORD(2,1), &winsock_data) == 0 ) {
            //printf( "Winsock 2.1\n" );
            WinSocket::_version = "Winsock 2.1";
            available = true;
        }
        else if( WSAStartup(MAKEWORD(2,0), &winsock_data) == 0 ) {
            //printf( "Winsock 2.0\n" );
            WinSocket::_version = "Winsock 2.0";
            available = true;
        }
        else if( WSAStartup(MAKEWORD(1,1), &winsock_data) == 0 ) {
            //printf( "Winsock 1.1\n" );
            WinSocket::_version = "Winsock 1.1";
            available = true;
        }
        else if( WSAStartup(MAKEWORD(1,0), &winsock_data) == 0 ) {
            //printf( "Winsock 1.0\n" );
            WinSocket::_version = "Winsock 1.0";
            available = true;
        }
        else {
            printf( "WSAStartup failed, no winsock available.\n" );
        }
        
        WinSocket::_available = available;
        return available;
    }

    bool WinSocket::isSupported()
    {
        return WinSocket::_available;
    }

    const char *WinSocket::_version = "Winsock";

    const char *WinSocket::getSocketVersion()
    {
        return WinSocket::_version;
    }

    int WinSocket::getLastError()
    {
        return WSAGetLastError();
    }
    
    int WinSocket::getMaxSelectDescriptor()
    {
        return FD_SETSIZE;
    }

}


