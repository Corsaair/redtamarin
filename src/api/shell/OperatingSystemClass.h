/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_OperatingSystemClass__
#define __avmshell_OperatingSystemClass__

namespace avmshell
{
    using namespace avmplus;

    class OperatingSystemClass : public ClassClosure
    {
    public:
        OperatingSystemClass(VTable* cvtable);
        ~OperatingSystemClass();
        
        bool isWindowsStore();
        
        DECLARE_SLOTS_OperatingSystemClass;
    };

}

#endif /* __avmshell_OperatingSystemClass__ */

