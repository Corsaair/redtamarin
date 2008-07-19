package C
	{
	
	/* Combine some native call to the C standard library
	   
	   - ANSI Standard library
	   assert.h, ctype.h, errno.h, float.h, limits.h, locale.h,
	   math.h, setjmp.h, signal.h, stdarg.h, stddef.h, 
	   stdio.h, stdlib.h, string.h, time.h
	   
	   
	   - POSIX.1 library
	   that are compatible with
	     - Mac OS X (gcc 3.3)
	     - Microsoft Windows Runtime Library (MS VIsual C++ 7.0)
	    (- Linux (gcc 3.2.2)) [optional, I'm already struggling enought to support OSX and WIN32]
	    
	    unistd.h, windows.h, etc.
	    see: http://www.crossplatformbook.com/posix.html
	   
	   
	   the goal is:
	   import C.stdlib.*; //equivalent to #include <stdlib.h>
	   var home:String = getenv( "HOME" );
	   
	   ref:
	   http://en.wikipedia.org/wiki/ANSI_C
	   http://en.wikipedia.org/wiki/POSIX
	   http://en.wikipedia.org/wiki/Category:C_standard_library
	   http://www.cplusplus.com/reference/clibrary/
	   
	   note:
	   this class exists only to obtain a abcclass_C_standard in toplevel.h
	   so we can declare in avmshell.cpp
	   NATIVE_CLASS(abcclass_C_standard, StandardCClass, ScriptObject)
	   
	   but we keep the declaration of native function in their own package
	   to avoid indirection
	   
	   we want:
	   ----
	   package C.stdlib
	   {
	       public native function rand():int;
	   }
	   ----
	   
	   we don't want:
	   ----
	   package C
	   {
	       public class standard
	       {
	           public native static function rand():int;
	       }
	   }
	   
	   package C.stdlib
	   {
	       import C.standard;
	       
	       public function rand():int
	       {
	           return standard.rand();
	       }
	   }
	   ----
	*/
	internal class standard
		{
		
		}
	
	}

/* <stdlib.h>
   http://en.wikipedia.org/wiki/Stdlib.h
   
   stdlib.h is the header of the general purpose standard library
   of C programming language which includes functions involving memory allocation,
   process control, conversions and others.
   
   It is compatible with C++ and is known as cstdlib in C++.
   The name "stdlib" stands for standard library.
*/
package C.stdlib
	{
	
	/* Type Conversion */
	
	//atof
	//atoi
	//atol
	//strtod
	//strtol
	//strtoul
	
	//-----------------------------------------------------------
	
	/* Pseudo-random sequence generation */
	
	/* Generate a pseudo-random value.
	   
	   info:
	   int rand( void );
	*/
	public native function rand():int;
	
	/* Set the pseudo-random generator seed.
	*/
	//srand
	
	//-----------------------------------------------------------
	
	/* Memory allocation and deallocation */
	
	//malloc
	//calloc
	//realloc
	//free
	
	//-----------------------------------------------------------
	
	/* Process control */
	
	/* Abort current process.
	   
	   info:
	   void abort ( void );
	*/
	public native function abort():void;
	
	
	//public native function _registerAtexit( f:Function ):void;
	
	internal var _exitFunctions:Array = [];
	
	internal function _atexitCallback():void
	    {
	    for( var i:int = 0; i<_exitFunctions.length; i++ )
	        {
	        _exitFunctions[i]();
	        }
	    }
	
	/* Register a callback function for program exit.
	   
	   note:
	   ideally we would want to do that directly from C
	   but because I failed to do that we gonna fake it in AS ;)
	   the limitation is that your atexit function will only
	   be called if you call exit(0) at the edn of your programm
	   
	   info:
	   int atexit ( void ( * function ) (void) );
	*/
	public function atexit( f:Function ):int
	    {
	    /*
	    if( _exitFunctions.length == 0 )
	        {
	        _registerAtexit( _atexitCallback );
	        }
	    */
	    
	    _exitFunctions.unshift( f );
	    return 0;
	    }
	
	internal native function _exit( status:int = 0 ):void;
	
	/* Terminate program execution.
	   
	   info:
	   void exit( int status );
	   http://en.wikipedia.org/wiki/Exit_(operating_system)
	*/
	public function exit( status:int = 0 ):void
	    {
	    _atexitCallback();
	    _exit( status );
	    }
	
	/* Retrieve an environment variable.
	   
	   note:
	   return an empty string if env var not found
	   
	   info:
	   char *getenv( const char *name );
	*/
	public native function getenv( name:String ):String;
	
	/* Set an environment variable.
	   
	   note:
	   If the variable already exists in the environment
	   and rewrite is set, it is overwritten. 
	   
	   info:
	   int setenv( const char *name, const char *value, int rewrite );
	*/
	public native function setenv( name:String, value:String, rewrite:int = 0 ):int;
	
	/* Execute an external command.
	   
	   info:
	   int system( const char *command );
	   http://en.wikipedia.org/wiki/System_(C_Standard_Library)
	*/
	public native function system( command:String ):int;
	
	//-----------------------------------------------------------
	
	/* Sorting and searching */
	
	//bsearch
	//qsort
	
	//-----------------------------------------------------------
	
	/* Mathematics */
	
	//abs
	//labs
	//div
	//ldiv
	
	//-----------------------------------------------------------
	
	}

