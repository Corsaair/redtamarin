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

#ifdef AVMPLUS_VERBOSE
#define if_verbose(...) if (pool->verbose) { __VA_ARGS__ }
#else
#define if_verbose(...)
#endif

namespace avmplus
{
    /**
     * parse a .abc file completely
     * @param code
     * @return
     */
    PoolObject* AbcParser::decodeAbc(AvmCore* core, ScriptBuffer code, 
		Toplevel* toplevel,
		Domain* domain,
		const NativeInitializer* natives,
		const List<Stringp>* keepVersions)
    {
		if (code.getSize() < 4)
			toplevel->throwVerifyError(kCorruptABCError);

		int version = AvmCore::readU16(&code[0]) | AvmCore::readU16(&code[2])<<16;

        #ifdef AVMPLUS_VERBOSE
		if (core->config.verbose)
			core->console << "major=" << (version&0xFFFF) << " minor=" << (version>>16) << "\n";
        #endif

		switch (version)
		{
		case (46<<16|16):
		{
			AbcParser parser(core, code, toplevel, domain, natives, keepVersions);
			PoolObject *pObject = parser.parse();
 			if ( !pObject )
 				toplevel->throwVerifyError( kCorruptABCError );
 			else
 				return pObject;
		}
		default:
			toplevel->throwVerifyError(kInvalidMagicError, core->toErrorString(version>>16), core->toErrorString(version&0xFFFF));
			return NULL;
		}
    }

	AbcParser::AbcParser(AvmCore* core, ScriptBuffer code, 
		Toplevel* toplevel,
		Domain* domain,
		const NativeInitializer* natives,
		const List<Stringp>* keepVersions)
		: toplevel(toplevel),
		  domain(domain),
		  instances(core->GetGC(), 0)
	{
		this->core = core;
		this->code = code;
		this->pool = NULL;
		this->version = AvmCore::readU16(&code[0]) | AvmCore::readU16(&code[2])<<16;
		this->pos = &code[4];
		this->natives = natives;
		this->keepVersions = keepVersions;

		abcStart = &code[0];
		abcEnd = &code[(int)code.getSize()];

		classCount = 0;
		metaNames = NULL;
	}

	AbcParser::~AbcParser()
	{
		if (metaNames)
			core->GetGC()->Free(metaNames);
	}

	uint32_t AbcParser::computeInstanceSize(int class_id, 
									   Traits* base) const
	{
		// If this is a native class, return the stated instance size
		const NativeClassInfo* nativeEntry;
		if (natives && (nativeEntry = natives->get_class(class_id)) != NULL && nativeEntry->sizeofInstance)
		{
			return nativeEntry->sizeofInstance;
		}

		// Search the inheritance chain for any native classes.
		while (base)
		{
			if (base->getSizeOfInstance() > sizeof(ScriptObject))
			{
				// non-Object base class uses a subclass of ScriptObject, so use that size.
				return base->getSizeOfInstance();
			}
			base = base->base;
		}

		// no derived native classes found
		return uint32_t(sizeof(ScriptObject));
	}

	Namespacep AbcParser::parseNsRef(const byte* &pc) const
	{
		uint32 index = readU30(pc);
		if (index == 0)
		{
			return NULL; // AnyNamespace
		}

		if (index >= pool->constantNsCount)
			toplevel->throwVerifyError(kCpoolIndexRangeError, core->toErrorString(index), core->toErrorString(pool->constantNsCount));
		return pool->cpool_ns[index];
	}

	#ifdef AVMPLUS_VERBOSE
	void AbcParser::parseTypeName(const byte* &pc, Multiname& m) const
	{
		// only save the type name for now.  verifier will resolve to traits
		uint32 index = readU30(pc);
		if (index == 0)
		{
			// type is *
			m.setNamespace(core->publicNamespace);
			m.setName(core->kAsterisk);
			return;
		}

		if (index >= pool->constantMnCount)
			toplevel->throwVerifyError(kCpoolIndexRangeError, core->toErrorString(index), core->toErrorString(pool->constantMnCount));

		pool->parseMultiname(m, index);
	}
	#endif

	void AbcParser::resolveQName(const byte* &p, Multiname &m) const
	{
		uint32 index = readU30(p);
		if (index == 0 || index >= pool->constantMnCount)
			toplevel->throwVerifyError(kCpoolIndexRangeError, core->toErrorString(index), core->toErrorString(pool->constantCount));

		Atom a = pool->cpool_mn[index];

		pool->parseMultiname(a, m);
		if (!m.isQName())
			toplevel->throwVerifyError(kCpoolEntryWrongTypeError, core->toErrorString(index));
	}

	AbstractFunction *AbcParser::resolveMethodInfo(uint32 index) const
	{
		if (index >= pool->methodCount)
			toplevel->throwVerifyError(kMethodInfoExceedsCountError, core->toErrorString(index), core->toErrorString(pool->methodCount));

		AbstractFunction *f = pool->getMethodInfo(index);
		if (!f)
			toplevel->throwVerifyError(kMethodInfoOrderError, core->toErrorString(index));

		return f;
	}

	Stringp AbcParser::resolveUtf8(uint32 index) const
	{
		if (index > 0 && index < pool->constantStringCount )
		{
			return pool->cpool_string[index];
		}
		toplevel->throwVerifyError(kCpoolIndexRangeError, core->toErrorString(index), core->toErrorString(pool->constantStringCount));
		return NULL;
	}

	Stringp AbcParser::parseName(const byte* &pc) const
	{
		uint32 index = readU30(pc);
		if (index == 0)
			return NULL;
		return resolveUtf8(index);
	}

