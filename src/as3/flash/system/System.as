/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.system
{
    import shell.Program;
    import shell.Runtime;
    
    /**
     * The System class contains properties related to local settings and operations.
     * 
     * <p>
     * Among these are settings for cameras and microphones,
     * operations with shared objects and the use of the Clipboard.
     * </p>
     * 
     * <p>
     * Additional properties and methods are in other classes within the flash.system package:
     * the Capabilities class, the IME class, and the Security class.
     * </p>
     * 
     * <p>
     * This class contains only static methods and properties.
     * You cannot create new instances of the System class.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion Flash 9
     * @playerversion AIR 1.0
     */
    [native(cls="::avmshell::SystemClass", methods="auto", construct="none")]
    public final class System
    {
        //NOT IMPLEMENTED
        //private static var _IME:IME = null;
        
        private static var _useCodePage:Boolean;
        
        public function System()
        {
            _useCodePage = false;
        }
        
        //NOT IMPLEMENTED
        //public static function get ime():IME
        
        //NOT IMPLEMENTED
        //public static native function setClipboard(string:String):void;
        public static function setClipboard( string:String ):void {}
        
        /**
         * Enters debugger.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public static function get totalMemory():uint { return totalMemoryNumber as uint; }
        
        //public static native function get totalMemoryNumber():Number;
        public static function get totalMemoryNumber():Number { return Program.totalMemory; }
        
        /**
         * The amount of memory (in bytes) that is allocated to the runtime and that is not in use.
         * 
         * <p>
         * This unused portion of allocated memory (<code>System.totalMemory</code>) fluctuates as garbage collection takes place.
         * Use this property to monitor garbage collection.
         * </p>
         * 
         * @langversion 3.0
         * @playerversion Flash 10.1
         * @playerversion AIR 2
         */
        [API(AVMGLUE::FP_10_1,AVMGLUE::AIR_2_0)]
        public native static function get freeMemory():Number;
        
        //public static native function get privateMemory():Number;
        public static function get privateMemory():Number { return Program.privateMemory; }
        
        //NOT PART OF THE PUBLIC FPAPI
        //public static native function get precise_startupTime():Number;
        
        //NOT PART OF THE PUBLIC FPAPI
        //public static native function get currentTime():Number;
        
        //NOT IMPLEMENTED
        //public static native function get useCodePage():Boolean;
        public static function get useCodePage():Boolean { return _useCodePage; }
        //public static native function set useCodePage(value:Boolean):void;
        public static function set useCodePage( value:Boolean ):void { _useCodePage = value; }
        
        //public static native function get vmVersion():String;
        public static function get vmVersion():String { return Runtime.version; }
        
        //NOT IMPLEMENTED
        //public static native function pause():void;
        public static function pause():void {}
        
        //NOT IMPLEMENTED
        //public static native function resume():void;
        public static function resume():void {}
        
        //public static native function exit(code:uint):void;
        public static function exit( code:uint ):void { Program.exit( code ); }
        
        //public static native function gc():void;
        public static function gc():void { Program.forceFullCollection(); }
        
        //NOT PART OF THE PUBLIC FPAPI
        //public static native function nativeConstructionOnly(object:Object):void;
        
        //public static native function disposeXML(node:XML):void;
        public static function disposeXML(node:XML):void { Program.disposeXML( node ); }
    }
}