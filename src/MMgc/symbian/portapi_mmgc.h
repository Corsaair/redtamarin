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

#ifndef __mmgc_portapi__
#define __mmgc_portapi__

#include "inttypes.h"
#include <e32std.h>
#include <stddef.h>
#include "GCDebug.h"


namespace MMgc
{

	class mmgc_tls_data
	{
	public:
		mmgc_tls_data(TInt aKeyId) :iKeyId(aKeyId), iData(NULL) {}
		TInt iKeyId;
		TAny* iData;
		struct mmgc_tls_data* ipNext;
	};

	class mmgc_tls_head
	{
	public:
		mmgc_tls_head() :ipHead(NULL), iKeyNext(0) {}
		mmgc_tls_data* ipHead;
		TInt iKeyNext;
		static mmgc_tls_head* s_tls;
	};

	template<typename T>
	class GCThreadLocal
	{
	public:
		GCThreadLocal()
		{
			GCAssert(sizeof(T) <= sizeof(void*));
			if (mmgc_tls_head::s_tls == NULL)
			{
				mmgc_tls_head::s_tls = new mmgc_tls_head;
			}
			iTlsId = mmgc_tls_head::s_tls->iKeyNext;
			mmgc_tls_head::s_tls->iKeyNext++;
			mmgc_tls_data* pData = new mmgc_tls_data(iTlsId);
			if (pData)
			{
				pData->ipNext = mmgc_tls_head::s_tls->ipHead;
				mmgc_tls_head::s_tls->ipHead = pData;
			}
		}

		T operator=(T tNew)
		{
			mmgc_tls_data* pData = mmgc_tls_head::s_tls->ipHead;
			while(pData)
			{
				if (pData->iKeyId == iTlsId)
				{
					break;
				}
				pData = pData->ipNext;
			}
			if (pData)
			{
				pData->iData = (TAny*)tNew;
			}
			return tNew;
		}

		operator T() const
		{
			mmgc_tls_data* pData = mmgc_tls_head::s_tls->ipHead;
			while(pData)
			{
				if (pData->iKeyId == iTlsId)
				{
					break;
				}
				pData = pData->ipNext;
			}
			return (T)pData;
		}
	private:
		TInt iTlsId;
	};
}


#define MMGC_ASSERT_GC_LOCK(gc)      ((void) 0)
#define MMGC_ASSERT_EXCLUSIVE_GC(gc) ((void) 0)

#ifdef __ARMCC__

extern "C" void portapi_mmgc_push_registers(int* regs);

#define MMGC_GET_STACK_EXTENTS(_gc, _stack, _size) \
		int _regs[12]; \
		portapi_mmgc_push_registers(_regs); \
		_stack =  (void*)__current_sp(); \
		_size = (unsigned int)_gc->GetStackTop() - (unsigned int)_stack;
#elif __WINSCW__
#define MMGC_GET_STACK_EXTENTS(_gc, _stack, _size) \
		int save1,save2,save3,save4,save5,save6,save7;\
		__asm mov save1, eax \
		__asm mov save2, ebx \
		__asm mov save3, ecx \
		__asm mov save4, edx \
		__asm mov save5, ebp \
		__asm mov save6, esi \
		__asm mov save7, edi \
		__asm { mov _stack,esp } ;\
		_size = (unsigned int)_gc->GetStackTop() - (unsigned int)_stack;
#endif

// The Initialize function does any setup required for MMgc.
// In the Symbian case, it creates a memory chunk that can
// contain code.
extern void MMGC_PortAPI_Initialize_Imp();
#define MMGC_PortAPI_Initialize() MMGC_PortAPI_Initialize_Imp()

extern void* MMGC_PortAPI_Alloc_Imp(size_t);
#define MMGC_PortAPI_Alloc(_size) MMGC_PortAPI_Alloc_Imp(_size)
#define MMGC_PortAPI_Alloc_func MMGC_PortAPI_Alloc_Imp

#define MMGC_PortAPI_Free(_ptr) User::Free(_ptr)
#define MMGC_PortAPI_Free_func User::Free
//extern void MMGC_PortAPI_Free_Imp(void*);
//#define MMGC_PortAPI_Free(_ptr) MMGC_PortAPI_Free_Imp(_ptr)
//#define MMGC_PortAPI_Free_func MMGC_PortAPI_Free_Imp

extern int MMGC_PortAPI_HighWaterMark;
#define MMGC_PortAPI_GetHighWaterMark() MMGC_PortAPI_HighWaterMark

// Symbian ARM page size is always 4kB. We can validate
// this by calling MMGC_PortAPI_GetPageSize_Imp(), but no
// need to add the expense.
#define MMGC_PORTAPI_VALIDATE_PAGE_SIZE
#ifdef MMGC_PORTAPI_VALIDATE_PAGE_SIZE
extern int MMGC_PortAPI_GetPageSize_Imp();
#define MMGC_PortAPI_GetPageSize() MMGC_PortAPI_GetPageSize_Imp()
#else
#define MMGC_PortAPI_GetPageSize() 4096
#endif

// No implementation of CleanStack required.
#define MMGC_PortAPI_CleanStack(_force) (void)_force

extern uintptr_t MMGC_PortAPI_GetStackTop_Imp();
#define MMGC_PortAPI_GetStackTop() MMGC_PortAPI_GetStackTop_Imp()

extern uint64_t MMGC_PortAPI_Time_Imp();
#define MMGC_PortAPI_Time() MMGC_PortAPI_Time_Imp()

extern uint64_t MMGC_PortAPI_Frequency_Imp();
#define MMGC_PortAPI_Frequency() MMGC_PortAPI_Frequency_Imp()

#endif /* __mmgc_portapi__ */
