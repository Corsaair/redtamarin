/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_CSpawnClass__
#define __avmshell_CSpawnClass__

namespace avmshell
{
    using namespace avmplus;

    class CSpawnClass : public ClassClosure
    {
    public:
        CSpawnClass(VTable* cvtable);
        ~CSpawnClass();

        //void dummy();

        static int spawn(ScriptObject* self, Cpid_tObject* pid, Stringp path, ArrayObject* argv, ArrayObject* envp);
        static int spawnp(ScriptObject* self, Cpid_tObject* pid, Stringp file, ArrayObject* argv, ArrayObject* envp);
        
        //DECLARE_SLOTS_CSpawnClass;
    };

    class Cpid_tClass : public ClassClosure
    {
    public:
        Cpid_tClass(VTable* vtable);
        ~Cpid_tClass();

        void dummy();

    private:
        DECLARE_SLOTS_Cpid_tClass;
    };

    class Cpid_tObject : public ScriptObject
    {
    public:
        Cpid_tObject(VTable *vtable, ScriptObject *delegate);
        ~Cpid_tObject();

        void dummy();

    private:
        DECLARE_SLOTS_Cpid_tObject;
    };

}

#endif /* __avmshell_CSpawnClass__ */

