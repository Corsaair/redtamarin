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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

#ifdef MMGC_MEMORY_PROFILER
#include <dlfcn.h>
#include <cxxabi.h>
#include <mach-o/dyld.h>
#endif

#include <sys/mman.h>
#include <sys/types.h>
#include <sys/sysctl.h>

#include <mach/mach.h>
#include <mach/mach_time.h>

#define MAP_ANONYMOUS MAP_ANON

static const int kOSX105 = 9;

static size_t computePagesize()
{
    long pagesize = sysconf(_SC_PAGESIZE);
    // MacOS X 10.1 needs the extra check
    if (pagesize == -1)
        pagesize = 4096;
    return size_t(pagesize);
}

// Private to VMPI_getVMPageSize; DO NOT REFERENCE THIS VARIABLE ELSEWHERE.
// Always call VMPI_getVMPageSize, even inside this file.

static size_t pagesize = computePagesize();

size_t VMPI_getVMPageSize()
{
    return pagesize;
}

bool VMPI_canMergeContiguousRegions()
{
    return VMPI_useVirtualMemory();
}

bool VMPI_canCommitAlreadyCommittedMemory()
{
    return true;
}

bool VMPI_areNewPagesDirty()
{
#ifdef MMGC_POISON_MEMORY_FROM_OS
    return true;
#else
    return false;
#endif
}

static int get_major_version()
{
    int mib[2];
    mib[0]=CTL_KERN;
    mib[1]=KERN_OSRELEASE;
    char buf[10];
    size_t siz=sizeof(buf);
    sysctl(mib, 2, &buf, &siz, NULL, 0);
    return strtol(buf, 0, 10);
}

bool VMPI_useVirtualMemory()
{
#ifdef MMGC_64BIT
    return true;
#else
    return get_major_version() >= kOSX105;
#endif
}

static int get_mmap_fdes(int delta)
{
    // ensure runtime version
    if(get_major_version() >= kOSX105)
        return VM_MAKE_TAG(VM_MEMORY_APPLICATION_SPECIFIC_1+delta);
    else
        return -1;
}

void* VMPI_reserveMemoryRegion(void *address, size_t size)
{
    void *addr = (char*)mmap(address,
                             size,
                             PROT_NONE,
                             MAP_PRIVATE | MAP_ANONYMOUS,
                             get_mmap_fdes(0), 0);

    // the man page for mmap documents it returns -1 to signal failure.
    if (addr == (void *)-1) return NULL;

    if(address && address != addr) {
        // fail if we didn't get the right address
        VMPI_releaseMemoryRegion(addr, size);
        return NULL;
    }
    return addr;
}

bool VMPI_releaseMemoryRegion(void* address, size_t size)
{
    int result = munmap(address, size);
    return (result == 0);
}

bool VMPI_commitMemory(void* address, size_t size)
{
    char *got = (char*)mmap(address,
                            size,
                            PROT_READ | PROT_WRITE,
                            MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED,
                            get_mmap_fdes(0), 0);
#ifdef MMGC_POISON_MEMORY_FROM_OS
    if(got == address)
        memset(got, MMgc::GCHeap::FXFreshPoison, size);
#endif
    return (got == address);
}

bool VMPI_decommitMemory(char *address, size_t size)
{
    kern_return_t result = vm_deallocate(mach_task_self(), (vm_address_t)address, size);
    if(result == KERN_SUCCESS)
    {
        result = vm_map(mach_task_self(), (vm_address_t*)&address, size, 0, FALSE, MEMORY_OBJECT_NULL, 0, FALSE, VM_PROT_NONE, VM_PROT_READ|VM_PROT_WRITE|VM_PROT_EXECUTE, VM_INHERIT_NONE);
    }
    //  return false; // for testing RemovePartialBlock
    return (result == KERN_SUCCESS);
}

