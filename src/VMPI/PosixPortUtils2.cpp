/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

// ==== BEFORE ==== 
/* for special case that need to be defined first */

// ==== HEADERS ==== 

#include "VMPI.h"
#include "VMPI2.h"

#ifdef AVMPLUS_MAC
    #include <malloc/malloc.h>
    #include <CoreServices/CoreServices.h>
    #include <crt_externs.h>
    #include <mach/vm_statistics.h>
    #include <mach/mach.h>
    #include <mach/mach_types.h>
    #include <mach/mach_init.h>
    #include <mach/mach_host.h>
#else
    #include <sys/sysinfo.h>
    #include <sys/sysctl.h>
    #include <sys/types.h>
#endif

//for termios, ttystate, tcgetattr, ICANON, WMIN, TCSANOW, tcsetattr in C.stdio
#include <termios.h>

#include <stdint.h>

#include <spawn.h>

#include <sys/wait.h>

#include <sys/resource.h>

// ==== ISO C / ANSI C ==== 

// ---- C.assert ---- 

// ---- C.assert ---- END


// ---- C.ctype ---- 

// ---- C.ctype ---- END


// ---- C.errno ---- 
void VMPI_set_errno(int value)
{
    errno = value;
}

int VMPI_get_errno()
{
    return errno;
}
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
int VMPI_kill(int pid, int sig)
{
    return kill( (pid_t)pid, sig );
}
// ---- C.signal ---- END


// ---- C.stdarg ---- 

// ---- C.stdarg ---- END


// ---- C.stddef ---- 

// ---- C.stddef ---- END


// ---- C.stdio ---- 
void VMPI_flockfile(FILE *stream)
{
    flockfile(stream);
}

int VMPI_ftrylockfile(FILE *stream)
{
    return ftrylockfile(stream);
}

void VMPI_funlockfile(FILE *stream)
{
    funlockfile(stream);
}

int VMPI_getc_unlocked(FILE *stream)
{
    return getc_unlocked( stream );
}

int VMPI_getchar_unlocked()
{
    return getchar_unlocked();
}

int VMPI_putc_unlocked(int c, FILE *stream)
{
    return putc_unlocked( c, stream );
}

int VMPI_putchar_unlocked(int c)
{
    return putchar_unlocked( c );
}
// ---- C.stdio ---- END


// ---- C.stdlib ---- 
const wchar *VMPI_getenv16(const wchar *name)
{
    (void)name;
    return NULL;
}

ldiv_t VMPI_ldiv(double numer, double denom)
{
    return ldiv( (long) numer, (long) denom );
}

lldiv_t VMPI_lldiv(double numer, double denom)
{
    return lldiv( (long long) numer, (long long) denom );
}

char *VMPI_mkdtemp(char *templ)
{
    return mkdtemp( templ );
}

int VMPI_mkstemp(char *templ)
{
    return mkstemp( templ );
}

int VMPI_putenv(char *name)
{
    return putenv( name );
}

int VMPI_putenv16(wchar *name)
{
    (void)name;
    return -1;
}

char *VMPI_realpath(char const *path)
{
    //char resolved[PATH_MAX];
    //return realpath(path, resolved);

    char* full = NULL;
    char* result = NULL;

    result = realpath( path, full );
    
    //printf( "realpath path = %s\n", path );
    //printf( "realpath full = %s\n", full );
    //printf( "realpath result = %s\n", result );
    
    if( result != NULL ) {
        return result;
    }
    
    return NULL;
}

wchar *VMPI_realpath16(wchar const *path)
{
    (void)path;
    return NULL;
}

int VMPI_setenv(const char *name, const char *value, int overwrite)
{
    return setenv( name, value, overwrite );
}

int VMPI_setenv16(const wchar *name, const wchar *value, int overwrite)
{
    (void)name;
    (void)value;
    (void)overwrite;
    return -1;
}

int VMPI_system(const char *command)
{
    return system( command );
}

int VMPI_system16(const wchar *command)
{
    (void)command;
    return -1;
}

int VMPI_unsetenv(const char *name)
{
    return unsetenv( name );
}

