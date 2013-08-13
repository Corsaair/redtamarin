/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/**
* stdio.h - standard buffered input/output
* 
* @langversion 3.0
* @playerversion AVM 0.4
* 
* @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/stdio.h.html
*/
package C.stdio2
{

    /**
     * Rename a file.
     *
     * <p>
     * The <code>rename()</code> function shall change the name of a file.
     * </p>
     * 
     * <p>
     * If the <code>rename()</code> function fails for any reason other than <code>EIO</code>,
     * any file named by <code>newname</code> shall be unaffected.
     * </p>
     *
     * @example usage
     * <listing>
     * import C.errno.&#42;;
     * import C.stdio2.&#42;;
     * 
     * var result:int = rename2( "/test/heelo.txt", "/test/world.txt" );
     * 
     * if( result &lt; 0 )
     * {
     *     trace( new CError( errno ) );
     * }
     * </listing>
     * 
     * @param oldname The pathname of the file to be renamed.
     * @param newname The new pathname of the file.
     * @return Upon successful completion, the <code>rename()</code> function shall return <code>0</code>.
     * Otherwise, it shall return <code>-1</code>, <code>errno</code> shall be set to indicate the error,
     * and neither the file named by <code>oldname</code> nor the file named by <code>newname</code> shall be changed or created.
     * 
     * @throws CError EACCES
     * @throws CError EBUSY
     * @throws CError EEXIST or ENOTEMPTY
     * @throws CError EINVAL
     * @throws CError EIO
     * @throws CError etc.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     * 
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/rename.html
     * @see C.errno
     */
    [native("::avmshell::CStdioClass::rename2")]
    public native function rename2( oldname:String, newname:String ):int;

}
