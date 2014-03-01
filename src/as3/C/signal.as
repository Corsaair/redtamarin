/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package C.signal
{

    /** @internal */
    [native(cls="::avmshell::CSignalClass", methods="auto", construct="none")]
    [Inspectable(environment="none")]
    internal class __signal
    {
        public native static function get SIGEV_NONE():int;
        public native static function get SIGEV_SIGNAL():int;
        public native static function get SIGEV_THREAD():int;
    }


    /**
     * No asynchronous notification is delivered when the event of interest occurs.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const SIGEV_NONE:int = __signal.SIGEV_NONE;

    /**
     * A queued signal, with an application-defined value, is generated when the event of interest occurs.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const SIGEV_SIGNAL:int = __signal.SIGEV_SIGNAL;

    /**
     * A notification function is called to perform notification.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const SIGEV_THREAD:int = __signal.SIGEV_THREAD;

    
    /**
     * Send a signal to a process or a group of processes.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CSignalClass::kill")]
    public native function kill( pid:int, sig:int ):int;

    /**
     * 
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native(cls="::avmshell::CsigvalClass", instance="::avmshell::CsigvalObject", methods="auto")]
    public class sigval
    {
        public var sival_int:int;

    }

    /**
     * 
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native(cls="::avmshell::Csiginfo_tClass", instance="::avmshell::Csiginfo_tObject", methods="auto")]
    public class siginfo_t
    {
        public var si_signo:int;

        public var si_code:int;

        public var si_errno:int;

        public var si_pid:int;

        public var si_uid:int;

        //public var si_addr:*;

        public var si_status:int;

        public var si_band:Number;

        //public var si_value:sigval = new sigval();
    }

}
