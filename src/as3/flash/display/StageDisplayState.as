/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.display
{
	/**
	 * The StageDisplayState class provides values for the
	 * <code>Stage.displayState</code> property.
	 * 
     * @langversion 3.0
     * @playerversion Flash 9.0.28.0
     * @playerversion AIR 1.0
     * 
     * @see flash.display.Stage#displayState
	 */
	public final class StageDisplayState
	{
		/**
		 * Specifies that the Stage is in full-screen mode.
		 * Keyboard interactivity is disabled in this mode.
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9.0.28.0
	     * @playerversion AIR 1.0
		 */
        public static const FULL_SCREEN:String = "fullScreen";

		/**
		 * Specifies that the Stage is in full-screen mode with keyboard interactivity enabled.
		 * As of Flash Player 11.3, this capability is supported in both AIR applications and browser-based applications.
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 11.3
	     * @playerversion AIR 1.0
	     * 
	     * @see flash.display.Stage#allowsFullScreenInteractive
		 */
		[API(AVMGLUE::SWF_16)]
        public static const FULL_SCREEN_INTERACTIVE:String = "fullScreenInteractive";

		/**
		 * Specifies that the Stage is in normal mode.
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9.0.28.0
	     * @playerversion AIR 1.0
		 */
        public static const NORMAL:String = "normal";
	}
}
