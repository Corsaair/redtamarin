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
	public class TimerEvent extends Event
	{
		public static const TIMER:String = "timer";
		public static const TIMER_COMPLETE:String = "timerComplete";

		public function TimerEvent( type:String, bubbles:Boolean = false, cancelable:Boolean = false )
		{
			super( type, bubbles, cancelable );
		}

		override public function clone():Event
		{
			return new TimerEvent( type, bubbles, cancelable );
		}

		override public function toString():String
		{
			return formatToString( "TimerEvent", "type", "bubbles", "cancelable", "eventPhase" );
		}

		//public native function updateAfterEvent():void;
		public function updateAfterEvent():void
		{
			trace( "TimerEvent.updateAfterEvent()" );
		}
	}
}
