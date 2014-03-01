/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package shell
{

    /**
     * The RunMode class defines string constants for the names of Execution Engine run modes.
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
	public final class RunMode
	{

		/**
		 * The unknown mode.
		 */
		public static const UNKNOWN:String = "unknown";

		/**
		 * The <b>mixed</b> mode (interpreter + JIT) <code>default</code>.
		 * 
		 * <p>
		 * This mode is governed by the "On-Stack Replacement" (OSR) threshold.
		 * </p>
		 */
		public static const MIXED:String = "mixed";

		/**
		 * The <b>JIT or die</b> mode (always use JIT, abort if JIT fails).
		 */
		public static const JITORDIE:String = "jitordie";

		/**
		 * The <b>Just In Time</b> mode (always use JIT, never interp unless the JIT fails).
		 */
		public static const JIT:String = "jit";

		/**
		 * The <b>interpreter</b> mode (never use JIT).
		 */
		public static const INTERP:String = "interp";

	}

}
