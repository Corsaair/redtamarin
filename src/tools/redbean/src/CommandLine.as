package
{
    import C.stdlib.*;
    import C.unistd.*;
    
    import redbean.core.Configuration;
    
    import shell.Program;

    /**
    * CommandLine class
    */
	public class CommandLine
	{
		private static var _usage:String = "usage";

		private static var _help:String = "help";

        public static function usage( str:String = "" ):void
        {
            trace( str + _usage );
        }
        
        public static function help( str:String = "" ):void
        {
            usage( str );
            trace( "" );
            trace( _help );
        }

        public static function parse( cmdline:CommandLine, argv:Array ):CommandLine
        {
            var result:CommandLine = cmdline;
            var msg:String = "";
            
            var i:uint;
            var len:uint = argv.length;
            var arg:String;
            //redbean -- [-h] [-i] [-e] [-q] [-v] [-dd] [-f buildfile]
            for( i = 0; i < len; i++ )
            {
                arg = argv[i];
                if( arg.charAt(0) == "-" )
                {
                    switch( arg )
                    {
                        case "-h":
                        help( "redbean" );
                        exit( EXIT_FAILURE );
                        break;
                        
                        case "-i":
                        result.showInformations = true;
                        break;
                        
                        case "-e":
                        result.showEnvironment = true;
                        break;
                        
                        case "-q":
                        result.quietMode = true;
                        break;
                        
                        case "-v":
                        result.verboseMode = true;
                        break;
                        
                        case "-dd":
                        result.useDebugger = true;
                        break;
                        
                        case "-f":
                        var buildfile:String = argv[i+1];
                        var valid_file:Boolean = access( buildfile, F_OK ) == 0
                        if( !valid_file )
                        {
                            msg = "[error] can not access '" + buildfile + "'";
                            trace( msg );
                            exit( EXIT_FAILURE );
                        }
                        
                        result.buildfile = buildfile;
                        break;
                        
                        default:
                        msg  = "Invalid option:" + arg + "\n";
                        msg += "redbean";
                        usage( msg );
                    }
                }
            }
            
            if( result.verboseMode && result.quietMode )
            {
                result.verboseMode = false;
                result.quietMode   = false;
            }
            
            if( !result.quietMode )
            {
                trace( "[redbean 1.0.0]" );
            }
            
            if( result.verboseMode )
            {
                trace( "[arg] " + argv.join( " " ) );
                trace( "[cwd] " + Program.workingDirectory );
            }
            
            return result;
        }
        
        //options
        public var REDTAMARIN_SDK:String;
        public var showHelp:Boolean;
        public var showInformations:Boolean;
        public var showEnvironment:Boolean;
        public var quietMode:Boolean;
        public var verboseMode:Boolean;
        public var buildfile:String;
        public var configfile:String;
        public var useDebugger:Boolean;
        //options - END
        
        
        public var name:String;
        
		public function CommandLine( name:String, config:Configuration = null ):void
		{
            this.name = name;
            
            if( config )
            {
                config.toObject( this );
            }
		}
        
        public function getConfiguration():Configuration
        {
            var conf:Configuration = new Configuration();
                conf.fromObject( this );
            
            return conf;
        }
        

        
	}
}