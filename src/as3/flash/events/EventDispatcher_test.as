/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.events
{

	public class EventDispatcher implements IEventDispatcher
	{
		public function EventDispatcher( target:IEventDispatcher = null )
		{
			trace( "EventDispatcher ctor" );
		}

		public function addEventListener( type:String, listener:Function, useCapture:Boolean = false, priority:int = 0, useWeakReference:Boolean = false ):void
		{

		}

		public function dispatchEvent( event:Event ):Boolean
		{
			return false;
		}

		public function hasEventListener( type:String ):Boolean
		{
			return false;
		}

		public function removeEventListener( type:String, listener:Function, useCapture:Boolean = false ):void
		{

		}

		public function willTrigger( type:String ):Boolean
		{
			return false;
		}
	}

}
