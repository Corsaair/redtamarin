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

#include "avmplus.h"


// ---- C.stdlib ---- 

int VMPI_setenv(const char *name, const char *value, int overwrite)
{
    return setenv(name, value, overwrite);
}

int VMPI_unsetenv(const char *name)
{
    return unsetenv(name);
}

char *VMPI_realpath(char const *path)
{
    char resolved[PATH_MAX];
    return realpath(path, resolved);
}

// ---- C.stdlib ---- END


// ---- C.unistd ---- 

int VMPI_chmod(const char *path, int mode)
{
    return chmod(path, (mode_t)mode);
}

int VMPI_mkdir(const char *path)
{
    //S_IRWXU = Read, write, execute/search by owner.
    //S_IRWXG = Read, write, execute/search by group.
    //S_IRWXO = Read, write, execute/search by others.
    return mkdir(path, S_IRWXU | S_IRWXG | S_IRWXO);
}

void VMPI_sleep(int milliseconds)
{
    usleep(1000 * milliseconds);
}

/* note:
   1. getpwuid( geteuid() ) shall return the name associated with the effective user ID of the process
   2. getlogin() shall return the name associated with the current login activity
   3. getpwuid( getuid() ) shall return the name associated with the real user ID of the process
*/
void VMPI_getUserName(char *username)
{
    struct passwd *pws;
    pws = getpwuid( geteuid() );
    VMPI_strcpy( username, pws->pw_name );
}

// ---- C.unistd ---- END


// ---- C.socket ---- 

struct hostent *VMPI_gethostbyaddr(const char *addr)
{
    struct in_addr ipv4addr;
    
    inet_pton(AF_INET, addr, &ipv4addr);
    return gethostbyaddr(&ipv4addr, sizeof ipv4addr, AF_INET);
}

// ---- C.socket ---- END

