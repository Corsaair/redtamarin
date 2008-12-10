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
using namespace MMgc;

#ifdef DARWIN
    #if defined(AVMPLUS_MAC_CARBON)
		#include <Carbon/Carbon.h>
	#endif
#endif

#ifdef AVMPLUS_ROSETTA
// Include sysctlbyname and getpid
#include <sys/types.h>
#include <sys/sysctl.h>
#include <unistd.h>
#endif

#ifdef AVMPLUS_UNIX

#ifdef BSD
#define GUARD_SIG SIGBUS
#else
#define GUARD_SIG SIGSEGV
#endif

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <signal.h>
#endif

/* number of pages commited each time grow() is called */
#define PAGES_PER_GROW	4

#ifdef AVMPLUS_MACH_EXCEPTIONS
extern "C"
{
	extern boolean_t exc_server(mach_msg_header_t *,
								mach_msg_header_t *);
		
	extern kern_return_t exception_raise(mach_port_t,
										 mach_port_t,
										 mach_port_t,
										 exception_type_t,
										 exception_data_t,
										 mach_msg_type_number_t);
		
	extern kern_return_t exception_raise_state(mach_port_t,
											   mach_port_t,
											   mach_port_t,
											   exception_type_t,
											   exception_data_t,
											   mach_msg_type_number_t,
											   thread_state_flavor_t*,
											   thread_state_t,
											   mach_msg_type_number_t,
											   thread_state_t,
											   mach_msg_type_number_t*);

	extern kern_return_t exception_raise_state_identity(mach_port_t,
														mach_port_t,
														mach_port_t,
														exception_type_t,
														exception_data_t,
														mach_msg_type_number_t,
														thread_state_flavor_t*,
														thread_state_t,
														mach_msg_type_number_t,
														thread_state_t,
														mach_msg_type_number_t*);

	#ifdef USE_EXC_SERVER
	kern_return_t catch_exception_raise(mach_port_t exception_port,
										mach_port_t thread,
										mach_port_t task,
										exception_type_t exception,
										exception_data_t code,
										mach_msg_type_number_t code_count)
	{
		return avmplus::GenericGuard::catch_exception_raise(exception_port,
														    thread,
														    task,
														    exception,
														    code,
														    code_count);
	}
	#endif
}
#endif

namespace avmplus
{
#if defined(AVMPLUS_MIR) || defined(DEBUGGER)
	GrowableBuffer::GrowableBuffer(MMgc::GCHeap *gcheap, bool mir)
		: heap(gcheap)
		, forMir(mir)
	{
		init();
		AvmAssert( (size_t)MathUtils::nextPowerOfTwo((int)(pageSize()-1)) == pageSize() );
	}

	GrowableBuffer::~GrowableBuffer()
	{
		free();
	}

	void GrowableBuffer::init()
	{
		first = 0;
		last = 0;
		uncommit = 0;
		current = 0;
	}

	byte* GrowableBuffer::reserve(size_t amt)
	{
		// attempt to reserve space 
		amt = (size_t)pageAfter((byte*)amt);   // align to page
		first = (forMir) ? (byte*)heap->ReserveMirMemory(amt) : (byte*)heap->ReserveCodeMemory(0, amt);
		last = first + amt;
		uncommit = first;
		current = first;

		// commit the first page and make it a guard page
		if (first)
			heap->SetGuardPage(first);
			
		return first;
	}

	byte* GrowableBuffer::decommitUnused()
	{
		// have we committed too much beyond the current location?
		if (current + pageSize() < uncommit) 
		{
			// get rid of pages
			byte* after = pageAfter(current);
#ifdef MEMORY_INFO
			MMgc::ChangeSizeForObject(this, (int)(-1 * (uncommit-after)));
#endif
			heap->DecommitCodeMemory((void*)after, uncommit-after);
			uncommit = after;

			heap->SetGuardPage(uncommit);
		}
		return uncommit;
	}

	byte* GrowableBuffer::grow()
	{ 
		return growBy(pageSize()*PAGES_PER_GROW); 
	}

	byte* GrowableBuffer::growBy(size_t amt)
	{
		AvmAssertMsg(amt % pageSize() == 0, "amt must be multiple of pageSize");
		size_t grow = ( (uncommit + amt) < last) ? amt : last - uncommit;
#ifdef MEMORY_INFO
		MMgc::ChangeSizeForObject(this, (int)grow);
#endif
		void* res = heap->CommitCodeMemory((void*)uncommit, grow);
		// This breaks when GrowableBuffer used by sampler, and is going away soon anyways
		//GC::GetGC(this)->UpdateStat("jit", (int) GCHeap::SizeToBlocks(grow));
		AvmAssert(res != 0);
		if(res == 0)
		  return uncommit;

		uncommit += grow;

		// commit the first page and make it a guard page
		heap->SetGuardPage(uncommit);
		
		return uncommit;
	}

	byte* GrowableBuffer::shrinkTo(size_t amt)
	{
		AvmAssertMsg(amt % pageSize() == 0, "amt must be multiple of pageSize");
		byte* shrinkTo = start() + amt;
		size_t size = (shrinkTo < uncommit) ? uncommit - shrinkTo : 0;
		if (size > 0)
		{	
#ifdef MEMORY_INFO
			MMgc::ChangeSizeForObject(this, (int)(-1 * size));
#endif
			void* res = heap->DecommitCodeMemory((void*)shrinkTo, size);
			// This breaks when GrowableBuffer used by sampler, and is going away soon anyways
			//GC::GetGC(this)->UpdateStat("jit", -1 * (int)GCHeap::SizeToBlocks(size));
			AvmAssert(res != 0);
			(void)res;
			uncommit = shrinkTo;

			// commit the first page and make it a guard page
			heap->SetGuardPage(uncommit);
		}
		return uncommit;
	}

