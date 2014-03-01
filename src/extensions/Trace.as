/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


package flash.trace
{

    /**
     * The Trace class allows to configure the AVM+ Debugger output.
     * 
     * <p>
     * With the <b>Flash Player</b>, you can enable the debugger output
     * by editing the <code>mm.cfg</code> file with <code>AS3Trace = 1</code>.
     * </p>
     * 
     * <p>
     * With <b>AIR</b> you can package a <code>mm.cfg</code> file at the root of the app
     * and by adding <code>AS3Trace = 1</code> the app will create a <code>flashlog.txt</code>
     * in the "app/Documents/Logs" directory, this file will contain the debugger output.
     * </p>
     * 
     * <p>
     * With the <b>avmshell</b> or the <b>reshell</b>, you can enable the debugger output
     * with the arg option <code>-Dastrace N</code> where N is <code>[1..4]</code> (the level of logging).
     * </p>
     * 
     * @example Basic Usage
     * <listing>
     * import flash.trace.Trace;
     * 
     * //custom trace function
     * function traceListener( file_name:String, linenum:int, method_name:String, method_args:String):void
     * {
     *     trace( method_name + "( " + method_args.join( ", " ) + " )" );
     * }
     * 
     * //start the tracing
     * Trace.setListener( traceListener );
     * Trace.setLevel( Trace.METHODS_AND_LINES_WITH_ARGS, Trace.LISTENER );
     * 
     * //more code here
     * 
     * //stop the tracing
     * Trace.setLevel( Trace.OFF, Trace.LISTENER );
     * </listing>
     * 
     * <p>
     * Output format is <code>AVMINF: LINE/MTHD</code>.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion Flash 9
     * @playerversion AIR 1.0
     * 
     */
    [native(cls="TraceClass", methods="auto", construct="none")]
    public class Trace
    {
        /* levels of desired logging */

        /**
         * Turns off the logging.
         */
        public static const OFF:int = 0;

        /**
         * Logs method entry only.
         */
        public static const METHODS:int = 1;                        // method entry only

        /**
         * Logs method entry and arguments.
         */
        public static const METHODS_WITH_ARGS:int = 2;              // method entry and arguments

        /**
         * Logs method entry and line numbers.
         */
        public static const METHODS_AND_LINES:int = 3;              // method entry and line numbers

        /**
         * 
         */
        public static const METHODS_AND_LINES_WITH_ARGS:int = 4;    // method entry, arguments and line numbers

        /* used to select either file or listener callback logging. */

        /**
         * 
         */
        public static const FILE = 1;

        /**
         * 
         */
        public static const LISTENER = 2;

        /**
         * 
         */
        public static native function setLevel(l:int, target:int=LISTENER);

        /**
         * 
         */
        public static native function getLevel(target:int=LISTENER):int;

        /**
         * Register a listener to receive trace callbacks upon method and/or
         * line number changes.  Passing null to this function effectively
         * 'unregisters' the listener and only a single listener can
         *  be specified.
         *
         *  The callback funcition must have the following signature:
         * <listing>
         *     function foo(file_name:String, linenum:int, method_name:String, method_args:String):void
         * </listing>
         *  Depending upon the setting of the trace level, 2 or more arguments may be non-empty.
         *  In all cases file_name and method_name are obtained and passed to the callback.  If
         *  the trace level include line numbers information then this value is also obtained
         *  and passed into the callback.  Setting the trace level to include method arguments implies
         *  that the 'method_args' parameter will be filled with string representation of the arguments
         *  passed into the call.
         */
        public static native function setListener(f:Function);

        /**
         * 
         */
        public static native function getListener():Function;
    };
};
