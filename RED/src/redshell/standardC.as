package C
	{
	/* <stdlib.h>
	   http://en.wikipedia.org/wiki/Stdlib.h
	   
	   stdlib.h is the header of the general purpose standard library
	   of C programming language which includes functions involving memory allocation,
	   process control, conversions and others.
	   
	   It is compatible with C++ and is known as cstdlib in C++.
	   The name "stdlib" stands for standard library.
	*/
	
	public class stdlib
		{
		
		/* Retrieve an environment variable.
		   info:
		   char *getenv(const char *name);
		*/
		public native static function getenv( name:String ):String;		
		
		}
	
	public function getenv( name:String ):String
		{
		return stdlib.getenv( name );
		}
	
	}