int VMPI_unsetenv16(const wchar *name)
{
    (void)name;
    return -1;
}
// ---- C.stdlib ---- END


// ---- C.string ---- 

// ---- C.string ---- END


// ---- C.time ---- 

// ---- C.time ---- END




// ==== POSIX ==== 

// ---- C.arpa.inet ---- 
uint32_t VMPI_htonl(uint32_t hostlong)
{
    return htonl( hostlong );
}

uint32_t VMPI_htons(uint32_t hostshort )
{
    return (uint32_t) htons( (uint16_t) hostshort );
}

uint32_t VMPI_ntohl(uint32_t netlong )
{
    return ntohl( netlong );
}

uint32_t VMPI_ntohs(uint32_t netshort )
{
    return (uint32_t) ntohs( (uint16_t) netshort );
}

uint32_t VMPI_inet_addr(const char *cp)
{
    return (uint32_t) inet_addr( cp );
}

uint32_t VMPI_inet_network(const char *cp)
{
    return (uint32_t) inet_network( cp );
}

char *VMPI_inet_ntoa(struct in_addr inaddr)
{
    return inet_ntoa( inaddr );
}

int VMPI_inet_aton(const char *cp, struct in_addr *inp)
{
    return inet_aton( cp, inp );
}

const char *VMPI_inet_ntop(int af, const void *src, char *dst, socklen_t size)
{
    return inet_ntop( af, src, dst, size);
}

int VMPI_inet_pton(int af, const char *src, void *dst)
{
    return inet_pton( af, src, dst );
}
// ---- C.arpa.inet ---- END

// ---- C.conio ---- 
void VMPI_canonical(bool status)
{
    struct termios settings;
    tcgetattr( STDIN_FILENO, &settings );

    if( status )
    {
        settings.c_lflag |= ICANON;
    }
    else
    {
        settings.c_lflag &= ~ICANON;
        settings.c_cc[VMIN] = 1;
    }
    
    tcsetattr( STDIN_FILENO, TCSANOW, &settings );
}

void VMPI_echo(bool status)
{
    struct termios settings;
    tcgetattr( STDIN_FILENO, &settings );
    settings.c_lflag = status ? (settings.c_lflag | ECHO ) : (settings.c_lflag & ~(ECHO));
    tcsetattr( STDIN_FILENO, TCSANOW, &settings );
}

/*int VMPI_getch()
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}*/

/*int VMPI_getche()
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}*/

int VMPI_kbhit()
{
    struct timeval tv;
    fd_set fds;
    tv.tv_sec = 0;
    tv.tv_usec = 0;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds); //STDIN_FILENO is 0
    select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
    return FD_ISSET(STDIN_FILENO, &fds);
}

bool VMPI_setBinaryMode(int fd, bool binary)
{
    (void)fd;
    (void)binary;
    return true;
}
// ---- C.conio ---- END


// ---- C.cpio ---- 

// ---- C.cpio ---- END


// ---- C.dirent ---- 
DIR *VMPI_fdopendir(int fd)
{
/* note:
   Macintosh does not define fdopendir()
   Linux does
*/
#ifdef AVMPLUS_MAC
    char fullpath[MAXPATHLEN];
    DIR *d;

    if(fcntl(fd, F_GETPATH, fullpath) < 0)
    {
        //perror("fcntl");
        //fprintf(stderr, "tup error: Unable to convert file descriptor back to pathname in fdopendir() compat library.\n");
        //fcntl() set the errno
        if( errno == 0 ) { errno = EBADF; }
        return NULL;
    }

    if(close(fd) < 0)
    {
        //perror("close(fd) in tup's OSX fdopendir() wrapper:");
        //close() set the errno
        return NULL;
    }

    d = opendir(fullpath);
    return d;
#else
    return fdopendir(fd);
#endif
}
// ---- C.dirent ---- END


// ---- C.fcntl ---- 
int VMPI_fcntl(int fildes, int cmd, int arg)
{
    if( arg > -1 )
    {
        return fcntl( fildes, cmd, arg );
    }
    else
    {
        return fcntl( fildes, cmd );
    }
}