/* <unistd.h>
   http://www.opengroup.org/onlinepubs/009695399/basedefs/unistd.h.html
   
   standard symbolic constants and types
   The <unistd.h> header defines miscellaneous symbolic constants and types,
   and declares miscellaneous functions.
*/
package C.unistd
	{
	
    /* access function
       see also http://msdn.microsoft.com/en-us/library/1w06ktdy.aspx
       for difference
       
       note:
       in short under WIN32 you can't test for execute (X_OK)
       but you can test for read and write (RW_OK),
       to be on the safe side you should use only F_OK, W_OK and R_OK
    */
    public const    F_OK:int        = 0;              /* test for existence of file */
    public const    X_OK:int        = (1<<0);         /* test for execute or search permission */
    public const    W_OK:int        = (1<<1);         /* test for write permission */
    public const    R_OK:int        = (1<<2);         /* test for read permission */
    public const    RW_OK:int       = 6;              /* test for read and write permission */
	
	/* Extended access functions. */
    public const    _READ_OK:int    = (1<<9);         /* read file data / read directory */
    public const    _WRITE_OK:int   = (1<<10);        /* write file data / add file to directory */
    public const    _EXECUTE_OK:int = (1<<11);        /* execute file / search in directory*/
    public const    _DELETE_OK:int  = (1<<12);        /* delete file / delete directory */
    public const    _APPEND_OK:int  = (1<<13);        /* append to file / add subdirectory to directory */
    public const    _RMFILE_OK:int  = (1<<14);        /* - / remove file from directory */
    public const    _RATTR_OK:int   = (1<<15);        /* read basic attributes */
    public const    _WATTR_OK:int   = (1<<16);        /* write basic attributes */
    public const    _REXT_OK:int    = (1<<17);        /* read extended attributes */
    public const    _WEXT_OK:int    = (1<<18);        /* write extended attributes */
    public const    _RPERM_OK:int   = (1<<19);        /* read permissions */
    public const    _WPERM_OK:int   = (1<<20);        /* write permissions */
    public const    _CHOWN_OK:int   = (1<<21);        /* change ownership */
	
	/* Determine accessibility of file.
	   
	   info:
	   int access( const char *path, int mode );
	   int _access( const char *path, int mode );
	*/
	public native function access( path:String, mode:int ):int;
	
	/* Get the pathname of the current working directory.
	   
	   info:
	   char *getcwd( char *buf, size_t size );
	*/
	public native function getcwd():String;
	
	/* Suspend execution for an interval of time.
	   http://www.opengroup.org/onlinepubs/000095399/functions/sleep.html
	   
	   info:
	   unsigned sleep(unsigned time);
	*/
	public native function sleep( second:uint ):void;
	
	}

