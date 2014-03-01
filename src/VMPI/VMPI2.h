/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmplus_VMPI2__
#define __avmplus_VMPI2__

// ==== BEFORE ==== 
/* for special case that need to be defined first */


// ==== HEADERS ==== 


// ==== ISO C / ANSI C ==== 

// ---- C.assert ---- 

// ---- C.assert ---- END


// ---- C.ctype ---- 

// ---- C.ctype ---- END


// ---- C.errno ---- 
extern void VMPI_set_errno(int value);
extern int VMPI_get_errno();
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
extern int VMPI_kill(int pid, int sig);
// ---- C.signal ---- END


// ---- C.stdarg ---- 

// ---- C.stdarg ---- END


// ---- C.stddef ---- 

// ---- C.stddef ---- END


// ---- C.stdio ---- 
extern int VMPI_getc_unlocked(FILE *stream);
extern int VMPI_getchar_unlocked();
extern int VMPI_putc_unlocked(int c, FILE *stream);
extern int VMPI_putchar_unlocked(int c);
// ---- C.stdio ---- END


// ---- C.stdlib ---- 
//extern void VMPI_free(void* ptr); // defined in VMPI.h
//extern const char *VMPI_getenv(const char *name); // defined in VMPI.h
//VMPI_malloc //extern void* VMPI_alloc(size_t size); // defined in VMPI.h
extern int VMPI_putenv(char *name);
extern char *VMPI_realpath(char const *path);
extern int VMPI_setenv(const char *name, const char *value, int overwrite);
extern int VMPI_system(const char *command);
extern int VMPI_unsetenv(const char *name);
// ---- C.stdlib ---- END


// ---- C.string ---- 

// ---- C.string ---- END


// ---- C.time ---- 

// ---- C.time ---- END




// ==== POSIX ==== 

// ---- C.conio ---- 
extern void VMPI_canonical(bool status);
extern void VMPI_echo(bool status);
//extern int VMPI_getch();
//extern int VMPI_getche();
extern int VMPI_kbhit();
// ---- C.conio ---- END


// ---- C.cpio ---- 

// ---- C.cpio ---- END


// ---- C.dirent ---- 

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
extern int VMPI_spawn(int *pid, const char *path, char *const argv[], char *const envp[]);
extern int VMPI_spawnp(int *pid, const char *file, char *const argv[], char *const envp[]);
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
extern int VMPI_chmod(const char *path, int mode);
extern int VMPI_mkdir(const char *path, int mode);
// ---- C.sys.stat ---- END


// ---- C.sys.time ---- 

// ---- C.sys.time ---- END


// ---- C.sys.types ---- 

// ---- C.sys.types ---- END


// ---- C.sys.utsname ---- 

// ---- C.sys.utsname ---- END


// ---- C.sys.wait ---- 
extern int VMPI_WEXITSTATUS(int status);
extern int VMPI_WIFCONTINUED(int status);
extern int VMPI_WIFEXITED(int status);
extern int VMPI_WIFSIGNALED(int status);
extern int VMPI_WIFSTOPPED(int status);
extern int VMPI_WSTOPSIG(int status);
extern int VMPI_WTERMSIG(int status);
extern int VMPI_wait(int *stat_loc);
extern int VMPI_waitid(int idtype, int id, siginfo_t *infop, int options);
extern int VMPI_waitpid(int pid, int *stat_loc, int options);
// ---- C.sys.wait ---- END


// ---- C.tar ---- 

// ---- C.tar ---- END


// ---- C.termios ---- 

// ---- C.termios ---- END


// ---- C.unistd ---- 
extern void VMPI_sleep(int milliseconds);
// ---- C.unistd ---- END


// ---- C.utime ---- 

// ---- C.utime ---- END




// ==== RNL ==== 

// ---- shell.HardwareInformation ---- 
// extern int VMPI_processorQtyAtBoot(); // defined in VMPI.h
extern double VMPI_SystemMemorySize();
extern double VMPI_SystemMemoryUse();
extern double VMPI_SystemMemoryPeak();
// ---- shell.HardwareInformation ---- END

