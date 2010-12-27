/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
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

#include "SymbianJITHeap.h"

#include "MMgc.h" // for AvmAssert
#include "AvmDebug.h" // for AvmAssert

SymbianJITHeap::SymbianJITHeap()
{
    m_numAllocs = 0;
    m_startAddr = 0;
    m_currentMaxMem = 0;
    m_previousFree = 0;

    memset(m_map, 0, sizeof(TUint)*kMaxMap);
    SetupBitLookup();

    if(m_chunk.CreateLocalCode(0, kMaxHeapSize) == KErrNone)
    {
        m_startAddr = (TUint)m_chunk.Base();
    }
}

SymbianJITHeap::~SymbianJITHeap()
{
    m_chunk.Close();
}

bool SymbianJITHeap::IsInitialized()
{
    return m_startAddr != 0;
}

TInt SymbianJITHeap::GetNumAllocs()
{
    return m_numAllocs;
}

void* SymbianJITHeap::Alloc()
{
    int chunkIndex = GetEmptyChunkIndex();
    // FIXME https://bugzilla.mozilla.org/show_bug.cgi?id=571407
    // It is really the task of VMPI_allocateCodeMemory to shut down the Player
    // in the event of a failure (not this function).
    if(chunkIndex == -1)
        return 0; // shut down Flash Player after this!
    TUint maxMem = (chunkIndex+1) * kPageSize; // could use shift in places like this but this is easier to read
    if(maxMem > m_currentMaxMem)
    {
        AvmAssert( maxMem == ((m_numAllocs+1) * kPageSize) ); // There should not be any empty slots
        maxMem += kHeapAdjustSize; // call Adjust for more than one chunk a time to improve performance
        if(m_chunk.Adjust(maxMem) != KErrNone)
        {
            // FIXME https://bugzilla.mozilla.org/show_bug.cgi?id=571407
            // It is really the task of VMPI_allocateCodeMemory to shut down the Player
            // in the event of a failure (not this function).
            // shut down Flash Player after this!
            return 0;
        }
        m_currentMaxMem = maxMem;
    }
    SetBit(chunkIndex); // mark as allocated
    void* ptr = (void*)(m_startAddr + chunkIndex * kPageSize);
    memset(ptr, 0, kPageSize);
    m_numAllocs ++;
    return ptr;
}

void SymbianJITHeap::Free(void* ptr)
{
    // assert that it's smaller than kMaxMap
    int chunkIndex = (((TUint)ptr)-m_startAddr) / kPageSize; // // could use shift in places like this but this is easier to read
    SetEmptyChunkIndex(chunkIndex);
    m_numAllocs --;
}

void SymbianJITHeap::SetupBitLookup()
{
    for(int i=0;i<256;i++)
    {
        int v = i;
        for(int j=0;j<8;j++)
        {
            if(!(v&1))
            {
                m_bitLookup[i] = j;
                break;
            }
            v >>= 1;
        }
    }
}

int SymbianJITHeap::GetEmptyBit(int arrayPos)
{
    TUint v = m_map[arrayPos];
    for(int i=0;i<4;i++) // max 4 iterations instead of 32 because of using a lookup
    {
        TUint8 b = v & 0xff;
        if(b != 0xff)
        {
            int bit = m_bitLookup[b];
            bit = bit + (i<<3); // *8
            return bit;
        }
        v >>= 8;
    }
    return -1;
}

void SymbianJITHeap::ClearBit(int mapPos)
{
    int arrayPos = mapPos>>5; // / kBitsInTUint
    int bit = mapPos & 31;
    int v = m_map[arrayPos];
    int mask = 1<<bit;
    v &= ~mask;
    m_map[arrayPos] = v;
}

void SymbianJITHeap::SetBit(int mapPos)
{
    int arrayPos = mapPos>>5; // / kBitsInTUint
    int bit = mapPos & 31;
    int v = m_map[arrayPos];
    int mask = 1<<bit;
    v |= mask;
    m_map[arrayPos] = v;
}

int SymbianJITHeap::GetEmptyChunkIndex()
{
    int i = m_previousFree;
    while(i<kMaxMap)
    {
        if(m_map[i] != 0xffffffff) // this loop can compare 128k a time because each bit = 4k chunk
            break;
        i++;
    }
    if(i==kMaxMap)
        return -1;

    m_previousFree = i;

    int bit = GetEmptyBit(i);

    return ((i<<5)+bit);
}

void SymbianJITHeap::SetEmptyChunkIndex(int index)
{
    if(index < m_previousFree)
        m_previousFree = index;
    ClearBit(index);
}