int VMPI_openat(int fd, const char *path, int oflag, int mode)
{
#ifdef AVMPLUS_MAC
    (void)fd;
    (void)path;
    (void)oflag;
    (void)mode;
    errno = ENOSYS;
    return -1;
#else
    if( mode > -1 )
    {
        return openat( fd, path, oflag, mode );
    }
    else
    {
        return openat( fd, path, oflag );
    }
#endif
}
// ---- C.fcntl ---- END


// ---- C.grp ---- 

// ---- C.grp ---- END


// ---- C.netdb ---- 
const char *VMPI_gai_strerror(int ecode)
{
    return gai_strerror( ecode );
}

struct hostent *VMPI_gethostbyname(const char *name)
{
    return gethostbyname( name );
}

struct hostent *VMPI_gethostbyaddr(const char *addr, int len, int type)
{
    return gethostbyaddr( addr, len, type );
}

struct protoent *VMPI_getprotobynumber(int proto)
{
    return ::getprotobynumber(proto);
}

struct protoent *VMPI_getprotoent()
{
    return ::getprotoent();
}

struct hostent *VMPI_gethostent()
{
    return ::gethostent();
}

int VMPI_getaddrinfo(const char *nodename, const char *servname, const struct addrinfo *hints, struct addrinfo **res)
{
    return getaddrinfo( nodename, servname, hints, res );
}

void VMPI_freeaddrinfo(struct addrinfo *ai)
{
    freeaddrinfo( ai );
}
// ---- C.netdb ---- END


// ---- C.pthread ---- 

// ---- C.pthread ---- END


// ---- C.pwd ---- 

// ---- C.pwd ---- END


// ---- C.spawn ---- 
int VMPI_spawn(int *pid, const char *path, char *const argv[], char *const envp[])
{
    return posix_spawn( (pid_t *)pid, path, NULL, NULL, argv, envp );
}

int VMPI_spawnp(int *pid, const char *file, char *const argv[], char *const envp[])
{
    return posix_spawnp( (pid_t *)pid, file, NULL, NULL, argv, envp );
}
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
void VMPI_FD_CLR(int fd, fd_set *fdset)
{
    FD_CLR( fd, fdset );
}

int VMPI_FD_ISSET(int fd, fd_set *fdset)
{
    return FD_ISSET( fd, fdset );
}

void VMPI_FD_SET(int fd, fd_set *fdset)
{
    FD_SET( fd, fdset );
}

void VMPI_FD_ZERO(fd_set *fdset)
{
    FD_ZERO( fdset );
}

int VMPI_select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *errorfds, struct timeval *timeout)
{
    return select( nfds, readfds, writefds, errorfds, timeout );
}
// ---- C.sys.select ---- END


// ---- C.sys.socket ---- 
int VMPI_accept(int socket, struct sockaddr *address, socklen_t *address_len)
{
    return accept( socket, address, address_len );
}

int VMPI_bind(int socket, const struct sockaddr *address, socklen_t address_len)
{
    return bind( socket, address, address_len );
}

int VMPI_connect(int socket, const struct sockaddr *address, socklen_t address_len)
{
    return connect( socket, address, address_len );
}

int VMPI_getpeername(int socket, struct sockaddr *address, socklen_t *address_len)
{
    return getpeername( socket, address, address_len );
}

int VMPI_getsockname(int socket, struct sockaddr *address, socklen_t *address_len)
{
    return getsockname( socket, address, address_len );
}

int VMPI_getsockopt(int socket, int level, int option_name, void *option_value, socklen_t *option_len)
{
    return getsockopt( socket, level, option_name, option_value, option_len );
}

int VMPI_setsockopt(int socket, int level, int option_name, const void *option_value, socklen_t option_len)
{
    return setsockopt( socket, level, option_name, option_value, option_len );
}

int VMPI_listen(int socket, int backlog)
{
    return listen( socket, backlog );
}

int VMPI_recv(int socket, void *buffer, size_t length, int flags)
{
    return recv( socket, buffer, length, flags );
}

