/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package shell
{
	import C.unistd.*;

    /**
     * The FileSystem class
     * Provides methods to access and manipulate computer files, directories, paths and data.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native(cls="::avmshell::FileSystemClass", methods="auto", construct="none")]
	public class FileSystem
	{

		//public native static function isWindowsStore():Boolean;

		/**
		 * Tests whether a <code>filename</code> exists.
		 * 
		 * @param  filename The filename to test.
		 * @return <code>true</code> if the file exists otherwise <code>false</code>.
		 *
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function exists( filename:String ):Boolean
		{
			return access( filename, F_OK ) == 0;
		}

		/**
		 * Reads the file <code>filename</code> into memory
		 * and returns it as a <code>String</code>.
		 *
		 * Supports UTF-8 files with or without BOM,
		 * as well as UTF-16 files.
		 * 
		 * @param  filename The filename to read.
		 * @return the string data contained in the filename.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public native static function read( filename:String ):String;
	}

}
