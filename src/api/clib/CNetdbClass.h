/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_CNetdbClass__
#define __avmshell_CNetdbClass__

namespace avmshell
{
    using namespace avmplus;

    class CNetdbClass : public ClassClosure
    {
    public:
        CNetdbClass(VTable* cvtable);
        ~CNetdbClass();

        int get_AI_PASSIVE();
        int get_AI_CANONNAME();
        int get_AI_NUMERICHOST();
        int get_AI_NUMERICSERV();
        int get_AI_V4MAPPED();
        int get_AI_ALL();
        int get_AI_ADDRCONFIG();
        
        static CprotoentObject* getprotobynumber(ScriptObject* self, int proto);
        static CprotoentObject* getprotoent(ScriptObject* self);
        static ChostentObject* gethostent(ScriptObject* self);

        DECLARE_SLOTS_CNetdbClass;
    };

    class ChostentClass : public ClassClosure
    {
    public:
        ChostentClass(VTable* vtable);
        ~ChostentClass();

        void dummy();

    private:
        DECLARE_SLOTS_ChostentClass;
    };

    class ChostentObject : public ScriptObject
    {
    public:
        ChostentObject(VTable *vtable, ScriptObject *delegate);
        ~ChostentObject();

        void dummy();

    private:
        DECLARE_SLOTS_ChostentObject;
    };

    class CprotoentClass : public ClassClosure
    {
    public:
        CprotoentClass(VTable* vtable);
        ~CprotoentClass();

        void dummy();

    private:
        DECLARE_SLOTS_CprotoentClass;
    };

    class CprotoentObject : public ScriptObject
    {
    public:
        CprotoentObject(VTable *vtable, ScriptObject *delegate);
        ~CprotoentObject();

        void dummy();

    private:
        DECLARE_SLOTS_CprotoentObject;
    };


}

#endif /* __avmshell_CNetdbClass__ */

