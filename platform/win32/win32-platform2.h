/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* -*- tab-width: 4 -*- */
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

#ifndef __avmplus_win32_platform2__
#define __avmplus_win32_platform2__

//for const MAX_PATH in C.stdlib
//#include <limits.h> //already included in win32-platform.h

//for C.stdlib
//#include <stdlib.h> //already included in win32-platform.h

//for C.errno
#include <errno.h>

////for const in C.unistd, for _S_IREAD etc.
#include <sys/stat.h>

//for _access, _unlink
#include <io.h>

//for _chdir, _getcwd, _rmdir, 
#include <direct.h>


//for gethostname, gethostbyaddr
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")



//C.string
#define VMPI_strerror    ::strerror

//C.unistd
#define VMPI_access         _access       //_waccess
#define VMPI_chdir          _chdir        //_wchdir
#define VMPI_getcwd         _getcwd       //_wgetcwd

/* note:
   #define VMPI_gethostname    ::gethostname
   can't do that
   we define a signature here
   and impl. the function in WinPortUtils2.cpp
   so we can call WIN32_SocketStart
*/
int VMPI_gethostname(char *name, int namelen);

#define VMPI_rmdir          _rmdir        //_wrmdir
#define VMPI_unlink         _unlink       //_wunlink

//C.stdio
#define VMPI_remove    ::remove           //_wremove
#define VMPI_rename    ::rename           //_wrename




//a lot of definitions to align with POSIX
#if !defined(ECURDIR)
  #define ECURDIR          EACCES
#endif /* !ECURDIR */
#if !defined(ENOSYS)
  #define ENOSYS           EPERM
#endif /* !ENOSYS */

#if !defined(ENETDOWN)
  #define ENETDOWN         WSAENETDOWN
#endif /* !ENETDOWN */

#if !defined(ENETUNREACH)
  #define ENETUNREACH      WSAENETUNREACH
#endif /* !ENETUNREACH */

#if !defined(ENETRESET)
  #define ENETRESET        WSAENETRESET
#endif /* !ENETRESET */

#if !defined(ECONNABORTED)
  #define ECONNABORTED     WSAECONNABORTED
#endif /* !ECONNABORTED */

#if !defined(ECONNRESET)
  #define ECONNRESET       WSAECONNRESET
#endif /* !ECONNRESET */

#if !defined(ENOBUFS)
  #define ENOBUFS          WSAENOBUFS
#endif /* !ENOBUFS */

#if !defined(EISCONN)
  #define EISCONN          WSAEISCONN
#endif /* !EISCONN */

#if !defined(ENOTCONN)
  #define ENOTCONN         WSAENOTCONN
#endif /* !ENOTCONN */

#if !defined(ESHUTDOWN)
  #define ESHUTDOWN        WSAESHUTDOWN
#endif /* !ESHUTDOWN */

#if !defined(ETOOMANYREFS)
  #define ETOOMANYREFS     WSAETOOMANYREFS
#endif /* !ETOOMANYREFS */

#if !defined(ETIMEDOUT)
  #define ETIMEDOUT        WSAETIMEDOUT
#endif /* !ETIMEDOUT */

#if !defined(ECONNREFUSED)
  #define ECONNREFUSED     WSAECONNREFUSED
#endif /* !ECONNREFUSED */

#if !defined(SHUT_RD)
  #define SHUT_RD          SD_RECEIVE
#endif /* !SHUT_RD */

#if !defined(SHUT_RDWR)
  #define SHUT_RDWR        SD_BOTH
#endif /* !SHUT_RDWR */

#if !defined(SHUT_WR)
  #define SHUT_WR          SD_SEND
#endif /* !SHUT_WR */



#if !defined(FILENAME_MAX)
  #define FILENAME_MAX   _MAX_FNAME
#endif /* !FILENAME_MAX */

#if !defined(PATH_MAX)
  #define PATH_MAX       _MAX_PATH
#endif /* !PATH_MAX */



#if !defined(S_IFMT)
  #define S_IFMT    _S_IFMT    /* 0xF000 file type mask */
#endif
#if !defined(S_IFDIR)
  #define S_IFDIR   _S_IFDIR   /* 0x4000 directory */
#endif
#if !defined(S_IFCHR)
  #define S_IFCHR   _S_IFCHR   /* 0x2000 character special */
#endif
#if !defined(S_IFIFO)
  #define S_IFIFO   _S_IFIFO   /* 0x1000 pipe */
#endif
#if !defined(S_IFREG)
  #define S_IFREG   _S_IFREG   /* 0x8000 regular */
