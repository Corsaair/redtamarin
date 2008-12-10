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


#include "avmplus.h"

#if defined(AVMPLUS_AMD64) && defined(_WIN64)
	extern "C"
	{
		_int64 __cdecl longjmp64(jmp_buf jmpbuf, _int64 arg);
	}
#endif

namespace avmplus
{
	//
	// Exception
	//

	Exception::Exception(Atom atom
#ifdef DEBUGGER
			, AvmCore* core
#endif /* DEBUGGER */
		)
	{
		this->atom = atom;
		this->flags = 0;

        #ifdef DEBUGGER
		// If the exception atom is an Error object, copy its stack trace.
		// Otherwise, generate a new stack trace.
		if (core->istype(atom, core->traits.error_itraits))
		{
			stackTrace = ((ErrorObject*)AvmCore::atomToScriptObject(atom))->getStackTraceObject();
		}
		else
		{
			stackTrace = core->newStackTrace();
		}
		#endif
	}
	
	bool Exception::isValid()
	{
		return (atom&7)==kObjectType;
	}
	
	//
	// ExceptionHandlerTable
	//
	
	ExceptionHandlerTable::ExceptionHandlerTable(int exception_count)
	{
		this->exception_count = exception_count;
		memset(exceptions, 0, sizeof(ExceptionHandler)*exception_count);
	}
	
	//
	// ExceptionFrame
	//

#if defined(AVMPLUS_AMD64) && !defined(_WIN64)
	// FIXME: This is a temporary approach.
	void *ExceptionFrame::lptr[MAX_LONG_JMP_COUNT] = {0};
	int   ExceptionFrame::lptrcounter = 1;
#endif //#if defined(AVMPLUS_AMD64) && !defined(_WIN64)

	void ExceptionFrame::beginTry(AvmCore* core)
	{
		this->core = core;

		prevFrame = core->exceptionFrame;

		if (!prevFrame) {
			// Do special setup for first frame
			core->setStackBase();
		}

		core->exceptionFrame = this;

#ifdef DEBUGGER
		callStack = core->callStack;

		// beginTry() is called from both the TRY macro and from JIT'd code.  The TRY
		// macro will immediately change the value of catchAction right after the
		// call to beginTry(); but the JIT'd code does not change catchAction.  So,
		// we initialize catchAction to the value that it needs when we're called
		// from JIT'd code, that is, kCatchAction_SearchForActionScriptExceptionHandler.
		catchAction = kCatchAction_SearchForActionScriptExceptionHandler;
#endif /* DEBUGGER */
		this->stacktop = core->allocaTop();
		
		codeContextAtom = core->codeContextAtom;
		dxnsAddr = core->dxnsAddr;
	}

	void ExceptionFrame::endTry()
	{
		if (core) {
			// ISSUE do we need to check core if it is set in constructor?
			core->exceptionFrame = prevFrame;

			// Restore the code context to what it was before the try
			core->codeContextAtom = codeContextAtom;
			
			core->allocaPopTo(this->stacktop);
		}
	}
	
	void ExceptionFrame::throwException(Exception *exception)
	{
		core->exceptionAddr = exception;
#if defined(AVMPLUS_AMD64) && defined(_WIN64)
		longjmp64(jmpbuf, (uintptr)exception); 
#elif defined(AVMPLUS_AMD64)
		// This is an amazingly gross hack.  I don't know why it's necessary, but it must be fixed.  (lhansen 2008-11-26)
		// https://bugzilla.mozilla.org/show_bug.cgi?id=464643
		//
		// Never allow memory to be corrupted in release builds, exit instead.
		AvmAssert(lptrcounter<MAX_LONG_JMP_COUNT);
		if (lptrcounter>=MAX_LONG_JMP_COUNT)
			exit(1);
		lptr[lptrcounter++] = exception;
		longjmp(jmpbuf, (lptrcounter-1)*sizeof(void *)); 
#else
		longjmp(jmpbuf, (int)(uintptr)exception); 
#endif
	}

	void ExceptionFrame::beginCatch()
	{
		core->exceptionFrame = prevFrame;

#ifdef DEBUGGER
		//AvmAssert(callStack && callStack->env);
		if (core->profiler && core->profiler->profilingDataWanted && callStack && callStack->env())
			core->profiler->sendCatch(callStack->env()->method);

		core->callStack = callStack;
#endif // DEBUGGER
		core->allocaPopTo(this->stacktop);
		core->codeContextAtom = codeContextAtom;
		core->dxnsAddr = dxnsAddr;
	}
}