	PoolObject* AbcParser::parse()
	{
#ifdef AVMPLUS_WORD_CODE
		// Loading a new ABC file always invalidates the lookup cache
		core->invalidateLookupCache();
#endif
		// Loading a new ABC file always invalidates the traits cache(s)
		core->tbCache()->flush();
		core->tmCache()->flush();

#ifdef FEATURE_BUFFER_GUARD // no Carbon
		TRY(this->core, kCatchAction_Rethrow)
		{
			// catches any access violation exceptions and sends control to
			// the CATCH block below.
			BufferGuard guard(&_ef.jmpbuf);			
			this->guard = &guard;

			if(toplevel == NULL) {
				this->guard = NULL;
				guard.disable();
			}
			
#endif // FEATURE_BUFFER_GUARD

			// constant pool
			parseCpool();

			// parse all methodInfos in one pass.  Nested functions must come before outer functions
			parseMethodInfos();

			// parse all metadataInfos - AVM+ doesn't care about this, so we are really just skipping them
			parseMetadataInfos();

			// parse classes.  base classes must come first.
			if (!parseInstanceInfos()) return NULL;

			bool first = false;
			if (CLASS_TYPE == NULL)
			{
				// if we haven't got types from the builtin file yet, do it now.
				first = true;
				core->traits.initInstanceTypes(pool);

				// register "void"
				addNamedTraits(core->publicNamespace, VOID_TYPE->name, VOID_TYPE);
			}

			// type information about class objects
			parseClassInfos();

			if (first)
			{
				core->traits.initClassTypes(pool);
			}

			// scripts
			if( !parseScriptInfos() ) return NULL;

			// method bodies: code, exception info, and activation traits
			parseMethodBodies();
#ifdef FEATURE_BUFFER_GUARD // no buffer guard in Carbon builds
		}
		CATCH(Exception *exception)
		{
		 	guard->disable();
			guard = NULL;
			if( exception && exception->isValid()) {
				// Re-throw if exception exists
				core->throwException(exception);
			} else if(toplevel) {
				// create new exception
				toplevel->throwVerifyError(kCorruptABCError);
			} 
		}
		END_CATCH
		END_TRY
#endif // FEATURE_BUFFER_GUARD

        return pool;
	}

#ifdef SAFE_PARSE
	// check to see if we are trying to read past the file end or the beginning.
	#define CHECK_POS(pos) do { if ((pos) < abcStart || (pos) >= abcEnd ) toplevel->throwVerifyError(kCorruptABCError); } while (0)
#else
	#define CHECK_POS(pos) do {  } while (0)
#endif //SAFE_PARSE

	/**
	 * setting up a traits that extends another one.  Two parser passes are required,
	 * one for sizing the traits object and the other for allocating it and filling
	 * it in.
	 */
	Traits* AbcParser::parseTraits(uint32_t sizeofInstance, 
									Traits* base, 
									Namespacep ns, 
									Stringp name, 
									AbstractFunction* script, 
									TraitsPosPtr traitsPos,
									TraitsPosType posType, 
									Namespacep protectedNamespace)
	{
		uint32_t nameCount = readU30(pos);

		// Very generous check for nameCount being way too large.
		if (nameCount > (uint32_t)(abcEnd - pos))
			toplevel->throwVerifyError(kCorruptABCError);

		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console << "        trait_count=" << nameCount << "\n";
		#endif

		Traits* traits = Traits::newTraits(pool, base, sizeofInstance, traitsPos, posType);
		traits->ns = ns;
		traits->name = name;
		traits->protectedNamespace = protectedNamespace;
		
		bool enableSkips = false;
		for (uint32_t i=0; i < nameCount; i++)
        {
			Multiname qn;
			resolveQName(pos, qn);
			Namespacep ns = qn.getNamespace();
			// TODO name can come out null and fire all kinds of asserts from a broken compiler
			// and crash a release build, not sure if null is valid in any cases but there's definitely
			// a missing verify error here somewhere
			Stringp name = qn.getName();
			CHECK_POS(pos);
            int tag = *pos++;
            TraitKind kind = (TraitKind) (tag & 0x0f);
			
			bool skip = false;
			uint32_t class_info = 0;
			uint32_t method_info = 0;
			uint32_t slot_id = 0;
			uint32_t value_index = 0;
			uint32_t earlyDispId = 0;
			int flags = 0;
#ifdef AVMPLUS_VERBOSE
			Multiname typeName;
#endif

			// Read in the trait entry.
			// Skip any traits that have version metadata that indicates they should be removed.
			switch (kind)
			{
			case TRAIT_Slot:
			case TRAIT_Const:
				slot_id = readU30(pos);							// slot id
#ifdef AVMPLUS_VERBOSE
				parseTypeName(pos, typeName);
#else
				readU30(pos);
#endif
				value_index = readU30(pos);	// value index
				if (value_index)
				{
					CHECK_POS(pos);
					pos += 1;				// value_kind
				}
				break;
			case TRAIT_Class:
				readU30(pos); // slot id
				class_info = readU30(pos);
				break;
			case TRAIT_Getter:
			case TRAIT_Setter:
			case TRAIT_Method:
				earlyDispId = readU30(pos);			// disp id
				method_info = readU30(pos);	
				break;
			default:
				// unsupported traits type
				toplevel->throwVerifyError(kUnsupportedTraitsKindError, core->toErrorString(kind));
			}
			const byte* meta_pos = pos;
			if (tag & ATTR_metadata)
			{
				const uint32_t metadataCount = readU30(pos);
				for (uint32_t metadata = 0; metadata < metadataCount; ++metadata)
				{
					const uint32_t index = readU30(pos);
					Stringp name = metaNames[index];
					if (pool->stripMetadataIndexes.indexOf(index) != -1)
						skip = true;  // Stripping this definition
					else if (name == core->kNeedsDxns)
						flags |= AbstractFunction::NEEDS_DXNS;
#ifdef AVMPLUS_VERBOSE
					else if (name == kVerboseVerify)
						flags |= AbstractFunction::VERBOSE_VERIFY;
#endif
				}
			}
			if (skip) 
			{
				if (!enableSkips)
				{
					traits->enableSkips(nameCount);
					enableSkips = true;
				}
				traits->setSkip(i);
				AvmAssert(traits->testSkip(i));
#ifdef AVMPLUS_VERBOSE
				if (pool->verbose)
				{
					core->console << "skipping definition " << i << " for " << traits << " name=" << Multiname::format(core,ns,name) << "\n";
				}
#endif
				continue;
			}
			
			// Didn't skip the trait, so do set up for the definition now.
			switch (kind)
            {
            case TRAIT_Slot:
            case TRAIT_Const:
            case TRAIT_Class:
			{
				if (script)
					addNamedScript(ns, name, script);

				if (kind == TRAIT_Class)
				{
					// get the class type
					if (class_info >= classCount)
						toplevel->throwVerifyError(kClassInfoExceedsCountError, core->toErrorString(class_info), core->toErrorString(classCount));

					AbstractFunction* cinit = pool->cinits[class_info];
					if (!cinit) 
						toplevel->throwVerifyError(kClassInfoOrderError, core->toErrorString(class_info));

					Traits* ctraits = cinit->declaringTraits;

					#ifdef AVMPLUS_VERBOSE
					if (pool->verbose)
					{
						core->console << "            " << traitNames[kind]
							<< " name=" << Multiname::format(core, ns, name)
							<< " slot_id=" << slot_id
							<< " type=" << ctraits
							<< "\n";
					}
					#endif

					if (script)
					{
						// promote instance type to the vm-wide type table.
						// map type name to traits
						addNamedTraits(ns, name, ctraits->itraits);
						if (tag & ATTR_metadata)
						{
							ctraits->itraits->setMetadataPos(meta_pos);
						}
					}
					else
					{
						if (tag & ATTR_metadata)
						{
							ctraits->setMetadataPos(meta_pos);
						}
					}
				}
				else
				{
					#ifdef AVMPLUS_VERBOSE
					if (pool->verbose)
					{
						core->console << "            " << traitNames[kind]
							<< " name=" << Multiname::format(core,ns,name)
							<< " slot_id=" << slot_id
							<< " value_index=" << value_index
							<< " type=" << typeName
							<< "\n";
					}
					#endif
				}
	            break;
			}
			case TRAIT_Getter:
			case TRAIT_Setter:
            case TRAIT_Method:
			{
				#ifdef AVMPLUS_VERBOSE
				if (pool->verbose)
				{
					core->console << "            " << traitNames[kind]
						<< " name=" << Multiname::format(core, ns, name)
						<< " disp_id=" << earlyDispId << " (ignored)"
					    << " method_info=" << method_info
						<< " attr=" << ((tag&ATTR_final)?"final":"virtual");
					if (tag&ATTR_override)
						core->console << "|override";
					core->console << "\n";
				}
				#endif

				// id is unused here
				AbstractFunction* f = resolveMethodInfo(method_info);

				#ifdef AVMPLUS_VERBOSE
				Stringp s1 = traits->format(core);
				Stringp s2 = core->newString(kind == TRAIT_Method ? "/" : (kind == TRAIT_Getter ? "/get " : "/set "));
				Stringp s3 = Multiname::format(core,ns,name);
				Stringp s4 = core->concatStrings(s2,s3);
				f->name = core->concatStrings(s1, s4);
				#endif

				// since this function is ref'ed here, we know the receiver type.
				if (!f->makeMethodOf(traits))
					toplevel->throwVerifyError(kCorruptABCError);

				f->flags |= flags;
				if (tag & ATTR_final)
					f->flags |= AbstractFunction::FINAL;
				if (tag & ATTR_override)
					f->flags |= AbstractFunction::OVERRIDE;
				
				// only export one name for an accessor 
				if (script && !domain->getNamedScript(name,ns))
					addNamedScript(ns, name, script);

                break;
			}

			default:
				// unsupported traits type
				toplevel->throwVerifyError(kUnsupportedTraitsKindError, core->toErrorString(kind));
            }

#ifdef AVMPLUS_VERBOSE
            if (tag & ATTR_metadata)
            {
                uint32_t metadataCount = readU30(meta_pos);
				for (uint32_t metadata = 0; metadata < metadataCount; ++metadata)
				{
					uint32_t index = readU30(meta_pos);
					if (pool->verbose)
						core->console << "            [" << metaNames[index] << "]\n";
				}
            }
#endif
        }

		return traits;
	}

