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
#include "DateMac.h"

namespace avmplus
{
	double OSDep::getDate()
	{
		// 23apr04 grandma : Warning, Actionscript expects an integer count stored as a double,
		// but (MAC ONLY) this returns two digits of accuracy. The Date object rounds the return
		// from this (for version 8 or greater), and so should you if you are writing new code.
		return MacDateTime::GetTime();
	}
	
	double OSDep::localTZA(double time)
	{
		return MacDateTime::LocalTZA(time);
	}
	
	double OSDep::daylightSavingTA(double time)
	{
		return MacDateTime::DaylightSavingTA(time);
	}
	
	void MicrosecondDelta(register const UnsignedWide *startPtr,
								   	   register const UnsignedWide *endPtr,
								   	   register UnsignedWide *resultPtr)
	{
		if (endPtr->lo >= startPtr->lo) {
			resultPtr->hi = endPtr->hi - startPtr->hi;
		} else {
			resultPtr->hi = (endPtr->hi - 1) - startPtr->hi;
		}
		resultPtr->lo = endPtr->lo - startPtr->lo;
	}

	
	uint64 OSDep::currentTimeMillis()
	{
		return MacDateTime::GetMsecCount();
	}

#ifdef DEBUGGER
	uintptr OSDep::startIntWriteTimer(uint32 millis, int *addr) { return 0; }
	void OSDep::stopTimer(uintptr handle) {}
#endif
}
