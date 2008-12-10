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

#ifndef __avmplus_Traits__
#define __avmplus_Traits__


namespace avmplus
{
	typedef ClassClosure* (*CreateClassClosureProc)(VTable*);
	typedef ScriptObject* (*CreateGlobalObjectProc)(VTable*, ScriptObject*);

#ifdef AVMPLUS_TRAITS_MEMTRACK
	// doesn't really belong here, but needs to go somewhere... good enough for now.
	enum TMTTYPE 
	{ 
		TMT_traits, 
		TMT_tbi, 
		TMT_tmi, 
		TMT_vtable, 
		TMT_methodenv, 
		TMT_abstractfunction, 
		TMT_COUNT 
	};

	extern void tmt_add_mem(TMTTYPE t, size_t d);
	extern void tmt_sub_mem(TMTTYPE t, size_t d);

	extern void tmt_add_inst(TMTTYPE t, const void* inst);
	extern void tmt_sub_inst(TMTTYPE t, const void* inst);

	#define AVMPLUS_TRAITS_MEMTRACK_ONLY(x) x
#else
	#define AVMPLUS_TRAITS_MEMTRACK_ONLY(x) 
#endif

#ifdef AVMPLUS_TRAITS_MEMTRACK
	typedef MMgc::GCFinalizedObject TRAITSBASE;
#else
	typedef MMgc::GCObject TRAITSBASE;
#endif

	// Note: we rely on being able to store this in 3 bits. 
	enum TraitsPosType
	{
		TRAITSTYPE_INSTANCE_FROM_ABC		= 0,	
		TRAITSTYPE_CLASS_FROM_ABC			= 1,
		TRAITSTYPE_SCRIPT_FROM_ABC			= 2,
		TRAITSTYPE_CATCH					= 3,
		TRAITSTYPE_ACTIVATION				= 4,
		TRAITSTYPE_FUNCTION					= 5,		// prototype function -- traitsPos will always be null
		TRAITSTYPE_NVA						= 6,		// null/void/any -- traitsPos will always be null
		TRAITSTYPE_RT						= 7			// Traits defined at runtime, e.g. instantiated parameterized types
	};
	
	// Note: we rely on this being <= 32 entries. None of the enumeration values are magic,
	// so we just keep them in alphabetical order for simplicity.
	enum BuiltinType
	{
		BUILTIN_any,	// this is the "*" type in AS3, corresponds to a NULL Traits in C++ (not the "null" value in AS3")
		BUILTIN_array,
		BUILTIN_boolean,
		BUILTIN_class,	// class Class only, not subclasses of Class
		BUILTIN_date,
		BUILTIN_error,
		BUILTIN_function,
		BUILTIN_int,
		BUILTIN_math,
		BUILTIN_methodClosure,
		BUILTIN_namespace,
		BUILTIN_null,	// this is the "null" AS3 value, not a NULL Traits* in C++
		BUILTIN_number,
		BUILTIN_object, // this is Object specifically, not a subclass thereof
		BUILTIN_qName,
		BUILTIN_regexp,
		BUILTIN_string,
		BUILTIN_uint,
		BUILTIN_vector,
		BUILTIN_vectordouble,
		BUILTIN_vectorint,
		BUILTIN_vectorobj,
		BUILTIN_vectoruint,
		BUILTIN_void,
		BUILTIN_xmlList,
		BUILTIN_xml,

		BUILTIN_none,		// "none of the above" (ie it's not any of the rest of this enum)
		
		BUILTIN_COUNT
	};

