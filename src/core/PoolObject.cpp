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

namespace avmplus
{
	PoolObject::PoolObject(AvmCore* core, ScriptBuffer& sb, const byte* startPos) :
		core(core),
		cpool_int(0),
		cpool_uint(0),
		cpool_double(core->GetGC(), 0),
		cpool_string(core->GetGC(), 0),
		cpool_ns(core->GetGC(), 0),
		cpool_ns_set(core->GetGC(), 0),
		cpool_mn(0),
		bugFlags(0),
		methods(core->GetGC(), 0),
		metadata_infos(0),
		cinits(core->GetGC(), 0),
		scripts(core->GetGC(), 0),
		abcStart(startPos)
	{
		namedTraits = new(core->GetGC()) MultinameHashtable();
		privateNamedScripts = new(core->GetGC()) MultinameHashtable();
		m_code = sb.getImpl();
#if defined(AVMPLUS_MIR)
		codeBuffer = new (core->GetGC()) GrowableBuffer(core->GetGC()->GetGCHeap());
#endif
		version = AvmCore::readU16(&code()[0]) | AvmCore::readU16(&code()[2])<<16;
	}

	PoolObject::~PoolObject()
	{
		#ifdef AVMPLUS_MIR
		delete codeBuffer;
		#endif
		#ifdef AVMPLUS_WORD_CODE
		delete word_code.cpool_mn;
		#endif
	}
	
    AbstractFunction* PoolObject::getMethodInfo(uint32 index)
    {
		AvmAssert(index < methodCount);
		return methods[index];
    }

	Traits* PoolObject::getBuiltinTraits(Stringp name) const
	{
		AvmAssert(BIND_NONE == 0);
		return (Traits*) namedTraits->getName(name);
	}

	Traits* PoolObject::getTraits(Stringp name, Namespace* ns, bool recursive/*=true*/) const
	{
		// look for class in VM-wide type table
		Traits* t = domain->getNamedTraits(name, ns, recursive);

		// look for class in current ABC file
		if (t == NULL)
			t = (Traits*) namedTraits->get(name, ns);
		return t;
	}

	Traits* PoolObject::getTraits(Stringp name, bool recursive/*=true*/) const
	{
		return getTraits(name, core->publicNamespace, recursive);
	}

	Traits* PoolObject::getTraits(const Multiname& mname, const Toplevel* toplevel, bool recursive/*=true*/) const
	{
		// do full lookup of multiname, error if more than 1 match
		// return Traits if 1 match, NULL if 0 match, throw ambiguity error if >1 match
		Traits* match = NULL;
		if (mname.isBinding())
		{
			// multiname must not be an attr name, have wildcards, or have runtime parts.
			for (int i=0, n=mname.namespaceCount(); i < n; i++)
			{
				Traits* t = getTraits(mname.getName(), mname.getNamespace(i), recursive);
				if (t != NULL)
				{
					if (match == NULL)
					{
						match = t;
					}
					else if (match != t)
					{
						// ambiguity
						if (toplevel)
							toplevel->throwReferenceError(kAmbiguousBindingError, mname);
						AvmAssert(!"unhandled ambiguous binding");
					}
				}
			}
		}
		return match;
	}

	void PoolObject::addNamedTraits(Stringp name, Namespace* ns, Traits* traits)
	{
		namedTraits->add(name, ns, (Binding)traits);
	}

	Namespace* PoolObject::getNamespace(int index) const
	{
		return cpool_ns[index];  
	}

	NamespaceSetp PoolObject::getNamespaceSet(int index) const
	{
		return cpool_ns_set[index];  
	}

	Stringp PoolObject::getString(int index) const
	{
		return cpool_string[index];  
	}

