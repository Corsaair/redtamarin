
import avmplus.System;
import flash.system.Capabilities;
import standard.*;

trace( "----" );

trace( Capabilities.playerType +" v"+ System.getRedTamarinVersion() );

trace( getcwd() );

trace( chdir( "C:\\temp" ) );

var err = chdir( "C:\\not_defined_directory" );
trace( "err: " + err );
trace( "errno: " + errno() );
trace( "strerror: " + strerror( errno() ) );


trace( getcwd() );

trace( getdrives() );

trace( "current drive: " + getdrive() );

trace( chdrive( 4 ) );

trace( "current drive: " + getdrive() );

trace( getcwd() );

trace( getdcwd( 3 ) );

trace( "----" );

var s = getTimer();
sleep( 100 );
var e = getTimer();
trace( "Slept " + (e-s) + "ms" );

trace( "----" );



