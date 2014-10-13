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
    import C.errno.*;
    import C.netinet.*;

    import flash.utils.ByteArray;

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

        public native static function get SOL_SOCKET():int;

        //getsockopt() or setsockopt()
        public native static function get SO_ACCEPTCONN():int;
        public native static function get SO_BROADCAST():int;
        public native static function get SO_DEBUG():int;
        public native static function get SO_DONTROUTE():int;
        public native static function get SO_ERROR():int;
        public native static function get SO_KEEPALIVE():int;
        public native static function get SO_LINGER():int;
        public native static function get SO_OOBINLINE():int;
        public native static function get SO_RCVBUF():int;
        public native static function get SO_RCVLOWAT():int;
        public native static function get SO_RCVTIMEO():int;
        public native static function get SO_REUSEADDR():int;
        public native static function get SO_SNDBUF():int;
        public native static function get SO_SNDLOWAT():int;
        public native static function get SO_SNDTIMEO():int;
        public native static function get SO_TYPE():int;

        //listen()
        public native static function get SOMAXCONN():int;

        //msghdr, recv(), recvfrom(), recvmsg(), send(), sendmsg(), or sendto()
        public native static function get MSG_CTRUNC():int;
        public native static function get MSG_DONTROUTE():int;
        public native static function get MSG_EOR():int;
        public native static function get MSG_OOB():int;
        public native static function get MSG_NOSIGNAL():int;
        public native static function get MSG_PEEK():int;
        public native static function get MSG_TRUNC():int;
        public native static function get MSG_WAITALL():int;

        public native static function get AF_INET():int;
        public native static function get AF_INET6():int;
        public native static function get AF_UNIX():int;
        public native static function get AF_UNSPEC():int;

        public native static function get SHUT_RD():int;
        public native static function get SHUT_RDWR():int;
        public native static function get SHUT_WR():int;

        public native static function accept4( socket:int, address:sockaddr_in ):int;
        public native static function accept6( socket:int, address:sockaddr_in6 ):int;

        public native static function bind4( socket:int, address:sockaddr_in ):int;
        public native static function bind6( socket:int, address:sockaddr_in6 ):int;

        public native static function connect4( socket:int, address:sockaddr_in ):int;
        public native static function connect6( socket:int, address:sockaddr_in6 ):int;

        public native static function getpeername4( socket:int, address:sockaddr_in ):int;
        public native static function getpeername6( socket:int, address:sockaddr_in6 ):int;
        
        public native static function getsockname4( socket:int, address:sockaddr_in ):int;
        public native static function getsockname6( socket:int, address:sockaddr_in6 ):int;

        public native static function getsockoptint( socket:int, level:int, option_name:int, option_value:ByteArray ):int;
        //getsockoptlinger( socket:int, level:int, option_name:int, option_value:linger ):int
        //getsockopttimeval( socket:int, level:int, option_name:int, option_value:timevl ):int
        
        public native static function recvfrom4( socket:int, bytes:ByteArray, address:sockaddr_in, len:int, flags:int = 0 ):int;
        public native static function recvfrom6( socket:int, bytes:ByteArray, address:sockaddr_in6, len:int, flags:int = 0 ):int;

        public native static function sendto4( socket:int, bytes:ByteArray, address:sockaddr_in, flags:int = 0, buffer:uint = 0 ):int;
        public native static function sendto6( socket:int, bytes:ByteArray, address:sockaddr_in6, flags:int = 0, buffer:uint = 0 ):int;

        public native static function setsockoptint( socket:int, level:int, option_name:int, option_value:int ):int;
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
     * Options to be accessed at socket level, not protocol level.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const SOL_SOCKET:int = __socket.SOL_SOCKET;

    /**
     * Socket is accepting connections.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const SO_ACCEPTCONN:int = __socket.SO_ACCEPTCONN;

    /**
     * Transmission of broadcast messages is supported.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const SO_BROADCAST:int = __socket.SO_BROADCAST;

    /**
     * Debugging information is being recorded.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const SO_DEBUG:int = __socket.SO_DEBUG;

    /**
     * Bypass normal routing.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const SO_DONTROUTE:int = __socket.SO_DONTROUTE;

    /**
     * Socket error status.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const SO_ERROR:int = __socket.SO_ERROR;

    /**
     * Connections are kept alive with periodic messages.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const SO_KEEPALIVE:int = __socket.SO_KEEPALIVE;

    /**
     * Socket lingers on close.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const SO_LINGER:int = __socket.SO_LINGER;

    /**
     * Out-of-band data is transmitted in line.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const SO_OOBINLINE:int = __socket.SO_OOBINLINE;

    /**
     * Receive buffer size.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const SO_RCVBUF:int = __socket.SO_RCVBUF;

    /**
     * Receive "low water mark".
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const SO_RCVLOWAT:int = __socket.SO_RCVLOWAT;

    /**
     * Receive timeout.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const SO_RCVTIMEO:int = __socket.SO_RCVTIMEO;

    /**
     * Reuse of local addresses is supported.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const SO_REUSEADDR:int = __socket.SO_REUSEADDR;

    /**
     * Send buffer size.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const SO_SNDBUF:int = __socket.SO_SNDBUF;

    /**
     * Send "low water mark".
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const SO_SNDLOWAT:int = __socket.SO_SNDLOWAT;

    /**
     * Send timeout.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const SO_SNDTIMEO:int = __socket.SO_SNDTIMEO;

    /**
     * Socket type.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const SO_TYPE:int = __socket.SO_TYPE;

    /**
     * The maximum backlog queue length.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const SOMAXCONN:int = __socket.SOMAXCONN;

    /**
     * Control data truncated.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const MSG_CTRUNC:int = __socket.MSG_CTRUNC;

    /**
     * Send without using routing tables.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const MSG_DONTROUTE:int = __socket.MSG_DONTROUTE;

    /**
     * Terminates a record (if supported by the protocol).
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const MSG_EOR:int = __socket.MSG_EOR;

    /**
     * Out-of-band data.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const MSG_OOB:int = __socket.MSG_OOB;

    /**
     * No <code>SIGPIPE</code> generated when an attempt
     * to send is made on a stream-oriented socket
     * that is no longer connected.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const MSG_NOSIGNAL:int = __socket.MSG_NOSIGNAL;

    /**
     * Leave received data in queue.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const MSG_PEEK:int = __socket.MSG_PEEK;

    /**
     * Normal data truncated.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const MSG_TRUNC:int = __socket.MSG_TRUNC;

    /**
     * Attempt to fill the read buffer.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const MSG_WAITALL:int = __socket.MSG_WAITALL;

    /**
     * Internet domain sockets for use with IPv4 addresses.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const AF_INET:int = __socket.AF_INET;

    /**
     * Internet domain sockets for use with IPv6 addresses.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const AF_INET6:int = __socket.AF_INET6;

    /**
     * UNIX domain sockets.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const AF_UNIX:int = __socket.AF_UNIX;

    /**
     * Unspecified.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const AF_UNSPEC:int = __socket.AF_UNSPEC;

    /**
     * Disables further receive operations.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const SHUT_RD:int = __socket.SHUT_RD;

    /**
     * Disables further send and receive operations.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const SHUT_RDWR:int = __socket.SHUT_RDWR;

    /**
     * Disables further send operations.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const SHUT_WR:int = __socket.SHUT_WR;


    
    /**
     * Accept a new connection on a socket.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/accept.html
     */
    public function accept( socket:int, address:* ):int
    {
        /* NOTE:
           here we cannot accept the type sockaddr
           because we can not cast it back to address reference
           well... we could accept it and then convert ti to a sockaddr_in/sockaddr_in6
           but then the original address object will stay unmodified
           and so useless
        */

        //address CAN be null
        /*if( !address )
        {
            Error.throwError( ArgumentError, Errors.kNullArgumentError, "address" );
        }*/

        if( address is sockaddr_in || !address )
        {
            return __socket.accept4( socket, address as sockaddr_in );
        }
        else if( address is sockaddr_in6 )
        {
            return __socket.accept6( socket, address as sockaddr_in6 );
        }

        trace( "'address' is not of the suppported type: sockaddr_in or sockaddr_in6" );
        trace( "address = " + address );
        errno.value = ENOSYS;
        return -1;
    }

    /**
     * Bind a name to a socket.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/bind.html
     */
    public function bind( socket:int, address:* ):int
    {
        if( !address )
        {
            Error.throwError( ArgumentError, Errors.kNullArgumentError, "address" );
        }

        var addr:*;
        if( address is sockaddr )
        {
            if( address.sa_family == AF_INET )
            {
                addr = address.toSockaddr_in();
            }
            else if( address.sa_family == AF_INET6 )
            {
                addr = address.toSockaddr_in6();
            }
            else
            {
                trace( "BETA: sa_family=" + address.sa_family + " not supported yet" );
                errno.value = ENOSYS;
                return -1;
            }
        }
        else
        {
            addr = address;
        }

        if( addr is sockaddr_in )
        {
            return __socket.bind4( socket, addr as sockaddr_in );
        }
        else if( addr is sockaddr_in6 )
        {
            return __socket.bind6( socket, addr as sockaddr_in6 );
        }

        trace( "'address' is not of the suppported type: sockaddr, sockaddr_in or sockaddr_in6" );
        trace( "address = " + address );
        errno.value = ENOSYS;
        return -1;
    }

    /**
     * Connect a socket.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/connect.html
     */
    public function connect( socket:int, address:* ):int
    {
        if( !address )
        {
            Error.throwError( ArgumentError, Errors.kNullArgumentError, "address" );
        }

        var addr:*;
        if( address is sockaddr )
        {
            if( address.sa_family == AF_INET )
            {
                addr = address.toSockaddr_in();
            }
            else if( address.sa_family == AF_INET6 )
            {
                addr = address.toSockaddr_in6();
            }
            else
            {
                trace( "BETA: sa_family=" + address.sa_family + " not supported yet" );
                errno.value = ENOSYS;
                return -1;
            }
        }
        else
        {
            addr = address;
        }

        if( addr is sockaddr_in )
        {
            return __socket.connect4( socket, addr as sockaddr_in );
        }
        else if( addr is sockaddr_in6 )
        {
            return __socket.connect6( socket, addr as sockaddr_in6 );
        }

        trace( "'address' is not of the suppported type: sockaddr, sockaddr_in or sockaddr_in6" );
        trace( "address = " + address );
        errno.value = ENOSYS;
        return -1;
    }

    /**
     * Get the name of the peer socket.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/getpeername.html
     */
    public function getpeername( socket:int, address:* ):int
    {
        if( !address )
        {
            Error.throwError( ArgumentError, Errors.kNullArgumentError, "address" );
        }

        if( address is sockaddr_in )
        {
            return __socket.getpeername4( socket, address as sockaddr_in );
        }
        else if( address is sockaddr_in6 )
        {
            return __socket.getpeername6( socket, address as sockaddr_in6 );
        }

        trace( "'address' is not of the suppported type: sockaddr_in or sockaddr_in6" );
        trace( "address = " + address );
        errno.value = ENOSYS;
        return -1;
    }

    /**
     * Get the socket name.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/getsockname.html
     */
    public function getsockname( socket:int, address:* ):int
    {
        if( !address )
        {
            Error.throwError( ArgumentError, Errors.kNullArgumentError, "address" );
        }

        if( address is sockaddr_in )
        {
            return __socket.getsockname4( socket, address as sockaddr_in );
        }
        else if( address is sockaddr_in6 )
        {
            return __socket.getsockname6( socket, address as sockaddr_in6 );
        }

        trace( "'address' is not of the suppported type: sockaddr_in or sockaddr_in6" );
        trace( "address = " + address );
        errno.value = ENOSYS;
        return -1;
    }

    /**
     * Get the socket options.
     *
     * <p>
     * Some optiosn are nto available on all systems.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/getsockopt.html
     * @see 2.10.16 Use of Options http://pubs.opengroup.org/onlinepubs/9699919799/functions/V2_chap02.html#tag_15_10_16
     * @see MSDN getsockopt function http://msdn.microsoft.com/en-us/library/windows/desktop/ms738544(v=vs.85).aspx
     * @see Winsock 2 program examples http://www.tenouk.com/Winsock/Winsock2example6.html
     */
    public function getsockopt( socket:int, level:int, option_name:int, option_value:ByteArray ):int
    {
        if( !option_value )
        {
            Error.throwError( ArgumentError, Errors.kNullArgumentError, "option_value" );
        }

        // Socket-Level Options
        switch( option_name )
        {
            //int
            case SO_ACCEPTCONN:
            case SO_BROADCAST:
            case SO_DEBUG:
            case SO_DONTROUTE:
            case SO_ERROR:
            case SO_KEEPALIVE:
            case SO_OOBINLINE:
            case SO_RCVBUF:
            case SO_RCVLOWAT:
            case SO_REUSEADDR:
            case SO_SNDBUF:
            case SO_SNDLOWAT:
            case SO_TYPE:
            
            return __socket.getsockoptint( socket, level, option_name, option_value );

            break;

            //struct linger
            case SO_LINGER:
            //break; //not supported yet

            //struct timeval
            case SO_RCVTIMEO:
            case SO_SNDTIMEO:
            //break; //not supported yet

            default:
            trace( "option_name=" + option_name + " is not supported" );
            errno.value = ENOPROTOOPT;
            return -1;
        }
    }

    /**
     * Get the socket options value.
     *
     * <p>
     * non-standard util.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function getsockoption( socket:int, level:int, option_name:int ):*
    {
        var value:ByteArray = new ByteArray();
        var result:int = getsockopt( socket, level, option_name, value );

        if( result != -1 )
        {
            value.position = 0;
            var o:* = value.readObject();
            return o;
        }

        return -1; //failure
    }


    /**
     * Listen for socket connections and limit the queue of incoming connections.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/listen.html
     */
    [native("::avmshell::CSysSocketClass::listen")]
    public native function listen( socket:int, backlog:int ):int;

    /**
     * Receive a message from a connected socket.
     *
     * <p>
     * By default we set <code>len = 8192</code> or <code>8KB (8 x 1024)</code>
     * and this is arbitrary as there are no absolute answer to
     * "How large shoudl the recv buffer be ?".
     *
     * There are different and many situations wether you use TCP or UDP,
     * wether you use IPv4 or IPv6, the size of the MTU (Max Transmission Unit), etc.
     *
     * In general we advise you to use a power of 2:
     * <code>512</code>, <code>1024</code>, <code>2048</code>, <code>4096</code>, <code>8192</code>, etc.
     * because there are nice even numbers and convenient to remember.
     *
     * In short, if your receive buffer is too big it will fragment
     * and you may lost the data.
     * </p>
     *
     * <p>
     * You can also run out of memory, because we use <code>ByteArray</code> with <code>int</code>
     * we check the buffer is not bigger than <code>int.MAX_VALUE</code> or <code>2147483647</code>
     * or <code>2GB</code>.
     *
     * You will run our of memory if you try to assign an amount (of recv buffer) bigger
     * than your actual available memory.
     *
     * For example, if you have 512MB of RAM available and try to receive 1GB of data.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/recv.html
     * @see http://en.wikipedia.org/wiki/Maximum_transmission_unit
     * @see RFC 1122
     * @see UNIX Network Programming by W. Richard Stevens
     */
    [native("::avmshell::CSysSocketClass::recv")]
    public native function recv( socket:int, bytes:ByteArray, len:int = 8192, flags:int = 0 ):int;

    /**
     * Receive the full message on a socket.
     *
     * <p>
     * This function handle reassembly buffer for you.
     * </p>
     *
     * <p>
     * The <code>len</code> allows you to define how much to split the data.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://beej.us/guide/bgnet/output/html/singlepage/bgnet.html#sendall
     */
    public function recvall( socket:int, bytes:ByteArray, len:int = 8192, flags:int = 0 ):int
    {
        var total:uint = 0; // how many bytes we received
        var n:int;
        var b:ByteArray = new ByteArray();

        var run:Boolean = true;
        while( run )
        {
            b.clear();
            n = recv( socket, b, len, flags );
            if( n == -1 ) { run = false; break; }
            bytes.writeBytes( b );
            total += n;
            if( n < len ) { run = false; break; }
        }
        
        b.clear();

        if( n < 0 )
        {
            return -1; //failure
        }

        return total; // number of bytes actually received
    }

    /**
     * Receive a message from a socket.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/recvfrom.html
     */
    public function recvfrom( socket:int, bytes:ByteArray, address:*, len:int = 8192, flags:int = 0 ):int
    {
        if( !bytes )
        {
            Error.throwError( ArgumentError, Errors.kNullArgumentError, "bytes" );
        }

        if( !address )
        {
            Error.throwError( ArgumentError, Errors.kNullArgumentError, "address" );
        }

        var addr:*;
        if( address is sockaddr )
        {
            if( address.sa_family == AF_INET )
            {
                addr = address.toSockaddr_in();
            }
            else if( address.sa_family == AF_INET6 )
            {
                addr = address.toSockaddr_in6();
            }
            else
            {
                trace( "BETA: sa_family=" + address.sa_family + " not supported yet" );
                errno.value = ENOSYS;
                return -1;
            }
        }
        else
        {
            addr = address;
        }

        if( addr is sockaddr_in )
        {
            return __socket.recvfrom4( socket, bytes, addr as sockaddr_in, len, flags );
        }
        else if( addr is sockaddr_in6 )
        {
            return __socket.recvfrom6( socket, bytes, addr as sockaddr_in6, len, flags );
        }

        trace( "'address' is not of the suppported type: sockaddr, sockaddr_in or sockaddr_in6" );
        trace( "address = " + address );
        errno.value = ENOSYS;
        return -1;
    }

    //recvmsg()
    
    /**
     * Send a message on a socket.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/send.html
     */
    [native("::avmshell::CSysSocketClass::send")]
    public native function send( socket:int, bytes:ByteArray, flags:int = 0, buffer:uint = 0 ):int;

    /**
     * Send the full message on a socket.
     *
     * <p>
     * This function handle partial sends for you.
     * </p>
     *
     * <p>
     * The <code>buffer</code> allows you to define how much to split the data.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://beej.us/guide/bgnet/output/html/singlepage/bgnet.html#sendall
     */
    public function sendall( socket:int, bytes:ByteArray, flags:int = 0, buffer:uint = 0 ):int
    {
        var len:uint       = bytes.length;
        var total:uint     = 0;   // how many bytes we've sent
        var bytesleft:uint = len; // how many we have left to send
        var n:int;

        var b:ByteArray = new ByteArray();

        while( total < len )
        {
            b.clear();
            b.writeBytes( bytes, total, bytesleft );
            n = send( socket, b, flags, buffer );
            if( n == -1 ) { break; }
            total     += n;
            bytesleft -= n;
        }

        b.clear();

        if( n < 0 )
        {
            return -1; //failure
        }

        return total; // number of bytes actually sent
    }

    //sendmsg()
    
    /**
     * Send a message on a socket.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/sendto.html
     */
    public function sendto( socket:int, bytes:ByteArray, address:*, flags:int = 0, buffer:uint = 0 ):int
    {
        if( !bytes )
        {
            Error.throwError( ArgumentError, Errors.kNullArgumentError, "bytes" );
        }

        if( !address )
        {
            Error.throwError( ArgumentError, Errors.kNullArgumentError, "address" );
        }

        var addr:*;
        if( address is sockaddr )
        {
            if( address.sa_family == AF_INET )
            {
                addr = address.toSockaddr_in();
            }
            else if( address.sa_family == AF_INET6 )
            {
                addr = address.toSockaddr_in6();
            }
            else
            {
                trace( "BETA: sa_family=" + address.sa_family + " not supported yet" );
                errno.value = ENOSYS;
                return -1;
            }
        }
        else
        {
            addr = address;
        }

        if( addr is sockaddr_in )
        {
            return __socket.sendto4( socket, bytes, addr as sockaddr_in, flags, buffer );
        }
        else if( addr is sockaddr_in6 )
        {
            return __socket.sendto6( socket, bytes, addr as sockaddr_in6, flags, buffer );
        }

        trace( "'address' is not of the suppported type: sockaddr, sockaddr_in or sockaddr_in6" );
        trace( "address = " + address );
        errno.value = ENOSYS;
        return -1;
    }
    
    /**
     * Set the socket options.
     *
     * <p>
     * Some optiosn are nto available on all systems.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/setsockopt.html
     */
    public function setsockopt( socket:int, level:int, option_name:int, option_value:* ):int
    {
        if( !option_value )
        {
            Error.throwError( ArgumentError, Errors.kNullArgumentError, "option_value" );
        }

        // Socket-Level Options
        switch( option_name )
        {
            //int
            case SO_ACCEPTCONN:
            case SO_BROADCAST:
            case SO_DEBUG:
            case SO_DONTROUTE:
            case SO_ERROR:
            case SO_KEEPALIVE:
            case SO_OOBINLINE:
            case SO_RCVBUF:
            case SO_RCVLOWAT:
            case SO_REUSEADDR:
            case SO_SNDBUF:
            case SO_SNDLOWAT:
            case SO_TYPE:
            
            return __socket.setsockoptint( socket, level, option_name, option_value as int );

            break;

            //struct linger
            case SO_LINGER:
            //break; //not supported yet

            //struct timeval
            case SO_RCVTIMEO:
            case SO_SNDTIMEO:
            //break; //not supported yet

            default:
            trace( "option_name=" + option_name + " is not supported" );
            errno.value = ENOPROTOOPT;
            return -1;
        }
    }

    /**
     * Set the socket options value.
     *
     * <p>
     * non-standard util.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function setsockoption( socket:int, level:int, option_name:int, option_value:* ):*
    {
        /* NOTE:
           only there to have a nice pair getsockoption() / setsockoption()
        */
        return setsockopt( socket, level, option_name, option_value );
    }

    /**
     * Shut down socket send and receive operations.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/shutdown.html
     */
    [native("::avmshell::CSysSocketClass::shutdown")]
    public native function shutdown( socket:int, how:int ):int;

    /**
     * Determine whether a socket is at the out-of-band mark.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/sockatmark.html
     * @see 2.10.12 Socket Out-of-Band Data State http://pubs.opengroup.org/onlinepubs/9699919799/functions/V2_chap02.html#tag_15_10_12
     */
    [native("::avmshell::CSysSocketClass::sockatmark")]
    public native function sockatmark( s:int ):int;

    /**
     * Create an endpoint for communication.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/socket.html
     */
    [native("::avmshell::CSysSocketClass::socket")]
    public native function socket( domain:int, type:int, protocol:int ):int;

    /**
     * Create a pair of connected sockets.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/socketpair.html
     */
    [native("::avmshell::CSysSocketClass::socketpair")]
    public native function socketpair( domain:int, type:int, protocol:int, sockets:Array ):int;
    


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
    [native(cls="::avmshell::CsockaddrClass", instance="::avmshell::CsockaddrObject", methods="auto")]
    public class sockaddr
    {

        public function sockaddr( sa_family:uint = 0, sa_data:* = null ):void
        {
            this.sa_family = sa_family;
            this.sa_data   = new Vector.<uint>();

            if( sa_data )
            {
                _load( sa_data );
            }
        }

    	/**
    	 * Address family.
    	 */
    	public var sa_family:uint;

    	/**
    	 * Socket address (variable-length data).
    	 */
    	public var sa_data:Vector.<uint>;

        private function _load( data:* )
        {
            if( data is sockaddr_in )
            {
                var addr4:sockaddr_in = data as sockaddr_in;
                var addr32bit:uint    = addr4.sin_addr.s_addr;

                sa_data    = new Vector.<uint>();
                sa_data[0] = (addr32bit >> 24) & 0xff;
                sa_data[1] = (addr32bit >> 16) & 0xff;
                sa_data[2] = (addr32bit >> 8) & 0xff;
                sa_data[3] = (addr32bit) & 0xff;

                sa_family = addr4.sin_family;

            }
            else if( data is sockaddr_in6 )
            {
                var addr6:sockaddr_in6 = data as sockaddr_in6;

                sa_data = new Vector.<uint>();
                for( var i:uint = 0; i < addr6.sin6_addr.s6_addr.length; i++ )
                {
                    sa_data[i] = addr6.sin6_addr.s6_addr[i];
                }
                
                sa_family = addr6.sin6_family;

            }
            else if( data is Vector.<uint> )
            {
                var len:uint = data.length;

                if( (len == 4) || (len == 16) )
                {
                    sa_data = new Vector.<uint>();
                    for( var i:uint = 0; i < len; i++ )
                    {
                        sa_data[i] = data[i];
                    }

                    if(len == 4)
                    {
                        sa_family = AF_INET;
                    }
                    else if(len == 16)
                    {
                        sa_family = AF_INET6;
                    }
                }

            }
        }


    	public function toSockaddr_storage():sockaddr_storage
    	{
    		/*var ss:sockaddr_storage = new sockaddr_storage();
    			ss.family = this.family;

    		return ss;*/
            return null;
    	}

        public function toSockaddr_in():sockaddr_in
        {
            if( sa_family == AF_INET )
            {
                var addr4:sockaddr_in = new sockaddr_in();
                    addr4.sin_family  = sa_family;

                var a:uint = sa_data[0];
                var b:uint = sa_data[1];
                var c:uint = sa_data[2];
                var d:uint = sa_data[3];

                addr4.sin_addr.s_addr = (a << 24) | (b << 16) | (c << 8) | d;

                return addr4;
            }

            return null;
        }

        public function toSockaddr_in6():sockaddr_in6
        {
            if( sa_family == AF_INET6 )
            {
                var addr6:sockaddr_in6 = new sockaddr_in6();
                    addr6.sin6_family  = sa_family;

                for( var i:uint = 0; i < sa_data.length; i++ )
                {
                    addr6.sin6_addr.s6_addr[i] = sa_data[i];
                }

                return addr6;
            }

            return null;
        }

        public function toSockaddr():*
        {
            if( sa_family == AF_INET )
            {
                return toSockaddr_in();
            }
            else if( sa_family == AF_INET6 )
            {
                return toSockaddr_in6();
            }

            return null;
        }
    }

    //not supported/used yet
    //[native(cls="::avmshell::Csockaddr_storageClass", instance="::avmshell::Csockaddr_storageObject", methods="auto")]
    public class sockaddr_storage
    {

    	/**
    	 * Address family.
    	 */
    	public var ss_family:uint;

    }


    //not supported/used yet
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
