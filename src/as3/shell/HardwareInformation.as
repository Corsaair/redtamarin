/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package shell
{
    import C.unistd.*;
    import shell.Runtime;

    /**
     * The HardwareInformation class provide informations about the underlying hardware.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native(cls="::avmshell::HardwareInformationClass", methods="auto", construct="none")]
    public class HardwareInformation
    {
        /** @private */
        private native static function _getProcessorCountAtBoot():uint;

        /* Note:
           performance infos should be moved to Diagnostics class
        */
        /** @private */
        //private native static function _getPerformanceFrequency():Number;

        /** @private */
        //private native static function _getPerformanceCounter():Number;

        /** @private */
        //private native static function _getPerformanceClockTicks():Number;

        /** @private */
        private native static function _getMemorySize():Number;

        /** @private */
        private native static function _getMemoryFree():Number;

        /** @private */
        private native static function _getProcMemoryUsage():Number;

        /** @private */
        private native static function _getProcMemoryPeakUsage():Number;


        
        /**
         * Returns the number of processors (or CPU cores).
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public static function get processors():uint
        {
            return _getProcessorCountAtBoot();
        }

        /**
         * Returns the frequency (i.e. counts per second) of a high performance counter/timer on the system.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        /*public static function get performanceFrequency():Number
        {
            return _getPerformanceFrequency();
        }*/

        /**
         * Returns the current value of the system's performance counter/timer.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        /*public static function get performanceCounter():Number
        {
            return _getPerformanceCounter();
        }*/

        /**
         * Returns the clock ticks per second on the system.
         * 
         * <p>
         * A kernel configured with 100 clock ticks per second
         * run a <code>100Hz</code> clock, meaning the clock
         * ticks every <code>10</code> milliseconds or <code>0.01</code> seconds.
         * </p>
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        /*public static function get performanceClockTicks():Number
        {
            return _getPerformanceClockTicks();
        }*/


        /**
         * Returns the size of physical memory (RAM) in bytes.
         * 
         * <p>
         * This is different than <code>Program.totalMemory</code>,
         * here we return the physical memory installed on the system
         * not the meroy used by our program.
         * </p>
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         * 
         * @see shell.Program#totalMemory Program.totalMemory
         */
        public static function get memory():Number
        {
            return _getMemorySize();
        }

        /**
         * Returns the total physical memory currently used in bytes.
         * 
         * <p>
         * For Mac OS X, this is the "Memory Used" plus the "Cache",
         * that you can see in "Acrivity Monitor / Memory".
         * </p>
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4.1
         * 
         * @see http://support.apple.com/en-us/HT201464#memory Use Activity Monitor on your Mac (Memory)
         */
        public static function get memoryUsage():Number
        {
            switch( Runtime.platform )
            {
                case "linux":
                return 0;

                case "macintosh":
                return _getMemorySize() - _getMemoryFree();

                case "windows":
                return _getMemorySize() - _getMemoryFree();
            }

            return 0;
        }

        /**
         * Returns the amount of free physical memory in bytes.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4.1
         */
        public static function get memoryFree():Number
        {
            return _getMemoryFree();
        }

        /**
         * Returns the physical memory in use by the current process in bytes.
         * 
         * <p>
         * The "Resident set size" is the amount of physical memory (RAM)
         * used by a process's code and data.
         * </p>
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4.1
         */
        public static function get processMemoryUsage():Number
        {
            return _getProcMemoryUsage();
        }

        /**
         * Returns the physical memory peak in use by the current process in bytes.
         * 
         * <p>
         * Peak means the "maximum so far" that has been used.
         * </p>
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4.1
         */
        public static function get processMemoryPeakUsage():Number
        {
            return _getProcMemoryPeakUsage();
        }

    }

}
