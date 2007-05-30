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
 *   zwetan <zwetan@gmail.com>
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


/* Package: standard
   Contains low level access function to the system.
*/
package standard
    {
    
    internal class _std
        {
    
    
        /* Function: errno
            Returns the last system-level error number.
            
            note:
            see also <StandardErrors> for a list of error numbers.
            
            note:
            see <strerror()> to return the error message as string.
         */
        public native static function errno():int;
        
        /* Function: strerror
            Returns a system error message corresponding to the errnum provided.
         */
        public native static function strerror( errnum:int ):String;
        
        /* Function: getcwd
            Get the current working directory.
            
            note:
            standard C arguments removed
            cf: getcwd( char *buffer, int maxlen )
            we don't want to store the path in a buffer
            and we always use MAX_PATH for maxlen
         */
        public native static function getcwd():String;
        
        /* Function: getdcwd
            Get the current working directory of the specified drive.
            
            note:
            as getcwd we don't want the buffer and maxlen properties
            cf: getdcwd( int drive, char *buffer, int maxlen )
            the drive parameter is an int indicating a specific drive
            also see <getdrives()> to obtain all the drives available.
         */
        public native static function getdcwd( drive:int ):String;
        
        /* Function: chdir
            Changes the current working directory.
            
            return -1 fro failure
            return 0 for success
            
            note:
            by default when you run avmplus
            getcwd() will return the current dir of the executable
            but if you use chdir( newpath )
            then getcwd will return that newpath
         */
        public native static function chdir( pathname:String ):int;
        
        /* Function: chdrive
            Changes the current working drive.
            
            return -1 fro failure
            return 0 for success
            
            note:
            newdrive parameter is an int indicating a specific drive
            1=A, 2=B, etc.
            also see <getdrives()> to obtain all the drives available.
         */
        public native static function chdrive( newdrive:int ):int;
        
        /* Function: getdrive
            Returns the current drive id.
            
            note:
            drives id are defined as int, and each int correspond to a letter
            A=1, B=2, C=3, D=4, etc.
            to a maximum of 26 (Z letter).
         */
        public native static function getdrive():int;
        
        /* Function: getdrives
            Returns an array containing all the drives id.
            
            note:
            standard C return changed
            cf: unsigned long getdrives( void );
            even if we want to stay low level as possible
            it's just more practicable to obtain an array of indexes.
            
            note2:
            the array you're obtaining can contain undefined indexes
            ex: [ undefined, undefined, 3, 4 ]
            that means that drive A and B does not exists
            so you would need to strip off all undefined
            to get the only exisitng drives
            cf: [ 3, 4 ]
         */
        public native static function getdrives():Array;
        
        /* Function: sleep
            Suspend the execution of the current thread.
            
            note:
            time parameter is for milliseconds
         */
        public native static function sleep( time:Number ):void;
        
        }
    
    
    public function errno():int
        {
        return _std.errno();
        }
    
    public function strerror( errnum:int ):String
        {
        return _std.strerror( errnum );
        }
    
    public function getcwd():String
        {
        return _std.getcwd();
        }
    
    public function getdcwd( drive:int ):String
        {
        return _std.getdcwd( drive );
        }
    
    public function chdir( pathname:String ):int
        {
        return _std.chdir( pathname );
        }
    
    public function chdrive( newdrive:int ):int
        {
        return _std.chdrive( newdrive );
        }
    
    public function getdrive():int
        {
        return _std.getdrive();
        }
    
    public function getdrives():Array
        {
        return _std.getdrives();
        }
    
    public function sleep( time:Number ):void
        {
        _std.sleep( time );
        }
    
    }




