/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package C.errno
{
    import C.string.*;

    /** @internal */
    /*[native(cls="::avmshell::CErrnoClass", methods="auto", construct="none")]
    [Inspectable(environment="none")]
    internal class __errno
    {
        public native static function dummy():void;
    }*/

    /**
     * @private
     * error map so we can retrieve the const name from the const value.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [Inspectable(environment="none")]
    internal const errmap:Object = {};

    /**
     * Operation not permitted.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EPERM:int = 1;
    errmap[ EPERM ] = "EPERM";

    /**
     * No such file or directory.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENOENT:int = 2;
    errmap[ ENOENT ] = "ENOENT";

    /**
     * No such process.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ESRCH:int = 3;
    errmap[ ESRCH ] = "ESRCH";

    /**
     * Interrupted function.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EINTR:int = 4;
    errmap[ EINTR ] = "EINTR";

    /**
     * I/O error.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EIO:int = 5;
    errmap[ EIO ] = "EIO";

    /**
     * No such device or address.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENXIO:int = 6;
    errmap[ ENXIO ] = "ENXIO";

    /**
     * Argument list too long.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const E2BIG:int = 7;
    errmap[ E2BIG ] = "E2BIG";

    /**
     * Executable file format error.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENOEXEC:int = 8;
    errmap[ ENOEXEC ] = "ENOEXEC";

    /**
     * Bad file descriptor.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EBADF:int = 9;
    errmap[ EBADF ] = "EBADF";

    /**
     * No child processes.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ECHILD:int = 10;
    errmap[ ECHILD ] = "ECHILD";

    /**
     * Resource unavailable, try again.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EAGAIN:int = 11;
    errmap[ EAGAIN ] = "EAGAIN";

    /**
     * Not enough space.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENOMEM:int = 12;
    errmap[ ENOMEM ] = "ENOMEM";

    /**
     * Permission denied.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EACCES:int = 13;
    errmap[ EACCES ] = "EACCES";

    /**
     * Bad address.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EFAULT:int = 14;
    errmap[ EFAULT ] = "EFAULT";

    /**
     * Block device required.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENOTBLK:int = 15;
    errmap[ ENOTBLK ] = "ENOTBLK";

    /**
     * Device or resource busy.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EBUSY:int = 16;
    errmap[ EBUSY ] = "EBUSY";

    /**
     * File exists.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EEXIST:int = 17;
    errmap[ EEXIST ] = "EEXIST";

    /**
     * Cross-device link.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EXDEV:int = 18;
    errmap[ EXDEV ] = "EXDEV";

    /**
     * No such device.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENODEV:int = 19;
    errmap[ ENODEV ] = "ENODEV";

    /**
     * Not a directory or a symbolic link to a directory.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENOTDIR:int = 20;
    errmap[ ENOTDIR ] = "ENOTDIR";

    /**
     * Is a directory.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EISDIR:int = 21;
    errmap[ EISDIR ] = "EISDIR";

    /**
     * Invalid argument.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EINVAL:int = 22;
    errmap[ EINVAL ] = "EINVAL";

    /**
     * Too many files open in system.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENFILE:int = 23;
    errmap[ ENFILE ] = "ENFILE";

    /**
     * File descriptor value too large.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EMFILE:int = 24;
    errmap[ EMFILE ] = "EMFILE";

    /**
     * Inappropriate I/O control operation.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENOTTY:int = 25;
    errmap[ ENOTTY ] = "ENOTTY";

    /**
     * Text file busy.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ETXTBSY:int = 26;
    errmap[ ETXTBSY ] = "ETXTBSY";

    /**
     * File too large.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EFBIG:int = 27;
    errmap[ EFBIG ] = "EFBIG";

    /**
     * No space left on device.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ENOSPC:int = 28;
    errmap[ ENOSPC ] = "ENOSPC";

    /**
     * Invalid seek.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ESPIPE:int = 29;
    errmap[ ESPIPE ] = "ESPIPE";

    /**
     * Read-only file system.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EROFS:int = 30;
    errmap[ EROFS ] = "EROFS";

    /**
     * Too many links.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EMLINK:int = 31;
    errmap[ EMLINK ] = "EMLINK";

    /**
     * Broken pipe.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EPIPE:int = 32;
    errmap[ EPIPE ] = "EPIPE";

    /**
     * Mathematics argument out of domain of function.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const EDOM:int = 33;
    errmap[ EDOM ] = "EDOM";

    /**
     * Result too large.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const ERANGE:int = 34;
    errmap[ ERANGE ] = "ERANGE";

    /**
     * @private
     * description.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    //public const AAA:int = 0;
    //errmap[ AAA ] = "AAA";


    /** 
     * @private
     * Gets the <code>errno</code> value.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CErrnoClass::_GetErrno")]
    [Inspectable(environment="none")]
    internal native function _GetErrno():int;

    /** 
     * @private
     * Sets the <code>errno</code> value.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CErrnoClass::_SetErrno")]
    [Inspectable(environment="none")]
    internal native function _SetErrno( value:int ):void;

    /**
     * Last error number.
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
     *      var e:CError = new CError( errno );
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
     */
    public class ErrorNumber
    {
        private var _value:uint;

        public function ErrorNumber()
        {

        }

        public function get value():int
        {
            _value = _GetErrno();
            return _value;
        }

        public function set value( num:int ):void
        {
            _value = num;
            _SetErrno( _value );
        }

        public function valueOf():int { return this.value; }

        public function toString():String { return strerror( this.value ); }

    }

    /**
     * The CError exception allow to throws an <b>errno</b> as an Error object.
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
     *     throw new CError( errno );
     * }
     * </code>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public dynamic class CError extends Error
    {
        prototype.name = "CError";
        
        public function CError( id:int = 0 )
        {
            super( strerror( id ), id );

            if( errmap[ id ] )
            {
                this.name = errmap[ id ];
            }
            else
            {
                this.name = prototype.name;
            }
        }
    }


    /* note:
       By default, something somewhere in tamarin define errno=2
       eg. "No such file or directory"
    
       for our API we want errno set as 0 (zero) from the start of the application
       forcing errno=0 here allow to do this
    */
    //set errno to zero
    //errno.value = 0;
    
}
