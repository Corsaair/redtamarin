/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "VMPI.h"
#include "VMPI2.h"

// ==== BEFORE ==== 
/* for special case that need to be defined first */

static int WIN32_winsock_started = 0;

int WIN32_SocketStart(int major, int minor)
{
    if( WIN32_winsock_started )
    {
        return 0;
    }

    WSADATA wsaData;
    WORD wVersionRequested;
    int err;
    
    wVersionRequested = MAKEWORD(major, minor);
    err = WSAStartup(wVersionRequested, &wsaData);
    
    if (err != 0) {
        printf("WSAStartup failed with error: %d\n", err);
        return 1;
    }

    WIN32_winsock_started = 1;
    return 0;
}

void WIN32_SocketStop()
{
    /* note:
       it would be a bad idea to call the WSA cleanup in the middle of code execution
       the function is here but not used, in Platform.h for WIN32
       when exit() is called we also call WSACleanup(), much cleaner approach imho

       Also we could also suppress the need to call WIN32_SocketStart
       by calling it by default in the start() function of Platform.h
       not sure how it can affect memory/load to automatically call it
       if no socket related code is used
    */
    if( WIN32_winsock_started )
    {
        WSACleanup();
    }
}

static int setenv_with_putenv(const char *name, const char *value)
{
    if(NULL != VMPI_strchr(name, '='))
    {
        errno = EINVAL;
        return -1;
    }
    else
    {
        size_t  nameLen     =   VMPI_strlen(name);
        size_t  valueLen    =   VMPI_strlen(value);
        size_t  required    =   1 + nameLen + 1 + valueLen;
        char    buffer_[101];
        char    *buffer     =   (ARRAY_SIZE(buffer_) < required)
                                    ? (char*)malloc(required * sizeof(char))
                                    : &buffer_[0];

        if(NULL == buffer)
        {
            errno = ENOMEM;
            return -1;
        }
        else
        {
            int r;
            (void)VMPI_strncpy(&buffer[0], name, nameLen);
            buffer[nameLen] = '=';
            buffer[nameLen + 1] = '\0';
            (void)VMPI_strncpy(&buffer[nameLen + 1], value, valueLen);
            buffer[nameLen + 1 + valueLen] = '\0';

            r = _putenv(&buffer[0]);

            if(buffer != &buffer_[0])
            {
                VMPI_free(buffer);
            }

            return r;
        }
    }
}

static int setenv16_with_putenv16(const wchar *name, const wchar *value)
{
    if(NULL != VMPI_strchr16(name, L'='))
    {
        errno = EINVAL;
        return -1;
    }
    else
    {
        size_t  nameLen     =   VMPI_strlen16(name);
        size_t  valueLen    =   VMPI_strlen16(value);
        size_t  required    =   1 + nameLen + 1 + valueLen;
        wchar   buffer_[101];
        wchar   *buffer     =   (ARRAY_SIZE(buffer_) < required)
                                    ? (wchar*)malloc(required * sizeof(wchar))
                                    : &buffer_[0];

        if(NULL == buffer)
        {
            errno = ENOMEM;
            return -1;
        }
        else
        {
            int r;
            (void)VMPI_strncpy16(&buffer[0], name, nameLen);
            buffer[nameLen] = L'=';
            buffer[nameLen + 1] = '\0';
            (void)VMPI_strncpy16(&buffer[nameLen + 1], value, valueLen);
            buffer[nameLen + 1 + valueLen] = '\0';

            r = _wputenv(&buffer[0]);

            if(buffer != &buffer_[0])
            {
                VMPI_free(buffer);
            }

            return r;
        }
    }
}

// ==== HEADERS ==== 

//#include <errno.h> //already included in win32-platform2.h

//#include <stdlib.h>

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
    (void)pid;
    (void)sig;
    
    errno = ENOSYS;
    return -1;
}
// ---- C.signal ---- END


// ---- C.stdarg ---- 

