/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.utils
{
    
    /**
     * Cancels a specified <code>setTimeout()</code> call.
     *
     * @example
     * The following example uses the <code>setTimeout()</code> method to call
     * another method following a specified delay period.
     *
     * A loop is created to count to one million.
     * If the system can process this request faster than a second can expire,
     * <code>clearTimeout()</code> will remove the <code>setTimeout()</code> request,
     * and <code>myDelayedFunction()</code> will not be called.
     * 
     * <listing>
     * package
     * {
     *      import flash.display.Sprite;
     *      import flash.utils.&#42;;
     * 
     *      public class ClearTimeoutExample extends Sprite
     *      {
     *          private var delay:Number = 1000; // delay before calling myDelayedFunction
     *          private var intervalId:uint;
     *          private var count:uint = 1000000;
     * 
     *          public function ClearTimeoutExample()
     *          {
     *              intervalId = setTimeout( myDelayedFunction, delay );
     *              startCounting();
     *          }
     * 
     *          public function startCounting():void
     *          {
     *              var i:uint = 0;
     *              do
     *              {
     *                  if( i == count-1 )
     *                  {
     *                      clearTimeout( intervalId );
     *                      trace( "Your computer can count to " + count + " in less than " + delay/1000 + " seconds." );
     *                  }
     *              }
     *              while( i &lt; count )
     *          }
     * 
     *          public function myDelayedFunction():void
     *          {
     *              trace( "Time expired." );
     *          }
     *      }
     * }
     * </listing>
     * 
     * @param id The ID of the setTimeout() call, which you set to a variable, as in the following:
     * 
	 * @playerversion Flash 9
	 * @playerversion AIR 1.0
	 * @langversion 3.0
     */
    public function clearTimeout( id:uint ):void
    {
        throw new Error( "not implemented" );
    }
}