	const uint32_t NOT_DERIVED_OR_XML_MASK = 
// commented out, why?
//		(1<<BUILTIN_array) |
//		(1<<BUILTIN_date) |
//		(1<<BUILTIN_regexp) |
		(1<<BUILTIN_boolean) |
		(1<<BUILTIN_class) |
		(1<<BUILTIN_function) |
		(1<<BUILTIN_int) |
		(1<<BUILTIN_methodClosure) |
		(1<<BUILTIN_namespace) |
		(1<<BUILTIN_null) |
		(1<<BUILTIN_number) |
		(1<<BUILTIN_object) |
		(1<<BUILTIN_qName) |
		(1<<BUILTIN_string) |
		(1<<BUILTIN_uint) |
		(1<<BUILTIN_void) |
		(1<<BUILTIN_xmlList) |
		(1<<BUILTIN_xml);

	const uint32_t MACHINE_TYPE_MASK = (1<<BUILTIN_object) | (1<<BUILTIN_void) | (1<<BUILTIN_int) | (1<<BUILTIN_uint) | (1<<BUILTIN_boolean) | (1<<BUILTIN_number);
	const uint32_t NUMERIC_TYPE_MASK = (1<<BUILTIN_int) | (1<<BUILTIN_uint) | (1<<BUILTIN_number);
	const uint32_t XML_TYPE_MASK = (1<<BUILTIN_xml) | (1<<BUILTIN_xmlList);

	typedef const uint8_t* TraitsPosPtr;

#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
	class ImtBuilder;
#endif

	// Note: we rely on this being <= 8 entries.
	enum SlotStorageType
	{
		// we rely on these 4 being first, so we can do <= SST_scriptobject in isAtomOrRCObjectSlot.
		// SST_atom is most frequently encountered, so value of zero is best
		SST_atom,
		SST_string,
		SST_namespace,
		SST_scriptobject,
		
		SST_int32,
		SST_uint32,
		SST_bool32,
		SST_double
	};
	inline bool isAtomOrRCObjectSlot(SlotStorageType sst) { return sst <= SST_scriptobject; }
	
	class TraitsBindings : public QCachedItem
	{
		friend class Traits;
	
	private:
		struct SlotInfo
		{
			Traitsp type;	
			uint32_t offsetAndSST;	// lower 3 bits: SlotStorageType, upper 29 bits: offset div 4
			#ifdef AVMPLUS_64BIT
			uint32_t padding;	// alignment to power-of-two boundary is a Good Thing here
			#endif
			inline SlotStorageType sst() const { return SlotStorageType(offsetAndSST & 7); }
			inline uint32_t offset() const { return (offsetAndSST >> 3) << 2; }
		};

		struct MethodInfo
		{
			AbstractFunction* f;
		};
		
		struct InterfaceInfo
		{
			Traits* t;
		};
		
	private:
		inline TraitsBindings(Traits* _owner, 
							TraitsBindingsp _base, 
							MultinameHashtable* _bindings,
							uint32_t _slotCount, 
							uint32_t _methodCount, 
							uint32_t _interfaceCapacity) : 
			owner(_owner),
			base(_base),
			m_bindings(_bindings),
			slotCount(_slotCount), 
			methodCount(_methodCount), 
			interfaceCapacity(_interfaceCapacity),
			m_slotSize(0)
		{
		}

#ifdef AVMPLUS_TRAITS_MEMTRACK 
		virtual ~TraitsBindings();
#endif

	public:
		static const uint32_t MAX_SLOT_OFFSET = (1U << 31) - 1;

	public:
		
		void addOneInterface(const Traits* intf);

		static TraitsBindings* alloc(MMgc::GC* gc, Traits* _owner, TraitsBindingsp _base, MultinameHashtable* _bindings, uint32_t slotCount, uint32_t methodCount, uint32_t interfaceCount);

#ifdef MMGC_DRC
		void buildSlotDestroyInfo(MMgc::GC* gc, FixedBitSet& slotDestroyInfo) const;
#endif

