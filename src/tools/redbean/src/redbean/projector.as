package redbean
{
	import C.sys.stat.*;
	
	import flash.utils.ByteArray;
	
	import redbean.core.findWith;
	import redbean.utils.bytesToHumanReadable;
	import redbean.utils.copyObject;
	
	import shell.FileSystem;

	/**
	 * Creates an executable projector.
	 * 
     * <p>
     * TODO
     * </p>
     * 
	 * @langversion 3.0
	 * @playerversion AVM 0.4
	 */
	public function projector( name:String, debug:Boolean = false, target:OS = null, filepath:Array = null ):void
	{
		if( target == null )
		{
			target = OS.autodetect();
		}
        
		var obj:Object = {};
		copyObject( _globals.strings, obj );
		obj.platform = target.name;
		obj.bits     = target.bits;
		obj.exe      = (obj.platform == "windows") ? ".exe": "";
		
		name += obj.exe;
        
        if( !_globals.quietMode )
        {
            trace( "[projector] " + name + " : " + target.toString() );
        }
        
		var avmshell_name:String;
		if( debug )
		{
			if( _globals.useDebugger )
			{
				avmshell_name = "redshell_dd";
			}
			else
			{
				avmshell_name = "redshell_d";
			}
		}
		else
		{
			avmshell_name = "redshell";
		}
		
        if( !filepath )
        {
            filepath = [];
        }
        
        var container:String;
		var len:uint = filepath.length;
		var data:ByteArray;
		if( len > 1 )
		{
            container = "SWF";
			var abc_files:Array = filepath;
			var swf:ByteArray = makeswf( false, abc_files );
			//FileSystem.writeByteArray( name + ".swf", swf );
			data = swf;
		}
		else
		{
			container = "ABC";
            var one_file:String = filepath[0];
			var abc:ByteArray = FileSystem.readByteArray( one_file );
			data = abc;
		}
        
        if( !_globals.quietMode && _globals.verboseMode )
        {
            trace( "[container] " + container + " = " + filepath.join( ", " ) );
        }
		
        
		var avmshell_exe:String = findWith( avmshell_name, obj );
		
		//do the work
		var bytesWritten:uint = 0;
		//trace( bytesWritten + " bytes written" );
		
		var exe_in:ByteArray  = FileSystem.readByteArray( avmshell_exe );
		var file_in:ByteArray = data;
		var file_len:uint     = file_in.length;
		
		var exe_out:ByteArray = new ByteArray();
		
		exe_out.writeBytes( exe_in );
		bytesWritten += exe_in.length;
		//trace( bytesWritten + " bytes written" );
		
		exe_out.writeBytes( file_in );
		bytesWritten += file_len;
		//trace( bytesWritten + " bytes written" );
		
		//projector signature
		var header:ByteArray = new ByteArray(); //always 8 bytes
		header.writeByte( 0x56 );
		header.writeByte( 0x34 );
		header.writeByte( 0x12 );
		header.writeByte( 0xFA );
		header.writeByte(  file_len      & 0xFF );
		header.writeByte( (file_len>>8)  & 0xFF );
		header.writeByte( (file_len>>16) & 0xFF);
		header.writeByte( (file_len>>24) & 0xFF );
		
		exe_out.writeBytes( header );
		bytesWritten += 8;
		//trace( bytesWritten + " bytes written" );
		
		exe_out.position = 0;
		var written:Boolean = FileSystem.writeByteArray( name, exe_out );
		
		if( written )
		{
            if( !_globals.quietMode )
            {
                trace( "[file] " +  name + ", " + bytesToHumanReadable( bytesWritten ) + " written" );
            }
			chmod( name, ACCESSPERMS );
		}
		else
		{
			trace( "[error] Could not create \"" + name + "\"" );
		}
	}
}