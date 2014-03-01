/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_CConioClass__
#define __avmshell_CConioClass__

namespace avmshell
{
    using namespace avmplus;

    class CConioClass : public ClassClosure
    {
    public:
        CConioClass(VTable* cvtable);
        ~CConioClass();
        
        static void canonical(ScriptObject*, bool status); //non standard
        static void echo(ScriptObject*, bool status); //non standard
        //static int getch(ScriptObject*);
        //static int getche(ScriptObject*);
        static int kbhit(ScriptObject*);

        //DECLARE_SLOTS_CConioClass;
    };



}

#endif /* __avmshell_CConioClass__ */

