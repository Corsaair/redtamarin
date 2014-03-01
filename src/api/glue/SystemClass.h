/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_SystemClass__
#define __avmshell_SystemClass__

namespace avmshell
{
    using namespace avmplus;

    class SystemClass : public ClassClosure
    {
    public:
        SystemClass(VTable* cvtable);
        ~SystemClass();
        
        double get_totalMemory();
        double get_freeMemory();
        double get_privateMemory();
        
        DECLARE_SLOTS_SystemClass;
    };

}

#endif /* __avmshell_SystemClass__ */

