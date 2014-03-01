/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.utils
{
    /**
     * The Endian class contains values that denote the byte order used to represent multibyte numbers.
     * The byte order is either bigEndian (most significant byte first)
     * or littleEndian (least significant byte first).
     *
     * @langversion 3.0
     * @playerversion Flash 9
     * @playerversion AIR 1.0
	 *
	 * @see flash.utils.ByteArray#endian
     */
    public class Endian
    {
    	/**
    	 * Indicates the most significant byte of the multibyte number appears first in the sequence of bytes.
    	 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 1.0
    	 */
        public static const BIG_ENDIAN:String = "bigEndian";

    	/**
    	 * Indicates the least significant byte of the multibyte number appears first in the sequence of bytes.
    	 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 1.0
    	 */
        public static const LITTLE_ENDIAN:String = "littleEndian";
    }
}
