/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.system
{

    /**
     * This class represents an enumeration of the possible worker states. 
     */
    [API(AVMGLUE::SWF_17)]
    public final class WorkerState
    {
        /**
        * These value represents a worker state returned value for Worker.state
        * and used by WorkerEvent.
        *
        * An object that represents the new worker has been created, 
        * but the worker is dormant; no code is executing on its behalf.
        */
        public static const NEW:String = "new";
                
        /**
        * The worker has begun executing application code
        * and it has not been directed to terminate in any way yet.
        */
        public static const RUNNING:String = "running";
                
        /**
        * The worker has been stopped programatically by some other worker 
        * that invoked the Worker.terminate() method on it.
        */
        public static const TERMINATED:String = "terminated";
        
        /**
        * The worker could not start due to lack of resources 
        * or due to some other error condition. 
        */
        public static const FAILED:String = "failed";
        
        /**
        * An active worker has been terminated involuntarily 
        * by the runtime system due to some error situation 
        * without ending in EXCEPTION and without stopping normally.
        * For instance, a debugger may be able to abort workers.
        */
        public static const ABORTED:String = "aborted";
        
        /**
        * The worker has terminated by not catching an exception.
        */
        public static const EXCEPTION:String = "exception";


        public static function code(s:String): int
        {
            if (s == NEW) return 1;
            else if (s == RUNNING) return 2;
            else if (s == TERMINATED) return 3;
            else if (s == FAILED) return 4;
            else if (s == ABORTED) return 5;
            else if (s == EXCEPTION) return 6;
            else throw Error("not an enum value: " + s);
        }

    }
    
}
