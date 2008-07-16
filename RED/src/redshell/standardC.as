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
	
	//atexit
	
	/* Terminate program execution.
	   
	   info:
	   void exit( int status );
	   http://en.wikipedia.org/wiki/Exit_(operating_system)
	*/
	public native function exit( status:int = 0 ):void;
	
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
	
	/* Get the pathname of the current working directory.
	   
	   info:
	   char *getcwd( char *buf, size_t size );
	*/
	public native function getcwd():String;
	
	
	}

/* <errno.h>
   http://www.opengroup.org/onlinepubs/000095399/basedefs/errno.h.html
   http://en.wikipedia.org/wiki/Errno.h
   
   system error numbers
*/
package C.errno
	{
	
	/* note:
	   maybe not usefull, could be removed
	*/
	public const	EPERM:int   =  1		/* Operation not permitted */
	public const	ENOENT:int  =  2		/* No such file or directory */
	public const	ESRCH:int   =  3		/* No such process */
	public const	EINTR:int   =  4		/* Interrupted system call */
	public const	EIO:int     =  5		/* Input/output error */
	public const	ENXIO:int   =  6		/* Device not configured */
	public const	E2BIG:int   =  7		/* Argument list too long */
	public const	ENOEXEC:int =  8		/* Exec format error */
	public const	EBADF:int   =  9		/* Bad file descriptor */
	public const	ECHILD:int  = 10		/* No child processes */
	public const	EDEADLK:int = 11		/* Resource deadlock avoided */
	public const	ENOMEM:int  = 12		/* Cannot allocate memory */
	public const	EACCES:int  = 13		/* Permission denied */
	public const	EFAULT:int  = 14		/* Bad address */
	public const	ENOTBLK:int = 15		/* Block device required */
	public const	EBUSY:int   = 16		/* Device / Resource busy */
	public const	EEXIST:int  = 17		/* File exists */
	public const	EXDEV:int   = 18		/* Cross-device link */
	public const	ENODEV:int  = 19		/* Operation not supported by device */
	public const	ENOTDIR:int = 20		/* Not a directory */
	public const	EISDIR:int  = 21		/* Is a directory */
	public const	EINVAL:int  = 22		/* Invalid argument */
	public const	ENFILE:int  = 23		/* Too many open files in system */
	public const	EMFILE:int  = 24		/* Too many open files */
	public const	ENOTTY:int  = 25		/* Inappropriate ioctl for device */
	public const	ETXTBSY:int = 26		/* Text file busy */
	public const	EFBIG:int   = 27		/* File too large */
	public const	ENOSPC:int  = 28		/* No space left on device */
	public const	ESPIPE:int  = 29		/* Illegal seek */
	public const	EROFS:int   = 30		/* Read-only file system */
	public const	EMLINK:int  = 31		/* Too many links */
	public const	EPIPE:int   = 32		/* Broken pipe */
	
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


