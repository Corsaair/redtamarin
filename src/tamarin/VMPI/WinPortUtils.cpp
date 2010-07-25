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
* Portions created by the Initial Developer are Copyright (C) 1993-2006
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

#include <Mmsystem.h>

namespace avmplus
{
    int WeekDay(double t);
    double MakeDate(double day, double time);
    double MakeDay(double year, double month, double date);
    double MakeTime(double hour, double min, double sec, double ms);
    int YearFromTime(double t);
}

/*
* Windows implementation of platform-dependent date and time code
*/
static const double kMsecPerDay       = 86400000;
static const double kMsecPerHour      = 3600000;
static const double kMsecPerSecond    = 1000;
static const double kMsecPerMinute    = 60000;

static TIME_ZONE_INFORMATION UpdateTimeZoneInfo()
{
    static vmpi_spin_lock_t gTimeZoneInfoLock;      // protects gTimeZoneInfo and gGmtCache
    static TIME_ZONE_INFORMATION gTimeZoneInfo;
    static SYSTEMTIME gGmtCache;

    SYSTEMTIME gmt;
    GetSystemTime(&gmt);
    MMGC_LOCK(gTimeZoneInfoLock);
    if ((gmt.wMinute != gGmtCache.wMinute) ||
        (gmt.wHour != gGmtCache.wHour) ||
        (gmt.wDay != gGmtCache.wDay) ||
        (gmt.wMonth != gGmtCache.wMonth) ||
        (gmt.wYear != gGmtCache.wYear)
        )
    {
        // Cache is invalid.
        GetTimeZoneInformation(&gTimeZoneInfo);
        gGmtCache = gmt;
    }
    TIME_ZONE_INFORMATION tz = gTimeZoneInfo;
    return tz;
}

double VMPI_getLocalTimeOffset()
{
    TIME_ZONE_INFORMATION tz = UpdateTimeZoneInfo();
    return -tz.Bias * 60.0 * 1000.0;
}

static double ConvertWin32DST(int year, SYSTEMTIME *st)
{
    // The StandardDate and DaylightDate members of
    // TIMEZONE_INFORMATION may be specified in two ways:
    // 1. An absolute time and date
    // 2. A month, day of week and week in month, and a time of day

    if (st->wYear != 0) {
        return avmplus::MakeDate(avmplus::MakeDay(year,
            st->wMonth - 1,
            st->wDay),
            avmplus::MakeTime(st->wHour,
            st->wMinute,
            st->wSecond,
            st->wMilliseconds));
    }

    double timeValue = avmplus::MakeDate(avmplus::MakeDay(year,
        st->wMonth-1,
        1),
        avmplus::MakeTime(st->wHour,
        st->wMinute,
        st->wSecond,
        st->wMilliseconds));

    double nextMonth;
    if (st->wMonth < 12) {
        nextMonth = avmplus::MakeDate(avmplus::MakeDay(year, st->wMonth, 1), 0);
    } else {
        nextMonth = avmplus::MakeDate(avmplus::MakeDay(year + 1, 0, 1), 0);
    }

    int dayOfWeek = avmplus::WeekDay(timeValue);
    if (dayOfWeek != st->wDayOfWeek) {
        int dayDelta = st->wDayOfWeek - dayOfWeek;
        if (dayDelta < 0) {
            dayDelta += 7;
        }
        timeValue += (double)kMsecPerDay * dayDelta;
    }

    // Advance appropriate # of weeks
    timeValue += (double)kMsecPerDay * 7.0 * (st->wDay - 1);

    // Cap it at the end of the month
    while (timeValue >= nextMonth) {
        timeValue -= (double)kMsecPerDay * 7.0;
    }

    return timeValue;
}

double VMPI_getDaylightSavingsTA(double time)
{
    // On Windows, ask the OS what the daylight saving time bias
    // is.  If it's zero, perform no adjustment.
    TIME_ZONE_INFORMATION tz = UpdateTimeZoneInfo();
    if (tz.DaylightBias != -60 || tz.DaylightDate.wMonth == 0) {
        return 0;
    }

    // In most of the US, Daylight Saving Time begins on the
    // first Sunday of April at 2 AM.  It ends at 2 am on
    // the last Sunday of October.

    // 1. Compute year this time represents.
    int year = avmplus::YearFromTime(time);

    // 2. Compute time that daylight saving time begins
    double timeD = ConvertWin32DST(year, &tz.DaylightDate);

    // 3. Compute time that standard time begins
    double timeS = ConvertWin32DST(year, &tz.StandardDate);

    // Subtract the daylight bias from the standard transition time
    timeS -= kMsecPerHour;

    // The times we have calculated are in local time,
    // but "time" was passed in as UTC.  Convert it to local time.
    time += VMPI_getLocalTimeOffset();

    // Does time fall in the daylight saving period?

    // Where Daylight savings time is earlier in the year than standard time
    if(timeS > timeD)
    {
        if (time >= timeD && time < timeS)
            return kMsecPerHour;
        else
            return 0;
    }
    // Where Daylight savings time is later in the year than standard time
    else
    {
        if (time >= timeS && time < timeD)
            return 0;
        else
            return kMsecPerHour;
    }

}

