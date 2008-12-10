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


// For memset
#include <string.h>

#include "MMgc.h"

namespace MMgc
{
	FixedMalloc *FixedMalloc::instance = NULL;

	// Size classes for our Malloc.  We start with a 4 byte allocator and then from
	// 8 to 128, size classes are spaced evenly 8 bytes apart, then from 128 to 1968 they
#ifdef MMGC_AMD64
	// The upper entries of the table (>128) are sized to 
	// match the kSizeClassIndex which uses the number-of-entries
	// per block to pick an allocator.  For example, if you want to 
	// allocate a 798 byte object, it gets rounded up to 800 and then
	// 4032/800 = 5.04 so you look up kSizeClassIndex[5] and get 37 which
	// returns the allocator size to allocate 800 bytes per alloc.  The 800
	// was picked to be just larger than the maximum 5-per-block size
	// that would fit (4032/5=804 down to 800) rounded down to the next 
	// lowest 8 bytes.  If someone was allocating 801 bytes, it would get rounded
	// up to 808 and then go into the 4-per-block allocator (4032/808=4.99).

	const int16 FixedMalloc::kSizeClasses[kNumSizeClasses] = {
		8, 16, 24, 32, 40, 48, 56, 64, 72, 80, //0-9
		88, 96, 104, 112, 120, 128,	136, 144, 152, 160, //10-19
		168, 176, 192, 208, 224, 232, 248, 264, 288, 304, //20-29
		336, 360, 400, 448, 504, 576, 672, 800, 1008, 1344, //30-39
		2016, //40
	};

	// This is an index which indicates that allocator i should be used
	// if kSizeClassIndex[i] items fit into a 4096 byte page.
	const uint8 FixedMalloc::kSizeClassIndex[32] = {
		40, 40, 40, 39, 38, 37, 36, 35, 34, 33, //0-9
		32, 31, 30, 29, 28, 27, 26, 25, 24, 23, //10-19
		23, 22, 21, 20, 20, 19, 18, 17, 17, 16, //20-29
		15, 15  //30-31
	};
	/*
	const int16 FixedMalloc::kSizeClasses[kNumSizeClasses] = {
		4, 8, 16, 24, 32, 40, 48, 56, 64, 72, //0-9
		80, 88, 96, 104, 112, 120, 128,	144, 160, 168, //10-19
        183, 192, 201, 211, 224, 235, 251, 267, 288, 310, //20-29
		336, 366, 403, 448, 504, 576, 672, 806, 1008, 1344, //30-39
		2032, //40
	};

	const uint8 FixedMalloc::kSizeClassIndex[32] = {
		40, 40, 40, 39, 38, 37, 36, 35, 34, 33, //0-10
		32, 31, 30, 29, 28, 27, 26, 25, 24, 23, //10-19
		22, 21, 20, 19, 19, 18, 18, 18, 17, 17, //20-29
		17, 16  //30-31
	};
	*/

#else
	const int16 FixedMalloc::kSizeClasses[kNumSizeClasses] = {
		4, 8, 16, 24, 32, 40, 48, 56, 64, 72, //0-9
		80, 88, 96, 104, 112, 120, 128,	144, 160, 176, //10-19
        184, 192, 200, 208, 224, 232, 248, 264, 288, 312, //20-29
		336, 368, 400, 448, 504, 576, 672, 808, 1016, 1352, //30-39
		2032, //40
	};

	// This is an index which indicates that allocator i should be used
	// if kSizeClassIndex[i] items fit into a 4096 byte page.
	const uint8 FixedMalloc::kSizeClassIndex[32] = {
		40, 40, 40, 39, 38, 37, 36, 35, 34, 33, //0-10
		32, 31, 30, 29, 28, 27, 26, 25, 24, 23, //10-19
		22, 21, 20, 19, 19, 18, 18, 18, 17, 17, //20-29
		17, 16  //30-31
	};

#endif
	void FixedMalloc::Init()
	{
		GCAssert(instance == NULL);
		instance = new FixedMalloc(GCHeap::GetGCHeap());
	}

	void FixedMalloc::Destroy()
	{
		GCAssert(instance != NULL);
		delete instance;
		instance = NULL;
	}

