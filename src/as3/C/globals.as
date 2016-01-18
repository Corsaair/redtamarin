/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package C
{
    import shell.Program;

    /** @internal */
    [Inspectable(environment="none")]
    internal class __c
    {

        public static function getArgc():uint
        {
            return Program.argv.length + 1;
        }

        public static function getArgv():Array
        {
            var args:Array = [];
                args.push( Program.filename );
                args = args.concat( Program.argv );

            return args;
        }

        public static function getEnviron():Array
        {
            return Program.environ;
        }
    }
    
    /**
     * The count of the arguments supplied to the program.
     * 
     * <p>
     * When you write a program in <code>C</code> you can define
     * your code run by default from the <code>main()</code> function.
     * If you want to retrieve command line arguments you define the function as
     * <code>int main(int argc, char &#42;argv[]);</code>.
     * </p>
     * 
     * <p>
     * In our ActionScript 3.0 context we do not have a global <code>main()</code> function,
     * the code is executed or starts as soon as some executable code is encountered.
     * </p>
     * 
     * <p>
     * But we sitll need to retrieve command line arguments to write command-line programs.
     * Here we can use <code>argc</code> and <code>argv</code> as if we were writing a <code>C</code> program.
     * </p>
     * 
     * <p>
     * Be careful, <code>argc</code> and <code>argv</code> are constants, you can not write or overwrite them.
     * Also <code>argv[0]</code> will contain the program filename to mimic the <code>C</code> beahviour.
     * If you need a list of arguments without the program filename use <code>Program.argv</code>.
     * </p>
     * 
     * @example Usage
     * <listing>
     * import C.&#42;;
     * 
     * if( argc > 1 )
     * {
     *     var total:uint = argc;
     *     var count:uint = 1;
     *     while( total-- )
     *     {
     *         trace( argv[count] );
     *     }
     * }
     * else
     * {
     *     trace( "no arguments" );
     * }
     * </listing>
     * 
     * @return an unsigned integer representing the number of arguments.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4.1
     * 
     * @see shell.Program#argv Program.argv
     * @see http://publications.gbdirect.co.uk/c_book/chapter10/arguments_to_main.html The C Book - Arguments to main
     * @see http://crasseux.com/books/ctutorial/argc-and-argv.html The GNU C Programming - argc and argv
     * @see http://en.cppreference.com/w/cpp/language/main_function CPP Reference - C++ Main function
     * @see http://en.cppreference.com/w/c/language/main_function CPP Reference - C Main function
     */
    public const argc:uint = __c.getArgc();

    /**
     * The array of arguments supplied to the program.
     * 
     * <p>
     * <code>argv[0]</code> will contain the program filename, you can also access it with
     * <code>Program.filename</code>
     * </p>
     * 
     * <p>
     * In the case of a shell script running with <b>as3shebang</b>,
     * <code>argv[0]</code> will contains the path of the script
     * and not the path to program executing it eg. <code>/usr/bin/as3shebang</code>.
     * </p>
     * 
     * @return an Array of arguments as strings.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4.1
     * 
     * @see shell.Program#filename Program.filename
     */
    public const argv:Array = __c.getArgv();

    /**
     * Array of environment variables.
     * 
     * @return an Array of environment variables as strings.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4.1
     *
     * @see http://pubs.opengroup.org/onlinepubs/007908799/xsh/environ.html environ
     * @see http://pubs.opengroup.org/onlinepubs/007908799/xbd/envvar.html Environment Variables
     */
    public const environ:Array = __c.getEnviron();

}