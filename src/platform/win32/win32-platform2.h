/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmplus_win32_platform2__
#define __avmplus_win32_platform2__

// ==== BEFORE ==== 
/* for special case that need to be defined first */

//we need to define FD_SETSIZE before the winsock.h include
#ifndef FD_SETSIZE
#define FD_SETSIZE      4096
#endif /* FD_SETSIZE */ 


// ==== HEADERS ==== 

//for C.stdlib
//#include <stdlib.h> //already included in win32-platform.h

////for const in C.unistd, for _S_IREAD etc.
#include <sys/stat.h>

//for _access, _unlink, _setmode
#include <io.h>

//for _kbhit
#include <conio.h>

//for _chdir, _getcwd, _rmdir, 
#include <direct.h>

//for socket, gethostname, gethostbyaddr
//Winsock 1.1, in WinSocket::Setup() use MAKEWORD(1, 1)
//#include <winsock.h>
//#pragma comment(lib, "wsock32.lib")
//Winsock 2.0, in WinSocket::Setup() use MAKEWORD(2, 0)
#include <winsock2.h>
#pragma comment(lib, "ws2_32.lib")
//for struct addrinfo
#include <ws2tcpip.h>

//other
#pragma comment(lib, "user32.lib")

//for setlocale, used with VMPI_getLocale
#include <locale.h>

//for _getpid
#include <process.h>


// ==== ISO C / ANSI C ==== 

// ---- C.assert ---- 

// ---- C.assert ---- END


// ---- C.ctype ---- 

// ---- C.ctype ---- END


// ---- C.errno ---- 
#include <errno.h>
//extern void VMPI_set_errno(int value); // defined in VMPI2.h
//extern int VMPI_get_errno(); // defined in VMPI2.h

//posix compat
#ifndef ENOTBLK
# define ENOTBLK 15
#endif

#ifndef EINVAL
# define EINVAL 22
#endif

//do not define ETXTBSY as 26
//MSVC define it as 139

#ifndef ERANGE
# define ERANGE 34
#endif

//posix compat from winsock2.h
#ifndef EREMOTE
# define EREMOTE WSAEREMOTE
#endif

#ifndef EUSERS
# define EUSERS WSAEUSERS
#endif

#ifndef ESOCKTNOSUPPORT
# define ESOCKTNOSUPPORT WSAESOCKTNOSUPPORT
#endif

#ifndef EPFNOSUPPORT
# define EPFNOSUPPORT WSAEPFNOSUPPORT
#endif

#ifndef ESHUTDOWN
# define ESHUTDOWN WSAESHUTDOWN
#endif

#ifndef ETOOMANYREFS
# define ETOOMANYREFS WSAETOOMANYREFS
#endif

#ifndef EHOSTDOWN
# define EHOSTDOWN WSAEHOSTDOWN
#endif

#ifndef ESTALE
# define ESTALE WSAESTALE
#endif

#ifndef EDQUOT
# define EDQUOT WSAEDQUOT
#endif

/* Based on Gnulib we start defining non-supported errno values from 2000
   Mac OS X largest errno is ELAST 106
   Windows largest errno is EWOULDBLOCK 140
   WinSock2 smallest error code is WSABASEERR 10000
   WinSock2 largest error code is WSA_QOS_RESERVED_PETYPE 10000+1031=11031 

   eg. if any systems start to support some of those values we will have to update and recompile
*/
//POSIX compat
#ifndef EMULTIHOP
# define EMULTIHOP 2000
#endif

//Linux compat
#ifndef ECHRNG
# define ECHRNG 2001
#endif

#ifndef EL2NSYNC
# define EL2NSYNC 2002
#endif

#ifndef EL3HLT
# define EL3HLT 2003
#endif

#ifndef EL3RST
# define EL3RST 2004
#endif

#ifndef ELNRNG
# define ELNRNG 2005
#endif

#ifndef EUNATCH
# define EUNATCH 2006
#endif

#ifndef ENOCSI
# define ENOCSI 2007
#endif

#ifndef EL2HLT
# define EL2HLT 2008
#endif

#ifndef EBADE
# define EBADE 2009
#endif