	void GrowableBuffer::free()
	{
		// get rid of the whole shebang
		if (first != 0)
		{
#ifdef MEMORY_INFO
			MMgc::ChangeSizeForObject(this, (int)(-1 * (uncommit-first)));
			heap->DecommitCodeMemory(first, uncommit-first);
#endif
			// This breaks when GrowableBuffer used by sampler, and is going away soon anyways
			//GC::GetGC(this)->UpdateStat("jit", -1 * (int)GCHeap::SizeToBlocks(uncommit-first));
			if (forMir)
				heap->ReleaseMirMemory(first, size());
			else
				heap->ReleaseCodeMemory(first, size());
			init();
		}
	}
#endif

#ifdef FEATURE_BUFFER_GUARD

	//
	// GenericGuard
	//

	#ifdef AVMPLUS_WIN32

	#ifdef _WIN64	
	static GenericGuard* gGrowthGuards = NULL;
	static GenericGuard* gBufferGuards = NULL;
	static PVOID gBufferGuardHandler = 0;
	static PVOID gGrowthGuardHandler = 0;
	#endif

    #pragma warning(disable: 4733) // make sure you build with linker option /SAFESEH:NO !!!!

	void GenericGuard::init()
	{
#ifndef _WIN64
		record.prev = 0;
		record.handler = 0;
		record.instance = 0;
		record.terminator = 0;
#endif
	}

#ifndef _WIN64
	void GenericGuard::registerHandler()
	{
		if (record.instance == 0)
		{
			record.handler = (DWORD)guardRoutine;
			record.instance = (GenericGuard*)this;
			record.terminator = 0xffffffff;		
			/* swap in our handler record */
			__asm
			{
				mov ecx, [this]
				mov eax, fs:[0];
				mov [ecx].record.prev, eax;
				lea eax, [ecx].record;
				mov fs:[0], eax;
			}
		}
	}

	void GenericGuard::unregisterHandler()
	{
		if (record.instance != 0)
		{
			/* swap out our handler record */
			__asm 
			{
				mov ecx, [this]
				mov eax, [ecx].record.prev;
				mov fs:[0], eax;
			}
		}
		record.instance = 0;
	}
#endif

#ifdef _WIN64
	LONG NTAPI GenericGuard::guardRoutine(PEXCEPTION_POINTERS pexp)
	{
		PEXCEPTION_RECORD exceptionRecord = pexp->ExceptionRecord;
		PCONTEXT contextRecord = pexp->ContextRecord;
		(void)contextRecord;

		if (exceptionRecord->ExceptionCode==EXCEPTION_GUARD_PAGE ||
			exceptionRecord->ExceptionCode == EXCEPTION_ACCESS_VIOLATION)
		{
			// GrowthGuard? Go through the list and see
			if (gGrowthGuards!=NULL)
			{
				GenericGuard* pGuard = gGrowthGuards;
				while(pGuard)
				{
					int ret = pGuard->handleException(exceptionRecord,
														NULL,
														contextRecord,
														NULL);
					if (ret==EXCEPTION_CONTINUE_EXECUTION)
						return ret;

					pGuard = pGuard->nextGuard;
				}
				// didn't find a handler for this, return if we were
				// looking for a guard page handler
				if (exceptionRecord->ExceptionCode==EXCEPTION_GUARD_PAGE)
					return EXCEPTION_CONTINUE_SEARCH;
			}
		}
		
		if (exceptionRecord->ExceptionCode == EXCEPTION_ACCESS_VIOLATION)
		{
			// BufferGuard?
			if(gBufferGuards!=NULL)
			{
				GenericGuard* pGuard = gBufferGuards;
				while(pGuard)
				{
					//GenericGuard* guard = (GenericGuard*)gBufferGuards.get(i);
					GenericGuard* guard = gBufferGuards;
					int ret = guard->handleException(exceptionRecord,
														NULL,
														contextRecord,
														NULL);
					if (ret==EXCEPTION_CONTINUE_EXECUTION)
						return ret;

					pGuard = pGuard->nextGuard;
				}
				// didn't find a handler for this
				return EXCEPTION_CONTINUE_SEARCH;
			}
		}
		return EXCEPTION_CONTINUE_SEARCH;
	}
#else
	/*static*/int __cdecl GenericGuard::guardRoutine(struct _EXCEPTION_RECORD *exceptionRecord,
													 void *establisherFrame,
													 struct _CONTEXT *contextRecord,
													 void *dispatcherContext)
	{
		if (exceptionRecord->ExceptionCode == EXCEPTION_ACCESS_VIOLATION || exceptionRecord->ExceptionCode == EXCEPTION_GUARD_PAGE)
		{
			GenericGuard* guard = (GenericGuard*)((ExceptionRegistrationRecord*)establisherFrame)->instance;

			return guard->handleException(exceptionRecord,
										  establisherFrame,
										  contextRecord,
										  dispatcherContext);
		}
		return ExceptionContinueSearch;
	}

    #pragma warning(default: 4733) // make sure you build with linker option /SAFESEH:NO !!!!	
#endif

    #endif /* AVMPLUS_WIN32 */
	
	#ifdef AVMPLUS_MACH_EXCEPTIONS
	mach_port_t GenericGuard::exceptionPort = (mach_port_t)NULL;
	pthread_t GenericGuard::exceptionThread;
	pthread_mutex_t GenericGuard::mutex;
	volatile GenericGuard* GenericGuard::guardList = NULL;

