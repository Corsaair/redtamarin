/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* -*- tab-width: 4 -*- */
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

#ifndef __avmplus_win32_platform__
#define __avmplus_win32_platform__

#include <stdarg.h>

/**
 * We have avmplus.vcproj compiled with the /W4 warning level
 * which is quite picky.  Disable warnings we don't care about.
 */
#ifdef _MSC_VER
    #pragma warning(disable:4127) // conditional expression is constant - appears to be compiler noise primarily
    #pragma warning(disable:4201) // nonstandard extension used : nameless struct/union
    #pragma warning(disable:4251) // X needs to have dll-interface to be used by clients of class Y
    #pragma warning(disable:4310) // cast truncates constant value
    #pragma warning(disable:4511) // can't generate copy ctor
    #pragma warning(disable:4512) // assignment operator could not be generated
    #pragma warning(disable:4611) // interaction between '_setjmp' and C++ object destruction is non-portable
    #pragma warning(disable:4725) // instruction may be inaccurate on some Pentiums

    // enable some that are off even in /W4 mode, but are still handy
    #pragma warning(default:4242)   // 'identifier' : conversion from 'type1' to 'type2', possible loss of data
    #pragma warning(default:4263)   // 'function' : member function does not override any base class virtual member function
    #pragma warning(default:4264)   // 'virtual_function' : no override available for virtual member function from base 'class'; function is hidden
    #pragma warning(default:4265)   // 'class' : class has virtual functions, but destructor is not virtual
    #pragma warning(default:4266)   // 'function' : no override available for virtual member function from base 'type'; function is hidden
    #pragma warning(default:4296)   // expression is always true (false) (Generally, an unsigned variable was used in a comparison operation with zero.)
    #pragma warning(default:4905)   // wide string literal cast to 'LPSTR'
    #pragma warning(default:4906)   // string literal cast to 'LPWSTR'

    // some that might be useful to turn on someday, but would require too much twiddly code tweaking right now
    //  #pragma warning(error:4820) // 'bytes' bytes padding added after construct 'member_name' (MSFT system headers generate zillions of these, sadly)

/**
 * Disable PREfast analysis warnings that complain about legitimate usage.
 */
#ifdef _PREFAST_
    // These are triggered by the use of named constants for configuration purposes.
    // There is nothing wrong with using these in preference to preprocessor conditionalization.
    #pragma warning(disable:6237)   // (<zero> && <expression>) is always zero
    #pragma warning(disable:6239)   // (<non-zero constant> && <expression>) always evaluates to the result of <expression>

    // This needs to be fixed, but reflects our generally cavalier treatment of stack overflow
    #pragma warning(disable:6255)   // _alloca indicates failure by raising a stack overflow exception
#endif
#endif // _MSC_VER

#define VMPI_memcpy         ::memcpy
#define VMPI_memset         ::memset
#define VMPI_memcmp         ::memcmp
#define VMPI_memmove        ::memmove
#define VMPI_memchr         ::memchr
#define VMPI_strcmp         ::strcmp
#define VMPI_strcat         ::strcat
#define VMPI_strchr         ::strchr
#define VMPI_strrchr        ::strrchr
#define VMPI_strcpy         ::strcpy
#define VMPI_strlen         ::strlen
#define VMPI_strncat        ::strncat
#define VMPI_strncmp        ::strncmp
#define VMPI_strncpy        ::strncpy
#define VMPI_strtol         ::strtol
#define VMPI_strstr         ::strstr
#define VMPI_strerror       ::strerror

#define VMPI_sprintf        ::sprintf
#define VMPI_sscanf         ::sscanf

// Print rest args into s according to format.  The size of s is n.  A NUL
// terminator is always written.  Returns the number of characters written,
// not including the NUL.  (Hence the return value is always 0..n-1.)

int VMPI_snprintf(char *s, size_t n, const char *format, ...);

// As for VMPI_snprintf but with an argument list instead of rest args.

int VMPI_vsnprintf(char *s, size_t n, const char *format, va_list args);

