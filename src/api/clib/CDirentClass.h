/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_CDirentClass__
#define __avmshell_CDirentClass__

namespace avmshell
{
    using namespace avmplus;

    class CDirentClass : public ClassClosure
    {
    public:
        CDirentClass(VTable* cvtable);
        ~CDirentClass();
        
        static int closedir(ScriptObject* self, CDIRObject* dirp);
        static CDIRObject* opendir(ScriptObject* self, Stringp dirname);
        static CdirentObject* readdir(ScriptObject* self, CDIRObject* dirp);
        
        //DECLARE_SLOTS_CDirentClass;
    };

    class CDIRClass : public ClassClosure
    {
    public:
        CDIRClass(VTable* vtable);
        ~CDIRClass();

        void dummy();

    private:
        DECLARE_SLOTS_CDIRClass;
    };

    class CDIRObject : public ScriptObject
    {
    public:
        CDIRObject(VTable *vtable, ScriptObject *delegate);
        ~CDIRObject();

        DIR* read();
        void write(DIR* value);

    private:
        DIR* _directory;

        DECLARE_SLOTS_CDIRObject;
    };

    class CdirentClass : public ClassClosure
    {
    public:
        CdirentClass(VTable* vtable);
        ~CdirentClass();

        void dummy();

    private:
        DECLARE_SLOTS_CdirentClass;
    };

    class CdirentObject : public ScriptObject
    {
    public:
        CdirentObject(VTable *vtable, ScriptObject *delegate);
        ~CdirentObject();

        dirent* read();
        void write(dirent* value);

    private:
        dirent* _entry;

        DECLARE_SLOTS_CdirentObject;
    };

}

#endif /* __avmshell_CDirentClass__ */

