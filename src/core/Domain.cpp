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


#include "avmplus.h"

#ifdef SOLARIS
typedef caddr_t maddr_ptr;
#else
typedef void *maddr_ptr;
#endif

namespace avmplus
{
	Domain::Domain(AvmCore *_core, Domain* base) : base(base)
#ifdef AVMPLUS_MOPS
		  , core(_core)
		  , globalMemoryBase(m_gmInfo.globalMemoryScratch)
		  , globalMemorySize(sizeof(m_gmInfo.globalMemoryScratch))
#endif
	{
#ifdef AVMPLUS_MOPS
		m_gmInfo.globalMemory = NULL;
		// should be able to contain largest read or write (currently double)
		AvmAssert(sizeof(m_gmInfo.globalMemoryScratch) >= sizeof(double));
#endif
		namedTraits  = new (_core->GetGC()) MultinameHashtable();
		namedScripts = new (_core->GetGC()) MultinameHashtable();
	}

	Traits* Domain::getNamedTraits(Stringp name, Namespacep ns, bool recursive/*=true*/) const
	{
		Traits *traits = NULL;
		if (recursive && base) {
			traits = base->getNamedTraits(name, ns, true);
		}
		if (!traits) {
			traits = (Traits*) namedTraits->get(name, ns);
		}
		return traits;
	}

	Traits* Domain::getNamedTraits(const Multiname *multiname, bool recursive/*=true*/) const
	{
		Traits *traits = NULL;
		if (recursive && base) {
			traits = base->getNamedTraits(multiname, true);
		}
		if (!traits) {
			traits = (Traits*) namedTraits->getMulti(multiname);
		}
		return traits;
	}
	
	AbstractFunction* Domain::getNamedScript(Stringp name, Namespacep ns) const
	{
		AbstractFunction *f = NULL;
		if (base) {
			f = base->getNamedScript(name, ns);
		}
		if (!f) {
			f = (AbstractFunction*) namedScripts->get(name, ns);
		}
		return f;
	}

	AbstractFunction* Domain::getNamedScript(const Multiname *multiname) const
	{
		AbstractFunction *f = NULL;
		if (base) {
			f = base->getNamedScript(multiname);
		}
		if (!f) {
			f = (AbstractFunction*) namedScripts->getMulti(multiname);
		}
		return f;
	}

#ifdef AVMPLUS_MOPS
	bool Domain::setGlobalMemory(ScriptObject *mem) const
	{
		if(!mem)
		{
			// null obj -- use scratch
			if(m_gmInfo.globalMemory) // unsubscribe from current if any
				globalMemoryUnsubscribe(m_gmInfo.globalMemory);
			// remember NULL obj
			m_gmInfo.globalMemory = NULL;
			// point at scratch mem
			notifyGlobalMemoryChanged(m_gmInfo.globalMemoryScratch, sizeof(m_gmInfo.globalMemoryScratch));
		}
		else if(!globalMemorySubscribe(mem))
		{
			// failed... do nothing
			return false;
		}
		else
		{
			// success on globalMemorySubscribe would have led to notifyGlobalMemoryChanged
			// success... unsubscribe from original
			if(m_gmInfo.globalMemory)
				globalMemoryUnsubscribe(m_gmInfo.globalMemory);
			// remember the new one
			m_gmInfo.globalMemory = mem;
		}
		return true;
	}

	// record that this unsigned char ** refers to a pointer to the
	// global memory backing store
	void Domain::addGlobalMemoryBaseRef(unsigned char **baseRef) const
	{
		AvmAssert(baseRef != NULL);

		// find the not slot in a given chunk
		int mod = m_gmInfo.globalMemoryBaseRefNum % GMInfo::REFS_PER_CHUNK;

		GMInfo::BaseRefChunk *refs;

		// if the slot is zero, we need a new chunk
		if(!mod)
		{
			refs = new (core->GetGC()) GMInfo::BaseRefChunk();
			refs->next = m_gmInfo.globalMemoryBaseRefs;
			m_gmInfo.globalMemoryBaseRefs = refs;
		}
		else
			refs = m_gmInfo.globalMemoryBaseRefs;
		// put it in the right slot
		refs->refs[mod] = baseRef;
		// and remember we added one
		m_gmInfo.globalMemoryBaseRefNum++;
	}

