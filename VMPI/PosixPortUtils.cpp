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
*   Adobe AS3 Team
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

#include "avmplus.h"

#include <stdlib.h>
#include <sys/time.h>
#include <sys/utsname.h>
#include <sys/statvfs.h>
#include <math.h>
#include <pwd.h>

#ifdef AVMPLUS_UNIX
    #include <time.h>
#endif // AVMPLUS_UNIX

#ifdef AVMPLUS_MAC
    #include <malloc/malloc.h>
    #include <CoreServices/CoreServices.h>
#endif //AVMPLUS_MAC

#include <sys/mman.h>

#define kMsecPerDay     86400000
#define kMsecPerHour    3600000
#define kMsecPerSecond  1000
#define kMsecPerMinute  60000

#define DIVCLOCK ( CLOCKS_PER_SEC / 1000 )

#define kMicroPerSec 1000000.0

double VMPI_getLocalTimeOffset()
{
    struct tm* t;
    time_t current, localSec, globalSec;

    // The win32 implementation ignores the passed in time
    // and uses current time instead, so to keep similar
    // behaviour we will do the same
    time( &current );

    t = localtime( &current );
    localSec = mktime( t );

    t = gmtime( &current );
    globalSec = mktime( t );

    return double( localSec - globalSec ) * 1000.0;
}

double VMPI_getDate()
{
    struct timeval tv;
    struct timezone tz; // Unused

    gettimeofday(&tv, &tz);
    double v = (tv.tv_sec + (tv.tv_usec/kMicroPerSec)) * kMsecPerSecond;
    double ip;
    ::modf(v, &ip); // strip fractional part
    return ip;
}

//time is passed in as milliseconds from UTC.
double VMPI_getDaylightSavingsTA(double newtime)
{
    struct tm *broken_down_time;

    //convert time from milliseconds
    newtime=newtime/kMsecPerSecond;

    time_t time_t_time=(time_t)newtime;

    //pull out a struct tm
    broken_down_time = localtime( &time_t_time );

    if (!broken_down_time)
    {
        return 0;
    }

    if (broken_down_time->tm_isdst > 0)
    {
        //daylight saving is definitely in effect.
        return kMsecPerHour;
    }

    //either daylight saving is not in effect, or we don't know (if tm_isdst is negative).
    return 0;
}


uint64_t VMPI_getTime()
{
    struct timeval tv;
    ::gettimeofday(&tv, NULL);
    uint64_t result = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
    return result;
}


void* VMPI_alloc(size_t size)
{
    return malloc(size);
}

void VMPI_free(void* ptr)
{
    free(ptr);
}

size_t VMPI_size(void *ptr)
{
#ifdef AVMPLUS_MAC
    return malloc_size(ptr);
#else
    (void)ptr;
    return 0;
#endif
}

typedef void (*LoggingFunction)(const char*);

LoggingFunction logFunc = NULL;

void RedirectLogOutput(LoggingFunction func)
{
    logFunc = func;
}

void VMPI_log(const char* message)
{
    if(logFunc)
        logFunc(message);
    else
        printf("%s",message);
}

bool VMPI_isMemoryProfilingEnabled()
{
    //read the mmgc profiling option switch
    const char *env = getenv("MMGC_PROFILE");
    return (env && (VMPI_strncmp(env, "1", 1) == 0));
}

// Constraint: nbytes must be a multiple of the VM page size.
//
// The returned memory will be aligned on a VM page boundary and cover
// an integral number of VM pages.  This is necessary in order for
// VMPI_makeCodeMemoryExecutable to work properly - it too operates
// on entire VM pages.
//
// This function is duplicated in the Windows port utils, if you
// fix a bug here be sure to fix the bug there.

