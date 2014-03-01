/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "avmshell.h"

namespace avmshell
{

    DiagnosticsClass::DiagnosticsClass(VTable *cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    DiagnosticsClass::~DiagnosticsClass()
    {
        
    }

    void DiagnosticsClass::debugger()
    {
        #ifdef DEBUGGER
        if (core()->debugger())
            core()->debugger()->enterDebugger();
        #endif
    }

    bool DiagnosticsClass::isDebugger()
    {
        #ifdef DEBUGGER
        return core()->debugger() != NULL;
        #else
        return false;
        #endif
    }

    void DiagnosticsClass::_log(Stringp message)
    {
        StUTF8String messageUTF8(message);
        VMPI_log( messageUTF8.c_str() );
    }

    void DiagnosticsClass::_initializeLogging(Stringp filename)
    {
        StUTF8String filenameUTF8(filename);
        Platform::GetInstance()->initializeLogging( filenameUTF8.c_str() );
    }


    bool DiagnosticsClass::_isGlobal(Atom o)
    {
        return avmplus::AvmCore::isObject(o) ? avmplus::AvmCore::atomToScriptObject(o)->isGlobalObject() : false;
    }

    bool DiagnosticsClass::_isIntptr(Atom a)
    {
        return atomKind(a) == AtomConstants::kIntptrType;
    }

    Atom DiagnosticsClass::_canonicalizeNumber(Atom a)
    {
        if (atomKind(a) == AtomConstants::kDoubleType) {
            double val = *((double*)atomPtr(a));
            intptr_t intval = intptr_t(val);
            if (double(intval) == val && !(val == 0 && MathUtils::isNegZero(val))) {
                // Atom is double representing an integer value that will fit in intptr_t.
                if (atomIsValidIntptrValue(intval)) {
                    // The intptr_t value will also fit in kIntptrType atom, with tag.
                    return atomFromIntptrValue(intval);
                }
            }
        }
        return a;
    }

    void DiagnosticsClass::_deopt(int32_t k)
    {
    #ifdef VMCFG_HALFMOON
        using Deoptimizer;
        if (!Deoptimizer::deoptAncestor(core(), k))
            toplevel()->throwArgumentError(kNullArgumentError, "frame number");
    #endif
        (void)k;
    }

    void DiagnosticsClass::_runInSafepoint(FunctionObject* code)
    {
        class Task: public vmbase::SafepointTask {
            FunctionObject* m_code;
        public:
            Task(FunctionObject* code): m_code(code) {}
            void run() {
                Atom argv[] = {nullObjectAtom};
                m_code->call(0, argv);
            }
        };
        Task task(code);
        core()->getIsolate()->getAggregate()->safepointManager()->requestSafepointTask(task);
    }

}