	void* GenericGuard::threadMain(void* /*arg*/)
	{
		struct
		{
			mach_msg_header_t head;
			NDR_record_t NDR;
			kern_return_t RetCode;
		}
		reply;

		struct
		{
			mach_msg_header_t head;
			mach_msg_body_t   msgh_body;
			mach_msg_port_descriptor_t thread;
			mach_msg_port_descriptor_t task;
			NDR_record_t NDR;
			exception_type_t exception;
			mach_msg_type_number_t codeCnt;
			integer_t code[2];
			mach_msg_trailer_t trailer;
		}
		msg;

		for (;;)
		{
			if (mach_msg(&msg.head,
						 MACH_RCV_MSG | MACH_RCV_LARGE,
						 0,
						 sizeof(msg),
						 exceptionPort,
						 MACH_MSG_TIMEOUT_NONE,
						 MACH_PORT_NULL) != MACH_MSG_SUCCESS)
			{
				AvmAssertMsg(false, "mach_msg failed");
				return NULL;
			}

			if (msg.head.msgh_id == kThreadExitMsg)
			{
				break;
			}
			
			#ifdef USE_EXC_SERVER
			// Handle the message (calls catch_exception_raise)
			if (!exc_server(&msg.head, &reply.head))
			{
				AvmAssertMsg(false, "exc_server failed");
			}
			#else
			reply.RetCode = catch_exception_raise(msg.head.msgh_remote_port,
												  msg.thread.name,
												  msg.task.name,
												  msg.exception,
												  msg.code,
												  msg.codeCnt);
			reply.head.msgh_bits = MACH_MSGH_BITS(MACH_MSGH_BITS_REMOTE(msg.head.msgh_bits), 0);
			reply.head.msgh_remote_port = msg.head.msgh_remote_port;
			reply.head.msgh_size = (mach_msg_size_t)sizeof(reply);
			reply.head.msgh_local_port = MACH_PORT_NULL;
			reply.head.msgh_id = msg.head.msgh_id + 100;
			#endif

			// Send the reply
			if (mach_msg(&reply.head,
						 MACH_SEND_MSG,
						 reply.head.msgh_size,
						 0,
						 MACH_PORT_NULL,
						 MACH_MSG_TIMEOUT_NONE,
						 MACH_PORT_NULL) != MACH_MSG_SUCCESS)
			{
				AvmAssertMsg(false, "mach_msg failed while sending reply");
			}
		}

		pthread_exit(NULL);
		return NULL;
	}

	#ifdef AVMPLUS_ROSETTA
	/*-*-------------------------------------------------------------------------
	/ Function
	/   LoadFrameworkBundle
	/
	/ Purpose
	/   Samething as GetSharedLibrary but for OS X and for non-CFM.
	/
	/ Entry
	/   framework  =>  A CFStringRef to the name of the framework you want to load.
	/ 	bundlePtr  =>  if non NULL upon return it will contain the reference to the framework you loaded.
	/--------------------------------------------*/
	static OSStatus LoadFrameworkBundle( CFStringRef framework, CFBundleRef *bundlePtr )
	{
		OSStatus 	err;
		FSRef 		frameworksFolderRef;
		CFURLRef	baseURL;
		CFURLRef	bundleURL;
		
		// clear out the result
		*bundlePtr = NULL;
		
		baseURL = NULL;
		bundleURL = NULL;
		
		err = ::FSFindFolder( kOnAppropriateDisk, kFrameworksFolderType, true, &frameworksFolderRef );
		if( err == noErr ) 
		{
			baseURL = ::CFURLCreateFromFSRef( kCFAllocatorSystemDefault, &frameworksFolderRef );
			if( !baseURL )
				err = coreFoundationUnknownErr;
		}
		
		if( !err ) 
		{
			bundleURL = ::CFURLCreateCopyAppendingPathComponent( kCFAllocatorSystemDefault, baseURL, framework, false );
			if( !bundleURL )
				err = coreFoundationUnknownErr;
		}

		if( !err )
		{
			*bundlePtr = ::CFBundleCreate( kCFAllocatorSystemDefault, bundleURL );
			if( !*bundlePtr)
				err = coreFoundationUnknownErr;
		}
		
		if( !err && !::CFBundleLoadExecutable( *bundlePtr ) )
				err = coreFoundationUnknownErr;

		// Clean up.
		if( err && *bundlePtr ) 
		{
			::CFRelease( *bundlePtr );
			*bundlePtr = NULL;
		}
		
		if( bundleURL != NULL )
			::CFRelease( bundleURL );

		if( baseURL != NULL)
			::CFRelease( baseURL );
		
		return err;
	}

	typedef int (*f_sysctlnametomib)(const char *name, int *mibp, size_t *sizep);

	bool GenericGuard::rosetta = false;

	/**
	 * The following two functions, sysctlbyname_with_pid and is_pid_native,
	 * are taken from Apple's Universal Binary Programming Guide.
	 * http://developer.apple.com/documentation/MacOSX/Conceptual/universal_binary/
	 *        universal_binary_exec_a/chapter_7_section_7.html
	 */
	static int sysctlbyname_with_pid(const char *name, pid_t pid, 
									 void *oldp, size_t *oldlenp, 
									 void *newp, size_t newlen)
	{
		if (pid == 0) {
			if (sysctlbyname(name, oldp, oldlenp, newp, newlen) == -1)  {
				AvmAssertMsg(false, "sysctlbyname_with_pid(0): sysctlbyname failed");
				return -1;
			}
		} else {
			int mib[CTL_MAXNAME];
			size_t len = CTL_MAXNAME;

			CFBundleRef sysBundle;
			if ( LoadFrameworkBundle( CFSTR("System.framework"), &sysBundle ) == noErr ) {
				// gcc -pedantic insists that "ISO C++ forbids casting between pointer-to-function and pointer-to-object"
				// this allows us to dodge that warning
				void* tmp = CFBundleGetFunctionPointerForName( sysBundle, CFSTR("sysctlnametomib") );
				f_sysctlnametomib p_sysctlnametomib = *(f_sysctlnametomib*)&tmp;
				if ( p_sysctlnametomib ) {
					if (p_sysctlnametomib(name, mib, &len) == -1) {
						//If we fail for any reason other than the sysctl does not exist
						//assert false.
						AvmAssertMsg( errno==ENOENT , "sysctlbyname_with_pid(0): sysctlnametomib failed");
						return -1;
					}
				} else {
					AvmAssertMsg(false, "CFBundleGetFunctionPointerForName(0): CFBundleGetFunctionPointerForName failed");				
					return -1;
				}
			} else {
				AvmAssertMsg(false, "LoadFrameworkBundle(0): LoadFrameworkBundle failed");				
				return -1;
			}
			mib[len] = pid;
			len++;
			if (sysctl(mib, len, oldp, oldlenp, newp, newlen) == -1)  {
				AvmAssertMsg(false, "sysctlbyname_with_pid(0): sysctl failed");
				return -1;
			}
		}
		return 0;
	}
	