void *VMPI_allocateCodeMemory(size_t nbytes)
{
    MMgc::GCHeap* heap = MMgc::GCHeap::GetGCHeap();
    size_t pagesize = VMPI_getVMPageSize();

    if (nbytes % pagesize != 0) {
#ifdef DEBUG
        char buf[256];
        VMPI_snprintf(buf,
                      sizeof(buf),
                      "VMPI_allocateCodeMemory invariants violated: request=%lu pagesize=%lu\nAborting.\n",
                      (unsigned long)nbytes,
                      (unsigned long)pagesize);
        VMPI_log(buf);
#endif
        VMPI_abort();
    }

    size_t nblocks = nbytes / MMgc::GCHeap::kBlockSize;

    heap->SignalCodeMemoryAllocation(nblocks, true);
    return heap->Alloc(nblocks, MMgc::GCHeap::flags_Alloc, pagesize/MMgc::GCHeap::kBlockSize);
}

// Constraint: address must have been returned from VMPI_allocateCodeMemory
// and nbytes must be the size of the allocation.  We can't quite check
// this, so we check that the address points to a page boundary and that
// the size is given as an integral number of VM pages and that the size
// corresponds to GCHeap's notion of the size.
//
// Usage note: on Posix, where the memory goes back into the common pool
// and isn't unmapped by the OS, it is very bad form for the client to
// free executable memory, we do not try to detect that (in DEBUG mode)
// but we probably should.
//
// This function is duplicated in the Windows port utils, if you
// fix a bug here be sure to fix the bug there.

void VMPI_freeCodeMemory(void* address, size_t nbytes)
{
    MMgc::GCHeap* heap = MMgc::GCHeap::GetGCHeap();
    size_t pagesize = VMPI_getVMPageSize();
    size_t nblocks = heap->Size(address);
    size_t actualBytes = nblocks * MMgc::GCHeap::kBlockSize;

    if ((uintptr_t)address % pagesize != 0 || nbytes % pagesize != 0 || nbytes != actualBytes) {
#ifdef DEBUG
        char buf[256];
        VMPI_snprintf(buf,
                      sizeof(buf),
                      "VMPI_freeCodeMemory invariants violated: address=%lu provided=%lu actual=%lu\nAborting.\n",
                      (unsigned long)address,
                      (unsigned long)nbytes,
                      (unsigned long)actualBytes);
        VMPI_log(buf);
#endif
        VMPI_abort();
    }

    heap->Free(address);
    heap->SignalCodeMemoryDeallocated(nblocks, true);
}

// Constraint: address must point into a block returned from VMPI_allocateCodeMemory
// that has not been freed, it must point to a VM page boundary, and the number of
// bytes to protect must be an integral number of VM pages.  We can't check that
// the memory was returned from VMPI_allocateCodeMemory though and we don't check
// that the memory is currently allocated.
//
// GCHeap may return memory that overlaps the boundary between two separately
// committed regions.  If that causes problems for you there are two options: either
// don't use GCHeap memory for code memory, or turn off VM support.

void VMPI_makeCodeMemoryExecutable(void *address, size_t nbytes, bool makeItSo)
{
    size_t pagesize = VMPI_getVMPageSize();

    if ((uintptr_t)address % pagesize != 0 || nbytes % pagesize != 0) {
#ifdef DEBUG
        char buf[256];
        VMPI_snprintf(buf,
                      sizeof(buf),
                      "VMPI_makeCodeMemoryExecutable invariants violated: address=%lu size=%lu pagesize=%lu\nAborting.\n",
                      (unsigned long)address,
                      (unsigned long)nbytes,
                      (unsigned long)pagesize);
        VMPI_log(buf);
#endif
        VMPI_abort();
    }

    int flags = makeItSo ? PROT_EXEC|PROT_READ : PROT_WRITE|PROT_READ;
    int retval = mprotect((maddr_ptr)address, (unsigned int)nbytes, flags);
    AvmAssert(retval == 0);
    (void)retval;
}

const char *VMPI_getenv(const char *name)
{
    return getenv(name);
}

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
    char resolved[PATH_MAX];
    return realpath(path, resolved);
}

void VMPI_getExecutablePath(const char *argv0, char *name)
{
    //char* realpath(const char*, char*)
    realpath(argv0,name);
}

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

int VMPI_getFileMode(const char *path)
{
    struct stat stats;
    stat(path, &stats);
    return stats.st_mode;
}

