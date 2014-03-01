/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_CFcntlClass__
#define __avmshell_CFcntlClass__

namespace avmshell
{
    using namespace avmplus;

    class CFcntlClass : public ClassClosure
    {
    public:
        CFcntlClass(VTable* cvtable);
        ~CFcntlClass();

        int get_O_RDONLY();
        int get_O_WRONLY();
        int get_O_RDWR();
        int get_O_ACCMODE();

        int get_O_APPEND();
        int get_O_CREAT();
        int get_O_TRUNC();
        int get_O_EXCL();
        
        int get_O_TEXT();
        int get_O_BINARY();
        
        DECLARE_SLOTS_CFcntlClass;
    };



}

#endif /* __avmshell_CFcntlClass__ */