// ---- C.stdarg ---- END


// ---- C.stddef ---- 

// ---- C.stddef ---- END


// ---- C.stdio ---- 
void VMPI_flockfile (FILE *stream)
{
    _lock_file(stream);
}

int VMPI_ftrylockfile (FILE *stream)
{
    _lock_file(stream); //yep that's cheap ...
    return 0;
}

void VMPI_funlockfile (FILE *stream)
{
    _unlock_file(stream);
}

int VMPI_getc_unlocked(FILE *stream)
{
    return _getc_nolock( stream );
}

int VMPI_getchar_unlocked()
{
    return _getchar_nolock();
}

int VMPI_putc_unlocked(int c, FILE *stream)
{
    return _putc_nolock( c, stream );
}

int VMPI_putchar_unlocked(int c)
{
    return _putchar_nolock( c );
}
// ---- C.stdio ---- END


// ---- C.stdlib ---- 
const char *VMPI_getenv(const char *name)
{
    return getenv( name );
}

const wchar *VMPI_getenv16(const wchar *name)
{
    return _wgetenv( name );
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
    (void)templ;
    
    errno = ENOSYS;
    return NULL;
}

int VMPI_mkstemp(char *templ)
{
    (void)templ;
    
    errno = ENOSYS;
    return -1;
}

/*
int VMPI_mkdir(const char *path, int mode)
{
    (void)mode;
    
    int size_needed = MultiByteToWideChar( CP_UTF8, 0, path, -1, NULL, 0);

    if( size_needed != 0 )
    {
        wchar* wpath = new wchar[size_needed];
        int result = MultiByteToWideChar( CP_UTF8, 0, path, -1, wpath, size_needed );

        return _wmkdir( wpath );
    }
    
    return -1;
}
*/

/*const char *VMPI_getenv(const char *env)
{
    const char *val = NULL;
    printf( "getenv() start \n" );

    //(void)env;
    // Environment variables are not available for Windows Store applications.
//#ifndef AVMSYSTEM_WINDOWSSTOREAPP
//#ifndef UNDER_CE
    int size_needed = MultiByteToWideChar( CP_UTF8, 0, env, -1, NULL, 0);
    printf( "size_needed = %u\n", size_needed );

    if( size_needed != 0 )
    {
        wchar* wenv = new wchar[size_needed];
        MultiByteToWideChar( CP_UTF8, 0, env, -1, wenv, size_needed );

        const wchar *wenvresult = _wgetenv( wenv );
        wprintf( L"wenvresult = %ls\n", wenvresult );

        if( wenvresult != NULL )
        {
            int wlen = WideCharToMultiByte( CP_UTF8, 0, wenvresult, -1, NULL, 0, NULL, NULL );
            printf( "wlen = %u\n", wlen );

            if( wlen != 0 )
            {
                char* envresult = new char[wlen];
                WideCharToMultiByte( CP_UTF8, 0, wenvresult, -1, envresult, wlen, NULL, NULL );

                printf( "envresult = %s\n", envresult );

                val = envresult;
            }
        }
    }

    //val = getenv(env);
//#endif
//#endif // AVMSYSTEM_WINDOWSSTOREAPP

    printf( "getenv() end \n" );
    return val;
}*/



int VMPI_putenv(char *name)
{
    return _putenv( name );
}

int VMPI_putenv16(wchar *name)
{
    return _wputenv( name );
}

char *VMPI_realpath(char const *path)
{
    /* note:
       if the path does not exists the path will still resolve
       and does not set errno to ENOENT "No such file or directory"
    */
    char* full = NULL;
    char* result = NULL;
    
    if( VMPI_access(path, F_OK) ) {
        errno = ENOENT;
        return NULL;
    }
    
    //char *_fullpath( char *absPath, const char *relPath, size_t maxLength );
    result = _fullpath( full, path, PATH_MAX );
    //and from this point 'full' is fuxored and 'result' is all good
    
    if( result != NULL ) {
        return result;
    }
    
    return NULL; 
}

