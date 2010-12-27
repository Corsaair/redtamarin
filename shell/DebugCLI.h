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

#ifndef __avmshell_AvmDebugCLI__
#define __avmshell_AvmDebugCLI__

#ifdef DEBUGGER
namespace avmshell
{
    /**
     * Represents a single breakpoint in the Debugger.
     */
    class BreakAction : public MMgc::GCObject
    {
    public:
        DWB(BreakAction*) prev;
        DWB(BreakAction*) next;
        DWB(SourceFile*) sourceFile;
        int id;
        DRCWB(Stringp) filename;
        int linenum;

        BreakAction(SourceFile *sourceFile,
                    int id,
                    Stringp filename,
                    int linenum)
        {
            this->sourceFile = sourceFile;
            this->id = id;
            this->filename = filename;
            this->linenum = linenum;
        }

        void print(PrintWriter& out);
    };

    /**
     * This can be either an l-value or an r-value.
     */
    class IValue : public MMgc::GCFinalizedObject
    {
    public:
        virtual ~IValue() {}

        virtual bool isLValue() = 0;
        virtual Atom get() = 0;
        virtual void set(Atom newValue) = 0;
    };

    class ConstantValue: public IValue
    {
    public:
        ConstantValue(Atom value) : value(value) { }

        virtual bool isLValue() { return false; }
        virtual Atom get() { return value; }
        virtual void set(Atom /*newValue*/) { AvmAssert(false); }

    private:
        ATOM_WB value;
    };

    /**
     * An IValue representing a local variable.
     */
    class LocalValue: public IValue
    {
    public:
        LocalValue(DebugFrame* frame, int index) : frame(frame), index(index) { }

        virtual bool isLValue() { return true; }
        virtual Atom get()
        {
            Atom* locals;
            int countLocals;
            frame->locals(locals, countLocals);
            return locals[index];
        }
        virtual void set(Atom newValue)
        {
            frame->setLocal(index, newValue);
        }

    private:
        DWB(DebugFrame*) frame;
        int index;
    };

    /**
     * An IValue representing an argument to a function.
     */
    class ArgumentValue: public IValue
    {
    public:
        ArgumentValue(DebugFrame* frame, int index) : frame(frame), index(index) { }

        virtual bool isLValue() { return true; }
        virtual Atom get()
        {
            Atom* arguments;
            int countArguments;
            frame->arguments(arguments, countArguments);
            return arguments[index];
        }
        virtual void set(Atom newValue)
        {
            frame->setArgument(index, newValue);
        }

    private:
        DWB(DebugFrame*) frame;
        int index;
    };

    /**
     * An IValue representing a property of an object.
     */
    class PropertyValue: public IValue
    {
    public:
        PropertyValue(ScriptObject* parent, Multiname& propertyname)
            : parent(parent), propertyname(propertyname) { }

        virtual bool isLValue() { return true; }
        virtual Atom get()
        {
            return parent->toplevel()->getproperty(parent->atom(), propertyname, parent->vtable);
        }
        virtual void set(Atom newValue)
        {
            parent->toplevel()->setproperty(parent->atom(), propertyname, newValue, parent->vtable);
        }

    private:
        DRCWB(ScriptObject*) parent;
        HeapMultiname propertyname;
    };

    /**
     * A simple command line interface for the Debugger.
     * Supports a gdb-like command line.
     */
    class GC_CPP_EXACT_IFDEF(DebugCLI, avmplus::Debugger, DEBUGGER)
    {
    private:
        DebugCLI(AvmCore *core, Debugger::TraceLevel tracelevel);
    public:
        /** @name command codes */
        /*@{*/
        enum {
            CMD_UNKNOWN = 0,
            CMD_QUIT,
            CMD_CONTINUE,
            CMD_STEP,
            CMD_NEXT,
            CMD_FINISH,
            CMD_BREAK,
            CMD_SET,
            CMD_LIST,
            CMD_PRINT,
            CMD_INFO,
            CMD_DELETE,
            CMD_COMMENT,
            CMD_HELP,
        };
        /*@}*/

        /** @name info sub commands */
        /*@{*/
        enum {
            INFO_UNKNOWN_CMD = 100,
            INFO_ARGS_CMD,
            INFO_BREAK_CMD,
            INFO_FILES_CMD,
            INFO_FUNCTIONS_CMD,
            INFO_LOCALS_CMD,
            INFO_STACK_CMD,
        };
        /*@}*/

        /**
         * StringInt is used to store the command arrays
         * used to translate command strings into command codes
         */
        struct StringInt
        {
            const char *text;
            int id;
        };

        REALLY_INLINE static DebugCLI* create(MMgc::GC* gc, AvmCore *core, Debugger::TraceLevel tracelevel)
        {
            return MMgc::setExact(new (gc) DebugCLI(core, tracelevel));
        }

        ~DebugCLI();

