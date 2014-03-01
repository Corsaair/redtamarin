/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.display
{
	/**
	 * The StageScaleMode class provides values for the <code>Stage.scaleMode</code> property.
	 * 
     * @langversion 3.0
     * @playerversion Flash 9
     * @playerversion AIR 1.0
     * 
     * @see flash.display.Stage#scaleMode
     * @see Controlling Stage scaling
	 */
	public final class StageScaleMode
	{
		/**
		 * Specifies that the entire application be visible in the specified area
		 * without distortion while maintaining the original aspect ratio of the application.
		 * Borders can appear on two sides of the application.
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 1.0
		 */
        public static const SHOW_ALL:String = "showAll";

		/**
		 * Specifies that the entire application be visible in the specified area
		 * without trying to preserve the original aspect ratio.
		 * Distortion can occur.
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 1.0
		 */
        public static const EXACT_FIT:String = "exactFit";

		/**
		 * Specifies that the entire application fill the specified area,
		 * without distortion but possibly with some cropping,
		 * while maintaining the original aspect ratio of the application.
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 1.0
		 */
        public static const NO_BORDER:String = "noBorder";

		/**
		 * Specifies that the size of the application be fixed,
		 * so that it remains unchanged even as the size of the player window changes.
		 * Cropping might occur if the player window is smaller than the content.
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 1.0
		 */
        public static const NO_SCALE:String = "noScale";
	}
}
