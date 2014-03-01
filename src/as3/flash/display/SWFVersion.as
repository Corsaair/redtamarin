/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.display
{
	/**
	 * The SWFVersion class is an enumeration of constant values that indicate
	 * the file format version of a loaded SWF file.
	 * The SWFVersion constants are provided for use in checking the <code>swfVersion</code> property
	 * of a <code>flash.display.LoaderInfo</code> object.
	 * 
     * @langversion 3.0
     * @playerversion Flash 9
     * @playerversion AIR 1.0
     * 
     * @see flash.display.LoaderInfo#swfVersion
     * @see http://www.adobe.com/devnet/articles/flashplayer-air-feature-list.html Flash Player and Adobe AIR feature list
	 */
	public final class SWFVersion
	{
        /**
         * SWF file format version 1.0.
         * 
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         */
        public static const FLASH1:uint  =  1;

        /**
         * SWF file format version 2.0.
         * 
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         */
        public static const FLASH2:uint  =  2;

        /**
         * SWF file format version 3.0.
         * 
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         */
        public static const FLASH3:uint  =  3;

        /**
         * SWF file format version 4.0.
         * 
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         */
        public static const FLASH4:uint  =  4;

        /**
         * SWF file format version 5.0.
         * 
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         */
        public static const FLASH5:uint  =  5;

        /**
         * SWF file format version 6.0.
         * 
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         */
        public static const FLASH6:uint  =  6;

        /**
         * SWF file format version 7.0.
         * 
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         */
        public static const FLASH7:uint  =  7;

        /**
         * SWF file format version 8.0.
         * 
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         */
        public static const FLASH8:uint  =  8;

        /**
         * SWF file format version 9.0.
         * 
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         */
        public static const FLASH9:uint  =  9;

        /**
         * SWF file format version 10.0.
         * 
         * @langversion 3.0
         * @playerversion Flash 10
         * @playerversion AIR 2.0
         */
        [API(AVMGLUE::FP_10_0)]
        public static const FLASH10:uint = 10;

        /**
         * SWF file format version 10.2.
         * 
         * @langversion 3.0
         * @playerversion Flash 10.2
         * @playerversion AIR 2.6
         */
        [API(AVMGLUE::FP_10_2)]
        public static const FLASH11:uint = 11;

        /**
         * SWF file format version 10.3.
         * 
         * @langversion 3.0
         * @playerversion Flash 10.3
         * @playerversion AIR 2.7
         */
        [API(AVMGLUE::SWF_12)]
        public static const FLASH12:uint = 12;


        /* note:
           not part of the official Flah API
           we fixed it for you Adobe!
        */

        /**
         * SWF file format version 11.0.
         * 
         * @langversion 3.0
         * @playerversion Flash 11
         * @playerversion AIR 3.0
         */
        [API(AVMGLUE::SWF_13)]
        public static const FLASH13:uint = 13;

        /**
         * SWF file format version 11.1.
         * 
         * @langversion 3.0
         * @playerversion Flash 11.1
         * @playerversion AIR 3.1
         */
        [API(AVMGLUE::SWF_14)]
        public static const FLASH14:uint = 14;

        /**
         * SWF file format version 11.2.
         * 
         * @langversion 3.0
         * @playerversion Flash 11.2
         * @playerversion AIR 3.2
         */
        [API(AVMGLUE::SWF_15)]
        public static const FLASH15:uint = 15;

        /**
         * SWF file format version 11.3.
         * 
         * @langversion 3.0
         * @playerversion Flash 11.3
         * @playerversion AIR 3.3
         */
        [API(AVMGLUE::SWF_16)]
        public static const FLASH16:uint = 16;

        /**
         * SWF file format version 11.4.
         * 
         * @langversion 3.0
         * @playerversion Flash 11.4
         * @playerversion AIR 3.4
         */
        [API(AVMGLUE::SWF_17)]
        public static const FLASH17:uint = 17;

        /**
         * SWF file format version 11.5.
         * 
         * @langversion 3.0
         * @playerversion Flash 11.5
         * @playerversion AIR 3.5
         */
        [API(AVMGLUE::SWF_18)]
        public static const FLASH18:uint = 18;

        /**
         * SWF file format version 11.6.
         * 
         * @langversion 3.0
         * @playerversion Flash 11.6
         * @playerversion AIR 3.6
         */
        [API(AVMGLUE::SWF_19)]
        public static const FLASH19:uint = 19;

        //[API(AVMGLUE::SWF_20)]
        //public static const FLASH20:uint = 20;

        //[API(AVMGLUE::SWF_21)]
        //public static const FLASH21:uint = 21;

        //[API(AVMGLUE::SWF_22)]
        //public static const FLASH22:uint = 22;
        
        //[API(AVMGLUE::SWF_23)]
        //public static const FLASH23:uint = 23;
	}
}
