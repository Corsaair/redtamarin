package redbean.utils
{
    /** @private */
	public function copyObject( source:Object, destination:Object ):void
	{
		var member:String;
		for( member in source )
		{
			destination[member] = source[member];
			//trace( "copying [" + member + "] = " + destination[member] );
		}
	}
}