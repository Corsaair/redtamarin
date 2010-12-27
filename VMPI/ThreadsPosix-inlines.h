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
 * Portions created by the Initial Developer are Copyright (C) 2009
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

typedef pthread_mutex_t        vmpi_mutex_t;
typedef pthread_cond_t         vmpi_condvar_t;
typedef void*                  vmpi_thread_arg_t; // Argument type for thread start function
typedef void*                  vmpi_thread_rtn_t; // Return type for thread start function
typedef vmpi_thread_rtn_t (*vmpi_thread_start_t)(vmpi_thread_arg_t);
typedef pthread_attr_t         vmpi_thread_attr_t;

#define VMPI_THREAD_START_CC

REALLY_INLINE bool VMPI_recursiveMutexInit(vmpi_mutex_t* mutex)
{
    pthread_mutexattr_t attr;
    if (pthread_mutexattr_init(&attr) == 0) {
        if (pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE) == 0) {
            return pthread_mutex_init(mutex, &attr) == 0;
        }
    }
    return false;
}

REALLY_INLINE bool VMPI_recursiveMutexDestroy(vmpi_mutex_t* mutex)
{
    return pthread_mutex_destroy(mutex) == 0;
}

REALLY_INLINE void VMPI_recursiveMutexLock(vmpi_mutex_t* mutex)
{
    pthread_mutex_lock(mutex);
}

REALLY_INLINE bool VMPI_recursiveMutexTryLock(vmpi_mutex_t* mutex)
{
    return pthread_mutex_trylock(mutex) == 0;
}

REALLY_INLINE void VMPI_recursiveMutexUnlock(vmpi_mutex_t* mutex)
{
    pthread_mutex_unlock(mutex);
}

REALLY_INLINE bool VMPI_condVarInit(vmpi_condvar_t* condvar)
{
    return pthread_cond_init(condvar, NULL) == 0;
}

REALLY_INLINE bool VMPI_condVarDestroy(vmpi_condvar_t* condvar)
{
    return pthread_cond_destroy(condvar) == 0;
}

REALLY_INLINE vmpi_thread_t VMPI_currentThread()
{
    return pthread_self();
}

REALLY_INLINE bool VMPI_tlsSetValue(uintptr_t tlsId, void* value)
{
    return pthread_setspecific((pthread_key_t)tlsId, value) == 0;
}

REALLY_INLINE void* VMPI_tlsGetValue(uintptr_t tlsId)
{
    return pthread_getspecific((pthread_key_t)tlsId);
}

// This is clearly very slow, and should only be used for testing purposes.
#ifdef EMULATE_ATOMICS_WITH_PTHREAD_MUTEX

static pthread_mutex_t atomicsLock = PTHREAD_MUTEX_INITIALIZER;

REALLY_INLINE int32_t VMPI_atomicIncAndGet32WithBarrier(volatile int32_t* value)
{
    pthread_mutex_lock(&atomicsLock);
    int32_t result = *value + 1;
    *value = result;
    pthread_mutex_unlock(&atomicsLock);
    return result;
}

REALLY_INLINE int32_t VMPI_atomicIncAndGet32(volatile int32_t* value)
{
    return VMPI_atomicIncAndGet32WithBarrier(value);
}

REALLY_INLINE int32_t VMPI_atomicDecAndGet32WithBarrier(volatile int32_t* value)
{
    pthread_mutex_lock(&atomicsLock);
    int32_t result = *value - 1;
    *value = result;
    pthread_mutex_unlock(&atomicsLock);
    return result;
}

REALLY_INLINE int32_t VMPI_atomicDecAndGet32(volatile int32_t* value)
{
    return VMPI_atomicDecAndGet32WithBarrier(value);
}

REALLY_INLINE bool VMPI_compareAndSwap32WithBarrier(int32_t oldValue, int32_t newValue, volatile int32_t* address)
{
    bool swapped;
    pthread_mutex_lock(&atomicsLock);
    if (*address == oldValue) {
        *address = newValue;
        swapped = true;
    } else {
        swapped = false;
    }
    pthread_mutex_unlock(&atomicsLock);
    return swapped;
}

REALLY_INLINE bool VMPI_compareAndSwap32(int32_t oldValue, int32_t newValue, volatile int32_t* address)
{
    return VMPI_compareAndSwap32WithBarrier(oldValue, newValue, address);
}

REALLY_INLINE void VMPI_memoryBarrier()
{
    pthread_mutex_lock(&atomicsLock);
    pthread_mutex_unlock(&atomicsLock);
}
#endif
