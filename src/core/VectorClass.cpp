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
#include "BuiltinNatives.h"

using namespace MMgc;

namespace avmplus
{
	bool VectorBaseObject::hasAtomProperty(Atom name) const
	{
		uint32 index;
		bool isNumber=false;
		if (getVectorIndex(name, index, isNumber))
		{
			return index < m_length;
		}
		else
		{
			if(isNumber)
			{
				return false;
			}
			return ScriptObject::hasAtomProperty(name);
		}
	}
	
	// helper method
	// sets index to the uint32 value of name, if it can be converted
	// isNumber is set to true if name was a number (whether it was a uint32 value or not)
	bool VectorBaseObject::getVectorIndex(Atom name, uint32& index, bool& isNumber) const
	{
		AvmCore* core = this->core();
		isNumber = false;
		if (core->getIndexFromAtom(name, &index))
		{
			isNumber = true;
			return true;
		}
		else
		{
			if( AvmCore::isString(name) )
			{
				Stringp s = core->string(name);
				const wchar *c = s->c_str();
				// Does it look like a number?
				if( s->length() > 0 && *c >= '0' && *c <= '9' )
				{
					double index_d = s->toNumber();
					if( !MathUtils::isNaN(index_d) )
					{
						isNumber = true;

						// name is a string that looks like a number
						int i = MathUtils::real2int(index_d);
						if ((double)i == index_d)
						{
							// It's an indexed property name
							index = i;
							return true;
						}
						else
						{
							return false;
						}
					}
				}
			}
		}
		return false;
	}

	void VectorBaseObject::setAtomProperty(Atom name, Atom value)
	{
		uint32 index;
		bool isNumber=false;
		if (getVectorIndex(name, index, isNumber))
		{
			setUintProperty(index, value);
		}
		else
		{
			Multiname mn(core()->publicNamespace,core()->string(name));
			// Vector is sorta sealed, can only write to "indexed" properties
			toplevel()->throwReferenceError(kWriteSealedError, &mn, traits());
		}
	}
	
	Atom VectorBaseObject::getAtomProperty(Atom name) const
	{
		uint32 index;
		bool isNumber=false;
		AvmCore* core = this->core();
		if (getVectorIndex(name, index, isNumber))
		{
			return getUintProperty(index);
		}
		else
		{
			if(isNumber)
			{
				// Not a valid indexed name - has a decimal part
				Multiname mn(core->publicNamespace,core->string(name));
				toplevel()->throwReferenceError(kReadSealedError, &mn, traits());
			}
			// Check the prototype chain - that will throw if there is no match
			return getAtomPropertyFromProtoChain(name, getDelegate(), traits());
		}
	}

	uint32 VectorBaseObject::get_length()
	{
		return m_length;
	}
	
	void VectorBaseObject::set_length(uint32 newLength)
	{
		if( m_fixed )
			toplevel()->throwRangeError(kVectorFixedError); 
		if (newLength > m_capacity)
		{
			grow(newLength, true);
		}
		m_length = newLength;
	}

	bool VectorBaseObject::get_fixed()
	{
		return m_fixed;
	}

	void VectorBaseObject::set_fixed(bool fixed)
	{
		m_fixed = fixed;
	}

	// Iterator support - for in, for each
	Atom VectorBaseObject::nextName(int index)
	{
		AvmAssert(index > 0);
		if (((uint32)index) <= m_length)
		{
			AvmCore *core = this->core();
			return core->intToAtom(index-1);
		}
		else
		{
			return nullStringAtom;
		}
	}
	Atom VectorBaseObject::nextValue(int index)
	{
		AvmAssert(index > 0);
		if (((uint32)index) <= m_length)
		{
			return getUintProperty(index-1);
		}
		else
		{
			return undefinedAtom;
		}
	}
	int VectorBaseObject::nextNameIndex(int index)
	{
		if (((uint32)index) < m_length)
		{
			return index + 1;
		}
		else
		{
			return 0;
		}
	}

	Atom VectorBaseObject::map (ScriptObject *callback, Atom thisObject)
	{
		AvmCore* core = this->core();
		VectorBaseObject *r = newVector(m_length);

		if (!callback)
			return r->atom();

		ScriptObject *d = this;
		uint32 len = m_length;

		// If thisObject is null, the call function will substitute the global object 
		Atom args[4] = { thisObject, nullObjectAtom, nullObjectAtom, this->atom() };

		for (uint32 i = 0; i < len; i++)
		{
			args[1] = d->getUintProperty (i); // element
			args[2] = core->uintToAtom (i); // index

			Atom result = callback->call(3, args);

			r->setUintProperty (i, result);
		}

		return r->atom();
	}