	static int is_pid_native(pid_t pid)
	{
		int ret = 0;
		size_t sz = sizeof(ret);
 
		if (sysctlbyname_with_pid("sysctl.proc_native", pid, 
								  &ret, &sz, NULL, 0) == -1) {
			if (errno == ENOENT) {
				// sysctl doesn't exist, which means that this version of Mac OS 
				// pre-dates Rosetta, so the application must be native.
				return 1;
			}
			AvmAssertMsg(false, "is_pid_native: sysctlbyname_with_pid  failed");
			return -1;
		}

		return ret;
	}
    #endif /* AVMPLUS_ROSETTA */
	
	void GenericGuard::staticInit()
	{
		#ifdef AVMPLUS_ROSETTA
		// Detect whether we are running under Rosetta
		rosetta = !is_pid_native(getpid());
		#endif
		
		guardList = NULL;
		
		pthread_mutexattr_t mutexattr;
		pthread_mutexattr_init(&mutexattr);
		pthread_mutex_init(&mutex, &mutexattr);
		pthread_mutexattr_destroy(&mutexattr);
		
		// Allocate the port
		mach_port_t task = mach_task_self();

		kern_return_t r;
		r = mach_port_allocate(task,
							   MACH_PORT_RIGHT_RECEIVE,
							   &exceptionPort);
		if (r != KERN_SUCCESS)
		{
			AvmAssertMsg(false, "mach_port_allocate failed");
			return;
		}

		r = mach_port_insert_right(task,
								   exceptionPort,
								   exceptionPort,
								   MACH_MSG_TYPE_MAKE_SEND);
		if (r != KERN_SUCCESS)
		{
			AvmAssertMsg(false, "mach_port_insert_right failed");
			return;
		}
		
		// Start the thread
		pthread_attr_t attr;
		if (pthread_attr_init(&attr) != 0)
		{
			AvmAssertMsg(false, "pthread_attr_init failed");
			return;
		}

		if (pthread_create(&exceptionThread, &attr, threadMain, NULL) != 0)
		{
			AvmAssertMsg(false, "pthread_create failed");
			return;
		}

		pthread_attr_destroy(&attr);
	}

	void GenericGuard::staticDestroy()
	{
		// Send the thread the exit notification
		mach_msg_header_t msg;
		msg.msgh_bits = MACH_MSGH_BITS(MACH_MSG_TYPE_MAKE_SEND, 0);
		msg.msgh_size = sizeof(mach_msg_header_t);
		msg.msgh_remote_port = exceptionPort;
		msg.msgh_local_port = MACH_PORT_NULL;
		msg.msgh_id = kThreadExitMsg;

		mach_msg_return_t r;
		r = mach_msg(&msg,
					 MACH_SEND_MSG,
					 sizeof(msg),
					 0,
					 MACH_PORT_NULL,
					 MACH_MSG_TIMEOUT_NONE,
					 MACH_PORT_NULL);
		if (r != MACH_MSG_SUCCESS)
		{
			AvmAssertMsg(false, "mach_msg failed");
		}

		// Join the thread
		void *status;
		pthread_join(exceptionThread, &status);

		// Destroy the mutex
		pthread_mutex_destroy(&mutex);

		mach_port_deallocate(mach_task_self(), exceptionPort);
		exceptionPort = MACH_PORT_NULL;
	}

	void GenericGuard::init()
	{
	}

	kern_return_t GenericGuard::forward_exception(mach_port_t thread,
												 mach_port_t task,
												 exception_type_t exception,
												 exception_data_t data,
												 mach_msg_type_number_t data_count,
												 SavedExceptionPorts *savedExceptionPorts)
	{
		unsigned int i;
		kern_return_t r;
		mach_port_t port;
		exception_behavior_t behavior;
		thread_state_flavor_t flavor;
    
		#if defined (AVMPLUS_IA32) || defined(AVMPLUS_AMD64)
		i386_thread_state_t thread_state;
		#else
		ppc_thread_state_t thread_state;
		#endif
		
		mach_msg_type_number_t thread_state_count = THREAD_STATE_MAX;
        
		for (i=0; i<savedExceptionPorts->count; i++)
		{
			if (savedExceptionPorts->masks[i] & (1 << exception))
			{
				break;
			}
		}
		if (i == savedExceptionPorts->count)
		{
			AvmAssertMsg(false, "No handler for exception!");
		}
		
		port     = savedExceptionPorts->ports[i];
		behavior = savedExceptionPorts->behaviors[i];
		flavor   = savedExceptionPorts->flavors[i];
		
		if(behavior != EXCEPTION_DEFAULT)
		{
			r = thread_get_state(thread, flavor, (natural_t*)&thread_state, &thread_state_count);
			if(r != KERN_SUCCESS)
			{
				AvmAssertMsg(false, "thread_get_state failed in forward_exception");
			}
		}
    
		switch(behavior)
		{
        case EXCEPTION_DEFAULT:
            r = exception_raise(port, thread, task, exception, data, data_count);
            break;
        case EXCEPTION_STATE:
            r = exception_raise_state(port, thread, task, exception, data, 
									  data_count, &flavor, (natural_t*)&thread_state, thread_state_count, 
									  (natural_t*)&thread_state, &thread_state_count);
            break;
        case EXCEPTION_STATE_IDENTITY:
            r = exception_raise_state_identity(port, thread, task, exception, data, 
											   data_count, &flavor, (natural_t*)&thread_state, thread_state_count, 
											   (natural_t*)&thread_state, &thread_state_count);
            break;
        default:
            r = KERN_FAILURE;
            AvmAssertMsg(false, "forward_exception: unknown behavior");
            break;
		}
    
		if (behavior != EXCEPTION_DEFAULT)
		{
			r = thread_set_state(thread, flavor, (natural_t*)&thread_state, thread_state_count);
			if (r != KERN_SUCCESS)
			{
				AvmAssertMsg(false, "thread_set_state failed in forward_exception");
			}
		}
    
		return r;
	}

