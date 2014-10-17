/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package
{

    import shell.Domain;
    
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
    /**
     * Gets a class definition by name.
     * 
     * @param  name   The name of the definition.
     * @param  domain If no domain is passed, the function use the current domain.
     * @return        The class reference of the definition.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function getClassByName( name:String, domain:Domain = null ):Class
    {
        if( !domain )
        {
            domain = Domain.currentDomain;
        }

        return domain.getClass( name );
    }
	
}
