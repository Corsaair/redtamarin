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
 * Portions created by the Initial Developer are Copyright (C) 2008
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
#include "BuiltinNatives.h"
#include "TypeDescriber.h"

namespace avmplus
{
	TypeDescriber::TypeDescriber(Toplevel* toplevel) : 
		m_toplevel(toplevel)
	{
		memset(m_strs, 0, sizeof(m_strs));
	}

	Stringp TypeDescriber::describeClassName(Traitsp traits)
	{
		if (!traits)
			return str(kstrid_asterisk);
		
		Stringp name = traits->formatClassName();
		
		// no need to explicitly escape XML chars (eg > into &gt;)
		// since we're returning as JSON and converting to XML in AS3...
		// the escaping will happen automatically by E4X infrastructure
		return name;
	}

	ScriptObject* TypeDescriber::new_object()
	{
		return m_toplevel->objectClass->newInstance();
	}

	ArrayObject* TypeDescriber::new_array()
	{
		return (ArrayObject*)m_toplevel->arrayClass->newInstance();
	}

	void TypeDescriber::setpropmulti(ScriptObject* o, const TypeDescriber::KVPair* kv, uint32_t count)
	{
		while (count--)
		{
			o->setStringProperty(str(kv->keyid), kv->value);
			++kv;
		}
	}

	Stringp TypeDescriber::str(StringId i)
	{
		static const char* const k_strs[maxStringId] =
		{
			"access",
			"accessors",
			"*",
			"bases",
			"constructor",
			"declaredBy",
			"",
			"interfaces",
			"isDynamic",
			"isFinal",
			"isStatic",
			"key",
			"metadata",
			"method",
			"methods",
			"name",
			"native",
			"optional",
			"parameters",
			"readonly",
			"readwrite",
			"returnType",
			"traits",
			"type",
			"uri",
			"value",
			"variables",
			"writeonly"
		};
		if (!m_strs[i])
			m_strs[i] = m_toplevel->core()->constantString(k_strs[i]);
		return m_strs[i];
	}

	#define elem_count(o) (sizeof(o)/sizeof((o)[0]))

	static void pushstr(ArrayObject* a, Stringp s)
	{
		a->setUintProperty(a->getLength(), s->atom());
	}

	static void pushobj(ArrayObject* a, ScriptObject* o)
	{
		a->setUintProperty(a->getLength(), o->atom());
	}

	static inline Atom strAtom(Stringp s)
	{
		return s ? s->atom() : nullStringAtom;
	}

	static inline Atom objAtom(ScriptObject* o)
	{
		return o ? o->atom() : nullObjectAtom;
	}

	static inline Atom boolAtom(bool b)
	{
		return b ? trueAtom : falseAtom;
	}

	ArrayObject* TypeDescriber::describeParams(const AbstractFunction* af)
	{
		ArrayObject* a = new_array();
		const int requiredParamCount = af->requiredParamCount();
		for (int i = 1; i <= af->param_count; ++i) 
		{
			ScriptObject* v = new_object();
			const KVPair props[] = {
				{ kstrid_type, strAtom(describeClassName(af->paramTraits(i))) },
				{ kstrid_optional, boolAtom(i > requiredParamCount) },
			};
			setpropmulti(v, props, elem_count(props));
			pushobj(a, v);
		}
		return a;
	}

	static void addBindings(MultinameHashtable* bindings, TraitsBindingsp tb, uint32_t flags)
	{
		if (!tb) return;
		if ((flags & TypeDescriber::HIDE_OBJECT) && !tb->base) return;
		addBindings(bindings, tb->base, flags);
		for (int32_t index = 0; (index = tb->next(index)) != 0; )
		{
			bindings->add(tb->keyAt(index), tb->nsAt(index), tb->valueAt(index));
		}
	}
	
