/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is [clib - C more or less standard Libraries].
 *
 * The Initial Developer of the Original Code is
 * Zwetan Kjukov <zwetan@gmail.com>.
 * Portions created by the Initial Developer are Copyright (C) 2010
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

package C.socket
{
    
    /**
     * Socket constants and function helpers.
     * @internal
     * 
     * @langversion 3.0
     * @playerversion AVM 0.3
     */
    [native(cls="::avmshell::CSocketClass", methods="auto", construct="none")]
    [Inspectable(environment="none")]
    internal class __socket
    {
        public native static function get SOCK_RAW():int;
        public native static function get SOCK_STREAM():int;
        public native static function get SOCK_DGRAM():int;

        public native static function get SO_ACCEPTCONN():int;
        public native static function get SO_BROADCAST():int;
        public native static function get SO_DONTROUTE():int;
        public native static function get SO_KEEPALIVE():int;
        public native static function get SO_OOBINLINE():int;
        public native static function get SO_RCVBUF():int;
        public native static function get SO_RCVTIMEO():int;
        public native static function get SO_REUSEADDR():int;
        public native static function get SO_SNDBUF():int;
        public native static function get SO_SNDTIMEO():int;
        public native static function get SO_TYPE():int;

        public native static function get MSG_CTRUNC():int;
        public native static function get MSG_DONTROUTE():int;
        public native static function get MSG_OOB():int;
        public native static function get MSG_PEEK():int;
        public native static function get MSG_TRUNC():int;
        public native static function get MSG_WAITALL():int;
        public native static function get MSG_DONTWAIT():int;

        public native static function get AF_INET():int;
        public native static function get AF_INET6():int;
        public native static function get AF_UNSPEC():int;

        public native static function get SHUT_RD():int;
        public native static function get SHUT_RDWR():int;
        public native static function get SHUT_WR():int;

        public native static function get IPPROTO_IP():int;
        public native static function get IPPROTO_IPV6():int;
        public native static function get IPPROTO_ICMP():int;
        public native static function get IPPROTO_RAW():int;
        public native static function get IPPROTO_TCP():int;
        public native static function get IPPROTO_UDP():int;

        public native static function get SOMAXCONN():int;

        public native static function __gethostbyaddr( addr:String, numeric:Boolean ):Array;     //struct hostent *gethostbyaddr(const void *addr, socklen_t len, int type);
        public native static function __gethostbyname( hostname:String, numeric:Boolean ):Array; //struct hostent *gethostbyname(const char *name);
        public native static function __getpeername( descriptor:int ):String;                    //int getpeername(int socket, struct sockaddr *restrict address, socklen_t *restrict address_len);
        public native static function __getsockname( descriptor:int ):String;                    //int getsockname(int socket, struct sockaddr *restrict address, socklen_t *restrict address_len);
        
    }

    /** Raw Protocol Interface.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const SOCK_RAW:int    = __socket.SOCK_RAW;

    /** Byte-stream socket.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const SOCK_STREAM:int = __socket.SOCK_STREAM;

    /** Datagram socket.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const SOCK_DGRAM:int  = __socket.SOCK_DGRAM;


    /** Socket is accepting connections.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const SO_ACCEPTCONN:int = __socket.SO_ACCEPTCONN;

    /** Transmission of broadcast messages is supported.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const SO_BROADCAST:int  = __socket.SO_BROADCAST;

    /** Bypass normal routing.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const SO_DONTROUTE:int  = __socket.SO_DONTROUTE;

    /** Connections are kept alive with periodic messages.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const SO_KEEPALIVE:int  = __socket.SO_KEEPALIVE;

    /** Out-of-band data is transmitted in line.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const SO_OOBINLINE:int  = __socket.SO_OOBINLINE;

    /** Receive buffer size.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const SO_RCVBUF:int     = __socket.SO_RCVBUF;

    /** Receive timeout.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const SO_RCVTIMEO:int   = __socket.SO_RCVTIMEO;

    /** Reuse of local addresses is supported.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const SO_REUSEADDR:int  = __socket.SO_REUSEADDR;

    /** Send buffer size.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const SO_SNDBUF:int     = __socket.SO_SNDBUF;

    /** Send timeout.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const SO_SNDTIMEO:int   = __socket.SO_SNDTIMEO;

    /** Socket type.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const SO_TYPE:int       = __socket.SO_TYPE;
    
    
    /** Control data truncated.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const MSG_CTRUNC:int    = __socket.MSG_CTRUNC;

    /** Send without using routing tables.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const MSG_DONTROUTE:int = __socket.MSG_DONTROUTE;

    /** Out-of-band data.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const MSG_OOB:int       = __socket.MSG_OOB;

    /** Leave received data in queue.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const MSG_PEEK:int      = __socket.MSG_PEEK;

    /** Normal data truncated.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const MSG_TRUNC:int     = __socket.MSG_TRUNC;

    /** Attempt to fill the read buffer.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const MSG_WAITALL:int   = __socket.MSG_WAITALL;

    /** Enables non-blocking operation; if the operation would block, EAGAIN is returned.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const MSG_DONTWAIT:int   = __socket.MSG_DONTWAIT;
    

    /** Internet domain sockets for use with IPv4 addresses.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const AF_INET:int   = __socket.AF_INET;

    /** Internet domain sockets for use with IPv6 addresses.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const AF_INET6:int  = __socket.AF_INET6;

    /** Unspecified.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const AF_UNSPEC:int = __socket.AF_UNSPEC;


    /** Disables further receive operations.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const SHUT_RD:int   = __socket.SHUT_RD;

    /** Disables further send and receive operations.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const SHUT_RDWR:int = __socket.SHUT_RDWR;

    /** Disables further send operations.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const SHUT_WR:int   = __socket.SHUT_WR;


    /** Internet protocol.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const IPPROTO_IP:int   = __socket.IPPROTO_IP;

    /** Internet Protocol Version 6.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const IPPROTO_IPV6:int = __socket.IPPROTO_IPV6;

    /** Control message protocol.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const IPPROTO_ICMP:int = __socket.IPPROTO_ICMP;

    /** Raw IP Packets Protocol.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const IPPROTO_RAW:int  = __socket.IPPROTO_RAW;

    /** Transmission control protocol.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const IPPROTO_TCP:int  = __socket.IPPROTO_TCP;

    /** User datagram protocol.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const IPPROTO_UDP:int  = __socket.IPPROTO_UDP;


    /** The maximum backlog queue length.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const SOMAXCONN:int = __socket.SOMAXCONN;


    /**
     * Network host database function
     * which returns a list of hostnames or IP addresses by providing an IP address.
     * 
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public function gethostbyaddr( addr:String, numeric:Boolean = false ):Array
    {
        return __socket.__gethostbyaddr( addr, numeric );
    }

    /**
     * Network host database function
     * which returns a list of hostnames or IP addresses by providing a hostname.
     * 
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public function gethostbyname( hostname:String, numeric:Boolean = false ):Array
    {
        return __socket.__gethostbyname( hostname, numeric );
    }

    /**
     * Get the name of the peer socket.
     * 
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public function getpeername( descriptor:int ):String
    {
        return __socket.__getpeername( descriptor );
    }

    /**
     * Get the socket name.
     * 
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public function getsockname( descriptor:int ):String
    {
        return __socket.__getsockname( descriptor );
    }
    
}
