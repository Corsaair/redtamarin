/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/**
* netdb.h - definitions for network database operations
* 
* @langversion 3.0
* @playerversion AVM 0.4
* 
* @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/netdb.h.html
*/
package C.netdb
{

    /**
     * @internal
     */
    [native(cls="::avmshell::CNetdbClass", methods="auto", construct="none")]
    [Inspectable(environment="none")]
    internal class __netdb
    {
        public native static function get AI_PASSIVE():int;
        public native static function get AI_CANONNAME():int;
        public native static function get AI_NUMERICHOST():int;
        public native static function get AI_NUMERICSERV():int;
        public native static function get AI_V4MAPPED():int;
        public native static function get AI_ALL():int;
        public native static function get AI_ADDRCONFIG():int;
    }


    /**
     * Socket address is intended for bind().
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const AI_PASSIVE:int = __netdb.AI_PASSIVE;

    /**
     * Request for canonical name.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const AI_CANONNAME:int = __netdb.AI_CANONNAME;

    /**
     * Return numeric host address as name.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const AI_NUMERICHOST:int = __netdb.AI_NUMERICHOST;

    /**
     * Inhibit service name resolution.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const AI_NUMERICSERV:int = __netdb.AI_NUMERICSERV;

    /**
     * If no IPv6 addresses are found,
     * query for IPv4 addresses and return them to the caller as IPv4-mapped IPv6 addresses.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const AI_V4MAPPED:int = __netdb.AI_V4MAPPED;

    /**
     * Query for both IPv4 and IPv6 addresses.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const AI_ALL:int = __netdb.AI_ALL;

    /**
     * Query for IPv4 addresses only when an IPv4 address is configured;
     * query for IPv6 addresses only when an IPv6 address is configured.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const AI_ADDRCONFIG:int = __netdb.AI_ADDRCONFIG;

    /**
     * Find a protocol by number.
     * 
     * <p>
     * The <code>getprotobynumber()</code> function shall search the database from the
     * beginning and find the first entry for which the protocol number specified by
     * <code>proto</code> matches the <code>p_proto</code> member,
     * opening and closing a connection to the database as necessary.
     * </p>
     * 
     * @example Usage
     * <listing>
     * 
     * 
     * </listing>
     * 
     * @param proto The protocol number.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * 
     * @see protoent
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/getprotobynumber.html
     */
    [native("::avmshell::CNetdbClass::getprotobynumber")]
    public native function getprotobynumber( proto:int ):protoent;

    /**
     * Find the next protocol entry.
     * 
     * <p>
     * The <code>getprotoent()</code> function shall read the next entry of the database,
     * opening and closing a connection to the database as necessary.
     * </p>
     * 
     * @example Usage
     * <listing>
     * 
     * 
     * </listing>
     * 
     * @param proto The protocol number.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * 
     * @see protoent
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/getprotobynumber.html
     */
    [native("::avmshell::CNetdbClass::getprotoent")]
    public native function getprotoent():protoent;

    /**
     * Find the next host entry.
     * 
     * <p>
     * The <code>gethostent()</code> function shall read the next entry in the database,
     * opening and closing a connection to the database as necessary.
     * </p>
     * 
     * @example Usage
     * <listing>
     * 
     * 
     * </listing>
     * 
     * @param proto The protocol number.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * 
     * @see protoent
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/gethostent.html
     */
    [native("::avmshell::CNetdbClass::gethostent")]
    public native function gethostent():hostent;


    /**
     * A structure containing information about an internet host.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native(cls="::avmshell::ChostentClass", instance="::avmshell::ChostentObject", methods="auto")]
    public class hostent
    {

        /**
         * Official name of the host.
         */
        public var h_name:String;

        /**
         * An array of alternative host names.
         */
        public var h_aliases:Array;

        /**
         * Address type.
         */
        public var h_addrtype:int;

        /**
         * The length, in bytes, of the address.
         */
        public var h_length:int;

        /**
         * An array of network addresses (in network byte order) for the host.
         */
        public var h_addr_list:Array;

        public function toString():String
        {
            var str:String = "";
                str += "name: " + h_name;

            if( h_aliases && (h_aliases.length > 0) )
            {
                str += ", aliases: " + h_aliases.join( ", " );
            }

            if( h_addr_list && (h_addr_list.length > 0) )
            {
                str += ", addresses: " + h_addr_list.join( ", " );
            }

            return str;
        }
    }

    public class netent
    {
        //TODO
    }

    /**
     * A structure containing information about an internet protocol.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native(cls="::avmshell::CprotoentClass", instance="::avmshell::CprotoentObject", methods="auto")]
    public class protoent
    {

        /**
         * Official name of the protocol.
         */
        public var p_name:String;

        /**
         * An array of alternative protocol names.
         */
        public var p_aliases:Array;

        /**
         * The protocol number.
         */
        public var p_proto:int;

        public function toString():String
        {
            var str:String = "";
                str += "[" + p_proto + "]";
                str += " name: " + p_name;

            if( p_aliases && (p_aliases.length > 0) )
            {
                str += ", aliases: " + p_aliases.join( ", " );
            }

            return  str;
        }
        
    }

    public class servent
    {
        //TODO
    }

    public class addrinfo
    {
        //TODO
    }

}
