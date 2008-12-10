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
 * Portions created by the Initial Developer are Copyright (C) 1993-2006
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


#ifndef __GCTypes__
#define __GCTypes__

#include "mmgc_stdint.h"

#ifdef __SYMBIAN32__
#include <stddef.h>
#endif

#if defined(HAVE_VISIBILITY_ATTRIBUTE)
#define MMGC_VISIBILITY_DEFAULT __attribute__ ((visibility ("default")))
#else
#define MMGC_VISIBILITY_DEFAULT
#endif

#ifdef WIN32
#define MMGC_EXPORT __declspec(dllexport)
#define MMGC_IMPORT __declspec(dllimport)
#else
#define MMGC_EXPORT MMGC_VISIBILITY_DEFAULT
#define MMGC_IMPORT MMGC_VISIBILITY_DEFAULT
#endif

// If we're not making a MMgc DLL, MMGC_API is a no-op
#ifndef MMGC_DLL
#define MMGC_API
#else
#ifdef MMGC_IMPL
#define MMGC_API MMGC_EXPORT
#else
#define MMGC_API MMGC_IMPORT
#endif
#endif // MMGC_DLL

namespace MMgc
{
	// legacy types
	typedef int64_t		int64;
	typedef int64_t		sint64;
	typedef uint64_t	uint64;

	typedef uint32_t	uint32;
	typedef int32_t		int32;
	
	typedef uint16_t	uint16;
	typedef int16_t		int16;
	
	typedef uint8_t		uint8;
	typedef int8_t		int8;

	typedef uintptr_t	uintptr;
	typedef intptr_t	sintptr;

	/* wchar is our version of wchar_t, since wchar_t is different sizes
	   on different platforms, but we want to use UTF-16 uniformly. */
	typedef unsigned short wchar;

    typedef void* (*GCMallocFuncPtr)(size_t size);
    typedef void (*GCFreeFuncPtr)(void* mem);
	
    #ifndef NULL
    #define NULL 0
    #endif
}

#endif /* __GCTypes__ */
