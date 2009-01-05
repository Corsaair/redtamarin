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
 * The Original Code is [Open Source Virtual Machine.].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2004-2006
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Zwetan Kjukov <zwetan@gmail>.
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

package C.unistd
{
    
    [native(cls="UnistdClass", methods="auto")]
    internal class __unistd
    {
        
        public native static function get F_OK():int;
        public native static function get W_OK():int;
        public native static function get R_OK():int;
        public native static function __access( path:String, mode:int ):int;
        public native static function __chdir( path:String ):int;
        ﻿public native static function __getcwd():String;
        ﻿public native static function __gethostname():String;
        public native static function __sleep( second:uint ):void;﻿
        
    }
    
    /* test for existence of file
    */
    public const F_OK:int = __unistd.F_OK;
    
    /* test for write permission
    */
    public const W_OK:int = __unistd.W_OK;
    
    /* test for read permission
    */
    public const R_OK:int = __unistd.R_OK;
    
﻿   /* Determine accessibility of file.
       
       ref:
       http://msdn.microsoft.com/en-us/library/1w06ktdy(VS.80).aspx
       
       info:
       int access( const char *path, int mode );
       int _access( const char *path, int mode );
    */
    public function access( path:String, mode:int ):int
    {
        return __unistd.__access( path, mode );
    }
    
﻿   /* Change working directory.
       http://www.opengroup.org/onlinepubs/009695399/functions/chdir.html
       
       info:
       int chdir( const char *path );
       int _chdir( const char *path );
    */
    public function chdir( path:String ):int
    {
        return __unistd.__chdir( path );
    }
    
﻿   /* Get the pathname of the current working directory.
       
       info:
       char *getcwd( char *buf, size_t size );
    */
    public function getcwd():String
    {
        return __unistd.__getcwd();
    }
    
    /* Get name of current host
       
       ref:
       http://www.opengroup.org/onlinepubs/000095399/functions/gethostname.html
       http://msdn.microsoft.com/en-us/library/ms738527(VS.85).aspx
       
       info:
       int gethostname(char *name, size_t namelen);
    */
    public function gethostname():String
    {
        return __unistd.__gethostname();
    }
    
﻿   /* Suspend execution for an interval of time.
       http://www.opengroup.org/onlinepubs/000095399/functions/sleep.html
       
       info:
       unsigned sleep(unsigned time);
    */
    public function sleep( second:uint ):void
    {
        __unistd.__sleep( second );
    }
    
}
