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

package flash.utils
{
    import avmplus.*;
    
    public namespace flash_proxy;
    
    public function clearInterval(id:uint):void
    {
        
    }
    
    public function clearTimeout(id:uint):void
    {
        
    }
    
    public function describeType(value:*):XML
    {
        return avmplus.describeType( value, FLASH10_FLAGS );
    }
    
    public function escapeMultiByte(value:String):String
    {
        return "";
    }
    
    public function getDefinitionByName(name:String):Object
    {
        return Domain.currentDomain.getClass( name ) as Object;
    }
    
    public function getQualifiedClassName(value:*):String
    {
        return avmplus.getQualifiedClassName( value );
    }
    
    public function getQualifiedSuperclassName(value:*):String
    {
        return avmplus.getQualifiedSuperclassName( value );
    }
    
    public function getTimer():int
    {
        return System.getTimer();
    }
    
    public function setInterval(closure:Function, delay:Number, ... arguments):uint
    {
        return 0;
    }
    
    public function setTimeout(closure:Function, delay:Number, ... arguments):uint
    {
        return 0;
    }
    
    public function unescapeMultiByte(value:String):String
    {
        return "";
    }
    
    //see: ByteArray.as
    
    public final class CompressionAlgorithm
    {
        
    }
    
    //see: Dictionary.as
    
    public final class Endian
    {
        public static const BIG_ENDIAN:String = "bigEndian";
        public static const LITTLE_ENDIAN:String = "littleEndian";
    }
    
    public interface IDataInput
    {
        function get bytesAvailable():uint;
        function get endian():String;
        function set endian(value:String):void;
        function get objectEncoding():uint;
        function set objectEncoding(value:uint):void;
        
        function readBoolean():Boolean;
        function readByte():int;
        function readBytes(bytes:ByteArray, offset:uint = 0, length:uint = 0):void;
        function readDouble():Number;
        function readFloat():Number;
        function readInt():int;
        function readMultiByte(length:uint, charSet:String):String;
        function readObject():*;
        function readShort():int;
        function readUnsignedByte():uint;
        function readUnsignedInt():uint;
        function readUnsignedShort():uint;
        function readUTF():String;
        function readUTFBytes(length:uint):String;
    }
    
    public interface IDataOutput
    {
        function get endian():String;
        function set endian(value:String):void;
        function get objectEncoding():uint;
        function set objectEncoding(value:uint):void;
        
        function writeBoolean(value:Boolean):void;
        function writeByte(value:int):void;
        function writeBytes(bytes:ByteArray, offset:uint = 0, length:uint = 0):void;
        function writeDouble(value:Number):void;
        function writeFloat(value:Number):void;
        function writeInt(value:int):void;
        function writeMultiByte(value:String, charSet:String):void;
        function writeObject(object:*):void;
        function writeShort(value:int):void;
        function writeUnsignedInt(value:uint):void;
        function writeUTF(value:String):void;
        function writeUTFBytes(value:String):void;
    }
    
    public interface IExternalizable
    {
        function readExternal(input:IDataInput):void;
        function writeExternal(output:IDataOutput):void;
    }
    
    public class Proxy
    {
        use namespace flash_proxy;
        
        flash_proxy function callProperty(name:*, ... rest):*
        {
            return {};
        }
        
        flash_proxy function deleteProperty(name:*):Boolean
        {
            return false;
        }
        
        flash_proxy function getDescendants(name:*):*
        {
            return {};
        }
        
        flash_proxy function getProperty(name:*):*
        {
            
        }
        
        flash_proxy function hasProperty(name:*):Boolean
        {
            return false;
        }
        
        flash_proxy function isAttribute(name:*):Boolean
        {
            return false;
        }
        
        flash_proxy function nextName(index:int):String
        {
            return "";
        }
        
        flash_proxy function nextNameIndex(index:int):int
        {
            return 0;
        }
        
        flash_proxy function nextValue(index:int):*
        {
            return null;
        }
        
        flash_proxy function setProperty(name:*, value:*):void
        {
            
        }
        
    }
    
    public class Timer
    {
        
    }
    
}

