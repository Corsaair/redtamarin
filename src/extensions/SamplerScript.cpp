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


// Adobe patent application tracking #P721, entitled Application Profiling, inventors: T. Reilly

#ifdef AVMPLUS_SHELL
#include "avmshell.h"
#else
// player
#include "platformbuild.h"
#include "avmplayer.h"
#endif

using namespace MMgc;

namespace avmplus
{
	TraceClass::TraceClass(VTable *cvtable)
		: ClassClosure(cvtable)
    {
		createVanillaPrototype();
	}

	int TraceClass::getLevel(int target) 
	{
		int lvl = 0 ; /*Debugger::TRACE_OFF;*/
	#ifdef DEBUGGER
		AvmCore *core = this->core();
		if (core->debugger)
		{
			if (target > 1)
				lvl = Debugger::astrace_callback;
			else
				lvl = Debugger::astrace_console;				
		}
	#endif /* DEBUGGER */
		(void)target;
		return lvl;
	}
	
	void TraceClass::setLevel(int lvl, int target)
	{
	#ifdef DEBUGGER
		AvmCore *core = this->core();
		if (core->debugger)
		{
			if (target > 1)
				Debugger::astrace_callback = (Debugger::TraceLevel) lvl;
			else
				Debugger::astrace_console = (Debugger::TraceLevel) lvl;				
		}
	#endif /* DEBUGGER */
		(void)lvl;
		(void)target;
	}

	void TraceClass::setListener(ScriptObject* f)
	{
	#ifdef DEBUGGER
		AvmCore *core = this->core();
		if (core->debugger)
		{
			// Listeners MUST be functions or null
			if ( core->isNullOrUndefined(f->atom()) )
			{
				f = 0;
			}
			else if (!core->istype(f->atom(), core->traits.function_itraits)) 
			{
				toplevel()->argumentErrorClass()->throwError( kInvalidArgumentError, core->toErrorString("Function"));
				return;
			}
			
			//MethodClosure* mc = f->toplevel()->methodClosureClass->create(f->getCallMethodEnv(), f->atom());
			core->debugger->trace_callback = f;
		}
	#endif /* DEBUGGER */
		(void)f;
	}

	ScriptObject* TraceClass::getListener()
	{
		ScriptObject* f = 0;
	#ifdef DEBUGGER
		AvmCore *core = this->core();
		if (core->debugger)
			f = core->debugger->trace_callback;				
	#endif /* DEBUGGER */
		return f;
	}

	using namespace MMgc;

#ifdef FEATURE_SAMPLER

	class SampleIterator : public ScriptObject
	{
	public:
		SampleIterator(Sampler *sampler, SamplerScript *script, VTable *vt) : 
			ScriptObject(vt, NULL),
			sampler(sampler),
			script(script)
		{
			cursor = sampler->getSamples(count);			
		}

		int nextNameIndex(int index) 
		{
			if(count == 0)
			{
				return 0;
			}				
			return index+1;
		}

		Atom nextValue(int i)
		{
			(void) i;
			Sample s;
			sampler->readSample(cursor, s);
			count--;
			ScriptObject *sam = script->makeSample(s);
			if(!sam) {
				count = 0;			
				return undefinedAtom;
		}
			return sam->atom();
		}

		
		Atom nextName(int)
		{
			// they are iterating over the names, bail
			count = 0;
			return undefinedAtom;
		}

	private:
		uint32 count;
		byte *cursor;
		Sampler *sampler;
		DRCWB(SamplerScript*) script;
	};

	class SlotIterator : public ScriptObject
	{
	public:
		SlotIterator(Traits *t, VTable *vtable) : 
			currTraits(t ? t->getTraitsBindings() : NULL),
			ScriptObject(vtable, NULL) {}

		int nextNameIndex(int index)
		{
			while (currTraits != NULL)
			{
				while ((index = currTraits->next(index)) != 0)
				{
						return index;
				}

				currTraits = currTraits->base;
			}

			return 0;
		}

		Atom nextValue(int index)
		{
			Multiname mn(currTraits->nsAt(index), currTraits->keyAt(index), true);
			QNameObject *qname = new (gc(), toplevel()->qnameClass()->ivtable()->getExtraSize())
									QNameObject(toplevel()->qnameClass(), mn);

			return qname->atom();
		}

		Atom nextName(int)
		{
			// they are iterating over the names, bail
			currTraits = NULL;
			return undefinedAtom;
		}

	private:
		DWB(TraitsBindingsp) currTraits;
	};


