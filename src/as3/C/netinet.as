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
    import C.arpa.inet.*;
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
        //getsockopt() and setsockopt()
        public native static function get IPPROTO_IP():int;
        public native static function get IPPROTO_IPV6():int;
        public native static function get IPPROTO_ICMP():int;
        public native static function get IPPROTO_RAW():int;
        public native static function get IPPROTO_TCP():int;
        public native static function get IPPROTO_UDP():int;

        //connect(), sendmsg(), and sendto()
        //public native static function get INADDR_ANY():int;
        //public native static function get INADDR_BROADCAST():int;

        public native static function get INET_ADDRSTRLEN():int;
        public native static function get INET6_ADDRSTRLEN():int;

        //getsockopt() and setsockopt()
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
    public const INADDR_ANY:uint = 0x00000000;
    //public const INADDR_ANY:int = __netinet.INADDR_ANY;

    /**
     * IPv4 broadcast address.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const INADDR_BROADCAST:uint = 0xffffffff;
    //public const INADDR_BROADCAST:int = __netinet.INADDR_BROADCAST;

    /**
     * .
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function IN_CLASSA( i:uint ):Boolean
    {
        return ((uint(i & 0x80000000)) == 0);
    }

    /**
     * .
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IN_CLASSA_NET:uint = 0xff000000;

    /**
     * .
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IN_CLASSA_NSHIFT:uint = 24;

    /**
     * .
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IN_CLASSA_HOST:uint = 0x00ffffff;

    /**
     * .
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IN_CLASSA_MAX:uint = 128;

    /**
     * .
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function IN_CLASSB( i:uint ):Boolean
    {
        return ((uint(i & 0xc0000000)) == 0x80000000);
    }

    /**
     * .
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IN_CLASSB_NET:uint = 0xffff0000;

    /**
     * .
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IN_CLASSB_NSHIFT:uint = 16;

    /**
     * .
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IN_CLASSB_HOST:uint = 0x0000ffff;

    /**
     * .
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IN_CLASSB_MAX:uint = 65536;

    /**
     * .
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function IN_CLASSC( i:uint ):Boolean
    {
        return ((uint(i & 0xe0000000)) == 0xc0000000);
    }

    /**
     * .
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IN_CLASSC_NET:uint = 0xffffff00;

    /**
     * .
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IN_CLASSC_NSHIFT:uint = 8;

    /**
     * .
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IN_CLASSC_HOST:uint = 0x000000ff;

    /**
     * .
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function IN_CLASSD( i:uint ):Boolean
    {
        return ((uint(i & 0xf0000000)) == 0xe0000000);
    }

    /**
     * .
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IN_CLASSD_NET:uint = 0xf0000000;

    /**
     * .
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IN_CLASSD_NSHIFT:uint = 28;

    /**
     * .
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IN_CLASSD_HOST:uint = 0x0fffffff;

    /**
     * .
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function IN_MULTICAST( i:uint ):Boolean
    {
        return IN_CLASSD( i );
    }

    /**
     * .
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function IN_EXPERIMENTAL( i:uint ):Boolean
    {
        return ((uint(i & 0xf0000000)) == 0xf0000000);
    }

    /**
     * .
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function IN_BADCLASS( i:uint ):Boolean
    {
        return ((uint(i & 0xf0000000)) == 0xf0000000);
    }

    /**
     * .
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const INADDR_LOOPBACK:uint = 0x7f000001;

    /**
     * -1 return.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const INADDR_NONE:uint = 0xffffffff;

    /**
     * 224.0.0.0.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const INADDR_UNSPEC_GROUP:uint = 0xe0000000;

    /**
     * 224.0.0.1.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const INADDR_ALLHOSTS_GROUP:uint = 0xe0000001;

    /**
     * 224.0.0.2.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const INADDR_ALLRTRS_GROUP:uint = 0xe0000002;

    /**
     * 224.0.0.22, IGMPv3.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const INADDR_ALLRPTS_GROUP:uint = 0xe0000016;

    /**
     * 224.0.0.18.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const INADDR_CARP_GROUP:uint = 0xe0000012;

    /**
     * 224.0.0.240.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const INADDR_PFSYNC_GROUP:uint = 0xe00000f0;

    /**
     * 224.0.0.251.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const INADDR_ALLMDNS_GROUP:uint = 0xe00000fb;

    /**
     * 224.0.0.255.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const INADDR_MAX_LOCAL_GROUP:uint = 0xe00000ff;

    /**
     * 169.254.0.0.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IN_LINKLOCALNETNUM:uint = 0xA9FE0000;

    /**
     * .
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function IN_LINKLOCAL( i:uint ):Boolean
    {
        return ((uint(i & IN_CLASSB_NET)) == IN_LINKLOCALNETNUM);
    }

    /**
     * .
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function IN_LOOPBACK( i:uint ):Boolean
    {
        return ((uint(i & 0xff000000)) == 0x7f000000);
    }

    /**
     * .
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function IN_ZERONET( i:uint ):Boolean
    {
        return ((uint(i & 0xff000000)) == 0);
    }

    /**
     * .
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function IN_PRIVATE( i:uint ):Boolean
    {
        return ((uint(i & 0xff000000)) == 0x0a000000) ||
               ((uint(i & 0xfff00000)) == 0xac100000) ||
               ((uint(i & 0xffff0000)) == 0xc0a80000);
    }

    /**
     * .
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function IN_LOCAL_GROUP( i:uint ):Boolean
    {
        return ((uint(i & 0xffffff00)) == 0xe0000000);
    }

    /**
     * .
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function IN_ANY_LOCAL( i:uint ):Boolean
    {
        return (IN_LINKLOCAL(i) || IN_LOCAL_GROUP(i));
    }

    /**
     * official!.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IN_LOOPBACKNET:uint = 127;


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
     * Constant to help build type <code>in6_addr</code>.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IN6ADDR_ANY_INIT:Vector.<uint> = new <uint>[ 0x00, 0x00, 0x00, 0x00,
                                                              0x00, 0x00, 0x00, 0x00,
                                                              0x00, 0x00, 0x00, 0x00,
                                                              0x00, 0x00, 0x00, 0x00 ];

    /**
     * Constant to help build type <code>in6_addr</code>.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IN6ADDR_LOOPBACK_INIT:Vector.<uint> = new <uint>[ 0x00, 0x00, 0x00, 0x00,
                                                                   0x00, 0x00, 0x00, 0x00,
                                                                   0x00, 0x00, 0x00, 0x00,
                                                                   0x00, 0x00, 0x00, 0x01 ];

    /**
     * Constant to help build type <code>in6_addr</code>.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IN6ADDR_NODELOCAL_ALLNODES_INIT:Vector.<uint> = new <uint>[ 0xff, 0x01, 0x00, 0x00,
                                                                             0x00, 0x00, 0x00, 0x00,
                                                                             0x00, 0x00, 0x00, 0x00,
                                                                             0x00, 0x00, 0x00, 0x01 ];

    /**
     * Constant to help build type <code>in6_addr</code>.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IN6ADDR_INTFACELOCAL_ALLNODES_INIT:Vector.<uint> = new <uint>[ 0xff, 0x01, 0x00, 0x00,
                                                                                0x00, 0x00, 0x00, 0x00,
                                                                                0x00, 0x00, 0x00, 0x00,
                                                                                0x00, 0x00, 0x00, 0x01 ];

    /**
     * Constant to help build type <code>in6_addr</code>.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IN6ADDR_LINKLOCAL_ALLNODES_INIT:Vector.<uint> = new <uint>[ 0xff, 0x02, 0x00, 0x00,
                                                                             0x00, 0x00, 0x00, 0x00,
                                                                             0x00, 0x00, 0x00, 0x00,
                                                                             0x00, 0x00, 0x00, 0x01 ];

    /**
     * Constant to help build type <code>in6_addr</code>.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IN6ADDR_LINKLOCAL_ALLROUTERS_INIT:Vector.<uint> = new <uint>[ 0xff, 0x02, 0x00, 0x00,
                                                                               0x00, 0x00, 0x00, 0x00,
                                                                               0x00, 0x00, 0x00, 0x00,
                                                                               0x00, 0x00, 0x00, 0x02 ];

    /**
     * Constant to help build type <code>in6_addr</code>.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IN6ADDR_LINKLOCAL_ALLV2ROUTERS_INIT:Vector.<uint> = new <uint>[ 0xff, 0x02, 0x00, 0x00,
                                                                                 0x00, 0x00, 0x00, 0x00,
                                                                                 0x00, 0x00, 0x00, 0x00,
                                                                                 0x00, 0x00, 0x00, 0x16 ];

    /**
     * Constant to help build type <code>in6_addr</code>.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const IN6ADDR_V4MAPPED_INIT:Vector.<uint> = new <uint>[ 0x00, 0x00, 0x00, 0x00,
                                                                   0x00, 0x00, 0x00, 0x00,
                                                                   0x00, 0x00, 0xff, 0xff,
                                                                   0x00, 0x00, 0x00, 0x00 ];



    /**
     * The wildcard IPv6 address.
     *
     * <p>
     * This variable is initialized by the system to contain the wildcard IPv6 address.
     * The <code>netinet</code> package also defines the <code>IN6ADDR_ANY_INIT</code> macro.
     * This macro must be constant at compile time and can be used to initialize a variable of
     * type <code>in6_addr</code> to the IPv6 wildcard address.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const in6addr_any:in6_addr = new in6_addr( IN6ADDR_ANY_INIT );

    /**
     * The loopback IPv6 address.
     *
     * <p>
     * This variable is initialized by the system to contain the loopback IPv6 address.
     * The <code>netinet</code> package also defines the <code>IN6ADDR_LOOPBACK_INIT</code> macro.
     * This macro must be constant at compile time and can be used to initialize a variable of
     * type <code>in6_addr</code> to the IPv6 loopback address.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const in6addr_loopback:in6_addr = new in6_addr( IN6ADDR_LOOPBACK_INIT );

    /**
     * The nodelocal all nodes IPv6 address.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const in6addr_nodelocal_allnodes:in6_addr = new in6_addr( IN6ADDR_NODELOCAL_ALLNODES_INIT );

    /**
     * The linklocal all nodes IPv6 address.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const in6addr_linklocal_allnodes:in6_addr = new in6_addr( IN6ADDR_LINKLOCAL_ALLNODES_INIT );

    /**
     * The linklocal all routers IPv6 address.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const in6addr_linklocal_allrouters:in6_addr = new in6_addr( IN6ADDR_LINKLOCAL_ALLROUTERS_INIT );

    /**
     * The linklocal all v2 routers IPv6 address.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const in6addr_linklocal_allv2routers:in6_addr = new in6_addr( IN6ADDR_LINKLOCAL_ALLV2ROUTERS_INIT );



    /**
     * @private
     * util function to pack uint8 to uint32
     *
     * eg. 0x01, 0x02, 0x03, 0x04
     *  to 0x01020304
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [Inspectable(environment="none")]
    internal function pack4( v:Vector.<uint>, i:uint ):uint
    {
        var a:uint = v[i];
        var b:uint = v[i+1];
        var c:uint = v[i+2];
        var d:uint = v[i+3];
        return ((a << 24) | (b << 16) | (c << 8) | d);
    }

    /**
     * Unspecified address.
     *
     * <p>
     * Macro that test for special IPv6 address.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function IN6_IS_ADDR_UNSPECIFIED( a:in6_addr ):Boolean
    {
        return (pack4(a.s6_addr,0) == 0) &&
               (pack4(a.s6_addr,4) == 0) &&
               (pack4(a.s6_addr,8) == 0) &&
               (pack4(a.s6_addr,12) == 0);
    }

    /**
     * Loopback address.
     *
     * <p>
     * Macro that test for special IPv6 address.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function IN6_IS_ADDR_LOOPBACK( a:in6_addr ):Boolean
    {
        return (pack4(a.s6_addr,0) == 0) &&
               (pack4(a.s6_addr,4) == 0) &&
               (pack4(a.s6_addr,8) == 0) &&
               (pack4(a.s6_addr,12) == ntohl(1));
    }

    /**
     * Multicast address.
     *
     * <p>
     * Macro that test for special IPv6 address.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function IN6_IS_ADDR_MULTICAST( a:in6_addr ):Boolean
    {
        return (a.s6_addr[0] == 0xff);
    }

    /**
     * Unicast link-local address.
     *
     * <p>
     * Macro that test for special IPv6 address.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function IN6_IS_ADDR_LINKLOCAL( a:in6_addr ):Boolean
    {
        return (a.s6_addr[0] == 0xfe) &&
               ((a.s6_addr[1] & 0xc0) == 0x80);
    }

    /**
     * Unicast site-local address.
     *
     * <p>
     * Macro that test for special IPv6 address.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function IN6_IS_ADDR_SITELOCAL( a:in6_addr ):Boolean
    {
        return (a.s6_addr[0] == 0xfe) &&
               ((a.s6_addr[1] & 0xc0) == 0xc0);
    }

    /**
     * IPv4 mapped address.
     *
     * <p>
     * Macro that test for special IPv6 address.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function IN6_IS_ADDR_V4MAPPED( a:in6_addr ):Boolean
    {
        return (pack4(a.s6_addr,0) == 0) &&
               (pack4(a.s6_addr,4) == 0) &&
               (pack4(a.s6_addr,8) == ntohl(0x0000ffff));
    }

    /**
     * IPv4-compatible address.
     *
     * <p>
     * Macro that test for special IPv6 address.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function IN6_IS_ADDR_V4COMPAT( a:in6_addr ):Boolean
    {
        return (pack4(a.s6_addr,0) == 0) &&
               (pack4(a.s6_addr,4) == 0) &&
               (pack4(a.s6_addr,8) == 0) &&
               (pack4(a.s6_addr,12) != 0) &&
               (pack4(a.s6_addr,12) != ntohl(1));
    }

    /**
     * Unique Local IPv6 Unicast Addresses (per RFC 4193).
     *
     * <p>
     * Macro that test for special IPv6 address.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function IN6_IS_ADDR_UNIQUE_LOCAL( a:in6_addr ):Boolean
    {
        return (a.s6_addr[0] == 0xfc) ||
               (a.s6_addr[0] == 0xfd);
    }

    /**
     * @private
     * util const used for macros
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [Inspectable(environment="none")]
    public const __IPV6_ADDR_SCOPE_NODELOCAL:uint = 0x01;

    /**
     * @private
     * util const used for macros
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [Inspectable(environment="none")]
    public const __IPV6_ADDR_SCOPE_INTFACELOCAL:uint = 0x01;

    /**
     * @private
     * util const used for macros
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [Inspectable(environment="none")]
    public const __IPV6_ADDR_SCOPE_LINKLOCAL:uint = 0x02;

    /**
     * @private
     * util const used for macros
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [Inspectable(environment="none")]
    public const __IPV6_ADDR_SCOPE_SITELOCAL:uint = 0x05;

    /**
     * @private
     * util const used for macros
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [Inspectable(environment="none")]
    public const __IPV6_ADDR_SCOPE_ORGLOCAL:uint = 0x08;

    /**
     * @private
     * util const used for macros
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [Inspectable(environment="none")]
    public const __IPV6_ADDR_SCOPE_GLOBAL:uint = 0x0e;

    /**
     * @private
     * multicast macro helper
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [Inspectable(environment="none")]
    public function __IPV6_ADDR_MC_SCOPE( a:in6_addr ):uint
    {
        return (a.s6_addr[1] & 0x0f);
    }

    /**
     * Multicast node-local address.
     *
     * <p>
     * Macro that test for special IPv6 address.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function IN6_IS_ADDR_MC_NODELOCAL( a:in6_addr ):Boolean
    {
        return (IN6_IS_ADDR_MULTICAST(a) &&
               (__IPV6_ADDR_MC_SCOPE(a) == __IPV6_ADDR_SCOPE_NODELOCAL));
    }

    /**
     * Multicast link-local address.
     *
     * <p>
     * Macro that test for special IPv6 address.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function IN6_IS_ADDR_MC_LINKLOCAL( a:in6_addr ):Boolean
    {
        return (IN6_IS_ADDR_MULTICAST(a) &&
               (__IPV6_ADDR_MC_SCOPE(a) == __IPV6_ADDR_SCOPE_LINKLOCAL));
    }

    /**
     * Multicast site-local address.
     *
     * <p>
     * Macro that test for special IPv6 address.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function IN6_IS_ADDR_MC_SITELOCAL( a:in6_addr ):Boolean
    {
        return (IN6_IS_ADDR_MULTICAST(a) &&
               (__IPV6_ADDR_MC_SCOPE(a) == __IPV6_ADDR_SCOPE_SITELOCAL));
    }

    /**
     * Multicast organization-local address.
     *
     * <p>
     * Macro that test for special IPv6 address.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function IN6_IS_ADDR_MC_ORGLOCAL( a:in6_addr ):Boolean
    {
        return (IN6_IS_ADDR_MULTICAST(a) &&
               (__IPV6_ADDR_MC_SCOPE(a) == __IPV6_ADDR_SCOPE_ORGLOCAL));
    }

    /**
     * Multicast global address.
     *
     * <p>
     * Macro that test for special IPv6 address.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function IN6_IS_ADDR_MC_GLOBAL( a:in6_addr ):Boolean
    {
        return (IN6_IS_ADDR_MULTICAST(a) &&
               (__IPV6_ADDR_MC_SCOPE(a) == __IPV6_ADDR_SCOPE_GLOBAL));
    }



    /**
     * A structure containing information about an internet address.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native(cls="::avmshell::CIn_AddrClass", instance="::avmshell::CIn_AddrObject", methods="auto")]
    public class in_addr
    {
        public function in_addr( s_addr:uint = 0 ):void
        {
            this.s_addr = s_addr;
        }

        /**
         * an IPv4 binary address as 32bit uint.
         */
        public var s_addr:uint;

        private function _tohex( num:uint ):String
        {
            var hex:String = num.toString(16);
            
            while( hex.length < 8 )
            {
                hex = "0" + hex;
            }

            return "0x" + hex;
        }

        [cppcall]
        public function isValid():Boolean
        {
            if( s_addr === null )
            {
                return false;
            }

            if( s_addr > 0xffffffff )
            {
                return false;
            }

            return true;
        }

        public function toString():String
        {
            var str:String = "";
                str += "{";
                str += "s_addr:";
                str += _tohex( s_addr );
                str += "";
                str += "}";

            return str;
        }
    }

    /**
     * A structure containing information about an internet address family.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native(cls="::avmshell::CSockaddr_inClass", instance="::avmshell::CSockaddr_inObject", methods="auto")]
    public class sockaddr_in
    {

        public function sockaddr_in( sin_family:int = 0, sin_port:uint = 0, sin_addr:in_addr = null ):void
        {
            if( !sin_addr )
            {
                sin_addr = new in_addr();
            }

            this.sin_family = sin_family;
            this.sin_port   = sin_port;
            this.sin_addr   = sin_addr;
        }

        /**
         * AF_INET.
         */
        public var sin_family:int;

        /**
         * Port number.
         */
        public var sin_port:uint;

        /**
         * IP address.
         */
        public var sin_addr:in_addr;

        public function toString():String
        {
            var str:String = "";
                str += "{";
                str += "sin_family:" + sin_family;
                str += ", sin_port:" + sin_port;
                str += ", sin_addr:" + sin_addr.toString();
                str += "}";

            return str;
        }
    }

    /**
     * A structure containing information about an internet address v6.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native(cls="::avmshell::CIn6_AddrClass", instance="::avmshell::CIn6_AddrObject", methods="auto")]
    public class in6_addr
    {

        public static function fromArray( data:Array ):in6_addr
        {
            var in6addr:in6_addr = new in6_addr();

            for( var i:uint = 0; i < data.length; i++ )
            {
                in6addr.s6_addr[i] = data[i];
            }

            return in6addr;
        }

        public static function fromVarArgs( ... args ):in6_addr
        {
            var in6addr:in6_addr = new in6_addr();

            for( var i:uint = 0; i < args.length; i++ )
            {
                in6addr.s6_addr[i] = args[i];
            }

            return in6addr;
        }

        public function in6_addr( s6_addr:Vector.<uint> = null ):void
        {
            if( !s6_addr )
            {
                s6_addr = IN6ADDR_ANY_INIT;
                /*
                s6_addr = new <uint>[ 0x00, 0x00, 0x00, 0x00,
                                      0x00, 0x00, 0x00, 0x00,
                                      0x00, 0x00, 0x00, 0x00,
                                      0x00, 0x00, 0x00, 0x00 ];
                */
            }

            this.s6_addr = s6_addr;
        }

        /**
         * an IPv6 binary address as a Vector of 16 8bit uint.
         */
        public var s6_addr:Vector.<uint>;

        private function _tohex( num:uint ):String
        {
            var hex:String = num.toString(16);

            while( hex.length < 2 )
            {
                hex = "0" + hex;
            }

            return "0x" + hex;
        }

        [cppcall]
        public function isValid():Boolean
        {
            if( s6_addr === null )
            {
                return false;
            }

            if( s6_addr.length != 16 )
            {
                return false;
            }

            var value:uint;
            for( var i:uint = 0; i < s6_addr.length; i++ )
            {
                value = s6_addr[i];
                if( value > 0xffff )
                {
                    return false;
                }
            }

            return true;
        }

        public function toString():String
        {
            var str:String = "";
                str += "{";
                str += "s6_addr:[";

                var arr:Array = [];
                for( var i:uint = 0; i < s6_addr.length; i++ )
                {
                    arr.push( _tohex( s6_addr[i] ) );
                }

                str += arr.join( "," );
                str += "]";
                str += "}";

            return str;
        }
    }

    /**
     * A structure containing information about an internet address family v6.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native(cls="::avmshell::CSockaddr_in6Class", instance="::avmshell::CSockaddr_in6Object", methods="auto")]
    public class sockaddr_in6
    {

        public function sockaddr_in6( sin6_family:uint = 0,
                                      sin6_port:uint = 0,
                                      sin6_flowinfo:uint = 0,
                                      sin6_addr:in6_addr = null,
                                      sin6_scope_id:uint = 0 ):void
        {
            if( !sin6_addr )
            {
                sin6_addr = new in6_addr();
            }

            this.sin6_family   = sin6_family;
            this.sin6_port     = sin6_port;
            this.sin6_flowinfo = sin6_flowinfo;
            this.sin6_addr     = sin6_addr;
            this.sin6_scope_id = sin6_scope_id;
        }

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

        public function toString():String
        {
            var str:String = "";
                str += "{";
                str += "sin6_family:" + sin6_family;
                str += ", sin6_port:" + sin6_port;
                str += ", sin6_flowinfo:" + sin6_flowinfo;
                str += ", sin6_addr:" + sin6_addr.toString();
                str += ", sin6_scope_id:" + sin6_scope_id;
                str += "}";

            return str;
        }
    }

    //not supported/used yet
    /**
     * A structure containing information about an internet multicast request v6.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public class ipv6_mreq
    {

        public function ipv6_mreq( ipv6mr_multiaddr:in6_addr = null,
                                   ipv6mr_interface:uint = 0 ):void
        {
            if( !ipv6mr_multiaddr )
            {
                ipv6mr_multiaddr = new in6_addr();
            }

            this.ipv6mr_multiaddr = ipv6mr_multiaddr;
            this.ipv6mr_interface = ipv6mr_interface;
        }


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