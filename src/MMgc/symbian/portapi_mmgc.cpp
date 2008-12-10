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
 * Portions created by the Initial Developer are Copyright (C) 2004-2007
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

#include "portapi_mmgc.h"
#include <e32std.h>
#include <hal.h>

MMgc::mmgc_tls_head* MMgc::mmgc_tls_head::s_tls = NULL;

const TInt kHeapMinSize = 4 * 1024;
const TInt kHeapMaxSize = 64 * 1024 * 1024;

RChunk MMGC_PortAPI_Chunk;
RHeap* MMGC_PortAPI_Heap = NULL;
int MMGC_PortAPI_HighWaterMark = 0;

void MMGC_PortAPI_Initialize_Imp() 
{
}

#ifdef __WINSCW__
// Only use User::FastCounter() in the emulator. The value of TTime isn't updated
// often enough in the emulator.
#define USE_SYMBIAN_FASTCOUNTER
#endif

uint64_t MMGC_PortAPI_Frequency_Imp()
{
#ifdef USE_SYMBIAN_FASTCOUNTER
	TInt frequency;
	HAL::Get(HAL::EFastCounterFrequency, frequency);
	return frequency;
#else
	// TTime returns microseconds
	return 1000000;
#endif
}

TInt64 g_last_time = 0;
// We could move to use User::FastCounter, any benefits, disadvantages?
uint64_t MMGC_PortAPI_Time_Imp()
{
#ifdef USE_SYMBIAN_FASTCOUNTER
	TInt64 lt = User::FastCounter();
#else
	TTime t;
	t.UniversalTime ( );
	TInt64 lt = t.Int64 ( );
#endif
#ifndef EKA2
	return (uint64_t) (lt.Low() & 0x7FFFFFFF);
#else 
	return (uint64_t) (lt & 0x7FFFFFFF);
#endif // EKA2
}


void* MMGC_PortAPI_Alloc_Imp(size_t aSize)
{
	void* mem = User::Alloc(aSize);
	User::LeaveIfNull(mem);
	return mem;
}

#if 0
// Not needed -- the call to User::Free is defined in portapi_mmgc.h
void MMGC_PortAPI_Free_Imp(void* ptr)
{
	User::Free(ptr);
}
#endif

uintptr_t MMGC_PortAPI_GetStackTop_Imp()
{
	TThreadStackInfo info;
	RThread mythread;
	mythread.StackInfo(info);
	return uintptr_t(info.iBase);
}

#ifdef MMGC_PORTAPI_VALIDATE_PAGE_SIZE

int MMGC_PortAPI_GetPageSize_Imp()
{
	TInt pageSize;
	HAL::Get(HAL::EMemoryPageSize, pageSize);
	return pageSize;
}

#endif // #ifdef MMGC_PORTAPI_VALIDATE_PAGE_SIZE



#ifdef __ARMCC__
extern "C"
{
__asm void portapi_mmgc_push_registers(int* regs)
{
#ifdef __MARM_THUMB__
	stm r0!, {r1-r7}
#else
	stmia r0, {r1-r12}
#endif
	bx lr
}
}

#endif
