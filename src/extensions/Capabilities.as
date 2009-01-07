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
 * The Original Code is [Open Source Virtual Machine.].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2004-2006
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Zwetan Kjukov <zwetan@gmail>.
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

﻿package flash.system
{
    import avmplus.CompatibilityMode;
    import avmplus.System;
    import avmplus.redtamarin;
    
    /**
    * The Capabilities class provides properties that describe the system
    * and runtime that are hosting an ABC file.
    * 
    * note:
    * because redtamarin is intended to run only on the command-line
    * and will most unlikely have all the capacities of the Flash Player runtime
    * or the AIR runtime, we will hardcode some results and just try to be in sync
    * with the Flash Player API.
    * 
    * ex:
    * hasAudio() is always 'true' for Flash and AIR
    * but for redtamarin it will always be 'false' as
    * we have no sound codec support.
    * If at some point we implement some sound codecs (as OGG Vorbis)
    * then this can change.
    */
    [native(cls="CapabilitiesClass", methods="auto")]
    public final class Capabilities
    {
        private native static function __getOSname():String;
        private static var _OSname:String;
        
        private native static function __getLocale():String;
        private static var _locale:String;
        private static const UnknownLocale:String = "xu";
        
        /*public native static function __getInfos():String;*/
        
        public static function get avHardwareDisable():Boolean
        {
            return false;
        }
        
        public static function get hasAccessibility():Boolean
        {
            return false;
        }
        
        public static function get hasAudio():Boolean
        {
            return false;
        }
        
        public static function get hasAudioEncoder():Boolean
        {
            return false;
        }
        
        public static function get hasEmbeddedVideo():Boolean
        {
            return false;
        }
        
        /* note:
           that does not mean you could not input chinese
           or UTF-8 on the command-line, IME != command-line input.
        */
        public static function get hasIME():Boolean
        {
            return false;
        }
        
        public static function get hasMP3():Boolean
        {
            return false;
        }
        
        public static function get hasPrinting():Boolean
        {
            return false;
        }
        
        public static function get hasScreenBroadcast():Boolean
        {
            return false;
        }
        
        public static function get hasScreenPlayback():Boolean
        {
            return false;
        }
        
        public static function get hasStreamingAudio():Boolean
        {
            return false;
        }
        
        /* note:
           we could return 'true' here, once qe got
           the sockets implemented and openSSL
        */
        public static function get hasTLS():Boolean
        {
            return false;
        }
        
        public static function get hasVideoEncoder():Boolean
        {
            return false;
        }
        
        public static function get isDebugger():Boolean
        {
            return avmplus.System.isDebugger();
        }
        
        public static function get isEmbeddedInAcrobat():Boolean
        {
            return false;
        }
        
        /* note:
           by default we support only "en"/English,
           we should be able later to return different languages string
        */
        public static function get language():String
        {
            if( !_locale )
            {
                _locale = __getLocale();
            }
            
            if( _locale == "" )
            {
                return UnknownLocale;
            }
            
            return _locale.substr( 0, 2 );
        }
        
        public static function get languages():Array
        {
            if( !_locale )
            {
                _locale = __getLocale();
            }
            
            var locale:String;
            
            if( _locale == "" )
            {
                _locale = UnknownLocale;
                locale  = _locale;
            }
            else
            {
                locale  = _locale;
                
                if( locale.indexOf( "." ) > -1 )
                {
                    locale = _locale.split( "." )[0];
                }
                
                if( locale.indexOf( "@" ) > -1 )
                {
                    locale = _locale.split( "@" )[0];
                }
                
                locale = locale.split( "_" ).join( "-" );
            }
            
            return [ locale ];
        }
        
        /* note:
           we are an executable, we have full access to anything,
           no I/O, file access, etc. limitations of any kind.
        */
        public static function get localFileReadDisable():Boolean
        {
            return false;
        }
        
        /* note:
           either in the Flash Player or AIR it can returns 3 strings
           "Adobe Windows"
           "Adobe Macintosh"
           "Adobe Linux"
           
           as we're not Adobe we will return only
           "Windows"
           "Macintosh"
           "Linux"
           
           (a configuration could allow to change that,
           eg redtamarin.APImaxCompat = true, then we return "Adobe Macintosh")
        */
        public static function get manufacturer():String
        {
            if( !_OSname )
            {
                _OSname = __getOSname();
            }
            
            var name:String;
            
            if( redtamarin.compatibility == CompatibilityMode.flashPlayer )
            {
                name = "Adobe " + _OSname;
            }
            else
            {
                name = _OSname;
            }
            
            return name;
        }
        
        public static function get maxLevelIDC():String
        {
            return "";
        }
        
        /* note:
           not supported yet, but later it would be nice
           to be able to send a full OS signature.
        */
        public static function get os():String
        {
            if( !_OSname )
            {
                _OSname = __getOSname();
            }
            
            return _OSname;
        }
        
        public static function get pixelAspectRatio():Number
        {
            return 1;
        }
        
        /* note:
           same as the 'manufacturer' property
        */
        public static function get playerType():String
        {
            switch( redtamarin.compatibility )
            {
                case CompatibilityMode.flashPlayer:
                return "StandAlone";
                
                case CompatibilityMode.redtamarin:
                return "RedTamarin";
                
                case CompatibilityMode.tamarin:
                default:
                return "AVMPlus";
            }
        }
        
        /* note:
           let's consider a terminal screen having 2 colors only
        */
        public static function get screenColor():String
        {
            return "bw";
        }
        
        /* note:
           let's set on a common default of 72
        */
        public static function get screenDPI():Number
        {
            return 72;
        }
        
        public static function get screenResolutionX():Number
        {
            return 0;
        }
        
        public static function get screenResolutionY():Number
        {
            return 0;
        }
        
        /* note:
           return an empty string for now
           and yep we should implement it (not that important)
        */
        public static function get serverString():String
        {
            return "";
        }
        
        /* note:
           here too the redtamarin.APImaxCompat could be used
           to sync the major version with the flash player plugin
           or we could also use getAvmplusVersion() to sync with
           the Tamarin VM version ...
        */
        public static function get version():String
        {
            var str:String = "";
            var _os:String = "";
            var _version:String = "";
            
            switch( manufacturer )
            {
                case "Adobe Windows":
                case "Windows":
                _os = "WIN";
                break;
                
                case "Adobe Macintosh":
                case "Macintosh":
                _os = "MAC";
                break;
                
                case "Adobe Linux":
                case "Linux":
                _os = "UNIX";
                break;
            }
            
            /* note:
               from the flash player doc
               WIN 9,0,0,0  // Flash Player 9 for Windows
               MAC 7,0,25,0   // Flash Player 7 for Macintosh
               UNIX 5,0,55,0  // Flash Player 5 for UNIX
               
               for redtamarin we use the same format
               WIN 0,1,0,123 // redtamarin runtime 0.1 for Windows
               MAC 2,0,0,1024 // redtamarin runtime 2 for Macintosh
               UNIX 1,5,0,666 // redtamarin runtime 1.5 for UNIX
            */
            
            switch( redtamarin.compatibility )
            {
                case CompatibilityMode.flashPlayer:
                _version = "9,0,0,0";
                break;
                
                case CompatibilityMode.redtamarin:
                _version = redtamarin.version.split( "." ).join( "," );
                break;
                
                case CompatibilityMode.tamarin:
                default:
                var tmp:String = avmplus.System.getAvmplusVersion().split( " " )[0] + ".0.0";
                _version = tmp.split( "." ).join( "," );
            }
            
            str += _os + " " + _version;
            
            return str;
        }
        
    }
}


