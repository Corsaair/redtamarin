/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is [Open Source Virtual Machine.].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2004-2006
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Zwetan Kjukov <zwetan@gmail.com>.
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

package avmplus.profiles
{

    /* note:
       for each AIR profiles: DesktopProfile, ExtendedDesktopProfile, MobileDeviceProfile, TVPprofile, ExtendedTVProfile
       override the following based on AIR applications Device profiles
       http://help.adobe.com/en_US/air/build/WS144092a96ffef7cc16ddeea2126bb46b82f-8000.html

        private function _ctor():void
        {
            supportsAccelerometer
            supportsAccessibility
            supportsActionScript2
            supportsCacheAsBitmapMatrix
            supportsCamera
            supportsCameraRoll
            supportsCameraUI
            supportsContextMenu
            supportsDatagramSocket
            supportsDockIcon
            supportsNativeDrag
            supportsEncyptedLocalStore
            supportsExtensionContext
            supportsDRM
            supportsGeolocation
            supportsHTMLLoader
            supportsIME
            supportsLocalConnection
            supportsMicrophone
            supportsNativeMenu
            supportsNativeProcess
            supportsNativeWindow
            supportsNetworkInfo
            supportsOpenFilesWithDefaultApplication
            supportsPrintJob
            supportsSecureSocket
            supportsServerSocket
            supportsShader
            supportsOrientationChange
            supportsStageVideo
            supportsStageWebView
            supportsStartAtLogin
            supportsStorageVolumeInfo
            supportsSystemIdle
            supportsSystemTrayIcon
            supportsTextLayoutFrameworkInput
            supportsUpdater
            supportsXMLSignatureValidator
        }
    
    */

    import avmplus.OperatingSystem;

    public class AIRProfile extends FlashPlayerProfile
    {
        function AIRProfile()
        {
            super();
            _ctor();
        }

        private function _ctor():void
        {
            runtimeVersion = "2.0.0.0";
            sandbox        = "application";

            var version:String;
            switch( OperatingSystem.vendor )
            {
                case "Apple":
                version += "MAC";
                break;

                case "Microsoft":
                version += "WIN";
                break;

                case "Linux":
                version += "LNX";
                break;

                default:
                version += OperatingSystem.vendor.toUpperCase().substr( 0, 3);
            }
            version += " " + runtimeVersion.split( "." ).join( "," );
            _version = version;
        }
    }
}

