/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is [Open Source Virtual Machine.].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2004-2006
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Adobe AS3 Team
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

#include "avmshell.h"

#include "shell_toplevel.cpp"

namespace avmshell
{
    const int kScriptTimeout = 15;
    const int kScriptGracePeriod = 5;

    ShellCoreSettings::ShellCoreSettings()
        : arguments(NULL)
        , numargs(-1)
        , nodebugger(false)
        , astrace_console(0)
        , do_verbose(0)
        , enter_debugger_on_launch(false)
        , interrupts(AvmCore::interrupts_default)
        , verifyall(AvmCore::verifyall_default)
        , verifyonly(AvmCore::verifyonly_default)
        , greedy(false)
        , nogc(false)
        , incremental(true)
        , exactgc(true)
        , fixedcheck(true)
        , gcthreshold(0)
        , langID(-1)
        , jitordie(AvmCore::jitordie_default)
        , runmode(AvmCore::runmode_default)
#ifdef VMCFG_NANOJIT
        , njconfig()
#endif
        , st_component(NULL)
        , st_category(NULL)
        , st_name(NULL)
        , api(kApiVersion_default)
        , swfVersion(BugCompatibility::kLatest)
    {
    }

    ShellToplevel::ShellToplevel(AbcEnv* abcEnv) : Toplevel(abcEnv)
    {
        shellClasses = ExactHeapList< RCList<ClassClosure> >::create(core()->gc, avmplus::NativeID::shell_toplevel_abc_class_count);
        if (avmplus::NativeID::shell_toplevel_abc_class_count > 0)
            shellClasses->list.set(avmplus::NativeID::shell_toplevel_abc_class_count-1, 0);
    }

    ShellCore::ShellCore(MMgc::GC* gc)
        : AvmCore(gc)
    {
        systemClass = NULL;

        gracePeriod = false;
        inStackOverflow = false;

        allowDebugger = -1; // aka "not yet set"

        consoleOutputStream = new (gc) ConsoleOutputStream(gc);

        setConsoleStream(consoleOutputStream);
    }

    void ShellCore::stackOverflow(Toplevel* toplevel)
    {
        if (inStackOverflow)
        {
            // Already handling a stack overflow, so do not
            // re-enter handler.
            return;
        }

        // Temporarily disable stack overflow checks
        // so that we can construct an exception object.
        // There should be plenty of margin before the
        // actual stack bottom to do this.
        inStackOverflow = true;

        Stringp errorMessage = getErrorMessage(kStackOverflowError);
        Atom args[2] = { nullObjectAtom, errorMessage->atom() };
        Atom errorAtom = toplevel->errorClass()->construct(1, args);
        Exception *exception = new (GetGC()) Exception(this, errorAtom);

        // Restore stack overflow checks
        inStackOverflow = false;

        // Throw the stack overflow exception
        throwException(exception);
    }

    /* static */
    void ShellCore::interruptTimerCallback(void* data)
    {
        ((AvmCore*)data)->raiseInterrupt(ScriptTimeout);
    }

    void ShellCore::interrupt(Toplevel *toplevel, InterruptReason)
    {
        if (gracePeriod) {
            // This script has already had its chance; it violated
            // the grace period.
            // Throw an exception it cannot catch.
            Stringp errorMessage = getErrorMessage(kScriptTerminatedError);
            Atom args[2] = { nullObjectAtom, errorMessage->atom() };
            Atom errorAtom = toplevel->errorClass()->construct(1, args);
            Exception *exception = new (GetGC()) Exception(this, errorAtom);
            exception->flags |= Exception::EXIT_EXCEPTION;
            throwException(exception);
        }

        // Give the script an additional grace period to
        // clean up, and throw an exception.
        gracePeriod = true;

        Platform::GetInstance()->setTimer(kScriptGracePeriod, interruptTimerCallback, this);

        toplevel->throwError(kScriptTimeoutError);
    }

    void ShellCore::initShellPool()
    {
        shell_domain = Domain::newDomain(this, builtinDomain);
#ifdef VMCFG_AOT
        NativeInitializer shellNInit(this,
            &shell_toplevel_aotInfo,
            avmplus::NativeID::shell_toplevel_abc_method_count,
            avmplus::NativeID::shell_toplevel_abc_class_count);
        shellNInit.fillInClasses(avmplus::NativeID::shell_toplevel_classEntries);
        shellNInit.fillInMethods(avmplus::NativeID::shell_toplevel_methodEntries);
        shellPool = shellNInit.parseBuiltinABC(shell_domain);
#else
        shellPool = AVM_INIT_BUILTIN_ABC_IN_DOMAIN(shell_toplevel, this, shell_domain);
#endif
    }

