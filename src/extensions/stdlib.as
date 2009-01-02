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

package C.stdlib
{
    [native(cls="StdlibClass", methods="auto")]
    internal class __stdlib
    {
        
        public native static function get EXIT_SUCCESS():int;
        public native static function get EXIT_FAILURE():int;
        public native static function __rand():int;
        public native static function __abort():void;
        public native static function __exit( status:int = 0 ):void;
        public native static function __getenv( name:String ):String;
        public native static function __setenv( name:String, value:String, rewrite:int = 0 ):int;
        public native static function __system( command:String ):int;
        
    }
    
    /* Success termination code.
    */
    public const EXIT_SUCCESS:int = __stdlib.EXIT_SUCCESS;
    
    /* Failure termination code.
    */
    public const EXIT_FAILURE:int = __stdlib.EXIT_FAILURE;
    
    /* Generate a pseudo-random value.
       
       info:
       int rand( void );
    */
    public function rand():int
    {
        return __stdlib.__rand();
    }
    
    /* Abort current process.
       
       info:
       void abort ( void );
       
       note:
       will crash the shell with "62400 Abort trap"
    */
    public function abort():void
    {
        __stdlib.__abort();
    }
    
    /* Terminate program execution.
       
       info:
       void exit( int status );
       http://en.wikipedia.org/wiki/Exit_(operating_system)
    */
    public function exit( status:int = 0 ):void
    {
        __stdlib.__exit( status );
    }
    
    /* Retrieve an environment variable.
       
       note:
       return an empty string if env var not found
       
       info:
       char *getenv( const char *name );
    */
    public function getenv( name:String ):String
    {
        return __stdlib.__getenv( name );
    }
    
    /* Set an environment variable.
       
       note:
       If the variable already exists in the environment
       and rewrite is set, it is overwritten. 
       
       info:
       int setenv( const char *name, const char *value, int rewrite );
    */
    public function setenv( name:String, value:String, rewrite:int = 0 ):int
    {
        return __stdlib.__setenv( name, value, rewrite );
    }
    
    /* Execute an external command.
       
       info:
       int system( const char *command );
       http://en.wikipedia.org/wiki/System_(C_Standard_Library)
    */
    public function system( command:String ):int
    {
        return __stdlib.__system( command );
    }
    
}
