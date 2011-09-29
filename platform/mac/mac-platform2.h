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
 * Portions created by the Initial Developer are Copyright (C) 1993-2006
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

#ifndef __avmplus_mac_platform2__
#define __avmplus_mac_platform2__

//for const MAX_PATH in C.stdlib
//#include <limits.h> //already included in mac-platform.h

//for C.stdlib
//#include <stdlib.h> //already included in mac-platform.h

//for fileno(), popen()
//#include <stdio.h> //already included in mac-platform.h

//for select(), FD_SET(), etc. used by SocketClass
//we need to redefine FD_SETSIZE before the select.h include
#undef FD_SETSIZE
#define FD_SETSIZE 4096
#include <sys/select.h>

//for mode_t, needed with chmod
#include <sys/types.h>

//for const in C.unistd, chmod()
//for stat(), in avmplus.FileSystem
#include <sys/stat.h>

//for VMPI_getUserName()/getpwuid() used in C.unistd
#include <pwd.h>

//for const in C.socket
#include <sys/socket.h>
#include <netinet/in.h>

//for C.socket gethostbyaddr(), gethostbyname()
#include <arpa/inet.h>
#include <netdb.h>

//for ioctl()
#include <sys/ioctl.h>
//for fcntl()
#include <fcntl.h>
//for FIONREAD
#include <sys/filio.h>

//for uname(), in avmplus.OperatingSystem
#include <sys/utsname.h>

//for statvfs(), in avmplus.FileSystem
#include <sys/statvfs.h>

//for opendir(), readdir(), closedir(), DIR, etc., in avmplus.FileSystem
#include <dirent.h>

//for setlocale, used with VMPI_getLocale
#include <locale.h>



//C.string
#define VMPI_strerror    ::strerror

//C.unistd
#define VMPI_access      ::access
#define VMPI_chdir       ::chdir
#define VMPI_getcwd      ::getcwd
#define VMPI_gethostname ::gethostname
#define VMPI_getpid      ::getpid
#define VMPI_rmdir       ::rmdir
#define VMPI_unlink      ::unlink


//C.stdio
#define VMPI_remove      ::remove
#define VMPI_rename      ::rename
#define VMPI_popen       ::popen  //not defined in C.stdio, used by SystemClass::popenRead
#define VMPI_pclose      ::pclose //not defined in C.stdio, used by SystemClass::popenRead


#if !defined(NONBLOCKING_DISABLE)
  #define NONBLOCKING_DISABLE          0
#endif /* !NONBLOCKING_DISABLE */

#if !defined(NONBLOCKING_ENABLE)
  #define NONBLOCKING_ENABLE           1
#endif /* !NONBLOCKING_ENABLE */



#if !defined(O_TEXT)
  #define O_TEXT          0x4000
#endif /* !O_TEXT */

#if !defined(O_BINARY)
  #define O_BINARY        0x8000
#endif /* !O_BINARY */



//avmplus.Socket
#define VMPI_inet_ntop   ::inet_ntop

#endif // __avmplus_mac_platform2__
