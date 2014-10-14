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
    import C.netinet.*;
    import C.sys.socket.*;

    /**
     * @internal
     */
    [native(cls="::avmshell::CNetdbClass", methods="auto", construct="none")]
    [Inspectable(environment="none")]
    internal class __netdb
    {
        //addrinfo
        public native static function get AI_PASSIVE():int;
        public native static function get AI_CANONNAME():int;
        public native static function get AI_NUMERICHOST():int;
        public native static function get AI_NUMERICSERV():int;
        public native static function get AI_V4MAPPED():int;
        public native static function get AI_ALL():int;
        public native static function get AI_ADDRCONFIG():int;

        //getnameinfo()
        public native static function get NI_NOFQDN():int;
        public native static function get NI_NUMERICHOST():int;
        public native static function get NI_NAMEREQD():int;
        public native static function get NI_NUMERICSERV():int;
        public native static function get NI_NUMERICSCOPE():int;
        public native static function get NI_DGRAM():int;

        //getaddrinfo() and getnameinfo()
        public native static function get EAI_AGAIN():int;
        public native static function get EAI_BADFLAGS():int;
        public native static function get EAI_FAIL():int;
        public native static function get EAI_FAMILY():int;
        public native static function get EAI_MEMORY():int;
        public native static function get EAI_NONAME():int;
        public native static function get EAI_SERVICE():int;
        public native static function get EAI_SOCKTYPE():int;
        public native static function get EAI_SYSTEM():int;
        public native static function get EAI_OVERFLOW():int;

        public native static function gethostbyaddr4( addr:in_addr, type:int ):hostent;
        public native static function gethostbyaddr6( addr:in6_addr, type:int ):hostent;
    }


    /**
     * @private
     * error map so we can retrieve the const name from the const value.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [Inspectable(environment="none")]
    internal const __aierrmap:Object = {};

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
     * Only the nodename portion of the FQDN is returned for local hosts.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const NI_NOFQDN:int = __netdb.NI_NOFQDN;

    /**
     * The numeric form of the node's address is returned instead of its name.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const NI_NUMERICHOST:int = __netdb.NI_NUMERICHOST;

    /**
     * Return an error if the node's name cannot be located in the database.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const NI_NAMEREQD:int = __netdb.NI_NAMEREQD;

    /**
     * The numeric form of the service address is returned instead of its name.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const NI_NUMERICSERV:int = __netdb.NI_NUMERICSERV;

    /**
     * For IPv6 addresses, the numeric form of the scope identifier is returned instead of its name.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion POSIX +
     */
    public const NI_NUMERICSCOPE:int = __netdb.NI_NUMERICSCOPE;

    /**
     * Indicates that the service is a datagram service (SOCK_DGRAM).
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const NI_DGRAM:int = __netdb.NI_DGRAM;


    /**
     * The name could not be resolved at this time. Future attempts may succeed.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EAI_AGAIN:int = __netdb.EAI_AGAIN;
    __aierrmap[ EAI_AGAIN ] = "EAI_AGAIN";

    /**
     * The flags had an invalid value.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EAI_BADFLAGS:int = __netdb.EAI_BADFLAGS;
    __aierrmap[ EAI_BADFLAGS ] = "EAI_BADFLAGS";

    /**
     * A non-recoverable error occurred.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EAI_FAIL:int = __netdb.EAI_FAIL;
    __aierrmap[ EAI_FAIL ] = "EAI_FAIL";

    /**
     * The address family was not recognized or the address length was invalid for the specified family.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EAI_FAMILY:int = __netdb.EAI_FAMILY;
    __aierrmap[ EAI_FAMILY ] = "EAI_FAMILY";

    /**
     * There was a memory allocation failure.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EAI_MEMORY:int = __netdb.EAI_MEMORY;
    __aierrmap[ EAI_MEMORY ] = "EAI_MEMORY";

    /**
     * The name does not resolve for the supplied parameters.
     *
     * <p>
     * <code>NI_NAMEREQD</code> is set and the host's name cannot be located,
     * or both <code>nodename</code> and <code>servname</code> were null.
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EAI_NONAME:int = __netdb.EAI_NONAME;
    __aierrmap[ EAI_NONAME ] = "EAI_NONAME";

    /**
     * The service passed was not recognized for the specified socket type.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EAI_SERVICE:int = __netdb.EAI_SERVICE;
    __aierrmap[ EAI_SERVICE ] = "EAI_SERVICE";

    /**
     * The intended socket type was not recognized.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EAI_SOCKTYPE:int = __netdb.EAI_SOCKTYPE;
    __aierrmap[ EAI_SOCKTYPE ] = "EAI_SOCKTYPE";

    /**
     * A system error occurred. The error code can be found in <code>errno</code>.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion POSIX +
     */
    public const EAI_SYSTEM:int = __netdb.EAI_SYSTEM;
    __aierrmap[ EAI_SYSTEM ] = "EAI_SYSTEM";

    /**
     * An argument buffer overflowed.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion POSIX +
     */
    public const EAI_OVERFLOW:int = __netdb.EAI_OVERFLOW;
    __aierrmap[ EAI_OVERFLOW ] = "EAI_OVERFLOW";



    //endhostent()
    //endnetent()
    //endprotoent()
    //endservent()
    //freeaddrinfo() -- not needed

    /**
     * Address and name information error description.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/gai_strerror.html
     */
    [native("::avmshell::CNetdbClass::gai_strerror")]
    public native function gai_strerror( ecode:int ):String;

    /**
     * Find the next host entry.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     * 
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/getaddrinfo.html
     */
    [native("::avmshell::CNetdbClass::getaddrinfo")]
    public native function getaddrinfo( nodename:String, servname:String, hints:addrinfo = null, eaierr:CEAIrror = null ):Array;

    /**
     * hello.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * see: http://pubs.opengroup.org/onlinepubs/009695399/functions/gethostbyaddr.html
     */
    public function gethostbyaddr( addr:*, type:int ):hostent
    {
        if( type == AF_INET )
        {
            return __netdb.gethostbyaddr4( addr as in_addr, type );
        }
        else if( type == AF_INET6 )
        {
            return __netdb.gethostbyaddr6( addr as in6_addr, type );    
        }

        return null;
    }

    /**
     * hello.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * see: http://pubs.opengroup.org/onlinepubs/009695399/functions/gethostbyname.html
     */
    [native("::avmshell::CNetdbClass::gethostbyname")]
    public native function gethostbyname( name:String ):hostent;

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

    //getnameinfo()
    //getnetbyaddr()
    //getnetbyname()
    //getnetent()
    //getprotobyname()
    
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

    //getservbyname()
    //getservbyport()
    //getservent()
    //sethostent()
    //setnetent()
    //setprotoent()
    //setservent()






    /**
     * A structure containing information about an internet host.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native(cls="::avmshell::ChostentClass", instance="::avmshell::ChostentObject", methods="auto")]
    public class hostent
    {

        public function hostent( h_name:String = "",
                                 h_aliases:Array = null,
                                 h_addrtype:int = 0,
                                 h_length:int = 0,
                                 h_addr_list:Array = null ):void
        {
            if( !h_aliases )
            {
                h_aliases = [];
            }

            if( !h_addr_list )
            {
                h_addr_list = [];
            }

            this.h_name      = h_name;
            this.h_aliases   = h_aliases;
            this.h_addrtype  = h_addrtype;
            this.h_length    = h_length;
            this.h_addr_list = h_addr_list;
        }

        /**
         * Commonly defined alias for <code>h_addr_list[0]</code>
         */
        public function get h_addr():*
        {
            if( h_addr_list && (h_addr_list.length > 0) )
            {
                return h_addr_list[0];    
            }
            
            return null;
        }

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

    [native(cls="::avmshell::CaddrinfoClass", instance="::avmshell::CaddrinfoObject", methods="auto")]
    public class addrinfo
    {
        public function addrinfo( ai_flags:int = 0,
                                  ai_family:int = 0,
                                  ai_socktype:int = 0,
                                  ai_protocol:int = 0,
                                  ai_addrlen:uint = 0,
                                  ai_addr:* = null,
                                  ai_canonname:String = "" ):void
        {
            /*if( !ai_addr )
            {
                ai_addr = new sockaddr_in();
            }*/

            this.ai_flags     = ai_flags;
            this.ai_family    = ai_family;
            this.ai_socktype  = ai_socktype;
            this.ai_protocol  = ai_protocol;
            this.ai_addrlen   = ai_addrlen;
            this.ai_addr      = ai_addr;
            this.ai_canonname = ai_canonname;
        }

        /**
         * Input flags.
         */
        public var ai_flags:int;

        /**
         * Address family of socket.
         */
        public var ai_family:int;

        /**
         * Socket type.
         */
        public var ai_socktype:int;

        /**
         * Protocol of socket.
         */
        public var ai_protocol:int;

        /**
         * Length of socket address.
         */
        public var ai_addrlen:uint; //socklen_t

        /**
         * Socket address of socket.
         */
        public var ai_addr:*; //sockaddr_in or sockaddr_in6

        /**
         * Canonical name of service location.
         */
        public var ai_canonname:String;

        public function toString():String
        {
            var str:String = "";
                str += "{";
                str += "ai_flags:" + ai_flags;
                str += ", ai_family:" + ai_family;
                str += ", ai_socktype:" + ai_socktype;
                str += ", ai_protocol:" + ai_protocol;
                str += ", ai_addrlen:" + ai_addrlen;
                if( ai_addr )
                {
                str += ", ai_addr:" + ai_addr.toString();
                }
                str += ", ai_canonname:" + ai_canonname;
                str += "}";

            return str;
        }
    }

    /**
     * The CEAIrror exception allow to throws a C error as an Error object.
     *
     * ALternatively it can also be used to store an error passed into
     * a function argument.
     * 
     * @example basic usage
     * <code>
     * 
     * </code>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native(cls="::avmshell::CEAIrrorClass", instance="::avmshell::CEAIrrorObject", methods="auto")]
    public dynamic class CEAIrror extends Error
    {

        // E262 {ReadOnly, DontDelete, DontEnum }
        public static const length:int = 1;

        private var _errorID:int;
        prototype.name = "CEAIrror";
        
        public function CEAIrror( message = "", id = 0 )
        {
            super(message, id);
            this.name = prototype.name;

            this.apply( id );
        }

        public override function get errorID():int
        {
            return this._errorID;
        }

        [cppcall]
        public function apply( id:int = 0 ):void
        {
            this.message  = gai_strerror( id );
            this._errorID = id;

            if( __aierrmap[ id ] )
            {
                this.name = __aierrmap[ id ];
            }
            else
            {
                this.name = prototype.name;
            }
        }

        //CEAIrror: EAI_NONAME #8: nodename nor servname provided, or not known
        //CEAIrror #666
        public function toString():String
        {
            var e:Error = this;
            if( e.message !== "" )
            {
                return "CEAIrror: " + e.name + " #" + e.errorID + ": " + e.message
            }

            return e.name + " #" + e.id;
        }
    }

}
