/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package C.arpa.inet
{
    import C.netinet.*;
    import C.sys.socket.*;

    /**
     * @name <code>&lt;arpa/inet.h&gt;</code>
     * Definitions for internet operations.
     *
     * <p>
     * Functions for manipulating numeric IP addresses.
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/arpa_inet.h.html arpa/inet.h
     */

    /** @internal */
    [native(cls="::avmshell::CArpaInetClass", methods="auto", construct="none")]
    [Inspectable(environment="none")]
    internal class __inet
    {
        public native static function _htonl( hostlong:uint ):uint;
        public native static function _htons( hostshort:uint ):uint;
        public native static function _ntohl( netlong:uint ):uint;
        public native static function _ntohs( netshort:uint ):uint;

        public native static function _inet_addr( cp:String ):uint;
        public native static function _inet_network( cp:String ):uint;
        public native static function _inet_ntoa( inaddr:in_addr ):String;
        public native static function _inet_aton( cp:String, inp:in_addr ):int;
        public native static function _inet_ntop4( af:int, src:sockaddr_in ):String;
        public native static function _inet_ntop6( af:int, src:sockaddr_in6 ):String;
        public native static function _inet_pton4( af:int, src:String, dst:sockaddr_in ):int;
        public native static function _inet_pton6( af:int, src:String, dst:sockaddr_in6 ):int;
    }

    /**
     * Convert values between host and network byte order.
     *
     * <p>
     * host to network long
     * </p>
     *
     * <p>
     * TODO
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function htonl( hostlong:uint ):uint
    {
        return __inet._htonl( hostlong );
    }

    /**
     * Convert values between host and network byte order.
     *
     * <p>
     * host to network short
     * </p>
     *
     * <p>
     * TODO
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function htons( hostshort:uint ):uint
    {
        /* TODO:
           throw RangeError on > uint16
        */
        return __inet._htons( hostshort );
    }

    /**
     * Convert values between host and network byte order.
     *
     * <p>
     * network to host long
     * </p>
     *
     * <p>
     * TODO
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function ntohl( netlong:uint ):uint
    {
        return __inet._ntohl( netlong );
    }

    /**
     * Convert values between host and network byte order.
     *
     * <p>
     * network to host short
     * </p>
     *
     * <p>
     * TODO
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function ntohs( netshort:uint ):int
    {
        /* TODO:
           throw RangeError on > uint16
        */
        return __inet._ntohs( netshort );
    }


    /**
     * Convert a string in the standard IPv4 dotted decimal notation
     * to an integer value suitable for use as an Internet address.
     *
     * <p>
     * TODO
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function inet_addr( cp:String ):uint
    {
        return __inet._inet_addr( cp );
    }

    /**
     * Equivalent to <code>inet_addr</code>.
     * 
     * <p>
     * TODO
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function inet_network( cp:String ):uint
    {
        return __inet._inet_network( cp );
    }

    /**
     * Convert an IPv4 address <code>in_addr</code>
     * to a string in the Internet standard dot notation.
     *
     * <p>
     * TODO
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function inet_ntoa( inaddr:in_addr ):String
    {
        return __inet._inet_ntoa( inaddr );
    }
    
    /**
     * Convert a string in the Internet standard dot notation
     * to an IPv4 address <code>in_addr</code>.
     *
     * <p>
     * TODO
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function inet_aton( cp:String, inp:in_addr ):int
    {
        return __inet._inet_aton( cp, inp );
    }

    /**
     * Convert IPv4 and IPv6 addresses from binary to text form.
     *
     * <p>
     * TODO
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function inet_ntop( af:int, src:* ):String
    {
        if( af == AF_INET )
        {
            return __inet._inet_ntop4( af, src as sockaddr_in );
        }
        else if( af == AF_INET6 )
        {
            return __inet._inet_ntop6( af, src as sockaddr_in6 );    
        }
        
        return null;
    }

    /**
     * Convert IPv4 and IPv6 addresses from text form to binary.
     *
     * <p>
     * TODO
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function inet_pton( af:int, src:String, dst:* ):int
    {
        if( af == AF_INET )
        {
            return __inet._inet_pton4( af, src, dst as sockaddr_in );
        }
        else if( af == AF_INET6 )
        {
            return __inet._inet_pton6( af, src, dst as sockaddr_in6 );
        }

        return 0;
    }

}
