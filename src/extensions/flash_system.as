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

package flash.system
{
    import C.stdlib.getenv;
    
    import avmplus.CompatibilityMode;
    import avmplus.Domain;
    import avmplus.System;
    import avmplus.redtamarin;
    
    import flash.display.Loader;
    import flash.events.EventDispatcher;
    import flash.utils.ByteArray;
    
    public function fscommand(command:String, args:String = ""):void
    {
        
    }
    
    /* note:
       ideally we would want to implement this at the C/C++ level
       to be able to isolate domains,
       not sure it gonna happen, reasons:
       - we are one damn single exe, one app domain make sens here
       - we will not implement security (eg. we share everyhting in the exe)
    */
    public final class ApplicationDomain
    {
        private var _domain:Domain;
        
        public function ApplicationDomain( parentDomain:* = null )
        {
            _domain = new Domain( parentDomain );
        }
        
        public static function get currentDomain():ApplicationDomain
        {
            return new ApplicationDomain( Domain.currentDomain );
        }
        
        public static function get MIN_DOMAIN_MEMORY_LENGTH():uint
        {
            return Domain.MIN_DOMAIN_MEMORY_LENGTH;
        }
        
        public function get parentDomain():ApplicationDomain
        {
            return new ApplicationDomain( _domain );
        }
        
        public function get domainMemory():ByteArray
        {
            return _domain.domainMemory;
        }
        
        public function set domainMemory( value:ByteArray ):void
        {
            _domain.domainMemory = value;
        }
        
        public function getDefinition( name:String ):Object
        {
            return _domain.getClass( name ) as Object;
        }
        
        public function hasDefinition( name:String ):Boolean
        {
            var definition:Object = getDefinition( name );
            
            if( definition )
            {
                return true;
            }
            
            return false;
        }
        
    }
    
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
        
        private static function _getLocale():String
        {
            if( _locale )
            {
                return _locale;
            }
            
            /* note:
               We allow the user to override the system settings with
               environment variables.
            */
            var locale:String;
            
            locale = getenv( "LC_ALL" );
            
            if( locale == "" )
            {
                locale = getenv( "LANG" );
            }
            
            if( locale == "" )
            {
                locale = __getLocale();
            }
            
            /* note:
               if we can not found the locale
               we return the default "xu" for Other/unknown
            */
            if( locale == "" )
            {
                locale = UnknownLocale;
            }
            
            _locale = locale;
            
            return _locale;
        }
        
        /* note:
           by default we support only the language
           supported by the flash player
           see: http://livedocs.adobe.com/flex/3/langref/flash/system/Capabilities.html#language
        */
        public static function get language():String
        {
            var locale:String = _getLocale();
            
            return locale.substr( 0, 2 );
        }
        
        /* note:
           - if we can not find the country (or not supported)
             we will return only the language code
             ex: English Zimbabwe will return only "en"
           - the array will contain only the current locale
             ["en-GB","en-US"] will not happen
        */
        public static function get languages():Array
        {
            var locale:String = _getLocale();
            
            if( locale != UnknownLocale)
            {
                //ex: en-GB.UTF-8
                if( locale.indexOf( "." ) > -1 )
                {
                    locale = _locale.split( "." )[0];
                }
                
                //ex: es-ES@modern
                if( locale.indexOf( "@" ) > -1 )
                {
                    locale = _locale.split( "@" )[0];
                }
                
                //ex: en_US
                if( locale.indexOf( "_" ) > -1 )
                {
                    locale = locale.split( "_" ).join( "-" );
                }
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
    
    public final class IME extends EventDispatcher
    {
        
    }
    
    public final class IMEConversionMode
    {
        
    }
    
    public class LoaderContext
    {
        
    }
    
    public class JPEGLoaderContext extends LoaderContext
    {
        
    }
    
    public final class Security
    {
        
    }
    
    public class SecurityDomain
    {
        
    }
    
    /* note:
       if we implement security somehow
       here the panel could be a CLI
       with readline/writeline instead of a GUI
    */
    public final class SecurityPanel
    {
        
    }
    
    public final class System
    {
        public static function get ime():IME
        {
            return null;
        }
        
        public static function get totalMemory():uint
        {
            return avmplus.System.totalMemory;
        }
        
        /* TODO:
           check the string that AIR / FLash Player return
        */
        public static function get vmVersion():String
        {
            return avmplus.System.getAvmplusVersion();
        }
        
        public static function exit( code:uint ):void
        {
            avmplus.System.exit( code );
        }
        
        public static function gc():void
        {
            //do nothing;
        }
        
        public static function pause():void
        {
            //do nothing;
            //hint: use C.unistd.sleep
        }
        
        public static function resume():void
        {
            //do nothing;
        }
        
        public static function setClipboard(string:String):void
        {
            
        }
        
    }
    
    
}

