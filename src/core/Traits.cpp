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
#ifdef AVMPLUS_MIR
#include "../codegen/CodegenMIR.h"
#endif
#ifdef FEATURE_NANOJIT
#include "../codegen/CodegenLIR.h"
#endif

namespace avmplus
{
	using namespace MMgc;

#ifdef AVMPLUS_TRAITS_MEMTRACK
	const uint32_t TMT_REPORT_RATE = 1000;

	AvmCore* g_tmcore = NULL;
	
	class TMT_list
	{
	private:
		enum { MAXLIST = 150000 };
		uint32_t m_count;
		const void* m_p[MAXLIST];
	public:
		inline TMT_list() : m_count(0) {}
		inline uint32_t count() const { return m_count; }
		inline const void* operator[](uint32_t i) const { return m_p[i]; }
		int32_t find(const void* val) const;
		void add(const void* val);
		bool remove(const void* val);
		void reset() { m_count = 0; }
	};

	struct TMT
	{
		TMT_list live;
		uint32_t mem, active, cached;
		uint32_t count_hw, mem_hw;
		
		inline TMT() : mem(0), active(0), cached(0), count_hw(0), mem_hw(0) {}
	};
	static TMT g_tinfo[TMT_COUNT];
	static const char* const g_tinfonm[TMT_COUNT] = 
	{ 
		"Traits", 
		"TBI", 
		"TMI", 
		"VTable", 
		"MethodEnv", 
		"AbstractFunction" 
	};
	static uint32_t g_track_count = 0;

	int32_t TMT_list::find(const void* val) const
	{
		for(uint32_t i=0; i<m_count; i++)
			if (m_p[i] == val)
				return (int32_t)i;
		
		return -1;
	}

	void TMT_list::add(const void* val)
	{
		if (m_count >= MAXLIST)
		{
			AvmAssert(0);
			printf("***** WARNING, overflow\n");
			printf("***** WARNING, overflow\n");
			printf("***** WARNING, overflow\n");
			return;
		}
		
		if (find(val) >= 0)
			return;
		
		m_p[m_count++] = val;
	}

	bool TMT_list::remove(const void* val)
	{
		int32_t i = find(val);
		AvmAssert(i >= 0 && i < (int32_t)m_count);
		if (i >= 0)
		{
			if (i < (int32_t)m_count-1)
				memmove(&m_p[i], &m_p[i+1], sizeof(const void*)*(m_count-1-i));
			m_count -= 1;
			AvmAssert(find(val) < 0);
			return true;
		}
		return false;
	}
	
	void tmt_report()
	{
		static int g_in_delta = 0;
		if (g_in_delta == 0)	// bracket to prevent the Collect() call from recursing
		{
			++g_in_delta;
			
			g_tmcore->GetGC()->CleanStack();
			g_tmcore->GetGC()->Collect(); // flush out dead WeaKRefs first
			
			static TMT_list g_tmp;	// static only to avoid crushing the stack

			g_tmp.reset();
			for (QCachedItem* td = g_tmcore->tmCache()->first(); td; td = g_tmcore->tmCache()->next(td))
			{
				for (TraitsMetadatap t = (TraitsMetadatap)td; t; t = t->base)
					g_tmp.add(t);
			}
			g_tinfo[TMT_tmi].cached = g_tmcore->tmCache()->count();
			g_tinfo[TMT_tmi].active = g_tmp.count();

			g_tmp.reset();
			for (QCachedItem* td = g_tmcore->tbCache()->first(); td; td = g_tmcore->tbCache()->next(td))
			{
				for (TraitsBindingsp t = (TraitsBindingsp)td; t; t = t->base)
					g_tmp.add(t);
			}
			g_tinfo[TMT_tbi].cached = g_tmcore->tbCache()->count();
			g_tinfo[TMT_tbi].active = g_tmp.count();
			
			printf("\nTraitsMemTrack @ %d:\n",g_track_count);
			uint32_t totmem = 0;
			uint32_t totmem_hw = 0;
			for (int i = 0; i < TMT_COUNT; ++i)
			{
				printf("    %-16s live: %d=%dk (%db), hw: %d=%dk (%db) ",
					g_tinfonm[i],
					g_tinfo[i].live.count(),
					g_tinfo[i].mem>>10,
					g_tinfo[i].live.count()?(g_tinfo[i].mem/g_tinfo[i].live.count()):0,
					g_tinfo[i].count_hw,
					g_tinfo[i].mem_hw>>10,
					g_tinfo[i].count_hw?(g_tinfo[i].mem_hw/g_tinfo[i].count_hw):0);

				if (i == TMT_tmi || i == TMT_tbi)
					printf(" cached=%d(=%d incl bases)",
						g_tinfo[i].cached,
						g_tinfo[i].active);

				printf("\n");
				totmem += g_tinfo[i].mem;
				totmem_hw += g_tinfo[i].mem_hw;
			}
			// hw total may be inaccurate because different buckets might HW at different times
			printf("  totmem: %dk (hw estimate: %dk)\n",totmem>>10,totmem_hw>>10);

			// g_tmp still contains the list of all active cached TBI
			uint32_t rogues = 0;
			for (uint32_t i = 0; i < g_tinfo[TMT_tbi].live.count(); ++i)
			{
				if (g_tmp.find(g_tinfo[TMT_tbi].live[i]) < 0)
				{
					//Traitsp o = ((TraitsBindingsp)(g_live_tbi[i]))->owner;
					//printf("   rogue TBI found: %p size=%d owned by %s %p\n", (void*)g_live_tbi[i], (uint32_t)GC::Size(live_tbi[i]), (char*)o->rawname, (void*)o);
					#ifdef _DEBUG
					//g_tmcore->GetGC()->DumpBackPointerChain((void*)live_tbi[i]);
					#endif
					++rogues;
				}
			}
			if (rogues>10)
			printf(" **** found %d rogues\n",rogues);

			--g_in_delta;
		}
	}

	void tmt_add_mem(TMTTYPE t, size_t d)
	{
		if (!g_tmcore || g_tmcore->GetGC()->Destroying()) return;
		
		g_tinfo[t].mem += d;
		
		if (g_tinfo[t].mem_hw < g_tinfo[t].mem)
		{
			g_tinfo[t].mem_hw = g_tinfo[t].mem;
			g_tinfo[t].count_hw = g_tinfo[t].live.count();
		}
	}

	void tmt_sub_mem(TMTTYPE t, size_t d)
	{
		if (!g_tmcore || g_tmcore->GetGC()->Destroying()) return;
		
		g_tinfo[t].mem -= d;
	}

	void tmt_add_inst(TMTTYPE t, const void* inst)
	{
		if (!g_tmcore || g_tmcore->GetGC()->Destroying()) return;
		
		AvmAssert(g_tinfo[t].live.find(inst) < 0);
		g_tinfo[t].live.add(inst);
		
		tmt_add_mem(t, GC::Size(inst));

		if ((++g_track_count % TMT_REPORT_RATE) == 0) 
			tmt_report();
	}

	void tmt_sub_inst(TMTTYPE t, const void* inst)
	{
		if (!g_tmcore || g_tmcore->GetGC()->Destroying()) return;
		
		AvmAssert(g_tinfo[t].live.find(inst) >= 0);
		g_tinfo[t].live.remove(inst);

		tmt_sub_mem(t, GC::Size(inst));

		if ((++g_track_count % TMT_REPORT_RATE) == 0) 
			tmt_report();
	}
#endif

	// -------------------------------------------------------------------
	// -------------------------------------------------------------------
	// -------------------------------------------------------------------
	// -------------------------------------------------------------------

	/*static*/ TraitsBindings* TraitsBindings::alloc(GC* gc, 
												Traits* _owner, 
												TraitsBindingsp _base, 
												MultinameHashtable* _bindings, 
												uint32_t slotCount, 
												uint32_t methodCount,
												uint32_t interfaceCapacity)
	{
		const uint32_t extra = slotCount * sizeof(SlotInfo) + 
						methodCount * sizeof(MethodInfo) +
						interfaceCapacity * sizeof(InterfaceInfo);

		TraitsBindings* tb = new (gc, extra) TraitsBindings(_owner, _base, _bindings, slotCount, methodCount, interfaceCapacity);
		if (_base)
		{
			if (_base->slotCount)
			{
				const SlotInfo* src = &_base->getSlots()[0];
				SlotInfo* dst = &tb->getSlots()[0];
				memcpy(dst, src, _base->slotCount * sizeof(SlotInfo));
				if (!_owner->isMachineType())
				{
					AvmAssert(tb->owner->m_sizeofInstance >= _base->owner->m_sizeofInstance);
					// upshift by 3 bits to affect only the offset part, leaving sst alone...
					// downshift by 2 bits because it's stored as offset of uint32 (not uint8)
					// thus net upshift of 1
					const uint32_t delta = (tb->owner->m_sizeofInstance - _base->owner->m_sizeofInstance)<<1;
					if (delta > 0)
					{
						for (uint32_t i = 0, n = _base->slotCount; i < n; ++i)
							dst[i].offsetAndSST = src[i].offsetAndSST + delta;
					}
				}
			}
			if (_base->methodCount)
				memcpy(&tb->getMethods()[0], &_base->getMethods()[0], _base->methodCount * sizeof(MethodInfo));
		}
		AVMPLUS_TRAITS_MEMTRACK_ONLY( tmt_add_inst(TMT_tbi, tb); )
		return tb;
	}

#ifdef AVMPLUS_TRAITS_MEMTRACK
	TraitsBindings::~TraitsBindings()
	{
		AVMPLUS_TRAITS_MEMTRACK_ONLY( tmt_sub_inst( TMT_tbi, this); )
	}
#endif

