package redbean.utils
{
    /** @private */
	public function bytesToHumanReadable( bytes:Number, precision:uint = 2, SI:Boolean = false, force:String = "" ):String
	{
		const unit:uint = SI ? 1000 : 1024;
		
		if( (bytes < unit) && ((force == "") || (force == "B")) ) 
		{ 
			return bytes + " B"; 
		}
		
		var u:String;
		var s:String;
		
		const kilo:Number  = unit;
		const mega:Number  = kilo  * unit;
		const giga:Number  = mega  * unit;
		const tera:Number  = giga  * unit;
		const peta:Number  = tera  * unit;
		const exa:Number   = peta  * unit;
		const zetta:Number = exa   * unit;
		const yotta:Number = zetta * unit;
		
		if( (bytes >= 0) && (bytes < kilo) )           { u =  ""; }
		else if( (bytes >= kilo)  && (bytes < mega) )  { u = "K"; }
		else if( (bytes >= mega)  && (bytes < giga) )  { u = "M"; }
		else if( (bytes >= giga)  && (bytes < tera) )  { u = "G"; }
		else if( (bytes >= tera)  && (bytes < peta) )  { u = "T"; }
		else if( (bytes >= peta)  && (bytes < exa) )   { u = "P"; }
		else if( (bytes >= exa)   && (bytes < zetta) ) { u = "E"; }
		else if( (bytes >= zetta) && (bytes < yotta) ) { u = "Z"; }
		else if( (bytes >= yotta) )                    { u = "Y"; }
		
		if( force != "" )
		{
			if( force == "B" ) { force = ""; }
			u = force;
		}
		
		switch( u )
		{
			case "K": s = Number( bytes / kilo  ).toFixed( precision ); break;
			case "M": s = Number( bytes / mega  ).toFixed( precision ); break;
			case "G": s = Number( bytes / giga  ).toFixed( precision ); break;
			case "T": s = Number( bytes / tera  ).toFixed( precision ); break;
			case "P": s = Number( bytes / peta  ).toFixed( precision ); break;
			case "E": s = Number( bytes / exa   ).toFixed( precision ); break;
			case "Z": s = Number( bytes / zetta ).toFixed( precision ); break;
			case "Y": s = Number( bytes / yotta ).toFixed( precision ); break;
			case "":
			default:
				s = bytes + "";
		}
		
		var zeros:String = new Array(precision+1).join("0");
		var parts:Array  = s.split(".");
		
		if( s.indexOf( "." ) > -1 && (zeros == parts[1]) ) 
		{ 
			s = parts[0]; 
		}
		
		return s + " " + u + (SI ? "i" : "") + "B";
	}
}