wchar *VMPI_realpath16(wchar const *path)
{
    /* note:
       if the path does not exists the path will still resolve
       and does not set errno to ENOENT "No such file or directory"
    */
    wchar* full = NULL;
    wchar* result = NULL;
    
    if( VMPI_access16(path, F_OK) ) {
        errno = ENOENT;
        return NULL;
    }
    
    result = _wfullpath( full, path, PATH_MAX );
    
    if( result != NULL ) {
        return result;
    }
    
    return NULL; 
}

int VMPI_setenv(const char *name, const char *value, int overwrite)
{
    if(!overwrite)
    {
        //VMPI_log("getenv = [");
        //VMPI_log(VMPI_getenv(name));
        //VMPI_log("]\n");
        if(NULL != VMPI_getenv(name))
        {
            return 0;
        }
    }

    return setenv_with_putenv(name, value);
}

int VMPI_setenv16(const wchar *name, const wchar *value, int overwrite)
{
    if(!overwrite)
    {
        if(NULL != VMPI_getenv16(name))
        {
            return 0;
        }
    }

    return setenv16_with_putenv16(name, value);
}

int VMPI_system(const char *command)
{
    #ifdef UNDER_CE
        AvmAssert(0);
        return 0;
    #else
        return system( command );
    #endif
}

int VMPI_system16(const wchar *command)
{
    return _wsystem( command );
}



int VMPI_unsetenv(const char *name)
{
    return setenv_with_putenv( name, "" );
}

int VMPI_unsetenv16(const wchar *name)
{
    return setenv16_with_putenv16( name, L"" );
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
    return (uint32_t) htonl( (u_long) hostlong );
}

uint32_t VMPI_htons(uint32_t hostshort )
{
    return (uint32_t) htons( (u_short) hostshort );
}

uint32_t VMPI_ntohl(uint32_t netlong )
{
    return (uint32_t) ntohl( (u_long) netlong );
}

uint32_t VMPI_ntohs(uint32_t netshort )
{
    return (uint32_t) ntohs( (u_short) netshort );
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
    DWORD mode;
    HANDLE hConIn = GetStdHandle( STD_INPUT_HANDLE );
    GetConsoleMode( hConIn, &mode );
    mode = status ? (mode | ENABLE_LINE_INPUT) : (mode & ~(ENABLE_LINE_INPUT));
    SetConsoleMode( hConIn , mode );
    FlushConsoleInputBuffer( hConIn );
}

void VMPI_echo(bool status)
{
    DWORD mode;
    HANDLE hConIn = GetStdHandle( STD_INPUT_HANDLE );
    GetConsoleMode( hConIn, &mode );
    mode = status ? (mode | ENABLE_ECHO_INPUT) : (mode & ~(ENABLE_ECHO_INPUT));
    SetConsoleMode( hConIn, mode );
}

int VMPI_kbhit()
{
    return _kbhit();
}
// ---- C.conio ---- END


// ---- C.cpio ---- 

// ---- C.cpio ---- END


// ---- C.dirent ---- 
DIR * opendir (const char * name)
{
    DIR *dir;
    HANDLE hnd;
    char *file;
    WIN32_FIND_DATA find;

    if( !name || !*name )
    {
        return NULL;
    }

    file = static_cast<char *>( malloc( strlen (name) + 3 ) );
    strcpy( file, name );

    if( (file[strlen (name) - 1] != '/' ) && (file[strlen (name) - 1] != '\\' ) )
    {
        strcat( file, "/*" );
    }
    else
    {
        strcat( file, "*" );
    }

    if( (hnd = FindFirstFile( file, &find )) == INVALID_HANDLE_VALUE )
    {
        free( file );
        return NULL;
    }

    dir = reinterpret_cast<DIR *>( malloc( sizeof(DIR) ) );
    dir->mask       = file;
    dir->fd         = (int) hnd;
    dir->data       = static_cast<char *>( malloc( sizeof(WIN32_FIND_DATA) ) );
    dir->allocation = sizeof(WIN32_FIND_DATA);
    dir->size       = dir->allocation;
    dir->filepos    = 0;

    memcpy( dir->data, &find, sizeof(WIN32_FIND_DATA) );
    return dir;
}