	void GenericGuard::registerHandler()
	{
		registered = true;
		
		// Add self to exception thread's list
		int retCode = pthread_mutex_lock(&mutex);
		(void)retCode;

        #if !defined(AVMPLUS_PTHREAD_NO_ASSERT)
		AvmAssert(!retCode);
		#endif

		thread = mach_thread_self();
		
		next = guardList;
		guardList = this;
		
		retCode = pthread_mutex_unlock(&mutex);

        #if !defined(AVMPLUS_PTHREAD_NO_ASSERT)
		AvmAssert(!retCode);
		#endif

		exception_mask_t mask = EXC_MASK_BAD_ACCESS;
		
		// Save exception ports
		memset(&savedExceptionPorts, 0, sizeof(SavedExceptionPorts));
		
		kern_return_t r;
		r = thread_get_exception_ports(thread,
									   mask,
									   savedExceptionPorts.masks,
									   &savedExceptionPorts.count,
									   savedExceptionPorts.ports,
									   savedExceptionPorts.behaviors,
									   savedExceptionPorts.flavors);
		if (r != KERN_SUCCESS)
		{
			AvmAssertMsg(false, "thread_get_exception_ports failed");
			return;
		}
		
		// Loop over the ports and find null ports
		// make sure the thread state flavors of null exception ports
		// are not zero.  They aren't valid. 
		for (unsigned int i = 0; i < savedExceptionPorts.count; ++i) {
			if (savedExceptionPorts.ports[i] == MACH_PORT_NULL) {
				if (savedExceptionPorts.flavors[i] == 0)
					savedExceptionPorts.flavors[i] = MACHINE_THREAD_STATE;
			}
			AvmAssert(VALID_THREAD_STATE_FLAVOR(savedExceptionPorts.flavors[i]));
		}
		
		// Install exception ports
		r = thread_set_exception_ports(thread,
									   mask,
									   exceptionPort,
									   EXCEPTION_DEFAULT,
									   MACHINE_THREAD_STATE);

		if (r != KERN_SUCCESS)
		{
			AvmAssertMsg(false, "thread_set_exception_ports failed");
		}
	}

	void GenericGuard::unregisterHandler()
	{
		if (!registered)
		{
			return;
		}
		
		// Remove self from the exception thread's list
		pthread_mutex_lock(&mutex);

		volatile GenericGuard* volatile *prev = &guardList;
		while (*prev != this)
		{
			prev = &((**prev).next);
		}
		*prev = next;
		
		pthread_mutex_unlock(&mutex);
        
        // Restore thread exception ports
		for (unsigned int i=0; i<savedExceptionPorts.count; i++)
		{
            AvmAssert(VALID_THREAD_STATE_FLAVOR(savedExceptionPorts.flavors[i]));
			thread_set_exception_ports(thread,
									   savedExceptionPorts.masks[i],
									   savedExceptionPorts.ports[i],
									   savedExceptionPorts.behaviors[i],
									   savedExceptionPorts.flavors[i]);
		}
		
		registered = false;
	}

	#ifdef AVMPLUS_ROSETTA
	inline int SWAP32(int x)
	{
		return (((x       & 0xFF) << 24) |
				(((x>>8)  & 0xFF) << 16) |
				(((x>>16) & 0xFF) << 8) |
				(((x>>24) & 0xFF)));
	}
	#endif
			
