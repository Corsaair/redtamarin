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
	
	import flash.net.URLRequestHeader;

	/**
	 * The EventDispatcher class is the base class for all classes that dispatch events.
	 * The EventDispatcher class implements the IEventDispatcher interface and is the base class
	 * for the DisplayObject class.
	 * The EventDispatcher class allows any object on the display list to be an event target and as such,
	 * to use the methods of the IEventDispatcher interface.
	 *
	 * <p>
	 * Event targets are an important part of the Flash&#xAE; Player and Adobe&#xAE; AIR&#xAE; event model.
	 * The event target serves as the focal point for how events flow through the display list hierarchy.
	 * When an event such as a mouse click or a keypress occurs,
	 * Flash Player or the AIR application dispatches an event object into the event flow from
	 * the root of the display list. 
	 * The event object then makes its way through the display list until it reaches the event target,
	 * at which point it begins its return trip through the display list.
	 * This round-trip journey to the event target is conceptually divided into three phases:
	 * the capture phase comprises the journey from the root to the last node before the event target's node,
	 * the target phase comprises only the event target node,
	 * and the bubbling phase comprises any subsequent nodes encountered on the return trip
	 * to the root of the display list.
	 * </p>
	 *
	 * <p>
	 * In general, the easiest way for a user-defined class to gain event dispatching capabilities is
	 * to extend EventDispatcher.
	 * If this is impossible (that is, if the class is already extending another class),
	 * you can instead implement the IEventDispatcher interface, create an EventDispatcher member,
	 * and write simple hooks to route calls into the aggregated EventDispatcher.
	 * </p>
	 *
	 * @example
	 * The following example uses the classes <code>EventDispatcherExample</code>
	 * and <code>CustomDispatcher</code>, a subclass of <code>EventDispatcher</code>,
	 * to show how a custom event is created and dispatched.
	 * The example carries out the following tasks:
	 * <ol>
	 *		<li>The constructor of <code>EventDispatcherExample</code> creates a local variable <code>dispatcher</code> and assigns it to a new CustomDispatcher instance.</li>
	 *		<li>Inside <code>CustomDispatcher</code>, a string is set so that the event has the name <code>action</code>, and the <code>doAction()</code> method is declared. When called, this method creates the <code>action</code> event and dispatches it using <code>EventDispatcher.dispatchEvent()</code>.</li>
	 *		<li>The <code>dispatcher</code> property is then used to add the <code>action</code> event listener and associated subscriber method <code>actionHandler()</code>, which simply prints information about the event when it is dispatched.</li>
	 *		<li>The <code>doAction()</code> method is invoked, dispatching the <code>action</code> event.</li>
	 * </ol>
	 * 
	 * <listing>
	 * package
	 * {
	 * 		import flash.display.Sprite;
	 * 		import flash.events.Event;
	 * 
	 * 		public class EventDispatcherExample extends Sprite
	 * 		{
	 * 			public function EventDispatcherExample()
	 * 			{
	 * 				var dispatcher:CustomDispatcher = new CustomDispatcher();
	 * 				dispatcher.addEventListener( CustomDispatcher.ACTION, actionHandler );
	 * 				dispatcher.doAction();
	 * 			}
	 * 
	 * 			private function actionHandler( event:Event ):void
	 * 			{
	 * 				trace( "actionHandler: " + event );
	 * 			}
	 * 		}
	 * }
	 *
	 * 		import flash.events.EventDispatcher;
	 * 		import flash.events.Event;
	 * 
	 * 		class CustomDispatcher extends EventDispatcher
	 * 		{
	 * 			public static var ACTION:String = "action";
	 * 
	 * 			public function doAction():void
	 * 			{
	 * 				dispatchEvent( new Event( CustomDispatcher.ACTION ) );
	 * 			}
	 * 		}
	 * </listing>
	 * 
	 * @playerversion Flash 9
	 * @playerversion AIR 1.0
	 * @langversion 3.0
	 *
	 * @see http://help.adobe.com/en_US/Flex/4.6/UsingSDK/WS2db454920e96a9e51e63e3d11c0bf69084-7ce1.html Manually dispatching events
	 * @see http://help.adobe.com/en_US/Flex/4.6/UsingSDK/WS2db454920e96a9e51e63e3d11c0bf69084-7ce0.html Using event subclasses
	 * @see http://help.adobe.com/en_US/Flex/4.6/UsingSDK/WS2db454920e96a9e51e63e3d11c0bf64a29-7fe5.html About the EventDispatcher class
	 * @see http://help.adobe.com/en_US/Flex/4.6/UsingSDK/WS2db454920e96a9e51e63e3d11c0bf69084-7cdb.html Event propagation
	 * @see http://help.adobe.com/en_US/Flex/4.6/UsingSDK/WS2db454920e96a9e51e63e3d11c0bf69084-7cda.html Event priorities
	 * @see http://help.adobe.com/en_US/Flex/4.6/UsingSDK/WS2db454920e96a9e51e63e3d11c0bf64a29-7fdb.html About keyboard events
	 * @see http://help.adobe.com/en_US/as3/dev/WS5b3ccc516d4fbf351e63e3d118a9b90204-7dfb.html Handling events for display objects
	 */
	public class EventDispatcher implements IEventDispatcher
	{

        public static var _objectlist:Array = new Array();
        public static var _objectmap:Array  = new Array();

		private static function trimHeaderValue( headerValue:String ):String
		{
            var currChar:String            = "";
            var indexOfFirstValueChar:uint = 0;
            var headerValueLen:uint        = headerValue.length;
            var done:Boolean               = false;

            while( (indexOfFirstValueChar < headerValueLen) && !done )
            {
            	currChar = headerValue.charAt( indexOfFirstValueChar );
            	done = ( !(currChar == " ") && !(currChar == "\t") );

            	if( !done )
            	{
            		indexOfFirstValueChar++;
            	}
            }

            var indexOfLastValueChar:uint = headerValueLen;
            done = false;

            while( (indexOfLastValueChar > indexOfFirstValueChar) && !done )
            {
            	currChar = headerValue.charAt( indexOfLastValueChar - 1 );
            	done = ( !(currChar == " ") && !(currChar == "\t") );

				if( !done )
				{
					indexOfLastValueChar--;
				}
            }

            return headerValue.substring( indexOfFirstValueChar, indexOfLastValueChar );
		}



        private var _target:IEventDispatcher;
        public var _listeners:Array;
        public var _listenersNames:Array;
        public var _listenersCalls:Array;

		/**
		 * Aggregates an instance of the EventDispatcher class.
		 *
		 * <p>
		 * The EventDispatcher class is generally used as a base class,
		 * which means that most developers do not need to use this constructor function.
		 * However, advanced developers who are implementing the IEventDispatcher interface
		 * need to use this constructor.
		 * If you are unable to extend the EventDispatcher class and must instead implement
		 * the IEventDispatcher interface, use this constructor to aggregate an instance of
		 * the EventDispatcher class.
		 * </p>
		 * 
		 * @param target The target object for events dispatched to the EventDispatcher object.
		 * This parameter is used when the EventDispatcher instance is aggregated by a class
		 * that implements IEventDispatcher;
		 * it is necessary so that the containing object can be the target for events.
		 * Do not use this parameter in simple cases in which a class extends EventDispatcher.
		 *
		 * @playerversion Flash 9
		 * @playerversion AIR 1.0
		 * @langversion 3.0
		 */
		public function EventDispatcher( target:IEventDispatcher = null )
		{
			trace( "EventDispatcher ctor" );

			super();
			ctor( target );
		}

		//private native function ctor( target:IEventDispatcher ):void;
		private function ctor( target:IEventDispatcher ):void
		{
			trace( "EventDispatcher.ctor()" );
			_listeners      = new Array();
			_listenersNames = new Array();
			_listenersCalls = new Array();
			_target         = target;
		}

		//private native function dispatchEventFunction( event:Event ):Boolean;
		private function dispatchEventFunction( event:Event ):Boolean
		{
			trace( "EventDispatcher.dispatchEventFunction()" );
			trace( "Event = " + event );
			trace( "type = " + event.type );
			
			var arr:* = _listeners[ event.type ];
			trace( "arr = " + arr + " (" + arr.length + ")" );

			try
			{
                var currentCall = this._listenersCalls;
                var currentType = event.type;
                var nextCall = (currentCall[currentType] + 1);
                currentCall[currentType] = nextCall;
			}
			catch( e:Error )
			{
				//do nothing
				trace( "ERROR 1111" );
			}

			if( arr == null )
			{
				//do nothing
				trace( "ERROR: arr == null" );
			}
			else
			{
				var arr2:Array = new Array();
				var i:uint = 0;

				while( i < arr.length )
				{
					arr2[i] = arr[ i ];
					i++;
				}

				i=0;
				var fnc:* = undefined;
				while( i < arr2.length )
				{

					if( (arr2[i] == null) || (event == null) )
					{
						if( arr2[i] == null )
						{
							trace( "ERROR: dispatching event " + event.type + " function is null" );
						}

						if( event == null )
						{
							trace( "ERROR: event is null" );
						}

					}
					else
					{
						fnc = arr2[i];
						trace( this + " dispatching event " + event.type + " #" + i + " to " + fnc );

						try
						{
							fnc( event );
						}
						catch( e:Error )
						{
							trace( "ERROR: dispatching event " + e.getStackTrace() );
						}

						trace( this + " finished dispatching event " + event.type + " #" + i + " to " + fnc );
					}

					i++;
				}
			}
		}

		private function dispatchHttpStatusEvent( status:uint, redirected:Boolean, responseLocation:String, headers:String ):void
		{
            //var httpStatusEvent:*  = null;
            //var status:*           = status;
            //var redirected:*       = redirected;
            //var responseLocation:* = responseLocation;
            //var headers:*          = headers;

            var httpStatusEvent = new HTTPStatusEvent( HTTPStatusEvent.HTTP_RESPONSE_STATUS, false, false, status, redirected );
            	httpStatusEvent.responseURL = responseLocation;

            var headerArray:Array = headers.split( "\r\n" );

        	var parseResponseHeader:Function = function( element:*, index:int, arr:Array ):void
        	{
                var name:String;
                var value:String;
                var colonIdx:int = element.indexOf( ":", 0 );

                if( colonIdx != -1 )
                {
                	name  = element.slice( 0, colonIdx );
                	value = trimHeaderValue( element.slice( colonIdx + 1 ) );
                	httpStatusEvent.responseHeaders.push( new URLRequestHeader( name, value ) );
                }
        	}

            try
            {
            	headerArray.forEach( parseResponseHeader );
            	dispatchEvent( httpStatusEvent );
            }
            catch( e:Error )
            {
            	//do nothing
            	trace( "ERROR: in dispatchHttpStatusEvent() = " + e );
            }
		}


		/** @inheritDoc */
		//public native function addEventListener( type:String, listener:Function, useCapture:Boolean = false, priority:int = 0, useWeakReference:Boolean = false ):void;
		public function addEventListener( type:String, listener:Function, useCapture:Boolean = false, priority:int = 0, useWeakReference:Boolean = false ):void
		{
			trace( "EventDispatcher.addEventListener()" );

			if( _listeners[ type ] == undefined )
			{
				_listeners[ type ] = new Array();
			}

			_listeners[ type ].push( listener );

			var obj:*   = this;
			var fnd:int = -1;
			var i:uint  =  0;

			while( i < _listenersNames.length )
			{
				if( type == _listenersNames[i] )
				{
					fnd = i;
					break;
				}
				i++;
			}

			if( fnd == -1 )
			{
				_listenersNames.push( type );
				_listenersCalls[ type ] = 0;
			}

			if( obj == null )
			{
				obj = this;
			}

			fnd = -1;
			i   =  0;

			while( i < _objectlist.length )
			{
				if( _objectmap[i] == obj )
				{
					fnd = i;
					break;
				}
				i++;
			}

			if( fnd == -1 )
			{
				_objectlist.push( String(obj) );
				_objectmap.push( obj );
			}
		}

		/** @inheritDoc */
		public function dispatchEvent( event:Event ):Boolean
		{
			trace( "EventDispatcher.dispatchEvent()" );

			if( event.target )
			{
				return dispatchEventFunction( event.clone() );
			}

			return dispatchEventFunction( event );
		}

		/** @inheritDoc */
		//public native function hasEventListener( type:String ):Boolean;
		public function hasEventListener( type:String ):Boolean
		{
			trace( "EventDispatcher.hasEventListener()" );

			return !(_listenersCalls[type] == null);
		}

		/** @inheritDoc */
		//public native function removeEventListener( type:String, listener:Function, useCapture:Boolean = false ):void;
		public function removeEventListener( type:String, listener:Function, useCapture:Boolean = false ):void
		{
			trace( "EventDispatcher.removeEventListener()" );

			var obj:* = this;
			var i:uint;
			var j:uint;

			try
			{

                if( _listeners[ type ] != null )
                {
                    i = 0;
                    while( i < _listeners[type].length )
                    {
                        if( _listeners[type][i] == listener )
                        {
                            _listeners[type].splice(i, 1);
                            if( _listeners[type].length == 0 )
                            {
                                j = 0;
                                while( j < _listenersNames.length )
                                {
                                    if( _listenersNames[j] == type )
                                    {
                                        _listenersNames.splice(j, 1);
                                        _listenersCalls[type] = -1;
                                        break;
                                    }
                                    j++;
                                }
                            }
                            break;
                        }
                        i++;
                    }
                }

			}
			catch( e:Error )
			{
				trace( "exception: " + e );
				trace( e.getStackTrace() );
			}

		}

		/** @inheritDoc */
		//public native function willTrigger( type:String ):Boolean;
		public function willTrigger( type:String ):Boolean
		{
			trace( "EventDispatcher.willTrigger()" );
			return true;
		}

		/** @inheritDoc */
		public function toString():String
		{
			return Object.prototype.toString.call( this );
			//return "";
		}
	}

}
