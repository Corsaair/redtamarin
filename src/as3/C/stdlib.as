/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package C.stdlib
{
    import shell.Program;
    import C.errno.*;

    /**
     * @name <code>&lt;stdlib.h&gt;</code>
     * Standard library definitions.
     *
     * <p>
     * Defines numeric conversion functions,
     * pseudo-random numbers generation functions,
     * memory allocation, process control functions.
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/stdlib.h.html stdlib.h
     */

    /** @internal */
    [native(cls="::avmshell::CStdlibClass", methods="auto", construct="none")]
    [Inspectable(environment="none")]
    internal class __stdlib
    {
        public native static function get EXIT_SUCCESS():int;
        public native static function get EXIT_FAILURE():int;
        public native static function get RAND_MAX():int;
        public native static function get MB_CUR_MAX():int;

        public static function _str2num( str:String ):Number
        {
            var result:Number = parseFloat( str );

            if( isNaN(result) )
            {
                result = 0;
                errno.value = EINVAL;
            }

            return result;
        }

        public static function _str2int( str:String, base:uint = 0 ):int
        {
            if( (base != 0) && ( (base < 2) || (base > 36) ) )
            {
                errno.value = EINVAL;
                return 0;
            }

            var result:Number = parseInt( n, base );

            if( isNaN(result) )
            {
                result = 0;
                errno.value = EINVAL;
            }

            return int(result);
        }

        public static function _str2uint( str:String, base:uint = 0 ):uint
        {
            if( (base != 0) && ( (base < 2) || (base > 36) ) )
            {
                errno.value = EINVAL;
                return 0;
            }

            var result:Number = parseInt( n, base );

            if( isNaN(result) )
            {
                result = 0;
                errno.value = EINVAL;
            }

            return uint(result);
        }
    }
    

    /**
     * Success termination code.
     * Successful termination for exit(); evaluates to 0.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EXIT_SUCCESS:int = __stdlib.EXIT_SUCCESS;

    /**
     * Failure termination code.
     * Unsuccessful termination for exit(); evaluates to a non-zero value.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EXIT_FAILURE:int = __stdlib.EXIT_FAILURE;

    /**
     * Maximum value returned by rand(); at least 32767.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const RAND_MAX:int = __stdlib.RAND_MAX;

    /**
     * Maximum number of bytes in a character specified
     * by the current locale (category LC_CTYPE).
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const MB_CUR_MAX:int = __stdlib.MB_CUR_MAX;


    //_Exit()
    //a64l()

    /**
     * Generate an abnormal process abort.
     * 
     * <p>
     * The <code>abort()</code> function shall cause abnormal process termination to occur,
     * unless the signal <code>SIGABRT</code> is being caught and the signal handler does not return.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @private
     * we can not directly hook to the native function atexit()
     * because our code run inside a VM!
     */
    public function abort():void
    {
        Program.abort();
    }
    
    /**
     * Return an integer absolute value.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function abs( i:int ):int { return int( Math.abs(i) ); }

    /**
     * Register a function to run at process termination.
     * 
     * <p>
     * The <code>atexit()</code> function shall register the function pointed to by <code>f</code>,
     * to be called without arguments at normal program termination.
     * </p>
     * 
     * <p>
     * At normal program termination, all functions registered by the <code>atexit()</code> function
     * shall be called, in the reverse order of their registration, except that a function is called
     * after any previously registered functions that had already been called at the time it was registered.
     * Normal termination occurs either by a call to <code>exit()</code> or a return from <code>main()</code>.
     * </p>
     * 
     * <p>
     * At least <code>32</code> functions can be registered with <code>atexit()</code>.
     * </p>
     * 
     * <p>
     * After a successful call to any of the exec functions, any functions previously registered by
     * <code>atexit()</code> shall no longer be registered.
     * </p>
     * 
     * @example Usage
     * <listing>
     * import C.stdlib.&#42;;
     * 
     * atexit( function() { trace( "anonymous function" ); } );
     * 
     * var test1:Function = function():void
     * {
     *     trace( "test1 function" );
     * }
     * atexit( test1 );
     * 
     * exit();
     * 
     * //output
     * "test1 function"
     * "anonymous function"
     * </listing>
     * 
     * @param f The pointer to a <code>Function</code>.
     * @return Upon successful completion, <code>atexit()</code> shall return <code>0</code>;
     * otherwise, it shall return a non-zero value.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     * 
     * @see C.stdlib#exit()
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/atexit.html
     *
     * @private
     * we can not directly hook to the native function atexit()
     * because our code run inside a VM!
     */
    public function atexit( f:Function ):int
    {
        try
        {
            Program.AVM2::atExit( f );
        }
        catch( e:Error )
        {
            return 1;
        }

        return 0;
    }

    /**
     * Convert a string to a double-precision number.
     * 
     * @example Usage
     * <listing>
     * import C.stdlib.&#42;;
     * import C.math.&#42;;
     * 
     * var pi:Number = 3.1415926535;
     * var result:Number = atof( "45.0000000001" );
     * 
     * trace( "result = " + result );
     * trace( "sine = " + sin(result &#42; pi / 180) );
     * 
     * </listing>
     * 
     * @param str The string to convert.
     * @return The <code>atof()</code> function shall return the converted value if the value can be represented.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CStdlibClass::atof")]
    public native function atof( str:String ):Number;

    /**
     * Convert a string to an integer.
     * 
     * @example Usage
     * <listing>
     * import C.stdlib.&#42;;
     * 
     * var result:int = atoi( "73" );
     * 
     * trace( "result = " + result );
     * trace( "result x 2 = " + (result &#42; 2) );
     * 
     * </listing>
     * 
     * @param str The string to convert.
     * @return The <code>atoi()</code> function shall return the converted value if the value can be represented.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CStdlibClass::atoi")]
    public native function atoi( str:String ):int;

    /**
     * Convert a string to a long integer.
     * 
     * @example Usage
     * <listing>
     * import C.stdlib.&#42;;
     * 
     * var result:Number = atol( "567283" );
     * 
     * trace( "result = " + result );
     * trace( "result x 2 = " + (result &#42; 2) );
     * 
     * </listing>
     * 
     * @param str The string to convert.
     * @return The <code>atol()</code> function shall return the converted value if the value can be represented.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CStdlibClass::atol")]
    public native function atol( str:String ):Number;

    /**
     * Convert a string to a long integer.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function atoll( str:String ):Number { return atol( str ); }

    //bsearch()
    //calloc()

    /**
     * Compute the quotient and remainder of an integer division.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CStdlibClass::div")]
    public native function div( numer:int, denom:int ):div_t;

    //drand48()
    //erand48()

    /**
     * Terminate program execution.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @private
     * we can not directly hook to the native function exit()
     * because our code run inside a VM!
     */
    public function exit( status:int = -1 ):void
    {
        if( status == -1 ) { status = EXIT_SUCCESS; }
        Program.exit( status );
    }

    //free()

    /**
     * Get value of an environment variable.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CStdlibClass::getenv")]
    public native function getenv( name:String ):String;

    //getsubopt()
    //grantpt()
    //initstate()
    //jrand48()
    //l64a()

    /**
     * Return a long integer absolute value.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function labs( i:Number ):Number { return Math.abs(i); }

    //lcong48()

    /**
     * Compute the quotient and remainder of a number division.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CStdlibClass::ldiv")]
    public native function ldiv( numer:Number, denom:Number ):ldiv_t;

    /**
     * Return a long integer absolute value.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function llabs( i:Number ):Number { return Math.abs(i); }

    /**
     * Compute the quotient and remainder of a number division.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CStdlibClass::lldiv")]
    public native function lldiv( numer:Number, denom:Number ):lldiv_t;

    //lrand48()
    //malloc()

    /**
     * Get number of bytes in a character.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CStdlibClass::mblen")]
    public native function mblen( s:String, n:int ):int;

    //mbstowcs()
    //mbtowc()

    /**
     * Create a unique directory.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CStdlibClass::mkdtemp")]
    public native function mkdtemp( template:String ):String;

    /**
     * Create a unique file.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CStdlibClass::mkstemp")]
    public native function mkstemp( template:String ):int;

    //mrand48()
    //nrand48()
    //posix_memalign()
    //posix_openpt()
    //ptsname()

    /**
     * Change or add a value to an environment.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CStdlibClass::putenv")]
    public native function putenv( name:String ):int;

    //qsort()

    /**
     * Pseudo-random number generator.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CStdlibClass::rand")]
    public native function rand():int;

    //rand_r()
    //random()
    //realloc()

    /**
     * Resolve a pathname.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CStdlibClass::realpath")]
    public native function realpath( path:String ):String;

    //seed48()

    /**
     * Add or change an environment variable.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CStdlibClass::setenv")]
    public native function setenv( name:String, value:String, overwrite:Boolean = false ):int;

    //setkey()
    //setstate()

    /**
     * Pseudo-random number generator.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CStdlibClass::srand")]
    public native function srand( seed:uint ):void;

    //srand48()
    //srandom()

    /**
     * Convert a string to a double-precision number.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function strtod( str:String ):Number { return __stdlib._str2num( str ); }

    /**
     * Convert a string to a double-precision number.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function strtof( str:String ):Number { return __stdlib._str2num( str ); }

    /**
     * Convert a string to a long integer.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function strtol( str:String, base:uint = 0 ):int { return __stdlib._str2int( str, base ); }

    /**
     * Convert a string to a double-precision number.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function strtold( str:String ):Number { return __stdlib._str2num( str ); }

    /**
     * Convert a string to a long integer.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function strtoll( str:String, base:uint = 0 ):int { return __stdlib._str2int( str, base ); }

    /**
     * Convert a string to an unsigned long.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function strtoul( str:String, base:uint = 0 ):uint { return __stdlib._str2uint( str, base ); }

    /**
     * Convert a string to an unsigned long.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function strtoull( str:String, base:uint = 0 ):uint { return __stdlib._str2uint( str, base ); }

    /**
     * Issue a command.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CStdlibClass::system")]
    public native function system( command:String ):int;

    //unlockpt()

    /**
     * Remove an environment variable.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CStdlibClass::unsetenv")]
    public native function unsetenv( name:String ):int;
    
    //wcstombs()
    //wctomb()


    /**
     * Structure <code>div_t</code> returned by <code>div()</code>.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native(cls="::avmshell::Cdiv_tClass", instance="::avmshell::Cdiv_tObject", methods="auto")]
    public class div_t
    {

        /**
         * Construct a <code>div_t</code> structure.
         */
        public function div_t( quot:int = 0, rem:int = 0 ):void
        {
            this.quot = quot;
            this.rem  = rem;
        }

        /**
         * Quotient.
         */
        public var quot:int;

        /**
         * Remainder.
         */
        public var rem:int;

        public function toString():String
        {
            var str:String = "";
                str += "{div_t:"
                str += " quot="+quot;
                str += ", rem="+rem;
                str += "}";

            return str;
        }
    }

    /**
     * Structure <code>ldiv_t</code> returned by <code>ldiv()</code>.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native(cls="::avmshell::Cldiv_tClass", instance="::avmshell::Cldiv_tObject", methods="auto")]
    public class ldiv_t
    {

        /**
         * Construct a <code>ldiv_t</code> structure.
         */
        public function ldiv_t( quot:Number = 0, rem:Number = 0 ):void
        {
            this.quot = quot;
            this.rem  = rem;
        }

        /**
         * Quotient.
         */
        public var quot:Number;

        /**
         * Remainder.
         */
        public var rem:Number;

        public function toString():String
        {
            var str:String = "";
                str += "{ldiv_t:"
                str += " quot="+quot;
                str += ", rem="+rem;
                str += "}";

            return str;
        }
    }

    [native(cls="::avmshell::Clldiv_tClass", instance="::avmshell::Clldiv_tObject", methods="auto")]
    public class lldiv_t
    {

        /**
         * Construct a <code>lldiv_t</code> structure.
         */
        public function lldiv_t( quot:Number = 0, rem:Number = 0 ):void
        {
            this.quot = quot;
            this.rem  = rem;
        }

        /**
         * Quotient.
         */
        public var quot:Number;

        /**
         * Remainder.
         */
        public var rem:Number;

        public function toString():String
        {
            var str:String = "";
                str += "{lldiv_t:"
                str += " quot="+quot;
                str += ", rem="+rem;
                str += "}";

            return str;
        }
    }
    
}
