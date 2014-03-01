/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package C.fcntl
{
    /** @internal */
    [native(cls="::avmshell::CFcntlClass", methods="auto", construct="none")]
    [Inspectable(environment="none")]
    internal class __fcntl
    {
        public native static function get O_RDONLY():int;
        public native static function get O_WRONLY():int;
        public native static function get O_RDWR():int;
        public native static function get O_ACCMODE():int;

        public native static function get O_APPEND():int;
        public native static function get O_CREAT():int;
        public native static function get O_TRUNC():int;
        public native static function get O_EXCL():int;

        public native static function get O_TEXT():int;
        public native static function get O_BINARY():int;
        
        /*public native static function get O_RAW():int;
        public native static function get O_TEMPORARY():int;
        public native static function get O_NOINHERIT():int;
        public native static function get O_SEQUENTIAL():int;
        public native static function get O_RANDOM():int;

        public native static function get O_RDONLY():int;
        public native static function get O_RDONLY():int;
        public native static function get O_RDONLY():int;
        public native static function get O_RDONLY():int;
        public native static function get O_RDONLY():int;
        public native static function get O_RDONLY():int;*/
    }

    /**
     * Open for reading only.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const O_RDONLY:int = __fcntl.O_RDONLY;

    /**
     * Open for writing only.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const O_WRONLY:int = __fcntl.O_WRONLY;

    /**
     * Open for reading and writing.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const O_RDWR:int = __fcntl.O_RDWR;

    /**
     * Mask for file access modes.
     *
     * <p>
     * <b>Note: </b> equivalent to <code>O_RDONLY | O_WRONLY | O_RDWR</code>
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const O_ACCMODE:int = __fcntl.O_ACCMODE;


    /**
     * Set append mode.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const O_APPEND:int = __fcntl.O_APPEND;

    /**
     * Create file if it does not exist.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const O_CREAT:int = __fcntl.O_CREAT;

    /**
     * Truncate flag.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const O_TRUNC:int = __fcntl.O_TRUNC;

    /**
     * Exclusive use flag.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const O_EXCL:int = __fcntl.O_EXCL;

    /**
     * Opens a file in text (translated) mode.
     *
     * <p>
     * <b>Note: </b> Windows only.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const O_TEXT:int = __fcntl.O_TEXT;

    /**
     * Opens a file in binary (untranslated) mode.
     *
     * <p>
     * <b>Note: </b> Windows only.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const O_BINARY:int = __fcntl.O_BINARY;

}
