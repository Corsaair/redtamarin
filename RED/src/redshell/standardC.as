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
		
		/* char *getenv(const char *name); */
		public native static function getenv( name:String ):String;		
		
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
	
	/* Retrieve an environment variable.
	*/
	public function getenv( name:String ):String
		{
		return standard.getenv( name );
		}
	
	}

