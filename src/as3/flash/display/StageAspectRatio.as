/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.display
{
	/**
	 * The StageAspectRatio class provides values
     * for the <code>Stage.setAspectRatio()</code> method.
	 * 
     * @langversion 3.0
     * @playerversion AIR 2.0
     * 
     * @see flash.display.Stage#setAspectRatio()
	 */
    [API(AVMGLUE::AIR_2_0)]
	public final class StageAspectRatio
	{
        /**
         * Specifies a device orientation that supports both portrait and landscape UI.
         * Requires SWF version 16 or higher.
         * 
         * @langversion 3.0
         * @playerversion AIR 3.3
         */
        [API(AVMGLUE::AIR_3_3)]
		public static const ANY:String = "any";

        /**
         * Specifies a device orientation that presents a landscape UI.
         * 
         * @langversion 3.0
         * @playerversion AIR 2.0
         */
        public static const LANDSCAPE:String = "landscape";

        /**
         * Specifies a device orientation that presents a portrait UI.
         * 
         * @langversion 3.0
         * @playerversion AIR 2.0
         */
        public static const PORTRAIT:String = "portrait";
	}
}
