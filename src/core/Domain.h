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

#ifndef __avmplus_Domain__
#define __avmplus_Domain__

namespace avmplus
{
	class Domain : public MMgc::GCObject
	{
	private:
		// These are private so that we can invalidate global lookup caches if they change
		
		/** The domain-wide traits table (type name => instance Traits) */
		DWB(MultinameHashtable*) namedTraits;

		/** domain-wide type table of scripts, indexed by definition name */
		DWB(MultinameHashtable*) namedScripts;

	public:
		/** Parent domain */
		Domain* const base;
		
#ifdef AVMPLUS_MOPS
		AvmCore* const core;
#endif	
	
		Domain(AvmCore *core, Domain* base);
		
		Traits* getNamedTraits(Stringp name, Namespacep ns, bool recursive/*=true*/) const;
		Traits* getNamedTraits(const Multiname* multiname, bool recursive/*=true*/) const;
		AbstractFunction* getNamedScript(Stringp name, Namespacep ns) const;
		AbstractFunction* getNamedScript(const Multiname* multiname) const;
		
		Traits* getNamedTrait(Stringp name, Namespace* ns) const { return (Traits*)namedTraits->get(name, ns); }
		void addNamedTrait(Stringp name, Namespace* ns, Traits* v) { namedTraits->add(name, ns, (Binding)v); }
		void addNamedScript(Stringp name, Namespace* ns, AbstractFunction* v) { namedScripts->add(name, ns, (Binding)v); }

	#ifdef AVMPLUS_MOPS
		/**
		 * global memory access glue
		 */
		enum {
			GLOBAL_MEMORY_MIN_SIZE =
// on IA32, we have HAVE_MIR_SMOPS and can optimize range checks
// against ranges that can fit within the minimum memory size
// so it's worth burning a little space
#ifdef AVMPLUS_IA32
				1024
#else
				8
#endif
		};
		// backing store for global memory
		mutable unsigned char *globalMemoryBase;
		// current size of global memory
		mutable uint32 globalMemorySize;

		// global memory object accessor (will always be a ByteArray but
		// ByteArray isn't part of AVMPlus proper so plumbing is a little
		// weird...)
		ScriptObject* globalMemory() const { return m_gmInfo.globalMemory; }
		bool setGlobalMemory(ScriptObject *mem) const;

		// mark a pointer to pointer as being a reference to the global memory
		// so that it gets updated if the global memory moves
		void addGlobalMemoryBaseRef(unsigned char **baseRef) const;
		// mark a pointer to uint32 (TODO: 64 bit?) as being a reference to
		// the current size of the global memory so it can get updated
		void addGlobalMemorySizeRef(uint32 *sizeRef) const;

		// verifies that the Traits correspond to a memory object
		bool isMemoryObject(Traits *t) const;

	private:
		// global memory tracking stuff
		mutable struct GMInfo
		{
			// the actual memory object (can be NULL)
			DRCWB(ScriptObject*) globalMemory;
			// scratch memory to use if the memory object is NULL
			unsigned char globalMemoryScratch[GLOBAL_MEMORY_MIN_SIZE];

			// number of memory base or size references per "chunk"
			// these references are stored in linked list with each link
			// storing REFS_PER_CHUNK values to minimize overhead
			enum { REFS_PER_CHUNK = 254 }; // TODO chunk size is right?

			// chunk link for references to global memory base
			struct BaseRefChunk : public MMgc::GCObject
			{
				unsigned char **refs[REFS_PER_CHUNK];
				DWB(BaseRefChunk *) next;
			};
			// we keep count of the total so we know how many
			// slots are unoccupied in the head link
			uint32 globalMemoryBaseRefNum;
			// head link
			DWB(BaseRefChunk *) globalMemoryBaseRefs;

			// same as above but for reference to global memory size
			struct SizeRefChunk : public MMgc::GCObject
			{
				uint32 *refs[REFS_PER_CHUNK];
				DWB(SizeRefChunk *) next;
			};
			uint32 globalMemorySizeRefNum;
			DWB(SizeRefChunk *) globalMemorySizeRefs;
		} m_gmInfo;

		// called when the global memory backing store moves
		// updates all of the references held in globalMemoryBaseRefs and 
		// globalMemorySizeRefs
		void notifyGlobalMemoryChanged(unsigned char *newBase, uint32 newSize) const;
		// subscribes to the memory object "mem" such that "mem" will call our
		// notifyGlobalMemoryChanged when it moves
		bool globalMemorySubscribe(ScriptObject *mem) const;
		// stops "mem" from notifying us if it moves
		bool globalMemoryUnsubscribe(ScriptObject *mem) const;
#endif
	};
}

#endif /* __avmplus_Domain__ */
