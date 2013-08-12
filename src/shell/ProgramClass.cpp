/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


#include "avmshell.h"
#include "Deopt.h"

namespace avmshell
{
    ProgramClass::ProgramClass(avmplus::VTable *cvtable)
        : avmplus::ClassClosure(cvtable)
    {
        ShellCore* core = (ShellCore*)this->core();
        if (core->programClass == NULL) {
            core->programClass = this;
        }

        createVanillaPrototype();

        // initialTime: support for getTimer
        // todo note this is currently routed to the performance counter
        // for benchmark purposes.
        #ifdef PERFORMANCE_GETTIMER
        initialTime = VMPI_getPerformanceCounter();
        #else
        initialTime = VMPI_getTime();
        #endif // PERFORMANCE_GETTIMER

    }

    ProgramClass::~ProgramClass()
    {
        initialTime = 0;
    }

    int ProgramClass::user_argc;
    char **ProgramClass::user_argv;
    char *ProgramClass::exec_name;
    extern "C" char **environ;

    avmplus::ArrayObject * ProgramClass::getArgv()
    {
        // get VTable for avmplus.System
        avmplus::Toplevel *toplevel = this->toplevel();
        avmplus::AvmCore *core = this->core();

        avmplus::ArrayObject *array = toplevel->arrayClass()->newArray();
        for(int i=0; i<user_argc;i++)
            array->setUintProperty(i, core->newStringUTF8(user_argv[i])->atom());

        return array;
    }
    
    avmplus::ArrayObject * ProgramClass::getEnviron()
    {
        // get VTable for avmplus.System
        avmplus::Toplevel *toplevel = this->toplevel();
        avmplus::AvmCore *core = this->core();

        avmplus::ArrayObject *array = toplevel->arrayClass()->newArray();
        char **cur = environ;
        int i = 0;
        while(*cur)
        {
                array->setUintProperty(i, core->newStringUTF8(*cur)->atom());
            i++;
            cur++;
        }
        
        return array;
    }

    avmplus::Stringp ProgramClass::popenRead(avmplus::Stringp command)
    {
        if (!command) {
            toplevel()->throwArgumentError(kNullArgumentError, "command");
        }

        avmplus::StUTF8String commandUTF8(command);
        FILE *read_fp;
        char buffer[BUFSIZ + 1];
        int chars_read;

        VMPI_memset(buffer, '\0', sizeof(buffer));
        read_fp = VMPI_popen(commandUTF8.c_str(), "r");
        avmplus::Stringp output = core()->newStringUTF8( "" );
        
        if (read_fp != NULL) {
            chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
            output = output->append( core()->newStringUTF8(buffer, chars_read) );
            
            while(chars_read > 0) {
                buffer[chars_read - 1] = '\0';
                chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
                output = output->append( core()->newStringUTF8(buffer, chars_read) );
            }
            
            VMPI_pclose(read_fp);
            return output;
        }
        
        return NULL;
    }

    int32_t ProgramClass::get_apiVersion()
    {
        ShellCore* core = (ShellCore*)this->core();
        return core->defaultAPIVersion;
    }

    avmplus::Stringp ProgramClass::get_programFilename()
    {
        return core()->newStringUTF8( exec_name );
    }

    int32_t ProgramClass::get_swfVersion()
    {
        ShellCore* core = (ShellCore*)this->core();
        avmplus::BugCompatibility::Version v = core->getDefaultBugCompatibilityVersion();
        AvmAssert(v >= 0 && v < avmplus::BugCompatibility::VersionCount);
        return avmplus::BugCompatibility::kNames[v];
    }

    double ProgramClass::get_totalMemory()
    {
        MMgc::GCHeap* gcheap = MMgc::GCHeap::GetGCHeap();
        // Bugzilla 678975: use GetUsedHeapSize for compatibility with Player
        return double(gcheap->GetUsedHeapSize() * MMgc::GCHeap::kBlockSize);
    }

    double ProgramClass::get_freeMemory()
    {
        MMgc::GCHeap* gcheap = MMgc::GCHeap::GetGCHeap();
        return double(gcheap->GetFreeHeapSize() * MMgc::GCHeap::kBlockSize);
    }

