/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmplus_VMPI2__
#define __avmplus_VMPI2__

// Belt and suspenders...

#ifdef DEBUG
    #ifndef _DEBUG
        #define _DEBUG
    #endif
#endif

#ifdef _DEBUG
    #ifndef DEBUG
        #define DEBUG
    #endif
#endif

#ifdef NDEBUG
#undef _DEBUG
#undef DEBUG
#endif //#ifdef NDEBUG

/////////
// TODO: Remove dependency of VMPI on the feature system
#ifdef AVMSHELL_BUILD
#include "../shell/avmshell-features.h"
#else
/* The embedding host must provide this file in some directory that's included in
 * header search paths.  It must define a value (0 or 1) for every feature
 * required by avmplus, see shell/avmshell-features.h for a model, also see
 * core/avmfeatures.as for documentation of the feature system.
 */
#include "avmhost-features.h"
#endif

// Include the feature system here so that the platform files can depend on
// the internal (VMCFG_, etc) names rather than feature names.  Eases
// maintainability.

#include "../core/avmfeatures.h"
// END TODO: remove dependency of VMPI on the feature system
/////////

// TODO Move this file to VMPI:
#include "system-selection.h"

// TODO Move these files to VMPI:
#if AVMSYSTEM_WIN32

  #ifndef _WINSOCKAPI_
  #define _WINSOCKAPI_
  #endif

  #include "win32/win32-platform2.h"
#elif AVMSYSTEM_UNIX
  #include "unix/unix-platform2.h"
#elif AVMSYSTEM_MAC
  #include "mac/mac-platform2.h"
#elif AVMSYSTEM_SYMBIAN
  #include "symbian/symbian-platform.h"
#endif

/* wchar is our version of wchar_t, since wchar_t is different sizes
 on different platforms, but we want to use UTF-16 uniformly. */
typedef uint16_t wchar;

// Catchall, though in general the platform files are really responsible for giving
// REALLY_INLINE and FASTCALL a definition.

#ifndef REALLY_INLINE
    #define REALLY_INLINE inline
#endif
#ifndef FASTCALL
    #define FASTCALL
#endif

// Bug 569361.  NO_INLINE is hint that annotated function should be kept
// out-of-line.  Caveats: the NO_INLINE annotations guarantee nothing,
// as is evident from catch-all definition below (also, some compilers
// may require it to be applied to declaration sites to be effective).
#ifndef NO_INLINE
    #define NO_INLINE
#endif

#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

// ==== BEFORE ==== 
/* for special case that need to be defined first */


// ==== HEADERS ==== 


// ==== ISO C / ANSI C ==== 

// ---- C.assert ---- 

// ---- C.assert ---- END


// ---- C.ctype ---- 

// ---- C.ctype ---- END


// ---- C.errno ---- 
extern void VMPI_set_errno(int value);
extern int VMPI_get_errno();
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
extern int VMPI_kill(int pid, int sig);
// ---- C.signal ---- END


// ---- C.stdarg ---- 

// ---- C.stdarg ---- END


// ---- C.stddef ---- 

// ---- C.stddef ---- END


// ---- C.stdio ---- 
extern void VMPI_flockfile(FILE *stream);
extern int VMPI_ftrylockfile(FILE *stream);
extern void VMPI_funlockfile(FILE *stream);
extern int VMPI_getc_unlocked(FILE *stream);
extern int VMPI_getchar_unlocked();
extern int VMPI_putc_unlocked(int c, FILE *stream);
extern int VMPI_putchar_unlocked(int c);
// ---- C.stdio ---- END


// ---- C.stdlib ---- 
//VMPI_free
//VMPI_getenv
extern const wchar *VMPI_getenv16(const wchar *name);
extern ldiv_t VMPI_ldiv(double numer, double denom);
extern lldiv_t VMPI_lldiv(double numer, double denom);
//VMPI_malloc
extern char *VMPI_mkdtemp(char *templ);
extern int VMPI_mkstemp(char *templ);
extern int VMPI_putenv(char *name);
extern int VMPI_putenv16(wchar *name);
extern char *VMPI_realpath(char const *path);
extern wchar *VMPI_realpath16(wchar const *path);
extern int VMPI_setenv(const char *name, const char *value, int overwrite);
extern int VMPI_setenv16(const wchar *name, const wchar *value, int overwrite);
extern int VMPI_system(const char *command);
extern int VMPI_system16(const wchar *command);
extern int VMPI_unsetenv(const char *name);
extern int VMPI_unsetenv16(const wchar *name);
// ---- C.stdlib ---- END


