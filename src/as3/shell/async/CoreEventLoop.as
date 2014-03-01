/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package shell.async
{
	//import C.unistd.sleep;
	import shell.Program;
	import flash.utils.Timer;

	/**
	 * Defines the globsl <code>IEventLoop</code>.
	 *
	 * <p>
	 * TODO
	 * </p>
	 *
	 * @langversion 3.0
	 * @playerversion AVM 0.4
	 */
	public class CoreEventLoop implements EventLoop
	{
		private var _running:Boolean;
		private var _frequency:uint;
		private var _timers:Array;

		private var _started:uint;
		private var _elapsed:uint;

		private var _frame:uint;

		private var _callback:Function;

		public function CoreEventLoop( frequency:uint = 60 ):void
		{
			//trace( "CoreEventLoop ctor" );
			_running   = false;
			_frequency = frequency;
			_timers    = new Array();
		}

		public function get running():Boolean { return _running; }
		public function set running( value:Boolean ):void { _running = value; }

		public function get frequency():uint { return _frequency; }
		public function set frequency( value:uint ):void { _frequency = value; }

		public function get timers():Array { return _timers; }
		public function set timers( value:Array ):void { _timers = value; }

		public function get frame():uint { return _frame; }
		public function get started():uint { return _started; }
		public function get elapsed():uint { return _elapsed; }

		private function tick():void
		{
			/* note:
			   freq = 60 (frame per second)
			   frame = 1000 / 60 = 16.666ms
			
			*/
			if( _callback )
			{
				_callback( this );
			}
		}

		public function setCallback( f:Function ):void
		{
			_callback = f;
		}

		private function _loop():void
		{
			trace( "CoreEventLoop._loop()" );

			while( _running )
			{
				_elapsed = Program.getTimer() - _started;

				if( timerPending )
				{
					handleTimers();
				}

				Program.sleep( 1000 / _frequency );
				_frame++;
				//trace( "." );
				tick();
			}

		}

		public function get timerPending():Boolean
		{
			if( timers.length > 0 )
			{
				//trace( "CoreEventLoop.timerPending = true" );
				var i:uint;
				var timer:Timer;
				for( i = 0; i < timers.length; i++ )
				{
					timer = timers[ i ];
					if( timer.running )
					{
						//trace( "found timer running" );
						return true;
					}
				}
				return false;
			}
			else
			{
				//trace( "CoreEventLoop.timerPending = false" );
				return false;
			}
		}

		public function handleTimers():void
		{
			//trace( "CoreEventLoop.handleTimers()" );

			var i:uint;
			var timer:Timer;

			for( i = 0; i < timers.length; i++ )
			{
				//trace( "  handling timer #" + i );
				timer = timers[ i ];
				if( timer.running )
				{
					timer._elapsed = Program.getTimer() - timer._started;
					/*
					trace( "timer is running" );
					trace( "timer.delay = " + timer.delay );
					trace( "timer.currentCount = " + timer.currentCount );
					trace( "timer.repeatCount = " + timer.repeatCount );
					trace( " timer started: " + timer._started );
					trace( " timer elapsed: " + timer._elapsed );
					trace( "-" );
					trace( "(timer.delay * timer.currentCount+1) = " + (timer.delay * (timer.currentCount+1)) );
					trace( "" );
					*/


					if( timer._elapsed >= (timer.delay * (timer.currentCount+1)) )
					{
						trace( "tick() @ " + timer._elapsed );
						timer.tick();	
					}
				}
			}
		}

		public function start():void
		{
			trace( "CoreEventLoop.start()" );

			_running = true;
			_started = Program.getTimer();
			_elapsed = 0;
			_loop();
		}

		public function stop():void
		{
			trace( "CoreEventLoop.stop()" );

			_running = false;
		}
	}
}
