/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.system
{

    // Mockup worker event for shell use.
    public final class WorkerEvent
    {

        public static const WORKER_STATE:String = "workerState";

        public function WorkerEvent(previousState:String, currentState:String)
        {
            m_previousState = previousState;
            m_currentState = currentState;
            
        }
        public function get currentState():String
        {
            return m_currentState;
        }

        public function get previousState():String
        {
            return m_previousState;
        }

        public function get target():Object
        {
            return m_target;
        }

        private var m_previousState:String;
        private var m_currentState:String;
        var m_target:Object;

    }

}
