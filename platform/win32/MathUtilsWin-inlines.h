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

#include <math.h>

#ifdef AVMPLUS_IA32
#define X86_MATH
#endif

// warning this code is used by amd64 and arm builds

namespace avmplus
{

    REALLY_INLINE double MathUtils::abs(double value)
    {
#ifdef X86_MATH
        _asm fld [value];
        _asm fabs;
#else
        return ::fabs(value);
#endif /* X86_MATH */
    }

#ifdef X86_MATH
    REALLY_INLINE double MathUtils::atan2(double y, double x)
    {
        _asm fld [y];
        _asm fld [x];
        _asm fpatan;
    }
#elif !defined(AVMPLUS_ARM)
    REALLY_INLINE double MathUtils::atan2(double y, double x)
    {
        return ::atan2(y,x);
    }
#endif /* X86_MATH */

    REALLY_INLINE double MathUtils::acos(double value)
    {
#ifdef X86_MATH
        // atan2 and sqrt are hardware instructions on x86
        return MathUtils::atan2(MathUtils::sqrt(1.0-value*value), value);
#else
        return ::acos(value);
#endif /* X86_MATH */
    }

    REALLY_INLINE double MathUtils::asin(double value)
    {
#ifdef X86_MATH
        // atan2 and sqrt are hardware instructions on x86
        return MathUtils::atan2(value, MathUtils::sqrt(1.0-value*value));
#else
        return ::asin(value);
#endif /* X86_MATH */
    }

    REALLY_INLINE double MathUtils::atan(double value)
    {
#ifdef X86_MATH
        _asm fld [value];
        _asm fld1;
        _asm fpatan;
#else
        return ::atan(value);
#endif /* X86_MATH */
    }

#ifndef X86_MATH
    REALLY_INLINE double MathUtils::ceil(double value)
    {
        return ::ceil(value);
    }
#endif /* X86_MATH */

#ifdef X86_MATH
    REALLY_INLINE double MathUtils::cos(double value)
    {
        _asm fld [value];
        _asm fcos;
    }
#elif !defined(AVMPLUS_ARM)
    REALLY_INLINE double MathUtils::cos(double value)
    {
        return ::cos(value);
    }
#endif /* X86_MATH */

#ifndef X86_MATH
    REALLY_INLINE double MathUtils::exp(double value)
    {
        return ::exp(value);
    }
#endif /* X86_MATH */

#ifndef X86_MATH
    REALLY_INLINE double MathUtils::floor(double value)
    {
        return ::floor(value);
    }
#endif /* X86_MATH */

    REALLY_INLINE double MathUtils::log(double value)
    {
#ifdef X86_MATH
        _asm fld [value];
        _asm fldln2;
        _asm fxch;
        _asm fyl2x;
#else
        return ::log(value);
#endif /* X86_MATH */
    }

#ifndef X86_MATH
#ifdef UNDER_CE
    REALLY_INLINE double MathUtils::mod(double x, double y)
    {
        if (!y) {
            return kNaN;
        }
        return ::fmod(x, y);
    }
#else
    extern "C" {
        // See win64setjmp.asm
        double modInternal(double x, double y);
    }

    REALLY_INLINE double MathUtils::mod(double x, double y)
    {
        if (!y) {
            return kNaN;
        }
        return modInternal(x, y);
    }
#endif /* UNDER_CE */
#endif /* X86_MATH */

#ifndef X86_MATH
    REALLY_INLINE double MathUtils::powInternal(double x, double y)
    {
        return ::pow(x, y);
    }
#endif /* X86_MATH */

#ifdef X86_MATH
    REALLY_INLINE double MathUtils::sin(double value)
    {
        _asm fld [value];
        _asm fsin;
    }
#elif !defined(AVMPLUS_ARM)
    REALLY_INLINE double MathUtils::sin(double value)
    {
        return ::sin(value);
    }
#endif /* X86_MATH */

#if !defined(X86_MATH) && !defined(AVMPLUS_ARM)
    REALLY_INLINE double MathUtils::tan(double value)
    {
        return ::tan(value);
    }
#endif /* !defined(X86_MATH) && !defined(AVMPLUS_ARM) */

    REALLY_INLINE double MathUtils::sqrt(double value)
    {
#ifdef X86_MATH
        _asm fld [value];
        _asm fsqrt;
#else
        return ::sqrt(value);
#endif /* X86_MATH */
    }

}
