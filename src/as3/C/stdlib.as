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

package C.stdlib
{
    
    /**
     * Standard library definitions.
     * @internal
     * 
     * @langversion 3.0
     * @playerversion AVM 0.3
     */
    [native(cls="::avmshell::CStdlibClass", methods="auto", construct="none")]
    [Inspectable(environment="none")]
    internal class __stdlib
    {
        public native static function get EXIT_SUCCESS():int;
        public native static function get EXIT_FAILURE():int;

        public native static function abort():void;                    //void abort(void);
        public native static function exit( status:int = 0 ):void;     //void exit(int status);
        public native static function getenv( name:String ):String;    //char *getenv(const char *name);
        public native static function setenv( name:String, value:String, overwrite:int ):int; //int setenv(const char *name, const char *value, int overwrite);
        public native static function unsetenv( name:String ):int;     //int unsetenv(const char *name);
        public native static function realpath( path:String ):String;  //char *realpath(char const *path, char *resolvedPath);
        public native static function __system( command:String ):int;  //int system(const char *s);
    }
    
    /** Success termination code.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const EXIT_SUCCESS:int = __stdlib.EXIT_SUCCESS;

    /** Failure termination code.
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public const EXIT_FAILURE:int = __stdlib.EXIT_FAILURE;
    
    /**
     * Cause abnormal program termination.
     * 
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public function abort():void
    {
        __stdlib.abort();
    }
    
    /**
     * Terminate program execution.
     * 
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public function exit( status:int = -1 ):void
    {
        if( status == -1 ) { status = EXIT_SUCCESS; }
        __stdlib.exit( status );
    }

    /**
     * Retrieve an environment variable.
     * 
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public function getenv( name:String ):String
    {
        return __stdlib.getenv( name );
    }

    /**
     * Add or change an environment variable.
     * 
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public function setenv( name:String, value:String, overwrite:Boolean = false ):int
    {
        var writeover:int = 0;
        if( overwrite ) { writeover = 1; }
        
        return __stdlib.setenv( name, value, writeover );
    }

    /**
     * Remove an environment variable.
     * 
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public function unsetenv( name:String ):int
    {
        return __stdlib.unsetenv( name );
    }

    /**
     * Resolve a pathname.
     * 
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public function realpath( path:String ):String
    {
        return __stdlib.realpath( path );
    }

    /**
     * Issue a command.
     * 
     * @productversion redtamarin 0.3
     * @since 0.3.0
     */
    public function system( command:String ):int
    {
        return __stdlib.__system( command );
    }
    
    
}
