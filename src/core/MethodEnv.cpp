/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: t; tab-width: 4; -*- */
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

namespace avmplus
{
#undef DEBUG_EARLY_BINDING

	inline Atom *MethodEnv::unbox1(AvmCore* core, Toplevel* toplevel, Atom in, Traits *t, Atom *args)
	{
		AvmAssert(t != VOID_TYPE);

		if (t == NUMBER_TYPE) 
		{
			union {
				double d;
				uint32 l[2];
			};
			d = core->number(in);
			#ifdef AVMPLUS_64BIT
			AvmAssert(sizeof(Atom) == sizeof(double));
			*(double *) args = d;
			args++;
			#else
			AvmAssert(sizeof(Atom) * 2 == sizeof(double));
			*args++ = l[0];
			*args++ = l[1];
			#endif
		}
		else if (t == INT_TYPE)
		{
			*args++ = core->integer(in);
		}
		else if (t == UINT_TYPE)
		{
			*args++ = core->toUInt32(in);
		}
		else if (t == BOOLEAN_TYPE)
		{
			*args++ = core->boolean(in);
		}
		else if (t == OBJECT_TYPE)
		{
			*args++ = in == undefinedAtom ? nullObjectAtom : in;
		}
		else if (!t)
		{
			*args++ = in;
		}
		else
		{
			// ScriptObject, String, or Namespace, or Null
			*args++ = toplevel->coerce(in,t) & ~7;
		}
		return args;
	}
	
	inline Atom coerceAtom(AvmCore* core, Toplevel* toplevel, Atom in, Traits *t)
	{
		AvmAssert(t != VOID_TYPE);
		
		if (t == NUMBER_TYPE)
		{
			if (AvmCore::isDouble(in))
				return in;
			return core->numberAtom(in);
		}
		if (t == INT_TYPE)
		{
			if (AvmCore::isInteger(in))
				return in;
			return core->intAtom(in);
		}
		if (t == UINT_TYPE)
		{
			if (AvmCore::isInteger(in) && in >= 0)
				return in;
			return core->uintAtom(in);
		}
		if (t == BOOLEAN_TYPE)
		{
			if (AvmCore::isBoolean(in))
				return in;
			return core->booleanAtom(in);
		}
		if (t == OBJECT_TYPE)
		{
			if (in == undefinedAtom)
				return nullObjectAtom;
			return in;
		}
		if (t == NULL)
		{
			return in;
		}
		// ScriptObject, String, or Namespace, or Null
		return toplevel->coerce(in,t);
	}
	
	// helper
	inline int MethodEnv::startCoerce(int argc)
	{
		Toplevel* toplevel = vtable->toplevel;

		if (!method->argcOk(argc))
		{
			toplevel->argumentErrorClass()->throwError(kWrongArgumentCountError, 
													   core()->toErrorString((AbstractFunction*)method), 
													   core()->toErrorString(method->requiredParamCount()), 
													   core()->toErrorString(argc));
		}

		// Can happen with duplicate function definitions from corrupt ABC data.  F1 is defined
		// and F2 overrides the F1 slot which is okay as long as F1's MethodEnv is never called again.
		if (method->declaringTraits != this->declTraits)
		{
			toplevel->throwVerifyError(kCorruptABCError);
		}

		// just do enough to resolve signatures.  Don't do a full verify yet.
		method->resolveSignature(toplevel);

		// now unbox everything, including instance and rest args
		int extra = argc > method->param_count ? argc - method->param_count : 0;
		AvmAssert(method->restOffset > 0 && extra >= 0);

		return extra;
	}

	// helper
	inline Atom MethodEnv::endCoerce(int argc, uint32 *ap)
	{
		// we know we have verified the method, so we can go right into it.
		Traits* returnType = method->returnTraits();
		AvmCore* core = this->core();
		if (returnType == NUMBER_TYPE)
		{
			AvmAssert(method->implN != NULL);
			double d = method->implN(this, argc, ap);
			return core->doubleToAtom(d);
		}
		else
		{
			AvmAssert(method->impl32 != NULL);
			Atom i = method->impl32(this, argc, ap);
			if (returnType == INT_TYPE)
				return core->intToAtom((int)i);
			else if (returnType == UINT_TYPE)
				return core->uintToAtom((uint32)i);
			else if (returnType == BOOLEAN_TYPE)
				return i ? trueAtom : falseAtom;
			else if (!returnType || returnType == OBJECT_TYPE || returnType == VOID_TYPE)
				return (Atom)i;
			else if (returnType == STRING_TYPE)
				return ((Stringp)i)->atom();
			else if (returnType == NAMESPACE_TYPE)
				return ((Namespace*)i)->atom();
			else
				return ((ScriptObject*)i)->atom();
		}
	}

	// In interp-only builds this could still be delegateInvoke or verifyEnter.
	//
	// OPTIMIZEME: It would be nice to avoid the unbox / rebox paths through
	// those functions in interpreter-only builds!
	
	inline bool MethodEnv::isInterpreted()
	{
		return impl32 == interp32 || implN == interpN;
	}
	
	// Optimization opportunities: since we call interp() directly, it is
	// probably possible to allocate its stack frame here and pass it in.
	// If we do so then interp() should deallocate it.  This affords us
	// the optimization of getting rid of alloca() allocation here, 
	// which means improved tail calls for once.  For another, if the argv
	// pointer points into the stack segment s.t. argv+argc+1 equals the
	// current stack pointer then the stack may be extended in place 
	// provided there's space.  But that optimization may equally well
	// be performed inside interp(), and in fact if we alloc temp
	// space on the alloca stack here then interp() would always perform
	// that optimization.  So we'd just be moving the decision into interp().
	
	// fast/optimized call to a function without parameters
	Atom MethodEnv::coerceEnter(Atom thisArg)
	{
		startCoerce(0);
		// check receiver type first
		// caller will coerce instance if necessary,
		// so make sure it was done.
		AvmAssert(thisArg == toplevel()->coerce(thisArg, method->paramTraits(0)));
		if (isInterpreted())
		{
			// Tail call inhibited by &thisArg, and also by &thisArg in "else" clause
			return interp(this, 0, &thisArg);
		}
		else
		{
			unbox1(core(), toplevel(), thisArg, method->paramTraits(0), &thisArg);
			return endCoerce(0, (uint32*)&thisArg);
		}
	}
	
	Atom MethodEnv::coerceEnter(Atom thisArg, ArrayObject *a)
	{
		int argc = a->getLength();
		if (argc == 0)
			return coerceEnter(thisArg);
		int extra = startCoerce(argc);

		// check receiver type first
		// caller will coerce instance if necessary,
		// so make sure it was done.
		AvmAssert(thisArg == toplevel()->coerce(thisArg, method->paramTraits(0)));

		if (isInterpreted())
		{
			// Tail call inhibited by local allocation/deallocation
			AvmCore::AllocaAutoPtr _atomv;
			Atom* atomv = (Atom*)VMPI_alloca(core(), _atomv, sizeof(Atom)*(argc+1));
			atomv[0] = thisArg;
			for ( int i=0 ; i < argc ; i++ )
				atomv[i+1] = a->getUintProperty(i);
			return coerceEnter(argc, atomv);
		}
		else
		{
			size_t extra_sz = method->restOffset + sizeof(Atom)*extra;
			AvmCore::AllocaAutoPtr _ap;
			uint32_t *ap = (uint32 *)VMPI_alloca(core(), _ap, extra_sz);

			unboxCoerceArgs(thisArg, a, ap);
			return endCoerce(argc, ap);
		}
	}

	// It is enough that the exception handling mechanism knows how to unwind the alloca stack.
	// If TRY captures the current stack top and the CATCH and/or FINALLY just reset it, then
	// we're done.
	//
	// Then we can just call it AVMPI_alloca() and be done.
	//
	// Woot!
	