	// same as addGlobalMemoryBaseRef but for references to the
	// size of the global memory object
	void Domain::addGlobalMemorySizeRef(uint32 *sizeRef) const
	{
		AvmAssert(sizeRef != NULL);

		int mod = m_gmInfo.globalMemorySizeRefNum % GMInfo::REFS_PER_CHUNK;

		GMInfo::SizeRefChunk *refs;

		if(!mod)
		{
			refs = new (core->GetGC()) GMInfo::SizeRefChunk();
			refs->next = m_gmInfo.globalMemorySizeRefs;
			m_gmInfo.globalMemorySizeRefs = refs;
		}
		else
			refs = m_gmInfo.globalMemorySizeRefs;
		refs->refs[mod] = sizeRef;
		m_gmInfo.globalMemorySizeRefNum++;
	}

	#if (defined(AVMPLUS_MAC) || defined(AVMPLUS_UNIX)) && !defined(AVMPLUS_SYMBIAN)
	#include <sys/mman.h>
	#endif

	// junk to toggle protection on code while
	// updating global memory stuff
	// TODO get rid of ifdefs (some/most of this
	// functionality lives in GCHeap at various
	// levels)
	class ProtectionHelper
	{
	private:

	#if defined(AVMPLUS_WIN32)
		typedef DWORD PROT_TYPE;
		typedef DWORD PROT_SIZE;
	#elif (defined(AVMPLUS_MAC) || defined(AVMPLUS_UNIX) || defined(AVMPLUS_SYMBIAN))
		typedef int PROT_TYPE;
		typedef size_t PROT_SIZE;
	#else
		#error "PROT_TYPE and PROT_SIZE must be defined for this platform"
	#endif

		void*			m_lastPage;			// pointer to first page we have currently toggled
		PROT_TYPE		m_lastPageProt;		// old protection of pages currently toggled
		PROT_SIZE		m_lastPageSize;		// size of memory current toggled (divisible by page size)
		const PROT_SIZE	m_pageSize;
	#if (defined(AVMPLUS_MAC) || defined(AVMPLUS_UNIX) || defined(AVMPLUS_SYMBIAN))
		void*			m_codeMin;
		void*			m_codeMax;
	#endif
	
	private:
		void* GetPage(void *p, sintptr off)
		{
			return (void *)(~(m_pageSize-1) & (off + (sintptr)p));
		}

	public:

		ProtectionHelper() : 
			m_lastPage(NULL), 
			m_lastPageProt(0), 
			m_lastPageSize(0), 
			m_pageSize(MMgc::GCHeap::GetGCHeap()->kNativePageSize)
#if (defined(AVMPLUS_MAC) || defined(AVMPLUS_UNIX) || defined(AVMPLUS_SYMBIAN))
			, m_codeMin(NULL)
			, m_codeMax(NULL)
#endif
		{
		}

		// flush the instruction cache
		void FlushCache()
		{
		#if defined(AVMPLUS_WIN32)
			FlushInstructionCache(GetCurrentProcess(), NULL, 0);
		#elif (defined(AVMPLUS_MAC) || defined(AVMPLUS_UNIX))
			if (m_codeMin)
			{
				AvmAssert(m_codeMax != NULL);
				msync((maddr_ptr)m_codeMin, (char*)m_codeMax - (char*)m_codeMin + m_pageSize, MS_INVALIDATE);
			}
		#elif defined(AVMPLUS_SYMBIAN)
			// nothing
		#else
			#pragma warning flush instruction cache?
		#endif
		}

