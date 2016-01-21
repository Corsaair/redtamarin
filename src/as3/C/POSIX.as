/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

// DOCUMENTATION ONLY - DO NOT COMPILE IN ABC
package C
{
    /**
     * C POSIX Library.
     * 
     * <p>
     * <b>Documentation Stub:</b>
     * this definition is here only for documentation purpose.
     * </p>
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
     * @see C.aio C.aio (not planned)
     * @see C.arpa.inet C.arpa.inet (implemented)
     * @see C.conio C.conio (partial impl) - NOT POSIX
     * @see C.complex C.complex (not planned)
     * @see C.cpio C.cpio (implemented)
     * @see C.dirent C.dirent (almost implemented)
     * @see C.dlfcn C.dlfcn (not implemented)
     * @see C.fcntl C.fcntl (partial impl)
     * @see C.fenv C.fenv (not planned)
     * @see C.fmtmsg C.fmtmsg (not planned)
     * @see C.fnmatch C.fnmatch (not planned)
     * @see C.ftw C.ftw (not planned)
     * @see C.glob C.glob (not planned)
     * @see C.grp C.grp (not implemented)
     * @see C.iconv C.iconv (not planned)
     * @see C.inttypes C.inttypes (not planned)
     * @see C.iso646 C.iso646 (not planned)
     * @see C.langinfo C.langinfo (not implemented)
     * @see C.libgen C.libgen (not implemented)
     * @see C.monetary C.monetary (not planned)
     * @see C.mqueue C.mqueue (not planned)
     * @see C.ndbm C.ndbm (not planned)
     * @see C.net.if C.net.if (not planned)
     * @see C.netdb C.netdb (almost implemented)
     * @see C.netinet C.netinet (almost implemented)
     * @see C.nl_types C.nl_types (not planned)
     * @see C.poll C.poll (not planned)
     * @see C.pthread C.pthread (not planned)
     * @see C.pwd C.pwd (not implemented)
     * @see C.regex C.regex (not planned)
     * @see C.sched C.sched (not planned)
     * @see C.search C.search (not planned)
     * @see C.semaphore C.semaphore (not planned)
     * @see C.spawn C.spawn (almost implemented)
     * @see C.strings C.strings (not planned)
     * @see C.stropts C.stropts (not planned)
     * @see C.sys.ipc C.sys.ipc (not implemented)
     * @see C.sys.mman C.sys.mman (not planned)
     * @see C.sys.msg C.sys.msg (not planned)
     * @see C.sys.resource C.sys.resource (not implemented)
     * @see C.sys.select C.sys.select (implemented, half working, need review)
     * @see C.sys.sem C.sys.sem (not planned)
     * @see C.sys.shm C.sys.shm (not planned)
     * @see C.sys.socket (almost implemented)
     * @see C.sys.stat C.sys.stat (almost implemented)
     * @see C.sys.statvfs C.sys.statvfs (not implemented)
     * @see C.sys.time C.sys.time (not implemented)
     * @see C.sys.times C.sys.times (not implemented)
     * @see C.sys.types C.sys.types (not planned)
     * @see C.sys.uio C.sys.uio (not planned)
     * @see C.sys.un C.sys.un (not implemented)
     * @see C.sys.utsname C.sys.utsname (not implemented)
     * @see C.sys.wait (almost implemented, need review)
     * @see C.syslog C.syslog (not implemented)
     * @see C.tar C.tar (not implemented)
     * @see C.termios C.termios (not implemented)
     * @see C.tgmath C.tgmath (not planned)
     * @see C.trace C.trace (not planned)
     * @see C.ulimit C.ulimit (not implemented)
     * @see C.unistd C.unistd (almost implemented)
     * @see C.utime C.utime (not planned)
     * @see C.utmpx C.utmpx (not planned)
     * @see C.wchar C.wchar (not planned)
     * @see C.wctype C.wctype (not planned)
     * @see C.wordexp C.wordexp (not planned)
     * @see http://en.wikipedia.org/wiki/POSIX POSIX (Wikipedia)
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/ POSIX.1-2008 (The Open Group Base Specifications)
     */
    public const POSIX:String = "POSIX.1-2008 API";

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
     //public const SYS_STAT_H:String = "sys/stat.h documentation";

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
     //public const UNISTD_H:String = "unistd.h documentation";
}