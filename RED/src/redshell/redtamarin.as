package redtamarin
	{
	
	internal class sys
		{
		public native static function assert( expression:int ):void;
		
		public static function get version():String
			{
			return "0.1"
			}
		
		}
	
	public function getRedTamarinVersion():String
		{
		return sys.version
		}
	
	}
