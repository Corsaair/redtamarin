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
* The Original Code is [Open Source Machine.].
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

#include "PosixPartialPlatform.h"
#include "PosixFile.h"
#include "PosixSocket.h"

namespace avmshell
{
    void PosixPartialPlatform::exit(int code)
    {
        ::exit(code);
    }

    File* PosixPartialPlatform::createFile()
    {
        return mmfx_new( PosixFile() );
    }

    void PosixPartialPlatform::destroyFile(File* file)
    {
        mmfx_delete( file );
    }


    Socket* PosixPartialPlatform::createSocket()
    {
        return mmfx_new( PosixSocket() );
    }

    Socket* PosixPartialPlatform::createCustomSocket(int family, int socktype, int protocol)
    {
        return mmfx_new( PosixSocket(family, socktype, protocol) );
    }
    
    Socket* PosixPartialPlatform::createSocketFrom(int sd)
    {
        return mmfx_new( PosixSocket(sd) );
    }
    
    void PosixPartialPlatform::destroySocket(Socket* socket)
    {
        mmfx_delete( socket );
    }

    bool PosixPartialPlatform::isSocketSupported()
    {
        return PosixSocket::isSupported();
    }

    const char *PosixPartialPlatform::getSocketVersion()
    {
        return PosixSocket::getSocketVersion();
    }

    int PosixPartialPlatform::getLastSocketError()
    {
        return PosixSocket::getLastError();
    }

    int PosixPartialPlatform::getMaxSelectDescriptor()
    {
        return PosixSocket::getMaxSelectDescriptor();
    }


    void PosixPartialPlatform::initializeLogging(const char* filename)
    {
        FILE *f = freopen(filename, "w", stdout);
        if (!f)
            AvmLog("freopen %s failed.\n",filename);
    }

    int PosixPartialPlatform::logMessage(const char* message)
    {
        return fprintf(stdout, "%s", message);
    }

    char* PosixPartialPlatform::getUserInput(char* buffer, int bufferSize)
    {
        fflush(stdout);
        if (fgets(buffer, bufferSize, stdin) == NULL) {
            // EOF or error
            *buffer = 0;
            return NULL;
        }
        return buffer;
    }
}