	Atom PoolObject::getDefaultValue(const Toplevel* toplevel, uint32 index, CPoolKind kind, Traits* t) const
	{
		// toplevel actually can be null, when resolving the builtin classes...
		// but they should never cause verification errors in functioning builds
		//AvmAssert(toplevel != NULL);

		AvmAssert(index != 0);
		uint32_t maxcount = 0;
		// Look in the cpool specified by kind
		switch(kind)
		{
		case CONSTANT_Int:
			if (index >= (maxcount = constantIntCount))
				goto range_error;
			return core->intToAtom(cpool_int[index]);

		case CONSTANT_UInt:
			if (index >= (maxcount = constantUIntCount))
				goto range_error;
			return core->uintToAtom(cpool_uint[index]);

		case CONSTANT_Double:
			if (index >= (maxcount = constantDoubleCount))
				goto range_error;
			return kDoubleType|(uintptr)cpool_double[index];

		case CONSTANT_Utf8:
			if (index >= (maxcount = constantStringCount))
				goto range_error;
			return cpool_string[index]->atom();

		case CONSTANT_True:
			return trueAtom;

		case CONSTANT_False:
			return falseAtom;

		case CONSTANT_Namespace:
        case CONSTANT_PackageNamespace:
        case CONSTANT_PackageInternalNs:
        case CONSTANT_ProtectedNamespace:
        case CONSTANT_ExplicitNamespace:
        case CONSTANT_StaticProtectedNs:
		case CONSTANT_PrivateNs:
			if (index >= (maxcount = constantNsCount))
				goto range_error;
			return cpool_ns[index]->atom();

		case CONSTANT_Null:
			return nullObjectAtom;

		default:
			// Multinames & NamespaceSets are invalid default values.
			if (t)
			{
				toplevel->throwVerifyError(kIllegalDefaultValue, core->toErrorString(Multiname(t->ns, t->name)));
			}
			else
			{
				toplevel->throwVerifyError(kCorruptABCError);
			}
			return undefinedAtom; // not reached
		}

range_error:
		if (toplevel)
			toplevel->throwVerifyError(kCpoolIndexRangeError, core->toErrorString(index), core->toErrorString(maxcount));
		AvmAssert(!"unhandled verify error");
		return undefinedAtom; // not reached
	}

	void PoolObject::parseMultiname(const byte *pos, Multiname& m) const
	{
		// the multiname has already been validated so we don't do
		// any checking here, we just fill in the Multiname object
		// with the information we have parsed.

		int index;
		CPoolKind kind = (CPoolKind) *(pos++);
        switch (kind)
        {
		case CONSTANT_Qname: 
		case CONSTANT_QnameA:
		{
			// U16 namespace_index
            // U16 name_index
			// parse a multiname with one namespace (aka qname)

			index = AvmCore::readU30(pos);
			if (!index)
				m.setAnyNamespace();
			else
				m.setNamespace(getNamespace(index));

			index = AvmCore::readU30(pos);
			if (!index)
				m.setAnyName();
			else
				m.setName(getString(index));

			m.setQName();
			m.setAttr(kind==CONSTANT_QnameA);
			break;
		}

		case CONSTANT_RTQname:
		case CONSTANT_RTQnameA: 
		{
			// U16 name_index
			// parse a multiname with just a name; ns fetched at runtime

			index = AvmCore::readU30(pos);
			if (!index)
				m.setAnyName();
			else
				m.setName(getString(index));

			m.setQName();
			m.setRtns();
			m.setAttr(kind==CONSTANT_RTQnameA);
			break;
		}

		case CONSTANT_RTQnameL:
		case CONSTANT_RTQnameLA:
		{
			m.setQName();
			m.setRtns();
			m.setRtname();
			m.setAttr(kind==CONSTANT_RTQnameLA);
			break;
		}

		case CONSTANT_Multiname:
		case CONSTANT_MultinameA:
		{
			index = AvmCore::readU30(pos);
			if (!index)
				m.setAnyName();
			else
				m.setName(getString(index));

			index = AvmCore::readU30(pos);
			AvmAssert(index != 0);
			m.setNsset(getNamespaceSet(index));

			m.setAttr(kind==CONSTANT_MultinameA);
			break;
		}

		case CONSTANT_MultinameL:
		case CONSTANT_MultinameLA:
		{
			m.setRtname();

			index = AvmCore::readU30(pos);
			AvmAssert(index != 0);
			m.setNsset(getNamespaceSet(index));

			m.setAttr(kind==CONSTANT_MultinameLA);
			break;
		}

		case CONSTANT_TypeName:
		{
			index = AvmCore::readU30(pos);
			Atom a = cpool_mn[index];
			parseMultiname(atomToPos(a), m);
			index = AvmCore::readU30(pos);
			AvmAssert(index==1);
			m.setTypeParameter(AvmCore::readU30(pos));
			break;
		}
		
		default:
			AvmAssert(false);
		}

		return;
	}


