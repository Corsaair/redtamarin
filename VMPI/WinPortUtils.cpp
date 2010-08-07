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
* Utility function that convert Windows errror to errno
* from: UNIXem: UNIX Emulation Library for Win32
*       http://synesis.com.au/software/unixem.html
*/
int errno_from_Win32(unsigned long w32Err)
{
    struct errmap_t
    {
        unsigned long   w32Err;
        int             eerrno;
    };

    static const struct errmap_t    errmap[] = 
    {
        /*   1 */       {   ERROR_INVALID_FUNCTION          ,   EINVAL          }
        /*   2 */   ,   {   ERROR_FILE_NOT_FOUND            ,   ENOENT          }
        /*   3 */   ,   {   ERROR_PATH_NOT_FOUND            ,   ENOENT          }
        /*   4 */   ,   {   ERROR_TOO_MANY_OPEN_FILES       ,   EMFILE          }
        /*   5 */   ,   {   ERROR_ACCESS_DENIED             ,   EACCES          }
        /*   6 */   ,   {   ERROR_INVALID_HANDLE            ,   EBADF           }
        /*   7 */   ,   {   ERROR_ARENA_TRASHED             ,   ENOMEM          }
        /*   8 */   ,   {   ERROR_NOT_ENOUGH_MEMORY         ,   ENOMEM          }
        /*   9 */   ,   {   ERROR_INVALID_BLOCK             ,   ENOMEM          }
        /*  10 */   ,   {   ERROR_BAD_ENVIRONMENT           ,   E2BIG           }
        /*  11 */   ,   {   ERROR_BAD_FORMAT                ,   ENOEXEC         }
        /*  12 */   ,   {   ERROR_INVALID_ACCESS            ,   EINVAL          }
        /*  13 */   ,   {   ERROR_INVALID_DATA              ,   EINVAL          }
        /*  14 */   ,   {   ERROR_OUTOFMEMORY               ,   ENOMEM          }
        /*  15 */   ,   {   ERROR_INVALID_DRIVE             ,   ENOENT          }
        /*  16 */   ,   {   ERROR_CURRENT_DIRECTORY         ,   ECURDIR         }
        /*  17 */   ,   {   ERROR_NOT_SAME_DEVICE           ,   EXDEV           }
        /*  18 */   ,   {   ERROR_NO_MORE_FILES             ,   ENOENT          }
        /*  19 */   ,   {   ERROR_WRITE_PROTECT             ,   EROFS           }
        /*  20 */   ,   {   ERROR_BAD_UNIT                  ,   ENXIO           }
        /*  21 */   ,   {   ERROR_NOT_READY                 ,   EBUSY           }
        /*  22 */   ,   {   ERROR_BAD_COMMAND               ,   EIO             }
        /*  23 */   ,   {   ERROR_CRC                       ,   EIO             }
        /*  24 */   ,   {   ERROR_BAD_LENGTH                ,   EIO             }
        /*  25 */   ,   {   ERROR_SEEK                      ,   EIO             }
        /*  26 */   ,   {   ERROR_NOT_DOS_DISK              ,   EIO             }
        /*  27 */   ,   {   ERROR_SECTOR_NOT_FOUND          ,   ENXIO           }
        /*  28 */   ,   {   ERROR_OUT_OF_PAPER              ,   EBUSY           }
        /*  29 */   ,   {   ERROR_WRITE_FAULT               ,   EIO             }
        /*  30 */   ,   {   ERROR_READ_FAULT                ,   EIO             }
        /*  31 */   ,   {   ERROR_GEN_FAILURE               ,   EIO             }
        /*  32 */   ,   {   ERROR_SHARING_VIOLATION         ,   EAGAIN          }
        /*  33 */   ,   {   ERROR_LOCK_VIOLATION            ,   EACCES          }
        /*  34 */   ,   {   ERROR_WRONG_DISK                ,   ENXIO           }
        /*  35 */   ,   {   35                              ,   ENFILE          }
        /*  36 */   ,   {   ERROR_SHARING_BUFFER_EXCEEDED   ,   ENFILE          }
        /*  37 */   ,   {   ERROR_HANDLE_EOF                ,   EINVAL          }
        /*  38 */   ,   {   ERROR_HANDLE_DISK_FULL          ,   ENOSPC          }
        /*  39 */   ,   {   0                               ,   0               }
        /*  40 */   ,   {   0                               ,   0               }
        /*  41 */   ,   {   0                               ,   0               }
        /*  42 */   ,   {   0                               ,   0               }
        /*  43 */   ,   {   0                               ,   0               }
        /*  44 */   ,   {   0                               ,   0               }
        /*  45 */   ,   {   0                               ,   0               }
        /*  46 */   ,   {   0                               ,   0               }
        /*  47 */   ,   {   0                               ,   0               }
        /*  48 */   ,   {   0                               ,   0               }
        /*  49 */   ,   {   0                               ,   0               }
        /*  50 */   ,   {   ERROR_NOT_SUPPORTED             ,   ENOSYS          }
        /*  51 */   ,   {   0                               ,   0               }
        /*  52 */   ,   {   0                               ,   0               }
        /*  53 */   ,   {   ERROR_BAD_NETPATH               ,   ENOENT          }
        /*  54 */   ,   {   0                               ,   0               }
        /*  55 */   ,   {   0                               ,   0               }
        /*  56 */   ,   {   0                               ,   0               }
        /*  57 */   ,   {   0                               ,   0               }
        /*  58 */   ,   {   0                               ,   0               }
        /*  59 */   ,   {   0                               ,   0               }
        /*  60 */   ,   {   0                               ,   0               }
        /*  61 */   ,   {   0                               ,   0               }
        /*  62 */   ,   {   0                               ,   0               }
        /*  63 */   ,   {   0                               ,   0               }
        /*  64 */   ,   {   0                               ,   0               }
        /*  65 */   ,   {   ERROR_NETWORK_ACCESS_DENIED     ,   EACCES          }
        /*  66 */   ,   {   0                               ,   0               }
        /*  67 */   ,   {   ERROR_BAD_NET_NAME              ,   ENOENT          }
        /*  68 */   ,   {   0                               ,   0               }
        /*  69 */   ,   {   0                               ,   0               }
        /*  70 */   ,   {   0                               ,   0               }
        /*  71 */   ,   {   0                               ,   0               }
        /*  72 */   ,   {   0                               ,   0               }
        /*  73 */   ,   {   0                               ,   0               }
        /*  74 */   ,   {   0                               ,   0               }
        /*  75 */   ,   {   0                               ,   0               }
        /*  76 */   ,   {   0                               ,   0               }
        /*  77 */   ,   {   0                               ,   0               }
        /*  78 */   ,   {   0                               ,   0               }
        /*  79 */   ,   {   0                               ,   0               }
        /*  80 */   ,   {   ERROR_FILE_EXISTS               ,   EEXIST          }
        /*  81 */   ,   {   0                               ,   0               }
        /*  82 */   ,   {   ERROR_CANNOT_MAKE               ,   EACCES          }
        /*  83 */   ,   {   ERROR_FAIL_I24                  ,   EACCES          }
        /*  84 */   ,   {   0                               ,   0               }
        /*  85 */   ,   {   0                               ,   0               }
        /*  86 */   ,   {   0                               ,   0               }
        /*  87 */   ,   {   ERROR_INVALID_PARAMETER         ,   EINVAL          }
        /*  88 */   ,   {   0                               ,   0               }
        /*  89 */   ,   {   ERROR_NO_PROC_SLOTS             ,   EAGAIN          }
        /*  90 */   ,   {   0                               ,   0               }
        /*  91 */   ,   {   0                               ,   0               }
        /*  92 */   ,   {   0                               ,   0               }
        /*  93 */   ,   {   0                               ,   0               }
        /*  94 */   ,   {   0                               ,   0               }
        /*  95 */   ,   {   0                               ,   0               }
        /*  96 */   ,   {   0                               ,   0               }
        /*  97 */   ,   {   0                               ,   0               }
        /*  98 */   ,   {   0                               ,   0               }
        /*  99 */   ,   {   0                               ,   0               }
        /* 100 */   ,   {   0                               ,   0               }
        /* 101 */   ,   {   0                               ,   0               }
        /* 102 */   ,   {   0                               ,   0               }
        /* 103 */   ,   {   0                               ,   0               }
        /* 104 */   ,   {   0                               ,   0               }
        /* 105 */   ,   {   0                               ,   0               }
        /* 106 */   ,   {   0                               ,   0               }
        /* 107 */   ,   {   0                               ,   0               }
        /* 108 */   ,   {   ERROR_DRIVE_LOCKED              ,   EACCES          }
        /* 109 */   ,   {   ERROR_BROKEN_PIPE               ,   EPIPE           }
        /* 110 */   ,   {   0                               ,   0               }
        /* 111 */   ,   {   ERROR_BUFFER_OVERFLOW           ,   ENAMETOOLONG    }
        /* 112 */   ,   {   ERROR_DISK_FULL                 ,   ENOSPC          }
        /* 113 */   ,   {   0                               ,   0               }
        /* 114 */   ,   {   ERROR_INVALID_TARGET_HANDLE     ,   EBADF           }
        /* 115 */   ,   {   0                               ,   0               }
        /* 116 */   ,   {   0                               ,   0               }
        /* 117 */   ,   {   0                               ,   0               }
        /* 118 */   ,   {   0                               ,   0               }
        /* 119 */   ,   {   0                               ,   0               }
        /* 120 */   ,   {   0                               ,   0               }
        /* 121 */   ,   {   0                               ,   0               }
        /* 122 */   ,   {   0                               ,   0               }
        /* 123 */   ,   {   ERROR_INVALID_NAME              ,   ENOENT          }
        /* 124 */   ,   {   ERROR_INVALID_HANDLE            ,   EINVAL          }
        /* 125 */   ,   {   0                               ,   0               }
        /* 126 */   ,   {   0                               ,   0               }
        /* 127 */   ,   {   0                               ,   0               }
        /* 128 */   ,   {   ERROR_WAIT_NO_CHILDREN          ,   ECHILD          }
        /* 129 */   ,   {   ERROR_CHILD_NOT_COMPLETE        ,   ECHILD          }
        /* 130 */   ,   {   ERROR_DIRECT_ACCESS_HANDLE      ,   EBADF           }
        /* 131 */   ,   {   ERROR_NEGATIVE_SEEK             ,   EINVAL          }
        /* 132 */   ,   {   ERROR_SEEK_ON_DEVICE            ,   EACCES          }
        /* 133 */   ,   {   0                               ,   0               }
        /* 134 */   ,   {   0                               ,   0               }
        /* 135 */   ,   {   0                               ,   0               }
        /* 136 */   ,   {   0                               ,   0               }
        /* 137 */   ,   {   0                               ,   0               }
        /* 138 */   ,   {   0                               ,   0               }
        /* 139 */   ,   {   0                               ,   0               }
        /* 140 */   ,   {   0                               ,   0               }
        /* 141 */   ,   {   0                               ,   0               }
        /* 142 */   ,   {   0                               ,   0               }
        /* 143 */   ,   {   0                               ,   0               }
        /* 144 */   ,   {   0                               ,   0               }
        /* 145 */   ,   {   ERROR_DIR_NOT_EMPTY             ,   ENOTEMPTY       }
        /* 146 */   ,   {   0                               ,   0               }
        /* 147 */   ,   {   0                               ,   0               }
        /* 148 */   ,   {   0                               ,   0               }
        /* 149 */   ,   {   0                               ,   0               }
        /* 150 */   ,   {   0                               ,   0               }
        /* 151 */   ,   {   0                               ,   0               }
        /* 152 */   ,   {   0                               ,   0               }
        /* 153 */   ,   {   0                               ,   0               }
        /* 154 */   ,   {   0                               ,   0               }
        /* 155 */   ,   {   0                               ,   0               }
        /* 156 */   ,   {   0                               ,   0               }
        /* 157 */   ,   {   0                               ,   0               }
        /* 158 */   ,   {   ERROR_NOT_LOCKED                ,   EACCES          }
        /* 159 */   ,   {   0                               ,   0               }
        /* 160 */   ,   {   0                               ,   0               }
        /* 161 */   ,   {   ERROR_BAD_PATHNAME              ,   ENOENT          }
        /* 162 */   ,   {   0                               ,   0               }
        /* 163 */   ,   {   0                               ,   0               }
        /* 164 */   ,   {   ERROR_MAX_THRDS_REACHED         ,   EAGAIN          }
        /* 165 */   ,   {   0                               ,   0               }
        /* 166 */   ,   {   0                               ,   0               }
        /* 167 */   ,   {   ERROR_LOCK_FAILED               ,   EACCES          }
        /* 168 */   ,   {   0                               ,   0               }
        /* 169 */   ,   {   0                               ,   0               }
        /* 170 */   ,   {   0                               ,   0               }
        /* 171 */   ,   {   0                               ,   0               }
        /* 172 */   ,   {   0                               ,   0               }
        /* 173 */   ,   {   0                               ,   0               }
        /* 174 */   ,   {   0                               ,   0               }
        /* 175 */   ,   {   0                               ,   0               }
        /* 176 */   ,   {   0                               ,   0               }
        /* 177 */   ,   {   0                               ,   0               }
        /* 178 */   ,   {   0                               ,   0               }
        /* 179 */   ,   {   0                               ,   0               }
        /* 180 */   ,   {   0                               ,   0               }
        /* 181 */   ,   {   0                               ,   0               }
        /* 182 */   ,   {   0                               ,   0               }
        /* 183 */   ,   {   ERROR_ALREADY_EXISTS            ,   EEXIST          }
        /* 184 */   ,   {   0                               ,   0               }
        /* 185 */   ,   {   0                               ,   0               }
        /* 186 */   ,   {   0                               ,   0               }
        /* 187 */   ,   {   0                               ,   0               }
        /* 188 */   ,   {   0                               ,   0               }
        /* 189 */   ,   {   0                               ,   0               }
        /* 190 */   ,   {   0                               ,   0               }
        /* 191 */   ,   {   0                               ,   0               }
        /* 192 */   ,   {   0                               ,   0               }
        /* 193 */   ,   {   0                               ,   0               }
        /* 194 */   ,   {   0                               ,   0               }
        /* 195 */   ,   {   0                               ,   0               }
        /* 196 */   ,   {   0                               ,   0               }
        /* 197 */   ,   {   0                               ,   0               }
        /* 198 */   ,   {   0                               ,   0               }
        /* 199 */   ,   {   0                               ,   0               }

        /* 206 */   ,   {   ERROR_FILENAME_EXCED_RANGE      ,   ENAMETOOLONG    }

        /* 215 */   ,   {   ERROR_NESTING_NOT_ALLOWED       ,   EAGAIN          }

        /* 267 */   ,   {   ERROR_DIRECTORY                 ,   ENOTDIR         }

        /* 997 */   ,   {   ERROR_IO_PENDING                ,   EBUSY           }

        /* 1816 */  ,   {   ERROR_NOT_ENOUGH_QUOTA          ,   ENOMEM          }
    };

    size_t  i;

    for(i = 0; i < NUM_ELEMENTS(errmap); ++i)
    {
        if(w32Err == errmap[i].w32Err)
        {
            return errmap[i].eerrno;
        }
    }

    //assert(!"Unrecognised value");

    return EINVAL;
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

static int setenv_with_putenv(const char *name, const char *value)
{
    if(NULL != strchr(name, '='))
    {
        errno = EINVAL;
        return -1;
    }
    else
    {
        size_t  nameLen     =   strlen(name);
        size_t  valueLen    =   strlen(value);
        size_t  required    =   1 + nameLen + 1 + valueLen;
        char    buffer_[101];
        char    *buffer     =   (NUM_ELEMENTS(buffer_) < required)
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
            (void)strncpy(&buffer[0], name, nameLen);
            buffer[nameLen] = '=';
            buffer[nameLen + 1] = '\0';
            (void)strncpy(&buffer[nameLen + 1], value, valueLen);
            buffer[nameLen + 1 + valueLen] = '\0';

            r = _putenv(&buffer[0]);

            if(buffer != &buffer_[0])
            {
                free(buffer);
            }

            return r;
        }
    }
}

int VMPI_setenv(const char *name, const char *value, int overwrite)
{
    if(!overwrite)
    {
        VMPI_log("getenv = [");
        VMPI_log(VMPI_getenv(name));
        VMPI_log("]\n");
        if(NULL != VMPI_getenv(name))
        {
            return 0;
        }
    }

    return setenv_with_putenv(name, value);
}

int VMPI_unsetenv(const char *name)
{
    return setenv_with_putenv(name, "");
}

void VMPI_getExecutablePath(const char *argv0, char *name)
{
    (void)argv0;
    char actualpath[256];
    GetModuleFileName(NULL, actualpath, sizeof(actualpath));
    VMPI_strcpy( name, actualpath );
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
