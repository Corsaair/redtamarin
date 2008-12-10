/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: t; tab-width: 4 -*- */
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


#include "MMgc.h"

#if !defined(__MWERKS__) && !defined(MMGC_MAC_NO_CORE_SERVICES)
    #include <CoreServices/CoreServices.h>
#endif

#ifndef __MACH__
	#include <windows.h>
#endif

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#if defined(MMGC_CUSTOM_DEBUG_MESSAGE_HANDLER)
	void MMGCCustomDebugMessageHandler(const char *message);
#endif

namespace MMgc
{
	void GCDebugMsg(bool debuggerBreak, const char* format, ...)
	{
#ifdef _DEBUG
		char buf[4096];
		va_list args;
		va_start(args, format);

		vsprintf(buf, format, args);
		va_end(args);
		GCDebugMsg(buf, debuggerBreak);
#else
		(void)debuggerBreak;
		(void)format;
#endif
	}

	void GCDebugMsg(const char* p, bool debugBreak)
	{
#ifdef _DEBUG
        #if defined(MMGC_CUSTOM_DEBUG_MESSAGE_HANDLER)
			MMGCCustomDebugMessageHandler(p);
		#elif defined(MMGC_MAC_NO_CORE_SERVICES)
			fprintf(stderr, "%s\n", p);
		#else
		    CFStringRef cfStr = ::CFStringCreateWithCString(NULL, p, kCFStringEncodingUTF8);

			if(debugBreak)
			{
				Str255 buf;
				CFStringGetPascalString (cfStr, buf, 255, kCFStringEncodingUTF8);
				DebugStr(buf);
				exit(1);	// ensure we die
			}
			else
			{
				::CFShow(cfStr);
			}

			::CFRelease (cfStr);
		#endif
#else
		(void)p;
		(void)debugBreak;
#endif
	}
}
