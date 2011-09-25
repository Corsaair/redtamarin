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
    
    bool PosixSocket::Bind(const char* host, const int port)
    {
        if(!IsValid()) {
            return false;
        }

        sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        //addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
        addr.sin_addr.s_addr = inet_addr(host);
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
#ifdef AVMPLUS_MAC
        //nothing
#else
        flags |= MSG_NOSIGNAL;
#endif
        int status = send(_socket, data, len, flags);
        return status;
    }

    int PosixSocket::SendTo(const char* host, const char* port, const char* data, int len, int flags) const
    {
        if(!IsValid()) {
            return -1;
        }

#ifdef AVMPLUS_MAC
        //nothing
#else
        flags |= MSG_NOSIGNAL;
#endif
        
        //int type = GetType();
        int type;
        socklen_t tlen = sizeof(type);
        int tstatus = getsockopt(_socket, SOL_SOCKET, SO_TYPE, &type, &tlen);
        if(tstatus != 0) {
            printf( "GetType status = %i", tstatus );
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

        // Connect.
        //status = connect(_socket, result->ai_addr, result->ai_addrlen);
        //freeaddrinfo(result);
        //return status == 0;
        
        //int sendto(int sockfd, const void *msg, int len, unsigned int flags, const struct sockaddr *to, socklen_t tolen);
        status = sendto(_socket, data, len, flags, result->ai_addr, result->ai_addrlen);
        return status;
    }
    
    int PosixSocket::Receive(char* data, int len, int flags) const
    {
        int status = recv(_socket, data, len, flags);
        return status;
    }
    
    int PosixSocket::ReceiveFrom(char* data, int len, int flags) const
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


    int PosixSocket::GetDescriptor()
    {
        return _socket;
    }

    int PosixSocket::GetType()
    {
        int type;
        socklen_t len = sizeof(type);
        int status = getsockopt(_socket, SOL_SOCKET, SO_TYPE, &type, &len);
        if(status != 0) {
            //printf( "GetType status = %i\n", status );
            return status; //we want to return -1 in case of problem
        }
        return type;
    }

    bool PosixSocket::GetBlocking()
    {
        return _blocking;
    }
    
    void PosixSocket::SetBlocking(bool is_blocking)
    {
        int flags = fcntl(_socket, F_SETFL, 0);
        if(flags < 0) {
            printf( "Could not access blocking status = %i\n", flags );
            return;
        }
        
        flags = is_blocking ? (flags&~O_NONBLOCK) : (flags|O_NONBLOCK);
        int status = fcntl(_socket, F_SETFL, flags);
        if(status != 0) {
            printf( "Could not change blocking status = %i\n", status );
        }
        _blocking = is_blocking;
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

    int PosixSocket::GetReceiveTimeout()
    {
        struct timeval tv;
        socklen_t len = sizeof(tv);
        int status = getsockopt(_socket, SOL_SOCKET, SO_RCVTIMEO, &tv, &len);
        if(status == 0)
        {
            return (int)tv.tv_sec;
        }

        return 0;
    }

    void PosixSocket::SetReceiveTimeout(int sec)
    {
        struct timeval tv;
        tv.tv_sec  = sec;
        tv.tv_usec = 0;
        setsockopt(_socket, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));
    }

    int PosixSocket::GetSendTimeout()
    {
        struct timeval tv;
        socklen_t len = sizeof(tv);
        int status = getsockopt(_socket, SOL_SOCKET, SO_SNDTIMEO, &tv, &len);
        if(status == 0)
        {
            return (int)tv.tv_sec;
        }

        return 0;
    }
    
    void PosixSocket::SetSendTimeout(int sec)
    {
        struct timeval tv;
        tv.tv_sec  = sec;
        tv.tv_usec = 0;
        setsockopt(_socket, SOL_SOCKET, SO_SNDTIMEO, &tv, sizeof(tv));
    }

    void PosixSocket::SetNoSigPipe()
    {
#ifdef AVMPLUS_MAC
        int on = 1;
        setsockopt(_socket, SOL_SOCKET, SO_NOSIGPIPE, &on, sizeof(on));
#else
        //nothing
#endif
    }

    int PosixSocket::isReadable(int sec)
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
    
    int PosixSocket::isWritable(int sec)
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
    
    int PosixSocket::isExceptional(int sec)
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


    bool PosixSocket::_available = true;

    bool PosixSocket::Setup()
    {
        //nothing to do on POSIX
        return true;
    }

    bool PosixSocket::isSupported()
    {
        return PosixSocket::_available;
    }

    const char *PosixSocket::_version = "Berkeley sockets";

    const char *PosixSocket::getSocketVersion()
    {
        return PosixSocket::_version;
    }

    int PosixSocket::getLastError()
    {
        return errno;
    }
    
    int PosixSocket::getMaxSelectDescriptor()
    {
        return FD_SETSIZE;
    }

}