	void AbcParser::parseMethodInfos()
    {
        int methodCount = readU30(pos);

		if_verbose(
			core->console << "method_count=" << methodCount << "\n";
		)

		int size = methodCount == 0 ? 1 : methodCount;

		if (size > (abcEnd - pos))
			toplevel->throwVerifyError(kCorruptABCError);

		MMGC_MEM_TYPE(pool);
		pool->methods.ensureCapacity(size);
		pool->methodCount = methodCount;

#if defined(AVMPLUS_VERBOSE) || defined(DEBUGGER)
		const byte* startpos = pos;
#endif

		for (int i=0; i < methodCount; i++)
        {
#ifdef AVMPLUS_VERBOSE
			int offset = (int)(pos-startpos);
#endif
			// MethodInfo
			int param_count = readU30(pos);

			const byte* info_pos = pos;

			#ifdef AVMPLUS_VERBOSE
			Multiname returnTypeName;
			parseTypeName(pos, returnTypeName);
			if_verbose(
				core->console << "    " << offset << ":method["<<i<<"]\n"
					<< "        returnType=" << returnTypeName << "\n"
					<< "        param_count=" << param_count 
				    << "\n";
			)
			#else
			readU30(pos);// return type name
			#endif

			for( int j = 1; j <= param_count; ++j)
			{
				#ifdef AVMPLUS_VERBOSE
				Multiname multiname;
				parseTypeName(pos, multiname);
				if_verbose(
					core->console << "            paramType["<<j<<"]="<< multiname << "\n";
				)
				#else
				readU30(pos);
				#endif
			}

            uint32 name_index = readU30(pos);
            (void)name_index;
			CHECK_POS(pos);
			int flags = *pos++;

			if_verbose(
				core->console << "        name_index=" << name_index;
				if (name_index > 0 && name_index < pool->constantStringCount)
					core->console << " \"" << pool->cpool_string[name_index] << "\"";
				core->console << "\n        flags=" << flags << "\n";
			)

			AbstractFunction *info;			
			if (!(flags & AbstractFunction::NATIVE))
			{
				MethodInfo *methodInfo = new (core->GetGC()) MethodInfo();
				
				#if defined AVMPLUS_VERBOSE || defined FEATURE_SAMPLER
				if (name_index != 0) {
					methodInfo->name = resolveUtf8(name_index);
					if(methodInfo->name->length() == 0) 
					{
						methodInfo->name = core->kanonymousFunc;	
					}
				} else
					methodInfo->name = core->concatStrings(core->newString("MethodInfo-"), core->intToString(i));
				#endif
				info = methodInfo;
			}
			else
			{
				info = natives->newNativeMethod(i);
				if (!info)
				{
					// If this assert hits, you're missing a native method.  Method "i"
					// corresponds to the function of the same number in 
					// source\avmglue\avmglue.h if you're running the Flash player.
					AvmAssertMsg(0, "missing native method decl");
					toplevel->throwVerifyError(kIllegalNativeMethodError);
				}
			}

			info->info_pos = info_pos;
			info->pool = pool;
			info->method_id = i;
			info->param_count = param_count;
			info->initParamTypes(param_count+1);
			info->flags |= flags;

			if (flags & AbstractFunction::HAS_OPTIONAL)
			{
				int optional_count = readU30(pos);

				info->optional_count = optional_count;
				for( int j = 0; j < optional_count; ++j)
				{
					readU30(pos);
					++pos; // Kind bytes for each default value
				}

				if (!optional_count || (optional_count > param_count))
				{
					// cannot have more optional params than total params
					toplevel->throwVerifyError(kCorruptABCError);
				}
			}

			if( flags & AbstractFunction::HAS_PARAM_NAMES)
			{
				// AVMPlus doesn't care about the param names, just skip past them
				for( int j = 0; j < info->param_count; ++j )
				{
					readU30(pos);
				}
			}

			// save method info pointer.  we will verify code later.
			pool->methods.set(i, info);
		}
    }
	

