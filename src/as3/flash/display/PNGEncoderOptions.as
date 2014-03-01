/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.display
{
	/**
	 * The PNGEncoderOptions class defines a compression algorithm
	 * for the <code>flash.display.BitmapData.encode()</code> method.
	 * 
     * @langversion 3.0
     * @playerversion Flash 11.3
     * @playerversion AIR 3.3
     * 
     * @see flash.display.BitmapData
     * @see flash.display.BitmapData#encode()
     * @see Compressing bitmap data
	 */
	[API(AVMGLUE::SWF_16,AVMGLUE::AIR_3_3)]
	public final class PNGEncoderOptions
	{
		/**
		 * Chooses compression speed over file size.
		 * Setting this property to true improves compression speed but creates larger files.
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 11.3
	     * @playerversion AIR 3.3
		 */
		public var fastCompression:Boolean;

		/**
		 * Creates a PNGEncoderOptions object, optionally specifying compression settings.
		 * 
		 * @param fastCompression The initial compression mode.
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 11.3
	     * @playerversion AIR 3.3
		 */
		public function PNGEncoderOptions( fastCompression:Boolean = false )
		{
			super();
			this.fastCompression = fastCompression;
		}
	}
}
