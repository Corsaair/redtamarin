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

#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>

#ifdef WIN32
    #include <windows.h>
    #include <direct.h>
    #include <io.h>
	#define getcwd _getcwd
	#define sleep Sleep
    #define setenv _putenv
    #define access _access
    #define chdir _chdir
#else
    #include <unistd.h>
#endif

namespace avmshell
{
	BEGIN_NATIVE_MAP(StandardCClass)
		NATIVE_METHOD(C_stdlib_rand,             StandardCClass::stdlibRand)
        NATIVE_METHOD(C_stdlib_abort,            StandardCClass::stdlibAbort)
        NATIVE_METHOD(C_stdlib__exit,            StandardCClass::stdlibExit)
        NATIVE_METHOD(C_stdlib_getenv,           StandardCClass::stdlibGetenv)
        NATIVE_METHOD(C_stdlib_setenv,           StandardCClass::stdlibSetenv)
        NATIVE_METHOD(C_stdlib_system,           StandardCClass::stdlibSystem)
        NATIVE_METHOD(C_unistd_access,           StandardCClass::unistdAccess)
        NATIVE_METHOD(C_unistd_chdir,            StandardCClass::unistdChdir)
        NATIVE_METHOD(C_unistd_getcwd,           StandardCClass::unistdGetcwd)
        NATIVE_METHOD(C_unistd_sleep,            StandardCClass::unistdSleep)
        NATIVE_METHOD(C_errno_errno_set,         StandardCClass::errnoSeterrno)
        NATIVE_METHOD(C_errno_errno_get,         StandardCClass::errnoGeterrno)
        NATIVE_METHOD(C_string_strerror,         StandardCClass::stringStrerror)
	END_NATIVE_MAP()
	
	StandardCClass::StandardCClass(VTable *cvtable)
		: ClassClosure(cvtable)
	{
		createVanillaPrototype();
	}
    
	StandardCClass::~StandardCClass()
	{
		
	}
    
    int StandardCClass::stdlibRand()
    {
        return rand();
    }
    
    void StandardCClass::stdlibAbort()
    {
        ::abort();
    }
    
    void StandardCClass::stdlibExit( int status )
    {
        ::exit( status );
    }
    
	Stringp StandardCClass::stdlibGetenv(Stringp name)
	{
        if( !name )
        {
			toplevel()->throwArgumentError(kNullArgumentError, "name");
		}
        
        UTF8String* nameUTF8 = name->toUTF8String();
        char *str = getenv( nameUTF8->c_str() );
        Stringp s = core()->newString( str );
        
        return s;
	}
    
    int StandardCClass::stdlibSetenv(Stringp name, Stringp value, int rewrite)
    {
        if( !name )
        {
			toplevel()->throwArgumentError(kNullArgumentError, "name");
		}
        
        if( !value )
        {
			toplevel()->throwArgumentError(kNullArgumentError, "value");
		}
        
        UTF8String *nameUTF8  = name->toUTF8String();
        
		#ifdef WIN32
			AvmCore* core = this->core();
			Stringp original  = core->newString( getenv( nameUTF8->c_str() ) );
			Stringp envstring = core->concatStrings(name, core->newString("=") ); // name=
            
			if( (rewrite == 0) && (original->length() > 0) )
			{
				return 0;
			}
			envstring = core->concatStrings(envstring,value);    // name=value
			
			UTF8String *envstringUTF8 = envstring->toUTF8String();
			return setenv( envstringUTF8->c_str() );
		#else
			UTF8String *valueUTF8 = value->toUTF8String();
			return setenv( nameUTF8->c_str(), valueUTF8->c_str(), rewrite );
		#endif
    }
    
    int StandardCClass::stdlibSystem(Stringp command)
    {
        if( !command )
        {
			toplevel()->throwArgumentError(kNullArgumentError, "command");
		}
		
        UTF8String *commandUTF8 = command->toUTF8String();
		return system( commandUTF8->c_str() );
    }
    
    
    int StandardCClass::unistdAccess( Stringp path, int mode )
    {
        if( !path )
        {
			toplevel()->throwArgumentError(kNullArgumentError, "path");
		}
        
        UTF8String *pathUTF8 = path->toUTF8String();
        return access( pathUTF8->c_str(), mode );
    }
    
    int StandardCClass::unistdChdir( Stringp path )
    {
        if( !path )
        {
			toplevel()->throwArgumentError(kNullArgumentError, "path");
		}
        
        UTF8String *pathUTF8 = path->toUTF8String();
        return chdir( pathUTF8->c_str() );
    }
    
    Stringp StandardCClass::unistdGetcwd()
    {
        char path[1024];
        getcwd( path, (size_t)1024 );
        Stringp s = core()->newString( path );
        return s;
    }
    
    void StandardCClass::unistdSleep(uint32 second)
    {
        #ifdef WIN32
            sleep( second * 1000 ); //WIN32 Sleep take millisec
        #else
            sleep( second );
        #endif
    }
    
    void StandardCClass::errnoSeterrno(int value)
    {
        errno = value;
    }
    
    int StandardCClass::errnoGeterrno()
    {
        return errno;
    }
    
    Stringp StandardCClass::stringStrerror(int errnum)
    {
        char *errstr = strerror(errnum);
        Stringp s = core()->newString( errstr );
        return s;
    }
    
    /* note:
       does not work, better to use Date and getTimer
    */
    /*
    double StandardCClass::timeGetCLOCKS_PER_SEC()
    {
        return (double) CLOCKS_PER_SEC;
    }
    
    double StandardCClass::timeClock()
    {
        return (double) ::clock();
    }
    
    double StandardCClass::timeGetClock()
    {
        return (double) clock() * (double) CLOCKS_PER_SEC;
    }
    */
    
    /* note:
       crashes
       you can store and call an AS function from C
       but you can not use it with atexit
    */
    /*
    DRCWB(ScriptObject*) StandardCClass::atexit_callback;
    
    void StandardCClass::registerAtexit(ScriptObject* f)
    {
        atexit_callback = f;
        atexit( callAtexit );
        (void)f;
    }
    
    void StandardCClass::callAtexit()
    {
        Atom argv[1] = { atexit_callback->atom() };
        atexit_callback->call( 0, argv );
    }
    */
    
}
