/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package shell
{
    import C.unistd.*;
    import shell.Program;
    import shell.Runtime;
    import shell.FileSystem;

    /**
     * The OperatingSystem class provide informations about the Operating System.
     * 
     * <p>
     * TODO
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native(cls="::avmshell::OperatingSystemClass", methods="auto", construct="none")]
    public class OperatingSystem
    {

        /* Common */
        private static const EMPTY:String   = "";
        private static const UNKNOWN:String = "Unknown";
        
        private static var _name:String = "";
        private static var _version:String = "";

        private static var _hostname:String = "";
        private static var _username:String = "";

        private static var _vendor:String = "";
        private static var _vendorName:String = "";
        private static var _vendorVersion:String = "";
        private static var _vendorBuild:String = "";
        private static var _vendorDescription:String = "";

        private static var _codename:String = "";
        private static var _longDescription:String = "";


        /**
         * @internal
         * 
         * parse the result of a <code>regexp.exec()</code>
         * which kind of a bastard mix between array/object
         * and return a cleaner <code>Object</code>
         */
        private static function _parseRegExpResult( result:Object, findIndexes:Boolean = false ):Object
        {
            var o:Object = {};
            var a:Array  = [];
            var m:String;

            for( m in result )
            {
                switch( m )
                {
                    case "0":
                    case "1":
                    case "2":
                    case "3":
                    case "4":
                    case "5":
                    case "6":
                    case "7":
                    case "8":
                    case "9":
                    a[ parseInt(m) ] = result[ parseInt(m) ];
                    break;

                    case "input":
                    case "index":
                    // ignore
                    break;
                    
                    default:
                    o[ m ] = result[ m ];
                }
            }

            if( findIndexes && (a.length > 0) )
            {
                o._indexes = a;
            }

            return o;
        }

        /**
         * @internal
         * 
         * parse any raw string and search for
         * <code>major.minor.release.build</code>
         * returns a litteral version object
         */
        private static function _getVersionFrom( str:String ):Object
        {
            // version = major . minor . release . build
            //              mandatory        optional
            var re:RegExp = /\bv?(?P<major>[0-9]+)\.(?P<minor>[0-9]+)(?:\.(?P<release>[0-9]+))?(?:\.(?P<build>[0-9]+))?\b/;

            if( re.test( str ) )
            {
                var result:* = re.exec( str );
                
                if( result )
                {
                    var version:Object = _parseRegExpResult( result, false );
                    return version;
                }
            }

            return null;
        }

        /**
         * @internal
         * 
         * scan an <code>Array</code> and look into each index
         * properties to find the <code>value</code>
         * and if found returns the index Object
         * 
         * the <code>key</code> allow to specify the property to look into
         */
        private static function _findWithin( data:Array, value:String, key:String = "" ):Object
        {
            var i:uint;
            var len:uint = data.length;
            var o:Object;
            var m:String;

            for( i = 0; i < len; i++ )
            {
                o = data[i];
                for( m in o  )
                {
                    if( ((key != "") && (key == m)) || (key == "") )
                    {
                        if( value == o[m] )
                        {
                            return o;
                        }
                    }
                }
            }

            return null;
        }


        /* Windows */
        private static const MICROSOFT:String = "Microsoft";
        private static const NT:String        = "NT";

        /* Note:
           we don't use other const for Windows
           as we don't read/parse from a file
        */

        private static var _windows:Array = [];
                           _windows[ 0] = { name:"Windows 2000", build:"5.00", codename:UNKNOWN, description:"Windows 2000" }; // generic
                           _windows[ 1] = { name:"Windows 2000", build:"5.00.2195", codename:UNKNOWN, description:"Windows 2000" }; // Win 200 no codename
                           _windows[ 2] = { name:"Windows 2000", build:"5.0.2195", codename:"Janus", description:"Windows 2000 Professional" }; // considered as 64-bit so use codename
                           _windows[ 3] = { name:"Windows XP", build:"5.1", codename:"Whistler", description:"Windows XP" }; // generic
                           _windows[ 4] = { name:"Windows XP", build:"5.1.2600", codename:"Whistler", description:"Windows XP" };
                           _windows[ 5] = { name:"Windows XP", build:"5.2.3790", codename:"Whistler", description:"Windows XP Professional x64" };
                           _windows[ 6] = { name:"Windows Vista", build:"6.0", codename:"Longhorn", description:"Windows Vista" }; // generic
                           _windows[ 7] = { name:"Windows Vista", build:"6.0.6000", codename:"Longhorn", description:"Windows Vista" };
                           _windows[ 8] = { name:"Windows Vista", build:"6.0.6001", codename:"Longhorn", description:"Windows Vista SP1" };
                           _windows[ 9] = { name:"Windows Vista", build:"6.0.6002", codename:"Longhorn", description:"Windows Vista SP2" };
                           _windows[10] = { name:"Windows 7", build:"6.1", codename:"Blackcomb", description:"Windows 7" }; // generic
                           _windows[11] = { name:"Windows 7", build:"6.1.7600", codename:"Blackcomb", description:"Windows 7" };
                           _windows[12] = { name:"Windows 7", build:"6.1.7601", codename:"Blackcomb", description:"Windows 7 SP1" };
                           _windows[13] = { name:"Windows Home Server 2011", build:"6.1.8400", codename:"Vail", description:"Windows Home Server 2011" };
                           _windows[14] = { name:"Windows Server 2012", build:"6.2.8102", codename:"Windows Server 8", description:"Windows Server 2012" };
                           _windows[15] = { name:"Windows 8", build:"6.2", codename:"Midori", description:"Windows 8" }; // generic
                           _windows[16] = { name:"Windows 8", build:"6.2.9200", codename:"Midori", description:"Windows 8" };
                           _windows[17] = { name:"Windows 8.1", build:"6.3", codename:"Blue", description:"Windows 8.1" }; // generic
                           _windows[18] = { name:"Windows 8.1", build:"6.3.9200", codename:"Blue", description:"Windows 8.1" };
                           _windows[19] = { name:"Windows 8.1", build:"6.3.9600", codename:"Blue", description:"Windows 8.1 Update 1" };
                           _windows[20] = { name:"Windows 10", build:"6.4.9841", codename:"Threshold", description:"Windows 10 Technical Preview 1" };
                           _windows[21] = { name:"Windows 10", build:"6.4.9860", codename:"Threshold", description:"Windows 10 Technical Preview 2" };
                           _windows[22] = { name:"Windows 10", build:"6.4.9879", codename:"Threshold", description:"Windows 10 Technical Preview 3" };
                           _windows[23] = { name:"Windows 10", build:"10.0", codename:"Threshold", description:"Windows 10" }; // generic 2015
                           _windows[24] = { name:"Windows 10", build:"10.0.9926", codename:"Threshold", description:"Windows 10 Technical Preview 4" };
                           _windows[25] = { name:"Windows 10", build:"10.0.10041", codename:"Threshold", description:"Windows 10 Technical Preview 5" };
                           _windows[26] = { name:"Windows 10", build:"10.0.10049", codename:"Threshold", description:"Windows 10 Technical Preview 6" };
                           _windows[27] = { name:"Windows 10", build:"10.0.10166", codename:"Threshold", description:"Windows 10 Insider Preview" };
                           _windows[28] = { name:"Windows 10", build:"10.0.10240", codename:"Threshold", description:"Windows 10 RTM" };
                           _windows[29] = { name:"Windows 10", build:"10.0.10525", codename:"Threshold", description:"Windows 10 Insider Preview" };
                           _windows[30] = { name:"Windows 10", build:"10.0.10565", codename:"Threshold", description:"Windows 10 Insider Preview" };
                           _windows[31] = { name:"Windows 10", build:"10.0.10586", codename:"Threshold", description:"Windows 10 Fall Update" };
                           //_windows[ 0] = { name:"Windows 10", build:"", codename:"Redstone", description:"" }; // 2016 buulds have a new codename
                           //_windows[ 0] = { name:"Windows 10", build:"10.0", codename:"Redstone", description:"Windows 10" }; // generic 2016
                           

        private static var _windowsName:String = "";
        private static var _windowsVersion:String = "";

        private static var _windowsProductName:String = "";
        private static var _windowsReleaseVersion:String = "";
        private static var _windowsBuild:String = "";
        private static var _windowsDescription:String = "";
        private static var _windowsLongDescription:String = "";
        private static var _windowsCodename:String = "";


        /**
         * @internal
         * 
         * Entry point for the Windows detection
         */
        private static function _windowsDetect():void
        {
            _windowsParseVersion();
        }

        /**
         * @internal
         * 
         */
        private static function _windowsReadVerOutput():String
        {
            var data:String = Program.open( "ver" );
                data = data.split( "\r" ).join( "" );
                data = data.split( "\n" ).join( "" );

            return data;
        }

        /**
         * @internal
         * 
         */
        private static function _windowsParseVersion():void
        {
            var str:String = _windowsReadVerOutput();

            if( str && (str != EMPTY) )
            {
                var ver:Object = _getVersionFrom( str );

                if( ver )
                {
                    var version:String = ver.major + "." + ver.minor + "." + ver.release;
                    var shortVersion:String = ver.major + "." + ver.minor;

                    _windowsBuild = ver.release;

                    var o:Object = _findWithin(  _windows, version );

                    // not found, use a generic
                    if( o == null )
                    {
                        o = _findWithin(  _windows, shortVersion );
                        _windowsBuild = EMPTY;
                    }

                    if( o )
                    {
                        _windowsProductName = o.name;
                        _windowsName = _windowsProductName;

                        _windowsReleaseVersion = NT + " " + shortVersion;
                        _windowsVersion = shortVersion;

                        _windowsCodename = o.codename;

                        _windowsDescription  = MICROSOFT + " ";
                        _windowsDescription += o.description;

                        _windowsLongDescription = _windowsDescription;
                        _windowsLongDescription += " (";
                        if( _windowsCodename != "" )
                        {
                        _windowsLongDescription += _windowsCodename + " ";
                        }
                        _windowsLongDescription += shortVersion;
                        if( _windowsBuild != "" )
                        {
                        _windowsLongDescription += " build " + ver.release;
                        }
                        _windowsLongDescription += ")";
                    }
                }
            }

        }


        /* Mac OS X */
        private static const APPLE:String    = "Apple";
        private static const MAC_OS_X:String = "Mac OS X";

        private static const PRODUCT_NAME:String                 = "ProductName";
        private static const PRODUCT_BUILD_VERSION:String        = "ProductBuildVersion";
        private static const PRODUCT_VERSION:String              = "ProductVersion";
        private static const PRODUCT_USER_VISIBLE_VERSION:String = "ProductUserVisibleVersion";


        private static var _macintosh:Array = [];
                           _macintosh[ 0] = {  version:"10.1", darwin:"5.0.0", codename:"Puma" };
                           _macintosh[ 1] = {  version:"10.2", darwin:"6.0.0", codename:"Jaguar" };
                           _macintosh[ 2] = {  version:"10.3", darwin:"7.0.0", codename:"Panther" };
                           _macintosh[ 3] = {  version:"10.4", darwin:"8.0.0", codename:"Tiger" };
                           _macintosh[ 4] = {  version:"10.5", darwin:"9.0.0", codename:"Leopard" };
                           _macintosh[ 5] = {  version:"10.6", darwin:"10.0.0", codename:"Snow Leopard" };
                           _macintosh[ 6] = {  version:"10.7", darwin:"11.0.0", codename:"Lion" };
                           _macintosh[ 7] = {  version:"10.8", darwin:"12.0.0", codename:"Mountain Lion" };
                           _macintosh[ 8] = {  version:"10.9", darwin:"13.0.0", codename:"Mavericks" };
                           _macintosh[ 9] = {  version:"10.10", darwin:"14.0.0", codename:"Yosemite" };
                           _macintosh[10] = {  version:"10.11", darwin:"15.0.0", codename:"El Capitan" };


        private static var _macintoshName:String = "";
        private static var _macintoshVersion:String = "";

        private static var _macintoshProductName:String = "";
        private static var _macintoshProductBuildVersion:String = "";
        private static var _macintoshProductVersion:String = "";
        private static var _macintoshProductUserVisibleVersion:String = "";
        private static var _macintoshProductDescription:String = "";
        private static var _macintoshLongDescription:String = "";
        private static var _macintoshCodename:String = "";


        /**
         * @internal
         * 
         * Entry point for the Mac OS X detection
         */
        private static function _macintoshDetect():void
        {
            _macintoshParseSystemVersion();
        }

        /**
         * @internal
         * 
         */
        private static function _macintoshParseSystemVersionFile( file:String ):Object
        {
            var sysver:Object = null;

            if( FileSystem.exists( file ) )
            {
                var data:XML = new XML( FileSystem.read( file ) );

                if( data.name().localName == "plist" )
                {
                    var dict:XML = data.children()[0];
                    
                    if( dict.name().localName == "dict" )
                    {
                        sysver = {};
                        var children:XMLList = dict.children();
                        var i:uint;
                        var len:uint = children.children().length();
                        var count:uint;
                        for( i = 0, count = len; i < count; i += 2 )
                        {
                            var key:String   = String( children[i].text() );
                            var value:String = String( children[i+1].text() );
                            sysver[key] = value;
                        }
                    }
                }
                    
            }
            
            return sysver;
        }

        /**
         * @internal
         * 
         */
        private static function _macintoshParseSystemVersion():void
        {
            var file:String = "/System/Library/CoreServices/SystemVersion.plist";
            var data:Object = _macintoshParseSystemVersionFile( file );

            if( data )
            {

                if( PRODUCT_NAME in data )
                {
                    _macintoshProductName= data[ PRODUCT_NAME ];
                }

                if( PRODUCT_BUILD_VERSION in data )
                {
                    _macintoshProductBuildVersion = data[ PRODUCT_BUILD_VERSION ];
                }

                if( PRODUCT_VERSION in data )
                {
                    _macintoshProductVersion = data[ PRODUCT_VERSION ];
                }

                if( PRODUCT_USER_VISIBLE_VERSION in data )
                {
                    _macintoshProductUserVisibleVersion = data[ PRODUCT_USER_VISIBLE_VERSION ];
                }

                var v:Object = _getVersionFrom( _macintoshProductVersion );
                
                if( v )
                {
                    var shortVersion:String = v.major + "." + v.minor;
                    _macintoshName = _macintoshProductName + " " + shortVersion;
                    _macintoshVersion = shortVersion;

                    var o:Object = _findWithin(  _macintosh, shortVersion );

                    if( o )
                    {
                        _macintoshCodename = o.codename;

                        _macintoshProductDescription  = APPLE + " "
                        _macintoshProductDescription += _macintoshProductName + " " + _macintoshProductVersion;

                        _macintoshLongDescription  = _macintoshProductDescription;
                        _macintoshLongDescription += " (";
                        _macintoshLongDescription += _macintoshCodename;
                        _macintoshLongDescription += " build ";
                        _macintoshLongDescription += _macintoshProductBuildVersion;
                        _macintoshLongDescription += ")";
                    }
                    
                }

            }

        }


        /* Linux */
        private static const LINUX:String = "Linux";

        private static const DISTRIB_ID:String          = "DISTRIB_ID";
        private static const DISTRIB_RELEASE:String     = "DISTRIB_RELEASE";
        private static const DISTRIB_DESCRIPTION:String = "DISTRIB_DESCRIPTION";
        private static const DISTRIB_CODENAME:String    = "DISTRIB_CODENAME";


        private static var _linuxDistros:Array = [];
                           // supported
                           _linuxDistros[ 0] = { name: "Ubuntu",        files: [ "/etc/lsb-release" ] };
                           _linuxDistros[ 1] = { name: "Debian",        files: [ "/etc/debian_version", "/etc/debian_release" ] };
                           // untested
                           _linuxDistros[ 2] = { name: "CentOS",        files: [ "/etc/centos-release" ] };
                           _linuxDistros[ 3] = { name: "Red Hat",       files: [ "/etc/redhat-release", "/etc/redhat_version" ] };
                           _linuxDistros[ 4] = { name: "Gentoo",        files: [ "/etc/gentoo-release" ] };
                           _linuxDistros[ 5] = { name: "Slackware",     files: [ "/etc/slackware-version", "/etc/slackware-release" ] };
                           _linuxDistros[ 6] = { name: "Novell SUSE",   files: [ "/etc/SUSE-release" ] };
                           _linuxDistros[ 7] = { name: "SUSE",          files: [ "/etc/SuSE-release", "/etc/novell-release" ] };
                           _linuxDistros[ 8] = { name: "Arch",          files: [ "/etc/arch-release" ] };
                           _linuxDistros[ 9] = { name: "Fedora",        files: [ "/etc/fedora-release" ] };
                           _linuxDistros[10] = { name: "Mandrake",      files: [ "/etc/mandrake-release" ] };
                           _linuxDistros[11] = { name: "Yellow Dog",    files: [ "/etc/yellowdog-release" ] };
                           _linuxDistros[12] = { name: "UnitedLinux",   files: [ "/etc/UnitedLinux-release" ] };

        private static var _ubuntu:Array = [];
                           _ubuntu[ 0] = { version:"12.04", codename:"Precise Pangolin", short:"precise", lts:true };
                           _ubuntu[ 1] = { version:"12.10", codename:"Quantal Quetzal",  short:"quantal", lts:false };
                           _ubuntu[ 2] = { version:"13.04", codename:"Raring Ringtail",  short:"raring",  lts:false };
                           _ubuntu[ 3] = { version:"13.10", codename:"Saucy Salamander", short:"saucy",   lts:false };
                           _ubuntu[ 4] = { version:"14.04", codename:"Trusty Tahr",      short:"trusty",  lts:true };
                           _ubuntu[ 5] = { version:"14.10", codename:"Utopic Unicorn",   short:"utopic",  lts:false };
                           _ubuntu[ 6] = { version:"15.04", codename:"Vivid Vervet",     short:"vivid",   lts:false };
                           _ubuntu[ 7] = { version:"15.10", codename:"Wily Werewolf",    short:"wily",    lts:false };
                           _ubuntu[ 8] = { version:"16.04", codename:"Xenial Xerus",     short:"xenial",  lts:true };


        private static var _linuxName:String = "";
        private static var _linuxVersion:String = "";

        private static var _linuxVendorName:String = "";
        private static var _linuxVendorVersion:String = "";
        private static var _linuxVendorBuild:String = "";
        private static var _linuxVendorDescription:String = "";
        private static var _linuxLongDescription:String = "";
        private static var _linuxCodename:String = "";


        /**
         * @internal
         * 
         * Entry point for the Linux detection
         */
        private static function _linuxDetect():void
        {
            _linuxParseReleaseFile();
        }

        /**
         * @internal
         * 
         */
        private static function _linuxParseConfig( data:String ):Object
        {
            var lines:Array = data.split( "\n" );
            var i:uint;
            var len:uint = lines.length;
            var o:Object = {};
            var line:String;
            
            for( i = 0; i < len; i++ )
            {
                line = lines[i];
                if( line && (line != "") && (line.length > 0)  )
                {
                    var pos:int = line.indexOf( "=" );
                    var name:String = line.substr( 0, pos );
                    var value:String = line.substr( pos+1 );

                    if( value.charAt( 0 ) == "\"" )
                    {
                        value = value.substr( 1 );
                        value = value.substring( 0, value.length-1 );
                    }

                    o[ name ] = value;
                }
            }
            
            return o;
        }

        /**
         * @internal
         * 
         */
        private static function _linuxParseReleaseFile():void
        {
            var i:uint;
            var j:uint;
            var len:uint = _linuxDistros.length;
            var found:Boolean = false;
            var distro:Object;
            var distroName:String;
            var release:String;

            for( i = 0; !found && (i < len); i++ )
            {
                distro = _linuxDistros[i];
                distroName = distro.name.split( " " ).join( "" );
                _linuxName = distroName;
                
                for( j = 0; !found && (j < distro.files.length); j++ )
                {
                    release = distro.files[j];
                    if( FileSystem.exists( release ) )
                    {
                        var file:String = FileSystem.read( release );
                        var method:String = "_linuxParse" + distroName + "ReleaseFile";

                        if( OperatingSystem[ method ] )
                        {
                            OperatingSystem[ method ]( file, distro.name );
                            found = true;
                        }
                    }
                }
            }
        }

        /**
         * @internal
         * 
         */
        private static function _linuxParseUbuntuReleaseFile( file:String, name:String = "" ):void
        {
            var data:Object = _linuxParseConfig( file );
            var shortVersion:String;

            if( DISTRIB_ID in data )
            {
                _linuxVendorName = data[ DISTRIB_ID ];
            }

            if( DISTRIB_RELEASE in data )
            {
                _linuxVendorVersion = data[ DISTRIB_RELEASE ];
                shortVersion = _linuxVendorVersion;
            }

            /* Note:
               In general there is no build number under Linux
               so we need to define it as UNKNOWN
               to avoid _linuxDetect() to be called again and again
            */
            _linuxVendorBuild = UNKNOWN;

            if( DISTRIB_DESCRIPTION in data )
            {
                _linuxVendorDescription = LINUX + " " + data[ DISTRIB_DESCRIPTION ];

                var v:Object = _getVersionFrom( _linuxVendorDescription );
                
                if( v.release )
                {
                    shortVersion = _linuxVendorVersion;
                    _linuxVendorVersion = v.major + "." + v.minor + "." + v.release;
                }
            }

            if( DISTRIB_CODENAME in data )
            {
                _linuxCodename = data[ DISTRIB_CODENAME ];

                /* Note:
                   We could read and parse /etc/os-release
                   to get
                   VERSION="14.04.3 LTS, Trusty Tahr"
                   but we decided to go with a prefilled table
                   less complete but faster
                */
                var o:Object = _findWithin(  _ubuntu, _linuxCodename );

                if( o )
                {
                    _linuxCodename = o.codename;
                }
            }

            if( (_linuxVendorName != EMPTY) && (shortVersion != EMPTY) )
            {
                _linuxName = _linuxVendorName + " " + shortVersion;
                _linuxVersion = shortVersion;
            }

            if( _linuxVendorDescription != EMPTY )
            {
                _linuxLongDescription  = _linuxVendorDescription;
                _linuxLongDescription += " (";
                _linuxLongDescription += _linuxCodename;
                _linuxLongDescription += ")";
            }

        }


        /* shared */

        /**
         * @internal
         * 
         */
        private static function _getNameAll():String
        {
            var platform:String = Runtime.platform;

            switch( platform )
            {
                case "linux":
                if( _linuxName == EMPTY )
                {
                    _linuxName = UNKNOWN;
                    _linuxDetect();
                }

                return _linuxName;

                case "macintosh":
                if( _macintoshName == EMPTY )
                {
                    _macintoshName = UNKNOWN;
                    _macintoshDetect();
                }

                return _macintoshName;

                case "windows":
                if( _windowsName == EMPTY )
                {
                    _windowsName = UNKNOWN;
                    _windowsDetect();
                }

                return _windowsName;
            }

            return UNKNOWN;
        }

        /**
         * @internal
         * 
         */
        private static function _getVersionAll():String
        {
            var platform:String = Runtime.platform;

            switch( platform )
            {
                case "linux":
                if( _linuxVersion == EMPTY )
                {
                    _linuxVersion = UNKNOWN;
                    _linuxDetect();
                }

                return _linuxVersion;

                case "macintosh":
                if( _macintoshVersion == EMPTY )
                {
                    _macintoshVersion = UNKNOWN;
                    _macintoshDetect();
                }

                return _macintoshVersion;

                case "windows":
                if( _windowsVersion == "" )
                {
                    _windowsVersion = UNKNOWN;
                    _windowsDetect();
                }

                return _windowsVersion;
            }

            return UNKNOWN;
        }

        /**
         * @internal
         * 
         */
        private static function _getVendorAll():String
        {
            var platform:String = Runtime.platform;

            switch( platform )
            {
                case "linux":
                return LINUX;

                case "macintosh":
                return APPLE;

                case "windows":
                return MICROSOFT;
            }

            return UNKNOWN;
        }

        /**
         * @internal
         * 
         */
        private static function _getVendorNameAll():String
        {
            var platform:String = Runtime.platform;

            switch( platform )
            {
                case "linux":
                if( _linuxVendorName == EMPTY )
                {
                    _linuxVendorName = UNKNOWN;
                    _linuxDetect();
                }

                return _linuxVendorName;

                case "macintosh":
                return MAC_OS_X;
                
                case "windows":
                if( _windowsProductName == EMPTY )
                {
                    _windowsProductName = UNKNOWN;
                    _windowsDetect();
                }
                
                return _windowsProductName;
            }

            return UNKNOWN;
        }

        /**
         * @internal
         * 
         */
        private static function _getVendorVersionAll():String
        {
            var platform:String = Runtime.platform;

            switch( platform )
            {
                case "linux":
                if( _linuxVendorVersion == EMPTY )
                {
                    _linuxVendorVersion = UNKNOWN;
                    _linuxDetect();
                }

                return _linuxVendorVersion;

                case "macintosh":
                if( _macintoshProductVersion == EMPTY )
                {
                    _macintoshProductVersion = UNKNOWN;
                    _macintoshDetect();
                }

                return _macintoshProductVersion;
                
                case "windows":
                if( _windowsReleaseVersion == EMPTY )
                {
                    _windowsReleaseVersion = UNKNOWN;
                    _windowsDetect();
                }
                
                return _windowsReleaseVersion;
            }

            return UNKNOWN;
        }
        
        /**
         * @internal
         * 
         */
        private static function _getVendorBuildAll():String
        {
            var platform:String = Runtime.platform;

            switch( platform )
            {
                case "linux":
                if( _linuxVendorBuild == EMPTY )
                {
                    _linuxVendorBuild = UNKNOWN;
                    _linuxDetect();
                }

                return _linuxVendorBuild;
                
                case "macintosh":
                if( _macintoshProductBuildVersion == EMPTY )
                {
                    _macintoshProductBuildVersion = UNKNOWN;
                    _macintoshDetect();
                }

                return _macintoshProductBuildVersion;
                
                case "windows":
                if( _windowsBuild == EMPTY )
                {
                    _windowsBuild = UNKNOWN;
                    _windowsDetect();
                }

                return _windowsBuild;
            }

            return UNKNOWN;
        }

        /**
         * @internal
         * 
         */
        private static function _getVendorDescriptionAll():String
        {
            var platform:String = Runtime.platform;

            switch( platform )
            {
                case "linux":
                if( _linuxVendorDescription == EMPTY )
                {
                    _linuxVendorDescription = UNKNOWN;
                    _linuxDetect();
                }

                return _linuxVendorDescription;

                case "macintosh":
                if( _macintoshProductDescription == EMPTY )
                {
                    _macintoshProductDescription = UNKNOWN;
                    _macintoshDetect();
                }

                return _macintoshProductDescription;
                
                case "windows":
                if( _windowsDescription == EMPTY )
                {
                    _windowsDescription = UNKNOWN;
                    _windowsDetect();
                }
                
                return _windowsDescription;
            }

            return UNKNOWN;
        }

        /**
         * @internal
         * 
         */
        private static function _getCodenameAll():String
        {
            var platform:String = Runtime.platform;

            switch( platform )
            {
                case "linux":
                if( _linuxCodename == EMPTY )
                {
                    _linuxCodename = UNKNOWN;
                    _linuxDetect();
                }

                return _linuxCodename;

                case "macintosh":
                if( _macintoshCodename == EMPTY )
                {
                    _macintoshCodename = UNKNOWN;
                    _macintoshDetect();
                }

                return _macintoshCodename;
                
                case "windows":
                if( _windowsCodename == EMPTY )
                {
                    _windowsCodename = UNKNOWN;
                    _windowsDetect();
                }
                
                return _windowsCodename;
            }

            return UNKNOWN;
        }

        /**
         * @internal
         * 
         */
        private static function _getLongDescriptionAll():String
        {
            var platform:String = Runtime.platform;

            switch( platform )
            {
                case "linux":
                if( _linuxLongDescription == EMPTY )
                {
                    _linuxLongDescription = UNKNOWN;
                    _linuxDetect();
                }
                
                return _linuxLongDescription;
                
                case "macintosh":
                if( _macintoshLongDescription == EMPTY )
                {
                    _macintoshLongDescription = UNKNOWN;
                    _macintoshDetect();
                }
                
                return _macintoshLongDescription;
                
                case "windows":
                if( _windowsLongDescription == EMPTY )
                {
                    _windowsLongDescription = UNKNOWN;
                    _windowsDetect();
                }
                
                return _windowsLongDescription;
            }

            return UNKNOWN;
        }


        /**
         * Returns <code>true</code> is the program is a
         * Windows Store Apps.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        [Deprecated]
        public native static function isWindowsStore():Boolean;

        /**
         * The name of the Operating System.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4.1
         */
        public static function get name():String
        {
            if( _name != EMPTY ) { return _name; }

            _name = _getNameAll();
            return _name;
        }

        /**
         * The version of the Operating System.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4.1
         */
        public static function get version():String
        {
            if( _version != EMPTY ) { return _version; }

            _version = _getVersionAll();
            return _version;
        }

        /**
         * The host name of the local computer.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public static function get hostname():String
        {
            if( _hostname != EMPTY ) { return _hostname; }

            _hostname = gethostname();
            return _hostname;
        }

        /**
         * The current user name logged in the Operating System.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public static function get username():String
        {
            if( _username != EMPTY ) { return _username; }

            _username = getlogin();
            return _username;
        }

        /**
         * Name of the vendor (commercial)
         * or distributor (non-commercial) of the Operating System.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public static function get vendor():String
        {
            if( _vendor != EMPTY ) { return _vendor; }

            _vendor = _getVendorAll();
            return _vendor;
        }

        /**
         * The name of the Operating System
         * provided by the vendor/distributor.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4.1
         */
        public static function get vendorName():String
        {
            if( _vendorName != EMPTY ) { return _vendorName; }

            _vendorName = _getVendorNameAll();
            return _vendorName;
        }

        /**
         * The version of the Operating System
         * provided by the vendor/distributor.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4.1
         */
        public static function get vendorVersion():String
        {
            if( _vendorVersion != EMPTY ) { return _vendorVersion; }

            _vendorVersion = _getVendorVersionAll();
            return _vendorVersion;
        }

        /**
         * The build number or tag of the Operating System
         * provided by the vendor/distributor.
         * 
         * <p>
         * If the vendor does not provide a build number
         * it returns an empty string.
         * </p>
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4.1
         */
        public static function get vendorBuild():String
        {
            /* Note:
               EMPTY is an accepted value
            */
            if( _vendorBuild == EMPTY )
            {
                _vendorBuild = _getVendorBuildAll();
            }

            if( _vendorBuild == UNKNOWN ) { return EMPTY; }
            return _vendorBuild;
        }

        /**
         * The description of the Operating System
         * provided by the vendor/distributor
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4.1
         */
        public static function get vendorDescription():String
        {
            if( _vendorDescription != EMPTY ) { return _vendorDescription; }

            _vendorDescription = _getVendorDescriptionAll();
            return _vendorDescription;
        }

        /**
         * The codename of the Operating System.
         * 
         * <p>
         * If the vendor does not provide a codename
         * or if not found, it returns an empty string.
         * </p>
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4.1
         */
        public static function get codename():String
        {
            /* Note:
               EMPTY is an accepted value
            */
            if( _codename == EMPTY )
            {
                _codename = _getCodenameAll();
            }

            if( _codename == UNKNOWN ) { return EMPTY; }
            return _codename;
        }

        /**
         * The vendor description followed by the codename
         * and build number if they exists.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4.1
         */
        public static function get longDescription():String
        {
            if( _longDescription != EMPTY ) { return _longDescription; }

            _longDescription = _getLongDescriptionAll();
            return _longDescription;
        }

    }

}
