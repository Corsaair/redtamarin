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


        /**
         * Returns <code>true</code> is the program is a
         * Windows Store Apps.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public native static function isWindowsStore():Boolean;


        /**
         * The host name of the local computer.
         * 
         * @productversion redtamarin 0.3
         * @since 0.3.0
         */
        public static function get hostname():String
        {
            if( _hostname ) { return _hostname; }

            _hostname = gethostname(); //C.unistd.gethostname()
            return _hostname;
        }

        /**
         * Name of the vendor (commercial) or distributor (non-commercial) of this OS.
         * 
         * @productversion redtamarin 0.3
         * @since 0.3.0
         */
        public static function get vendor():String
        {
            if( _vendor ) { return _vendor; }

            _vendor = _getVendorAll();
            return _vendor;
        }

    }

}
