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
 * The Original Code is [Open Source Virtual Machine].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2008
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
/* machine generated file -- do not edit */
#define AVMTHUNK_VERSION 4
extern const uint32_t shell_toplevel_abc_class_count;
extern const uint32_t shell_toplevel_abc_script_count;
extern const uint32_t shell_toplevel_abc_method_count;
extern const uint32_t shell_toplevel_abc_length;
extern const uint8_t shell_toplevel_abc_data[];
AVMTHUNK_DECLARE_NATIVE_INITIALIZER(shell_toplevel)
/* classes */
const uint32_t abcclass_avmplus_System = 0;
const uint32_t abcclass_avmplus_File = 1;
const uint32_t abcclass_avmplus_Domain = 2;
const uint32_t abcclass_avmplus_StringBuilder = 3;
const uint32_t abcclass_flash_utils_ByteArray = 4;
const uint32_t abcclass_flash_sampler_StackFrame = 5;
const uint32_t abcclass_flash_sampler_Sample = 6;
const uint32_t abcclass_flash_sampler_NewObjectSample = 7;
const uint32_t abcclass_flash_sampler_DeleteObjectSample = 8;
const uint32_t abcclass_flash_trace_Trace = 9;
const uint32_t abcclass_flash_utils_Dictionary = 10;
const uint32_t abcclass_avmplus_CompatibilityMode = 11;
const uint32_t abcclass_avmplus_redtamarin = 12;
const uint32_t abcclass_C_stdlib___stdlib = 13;
const uint32_t abcclass_flash_errors_IOError = 14;
const uint32_t abcclass_flash_errors_IllegalOperationError = 15;
const uint32_t abcclass_flash_errors_MemoryError = 16;
const uint32_t abcclass_flash_errors_ScriptTimeoutError = 17;
const uint32_t abcclass_flash_errors_StackOverflowError = 18;
const uint32_t abcclass_flash_errors_EOFError = 19;
const uint32_t abcclass_flash_system_System = 20;
const uint32_t abcclass_flash_system_ApplicationDomain = 21;
const uint32_t abcclass_flash_system_Capabilities = 22;
const uint32_t abcclass_flash_net_Socket = 23;
const uint32_t abcclass_flash_utils_Endian = 24;
const uint32_t abcclass_avmplus_JObject = 25;
/* methods */
const uint32_t avmplus_System_exit = 10;
const uint32_t avmplus_System_exec = 11;
const uint32_t avmplus_System_getAvmplusVersion = 12;
const uint32_t avmplus_System_trace = 13;
const uint32_t avmplus_System_write = 14;
const uint32_t avmplus_System_debugger = 15;
const uint32_t avmplus_System_isDebugger = 16;
const uint32_t avmplus_System_getTimer = 17;
const uint32_t avmplus_System_private_getArgv = 18;
const uint32_t avmplus_System_readLine = 19;
const uint32_t avmplus_System_totalMemory_get = 20;
const uint32_t avmplus_System_freeMemory_get = 21;
const uint32_t avmplus_System_privateMemory_get = 22;
const uint32_t avmplus_System_isGlobal = 23;
const uint32_t avmplus_File_exists = 26;
const uint32_t avmplus_File_read = 27;
const uint32_t avmplus_File_write = 28;
const uint32_t avmplus_Domain_currentDomain_get = 34;
const uint32_t avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get = 35;
const uint32_t avmplus_Domain_private_init = 36;
const uint32_t avmplus_Domain_loadBytes = 38;
const uint32_t avmplus_Domain_getClass = 39;
const uint32_t avmplus_Domain_domainMemory_get = 41;
const uint32_t avmplus_Domain_domainMemory_set = 42;
const uint32_t avmplus_StringBuilder_append = 46;
const uint32_t avmplus_StringBuilder_capacity_get = 47;
const uint32_t avmplus_StringBuilder_charAt = 48;
const uint32_t avmplus_StringBuilder_charCodeAt = 49;
const uint32_t avmplus_StringBuilder_ensureCapacity = 50;
const uint32_t avmplus_StringBuilder_indexOf = 51;
const uint32_t avmplus_StringBuilder_insert = 52;
const uint32_t avmplus_StringBuilder_lastIndexOf = 53;
const uint32_t avmplus_StringBuilder_length_get = 54;
const uint32_t avmplus_StringBuilder_length_set = 55;
const uint32_t avmplus_StringBuilder_remove = 56;
const uint32_t avmplus_StringBuilder_removeCharAt = 57;
const uint32_t avmplus_StringBuilder_replace = 58;
const uint32_t avmplus_StringBuilder_reverse = 59;
const uint32_t avmplus_StringBuilder_setCharAt = 60;
const uint32_t avmplus_StringBuilder_substring = 61;
const uint32_t avmplus_StringBuilder_toString = 62;
const uint32_t avmplus_StringBuilder_trimToSize = 63;
const uint32_t flash_utils_ByteArray_readFile = 66;
const uint32_t flash_utils_ByteArray_writeFile = 67;
const uint32_t flash_utils_ByteArray_readBytes = 68;
const uint32_t flash_utils_ByteArray_writeBytes = 69;
const uint32_t flash_utils_ByteArray_writeBoolean = 70;
const uint32_t flash_utils_ByteArray_writeByte = 71;
const uint32_t flash_utils_ByteArray_writeShort = 72;
const uint32_t flash_utils_ByteArray_writeInt = 73;
const uint32_t flash_utils_ByteArray_writeUnsignedInt = 74;
const uint32_t flash_utils_ByteArray_writeFloat = 75;
const uint32_t flash_utils_ByteArray_writeDouble = 76;
const uint32_t flash_utils_ByteArray_writeUTF = 77;
const uint32_t flash_utils_ByteArray_writeUTFBytes = 78;
const uint32_t flash_utils_ByteArray_readBoolean = 79;
const uint32_t flash_utils_ByteArray_readByte = 80;
const uint32_t flash_utils_ByteArray_readUnsignedByte = 81;
const uint32_t flash_utils_ByteArray_readShort = 82;
const uint32_t flash_utils_ByteArray_readUnsignedShort = 83;
const uint32_t flash_utils_ByteArray_readInt = 84;
const uint32_t flash_utils_ByteArray_readUnsignedInt = 85;
const uint32_t flash_utils_ByteArray_readFloat = 86;
const uint32_t flash_utils_ByteArray_readDouble = 87;
const uint32_t flash_utils_ByteArray_readUTF = 88;
const uint32_t flash_utils_ByteArray_readUTFBytes = 89;
const uint32_t flash_utils_ByteArray_length_get = 90;
const uint32_t flash_utils_ByteArray_length_set = 91;
const uint32_t flash_utils_ByteArray_private_zlib_compress = 92;
const uint32_t flash_utils_ByteArray_private_zlib_uncompress = 94;
const uint32_t flash_utils_ByteArray_private__toString = 96;
const uint32_t flash_utils_ByteArray_bytesAvailable_get = 98;
const uint32_t flash_utils_ByteArray_position_get = 99;
const uint32_t flash_utils_ByteArray_position_set = 100;
const uint32_t flash_utils_ByteArray_endian_get = 101;
const uint32_t flash_utils_ByteArray_endian_set = 102;
const uint32_t flash_sampler_isGetterSetter = 105;
const uint32_t flash_sampler__getInvocationCount = 106;
const uint32_t flash_sampler_getSampleCount = 110;
const uint32_t flash_sampler_getSamples = 111;
const uint32_t flash_sampler_getMemberNames = 112;
const uint32_t flash_sampler_getSize = 113;
const uint32_t flash_sampler__setSamplerCallback = 114;
const uint32_t flash_sampler_sampleInternalAllocs = 117;
const uint32_t flash_sampler_pauseSampling = 118;
const uint32_t flash_sampler_stopSampling = 119;
const uint32_t flash_sampler_startSampling = 120;
const uint32_t flash_sampler_clearSamples = 121;
const uint32_t flash_sampler_NewObjectSample_object_get = 128;
const uint32_t flash_sampler_NewObjectSample_size_get = 129;
const uint32_t flash_trace_Trace_setLevel = 135;
const uint32_t flash_trace_Trace_getLevel = 136;
const uint32_t flash_trace_Trace_setListener = 137;
const uint32_t flash_trace_Trace_getListener = 138;
const uint32_t flash_utils_Dictionary_private_init = 142;
const uint32_t avmplus_redtamarin_private____assert = 148;
const uint32_t C_stdlib___stdlib_EXIT_SUCCESS_get = 162;
const uint32_t C_stdlib___stdlib_EXIT_FAILURE_get = 163;
const uint32_t C_stdlib___stdlib___rand = 164;
const uint32_t C_stdlib___stdlib___abort = 165;
const uint32_t C_stdlib___stdlib___exit = 166;
const uint32_t C_stdlib___stdlib___getenv = 167;
const uint32_t C_stdlib___stdlib___setenv = 168;
const uint32_t C_stdlib___stdlib___system = 169;
const uint32_t flash_system_Capabilities_private___getOSname = 203;
const uint32_t flash_net_Socket_private_init = 237;
const uint32_t flash_net_Socket_inited_get = 238;
const uint32_t avmplus_JObject_create = 257;
const uint32_t avmplus_JObject_createArray = 258;
const uint32_t avmplus_JObject_toArray = 259;
const uint32_t avmplus_JObject_constructorSignature = 260;
const uint32_t avmplus_JObject_methodSignature = 261;
const uint32_t avmplus_JObject_fieldSignature = 262;
extern AvmBox shell_toplevel_s2a_oos_rest_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_JObject_methodSignature_thunk  shell_toplevel_s2a_oos_rest_thunk