	void AbcParser::parseMetadataInfos()
    {
        uint32_t metadataCount = readU30(pos);

		if_verbose(
			core->console << "metadata_count=" << metadataCount << "\n";
		)

		if (metadataCount > uint32_t(abcEnd - pos))
			toplevel->throwVerifyError(kCorruptABCError);

		pool->metadata_infos.ensureCapacity(metadataCount);
		pool->metadataCount = metadataCount;

		if (metadataCount > 0)
		{
			metaNames = (Stringp*) core->GetGC()->Calloc(metadataCount, sizeof(Stringp), MMgc::GC::kContainsPointers);

#ifdef AVMPLUS_VERBOSE
			kVerboseVerify = core->constantString("VerboseVerify");
#endif

			for (uint32_t i=0; i < metadataCount; i++)
			{
				pool->metadata_infos.set(i, pos);
				// MetadataInfo
				uint32_t index = readU30(pos);
				Stringp name = resolveUtf8(index);
				// constant pool names are stuck and always reachable via PoolObject, DRC or WB
				metaNames[i] = name;

				if_verbose(
					core->console << "    " << name;
				)
				int values_count = readU30(pos);
				if (values_count > 0)
				{
					if_verbose(
						core->console << "(";
					)
					for(int q = 0; q < values_count; ++q)
					{
						uint32_t a = readU30(pos);
						uint32_t b = readU30(pos);
						if(keepVersions
							&& name == core->kVersion 
							&& a==0 
							&& keepVersions->indexOf(resolveUtf8(b))==-1)
						{
							// Found the metadata to strip
							pool->stripMetadataIndexes.add(i);
						}
						if_verbose(
							core->console << a << "," << b;
							if (q+1 < values_count)
								core->console << " ";
						)
					}
					if_verbose(
						core->console << ")";
					)
				}
				if_verbose(
					core->console << "\n";
				)
			}
		}
    }

    void AbcParser::parseMethodBodies()
    {
        int bodyCount = readU30(pos);

		if_verbose(
			core->console << "bodies_count=" << bodyCount << "\n";
		)

#if defined(AVMPLUS_VERBOSE) || defined(DEBUGGER)
		const byte* startpos = pos;
#endif

		for (int i=0; i < bodyCount; i++)
        {
#ifdef AVMPLUS_VERBOSE
			int offset = (int)(pos-startpos);
#endif

			uint32 method_info = readU30(pos);
			AbstractFunction* info = resolveMethodInfo(method_info);

			const byte *body_pos = pos;

            int max_stack = readU30(pos);
            (void)max_stack;
            
            int local_count = readU30(pos);

			if (local_count < info->param_count+1)
			{
				// must have enough locals to hold all parameters including this
				toplevel->throwVerifyError(kCorruptABCError);
			}

			// TODO change file format, just want local max_scope
			int init_scope_depth = readU30(pos);
			(void)init_scope_depth;
			
			int max_scope_depth = readU30(pos);
			(void)max_scope_depth;

			int code_length = readU30(pos);


			if (code_length <= 0) 
			{
				toplevel->throwVerifyError(kInvalidCodeLengthError, core->toErrorString(code_length));
			}

			// check to see if we are trying to jump past the file end or the beginning.
			if ( pos < abcStart || pos+code_length >= abcEnd )
				toplevel->throwVerifyError(kCorruptABCError);
            pos += code_length;

            int exception_count = readU30(pos);

			if_verbose(
				core->console << "    " << offset << ":method["<<method_info<<"] max_stack=" << max_stack
					<< " local_count=" << local_count 
					<< " init_scope_depth=" << init_scope_depth 
					<< " max_scope_depth=" << max_scope_depth
					<< " code_length=" << code_length
					<< " exception_count=" << exception_count
				    << "\n";
			)

			if (exception_count != 0) 
			{
				info->flags |= AbstractFunction::HAS_EXCEPTIONS;
				for (int i=0; i<exception_count; i++) 
				{
					// this will be parsed when method is verified.
					// see AbstractFunction::resolveSignature

					#ifdef AVMPLUS_VERBOSE
					int from = readU30(pos);
					int to = readU30(pos);
					int target = readU30(pos);
					Multiname typeName;
					parseTypeName(pos, typeName);

					Multiname qn;
					uint32 name_index = (version != (46<<16|15)) ? readU30(pos) : 0;
					if (name_index != 0)
					{
						if (name_index >= pool->constantMnCount)
							toplevel->throwVerifyError(kCpoolIndexRangeError, core->toErrorString(name_index), core->toErrorString(pool->constantCount));
						pool->parseMultiname(qn, name_index);
					}

					if (pool->verbose)
					{
						core->console << "            exception["<<i<<"] from="<< from
							<< " to=" << to
							<< " target=" << target 
							<< " type=" << typeName
							<< " name=";
						if (name_index)
						{
							core->console << qn;
						}
						else
						{
							core->console << "(none)";
						}
						core->console << "\n";
					}
					#else
					readU30(pos); // from
					readU30(pos); // to
					readU30(pos); // target
					readU30(pos); // type name
					if (version != (46<<16|15))
					{
						uint32 name_index = readU30(pos); // variable name
						if (name_index >= pool->constantMnCount)
							toplevel->throwVerifyError(kCpoolIndexRangeError, core->toErrorString(name_index), core->toErrorString(pool->constantCount));
					}
					#endif
				}
			}

			if (info->hasMethodBody())
			{
				MethodInfo *methodInfo = (MethodInfo*) info;

				// Interface methods should not have bodies
				if (info->declaringTraits && info->declaringTraits->isInterface)
				{
					toplevel->throwVerifyError(kIllegalInterfaceMethodBodyError, core->toErrorString(info));
				}

#ifdef DEBUGGER
				methodInfo->local_count = local_count;
				methodInfo->codeSize = code_length;
				methodInfo->max_scopes = max_scope_depth - init_scope_depth;
#endif

				// if non-zero, we have a duplicate method body - throw a verify error
				if (methodInfo->body_pos)
				{
					toplevel->throwVerifyError(kDuplicateMethodBodyError, core->toErrorString(info));
				}

				methodInfo->body_pos = body_pos;

				// there will be a traits_count here, even if NEED_ACTIVATION is not
				// set.  So we parse the same way all the time.  We could reduce file size and
				// memory by omitting the count + traits completely.

				const byte* traits_pos = pos;
				int nameCount = readU30(pos);
				if ((methodInfo->flags & AbstractFunction::NEED_ACTIVATION) || nameCount > 0)
				{
					pos = traits_pos;
					#ifdef AVMPLUS_VERBOSE
					const Namespacep ns = core->publicNamespace;
					const Stringp name = core->internString(methodInfo->name);
					#else
					const Namespacep ns = NULL;
					const Stringp name = NULL;
					#endif
					// activation traits are raw types, not subclasses of object.  this is
					// okay because they aren't accessable to the programming model.
					methodInfo->activationTraits = parseTraits(sizeof(ScriptObject), 
																NULL, 
																ns, 
																name, 
																NULL, 
																traits_pos,
																TRAITSTYPE_ACTIVATION, 
																NULL);
					methodInfo->activationTraits->final = true;
					//methodInfo->activationTraits->resolveSignatures(NULL);
				}
				else
				{
					// TODO remove this assert once abc format is adjusted
					AvmAssert(nameCount == 0);
				}
			}
			else
			{
				// native methods should not have bodies!
				toplevel->throwVerifyError(kIllegalNativeMethodBodyError, core->toErrorString(info));
			}
		}
    }