struct dirent * readdir (DIR * dir)
{
    static struct dirent entry;
    WIN32_FIND_DATA *find;

    entry.d_ino  = 0;
    entry.d_type = 0;

    find = (WIN32_FIND_DATA *) dir->data;

    if( dir->filepos )
    {
        if( !FindNextFile( (HANDLE) dir->fd, find ) )
        {
            return NULL;
        }
    }

    entry.d_off = dir->filepos;
    strncpy( entry.d_name, find->cFileName, sizeof(entry.d_name) );
    entry.d_reclen = (unsigned short int) strlen( find->cFileName );
    dir->filepos++;

    return &entry;
}

int closedir (DIR * dir)
{
    HANDLE hnd = (HANDLE) dir->fd;

    free( dir->data );
    free( dir->mask );
    free( dir );

    return FindClose(hnd) ? 0 : -1;
}

void rewinddir (DIR * dir)
{
    HANDLE hnd = (HANDLE) dir->fd;
    WIN32_FIND_DATA *find = (WIN32_FIND_DATA *) dir->data;

    FindClose( hnd );
    hnd = FindFirstFile( dir->mask, find );

    dir->fd      = (int) hnd;
    dir->filepos = 0;
}

void seekdir (DIR * dir, off_t offset)
{
    off_t n;

    rewinddir( dir );

    for( n = 0; n < offset; n++ )
    {
        if( FindNextFile( (HANDLE) dir->fd, (WIN32_FIND_DATA *) dir->data ) )
        {
            dir->filepos++;
        }
    }
}

off_t telldir (DIR * dir)
{
    return dir->filepos;
}

int dirfd (DIR * dir)
{
    return dir->fd;
}

DIR *VMPI_fdopendir(int fd)
{
    (void)fd;

    errno = ENOSYS;
    return NULL;
}
// ---- C.dirent ---- END


// ---- C.fcntl ---- 
int VMPI_fcntl(int fildes, int cmd, int arg)
{
    (void)fildes;
    (void)cmd;
    (void)arg;

    errno = ENOSYS;
    return -1;
}

