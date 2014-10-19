package redbean.core
{
	import C.sys.stat.*;
	import C.unistd.*;

	/**
	 * @private
     * Check if we can find the SDK
	 */
	public function verifySDK( sdk:String ):Boolean
	{
		if( sdk == "" )
		{
			return false;
		}
		
		var exists:Boolean = access( sdk, F_OK ) == 0;
		var bufstat:status = new status();
		stat( sdk, bufstat );
		var isdir:Boolean  = S_ISDIR( bufstat.st_mode );
		
		return exists && isdir;
	}
}