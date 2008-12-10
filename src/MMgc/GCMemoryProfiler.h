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

#ifndef __GCMemoryProfiler__
#define __GCMemoryProfiler__


#ifdef FEATURE_SAMPLER
// Sampling support
namespace avmplus
{
	class Sampler;
}
#endif


#ifdef FEATURE_SAMPLER
namespace MMgc
{
	extern GCThreadLocal<avmplus::Sampler*> m_sampler;
	extern bool sampling;
	void recordAllocationSample(void* item, size_t size, bool in_lock = false);
	void recordDeallocationSample(const void* item, size_t size);
}
#endif
#ifndef MEMORY_INFO

#define MMGC_MEM_TAG(_x)
#define MMGC_MEM_TYPE(_x)
#define GetRealPointer(_x) _x
#define GetUserPointer(_x) _x
#define DebugSize() 0
#else

#define MMGC_MEM_TAG(_x) MMgc::SetMemTag(_x)
#define MMGC_MEM_TYPE(_x) MMgc::SetMemType(_x)

namespace MMgc
{
	MMGC_API void SetMemTag(const char *memtag);
	MMGC_API void SetMemType(const void *memtype);

	/**
	 * calculate a stack trace skipping skip frames and return index into
	 * trace table of stored trace
	 */
	unsigned int GetStackTraceIndex(int skip);
	unsigned int LookupTrace(int *trace);
	void ChangeSize(int traceIndex, int delta);
	void DumpFatties();

	/**
	* Manually set me, for special memory not new/deleted, like the code memory region
	*/
	MMGC_API void ChangeSizeForObject(void *object, int size);

	/**
	* How much extra size does DebugDecorate need?
	*/
	MMGC_API size_t DebugSize();

	/**
	* decorate memory with debug information, return pointer to memory to return to caller
	*/
	MMGC_API void *DebugDecorate(void *item, size_t size, int skip);

	/** 
	* Given a pointer to user memory do debug checks and return pointer to real memory
	*/
	void *DebugFree(const void *item, int poison, int skip);		

	/**
	* Given a pointer to real memory do debug checks and return pointer to user memory
	*/
	void *DebugFreeReverse(void *item, int poison, int skip);

	/**
	* Given a user pointer back up to real beginning
	*/
	inline void *GetRealPointer(const void *item) { return (void*)((uintptr) item -  2 * sizeof(int)); }

	/**
	* Given a user pointer back up to real beginning
	*/
	inline void *GetUserPointer(const void *item) { return (void*)((uintptr) item +  2 * sizeof(int)); }

	const char* GetTypeName(int index, void *obj);

	void GetInfoFromPC(sintptr pc, char *buff, int buffSize);
	void GetStackTrace(sintptr *trace, int len, int skip);
	// print stack trace of index into trace table
	void PrintStackTraceByIndex(int index);
	MMGC_API void PrintStackTrace(const void *item);
	// print stack trace of caller
	void DumpStackTrace(int skip=1);

}

#endif //MEMORY_INFO
#endif //!__GCMemoryProfiler__