    double ProgramClass::get_privateMemory()
    {
        return double(AVMPI_getPrivateResidentPageCount() * VMPI_getVMPageSize());
    }

    void ProgramClass::eval(avmplus::Stringp source)
    {
        if (!source) {
            toplevel()->throwArgumentError(kNullArgumentError, "source");
        }
        
        #ifdef VMCFG_EVAL
        ShellCore* core = (ShellCore*)this->core();
        core->evaluateString( source, false );
        #endif // VMCFG_EVAL
    }

    int ProgramClass::exec(avmplus::Stringp command)
    {
        if (!command) {
            toplevel()->throwArgumentError(kNullArgumentError, "command");
        }
        #ifdef UNDER_CE
        AvmAssert(0);
        return 0;
        #else
        avmplus::StUTF8String commandUTF8(command);
        return system(commandUTF8.c_str());
        #endif
    }

    void ProgramClass::exit(int status)
    {
        if (core()->getIsolate()->getAggregate()->isPrimordial(core()->getIsolate()->getDesc())) {
            Platform::GetInstance()->exit(status);
        } else {
            GCRef<avmplus::ClassClosure> workerClass = toplevel()->workerClass();
            static_cast<ShellWorkerClass*>((avmplus::ClassClosure*)workerClass)->getCurrentWorker()->terminate();
        }
    }

    avmplus::Stringp ProgramClass::getAvmplusVersion()
    {
        return core()->newConstantStringLatin1(AVMPLUS_VERSION_USER " " AVMPLUS_BUILD_CODE);
    }

    avmplus::Stringp ProgramClass::getFeatures()
    {
        return core()->newConstantStringLatin1(avmfeatures);
    }

    avmplus::Stringp ProgramClass::getRunmode()
    {
        ShellCore* core = (ShellCore*)this->core();
        if (core->config.runmode == avmplus::RM_mixed)
            return core->newConstantStringLatin1("mixed");
        if (core->config.runmode == avmplus::RM_jit_all)
        {
            if (core->config.jitordie)
                return core->newConstantStringLatin1("jitordie");
            return core->newConstantStringLatin1("jit");
        }
        if (core->config.runmode == avmplus::RM_interp_all)
            return core->newConstantStringLatin1("interp");
        return core->newConstantStringLatin1("unknown");
    }

    double ProgramClass::getNanosecondTimer()
    {
        return ((VMPI_getPerformanceCounter() - initialTime) * 1e9)
            / VMPI_getPerformanceFrequency();
    }
    
    unsigned ProgramClass::getTimer()
    {
#ifdef PERFORMANCE_GETTIMER
        double time = ((double) (VMPI_getPerformanceCounter() - initialTime) * 1000.0 /
                       (double)VMPI_getPerformanceFrequency());
        return (uint32_t)time;
#else
        return (uint32_t)(VMPI_getTime() - initialTime);
#endif /* PERFORMANCE_GETTIMER */

    }

    avmplus::Stringp ProgramClass::readLine()
    {
        avmplus::AvmCore* core = this->core();
        avmplus::Stringp s = core->kEmptyString;
        wchar wc[64];
        int i=0;
        for (int c = getchar(); c != '\n' && c != EOF; c = getchar())
        {
            wc[i++] = (wchar)c;
            if (i == 63) {
                wc[i] = 0;
                s = s->append16(wc);
                i = 0;
            }
        }
        if (i > 0) {
            wc[i] = 0;
            s = s->append16(wc);
        }
        return s;
    }

    void ProgramClass::sleep(int32_t ms)
    {
        // Or do we try to make the all the isolate threads sleep? In a safepoint? and interruptibly?
        if (ms < 0) 
            ms = 0;
        vmbase::VMThread::sleep(ms);
    }

