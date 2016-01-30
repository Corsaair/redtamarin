package C.unistd
{
    import C.stdlib.*;   // getenv, exit, EXIT_SUCCESS, EXIT_FAILURE
    import C.unistd.*;   // access, X_OK, getlogin
    import C.sys.stat.*; // stat, status, S_ISREG, S_IXUSR, S_IXGRP, S_IXOTH
    
    /**
     * Locate a program file in the user's path.
     * 
     * <p>
     * This is a non-standard extension to POSIX.
     * </p>
     * 
     * <p>
     * The <b>which</b> utility takes a command name and searches the path
     * for each executable file that would be run had this
     * command actually been invoked.
     * </p>
     * 
     * @example Usage
     * <listing>
     * trace( "which bash = " + which( "bash" ) ); //output: which bash = /bin/bash
     * trace( "which svn = " + which( "svn", true ) ); //output: which svn = /opt/local/bin/svn /usr/bin/svn
     * </listing>
     * 
     * @param name program name to look for.
     * @param all if <code>true</code> list all instances of executables found.
     * @return the full path of the program or the empty string if not found.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4.1
     * @playerversion POSIX +
     * 
     * @see C.stdlib#getenv getenv()
     * @see http://stackoverflow.com/questions/592620/check-if-a-program-exists-from-a-bash-script Check if a program exists from a bash script
     * @see http://www.opensource.apple.com/source/shell_cmds/shell_cmds-170/which/which.c which.c (OpenSource Apple)
     */
    public function which( name:String, all:Boolean = false ):String
    {
        var PATH:String = getenv( "PATH" );
        if( PATH == "" ) { return ""; }

        /* Note:
           usual paths are

           /opt/local/bin
           /opt/local/sbin
           /usr/local/bin
           /usr/bin
           /bin
           /usr/sbin
           /sbin
        */
        var paths:Array = PATH.split( ":" );
            paths.push( "." );

        var is_there:Function = function( candidate:String ):Boolean
        {
            var fin:* = new status();
            /* Note:
               getlogin() != "root"
               should be
               getuid() != 0
            */
            if( (access( candidate, X_OK ) == 0) &&
                (stat( candidate, fin ) == 0) &&
                S_ISREG( fin.st_mode ) &&
                ( (getlogin() != "root") || 
                  ((fin.st_mode & (S_IXUSR | S_IXGRP | S_IXOTH)) != 0) ) )
            {
                return true;
            }

            return false;
        }

        var found:String = "";

        var i:uint;
        var len:uint = paths.length;
        var candidate:String;
        for( i = 0; i < len; i++ )
        {
            candidate = paths[i] + "/" + name;
            if( is_there( candidate ) )
            {
                if( all )
                {
                    found += (found == "" ? "": " ") + candidate;
                }
                else
                {
                    return candidate;
                }
            }
        }
        
        return found;
    }

}