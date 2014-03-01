/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package C.math
{

	//M_E
    /**
     * Value of <code>e</code>.
     *
     * <p>
     * A mathematical constant for the base of natural logarithms, expressed as <code>e</code>.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const M_E:Number = Math.E;

	//M_LOG2E
	//M_LOG10E
	//M_LN2
	//M_LN10
	//M_PI
	//M_PI_2
	//M_PI_4
	//M_1_PI
	//M_2_PI
	//M_2_SQRTPI
	//M_SQRT2
	//M_SQRT1_2


	//int fpclassify(real-floating x);
	//int isfinite(real-floating x);
	//int isgreater(real-floating x, real-floating y);
	//int isgreaterequal(real-floating x, real-floating y);
	//int isinf(real-floating x);
	//int isless(real-floating x, real-floating y);
	//int islessequal(real-floating x, real-floating y);
	//int islessgreater(real-floating x, real-floating y);
	//int isnan(real-floating x);
	//int isnormal(real-floating x);
	//int isunordered(real-floating x, real-floating y);
	//int signbit(real-floating x);

	
	//double      acos(double);
			//float       acosf(float);
	//double      acosh(double);
			//float       acoshf(float);
			//long double acoshl(long double);
			//long double acosl(long double);
	//double      asin(double);
			//float       asinf(float);
	//double      asinh(double);
			//float       asinhf(float);
			//long double asinhl(long double);
			//long double asinl(long double);
	//double      atan(double);
	//double      atan2(double, double);
			//float       atan2f(float, float);
			//long double atan2l(long double, long double);
			//float       atanf(float);
	//double      atanh(double);
			//float       atanhf(float);
			//long double atanhl(long double);
			//long double atanl(long double);
	//double      cbrt(double);
			//float       cbrtf(float);
			//long double cbrtl(long double);
	//double      ceil(double);
			//float       ceilf(float);
			//long double ceill(long double);
	//double      copysign(double, double);
			//float       copysignf(float, float);
			//long double copysignl(long double, long double);
	//double      cos(double);
			//float       cosf(float);
	//double      cosh(double);
			//float       coshf(float);
			//long double coshl(long double);
			//long double cosl(long double);
	//double      erf(double);
	//double      erfc(double);
			//float       erfcf(float);
			//long double erfcl(long double);
			//float       erff(float);
			//long double erfl(long double);
	//double      exp(double);
	//double      exp2(double);
			//float       exp2f(float);
			//long double exp2l(long double);
			//float       expf(float);
			//long double expl(long double);
	//double      expm1(double);
			//float       expm1f(float);
			//long double expm1l(long double);
	
	//double      fabs(double);
    /**
     * Absolute value function.
     *
     * <p>
     * This function shall compute the absolute value of its argument <code>x</code>.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function fabs( x:Number ):Number { return Math.abs( x ); }

			//float       fabsf(float);
			//long double fabsl(long double);
	//double      fdim(double, double);
			//float       fdimf(float, float);
			//long double fdiml(long double, long double);
	//double      floor(double);
			//float       floorf(float);
			//long double floorl(long double);
	//double      fma(double, double, double);
			//float       fmaf(float, float, float);
			//long double fmal(long double, long double, long double);
	//double      fmax(double, double);
			//float       fmaxf(float, float);
			//long double fmaxl(long double, long double);
	//double      fmin(double, double);
			//float       fminf(float, float);
			//long double fminl(long double, long double);
	//double      fmod(double, double);
			//float       fmodf(float, float);
			//long double fmodl(long double, long double);
	//double      frexp(double, int *);
			//float       frexpf(float, int *);
			//long double frexpl(long double, int *);
	//double      hypot(double, double);
			//float       hypotf(float, float);
			//long double hypotl(long double, long double);
	//int         ilogb(double);
			//int         ilogbf(float);
			//int         ilogbl(long double);
	//double      j0(double);
	//double      j1(double);
	//double      jn(int, double);
	//double      ldexp(double, int);
			//float       ldexpf(float, int);
			//long double ldexpl(long double, int);
	//double      lgamma(double);
			//float       lgammaf(float);
			//long double lgammal(long double);
			//long long   llrint(double);
			//long long   llrintf(float);
			//long long   llrintl(long double);
			//long long   llround(double);
			//long long   llroundf(float);
			//long long   llroundl(long double);
	//double      log(double);
	//double      log10(double);
			//float       log10f(float);
			//long double log10l(long double);
	//double      log1p(double);
			//float       log1pf(float);
			//long double log1pl(long double);
	//double      log2(double);
			//float       log2f(float);
			//long double log2l(long double);
	//double      logb(double);
			//float       logbf(float);
			//long double logbl(long double);
			//float       logf(float);
			//long double logl(long double);
	//long        lrint(double);
			//long        lrintf(float);
			//long        lrintl(long double);
	//long        lround(double);
			//long        lroundf(float);
			//long        lroundl(long double);
	//double      modf(double, double *);
			//float       modff(float, float *);
			//long double modfl(long double, long double *);
	//double      nan(const char *);
			//float       nanf(const char *);
			//long double nanl(const char *);
	//double      nearbyint(double);
			//float       nearbyintf(float);
			//long double nearbyintl(long double);
	//double      nextafter(double, double);
			//float       nextafterf(float, float);
			//long double nextafterl(long double, long double);
	//double      nexttoward(double, long double);
			//float       nexttowardf(float, long double);
			//long double nexttowardl(long double, long double);
	//double      pow(double, double);
			//float       powf(float, float);
			//long double powl(long double, long double);
	//double      remainder(double, double);
			//float       remainderf(float, float);
			//long double remainderl(long double, long double);
	//double      remquo(double, double, int *);
			//float       remquof(float, float, int *);
			//long double remquol(long double, long double, int *);
	//double      rint(double);
			//float       rintf(float);
			//long double rintl(long double);
	//double      round(double);
			//float       roundf(float);
			//long double roundl(long double);
	//double      scalbln(double, long);
			//float       scalblnf(float, long);
			//long double scalblnl(long double, long);
	//double      scalbn(double, int);
			//float       scalbnf(float, int);
			//long double scalbnl(long double, int);

	//double      sin(double);
    /**
     * Sine function.
     *
     * <p>
     * This function shall compute the sine of their argument <code>x</code>, measured in radians.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
	public function sin( x:Number ):Number { return Math.sin( x ); }

			//float       sinf(float);
	//double      sinh(double);
			//float       sinhf(float);
			//long double sinhl(long double);
			//long double sinl(long double);
	//double      sqrt(double);
			//float       sqrtf(float);
			//long double sqrtl(long double);
	//double      tan(double);
			//float       tanf(float);
	//double      tanh(double);
			//float       tanhf(float);
			//long double tanhl(long double);
			//long double tanl(long double);
	//double      tgamma(double);
			//float       tgammaf(float);
			//long double tgammal(long double);
	//double      trunc(double);
			//float       truncf(float);
			//long double truncl(long double);
	//double      y0(double);
	//double      y1(double);
	//double      yn(int, double);

}