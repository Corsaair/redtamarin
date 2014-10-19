package redbean
{
	import redbean.core.find;
	import redbean.tools.ASC;
	
	import shell.Program;

	/**
	 * Compiles <code>ActionScript 3.0</code> source files
     * with the ActionScript Compiler (ASC).
	 * 
     * <p>
     * TODO
     * </p>
     * 
     * @param filepath The main source file.
     * @param options If not <code>null</code> allows to override the <code>ASC</code> compiler options.
     * @param libraries An array of ABC files to import.
     * 
	 * @langversion 3.0
	 * @playerversion AVM 0.4
     * 
     * @see redbean.tools.ASC
	 */
	public function compile( filepath:String, options:ASC = null, libraries:Array = null ):void
	{
        if( !_globals.quietMode )
        {
            trace( "[compile] " + filepath );
        }
    
		var asc1:ASC;
		if( !options )
		{
			asc1 = new ASC();
			asc1.AS3      = true;
			asc1.strict   = true;
			asc1.optimize = true;
			asc1.addImport( find( "redtamarin_abc" ) );
		}
		else
		{
			asc1 = options;
		}
		
        if( !libraries )
        {
            libraries = [];
        }
        
		var len:uint = libraries.length;
		var i:uint;
		for( i = 0; i < len; i++ )
		{
			asc1.addImport( libraries[i] );
		}
		
		asc1.addFiles( filepath );
		
		var cli:String = asc1.toString();
		//trace( "cli = " + cli );
		
        if( !_globals.quietMode && _globals.verboseMode )
        {
            trace( "[asc1] " + cli );
        }
        
        var output:String = Program.open( cli );
		trace( output );
	}
}