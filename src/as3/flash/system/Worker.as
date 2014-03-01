/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.system
{
	import flash.utils.ByteArray;
	
   /**
    * A user program-initiated, software-isolated, virtual player instance.
    *
    * There can be multiple ActionScript programs running in the same OS process.
    * In earlier versions, this only happened when a user opened several browser tabs
    * and a separate Flash script/application was to appear in each of these.
    *
    * Now ActionScript code can start new player instances programmatically, using this class. We call these "workers".
    *
    * The primordial ActionScript program that is running when the player starts up is also regarded as a worker.
    * It is called the "main" Worker.
    * The others are called "background" workers.
    *
    * The APIs available to background workers may be somewhat limited.
    * Furthermore physical screen access may not be available to background workers.
    * Off-screen rendering applies then instead.
    *
    * TODO: explain what happens in AVM shell? Do we document AVM shell in public APIs at all?
    */
    [native(cls="::avmshell::ShellWorkerClass", instance="::avmshell::ShellWorkerObject", methods="auto", construct="native")]
    public final class Worker
    {

        /**
        * @private
        */
        public function Worker() { }



        public native function get state():String;

        /**
        * Run the code blobs passed into the constructor in order and enter the event loop.
        * @return proxy to the remote worker.
        */
        public native function start() :void;

        public native function isParentOf(other: Worker): Boolean;
        public native function get isPrimordial(): Boolean;

        public native function setSharedProperty(key:String, value:*):void;
        public native function getSharedProperty(key:String):*;


        /**
        * Terminate this worker.
        *
        * If this is the main worker, then all other workers are terminated, too.
        * Currently blocks for termination, which should be prompt.
        *
        * @return true if the worker was running and interrupted, false if it had already terminated.
        */
        public native function terminate() :Boolean;

        /**
        * Obtain a reference to the worker in which this code is currently running.
        */
        public static function get current() :Worker
        {
            return m_current;
        }

        /**
        * Temporary - debugging only
        */
        public static native function pr(s :String) :void;

        private static var m_current :Worker;

        private var m_byteCode :ByteArray;
        
    }

}
