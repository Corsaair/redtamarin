/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
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

#ifndef AVMSHELL_BUILD
#error "This file is only for use with avmshell"
#endif

namespace avmplus
{
    using namespace avmshell;
    
    DomainObject::DomainObject(VTable *vtable, ScriptObject *delegate)
        : ScriptObject(vtable, delegate)
    {
    }

    DomainObject::~DomainObject()
    {
    }

    void DomainObject::init(DomainObject* parentDomain)
    {
        ShellCore* core = (ShellCore*) this->core();

        DomainEnv* baseDomainEnv = parentDomain ?
                                parentDomain->domainEnv :
                                (DomainEnv*)NULL;
        Domain* baseDomain = baseDomainEnv ?
                                baseDomainEnv->domain() :
                                NULL;

        domainToplevel = parentDomain ?
                            (Toplevel*)parentDomain->domainToplevel :
                            core->createShellToplevel();

        Domain* domain = Domain::newDomain(core, baseDomain);
        domainEnv = DomainEnv::newDomainEnv(core, domain, parentDomain ? parentDomain->domainEnv : (DomainEnv*)NULL);
    }

    Atom DomainObject::loadBytes(ByteArrayObject* b, uint32_t swfVersion)
    {
        AvmCore* core = this->core();
        if (!b)
            toplevel()->throwTypeError(kNullArgumentError, core->toErrorString("bytes"));

        // parse new bytecode
        size_t len = b->get_length();
        ScriptBuffer code = core->newScriptBuffer(len);
        VMPI_memcpy(code.getBuffer(), &b->GetByteArray()[0], len);

        Toplevel* toplevel = domainToplevel;
        uint32_t api = core->getAPI(NULL);

        // parse constants and attributes.
        PoolObject* pool = core->parseActionBlock(code,
                                /*start*/0,
                                toplevel,
                                domainEnv->domain(),
                                /*ninit*/NULL,
                                api);


        // by default, use the same bugCompatibility as the builtins use
        const BugCompatibility* bugCompatibility = toplevel->abcEnv()->codeContext()->bugCompatibility();
        if (swfVersion != 0)
        {
            // ...unless specified otherwise.
            for (int j = 0; j < BugCompatibility::VersionCount; ++j)
            {
                if (BugCompatibility::kNames[j] == swfVersion)
                {
                    bugCompatibility = core->createBugCompatibility((BugCompatibility::Version)j);
                    goto done;
                }
            }
            // if we get here, didn't find a valid name
            toplevel->throwTypeError(kInvalidArgumentError, core->toErrorString("swfVersion"));
        }
done:

        ShellCodeContext* codeContext = new (core->GetGC()) ShellCodeContext(domainEnv, bugCompatibility);
        return core->handleActionPool(pool, toplevel, codeContext);
    }

    ScriptObject* DomainObject::finddef(const Multiname& multiname,
                                        DomainEnv* domainEnv)
    {
        Toplevel* toplevel = this->toplevel();

        ScriptEnv* script = core()->domainMgr()->findScriptEnvInDomainEnvByMultiname(domainEnv, multiname);
        if (script == (ScriptEnv*)BIND_AMBIGUOUS)
            toplevel->throwReferenceError(kAmbiguousBindingError, multiname);

        if (script == (ScriptEnv*)BIND_NONE)
            toplevel->throwReferenceError(kUndefinedVarError, multiname);

        if (script->global == NULL)
        {
            script->initGlobal();
            script->coerceEnter(script->global->atom());
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
        int dot = name->lastIndexOf(core->cachedChars[(int)'.']);

        // If there is a '.', this is a fully-qualified
        // class name in a package.  Must turn it into
        // a namespace-qualified multiname.
        Namespace* ns;
        Stringp className;
        if (dot >= 0) {
            Stringp uri = core->internString(name->substring(0, dot));
            ns = core->internNamespace(core->newNamespace(uri, Namespace::NS_Public, core->getAPI(NULL)));
            className = core->internString(name->substring(dot+1, name->length()));
        } else {
            ns = core->findPublicNamespace();
            className = core->internString(name);
        }

        Multiname multiname(ns, className);

        ScriptObject *container = finddef(multiname, domainEnv);
        if (!container) {
            toplevel()->throwTypeError(kClassNotFoundError, core->toErrorString(&multiname));
        }
        Atom atom = toplevel()->getproperty(container->atom(),
                                            &multiname,
                                            container->vtable);

        if (!AvmCore::istype(atom, core->traits.class_itraits)) {
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
        return DomainObject::create(core()->GetGC(), ivtable, prototype);
    }

    DomainObject* DomainClass::get_currentDomain()
    {
        CodeContext* codeContext = core()->codeContext();

        DomainObject* domainObject = (DomainObject*) createInstance(ivtable(), prototypePtr());
        domainObject->domainEnv = codeContext->domainEnv();
        domainObject->domainToplevel = toplevel();

        return domainObject;
    }

    int DomainClass::get_MIN_DOMAIN_MEMORY_LENGTH()
    {
        return DomainEnv::GLOBAL_MEMORY_MIN_SIZE;
    }

    ByteArrayObject* DomainObject::get_domainMemory() const
    {
        return (ByteArrayObject*)domainEnv->get_globalMemory();
    }

    void DomainObject::set_domainMemory(ByteArrayObject* mem)
    {
        if(!domainEnv->set_globalMemory(mem))
            toplevel()->throwError(kEndOfFileError);
    }
}
