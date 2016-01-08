/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.system
{
    
    use namespace AVM2;

    /**
     * The Security class lets you specify how content in different domains can communicate with each other.
     * 
     * @langversion 3.0
     * @playerversion Flash 9
     * @playerversion AIR 1.0
     */
    public final class Security
    {

        private static var _exactSettings:Boolean = true;
        private static var _pageDomain:String     = "http://localhost";
        private static var _sandboxType:String    = APPLICATION;

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
         * Determines how Flash Player or AIR chooses the domain to use for certain
         * content settings, including settings for camera and microphone permissions,
         * storage quotas, and storage of persistent shared objects.
         * To have the SWF file use the same settings that were used in Flash Player 6,
         * set <code>exactSettings</code> to <code>false</code>.
         * 
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         */
        public static function get exactSettings():Boolean
        {
            return _exactSettings;
        }

        /** @private */
        public static function set exactSettings( value:Boolean ):void
        {
            _exactSettings = value;
        }

        /**
         * The domain portion of the HTML page containing the swf.
         * 
         * @langversion 3.0
         * @playerversion Flash 10.3
         * @playerversion AIR 2.7
         */
        [API(AVMGLUE::FP_10_2,AVMGLUE::AIR_2_7)]
        public static function get pageDomain():String
        {
            /* Note:
               should use FP_10_3 but not defined?
               so instead use FP_10_2
            */
            return _pageDomain;
        }

        /** @private */
        AVM2 static function set pageDomain( value:String ):void
        {
            _pageDomain = value;
        }

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
         *     <code>localWithNetwork</code> (<code>Security.LOCAL_WITH_NETWORK</code>) —
         *     This SWF file is a local file, has not been trusted by the user, and was published
         *     with a networking designation. The SWF file can communicate with the Internet
         *     but cannot read from local data sources.
         *     </li>
         *     <li>
         *     <code>localTrusted</code> (<code>Security.LOCAL_TRUSTED</code>) —
         *     This file is a local file and has been trusted by the user, using either the
         *     Flash Player Settings Manager or a FlashPlayerTrust configuration file.
         *     The file can read from local data sources and communicate with the Internet.
         *     </li>
         *     <li>
         *     <code>application</code> (<code>Security.APPLICATION</code>) —
         *     This file is running in an AIR application, and it was installed with the package (AIR file)
         *     for that application. By default, files in the AIR application sandbox can cross-script
         *     any file from any domain (although files outside the AIR application sandbox may not
         *     be permitted to cross-script the AIR file).
         *     By default, files in the AIR application sandbox can load content and data from any domain.
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

        /**
         * Lets SWF files in the identified domains access objects and variables
         * in the SWF file that contains the <code>allowDomain()</code> call.
         * 
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         */
        public static function allowDomain( ... domains ):void
        {
            //not implemented
        }

        /**
         * Lets SWF files and HTML files in the identified domains access
         * objects and variables in the calling SWF file, which is hosted
         * by means of the HTTPS protocol.
         * 
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         */
        public static function allowInsecureDomain( ... domains ):void
        {
            //not implemented
        }

        /**
         * Looks for a policy file at the location specified by the
         * <code>url</code> parameter.
         * 
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         */
        public static function loadPolicyFile( url:String ):void
        {
            //not implemented
        }

        /**
         * Displays the Security Settings panel in Flash Player.
         * This method does not apply to content in Adobe AIR;
         * calling it in an AIR application has no effect.
         * 
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         */
        public static function showSettings( panel:String = "default" ):void
        {
            //not implemented
        }

    }

}