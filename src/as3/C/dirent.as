/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package C.dirent
{

    /**
     * @name <code>&lt;dirent.h&gt;</code>
     * Format of directory entries.
     * 
     * <p>
     * Contains constructs that facilitate directory traversing.
     * The function is not part of the C standard,
     * but is considered "pseudo-standard"
     * and is usually portable between platforms.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/dirent.h.html dirent.h
     */

    /**
     * Close a directory stream.
     *
     * <p>
     * TODO
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CDirentClass::closedir")]
    public native function closedir( dirp:DIR ):int;

    /**
     * Extract the file descriptor used by a DIR stream.
     *
     * <p>
     * TODO
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CDirentClass::dirfd")]
    public native function dirfd( dirp:DIR ):int;

    /**
     * Open directory associated with name.
     *
     * <p>
     * TODO
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion POSIX +
     */
    [native("::avmshell::CDirentClass::fdopendir")]
    public native function fdopendir( fd:int ):DIR;

    /**
     * Read directory entries from a directory path.
     *
     * <p>
     * Non-standard extension
     * </p>
     *
     * <p>
     * For more advanced listing you should implement your own function
     * based on <code>opendir()</code>, <code>readdir()</code> and <code>closedir()</code>.
     *
     * For example, if you may want to list only files and
     * sort them by size
     * </p>
     *
     * <p>
     * You can use Arrays sort functions on the result.
     * </p>
     *
     * @example Basic sorting
     * <listing>
     * var dir:Array = getdirentries( "." );
     *     dir.sort( Array.DESCENDING | Array.CASEINSENSITIVE );
     * </listing>
     *
     * @example Build your own custom functions
     * <listing>
     * function getFilesBySize( dirname:String, smallerFirst:Boolean = true ):String
     * {
     *     var entries:Array = [];
     *     var entries:Array = [];
     *     //format: { name: , size: }
     *     
     *     var d:DIR = opendir( dirname );
     *     if( d == null )
     *     {
     *        //opendir() set errno
     *        return null;
     *     }
     *     
     *     var dp:dirent;
     *     var statbuf:status;
     *     var ffd:int;
     *     while( (dp = readdir(d)) != null )
     *     {
     *         //ignore dot and dotdot
     *         if( (dp.d_name == ".") || (dp.d_name == "..") )
     *         {
     *             continue;
     *         }
     *     
     *        statbuf = new status();
     *        ffd = stat( dirname + "/" + dp.d_name, statbuf );
     *     
     *        if( S_ISREG( statbuf.st_mode ) )
     *        {
     *            entries.push( { name:dp.d_name, size:statbuf.st_size } );
     *        }
     *     }
     *     closedir( d );
     *     
     *     if( smallerFirst )
     *     {
     *        entries.sortOn( "size", Array.NUMERIC );
     *     }
     *     else
     *     {
     *        entries.sortOn( "size", Array.DESCENDING | Array.NUMERIC );
     *     }
     *     
     *     return entries;
     * }
     *
     * function printFiles( files:Array ):void
     * {
     *     var i:uint;
     *     var len:uint = files.length;
     *     var file:Object;
     *     for( i=0; i&lt;len; i++ )
     *     {
     *         file = files[i];
     *         trace( file.name + " - " + file.size + " bytes" );
     *     }
     * }
     *
     * //usage
     * var list:Array = getFilesBySize( "." );
     * trace( "found " + list.length + " files" );
     * printFiles( list );
     * </listing>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function getdirentries( dirname:String ):Array
    {
        var entries:Array = [];

        var d:DIR = opendir( dirname );
        if( d == null )
        {
            //opendir() set errno
            return null;
        }

        var dp:dirent;
        while( (dp = readdir(d)) != null )
        {
            entries.push( dp.d_name );
        }
        closedir( d );

        return entries;
    }

    /**
     * Open directory associated with name.
     *
     * <p>
     * TODO
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CDirentClass::opendir")]
    public native function opendir( dirname:String ):DIR;

    /**
     * Read a directory.
     *
     * <p>
     * TODO
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CDirentClass::readdir")]
    public native function readdir( dirp:DIR ):dirent;

    /**
     * Reset the position of a directory stream to the beginning of a directory.
     *
     * <p>
     * TODO
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CDirentClass::rewinddir")]
    public native function rewinddir( dirp:DIR ):void;

    /**
     * Set the position of a directory stream.
     *
     * <p>
     * TODO
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CDirentClass::seekdir")]
    public native function seekdir( dirp:DIR, loc:Number ):void;

    /**
     * Current location of a named directory stream.
     *
     * <p>
     * TODO
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CDirentClass::telldir")]
    public native function telldir( dirp:DIR ):Number;




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
