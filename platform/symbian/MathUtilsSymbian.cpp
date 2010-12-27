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
 * Portions created by the Initial Developer are Copyright (C) 2004-2007
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

#include <e32math.h>
#include <math.h> // no Symbian equivalent of frexp, ceil, floor.

#include "avmplus.h"

namespace avmplus
{
	double MathUtils::abs(double value)
	{
		return ::fabs(value);
	}
	
	double MathUtils::acos(double value)
	{
		double result;
		Math::ACos(result, value);
		return result;
	}
	
	double MathUtils::asin(double value)
	{
		double result;
		Math::ASin(result, value);
		return result;
	}
	
	double MathUtils::atan(double value)
	{
		double result;
		Math::ATan(result, value);
		return result;
	}

	double MathUtils::atan2(double y, double x)
	{
		bool xnan = (((int*)(&x))[1] & 0x7FF80000) == 0x7FF80000;
		bool ynan = (((int*)(&y))[1] & 0x7FF80000) == 0x7FF80000;
		
		if (xnan || ynan)
		{
			return nan();
		}

		int sx = (((int*)(&x))[1] & 0x80000000);
		int sy = (((int*)(&y))[1] & 0x80000000);
		
		if (y == 0.0)
		{
			if (sy) // y is -0
			{
				if (sx) // x is <0 or -0
				{
					return -KPi;
				}
				else // x is >0 or +0
				{
					return -0.0;
				}
			}
			else // y is +0
			{
				if (sx) // x is <0 or -0
				{
					return KPi;
				}
				else // x is >0 or +0
				{
					return +0.0;
				}
			}
		}
		double result;
		Math::ATan(result, y, x);
		return result;
	}
	
	double MathUtils::ceil(double value)
	{
		return ::ceil(value);
	}

	double MathUtils::cos(double value)
	{
		double result;
		Math::Cos(result, value);
		return result;
	}
	
	double MathUtils::exp(double value)
	{
		double result;
		Math::Exp(result, value);
		return result;
	}

	double MathUtils::floor(double value)
	{
		return ::floor(value);
	}

	uint64_t MathUtils::frexp(double value, int *eptr)
	{
		double fracMantissa = ::frexp(value, eptr);
		// correct mantissa and eptr to get integer values for both
		*eptr -= 53; // 52 mantissa bits + the hidden bit
		return (uint64_t)(fracMantissa * (double)(1LL << 53));
	}
	
	// The log function wants the natural log, not the base 10 log.
	double MathUtils::log(double value)
	{
		double result;
		Math::Ln(result, value);
		return result;
	}

	double fmod(double x, double y)
	{
		double result;
		Math::Mod(result, x, y);
		return result;
	}

	double MathUtils::mod(double x, double y)
	{
		double result;
		Math::Mod(result, x, y);
		return result;
	}

	double MathUtils::powInternal(double x, double y)
	{
		double result;
		Math::Pow(result, x, y);
		return result;
	}
	
	double MathUtils::sin(double value)
	{
		double result;
		Math::Sin(result, value);
		return result;
	}

	double MathUtils::sqrt(double value)
	{
		double result;
		Math::Sqrt(result, value);
		return result;
	}

	double MathUtils::tan(double value)
	{
		double result;
		Math::Tan(result, value);
		return result;
	}
}