		Traitsp getSlotTraits(uint32_t i) const { AvmAssert(i < slotCount); return getSlots()[i].type; }
		uint32_t getSlotOffset(uint32_t i) const { AvmAssert(i < slotCount); return getSlots()[i].offset(); }
// if you need SST you probably want offset too; call calcSlotAddrAndSST
//		SlotStorageType getSlotSST(uint32_t i) const { AvmAssert(i < slotCount); return getSlots()[i].sst(); }
		SlotStorageType calcSlotAddrAndSST(uint32_t i, void* pin, void*& pout) const 
		{ 
			AvmAssert(i < slotCount); 
			uint32_t offsetAndSST = getSlots()[i].offsetAndSST; 
			pout = (void*)(((uint32_t*)pin) + (offsetAndSST >> 3));
			return SlotStorageType(offsetAndSST & 7);
		}
		inline Traitsp getInterface(uint32 i) const { AvmAssert(i < interfaceCapacity); return getInterfaces()[i].t; }
		inline AbstractFunction* getMethod(uint32_t i) const { AvmAssert(i < methodCount); return getMethods()[i].f; }
		bool containsInterface(Traitsp t) const;
		Binding findBinding(Stringp key) const;
		Binding findBinding(Stringp name, Namespacep ns) const;
		Binding findBinding(Stringp name, NamespaceSetp nsset) const;

		inline int32_t next(int32_t index) const { return m_bindings->next(index); }
		inline Stringp keyAt(int32_t index) const { return m_bindings->keyAt(index); }
		inline Namespacep nsAt(int32_t index) const { return m_bindings->nsAt(index); }
		inline Binding valueAt(int32_t index) const { return Binding(m_bindings->valueAt(index)); }

	private:
		SlotInfo* getSlots() { return (SlotInfo*)(this + 1); }
		const SlotInfo* getSlots() const { return (const SlotInfo*)(this + 1); }

		InterfaceInfo* getInterfaces() { return (InterfaceInfo*)(getSlots() + slotCount); }
		const InterfaceInfo* getInterfaces() const { return (const InterfaceInfo*)(getSlots() + slotCount); }

		MethodInfo* getMethods() { return (MethodInfo*)(getInterfaces() + interfaceCapacity); }
		const MethodInfo* getMethods() const { return (const MethodInfo*)(getInterfaces() + interfaceCapacity); }

		inline void setSlotInfo(uint32_t i, Traits* t, SlotStorageType sst, uint32_t offset) 
		{ 
			AvmAssert(i < slotCount); 
			// don't need WB here
			getSlots()[i].type = t;
			// offset is always a multiple of 4 so skip those, gives us a max of 1<<31-1
			AvmAssert((offset & 3) == 0);
			AvmAssert(offset <= MAX_SLOT_OFFSET);
			getSlots()[i].offsetAndSST = (offset<<1) | uint32_t(sst);
		}

		inline void setMethodInfo(uint32_t i, AbstractFunction* f) 
		{ 
			AvmAssert(i < methodCount); 
			// don't need WB here
			getMethods()[i].f = f;
		}

		void addOneInterface(Traitsp intf);
		InterfaceInfo* findInterfaceAddr(Traitsp intf);
		inline const InterfaceInfo* findInterfaceAddr(Traitsp intf) const { return const_cast<TraitsBindings*>(this)->findInterfaceAddr(intf); }
		bool checkOverride(AvmCore* core, AbstractFunction* virt, AbstractFunction* over) const;
		bool checkLegalInterfaces(AvmCore* core) const;
#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
		void fixInterfaceBindings(AvmCore* core, const Toplevel* toplevel, ImtBuilder* imtBuilder);
#else
		void fixInterfaceBindings(AvmCore* core, const Toplevel* toplevel);
#endif

	// ------------------------ DATA SECTION BEGIN
		public:		const Traitsp					owner;
		public:		const TraitsBindingsp			base; 
		private:	MultinameHashtable* const		m_bindings;
		public:		const uint32_t					slotCount;			// including slots in our base classes
		public:		const uint32_t					methodCount;		// including methods in our base classes
		public:		const uint32_t					interfaceCapacity;	// cap, not count: will contain null entries
		private:	uint32_t						m_slotSize;			// size of slot area in bytes, including base classes
		// plus extra at end
	// ------------------------ DATA SECTION END

	};