	void PoolObject::resolveQName(uint32_t index, Multiname &m, const Toplevel* toplevel) const
	{
		if (index == 0 || index >= constantMnCount)
		{
			if (toplevel)
				toplevel->throwVerifyError(kCpoolIndexRangeError, core->toErrorString(index), core->toErrorString(constantMnCount));
			AvmAssert(!"unhandled verify error");
		}

		parseMultiname(cpool_mn[index], m);
		if (!m.isQName())
		{
			if (toplevel)
				toplevel->throwVerifyError(kCpoolEntryWrongTypeError, core->toErrorString(index));
			AvmAssert(!"unhandled verify error");
		}
	}

	Traits* PoolObject::resolveTypeName(uint32 index, const Toplevel* toplevel, bool allowVoid/*=false*/) const
	{
		// only save the type name for now.  verifier will resolve to traits
		if (index == 0)
		{
			return NULL;
		}

		// check contents is a multiname.  in the cpool, and type system, kObjectType means multiname.
		if (index >= constantMnCount)
		{
			if (toplevel)
				toplevel->throwVerifyError(kCpoolIndexRangeError, core->toErrorString(index), core->toErrorString(constantMnCount));
			AvmAssert(!"unhandled verify error");
		}

		Multiname m;
		parseMultiname(cpool_mn[index], m);

		Traits* t = getTraits(m, toplevel);
		if(m.isParameterizedType())
		{
			Traits* param_traits = resolveTypeName(m.getTypeParameter(), toplevel);
			t = resolveParameterizedType(toplevel, t, param_traits);
		}
		if (!t)
		{
			#ifdef AVMPLUS_VERBOSE
			if (!toplevel || !toplevel->verifyErrorClass())
				core->console << "class not found: " << m << " index=" << index << "\n";
			#endif
			if (toplevel)
				toplevel->throwVerifyError(kClassNotFoundError, core->toErrorString(&m));
			AvmAssert(!"unhandled verify error");
		}
		if (!allowVoid && t == VOID_TYPE)
		{
			if (toplevel)
				toplevel->throwVerifyError(kIllegalVoidError);
			AvmAssert(!"unhandled verify error");
		}

		return t;
	}

	Traits* PoolObject::resolveParameterizedType(const Toplevel* toplevel, Traits* base, Traits* param_traits ) const
	{
		Traits* r = NULL;
		if( base == core->traits.vector_itraits)
		{
			// Only vector is parameterizable for now...
			if(!param_traits) // Vector.<*>
				r = core->traits.vectorobj_itraits;  
			else if( param_traits == core->traits.int_itraits)
				r = core->traits.vectorint_itraits;
			else if (param_traits == core->traits.uint_itraits)
				r = core->traits.vectoruint_itraits;
			else if (param_traits == core->traits.number_itraits)
				r = core->traits.vectordouble_itraits;
			else
			{
				Stringp fullname = core->internString( core->concatStrings(core->newString("Vector.<"), 
					core->concatStrings(param_traits->formatClassName(), core->newString(">")))->atom());

				Multiname newname;
				newname.setName(fullname);
				newname.setNamespace(base->ns);

				r = getTraits(newname, toplevel);

				if( !r )
				{
					r = core->traits.vectorobj_itraits->newParameterizedITraits(fullname, base->ns);
					core->traits.vector_itraits->pool->domain->addNamedTrait(fullname, base->ns, r);
				}
			}
		}
		return r;
	}

	void PoolObject::addPrivateNamedScript(Stringp name, Namespace* ns, AbstractFunction *script)
	{
		privateNamedScripts->add(name, ns, (Binding)script);
	}

	AbstractFunction* PoolObject::getNamedScript(const Multiname* multiname) const
	{
		AbstractFunction *f = domain->getNamedScript(multiname);
		if(!f)
		{
			f = (AbstractFunction*)privateNamedScripts->getMulti(multiname);
		}
		return f;
	}
	
#ifdef AVMPLUS_WORD_CODE
	PrecomputedMultinames::PrecomputedMultinames(MMgc::GC* gc, PoolObject* pool)
		: MMgc::GCRoot(gc)
		, nNames (0)
	{
		nNames = pool->constantMnCount;
		for ( uint32 i=1 ; i < nNames ; i++ ) {
			Multiname mn;
			pool->parseMultiname(mn, i);
			mn.IncrementRef();
			multinames[i] = mn;
		}
	}
	
	PrecomputedMultinames::~PrecomputedMultinames() {
		for ( uint32 i=1 ; i < nNames ; i++ ) 
			multinames[i].DecrementRef();
	}
#endif
	
}
