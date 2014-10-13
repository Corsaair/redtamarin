/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package C.errno
{
    import C.string.*;

    /**
     * @name <code>&lt;errno.h&gt;</code>
     * System error numbers.
     *
     * <p>
     * Defines macros to report error conditions
     * through error codes stored in a static location called errno.
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/errno.h.html errno.h
     */

    /** @internal */
    [native(cls="::avmshell::CErrnoClass", methods="auto", construct="none")]
    [Inspectable(environment="none")]
    internal class __errno
    {
        //shared - standards
        public native static function get EPERM():int;
        public native static function get ENOENT():int;
        public native static function get ESRCH():int;
        public native static function get EINTR():int;
        public native static function get EIO():int;
        public native static function get ENXIO():int;
        public native static function get E2BIG():int;
        public native static function get ENOEXEC():int;
        public native static function get EBADF():int;
        public native static function get ECHILD():int;
        public native static function get EAGAIN():int;
        public native static function get ENOMEM():int;
        public native static function get EACCES():int;
        public native static function get EFAULT():int;
        public native static function get ENOTBLK():int;
        public native static function get EBUSY():int;
        public native static function get EEXIST():int;
        public native static function get EXDEV():int;
        public native static function get ENODEV():int;
        public native static function get ENOTDIR():int;
        public native static function get EISDIR():int;
        public native static function get EINVAL():int;
        public native static function get ENFILE():int;
        public native static function get EMFILE():int;
        public native static function get ENOTTY():int;
        public native static function get ETXTBSY():int;
        public native static function get EFBIG():int;
        public native static function get ENOSPC():int;
        public native static function get ESPIPE():int;
        public native static function get EROFS():int;
        public native static function get EMLINK():int;
        public native static function get EPIPE():int;
        public native static function get EDOM():int;
        public native static function get ERANGE():int;

        //shared - the rest
        public native static function get EDEADLK():int;
        public native static function get ENAMETOOLONG():int;
        public native static function get ENOLCK():int;
        public native static function get ENOSYS():int;
        public native static function get ENOTEMPTY():int;
        public native static function get ELOOP():int;
        public native static function get EWOULDBLOCK():int;
        public native static function get ENOMSG():int;
        public native static function get EIDRM():int;

        public native static function get EDEADLOCK():int; //equivalent to EDEADLK

        public native static function get ENOSTR():int;
        public native static function get ENODATA():int;
        public native static function get ETIME():int;
        public native static function get ENOSR():int;
        public native static function get ENOLINK():int;
        public native static function get EBADMSG():int;
        public native static function get EOVERFLOW():int;
        public native static function get EILSEQ():int;
        public native static function get ENOTSOCK():int;
        public native static function get EDESTADDRREQ():int;
        public native static function get EMSGSIZE():int;
        public native static function get EPROTO():int;
        public native static function get EPROTOTYPE():int;
        public native static function get ENOPROTOOPT():int;
        public native static function get EPROTONOSUPPORT():int;
        public native static function get EOPNOTSUPP():int;
        public native static function get EAFNOSUPPORT():int;
        public native static function get EADDRINUSE():int;
        public native static function get EADDRNOTAVAIL():int;
        public native static function get ENETDOWN():int;
        public native static function get ENETUNREACH():int;
        public native static function get ENETRESET():int;
        public native static function get ECONNABORTED():int;
        public native static function get ECONNRESET():int;
        public native static function get ENOBUFS():int;
        public native static function get EISCONN():int;
        public native static function get ENOTCONN():int;
        public native static function get ETIMEDOUT():int;
        public native static function get ECONNREFUSED():int;
        public native static function get EHOSTUNREACH():int;
        public native static function get EALREADY():int;
        public native static function get EINPROGRESS():int;
        public native static function get ECANCELED():int;
        public native static function get EOWNERDEAD():int;
        public native static function get ENOTRECOVERABLE():int;

        public native static function get EREMOTE():int;
        public native static function get EUSERS():int;
        public native static function get ESOCKTNOSUPPORT():int;
        public native static function get EPFNOSUPPORT():int;
        public native static function get ESHUTDOWN():int;
        public native static function get ETOOMANYREFS():int;
        public native static function get EHOSTDOWN():int;
        public native static function get ESTALE():int;
        public native static function get EDQUOT():int;

        //POSIX only
        public native static function get EMULTIHOP():int;

        //Linux only - completely optional but we want to support fully Linux
        public native static function get ECHRNG():int;
        public native static function get EL2NSYNC():int;
        public native static function get EL3HLT():int;
        public native static function get EL3RST():int;
        public native static function get ELNRNG():int;
        public native static function get EUNATCH():int;
        public native static function get ENOCSI():int;
        public native static function get EL2HLT():int;
        public native static function get EBADE():int;
        public native static function get EBADR():int;
        public native static function get EXFULL():int;
        public native static function get ENOANO():int;
        public native static function get EBADRQC():int;
        public native static function get EBADSLT():int;
        public native static function get EBFONT():int;
        public native static function get ENONET():int;
        public native static function get ENOPKG():int;
        public native static function get EADV():int;
        public native static function get ESRMNT():int;
        public native static function get ECOMM():int;
        public native static function get EDOTDOT():int;
        public native static function get ENOTUNIQ():int;
        public native static function get EBADFD():int;
        public native static function get EREMCHG():int;
        public native static function get ELIBACC():int;
        public native static function get ELIBBAD():int;
        public native static function get ELIBSCN():int;
        public native static function get ELIBMAX():int;
        public native static function get ELIBEXEC():int;
        public native static function get ERESTART():int;
        public native static function get ESTRPIPE():int;
        public native static function get EUCLEAN():int;
        public native static function get ENOTNAM():int;
        public native static function get ENAVAIL():int;
        public native static function get EISNAM():int;
        public native static function get EREMOTEIO():int;
        public native static function get ENOMEDIUM():int;
        public native static function get EMEDIUMTYPE():int;
        public native static function get ENOKEY():int;
        public native static function get EKEYEXPIRED():int;
        public native static function get EKEYREVOKED():int;
        public native static function get EKEYREJECTED():int;
        public native static function get ERFKILL():int;
        public native static function get EHWPOISON():int;

        /** 
         * @private
         * Gets the <code>errno</code> value.
         *
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public native static function _GetErrno():int;

        /** 
         * @private
         * Sets the <code>errno</code> value.
         *
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public native static function _SetErrno( value:int ):void;

    }

    /**
     * @private
     * error map so we can retrieve the const name from the const value.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [Inspectable(environment="none")]
    internal const __errmap:Object = {};

    /**
     * @private
     * error strings so we can retrieve the definition from the const value.
     *
     * We don't do it for now but it would be nice to have for OS
     * not having some errors definitions
     *
     * eg.
     * __errstr[ EPERM ] = "Operation not permitted";
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    //internal const __errstr:Object = {};

    /**
     * Operation not permitted.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EPERM:int = __errno.EPERM;
    __errmap[ EPERM ] = "EPERM";

    /**
     * No such file or directory.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENOENT:int = __errno.ENOENT;
    __errmap[ ENOENT ] = "ENOENT";

    /**
     * No such process.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ESRCH:int = __errno.ESRCH;
    __errmap[ ESRCH ] = "ESRCH";

    /**
     * Interrupted function.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EINTR:int = __errno.EINTR;
    __errmap[ EINTR ] = "EINTR";

    /**
     * I/O error.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EIO:int = __errno.EIO;
    __errmap[ EIO ] = "EIO";

    /**
     * No such device or address.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENXIO:int = __errno.ENXIO;
    __errmap[ ENXIO ] = "ENXIO";

    /**
     * Argument list too long.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const E2BIG:int = __errno.E2BIG;
    __errmap[ E2BIG ] = "E2BIG";

    /**
     * Executable file format error.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENOEXEC:int = __errno.ENOEXEC;
    __errmap[ ENOEXEC ] = "ENOEXEC";

    /**
     * Bad file descriptor.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EBADF:int = __errno.EBADF;
    __errmap[ EBADF ] = "EBADF";

    /**
     * No child processes.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ECHILD:int = __errno.ECHILD;
    __errmap[ ECHILD ] = "ECHILD";

    /**
     * Resource unavailable, try again.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EAGAIN:int = __errno.EAGAIN;
    __errmap[ EAGAIN ] = "EAGAIN";

    /**
     * Not enough space.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENOMEM:int = __errno.ENOMEM;
    __errmap[ ENOMEM ] = "ENOMEM";

    /**
     * Permission denied.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EACCES:int = __errno.EACCES;
    __errmap[ EACCES ] = "EACCES";

    /**
     * Bad address.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EFAULT:int = __errno.EFAULT;
    __errmap[ EFAULT ] = "EFAULT";

    /**
     * Block device required.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENOTBLK:int = ENOTBLK;
    __errmap[ ENOTBLK ] = "ENOTBLK";

    /**
     * Device or resource busy.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EBUSY:int = __errno.EBUSY;
    __errmap[ EBUSY ] = "EBUSY";

    /**
     * File exists.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EEXIST:int = __errno.EEXIST;
    __errmap[ EEXIST ] = "EEXIST";

    /**
     * Cross-device link.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EXDEV:int = __errno.EXDEV;
    __errmap[ EXDEV ] = "EXDEV";

    /**
     * No such device.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENODEV:int = __errno.ENODEV;
    __errmap[ ENODEV ] = "ENODEV";

    /**
     * Not a directory or a symbolic link to a directory.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENOTDIR:int = __errno.ENOTDIR;
    __errmap[ ENOTDIR ] = "ENOTDIR";

    /**
     * Is a directory.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EISDIR:int = __errno.EISDIR;
    __errmap[ EISDIR ] = "EISDIR";

    /**
     * Invalid argument.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EINVAL:int = __errno.EINVAL;
    __errmap[ EINVAL ] = "EINVAL";

    /**
     * Too many files open in system.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENFILE:int = __errno.ENFILE;
    __errmap[ ENFILE ] = "ENFILE";

    /**
     * File descriptor value too large.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EMFILE:int = __errno.EMFILE;
    __errmap[ EMFILE ] = "EMFILE";

    /**
     * Inappropriate I/O control operation.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENOTTY:int = __errno.ENOTTY;
    __errmap[ ENOTTY ] = "ENOTTY";

    /**
     * Text file busy.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ETXTBSY:int = __errno.ETXTBSY;
    __errmap[ ETXTBSY ] = "ETXTBSY";

    /**
     * File too large.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EFBIG:int = __errno.EFBIG;
    __errmap[ EFBIG ] = "EFBIG";

    /**
     * No space left on device.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENOSPC:int = __errno.ENOSPC;
    __errmap[ ENOSPC ] = "ENOSPC";

    /**
     * Invalid seek.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ESPIPE:int = __errno.ESPIPE;
    __errmap[ ESPIPE ] = "ESPIPE";

    /**
     * Read-only file system.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EROFS:int = __errno.EROFS;
    __errmap[ EROFS ] = "EROFS";

    /**
     * Too many links.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EMLINK:int = __errno.EMLINK;
    __errmap[ EMLINK ] = "EMLINK";

    /**
     * Broken pipe.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EPIPE:int = __errno.EPIPE;
    __errmap[ EPIPE ] = "EPIPE";

    /**
     * Mathematics argument out of domain of function.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EDOM:int = __errno.EDOM;
    __errmap[ EDOM ] = "EDOM";

    /**
     * Result too large.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ERANGE:int = __errno.ERANGE;
    __errmap[ ERANGE ] = "ERANGE";



    /**
     * Resource deadlock would occur.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EDEADLK:int = __errno.EDEADLK;
    __errmap[ EDEADLK ] = "EDEADLK";

    /**
     * File name too long.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENAMETOOLONG:int = __errno.ENAMETOOLONG;
    __errmap[ ENAMETOOLONG ] = "ENAMETOOLONG";

    /**
     * No record locks available.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENOLCK:int = __errno.ENOLCK;
    __errmap[ ENOLCK ] = "ENOLCK";

    /**
     * Function not implemented.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENOSYS:int = __errno.ENOSYS;
    __errmap[ ENOSYS ] = "ENOSYS";

    /**
     * Directory not empty.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENOTEMPTY:int = __errno.ENOTEMPTY;
    __errmap[ ENOTEMPTY ] = "ENOTEMPTY";

    /**
     * Too many symbolic links encountered.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ELOOP:int = __errno.ELOOP;
    __errmap[ ELOOP ] = "ELOOP";

    /**
     * Operation would block.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EWOULDBLOCK:int = __errno.EWOULDBLOCK;
    __errmap[ EWOULDBLOCK ] = "EWOULDBLOCK";

    /**
     * No message of desired type.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENOMSG:int = __errno.ENOMSG;
    __errmap[ ENOMSG ] = "ENOMSG";

    /**
     * Identifier removed.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EIDRM:int = __errno.EIDRM;
    __errmap[ EIDRM ] = "EIDRM";

    /**
     * Resource deadlock would occur.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EDEADLOCK:int = __errno.EDEADLOCK;
    __errmap[ EDEADLOCK ] = "EDEADLOCK";

    /**
     * Device not a stream.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENOSTR:int = __errno.ENOSTR;
    __errmap[ ENOSTR ] = "ENOSTR";

    /**
     * No data available.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENODATA:int = __errno.ENODATA;
    __errmap[ ENODATA ] = "ENODATA";

    /**
     * Timer expired.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ETIME:int = __errno.ETIME;
    __errmap[ ETIME ] = "ETIME";

    /**
     * Out of streams resources.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENOSR:int = __errno.ENOSR;
    __errmap[ ENOSR ] = "ENOSR";

    /**
     * Link has been severed.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENOLINK:int = __errno.ENOLINK;
    __errmap[ ENOLINK ] = "ENOLINK";

    /**
     * Not a data message.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EBADMSG:int = __errno.EBADMSG;
    __errmap[ EBADMSG ] = "EBADMSG";

    /**
     * Value too large for defined data type.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EOVERFLOW:int = __errno.EOVERFLOW;
    __errmap[ EOVERFLOW ] = "EOVERFLOW";

    /**
     * Illegal byte sequence.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EILSEQ:int = __errno.EILSEQ;
    __errmap[ EILSEQ ] = "EILSEQ";

    /**
     * Socket operation on non-socket.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENOTSOCK:int = __errno.ENOTSOCK;
    __errmap[ ENOTSOCK ] = "ENOTSOCK";

    /**
     * Destination address required.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EDESTADDRREQ:int = __errno.EDESTADDRREQ;
    __errmap[ EDESTADDRREQ ] = "EDESTADDRREQ";

    /**
     * Message too long.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EMSGSIZE:int = __errno.EMSGSIZE;
    __errmap[ EMSGSIZE ] = "EMSGSIZE";

    /**
     * Protocol error.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EPROTO:int = __errno.EPROTO;
    __errmap[ EPROTO ] = "EPROTO";

    /**
     * Protocol wrong type for socket.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EPROTOTYPE:int = __errno.EPROTOTYPE;
    __errmap[ EPROTOTYPE ] = "EPROTOTYPE";

    /**
     * Protocol not available.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENOPROTOOPT:int = __errno.ENOPROTOOPT;
    __errmap[ ENOPROTOOPT ] = "ENOPROTOOPT";

    /**
     * Protocol not supported.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EPROTONOSUPPORT:int = __errno.EPROTONOSUPPORT;
    __errmap[ EPROTONOSUPPORT ] = "EPROTONOSUPPORT";

    /**
     * Operation not supported on transport endpoint.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EOPNOTSUPP:int = __errno.EOPNOTSUPP;
    __errmap[ EOPNOTSUPP ] = "EOPNOTSUPP";

    /**
     * Address family not supported by protocol.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EAFNOSUPPORT:int = __errno.EAFNOSUPPORT;
    __errmap[ EAFNOSUPPORT ] = "EAFNOSUPPORT";

    /**
     * Address already in use.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EADDRINUSE:int = __errno.EADDRINUSE;
    __errmap[ EADDRINUSE ] = "EADDRINUSE";

    /**
     * Cannot assign requested address.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EADDRNOTAVAIL:int = __errno.EADDRNOTAVAIL;
    __errmap[ EADDRNOTAVAIL ] = "EADDRNOTAVAIL";

    /**
     * Network is down.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENETDOWN:int = __errno.ENETDOWN;
    __errmap[ ENETDOWN ] = "ENETDOWN";

    /**
     * Network is unreachable.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENETUNREACH:int = __errno.ENETUNREACH;
    __errmap[ ENETUNREACH ] = "ENETUNREACH";

    /**
     * Network dropped connection because of reset.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENETRESET:int = __errno.ENETRESET;
    __errmap[ ENETRESET ] = "ENETRESET";

    /**
     * Software caused connection abort.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ECONNABORTED:int = __errno.ECONNABORTED;
    __errmap[ ECONNABORTED ] = "ECONNABORTED";

    /**
     * Connection reset by peer.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ECONNRESET:int = __errno.ECONNRESET;
    __errmap[ ECONNRESET ] = "ECONNRESET";

    /**
     * No buffer space available.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENOBUFS:int = __errno.ENOBUFS;
    __errmap[ ENOBUFS ] = "ENOBUFS";

    /**
     * Transport endpoint is already connected.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EISCONN:int = __errno.EISCONN;
    __errmap[ EISCONN ] = "EISCONN";

    /**
     * Transport endpoint is not connected.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENOTCONN:int = __errno.ENOTCONN;
    __errmap[ ENOTCONN ] = "ENOTCONN";

    /**
     * Connection timed out.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ETIMEDOUT:int = __errno.ETIMEDOUT;
    __errmap[ ETIMEDOUT ] = "ETIMEDOUT";

    /**
     * Connection refused.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ECONNREFUSED:int = __errno.ECONNREFUSED;
    __errmap[ ECONNREFUSED ] = "ECONNREFUSED";

    /**
     * No route to host.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EHOSTUNREACH:int = __errno.EHOSTUNREACH;
    __errmap[ EHOSTUNREACH ] = "EHOSTUNREACH";

    /**
     * Operation already in progress.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EALREADY:int = __errno.EALREADY;
    __errmap[ EALREADY ] = "EALREADY";

    /**
     * Operation now in progress.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EINPROGRESS:int = __errno.EINPROGRESS;
    __errmap[ EINPROGRESS ] = "EINPROGRESS";

    /**
     * Operation Canceled.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ECANCELED:int = __errno.ECANCELED;
    __errmap[ ECANCELED ] = "ECANCELED";

    /**
     * Owner died.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EOWNERDEAD:int = __errno.EOWNERDEAD;
    __errmap[ EOWNERDEAD ] = "EOWNERDEAD";

    /**
     * State not recoverable.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENOTRECOVERABLE:int = __errno.ENOTRECOVERABLE;
    __errmap[ ENOTRECOVERABLE ] = "ENOTRECOVERABLE";

    /**
     * Remote I/O error.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EREMOTE:int = __errno.EREMOTE;
    __errmap[ EREMOTE ] = "EREMOTE";

    /**
     * Too many users.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EUSERS:int = __errno.EUSERS;
    __errmap[ EUSERS ] = "EUSERS";

    /**
     * Socket type not supported.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ESOCKTNOSUPPORT:int = __errno.ESOCKTNOSUPPORT;
    __errmap[ ESOCKTNOSUPPORT ] = "ESOCKTNOSUPPORT";

    /**
     * Protocol family not supported.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EPFNOSUPPORT:int = __errno.EPFNOSUPPORT;
    __errmap[ EPFNOSUPPORT ] = "EPFNOSUPPORT";

    /**
     * Cannot send after transport endpoint shutdown.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ESHUTDOWN:int = __errno.ESHUTDOWN;
    __errmap[ ESHUTDOWN ] = "ESHUTDOWN";

    /**
     * Too many references: cannot splice.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ETOOMANYREFS:int = __errno.ETOOMANYREFS;
    __errmap[ ETOOMANYREFS ] = "ETOOMANYREFS";

    /**
     * Host is down.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EHOSTDOWN:int = __errno.EHOSTDOWN;
    __errmap[ EHOSTDOWN ] = "EHOSTDOWN";

    /**
     * Stale NFS file handle.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ESTALE:int = __errno.ESTALE;
    __errmap[ ESTALE ] = "ESTALE";

    /**
     * Quota exceeded.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EDQUOT:int = __errno.EDQUOT;
    __errmap[ EDQUOT ] = "EDQUOT";




    /**
     * Multihop attempted.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion POSIX +
     */
    public const EMULTIHOP:int = __errno.EMULTIHOP;
    __errmap[ EMULTIHOP ] = "EMULTIHOP";





    /**
     * Channel number out of range.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const ECHRNG:int = __errno.ECHRNG;
    __errmap[ ECHRNG ] = "ECHRNG";

    /**
     * Level 2 not synchronized.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const EL2NSYNC:int = __errno.EL2NSYNC;
    __errmap[ EL2NSYNC ] = "EL2NSYNC";

    /**
     * Level 3 halted.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const EL3HLT:int = __errno.EL3HLT;
    __errmap[ EL3HLT ] = "EL3HLT";

    /**
     * Level 3 reset.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const EL3RST:int = __errno.EL3RST;
    __errmap[ EL3RST ] = "EL3RST";

    /**
     * Link number out of range.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const ELNRNG:int = __errno.ELNRNG;
    __errmap[ ELNRNG ] = "ELNRNG";

    /**
     * Protocol driver not attached.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const EUNATCH:int = __errno.EUNATCH;
    __errmap[ EUNATCH ] = "EUNATCH";

    /**
     * No CSI structure available.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const ENOCSI:int = __errno.ENOCSI;
    __errmap[ ENOCSI ] = "ENOCSI";

    /**
     * Level 2 halted.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const EL2HLT:int = __errno.EL2HLT;
    __errmap[ EL2HLT ] = "EL2HLT";

    /**
     * Invalid exchange.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const EBADE:int = __errno.EBADE;
    __errmap[ EBADE ] = "EBADE";

    /**
     * Invalid request descriptor.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const EBADR:int = __errno.EBADR;
    __errmap[ EBADR ] = "EBADR";

    /**
     * Exchange full.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const EXFULL:int = __errno.EXFULL;
    __errmap[ EXFULL ] = "EXFULL";

    /**
     * No anode.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const ENOANO:int = __errno.ENOANO;
    __errmap[ ENOANO ] = "ENOANO";

    /**
     * Invalid request code.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const EBADRQC:int = __errno.EBADRQC;
    __errmap[ EBADRQC ] = "EBADRQC";

    /**
     * Invalid slot.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const EBADSLT:int = __errno.EBADSLT;
    __errmap[ EBADSLT ] = "EBADSLT";

    /**
     * Bad font file format.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const EBFONT:int = __errno.EBFONT;
    __errmap[ EBFONT ] = "EBFONT";

    /**
     * Machine is not on the network.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const ENONET:int = __errno.ENONET;
    __errmap[ ENONET ] = "ENONET";

    /**
     * Package not installed.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const ENOPKG:int = __errno.ENOPKG;
    __errmap[ ENOPKG ] = "ENOPKG";

    /**
     * Advertise error.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const EADV:int = __errno.EADV;
    __errmap[ EADV ] = "EADV";

    /**
     * Srmount error.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const ESRMNT:int = __errno.ESRMNT;
    __errmap[ ESRMNT ] = "ESRMNT";

    /**
     * Communication error on send.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const ECOMM:int = __errno.ECOMM;
    __errmap[ ECOMM ] = "ECOMM";

    /**
     * RFS specific error.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const EDOTDOT:int = __errno.EDOTDOT;
    __errmap[ EDOTDOT ] = "EDOTDOT";

    /**
     * Name not unique on network.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const ENOTUNIQ:int = __errno.ENOTUNIQ;
    __errmap[ ENOTUNIQ ] = "ENOTUNIQ";

    /**
     * File descriptor in bad state.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const EBADFD:int = __errno.EBADFD;
    __errmap[ EBADFD ] = "EBADFD";

    /**
     * Remote address changed.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const EREMCHG:int = __errno.EREMCHG;
    __errmap[ EREMCHG ] = "EREMCHG";

    /**
     * Can not access a needed shared library.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const ELIBACC:int = __errno.ELIBACC;
    __errmap[ ELIBACC ] = "ELIBACC";

    /**
     * Accessing a corrupted shared library.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const ELIBBAD:int = __errno.ELIBBAD;
    __errmap[ ELIBBAD ] = "ELIBBAD";

    /**
     * .lib section in a.out corrupted.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const ELIBSCN:int = __errno.ELIBSCN;
    __errmap[ ELIBSCN ] = "ELIBSCN";

    /**
     * Attempting to link in too many shared libraries.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const ELIBMAX:int = __errno.ELIBMAX;
    __errmap[ ELIBMAX ] = "ELIBMAX";

    /**
     * Cannot exec a shared library directly.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const ELIBEXEC:int = __errno.ELIBEXEC;
    __errmap[ ELIBEXEC ] = "ELIBEXEC";

    /**
     * Interrupted system call should be restarted.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const ERESTART:int = __errno.ERESTART;
    __errmap[ ERESTART ] = "ERESTART";

    /**
     * Streams pipe error.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const ESTRPIPE:int = __errno.ESTRPIPE;
    __errmap[ ESTRPIPE ] = "ESTRPIPE";

    /**
     * Structure needs cleaning.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const EUCLEAN:int = __errno.EUCLEAN;
    __errmap[ EUCLEAN ] = "EUCLEAN";

    /**
     * Not a XENIX named type file.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const ENOTNAM:int = __errno.ENOTNAM;
    __errmap[ ENOTNAM ] = "ENOTNAM";

    /**
     * No XENIX semaphores available.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const ENAVAIL:int = __errno.ENAVAIL;
    __errmap[ ENAVAIL ] = "ENAVAIL";

    /**
     * Is a named type file.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const EISNAM:int = __errno.EISNAM;
    __errmap[ EISNAM ] = "EISNAM";

    /**
     * Remote I/O error.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const EREMOTEIO:int = __errno.EREMOTEIO;
    __errmap[ EREMOTEIO ] = "EREMOTEIO";

    /**
     * No medium found.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const ENOMEDIUM:int = __errno.ENOMEDIUM;
    __errmap[ ENOMEDIUM ] = "ENOMEDIUM";

    /**
     * Wrong medium type.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const EMEDIUMTYPE:int = __errno.EMEDIUMTYPE;
    __errmap[ EMEDIUMTYPE ] = "EMEDIUMTYPE";

    /**
     * Required key not available.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const ENOKEY:int = __errno.ENOKEY;
    __errmap[ ENOKEY ] = "ENOKEY";

    /**
     * Key has expired.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const EKEYEXPIRED:int = __errno.EKEYEXPIRED;
    __errmap[ EKEYEXPIRED ] = "EKEYEXPIRED";


    /**
     * Key has been revoked.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const EKEYREVOKED:int = __errno.EKEYREVOKED;
    __errmap[ EKEYREVOKED ] = "EKEYREVOKED";

    /**
     * Key was rejected by service.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const EKEYREJECTED:int = __errno.EKEYREJECTED;
    __errmap[ EKEYREJECTED ] = "EKEYREJECTED";

    /**
     * Operation not possible due to RF-kill.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const ERFKILL:int = __errno.ERFKILL;
    __errmap[ ERFKILL ] = "ERFKILL";

    /**
     * Memory page has hardware error.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * @playerversion NIX +
     */
    public const EHWPOISON:int = __errno.EHWPOISON;
    __errmap[ EHWPOISON ] = "EHWPOISON";


    /**
     * Last error number.
     *
     * <p>
     * TODO
     * </p>
     * 
     * <p>
     * A value is stored in <b>errno</b> by certain library functions when they detect errors.
     * </p>
     *
     * <p>
     * At program startup, the value stored is zero. Library functions store only values greater than zero.
     * Any library function can alter the value stored before return, whether or not they detect errors.
     * </p>
     *
     * <p>
     * Most functions indicate that they detected an error by returning a special value,
     * typically <code>NULL</code> for functions that return pointers, and <code>-1</code> for functions that return integers.
     * A few functions require the caller to preset errno to zero and test it afterwards to see if an error was detected.
     * </p>
     *
     * @example basic usage
     * <listing version="3.0">
     *  import C.errno.&#42;;
     *  import C.string.&#42;;
     *  import avmplus.FileSystem;
     *  
     *  var filename:String = "dummy_file";
     *  
     *  if( !FileSystem.exists( filename ) )
     *  {
     *      trace( "errno = " + int(errno) + " - " + errno ); //errno = 2 - No such file or directory
     *  }
     * </listing>
     *
     * @example ActionScript Error usage
     * <listing version="3.0">
     *  import C.errno.&#42;;
     *  import C.string.&#42;;
     *  import avmplus.FileSystem;
     *  
     *  var filename:String = "dummy_file";
     *  
     *  if( !FileSystem.exists( filename ) )
     *  {
     *      var e:CError = new CError( "", errno );
     *      trace( e ); //ENOENT: No such file or directory
     *  }
     * </listing>
     *
     * 
     * @example read errno
     * <listing version="3.0">
     *  import C.errno.&#42;;
     *  
     *  //let's assume that errno = 2;
     *  
     *  trace( errno ); //wil use the toString() method, output: No such file or directory
     *  
     *  trace( errno.value ); //return the value of errno as a int, output: 2
     *  
     *  trace( int(errno) ); //will cast the valueOf() to int, output: 2
     *  
     *  trace( errno.valueOf() ); //will return the valueOf(), output: 2
     *  
     *  trace( errno.toString() ); //will return the toString(), output: No such file or directory
     * </listing>
     * 
     * @example write errno
     * <listing version="3.0">
     *  import C.errno.&#42;;
     *  
     *  errno.value = 0; //reset errno
     *  
     * </listing>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see ErrorNumber
     */
    public const errno:ErrorNumber = new ErrorNumber();

    /**
     * Error Number value.
     *
     * <p>
     * TODO
     * </p>
     * 
     * <p>
     * Designates an object that is assigned a value greater than zero on certain library errors.
     * </p>
     * 
     * <p>
     * The Error Number value is a modifiable value that can be both read and modified by a program.
     * </p>
     *
     * <p>
     * <b>errno</b> is set to zero at program startup, and any function of the standard C library can modify
     * its value to some value different from zero, generally to signal specific categories of error
     * (no library function sets its value back to zero once changed).
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see C.errno#errno
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/V2_chap02.html#tag_15_03 POSIX Error Numbers
     */
    public class ErrorNumber
    {
        private var _value:uint;

        /**
         * [ErrorNumber description]
         *
         * <p>
         * TODO
         * </p>
         * 
         */
        public function ErrorNumber()
        {

        }

        /**
         * [value description]
         * @return [description]
         *
         * <p>
         * TODO
         * </p>
         * 
         */
        public function get value():int
        {
            _value = __errno._GetErrno();
            return _value;
        }

        /**
         * @private
         */
        public function set value( num:int ):void
        {
            _value = num;
            __errno._SetErrno( _value );
        }

        /**
         * [valueOf description]
         * @return [description]
         *
         * <p>
         * TODO
         * </p>
         * 
         */
        public function valueOf():int { return this.value; }

        /**
         * [toString description]
         * @return [description]
         *
         * <p>
         * TODO
         * </p>
         * 
         */
        public function toString():String { return strerror( this.value ); }

        /**
         * [toErrnoString description]
         * @return [description]
         *
         * <p>
         * TODO
         * </p>
         * 
         */
        public function toErrnoString():String
        {
            if( __errmap[ valueOf() ] )
            {
                return __errmap[ valueOf() ];
            }

            return String( valueOf() );
        }

    }

    /**
     * The CError exception allow to throws an <b>errno</b> as an Error object.
     *
     * <p>
     * TODO
     * </p>
     * 
     * @example basic usage
     * <code>
     * import C.errno.errno;
     * import C.errno.CError;
     * import C.stdio.rename;
     * 
     * var result:int = rename( "hello.txt", "world.txt" );
     * if( errno > 0 )
     * {
     *     throw new CError( "", errno );
     * }
     * </code>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native(cls="::avmshell::CErrorClass", instance="::avmshell::CErrorObject", methods="auto")]
    public dynamic class CError extends Error
    {
        
        // E262 {ReadOnly, DontDelete, DontEnum }
        public static const length:int = 1;

        private var _errorID:int;
        prototype.name = "CError";
        
        /**
         * [CError description]
         * @param message [description]
         * @param id      [description]
         *
         * <p>
         * TODO
         * </p>
         * 
         */
        public function CError( message = "", id = 0 )
        {
             super(message, id);
            this.name = prototype.name;

            this.apply( id );
        }

        /**
         * [errorID description]
         * @return [description]
         *
         * <p>
         * TODO
         * </p>
         * 
         */
        public override function get errorID():int
        {
            return this._errorID;
        }


        /**
         * [apply description]
         * @param  id [description]
         * @return    [description]
         *
         * <p>
         * TODO
         * </p>
         * 
         */
        [cppcall]
        public function apply( id:int = 0 ):void
        {
            this.message  = strerror( id );
            this._errorID = id;

            if( __errmap[ id ] )
            {
                this.name = __errmap[ id ];
            }
            else
            {
                this.name = prototype.name;
            }
        }

        //ArgumentError: Error #1507: Argument filename cannot be null.
        //CError: EOVERFLOW #84: Value too large to be stored in data type
        //CError #666
        /**
         * [toString description]
         * @return [description]
         *
         * <p>
         * TODO
         * </p>
         * 
         */
        public function toString():String
        {
            var e:Error = this;
            if( e.message !== "" )
            {
                return "CError: " + e.name + " #" + e.errorID + ": " + e.message
            }

            return e.name + " #" + e.id;
        }
    }
    
}