	ScriptObject* TypeDescriber::describeTraits(Traitsp traits, uint32_t flags)
	{
		if (!(flags & INCLUDE_TRAITS))
			return NULL;
			
		AvmCore* core = m_toplevel->core();
		GC* gc = core->GetGC();
		TraitsBindingsp tb = traits->getTraitsBindings();
		TraitsMetadatap tm = traits->getTraitsMetadata();

		ScriptObject* o = new_object();

		ArrayObject* bases = NULL;
		ArrayObject* metadata = NULL;
		ArrayObject* interfaces = NULL;
		ArrayObject* methods = NULL;
		ArrayObject* accessors = NULL;
		ArrayObject* variables = NULL;
		ScriptObject* constructor = NULL;

		if (flags & INCLUDE_BASES)
		{
			metadata = new_array();
			PoolObject* class_mdpool;
			const uint8_t* class_md = tm->getMetadataPos(class_mdpool);
			if (class_md)
				addDescribeMetadata(metadata, class_mdpool, class_md);
		}
		
		if (flags & INCLUDE_BASES)
		{
			bases = new_array();
			for (Traitsp b = traits->base; b; b = b->base) 
				pushstr(bases, describeClassName(b));
		}
		
		if (flags & INCLUDE_INTERFACES)
		{
			interfaces = new_array();
			// our TraitsBindings only includes our own interfaces, not any we might have inherited, 
			// so walk the tree. there might be redundant interfaces listed in the inheritance, 
			// so use a list to remove dupes
			List<Traitsp> unique(gc);
			for (Traitsp b = traits; b; b = b->base) 
			{
				TraitsBindingsp tbi = b->getTraitsBindings();
				for (uint32_t i = 0; i < tbi->interfaceCapacity; ++i)
				{
					Traitsp ti = tbi->getInterface(i);
					if (ti && ti->isInterface && unique.indexOf(ti) < 0)
					{
						unique.add(ti);
						pushstr(interfaces, describeClassName(ti));
					}
				}
			}
		}

		// constructor
		if (flags & INCLUDE_CONSTRUCTOR)
		{
			AbstractFunction* initMethod = traits->init;
			if (initMethod && initMethod->param_count)
			{
				constructor = describeParams(initMethod);
			}
		}
		
		if (flags & (INCLUDE_ACCESSORS | INCLUDE_METHODS | INCLUDE_VARIABLES))
		{
			// recover slot/method metadata and method-declarer information.
			
			// make a flattened set of bindings so we don't have to check for overrides as we go.
			// This is not terribly efficient, but doesn't need to be.
			MultinameHashtable* mybind = new (gc) MultinameHashtable();
			addBindings(mybind, tb, flags);

			// Don't want interface methods, so post-process and wipe out any
			// bindings that were added
			for (uint32_t i = 0; i < tb->interfaceCapacity; ++i)
			{
				Traitsp ti = tb->getInterface(i);
				if (ti && ti->isInterface)
				{
					TraitsBindingsp tbi = ti->getTraitsBindings();
					for (int32_t index = 0; (index = tbi->next(index)) != 0; )
					{
						Stringp name = tbi->keyAt(index);
						Namespacep ns = tbi->nsAt(index);
						mybind->add(name, ns, BIND_NONE);
					}
				}
			}
			
			// yuck, replicate buggy behavior in FP9/10
			List<Namespacep> nsremoval(gc);
			if (flags & HIDE_NSURI_METHODS)
			{
				for (uint32_t i = 0; i < tb->interfaceCapacity; ++i)
				{
					Traitsp ti = tb->getInterface(i);
					// already did interfaces, don't need to do them again
					if (ti && !ti->isInterface)
					{
						TraitsBindingsp tbi = ti->getTraitsBindings();
						for (int32_t index = 0; (index = tbi->next(index)) != 0; )
						{
							Namespacep ns = tbi->nsAt(index);
							if (ns->getURI()->length() > 0 && nsremoval.indexOf(ns) < 0)
								nsremoval.add(ns);
						}
					}
				}
			}

			for (int32_t index = 0; (index = mybind->next(index)) != 0; )
			{
				Binding binding = mybind->valueAt(index);
				Stringp name = mybind->keyAt(index);
				Namespacep ns = mybind->nsAt(index);
				Stringp nsuri = ns->getURI();
				TraitsMetadata::MetadataPtr md1 = NULL;
				TraitsMetadata::MetadataPtr md2 = NULL;
				PoolObject* md1pool = NULL;
				PoolObject* md2pool = NULL;

				// We only display public members -- exposing private namespaces could compromise security.
				if (ns->getType() != Namespace::NS_Public) 
					continue;
				
				if ((flags & HIDE_NSURI_METHODS) && nsremoval.indexOf(ns) >= 0)
					continue;
			
				ScriptObject* v = new_object();

				const BindingKind bk = AvmCore::bindingKind(binding);
				switch (bk)
				{
					case BKIND_CONST:
					case BKIND_VAR:
					{
						if (!(flags & INCLUDE_VARIABLES))
							continue;

						const uint32_t slotID = AvmCore::bindingToSlotId(binding);
						const KVPair props[] = {
							{ kstrid_access, strAtom(str(bk == BKIND_CONST ? kstrid_readonly : kstrid_readwrite)) },
							{ kstrid_type, strAtom(describeClassName(tb->getSlotTraits(slotID))) },
						};
						setpropmulti(v, props, elem_count(props));
						if (!variables) variables = new_array();
						pushobj(variables, v);
						md1 = tm->getSlotMetadataPos(slotID, md1pool);
						break;
					}

					case BKIND_METHOD:
					{
						if (!(flags & INCLUDE_METHODS))
							continue;

						const uint32_t methodID = AvmCore::bindingToMethodId(binding);
						const AbstractFunction* af = tb->getMethod(methodID);

						Traitsp declaringTraits = af->declaringTraits;

						const KVPair props[] = {
							{ kstrid_declaredBy, strAtom(describeClassName(declaringTraits)) },
							{ kstrid_returnType, strAtom(describeClassName(af->returnTraits())) },
							{ kstrid_parameters, objAtom(describeParams(af)) },
						};
						setpropmulti(v, props, elem_count(props));
						if (!methods) methods = new_array();
						pushobj(methods, v);
						md1 = tm->getMethodMetadataPos(methodID, md1pool);
						break;
					}
					
					case BKIND_GET:
					case BKIND_SET:
					case BKIND_GETSET:
					{
						if (!(flags & INCLUDE_ACCESSORS))
							continue;
							
						const uint32_t methodID = AvmCore::hasGetterBinding(binding) ?
													AvmCore::bindingToGetterId(binding) :
													AvmCore::bindingToSetterId(binding);

						const AbstractFunction* af = tb->getMethod(methodID);

						Traitsp declaringTraits = af->declaringTraits;

						Traitsp accessorType = AvmCore::hasGetterBinding(binding) ?
													af->returnTraits() :
													af->paramTraits(1);

						static const uint8_t bk2str[8] = 
						{
							uint8_t(kstrid_emptyString),	// BKIND_NONE
							uint8_t(kstrid_emptyString),	// BKIND_METHOD
							uint8_t(kstrid_emptyString),	// BKIND_VAR
							uint8_t(kstrid_emptyString),	// BKIND_CONST
							uint8_t(kstrid_emptyString),	// BKIND_ITRAMP
							uint8_t(kstrid_readonly),		// BKIND_GET
							uint8_t(kstrid_writeonly),		// BKIND_SET
							uint8_t(kstrid_readwrite)		// BKIND_GETSET
						};
						const KVPair props[] = {
							{ kstrid_declaredBy, strAtom(describeClassName(declaringTraits)) },
							{ kstrid_access, strAtom(str(StringId(bk2str[bk]))) },
							{ kstrid_type, strAtom(describeClassName(accessorType)) },
						};
						setpropmulti(v, props, elem_count(props));
						if (AvmCore::hasGetterBinding(binding))
							md1 = tm->getMethodMetadataPos(AvmCore::bindingToGetterId(binding), md1pool);
						if (AvmCore::hasSetterBinding(binding))
							md2 = tm->getMethodMetadataPos(AvmCore::bindingToSetterId(binding), md2pool);
						if (!accessors) accessors = new_array();
						pushobj(accessors, v);
						break;
					}
					case BKIND_NONE:
						break;
				}

				ArrayObject* vm = NULL;
				if ((flags & INCLUDE_METADATA) && (md1 || md2))
				{
					vm = new_array();
					addDescribeMetadata(vm, md1pool, md1);
					addDescribeMetadata(vm, md2pool, md2);
				}
				const KVPair props[] = {
					{ kstrid_name, strAtom(name) },
					{ kstrid_uri, strAtom(nsuri->length() == 0 ? NULL : nsuri) },
					{ kstrid_metadata, objAtom(vm) },
				};
				setpropmulti(v, props, elem_count(props));
			}
		}

		const KVPair props[] = {
			{ kstrid_bases, objAtom(bases) },
			{ kstrid_interfaces, objAtom(interfaces) },
			{ kstrid_metadata, objAtom(metadata) },
			{ kstrid_accessors, objAtom(accessors) },
			{ kstrid_methods, objAtom(methods) },
			{ kstrid_variables, objAtom(variables) },
			{ kstrid_constructor, objAtom(constructor) },
		};
		setpropmulti(o, props, elem_count(props));

		return o;
	}

