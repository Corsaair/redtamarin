/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.display
{
	/**
	 * The PixelSnapping class is an enumeration of constant values for setting
	 * the pixel snapping options by using the <code>pixelSnapping</code> property of a Bitmap object.
	 * 
     * @langversion 3.0
     * @playerversion Flash 9
     * @playerversion AIR 1.0
     * 
     * @see flash.display.Bitmap#pixelSnapping
	 */
	public final class PixelSnapping
	{
		/**
		 * A constant value used in the <code>pixelSnapping</code> property of a Bitmap object
		 * to specify that no pixel snapping occurs.
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 1.0
		 */
        public static const NEVER:String = "never";

		/**
		 * A constant value used in the <code>pixelSnapping</code> property of a Bitmap object
		 * to specify that the bitmap image is always snapped to the nearest pixel,
		 * independent of any transformation.
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 1.0
		 */
        public static const ALWAYS:String = "always";

		/**
		 * A constant value used in the <code>pixelSnapping</code> property of a Bitmap object
		 * to specify that the bitmap image is snapped to the nearest pixel
		 * if it is drawn with no rotation or skew
		 * and it is drawn at a scale factor of 99.9% to 100.1%.
		 * If these conditions are satisfied, the image is drawn at 100% scale,
		 * snapped to the nearest pixel.
		 * Internally, this setting allows the image to be drawn as fast as possible
		 * by using the vector renderer.
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 1.0
		 */
        public static const AUTO:String = "auto";
	}
}
