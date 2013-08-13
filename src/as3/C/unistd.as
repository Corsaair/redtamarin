/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package C.unistd
{
    
    /**
     * POSIX operating system API
     * @internal
     * 
     * @langversion 3.0
     * @playerversion AVM 0.3
     */
    [native(cls="::avmshell::CUnistdClass", methods="auto", construct="none")]
    [Inspectable(environment="none")]
    internal class __unistd
    {
        public native static function get F_OK():int;
        public native static function get X_OK():int;
        public native static function get W_OK():int;
        public native static function get R_OK():int;

        /* note:
           all those are also normaly defined in <sys/stat.h>
           moved here because of chmod()
        */
        public native static function get S_IFMT():int;
        public native static function get S_IFIFO():int;
        public native static function get S_IFCHR():int;
        public native static function get S_IFDIR():int;
        public native static function get S_IFBLK():int;
        public native static function get S_IFREG():int;
        public native static function get S_IFLNK():int;
        public native static function get S_IFSOCK():int;

        public native static function get S_IRWXU():int;
        public native static function get S_IRUSR():int;
        public native static function get S_IWUSR():int;
        public native static function get S_IXUSR():int;
        
        public native static function get S_IRWXG():int;
        public native static function get S_IRGRP():int;
        public native static function get S_IWGRP():int;
        public native static function get S_IXGRP():int;
        
        public native static function get S_IRWXO():int;
        public native static function get S_IROTH():int;
        public native static function get S_IWOTH():int;
        public native static function get S_IXOTH():int;

        public native static function get S_IREAD():int;
        public native static function get S_IWRITE():int;
        public native static function get S_IEXEC():int;


        public native static function access( path:String, mode:int ):int;  //int access(const char *path, int mode);
        public native static function chdir( path:String ):int;             //int chdir(const char *path);
        public native static function chmod( path:String, mode:int ):int;   //int chmod(const char *path, mode_t mode);
        public native static function getcwd():String;                      //char *getcwd(char *buf, size_t size);
        public native static function gethostname():String;                 //int gethostname(char *name, size_t namelen);
        public native static function getlogin():String;                    //char *getlogin(void);
        public native static function getpid():int;                         //pid_t getpid(void);

        /* note:
           mkdir() is normaly defined in <sys/stat.h> and can define file permission
           eg. int mkdir(const char *path, mode_t mode);
           1. to be in sync with _mkdir() WIN32 which can not define file permission
              we don't allow it in the API, we use those default permissions:
              S_IRWXU = Read, write, execute/search by owner.
              S_IRWXG = Read, write, execute/search by group.
              S_IRWXO = Read, write, execute/search by others.
           2. because unistd define rmdir(), we moved the function here
              instead of having C.sys.stat::mkdir() as it seems cleaner
        */
        public native static function mkdir( path:String ):int;            //int mkdir(const char *path);
        public native static function rmdir( path:String ):int;            //int rmdir(const char *path);
        public native static function sleep( milliseconds:uint ):void;     //unsigned sleep(unsigned seconds);
        public native static function unlink( path:String ):int;           //int unlink(const char *path);
    }

    /** Check for existence.
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public const F_OK:int = __unistd.F_OK;

    /** Check for execute permission.
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public const X_OK:int = __unistd.X_OK;

    /** Check for write permission.
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public const W_OK:int = __unistd.W_OK;

    /** Check for read permission.
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public const R_OK:int = __unistd.R_OK;

    /** Type of file mask.
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public const S_IFMT:int   = __unistd.S_IFMT;
    
    /** Named pipe (fifo).
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public const S_IFIFO:int  = __unistd.S_IFIFO;
    
    /** Character special (device).
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public const S_IFCHR:int  = __unistd.S_IFCHR;
    
    /** Directory.
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public const S_IFDIR:int  = __unistd.S_IFDIR;
    
    /** Block special (device).
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public const S_IFBLK:int  = __unistd.S_IFBLK;
    
    /** Regular file.
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public const S_IFREG:int  = __unistd.S_IFREG;
    
    /** Symbolic link.
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public const S_IFLNK:int  = __unistd.S_IFLNK;
    
    /** Socket.
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public const S_IFSOCK:int = __unistd.S_IFSOCK;

    /** Read/Write/Execute mask for owner.
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public const S_IRWXU:int = __unistd.S_IRWXU;
    /** Read permission for owner.
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public const S_IRUSR:int = __unistd.S_IRUSR;
    /** Write permission for owner.
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public const S_IWUSR:int = __unistd.S_IWUSR;
    /** Execute permission for owner.
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public const S_IXUSR:int = __unistd.S_IXUSR;

    /** Read/Write/Execute mask for group.
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public const S_IRWXG:int = __unistd.S_IRWXG;
    /** Read permission for group.
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public const S_IRGRP:int = __unistd.S_IRGRP;
    /** Write permission for group.
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public const S_IWGRP:int = __unistd.S_IWGRP;
    /** Execute permission for group.
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public const S_IXGRP:int = __unistd.S_IXGRP;

    /** Read/Write/Execute mask for other.
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public const S_IRWXO:int = __unistd.S_IRWXO;
    /** Read permission for other.
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public const S_IROTH:int = __unistd.S_IROTH;
    /** Write permission for other.
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public const S_IWOTH:int = __unistd.S_IWOTH;
    /** Execute permission for other.
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public const S_IXOTH:int = __unistd.S_IXOTH;

    /** Read permission for all (backward compatability).
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public const S_IREAD:int  = __unistd.S_IREAD;
    /** Write permission for all (backward compatability).
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public const S_IWRITE:int = __unistd.S_IWRITE;
    /** Execute permission for all (backward compatability).
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public const S_IEXEC:int  = __unistd.R_OK;


    /**
     * Determine accessibility of a file.
     * 
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public function access( path:String, mode:int ):int
    {
        return __unistd.access( path, mode );
    }
    
    /**
     * Change working directory.
     * 
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public function chdir( path:String ):int
    {
        return __unistd.chdir( path );
    }
    
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
    public function chmod( path:String, mode:int ):int
    {
        return __unistd.chmod( path, mode );
    }
    
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
    public function mkdir( path:String ):int
    {
        return __unistd.mkdir( path );
    }

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

    /**
     * Test 123.
     * 
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public var test123:Boolean = true;

    /**
     * Test 456.
     * 
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public var test456:String = "hello world";

    /**
     * Interface Test 123.
     * 
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public interface ISomething
    {
        function test1():void;
        function test2( a:String ):Boolean;
        function get a():Boolean;
        function set a( value:Boolean ):void;
    }

    /**
     * Class Test 123.
     * 
     * @playerversion AVM 0.3
     * @since 0.3.0
     */
    public class HelloSomething
    {
        public function HelloSomething()
        {

        }

        public var test123:Boolean = false;

        public const ABCD:String = "ABCD";

        public function testThere():void
        {

        }
    }
}
