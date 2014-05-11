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

        int _avm_isalnum(int c);
        int _avm_isalpha(int c);
        int _avm_isascii(int c);
        int _avm_isblank(int c);
        int _avm_iscntrl(int c);
        int _avm_isdigit(int c);
        int _avm_isgraph(int c);
        int _avm_islower(int c);
        int _avm_isprint(int c);
        int _avm_ispunct(int c);
        int _avm_isspace(int c);
        int _avm_isupper(int c);
        int _avm_isxdigit(int c);
        int _avm_toascii(int c);
        int _avm_tolower(int c);
        int _avm_toupper(int c);

        DECLARE_SLOTS_CTypeClass;
    };

}

#endif /* __avmshell_CTypeClass__ */