	bool TraitsBindings::containsInterface(Traitsp t) const 
	{ 
		for (TraitsBindingsp self = this; self; self = self->base)
		{
			if (self->owner == t || self->findInterfaceAddr(t)->t != NULL) 
				return true;
		}
		return false;
	}

	Binding TraitsBindings::findBinding(Stringp name) const
	{
		for (TraitsBindingsp self = this; self; self = self->base)
		{
			const Binding b = self->m_bindings->getName(name);
			if (b != BIND_NONE)
				return b;
		}
		return BIND_NONE;
	}

	Binding TraitsBindings::findBinding(Stringp name, Namespacep ns) const
	{
		for (TraitsBindingsp self = this; self; self = self->base)
		{
			const Binding b = self->m_bindings->get(name, ns);
			if (b != BIND_NONE)
				return b;
		}
		return BIND_NONE;
	}

	Binding TraitsBindings::findBinding(Stringp name, NamespaceSetp nsset) const
	{
		for (TraitsBindingsp self = this; self; self = self->base)
		{
			const Binding b = self->m_bindings->get(name, nsset);
			if (b != BIND_NONE)
				return b;
		}
		return BIND_NONE;
	}

	void TraitsBindings::addOneInterface(Traitsp intf)
	{
		AvmAssert(intf != NULL);
		AvmAssert(intf->posType() != TRAITSTYPE_FUNCTION);
		AvmAssert(intf->posType() != TRAITSTYPE_NVA);
		AvmAssert(intf->posType() != TRAITSTYPE_RT);

		// since this is in the cache, no need for WB: ifc isn't going to go
		// away before we do
		InterfaceInfo* addr = findInterfaceAddr(intf);
		AvmAssert(addr->t == NULL || addr->t == intf);
		addr->t = intf;
	}

	TraitsBindings::InterfaceInfo* TraitsBindings::findInterfaceAddr(Traitsp intf)
	{
		InterfaceInfo* set = getInterfaces();
        // this is a quadratic probe
        int32_t n = 7;
		const uint32_t bitMask = this->interfaceCapacity - 1;

		uint32_t i = (uintptr_t(intf)) & bitMask;
		AvmAssert(i < this->interfaceCapacity);
        Traitsp k;
        while ((k = set[i].t) != intf && k != NULL)
		{
			i = (i + (n++)) & bitMask;				// quadratic probe
		}
		AvmAssert(i < this->interfaceCapacity);
		AvmAssert(set[i].t == NULL || set[i].t == intf);
        return &set[i];
	}

#ifdef MMGC_DRC

	void TraitsBindings::buildSlotDestroyInfo(MMgc::GC* gc, FixedBitSet& slotDestroyInfo) const
	{
		// this is really a compile-time assertion
		AvmAssert(kUnusedAtomTag == 0 && kObjectType == 1 && kStringType == 2 && kNamespaceType == 3);
		
		// not the same as slotCount since a slot of type double
		// takes two bits (in 32-bit builds). note that the bits are
		// always 4-byte chunks even in 64-bit builds!
		const uint32_t bitsNeeded = m_slotSize / sizeof(uint32_t);	// not sizeof(Atom)!
		AvmAssert(bitsNeeded * sizeof(uint32_t) == m_slotSize);		// should be even multiple!
		// allocate one extra bit and use it for "all-zero"
		AVMPLUS_TRAITS_MEMTRACK_ONLY( tmt_sub_mem(TMT_traits, slotDestroyInfo.allocatedSize() ); )
		slotDestroyInfo.resize(gc, bitsNeeded+1);
		AVMPLUS_TRAITS_MEMTRACK_ONLY( tmt_add_mem(TMT_traits, slotDestroyInfo.allocatedSize() ); )
		
		const uint32_t sizeofInstance = this->owner->m_sizeofInstance;
		const TraitsBindings::SlotInfo* tbs		= getSlots();
		const TraitsBindings::SlotInfo* tbs_end	= tbs + slotCount;
		for ( ; tbs < tbs_end; ++tbs) 
		{
			// offset is pointed off the end of our object
			if (isAtomOrRCObjectSlot(tbs->sst())) 
			{
				//owner->core->console<<"SDI "<<owner<<" "<<sizeofInstance<<" "<<tbs->type<<" "<<tbs->offset()<<"\n";
				AvmAssert(tbs->offset() >= sizeofInstance);
				const uint32_t off = tbs->offset() - sizeofInstance;
				AvmAssert((off % 4) == 0);
				// if slot is "big" then this is the bit of the first 4 bytes. that's fine.
				slotDestroyInfo.set((off>>2)+1);	// +1 to leave room for bit 0
				slotDestroyInfo.set(0);				// bit 0 is "anyset" flag
			} 
			// otherwise leave the bit zero
		}

		// if nothing set, blow away what we built and realloc as single clear bit -- smaller and faster
		if (!slotDestroyInfo.test(0))
		{
			AVMPLUS_TRAITS_MEMTRACK_ONLY( tmt_sub_mem(TMT_traits, slotDestroyInfo.allocatedSize() ); )
			slotDestroyInfo.resize(gc, 1);
			AVMPLUS_TRAITS_MEMTRACK_ONLY( tmt_add_mem(TMT_traits, slotDestroyInfo.allocatedSize() ); )
			AvmAssert(!slotDestroyInfo.test(0));
		}
	}
#endif // MMGC_DRC

    bool TraitsBindings::checkOverride(AvmCore* core, AbstractFunction* virt, AbstractFunction* over) const
    {
		if (over == virt)
			return true;
			
        Traits* overTraits = over->returnTraits();
        Traits* virtTraits = virt->returnTraits();

        if (overTraits != virtTraits)
        {
#ifdef AVMPLUS_VERBOSE
            core->console << "\n";
            core->console << "return types dont match\n";
            core->console << "   virt " << virtTraits << " " << virt << "\n";
            core->console << "   over " << overTraits << " " << over << "\n";
#endif
            return false;
        }

        if (over->param_count != virt->param_count ||
            over->optional_count != virt->optional_count)
        {
#ifdef AVMPLUS_VERBOSE
            core->console << "\n";
            core->console << "param count mismatch\n";
            core->console << "   virt params=" << virt->param_count << " optional=" << virt->optional_count << " " << virt << "\n";
            core->console << "   over params=" << over->param_count << " optional=" << over->optional_count << " " << virt << "\n";
#endif
            return false;
        }

		// allow subclass param 0 to implement or extend base param 0
		virtTraits = virt->paramTraits(0);
		if (!containsInterface(virtTraits) || !Traits::isMachineCompatible(this->owner, virtTraits))
		{
			if (!this->owner->isMachineType() && virtTraits == core->traits.object_itraits)
			{
				over->flags |= AbstractFunction::UNBOX_THIS;
			}
			else
			{
				#ifdef AVMPLUS_VERBOSE
				core->console << "\n";
				core->console << "param 0 incompatible\n";
				core->console << "   virt " << virtTraits << " " << virt << "\n";
				core->console << "   over " << this->owner << " " << over << "\n";
				#endif
				return false;
			}
		}

        for (int k=1, p=over->param_count; k <= p; k++)
        {
            overTraits = over->paramTraits(k);
            virtTraits = virt->paramTraits(k);
            if (overTraits != virtTraits)
            {
				#ifdef AVMPLUS_VERBOSE
				core->console << "\n";
				core->console << "param " << k << " incompatible\n";
				core->console << "   virt " << virtTraits << " " << virt << "\n";
				core->console << "   over " << overTraits << " " << over << "\n";
				#endif
				return false;
            }
        }

		if (virt->flags & AbstractFunction::UNBOX_THIS)
		{
			// the UNBOX_THIS flag is sticky, all the way down the inheritance tree
			over->flags |= AbstractFunction::UNBOX_THIS;
		}

        return true;
    }

	static bool isCompatibleOverrideKind(BindingKind baseKind, BindingKind overKind)
	{
		static const uint8_t kCompatibleBindingKinds[8] = 
		{
			0,														// BKIND_NONE
			(1<<BKIND_METHOD),										// BKIND_METHOD
			0,														// BKIND_VAR
			0,														// BKIND_CONST
			0,														// BKIND_ITRAMP
			(1<<BKIND_GET) | (1<<BKIND_SET) | (1<<BKIND_GETSET),	// BKIND_GET
			(1<<BKIND_GET) | (1<<BKIND_SET) | (1<<BKIND_GETSET),	// BKIND_SET
			(1<<BKIND_GET) | (1<<BKIND_SET) | (1<<BKIND_GETSET)		// BKIND_GETSET
		};
		return (kCompatibleBindingKinds[baseKind] & (1<<overKind)) != 0;
	}

