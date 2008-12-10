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

namespace avmplus
{
	FunctionClass::FunctionClass(VTable* cvtable)
		: ClassClosure(cvtable)
	{
		Toplevel* toplevel = this->toplevel();

		toplevel->functionClass = this;
		AvmAssert(traits()->getSizeOfInstance() == sizeof(FunctionClass));

		prototype = createEmptyFunction();
		prototype->setDelegate(toplevel->objectClass->prototype);

		//
		// now that Object, Class, and Function are initialized, we
		// can set up Object.prototype.  other classes will init normally.
		// 

		// init Object prototype
		toplevel->objectClass->initPrototype();
	}

	// Function called as constructor ... not supported from user code
	// this = argv[0] (ignored)
	// arg1 = argv[1]
	// argN = argv[argc]
	Atom FunctionClass::construct(int argc, Atom* /*argv*/)
	{
		// ISSUE do we need an exception here?
		// cn: if argc is 0, this is harmless and we have to return an anonymous
		// function that itself if its > 0, then we can't support it

		/*
		from ECMA 327 5.1 Runtime Compilation
		An implementation that does not support global eval() or calling Function as a function or constructor
		SHALL throw an EvalError exception whenever global eval() (ES3 section 15.1.2.1), Function(p1,
		p2, ..., pn, body) (ES3 section 15.3.1.1), or new Function(p1, p2, ..., pn, body) (ES3 section 15.3.2.1) is
		called.
		*/

		if (argc != 0)
		{
			toplevel()->evalErrorClass()->throwError(kFunctionConstructorError);
		}

		return createEmptyFunction()->atom();
	}

	ClassClosure* FunctionClass::createEmptyFunction()
	{
		// invoke AS3 private static function emptyCtor, which returns an empty function.
		TraitsBindingsp t = traits()->getTraitsBindings();
		Binding b = t->findBinding(core()->constantString("emptyCtor"));
		MethodEnv *f = vtable->methods[AvmCore::bindingToMethodId(b)];
		return (ClassClosure*)AvmCore::atomToScriptObject(f->coerceEnter(this->atom()));
	}

	/**
     * Function.prototype.call()
     */
	Atom FunctionObject::AS3_call(Atom thisArg,
							 Atom *argv,
							 int argc)
	{
		if (argc > 0) 
			return call_this_aa(thisArg, argc, argv);
		else
			return call_this(thisArg);
	}

	/**
     * Function.prototype.apply()
     */
	Atom FunctionObject::AS3_apply(Atom thisArg, Atom argArray)
	{
		// when argArray == undefined or null, same as not being there at all
		// see Function/e15_3_4_3_1.as 
	
		if (!AvmCore::isNullOrUndefined(argArray))
		{
			AvmCore* core = this->core();

			if (!core->istype(argArray, ARRAY_TYPE))
				toplevel()->throwTypeError(kApplyError);

			return call_this_a(thisArg, (ArrayObject*)AvmCore::atomToScriptObject(argArray));
			
		}
		else
			return call_this(thisArg);
	}
 
}
