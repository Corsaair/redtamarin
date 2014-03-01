/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package C.sys.wait
{
    import C.signal.siginfo_t;
    
    /** @internal */
    [native(cls="::avmshell::CSysWaitClass", methods="auto", construct="none")]
    [Inspectable(environment="none")]
    internal class __wait
    {
        public native static function get WCONTINUED():int;
        public native static function get WNOHANG():int;
        public native static function get WUNTRACED():int;

        public native static function get WEXITED():int;
        public native static function get WNOWAIT():int;
        public native static function get WSTOPPED():int;

        public native static function get P_ALL():int;
        public native static function get P_PGID():int;
        public native static function get P_PID():int;

        public native static function _WEXITSTATUS( status:int ):int;
        public native static function _WIFCONTINUED( status:int ):int;
        public native static function _WIFEXITED( status:int ):int;
        public native static function _WIFSIGNALED( status:int ):int;
        public native static function _WIFSTOPPED( status:int ):int;
        public native static function _WSTOPSIG( status:int ):int;
        public native static function _WTERMSIG( status:int ):int;

    }

    /**
     * Report status of continued child process.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const WCONTINUED:int = __wait.WCONTINUED;

    /**
     * Do not hang if no status is available; return immediately.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const WNOHANG:int = __wait.WNOHANG;

    /**
     * Report status of stopped child process.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const WUNTRACED:int = __wait.WUNTRACED;


    /**
     * Wait for processes that have exited.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const WEXITED:int = __wait.WEXITED;

    /**
     * Keep the process whose status is returned in infop in a waitable state.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const WNOWAIT:int = __wait.WNOWAIT;

    /**
     * Status is returned for any child that has stopped upon receipt of a signal.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const WSTOPPED:int = __wait.WSTOPPED;


    /**
     * 
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const P_ALL:int = __wait.P_ALL;

    /**
     * 
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const P_PGID:int = __wait.P_PGID;

    /**
     * 
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const P_PID:int = __wait.P_PID;



    /**
     * Return exit status.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function WEXITSTATUS( status:int ):int
    {
        return __wait._WEXITSTATUS( status );
    }

    /**
     * True if child has been continued.
     *
     * <p>
     * <b>Note: </b> not supported for <code>Windows</code>.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function WIFCONTINUED( status:int ):int
    {
        return __wait._WIFCONTINUED( status );
    }

    /**
     * True if child exited normally.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function WIFEXITED( status:int ):int
    {
        return __wait._WIFEXITED( status );
    }

    /**
     * True if child exited due to uncaught signal.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function WIFSIGNALED( status:int ):int
    {
        return __wait._WIFSIGNALED( status );
    }

    /**
     * True if child is currently stopped.
     *
     * <p>
     * <b>Note: </b> not supported for <code>Windows</code>.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function WIFSTOPPED( status:int ):int
    {
        return __wait._WIFSTOPPED( status );
    }

    /**
     * Return signal number that caused process to stop.
     *
     * <p>
     * <b>Note: </b> not supported for <code>Windows</code>.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function WSTOPSIG( status:int ):int
    {
        return __wait._WSTOPSIG( status );
    }

    /**
     * Return signal number that caused process to terminate.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function WTERMSIG( status:int ):int
    {
        return __wait._WTERMSIG( status );
    }

    /**
     *
     * <p>
     * <b>Note: </b> not supported for <code>Windows</code>.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CSysWaitClass::wait")]
    public native function wait( waitstat:wait_status ):int;

    /**
     *
     * <p>
     * <b>Note: </b> not supported for <code>Windows</code>.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CSysWaitClass::waitid")]
    public native function waitid( idtype:int, id:int, infop:siginfo_t, options:int ):int;

    /**
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CSysWaitClass::waitpid")]
    public native function waitpid( pid:int, waitstat:wait_status, options:int ):int;



    /**
     * Used with <code>waitpid()</code> to pass by reference the <code>stat_loc</code> integer,
     * here instead of directly passing by reference an integer (as possible in C, and not possible in AS3)
     * we pass by reference an object which contains the property <code>stat_loc</code> of type integer.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native(cls="::avmshell::CWaitStatusClass", instance="::avmshell::CWaitStatusObject", methods="auto")]
    public class wait_status
    {
        public var stat_loc:int;
    }

    /**
     *
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    /*public class idtype_t
    {
        public const P_ALL:idtype_t = new idtype_t(  __wait.P_ALL, "P_ALL" );
        public const P_PGID:idtype_t = new idtype_t( __wait.P_PGID, "P_PGID" );
        public const P_PID:idtype_t = new idtype_t(  __wait.P_PID, "P_PID" );

        private var _value:int;
        private var _name:String;

        public function idtype_t( value:int, name:String )
        {
            _value = value;
            _name  = name;
        }

        public function toString():String
        {
            return _name;
        }

        public function valueOf():int
        {
            return _value;
        }
    }*/

}