    void AbcParser::parseCpool()
    {
		pool = new (core->GetGC()) PoolObject(core, code, pos);
		pool->domain = domain;
		pool->isBuiltin = (natives != NULL);

		uint32 int_count = readU30(pos);
		// sanity check to prevent huge allocations
		if (int_count > (uint32)(abcEnd - pos)) 
			toplevel->throwVerifyError(kCorruptABCError);

		List<int>& cpool_int = pool->cpool_int;
		cpool_int.ensureCapacity(int_count);
		pool->constantIntCount = int_count;

#ifdef AVMPLUS_VERBOSE
		pool->verbose = core->config.verbose;
#endif

#if defined(AVMPLUS_VERBOSE) || defined(DEBUGGER)
		const byte* startpos = pos;
#endif

		for(uint32 i = 1; i < int_count; ++i)
		{
#ifdef AVMPLUS_VERBOSE
			int offset = (int)(pos-startpos);
#endif
			// S32 value
			cpool_int.set(i, readS32(pos));
			if_verbose(
				core->console << "    " << offset << ":" << "cpool_int["<<i<<"]="
					<<constantNames[CONSTANT_Int] << " ";
				core->console << cpool_int[i] << "\n";
			)
		}

		uint32 uint_count = readU30(pos);
		if (uint_count > (uint32)(abcEnd - pos))
			toplevel->throwVerifyError(kCorruptABCError);

		List<uint32>& cpool_uint = pool->cpool_uint;
		cpool_uint.ensureCapacity(uint_count);
		pool->constantUIntCount = uint_count;

#if defined(AVMPLUS_VERBOSE) || defined(DEBUGGER)
		startpos = pos;
#endif

		for(uint32 i = 1; i < uint_count; ++i)
		{
#ifdef AVMPLUS_VERBOSE
			int offset = (int)(pos-startpos);
#endif
			// U32 value
			cpool_uint.set(i, (unsigned)readS32(pos));

			if_verbose(
				core->console << "    " << offset << ":" << "cpool_uint["<<i<<"]="
					<<constantNames[CONSTANT_UInt] << " ";
				core->console << (double)cpool_uint[i];
				core->console << "\n";
			)
		}

		uint32 double_count = readU30(pos);
		if (double_count > (uint32)(abcEnd - pos))
			toplevel->throwVerifyError(kCorruptABCError);

		List<double*, LIST_GCObjects>& cpool_double = pool->cpool_double;
		cpool_double.ensureCapacity(double_count);
		pool->constantDoubleCount = double_count;

#if defined(AVMPLUS_VERBOSE) || defined(DEBUGGER)
		startpos = pos;
#endif

		for(uint32 i = 1; i < double_count; ++i)
		{
#ifdef AVMPLUS_VERBOSE
			int offset = (int)(pos-startpos);
#endif
			double value = readDouble(pos);
			cpool_double.set(i, (double*)(core->allocDouble(value)&~7));
			if_verbose(
				core->console << "    " << offset << ":" << "cpool_double["<<i<<"]="
					<<constantNames[CONSTANT_Double] << " ";
				core->console << *cpool_double[i];
				core->console << "\n";
			)
		}

		uint32 string_count = readU30(pos);
		if (string_count > (uint32)(abcEnd - pos))
			toplevel->throwVerifyError(kCorruptABCError);

		List<Stringp> &cpool_string = pool->cpool_string;
		MMGC_MEM_TYPE(pool);
		cpool_string.ensureCapacity(string_count);
		pool->constantStringCount = string_count;

#if defined(AVMPLUS_VERBOSE) || defined(DEBUGGER)
		startpos = pos;
#endif

		for(uint32 i = 1; i < string_count; ++i)
		{
#ifdef AVMPLUS_VERBOSE
			int offset = (int)(pos-startpos);
#endif

			// number of characters
			// todo - is compiler emitting no. of chars or no. of bytes?
			int len = readU30(pos);

			// check to see if we are trying to read past the file end or the beginning.
			if (pos < abcStart || pos+len >= abcEnd )
				toplevel->throwVerifyError(kCorruptABCError);
			// don't need to create an atom for this now, because
			// each caller will take care of it.
			Stringp s = core->internAllocUtf8(pos, len);
#ifdef MMGC_DRC
			// MIR skips WB on string constants so make them sticky
			s->Stick();
#endif
			cpool_string.set(i, s);
			pos += len;

			if_verbose(
				core->console << "    " << offset << ":" << "cpool_string["<<i<<"]="
					<<constantNames[CONSTANT_Utf8] << " ";
				core->console << core->format(cpool_string[i]->atom());
				core->console << "\n";
			)
		}

		uint32 ns_count = readU30(pos);
		if (ns_count > (uint32)(abcEnd - pos))
			toplevel->throwVerifyError(kCorruptABCError);

		List<Namespacep> &cpool_ns = pool->cpool_ns;

		MMGC_MEM_TYPE(pool);
		cpool_ns.ensureCapacity(ns_count);
		pool->constantNsCount = ns_count;

#if defined(AVMPLUS_VERBOSE) || defined(DEBUGGER)
		startpos = pos;
#endif
		for( uint32 i = 1; i < ns_count; ++i )
		{
#ifdef AVMPLUS_VERBOSE
			int offset = (int)(pos-startpos);
#endif
			CHECK_POS(pos);
			CPoolKind kind = (CPoolKind) *(pos++);
			switch(kind)
			{
				case CONSTANT_Namespace: 
                case CONSTANT_PackageNamespace:
                case CONSTANT_PackageInternalNs:
                case CONSTANT_ProtectedNamespace:
			    case CONSTANT_ExplicitNamespace:					
                case CONSTANT_StaticProtectedNs:
				{
					uint32 index = readU30(pos);
                    Namespace::NamespaceType type = Namespace::NS_Public;
                    switch(kind)
                    {
                    case CONSTANT_PackageInternalNs:
                        type = Namespace::NS_PackageInternal;
                        break;
                    case CONSTANT_ProtectedNamespace:
                        type = Namespace::NS_Protected;
                        break;
                    case CONSTANT_ExplicitNamespace:
                        type = Namespace::NS_Explicit;
						break;
                    case CONSTANT_StaticProtectedNs:
                        type = Namespace::NS_StaticProtected;
                        break;
                    }

                    if (index)
					{
						Stringp uri = resolveUtf8(index);
						cpool_ns.set(i, core->internNamespace(core->newNamespace(uri, type)));
					}
					else
					{
						// issue this looks wrong.  should uri be ""?
						Atom uri = undefinedAtom;
						cpool_ns.set(i, core->internNamespace(core->newNamespace(uri, type)));
					}
					break;
				}

				case CONSTANT_PrivateNs: 
				{
					uint32 index =  readU30(pos);
					Stringp uri = index ? resolveUtf8(index) : (Stringp)core->kEmptyString;
                    Namespacep ns = new (core->GetGC()) Namespace(nullStringAtom, uri, Namespace::NS_Private);
					cpool_ns.set(i, ns);
					break;
				}
				default:
				{
					toplevel->throwVerifyError(kCpoolEntryWrongTypeError, core->toErrorString(i));
				}
			}
			if_verbose(
				core->console << "    " << offset << ":" << "cpool_ns["<<i<<"]="
					<<constantNames[kind] << " ";
				core->console << core->format(cpool_ns[i]->atom());
				core->console << "\n";
			)
		}

		uint32 ns_set_count = readU30(pos);
		if (ns_set_count > (uint32)(abcEnd - pos))
			toplevel->throwVerifyError(kCorruptABCError);

		List<NamespaceSetp>& cpool_ns_set = pool->cpool_ns_set;
		cpool_ns_set.ensureCapacity(ns_set_count);
		pool->constantNsSetCount = ns_set_count;

#if defined(AVMPLUS_VERBOSE) || defined(DEBUGGER)
		startpos = pos;
#endif

		for( uint32 i = 1; i < ns_set_count; ++i)
		{
#ifdef AVMPLUS_VERBOSE
			int offset = (int)(pos-startpos);
#endif
			uint32 ns_count = readU30(pos);
			
			if (ns_count > (uint32)(abcEnd - pos))
				toplevel->throwVerifyError(kCorruptABCError);
			NamespaceSet* namespace_set = core->newNamespaceSet(ns_count);

			Namespacep* nss = namespace_set->namespaces;
			for(uint32 j=0; j < ns_count; ++j)
			{
				Namespacep ns = parseNsRef(pos);
				if (!ns)
					toplevel->throwVerifyError(kIllegalNamespaceError);
				//namespace_set->namespaces[j] = ns;
				WBRC(core->GetGC(), namespace_set, &nss[j], ns);
			}
			cpool_ns_set.set(i, namespace_set);

			if_verbose(
				core->console << "    " << offset << ":" << "cpool_ns_set["<<i<<"]="
					<<constantNames[CONSTANT_NamespaceSet] << " ";
				core->console << cpool_ns_set[i]->format(core);
				core->console << "\n";
			)
		}

		uint32 mn_count = readU30(pos);
		if (mn_count > (uint32)(abcEnd - pos))
			toplevel->throwVerifyError(kCorruptABCError);

		// TODO: why Atom?  its actually a list of positions
		List<Atom>& cpool_mn = pool->cpool_mn;
		MMGC_MEM_TYPE(pool);
		cpool_mn.ensureCapacity(mn_count);
		pool->constantMnCount = mn_count;

#if defined(AVMPLUS_VERBOSE) || defined(DEBUGGER)
		startpos = pos;
#endif
		for(uint32 i = 1; i < mn_count; ++i )
		{
#ifdef AVMPLUS_VERBOSE
			int offset = (int)(pos-startpos);
#endif
			CHECK_POS(pos);
			CPoolKind kind = (CPoolKind) *(pos++);
			switch(kind)
			{
			case CONSTANT_Qname: 
			case CONSTANT_QnameA:
			{
				// U16 namespace_index
				// U16 name_index
				// parse a multiname with one namespace (aka qname)
				cpool_mn.set(i, pool->posToAtom(pos-1));
				parseNsRef(pos);
				parseName(pos);
				break;
			}

			case CONSTANT_RTQname:
			case CONSTANT_RTQnameA: 
			{
				// U16 name_index
				// parse a multiname with just a name; ns fetched at runtime
				cpool_mn.set(i, pool->posToAtom(pos-1));
				parseName(pos);
				break;
			}
			case CONSTANT_RTQnameL:
			case CONSTANT_RTQnameLA:
			{
				cpool_mn.set(i, pool->posToAtom(pos-1));
				break;
			}

			case CONSTANT_Multiname:
			case CONSTANT_MultinameA:
			{
				cpool_mn.set(i, pool->posToAtom(pos-1));
   				
				parseName(pos);
				
				uint32 index = readU30(pos);

				if (!index || index >= pool->constantNsSetCount)
					toplevel->throwVerifyError(kCpoolIndexRangeError, core->toErrorString(index), core->toErrorString(pool->constantNsSetCount));

				// If it is in the range of Namespace Sets then it must be a namespace set/
				break;
			}

			case CONSTANT_MultinameL:
			case CONSTANT_MultinameLA:
			{
				cpool_mn.set(i, pool->posToAtom(pos-1));
   				
				uint32 index = readU30(pos);

				if (!index || index >= pool->constantNsSetCount)
					toplevel->throwVerifyError(kCpoolIndexRangeError, core->toErrorString(index), core->toErrorString(pool->constantNsSetCount));

				// If it is in the range of Namespace Sets then it must be a namespace set.

				break;
			}
			
			case CONSTANT_TypeName:
			{
				cpool_mn.set(i, pool->posToAtom(pos-1));

				uint32 index = readU30(pos);

				if(!index || index >= pool->constantMnCount)
					toplevel->throwVerifyError(kCpoolIndexRangeError, core->toErrorString(index), core->toErrorString(pool->constantMnCount));

				index = readU30(pos);
				if(index != 1)
					toplevel->throwVerifyError(kCorruptABCError);
				readU30(pos);
				break;
			}
			default:
				toplevel->throwVerifyError(kCpoolEntryWrongTypeError, core->toErrorString(i));
			}
			if_verbose(
				core->console << "    " << offset << ":" << "cpool_mn["<<i<<"]="
					<<constantNames[kind] << " ";
				Multiname name;
				pool->parseMultiname(name, i);
				core->console << name;
				core->console << "\n";
			)
		}
    }