// ---- C.string ---- 

// ---- C.string ---- END


// ---- C.time ---- 

// ---- C.time ---- END




// ==== POSIX ==== 

// ---- C.arpa.inet ---- 
extern uint32_t VMPI_htonl(uint32_t hostlong);
extern uint32_t VMPI_htons(uint32_t hostshort );
extern uint32_t VMPI_ntohl(uint32_t netlong );
extern uint32_t VMPI_ntohs(uint32_t netshort );

extern uint32_t VMPI_inet_addr(const char *cp);
extern uint32_t VMPI_inet_network(const char *cp);
extern char *VMPI_inet_ntoa(struct in_addr inaddr);
extern int VMPI_inet_aton(const char *cp, struct in_addr *inp);
extern const char *VMPI_inet_ntop(int af, const void *src, char *dst, socklen_t size);
extern int VMPI_inet_pton(int af, const char *src, void *dst);
// ---- C.arpa.inet ---- END

// ---- C.conio ---- 
extern void VMPI_canonical(bool status);
extern void VMPI_echo(bool status);
//extern int VMPI_getch();
//extern int VMPI_getche();
extern int VMPI_kbhit();
// ---- C.conio ---- END


// ---- C.cpio ---- 

// ---- C.cpio ---- END


// ---- C.dirent ---- 
extern DIR *VMPI_fdopendir(int fd);
// ---- C.dirent ---- END


// ---- C.fcntl ---- 
extern int VMPI_fcntl(int fildes, int cmd, int arg);
extern int VMPI_openat(int fd, const char *path, int oflag, int mode);
// ---- C.fcntl ---- END


// ---- C.grp ---- 

// ---- C.grp ---- END


// ---- C.netdb ---- 
extern const char *VMPI_gai_strerror(int ecode);
extern struct hostent *VMPI_gethostbyname(const char *name);
extern struct hostent *VMPI_gethostbyaddr(const char *addr, int len, int type);
extern struct protoent *VMPI_getprotobynumber(int proto);
extern struct protoent *VMPI_getprotoent();
extern struct hostent *VMPI_gethostent();
extern int VMPI_getaddrinfo(const char *nodename, const char *servname, const struct addrinfo *hints, struct addrinfo **res);
extern void VMPI_freeaddrinfo(struct addrinfo *ai);
// ---- C.netdb ---- END


// ---- C.pthread ---- 

// ---- C.pthread ---- END


// ---- C.pwd ---- 

// ---- C.pwd ---- END


// ---- C.spawn ---- 
extern int VMPI_spawn(int *pid, const char *path, char *const argv[], char *const envp[]);
extern int VMPI_spawnp(int *pid, const char *file, char *const argv[], char *const envp[]);
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
extern void VMPI_FD_CLR(int fd, fd_set *fdset);
extern int VMPI_FD_ISSET(int fd, fd_set *fdset);
extern void VMPI_FD_SET(int fd, fd_set *fdset);
extern void VMPI_FD_ZERO(fd_set *fdset);
extern int VMPI_select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *errorfds, struct timeval *timeout);
// ---- C.sys.select ---- END


