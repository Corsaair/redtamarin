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

//unix/solaris

#include "avmshell.h"
#include "PosixPartialPlatform.h"

#include <e32base.h>
#include <e32std.h>

namespace avmshell
{
	class SymbianPlatform : public PosixPartialPlatform
	{
	public:
		SymbianPlatform(void* stackbase) : stackbase(stackbase), f(NULL) {}
		virtual ~SymbianPlatform() { fclose(f); }

		virtual void initializeLogging(const char* filename);
		virtual int logMessage(const char* message);
		
		virtual void exit(int /*code*/) {}

		virtual void setTimer(int seconds, AvmTimerCallback callback, void* callbackData);
		virtual uintptr_t getMainThreadStackLimit();
		
	private:
		void* stackbase;
		FILE *f;
	};
	
	void SymbianPlatform::initializeLogging(const char* filename)
	{
		f = freopen(filename, "w", stdout);
		if (!f)
			AvmLog("freopen %s failed.\n",filename);
	}
	
	int SymbianPlatform::logMessage(const char* message)
	{
		int ret = fprintf(stdout, "%s", message);
		fflush(stdout);
		return ret;
	}
	
	//AvmTimerCallback pCallbackFunc = 0;
	//void* pCallbackData = 0;
	
	uintptr_t SymbianPlatform::getMainThreadStackLimit()
	{
		TThreadStackInfo info;
		RThread currentThread;
		currentThread.StackInfo(info);
		return uintptr_t(info.iLimit) + avmshell::kStackMargin;
	}
	
	void SymbianPlatform::setTimer(int /*seconds*/, AvmTimerCallback /*callback*/, void* /*callbackData*/)
	{
		// TODO. Symbian Posix library does not have signals, timer should be implemented using other Symbian API.
	}
}

avmshell::SymbianPlatform* gPlatformHandle = NULL;

avmshell::Platform* avmshell::Platform::GetInstance()
{
	AvmAssert(gPlatformHandle != NULL);
	return gPlatformHandle;
}

_LIT(kProcessName, "AVMPLUSSHELL");

void RunTestL()
{
	// Create active scheduler (to run active objects)
	CActiveScheduler* scheduler = new (ELeave) CActiveScheduler();
	CleanupStack::PushL(scheduler);
	CActiveScheduler::Install(scheduler);

	// Rename the process so TestShell can find it
	RProcess process;
	process.RenameMe(kProcessName);

	char* dummy;
	avmshell::SymbianPlatform platformInstance(&dummy);
	gPlatformHandle = &platformInstance;

	int argc = 3;
	char* argv[3];
	argv[0] = 0;
	argv[1] = "-log";
	argv[2] = "c:/data/avmplus_file.abc\0";

	/*int code = */avmshell::Shell::run(argc, argv);
	/*
	if (code == avmshell::OUT_OF_MEMORY) {
	write(1, "OUT OF MEMORY\n", 14);
	}
	*/
	// Delete active scheduler
	CleanupStack::PopAndDestroy(scheduler);
}

GLDEF_C TInt E32Main()
{
//	__UHEAP_MARK;
	CTrapCleanup* cleanup = CTrapCleanup::New();
	TInt result = KErrNoMemory;
	if (cleanup)
	{
		TRAP(result, RunTestL());
        delete cleanup;
	}
//	__UHEAP_MARKEND;
	return result;
}