	SamplerScript::SamplerScript(VTable *vtable, ScriptObject *delegate)
	  : ScriptObject(vtable, delegate), 
	    sampleIteratorVTable(core()->newVTable(Traits::newTraits(vtable->abcEnv->pool(), NULL, sizeof(SampleIterator), 0, TRAITSTYPE_RT),
						   NULL, NULL, NULL, toplevel())),
	    slotIteratorVTable(core()->newVTable(Traits::newTraits(vtable->abcEnv->pool(), NULL, sizeof(SlotIterator), 0, TRAITSTYPE_RT),
						 NULL, NULL, NULL, toplevel()))
	{
		sampleIteratorVTable->traits->resolveSignatures(NULL);
		slotIteratorVTable->traits->resolveSignatures(NULL);
		AvmAssert(traits()->getSizeOfInstance() == sizeof(SamplerScript));
	}

	Atom SamplerScript::getSamples()
	{	
		AvmCore *core = this->core();
		if(!core->sampling() || core->sampler()->sampleCount() == 0)
			return undefinedAtom;
		
		if (!trusted())
			return undefinedAtom;

		Sampler *s = core->sampler();
		ScriptObject *iter = new (gc()) SampleIterator(s, this, sampleIteratorVTable);
		return iter->atom();
	}

	double SamplerScript::getSampleCount()
	{
		Sampler *s = core()->sampler();
		uint32 num;
		s->getSamples(num);
		return (double)num;
	}

	ClassClosure *SamplerScript::getType(Atom typeOrVTable, const void *ptr)
	{
		Toplevel *tl = toplevel();
		AvmCore *core = this->core();

		if((typeOrVTable&7) != 0) {
			// String of Namespace
			if((typeOrVTable&~7) != 0) {
				tl = (Toplevel*)(typeOrVTable&~7);
			}

			if(((Atom) typeOrVTable&7) == kStringType)
				return tl->stringClass;

			if(((Atom) typeOrVTable&7) == kNamespaceType)
				return tl->namespaceClass;
		}
		
		VTable *vtable = (VTable*)typeOrVTable;
		if( vtable && vtable->toplevel )
			tl = vtable->toplevel;

		ScriptObject *obj=NULL;
		if (ptr != NULL ) {
			obj = (ScriptObject*)ptr;	
		}
		
		ClassClosure *type;
		if(obj && core->istype(obj->atom(), CLASS_TYPE))
		{
			type = tl->classClass;
		} 
		else if(obj && core->istype(obj->atom(), FUNCTION_TYPE))
		{
			type = tl->functionClass;
		}
#ifdef DEBUGGER
		else if(obj && obj->traits()->isActivationTraits())
		{
			type = tl->objectClass;
		}
#endif
		else
		{
			// fallback answer
			type = tl->objectClass;
			ScopeChain *sc = vtable->scope;
			
			if(sc && sc->getSize() <= 1) {
				if(sc->getSize() == 1)
					type = tl->classClass;
			} else if(sc) {
				Atom ccAtom = sc->getScope(sc->getSize()-1);
				if(AvmCore::isObject(ccAtom))
				{
					type = (ClassClosure*) AvmCore::atomToScriptObject(ccAtom);
					if(!core->istype(type->atom(), CLASS_TYPE))
					{
						// obj is a ClassClosure
						type = tl->classClass;
					}
				}
			}
		}
#ifdef DEBUGGER
		// If this fires off, Tommy Reilly says: "It basically means we exhausting all efforts to
		// associate an object with some "type" and failed.  You can ignore it.
		AvmAssert(!obj || 
			typeOrVTable < 7 || 
			  (obj->traits()->name && obj->traits()->name->Equals("global")) ||
			(core->istype(obj->atom(), CLASS_TYPE) && type == tl->classClass) ||
			(obj->traits()->isActivationTraits() && type == tl->objectClass) ||
			core->istype(obj->atom(), type->traits()->itraits));
#else
		AvmAssert(!obj || 
			  typeOrVTable < 7 || 
			  (obj->traits()->name && obj->traits()->name->Equals("global")) ||
			  (core->istype(obj->atom(), CLASS_TYPE) && type == tl->classClass) ||
			  core->istype(obj->atom(), type->traits()->itraits));
#endif
		AvmAssert(core->istype(type->atom(), CLASS_TYPE));	
		return type;	
	}

