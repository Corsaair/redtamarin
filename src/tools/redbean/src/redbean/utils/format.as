package redbean.utils
{
    /** @private */
	public function format( pattern:String, ...args:Array ):String
	{
		if( pattern == null || pattern == "" )
		{
			return "";
		}
		
		var formatted:String = pattern;
		var len:uint         = args.length;
		var words:Object     = {};
		
		if( (len == 1) && (args[0] is Array) )
		{
			args = args[0];
		}
		else if( args[0] is Array )
		{
			var a:Array = args[0];
			args.shift();
			args = a.concat( args );
		}
		else if( (args[0] is Object) && (String( args[0] ) == "[object Object]") )
		{
			words = args[0];
			//trace( "words = " + words );
			if( len > 1 ) 
			{ 
				args.shift(); 
			}
		}
		
		/* note:
		don't use the global flag here as we want the search
		to be iterative and starting at index 0 of the string
		
		but do use the multiline flag if a token can be replaced
		by a \n, \r, etc.
		*/
		var search:RegExp = new RegExp( "{([a-z0-9,:\\-]*)}", "m" );
		var result:Object = search.exec( formatted );
		
		var part:String;
		var token:String;
		var c:String;
		
		var dirty:Boolean ;
		
		var padding:int = 0;
		
		/* note:
		the buffer will store special string parts of the form
		buffer[0] = "{a:1,b:2,c:3}"
		the fromatted string will replace it by the form
		\uFFFC0 , \uFFFC+N , N being an integer from 0 to N
		*/
		var buffer:Array = [];
		
		while( result != null )
		{
			part = result[0];
			//trace( "part = " + part );
			
			/////// pad the token expression
			
			token = result[1] ;
			//trace( "token = " + token );
			
			var pos:int = token.indexOf( "," );
			
			if( pos >= 0 )
			{
				padding = Number( token.substr( pos + 1 ) );
				token   = token.substring( 0, pos );
			}
			
			////////////
			
			c = token.charAt( 0 );
			//trace( "c = " + c );
			
			if( ("0" <= c) && (c <= "9") )
			{
				formatted = formatted.replace( part, pad( String( args[token] ) , padding ) );
			}
			else if( ( token == "" ) || ( token.indexOf( ":" ) > -1 ) ) // if the token is not valid
			{
				/* note:
				this is to deal with eden/json strings inside a format string
				if you do a format( "expected: <{a:1,b:2,c:3}> but was: <{a:1,b:2,c:4}>", "test" )
				this will collide of the legit parsing of
				format( "hello {x,-8} and nhello {y,-8}" )
				*/
				
				buffer.push( part );
				
				formatted = formatted.replace( new RegExp(part,"g"), "\uFFFC"+ ( buffer.length - 1 ) ) ;
				dirty     = true;
			}
			else if( ( "a" <= c ) && ( c <= "z" ) )
			{
				//trace( "found letter" );
				if( token in words || words.hasOwnProperty( token ) )
				{
					//trace( "words[token] = " + words[token] );
					/* note:
					here you want the part to have a global flag to replace all token instances
					*/
					formatted = formatted.replace( new RegExp(part,"g"), pad( String(words[token]) , padding ) );
				}
//                else
//                {
//                    trace( token + " not found" );
//                }
				
				/* NOTE:
				   bug here when we can not find words[token]
				   we run into an infinite loop
				*/
			}
			else
			{
				/* note: 
				don't use format() within itself
				*/
				throw new Error( "core.strings.format failed, malformed token \"" + part + "\", can not start with \"" + c + "\"" ) ;
			}
			
			result = search.exec( formatted );
		}
		
		if( dirty )
		{
			var i:int;
			var bl:int = buffer.length ; 
			for( i = 0 ; i < bl ; i++ )
			{
				formatted = formatted.replace( new RegExp( "\uFFFC" + i , "g" ) , buffer[i] );
			}
		}
		
		return formatted;
	}
}