/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package shell
{
    import C.errno.*;
    import C.stdlib.*;
    //import shell.async.CoreEventLoop;

    /* IMPORTANT:
       this is the redtamarin boot system,
       it's where we configure the shell main entry point.

       some of those access are protected under the AVM2 namespace
    */
    use namespace AVM2;
   
    /* note:
       By default, something somewhere in tamarin define errno=2
       eg. "No such file or directory"
    
       for our API we want errno set as 0 (zero) from the start of the application
       forcing errno=0 here allow to do this
    */
    //set errno to zero
    errno.value = 0;

    /* note:
       Here we define the logic to find the current operating system
       command shell or command interpreter

       This allow in some case to use the shell as a fallback
       if a native command fail or is missing
    */
    Program.findShell = function():String
    {
        var sh:String = "";

        /*switch( OperatingSystem.vendor )
        {
            case "Microsoft":
            sh = getenv( "COMSPEC" );
            break;

            case "Apple":
            case "Linux":
            default:
            sh = getenv( "SHELL" );
        }*/

        //sh = getenv( "SHELL" ); //temp

        switch( Runtime.platform )
        {
            case "windows":
            sh = getenv( "COMSPEC" );
            break;

            case "macintosh":
            sh = getenv( "SHELL" );
            break;

            case "linux":
            sh = getenv( "SHELL" );
            break;
        }
        
        return sh;
    }

    /* note:
       Causes the specified function to be called when the program terminates normally.
       At least 32 functions can be registered to be called when the program terminates.
       They are called in a last-in, first-out basis (the last function registered is called first).
    */
    Program.onExit = function()
    {
        var f:Function;
        while( Program._exitcall.length > 0 )
        {
            f = Program._exitcall.pop();
            f();
        }

        Program.setExitListener( null );
    }
    
    Program.setExitListener( Program.onExit );

    Runtime.goAsync = function()
    {
        trace( "Runtime.goAsync()" );

        if( Runtime.loop )
        {
            trace( "starts loop" );
            Runtime.loop.start();
        }
        
    }
    
    Program.selfCheck();        
}