/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package C.fcntl
{

    /**
     * @name <code>&lt;fcntl.h&gt;</code>
     * File control options and operations.
     *
     * <p>
     * Contains constructs that refer to file control,
     * e.g. opening a file,
     * retrieving and changing the permissions of file,
     * locking a file for edit, etc.
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/fcntl.h.html fcntl.h
     */

    /** @internal */
    [native(cls="::avmshell::CFcntlClass", methods="auto", construct="none")]
    [Inspectable(environment="none")]
    internal class __fcntl
    {
        /*
        O_TTY_INIT     - ??- missing ?
        O_EXEC         - ??- missing ?
        O_SEARCH       - ??- missing ?
        */
       
        //shared
        public native static function get O_RDONLY():int;
        public native static function get O_WRONLY():int;
        public native static function get O_RDWR():int;
        public native static function get O_ACCMODE():int;

        public native static function get O_APPEND():int;
        public native static function get O_CREAT():int;
        public native static function get O_TRUNC():int;
        public native static function get O_EXCL():int;

        //POSIX only
        public native static function get O_EXEC():int;
        public native static function get O_CLOEXEC():int;
        public native static function get O_DIRECTORY():int;
        public native static function get O_NOFOLLOW():int;
        public native static function get O_NONBLOCK():int;
        public native static function get O_NOCTTY():int;
        public native static function get O_SEARCH():int;
        public native static function get O_TTY_INIT():int;
        
        public native static function get O_SYNC():int;
        public native static function get O_DSYNC():int;
        public native static function get O_RSYNC():int;
        public native static function get O_ASYNC():int;
        public native static function get O_FSYNC():int;

        //macintosh only
        public native static function get O_SHLOCK():int;
        public native static function get O_EXLOCK():int;

        //windows only
        public native static function get O_TEXT():int;
        public native static function get O_BINARY():int;
        public native static function get O_WTEXT():int;
        public native static function get O_U16TEXT():int;
        public native static function get O_U8TEXT():int;
        public native static function get O_RAW():int;
        public native static function get O_NOINHERIT():int;
        public native static function get O_TEMPORARY():int;
        public native static function get O_SHORT_LIVED():int;
        public native static function get O_SEQUENTIAL():int;
        public native static function get O_RANDOM():int;
        
        //POSIX only
        public native static function get F_DUPFD():int;
        public native static function get F_DUPFD_CLOEXEC():int;
        public native static function get F_GETFD():int;
        public native static function get F_SETFD():int;
        public native static function get F_GETFL():int;
        public native static function get F_SETFL():int;
        public native static function get F_GETOWN():int;
        public native static function get F_SETOWN():int;

        //not supported
        //F_GETLK
        //F_SETLK
        //F_SETLKW
    }

    //----shared----

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


    //----posix----

    /**
     * Open for execute only (non-directory files).
     * The result is unspecified if this flag is applied to a directory.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const O_EXEC:int = __fcntl.O_EXEC;
    
    /**
     * implicitly set FD_CLOEXEC (Set "close on exec").
     *
     * The FD_CLOEXEC flag associated with the new descriptor
     * shall be set to close the file descriptor upon execution of an exec family function.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion POSIX +
     */
    public const O_CLOEXEC:int = __fcntl.O_CLOEXEC;

    /**
     * Fail if not a directory.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion POSIX +
     */
    public const O_DIRECTORY:int = __fcntl.O_DIRECTORY;

    /**
     * Do not follow symbolic links.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion POSIX +
     */
    public const O_NOFOLLOW:int = __fcntl.O_NOFOLLOW;

    /**
     * Non-blocking mode.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion POSIX +
     */
    public const O_NONBLOCK:int = __fcntl.O_NONBLOCK;

    /**
     * Do not assign controlling terminal.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion POSIX +
     */
    public const O_NOCTTY:int = __fcntl.O_NOCTTY;

    /**
     * Open directory for search only.
     * The result is unspecified if this flag is applied to a non-directory file.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const O_SEARCH:int = __fcntl.O_SEARCH;

    /**
     * If path identifies a terminal device other than a pseudo-terminal,
     * the device is not already open in any process, and either O_TTY_INIT
     * is set in oflag or O_TTY_INIT has the value zero, open() shall set
     * any non-standard termios structure terminal parameters to a state
     * that provides conforming behavior; see <a href="http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap11.html#tag_11_02">Parameters that Can be Set</a>.
     *
     * It is unspecified whether O_TTY_INIT has any effect if the device is already open
     * in any process.
     * 
     * If path identifies the slave side of a pseudo-terminal that is not already open
     * in any process, open() shall set any non-standard termios structure terminal
     * parameters to a state that provides conforming behavior,
     * regardless of whether O_TTY_INIT is set.
     * 
     * If path does not identify a terminal device, O_TTY_INIT shall be ignored.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap11.html#tag_11_02 Parameters that Can be Set 
     */
    public const O_TTY_INIT:int = __fcntl.O_TTY_INIT;




    /**
     * Write according to synchronized I/O file integrity completion.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion POSIX +
     */
    public const O_SYNC:int = __fcntl.O_SYNC;

    /**
     * Write according to synchronized I/O data integrity completion.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion POSIX +
     */
    public const O_DSYNC:int = __fcntl.O_DSYNC;

    /**
     * Synchronized read I/O operations.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion POSIX +
     */
    public const O_RSYNC:int = __fcntl.O_RSYNC;

    /**
     * signal pgrp when data ready.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion POSIX +
     */
    public const O_ASYNC:int = __fcntl.O_ASYNC;

    /**
     * source compatibility: do not use.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion POSIX +
     */
    public const O_FSYNC:int = __fcntl.O_FSYNC;


    //----macintosh----
    
    /**
     * open with shared file lock.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion MAC +
     */
    public const O_SHLOCK:int = __fcntl.O_SHLOCK;

    /**
     * open with exclusive file lock.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion MAC +
     */
    public const O_EXLOCK:int = __fcntl.O_EXLOCK;


    //----windows----
    
    /**
     * Opens a file in text (translated) mode.
     *
     * O_TEXT files have <code>&lt;cr&gt;&lt;lf&gt;</code> sequences translated
     * to <code>&lt;lf&gt;</code> on <code>read()</code>'s,
     * and <code>&lt;lf&gt;</code> sequences translated
     * to <code>&lt;cr&gt;&lt;lf&gt;</code> on <code>write()</code>'s
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion WIN +
     */
    public const O_TEXT:int = __fcntl.O_TEXT;

    /**
     * Opens a file in binary (untranslated) mode.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion WIN +
     */
    public const O_BINARY:int = __fcntl.O_BINARY;

    /**
     * Open the file in Unicode mode, UTF16 (translated).
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion WIN +
     */
    public const O_WTEXT:int = __fcntl.O_WTEXT;

    /**
     * Open the file in Unicode UTF-16 mode, UTF16 no BOM (translated).
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion WIN +
     */
    public const O_U16TEXT:int = __fcntl.O_U16TEXT;

    /**
     * Open the file in Unicode UTF-8 mode, UTF8  no BOM (translated).
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion WIN +
     */
    public const O_U8TEXT:int = __fcntl.O_U8TEXT;

    /**
     * macro to translate the C 2.0 name used to force binary mode for files.
     *
     * Equivalent to O_BINARY
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion WIN +
     */
    public const O_RAW:int = __fcntl.O_RAW;

    /**
     * Prevents creation of a shared file descriptor.
     *
     * child process doesn't inherit file
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion WIN +
     */
    public const O_NOINHERIT:int = __fcntl.O_NOINHERIT;

    /**
     * Temporary file bit - file is deleted when last handle is closed.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion WIN +
     */
    public const O_TEMPORARY:int = __fcntl.O_TEMPORARY;

    /**
     * temporary access hint.
     *
     * temporary storage file, try not to flush.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion WIN +
     */
    public const O_SHORT_LIVED:int = __fcntl.O_SHORT_LIVED;

    /**
     * Specifies that caching is optimized for, but not restricted to,
     * sequential access from disk.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion WIN +
     */
    public const O_SEQUENTIAL:int = __fcntl.O_SEQUENTIAL;

    /**
     * Specifies that caching is optimized for, but not restricted to, random access from disk.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion WIN +
     */
    public const O_RANDOM:int = __fcntl.O_RANDOM;



    //----posix----
    
    /**
     * Return a new file descriptor which shall be the lowest numbered available
     * (that is, not already open) file descriptor greater than or equal to the third argument,
     * arg, taken as an integer of type int. The new file descriptor shall refer to the
     * same open file description as the original file descriptor, and shall share any locks.
     * 
     * The FD_CLOEXEC flag associated with the new file descriptor shall be cleared to keep
     * the file open across calls to one of the exec functions.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion POSIX +
     */
    public const F_DUPFD:int = __fcntl.F_DUPFD;

    /**
     * Like F_DUPFD, but the FD_CLOEXEC flag associated with the new file descriptor
     * shall be set.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion POSIX +
     */
    public const F_DUPFD_CLOEXEC:int = __fcntl.F_DUPFD_CLOEXEC;

    /**
     * Get the file descriptor flags defined in fcntl.h that are associated with
     * the file descriptor fildes.
     * 
     * File descriptor flags are associated with a single file descriptor
     * and do not affect other file descriptors that refer to the same file.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion POSIX +
     */
    public const F_GETFD:int = __fcntl.F_GETFD;

    /**
     * Set the file descriptor flags defined in fcntl.h, that are associated with fildes,
     * to the third argument, arg, taken as type int.
     * 
     * If the FD_CLOEXEC flag in the third argument is 0,
     * the file descriptor shall remain open across the exec functions;
     * otherwise, the file descriptor shall be closed upon successful execution of one
     * of the exec functions.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion POSIX +
     */
    public const F_SETFD:int = __fcntl.F_SETFD;

    /**
     * Get the file status flags and file access modes, defined in fcntl.h,
     * for the file description associated with fildes.
     * 
     * The file access modes can be extracted from the return value using
     * the mask O_ACCMODE, which is defined in fcntl.h.
     * 
     * File status flags and file access modes are associated with the file description
     * and do not affect other file descriptors that refer to the same file with
     * different open file descriptions.
     * 
     * The flags returned may include non-standard file status flags which
     * the application did not set, provided that these additional flags
     * do not alter the behavior of a conforming application.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion POSIX +
     */
    public const F_GETFL:int = __fcntl.F_GETFL;

    /**
     * Set the file status flags, defined in fcntl.h, for the file description
     * associated with fildes from the corresponding bits in the third argument, arg,
     * taken as type int.
     * 
     * Bits corresponding to the file access mode and the file creation flags,
     * as defined in fcntl.h, that are set in arg shall be ignored.
     * 
     * If any bits in arg other than those mentioned here are changed by the application,
     * the result is unspecified.
     * 
     * If fildes does not support non-blocking operations, it is unspecified whether
     * the O_NONBLOCK flag will be ignored.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion POSIX +
     */
    public const F_SETFL:int = __fcntl.F_SETFL;

    /**
     * If fildes refers to a socket, get the process or process group ID specified
     * to receive SIGURG signals when out-of-band data is available.
     * 
     * Positive values indicate a process ID; negative values, other than -1,
     * indicate a process group ID.
     * 
     * If fildes does not refer to a socket, the results are unspecified.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion POSIX +
     */
    public const F_GETOWN:int = __fcntl.F_GETOWN;

    /**
     * If fildes refers to a socket, set the process or process group ID specified
     * to receive SIGURG signals when out-of-band data is available,
     * using the value of the third argument, arg, taken as type int.
     * 
     * Positive values indicate a process ID;
     * negative values, other than -1, indicate a process group ID.
     * 
     * If fildes does not refer to a socket, the results are unspecified.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion POSIX +
     */
    public const F_SETOWN:int = __fcntl.F_SETOWN;


    /**
     * Create a new file or rewrite an existing one.
     * 
     * <p>
     * TODO
     * </p>
     * 
     * @example The <code>creat()</code> function shall behave as if it is implemented as follows:
     * <listing>
     * function creat( path:String, mode:int ):int
     * {
     *     return open( path, O_WRONLY|O_CREAT|O_TRUNC, mode );
     * }
     * </listing>
     *
     * @example Creating a file
     * <listing>
     * var fd:int;
     * var mode:int = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
     * var pathname:String = "/tmp/file";
     * 
     * fd = creat( pathname, mode );
     * </listing>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CFcntlClass::creat")]
    public native function creat( path:String, mode:int ):int;

    /**
     * File control.
     * 
     * <p>
     * TODO
     * </p>
     * 
     * @example 
     * 
     * <listing>
     * var s:int = socket(PF_INET, SOCK_STREAM, 0);
     * 
     * fcntl(s, F_SETFL, O_NONBLOCK);  // set to non-blocking
     * 
     * fcntl(s, F_SETFL, O_ASYNC);     // set to asynchronous I/O
     * </listing>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion POSIX +
     *
     * @see http://www.beej.us/guide/bgnet/output/html/multipage/fcntlman.html
     */
    [native("::avmshell::CFcntlClass::fcntl")]
    public native function fcntl( fildes:int, cmd:int, arg:int = -1 ):int;

    /**
     * Open file relative to a path.
     *
     * <p>
     * TODO
     * </p>
     * 
     * @example Opening a File for Writing by the Owner
     * <listing>
     * var fd:int;
     * var mode:int = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
     * var pathname:String = "/tmp/file";
     * 
     * fd = open( pathname, O_WRONLY | O_CREAT | O_TRUNC, mode );
     * </listing>
     *
     * @example Opening a File Using an Existence Check
     * <listing>
     * var lockedfile:String = "/etc/ptmp";
     * 
     * var pfd:int; // Integer for file descriptor returned by open() call.
     * var oflag:int = O_WRONLY | O_CREAT | O_EXCL;
     * var mode:int = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
     * 
     * if( (pfd = open( lockedfile, oflag, mode)) == -1 )
     * {
     *     trace( "Cannot open /etc/ptmp. Try again later." );
     *     exit(1);
     * }
     * </listing>
     *
     * @example Opening a File for Writing
     * <listing>
     * var lockedfile:String = "/etc/ptmp";
     * 
     * var pfd:int;
     * var mode:int = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
     * 
     * if( (pfd = open(pathname, O_WRONLY | O_CREAT | O_TRUNC, mode)) == -1 )
     * {
     *     trace( "Cannot open output file." );
     *     exit(1);
     * }
     * </listing>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CFcntlClass::open")]
    public native function open( path:String, oflag:int, mode:int = -1 ):int;

    /**
     * Open file relative to directory file descriptor.
     *
     * <p>
     * TODO
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     *
     * @internal can be patched later for Macintosh
     * see https://github.com/gittup/tup/blob/master/src/compat/openat.c
     */
    [native("::avmshell::CFcntlClass::openat")]
    public native function openat( fd:int, path:String, oflag:int, mode:int = -1 ):int;

}
