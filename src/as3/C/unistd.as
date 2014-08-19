/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package C.unistd
{
    
    /** @internal */
    [native(cls="::avmshell::CUnistdClass", methods="auto", construct="none")]
    [Inspectable(environment="none")]
    internal class __unistd
    {
        public native static function get F_OK():int;
        public native static function get X_OK():int;
        public native static function get W_OK():int;
        public native static function get R_OK():int;

        public native static function getcwd():String;
        public native static function gethostname():String;
        public native static function getlogin():String;
        public native static function getpid():int;
        public native static function rmdir( path:String ):int;
        public native static function sleep( milliseconds:uint ):void;
        public native static function unlink( path:String ):int;
    }

    /**
     * Test for existence of file.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const F_OK:int = __unistd.F_OK;

    /**
     * Test for execute (search) permission.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const X_OK:int = __unistd.X_OK;

    /**
     * Test for write permission.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const W_OK:int = __unistd.W_OK;

    /**
     * Test for read permission.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const R_OK:int = __unistd.R_OK;


    /**
     * File number of <code>stdin</code>; <code>0</code>.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const STDIN_FILENO:int = 0;

    /**
     * File number of <code>stdout</code>; <code>1</code>.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const STDOUT_FILENO:int = 1;

    /**
     * File number of <code>stderr</code>; <code>2</code>.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const STDERR_FILENO:int = 2;






    /**
     * Determine accessibility of a file relative to directory file descriptor.
     * 
     * <p>
     * The <code>access()</code> function shall check the file named by the pathname pointed
     * to by the <code>path</code> argument for accessibility according to the bit pattern
     * contained in <code>mode</code>, using the real user ID in place of the effective user ID
     * and the real group ID in place of the effective group ID.
     * </p>
     * 
     * <p>
     * The value of <code>mode</code> is either the bitwise-inclusive <code>OR</code> of the
     * access permissions to be checked (<code>R_OK</code>, <code>W_OK</code>, <code>X_OK</code>)
     * or the existence test (<code>F_OK</code>).
     * </p>
     *
     * <p>
     * If any access permissions are checked, each shall be checked individually,
     * as described in XBD <a href="http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap04.html#tag_04_04">File Access Permissions</a>,
     * except that where that description refers to execute permission for a process
     * with appropriate privileges, an implementation may indicate success for <code>X_OK</code>
     * even if execute permission is not granted to any user.
     * </p>
     * 
     * @example Usage
     * <listing>
     * import C.errno.&#42;;
     * import C.unistd.&#42;;
     * 
     * var pathname:String = "/tmp/myfile";
     * 
     * // tests whether a file named myfile exists in the /tmp directory
     * var result:int = access( pathname, F_OK );
     * 
     * if( result == 0 )
     * {
     *     trace( "file exists" );
     * }
     * else
     * {
     *     trace( "file does not exists" );
     *     trace( errno );
     * }
     * 
     * </listing>
     * 
     * @param path The pathname to check.
     * @param mode the bit pattern access permissions.
     * @return Upon successful completion, these functions shall return <code>0</code>.
     * Otherwise, these functions shall return <code>-1</code> and set <code>errno</code> to indicate the error.
     * 
     * @throws C.errno.CError <b>EACCES</b> Permission bits of the file mode do not permit the requested access, or search permission is denied on a component of the path prefix.
     * @throws C.errno.CError <b>ELOOP</b> A loop exists in symbolic links encountered during resolution of the path argument.
     * @throws C.errno.CError <b>ENAMETOOLONG</b> The length of a component of a pathname is longer than <code>{NAME_MAX}</code>.
     * @throws C.errno.CError <b>ENOENT</b> A component of <code>path</code> does not name an existing file or <code>path</code> is an empty string.
     * @throws C.errno.CError <b>ENOTDIR</b> A component of the <code>path</code> prefix names an existing file that is neither a directory nor a symbolic link to a directory, or the <code>path</code> argument contains at least one non-&lt;slash&gt; character and ends with one or more trailing &lt;slash&gt; characters and the last pathname component names an existing file that is neither a directory nor a symbolic link to a directory.
     * @throws C.errno.CError <b>EROFS</b> Write access is requested for a file on a read-only file system.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     * 
     * @see C.errno#EACCES
     * @see C.errno#ELOOP
     * @see C.errno#ENAMETOOLONG
     * @see C.errno#ENOENT
     * @see C.errno#ENOTDIR
     * @see C.errno#EROFS
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/access.html
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap04.html#tag_04_04 File Access Permissions
     */
    [native("::avmshell::CUnistdClass::access")]
    public native function access( path:String, mode:int ):int;

    /**
     * Change working directory.
     *
     * <p>
     * The <code>chdir()</code> function shall cause the directory named by the pathname
     * pointed to by the <code>path</code> argument to become the current working directory;
     * that is, the starting point for path searches for pathnames not beginning with '/'.
     * </p>
     *
     * @example Usage
     * <listing>
     * import C.errno.&#42;;
     * import C.unistd.&#42;;
     * 
     * var directory:String = "/tmp";
     * 
     * // makes the value pointed to by directory, the current working directory
     * var result:int = chdir( directory );
     * 
     * if( result == 0 )
     * {
     *     trace( "successfully changed directory" );
     * }
     * else
     * {
     *     trace( "could not change directory" );
     *     trace( errno );
     * }
     * 
     * </listing>
     *
     * @param path The pathname to change directory to.
     * @return Upon successful completion, <code>0</code> shall be returned.
     * Otherwise, <code>-1</code> shall be returned, the current working directory
     * shall remain unchanged, and <code>errno</code> shall be set to indicate the error.
     * 
     * @throws C.errno.CError <b>EACCES</b> Search permission is denied for any component of the pathname.
     * @throws C.errno.CError <b>ELOOP</b> A loop exists in symbolic links encountered during resolution of the <code>path</code> argument.
     * @throws C.errno.CError <b>ENAMETOOLONG</b> The length of a component of a pathname is longer than <code>{NAME_MAX}</code>.
     * @throws C.errno.CError <b>ENOENT</b> A component of <code>path</code> does not name an existing directory or <code>path</code> is an empty string.
     * @throws C.errno.CError <b>ENOTDIR</b> A component of the pathname names an existing file that is neither a directory nor a symbolic link to a directory.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see C.errno#EACCES
     * @see C.errno#ELOOP
     * @see C.errno#ENAMETOOLONG
     * @see C.errno#ENOENT
     * @see C.errno#ENOTDIR
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/chdir.html
     */
    [native("::avmshell::CUnistdClass::chdir")]
    public native function chdir( path:String ):int;
    
    /**
     * Close a file descriptor.
     *
     * <p>
     * The <code>close()</code> function shall deallocate the file descriptor indicated
     * by <code>fildes</code>. To deallocate means to make the file descriptor available
     * for return by subsequent calls to <code>open()</code> or other functions that allocate
     * file descriptors. All outstanding record locks owned by the process on the file
     * associated with the file descriptor shall be removed (that is, unlocked).
     * </p>
     *
     * <p>
     * If <code>close()</code> is interrupted by a signal that is to be caught,
     * it shall return <code>-1</code> with <code>errno</code> set to <code>EINTR</code>
     * and the state of <code>fildes</code> is unspecified.
     * If an I/O error occurred while reading from or writing to the file system during
     * <code>close()</code>, it may return <code>-1</code> with <code>errno</code> set to
     * <code>EIO</code>; if this error is returned, the state of <code>fildes</code> is unspecified.
     * </p>
     *
     * <p>
     * When all file descriptors associated with a pipe or FIFO special file are closed,
     * any data remaining in the pipe or FIFO shall be discarded.
     * </p>
     *
     * <p>
     * When all file descriptors associated with an open file description have been closed,
     * the open file description shall be freed.
     * </p>
     *
     * <p>
     * If the link count of the file is <code>0</code>, when all file descriptors associated
     * with the file are closed, the space occupied by the file shall be freed
     * and the file shall no longer be accessible.
     * </p>
     *
     * @example Usage
     * <listing>
     * import C.errno.&#42;;
     * import C.stdlib.&#42;;
     * import C.stdio.&#42;;
     * import C.unistd.&#42;;
     * 
     * const LOCKFILE:String = "/etc/ptmp";
     *
     * // obtain a file descriptor
     * var pfd:int = open( LOCKFILE, O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH );
     * 
     * // attempt to associate that file descriptor with a stream
     * var fpfd:FILE = fdopen( pfd, "w" );
     * 
     * if( fpfd == null )
     * {
     *     // close a file descriptor after the unsuccessful attempt
     *     close( pfd );
     *     
     *     // delete the file
     *     unlink( LOCKFILE );
     *     
     *     exit( 1 );
     * }
     * 
     * </listing>
     * 
     * @param fildes The file descriptor.
     * @return Upon successful completion, <code>0</code> shall be returned;
     * otherwise, <code>-1</code> shall be returned and <code>errno</code> set to indicate the error.
     * 
     * @throws C.errno.CError <b>EBADF</b> The <code>fildes</code> argument is not a open file descriptor.
     * @throws C.errno.CError <b>EINTR</b> The <code>close()</code> function was interrupted by a signal.
     * @throws C.errno.CError <b>EIO</b> An I/O error occurred while reading from or writing to the file system.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see C.errno#EBADF
     * @see C.errno#EINTR
     * @see C.errno#EIO
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/close.html
     */
    [native("::avmshell::CUnistdClass::close")]
    public native function close( fildes:int ):int;

    /**
     * Duplicate an open file descriptor.
     *
     * <p>
     * The <code>dup()</code> function provides an alternative interface to the service
     * provided by <code>fcntl()</code> using the <code>F_DUPFD</code> command.
     * </p>
     *
     * <p>
     * The call <code>dup(fildes)</code> shall be equivalent to:
     * <pre>
     * fcntl( fildes, F_DUPFD, 0 );
     * </pre>
     * </p>
     *
     * @example Usage
     * <listing>
     * import C.errno.&#42;;
     * import C.unistd.&#42;;
     *
     * // re-assign standard output to go to the file referencec by outcopy
     * var outcopy:int = dup( STDOUT_FILENO );
     * 
     * </listing>
     * 
     * @param fildes The file descriptor to duplicate.
     * @return Upon successful completion a non-negative integer, namely the file descriptor,
     * shall be returned; otherwise, <code>-1</code> shall be returned and <code>errno</code> set to indicate the error.
     *
     * @throws C.errno.CError <b>EBADF</b> The <code>fildes</code> argument is not a valid open file descriptor.
     * @throws C.errno.CError <b>EMFILE</b> All file descriptors available to the process are currently open.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see C.errno#EBADF
     * @see C.errno#EMFILE
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/dup.html
     */
    [native("::avmshell::CUnistdClass::dup")]
    public native function dup( fildes:int ):int;

    /**
     * Duplicate an open file descriptor.
     *
     * <p>
     * The <code>dup2()</code> function shall cause the file descriptor <code>fildes2</code>
     * to refer to the same open file description as the file descriptor <code>fildes</code>
     * and to share any locks, and shall return <code>fildes2</code>.
     * </p>
     * 
     * <p>
     * If <code>fildes2</code> is already a valid open file descriptor,
     * it shall be closed first, unless <code>fildes</code> is equal to <code>fildes2</code>
     * in which case <code>dup2()</code> shall return <code>fildes2</code> without closing it.
     * </p>
     * 
     * <p>
     * If the close operation fails to close <code>fildes2</code>,
     * <code>dup2()</code> shall return <code>-1</code> without changing the open
     * file description to which <code>fildes2</code> refers.
     * </p>
     * 
     * <p>
     * If <code>fildes</code> is not a valid file descriptor,
     * <code>dup2()</code> shall return <code>-1</code> and shall not close <code>fildes2</code>.
     * </p>
     * 
     * <p>
     * If <code>fildes2</code> is less than <code>0</code> or greater than or equal to <code>{OPEN_MAX}</code>,
     * <code>dup2()</code> shall return <code>-1</code> with <code>errno</code> set to <code>EBADF</code>.
     * </p>
     *
     * @example Usage
     * <listing>
     * import C.errno.&#42;;
     * import C.unistd.&#42;;
     *
     * // redirect messages from stderr to stdout
     * var outcopy:int = dup2( STDOUT_FILENO, STDERR_FILENO );
     * 
     * </listing>
     *
     * @example Redirect to a file
     * <listing>
     * import C.errno.&#42;;
     * import C.stdlib.&#42;;
     * import C.unistd.&#42;;
     * 
     * // we open a file
     * var myfile:int = open( "myfile.txt", O_APPEND | O_WRONLY );
     * 
     * // we redirect the standard output to file
     * var result:int = dup2( myfile, STDOUT_FILENO );
     * 
     * // now standard out has been redirected, we can write to the file
     * trace( "This will print in myfile.txt" );
     * 
     * </listing>
     * 
     * @param fildes The source file descriptor.
     * @param fildes2 The destination file descriptor.
     * @return Upon successful completion a non-negative integer, namely the file descriptor,
     * shall be returned; otherwise, <code>-1</code> shall be returned and <code>errno</code> set to indicate the error.
     *
     * @throws C.errno.CError <b>EBADF</b> The <code>fildes</code> argument is not a valid open file descriptor or the argument <code>fildes2</code> is negative or greater than or equal to <code>{OPEN_MAX}</code>.
     * @throws C.errno.CError <b>EINTR</b> The <code>dup2()</code> function was interrupted by a signal.
     * @throws C.errno.CError <b>EIO</b> An I/O error occurred while attempting to close <code>fildes2</code>.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see C.errno#EBADF
     * @see C.errno#EINTR
     * @see C.errno#EIO
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/dup2.html
     */
    [native("::avmshell::CUnistdClass::dup2")]
    public native function dup2( fildes:int, fildes2:int ):int;

    /* note:

        e = envp, array of pointers to environment settings, is passed to the new process.

        l = Command-line arguments are passed individually to _exec function.
            Typically used when the number of parameters to the new process is known in advance.
        
        p = PATH environment variable is used to find the file to execute.

        v = argv, array of pointers to command-line arguments, is passed to _exec.
            Typically used when the number of parameters to the new process is variable.
    
    */

    /**
     * Execute a file.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CUnistdClass::execl")]
    public native function execl( path:String, ...args ):int;

    /**
     * Execute a file.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CUnistdClass::execle")]
    public native function execle( path:String, ...args ):int;

    /**
     * Execute a file.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CUnistdClass::execlp")]
    public native function execlp( file:String, ...args ):int;

    /**
     * Execute a file.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CUnistdClass::execv")]
    public native function execv( path:String, argv:Array ):int;

    /**
     * Execute a file.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CUnistdClass::execve")]
    public native function execve( path:String, argv:Array, envp:Array ):int;

    /**
     * Execute a file.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CUnistdClass::execvp")]
    public native function execvp( file:String, argv:Array ):int;

    /**
     * Synchronize changes to a file.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CUnistdClass::fsync")]
    public native function fsync( fildes:int ):int;

    /**
     * Truncate a file to a specified length.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CUnistdClass::ftruncate")]
    public native function ftruncate( fildes:int, length:uint ):int;




















    /**
     * Change mode of a file.
     * 
     * <p><b>note:</b></p>
     * <p>
     * under WIN32 chmod is limited, you will only be able to set read or write at the user level
     * </p>
     * <code>chmod( "myfile.txt", S_WRITE );</code>
     * <p>
     * will be the same as
     * </p>
     * <code>chmod( "myfile.txt", (S_IWUSR | S_IWGRP | S_IWOTH ) );</code>
     * 
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    /*public function chmod( path:String, mode:int ):int
    {
        return __unistd.chmod( path, mode );
    }*/
    
    /**
     * Get the pathname of the current working directory.
     * 
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public function getcwd():String
    {
        return __unistd.getcwd();
    }

    /**
     * Get the name of the current host.
     * 
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public function gethostname():String
    {
        return __unistd.gethostname();
    }

    /**
     * Get the login name of the current user.
     * 
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public function getlogin():String
    {
        return __unistd.getlogin();
    }

    /**
     * Get the process ID.
     * 
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public function getpid():int
    {
        return __unistd.getpid();
    }

    /**
     * Make directory.
     * 
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    /*public function mkdir( path:String ):int
    {
        return __unistd.mkdir( path );
    }*/

    /**
     * Remove directory.
     * 
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public function rmdir( path:String ):int
    {
        return __unistd.rmdir( path );
    }

    /**
     * Suspend execution for an interval of time.
     *
     * <p><b>note:</b></p>
     * <p>
     * <code>sleep()</code> in C usually use seconds, here we are using milliseconds
     * </p>
     * 
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public function sleep( milliseconds:uint ):void
    {
        __unistd.sleep( milliseconds );
    }

    /**
     * Remove a directory entry.
     * 
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public function unlink( path:String ):int
    {
        return __unistd.unlink( path );
    }

}
