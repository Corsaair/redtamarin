/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.utils
{
    import shell.Program;

    /**
     * Used to compute relative time.
     * For a Flash runtime processing ActionScript 3.0, this method returns the number of milliseconds
     * that have elapsed since the Flash runtime virtual machine for ActionScript 3.0 (AVM2) started.
     * 
     * <p>
     * For a calendar date (timestamp), see the Date object.
     * </p>
     *
     * @example
     * The following example uses the class <code>GetTimerExample</code>
     * to get and print the number of milliseconds since the runtime initialized.
     * 
     * <listing>
     * package
     * {
     *      import flash.utils.getTimer;
     *      import flash.display.Sprite;
     * 
     *      public class GetTimerExample extends Sprite
     *      {
     *          public function GetTimerExample()
     *          {
     *              var duration:uint = getTimer();
     *              trace( "duration: " + duration );
     *          }
     *      }
     * }
     * </listing>
     * 
     * @return The number of milliseconds since the virtual machine started (while processing ActionScript 3.0).
     * If the runtime starts playing one SWF file, and another SWF file is loaded later,
     * the return value is relative to when the first SWF file was loaded.
     * 
	 * @playerversion Flash 9
	 * @playerversion AIR 1.0
	 * @langversion 3.0
     *
     * @see flash.display.AVM1Movie
     * @see Date
     */
    public function getTimer():int
    {
        return Program.getTimer();
    }
}
