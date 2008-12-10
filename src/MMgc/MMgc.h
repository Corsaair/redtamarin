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

#ifndef __MMgc__
#define __MMgc__

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif // HAVE_CONFIG_H

#ifdef NEED_MMGC_CONFIG_H
#include "MMgc-config.h"
#endif

// For size_t
#include <stddef.h>

#if defined(MMGC_CUSTOM_BUILD)
    #include "MMgcCustomBuild.h"
#else
	#ifdef WIN32
		#ifdef ARM
			#include "armbuild.h"
		#else
			#include "winbuild.h"
		#endif
	#endif

	#ifdef _MAC
		#include "macbuild.h"
	#endif

	#ifdef UNIX
		#include "unixbuild.h"
	#endif

	// don't include armbuild.h when MMGC_CUSTOM_BUILD is used
	#ifdef MMGC_ARM
		#include "armbuild.h"
	#endif
#endif

#ifdef SCRIPT_DEBUGGER
#ifndef DEBUGGER
#define DEBUGGER
#endif
#endif

#ifdef MMGC_AVMPLUS
#  define MMGC_RCROOT_SUPPORT
#endif

/**
* Controls whether MMgc reports alloc/dealloc info to a Sampler
*/
#ifdef DEBUGGER
#define FEATURE_SAMPLER
#endif
// Turn on in release builds
//#define FEATURE_SAMPLER

#ifdef FEATURE_SAMPLER
#define SAMPLE_ALLOC(_item, _size) if(MMgc::sampling) recordAllocationSample(_item, _size)
#define SAMPLE_FIXED_ALLOC(_item, _size) if( MMgc::sampling) recordAllocationSample(_item, _size, true)
#define SAMPLE_DEALLOC(_item, _size) if(MMgc::sampling) recordDeallocationSample(_item, _size)
#else
#define SAMPLE_ALLOC(_x, _s)
#define SAMPLE_FIXED_ALLOC(_x, _s)
#define SAMPLE_DEALLOC(_x, _s)
#endif

#if defined(_DEBUG) || defined(_MAC)
// for memset
#include <string.h>
#endif

#ifndef _MSC_VER
#define __forceinline
#else
#ifndef DEBUG
#include <memory.h>
#include <string.h>
#pragma intrinsic(memcmp)
#pragma intrinsic(memcpy)
#pragma intrinsic(memset)
#pragma intrinsic(strlen)
#pragma intrinsic(strcpy)
#pragma intrinsic(strcat)
#endif // DEBUG
#endif

#include "GCDebug.h"
/*
 * If _GCHeapLock is defined, a spin lock is used for thread safety
 * on all public API's (Alloc, Free, ExpandHeap)
 *
 * Warning:
 * We may use GCHeap for allocation on other threads, hence the
 * spinlock, but the MMgc garbage collector in general is not
 * thread-safe.
 */

#ifdef GCHEAP_LOCK
#ifdef WIN32
#include "GCSpinLockWin.h"
#endif
#ifdef _MAC
#include "GCSpinLockMac.h"
#endif
#ifdef UNIX
#include "GCSpinLockUnix.h"
#endif
#endif

namespace MMgc
{
	class GC;
	class GCTraceObject;
	class RCObject;
	class GCWeakRef;
	class GCObject;
	class GCHashtable;
	class Cleaner;
	class GCAlloc;
}

#include "GCTypes.h"
#include "GCStack.h"
#include "GCThreads.h"
#include "GCAllocObject.h"
#include "GCHeap.h"
#include "GCAlloc.h"
#include "GCLargeAlloc.h"
#include "GCThreadLocal.h"
#include "GCMemoryProfiler.h"
#include "FixedAlloc.h"
#include "FixedMalloc.h"
#include "GCGlobalNew.h"
#include "GCHashtable.h"
#include "GC.h"
#include "GCObject.h"
#include "GCWeakRef.h"
#include "WriteBarrier.h"

#if defined(MMGC_DRC) && !defined(WRITE_BARRIERS)
#error "Need write barriers for DRC"
#endif

#endif /* __MMgc__ */

