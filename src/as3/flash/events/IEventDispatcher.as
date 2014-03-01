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
	 * The IEventDispatcher interface defines methods for adding or removing event listeners,
	 * checks whether specific types of event listeners are registered, and dispatches events.
	 *
	 * <p>
	 * Event targets are an important part of the Flash&#xAE; Player and Adobe&#xAE; AIR&#xAE; event model.
	 * The event target serves as the focal point for how events flow through the display list hierarchy.
	 * When an event such as a mouse click or a keypress occurs,
	 * an event object is dispatched into the event flow from the root of the display list.
	 * The event object makes a round-trip journey to the event target,
	 * which is conceptually divided into three phases:
	 * the capture phase includes the journey from the root to the last node before the event target's node;
	 * the target phase includes only the event target node;
	 * and the bubbling phase includes any subsequent nodes encountered on the return trip to the root
	 * of the display list.
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
	 * The following example uses the IEventDispatcherExample and DecoratedDispatcher sample classes
	 * to show how the IEventDispatcher class can be implemented and used.
	 * The example accomplishes this by implementing each method of DecoratedDispatcher in the same manner
	 * as in EventDispatcher.
	 * Within the constructor for IEventDispatcherExample, a new instance (named <code>decorDispatcher</code>)
	 * of the DecoratedDispatcher class is constructed and the decorDispatcher variable is used to call
	 * <code>addEventListener()</code> with the custom event <code>doSomething</code>,
	 * which is then handled by <code>didSomething()</code>, which prints a line of text using <code>trace()</code>.
	 * 
	 * <listing>
	 * package
	 * {
	 * 		import flash.events.Event;
	 * 		import flash.display.Sprite;
	 *
	 * 		public class IEventDispatcherExample extends Sprite
	 * 		{
	 * 			public function IEventDispatcherExample()
	 * 			{
	 * 				var decorDispatcher:DecoratedDispatcher = new DecoratedDispatcher();
	 * 				decorDispatcher.addEventListener( "doSomething", didSomething );
	 * 				decorDispatcher.dispatchEvent( new Event("doSomething") );
	 * 			}
	 * 
	 * 			public function didSomething( evt:Event ):void
	 * 			{
	 * 				trace( ">> didSomething" );
	 * 			}
	 * 		}
	 * }
	 * 
	 * 		import flash.events.IEventDispatcher;
	 * 		import flash.events.EventDispatcher;
	 * 		import flash.events.Event;
	 * 
	 * 		class DecoratedDispatcher implements IEventDispatcher
	 * 		{
	 * 			private var dispatcher:EventDispatcher;
	 * 
	 * 			public function DecoratedDispatcher()
	 * 			{
	 * 				dispatcher = new EventDispatcher( this );
	 * 			}
	 * 
	 * 			public function addEventListener( type:String, listener:Function,
	 * 											  useCapture:Boolean = false, priority:int = 0, useWeakReference:Boolean = false ):void
	 * 			{
	 * 				dispatcher.addEventListener( type, listener, useCapture, priority );
	 * 			}
	 * 
	 * 			public function dispatchEvent( evt:Event ):Boolean
	 * 			{
	 * 				return dispatcher.dispatchEvent( evt );
	 * 			}
	 * 
	 * 			public function hasEventListener( type:String ):Boolean
	 * 			{
	 * 				return dispatcher.hasEventListener( type );
	 * 			}
	 * 
	 * 			public function removeEventListener( type:String, listener:Function,
	 * 												 useCapture:Boolean = false ):void
	 * 			{
	 * 				dispatcher.removeEventListener( type, listener, useCapture );
	 * 			}
	 * 
	 * 			public function willTrigger( type:String ):Boolean
	 * 			{
	 * 				return dispatcher.willTrigger( type );
	 * 			}
	 * 		}
	 * </listing>
	 * 
	 * @playerversion Flash 9
	 * @playerversion AIR 1.0
	 * @langversion 3.0
	 *
	 * @see http://help.adobe.com/en_US/Flex/4.6/UsingSDK/WS2db454920e96a9e51e63e3d11c0bf64a29-7fe5.html About the EventDispatcher class
	 */
	public interface IEventDispatcher
	{
		/**
		 * Registers an event listener object with an EventDispatcher object so that the listener
		 * receives notification of an event.
		 * You can register event listeners on all nodes in the display list for a specific type
		 * of event, phase, and priority.
		 *
		 * <p>
		 * After you successfully register an event listener, you cannot change its priority through
		 * additional calls to <code>addEventListener()</code>.
		 * To change a listener's priority, you must first call <code>removeEventListener()</code>.
		 * Then you can register the listener again with the new priority level.
		 * </p>
		 *
		 * <p>
		 * After the listener is registered, subsequent calls to <code>addEventListener()</code>
		 * with a different value for either <code>type</code> or <code>useCapture</code>
		 * result in the creation of a separate listener registration.
		 * For example, if you first register a listener with <code>useCapture</code> set to <code>true</code>,
		 * it listens only during the capture phase.
		 * If you call <code>addEventListener()</code> again using the same listener object,
		 * but with <code>useCapture</code> set to <code>false</code>,
		 * you have two separate listeners:
		 * one that listens during the capture phase,
		 * and another that listens during the target and bubbling phases.
		 * </p>
		 *
		 * <p>
		 * You cannot register an event listener for only the target phase or the bubbling phase.
		 * Those phases are coupled during registration because bubbling applies only to the ancestors
		 * of the target node.
		 * </p>
		 *
		 * <p>
		 * When you no longer need an event listener, remove it by calling <code>EventDispatcher.removeEventListener()</code>;
		 * otherwise, memory problems might result.
		 * Objects with registered event listeners are not automatically removed from memory
		 * because the garbage collector does not remove objects that still have references.
		 * </p>
		 *
		 * <p>
		 * Copying an EventDispatcher instance does not copy the event listeners attached to it.
		 * (If your newly created node needs an event listener, you must attach the listener after creating the node.)
		 * However, if you move an EventDispatcher instance, the event listeners attached to it
		 * move along with it.
		 * </p>
		 *
		 * <p>
		 * If the event listener is being registered on a node while an event is also being processed
		 * on this node, the event listener is not triggered during the current phase but may be
		 * triggered during a later phase in the event flow, such as the bubbling phase.
		 * </p>
		 *
		 * <p>
		 * If an event listener is removed from a node while an event is being processed on the node,
		 * it is still triggered by the current actions.
		 * After it is removed, the event listener is never invoked again
		 * (unless it is registered again for future processing).
		 * </p>
		 * 
		 * @param type The type of event.
		 * @param listener The listener function that processes the event.
		 * This function must accept an event object as its only parameter and must return nothing,
		 * as this example shows:
		 * <pre>
		 * function(evt:Event):void
		 * </pre>
		 * @param useCapture Determines whether the listener works in the capture phase
		 * or the target and bubbling phases.
		 * If <code>useCapture</code> is set to <code>true</code>,
		 * the listener processes the event only during the capture phase and not in the target or bubbling phase.
		 * If <code>useCapture</code> is <code>false</code>, the listener processes the event only during the target
		 * or bubbling phase.
		 * To listen for the event in all three phases, call <code>addEventListener()</code> twice,
		 * once with <code>useCapture</code> set to <code>true</code>,
		 * then again with <code>useCapture</code> set to <code>false</code>.
		 * @param priority The priority level of the event listener.
		 * Priorities are designated by a 32-bit integer.
		 * The higher the number, the higher the priority.
		 * All listeners with priority n are processed before listeners of priority n-1.
		 * If two or more listeners share the same priority,
		 * they are processed in the order in which they were added.
		 * The default priority is 0.
		 * @param useWeakReference Determines whether the reference to the listener is strong or weak.
		 * A strong reference (the default) prevents your listener from being garbage-collected.
		 * A weak reference does not.
		 * 
		 * Class-level member functions are not subject to garbage collection, so you can set
		 * <code>useWeakReference</code> to <code>true</code> for class-level member functions without
		 * subjecting them to garbage collection.
		 * If you set <code>useWeakReference</code> to <code>true</code> for a listener that is
		 * a nested inner function, the function will be garbge-collected and no longer persistent.
		 * If you create references to the inner function (save it in another variable)
		 * then it is not garbage-collected and stays persistent.
		 * 
		 * @playerversion Flash 9
		 * @playerversion AIR 1.0
		 * @langversion 3.0
		 */
		function addEventListener( type:String, listener:Function, useCapture:Boolean = false, priority:int = 0, useWeakReference:Boolean = false ):void;

		/**
		 * Dispatches an event into the event flow.
		 * The event target is the EventDispatcher object upon which <code>dispatchEvent()</code> is called.
		 * 
		 * @param event The event object dispatched into the event flow.
		 * @return A value of <code>true</code> unless <code>preventDefault()</code> is called on the event,
		 * in which case it returns <code>false</code>.
		 *
		 * @playerversion Flash 9
		 * @playerversion AIR 1.0
		 * @langversion 3.0
		 */
		function dispatchEvent( event:Event ):Boolean;

		/**
		 * Checks whether the EventDispatcher object has any listeners registered for a specific type of event.
		 * This allows you to determine where an EventDispatcher object has altered handling of an event type
		 * in the event flow hierarchy.
		 * To determine whether a specific event type will actually trigger an event listener,
		 * use <code>IEventDispatcher.willTrigger()</code>.
		 * 
		 * @param  type The type of event.
		 * @return A value of <code>true</code> if a listener of the specified type is registered;
		 * <code>false</code> otherwise.
		 *
		 * @playerversion Flash 9
		 * @playerversion AIR 1.0
		 * @langversion 3.0
		 *
		 * @see IEventDispatcher#willTrigger() willTrigger()
		 */
		function hasEventListener( type:String ):Boolean;

		/**
		 * Removes a listener from the EventDispatcher object.
		 * If there is no matching listener registered with the EventDispatcher object,
		 * a call to this method has no effect.
		 * 
		 * @param  type The type of event.
		 * @param  listener The listener object to remove.
		 * @param  useCapture Specifies whether the listener was registered for the capture phase
		 * or the target and bubbling phases.
		 * If the listener was registered for both the capture phase and the target and bubbling phases,
		 * two calls to <code>removeEventListener()</code> are required to remove both:
		 * one call with <code>useCapture</code> set to <code>true</code>,
		 * and another call with <code>useCapture</code> set to <code>false</code>.
		 * 
		 * @playerversion Flash 9
		 * @playerversion AIR 1.0
		 * @langversion 3.0
		 */
		function removeEventListener( type:String, listener:Function, useCapture:Boolean = false ):void;

		/**
		 * Checks whether an event listener is registered with this EventDispatcher object
		 * or any of its ancestors for the specified event type.
		 * This method returns <code>true</code> if an event listener is triggered during
		 * any phase of the event flow when an event of the specified type is dispatched
		 * to this EventDispatcher object or any of its descendants.
		 *
		 * <p>
		 * The difference between <code>hasEventListener()</code> and <code>willTrigger()</code>
		 * is that <code>hasEventListener()</code> examines only the object to which it belongs,
		 * whereas <code>willTrigger()</code> examines the entire event flow for the event specified by
		 * the <code>type</code> parameter.
		 * </p>
		 * 
		 * @param  type The type of event.
		 * @return A value of <code>true</code> if a listener of the specified type will be triggered;
		 * <code>false</code> otherwise.
		 *
		 * @playerversion Flash 9
		 * @playerversion AIR 1.0
		 * @langversion 3.0
		 */
		function willTrigger( type:String ):Boolean;

	}
}