	class TraitsMetadata : public QCachedItem
	{
		friend class Traits;

	public:
		typedef const uint8_t* MetadataPtr;

	private:
		inline TraitsMetadata(TraitsMetadatap _base, PoolObject* _residingPool, MetadataPtr _metadata_pos, uint32_t _slotCount, uint32_t _methodCount) : 
			base(_base),
			residingPool(_residingPool),
			slotCount(_slotCount), 
			methodCount(_methodCount),
			metadataPos(_metadata_pos),
			slotMetadataPos(NULL),
			methodMetadataPos(NULL)
		{
		}

	public:

#ifdef AVMPLUS_TRAITS_MEMTRACK 
		virtual ~TraitsMetadata();
#endif

		MetadataPtr getMetadataPos(PoolObject*& residingPool) const { residingPool = this->residingPool; return metadataPos; }
		MetadataPtr getSlotMetadataPos(uint32_t i, PoolObject*& residingPool) const;
		MetadataPtr getMethodMetadataPos(uint32_t i, PoolObject*& residingPool) const;

	// ------------------------ DATA SECTION BEGIN
		public:		const TraitsMetadatap			base; 
		private:	PoolObject* const				residingPool;
		public:		const uint32_t					slotCount;			// including slots in our base classes
		public:		const uint32_t					methodCount;		// including methods in our base classes
		private:	MetadataPtr						metadataPos;
		private:	MetadataPtr*					slotMetadataPos;
		private:	MetadataPtr*					methodMetadataPos;
	// ------------------------ DATA SECTION END
	};

	/**
	 * Traits objects describe the layout of objects.  Traits are
	 * used to describe a variety of things in the VM, such as
	 * classes, global objects, and activation objects.
	 *
	 * A Traits object contains a hash table with the names of
	 * all properties and methods.  Each name maps to a binding.
	 *
	 * There are several types of binding: binding to a slot,
	 * binding to an accessor, binding to a virtual function,
	 * binding to a final function.
	 */
	class Traits : public TRAITSBASE 
	{
		friend class TraitsBindings;	// for m_sizeofInstance
		#if defined AVMPLUS_MIR
		friend class CodegenMIR;
		#elif defined FEATURE_NANOJIT
		friend class CodegenLIR;
		#endif

	public:
#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
		// choose a number that is relatively prime to sizeof(AbstractFunction)/8
		// since we use the AbstractFunction pointer as the interface method id
		// smaller = dense table, few large conflict stubs
		// larger  = sparse table, many small conflict stubs 

#ifdef _DEBUG
		static const uint32_t IMT_SIZE = 3;  // good for testing all code paths
#else
		static const uint32_t IMT_SIZE = 7;  // good for performance
#endif
#endif // AVMPLUS_MIR | FEATURE_NANOJIT

		inline void resetSizeof(uint32_t size)
		{
			// @todo -- this is a hack for things like FlashPlayer that subclass
			// Toplevel with a native class; since Toplevel is "special" we have to 
			// be able to adjust this after creation. Eventually we should make Toplevel
			// not be a subclass of ScriptObject (this is the case in TT) and at that point
			// this special case can be removed.
			AvmAssert(size <= 0xffff);
			if (linked)
			{
				m_totalSize -= m_sizeofInstance;
				m_totalSize += uint16_t(size);
			}
			m_sizeofInstance = uint16_t(size);
		}

		inline uint32_t getSizeOfInstance() const { return m_sizeofInstance; }
		inline uint32_t getHashtableOffset() const { AvmAssert(linked); return m_hashTableOffset; }
		inline uint32_t getTotalSize() const { AvmAssert(linked); return m_totalSize; }

		// in bytes. includes size for all base classes too.
		inline uint32_t getSlotAreaSize() const { AvmAssert(linked); return m_totalSize - m_sizeofInstance - (m_hashTableOffset ? sizeof(Hashtable) : 0); }

