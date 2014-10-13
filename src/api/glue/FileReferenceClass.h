/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_FileReferenceClass__
#define __avmshell_FileReferenceClass__

namespace avmshell
{
    using namespace avmplus;

    class FileReferenceClass : public ClassClosure
    {
    public:
        FileReferenceClass(VTable* cvtable);
        ~FileReferenceClass();
        
        bool isDummy();
        
    private:
        DECLARE_SLOTS_FileReferenceClass;
    };

    class FileReferenceObject : public ScriptObject
    {
    public:
        FileReferenceObject(VTable* vtable, ScriptObject* prototype);
        ~FileReferenceObject();
        
        bool isLocalDummy();
        
    private:
        DECLARE_SLOTS_FileReferenceObject;
    };

}

#endif /* __avmshell_FileReferenceClass__ */