	bool TraitsBindings::checkLegalInterfaces(AvmCore* core) const
	{
		// make sure every interface method is implemented
		const TraitsBindings::InterfaceInfo* tbi		= this->getInterfaces();
		const TraitsBindings::InterfaceInfo* tbi_end	= tbi + this->interfaceCapacity;
		for ( ; tbi < tbi_end; ++tbi) 
		{
			Traitsp ifc = tbi->t;
			if (!ifc || !ifc->isInterface)
				continue;

			TraitsBindingsp ifcd = ifc->getTraitsBindings();
			for (int32_t j = ifcd->next(0); j != 0; j = ifcd->next(j))
			{
				Stringp name = ifcd->keyAt(j);
				Namespacep ns = ifcd->nsAt(j);
				Binding iBinding = ifcd->valueAt(j);
				const BindingKind iBindingKind = AvmCore::bindingKind(iBinding);

				Binding cBinding = this->findBinding(name, ns);
				if (!isCompatibleOverrideKind(iBindingKind, AvmCore::bindingKind(cBinding)))
				{
					// Try again with public namespace
					const Binding pBinding = this->findBinding(name, core->publicNamespace);
					if (isCompatibleOverrideKind(iBindingKind, AvmCore::bindingKind(pBinding)))
						cBinding = pBinding;
				}
				if (!isCompatibleOverrideKind(iBindingKind, AvmCore::bindingKind(cBinding)))
					return false;

				switch (iBindingKind)
				{
					default:
					{
						AvmAssert(0);	// interfaces shouldn't have anything but methods, getters, and setters
						return false;
					}
					case BKIND_METHOD:
					{
						AbstractFunction* virt = ifcd->getMethod(AvmCore::bindingToMethodId(iBinding));
						AbstractFunction* over = this->getMethod(AvmCore::bindingToMethodId(cBinding));
						if (!checkOverride(core, virt, over))
							return false;
						break;
					}
					case BKIND_GET:
					case BKIND_SET:
					case BKIND_GETSET:
					{
						// check getter & setter overrides
						if (AvmCore::hasGetterBinding(iBinding))
						{
							if (!AvmCore::hasGetterBinding(cBinding))
								return false;
							
							AbstractFunction* virt = ifcd->getMethod(AvmCore::bindingToGetterId(iBinding));
							AbstractFunction* over = this->getMethod(AvmCore::bindingToGetterId(cBinding));
							if (!checkOverride(core, virt, over))
								return false;
						}

						if (AvmCore::hasSetterBinding(iBinding))
						{
							if (!AvmCore::hasSetterBinding(cBinding))
								return false;
								
							AbstractFunction* virt = ifcd->getMethod(AvmCore::bindingToSetterId(iBinding));
							AbstractFunction* over = this->getMethod(AvmCore::bindingToSetterId(cBinding));
							if (!checkOverride(core, virt, over))
								return false;
						}
					}
					break;
				} // switch
			} // for j
		} // for tbi
		return true;
	}
	
#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
	void TraitsBindings::fixInterfaceBindings(AvmCore* core, const Toplevel* toplevel, ImtBuilder* imtBuilder)
#else
	void TraitsBindings::fixInterfaceBindings(AvmCore* core, const Toplevel* toplevel)
#endif
	{
		if (owner->isInterface)
			return;
		
	#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
		for (TraitsBindingsp self = this; self; self = self->base)
	#else
		// only need this to be a loop if we are building IMT, which never happens in non-MIR mode
		TraitsBindingsp self = this;
	#endif
		{
			const TraitsBindings::InterfaceInfo* tbi		= self->getInterfaces();
			const TraitsBindings::InterfaceInfo* tbi_end	= tbi + self->interfaceCapacity;
			for ( ; tbi < tbi_end; ++tbi) 
			{
				Traitsp ifc = tbi->t;
				if (!ifc || !ifc->isInterface)
					continue;

				if (!ifc->linked) 
				{
					// toplevel will be non-null only for the first call (will be null afterwards) --
					// but all our interfaces will be resolved by then
					AvmAssert(toplevel != NULL);
					ifc->resolveSignatures(toplevel);
				}

				TraitsBindingsp ifcd = ifc->getTraitsBindings();
				for (int32_t j = ifcd->next(0); j != 0; j = ifcd->next(j))
				{
					Stringp name = ifcd->keyAt(j);
					Namespacep ns = ifcd->nsAt(j);
					Binding iBinding = ifcd->valueAt(j);
					const BindingKind iBindingKind = AvmCore::bindingKind(iBinding);

					Binding cBinding = self->findBinding(name, ns);
					if (!isCompatibleOverrideKind(iBindingKind, AvmCore::bindingKind(cBinding)))
					{
						// Try again with public namespace
						const Binding pBinding = self->findBinding(name, core->publicNamespace);
						if (isCompatibleOverrideKind(iBindingKind, AvmCore::bindingKind(pBinding)))
						{
							// don't need to add bindings for ancestors
							if (self == this)
								this->m_bindings->add(name, ns, pBinding);
							cBinding = pBinding;
						}
					}
					AvmAssert(isCompatibleOverrideKind(iBindingKind, AvmCore::bindingKind(cBinding)));
	#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
					// don't need to add bindings for ancestors, but we do need to add ancestor interfaces
					// to the IMT if we are building that.
					if (imtBuilder)
					{
						if (AvmCore::isMethodBinding(iBinding))
						{
							imtBuilder->addEntry(ifcd->getMethod(AvmCore::bindingToMethodId(iBinding)), AvmCore::bindingToMethodId(cBinding));
						}
						if (AvmCore::hasGetterBinding(iBinding))
						{
							imtBuilder->addEntry(ifcd->getMethod(AvmCore::bindingToGetterId(iBinding)), AvmCore::bindingToGetterId(cBinding));
						}
						if (AvmCore::hasSetterBinding(iBinding))
						{
							imtBuilder->addEntry(ifcd->getMethod(AvmCore::bindingToSetterId(iBinding)), AvmCore::bindingToSetterId(cBinding));
						}
					}
	#endif
				} // for j
			} // for tbi
			//
	#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
			// if not building IMT, we're done after one iteration.
			if (!imtBuilder) 
				break;
	#endif
		}
	}
		
	// -------------------------------------------------------------------
	// -------------------------------------------------------------------

#ifdef AVMPLUS_TRAITS_MEMTRACK 
	TraitsMetadata::~TraitsMetadata()
	{
		AVMPLUS_TRAITS_MEMTRACK_ONLY( tmt_sub_inst( TMT_tmi, this); )
	}
#endif

	TraitsMetadata::MetadataPtr TraitsMetadata::getSlotMetadataPos(uint32_t i, PoolObject*& residingPool) const
	{
		AvmAssert(i < slotCount);
		residingPool = NULL;
		for (TraitsMetadatap self = this; self && (i < self->slotCount); self = self->base)
		{
			MetadataPtr pos = self->slotMetadataPos[i];
			if (pos)
			{
				residingPool = self->residingPool;
				return pos;
			}
		}
		return NULL;
	}

	TraitsMetadata::MetadataPtr TraitsMetadata::getMethodMetadataPos(uint32_t i, PoolObject*& residingPool) const
	{
		AvmAssert(i < methodCount);
		residingPool = NULL;
		for (TraitsMetadatap self = this; self && (i < self->methodCount); self = self->base)
		{
			MetadataPtr pos = self->methodMetadataPos[i];
			if (pos)
			{
				residingPool = self->residingPool;
				return pos;
			}
		}
		return NULL;
	}

	// -------------------------------------------------------------------
	// -------------------------------------------------------------------

    Traits::Traits(PoolObject* _pool, 
				   Traits* _base,
				   uint32_t _sizeofInstance,
				   TraitsPosPtr traitsPos,
				   TraitsPosType posType) : 
		core(_pool->core),
		base(_base),
		pool(_pool),
		m_traitsPos(traitsPos),
		m_tbref(_pool->core->GetGC()->emptyWeakRef),
		m_tmref(_pool->core->GetGC()->emptyWeakRef),
		m_sizeofInstance(uint16_t(_sizeofInstance)),
		builtinType(BUILTIN_none),
		m_posType(uint8_t(posType))
    {
		AvmAssert(m_tbref->get() == NULL);
		AvmAssert(m_tmref->get() == NULL);
		AvmAssert(BUILTIN_COUNT <= 32);
		AvmAssert(_sizeofInstance <= 0xffff);
		AvmAssert(m_slotDestroyInfo.allocatedSize() == 0);
		AvmAssert(m_skips.allocatedSize() == 0);
		// assume no skips (bit zero = clear)
		m_skips.resize(core->GetGC(), 1);
		AvmAssert(!m_skips.test(0));
#ifdef _DEBUG
		switch (posType)
		{
			case TRAITSTYPE_FUNCTION:
			case TRAITSTYPE_NVA:
			case TRAITSTYPE_RT:
				AvmAssert(m_traitsPos == 0);
				break;
			default:
				AvmAssert(m_traitsPos != 0);
				break;
		}
#endif
		AVMPLUS_TRAITS_MEMTRACK_ONLY( tmt_add_inst(TMT_traits, this); )
    }

#ifdef AVMPLUS_TRAITS_MEMTRACK
	Traits::~Traits()
	{
		if (!GC::GetGC(this)->Destroying())
		{
			AVMPLUS_TRAITS_MEMTRACK_ONLY( tmt_sub_inst(TMT_traits, this); )
		}
	}
#endif

	/*static*/ Traits* Traits::newTraits(PoolObject* pool,
							Traits *base,
							uint32 objectSize,
							TraitsPosPtr traitsPos,
							TraitsPosType posType)
    {
		AvmAssert(posType != TRAITSTYPE_CATCH && posType != TRAITSTYPE_FUNCTION);
		AvmAssert(pool != NULL);
		Traits* traits = new (pool->core->GetGC()) Traits(pool, base, objectSize, traitsPos, posType);
		return traits;
	}

	/*static*/ Traits* Traits::newCatchTraits(const Toplevel* toplevel, PoolObject* pool, TraitsPosPtr traitsPos, Stringp name, Namespacep ns)
	{
		AvmAssert(pool != NULL);
		Traits* traits = new (pool->core->GetGC()) Traits(pool, NULL, sizeof(ScriptObject), traitsPos, TRAITSTYPE_CATCH);
		traits->final = true;
		traits->name = name;	
		traits->ns = ns;
		traits->resolveSignatures(toplevel);
		return traits;
	}

