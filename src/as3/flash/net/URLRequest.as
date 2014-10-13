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
     * The URLRequest class captures all of the information in a single HTTP request.
     * URLRequest objects are passed to the <code>load()</code> methods of the
     * Loader, URLStream, and URLLoader classes, and to other loading operations,
     * to initiate URL downloads.
     * They are also passed to the <code>upload()</code> and <code>download()</code> methods
     * of the FileReference class.
     * 
     * @langversion 3.0
     * @playerversion Flash 9
     * @playerversion AIR 1.0
     */
    public final class URLRequest
    {
        private static const kInvalidParamError:uint = 2004;

        private var _requestHeaders:Array;
        private var _userAgent:String;

        /**
         * Creates a URLRequest object.
         * If <code>System.useCodePage</code> is <code>true</code>,
         * the request is encoded using the system code page, rather than Unicode.
         * If <code>System.useCodePage</code> is <code>false</code>,
         * the request is encoded using Unicode, rather than the system code page.
         * 
         * @param url The URL to be requested.
         *            You can set the URL later by using the <code>url</code> property.
         *
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         */
        public function URLRequest( url:String = null )
        {
            super();

            if( url != null )
            {
                this.url = url;
            }

            this.requestHeaders = [];

            _userAgent = "Mozilla/5.0 AppleWebKit/531.9 (KHTML, like Gecko) RedTamarin/0.4";
        }

        private function setRequestHeaders( value:Array ):void
        {
            if( value == null )
            {
                value = [];
            }

            _requestHeaders = value;
        }

        private function filterRequestHeaders( item:*, index:int, array:Array ):Boolean
        {
            if( (item instanceof URLRequestHeader) &&
                (item.name.toLowerCase() == "user-agent") )
            {
                this.userAgent = item.value;
                return false;
            }

            return true;
        }

        /**
         * [requestHeaders description]
         * 
         * @return [description]
         */
        public function get requestHeaders():Array
        {
            return _requestHeaders;
        }

        /** @private */
        public function set requestHeaders( value:Array ):void
        {
            if( value != null )
            {
                setRequestHeaders( value.filter( filterRequestHeaders ) );
            }
            else
            {
                setRequestHeaders( value );
            }
        }

        /**
         * Specifies the user-agent string to be used in the HTTP request.
         * 
         *
         * @langversion 3.0
         * @playerversion AIR 1.0
         */
        [API(AVMGLUE::AIR_1_0)]
        public function get userAgent():String
        {
            return _userAgent;
        }

        /** @private */
        [API(AVMGLUE::AIR_1_0)]
        public function set userAgent(value:String):void
        {
            _userAgent = value;
        }
    }

}