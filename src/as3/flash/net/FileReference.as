/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.net
{
    import shell.FileSystem;

    import flash.utils.ByteArray;

    use namespace AVM2;

    /**
     * The FileReference class provides a means to upload and download files
     * between a user's computer and a server.
     * An operating-system dialog box prompts the user to select a file to upload
     * or a location for download.
     * Each FileReference object refers to a single file on the user's disk
     * and has properties that contain information about the file's size, type,
     * name, creation date, modification date, and creator type (Macintosh only).
     * 
     * @langversion 3.0
     * @playerversion Flash 9
     * @playerversion AIR 1.0
     */
    [native(cls="::avmshell::FileReferenceClass", instance="::avmshell::FileReferenceObject", methods="auto")]
    public class FileReference
    {
        
        /**
         * Native dummy function.
         *
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public native static function isDummy():Boolean;

        /**
         * Native dummy function.
         *
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public native function isLocalDummy():Boolean;
        
        private static const kInvalidParamError:uint  = 2004;
        private static const kNullPointerError:uint   = 2007;
        private static const kInvalidCallError:uint   = 2037;
        private static const kLocalSecurityError:uint = 2028;

        private var _fileref:String;
        private var _data:ByteArray;
        private var _populated:Boolean;
        private var _opened:Boolean;

        /**
         * Creates a new FileReference object.
         * When populated, a FileReference object represents a file on the user's local disk.
         *
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         */
        public function FileReference()
        {
            super();

            _reset();
        }

        private function _reset():void
        {
            _fileref   = null;
            _data      = null;
            _populated = false;
            _opened    = false;
        }

        /**
         * [creationDate description]
         * @return [description]
         */
        public function get creationDate():Date
        {
            return null;
        }

        /**
         * [creationDate description]
         * @return [description]
         */
        public function get creator():String
        {
            retrun "";
        }

        /**
         * [creationDate description]
         * @return [description]
         */
        public function get modificationDate():Date
        {
            return null;
        }

        /**
         * [creationDate description]
         * @return [description]
         */
        public function get name():String
        {
            /* NOTE:
               Error: Error #2037: Functions called in incorrect sequence,
               or earlier call was unsuccessful.
               at flash.net::FileReference/get name()
            */
           
            if( !_populated )
            {
                Error.throwError( IllegalOperationError, kInvalidCallError );
            }

            if( _fileref )
            {
                return FileSystem.getBasenameFromPath( _fileref );
            }

            return null;
        }

        /**
         * [creationDate description]
         * @return [description]
         */
        public function get size():Number
        {
            return 0;
        }

        /**
         * [creationDate description]
         * @return [description]
         */
        public function get type():String
        {
            return "";
        }

        /**
         * [creationDate description]
         * @return [description]
         */
        public function get data():ByteArray
        {
            if( !_populated )
            {
                Error.throwError( IllegalOperationError, kInvalidCallError );
            }

        }

        /**
         * The filename extension.
         *
         * <p>
         * A file's extension is the part of the name following (and not including) the final dot (".").
         * If there is no dot in the filename, the extension is <code>null</code>.
         * </p>
         *
         * <p>
         * <b>Note:</b> 
         * You should use the <code>extension</code> property to determine a file's type;
         * do not use the <code>creator</code> or <code>type</code> properties.
         * You should consider the <code>creator</code> and <code>type</code> properties
         * to be considered deprecated. They apply to older versions of Mac OS.
         * </p>
         *
         * @throws IllegalOperationError If the reference is not initialized.
         * 
         * @langversion 3.0
         * @playerversion AIR 1.0
         */
        [API(AVMGLUE::AIR_1_0)]
        public function get extension():String
        {

            var n:String = name;
            if( !n )
            {
                return null;
            }

            var pos:int = n.lastIndexOf( "." );
            if( pos < 0 )
            {
                return null;
            }

            return n.substr( pos + 1 );
        }

        /**
         * [browse description]
         * @param  typeFilter [description]
         * @return            [description]
         *
         * @langversion 3.0
         * @playerversion AIR 1.0
         */
        public function browse( typeFilter:Array = null ):Boolean
        {
            return false;
        }

        /**
         * [browseOverride description]
         * @param  filename [description]
         * @return          [description]
         *
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        AVM2 function browseOverride( filename:String ):Boolean
        {
            if( !filename )
            {
              Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
            }

            var exists:Boolean = FileSystem.exists( filename );

            if( exists )
            {
                _fileref   = filename;
                _populated = true;
            }

            return exists;
        }

        private function _load( dest:ByteArray ):void
        {
            if( !_populated )
            {
                Error.throwError( IllegalOperationError, kInvalidCallError );
            }

            _data = dest;

            //should be async
            if( _fileref )
            {
                var bytes:ByteArray = FileSystem.readByteArray( _fileref );

                _data.writeBytes( bytes );
                _data.position = 0;
            }
        }

        public function load():void
        {
            _load( new ByteArray() );
        }

        private function _save( data:ByteArray, defaultFileName:String ):void
        {
            if( !data )
            {
              Error.throwError( ArgumentError, Errors.kNullArgumentError, "data" );
            }

            if( !defaultFileName )
            {
              Error.throwError( ArgumentError, Errors.kNullArgumentError, "defaultFileName" );
            }

            if( _fileref )
            {
                var written:Boolean = FileSystem.writeByteArray( _fileref, data )  
            }
            
        }

        public function save( data:*, defaultFileName:String = null ):void
        {
            if( data == null )
            {
                throw new ArgumentError( "data" );
            }

            var d:ByteArray = new ByteArray();

            if( data is String )
            {
                d.writeUTFBytes( data as String );
            }
            else if( data is XML )
            {
                d.writeUTFBytes( (data as XML).toXMLString() );
            }
            else if( data is ByteArray )
            {
                d.writeBytes( data as ByteArray );
            }
            else
            {
                try
                {
                    d.writeUTFBytes( data );
                }
                catch( e:Error )
                {
                    throw new ArgumentError( "data" );
                }
            }

            d.position = 0;

            if( defaultFileName == null )
            {
                defaultFileName = "";
            }

            _save( d, defaultFileName );
        }

        AVM2 function saveOverride( filename:String, data:* ):void
        {
            if( !filename )
            {
              Error.throwError( ArgumentError, Errors.kNullArgumentError, "filename" );
            }

            var exists:Boolean = FileSystem.exists( filename );

            if( exists )
            {
                _fileref   = filename;
                _populated = true;
            }
            else
            {
                var created:Boolean = FileSystem.createByteArray( filename );
                if( created )
                {
                    _fileref   = filename;
                    _populated = true;
                }
            }

            save( data );
        }


        public function uploadUnencoded( request:URLRequest ):void
        {
            Error.throwError( VerifyError, Errors.kNotImplementedError, "uploadUnencoded" );
        }

    }

}