	/*static*/ Traits* Traits::newFunctionTraits(const Toplevel* toplevel, PoolObject* pool, uint32_t method_id)
	{
		AvmAssert(pool != NULL);
		AvmCore* core = pool->core;
		Traits* base = core->traits.function_itraits;
		AvmAssert(base->isResolved());
		Traits* traits = new (pool->core->GetGC()) Traits(pool, base, base->m_sizeofInstance, NULL, TRAITSTYPE_FUNCTION);
		traits->itraits = core->traits.object_itraits;
		traits->m_needsHashtable = true;
		traits->final = true;
	#ifdef AVMPLUS_VERBOSE
		traits->ns = core->publicNamespace;
		traits->name = core->internString(core->concatStrings(core->newString("Function-"), core->intToString(method_id)));
	#else
		traits->ns = NULL;
		traits->name = NULL;
		(void)method_id;
	#endif
		traits->resolveSignatures(toplevel);
		return traits;
	}

	Traits* Traits::_newParameterizedTraits(Stringp name, Namespacep ns, Traits* _base)
	{
		Traits* newtraits = Traits::newTraits(this->pool, _base, this->getSizeOfInstance(), NULL, TRAITSTYPE_RT);
		newtraits->m_needsHashtable = this->m_needsHashtable;
		newtraits->name = name;
		newtraits->ns = ns;
		return newtraits;
	}

	void Traits::enableSkips(uint32_t nameCount) 
	{ 
		AvmAssert(!m_skips.test(0)); 
		AVMPLUS_TRAITS_MEMTRACK_ONLY( tmt_sub_mem(TMT_traits, m_skips.allocatedSize() ); )
		m_skips.resize(core->GetGC(), nameCount+1); 
		AVMPLUS_TRAITS_MEMTRACK_ONLY( tmt_add_mem(TMT_traits, m_skips.allocatedSize() ); )
		m_skips.set(0); 
	}

	TraitsPosPtr Traits::traitsPosStart() const
	{
		TraitsPosPtr pos = m_traitsPos;
		switch (posType())
		{
			case TRAITSTYPE_INSTANCE_FROM_ABC:	
				pos = skipToInstanceInitPos(pos);
				// fall thru, no break

			case TRAITSTYPE_CLASS_FROM_ABC:
			case TRAITSTYPE_SCRIPT_FROM_ABC:
				AvmCore::skipU30(pos, 1);		// skip in init_index
				break;

			case TRAITSTYPE_ACTIVATION:
				// nothing to do
				break;

			case TRAITSTYPE_CATCH:
			case TRAITSTYPE_FUNCTION:
			case TRAITSTYPE_NVA:
			case TRAITSTYPE_RT:
				pos = NULL;
				break;
		}
		return pos;
	}

	TraitsPosPtr Traits::skipToInstanceInitPos(TraitsPosPtr pos) const
	{
		AvmAssert(posType() == TRAITSTYPE_INSTANCE_FROM_ABC && pos != NULL);
		AvmCore::skipU30(pos, 2);		// skip the QName & base traits 
		const uint8_t theflags = *pos++;		
		const bool hasProtected = (theflags & 8) != 0;
		if (hasProtected)
		{
			AvmCore::skipU30(pos);
		}
		const uint32_t interfaceCount = AvmCore::readU30(pos);
		AvmCore::skipU30(pos, interfaceCount);
		return pos;
	}

	static bool is8ByteSlot(Traits* slotTE)
	{
		#ifdef AVMPLUS_64BIT
		const uint32_t BIG_TYPE_MASK = ~((1U<<BUILTIN_int) | (1U<<BUILTIN_uint) | (1U<<BUILTIN_boolean));
		#else
		const uint32_t BIG_TYPE_MASK = (1U<<BUILTIN_number);
		#endif
		
		return ((1 << Traits::getBuiltinType(slotTE)) & BIG_TYPE_MASK) != 0;
	}

	static int32_t pad4(int32_t& hole, int32_t& nextSlotOffset)
	{
		// 4-aligned, 4-byte field
		int32_t slotOffset;
		if (hole != -1)
		{
			// this is a trick: if we have 4-8-4, this allows us
			// to quietly rearrange into 4-4-8
			slotOffset = hole;
			hole = -1;
		}
		else
		{
			slotOffset = nextSlotOffset;
			nextSlotOffset += 4;
		}
		return slotOffset;
	}
	
	static int32_t pad8(int32_t& hole, int32_t& nextSlotOffset)
	{
		// 8-aligned, 8-byte field
		if (nextSlotOffset & 7)
		{
			AvmAssert((nextSlotOffset % 4) == 0);	// should always be a multiple of 4
			hole = nextSlotOffset;
			nextSlotOffset += 4;
		}
		int32_t slotOffset = nextSlotOffset;
		nextSlotOffset += 8;
		return slotOffset;
	}

	static SlotStorageType bt2sst(BuiltinType bt)
	{
		AvmAssert(bt != BUILTIN_void);
		switch (bt)
		{
			case BUILTIN_int:		return SST_int32;
			case BUILTIN_uint:		return SST_uint32;
			case BUILTIN_number:	return SST_double;
			case BUILTIN_boolean:	return SST_bool32;
			case BUILTIN_any:		return SST_atom;
			case BUILTIN_object:	return SST_atom;
			case BUILTIN_string:	return SST_string;
			case BUILTIN_namespace:	return SST_namespace;
			default:				return SST_scriptobject;
		}
	}

	// the logic for assigning slot id's is used in several places, so it's now collapsed here
	// rather than redundantly sprinkled thru several bits of code.
	class SlotIdCalcer
	{
	private:
		uint32_t m_slotCount;
		bool m_earlySlotBinding;
	public:
		SlotIdCalcer(uint32_t _baseSlotCount, bool _earlySlotBinding) : 
			m_slotCount(_baseSlotCount), 
			m_earlySlotBinding(_earlySlotBinding) 
		{
		}

		uint32_t calc_id(uint32_t id)
		{
			if (!id || !m_earlySlotBinding)
			{
				id = ++m_slotCount;
			}
			if (m_slotCount < id)
				m_slotCount = id;
			return id - 1;
		}
		
		uint32_t slotCount() const { return m_slotCount; }
	};
	
	struct NameEntry
	{
		const uint8_t* meta_pos;
		uint32_t qni, id, info, value_index;
		CPoolKind value_kind;
		TraitKind kind;
		uint8_t tag;
		
		void readNameEntry(const uint8_t*& pos);
	};
	
	void NameEntry::readNameEntry(const uint8_t*& pos)
	{
		qni = AvmCore::readU30(pos);
		tag = *pos++;
		kind = (TraitKind) (tag & 0x0f);
		value_kind = CONSTANT_unused_0x00;
		value_index = 0;

		// Read in the trait entry.
		switch (kind)
		{
			case TRAIT_Slot:
			case TRAIT_Const:
				id = AvmCore::readU30(pos);				// slot id
				info = AvmCore::readU30(pos);			// value type
				value_index = AvmCore::readU30(pos);	// value index
				if (value_index)
					value_kind = (CPoolKind)*pos++;		// value kind
				break;
			case TRAIT_Class:
				id = AvmCore::readU30(pos);		// slot id
				info = AvmCore::readU30(pos);	// classinfo
				break;
			case TRAIT_Getter:
			case TRAIT_Setter:
			case TRAIT_Method:
				AvmCore::skipU30(pos);			// disp id (never used)
				id = AvmCore::readU30(pos);		// method index
				info = 0;
				break;
			default:
				// unsupported traits type -- can't happen, caught in AbcParser::parseTraits
				AvmAssert(0);
				break;
		}
		meta_pos = pos;
		if (tag & ATTR_metadata)
		{
			uint32_t metaCount = AvmCore::readU30(pos);
			AvmCore::skipU30(pos, metaCount);
		}
	}
	
 	bool Traits::allowEarlyBinding() const
 	{
 		// the compiler can early bind to a type's slots when it's defined
 		// or when the base class came from another abc file and has zero slots
 		// this ensures you cant use the early opcodes to access an external type's
 		// private members.
		TraitsBindingsp tb = this->base ? this->base->getTraitsBindings() : NULL;
		while (tb != NULL && tb->slotCount > 0)
		{
			if (tb->owner->pool != this->pool && tb->slotCount > 0)
			{
				return false;
			}
			tb = tb->base;
		}
		return true;
	}