// ---- C.sys.socket ---- 
extern int VMPI_accept(int socket, struct sockaddr *address, socklen_t *address_len);
extern int VMPI_bind(int socket, const struct sockaddr *address, socklen_t address_len);
extern int VMPI_connect(int socket, const struct sockaddr *address, socklen_t address_len);
extern int VMPI_getpeername(int socket, struct sockaddr *address, socklen_t *address_len);
extern int VMPI_getsockname(int socket, struct sockaddr *address, socklen_t *address_len);
extern int VMPI_getsockopt(int socket, int level, int option_name, void *option_value, socklen_t *option_len);
extern int VMPI_setsockopt(int socket, int level, int option_name, const void *option_value, socklen_t option_len);
extern int VMPI_listen(int socket, int backlog);
extern int VMPI_recv(int socket, void *buffer, size_t length, int flags);
extern int VMPI_recvfrom(int socket, void *buffer, size_t length, int flags, struct sockaddr *address, socklen_t *address_len);
extern int VMPI_send(int socket, const void *buffer, size_t length, int flags);
extern int VMPI_sendto(int socket, const void *message, size_t length, int flags, const struct sockaddr *dest_addr, socklen_t dest_len);
extern int VMPI_shutdown(int socket, int how);
extern int VMPI_sockatmark(int s);
extern int VMPI_socket(int domain, int type, int protocol);
extern int VMPI_socketpair(int domain, int type, int protocol, int socket_vector[2]);
// ---- C.sys.socket ---- END


// ---- C.sys.stat ---- 
extern int VMPI_chmod(const char *path, int mode);
extern int VMPI_chmod16(const wchar *path, int mode);
//extern int VMPI_fstat(int fildes, struct stat *buf);
extern int VMPI_mkdir(const char *path, int mode);
extern int VMPI_mkdir16(const wchar *path, int mode);
//extern int VMPI_stat(const char *path, struct stat *buf);
// ---- C.sys.stat ---- END


// ---- C.sys.time ---- 

// ---- C.sys.time ---- END


// ---- C.sys.types ---- 

// ---- C.sys.types ---- END


// ---- C.sys.utsname ---- 

// ---- C.sys.utsname ---- END


// ---- C.sys.wait ---- 
extern int VMPI_WEXITSTATUS(int status);
extern int VMPI_WIFCONTINUED(int status);
extern int VMPI_WIFEXITED(int status);
extern int VMPI_WIFSIGNALED(int status);
extern int VMPI_WIFSTOPPED(int status);
extern int VMPI_WSTOPSIG(int status);
extern int VMPI_WTERMSIG(int status);
extern int VMPI_wait(int *stat_loc);
extern int VMPI_waitid(int idtype, int id, siginfo_t *infop, int options);
extern int VMPI_waitpid(int pid, int *stat_loc, int options);
// ---- C.sys.wait ---- END


// ---- C.tar ---- 

// ---- C.tar ---- END


// ---- C.termios ---- 

// ---- C.termios ---- END


// ---- C.unistd ---- 
extern int VMPI_close(int fildes);
extern char **VMPI_GetEnviron();
extern wchar **VMPI_GetEnviron16();
extern wchar *VMPI_getcwd16(wchar *buf, size_t size);
extern int VMPI_gethostname(char *name, int namelen);
extern void VMPI_sleep(int milliseconds);
// ---- C.unistd ---- END


// ---- C.utime ---- 

// ---- C.utime ---- END




// ==== RNL ==== 

// ---- shell.Program ---- 
extern void VMPI_exitCleanup();
// ---- shell.Program ---- END

// ---- shell.HardwareInformation ---- 
// extern int VMPI_processorQtyAtBoot(); // defined in VMPI.h
extern double VMPI_SystemMemorySize();
extern double VMPI_SystemMemoryUse();
extern double VMPI_SystemMemoryPeak();
// ---- shell.HardwareInformation ---- END

// ---- shell.OperatingSystem ---- 
extern void VMPI_getUserName(char *username);
extern void VMPI_getUserName16(wchar *username);
//extern void VMPI_OperatingSystemName(char *name);
// ---- shell.OperatingSystem ---- END

// ---- shell.FileSystem ---- 
extern bool VMPI_isAttributeHidden(const char *path);
extern bool VMPI_isAttributeHidden16(const wchar *path);
extern int VMPI_getLogicalDrives();
extern double VMPI_getFreeDiskSpace(const char *path);
extern double VMPI_getFreeDiskSpace16(const wchar *path);
extern double VMPI_getTotalDiskSpace(const char *path);
extern double VMPI_getTotalDiskSpace16(const wchar *path);
// ---- shell.FileSystem ---- END



// ==== AVMGLUE ==== 


#endif /* __avmplus_VMPI2__ */
