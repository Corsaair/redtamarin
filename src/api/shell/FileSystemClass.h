/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_FileSystemClass__
#define __avmshell_FileSystemClass__

namespace avmshell
{
    using namespace avmplus;

    class FileSystemClass : public ClassClosure
    {
    public:
        FileSystemClass(VTable* cvtable);
        ~FileSystemClass();
        
        //bool isWindowsStore();
        Stringp read(Stringp filename);
        
        DECLARE_SLOTS_FileSystemClass;
    };

}

#endif /* __avmshell_FileSystemClass__ */