	FixedMalloc::FixedMalloc(GCHeap* heap)
	{
		m_heap = heap;
		numLargeChunks = 0;
		// Create all the allocators up front (not lazy)
		// so that we don't have to check the pointers for
		// NULL on every allocation.
		for (int i=0; i<kNumSizeClasses; i++) {
			// FIXME: by default FixedAlloc uses 4K chunks, for the
			// more common size classes maybe we should use 8/16/32.
			// FIXME: we could use FixedAllocLarge for the bigger size 
			// classes but how to call the right Free would need to be work out
			m_allocs[i] = new FixedAllocSafe(kSizeClasses[i], heap);
		}

#ifdef _DEBUG 
		// sanity check our tables
		for (int size8 = 136; size8 < 2016; size8 += 8)
		{
			int foo = kPageUsableSpace/(size8);
			unsigned index = kSizeClassIndex[foo];

			// Given our foo index, this is the maximum sized alloc that may occur
			// and need to fit into the m_alloc[index] value.
			unsigned maxsize = (kPageUsableSpace / foo) & ~0x7;

			// assert that I fit
			GCAssert(maxsize <= (m_allocs[index]->GetItemSize()));

			// assert that I don't fit (makes sure we don't waste space)
			GCAssert(maxsize > (m_allocs[index-1]->GetItemSize()));
		}
#endif
	}

	FixedMalloc::~FixedMalloc()
	{
		for (int i=0; i<kNumSizeClasses; i++) {
			FixedAllocSafe *a = m_allocs[i];
			delete a;
		}		
	}

	size_t FixedMalloc::GetBytesInUse()
	{
		size_t bytes = 0;
		for (int i=0; i<kNumSizeClasses; i++) {
			FixedAllocSafe *a = m_allocs[i];
			bytes += a->GetBytesInUse();
		}
		// not entirely accurate
		bytes += numLargeChunks * GCHeap::kBlockSize;
		return bytes;
	}

	FixedAllocSafe *FixedMalloc::FindSizeClass(size_t size) const
	{
		GCAssertMsg(size > 0, "cannot allocate a 0 sized block\n");

		uint32 size8 = (uint32)((size+7)&~7); // round up to multiple of 8

		// Buckets up to 128 are spaced evenly at 8 bytes.
		if (size <= 128) {
#ifdef MMGC_AMD64
			unsigned index = size8 ? ((size8 >> 3) - 1) : 0;
#else
			unsigned index = size > 4 ? size8 >> 3 : 0;
#endif
			FixedAllocSafe *a = m_allocs[index];
			// make sure I fit
			GCAssert(size <= a->GetItemSize());

			// make sure I don't fit
			GCAssert(index == 0 || size > m_allocs[index-1]->GetItemSize());
				
			return a;
		}

		// This is the fast lookup table implementation to
		// find the right allocator.
		// FIXME: do this w/o division!
		unsigned index = kSizeClassIndex[kPageUsableSpace/size8];

		// assert that I fit
		GCAssert(size <= m_allocs[index]->GetItemSize());

		// assert that I don't fit (makes sure we don't waste space
		GCAssert(size > m_allocs[index-1]->GetItemSize());

	    return m_allocs[index];
	}

	void *FixedMalloc::LargeAlloc(size_t size)
	{
		size += DebugSize();
		int blocksNeeded = (int)GCHeap::SizeToBlocks(size);
		void *item = m_heap->Alloc(blocksNeeded, true, false);
		if(!item)
		{
			GCAssertMsg(item != NULL, "Large allocation failed!");
		}
		else
		{
			numLargeChunks += blocksNeeded;
#ifdef MEMORY_INFO
			item = DebugDecorate(item, size, 5);
			memset(item, 0xfb, size - DebugSize());
#endif
		}
		return item;
	}
	
	
	void FixedMalloc::LargeFree(void *item)
	{
#ifdef MEMORY_INFO
		item = DebugFree(item, 0xed, 5);
#endif
		numLargeChunks -= GCHeap::SizeToBlocks(LargeSize(item));
		m_heap->Free(item);
	}
	
	size_t FixedMalloc::LargeSize(const void *item)
	{
		return m_heap->Size(item) * GCHeap::kBlockSize;
	}

	size_t FixedMalloc::GetTotalSize()
	{
		size_t total = numLargeChunks;
		for (int i=0; i<kNumSizeClasses; i++) {
			FixedAllocSafe *a = m_allocs[i];
			total += a->GetNumChunks();
		}	
		return total;
	}
}

