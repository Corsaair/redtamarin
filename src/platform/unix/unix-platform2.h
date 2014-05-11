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

#define VMPI_isascii(c)  isascii(c)
#define VMPI_isblank  ::isblank
#define VMPI_toascii(c)  toascii(c)

/*
int VMPI_isascii(int value)
{
    return isascii( value );
}

int VMPI_isblank(int value)
{
    return isblank( value );
}

int VMPI_toascii(int value)
{
    return toascii( value );
}*/

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

# if __WORDSIZE == 64
#  define SIZE_MAX    (18446744073709551615UL)
# else
#  define SIZE_MAX    (4294967295U)
# endif

//POSIX compat
#ifndef _POSIX_SYMLINK_MAX
#define _POSIX_SYMLINK_MAX           255
#endif

#ifndef _POSIX_AIO_LISTIO_MAX
#define _POSIX_AIO_LISTIO_MAX        2
#endif

#ifndef _POSIX_AIO_MAX
#define _POSIX_AIO_MAX               1
#endif

#ifndef _POSIX_DELAYTIMER_MAX
#define _POSIX_DELAYTIMER_MAX        32
#endif

#ifndef _POSIX_HOST_NAME_MAX
#define _POSIX_HOST_NAME_MAX         255
#endif

#ifndef _POSIX_MQ_OPEN_MAX
#define _POSIX_MQ_OPEN_MAX           8
#endif

#ifndef _POSIX_MQ_PRIO_MAX
#define _POSIX_MQ_PRIO_MAX           32
#endif

#ifndef _POSIX_RE_DUP_MAX
#define _POSIX_RE_DUP_MAX            255
#endif

#ifndef _POSIX_RTSIG_MAX
#define _POSIX_RTSIG_MAX             8
#endif

#ifndef _POSIX_SEM_NSEMS_MAX
#define _POSIX_SEM_NSEMS_MAX         256
#endif

#ifndef _POSIX_SEM_VALUE_MAX
#define _POSIX_SEM_VALUE_MAX         32767
#endif

#ifndef _POSIX_SIGQUEUE_MAX
#define _POSIX_SIGQUEUE_MAX          32
#endif

#ifndef _POSIX_SS_REPL_MAX
#define _POSIX_SS_REPL_MAX           4
#endif

#ifndef _POSIX_SYMLOOP_MAX
#define _POSIX_SYMLOOP_MAX           8
#endif

#ifndef _POSIX_TIMER_MAX
#define _POSIX_TIMER_MAX             32
#endif

#ifndef _POSIX_TRACE_EVENT_NAME_MAX
#define _POSIX_TRACE_EVENT_NAME_MAX  30
#endif

#ifndef _POSIX_TRACE_NAME_MAX
#define _POSIX_TRACE_NAME_MAX        8
#endif

#ifndef _POSIX_TRACE_SYS_MAX
#define _POSIX_TRACE_SYS_MAX         8
#endif

#ifndef _POSIX_TRACE_USER_EVENT_MAX
#define _POSIX_TRACE_USER_EVENT_MAX  32
#endif

#ifndef _POSIX_TTY_NAME_MAX
#define _POSIX_TTY_NAME_MAX          9
#endif



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
#define VMPI_clearerr          ::clearerr
#define VMPI_fclose            ::fclose
#define VMPI_fdopen            ::fdopen
#define VMPI_feof              ::feof
#define VMPI_ferror            ::ferror
#define VMPI_fflush            ::fflush
#define VMPI_fgetc             ::fgetc
#define VMPI_fgetpos           ::fgetpos
#define VMPI_fgets             ::fgets
#define VMPI_fileno            ::fileno
#define VMPI_flockfile         ::flockfile
#define VMPI_fopen             ::fopen
#define VMPI_fputc             ::fputc
#define VMPI_fputs             ::fputs
#define VMPI_fread             ::fread
#define VMPI_freopen           ::freopen
#define VMPI_fseek             ::fseek
#define VMPI_fsetpos           ::fsetpos
#define VMPI_ftell             ::ftell
#define VMPI_ftrylockfile      ::ftrylockfile
#define VMPI_funlockfile       ::funlockfile
#define VMPI_fwrite            ::fwrite
#define VMPI_getc              ::getc
#define VMPI_getchar           ::getchar
//getc_unlocked //need to be defined in VMPI2.h as it is a macro
//getchar_unlocked //need to be defined in VMPI2.h as it is a macro
#define VMPI_pclose            ::pclose
#define VMPI_perror            ::perror
#define VMPI_popen             ::popen
//putc_unlocked //need to be defined in VMPI2.h as it is a macro
//putchar_unlocked //need to be defined in VMPI2.h as it is a macro
#define VMPI_remove            ::remove
#define VMPI_rename            ::rename
#define VMPI_rewind            ::rewind
// ---- C.stdio ---- END


