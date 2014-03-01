/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package shell
{
	import flash.utils.ByteArray;

    /**
     * FileIO class
     *
     * @langversion ActionScript 3.0
     * @playerversion AVM 2.1
     * @playerversion RT 0.3
     */
    [native(cls="::avmshell::FileClass", methods="auto", construct="none")]
    public class FileIO
    {
        public native static function exists( filename:String ):Boolean;
        public native static function read( filename:String ):String;
        public native static function write( filename:String, data:String ):void;

        public native static function readByteArray( filename:String ):ByteArray;
        public native static function writeByteArray( filename:String, bytes:ByteArray ):Boolean;
    }

}
