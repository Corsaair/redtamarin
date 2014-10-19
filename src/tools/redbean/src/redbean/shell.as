package redbean
{
	import redbean.core.find;
	import redbean.utils.format;
	
	import shell.Program;

	/**
	 * Runs files with the <code>redshell</code> runtime.
	 * 
     * <p>
     * TODO
     * </p>
     * 
	 * @langversion 3.0
	 * @playerversion AVM 0.4
	 */
	public function shell( filepath:String, debug:Boolean = false, libraries:Array = null ):void
	{
        if( !_globals.quietMode )
        {
            trace( "[shell] " + filepath );
        }
        
		var rs:String;
        var name:String;
		
		if( debug )
		{
			if( _globals.useDebugger )
			{
                name = "redshell_dd";
			}
			else
			{
                name = "redshell_d";
			}
		}
		else
		{
			name = "redshell";
		}
		
        rs = find( name );
        
		/* NOTE:
		   libraries does not need to contain redtamarin.abc
		   because it is already embedded in redshell
		   maybe make a check and display a warning ?
		*/
        if( !libraries )
        {
            libraries = [];
        }
        
		var lib:String = "";
        var len:uint = libraries.length;
        var i:uint;
		if( len > 0 )
		{
			for( i = 0; i < len; i++ )
			{
				lib += " " + libraries[i];
			}
		}
		lib += " ";
		
		var commandline:String = "{redshell}{libraries}{file}";
		var cli:String = format( commandline, {redshell:rs, libraries:lib, file:filepath} );
		
        if( !_globals.quietMode && _globals.verboseMode )
        {
            trace( "[" + name + "] " + cli );
            trace( "" );
        }
        
		var output:String = Program.open( cli );
		trace( output );
	}
}