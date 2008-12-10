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

#include "avmplus.h"

using namespace MMgc;

namespace avmplus
{	
	void MultinameHashtable::grow()
	{
		// double our table
		int capacity = numQuads*2;
		MMgc::GC* gc = MMgc::GC::GetGC(this);
		MMGC_MEM_TYPE(this);
		Quad* newAtoms = (Quad *) gc->Calloc(capacity, sizeof(Quad), GC::kContainsPointers|GC::kZero);
		rehash(m_quads, numQuads, newAtoms, capacity);
		gc->Free(m_quads);
		WB(gc, this, &m_quads, newAtoms);
		numQuads = capacity;
	}

	Binding MultinameHashtable::getMulti(const Multiname* mname) const
	{
		// multiname must not be an attr name, have wildcards, or have runtime parts.
		AvmAssert(mname->isBinding() && !mname->isAnyName());

		if (!mname->isNsset())
			return get(mname->getName(), mname->getNamespace());
		else
			return get(mname->getName(), mname->getNsset());
	}

	void MultinameHashtable::add(Stringp name, Namespacep ns, Binding value)
	{
		if (isFull())
		{
			grow();
		}
		put(name, ns, value);
	}

	MultinameHashtable::MultinameHashtable(int capacity) : 
		m_quads(NULL),
		size(0),
		numQuads(0)
	{
		Init(capacity);
#ifdef MH_CACHE1
		m_cache1.name = 0;
		m_cache1.ns = 0;
		m_cache1.value = 0;
		m_cache1.multiNS = 0;
#endif
	}

	void MultinameHashtable::Init(int capacity)
	{
		if (capacity)
		{
			numQuads = MathUtils::nextPowerOfTwo(capacity);

			MMgc::GC* gc = MMgc::GC::GetGC(this);

			AvmAssert(numQuads > 0);
			MMGC_MEM_TYPE(this);
			Quad* newAtoms = (Quad *) gc->Alloc (sizeof(Quad) * numQuads, GC::kContainsPointers|GC::kZero);
			WB(gc, this, &m_quads, newAtoms);
		}
	}

	MultinameHashtable::~MultinameHashtable()
	{
		GC *gc = GC::GetGC(this);
		gc->Free(m_quads);
	}

	bool MultinameHashtable::isFull() const
	{ 
		// 0.80 load factor
		return 5*(size+1) >= numQuads*4; 
	}

	int MultinameHashtable::find(Stringp name, Namespacep ns, const Quad* t, unsigned m)
	{
		AvmAssert(name != NULL && ns != NULL);

		// this is a quadratic probe but we only hit every third slot since those hold keys.
		int n = 7;

		int bitmask = (m - 1);

		// Note: Mask off MSB to avoid negative indices.  Mask off bottom
		// 3 bits because it doesn't contribute to hash.  Quad it
		// because names, namespaces, and values are stored adjacently.
		unsigned i = ((0x7FFFFFF8 & (uintptr)name) >> 3) & bitmask;
		Stringp k;
		while (((k=t[i].name) != name || t[i].ns != ns) && k != NULL)
		{
			i = (i + (n++)) & bitmask;			// quadratic probe
		}
		return i;
	}

#ifdef MH_CACHE1
	Binding MultinameHashtable::_get(Stringp mnameName, NamespaceSetp nsset) const
#else
	Binding MultinameHashtable::get(Stringp mnameName, NamespaceSetp nsset) const
#endif
	{
		int nsCount = nsset->size;
		int j;

		Binding match = BIND_NONE;

		// this is a quadratic probe but we only hit every third slot since those hold keys.
		int n = 7;
		int bitMask = numQuads - 1;

		// Note: Mask off MSB to avoid negative indices.  Mask off bottom
		// 3 bits because it doesn't contribute to hash.  Quad it
		// because names, namespaces, and values are stored adjacently.
		unsigned i = ((0x7FFFFFF8 & (uintptr)mnameName)>>3) & bitMask;
		Stringp atomName;

		const Quad* t = m_quads;
		while ((atomName = t[i].name) != EMPTY)
		{
			if (atomName == mnameName)
			{
				Namespacep ns = t[i].ns;
				for (j=0; j < nsCount; j++)
				{
					if (ns == nsset->namespaces[j])
					{
						match = t[i].value;
						goto found1;
					}
				}
			}

			i = (i + (n++)) & bitMask;			// quadratic probe
		}

		return BIND_NONE;

found1:
		if(t[i].multiNS)
		{
			int k = (i + (n++)) & bitMask;			// quadratic probe
			while ((atomName = t[k].name) != EMPTY)
			{
				if (atomName == mnameName)
				{
					Namespacep ns = t[k].ns;
					for (j=0; j < nsCount; j++)
					{
						if (ns == nsset->namespaces[j] && match != t[k].value)
						{
							return BIND_AMBIGUOUS;
						}
					}
				}
				k = (k + (n++)) & bitMask;			// quadratic probe
			}
		}
#ifdef MH_CACHE1
		m_cache1 = t[i];
#endif
		return match;
	}

