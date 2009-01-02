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
    import flash.utils.Endian;
    
    [native(cls="SocketClass", instance="SocketObject", methods="auto")]
    public class Socket
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
    
}