	Atom MethodEnv::coerceEnter(Atom thisArg, int argc, Atom *argv)
	{
		int extra = startCoerce(argc);

		// check receiver type first
		// caller will coerce instance if necessary,
		// so make sure it was done.
		AvmAssert(thisArg == toplevel()->coerce(thisArg, method->paramTraits(0)));

		if (isInterpreted())
		{
			// Tail call inhibited by local allocation/deallocation
			AvmCore::AllocaAutoPtr _atomv;
			Atom* atomv = (Atom*)VMPI_alloca(core(), _atomv, sizeof(Atom)*(argc+1));
			atomv[0] = thisArg;
			memcpy(atomv+1, argv, sizeof(Atom)*argc);
			return coerceEnter(argc, atomv);
		}
		else
		{
			size_t extra_sz = method->restOffset + sizeof(Atom)*extra;
			AvmCore::AllocaAutoPtr _ap;
			uint32_t *ap = (uint32 *)VMPI_alloca(core(), _ap, extra_sz);
				
			unboxCoerceArgs(thisArg, argc, argv, ap);
			return endCoerce(argc, ap);
		}
	}

	Atom MethodEnv::coerceEnter(int argc, Atom* atomv)
	{
		// check receiver type first
		// caller will coerce instance if necessary,
		// so make sure it was done.

		AvmAssert(atomv[0] == toplevel()->coerce(atomv[0], method->paramTraits(0)));

		// Trying hard here to allow this to be a tail call, so don't inline
		// coerceUnboxEnter into this function - the allocation it performs
		// may prevent the compiler from performing the tail call.
		//
		// The tail call is important in order to keep stack consumption down in an
		// interpreter-only configuration, but it's good always.

		if (isInterpreted())
		{
			AvmCore* core = this->core();
			Toplevel* toplevel = this->toplevel();
			
			startCoerce(argc);
			int end = argc >= method->param_count ? method->param_count : argc;
			for ( int i=1 ; i <= end ; i++ )
				atomv[i] = coerceAtom(core, toplevel, atomv[i], method->paramTraits(i));
			return interp(this, argc, atomv);
		}
		else
			return coerceUnboxEnter(argc, atomv);
	}

	// In principle we want this to be inlined if the compiler is not tailcall-aware,
	// and not inlined if it is tailcall-aware (as doing so may inhibit tail calls).
	Atom MethodEnv::coerceUnboxEnter(int argc, Atom* atomv)
	{
		int extra = startCoerce(argc);
		size_t extra_sz = method->restOffset + sizeof(Atom)*extra;
		AvmCore::AllocaAutoPtr _ap;
		uint32_t *ap = (uint32_t *)VMPI_alloca(core(), _ap, extra_sz);
			
		unboxCoerceArgs(argc, atomv, ap);
		return endCoerce(argc, ap);
	}

	/**
	 * convert atoms to native args.  argc is the number of
	 * args, not counting the instance which is arg[0].  the
	 * layout is [instance][arg1..argN]
	 */
	void MethodEnv::unboxCoerceArgs(int argc, Atom* in, uint32 *argv)
	{
		AbstractFunction* f = this->method;
		AvmCore* core = this->core();
		Toplevel* toplevel = this->toplevel();

		Atom *args = unbox1(core, toplevel, in[0], f->paramTraits(0), (Atom *) argv);

		int end = argc >= f->param_count ? f->param_count : argc;
		for (int i=0; i < end; i++)
			args = unbox1(core, toplevel, in[i+1], f->paramTraits(i+1), args);
		while (end < argc)
			*args++ = in[++end];
	}

	void MethodEnv::unboxCoerceArgs(Atom thisArg, ArrayObject *a, uint32 *argv)
	{
		AbstractFunction* f = this->method;
		AvmCore* core = this->core();
		Toplevel* toplevel = this->toplevel();
		int argc = a->getLength();

		Atom *args = unbox1(core, toplevel, thisArg, f->paramTraits(0), (Atom *) argv);

		int end = argc >= f->param_count ? f->param_count : argc;
		for (int i=0; i < end; i++)
			args = unbox1(core, toplevel, a->getUintProperty(i), f->paramTraits(i+1), args);
		while (end < argc)
			*args++ = a->getUintProperty(end++);
	}

	void MethodEnv::unboxCoerceArgs(Atom thisArg, int argc, Atom* in, uint32 *argv)
	{
		AbstractFunction* f = this->method;
		AvmCore* core = this->core();
		Toplevel* toplevel = this->toplevel();

		Atom *args = unbox1(core, toplevel, thisArg, f->paramTraits(0), (Atom *) argv);

		int end = argc >= f->param_count ? f->param_count : argc;
		for (int i=0; i < end; i++)
			args = unbox1(core, toplevel, in[i], f->paramTraits(i+1), args);
		while (end < argc)
			*args++ = in[end++];
	}

	Atom MethodEnv::delegateInvoke(MethodEnv* env, int argc, uint32 *ap)
	{
		env->impl32 = env->method->impl32;
#if 0 // This is handled near the top of interp() for the moment, see comments there
#ifdef AVMPLUS_WORD_CODE
		{
			// Install the lookup cache here, if the information is available to create it.
			// Otherwise it's done in verifyEnter, inside env->impl32() below.
			using namespace MMgc;
			MethodInfo* info = (MethodInfo*)(AbstractFunction*) env->method;
			int n;
			if ((n = info->word_code.cache_size) > 0) {
				AvmAssert(env->lookup_cache == NULL);
				env->lookup_cache = (LookupCache*)env->core()->GetGC()->Alloc(sizeof(LookupCache)*n, GC::kContainsPointers|GC::kZero);
			}
		}
#endif
#endif // 0
		return env->impl32(env, argc, ap);
	}

#if defined(AVMPLUS_MIR) || defined(FEATURE_NANOJIT)
	MethodEnv::MethodEnv(void *addr, VTable *vtable)
		: vtable(vtable), method(NULL), declTraits(NULL), activationOrMCTable(0)
	{
		implV = addr;
		AVMPLUS_TRAITS_MEMTRACK_ONLY( tmt_add_inst( TMT_methodenv, this); )
	}
#endif

	MethodEnv::MethodEnv(AbstractFunction* method, VTable *vtable)
		: vtable(vtable)
		, method(method)
		, declTraits(method->declaringTraits)
		, activationOrMCTable(0)
	{
		// make the first call go to the method impl
		impl32 = delegateInvoke;

		AvmCore* core = vtable->traits->core;
		if (method->declaringTraits != vtable->traits)
		{
		#ifdef AVMPLUS_VERBOSE
			core->console << "ERROR " << method->name << " " << method->declaringTraits << " " << vtable->traits << "\n";
		#endif
			AvmAssertMsg(0, "(method->declaringTraits != vtable->traits)");
			toplevel()->throwVerifyError(kCorruptABCError);
		}

		if (method->flags & AbstractFunction::NEED_ACTIVATION)
		{
			// This can happen when the ABC has MethodInfo data but not MethodBody data
			if (!method->activationTraits)
			{
				toplevel()->throwVerifyError(kCorruptABCError);
			}

			VTable *activation = core->newVTable(method->activationTraits, NULL, vtable->scope, vtable->abcEnv, toplevel());
			activation->resolveSignatures();
			setActivationOrMCTable(activation, kActivation);
		}
		AVMPLUS_TRAITS_MEMTRACK_ONLY( tmt_add_inst( TMT_methodenv, this); )
	}
	
#ifdef AVMPLUS_TRAITS_MEMTRACK 
	MethodEnv::~MethodEnv()
	{
		AVMPLUS_TRAITS_MEMTRACK_ONLY( tmt_sub_inst(TMT_methodenv, this); )
	}
#endif

#ifdef FEATURE_SAMPLER
	void MethodEnv::debugEnter(int argc, uint32 *ap, 
							   Traits**frameTraits, int localCount,
							   CallStackNode* callstack,
							   Atom* framep, volatile sintptr *eip)
	{
		debugEnterInner(argc, (void*)ap, frameTraits, localCount, callstack, framep, eip, false);
	}
	
