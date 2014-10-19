package redbean.utils
{
    /** @private */
	public function pad( source:String, amount:int, char:String = " " ):String
	{
		var left:Boolean  = amount >= 0 ;
		var width:int     = amount > 0 ? amount : -amount ;
		
		if( ( width < source.length ) || ( width == 0 ) )
		{
			return source;
		}
		
		if ( char == null )
		{
			char = " " ; // default
		}
		else if ( char.length > 1 )
		{
			char = char.charAt(0) ; //we want only 1 char
		}
		
		while( source.length != width )
		{
			if( left )
			{
				source = char + source;
			}
			else
			{
				source += char;
			}
		}
		
		return source;
	};
}