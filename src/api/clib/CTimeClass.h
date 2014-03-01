/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_CTimeClass__
#define __avmshell_CTimeClass__

namespace avmshell
{
	using namespace avmplus;

    class CTimeClass : public ClassClosure
    {
    public:
        CTimeClass(VTable* cvtable);
        ~CTimeClass();


        int get_CLOCKS_PER_SEC();


        DECLARE_SLOTS_CTimeClass;
    };

}

#endif /* __avmshell_CTimeClass__ */