	void MethodEnv::debugEnterInner(int argc, 
									void *ap, 
									Traits**frameTraits, 
									int localCount,
									CallStackNode* callstack,
									Atom* framep, 
									volatile sintptr *eip,
									bool boxed)
	{
		AvmCore* core = this->core();

#ifdef DEBUGGER
		// update profiler
		// sendEnter ignores the arguments, ergo we pass 0, 0
		sendEnter(0, 0 /* argc, ap */);

		// dont reset the parameter traits since they are setup in the prologue
		int firstLocalAt = method->param_count+1;
		AvmAssert(!frameTraits || localCount >= firstLocalAt);
		if (frameTraits) memset(&frameTraits[firstLocalAt], 0, (localCount-firstLocalAt)*sizeof(Traits*));
		if (callstack) callstack->init(this, framep, frameTraits, argc, ap, eip, /*scopeDepth*/NULL, boxed);
		if (core->debugger) core->debugger->_debugMethod(this);
#else
		(void)localCount;
		if (callstack) callstack->init(this);
#endif

		core->sampleCheck();

#ifdef DEBUGGER
		invocationCount++;
#endif
	}

	void MethodEnv::debugExit(CallStackNode* callstack)
	{
		AvmAssert(this != 0);
		AvmCore* core = this->core();

#ifdef DEBUGGER
		// update profiler 
		sendExit();
#endif

		core->callStack = callstack->next();

#ifdef DEBUGGER
		// trigger a faked "line number changed" since we exited the function and are now back on the old line (well, almost)
		if (core->callStack && core->callStack->linenum() > 0)
		{
			int line = core->callStack->linenum();
			core->callStack->set_linenum(-1);
			if (core->debugger) core->debugger->debugLine(line);
		}
#endif
	}
#endif

#ifdef DEBUGGER
	void MethodEnv::sendEnter(int /*argc*/, uint32 * /*ap*/)
	{
		Profiler *profiler = core()->profiler;
		if (profiler && profiler->profilingDataWanted && !core()->sampler()->sampling)
			profiler->sendFunctionEnter(method);
	}

	void MethodEnv::sendExit()
	{
		Profiler *profiler = core()->profiler;
		if (profiler && profiler->profilingDataWanted && !core()->sampler()->sampling)
			profiler->sendFunctionExit();
	}
#endif

    void FASTCALL MethodEnv::nullcheckfail(Atom atom)
    {
		AvmAssert(AvmCore::isNullOrUndefined(atom));

		// TypeError in ECMA
		ErrorClass *error = toplevel()->typeErrorClass();
		if( error ){
			error->throwError(
					(atom == undefinedAtom) ? kConvertUndefinedToObjectError :
										kConvertNullToObjectError);
		} else {
			toplevel()->throwVerifyError(kCorruptABCError);
		}
    }

	void MethodEnv::npe()
	{
		toplevel()->throwTypeError(kConvertNullToObjectError);
	}

	void MethodEnv::interrupt()
	{
		vtable->traits->core->interrupt(this);
	}

    void MethodEnv::stkover()
    {
        this->core()->stackOverflow(this);
    }

	ArrayObject* MethodEnv::createRest(Atom* argv, int argc)
	{
		// create arguments Array using argv[param_count..argc]
		Atom* extra = argv + method->param_count + 1;
		int extra_count = argc > method->param_count ? argc - method->param_count : 0;
		return toplevel()->arrayClass->newarray(extra, extra_count);
	}

#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT

	Atom MethodEnv::getpropertyHelper(Atom obj, /* not const */ Multiname *multi, VTable *vtable, Atom index)
	{
		if ((index&7) == kIntegerType)
		{
			return getpropertylate_i(obj, (int)(index>>3));
		}

		if ((index&7) == kDoubleType)
		{
			int i = AvmCore::integer_i(index);
			if ((double)i == AvmCore::atomToDouble(index))
			{
				return getpropertylate_i(obj, i);
			}
		}

		if (AvmCore::isObject(index))
		{
			ScriptObject* i = AvmCore::atomToScriptObject(index);
			if (i->traits() == core()->traits.qName_itraits)
			{
				QNameObject* qname = (QNameObject*) i;
				qname->getMultiname(*multi);
			}
			else if(!multi->isRtns() && core()->isDictionary(obj))
			{
				return AvmCore::atomToScriptObject(obj)->getAtomProperty(index);
			}
			else
			{
				multi->setName(core()->intern(index));
			}
		}
		else
		{
			multi->setName(core()->intern(index));
		}

		return toplevel()->getproperty(obj, multi, vtable);
	}

	void MethodEnv::initpropertyHelper(Atom obj, /* not const */ Multiname *multi, Atom value, VTable *vtable, Atom index)
	{
		if ((index&7) == kIntegerType)
		{
			setpropertylate_i(obj, (int)(index>>3), value);
			return;
		}

		if ((index&7) == kDoubleType)
		{
			int i = core()->integer(index);
			uint32 u = (uint32)(i);
			if ((double)u == AvmCore::atomToDouble(index))
			{
				setpropertylate_u(obj, u, value);
				return;
			}
			else if ((double)i == AvmCore::atomToDouble(index))
			{
				setpropertylate_i(obj, i, value);
				return;
			}
		}

		if (AvmCore::isObject(index))
		{
			ScriptObject* i = AvmCore::atomToScriptObject(index);
			if (i->traits() == core()->traits.qName_itraits)
			{
				QNameObject* qname = (QNameObject*) i;
				qname->getMultiname(*multi);
			}
			else
			{
				multi->setName(core()->intern(index));
			}
		}
		else
		{
			multi->setName(core()->intern(index));
		}

		initproperty(obj, multi, value, vtable);
	}

	void MethodEnv::setpropertyHelper(Atom obj, /* not const */ Multiname *multi, Atom value, VTable *vtable, Atom index)
	{
		if ((index&7) == kIntegerType)
		{
			setpropertylate_i(obj, (int)(index>>3), value);
			return;
		}

		if ((index&7) == kDoubleType)
		{
			int i = core()->integer(index);
			uint32 u = (uint32)(i);
			if ((double)u == AvmCore::atomToDouble(index))
			{
				setpropertylate_u(obj, u, value);
				return;
			}
			else if ((double)i == AvmCore::atomToDouble(index))
			{
				setpropertylate_i(obj, i, value);
				return;
			}
		}

		if (AvmCore::isObject(index))
		{
			ScriptObject* i = AvmCore::atomToScriptObject(index);
			if (i->traits() == core()->traits.qName_itraits)
			{
				QNameObject* qname = (QNameObject*) i;
				qname->getMultiname(*multi);
			}	
			else if(!multi->isRtns() && core()->isDictionary(obj))
			{
				AvmCore::atomToScriptObject(obj)->setAtomProperty(index, value);
				return;
			}
			else
			{
				multi->setName(core()->intern(index));
			}
		}
		else
		{
			multi->setName(core()->intern(index));
		}

		toplevel()->setproperty(obj, multi, value, vtable);
	}
	
	Atom MethodEnv::delpropertyHelper(Atom obj, /* not const */ Multiname *multi, Atom index)
	{
		AvmCore* core = this->core();

		if (AvmCore::isObject(obj) && AvmCore::isObject(index))
		{
            if( core->isXMLList(index) )
            {
                // Error according to E4X spec, section 11.3.1
                toplevel()->throwTypeError(kDeleteTypeError, core->toErrorString(toplevel()->toTraits(index)));
            }
			ScriptObject* i = AvmCore::atomToScriptObject(index);
			if (i->traits() == core->traits.qName_itraits)
			{
				QNameObject* qname = (QNameObject*) i;
				qname->getMultiname(*multi);
			}
			else if(!multi->isRtns() && core->isDictionary(obj))
			{
				bool res = AvmCore::atomToScriptObject(obj)->deleteAtomProperty(index);
				return res ? trueAtom : falseAtom;
			}
			else
			{
				multi->setName(core->intern(index));
			}
		}
		else
		{
			multi->setName(core->intern(index));
		}

		return delproperty(obj, multi);
	}

