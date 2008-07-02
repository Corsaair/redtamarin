package flash.system
{
    import avmplus.System;
    
    public final class Capabilities
    {
		public static function get playerType():String
		{
		    return "AVMPlus";
		}
		
		public static function get isDebugger():Boolean
		{
		    return avmplus.System.isDebugger();
		}

    }
}