/* <errno.h>
   http://www.opengroup.org/onlinepubs/000095399/basedefs/errno.h.html
   http://en.wikipedia.org/wiki/Errno.h
   
   system error numbers
*/
package C.errno
	{
	
	/* Error codes */
    public const    EPERM:int           =  1;        /* Operation not permitted */
    public const    ENOENT:int          =  2;        /* No such file or directory */
    public const    ESRCH:int           =  3;        /* No such process */
    public const    EINTR:int           =  4;        /* Interrupted system call */
    public const    EIO:int             =  5;        /* Input/output error */
    public const    ENXIO:int           =  6;        /* Device not configured */
    public const    E2BIG:int           =  7;        /* Argument list too long */
    public const    ENOEXEC:int         =  8;        /* Exec format error */
    public const    EBADF:int           =  9;        /* Bad file descriptor */
    public const    ECHILD:int          = 10;        /* No child processes */
    public const    EDEADLK:int         = 11;        /* Resource deadlock avoided */
    public const    ENOMEM:int          = 12;        /* Cannot allocate memory */
    public const    EACCES:int          = 13;        /* Permission denied */
    public const    EFAULT:int          = 14;        /* Bad address */
    public const    ENOTBLK:int         = 15;        /* Block device required */
    public const    EBUSY:int           = 16;        /* Device / Resource busy */
    public const    EEXIST:int          = 17;        /* File exists */
    public const    EXDEV:int           = 18;        /* Cross-device link */
    public const    ENODEV:int          = 19;        /* Operation not supported by device */
    public const    ENOTDIR:int         = 20;        /* Not a directory */
    public const    EISDIR:int          = 21;        /* Is a directory */
    public const    EINVAL:int          = 22;        /* Invalid argument */
    public const    ENFILE:int          = 23;        /* Too many open files in system */
    public const    EMFILE:int          = 24;        /* Too many open files */
    public const    ENOTTY:int          = 25;        /* Inappropriate ioctl for device */
    public const    ETXTBSY:int         = 26;        /* Text file busy */
    public const    EFBIG:int           = 27;        /* File too large */
    public const    ENOSPC:int          = 28;        /* No space left on device */
    public const    ESPIPE:int          = 29;        /* Illegal seek */
    public const    EROFS:int           = 30;        /* Read-only file system */
    public const    EMLINK:int          = 31;        /* Too many links */
    public const    EPIPE:int           = 32;        /* Broken pipe */
    
	/* math software */
    public const    EDOM:int            = 33;        /* Numerical argument out of domain */
    public const    ERANGE:int          = 34;        /* Result too large */
    
	/* non-blocking and interrupt i/o */
    public const    EAGAIN:int          = 35;        /* Resource temporarily unavailable */
    public const    EWOULDBLOCK:int     = EAGAIN;    /* Operation would block */
    public const    EINPROGRESS:int     = 36;        /* Operation now in progress */
    public const    EALREADY:int        = 37;        /* Operation already in progress */
	
	/* ipc/network software -- argument errors */
    public const    ENOTSOCK:int        = 38;        /* Socket operation on non-socket */
    public const    EDESTADDRREQ:int    = 39;        /* Destination address required */
    public const    EMSGSIZE:int        = 40;        /* Message too long */
    public const    EPROTOTYPE:int      = 41;        /* Protocol wrong type for socket */
    public const    ENOPROTOOPT:int     = 42;        /* Protocol not available */
    public const    EPROTONOSUPPORT:int = 43;        /* Protocol not supported */
    public const    ESOCKTNOSUPPORT:int = 44;        /* Socket type not supported */
    public const    ENOTSUP:int         = 45;        /* Operation not supported */
    public const    EOPNOTSUPP:int      = ENOTSUP;   /* Operation not supported on socket */
    public const    EPFNOSUPPORT:int    = 46;        /* Protocol family not supported */
    public const    EAFNOSUPPORT:int    = 47;        /* Address family not supported by protocol family */
    public const    EADDRINUSE:int      = 48;        /* Address already in use */
    public const    EADDRNOTAVAIL:int   = 49;        /* Can't assign requested address */	
    
	/* ipc/network software -- operational errors */
    public const    ENETDOWN:int        = 50;        /* Network is down */
    public const    ENETUNREACH:int     = 51;        /* Network is unreachable */
    public const    ENETRESET:int       = 52;        /* Network dropped connection on reset */
    public const    ECONNABORTED:int    = 53;        /* Software caused connection abort */
    public const    ECONNRESET:int      = 54;        /* Connection reset by peer */
    public const    ENOBUFS:int         = 55;        /* No buffer space available */
    public const    EISCONN:int         = 56;        /* Socket is already connected */
    public const    ENOTCONN:int        = 57;        /* Socket is not connected */
    public const    ESHUTDOWN:int       = 58;        /* Can't send after socket shutdown */
    public const    ETOOMANYREFS:int    = 59;        /* Too many references: can't splice */
    public const    ETIMEDOUT:int       = 60;        /* Operation timed out */
    public const    ECONNREFUSED:int    = 61;        /* Connection refused */
    public const    ELOOP:int           = 62;        /* Too many levels of symbolic links */
    public const    ENAMETOOLONG:int    = 63;        /* File name too long */
    public const    EHOSTDOWN:int       = 64;        /* Host is down */
    public const    EHOSTUNREACH:int    = 65;        /* No route to host */
    public const    ENOTEMPTY:int       = 66;        /* Directory not empty */
    
	/* quotas & mush */
    public const    EPROCLIM:int        = 67;        /* Too many processes */
    public const    EUSERS:int          = 68;        /* Too many users */
    public const    EDQUOT:int          = 69;        /* Disc quota exceeded */
    
	/* Network File System */
    public const    ESTALE:int          = 70;        /* Stale NFS file handle */
    public const    EREMOTE:int         = 71;        /* Too many levels of remote in path */
    public const    EBADRPC:int         = 72;        /* RPC struct is bad */
    public const    ERPCMISMATCH:int    = 73;        /* RPC version wrong */
    public const    EPROGUNAVAIL:int    = 74;        /* RPC prog. not avail */
    public const    EPROGMISMATCH:int   = 75;        /* Program version wrong */
    public const    EPROCUNAVAIL:int    = 76;        /* Bad procedure for program */
    public const    ENOLCK:int          = 77;        /* No locks available */
    public const    ENOSYS:int          = 78;        /* Function not implemented */
    public const    EFTYPE:int          = 79;        /* Inappropriate file type or format */
    public const    EAUTH:int           = 80;        /* Authentication error */
    public const    ENEEDAUTH:int       = 81;        /* Need authenticator */
    
	/* Intelligent device errors */
    public const    EPWROFF:int         = 82;        /* Device power is off */
    public const    EDEVERR:int         = 83;        /* Device error, e.g. paper out */
    public const    EOVERFLOW:int       = 84;        /* Value too large to be stored in data type */
    
	/* Program loading errors */
    public const    EBADEXEC:int        = 85;        /* Bad executable */
    public const    EBADARCH:int        = 86;        /* Bad CPU type in executable */
    public const    ESHLIBVERS:int      = 87;        /* Shared library version mismatch */
    public const    EBADMACHO:int       = 88;        /* Malformed Macho file */
    public const    ECANCELED:int       = 89;        /* Operation canceled */
    public const    EIDRM:int           = 90;        /* Identifier removed */
    public const    ENOMSG:int          = 91;        /* No message of desired type */   
    public const    EILSEQ:int          = 92;        /* Illegal byte sequence */
    public const    ENOATTR:int         = 93;        /* Attribute not found */
    public const    EBADMSG:int         = 94;        /* Bad message */
    public const    EMULTIHOP:int       = 95;        /* Reserved */
    public const    ENODATA:int         = 96;        /* No message available on STREAM */
    public const    ENOLINK:int         = 97;        /* Reserved */
    public const    ENOSR:int           = 98;        /* No STREAM resources */
    public const    ENOSTR:int          = 99;        /* Not a STREAM */
    public const    EPROTO:int          =100;        /* Protocol error */
    public const    ETIME:int           =101;        /* STREAM ioctl timeout */
    public const    ELAST:int           =103;        /* Must be equal largest errno */
    
	/* Last error number.
	   
	   info:
	   int errno; //macro
	   http://www.cplusplus.com/reference/clibrary/cerrno/errno.html
	*/
	public native function get errno():int;
	public native function set errno( value:int ):void; //do we really want to write to errno ?
	
	
	}