int VMPI_recvfrom(int socket, void *buffer, size_t length, int flags, struct sockaddr *address, socklen_t *address_len)
{
    return recvfrom( socket, buffer, length, flags, address, address_len );
}

int VMPI_send(int socket, const void *buffer, size_t length, int flags)
{
    return send( socket, buffer, length, flags );
}

int VMPI_sendto(int socket, const void *message, size_t length, int flags, const struct sockaddr *dest_addr, socklen_t dest_len)
{
    return sendto( socket, message, length, flags, dest_addr, dest_len );
}

int VMPI_shutdown(int socket, int how)
{
    return shutdown( socket, how );
}

int VMPI_sockatmark(int s)
{
    return sockatmark( s );
}

int VMPI_socket(int domain, int type, int protocol)
{
    return socket( domain, type, protocol );
}

int VMPI_socketpair(int domain, int type, int protocol, int socket_vector[2])
{
    return socketpair( domain, type, protocol, socket_vector );
}
// ---- C.sys.socket ---- END


// ---- C.sys.stat ---- 
int VMPI_chmod(const char *path, int mode)
{
    return chmod(path, (mode_t)mode);
}

int VMPI_chmod16(const wchar *path, int mode)
{
    (void)path;
    (void)mode;
    return -1;
}

/*int VMPI_fstat(int fildes, struct stat *buf)
{
    return fstat( fildes, &buf );
}*/

int VMPI_mkdir(const char *path, int mode)
{
    return mkdir(path, (mode_t)mode);
}

int VMPI_mkdir16(const wchar *path, int mode)
{
    (void)path;
    (void)mode;
    return -1;
}

/*int VMPI_stat(const char *path, struct stat *buf)
{
    return stat( path, &buf );
}*/
// ---- C.sys.stat ---- END


// ---- C.sys.time ---- 

// ---- C.sys.time ---- END


// ---- C.sys.types ---- 

// ---- C.sys.types ---- END


// ---- C.sys.utsname ---- 

// ---- C.sys.utsname ---- END


// ---- C.sys.wait ---- 
int VMPI_WEXITSTATUS(int status)
{
    return WEXITSTATUS(status);
}

int VMPI_WIFCONTINUED(int status)
{
    return WIFCONTINUED(status);
}

int VMPI_WIFEXITED(int status)
{
    return WIFEXITED(status);
}

int VMPI_WIFSIGNALED(int status)
{
    return WIFSIGNALED(status);
}

int VMPI_WIFSTOPPED(int status)
{
    return WIFSTOPPED(status);
}

int VMPI_WSTOPSIG(int status)
{
    return WSTOPSIG(status);
}

int VMPI_WTERMSIG(int status)
{
    return WTERMSIG(status);
}

int VMPI_wait(int *stat_loc)
{
    return wait( stat_loc );
}

int VMPI_waitid(int idtype, int id, siginfo_t *infop, int options)
{
    //idtype_t idtype, id_t id, siginfo_t *infop, int options
    return waitid( (idtype_t)idtype, (id_t)id, infop, options );
}

int VMPI_waitpid(int pid, int *stat_loc, int options)
{
    return waitpid( pid, stat_loc, options );
}
// ---- C.sys.wait ---- END


// ---- C.tar ---- 

// ---- C.tar ---- END


// ---- C.termios ---- 

// ---- C.termios ---- END


// ---- C.unistd ---- 
int VMPI_close(int fildes)
{
    return ::close( fildes );
}

/* NOTE:
   see: https://developer.apple.com/library/mac/documentation/Darwin/Reference/Manpages/man7/environ.7.html
   "if direct access to environ is needed, the _NSGetEnviron() routine,
   defined in <crt_externs.h>, can be used to retrieve the address of environ at runtime."

*/
char **VMPI_GetEnviron()
{
    #if AVMSYSTEM_MAC
        return *_NSGetEnviron();
    #else
        return environ;
    #endif
}

wchar **VMPI_GetEnviron16()
{
    return NULL;
}

wchar *VMPI_getcwd16(wchar *buf, size_t size)
{
    (void)buf;
    (void)size;
    return NULL;
}

