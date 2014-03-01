/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package shell
{

    /**
     * The Diagnostics class provide debugging extensions for the VM.
     * 
     * <p>
     * Some methods are hidden the <code>AVM2</code> namespace,
     * and are provided solely for testing purposes.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native(cls="::avmshell::DiagnosticsClass", methods="auto", construct="none")]
	public class Diagnostics
	{

		private native static function _isGlobal( o:Object ):Boolean;
		private native static function _isIntptr( a:* ):Boolean;
		private native static function _canonicalizeNumber( a:* ):*;
		private native static function _deopt( n:int ):void;
		private native static function _runInSafepoint( code:Function ):void;
        private native static function _log( message:String ):void;
        private native static function _initializeLogging( filename:String ):void;

        /**
         * Enters debugger.
         * 
     	 * @langversion 3.0
     	 * @playerversion AVM 0.4
         */
        public native static function debugger():void;

        /**
         * Tests if the current program is compiled with debugger flags.
         * 
     	 * @langversion 3.0
     	 * @playerversion AVM 0.4
         */
        public native static function isDebugger():Boolean;

        /**
         * Output log messages.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        AVM2 static function log( message:String ):void
        {
            _log( message );
        }

        /**
         * Initialize logging to a file.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        AVM2 static function initializeLogging( filename:String ):void
        {
            _initializeLogging( filename );
        }

        // function exists solely to test ScriptObject::isGlobalObject
        AVM2 static function isGlobal( o:Object ):Boolean
        {
        	return _isGlobal( o );
        }

        // Support for VM tests that depend on representation of numeric atoms.
        // These are provided solely for testing purposes, as the semantics of an AS3 program
        // should not depend on the word size of the platform nor the internal encoding of atoms.

        // Return true if the argument is an atom with tag kIntptrType.
        AVM2 static function isIntptr( a:* ):Boolean
        {
        	return _isIntptr( a );
        }

        // Return argument value as a kIntptrType atom if the argument is a numeric
        // value that can be so represented, else return the argument unchanged.
        AVM2 static function canonicalizeNumber( a:* ):*
        {
        	return _canonicalizeNumber( a );
        }

        // DEOPT: Diagnostic scaffolding.
	    // Debug scaffolding for deoptimization.
	    // Deoptimize method invoked in frame K levels above our caller.
	    // Throws if no such frame exists, but is silently ignored if
	    // the method is not currently compiled.
        AVM2 static function deopt( n:int ):void
        {
        	_deopt( n );
        }

        AVM2 static function runInSafepoint( code:Function ):void
        {
        	_runInSafepoint( code );
        }

	}

}
