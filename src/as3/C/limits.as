/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package C.limits
{

    /**
     * @name <code>&lt;limits.h&gt;</code>
     * Implementation-defined constants.
     *
     * <p>
     * Defines macros and symbolic constants for various limits
     * on resources that the implementation imposes on applications.
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/limits.h.html limits.h
     */
    
    /** @internal */
    [native(cls="::avmshell::CLimitsClass", methods="auto", construct="none")]
    [Inspectable(environment="none")]
    internal class __limits
    {
        //numerical limits
        public native static function get CHAR_BIT():int;
        public native static function get CHAR_MAX():int;
        public native static function get CHAR_MIN():int;
        public native static function get INT_MAX():int;
        public native static function get INT_MIN():int;
        public native static function get LLONG_MAX():Number;
        public native static function get LLONG_MIN():Number;
        public native static function get LONG_BIT():int;
        public native static function get LONG_MAX():Number;
        public native static function get LONG_MIN():Number;
        public native static function get SCHAR_MAX():int;
        public native static function get SCHAR_MIN():int;
        public native static function get SHRT_MAX():int;
        public native static function get SHRT_MIN():int;
        public native static function get UCHAR_MAX():int;
        public native static function get UINT_MAX():uint;
        public native static function get ULLONG_MAX():Number;
        public native static function get ULONG_MAX():uint;
        public native static function get USHRT_MAX():int;
        public native static function get WORD_BIT():int;

        /* NOTE:
           change the type int to type Number
           for some const containing big values
           like SSIZE_MAX, SIZE_MAX, etc.
        */
       
        //shared
        public native static function get ARG_MAX():int;
        public native static function get ATEXIT_MAX():int;
        public native static function get CHILD_MAX():int;
        public native static function get LINK_MAX():int;
        public native static function get MAX_CANON():int;
        public native static function get MAX_INPUT():int;
        public native static function get NAME_MAX():int;
        public native static function get NGROUPS_MAX():int;
        public native static function get OPEN_MAX():int;
        public native static function get PATH_MAX():int;
        public native static function get PIPE_BUF():int;
        public native static function get SSIZE_MAX():Number; // for ssize_t
        public native static function get STREAM_MAX():int;
        public native static function get TZNAME_MAX():int;

        //shared - rest
        public native static function get MB_LEN_MAX():int;
        public native static function get SIZE_MAX():Number; //from stdint, for size_t
        public native static function get SYMLINK_MAX():int;

        //shared - compat
        public native static function get AIO_LISTIO_MAX():int;
        public native static function get AIO_MAX():int;
        public native static function get AIO_PRIO_DELTA_MAX():int;
        public native static function get DELAYTIMER_MAX():int;
        public native static function get HOST_NAME_MAX():int;
        //public native static function get IOV_MAX():int; // we don't support _XOPEN_anything
        public native static function get LOGIN_NAME_MAX():int;
        public native static function get MQ_OPEN_MAX():int;
        public native static function get MQ_PRIO_MAX():int;

        public native static function get PAGESIZE():int;
        public native static function get PAGE_SIZE():int;
        public native static function get RE_DUP_MAX():int;
        public native static function get RTSIG_MAX():int;
        public native static function get SEM_NSEMS_MAX():int;
        public native static function get SEM_VALUE_MAX():int;
        public native static function get SIGQUEUE_MAX():int;
        public native static function get SS_REPL_MAX():int;

        public native static function get SYMLOOP_MAX():int;
        public native static function get TIMER_MAX():int;
        public native static function get TRACE_EVENT_NAME_MAX():int;
        public native static function get TRACE_NAME_MAX():int;
        public native static function get TRACE_SYS_MAX():int;
        public native static function get TRACE_USER_EVENT_MAX():int;
        public native static function get TTY_NAME_MAX():int;

        //Windows only
        //RSIZE_MAX

        //POSIX only
        //
        
        //Macintosh only
        //

        //Linux only
        //
        
        //shared - POSIX min values
        public native static function get _POSIX_ARG_MAX():int;
        public native static function get _POSIX_CHILD_MAX():int;
        public native static function get _POSIX_LINK_MAX():int;
        public native static function get _POSIX_MAX_CANON():int;
        public native static function get _POSIX_MAX_INPUT():int;
        public native static function get _POSIX_NAME_MAX():int;
        public native static function get _POSIX_NGROUPS_MAX():int;
        public native static function get _POSIX_OPEN_MAX():int;
        public native static function get _POSIX_PATH_MAX():int;
        public native static function get _POSIX_PIPE_BUF():int;
        public native static function get _POSIX_SSIZE_MAX():int;
        public native static function get _POSIX_STREAM_MAX():int;
        public native static function get _POSIX_TZNAME_MAX():int;
        public native static function get _POSIX_SYMLINK_MAX():int;

        //shared - compat
        public native static function get _POSIX_AIO_LISTIO_MAX():int;
        public native static function get _POSIX_AIO_MAX():int;
        public native static function get _POSIX_DELAYTIMER_MAX():int;
        public native static function get _POSIX_HOST_NAME_MAX():int;
        public native static function get _POSIX_LOGIN_NAME_MAX():int;
        public native static function get _POSIX_MQ_OPEN_MAX():int;
        public native static function get _POSIX_MQ_PRIO_MAX():int;

        public native static function get _POSIX_RE_DUP_MAX():int;
        public native static function get _POSIX_RTSIG_MAX():int;
        public native static function get _POSIX_SEM_NSEMS_MAX():int;
        public native static function get _POSIX_SEM_VALUE_MAX():int;
        public native static function get _POSIX_SIGQUEUE_MAX():int;
        public native static function get _POSIX_SS_REPL_MAX():int;

        public native static function get _POSIX_SYMLOOP_MAX():int;
        public native static function get _POSIX_TIMER_MAX():int;
        public native static function get _POSIX_TRACE_EVENT_NAME_MAX():int;
        public native static function get _POSIX_TRACE_NAME_MAX():int;
        public native static function get _POSIX_TRACE_SYS_MAX():int;
        public native static function get _POSIX_TRACE_USER_EVENT_MAX():int;
        public native static function get _POSIX_TTY_NAME_MAX():int;
    }


    /**
     * Number of bits in a type <code>char</code>.
     * 
     * <p>
     * Value: 8
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const CHAR_BIT:int = __limits.CHAR_BIT;

    /**
     * Maximum value for an object of type <code>char</code>.
     * 
     * <p>
     * Value: UCHAR_MAX or SCHAR_MAX
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const CHAR_MAX:int = __limits.CHAR_MAX;

    /**
     * Minimum value for an object of type <code>char</code>.
     * 
     * <p>
     * Value: SCHAR_MIN or 0
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const CHAR_MIN:int = __limits.CHAR_MIN;

    /**
     * Maximum value for an object of type <code>int</code>.
     * 
     * <p>
     * Minimum Acceptable Value: 2147483647
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const INT_MAX:int = __limits.INT_MAX;

    /**
     * Minimum value for an object of type <code>int</code>.
     * 
     * <p>
     * Maximum Acceptable Value: -2147483647
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const INT_MIN:int = __limits.INT_MIN;

    /**
     * Maximum value for an object of type <code>long long</code>.
     * 
     * <p>
     * Minimum Acceptable Value: +9223372036854775807
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const LLONG_MAX:Number = __limits.LLONG_MAX;

    /**
     * Minimum value for an object of type <code>long long</code>.
     * 
     * <p>
     * Maximum Acceptable Value: -9223372036854775807
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const LLONG_MIN:Number = __limits.LLONG_MIN;

    /**
     * Number of bits in an object of type <code>long</code>.
     * 
     * <p>
     * Minimum Acceptable Value: 32
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const LONG_BIT:int = __limits.LONG_BIT;

    /**
     * Maximum value for an object of type <code>long</code>.
     * 
     * <p>
     * Minimum Acceptable Value: +2147483647
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const LONG_MAX:int = __limits.LONG_MAX;

    /**
     * Minimum value for an object of type <code>long</code>.
     * 
     * <p>
     * Maximum Acceptable Value: -2147483647
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const LONG_MIN:int = __limits.LONG_MIN;

    /**
     * Maximum value for an object of type <code>signed char</code>.
     * 
     * <p>
     * Value: +127
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const SCHAR_MAX:int = __limits.SCHAR_MAX;

    /**
     * Minimum value for an object of type <code>signed char</code>.
     * 
     * <p>
     * Value: -128
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const SCHAR_MIN:int = __limits.SCHAR_MIN;

    /**
     * Maximum value for an object of type <code>short</code>.
     * 
     * <p>
     * Minimum Acceptable Value: +32767
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const SHRT_MAX:int = __limits.SHRT_MAX;

    /**
     * Minimum value for an object of type <code>short</code>.
     * 
     * <p>
     * Maximum Acceptable Value: -32767
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const SHRT_MIN:int = __limits.SHRT_MIN;

    /**
     * Maximum value for an object of type <code>unsigned char</code>.
     * 
     * <p>
     * Value: 255
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const UCHAR_MAX:int = __limits.UCHAR_MAX;

    /**
     * Maximum value for an object of type <code>unsigned</code>.
     * 
     * <p>
     * Minimum Acceptable Value: 4294967295
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const UINT_MAX:uint = __limits.UINT_MAX;

    /**
     * Maximum value for an object of type <code>unsigned long long</code>.
     * 
     * <p>
     * Minimum Acceptable Value: 18446744073709551615
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const ULLONG_MAX:Number = __limits.ULLONG_MAX;

    /**
     * Maximum value for an object of type <code>unsigned long</code>.
     * 
     * <p>
     * Minimum Acceptable Value: 4294967295
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const ULONG_MAX:uint = __limits.ULONG_MAX;

    /**
     * Maximum value for an object of type <code>unsigned short</code>.
     * 
     * <p>
     * Minimum Acceptable Value: 65535
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const USHRT_MAX:int = __limits.USHRT_MAX;

    /**
     * Number of bits in an object of type <code>int</code>.
     * 
     * <p>
     * Minimum Acceptable Value: 32
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const WORD_BIT:int = __limits.WORD_BIT;



    /**
     * Maximum length of argument to the exec functions including environment data.
     * 
     * <p>
     * bytes of args + environ for exec().
     * </p>
     *
     * <p>
     * Minimum Acceptable Value: _POSIX_ARG_MAX
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const ARG_MAX:int = __limits.ARG_MAX;

    /**
     * Maximum number of functions that may be registered with <code>atexit()</code>.
     * 
     * <p>
     * Minimum Acceptable Value: 32
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const ATEXIT_MAX:int = __limits.ATEXIT_MAX;

    /**
     * Maximum number of simultaneous processes per real user ID.
     * 
     * <p>
     * Minimum Acceptable Value: _POSIX_CHILD_MAX
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const CHILD_MAX:int = __limits.CHILD_MAX;

    /**
     * Maximum number of links to a single file.
     * 
     * <p>
     * Minimum Acceptable Value: _POSIX_LINK_MAX
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const LINK_MAX:int = __limits.LINK_MAX;

    /**
     * Maximum number of bytes in a terminal canonical input line.
     * 
     * <p>
     * Minimum Acceptable Value: _POSIX_MAX_CANON
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const MAX_CANON:int = __limits.MAX_CANON;

    /**
     * Minimum number of bytes for which space is available in a terminal input queue;
     * therefore, the maximum number of bytes a conforming application may require
     * to be typed as input before reading them.
     * 
     * <p>
     * Minimum Acceptable Value: _POSIX_MAX_INPUT
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const MAX_INPUT:int = __limits.MAX_INPUT;

    /**
     * Maximum number of bytes in a filename (not including the terminating null of a filename string).
     * 
     * <p>
     * Minimum Acceptable Value: _POSIX_NAME_MAX
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const NAME_MAX:int = __limits.NAME_MAX;

    /**
     * Maximum number of simultaneous supplementary group IDs per process.
     * 
     * <p>
     * Minimum Acceptable Value: _POSIX_NGROUPS_MAX
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const NGROUPS_MAX:int = __limits.NGROUPS_MAX;

    /**
     * A value one greater than the maximum value that the system
     * may assign to a newly-created file descriptor.
     * 
     * <p>
     * Minimum Acceptable Value: _POSIX_OPEN_MAX
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const OPEN_MAX:int = __limits.OPEN_MAX;

    /**
     * Maximum number of bytes the implementation will store as a pathname
     * in a user-supplied buffer of unspecified size,
     * including the terminating null character.
     * 
     * Minimum number the implementation will accept as the maximum number
     * of bytes in a pathname.
     * 
     * <p>
     * Minimum Acceptable Value: _POSIX_PATH_MAX
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const PATH_MAX:int = __limits.PATH_MAX;

    /**
     * Maximum number of bytes that is guaranteed to be atomic when writing to a pipe.
     * 
     * <p>
     * Minimum Acceptable Value: _POSIX_PIPE_BUF
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const PIPE_BUF:int = __limits.PIPE_BUF;

    /**
     * Maximum value for an object of type ssize_t.
     *
     * <p>
     * Minimum Acceptable Value: _POSIX_SSIZE_MAX
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const SSIZE_MAX:int = __limits.SSIZE_MAX;

    /**
     * Maximum number of streams that one process
     * can have open at one time.
     * 
     * If defined, it has the same value as FOPEN_MAX (see stdio.h).
     *
     * <p>
     * Minimum Acceptable Value: _POSIX_STREAM_MAX
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const STREAM_MAX:int = __limits.STREAM_MAX;

    /**
     * Maximum number of bytes supported for the name of a timezone (not of the TZ variable).
     *
     * <p>
     * Minimum Acceptable Value: _POSIX_TZNAME_MAX
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const TZNAME_MAX:int = __limits.TZNAME_MAX;

    /**
     * Maximum number of bytes in a character, for any supported locale.
     *
     * <p>
     * Minimum Acceptable Value: 1
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const MB_LEN_MAX:int = __limits.MB_LEN_MAX;

    /**
     * Limit of size_t.
     *
     * <p>
     * defined in stdint
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const SIZE_MAX:int = __limits.SIZE_MAX;

    /**
     * Maximum number of bytes in a symbolic link.
     *
     * <p>
     * Minimum Acceptable Value: _POSIX_SYMLINK_MAX
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const SYMLINK_MAX:int = __limits.SYMLINK_MAX;

    /**
     * Maximum number of I/O operations in a single list I/O call supported by the implementation.
     *
     * <p>
     * Minimum Acceptable Value: _POSIX_AIO_LISTIO_MAX
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const AIO_LISTIO_MAX:int = __limits.AIO_LISTIO_MAX;

    /**
     * Maximum number of outstanding asynchronous I/O operations supported by the implementation.
     *
     * <p>
     * Minimum Acceptable Value: _POSIX_AIO_MAX
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const AIO_MAX:int = __limits.AIO_MAX;

    /**
     * The maximum amount by which a process can decrease its
     * asynchronous I/O priority level from its own scheduling priority.
     *
     * <p>
     * Minimum Acceptable Value: 0
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const AIO_PRIO_DELTA_MAX:int = __limits.AIO_PRIO_DELTA_MAX;

    /**
     * Maximum number of timer expiration overruns.
     *
     * <p>
     * Minimum Acceptable Value: _POSIX_DELAYTIMER_MAX
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const DELAYTIMER_MAX:int = __limits.DELAYTIMER_MAX;

    /**
     * Maximum length of a host name (not including the terminating null)
     * as returned from the gethostname() function.
     *
     * <p>
     * Minimum Acceptable Value: _POSIX_HOST_NAME_MAX
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const HOST_NAME_MAX:int = __limits.HOST_NAME_MAX;

    /**
     * Maximum length of a login name.
     *
     * <p>
     * Minimum Acceptable Value: _POSIX_LOGIN_NAME_MAX
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const LOGIN_NAME_MAX:int = __limits.LOGIN_NAME_MAX;

    /**
     * The maximum number of open message queue descriptors a process may hold.
     *
     * <p>
     * Minimum Acceptable Value: _POSIX_MQ_OPEN_MAX
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const MQ_OPEN_MAX:int = __limits.MQ_OPEN_MAX;

    /**
     * The maximum number of message priorities supported by the implementation.
     *
     * <p>
     * Minimum Acceptable Value: _POSIX_MQ_PRIO_MAX
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const MQ_PRIO_MAX:int = __limits.MQ_PRIO_MAX;

    /**
     * Size in bytes of a page.
     *
     * <p>
     * Minimum Acceptable Value: 1
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const PAGESIZE:int = __limits.PAGESIZE;

    /**
     * Equivalent to <code>PAGESIZE</code>.
     *
     * <p>
     * Minimum Acceptable Value: 1
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const PAGE_SIZE:int = __limits.PAGE_SIZE;

    /**
     * Maximum number of repeated occurrences of a BRE or ERE interval expression.
     *
     * Maximum number of repeated occurrences of a regular expression permitted when
     * using the interval notation <code>\{m,n\}</code>.
     *
     * <p>
     * Minimum Acceptable Value: _POSIX_RE_DUP_MAX
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap09.html#tag_09_03_06 BREs Matching Multiple Characters
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap09.html#tag_09_04_06 EREs Matching Multiple Characters
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap09.html#tag_09 Regular Expressions
     */
     public const RE_DUP_MAX:int = __limits.RE_DUP_MAX;

    /**
     * Maximum number of realtime signals reserved for application use in this implementation.
     *
     * <p>
     * Minimum Acceptable Value: _POSIX_RTSIG_MAX
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const RTSIG_MAX:int = __limits.RTSIG_MAX;

    /**
     * Maximum number of semaphores that a process may have.
     * 
     * <p>
     * Minimum Acceptable Value: _POSIX_SEM_NSEMS_MAX
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const SEM_NSEMS_MAX:int = __limits.SEM_NSEMS_MAX;

    /**
     * The maximum value a semaphore may have.
     * 
     * <p>
     * Minimum Acceptable Value: _POSIX_SEM_VALUE_MAX
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const SEM_VALUE_MAX:int = __limits.SEM_VALUE_MAX;

    /**
     * Maximum number of queued signals that a process may send
     * and have pending at the receiver(s) at any time.
     * 
     * <p>
     * Minimum Acceptable Value: _POSIX_SIGQUEUE_MAX
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const SIGQUEUE_MAX:int = __limits.SIGQUEUE_MAX;

    /**
     * The maximum number of replenishment operations
     * that may be simultaneously pending for a particular sporadic server scheduler.
     * 
     * <p>
     * Minimum Acceptable Value: _POSIX_SS_REPL_MAX
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const SS_REPL_MAX:int = __limits.SS_REPL_MAX;

    /**
     * Maximum number of symbolic links that can be reliably traversed
     * in the resolution of a pathname in the absence of a loop.
     * 
     * <p>
     * Minimum Acceptable Value: _POSIX_SYMLOOP_MAX
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const SYMLOOP_MAX:int = __limits.SYMLOOP_MAX;

    /**
     * Maximum number of timers per process supported by the implementation.
     * 
     * <p>
     * Minimum Acceptable Value: _POSIX_TIMER_MAX
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const TIMER_MAX:int = __limits.TIMER_MAX;

    /**
     * Maximum length of the trace event name (not including the terminating null).
     * 
     * <p>
     * Minimum Acceptable Value: _POSIX_TRACE_EVENT_NAME_MAX
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const TRACE_EVENT_NAME_MAX:int = __limits.TRACE_EVENT_NAME_MAX;

    /**
     * Maximum length of the trace generation version string
     * or of the trace stream name (not including the terminating nul
     * 
     * <p>
     * Minimum Acceptable Value: _POSIX_TRACE_NAME_MAX
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const TRACE_NAME_MAX:int = __limits.TRACE_NAME_MAX;

    /**
     * Maximum number of trace streams that may simultaneously exist in the system.
     * 
     * <p>
     * Minimum Acceptable Value: _POSIX_TRACE_SYS_MAX
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const TRACE_SYS_MAX:int = __limits.TRACE_SYS_MAX;

    /**
     * Maximum number of user trace event type identifiers that may simultaneously exist
     * in a traced process, including the predefined user trace event
     * <code>POSIX_TRACE_UNNAMED_USER_EVENT</code>.
     * 
     * <p>
     * Minimum Acceptable Value: _POSIX_TRACE_USER_EVENT_MAX
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const TRACE_USER_EVENT_MAX:int = __limits.TRACE_USER_EVENT_MAX;

    /**
     * Maximum length of terminal device name.
     * 
     * <p>
     * Minimum Acceptable Value: _POSIX_TTY_NAME_MAX
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const TTY_NAME_MAX:int = __limits.TTY_NAME_MAX;








    /**
     * Maximum length of argument to the exec functions including environment data.
     *
     * <p>
     * Value: 4 096
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const _POSIX_ARG_MAX:int = __limits._POSIX_ARG_MAX;

    /**
     * Maximum number of simultaneous processes per real user ID.
     *
     * <p>
     * Value: 25
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const _POSIX_CHILD_MAX:int = __limits._POSIX_CHILD_MAX;

    /**
     * Maximum number of links to a single file.
     *
     * <p>
     * Value: 8
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const _POSIX_LINK_MAX:int = __limits._POSIX_LINK_MAX;

    /**
     * Maximum number of bytes in a terminal canonical input queue.
     *
     * <p>
     * Value: 255
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const _POSIX_MAX_CANON:int = __limits._POSIX_MAX_CANON;

    /**
     * Maximum number of bytes allowed in a terminal input queue.
     *
     * <p>
     * Value: 255
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const _POSIX_MAX_INPUT:int = __limits._POSIX_MAX_INPUT;

    /**
     * Maximum number of bytes in a filename (not including the terminating null of a filename string).
     *
     * <p>
     * Value: 14
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const _POSIX_NAME_MAX:int = __limits._POSIX_NAME_MAX;

    /**
     * Maximum number of simultaneous supplementary group IDs per process.
     *
     * <p>
     * Value: 8 (Windows: 0)
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const _POSIX_NGROUPS_MAX:int = __limits._POSIX_NGROUPS_MAX;

    /**
     * A value one greater than the maximum value that the system
     * may assign to a newly-created file descriptor.
     *
     * <p>
     * Value: 20
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const _POSIX_OPEN_MAX:int = __limits._POSIX_OPEN_MAX;

    /**
     * Minimum number the implementation will accept as the maximum number of bytes in a pathname.
     *
     * <p>
     * Value: 256
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const _POSIX_PATH_MAX:int = __limits._POSIX_PATH_MAX;

    /**
     * Maximum number of bytes that is guaranteed to be atomic when writing to a pipe.
     *
     * <p>
     * Value: 512
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const _POSIX_PIPE_BUF:int = __limits._POSIX_PIPE_BUF;

    /**
     * The value that can be stored in an object of type ssize_t.
     *
     * <p>
     * Value: 32 767
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const _POSIX_SSIZE_MAX:int = __limits._POSIX_SSIZE_MAX;

    /**
     * The number of streams that one process can have open at one time.
     *
     * <p>
     * Value: 8
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const _POSIX_STREAM_MAX:int = __limits._POSIX_STREAM_MAX;

    /**
     * Maximum number of bytes supported for the name of a timezone (not of the TZ variable).
     *
     * <p>
     * Value: 6
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const _POSIX_TZNAME_MAX:int = __limits._POSIX_TZNAME_MAX;

    /**
     * The number of bytes in a symbolic link.
     *
     * <p>
     * Value: 255
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const _POSIX_SYMLINK_MAX:int = __limits._POSIX_SYMLINK_MAX;

    /**
     * The number of I/O operations that can be specified in a list I/O call.
     *
     * <p>
     * Value: 2
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const _POSIX_AIO_LISTIO_MAX:int = __limits._POSIX_AIO_LISTIO_MAX;

    /**
     * The number of outstanding asynchronous I/O operations.
     *
     * <p>
     * Value: 1
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const _POSIX_AIO_MAX:int = __limits._POSIX_AIO_MAX;

    /**
     * The number of timer expiration overruns.
     *
     * <p>
     * Value: 32
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const _POSIX_DELAYTIMER_MAX:int = __limits._POSIX_DELAYTIMER_MAX;

    /**
     * Maximum length of a host name (not including the terminating null)
     * as returned from the gethostname() function.
     *
     * <p>
     * Value: 255
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const _POSIX_HOST_NAME_MAX:int = __limits._POSIX_HOST_NAME_MAX;

    /**
     * The size of the storage required for a login name,
     * in bytes (including the terminating null).
     *
     * <p>
     * Value: 9
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const _POSIX_LOGIN_NAME_MAX:int = __limits._POSIX_LOGIN_NAME_MAX;

    /**
     * The number of message queues that can be open for a single process.
     *
     * <p>
     * Value: 8
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const _POSIX_MQ_OPEN_MAX:int = __limits._POSIX_MQ_OPEN_MAX;

    /**
     * The maximum number of message priorities supported by the implementation.
     *
     * <p>
     * Value: 32
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const _POSIX_MQ_PRIO_MAX:int = __limits._POSIX_MQ_PRIO_MAX;

    /**
     * The number of repeated occurrences of a BRE permitted by the regexec() and regcomp()
     * functions when using the interval notation <code>{\(m,n\}</code>.
     *
     * <p>
     * Value: 255
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap09.html#tag_09_03_06 BREs Matching Multiple Characters
     */
     public const _POSIX_RE_DUP_MAX:int = __limits._POSIX_RE_DUP_MAX;

    /**
     * The number of realtime signal numbers reserved for application use.
     *
     * <p>
     * Value: 8
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const _POSIX_RTSIG_MAX:int = __limits._POSIX_RTSIG_MAX;

    /**
     * The number of semaphores that a process may have.
     *
     * <p>
     * Value: 256
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const _POSIX_SEM_NSEMS_MAX:int = __limits._POSIX_SEM_NSEMS_MAX;

    /**
     * The maximum value a semaphore may have.
     *
     * <p>
     * Value: 32767
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const _POSIX_SEM_VALUE_MAX:int = __limits._POSIX_SEM_VALUE_MAX;

    /**
     * The number of queued signals that a process may send
     * and have pending at the receiver(s) at any time.
     *
     * <p>
     * Value: 32
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const _POSIX_SIGQUEUE_MAX:int = __limits._POSIX_SIGQUEUE_MAX;

    /**
     * The number of replenishment operations
     * that may be simultaneously pending for a particular sporadic server scheduler.
     *
     * <p>
     * Value: 4
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const _POSIX_SS_REPL_MAX:int = __limits._POSIX_SS_REPL_MAX;

    /**
     * The number of symbolic links that can be traversed in the
     * resolution of a pathname in the absence of a loop.
     *
     * <p>
     * Value: 8
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const _POSIX_SYMLOOP_MAX:int = __limits._POSIX_SYMLOOP_MAX;

    /**
     * The per-process number of timers.
     *
     * <p>
     * Value: 32
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const _POSIX_TIMER_MAX:int = __limits._POSIX_TIMER_MAX;

    /**
     * The length in bytes of a trace event name (not including the terminating null).
     *
     * <p>
     * Value: 30
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const _POSIX_TRACE_EVENT_NAME_MAX:int = __limits._POSIX_TRACE_EVENT_NAME_MAX;

    /**
     * The length in bytes of a trace generation version string
     * or a trace stream name (not including the terminating null).
     *
     * <p>
     * Value: 8
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const _POSIX_TRACE_NAME_MAX:int = __limits._POSIX_TRACE_NAME_MAX;

    /**
     * The number of trace streams that may simultaneously exist in the system.
     *
     * <p>
     * Value: 8
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const _POSIX_TRACE_SYS_MAX:int = __limits._POSIX_TRACE_SYS_MAX;

    /**
     * The number of user trace event type identifiers that may simultaneously exist
     * in a traced process, including the predefined user trace event
     * <code>POSIX_TRACE_UNNAMED_USER_EVENT</code>.
     *
     * <p>
     * Value: 32
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const _POSIX_TRACE_USER_EVENT_MAX:int = __limits._POSIX_TRACE_USER_EVENT_MAX;

    /**
     * The size of the storage required for a terminal device name,
     * in bytes (including the terminating null).
     *
     * <p>
     * Value: 9
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const _POSIX_TTY_NAME_MAX:int = __limits._POSIX_TTY_NAME_MAX;

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