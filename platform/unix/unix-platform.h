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

#ifndef __avmplus_unix_platform__
#define __avmplus_unix_platform__

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

#define VMPI_sprintf        ::sprintf
#define VMPI_snprintf       ::snprintf
#define VMPI_vsnprintf      ::vsnprintf
#define VMPI_sscanf         ::sscanf

#define VMPI_atoi   ::atoi
#define VMPI_tolower ::tolower
#define VMPI_islower ::islower
#define VMPI_toupper ::toupper
#define VMPI_isupper ::isupper
#define VMPI_isdigit ::isdigit
#define VMPI_isalnum ::isalnum
#define VMPI_isxdigit ::isxdigit
#define VMPI_isspace ::isspace
#define VMPI_isgraph ::isgraph
#define VMPI_isprint ::isprint
#define VMPI_ispunct ::ispunct
#define VMPI_iscntrl ::iscntrl
#define VMPI_isalpha ::isalpha
#define VMPI_abort   ::abort
#define VMPI_exit    ::exit

// Note: the linux #define provided by the compiler.

// Set up a jmp_buf suitable for VMPI_longjmpNoUnwind.
#ifdef linux
// Use the routine version with an underscore to avoid system calls
// to query the signal mask.
#define VMPI_setjmpNoUnwind ::_setjmp
#else
// Don't assume _setjmp is available
#define VMPI_setjmpNoUnwind ::setjmp
#endif

// Jump to an active jmp_buf that was set up by VMPI_setjmpNoUnwind.
// Under no circumstances may C++ destructors be unwound during the
// jump (MSVC likes to do this by default).
#ifdef linux
// Use the routine version with an underscore to avoid system calls
// to query the signal mask.
#define VMPI_longjmpNoUnwind ::_longjmp
#else
// Don't assume _longjmp is avialable
#define VMPI_longjmpNoUnwind ::longjmp
#endif

#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <setjmp.h>
#include <inttypes.h>

// Note, this used to be #ifndef SYMBIAN, but Symbian code belongs in the Symbian platform file.
// Do *NOT* unfix this.
#include <stdint.h>

#include <sys/mman.h>
#include <sys/time.h>
#include <errno.h>
#include <stdlib.h>

#include <unistd.h>
#include <pthread.h>
#include <signal.h>

typedef pthread_t vmpi_thread_t;

#ifdef ANDROID
#define USE_CUTILS_ATOMICS FALSE
#if USE_CUTILS_ATOMICS
#include <cutils/atomic.h>
#else
#include <sys/atomics.h>
#endif
#endif

#ifdef SOLARIS
 #include <alloca.h>
 #include <atomic.h>
typedef caddr_t maddr_ptr;
#else
typedef void *maddr_ptr;
#endif

#include <new>

#ifdef SOLARIS
// "NP" = non-portable.  Origin of code unclear, may be old.  Consider removing it,
// it's not used by current Solaris builds.
#ifdef HAVE_PTHREAD_NP_H
#include <pthread_np.h>
#define pthread_getattr_np pthread_attr_get_np
#endif
#endif // SOLARIS

#ifdef __GNUC__
#define REALLY_INLINE inline __attribute__((always_inline))
// only define FASTCALL for x86-32; other gcc versions will spew warnings
#ifdef AVMPLUS_IA32
    #define FASTCALL __attribute__((fastcall))
#endif
#endif

// inline __attribute__((always_inline)) is supposed to work for SunStudio.
// Currently SunStudio C++ compiler has a bug which can not parse keyword
// inline and __attribute__((always_inline)) together. It will be added back
// when this bug got fixed.
#if defined __SUNPRO_C || defined __SUNPRO_CC
#define REALLY_INLINE inline __hidden
#define FASTCALL
#endif

#if defined(__GNUC__)
    #define AVMPLUS_ALIGN8(type) type __attribute__ ((aligned (8)))
    #define AVMPLUS_ALIGN16(type) type __attribute__ ((aligned (16)))
#elif defined(__SUNPRO_C) || defined(__SUNPRO_CC)
    #define AVMPLUS_ALIGN8(type) type __attribute__ ((aligned (8)))
    #define AVMPLUS_ALIGN16(type) type __attribute__ ((aligned (16)))
#else
    #error "Unrecognized compiler"
#endif

/**
* Type defintion for an opaque data type representing platform-defined spin lock
* @see VMPI_lockInit(), VMPI_lockAcquire()
*/
#if defined(__GNUC__) && (defined(AVMPLUS_IA32) || defined(AVMPLUS_AMD64))