	void Traits::buildBindings(TraitsBindingsp basetb, 
								MultinameHashtable* bindings, 
								uint32_t& slotCount, 
								uint32_t& methodCount,
								const Toplevel* toplevel) const
	{
		const uint8_t* pos = traitsPosStart();

		const uint32_t baseSlotCount = basetb ? basetb->slotCount : 0;
		const uint32_t baseMethodCount = basetb ? basetb->methodCount : 0;

		//slotCount = baseSlotCount;
		methodCount = baseMethodCount;
		
		SlotIdCalcer sic(baseSlotCount, this->allowEarlyBinding());

		NameEntry ne;
		const uint32_t nameCount = pos ? AvmCore::readU30(pos) : 0;
		for (uint32_t i = 0; i < nameCount; i++)
        {
			ne.readNameEntry(pos);
			if (testSkip(i))
			{
				//Multiname qn;
				//this->pool->resolveQName_index(qni, qn, toplevel);
				//Namespacep ns = qn.getNamespace();
				//Stringp name = qn.getName();
				//core->console << "BB skipping definition " << i << " for " << this << " name=" << Multiname::format(core,ns,name) << "\n";
				continue;
			}
			
			// Didn't skip the trait, so do set up for the definition now.

			Multiname qn;
			this->pool->resolveQName(ne.qni, qn, toplevel);
			Namespacep ns = qn.getNamespace();
			Stringp name = qn.getName();

			switch (ne.kind)
            {
				case TRAIT_Slot:
				case TRAIT_Const:
				case TRAIT_Class:
				{
					uint32_t slot_id = sic.calc_id(ne.id);
					if (toplevel)
					{
						AvmAssert(!this->linked);
						
						// first time thru, we must do some additional verification checks... these were formerly 
						// done in AbcParser::parseTraits but require the base class to be resolved first, so we
						// now defer it to here.
						
						// illegal raw slot id.
						if (ne.id > nameCount)
							toplevel->throwVerifyError(kCorruptABCError);
						
						// slots are final.
						if (basetb && slot_id < basetb->slotCount) 
							toplevel->throwVerifyError(kIllegalOverrideError, core->toErrorString(qn), core->toErrorString(base));

						// a slot cannot override anything else.
						if (bindings->get(name, ns) != BIND_NONE)
							toplevel->throwVerifyError(kCorruptABCError);

						// In theory we should reject duplicate slots here; 
						// in practice we don't, as it causes problems with some existing content
						//if (basetb->findBinding(name, ns) != BIND_NONE)
						//	toplevel->throwVerifyError(kIllegalOverrideError, toplevel->core()->toErrorString(qn), toplevel->core()->toErrorString(this));
						
						// Interfaces cannot have slots.
						if (this->isInterface)
							toplevel->throwVerifyError(kIllegalSlotError, core->toErrorString(this));

					}
					AvmAssert(!(ne.id > nameCount));						// unhandled verify error
					AvmAssert(!(basetb && slot_id < basetb->slotCount));	// unhandled verify error
					AvmAssert(!(bindings->get(name, ns) != BIND_NONE));		// unhandled verify error
					bindings->add(name, ns, AvmCore::makeSlotBinding(slot_id, ne.kind==TRAIT_Slot ? BKIND_VAR : BKIND_CONST));
					break;
				}
				case TRAIT_Method:
				{
					Binding baseBinding = this->getOverride(basetb, ns, name, ne.tag, toplevel);
					if (baseBinding == BIND_NONE)
					{
						bindings->add(name, ns, AvmCore::makeMGSBinding(methodCount, BKIND_METHOD));
						// accessors require 2 vtable slots, methods only need 1.
						methodCount += 1;
					}
					else if (AvmCore::isMethodBinding(baseBinding))
					{
						// something got overridden, need new name entry for this subclass
						// but keep the existing disp_id
						bindings->add(name, ns, baseBinding);
					}
					else
					{
						if (toplevel)
							toplevel->throwVerifyError(kCorruptABCError);
						AvmAssert(!"unhandled verify error");
					}
					break;
				}
				case TRAIT_Getter:
				case TRAIT_Setter:
				{
					// if nothing already is defined in this class, use base class in case getter/setter has already been defined.
					Binding baseBinding = bindings->get(name, ns);
					if (baseBinding == BIND_NONE)
						baseBinding = this->getOverride(basetb, ns, name, ne.tag, toplevel);
						
					const BindingKind us = (ne.kind == TRAIT_Getter) ? BKIND_GET : BKIND_SET;
					const BindingKind them = (ne.kind == TRAIT_Getter) ? BKIND_SET : BKIND_GET;
					if (baseBinding == BIND_NONE)
					{
						bindings->add(name, ns, AvmCore::makeMGSBinding(methodCount, us));
						// accessors require 2 vtable slots, methods only need 1.
						methodCount += 2;
					}
					else if (AvmCore::isAccessorBinding(baseBinding))
					{
						// something maybe got overridden, need new name entry for this subclass
						// but keep the existing disp_id
						// both get & set bindings use the get id.  set_id = get_id + 1.
						if (AvmCore::bindingKind(baseBinding) == them)
						{
							baseBinding = AvmCore::makeGetSetBinding(baseBinding);
						}
						bindings->add(name, ns, baseBinding);
					}
					else
					{
						if (toplevel)
							toplevel->throwVerifyError(kCorruptABCError);
						AvmAssert(!"unhandled verify error");
					}
					break;
				}

				default:
					// unsupported traits type -- can't happen, caught in AbcParser::parseTraits
					AvmAssert(0);
					break;
            }
        } // for i
		
		slotCount = sic.slotCount();
	}

	uint32_t Traits::finishSlotsAndMethods(TraitsBindingsp basetb, 
									TraitsBindings* tb, 
									const Toplevel* toplevel,
									AbcGen* abcGen) const
	{
		const uint8_t* pos = traitsPosStart();

		SlotIdCalcer sic(basetb ? basetb->slotCount : 0, this->allowEarlyBinding());
		int32_t nextSlotOffset = this->getSlotAreaStart();
		int32_t hole = -1;

		NameEntry ne;
		const uint32_t nameCount = pos ? AvmCore::readU30(pos) : 0;
		for (uint32_t i = 0; i < nameCount; i++)
        {
			ne.readNameEntry(pos);
			if (testSkip(i))
			{
				//Multiname qn;
				//this->pool->resolveQName_index(qni, qn, toplevel);
				//Namespacep ns = qn.getNamespace();
				//Stringp name = qn.getName();
				//core->console << "FSM skipping definition " << i << " for " << this << " name=" << Multiname::format(core,ns,name) << "\n";
				continue;
			}
			
			// Didn't skip the trait, so do set up for the definition now.

			Multiname qn;
			this->pool->resolveQName(ne.qni, qn, toplevel);
			Namespacep ns = qn.getNamespace();
			Stringp name = qn.getName();

			switch (ne.kind)
            {
				case TRAIT_Slot:
				case TRAIT_Const:
				case TRAIT_Class:
				{
					uint32_t slotid = sic.calc_id(ne.id);
					// note, for TRAIT_Class, AbcParser::parseTraits has already verified that pool->cinits[ne.info] is not null
					Traitsp slotType = (ne.kind == TRAIT_Class) ? 
										(Traitsp)pool->cinits[ne.info]->declaringTraits :
										this->pool->resolveTypeName(ne.info, toplevel);
					uint32_t slotOffset = is8ByteSlot(slotType) ? 
											pad8(hole, nextSlotOffset) : 
											pad4(hole, nextSlotOffset);	// all slots get at least 4 bytes, even bool
					tb->setSlotInfo(slotid, slotType, bt2sst(getBuiltinType(slotType)), slotOffset);
					
					if (abcGen)
						genDefaultValue(ne.value_index, slotid, toplevel, slotType, ne.value_kind, *abcGen);
					break;
				}
				case TRAIT_Getter:
				case TRAIT_Setter:
				case TRAIT_Method:
				{
					const Binding b = tb->m_bindings->get(name, ns);
					AvmAssert(b != BIND_NONE);
					const uint32 disp_id = urshift(b, 3) + (ne.kind == TRAIT_Setter);
					AbstractFunction* f = this->pool->getMethodInfo(ne.id);
					AvmAssert(f->declaringTraits == this);
					tb->setMethodInfo(disp_id, f);
					break;
				}

				default:
					// unsupported traits type -- can't happen, caught in AbcParser::parseTraits
					AvmAssert(0);
					break;
            }
        } // for i
		return nextSlotOffset;
	}


	// Flex apps often have many interfaces redundantly listed, so first time thru,
	// eliminate redundant ones.
	void Traits::countInterfaces(const Toplevel* toplevel, List<Traitsp, LIST_NonGCObjects>& seen) const
	{
		if (this->base && seen.indexOf(this->base) < 0)
			seen.add(this->base);

		const uint8_t* pos = (this->posType() == TRAITSTYPE_INSTANCE_FROM_ABC) ? m_traitsPos : NULL;
		if (pos)
		{
			AvmCore::skipU30(pos, 2);		// skip the QName + basetraits
			const uint8_t theflags = *pos++;		
			if (theflags & 8)
				AvmCore::skipU30(pos);	// skip protected namespace
			
			const uint32_t interfaceCount = AvmCore::readU30(pos);
			for (uint32_t j = 0; j < interfaceCount; j++)
			{
				Traitsp intf = this->pool->resolveTypeName(pos, toplevel);
				AvmAssert(intf && intf->isInterface);
				if (intf && intf->isInterface && seen.indexOf(intf) < 0)
				{
					seen.add(intf);
					intf->countInterfaces(toplevel, seen);
				}
			}
		}
	}

	void Traits::addInterfaces(TraitsBindings* tb) const
	{
		if (this->base)
			tb->addOneInterface(this->base);

		const uint8_t* pos = (this->posType() == TRAITSTYPE_INSTANCE_FROM_ABC) ? m_traitsPos : NULL;
		if (pos)
		{
			AvmCore::skipU30(pos, 2);		// skip the QName + basetraits
			const uint8_t theflags = *pos++;		
			if (theflags & 8)
				AvmCore::skipU30(pos);	// skip protected namespace
			
			const uint32_t interfaceCount = AvmCore::readU30(pos);
			for (uint32_t j = 0; j < interfaceCount; j++)
			{
				// never need to pass toplevel here: we've already validated the typenames in AbcParser::parseInstanceInfos
				Traitsp intf = this->pool->resolveTypeName(pos, /*toplevel*/NULL);
				AvmAssert(intf && intf->isInterface);
				if (intf && intf->isInterface)
				{
					tb->addOneInterface(intf);
					intf->addInterfaces(tb);
				}
			}
		}
	}

