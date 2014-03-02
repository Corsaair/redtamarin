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
// ---- C.errno ---- END


// ---- C.float ---- 

// ---- C.float ---- END


// ---- C.limits ---- 
//#include <limits.h> //already included in mac-platform.h
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

#if !defined(O_TEXT)
  #define O_TEXT          0x0000
#endif /* !O_TEXT */

#if !defined(O_BINARY)
  #define O_BINARY        0x0000
#endif /* !O_BINARY */
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

// ---- C.sys.wait ---- END


// ---- C.tar ---- 

// ---- C.tar ---- END


// ---- C.termios ---- 

// ---- C.termios ---- END


// ---- C.unistd ---- 
//#include <unistd.h> //already included in mac-platform.h
#define VMPI_access      ::access
#define VMPI_chdir       ::chdir
#define VMPI_close       ::close
#define VMPI_dup         ::dup
#define VMPI_dup2        ::dup2
//#define VMPI_execl		 ::execl //not used
//#define VMPI_execle		 ::execle //not used
//#define VMPI_execlp		 ::execlp //not used
#define VMPI_execv		 ::execv
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

//avmplus.Socket
#define VMPI_inet_ntop   ::inet_ntop


#endif // __avmplus_mac_platform2__
