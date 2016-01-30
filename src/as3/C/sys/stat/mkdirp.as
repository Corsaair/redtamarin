package C.sys.stat
{

    import C.errno.*;
    import C.sys.stat.*; // mkdir
    import C.unistd.*;   // access, F_OK

    /**
     * Create a new directory and intermediate directories as required.
     * 
     * <p>
     * This is a non-standard extension to POSIX.
     * </p>
     * 
     * <p>
     * Replicates the command line behaviour <code>mkdir -p</code> which
     * allow to create a directory tree.
     * </p>
     * 
     * @example Usage
     * <listing>
     *  /&#42; Create the following directory tree
     *  .
     *  └── hello
     *      └── the
     *          └── big
     *              └── world
     *  &#42;/
     * var result:int = mkdirp( "hello/the/big/world/" );
     * trace( "result = " + result );
     * if( result != 0 )
     * {
     *     trace( new CError( "", errno ) );
     * }
     * </listing>
     * 
     * @param path The pathname of the directory tree to be created.
     * @param mode The file permission bits (optional).
     * @return Upon successful completion, this function shall return <code>0</code>.
     * Otherwise, this function shall return <code>-1</code> and set <code>errno</code>
     * to indicate the error.
     * If <code>-1</code> is returned, last directory in the path shall not be created.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4.1
     * @playerversion POSIX +
     * 
     * @see C.sys.stat#mkdir mkdir()
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/utilities/mkdir.html The mkdir utility
     * @see http://www.unix.com/man-page/opensolaris/3gen/mkdirp/ man page for mkdirp (Open Solaris)
     */
    public function mkdirp( path:String, mode:int = -1 ):int
    {
        // special case
        if( (path == ".") || (path == "/") )
        {
            return 0;
        }

        if( mode == -1 )
        {
            mode = S_IRWXU | S_IRWXG | S_IRWXO;
        }

        // remove trailing slash
        if( path.charAt( path.length - 1 ) == "/" )
        {
            path = path.substr( 0, path.length - 1 );
        }

        var start:String = "";
        // remove head slash if exists
        if( path.charAt( 0 ) == "/" )
        {
            path  = path.substr( 1 );
            start = "/";
        }

        // split path into components
        var paths:Array;
        if( path.indexOf( "/" ) > -1 )
        {
            paths = path.split( "/" );
        }
        else
        {
            paths = [ path ];
        }

        // remember the head slash
        paths[0] = start + paths[0];

        // iterates trough the path components
        // check if the directory exists, if not create it
        var last:String = "";
        var result:int;
        while( paths.length > 0 )
        {
            // accumulate path components
            last += paths.shift();

            // does the dir exists ?
            if( access( last, F_OK ) != 0 )
            {
                // create the directory
                result = mkdir( last, mode );
                if( result != 0 )
                {
                    return result;
                }
            }
            last += "/"; // append dir separator for next component
        }

        return 0;
    }
    
}
