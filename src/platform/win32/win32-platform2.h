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
#endif

typedef int pid_t;

typedef int uid_t;

typedef int mode_t;


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
#include <ws2tcpip.h>
#pragma comment(lib, "Ws2_32.lib")
#pragma comment(lib, "User32.lib")

//for setlocale, used with VMPI_getLocale
#include <locale.h>

//for _getpid
#include <process.h>

#include <time.h>

//for VMPI_SystemMemorySize, VMPI_SystemMemoryUse, VMPI_SystemMemoryPeak
#include <Psapi.h>
#pragma comment(lib, "psapi.lib") // Added to support GetProcessMemoryInfo()

// ==== ISO C / ANSI C ==== 

// ---- C.assert ---- 

// ---- C.assert ---- END


// ---- C.ctype ---- 

#ifndef isblank
# define isblank(x) ((x) == ' ' || (x) == '\t')
#endif

#define VMPI_isascii  isascii
#define VMPI_isblank  isblank
#define VMPI_toascii  toascii
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

//missing
#ifndef LONG_BIT
# define LONG_BIT 32
#endif

//missing
#ifndef WORD_BIT
# define WORD_BIT 32
#endif

/* NOTE:
   UNLEN 256 (eg. User Name Length)
   is defined in Lmcons.h
   used for LOGIN_NAME_MAX
*/
#ifndef UNLEN
# define UNLEN  256
#endif

//POSIX compat
#define _POSIX_ARG_MAX               4096
#define _POSIX_CHILD_MAX             6
#define _POSIX_LINK_MAX              8
#define _POSIX_MAX_CANON             255
#define _POSIX_MAX_INPUT             255
#define _POSIX_NAME_MAX              14
#define _POSIX_NGROUPS_MAX           0
#define _POSIX_OPEN_MAX              16
#define _POSIX_PATH_MAX              255
#define _POSIX_PIPE_BUF              512
#define _POSIX_SSIZE_MAX             32767
#define _POSIX_STREAM_MAX            8
#define _POSIX_TZNAME_MAX            3
#define _POSIX_SYMLINK_MAX           255
#define _POSIX_AIO_LISTIO_MAX        2
#define _POSIX_AIO_MAX               1
#define _POSIX_DELAYTIMER_MAX        32
#define _POSIX_HOST_NAME_MAX         255
#define _POSIX_LOGIN_NAME_MAX        9
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

/* NOTE:
   we can not use _POSIX_
   so we do it here 
*/
#define ARG_MAX             14500       /* 16k heap, minus overhead */
#define LINK_MAX            1024
#define MAX_CANON           _POSIX_MAX_CANON
#define MAX_INPUT           _POSIX_MAX_INPUT
#define NAME_MAX            255
#define NGROUPS_MAX         16
#define OPEN_MAX            32
#define PATH_MAX            512
#define PIPE_BUF            _POSIX_PIPE_BUF
#define SSIZE_MAX           _POSIX_SSIZE_MAX
#define STREAM_MAX          20
#define TZNAME_MAX          10