		// if p != NULL, ensure that [p, p+r) is writeable
		// (and maybe restore previous state for previous protect change)
		// if p == NULL, restore previous state
		// ([m_lastPage, m_lastPage + m_lastPageSize) to m_lastPageProt protection)
		void MakeWriteable(void* p, uint32 r)
		{
			AvmAssert(r < m_pageSize);
			void* page = GetPage(p, 0);
			void* page1 = GetPage(p, r - 1); // might span a page
			unsigned size = (page == page1) ? m_pageSize : 2 * m_pageSize;

			#if (defined(AVMPLUS_MAC) || defined(AVMPLUS_UNIX))
			if (!page)
			{
				m_codeMin = m_codeMax = NULL;
			}
			else
			{
				if (!m_codeMin)
					m_codeMin = page;
				if (page > m_codeMax)
					m_codeMax = (char*)page - m_pageSize + size;
			}
			#endif

			if (page != m_lastPage || size != m_lastPageSize)
			{
				if (m_lastPage)
				{
				#ifdef AVMPLUS_WIN32
				#ifndef UNDER_CE
					DWORD dwIgnore;
					VirtualProtectEx(GetCurrentProcess(), m_lastPage, m_lastPageSize, m_lastPageProt, &dwIgnore);
				#else
					AvmAssert(0);
				#endif
				#elif !defined(AVMPLUS_SYMBIAN)
					int result = mprotect((maddr_ptr)m_lastPage, m_lastPageSize, m_lastPageProt);
					AvmAssert(result == 0);
					(void)result;
				#else
					AvmAssert(0);
				#endif
					m_lastPage =  NULL;
					m_lastPageSize = 0;
				}
				if (page)
				{
				#ifdef AVMPLUS_WIN32
				#ifndef UNDER_CE
					VirtualProtectEx(GetCurrentProcess(), page, size, PAGE_READWRITE, &m_lastPageProt);
				#else
					AvmAssert(0);
				#endif
				#elif !defined(AVMPLUS_SYMBIAN)
					int result = mprotect((maddr_ptr)page, size, PROT_READ | PROT_WRITE);
					AvmAssert(result == 0);
					(void)result;
					m_lastPageProt = PROT_READ | PROT_EXEC;
				#endif
					m_lastPage = page;
					m_lastPageSize = size;
				}
			}
		}
	};

	// memory changed so go through and update all reference to both the base
	// and the size of the global memory
	void Domain::notifyGlobalMemoryChanged(unsigned char *newBase, uint32 newSize) const
	{
		AvmAssert(newBase != NULL); // real base address
		AvmAssert(newSize >= GLOBAL_MEMORY_MIN_SIZE); // big enough

		// ensure a real change happened...
		if(newBase != globalMemoryBase || newSize != globalMemorySize)
		{
			ProtectionHelper protHelper;

			// if a real change happened to backing store base address...
			if(newBase != globalMemoryBase)
			{
				GMInfo::BaseRefChunk *baseRefs = m_gmInfo.globalMemoryBaseRefs;

				// go through each reference
				for(uint32 n = 0; n < m_gmInfo.globalMemoryBaseRefNum; n++)
				{
					// get the slot
					int mod = n % GMInfo::REFS_PER_CHUNK;

					// if it's zero, get the NEXT slot
					// this means we start with the SECOND chunk
					if(!mod)
					{
						baseRefs = baseRefs->next;
						// and when we get to the end, THEN do the first chunk
						if(!baseRefs)
							baseRefs = m_gmInfo.globalMemoryBaseRefs;
					}
					unsigned char** p = (baseRefs->refs[mod]);
					// make it writeable
					protHelper.MakeWriteable(p, sizeof(unsigned char *));
					// and do a difference instead of a simple write
					// as it may be offset from the base
					*p = *p - globalMemoryBase + newBase;
				}
			}

			// same as above but for size
			if(newSize != globalMemorySize)
			{
				GMInfo::SizeRefChunk* sizeRefs = m_gmInfo.globalMemorySizeRefs;

				for(uint32 n = 0; n < m_gmInfo.globalMemorySizeRefNum; n++)
				{
					int mod = n % GMInfo::REFS_PER_CHUNK;

					if(!mod) // start with SECOND chunk
					{
						sizeRefs = sizeRefs->next;
						// and when we get to the end, THEN do the first chunk
						if(!sizeRefs)
							sizeRefs = m_gmInfo.globalMemorySizeRefs;
					}
					uint32* p = (sizeRefs->refs[mod]);
					protHelper.MakeWriteable(p, sizeof(uint32));
					*p = *p - globalMemorySize + newSize;
				}
			}

			// remove and writeability changes
			protHelper.MakeWriteable(NULL, 1);
			// record the new base and size
			globalMemoryBase = newBase;
			globalMemorySize = newSize;

			// and flush the instruction cache
			protHelper.FlushCache();
		}
	}
#endif
}