	Atom VectorBaseObject::filter(ScriptObject *callback, Atom thisObject)
	{
		AvmCore* core = this->core();
		VectorBaseObject *r = newVector();

		if (!callback)
			return r->atom();

		ScriptObject *d = this;
		uint32 len = m_length;

		// If thisObject is null, the call function will substitute the global object 
		Atom args[4] = { thisObject, nullObjectAtom, nullObjectAtom, this->atom() };

		for (uint32 i = 0, k = 0; i < len; i++)
		{
			args[1] = d->getUintProperty (i); // element
			args[2] = core->uintToAtom (i); // index

			Atom result = callback->call(3, args);

			if (result == trueAtom)
			{
				r->setUintProperty (k++, args[1]);
			}
		}

		return r->atom();
	}

	uint32 VectorBaseObject::AS3_push(Atom *argv, int argc)
	{
		if( m_fixed )
			toplevel()->throwRangeError(kVectorFixedError);
		grow(m_length + argc);
		for (int i=0; i < argc; i++) {
			setUintProperty(m_length, argv[i]);
		}
		return m_length;
	}

	//
	// IntVectorClass
	//

	IntVectorClass::IntVectorClass(VTable *vtable)
		: ClassClosure(vtable)
    {
		toplevel()->intVectorClass = this;
        prototype = toplevel()->objectClass->construct();
	}

	ScriptObject* IntVectorClass::createInstance(VTable *ivtable,
												 ScriptObject *prototype)
    {
        return new (core()->GetGC(), ivtable->getExtraSize()) IntVectorObject(ivtable, prototype);
    }

	Atom IntVectorClass::call(int argc, Atom* argv) 
	{
		if (argc != 1)
		{
			toplevel()->throwArgumentError(kCoerceArgumentCountError, toplevel()->core()->toErrorString(argc));
		}
		if( core()->istype(argv[1], ivtable()->traits ) )
			return argv[1];

		IntVectorObject* v = (IntVectorObject*)createInstance(ivtable(), prototype);

		v->initWithObj(argv[1]);

		return v->atom();
	}

	IntVectorObject* IntVectorClass::newVector(uint32 length)
	{
		VTable* ivtable = this->ivtable();
		IntVectorObject *v = new (core()->GetGC(), ivtable->getExtraSize()) 
			IntVectorObject(ivtable, prototype);
		v->set_length(length);
		return v;
	}


	VectorBaseObject* IntVectorObject::newVector(uint32 length)
	{
		return toplevel()->intVectorClass->newVector(length);
	}

	//
	// UIntVectorClass
	//

	UIntVectorClass::UIntVectorClass(VTable *vtable)
		: ClassClosure(vtable)
    {
		toplevel()->uintVectorClass = this;
        prototype = toplevel()->objectClass->construct();
	}

	ScriptObject* UIntVectorClass::createInstance(VTable *ivtable,
												 ScriptObject *prototype)
    {
        return new (core()->GetGC(), ivtable->getExtraSize()) UIntVectorObject(ivtable, prototype);
    }

	Atom UIntVectorClass::call(int argc, Atom* argv) 
	{
		if (argc != 1)
		{
			toplevel()->throwArgumentError(kCoerceArgumentCountError, toplevel()->core()->toErrorString(argc));
		}

		if( core()->istype(argv[1], ivtable()->traits ) )
			return argv[1];

		UIntVectorObject* v = (UIntVectorObject*)createInstance(ivtable(), prototype);

		v->initWithObj(argv[1]);

		return v->atom();
	}

	UIntVectorObject* UIntVectorClass::newVector(uint32 length)
	{
		VTable* ivtable = this->ivtable();
		UIntVectorObject *v = new (core()->GetGC(), ivtable->getExtraSize()) 
			UIntVectorObject(ivtable, prototype);
		v->set_length(length);
		return v;
	}

	VectorBaseObject* UIntVectorObject::newVector(uint32 length)
	{
		return toplevel()->uintVectorClass->newVector(length);
	}

	//
	// DoubleVectorClass
	//

	DoubleVectorClass::DoubleVectorClass(VTable *vtable)
		: ClassClosure(vtable)
	{
		toplevel()->doubleVectorClass = this;
        prototype = toplevel()->objectClass->construct();
	}

	ScriptObject* DoubleVectorClass::createInstance(VTable *ivtable,
												   ScriptObject *prototype)
    {
        return new (core()->GetGC(), ivtable->getExtraSize()) DoubleVectorObject(ivtable, prototype);
    }