#ifndef EBADR
# define EBADR 2010
#endif

#ifndef EXFULL
# define EXFULL 2011
#endif

#ifndef ENOANO
# define ENOANO 2012
#endif

#ifndef EBADRQC
# define EBADRQC 2013
#endif

#ifndef EBADSLT
# define EBADSLT 2014
#endif

#ifndef EBFONT
# define EBFONT 2015
#endif

#ifndef ENONET
# define ENONET 2016
#endif

#ifndef ENOPKG
# define ENOPKG 2017
#endif

#ifndef EADV
# define EADV 2018
#endif

#ifndef ESRMNT
# define ESRMNT 2019
#endif

#ifndef ECOMM
# define ECOMM 2020
#endif

#ifndef EDOTDOT
# define EDOTDOT 2021
#endif

#ifndef ENOTUNIQ
# define ENOTUNIQ 2022
#endif

#ifndef EBADFD
# define EBADFD 2023
#endif

#ifndef EREMCHG
# define EREMCHG 2024
#endif

#ifndef ELIBACC
# define ELIBACC 2025
#endif

#ifndef ELIBBAD
# define ELIBBAD 2026
#endif

#ifndef ELIBSCN
# define ELIBSCN 2027
#endif

#ifndef ELIBMAX
# define ELIBMAX 2028
#endif

#ifndef ELIBEXEC
# define ELIBEXEC 2029
#endif

#ifndef ERESTART
# define ERESTART 2030
#endif

#ifndef ESTRPIPE
# define ESTRPIPE 2031
#endif

#ifndef EUCLEAN
# define EUCLEAN 2032
#endif

#ifndef ENOTNAM
# define ENOTNAM 2033
#endif

#ifndef ENAVAIL
# define ENAVAIL 2034
#endif

#ifndef EISNAM
# define EISNAM 2035
#endif

#ifndef EREMOTEIO
# define EREMOTEIO 2036
#endif

#ifndef ENOMEDIUM
# define ENOMEDIUM 2037
#endif

#ifndef EMEDIUMTYPE
# define EMEDIUMTYPE 2038
#endif

#ifndef ENOKEY
# define ENOKEY 2039
#endif

#ifndef EKEYEXPIRED
# define EKEYEXPIRED 2040
#endif

#ifndef EKEYREVOKED
# define EKEYREVOKED 2041
#endif

#ifndef EKEYREJECTED
# define EKEYREJECTED 2042
#endif

#ifndef ERFKILL
# define ERFKILL 2043
#endif

#ifndef EHWPOISON
# define EHWPOISON 2044
#endif
// ---- C.errno ---- END


// ---- C.float ---- 

// ---- C.float ---- END


// ---- C.limits ---- 
//#include <limits.h> //already included in win32-platform.h

//POSIX compat
//ARG_MAX  14500       /* 16k heap, minus overhead */

//from POSIX, min acceptable value
/* from http://msdn.microsoft.com/en-us/library/tze57ck3.aspx
   atexit and _onexit use the heap to hold the register of functions.
   Thus, the number of functions that can be registered is limited only by heap memory.

   so again 16k heap minus overhead could be 14500
   but because we defien 32 already for mac and linux
   and that 32 is good enough let's keep it also for windows
*/
#ifndef ATEXIT_MAX
# define ATEXIT_MAX 32
#endif

//from POSIX, min acceptable value
/* from http://blogs.technet.com/b/markrussinovich/archive/2009/07/08/3261309.aspx
   Q: how many processes can you run concurrently on Windows?
   A: depends
   
   in short it depens on the amount of memory and CPU ...
*/
#ifndef CHILD_MAX
# define CHILD_MAX 25
#endif

//LINK_MAX  1024

//MAX_CANON  255
//MAX_INPUT  255
//NAME_MAX  255
//OPEN_MAX  32
//PATH_MAX  512
//PIPE_BUF  512
//SSIZE_MAX  32767
//STREAM_MAX  20
//TZNAME_MAX  10

