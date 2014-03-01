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

    public class Profile
    {
        //Capabilities
        protected var _isEmbeddedInAcrobat:Boolean;
        protected var _hasEmbeddedVideo:Boolean;
        protected var _hasAudio:Boolean;
        protected var _avHardwareDisable:Boolean;
        protected var _hasAccessibility:Boolean;
        protected var _hasAudioEncoder:Boolean;
        protected var _hasMP3:Boolean;
        protected var _hasPrinting:Boolean;
        protected var _hasScreenBroadcast:Boolean;
        protected var _hasScreenPlayback:Boolean;
        protected var _hasStreamingAudio:Boolean;
        protected var _hasStreamingVideo:Boolean;
        protected var _hasVideoEncoder:Boolean;
        protected var _isDebugger:Boolean;
        protected var _localFileReadDisable:Boolean;
        protected var _language:String;
        protected var _languages:Array;
        protected var _manufacturer:String;
        protected var _os:String;
        protected var _cpuArchitecture:String;
        protected var _playerType:String;
        protected var _serverString:String;
        protected var _version:String;
        protected var _screenColor:String;
        protected var _pixelAspectRatio:Number;
        protected var _screenDPI:Number;
        protected var _screenResolutionX:Number;
        protected var _screenResolutionY:Number;
        protected var _touchscreenType:String;
        protected var _hasIME:Boolean;
        protected var _hasTLS:Boolean;
        protected var _maxLevelIDC:String;
        protected var _supports32BitProcesses:Boolean;
        protected var _supports64BitProcesses:Boolean;

        //Features
        public var supportsAccelerometer:Boolean = false;
        public var supportsAccessibility:Boolean = false;
        public var supportsActionScript2:Boolean = false;
        public var supportsCacheAsBitmapMatrix:Boolean = false;
        public var supportsCamera:Boolean = false;
        public var supportsCameraRoll:Boolean = false;
        public var supportsCameraUI:Boolean = false;
        public var supportsContextMenu:Boolean = false;
        public var supportsDatagramSocket:Boolean = false;
        public var supportsDockIcon:Boolean = false;
        public var supportsNativeDrag:Boolean = false;
        public var supportsEncyptedLocalStore:Boolean = false;
        public var supportsExtensionContext:Boolean = false;
        public var supportsDRM:Boolean = false;
        public var supportsGeolocation:Boolean = false;
        public var supportsHTMLLoader:Boolean = false;
        public var supportsIME:Boolean = false;
        public var supportsLocalConnection:Boolean = false;
        public var supportsMicrophone:Boolean = false;
        public var supportsNativeMenu:Boolean = false;
        public var supportsNativeProcess:Boolean = false;
        public var supportsNativeWindow:Boolean = false;
        public var supportsNetworkInfo:Boolean = false;
        public var supportsOpenFilesWithDefaultApplication:Boolean = false;
        public var supportsPrintJob:Boolean = false;
        public var supportsSecureSocket:Boolean = false;
        public var supportsServerSocket:Boolean = false;
        public var supportsShader:Boolean = false;
        public var supportsOrientationChange:Boolean = false;
        public var supportsStageVideo:Boolean = false;
        public var supportsStageWebView:Boolean = false;
        public var supportsStartAtLogin:Boolean = false;
        public var supportsStorageVolumeInfo:Boolean = false;
        public var supportsSystemIdle:Boolean = false;
        public var supportsSystemTrayIcon:Boolean = false;
        public var supportsTextLayoutFrameworkInput:Boolean = false;
        public var supportsUpdater:Boolean = false;
        public var supportsXMLSignatureValidator:Boolean = false;

        //Information
        public var runtimeVersion:String = "0.0.0.0";

        //Security
        public var sandbox:String = "application";

        function Profile()
        {
            super();
            _ctor();
        }

        private function _ctor():void
        {
            _isEmbeddedInAcrobat    = false;
            _hasEmbeddedVideo       = false;
            _hasAudio               = false;
            _avHardwareDisable      = false;
            _hasAccessibility       = false;
            _hasAudioEncoder        = false;
            _hasMP3                 = false;
            _hasPrinting            = false;
            _hasScreenBroadcast     = false;
            _hasScreenPlayback      = false;
            _hasStreamingAudio      = false;
            _hasStreamingVideo      = false;
            _hasVideoEncoder        = false;
            _isDebugger             = false;
            _localFileReadDisable   = false;
            _language               = "";
            _languages              = [];
            _manufacturer           = "";
            _os                     = "";
            _cpuArchitecture        = "";
            _playerType             = "";
            _serverString           = "";
            _version                = "";
            _screenColor            = "";
            _pixelAspectRatio       = 0;
            _screenDPI              = 0;
            _screenResolutionX      = 0;
            _screenResolutionY      = 0;
            _touchscreenType        = "";
            _hasIME                 = false;
            _hasTLS                 = false;
            _maxLevelIDC            = "";
            _supports32BitProcesses = false;
            _supports64BitProcesses = false;
        }

        private function _generateServerString():String
        {
            //TODO
            return "";
        }

        public function get isEmbeddedInAcrobat():Boolean { return _isEmbeddedInAcrobat; }
        public function set isEmbeddedInAcrobat( value:Boolean ):void { _isEmbeddedInAcrobat = value; }

        public function get hasEmbeddedVideo():Boolean { return _hasEmbeddedVideo; }
        public function set hasEmbeddedVideo( value:Boolean ):void { _hasEmbeddedVideo = value; }

        public function get hasAudio():Boolean { return _hasAudio; }
        public function set hasAudio( value:Boolean ):void { _hasAudio = value; }

        public function get avHardwareDisable():Boolean { return _avHardwareDisable; }
        public function set avHardwareDisable( value:Boolean ):void { _avHardwareDisable = value; }

        public function get hasAccessibility():Boolean { return _hasAccessibility; }
        public function set hasAccessibility( value:Boolean ):void { _hasAccessibility = value; }

        public function get hasAudioEncoder():Boolean { return _hasAudioEncoder; }
        public function set hasAudioEncoder( value:Boolean ):void { _hasAudioEncoder = value; }

        public function get hasMP3():Boolean { return _hasMP3; }
        public function set hasMP3( value:Boolean ):void { _hasMP3 = value; }

        public function get hasPrinting():Boolean { return _hasPrinting; }
        public function set hasPrinting( value:Boolean ):void { _hasPrinting = value; }

        public function get hasScreenBroadcast():Boolean { return _hasScreenBroadcast; }
        public function set hasScreenBroadcast( value:Boolean ):void { _hasScreenBroadcast = value; }

        public function get hasScreenPlayback():Boolean { return _hasScreenPlayback; }
        public function set hasScreenPlayback( value:Boolean ):void { _hasScreenPlayback = value; }

        public function get hasStreamingAudio():Boolean { return _hasStreamingAudio; }
        public function set hasStreamingAudio( value:Boolean ):void { _hasStreamingAudio = value; }

        public function get hasStreamingVideo():Boolean { return _hasStreamingVideo; }
        public function set hasStreamingVideo( value:Boolean ):void { _hasStreamingVideo = value; }

        public function get hasVideoEncoder():Boolean { return _hasVideoEncoder; }
        public function set hasVideoEncoder( value:Boolean ):void { _hasVideoEncoder = value; }

        public function get isDebugger():Boolean { return _isDebugger; }
        public function set isDebugger( value:Boolean ):void { _isDebugger = value; }

        public function get localFileReadDisable():Boolean { return _localFileReadDisable; }
        public function set localFileReadDisable( value:Boolean ):void { _localFileReadDisable = value; }

        public function get language():String { return _language; }
        public function set language( value:String ):void { _language = value; }

        public function get languages():Array { return _languages; }
        public function set languages( value:Array ):void { _languages = value; }

        public function get manufacturer():String { return _manufacturer; }
        public function set manufacturer( value:String ):void { _manufacturer = value; }

        public function get os():String { return _os; }
        public function set os( value:String ):void { _os = value; }

        public function get cpuArchitecture():String { return _cpuArchitecture; }
        public function set cpuArchitecture( value:String ):void { _cpuArchitecture = value; }

        public function get playerType():String { return _playerType; }
        public function set playerType( value:String ):void { _playerType = value; }

        public function get serverString():String
        {
            if( _serverString && _serverString != "" ) { return _serverString; }
            return _generateServerString();
        }
        public function set serverString( value:String ):void { _serverString = value; }

        public function get version():String { return _version; }
        public function set version( value:String ):void { _version = value; }

        public function get screenColor():String { return _screenColor; }
        public function set screenColor( value:String ):void { _screenColor = value; }

        public function get pixelAspectRatio():Number { return _pixelAspectRatio; }
        public function set pixelAspectRatio( value:Number ):void { _pixelAspectRatio = value; }

        public function get screenDPI():Number { return _screenDPI; }
        public function set screenDPI( value:Number ):void { _screenDPI = value; }

        public function get screenResolutionX():Number { return _screenResolutionX; }
        public function set screenResolutionX( value:Number ):void { _screenResolutionX = value; }

        public function get screenResolutionY():Number { return _screenResolutionY; }
        public function set screenResolutionY( value:Number ):void { _screenResolutionY = value; }

        public function get touchscreenType():String { return _touchscreenType; }
        public function set touchscreenType( value:String ):void { _touchscreenType = value; }

        public function get hasIME():Boolean { return _hasIME; }
        public function set hasIME( value:Boolean ):void { _hasIME = value; }

        public function get hasTLS():Boolean { return _hasTLS; }
        public function set hasTLS( value:Boolean ):void { _hasTLS = value; }

        public function get maxLevelIDC():String { return _maxLevelIDC; }
        public function set maxLevelIDC( value:String ):void { _maxLevelIDC = value; }

        public function get supports32BitProcesses():Boolean { return _supports32BitProcesses; }
        public function set supports32BitProcesses( value:Boolean ):void { _supports32BitProcesses = value; }

        public function get supports64BitProcesses():Boolean { return _supports64BitProcesses; }
        public function set supports64BitProcesses( value:Boolean ):void { _supports64BitProcesses = value; }
    
    }

}

