package redtamarin
	{
	
	internal class sys
		{
		public native static function assert( expression:int ):void; //test only
		
		public static function get version():String
			{
			return "0.1.0." + parseInt( "$Rev$".split( " " )[1] );
			}
		
		}
	
	public function assert( expression:int ):void
		{
		sys.assert( expression );
		}
	
	public native function sleep( second:uint ):void;
	
	public native function saveFunction( f:* ):void;
	public native function callFunction():void;
	
	public function getRedTamarinVersion():String
		{
		return sys.version;
		}
	
	}
