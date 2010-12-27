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

#ifndef __avmshell_DomainClass__
#define __avmshell_DomainClass__

#ifndef AVMSHELL_BUILD
#error "This file is only for use with avmshell"
#endif

namespace avmplus
{
    class GC_AS3_EXACT(DomainObject, ScriptObject)
    {
    protected:
        DomainObject(VTable *vtable, ScriptObject *delegate);
    public:
        REALLY_INLINE static DomainObject* create(MMgc::GC* gc, VTable* ivtable, ScriptObject* delegate)
        {
            return new (gc, ivtable->getExtraSize()) DomainObject(ivtable, delegate);
        }

        ~DomainObject();

        void init(DomainObject *base);
        Atom loadBytes(ByteArrayObject* bytes, uint32_t swfVersion);
        ClassClosure* getClass(Stringp name);
        // AS3 declaration requires these are ByteArrayObject
        ByteArrayObject* get_domainMemory() const;
        void set_domainMemory(ByteArrayObject* mem);

    private:
        ScriptObject* finddef(const Multiname& multiname, DomainEnv* domainEnv);

    // ------------------------ DATA SECTION BEGIN
        GC_DATA_BEGIN(DomainObject)

    public:
        DWB(DomainEnv*) GC_POINTER(domainEnv);
        DWB(Toplevel*)  GC_POINTER(domainToplevel);
        
        GC_DATA_END(DomainObject)

    private:
        DECLARE_SLOTS_DomainObject;
    // ------------------------ DATA SECTION END
    };

    class GC_AS3_EXACT(DomainClass, ClassClosure)
    {
    protected:
        DomainClass(VTable* cvtable);
        
    public:
        REALLY_INLINE static DomainClass* create(MMgc::GC* gc, VTable* cvtable)
        {
            return new (gc, cvtable->getExtraSize()) DomainClass(cvtable);
        }

        ScriptObject *createInstance(VTable *ivtable, ScriptObject *delegate);

        DomainObject* get_currentDomain();
        int get_MIN_DOMAIN_MEMORY_LENGTH();

    // ------------------------ DATA SECTION BEGIN
        GC_NO_DATA(DomainClass)

    private:
        DECLARE_SLOTS_DomainClass;
    // ------------------------ DATA SECTION END
    };
}

#endif /* __avmshell_DomainClass__ */