void* VMPI_allocateAlignedMemory(size_t size)
{
    void *addr = valloc(size);
#ifdef MMGC_POISON_MEMORY_FROM_OS
    GCAssert(size % VMPI_getVMPageSize() == 0);
    memset(addr, MMgc::GCHeap::FXFreshPoison, size);
#endif
    return addr;
}

void VMPI_releaseAlignedMemory(void* address)
{
    free(address);
}

size_t VMPI_getPrivateResidentPageCount()
{
    size_t private_pages = 0;
    task_t task = mach_task_self();

    vm_address_t addr = VM_MIN_ADDRESS;
    vm_size_t size = 0;
    while (true)
    {
        mach_msg_type_number_t count = VM_REGION_TOP_INFO_COUNT;
        vm_region_top_info_data_t info;
        mach_port_t object_name;
        kern_return_t ret;

        addr += size;

#if defined(VMCFG_64BIT) || defined(VMCFG_ARM)
        ret = vm_region_64(task, &addr, &size, VM_REGION_TOP_INFO, (vm_region_info_t)&info, &count, &object_name);
#else
        ret = vm_region(task, &addr, &size, VM_REGION_TOP_INFO, (vm_region_info_t)&info, &count, &object_name);
#endif

        if (ret != KERN_SUCCESS)
            break;
        private_pages += info.private_pages_resident;
    }
    return private_pages;
}

// Call VMPI_getPerformanceFrequency() once to initialize its cache; avoids thread safety issues.
static uint64_t unused_value = VMPI_getPerformanceFrequency();

uint64_t VMPI_getPerformanceFrequency()
{
    // *** NOTE ABOUT THREAD SAFETY ***
    //
    // These statics ought to be safe because they are initialized by a call at startup
    // (see lines above this function), before any AvmCores are created.

    static mach_timebase_info_data_t info;
    static uint64_t frequency = 0;
    if ( frequency == 0 ) {
        (void) mach_timebase_info(&info);
        frequency = (uint64_t) ( 1e9 / ((double) info.numer / (double) info.denom) );
    }
    return frequency;
}

void VMPI_cleanStack(size_t amount)
{
    void *space = alloca(amount);
    if(space)
        VMPI_memset(space, 0, amount);
}

uint64_t VMPI_getPerformanceCounter()
{
    return mach_absolute_time();
}

uintptr_t VMPI_getThreadStackBase()
{
    return (uintptr_t)pthread_get_stackaddr_np(pthread_self());
}

// Defined in PosixPortUtils.cpp to prevent them from being inlined below

extern void CallWithRegistersSaved2(void (*fn)(void* stackPointer, void* arg), void* arg, void* buf);
extern void CallWithRegistersSaved3(void (*fn)(void* stackPointer, void* arg), void* arg, void* buf);

void VMPI_callWithRegistersSaved(void (*fn)(void* stackPointer, void* arg), void* arg)
{
#if defined MMGC_IA32
    void* buf = NULL;
    __builtin_unwind_init();                    // Save registers - GCC intrinsic.  Not reliable on 10.4 PPC or 64-bit
#else
    jmp_buf buf;
    VMPI_setjmpNoUnwind(buf);                   // Save registers - not always reliable
#endif
    CallWithRegistersSaved2(fn, arg, &buf);     // Computes the stack pointer, calls fn
    CallWithRegistersSaved3(fn, &arg, &buf);    // Probably prevents the previous call from being a tail call
}

#ifdef MMGC_MEMORY_PROFILER

#ifdef MMGC_PPC

bool VMPI_captureStackTrace(uintptr_t* buffer, size_t len, uint32_t skip)
{
    register int stackp;
    uintptr_t pc;
    asm("mr %0,r1" : "=r" (stackp));
    while(skip--) {
        stackp = *(int*)stackp;
    }
    size_t i=0;
    // save space for 0 terminator
    len--;
    while(i<len && stackp) {
        pc = *((uintptr_t*)stackp+2);
        buffer[i++]=pc;
        stackp = *(int*)stackp;
    }
    buffer[i] = 0;
    return true;
}
#endif

