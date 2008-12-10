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

#ifdef DEBUG
#ifndef _DEBUG
#define _DEBUG
#endif
#endif

/**
 * Critical section on GCHeap allocations.
 */
#define GCHEAP_LOCK

/**
 * IA-32
 */
#if defined(__i386__) || defined(__i386)
#define MMGC_IA32
#elif defined(__x86_64__)
#define MMGC_AMD64
#define MMGC_64BIT
#elif defined(__powerpc__)
#define MMGC_PPC
#elif defined(__sparc__) || defined(__sparc)
#define MMGC_SPARC
#elif defined(__arm__)
#define MMGC_ARM
#else
#error Unknown CPU type
#endif

/**
 * Define this to get stack traces.  Helps with memory leaks.
 */
#ifdef DEBUG
#define MEMORY_INFO
#endif

/**
 * This turns on incremental collection as well as all of
 * the write barriers.
 */
#define WRITE_BARRIERS

/**
 * Define this if MMgc is being integrated with avmplus.
 * Activates dynamic profiling support, etc.
 */
#define MMGC_AVMPLUS

/**
 * Use VirtualAlloc to reserve/commit memory
 */
#define USE_MMAP

/**
 *
 */
#define DECOMMIT_MEMORY

/**
 * Controls whether DRC is in use
 */

#define MMGC_DRC

/**
 * This makes JIT code buffers read-only to reduce the probability of
 * heap overflow attachs
 */

#define AVMPLUS_JIT_READONLY

/**
 * Do not Use VirtualAlloc to reserve/commit memory for sparc
 * The pagesize of sparc is 8192 which is not supported yet.
 */
#ifdef MMGC_SPARC
#undef USE_MMAP
#endif

#define HAVE_PTHREADS
#define HAVE_STDARG