	void AbcParser::addNamedTraits(Namespacep ns, Stringp name, Traits* itraits)
	{
		if (!ns->isPrivate() && !domain->getNamedTrait(name, ns))
		{
			domain->addNamedTrait(name, ns, itraits);
		}
		else
		{
			// duplicate class
			//Multiname qname(ns,name);
			//toplevel->definitionErrorClass()->throwError(kRedefinedError, core->toErrorString(&qname));
		}
	}
	
	void AbcParser::addNamedScript(Namespacep ns, Stringp name, AbstractFunction* script)
	{
		AbstractFunction* s = (AbstractFunction*) domain->getNamedScript(name, ns);
		if (!s)
		{
			if(ns->isPrivate())
			{
				pool->addPrivateNamedScript(name, ns, script);
			}
			else
			{
				domain->addNamedScript(name, ns, script);
			}
		}
		else
		{
			// duplicate definition
			//Multiname qname(ns, name);
			//toplevel->definitionErrorClass()->throwError(kRedefinedError, core->toErrorString(&qname));
		}
	}

	bool AbcParser::parseScriptInfos()
	{
		/*
			U16 script_count
			ScriptInfo[script_count]
			{
				U16 init_index			// method_info index of init function
				Traits script_traits    // traits for the global object of this package
			}
		*/

		uint32 count = readU30(pos);

		if_verbose(
			core->console << "script_count=" << count << "\n";
		)

#if defined(AVMPLUS_VERBOSE) || defined(DEBUGGER)
		const byte* startpos = pos;
#endif

		if (count == 0)
		{
			return true;
		}

		if (count > (uint32)(abcEnd - pos))
			toplevel->throwVerifyError(kCorruptABCError);

		pool->scripts.ensureCapacity(count);
		pool->scriptCount = count;

		// make global objects subclasses of Object

		for (uint32 i=0; i < count; i++)
		{
			const byte* script_pos = pos;

			int init_index = readU30(pos);

			if_verbose(
				core->console << "    " << (int)(script_pos-startpos) << ":script[" << i << "]"
					<< " init_index=" << init_index
					<< "\n";
			)
			AbstractFunction* script = resolveMethodInfo(init_index);
			AvmAssert(script->declaringTraits == NULL);

			if (script->declaringTraits != NULL)
			{
				// method has already been bound to a different type.  Can't bind it twice because
				// it can only have one environment, for its scope chain and super references.
				toplevel->throwVerifyError(kAlreadyBoundError, core->toErrorString(script), core->toErrorString((Traits*)script->declaringTraits));
			}

			const NativeScriptInfo* nativeEntry = natives ? natives->get_script(i) : NULL;
			Traits* traits = parseTraits(nativeEntry && nativeEntry->sizeofInstance ? nativeEntry->sizeofInstance : sizeof(ScriptObject), 
											core->traits.object_itraits, 
											core->publicNamespace, 
											core->kglobal, 
											script, 
											script_pos,
											TRAITSTYPE_SCRIPT_FROM_ABC,
											NULL);

			if( !traits ) return false; // parseTraits failed

			
			// global object, make it dynamic
			traits->setCreateGlobalObjectProc(nativeEntry ? nativeEntry->createGlobalObject : NULL);
			traits->set_needsHashtable(true);
			traits->final = true;

			script->makeMethodOf(traits);
			traits->init = script;

			#ifdef AVMPLUS_VERBOSE
			script->name = core->concatStrings(traits->format(core), core->newString("$init"));
			#endif

            #if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
			if (core->config.runmode == RM_mixed || core->config.runmode == RM_interp_all)
			{
				// suggest that we don't jit the $init methods
				script->flags |= AbstractFunction::SUGGEST_INTERP;
			}
			#endif

			pool->scripts.set(i, script);

			// initial scope chain is []
			traits->scope = ScopeTypeChain::create(core->GetGC(),NULL,0);
		}

		return true;
	}

