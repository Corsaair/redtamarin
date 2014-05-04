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

//for C.stdlib
//#include <stdlib.h> //already included in unix-platform.h

//for fileno(), popen()
//#include <stdio.h> //already included in unix-platform.h

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
//#include <limits.h> //already included in unix-platform.h

/* NOTE:
   Linux does not provide fixed values for
   ARG_MAX, ATEXIT_MAX, CHILD_MAX, OPEN_MAX,
   PAGESIZE, PAGE_SIZE, PASS_MAX, etc.

   at our level we need fixed valaues
   but still we try to define the bigger one possible
   not necessarily UINT32_MAX/UINT64_MAX
*/

//POSIX compat
//from linux/limits.h:#define ARG_MAX 131072	/* # bytes of args + environ for exec() */
#ifndef ARG_MAX
# define ARG_MAX 131072
#endif

//from POSIX, min acceptable value
#ifndef ATEXIT_MAX
# define ATEXIT_MAX 32
#endif

//from POSIX, min acceptable value
#ifndef CHILD_MAX
# define CHILD_MAX 25
#endif

//from linux/limits.h:#define LINK_MAX 127	/* # links a file may have */
/* NOTE:
   from http://www.gossamer-threads.com/lists/linux/kernel/103610?do=post_view_threaded#103610

   Just a quick question - why is LINK_MAX in limits.h restricted to 
   127? EXT2_LINK_MAX is 32000, so is there any reason for keeping 
   the value of LINK_MAX so low? 

   As far as I know symlinks are handled by recursive mechanisms inside the 
   kernel, and amount of kernel stack is limited. 

   LINK_MAX refers to hard links, not symlinks. Hard links aren't recursive. 

   LINK_MAX has nothing to do with symlinks. That's the maximum number of 
   *hard* links an inode can have. 
*/
#ifndef LINK_MAX
# define LINK_MAX 127
#endif

//from linux/limits.h:#define MAX_CANON        255	/* size of the canonical input queue */
#ifndef MAX_CANON
# define MAX_CANON 255
#endif

//from linux/limits.h:#define MAX_INPUT        255	/* size of the type-ahead buffer */
#ifndef MAX_INPUT
# define MAX_INPUT 255
#endif

//NAME_MAX  255

#ifndef OPEN_MAX
# define OPEN_MAX 256
#endif

//from linux/limits.h:#define PATH_MAX        4096	/* # chars in a path name including nul */
#ifndef PATH_MAX
# define PATH_MAX 4096
#endif

//from linux/limits.h:#define PIPE_BUF        4096	/* # bytes in atomic write to a pipe */
#ifndef PIPE_BUF
# define PIPE_BUF 4096
#endif

//SSIZE_MAX  32767

//from POSIX, min acceptable value
#ifndef STREAM_MAX
# define STREAM_MAX _POSIX_STREAM_MAX
#endif

//from POSIX, min acceptable value
#ifndef TZNAME_MAX
# define TZNAME_MAX _POSIX_TZNAME_MAX
#endif

#ifndef SYMLINK_MAX
# define SYMLINK_MAX  _POSIX_SYMLINK_MAX
#endif

#ifndef AIO_LISTIO_MAX
# define AIO_LISTIO_MAX _POSIX_AIO_LISTIO_MAX
#endif

#ifndef AIO_MAX
# define AIO_MAX _POSIX_AIO_MAX
#endif

#ifndef AIO_PRIO_DELTA_MAX
# define AIO_PRIO_DELTA_MAX 0
#endif

#ifndef DELAYTIMER_MAX
# define DELAYTIMER_MAX  _POSIX_DELAYTIMER_MAX
#endif

#ifndef HOST_NAME_MAX
# define HOST_NAME_MAX  _POSIX_HOST_NAME_MAX
#endif

#ifndef MQ_OPEN_MAX
# define MQ_OPEN_MAX  _POSIX_MQ_OPEN_MAX
#endif

//local_lim.h:#define MQ_PRIO_MAX  32768
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