int VMPI_openat(int fd, const char *path, int oflag, int mode)
{
    (void)fd;
    (void)path;
    (void)oflag;
    (void)mode;
    
    errno = ENOSYS;
    return -1;
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

struct protoent *getprotoent()
{
    return (struct protoent *) NULL;
}

struct hostent *gethostent()
{
    return (struct hostent *) NULL;
}

struct protoent *VMPI_getprotobynumber(int proto)
{
    struct protoent *result = NULL;

    if( WIN32_SocketStart(2,2) == 0 ) {
        result = ::getprotobynumber(proto);
    }

    return result;
}

struct protoent *VMPI_getprotoent()
{
    struct protoent *result = NULL;

    if( WIN32_SocketStart(2,2) == 0 ) {
        result = ::getprotoent();
    }

    return result;
}

struct hostent *VMPI_gethostent()
{
    struct hostent *result = NULL;

    if( WIN32_SocketStart(2,2) == 0 ) {
        result = ::gethostent();
    }

    return result;
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
    /* note:
       see http://msdn.microsoft.com/en-us/library/zb9ehy71.aspx
       _spawnvpe() return the pid, not the status
     */
    //return posix_spawn( pid, path, NULL, NULL, argv, envp );
    (void)pid;
    int mode = _P_NOWAIT;
    return _spawnvpe( mode, path, argv, envp );
}

int VMPI_spawnp(int *pid, const char *file, char *const argv[], char *const envp[])
{
    //return posix_spawnp( (pid_t *)pid, file, NULL, NULL, argv, envp );
    (void)pid;
    int mode = _P_NOWAIT;
    return _spawnve( mode, file, argv, envp );
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
    return _chmod( path, (mode_t) mode );
}

int VMPI_chmod16(const wchar *path, int mode)
{
    return _wchmod( path, (mode_t) mode );
}

/*int VMPI_fstat(int fildes, struct stat *buf)
{
    struct _stat st;
    int ret = _fstat( fildes, &st );
    if( ret == -1 )
    {
        VMPI_memset( buf, 0, sizeof(struct stat) );
        return -1;
    }

    return ret;
}*/

/*
        #if defined (UNDER_CE)
            int filenameLen = VMPI_strlen(filename);

            TCHAR* logname = new TCHAR[filenameLen+1];

            mbstowcs(logname, filename, filenameLen+1);

            _wfreopen(logname, L"w", stdout);

            delete [] logname;
        #else
            FILE *f = freopen(filename, "w", stdout);

*/

/*int VMPI_mkdir(const char *path, int mode)
{
    (void)mode;

    int size_needed = MultiByteToWideChar( CP_UTF8, 0, path, -1, NULL, 0);

    if( size_needed != 0 )
    {
        wchar* wpath = new wchar[size_needed];
        MultiByteToWideChar( CP_UTF8, 0, path, -1, wpath, size_needed );

        return _wmkdir( wpath );
    }
    
    return -1;
}*/

int VMPI_mkdir(const char *path, int mode)
{
    (void)mode;
    return _mkdir( path );
}

int VMPI_mkdir16(const wchar *path, int mode)
{
    (void)mode;
    return _wmkdir( path );
}


/*int VMPI_stat(const char *path, struct stat *buf)
{
    //error C2664: '_stat64i32' : cannot convert parameter 2
    //from 'stat *' to '_stat64i32 *'

    struct _stat st;
    int ret = _stat( path, &st );
    if( ret == -1 )
    {
        VMPI_memset( buf, 0, sizeof(struct stat) );
        return -1;
    }

    return ret;
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
    return status;
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
    return status;
}

int VMPI_WSTOPSIG(int status)
{
    return status;
}

int VMPI_WTERMSIG(int status)
{
    return WTERMSIG(status);
}

int VMPI_wait(int *stat_loc)
{
    (void)stat_loc;

    errno = ENOSYS;
    return -1;
}

int VMPI_waitid(int idtype, int id, siginfo_t *infop, int options)
{
    (void)idtype;
    (void)id;
    (void)infop;
    (void)options;

    errno = ENOSYS;
    return -1;
}

int VMPI_waitpid(int pid, int *stat_loc, int options)
{
    (void)options;

    return _cwait( stat_loc, pid, WAIT_CHILD );
}
// ---- C.sys.wait ---- END


// ---- C.tar ---- 

// ---- C.tar ---- END


// ---- C.termios ---- 

// ---- C.termios ---- END


// ---- C.unistd ---- 
int ftruncate(int fildes, off_t length)
{
    HANDLE hfile;
    unsigned int curpos;

    if( fildes < 0 )
    {
        errno = EBADF;
        return -1;
    }

    if( length < 0 )
    {
        errno = EINVAL;
        return -1;
    }

    hfile = (HANDLE) _get_osfhandle (fildes);
    curpos = SetFilePointer( hfile, 0, NULL, FILE_CURRENT );

    if( (curpos == ~0) ||
        (SetFilePointer( hfile, length, NULL, FILE_BEGIN ) == ~0) ||
        (!SetEndOfFile( hfile )) )
    {
        int error = GetLastError();

        switch( error )
        {
            case ERROR_INVALID_HANDLE:
            errno = EBADF;
            break;

            default:
            errno = EIO;
            break;
        }

        return -1;
    }

    return 0;
}

char **VMPI_GetEnviron()
{
    return _environ;
}

wchar **VMPI_GetEnviron16()
{
    return _wenviron;
}

wchar *VMPI_getcwd16(wchar *buf, size_t size)
{
    return _wgetcwd( buf, (int) size );
}

int VMPI_gethostname(char *name, int namelen)
{
    int result = -1;
    
    if( WIN32_SocketStart(2,2) == 0 ) {
        result = ::gethostname(name, namelen);
    }
    
    return result;
}

void VMPI_sleep(int milliseconds)
{
    Sleep(milliseconds);
}
// ---- C.unistd ---- END


// ---- C.utime ---- 

// ---- C.utime ---- END




// ==== RNL ==== 

// ---- shell.HardwareInformation ---- 
double VMPI_SystemMemorySize()
{
    double result_size = 0L;

    MEMORYSTATUSEX status;
    status.dwLength = sizeof(status);
    GlobalMemoryStatusEx( &status );
    result_size = (double) status.ullTotalPhys;

    return result_size;
}

double VMPI_SystemMemoryUse()
{
    double result_used = 0L;

    PROCESS_MEMORY_COUNTERS info;
    GetProcessMemoryInfo( GetCurrentProcess(), &info, sizeof(info) );
    result_used = (double) info.WorkingSetSize;

    return result_used;
}

double VMPI_SystemMemoryPeak()
{
    double result_peak = 0L;

    PROCESS_MEMORY_COUNTERS info;
    GetProcessMemoryInfo( GetCurrentProcess(), &info, sizeof(info) );
    result_peak = (double) info.PeakWorkingSetSize;

    return result_peak;
}

// ---- shell.HardwareInformation ---- END

// ---- shell.OperatingSystem ---- 
void VMPI_getUserName(char *username)
{
    //DWORD bufsize = 256;
    DWORD bufsize = LOGIN_NAME_MAX;
    GetUserNameA(username, &bufsize);
}

void VMPI_getUserName16(wchar *username)
{
    DWORD bufsize = LOGIN_NAME_MAX;
    GetUserNameW(username, &bufsize);
}
// ---- shell.OperatingSystem ---- END

// ---- shell.FileSystem ---- 
bool VMPI_isAttributeHidden(const char *path)
{
    DWORD attrib = GetFileAttributes( path );

    if(attrib & FILE_ATTRIBUTE_HIDDEN) {
        return true;
    }

    return false;
}

bool VMPI_isAttributeHidden16(const wchar *path)
{
    /* NOTE:
       the AS3 function preprend "\\?\" to the path
    */
    DWORD attrib = GetFileAttributes( path );

    if(attrib & FILE_ATTRIBUTE_HIDDEN) {
        return true;
    }

    return false;
}

int VMPI_getLogicalDrives()
{
    DWORD drives = GetLogicalDrives();
    return (int)drives;
}

double VMPI_getFreeDiskSpace(const char *path)
{
    ULARGE_INTEGER available;
    if(!GetDiskFreeSpaceExA(path, &available, NULL, NULL)) {
        return -1;
    }
    return static_cast<double>(available.QuadPart);
}

double VMPI_getFreeDiskSpace16(const wchar *path)
{
    ULARGE_INTEGER available;
    if(!GetDiskFreeSpaceExW(path, &available, NULL, NULL)) {
        return -1;
    }
    return static_cast<double>(available.QuadPart);
}

double VMPI_getTotalDiskSpace(const char *path)
{
    ULARGE_INTEGER total;
    if(!GetDiskFreeSpaceExA(path, NULL, &total, NULL)) {
        return -1;
    }
    return static_cast<double>(total.QuadPart);
}

double VMPI_getTotalDiskSpace16(const wchar *path)
{
    ULARGE_INTEGER total;
    if(!GetDiskFreeSpaceExW(path, NULL, &total, NULL)) {
        return -1;
    }
    return static_cast<double>(total.QuadPart);
}
// ---- shell.FileSystem ---- END


// ==== AVMGLUE ==== 