#ifdef MMGC_ARM
bool VMPI_captureStackTrace(uintptr_t* buffer, size_t bufferSize, uint32_t framesToSkip)
{
    (void) buffer;
    (void) bufferSize;
    (void) framesToSkip;
    return false;
}
#endif

#if (defined(MMGC_IA32) || defined(MMGC_AMD64))

bool VMPI_captureStackTrace(uintptr_t* buffer, size_t bufferSize, uint32_t skip)
{
    void **ebp;
#ifdef MMGC_IA32
    asm("mov %%ebp, %0" : "=r" (ebp));
#else
    asm("mov %%rbp, %0" : "=r" (ebp));
#endif

    if (skip)
        --skip;

    // our embedder (eg Safari) can have stack frames that aren't formed
    // in the way we expect, which can make us crash. so sniff to ensure we're still
    // inside the stack range, and if not, bail before trying to dereference.
    // Note that pthread_get_stackaddr_np() and pthread_get_stacksize_np() seems
    // to be poorly documented and thus it's not completely clear if they are meant to
    // apply to the current thread vs. the main thread; the fact they take a thread as
    // an argument, and anecdotal evidence online, suggests the former (which is what we want).
    // In any event, doing this check makes for less-crashy code than what we had before,
    // which is good, but if you find misbehavior here, be aware.
    pthread_t const self = pthread_self();
    uintptr_t const stacktop = uintptr_t(pthread_get_stackaddr_np(self));
    uintptr_t const stacksize = pthread_get_stacksize_np(self);
    uintptr_t const stackbot = stacktop - stacksize;

    while(skip--)
    {
        if ((uintptr_t(ebp) - stackbot) >= stacksize)
            break;
        if (!*ebp)
            break;
        ebp = (void**)(*ebp);
    }

    bufferSize--;
    size_t i=0;
    while(i<bufferSize)
    {
        if ((uintptr_t(ebp) - stackbot) >= stacksize)
            break;
        if (!*ebp)
            break;
        buffer[i++] = *((uintptr_t*)ebp+1);
        ebp = (void**)(*ebp);
    }
    buffer[i] = 0;
    return true;
}
#endif

static FILE* atos_file = NULL;

bool startATOSProcess()
{
    char cmd[PATH_MAX];
    VMPI_snprintf(cmd, sizeof(cmd), "atos -p %d 2> /dev/null", getpid());
    // thank you very much http://boinc.berkeley.edu/svn/trunk/boinc/lib/mac/mac_backtrace.cpp
    // thank you very little Apple!
    // this is required for bi-directional I/O to work
    setenv("NSUnbufferedIO", "YES", 1);
    atos_file = popen(cmd, "r+");
    setlinebuf(atos_file);
    return atos_file != NULL;
}

void VMPI_setupPCResolution()
{
    //attempt launch of atos for the first time
    //if it fails for some reason we never reattempt it
    // silence occasional errors from atos
    //    startATOSProcess();
}

void VMPI_desetupPCResolution()
{
    if(atos_file != NULL)
    {
        pclose(atos_file);
        atos_file = NULL;
    }
}

bool VMPI_getFunctionNameFromPC(uintptr_t pc, char *buffer, size_t bufferSize)
{
    if(atos_file == NULL)
        return false;

    fprintf( atos_file, "%p\n",  (void*)pc);
    if(!fgets( buffer, bufferSize, atos_file))
        return false;

    char *eol = strchr(buffer, '\n');
    if(eol) {
        *eol = '\0';
    }

    return true;
}

bool VMPI_getFileAndLineInfoFromPC(uintptr_t pc, char *buffer, size_t bufferSize, uint32_t* lineNumber)
{
    (void)buffer;
    (void)pc;
    (void)bufferSize;
    (void)lineNumber;
    return false;
}

#endif //MMGC_MEMORY_PROFILER