/* <string.h>
   http://www.opengroup.org/onlinepubs/009695399/basedefs/string.h.html
   http://en.wikipedia.org/wiki/String.h
   
   string operations
   for manipulating several kinds of strings.
*/
package C.string
	{
	
	/* Returns the string representation of an error number.
	   
	   info:
	   char *strerror( int errnum );
	   http://en.wikipedia.org/wiki/Strerror
	*/
	public native function strerror( errnum:int ):String;
	
	
	}

/* <time.h>
   http://www.opengroup.org/onlinepubs/009695399/basedefs/time.h.html
   http://en.wikipedia.org/wiki/Time.h
   
   time types
   functions to get and manipulate date and time information.
   
   note:
   this lib have fery few chances to get implemented
   1. you can use Date Object
   2. you can use getTimer()
   
   but later it could be possible that some of function get implemented
   for ex:
   double difftime ( time_t time2, time_t time1 );
   will become
   difftime( time2:Date, time1:Date ):Number
   difftime( time2:Number, time1:Number ):Number
   
   or another ex:
   size_t strftime ( char * ptr, size_t maxsize, const char * format, const struct tm * timeptr );
   will become
   strftime( format:String, time:Date ):String
   used like strftime( "Now is %I:%M%p.", new Date() ); //Now is 10:21PM.
   
*/
package C.time
	{
	
	/* A number used to convert the value returned by the clock() function into seconds.
	*/
	//public native function get CLOCKS_PER_SEC():Number;
	
	/* Return number of clock ticks since process start.
	    
	   info:
	   clock_t clock(void);
	*/
	//public native function clock():Number;
	
	}



