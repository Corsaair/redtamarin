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


#ifdef AVMPLUS_SHELL
#include "avmshell.h"
#else
// player
#include "platformbuild.h"
#include "avmplayer.h"
#endif

#ifdef WIN32
    #include <io.h>
    #define access _access
    #define F_OK 0
    #define W_OK 2
    #define R_OK 4
    #include <direct.h>
	#define getcwd _getcwd
    #define chdir _chdir
    #include <windows.h>
	#define sleep Sleep
#else
    #include <unistd.h>
#endif

namespace avmshell
{
    UnistdClass::UnistdClass(VTable *cvtable)
	: ClassClosure(cvtable)
	{		
		createVanillaPrototype();
        
	}
    
    UnistdClass::~UnistdClass()
    {
        
    }
    
    int UnistdClass::get_F_OK()
    {
        return F_OK;
    }
    
    int UnistdClass::get_W_OK()
    {
        return W_OK;
    }
    
    int UnistdClass::get_R_OK()
    {
        return R_OK;
    }
    
    int UnistdClass::__access( Stringp path, int mode )
    {
        if( !path )
        {
			toplevel()->throwArgumentError(kNullArgumentError, "path");
		}
        
        UTF8String *pathUTF8 = path->toUTF8String();
        return access( pathUTF8->c_str(), mode );
    }
    
    int UnistdClass::__chdir( Stringp path )
    {
        if( !path )
        {
			toplevel()->throwArgumentError(kNullArgumentError, "path");
		}
        
        UTF8String *pathUTF8 = path->toUTF8String();
        return chdir( pathUTF8->c_str() );
    }
    
    Stringp UnistdClass::__getcwd()
    {
        char path[1024];
        getcwd( path, (size_t)1024 );
        Stringp s = core()->newString( path );
        return s;
    }
    
    Stringp UnistdClass::__gethostname()
    {
        #ifdef WIN32
        DWORD nSize = 255;
        char name[256];
        Stringp s;

        if( GetComputerNameEx( ComputerNameNetBIOS, name, &nSize ) == FALSE )
        {
            s = core()->kEmptyString;
        }
        else
        {
            s = core()->newString( name );
        }
        
        return s;

        #else
        char name[256];
        int result = gethostname( name, (size_t)255 );
        Stringp s;
        
        if( result >= 0 )
        {
            s = core()->newString( name );
        }
        else
        {
            s = core()->kEmptyString;
        }
        
        return s;
        #endif
    }
    
    void UnistdClass::__sleep(uint32 second)
    {
        #ifdef WIN32
            sleep( second * 1000 ); //WIN32 Sleep take millisec
        #else
            sleep( second );
        #endif
    }
        
}	


