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

#ifndef __avmplus_SortedIntMap__
#define __avmplus_SortedIntMap__


namespace avmplus
{
	/**
	 * The SortedIntMap<T> template implements an object that
	 * maps integer keys to values.	  The keys are sorted
	 * from smallest to largest in the map. Time of operations 
	 * is as follows: 
 	 *   put() is O(1) if the key is higher than any existing 
	 *         key; O(logN) if the key already exists,
     *         and O(N) otherwise. 
	 *   get() is an O(logN) binary search.
	 * 
	 * no duplicates are allowed.
	 */
	template <class T>
	class SortedIntMap : public MMgc::GCObject
	{
	public:
		enum { kInitialCapacity= 64 };
		
		SortedIntMap(int _capacity=kInitialCapacity)
		{
			init(0, _capacity, false, 0);
		}
		SortedIntMap(MMgc::GC* _gc, uint32 _capacity=kInitialCapacity, bool _livesInGCContainer=true, int _flags=MMgc::GC::kContainsPointers)
		{
			init(_gc, _capacity, _livesInGCContainer, _flags);
		}
		void init(MMgc::GC* _gc, uint32 _capacity, bool _livesInGCContainer, int _flags)
		{
			len = 0;
			max = 0;
			keys = NULL;
			values = NULL;
			this->gc = _gc;
			this->gcFlags = _flags;
			this->livesInGCContainer = _livesInGCContainer;
			ensureCapacity(_capacity);
		}
		~SortedIntMap()
		{
			if(gc)
			{
				gc->Free(keys);
				gc->Free(values);
			}
			else
			{
				delete [] keys;
				delete [] values;
			}
			max = 0;
			len = 0;
		}
		bool isEmpty() const
		{
			return len == 0;
		}
		int size() const
		{
			return len;
		}
		int capacity() const
		{
			return max;
		}
		void clear()
		{
			len = 0;
		}
		T put(sintptr k, T v)
		{
			if (len == 0 || k > keys[len-1])
			{
				if (len == max)
					grow();
				set(len, k, v);
				len++;
				return (T)v;
			}
			else
			{
				int i = find(k);		
				if (i >= 0)
				{
					T old = values[i];
					set(i, k, v);
					return old;
				}
				else
				{
					i = -i - 1; // recover the insertion point
					if (len == max)
						grow();
					arraycopy(keys,i,keys,i+1,len-i);
					arraycopy(values,i,values,i+1,len-i);
					set(i, k, v);
					len++;
					return (T)v;
				}
			}
		}
		T get(sintptr k) const
		{
			int i = find(k);
	        return i >= 0 ? values[i] : 0;
		}
		bool containsKey(sintptr k) const
		{
			int i = find(k);
			return (i >= 0) ? true : false;
		}
		T remove(sintptr k)
		{
			int i = find(k);
			return removeAt(i);
		}
		T removeAt(int i)
		{
			T old = (T)0;
			if (i >= 0)
			{
				old = values[i];
				arraycopy(keys, i+1, keys, i, len-i-1);
				arraycopy(values, i+1, values, i, len-i-1);
				len--;
			}
			return old;
		}

		T removeFirst() { return isEmpty() ? (T)0 : removeAt(0); }
		T removeLast()  { return isEmpty() ? (T)0 : removeAt(len-1); }
		T first() const { return isEmpty() ? (T)0 : values[0]; }
		T last()  const { return isEmpty() ? (T)0 : values[len-1]; }

		sintptr firstKey() const	{ return isEmpty() ? 0 : keys[0]; }
		sintptr lastKey() const		{ return isEmpty() ? 0 : keys[len-1]; }

		// you need to allocate the space for these
		int keyArray(sintptr* arr) { arraycopy(keys, 0, arr, 0, len); return len; }
		int valueArray(T* arr) { arraycopy(values, 0, arr, 0, len); return len; }

		// iterator 
		T	at(int i) const { return values[i]; }
		sintptr keyAt(int i) const { return keys[i]; }

	protected:
		T *values;
		sintptr *keys;
		int len;
		int max;