extern double shell_toplevel_d2d_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define flash_sampler_NewObjectSample_size_get_thunk  shell_toplevel_d2d_o_thunk
#define avmplus_System_freeMemory_get_thunk  shell_toplevel_d2d_o_thunk
#define avmplus_System_privateMemory_get_thunk  shell_toplevel_d2d_o_thunk
#define flash_sampler_getSampleCount_thunk  shell_toplevel_d2d_o_thunk
#define flash_utils_ByteArray_readFloat_thunk  shell_toplevel_d2d_o_thunk
#define avmplus_System_totalMemory_get_thunk  shell_toplevel_d2d_o_thunk
#define flash_utils_ByteArray_readDouble_thunk  shell_toplevel_d2d_o_thunk

extern AvmBox shell_toplevel_v2a_oouu_opti0_opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define flash_utils_ByteArray_writeBytes_thunk  shell_toplevel_v2a_oouu_opti0_opti0_thunk
#define flash_utils_ByteArray_readBytes_thunk  shell_toplevel_v2a_oouu_opti0_opti0_thunk

extern AvmBox shell_toplevel_a2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define flash_utils_ByteArray_readFile_thunk  shell_toplevel_a2a_os_thunk
#define avmplus_Domain_getClass_thunk  shell_toplevel_a2a_os_thunk

