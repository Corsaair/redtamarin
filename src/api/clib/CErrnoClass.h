/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_CErrnoClass__
#define __avmshell_CErrnoClass__

namespace avmshell
{
    using namespace avmplus;

    class CErrnoClass : public ClassClosure
    {
    public:
        CErrnoClass(VTable* cvtable);
        ~CErrnoClass();
        
        //void dummy();

        static int _GetErrno(ScriptObject*);
        static void _SetErrno(ScriptObject*, int value);

        //DECLARE_SLOTS_CErrnoClass;
    };

}

#endif /* __avmshell_CErrnoClass__ */