#define FILETIME_EPOCH_BIAS ((LONGLONG)116444736000000000)
#define FILETIME_MS_FACTOR (10000.0)

static double NormalizeFileTime(FILETIME* ft)
{
    LARGE_INTEGER li;
    li.LowPart = ft->dwLowDateTime;
    li.HighPart = ft->dwHighDateTime;

    return ((double) (li.QuadPart - FILETIME_EPOCH_BIAS)) / FILETIME_MS_FACTOR;
}

static double NormalizeSystemTime(SYSTEMTIME* st)
{
    FILETIME ft;
    SystemTimeToFileTime(st, &ft);
    return NormalizeFileTime(&ft);
}

double VMPI_getDate()
{
    SYSTEMTIME stime;
    GetSystemTime(&stime);
    return NormalizeSystemTime(&stime);
}

uint64_t VMPI_getTime()
{
    return timeGetTime();
}

// On Windows, _vsnprintf isn't reliable (no NUL termination) and _vsnprintf_s
// is not compatible (throws an exception if the format is wrong).  Easy
// enough to create our own on top of _vsnprintf by adding the terminator
// and adjusting the return value.
//
// ANSI C requires vsnprintf to return the number of characters that would have
// been printed had the buffer been unrestricted.  The MSVC _vsnprintf does not
// do that.  Instead, return the number of characters written not including
// the NUL in all cases.

int VMPI_vsnprintf(char *s, size_t n, const char *format, va_list args)
{
    int ret = _vsnprintf(s, n, format, args);
    if (ret == -1)
        ret = int(n);
    if (ret == int(n)) {
        s[n-1] = 0;
        ret--;
    }
    return ret;
}

// On Windows, _snprintf isn't reliable (no NUL termination) and _snpritnf_s
// is not compatible (throws an exception if the format is wrong).  Easy
// enough to create our own on top of VMPI_vsnprintf.
//
// Return what VMPI_vsnprintf returns; see notes above.

int VMPI_snprintf(char *s, size_t n, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    int ret = VMPI_vsnprintf(s, n, format, args);
    va_end(format);
    return ret;
}

void* VMPI_alloc(size_t size)
{
    return HeapAlloc(GetProcessHeap(), 0, size);
}

void VMPI_free(void* ptr)
{
    HeapFree(GetProcessHeap(), 0, ptr);
}

size_t VMPI_size(void* ptr)
{
    return HeapSize(GetProcessHeap(), 0, ptr);
}

typedef void (*LoggingFunction)(const char*);

LoggingFunction logFunc = NULL;

void RedirectLogOutput(LoggingFunction func)
{
    logFunc = func;
}

void VMPI_log(const char* message)
{
#ifndef UNDER_CE
    ::OutputDebugStringA(message);
#endif

    if(logFunc)
        logFunc(message);
    else {
        printf("%s",message);
        fflush(stdout);
    }
}

bool VMPI_isMemoryProfilingEnabled()
{
#if defined (UNDER_CE) && defined(MMGC_MEMORY_PROFILER)
    return true;
#else
    //read the mmgc profiling option switch
    const char *env = VMPI_getenv("MMGC_PROFILE");
    return (env && (VMPI_strncmp(env, "1", 1) == 0));
#endif
}

// Constraint: nbytes must be a multiple of the VM page size.
//
// The returned memory will be aligned on a VM page boundary and cover
// an integral number of VM pages.  This is necessary in order for
// VMPI_makeCodeMemoryExecutable to work properly - it too operates
// on entire VM pages.
//
// This function should be the same as for generic Posix platforms, if you
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
// This function should be the same as for generic Posix platforms, if you
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

    DWORD oldProtectFlags = 0;
    DWORD newProtectFlags = 0;
    if ( makeItSo )
        newProtectFlags = PAGE_EXECUTE_READWRITE;
    else
        newProtectFlags = PAGE_READWRITE;

    BOOL retval;
    do {
        MEMORY_BASIC_INFORMATION mbi;
        VirtualQuery(address, &mbi, sizeof(MEMORY_BASIC_INFORMATION));
        size_t markSize = nbytes > mbi.RegionSize ? mbi.RegionSize : nbytes;  // handle multiple adjoining regions

        retval = VirtualProtect(address, markSize, newProtectFlags, &oldProtectFlags);
        AvmAssert(retval != 0);

        address = (char*) address + markSize;
        nbytes -= markSize;
    } while(nbytes != 0 && retval != 0);
}

const char *VMPI_getenv(const char *env)
{
    const char *val = NULL;
    (void)env;
#ifndef UNDER_CE
    val = getenv(env);
#endif
    return val;
}


// Helper functions for VMPI_callWithRegistersSaved, kept in this file to prevent them from
// being inlined in MMgcPortWin.cpp.

void CallWithRegistersSaved2(void (*fn)(void* stackPointer, void* arg), void* arg, void* buf)
{
    (void)buf;
    volatile int temp = 0;
    fn((void*)((uintptr_t)&temp & ~7), arg);
}

void CallWithRegistersSaved3(void (*fn)(void* stackPointer, void* arg), void* arg, void* buf)
{
    (void)buf;
    (void)fn;
    (void)arg;
}