	ScriptObject *SamplerScript::makeSample(Sample sample)
	{
		AvmCore *core = this->core();
		int clsId = NativeID::abcclass_flash_sampler_Sample;
		
		if(sample.sampleType == Sampler::NEW_OBJECT_SAMPLE || sample.sampleType == Sampler::NEW_AUX_SAMPLE)
			clsId = NativeID::abcclass_flash_sampler_NewObjectSample;
		else if(sample.sampleType == Sampler::DELETED_OBJECT_SAMPLE)
			clsId = NativeID::abcclass_flash_sampler_DeleteObjectSample;
		
		SampleClass *cc = (SampleClass*) toplevel()->getBuiltinExtensionClass(clsId);
		SampleObject *sam = (SampleObject*)cc->createInstance(cc->ivtable(), NULL);
		*(double*)((char*)sam + cc->timeOffset) = (double)sample.micros;

		if(sample.sampleType != Sampler::RAW_SAMPLE)
		{
			AvmAssertMsg(sample.id != 0, "Didn't get id!");
			*(double*)((char*)sam + cc->idOffset) = (double)sample.id;
		}

		if(sample.sampleType == Sampler::DELETED_OBJECT_SAMPLE)
		{
			if (cc->sizeOffset > 0)
			*(double*)((char*)sam + cc->sizeOffset) = (double)sample.size;
			return sam;
		}
		
		uint32 num;

		if(sample.stack.depth > 0)
		{
			VTable *stackFrameVT = toplevel()->getBuiltinExtensionClass(NativeID::abcclass_flash_sampler_StackFrame)->vtable->ivtable;		
			ArrayObject *stack = toplevel()->arrayClass->newArray(sample.stack.depth);
			StackTrace::Element *e = (StackTrace::Element*)sample.stack.trace;
			for(uint32 i=0; i < sample.stack.depth; i++, e++)
			{
				ScriptObject *f = core->newObject(stackFrameVT, NULL);
				
				// at every allocation the sample buffer could overflow and the samples could be deleted
				// the StackTrace::Element pointer is a raw pointer into that buffer so we need to check
				// that its still around before dereferencing e
				if(core->sampler()->getSamples(num) == NULL)
					return NULL;
		
				WBRC(gc(), f, ((char*)f + cc->nameOffset), uintptr(e->infoname()));	// NOT e->info()->name() 
				if(e->filename()) {
					WBRC(gc(), f, ((char*)f + cc->fileOffset), e->filename());
					*(uint32*)((char*)f + cc->lineOffset) = e->linenum();
				}
				stack->setUintProperty(i, f->atom());
			}			
			WBRC(gc(), sam, (char*)sam + cc->stackOffset, stack);
		}
		
		if(sample.sampleType == Sampler::RAW_SAMPLE)
			return sam;

		if( sample.sampleType == Sampler::NEW_OBJECT_SAMPLE ) {

			if (sample.ptr != NULL ) {
				((NewObjectSampleObject*)sam)->setRef((AvmPlusScriptableObject*)sample.ptr);
			}
#ifdef DEBUGGER
			ClassClosure *type = getType(sample.typeOrVTable, sample.ptr);
			WBRC(gc(), sam, ((char*)sam + cc->typeOffset), type);
#endif

			((NewObjectSampleObject*)sam)->setSize(sample.alloc_size);
		}
		else if( sample.sampleType == Sampler::NEW_AUX_SAMPLE ) {
			// Set up size... we know these samples won't have weakref or type info 
			((NewObjectSampleObject*)sam)->setSize(sample.alloc_size);
		}
		return sam;
	}


	
	Atom SamplerScript::getMemberNames(Atom o, bool instanceNames)
	{
		if (!trusted())
			return undefinedAtom;

		AvmCore *core = this->core();
		if (AvmCore::isObject(o))
		{
			Traits *t = AvmCore::atomToScriptObject(o)->traits();
			if(core->istype(o, CLASS_TYPE) && instanceNames && t->itraits)
				t = t->itraits;
			return (new (gc()) SlotIterator(t, slotIteratorVTable))->atom();			   
		}
		return undefinedAtom;
	}

	static double _get_size(Atom a)
	{
#ifdef DEBUGGER
		switch(a&7)
		{
		case kDoubleType:
			return 8;
		case kObjectType:
		case kStringType:
		case kNamespaceType:
			AvmPlusScriptableObject *o = (AvmPlusScriptableObject*)(a&~7);
			if(o)
				return (double)o->size();
		}
		return 4;
#else
		(void)a;
		return 0;
#endif
	}

	double SamplerScript::getSize(Atom a)
	{
		return _get_size(a);
	}

