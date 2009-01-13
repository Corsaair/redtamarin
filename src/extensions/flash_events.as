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
 *   Zwetan Kjukov <zwetan@gmail>.
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

package flash.events
{
    
    public class Event
    {
        public static const ACTIVATE:String = "activate";
        public static const ADDED:String = "added";
        public static const ADDED_TO_STAGE:String = "addedToStage";
        public static const CANCEL:String = "cancel";
        public static const CHANGE:String = "change";
        public static const CLEAR:String = "clear";
        public static const CLOSE:String = "close";
        public static const CLOSING:String = "closing"; //AIR
        public static const COMPLETE:String = "complete";
        public static const CONNECT:String = "connect";
        public static const COPY:String = "copy";
        public static const CUT:String = "cut";
        public static const DEACTIVATE:String = "deactivate";
        public static const DISPLAYING:String = "displaying";
        public static const ENTER_FRAME:String = "enterFrame";
        public static const EXIT_FRAME:String = "exitFrame";
        public static const EXITING:String = "exiting"; //AIR
        public static const FRAME_CONSTRUCTED:String = "frameConstructed";
        public static const FULLSCREEN:String = "fullScreen";
        public static const HTML_BOUNDS_CHANGE:String = "htmlBoundsChange"; //AIR
        public static const HTML_DOM_INITIALIZE:String = "htmlDOMInitialize"; //AIR
        public static const HTML_RENDER:String = "htmlRender"; //AIR
        public static const ID3:String = "id3";
        public static const INIT:String = "init";
        public static const LOCATION_CHANGE:String = "locationChange"; //AIR
        public static const MOUSE_LEAVE:String = "mouseLeave";
        public static const NETWORK_CHANGE:String = "networkChange"; //AIR
        public static const OPEN:String = "open";
        public static const PASTE:String = "paste";
        public static const REMOVED:String = "removed";
        public static const REMOVED_FROM_STAGE:String = "removedFromStage";
        public static const RENDER:String = "render";
        public static const RESIZE:String = "resize";
        public static const SAMPLE_DATA:String = "sampleData";
        public static const SCROLL:String = "scroll";
        public static const SELECT:String = "select";
        public static const SELECT_ALL:String = "selectAll";
        public static const SOUND_COMPLETE:String = "soundComplete";
        public static const TAB_CHILDREN_CHANGE:String = "tabChildrenChange";
        public static const TAB_ENABLED_CHANGE:String = "tabEnabledChange";
        public static const TAB_INDEX_CHANGE:String = "tabIndexChange";
        public static const UNLOAD:String = "unload";
        public static const USER_IDLE:String = "userIdle"; //AIR
        public static const USER_PRESENT:String = "userPresent"; //AIR
        
        public function Event(type:String, bubbles:Boolean = false, cancelable:Boolean = false)
        {
            
        }
        
        public function get bubbles():Boolean
        {
            return false;
        }
        
        public function get cancelable():Boolean
        {
            return false;
        }
        
        public function get currentTarget():Object
        {
            return {};
        }
        
        public function get eventPhase():uint
        {
            return 0;
        }
        
        public function get target():Object
        {
            return {};
        }
        
        public function get type():String
        {
            return "";
        }
        
        
        public function clone():Event
        {
            return new Event( "" );
        }
        
        public function formatToString(className:String, ... arguments):String
        {
            return "";
        }
        
        public function isDefaultPrevented():Boolean
        {
            return false;
        }
        
        public function preventDefault():void
        {
            
        }
        
        public function stopImmediatePropagation():void
        {
            
        }
        
        public function stopPropagation():void
        {
            
        }
        
        public function toString():String
        {
            return "";
        }
        
    }
    
    public interface IEventDispatcher
    {
        function addEventListener(type:String, listener:Function, useCapture:Boolean = false, priority:int = 0, useWeakReference:Boolean = false):void;
        function dispatchEvent(event:Event):Boolean;
        function hasEventListener(type:String):Boolean;
        function removeEventListener(type:String, listener:Function, useCapture:Boolean = false):void;
        function willTrigger(type:String):Boolean;
    }
    
    public class EventDispatcher implements IEventDispatcher
    {
        
        public function EventDispatcher(target:IEventDispatcher = null)
        {
            
        }
        
        public function addEventListener(type:String, listener:Function, useCapture:Boolean = false, priority:int = 0, useWeakReference:Boolean = false):void
        {
            
        }
        
        public function dispatchEvent(event:Event):Boolean
        {
            return false;
        }
        
        public function hasEventListener(type:String):Boolean
        {
            return false;
        }
        
        public function removeEventListener(type:String, listener:Function, useCapture:Boolean = false):void
        {
            
        }
        
        public function willTrigger(type:String):Boolean
        {
            return false;
        }
        
        
    }
    
    public class NetStatusEvent extends Event
    {
        public static const NET_STATUS:String = "netStatus";
        
        private var _info:Object;
        
        public function NetStatusEvent(type:String, bubbles:Boolean = false, cancelable:Boolean = false, info:Object = null)
        {
            super( type, bubbles, cancelable );
            _info = info;
        }
        
        public function get info():Object
        {
            return _info;
        }
        
        public function set info(value:Object):void
        {
            _info = value;
        }
        
        override public function clone():Event
        {
            return new NetStatusEvent( type, bubbles, cancelable, info );
        }
        
        override public function toString():String
        {
            return formatToString( "NetStatusEvent", "type", "bubbles", "cancelable", "info" );
        }
        
    }
    
}

