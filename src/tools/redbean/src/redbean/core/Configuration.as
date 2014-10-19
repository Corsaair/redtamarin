package redbean.core
{
	/**
	 * Redbean configuration.
	 * 
	 * <p>
	 * If you need to understand or know what <code>this</code> or <code>that</code> options
	 * is doing, this is the file to read.
	 * </p>
	 */
	public class Configuration
	{
		private var _config:Object;
		
		public function Configuration( config:Object = null )
		{
			if( config )
			{
				_config = config;
			}
			else
			{
				_config = {};
			}
		}
		
        public function toString():String
        {
            var str:String = "";
                str += "REDTAMARIN_SDK = \"" + REDTAMARIN_SDK + "\"\n";
                str += "showHelp = " + showHelp + "\n";
                str += "showInformations = " + showInformations + "\n";
                str += "showEnvironment = " + showEnvironment + "\n";
                str += "quietMode = " + quietMode + "\n";
                str += "verboseMode = " + verboseMode + "\n";
                str += "buildfile = \"" + buildfile + "\"\n";
                str += "configfile = \"" + configfile + "\"\n";
                str += "useDebugger = " + useDebugger;
            
            return str;
        }
        
        public function toObject( destination:* ):void
        {
            destination.REDTAMARIN_SDK   = REDTAMARIN_SDK;
            destination.showHelp         = showHelp;
            destination.showInformations = showInformations;
            destination.showEnvironment  = showEnvironment;
            destination.quietMode        = quietMode;
            destination.verboseMode      = verboseMode;
            destination.buildfile        = buildfile;
            destination.configfile       = configfile;
            destination.useDebugger      = useDebugger;
        }
        
        public function fromObject( source:* ):void
        {
            REDTAMARIN_SDK   = source.REDTAMARIN_SDK;
            showHelp         = source.showHelp;
            showInformations = source.showInformations;
            showEnvironment  = source.showEnvironment;
            quietMode        = source.quietMode;
            verboseMode      = source.verboseMode;
            buildfile        = source.buildfile;
            configfile       = source.configfile;
            useDebugger      = source.useDebugger;
        }
        
		/**
		 * The RedTamarin SDK path.
		 * 
		 * <p>
		 * By default, this path is <b>empty</b>.
		 * If there is one thing you need  to do with redbean is to configure this path.
		 * </p>
		 */	
		public function get REDTAMARIN_SDK():String { return _config.REDTAMARIN_SDK; }
		/** @private */
		public function set REDTAMARIN_SDK( value:String ):void { _config.REDTAMARIN_SDK = value; }

		/**
		 * Command line option <code>-h</code>
		 * to show the command line help.
		 */
		public function get showHelp():Boolean { return _config.showHelp; }
		/** @private */
		public function set showHelp( value:Boolean ):void { _config.showHelp = value; }

		/**
		 * Command line option <code>-i</code>
		 * to show system informations.
		 */
		public function get showInformations():Boolean { return _config.showInformations; }
		/** @private */
		public function set showInformations( value:Boolean ):void { _config.showInformations = value; }

		/**
		 * Command line option <code>-e</code>
		 * to show environment variables.
		 */
		public function get showEnvironment():Boolean { return _config.showEnvironment; }
		/** @private */
		public function set showEnvironment( value:Boolean ):void { _config.showEnvironment = value; }
		
		/**
		 * Command line option <code>-q</code>
		 * to mute the command line output.
		 */
		public function get quietMode():Boolean { return _config.quietMode; }
		/** @private */
		public function set quietMode( value:Boolean ):void { _config.quietMode = value; }

		/**
		 * Command line option <code>-v</code>
		 * to make the command line more verbose.
		 */
		public function get verboseMode():Boolean { return _config.verboseMode; }
		/** @private */
		public function set verboseMode( value:Boolean ):void { _config.verboseMode = value; }

		/**
		 * Default <code>buildfile</code> name used by the command line option <code>-f</code>.
		 */
		public function get buildfile():String { return _config.buildfile; }
		/** @private */
		public function set buildfile( value:String ):void { _config.buildfile = value; }

		/**
		 * Default <code>configfile</code> name used by redbean.
		 */
		public function get configfile():String { return _config.configfile; }
		/** @private */
		public function set configfile( value:String ):void { _config.configfile = value; }
		
		/**
		 * Command line option <code>-dd</code>
		 * to use the <b>redshell debug debugger</b> (<code>redshell_dd</code>).
		 * 
		 * <p>
		 * When this option is <code>true</code>, <code>debug = true</code>
		 * will use <code>redshell_dd</code> instead of <code>redshell_d</code> executable.
		 * </p>
		 */
		public function get useDebugger():Boolean { return _config.useDebugger; }
		/** @private */
		public function set useDebugger( value:Boolean ):void { _config.useDebugger = value; }
	}
	
	
}