//POSIX compat
#define _POSIX_SYMLINK_MAX           255
#define _POSIX_AIO_LISTIO_MAX        2
#define _POSIX_AIO_MAX               1
#define _POSIX_DELAYTIMER_MAX        32
#define _POSIX_HOST_NAME_MAX         255
#define _POSIX_MQ_OPEN_MAX           8
#define _POSIX_MQ_PRIO_MAX           32
#define _POSIX_RE_DUP_MAX            255
#define _POSIX_RTSIG_MAX             8
#define _POSIX_SEM_NSEMS_MAX         256
#define _POSIX_SEM_VALUE_MAX         32767
#define _POSIX_SIGQUEUE_MAX          32
#define _POSIX_SS_REPL_MAX           4
#define _POSIX_SYMLOOP_MAX           8
#define _POSIX_TIMER_MAX             32
#define _POSIX_TRACE_EVENT_NAME_MAX  30
#define _POSIX_TRACE_NAME_MAX        8
#define _POSIX_TRACE_SYS_MAX         8
#define _POSIX_TRACE_USER_EVENT_MAX  32
#define _POSIX_TTY_NAME_MAX          9

//POSIX support

#ifndef SYMLINK_MAX
# define SYMLINK_MAX  _POSIX_SYMLINK_MAX
#endif

#ifndef AIO_LISTIO_MAX
# define AIO_LISTIO_MAX  _POSIX_AIO_LISTIO_MAX
#endif

#ifndef AIO_MAX
# define AIO_MAX  _POSIX_AIO_MAX
#endif

#ifndef AIO_PRIO_DELTA_MAX
# define AIO_PRIO_DELTA_MAX 0
#endif

#ifndef DELAYTIMER_MAX
# define DELAYTIMER_MAX  _POSIX_DELAYTIMER_MAX
#endif

#ifndef HOST_NAME_MAX
# define HOST_NAME_MAX  MAX_COMPUTERNAME_LENGTH+1
#endif

/* NOTE:
   UNLEN 256 (eg. User Name Length)
   is defined in Lmcons.h
*/
#ifndef LOGIN_NAME_MAX
# define LOGIN_NAME_MAX  UNLEN
#endif

#ifndef MQ_OPEN_MAX
# define MQ_OPEN_MAX  _POSIX_MQ_OPEN_MAX
#endif

#ifndef MQ_PRIO_MAX
# define MQ_PRIO_MAX  _POSIX_MQ_PRIO_MAX
#endif

#ifndef PAGE_SIZE
# define PAGE_SIZE 4096
#endif

#ifndef PAGESIZE
# define PAGESIZE PAGE_SIZE
#endif

#ifndef RE_DUP_MAX
# define RE_DUP_MAX _POSIX_RE_DUP_MAX
#endif

#ifndef RTSIG_MAX
# define RTSIG_MAX _POSIX_RTSIG_MAX
#endif

#ifndef SEM_NSEMS_MAX
# define SEM_NSEMS_MAX _POSIX_SEM_NSEMS_MAX
#endif

#ifndef SEM_VALUE_MAX
# define SEM_VALUE_MAX _POSIX_SEM_VALUE_MAX
#endif

#ifndef SIGQUEUE_MAX
# define SIGQUEUE_MAX _POSIX_SIGQUEUE_MAX
#endif

#ifndef SS_REPL_MAX
# define SS_REPL_MAX _POSIX_SS_REPL_MAX
#endif

#ifndef SYMLOOP_MAX
# define SYMLOOP_MAX  _POSIX_SYMLOOP_MAX
#endif

#ifndef TIMER_MAX
# define TIMER_MAX  _POSIX_TIMER_MAX
#endif

#ifndef TRACE_EVENT_NAME_MAX
# define TRACE_EVENT_NAME_MAX  _POSIX_TRACE_EVENT_NAME_MAX
#endif

#ifndef TRACE_NAME_MAX
# define TRACE_NAME_MAX  _POSIX_TRACE_NAME_MAX
#endif

#ifndef TRACE_SYS_MAX
# define TRACE_SYS_MAX  _POSIX_TRACE_SYS_MAX
#endif

#ifndef TRACE_USER_EVENT_MAX
# define TRACE_USER_EVENT_MAX  _POSIX_TRACE_USER_EVENT_MAX
#endif