    ShellToplevel* ShellCore::createShellToplevel()
    {
        // Initialize a new Toplevel.  This will also create a new
        // DomainEnv based on the builtinDomain.
        ShellToplevel* shell_toplevel = (ShellToplevel*)initToplevel();

        DomainEnv* builtinDomainEnv = shell_toplevel->domainEnv();
        AvmAssert(builtinDomainEnv->domain() == builtinDomain);
        AvmAssert(builtinDomainEnv->base() == NULL);

        shell_domainEnv = DomainEnv::newDomainEnv(this, shell_domain, builtinDomainEnv);

        // Initialize the shell builtins in the new Toplevel
        // use the same bugCompatibility that the base builtins use
        const BugCompatibility* shell_bugCompatibility = shell_toplevel->abcEnv()->codeContext()->bugCompatibility();
        ShellCodeContext* shell_codeContext = new(GetGC()) ShellCodeContext(shell_domainEnv, shell_bugCompatibility);

        //handleActionPool(shellPool, shell_toplevel, shell_codeContext);
        shell_toplevel->shellEntryPoint = prepareActionPool(shellPool, shell_toplevel, shell_codeContext);

        return shell_toplevel;
    }

    /*virtual*/ Toplevel* ShellCore::createToplevel(AbcEnv* abcEnv)
    {
        return ShellToplevel::create(GetGC(), abcEnv);
    }

#ifdef VMCFG_EVAL

    // FIXME, this is currently hokey for several reasons:
    //
    //  - Does not try to determine whether input is Latin1, UTF8, or indeed, already UTF16,
    //    but assumes UTF8, which can be dangerous.  Falls back to latin1 if the utf8 conversion
    //    fails, this seems ill-defined in the string layer though so it's just one more hack.
    //
    //  - Does not create an UTF16 string.  The string layer is actually broken on this count,
    //    because requesting an empty UTF16 string returns a constant that is a Latin1 string,
    //    and appending to it won't force the representation to UTF16 unless the data require
    //    that to happen.  See <URL:https://bugzilla.mozilla.org/show_bug.cgi?id=473995>.
    //
    //  - May incur copying because the terminating NUL is not accounted for in the original
    //    creation

    String* ShellCore::decodeBytesAsUTF16String(uint8_t* bytes, uint32_t nbytes, bool terminate)
    {
        String* s = newStringUTF8((const char*)bytes, nbytes);
        if (s == NULL)
            s = newStringLatin1((const char*)bytes, nbytes);
        if (terminate)
            s = s->appendLatin1("\0", 1);
        return s;
    }

    String* ShellCore::readFileForEval(String* referencingFile, String* filename)
    {
        // FIXME, filename sanitazion is more complicated than this
        if (referencingFile != NULL && filename->charAt(0) != '/' && filename->charAt(0) != '\\') {
            // find the last slash if any, truncate the string there, append the
            // new filename
            int32_t x = referencingFile->lastIndexOf(newStringLatin1("/"));
            if (x != -1)
                filename = referencingFile->substring(0,x+1)->append(filename);
        }
        filename = filename->appendLatin1("\0", 1);

        // FIXME, not obvious that UTF8 is correct for all operating systems (far from it!)
        StUTF8String fn(filename);
        FileInputStream f(fn.c_str());
        if (!f.valid() || (uint64_t) f.length() >= UINT32_T_MAX)
            return NULL;

        uint32_t nbytes = (uint32_t) f.available();
        uint8_t* bytes = new uint8_t[nbytes];
        f.read(bytes, nbytes);
        String* str = decodeBytesAsUTF16String(bytes, nbytes, true);
        delete [] bytes;
        return str;
    }

    // input is always NUL-terminated
    void ShellCore::evaluateString(String* input, bool record_time)
    {
        setStackLimit();

        TRY(this, kCatchAction_ReportAsError)
        {
            // Always Latin-1 here
            input = input->appendLatin1("\0", 1);
            double then = 0, now = 0;
            if (record_time)
                then = VMPI_getDate();
            uint32_t api = this->getAPI(NULL);
            Atom result = handleActionSource(input, /*filename*/NULL, shell_toplevel, /*ninit*/NULL, user_codeContext, api);
            if (record_time)
                now = VMPI_getDate();
            if (result != undefinedAtom)
                console << string(result) << "\n";
            if (record_time)
                console << "Elapsed time: " << (now - then)/1000 << "s\n";
        }
        CATCH(Exception *exception)
        {
#ifdef DEBUGGER
            if (!(exception->flags & Exception::SEEN_BY_DEBUGGER))
            {
                console << string(exception->atom) << "\n";
            }
            if (exception->getStackTrace()) {
                console << exception->getStackTrace()->format(this) << '\n';
            }
#else
            console << string(exception->atom) << "\n";
#endif
        }
        END_CATCH
        END_TRY
    }

#endif // VMCFG_EVAL

#ifdef AVMSHELL_PROJECTOR_SUPPORT

