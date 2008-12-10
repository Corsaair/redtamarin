/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: t; tab-width: 4 -*- */
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
 *   leon.sha@sun.com
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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

#include "MMgc.h"
#include "GCDebug.h"
#include "GC.h"

#include <sys/mman.h>

#if !defined(MAP_ANONYMOUS) && defined(MAP_ANON)
#define MAP_ANONYMOUS MAP_ANON
#endif // !defined(MAP_ANONYMOUS) && defined(MAP_ANON)

#if defined(MEMORY_INFO) && defined(AVMPLUS_UNIX)
#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <dlfcn.h>
#endif

// avmplus standalone uses UNIX  
#ifdef _MAC
#define MAP_ANONYMOUS MAP_ANON
#endif

#ifdef SOLARIS
#include <ucontext.h>
#include <dlfcn.h>
extern "C" caddr_t _getfp(void);
typedef caddr_t maddr_ptr;
#else
typedef void *maddr_ptr;
#endif

#include <fcntl.h>

namespace MMgc
{
#ifndef USE_MMAP
	void *aligned_malloc(size_t size, size_t align_size, GCMallocFuncPtr m_malloc)
	{
		char *ptr, *ptr2, *aligned_ptr;
		int align_mask = align_size - 1;

		int alloc_size = size + align_size + sizeof(int);
		ptr=(char *)m_malloc(alloc_size);

		if(ptr==NULL) return(NULL);

		ptr2 = ptr + sizeof(int);
		aligned_ptr = ptr2 + (align_size - ((size_t)ptr2 & align_mask));

		ptr2 = aligned_ptr - sizeof(int);
		*((int *)ptr2)=(int)(aligned_ptr - ptr);

		return(aligned_ptr);
	}

	void aligned_free(void *ptr, GCFreeFuncPtr m_free)
	{
		int *ptr2=(int *)ptr - 1;
		char *unaligned_ptr = (char*) ptr - *ptr2;
		m_free(unaligned_ptr);
	}
#endif /* !USE_MMAP */

#ifdef USE_MMAP
	int GCHeap::vmPageSize()
	{
		long v = sysconf(_SC_PAGESIZE);
		return v;
	}

	void* GCHeap::ReserveCodeMemory(void* address,
									size_t size)
	{
		return (char*) mmap((maddr_ptr)address,
							size,
							PROT_READ | PROT_WRITE,
							MAP_PRIVATE | MAP_ANONYMOUS,
							-1, 0);
	}

	void GCHeap::ReleaseCodeMemory(void* address,
								   size_t size)
	{
		if (munmap((maddr_ptr)address, size) != 0)
			GCAssert(false);
	}

	bool GCHeap::SetGuardPage(void */*address*/)
	{
		return false;
	}
#endif /* USE_MMAP */

#ifdef AVMPLUS_JIT_READONLY
	/**
	 * SetPageProtection changes the page access protections on a block of pages,
	 * to make JIT-ted code executable or not.
	 *
	 * If executableFlag is true, the memory is made executable and read-only.
	 *
	 * If executableFlag is false, the memory is made non-executable and
	 * read-write.
	 */
	void GCHeap::SetPageProtection(void *address,
							   size_t size,
							   bool executableFlag,
							   bool writeableFlag)
	{
		// Should use vmPageSize() or kNativePageSize here.
		// But this value is hard coded to 4096 if we don't use mmap.
		int bitmask = sysconf(_SC_PAGESIZE) - 1;

		// mprotect requires that the addresses be aligned on page boundaries
		void *endAddress = (void*) ((char*)address + size);
		void *beginPage = (void*) ((size_t)address & ~bitmask);
		void *endPage   = (void*) (((size_t)endAddress + bitmask) & ~bitmask);
		size_t sizePaged = (size_t)endPage - (size_t)beginPage;

		int flags = PROT_READ;
		if (executableFlag) {
			flags |= PROT_EXEC;
		}
		if (writeableFlag) {
			flags |= PROT_WRITE;
		}
#ifdef DEBUG
		int retval =
#endif
		  mprotect((maddr_ptr)beginPage, sizePaged,flags);

		GCAssert(retval == 0);
	}
#endif /* AVMPLUS_JIT_READONLY */
	
#ifdef USE_MMAP
	void* GCHeap::CommitCodeMemory(void* address,
								  size_t size)
	{
		void* res;
		if (size == 0)
			size = GCHeap::kNativePageSize;  // default of one page

#ifdef AVMPLUS_JIT_READONLY
		mmap((maddr_ptr)address,
			 size,
			 PROT_READ | PROT_WRITE,
			 MAP_PRIVATE | MAP_FIXED | MAP_ANONYMOUS,
			 -1, 0);
#else
		mmap((maddr_ptr)address,
			 size,
			 PROT_READ | PROT_WRITE | PROT_EXEC,
			 MAP_PRIVATE | MAP_FIXED | MAP_ANONYMOUS,
			 -1, 0);
#endif /* AVMPLUS_JIT_READONLY */
		res = address;
		
		if (res == address)
			address = (void*)( (uintptr)address + size );
		else
			address = 0;
			
		committedCodeMemory += size;
		return address;
	}

