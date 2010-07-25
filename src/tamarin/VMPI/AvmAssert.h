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
 * Portions created by the Initial Developer are Copyright (C) 1993-2006
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


#ifndef __AvmAssert__
#define __AvmAssert__

// AVMPLUS_CUSTOM_ASSERTION_HANDLER not yet (now == Apr-2009) exposed as a feature;
// awaiting cleanup of the debug code (merging MMgc and Avm debug macros, etc)

#if defined(AVMPLUS_CUSTOM_ASSERTION_HANDLER)
    extern "C"
    {
        void AVMPlusCustomAssertionHandler(const char *message);
    }
#endif

namespace avmplus
{
    void AvmDebugMsg(bool debuggerBreak, const char* format, ...);
    void AvmDebugMsg(const char* msg, bool debuggerBreak);
    void AvmDebugMsg(const wchar* msg, bool debuggerBreak);

#if defined DEBUG || defined _DEBUG

    inline void AvmAssertFail(const char *message) {
        #if defined(AVMPLUS_CUSTOM_ASSERTION_HANDLER)
            AVMPlusCustomAssertionHandler(message);
        #else
            AvmDebugMsg(message, true);
        #endif
    }

    inline void _AvmAssertMsg(int32_t condition, const char* message) {
        if (!condition)
            AvmAssertFail(message);
    }

    #define AvmAssert(condition) \
        _AvmAssert((condition), __LINE__,__FILE__)

    #define AvmAssertMsg(condition,message) \
        do { avmplus::_AvmAssertMsg((condition), (message)); } while (0) /* no semi */

    #define _AvmAssert(condition, line_, file_) \
        __AvmAssert((condition), line_, file_)

    #define __AvmAssert(condition, line_, file_) \
        do { AvmAssertMsg((condition), \
                          "Assertion failed: \"" #condition "\" (" #file_ ":" #line_ ")\n"); \
        } while (0) /* no semi */

#else

    #define AvmAssertMsg(condition,message) \
        do { } while (0) /* no semi */

    #define AvmAssert(condition) \
        do { } while (0) /* no semi */

#endif
}

#endif /* __AvmAssert__ */
