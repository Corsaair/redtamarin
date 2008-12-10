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

#ifndef __avmplus_BitSet__
#define __avmplus_BitSet__


namespace avmplus
{
	/**
	 * Bit vectors are an efficent method of keeping True/False information 
	 * on a set of items or conditions. Class BitSet provides functions 
	 * to manipulate individual bits in the vector.
	 *
	 * Since most vectors are rather small an array of machine words is used by
	 * default to house the value of the bits.  If more bits are needed
	 * then an array is allocated dynamically outside of this object. 
	 * 
	 * This object is not optimized for a fixed sized bit vector
	 * it instead allows for dynamically growing the bit vector.
	 */ 
	class BitSet: public MMgc::GCFinalizedObject
	{
        private:
            uintptr_t *getbits() {
                return capacity > kDefaultCapacity ? bits.ptr : bits.ar;
            }
            const uintptr_t *getbits() const {
                return capacity > kDefaultCapacity ? bits.ptr : bits.ar;
            }
			static const uintptr_t kOne = 1;

		public:

			enum {  kUnit = 8*sizeof(uintptr_t),
					kDefaultCapacity = 4   };

            BitSet() : capacity(kDefaultCapacity)
            {
                reset();
            }

            BitSet(MMgc::GC *gc, int bitcap=kDefaultCapacity*kUnit) : capacity(kDefaultCapacity)
			{
                reset();
                int cap = ((bitcap+kUnit-1)/kUnit);
                if (cap > kDefaultCapacity)
                    grow(gc, cap);
			}

			virtual ~BitSet() {
				if (capacity > kDefaultCapacity) {
					uintptr_t *p = bits.ptr;
					MMgc::GC::GetGC(p)->Free(p);
					bits.ptr = 0;
					capacity = kDefaultCapacity;
				}
			}

            void reset()
            {
                uintptr_t *bits = getbits();
                for (int i=0, n = capacity; i < n; i++)
                    bits[i] = 0;
            }

            void set(MMgc::GC *gc, int bitNbr)
			{
				int index = bitNbr / kUnit;
				int bit = bitNbr % kUnit;
                int cap = this->capacity;
                if (index >= cap) {
                    cap *= 2;
                    while (index >= cap) {
                        cap *= 2;
                    }
					grow(gc, cap);
                }
    			getbits()[index] |= kOne << bit;
			}

			void clear(int bitNbr)
			{
				int index = bitNbr / kUnit;
				int bit = bitNbr % kUnit;
				if (index < capacity)
                    getbits()[index] &= ~(kOne << bit);
			}

			bool get(int bitNbr) const
			{
				int index = bitNbr / kUnit;
				int bit = bitNbr % kUnit;
                return index < capacity && (getbits()[index] & kOne<<bit) != 0;
			}

            uintptr_t setFrom(MMgc::GC *gc, BitSet &other) {
                int c = other.capacity;
                if (c > capacity)
                    grow(gc, c);
                uintptr_t *bits = getbits();
                uintptr_t *otherbits = other.getbits();
                uintptr_t newbits = 0;
                for (int i=0; i < c; i++) {
                    uintptr_t b = bits[i];
                    uintptr_t b2 = otherbits[i];
                    newbits |= b2 & ~b; // bits in b2 that are not in b
                    bits[i] = b|b2;
                }
                return newbits;
            }

		private:

			// Grow the array until at least newCapacity big
			void grow(MMgc::GC *gc, int newCapacity)
			{
				//MEMTAG("BitVector::Grow - uintptr_t[]");
				uintptr_t* newBits = (uintptr_t*)gc->Alloc(newCapacity * sizeof(uintptr_t), MMgc::GC::kZero);

				// copy the old one 
                uintptr_t *bits = getbits();
                for (int i=0, n=capacity; i < n; i++)
                    newBits[i] = bits[i];

				// in with the new out with the old
				if (capacity > kDefaultCapacity)
					gc->Free(bits);

                if (gc->IsPointerToGCPage(this))
    				WB(gc, this, &this->bits.ptr, newBits);
                else
                    this->bits.ptr = newBits;
				capacity = newCapacity;
			}

			// by default we use the array, but if the vector 
			// size grows beyond kDefaultCapacity we allocate
			// space dynamically.
			int capacity;
			union
			{
				uintptr_t ar[kDefaultCapacity];
				uintptr_t*  ptr;
			}
			bits;
	};
	
	// a simpler version of BitSet that doesn't dynamically grow,
	// and doesn't require allocation for <=31 (or 63) size. This expects
	// to be embedded as a member variable in a GCObject and will
	// use WB if allocation is necessary.
	class FixedBitSet
	{
	public:
		inline explicit FixedBitSet() : m_bits(0) 
		#ifdef _DEBUG
			, m_cap(0)
		#endif
		{
		}
		
		// blows away existing content, sets all bits to 0
		inline void resize(MMgc::GC* gc, uint32_t cap)
		{
			const uint32_t MAX_INLINE_BITS = BITS_PER_UINTPTR - 1;
			if (cap > MAX_INLINE_BITS)
			{
				// always allocate one more bit than we need to simplify the logic elsewhere (bit 0 goes unused)
				const uint32_t sz = (cap + (BITS_PER_UINTPTR - 1) + 1) / sizeof(uintptr_t);
				uintptr_t* v = (uintptr_t*)gc->Alloc(sz, MMgc::GC::kZero);
				void* beginning =  gc->FindBeginning(this);
				if (beginning)
				{
					WB(gc, beginning, &m_bits, v);
				}
				else
				{
					m_bits = uintptr_t(v);
				}
			}
			else
			{
				m_bits = 0x1;
			}
		#ifdef _DEBUG
			m_cap = cap;
		#endif
		}

		inline void set(uint32_t bit)
		{
			AvmAssert(bit < m_cap);
			uintptr_t* v = (m_bits & 1) ? &m_bits : (uintptr_t*)m_bits;
			const uint32_t nbit = bit + 1;
			v[nbit / BITS_PER_UINTPTR] |= (uintptr_t(1) << (nbit & (BITS_PER_UINTPTR-1)));
		}

		inline void clr(uint32_t bit)
		{
			AvmAssert(bit < m_cap);
			uintptr_t* v = (m_bits & 1) ? &m_bits : (uintptr_t*)m_bits;
			const uint32_t nbit = bit + 1;
			v[nbit / BITS_PER_UINTPTR] &= ~(uintptr_t(1) << (nbit & (BITS_PER_UINTPTR-1)));
		}
		
		inline bool test(uint32_t bit) const
		{
			AvmAssert(bit < m_cap);
			const uintptr_t* v = (m_bits & 1) ? &m_bits : (const uintptr_t*)m_bits;
			const uint32_t nbit = bit + 1;
			return (v[nbit / BITS_PER_UINTPTR] & (uintptr_t(1) << (nbit & (BITS_PER_UINTPTR-1)))) != 0;
		}

		inline size_t allocatedSize()
		{
			return ((m_bits & 1) || (m_bits == 0)) ? 0 : MMgc::GC::Size((void*)m_bits);
		}

		#ifdef _DEBUG
		inline uint32_t cap() const { return uint32_t(m_cap); }
		#endif

	private:
		enum { BITS_PER_UINTPTR = sizeof(uintptr_t)*8 };
	private:
		uintptr_t m_bits;	// low bit 1 == inline, low bit 0 == dynamic alloc
		#ifdef _DEBUG
		uintptr_t m_cap;
		#endif
	};
	
}

#endif /* __avmplus_BitSet__ */