//from POSIX, min acceptable value
/* from http://msdn.microsoft.com/en-us/library/tze57ck3.aspx
   atexit and _onexit use the heap to hold the register of functions.
   Thus, the number of functions that can be registered is limited only by heap memory.

   so again 16k heap minus overhead could be 14500
   but because we define 32 already for mac and linux
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
#include <signal.h>

union sigval
{
  int sival_int;
  void *sival_ptr;
};

struct siginfo_t
{
  int si_signo;
  int si_code;
  int si_errno;
  pid_t si_pid;
  uid_t si_uid;
  void *si_addr;
  int si_status;
  long si_band;
  union sigval si_value;
};

typedef struct siginfo_t siginfo_t;

#ifndef SIGEV_SIGNAL
# define SIGEV_SIGNAL  0
#endif

#ifndef SIGEV_NONE
# define SIGEV_NONE  1
#endif

#ifndef SIGEV_THREAD
# define SIGEV_THREAD  2
#endif

// ---- C.signal ---- END


// ---- C.stdarg ---- 

// ---- C.stdarg ---- END


// ---- C.stddef ---- 

// ---- C.stddef ---- END


// ---- C.stdio ---- 
#include <stdio.h>
#define VMPI_clearerr          ::clearerr
#define VMPI_fclose            ::fclose
#define VMPI_fdopen            ::_fdopen
#define VMPI_feof              ::feof
#define VMPI_ferror            ::ferror
#define VMPI_fflush            ::fflush
#define VMPI_fgetc             ::fgetc
#define VMPI_fgetpos           ::fgetpos
#define VMPI_fgets             ::fgets
#define VMPI_fileno            ::_fileno
//flockfile() //defined in VMPI2.h
#define VMPI_fopen             ::fopen
#define VMPI_fputc             ::fputc
#define VMPI_fputs             ::fputs
#define VMPI_fread             ::fread
#define VMPI_freopen           ::freopen
#define VMPI_fseek             ::fseek
#define VMPI_fsetpos           ::fsetpos
#define VMPI_ftell             ::ftell
//ftrylockfile() //defined in VMPI2.h
//funlockfile() //defined in VMPI2.h
#define VMPI_fwrite            ::fwrite
#define VMPI_getc              ::getc
#define VMPI_getchar           ::getchar
//getc_unlocked //need to be defined in VMPI2.h as it is a macro
//getchar_unlocked //need to be defined in VMPI2.h as it is a macro
#define VMPI_pclose            ::_pclose
#define VMPI_perror            ::perror
#define VMPI_perror16          ::_wperror
#define VMPI_popen             ::_popen
#define VMPI_popen16           ::_wpopen
//putc_unlocked //need to be defined in VMPI2.h as it is a macro
//putchar_unlocked //need to be defined in VMPI2.h as it is a macro
#define VMPI_remove            ::remove
#define VMPI_remove16          ::_wremove
#define VMPI_rename            ::rename
#define VMPI_rename16          ::_wrename
#define VMPI_rewind            ::rewind
// ---- C.stdio ---- END


// ---- C.stdlib ---- 
//_Exit()
//a641()
//VMPI_abort
//abs()
//atexit()
#define VMPI_atof    ::atof
//VMPI_atoi
#define VMPI_atol    ::atol
//atoll()
//bsearch()
//calloc()
#define VMPI_div     ::div
//drand48()
//erand48()
//VMPI_exit
//VMPI_free
//VMPI_getenv
//getsubopt()
//grantpt()
//initstate()
//jrand48()
//l64a()
//labs()
//lcong48()
//VMPI_ldiv
//llabs()
//VMPI_lldiv
//lrand48()
//VMPI_malloc
#define VMPI_mblen    ::mblen
//mbstowcs()
//mbtowc()
//VMPI_mkdtemp
//VMPI_mkstemp
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
//VMPI_realpath
//seed48()
//VMPI_setenv
//setkey()
//setstate()
#define VMPI_srand    ::srand
//srand48()
//srandom()
//strtod()
//strtof()
//VMPI_strtol
//strtold()
//strtoll()
//strtoul()
//strtoull()
//system()
//unlockpt()
//VMPI_unsetenv
//wcstombs()
//wctomb()
// ---- C.stdlib ---- END


// ---- C.string ---- 
//memccpy()
//VMPI_memchr
//VMPI_memcmp
//VMPI_memcpy
//VMPI_memmove
//VMPI_memset
//stpcpy()
//stpncpy()
//VMPI_strcat
#define VMPI_strcat16    ::wcscat
//VMPI_strchr
#define VMPI_strchr16    ::wcschr 
//VMPI_strcmp
#define VMPI_strcmp16    ::wcscmp
#define VMPI_strcoll     ::strcoll
#define VMPI_strcoll16   ::wcscoll
//strcoll_l()
//VMPI_strcpy
#define VMPI_strcpy16    ::wcscpy
//strcspn()
#define VMPI_strdup      ::_strdup
#define VMPI_strdup16    ::_wcsdup
#define VMPI_strerror    ::strerror
#define VMPI_strerror16  ::_wcserror
//strerror_l()
//strerror_r()
//VMPI_strlen
#define VMPI_strlen16    ::wcslen
//VMPI_strncat
#define VMPI_strncat16   ::wcsncat
//VMPI_strncmp
#define VMPI_strncmp16   ::wcsncmp
//VMPI_strncpy
#define VMPI_strncpy16   ::wcsncpy
//strndup()
//strnlen()
//strpbrk()
//VMPI_strrchr
#define VMPI_strrchr16   ::wcsrchr
//strsignal()
#define VMPI_strspn      ::strspn
#define VMPI_strspn16    ::wcsspn
//VMPI_strstr
#define VMPI_strstr16    ::wcsstr
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
struct dirstream
{
    int fd;            /* File descriptor.  */
    char *data;        /* Directory block.  */
    size_t allocation; /* Space allocated for the block.  */
    size_t size;       /* Total valid data in the block.  */
    size_t offset;     /* Current offset into the block.  */
    off_t filepos;     /* Position of next entry to read.  */
    char *mask;           /* Initial file mask. */
};

struct dirent
{
    long d_ino;
    off_t d_off;
    unsigned short int d_reclen;
    unsigned char d_type;
    char d_name[256];
};

typedef struct dirstream DIR;

DIR * opendir (const char * name);
struct dirent * readdir (DIR * dir);
int closedir (DIR * dir);
void rewinddir (DIR * dir);
void seekdir (DIR * dir, off_t offset);
off_t telldir (DIR * dir);
int dirfd (DIR * dir);

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

