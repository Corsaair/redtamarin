/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmplus_mac_platform2__
#define __avmplus_mac_platform2__

// ==== BEFORE ==== 
/* for special case that need to be defined first */

//we need to redefine FD_SETSIZE before the select.h include
#undef FD_SETSIZE
#define FD_SETSIZE 16384

// ==== HEADERS ==== 

//for C.stdlib
//#include <stdlib.h> //already included in mac-platform.h

//for fileno(), popen()
//#include <stdio.h> //already included in mac-platform.h

//for select(), FD_SET(), etc. used by SocketClass
#include <sys/select.h>

//for mode_t, needed with chmod
#include <sys/types.h>

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
#include <sys/filio.h>

//for uname(), in avmplus.OperatingSystem
#include <sys/utsname.h>

//for statvfs(), in avmplus.FileSystem
#include <sys/statvfs.h>



//for C.locale, setlocale, used with VMPI_getLocale
#include <locale.h>

#include <time.h>

// ==== ISO C / ANSI C ==== 

// ---- C.assert ---- 

// ---- C.assert ---- END


// ---- C.ctype ---- 
//#include <ctype.h> //already included in mac-platform.h
//#define VMPI_isalnum  ::isalnum //already defined in mac-platform.h
//#define VMPI_isalpha  ::isalpha //already defined in mac-platform.h
#define VMPI_isascii  ::isascii
#define VMPI_isblank  ::isblank
//#define VMPI_iscntrl  ::iscntrl //already defined in mac-platform.h
//#define VMPI_isdigit  ::isdigit //already defined in mac-platform.h
//#define VMPI_isgraph  ::isgraph //already defined in mac-platform.h
//#define VMPI_islower  ::islower //already defined in mac-platform.h
//#define VMPI_isprint  ::isprint //already defined in mac-platform.h
//#define VMPI_ispunct  ::ispunct //already defined in mac-platform.h
//#define VMPI_isspace  ::isspace //already defined in mac-platform.h
//#define VMPI_isupper  ::isupper //already defined in mac-platform.h
//#define VMPI_isxdigit ::isxdigit //already defined in mac-platform.h
#define VMPI_toascii  ::toascii
//#define VMPI_tolower  ::tolower //already defined in mac-platform.h
//#define VMPI_toupper  ::toupper //already defined in mac-platform.h
// ---- C.ctype ---- END


// ---- C.errno ---- 
//#include <errno.h> //already included in mac-platform.h
//extern void VMPI_set_errno(int value); // defined in VMPI2.h
//extern int VMPI_get_errno(); // defined in VMPI2.h

//posix compat
#ifndef ENOTBLK
# define ENOTBLK 15
#endif

#ifndef EDEADLOCK
# define EDEADLOCK EDEADLK
#endif

//Mac OS X define EMULTIHOP

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
//#include <limits.h> //already included in mac-platform.h

//POSIX compat
//from syslimits.h, eg. 256 * 1024 = 262144
#ifndef ARG_MAX
# define ARG_MAX (256 * 1024)
#endif

//from POSIX, min acceptable value
#ifndef ATEXIT_MAX
# define ATEXIT_MAX 32
#endif

//from syslimits.h
/* Note:
   CHILD_MAX *must* be less than hard_maxproc, which is set at
   compile time; you *cannot* set it higher than the hard limit!!
*/
#ifndef CHILD_MAX
# define CHILD_MAX 266
#endif

//from syslimits.h
#ifndef LINK_MAX
# define LINK_MAX 32767
#endif

//from syslimits.h
#ifndef MAX_CANON
# define MAX_CANON 1024
#endif

//from syslimits.h
#ifndef MAX_INPUT
# define MAX_INPUT 1024
#endif

//NAME_MAX  255

//from syslimits.h
#ifndef OPEN_MAX
# define OPEN_MAX 10240
#endif

//from syslimits.h
#ifndef PATH_MAX
# define PATH_MAX 1024
#endif

//from syslimits.h
#ifndef PIPE_BUF
# define PIPE_BUF 512
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
# define HOST_NAME_MAX  MAXHOSTNAMELEN
#endif