#endif
#if !defined(S_IREAD)
  #define S_IREAD   _S_IREAD   /* 0x0100 read permission, owner */
#endif
#if !defined(S_IWRITE)
  #define S_IWRITE  _S_IWRITE   /* 0x0080 write permission, owner */
#endif
#if !defined(S_IEXEC)
  #define S_IEXEC   _S_IEXEC   /* 0x0040 execute/search permission, owner */
#endif

//not used under WIN32, added for AS3 API
#if !defined(S_IFBLK)
  #define S_IFBLK   0060000   /* [XSI] block special */
#endif
#if !defined(S_IFLNK)
  #define S_IFLNK   0120000   /* [XSI] symbolic link */
#endif
#if !defined(S_IFSOCK)
  #define S_IFSOCK  0140000   /* [XSI] socket */
#endif



#if !defined(F_OK)
  #define F_OK        0
#endif /* !F_OK */
#if !defined(X_OK)
  #define X_OK        1
#endif /* !X_OK */
#if !defined(W_OK)
  #define W_OK        2
#endif /* !W_OK */
#if !defined(R_OK)
  #define R_OK        4
#endif /* !R_OK */



#ifndef DT_UNKNOWN
  #define DT_UNKNOWN      0
#endif /* !DT_UNKNOWN */
#ifndef DT_FIFO
  #define DT_FIFO         1
#endif /* !DT_FIFO */
#ifndef DT_CHR
  #define DT_CHR          2
#endif /* !DT_CHR */
#ifndef DT_DIR
  #define DT_DIR          4
#endif /* !DT_DIR */
#ifndef DT_BLK
  #define DT_BLK          6
#endif /* !DT_BLK */
#ifndef DT_REG
  #define DT_REG          8
#endif /* !DT_REG */
#ifndef DT_LNK
  #define DT_LNK          10
#endif /* !DT_LNK */
#ifndef DT_SOCK
  #define DT_SOCK         12
#endif /* !DT_SOCK */
#ifndef DT_WHT
  #define DT_WHT          14
#endif /* !DT_WHT */



/** \def NUM_ELEMENTS(ar)
 *
 * Evaluates the size of an array.
 *
 * \param ar The array.
 *
 * \warning This produces unintended behaviour if used with a pointer, and
 *  undefined behaviour if used, in C++, with a user-defined type that
 *  defines a subscript operator. See Chapter 14 of <em>Imperfect C++</em>
 *  (http://www.imperfectcplusplus.com/)
 */

#ifndef NUM_ELEMENTS
  #define NUM_ELEMENTS(ar)      (sizeof(ar) / sizeof(0[ar]))
#endif /* !NUM_ELEMENTS */

#ifndef FILE_ATTRIBUTE_ERROR
  #define FILE_ATTRIBUTE_ERROR           (0xFFFFFFFF)
#endif /* FILE_ATTRIBUTE_ERROR */



#ifndef S_ISDIR
  #define S_ISDIR(mode)  (((mode) & S_IFMT) == S_IFDIR)
#endif

#ifndef S_ISREG
  #define S_ISREG(mode)  (((mode) & S_IFMT) == S_IFREG)
#endif

#ifndef S_ISLNK
  #define S_ISLNK(mode)  (((mode) & S_IFMT) == S_IFLNK)
#endif



/**
 * chmod
 */

typedef int mode_t;

//as WIN32 does not have GRP and OTH rights, we map them to the USR rights
static const mode_t S_IRUSR      = mode_t(S_IREAD);      // read by user
static const mode_t S_IWUSR      = mode_t(S_IWRITE);     // write by user
static const mode_t S_IXUSR      = 0;                    // does nothing
static const mode_t S_IRGRP      = mode_t(S_IREAD);      // read by *USER*
static const mode_t S_IWGRP      = mode_t(S_IWRITE);     // write by *USER*
static const mode_t S_IXGRP      = 0;                    // does nothing
static const mode_t S_IROTH      = mode_t(S_IREAD);      // read by *USER*
static const mode_t S_IWOTH      = mode_t(S_IWRITE);     // write by *USER*
static const mode_t S_IXOTH      = 0;                    // does nothing

static const mode_t S_IRWXU      = S_IRUSR | S_IWUSR | S_IXUSR;
static const mode_t S_IRWXG      = S_IRGRP | S_IWGRP | S_IXGRP;
static const mode_t S_IRWXO      = S_IROTH | S_IWOTH | S_IXOTH;


#endif // __avmplus_win32_platform2__
