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
 *   Jason Orendorff
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

#ifndef __MMGC_GCTHREADS__
#define __MMGC_GCTHREADS__

#ifdef MMGC_THREADSAFE

#include "prthread.h"
#include "prlock.h"
#include "prcvar.h"

namespace MMgc
{
	/** A non-reentrant mutex. */
	class GCLock
	{
		friend class GCCondition;
	public:
		GCLock() 
			: m_lock(PR_NewLock())
#ifdef _DEBUG
			, m_holder(NULL)
#endif
		{
			GCAssert(m_lock != NULL);
		}

		~GCLock() { PR_DestroyLock(m_lock); }

		void Acquire()
		{
#ifdef _DEBUG
			PRThread *thr = PR_GetCurrentThread();
			GCAssertMsg(m_holder != thr, "deadlock in GCLock::Acquire");
#endif
			PR_Lock(m_lock);
#ifdef _DEBUG
			m_holder = thr;
#endif
		}

		void Release()
		{
#ifdef _DEBUG
			GCAssert(IsHeld());
			m_holder = NULL;
#endif
			PR_Unlock(m_lock);
		}

#ifdef _DEBUG
		/**
		 * True if the calling thread owns the lock.
		 *
		 * Warning: This is for use in debug-mode assertions about the lock
		 * state ONLY.  It's theoretically possible, on some non-IA32
		 * platforms, that reading m_holder outside the lock like this could
		 * return random junk, causing a false positive here.  On IA32, it's
		 * safe.
		 */
		bool IsHeld()
		{
			return m_holder == PR_GetCurrentThread();
		}
#endif

	private:
		// Prohibit copying.
		GCLock(const GCLock &);
		GCLock & operator=(const GCLock &);

		PRLock *m_lock;
#ifdef _DEBUG
		PRThread *m_holder;
#endif
	};

	class GCAutoLock {
	public:
		explicit GCAutoLock(GCLock &lock)
			: m_lock(lock)
		{
			lock.Acquire();
		}

		~GCAutoLock() { m_lock.Release(); }

	private:
		// Prohibit copying.
		GCAutoLock(const GCAutoLock &);
		GCAutoLock & operator=(const GCAutoLock &);

		GCLock &m_lock;
	};

	/** A pthreads-style condition variable. */
	class GCCondition {
	public:
		explicit GCCondition(GCLock &lock)
			: m_cvar(PR_NewCondVar(lock.m_lock))
#ifdef _DEBUG
			, m_lockObject(lock)
#endif
		{
			GCAssert(m_cvar != NULL);
		}

		~GCCondition() { PR_DestroyCondVar(m_cvar); }

		void Wait()
		{
			PRStatus st;

#ifdef _DEBUG
			m_lockObject.m_holder = NULL;
#endif
			st = PR_WaitCondVar(m_cvar, PR_INTERVAL_NO_TIMEOUT);
#ifdef _DEBUG
			m_lockObject.m_holder = PR_GetCurrentThread();
#endif
			(void)st;
			GCAssert(st == PR_SUCCESS);
		}

		void NotifyAll()
		{
			PRStatus st;

			st = PR_NotifyAllCondVar(m_cvar);
			(void)st;
			GCAssert(st == PR_SUCCESS);
		}

	private:
		// Prohibit copying.
		GCCondition(const GCCondition &);
		GCCondition & operator=(const GCCondition &);

		PRCondVar *m_cvar;
#ifdef _DEBUG
		GCLock &m_lockObject;
#endif
    };

	/** A catchall object for per-thread state. */
	class MMGC_API GCThread {
	public:
		static void Init();
		static void Destroy();

		static GCThread * GetCurrentThread();

#ifdef _DEBUG
	public:
		void OnEnterRequest()
		{
			GCAssert(!m_inRequest);
			m_inRequest = true;
		}

		void OnLeaveRequest()
		{
			GCAssert(m_inRequest);
			m_inRequest = false;
		}

		bool IsInActiveRequest() { return m_inRequest; }

	private:
		bool m_inRequest;
#else
	public:
		void OnEnterRequest() {}
		void OnLeaveRequest() {}
#endif

	private:
		// Prohibit copying.
		GCThread(const GCThread &);
		GCThread & operator=(const GCThread &);

		GCThread();

		static PRUintn g_tlsIndex;
		static GCThread *g_first;
		GCThread *m_next;
	};
}

#endif // MMGC_THREADSAFE

#endif // __MMGC_GCTHREADS__
