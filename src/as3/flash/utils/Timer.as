/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.utils
{
	/* IMPORTANT:
	   this code is alpha quality
	   for proof of concept
	   use at your own risk
	*/

	import shell.Runtime;
	import shell.Program;

	import flash.events.*;

	/**
	 * @eventType flash.events.TimerEventType.TIMER
	 *
	 * @playerversion Flash 9
	 * @playerversion AIR 1.0
	 * @langversion 3.0
	 */
	[Event(name="timer", type="flash.events.TimerEvent")]

    /**
     * The Timer class is the interface to timers,
     * which let you run code on a specified time sequence.
     * Use the <code>start()</code> method to start a timer.
     * Add an event listener for the timer event to set up code to be run on the timer interval.
     *
     * <p>
     * You can create Timer objects to run once or repeat at specified intervals to execute code on a schedule.
     * Depending on the SWF file's framerate or the runtime environment (available memory and other factors),
     * the runtime may dispatch events at slightly offset intervals.
     * For example, if a SWF file is set to play at 10 frames per second (fps),
     * which is 100 millisecond intervals, but your timer is set to fire an event at 80 milliseconds,
     * the event will be dispatched close to the 100 millisecond interval.
     * Memory-intensive scripts may also offset the events.
     * </p>
     *
     * @example
     * The following example uses the class <code>TimerExample</code> to show
     * how a listener method <code>timerHandler()</code> can be set to listen for
     * a new TimerEvent to be dispatched.
     * The timer is started when <code>start()</code> is called, and after that point,
     * the timer events are dispatched.
     * 
     * <listing>
     * package
     * {
     * 		import flash.utils.Timer;
     * 		import flash.events.TimerEvent;
     * 		import flash.display.Sprite;
     *
     * 		public class TimerExample extends Sprite
     * 		{
     * 			public function TimerExample()
     * 			{
     * 				var myTimer:Timer = new Timer( 1000, 2 );
     * 				myTimer.addEventListener( "timer", timerHandler );
     * 				myTimer.start();
     * 			}
     *	
     * 			public function timerHandler( event:TimerEvent ):void
     * 			{
     * 				trace( "timerHandler: " + event );
     * 			}
     * 		}
     * }
     * </listing>
     * 
	 * @playerversion Flash 9
	 * @playerversion AIR 1.0
	 * @langversion 3.0
     *
     * @see http://help.adobe.com/en_US/as3/dev/WS5b3ccc516d4fbf351e63e3d118a9b90204-7f0a.html Performing date and time arithmetic
     * @see http://help.adobe.com/en_US/as3/dev/WS5b3ccc516d4fbf351e63e3d118a9b90204-7f09.html Converting between time zones
     * @see http://help.adobe.com/en_US/as3/dev/WS5b3ccc516d4fbf351e63e3d118a9b90204-7f0f.html Controlling time intervals
     * @see http://help.adobe.com/en_US/as3/dev/WS5b3ccc516d4fbf351e63e3d118a9b90204-7f0e.html Date and time example: Simple analog clock
     * @see http://help.adobe.com/en_US/as3/dev/WS5b3ccc516d4fbf351e63e3d118a9b90204-7e52.html Working with dates and times
     * @see http://help.adobe.com/en_US/as3/dev/WS5b3ccc516d4fbf351e63e3d118a9b90204-7f07.html The Timer class
     */
	public class Timer extends EventDispatcher
	{
		private var _delay:Number;
		private var _repeatCount:int;
		private var _iteration:int;

		private var _running:Boolean = false;
		private var _closure:Function;

		public var _started:uint;
		public var _elapsed:uint;

		/**
		 * Constructs a new Timer object with the specified <code>delay</code>
		 * and <code>repeatCount</code> states.
		 *
		 * <p>
		 * The timer does not start automatically; you must call the <code>start()</code> method to start it.
		 * </p>
		 *
		 * @example
		 * In the following example, the user is given 90 seconds to enter a response in an input text field.
		 * Also, every 30 seconds, a status message lets the user know how many seconds are left.
		 *
		 * <p>
		 * A Timer object is created that starts in 30 seconds (delay is set to 30000 milliseconds)
		 * and repeats three times, for a total of 90 seconds (The timer stops after the third time).
		 * </p>
		 *
		 * <p>
		 * Two event listeners are added for the <code>myTimer</code> timer.
		 * The first is triggered by the <code>TimerEvent.TIMER</code> event,
		 * which occurs every time the timer is started.
		 * The <code>timerHandler()</code> method changes the text for the <code>statusTextField</code>
		 * text field to reflect the seconds remaining.
		 * </p>
		 *
		 * <p>
		 * <b>Note: </b> The Timer class keeps track of the number of times it has to start (<code>repeats</code>)
		 * by increasing the number in the <code>currentCount</code> property.
		 * </p>
		 *
		 * <p>
		 * After the timer is called for the last time, the <code>TimerEvent.TIMER_COMPLETE</code> event
		 * is dispatched and the <code>completeHandler()</code> method is called.
		 * The <code>completeHandler()</code> method changes the type of the inputTextField text field
		 * from <code>INPUT</code> to <code>DYNAMIC</code>,
		 * which means the user can no longer enter or change text.
		 * </p>
		 * 
		 * <listing>
		 * package
		 * {
		 * 		//TODO
		 * }
		 * </listing>
		 * 
		 * @param delay The delay between timer events, in milliseconds.
		 * A delay lower than 20 milliseconds is not recommended.
		 * Timer frequency is limited to 60 frames per second, meaning a delay lower than 16.6 milliseconds
		 * causes runtime problems.
		 * @param repeatCount Specifies the number of repetitions.
		 * If zero, the timer repeats indefinitely, up to a maximum of 24.86 days (int.MAX_VALUE + 1).
		 * If nonzero, the timer runs the specified number of times and then stops.
		 *
		 * @throws Error if the delay specified is negative or not a finite number
		 *
		 * @playerversion Flash 9
		 * @playerversion AIR 1.0
		 * @langversion 3.0
		 */
		public function Timer( delay:Number, repeatCount:int = 0 )
		{
			trace( "Timer ctor" );

			if( (delay < 0) || !isFinite(delay) )
			{
				Error.throwError( RangeError, 2066 );
			}

			_delay       = delay;
			_repeatCount = repeatCount;

			use namespace AVM2;

			if( !shell.Runtime.loop )
			{
				trace( "Runtime.loop does not exists" );
				trace( "you need to call Runtime.goAsync() first" );
				throw new Error( "Runtime.loop does not exists" );
			}
			else
			{
				trace( "add myself to the global timers [" + this + "]" );
				shell.Runtime.loop.timers.push( this );	
			}
		}

		/**
		 * @private
		 * Private native helper function for event dispatch
		 */
		//private native function _timerDispatch():void;
		private function _timerDispatch():void
		{
			trace( "Timer._timerDispatch()" );

			dispatchEvent( new TimerEvent( TimerEvent.TIMER, false, false ) );
		}

		/**
		 * @private
		 * Private native helper function for start
		 */
		//private native function _start( delay:Number, callback:Function ):void;
		private function _start( delay:Number, callback:Function ):void
		{
			trace( "Timer._start()" );

			_delay   = delay;
			_running = true;
			_closure = callback;

			//_elapsed = Program.getTimer() - _started;
			_started = Program.getTimer();
		}

		/**
		 * @private
		 * This method is invoked when a timer event occurs.
		 * It dispatches an Event of type "timer".
		 */
		public function tick():void
		{
			trace( "Timer.tick()" );
			_iteration++;
			trace( "- _iteration = " + _iteration );
			_timerDispatch();
			trace( "- _repeatCount = " + _repeatCount );

			if( !(_repeatCount == 0) && (_iteration >= _repeatCount) )
			{
				stop();
				dispatchEvent( new TimerEvent( TimerEvent.TIMER_COMPLETE, false, false ) );
			}
		}

		/**
		 * The delay, in milliseconds, between timer events.
		 * If you set the delay interval while the timer is running,
		 * the timer will restart at the same <code>repeatCount</code> iteration.
		 *
		 * <p>
		 * <b>Note: </b> A <code>delay</code> lower than 20 milliseconds is not recommended.
		 * Timer frequency is limited to 60 frames per second, meaning a delay lower than 16.6 milliseconds
		 * causes runtime problems.
		 * </p>
		 *
		 * @throws Error Throws an exception if the delay specified is negative or not a finite number.
		 * 
		 * @playerversion Flash 9
		 * @playerversion AIR 1.0
		 * @langversion 3.0
		 */
		public function get delay():Number
		{
			return _delay;
		}

		/** @private */
		public function set delay( value:Number ):void
		{
			if( (value < 0) || !isFinite(value) )
			{
				Error.throwError( RangeError, 2066 );
			}

			_delay = value;

			if( running )
			{
				stop();
				start();
			}
		}

		/**
		 * The total number of times the timer is set to run.
		 * If the repeat count is set to 0, the timer continues indefinitely,
		 * up to a maximum of 24.86 days, or until the <code>stop()</code> method is invoked
		 * or the program stops.
		 * If the repeat count is nonzero, the timer runs the specified number of times.
		 * If <code>repeatCount</code> is set to a total that is the same or less
		 * then <code>currentCount</code> the timer stops and will not fire again.
		 * 
		 * @playerversion Flash 9
		 * @playerversion AIR 1.0
		 * @langversion 3.0
		 */
		public function get repeatCount():int
		{
			return _repeatCount;
		}

		/** @private */
		public function set repeatCount( value:int ):void
		{
			_repeatCount = value;

			if( running && !(_repeatCount == 0) && (_iteration >= _repeatCount) )
			{
				stop();
			}
		}

		/**
		 * The total number of times the timer has fired since it started at zero.
		 * If the timer has been reset, only the fires since the reset are counted.
		 * 
		 * @playerversion Flash 9
		 * @playerversion AIR 1.0
		 * @langversion 3.0
		 */
		public function get currentCount():int
		{
			return _iteration;
		}

		/**
		 * The timer's current state; <code>true</code> if the timer is running, otherwise <code>false</code>.
		 * 
		 * @playerversion Flash 9
		 * @playerversion AIR 1.0
		 * @langversion 3.0
		 */
		//public native function get running():Boolean;
		public function get running():Boolean
		{
			return _running;
		}


		/**
		 * Stops the timer, if it is running, and sets the <code>currentCount</code> property back to 0,
		 * like the reset button of a stopwatch.
		 * Then, when <code>start()</code> is called, the timer instance runs for the specified number
		 * of repetitions, as set by the <code>repeatCount</code> value.
		 *
		 * @playerversion Flash 9
		 * @playerversion AIR 1.0
		 * @langversion 3.0
		 *
		 * @see Timer#stop()
		 */
		public function reset():void
		{
			if( running )
			{
				stop();
			}

			_iteration = 0;
		}

		/**
		 * Starts the timer, if it is not already running.
		 *
		 * @playerversion Flash 9
		 * @playerversion AIR 1.0
		 * @langversion 3.0
		 */
		public function start():void
		{
			trace( "Timer.start()" );

			if( !running )
			{
				_iteration = 0;
				_start( _delay, tick );
			}
		}

		/**
		 * Stops the timer.
		 * When <code>start()</code> is called after <code>stop()</code>,
		 * the timer instance runs for the remaining number of repetitions,
		 * as set by the <code>repeatCount</code> property.
		 *
		 * @playerversion Flash 9
		 * @playerversion AIR 1.0
		 * @langversion 3.0
		 *
		 * @see Timer#reset()
		 */
		//public native function stop():void;
		public function stop():void
		{
			trace( "Timer.stop()" );

			_running = false;
		}

	}
}