int VMPI_gethostname(char *name, int namelen)
{
    return ::gethostname(name, namelen);
}

void VMPI_sleep(int milliseconds)
{
    usleep(1000 * milliseconds);
}
// ---- C.unistd ---- END


// ---- C.utime ---- 

// ---- C.utime ---- END




// ==== RNL ==== 

// ---- shell.Program ---- 
void VMPI_exitCleanup()
{
    //nothing to cleanup for Macintosh/Linux
}
// ---- shell.Program ---- END

// ---- shell.HardwareInformation ---- 

/*
double VMPI_getPerformanceClockTicks()
{
    return (double)sysconf(_SC_CLK_TCK);
}
*/

/* cpu ticks to milliseconds */
/*
#define CPU_MSEC 1000L
#define CPU_TICK2MSEC(s) \
    ((uint64_t)(s) * ((uint64_t)CPU_MSEC / (double)VMPI_getPerformanceClockTicks()))
*/

/*
void VMPI_GatherCPUUsage( double &cpu_kernel, double &cpu_user, double &cpu_nice, double &cpu_idle )
{

#ifdef AVMPLUS_MAC

    mach_msg_type_number_t count;
    host_cpu_load_info_data_t cpu_load;
    mach_port_t mach_port;

    count = HOST_CPU_LOAD_INFO_COUNT;
    mach_port = mach_host_self();

    if( host_statistics(mach_port, HOST_CPU_LOAD_INFO, 
      ( host_info_t )&cpu_load, &count ) != KERN_SUCCESS )
    {
        cpu_load = host_cpu_load_info_data_t();
    }

    
    //unsigned long long current_system = CPU_TICK2MSEC( cpu_load.cpu_ticks[CPU_STATE_SYSTEM] );
    //unsigned long long current_user   = CPU_TICK2MSEC( cpu_load.cpu_ticks[CPU_STATE_USER] );
    //unsigned long long current_nice   = CPU_TICK2MSEC( cpu_load.cpu_ticks[CPU_STATE_NICE] );
    //unsigned long long current_idle   = CPU_TICK2MSEC( cpu_load.cpu_ticks[CPU_STATE_IDLE] );
    
    unsigned long long current_system = cpu_load.cpu_ticks[CPU_STATE_SYSTEM];
    unsigned long long current_user   = cpu_load.cpu_ticks[CPU_STATE_USER];
    unsigned long long current_nice   = cpu_load.cpu_ticks[CPU_STATE_NICE];
    unsigned long long current_idle   = cpu_load.cpu_ticks[CPU_STATE_IDLE];
    
    cpu_kernel = (double)( current_system );
    cpu_user   = (double)( current_user );
    cpu_nice   = (double)( current_nice );
    cpu_idle   = (double)( current_idle );

#endif

}

double VMPI_SystemCPUUsage()
{
    double cpu_used = 0;

#ifdef AVMPLUS_MAC

    mach_msg_type_number_t count;
    host_cpu_load_info_data_t cpu_load;
    mach_port_t mach_port;

    count = HOST_CPU_LOAD_INFO_COUNT;
    mach_port = mach_host_self();

    if( host_statistics(mach_port, HOST_CPU_LOAD_INFO, 
      ( host_info_t )&cpu_load, &count ) != KERN_SUCCESS )
    {
        cpu_load = host_cpu_load_info_data_t();
    }

    //unsigned long long current_user = cpu_load.cpu_ticks[CPU_STATE_USER];
    unsigned long long current_system = CPU_TICK2MSEC( cpu_load.cpu_ticks[CPU_STATE_SYSTEM] );
    //unsigned long long current_nice = cpu_load.cpu_ticks[CPU_STATE_NICE];
    //unsigned long long current_idle = cpu_load.cpu_ticks[CPU_STATE_IDLE];
    
    cpu_used = (double)( current_system );

#endif

    return cpu_used;
}

double VMPI_UserCPUUsage()
{
    double cpu_used = 0;

#ifdef AVMPLUS_MAC

    mach_msg_type_number_t count;
    host_cpu_load_info_data_t cpu_load;
    mach_port_t mach_port;

    count = HOST_CPU_LOAD_INFO_COUNT;
    mach_port = mach_host_self();

    if( host_statistics(mach_port, HOST_CPU_LOAD_INFO, 
      ( host_info_t )&cpu_load, &count ) != KERN_SUCCESS )
    {
        cpu_load = host_cpu_load_info_data_t();
    }

    unsigned long long current_user = CPU_TICK2MSEC( cpu_load.cpu_ticks[CPU_STATE_USER] );
    
    cpu_used = (double)( current_user );

#endif

    return cpu_used;
}
*/

