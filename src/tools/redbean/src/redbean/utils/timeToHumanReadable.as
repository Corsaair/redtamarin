package redbean.utils
{
    /** @private */
	public function timeToHumanReadable( milliseconds:uint,
										 short:Boolean = true,
										 useLetters:Boolean = true,
										 format:Array = null ):String
	{
		if( !format )
		{
			format = [ ":", ".", "h", "m", "s", "ms" ];
		}
		
		var sep:String = format[0];
		var end:String = format[1];
		var _h:String  = useLetters ? format[2]: "";
		var _m:String  = useLetters ? format[3]: "";
		var _s:String  = useLetters ? format[4]: "";
		var _ms:String = useLetters ? format[5]: "";
		
		var sec:Number = milliseconds / 1000;
		
		var ms:String = "";
		var ss:String = "";
		var mm:String = "";
		var hh:String = "";
		
		var str:String = sec.toString();
		var pos:int = str.indexOf( "." );
		if( pos > -1 )
		{
			sec = parseInt( str.substr( 0, pos ) );
			ms = str.substring( pos+1 );
		}
		else
		{
			sec = parseInt( str );
			ms = "0"; 
		}
		
		var s:Number = sec % 60;
		var m:Number = Math.floor( (sec % 3600) / 60 );
		var h:Number = Math.floor( sec / (60 * 60) );
		
		var ddigit:Function = function( n:Number ):String
		{
			if( n < 10 )
			{
				return "0" + n;
			}
			
			return n.toString();
		}
		
		ss = ddigit( s );
		mm = ddigit( m );
		hh = ddigit( h );
		
		str = "";
		if( short )
		{
			str = ms + _ms;
			if( ss != "00" )
			{
				str = ss + _s + end + str;
				
				if( mm != "00" )
				{
					str = mm + _m + sep + str;
					
					if( hh != "00" )
					{
						str = hh + _h + sep + str;
					}
				}
			}
		}
		else
		{
			str = hh + _h + sep + mm + _m + sep + ss + _s + end + ms + _ms;	
		}
		
		return str;
	}
}