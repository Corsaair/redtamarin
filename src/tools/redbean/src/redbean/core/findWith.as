package redbean.core
{
	import redbean.utils.format;
	
	import shell.FileSystem;

    /** @private */
	public function findWith( name:String, data:Object ):String
	{
		if( data[name] )
		{
			//trace( "found data[" + name + "] = " + data[name] );
			var str:String = format( data[name], data );
			//trace( "str = " + str );
			str = FileSystem.normalizePath( str );
			//trace( "str = " + str );
			return str;
		}
		//trace( "not found data[" + name + "]" );
		return "";		
	}
}