#ifndef LOGIN_NAME_MAX
# define LOGIN_NAME_MAX  MAXLOGNAME+1
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
//#include <signal.h> //already included in mac-platform.h
#define VMPI_signal    ::signal
// ---- C.signal ---- END


// ---- C.stdarg ---- 

// ---- C.stdarg ---- END


// ---- C.stddef ---- 

// ---- C.stddef ---- END


// ---- C.stdio ---- 
//#include <stdio.h> //already included in mac-platform.h
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
//#define VMPI_flockfile         ::flockfile
#define VMPI_fopen             ::fopen
#define VMPI_fputc             ::fputc
#define VMPI_fputs             ::fputs
#define VMPI_fread             ::fread
#define VMPI_freopen           ::freopen
#define VMPI_fseek             ::fseek
#define VMPI_fsetpos           ::fsetpos
#define VMPI_ftell             ::ftell
//#define VMPI_ftrylockfile      ::ftrylockfile
//#define VMPI_funlockfile       ::funlockfile
#define VMPI_fwrite            ::fwrite
#define VMPI_getc              ::getc
#define VMPI_getchar           ::getchar
//getc_unlocked //need to be defined in VMPI2.h as it is a macro
//getchar_unlocked //need to be defined in VMPI2.h as it is a macro
#define VMPI_pclose            ::pclose
#define VMPI_perror            ::perror
#define VMPI_perror16(...) ((void)0)
#define VMPI_popen             ::popen
#define VMPI_popen16(...) (NULL)
//putc_unlocked //need to be defined in VMPI2.h as it is a macro
//putchar_unlocked //need to be defined in VMPI2.h as it is a macro
#define VMPI_remove            ::remove
#define VMPI_remove16(...) (-1)
#define VMPI_rename            ::rename
#define VMPI_rename16(...) (-1)
#define VMPI_rewind            ::rewind
// ---- C.stdio ---- END


// ---- C.stdlib ---- 
//#include <stdlib.h> // included in mac-platform.h
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
//VMPI_ldiv
//llabs()
//VMPI_lldiv
//lrand48()
//VMPI_malloc //extern void* VMPI_alloc(size_t size); // defined in VMPI.h
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
//#include <string.h> // included in mac-platform.h
//memccpy()
//#define VMPI_memchr         ::memchr //already defined in mac-platform.h
//#define VMPI_memcmp         ::memcmp //already defined in mac-platform.h
//#define VMPI_memcpy         ::memcpy //already defined in mac-platform.h
//#define VMPI_memmove        ::memmove //already defined in mac-platform.h
//#define VMPI_memset         ::memset //already defined in mac-platform.h
//stpcpy()
//stpncpy()
//#define VMPI_strcat         ::strcat //already defined in mac-platform.h
#define VMPI_strcat16(...) (NULL)
//#define VMPI_strchr         ::strchr //already defined in mac-platform.h
#define VMPI_strchr16(...) (NULL)
//#define VMPI_strcmp         ::strcmp //already defined in mac-platform.h
#define VMPI_strcmp16(...) (-1)
#define VMPI_strcoll          ::strcoll
#define VMPI_strcoll16(...) (-1)
//strcoll_l()
//#define VMPI_strcpy         ::strcpy //already defined in mac-platform.h
//strcspn()
#define VMPI_strdup      ::strdup
#define VMPI_strdup16(...) (NULL)
#define VMPI_strerror    ::strerror
#define VMPI_strerror16(...) (NULL)
//strerror_l()
//strerror_r()
//#define VMPI_strlen         ::strlen //already defined in mac-platform.h
#define VMPI_strlen16(...) (0)
//#define VMPI_strncat        ::strncat //already defined in mac-platform.h
#define VMPI_strncat16(...) (NULL)
//#define VMPI_strncmp        ::strncmp //already defined in mac-platform.h
#define VMPI_strncmp16(...) (-1)
//#define VMPI_strncpy        ::strncpy //already defined in mac-platform.h
#define VMPI_strncpy16(...) (NULL)
//strndup()
//strnlen()
//strpbrk()
//#define VMPI_strrchr        ::strrchr //already defined in mac-platform.h
#define VMPI_strrchr16(...) (NULL)
//strsignal()
#define VMPI_strspn           ::strspn
#define VMPI_strspn16(...) (0)
//#define VMPI_strstr         ::strstr //already defined in mac-platform.h
#define VMPI_strstr16(...) (NULL)
//strtok()
//strtok_r()
//strxfrm()
//strxfrm_l()
// ---- C.string ---- END


