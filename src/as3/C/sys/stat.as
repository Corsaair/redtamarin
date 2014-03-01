/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package C.sys.stat
{
    /** @internal */
    [native(cls="::avmshell::CSysStatClass", methods="auto", construct="none")]
    [Inspectable(environment="none")]
    internal class __stat
    {
        /* note:
           we need to wrap mkdir() here so we can override the mode argument
        */
        public native static function _mkdir( path:String, mode:int ):int;
    }

    /**
     * Type of file.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const S_IFMT:int = 0x00F000;
     /*               octal = 0170000 */
     /*             decimal = 61440 */

    /**
     * FIFO special.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const S_IFIFO:int = 0x001000;
     /*                octal = 0010000 */
     /*              decimal = 4096 */

    /**
     * Character special.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const S_IFCHR:int = 0x002000;
     /*                octal = 0020000 */
     /*              decimal = 8192 */

    /**
     * Directory.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const S_IFDIR:int = 0x004000;
     /*                octal = 0040000 */
     /*              decimal = 16384 */

    /**
     * Block special.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const S_IFBLK:int = 0x006000;
     /*                octal = 0060000 */
     /*              decimal = 24576 */

    /**
     * Regular.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const S_IFREG:int = 0x008000;
     /*                octal = 0100000 */
     /*              decimal = 32768 */

    /**
     * Symbolic link.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const S_IFLNK:int = 0x00A000;
     /*                octal = 0120000 */
     /*              decimal = 40960 */

    /**
     * Socket.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const S_IFSOCK:int = 0x00C000;
     /*                 octal = 0140000 */
     /*               decimal = 49152 */


    

    /**
     * Read, write, execute/search by owner.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const S_IRWXU:int = 0x0001C0;
     /*                 octal = 0000700 */
     /*               decimal = 448 */
     /*                 owner:  ?rwx------ */

    /**
     * Read permission, owner.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const S_IRUSR:int = 0x000100;
     /*                 octal = 0000400 */
     /*               decimal = 256 */
     /*                 owner:  ?r-------- */

    /**
     * Write permission, owner.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const S_IWUSR:int = 0x000080;
     /*                 octal = 0000200 */
     /*               decimal = 128 */
     /*                 owner:  ?-w------- */

    /**
     * Execute/search permission, owner.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const S_IXUSR:int = 0x000040;
     /*                 octal = 0000100 */
     /*               decimal = 64 */
     /*                 owner:  ?--x------ */

    /**
     * Read, write, execute/search by group.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const S_IRWXG:int = 0x000038;
     /*                 octal = 0000070 */
     /*               decimal = 56 */
     /*                 owner:  ?---rwx--- */

    /**
     * Read permission, group.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const S_IRGRP:int = 0x000020;
     /*                 octal = 0000040 */
     /*               decimal = 32 */
     /*                 owner:  ?---r----- */

    /**
     * Write permission, group.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const S_IWGRP:int = 0x000010;
     /*                 octal = 0000020 */
     /*               decimal = 16 */
     /*                 owner:  ?----w---- */

    /**
     * Execute/search permission, group.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const S_IXGRP:int = 0x000008;
     /*                 octal = 0000010 */
     /*               decimal = 8 */
     /*                 owner:  ?-----x--- */

    /**
     * Read, write, execute/search by others.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const S_IRWXO:int = 0x000007;
     /*                 octal = 0000007 */
     /*               decimal = 7 */
     /*                 owner:  ?------rwx */

    /**
     * Read permission, others.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const S_IROTH:int = 0x000004;
     /*                 octal = 0000004 */
     /*               decimal = 4 */
     /*                 owner:  ?------r-- */

    /**
     * Write permission, others.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const S_IWOTH:int = 0x000002;
     /*                 octal = 0000002 */
     /*               decimal = 2 */
     /*                 owner:  ?-------w- */

    /**
     * Execute/search permission, others.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const S_IXOTH:int = 0x000001;
     /*                 octal = 0000001 */
     /*               decimal = 1 */
     /*                 owner:  ?--------x */

    /**
     * Set-user-ID on execution.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const S_ISUID:int = 0x000800;
     /*                 octal = 0004000 */
     /*               decimal = 2048 */
     /*                 owner:  ?--S------ */

    /**
     * Set-group-ID on execution.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const S_ISGID:int = 0x000400;
     /*                 octal = 0002000 */
     /*               decimal = 1024 */
     /*                 owner:  ?-----S--- */

    /**
     * On directories, restricted deletion flag.
     *
     * <p>
     * Also called the "sticky bit".
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const S_ISVTX:int = 0x000200;
     /*                 octal = 0001000 */
     /*               decimal = 512 */
     /*                 owner:  ?--------T */

    /**
     * Obsolete synonym of <code>S_ISVTX</code> provided for BSD and backward compatibility.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const S_ISTXT:int = S_ISVTX;

    /**
     * Obsolete synonym of <code>S_IRUSR</code> provided for BSD and backward compatibility.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const S_IREAD:int = S_IRUSR;

    /**
     * Obsolete synonym of <code>S_IWUSR</code> provided for BSD and backward compatibility.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const S_IWRITE:int = S_IWUSR;

    /**
     * Obsolete synonym of <code>S_IXUSR</code> provided for BSD and backward compatibility.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const S_IEXEC:int = S_IXUSR;

    /**
     * Access permissions (<code>0777</code>).
     *
     * <p>
     * Equivalent to <code>S_IRWXU | S_IRWXG | S_IRWXO</code>.
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const ACCESSPERMS:int = (S_IRWXU|S_IRWXG|S_IRWXO);   /* 0777 */

    /**
     * All permissions (<code>7777</code>).
     *
     * <p>
     * Equivalent to <code>S_ISUID | S_ISGID | S_ISVTX | S_IRWXU | S_IRWXG | S_IRWXO</code>.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const ALLPERMS:int = (S_ISUID|S_ISGID|S_ISVTX|S_IRWXU|S_IRWXG|S_IRWXO); /* 7777 */

    /**
     * Default file mode (<code>0666</code>).
     *
     * <p>
     * Equivalent to <code>S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH</code>.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public const DEFFILEMODE:int = (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH); /* 0666 */



    /**
     * Test for a directory.
     *
     * @example Usage
     * <listing>
     * var info:status: new status();
     * stat( "somefile", info );
     * 
     * trace( "is a directory: " + S_ISDIR( info.st_mode ) );
     * </listing>
     * 
     * @param mode The permission bits.
     * @return If is a directory should return <code>true</code>;
     * Otherwise returns <code>false</code>.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function S_ISDIR( mode:int ):Boolean
    {
        //((m & 0170000) == 0040000)
        return (mode & S_IFMT) == S_IFDIR;
    }

    /**
     * Test for a character special file.
     *
     * @example Usage
     * <listing>
     * var info:status: new status();
     * stat( "somefile", info );
     * 
     * trace( "is a character special file: " + S_ISCHR( info.st_mode ) );
     * </listing>
     * 
     * @param mode The permission bits.
     * @return If is a character special file should return <code>true</code>;
     * Otherwise returns <code>false</code>.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function S_ISCHR( mode:int ):Boolean
    {
        //((m & 0170000) == 0020000)
        return (mode & S_IFMT) == S_IFCHR;
    }

    /**
     * Test for a block special file.
     *
     * @example Usage
     * <listing>
     * var info:status: new status();
     * stat( "somefile", info );
     * 
     * trace( "is a block special file: " + S_ISBLK( info.st_mode ) );
     * </listing>
     * 
     * @param mode The permission bits.
     * @return If is a block special file should return <code>true</code>;
     * Otherwise returns <code>false</code>.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function S_ISBLK( mode:int ):Boolean
    {
        //((m & 0170000) == 0060000)
        return (mode & S_IFMT) == S_IFBLK;
    }

    /**
     * Test for a regular file.
     *
     * @example Usage
     * <listing>
     * var info:status: new status();
     * stat( "somefile", info );
     * 
     * trace( "is a regular file: " + S_ISREG( info.st_mode ) );
     * </listing>
     * 
     * @param mode The permission bits.
     * @return If is a regular file should return <code>true</code>;
     * Otherwise returns <code>false</code>.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function S_ISREG( mode:int ):Boolean
    {
        //((m & 0170000) == 0100000)
        return (mode & S_IFMT) == S_IFREG;
    }

    /**
     * Test for a pipe or FIFO special file.
     *
     * @example Usage
     * <listing>
     * var info:status: new status();
     * stat( "somefile", info );
     * 
     * trace( "is a FIFO special file: " + S_ISFIFO( info.st_mode ) );
     * </listing>
     * 
     * @param mode The permission bits.
     * @return If is a FIFO special file should return <code>true</code>;
     * Otherwise returns <code>false</code>.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function S_ISFIFO( mode:int ):Boolean
    {
        //((m & 0170000) == 0010000)
        return (mode & S_IFMT) == S_IFIFO;
    }

    /**
     * Test for a symbolic link.
     *
     * @example Usage
     * <listing>
     * var info:status: new status();
     * stat( "somefile", info );
     * 
     * trace( "is a symbolic link: " + S_ISLNK( info.st_mode ) );
     * </listing>
     * 
     * @param mode The permission bits.
     * @return If is a symbolic link should return <code>true</code>;
     * Otherwise returns <code>false</code>.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function S_ISLNK( mode:int ):Boolean
    {
        //((m & 0170000) == 0120000)
        return (mode & S_IFMT) == S_IFLNK;
    }

    /**
     * Test for a socket.
     *
     * @example Usage
     * <listing>
     * var info:status: new status();
     * fstat( sockfd, info );
     * 
     * trace( "is a socket: " + S_ISSOCK( info.st_mode ) );
     * </listing>
     * 
     * @param mode The permission bits.
     * @return If is a socket should return <code>true</code>;
     * Otherwise returns <code>false</code>.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function S_ISSOCK( mode:int ):Boolean
    {
        //((m & 0170000) == 0140000)
        return (mode & S_IFMT) == S_IFSOCK;
    }


    /**
     * Change mode of a file relative to directory path.
     *
     * <p>
     * The <code>chmod()</code> function shall change <code>S_ISUID</code>, <code>S_ISGID</code>,
     * <code>S_ISVTX</code>, and the file permission bits of the file named by the pathname
     * pointed to by the <code>path</code> argument to the corresponding bits in the <code>mode</code> argument.
     * </p>
     * 
     * <p>
     * <code>S_ISUID</code>, <code>S_ISGID</code>, <code>S_ISVTX</code>,
     * and the file permission bits are described in <b>C.sys.stat</b>.
     * </p>
     *
     * <p>
     * Additional implementation-defined restrictions may cause the <code>S_ISUID</code>
     * and <code>S_ISGID</code> bits in mode to be ignored.
     * </p>
     *
     * <p>
     * Upon successful completion, <code>chmod()</code> shall mark for update
     * the last file status change timestamp of the file.
     * </p>
     *
     * @example Setting Read Permissions for User, Group, and Others
     * <listing>
     * chmod( "/etc/myfile", S_IRUSR|S_IRGRP|S_IROTH );
     * </listing>
     *
     * @example Setting Read, Write, and Execute Permissions for the Owner Only
     * <listing>
     * chmod( "/etc/myfile", S_IRWXU );
     * </listing>
     *
     * @example Setting and Checking File Permissions
     * <listing>
     * import C.sys.stat.&#42;;
     * import C.string.&#42;;
     * import C.errno.&#42;;
     * 
     * chmod( "/etc/myfile", S_IRWXU | S_IRGRP | S_IROTH );
     * 
     * var info:status = new status();
     * var result:int = stat( "/etc/myfile", info );
     * 
     * if( result == -1 )
     * {
     *     // if "/etc/myfile" does not exists you'll get
     *     // ERROR: No such file or directory
     *     trace( "ERROR: " + strerror( errno ) );
     * }
     * 
     * trace( " mode = " + strmode( info.st_mode ) ); //   mode = -rwxr--r--
     * trace( "octal = " + stroctal( info.st_mode ) ); // octal = 744
     * </listing>
     * 
     * @param path The pathname of the file to be changed.
     * @param mode The file permission bits.
     * @return Upon successful completion, these functions shall return <code>0</code>.
     * Otherwise, these functions shall return <code>-1</code> and set <code>errno</code> to indicate the error.
     * If <code>-1</code> is returned, no change to the file mode occurs.
     * 
     * @throws C.errno.CError <b>EACCES</b> Search permission is denied on a component of the <code>path</code> prefix.
     * @throws C.errno.CError <b>ELOOP</b> A loop exists in symbolic links encountered during resolution of the <code>path</code> argument.
     * @throws C.errno.CError <b>ENAMETOOLONG</b> The length of a component of a pathname is longer than <code>NAME_MAX</code>.
     * @throws C.errno.CError <b>ENOENT</b> A component of <code>path</code> does not name an existing file or <code>path</code> is an empty string.
     * @throws C.errno.CError <b>ENOTDIR</b> A component of the <code>path</code> prefix names an existing file that is neither a directory nor a symbolic link to a directory, or the <code>path</code> argument contains at least one non-&lt;slash&gt; character and ends with one or more trailing &lt;slash&gt; characters and the last pathname component names an existing file that is neither a directory nor a symbolic link to a directory.
     * @throws C.errno.CError <b>EPERM</b> The effective user ID does not match the owner of the file and the process does not have appropriate privileges.
     * @throws C.errno.CError <b>EROFS</b> The named file resides on a read-only file system.
     *
     * @throws C.errno.CError <b>EINTR</b> A signal was caught during execution of the function.
     * @throws C.errno.CError <b>EINVAL</b> The value of the <code>mode</code> argument is invalid.
     * @throws C.errno.CError <b>ELOOP</b> More than <code>SYMLOOP_MAX</code> symbolic links were encountered during resolution of the path argument.
     * @throws C.errno.CError <b>ENAMETOOLONG</b> The length of a pathname exceeds <code>PATH_MAX</code>, or pathname resolution of a symbolic link produced an intermediate result with a length that exceeds <code>PATH_MAX</code>.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see C.errno#EACCES
     * @see C.errno#ELOOP
     * @see C.errno#ENAMETOOLONG
     * @see C.errno#ENOENT
     * @see C.errno#ENOTDIR
     * @see C.errno#EPERM
     * @see C.errno#EROFS
     * @see C.errno#EINTR
     * @see C.errno#EINVAL
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/chmod.html
     */
    [native("::avmshell::CSysStatClass::chmod")]
    public native function chmod( path:String, mode:int ):int;

    /**
     * Get file status.
     *
     * <p>
     * The <code>fstat()</code> function shall obtain information about an open file
     * associated with the file descriptor <code>fildes</code>, and shall write it to
     * the area pointed to by <code>buf</code>.
     * </p>
     *
     * <p>
     * The <code>buf</code> argument is a pointer to a <code>status</code> structure,
     * as defined in <b>C.sys.stat</b>, into which information is placed concerning the file.
     * </p>
     *
     * <p>
     * For all other file types defined in this volume of POSIX.1-2008,
     * the structure members <code>st_mode</code>, <code>st_ino</code>, <code>st_dev</code>,
     * <code>st_uid</code>, <code>st_gid</code>, <code>st_atime</code>, <code>st_ctime</code>,
     * and <code>st_mtime</code> shall have meaningful values and the value of the <code>st_nlink</code>
     * member shall be set to the number of links to the file.
     * </p>
     *
     * <p>
     * The <code>fstat()</code> function shall update any time-related fields,
     * before writing into the <code>status</code> structure.
     * </p>
     *
     * @example Usage
     * <listing>
     * import C.sys.stat.&#42;;
     * import C.stdio.&#42;;
     * 
     * var myfile:FILE = fopen( "/etc/myfile", "r" );
     * var fd:int = fileno( myfile );
     * 
     * var info:status = new status();
     * var result:int = fstat( fd, info );
     * </listing>
     * 
     * @param fildes The file descriptor.
     * @param buf The <code>status</code> structure.
     * @return Upon successful completion, <code>0</code> shall be returned.
     * Otherwise, <code>-1</code> shall be returned and <code>errno</code> set to indicate the error.
     *
     * @throws C.errno.CError <b>EBADF</b> The <code>fildes</code> argument is not a valid file descriptor.
     * @throws C.errno.CError <b>EIO</b> An I/O error occurred while reading from the file system.
     * @throws C.errno.CError <b>EOVERFLOW</b> The file size in bytes or the number of blocks allocated to the file or the file serial number cannot be represented correctly in the structure pointed to by <code>buf</code>.
     *
     * @throws C.errno.CError <b>EOVERFLOW</b> One of the values is too large to store into the structure pointed to by the <code>buf</code> argument.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see C.errno#EBADF
     * @see C.errno#EIO
     * @see C.errno#EOVERFLOW
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/fstat.html
     */
    [native("::avmshell::CSysStatClass::fstat")]
    public native function fstat( fildes:int, buf:status ):int;
    
    /**
     * Return the current value of the file creation mask for the current process.
     *
     * <p>
     * <b>Note: </b>
     * not part of the C standard lib,
     * This function is a GNU extension and is usually only available on GNU/Hurd systems.
     * Non-standard but we added it.
     * </p>
     *
     * @example Get the current umask
     * <listing>
     * import C.sys.stat.&#42;;
     * import C.string.&#42;;
     * 
     * var current_mask:int = getumask();
     * trace( "current mask = " +  strmode( current_mask ) + " (" + stroctal( current_mask ) + ")" );
     * // current mask = ?----w--w- (022)
     * </listing>
     * 
     * @return The current file creation mask.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function getumask():int
    {
        var m:int = umask( 0 );
        umask( m );
        return m;
    }

    /**
     * Make a directory relative to directory path.
     *
     * <p>
     * The <code>mkdir()</code> function shall create a new directory with name <code>path</code>.
     * The file permission bits of the new directory shall be initialized from <code>mode</code>.
     * These file permission bits of the <code>mode</code> argument shall be modified by the
     * process' file creation mask.
     * </p>
     *
     * <p>
     * When bits in <code>mode</code> other than the file permission bits are set,
     * the meaning of these additional bits is implementation-defined.
     * </p>
     *
     * <p>
     * The newly created directory shall be an empty directory.
     * </p>
     *
     * <p>
     * If <code>path</code> names a symbolic link,
     * <code>mkdir()</code> shall fail and set <code>errno</code> to <code>EEXIST</code>.
     * </p>
     *
     * <p>
     * Upon successful completion, <code>mkdir()</code> shall mark for update the last data
     * access, last data modification, and last file status change timestamps of the directory.
     * Also, the last data modification and last file status change timestamps of the directory
     * that contains the new entry shall be marked for update.
     * </p>
     *
     * <p>
     * <b>Note: </b> If the <code>mode</code> argument is not provided,
     * it defaults to <code>S_IRWXU | S_IRWXG | S_IRWXO</code>.
     * </p>
     *
     * <p>
     * <b>Note: </b> under <b>windows</b> the <code>mode</code> argument does nothing.
     * </p>
     *
     * @example Create a directory with default mode
     * <listing>
     * import C.sys.stat.&#42;;
     * import C.string.&#42;;
     * 
     * mkdir( "xyz" ); //default umask 022 apply
     * 
     * var info:status = new status();
     * stat( "xyz", info );
     * trace( "directory = " +  strmode( info.st_mode ) + " (" + stroctal( info.st_mode ) + ")" );
     * // directory = drwxr-xr-x (755)
     * </listing>
     *
     * @example Create a directory with file permission bits
     * <listing>
     * import C.sys.stat.&#42;;
     * import C.string.&#42;;
     * 
     * mkdir( "xyz", S_IRWXU | S_IRWXG );
     * 
     * var info:status = new status();
     * stat( "xyz", info );
     * trace( "directory = " +  strmode( info.st_mode ) + " (" + stroctal( info.st_mode ) + ")" );
     * // directory = drwxr-x--- (750)
     * </listing>
     * 
     * @param path The pathname of the directory to be created.
     * @param mode The file permission bits (optional).
     * @return Upon successful completion, this function shall return <code>0</code>.
     * Otherwise, this function shall return <code>-1</code> and set <code>errno</code>
     * to indicate the error.
     * If <code>-1</code> is returned, no directory shall be created.
     *
     * @throws C.errno.CError <b>EACCES</b> Search permission is denied on a component of the <code>path</code> prefix, or write permission is denied on the parent directory of the directory to be created.
     * @throws C.errno.CError <b>EEXIST</b> The named file exists.
     * @throws C.errno.CError <b>ELOOP</b> A loop exists in symbolic links encountered during resolution of the <code>path</code> argument.
     * @throws C.errno.CError <b>EMLINK</b> The link count of the parent directory would exceed <code>LINK_MAX</code>.
     * @throws C.errno.CError <b>ENAMETOOLONG</b> The length of a component of a pathname is longer than <code>NAME_MAX</code>.
     * @throws C.errno.CError <b>ENOENT</b> A component of the <code>path</code> prefix specified by path does not name an existing directory or <code>path</code> is an empty string.
     * @throws C.errno.CError <b>ENOSPC</b> The file system does not contain enough space to hold the contents of the new directory or to extend the parent directory of the new directory.
     * @throws C.errno.CError <b>ENOTDIR</b> A component of the <code>path</code> prefix names an existing file that is neither a directory nor a symbolic link to a directory.
     * @throws C.errno.CError <b>EROFS</b> The parent directory resides on a read-only file system.
     * 
     * @throws C.errno.CError <b>ELOOP</b> More than <code>SYMLOOP_MAX</code> symbolic links were encountered during resolution of the <code>path</code> argument.
     * @throws C.errno.CError <b>ENAMETOOLONG</b> The length of a pathname exceeds <code>PATH_MAX</code>, or pathname resolution of a symbolic link produced an intermediate result with a length that exceeds <code>PATH_MAX</code>.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     * 
     * @see C.errno#EACCES
     * @see C.errno#EEXIST
     * @see C.errno#ELOOP
     * @see C.errno#EMLINK
     * @see C.errno#ENAMETOOLONG
     * @see C.errno#ENOENT
     * @see C.errno#ENOSPC
     * @see C.errno#ENOTDIR
     * @see C.errno#EROFS
     * @see http://www.gnu.org/software/libc/manual/html_node/Permission-Bits.html The Mode Bits for Access Permission
     */
    public function mkdir( path:String, mode:int = -1 ):int
    {
        if( mode == -1 )
        {
            mode = S_IRWXU | S_IRWXG | S_IRWXO;
        }

        return __stat._mkdir( path, mode );
    }

    /**
     * Get file status.
     *
     * <p>
     * The <code>stat()</code> function shall obtain information about the named file
     * and write it to the area pointed to by the <code>buf</code> argument.
     * The <code>path</code> argument points to a pathname naming a file.
     * Read, write, or execute permission of the named file is not required.
     * An implementation that provides additional or alternate file access control mechanisms
     * may, under implementation-defined conditions, cause <code>stat()</code> to fail.
     * In particular, the system may deny the existence of the file specified by path.
     * </p>
     * 
     * <p>
     * If the named file is a symbolic link, the <code>stat()</code> function shall continue
     * pathname resolution using the contents of the symbolic link,
     * and shall return information pertaining to the resulting file if the file exists.
     * </p>
     *
     * <p>
     * The <code>buf</code> argument is a pointer to a <code>status</code> structure,
     * as defined in <b>C.stat</b>, into which information is placed concerning the file.
     * </p>
     *
     * <p>
     * The <code>stat()</code> function shall update any time-related fields,
     * before writing into the <code>status</code> structure.
     * </p>
     *
     * @example Usage
     * <listing>
     * import C.sys.stat.&#42;;
     * import C.string.&#42;;
     * 
     * /&#42;&#42;
     *  &#42; Formats bytes into a human readable string.
     *  &#42; 
     *  &#42; &#64;param bytes The bytes value to format.
     *  &#42; &#64;param precision An integer between 0 and 20, inclusive,
     *  &#42;                      that represents the desired number of decimal places.
     *  &#42; &#64;param SI Indicates if the formatter use the
     *  &#42;               International System of Units (SI).
     *  &#42; &#64;param force A string to force a particular unit
     *  &#42;                  ("K","M","G","T","P","E","Z","Y")
     *  &#42;/ 
     * function bytesToHumanReadable( bytes:Number, precision:uint = 2,
     *                                SI:Boolean = false, force:String = "" ):String
     * {
     *     const unit:uint = SI ? 1000 : 1024;
     *     
     *     if( (bytes &lt; unit) &#38;&#38; ((force == "") || (force == "B")) ) 
     *     { 
     *         return bytes + " B"; 
     *     }
     *     
     *     var u:String;
     *     var s:String;
     *     
     *     const kilo:Number  = unit;
     *     const mega:Number  = kilo  &#42; unit;
     *     const giga:Number  = mega  &#42; unit;
     *     const tera:Number  = giga  &#42; unit;
     *     const peta:Number  = tera  &#42; unit;
     *     const exa:Number   = peta  &#42; unit;
     *     const zetta:Number = exa   &#42; unit;
     *     const yotta:Number = zetta &#42; unit;
     *     
     *     if( (bytes &gt;= 0) &#38;&#38; (bytes &lt; kilo) )           { u =  ""; }
     *     else if( (bytes &gt;= kilo)  &#38;&#38; (bytes &lt; mega) )  { u = "K"; }
     *     else if( (bytes &gt;= mega)  &#38;&#38; (bytes &lt; giga) )  { u = "M"; }
     *     else if( (bytes &gt;= giga)  &#38;&#38; (bytes &lt; tera) )  { u = "G"; }
     *     else if( (bytes &gt;= tera)  &#38;&#38; (bytes &lt; peta) )  { u = "T"; }
     *     else if( (bytes &gt;= peta)  &#38;&#38; (bytes &lt; exa) )   { u = "P"; }
     *     else if( (bytes &gt;= exa)   &#38;&#38; (bytes &lt; zetta) ) { u = "E"; }
     *     else if( (bytes &gt;= zetta) &#38;&#38; (bytes &lt; yotta) ) { u = "Z"; }
     *     else if( (bytes &gt;= yotta) )                    { u = "Y"; }
     *     
     *     if( force != "" )
     *     {
     *         if( force == "B" ) { force = ""; }
     *         u = force;
     *     }
     *     
     *     switch( u )
     *     {
     *         case "K": s = Number( bytes / kilo  ).toFixed( precision ); break;
     *         case "M": s = Number( bytes / mega  ).toFixed( precision ); break;
     *         case "G": s = Number( bytes / giga  ).toFixed( precision ); break;
     *         case "T": s = Number( bytes / tera  ).toFixed( precision ); break;
     *         case "P": s = Number( bytes / peta  ).toFixed( precision ); break;
     *         case "E": s = Number( bytes / exa   ).toFixed( precision ); break;
     *         case "Z": s = Number( bytes / zetta ).toFixed( precision ); break;
     *         case "Y": s = Number( bytes / yotta ).toFixed( precision ); break;
     *         case "":
     *         default:
     *         s = bytes + "";
     *     }
     *     
     *     var zeros:String = new Array(precision+1).join("0");
     *     var parts:Array  = s.split(".");
     *     
     *     if( s.indexOf( "." ) &gt; -1 &#38;&#38; (zeros == parts[1]) ) 
     *     { 
     *         s = parts[0]; 
     *     }
     *     
     *     return s + " " + u + (SI ? "i" : "") + "B";
     * }
     * 
     * var info:status = new status();
     * var result:int = stat( "/etc/myfile.bin", info );
     * 
     * trace( "file mode: " + strmode( info.st_mode ) );
     * trace( "file size: " + info.st_size + " bytes" );
     * trace( "file size: " + bytesToHumanReadable( info.st_size, 3, true, "K" ) );
     * trace( "file size: " + bytesToHumanReadable( info.st_size, 3, false, "K" ) );
     * trace( "file size: " + bytesToHumanReadable( info.st_size, 3 ) );
     * trace( "file size: " + bytesToHumanReadable( info.st_size, 3, true ) );
     * 
     * // will output something like
     * 
     * // file mode: -rwxr-xr-x
     * // file size: 6836396 bytes
     * // file size: 6836.396 KiB
     * // file size: 6676.168 KB
     * // file size: 6.520 MB
     * // file size: 6.836 MiB
     * </listing>
     * 
     * @param path The pathname naming a file.
     * @param buf The <code>status</code> structure.
     * @return Upon successful completion, these functions shall return <code>0</code>.
     * Otherwise, these functions shall return <code>-1</code> and set <code>errno</code> to indicate the error.
     * 
     * @throws C.errno.CError <b>EACCES</b> Search permission is denied for a component of the <code>path</code> prefix.
     * @throws C.errno.CError <b>EIO</b> An error occurred while reading from the file system.
     * @throws C.errno.CError <b>ELOOP</b> A loop exists in symbolic links encountered during resolution of the <code>path</code> argument.
     * @throws C.errno.CError <b>ENAMETOOLONG</b> The length of a component of a pathname is longer than <code>NAME_MAX</code>.
     * @throws C.errno.CError <b>ENOENT</b> A component of <code>path</code> does not name an existing file or <code>path</code> is an empty string.
     * @throws C.errno.CError <b>ENOTDIR</b> A component of the <code>path</code> prefix names an existing file that is neither a directory nor a symbolic link to a directory, or the <code>path</code> argument contains at least one non-&lt;slash&gt; character and ends with one or more trailing &lt;slash&gt; characters and the last pathname component names an existing file that is neither a directory nor a symbolic link to a directory.
     * @throws C.errno.CError <b>EOVERFLOW</b> The file size in bytes or the number of blocks allocated to the file or the file serial number cannot be represented correctly in the structure pointed to by <code>buf</code>.
     *
     * @throws C.errno.CError <b>ELOOP</b> More than <code>SYMLOOP_MAX</code> symbolic links were encountered during resolution of the <code>path</code> argument.
     * @throws C.errno.CError <b>ENAMETOOLONG</b> The length of a pathname exceeds <code>PATH_MAX</code>, or pathname resolution of a symbolic link produced an intermediate result with a length that exceeds <code>PATH_MAX</code>.
     * @throws C.errno.CError <b>EOVERFLOW</b> A value to be stored would overflow one of the members of the <code>status</code> structure.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     * 
     * @see C.errno#EACCES
     * @see C.errno#EIO
     * @see C.errno#ELOOP
     * @see C.errno#ENAMETOOLONG
     * @see C.errno#ENOENT
     * @see C.errno#ENOTDIR
     * @see C.errno#EOVERFLOW
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/stat.html
     */
    [native("::avmshell::CSysStatClass::stat")]
    public native function stat( path:String, buf:status ):int;

    /**
     * Set and get the file mode creation mask
     *
     * <p>
     * The <code>umask()</code> function shall set the file mode creation mask of the process
     * to <code>cmask</code> and return the previous value of the mask.
     * Only the file permission bits of <code>cmask</code> are used;
     * the meaning of the other bits is implementation-defined.
     * </p>
     * 
     * <p>
     * The file mode creation mask of the process is used to turn off permission bits
     * in the mode argument supplied during calls to the following functions:
     * <code>open()</code>, <code>creat()</code>, <code>mkdir()</code>, etc.
     * </p>
     *
     * <p>
     * Bit positions that are set in <code>cmask</code> are cleared in the mode of the created file.
     * </p>
     *
     * @example Default umask
     * <listing>
     * import C.sys.stat.&#42;;
     * import C.string.&#42;;
     *
     * //by default umask is 022
     * var current_mask:int = getumask();
     * trace( "current mask = " +  strmode( current_mask ) + " (" + stroctal( current_mask ) + ")" );
     * // current mask = ?----w--w- (022)
     * 
     * // we create a directory
     * mkdir( "xyz" );
     * 
     * var info:status = new status();
     * stat( "xyz", info );
     * trace( "directory = " +  strmode( info.st_mode ) + " (" + stroctal( info.st_mode ) + ")" );
     * // directory = drwxr-xr-x (755)
     * </listing>
     *
     * @example Updating umask
     * <listing>
     * import C.sys.stat.&#42;;
     * import C.string.&#42;;
     * 
     * //we update the umask to 055
     * var old_mask:int = umask( S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH );
     * trace( "old mask = " +  strmode( old_mask ) + " (" + stroctal( old_mask ) + ")" );
     * // old mask = ?----w--w- (022)
     * 
     * var current_mask:int = getumask();
     * trace( "current mask = " +  strmode( current_mask ) + " (" + stroctal( current_mask ) + ")" );
     * // current mask = ?---r-xr-x (055)
     * 
     * // we create a directory
     * mkdir( "xyz" );
     * 
     * var info:status = new status();
     * stat( "xyz", info );
     * trace( "directory = " +  strmode( info.st_mode ) + " (" + stroctal( info.st_mode ) + ")" );
     * // directory = drwx-w--w- (722)
     * </listing>
     * 
     * @param cmask The creation mask.
     * @return The file permission bits in the value returned by <code>umask()</code>
     * shall be the previous value of the file mode creation mask.
     * The state of any other bits in that value is unspecified,
     * except that a subsequent call to <code>umask()</code> with the returned value
     * as <code>cmask</code> shall leave the state of the mask the same as its state
     * before the first call, including any unspecified use of those bits.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/umask.html
     */
    [native("::avmshell::CSysStatClass::umask")]
    public native function umask( cmask:int ):int;


     /**
      * The status class (<b>stat structure</b>) contains information about a file.
      *
      * <p>
      * The informations will be different depending on the operating system
      * (linux and macintosh vs windows) and depending on the file system
      * (FAT, HPFS, NTFS, etc.).
      * </p>
      * 
      * <p>
      * By itself this class does nothing, you need to create an instance
      * and pass it <b>by reference</b> to one of the <code>stat()</code> functions
      * so the native call can fill in the data structure with the different file informations.
      * </p>
      *
      * @example Usage
      * <listing>
      * import C.sys.stat.&#42;;
      * 
      * // create an instance
      * var info:status = new status();
      * 
      * // now pass it by reference
      * stat( "/etc/myfile", info );
      * 
      * // after that, you can access the file informations
      * trace( "file size = " + info.st_size + " bytes" );
      * </listing>
      * 
      * @langversion 3.0
      * @playerversion AVM 0.4
      *
      * @see C.sys.stat#stat stat()
      */
     [native(cls="::avmshell::CStatusClass", instance="::avmshell::CStatusObject", methods="auto")]
     public class status
     {

        /**
         * Device ID of device containing file.
         *
         * <p>
         * <b>Note:</b> For Windows,
         * Drive number of the disk containing the file (same as <code>st_rdev</code>).
         * </p>
         *
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public var st_dev:int;

        /**
         * File serial number.
         *
         * <p>
         * <b>Note:</b> For Windows,
         * Number of the information node (the inode) for the file (UNIX-specific).
         * On UNIX file systems, the inode describes the file date and time stamps,
         * permissions, and content.
         * When files are hard-linked to one another, they share the same inode.
         * The inode, and therefore <code>st_ino</code>, has no meaning in the
         * <b>FAT</b>, <b>HPFS</b>, or <b>NTFS</b> file systems.
         * </p>
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public var st_ino:uint;

        /**
         * Mode of file (see below).
         *
         * <p>
         * <b>Note:</b> For Windows,
         * Bit mask for file-mode information.
         * The <code>S_IFDIR</code> bit is set if path specifies a directory;
         * the <code>S_IFREG</code> bit is set if path specifies an ordinary file or a device.
         * User read/write bits are set according to the file's permission mode;
         * user execute bits are set according to the filename extension.
         * </p>
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public var st_mode:int;

        /**
         * Number of hard links to the file.
         *
         * <p>
         * <b>Note:</b> For Windows,
         * Always <code>1</code> on <b>non-NTFS</b> file systems.
         * </p>
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public var st_nlink:int;

        /**
         * User ID of file.
         *
         * <p>
         * <b>Note:</b> For Windows,
         * Numeric identifier of user who owns file (UNIX-specific).
         * This field will always be zero on Windows systems.
         * A redirected file is classified as a Windows file.
         * </p>
         *
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public var st_uid:int;

        /**
         * Group ID of file.
         *
         * <p>
         * <b>Note:</b> For Windows,
         * Numeric identifier of group that owns the file (UNIX-specific).
         * This field will always be zero on Windows systems.
         * A redirected file is classified as a Windows file.
         * </p>
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public var st_gid:int;

        /**
         * Device ID (if file is character or block special).
         *
         * <p>
         * <b>Note:</b> For Windows,
         * Drive number of the disk containing the file (same as <code>st_dev</code>).
         * </p>
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public var st_rdev:int;

        /**
         * For regular files, the file size in bytes.
         *
         * <p>
         * <b>Note:</b> For Windows,
         * Size of the file in bytes;
         * a 64-bit integer for variations with the <b>i64</b> suffix.
         * </p>
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public var st_size:Number;

        /**
         * Last data access timestamp.
         *
         * <p>
         * <b>Note:</b> For Windows,
         * Time of last access of file.
         * Valid on <b>NTFS</b> but not on <b>FAT</b> formatted disk drives.
         * </p>
         *
         * <p>
         * <b>Attention: </b> here the time value is represented in <b>seconds</b>,
         * if you need to convert to a <code>Date</code> object you will have to
         * multiply by <code>1000</code> to convert the value to <b>milliseconds</b>.
         * </p>
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public var st_atime:int;

        /**
         * Last data modification timestamp.
         *
         * <p>
         * <b>Note:</b> For Windows,
         * Time of last modification of file.
         * </p>
         *
         * <p>
         * <b>Attention: </b> here the time value is represented in <b>seconds</b>,
         * if you need to convert to a <code>Date</code> object you will have to
         * multiply by <code>1000</code> to convert the value to <b>milliseconds</b>.
         * </p>
         *
         * @example Time convertion
         * <listing>
         * var info:status = new status();
         * var result:int = stat( "somefile", info );
         * 
         * var modified:Date = new Date();
         *     modified.setTime( info.st_mtime &#42; 1000 );
         * </listing>
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public var st_mtime:int;

        /**
         * Last file status change timestamp.
         *
         * <p>
         * <b>Note:</b> For Windows,
         * Time of creation of file.
         * Valid on <b>NTFS</b> but not on <b>FAT</b> formatted disk drives.
         * </p>
         *
         * <p>
         * <b>Attention: </b> here the time value is represented in <b>seconds</b>,
         * if you need to convert to a <code>Date</code> object you will have to
         * multiply by <code>1000</code> to convert the value to <b>milliseconds</b>.
         * </p>
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public var st_ctime:int;

        public function toString():String
        {
            var str:String = "";
                str += "[status:"
                str += " st_dev="+st_dev;
                str += ", st_ino="+st_ino;
                str += ", st_mode="+st_mode;
                str += ", st_nlink="+st_nlink;
                str += ", st_uid="+st_uid;
                str += ", st_gid="+st_gid;
                str += ", st_rdev="+st_rdev;
                str += ", st_size="+st_size;
                str += ", st_atime="+st_atime;
                str += ", st_mtime="+st_mtime;
                str += ", st_ctime="+st_ctime;
                str += "]";

            return str;
        }

     }
}
