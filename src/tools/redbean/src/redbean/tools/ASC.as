package redbean.tools
{
	import redbean.core.find;

	/**
	 * Allows to configure the <b>ASC</b> tool (ActionScript Compiler).
	 */
	public class ASC
	{
		private var _AS3:Boolean      = true;
		private var _ES:Boolean       = false;
		private var _d:Boolean        = false;
		private var _f:Boolean        = false;
		private var _h:Boolean        = false;
		private var _i:Boolean        = false;
		private var _m:Boolean        = false;
		private var _p:Boolean        = false;
		private var _md:Boolean       = false;
		private var _warnings:Boolean = false;
		private var _strict:Boolean   = false;
		private var _sanity:Boolean   = false;
		//private var _log:String       = "";
		//private var _exe:String       = "";
		private var _optimize:Boolean = false;
		
		private var _imports:Array = [];
		private var _includes:Array = [];
		private var _files:Array = [];
		
		private var _pre:String = "java -jar ";
		private var _exe:String = "asc";
		
		public function ASC( exe:String = "" ):void
		{
			if( exe != "" )
			{
				//_exe = exe;
				_exe = find( exe );
			}
		}
		
		/**
		 * Use the AS3 class based object model for greater performance and better error reporting.
		 */
		public function get AS3():Boolean { return _AS3; }
		public function set AS3( value:Boolean ):void { _AS3 = value; _ES = !value; }
		
		/**
		 * Use the ECMAScript edition 3 prototype based object model to allow dynamic overriding of prototype properties.
		 */
		public function get ES():Boolean { return _ES; }
		public function set ES( value:Boolean ):void { _ES = value; _AS3 = !value; }
		
		/**
		 * Emit debug info into the bytecode.
		 */
		public function get d():Boolean { return _d; }
		public function set d( value:Boolean ):void { _d = value; }

		/**
		 * Print the flow graph to standard out.
		 */
		public function get f():Boolean { return _f; }
		public function set f( value:Boolean ):void { _f = value; }
		
		/**
		 * Print this message.
		 */
		public function get h():Boolean { return _h; }
		public function set h( value:Boolean ):void { _h = value; }
		
		/**
		 * Write intermediate code to the .il file.
		 */
		public function get i():Boolean { return _i; }
		public function set i( value:Boolean ):void { _i = value; }
		
		/**
		 * Write the avm+ assembly code to the .il file.
		 */
		public function get m():Boolean { return _m; }
		public function set m( value:Boolean ):void { _m = value; }
		
		/**
		 * Write parse tree to the .p file.
		 */
		public function get p():Boolean { return _p; }
		public function set p( value:Boolean ):void { _p = value; }
		
		/**
		 * Emit metadata information into the bytecode.
		 */
		public function get md():Boolean { return _md; }
		public function set md( value:Boolean ):void { _md = value; }
		
		/**
		 * Warn on common actionscript mistakes.
		 */
		public function get warnings():Boolean { return _warnings; }
		public function set warnings( value:Boolean ):void { _warnings = value; }
		
		/**
		 * Treat undeclared variable and method access as errors.
		 */
		public function get strict():Boolean { return _strict; }
		public function set strict( value:Boolean ):void { _strict = value; }

		/**
		 * System-independent error/warning output.
		 * Appropriate for sanity testing.
		 */
		public function get sanity():Boolean { return _sanity; }
		public function set sanity( value:Boolean ):void { _sanity = value; }
		
		/**
		 * Produce an optimized abc file.
		 */
		public function get optimize():Boolean { return _optimize; }
		public function set optimize( value:Boolean ):void { _optimize = value; }
		
		
		
		
		/**
		 * Imports specified package(s).
		 * You can specify more than one.
		 */
		public function addImport( ...files ):void
		{
			for( var i:uint = 0; i<files.length; i++ )
			{
				var file:String = files[i];
				_imports.push( file );
			}
		}

		/**
		 * Includes specified file(s).
		 * You can specify more than one.
		 */
		public function addIncludes( ...files ):void
		{
			for( var i:uint = 0; i<files.length; i++ )
			{
				var file:String = files[i];
				_includes.push( file );
			}
		}

		/**
		 * Compiles specified file(s).
		 * You can specify more than one.
		 */
		public function addFiles( ...files ):void
		{
			for( var i:uint = 0; i<files.length; i++ )
			{
				var file:String = files[i];
				_files.push( file );
			}
		}
		
		/**
		 * Returns the command-line equivalent to the tool actual configuration.
		 */
		public function toString():String
		{
			var str:String = "";
				str += _pre;
				str += find( _exe );
			
			if( _AS3 ) {     str += " -AS3"; }
			else if( _ES ) { str += " -ES"; }
			
			if( _d ) { str += " -d"; }
			if( _f ) { str += " -f"; }
			if( _h ) { str += " -h"; }
			if( _i ) { str += " -i"; }
			if( _m ) { str += " -m"; }
			if( _p ) { str += " -p"; }
			if( _md ) { str += " -md"; }
			if( _warnings ) { str += " -warnings"; }
			if( _strict ) { str += " -strict"; }
			if( _sanity ) { str += " -sanity"; }
			if( _optimize ) { str += " -optimize"; }
			
			if( _imports.length > 0 )
			{
				for( var i:uint = 0; i<_imports.length; i++ )
				{
					str += " -import " + _imports[i];
				}
			}
			
			if( _includes.length > 0 )
			{
				for( var j:uint = 0; j<_includes.length; j++ )
				{
					str += " -in " + _includes[j];
				}
			}
			
			if( _files.length > 0 )
			{
				for( var k:uint = 0; k<_files.length; k++ )
				{
					str += " " + _files[k];
				}
			}
			
			return str;
		}
	}
	
}