	bool AbcParser::parseInstanceInfos()
    {
        classCount = readU30(pos);

		if_verbose(
			core->console << "class_count=" << classCount <<"\n";
		)

#if defined(AVMPLUS_VERBOSE) || defined(DEBUGGER)
		const byte* startpos = pos;
#endif

		if (classCount == 0)
		{
			return true;
		}

		if (classCount > uintptr_t(abcEnd - pos))
			toplevel->throwVerifyError(kCorruptABCError);

		// allocate room for class infos early, to handle nested classes
		pool->cinits.ensureCapacity(classCount);
		pool->classCount = classCount;

		instances.ensureCapacity(classCount);

        for (uint32_t i=0; i < classCount; i++)
        {
            const byte* instancepos = pos;

            // CONSTANT_QName name of this class
			Namespacep ns;
			Stringp name;

			Multiname qname;
			resolveQName(pos, qname);
			ns = qname.getNamespace();
			name = qname.getName();

			// resolving base class type means class heirarchy must be a Tree
			Traits* baseTraits = pool->resolveTypeName(pos, toplevel);

			if (baseTraits && baseTraits->final ||
				CLASS_TYPE != NULL && baseTraits == CLASS_TYPE ||
				FUNCTION_TYPE != NULL && baseTraits == FUNCTION_TYPE)
			{
				// error - attempt to extend final class
				if_verbose(
					core->console << qname << " can't extend final class " << baseTraits << "\n";
				)
				toplevel->throwVerifyError(kCannotExtendFinalClass, core->toErrorString(&qname));
			}

			if (baseTraits && baseTraits->isInterface)
			{
				// error, can't extend interface
				toplevel->throwVerifyError(kCannotExtendError, core->toErrorString(&qname), core->toErrorString(baseTraits));
			}

            // read flags:	bit 0: sealed
			//				bit 1: final
			//              bit 2: interface
			//              bit 3: protected
			CHECK_POS(pos);
			int flags = *pos++;

			// read protected namespace
			Namespacep protectedNamespace = NULL;
			if (flags & 8)
			{
				protectedNamespace = parseNsRef(pos);
			}
			
            int interfaceCount = readU30(pos);
			const byte* interfacePos = pos;

			if(interfaceCount)
			{
				for( int x = 0; x < interfaceCount; ++ x )
				{
					Traits *t = pool->resolveTypeName(pos, toplevel);
					if (!t || !t->isInterface)
					{
						// error, can't extend interface
						toplevel->throwVerifyError(kCannotImplementError, core->toErrorString(&qname), core->toErrorString(t));
					}
				}
			}

			// TODO make sure the inheritance is legal.  
			//  - can't override final members
			//  - overrides agree with base class signature
			
            uint32 iinit_index = readU30(pos);
			AbstractFunction *iinit = resolveMethodInfo(iinit_index);

			if_verbose(
				// TODO:  fixup this math here, since the 2's are all wrong
				core->console
					<< "    " << (int)(instancepos-startpos) << ":instance[" << i << "]"
					<< " " << qname;

				if (baseTraits)
					core->console << " extends " << baseTraits;

				core->console
					<< " interface_count=" << interfaceCount
					<< " iinit_index=" << iinit_index
					<< "\n";
			)

			#if defined AVMPLUS_VERBOSE || defined FEATURE_SAMPLER
			iinit->name = Multiname::format(core,ns,name);
			#endif

			Traits* itraits = parseTraits(computeInstanceSize(i, baseTraits), 
											baseTraits, 
											ns, 
											name, 
											0, 
											instancepos,
											TRAITSTYPE_INSTANCE_FROM_ABC, 
											protectedNamespace);
			if( !itraits ) return false;
			if (!baseTraits && core->traits.object_itraits == NULL)
			{
				// save object traits
				core->traits.object_itraits = itraits;
				itraits->builtinType = BUILTIN_object;
			}

			// AS3 language decision: dynamic is not inherited.
			itraits->set_needsHashtable((flags&1) == 0);
			itraits->final   = (flags&2) != 0;

			if (flags & 4)
			{
				itraits->isInterface = true;

				// check for slotCount != 0 now done at resolve time

				// interface base must be *
				if (baseTraits)
				{
					// error, can't extend this type
					toplevel->throwVerifyError(kCannotExtendError, core->toErrorString(&qname), core->toErrorString(baseTraits));
				}
			}

			if (iinit->declaringTraits != NULL)
			{
				// method has already been bound to a different type.  Can't bind it twice because
				// it can only have one environment, for its scope chain and super references.
				toplevel->throwVerifyError(kAlreadyBoundError, core->toErrorString(iinit), core->toErrorString((Traits*)iinit->declaringTraits));
			}

			iinit->makeMethodOf(itraits);
			itraits->init = iinit;

			// parse the interfaces.  resolving type refs here means interface heirarchy must be a DAG.
			for (int j=0, n=interfaceCount; j < n; j++)
			{
				Traits *interfaceTraits = pool->resolveTypeName(interfacePos, toplevel);
				(void)interfaceTraits;
				if_verbose(
					core->console << "        interface["<<j<<"]=" << interfaceTraits <<"\n";
				)
			}
						
			instances.set(i, itraits);

			if (pool->getTraits(name, ns, false) == NULL)
			{
				pool->addNamedTraits(name, ns, itraits);
			}
			else
			{
				// error, can't redefine a class or interface
				//toplevel->definitionErrorClass()->throwError(kRedefinedError, core->toErrorString(&qname));
			}
        }

		return true;
    }

