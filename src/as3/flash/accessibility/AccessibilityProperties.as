/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.accessibility
{
	/**
	 * The AccessibilityProperties class lets you control the presentation of Flash objects
	 * to accessibility aids, such as screen readers.
	 * 
	 * <p>
	 * You can attach an AccessibilityProperties object to any display object, but Flash Player will read
	 * your AccessibilityProperties object only for certain kinds of objects:
	 * entire SWF files (as represented by <code>DisplayObject.root</code>),
	 * container objects (<code>DisplayObjectContainer</code> and subclasses),
	 * buttons (<code>SimpleButton</code> and subclasses),
	 * and text (<code>TextField</code> and subclasses).
	 * </p>
	 * 
	 * <p>
	 * The name property of these objects is the most important property to specify because accessibility aids provide the names of objects to users as a basic means of navigation. Do not confuse AccessibilityProperties.name with DisplayObject.name; these are separate and unrelated. The AccessibilityProperties.name property is a name that is read aloud by the accessibility aids, whereas DisplayObject.name is essentially a variable name visible only to ActionScript code.
	 * </p>
	 * 
	 * <p>
	 * In Flash Professional, the properties of AccessibilityProperties objects override the corresponding settings available in the Accessibility panel during authoring.
	 * </p>
	 * 
	 * <p>
	 * To determine whether Flash Player is running in an environment that supports accessibility aids, use the Capabilities.hasAccessibility property. If you modify AccessibilityProperties objects, you need to call the Accessibility.updateProperties() method for the changes to take effect.
	 * </p>
	 * 
     * @example
     * <p>
     * The following example uses the <code>AccessibilityExample</code>, <code>CustomAccessibleButton</code>,
     * <code>CustomSimpleButton</code>, and <code>ButtonDisplayState</code> classes to create
     * an accessibility-compliant menu that works with common screen readers.
     * The main functionality of the <code>AccessibilityProperties</code> class is as follows:
     * </p>
     * 
     * <p>
     * <ol>
     *   <li>Call <code>configureAssets</code>, which creates a custom button and sets its label and description. These are the values that the screen reader conveys to the end user.</li>
     *   <li>Call <code>setTimeOut()</code> to ensure that Flash Player has enough time to detect the screen reader before updating the properties.</li>
     * </ol>
     * </p>
     * 
     * <p>
     * <b>Note:</b> Call <code>setTimeout()</code> before checking <code>Accessibility.active</code>.
     * to give Flash Player the 2 seconds it needs to connect to a screen reader, if one is available.
     * If you do not provide a sufficient delay time, the <code>setTimeout</code> call might return false,
     * even if a screen reader is available.
     * </p>
     * 
     * <p>
     * The following example processes the <code>Accessibility.updateProperties()</code> method
     * only if the call to <code>Accessibility.active</code> returns <code>true</code>,
     * which occurs only if Flash Player is currently connected to an active screen reader.
     * If <code>updateProperties</code> is called without an active screen reader,
     * it throws an <code>IllegalOperationError</code> exception.
     * </p>
     * 
     * <listing>
     * package {
     *     import flash.display.Sprite;
     *     import flash.accessibility.Accessibility;
     *     import flash.utils.setTimeout;
     *     
     *     public class AccessibilityPropertiesExample extends Sprite {
     *         public static const BUTTON_WIDTH:uint = 90;
     *         public static const BUTTON_HEIGHT:uint = 20;
     *         
     *         private var gutter:uint = 5;
     *         private var menuLabels:Array = new Array("PROJECTS", "PORTFOLIO", "CONTACT");
     *         private var menuDescriptions:Array = new Array("Learn more about our projects"
     *                                                      , "See our portfolio"
     *                                                      , "Get in touch with our team");
     *         
     *         public function AccessibilityPropertiesExample() {
     *             configureAssets();
     *             setTimeout(updateAccessibility, 2000); 
     *         }
     *         
     *         private function updateAccessibility():void {
     *             trace("Accessibility.active: " + Accessibility.active);
     *             if(Accessibility.active) {
     *                 Accessibility.updateProperties();
     *             }
     *         }
     *         
     *         private function configureAssets():void {
     *             var child:CustomAccessibleButton;
     *             for(var i:uint; i &lt; menuLabels.length; i++) {
     *                 child = new CustomAccessibleButton();
     *                 child.y = (numChildren &#42; (BUTTON_HEIGHT + gutter));
     *                 child.setLabel(menuLabels[i]);
     *                 child.setDescription(menuDescriptions[i]);
     *                 addChild(child);
     *             }
     *         }
     *     }
     * 
     * 
     * import flash.accessibility.AccessibilityProperties;
     * import flash.display.Shape;
     * import flash.display.SimpleButton;
     * import flash.display.Sprite;
     * import flash.events.Event;
     * import flash.text.TextFormat;
     * import flash.text.TextField;
     *     
     * class CustomAccessibleButton extends Sprite {
     *     private var button:SimpleButton;
     *     private var label1:TextField;
     *     private var description:String;
     *     private var _name:String;
     *         
     *     public function CustomAccessibleButton(_width:uint = 0, _height:uint = 0) {
     *         _width = (_width == 0) ? AccessibilityPropertiesExample.BUTTON_WIDTH : _width;
     *         _height = (_height == 0) ? AccessibilityPropertiesExample.BUTTON_HEIGHT : _height;
     *             
     *         button = buildButton(_width, _height);
     *         label1 = buildLabel(_width, _height);
     *             
     *         addEventListener(Event.ADDED, addedHandler);
     *     }
     *         
     *     private function addedHandler(event:Event):void {
     *         trace("addedHandler: " + name);
     *         var accessProps:AccessibilityProperties = new AccessibilityProperties();
     *         accessProps.name = this._name;
     *         accessProps.description = description;
     *         accessibilityProperties = accessProps;
     *         removeEventListener(Event.ADDED, addedHandler);
     *     }
     *         
     *     private function buildButton(_width:uint, _height:uint):SimpleButton {
     *         var child:SimpleButton = new CustomSimpleButton(_width, _height);
     *         addChild(child);
     *         return child;
     *     }
     * 
     *     private function buildLabel(_width:uint, _height:uint):TextField {
     *         var format:TextFormat = new TextFormat();
     *         format.font = "Verdana";
     *         format.size = 11;
     *         format.color = 0xFFFFFF;
     *         format.align = TextFormatAlign.CENTER;
     *         format.bold = true;
     *             
     *         var child:TextField = new TextField();
     *         child.y = 1;
     *         child.width = _width;
     *         child.height = _height;
     *         child.selectable = false;
     *         child.defaultTextFormat = format;
     *         child.mouseEnabled = false;
     *             
     *         addChild(child);
     *         return child;
     *     }
     *         
     *     public function setLabel(text:String):void {
     *         label1.text = text;
     *         this._name = text;
     *     }
     *         
     *     public function setDescription(text:String):void {
     *         description = text;
     *     }
     * }
     *     
     * class CustomSimpleButton extends SimpleButton {
     *     private var upColor:uint = 0xFFCC00;
     *     private var overColor:uint = 0xCCFF00;
     *     private var downColor:uint = 0x00CCFF;
     * 
     *     public function CustomSimpleButton(_width:uint, _height:uint) {
     *         downState = new ButtonDisplayState(downColor, _width, _height);
     *         overState = new ButtonDisplayState(overColor, _width, _height);
     *         upState = new ButtonDisplayState(upColor, _width, _height);
     *         hitTestState = new ButtonDisplayState(upColor, _width, _height);
     *         useHandCursor = true;
     *     }        
     * }
     * 
     * class ButtonDisplayState extends Shape {
     *     private var bgColor:uint;
     *     private var _width:uint;
     *     private var _height:uint;
     * 
     *     public function ButtonDisplayState(bgColor:uint, _width:uint, _height:uint) {
     *         this.bgColor = bgColor;
     *         this._width = _width;
     *         this._height = _height;
     *         draw();
     *     }
     * 
     *     private function draw():void {
     *         graphics.beginFill(bgColor);
     *         graphics.drawRect(0, 0, _width, _height);
     *         graphics.endFill();
     *     }
     * }
     * }
     * 
     * </listing>
     * 
     * @langversion 3.0
     * @playerversion Flash 9
     * @playerversion AIR 1.0
     * 
     * @see flash.accessibility.Accessibility#updateProperties()
     * @see flash.display.DisplayObject#accessibilityProperties
     * @see flash.display.InteractiveObject#tabIndex
     * @see flash.system.Capabilities#hasAccessibility
	 */
	public class AccessibilityProperties
	{

		/**
		 * 
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 1.0
		 */
        public var name:String;

		/**
		 * 
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 1.0
		 */
        public var description:String;

		/**
		 * 
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 1.0
		 */
        public var shortcut:String;

		/**
		 * 
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 1.0
		 */
        public var silent:Boolean;

		/**
		 * 
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 1.0
		 */
        public var forceSimple:Boolean;

		/**
		 * 
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 1.0
		 */
        public var noAutoLabeling:Boolean;

		/**
		 * 
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 1.0
		 */
        public function AccessibilityProperties()
        {
        	super();
            name           = "";
            description    = "";
            shortcut       = "";
            silent         = false;
            forceSimple    = false;
            noAutoLabeling = false;
        }
	}
}
