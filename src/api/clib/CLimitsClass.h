/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_CLimitsClass__
#define __avmshell_CLimitsClass__

namespace avmshell
{
    using namespace avmplus;

    class CLimitsClass : public ClassClosure
    {
    public:
        CLimitsClass(VTable* cvtable);
        ~CLimitsClass();
        
        int get_PATH_MAX();
        
        DECLARE_SLOTS_CLimitsClass;
    };

}

#endif /* __avmshell_CLimitsClass__ */