extern AvmBox shell_toplevel_u2a_ou_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_StringBuilder_charCodeAt_thunk  shell_toplevel_u2a_ou_thunk

extern AvmBox shell_toplevel_a2a_ou_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_StringBuilder_length_set_thunk  shell_toplevel_a2a_ou_thunk

extern AvmBox shell_toplevel_a2a_oo_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_JObject_toArray_thunk  shell_toplevel_a2a_oo_thunk
#define avmplus_Domain_loadBytes_thunk  shell_toplevel_a2a_oo_thunk
#define avmplus_Domain_domainMemory_set_thunk  shell_toplevel_a2a_oo_thunk
#define flash_trace_Trace_setListener_thunk  shell_toplevel_a2a_oo_thunk

extern AvmBox shell_toplevel_s2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_System_readLine_thunk  shell_toplevel_s2a_o_thunk
#define flash_utils_ByteArray_endian_get_thunk  shell_toplevel_s2a_o_thunk
#define flash_net_Socket_inited_get_thunk  shell_toplevel_s2a_o_thunk
#define flash_utils_ByteArray_readUTF_thunk  shell_toplevel_s2a_o_thunk
#define flash_utils_ByteArray_private__toString_thunk  shell_toplevel_s2a_o_thunk
#define avmplus_System_getAvmplusVersion_thunk  shell_toplevel_s2a_o_thunk
#define flash_system_Capabilities_private___getOSname_thunk  shell_toplevel_s2a_o_thunk
#define avmplus_StringBuilder_toString_thunk  shell_toplevel_s2a_o_thunk

