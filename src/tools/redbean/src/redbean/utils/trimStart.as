package redbean.utils
{
    /** @private */
	public function trimStart( source:String , chars:Array = null ):String
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
		for( i = 0; (i < l) && (chars.indexOf( source.charAt( i ) ) > - 1) ; i++ )
		{
		}
		return source.substring( i );
	};
}