		inline uint32_t getSlotAreaStart() const { return m_sizeofInstance + (base ? base->getSlotAreaSize() : 0); }

		// in bytes. includes size for all base classes too.
		inline uint32_t getExtraSize() const { AvmAssert(linked); AvmAssert(m_totalSize >= m_sizeofInstance); return m_totalSize - m_sizeofInstance; }

		// sadly, it's still more efficient to stash this in Traits itself, as it's nontrivial to recover when
		// we rebuild the TraitMethodInfo. 
		void setMetadataPos(const byte* pos) 
		{
			AvmAssert(metadata_pos == NULL);
			metadata_pos = pos;
		}

	private:

	private:
		void buildBindings(TraitsBindingsp basetb, 
							MultinameHashtable* bindings, 
							uint32_t& slotCount, 
							uint32_t& methodCount,
							const Toplevel* toplevel) const;
		uint32_t finishSlotsAndMethods(TraitsBindingsp basetb, 
									TraitsBindings* tb, 
									const Toplevel* toplevel,
									AbcGen* abcGen) const;
	#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
		TraitsBindings* _buildTraitsBindings(const Toplevel* toplevel, AbcGen* abcGen, ImtBuilder* imtBuilder);
	#else
		TraitsBindings* _buildTraitsBindings(const Toplevel* toplevel, AbcGen* abcGen);
	#endif

		TraitsMetadata* _buildTraitsMetadata();

		TraitsPosPtr traitsPosStart() const;
		TraitsPosPtr skipToInstanceInitPos(TraitsPosPtr pos) const;
		void countInterfaces(const Toplevel* toplevel, List<Traitsp, LIST_NonGCObjects>& seen) const;
		void addInterfaces(TraitsBindings* tb) const;
		Binding getOverride(TraitsBindingsp basetb, Namespacep ns, Stringp name, int tag, const Toplevel *toplevel) const;

	private:

		/**
		 * Constructor for traits.  base != NULL means inheritance.
		 */
		Traits(PoolObject* pool,
			   Traits* base,
			   uint32_t sizeofInstance,
			   TraitsPosPtr traitsPos,
			   TraitsPosType posType);

		Traits* _newParameterizedTraits(Stringp name, Namespacep ns, Traits* _base);

	public:
		/**
		 * traits with base traits (inheritance)
		 */
		static Traits* newTraits(PoolObject* pool,
			   Traits *base,
				uint32_t sizeofInstance,
				TraitsPosPtr traitsPos,
				TraitsPosType posType);
		
#ifdef AVMPLUS_TRAITS_MEMTRACK
		virtual ~Traits();
#endif

		static Traits* newCatchTraits(const Toplevel* toplevel, PoolObject* pool, TraitsPosPtr traitsPos, Stringp name, Namespacep ns);
		static Traits* newFunctionTraits(const Toplevel* toplevel, PoolObject* pool, uint32_t method_id);
		Traits* newParameterizedITraits(Stringp name, Namespacep ns) { return _newParameterizedTraits(name, ns, this); }
		Traits* newParameterizedCTraits(Stringp name, Namespacep ns) { return _newParameterizedTraits(name, ns, this->base); }

	public:
		void enableSkips(uint32_t nameCount);
		inline void setSkip(uint32_t i) { AvmAssert(m_skips.test(0)); m_skips.set(i+1); }
		inline bool testSkip(uint32_t i) const { return m_skips.test(0) && m_skips.test(i+1); }

		bool allowEarlyBinding() const;

