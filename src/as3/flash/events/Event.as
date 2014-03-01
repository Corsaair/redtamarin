/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.events
{
	/* IMPORTANT:
	   this code is alpha quality
	   for proof of concept
	   use at your own risk
	*/

	/**
	 * The Event class is used as the base class for the creation of Event objects,
	 * which are passed as parameters to event listeners when an event occurs.
	 *
	 * <p>TODO</p>
	 * 
	 * @playerversion Flash 9
	 * @playerversion AIR 1.0
	 * @langversion 3.0
	 */
	public class Event
	{

		/**
		 * The <code>ACTIVATE</code> constant defines the value of the <code>type</code> property
		 * of an <code>activate</code> event object.
		 *
		 * <p>
		 * <b>Note: </b> This event has neither a "capture phase" nor a "bubble phase",
		 * which means that event listeners must be added directly to any potential targets,
		 * whether the target is on the display list or not.
		 * </p>
		 *
		 * <p>
		 * AIR for TV devices never automatically dispatch this event. You can, however, dispatch it manually.
		 * </p>
		 *
		 * <p>
		 * This event has the following properties:
		 *
	     * <table class="innertable">
	     * <tr>
	     *      <th>Property</th>
	     *      <th>Value</th>
	     * </tr>
	     * <tr>
	     *      <td><code>bubbles</code></td>
	     *      <td><code>false</code></td>
	     * </tr>
	     * <tr>
	     *      <td><code>cancelable</code></td>
	     *      <td><code>false</code>; there is no default behavior to cancel.</td>
	     * </tr>
	     * <tr>
	     *      <td><code>currentTarget</code></td>
	     *      <td>The object that is actively processing the Event object with an event listener.</td>
	     * </tr>
	     * <tr>
	     *      <td><code>target</code></td>
	     *      <td>Any DisplayObject instance with a listener registered for the <code>activate</code> event.</td>
	     * </tr>
	     * </table>
		 * </p>
		 * 
		 * @playerversion Flash 9
		 * @playerversion AIR 1.0
		 * @langversion 3.0
		 *
		 * @see flash.events.EventDispatcher#activate
		 * @see DEACTIVATE
		 */
        public static const ACTIVATE:String = "activate";

        public static const ADDED:String = "added";
        public static const ADDED_TO_STAGE:String = "addedToStage";
        public static const CANCEL:String = "cancel";
        public static const CHANGE:String = "change";
        public static const CLEAR:String = "clear";
        public static const CLOSE:String = "close";
        public static const COMPLETE:String = "complete";
        public static const CONNECT:String = "connect";
        public static const COPY:String = "copy";
        public static const CUT:String = "cut";
        public static const DEACTIVATE:String = "deactivate";
        public static const ENTER_FRAME:String = "enterFrame";
        public static const FRAME_CONSTRUCTED:String = "frameConstructed";
        public static const EXIT_FRAME:String = "exitFrame";
        public static const FRAME_LABEL:String = "frameLabel";
        public static const ID3:String = "id3";
        public static const INIT:String = "init";
        public static const MOUSE_LEAVE:String = "mouseLeave";
        public static const OPEN:String = "open";
        public static const PASTE:String = "paste";
        public static const REMOVED:String = "removed";
        public static const REMOVED_FROM_STAGE:String = "removedFromStage";
        public static const RENDER:String = "render";
        public static const RESIZE:String = "resize";
        public static const SCROLL:String = "scroll";
        public static const TEXT_INTERACTION_MODE_CHANGE:String = "textInteractionModeChange";
        public static const SELECT:String = "select";
        public static const SELECT_ALL:String = "selectAll";
        public static const SOUND_COMPLETE:String = "soundComplete";
        public static const TAB_CHILDREN_CHANGE:String = "tabChildrenChange";
        public static const TAB_ENABLED_CHANGE:String = "tabEnabledChange";
        public static const TAB_INDEX_CHANGE:String = "tabIndexChange";
        public static const UNLOAD:String = "unload";
        public static const FULLSCREEN:String = "fullScreen";
        public static const CONTEXT3D_CREATE:String = "context3DCreate";
        public static const TEXTURE_READY:String = "textureReady";
        public static const VIDEO_FRAME:String = "videoFrame";
        public static const SUSPEND:String = "suspend";
        public static const CHANNEL_MESSAGE:String = "channelMessage";
        public static const CHANNEL_STATE:String = "channelState";
        public static const WORKER_STATE:String = "workerState";
        public static const CLOSING:String = "closing";
        public static const EXITING:String = "exiting";
        public static const DISPLAYING:String = "displaying";
        public static const PREPARING:String = "preparing";
        public static const NETWORK_CHANGE:String = "networkChange";
        public static const USER_IDLE:String = "userIdle";
        public static const USER_PRESENT:String = "userPresent";
        public static const STANDARD_OUTPUT_CLOSE:String = "standardOutputClose";
        public static const STANDARD_ERROR_CLOSE:String = "standardErrorClose";
        public static const STANDARD_INPUT_CLOSE:String = "standardInputClose";
        public static const HTML_BOUNDS_CHANGE:String = "htmlBoundsChange";
        public static const HTML_RENDER:String = "htmlRender";
        public static const HTML_DOM_INITIALIZE:String = "htmlDOMInitialize";
        public static const LOCATION_CHANGE:String = "locationChange";




        private var _type:String;
        private var _bubbles:Boolean;
        private var _cancelable:Boolean;

        private var _target:Object;
        private var _currenttarget:Object;
        private var _currentphase:uint;
        private var _preventdefault = false;

        /**
         * Creates an Event object to pass as a parameter to event listeners.
         * 
         * @param type The type of the event, accessible as <code>Event.type</code>.
         * @param bubbles Determines whether the Event object participates in the bubbling stage
         * of the event flow.
         * The default value is <code>false</code>.
         * @param cancelable Determines whether the Event object can be canceled.
         * The default values is <code>false</code>.
         *
		 * @playerversion Flash 9
		 * @playerversion AIR 1.0
		 * @langversion 3.0
         */
		public function Event( type:String, bubbles:Boolean = false, cancelable:Boolean = false )
		{
			trace( "Event ctor" );
			super();
			ctor( type, bubbles, cancelable );
		}

		//private native function ctor( type:String, bubbles:Boolean, cancelable:Boolean ):void;
		private function ctor( type:String, bubbles:Boolean, cancelable:Boolean ):void
		{
			trace( "Event.ctor(), type = " + type );
			_type       = type;
			_bubbles    = bubbles;
			_cancelable = cancelable;
		}

		//public native function get type():String;
		public function get type():String
		{
			//trace( "Event.get type" );
			return _type;
		}

		/**
		 * Indicates whether an event is a bubbling event.
		 * If the event can bubble, this value is <code>true</code>; otherwise it is <code>false</code>.
		 *
		 * @playerversion Flash 9
		 * @playerversion AIR 1.0
		 * @langversion 3.0
		 */
		//public native function get bubbles():Boolean;
		public function get bubbles():Boolean
		{
			//trace( "Event.get bubbles" );
			return _bubbles;
		}

		//public native function get cancelable():Boolean;
		public function get cancelable():Boolean
		{
			//trace( "Event.get cancelable" );
			return _cancelable;
		}

		//public native function get target():Object;
		public function get target():Object
		{
			//trace( "Event.get target" );
			return _target;
		}

		//public native function get currentTarget():Object;
		public function get currentTarget():Object
		{
			//trace( "Event.get currentTarget" );
			return _currenttarget;
		}

		//public native function get eventPhase():uint;
		public function get eventPhase():uint
		{
			//trace( "Event.get eventPhase" );
			return _currentphase;
		}

		/**
		 * A utility function for implementing the <code>toString()</code> method in custom ActionScript 3.0 Event classes.
		 * Overriding the <code>toString()</code> method is recommended, but not required.
		 *
		 * <pre>
		 * 		class PingEvent extends Event
		 * 		{
		 * 			var URL:String;
		 * 
		 * 			public override function toString():String
		 * 			{
		 * 				return formatToString( "PingEvent", "type", "bubbles", "cancelable", "eventPhase", "URL" );
		 * 			}
		 * 		}
		 * </pre>
		 * 
		 * @param  className The name of your custom Event class.
		 * In the previous example, the <code>className</code> parameter is <code>PingEvent</code>.
		 * @param  ...arguments The properties of the Event class and the properties that you add in your custom Event class.
		 * In the previous example, the <code>...arguments</code> parameter includes <code>type</code>,
		 * <code>bubbles</code>, <code>cancelable</code>, <code>eventPhase</code>, and <code>URL</code>.
		 * @return The name of your custom Event class and the String value of your <code>...arguments</code> parameter.
		 *
		 * @playerversion Flash 9
		 * @playerversion AIR 1.0
		 * @langversion 3.0
		 */
		public function formatToString( className:String, ...arguments ):String
		{
			//trace( "Event.formatToString()" );

            var name:String = "";
            var value:*;

            var s:String = "";
                s += "[" + className;

        	var i:uint;
        	while( i < arguments.length )
        	{
        		name  = arguments[ i ];
        		value = this[ name ];

        		if( value is String )
        		{
        			s += " " + name + "=\"" + value + "\"";
        		}
        		else
        		{
        			s += " " + name + "=" + value;
        		}
        		i++;
        	}

        	s += "]";
        	return s;
		}

		/**
		 * Duplicates an instance of an Event subclass.
		 *
		 * <p>
		 * Returns a new Event object that is a copy of the original instance of the Event object.
		 * You do not normally call <code>clone()</code>;
		 * the EventDispatcher class calls it automatically when you redispatch an event—that is,
		 * when you call <code>dispatchEvent(event)</code> from a handler that is handling event.
		 * </p>
		 *
		 * <p>
		 * The new Event object includes all the properties of the original.
		 * </p>
		 *
		 * <p>
		 * When creating your own custom Event class,
		 * you must override the inherited <code>Event.clone()</code> method
		 * in order for it to duplicate the properties of your custom class.
		 * If you do not set all the properties that you add in your event subclass,
		 * those properties will not have the correct values when listeners handle the redispatched event.
		 * </p>
		 *
		 * @example
		 * In this example, <code>PingEvent</code> is a subclass of <code>Event</code>
		 * and therefore implements its own version of <code>clone()</code>.
		 * 
		 * <listing>
		 * 		class PingEvent extends Event
		 * 		{
		 * 			var URL:String;
		 * 
		 * 			public override function clone():Event
		 * 			{
		 * 				return new PingEvent( type, bubbles, cancelable, URL);
		 * 			}
		 * 		}
		 * </listing>
		 * 
		 * @return  A new Event object that is identical to the original.
		 *
		 * @playerversion Flash 9
		 * @playerversion AIR 1.0
		 * @langversion 3.0
		 */
		public function clone():Event
		{
			//trace( "Event.clone()" );

			return new Event( type, bubbles, cancelable );
		}

		/**
		 * Checks whether the <code>preventDefault()</code> method has been called on the event.
		 * If the <code>preventDefault()</code> method has been called, returns <code>true</code>;
		 * otherwise, returns <code>false</code>.
		 * 
		 * @return If <code>preventDefault()</code> has been called, returns <code>true</code>;
		 * otherwise, returns <code>false</code>.
		 *
		 * @playerversion Flash 9
		 * @playerversion AIR 1.0
		 * @langversion 3.0
		 *
		 * @see Evetn#preventDefault() preventDefault()
		 */
		//public native function isDefaultPrevented():Boolean;
		public function isDefaultPrevented():Boolean
		{
			//trace( "Event.isDefaultPrevented()" );

			return _preventdefault;
		}

		/**
		 * Cancels an event's default behavior if that behavior can be canceled.
		 *
		 * <p>
		 * Many events have associated behaviors that are carried out by default.
		 * For example, if a user types a character into a text field,
		 * the default behavior is that the character is displayed in the text field.
		 * Because the <code>TextEvent.TEXT_INPUT</code> event's default behavior can be canceled,
		 * you can use the <code>preventDefault()</code> method to prevent the character from appearing.
		 * </p>
		 *
		 * <p>
		 * An example of a behavior that is not cancelable is the default behavior associated
		 * with the <code>Event.REMOVED </code>event,
		 * which is generated whenever Flash Player is about to remove a display object from the display list.
		 * The default behavior (removing the element) cannot be canceled,
		 * so the <code>preventDefault()</code> method has no effect on this default behavior.
		 * </p>
		 *
		 * <p>
		 * You can use the <code>Event.cancelable</code> property to check whether you can prevent
		 * the default behavior associated with a particular event.
		 * If the value of <code>Event.cancelable</code> is <code>true</code>,
		 * then <code>preventDefault()</code> can be used to cancel the event;
		 * otherwise, <code>preventDefault()</code> has no effect.
		 * </p>
		 *
		 * @playerversion Flash 9
		 * @playerversion AIR 1.0
		 * @langversion 3.0
		 *
		 * @see Event#isDefaultPrevented()
		 * @see Event#cancelable
		 */
		//public native function preventDefault():void;
		public function preventDefault():void
		{
			//trace( "Event.preventDefault()" );

			_preventdefault = true;
		}

		//public native function stopImmediatePropagation():void;
		public function stopImmediatePropagation():void
		{
			trace( "Event.stopImmediatePropagation()" );
		}

		//public native function stopPropagation():void;
		public function stopPropagation():void
		{
			trace( "Event.stopPropagation()" );
		}

		/**
		 * Returns a string containing all the properties of the Event object.
		 * The string is in the following format:
		 * <pre>
		 * [Event type=value bubbles=value cancelable=value]
		 * </pre>
		 * 
		 * @return A string containing all the properties of the Event object.
		 *
		 * @playerversion Flash 9
		 * @playerversion AIR 1.0
		 * @langversion 3.0
		 */
		public function toString():String
		{
			//trace( "Event.toString()" );

			return formatToString( "Event", "type", "bubbles", "cancelable", "eventPhase" );
		}
	}
}
