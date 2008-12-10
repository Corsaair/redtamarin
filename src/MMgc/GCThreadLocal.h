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

#ifndef __GCThreadLocal__
#define __GCThreadLocal__

#ifndef MMGC_PORTING_API

#ifdef HAVE_PTHREADS
#include <pthread.h>
#endif

namespace MMgc
{
#ifdef WIN32
	/**
	 * GCCriticalSection is a simple Critical Section class used by GCMemoryProfiler to
	 * ensure mutually exclusive access.  GCSpinLock doesn't suffice since its not
	 * re-entrant and we need that
	 */
	class GCCriticalSection
	{
	public:
		GCCriticalSection()
		{
			InitializeCriticalSection(&cs);
		}

		inline void Acquire()
		{
			EnterCriticalSection(&cs);
		}
		
		inline void Release()
		{
			LeaveCriticalSection(&cs);
		}

	private:
		CRITICAL_SECTION cs;
	};
	
	template<typename T>
	class GCThreadLocal
	{
	public:
		GCThreadLocal()
		{
			GCAssert(sizeof(T) <= sizeof(LPVOID));
			tlsId = TlsAlloc();
		}
		T operator=(T tNew)
		{
			TlsSetValue(tlsId, (LPVOID) tNew);
			return tNew;
		}
		operator T() const
		{
			return (T) TlsGetValue(tlsId);
		}
	private:
		DWORD tlsId;
	};
#else

#ifdef HAVE_PTHREADS
	template<typename T>
	class GCThreadLocal
	{
	public:
		GCThreadLocal()
		{
			GCAssert(sizeof(T) <= sizeof(void*));
			pthread_key_create(&tlsId, NULL);
		}
		T operator=(T tNew)
		{
			pthread_setspecific(tlsId, (const void*)tNew);
			return tNew;
		}
		operator T() const
		{
			return (T)pthread_getspecific(tlsId);
		}
	private:
		pthread_key_t tlsId ;
	};
#else	//HAVE_PTHREADS
	template<typename T>
	class GCThreadLocal
	{
	public:
		GCThreadLocal()
		{
			GCAssert(sizeof(T) <= sizeof(void*));
		}
		T operator=(T tNew)
		{
			return value=tNew;
		}
		operator T() const
		{
			return value;
		}
	private:
		T value ;
	};
#endif	//HAVE_PTHREADS

	class GCCriticalSection
	{
	public:
		GCCriticalSection()
		{
		}

		inline void Acquire()
		{
		}
		
		inline void Release()
		{
		}
	};
#endif

	class GCEnterCriticalSection
	{
	public:
		GCEnterCriticalSection(GCCriticalSection& cs) : m_cs(cs)
		{
			m_cs.Acquire();
		}
		~GCEnterCriticalSection()
		{
			m_cs.Release();
		}

	private:
		GCCriticalSection& m_cs;

		GCEnterCriticalSection & operator = (const GCEnterCriticalSection&);
		GCEnterCriticalSection(const GCEnterCriticalSection&);
	};
}

#endif // MMGC_PORTING_API

#endif