	private:
		TraitsBindings* FASTCALL _getTraitsBindings();
		TraitsMetadata* FASTCALL _getTraitsMetadata();
	public:
		inline TraitsBindingsp getTraitsBindings()
		{
			AvmAssert(this->linked);
			AvmAssert(m_tbref != NULL);
			TraitsBindings* tb;
			if ((tb = (TraitsBindings*)m_tbref->get()) == NULL)
				tb = _getTraitsBindings();
			tb->use();
			return tb;
		}
		inline TraitsMetadatap getTraitsMetadata()
		{
			AvmAssert(this->linked);
			AvmAssert(m_tmref != NULL);
			TraitsMetadata* tm;
			if ((tm = (TraitsMetadata*)m_tmref->get()) == NULL)
				tm = _getTraitsMetadata();
			tm->use();
			return tm;
		}
		inline bool containsInterface(Traitsp t) { return this == t || this->getTraitsBindings()->containsInterface(t); }
		
	public:
		// table of interface dispatch stubs.
		// BIND_NONE   = no entry
		// BIND_METHOD+disp_id = no conflict, dispatches to concrete method
		// BIND_ITRAMP+addr    = conflict, dispatch to conflict resolution stub
		// IMT table (if we have one, comes after the interfaces)
	#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
		const Binding* getIMT() const 
		{
			// @todo we only need this at vtable-resolution time, could move into TD or gen on demand?
			return m_imt;
		}
	#endif

		void genDefaultValue(uint32_t value_index, uint32_t slot_id, const Toplevel* toplevel, Traits* slotType, CPoolKind kind, AbcGen& gen) const;
		void genInitBody(const Toplevel* toplevel, AbcGen& gen);
		
		void resolveSignatures(const Toplevel* toplevel);

		// convenient wrapper to check for null (returns "BUILTIN_any")
		inline static BuiltinType getBuiltinType(const Traitsp t) { return t ? BuiltinType(t->builtinType) : BUILTIN_any; }

		inline bool notDerivedObjectOrXML() const { return ((1<<builtinType) & NOT_DERIVED_OR_XML_MASK) != 0; }
		inline bool isMachineType() const { return ((1<<builtinType) & MACHINE_TYPE_MASK) != 0; }
		inline bool isNumeric() const { return ((1<<builtinType) & NUMERIC_TYPE_MASK) != 0; }
		inline bool isXMLType() const { return ((1<<builtinType) & XML_TYPE_MASK) != 0; }

		inline TraitsPosType posType() const { return (TraitsPosType)(uint32_t)m_posType; }
		inline bool isResolved() const { return linked; }
		inline bool isActivationTraits() const { return posType() == TRAITSTYPE_ACTIVATION; }

		inline bool needsHashtable() const { AvmAssert(linked); return m_needsHashtable; }
		inline void set_needsHashtable(bool v) { AvmAssert(!linked); m_needsHashtable = v; }

		static bool isMachineCompatible(const Traits* a, const Traits* b);

		void setCreateClassClosureProc(CreateClassClosureProc p) { this->m_nativeInfo.createClassClosure = p; }
		void setCreateGlobalObjectProc(CreateGlobalObjectProc p) { this->m_nativeInfo.createGlobalObject = p; }

		CreateClassClosureProc getCreateClassClosureProc() const { return m_nativeInfo.createClassClosure; }
		CreateGlobalObjectProc getCreateGlobalObjectProc() const { return m_nativeInfo.createGlobalObject; }


		Stringp formatClassName();

#ifdef MMGC_DRC
		void destroyInstance(ScriptObject *obj) const;
#endif

	private:
		Traitsp* findInterface(Traits* t) const;

	public:
#ifdef AVMPLUS_VERBOSE
		Stringp format(AvmCore* core) const;
#endif


	private:
		union NativeInfo {
			CreateClassClosureProc	createClassClosure;
			CreateGlobalObjectProc	createGlobalObject;
		};

