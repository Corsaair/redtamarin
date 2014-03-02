/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package C.dirent
{

    /**
     * Close a directory stream.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CDirentClass::closedir")]
    public native function closedir( dirp:DIR ):int;

    /**
     * Open directory associated with name.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CDirentClass::opendir")]
    public native function opendir( dirname:String ):DIR;


    /**
     * Read a directory.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CDirentClass::readdir")]
    public native function readdir( dirp:DIR ):dirent;

    /**
     * A type representing a directory stream.
     *
     * <p>
     * <b>DIR</b> is a type suitable for storing information for a directory stream.
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native(cls="::avmshell::CDIRClass", instance="::avmshell::CDIRObject", methods="auto")]
    public class DIR
    {

    }

    /**
     * <code>dirent</code> structure.
     *
     * <p>
     * <b>dirent</b> is a type suitable for storing information for a directory entry.
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native(cls="::avmshell::CdirentClass", instance="::avmshell::CdirentObject", methods="auto")]
    public class dirent
    {
        /**
         * File serial number.
         *
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public var d_ino:uint;

        /**
         * Filename string of entry.
         *
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public var d_name:String;
    }

}