	void* GCHeap::DecommitCodeMemory(void* address,
									 size_t size)
	{
		if (size == 0)
			size = GCHeap::kNativePageSize;  // default of one page

		// release and re-reserve it
		ReleaseCodeMemory(address, size);
		address = ReserveCodeMemory(address, size);
		committedCodeMemory -= size;
		return address;
	}
#else
	int GCHeap::vmPageSize()
	{
		return 4096;
	}

	void* GCHeap::ReserveCodeMemory(void* address,
									size_t size)
	{
		return aligned_malloc(size, 4096, m_malloc);
	}

	void GCHeap::ReleaseCodeMemory(void* address,
								   size_t size)
	{
		aligned_free(address, m_free);
	}

	bool GCHeap::SetGuardPage(void *address)
	{
		return false;
	}
	
	void* GCHeap::CommitCodeMemory(void* address,
								   size_t size)
	{
		committedCodeMemory += size;
		return address;
	}	
	void* GCHeap::DecommitCodeMemory(void* address,
									 size_t size)
	{
		committedCodeMemory -= size;
		return address;
	}	
#endif /* USE_MMAP */	

#ifdef USE_MMAP
	char* GCHeap::ReserveMemory(char *address, size_t size)
	{
		char *addr = (char*)mmap((maddr_ptr)address,
					 size,
					 PROT_READ | PROT_WRITE,
					 MAP_PRIVATE | MAP_ANONYMOUS,
					 -1, 0);
		if (addr == MAP_FAILED) {
			return NULL;
		}
		if(address && address != addr) {
			// behave like windows and fail if we didn't get the right address
			ReleaseMemory(addr, size);
			return NULL;
		}
		return addr;
	}

	bool GCHeap::CommitMemory(char *address, size_t size)
	{
		char *addr = (char*)mmap(address,
					size,
					PROT_READ | PROT_WRITE,
			                MAP_PRIVATE | MAP_FIXED | MAP_ANONYMOUS,
					-1, 0);
		GCAssert(addr == address);
		char* temp_addr = addr;
		while( temp_addr < (addr+size))
		{
			// Touch each page
			*temp_addr = 0;
			temp_addr += GCHeap::kBlockSize;
		}
		return addr == address;
	}

	bool GCHeap::DecommitMemory(char *address, size_t size)
	{
		ReleaseMemory(address, size);
		// re-reserve it
		char *addr = (char*)mmap((maddr_ptr)address,
					 size,
					 PROT_NONE,
					 MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED,
					 -1, 0);
		GCAssert(addr == address);
		return addr == address;
	}

	bool GCHeap::CommitMemoryThatMaySpanRegions(char *address, size_t size)
	{
		return CommitMemory(address, size);
	}

	bool GCHeap::DecommitMemoryThatMaySpanRegions(char *address, size_t size)
	{
		return DecommitMemory(address, size);
	}

	void GCHeap::ReleaseMemory(char *address, size_t size)
	{
#ifdef DEBUG
		int result =
#endif
		munmap((maddr_ptr)address, size);
		GCAssert(result == 0);
	}
#else
	char* GCHeap::AllocateMemory(size_t size)
	{
		return (char *) aligned_malloc(size, 4096, m_malloc);
	}