    void ProgramClass::trace(avmplus::ArrayObject* a)
    {
        if (!a)
            toplevel()->throwArgumentError(kNullArgumentError, "array");
        avmplus::AvmCore* core = this->core();
        avmplus::PrintWriter& console = core->console;
        for (int i=0, n = a->getLength(); i < n; i++)
        {
            if (i > 0)
                console << ' ';
            avmplus::StringIndexer s(core->string(a->getUintProperty(i)));
            for (int j = 0; j < s->length(); j++)
            {
                wchar c = s[j];
                // '\r' gets converted into '\n'
                // '\n' is left alone
                // '\r\n' is left alone
                if (c == '\r')
                {
                    if (((j+1) < s->length()) && s[j+1] == '\n')
                    {
                        console << '\r';
                        j++;
                    }

                    console << '\n';
                }
                else
                {
                    console << c;
                }
            }
        }
        console << '\n';
    }

    void ProgramClass::write(avmplus::Stringp s)
    {
        if (!s)
            toplevel()->throwArgumentError(kNullArgumentError, "string");
        core()->console << s;
    }
 
    void ProgramClass::debugger()
    {
        #ifdef DEBUGGER
        if (core()->debugger())
            core()->debugger()->enterDebugger();
        #endif
    }

    bool ProgramClass::isDebugger()
    {
        #ifdef DEBUGGER
        return core()->debugger() != NULL;
        #else
        return false;
        #endif
    }

    void ProgramClass::forceFullCollection()
    {
        core()->GetGC()->Collect();
    }

    void ProgramClass::queueCollection()
    {
        core()->GetGC()->QueueCollection();
    }

    void ProgramClass::pauseForGCIfCollectionImminent(double imminence)
    {
        if( avmplus::MathUtils::isNaN(imminence) )
            imminence = 0.75;
        core()->GetGC()->Collect(imminence);
    }

    void ProgramClass::disposeXML(avmplus::XMLObject *xmlObject)
    {
        if(xmlObject)
            xmlObject->dispose();
    }

    bool ProgramClass::isGlobal(avmplus::Atom o)
    {
        return avmplus::AvmCore::isObject(o) ? avmplus::AvmCore::atomToScriptObject(o)->isGlobalObject() : false;
    }

    bool ProgramClass::is64bit()
    {
        #ifdef AVMPLUS_64BIT
            return true;
        #else
            return false;
        #endif
    }

    bool ProgramClass::isIntptr(avmplus::Atom a)
    {
        return atomKind(a) == avmplus::AtomConstants::kIntptrType;
    }

    avmplus::Atom ProgramClass::canonicalizeNumber(avmplus::Atom a)
    {
        if (atomKind(a) == avmplus::AtomConstants::kDoubleType) {
            double val = *((double*)atomPtr(a));
            intptr_t intval = intptr_t(val);
            if (double(intval) == val && !(val == 0 && avmplus::MathUtils::isNegZero(val))) {
                // Atom is double representing an integer value that will fit in intptr_t.
                if (avmplus::atomIsValidIntptrValue(intval)) {
                    // The intptr_t value will also fit in kIntptrType atom, with tag.
                    return avmplus::atomFromIntptrValue(intval);
                }
            }
        }
        return a;
    }

    // Debug scaffolding for deoptimization.
    // Deoptimize method invoked in frame K levels above our caller.
    // Throws if no such frame exists, but is silently ignored if
    // the method is not currently compiled.

    void ProgramClass::deopt(int32_t k)
    {
#ifdef VMCFG_HALFMOON
        using avmplus::Deoptimizer;
        if (!Deoptimizer::deoptAncestor(core(), k))
            toplevel()->throwArgumentError(kNullArgumentError, "frame number");
#endif
        (void)k;
    }

    void ProgramClass::runInSafepoint(avmplus::FunctionObject* code)
    {
        class Task: public vmbase::SafepointTask {
            avmplus::FunctionObject* m_code;
        public:
            Task(avmplus::FunctionObject* code): m_code(code) {}
            void run() {
                avmplus::Atom argv[] = {avmplus::nullObjectAtom};
                m_code->call(0, argv);
            }
        };
        Task task(code);
        core()->getIsolate()->getAggregate()->safepointManager()->requestSafepointTask(task);
    }

}