#ifndef TTY_NAME_MAX
# define TTY_NAME_MAX  _POSIX_TTY_NAME_MAX
#endif

// ---- C.limits ---- END


// ---- C.locale ---- 

// ---- C.locale ---- END


// ---- C.math ---- 

// ---- C.math ---- END


// ---- C.setjmp ---- 

// ---- C.setjmp ---- END


// ---- C.signal ---- 

// ---- C.signal ---- END


// ---- C.stdarg ---- 

// ---- C.stdarg ---- END


// ---- C.stddef ---- 

// ---- C.stddef ---- END


// ---- C.stdio ---- 

// ---- C.stdio ---- END


// ---- C.stdlib ---- 

// ---- C.stdlib ---- END


// ---- C.string ---- 

// ---- C.string ---- END


// ---- C.time ---- 

// ---- C.time ---- END




// ==== POSIX ==== 

// ---- C.conio ---- 

// ---- C.conio ---- END


// ---- C.cpio ---- 

// ---- C.cpio ---- END


// ---- C.dirent ---- 

// ---- C.dirent ---- END


// ---- C.fcntl ---- 
//for fcntl()
#include <fcntl.h>
#define VMPI_creat        ::_creat
#define VMPI_open         ::_open

//posix compat
#ifndef O_ACCMODE
# define O_ACCMODE O_RDONLY | O_WRONLY | O_RDWR
#endif

#ifndef O_CLOEXEC
# define O_CLOEXEC 0x0000
#endif

#ifndef O_DIRECTORY
# define O_DIRECTORY 0x0000
#endif

#ifndef O_NOFOLLOW
# define O_NOFOLLOW 0x0000
#endif

#ifndef O_NONBLOCK
# define O_NONBLOCK 0x0000
#endif

#ifndef O_NOCTTY
# define O_NOCTTY 0x0000
#endif

#ifndef O_SYNC
# define O_SYNC 0x0000
#endif

#ifndef O_RSYNC
# define O_RSYNC 0x0000
#endif

#ifndef O_ASYNC
# define O_ASYNC 0x0000
#endif

#ifndef O_FSYNC
# define O_FSYNC 0x0000
#endif

#ifndef O_EXEC
# define O_EXEC 0x0000
#endif

#ifndef O_SEARCH
# define O_SEARCH 0x0000
#endif

#ifndef O_TTY_INIT
# define O_TTY_INIT 0x0000
#endif

//macintosh compat
#ifndef O_SHLOCK
# define O_SHLOCK 0x0000
#endif

#ifndef O_EXLOCK
# define O_EXLOCK 0x0000
#endif
// ---- C.fcntl ---- END


// ---- C.grp ---- 

// ---- C.grp ---- END


// ---- C.netdb ---- 

// ---- C.netdb ---- END


// ---- C.pthread ---- 

// ---- C.pthread ---- END


// ---- C.pwd ---- 

// ---- C.pwd ---- END


// ---- C.spawn ---- 

// ---- C.spawn ---- END


// ---- C.sys.ipc ---- 

// ---- C.sys.ipc ---- END


// ---- C.sys.mman ---- 

// ---- C.sys.mman ---- END


// ---- C.sys.msg ---- 

// ---- C.sys.msg ---- END


// ---- C.sys.sem ---- 

// ---- C.sys.sem ---- END


// ---- C.sys.socket ---- 

// ---- C.sys.socket ---- END


// ---- C.sys.stat ---- 

// ---- C.sys.stat ---- END


// ---- C.sys.time ---- 

// ---- C.sys.time ---- END


// ---- C.sys.types ---- 

// ---- C.sys.types ---- END


// ---- C.sys.utsname ---- 

// ---- C.sys.utsname ---- END


// ---- C.sys.wait ---- 

// ---- C.sys.wait ---- END


// ---- C.tar ---- 

// ---- C.tar ---- END


// ---- C.termios ---- 

// ---- C.termios ---- END


// ---- C.unistd ---- 

// ---- C.unistd ---- END


// ---- C.utime ---- 

// ---- C.utime ---- END



// ==== MISC ==== 

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

#define VMPI_getpid         _getpid
#define VMPI_rmdir          _rmdir        //_wrmdir
#define VMPI_unlink         _unlink       //_wunlink