		MMgc::GC* gc;
		int reserved:28;
		int gcFlags:3;
		int livesInGCContainer:1;

		void set(int index, sintptr k, T v)
		{
			keys[index] = k;
			if (gc)
			{
				AvmAssert(sizeof(T) <= sizeof(int*)); // WB requries this...
				WB(gc, values, &values[index], v);
			}
			else
			{
				values[index] = v;
			}
		}
		int find(sintptr k) const
		{
			int lo = 0;
			int hi = len-1;

			while (lo <= hi)
			{
				int i = (lo + hi)/2;
				sintptr m = keys[i];
				if (k > m)
					lo = i + 1;
				else if (k < m)
					hi = i - 1;
				else
					return i; // key found
			}
			return -(lo + 1);  // key not found, low is the insertion point
		}
		void grow()
		{
			ensureCapacity(2*max);
		}
		void ensureCapacity(int32 cap)
		{			
			if(cap > max) 
			{
				T* newvalues = (gc) ? (T*) gc->Calloc(cap, sizeof(T), gcFlags) : new T[cap];
				sintptr* newkeys = (gc) ? (sintptr*) gc->Calloc(cap, sizeof(sintptr), 0) : new sintptr[cap];
				arraycopy(keys, 0, newkeys, 0 , len);
				arraycopy(values, 0, newvalues, 0 , len);
				if (gc)
				{
					gc->Free(keys);
					gc->Free(values);
				}
				else
				{
					delete [] keys;
					delete [] values;
				}

				if (gc && livesInGCContainer) 
				{
					WB(gc, gc->FindBeginning(this), &keys, newkeys);
					WB(gc, gc->FindBeginning(this), &values, newvalues);
				} 
				else 
				{
					keys = newkeys;
					values = newvalues;
				}
				max = cap;
			}
		}
		void arraycopy(sintptr* src, int srcStart, sintptr* dst, int dstStart, int nbr)
		{
			// we have 2 cases, either closing a gap or opening it.
			if ((src == dst) && (srcStart > dstStart) )
			{
				for(int i=0; i<nbr; i++)
					dst[i+dstStart] = src[i+srcStart];	
			}
			else
			{
				for(int i=nbr-1; i>=0; i--)
					dst[i+dstStart] = src[i+srcStart];
			}
		}
		void arraycopy(T* src, int srcStart, T* dst, int dstStart, int nbr)
		{
			// we have 2 cases, either closing a gap or opening it.
			if ((src == dst) && (srcStart > dstStart) )
			{
				for(int i=0; i<nbr; i++)
					dst[i+dstStart] = src[i+srcStart];	
			}
			else
			{
				for(int i=nbr-1; i>=0; i--)
					dst[i+dstStart] = src[i+srcStart];
			}
		}
	};

	/**
	 * The SortedMap<K,T> template implements an object that
	 * maps keys to values.	  The keys are sorted
	 * from smallest to largest in the map. Time of operations 
	 * is as follows: 
 	 *   put() is O(1) if the key is higher than any existing 
	 *         key; O(logN) if the key already exists,
     *         and O(N) otherwise. 
	 *   get() is an O(logN) binary search.
	 * 
	 * no duplicates are allowed.
	 */
  template <class K, class T, ListElementType valType>
	class SortedMap 
	{
	public:
		enum { kInitialCapacity= 64 };
		
		SortedMap(MMgc::GC* gc, int _capacity=kInitialCapacity)
		  : keys(gc, _capacity), values(gc, _capacity)
		{
		}
		
