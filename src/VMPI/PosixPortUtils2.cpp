/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* ***** BEGIN LICENSE BLOCK *****
* Version: MPL 1.1/GPL 2.0/LGPL 2.1
*
* The contents of this file are subject to the Mozilla Public License Version
* 1.1 (the "License"); you may not use this file except in compliance with
* the License. You may obtain a copy of the License at
* http://www.mozilla.org/MPL/
*
* Software distributed under the License is distributed on an "AS IS" basis,
* WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
* for the specific language governing rights and limitations under the
* License.
*
* The Original Code is [Open Source Virtual Machine.].
*
* The Initial Developer of the Original Code is
* Adobe System Incorporated.
* Portions created by the Initial Developer are Copyright (C) 2004-2006
* the Initial Developer. All Rights Reserved.
*
* Contributor(s):
*   Zwetan Kjukov <zwetan@gmail.com>.
*
* Alternatively, the contents of this file may be used under the terms of
* either the GNU General Public License Version 2 or later (the "GPL"), or
* the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
* in which case the provisions of the GPL or the LGPL are applicable instead
* of those above. If you wish to allow use of your version of this file only
* under the terms of either the GPL or the LGPL, and not to allow others to
* use your version of this file under the terms of the MPL, indicate your
* decision by deleting the provisions above and replace them with the notice
* and other provisions required by the GPL or the LGPL. If you do not delete
* the provisions above, a recipient may use your version of this file under
* the terms of any one of the MPL, the GPL or the LGPL.
*
* ***** END LICENSE BLOCK ***** */

#ifdef AVMPLUS_MAC
    #include <malloc/malloc.h>
    #include <CoreServices/CoreServices.h>
#endif //AVMPLUS_MAC

//for termios, ttystate, tcgetattr, ICANON, WMIN, TCSANOW, tcsetattr in C.stdio
#include <termios.h>

// ---- utilities ----

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

// ---- utilities ---- END


// ---- C.stdlib ---- 

int VMPI_setenv(const char *name, const char *value, int overwrite)
{
    return setenv(name, value, overwrite);
}

int VMPI_unsetenv(const char *name)
{
    return unsetenv(name);
}

char *VMPI_realpath(char const *path)
{
    //char resolved[PATH_MAX];
    //return realpath(path, resolved);

    char* full = NULL;
    char* result = NULL;

    result = realpath(path, full);
    
    //printf( "realpath path = %s\n", path );
    //printf( "realpath full = %s\n", full );
    //printf( "realpath result = %s\n", result );
    
    if( result != NULL ) {
        return result;
    }
    
    return NULL;
}

// ---- C.stdlib ---- END


// ---- C.unistd ---- 

int VMPI_chmod(const char *path, int mode)
{
    return chmod(path, (mode_t)mode);
}

int VMPI_mkdir(const char *path)
{
    //S_IRWXU = Read, write, execute/search by owner.
    //S_IRWXG = Read, write, execute/search by group.
    //S_IRWXO = Read, write, execute/search by others.
    return mkdir(path, S_IRWXU | S_IRWXG | S_IRWXO);
}

void VMPI_sleep(int milliseconds)
{
    usleep(1000 * milliseconds);
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

// ---- C.unistd ---- END

// ---- C.stdio ---- 

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

// ---- C.stdio ---- END

// ---- C.socket ---- 

struct hostent *VMPI_gethostbyaddr(const char *addr)
{
    struct in_addr ipv4addr;
    
    inet_pton(AF_INET, addr, &ipv4addr);
    return gethostbyaddr(&ipv4addr, sizeof ipv4addr, AF_INET);
}

// ---- C.socket ---- END


// ---- avmplus.System ---- 

double VMPI_getStdinFileLength()
{
    int stdinHandle = fileno(stdin);
    struct stat stats;
    fstat(stdinHandle, &stats);
    return stats.st_size;
}

// ---- avmplus.System ---- END


// ---- avmplus.OperatingSystem ---- 

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

// ---- avmplus.OperatingSystem ---- 


// ---- avmplus.FileSystem ---- 

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

// ---- avmplus.FileSystem ---- END



