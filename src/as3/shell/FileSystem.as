/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package shell
{
	import C.errno.*;
	import C.stdio.*;
	import C.stdlib.*;
	import C.limits.*;
	import C.unistd.*;
	import C.dirent.*;
	import C.sys.stat.*;

	import shell.Runtime;

	import flash.utils.ByteArray;

    /**
     * The FileSystem class
     * Provides methods to access and manipulate computer files, directories, paths and data.
     *
     * <p>
     * A <b>filename</b> uniquely identify a file or directory stored on the file system.
     * </p>
     *
     * <p>
     * A <b>filepath</b> identify a path to a directory stored on the file system.
     * </p>
     *
     * <p>
     * A <b>component</b> is a name of a part composing a filename exluding the separators.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native(cls="::avmshell::FileSystemClass", methods="auto", construct="none")]
	public class FileSystem
	{

		private static var _win32_separators:Array  = [ "\\", "/" ];
		private static var _posix_separators:Array  = [ "/" ];

		private static var _win32_pathsep:String    = ";";
		private static var _posix_pathsep:String    = ":";

		private static var _win32_lineEnding:String = "\r\n";
		private static var _posix_lineEnding:String = "\n";

		private static var _posix_alt_home:Array  = [ "/var/users/",
													  "/u01/",
													  "/usr/",
													  "/user/",
													  "/users/",
													  "/Users/"
													];

		private static var _win32_reserved_chars:Array = [ "<",
														   ">",
														   ":",
														   "\"",
														   "/",
														   "\\",
														   "|",
														   "?",
														   "*",
														   "^"
														 ];
		private static var _win32_reserved_words:Array = [ "CON", "PRN", "AUX", "NUL",
														   "COM1", "COM2", "COM3", "COM4",
														   "COM5", "COM6", "COM7", "COM8", "COM9",
														   "LPT1", "LPT2", "LPT3", "LPT4",
														   "LPT5", "LPT6", "LPT7", "LPT8", "LPT9"
														 ];
		private static var _macosx_reserved_chars:Array = [ ":", "/" ];
		private static var _linux_reserved_chars:Array = [ "/" ];


		private static var _rootDirectory:String;
		private static var _homeDirectory:String;



		/* windows, macintosh only */
		private native static function _isAttributeHidden( filename:String ):Boolean;

		/* windows only */
		private native static function _getLogicalDrives():int;

		private static function _findLogicalDrives():Array
		{
			var drives:Array = [];

			switch( Runtime.platform )
			{
				case "windows":
				var mask:int    = 1;
				var bits:int    = _getLogicalDrives();
				var base:Number = "A".charCodeAt(0);
				var i:uint;
				for( i = 0; i < 26; i++ )
				{
					if( bits & mask )
					{
						drives.push( String.fromCharCode( base+i ) + ":" );
					}

					mask <<= 1;
				}
				return drives;
				break;

				case "macintosh":
				case "linux":
				default:
				return drives;
			}
		}

		private static function _findRootDirectory():String
		{
			var root:String = "";

			switch( Runtime.platform )
			{
				case "windows":
				var tmp = getenv( "SYSTEMDRIVE" ); // %SYSTEMDRIVE% should return "C:"
				if( tmp == "" )
				{
					tmp = "C:"; //we use "C:" by default
				}

				if( !endsWithSeparator( tmp ) )
				{
					tmp = ensureEndsWithSeparator( tmp ); //eg. C:\\
				}

				root = tmp;
				break;

				case "macintosh":
				case "linux":
				default:
				root = "/"; //always '/' for POSIX
			}

			return root;
		}

		private static function _findHomeDirectory():String
		{
			var home:String = "";

			switch( Runtime.platform )
			{
				case "windows":
				home = getenv( "USERPROFILE" );
				if( home == "" )
				{
					//TODO
					//alternative
				}
				break;

				case "macintosh":
				case "linux":
				default:
				home = getenv( "HOME" );

				if( home == "" )
				{
					var username:String = getlogin();

					var i:uint;
					for( i = 0; i < _posix_alt_home.length; i++ )
					{
						home = _posix_alt_home[i] + username;
						if( isDirectory( home ) )
						{
							break;
						}
					}
				}
			}

			return home;
		}

		// apply a regexp and return a filter array function
		private static function _filterWithRegexp( filter:RegExp ):Function
		{
			return function( element:*, index:int, arr:Array ):Boolean { return filter.test( element ); }
		}

		/* properties */

		/**
		 * The character used to identify a file extension.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static const extensionSeparator:String = ".";

		/**
		 * A special path component meaning "this directory".
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static const currentDirectory:String = ".";

		/**
		 * A special path component meaning "the parent directory".
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static const parentDirectory:String = "..";

		/**
		 * The list of drives.
		 *
		 * <p>
		 * Always empty on Macintosh and Linux.
		 * </p>
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 * @playerversion WIN +
		 */
		public static function get drives():Array
		{
			/* NOTE:
			   we do not want to cache this value
			   as under Windows the number of drives
			   can change (eg. plugged in new USB drive)
			*/
			return _findLogicalDrives();
		}

		/**
		 * The line-ending character sequence used by the host operating system.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function get lineEnding():String
		{
			/* TODO:
			   If I remember well under a CLI le line ending is always "\n"
			   even under WIndows, so maybe add an option to switch to
			   CLI line ending.
			*/
			
			switch( Runtime.platform )
			{
				case "windows":
				return _win32_lineEnding;

				case "macintosh":
				case "linux":
				default:
				return _posix_lineEnding;
			}
		}

		/**
		 * The system root directory.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function get rootDirectory():String
		{
			if( _rootDirectory ) { return _rootDirectory; }

			_rootDirectory = _findRootDirectory();
			return _rootDirectory;
		}

		/**
		 * The user home directory.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function get homeDirectory():String
		{
			if( _homeDirectory ) { return _homeDirectory; }

			_homeDirectory = _findHomeDirectory();
			return _homeDirectory;
		}

		/**
		 * The character separators used by the operating system.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function get separators():Array
		{
			switch( Runtime.platform )
			{
				case "windows":
				return _win32_separators;

				case "macintosh":
				case "linux":
				default:
				return _posix_separators;
			}
		}

		/**
		 * The path separator used by the operating system.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function get pathSeparator():String
		{
			switch( Runtime.platform )
			{
				case "windows":
				return _win32_pathsep;

				case "macintosh":
				case "linux":
				default:
				return _posix_pathsep;
			}
		}


		/* file and directory native manipulation */

		/**
		 * Reads the file <code>filename</code> into memory
		 * and returns it as a <code>String</code>.
		 *
		 * <p>
		 * Supports UTF-8 files with or without BOM,
		 * as well as UTF-16 files.
		 * </p>
		 *
		 * <p>
		 * Does not support UTF-8 filename under Windows.
		 * </p>
		 * 
		 * @param filename The filename to read.
		 * @return the string data contained in the filename.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public native static function nativeRead( filename:String ):String;

		/**
		 * Writes the text <code>data</code> to the file <code>filename</code>.
		 *
		 * <p>
		 * Does not support UTF-8 filename under Windows.
		 * </p>
		 * 
		 * @param filename The filename to write.
		 * @param data the string data to write into the file.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public native static function nativeWrite( filename:String, data:String ):void;

		/**
		 * Reads the binary file <code>filename</code> into memory
		 * and returns it as a <code>ByteArray</code>.
		 *
		 * <p>
		 * Does not support UTF-8 filename under Windows.
		 * </p>
		 * 
		 * @param filename The filename to read.
		 * @return the <code>ByteArray</code> data contained in the filename.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public native static function nativeReadByteArray( filename:String ):ByteArray;

		/**
		 * Writes the binary <code>bytes</code> to the file <code>filename</code>
		 * and returns <code>true</code> on success.
		 *
		 * <p>
		 * Does not support UTF-8 filename under Windows.
		 * </p>
		 * 
		 * @param filename The filename to write.
		 * @param bytes the binary data to write into the file.
		 * @return <code>true</code> if wirtten successfully, otherwise <code>false</code>.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public native static function nativeWriteByteArray( filename:String, bytes:ByteArray ):Boolean;



		/* path manipulation */

		/**
		 * Returns the absolute path of <code>filename</code>.
		 * 
		 * @param  filename The filename to transform.
		 * @return the filename as an absolute path.
		 *
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function absolutePath( filename:String ):String
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			return realpath( normalizePath( filename ) );
		}
		
		/**
		 * Normalizes the separators of the <code>filename</code>.
		 * 
		 * @param  filename The filename to transform.
		 * @return the filename as an normalized path (all separators are the same).
		 *
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function normalizePath( filename:String ):String
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			var sep:String;

			switch( Runtime.platform )
			{
				case "windows":
				sep = _posix_separators[0];
				break;

				case "macintosh":
				case "linux":
				default:
				sep = _win32_separators[0];
			}

			if( filename.indexOf( sep ) > -1 )
			{
				filename = filename.split( sep ).join( separators[0] );
			}

			return filename;
		}

		/**
		 * Returns a filepath corresponding to the last path component
		 * of this <code>filename</code>, either a file or a directory.
		 * 
		 * @param  filename The filename to operate on.
		 * @return the basename of this filename.
		 *
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function getBasenameFromPath( filename:String ):String
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			var path:String = stripTrailingSeparators( filename );

			if( hasDriveLetter( path ) )
			{
				path = path.substr( 2 ); // eg. C:
			}

			var last:int = path.lastIndexOf( separators[0] );

			/* NOTE:
			   Keep everything after the final separator, but if the pathname is only
			   one character and it's a separator, leave it alone.
			*/
			if( (path.length > 1) && (last >= 0) )
			{
				if( !isSeparator( path.charAt(1) ) )
				{
					path = path.substr( last+1 );
				}
			}

			return path;
		}

		/**
		 * Returns the directory component of a <code>filename</code>
		 * without the trailing path separator, or an empty string on error.
		 * 
		 * @param  filename The filename to operate on.
		 * @return the filename with only its directory component.
		 *
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function getDirectoryFromPath( filename:String ):String
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			var endSeparator:String = "";
			var haveEndSeparator:Boolean = isSeparator( filename.charAt( filename.length-1 ) );

			if( haveEndSeparator )
			{
				endSeparator = filename.charAt( filename.length-1 );
			}

			var path:String = stripTrailingSeparators( filename );
				path += endSeparator;

			var start:String = "";
			var dir:String   = "";

			if( hasDriveLetter( path ) )
			{
				start = path.substring( 0, 2 );
				dir   = path.substr( 2 );
			}
			else if( isSeparator( path.charAt(0) ) )
			{
				start = path.substring( 0, 1 );
				dir   = path.substr( 1 );
			}
			else
			{
				dir = path;
			}

			if( (dir != "") && (dir.length > 1) )
			{
				var last:int = dir.lastIndexOf( separators[0] );

				if( (last > 0) && !isSeparator(dir.charAt(0)) )
				{
					dir = dir.substring( 0, last );
				}
			}

			return start+dir;
		}

		/**
		 * Returns the components of a <code>filename</code>.
		 * 
		 * @param  filename The filename to operate on.
		 * @return AN <code>Array</code> of components.
		 *
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function getComponentsFromPath( filename:String ):Array
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			var start:String = "";
			var path:String  = "";

			if( hasDriveLetter( filename ) )
			{
				start = filename.substring( 0, 2 );
				path  = filename.substr( 2 );
			}
			else if( isSeparator( filename.charAt(0) ) )
			{
				start = filename.substring( 0, 1 );
				path  = filename.substr( 1 );
			}
			else
			{
				path = filename;
			}

			if( path == "" )
			{
				throw new Error( "filename is empty" );
			}
			else if( (path == "") && (start.length > 0) )
			{
				throw new Error( "filename is root" );	
			}

			var paths:Array;
			if( path.indexOf( separators[0] ) > -1 )
			{
				path = stripTrailingSeparators( path );
				paths = path.split( separators[0] );
			}
			else
			{
				paths = [ path ];
			}

			return paths;
		}

		/**
		 * Tests if a parent filename contains a child filename. 
		 *
		 * <p>
		 * Both paths are converted to absolute paths before doing the comparison.
		 * </p>
		 * 
		 * @param  parent The filename considered as the parent or container.
		 * @param  child  The filename considered as the child or containee.
		 * @return <code>true</code> if <code>parent</code> contains <code>child</code>,
		 *         otherwise <code>false</code>.
		 *
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function containsPath( parent:String, child:String ):Boolean
		{
			if( !parent )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "parent" );
			}

			if( !child )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "child" );
			}

			var abs_parent:String = absolutePath( parent );
			var abs_child:String  = absolutePath( child );

			if( (abs_parent.length <= abs_child.length) && (abs_child.indexOf( abs_parent ) == 0) )
			{
				return true;
			}

			return false;
		}


		/* file and directory manipulation */

		/**
		 * Creates a text file <code>filename</code>.
		 *
		 * <p>
		 * More exactly it is opening a file for writing,
		 * if it does not exists then a new file is created.
		 * </p>
		 * 
		 * @param filename The filename to create.
		 * @param useBOM if <code>true</code> write an UTF-8 BOM.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function create( filename:String, useBOM:Boolean = false ):void
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			var fp:FILE = fopen( filename, "w" );

			if( !fp )
			{
				Error.throwError( Error, Errors.kFileWriteError, filename );
			}

			if( useBOM )
			{
				var bytes:ByteArray = new ByteArray();
					bytes.writeByte( 0xef );
					bytes.writeByte( 0xbb );
					bytes.writeByte( 0xbf );

					bytes.position = 0;

				var blen:uint = bytes.length;
				var wrote:int = fwrite( bytes, blen, fp );

				if( wrote != blen )
				{
					Error.throwError( Error, Errors.kFileWriteError, filename );
				}

				fflush( fp );
				bytes.clear();
			}
			
			fclose( fp );
		}

		/**
		 * Creates a binary file <code>filename</code>
		 * and returns <code>true</code> on success.
		 *
		 * <p>
		 * More exactly it is opening a file for writing,
		 * if it does not exists then a new file is created.
		 * </p>
		 * 
		 * @param filename The filename to write.
		 * @return <code>true</code> if created successfully, otherwise <code>false</code>.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function createByteArray( filename:String ):Boolean
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			var fp:FILE = fopen( filename, "wb" );

			if( !fp )
			{
				Error.throwError( Error, Errors.kFileWriteError, filename );
			}

			var success:Boolean = true;

			fclose( fp );
			return success;
		}

		/**
		 * Creates a directory path from <code>filename</code>,
		 * iterates trough the path components and create the missing directories if needed.
		 *
		 * <p>
		 * If you only provide a single path component e. <code>createDirectory("test")</code>
		 * it creates a single directory in your current path.
		 * </p>
		 * 
		 * @param filename The filename of the directory to create.
		 * @return <code>true</code> if created successfully, otherwise <code>false</code>.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function createDirectory( filename:String ):Boolean
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			var start:String = "";
			var path:String  = "";

			if( hasDriveLetter( filename ) )
			{
				start = filename.substring( 0, 2 );
				path  = filename.substr( 2 );
			}
			else if( isSeparator( filename.charAt(0) ) )
			{
				start = filename.substring( 0, 1 );
				path  = filename.substr( 1 );
			}
			else
			{
				path = filename;
			}

			var paths:Array;
			if( path.indexOf( separators[0] ) > -1 )
			{
				path = stripTrailingSeparators( path );
				paths = path.split( separators[0] );
			}
			else
			{
				paths = [ path ];
			}

			var last:String = "";
			var last_path:String = "";
			var result:int;
			while( paths.length > 0 )
			{
				last += paths.shift() + separators[0];
				last_path = start + last;

				if( isDirectory( last_path ) )
				{
					continue;
				}

				result = mkdir( last_path );
				if( result < 0 )
				{
					throw new CError( errno );
				}

				if( !isDirectory( last_path ) )
				{
					return false;
				}
			}

			return true;
		}

		/**
		 * Copy an <code>origin</code> file
		 * to a <code>destination</code> file
		 * and returns <code>true</code> on success.
		 *
		 * <p>
		 * This method cannot handle files bigger than <code>2 GB</code>,
		 * or <code>2147483647 bytes</code> or <code>MAX_INT</code>
		 * or <code>int.MAX_VALUE</code>.
		 * </p>
		 * 
		 * @param origin The origin filename to copy from.
		 * @param destination The destination filename to copy into.
		 * @param overwrite if <code>true</code> overwrite an already existing destination.
		 * @param copyMode if <code>true</code> copy also the filename mode.
		 * @return <code>true</code> if the file copied successfully
		 *         otherwise <code>false</code>.
		 *
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function copyFile( origin:String, destination:String,
										 overwrite:Boolean = false,
										 copyMode:Boolean = false ):Boolean
		{
			if( !origin )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "origin" );
			}

			if( !destination )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "destination" );
			}

			if( !exists( origin ) )
			{
				throw new Error( "Can not copy file \"" + origin + "\" as it does not exists." );
			}

			if( exists( destination ) && !overwrite )
			{
				throw new Error( "Can not copy file \"" + origin + "\" over already existing \"" + destination + "\"." );
			}

			if( isDirectory( origin ) )
			{
				throw new Error( "Can not copy from a directory \"" + origin + "\" to a file." );
			}

			if( exists( destination ) && isDirectory( destination ) )
			{
				throw new Error( "Can not copy a file \"" + origin + "\" to a directory \"" + destination + "\"." );
			}

			var bytes:ByteArray = readByteArray( origin );
			var result:Boolean  = writeByteArray( destination, bytes );
			if( !result )
			{
				return false;
			}

			if( copyMode )
			{
				var mode:int = getFileMode( origin );
				var changed:int = chmod( destination, mode );
				if( changed < 0 )
				{
					throw new CError( errno );
				}
			}

			return true;
		}

		/**
		 * Copy all files matching the <code>filter</code>
		 * from directory <code>origin</code>
		 * to <code>destination</code> directory
		 * and returns <code>true</code> on success.
		 *
		 * <p>
		 * This method cannot handle files bigger than <code>2 GB</code>,
		 * or <code>2147483647 bytes</code> or <code>MAX_INT</code>
		 * or <code>int.MAX_VALUE</code>.
		 * </p>
		 * 
		 * @param origin The origin filename to copy from.
		 * @param destination The destination filename to copy into.
		 * @param filter The regular expression used to filter the results,
		 *        default is <code>/.&#42;/</code> (eg. all files).
		 * @param overwrite if <code>true</code> overwrite an already existing destination.
		 * @param noHidden if <code>true</code>(default) do not copy hidden entries.
		 * @param copyMode if <code>true</code> copy also the filename mode.
		 * @return <code>true</code> if all the files copied successfully
		 *         otherwise <code>false</code>.
		 *
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function copyFiles( origin:String, destination:String,
										  filter:RegExp = null,
										  overwrite:Boolean = false,
										  noHidden:Boolean = true,
										  copyMode:Boolean = false ):Boolean
		{
			if( !origin )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "origin" );
			}

			if( !destination )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "destination" );
			}

			if( !exists( origin ) )
			{
				throw new Error( "Can not copy files from directory \"" + origin + "\" as it does not exists." );
			}

			if( !exists( destination ) )
			{
				throw new Error( "Can not copy files to directory \"" + destination + "\" as it does not exists." );
			}

			if( !isDirectory( origin ) )
			{
				throw new Error( "Can not list files from origin, \"" + origin + "\" is not a directory." );
			}

			if( !isDirectory( destination ) )
			{
				throw new Error( "Can not copy files to destination, \"" + destination + "\" is not a directory." );
			}

			if( !filter )
			{
				filter = /.*/; //default filter, all the files
			}

			var files:Array = listFilesWithRegexp( origin, filter, true, noHidden );

			if( endsWithSeparator( destination ) )
			{
				destination = stripTrailingSeparators( destination );
			}

			var origin_file:String;
			var dest_file:String;
			var basename:String;
			var copied:Boolean;
			var i:uint;
			for( i = 0; i < files.length; i++ )
			{
				basename    = files[i];
				origin_file = origin + separators[0] + basename;
				dest_file   = destination + separators[0] + basename;

				copied = copyFile( origin_file, dest_file, overwrite, copyMode );
				if( !copied )
				{
					return false;
				}
			}

			return true;
		}

		/**
		 * Copy by chunk of <code>buffer</code>
		 * an <code>origin</code> file
		 * to a <code>destination</code> file
		 * and returns <code>true</code> on success.
		 *
		 * <p>
		 * This method cannot handle files bigger than <code>2 GB</code>,
		 * or <code>2147483647 bytes</code> or <code>MAX_INT</code>
		 * or <code>int.MAX_VALUE</code>.
		 * </p>
		 * 
		 * @param origin The origin filename to copy from.
		 * @param destination The destination filename to copy into.
		 * @param buffer The size of the buffer in bytes.
		 * @param overwrite if <code>true</code> overwrite an already existing destination.
		 * @param copyMode if <code>true</code> copy also the filename mode.
		 * @return <code>true</code> if the file copied successfully
		 *         otherwise <code>false</code>.
		 *
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function bufferedCopyFile( origin:String, destination:String,
										 		 buffer:int = 0,
										 		 overwrite:Boolean = false,
										 		 copyMode:Boolean = false ):Boolean
		{
			if( !origin )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "origin" );
			}

			if( !destination )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "destination" );
			}

			if( !exists( origin ) )
			{
				throw new Error( "Can not copy file \"" + origin + "\" as it does not exists." );
			}

			if( exists( destination ) && !overwrite )
			{
				throw new Error( "Can not copy file \"" + origin + "\" over already existing \"" + destination + "\"." );
			}

			if( isDirectory( origin ) )
			{
				throw new Error( "Can not copy from a directory \"" + origin + "\" to a file." );
			}

			if( exists( destination ) && isDirectory( destination ) )
			{
				throw new Error( "Can not copy a file \"" + origin + "\" to a directory \"" + destination + "\"." );
			}


			var fp:FILE = fopen( origin, "rb" );

			if( !fp )
			{
				Error.throwError( Error, Errors.kFileOpenError, origin );
			}

			
			var lookup:int = fseek( fp, 0, SEEK_END );
			if( lookup < 0 )
			{
				throw new CError( errno );
			}
			var fileSize:Number = ftell( fp );
			fseek( fp, 0, SEEK_SET );
			
			/* NOTE:
			   ByteArray APIs cannot handle files > 4GB
			   but fseek() can not read past MAX_INT (2GB)
			   so here we set the limit accordingly
			*/
			if( fileSize >= INT_MAX )
			{
				Error.throwError( RangeError, Errors.kOutOfRangeError, origin );
			}

			var destp:FILE = fopen( destination, "wb" );

			if( !destp )
			{
				Error.throwError( Error, Errors.kFileOpenError, destination );
			}

			/* NOTE:
			   ByteArrya use a threshold of 24MB to switch to large-size handling,
			   which is incremented every 24MB.
			
			   For files < 24MB we use a buffer of 512KB
			   for files > 24MB we use a buffer of 24MB
			*/
			const b512KB:int = 512 * 1024;
			const b24MB:int  = 24 * 1024 * 1024;

			var copylen:uint = uint(fileSize);

			var actualr:int;
			var actualw:int;
			var reading:ByteArray = new ByteArray();
			
			var maxcopy:int;
			if( buffer > 0 )
			{
				maxcopy = buffer;
			}
			else
			{
				if( copylen >= b24MB )
				{
					maxcopy = b24MB;
				}
				else
				{
					maxcopy = b512KB;
				}
			}

			while( copylen > 0 )
			{
				reading.clear();
				actualr = fread( reading, maxcopy, fp );
				if( actualr > 0)
				{
					reading.position = 0;
					actualw = fwrite( reading, actualr, destp );
					copylen -= actualr;
				}
				else
				{
					break;
				}
			}
			
			reading.clear();
			var success:Boolean = (actualw < 0) ? false: true;

			if( !success )
			{
				Error.throwError( Error, Errors.kFileWriteError, destination );
			}
			
			fflush( fp );
			fclose( fp );
			fflush( destp );
			fclose( destp );
			return success;
		}

		/**
		 * Copy by chunk of <code>buffer</code>
		 * an <code>origin</code> file
		 * to a <code>destination</code> file
		 * and returns <code>true</code> on success.
		 *
		 * <p>
		 * this works like <code>bufferedCopyFile()</code>
		 * except here we don't check for files boundaries,
		 * technically any file size could be copied
		 * provided the system have the ressources and
		 * provided you are ready to wait long enough for
		 * the file to be copied.
		 * </p>
		 * 
		 * @param origin The origin filename to copy from.
		 * @param destination The destination filename to copy into.
		 * @param buffer The size of the buffer in bytes.
		 * @param overwrite if <code>true</code> overwrite an already existing destination.
		 * @param copyMode if <code>true</code> copy also the filename mode.
		 * @return <code>true</code> if the file copied successfully
		 *         otherwise <code>false</code>.
		 *
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function bufferedFastCopyFile( origin:String, destination:String,
										 		     buffer:int = 0,
										 		     overwrite:Boolean = false,
										 		     copyMode:Boolean = false ):Boolean
		{
			if( !origin )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "origin" );
			}

			if( !destination )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "destination" );
			}

			if( !exists( origin ) )
			{
				throw new Error( "Can not copy file \"" + origin + "\" as it does not exists." );
			}

			if( exists( destination ) && !overwrite )
			{
				throw new Error( "Can not copy file \"" + origin + "\" over already existing \"" + destination + "\"." );
			}

			if( isDirectory( origin ) )
			{
				throw new Error( "Can not copy from a directory \"" + origin + "\" to a file." );
			}

			if( exists( destination ) && isDirectory( destination ) )
			{
				throw new Error( "Can not copy a file \"" + origin + "\" to a directory \"" + destination + "\"." );
			}


			var fp:FILE = fopen( origin, "rb" );

			if( !fp )
			{
				Error.throwError( Error, Errors.kFileOpenError, origin );
			}

			/* NOTE:
			   using stat() to get the file size allows
			   to overcome the INT_MAX limitation of fseek()/feteel()
			   and the UINT_MAX limitation of fseeko()/ftello()
			*/
			var info:status = new status();
			var result:int  = stat( origin, info );
			if( result < 0 )
			{
				throw new CError( errno );
			}
			var fileSize:Number = info.st_size;

			/* NOTE:
			   we do not check for INT_MAX (2GB)
			   or UINT_MAX (4GB)
			*/

			var destp:FILE = fopen( destination, "wb" );

			if( !destp )
			{
				Error.throwError( Error, Errors.kFileOpenError, destination );
			}

			/* NOTE:
			   ByteArrya use a threshold of 24MB to switch to large-size handling,
			   which is incremented every 24MB.
			
			   For files < 24MB we use a buffer of 512KB
			   for files > 24MB we use a buffer of 24MB
			*/
			const b512KB:int = 512 * 1024;
			const b24MB:int  = 24 * 1024 * 1024;

			var copylen:uint = uint(fileSize);

			var actualr:int;
			var actualw:int;
			var reading:ByteArray = new ByteArray();
			
			var maxcopy:int;
			if( buffer > 0 )
			{
				maxcopy = buffer;
			}
			else
			{
				if( copylen >= b24MB )
				{
					maxcopy = b24MB;
				}
				else
				{
					maxcopy = b512KB;
				}
			}

			while( copylen > 0 )
			{
				reading.clear();
				actualr = fread( reading, maxcopy, fp );
				if( actualr > 0)
				{
					reading.position = 0;
					actualw = fwrite( reading, actualr, destp );
					copylen -= actualr;
				}
				else
				{
					break;
				}
			}
			
			reading.clear();
			var success:Boolean = (actualw < 0) ? false: true;

			if( !success )
			{
				Error.throwError( Error, Errors.kFileWriteError, destination );
			}
			
			fflush( fp );
			fclose( fp );
			fflush( destp );
			fclose( destp );
			return success;
		}

		/**
		 * Recursively copy the content of an <code>origin</code> directory
		 * to a <code>destination</code> directory
		 * and returns <code>true</code> on success.
		 * 
		 * @param origin The origin filename to move from.
		 * @param destination The destination filename where to move it.
		 * @param overwrite if <code>true</code> overwrite an already existing destination.
		 * @param noHidden if <code>true</code>(default) do not list hidden entries.
		 * @param copyMode if <code>true</code> copy also the filename mode.
		 * @return <code>true</code> if the directory copied successfully
		 *         otherwise <code>false</code>.
		 *
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function copyDirectory( origin:String, destination:String,
											  overwrite:Boolean = false,
											  noHidden:Boolean = true,
											  copyMode:Boolean = false ):Boolean
		{
			if( !origin )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "origin" );
			}

			if( !destination )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "destination" );
			}

			if( !exists( origin ) )
			{
				throw new Error( "Can not copy directory \"" + origin + "\" as it does not exists." );
			}

			if( exists( destination ) && !overwrite )
			{
				throw new Error( "Can not copy directory \"" + origin + "\" over already existing \"" + destination + "\"." );
			}

			if( !isDirectory( origin ) )
			{
				throw new Error( "Can not copy from a file \"" + origin + "\" to a directory." );
			}

			if( exists( destination ) && !isDirectory( destination ) )
			{
				throw new Error( "Can not copy a directory \"" + origin + "\" to a file \"" + destination + "\"." );
			}

			/* NOTE:
			   here we are in the case where 'destination' does not exists
			   and we have to use createDirectory() to create the directory first
			*/
			if( !exists( destination ) )
			{
				var created:Boolean = createDirectory( destination );
				if( !created )
				{
					throw new Error( "Could not create destination directory \"" + destination + "\"." );
				}
			}

			/* NOTE:
			   if you are in the following situation
			   origin      = /some/dir1
			   destination = /some/dir1/dir2

			   because the origin contains the destination
			   we can end up in some cases where we will have an infinite loop
			   with the listing of files/folders, so we block it here

			   this could be fixed later by exluding this orign directory
			   from a listing of files
			*/
			if( containsPath( origin, destination ) )
			{
				throw new Error( "You can not copy a directory into one of its sub-directory."  );
			}

			if( endsWithSeparator( origin ) )
			{
				origin = stripTrailingSeparators( origin );
			}

			if( endsWithSeparator( destination ) )
			{
				destination = stripTrailingSeparators( destination );
			}

			//first we copy the content of the root
			var copiedfiles:Boolean = copyFiles( origin, destination, /.*/,
												 overwrite, noHidden, copyMode );
			if( !copiedfiles )
			{
				return false;
			}

			var directories:Array = listDirectories( origin, true, noHidden );
			
			var origin_dir:String;
			var dest_dir:String;
			var copieddir:Boolean;
			var i:uint;
			for( i = 0; i < directories.length; i++ )
			{
				origin_dir = origin + separators[0] + directories[i];
				dest_dir   = destination + separators[0] + directories[i];

				copieddir = copyDirectory( origin_dir, dest_dir,
										   overwrite, noHidden, copyMode );
				if( !copieddir )
				{
					return false;
				}

			}

			return true;
		}

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
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			var result:int = access( filename, F_OK );
			/*if( result < 0 )
			{
				throw new CError( errno );
			}*/

			return result == 0;
		}

		/**
		 * Moves an <code>origin</code> entry (file or directory)
		 * to a <code>destination</code> entry
		 * and returns <code>true</code> on success.
		 *
		 * <p>
		 * You can only move file to file
		 * or directory to directory
		 * in case of mismatch it will returns <code>false</code>.
		 * </p>
		 *
		 * <p>
		 * A <code>move()</code> is almost like a <code>rename()</code>,
		 * but if the rename does not work the method will try to copy first
		 * then followed by a delete, and in this case the copy could work
		 * but it will returns <code>false</code> if the delete does not.
		 * </p>
		 * 
		 * @param origin The origin filename to move from.
		 * @param destination The destination filename where to move it.
		 * @param overwrite if <code>true</code> overwrite an already existing destination.
		 * @param force if <code>true</code> and if the rename fail
		 *              will try to do a copy and delete instead,
		 *              works only with directories.
		 * @return <code>true</code> if the filename moved successfully
		 *         otherwise <code>false</code>.
		 *
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function move( origin:String, destination:String,
									 overwrite:Boolean = false, force:Boolean = false ):Boolean
		{
			if( !origin )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "origin" );
			}

			if( !destination )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "destination" );
			}

			if( !exists( origin ) )
			{
				throw new Error( "Can not move \"" + origin + "\" as it does not exists." );
			}

			if( exists( destination ) && !overwrite )
			{
				throw new Error( "Can not move \"" + origin + "\" over already existing \"" + destination + "\"." );
			}

			if( exists( destination ) ) //we can overwrite
			{
				/* NOTE:
				   we can move only a file to a file or a directory to a directory
				*/
				if( isDirectory( origin ) != isDirectory( destination ) )
				{
					return false;
				}
			}

			var result:int = rename( origin, destination );
			if( result < 0 )
			{
				if( force && isDirectory( origin ) ) //we try a copy and delete instead
				{
					//noHidden is false because in this case we do a copy to replace a move
					var copied:Boolean = copyDirectory( origin, destination, overwrite, false );
					if( copied )
					{
						removeDirectory( origin, true ); //this is recursive, it will delete all the childs
						return true;
					}

					return false;
				}
				else
				{
					throw new CError( errno );
				}
			}
			
			return true;
		}

		/**
		 * Removes an entry (file or directory) from the file system.
		 * 
		 * @param filename The filename to remove.
		 * @param recursive if <code>true</code> and filename is a directory
		 *        delete all child entries first.
		 *
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function remove( filename:String, recursive:Boolean = false ):void
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			if( isDirectory( filename ) )
			{
				removeDirectory( filename, recursive );
			}
			else
			{
				removeFile( filename );
			}
		}

		/**
		 * Removes a file entry from the file system.
		 * 
		 * @param  filename The filename to remove.
		 *
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function removeFile( filename:String ):void
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			if( isDirectory( filename ) )
			{
				throw new Error( "filename \"" + filename + "\" is not a file, you should use removeDirectory()." );
			}

			/* NOTE:
			   We could alos use remove().
			*/
			var result:int = unlink( filename );
			if( result < 0 )
			{
				throw new CError( errno );
			}
		}

		/**
		 * Removes a directory entry from the file system,
		 * if <code>recursive=true</code> delete all child entries
		 * (files and directories) first.
		 * 
		 * @param filename The filename to remove.
		 * @param recursive if <code>true</code> delete all child entries first.
		 *
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function removeDirectory( filename:String, recursive:Boolean = false ):void
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			if( !isDirectory( filename ) )
			{
				throw new Error( "filename \"" + filename + "\" is not a directory, you should use removeFile()." );
			}

			if( endsWithSeparator( filename ) )
			{
				filename = stripTrailingSeparators( filename );
			}

			var result:int;
			if( isEmptyDirectory( filename ) ) //dir is empty
			{
				result = rmdir( filename );
				if( result < 0 )
				{
					throw new CError( errno );
				}
			}
			else if( recursive ) //dir is not empty, but remove is recursive
			{
				var files:Array = listFiles( filename );

				var file:String;
				var i:uint;
				for( i = 0; i < files.length; i++ )
				{
					file = filename + separators[0] + files[i];
					removeFile( file );
				}

				var directories:Array = listDirectories( filename );

				var directory:String;
				var j:uint;
				for( j = 0; j < directories.length; j++ )
				{
					directory = filename + separators[0] + directories[j];
					removeDirectory( directory, recursive );
				}

				result = rmdir( filename );
				if( result < 0 )
				{
					throw new CError( errno );
				}
			}
			else //dir is not empty and remove is not recursive
			{
				/* NOTE:
				   this will most likely returns an error
				   and it is what we want
				*/
				result = rmdir( filename );
				if( result < 0 )
				{
					throw new CError( errno );
				}
			}
		}


		/**
		 * Reads the file <code>filename</code> into memory
		 * and returns it as a <code>String</code>.
		 *
		 * <p>
		 * Supports UTF-8 files with or without BOM,
		 * as well as UTF-16 files.
		 * </p>
		 *
		 * <p>
		 * This method cannot handle files bigger than <code>2 GB</code>,
		 * or <code>2147483647 bytes</code> or <code>MAX_INT</code>
		 * or <code>int.MAX_VALUE</code>.
		 * </p>
		 * 
		 * @param  filename The filename to read.
		 * @return the string data contained in the filename.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function read( filename:String ):String
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			var fp:FILE = fopen( filename, "r" );

			if( !fp )
			{
				Error.throwError( Error, Errors.kFileOpenError, filename );
			}

			var lookup:int = fseek( fp, 0, SEEK_END );
			if( lookup < 0 )
			{
				throw new CError( errno );
			}
			var fileSize:Number = ftell( fp );
			fseek( fp, 0, SEEK_SET );

			if( fileSize >= INT_MAX ) //File APIs cannot handle files > 2GB
			{
				Error.throwError( RangeError, Errors.kOutOfRangeError, filename );
			}

			var c:ByteArray = new ByteArray();
			var len:int = fread( c, int(fileSize), fp );

			fclose( fp );
			var ret:String;

			if( len >= 3 )
			{
				// UTF8 BOM
				if( (c[0] == 0xef) && (c[1] == 0xbb) && (c[2] == 0xbf) )
				{
					c.position = 3;
					ret = c.readUTFBytes( len - 3 );
				}
				else if( (c[0] == 0xfe) && (c[1] == 0xff) )
				{
					//UTF-16 big endian
					c.position = 2;
					ret = c.readUTFBytes( len - 2 );
				}
				else if( (c[0] == 0xff) && (c[1] == 0xfe) )
				{
					//UTF-16 little endian
					c.position = 2;
					ret = c.readUTFBytes( len - 2 );
				}
			}

			if( !ret )
			{
				c.position = 0;
				ret = c.readUTFBytes( len );
			}

			c.clear();

			return ret;
		}

		/**
		 * Reads the binary file <code>filename</code> into memory
		 * and returns it as a <code>ByteArray</code>.
		 *
		 * <p>
		 * This method cannot handle files bigger than <code>2 GB</code>,
		 * or <code>2147483647 bytes</code> or <code>MAX_INT</code>
		 * or <code>int.MAX_VALUE</code>.
		 * </p>
		 * 
		 * @param filename The filename to read.
		 * @return the <code>ByteArray</code> data contained in the filename.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function readByteArray( filename:String ):ByteArray
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			var fp:FILE = fopen( filename, "rb" );

			if( !fp )
			{
				Error.throwError( Error, Errors.kFileOpenError, filename );
			}

			var lookup:int = fseek( fp, 0, SEEK_END );
			if( lookup < 0 )
			{
				throw new CError( errno );
			}
			var fileSize:Number = ftell( fp );
			fseek( fp, 0, SEEK_SET );

			/* NOTE:
			   ByteArray APIs cannot handle files > 4GB
			   but fseek() can not read past MAX_INT (2GB)
			   so here we set the limit accordingly
			*/
			if( fileSize >= INT_MAX )
			{
				Error.throwError( RangeError, Errors.kOutOfRangeError, filename );
			}

			var b:ByteArray = new ByteArray();
			var readlen:uint = uint(fileSize);
			/* NOTE:
			   assigning the length here gives the program a chance
			   to throw an Out Of Memory error first
			*/
			b.length = readlen;

			var actual:int = fread( b, int(readlen), fp );

			b.position = 0;
			fclose( fp );

			return b;
		}

		/**
		 * Reads by chunk of <code>buffer</code>
		 * the binary file <code>filename</code> into memory
		 * and returns it as a <code>ByteArray</code>.
		 *
		 * <p>
		 * A buffered read is bit slower but allow to progressively read a file
		 * and so can be usefull when reading big files.
		 * </p>
		 *
		 * <p>
		 * This method cannot handle files bigger than <code>2 GB</code>,
		 * or <code>2147483647 bytes</code> or <code>MAX_INT</code>
		 * or <code>int.MAX_VALUE</code>.
		 * </p>
		 *
		 * <p>
		 * The default <code>buffer</code> value is <code>0</code>,
		 * in this situation the method will automically assign a buffer.
		 * </p>
		 * 
		 * <p>
		 * Internally <code>ByteArray</code> use a threshold of <code>24 MB</code>
		 * to switch to large-size handling, so when the buffer is <code>0</code>
		 * the automatically assigned buffer is <code>512 KB</code> for files smaller than <code>24 MB</code>,
		 * and for bigger files the buffer is <code>24 MB</code>.
		 * </p>
		 * 
		 * @param filename The filename to read.
		 * @param buffer The size of the buffer in bytes.
		 * @return the <code>ByteArray</code> data contained in the filename.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function bufferedReadByteArray( filename:String, buffer:int = 0 ):ByteArray
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			var fp:FILE = fopen( filename, "rb" );

			if( !fp )
			{
				Error.throwError( Error, Errors.kFileOpenError, filename );
			}

			var lookup:int = fseek( fp, 0, SEEK_END );
			if( lookup < 0 )
			{
				throw new CError( errno );
			}
			var fileSize:Number = ftell( fp );
			fseek( fp, 0, SEEK_SET );

			/* NOTE:
			   ByteArray APIs cannot handle files > 4GB
			   but fseek() can not read past MAX_INT (2GB)
			   so here we set the limit accordingly
			*/
			if( fileSize >= INT_MAX )
			{
				Error.throwError( RangeError, Errors.kOutOfRangeError, filename );
			}

			/* NOTE:
			   ByteArrya use a threshold of 24MB to switch to large-size handling,
			   which is incremented every 24MB.
			
			   For files < 24MB we use a buffer of 512KB
			   for files > 24MB we use a buffer of 24MB
			*/
			const b512KB:int = 512 * 1024;
			const b24MB:int  = 24 * 1024 * 1024;

			var b:ByteArray = new ByteArray();
			/* NOTE:
			   fread() nitems is int
			   so we will not be able to read more than INT_MAX
			   eg. 2G
			*/
			var readlen:uint = uint(fileSize);
			/* NOTE:
			   assigning the length here gives the program a chance
			   to throw an Out Of Memory error first
			*/
			b.length = readlen;

			var actual:int;
			var reading:ByteArray = new ByteArray();
			
			var maxread:int;
			if( buffer > 0 )
			{
				maxread = buffer;
			}
			else
			{
				if( readlen >= b24MB )
				{
					maxread = b24MB;
				}
				else
				{
					maxread = b512KB;
				}
			}

			while( readlen > 0 )
			{
				reading.clear();
				actual = fread( reading, maxread, fp );
				if( actual > 0)
				{
					reading.position = 0;
					b.writeBytes( reading );
					readlen -= actual;
				}
				else
				{
					break;
				}
			}
			reading.clear();
			b.position = 0;
			fclose( fp );

			return b;
		}


		/**
		 * Writes the text <code>data</code> to the file <code>filename</code>.
		 * 
		 * @param filename The filename to write.
		 * @param data the string data to write into the file.
		 * @param useBOM if <code>true</code> write an UTF-8 BOM.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function write( filename:String, data:String, useBOM:Boolean = false ):void
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			if( !data )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "data" );
			}

			var fp:FILE = fopen( filename, "w" );

			if( !fp )
			{
				Error.throwError( Error, Errors.kFileWriteError, filename );
			}

			var bytes:ByteArray = new ByteArray();

			if( useBOM )
			{
				bytes.writeByte( 0xef );
				bytes.writeByte( 0xbb );
				bytes.writeByte( 0xbf );
			}
				bytes.writeUTFBytes( data );
				bytes.position = 0;

			var blen:uint = bytes.length;

			var wrote:int = fwrite( bytes, blen, fp );

			if( wrote != blen )
			{
				Error.throwError( Error, Errors.kFileWriteError, filename );
			}

			fflush( fp );
			bytes.clear();
			fclose( fp );
		}

		/**
		 * Writes the binary <code>bytes</code> to the file <code>filename</code>
		 * and returns <code>true</code> on success.
		 * 
		 * @param filename The filename to write.
		 * @param bytes the binary data to write into the file.
		 * @return <code>true</code> if written successfully, otherwise <code>false</code>.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function writeByteArray( filename:String, bytes:ByteArray ):Boolean
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			var fp:FILE = fopen( filename, "wb" );

			if( !fp )
			{
				Error.throwError( Error, Errors.kFileWriteError, filename );
			}

			var len:uint = bytes.length;
			/* NOTE:
			   fwrite() nitems is int
			   so we will not be able to write more than INT_MAX
			   eg. 2G
			*/
			var wrotelen:uint = len;
			var actual:int;
			//bytes.position = 0; //let's avoid this for now
			while( wrotelen > 0 )
			{
				actual = fwrite( bytes, len, fp );
				if( actual > 0 )
				{
					wrotelen -= actual;
				}
				else
				{
					break;
				}
			}

			var success:Boolean = (actual < 0) ? false: true;

			if( !success )
			{
				Error.throwError( Error, Errors.kFileWriteError, filename );
			}
			
			fflush( fp );
			fclose( fp );
			return success;
		}

		/**
		 * Writes by chunk of <code>buffer</code>
		 * the binary <code>bytes</code> to the file <code>filename</code>
		 * and returns <code>true</code> on success.
		 * 
		 * @param filename The filename to write.
		 * @param bytes the binary data to write into the file.
		 * @param buffer The size of the buffer in bytes.
		 * @return <code>true</code> if written successfully, otherwise <code>false</code>.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function bufferedWriteByteArray( filename:String, bytes:ByteArray, buffer:int = 0 ):Boolean
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			var fp:FILE = fopen( filename, "wb" );

			if( !fp )
			{
				Error.throwError( Error, Errors.kFileWriteError, filename );
			}

			/* NOTE:
			   ByteArrya use a threshold of 24MB to switch to large-size handling,
			   which is incremented every 24MB.
			
			   For files < 24MB we use a buffer of 512KB
			   for files > 24MB we use a buffer of 24MB
			*/
			const b512KB:int = 512 * 1024;
			const b24MB:int  = 24 * 1024 * 1024;

			var len:uint = bytes.length;
			/* NOTE:
			   fwrite() nitems is int
			   so we will not be able to write more than INT_MAX
			   eg. 2G
			*/
			var wrotelen:uint = len;
			var maxwrite:int;
			if( buffer > 0 )
			{
				maxwrite = buffer;
			}
			else
			{
				if( wrotelen >= b24MB )
				{
					maxwrite = b24MB;
				}
				else
				{
					maxwrite = b512KB;
				}
			}

			var actual:int;
			while( wrotelen > 0 )
			{
				actual = fwrite( bytes, maxwrite, fp );
				if( actual > 0 )
				{
					wrotelen -= actual;
				}
				else
				{
					break;
				}
			}

			var success:Boolean = (actual < 0) ? false: true;

			if( !success )
			{
				Error.throwError( Error, Errors.kFileWriteError, filename );
			}
			
			fflush( fp );
			fclose( fp );
			return success;
		}




		/* can it ? has it ? kind of information */

		/**
		 * Verify if we can access the <code>filename</code>.
		 * 
		 * @param filename The filename to test.
		 * @return <code>true</code> if filename can be accessed,
		 *         otherwise <code>false</code>.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function canAccess( filename:String ):Boolean
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			var result:int = access( filename, F_OK );
			if( result < 0 )
			{
				throw new CError( errno );
			}

			return result == 0;
		}

		/**
		 * Verify if we can read the <code>filename</code>.
		 * 
		 * @param filename The filename to test.
		 * @return <code>true</code> if filename can be read,
		 *         otherwise <code>false</code>.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function canRead( filename:String ):Boolean
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			var result:int = access( filename, R_OK );
			if( result < 0 )
			{
				throw new CError( errno );
			}

			return result == 0;
		}

		/**
		 * Verify if we can write to the <code>filename</code>.
		 * 
		 * @param filename The filename to test.
		 * @return <code>true</code> if can write to the filename,
		 *         otherwise <code>false</code>.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function canWrite( filename:String ):Boolean
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			var result:int = access( filename, W_OK );
			if( result < 0 )
			{
				throw new CError( errno );
			}

			return result == 0;
		}

		/**
		 * Tests if the <code>filename</code> contains a drive letter.
		 * 
		 * @param filename The filename to test.
		 * @return <code>true</code> if the filename starts with <code>[A-z]:</code>,
		 *         otherwise <code>false</code>.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function hasDriveLetter( filename:String ):Boolean
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			var c:Array = filename.split( "" );

			if( (filename.length >= 2) && (c[1] == ":") &&
				((("A" <= c[0]) && (c[0] <= "Z")) || (("a" <= c[0]) && (c[0] <= "z"))) )
			{
				return true;
			}

			return false;
		}




		/* get informations */

		/**
		 * Returns the <code>filename</code> mode.
		 * 
		 * @param filename The filename to use.
		 * @return an <code>int</code> representing the file mode.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function getFileMode( filename:String ):int
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			var info:status = new status();
			var result:int  = stat( filename, info );
			if( result < 0 )
			{
				throw new CError( errno );
			}

			return info.st_mode;
		}

		/**
		 * Returns the <code>filename</code> last access time.
		 *
		 * <p>
		 * The access time is the time when the data of a file was last accessed.
		 * Displaying the contents of a file or executing a shell script will update
		 * a file's <code>atime</code>.
		 * For example: <code>$ cat file</code> will update the file's atime.
		 * </p>
		 * 
		 * @param filename The filename to use.
		 * @return a <code>Date</code> representing the file last access time.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function getFileAccessTime( filename:String ):Date
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			var info:status = new status();
			var result:int  = stat( filename, info );
			if( result < 0 )
			{
				throw new CError( errno );
			}

			var d:Date = new Date();
				d.setTime( info.st_atime * 1000 );
			return d;
		}

		/**
		 * Returns the <code>filename</code> last modified time.
		 *
		 * <p>
		 * The modify time is the time when the actual contents of a file
		 * was last modified.
		 * For example: opening a text file and appending text to it,
		 * <code>$ echo "something" &gt;&gt; file</code> will update
		 * the ctime and mtime of the file.
		 * </p>
		 * 
		 * @param filename The filename to use.
		 * @return a <code>Date</code> representing the file last modified time.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function getFileModifiedTime( filename:String ):Date
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			var info:status = new status();
			var result:int  = stat( filename, info );
			if( result < 0 )
			{
				throw new CError( errno );
			}

			var d:Date = new Date();
				d.setTime( info.st_mtime * 1000 );
			return d;
		}

		/**
		 * Returns the <code>filename</code> last changed time.
		 *
		 * <p>
		 * In general it is not possible to tell the actual creation time of a file.
		 * The change time is the time when changes were made to the file
		 * or directory's <code>inode</code> (owner, permissions, etc.).
		 * The <code>ctime</code> is also updated when the contents of a file change.
		 * For example: <code>$ chmod g+w file</code> will update the ctime of the file.
		 * </p>
		 * 
		 * @param filename The filename to use.
		 * @return a <code>Date</code> representing the file last changed time.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function getFileChangedTime( filename:String ):Date
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			var info:status = new status();
			var result:int  = stat( filename, info );
			if( result < 0 )
			{
				throw new CError( errno );
			}

			var d:Date = new Date();
				d.setTime( info.st_atime * 1000 );
			return d;
		}

		/**
		 * Returns the file <code>filename</code> size in bytes.
		 * 
		 * @param filename The filename to use.
		 * @return a <code>Number</code> representing the file size.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function getFileSize( filename:String ):Number
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			var info:status = new status();
			var result:int  = stat( filename, info );
			if( result < 0 )
			{
				throw new CError( errno );
			}

			return info.st_size;
		}

		/**
		 * Returns the <code>FILE</code> <code>stream</code> size in bytes.
		 * 
		 * @param stream The <code>FILE</code> to use.
		 * @return a <code>Number</code> representing the file size.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function getSize( stream:FILE ):Number
		{
			if( !stream )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "stream" );
			}

			var lookup:int = fseek( stream, 0, SEEK_END );
			if( lookup < 0 )
			{
				throw new CError( errno );
			}
			var fileSize:Number = ftell( stream );
			fseek( stream, 0, SEEK_SET );

			return fileSize;
		}

		/**
		 * Returns the directory <code>filename</code> size in bytes (adding all its files size)
		 * and if <code>recursive</code> add the size of any child directory entries.
		 * 
		 * @param filename The filename to use.
		 * @param recursive if <code>true</code> add the size of child directories.
		 * @param includeHidden if <code>true</code> include the hidden files size.
		 * @return a <code>Number</code> representing the directory size.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function getDirectorySize( filename:String,
												 recursive:Boolean = true,
												 includeHidden:Boolean = true ):Number
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			if( !isDirectory( filename ) )
			{
				throw new Error( "filename \"" + filename + "\" is not a directory, you should use getFileSize()." );
			}

			var size:Number = 0;

			if( endsWithSeparator( filename ) ) { filename = stripTrailingSeparators( filename ); }

			if( isEmptyDirectory( filename ) )
			{
				return size;
			}
			else
			{
				var files:Array = listFiles( filename );

				var file:String;
				var i:uint;
				for( i = 0; i < files.length; i++ )
				{
					file = filename + separators[0] + files[i];

					if( includeHidden || !isHidden( file ) )
					{
						size += getFileSize( file );
					}
				}
			}

			if( recursive )
			{
				var directories:Array = listDirectories( filename );

				var directory:String;
				var j:uint;
				for( j = 0; j < directories.length; j++ )
				{
					directory = filename + separators[0] + directories[j];

					if( includeHidden || !isHidden( directory ) )
					{
						size += getDirectorySize( directory, recursive, includeHidden );
					}
				}
			}

			return size;
		}

		/**
		 * Returns the available disk space in bytes on the volume
		 * containing <code>filename</code>, or <code>-1</code> on failure.
		 * 
		 * @param filename The filename to use.
		 * @return a <code>Number</code> representing the available disk space in bytes.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public native static function getFreeDiskSpace( filename:String ):Number;

		/**
		 * Returns the total disk space in bytes on the volume
		 * containing <code>filename</code>, or <code>-1</code> on failure.
		 * 
		 * @param filename The filename to use.
		 * @return a <code>Number</code> representing the total disk space in bytes.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public native static function getTotalDiskSpace( filename:String ):Number;

		/**
		 * Returns the used disk space in bytes on the volume
		 * containing <code>filename</code>, or <code>-1</code> on failure.
		 * 
		 * @param filename The filename to use.
		 * @return a <code>Number</code> representing the used disk space in bytes.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function getUsedDiskSpace( filename:String ):Number
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			var free:Number  = getFreeDiskSpace( filename );
			var total:Number = getTotalDiskSpace( filename );

			if( (free != -1) && (total != -1) )
			{
				return total-free;
			}

			return -1;
		}








		/* it is ? identification and information */

		/**
		 * Test if the <code>filename</code> is a regular file.
		 * 
		 * @param filename The filename to test.
		 * @return <code>true</code> if filename is a regular file, otherwise <code>false</code>.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function isRegularFile( filename:String ):Boolean
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			var mode:int = getFileMode( filename );
			return isRegularFileMode( mode );
		}

		/**
		 * Test if the <code>mode</code> represents a regular file.
		 * 
		 * @param mode The mode of a filename.
		 * @return <code>true</code> if mode is a regular file, otherwise <code>false</code>.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function isRegularFileMode( mode:int ):Boolean
		{
			return S_ISREG( mode );
		}

		/**
		 * Tests if the <code>filename</code> is a directory.
		 * 
		 * @param filename The filename to test.
		 * @return <code>true</code> if filename is a directory, otherwise <code>false</code>.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function isDirectory( filename:String ):Boolean
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			var mode:int = getFileMode( filename );
			return isDirectoryMode( mode );
		}

		/**
		 * Tests if the <code>mode</code> represents a directory.
		 * 
		 * @param mode The mode of a filename.
		 * @return <code>true</code> if mode is a directory, otherwise <code>false</code>.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function isDirectoryMode( mode:int ):Boolean
		{
			return S_ISDIR( mode );
		}

		/**
		 * Tests if the <code>filename</code> is considered <code>hidden</code> by the system.
		 * 
		 * @param filename The filename to test.
		 * @return <code>true</code> if filename is hidden,
		 *         otherwise <code>false</code>.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function isHidden( filename:String ):Boolean
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			if( isDotOrDotdot( filename ) )
			{
				return false;
			}

			switch( Runtime.platform )
			{
				/* NOTE:
				   to support Unicode filename we need to prepend
				   the path with "\\?\"
				   see: http://msdn.microsoft.com/en-us/library/windows/desktop/aa364944(v=vs.85).aspx
				*/
				case "windows":
				return _isAttributeHidden( "\\\\?\\" + filename );

				case "macintosh":
				var hidden:Boolean = _isAttributeHidden( filename );

				if( hidden )
				{
					return true;
				}
				//fall trough

				case "linux":
				var name:String = getBasenameFromPath( filename );

				if( name.charAt(0) == "." )
				{
					return true;
				}
				break;

				default:
				return false;
			}

			return false;
		}

		/**
		 * Tests if the <code>entry</code> is the current directory <code>.</code>
		 * or the parent directory <code>..</code>.
		 * 
		 * @param entry The file entry to test.
		 * @return <code>true</code> if entry is <code>.</code> or <code>..</code>,
		 *         otherwise <code>false</code>.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function isDotOrDotdot( entry:String ):Boolean
		{
			if( (entry == currentDirectory) || (entry == parentDirectory) )
			{
				return true;
			}

			return false;
		}

		/**
		 * Tests if the character <code>c</code> is a separator.
		 * 
		 * @param c The char to test.
		 * @return <code>true</code> if char is a separator,
		 *         otherwise <code>false</code>.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function isSeparator( c:String ):Boolean
		{
			var i:uint;
			for( i = 0; i < separators.length; i++ )
			{
				if( c == separators[i] )
				{
					return true;
				}
			}

			return false;
		}

		/**
		 * Tests if the <code>filename</code> is an empty directory.
		 * 
		 * @param filename The filename to test.
		 * @return <code>true</code> if filename is an empty directory,
		 *         otherwise <code>false</code>.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function isEmptyDirectory( filename:String ):Boolean
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			if( isDirectory( filename ) )
			{
				var entries:Array = listFilesOrDirectories( filename );
				if( entries.length > 0 )
				{
					return false;
				}

				return true;
			}

			return false;
		}

		/**
		 * Tests if the <code>component</code> is valid
		 * under Windows file system rules.
		 * 
		 * @param component The component to test.
		 * @return <code>true</code> if component is valid,
		 *         otherwise <code>false</code>.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function isValidWindowsComponent( component:String ):Boolean
		{
			var reserved:String;
			var i:uint;
			for( i = 0; i < _win32_reserved_chars.length; i++ )
			{
				reserved = _win32_reserved_chars[i];

				if( component.indexOf( reserved ) > -1 )
				{
					return false;
				}
			}

			for( i = 0; i < _win32_reserved_words.length; i++ )
			{
				reserved = _win32_reserved_words[i];

				if( component.indexOf( reserved ) > -1 )
				{
					return false;
				}
			}

			//check also from \x01 to \x31
			//check null char
			//check last char as not being a dot or space

			return true;
		}

		/**
		 * Tests if the <code>component</code> is valid
		 * under Macintosh file system rules.
		 * 
		 * @param component The component to test.
		 * @return <code>true</code> if component is valid,
		 *         otherwise <code>false</code>.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function isValidMacintoshComponent( component:String ):Boolean
		{
			var reserved:String;
			var i:uint;
			for( i = 0; i < _macosx_reserved_chars.length; i++ )
			{
				reserved = _macosx_reserved_chars[i];

				if( component.indexOf( reserved ) > -1 )
				{
					return false;
				}
			}

			//check null char
			
			return true;
		}

		/**
		 * Tests if the <code>component</code> is valid
		 * under Linux file system rules.
		 * 
		 * @param component The component to test.
		 * @return <code>true</code> if component is valid,
		 *         otherwise <code>false</code>.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function isValidLinuxComponent( component:String ):Boolean
		{
			var reserved:String;
			var i:uint;
			for( i = 0; i < _linux_reserved_chars.length; i++ )
			{
				reserved = _linux_reserved_chars[i];

				if( component.indexOf( reserved ) > -1 )
				{
					return false;
				}
			}

			//check null char

			return true;
		}

		/**
		 * Tests if the <code>component</code> is valid
		 * under the current system rules.
		 * 
		 * @param component The component to test.
		 * @return <code>true</code> if component is valid,
		 *         otherwise <code>false</code>.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function isValidComponent( component:String ):Boolean
		{
			var valid:Boolean;
			switch( Runtime.platform )
			{
				case "windows":
				valid = isValidWindowsComponent( component );
				break;

				case "macintosh":
				valid = isValidMacintoshComponent( component );
				break;

				case "linux":
				default:
				valid = isValidLinuxComponent( component );
			}

			return valid;
		}

		/**
		 * Tests if the <code>component</code> is valid
		 * under all file system rules.
		 * 
		 * @param component The component to test.
		 * @return <code>true</code> if component is valid,
		 *         otherwise <code>false</code>.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function isValidEverywhereComponent( component:String ):Boolean
		{
			if( !isValidWindowsComponent( component ) )
			{
				return false;
			}

			if( !isValidMacintoshComponent( component ) )
			{
				return false;
			}

			if( !isValidLinuxComponent( component ) )
			{
				return false;
			}

			return true;
		}

		/**
		 * Tests if the <code>filename</code> is valid
		 * under the current system rules.
		 * 
		 * @param filename The filename to test.
		 * @return <code>true</code> if component is valid,
		 *         otherwise <code>false</code>.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function isValid( filename:String ):Boolean
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			var components:Array = getComponentsFromPath( filename );
			var component:String;
			var valid:Boolean;
			var i:uint;
			for( i = 0; i < components.length; i++ )
			{
				component = components[i];
				valid     = isValidComponent( component );

				if( !valid )
				{
					return false;
				}
			}

			return true;
		}

		/**
		 * Tests if the <code>filename</code> is valid
		 * under all file system rules.
		 * 
		 * @param filename The filename to test.
		 * @return <code>true</code> if component is valid,
		 *         otherwise <code>false</code>.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function isValidEverywhere( filename:String ):Boolean
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			var components:Array = getComponentsFromPath( filename );
			var component:String;
			var valid:Boolean;
			var i:uint;
			for( i = 0; i < components.length; i++ )
			{
				component = components[i];
				valid     = isValidEverywhereComponent( component );

				if( !valid )
				{
					return false;
				}
			}

			return true;
		}






		/* separator manipulation */

		/**
		 * Tests if <code>filename</code> ends with a separator.
		 * 
		 * @param filename The filename to test.
		 * @return <code>true</code> if filename last char is a separator,
		 *         otherwise <code>false</code>.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function endsWithSeparator( filename:String ):Boolean
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			if( filename == "" ) { return false; }

			return isSeparator( filename.charAt( filename.length-1 ) );
		}

		/**
		 * Returns <code>filename</code> ending with a separator.
		 * 
		 * @param filename The filename to verify.
		 * @return a string which has been verified to end with a separator.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function ensureEndsWithSeparator( filename:String ):String
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			if( endsWithSeparator( filename ) ) { return filename; }

			return filename + separators[0];
		}

		/**
		 * Remove trailing separators from the <code>filename</code>.
		 * 
		 * @param filename The filename to verify.
		 * @return a string which end has been stripped of any separators.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function stripTrailingSeparators( filename:String ):String
		{
			if( !filename )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
			}

			var start:String = "";
			var path:String  = "";

			if( hasDriveLetter( filename ) )
			{
				start = filename.substring( 0, 2 );
				path  = filename.substr( 2 );
			}
			else if( isSeparator( filename.charAt(0) ) )
			{
				/* NOTE:
				   loop to support UNC paths ?
				   eg. //server/drive
				*/
				start = filename.substring( 0, 1 );
				path  = filename.substr( 1 );
			}
			else
			{
				path = filename;
			}

			/* NOTE:
			   If the string only has two separators and they're at the beginning,
			   don't strip them, unless the string began with more than two separators.
			   eg. //path vs ///otherpath
			*/
			while( isSeparator( path.charAt( path.length-1 ) ) )
			{
				if( (path.length == 1) && isSeparator( path.charAt(0) ) )
				{
					break;
				}

				path = path.substring( 0, path.length-1 );
			}


			return start+path;
		}
















		/* listing manipulation */

		/**
		 * Returns an array of files and directories from <code>filename</code>.
		 * 
		 * @param filepath The filename from where to list.
		 * @param noDots if <code>true</code>(default) do not list <code>.</code> and <code>..</code>.
		 * @param noHidden if <code>true</code>(default) do not list hidden entries.
		 * @param sorting negative (default) does not sort, if positive, use <code>Array</code> class constant to sort the entries.
		 * @return an array of files and directories.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function listFilesOrDirectories( filepath:String, noDots:Boolean = true,
													   noHidden:Boolean = true, sorting:int = -1 ):Array
		{
			if( !filepath )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filepath" );
			}

			var entries:Array = [];
			var dirp:DIR = opendir( filepath );
			if( !dirp )
			{
				throw new CError( errno );
			}

			/* NOTE:
			   we need to test for root directory
			   eg. listDirectories( "/" )
			   then dirsep == ""
			
				for now it works but it feel weird
				to "/" + "/" + name
			*/
			var dirsep:String = separators[0];

			if( filepath == rootDirectory )
			{
				dirsep = "";
			}

			var dp:dirent;
			var statbuf:status;
			var ffd:int;
			var name:String;
			var fullname:String;
			while( (dp = readdir( dirp )) != null )
			{
				name     = dp.d_name;
				fullname = filepath + dirsep + name;

				if( noDots && isDotOrDotdot( name ) )
				{
					continue;
				}

				if( noHidden && isHidden( fullname ) )
				{
					continue;
				}

				statbuf = new status();
				ffd = stat( fullname, statbuf );
				if( ffd < 0 )
				{
					throw new CError( errno );
				}

				if( S_ISREG( statbuf.st_mode ) || 
					S_ISDIR( statbuf.st_mode ) )
				{
					entries.push( name );
				}
			}

			if( sorting >= 0 )
			{
				if( sorting == 0 )
				{
					entries.sort();
				}
				else
				{
					entries.sort( sorting );
				}
			}

			var result:int = closedir( dirp );
			if( result < 0 )
			{
				throw new CError( errno );
			}

			return entries;
		}

		/**
		 * Returns an array of files and directories from <code>filename</code>
		 * filtered by a function.
		 * 
		 * @param filepath The filename from where to list.
		 * @param filter The function used to filter the results.
		 * @param noDots if <code>true</code>(default) do not list <code>.</code> and <code>..</code>.
		 * @param noHidden if <code>true</code>(default) do not list hidden entries.
		 * @param sorting negative (default) does not sort, if positive, use <code>Array</code> class constant to sort the entries.
		 * @return an array of files and directories.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function listFilesOrDirectoriesWithFilter( filepath:String, filter:Function,
												  		  		 noDots:Boolean = true, 
														  		 noHidden:Boolean = true,
														  		 sorting:int = -1 ):Array
		{
			if( !filepath )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filepath" );
			}

			if( !filter )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filter" );
			}

			var list:Array = listFilesOrDirectories( filepath, noDots, noHidden, sorting );
			return list.filter( filter );
		}

		/**
		 * Returns an array of files and directories from <code>filename</code>
		 * filtered by a regular expression.
		 * 
		 * @param filepath The filename from where to list.
		 * @param filter The regular expression used to filter the results.
		 * @param noDots if <code>true</code>(default) do not list <code>.</code> and <code>..</code>.
		 * @param noHidden if <code>true</code>(default) do not list hidden entries.
		 * @param sorting negative (default) does not sort, if positive, use <code>Array</code> class constant to sort the entries.
		 * @return an array of files and directories.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function listFilesOrDirectoriesWithRegexp( filepath:String, filter:RegExp,
												  		  		 noDots:Boolean = true, 
														  		 noHidden:Boolean = true,
														  		 sorting:int = -1 ):Array
		{
			if( !filepath )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filepath" );
			}

			if( !filter )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filter" );
			}

			var list:Array = listFilesOrDirectories( filepath, noDots, noHidden, sorting );
			return list.filter( _filterWithRegexp( filter ) );
		}

		/**
		 * Returns an array of files from <code>filename</code>.
		 * 
		 * @param filepath The filename from where to list.
		 * @param noDots if <code>true</code>(default) do not list <code>.</code> and <code>..</code>.
		 * @param noHidden if <code>true</code>(default) do not list hidden entries.
		 * @param sorting negative (default) does not sort, if positive, use <code>Array</code> class constant to sort the entries.
		 * @return an array of files.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function listFiles( filepath:String, noDots:Boolean = true,
										  noHidden:Boolean = true, sorting:int = -1 ):Array
		{
			if( !filepath )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filepath" );
			}

			var files:Array = [];
			var dirp:DIR = opendir( filepath );
			if( !dirp )
			{
				throw new CError( errno );
			}

			/* NOTE:
			   we need to test for root directory
			   eg. listDirectories( "/" )
			   then dirsep == ""
			
				for now it works but it feel weird
				to "/" + "/" + name
			*/
			var dirsep:String = separators[0];

			if( filepath == rootDirectory )
			{
				dirsep = "";
			}

			var dp:dirent;
			var statbuf:status;
			var ffd:int;
			var filename:String;
			var fullname:String;
			while( (dp = readdir( dirp )) != null )
			{
				filename = dp.d_name;
				fullname = filepath + dirsep + filename;

				if( noDots && isDotOrDotdot( filename ) )
				{
					continue;
				}

				if( noHidden && isHidden( fullname ) )
				{
					continue;
				}

				statbuf = new status();
				ffd = stat( fullname, statbuf );
				if( ffd < 0 )
				{
					throw new CError( errno );
				}

				if( S_ISREG( statbuf.st_mode ) )
				{
					files.push( filename );
				}
			}

			if( sorting >= 0 )
			{
				if( sorting == 0 )
				{
					files.sort();
				}
				else
				{
					files.sort( sorting );
				}
			}

			var result:int = closedir( dirp );
			if( result < 0 )
			{
				throw new CError( errno );
			}

			return files;
		}

		/**
		 * Returns an array of files from <code>filename</code>
		 * filtered by a function.
		 *
	     * @example Usage
	     * <listing>
	     * import shell.FileSystem.&#42;;
	     * 
	     * //our filter function
	     * var isATextFile:Function = function( element:&#42;, index:int, arr:Array ):Boolean
	     * {
	     * 		if( element.indexOf( ".txt" ) > -1 )
	     * 		{
	     * 			return true;
	     * 		}
	     * 
	     * 		return false;
	     * }
	     * 
	     * //get a list of files and apply the filter
	     * var myfiles:Array = FileSystem.listFilesWithFilter( "test", isATextFile );
	     *
	     * //will show a list of files ending by ".txt"
	     * trace( myfiles.join( "\n" ) );
	     * 
	     * </listing>
		 * 
		 * @param filepath The filename from where to list.
		 * @param filter The function used to filter the results.
		 * @param noDots if <code>true</code>(default) do not list <code>.</code> and <code>..</code>.
		 * @param noHidden if <code>true</code>(default) do not list hidden entries.
		 * @param sorting negative (default) does not sort, if positive, use <code>Array</code> class constant to sort the entries.
		 * @return an array of files.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function listFilesWithFilter( filepath:String, filter:Function,
													noDots:Boolean = true, 
													noHidden:Boolean = true,
													sorting:int = -1 ):Array
		{
			if( !filepath )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filepath" );
			}

			if( !filter )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filter" );
			}

			var list:Array = listFiles( filepath, noDots, noHidden, sorting );
			return list.filter( filter );
		}

		/**
		 * Returns an array of files from <code>filename</code>
		 * filtered by a regular expression.
		 *
	     * @example Usage
	     * <listing>
	     * import shell.FileSystem.&#42;;
	     * 
	     * //list all files ending with extension "&#42;.abc"
	     * var myfiles:Array = FileSystem.listFilesWithRegexp( "test", /.&#42;\.abc$/ );
	     * 
	     * trace( myfiles.join( "\n" ) );
	     * 
	     * </listing>
		 * 
		 * @param filepath The filename from where to list.
		 * @param filter The regular expression used to filter the results.
		 * @param noDots if <code>true</code>(default) do not list <code>.</code> and <code>..</code>.
		 * @param noHidden if <code>true</code>(default) do not list hidden entries.
		 * @param sorting negative (default) does not sort, if positive, use <code>Array</code> class constant to sort the entries.
		 * @return an array of files.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function listFilesWithRegexp( filepath:String, filter:RegExp,
													noDots:Boolean = true, 
													noHidden:Boolean = true,
													sorting:int = -1 ):Array
		{
			if( !filepath )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filepath" );
			}

			if( !filter )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filter" );
			}

			var list:Array = listFiles( filepath, noDots, noHidden, sorting );
			return list.filter( _filterWithRegexp( filter ) );
		}


		/**
		 * Returns an array of directories from <code>filename</code>.
		 * 
		 * @param filepath The filename from where to list.
		 * @param noDots if <code>true</code>(default) do not list <code>.</code> and <code>..</code>.
		 * @param noHidden if <code>true</code>(default) do not list hidden entries.
		 * @param sorting negative (default) does not sort, if positive, use <code>Array</code> class constant to sort the entries.
		 * @return an array of directories.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function listDirectories( filepath:String, noDots:Boolean = true,
												noHidden:Boolean = true, sorting:int = -1 ):Array
		{
			if( !filepath )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filepath" );
			}

			var directories:Array = [];
			var dirp:DIR = opendir( filepath );
			if( !dirp )
			{
				throw new CError( errno );
			}

			/* NOTE:
			   we need to test for root directory
			   eg. listDirectories( "/" )
			   then dirsep == ""
			
				for now it works but it feel weird
				to "/" + "/" + name
			*/
			var dirsep:String = separators[0];

			if( filepath == rootDirectory )
			{
				dirsep = "";
			}

			var dp:dirent;
			var statbuf:status;
			var ffd:int;
			var dirname:String;
			var fullname:String;
			while( (dp = readdir( dirp )) != null )
			{
				dirname  = dp.d_name;
				fullname = filepath + dirsep + dirname;

				if( noDots && isDotOrDotdot( dirname ) )
				{
					continue;
				}

				if( noHidden && isHidden( fullname ) )
				{
					continue;
				}

				statbuf = new status();
				ffd = stat( fullname, statbuf );
				if( ffd < 0 )
				{
					throw new CError( errno );
				}

				if( S_ISDIR( statbuf.st_mode ) )
				{
					directories.push( dirname );
				}
			}

			if( sorting >= 0 )
			{
				if( sorting == 0 )
				{
					directories.sort();
				}
				else
				{
					directories.sort( sorting );
				}
			}

			var result:int = closedir( dirp );
			if( result < 0 )
			{
				throw new CError( errno );
			}

			return directories;
		}

		/**
		 * Returns an array of directories from <code>filename</code>
		 * filtered by a function.
		 * 
		 * @param filepath The filename from where to list.
		 * @param filter The function used to filter the results.
		 * @param noDots if <code>true</code>(default) do not list <code>.</code> and <code>..</code>.
		 * @param noHidden if <code>true</code>(default) do not list hidden entries.
		 * @param sorting negative (default) does not sort, if positive, use <code>Array</code> class constant to sort the entries.
		 * @return an array of directories.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function listDirectoriesWithFilter( filepath:String, filter:Function,
												  		  noDots:Boolean = true, 
														  noHidden:Boolean = true,
														  sorting:int = -1 ):Array
		{
			if( !filepath )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filepath" );
			}

			if( !filter )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filter" );
			}

			var list:Array = listDirectories( filepath, noDots, noHidden, sorting );
			return list.filter( filter );
		}

		/**
		 * Returns an array of directories from <code>filename</code>
		 * filtered by a regular expression.
		 * 
		 * @param filepath The filename from where to list.
		 * @param filter The regular expression used to filter the results.
		 * @param noDots if <code>true</code>(default) do not list <code>.</code> and <code>..</code>.
		 * @param noHidden if <code>true</code>(default) do not list hidden entries.
		 * @param sorting negative (default) does not sort, if positive, use <code>Array</code> class constant to sort the entries.
		 * @return an array of directories.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function listDirectoriesWithRegexp( filepath:String, filter:RegExp,
												  		  noDots:Boolean = true, 
														  noHidden:Boolean = true,
														  sorting:int = -1 ):Array
		{
			if( !filepath )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filepath" );
			}

			if( !filter )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filter" );
			}

			var list:Array = listDirectories( filepath, noDots, noHidden, sorting );
			return list.filter( _filterWithRegexp( filter ) );
		}

		/**
		 * Returns an array of files and directories sorted by depth.
		 * 
		 * @param filepath The filename from where to list.
		 * @param includePath Include the original <code>filepath</code> in the results.
		 * @param noHidden if <code>true</code>(default) do not list hidden entries.
		 * @param sorting negative (default) does not sort, if positive, use <code>Array</code> class constant to sort the entries.
		 * @return an array of directories.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function listByDepth( filepath:String, includePath:Boolean = false,
											noHidden:Boolean = true, sorting:int = -1 ):Array
		{
			if( !filepath )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filepath" );
			}

			var list:Array    = [];
			var stack:Array   = [];
			var dirsep:String = separators[0];

			stack.push( filepath );
			
			while( stack.length > 0 )
			{
				var directory:String = stack.pop();
				
				var directories:Array = listDirectories( directory, true, noHidden, sorting );
				for( var i:uint = 0; i < directories.length; i++ )
				{
					stack.push( directory + dirsep + directories[i] );
				}
				
				var files:Array = listFiles( directory, true, noHidden, sorting );
				for( var j:uint = 0; j < files.length; j++ )
				{
					if( includePath )
					{
						list.push( directory + dirsep + files[j] );
					}
					else
					{
						list.push( directory.substr(filepath.length) + dirsep + files[j] );
					}
				}
			}
			
			return list;
		}

		/**
		 * Returns an array of files and directories sorted by breadth.
		 * 
		 * @param filepath The filename from where to list.
		 * @param includePath Include the original <code>filepath</code> in the results.
		 * @param noHidden if <code>true</code>(default) do not list hidden entries.
		 * @param sorting negative (default) does not sort, if positive, use <code>Array</code> class constant to sort the entries.
		 * @return an array of directories.
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function listByBreadth( filepath:String, includePath:Boolean = false,
											  noHidden:Boolean = true, sorting:int = -1 ):Array
		{
			if( !filepath )
			{
				Error.throwError( ArgumentError, Errors.kNullArgumentError, "filepath" );
			}

			var list:Array    = [];
			var queue:Array   = [];
			var dirsep:String = separators[0];

			queue[ queue.length ] = filepath;
			
			var counter:uint = 0;
			while( counter < queue.length )
			{
				var directory:String = queue[ counter ];
				
				var directories:Array = listDirectories( directory, true, noHidden, sorting );
				for( var i:uint = 0; i < directories.length; i++ )
				{
					queue[ queue.length ] = directory + dirsep + directories[i];
				}
				
				var files:Array = listFiles( directory, true, noHidden, sorting );
				for( var j:uint = 0; j < files.length; j++ )
				{
					if( includePath )
					{
						list.push( directory + dirsep + files[j] );
					}
					else
					{
						list.push( directory.substr(filepath.length) + dirsep + files[j] );
					}
				}
				
				queue[ counter ] = null;
				counter++;
			}
			
			return list;
		}



	}

}
