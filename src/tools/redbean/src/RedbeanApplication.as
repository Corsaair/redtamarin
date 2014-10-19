/*
Version: MPL 1.1/GPL 2.0/LGPL 2.1

The contents of this file are subject to the Mozilla Public License Version
1.1 (the "License"); you may not use this file except in compliance with
the License. You may obtain a copy of the License at
http://www.mozilla.org/MPL/

Software distributed under the License is distributed on an "AS IS" basis,
WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
for the specific language governing rights and limitations under the
License.

The Original Code is [redbean].

The Initial Developers of the Original Code are
Zwetan Kjukov <zwetan@gmail.com>.
Portions created by the Initial Developers are Copyright (C) 2014
the Initial Developers. All Rights Reserved.

Contributor(s):

Alternatively, the contents of this file may be used under the terms of
either the GNU General Public License Version 2 or later (the "GPL"), or
the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
in which case the provisions of the GPL or the LGPL are applicable instead
of those above. If you wish to allow use of your version of this file only
under the terms of either the GPL or the LGPL, and not to allow others to
use your version of this file under the terms of the MPL, indicate your
decision by deleting the provisions above and replace them with the notice
and other provisions required by the LGPL or the GPL. If you do not delete
the provisions above, a recipient may use your version of this file under
the terms of any one of the MPL, the GPL or the LGPL.
*/

