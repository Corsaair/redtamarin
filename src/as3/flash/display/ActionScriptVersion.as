/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.display
{
	/**
	 * The ActionScriptVersion class is an enumeration of constant values that indicate
	 * the language version of a loaded SWF file.
	 * The language version constants are provided for use in checking
	 * the <code>actionScriptVersion</code> property of a <code>flash.display.LoaderInfo</code> object.
	 * 
     * @langversion 3.0
     * @playerversion Flash 9
     * @playerversion AIR 1.0
     * 
     * @see flash.display.LoaderInfo#actionScriptVersion
	 */
	public final class ActionScriptVersion
	{
        /**
         * ActionScript language version 2.0 and earlier.
         * 
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         */
		public static const ACTIONSCRIPT2:uint = 2;

        /**
         * ActionScript language version 3.0.
         * 
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         */
		public static const ACTIONSCRIPT3:uint = 3;
	}
}
