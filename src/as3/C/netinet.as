/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/**
* netinet/in.h - Internet address family
* 
* <p>
* <code>in</code> is a reserverd keyword so we declare
* <code>C.netinet</code> instead of
* <code>C.netinet.in</code>
* </p>
* 
* @langversion 3.0
* @playerversion AVM 0.4
* 
* @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/netinet_in.h.html
*/
package C.netinet
{

    //in_port_t - equivalent to the type uint16_t
    //in_addr_t - equivalent to the type uint32_t
    //sa_family_t - unsigned integer type

    /**
     * @internal
     */
    [native(cls="::avmshell::CNetinetInClass", methods="auto", construct="none")]
    [Inspectable(environment="none")]
    internal class __netinet
    {
        public native static function get IPPROTO_IP():int;
        public native static function get IPPROTO_IPV6():int;
        public native static function get IPPROTO_ICMP():int;
        public native static function get IPPROTO_RAW():int;
        public native static function get IPPROTO_TCP():int;
        public native static function get IPPROTO_UDP():int;

        public native static function get INADDR_ANY():int;
        public native static function get INADDR_BROADCAST():int;

        public native static function get INET_ADDRSTRLEN():int;
        public native static function get INET6_ADDRSTRLEN():int;

        public native static function get IPV6_JOIN_GROUP():int;
        public native static function get IPV6_LEAVE_GROUP():int;
        public native static function get IPV6_MULTICAST_HOPS():int;
        public native static function get IPV6_MULTICAST_IF():int;
        public native static function get IPV6_MULTICAST_LOOP():int;
        public native static function get IPV6_UNICAST_HOPS():int;
        public native static function get IPV6_V6ONLY():int;

    }


    /**
     * Internet protocol.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IPPROTO_IP:int = __netinet.IPPROTO_IP;

    /**
     * Internet Protocol Version 6.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IPPROTO_IPV6:int = __netinet.IPPROTO_IPV6;

    /**
     * Control message protocol.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IPPROTO_ICMP:int = __netinet.IPPROTO_ICMP;

    /**
     * Raw IP Packets Protocol.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IPPROTO_RAW:int = __netinet.IPPROTO_RAW;

    /**
     * Transmission control protocol.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IPPROTO_TCP:int = __netinet.IPPROTO_TCP;

    /**
     * User datagram protocol.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IPPROTO_UDP:int = __netinet.IPPROTO_UDP;


    /**
     * IPv4 local host address.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const INADDR_ANY:int = __netinet.INADDR_ANY;

    /**
     * IPv4 broadcast address.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const INADDR_BROADCAST:int = __netinet.INADDR_BROADCAST;


    /**
     * Length of the string form for IP (16).
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const INET_ADDRSTRLEN:int = __netinet.INET_ADDRSTRLEN;

    /**
     * Length of the string form for IPv6 (46).
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const INET6_ADDRSTRLEN:int = __netinet.INET6_ADDRSTRLEN;


    /**
     * Join a multicast group.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IPV6_JOIN_GROUP:int = __netinet.IPV6_JOIN_GROUP;

    /**
     * Quit a multicast group.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IPV6_LEAVE_GROUP:int = __netinet.IPV6_LEAVE_GROUP;

    /**
     * Multicast hop limit.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IPV6_MULTICAST_HOPS:int = __netinet.IPV6_MULTICAST_HOPS;

    /**
     * Interface to use for outgoing multicast packets.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IPV6_MULTICAST_IF:int = __netinet.IPV6_MULTICAST_IF;

    /**
     * Multicast packets are delivered back to the local application.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IPV6_MULTICAST_LOOP:int = __netinet.IPV6_MULTICAST_LOOP;

    /**
     * Unicast hop limit.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IPV6_UNICAST_HOPS:int = __netinet.IPV6_UNICAST_HOPS;

    /**
     * Restrict AF_INET6 socket to IPv6 communications only.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IPV6_V6ONLY:int = __netinet.IPV6_V6ONLY;


    /**
     * The wildcard IPv6 address.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const in6addr_any:in6_addr = new in6_addr();


    /**
     * The loopback IPv6 address.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const in6addr_loopback:in6_addr = new in6_addr();


    /**
     * A structure containing information about an internet address.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public class in_addr
    {
        public var s_addr:uint;
    }

    /**
     * A structure containing information about an internet address family.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public class sockaddr_in
    {
        /**
         * AF_INET.
         */
        public var sin_family:uint;

        /**
         * Port number.
         */
        public var sin_port:uint;

        /**
         * IP address.
         */
        public var sin_addr:in_addr;
    }

    /**
     * A structure containing information about an internet address v6.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public class in6_addr
    {
        public var s6_addr:Vector.<uint>;
    }

    /**
     * A structure containing information about an internet address family v6.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public class sockaddr_in6
    {
        /**
         * AF_INET6.
         */
        public var sin6_family:uint;

        /**
         * Port number.
         */
        public var sin6_port:uint;

        /**
         * IPv6 traffic class and flow information.
         */
        public var sin6_flowinfo:uint;

        /**
         * IPv6 address.
         */
        public var sin6_addr:in6_addr;

        /**
         * Set of interfaces for a scope.
         */
        public var sin6_scope_id:uint;
    }

    /**
     * A structure containing information about an internet multicast request v6.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public class ipv6_mreq
    {
        /**
         * IPv6 multicast address.
         */
        public var ipv6mr_multiaddr:in6_addr;

        /**
         * Interface index.
         */
        public var ipv6mr_interface:uint;
    }
}