	kern_return_t GenericGuard::catch_exception_raise(mach_port_t /*exception_port*/,
													  mach_port_t thread,
													  mach_port_t task,
													  exception_type_t exception,
													  exception_data_t code,
													  mach_msg_type_number_t code_count)
	{
		bool isAccessViolation = false;
		
		// Find the GenericGuard associated with thread
		int retCode = pthread_mutex_lock(&mutex);
		(void)retCode;
		AvmAssert(!retCode);

		GenericGuard *guard = (GenericGuard*) guardList;
		while (guard)
		{
			if (guard->thread == thread)
			{
				break;
			}
			guard = (GenericGuard*) guard->next;
		}

		// If we couldn't find it, must be a different thread
		if (!guard)
		{
			// reset guard to get saved exception ports
			guard = (GenericGuard*) guardList;
			retCode = pthread_mutex_unlock(&mutex);
			AvmAssert(!retCode);
			goto forward;
		}
		
		retCode = pthread_mutex_unlock(&mutex);
		AvmAssert(!retCode);

		// If an access violation occurred, let the GenericGuard a shot
		// at handling the exception.
		isAccessViolation = (exception == EXC_BAD_ACCESS && code[0] == KERN_PROTECTION_FAILURE);

		#ifdef AVMPLUS_ROSETTA
		// Under Rosetta on 10.4.6 i386, exception and code[0] come through in
		// little-endian instead of big-endian.  Apple might fix that at some point,
		// so we'll permit either endian to match.
		if (rosetta)
		{
			isAccessViolation = isAccessViolation || (exception == SWAP32(EXC_BAD_ACCESS) &&
													  code[0] == SWAP32(KERN_PROTECTION_FAILURE));
		}
		#endif
		
		if (isAccessViolation)
		{
			kern_return_t returnCode;
			if (guard->handleException(returnCode))
			{
				// Our handler handled the exception.
				return returnCode;
			}
		}
		
		forward:

		// We didn't handle the exception, so pass it to the regular handler.
		SavedExceptionPorts *ports = (SavedExceptionPorts*)&guard->savedExceptionPorts;
		return forward_exception(thread, task, exception, code, code_count,
								 ports);
	}
	
#ifdef AVMPLUS_MIR
	bool GrowthGuard::handleException(kern_return_t& returnCode)
	{
    #ifdef AVMPLUS_ROSETTA
		// Under Rosetta, thread_get_state does not appear to work.
		// So, we will simply assume that this exception is intended for us
		// and grow the buffer.
		if (rosetta)
		{
			GrowableBuffer* g = buffer;
			g->grow();
			returnCode = KERN_SUCCESS;
			return true;
		}
	#endif
		
	#if defined (AVMPLUS_IA32) || defined(AVMPLUS_AMD64)
		i386_exception_state_t exc_state;
		mach_msg_type_number_t exc_state_count = i386_EXCEPTION_STATE_COUNT;
		thread_state_flavor_t flavor = i386_EXCEPTION_STATE;
	#else
		ppc_exception_state_t exc_state;
		mach_msg_type_number_t exc_state_count = PPC_EXCEPTION_STATE_COUNT;
		thread_state_flavor_t flavor = PPC_EXCEPTION_STATE;
	#endif

		thread_get_state(thread,
						 flavor,
						 (natural_t*)&exc_state,
						 &exc_state_count);

	#if defined (AVMPLUS_IA32) || defined(AVMPLUS_AMD64)
	#if __DARWIN_UNIX03 // Mac 10.5 SDK changed definition
		byte *AccessViolationAddress = (byte*) exc_state.__faultvaddr;
	#else
		byte *AccessViolationAddress = (byte*) exc_state.faultvaddr;
	#endif
    #else
		byte *AccessViolationAddress = (byte*) exc_state.dar;
    #endif
			
		GrowableBuffer* g = buffer;
		byte* nextPage = g->uncommitted();
		byte* nextPageAfterGrow = NULL;

		if (AccessViolationAddress == nextPage)
		{
			// sequential write access to buffer
			nextPageAfterGrow = g->grow();
		}
		
		if (AccessViolationAddress > nextPage && AccessViolationAddress < g->end())
		{
			// random access into buffer (commit next page after the hit)
			byte* page = g->pageAfter(AccessViolationAddress);
			nextPageAfterGrow = g->growBy(page - nextPage);			
		}
		
		if(nextPage != nextPageAfterGrow)
		{
			returnCode = KERN_SUCCESS;
			return true;
		}

		return false;
	}	
#endif // AVMPLUS_MACH_EXCEPTIONS
#endif

#ifdef AVMPLUS_UNIX
    static pthread_key_t guardKey = 0;
    static struct sigaction orig_sa;

    static void dispatchHandleException(int /*sig*/, siginfo_t *info, void * /*context*/)
    {
        GenericGuard *genericGuard = (GenericGuard*) pthread_getspecific(guardKey);
        bool handled = false;

        while (genericGuard && !handled)
        {
            handled = genericGuard->handleException((byte*) info->si_addr);
            genericGuard = genericGuard->next;
        }

        if (!handled)
        {
		sigaction(GUARD_SIG, &orig_sa, NULL);
        }
    }

    void GenericGuard::init()
    {
        next = NULL;
        if (!guardKey)
        {
            pthread_key_create(&guardKey, NULL);
        }
    }

    void GenericGuard::registerHandler()
    {
        GenericGuard *genericGuard = (GenericGuard*) pthread_getspecific(guardKey);

        if (!genericGuard)
        {
            // Make "this" the beginning.
            pthread_setspecific(guardKey, this);

            // install the signal handler
            struct sigaction sa;
        
            sa.sa_handler = 0;
            sa.sa_sigaction = dispatchHandleException;
            sigemptyset(&sa.sa_mask);
            sa.sa_flags = SA_SIGINFO;

	    sigaction(GUARD_SIG, &sa, &orig_sa);
        }
        else
        {
            // Add "this" to the end.
            while (genericGuard->next)
            {
                genericGuard = genericGuard->next;
            }

            genericGuard->next = this;
        }
    }

    void GenericGuard::unregisterHandler()
    {
        GenericGuard *genericGuard = (GenericGuard*) pthread_getspecific(guardKey);

        if (genericGuard == this)
        {
            // "this" is the first in the linked list
            if (genericGuard->next)
            {
                // Make "next" the beginning.
                pthread_setspecific(guardKey, genericGuard->next);
            }
            else
            {
                // "this" is the only element of the linked list, so
                // null out the thread local and remove the signal
                // handler.
                pthread_setspecific(guardKey, NULL);
                sigaction(GUARD_SIG, &orig_sa, NULL);
            }
        }
        else
        {
            while (genericGuard && genericGuard->next != this)
            {
                genericGuard = genericGuard->next;
            }

            if (genericGuard && genericGuard->next == this)
            {
                if (genericGuard->next->next)
                {
                    // "this" is in the middle of the linked list, so
                    // make the "before" point to the "after".
                    genericGuard->next = genericGuard->next->next;
                }
                else
                {
                    // "this" is at the end of the linked list, so
                    // just null out the pointer to it.
                    genericGuard->next = NULL;
                }
            }
        }
    }
#endif // AVMPLUS_UNUX