	static uint8_t calcLog2(uint32_t cap)
	{
		uint8_t capLog = 1; // start with at least 2 entries
		while ((1U<<capLog) < cap)
		{
			++capLog;
		}
		AvmAssert((1U<<capLog) >= cap);
		return capLog;
	}

#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
	TraitsBindings* Traits::_buildTraitsBindings(const Toplevel* toplevel, AbcGen* abcGen, ImtBuilder* imtBuilder)
#else
	TraitsBindings* Traits::_buildTraitsBindings(const Toplevel* toplevel, AbcGen* abcGen)
#endif
	{
		// no, this can be called before the resolved bit is set
		//AvmAssert(this->linked);
#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
		{
			core->console << "Generate TraitsBindings for "<<this<<"\n";
		}
#endif
		TraitsBindings* thisData = NULL;

		// if we know the cap we need, go there right away, otherwise start at small power of 2
		// this saves tremendously on subsequent builds of this set of bindings since we don't have to
		// waste time growing the MNHT as we build it
		const int32_t bindingCap = m_bindingCapLog2 ? (1 << m_bindingCapLog2) : 2;

		MMgc::GC* gc = core->GetGC();
		MultinameHashtable* bindings = new (gc) MultinameHashtable(bindingCap);
		AvmAssert(bindings->numQuads == bindingCap);
		
		if (this->posType() == TRAITSTYPE_CATCH)
		{
			const uint8_t* pos = m_traitsPos;

			Traits* t = this->pool->resolveTypeName(pos, toplevel);

			// this assumes we save name/ns in all builds, not just verbose
			bindings->add(this->name, this->ns, AvmCore::makeSlotBinding(0, BKIND_VAR));

			thisData = TraitsBindings::alloc(gc, this, /*base*/NULL, bindings, /*slotCount*/1, /*methodCount*/0, /*interfaceCap*/0);
			thisData->setSlotInfo(0, t, bt2sst(getBuiltinType(t)), this->m_sizeofInstance);
			thisData->m_slotSize = is8ByteSlot(t) ? 8 : 4;
		}
		else
		{
			if (m_interfaceCapLog2 == 0)
			{
				List<Traitsp, LIST_NonGCObjects> seen(gc);
				countInterfaces(toplevel, seen);
				// a little redundant, but clarity is king
				m_interfaceCapLog2 = calcLog2(MathUtils::nextPowerOfTwo((5*seen.size() >> 2) + 1));
				AvmAssert(m_interfaceCapLog2 > 0);
			}

			TraitsBindingsp basetb = this->base ? this->base->getTraitsBindings() : NULL;

			// Copy protected traits from base class into new protected namespace
			if (basetb && base->protectedNamespace && this->protectedNamespace)
			{
				for (int i=0; (i = basetb->next(i)) != 0; )
				{
					if (basetb->nsAt(i) == base->protectedNamespace)
					{
						bindings->add(basetb->keyAt(i), this->protectedNamespace, basetb->valueAt(i));
					}
				}
			}
			
			uint32_t slotCount = 0;
			uint32_t methodCount = 0;
			buildBindings(basetb, bindings, slotCount, methodCount, toplevel);
			
			thisData = TraitsBindings::alloc(gc, this, basetb, bindings, slotCount, methodCount, (1U << m_interfaceCapLog2));
			
			thisData->m_slotSize = finishSlotsAndMethods(basetb, thisData, toplevel, abcGen) - m_sizeofInstance;
			addInterfaces(thisData);
#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
			thisData->fixInterfaceBindings(core, toplevel, imtBuilder);
#else
			thisData->fixInterfaceBindings(core, toplevel);
#endif
		}

		// hashtable (if we have one) must start on pointer-sized boundary...
		// much easier to always round slotsize up unconditionally rather than
		// only for cases with hashtable, so that's what we'll do. (MMgc currently
		// allocate in 8-byte increments anyway, so we're not really losing any space.)
		thisData->m_slotSize = (thisData->m_slotSize + (sizeof(uintptr_t)-1)) & ~(sizeof(uintptr_t)-1);
		
		// remember the cap we need
		if (m_bindingCapLog2 == 0)
			m_bindingCapLog2 = calcLog2(thisData->m_bindings->numQuads);	// remember capacity, not count
		AvmAssert(m_bindingCapLog2 > 0);

#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
		{
			core->console << this << " bindings\n";
			for (int32_t i = thisData->m_bindings->next(0); i != 0; i = thisData->m_bindings->next(i))
			{
				core->console << thisData->m_bindings->keyAt(i) << ":" << (uint32_t)(uintptr_t)(thisData->m_bindings->valueAt(i)) << "\n";
			}
			core->console << this << " end bindings \n";
		}
#endif
		return thisData;
	}

	TraitsMetadata* Traits::_buildTraitsMetadata()
	{
		AvmAssert(this->linked);

#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
		{
			core->console << "Generate TraitsMetadata for "<<this<<"\n";
		}
#endif
		TraitsBindingsp td = this->getTraitsBindings();
		
		MMgc::GC* gc = core->GetGC();
		
		TraitsMetadatap basetm = this->base ? this->base->getTraitsMetadata() : NULL;

		const uint32_t extra = td->slotCount * sizeof(TraitsMetadata::MetadataPtr) + td->methodCount * sizeof(TraitsMetadata::MetadataPtr);

		TraitsMetadata* tm = new (gc, extra) TraitsMetadata(basetm, this->pool, this->metadata_pos, td->slotCount, td->methodCount);
		AVMPLUS_TRAITS_MEMTRACK_ONLY( tmt_add_inst(TMT_tmi, tm); )
		tm->slotMetadataPos = (TraitsMetadata::MetadataPtr*)(tm + 1);
		tm->methodMetadataPos = (TraitsMetadata::MetadataPtr*)(tm->slotMetadataPos + tm->slotCount);

		const uint8_t* pos = traitsPosStart();
		const uint32_t nameCount = pos ? AvmCore::readU30(pos) : 0;
		SlotIdCalcer sic(td->base ? td->base->slotCount : 0, this->allowEarlyBinding());
		NameEntry ne;
		for (uint32_t i = 0; i < nameCount; i++)
        {
			ne.readNameEntry(pos);
			if (testSkip(i))
			{
				continue;
			}

			switch (ne.kind)
            {
				case TRAIT_Class:
					AvmAssert(0);
					// classes shouldn't have metadata, but just fall thru just in case
				case TRAIT_Slot:
				case TRAIT_Const:
				{
					const uint32_t slot_id = sic.calc_id(ne.id);
					if (ne.tag & ATTR_metadata)
						tm->slotMetadataPos[slot_id] = ne.meta_pos;
					break;
				}
				case TRAIT_Getter:
				case TRAIT_Setter:
				case TRAIT_Method:
				{
					if (ne.tag & ATTR_metadata)
					{
						Multiname qn;
						// passing NULL for toplevel here, since it's only used if a verification error occurs -- 
						// but if there was one, we would have encountered it during AbcParser::parseTraits.
						this->pool->resolveQName(ne.qni, qn, /*toplevel*/NULL);
						const Binding b = td->findBinding(qn.getName(), qn.getNamespace());
						AvmAssert(b != BIND_NONE);
						const uint32 disp_id = urshift(b,3) + (ne.kind == TRAIT_Setter);
						tm->methodMetadataPos[disp_id] = ne.meta_pos;
					}
					break;
				}

				default:
					// unsupported traits type -- can't happen, caught in AbcParser::parseTraits
					AvmAssert(0);
					break;
			}
        } // for i
			
		return tm;
	}

