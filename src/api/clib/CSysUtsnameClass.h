/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_CSysUtsnameClass__
#define __avmshell_CSysUtsnameClass__

namespace avmshell
{
    using namespace avmplus;

    class CSysUtsnameClass : public ClassClosure
    {
    public:
        CSysUtsnameClass(VTable* cvtable);
        ~CSysUtsnameClass();
        
        static int uname(ScriptObject* self, Atom name);
        
        //DECLARE_SLOTS_CSysUtsnameClass;
    };

}

#endif /* __avmshell_CSysUtsnameClass__ */

