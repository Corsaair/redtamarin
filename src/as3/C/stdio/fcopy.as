package C.stdio
{

    import C.stdio.*; // FILE, fopen, fclose, fread, fwrite

    import flash.utils.*; // ByteArray

    /**
     * Copy file of any size using stdio functions.
     * 
     * <p>
     * This is a non-standard extension to POSIX.
     * </p>
     * 
     * <p>
     * If you copy a file using <code>fseek()</code> and <code>ftell()</code>
     * you cannot handle files bigger than <code>2 GB</code>,
     * or <code>2147483647 bytes</code> or
     * <code>MAX_INT</code> or <code>int.MAX_VALUE</code>.
     * </p>
     * 
     * <p>
     * Another way would be to add <b>Large File Support</b> (LFS)
     * using functions like <code>fseeko()</code> and <code>ftello()</code>
     * but you would still not be able to copy files bigger than <code>4 GB</code>.
     * </p>
     * 
     * @example Usage
     * <listing>
     * /&#42; Generating big files under Linux
     *     $ fallocate -l 100M test100MB
     *     $ fallocate -l 10G test10GB
     * &#42;/
     * /&#42; Generating big files under Mac OS X
     *     $ mkfile -n 100m test100MB
     *     $ mkfile -n 10g test10GB
     * &#42;/
     * trace( "start copying ..." );
     * var t0:uint = getTimer();
     * var total:Number = fcopy( "test10GB", "copy10GB", 8192 * 100 );
     * var t1:uint = getTimer();
     * trace( "copied " + total + " bytes in " + (t1-t0) + "ms" );
     * </listing>
     * 
     * @param origin the filepath to copy from.
     * @param destination the filepath to copy to.
     * @param buffer how mnay bytes to copy per cycle (default is 8192, eg. BUFSIZ)
     * @return Upon successful completion, <code>fcopy()</code> should return the number of bytes copied.
     * Otherwise, if a copy error occurs, the return value should be less than zero, and errno shall be set to indicate the error.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4.1
     * 
     * @see C.stdio#fread
     * @see C.stdio#fwrite
     * @see http://stackoverflow.com/questions/10195343/copy-a-file-in-an-sane-safe-and-efficient-way Copy a file in an sane, safe and efficient way
     * @see http://www.gnu.org/software/libc/manual/html_node/Controlling-Buffering.html BUFSIZ
     * @see http://en.wikipedia.org/wiki/Large_file_support Large File Support
     */
    public function fcopy( origin:String, destination:String, buffer:uint = 8192 ):Number
    {
        // open for reading
        var source:FILE = fopen( origin, "rb" );
        if( !source )
        {
            return -1;
        }

        // open for writing
        var dest:FILE = fopen( destination, "wb" );
        if( !dest )
        {
            fclose( source );
            return -1;
        }

        var b:ByteArray = new ByteArray();
        var size:int;
        var wrote:int;
        var total:Number = 0;

        // loop as long as fread() does not returns zero
        // if returns zero that means EOF reached
        // if returns less than zero that means an error occured
        while( size = fread( b, int(buffer), source ) )
        {
            wrote = fwrite( b, b.length, dest );
            if( wrote < 0 )
            {
                fclose( source );
                fclose( dest );
                return wrote;
            }

            total += wrote;
            b.clear();
        }

        fclose( source );
        fclose( dest );

        if( size < 0 )
        {
            return size;
        }

        return total;
    }
}