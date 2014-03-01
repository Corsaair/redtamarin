/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package shell.async
{
	/**
	 * Defines what the main event loop needs to implements.
	 * 
	 * @langversion 3.0
	 * @playerversion AVM 0.4
	 */
	public interface EventLoop
	{
		/**
		 * Indicates if the event loop is running
		 */
		function get running():Boolean;

		/** @private */
		function set running( value:Boolean ):void;

		/**
		 * The Event loop frequency.
		 *
		 * <p>
		 * Default is 60.
		 * </p>
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		function get frequency():uint;

		/** @private */
		function set frequency( value:uint ):void;

		/**
		 * Access the global Timers.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		function get timers():Array;

		/** @private */
		function set timers( value:Array ):void


		function get frame():uint;
		function get started():uint;
		function get elapsed():uint;

		/**
		 * Indicates if timers are pending or not.
		 * 
		 * @return <code>true</code> if timers are pending; otherwise return <code>false</code>.
		 *
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		function get timerPending():Boolean;

		function setCallback( f:Function ):void;

		/**
		 * Process timers.
		 *
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		function handleTimers():void;

		/**
		 * Starts the main event loop.
		 *
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		function start():void;

		/**
		 * Stops the main event loop.
		 *
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		function stop():void;
	}
}