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
 *   zwetan <zwetan@gmail.com>
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

#ifdef AVMPLUS_WIN32
//#include <Fcntl.h>
//#include <errno.h>
//#include <sys/types.h>
//#include <sys/stat.h>
#include <direct.h>
#include <stdlib.h>
#define sleep Sleep
#undef getcwd
#define getcwd _getcwd
#define getdcwd _getdcwd
#undef chdir
#define chdir _chdir
#define chdrive _chdrive
#define getdrive _getdrive
#define getdrives _getdrives
#elif defined AVMPLUS_UNIX
#include <unistd.h>
#endif

#include <string.h>
#include <stdio.h>

namespace avmshell
{
	BEGIN_NATIVE_MAP(StandardClass)
        NATIVE_METHOD(standard__std_errno, StandardClass::std_errno)
		NATIVE_METHOD(standard__std_strerror, StandardClass::std_strerror)
		NATIVE_METHOD(standard__std_getcwd, StandardClass::std_getcwd)
		NATIVE_METHOD(standard__std_getdcwd, StandardClass::std_getdcwd)
		NATIVE_METHOD(standard__std_chdir, StandardClass::std_chdir)
		NATIVE_METHOD(standard__std_chdrive, StandardClass::std_chdrive)
		NATIVE_METHOD(standard__std_getdrive, StandardClass::std_getdrive)
		NATIVE_METHOD(standard__std_getdrives, StandardClass::std_getdrives)
		NATIVE_METHOD(standard__std_sleep, StandardClass::std_sleep)
	END_NATIVE_MAP()
	
	StandardClass::StandardClass(VTable *cvtable)
		: ClassClosure(cvtable)
    {
		createVanillaPrototype();
	}
    
	int StandardClass::std_errno()
	{
		return errno;
	}
	
	Stringp StandardClass::std_strerror(int errnum)
	{
		return core()->newString( strerror(errnum) );
	}

    Stringp StandardClass::std_getcwd()
    {
        return core()->newString( getcwd( NULL, MAX_PATH ) );
    }

    Stringp StandardClass::std_getdcwd(int drive)
    {
        Toplevel* toplevel = this->toplevel();
		
		if (!drive) {
			toplevel->throwArgumentError(kNullArgumentError, "drive");
		}
		
        return core()->newString( getdcwd( drive, NULL, MAX_PATH ) );
    }

    int StandardClass::std_chdir(Stringp pathname)
    {
        Toplevel* toplevel = this->toplevel();

		if (!pathname) {
			toplevel->throwArgumentError(kNullArgumentError, "pathname");
		}
		
		UTF8String* pathnameUTF8 = pathname->toUTF8String();
		return chdir( pathnameUTF8->c_str() );
    }

    int StandardClass::std_chdrive(int newdrive)
    {
        Toplevel* toplevel = this->toplevel();

		if (!newdrive) {
			toplevel->throwArgumentError(kNullArgumentError, "newdrive");
		}
		
		return chdrive( newdrive );
    }

    int StandardClass::std_getdrive()
    {	
		return getdrive();
    }

    ArrayObject * StandardClass::std_getdrives()
    {
        Toplevel* toplevel = this->toplevel();
		AvmCore *core = this->core();

		ULONG driveMask     = getdrives();
		ArrayObject *drives = toplevel->arrayClass->newArray();
		
		if (driveMask == 0)
		{
		//return an empty array
		return drives;
		}
		else
		{
			int i=0;
			while (driveMask)
			{
				if ( driveMask & 1 )
				{
					drives->setUintProperty(i, core->intToAtom( i+1 ) );
				}
				i++;
				driveMask >>= 1;
			}
		}

		return drives;
    }

    void StandardClass::std_sleep(double time)
    {	
		sleep( (DWORD)(time) );
    }

}