extern AvmBox shell_toplevel_v2a_oss_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_File_write_thunk  shell_toplevel_v2a_oss_thunk

extern AvmBox shell_toplevel_b2a_oao_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define flash_sampler_isGetterSetter_thunk  shell_toplevel_b2a_oao_thunk

extern AvmBox shell_toplevel_i2a_oi_opti2_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define flash_trace_Trace_getLevel_thunk  shell_toplevel_i2a_oi_opti2_thunk

extern AvmBox shell_toplevel_v2a_ous_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_StringBuilder_setCharAt_thunk  shell_toplevel_v2a_ous_thunk

extern AvmBox shell_toplevel_u2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define flash_utils_ByteArray_readUnsignedShort_thunk  shell_toplevel_u2a_o_thunk
#define flash_utils_ByteArray_bytesAvailable_get_thunk  shell_toplevel_u2a_o_thunk
#define flash_utils_ByteArray_length_get_thunk  shell_toplevel_u2a_o_thunk
#define avmplus_StringBuilder_length_get_thunk  shell_toplevel_u2a_o_thunk
#define flash_utils_ByteArray_readUnsignedInt_thunk  shell_toplevel_u2a_o_thunk
#define flash_utils_ByteArray_readUnsignedByte_thunk  shell_toplevel_u2a_o_thunk
#define avmplus_System_getTimer_thunk  shell_toplevel_u2a_o_thunk
#define avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get_thunk  shell_toplevel_u2a_o_thunk
#define avmplus_StringBuilder_capacity_get_thunk  shell_toplevel_u2a_o_thunk
#define flash_utils_ByteArray_position_get_thunk  shell_toplevel_u2a_o_thunk

extern AvmBox shell_toplevel_v2a_ouu_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_StringBuilder_remove_thunk  shell_toplevel_v2a_ouu_thunk

extern AvmBox shell_toplevel_a2a_ooio_optakAvmThunkNull_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_JObject_createArray_thunk  shell_toplevel_a2a_ooio_optakAvmThunkNull_thunk

extern AvmBox shell_toplevel_s2a_os_rest_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_JObject_constructorSignature_thunk  shell_toplevel_s2a_os_rest_thunk

extern AvmBox shell_toplevel_i2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define C_stdlib___stdlib_EXIT_FAILURE_get_thunk  shell_toplevel_i2a_o_thunk
#define flash_utils_ByteArray_readInt_thunk  shell_toplevel_i2a_o_thunk
#define flash_utils_ByteArray_readShort_thunk  shell_toplevel_i2a_o_thunk
#define C_stdlib___stdlib___rand_thunk  shell_toplevel_i2a_o_thunk
#define C_stdlib___stdlib_EXIT_SUCCESS_get_thunk  shell_toplevel_i2a_o_thunk
#define flash_utils_ByteArray_readByte_thunk  shell_toplevel_i2a_o_thunk

extern AvmBox shell_toplevel_v2a_oua_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_StringBuilder_insert_thunk  shell_toplevel_v2a_oua_thunk