    // Run a known projector file
    int ShellCore::executeProjector(char *executablePath)
    {
        AvmAssert(isValidProjectorFile(executablePath));

        uint8_t header[8];

        FileInputStream file(executablePath);

        file.seek(file.length() - 8);
        file.read(header, 8);

        int abcLength = (header[4]     |
                         header[5]<<8  |
                         header[6]<<16 |
                         header[7]<<24);

        ScriptBuffer code = newScriptBuffer(abcLength);
        file.seek(file.length() - 8 - abcLength);
        file.read(code.getBuffer(), abcLength);

        return handleArbitraryExecutableContent(code, executablePath);
    }

    /* static */
    bool ShellCore::isValidProjectorFile(const char* filename)
    {
        FileInputStream file(filename);
        uint8_t header[8];

        if (!file.valid())
            return false;

        file.seek(file.length() - 8);
        file.read(header, 8);

        // Check the magic number
        if (header[0] != 0x56 || header[1] != 0x34 || header[2] != 0x12 || header[3] != 0xFA)
            return false;

        return true;
    }

#endif // AVMSHELL_PROJECTOR_SUPPORT

#ifdef VMCFG_SELFTEST
    void ShellCore::executeSelftest(ShellCoreSettings& settings)
    {
        setStackLimit();
        ::selftests(this, settings.st_component, settings.st_category, settings.st_name);
    }
#endif

    bool ShellCore::setup(const ShellCoreSettings& settings)
    {
#ifdef VMCFG_AOT
        if(nAOTInfos == 0) {
            console << "To run an AOT enabled avmshell you must link in some AOT compiled ABC blocks.\n";
            return false;
        }
#endif

        // set the default api version
        this->defaultAPIVersion = settings.api;
        this->setActiveAPI(ApiUtils::toAPI(this, this->defaultAPIVersion));

        this->defaultBugCompatibilityVersion = settings.swfVersion;
        this->bugzilla444630 = (this->defaultBugCompatibilityVersion >= BugCompatibility::kSWF10);

        // This is obscure but well-defined: the clearing of this flag is allowed
        // at any time, see comment for checkFixedMemory in GCHeap.h.
        if (!settings.fixedcheck)
            MMgc::GCHeap::GetGCHeap()->Config().clearCheckFixedMemory();

        config.interrupts = settings.interrupts;
#ifdef VMCFG_VERIFYALL
        config.verifyall = settings.verifyall;
        config.verifyonly = settings.verifyonly;
#endif
        config.jitordie = settings.jitordie;
#ifdef VMCFG_NANOJIT
        config.njconfig = settings.njconfig;
#endif

#ifdef AVMPLUS_VERBOSE
        if (settings.do_verbose & VB_builtins)
            config.verbose_vb = settings.do_verbose;  // ~builtins then skip verbose settings during setup()
#endif
        config.runmode = settings.runmode;

#if VMCFG_METHOD_NAMES
        // verbose requires methodnames (in avmshell, anyway), before calling initBuiltinPool.
        if (settings.do_verbose)
            config.methodNames = true;
    #ifdef DEBUGGER
        // debugger in avmshell always enables methodnames.
        if (allowDebugger)
            config.methodNames = true;
    #endif
#endif // VMCFG_METHOD_NAMES

#ifdef DEBUGGER
        langID = settings.langID;
#endif

        TRY(this, kCatchAction_ReportAsError)
        {
            setStackLimit();

            allowDebugger = !settings.nodebugger;

            setCacheSizes(settings.cacheSizes);

            SystemClass::user_argc = settings.numargs;
            SystemClass::user_argv = settings.arguments;

#ifdef DEBUGGER
            initBuiltinPool((avmplus::Debugger::TraceLevel)settings.astrace_console);
#else
            initBuiltinPool();
#endif
            initShellPool();

            // init toplevel internally
            shell_toplevel = createShellToplevel();

            // Create a new Domain/DomainEnv for the user code
            Domain* user_domain = Domain::newDomain(this, shell_domain);
            DomainEnv* user_domainEnv = DomainEnv::newDomainEnv(this, user_domain, shell_domainEnv);
            const BugCompatibility* user_bugCompatibility = createBugCompatibility(defaultBugCompatibilityVersion);
            this->user_codeContext = new (GetGC()) ShellCodeContext(user_domainEnv, user_bugCompatibility);

#ifdef AVMPLUS_VERBOSE
            config.verbose_vb = settings.do_verbose;  // builtins is done, so propagate verbose
#endif
            return true;
        }
        CATCH(Exception *exception)
        {
#ifdef DEBUGGER
            if (!(exception->flags & Exception::SEEN_BY_DEBUGGER))
                console << string(exception->atom) << "\n";

            if (exception->getStackTrace())
                console << exception->getStackTrace()->format(this) << '\n';
#else
            // [ed] always show error, even in release mode,
            // see bug #121382
            console << string(exception->atom) << "\n";
#endif /* DEBUGGER */
            return false;
        }
        END_CATCH
        END_TRY
    }

#ifdef AVMPLUS_VERBOSE
    const char* ShellCore::identifyDomain(Domain* domain) {
        return domain == builtinDomain ? "builtin" : (domain == shell_domain ? "shell" : NULL);
    }
#endif

