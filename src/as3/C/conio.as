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

}