extern AvmBox shell_toplevel_s2a_oos_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_JObject_fieldSignature_thunk  shell_toplevel_s2a_oos_thunk

extern AvmBox shell_toplevel_v2a_ouus_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_StringBuilder_replace_thunk  shell_toplevel_v2a_ouus_thunk

extern AvmBox shell_toplevel_i2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define C_stdlib___stdlib___system_thunk  shell_toplevel_i2a_os_thunk
#define avmplus_System_exec_thunk  shell_toplevel_i2a_os_thunk

extern AvmBox shell_toplevel_b2a_oa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_System_isGlobal_thunk  shell_toplevel_b2a_oa_thunk

extern AvmBox shell_toplevel_s2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define C_stdlib___stdlib___getenv_thunk  shell_toplevel_s2a_os_thunk
#define avmplus_File_read_thunk  shell_toplevel_s2a_os_thunk

extern AvmBox shell_toplevel_s2a_ou_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_StringBuilder_charAt_thunk  shell_toplevel_s2a_ou_thunk
#define flash_utils_ByteArray_readUTFBytes_thunk  shell_toplevel_s2a_ou_thunk

extern AvmBox shell_toplevel_a2a_os_rest_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_JObject_create_thunk  shell_toplevel_a2a_os_rest_thunk

extern AvmBox shell_toplevel_b2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define flash_utils_ByteArray_readBoolean_thunk  shell_toplevel_b2a_o_thunk
#define avmplus_System_isDebugger_thunk  shell_toplevel_b2a_o_thunk

extern AvmBox shell_toplevel_i2a_ossi_opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define C_stdlib___stdlib___setenv_thunk  shell_toplevel_i2a_ossi_opti0_thunk

extern AvmBox shell_toplevel_b2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_File_exists_thunk  shell_toplevel_b2a_os_thunk

extern AvmBox shell_toplevel_a2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define flash_sampler_getSamples_thunk  shell_toplevel_a2a_o_thunk
#define avmplus_Domain_currentDomain_get_thunk  shell_toplevel_a2a_o_thunk
#define avmplus_System_private_getArgv_thunk  shell_toplevel_a2a_o_thunk
#define flash_trace_Trace_getListener_thunk  shell_toplevel_a2a_o_thunk
#define flash_sampler_NewObjectSample_object_get_thunk  shell_toplevel_a2a_o_thunk
#define avmplus_Domain_domainMemory_get_thunk  shell_toplevel_a2a_o_thunk

extern double shell_toplevel_d2d_oaou_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define flash_sampler__getInvocationCount_thunk  shell_toplevel_d2d_oaou_thunk

extern AvmBox shell_toplevel_i2a_osu_optu4294967295U_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_StringBuilder_lastIndexOf_thunk  shell_toplevel_i2a_osu_optu4294967295U_thunk

extern AvmBox shell_toplevel_v2a_od_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define flash_utils_ByteArray_writeDouble_thunk  shell_toplevel_v2a_od_thunk
#define flash_utils_ByteArray_writeFloat_thunk  shell_toplevel_v2a_od_thunk

extern AvmBox shell_toplevel_s2a_ouu_optu4294967295U_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_StringBuilder_substring_thunk  shell_toplevel_s2a_ouu_optu4294967295U_thunk

extern AvmBox shell_toplevel_v2a_ob_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define flash_utils_Dictionary_private_init_thunk  shell_toplevel_v2a_ob_thunk
#define flash_utils_ByteArray_writeBoolean_thunk  shell_toplevel_v2a_ob_thunk
#define flash_sampler_sampleInternalAllocs_thunk  shell_toplevel_v2a_ob_thunk

extern AvmBox shell_toplevel_v2a_oa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_StringBuilder_append_thunk  shell_toplevel_v2a_oa_thunk

extern double shell_toplevel_d2d_oa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define flash_sampler_getSize_thunk  shell_toplevel_d2d_oa_thunk