	/**
	 * This must be called before any method is verified or any
	 * instances are created.  It is not done eagerly in AbcParser
	 * because doing so would prevent circular type references between
	 * slots of cooperating classes.
     *
     * Resolve the type and position/width of each slot.
	 */
	void Traits::resolveSignatures(const Toplevel* toplevel)
	{
		// toplevel actually can be null, when resolving the builtin classes...
		// but they should never cause verification errors in functioning builds
		//AvmAssert(toplevel != NULL);
		
		if (linked)
			return;

		MMgc::GC* gc = core->GetGC();
		for (Traits* t = this->base; t != NULL; t = t->base)
		{
			// make sure our base classes our resolved. (must be done before calling _buildTraitsBindings)
			if (!t->linked) 
				t->resolveSignatures(toplevel);
		}

		AbcGen gen(gc);	
		TraitsBindings* tb;
#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
		if (core->IsMIREnabled())
		{
			ImtBuilder imtBuilder(gc);
			tb = _buildTraitsBindings(toplevel, &gen, &imtBuilder);
			imtBuilder.finish(m_imt, pool, toplevel);
		}
		else
		{
			tb = _buildTraitsBindings(toplevel, &gen, NULL);
		}
#else
		tb = _buildTraitsBindings(toplevel, &gen);
#endif
		this->genInitBody(toplevel, gen);

		AvmAssert(tb->owner == this);
		m_tbref = tb->GetWeakRef();
		// leave m_tmref as empty

		// all interfaces should have been resolved inside _buildTraitsBindings, UNLESS we are an interface ourself...
		// in which case let's do it now
		if (this->isInterface)
		{
			TraitsBindings::InterfaceInfo* tbi = tb->getInterfaces();
			TraitsBindings::InterfaceInfo* tbi_end = tbi + tb->interfaceCapacity;
			for ( ; tbi < tbi_end; ++tbi) 
			{
				Traits* ti = tbi->t;
				if (!ti || ti->linked) continue;
				ti->resolveSignatures(toplevel);
			}
		}

		switch (posType())
		{
			case TRAITSTYPE_INSTANCE_FROM_ABC:
			case TRAITSTYPE_CLASS_FROM_ABC:
			case TRAITSTYPE_SCRIPT_FROM_ABC:
			case TRAITSTYPE_ACTIVATION:
			case TRAITSTYPE_CATCH:
				m_totalSize = m_sizeofInstance + tb->m_slotSize;
				break;
			case TRAITSTYPE_FUNCTION:
			case TRAITSTYPE_NVA:
			case TRAITSTYPE_RT:
				m_totalSize = m_sizeofInstance;
				break;
		}
		
		AvmAssert(m_totalSize >= m_sizeofInstance);
		if (m_needsHashtable || (base && base->m_hashTableOffset && !isXMLType()))
		{
			// slotSize is already rounded up to pointer-sized boundary, but totalsize might not be
			// (eg for bool/int/uint, which have weird sizes)
			m_totalSize = ((m_totalSize+(sizeof(uintptr_t)-1))&~(sizeof(uintptr_t)-1));
			m_hashTableOffset = m_totalSize;
			m_totalSize += sizeof(Hashtable);
			AvmAssert(builtinType == BUILTIN_boolean ? true : (m_hashTableOffset & 3) == 0);
			AvmAssert((m_hashTableOffset & (sizeof(uintptr_t)-1)) == 0);
			AvmAssert((m_totalSize & (sizeof(uintptr_t)-1)) == 0);
		}

		// make sure all the methods have resolved types
		{
			const TraitsBindings::MethodInfo* tbm		= tb->getMethods();
			const TraitsBindings::MethodInfo* tbm_end	= tbm + tb->methodCount;
			for ( ; tbm < tbm_end; ++tbm) 
			{
				// don't assert: could be null if only one of a get/set pair is implemented
				//AvmAssert(tbm->f != NULL);
				if (tbm->f != NULL)
					tbm->f->resolveSignature(toplevel);
			}
		}

		bool legal = true;
		TraitsBindingsp tbbase = tb->base;	// might be null

		if (tbbase && tbbase->methodCount > 0)
		{
			// check concrete overrides
			const TraitsBindings::MethodInfo* basetbm		= tbbase->getMethods();
			const TraitsBindings::MethodInfo* basetbm_end	= basetbm + tbbase->methodCount;
			const TraitsBindings::MethodInfo* tbm			= tb->getMethods();
			for ( ; basetbm < basetbm_end; ++basetbm, ++tbm) 
			{
				if (basetbm->f != NULL && basetbm->f != tbm->f)
					legal &= tb->checkOverride(core, basetbm->f, tbm->f);
			}
		}

		if (legal && !this->isInterface)
		{
			legal &= tb->checkLegalInterfaces(core);
		}

		if (!legal)
		{
			AvmAssert(!linked);
			Multiname qname(ns, name);
			if (toplevel)
				toplevel->throwVerifyError(kIllegalOverrideError, core->toErrorString(&qname), core->toErrorString(this));
			AvmAssert(!"unhandled verify error");
		}

#ifdef MMGC_DRC
		tb->buildSlotDestroyInfo(gc, m_slotDestroyInfo);
#endif

		linked = true;

#ifdef AVMPLUS_TRAITS_MEMTRACK
		const char* xstr = name ? name->toUTF8String()->c_str() : "(null)";
		rawname = (char*)gc->Alloc(strlen(xstr)+1);
		strcpy(rawname, xstr);
#endif
	}

	// static
	bool Traits::isMachineCompatible(const Traits* a, const Traits* b)
	{
		return a == b ||
			// *, Object, and Void are each represented as Atom
			(!a || a->builtinType == BUILTIN_object || a->builtinType == BUILTIN_void) &&
			(!b || b->builtinType == BUILTIN_object || b->builtinType == BUILTIN_void) ||
			// all other non-pointer types have unique representations
			(a && b && !a->isMachineType() && !b->isMachineType());
	}

#ifdef AVMPLUS_VERBOSE
	Stringp Traits::format(AvmCore* core) const
	{
		if (name != NULL)
			return Multiname::format(core, ns, name);
		else
			return core->concatStrings(core->newString("Traits@"),
									   core->formatAtomPtr((uintptr)this));
	}
#endif

	void Traits::genDefaultValue(uint32_t value_index, uint32 slot_id, const Toplevel* toplevel, Traitsp slotType, CPoolKind kind, AbcGen& gen) const
		{
		// toplevel actually can be null, when resolving the builtin classes...
		// but they should never cause verification errors in functioning builds
		//AvmAssert(toplevel != NULL);

		Atom value = value_index ? pool->getDefaultValue(toplevel, value_index, kind, slotType) : 0;
		switch (Traits::getBuiltinType(slotType))
		{
			case BUILTIN_any:
			{
				AvmAssert(slotType == NULL);
				
				if (!value_index) value = undefinedAtom;

				if (value == 0)
					return;

				break;
			}
			case BUILTIN_object:
			{
				if (!value_index) value = nullObjectAtom;

				if (value == undefinedAtom)
					goto illegal_default;

				if (value == 0)
					return;

				break;
			}
			case BUILTIN_number:
			{
				if (!value_index) value = core->kNaN;

				if (!(AvmCore::isInteger(value)||AvmCore::isDouble(value)))
					goto illegal_default;

				if (AvmCore::number_d(value) == 0)
					return;

				break;
			}
			case BUILTIN_boolean:
			{
				if (!value_index) value = falseAtom;
				
				if (!AvmCore::isBoolean(value))
					goto illegal_default;

				AvmAssert(urshift(falseAtom,3) == 0);
				if (value == falseAtom)
					return;
				
				AvmAssert(value == trueAtom);
				break;
			}
			case BUILTIN_uint:
			{
				if (!value_index) value = (0|kIntegerType);
				
				if (!AvmCore::isInteger(value) && !AvmCore::isDouble(value)) 
					goto illegal_default;

				const double d = AvmCore::number_d(value);
				if (d != (uint32_t)d) 
					goto illegal_default;

				if (value == (0|kIntegerType))
					return;

				break;
			}
			case BUILTIN_int:
			{
				if (!value_index) value = (0|kIntegerType);

				if (!AvmCore::isInteger(value) && !AvmCore::isDouble(value)) 
					goto illegal_default;

				const double d = AvmCore::number_d(value);
				if (d != (int32_t)d)
					goto illegal_default;
			
				if (value == (0|kIntegerType))
					return;

				break;
			}
			case BUILTIN_string:
			{
				if (!value_index) value = nullStringAtom;

				if (!(AvmCore::isNull(value) || AvmCore::isString(value)))
					goto illegal_default;

				if (AvmCore::isNull(value))
					return;

				break;
			}
			case BUILTIN_namespace:
			{
				if (!value_index) value = nullNsAtom;

				if (!(AvmCore::isNull(value) || AvmCore::isNamespace(value)))
					goto illegal_default;

				if (AvmCore::isNull(value))
					return;

				break;
			}
			default:
			{								
				AvmAssert(slotType->builtinType != BUILTIN_void);
				// any other type: only allow null default value
				if (!value_index) value = nullObjectAtom;
				if (!AvmCore::isNull(value))
					goto illegal_default;
				break;
			}
		}

		gen.getlocalN(0);
		if (value == undefinedAtom)
			gen.pushundefined();
		else if (AvmCore::isNull(value))
			gen.pushnull();
		else if (value == core->kNaN)
			gen.pushnan();
		else if (value == trueAtom)
			gen.pushtrue();
		else
			gen.pushconstant(kind, value_index);
				gen.setslot(slot_id);				
		return;

	illegal_default:
		if (toplevel)
			toplevel->throwVerifyError(kIllegalDefaultValue, core->toErrorString(Multiname(slotType->ns, slotType->name)));
		AvmAssert(!"unhandled verify error");
	}

