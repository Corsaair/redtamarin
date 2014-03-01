/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_DiagnosticsClass__
#define __avmshell_DiagnosticsClass__

namespace avmshell
{
    using namespace avmplus;

    class DiagnosticsClass : public ClassClosure
    {
    public:
        DiagnosticsClass(VTable* cvtable);
        ~DiagnosticsClass();
        
        void debugger();
        bool isDebugger();
        void _log(Stringp message);
        void _initializeLogging(Stringp filename);

        bool _isGlobal(Atom o);
        bool _isIntptr(Atom a);
        Atom _canonicalizeNumber(Atom a);
        void _deopt(int32_t k);
        void _runInSafepoint(FunctionObject* closure);
        
        DECLARE_SLOTS_DiagnosticsClass;
    };

}

#endif /* __avmshell_DiagnosticsClass__ */

