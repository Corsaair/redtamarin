/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package shell
{
    import shell.Program;
    import shell.Runtime;
    import shell.FileSystem;
    import C.stdlib.*;

    /**
     * The Cygwin class is an helper to run shell commands under Windows.
     * 
     * <p>
     * Windows shell environment is a special beast,
     * by default it will use the COMSPEC environment variable
     * eg. <code>C:\Windows\system32\cmd.exe</code>.
     * But we decided to rely on a POSIX environment which involve
     * the installation of Cygwin where we get the following
     * SHELL environment variable eg. <code>/bin/bash</code>.
     * As we are executing under Windows, even with Cygwin installed
     * to run a command trough the Bash shell we need to use the
     * Windows path of this SHELL eg. <code>C:\cygwin\bin\bash.exe</code>.
     * </p>
     * 
     * <p>
     * This helper will detect if Cygwin is installed, find out its
     * install directory, and automate the call to the Bash shell.
     * </p>
     * 
     * <p>
     * For special cases when you run Redtamarin as CGI under
     * Internet information Server (IIS) or Apache running on Windows
     * and you want to use "/bin/bash" instead of the default "cmd.exe".
     * </p>
     * 
     * <listing>
     * import shell.Cygwin;
     * 
     * // under CGI you will detect Cygwin
     * // but the shell will not be declared
     * if( Cygwin.isAvailable &#38;&#38; ( Cygwin.shell == "") )
     * {
     *     Cygwin.forceShell( "/bin/bash" );
     *     Cygwin.addToEnvironment();
     * }
     * 
     * // Now you can call bahs shell "as if" you were in an interactive shell
     * var output:String = Cygwin.open( "command -with -args" );
     * 
     * trace( "output:\n" + output );
     * </listing>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4.1
     * @playerversion WIN +
     */
    public class Cygwin
    {
        private static const CYGWIN_REGISTRY:String = "HKLM\\SOFTWARE\\Cygwin";
        private static const CYGWIN_ROOT:String     = CYGWIN_REGISTRY + "\\setup /v rootdir";

        private static var _availability:String = "";
        private static var _isAvailable:Boolean;

        private static var _installDirectory:String = "";

        private static var _shell:String = "";

        private static var _addedToEnvironment:Boolean = false;

        private static function _getAvailability():Boolean
        {
            if( Runtime.platform == "windows" )
            {
                if( _findCygwinInRegistry() )
                {
                    _availability = "true";
                    return true;
                }
            }

            _availability = "false";
            return false;
        }

        /* Note:
           We can use the registry to detect the presenc of Cygwin
           but only from a 64-bit process

           with a 32-bit process the registry call will fail with an error

           see:
           Registry Virtualization
           https://msdn.microsoft.com/en-us/library/windows/desktop/aa965884(v=vs.85).aspx

           Registry Virtualization Scope

            Registry virtualization is enabled only for the following:
            - 32-bit interactive processes.
            - Keys in HKEY_LOCAL_MACHINE\Software.
            - Keys that an administrator can write to.

            Registry virtualization is disabled for the following:
            - 64-bit processes.
            - Processes that are not interactive, such as services.
            etc.

            SO, because of that we need to jump trough hoop to detect Cygwin
            under Windows 32-bit
        */
        private static function _findCygwinInRegistry():Boolean
        {
            if( Runtime.is64bit() )
            {
                return _findCygwinInRegistry64();
            }
            else
            {
                return _findCygwinInRegistry32();
            }
        }

        private static function _findCygwinInRegistry32():Boolean
        {
            /* Note:
               yep stupid way to find Cygwin
               iterates trough all the Windows drives
               and find a directory named "cygwin"
            */
            var drives:Array = FileSystem.drives; // C:,D:
            var path:String;
            var i:uint;
            for( i = 0; i < drives.length; i++ )
            {
                path = drives[i] + "\\cygwin";
                if( FileSystem.exists( path ) )
                {
                    return true;
                }
            }

            return false;
        }

        private static function _findCygwinInRegistry64():Boolean
        {
            var str:String = Program.open( "REG QUERY " + CYGWIN_REGISTRY + " 2>nul" );
                str = str.toLowerCase();

            if( (str == "") || str.indexOf( "error" ) > -1 )
            {
                return false;
            }

            return true;
        }

        private static function _getCygwinInstallDirectory():String
        {
            if( Runtime.is64bit() )
            {
                return _getCygwinInstallDirectory64();
            }
            else
            {
                return _getCygwinInstallDirectory32();
            }
        }

        private static function _getCygwinInstallDirectory32():String
        {
            var drives:Array = FileSystem.drives; // C:,D:
            var path:String;
            var i:uint;
            for( i = 0; i < drives.length; i++ )
            {
                path = drives[i] + "/cygwin";
                if( FileSystem.exists( path ) )
                {
                    return path;
                }
            }

            return "";
        }

        private static function _getCygwinInstallDirectory64():String
        {
            var str:String = Program.open( "REG QUERY " + CYGWIN_ROOT + " 2>nul" );

            if( str != "" )
            {
                var lines:Array = str.split( "\n" );
                var data:String = lines[2];
                    data = data.split( " " ).join( "" ).split( "REG_SZ" )[1];
                return data;        
            }

            return "";
        }

        private static function _getCygwinShell():String
        {
            var SHELL:String = getenv( "SHELL" );
            if( SHELL != "" )
            {
                var cygwin_shell:String = SHELL;
                if( cygwin_shell.indexOf( ".exe" ) == -1 )
                {
                    cygwin_shell += ".exe";
                }

                cygwin_shell = installDirectory + cygwin_shell
                cygwin_shell = FileSystem.normalizePath( cygwin_shell );
                
                return cygwin_shell;
            }
            
            return "";
        }

        /**
         * Returns <code>true</code> if the Operating System is Windows
         * and Cygwin has been detected.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4.1
         */
        public static function get isAvailable():Boolean
        {
            if( _availability != "" ) { return _isAvailable; }

            _isAvailable = _getAvailability();
            return _isAvailable;
        }

        /**
         * Returns Cygwin install directory path
         * or the empty string if Cygwin is not available.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4.1
         */
        public static function get installDirectory():String
        {
            if( isAvailable )
            {
                if( _installDirectory != "" ) { return _installDirectory; }

                _installDirectory = _getCygwinInstallDirectory();
                return _installDirectory;
            }

            return "";
        }

        /**
         * Returns Cygwin shell as a Windows path
         * or the empty string if you are in a non-bash environment
         * or Cygwin is not available.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4.1
         */
        public static function get shell():String
        {
            if( isAvailable )
            {
                if( _shell != "" ) { return _shell; }

                _shell = _getCygwinShell();
                return _shell;
            }

            return "";
        }

        /**
         * Add the Cygwin bin folder to the current PATH environment variable.
         * 
         * <p>
         * The PATH environment variable will be modified only once
         * even if you call this function numerous times.
         * </p>
         * 
         * <p>
         * The change is only available during the current process session.
         * </p>
         * 
         * <p>
         * Allows you to call any cygwin executable from
         * a <code>Program.open()</code> call.
         * </p>
         * 
         * @example Usage
         * <listing>
         * import shell.Cygwin;
         * 
         * Cygwin.addToEnvironment();
         * var output:String = Program.open( "ls -la" );
         * 
         * trace( "output:\n" + output );
         * </listing>
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4.1
         */
        public static function addToEnvironment():void
        {
            if( isAvailable && !_addedToEnvironment )
            {
                var PATH:String = getenv( "PATH" );
                var bin_path:String = installDirectory + "/bin";
                    bin_path = FileSystem.normalizePath( bin_path );
                putenv( "PATH=" + PATH + ";" + bin_path );
                _addedToEnvironment = true;
            }
        }

        /**
         * Force the path of the Cygwin install directory.
         * 
         * <p>
         * Allow to override the auto-detection mecanism.
         * </p>
         * 
         * @example Usage
         * <listing>
         * import shell.Cygwin;
         * 
         * Cygwin.forceInstallDirectory( "E:/cygwin" );
         * </listing>
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4.1
         */
        public static function forceInstallDirectory( path:String ):void
        {
            if( FileSystem.exists( path ) )
            {
                _availability = "true";
                _isAvailable  = true;
                _installDirectory = path;
            }
        }

        /**
         * Force the path of the Cygwin shell.
         * 
         * <p>
         * Allow to override the auto-detection mecanism.
         * </p>
         * 
         * @example Usage
         * <listing>
         * import shell.Cygwin;
         * 
         * Cygwin.forceShell( "/bin/sh" );
         * </listing>
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4.1
         */
        public static function forceShell( path:String ):void
        {
            //setenv( "SHELL", path );
            putenv( "SHELL=" + path );
            _shell = _getCygwinShell();
        }

        /**
         * Executes the specified command line in the context of the Cygwin shell
         * and returns the output.
         * 
         * <p>
         * Similar to <code>Program.open( "bash.exe -c 'command -with -args'" )</code>.
         * For when your execution context does not have a real shell,
         * when your code is launched by a server process for example.
         * </p>
         * 
         * @example Usage
         * <listing>
         * import shell.Cygwin;
         * 
         * var output:String = Cygwin.open( "command -with -args" );
         * 
         * trace( "output:\n" + output );
         * </listing>
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4.1
         */
        public static function open( command:String ):String
        {
            if( isAvailable && (shell != "") )
            {
                var str:String = "";
                    str += shell;
                    str += " -c ";
                    str += "\'" + command + "\'";

                return Program.open( str );
            }

            return "";
        }

    }
}
