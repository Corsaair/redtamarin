/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_ProgramClass__
#define __avmshell_ProgramClass__


namespace avmshell
{
    
    /**
     * A simple class that has some native methods.
     * Included as an example for writers of native methods,
     * and also to provide some useful QA instrumentation.
     */
    class GC_AS3_EXACT(ProgramClass, avmplus::ClassClosure)
    {
        uint64_t initialTime;

        ProgramClass(avmplus::VTable* cvtable);
    public:
        REALLY_INLINE static ProgramClass* create(MMgc::GC* gc, avmplus::VTable* cvtable)
        {
            return new (gc, MMgc::kExact, cvtable->getExtraSize()) ProgramClass(cvtable);
        }

        ~ProgramClass();

        // set by shell
        static int user_argc;
        static char **user_argv;
        static char *exec_name;

        avmplus::ArrayObject * getArgv();
        avmplus::ArrayObject * getEnviron();

        avmplus::Stringp popenRead(avmplus::Stringp command);

        int32_t get_apiVersion();

        avmplus::Stringp get_programFilename();

        int32_t get_swfVersion();

        double get_totalMemory();

        double get_freeMemory();

        double get_privateMemory();

        /**
         * Implementation of System.eval
         * AS usage: System.eval(source_code);
         * Evaluates AS3 source code at runtime.
         */
        void eval(avmplus::Stringp source);

        /**
         * Implementation of System.exec
         * AS usage: exitCode = System.exec("command");
         * Executes the specified command line and returns
         * the status code
         */
        int exec(avmplus::Stringp command);

        /**
         * Implementation of System.exit
         * AS usage: System.exit(status);
         * Exits the VM with OS exit code specified by  status.
         */
        void exit(int status);

        /**
         * Implementation of System.getAvmplusVersion
         * AS usage: System.getAvmplusVersion();
         * Returns the current version of AVM+ in the form
         * "1.0 d100"
         */
        avmplus::Stringp getAvmplusVersion();

        /**
         * Implementation of System.getFeatures
         * AS usage: System.getFeatures();
         * Returns the compiled in features of AVM+
         */
        avmplus::Stringp getFeatures();

        /**
         * Implementation of System.getRunmode
         * AS usage: System.getRunmode();
         * Returns the current runmode
         */
        avmplus::Stringp getRunmode();

        /**
         * @name ActionScript Extensions
         * ActionScript extensions to ECMAScript
         */
        /*@{*/
        double getNanosecondTimer();
        unsigned getTimer();
        /*@}*/

        avmplus::Stringp readLine();

        /**
         * Implementation of System.sleep.
         */
        void sleep(int ms);

        void trace(avmplus::ArrayObject* a);

        void write(avmplus::Stringp s);

        /**
         * @name Debugging Extensions
         */
        /*@{*/
        void debugger();
        bool isDebugger();
        /*@}*/
        
        // Initiate a garbage collection; future versions will not return before completed.
        void forceFullCollection();

        // Queue a garbage collection request.
        void queueCollection();

        void pauseForGCIfCollectionImminent(double imminence);
        
        void disposeXML(avmplus::XMLObject *xmlObject);

        // function exists solely to test ScriptObject::isGlobalObject
        bool isGlobal(avmplus::Atom o);
        
        // Support for VM tests that depend on representation of numeric atoms.
        // These are provided solely for testing purposes, as the semantics of an AS3 program
        // should not depend on the word size of the platform nor the internal encoding of atoms.

        // Return true if running on a 64-bit platform.
        bool is64bit();

        // Return true if the argument is an atom with tag kIntptrType.
        bool isIntptr(avmplus::Atom a);

        // Return argument value as a kIntptrType atom if the argument is a numeric
        // value that can be so represented, else return the argument unchanged.
        avmplus::Atom canonicalizeNumber(avmplus::Atom a);

        // DEOPT: Diagnostic scaffolding.
        void deopt(int32_t k);
        void runInSafepoint(avmplus::FunctionObject* closure);

        GC_NO_DATA(ProgramClass)

        DECLARE_SLOTS_ProgramClass;
    };
}

#endif /* __avmshell_ProgramClass__ */