	void SamplerScript::startSampling() 
	{ 
		if (!trusted())
			return;

		core()->sampler()->startSampling(); 
	}
	
	void SamplerScript::stopSampling() 
	{ 
		if (!trusted())
			return;
		core()->sampler()->stopSampling(); 
	}

	void SamplerScript::clearSamples() 
	{
		if (!trusted())
			return;
		core()->sampler()->clearSamples();
	}		

	void SamplerScript::pauseSampling() 
	{
		if (!trusted())
			return;
		core()->sampler()->pauseSampling();
	}	

	void SamplerScript::sampleInternalAllocs(bool b)
	{
		if(!trusted())
			return;
		core()->sampler()->sampleInternalAllocs(b);
	}

	void SamplerScript::_setSamplerCallback(ScriptObject *callback)
	{
		if(!trusted())
			return;

		core()->sampler()->setCallback(callback);
	}

	double SamplerScript::_getInvocationCount(Atom a, QNameObject* qname, uint32 type) 
	{
		if (!trusted())
			return -1;
#ifdef DEBUGGER
		AvmCore *core = this->core();
		Multiname multiname;
		if(qname)
			qname->getMultiname(multiname);

		ScriptObject *object = toplevel();
		if(!AvmCore::isObject(a))
		{
			// not sure if this will be true for standalone avmplus
			AvmAssert(core->codeContext() != NULL);
			DomainEnv *domainEnv = core->codeContext()->domainEnv();
			ScriptEnv* script = (ScriptEnv*) domainEnv->getScriptInit(multiname);
			if (script != (ScriptEnv*)BIND_NONE)
			{
				if (script == (ScriptEnv*)BIND_AMBIGUOUS)
					toplevel()->throwReferenceError(kAmbiguousBindingError, &multiname);

				object = script->global;
				if (object == NULL)
				{
					object = script->initGlobal();
					script->coerceEnter(script->global->atom());
				}				
			}
		}
		else
		{
			object = AvmCore::atomToScriptObject(a);

			if(core->istype(a, CLASS_TYPE) && !qname) {
				// return constructor count
				ClassClosure *cc = (ClassClosure*)object;
				if (cc->vtable->init) // Vector related crash here, Tommy says: I didn't think a type could ever not have a constructor but I guess there's no reason it has to.
					return (double)cc->vtable->init->invocationCount;
			}
		}

		if(!object || !qname)			
			return -1;

		VTable *v = object->vtable;
	
	again:

		MethodEnv *env = NULL;
		Binding b = toplevel()->getBinding(v->traits, &multiname);
		switch (AvmCore::bindingKind(b))
		{
		case BKIND_VAR:
		case BKIND_CONST:
		{	
			// only look at slots for first pass, otherwise we're applying instance traits to the Class
			if(v == object->vtable) {
				Atom method = object->getSlotAtom(AvmCore::bindingToSlotId(b));
				if(AvmCore::isObject(method))
				{
					env = AvmCore::atomToScriptObject(method)->getCallMethodEnv();
				}
			}
			break;
		}
		case BKIND_METHOD:
		{
			int m = AvmCore::bindingToMethodId(b);
			env = v->methods[m];
			break;
		}
		case BKIND_GET:
		case BKIND_GETSET:
		case BKIND_SET:
		{	
			if(type == GET && AvmCore::hasGetterBinding(b))
				env = v->methods[AvmCore::bindingToGetterId(b)];
			else if(type == SET && AvmCore::hasSetterBinding(b))
				env = v->methods[AvmCore::bindingToSetterId(b)];
			break;
		}
		case BKIND_NONE:
		{
			Atom method = object->getStringProperty(multiname.getName());
			if(AvmCore::isObject(method))
			{
				env = AvmCore::atomToScriptObject(method)->getCallMethodEnv();
			}
			else if(v->ivtable)
			{
				v = v->ivtable;
				goto again;
			}
		}
		default:
			break;
		}

		if(env)
			return (double)env->invocationCount;
#else
		(void)type;
		(void)qname;
		(void)a;
#endif

		return -1;
	}
  
	bool SamplerScript::isGetterSetter(Atom a, QNameObject *qname)
	{
		if(!AvmCore::isObject(a) || !AvmCore::atomToScriptObject(a))
			toplevel()->throwArgumentError(kInvalidArgumentError, "object");

		ScriptObject *object = AvmCore::atomToScriptObject(a);

		if(!object || !qname)			
			toplevel()->argumentErrorClass()->throwError(kInvalidArgumentError);

		Multiname multiname;
		qname->getMultiname(multiname);

		VTable *v = object->vtable;
	
	again:

		Binding b = toplevel()->getBinding(v->traits, &multiname);
	
		if(b == BIND_NONE && v->ivtable)
		{
			v = v->ivtable;
			goto again;
		}

		return AvmCore::hasSetterBinding(b) || AvmCore::hasGetterBinding(b);
	}

#else

