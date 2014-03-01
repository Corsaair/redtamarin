/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_ProgramClass__
#define __avmshell_ProgramClass__


namespace avmshell
{
    using namespace avmplus;

    /**
     * A simple class that has some native methods.
     * Included as an example for writers of native methods,
     * and also to provide some useful QA instrumentation.
     */
    class GC_AS3_EXACT(ProgramClass, avmplus::ClassClosure)
    {
        uint64_t initialPerfTime;
        uint64_t initialTime;

        ProgramClass(VTable* cvtable);
    public:
        REALLY_INLINE static ProgramClass* create(MMgc::GC* gc, VTable* cvtable)
        {
            return new (gc, MMgc::kExact, cvtable->getExtraSize()) ProgramClass(cvtable);
        }

        ~ProgramClass();

        // set by shell
        static int user_argc;
        static char **user_argv;
        static char *exec_name;

        GCMember<FunctionObject> GC_POINTER(exit_callback);

        ArrayObject * _getArgv();
        ArrayObject * _getEnviron();
        Stringp _getProgramFilename();

        void _setExitListener(FunctionObject* f);

        Stringp _popenRead(Stringp command);

        //_findShell()

        //argv
        //filename
        //startupDirectory
        
        double get_totalMemory();
        double get_freeMemory();
        double get_privateMemory();

        //environ
        //pid
        //shell
        //workingDirectory

        void abort();
        int exec(Stringp command);
        //open()

        void exit(int status);
        void exitCallback(); //C++ side only

        void sleep(int ms);
        double getNanosecondTimer();
        unsigned getTimer();

        Stringp readLine();
        void write(Stringp s);
        //writeLine()
        void trace(ArrayObject* a);

        
        // Initiate a garbage collection; future versions will not return before completed.
        void forceFullCollection();

        // Queue a garbage collection request.
        void queueCollection();

        void pauseForGCIfCollectionImminent(double imminence);
        void disposeXML(XMLObject *xmlObject);


        GC_NO_DATA(ProgramClass)

        DECLARE_SLOTS_ProgramClass;
    };
}

#endif /* __avmshell_ProgramClass__ */
