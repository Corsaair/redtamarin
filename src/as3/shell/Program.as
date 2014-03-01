/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package shell
{
    import C.stdlib.*;
    import C.unistd.*;
    import C.errno.*;
    import flash.utils.ByteArray;

    use namespace AVM2;

    /**
     * The Program class represents the currently running application.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native(cls="::avmshell::ProgramClass", classgc="exact", methods="auto", construct="none")]
    public class Program
    {

        /** @private */
        AVM2 static var _shell:String;

        /** @private */
        AVM2 static var _exitcall:Array = [];

        /** @private */
        private native static function _getArgv():Array;

        /** @private */
        private native static function _getEnviron():Array;

        /** @private */
        private native static function _getProgramFilename():String;

        /** @private */
        private native static function _setExitListener( f:Function ):void;

        /** @private */
        private native static function _popenRead( command:String ):String;



        /**
         * Contains the arguments passed to the program.
         *
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public static const argv:Array = _getArgv();

        /**
         * Returns the program filename.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public static const filename:String = _getProgramFilename();

        /**
         * The original directory when the application started.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public static const startupDirectory:String = getcwd();

        /**
         * Amount of real memory we've aqcuired from the OS.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public native static function get totalMemory():Number;

        /**
         * Part of totalMemory we aren't using.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public native static function get freeMemory():Number;

        /**
         * Process wide size of resident private memory.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public native static function get privateMemory():Number;

        /**
         * Get a list of all environment variables value-pair accessible by the program.
         *
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public static function get environ():Array
        {
            return _getEnviron();
        }
        
        /**
         * Returns the current process id.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public static function get pid():int
        {
            return getpid();
        }

        /**
         * Returns the default shell.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public static function get shell():String
        {
            if( _shell ) { return _shell; }

            _shell = findShell();
            return _shell;
        }

        /**
         * Allows to get or set the current working directory of the application.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public static function get workingDirectory():String
        {
            return getcwd();
        }

        /** @private */
        public static function set workingDirectory( value:String ):void
        {
            //TODO: deal with errors etc.
            chdir( value );
        }

        /**
         * Add a function to run when the AVM terminate.
         *
         * <p>
         * TODO at normal program termination.
         * </p>
         * 
         * @param f The function to execute.
         *
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        AVM2 static function atExit( f:Function ):void
        {
            _exitcall.push( f );
        }

        /**
         * Store the function to execute when the AVM terminate.
         *
         * <p>
         * TODO
         * </p>
         * 
         * @param f The function to execute.
         *
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        AVM2 static function setExitListener( f:Function ):void
        {
            _setExitListener( f );
        }

        /**
         * Allows to define a custom shell
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        AVM2 static function setShell( path:String ):void
        {
            _shell = path;
        }

        /**
         * The function to execute by default when the AVM terminate.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        AVM2 static var onExit:Function = null;

        AVM2 static var findShell:Function = null;
        
        /**
         * TODO
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        AVM2 static function selfCheck():Boolean
        {
            var check:Boolean = false;
            var message:String = "";

            if( errno.value != 0 )
            {
                message += "errno is not zero from the start of the application" + "\n";
                message += "errno = " + errno.valueOf() + " - " + errno.toString() + "\n";
            }

            if( !Program.findShell )
            {
                message += "Program.findShell not defined" + "\n";
                message += "command shell fallback will not work" + "\n";
            }

            if( !Program.onExit )
            {
                message += "Program.onExit not defined" + "\n";
                message += "atexit() and onExit() calls will not work" + "\n";
            }

            if( !Runtime.loop )
            {
                message += "Runtime.loop not defined" + "\n";
                message += "EventLoop will not work" + "\n";
            }

            if( !Runtime.goAsync )
            {
                message += "Runtime.goAsync not defined" + "\n";
                message += "async mode and events will not work" + "\n";
            }

            if( message == "" )
            {
                check = true;
            }
            else
            {
                message  = "Check:\n" + message;
                message += "boot complete";
                trace( message );    
            }

            return check;
        }

        /**
         * Abort the program execution.
         *
         * <p>
         * This is an abnormal program exit, atexit functions will not run.
         * </p>
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public native static function abort():void;

        /**
         * Executes the specified command line and returns the status code.
         *
         * @example Usage
         * <listing>
         * import shell.Program;
         * 
         * var exitcode:int = Program.exec( "command -with -args" );
         * 
         * trace( "exit code: " + exitcode );
         * </listing>
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public native static function exec( command:String ):int;

        /**
         * Terminates the program execution.
         *
         * <p>
         * Will exits the VM with the Operating System code
         * specified by <code>status</code>.
         * </p>
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public native static function exit( status:int = -1 ):void;

        /**
         * Executes the specified command line and returns the output.
         *
         * @example Usage
         * <listing>
         * import shell.Program;
         * 
         * var output:String = Program.open( "command -with -args" );
         * 
         * trace( "output:\n" + output );
         * </listing>
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public static function open( command:String ):String
        {
            return _popenRead( command );
        }

        /**
        * Do nothing in this process for some time.
        *
        * @param ms  A timeout value in milliseconds. Negative values are taken to be zero.
        *
         * @langversion 3.0
         * @playerversion AVM 0.4
        */
        public native static function sleep( ms:int ):void;

        /**
         * Returns the number of nano seconds that have elapsed
         * since the AMV+ started.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public native static function getNanosecondTimer():Number;

        /**
         * Returns the number of milliseconds that have elapsed
         * since the AMV+ started.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public native static function getTimer():uint;



        /**
         * Waits and returns all the characters entered by the user.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public native static function readLine():String;

        /**
         * Writes a string to the command line.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public native static function write( s:String ):void;

        /**
         * Writes a string to the command line and returns to the line.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public static function writeLine( s:String ):void
        {
            Program.write( s + "\n" );
        }

        /**
         * Writes arguments to the command line and returns to the line.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public native static function trace( a:Array ):void;



        // Initiate a garbage collection; future versions will not return before completed.
        /**
         * Initiate a garbage collection
         * (future versions will not return before completed).
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public native static function forceFullCollection():void;

        // Queue a garbage collection request.
        /**
         * Queue a garbage collection request.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public native static function queueCollection():void;

        /**
         * Suggest to the garbage collector that if collector's imminence
         * exceeds imminence parameter then the collector should finish
         * the incremental collection cycle.  Doing so may incur a pause.
         *
         * @param imminence  A number between 0 and 1 where 0 means less imminent and 1 means most imminent
         *
         * @note The API is provided to allow the program to help the GC schedule GC pauses, thereby
         * working around a weakness in the garbage collector: though the GC is incremental, there is
         * still the chance of longer-than-desired pauses in some situations.  Scheduling those pauses
         * at points where the user won't notice or won't care (program phase transitions, say)
         * makes for a smoother user experience.
         *
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public static native function pauseForGCIfCollectionImminent( imminence:Number = 0.75 ):void;

        /**
         * Makes the specified XML object immediately available for garbage collection.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public native static function disposeXML( xml:XML ):void;

    }

}