	Atom DoubleVectorClass::call(int argc, Atom* argv) 
	{
		if (argc != 1)
		{
			toplevel()->throwArgumentError(kCoerceArgumentCountError, toplevel()->core()->toErrorString(argc));
		}

		if( core()->istype(argv[1], ivtable()->traits ) )
			return argv[1];

		DoubleVectorObject* v = (DoubleVectorObject*)createInstance(ivtable(), prototype);

		v->initWithObj(argv[1]);

		return v->atom();
	}

	DoubleVectorObject* DoubleVectorClass::newVector(uint32 length)
	{
		VTable* ivtable = this->ivtable();
		DoubleVectorObject *v = new (core()->GetGC(), ivtable->getExtraSize()) 
			DoubleVectorObject(ivtable, prototype);
		v->set_length(length);
		return v;
	}

	VectorBaseObject* DoubleVectorObject::newVector(uint32 length)
	{
		return toplevel()->doubleVectorClass->newVector(length);
	}

	//
	// VectorClass
	//

	VectorClass::VectorClass(VTable *vtable)
	: ClassClosure(vtable)
	{
		toplevel()->vectorClass = this;
		prototype = toplevel()->objectClass->construct();
		instantiated_types = new (core()->GetGC(), 0)Hashtable(core()->GetGC());
	}

	Atom VectorClass::applyTypeArgs(int argc, Atom* argv)
	{
		//Vector only takes 1 type argument
		AvmAssert(argc==1);
		if( argc != 1 )
		{
			toplevel()->typeErrorClass()->throwError(kWrongTypeArgCountError, traits()->formatClassName(), core()->toErrorString(1), core()->toErrorString(argc));
		}
		Atom type = argv[0];
		Stringp fullname = NULL;
		AvmCore* core = this->core();
		Traits* param_traits = NULL;
		if( ISNULL(type) )
			return toplevel()->objectVectorClass->atom();
		if( (type&7) == kObjectType )
		{
			ScriptObject* so = AvmCore::atomToScriptObject(type);

			if (so == toplevel()->intClass)
				return toplevel()->intVectorClass->atom();
			else if( so == toplevel()->numberClass )
				return toplevel()->doubleVectorClass->atom();
			else if( so == toplevel()->uintClass )
				return toplevel()->uintVectorClass->atom();

			fullname = so->vtable->ivtable->traits->formatClassName();
			param_traits = so->vtable->ivtable->traits;
		}
		fullname = core->intern(core->concatStrings(core->kVector, core->concatStrings(fullname, core->newString(">")))->atom());

		if( !instantiated_types->contains(fullname->atom()) )
		{
			Traits* vecobj_traits = toplevel()->objectVectorClass->vtable->traits;
			Multiname name;
			name.setName(fullname);
			name.setNamespace(this->traits()->ns);
			Stringp classname = core->internString(core->concatStrings(fullname, core->newString("$")));
			Multiname class_mname;
			class_mname.setName(classname);
			class_mname.setNamespace(this->traits()->ns);

			Traits* itraits = traits()->pool->resolveParameterizedType(toplevel(), ivtable()->traits, param_traits);

			Traits* ctraits = traits()->pool->getTraits(class_mname, toplevel());
			if( !ctraits ){
				ctraits = vecobj_traits->newParameterizedCTraits(classname, this->traits()->ns);
			}

			itraits->resolveSignatures(toplevel());
			ctraits->resolveSignatures(toplevel());

			ctraits->itraits = itraits;

			VTable* objVecVTable = toplevel()->objectVectorClass->vtable;
			VTable* objVecIVTable = toplevel()->objectVectorClass->ivtable();

			// Create vtables for the new parameterized type
			VTable* vtab = core->newVTable(ctraits, toplevel()->class_vtable, objVecVTable->scope, objVecVTable->abcEnv, objVecVTable->toplevel); 
			VTable* ivtab = core->newVTable(itraits, objVecIVTable, objVecIVTable->scope, objVecIVTable->abcEnv, objVecIVTable->toplevel);
			vtab->ivtable = ivtab;
			ivtab->init = objVecIVTable->init;
			vtab->resolveSignatures();
			ivtab->resolveSignatures();

			ObjectVectorClass* new_type = new (vtab->gc(), vtab->getExtraSize()) ObjectVectorClass(vtab);
			new_type->index_type = (ClassClosure*)AvmCore::atomToScriptObject(type);
			new_type->setDelegate(toplevel()->classClass->prototype);

			// Is this right?  Should each instantiation get its own prototype?
			new_type->prototype = toplevel()->objectVectorClass->prototype;
			instantiated_types->add(fullname->atom(), new_type->atom());
		}
		return (Atom)instantiated_types->get(fullname->atom());
	}