// ---- C.time ---- 

// ---- C.time ---- END




// ==== POSIX ==== 

// ---- C.arpa.inet ---- 

// ---- C.arpa.inet ---- END

// ---- C.conio ---- 
//#define VMPI_canonical //already defined in VMPI2.h
//#define VMPI_echo      //already defined in VMPI2.h
//#define VMPI_getch     //already defined in VMPI2.h
//#define VMPI_getche    //already defined in VMPI2.h
//#define VMPI_kbhit     //already defined in VMPI2.h
// ---- C.conio ---- END


// ---- C.cpio ---- 

// ---- C.cpio ---- END


// ---- C.dirent ---- 
#include <dirent.h>
#define VMPI_closedir       ::closedir
#define VMPI_dirfd          ::dirfd
//VMPI_fdopendir
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
/* NOTE:
   see unix-platform2.h notes
*/
#ifndef NI_NUMERICSCOPE
# define NI_NUMERICSCOPE 256 /* Don't convert scope_id to name.  */
#endif

//#define VMPI_getprotobynumber  ::getprotobynumber
//#define VMPI_getprotoent       ::getprotoent
//#define VMPI_gethostent        ::gethostent
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


// ---- C.sys.select ---- 

// ---- C.sys.select ---- END


// ---- C.sys.socket ---- 

/* NOTE:
   OSX has no MSG_NOSIGNAL
   from 10.2+ you can use SO_NOSIGPIPE
   SO_NOSIGPIPE is a setsockopt() option
   and not a send() parameter as MSG_NOSIGNAL
   see: http://lists.apple.com/archives/macnetworkprog/2002/Dec/msg00091.html
*/
#ifndef MSG_NOSIGNAL
//#define MSG_NOSIGNAL SO_NOSIGPIPE
#define MSG_NOSIGNAL 0
#endif

// ---- C.sys.socket ---- END


// ---- C.sys.stat ---- 
#include <sys/stat.h>
//#define VMPI_chmod       ::chmod // defined in VMPI2.h
//#define VMPI_mkdir       ::mkdir // defined in VMPI2.h
#define VMPI_stat        ::stat
#define VMPI_stat16(...) (-1)
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

// ---- C.sys.wait ---- END


// ---- C.tar ---- 

// ---- C.tar ---- END


// ---- C.termios ---- 

// ---- C.termios ---- END


// ---- C.unistd ---- 
//#include <unistd.h> //already included in mac-platform.h
#define VMPI_access      ::access
#define VMPI_access16(...) (-1)
#define VMPI_chdir       ::chdir
#define VMPI_chdir16(...) (-1)
//#define VMPI_close       ::close
#define VMPI_dup         ::dup
#define VMPI_dup2        ::dup2
//#define VMPI_execl		 ::execl //not used
//#define VMPI_execle		 ::execle //not used
//#define VMPI_execlp		 ::execlp //not used
#define VMPI_execv		 ::execv
#define VMPI_execv16(...) (-1)
#define VMPI_execve      ::execve
#define VMPI_execve16(...) (-1)
#define VMPI_execvp      ::execvp
#define VMPI_execvp16(...) (-1)
#define VMPI_fsync       ::fsync
#define VMPI_ftruncate   ::ftruncate
#define VMPI_getcwd      ::getcwd
//#define VMPI_getcwd16(...) (-1)

//#define VMPI_gethostname ::gethostname
#define VMPI_getpid      ::getpid
#define VMPI_rmdir       ::rmdir
#define VMPI_rmdir16(...) (-1)
#define VMPI_unlink      ::unlink
#define VMPI_unlink16(...) (-1)
// ---- C.unistd ---- END


// ---- C.utime ---- 

// ---- C.utime ---- END



#endif // __avmplus_mac_platform2__
