/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.utils
{
    
    /**
     * Runs a specified function after a specified delay (in milliseconds).
     * 
     * <p>
     * Instead of using this method, consider creating a Timer object, with the specified interval,
     * using 1 as the <code>repeatCount</code> parameter (which sets the timer to run only once).
     * </p>
     *
     * <p>
     * If you intend to use the <code>clearTimeout()</code> method to cancel the <code>setTimeout()</code> call,
     * be sure to assign the <code>setTimeout()</code> call to a variable
     * (which the <code>clearTimeout()</code> function will later reference).
     * If you do not call the <code>clearTimeout()</code> function to cancel the <code>setTimeout()</code> call,
     * the object containing the set timeout closure function will not be garbage collected.
     * </p>
     *
     * @example
     * The following example uses the <code>setTimeout()</code> method
     * to call another method following a specified delay period.
     * 
     * <listing>
     * package
     * {
     *      import flash.display.Sprite;
     *      import flash.utils.&#42;;
     * 
     *      public class SetTimeoutExample extends Sprite
     *      {
     *          private var delay:Number = 1000; // delay before calling myDelayedFunction
     * 
     *          public function SetTimeoutExample()
     *          {
     *              var intervalId:uint = setTimeout( myDelayedFunction, delay, "Hello", "World" );
     *          }
     * 
     *          public function myDelayedFunction():void
     *          {
     *              trace( arguments[0] + " " + arguments[1] );
     *          }
     *      }
     * }
     * </listing>
     * 
     * @param closure The name of the function to execute.
     * Do not include quotation marks or parentheses, and do not specify parameters of the function to call.
     * For example, use <code>functionName</code>,
     * not <code>functionName()</code> or <code>functionName(param)</code>.
     * @param delay The delay, in milliseconds, until the function is executed.
     * @param arguments An optional list of arguments that are passed to the closure function.
     * @return  Unique numeric identifier for the timed process.
     * Use this identifier to cancel the process, by calling the <code>clearTimeout()</code> method.
     * 
	 * @playerversion Flash 9
	 * @playerversion AIR 1.0
	 * @langversion 3.0
     *
     * @see flash.utils#clearTimeout() clearTimeout()
     */
    public function setTimeout( closure:Function, delay:Number, ... arguments ):uint
    {
        throw new Error( "not implemented" );
        return 0;
    }
}
