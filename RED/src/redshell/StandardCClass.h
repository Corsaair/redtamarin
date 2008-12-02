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
 *   Zwetan Kjukov <zwetan@gmail.com>.
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

#ifndef __avmshell_StandardCClass__
#define __avmshell_StandardCClass__


namespace avmshell
{
	/**
	 * A simple class that has some native methods.
	 * Included as an example for writers of native methods,
	 * and also to provide some useful QA instrumentation.
	 */
	class StandardCClass : public ClassClosure
	{
    
	public:
		StandardCClass(VTable* cvtable);
		~StandardCClass();
		
        int stdlibEXIT_SUCCESS();
        
        int stdlibEXIT_FAILURE();
        
        int stdlibRand();
        
        void stdlibAbort();
        
        void stdlibExit( int status );
        
		Stringp stdlibGetenv(Stringp name);
        
        int stdlibSetenv(Stringp name, Stringp value, int rewrite);
		
        int stdlibSystem(Stringp command);
        
        int unistdAccess( Stringp path, int mode );
        
        int unistdChdir( Stringp path );
        
        Stringp unistdGetcwd();
        
        void unistdSleep(uint32 second);
        
        void errnoSeterrno(int value);
        
        int errnoGeterrno();
        
        Stringp stringStrerror(int errnum);
        
        
        
        /*double timeGetCLOCKS_PER_SEC();*/
        
        /*double timeClock();*/
        
        
        /* static DRCWB(ScriptObject*) atexit_callback; */
        
        /* void registerAtexit(ScriptObject* f); */
        
        /* static void callAtexit(); */
        
        int socketSOCK_STREAM();
        
        int socketSOCK_DGRAM();
        
        int socketSOCK_RAW();
        
        int socketSOCK_RDM();
        
        int socketSOCK_SEQPACKET();
        
        int socketAF_UNSPEC();
        
        int socketAF_UNIX();
        
        int socketAF_LOCAL();
        
        int socketAF_INET();
        
        int socketSocket(int domain, int type, int protocol);
        
		DECLARE_NATIVE_MAP(StandardCClass)
    };
}

#endif /* __avmshell_StandardCClass__ */
