/* -*- mode: java; tab-width: 4; insert-tabs-mode: nil; indent-tabs-mode: nil -*- */
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
 *   Adobe AS3 Team
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

use namespace "flash.utils";

/* Emitter for various data in ABC-compatible formats, as a byte
 * stream.  The byte stream is represented as an array of unsigned
 * integers below 256 here, the purpose is that we will dump its
 * contents to an external medium and load it into a VM.
 *
 * All data are dumped in litte-endian format.
 */

class ABCByteStream
{
    /*private*/ const bytes;

    // If a ByteArray is passed in, then it is used to construct the ABCByteStream, otherwise a new empty ByteArray is used
    function ABCByteStream (b = null) : bytes = (b != null ? b : new ByteArray )
    {
        // Tamarin was fixed so this is always set correctly now... I think
        bytes.endian = "littleEndian";
        bytes.position = 0;
    }

    function get length() {
        return bytes.length;
    }

    function uint8(val:uint) {
        Util::assert(val < 256);
        bytes.writeByte (val);
    }

    function uint16(val:uint) {
        Util::assert(val < 65536);
        //bytes.push(val & 0xFF,
        //           (val >> 8) & 0xFF);
        bytes.writeByte (val & 0xFF);
        bytes.writeByte ((val >> 8) & 0xFF);
    }

    function int16(val:int) {
        Util::assert(-32768 <= val && val < 32768);
        //bytes.push(val & 0xFF,
        //           (val >> 8) & 0xFF);
        bytes.writeByte (val & 0xFF);
        bytes.writeByte ((val >> 8) & 0xFF);
    }

    function int24(val:int) {
        Util::assert(-16777216 <= val && val < 16777216);
        //bytes.push(val & 0xFF,
        //           (val >> 8) & 0xFF,
        //           (val >> 16) & 0xFF);
        bytes.writeByte (val & 0xFF);
        bytes.writeByte ((val >> 8) & 0xFF);
        bytes.writeByte ((val >> 16) & 0xFF);
    }

    function uint30(val:uint) {
        Util::assert(val < 1073741824);
        uint32(val);
    }

    function int30(val:int) {
        Util::assert(-1073741824 <= val && val < 1073741824);
        if (val < 0)
            uint32(-val);
        else
            uint32(uint(val));
    }

    function int32(val:int) {
        uint32(uint(val));
    }

    function uint32(val:uint) {
        if( val < 0x80 ) {
            // 7 bits
            //bytes.push(val & 0x7F);
            bytes.writeByte (val & 0x7F);
        }
        else if ( val < 0x4000 ) {
            // 14 bits
            //bytes.push((val & 0x7F) | 0x80,
            //           (val >> 7) & 0x7F);
            bytes.writeByte ((val & 0x7F) | 0x80);
            bytes.writeByte ((val >> 7) & 0x7F);
        }
        else if ( val < 0x200000 ) {
            // 21 bits
            //bytes.push((val & 0x7F) | 0x80,
            //           ((val >> 7) & 0x7F) | 0x80,
            //           (val >> 14) & 0x7F);
            bytes.writeByte ((val & 0x7F) | 0x80);
            bytes.writeByte (((val >> 7) & 0x7F) | 0x80);
            bytes.writeByte ((val >> 14) & 0x7F);
        }
        else if ( val < 0x10000000 ) {
            // 28 bits
            //bytes.push((val & 0x7F) | 0x80,
            //           ((val >> 7) & 0x7F) | 0x80,
            //           ((val >> 14) & 0x7F) | 0x80,
            //           (val >> 21) & 0x7F);
            bytes.writeByte ((val & 0x7F) | 0x80);
            bytes.writeByte (((val >> 7) & 0x7F) | 0x80);
            bytes.writeByte (((val >> 14) & 0x7F) | 0x80);
            bytes.writeByte ((val >> 21) & 0x7F);
        }
        else {
            // 32 bits
            //bytes.push((val & 0x7F) | 0x80,
            //           ((val >> 7) & 0x7F) | 0x80,
            //           ((val >> 14) & 0x7F) | 0x80,
            //           ((val >> 21) & 0x7F) | 0x80,
            //           (val >> 28) & 0x7F);
            bytes.writeByte ((val & 0x7F) | 0x80);
            bytes.writeByte (((val >> 7) & 0x7F) | 0x80);
            bytes.writeByte (((val >> 14) & 0x7F) | 0x80);
            bytes.writeByte (((val >> 21) & 0x7F) | 0x80);
            bytes.writeByte ((val >> 28) & 0x7F);
        }
    }

    function float64(val /*FIXME ES4: double*/) {
        bytes.writeDouble (val);
    }

    function utf8(str /*FIXME ES4: string*/) {
        bytes.writeUTFBytes (str);
    }

    function setInt24(loc, val) {
        Util::assert(-16777216 <= val && val < 16777216);
        //bytes[loc] = val & 0xFF;
        //bytes[loc+1] = (val >> 8) & 0xFF;
        //bytes[loc+2] = (val >> 16) & 0xFF;
        let orig_pos = bytes.position;
        bytes.position = loc;
        int24 (val);
        bytes.position = bytes.length;
    }

    function serialize(s:ABCByteStream) {
        s.byteStream(this);
    }

    function byteStream(from:ABCByteStream) {
        bytes.writeBytes (from.bytes);
        //var from_bytes = from.bytes;
        //for ( var i=0, limit=from_bytes.length ; i < limit ; i++ )
        //    bytes.push(from_bytes[i]);
    }

    /* Returns *some* concrete byte-array type, but the concrete
     * type is not part of the API here.  Clients must be adapted
     * to particular environments anyway.
     */
    function getBytes(): * {
        return bytes;
    }

    function getArrayOfBytes () {
        var a = [];
        bytes.position = 0;
        while (bytes.bytesAvailable) {
            a.push (bytes.readByte()&0xff);
        }
        return a;
    }
        
    function readByte() : uint {
        return bytes.readUnsignedByte();
    }
        
    function readInt() {
        return bytes.readInt();
    }

    function readDouble() {
        return bytes.readDouble();
    }
        
    function readUTFBytes(length:uint) {
        return bytes.readUTFBytes(length);
    }
        
    function readU30():uint
        readU32();

    function readS32():int
        int(readU32());

    // FIXME
    //
    // Explicit uint cast here because ESC erases type annotations
    // at present, and bitops produce 'int'.

    function readU32():uint {
        var result = bytes.readUnsignedByte();
        if (result & 0x00000080) {
            result = result & 0x0000007f | bytes.readUnsignedByte()<<7;
            if (result & 0x00004000) {
                result = result & 0x00003fff | bytes.readUnsignedByte()<<14;
                if (result & 0x00200000) {
                    result = result & 0x001fffff | bytes.readUnsignedByte()<<21;
                    if (result & 0x10000000)
                        result = result & 0x0fffffff | bytes.readUnsignedByte()<<28;
                }
            }
        }
        return uint(result);
    }
        
    function readS24():int
    {
        var b:uint = bytes.readUnsignedByte();
        var b1:uint = bytes.readUnsignedByte();
        var b2:uint = bytes.readUnsignedByte();
            
        b = b | (b1<<8);
        b = b | (b2<<16);
        return b;
    }

    function get position() {
        return bytes.position;
    }
    function set position(pos) {
        bytes.position = pos;
    }
        
    function get bytesAvailable() {
        return bytes.bytesAvailable;
    }
}