	void Traits::genInitBody(const Toplevel* toplevel, AbcGen& gen)
	{
		// if initialization code gen is required, create a new method body and write it to traits->init->body_pos
		if (gen.size() == 0)
			return;
		
		MMgc::GC* gc = core->GetGC();
		AbcGen newMethodBody(gc, uint32_t(16 + gen.size()));	// @todo 16 is a magic value that was here before I touched the code -- I don't know the significance

		// insert body preamble
		MethodInfo* new_init = NULL;
		
		if (this->init) 
		{
			new_init = (MethodInfo*)(AbstractFunction*)this->init;
			const uint8_t* pos = new_init->body_pos;
			if (!new_init->body_pos) 
				toplevel->throwVerifyError(kCorruptABCError);

			uint32_t maxStack = AvmCore::readU30(pos);
			// the code we're generating needs at least 2
			maxStack = maxStack > 1 ? maxStack : 2;
			newMethodBody.writeInt(maxStack); // max_stack
			newMethodBody.writeInt(AvmCore::readU30(pos)); //local_count
			newMethodBody.writeInt(AvmCore::readU30(pos)); //init_scope_depth
			newMethodBody.writeInt(AvmCore::readU30(pos)); //max_scope_depth

			// skip real code length
			uint32_t code_length = AvmCore::readU30(pos);
		
			// if first instruction is OP_constructsuper keep it as first instruction
			if (*pos == OP_constructsuper)
			{
				gen.getBytes().insert(0, OP_constructsuper);
				// don't invoke it again later
				pos++;
				code_length--;
			}
			gen.abs_jump(pos, code_length);	
		}
		else 
		{
			// make one
			new_init = new (gc) MethodInfo();
			new_init->declaringTraits = this;
			new_init->pool = this->pool;
			new_init->param_count = 0;
			new_init->restOffset = sizeof(Atom); // sizeof(this)
			new_init->initParamTypes(1);
			new_init->setParamType(0, this);	
			new_init->setReturnType(core->traits.void_itraits);
			new_init->flags |= AbstractFunction::LINKED;
			this->init = new_init;

			newMethodBody.writeInt(2); // max_stack
			newMethodBody.writeInt(1); //local_count
			newMethodBody.writeInt(1); //init_scope_depth
			newMethodBody.writeInt(1); //max_scope_depth

			gen.returnvoid();
		}

		newMethodBody.writeInt((uint32_t)gen.size()); // code length
		newMethodBody.writeBytes(gen.getBytes());

		// no exceptions, when we jump to the real code, we'll read the exceptions for that code
		newMethodBody.writeInt(0);

		// the verifier and interpreter don't read the activation traits so stop here
		uint8_t* newBytes = (uint8_t*) gc->Alloc(newMethodBody.size());
		memcpy(newBytes, newMethodBody.getBytes().getData(), newMethodBody.size());
		//init->body_pos = newBytes;
		WB(gc, new_init, &new_init->body_pos, newBytes);
	}

#ifdef MMGC_DRC
	void Traits::destroyInstance(ScriptObject* obj) const
	{
		AvmAssert(linked);

		Hashtable* ht = m_hashTableOffset ? obj->getTable() : NULL;

		// start by clearing native space to zero (except baseclasses)
		uint32_t* p = (uint32_t*)((char*)obj + sizeof(AvmPlusScriptableObject));
		AvmAssert((uintptr_t(p) & 0x3) == 0);
		const uint32_t mysize = m_sizeofInstance - uint32_t(sizeof(AvmPlusScriptableObject));
		AvmAssert((mysize & 0x3) == 0); // we assume all sizes are multiples of 4

		const uint32_t slotAreaSize = getSlotAreaSize();
		if (!m_slotDestroyInfo.test(0))
		{
			AvmAssert(m_slotDestroyInfo.cap() == 1);
			// no RCObjects, so just zero it all... my, that was easy
			memset(p, 0, mysize + slotAreaSize);
		}
		else
		{
			memset(p, 0, mysize);
			p += (mysize>>2);

			AvmAssert(m_slotDestroyInfo.cap() >= 1);
			AvmAssert((uintptr_t(p) & 3) == 0);
			const uint32_t bitsUsed = slotAreaSize / sizeof(uint32_t);	// not sizeof(Atom)!
			GC* gc = GC::GetGC(obj);
			for (uint32_t bit = 1; bit <= bitsUsed; bit++) 
			{
				if (m_slotDestroyInfo.test(bit))
				{
					#ifdef AVMPLUS_64BIT
					AvmAssert((uintptr_t(p) & 7) == 0);	// we had better be on an 8-byte boundary...
					#endif
					Atom a = *(const Atom*)p;
					RCObject* rc = NULL;
					switch (atomKind(a))
					{
						case kStringType:
						case kObjectType:
						case kNamespaceType:
							rc = (RCObject*)atomPtr(a);
							break;
						case kSpecialType:
							rc = (RCObject*)atomPtr(a);
							// kSpecialType might be GC or RC, gotta check
							if (rc && !gc->IsRCObject(rc))
								rc = NULL;
							break;
					}
					if (rc)
					{
						AvmAssert(GC::GetGC(obj)->IsRCObject(rc));
						rc->DecrementRef();
					}
				}
				*p++ = 0;
			}
		}

		// finally, zap the hashtable (if any)
		if (ht)
		{
			ht->destroy();
		}
		
	}
#endif

#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
	ImtBuilder::ImtBuilder(MMgc::GC* _gc) : gc(_gc)
	{
		memset(entries, 0, sizeof(ImtEntry*)*Traits::IMT_SIZE);
	}

	void ImtBuilder::addEntry(AbstractFunction* virt, uint32_t disp_id)
	{
		AvmAssert(virt != NULL);
		const uint32_t i = uint32_t(virt->iid() % Traits::IMT_SIZE);
#ifdef AVMPLUS_VERBOSE
		if (entries[i] && virt->pool->verbose)
			virt->core()->console << "conflict " << (uint64_t)virt->iid() << " " << i << "\n";
#endif
		entries[i] = new (gc) ImtEntry(virt, entries[i], disp_id);
	}

	void ImtBuilder::finish(Binding imt[], PoolObject* pool, const Toplevel *toplevel)
	{
		for (uint32_t i = 0; i < Traits::IMT_SIZE; i++)
		{
			ImtEntry *e = entries[i];
			if (e == NULL)
			{
				imt[i] = BIND_NONE;
			}
			else if (e->next == NULL)
			{
				// single entry, no conflict
				imt[i] = AvmCore::makeMGSBinding(e->disp_id, BKIND_METHOD);
				gc->Free(e);
			}
			else
			{
				// build conflict stub
				#if defined AVMPLUS_MIR
				CodegenMIR imtgen(pool);
				#elif defined FEATURE_NANOJIT
				CodegenIMT imtgen(pool);
				#endif

				TRY(pool->core, kCatchAction_Rethrow)
				{
					void* thunk = imtgen.emitImtThunk(e);
					imt[i] = AvmCore::makeITrampBinding(uintptr_t(thunk));
					if (imtgen.overflow)
						toplevel->throwError(kOutOfMemoryError);
				}
				CATCH (Exception* exception) 
				{
					#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
					imtgen.clearMIRBuffers();
                    #endif

					// re-throw exception
					pool->core->throwException(exception);
				}
				END_CATCH
				END_TRY
			}
		}
	}
#endif 
	
	Stringp Traits::formatClassName()
	{
#ifndef DEBUGGER
		Stringp fullName=NULL;
#endif
		if(!fullName)
		{
			Multiname qname(ns, name);
			qname.setQName();
			StringBuffer buffer(core);
			buffer << qname;
			int length = buffer.length();
			if (length && buffer.c_str()[length-1] == '$') {
				fullName = core->newString(buffer.c_str(), length-1);
			} else {
				fullName = core->newString(buffer.c_str());
			}
		}
		return fullName;
	}


	Binding Traits::getOverride(TraitsBindingsp basetb, Namespacep ns, Stringp name, int tag, const Toplevel* toplevel) const
	{
		Binding baseBinding = BIND_NONE;
		if (base)
		{
			const Namespacep lookupNS = (protectedNamespace == ns && base->protectedNamespace) ? (Namespacep)base->protectedNamespace : ns;
			AvmAssert(basetb != NULL);
			baseBinding = basetb->findBinding(name, lookupNS);
		}
		const BindingKind baseBindingKind = AvmCore::bindingKind(baseBinding);

		const TraitKind kind = TraitKind(tag & 0x0f);
		AvmAssert(kind >= 0 && kind < TRAIT_COUNT); 

		static const uint8_t kDesiredKind[TRAIT_COUNT] = 
		{
			BKIND_NONE,						// TRAIT_Slot
			BKIND_METHOD,					// TRAIT_Method
			BKIND_GET,						// TRAIT_Getter
			BKIND_SET,						// TRAIT_Setter
			BKIND_NONE,						// TRAIT_Class
			BKIND_NONE,						// TRAIT_Function
			BKIND_NONE						// TRAIT_Const
		};

		const BindingKind desiredKind = BindingKind(kDesiredKind[kind]);
		const uint8_t dkMask = uint8_t(1 << desiredKind);

		// given baseBindingKind, what are legal desiredKinds?
		static const uint8_t kLegalBaseKinds[8] = 
		{
			(1<<BKIND_METHOD) | (1<<BKIND_GET) | (1<<BKIND_SET),	// BKIND_NONE
			(1<<BKIND_METHOD),										// BKIND_METHOD
			0,														// BKIND_VAR
			0,														// BKIND_CONST
			0,														// BKIND_ITRAMP
			(1<<BKIND_GET) | (1<<BKIND_SET),						// BKIND_GET
			(1<<BKIND_GET) | (1<<BKIND_SET),						// BKIND_SET
			(1<<BKIND_GET) | (1<<BKIND_SET)							// BKIND_GETSET
		};

		if ((kLegalBaseKinds[baseBindingKind] & dkMask) == 0)
			goto failure;

		// given baseBindingKind, which desiredKinds *require* override?
		static const uint8_t kOverrideRequired[8] = 
		{
			0,														// BKIND_NONE
			(1<<BKIND_METHOD),										// BKIND_METHOD
			0,														// BKIND_VAR
			0,														// BKIND_CONST
			0,														// BKIND_ITRAMP
			(1<<BKIND_GET),											// BKIND_GET
			(1<<BKIND_SET),											// BKIND_SET
			(1<<BKIND_GET) | (1<<BKIND_SET)							// BKIND_GETSET
		};
		
		if (((kOverrideRequired[baseBindingKind] & dkMask) ? ATTR_override : 0) != (tag & ATTR_override))
			goto failure;

		return baseBinding;

failure:

#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console << "illegal override in "<< this << ": " << Multiname(ns,name) <<"\n";
#endif
		if (toplevel)
			toplevel->throwVerifyError(kIllegalOverrideError, toplevel->core()->toErrorString(Multiname(ns,name)), toplevel->core()->toErrorString(this));
		AvmAssert(!"unhandled verify error");
		return BIND_NONE;
	}

	TraitsBindings* FASTCALL Traits::_getTraitsBindings() 
	{ 
		AvmAssert(this->linked);
		// note: TraitsBindings are always built the first time in resolveSignature; this is only 
		// executed for subsequent re-buildings. Thus we pass NULL for toplevel (it's only used
		// for verification errors, but those will have been caught prior to this) and for
		// abcGen and imtBuilder (since those only need to be done once).
#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
		TraitsBindings* tb = _buildTraitsBindings(/*toplevel*/NULL, /*abcGen*/NULL, /*imtBuilder*/NULL);
#else
		TraitsBindings* tb = _buildTraitsBindings(/*toplevel*/NULL, /*abcGen*/NULL);
#endif
		m_tbref = tb->GetWeakRef();
		core->tbCache()->add(tb);
		return tb;
	}

	TraitsMetadata* FASTCALL Traits::_getTraitsMetadata() 
	{ 
		AvmAssert(this->linked);
		TraitsMetadata* tm = _buildTraitsMetadata();
		m_tmref = tm->GetWeakRef();
		core->tmCache()->add(tm);
 		return tm;
	}
}
