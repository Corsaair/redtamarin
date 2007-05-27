
import avmplus.File;


/* description:
   File.exists() should return true or false
   but not null
*/
result = File.exists( "unknown.txt" );

if( result == false )
   {
   trace( "passed" );
   }
else
   {
   trace( "failed" );
   }

