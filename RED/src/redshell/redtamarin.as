package redtamarin
	{
	
	internal class sys
		{
		public native static function assert( expression:int ):void; //test only
		
		public static function get version():String
			{
			return "0.1"
			}
		
		}
	
	public function assert( expression:int ):void
		{
		sys.assert( expression );
		}
	
	public function getRedTamarinVersion():String
		{
		return sys.version;
		}
	
	}
