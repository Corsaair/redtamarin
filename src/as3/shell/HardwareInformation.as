/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package shell
{

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

		/** @private */
		private native static function _getMemorySize():Number;

		/** @private */
		private native static function _getMemoryUsage():Number;

		/** @private */
		private native static function _getMemoryPeakUsage():Number;

		/**
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function get processors():uint
		{
			return _getProcessorCountAtBoot();
		}

		/**
		 * 
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function get memory():Number
		{
			return _getMemorySize();
		}

		/**
		 * 
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function get memoryUsage():Number
		{
			return _getMemoryUsage();
		}

		/**
		 * 
		 * 
		 * @langversion 3.0
		 * @playerversion AVM 0.4
		 */
		public static function get memoryPeakUsage():Number
		{
			return _getMemoryPeakUsage();
		}
	}

}
