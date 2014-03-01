/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_CTypeClass__
#define __avmshell_CTypeClass__

namespace avmshell
{
    using namespace avmplus;

    class CTypeClass : public ClassClosure
    {
    public:
        CTypeClass(VTable* cvtable);
        ~CTypeClass();
        
        static int isalnum(ScriptObject*, int c);

        static int isalpha(ScriptObject*, int c);

        static int isascii(ScriptObject*, int c);

        static int isblank(ScriptObject*, int c);

        static int iscntrl(ScriptObject*, int c);

        static int isdigit(ScriptObject*, int c);

        static int isgraph(ScriptObject*, int c);

        static int islower(ScriptObject*, int c);

        static int isprint(ScriptObject*, int c);

        static int ispunct(ScriptObject*, int c);

        static int isspace(ScriptObject*, int c);

        static int isupper(ScriptObject*, int c);

        static int isxdigit(ScriptObject*, int c);

        static int toascii(ScriptObject*, int c);

        static int tolower(ScriptObject*, int c);

        static int toupper(ScriptObject*, int c);
        
        //DECLARE_SLOTS_CTypeClass;
    };

}

#endif /* __avmshell_CTypeClass__ */

