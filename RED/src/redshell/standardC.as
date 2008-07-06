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
	
	//abort
	//atexit
	
	/* Terminate program execution.
	   
	   info:
	   void exit( int status );
	   http://en.wikipedia.org/wiki/Exit_(operating_system)
	*/
	public native function exit( status:int ):void;
	
	/* Retrieve an environment variable.
	   
	   note:
	   return an empty string if env var not found
	   
	   info:
	   char *getenv( const char *name );
	*/
	public native function getenv( name:String ):String;
	
	/* Execute an external command.
	   
	   info:
	   int system ( const char *command );
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

