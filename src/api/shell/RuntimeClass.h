/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_RuntimeClass__
#define __avmshell_RuntimeClass__

namespace avmshell
{
    using namespace avmplus;

    class RuntimeClass : public ClassClosure
    {
    public:
        RuntimeClass(VTable* cvtable);
        ~RuntimeClass();
        
        int32_t get_apiVersion();
        int32_t get_swfVersion();
        Stringp _getAvmplusPlatform();
        Stringp _getAvmplusArchitecture();
        Stringp _getAvmplusVersion();
        Stringp _getAvmplusDescription();
        Stringp _getFeatures();
        Stringp _getRunmode();
        Stringp _getEndian();

        void eval(Stringp source);
        Stringp returnEval(Stringp source, bool recordTime);
        bool is64bit();
        
        DECLARE_SLOTS_RuntimeClass;
    };

}

#endif /* __avmshell_RuntimeClass__ */