// ---- C.stdlib ---- 
//_Exit()
//a641()
//#define VMPI_abort   ::abort // defined in mac-platform.h
//abs()
//atexit()
#define VMPI_atof    ::atof
//#define VMPI_atoi    ::atoi // defined in mac-platform.h
#define VMPI_atol    ::atol
//atoll()
//bsearch()
//calloc()
#define VMPI_div     ::div
//drand48()
//erand48()
//#define VMPI_exit    ::exit // defined in mac-platform.h
//extern void VMPI_free(void* ptr); // defined in VMPI.h
//extern const char *VMPI_getenv(const char *name); // defined in VMPI.h
//getsubopt()
//grantpt()
//initstate()
//jrand48()
//l64a()
//labs()
//lcong48()
#define VMPI_ldiv     ::ldiv
//llabs()
#define VMPI_lldiv    ::lldiv
//lrand48()
//VMPI_malloc //extern void* VMPI_alloc(size_t size); // defined in VMPI.h
#define VMPI_mblen    ::mblen
//mbstowcs()
//mbtowc()
#define VMPI_mkdtemp  ::mkdtemp
#define VMPI_mkstemp  ::mkstemp
//mrand48()
//nrand48()
//posix_memalign()
//posix_openpt()
//ptsname()
//putenv()
//qsort()
#define VMPI_rand     ::rand
//rand_r()
//random()
//realloc()
//extern char *VMPI_realpath(char const *path); // defined in VMPI2.h
//seed48()
//extern int VMPI_setenv(const char *name, const char *value, int overwrite); // defined in VMPI2.h
//setkey()
//setstate()
#define VMPI_srand    ::srand
//srand48()
//srandom()
//strtod()
//strtof()
//#define VMPI_strtol         ::strtol //already defined in mac-platform.h
//strtold()
//strtoll()
//strtoul()
//strtoull()
//system()
//unlockpt()
//extern int VMPI_unsetenv(const char *name); // defined in VMPI2.h
//wcstombs()
//wctomb()
// ---- C.stdlib ---- END


// ---- C.string ---- 
//memccpy()
//#define VMPI_memchr         ::memchr //already defined in mac-platform.h
//#define VMPI_memcmp         ::memcmp //already defined in mac-platform.h
//#define VMPI_memcpy         ::memcpy //already defined in mac-platform.h
//#define VMPI_memmove        ::memmove //already defined in mac-platform.h
//#define VMPI_memset         ::memset //already defined in mac-platform.h
//stpcpy()
//stpncpy()
//#define VMPI_strcat         ::strcat //already defined in mac-platform.h
//#define VMPI_strchr         ::strchr //already defined in mac-platform.h
//#define VMPI_strcmp         ::strcmp //already defined in mac-platform.h
#define VMPI_strcoll     ::strcoll
//strcoll_l()
//#define VMPI_strcpy         ::strcpy //already defined in mac-platform.h
//strcspn()
#define VMPI_strdup      ::strdup
#define VMPI_strerror    ::strerror
//strerror_l()
//strerror_r()
//#define VMPI_strlen         ::strlen //already defined in mac-platform.h
//#define VMPI_strncat        ::strncat //already defined in mac-platform.h
//#define VMPI_strncmp        ::strncmp //already defined in mac-platform.h
//#define VMPI_strncpy        ::strncpy //already defined in mac-platform.h
//strndup()
//strnlen()
//strpbrk()
//#define VMPI_strrchr        ::strrchr //already defined in mac-platform.h
//strsignal()
#define VMPI_strspn      ::strspn
//#define VMPI_strstr         ::strstr //already defined in mac-platform.h
//strtok()
//strtok_r()
//strxfrm()
//strxfrm_l()
// ---- C.string ---- END


// ---- C.time ---- 

// ---- C.time ---- END




// ==== POSIX ==== 

// ---- C.conio ---- 

// ---- C.conio ---- END


// ---- C.cpio ---- 

// ---- C.cpio ---- END


// ---- C.dirent ---- 
#include <dirent.h>
#define VMPI_closedir       ::closedir
#define VMPI_dirfd          ::dirfd
//extern DIR *VMPI_fdopendir(int fd); //already defined in VMPI2.h
#define VMPI_opendir        ::opendir
#define VMPI_readdir        ::readdir
#define VMPI_rewinddir      ::rewinddir
#define VMPI_seekdir        ::seekdir
#define VMPI_telldir        ::telldir
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

//posix compat
#ifndef O_EXEC
# define O_EXEC O_RDONLY
#endif

#ifndef O_SEARCH
# define O_SEARCH O_RDONLY
#endif

#ifndef O_TTY_INIT
# define O_TTY_INIT 0x0000
#endif

#ifndef O_RSYNC
# define O_RSYNC O_SYNC
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
#define VMPI_getprotobynumber  ::getprotobynumber
#define VMPI_getprotoent       ::getprotoent
#define VMPI_gethostent        ::gethostent
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
#include <sys/stat.h>
//#define VMPI_chmod       ::chmod // defined in VMPI2.h
//#define VMPI_mkdir       ::mkdir // defined in VMPI2.h
#define VMPI_stat        ::stat
#define VMPI_fstat       ::fstat
#define VMPI_umask       ::umask
// ---- C.sys.stat ---- END


// ---- C.sys.time ---- 

// ---- C.sys.time ---- END


// ---- C.sys.types ---- 

// ---- C.sys.types ---- END


// ---- C.sys.utsname ---- 

// ---- C.sys.utsname ---- END


// ---- C.sys.wait ---- 
#include <sys/wait.h>
// ---- C.sys.wait ---- END


// ---- C.tar ---- 

// ---- C.tar ---- END


// ---- C.termios ---- 

// ---- C.termios ---- END


// ---- C.unistd ---- 
#define VMPI_access      ::access
#define VMPI_chdir       ::chdir
#define VMPI_close       ::close
#define VMPI_dup         ::dup
#define VMPI_dup2        ::dup2
//#define VMPI_execl     ::execl //not used
//#define VMPI_execle    ::execle //not used
//#define VMPI_execlp    ::execlp //not used
#define VMPI_execv     ::execv
#define VMPI_execve      ::execve
#define VMPI_execvp      ::execvp
#define VMPI_fsync       ::fsync
#define VMPI_ftruncate   ::ftruncate
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


#define VMPI_inet_ntop   ::inet_ntop


#endif // __avmplus_unix_platform2__
