/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package C.sys.select
{
	import C.errno.*;

    /**
     * @internal
     */
    [native(cls="::avmshell::CSysSelectClass", methods="auto", construct="none")]
    [Inspectable(environment="none")]
    internal class __select
    {
        public native static function get FD_SETSIZE():int;
    }

    /**
     * Maximum number of file descriptors in an <code>fd_set</code> structure.
     *
     * <p>
     * We overrided the size to <code>16384</code> (or <code>2^14</code>),
     * but it could create problems, if so please report bugs.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const FD_SETSIZE:int = __select.FD_SETSIZE;


    /**
     * Shall remove the file descriptor <code>fd</code>
     * from the set pointed to by <code>fdsetp</code>.
     *
     * <p>
     * If fd is not a member of this set,
     * there shall be no effect on the set,
     * nor will an error be returned.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/select.html
     */
    [native("::avmshell::CSysSelectClass::__FD_CLR")]
    public native function FD_CLR( fd:int, fdsetp:fd_set ):void;

    /**
     * Shall evaluate to non-zero if the file descriptor <code>fd</code>
     * is a member of the set pointed to by <code>fdsetp</code>,
     * and shall evaluate to zero otherwise.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/select.html
     */
    [native("::avmshell::CSysSelectClass::__FD_ISSET")]
    public native function FD_ISSET( fd:int, fdsetp:fd_set ):int;

    /**
     * Shall add the file descriptor <code>fd</code>
     * to the set pointed to by <code>fdsetp</code>.
     * 
     * <p>
     * If the file descriptor <code>fd</code> is already in this set,
     * there shall be no effect on the set,
     * nor will an error be returned.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/select.html
     */
    [native("::avmshell::CSysSelectClass::__FD_SET")]
    public native function FD_SET( fd:int, fdsetp:fd_set ):void;

    /**
     * Shall initialize the descriptor set pointed to by <code>fdsetp</code>
     * to the <code>null</code> set.
     *
     * <p>
     * No error is returned if the set is not empty
     * at the time <code>FD_ZERO()</code> is invoked.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/select.html
     */
    [native("::avmshell::CSysSelectClass::__FD_ZERO")]
    public native function FD_ZERO( fdsetp:fd_set ):void;


    /**
     * Synchronous I/O multiplexing.
     *
     * <p>
     * The arguments <code>readfds</code>, <code>writefds</code> and <code>errorfds</code>
     * can be <code>null</code> but you will to explicitly set them to <code>null</code>.
     * </p>
     * 
     * <p>
     * The <code>timeout</code> argument is mandatory,
     * either you provide time values for the <code>select()</code> to wait,
     * or set those values to <code>zero</code> to not wait.
     * THe third option to provide a <code>null</code> time value is not available.
     * (eg. when timevla is null, the select first block forever till a first connection is made).
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/select.html
     */
    [native("::avmshell::CSysSelectClass::select")]
    public native function select( nfds:int, readfds:fd_set, writefds:fd_set, errorfds:fd_set, timeout:timeval ):int;



    /**
     * Test if a socket is ready for reading.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CSysSelectClass::isReadable")]
    public native function isReadable( nfds:int, err:CError = null ):Boolean;

    /**
     * Test if a socket is ready for writing.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CSysSelectClass::isWritable")]
    public native function isWritable( nfds:int, err:CError = null ):Boolean;

    /**
     * Test if a socket has an exceptional condition pending.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CSysSelectClass::isExceptional")]
    public native function isExceptional( nfds:int, err:CError = null ):Boolean;





    /**
     * A structure containing precise time values.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native(cls="::avmshell::CtimevalClass", instance="::avmshell::CtimevalObject", methods="auto")]
    public class timeval
    {
    	public function timeval( tv_sec:int = 0, tv_usec:int = 0 ):void
    	{
    		super();

    		this.tv_sec  = tv_sec;
    		this.tv_usec = tv_usec;
    	}

    	/**
    	 * Seconds.
    	 */
    	public var tv_sec:int;

    	/**
    	 * Microseconds.
    	 *
    	 * <p>
    	 * There are <code>1000</code> microseconds in a millisecond,
    	 * and <code>1000</code> milliseconds in a second.
    	 * Thus, there are <code>1000000</code> microseconds in a second.
    	 * </p>
    	 * 
    	 */
    	public var tv_usec:int;

    	public function toString():String
    	{
    		// will be wrongish if usec > 1000000-1
    		// {0.000000 sec}
    		var str:String = "";
    			str += "{";
    			str += String( tv_sec );
    			str += ".";

    			var usec:String = String( tv_usec );
    			while( usec.length < 6 )
    			{
    				usec = "0" + usec;
    			}

    			str += usec;
    			str += " sec"
    			str += "}";

    		return str;
    	}
    }

    /**
     * A structure file/socket descriptors.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native(cls="::avmshell::Cfd_setClass", instance="::avmshell::Cfd_setObject", methods="auto")]
    public class fd_set
    {
    	public function fd_set():void
    	{
    		super();
    	}
    }

}
