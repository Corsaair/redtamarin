/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package shell
{
    import shell.async.EventLoop;

    //use namespace AVM2;

    /**
     * The Runtime class represents the currently running redshell runtime.
     * 
     * <p>
     * TODO
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native(cls="::avmshell::RuntimeClass", methods="auto", construct="none")]
    public class Runtime
    {
        //private static var _localAvmplusDescription = "redtamarin-0.0-unknown[0A000]";
        include "description.incl";
        

        private static var _API:Array = [];
                           _API[660] = "FP_9_0";
                           _API[661] = "AIR_1_0";
                           _API[662] = "FP_10_0";
                           _API[663] = "AIR_1_5";
                           _API[664] = "AIR_1_5_1";
                           _API[665] = "FP_10_0_32";
                           _API[666] = "AIR_1_5_2";
                           _API[667] = "FP_10_1";
                           _API[668] = "AIR_2_0";
                           _API[669] = "AIR_2_5";
                           _API[670] = "FP_10_2";
                           _API[671] = "AIR_2_6";
                           _API[672] = "SWF_12";
                           _API[673] = "AIR_2_7";
                           _API[674] = "SWF_13";
                           _API[675] = "AIR_3_0";
                           _API[676] = "SWF_14";
                           _API[677] = "AIR_3_1";
                           _API[678] = "SWF_15";
                           _API[679] = "AIR_3_2";
                           _API[680] = "SWF_16";
                           _API[681] = "AIR_3_3";
                           _API[682] = "SWF_17";
                           _API[683] = "AIR_3_4";
                           _API[684] = "SWF_18";
                           _API[685] = "AIR_3_5";
                           _API[686] = "SWF_19";
                           _API[687] = "AIR_3_6";
                           _API[688] = "VM_INTERNAL";

        private static var _loop:EventLoop;

        private native static function _getAvmplusPlatform():String;
        private native static function _getAvmplusArchitecture():String;
        private native static function _getAvmplusVersion():String;
        private native static function _getAvmplusDescription():String;
        private native static function _getFeatures():String;
        private native static function _getRunmode():String;
        private native static function _getEndian():String;

        /**
         * Return the value passed to <code>-api</code> at launch or the default value.
         * 
      	 * @langversion 3.0
      	 * @playerversion AVM 0.4
         */
        public native static function get apiVersion():int;

        /**
         * Returns the string name of the api version.
         * 
      	 * @langversion 3.0
      	 * @playerversion AVM 0.4
         */
        public static function get api():String
        {
            return _API[ 660 + apiVersion ];
        }

        /**
         * Returns the value passed to <code>-swfversion</code> at launch or the default value.
         * 
      	 * @langversion 3.0
      	 * @playerversion AVM 0.4
         */
        public native static function get swfVersion():int;

        /**
         * Returns the current Operating System platform.
         *
         * <p>
         * The value can be <code>"windows"</code>, <code>"macintosh"</code>,
         * or <code>"linux"</code>.
         * </p>
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public static function get platform():String
        {
            return _getAvmplusPlatform();
        }

        /**
         * Returns the current CPU architecture.
         *
         * <p>
         * The value can be <code>"x86-32"</code>, <code>"x86-64"</code>,
         * <code>"ARM"</code>, <code>"PowerPC"</code>, <code>"SPARC"</code>,
         * <code>"MIPS"</code>, <code>"SH4"</code>, or <code>"unknown"</code>.
         * </p>
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public static function get architecture():String
        {
            return _getAvmplusArchitecture();
        }

        /**
         * Returns the current version of AVM+ in the form "1.0 d100".
         * 
      	 * @langversion 3.0
      	 * @playerversion AVM 0.4
         */
        public static function get version():String
        {
            return _getAvmplusVersion();
        }

        /**
         * Returns the current string description emebedded in the AVM+ shell.
         * 
      	 * @langversion 3.0
      	 * @playerversion AVM 0.4
         */
        public static function get description():String
        {
            var desc:String = _getAvmplusDescription();

            if( desc == "" )
            {
                desc = _localAvmplusDescription;
            }

            return desc;
        }

        /**
         * Returns the compiled in features of AVM+.
         * 
      	 * @langversion 3.0
      	 * @playerversion AVM 0.4
         */
        public static function get features():String
        {
            return _getFeatures();
        }

        /**
         * Returns the current runmode.
         * 
      	 * @langversion 3.0
      	 * @playerversion AVM 0.4
         */
        public static function get runmode():String
        {
            return _getRunmode();
        }

        /**
         * Returns the byte order (endianess) of the runtime.
         * 
      	 * @langversion 3.0
      	 * @playerversion AVM 0.4
         */
        public static function get endian():String
        {
            return _getEndian();
        }

        /**
         * Returns the current version of RedTamarin in the form "1.0.2X100" (major.minor.tag).
         * 
      	 * @langversion 3.0
      	 * @playerversion AVM 0.4
         */
        public static function get redtamarin():String
        {
            //format: redtamarin-0.4-beta[1S131]
            var rtversion:String = "";
            var desc:String = description;

            if( desc == "" )
            {
                return "";
            }

            var tmp:Array = desc.split( "-" );
            
            rtversion += tmp[1]; //0.4
            
            var fulltag:String = tmp[2]; //beta[1S131]
                fulltag = fulltag.split( "[" )[1]; //1S131]
                fulltag = fulltag.split( "]" ).join( "" ); //1S131
            
            rtversion += "." + fulltag; //0.4.1S131
            
            return rtversion;
        }

        /**
         * The global <code>EventLoop</code> instance.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public static function get loop():EventLoop
        {
            //return _loop;
            if( _loop ) { return _loop; }

            //lazy init
            var defaultLoop:Class = getClassByName( "shell.async.CoreEventLoop" );
            //trace( "defaultLoop = " + defaultLoop );

            if( defaultLoop )
            {
                _loop = new defaultLoop();
                return _loop;
            }

            return null;
        }

        /*
        public static function get profile():Profile
        {
            if( _profile ) { return _profile; }

            //lazy init
            var defaultProfile:Class = getClassByName( "avmplus.profiles.RedTamarinProfile" );

            if( defaultProfile )
            {
                _profile = new defaultProfile();
                return _profile;
            }

            return null;
        }
        */


        /** @private */
        public static function set loop( value:EventLoop ):void
        {
            _loop = value;
        }

        /**
         * Forces !RedTamarin to run asynchronous so it can support Events.
         *
         * <p>
         * Instanciate an <code>EventLoop</code> implementation.
         * </p>
         *
         * <p>
         * This is setup by the boot system.
         * </p>
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public static var goAsync:Function = null;

        /**
         * Evaluates AS3 source code at runtime.
         * 
     	   * @langversion 3.0
     	   * @playerversion AVM 0.4
         */
        public native static function eval( source:String ):void;

        /**
         * Evaluates AS3 source code at runtime
         * and return the result into a string.
         * 
     	   * @langversion 3.0
       	 * @playerversion AVM 0.4
         */
        public native static function returnEval( source:String, recordTime:Boolean = false ):String;

        /**
         * Indicates if the runtime is running on a 64-bit platform.
         * 
       	 * @langversion 3.0
     	   * @playerversion AVM 0.4
         */
        public native static function is64bit():Boolean;



        /*public static function goAsync():void
        {
            trace( "Runtime.goAsync()" );

            if( loop == null )
            {
                trace( "build EventLoop" );
                loop = new EventLoop();  
            }
            
            trace( "starts loop" );
            loop.start();
        }*/

        


    }
    
}
