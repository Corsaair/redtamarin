package redbean
{
	import flash.utils.ByteArray;
	import flash.utils.Endian;
	
	import shell.FileSystem;

	/**
	 * Creates a SWF file.
	 * 
	 * <p>
	 * The <code>redshell</code> can read either ABC files or SWF files
	 * for example:
	 * </p>
	 * 
	 * <listing>
	 *  $ ./redshell program.abc
	 *  $ ./redshell lib1.abc lib2.abc program.abc
	 *  $ ./redshell program.swf
	 * </listing>
	 * 
	 * <p>
	 * As it is not very convenient to pass a lot of ABC files
	 * we use a SWF files to 'merge' those ABC files together.
	 * 
	 * This also allow us to create executable projectors with more
	 * than one ABC file.
	 * </p>
	 * 
	 * <p>
	 * <b>IMPORTANT</b>: your main program need to be the last ABC file.
	 * </p>
	 * 
	 * @param compress If <code>true</code> returns a compressed SWF; otherwise returns a non-compressed SWF.
	 * @param abcfiles A list of ABC files.
     * 
     * @return A <code>SWF</code> binary as a <code>ByteArray</code>.
	 * 
	 * @langversion 3.0
	 * @playerversion AVM 0.4
     * 
     * @see redbean.projector()
	 */
	public function makeswf( compress:Boolean = false, abcfiles:Array = null ):ByteArray
	{
        if( !abcfiles )
        {
            abcfiles = [];
        }
                
		var body:ByteArray = new ByteArray();
			body.endian = Endian.LITTLE_ENDIAN;
			body.writeByte(2 << 3);   // RECT: 2 bits per dim
			body.writeByte(0);        //   and they're all zero
			body.writeShort(0);       // framerate
			body.writeShort(0);       // framecount
		
		var len:uint = abcfiles.length;
		var i:uint;
		var j:uint;
		var abc:String;
        
        if( !_globals.quietMode )
        {
            trace( "[makeswf] " + len + " files" );
        }
        
        if( len == 0 )
        {
            return null;
        }
        
		for( i = 0; i < len; i++ )
		{
			abc = abcfiles[i];
			
			var bytes = FileSystem.readByteArray( abc ); //read the abc file
			body.writeShort((82 << 6) | 63);  // DoABC, extended length
			body.writeUnsignedInt( bytes.length + 4 + abc.length + 1 );
			body.writeUnsignedInt(0);         // flags
			for ( j=0 ; j < abc.length ; j++ )
			{
				body.writeByte( abc.charCodeAt(j) & 255 );
			}
			
			body.writeByte(0);
			body.writeBytes( bytes );
		}
		
			body.writeShort(0); // End
		
		var numbytes = body.length + 8;
		
		if( compress )
		{
			body.compress();
		}
		
		var compress_letter:String = compress ? 'C' : 'F';
		var compress_option:uint   = compress_letter.charCodeAt(0);
		var W:uint = "W".charCodeAt(0);
		var S:uint = "S".charCodeAt(0);
		
		var swf:ByteArray = new ByteArray();
		swf.endian = Endian.LITTLE_ENDIAN;
		swf.writeByte( compress_option );
		swf.writeByte( W );
		swf.writeByte( S );
		swf.writeByte( 9 );
		swf.writeUnsignedInt( numbytes );
		swf.writeBytes( body );
		
		return swf;
	}
}