/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.display
{
	/**
	 * The StageQuality class provides values for the <code>Stage.quality</code> property
	 * and for the value of the <code>quality</code> parameter to the <code>BitmapData.drawWithQuality()</code> method.
	 * 
	 * <p>
	 * Higher quality settings produce better rendering of scaled bitmaps.
	 * However, higher quality settings are computationally more expensive.
	 * In particular, when rendering scaled video, using higher quality settings
	 * can reduce the frame rate.
	 * </p>
	 * 
	 * <p>
	 * In the desktop profile of Adobe AIR, <code>quality</code> can be set to
	 * <code>StageQuality.BEST</code> or <code>StageQuality.HIGH</code>
	 * (and the default value is <code>StageQuality.HIGH</code>).
	 * Attempting to set it to another value has no effect (and the property remains unchanged).
	 * 
	 * In the mobile profile of AIR, all four quality settings are available.
	 * The default value on mobile devices is <code>StageQuality.MEDIUM</code>.
	 * </p>
	 * 
	 * <p>
	 * For content running in Adobe AIR, setting the <code>quality</code> property
	 * of one Stage object changes the rendering quality for all Stage objects
	 * (used by different NativeWindow objects).
	 * </p>
	 * 
	 * <p>
	 * <b>Note:</b> The operating system draws the device fonts,
	 * which are therefore unaffected by the <code>quality</code> property.
	 * </p>
	 * 
     * @langversion 3.0
     * @playerversion Flash 9
     * @playerversion AIR 1.0
     * 
     * @see flash.display.Stage#quality
     * @see flash.display.BitmapData#drawWithQuality()
	 */
	public final class StageQuality
	{

		/**
		 * Specifies low rendering quality.
		 * Graphics are not anti-aliased, and bitmaps are not smoothed,
		 * but runtimes still use mip-mapping.
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 1.0
		 */
        public static const LOW:String = "low";

		/**
		 * Specifies medium rendering quality.
		 * Graphics are anti-aliased using a 2 x 2 pixel grid,
		 * bitmap smoothing is dependent on the <code>Bitmap.smoothing</code> setting.
		 * Runtimes use mip-mapping.
		 * This setting is suitable for movies that do not contain text.
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 1.0
		 */
        public static const MEDIUM:String = "medium";

		/**
		 * Specifies high rendering quality.
		 * Graphics are anti-aliased using a 4 x 4 pixel grid,
		 * and bitmap smoothing is dependent on the <code>Bitmap.smoothing</code> setting.
		 * Runtimes use mip-mapping.
		 * This is the default rendering quality setting that Flash Player uses.
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 1.0
		 */
        public static const HIGH:String = "high";

		/**
		 * Specifies very high rendering quality.
		 * Graphics are anti-aliased using a 4 x 4 pixel grid.
		 * If <code>Bitmap.smoothing</code> is <code>true</code> the runtime uses a high quality
		 * downscale algorithm that produces fewer artifacts
		 * (however, using <code>StageQuality.BEST</code> with <code>Bitmap.smoothing</code>
		 * set to <code>true</code> slows performance significantly
		 * and is not a recommended setting).
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 1.0
		 */
        public static const BEST:String = "best";

		/**
		 * Specifies very high rendering quality.
		 * Graphics are anti-aliased using a 8 x 8 pixel grid.
		 * If <code>Bitmap.smoothing</code> is <code>true</code> the runtime uses a high quality
		 * downscale algorithm that produces fewer artifacts
		 * (however, using <code>StageQuality.HIGH_8X8</code> with <code>Bitmap.smoothing</code>
		 * set to <code>true</code> slows performance significantly
		 * and is not a recommended setting).
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 11.3
	     * @playerversion AIR 1.0
		 */
		[API(AVMGLUE::SWF_16)]
        public static const HIGH_8X8:String = "8x8";

		/**
		 * Specifies very high rendering quality.
		 * Graphics are anti-aliased using a 8 x 8 pixel grid.
		 * Antialiasing is generated in linear sRGB space.
		 * If <code>Bitmap.smoothing</code> is <code>true</code> the runtime uses a high quality
		 * downscale algorithm that produces fewer artifacts
		 * (however, using <code>StageQuality.HIGH_8X8_LINEAR</code> with <code>Bitmap.smoothing</code>
		 * set to <code>true</code> slows performance significantly
		 * and is not a recommended setting).
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 11.3
	     * @playerversion AIR 1.0
		 */
		[API(AVMGLUE::SWF_16)]
        public static const HIGH_8X8_LINEAR:String = "8x8linear";

		/**
		 * Specifies very high rendering quality.
		 * Graphics are anti-aliased using a 16 x 16 pixel grid.
		 * If <code>Bitmap.smoothing</code> is <code>true</code> the runtime uses a high quality
		 * downscale algorithm that produces fewer artifacts
		 * (however, using <code>StageQuality.HIGH_16X16</code> with <code>Bitmap.smoothing</code>
		 * set to <code>true</code> slows performance significantly
		 * and is not a recommended setting).
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 11.3
	     * @playerversion AIR 1.0
		 */
		[API(AVMGLUE::SWF_16)]
        public static const HIGH_16X16:String = "16x16";

		/**
		 * Specifies very high rendering quality.
		 * Graphics are anti-aliased using a 16 x 16 pixel grid.
		 * Antialiasing is generated in linear sRGB space.
		 * If <code>Bitmap.smoothing</code> is <code>true</code> the runtime uses a high quality
		 * downscale algorithm that produces fewer artifacts
		 * (however, using <code>StageQuality.HIGH_16X16_LINEAR</code> with <code>Bitmap.smoothing</code>
		 * set to <code>true</code> slows performance significantly
		 * and is not a recommended setting).
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 11.3
	     * @playerversion AIR 1.0
		 */
		[API(AVMGLUE::SWF_16)]
        public static const HIGH_16X16_LINEAR:String = "16x16linear";
	}
}
