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

    /* 0. in the futur

       we will make this boot system in such way
       that users can override its logic from a text file

       but before doing that we need a profile class
       and a config class
    */
   
    /* 1. we reset errno to zero

       By default, something somewhere in tamarin define errno=2
       eg. "No such file or directory"
    
       for our API we want errno set as 0 (zero) from the start of the application
       forcing errno=0 here allow to do this
    */
    errno.value = 0;

    /* 2. we setup the onExit() function

       this function basically loop trough the _exitcall array
       and call each one of the functions it may contain

       then this function is defined as the "exit listener"
       and when the redshell is about to terminate normally
       it call this function (only if this function exists)
       just before the actual exiting
       
       if the program terminates abnormally
       the "exit listener" is not called

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
    
    /* 2a. the onExit function is defined as the "exit listener"
    */
    Program.setExitListener( Program.onExit );

    /* 3. we setup the goAsync() function
       
       this function only check if the loop is not null
       and then start the loop
    */
    Runtime.goAsync = function()
    {
        trace( "Runtime.goAsync()" );

        if( Runtime.loop )
        {
            trace( "starts loop" );
            Runtime.loop.start();
        }
        
    }
    
    /* 4. we run the program selfCheck() function
       no we don't
    */
    //Program.selfCheck();
}