	// BufferGuard
	BufferGuard::BufferGuard(jmp_buf *jmpBuf)
	{
		this->jmpBuf = jmpBuf;	
		init();
		registerHandler();
	}

	BufferGuard::~BufferGuard()
	{
		unregisterHandler();
	}

#ifdef _WIN64
	void BufferGuard::registerHandler()
	{
		// If handler hasn't been installed, install it
		if (gBufferGuardHandler==0)
		{
			gBufferGuardHandler = AddVectoredExceptionHandler(1, (PVECTORED_EXCEPTION_HANDLER)&avmplus::GenericGuard::guardRoutine);
		}

		if (gBufferGuards==NULL)
		{
			// first guard
			this->prevGuard = NULL;
			this->nextGuard = NULL;
			gBufferGuards = this;
		}
		else
		{
			// Make this the first guard in the list
			this->prevGuard = NULL;
			this->nextGuard = gBufferGuards;
			gBufferGuards->prevGuard = this;
			gBufferGuards = this;
		}
	}

	void BufferGuard::unregisterHandler()
	{
		// Find us in the list
		GenericGuard* pGuard = gBufferGuards;
		while (pGuard!=this && pGuard!=NULL)
			pGuard = pGuard->nextGuard;
		if (pGuard)
		{
			// this is us
			if (pGuard->prevGuard)
				pGuard->prevGuard->nextGuard = pGuard->nextGuard;
			else
			{
				gBufferGuards = pGuard->nextGuard; // might be NULL
				if (gBufferGuards)
					gBufferGuards->prevGuard = NULL;
			}
		}

		if (gBufferGuards==NULL && gBufferGuardHandler!=NULL)
		{		
			// No more buffer guards, remove handler
			RemoveVectoredExceptionHandler(gBufferGuardHandler);
			gBufferGuardHandler = 0;
		}
	}
#endif

	// Platform specific code follows
#ifdef AVMPLUS_WIN32
	int BufferGuard::handleException(struct _EXCEPTION_RECORD* /*exceptionRecord*/,
									 void* /*establisherFrame*/,
									 struct _CONTEXT *contextRecord,
									 void* /*dispatcherContext*/)
	{
		// Set registers in contextRecord to point to the catch location when
		// we return.  We will *really* handle the exception there.  All exceptions
		// caught by this handler must be wrapped by TRY/CATCH blocks. See win32setjmp.cpp
#ifdef _WIN64
		struct _JUMP_BUFFER *buf = (_JUMP_BUFFER*)jmpBuf;
		contextRecord->Rdx = buf->Frame;
		contextRecord->Rbx = buf->Rbx;
		contextRecord->Rsp = buf->Rsp;
		contextRecord->Rbp = buf->Rbp;
		contextRecord->Rsi = buf->Rsi;
		contextRecord->Rdi = buf->Rdi;
		contextRecord->R12 = buf->R12;
		contextRecord->R13 = buf->R13;
		contextRecord->R14 = buf->R14;
		contextRecord->R15 = buf->R15;

		contextRecord->Rip = buf->Rip;

		memcpy(&contextRecord->Xmm6, &buf->Xmm6, sizeof(M128A)*10);
		//contextRecord->Xmm6 = (M128A)buf->Xmm6;
		//contextRecord->Xmm7 = buf->Xmm7;
		//contextRecord->Xmm8 = buf->Xmm8;
		//contextRecord->Xmm9 = buf->Xmm9;
		//contextRecord->Xmm10 = buf->Xmm10;
		//contextRecord->Xmm11 = buf->Xmm11;
		//contextRecord->Xmm12 = buf->Xmm12;
		//contextRecord->Xmm13 = buf->Xmm13;
		//contextRecord->Xmm14 = buf->Xmm14;
		//contextRecord->Xmm15 = buf->Xmm15;

		contextRecord->Rax = 1123;

		return EXCEPTION_CONTINUE_EXECUTION;
#else
		
		contextRecord->Ebp = (*jmpBuf)[0];
		contextRecord->Ebx = (*jmpBuf)[1];
		contextRecord->Edi = (*jmpBuf)[2];
		contextRecord->Esi = (*jmpBuf)[3];
		contextRecord->Esp = (*jmpBuf)[4];
		contextRecord->Eip = (*jmpBuf)[5];
		contextRecord->Eax = 1123;

		return ExceptionContinueExecution;
#endif // _WIN64

	}
#endif // AVMPLUS_WIN32

#ifdef AVMPLUS_MACH_EXCEPTIONS
	
