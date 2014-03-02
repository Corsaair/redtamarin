/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

// ==== BEFORE ==== 
/* for special case that need to be defined first */


// ==== HEADERS ==== 

#ifdef AVMPLUS_MAC
    #include <malloc/malloc.h>
    #include <CoreServices/CoreServices.h>
#endif //AVMPLUS_MAC

//for termios, ttystate, tcgetattr, ICANON, WMIN, TCSANOW, tcsetattr in C.stdio
#include <termios.h>

#include <stdint.h>

#include <spawn.h>

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
int VMPI_putenv(char *name)
{
    return putenv( name );
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

int VMPI_setenv(const char *name, const char *value, int overwrite)
{
    return setenv( name, value, overwrite );
}

int VMPI_system(const char *command)
{
    return system( command );
}

int VMPI_unsetenv(const char *name)
{
    return unsetenv( name );
}
// ---- C.stdlib ---- END


// ---- C.string ---- 

// ---- C.string ---- END


// ---- C.time ---- 

// ---- C.time ---- END




// ==== POSIX ==== 

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


// ---- C.sys.socket ---- 

// ---- C.sys.socket ---- END


// ---- C.sys.stat ---- 
int VMPI_chmod(const char *path, int mode)
{
    return chmod(path, (mode_t)mode);
}

int VMPI_mkdir(const char *path, int mode)
{
    return mkdir(path, (mode_t)mode);
}
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
void VMPI_sleep(int milliseconds)
{
    usleep(1000 * milliseconds);
}
// ---- C.unistd ---- END


// ---- C.utime ---- 

// ---- C.utime ---- END




// ==== RNL ==== 

// ---- shell.HardwareInformation ---- 
double VMPI_SystemMemorySize()
{
    double result_size = 0;

    /*#if defined(CTL_HW) && defined(HW_MEMSIZE)
    printf( "---> use CTL_HW\n" );
    int mib[2];
    mib[0] = CTL_HW;
    mib[1] = HW_MEMSIZE;
    

    int64_t size = 0;
    size_t len = sizeof( size );
    if( sysctl( mib, 2, &size, &len, NULL, 0 ) == 0 )
    {
        printf( "---> sysctl()\n" );
        //return (size_t)size;
        result_size = (size_t)size;
    }*/
    
    /*if( (result_size == 0) && (sysctlbyname("hw.memsize", &size, &len, NULL, 0) == 0) )
    {
        printf( "---> sysctlbyname()\n" );
        result_size = (size_t)size;
    }*/
    /*#elif defined(_SC_PHYS_PAGES) && defined(_SC_PAGESIZE)
        printf( "---> _SC_PAGESIZE\n" );
        result_size = (size_t)sysconf( _SC_PHYS_PAGES ) * (size_t)sysconf( _SC_PAGESIZE );
    #endif*/

    #if AVMSYSTEM_MAC
        /*int64_t size = 0;
        size_t len = sizeof( size );

        if( sysctlbyname("hw.memsize", &size, &len, NULL, 0) == 0 )
        {
            printf( "---> sysctlbyname()\n" );
            result_size = (size_t)size;
        }*/

        int mib[2];
        int64_t physical_memory;
        size_t length;

        // Get the Physical memory size
        mib[0] = CTL_HW;
        mib[1] = HW_MEMSIZE;
        length = sizeof(int64_t);
        if( sysctl(mib, 2, &physical_memory, &length, NULL, 0) == 0 )
        {
            //printf( "---> sysctl()\n" );
            //printf( "physical_memory = %" PRId64 "\n", physical_memory );
            result_size = (double)physical_memory;
        }

        /*printf( "misc stuff\n" );
        printf( "---> sysctlbyname()\n" );
        uint64_t mem;
        size_t len = sizeof(mem);
        sysctlbyname("hw.memsize", &mem, &len, NULL, 0);
        printf( "mem = %" PRIu64 "\n", mem );*/
    #endif


    return result_size;
}

double VMPI_SystemMemoryUse()
{
    double result_peak = 0;

    #if AVMSYSTEM_MAC
        struct mach_task_basic_info info;
        mach_msg_type_number_t infoCount = MACH_TASK_BASIC_INFO_COUNT;

        if ( task_info( mach_task_self( ), MACH_TASK_BASIC_INFO, (task_info_t)&info, &infoCount ) == KERN_SUCCESS )
        {
            result_peak = (double)info.resident_size;
        }
    #endif

    return result_peak;
}

double VMPI_SystemMemoryPeak()
{
    double result_used = 0;

        struct rusage rusage;
        getrusage( RUSAGE_SELF, &rusage );
    #if AVMSYSTEM_MAC
        result_used = (double)rusage.ru_maxrss;
    #elif AVMSYSTEM_UNIX
        result_used = (double)(rusage.ru_maxrss * 1024);
    #endif

    return result_used;
}
// ---- shell.HardwareInformation ---- END

// ---- shell.OperatingSystem ---- 

// ---- shell.OperatingSystem ---- END



// ==== AVMGLUE ==== 



// ==== MISC ==== 

char *VMPI_int2char(int n)
{
    char buffer[100];
    char *value;
    size_t size;

    size  = VMPI_sprintf( buffer, "%d", n ) * sizeof(char);
    value = (char*) VMPI_alloc( size+1 );
    VMPI_strcpy( value, buffer );
    
    return value;
}

char *VMPI_getLocale()
{
    //get the Environment's default locale
    return setlocale( LC_ALL, "" );
}

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

void VMPI_con_stream_mode(int state)
{
    struct termios ttystate;
 
    //get the terminal state
    tcgetattr(STDIN_FILENO, &ttystate);
 
    if (state==NONBLOCKING_ENABLE)
    {
        //turn off canonical mode
        ttystate.c_lflag &= ~ICANON;
        //minimum of number input read.
        ttystate.c_cc[VMIN] = 1;
    }
    else if (state==NONBLOCKING_DISABLE)
    {
        //turn on canonical mode
        ttystate.c_lflag |= ICANON;
    }
    //set the terminal attributes.
    tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
}

void VMPI_con_trans_mode(int state)
{
    (void)state; //does nothing under POSIX
}

double VMPI_getStdinFileLength()
{
    int stdinHandle = fileno(stdin);
    struct stat stats;
    fstat(stdinHandle, &stats);
    return stats.st_size;
}

struct hostent *VMPI_gethostbyaddr(const char *addr)
{
    struct in_addr ipv4addr;
    
    inet_pton(AF_INET, addr, &ipv4addr);
    return gethostbyaddr(&ipv4addr, sizeof ipv4addr, AF_INET);
}

//OperatingSystem.getName()
void VMPI_getOperatingSystemName(char *name)
{
    utsname info;
    const char *osname;
    
    if( uname(&info) < 0 ) {
        osname = "";
    }
    else {
        osname = info.sysname;
    }
    
    VMPI_strcpy( name, osname );
}

//OperatingSystem.getNodeName()
void VMPI_getOperatingSystemNodeName(char *nodename)
{
    utsname info;
    const char *osnodename;
    
    if( uname(&info) < 0 ) {
        osnodename = "";
    }
    else {
        osnodename = info.nodename;
    }
    
    VMPI_strcpy( nodename, osnodename );
}

//OperatingSystem.getRelease()
void VMPI_getOperatingSystemRelease(char *release)
{
    utsname info;
    const char *osrelease;
    
    if( uname(&info) < 0 ) {
        osrelease = "";
    }
    else {
        osrelease = info.release;
    }
    
    VMPI_strcpy( release, osrelease );
}

//OperatingSystem.getVersion()
void VMPI_getOperatingSystemVersion(char *version)
{
    utsname info;
    const char *osversion;
    
    if( uname(&info) < 0 ) {
        osversion = "";
    }
    else {
        osversion = info.version;
    }

    VMPI_strcpy( version, osversion );
}

//OperatingSystem.getMachine()
void VMPI_getOperatingSystemMachine(char *machine)
{
    utsname info;
    const char *osmachine;
    
    if( uname(&info) < 0 ) {
        osmachine = "";
    }
    else {
        osmachine = info.machine;
    }
    
    VMPI_strcpy( machine, osmachine );
}

//OperatingSystem.getVendorVersion()
void VMPI_getOperatingSystemVersionNumbers(int *major, int *minor, int *bugfix)
{
#ifdef AVMPLUS_MAC
    /* under OSX 10.8 ‘Gestalt’ is deprecated and there is no replacement
       see:
       http://stackoverflow.com/questions/11072804/mac-os-x-10-8-replacement-for-gestalt-for-testing-os-version-at-runtime

       instead use:

       on the command line
       $ sysctl kern.osrelease
       kern.osrelease: 12.0.0
       $ sysctl kern.osversion
       kern.osversion: 12A269

       in code
       #include <errno.h>
       #include <sys/sysctl.h>
       
       char str[256];
       size_t size = sizeof(str);
       int ret = sysctlbyname("kern.osrelease", str, &size, NULL, 0);

       results can be:
       12.x.x  OS X 10.8.x Mountain Lion
       11.x.x  OS X 10.7.x Lion
       10.x.x  OS X 10.6.x Snow Leopard
       9.x.x  OS X 10.5.x Leopard
       8.x.x  OS X 10.4.x Tiger
       7.x.x  OS X 10.3.x Panther
       6.x.x  OS X 10.2.x Jaguar
       5.x    OS X 10.1.x Puma
    */ 
    /*
    SInt32 version, version_major, version_minor, version_bugfix;
    if( Gestalt(gestaltSystemVersion, &version) == noErr )
    {
        if( version >= 0x00001040 )
        {
            Gestalt(gestaltSystemVersionMajor, &version_major);
            Gestalt(gestaltSystemVersionMinor, &version_minor);
            Gestalt(gestaltSystemVersionBugFix, &version_bugfix);
        }
        else
        {
            version_bugfix = version & 0xf;
            version >>= 4;
            version_minor = version & 0xf;
            version >>= 4;
            version_major = version - (version >> 4) * 6;
        }
        
        *major  = (int)version_major;
        *minor  = (int)version_minor;
        *bugfix = (int)version_bugfix;
    }
    */

    //tmp fix
    *major  = 0;
    *minor  = 0;
    *bugfix = 0;
#else
    (void)major;
    (void)minor;
    (void)bugfix;
#endif
}

int VMPI_getLogicalDrives()
{
    return 0;
}

int VMPI_getFileMode(const char *path)
{
    struct stat stats;
    stat(path, &stats);
    return stats.st_mode;
}

double VMPI_getFileSize(const char *path)
{
    struct stat stats;
    stat(path, &stats);
    return stats.st_size;
}

double VMPI_getFileLastModifiedTime(const char *path)
{
    struct stat stats;
    stat(path, &stats);
    return double( stats.st_mtime ) * 1000.0;
    //return double( stats.st_atime ) * 1000.0;
    //return double( stats.st_ctime ) * 1000.0;
}

bool VMPI_isRegularFile(const char *path)
{
    return S_ISREG( VMPI_getFileMode(path) );
}

bool VMPI_isDirectory(const char *path)
{
    return S_ISDIR( VMPI_getFileMode(path) );
}

//bool VMPI_isSymbolicLink(const char *path)

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

double VMPI_getFreeDiskSpace(const char *path)
{
    struct statvfs stats;
    if( statvfs(path, &stats) != 0) {
        return -1;
    }
    return static_cast<double>(stats.f_bavail) * stats.f_frsize;
}

double VMPI_getTotalDiskSpace(const char *path)
{
    struct statvfs stats;
    if( statvfs(path, &stats) != 0) {
        return -1;
    }
    return static_cast<double>(stats.f_blocks) * stats.f_frsize;
}



