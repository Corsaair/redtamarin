/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.accessibility
{
	/**
	 * The ISimpleTextSelection class can be used to add support
	 * for the MSAA ISimpleTextSelection interface to an AccessibilityImplementation.
	 * 
	 * <p>
	 * If an AccessibilityImplementation subclass implements the two getters in this class,
	 * a screen reader such as JAWS can determine the text selection range by calling them.
	 * The AccessibilityImplementation subclass does not have to formally declare that
	 * it implements this interface;
	 * you can simply declare getters for these two properties, as follows:
	 * </p>
	 * 
     * @example
     * <listing>
     * class TextAreaAccImpl extends AccesibilityImplementation
     * {
     *  ...
     *      public function get selectionAnchorIndex():int
     *      {
	 *        ...
     *      }
     *      
     *      public function get selectionActiveIndex():int
     *      {
	 *        ...
     *      }
     *  ...
     * }
     * </listing>
     * 
     * @langversion 3.0
     * @playerversion Flash 10.1
     * @playerversion AIR 1.0
     * 
     * @see flash.accessibility.AccessibilityImplementation
	 */
	[API(AVMGLUE::FP_10_1,AVMGLUE::AIR_1_0)]
	public interface ISimpleTextSelection
	{
        
		/**
		 * The zero-based character index value of the first character in the current selection.
		 * If you want a component to support inline IME or accessibility, override this method.
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 10.1
	     * @playerversion AIR 1.0
		 */
        function get selectionAnchorIndex():int;

		/**
		 * The zero-based character index value of the last character in the current selection.
		 * If you want a component to support inline IME or accessibility, override this method.
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 10.1
	     * @playerversion AIR 1.0
		 */
        function get selectionActiveIndex():int;
	}
}
