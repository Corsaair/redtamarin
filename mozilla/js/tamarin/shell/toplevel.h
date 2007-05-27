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

const int avmplus_System_exit = 7;
const int avmplus_System_exec = 8;
const int avmplus_System_getAvmplusVersion = 9;
const int avmplus_System_trace = 10;
const int avmplus_System_write = 11;
const int avmplus_System_debugger = 12;
const int avmplus_System_isDebugger = 13;
const int avmplus_System_getTimer = 14;
const int avmplus_System_private_getArgv = 15;
const int avmplus_System_readLine = 16;
const int abcclass_avmplus_System = 0;
const int avmplus_File_exists = 19;
const int avmplus_File_read = 20;
const int avmplus_File_write = 21;
const int abcclass_avmplus_File = 1;
const int abcclass_flash_system_Capabilities = 2;
const int avmplus_Domain_currentDomain_get = 28;
const int avmplus_Domain_Domain = 29;
const int avmplus_Domain_loadBytes = 30;
const int avmplus_Domain_getClass = 31;
const int abcclass_avmplus_Domain = 3;
const int avmplus_StringBuilder_append = 35;
const int avmplus_StringBuilder_capacity_get = 36;
const int avmplus_StringBuilder_charAt = 37;
const int avmplus_StringBuilder_charCodeAt = 38;
const int avmplus_StringBuilder_ensureCapacity = 39;
const int avmplus_StringBuilder_indexOf = 40;
const int avmplus_StringBuilder_insert = 41;
const int avmplus_StringBuilder_lastIndexOf = 42;
const int avmplus_StringBuilder_length_get = 43;
const int avmplus_StringBuilder_length_set = 44;
const int avmplus_StringBuilder_remove = 45;
const int avmplus_StringBuilder_removeCharAt = 46;
const int avmplus_StringBuilder_replace = 47;
const int avmplus_StringBuilder_reverse = 48;
const int avmplus_StringBuilder_setCharAt = 49;
const int avmplus_StringBuilder_substring = 50;
const int avmplus_StringBuilder_toString = 51;
const int avmplus_StringBuilder_trimToSize = 52;
const int abcclass_avmplus_StringBuilder = 4;
const int flash_utils_ByteArray_readFile = 54;
const int flash_utils_ByteArray_writeFile = 55;
const int flash_utils_ByteArray_readBytes = 56;
const int flash_utils_ByteArray_writeBytes = 57;
const int flash_utils_ByteArray_writeBoolean = 58;
const int flash_utils_ByteArray_writeByte = 59;
const int flash_utils_ByteArray_writeShort = 60;
const int flash_utils_ByteArray_writeInt = 61;
const int flash_utils_ByteArray_writeUnsignedInt = 62;
const int flash_utils_ByteArray_writeFloat = 63;
const int flash_utils_ByteArray_writeDouble = 64;
const int flash_utils_ByteArray_writeUTF = 65;
const int flash_utils_ByteArray_writeUTFBytes = 66;
const int flash_utils_ByteArray_readBoolean = 67;
const int flash_utils_ByteArray_readByte = 68;
const int flash_utils_ByteArray_readUnsignedByte = 69;
const int flash_utils_ByteArray_readShort = 70;
const int flash_utils_ByteArray_readUnsignedShort = 71;
const int flash_utils_ByteArray_readInt = 72;
const int flash_utils_ByteArray_readUnsignedInt = 73;
const int flash_utils_ByteArray_readFloat = 74;
const int flash_utils_ByteArray_readDouble = 75;
const int flash_utils_ByteArray_readUTF = 76;
const int flash_utils_ByteArray_readUTFBytes = 77;
const int flash_utils_ByteArray_length_get = 78;
const int flash_utils_ByteArray_length_set = 79;
const int flash_utils_ByteArray_compress = 80;
const int flash_utils_ByteArray_uncompress = 81;
const int flash_utils_ByteArray_toString = 82;
const int flash_utils_ByteArray_bytesAvailable_get = 83;
const int flash_utils_ByteArray_position_get = 84;
const int flash_utils_ByteArray_position_set = 85;
const int flash_utils_ByteArray_endian_get = 86;
const int flash_utils_ByteArray_endian_set = 87;
const int abcclass_flash_utils_ByteArray = 5;
const int flash_utils_IntArray_length_get = 90;
const int flash_utils_IntArray_length_set = 91;
const int abcclass_flash_utils_IntArray = 6;
const int flash_utils_UIntArray_length_get = 94;
const int flash_utils_UIntArray_length_set = 95;
const int abcclass_flash_utils_UIntArray = 7;
const int flash_utils_DoubleArray_length_get = 98;
const int flash_utils_DoubleArray_length_set = 99;
const int abcclass_flash_utils_DoubleArray = 8;
const int flash_utils_FloatArray_length_get = 102;
const int flash_utils_FloatArray_length_set = 103;
const int abcclass_flash_utils_FloatArray = 9;
const int flash_utils_ShortArray_length_get = 106;
const int flash_utils_ShortArray_length_set = 107;
const int abcclass_flash_utils_ShortArray = 10;
const int flash_utils_UShortArray_length_get = 110;
const int flash_utils_UShortArray_length_set = 111;
const int abcclass_flash_utils_UShortArray = 11;
const int flash_utils_Dictionary_Dictionary = 114;
const int abcclass_flash_utils_Dictionary = 12;
const int abcclass_flash_utils_Endian = 13;
const int avmplus_JObject_create = 118;
const int avmplus_JObject_createArray = 119;
const int avmplus_JObject_toArray = 120;
const int avmplus_JObject_constructorSignature = 121;
const int avmplus_JObject_methodSignature = 122;
const int avmplus_JObject_fieldSignature = 123;
const int avmplus_JObject_toString = 124;
const int abcclass_avmplus_JObject = 14;