#define VMPI_atoi           ::atoi
// these aren't prefixed b/c off winmo/pcre problems with ? : expressions
#define VMPI_tolower        tolower
#define VMPI_islower        islower
#define VMPI_toupper        toupper
#define VMPI_isupper        isupper
#define VMPI_isdigit        isdigit
#define VMPI_isalnum        isalnum
#define VMPI_isxdigit       isxdigit
#define VMPI_isspace        isspace
#define VMPI_isgraph        isgraph
#define VMPI_isprint        isprint
#define VMPI_ispunct        ispunct
#define VMPI_iscntrl        iscntrl
#define VMPI_isalpha        isalpha
#ifdef UNDER_CE
    #define VMPI_abort() ::TerminateProcess(GetCurrentProcess(), 0)
#else
    #define VMPI_abort   ::abort
#endif

#define VMPI_exit           ::exit

#define VMPI_access    _access
#define VMPI_getcwd    _getcwd
#define VMPI_rmdir     _rmdir

#define VMPI_remove    ::remove
#define VMPI_rename    ::rename


#include <stddef.h>
#include <memory.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

#include <ctype.h>
#include <limits.h>

#include <sys/stat.h>

#include <direct.h>
#include <io.h>
#include <windows.h>
#include <malloc.h>

//a lot of definitions to align with POSIX
#if !defined(ECURDIR)
  #define ECURDIR          EACCES
#endif /* !ECURDIR */
#if !defined(ENOSYS)
  #define ENOSYS           EPERM
#endif /* !ENOSYS */

#if !defined(FILENAME_MAX)
  #define FILENAME_MAX    _MAX_FNAME
#endif /* !FILENAME_MAX */
#if !defined(PATH_MAX)
  #define PATH_MAX        _MAX_PATH
#endif /* !PATH_MAX */

#if !defined(S_IFMT)
  #define S_IFMT    _S_IFMT    /* 0xF000 file type mask */
#endif
#if !defined(S_IFDIR)
  #define S_IFDIR   _S_IFDIR   /* 0x4000 directory */
#endif
#if !defined(S_IFCHR)
  #define S_IFCHR   _S_IFCHR   /* 0x2000 character special */
#endif
#if !defined(S_IFIFO)
  #define S_IFIFO   _S_IFIFO   /* 0x1000 pipe */
#endif
#if !defined(S_IFREG)
  #define S_IFREG   _S_IFREG   /* 0x8000 regular */
#endif
#if !defined(S_IREAD)
  #define S_IREAD   _S_IREAD   /* 0x0100 read permission, owner */
#endif
#if !defined(S_IWRITE)
  #define S_IWRITE  _S_IWRITE   /* 0x0080 write permission, owner */
#endif
#if !defined(S_IEXEC)
  #define S_IEXEC   _S_IEXEC   /* 0x0040 execute/search permission, owner */
#endif

//not used under WIN32, added for AS3 API
#if !defined(S_IFBLK)
  #define S_IFBLK   0060000   /* [XSI] block special */
#endif
#if !defined(S_IFLNK)
  #define S_IFLNK   0120000   /* [XSI] symbolic link */
#endif
#if !defined(S_IFSOCK)
  #define S_IFSOCK  0140000   /* [XSI] socket */
#endif

#if !defined(F_OK)
  #define F_OK        0
#endif /* !F_OK */
#if !defined(X_OK)
  #define X_OK        1
#endif /* !X_OK */
#if !defined(W_OK)
  #define W_OK        2
#endif /* !W_OK */
#if !defined(R_OK)
  #define R_OK        4
#endif /* !R_OK */

#ifndef DT_UNKNOWN
  #define DT_UNKNOWN      0
#endif /* !DT_UNKNOWN */
#ifndef DT_FIFO
  #define DT_FIFO         1
#endif /* !DT_FIFO */
#ifndef DT_CHR
  #define DT_CHR          2
#endif /* !DT_CHR */
#ifndef DT_DIR
  #define DT_DIR          4
#endif /* !DT_DIR */
#ifndef DT_BLK
  #define DT_BLK          6