//C.stdio
#define VMPI_remove    ::remove           //_wremove
#define VMPI_rename    ::rename           //_wrename
#define VMPI_popen     _popen             //_wpopen //not defined in C.stdio, used by SystemClass::popenRead
#define VMPI_pclose    _pclose                      //not defined in C.stdio, used by SystemClass::popenRead



#if !defined(NONBLOCKING_DISABLE)
  #define NONBLOCKING_DISABLE          0
#endif /* !NONBLOCKING_DISABLE */

#if !defined(NONBLOCKING_ENABLE)
  #define NONBLOCKING_ENABLE           1
#endif /* !NONBLOCKING_ENABLE */



//a lot of definitions to align with POSIX
#if !defined(ECURDIR)
  #define ECURDIR          EACCES
#endif /* !ECURDIR */
#if !defined(ENOSYS)
  #define ENOSYS           EPERM
#endif /* !ENOSYS */


#if !defined(EWOULDBLOCK)
  #define EWOULDBLOCK        WSAEWOULDBLOCK
#endif /* !EWOULDBLOCK */

#if !defined(EINPROGRESS)
  #define EINPROGRESS        WSAEINPROGRESS
#endif /* !EINPROGRESS */

#if !defined(EALREADY)
  #define EALREADY        WSAEALREADY
#endif /* !EALREADY */

#if !defined(EDESTADDRREQ)
  #define EDESTADDRREQ          WSAEDESTADDRREQ
#endif /* !EDESTADDRREQ */

#if !defined(EMSGSIZE)
  #define EMSGSIZE          WSAEMSGSIZE
#endif /* !EMSGSIZE */

#if !defined(EPROTOTYPE)
  #define EPROTOTYPE          WSAEPROTOTYPE
#endif /* !EPROTOTYPE */

#if !defined(ENOPROTOOPT)
  #define ENOPROTOOPT          WSAENOPROTOOPT
#endif /* !ENOPROTOOPT */

#if !defined(EADDRINUSE)
  #define EADDRINUSE          WSAEADDRINUSE
#endif /* !EADDRINUSE */

#if !defined(EADDRNOTAVAIL)
  #define EADDRNOTAVAIL          WSAEADDRNOTAVAIL
#endif /* !EADDRNOTAVAIL */

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

#if !defined(ELOOP)
  #define ELOOP          WSAELOOP
#endif /* !ELOOP */

#if !defined(EHOSTDOWN)
  #define EHOSTDOWN          WSAEHOSTDOWN
#endif /* !EHOSTDOWN */

#if !defined(EHOSTUNREACH)
  #define EHOSTUNREACH          WSAEHOSTUNREACH
#endif /* !EHOSTUNREACH */



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



#if !defined(O_TEXT)
  #define O_TEXT          _O_TEXT
#endif /* !O_TEXT */

#if !defined(O_BINARY)
  #define O_BINARY       _O_BINARY
#endif /* !O_BINARY */



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


/**
 * dirent
 */

// this is a big sortcut to be able to use dirent directly in a native class
typedef struct dirent
{
    char *d_name;
    int d_type;
} dirent;

typedef struct DIR
{
    long                handle; /* -1 for failed rewind */
    struct _finddata_t  info;
    struct dirent       result; /* d_name null if first time */
    char                *name;  /* null-terminated char string */
} DIR;


extern DIR           *opendir(const char *name);
extern int           closedir(DIR *dir);
extern struct dirent *readdir(DIR *dir);
extern void          rewinddir(DIR *dir);


/**
 * uname
 */

#ifndef _UTSNAME_LENGTH
  #define _UTSNAME_LENGTH 255
#endif

#ifndef _UTSNAME_NODENAME_LENGTH
  #define _UTSNAME_NODENAME_LENGTH _UTSNAME_LENGTH
#endif

struct utsname
{
  char sysname[_UTSNAME_LENGTH];            // Name of the operating system
  char nodename[_UTSNAME_NODENAME_LENGTH];  // Name of this node on the network
  char release[_UTSNAME_LENGTH];            // Current release level
  char version[_UTSNAME_LENGTH];            // Current version level of this release
  char machine[_UTSNAME_LENGTH];            // Name of the hardware type the system is running on
};

