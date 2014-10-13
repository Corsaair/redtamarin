/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.system
{
    
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
    public final class Security
    {
        private static var _sandboxType:String = APPLICATION;

        /**
         * The file is from an Internet URL and operates under domain-based sandbox rules.
         * 
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         */
        public static const REMOTE:String             = "remote";

        /**
         * The file is a local file, has not been trusted by the user,
         * and it is not a SWF file that was published with a networking designation.
         * In Adobe AIR, the local file is not in the application resource directory;
         * such files are put in the application security sandbox.
         * The file may read from local data sources but may not communicate with the Internet.
         * 
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         */
        public static const LOCAL_WITH_FILE:String    = "localWithFile";

        /**
         * The file is a local file, has not been trusted by the user,
         * and it is a SWF file that was published with a networking designation.
         * The file can communicate with the Internet but cannot read from local data sources.
         * 
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         */
        public static const LOCAL_WITH_NETWORK:String = "localWithNetwork";

        /**
         * The file is a local file and has been trusted by the user,
         * using either the Flash Player Settings Manager
         * or a FlashPlayerTrust configuration file.
         * The file can read from local data sources and communicate with the Internet.
         * 
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         */
        public static const LOCAL_TRUSTED:String      = "localTrusted";

        /**
         * The file is running in an AIR application,
         * and it was installed with the package (the AIR file) for that application.
         * This content is included in the AIR application resource directory
         * (where the application content is installed).
         * 
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         */
        public static const APPLICATION:String        = "application";

        /**
         * Indicates the type of security sandbox in which the calling file is operating.
         *
         * <p>
         * <code>Security.sandboxType</code> has one of the following values:
         *
         * <ul>
         *     <li>
         *     <code>remote</code> (<code>Security.REMOTE</code>) —
         *     This file is from an Internet URL and operates under domain-based sandbox rules.
         *     </li>
         *     <li>
         *     <code>localWithFile</code> (<code>Security.LOCAL_WITH_FILE</code>) —
         *     This file is a local file, has not been trusted by the user,
         *     and it is not a SWF file that was published with a networking designation.
         *     The file may read from local data sources but may not communicate with the Internet.
         *     </li>
         *     <li>
         *     </li>
         *     <li>
         *     </li>
         *     <li>
         *     </li>
         * </ul>
         * </p>
         *
         * <p>
         * For more information related to security,
         * see the Flash Player Developer Center Topic:
         * <a href="http://www.adobe.com/go/devnet_security_en">Security</a>.
         * </p>
         *
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         */
        public static function get sandboxType():String
        {
            return _sandboxType;
        }

        /** @private */
        AVM2 static function set sandboxType( value:String ):void
        {
            _sandboxType = value;
        }

    }

}