	void AbcParser::parseClassInfos()
    {
		if (classCount == 0)
		{
			return;
		}

#if defined(AVMPLUS_VERBOSE) || defined(DEBUGGER)
		const byte* startpos = pos;
#endif

        for (uint32_t i=0; i < classCount; i++)
        {
            // CONSTANT_Multiname name of this class
			Traits* itraits = instances[i];
			Namespacep ns = itraits->ns;
			Stringp name = itraits->name;

			const byte* class_pos = pos;

			uint32 cinit_index = readU30(pos);
            AbstractFunction *cinit = resolveMethodInfo(cinit_index);

			if_verbose(
				core->console
					<< "    " << (int)(class_pos-startpos) << ":class[" << i << "]"
					<< " " << ns << "::" << name;

				core->console
					<< " cinit_index=" << cinit_index
					<< "\n";
			)

			#if defined AVMPLUS_VERBOSE || defined FEATURE_SAMPLER
			Stringp cinitName = core->concatStrings(name, core->newString("$cinit"));
			cinit->name = Multiname::format(core,ns,cinitName);
			#endif

			const NativeClassInfo* nativeEntry = natives ? natives->get_class(i) : NULL;
			Traits* ctraits = parseTraits(nativeEntry && nativeEntry->sizeofClass ? nativeEntry->sizeofClass : sizeof(ClassClosure),
											CLASS_TYPE, 
											ns, 
											core->internString(core->concatStrings(name, core->newString("$"))), 
											NULL, 
											class_pos,
											TRAITSTYPE_CLASS_FROM_ABC, 
											itraits->protectedNamespace);

			ctraits->setCreateClassClosureProc(nativeEntry ? nativeEntry->createClassClosure : NULL);
			AvmAssert(cinit->declaringTraits == NULL);

			if (cinit->declaringTraits != NULL)
			{
				// method has already been bound to a different type.  Can't bind it twice because
				// it can only have one environment, for its scope chain and super references.
				toplevel->throwVerifyError(kAlreadyBoundError, core->toErrorString(cinit), core->toErrorString((Traits*)cinit->declaringTraits));
			}
			
			cinit->makeMethodOf(ctraits);
			ctraits->init = cinit;
			ctraits->itraits = itraits;
			ctraits->final = true;
			ctraits->set_needsHashtable(true);

            #if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
			if (core->config.runmode == RM_mixed || core->config.runmode == RM_interp_all)
			{
				// suggest that we don't jit the class initializer
				cinit->flags |= AbstractFunction::SUGGEST_INTERP;
			}
			#endif

			pool->cinits.set(i, cinit);
        }
    }

	uint32_t AbcParser::readU30(const byte*& p) const
	{
		// We have added kBufferPadding bytes to the end of the main swf buffer.
		// Why?  Here we can read from 1 to 5 bytes.  If we were to
		// put the required safety checks at each byte read, we would slow
		// parsing of the file down.  With this buffer, only one check at the
		// top of this function is necessary. (we will read on into our own memory)
		CHECK_POS(p);
		return toplevel->readU30(p);
	}

	double AbcParser::readDouble(const byte* &p) const
	{
#ifdef SAFE_PARSE
		// check to see if we are trying to read past the file end.
		if (p < abcStart || p+7 >= abcEnd )
			toplevel->throwVerifyError(kCorruptABCError);
#endif //SAFE_PARSE

		union {
			double value;
			#if defined AVMPLUS_BIG_ENDIAN || defined AVMPLUS_ARM_OLDABI
				struct { uint32_t hi, lo; } words;
			#else
				struct { uint32_t lo, hi; } words;
			#endif
		};
		// the bytes in the abc are little endian but the words
		// in memory can be little endian or big endian.
		words.lo = p[0] | p[1]<<8 | p[2]<<16 | p[3]<<24;
		words.hi = p[4] | p[5]<<8 | p[6]<<16 | p[7]<<24;
		p += 8;
		return value;
	}
}
