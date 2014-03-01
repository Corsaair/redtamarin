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

//for const MAX_PATH in C.stdlib
//#include <limits.h> //already included in win32-platform.h

//for C.stdlib
//#include <stdlib.h> //already included in win32-platform.h

//for C.errno
#include <errno.h>

////for const in C.unistd, for _S_IREAD etc.
#include <sys/stat.h>

//for _access, _unlink, _setmode
#include <io.h>

//for _O_BINARY, _O_TEXT
#include <fcntl.h>

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

// ---- C.errno ---- END


// ---- C.float ---- 

// ---- C.float ---- END


// ---- C.limits ---- 

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