	void MethodEnv::initMultinameLateForDelete(Multiname& name, Atom index)
	{
		AvmCore *core = this->core();
		
		if (AvmCore::isObject(index))
		{
            if (core->isXMLList(index))
            {
                // Error according to E4X spec, section 11.3.1
                toplevel()->throwTypeError(kDeleteTypeError, core->toErrorString(toplevel()->toTraits(index)));
            }
			
			ScriptObject* i = AvmCore::atomToScriptObject(index);
			if (i->traits() == core->traits.qName_itraits)
			{
				QNameObject* qname = (QNameObject*) i;
				bool attr = name.isAttr();
				qname->getMultiname(name);
				if (attr)
					name.setAttr(attr);
				return;
			}
		}

		name.setName(core->intern(index));
	}		
#endif

	ScriptObject* MethodEnv::newcatch(Traits* traits)
	{
		AvmCore* core = this->core();
		Toplevel* toplevel = this->toplevel();
		if (traits == core->traits.object_itraits)
		{
			// don't need temporary vtable.  this is a scope for a finally clause
			// todo: asc shouldn't even call OP_newcatch in a finally clause
			return toplevel->objectClass->construct();
		}
		else
		{
			VTable *vt = core->newVTable(traits, NULL, vtable->scope, vtable->abcEnv, toplevel);
			vt->resolveSignatures();
			return core->newObject(vt, NULL);
		}
	}

#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
	ArrayObject* MethodEnv::createArgumentsHelper(int argc, uint32 *ap)
	{
		// create arguments using argv[1..argc].
		// Even tho E3 says create an Object, E4 says create an Array so thats what we will do.
		AvmAssert(argc >= 0);
		AvmCore::AllocaAutoPtr _atomv;
		Atom* atomv = (Atom*) VMPI_alloca(core(), _atomv, (argc+1) * sizeof(Atom));
		method->boxArgs(argc, ap, atomv);
		return createArguments(atomv, argc);
	}

	ArrayObject* MethodEnv::createRestHelper(int argc, uint32 *ap)
	{
		// create rest Array using argv[param_count..argc]
		Atom* extra = (Atom*) (method->restOffset + (char*)ap);
		int extra_count = argc > method->param_count ? argc - method->param_count : 0;
		return toplevel()->arrayClass->newarray(extra, extra_count);
	}

#endif // AVMPLUS_MIR || FEATURE_NANOJIT

	Atom MethodEnv::getpropertylate_i(Atom obj, int index) const
	{
		// here we put the case for bind-none, since we know there are no bindings
		// with numeric names.
		if ((obj&7) == kObjectType)
		{
			if (index >= 0)
			{
				// try dynamic lookup on instance.  even if the traits are sealed,
				// we might need to search the prototype chain
				return AvmCore::atomToScriptObject(obj)->getUintProperty(index);
			}
			else
			{
				// negative - we must intern the integer
				return AvmCore::atomToScriptObject(obj)->getAtomProperty(method->core()->internInt(index)->atom());
			}
		}
		else
		{
			// primitive types are not dynamic, so we can go directly
			// to their __proto__ object
			AvmCore* core = method->core();
			Toplevel *toplevel = this->toplevel();
			ScriptObject *protoObject = toplevel->toPrototype(obj);
			return protoObject->ScriptObject::getStringPropertyFromProtoChain(core->internInt(index), protoObject, toplevel->toTraits(obj));			
		}
	}

	Atom MethodEnv::getpropertylate_u(Atom obj, uint32 index) const
	{
		// here we put the case for bind-none, since we know there are no bindings
		// with numeric names.
		if ((obj&7) == kObjectType)
		{
			// try dynamic lookup on instance.  even if the traits are sealed,
			// we might need to search the prototype chain
			return AvmCore::atomToScriptObject(obj)->getUintProperty(index);
		}
		else
		{
			// primitive types are not dynamic, so we can go directly
			// to their __proto__ object
			AvmCore* core = method->core();
			Toplevel *toplevel = this->toplevel();
			ScriptObject *protoObject = toplevel->toPrototype(obj);
			return protoObject->ScriptObject::getStringPropertyFromProtoChain(core->internUint32(index), protoObject, toplevel->toTraits(obj));			
		}
	}

	ScriptObject* MethodEnv::finddef(const Multiname* multiname) const
	{
		Toplevel* toplevel = vtable->toplevel;

		ScriptEnv* script = getScriptEnv(multiname);
		if (script == (ScriptEnv*)BIND_AMBIGUOUS)
            toplevel->throwReferenceError(kAmbiguousBindingError, multiname);

		if (script == (ScriptEnv*)BIND_NONE)
            toplevel->throwReferenceError(kUndefinedVarError, multiname);

		ScriptObject* global = script->global;
		if (!global)
		{
			global = script->initGlobal();
			Atom argv[1] = { global->atom() };
			script->coerceEnter(0, argv);
		}
		return global;
	}

	ScriptEnv* MethodEnv::getScriptEnv(const Multiname *multiname) const
	{
		ScriptEnv *se = (ScriptEnv*)abcEnv()->domainEnv()->getScriptInit(*multiname);
		if(!se)
		{	
			// check privates
			se = abcEnv()->getPrivateScriptEnv(*multiname);
		}
		return se;
	}

	ScriptObject* MethodEnv::finddefNsset(NamespaceSet* nsset, Stringp name) const
	{
		Multiname m(nsset);
		m.setName(name);
		return finddef(&m);
	}

	ScriptObject* MethodEnv::finddefNs(Namespace* ns, Stringp name) const
	{
		Multiname m(ns, name);
		return finddef(&m);
	}

	ScriptObject* ScriptEnv::initGlobal()
	{
		// object not defined yet.  define it by running the script that exports it
		Traits* traits = vtable->traits;
		vtable->resolveSignatures();

		Toplevel* toplevel = this->toplevel();
		traits->resolveSignatures(toplevel);
		ScriptObject* delegate = toplevel->objectClass->prototype;

		CreateGlobalObjectProc createGlobalObject = traits->getCreateGlobalObjectProc();
		if (createGlobalObject != NULL)
		{
			// special script with native impl object
			return global = (*createGlobalObject)(vtable, delegate);
		}
		else
		{
			// ordinary user script
			return global = method->core()->newObject(vtable, delegate);
		}
	}

    ScriptObject* MethodEnv::op_newobject(Atom* sp, int argc) const
    {
		// pre-size the hashtable since we know how many vars are coming
		VTable* object_vtable = toplevel()->object_vtable;
		AvmCore* core = method->core();

		ScriptObject* o = new (core->GetGC(), object_vtable->getExtraSize()) 
			ScriptObject(object_vtable, toplevel()->objectClass->prototype,
					2*argc+1);

		for (; argc-- > 0; sp -= 2)
		{
			Atom name = sp[-1];
			//verifier should ensure names are String
			//todo have the verifier take care of interning too
			AvmAssert(AvmCore::isString(name));

			o->setAtomProperty(core->internString(name)->atom(), sp[0]);
		}
		return o;
    }



	Atom MethodEnv::nextname(Atom objAtom, int index) const
	{
		if (index <= 0)
			return nullStringAtom;

		switch (objAtom&7)
		{
		case kObjectType:
			return AvmCore::atomToScriptObject(objAtom)->nextName(index);
		case kNamespaceType:
			return AvmCore::atomToNamespace(objAtom)->nextName(method->core(), index);
		default:
			ScriptObject* proto = toplevel()->toPrototype(objAtom);  // cn: types like Number are sealed, but their prototype could have dynamic properties
			return proto ? proto->nextName(index) : undefinedAtom;
		}
	}

	Atom MethodEnv::nextvalue(Atom objAtom, int index) const
	{
		if (index <= 0)
			return undefinedAtom;

		switch (objAtom&7)
		{
		case kObjectType:
			return AvmCore::atomToScriptObject(objAtom)->nextValue(index);
		case kNamespaceType:
			return AvmCore::atomToNamespace(objAtom)->nextValue(index);
		default:
			ScriptObject*  proto = toplevel()->toPrototype(objAtom);
			return (proto ? proto->nextValue(index) : undefinedAtom);
		}
	}