double VMPI_SystemMemorySize()
{
    double result_size = 0;

#ifdef AVMPLUS_MAC
    
    int mib[2];
    int64_t physical_memory;
    size_t length;

    mib[0] = CTL_HW;
    mib[1] = HW_MEMSIZE;
    length = sizeof(int64_t);
    if( sysctl(mib, 2, &physical_memory, &length, NULL, 0) == 0 )
    {
        result_size = (double)physical_memory;
    }

#else

    /* Note:
       on a Linux Ubuntu system with 8GB RAM, 
       alternative1 and alternative2
       reports only around 4GB RAM

       it is because of size_t
       eg. don't use size_t
    */

    //alternative1
    /*
    struct sysinfo info;
    sysinfo( &info );
    size_t total_ram = (size_t)info.totalram;
    size_t mem_unit = (size_t)info.mem_unit;

    result_size = (double)(total_ram * mem_unit);
    */
    
    //alternative2
    /*  
    size_t pagesize = (size_t)sysconf( _SC_PAGESIZE );
    size_t pages = (size_t)sysconf( _SC_PHYS_PAGES );
    
    result_size = (double)(pages * pagesize);
    */

    //the Linux way
    FILE* fp = fopen( "/proc/meminfo", "r" );
    if( fp != NULL )
    {
        size_t bufsize = 1024 * sizeof(char);
        char* buf      = (char*)malloc( bufsize );
        /* Note:
           uint64_t is equivalent to unsigned long long
           and sscanf() would need to use %SCNu64
           %llu work only on 32-bit but fail in 64-bit
           and yes we want to return double (Number in AS3)
           to not hit the MAX_UINT32 limit
        */
        uint64_t value = 0;

        while( getline( &buf, &bufsize, fp ) >= 0 )
        {
            if( strncmp( buf, "MemTotal", 8 ) != 0 )
            {
                continue;
            }

            sscanf( buf, "%*s%" SCNu64 , &value );
            break;
        }

        fclose( fp );
        free( (void*)buf );

        if( value != 0 )
        {
            result_size = (double)(value * 1024);
        }
    }

#endif

    return result_size;
}

double VMPI_SystemMemoryFree()
{
    double result_free = 0;

#ifdef AVMPLUS_MAC
    
    vm_size_t page_size;
    mach_port_t mach_port;
    mach_msg_type_number_t count;
    vm_statistics64_data_t vm_stats;

    mach_port = mach_host_self();
    count = sizeof(vm_stats) / sizeof(natural_t);

    if( (host_page_size(mach_port, &page_size) == KERN_SUCCESS) &&
        (host_statistics64(mach_port, HOST_VM_INFO,(host_info64_t)&vm_stats, &count) == KERN_SUCCESS) )
    {
        long long free_memory  = (int64_t)vm_stats.free_count;
                  free_memory *= (int64_t)page_size;

        result_free = (double)free_memory;
    }

#else

    //alternative1
    /*
    struct sysinfo info;
    sysinfo( &info );
    size_t free_ram = (size_t)info.freeram;
    size_t mem_unit = (size_t)info.mem_unit;

    result_free = (double)(free_ram * mem_unit);
    */

    //alternative2
    /*
    size_t pagesize = (size_t)sysconf( _SC_PAGESIZE );
    size_t availpages = (size_t)sysconf( _SC_AVPHYS_PAGES );
    
    result_free = (double)(availpages * pagesize);
    */

    //the Linux way
    FILE* fp = fopen( "/proc/meminfo", "r" );
    if( fp != NULL )
    {
        size_t bufsize = 1024 * sizeof(char);
        char* buf      = (char*)malloc( bufsize );
        uint64_t value = 0;

        while( getline( &buf, &bufsize, fp ) >= 0 )
        {
            if( strncmp( buf, "MemAvailable", 12 ) != 0 )
            {
                continue;
            }

            sscanf( buf, "%*s%" SCNu64, &value );
            break;
        }

        fclose( fp );
        free( (void*)buf );

        if( value != 0 )
        {
            result_free = (double)(value * 1024);
        }
    }

#endif
    
    return result_free;
}