struct vmpi_spin_lock_t
{
    volatile uint32_t lock;
};


REALLY_INLINE uint32_t X86_TestAndSet(volatile uint32_t* ptr, uint32_t val) {
    __asm__ volatile("xchgl %0, (%2)" :"=r"(val) : "0"(val), "r"(ptr));
    return val;
}

REALLY_INLINE void X86_Pause()
{
    __asm__ volatile("pause");
}

REALLY_INLINE void VMPI_lockInit(vmpi_spin_lock_t* lock)
{
    lock->lock = 0;
    __asm__ volatile("" : : : "memory");
}

REALLY_INLINE void VMPI_lockDestroy(vmpi_spin_lock_t* lock)
{
    lock->lock = 0;
    __asm__ volatile("" : : : "memory");
}

REALLY_INLINE bool VMPI_lockAcquire(vmpi_spin_lock_t *lock)
{
    while ( X86_TestAndSet(&lock->lock, 1) != 0 ) {
        X86_Pause();
    }
    __asm__ volatile("" : : : "memory");
    return true;
}

REALLY_INLINE bool VMPI_lockRelease(vmpi_spin_lock_t *lock)
{
    __asm__ volatile("" : : : "memory");
    lock->lock = 0;
    return true;
}

REALLY_INLINE bool VMPI_lockTestAndAcquire(vmpi_spin_lock_t *lock)
{
    __asm__ volatile("" : : : "memory");
    if(X86_TestAndSet(&lock->lock, 1) != 0)
        return false;
    return true;
}

#elif defined(USE_PTHREAD_MUTEX)

struct vmpi_spin_lock_t
{
    // Some small systems (eg android) don't provide spinlock.
    // using pthread_mutex for now (unfortunate since it's usually more expensive)
    volatile pthread_mutex_t lock;
};

REALLY_INLINE void VMPI_lockInit(vmpi_spin_lock_t* lock)
{
    pthread_mutex_init((pthread_mutex_t*)&lock->lock, 0);
}

REALLY_INLINE void VMPI_lockDestroy(vmpi_spin_lock_t *lock)
{
    pthread_mutex_destroy((pthread_mutex_t*)&lock->lock);
}

REALLY_INLINE bool VMPI_lockAcquire(vmpi_spin_lock_t *lock)
{
    return pthread_mutex_lock((pthread_mutex_t*)&lock->lock) == 0;
}

REALLY_INLINE bool VMPI_lockRelease(vmpi_spin_lock_t *lock)
{
    return pthread_mutex_unlock((pthread_mutex_t*)&lock->lock) == 0;
}

REALLY_INLINE bool VMPI_lockTestAndAcquire(vmpi_spin_lock_t *lock)
{
    return pthread_mutex_trylock((pthread_mutex_t*)&lock->lock) == 0;
}

#else

struct vmpi_spin_lock_t
{
    volatile pthread_spinlock_t lock;
};

REALLY_INLINE void VMPI_lockInit(vmpi_spin_lock_t* lock)
{
    pthread_spin_init((pthread_spinlock_t*)&lock->lock, 0);
}

REALLY_INLINE void VMPI_lockDestroy(vmpi_spin_lock_t *lock)
{
    pthread_spin_destroy((pthread_spinlock_t*)&lock->lock);
}

REALLY_INLINE bool VMPI_lockAcquire(vmpi_spin_lock_t *lock)
{
    return pthread_spin_lock((pthread_spinlock_t*)&lock->lock) == 0;
}

REALLY_INLINE bool VMPI_lockRelease(vmpi_spin_lock_t *lock)
{
    return pthread_spin_unlock((pthread_spinlock_t*)&lock->lock) == 0;
}

REALLY_INLINE bool VMPI_lockTestAndAcquire(vmpi_spin_lock_t *lock)
{
    return pthread_spin_trylock((pthread_spinlock_t*)&lock->lock) == 0;
}

#endif

#ifdef ANDROID
// Nov' 2010.
// There is some confusion as to which atomics API
// to use for Android. (See bug 609809).
// The sys/atomics.h implementation, as of Nov' 2010,
// apparently does not include memory barriers, so it is
// not suitable for multi-core. The cutils/atomic.h
// implementation is dynamically linked and will feature
// barriers when necessary, but its current implementation is
// anecdotally the same as sys/atomics.h.
//
// For now, the sys/atomics.h implementation is used as it is
// already being used in the player.
//
// Note that on single-core devices, memory barriers are
// no-ops on all architectures that we support, so the
// VMPI_memoryBarrier() and VMPI_*WithBarrier functions
// fulfill their documented API.
//
// Linking with sys/atomics.h causes linker warnings such as:
// "warning: type and size of dynamic symbol `__atomic_inc'
// are not defined". These also occur in player builds and are
// currently ignored.
#if USE_CUTILS_ATOMICS