	int MethodEnv::hasnext(Atom objAtom, int index) const
	{
		if (index < 0)
			return 0;

		if (!AvmCore::isNullOrUndefined(objAtom))
		{
			switch (objAtom&7)
			{
			case kObjectType:
				return AvmCore::atomToScriptObject(objAtom)->nextNameIndex(index);
			case kNamespaceType:
				return AvmCore::atomToNamespace(objAtom)->nextNameIndex(index);
			default:
				ScriptObject* proto = toplevel()->toPrototype(objAtom);
				int nextIndex = ( proto ? proto->nextNameIndex(index) : 0);
				return nextIndex;
			}
		}
		else
		{
			return 0;
		}
	}

	int MethodEnv::hasnextproto(Atom& objAtom, int& index) const
	{
		if (index < 0)
			return 0;

		ScriptObject *delegate = NULL;
		
		if (!AvmCore::isNullOrUndefined(objAtom))
		{
			switch (objAtom&7)
			{
			case kObjectType:
				{
					ScriptObject *object = AvmCore::atomToScriptObject(objAtom);
					delegate = object->getDelegate();
					index = object->nextNameIndex(index);
				}
				break;
			case kNamespaceType:
				{
					index = AvmCore::atomToNamespace(objAtom)->nextNameIndex(index);
					delegate = toplevel()->namespaceClass->prototype;
				}
				break;
			default:
				{
					ScriptObject* proto = toplevel()->toPrototype(objAtom);
					delegate = proto ? proto->getDelegate() : NULL;
					index = ( proto ? proto->nextNameIndex(index) : 0);
				}
			}
		}
		else
		{
			index = 0;
		}

		while (index == 0 && delegate != NULL)
		{
			// Advance to next object on prototype chain
			ScriptObject *object = delegate;
			objAtom = object->atom();
			delegate = object->getDelegate();
			index = object->nextNameIndex(index);
		}

		if (index == 0)
		{
			// If we're done, set object local to null
			objAtom = nullObjectAtom;
		}

		return index != 0;
	}
	
	
#ifdef AVMPLUS_MOPS

	void MethodEnv::mopRangeCheckFailed() const
	{
		toplevel()->throwRangeError(kInvalidRangeError);
	}

	int MethodEnv::li8(int addr) const
	{
		const Domain *dom = domainEnv()->domain();

		if(addr < 0 || (uint32)(addr + 1) > dom->globalMemorySize)
			mopRangeCheckFailed();
		uint8 result = *(uint8 *)(dom->globalMemoryBase + addr);
		return result;
	}

	int MethodEnv::li16(int addr) const
	{
		const Domain *dom = domainEnv()->domain();

		if(addr < 0 || (uint32)(addr + 2) > dom->globalMemorySize)
			mopRangeCheckFailed();

		uint16_t result = *(uint16_t *)(dom->globalMemoryBase + addr);

		MOPS_SWAP_BYTES(&result);

		return result;
	}

	int MethodEnv::li32(int addr) const
	{
		const Domain *dom = domainEnv()->domain();

		if(addr < 0 || (uint32)(addr + 4) > dom->globalMemorySize)
			mopRangeCheckFailed();

		// TODO is using raw "int" type correct?
		int32_t result = *(int32_t *)(dom->globalMemoryBase + addr);

		MOPS_SWAP_BYTES(&result);

		return result;
	}

	double MethodEnv::lf32(int addr) const
	{
		const Domain *dom = domainEnv()->domain();

		if(addr < 0 || (uint32)(addr + 4) > dom->globalMemorySize)
			mopRangeCheckFailed();

		float result = *(float *)(dom->globalMemoryBase + addr);

		MOPS_SWAP_BYTES(&result);

		return result;
	}

	double MethodEnv::lf64(int addr) const
	{
		const Domain *dom = domainEnv()->domain();

		if(addr < 0 || (uint32)(addr + 8) > dom->globalMemorySize)
			mopRangeCheckFailed();

		double result = *(double *)(dom->globalMemoryBase + addr);

		MOPS_SWAP_BYTES(&result);

		return result;
	}

	void MethodEnv::si8(int value, int addr) const
	{
		const Domain *dom = domainEnv()->domain();

		if(addr < 0 || (uint32)(addr + 1) > dom->globalMemorySize)
			mopRangeCheckFailed();

		*(uint8 *)(dom->globalMemoryBase + addr) = (uint8)value;
	}

	void MethodEnv::si16(int value, int addr) const
	{
		const Domain *dom = domainEnv()->domain();

		if(addr < 0 || (uint32)(addr + 2) > dom->globalMemorySize)
			mopRangeCheckFailed();

		uint16 svalue = (uint16)value;

		MOPS_SWAP_BYTES(&svalue);

		*(uint16 *)(dom->globalMemoryBase + addr) = svalue;
	}

	void MethodEnv::si32(int value, int addr) const
	{
		const Domain *dom = domainEnv()->domain();

		if(addr < 0 || (uint32)(addr + 4) > dom->globalMemorySize)
			mopRangeCheckFailed();

		MOPS_SWAP_BYTES(&value);

		*(int *)(dom->globalMemoryBase + addr) = value;
	}

	void MethodEnv::sf32(double value, int addr) const
	{
		const Domain *dom = domainEnv()->domain();

		if(addr < 0 || (uint32)(addr + 4) > dom->globalMemorySize)
			mopRangeCheckFailed();

		float fvalue = (float)value;

		MOPS_SWAP_BYTES(&fvalue);

		*(float *)(dom->globalMemoryBase + addr) = fvalue;
	}

	void MethodEnv::sf64(double value, int addr) const
	{
		const Domain *dom = domainEnv()->domain();

		if(addr < 0 || (uint32)(addr + 8) > dom->globalMemorySize)
			mopRangeCheckFailed();

		MOPS_SWAP_BYTES(&value);

		*(double *)(dom->globalMemoryBase + addr) = value;
	}

#endif // AVMPLUS_MOPS

	// see 13.2 creating function objects
    ClassClosure* MethodEnv::newfunction(AbstractFunction *function,
									 ScopeChain* outer,
									 Atom* scopes) const
    {
		AvmCore* core = this->core();
		AbcEnv* abcEnv = vtable->abcEnv;

		// TODO: if we have already created a function and the scope chain
		// is the same as last time, re-use the old closure?

		// declaringTraits must have been filled in by verifier.
		Traits* ftraits = function->declaringTraits;
		AvmAssert(ftraits != NULL);
		AvmAssert(ftraits->scope != NULL);

		ScopeChain* scope = ScopeChain::create(core->GetGC(), ftraits->scope, outer, *core->dxnsAddr);

		for (int i=outer->getSize(), n=scope->getSize(); i < n; i++)
		{
			scope->setScope(i, *scopes++);
		}

		FunctionClass* functionClass = toplevel()->functionClass;

		// the vtable for the new function object
		VTable* fvtable = core->newVTable(ftraits, functionClass->ivtable(), scope, abcEnv, toplevel());
		fvtable->resolveSignatures();
		FunctionEnv *fenv = new (core->GetGC()) FunctionEnv(function, fvtable);
		fvtable->call = fenv;
		fvtable->ivtable = toplevel()->object_vtable;

		ClassClosure* c = new (core->GetGC(), fvtable->getExtraSize()) ClassClosure(fvtable);
		c->setDelegate( functionClass->prototype );

		c->createVanillaPrototype();
		c->prototype->setStringProperty(core->kconstructor, c->atom());
		c->prototype->setStringPropertyIsEnumerable(core->kconstructor, false);

		fenv->closure = c;
		
        return c;
    }

    /**
     * given a classInfo, create a new ClassClosure object and return it on the stack.
     */