double VMPI_ProcessMemoryUse()
{
    double result_used = 0;

#ifdef AVMPLUS_MAC
    
    struct mach_task_basic_info info;
    mach_msg_type_number_t infoCount = MACH_TASK_BASIC_INFO_COUNT;

    if ( task_info( mach_task_self( ), MACH_TASK_BASIC_INFO, (task_info_t)&info, &infoCount ) != KERN_SUCCESS )
    {
        result_used = 0; // can't access
    }
    else
    {
        result_used = (double)info.resident_size;
    }
    

#else

    long rss = 0L;
    FILE* fp = NULL;
    size_t current = 0;
    size_t pagesize = (size_t)sysconf( _SC_PAGESIZE );

    if( (fp = fopen( "/proc/self/statm", "r" )) == NULL )
    {
        current = 0; // can't open
    }
    else
    {
        if( fscanf( fp, "%*s%ld", &rss ) != 1 )
        {
            current = 0; // can't read
        }
        else
        {
            current = (size_t)rss;
        }

        fclose( fp );
    }

    result_used = (double)(current * pagesize);

#endif

    return result_used;
}

double VMPI_ProcessMemoryPeak()
{
    double result_peak = 0;

    struct rusage rusage;
    getrusage( RUSAGE_SELF, &rusage );

#ifdef AVMPLUS_MAC

    result_peak = (double)rusage.ru_maxrss;

#else

    result_peak = (double)(rusage.ru_maxrss * 1024);

#endif

    return result_peak;
}

// ---- shell.HardwareInformation ---- END

// ---- shell.OperatingSystem ---- 
/* note:
   1. getpwuid( geteuid() ) shall return the name associated with the effective user ID of the process
   2. getlogin() shall return the name associated with the current login activity
   3. getpwuid( getuid() ) shall return the name associated with the real user ID of the process
*/
void VMPI_getUserName(char *username)
{
    struct passwd *pws;
    pws = getpwuid( geteuid() );
    VMPI_strcpy( username, pws->pw_name ); 
}

void VMPI_getUserName16(wchar *username)
{
    (void)username;
}
// ---- shell.OperatingSystem ---- END

// ---- shell.FileSystem ---- 
bool VMPI_isAttributeHidden(const char *path)
{
#ifdef AVMPLUS_MAC
    struct stat stats;
    stat(path, &stats);
    return (stats.st_flags & UF_HIDDEN);
#else
    (void)path;
    return false;
#endif
}

bool VMPI_isAttributeHidden16(const wchar *path)
{
    (void)path;
    return false;
}

int VMPI_getLogicalDrives()
{
    return 0;
}

double VMPI_getFreeDiskSpace(const char *path)
{
    struct statvfs stats;
    if( statvfs(path, &stats) != 0) {
        return -1;
    }
    return static_cast<double>(stats.f_bavail) * stats.f_frsize;
}

double VMPI_getFreeDiskSpace16(const wchar *path)
{
    (void)path;
    return -1;
}

double VMPI_getTotalDiskSpace(const char *path)
{
    struct statvfs stats;
    if( statvfs(path, &stats) != 0) {
        return -1;
    }
    return static_cast<double>(stats.f_blocks) * stats.f_frsize;
}

double VMPI_getTotalDiskSpace16(const wchar *path)
{
    (void)path;
    return -1;
}
// ---- shell.FileSystem ---- END



// ==== AVMGLUE ==== 




