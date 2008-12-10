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


#include "avmshell.h"

namespace avmshell
{
	DomainObject::DomainObject(VTable *vtable, ScriptObject *delegate)
		: ScriptObject(vtable, delegate)
	{
	}

	DomainObject::~DomainObject()
	{
	}

	void DomainObject::init(DomainObject *parentDomain)
	{
		Shell *core = (Shell*) this->core();

		Domain* baseDomain;
		if (parentDomain) {
			baseDomain = parentDomain->domainEnv->domain();
		} else {
			baseDomain = core->builtinDomain;
		}
		
		Domain* domain = new (core->GetGC()) Domain(core, baseDomain);

		if (parentDomain) {
			domainToplevel = parentDomain->domainToplevel;
		} else {
			domainToplevel = core->initShellBuiltins();
		}
		
		domainEnv = new (core->GetGC()) DomainEnv(core, domain, parentDomain->domainEnv);
	}

	Atom DomainObject::loadBytes(ByteArrayObject *b)
	{
		AvmCore* core = this->core();
		if (!b)
			toplevel()->throwTypeError(kNullArgumentError, core->toErrorString("bytes"));

		ShellCodeContext* codeContext = new (core->GetGC()) ShellCodeContext();
		codeContext->m_domainEnv = domainEnv;

		// parse new bytecode
		size_t len = b->get_length();
		ScriptBuffer code = core->newScriptBuffer(len);
		memcpy(code.getBuffer(), &b->GetByteArray()[0], len); 
		Toplevel *toplevel = domainToplevel;
		return core->handleActionBlock(code, 0,
								  domainEnv,
								  toplevel,
								  NULL, codeContext);
	}

	ScriptObject* DomainObject::finddef(const Multiname& multiname,
										DomainEnv* domainEnv)
	{
		Toplevel* toplevel = this->toplevel();

		ScriptEnv* script = (ScriptEnv*) domainEnv->getScriptInit(multiname);
		if (script == (ScriptEnv*)BIND_AMBIGUOUS)
            toplevel->throwReferenceError(kAmbiguousBindingError, multiname);

		if (script == (ScriptEnv*)BIND_NONE)
            toplevel->throwReferenceError(kUndefinedVarError, multiname);

		if (script->global == NULL)
		{
			script->initGlobal();
			Atom argv[1] = { script->global->atom() };
			script->coerceEnter(0, argv);
		}

		return script->global;
	}
	
	ClassClosure* DomainObject::getClass(Stringp name)
	{
		AvmCore *core = this->core();

		if (name == NULL) {
			toplevel()->throwArgumentError(kNullArgumentError, core->toErrorString("name"));
		}
			
		// Search for a dot from the end.
		int dot;
		for (dot=name->length()-1; dot >= 0; dot--)
			if ((*name)[dot] == (wchar)'.')
				break;
		
		// If there is a '.', this is a fully-qualified
		// class name in a package.  Must turn it into
		// a namespace-qualified multiname.
		Namespace* ns;
		Stringp className;
		if (dot != -1) {
			Stringp uri = core->internString(new (core->GetGC()) String(name, 0, dot));
			ns = core->internNamespace(core->newNamespace(uri));
			className = core->internString(new (core->GetGC()) String(name, dot+1, name->length()-(dot+1)));
		} else {
			ns = core->publicNamespace;
			className = core->internString(name);
		}

		Multiname multiname(ns, className);

		ShellCodeContext* codeContext = (ShellCodeContext*)core->codeContext();
		
		ScriptObject *container = finddef(multiname, codeContext->domainEnv());
		if (!container) {
			toplevel()->throwTypeError(kClassNotFoundError, core->toErrorString(&multiname));
		}
		Atom atom = toplevel()->getproperty(container->atom(),
											&multiname,
											container->vtable);

		if (!core->istype(atom, core->traits.class_itraits)) {
			toplevel()->throwTypeError(kClassNotFoundError, core->toErrorString(&multiname));
		}			
		return (ClassClosure*)AvmCore::atomToScriptObject(atom);
	}

	DomainClass::DomainClass(VTable *cvtable)
		: ClassClosure(cvtable)
	{
		createVanillaPrototype();
	}

	ScriptObject* DomainClass::createInstance(VTable *ivtable,
											  ScriptObject *prototype)
	{
		return new (core()->GetGC(), ivtable->getExtraSize()) DomainObject(ivtable, prototype);
	}

	DomainObject* DomainClass::get_currentDomain()
	{
		ShellCodeContext* codeContext = (ShellCodeContext*)core()->codeContext();

		DomainObject* domainObject = (DomainObject*) createInstance(ivtable(), prototype);
		domainObject->domainEnv = codeContext->domainEnv();
		domainObject->domainToplevel = toplevel();
		
		return domainObject;
	}
	
	int DomainClass::get_MIN_DOMAIN_MEMORY_LENGTH()
 	{
#ifdef AVMPLUS_MOPS
 		return Domain::GLOBAL_MEMORY_MIN_SIZE;
#else
		AvmAssert(0);
		return 0;
#endif
 	}

 	ScriptObject *DomainObject::get_domainMemory() const
 	{
#ifdef AVMPLUS_MOPS
 		return domainEnv->domain()->globalMemory();
#else
		AvmAssert(0);
		return 0;
#endif
 	}
 
 	void DomainObject::set_domainMemory(ScriptObject *mem)
 	{
#ifdef AVMPLUS_MOPS
 		if(!domainEnv->domain()->setGlobalMemory(mem))
 			toplevel()->throwError(kEndOfFileError);
#else
		AvmAssert(0);
#endif
 	}

}