#endif /* !DT_BLK */
#ifndef DT_REG
  #define DT_REG          8
#endif /* !DT_REG */
#ifndef DT_LNK
  #define DT_LNK          10
#endif /* !DT_LNK */
#ifndef DT_SOCK
  #define DT_SOCK         12
#endif /* !DT_SOCK */
#ifndef DT_WHT
  #define DT_WHT          14
#endif /* !DT_WHT */

/** \def NUM_ELEMENTS(ar)
 *
 * Evaluates the size of an array.
 *
 * \param ar The array.
 *
 * \warning This produces unintended behaviour if used with a pointer, and
 *  undefined behaviour if used, in C++, with a user-defined type that
 *  defines a subscript operator. See Chapter 14 of <em>Imperfect C++</em>
 *  (http://www.imperfectcplusplus.com/)
 */

#ifndef NUM_ELEMENTS
  #define NUM_ELEMENTS(ar)      (sizeof(ar) / sizeof(0[ar]))
#endif /* !NUM_ELEMENTS */

#ifndef FILE_ATTRIBUTE_ERROR
  #define FILE_ATTRIBUTE_ERROR           (0xFFFFFFFF)
#endif /* FILE_ATTRIBUTE_ERROR */

#ifndef S_ISDIR
  #define S_ISDIR(mode)  (((mode) & S_IFMT) == S_IFDIR)
#endif

#ifndef S_ISREG
  #define S_ISREG(mode)  (((mode) & S_IFMT) == S_IFREG)
#endif

typedef int mode_t;

//as WIN32 does not have GRP and OTH rights, we map them to the USR rights
static const mode_t S_IRUSR      = mode_t(S_IREAD);      // read by user
static const mode_t S_IWUSR      = mode_t(S_IWRITE);     // write by user
static const mode_t S_IXUSR      = 0;                    // does nothing
static const mode_t S_IRGRP      = mode_t(S_IREAD);      // read by *USER*
static const mode_t S_IWGRP      = mode_t(S_IWRITE);     // write by *USER*
static const mode_t S_IXGRP      = 0;                    // does nothing
static const mode_t S_IROTH      = mode_t(S_IREAD);      // read by *USER*
static const mode_t S_IWOTH      = mode_t(S_IWRITE);     // write by *USER*
static const mode_t S_IXOTH      = 0;                    // does nothing

static const mode_t S_IRWXU      = S_IRUSR | S_IWUSR | S_IXUSR;
static const mode_t S_IRWXG      = S_IRGRP | S_IWGRP | S_IXGRP;
static const mode_t S_IRWXO      = S_IROTH | S_IWOTH | S_IXOTH;

// this is a big sortcut to be able to use dirent directly in a native class
typedef struct dirent
{
    char *d_name;
    int d_type;
} dirent;

typedef struct DIR
{
    long                handle; /* -1 for failed rewind */
    struct _finddata_t  info;
    struct dirent       result; /* d_name null if first time */
    char                *name;  /* null-terminated char string */
} DIR;


extern DIR           *opendir(const char *name);
extern int           closedir(DIR *dir);
extern struct dirent *readdir(DIR *dir);
extern void          rewinddir(DIR *dir);

#if defined(UNDER_CE)
// winmo complains if we try to include <new> and it complains if someone else includes new before us so...
#ifndef __PLACEMENT_NEW_INLINE
#define __PLACEMENT_NEW_INLINE
inline void* operator new(size_t, void* p) { return p; }
#endif
#else
// others want the system new
#include <new>
#endif

#ifdef _ARM_
    // Windows Mobile doesn't provide intptr_t or uintptr_t
    typedef __int32             intptr_t;
    typedef unsigned __int32    uintptr_t;
#endif

typedef void *maddr_ptr;

// Set up a jmp_buf suitable for VMPI_longjmpNoUnwind.
//#define VMPI_setjmpNoUnwind ::setjmp

// Jump to an active jmp_buf that was set up by VMPI_setjmpNoUnwind.
// Under no circumstances may C++ destructors be unwound during the
// jump (MSVC likes to do this by default).
//#define VMPI_longjmpNoUnwind ::longjmp

