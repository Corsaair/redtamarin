package redbean.utils
{
    /** @private */
	public function trimEnd( source:String , chars:Array = null ):String
	{
		if( chars == null )
		{
			chars = whiteSpaces;
		}
		if ( source == null || source == "" )
		{
			return "" ;
		}
		var i:int;
		var l:int = source.length ;
		for( i = source.length - 1; (i >= 0) && (chars.indexOf( source.charAt( i ) ) > - 1) ; i-- )
		{
		}
		return source.substring( 0, i + 1 );
	};

}