        void enterDebugger();
        void setCurrentSource(Stringp file);
        bool filterException(Exception *exception, bool willBeCaught);
        bool hitWatchpoint() { return false; }

        /**
         * @name command implementations
         */
        /*@{*/
        void breakpoint(char *location);
        void deleteBreakpoint(char *idstr);
        void showBreakpoints();
        void help();
        void locals(int frameNumber);
        void arguments(int frameNumber);

        static void bt();
        static bool printFrame(int frameNumber);
        static bool debuggerInterruptOnEnter;


        void info();
        void set();
        void list(const char* line);
        void print(char *name);
        void quit();
        /*@}*/

        void activate() { activeFlag = true; }

        static MethodInfo* functionFor(SourceInfo* src, int line);

        /**
         * Formats a value for display to the user.  Very similar to
         * AvmCore::format(), but does a few extra things.
         */
        Stringp formatValue(Atom value);

        GC_DATA_BEGIN(DebugCLI)
        
    private:
        bool activeFlag;
        char *currentSource;
        uint32_t currentSourceLen;
        DRCWB(Stringp) GC_POINTER(currentFile);
        int breakpointCount;
        bool warnMissingSource;

        DWB(BreakAction*) GC_POINTER(firstBreakAction);
        DWB(BreakAction*) GC_POINTER(lastBreakAction);

        enum { kMaxCommandLine = 1024 };
        char commandLine[kMaxCommandLine];
        char lastCommand[kMaxCommandLine];
        char *currentToken;
        
        GC_DATA_END(DebugCLI)

        char *nextToken();

        void printIP();
        void displayLines(int linenum, int count);

        char* lineStart(int linenum);
        Atom ease2Atom(const char* to, Atom baseline);

        void throwUndefinedVarError(const char* name);

        /**
         * Gets a value.  "name" can be either a constant (string,
         * number, boolean, undefined, null, xml, xmllist), or the
         * name of a local, argument, or member of a variable on
         * the scope chain.
         */
        IValue* getValue(const char *name);

        /**
         * Evaluates an expression, and returns its value.
         * *outSawTrailingDot is set to true if the expression has a trailing
         * dot, e.g. "foo." or "foo.bar."
         */
        IValue* evaluate(char *expr, bool* outSawTrailingDot);

       /**
         * @name command name arrays and support code
         */
        /*@{*/
        int determineCommand(StringInt cmdList[],
                             const char *input,
                             int defCmd);
        const char* commandNumberToCommandName(StringInt cmdList[],
                                               int cmdNumber);
        int commandFor(const char *input) {
            return determineCommand(commandArray, input, CMD_UNKNOWN);
        }
        int infoCommandFor(const char *input) {
            return determineCommand(infoCommandArray, input, INFO_UNKNOWN_CMD);
        }

        static StringInt commandArray[];
        static StringInt infoCommandArray[];
        /*@}*/
    };

    /**
     * Helper class to iterate over all properties of an object (both slots
     * and dynamic properties).
     */
    class PropertyIterator
    {
    public:
        /**
         * atom: the object whose properties we will iterate over.
         */
        PropertyIterator(AvmCore* core, Atom atom);
        virtual ~PropertyIterator() {}

        /**
         * Iterates over all the object's properties, and calls process()
         * for each one.  If process() ever returns false, iteration halts.
         */
        void iterate();

    protected:
        /**
         * Called once for each property that has been found.  If process()
         * ever returns false, iteration halts.
         */
        virtual bool process(Multiname* key, BindingKind bk) = 0;

        AvmCore* core;
        ScriptObject* object;
    };

    /**
     * Helper to find a property with the given name.  Since this is for the
     * debugger, it ignores visibility issues -- e.g. it will match any property
     * with the given name, even if that property is private and therefore not
     * visible from the caller's context.
     *
     * After you call iterate(), 'value' will be the property's value if it was
     * found, or NULL if it was not found.
     *
     * This class can only be used on the stack.  ('value' does not have a write
     * barrier around it.)
     */
    class StPropertyFinder: public PropertyIterator
    {
    public:
        /**
         * atom:         The object in which we want to look for a property.
         * propertyname: The property name to look for.
         */
        StPropertyFinder(AvmCore* core, Atom atom, const char* propertyname);

        IValue* value;

    protected:
        /**
         * Returns true if the key matches the originally passed-in property name.
         */
        bool matches(const Multiname* key) const;

        virtual bool process(Multiname* key, BindingKind bk);

        const char* propertyname;
    };

    /**
     * Prints all of an object's properties, and their values, to core->console.
     */
    class PropertyPrinter: public PropertyIterator
    {
    public:
        PropertyPrinter(AvmCore* core, DebugCLI* debugger, Atom atom);

    protected:
        virtual bool process(Multiname* key, BindingKind bk);

        DebugCLI* debugger;
    };
}
#endif

#endif /* __avmshell_AvmDebugCLI__ */
