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

package flash.net
{
    import flash.events.EventDispatcher;
    import flash.utils.Endian;
    
    public function getClassByAlias(aliasName:String):Class
    {
        return null;
    }
    
    public function navigateToURL(request:URLRequest, window:String = null):void
    {
        
    }
    
    public function registerClassAlias(aliasName:String, classObject:Class):void
    {
        
    }
    
    public function sendToURL(request:URLRequest):void
    {
        
    }
    
    
    public final class FileFilter
    {
        
    }
    
    public class FileReference extends EventDispatcher
    {
        
    }
    
    public class FileReferenceList extends EventDispatcher
    {
        
    }
    
    public interface IDynamicPropertyOutput
    {
        function writeDynamicProperty(name:String, value:*):void;
    }
    
    public interface IDynamicPropertyWriter
    {
        function writeDynamicProperties(obj:Object, output:IDynamicPropertyOutput):void;
    }
    
    public class LocalConnection extends EventDispatcher
    {
        public function LocalConnection()
        {
            
        }
        
        public function get client():Object
        {
            return null;
        }
        
        public function set client(value:Object):void
        {
            
        }
        
        public function get domain():String
        {
            return "";
        }
        
        public function allowDomain(... domains):void
        {
            
        }
        
        public function allowInsecureDomain(... domains):void
        {
            
        }
        
        public function close():void
        {
            
        }
        
        public function connect(connectionName:String):void
        {
            
        }
        
        public function send(connectionName:String, methodName:String, ... arguments):void
        {
            
        }
        
    }
    
    public class NetConnection extends EventDispatcher
    {
        
    }
    
    public class NetStream extends EventDispatcher
    {
        
    }
    
    public final class NetStreamInfo
    {
        
    }
    
    public dynamic class NetStreamPlayOptions extends EventDispatcher
    {
        
    }
    
    public class NetStreamPlayTransitions
    {
        
    }
    
    public final class ObjectEncoding
    {
        
    }
    
    public class Responder
    {
        
    }
    
    public class SharedObject extends EventDispatcher
    {
        
        public function get client():Object
        {
            return null;
        }
        
        public function set client(value:Object):void
        {
            
        }
        
        public function get data():Object
        {
            return null;
        }
        
        public static function get defaultObjectEncoding():uint
        {
            return 0;
        }
        
        public function set defaultObjectEncoding(value:uint):void
        {
            
        }
        
        public function set fps(value:Number):void
        {
            
        }
        
        public function get objectEncoding():uint
        {
            return 0;
        }
        
        public function set objectEncoding(value:uint):void
        {
            
        }
        
        public function get size():uint
        {
            return 0;
        }
        
        public function clear():void
        {
            
        }
        
        public function close():void
        {
            
        }
        
        public function connect(myConnection:NetConnection, params:String = null):void
        {
            
        }
        
        public function flush(minDiskSpace:int = 0):String
        {
            
        }
        
        public static function getLocal(name:String, localPath:String = null, secure:Boolean = false):SharedObject
        {
            return null;
        }
        
        public static function getRemote(name:String, remotePath:String = null, persistence:Object = false, secure:Boolean = false):SharedObject
        {
            return null;
        }
        
        public function send(... arguments):void
        {
            
        }
        
        public function setDirty(propertyName:String):void
        {
            
        }
        
        public function setProperty(propertyName:String, value:Object = null):void
        {
            
        }
        
    }
    
    [native(cls="SocketClass", instance="SocketObject", methods="auto")]
    public class Socket extends EventDispatcher
    {
        private var _connected:Boolean = false;
        private var _endian:String     = Endian.BIG_ENDIAN;
        private var _objectEncoding:uint;
        private var _timeout:uint      = 20000; //ms
        
        public function Socket( host:String = null, port:int = 0 )
        {
            //init( "hello world" );
        }
        
        private native function init( test:String ):void;
        
        public native function get inited():String;
        
        public function get bytesAvailable():uint
        {
            return 0;
        }
        
        public function get connected():Boolean
        {
            return _connected;
        }
        
        public function get endian():String
        {
            return _endian;
        }
        
        public function set endian( value:String ):void
        {
            _endian = value;
        }
        
        public function get objectEncoding():uint
        {
            return _objectEncoding;
        }
        
        public function set objectEncoding( value:uint ):void
        {
            _objectEncoding = value;
        }
        
        public function get timeout():uint
        {
            return _timeout;
        }
        
        public function set timeout( value:uint ):void
        {
            _timeout = value;
        }
        
        
        public function close():void
        {
            
        }
        
        public function connect( host:String, port:int ):void
        {
            
        }
        
        public function flush():void
        {
            
        }
        
        public function readByte():int
        {
            return 0;
        }
        
        public function writeByte( value:int ):void
        {
            
        }
        
    }
    
    public class URLLoader extends EventDispatcher
    {
        
    }
    
    public final class URLLoaderDataFormat
    {
        
    }
    
    public final class URLRequest
    {
        
    }
    
    public class URLRequestDefaults
    {
        
    }
    
    public final class URLRequestHeader
    {
        
    }
    
    public final class URLRequestMethod
    {
        
    }
    
    public class URLStream extends EventDispatcher
    {
        
    }
    
    public dynamic class URLVariables
    {
        
    }
    
    public class XMLSocket extends EventDispatcher
    {
        
    }
    
}

