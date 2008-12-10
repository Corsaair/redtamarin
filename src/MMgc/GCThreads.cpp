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

#include "MMgc.h"

#ifdef MMGC_THREADSAFE
#include "prtypes.h"

using namespace MMgc;

PRUintn GCThread::g_tlsIndex;
GCThread *GCThread::g_first = NULL;
static PRLock *g_threadListLock = NULL;

void (PR_CALLBACK DestroyGCThread)(void *obj)
{
	delete static_cast<GCThread *>(obj);
}

void GCThread::Init()
{
    GCAssert(g_threadListLock == NULL);
	g_threadListLock = PR_NewLock();
	GCAssert(g_threadListLock != NULL);
	if (g_threadListLock != NULL) {
		PRStatus st = PR_NewThreadPrivateIndex(&g_tlsIndex, DestroyGCThread);
		(void) st;
		GCAssert(st == PR_SUCCESS);
	}
}

void GCThread::Destroy()
{
    GCAssert(g_threadListLock != NULL);

	PR_DestroyLock(g_threadListLock);
	g_threadListLock = NULL;
    // NSPR provides no way to release g_tlsIndex to the system.
}

GCThread::GCThread()
#ifdef _DEBUG
	: m_inRequest(false)
#endif
{
	PR_Lock(g_threadListLock);
	m_next = g_first;
	g_first = this;
	PR_Unlock(g_threadListLock);
}

GCThread * GCThread::GetCurrentThread()
{
    GCAssert(g_threadListLock != NULL);

    GCThread *t = static_cast<GCThread *>(PR_GetThreadPrivate(g_tlsIndex));
    if (t == NULL) {
        t = new GCThread;
        PRStatus st = PR_SetThreadPrivate(g_tlsIndex, t);
		(void) st;
        GCAssert(st == PR_SUCCESS);
    }
    return t;
}

#endif  // MMGC_THREADSAFE
