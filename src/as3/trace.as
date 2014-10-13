/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package
{
	import shell.Program;

    // nonstandard Flash Player extensions

    /**
     * Displays expressions, or writes to log files, while debugging.
     * 
     * <p>
     * A single trace statement can support multiple arguments.
     * If any argument in a trace statement includes a data type other than a String,
     * the trace function invokes the associated <code>toString()</code> method for that data type.
     * For example, if the argument is a Boolean value the trace function invokes <code>Boolean.toString()</code>
     * and displays the return value.
     * </p>
     *
     * @example
     * The following example uses the class <code>TraceExample</code> to show
     * how the <code>trace()</code> method can be used to print a simple string.
     * Generally, the message will be printed to a "Debug" console.
     * <listing>
     * package
     * {
     *      import flash.display.Sprite;
     * 
     *      public class TraceExample extends Sprite
     *      {
     *          public function TraceExample()
     *          {
     *              trace( "Hello World" );
     *          }
     *      }
     * }
     * </listing>
     * 
     * @param arguments One or more (comma separated) expressions to evaluate.
     *                  For multiple expressions, a space is inserted between each expression in the output.
     * 
     * @playerversion Flash 9
     * @playerversion AIR 1.0
     * @langversion 3.0
     */
    public function trace( ... arguments ):void
    {
        Program.trace( arguments );
        //Program.trace.apply( null, arguments );
    }
}
