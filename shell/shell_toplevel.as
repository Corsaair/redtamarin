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
 * The Original Code is [Open Source Virtual Machine.].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2004-2006
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Adobe AS3 Team
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

package
{

    import avmplus.System;
    import avmplus.Domain;
    import C.errno.*;

    /* note:
       this function is essential for when we run code with
       
        - running scripts
          ./redshell file.as
       
        - read-eval-print mode
          ./redshell -repl

        - eval() call from within the API
          System.eval( source )

       in all those cases you can not use the `import` statement
       for fully qualified name
       import avmplus.System; //will not work

       but you can use the `import` statement for non qualified name
       import avmplus.*; //will work

       also you can call functions declared at the anonymous package level
       (that's why you can call getClassByName() without the need of an import)


       to invoke classes defined in builtin.abc and toplevel.abc
       or any other *.abc loaded in memory for that matter
       
       in the shell you can use this workaround
       var sys:* = getClassByName( "avmplus.System" );
       trace( sys.argv );

       this workaround will aork also when you have an ambiguity in the class name
       (eg. 2 classes with the same name in a different package that you want to import)
       var sys:*  = getClassByName( "avmplus.System" );
       var fsys:* = getClassByName( "flash.system.System" );
    */
    public function getClassByName( name:String, domain:Domain = null ):Class
    {
        if( !domain )
        {
            domain = Domain.currentDomain;
        }
        
        return domain.getClass( name ) ;
    }
    
    // nonstandard extensions to ECMAScript
    public function print( ...s )
    {
        System.trace( s )
    }

    // nonstandard Flash Player extensions
    public function trace( ...s )
    {
        System.trace( s )
    }
    
    public function readLine():String
    {
        return System.readLine();
    }

    /* note:
       From this point we are in the static code block execution
       and so the code is called as soon as the class is loaded.

       Here the trick is that we are in the anonymous package,
       so this particular static code block is executed before anything else.
    */
    
    /* note:
       By default, something somewhere in tamarin define errno=2
       eg. "No such file or directory"

       for our API we want errno set as 0 (zero) from the start of the application
       here forcing errno=0 in the unnamed package allow to do this
    */
    errno = 0;
}



