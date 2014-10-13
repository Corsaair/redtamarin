/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

// The flash.system package is present so identical ATS test media can be used
// in the command-line VM and the Player
package flash.system
{
    
    import shell.Runtime;
    import shell.Diagnostics;

    /**
     * The Capabilities class provides properties that describe the system
     * and runtime that are hosting the application. 
     *
     * @langversion 3.0
     * @playerversion Flash 9
     * @playerversion AIR 1.0
     */
    public final class Capabilities
    {
    	private static var _ARCH:String;
    	private static var _M:String;
    	private static var _PR32:String;
    	private static var _PR64:String;

    	/**
    	 * [avHardwareDisable description]
    	 *
    	 * @langversion 3.0
    	 * @playerversion Flash 9
    	 * @playerversion AIR 1.0
    	 */
    	public static function get avHardwareDisable():Boolean
    	{
    		return false;
    	}

    	/**
    	 * Specifies the current CPU architecture.
    	 * The <code>cpuArchitecture</code> property can return the following strings:
    	 * "<code>PowerPC</code>", "<code>x86</code>", "<code>SPARC</code>",
    	 * and "<code>ARM</code>".
    	 * The server string is <code>ARCH</code>.
    	 *
    	 * @langversion 3.0
    	 * @playerversion Flash 10.0.32
    	 * @playerversion AIR 1.5.1
    	 */
    	[API(AVMGLUE::FP_10_0_32,AVMGLUE::AIR_1_5_1)]
    	public static function get cpuArchitecture():String
    	{
    		if( _ARCH )
    		{
    			return _ARCH;
    		}

    		var cpuarch:String = Runtime.architecture;
    		var arch:String;

    		switch( cpuarch )
    		{
    			case "PowerPC":
    			arch = "PowerPC";
    			break;

    			case "x86-32":
    			case "x86-64":
    			arch = "x86";
    			break;

    			case "SPARC":
    			arch = "SPARC";
    			break;

    			case "ARM":
    			arch = "ARM";
    			break;

    			//non-standard to Flash/AIR
    			
    			case "MIPS":
    			arch = "MIPS";
    			break;

    			case "SH4":
    			arch = "SH4";
    			break;

    			//not found
    			
    			case "unknown":
    			default:
    			arch = "x86";
    			break;

    		}

    		_ARCH = arch;
    		return _ARCH;
    	}

    	/**
    	 * Specifies the manufacturer of the running version of Flash Player or the AIR runtime,
    	 * in the format "Adobe OSName".
    	 * The value for OSName could be "Windows", "Macintosh", "Linux",
    	 * or another operating system name.
    	 * The server string is <code>M</code>.
    	 *
    	 * @langversion 3.0
    	 * @playerversion Flash 9
    	 * @playerversion AIR 1.0
    	 */
    	public static function get manufacturer():String
    	{
    		if( _M )
    		{
    			return _M;
    		}

    		var mfct:String = "Adobe ";
			switch( Runtime.platform )
			{
				case "windows":
				mfct += "Windows";
				break;

				case "macintosh":
				mfct += "Macintosh";
				break;

				case "linux":
				mfct += "Linux";
				break;

				/* TODO:
				   add detection for "another operating system name"
				   for ex openBSD/freeBSD, returns BSD ?
				   or maybe jsut returns name for uname ?
				   eg. returns "Android" for Android
				   but our runtime does not support ANdroid, so be able to fake it ?
				*/
			}

			_M = mfct;
			return _M;
    	}

    	/**
    	 * [playerType description]
    	 * 
    	 * @langversion 3.0
    	 * @playerversion Flash 9
    	 * @playerversion AIR 1.0
    	 */
        public static function get playerType():String
        {
        	return "AVMPlus";
    	}

    	/**
    	 * [isDebugger description]
    	 * 
    	 * @langversion 3.0
    	 * @playerversion Flash 9
    	 * @playerversion AIR 1.0
    	 */
        public static function get isDebugger():Boolean
        {
        	return Diagnostics.isDebugger();
        }

    	/**
    	 * Specifies whether the system supports running 32-bit processes.
    	 * The server string is <code>PR32</code>.
    	 *
    	 * @langversion 3.0
    	 * @playerversion Flash 10.0.32
    	 * @playerversion AIR 1.5.2
    	 */
    	[API(AVMGLUE::FP_10_0_32,AVMGLUE::AIR_1_5_2)]
        public static function get supports32BitProcesses():Boolean
        {
        	/* NOTE:
        	   by default we consider that any OS can always run a32-bit
        	   But could we have a case where 32-bit false and 64-bit true ?
        	*/

        	return true;
        }

    	/**
    	 * Specifies whether the system supports running 64-bit processes.
    	 * The server string is <code>PR64</code>.
    	 *
    	 * @langversion 3.0
    	 * @playerversion Flash 10.0.32
    	 * @playerversion AIR 1.5.2
    	 */
    	[API(AVMGLUE::FP_10_0_32,AVMGLUE::AIR_1_5_2)]
        public static function get supports64BitProcesses():Boolean
        {
        	return Runtime.is64bit();
        }

    	/**
    	 * Specifies whether the system supports multichannel audio of a specific type.
    	 * The class flash.media.AudioDecoder enumerates the possible types.
    	 *
    	 * @param type A String value representing a multichannel audio type.
    	 *             The valid values are the constants defined in flash.media.AudioDecoder.
    	 * 
    	 * @langversion 3.0
    	 * @playerversion Flash 11
    	 * @playerversion AIR 3.0
    	 */
    	[API(AVMGLUE::SWF_13,AVMGLUE::AIR_3_0)]
        public static function hasMultiChannelAudio( type:String ):Boolean
        {
        	return false;
        }
    }
}
