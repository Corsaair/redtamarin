/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.display
{
	/**
	 * The StageOrientation class defines constants enumerating
     * the possible orientations of the stage and the device.
	 * 
     * @langversion 3.0
     * @playerversion AIR 2.0
     * 
     * @see flash.display.Stage#orientation
     * @see flash.display.Stage#setOrientation()
     * @see flash.display.Stage#deviceOrientation
     * @see flash.events.StageOrientationEvent#afterOrientation
     * @see flash.events.StageOrientationEvent#beforeOrientation
	 */
    [API(AVMGLUE::AIR_2_0)]
	public final class StageOrientation
	{
        /**
         * Specifies that the stage is currently in the default orientation
         * of the device (right-side up).
         * 
         * @langversion 3.0
         * @playerversion AIR 2.0
         */
        public static const DEFAULT:String = "default";

        /**
         * Specifies that the stage is currently rotated left relative to the default orientation.
         * 
         * <p>
         * <b>Note:</b> When the orientation of the device is rotated left,
         * the orientation of the stage must be rotated right in order to remain upright.
         * </p>
         * 
         * @langversion 3.0
         * @playerversion AIR 2.0
         */
        public static const ROTATED_LEFT:String = "rotatedLeft";

        /**
         * Specifies that the stage is currently rotated right relative to the default orientation.
         * 
         * <p>
         * <b>Note:</b> When the orientation of the device is rotated right,
         * the orientation of the stage must be rotated left in order to remain upright.
         * </p>
         * 
         * @langversion 3.0
         * @playerversion AIR 2.0
         */
        public static const ROTATED_RIGHT:String = "rotatedRight";

        /**
         * Specifies that the device has not determined an orientation.
         * This state can occur when the device is lying flat on a table
         * and also while the application is initializing.
         * 
         * @langversion 3.0
         * @playerversion AIR 2.0
         */
        public static const UNKNOWN:String = "unknown";

        /**
         * Specifies that the stage is currently upside down relative to the default orientation.
         * 
         * @langversion 3.0
         * @playerversion AIR 2.0
         */
        public static const UPSIDE_DOWN:String = "upsideDown";
	}
}
