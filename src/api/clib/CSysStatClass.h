/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_CSysStatClass__
#define __avmshell_CSysStatClass__

namespace avmshell
{
    using namespace avmplus;

    class CSysStatClass : public ClassClosure
    {
    public:
        CSysStatClass(VTable* cvtable);
        ~CSysStatClass();

        int mkdir(Stringp path, int mode);


        static int chmod(ScriptObject* self, Stringp path, int mode);
        //fchmod()
        //fchmodat()
        static int fstat(ScriptObject* self, int fildes, CStatusObject* buf);
        //fstatat()
        //futimens()
        //AS3//getumask()
        //lstat()
        //static int mkdir(ScriptObject* self, Stringp path, int mode);
        //mkdirat()
        //mkfifo()
        //mkfifoat()
        //mknod()
        //mknodat()
        static int stat(ScriptObject* self, Stringp path, CStatusObject* buf);
        static int umask(ScriptObject*, int cmask);
        //utimensat()


        DECLARE_SLOTS_CSysStatClass;
    };

    class CStatusClass : public ClassClosure
    {
    public:
        CStatusClass(VTable* vtable);
        ~CStatusClass();

        void dummy();

    private:
        DECLARE_SLOTS_CStatusClass;
    };

    class CStatusObject : public ScriptObject
    {
    public:
        CStatusObject(VTable *vtable, ScriptObject *delegate);
        ~CStatusObject();

        void dummy();

    private:
        DECLARE_SLOTS_CStatusObject;
    };

}

#endif /* __avmshell_CSysStatClass__ */

