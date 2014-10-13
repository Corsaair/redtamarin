/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.net
{
    import flash.system.Security;

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
    [API(AVMGLUE::AIR_1_0)]
    public class URLRequestDefaults
    {
        private static const kApplicationFeatureSecurityError:uint = 3205;

        private static var _followRedirects:Boolean = true;
        private static var _manageCookies:Boolean   = true;
        private static var _authenticate:Boolean    = true;
        private static var _useCache:Boolean        = true;
        private static var _cacheResponse:Boolean   = true;
        private static var _idleTimeout:Number      = 0;
        private static var _userAgent:String        = null;
        private static var _loginCredentials        = initLoginCredentials();
        private static var _defaultUserAgent:String = initUA();

        private static function initLoginCredentials():Object
        {
            return {};
        }

        private static function initUA():String
        {
            /* NOTE:
               user-agent for AIR 2.6
               Mozilla/5.0 (Macintosh; U; Intel Mac OS X; en) AppleWebKit/531.9 (KHTML, like Gecko) AdobeAIR/2.6
            */
           return "Mozilla/5.0 AppleWebKit/531.9 (KHTML, like Gecko) RedTamarin/0.4";
        }

        public static function setLoginCredentialsForHost( hostname:String,
                                                           user:String,
                                                           password:String ):void
        {
            _loginCredentials[ hostname ] = { user:user, pw:password };
        }

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
         * @playerversion AIR 1.0
         */
        [API(AVMGLUE::AIR_1_0)]
        public static function get followRedirects():Boolean
        {
            if( Security.sandboxType != Security.APPLICATION )
            {
                Error.throwError( SecurityError, kApplicationFeatureSecurityError );
            }

            return _followRedirects;
        }

        /** @private */
        [API(AVMGLUE::AIR_1_0)]
        public static function set followRedirects( value:Boolean ):void
        {
            if( Security.sandboxType != Security.APPLICATION )
            {
                Error.throwError( SecurityError, kApplicationFeatureSecurityError );
            }

            _followRedirects = value;
        }

        /**
         * The default setting for the <code>idleTimeout</code> property of
         * URLRequest objects and HTMLLoader objects.
         *
         * @langversion 3.0
         * @playerversion AIR 2.0
         */
        [API(AVMGLUE::AIR_2_0)]
        public static function get idleTimeout():Number
        {
            if( Security.sandboxType != Security.APPLICATION )
            {
                Error.throwError( SecurityError, kApplicationFeatureSecurityError );
            }

            return _idleTimeout;
        }

        /** @private */
        [API(AVMGLUE::AIR_2_0)]
        public static function set idleTimeout( value:Number ):void
        {
            if( Security.sandboxType != Security.APPLICATION )
            {
                Error.throwError( SecurityError, kApplicationFeatureSecurityError );
            }
            
            if( value < 0 )
            {
                Error.throwError( RangeError, 2006 );
            }

            _idleTimeout = value;
        }

    }

}