    int ShellCore::evaluateFile(ShellCoreSettings& settings, const char* filename)
    {
#ifdef VMCFG_AOT
        ScriptBuffer dummyScriptBuffer;
        return handleArbitraryExecutableContent(dummyScriptBuffer, NULL);
#endif

        if (config.interrupts)
            Platform::GetInstance()->setTimer(kScriptTimeout, interruptTimerCallback, this);

#ifdef AVMPLUS_VERBOSE
        if (config.verbose_vb)
            console << "run " << filename << "\n";
#endif

        FileInputStream f(filename);
        bool isValid = f.valid() && ((uint64_t)f.length() < UINT32_T_MAX); //currently we cannot read files > 4GB
        if (!isValid) {
            console << "cannot open file: " << filename << "\n";
            return(1);
        }

        // parse new bytecode
        ScriptBuffer code = newScriptBuffer((size_t)f.available());
        f.read(code.getBuffer(), (size_t)f.available());

#ifdef DEBUGGER
        if (settings.enter_debugger_on_launch)
        {
            // Activate the debug CLI and stop at
            // start of program
            debugCLI()->activate();
            debugCLI()->stepInto();
        }
#else
        // placate MSVC - settings is unreferenced if this is not here
        (void)settings.enter_debugger_on_launch;
#endif

        return handleArbitraryExecutableContent(code, filename);
    }

    int ShellCore::handleArbitraryExecutableContent(ScriptBuffer& code, const char * filename)
    {
        setStackLimit();

        TRY(this, kCatchAction_ReportAsError)
        {
#ifdef VMCFG_AOT
            if (filename == NULL) {
                handleAOT(shell_toplevel, user_codeContext);
            } else
#endif
            if (AbcParser::canParse(code) == 0) {
                #ifdef VMCFG_VERIFYALL
                if (config.verbose_vb & VB_verify)
                    console << "ABC " << filename << "\n";
                #endif

                uint32_t api = this->getAPI(NULL);
                handleActionBlock(code, 0, shell_toplevel, NULL, user_codeContext, api);
            }
            else if (isSwf(code)) {
                #ifdef VMCFG_VERIFYALL
                if (config.verbose_vb & VB_verify)
                    console << "SWF " << filename << "\n";
                #endif
                handleSwf(filename, code, shell_toplevel, user_codeContext);
            }
            else {
#ifdef VMCFG_EVAL
                AvmCore* core = shell_toplevel->core();
                if (!core->config.verifyonly) {
                    // FIXME: I'm assuming code is UTF8 - OK for now, but easy to go wrong; it could be 8-bit ASCII
                    String* code_string = decodeBytesAsUTF16String(code.getBuffer(), (uint32_t)code.getSize(), true);
                    String* filename_string = decodeBytesAsUTF16String((uint8_t*)filename, (uint32_t)VMPI_strlen(filename));
                    ScriptBuffer empty;     // With luck: allow the
                    code = empty;           //    buffer to be garbage collected
                    uint32_t api = this->getAPI(NULL);
                    handleActionSource(code_string, filename_string, shell_toplevel, NULL, user_codeContext, api);
                }
#else
                console << "unknown input format in file: " << filename << "\n";
                return(1);
#endif // VMCFG_EVAL
            }
        }
        CATCH(Exception *exception)
        {
            TRY(this, kCatchAction_ReportAsError)
            {
    #ifdef DEBUGGER
                if (!(exception->flags & Exception::SEEN_BY_DEBUGGER))
                {
                    console << string(exception->atom) << "\n";
                }
                if (exception->getStackTrace()) {
                    console << exception->getStackTrace()->format(this) << '\n';
                }
    #else
                // [ed] always show error, even in release mode,
                // see bug #121382
                console << string(exception->atom) << "\n";
    #endif /* DEBUGGER */
            }
            CATCH(Exception * e2)
            {
                (void)e2;
                console << "Sorry, an exception occurred but could not be reported\n";
            }
            END_CATCH
            END_TRY

            return 1;
        }
        END_CATCH
        END_TRY

        return 0;
    }

}

