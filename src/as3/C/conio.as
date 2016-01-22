/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package C.conio
{

    /**
     * @name <code>&lt;conio.h&gt;</code>
     * Console input and output.
     *
     * <p>
     * Declares several useful library functions for performing
     * console input and output from a program.
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://en.wikipedia.org/wiki/Conio.h conio.h
     */

    /**
     * <p>
     * <b>NEED MORE WORK</b>
     * </p>
     * 
     * Emit a beep sound.
     *
     * <p>
     * TODO
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function beep():void
    {
        //ASCII BEL 007
        Program.write( "\x07" );
    }

    /**
     * <p>
     * <b>NEED MORE WORK</b>
     * </p>
     * 
     * Turns the console/terminal <b>canonical</b> mode <code>on</code> or <code>off</code>.
     *
     * <p>
     * By default, <b>canonical</b> mode is <code>on</code>.
     * </p>
     *
     * <p>
     * This is also called the "cooked mode", when you read from the console/terminal,
     * it returns a line at a time instead of each character as it is received.
     * </p>
     *
     * <p>
     * Changing the <b>canonical</b> mode to <code>off</code>
     * is called the "raw mode" (or noncanonical).
     * WIth this mode the input will not be put into lines before it is returned,
     * and it will also not process some special characters:
     * <code>ERASE</code>, <code>KILL</code>, <code>EOF</code>, <code>NL</code>, <code>EOL</code>,
     * <code>EOL2</code>, <code>CR</code>, <code>REPRINT</code>, <code>STATUS</code> and <code>WERASE</code>.
     * </p>
     * 
     * <p>
     * <b> Note: </b> This is a non-standard extension to conio.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CConioClass::canonical")]
    public native function canonical( status:Boolean ):void;

    /**
     * <p>
     * <b>NEED MORE WORK</b>
     * </p>
     * 
     * Turns the console/terminal <b>echo</b> mode <code>on</code> or <code>off</code>.
     *
     * <p>
     * By default, <b>echo</b> mode is <code>on</code>.
     * </p>
     *
     * <p>
     * Each time you read <code>stdin</code> the console/terminal echo it to <code>stdout</code>.
     * </p>
     * 
     * <p>
     * <b> Note: </b> This is a non-standard extension to conio.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CConioClass::echo")]
    public native function echo( status:Boolean ):void;

    /*
     * Gets a character from the console/terminal without echo.
     *
     * <p>
     * <b> Note: </b> This is a non-standard extension to stdio inspired by windows <code>_getch</code>.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     * 
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/getchar.html
     */
    //[native("::avmshell::CConioClass::getch")]
    //public native function getch():int;

    /*
     * Gets a character from the console with echo.
     *
     * <p>
     * <b> Note: </b> This is a non-standard extension to stdio inspired by windows <code>_getche</code>.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    //[native("::avmshell::CConioClass::getche")]
    //public native function getche():int;

    /**
     * <p>
     * <b>NEED MORE WORK</b>
     * </p>
     * 
     * Checks the console for keyboard input.
     *
     * <p>
     * The <code>kbhit()</code> function checks for the the console recent keystroke.
     * If the function returns a non-zero value that means a character value is waiting in the buffer.
     * You can then use <code>getch()</code> to obtain the char value.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://msdn.microsoft.com/en-us/library/58w7c94c.aspx
     */
    [native("::avmshell::CConioClass::kbhit")]
    public native function kbhit():int;

    /**
     * Set the file translation to <b>binary</b> or <b>text</b>.
     *
     * <p>
     * Under Windows the console is in text mode (<code>O_TEXT</code>) by default,
     * this function allow to change it to binary mode (<code>O_BINARY</code>).
     * </p>
     * 
     * <p>
     * Under Mac OS X and Linux, the console on those platforms does not
     * distinguish between text and binary, and so it will always returns <code>true</code>.
     * </p>
     * 
     * <p>
     * This is particularly useful when you need to pipe binary data on the command-line,
     * for ex: <code>some_program | other_program</code>.
     * The pipe (<b>|</b>) reads the output from one command and writes it to the input of another command,
     * in the example: both commands start simultaneously, but then the <b>other_program</b>
     * command pauses until it receives the <b>some_program</b> command's output.
     * The <b>other_program</b> command uses the <b>some_program</b> command's output as
     * its input, and then sends its output to <code>STDOUT</code>.
     * </p>
     * 
     * @example Usage
     * <listing>
     * import shell.Runtime;
     * import C.stdio.&#42;;
     * import C.unistd.&#42;;
     * import C.conio.&#42;;
     * 
     * // Note:
     * // stdin is of type FILE
     * // instead of 'stdin' you can also fdopen( STDIN_FILENO, "rb" )
     * // STDIN_FILENO is of type int, eg. a file descriptor
     * 
     * // Note:
     * // the usage is: $ cat some_binary | ./yourprogram
     * // but if nothing is sent to stdin, it will block forever
     * // for ex: $ ./yourprogram
     * // the program will block forever till you
     * // press Ctrl+D on the command line to signal end-of-file
     * // for standard input on the running program.
     * // to not block forever, we can use kbhit()
     * 
     * // if under Windows we set our console to binary
     * if( Runtime.platform == "windows" )
     * {
     *     set_binary_mode( STDIN_FILENO, true );
     * }
     * 
     * // read the stdin
     * var buffer:uint = 8192; // 8K buffer, we read by chunk of 8K
     * var bytes:ByteArray = new ByteArray(); // our data buffer
     * var size:int; // the current size we read
     * 
     * var input:ByteArray = new ByteArray(); // where we concate the chunk of buffer
     * var total:Number = 0; // the total size read
     * 
     * // kbhit() allow us to detect if some data is pending in stdin
     * // to avoid our program to block forever
     * if( kbhit() &gt; 0 )
     * {
     * 
     *     // loop as long as fread() does not returns zero
     *     // if returns zero that means EOF reached
     *     // if returns less than zero that means an error occured
     *     while( size = fread( bytes, int(buffer), stdin ) )
     *     {
     *         input.writeBytes( bytes ); //add the chunk of data
     *         total += size;
     *         bytes.clear(); //reset the chunk
     *     }
     * 
     * }
     * 
     * // total and input.length should be the same size
     * // if no data in stdin will be zero
     * trace( "stdin received " + total + " bytes" );
     * trace( "input size is " + input.length + " bytes" ); 
     * 
     * // now we can search the input bytes to determine
     * // if the input is binary or text
     * input.position = 0;
     * var byte_null:ByteArray = new ByteArray();
     *     byte_null.writeByte( 0 );
     * // searchBytes() is not defined/explained here
     * var found_null:Boolean = searchBytes( byte_null, input );
     * 
     * if( found_null )
     * {
     *      // if we found null we are a binary
     *      // parse the input here
     * }
     * else
     * {
     *      // if not, we are text
     *      var text:String = input.readUTFBytes();
     * }
     * </listing>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4.1
     * @playerversion WIN +
     *
     * @see http://msdn.microsoft.com/en-us/library/tw4k6df8.aspx _setmode (MSDN)
     * @see http://www.microsoft.com/resources/documentation/windows/xp/all/proddocs/en-us/redirection.mspx?mfr=true Using command redirection operators (Windows XP)
     */
    [native("::avmshell::CConioClass::set_binary_mode")]
    public native function set_binary_mode( fd:int, binary:Boolean = false ):Boolean;

}