	SamplerScript::SamplerScript(VTable *vtable, ScriptObject *delegate)
	: ScriptObject(vtable, delegate)
	{
	}

	static double _get_size(Atom a)
	{
		(void)a;
		return 0;
	}

#endif // FEATURE_SAMPLER

	
	SampleObject::SampleObject(VTable *vtable, ScriptObject *delegate)
		: ScriptObject(vtable, delegate) 
	{}

	
	NewObjectSampleObject::NewObjectSampleObject(VTable *vtable, ScriptObject *delegate)
		: size(0), SampleObject(vtable, delegate) 
	{}

	Atom NewObjectSampleObject::get_object()
	{
		if(obj) {
			Atom a = obj->toAtom();
			AvmAssert((a&~7) != 0);
			return a;
		}
		return undefinedAtom;
	}

	double NewObjectSampleObject::get_size()
	{
		double s = (double)size;
		if( !size ) {
			Atom a = get_object();
			s = _get_size(a);
		}
		return s;
	}

	SampleClass::SampleClass(VTable *vtable)
		: ClassClosure(vtable)
	{
		createVanillaPrototype();
		TraitsBindingsp t = vtable->ivtable->traits->getTraitsBindings();
		Binding b =  t->findBinding(core()->constantString("time"), core()->publicNamespace);
		AvmAssert(AvmCore::bindingKind(b) == BKIND_CONST);
		timeOffset = t->getSlotOffset(AvmCore::bindingToSlotId(b));

		b = t->findBinding(core()->constantString("stack"), core()->publicNamespace);
		AvmAssert(AvmCore::bindingKind(b) == BKIND_CONST);
		stackOffset = t->getSlotOffset(AvmCore::bindingToSlotId(b));

		b = t->findBinding(core()->constantString("id"), core()->publicNamespace);
		if(b != BIND_NONE)
		{
			AvmAssert(AvmCore::bindingKind(b) == BKIND_CONST);
			idOffset = t->getSlotOffset(AvmCore::bindingToSlotId(b));
		}

		sizeOffset = 0;
		b = t->findBinding(core()->constantString("size"), core()->publicNamespace);
		if(AvmCore::bindingKind(b) == BKIND_CONST)
		{
			sizeOffset = t->getSlotOffset(AvmCore::bindingToSlotId(b));
		}

		t = toplevel()->getBuiltinExtensionClass(NativeID::abcclass_flash_sampler_StackFrame)->vtable->ivtable->traits->getTraitsBindings();

		b =  t->findBinding(core()->constantString("name"), core()->publicNamespace);
		AvmAssert(AvmCore::bindingKind(b) == BKIND_CONST);
		nameOffset = t->getSlotOffset(AvmCore::bindingToSlotId(b));

		b = t->findBinding(core()->constantString("file"), core()->publicNamespace);
		AvmAssert(AvmCore::bindingKind(b) == BKIND_CONST);
		fileOffset = t->getSlotOffset(AvmCore::bindingToSlotId(b));

		b = t->findBinding(core()->constantString("line"), core()->publicNamespace);
		AvmAssert(AvmCore::bindingKind(b) == BKIND_CONST);
		lineOffset = t->getSlotOffset(AvmCore::bindingToSlotId(b));
	}

	ScriptObject *SampleClass::createInstance(VTable *ivtable, ScriptObject* /*delegate*/)
	{
		return new (core()->gc, ivtable->getExtraSize()) SampleObject(ivtable, prototype);
	}

	NewObjectSampleClass::NewObjectSampleClass(VTable *vtable)
		: SampleClass(vtable)
	{		
		TraitsBindingsp t = vtable->ivtable->traits->getTraitsBindings();

		Binding b =  t->findBinding(core()->constantString("type"), core()->publicNamespace);
		AvmAssert(AvmCore::bindingKind(b) == BKIND_CONST);
		typeOffset = t->getSlotOffset(AvmCore::bindingToSlotId(b));
	}
	
	ScriptObject *NewObjectSampleClass::createInstance(VTable *ivtable, ScriptObject* /*delegate*/)
	{
		return new (core()->gc, ivtable->getExtraSize()) NewObjectSampleObject(ivtable, prototype);
	}
}
