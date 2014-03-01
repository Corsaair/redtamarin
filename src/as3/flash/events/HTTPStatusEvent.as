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
	 * TODO
	 *
	 * @playerversion Flash 9
	 * @playerversion AIR 1.0
	 * @langversion 3.0
	 */
	public class HTTPStatusEvent extends Event
	{
		public static const HTTP_STATUS:String = "httpStatus";
		public static const HTTP_RESPONSE_STATUS:String = "httpResponseStatus";

        private var _status:int;
        private var _responseHeaders:Array;
        private var _responseUrl:String;
        private var _redirected:Boolean;

		public function HTTPStatusEvent( type:String, bubbles:Boolean = false, cancelable:Boolean = false,
			                             status:int = 0, redirected:Boolean = false )
		{
			super( type, bubbles, cancelable );

			_status          = status;
			_redirected      = redirected;
			_responseHeaders = [];
		}

		public function get status():int { return _status; }

		public function get responseURL():String { return _responseUrl; }
		public function set responseURL( value:String ):void { _responseUrl = value; }

		public function get responseHeaders():Array { return _responseHeaders; }
		public function set responseHeaders(value:Array):void { _responseHeaders = value; }

		public function get redirected():Boolean { return _redirected; }
		public function set redirected( value:Boolean ):void { _redirected = value; }

		override public function clone():Event
		{
			var result:HTTPStatusEvent = new HTTPStatusEvent( type, bubbles, cancelable, status, redirected );
				result.responseURL     = responseURL;
				result.responseHeaders = responseHeaders;

			return result;
		}

		override public function toString():String
		{
			return formatToString( "HTTPStatusEvent", "type", "bubbles", "cancelable", "eventPhase",
								   "status", "redirected", "responseURL" );
		}

	}
}