#ifndef VER_SUITE_WH_SERVER
  #define VER_SUITE_WH_SERVER     0x00008000
#endif

#ifndef PRODUCT_PROFESSIONAL
  #define PRODUCT_PROFESSIONAL    0x00000030
#endif

extern int uname (struct utsname *uts);

/**
 * missing in WIN32 socket
 */

#if !defined(MSG_DONTWAIT)
  #define MSG_DONTWAIT        0
#endif /* !MSG_DONTWAIT */


#if !defined(INET6_ADDRSTRLEN)
  #define INET6_ADDRSTRLEN    46
#endif /* !INET6_ADDRSTRLEN */

typedef int socklen_t;

//const char *inet_ntop(int af, const void *restrict src, char *restrict dst, socklen_t size);
extern const char* VMPI_inet_ntop(int af, const void* src, char* dst, int cnt);





//for C.sys.wait

//see http://docs.huihoo.com/doxygen/postgresql/include_2port_2win32_8h_source.html
//see http://www.postgresql.org/message-id/200701220452.l0M4qtf04022@momjian.us
/*
 *  Signal stuff
 *
 *  For WIN32, there is no wait() call so there are no wait() macros
 *  to interpret the return value of system().  Instead, system()
 *  return values < 0x100 are used for exit() termination, and higher
 *  values are used to indicated non-exit() termination, which is
 *  similar to a unix-style signal exit (think SIGSEGV ==
 *  STATUS_ACCESS_VIOLATION).  Return values are broken up into groups:
 *
 *  http://msdn2.microsoft.com/en-gb/library/aa489609.aspx
 *
 *      NT_SUCCESS          0 - 0x3FFFFFFF
 *      NT_INFORMATION      0x40000000 - 0x7FFFFFFF
 *      NT_WARNING          0x80000000 - 0xBFFFFFFF
 *      NT_ERROR            0xC0000000 - 0xFFFFFFFF
 *
 *  Effectively, we don't care on the severity of the return value from
 *  system(), we just need to know if it was because of exit() or generated
 *  by the system, and it seems values >= 0x100 are system-generated.
 *  See this URL for a list of WIN32 STATUS_* values:
 *
 *      Wine (URL used in our error messages) -
 *          http://source.winehq.org/source/include/ntstatus.h
 *      Descriptions - http://www.comp.nus.edu.sg/~wuyongzh/my_doc/ntstatus.txt
 *      MS SDK - http://www.nologs.com/ntstatus.html
 *
 *  It seems the exception lists are in both ntstatus.h and winnt.h, but
 *  ntstatus.h has a more comprehensive list, and it only contains
 *  exception values, rather than winnt, which contains lots of other
 *  things:
 *
 *      http://www.microsoft.com/msj/0197/exception/exception.aspx
 *
 *      The ExceptionCode parameter is the number that the operating system
 *      assigned to the exception. You can see a list of various exception codes
 *      in WINNT.H by searching for #defines that start with "STATUS_". For
 *      example, the code for the all-too-familiar STATUS_ACCESS_VIOLATION is
 *      0xC0000005. A more complete set of exception codes can be found in
 *      NTSTATUS.H from the Windows NT DDK.
 *
 *  Some day we might want to print descriptions for the most common
 *  exceptions, rather than printing an include file name.  We could use
 *  RtlNtStatusToDosError() and pass to FormatMessage(), which can print
 *  the text of error values, but MinGW does not support
 *  RtlNtStatusToDosError().
 */
#define WEXITSTATUS(w)  ((int) ((w) & 0x40000000))
#define WIFEXITED(w)    ((w) & 0x40000000) == 0)
#define WIFSIGNALED(w)  ((w) & 0x40000000) != 0)
#define WTERMSIG(w)     (w) // or ((w) & 0x3FFFFFFF)

//see https://gitorious.org/git-win32/mainline/source/9ae6b7513158e0b1523766c9ad4a1ad286a96e2c:win32/git-compat-win32.h#L222


#endif // __avmplus_win32_platform2__
