/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package C.sys.utsname
{

    /**
     * @name <code>&lt;sys/utsname.h&gt;</code>
     * System name structure.
     *
     * <p>
     * 
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/sys_utsname.h.html sys/utsname.h
     */

    /** @internal */
    /*[native(cls="::avmshell::CSysUtsnameClass", methods="auto", construct="none")]
    [Inspectable(environment="none")]
    internal class __utsname
    {
        public native static function get DUMMY():int;
    }*/

    /**
     * <p>
     * <b>NOT IMPLEMENTED</b>
     * </p>
     *
     * Get the name of the current system.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CSysUtsnameClass::uname")]
    public native function uname( name:* ):int;
    //public native function uname( name:utsname ):int;


    //utsname
    //[native(cls="::avmshell::CutsnameClass", instance="::avmshell::CutsnameObject", methods="auto")]
    public class utsname
    {

        /**
         * Construct a <code>utsname</code> structure.
         */
        public function utsname( sysname:String = "",
                                 nodename:String = "",
                                 release:String = "",
                                 version:String = "",
                                 machine:String = "" ):void
        {
            this.sysname  = sysname;
            this.nodename = nodename;
            this.release  = release;
            this.version  = version;
            this.machine  = machine;
        }

        /**
         * Name of this implementation of the operating system.
         */
        public var sysname:String;

        /**
         * Name of this node within the communications 
           network to which this node is attached, if any.
         */
        public var nodename:String;

        /**
         * Current release level of this implementation.
         */
        public var release:String;

        /**
         * Current version level of this release.
         */
        public var version:String;

        /**
         * Name of the hardware type on which the system is running.
         */
        public var machine:String;
    }

    /**
     * @private
     * only here for asdocs
     */
    [Inspectable(environment="none")]
    internal function dummy():void
    {
        //do nothing
    }
}