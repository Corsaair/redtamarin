
package shell
{
	import flash.utils.Proxy;
    import flash.utils.flash_proxy;
    import shell.Program;

    /* TODO:
       this class is just a test for now
       need to be worked on and tested

       should work also with getenv() / setenv() etc.

       eg.
       deleting a property should remove it from the current environ
       getenv() should not find it
       at least for the current session of the program

       see if it's possible to have a GlobalEnvironment class
       allowing to update/create/delete env vars that persist after the end of the program session

       also Environment is not to be used "as is"
       it is supposed to be initialised in the Program class
       public const environment:Environment = new Environment();
       and then used from Program
	   trace( Program.environment.HOME );
	   Program.environment.TEST = "hello world"

	   later if we impl. subprocesses we should be able to pass
	   a copy of the current env vars
	   eg. new subprocess( someprogram,exe, Program.environment );
    */
    /**
    * Environment class
    * to access the current environment variables
    */
	public dynamic class Environment extends Proxy
	{
		private var _vars:Array;
		private var _idx:Array;
		private var _env:Object;

		public function Environment()
		{
			trace( "Environment ctor" );
			refresh();
		}

		private function _parse():void
		{
			var i:uint;
			var len:uint = _vars.length;
			var line:String;
			var pos:int;
			var name:String;
			var value:String;

			for( i=0; i<len; i++ )
			{
				line = _vars[ i ];
				pos  = line.indexOf( "=" );
				name = line.substr( 0, pos );
				value = line.substring( pos+1 );
				_env[ name ] = value;
				_idx[ i ] = name;
			}
		}

		/** @private */
		override flash_proxy function callProperty( methodName:*, ... args ):*
		{
			trace( "Environment callProperty - " + methodName + "( " + args.join(", ") + " )" );
		}

		/** @private */
		override flash_proxy function deleteProperty( name:* ):Boolean
		{
			return delete _env[ name ];
		}

		/** @private */
		override flash_proxy function getProperty( name:* ):*
		{
			return _env[ name ];
		}

		/** @private */
		override flash_proxy function setProperty( name:*, value:* ):void
		{
			/* TODO:
			   if the property already exists update it -done

			   if the property does not exists, create it - not done
			*/
			if( hasProperty( name ) )
			{
				_env[ name ] = value;
			}
		}
		
		/** @private */
		override flash_proxy function hasProperty( name:* ):Boolean
		{
			return name in _env;
		}

		/** @private */
		override flash_proxy function nextNameIndex( index:int ):int
		{
			if( index > (_idx.length-1) )
			{
				return 0;
			}

			return index + 1;
		}

		/** @private */
		override flash_proxy function nextName( index:int ):String
		{
			return String( _idx[ index - 1 ] );
		}

		/** @private */
		override flash_proxy function nextValue( index:int ):*
		{
			return String( _env[ _idx[ index - 1 ] ] );
		}

		/**
		* TODO
		*/
		public function get length():uint
		{
			return _idx.length;
		}

		/**
		* TODO
		*/
		public function refresh():void
		{
			/* TODO:
			   by default we inherit the system env vars
			   we should also have the option to create an empty environment
			   that can isolated from the system env vars
			   eg. case of a subprocess where you want only
			   to passtrough some env vars
			*/
			_vars = Program.getEnviron();
			if( _idx ) { _idx.length = 0; }
			_idx  = new Array();
			_env  = new Object();

			_parse();
		}
	}
}
