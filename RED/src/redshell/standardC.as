package C
	{
	
	/* Combine all the native call to the C standard library
	   
	   assert.h, ctype.h, errno.h, float.h, limits.h, locale.h,
	   math.h, setjmp.h, signal.h, stdarg.h, stddef.h, 
	   stdio.h, stdlib.h, string.h, time.h
	   
	   the goal is:
	   import C.stdlib.*; //equivalent to #include <stdlib.h>
	   var home:String = getenv( "HOME" );
	   
	   ref:
	   http://en.wikipedia.org/wiki/ANSI_C
	   http://en.wikipedia.org/wiki/Category:C_standard_library
	   http://www.cplusplus.com/reference/clibrary/
	*/
	public class standard
		{
		/* <stdlib.h>
		*/
		
		//atof
		//atoi
		//atol
		//strtod
		//strtol
		//strtoul
		
		/* int rand( void ); */
		//public native static function rand():int;
		
		//srand
		//malloc
		//calloc
		//realloc
		//free
		//abort
		//atexit
		
		/* void exit( int status );
		   http://en.wikipedia.org/wiki/Exit_(operating_system)
		*/
		public native static function exit( status:int ):void;
		
		/* char *getenv( const char *name ); */
		public native static function getenv( name:String ):String;		
		
		/* int system ( const char *command );
		   http://en.wikipedia.org/wiki/System_(C_Standard_Library)
		*/
		public native static function system( command:String ):int;
		
		//bsearch
		//qsort
		//abs
		//labs
		//div
		//ldiv
		
		//-----------------------------------------------------------
		
		/* <stdio.h>
		*/
		
		//-----------------------------------------------------------
		
		//etc.
		
		}
	
	}

/* http://en.wikipedia.org/wiki/Stdlib.h
   
   stdlib.h is the header of the general purpose standard library
   of C programming language which includes functions involving memory allocation,
   process control, conversions and others.
   
   It is compatible with C++ and is known as cstdlib in C++.
   The name "stdlib" stands for standard library.
*/
package C.stdlib
	{
	import C.standard;
	
	/* Type Conversion */
	
	//atof
	//atoi
	//atol
	//strtod
	//strtol
	//strtoul
	
	//-----------------------------------------------------------
	
	/* Pseudo-random sequence generation */
	
	//rand
	public native function rand():int;
	
	//srand
	
	//-----------------------------------------------------------
	
	/* Memory allocation and deallocation */
	
	//malloc
	//calloc
	//realloc
	//free
	
	//-----------------------------------------------------------
	
	/* Process control */
	
	//abort
	//atexit
	
	/* Terminate program execution.
	*/
	public function exit( status:int ):void
		{
		standard.exit( status );
		}
	
	/* Retrieve an environment variable.
	   
	   note:
	   return an empty string if env var not found
	*/
	public function getenv( name:String ):String
		{
		return standard.getenv( name );
		}
	
	/* Execute an external command.
	*/
	public function system( command:String ):int
		{
		return standard.system( command );
		}
	
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