	// ------------------------ DATA SECTION BEGIN
	public:		AvmCore* const			core;		// @todo remove, can get from pool->core
	public:		Traits* const			base;		// Pointer to the base traits; that is, the traits of the base class
	public:		PoolObject* const		pool;		// The constant pool owning this definition. never null.
	public:		Traits*					itraits;	// if this type is a factory, itraits is non-null and points to the type created by this factory.
	public:		DRCWB(Namespacep)		ns;			// The namespace of the class described by this traits object
	public:		DRCWB(Stringp)			name;		// The name of the class described by this traits object
#ifdef DEBUGGER
	public:		DRCWB(Stringp)			fullName;
#endif
#ifdef AVMPLUS_TRAITS_MEMTRACK
	public:		DWB(char*)				rawname;
#endif
	public:		DRCWB(Namespacep)		protectedNamespace;	// protected namespace, if any
	public:		DWB(ScopeTypeChain*)	scope;				// scope chain types
	public:		DWB(AbstractFunction*)	init;				// not a call/init union b/c smart pointers and union's don't mix
	private:	NativeInfo				m_nativeInfo;
	private:	const TraitsPosPtr		m_traitsPos;		// ptr into our ABC definition, depending on m_posType
	private:	const byte*				metadata_pos;
	private:	FixedBitSet				m_skips;	
	#ifdef MMGC_DRC
	private:	FixedBitSet				m_slotDestroyInfo;	
	#endif
	#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
	private:	Binding					m_imt[Traits::IMT_SIZE];
	#endif
	private:	DWB(MMgc::GCWeakRef*)	m_tbref;				// our TraitsBindings 
	private:	DWB(MMgc::GCWeakRef*)	m_tmref;				// our TraitsMetadata
// @todo -- we should be able to store m_sizeofInstance in 16 bits but MIR doesn't have a convenient way to do a 16-bit load. Leaving at 32 for now.
	private:	uint32_t				m_sizeofInstance;	// sizeof implementation class, e.g. ScriptObject, etc. < 64k. Not counting extra room for slots.
	private:	uint32_t				m_hashTableOffset;	// offset to our hashtable (or 0 if none)
	private:	uint32_t				m_totalSize;		// total size, including sizeofInstance + slots + hashtable
	public:		uint8_t					builtinType;				// BuiltinType enumeration -- only need 5 bits but stored in byte for faster access
	private:	const uint8_t			m_posType;					// TraitsPosType enumeration -- only need 3 bits but stored in byte for faster access
	private:	uint8_t					m_bindingCapLog2;			// if nonzero, log2 of the cap needed for bindings
	private:	uint8_t					m_interfaceCapLog2;			// if nonzero, log2 of the cap needed for interfaces
	// 8 bits follow
	private:	uint32_t				m_needsHashtable:1;			// If true, the class needs a hash table. Typically true for dynamic classes, but will be false for XML
	private:	uint32_t				linked:1;					// set once signature types have been resolved */
	public:		uint32_t				final:1;					// set when the class cannot be extended */
	public:		uint32_t				isInterface:1;				// true for types that are interfaces */
	public:		uint32_t				commonBase:1;				// used for Verify::findCommonBase */
	public:		uint32_t				isDictionary:1;				// how we implement dictionary or strict style lookups
	public:		uint32_t				hasCustomConstruct:1;		// does this type use the default ClassClosure::construct method or not?
										// If the traits are for a type that implements its own construct method, this must be set to true.  
										// If it is false, the JIT will early bind to the AS defined constructor. 
	// ------------------------ DATA SECTION END
	};

#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
	class ImtBuilder
	{
	public:
		class ImtEntry: public MMgc::GCObject
		{
		public:
			ImtEntry(AbstractFunction* v, ImtEntry* n, uint32_t d) : 
				virt(v), 
				next(n), 
				disp_id(d) 
			{
			}
			AbstractFunction * const virt;
			ImtEntry * const next;
			const uint32_t disp_id;
		};

		ImtBuilder(MMgc::GC *gc);
		void addEntry(AbstractFunction* virt, uint32_t disp_id);
		void finish(Binding imt[], PoolObject* pool, const Toplevel *toplevel);

	private:
		MMgc::GC *gc;
		ImtEntry *entries[Traits::IMT_SIZE];
	};
#endif
}

#endif /* __avmplus_Traits__ */