	void MultinameHashtable::put(Stringp name, Namespacep ns, Binding value)
	{
		AvmAssert(!isFull());

		GC* gc = GC::GetGC(m_quads);
		int i = find(name, ns, m_quads, numQuads);
		Quad& t = m_quads[i];
		if (t.name == name)
		{
			// This <name,ns> pair is already in the table
			AvmAssert(t.ns == ns);
		}
		else
		{
			bool multiNS = getName(name) != BIND_NONE;

			// New table entry for this <name,ns> pair
			size++;
			//quads[i] = name;
			WBRC(gc, m_quads, &t.name, name);
			//quads[i+1] = ns;
			WBRC(gc, m_quads, &t.ns, ns);

			if(multiNS)
			{
				Quad* cur = m_quads;
				for(int i = numQuads; i--; cur++)
					if(cur->name == name)
						cur->multiNS = (unsigned)-1;
			}
		}

		//quads[i+2] = value;
		WB(gc, m_quads, &t.value, value);
#ifdef MH_CACHE1
		m_cache1 = t;
#endif
	}

#ifdef MH_CACHE1
	Binding MultinameHashtable::_get(Stringp name, Namespacep ns) const
#else
	Binding MultinameHashtable::get(Stringp name, Namespacep ns) const
#endif
	{
		const Quad* t = m_quads;
		int i = find(name, ns, t, numQuads);
		if (t[i].name == name)
		{
			const Quad& tf = t[i];
			AvmAssert(tf.ns == ns);
#ifdef MH_CACHE1
			m_cache1 = tf;
#endif
			return tf.value;
		}
		return BIND_NONE;
	}

#ifdef MH_CACHE1
	Binding MultinameHashtable::_getName(Stringp name) const
#else
	Binding MultinameHashtable::getName(Stringp name) const
#endif
	{
		const Quad* t = m_quads;
		for (int i=0, n=numQuads; i < n; i++)
		{
			if (t[i].name == name)
			{
				const Quad& tf = t[i];

#ifdef MH_CACHE1
				m_cache1 = tf;
#endif
				return tf.value;
			}
		}
		return BIND_NONE;
	}

	void MultinameHashtable::rehash(const Quad* oldAtoms, int oldTriplet, Quad* newAtoms, int newTriplet)
	{
		for (int i=0, n=oldTriplet; i < n; i++)
		{
			Stringp oldName;
			if ((oldName=oldAtoms[i].name) != EMPTY)
			{
				// inlined & simplified version of put()
				int j = find(oldName, oldAtoms[i].ns, newAtoms, newTriplet);
				newAtoms[j].name = oldName;
				newAtoms[j].ns = oldAtoms[i].ns;
				newAtoms[j].value = oldAtoms[i].value;
				newAtoms[j].multiNS = oldAtoms[i].multiNS;
			}
		}
	}

	Stringp MultinameHashtable::keyAt(int index) const
	{
		AvmAssert(m_quads[index-1].name != NULL);
		return m_quads[index-1].name;
	}

	Namespacep MultinameHashtable::nsAt(int index) const
	{
		return m_quads[index-1].ns;
	}

	Binding MultinameHashtable::valueAt(int index) const
	{
		return m_quads[index-1].value;
	}

	// call this method using the previous value returned
	// by this method starting with 0, until 0 is returned.
	int MultinameHashtable::next(int index) const
	{
		// Advance to first non-empty slot.
		const Quad* t = m_quads;
		while (index < numQuads) {
			if (t[index++].name != NULL) {
				return index;
			}
		}
		return 0;
	}	
}

