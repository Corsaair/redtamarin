/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package
{
	import shell.Program;
	
    // nonstandard extensions to ECMAScript

    /**
     * Displays expressions, or writes to log files, while debugging.
     * 
     * <p>
     * A single print statement can support multiple arguments.
     * If any argument in a print statement includes a data type other than a String,
     * the print function invokes the associated <code>toString()</code> method for that data type.
     * For example, if the argument is a Boolean value the print function invokes <code>Boolean.toString()</code>
     * and displays the return value.
     * </p>
     *
     * <p>
     * <b>Note: </b> The <code>print()</code> function is completely similar to the <code>trace()</code> function,
     * the only difference is that you can hook your own function to the <code>print()</code> function.
     * TODO <code>Program.onPrint = function() { ... }</code>
     * </p>
     * 
     * @example
     * The following example show how the <code>print()</code> method can be used to print a simple string.
     * Generally, the message will be printed to a "Debug" console.
     * 
     * <listing>
     * print( "Hello World" );
     * </listing>
     * 
     * @param arguments One or more (comma separated) expressions to evaluate.
     *                  For multiple expressions, a space is inserted between each expression in the output.
     * 
     * @playerversion AVM 0.4
     * @langversion 3.0
     *
     * @see trace()
     */
    public function print( ...arguments ):void
    {
        //TODO: define trace/print hook in Program ?

        //Program.trace( s );
        Program.trace.apply( null, arguments );
    }
	
}
