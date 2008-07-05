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

#ifndef __avmshell__
#define __avmshell__

#include <stdio.h>
#include <stdlib.h>

#include "avmplus.h"

// interactive shell requires functional external compiler, not yet
// present in Tamarin. commented out for now.
// #define AVMPLUS_INTERACTIVE

using namespace avmplus;

// avmplus and NSPR both typedef some basic types: we must disambiguate
using avmplus::uint64;
using avmplus::uint32;
using avmplus::uint16;
using avmplus::uint8;

namespace avmshell
{
	class ByteArrayObject;
	class ByteArray;
}

namespace avmplus
{
	class Dictionary;
}

#include "FileInputStream.h"
#include "ConsoleOutputStream.h"
#include "SystemClass.h"
#include "StringBuilderClass.h"
#include "FileClass.h"
#include "DomainClass.h"
#include "DebugCLI.h"
#include "Profiler.h"
#include "DataIO.h"
#include "ByteArrayGlue.h"
#include "DictionaryGlue.h"
#include "SamplerScript.h"
#include "JavaGlue.h"

#ifdef _MSC_VER
#pragma warning(disable:4996)
#endif

namespace avmplus
{
	namespace NativeID
	{
        #include "toplevel.h"
    }
}

namespace avmshell
{
	class ShellCodeContext : public CodeContext
	{
	  public:
		DWB(DomainEnv*) m_domainEnv;
		virtual ~ShellCodeContext() {}
		virtual DomainEnv *domainEnv() const { return m_domainEnv; }
	};
	
	/**
	 * A command-line shell around the avmplus core.  This can be
	 * used to execute and debug .abc files from the command line.
	 */
	class Shell : public AvmCore
	{
	public:
		Shell(MMgc::GC *gc);
		void usage();
		int main(int argc, char *argv[]);

		void interrupt(MethodEnv *env);
		void stackOverflow(MethodEnv *env);

		void initShellPool();
		Toplevel* initShellBuiltins();

		void setEnv(Toplevel *toplevel, int argc, char *argv[]);

		SystemClass* systemClass;
		
		virtual Toplevel* createToplevel(VTable *vtable);

		virtual size_t getToplevelSize() const;

		PoolObject* shellPool;

	private:
		DECLARE_NATIVE_CLASSES()
		DECLARE_NATIVE_SCRIPTS()			

		ConsoleOutputStream *consoleOutputStream;
		bool gracePeriod;
		bool inStackOverflow;

		bool executeProjector(int argc, char *argv[], int& exitCode);
		
		void computeStackBase();
		
		#ifdef DEBUGGER
		DebugCLI *debugCLI;
		#endif

		// for interactive
		#ifdef AVMPLUS_INTERACTIVE
		int addToImports(char* imports, char* addition);
		#endif //AVMPLUS_INTERACTIVE
	};

	class AvmplusScript : public ScriptObject
	{

	public:
		AvmplusScript(VTable *vtable, ScriptObject* delegate)
			: ScriptObject(vtable, delegate)
		{
		}


		DECLARE_NATIVE_SCRIPT(AvmplusScript)
	};

	class ShellToplevel : public Toplevel
	{
	public:
		ShellToplevel(VTable* vtable, ScriptObject* delegate);

		Shell* core() const {
			return (Shell*)Toplevel::core();
		}

		virtual ClassClosure *getBuiltinExtensionClass(int class_id) 
		{ 
            return shellClasses[class_id] ? shellClasses[class_id] : resolveShellClass(class_id);
		}

	private:

		ClassClosure* resolveShellClass(int class_id)
		{
			Traits *traits = core()->shellPool->cinits[class_id]->declaringTraits->itraits;
			Multiname qname(traits->ns, traits->name);
			ScriptObject *container = vtable->init->finddef(&qname);

			Atom classAtom = getproperty(container->atom(), &qname, container->vtable);
			ClassClosure *cc = (ClassClosure*)AvmCore::atomToScriptObject(classAtom);
			WBRC(core()->GetGC(), shellClasses, &shellClasses[class_id], cc);
			return cc;
		}

		DWB(ClassClosure**) shellClasses;
	};
}

#endif /* __avmshell__ */
