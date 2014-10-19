package
{
	/* NOTE:
	   when we use eval()
	   only public var declared in the unamed package are considered globals
	   so here we create this "_globals" object
	   so we can read/write to it
	   to exchange data from/to evalued scripts
	*/
    /** @private */
	public var _globals:Object = {};
}