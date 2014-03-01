/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.accessibility
{
	/**
	 * The ISearchableText interface can be implemented by objects
	 * that contain text which should be searchable on the web.
	 * 
     * @langversion 3.0
     * @playerversion Flash 10.1
     * @playerversion AIR 1.0
	 */
	[API(AVMGLUE::FP_10_1,AVMGLUE::AIR_1_0)]
	public interface ISearchableText
	{
		/**
		 * Gets the search text from a component implementing ISearchableText.
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 10.1
	     * @playerversion AIR 1.0
		 */
		function get searchText():String;
	}
}
