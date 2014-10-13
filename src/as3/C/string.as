/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package C.string
{
    import C.sys.stat.*;
    
    /**
     * @name <code>&lt;string.h&gt;</code>
     * String operations.
     *
     * <p>
     * Defines string handling functions.
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/string.h.html string.h
     */

    //memccpy()
    //memchr()
    //memcmp()
    //memcpy()
    //memmove()
    //memset()
    //stpcpy()
    //stpncpy()

    /**
     * Concatenate two or more strings.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function strcat( s1:String, ...s ):String
    {
        return s1.concat.apply( s1, s );
    }

    /**
     * String scanning operation.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function strchr( s:String, c:int ):int
    {
        return s.indexOf( String.fromCharCode(c) );
    }

    /**
     * Compare two strings.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CStringClass::strcmp")]
    public native function strcmp( s1:String, s2:String ):int;

    /**
     * String comparison using collating information.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CStringClass::strcoll")]
    public native function strcoll( s1:String, s2:String ):int;

    //strcoll_l()
    //strcpy()
    //strcspn()
    //strdup()

    /**
     * Accepts an error number argument errnum and returns the corresponding message string.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CStringClass::strerror")]
    public native function strerror( errnum:int ):String;

    //strerror_l()
    //strerror_r()
    
    /**
     * Find length of string.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    //[native("::avmshell::CStringClass::strlen")]
    //public native function strlen( str:String ):uint;
    public function strlen( str:String ):uint
    {
        return str.length;
    }

    /**
     * Returns a string describing file modes.
     * 
     * <p>
     * <b>Note: </b>
     * not part of the C standard lib, but part of GNU libc.
     * Non-standard but we added it.
     * </p>
     *
     * @example Usage
     * <listing>
     * var info:status = new status();
     * var result:int = stat( "test.bin", info );
     * 
     * trace( "mode = " + strmode( info.st_mode );
     * 
     * // will output
     * // mode = -rwxr-xr-x
     * </listing>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function strmode( mode:int ):String
    {
        var n:Array = new Array(10);

        /* Return a character indicating the type of file described by
           file mode BITS:
           '-' regular file
           'b' block special file
           'c' character special file
           'd' directory
           'l' symbolic link
           'n' network special file (HP-UX)
           'p' fifo (named pipe)
           's' socket
           '?' some other file type
        */
        var ftype:Function = function( bits:int ):String
        {
            switch (bits & S_IFMT)
            {
                case S_IFREG: /* regular */
                return "-";
                
                case S_IFDIR: /* directory */
                return "d";
                
                case S_IFCHR: /* character special */
                return "c";
                
                case S_IFBLK: /* block special */
                return "b";
                
                case S_IFLNK: /* symbolic link */
                return "l";
                
                case S_IFIFO: /* fifo */
                return "p";
                
                case S_IFSOCK: /* socket */
                return "s";

                default: /* unknown */
                return "?";
            }
        }

        n[0] = ftype( mode );

        /* user */
        n[1] = mode & S_IRUSR ? "r" : "-";
        n[2] = mode & S_IWUSR ? "w" : "-";
        //n[3] = mode & S_IXUSR ? "x" : "-";
        switch( mode & (S_IXUSR | S_ISUID) )
        {
            case 0:
            n[3] = "-";
            break;

            case S_IXUSR:
            n[3] = "x";
            break;

            case S_ISUID:
            n[3] = "S";
            break;

            case S_IXUSR | S_ISUID:
            n[3] = "s";
            break;
        }
        
        /* group */
        n[4] = mode & S_IRGRP ? "r" : "-";
        n[5] = mode & S_IWGRP ? "w" : "-";
        //n[6] = mode & S_IXGRP ? "x" : "-";
        switch( mode & (S_IXGRP | S_ISGID) )
        {
            case 0:
            n[6] = "-";
            break;

            case S_IXGRP:
            n[6] = "x";
            break;

            case S_ISGID:
            n[6] = "S";
            break;

            case S_IXGRP | S_ISGID:
            n[6] = "s";
            break;
        }
        
        /* other */
        n[7] = mode & S_IROTH ? "r" : "-";
        n[8] = mode & S_IWOTH ? "w" : "-";
        //n[9] = mode & S_IXOTH ? "x" : "-";
        switch( mode & (S_IXOTH | S_ISVTX) )
        {
            case 0:
            n[9] = "-";
            break;

            case S_IXOTH:
            n[9] = "x";
            break;

            case S_ISVTX:
            n[9] = "T";
            break;

            case S_IXOTH | S_ISVTX:
            n[9] = "t";
            break;
        }
        
        return n.join( "" );
    }
    
    /**
     * Concatenate a string with part of another.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function strncat( s1:String, s2:String = "", n:uint = 0 ):String
    {
        return s1 + s2.substr( 0, n );
    }

    /**
     * Compare part of two strings.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function strncmp( s1:String, s2:String = "", n:uint = 0 ):int
    {
        return strcmp( s1.substr( 0, n ), s2.substr( 0, n ) );
    }

    //strncpy()
    //strndup()
    //strnlen()

    /**
     * Returns an octal string describing file modes.
     *
     * <p>
     * <b>Note: </b>
     * not part of the C standard lib.
     * Non-standard but we added it.
     * </p>
     *
     * @example Usage
     * <listing>
     * // get the current umask
     * var mask:int = getumask(); //022
     * 
     * trace( " " + stroctal( ACCESSPERMS ) );
     * trace( "-" + stroctal( mask ) );
     * trace( " ---" );
     * trace( " " + stroctal( ACCESSPERMS &#38; ~mask ) );
     * 
     * // will output
     * //  777
     * // -022
     * //  ---
     * //  755
     * </listing>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function stroctal( mode:int ):String
    {
        //to octal string
        var m:String = mode.toString( 8 );

        //if length bigger than 3, take the last 3 chars
        if( m.length > 3 ) { m = m.substr(m.length-3, 3); }

        //prepend 0 till length smaller than 3
        while( m.length < 3 )
        {
            m = "0" + m;
        }

        return m;
    }

    /**
     * Scan a string for a byte.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function strpbrk( s1:String, s2:String ):Array
    {
        var pos:Array = [];
        var i:uint;
        var c:String;

        for( i=0; i<s1.length; i++ )
        {
            c = s1.charAt(i);
            if( s2.indexOf( c ) > -1 )
            {
                pos.push( i );
            }
        }

        return pos;
    }

    /**
     * String scanning operation.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function strrchr( s:String, c:int ):int
    {
        return s.lastIndexOf( String.fromCharCode(c) );
    }

    //strsignal()
    //strsigno()
    
    /**
     * Get length of a substring.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CStringClass::strspn")]
    public native function strspn( s1:String, s2:String ):int;

    /**
     * Find a substring.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function strstr( s1:String, s2:String ):int
    {
        return s1.indexOf( s2 );
    }

    /**
     * Split string into tokens.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function strtok( s1:String, s2:String = "" ):Array
    {
        return s1.split( s2 );
    }

    //strtok_r()
    //strxfrm()
    //strxfrm_l()

}
