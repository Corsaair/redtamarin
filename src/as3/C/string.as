/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is [clib - C more or less standard Libraries].
 *
 * The Initial Developer of the Original Code is
 * Zwetan Kjukov <zwetan@gmail.com>.
 * Portions created by the Initial Developer are Copyright (C) 2010
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

package C.string
{
    import C.unistd.*;
    
    /**
     * String operations.
     * @internal
     * 
     * @langversion 3.0
     * @playerversion AVM 0.3
     */
    [native(cls="::avmshell::CStringClass", methods="auto", construct="none")]
    [Inspectable(environment="none")]
    internal class __string
    {
        public native static function strerror( errnum:int ):String;   //char *strerror(int errcode);
        public native static function strlen( str:String ):uint;       //size_t strlen(const char *s);
    }

    /**
     * Accepts an error number argument errnum and returns the corresponding message string.
     * 
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public function strerror( errnum:int ):String
    {
        return __string.strerror( errnum );
    }
    
    /**
     * Find length of string.
     * 
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public function strlen( str:String ):uint
    {
        return __string.strlen( str );
    }

    /**
     * Returns a string describing file modes.
     * 
     * <p><b>note:</b></p>
     * <p><code>void strmode(mode_t mode char *bp);</code></p>
     * <p><code>void strmode(int mode, char *bp); //OSX</code></p>
     * <p>
     * not part of the C standard lib, but part of GNU libc
     * and pretty usefull function so we added it.
     * </p>
     * 
     * @productversion redtamarin 0.3
     * @since 0.3.0
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
                case S_IFREG:
                return "-";
                
                case S_IFDIR:
                return "d";
                
                case S_IFCHR:
                return "c";
                
                case S_IFBLK:
                return "b";
                
                case S_IFLNK:
                return "l";
                
                case S_IFIFO:
                return "p";
                
                case S_IFSOCK:
                return "s";

                default:
                return "?";
            }
        }

        n[0] = ftype( mode );
        n[1] = mode & S_IRUSR ? "r" : "-";
        n[2] = mode & S_IWUSR ? "w" : "-";
        n[3] = mode & S_IXUSR ? "x" : "-";
        n[4] = mode & S_IRGRP ? "r" : "-";
        n[5] = mode & S_IWGRP ? "w" : "-";
        n[6] = mode & S_IXGRP ? "x" : "-";
        n[7] = mode & S_IROTH ? "r" : "-";
        n[8] = mode & S_IWOTH ? "w" : "-";
        n[9] = mode & S_IXOTH ? "x" : "-";
        
        return n.join( "" );
    }
    
    
}