	ClassClosure* MethodEnv::newclass(AbstractFunction* cinit,
							ClassClosure *base,
							ScopeChain* outer,
							Atom* scopes) const
    {
		AvmCore* core = this->core();
		// adds clarity to what is usually just global$init()
		SAMPLE_FRAME("[newclass]", core);
		Toplevel* toplevel = this->toplevel();

		Traits* ctraits = cinit->declaringTraits;
		Traits* itraits = ctraits->itraits;

		// finish resolving the base class
		if (!base && itraits->base)
		{
			// class has a base but no base object was provided
			ErrorClass *error = toplevel->typeErrorClass();
			if( error )
				error->throwError(kConvertNullToObjectError);
			else
				toplevel->throwTypeError(kCorruptABCError);
		}

		// have to use local variables for CodeWarrior
		Traits* baseIvtableTraits = base ? base->ivtable()->traits : 0;
		Traits* itraitsBase = itraits->base;
		// make sure the traits of the base vtable matches the base traits
		if (!(base == NULL && itraits->base == NULL || base != NULL && itraitsBase == baseIvtableTraits))
		{
			ErrorClass *error = toplevel->verifyErrorClass();
			if( error )
				error->throwError(kInvalidBaseClassError);
			else
				toplevel->throwTypeError(kCorruptABCError);
		}

		ctraits->resolveSignatures(toplevel);
		itraits->resolveSignatures(toplevel);

		// class scopechain = [..., class]
		ScopeChain* cscope = ScopeChain::create(core->GetGC(), ctraits->scope, outer, *core->dxnsAddr);

		int staticScopesCount = 0;

		int i = outer->getSize();
		for (int n=cscope->getSize()-staticScopesCount; i < n; i++)
		{
			cscope->setScope(i, *scopes++);
		}

		ScopeChain* iscope = ScopeChain::create(core->GetGC(), itraits->scope, cscope, *core->dxnsAddr);

		AbcEnv *abcEnv = vtable->abcEnv;
		VTable* cvtable = core->newVTable(ctraits, toplevel->class_vtable, cscope, abcEnv, toplevel);
		cvtable->resolveSignatures();
		VTable* ivtable = core->newVTable(itraits, base ? base->ivtable() : NULL, iscope, abcEnv, toplevel);
		ivtable->resolveSignatures();
		cvtable->ivtable = ivtable;

		if (itraits == core->traits.object_itraits) {
			// we just defined Object
			toplevel->object_vtable = ivtable;
		}
		else if (itraits == core->traits.class_itraits) {
			// we just defined Class
			toplevel->class_vtable = ivtable;
			cvtable->base = ivtable;
			toplevel->objectClass->vtable->base = ivtable;
		}

		CreateClassClosureProc createClassClosure = cvtable->traits->getCreateClassClosureProc();
		ClassClosure *cc;
		if (createClassClosure != NULL)
		{
			cc = (*createClassClosure)(cvtable);
		}
		else
		{
			cc = new (core->GetGC(), cvtable->getExtraSize()) ClassClosure(cvtable);
			AvmAssert(cc->prototype == NULL);
			cc->createVanillaPrototype();
		}

		if (cc->prototype)
		{
			// C.prototype.__proto__ = Base.prototype
			if (base != NULL) 
				cc->prototype->setDelegate( base->prototype );

			// C.prototype.constructor = C {DontEnum}
			cc->prototype->setStringProperty(core->kconstructor, cc->atom());
			cc->prototype->setStringPropertyIsEnumerable(core->kconstructor, false);
		}

		AvmAssert(i == iscope->getSize()-1);
		iscope->setScope(i, cc->atom());
		if (toplevel->classClass)
		{
			cc->setDelegate( toplevel->classClass->prototype );
		}

		// Invoke the class init function.
		cvtable->init->coerceEnter(cc->atom());
		return cc;
    }

    void MethodEnv::initproperty(Atom obj, const Multiname* multiname, Atom value, VTable* vtable) const
    {
		Toplevel* toplevel = this->toplevel();
		Binding b = toplevel->getBinding(vtable->traits, multiname);
		if (AvmCore::bindingKind(b) == BKIND_CONST)
		{
			if (vtable->init != this)
				toplevel->throwReferenceError(kConstWriteError, multiname, vtable->traits);
			b = AvmCore::makeSlotBinding(AvmCore::bindingToSlotId(b), BKIND_VAR);
		}
		toplevel->setproperty_b(obj, multiname, value, vtable, b);
    }

	void MethodEnv::setpropertylate_i(Atom obj, int index, Atom value) const
	{
		if (AvmCore::isObject(obj))
		{
			ScriptObject* o = AvmCore::atomToScriptObject(obj);
			if (index >= 0)
			{
				o->setUintProperty(index, value);
			}
			else
			{
				// negative index - we must intern the integer
				o->setAtomProperty(method->core()->internInt(index)->atom(), value);
			}
		}
		else
		{
			// obj represents a primitive Number, Boolean, int, or String, and primitives
			// are sealed and final.  Cannot add dynamic vars to them.

			// throw a ReferenceError exception  Property not found and could not be created.
			Multiname tempname(core()->publicNamespace, core()->internInt(index));
			toplevel()->throwReferenceError(kWriteSealedError, &tempname, toplevel()->toTraits(obj));
		}
	}

	void MethodEnv::setpropertylate_u(Atom obj, uint32 index, Atom value) const
	{
		if (AvmCore::isObject(obj))
		{
			AvmCore::atomToScriptObject(obj)->setUintProperty(index, value);
		}
		else
		{
			// obj represents a primitive Number, Boolean, int, or String, and primitives
			// are sealed and final.  Cannot add dynamic vars to them.

			// throw a ReferenceError exception  Property not found and could not be created.
			Multiname tempname(core()->publicNamespace, core()->internUint32(index));
			toplevel()->throwReferenceError(kWriteSealedError, &tempname, toplevel()->toTraits(obj));
		}
	}

	Atom MethodEnv::callsuper(const Multiname* multiname, int argc, Atom* atomv) const
	{
		VTable* base = vtable->base;
		Toplevel* toplevel = this->toplevel();
		Binding b = toplevel->getBinding(base->traits, multiname);
		switch (AvmCore::bindingKind(b))
		{
		default:
			toplevel->throwReferenceError(kCallNotFoundError, multiname, base->traits);

		case BKIND_METHOD:
		{
			#ifdef DEBUG_EARLY_BINDING
			core()->console << "callsuper method " << base->traits << " " << multiname->name << "\n";
			#endif
			MethodEnv* superenv = base->methods[AvmCore::bindingToMethodId(b)];
			return superenv->coerceEnter(argc, atomv);
		}
		case BKIND_VAR:
		case BKIND_CONST:
		{
			#ifdef DEBUG_EARLY_BINDING
			core()->console << "callsuper slot " << base->traits << " " << multiname->name << "\n";
			#endif
			uint32 slot = AvmCore::bindingToSlotId(b);
			Atom method = AvmCore::atomToScriptObject(atomv[0])->getSlotAtom(slot);
			return toplevel->op_call(method, argc, atomv);
		}
		case BKIND_SET:
		{
			#ifdef DEBUG_EARLY_BINDING
			core()->console << "callsuper setter " << base->traits << " " << multiname->name << "\n";
			#endif
			// read on write-only property
			toplevel->throwReferenceError(kWriteOnlyError, multiname, base->traits);
		}
		case BKIND_GET:
		case BKIND_GETSET:
		{
			#ifdef DEBUG_EARLY_BINDING
			core()->console << "callsuper getter " << base->traits << " " << multiname->name << "\n";
			#endif
			// Invoke the getter
			int m = AvmCore::bindingToGetterId(b);
			MethodEnv *f = base->methods[m];
			Atom atomv_out[1] = { atomv[0] };
			Atom method = f->coerceEnter(0, atomv_out);
			return toplevel->op_call(method, argc, atomv);
		}
		}
	}

