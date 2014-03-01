/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package shell
{
	import flash.utils.ByteArray;
	import flash.utils.describeType;

    /**
     * Allows to create a subclass with metadata to embed binary data.
     * 
     * <p>
     * To define the binary uses the metadata <code>[HexData]</code>.
     * </p>
     * 
     * <p>
     * You will need to use the <code>-md</code> option when compiling with ASC.
     * </p>
     * 
     * @example Usage
     * <listing>
     * import shell.BinaryData;
     * import flash.utils.ByteArray;
     * 
     * // define a class that extend BinaryData
     * // and use the metadata to define the binary in hexadecimal
     * [HexData("aabbccdd")]
     * public class BlobOfData extends BinaryData
     * {
     * }
     * 
     * 
     * // then later, instanciate the class
     * var binary:BlobOfData = new BlobOfData();
     * 
     * // to get the original data, you can copy it
     * var original1:ByteArray = new ByteArray();
     *     original1.writeBytes( binary, 0, binary.length );
     * 
     * // or you can downcast it
     * var original2:ByteArray = binary as ByteArray;
     * </listing>
     * 
     * @example Compilation
     * <listing>
     * java -jar asc.jar -AS3 -md -import redtamarin.abc test.as
     * 
     * </listing>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
	public class BinaryData extends ByteArray
	{
		public function BinaryData()
		{
			var md:XML = describeType( this );
			var bdList:XMLList = md..metadata.(@name == "HexData");

			for each( var bd:XML in bdList )
			{
				var argList:XMLList = bd..arg.(@key == "");

				for each(var arg:XML in argList)
				{
					var hex:String = arg.@value;
					var len:uint   = hex.length

					//the way crossbrdige doing it
					/*
					for (var i:uint = 0; i < len; i += 2)
					{
						var c1:int = hex.charCodeAt(i)
						var c2:int = hex.charCodeAt(i+1)
						var result:int = 0

						if(c1 < 58) result = c1 - 48
						else if(c1 < 71) result = 10 + (c1 - 65)
						else if(c1 < 103) result = 10 + (c1 - 97)

						result *= 16

						if(c2 < 58) result += c2 - 48
						else if(c2 < 71) result += 10 + (c2 - 65)
						else if(c2 < 103) result += 10 + (c2 - 97)
						
						trace( i + " = [" + result + "]" );
						writeByte( result );
					}
					*/
					
					//the way redtamarin doing it ;)
					for( var i:uint = 0; i < len; i += 2 )
					{
						var b:String = hex.substr( i , 2 );
						var result:int = Number( "0x" + b );
						//trace( "0x"+b + " = [" + result + "]" ); //debug
						writeByte( result );
					}
					
				}
			}

			position = 0;
		}

	}

}
