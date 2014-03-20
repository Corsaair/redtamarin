/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmplus_unix_platform2__
#define __avmplus_unix_platform2__

// ==== BEFORE ==== 
/* for special case that need to be defined first */

//we need to redefine FD_SETSIZE before the select.h include
#undef FD_SETSIZE
#define FD_SETSIZE 4096


// ==== HEADERS ==== 

//for const MAX_PATH in C.stdlib
//#include <limits.h> //already included in mac-platform.h

//for C.stdlib
//#include <stdlib.h> //already included in mac-platform.h

//for fileno(), popen()
//#include <stdio.h> //already included in mac-platform.h

//for select(), FD_SET(), etc. used by SocketClass
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
//for FIONREAD
#include <sys/ioctl.h>


//for uname(), in avmplus.OperatingSystem
#include <sys/utsname.h>

//for statvfs(), in avmplus.FileSystem
#include <sys/statvfs.h>

//for opendir(), readdir(), closedir(), DIR, etc., in avmplus.FileSystem
#include <dirent.h>

//for setlocale, used with VMPI_getLocale
#include <locale.h>


// ==== ISO C / ANSI C ==== 

// ---- C.assert ---- 

// ---- C.assert ---- END


// ---- C.ctype ---- 

// ---- C.ctype ---- END


// ---- C.errno ---- 
//#include <errno.h> //already included in unix-platform.h

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
#define VMPI_remove      ::remove
#define VMPI_rename      ::rename
#define VMPI_popen       ::popen
#define VMPI_pclose      ::pclose
// ---- C.stdio ---- END


// ---- C.stdlib ---- 

// ---- C.stdlib ---- END


// ---- C.string ---- 
#define VMPI_strerror    ::strerror
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
#define VMPI_creat        ::creat
#define VMPI_open         ::open

//solaris compat
#ifndef FIONREAD
  #include <sys/filio.h> /* Solaris 2 puts it here */
#endif

//macintosh compat
#ifndef O_SHLOCK
# define O_SHLOCK 0x0000
#endif

#ifndef O_EXLOCK
# define O_EXLOCK 0x0000
#endif

//windows compat
#ifndef O_TEXT
# define O_TEXT 0x0000
#endif

#ifndef O_BINARY
# define O_BINARY 0x0000
#endif

#ifndef O_WTEXT
# define O_WTEXT 0x0000
#endif

#ifndef O_U16TEXT
# define O_U16TEXT 0x0000
#endif

#ifndef O_U8TEXT
# define O_U8TEXT 0x0000
#endif

#ifndef O_RAW
# define O_RAW 0x0000
#endif

#ifndef O_NOINHERIT
# define O_NOINHERIT 0x0000
#endif

#ifndef O_TEMPORARY
# define O_TEMPORARY 0x0000
#endif

#ifndef O_SHORT_LIVED
# define O_SHORT_LIVED 0x0000
#endif

#ifndef O_SEQUENTIAL
# define O_SEQUENTIAL 0x0000
#endif

#ifndef O_RANDOM
# define O_RANDOM 0x0000
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
#define VMPI_access      ::access
#define VMPI_chdir       ::chdir
#define VMPI_getcwd      ::getcwd
#define VMPI_gethostname ::gethostname
#define VMPI_getpid      ::getpid
#define VMPI_rmdir       ::rmdir
#define VMPI_unlink      ::unlink
// ---- C.unistd ---- END


// ---- C.utime ---- 

// ---- C.utime ---- END



// ==== MISC ==== 

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

#define VMPI_inet_ntop   ::inet_ntop


#endif // __avmplus_unix_platform2__