bool VMPI_isRegularFile(const char *path)
{
    return S_ISREG( VMPI_getFileMode(path) );
    /*
    bool test = false;
    struct stat stats;
    if (!stat(path, &stats)) {
        if (S_ISREG(stats.st_mode)) {
            test = true;
        }
    }
    return test;
    */
}

bool VMPI_isDirectory(const char *path)
{
    return S_ISDIR( VMPI_getFileMode(path) );
    /*
    bool test = false;
    struct stat stats;
    if (!stat(path, &stats)) {
        if (S_ISDIR(stats.st_mode)) {
            test = true;
        }
    }
    return test;
    */
}

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

void VMPI_getOperatingSystemVersionNumbers(int *major, int *minor, int *bugfix)
{
#ifdef AVMPLUS_MAC
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
#else
    (void)major;
    (void)minor;
    (void)bugfix;
#endif
}

int WMPI_SocketStart(int major, int minor)
{
    (void)major;
    (void)minor;
    //no need to initialize socket for POSIX
    return 0;
}

void WMPI_SocketStop()
{
    //do nothing
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

struct hostent *VMPI_gethostbyaddr(const char *addr)
{
    struct in_addr ipv4addr;
    
    inet_pton(AF_INET, addr, &ipv4addr);
    return gethostbyaddr(&ipv4addr, sizeof ipv4addr, AF_INET);
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

void VMPI_sleep(int milliseconds)
{
    usleep(1000 * milliseconds);
}

bool VMPI_isNullTerminated(const char *str)
{
    int len = VMPI_strlen(str);

    if( str[len]-1 == '\0') {
        return true;
    }

    return  false;
}

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




// Helper functions for VMPI_callWithRegistersSaved, kept in this file to prevent them from
// being inlined in MMgcPortUnix.cpp / MMgcPortMac.cpp.

// Registers have been flushed; compute a stack pointer and call the user function.
void CallWithRegistersSaved2(void (*fn)(void* stackPointer, void* arg), void* arg, void* buf)
{
    (void)buf;
    volatile int temp = 0;
    fn((void*)((uintptr_t)&temp & ~7), arg);
}

// Do nothing - just called to prevent another call from being a tail call, and to keep some values alive
void CallWithRegistersSaved3(void (*fn)(void* stackPointer, void* arg), void* arg, void* buf)
{
    (void)buf;
    (void)fn;
    (void)arg;
}

// Note: the linux #define provided by the compiler.

uint32_t querySignalMask() {
#if (defined(AVMPLUS_MAC) || defined(linux)) && defined(DEBUG)
    // will save just the 32 signals to avoid exposing sigset_t in ExceptionFrame
    sigset_t set;
    uint32_t mask = 0;
    if (sigprocmask(0, NULL, &set) == -1) {
        VMPI_debugLog("signal mask query failed\n");
        VMPI_debugBreak();
    }

    for (int i = 0; i< 32; i++) {
        if (sigismember(&set, i))
            mask |= (1 << i);
    }
    return mask;
#else
    // will use the setjmp/longjmp calls that do save and restore
    // signal masks, so no need to verify that the signal mask
    // hasn't changed.
    return 0;
#endif
}

void assertSignalMask(uint32_t expected) {
#if (defined(AVMPLUS_MAC) || defined(linux)) && defined(DEBUG)
    sigset_t current_mask;
    sigemptyset(&current_mask);

    if (sigprocmask(0, NULL, &current_mask) == -1)  {
        VMPI_debugLog("signal mask query failed\n");
        VMPI_debugBreak();
    } else {
        for (int i = 0; i< 32; i++) {
            bool result = sigismember(&current_mask, i);
            if (result != (bool)(expected  & (1 << i))) {
                VMPI_debugLog("masks not equal\n");
                VMPI_debugBreak();
            }
        }
    }
#else // do nothing
    (void)expected;
    // will use the setjmp/longjmp calls that do save and restore
    // signal masks, so no need to verify that the signal mask
    // hasn't changed.

#endif
}