		bool isEmpty() const
		{
			return keys.size() == 0;
		}
		int size() const
		{
			return keys.size();
		}
		void clear()
		{
			keys.clear();
			values.clear();
		}
		void destroy()
		{
			keys.destroy();
			values.destroy();
		}
		T put(K k, T v)
		{
			if (keys.size() == 0 || k > keys.last()) 
			{
				MMGC_MEM_TYPE("avmplusSortedMap");
				keys.add(k);
				values.add(v);
				return (T)v;
			}
			else
			{
				int i = find(k);		
				if (i >= 0)
				{
					T old = values[i];
					keys.set(i, k);
					values.set(i, v);
					return old;
				}
				else
				{
					i = -i - 1; // recover the insertion point
					AvmAssert(keys.size() != (uint32_t)i);
					keys.insert(i, k);
					values.insert(i, v);
					return v;
				}
			}
		}
		T get(K k) const
		{
			int i = find(k);
			return i >= 0 ? values[i] : 0;
		}
		bool get(K k, T& v) const
		{
			int i = find(k);
			if (i >= 0)
			{
				v = values[i];
				return true;
			}
			return false;
		}
		bool containsKey(K k) const
		{
			int i = find(k);
			return (i >= 0) ? true : false;
		}
		T remove(K k)
		{
			int i = find(k);
			return removeAt(i);
		}
		T removeAt(int i)
		{
			T old = values.removeAt(i);
			keys.removeAt(i);
			return old;
		}

		T removeFirst() { return isEmpty() ? (T)0 : removeAt(0); }
		T removeLast()  { return isEmpty() ? (T)0 : removeAt(keys.size()-1); }
		T first() const { return isEmpty() ? (T)0 : values[0]; }
		T last()  const { return isEmpty() ? (T)0 : values[keys.size()-1]; }

		K firstKey() const	{ return isEmpty() ? 0 : keys[0]; }
		K lastKey() const	{ return isEmpty() ? 0 : keys[keys.size()-1]; }

		// iterator 
		T	at(int i) const { return values[i]; }
		K   keyAt(int i) const { return keys[i]; }

		int findNear(K k) const {
			int i = find(k);
			return i >= 0 ? i : -i-2;
		}
	protected:
		List<K, LIST_NonGCObjects> keys;
		List<T, valType> values;
		
		int find(K k) const
		{
			int lo = 0;
			int hi = keys.size()-1;

			while (lo <= hi)
			{
				int i = (lo + hi)/2;
				K m = keys[i];
				if (k > m)
					lo = i + 1;
				else if (k < m)
					hi = i - 1;
				else
					return i; // key found
			}
			return -(lo + 1);  // key not found, low is the insertion point
		}
	private:
		// cannot instantiate dynamically, use GCSortedMap instead
		void* operator new(size_t size); // unimplemented
		void* operator new(size_t size, MMgc::GC* gc); // unimplemented
#if defined(REQUIRE_DELETE_OPERATOR)
		void operator delete(void*) {}
		void operator delete(void*, MMgc::GC*) {}
#endif
	};

	template <class K, class T, ListElementType valType>
	class GCSortedMap : public MMgc::GCFinalizedObject
	{
	private:
		typedef SortedMap<K, T, valType> MapType;
		MapType map;
	public:
		GCSortedMap(MMgc::GC* gc, int _capacity=MapType::kInitialCapacity)
		  : map(gc, _capacity)
		{
		}

		inline bool isEmpty() const { return map.isEmpty(); }
		inline int size() const { return map.size(); }
		inline void clear() { map.clear(); }
		inline T put(K k, T v) { return map.put(k, v); }
		inline T get(K k) const { return map.get(k); }
		inline bool get(K k, T& v) const { return map.get(k, v); }
		inline bool containsKey(K k) const { return map.containsKey(k); }
		inline T remove(K k) { return map.remove(k); }
		inline T removeAt(int i) { return map.removeAt(i); }
		inline T removeFirst() { return map.removeFirst(); }
		inline T removeLast()  { return map.removeLast(); }
		inline T first() const { return map.first(); }
		inline T last()  const { return map.last(); }
		inline K firstKey() const	{ return map.firstKey(); }
		inline K lastKey() const	{ return map.lastKey(); }
		inline T	at(int i) const { return map.at(i); }
		inline K   keyAt(int i) const { return map.keyAt(i); }
		inline int findNear(K k) const { return map.findNear(k); }
	};
}

#endif /* __avmplus_SortedIntMap__ */
