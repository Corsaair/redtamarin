/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.accessibility
{
	import flash.geom.Rectangle;

	/**
	 * The AccessibilityImplementation class is the base class in Flash Player that allows for the implementation of accessibility in components. This class enables communication between a component and a screen reader. Screen readers are used to translate screen content into synthesized speech or braille for visually impaired users.
	 * 
	 * <p>
	 * The AccessibilityImplementation class provides a set of methods that allow a component developer to make information about system roles, object based events, and states available to assistive technology.
	 * </p>
	 * 
	 * <p>
	 * Adobe Flash Player uses Microsoft Active Accessibility (MSAA), which provides a descriptive and standardized way for applications and screen readers to communicate. For more information on how the Flash Player works with MSAA, see the accessibility chapter in <i>Using Flex SDK</i>.
	 * </p>
	 * 
	 * <p>
	 * The methods of the AccessibilityImplementation class are a subset of the <a href="http://msdn.microsoft.com/en-us/library/ms696097(VS.85).aspx">IAccessible</a> interface for a component instance.
	 * </p>
	 * 
	 * <p>
	 * The way that an AccessibilityImplementation implements the IAccessible interface, and the events that it sends, depend on the kind of component being implemented.
	 * </p>
	 * 
	 * <p>
	 * Do not directly instantiate AccessibilityImplementation by calling its constructor. Instead, create new accessibility implementations by extending the AccImpl class for each new component. In Flash, see the fl.accessibility package. In Flex, see the mx.accessibility package and the accessibility chapter in <i>Using Flex SDK</i>.
	 * </p>
	 * 
	 * <p>
	 * <b>Note:</b> The AccessibilityImplementation class is not supported in AIR runtime versions before AIR 2. The class is available for compilation in AIR versions before AIR 2, but is not supported in the runtime until AIR 2.
	 * </p>
	 * 
     * @langversion 3.0
     * @playerversion Flash 9
     * @playerversion AIR 2.0
     * 
     * @see http://msdn.microsoft.com/en-us/library/ms696097(VS.85).aspx IAccessible
	 */
	[API(AVMGLUE::AIR_2_0)]
	public class AccessibilityImplementation
	{

		/**
		 * Indicates an error code.
		 * Errors are indicated out-of-band, rather than in return values.
		 * To indicate an error, set the <code>errno</code> property to one of the error codes
		 * documented in the AccessibilityImplementation Constants appendix.
		 * This causes your return value to be ignored.
		 * The <code>errno</code> property of your AccessibilityImplementation is always cleared
		 * (set to zero) by the player before any AccessibilityImplementation method is called.
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 2.0
	     * 
	     * @see http://help.adobe.com/en_US/FlashPlatform/reference/actionscript/3/accessibilityImplementationConstants.html AccessibilityImplementation Constants
		 */
        public var errno:uint;

		/**
		 * Used to create a component accessibility stub.
		 * If a component is released without an ActionScript accessibility implementation,
		 * Adobe recommends that you add a component accessibility stub.
		 * This stub causes Flash Player, for accessibility purposes, to treat the component
		 * as a simple graphic rather than exposing the internal structure of buttons,
		 * textfields, and so on, within the component.
		 * 
		 * <p>
		 * To create a component accessibility stub, subclass the relevant AccImpl class,
		 * overriding the property stub with a value of <code>true</code>.
		 * </p>
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 2.0
	     * 
	     * @see The mx.accessibility.AccImpl class in Flex (\sdks\4.0.0\frameworks\projects\framework\src\mx\accessibility\AccImpl.as)
	     * @see The fl.accessibility.AccImpl class in Flash (\Local Settings\Application Data\Adobe\Flash CS5\en_US\Configuration\Classes\mx\accessibility\AccImpl.as)
		 */
        public var stub:Boolean;

		/**
		 * Static constructor.
		 * Do not directly instantiate AccessibilityImplementation by calling its constructor.
		 * Instead, create new accessibility implementations by extending
		 * the <code>mx.accessibility.AccImpl</code> class for each new component.
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 2.0
	     * 
	     * @see mx.accessibility.AccImpl
		 */
        public function AccessibilityImplementation()
        {
            super();
            stub  = false;
            errno = 0;
        }

		/**
		 * MSAA method for returning the system role for the component that
		 * this AccessibilityImplementation represents or for one of its child elements.
		 * System roles are predefined for all the components in MSAA.
		 * 
		 * @param childID An unsigned integer corresponding to one of the component's child
		 * elements as defined by <code>getChildIDArray()</code>.
		 * 
		 * @throw Error Error code 2143, AccessibilityImplementation.get_accRole() must be overridden from its default.
		 * @return System role associated with the component.
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 2.0
	     * 
	     * @see getChildIDArray()
	     * @see http://help.adobe.com/en_US/FlashPlatform/reference/actionscript/3/accessibilityImplementationConstants.html AccessibilityImplementation Constants: Object Role Constants
	     * @see http://msdn.microsoft.com/en-us/library/ms696113(VS.85).aspx Microsoft Accessibility Developer Center: IAccessible::get_accRole
		 */
        public function get_accRole( childID:uint ):uint
        {
            Error.throwError( Error, 2143 );
            return 0;
        }
        
		/**
		 * 
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 2.0
	     * 
	     * @see 
		 */
        public function get_accName( childID:uint ):String
        {
            return null;
        }

		/**
		 * 
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 2.0
	     * 
	     * @see 
		 */
        public function get_accValue(childID:uint):String
        {
            return null;
        }

		/**
		 * 
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 2.0
	     * 
	     * @see 
		 */
        public function get_accState(childID:uint):uint
        {
            Error.throwError( Error, 2144 );
            return 0;
        }

		/**
		 * 
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 2.0
	     * 
	     * @see 
		 */
        public function get_accDefaultAction(childID:uint):String
        {
            return null;
        }

		/**
		 * 
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 2.0
	     * 
	     * @see 
		 */
        public function accDoDefaultAction(childID:uint):void
        {

        }

		/**
		 * 
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 2.0
	     * 
	     * @see 
		 */
        public function isLabeledBy(labelBounds:Rectangle):Boolean
        {
            return false;
        }

		/**
		 * 
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 2.0
	     * 
	     * @see 
		 */
        public function getChildIDArray():Array
        {
            return null;
        }

		/**
		 * 
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 2.0
	     * 
	     * @see 
		 */
        public function accLocation(childID:uint)
        {
            return null;
        }

		/**
		 * 
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 2.0
	     * 
	     * @see 
		 */
        public function get_accSelection():Array
        {
            return null;
        }

		/**
		 * 
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 2.0
	     * 
	     * @see 
		 */
        public function get_accFocus():uint
        {
            return 0;
        }

		/**
		 * 
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 2.0
	     * 
	     * @see 
		 */
        public function accSelect(operation:uint, childID:uint):void
        {

        }

		/**
		 * 
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 2.0
	     * 
	     * @see 
		 */
        public function get_selectionAnchorIndex():*
        {
            return this["selectionAnchorIndex"];
        }

		/**
		 * 
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 2.0
	     * 
	     * @see 
		 */
        public function get_selectionActiveIndex():*
        {
            return this["selectionActiveIndex"];
        }
	}
}
