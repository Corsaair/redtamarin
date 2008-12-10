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

#ifndef __avmplus_MultinameHashtable__
#define __avmplus_MultinameHashtable__

// the TC performance suites of sunspider, misc, and scimark show
// no meaningful performance difference with MH_CACHE1 enabled, thus 
// disabled for now until profiling evidence justifies it.
//#define MH_CACHE1

#ifdef MH_CACHE1
	#include "NamespaceSet.h"
#endif

namespace avmplus
{
	/**
	 * Hashtable for mapping <name, ns> pairs to a Binding
	 */
#ifdef AVMPLUS_TRAITS_MEMTRACK
	class MultinameHashtable : public MMgc::GCFinalizedObject
#else
	class MultinameHashtable : public MMgc::GCObject
#endif
	{
	private:
		class Quad // 33% better!
		{
		public:
			Stringp name;
			Namespacep ns;
			Binding value;
			// non-0 if the given name exists elsewhere w/ a different NS
			// (also the alignment gives a speed boost)
			uint32_t multiNS;
			#ifdef AVMPLUS_64BIT
			uint32_t padding;
			#endif
		};

	private:

		/**
		 * Finds the hash bucket corresponding to the key <name,ns>
		 * in the hash table starting at t, containing tLen
		 * quads.
		 */
		static int find(Stringp name, Namespacep ns, const Quad *t, unsigned tLen);
	    void rehash(const Quad *oldAtoms, int oldlen, Quad *newAtoms, int newlen);

		/**
		 * Called to grow the Hashtable, particularly by add.
		 *
		 * - Calculates the needed size for the new Hashtable
		 *   (typically 2X the current size)
		 * - Creates a new array of Atoms
		 * - Rehashes the current table into the new one
		 * - Deletes the old array of Atoms and sets the Atom
		 *   pointer to our new array of Atoms
		 * 
		 */
		void grow();

	public:
		/**
		 * since identifiers are always interned strings, they can't be 0,
		 * so we can use 0 as the empty value.
		 */
		const static Atom EMPTY = 0;

		/** kDefaultCapacity must be a power of 2 */
		const static int kDefaultCapacity = 8;

		/**
		 * initialize with a known capacity.  i.e. we can fit minSize
		 * elements in without rehashing.
		 * @param heap
		 * @param capacity  # of logical slots
		 */
		MultinameHashtable(int capacity = kDefaultCapacity);

		~MultinameHashtable();

		bool isFull() const;

		/**
		 * @name operations on name/ns/binding quads
		 */
		/*@{*/
		void    put(Stringp name, Namespacep ns, Binding value);

#ifdef MH_CACHE1
		inline Binding getName(Stringp name) const
		{
			if (m_cache1.name == name)
				return m_cache1.value;
			return _getName(name);
		}
		inline Binding get(Stringp name, Namespacep ns) const
		{
			if (m_cache1.name == name && m_cache1.ns == ns)
				return m_cache1.value;
			return _get(name, ns);
		}
		inline Binding get(Stringp name, NamespaceSetp nsset) const
		{
			if (name == m_cache1.name && !m_cache1.multiNS)
			{
				for (int j = 0, n = nsset->size; j < n; j++)
					if (m_cache1.ns == nsset->namespaces[j])
						return m_cache1.value;
				return BIND_NONE;
			}
			return _get(name, nsset);
		}
		Binding _getName(Stringp name) const;
		Binding _get(Stringp name, Namespacep ns) const;
		Binding _get(Stringp name, NamespaceSetp nsset) const;
#else
		Binding get(Stringp name, Namespacep ns) const;
		Binding get(Stringp name, NamespaceSetp nsset) const;
		Binding getName(Stringp name) const;
#endif
		Binding getMulti(const Multiname* name) const;
		inline Binding getMulti(const Multiname& name) const { return getMulti(&name); }
		/*@}*/

		/**
		 * Adds a name/value pair to a hash table.  Automatically
		 * grows the hash table if it is full.
		 */
		void add(Stringp name, Namespacep ns, Binding value);

		/**
		 * Allow caller to enumerate all entries in the table.
		 */
		int next(int index) const;
		Stringp keyAt(int index) const;
		Namespacep nsAt(int index) const;
		Binding valueAt(int index) const;
		
		size_t allocatedSize() const { return numQuads * sizeof(Quad); }

	protected:
		void Init(int capacity);

	// ------------------------ DATA SECTION BEGIN
	private:	Quad* m_quads;			// property hashtable (written with explicit WB)
	public:		int size;				// no. of properties
	public:		int numQuads;			// size of hashtable 
#ifdef MH_CACHE1
	private:	mutable Quad m_cache1;	// single-level cache
#endif
	// ------------------------ DATA SECTION END
	};
}

#endif /* __avmplus_MultinameHashtable__ */
