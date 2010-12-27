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

#include "MMgc.h"

#include <pthread.h>

bool VMPI_tlsCreate(uintptr_t* tlsId)
{
    pthread_key_t key;
    const int r = pthread_key_create(&key, NULL);

    if(r == 0)
    {
        // we expect the value to default to zero
        GCAssert(pthread_getspecific(key) == 0);
        *tlsId = (uintptr_t) key;
        return true;
    }

    return false;
}

void VMPI_tlsDestroy(uintptr_t tlsId)
{
    pthread_key_delete((pthread_key_t)tlsId);
}

bool VMPI_threadCreate(vmpi_thread_t* thread, vmpi_thread_attr_t* attr, vmpi_thread_start_t start_fn, vmpi_thread_arg_t arg)
{
    return pthread_create(thread, attr, start_fn, arg) == 0;
}

bool VMPI_threadDetach(vmpi_thread_t thread)
{
    return pthread_detach(thread) == 0;
}

void VMPI_threadSleep(int32_t timeout_millis)
{
    // We emulate sleeping by performing a timed wait
    // on a stack-local mutex and condition variable.
    vmpi_mutex_t mutex;
    vmpi_condvar_t condvar;
    VMPI_recursiveMutexInit(&mutex);
    VMPI_condVarInit(&condvar);
    VMPI_recursiveMutexLock(&mutex);
    VMPI_condVarTimedWait(&condvar, &mutex, timeout_millis);
    VMPI_recursiveMutexUnlock(&mutex);
    VMPI_recursiveMutexDestroy(&mutex);
    VMPI_condVarDestroy(&condvar);
}

void VMPI_threadJoin(vmpi_thread_t thread)
{
    void* value;
    pthread_join(thread, &value);
}

void VMPI_condVarWait(vmpi_condvar_t* condvar, vmpi_mutex_t* mutex)
{
    pthread_cond_wait(condvar, mutex);
}


bool VMPI_condVarTimedWait(vmpi_condvar_t* condvar, vmpi_mutex_t* mutex, int32_t timeout_millis)
{
#if AVMSYSTEM_MAC
    struct timespec timeSpec;
    timeSpec.tv_sec = timeout_millis / 1000;
    timeSpec.tv_nsec = (timeout_millis % 1000) * 1000000;
    return pthread_cond_timedwait_relative_np(condvar, mutex, &timeSpec) == ETIMEDOUT;
#else
    struct timespec timeSpec;
    struct timeval timeVal;
    gettimeofday(&timeVal, NULL);
    timeSpec.tv_sec = timeVal.tv_sec + (timeout_millis / 1000);
    timeSpec.tv_nsec = (timeVal.tv_usec * 1000) + ((timeout_millis % 1000) * 1000000);
    return pthread_cond_timedwait(condvar, mutex, &timeSpec) == ETIMEDOUT;
#endif
}

void VMPI_condVarBroadcast(vmpi_condvar_t* condvar)
{
    pthread_cond_broadcast(condvar);
}

void VMPI_condVarSignal(vmpi_condvar_t* condvar)
{
    pthread_cond_signal(condvar);
}

bool VMPI_threadAttrInit(vmpi_thread_attr_t* attr)
{
    return pthread_attr_init(attr) == 0;
}

bool VMPI_threadAttrDestroy(vmpi_thread_attr_t* attr)
{
    return pthread_attr_destroy(attr) == 0;
}

bool VMPI_threadAttrSetGuardSize(vmpi_thread_attr_t* attr, size_t size)
{
    return pthread_attr_setguardsize(attr, size) == 0;
}

bool VMPI_threadAttrSetStackSize(vmpi_thread_attr_t* attr, size_t size)
{
    return pthread_attr_setstacksize(attr, size) == 0;
}

void VMPI_threadAttrSetPriorityLow(vmpi_thread_attr_t* attr)
{
    (void)attr;
    // pthreads don't have priorities at the PTHREAD_SCOPE_SYSTEM scope.
}

void VMPI_threadAttrSetPriorityNormal(vmpi_thread_attr_t* attr)
{
    (void)attr;
    // pthreads don't have priorities at the PTHREAD_SCOPE_SYSTEM scope.
}

void VMPI_threadAttrSetPriorityHigh(vmpi_thread_attr_t* attr)
{
    (void)attr;
    // pthreads don't have priorities at the PTHREAD_SCOPE_SYSTEM scope.
}

size_t VMPI_threadAttrDefaultGuardSize()
{
    pthread_attr_t attr;
    size_t size;
    pthread_attr_init(&attr);
    pthread_attr_getguardsize(&attr, &size);
    return size;
}

size_t VMPI_threadAttrDefaultStackSize()
{
    pthread_attr_t attr;
    size_t size;
    pthread_attr_init(&attr);
    pthread_attr_getstacksize(&attr, &size);
    return size;
}
