/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

// DOCUMENTATION ONLY - DO NOT COMPILE IN ABC/SWC
package C
{
    /**
     * C standard library.
     * 
     * <p>
     * <b>ANSI C (C89) / ISO C (C90)</b> documentation.
     * </p>
     * 
     * <p>
     * ANSI C refers to the family of successive standards published by
     * the <a href="http://en.wikipedia.org/wiki/American_National_Standards_Institute">American National Standards Institute</a> (ANSI)
     * for the <a href="http://en.wikipedia.org/wiki/C_(programming_language)">C programming language</a>.
     * </p>
     * 
     * <p>
     * Software developers writing in C are encouraged to conform to the standards, as doing so aids portability between compilers.
     * </p>
     * 
     * <p>
     * The first standard for C was published by ANSI.
     * Although this document was subsequently adopted
     * by <a href="http://en.wikipedia.org/wiki/International_Organization_for_Standardization">International Organization for Standardization</a> (ISO)
     * and subsequent revisions published by ISO have been adopted by ANSI, the name ANSI C (rather than ISO C) is still more widely used.
     * </p>
     * 
     * <p>
     * While some software developers use the term <b>ISO C</b>, others are standards body–neutral and use <b>Standard C</b>.
     * </p>
     * 
     * <p>
     * <b>TODO</b> more documentation.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     * 
     * @see C.assert
     * @see C.ctype
     * @see C.errno
     * @see C.float
     * @see C.limits
     * @see C.locale
     * @see C.math
     * @see C.setjmp
     * @see C.signal
     * @see C.stdarg
     * @see C.stddef
     * @see C.stdio
     * @see C.stdlib
     * @see C.string
     * @see C.time
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/
     * @see http://code.google.com/p/redtamarin/wiki/clib
     * @see http://en.wikipedia.org/wiki/ISO_C
     * @see http://en.wikipedia.org/wiki/ANSI_C
     */
	public const ISO_C:String = "ISO C / ANSI C documentation";

     /**
      * assert.h - verify program assertion
      * 
      * <p>
      * assert.h is a header file in the standard library of the C programming language
      * that defines the C preprocessor macro <code>assert()</code>.
      * </p>
      * 
      * <p>
      * The macro implements an assertion, which can be used to verify assumptions made by the program
      * and print a diagnostic message if this assumption is false.
      * </p>
      * 
      * @langversion 3.0
      * @playerversion AVM 0.4
      * 
      * @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/assert.h.html
      * @see http://en.wikipedia.org/wiki/Assert.h
      */
     public const ASSERT_H:String = "assert.h documentation";

     /**
      * ctype.h - character types
      * 
      * <p>
      * C character classification is an operation provided by a group of functions
      * in the ANSI C Standard Library for the C programming language.
      * </p>
      * 
      * <p>
      * These functions are used to test characters for membership in a particular class of characters,
      * such as alphabetic characters, control characters, etc.
      * </p>
      * 
      * <p>
      * Both single-byte, and wide characters are supported.
      * </p>
      * 
      * @langversion 3.0
      * @playerversion AVM 0.4
      * 
      * @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/ctype.h.html
      * @see http://en.wikipedia.org/wiki/Ctype.h
      */
     public const CTYPE_H:String = "ctype.h documentation";

     /**
      * errno.h - system error numbers
      * 
      * <p>
      * errno.h is a header file in the standard library of C programming language.
      * </p>
      * 
      * <p>
      * It defines macros to report error conditions through error codes stored
      * in a static location called <code>errno</code>.
      * </p>
      * 
      * @langversion 3.0
      * @playerversion AVM 0.4
      * 
      * @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/errno.h.html
      * @see http://en.wikipedia.org/wiki/Errno.h
      */
     public const ERRNO_H:String = "errno.h documentation";

     /** not supported */
     public const FLOAT_H:String = "float.h not supported";

     /**
      * limits.h - implementation-defined constants
      * 
      * <p>
      * limits.h is a header file in the standard library of C programming language.
      * </p>
      * 
      * <p>
      * It defines macros and symbolic constants for various limits on resources
      * that the implementation imposes on applications.
      * </p>
      * 
      * @langversion 3.0
      * @playerversion AVM 0.4
      * 
      * @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/limits.h.html
      * @see http://en.wikipedia.org/wiki/Limits.h#limits.h
      */
     public const LIMITS_H:String = "limits.h documentation";

     /**
      * locale.h - localization category macros
      * 
      * <p>
      * locale.h is a header file in the standard library of C programming language.
      * </p>
      * 
      * <p>
      * It defines macros and functions implementing basic localization routines and specific information.
      * </p>
      * 
      * @langversion 3.0
      * @playerversion AVM 0.4
      * 
      * @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/locale.h.html
      * @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap07.html
      * @see http://en.wikipedia.org/wiki/Locale.h
      */
     public const LOCALE_H:String = "locale.h documentation";

     /**
      * math.h - mathematical declarations
      * 
      * @langversion 3.0
      * @playerversion AVM 0.4
      * 
      * @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/math.h.html
      * @see http://en.wikipedia.org/wiki/Math.h
      */
     public const MATH_H:String = "math.h documentation";

     /** not supported */
     public const SETJMP_H:String = "setjmp.h not supported";

     /** not supported */
     public const SIGNAL_H:String = "signal.h not supported";

     /** not supported */
     public const STDARG_H:String = "stdarg.h not supported";

     /** not supported */
     public const STDDEF_H:String = "stddef.h not supported";

     /**
      * stdio.h - standard buffered input/output
      * 
      * <p>
      * stdio.h is a header file in the standard library of C programming language.
      * </p>
      * 
      * <p>
      * It defines macros, symbolic constants and functions for file input and output.
      * </p>
      * 
      * @langversion 3.0
      * @playerversion AVM 0.4
      * 
      * @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/stdio.h.html
      * @see http://en.wikipedia.org/wiki/Stdio.h
      * @see http://www.acm.uiuc.edu/webmonkeys/book/c_guide/2.12.html
      * @see http://beej.us/guide/bgc/output/html/multipage/stdio.html
      */
     public const STDIO_H:String = "stdio.h documentation";

     /**
      * stdlib.h - standard library definitions
      * 
      * <p>
      * stdlib.h is a header file in the standard library of C programming language.
      * </p>
      *
      * <p>
      * It defines general operation functions.
      * </p>
      * 
      * @langversion 3.0
      * @playerversion AVM 0.4
      * 
      * @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/stdlib.h.html
      * @see http://www.acm.uiuc.edu/webmonkeys/book/c_guide/2.13.html
      */
     public const STDLIB_H:String = "stdlib.h documentation";

     /**
      * string.h - string operations
      * 
      * <p>
      * string.h is a header file in the standard library of C programming language.
      * </p>
      * 
      * <p>
      * It defines functions for manipulating strings (character arrays).
      * </p>
      * 
      * @langversion 3.0
      * @playerversion AVM 0.4
      * 
      * @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/string.h.html
      * @see http://en.wikipedia.org/wiki/String.h
      * @see http://www.acm.uiuc.edu/webmonkeys/book/c_guide/2.14.html
      */
     public const STRING_H:String = "string.h documentation";

     /**
      * time.h - time types
      * 
      * <p>
      * time.h is a header file in the standard library of C programming language.
      * </p>
      * 
      * <p>
      * It defines functions useful for reading and converting the current time and date.
      * </p>
      * 
      * @langversion 3.0
      * @playerversion AVM 0.4
      * 
      * @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/time.h.html
      * @see http://en.wikipedia.org/wiki/Assert.h
      * @see http://www.acm.uiuc.edu/webmonkeys/book/c_guide/2.15.html
      */
     public const TIME_H:String = "time.h documentation";

}