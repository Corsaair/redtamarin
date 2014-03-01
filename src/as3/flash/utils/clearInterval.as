/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.utils
{
    
    /**
     * Cancels a specified <code>setInterval()</code> call.
     * 
     * @example
     * The following example uses the <code>setInterval()</code> method to create a timed interval,
     * calling the <code>myRepeatingFunction()</code> method after regular intervals of one second.
     *
     * Each call of the <code>myRepeatingFunction</code> method increments the <code>counter</code> property,
     * and when it equals the <code>stopCount</code> property, the <code>clearInterval()</code> method is called
     * with the property <code>intervalId</code> which is a reference id to the interval that was created earlier.
     * 
     * <listing>
     * package
     * {
     *      import flash.display.Sprite;
     *      import flash.utils.&#42;;
     * 
     *      public class ClearIntervalExample extends Sprite
     *      {
     *          private var intervalDuration:Number = 1000; // duration between intervals, in milliseconds
     *          private var intervalId:uint;
     *          private var counter:uint = 0;
     *          private var stopCount:uint = 3;
     * 
     *          public function ClearIntervalExample()
     *          {
     *              intervalId = setInterval( myRepeatingFunction, intervalDuration, "Hello", "World" );
     *          }
     * 
     *          public function myRepeatingFunction():void
     *          {
     *              trace( arguments[0] + " " + arguments[1] );
     * 
     *              counter++;
     *              if( counter == stopCount )
     *              {
     *                  trace( "Clearing Interval" );
     *                  clearInterval( intervalId );
     *              }
     *          }
     *      }
     * }
     * </listing>
     * 
     * @param id The ID of the setInterval() call, which you set to a variable, as in the following:
     * 
	 * @playerversion Flash 9
	 * @playerversion AIR 1.0
	 * @langversion 3.0
     */
    public function clearInterval( id:uint ):void
    {
        throw new Error( "not implemented" );
    }
}
