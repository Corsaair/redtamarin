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

#ifndef __avmshell_PosixSocket__
#define __avmshell_PosixSocket__

#include "Socket.h"

namespace avmshell
{
    class PosixSocket : public Socket
    {
    public:
        explicit PosixSocket()
        {
            // Create the default socket.
            _socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
            _blocking = true;
        }
        explicit PosixSocket(int family, int socktype, int protocol)
        {
            // Create the custom socket.
            _socket = socket(family, socktype, protocol);
            _blocking = true;
        }
        explicit PosixSocket(int socket): _socket(socket) { _blocking = true; }
        virtual ~PosixSocket() { Shutdown(); }

        bool Bind(const char* host, const int port);
        bool Listen(int backlog) const;
        int Accept() const;

        bool Connect(const char* host, const char* port);
        bool Shutdown();
        
        int Send(const char* data, int len, int flags) const;
        int SendTo(const char* host, const char* port, const char* data, int len, int flags) const;
        int Receive(char* data, int len, int flags) const;
        int ReceiveFrom(char* data, int len, int flags) const;

        int GetDescriptor();
        int GetType();

        bool GetBlocking();
        void SetBlocking(bool is_blocking);
        
        bool GetReuseAddress();
        void SetReuseAddress(bool reuse_address);

        bool GetBroadcast();
        void SetBroadcast(bool broadcast);

        int GetReceiveTimeout();
        void SetReceiveTimeout(int sec);

        int GetSendTimeout();
        void SetSendTimeout(int sec);
        
        void SetNoSigPipe();

        bool IsValid() const { return _socket != -1; }

        int isReadable(int sec);
        int isWritable(int sec);
        int isExceptional(int sec);

        static bool Setup();
        static bool isSupported();
        static const char *getSocketVersion();
        static int getLastError();
        static int getMaxSelectDescriptor();

        
    private:
        static bool _available;
        static const char *_version;
        
        int _socket;
        bool _blocking;
    };
}

#endif /* __avmshell_PosixSocket__ */

