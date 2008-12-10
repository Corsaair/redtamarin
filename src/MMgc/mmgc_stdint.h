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

#ifndef __mmgc_stdint__
#define __mmgc_stdint__

// pull in stdlib.h everywhere so that downstream includers can predict it.
// on Win32 and Win64, this defines intptr_t and uintptr_t, but no other C99 types we care about.
#include <stdlib.h>	

#ifdef _MSC_VER
	// MSVC doesn't support inttypes.h or most C99 types directly, so declare them ourself.

	#ifdef _ARM_
		// Windows Mobile doesn't provide intptr_t or uintptr_t, so we'll do it ourself
		typedef __int32				intptr_t; 
		typedef unsigned __int32	uintptr_t; 
	#endif

	typedef __int8				int8_t;
	typedef __int16				int16_t;
	typedef __int32				int32_t;
	typedef __int64				int64_t;
	typedef unsigned __int8		uint8_t;
	typedef unsigned __int16	uint16_t;
	typedef unsigned __int32	uint32_t; 
	typedef unsigned __int64	uint64_t;
#else
	#include <inttypes.h>
#endif

#endif /* __mmgc_stdint__ */
