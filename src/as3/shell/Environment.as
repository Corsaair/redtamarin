/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package shell
{
    import flash.utils.Proxy;
    import flash.utils.flash_proxy;
    import shell.Program;
    import C.errno.*;
    import C.stdlib.*;

    /**
     * Environment class to access the current environment variables.
     * 
     * @example Usage
     * <listing>
     * import shell.Environment;
     * 
     * var env:Environment = new Environment();
     * 
     * if( "SHELL" in env )
     * {
     *     trace( "found the SHELL env var" );
     *     trace( "SHELL = " + env.SHELL );
     * }
     * </listing>
     * 
     * @playerversion AVM 0.4.1
     * 
     * @langversion 3.0
     * @see shell.Program#environment Program.environment
     * @see http://www.dwheeler.com/secure-programs/Secure-Programs-HOWTO/environment-variables.html Secure Programming HOWTO 5.4. Environment Variables
     */
    public dynamic class Environment extends Proxy
    {
        private var _vars:Array;
        private var _idx:Array;
        private var _env:Object;

        private var _synchronise:Boolean;
        private var _allowEmpty:Boolean;

        /**
         * Create an <code>Environment</code> instance.
         * 
         * <p>
         * You can access a synchronised instance of this class from <code>Program.environment</code>,
         * but you can also use an independant instance to create snapshop of the current environment variables,
         * for example you could delete a bunch of variables before passing an array to a call to <code>execve()</code>.
         * </p>
         * 
         * @param synchronise Synchronise add/delete/update with session environment variables
         * @param allowEmpty  Alllow empty environment variables
         * @param data the data set to scan, if <code>null</code>
         *             will use <code>Program.environ</code>.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4.1
         * 
         * @see C.unistd#execve()
         */
        public function Environment( synchronise:Boolean = false,
                                     allowEmpty:Boolean = false,
                                     data:Array = null )
        {
            super();

            _vars = [];
            _idx  = [];
            _env  = {};

            _synchronise = synchronise;
            _allowEmpty  = allowEmpty;

            refresh();
        }

        private function _parse():void
        {
            var i:uint;
            var len:uint = _vars.length;
            var line:String;
            var pos:int;
            var name:String;
            var value:String;

            for( i=0; i<len; i++ )
            {
                line = _vars[ i ];
                pos  = line.indexOf( "=" );
                name = line.substr( 0, pos );
                value = line.substring( pos+1 );
                
                if( !_allowEmpty &&
                    ((value == "") || (value == null)) )
                {
                    continue;
                }

                _env[ name ] = value;
                _idx[ i ] = name;
            }
        }

        private function _findIndexBy( name:String ):int
        {
            var i:uint;
            var len:uint = _idx.length;
            var index:String;
            for( i = 0; i < len; i++ )
            {
                index = _idx[ i ];
                if( index == name )
                {
                    return i;
                }
            }

            return -1; //not found
        }

        /** @private */
        override flash_proxy function callProperty( methodName:*, ... args ):*
        {
            // we want to ignore any function calls not defined by us
            // void
        }

        /** @private */
        override flash_proxy function deleteProperty( name:* ):Boolean
        {
            if( synchronised )
            {
                /* Note:
                   putenv( name+"=" ) shoudl work too
                   maybe one or the other work better on different OS
                */
                var result:int = setenv( name, "", true );
                if( result < 0 )
                {
                    //trace( "Could not delete session env var `" + name + "`" );
                    //trace( new CError( "", errno ) );
                    return false;
                }
            }

            var deleted:Boolean = delete _env[ name ];
            if( deleted )
            {
                var index:int = _findIndexBy( name );
                if( index > -1 )
                {
                    _idx.splice( index, 1 );
                }
                else
                {
                    //trace( "Could not find index for `" + name + "`" );
                    return false;
                }
            }
            /*else
            {
                trace( "delete failed on `" + name + "`" );
            }*/

            return deleted;
        }

        /** @private */
        override flash_proxy function getProperty( name:* ):*
        {
            return _env[ name ];
        }

        /** @private */
        override flash_proxy function setProperty( name:*, value:* ):void
        {
            // we accept only String type
            if( !(value is String) )
            {
                return;
            }

            // no empty strings
            if( !_allowEmpty &&
                ((value == undefined) || (value == null) || (value == "")) )
            {
                return;
            }

            /* Note:
               the equals char `=` is not allowed
            */
            if( value.indexOf( "=" ) > -1 )
            {
                return;
            }

            if( synchronised )
            {
                var result:int = setenv( name, value, true );
                if( result < 0 )
                {
                    //trace( "Could not set session env var `" + name  + "=" + value + "`" );
                    //trace( new CError( "", errno ) );
                    return;
                }
            }

            if( flash_proxy::hasProperty( name ) )
            {
                _env[ name ] = value;
            }
            else
            {
                _env[ name ] = value;
                _idx[ this.length ] = name;
            }
        }
        
        /** @private */
        override flash_proxy function hasProperty( name:* ):Boolean
        {
            return name in _env;
        }

        /** @private */
        override flash_proxy function nextNameIndex( index:int ):int
        {
            if( index > (_idx.length-1) )
            {
                return 0;
            }

            return index + 1;
        }

        /** @private */
        override flash_proxy function nextName( index:int ):String
        {
            return String( _idx[ index - 1 ] );
        }

        /** @private */
        override flash_proxy function nextValue( index:int ):*
        {
            return String( _env[ _idx[ index - 1 ] ] );
        }

        /**
         * The number of environment variables entries.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4.1
         */
        public function get length():uint
        {
            return _idx.length;
        }

        /**
         * Indicates whether an object has a specified property defined.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4.1
         */
        public function hasOwnProperty( name:String ):Boolean
        {
            /* Note:
               could be handled in callProperty()
               but faster to execute when defined here
            */
            return this.AS3::hasOwnProperty( name );
        }

        /**
         * Indicates whether the specified property exists and is enumerable.
         * If <code>true</code>, then the property exists and can be enumerated
         * in a <code>for..in</code> loop.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4.1
         */
        public function propertyIsEnumerable( name:String ):Boolean
        {
            /* Note:
               this.AS3::propertyIsEnumerable( name );
               return false as we don't really have real properties inside a Proxy
               but we consider that if we detect the property then it is enumerable,
               and in fact it is for..in enumerable
            */
            return this.AS3::hasOwnProperty( name );
        }

        /**
         * Returns <code>true</code> if the environment variables
         * are synchronised with the system environment variables.
         * 
         * <p>
         * The synchronisation occurs on add, delete and update of the variables.
         * </p>
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4.1
         */
        public function get synchronised():Boolean
        {
            return _synchronise;
        }

        /**
         * Scan the current session environment variables
         * or the <code>data</code> set, if provided..
         * 
         * @param data the data set to scan, if <code>null</code>
         *             will use <code>Program.environ</code>.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4.1
         * 
         * @see shell.Program#environ Program.environ
         */
        public function refresh( data:Array = null ):void
        {
            /* Note:
               by default we inherit the system env vars
            */
            if( data == null )
            {
                data = Program.environ;
            }

            // clean up
            _vars.length = 0;
            _idx.length = 0;
            _env = null;

            // reset
            _vars = data;
            _idx  = [];
            _env  = {};

            // populate
            if( data.length > 0 )
            {
                _parse();
            }
        }

        /**
         * Export the environment variables as an
         * <code>Array</code> data structure.
         * 
         * <p>
         * Format is <code>[ "NAME=value", ... ]</code>.
         * </p>
         * 
	     * @example Pass modified environment variables to another process
	     * <listing>
	     * import C.unistd.&#42;;
	     * 
	     * // we obtain a snapshot of our current env vars
	     * var env:Environment = new Environment();
	     * 
	     * // we delete what we don't need
	     * delete env.USER;
	     * delete env.LOGNAME;
	     * delete env.HOME;
	     * delete env.SHELL;
	     * 
	     * // we can also add new ones
	     * env.GATEWAY_INTERFACE = "CGI/1.1";
	     * env.HTTP_HOST = "www.as3lang.org";
	     * // etc.
	     * 
	     * // then we pass those env vars to a new process
	     * execve( "someprogram", [ "-arg1", "-arg2" ], env.toArray() );
	     * 
	     * </listing>
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4.1
         * 
         * @see C.unistd#execve()
         */
        public function toArray():Array
        {
            /* Note:
               we need to return an array of the form
               [ "HOME=/usr/home", "LOGNAME=home", etc. ]
            */

            var a:Array = [];
            var m:String;
            var value:String;
            for( m in _env )
            {
                value = _env[ m ];

                if( !_allowEmpty &&
                    ((value == "") || (value == null)) )
                {
                    continue;
                }

                a.push( m + "=" + value );
            }

            return a;
        }

        /**
         * Export the environment variables as an
         * <code>Object</code> data structure.
         * 
         * <p>
         * Format is <code>{ NAME: "value", ... }</code>.
         * </p>
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4.1
         */
        public function toObject():Object
        {
            var o:Object = {};
            var m:String;
            var value:String;
            for( m in _env )
            {
                value = _env[ m ];

                if( !_allowEmpty &&
                    ((value == "") || (value == null)) )
                {
                    continue;
                }

                o[ m ] = value;
            }

            return o;
        }
    }
}
