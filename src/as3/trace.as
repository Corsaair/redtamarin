/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package
{
	import shell.*;

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
     * The following example show how the <code>trace()</code> method can be used to print a simple string.
     * Generally, the message will be printed to a "Debug" console.
     * 
     * <listing version="3.0">
     * trace( "Hello World" );
     * </listing>
     * 
     * @param ... One or more (comma separated) expressions to evaluate.
     *            For multiple expressions, a space is inserted between each expression in the output.
     * 
     * @langversion ActionScript 3.0
	 * @playerversion RT 0.3
     */
    public function trace( ...arguments ):void
    {
        Program.trace( arguments );
    }
}