REALLY_INLINE int32_t VMPI_atomicIncAndGet32WithBarrier(volatile int32_t* value)
{
    return android_atomic_inc(value) - 1;
}

REALLY_INLINE int32_t VMPI_atomicIncAndGet32(volatile int32_t* value)
{
    return VMPI_atomicIncAndGet32WithBarrier(value);
}

REALLY_INLINE int32_t VMPI_atomicDecAndGet32WithBarrier(volatile int32_t* value)
{
    return android_atomic_dec(value) + 1;
}

REALLY_INLINE int32_t VMPI_atomicDecAndGet32(volatile int32_t* value)
{
    return VMPI_atomicDecAndGet32WithBarrier(value);
}

REALLY_INLINE bool VMPI_compareAndSwap32WithBarrier(int32_t oldValue, int32_t newValue, volatile int32_t* address)
{
    return android_atomic_cmpxchg(oldValue, newValue, address) == 0;
}

REALLY_INLINE bool VMPI_compareAndSwap32(int32_t oldValue, int32_t newValue, volatile int32_t* address)
{
    return VMPI_compareAndSwap32WithBarrier(oldValue, newValue, address);
}

REALLY_INLINE void VMPI_memoryBarrier()
{
    // No memory barrier native API
    volatile int32_t dummy;
    VMPI_compareAndSwap32WithBarrier(0, 1, &dummy);
}

#else // USE_CUTILS_ATOMICS

REALLY_INLINE int32_t VMPI_atomicIncAndGet32WithBarrier(volatile int32_t* value)
{
    return __atomic_inc((volatile int*)value) - 1;
}

REALLY_INLINE int32_t VMPI_atomicIncAndGet32(volatile int32_t* value)
{
    return VMPI_atomicIncAndGet32WithBarrier(value);
}

REALLY_INLINE int32_t VMPI_atomicDecAndGet32WithBarrier(volatile int32_t* value)
{
    return __atomic_dec((volatile int*)value) - 1;
}

REALLY_INLINE int32_t VMPI_atomicDecAndGet32(volatile int32_t* value)
{
    return VMPI_atomicDecAndGet32WithBarrier(value);
}

REALLY_INLINE bool VMPI_compareAndSwap32WithBarrier(int32_t oldValue, int32_t newValue, volatile int32_t* address)
{
    return __atomic_cmpxchg((int)oldValue, (int)newValue, (volatile int*)address) == 0;
}

REALLY_INLINE bool VMPI_compareAndSwap32(int32_t oldValue, int32_t newValue, volatile int32_t* address)
{
    return VMPI_compareAndSwap32WithBarrier(oldValue, newValue, address);
}

REALLY_INLINE void VMPI_memoryBarrier()
{
    // No memory barrier native API
    volatile int32_t dummy;
    VMPI_compareAndSwap32WithBarrier(0, 1, &dummy);
}

#endif // USE_CUTILS_ATOMICS

#elif defined(AVMSYSTEM_ARM)
//FIXME: bug 609810 VMPI atomic primitives for ARM require inline-asm implementations
#define EMULATE_ATOMICS_WITH_PTHREAD_MUTEX

#else

#if !defined(SOLARIS)
    #if defined(__GNUC__) && defined(__GNUC_MINOR__) && (__GNUC__ >= 4)
        #if (__GNUC_MINOR__ >= 1) // _GLIBCXX_ATOMIC_BUILTINS_4 was added after the intrinsic was available
            #define HAS_RELIABLE_GCC_ATOMICS
        #endif
        #if (__GNUC_MINOR__ >= 4) || ((__GNUC_MINOR__ >= 1) && !defined(AVMPLUS_AMD64))
            #define HAS_RELIABLE_GCC_MEMBAR
        #endif
    #endif
#endif

