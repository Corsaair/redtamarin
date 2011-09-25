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

#ifndef __avmshell_Socket__
#define __avmshell_Socket__

#include "avmshell.h"

namespace avmshell
{
    /**
    * Abstract base class for performing platform-specific socket operations
    * This class needs to be derived and its methods implemented by platform
    * to enable the shell to perform basic blocking sockets
    */
    class Socket
    {
    public:

        /**
        * Virtual Destructor
        */
        virtual ~Socket() {}

        // Server initialization.
        virtual bool Bind(const char* host, const int port) = 0;
        virtual bool Listen(int backlog) const = 0;
        virtual int Accept() const = 0;

        // Client initialization.
        virtual bool Connect(const char* host, const char* port) = 0;

        // Shutdown socket for both read and write. This causes blocking Send and
        // Receive calls to exit. After Shutdown the Socket object cannot be used for
        // any communication.
        virtual bool Shutdown() = 0;

        // Data Transimission
        virtual int Send(const char* data, int len, int flags) const = 0;
        virtual int SendTo(const char* host, const char* port, const char* data, int len, int flags) const = 0;
        virtual int Receive(char* data, int len, int flags) const = 0;
        virtual int ReceiveFrom(char* data, int len, int flags) const = 0;

        // Get the socket descriptor
        virtual int GetDescriptor() = 0;

        // Get the value of the SO_TYPE socket option.
        virtual int GetType() = 0;

        // Get/Set the socket blocking mode
        virtual bool GetBlocking() = 0;
        virtual void SetBlocking(bool is_blocking) = 0;
        
        // Get/Set the value of the SO_REUSEADDR socket option.
        virtual bool GetReuseAddress() = 0;
        virtual void SetReuseAddress(bool reuse_address) = 0;

        // Get/Set the value of the SO_BROADCAST socket option.
        virtual bool GetBroadcast() = 0;
        virtual void SetBroadcast(bool broadcast) = 0;

        // Get/Set the value of the SO_RCVTIMEO socket option.
        virtual int GetReceiveTimeout() = 0;
        virtual void SetReceiveTimeout(int sec) = 0;

        // Get/Set the value of the SO_SNDTIMEO socket option.
        virtual int GetSendTimeout() = 0;
        virtual void SetSendTimeout(int sec) = 0;

        virtual void SetNoSigPipe() = 0;

        virtual bool IsValid() const = 0;

        virtual int isReadable(int sec) = 0;
        virtual int isWritable(int sec) = 0;
        virtual int isExceptional(int sec) = 0;

        static bool Setup();
        static bool isSupported();
        static const char *getSocketVersion();
        static int getLastError();
        static int getMaxSelectDescriptor();
        
    };
}

#endif /* __avmshell_Socket__ */
