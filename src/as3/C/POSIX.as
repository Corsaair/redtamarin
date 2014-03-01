/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package C
{
    /**
     * C POSIX Library.
     *
     * <p>
     * <b>POSIX.1</b> documentation.
     * </p>
     * 
     * <p>
     * <a href="http://en.wikipedia.org/wiki/POSIX">POSIX</a>, an acronym for "Portable Operating System Interface",
     * is a family of standards specified by the IEEE for maintaining compatibility between operating systems.
     * </p>
     *
     * <p>
     * POSIX defines the application programming interface (API), along with command line shells and utility interfaces,
     * for software compatibility with variants of Unix and other operating systems.
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see C.conio
     * @see C.cpio
     * @see C.dirent
     * @see C.fcntl
     * @see C.grp
     * @see C.netdb
     * @see C.pthread
     * @see C.pwd
     * @see C.spawn
     * @see C.sys.ipc
     * @see C.sys.mman
     * @see C.sys.msg
     * @see C.sys.sem
     * @see C.sys.socket
     * @see C.sys.stat
     * @see C.sys.time
     * @see C.sys.types
     * @see C.sys.utsname
     * @see C.sys.wait
     * @see C.tar
     * @see C.termios
     * @see C.unistd
     * @see C.utime
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/
     * @see http://code.google.com/p/redtamarin/wiki/clib
     * @see http://en.wikipedia.org/wiki/POSIX
     */
	public const POSIX:uint = 1;

     /**
      * sys/stat.h - data returned by the <code>stat()</code> function
      * 
      * <p>
      * sys/stat.h is a header file in the Portable Operating System Interface library.
      * </p>
      * 
      * <p>
      * Contains constructs that facilitate getting information about files attributes.
      * </p>
      * 
      * @langversion 3.0
      * @playerversion AVM 0.4
      * 
      * @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/sys_stat.h.html
      * @see http://en.wikibooks.org/wiki/C_Programming/POSIX_Reference/sys/stat.h
      */
     public const SYS_STAT_H:String = "sys/stat.h documentation";

     /**
      * unistd.h - standard symbolic constants and types
      * 
      * <p>
      * stdlib.h is a header file in the Portable Operating System Interface library.
      * </p>
      *
      * <p>
      * It provides access to the POSIX operating system API.
      * </p>
      * 
      * @langversion 3.0
      * @playerversion AVM 0.4
      * 
      * @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/unistd.h.html
      * @see http://en.wikipedia.org/wiki/Unistd.h
      */
     public const UNISTD_H:String = "unistd.h documentation";
}