#ifndef O_DSYNC
# define O_DSYNC 0x0000
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

#ifndef O_WTEXT
# define O_WTEXT _O_WTEXT
#endif

#ifndef O_U16TEXT
# define O_U16TEXT _O_U16TEXT
#endif

#ifndef O_U8TEXT
# define O_U8TEXT _O_U8TEXT
#endif

#ifndef O_SHORT_LIVED
# define O_SHORT_LIVED _O_SHORT_LIVED
#endif

#ifndef F_DUPFD
# define F_DUPFD 0
#endif
     
#ifndef F_GETFD
# define F_GETFD 1
#endif

#ifndef F_SETFD
# define F_SETFD 2
#endif

#ifndef F_GETFL
# define F_GETFL 3
#endif

#ifndef F_SETFL
# define F_SETFL 4
#endif

#ifndef F_GETOWN
# define F_GETOWN 5
#endif

#ifndef F_SETOWN
# define F_SETOWN 6
#endif

#ifndef F_GETLK
# define F_GETLK 7
#endif

#ifndef F_SETLK
# define F_SETLK 8
#endif

//F_SETLKW 9

#ifndef F_DUPFD_CLOEXEC
# define F_DUPFD_CLOEXEC 14
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
struct protoent *getprotoent();
struct hostent *gethostent();
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
#undef stat
#define stat  __stat64
#define VMPI_umask   ::_umask
#define VMPI_fstat   ::_fstat64
#define VMPI_stat    ::_stat64
#define VMPI_stat16  ::_wstat64
// ---- C.sys.stat ---- END


// ---- C.sys.time ---- 

// ---- C.sys.time ---- END


// ---- C.sys.types ---- 


// ---- C.sys.types ---- END


// ---- C.sys.utsname ---- 

// ---- C.sys.utsname ---- END


// ---- C.sys.wait ---- 
#define WEXITSTATUS(w)  ( (int) ((w) & 0x40000000) )
#define WIFEXITED(w)    ( ((w) & 0x40000000) == 0 )
#define WIFSIGNALED(w)  ( ((w) & 0x40000000) != 0 )
//#define WTERMSIG(w)     (w)
#define WTERMSIG(w)     ( ((w) & 0x3FFFFFFF) )


#ifndef WCONTINUED
# define WCONTINUED 0x0000
#endif

#ifndef WNOHANG
# define WNOHANG 0x0000
#endif

#ifndef WUNTRACED
# define WUNTRACED 0x0000
#endif


#ifndef WEXITED
# define WEXITED 0x0000
#endif

#ifndef WNOWAIT
# define WNOWAIT 0x0000
#endif

#ifndef WSTOPPED
# define WSTOPPED 0x0000
#endif


#ifndef P_ALL
# define P_ALL 0x0000
#endif

#ifndef P_PGID
# define P_PGID 0x0000
#endif

#ifndef P_PID
# define P_PID 0x0000
#endif

// ---- C.sys.wait ---- END


// ---- C.tar ---- 

// ---- C.tar ---- END


// ---- C.termios ---- 

// ---- C.termios ---- END


// ---- C.unistd ---- 
#ifndef F_OK
# define F_OK 0
#endif

#ifndef X_OK
# define X_OK 1
#endif

#ifndef W_OK
# define W_OK 2
#endif

#ifndef R_OK
# define R_OK 4
#endif

int ftruncate(int fildes, off_t length);

#define VMPI_access      ::_access
#define VMPI_access16    ::_waccess
#define VMPI_chdir       ::_chdir
#define VMPI_chdir16     ::_wchdir
#define VMPI_close       ::_close
#define VMPI_dup         ::_dup
#define VMPI_dup2        ::_dup2
//#define VMPI_execl     ::execl //not used
//#define VMPI_execle    ::execle //not used
//#define VMPI_execlp    ::execlp //not used
#define VMPI_execv       ::_execv
#define VMPI_execv16     ::_wexecv
#define VMPI_execve      ::_execve
#define VMPI_execve16    ::_wexecve
#define VMPI_execvp      ::_execvp
#define VMPI_execvp16    ::_wexecvp
#define VMPI_fsync       ::_commit
#define VMPI_ftruncate   ::ftruncate
#define VMPI_getcwd      ::_getcwd
//#define VMPI_getcwd16    ::_wgetcwd

#define VMPI_getpid      ::_getpid
#define VMPI_rmdir       ::_rmdir
#define VMPI_rmdir16     ::_wrmdir
#define VMPI_unlink      ::_unlink
#define VMPI_unlink16    ::_wunlink
// ---- C.unistd ---- END


// ---- C.utime ---- 

// ---- C.utime ---- END


#endif // __avmplus_win32_platform2__