// ---- shell.OperatingSystem ---- 
//extern void VMPI_OperatingSystemName(char *name);
// ---- shell.OperatingSystem ---- END



// ==== AVMGLUE ==== 


// ==== MISC ==== 

extern char *VMPI_int2char(int n);
extern char *VMPI_getLocale();
extern void VMPI_getUserName(char *username);
extern void VMPI_con_stream_mode(int state);
extern void VMPI_con_trans_mode(int state);
extern struct hostent *VMPI_gethostbyaddr(const char *addr);
extern double VMPI_getStdinFileLength();
extern void VMPI_getOperatingSystemName(char *name);
extern void VMPI_getOperatingSystemNodeName(char *nodename);
extern void VMPI_getOperatingSystemRelease(char *release);
extern void VMPI_getOperatingSystemVersion(char *version);
extern void VMPI_getOperatingSystemMachine(char *machine);
extern void VMPI_getOperatingSystemVersionNumbers(int *major, int *minor, int *bugfix);
extern int VMPI_getLogicalDrives();
extern int VMPI_getFileMode(const char *path);
extern double VMPI_getFileSize(const char *path);
extern double VMPI_getFileLastModifiedTime(const char *path);
extern bool VMPI_isRegularFile(const char *path);
extern bool VMPI_isDirectory(const char *path);
extern bool VMPI_isAttributeHidden(const char *path);
extern double VMPI_getFreeDiskSpace(const char *path);
extern double VMPI_getTotalDiskSpace(const char *path);