	ScriptObject* VectorClass::createInstance(VTable * /*ivtable*/,
		ScriptObject * /*prototype*/)
	{
		toplevel()->throwTypeError(kConstructOfNonFunctionError);
		return 0;
	}

	Atom ObjectVectorClass::call(int argc, Atom* argv) 
	{
		if (argc != 1)
		{
			toplevel()->throwArgumentError(kCoerceArgumentCountError, toplevel()->core()->toErrorString(argc));
		}

		if( core()->istype(argv[1], ivtable()->traits ) )
			return argv[1];

		ObjectVectorObject* v = (ObjectVectorObject*)createInstance(ivtable(), prototype);

		v->initWithObj(argv[1]);

		return v->atom();
	}

	ObjectVectorObject* VectorClass::newVector(ClassClosure* type, uint32 length)
	{
		Atom args[1] = {type->atom()};

		ObjectVectorClass* vecclass = (ObjectVectorClass*)AvmCore::atomToScriptObject(applyTypeArgs(1, args));
		return vecclass->newVector(length);
	}

	//
	// ObjectVectorClass
	//

	ObjectVectorClass::ObjectVectorClass(VTable *vtable)
		: ClassClosure(vtable)
    {
		if( !toplevel()->objectVectorClass )
			toplevel()->objectVectorClass = this;
        prototype = toplevel()->objectClass->construct();
	}

	ScriptObject* ObjectVectorClass::createInstance(VTable *ivtable,
												   ScriptObject *prototype)
    {
		ObjectVectorObject* v = new (core()->GetGC(), ivtable->getExtraSize()) ObjectVectorObject(ivtable, prototype);
		v->set_type(index_type->atom());
        return v;
    }

	ObjectVectorObject* ObjectVectorClass::newVector(uint32 length)
	{
		VTable* ivtable = this->ivtable();
		ObjectVectorObject *v = new (core()->GetGC(), ivtable->getExtraSize()) 
			ObjectVectorObject(ivtable, prototype);
		v->set_type(this->index_type->atom());
		v->set_length(length);
		return v;
	}

	Atom ObjectVectorObject::getUintProperty(uint32 index) const
	{
		return _getUintProperty(index);
	}
	Atom ObjectVectorObject::_getUintProperty(uint32 index) const
	{
		if (m_length <= index)
		{
			toplevel()->throwRangeError(kOutOfRangeError, core()->uintToString(index), core()->uintToString(m_length));
		}
		else
		{
			return m_array[index];
		}
		return 0;
	}
	
	void ObjectVectorObject::setUintProperty(uint32 index, Atom value)
	{
		return _setUintProperty(index, value);
	}
	void ObjectVectorObject::_setUintProperty(uint32 index, Atom value)
	{
		if (m_length <= index)
		{
			if( index > m_length || m_fixed )
				toplevel()->throwRangeError(kOutOfRangeError, core()->uintToString(index), core()->uintToString(m_length));
			grow(index+1);
			m_length = index+1;
		}
		WBATOM( MMgc::GC::GetGC(m_array), m_array, m_array + index, (t ? toplevel()->coerce(value, t->traits()->itraits) : value));
	}			

	Atom ObjectVectorObject::_getIntProperty(int index) const
	{
		if (index >= 0) 
		{
			if (m_length <= (uint32)index)
			{
				toplevel()->throwRangeError(kOutOfRangeError, core()->uintToString(index), core()->uintToString(m_length));
			}
			else
			{
				return m_array[index];
			}
		}
		else 
			toplevel()->throwRangeError(kOutOfRangeError, core()->intToString(index), core()->uintToString(m_length));
		return 0;
	}

	void ObjectVectorObject::_setIntProperty(int index, Atom value)
	{
		if (index >= 0) 
			_setUintProperty(index, value);
		else 
			toplevel()->throwRangeError(kOutOfRangeError, core()->intToString(index), core()->uintToString(m_length));
	}

	void ObjectVectorObject::set_length(uint32 newLength)
	{
		if (newLength > m_length)
		{
			if( m_fixed )
				toplevel()->throwRangeError(kVectorFixedError);

			grow(newLength, true);
		}
		else if( newLength < m_length)
		{
			if( m_fixed )
				toplevel()->throwRangeError(kVectorFixedError);

			memset(m_array+newLength, 0, (m_length-newLength)*sizeof(Atom));
			//_spliceHelper (newLength, 0, (m_length - newLength), 0, 0);
		}
		m_length = newLength;
	}

