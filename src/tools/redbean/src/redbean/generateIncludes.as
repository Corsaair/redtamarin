package redbean
{
	import redbean.utils.format;
	import redbean.utils.trimStart;
	
	import shell.FileSystem;

    /**
     * Generates include lines from a path.
     * 
     * <p>
     * TODO
     * </p>
     * 
     * @example
     * <listing>
     * import redbean.&#42;;
     * import shell.FileSystem;
     * 
     * /&#42; Will generated all the includes from the path "src"
     *   but will not include the file "program.as"
     * &#42;/
     * var myincludes:Array = generateIncludes( "src", [ "program.as" ] );
     * 
     * // we save those includes
     * FileSystem.save( "src/includes.as", myincludes.join( "\n" ) );
     * </listing>
     * 
     * @param path The source path.
     * @param ignore A list of file to ignore.
     * @param extensions A list of extensions to take into account.
     * 
     * @return A list of include lines as an <code>Array</code>
     * 
	 * @langversion 3.0
	 * @playerversion AVM 0.4
     */
	public function generateIncludes( path:String, ignore:Array = null, extensions:Array = null ):Array
	{
		if( !_globals.quietMode )
        {
            trace( "[generateIncludes] " + path );
        }
        
        if( !ignore )
		{
			ignore = [];
		}
		
		if( !extensions )
		{
			extensions = [ ".as" ];
		}
		
		var hasExtension:Function = function( filepath:String, ext:Array ):Boolean
		{
			var filext:String;
			var filediff:String;
			
			for( var i:uint = 0; i<ext.length; i++ )
			{
				filext = ext[i];
				filediff = filepath.substring( filepath.length - filext.length );
				if( filext == filediff )
				{
					return true;
				}
			}
			return false;
		}
		
		var isIgnored:Function = function( filepath:String ):Boolean
		{
			if( ignore.length == 0 ) { return false; }
			
			var pattern:String;
			
			for(var i:uint = 0; i<ignore.length; i++)
			{
				pattern = ignore[i];
				if( filepath.search( pattern ) > -1 )
				{
					return true;
				}
			}
			
			return false;
		}
		
		var select:Function = function( item:*, index:int, array:Array ):void
		{
			if( hasExtension(item, extensions) && !isIgnored(item) )
			{
				item = trimStart( item, ["/"] );
				includes.push( format( _globals.strings.includeLine, {path:item} ) );
			}
		}
		
		var includes:Array = [];
		//var files:Array = getListByDepth( path, false );
		//var files:Array = getListByBreadth( path, false );
		var files:Array = FileSystem.listByBreadth( path, false );
		
		files.forEach( select );
		
        if( !_globals.quietMode && _globals.verboseMode )
        {
            trace( "[comment] " + includes.length + " includes" );
            //trace( includes );
            trace( "[line] " + includes.join( "\n[line] " ) );
        }
        
		return includes;
	}
}