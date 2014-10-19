package redbean
{
	import shell.Runtime;
	
	/**
	 * Operating System compilation targets.
	 * 
	 * <p>
	 * Those targets allow to inform different <b>tools</b> and <b>functions</b>
	 * which target you want to compile for.
	 * </p>
	 * 
	 * <p>
	 * You can select different targets between <b>Windows</b>, <b>Macintosh</b> and <b>Linux</b>,
	 * in either <b>32-bit</b>, <b>64-bit</b> or <b>both</b>.
	 * </p>
	 */
	public class OS
	{
		/**
		 * Unknown Operating System.
		 * 
		 * <p>
		 * This should not happen and in general indicate an error.
		 * </p>
		 */
		public static const unknown:OS     = new OS( 0x0000, "unknown", false );
		
		/**
		 * Windows 32-bit Operating System.
		 */
		public static const windows32:OS   = new OS( 0x0001, "windows", false );
		
		/**
		 * Macintosh 32-bit Operating System.
		 */
		public static const macintosh32:OS = new OS( 0x0002, "macintosh", false );
		
		/**
		 * Linux 32-bit Operating System.
		 */
		public static const linux32:OS     = new OS( 0x0003, "linux", false );

		/**
		 * Windows 64-bit Operating System.
		 */
		public static const windows64:OS   = new OS( 0x0010, "windows", true );
		
		/**
		 * Macintosh 64-bit Operating System.
		 */
		public static const macintosh64:OS = new OS( 0x0020, "macintosh", true );
		
		/**
		 * Linux 64-bit Operating System.
		 */
		public static const linux64:OS     = new OS( 0x0030, "linux", true );
		
		
		private var _value:int;
		private var _name:String;
		private var _bit64:Boolean;
		
		public function OS( value:int, name:String, bit64:Boolean = false ):void
		{
			_value = value;
			_name  = name;
			_bit64 = bit64;
		}
		
		/**
		 * Will auto-detect which Operating System you are running
		 * and will return the appropriate constant or <code>unknown</code> if not found.
		 */
		public static function autodetect():OS
		{
			var str:String = Runtime.platform;
			
			if( Runtime.is64bit() )
			{
				str += "64";
			}
			
			if( str.length < 4 )
			{
				str = "unknown";
			}
			
			return OS[str];
		}
		
		public function get name():String
		{
			return _name;
		}
		
		public function get bits():String
		{
			var b:String = "";
			
			if( name == "unknown" )
			{
				return b;
			}
			
			if( _bit64 )
			{
				b = "64";
			}
			else
			{
				b = "32";
			}
			
			return b;
		}
		
		/**
		 * Returns a string representation of the target.
		 */
		public function toString():String
		{
			return "OS." + name + bits;
		}
		
		/**
		 * Returns a unique value.
		 */
		public function valueOf():int
		{
			return _value;
		}
	}
	
}