	void ObjectVectorObject::set_type(Atom a)
	{
		this->t = (ClassClosure*)AvmCore::atomToScriptObject(a);
	}

	Atom ObjectVectorObject::get_type()
	{
		return t->atom();
	}

	void ObjectVectorObject::grow(uint32 newCapacity, bool exact)
	{
		if (newCapacity > m_capacity)
		{
			if(!exact)
				newCapacity = newCapacity + (newCapacity >>2);
			//newCapacity = ((newCapacity+kGrowthIncr)/kGrowthIncr)*kGrowthIncr;
			GC* gc = GC::GetGC(this);
			Atom* newArray = (Atom*) gc->Calloc(newCapacity, sizeof(Atom), GC::kContainsPointers|GC::kZero);
			Atom* oldAtoms = m_array;
			if (!newArray)
			{
				toplevel()->throwError(kOutOfMemoryError);
			}
			if (m_array)
			{
				memcpy(newArray, m_array, m_length * sizeof(Atom));
				memset(oldAtoms, 0, m_length*sizeof(Atom));
				gc->Free(oldAtoms);
			}
			m_array = newArray;
			m_capacity = newCapacity;
		}
	}

	VectorBaseObject* ObjectVectorObject::newVector(uint32 length)
	{
		return toplevel()->vectorClass->newVector(t, length);
	}

	void ObjectVectorObject::_spliceHelper(uint32 insertPoint, uint32 insertCount, uint32 deleteCount, Atom args, int offset)
	{
		long l_shiftAmount = (long)insertCount - (long) deleteCount; // long because result could be negative

		grow(m_length + l_shiftAmount);

		Atom *arr = m_array;

		ScriptObject* so_args = (args&7)==kObjectType ?  AvmCore::atomToScriptObject(args) : 0;
		ObjectVectorObject* vec_args = isVector(args);

		if (l_shiftAmount < 0) 
		{
			int numberBeingDeleted = -l_shiftAmount;

			// shift elements down
			int toMove = m_length - insertPoint - deleteCount;
			memmove (arr + insertPoint + insertCount, arr + insertPoint + deleteCount, toMove * sizeof(Atom));

			memset (arr + m_length - numberBeingDeleted, 0, numberBeingDeleted * sizeof(Atom));
		}
		else if (l_shiftAmount > 0)
		{
			memmove (arr + insertPoint + l_shiftAmount, arr + insertPoint, (m_length - insertPoint) * sizeof(Atom));
			//clear for gc purposes
			memset (arr + insertPoint, 0, l_shiftAmount * sizeof(Atom));
		}

		set_length(m_length + l_shiftAmount);

		// Add the items to insert
		if (insertCount)
		{
			if( vec_args && (offset+insertCount <= vec_args->m_length) )
			{
				Atom* a = vec_args->m_array;
				for (uint32 i=0; i<insertCount; i++)
				{
					_setUintProperty(insertPoint+i, a[i+offset]);
				}
			}
			else if( so_args )
			{
				for (uint32 i=0; i<insertCount; i++)
				{
					//setUintProperty(insertPoint+i, so_args->getUintProperty(i+offset));
					_setUintProperty(insertPoint+i, so_args->getUintProperty(i+offset));
				}
			}
		}

		return;
	}

	Atom ObjectVectorObject::AS3_pop()
	{
		if(m_fixed)
			toplevel()->throwRangeError(kVectorFixedError);
		if(m_length)
		{
			uint32 l = m_length-1;
			Atom r = m_array[l];
			set_length(m_length-1);
			return r;
		}
		return undefinedAtom;
	}

	uint32 ObjectVectorObject::AS3_unshift(Atom* argv, int argc)
	{
		// shift elements up by argc
		// inserts args into initial spots

		if( argc > 0 )
		{
			if( m_fixed )
				toplevel()->throwRangeError(kVectorFixedError);
			grow (m_length + argc);
			Atom *arr = m_array;
			memmove (arr + argc, arr, m_length * sizeof(Atom));
			// clear moved element for RC purposes
			memset (arr, 0, argc * sizeof(Atom));
			for(int i=0; i<argc; i++) {
				_setUintProperty(i, argv[i]);
			}
			// setUintProperty will up the length
			//m_length += argc;
		}
		return m_length;
	}

}