//extern size_t VMPI_getVMPageSize(); // defined in VMPI.h
//extern double VMPI_getLocalTimeOffset(); // defined in VMPI.h
//extern double VMPI_getDaylightSavingsTA(double time); // defined in VMPI.h
//extern double VMPI_getDate(); // defined in VMPI.h
//extern uint64_t VMPI_getTime(); // defined in VMPI.h
//extern void VMPI_log(const char* message); // defined in VMPI.h
//extern void VMPI_debugLog(const char* message); // defined in VMPI.h
//extern void VMPI_debugBreak(); // defined in VMPI.h
//extern size_t VMPI_size(void* ptr); // defined in VMPI.h
//extern uint64_t VMPI_getPerformanceFrequency(); // defined in VMPI.h
//extern uint64_t VMPI_getPerformanceCounter(); // defined in VMPI.h
//class VMPI_TimerClient // defined in VMPI.h
//extern uintptr_t VMPI_startTimer(unsigned int period, VMPI_TimerClient* client); // defined in VMPI.h
//extern void VMPI_stopTimer(uintptr_t id); // defined in VMPI.h
//extern void VMPI_lockInit(vmpi_spin_lock_t* lock); // defined in VMPI.h
//extern void VMPI_lockDestroy(vmpi_spin_lock_t* lock); // defined in VMPI.h
//extern bool VMPI_lockAcquire(vmpi_spin_lock_t* lock); // defined in VMPI.h
//extern bool VMPI_lockRelease(vmpi_spin_lock_t* lock); // defined in VMPI.h
//extern bool VMPI_lockTestAndAcquire(vmpi_spin_lock_t* lock); // defined in VMPI.h
//extern bool VMPI_tlsCreate(uintptr_t* tlsId); // defined in VMPI.h
//extern void VMPI_tlsDestroy(uintptr_t tlsId); // defined in VMPI.h
//extern bool VMPI_tlsSetValue(uintptr_t tlsId, void* value); // defined in VMPI.h
//extern void* VMPI_tlsGetValue(uintptr_t tlsId); // defined in VMPI.h
//extern vmpi_thread_t VMPI_currentThread(); // defined in VMPI.h
//extern vmpi_thread_t VMPI_nullThread(); // defined in VMPI.h
//extern void VMPI_callWithRegistersSaved(void (*fn)(void* stackPointer, void* arg), void* arg); // defined in VMPI.h
//extern int32_t VMPI_atomicIncAndGet32(volatile int32_t* value); // defined in VMPI.h
//extern int32_t VMPI_atomicIncAndGet32WithBarrier(volatile int32_t* value); // defined in VMPI.h
//extern int32_t VMPI_atomicDecAndGet32(volatile int32_t* value); // defined in VMPI.h
//extern int32_t VMPI_atomicDecAndGet32WithBarrier(volatile int32_t* value); // defined in VMPI.h
//extern bool VMPI_compareAndSwap32(int32_t oldValue, int32_t newValue, volatile int32_t* address); // defined in VMPI.h
//extern bool VMPI_compareAndSwap32WithBarrier(int32_t oldValue, int32_t newValue, volatile int32_t* address); // defined in VMPI.h
//extern void VMPI_memoryBarrier(); // defined in VMPI.h
//extern bool VMPI_threadCreate(vmpi_thread_t* thread, vmpi_thread_attr_t* attr, vmpi_thread_start_t start_fn, vmpi_thread_arg_t arg); // defined in VMPI.h
//extern bool VMPI_threadDetach(vmpi_thread_t thread); // defined in VMPI.h
//extern void VMPI_threadSleep(int32_t timeout_millis); // defined in VMPI.h
//extern void VMPI_threadJoin(vmpi_thread_t thread); // defined in VMPI.h
//extern bool VMPI_recursiveMutexInit(vmpi_mutex_t* mutex); // defined in VMPI.h
//extern bool VMPI_recursiveMutexDestroy(vmpi_mutex_t* mutex); // defined in VMPI.h
//extern void VMPI_recursiveMutexLock(vmpi_mutex_t* mutex); // defined in VMPI.h
//extern bool VMPI_recursiveMutexTryLock(vmpi_mutex_t* mutex); // defined in VMPI.h
//extern void VMPI_recursiveMutexUnlock(vmpi_mutex_t* mutex); // defined in VMPI.h
//extern bool VMPI_condVarInit(vmpi_condvar_t* condvar); // defined in VMPI.h
//extern bool VMPI_condVarDestroy(vmpi_condvar_t* condvar); // defined in VMPI.h
//extern void VMPI_condVarWait(vmpi_condvar_t* condvar, vmpi_mutex_t* mutex); // defined in VMPI.h
//extern bool VMPI_condVarTimedWait(vmpi_condvar_t* condvar, vmpi_mutex_t* mutex, int32_t timeout_millis); // defined in VMPI.h
//extern void VMPI_condVarBroadcast(vmpi_condvar_t* condvar); // defined in VMPI.h
//extern void VMPI_condVarSignal(vmpi_condvar_t* condvar); // defined in VMPI.h
//extern bool VMPI_threadAttrInit(vmpi_thread_attr_t* attr); // defined in VMPI.h
//extern bool VMPI_threadAttrSetGuardSize(vmpi_thread_attr_t* attr, size_t size); // defined in VMPI.h
//extern bool VMPI_threadAttrSetStackSize(vmpi_thread_attr_t* attr, size_t size); // defined in VMPI.h
//extern void VMPI_threadAttrSetPriorityLow(vmpi_thread_attr_t* attr); // defined in VMPI.h
//extern void VMPI_threadAttrSetPriorityNormal(vmpi_thread_attr_t* attr); // defined in VMPI.h
//extern void VMPI_threadAttrSetPriorityHigh(vmpi_thread_attr_t* attr); // defined in VMPI.h
//extern size_t VMPI_threadAttrDefaultGuardSize(); // defined in VMPI.h
//extern size_t VMPI_threadAttrDefaultStackSize(); // defined in VMPI.h
//extern void VMPI_threadYield(); // defined in VMPI.h
//extern int VMPI_processorQtyAtBoot(); // defined in VMPI.h
//extern void VMPI_spinloopPause(); // defined in VMPI.h
//struct VMPI_TimerData // defined in VMPI.h




#endif /* __avmplus_VMPI2__ */