extern AvmBox shell_toplevel_v2a_oo_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_System_trace_thunk  shell_toplevel_v2a_oo_thunk
#define avmplus_Domain_private_init_thunk  shell_toplevel_v2a_oo_thunk
#define flash_sampler__setSamplerCallback_thunk  shell_toplevel_v2a_oo_thunk

extern AvmBox shell_toplevel_i2a_osu_opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_StringBuilder_indexOf_thunk  shell_toplevel_i2a_osu_opti0_thunk

extern AvmBox shell_toplevel_v2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define flash_sampler_startSampling_thunk  shell_toplevel_v2a_o_thunk
#define flash_utils_ByteArray_private_zlib_compress_thunk  shell_toplevel_v2a_o_thunk
#define flash_sampler_pauseSampling_thunk  shell_toplevel_v2a_o_thunk
#define flash_sampler_clearSamples_thunk  shell_toplevel_v2a_o_thunk
#define flash_utils_ByteArray_private_zlib_uncompress_thunk  shell_toplevel_v2a_o_thunk
#define avmplus_System_debugger_thunk  shell_toplevel_v2a_o_thunk
#define avmplus_StringBuilder_trimToSize_thunk  shell_toplevel_v2a_o_thunk
#define C_stdlib___stdlib___abort_thunk  shell_toplevel_v2a_o_thunk
#define flash_sampler_stopSampling_thunk  shell_toplevel_v2a_o_thunk
#define avmplus_StringBuilder_reverse_thunk  shell_toplevel_v2a_o_thunk

extern AvmBox shell_toplevel_a2a_oii_opti2_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define flash_trace_Trace_setLevel_thunk  shell_toplevel_a2a_oii_opti2_thunk

extern AvmBox shell_toplevel_v2a_ou_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_StringBuilder_ensureCapacity_thunk  shell_toplevel_v2a_ou_thunk
#define flash_utils_ByteArray_position_set_thunk  shell_toplevel_v2a_ou_thunk
#define avmplus_StringBuilder_removeCharAt_thunk  shell_toplevel_v2a_ou_thunk
#define flash_utils_ByteArray_length_set_thunk  shell_toplevel_v2a_ou_thunk
#define flash_utils_ByteArray_writeUnsignedInt_thunk  shell_toplevel_v2a_ou_thunk

extern AvmBox shell_toplevel_v2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define flash_net_Socket_private_init_thunk  shell_toplevel_v2a_os_thunk
#define flash_utils_ByteArray_endian_set_thunk  shell_toplevel_v2a_os_thunk
#define flash_utils_ByteArray_writeUTF_thunk  shell_toplevel_v2a_os_thunk
#define flash_utils_ByteArray_writeUTFBytes_thunk  shell_toplevel_v2a_os_thunk
#define avmplus_System_write_thunk  shell_toplevel_v2a_os_thunk
#define flash_utils_ByteArray_writeFile_thunk  shell_toplevel_v2a_os_thunk

extern AvmBox shell_toplevel_v2a_oi_opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define C_stdlib___stdlib___exit_thunk  shell_toplevel_v2a_oi_opti0_thunk

extern AvmBox shell_toplevel_v2a_oi_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_System_exit_thunk  shell_toplevel_v2a_oi_thunk
#define flash_utils_ByteArray_writeByte_thunk  shell_toplevel_v2a_oi_thunk
#define avmplus_redtamarin_private____assert_thunk  shell_toplevel_v2a_oi_thunk
#define flash_utils_ByteArray_writeInt_thunk  shell_toplevel_v2a_oi_thunk
#define flash_utils_ByteArray_writeShort_thunk  shell_toplevel_v2a_oi_thunk

extern AvmBox shell_toplevel_a2a_oab_optbfalse_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define flash_sampler_getMemberNames_thunk  shell_toplevel_a2a_oab_optbfalse_thunk

