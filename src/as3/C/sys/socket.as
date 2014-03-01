/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/**
* sys/socket.h - main sockets header
* 
* stdio.h is a header file in the standard library of C programming language.
* It defines macros, symbolic constants and functions for file input and output.
* 
* @langversion 3.0
* @playerversion AVM 0.4
* 
* @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/sys_socket.h.html
*/
package C.sys.socket
{

	//socklen_t   - an integer type of width of at least 32 bits
	//sa_family_t - unsigned integer type

    /**
     * @internal
     */
    [native(cls="::avmshell::CSysSocketClass", methods="auto", construct="none")]
    [Inspectable(environment="none")]
    internal class __socket
    {
        public native static function get SOCK_DGRAM():int;
        public native static function get SOCK_RAW():int;
        public native static function get SOCK_SEQPACKET():int;
        public native static function get SOCK_STREAM():int;
    }


    /**
     * Datagram socket.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const SOCK_DGRAM:int = __socket.SOCK_DGRAM;

    /**
     * Raw Protocol Interface.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const SOCK_RAW:int = __socket.SOCK_RAW;

    /**
     * Sequenced-packet socket.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const SOCK_SEQPACKET:int = __socket.SOCK_SEQPACKET;

    /**
     * Byte-stream socket.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const SOCK_STREAM:int = __socket.SOCK_STREAM;


    /**
     * A structure containing a socket descriptor.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    //[native(cls="::avmshell::CsockdClass", instance="::avmshell::CsockdObject", methods="auto")]
    public class sockd
    {

    }

    /**
     * A structure containing information about a socket address.
     *
     * <p>
     * The <b>sockaddr</b> structure is used to define a socket address
     * which is used in the <code>bind()</code>, <code>connect()</code>, <code>getpeername()</code>,
     * <code>getsockname()</code>, <code>recvfrom()</code>, and <code>sendto()</code> functions.
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    //[native(cls="::avmshell::CsockaddrClass", instance="::avmshell::CsockaddrObject", methods="auto")]
    public class sockaddr
    {

    	/**
    	 * Address family.
    	 */
    	public var sa_family:uint;

    	/**
    	 * Socket address (variable-length data).
    	 */
    	public var sa_data:String;

    	public function toSockaddr_storage():sockaddr_storage
    	{
    		var ss:sockaddr_storage = new sockaddr_storage();
    			ss.family = this.family;

    		return ss;
    	}

        /** @private */
        /*[cppcall]
        public function dummyTestRead():void
        {
            trace( "dummyTestRead() called from C++" );
        }*/

        /** @private */
        /*[cppcall]
        public function dummyTestWrite():void
        {
            trace( "dummyTestWrite() called from C++" );
        }*/

    }

    //[native(cls="::avmshell::Csockaddr_storageClass", instance="::avmshell::Csockaddr_storageObject", methods="auto")]
    public class sockaddr_storage
    {

    	/**
    	 * Address family.
    	 */
    	public var ss_family:uint;

    	public function toSockaddr():sockaddr
    	{
    		var sa:sockaddr = new sockaddr();
    			sa.sa_family = this.ss_family;

    		return sa;
    	}

    }


    //[native(cls="::avmshell::CmsghdrClass", instance="::avmshell::CmsghdrObject", methods="auto")]
    public class msghdr
    {

    	/**
    	 * Optional address.
    	 */
    	public var msg_name:*;

    	/**
    	 * Size of address.
    	 */
    	public var msg_namelen:int;

    	/**
    	 * Scatter/gather array.
    	 */
    	public var msg_iov:*;

    	/**
    	 * Members in msg_iov.
    	 */
    	public var msg_iovlen:int;

    	/**
    	 * Ancillary data; see below.
    	 */
    	public var msg_control:*;

    	/**
    	 * Ancillary data buffer len.
    	 */
    	public var msg_controllen:int;

    	/**
    	 * Flags on received message.
    	 */
    	public var msg_flags:int;

    }

}
