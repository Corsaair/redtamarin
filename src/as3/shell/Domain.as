/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


package shell
{

    import flash.utils.ByteArray;
    import shell.FileSystem;

    /**
     * The Domain class is a container for discrete groups of class definitions.
     * 
     * @langversion 3.0
     * @playerversion Flash 9
     * @playerversion AIR 1.0
     */
    [native(cls="DomainClass", gc="exact", instance="DomainObject", methods="auto")]
    public class Domain
    {
        private native function init( base:Domain ):void;

        private var _parentDomain:Domain;

        /**
         * Creates a new domain.
         * 
         * @param base If no parent domain is passed in, this program domain takes the system domain as its parent.
         *
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         */
        public function Domain( base:Domain = null )
        {
            _parentDomain = base;
            init( base );
        }
        
        public function get parentDomain():Domain
        {
            return _parentDomain;
        }

        // If swfVersion is not zero, then load the given ABC with the specific BugCompatibility
        // (overriding the default passed to -swfversion). Note that swfVersion must be a known
        // value, or an exception will be thrown.
        /**
         * [loadBytes description]
         * @param  byteArray  [description]
         * @param  swfVersion [description]
         * @return            [description]
         *
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public native function loadBytes(byteArray:ByteArray, swfVersion:uint = 0);

        /**
         * Gets a class definition from the specified program domain.
         * 
         * @param  className The name of the definition.
         * @return           The class associated with the definition.
         *
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public native function getClass( className:String ):Class;

        /**
         * Gets a public definition from the specified program domain.
         *
         * <p>
         * The definition can be that of a class, a namespace, or a function.
         * </p>
         * 
         * @param  name The name of the definition.
         * @return      The object associated with the definition.
         *
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         */
        public function getDefinition( name:String ):Object
        {
            return getClass( name ) as Object;
        }

        /**
         * Checks to see if a public definition exists within the specified program domain.
         *
         * <p>
         * The definition can be that of a class, a namespace, or a function.
         * </p>
         * 
         * @param  name The name of the definition.
         * @return      A value of <code>true</code> if the specified definition exists;
         *              otherwise, <code>false</code>.
         *
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         */
        public function hasDefinition( name:String ):Boolean
        {
            var obj:Object;

            try
            {
                obj = getDefinition( name );
            }
            catch( e:Error )
            {
                return false;
            }

            if( obj )
            {
                return true;
            }

            return false;
        }

        /**
         * Gets the current program domain in which your code is executing.
         * 
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         */
        public native static function get currentDomain():Domain;

        /**
         * [load description]
         * @param  filename   [description]
         * @param  swfVersion [description]
         * @return            [description]
         */
        public function load( filename:String, swfVersion:uint = 0 )
        {
            //return loadBytes( FileIO.readByteArray( filename ), swfVersion );
            return loadBytes( FileSystem.readByteArray( filename ), swfVersion );
        }
        
        /**
         * Gets the minimum length of a ByteArray required to be used as
         * ApplicationDomain.globalMemory
         *
         * @tiptext
         * @playerversion Flash 10
         * @langversion 3.0
         */
        public native static function get MIN_DOMAIN_MEMORY_LENGTH():uint;

        /**
         * Gets and sets the ByteArray object on which global memory operations
         * will operate within this ApplicationDomain
         *
         * @langversion 3.0
         * @playerversion Flash 10
         * @playerversion AIR 1.5
         */
        public native function get domainMemory():ByteArray;
        
        /** @private */
        public native function set domainMemory( mem:ByteArray );
    }

}
