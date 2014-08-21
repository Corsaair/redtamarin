/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


#include "avmshell.h"
#include "Deopt.h"

namespace avmshell
{
    ProgramClass::ProgramClass(VTable *cvtable)
        : ClassClosure(cvtable)
    {
        ShellCore* core = (ShellCore*)this->core();
        if (core->programClass == NULL) {
            core->programClass = this;
        }

        createVanillaPrototype();

        // initialTime: support for getTimer
        // todo note this is currently routed to the performance counter
        // for benchmark purposes.
        initialPerfTime = VMPI_getPerformanceCounter();
        initialTime = VMPI_getTime();
    }

    ProgramClass::~ProgramClass()
    {
        exit_callback = 0;
        initialPerfTime = 0;
        initialTime = 0;
    }

    int ProgramClass::user_argc;
    char **ProgramClass::user_argv;
    char *ProgramClass::exec_name;
    extern "C" char **environ;

    ArrayObject * ProgramClass::_getArgv()
    {
        Toplevel *toplevel = this->toplevel();
        AvmCore *core = this->core();

        ArrayObject *array = toplevel->arrayClass()->newArray();
        for( int i=0; i<user_argc; i++ )
        {
            array->setUintProperty(i, core->newStringUTF8(user_argv[i])->atom());
        }
        
        return array;
    }
    
    ArrayObject * ProgramClass::_getEnviron()
    {
        Toplevel *toplevel = this->toplevel();
        AvmCore *core = this->core();

        ArrayObject *array = toplevel->arrayClass()->newArray();

        #ifdef AVMSYSTEM_WIN32
            wchar **cur = VMPI_GetEnviron16();
        #else
            char **cur = VMPI_GetEnviron();
        #endif

        int i = 0;
        while( *cur )
        {
            #ifdef AVMSYSTEM_WIN32
                Stringp value = core->newStringUTF16(*cur);
                StUTF8String valueUTF8(value);

                array->setUintProperty( i, core->newStringUTF8( valueUTF8.c_str() )->atom() );
            #else
                array->setUintProperty( i, core->newStringUTF8( *cur )->atom() );
            #endif

            cur++;
            i++;
        }
        
        return array;
    }

    Stringp ProgramClass::_getProgramFilename()
    {
        return core()->newStringUTF8( exec_name );
    }

    void ProgramClass::_setExitListener(FunctionObject* f)
    {
        AvmCore *core = this->core();

        // Listeners MUST be functions or null
        if ( core->isNullOrUndefined(f->atom()) )
        {
            f = 0;
        }
        else if (!AvmCore::istype(f->atom(), core->traits.function_itraits))
        {
            toplevel()->argumentErrorClass()->throwError( kInvalidArgumentError, core->toErrorString("Function"));
        }

        exit_callback = f;
    }

    Stringp ProgramClass::_popenRead(Stringp command)
    {
        if( !command )
        {
            toplevel()->throwArgumentError(kNullArgumentError, "command");
        }

        StUTF8String commandUTF8(command);
        FILE *read_fp;
        char buffer[BUFSIZ + 1];
        int chars_read;

        VMPI_memset(buffer, '\0', sizeof(buffer));
        read_fp = VMPI_popen(commandUTF8.c_str(), "r");
        Stringp output = core()->newStringUTF8( "" );
        
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

    void ProgramClass::abort()
    {
        if( core()->getIsolate()->getAggregate()->isPrimordial(core()->getIsolate()->getDesc()) )
        {
            //exitCallback();
            //Platform::GetInstance()->exit( status );
            
            //MMgc::GCHeap::GetGCHeap()->Abort();
            //MMgc::GCHeap::GetGCHeap()->SignalImminentAbort();
            
            //ShellCore* score = (ShellCore*)this->core();
            //score->raiseExternalInterrupt();
            
            Platform::GetInstance()->exit( 1 );
        }
        else
        {
            GCRef<ClassClosure> workerClass = toplevel()->workerClass();
            static_cast<ShellWorkerClass*>((ClassClosure*)workerClass)->getCurrentWorker()->terminate();
        }
    }   

    int ProgramClass::exec(Stringp command)
    {
        if( !command )
        {
            toplevel()->throwArgumentError(kNullArgumentError, "command");
        }

        #ifdef UNDER_CE
        AvmAssert(0);
        return 0;
        #else
        StUTF8String commandUTF8(command);
        return system( commandUTF8.c_str() );
        #endif
    }

    void ProgramClass::exit(int status)
    {
        if( core()->getIsolate()->getAggregate()->isPrimordial(core()->getIsolate()->getDesc()) )
        {
            exitCallback();
            Platform::GetInstance()->exit( status );
        }
        else
        {
            GCRef<ClassClosure> workerClass = toplevel()->workerClass();
            static_cast<ShellWorkerClass*>((ClassClosure*)workerClass)->getCurrentWorker()->terminate();
        }
    }

    void ProgramClass::exitCallback()
    {
        if( exit_callback )
        {
            Atom argv[] = { nullObjectAtom };
            int argc = 0;
            
            exit_callback->call(argc, argv);
        }
    }

    double ProgramClass::getNanosecondTimer()
    {
        return ((VMPI_getPerformanceCounter() - initialPerfTime) * 1e9)
            / VMPI_getPerformanceFrequency();
    }
    
    unsigned ProgramClass::getTimer()
    {
        return (uint32_t)(VMPI_getTime() - initialTime);
    }

    Stringp ProgramClass::readLine()
    {
        AvmCore* core = this->core();
        Stringp s = core->kEmptyString;
        wchar wc[64];
        int i=0;
        for( int c = getchar(); c != '\n' && c != EOF; c = getchar() )
        {
            wc[i++] = (wchar)c;
            if( i == 63 )
            {
                wc[i] = 0;
                s = s->append16(wc);
                i = 0;
            }
        }

        if( i > 0 )
        {
            wc[i] = 0;
            s = s->append16(wc);
        }

        return s;
    }

    void ProgramClass::sleep(int32_t ms)
    {
        // Or do we try to make the all the isolate threads sleep? In a safepoint? and interruptibly?
        if (ms < 0) 
        {
            ms = 0;
        }

        vmbase::VMThread::sleep(ms);
    }

    void ProgramClass::trace(ArrayObject* a)
    {
        if( !a )
        {
            toplevel()->throwArgumentError(kNullArgumentError, "array");
        }
        
        AvmCore* core = this->core();
        PrintWriter& console = core->console;
        for( int i=0, n = a->getLength(); i < n; i++ )
        {
            if( i > 0 )
            {
                console << ' ';
            }
            
            StringIndexer s(core->string(a->getUintProperty(i)));
            for( int j = 0; j < s->length(); j++ )
            {
                wchar c = s[j];
                // '\r' gets converted into '\n'
                // '\n' is left alone
                // '\r\n' is left alone
                if( c == '\r' )
                {
                    if( ((j+1) < s->length()) && s[j+1] == '\n' )
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

    void ProgramClass::write(Stringp s)
    {
        if( !s )
        {
            toplevel()->throwArgumentError(kNullArgumentError, "string");
        }
        
        core()->console << s;
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

    void ProgramClass::disposeXML(XMLObject *xmlObject)
    {
        if( xmlObject )
        {
            xmlObject->dispose();
        }
    }


}