	void TypeDescriber::addDescribeMetadata(ArrayObject* a, PoolObject* pool, const uint8_t* meta_pos)
	{
		if (meta_pos)
		{
			uint32_t metadata_count = AvmCore::readU30(meta_pos);
			while (metadata_count--)
			{
				const uint32_t metadata_index = AvmCore::readU30(meta_pos);
				ScriptObject* md = describeMetadataInfo(pool, metadata_index);
				if (md)
					pushobj(a, md);
			}
		}
	}
	
	static void read_u30_list(List<uint32_t>& list, uint32_t val_count, const uint8_t*& pos)
	{
		list.ensureCapacity(val_count);
		while (val_count--)
		{
			list.add(AvmCore::readU30(pos));
		}
	}

	ScriptObject* TypeDescriber::describeMetadataInfo(PoolObject* pool, uint32_t metadata_index)
	{
		AvmCore* core = m_toplevel->core();
		const uint8_t* metadata_pos = pool->metadata_infos[metadata_index];

		const uint32_t name_index = (metadata_pos) ? AvmCore::readU30(metadata_pos) : 0;
		// A bit of a hack: if the pool is builtin, always omit metadata chunks with names of "Version"
		// or "native", since these are used for reserved purposes internally.
		Stringp name = poolstr(pool, name_index);
		AvmAssert(name->isInterned() && core->kVersion->isInterned() && str(kstrid_native)->isInterned());
		if (pool->isBuiltin && (name == core->kVersion || name == str(kstrid_native))) 
			return NULL;

		const uint32_t val_count = (metadata_pos) ? AvmCore::readU30(metadata_pos) : 0;

		ScriptObject* o = new_object();
		ArrayObject* a = new_array();

		if (val_count > 0)
		{
			GC* gc = core->GetGC();
			List<uint32_t> key_indexes(gc);
			List<uint32_t> val_indexes(gc);
			
			read_u30_list(key_indexes, val_count, metadata_pos);
			read_u30_list(val_indexes, val_count, metadata_pos);

			for (uint32_t i = 0; i < val_count; ++i)
			{
				ScriptObject* v = new_object();
				const KVPair props[] = {
					{ kstrid_key, strAtom(poolstr(pool, key_indexes.get(i))) },
					{ kstrid_value, strAtom(poolstr(pool, val_indexes.get(i))) },
				};
				setpropmulti(v, props, elem_count(props));
				pushobj(a, v);
			}
		}

		const KVPair props[] = {
			{ kstrid_name, strAtom(name) },
			{ kstrid_value, objAtom(a) },
		};
		setpropmulti(o, props, elem_count(props));

		return o;
	}

	Stringp TypeDescriber::poolstr(PoolObject* pool, uint32_t index)
	{
		Stringp name = index < pool->cpool_string.size() ? pool->cpool_string[index] : NULL;
		return name ? name : str(kstrid_emptyString);
	}
	
	ScriptObject* TypeDescriber::describeType(Atom value, uint32_t flags)
	{
		Traitsp traits = m_toplevel->toTraits(value);

		if (flags & USE_ITRAITS)
			traits = traits->itraits;

		if (!traits)
			return NULL;

		ScriptObject* o = new_object();
		
		const KVPair props[] = {
			{ kstrid_name, strAtom(describeClassName(traits)) },
			{ kstrid_isDynamic, boolAtom(traits->needsHashtable()) },
			{ kstrid_isFinal, boolAtom(traits->final) },
			{ kstrid_isStatic, boolAtom(traits->itraits != NULL) },
			{ kstrid_traits, objAtom(describeTraits(traits, flags)) },
		};
		setpropmulti(o, props, elem_count(props));

		return o;
	}
}