#ifdef VMCFG_64BIT
    #include <setjmpex.h>
    extern "C"
    {
        _int64 __cdecl longjmp64(jmp_buf jmpbuf, _int64 arg);
    }
    #define VMPI_setjmpNoUnwind     ::setjmp
    #define VMPI_longjmpNoUnwind    ::longjmp64
#else
    #include <setjmp.h>
    #define VMPI_setjmpNoUnwind     ::setjmp
    #define VMPI_longjmpNoUnwind    ::longjmp
#endif

#ifndef UNDER_CE
  // Newer versions of the Windows SDK set up the intrinsics slightly differently
  // than VC8. Only include intrin.h if the SDK doesn't declare it.
  #ifndef InterlockedBitTestAndSet
    #include <intrin.h>
  #endif
  #include <emmintrin.h>

  #ifdef VTUNE
    #include "JITProfiling.h"
  #endif
#endif

// Windows doesn't support inttypes.h or most C99 types directly
typedef __int8              int8_t;
typedef __int16             int16_t;
typedef __int32             int32_t;
typedef __int64             int64_t;
typedef unsigned __int8     uint8_t;
typedef unsigned __int16    uint16_t;
typedef unsigned __int32    uint32_t;
typedef unsigned __int64    uint64_t;

// This must come after all the include files
#if defined _MSC_VER && !defined DEBUG
    #pragma intrinsic(memcmp)
    #pragma intrinsic(memcpy)
    #pragma intrinsic(memset)
    #pragma intrinsic(strlen)
    #pragma intrinsic(strcpy)
    #pragma intrinsic(strcat)
#endif

#if _MSC_VER
    #define REALLY_INLINE __forceinline
    #define FASTCALL __fastcall
#elif __GNUC__
    #define FASTCALL __attribute__((fastcall))
#else
    #define FASTCALL
#endif

#if defined(_MSC_VER)
    #define AVMPLUS_ALIGN8(type) __declspec(align(8)) type
    #define AVMPLUS_ALIGN16(type) __declspec(align(16)) type
#elif defined(__GNUC__)
    #define AVMPLUS_ALIGN8(type) type __attribute__ ((aligned (8)))
    #define AVMPLUS_ALIGN16(type) type __attribute__ ((aligned (16)))
#else
    #error "Unrecognized compiler"
#endif

#if defined(_MSC_VER) && _MSC_VER < 1400 && defined(FEATURE_NANOJIT)
    #define NJ_NO_VARIADIC_MACROS
#endif

/**
* Type defintion for an opaque data type representing platform-defined spin lock
* @see VMPI_lockInit(), VMPI_lockAcquire()
*/
struct vmpi_spin_lock_t
{
    volatile LONG lock;
};

REALLY_INLINE void VMPI_lockInit(vmpi_spin_lock_t* lock)
{
    lock->lock = 0;
}

REALLY_INLINE void VMPI_lockDestroy(vmpi_spin_lock_t* lock)
{
    lock->lock = 0;
}

REALLY_INLINE bool VMPI_lockAcquire(vmpi_spin_lock_t *lock)
{
    int tries = 0;
    while (::InterlockedCompareExchange((LPLONG)&lock->lock, 1, 0) != 0)
    {
        ++tries;
        // We used to reset to zero if we got to 100. This resets to 0 at 64 instead, with no branch.
        tries &= 63;
        // if tries == 0, we just rolled over 64, so we Sleep(1) to give other threads a chance to run... otherwise we Sleep(0)
        ::Sleep(tries == 0);
    }
    return true;
}

REALLY_INLINE bool VMPI_lockRelease(vmpi_spin_lock_t *lock)
{
    ::InterlockedExchange((LPLONG)&lock->lock, 0);
    return true;
}

REALLY_INLINE bool VMPI_lockTestAndAcquire(vmpi_spin_lock_t *lock)
{
    return ::InterlockedCompareExchange((LPLONG)&lock->lock, 1, 0) == 0;
}

#endif // __avmplus_win32_platform__

