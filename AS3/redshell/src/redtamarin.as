package redtamarin
	{
	
	internal class sys
		{
		public native static function assert( expression:int ):void; //test only
		
		}
	
	public function assert( expression:int ):void
		{
		sys.assert( expression );
		}
	
	public native function sleep( second:uint ):void;
	
	/* note:
	   test to save AS function in C
	   and call the AS function from C
	   
	public native function testSave( f:Function ):void;
	public native function testCall():void;
	*/
	
	public function get version():String
		{
		return "0.1.0." + parseInt( "$Rev: 92 $".split( " " )[1] );
		}
	
	}
