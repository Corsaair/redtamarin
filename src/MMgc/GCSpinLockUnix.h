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

#ifndef __GCSpinLock__
#define __GCSpinLock__

#include <pthread.h>

namespace MMgc
{
	/**
	 * GCSpinLock is a simple spin lock class used by GCHeap to
	 * ensure mutually exclusive access.  The GCHeap may be accessed
	 * by multiple threads, so this is necessary to ensure that
	 * the threads do not step on each other.
	 */
	class GCSpinLock
	{
	public:
#if defined(__GNUC__) && (defined(MMGC_IA32) || defined(MMGC_AMD64))

		GCSpinLock()
 		{
			lock = 0;
			__asm__ volatile("" : : : "memory");
		}
	
		~GCSpinLock()
		{
			lock = 0;
			__asm__ volatile("" : : : "memory");
		}

		inline void Acquire()
		{
			while ( X86_TestAndSet(&lock, 1) != 0 ) {
				X86_Pause();
			}
			__asm__ volatile("" : : : "memory");
		}
		
		inline void Release()
		{
			__asm__ volatile("" : : : "memory");
			lock = 0;
		}

	private:

		inline int X86_TestAndSet(volatile int *ptr, int val) {
			__asm__ volatile("xchgl %0, (%2)" :"=r"(val) : "0"(val), "r"(ptr));
			return val;
		}

		inline void X86_Pause(void)
		{
			__asm__ volatile("pause");
		}

		volatile int lock;

#elif defined (USE_PTHREAD_MUTEX) //defined(MMGC_IA32) || defined(MMGC_AMD64)

		GCSpinLock()
		{
			pthread_mutex_init( &m1, 0 );
		}
	
		~GCSpinLock()
		{
			pthread_mutex_destroy( &m1 );
		}

		inline void Acquire()
		{
			pthread_mutex_lock( &m1 );
		}
		
		inline void Release()
		{
			pthread_mutex_unlock( &m1 );
		}

	private:
		pthread_mutex_t m1;

#else //defined(MMGC_IA32) || defined(MMGC_AMD64)

		GCSpinLock()
		{
			pthread_spin_init( &m1, 0 );
		}
	
		~GCSpinLock()
		{
			pthread_spin_destroy( &m1 );
		}

		inline void Acquire()
		{
			pthread_spin_lock( &m1 );
		}
		
		inline void Release()
		{
			pthread_spin_unlock( &m1 );
		}

	private:
		pthread_spinlock_t m1;

#endif //defined(MMGC_IA32) || defined(MMGC_AMD64)
	};

	/**
	 * GCAcquireSpinlock is a convenience class which acquires
	 * the specified spinlock at construct time, then releases
	 * the spinlock at desruct time.  The single statement
	 *
	 *    GCAcquireSpinlock acquire(spinlock);
	 *
	 * ... will acquire the spinlock at the top of the function
	 * and release it at the end.  This makes for less error-prone
	 * code than explicit acquire/release.
	 */
	class GCAcquireSpinlock
	{
	public:
		GCAcquireSpinlock(GCSpinLock& spinlock) : m_spinlock(spinlock)
		{
			m_spinlock.Acquire();
		}
		~GCAcquireSpinlock()
		{
			m_spinlock.Release();
		}

	private:
		GCSpinLock& m_spinlock;
	};
}

#endif /* __GCSpinLock__ */