	Atom MethodEnv::delproperty(Atom obj, const Multiname* multiname) const
	{
		Toplevel* toplevel = this->toplevel();
		Traits* traits = toplevel->toTraits(obj); // includes null check
		if (AvmCore::isObject(obj))
		{
			Binding b = toplevel->getBinding(traits, multiname);
			if (b == BIND_NONE) 
			{
				bool b = AvmCore::atomToScriptObject(obj)->deleteMultinameProperty(multiname);
#ifdef AVMPLUS_WORD_CODE
				// Deleting a deletable bound property means deleting a dynamic global property, so
				// invalidate the lookup cache (because subsequent lookups should fail).
				if (b)
					core()->invalidateLookupCache();
#endif
				return b ? trueAtom : falseAtom;
			}
			else if (AvmCore::isMethodBinding(b))
			{
				if (multiname->contains(core()->publicNamespace) && toplevel->isXmlBase(obj))
				{
					// dynamic props should hide declared methods on delete
					ScriptObject* so = AvmCore::atomToScriptObject(obj);
					bool b = so->deleteMultinameProperty(multiname);
					return b ? trueAtom : falseAtom;
				}
			}
		}
		else
		{
			toplevel->throwReferenceError(kDeleteSealedError, multiname, traits);
		}

		return falseAtom;
	}
	
    Atom MethodEnv::getsuper(Atom obj, const Multiname* multiname) const
    {
		VTable* vtable = this->vtable->base;
		Toplevel* toplevel = this->toplevel();
		Binding b = toplevel->getBinding(vtable->traits, multiname);
        switch (AvmCore::bindingKind(b))
        {
		default:
			toplevel->throwReferenceError(kReadSealedError, multiname, vtable->traits);

		case BKIND_METHOD: 
		{
			#ifdef DEBUG_EARLY_BINDING
			core->console << "getsuper method " << vtable->traits << " " << multiname->name << "\n";
			#endif
			// extracting a virtual method
			MethodEnv *m = vtable->methods[AvmCore::bindingToMethodId(b)];
			return toplevel->methodClosureClass->create(m, obj)->atom();
		}

        case BKIND_VAR:
        case BKIND_CONST:
			#ifdef DEBUG_EARLY_BINDING
			core->console << "getsuper slot " << vtable->traits << " " << multiname->name << "\n";
			#endif
			return AvmCore::atomToScriptObject(obj)->getSlotAtom(AvmCore::bindingToSlotId(b));

		case BKIND_SET:
		{
			#ifdef DEBUG_EARLY_BINDING
			core->console << "getsuper setter " << vtable->traits << " " << multiname->name << "\n";
			#endif
			// read on write-only property
			toplevel->throwReferenceError(kWriteOnlyError, multiname, vtable->traits);
		}
		case BKIND_GET:
		case BKIND_GETSET:
		{
			#ifdef DEBUG_EARLY_BINDING
			core->console << "getsuper getter " << vtable->traits << " " << multiname->name << "\n";
			#endif
			// Invoke the getter
			int m = AvmCore::bindingToGetterId(b);
			MethodEnv *f = vtable->methods[m];
			Atom atomv_out[1] = { obj };
			return f->coerceEnter(0, atomv_out);
		}
		}
    }

	
    void MethodEnv::setsuper(Atom obj, const Multiname* multiname, Atom value) const
    {
		VTable* vtable = this->vtable->base;
		Toplevel* toplevel = this->toplevel();
		Binding b = toplevel->getBinding(vtable->traits, multiname);
        switch (AvmCore::bindingKind(b))
        {
		default:
			toplevel->throwReferenceError(kWriteSealedError, multiname, vtable->traits);

		case BKIND_CONST:
			toplevel->throwReferenceError(kConstWriteError, multiname, vtable->traits);

		case BKIND_METHOD: 
			toplevel->throwReferenceError(kCannotAssignToMethodError, multiname, vtable->traits);

		case BKIND_GET: 
			#ifdef DEBUG_EARLY_BINDING
			core()->console << "setsuper getter " << vtable->traits << " " << multiname->name << "\n";
			#endif
			toplevel->throwReferenceError(kConstWriteError, multiname, vtable->traits);

		case BKIND_VAR:
			#ifdef DEBUG_EARLY_BINDING
			core()->console << "setsuper slot " << vtable->traits << " " << multiname->name << "\n";
			#endif
			AvmCore::atomToScriptObject(obj)->setSlotAtom(AvmCore::bindingToSlotId(b), value);
            return;

		case BKIND_SET: 
		case BKIND_GETSET: 
		{
			#ifdef DEBUG_EARLY_BINDING
			core()->console << "setsuper setter " << vtable->traits << " " << multiname->name << "\n";
			#endif
			// Invoke the setter
			uint32 m = AvmCore::bindingToSetterId(b);
			AvmAssert(m < vtable->traits->getTraitsBindings()->methodCount);
			MethodEnv* method = vtable->methods[m];
			Atom atomv_out[2] = { obj, value };
			// coerce value to proper type, then call enter
			method->coerceEnter(1, atomv_out);
			return;
		}
        }
    }

	Atom MethodEnv::findWithProperty(Atom atom, const Multiname* multiname)
	{
		Toplevel* toplevel = this->toplevel();
		if ((atom&7)==kObjectType)
		{
			// usually scope objects are ScriptObject's

			ScriptObject* o = AvmCore::atomToScriptObject(atom);

			// search the delegate chain for a value.  we must look at
			// traits at each step along the way in case we have class
			// instances on the scope chain
			do
			{
				// ISSUE it is incorrect to return a reference to an object on the prototype
				// chain, we should only return the scopechain object; the next operation
				// could be a setproperty, and we don't want to mutate prototype objects this way.

				// look at the traits first, stop if found.
				Binding b = toplevel->getBinding(o->traits(), multiname);
				if (b != BIND_NONE)
					return atom;
				if (o->hasMultinameProperty(multiname))
					return atom;
			}
			while ((o = o->getDelegate()) != NULL);
		}
		else
		{
			// primitive value on scope chain!

			// first iteration looks at traits only since primitive values don't have
			// dynamic variables

			Binding b = toplevel->getBinding(toplevel->toTraits(atom), multiname);
			if (b != BIND_NONE)
				return atom;

			// then we continue starting at the prototype for this primitive type
			ScriptObject* o = toplevel->toPrototype(atom);
			do
			{
				Binding b = toplevel->getBinding(o->traits(), multiname);
				if (b != BIND_NONE)
					return atom;
				if (o->hasMultinameProperty(multiname))
					return atom;
			}
			while ((o = o->getDelegate()) != NULL);
		}

		return nullObjectAtom;
	}

	/**
	 * return the object on the scope chain that owns the given property.
	 * if no object has that property, return scope[0].  we search each
	 * delegate chain but only return objects that are on the scope chain.
	 * this way, find+get and find+set are both correct.  find+set should
	 * not mutate a prototype object.
	 */
	Atom MethodEnv::findproperty(ScopeChain* outer,
								 Atom* scopes,
								 int extraScopes,
								 const Multiname* multiname,
								 bool strict,
								 Atom* withBase)
    {
		Toplevel* toplevel = this->toplevel();

		// look in each with frame in the current stack frame
		Atom* scopep = &scopes[extraScopes-1];
		if (withBase)
		{
			for (; scopep >= withBase; scopep--)
			{
				Atom result = findWithProperty(*scopep, multiname);
				if (!AvmCore::isNull(result))
				{
					return result;
				}
			}
		}

		// if we're in global$init (outer_depth==0), don't check "this" scope just yet.
		int outer_depth = outer->getSize();
		for (; scopep > scopes; scopep--)
		{
			Atom a = *scopep;
			Traits* t = toplevel->toTraits(a);
			Binding b = toplevel->getBinding(t, multiname);
			if (b != BIND_NONE)
				return a;
		}

		ScopeTypeChain* outerTraits = outer->scopeTraits;

		if (outer_depth > 0 && scopep >= scopes)
		{
			// consider "this" scope now, but constrain it to the declaringTraits of
			// the current method (verifier ensures this is safe)
			Atom a = *scopep;
			Traits *t;
			if (outerTraits->fullsize > outerTraits->size)
			{
				// scope traits has extra constraint for "this" scope, see OP_newclass in verifier
				t = outerTraits->getScopeTraitsAt(outerTraits->size);
			}
			else
			{
				// "this" scope type is the runtime type
				t = toplevel->toTraits(a);
			}

			Binding b = toplevel->getBinding(t, multiname);
			if (b != BIND_NONE)
				return a;
		}

		// now search outer scopes
		for (int i=outer_depth-1; i > 0; i--)
		{
			if (outerTraits->getScopeIsWithAt(i))
			{
				Atom result = findWithProperty(outer->getScope(i), multiname);
				if (!AvmCore::isNull(result))
					return result;
			}
			else
			{
				// only look at the properties on the captured (verify time) type, not the actual type,
				// of the outer scope object.
				Atom a = outer->getScope(i);
				Traits* t = outerTraits->getScopeTraitsAt(i);
				Binding b = toplevel->getBinding(t, multiname);
				if (b != BIND_NONE)
					return a;
			}
		}

		// No imported definitions or global scope can have attributes.  (Using filter
		// operator with non existent attribute will get here. 
		if (multiname->isAttr())
		{
			if (strict)
				toplevel->throwReferenceError(kUndefinedVarError, multiname);
			return undefinedAtom;
		}

		// now we have searched all the scopes, except global
		{
			ScriptObject* global = AvmCore::atomToScriptObject(outer->getSize() > 0 ? outer->getScope(0) : *scopes);
			ScriptObject* obj = findglobalproperty(global, multiname);
			if (obj == NULL) {
				if (strict)
					toplevel->throwReferenceError(kUndefinedVarError, multiname);
				obj = global;
			}
			return obj->atom();
		}
	}
	