	void GCHeap::ReleaseMemory(char *address)
	{
		aligned_free(address, m_free);
	}	
#endif


#ifdef MEMORY_INFO  
	void GetInfoFromPC(int pc, char *buff, int /*buffSize*/) 
	{
#ifdef AVMPLUS_UNIX
		Dl_info dlip;
		dladdr((void *const)pc, &dlip);
		sprintf(buff, "0x%p:%s", (void *)pc, dlip.dli_sname);
#else
		sprintf(buff, "0x%x", pc);
#endif
	}

#ifdef MMGC_SPARC
	void GetStackTrace(sintptr *trace, int len, int skip)
	{
	  // TODO for sparc.
		GCAssert(false);

	}
#endif

#ifdef MMGC_PPC
	void GetStackTrace(sintptr *trace, int len, int skip) 
	{
	  register int stackp;
	  sintptr pc;
	  asm("mr %0,%%r1" : "=r" (stackp));
	  while(skip--) {
	    stackp = *(int*)stackp;
	  }
	  int i=0;
	  // save space for 0 terminator
	  len--;
	  while(i<len && stackp) {
	    pc = *((sintptr*)stackp+2);
	    trace[i++]=pc;
	    stackp = *(int*)stackp;
	  }
	  trace[i] = 0;
	}
#endif

#ifdef MMGC_IA32
	void GetStackTrace(sintptr *trace, int len, int skip)
	{
		void **ebp;
#ifdef SOLARIS
		ebp = (void **)_getfp();
#else
		asm("mov %%ebp, %0" : "=r" (ebp));
#endif

		while(skip-- && *ebp)
		{
			ebp = (void**)(*ebp);
		}

		/* save space for 0 terminator */
		len--;

		int i = 0;

		while (i < len && *ebp)
		{
			/* store the current frame pointer */
			trace[i++] = *((sintptr*) ebp + 1);
			/* get the next frame pointer */
			ebp = (void**)(*ebp);
		}

		trace[i] = 0;
	}
#endif

#ifdef MMGC_ARM
	void GetStackTrace(sintptr *trace, int len, int skip) {
		(void) trace;
		(void) len;
		(void) skip;
	}
#endif

#endif

#define state_newline  1
#define state_skipline  2
#define state_P 3
#define state_Pr 4
#define state_Private 6
#define state_size 7

	/*static*/
	size_t GCHeap::GetPrivateBytes() 
	{
#ifdef LINUX
		uint32 pid = getpid();
		char buff[32];
		sprintf(buff, "/proc/%d/smaps", pid);
		int smap_hndl = open(buff, O_RDONLY);
		size_t priv_bytes = 0;
		if( smap_hndl != -1 )
		{
			uint32 state = state_newline;
			char size_buff[16];
			uint32 size_idx = 0;
			int read_size = 0;
			while( (read_size = read(smap_hndl, buff, 32)) )
			{
				int i = 0;
				while(i < read_size )
				{
					char c = buff[i++];
					switch( state )
					{
					case state_newline:
						if( c == 'P' )
							state = state_P;
						else
							state = state_skipline;
						break;

					case state_skipline:
						if( c == '\n' )
							state = state_newline;
						break;

					case state_P:
						if( c == 'r' )
							state = state_Pr;
						else
							state = state_skipline;
						break;

					case state_Pr:
						if( c == 'i' )  // Good enough, nothing else in smaps starts with Pr
							state = state_Private;
						else
							state = state_skipline;
						break;

					case state_Private:
						if ( c >= '0' && c <= '9' )
						{
							state = state_size;
							size_buff[size_idx++] = c;
						}
						else if ( c == '\n')
							state = state_newline;
						break;

					case state_size:
						if( c >= '0' && c <= '9' )
							size_buff[size_idx++] = c;
						else
						{
							size_buff[size_idx] = 0;
							size_idx = 0;
							uint32 size = atoi(size_buff)*1024;
							uint32 blocks = size/GCHeap::kBlockSize;
							if( size % GCHeap::kBlockSize != 0 )
								++blocks;
							priv_bytes += blocks;
							
							if ( c == '\n' )
								state = state_newline;
							else
								state = state_skipline;
						}
						break;
					}
				}
			} 
			close(smap_hndl);
		}
	//	return 0;
	return priv_bytes; 
#else
	return 0;
#endif
	}
}
