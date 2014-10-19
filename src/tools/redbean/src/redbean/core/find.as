package redbean.core
{
	import redbean.utils.format;
	
	import shell.FileSystem;

    /** @private */
	public function find( name:String ):String
	{
		if( _globals.strings[name] )
		{
			//trace( "[find] found: " + name + " = " + _globals.strings[name] );
            //trace( "[debug] _globals.strings.sdk = " + _globals.strings.sdk );
			var str:String = format( _globals.strings[name], _globals.strings );
            //trace( "[find] resolved: " + str );
			    str = FileSystem.normalizePath( str );
			//trace( "[find] normalized: " + str );
            return str;
		}
		
		return "";
	}
}