	bool BufferGuard::handleException(kern_return_t& returnCode)
	{
	#if defined (AVMPLUS_IA32) || defined(AVMPLUS_AMD64)
		i386_thread_state_t thread_state;
		mach_msg_type_number_t thread_state_count = i386_THREAD_STATE_COUNT;
		thread_state_flavor_t flavor = i386_THREAD_STATE;
	#else
		ppc_thread_state_t thread_state;
		mach_msg_type_number_t thread_state_count = PPC_THREAD_STATE_COUNT;
		thread_state_flavor_t flavor = PPC_THREAD_STATE;
	#endif

		kern_return_t retVal;
		
		retVal = thread_suspend(thread);
		
		retVal = thread_get_state(thread,
								  flavor,
								  (natural_t*)&thread_state,
								  &thread_state_count);
		
		// set the registers to point back to the CATCH block     
		#ifdef AVMPLUS_PPC
		thread_state.srr0 = (*jmpBuf)[21];
		thread_state.r1   = (*jmpBuf)[0];
		#endif

		#if defined (AVMPLUS_IA32) || defined(AVMPLUS_AMD64)
		#if __DARWIN_UNIX03 // Mac 10.5 SDK changed definition
		thread_state.__ebx = (*jmpBuf)[0];
		thread_state.__esi = (*jmpBuf)[1];
		thread_state.__edi = (*jmpBuf)[2];
		thread_state.__ebp = (*jmpBuf)[3];
		thread_state.__esp = (*jmpBuf)[4];
		thread_state.__eip = (*jmpBuf)[5];			
		#else
		thread_state.ebx = (*jmpBuf)[0];
		thread_state.esi = (*jmpBuf)[1];
		thread_state.edi = (*jmpBuf)[2];
		thread_state.ebp = (*jmpBuf)[3];
		thread_state.esp = (*jmpBuf)[4];
		thread_state.eip = (*jmpBuf)[5];			
		#endif 
		#endif
		
		retVal = thread_set_state(thread,
								  flavor,
								  (natural_t*)&thread_state,
								  thread_state_count);
						 
		retVal = thread_resume(thread);
						 
		if(retVal == KERN_INVALID_ARGUMENT)
		{
			returnCode = KERN_FAILURE;
			return true;
		}
		
		// Handle the exception
		returnCode = KERN_SUCCESS;
		return true;
	}
	
	
#endif /* AVMPLUS_MACH_EXCEPTIONS */

#ifdef AVMPLUS_UNIX
    bool BufferGuard::handleException(byte * /*addr*/)
    {
#ifdef _DEBUG
        printf("BufferGuard::handleException: not implemented yet\n");
#endif
        return false;
    }
#endif // AVMPLUS_UNIX

#ifdef AVMPLUS_MIR
	// GrowthGuard
	GrowthGuard::GrowthGuard(GrowableBuffer* buffer)
	{
		this->registered = false;
		this->buffer = buffer;
		init();
		if (buffer) 
			registerHandler();
	}

	GrowthGuard::~GrowthGuard()
	{
		if (buffer) 
			unregisterHandler();
	}

#ifdef _WIN64
	void GrowthGuard::registerHandler()
	{
		if (gGrowthGuardHandler==0)
		{
			gGrowthGuardHandler = AddVectoredExceptionHandler(1, (PVECTORED_EXCEPTION_HANDLER)&avmplus::GenericGuard::guardRoutine);
		}

		if (gGrowthGuards==NULL)
		{
			// first guard
			this->prevGuard = NULL;
			this->nextGuard = NULL;
			gGrowthGuards = this;
		}
		else
		{
			// Make this the first guard in the list
			this->prevGuard = NULL;
			this->nextGuard = gGrowthGuards;
			gGrowthGuards->prevGuard = this;
			gGrowthGuards = this;
		}
	}

	void GrowthGuard::unregisterHandler()
	{
		// Find us in the list
		GenericGuard* pGuard = gGrowthGuards;
		while (pGuard!=this && pGuard!=NULL)
			pGuard = pGuard->nextGuard;
		if (pGuard)
		{
			// this is us
			if (pGuard->prevGuard)
				pGuard->prevGuard->nextGuard = pGuard->nextGuard;
			else
			{
				gGrowthGuards = pGuard->nextGuard; // might be NULL
				if (gGrowthGuards)
					gGrowthGuards->prevGuard = NULL;
			}
		}

		if (gGrowthGuards==NULL && gGrowthGuardHandler!=NULL)
		{		
			// No more Growth guards, remove handler
			RemoveVectoredExceptionHandler(gGrowthGuardHandler);
			gGrowthGuardHandler = 0;
		}
	}
#endif
#endif

	// Platform specific code follows
#ifdef AVMPLUS_MIR
#ifdef AVMPLUS_WIN32
	int GrowthGuard::handleException(struct _EXCEPTION_RECORD* exceptionRecord,
									 void* /*establisherFrame*/,
									 struct _CONTEXT* /*contextRecord*/,
									 void* /*dispatcherContext*/)
	{
		byte* AccessViolationAddress = (byte*) exceptionRecord->ExceptionInformation[1];
		byte* nextPage = buffer->uncommitted();
		if (AccessViolationAddress == nextPage)
		{
			// sequential write access to buffer
			buffer->grow();
			#ifdef _WIN64
			return EXCEPTION_CONTINUE_EXECUTION;
			#else
			return ExceptionContinueExecution;
			#endif
		}
		else if (AccessViolationAddress > nextPage && AccessViolationAddress < buffer->end())
		{
			// random access into buffer (commit next page after the hit)
			byte* page = buffer->pageAfter(AccessViolationAddress);
			buffer->growBy(page - nextPage);
			#ifdef _WIN64
			return EXCEPTION_CONTINUE_EXECUTION;
			#else
			return ExceptionContinueExecution;
			#endif
		}
		else
		{
			// hmm something is pretty bad here
			#ifdef _WIN64
			return EXCEPTION_CONTINUE_SEARCH;
			#else
			return ExceptionContinueSearch;
			#endif
		}
	}

#endif /* AVMPLUS_WIN32 */
#endif

#ifdef AVMPLUS_MIR
#ifdef AVMPLUS_UNIX
    bool GrowthGuard::handleException(byte* addr)
    {
        GrowableBuffer* g = buffer;
        byte* nextPage = g->uncommitted();
        bool result = false;

        if (addr == nextPage)
        {
            // sequential write access to buffer
            g->grow();
            result = true;
        }
        else if (addr > nextPage && addr < g->end())
        {
            // random access into buffer (commit next page after the hit)
            byte* page = g->pageAfter(addr);
            g->growBy(page - nextPage);
            result = true;
        }

        return result;
    }
#endif /* AVMPLUS_UNIX */
#endif

#endif /* FEATURE_BUFFER_GUARD */
}