REALLY_INLINE int32_t VMPI_atomicIncAndGet32WithBarrier(volatile int32_t* value)
{
#if defined(SOLARIS)
    int32_t result = atomic_inc_32_nv((volatile uint32_t*)value);
    membar_producer();
    membar_consumer();
    return result;
#elif defined(__GNUC__)
    #if defined(AVMPLUS_IA32) || defined(AVMPLUS_AMD64)
        #if defined(HAS_RELIABLE_GCC_ATOMICS)
            return __sync_add_and_fetch(value, 1); // This requires -march=i486 or better
        #else
            register int32_t result;
            __asm__ __volatile__("lock; xaddl %0, %1" : "=r" (result), "=m" (*value) : "0" (1), "m" (*value) : "memory");
            return result + 1;
        #endif
    #else
        #error "Unsupported arch for GCC/Unix"
    #endif
#else
    #error "Unsupported compiler/Unix variant"
#endif
    return 0; // pedantic GCC
}

REALLY_INLINE int32_t VMPI_atomicIncAndGet32(volatile int32_t* value)
{
#if defined(SOLARIS)
    return atomic_inc_32_nv((volatile uint32_t*)value);
#else
    // No barrier-less version implemented
    return VMPI_atomicIncAndGet32WithBarrier(value);
#endif
}

REALLY_INLINE int32_t VMPI_atomicDecAndGet32WithBarrier(volatile int32_t* value)
{
#if defined(SOLARIS)
    int32_t result = atomic_dec_32_nv((volatile uint32_t*)value);
    membar_producer();
    membar_consumer();
    return result;
#elif defined(__GNUC__)
    #if defined(AVMPLUS_IA32) || defined(AVMPLUS_AMD64)
        #if defined(HAS_RELIABLE_GCC_ATOMICS)
            return __sync_sub_and_fetch(value, 1); // This requires -march=i486 or better
        #else
            register int32_t result;
            __asm__ __volatile__("lock; xaddl %0, %1" : "=r" (result), "=m" (*value) : "0" (-1), "m" (*value) : "memory");
            return result - 1;
        #endif
    #else
        #error "Unsupported arch for GCC/Unix"
    #endif
#else
    #error "Unsupported compiler/Unix variant"
#endif
    return 0; // pedantic GCC
}

REALLY_INLINE int32_t VMPI_atomicDecAndGet32(volatile int32_t* value)
{
#if defined(SOLARIS)
    return atomic_dec_32_nv((volatile uint32_t*)value);
#else
    // No barrier-less version implemented
    return VMPI_atomicDecAndGet32WithBarrier(value);
#endif
}

REALLY_INLINE bool VMPI_compareAndSwap32WithBarrier(int32_t oldValue, int32_t newValue, volatile int32_t* address)
{
#if defined(SOLARIS)
    bool result = atomic_cas_32((volatile uint32_t*)address, (uint32_t)oldValue, (uint32_t)newValue) == (uint32_t)oldValue;
    membar_producer();
    membar_consumer();
    return result;
#elif defined(__GNUC__)
    #if defined(AVMPLUS_IA32) || defined(AVMPLUS_AMD64)
        #if defined(HAS_RELIABLE_GCC_ATOMICS)
            return __sync_bool_compare_and_swap(address, oldValue, newValue); // This requires -march=i486 or better
        #else
            int32_t currentValue;
            __asm__ __volatile__("lock cmpxchgl %4, %0" : "=m" (*address), "=a" (currentValue) : "m" (*address), "1" (oldValue), "r" (newValue) : "memory");
            return oldValue == currentValue;
        #endif
    #else
        #error "Unsupported arch for GCC/Unix"
    #endif
#else
    #error "Unsupported compiler/Unix variant"
#endif
    return 0; // pedantic GCC
}

REALLY_INLINE bool VMPI_compareAndSwap32(int32_t oldValue, int32_t newValue, volatile int32_t* address)
{
#if defined(SOLARIS)
    return atomic_cas_32((volatile uint32_t*)address, (uint32_t)oldValue, (uint32_t)newValue) == (uint32_t)oldValue;
#else
    // No barrier-less version implemented
    return VMPI_compareAndSwap32WithBarrier(oldValue, newValue, address);
#endif
}

REALLY_INLINE void VMPI_memoryBarrier()
{
#if defined(SOLARIS)
    membar_producer();
    membar_consumer();
#elif defined(__GNUC__)
    #if defined(HAS_RELIABLE_GCC_MEMBAR)
        __sync_synchronize();  // This requires -march=i486 or better
    #else
        volatile int32_t dummy;
        VMPI_atomicIncAndGet32WithBarrier(&dummy);
    #endif
#else
    #error "Unsupported compiler/Unix variant"
#endif
}
#endif

#include "../VMPI/ThreadsPosix-inlines.h"

#endif // __avmplus_unix_platform__