	ScriptObject* MethodEnv::findglobalproperty(ScriptObject* target_global, const Multiname* multiname)
	{
		Toplevel* toplevel = this->toplevel();
		
		// look for imported definition (similar logic to OP_finddef).  This will
		// find definitions in this script and in other scripts.
		ScriptEnv* script = getScriptEnv(multiname);
		if (script != (ScriptEnv*)BIND_NONE)
		{
			if (script == (ScriptEnv*)BIND_AMBIGUOUS)
				toplevel->throwReferenceError(kAmbiguousBindingError, multiname);

			ScriptObject* global = script->global;
			if (global == NULL)
			{
				global = script->initGlobal();
				Atom argv[1] = { script->global->atom() };
				script->coerceEnter(0, argv);
			}
			return global;
		}

		// no imported definition found.  look for dynamic props
		// on the global object

		ScriptObject* global = target_global;

		// search the delegate chain for a value.  The delegate
		// chain for the global object will only contain vanilla
		// objects (Object.prototype) so we can skip traits

		ScriptObject* o = global;
		do
		{
			if (o->hasMultinameProperty(multiname))
				return global;
		}
		while ((o = o->getDelegate()) != NULL);

		return NULL;
    }

	Namespace* MethodEnv::internRtns(Atom nsAtom)
	{
		if (((nsAtom&7) != kNamespaceType) || AvmCore::isNull(nsAtom))
			toplevel()->throwTypeError(kIllegalNamespaceError);
		return core()->internNamespace(AvmCore::atomToNamespace(nsAtom));
	}

	ArrayObject* MethodEnv::createArguments(Atom *atomv, int argc)
	{
		Toplevel* toplevel = this->toplevel();
		ArrayObject *arguments = toplevel->arrayClass->newarray(atomv+1,argc);
		ScriptObject *closure;
		if (method->flags & AbstractFunction::NEED_CLOSURE)
		{
			closure = toplevel->methodClosureClass->create(this, atomv[0]);
		}
		else
		{
			closure = ((FunctionEnv*)this)->closure;
		}
		arguments->setStringProperty(core()->kcallee, closure->atom());
		arguments->setStringPropertyIsEnumerable(core()->kcallee, false);
		return arguments;
	}

	Atom MethodEnv::getdescendants(Atom obj, const Multiname* multiname)
	{
		if (AvmCore::isObject (obj))
		{
			return core()->atomToScriptObject(obj)->getDescendants (multiname);
		}
		else
		{
			// Rhino simply returns undefined for other Atom types
			// SpiderMonkey throws TypeError.  We're doing TypeError.
			toplevel()->throwTypeError(kDescendentsError, core()->toErrorString(toplevel()->toTraits(obj)));
			return undefinedAtom; // not reached
		}
	}

	Atom MethodEnv::getdescendantslate(Atom obj, Atom index, bool attr)
	{
		if (AvmCore::isObject(index))
		{
			ScriptObject* i = AvmCore::atomToScriptObject(index);
			if (i->traits() == core()->traits.qName_itraits)
			{
				QNameObject* qname = (QNameObject*) i;
				Multiname n2;
				qname->getMultiname(n2);
				if (attr)
					n2.setAttr(attr);
				return getdescendants(obj, &n2);
			}
		}

		// convert index to string

		AvmCore* core = this->core();
		Multiname name(core->publicNamespace, core->intern(index));
		if (attr)
			name.setAttr();
		return getdescendants(obj, &name);
	}

	void MethodEnv::checkfilter(Atom obj)
	{
		if ( !toplevel()->isXmlBase(obj) )
		{
			toplevel()->throwTypeError(kFilterError, core()->toErrorString(toplevel()->toTraits(obj)));
		}
	}

		
	/**
	 * implements ECMA implicit coersion.  returns the coerced value,
	 * or throws a TypeError if coersion is not possible.
	 */
    ScriptObject* MethodEnv::coerceAtom2SO(Atom atom, Traits* expected) const
    {
		AvmAssert(expected != NULL);
		AvmAssert(!expected->isMachineType());
		AvmAssert(expected != core()->traits.string_itraits);
		AvmAssert(expected != core()->traits.namespace_itraits);

		if (AvmCore::isNullOrUndefined(atom))
			return NULL;

		if ((atom&7) == kObjectType)
		{
			ScriptObject* so = AvmCore::atomToScriptObject(atom);
			if (so->traits()->containsInterface(expected))
			{
				return so;
			}
		}

		// failed
#ifdef AVMPLUS_VERBOSE
		//core->console << "checktype failed " << expected << " <- " << atom << "\n";
#endif
		toplevel()->throwTypeError(kCheckTypeFailedError, core()->atomToErrorString(atom), core()->toErrorString(expected));
		return NULL;
    }

	VTable *MethodEnv::getActivation()
	{
		int type = getType();
		switch(type)
		{
		case kActivation:
			return (VTable *)(activationOrMCTable&~7);
		case kActivationMethodTablePair:
			return getPair()->activation;
		default:
			return NULL;
		}
	}

    ScriptObject *MethodEnv::newActivation()
    {
        VTable *vtable = getActivation();
		AvmCore *core = this->core();
        MMgc::GC *gc = core->GetGC();
		SAMPLE_FRAME("[activation-object]", core);
		ScriptObject* obj = new (gc, vtable->getExtraSize()) ScriptObject(vtable, 0/*delegate*/);
        MethodEnv *init = vtable->init;
        if (init)
			init->coerceEnter(obj->atom());
		return obj;
    }

	WeakKeyHashtable *MethodEnv::getMethodClosureTable()
	{
		int type = getType();
		if(!activationOrMCTable)
		{
			WeakKeyHashtable *wkh = new (core()->GetGC()) WeakKeyHashtable(core()->GetGC());			
			setActivationOrMCTable(wkh, kMethodTable);
			return wkh;
		}
		else if(type == kActivation)
		{
			WeakKeyHashtable *wkh = new (core()->GetGC()) WeakKeyHashtable(core()->GetGC());
			ActivationMethodTablePair *amtp = new (core()->GetGC()) ActivationMethodTablePair(getActivation(), wkh);					
			setActivationOrMCTable(amtp, kActivationMethodTablePair);
			return wkh;
		}
		else if(type == kActivationMethodTablePair)
		{
			return getPair()->methodTable;
		}
		return (WeakKeyHashtable*)(activationOrMCTable&~7);
	}
}
