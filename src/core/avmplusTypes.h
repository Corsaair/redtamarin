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

#ifndef __avmplus_types__
#define __avmplus_types__

#include "avmplus_stdint.h"

namespace avmplus
{
	// legacy types
	typedef int8_t		sint8;
	typedef int8_t		int8;
	typedef uint8_t		byte;
	typedef uint8_t		uint8;

	typedef int16_t		sint16;
	typedef int16_t		int16;
	typedef uint16_t	uint16;

	typedef int32_t		sint32;
	typedef int32_t		int32;
	typedef uint32_t	uint32; 

	typedef int64_t		int64;
	typedef int64_t		sint64;
	typedef uint64_t	uint64;

	typedef intptr_t	sintptr;
	typedef uintptr_t	uintptr;

	/* wchar is our version of wchar_t, since wchar_t is different sizes
	   on different platforms, but we want to use UTF-16 uniformly. */
	typedef uint16_t wchar;
	
    #ifndef NULL
    #define NULL 0
    #endif

	// Atom should really be an intptr_t, but doing so can cause problematic compiles
	// because some platforms define intptr_t as an int64, and some as a long, which
	// create different overload possibilities in a few cases. Ideally, Atom should
	// be a unique pointer type (as it is in TT) but for now, avoid the code churn
	// by defining it the "old" way
	//
	// math friendly pointer (64 bits in LP 64 systems)
	#if defined (_MSC_VER) && (_MSC_VER >= 1300)
	    #define AVMPLUS_TYPE_IS_POINTER_SIZED __w64
	#else
	    #define AVMPLUS_TYPE_IS_POINTER_SIZED
	#endif	
	#ifdef AVMPLUS_64BIT
	typedef AVMPLUS_TYPE_IS_POINTER_SIZED int64_t Atom;
	#else
	typedef AVMPLUS_TYPE_IS_POINTER_SIZED int32_t Atom;
	#endif
	
	typedef struct Binding_* Binding;
	typedef struct CodeContextAtom_* CodeContextAtom;

	inline uint32 urshift(Atom atom, int amount)
	{
		return ((uint32)atom >> amount);
	}

	inline uint32 urshift(Binding b, int amount)
	{
		return (uint32_t(uintptr_t(b)) >> amount);
	}

	inline uint32 urshift(CodeContextAtom c, int amount)
	{
		return (uint32_t(uintptr_t(c)) >> amount);
	}
}

#endif /* __avmplus_types__ */