package
{
	import C.stdlib.*;
	import C.unistd.*;
	
	import flash.utils.getTimer;
	
	import redbean.core.Configuration;
	import redbean.core.Strings;
	import redbean.core.verifySDK;
	import redbean.utils.timeToHumanReadable;
	
	import shell.FileSystem;
	import shell.OperatingSystem;
	import shell.Program;
	import shell.Runtime;
	
	public class RedbeanApplication
	{
        
        public static function main():void
        {
            //our default config
            var conf:Configuration = defaultConfiguration();
//            trace( "our default config:" );
//            trace( conf.toString() );
            
            //our default strings
            var str:Strings = defaultStrings();
            
            //find env var
            var found:Boolean = findRedTamarinSDK( conf );
//            trace( "find the RedTamarin SDK path:" + found );
//            trace( "edited conf:" );
//            trace( conf.toString() );
            
            //load home config
            var found_home:Boolean = loadHomeConfiguration( conf );
//            trace( "load home config:" + found_home );
//            trace( "home conf:" );
//            trace( conf.toString() );
                        
            //load local config
            var found_local:Boolean = loadLocalConfiguration( conf );
//            trace( "load local config:" + found_local );
//            trace( "local conf:" );
//            trace( conf.toString() );
            
            //conf.REDTAMARIN_SDK = ""; //debug
            
            //find the RedTamarin SDK path
            if( !verifySDK( conf.REDTAMARIN_SDK ) )
            {
                var msg_error1:String = "RedTamarin SDK Not Found!!";
                trace( "[error] " + msg_error1 );
                exit( EXIT_FAILURE );
            }
            
            //our default state
            var base:CommandLine    = new CommandLine( "redbean", conf );
            
            //parse command line args
            var cmdline:CommandLine = CommandLine.parse( base, Program.argv );
            
            //our modified config per cmdline args
            conf = cmdline.getConfiguration();
//            trace( "our modified config per cmdline args:" );
//            trace( conf.toString() );
            
            //verify the build file
            var verify:Boolean = _verifyFile( conf.buildfile );
            if( !verify )
            {
                var msg_error2:String = "\"" + conf.buildfile + "\" is not a valid file";
                trace( "[error] " + msg_error2 );
                exit( EXIT_FAILURE );
            }
            
            //copy config to _globals
            conf.toObject( _globals );
            
            //copy SDK path to strings
            str.sdk = conf.REDTAMARIN_SDK;
            //trace( "[debug] str.sdk = " + str.sdk );
            // copy strings in _globals
            _globals.strings = str.toObject();
            
            if( !conf.quietMode && conf.showInformations )
            {
                trace( "[informations]" );
                trace( "Operating System: " + OperatingSystem.vendor );
                trace( "Hostname: " + OperatingSystem.hostname );
                trace( "Architecture: " + Runtime.architecture );
            }
            
            if( !conf.quietMode && conf.showEnvironment )
            {
                trace( "[environment]" );
                trace( Program.environ.join( "\n" ) );
            }
            
            
            //run the application
            var app:RedbeanApplication = new RedbeanApplication( conf, str );
        }
        
        private static function _verifyFile( file:String ):Boolean
        {
            var valid_file:Boolean = access( file, F_OK ) == 0
            if( valid_file )
            {
                return true;
            }
            
            return false;
        }
        
        public static function defaultConfiguration():Configuration
        {
            //default configuration
            var conf:Configuration = new Configuration();
            	
            	conf.REDTAMARIN_SDK   = "";
            	conf.showHelp         = false;
            	conf.showInformations = false;
            	conf.showEnvironment  = false;
            	conf.quietMode        = false;
            	conf.verboseMode      = false;
            	conf.buildfile        = "build.as3";
                conf.configfile       = "redbean.cfg";
            	conf.useDebugger      = false;
            
            return conf;
        }
        
        public static function defaultStrings():Strings
        {
            var str:Strings = new Strings();
                str.asc            = "{sdk}/lib/asc.jar";
                str.asc2           = "{sdk}/lib/asc2.jar";
                str.redshell       = "{sdk}/runtimes/redshell/{platform}/{bits}/redshell{extension}";
                str.redshell_d     = "{sdk}/runtimes/redshell/{platform}/{bits}/redshell_d{extension}";
                str.redshell_dd    = "{sdk}/runtimes/redshell/{platform}/{bits}/redshell_dd{extension}";
                str.redtamarin_abc = "{sdk}/lib-abc/redtamarin.abc";
                str.includeLine    = "include \"{path}\";";
                str.platform       = Runtime.platform;
                str.bits           = Runtime.is64bit() ? "64" : "32";
                str.extension      = (Runtime.platform == "windows") ? ".exe": "";
                
            return str;
        }
        
        public static function loadLocalConfiguration( config:Configuration ):Boolean
        {
            /* NOTE:
               to have a warning/error from the IDE here is normal
               the variable 'REDTAMARIN_SDK' and others are created
               by the evalued script so this var does not already exists
               hence error #1120 Access of undefined property
               
               you can disable those errors/warnings by adding
               -compiler.strict=false -compiler.warn-bad-bool-assignment=false
               to the Flex Builder compiler settings
               
               at qorst if an error occurs, asc.jar will point to the error
            */
            
            var local_config:String = config.configfile;
			var local_exists:Boolean = access( local_config, F_OK ) == 0;
            
			if( local_exists )
			{
				var local_source:String = FileSystem.read( local_config );
				var local_result:String = Runtime.returnEval( local_source );
				var local_var:*;
                
                include "local.incl";
                
                return true;
			}
            
            return false;
        }
        
        public static function loadHomeConfiguration( config:Configuration ):Boolean
        {
			var local_config:String = FileSystem.homeDirectory + FileSystem.separators[0] + config.configfile;
                local_config = FileSystem.normalizePath( local_config );
			var local_exists:Boolean = access( local_config, F_OK ) == 0;
            
			if( local_exists )
			{
				var local_source:String = FileSystem.read( local_config );
				var local_result:String = Runtime.returnEval( local_source );
				var local_var:*;
                
                include "home.incl";
                
                return true;
			}
            
            return false;
        }
        
        public static function findRedTamarinSDK( config:Configuration ):Boolean
        {
			var env_var:String = getenv( "REDTAMARIN_SDK" );
			if( env_var != "" )
			{
				config.REDTAMARIN_SDK = env_var;
			}
            
            if( config.REDTAMARIN_SDK != "" )
            {
                return true;
            }
            
            return false;
        }
        
        
        private var _start:uint;
        private var _end:uint;
        
        public var config:Configuration;
        public var strings:Strings;
        
		public function RedbeanApplication( config:Configuration, strings:Strings )
		{
			this.config  = config;
            this.strings = strings;
			
            before();
            run();
            after();
		}
        
        public function before():void
        {
            _start = getTimer();
        }
        
        public function run():void
        {
            if( !config.quietMode )
            {
                trace( "[run] " + config.buildfile );
            }
            
            var source:String = FileSystem.read( config.buildfile );
            
            if( !config.quietMode )
            {
                trace( "" );
            }
            
            Runtime.eval( source );
            
            if( !config.quietMode )
            {
                trace( "" );
            }
        }
        
        public function after():void
        {
			_end = getTimer();
            
            if( !config.quietMode )
            {
                trace( "[done] in " + timeToHumanReadable( _end - _start ) );
            }
			
			exit( EXIT_SUCCESS );
        }
        
        
	}
}