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

#define AVMTHUNK_VERSION 5

namespace avmplus {
    class ArrayObject; // Array
    class ClassClosure; // Class
    class DeleteObjectSampleClass; // flash.sampler::DeleteObjectSample$
    class DeleteObjectSampleObject; // flash.sampler::DeleteObjectSample
    class DictionaryClass; // flash.utils::Dictionary$
    class DictionaryObject; // flash.utils::Dictionary
    class DomainClass; // avmplus::Domain$
    class DomainObject; // avmplus::Domain
    class JObject; // avmplus::JObject
    class JObjectClass; // avmplus::JObject$
    class NewObjectSampleClass; // flash.sampler::NewObjectSample$
    class NewObjectSampleObject; // flash.sampler::NewObjectSample
    class SampleClass; // flash.sampler::Sample$
    class SampleObject; // flash.sampler::Sample
    class ScriptObject; // avmplus::System
    class ScriptObject; // avmplus::File
    class ScriptObject; // flash.trace::Trace
    class StackFrameClass; // flash.sampler::StackFrame$
    class StackFrameObject; // flash.sampler::StackFrame
    class String; // String
    class TraceClass; // flash.trace::Trace$
}

namespace avmshell {
    class FileClass; // avmplus::File$
    class MIClass; // avmplus::MI$
    class MIObject; // avmplus::MI
    class SystemClass; // avmplus::System$
}

namespace avmplus { namespace NativeID {

extern const uint32_t shell_toplevel_abc_class_count;
extern const uint32_t shell_toplevel_abc_script_count;
extern const uint32_t shell_toplevel_abc_method_count;
extern const uint32_t shell_toplevel_abc_length;
extern const uint8_t shell_toplevel_abc_data[];
extern const char* const shell_toplevel_versioned_uris[];
AVMTHUNK_DECLARE_NATIVE_INITIALIZER(shell_toplevel)

/* classes */
const uint32_t abcclass_avmplus_ITest = 0;
const uint32_t abcclass_avmplus_CTest = 1;
const uint32_t abcclass_avmplus_MI = 2;
const uint32_t abcclass_avmplus_System = 3;
const uint32_t abcclass_avmplus_File = 4;
const uint32_t abcclass_flash_system_Capabilities = 5;
const uint32_t abcclass_avmshell_public_class = 6;
const uint32_t abcclass_avmshell_public_class_FP_9_0 = 7;
const uint32_t abcclass_avmshell_public_class_AIR_1_0 = 8;
const uint32_t abcclass_avmshell_public_class_FP_10_0 = 9;
const uint32_t abcclass_avmshell_public_class_AIR_1_5 = 10;
const uint32_t abcclass_avmshell_public_class_AIR_1_5_1 = 11;
const uint32_t abcclass_avmshell_public_class_FP_10_0_32 = 12;
const uint32_t abcclass_avmshell_public_class_AIR_1_5_2 = 13;
const uint32_t abcclass_avmshell_public_class_AIR_1_0_FP_10_0 = 14;
const uint32_t abcclass_avmshell_public_class_AIR_1_5_2_FP_9_0 = 15;
const uint32_t abcclass_avmshell_public_class_AIR_1_5_1_FP_10_0_AIR_1_5_2 = 16;
const uint32_t abcclass_avmshell_public_class_FP_10_0_32_FP_9_0_AIR_1_0_FP_10_0 = 17;
const uint32_t abcclass_avmshell_public_interface = 18;
const uint32_t abcclass_avmshell_public_interface_FP_9_0 = 19;
const uint32_t abcclass_avmshell_public_interface_AIR_1_0 = 20;
const uint32_t abcclass_avmshell_public_interface_FP_10_0 = 21;
const uint32_t abcclass_avmshell_public_interface_AIR_1_5 = 22;
const uint32_t abcclass_avmshell_public_interface_AIR_1_5_1 = 23;
const uint32_t abcclass_avmshell_public_interface_FP_10_0_32 = 24;
const uint32_t abcclass_avmshell_public_interface_AIR_1_5_2 = 25;
const uint32_t abcclass_avmshell_public_interface_AIR_1_0_FP_10_0 = 26;
const uint32_t abcclass_avmshell_public_interface_AIR_1_5_2_FP_9_0 = 27;
const uint32_t abcclass_avmshell_public_interface_AIR_1_5_1_FP_10_0_AIR_1_5_2 = 28;
const uint32_t abcclass_avmshell_public_interface_FP_10_0_32_FP_9_0_AIR_1_0_FP_10_0 = 29;
const uint32_t abcclass_avmplus_Domain = 30;
const uint32_t abcclass_flash_sampler_StackFrame = 31;
const uint32_t abcclass_flash_sampler_Sample = 32;
const uint32_t abcclass_flash_sampler_NewObjectSample = 33;
const uint32_t abcclass_flash_sampler_DeleteObjectSample = 34;
const uint32_t abcclass_flash_trace_Trace = 35;
const uint32_t abcclass_flash_utils_Dictionary = 36;
const uint32_t abcclass_flash_utils_Endian = 37;
const uint32_t abcclass_avmplus_JObject = 38;

/* methods */
const uint32_t avmplus_MI_plus = 49;
const uint32_t avmplus_System_exit = 52;
const uint32_t avmplus_System_exec = 53;
const uint32_t avmplus_System_getAvmplusVersion = 54;
const uint32_t avmplus_System_getFeatures = 55;
const uint32_t avmplus_System_getRunmode = 56;
const uint32_t avmplus_System_trace = 57;
const uint32_t avmplus_System_write = 58;
const uint32_t avmplus_System_debugger = 59;
const uint32_t avmplus_System_isDebugger = 60;
const uint32_t avmplus_System_getTimer = 61;
const uint32_t avmplus_System_private_getArgv = 62;
const uint32_t avmplus_System_readLine = 63;
const uint32_t avmplus_System_totalMemory_get = 64;
const uint32_t avmplus_System_freeMemory_get = 65;
const uint32_t avmplus_System_privateMemory_get = 66;
const uint32_t avmplus_System_forceFullCollection = 67;
const uint32_t avmplus_System_queueCollection = 68;
const uint32_t avmplus_System_ns_example_nstest = 69;
const uint32_t avmplus_System_isGlobal = 70;
const uint32_t avmplus_System_swfVersion_get = 71;
const uint32_t avmplus_System_apiVersion_get = 72;
const uint32_t avmplus_System_disposeXML = 73;
const uint32_t avmplus_File_exists = 76;
const uint32_t avmplus_File_read = 77;
const uint32_t avmplus_File_write = 78;
const uint32_t avmplus_File_readByteArray = 79;
const uint32_t avmplus_File_writeByteArray = 80;
const uint32_t avmplus_Domain_currentDomain_get = 172;
const uint32_t avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get = 173;
const uint32_t avmplus_Domain_private_init = 174;
const uint32_t avmplus_Domain_loadBytes = 176;
const uint32_t avmplus_Domain_getClass = 177;
const uint32_t avmplus_Domain_domainMemory_get = 179;
const uint32_t avmplus_Domain_domainMemory_set = 180;
const uint32_t native_script_function_flash_sampler_getMasterString = 182;
const uint32_t native_script_function_flash_sampler_getSavedThis = 183;
const uint32_t native_script_function_flash_sampler_getLexicalScopes = 184;
const uint32_t native_script_function_flash_sampler_isGetterSetter = 185;
const uint32_t native_script_function_flash_sampler__getInvocationCount = 186;
const uint32_t native_script_function_flash_sampler_getSampleCount = 190;
const uint32_t native_script_function_flash_sampler_getSamples = 191;
const uint32_t native_script_function_flash_sampler_getMemberNames = 192;
const uint32_t native_script_function_flash_sampler_getSize = 193;
const uint32_t native_script_function_flash_sampler__setSamplerCallback = 194;
const uint32_t native_script_function_flash_sampler_sampleInternalAllocs = 197;
const uint32_t native_script_function_flash_sampler_pauseSampling = 198;
const uint32_t native_script_function_flash_sampler_stopSampling = 199;
const uint32_t native_script_function_flash_sampler_startSampling = 200;
const uint32_t native_script_function_flash_sampler_clearSamples = 201;
const uint32_t flash_sampler_NewObjectSample_object_get = 208;
const uint32_t flash_sampler_NewObjectSample_size_get = 209;
const uint32_t flash_trace_Trace_setLevel = 215;
const uint32_t flash_trace_Trace_getLevel = 216;
const uint32_t flash_trace_Trace_setListener = 217;
const uint32_t flash_trace_Trace_getListener = 218;
const uint32_t flash_utils_Dictionary_private_init = 222;
const uint32_t avmplus_JObject_create = 229;
const uint32_t avmplus_JObject_createArray = 230;
const uint32_t avmplus_JObject_toArray = 231;
const uint32_t avmplus_JObject_constructorSignature = 232;
const uint32_t avmplus_JObject_methodSignature = 233;
const uint32_t avmplus_JObject_fieldSignature = 234;

extern AvmBox avmplus_Domain_currentDomain_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_Domain_private_init_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_Domain_loadBytes_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_Domain_getClass_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_Domain_domainMemory_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_Domain_domainMemory_set_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_sampler_NewObjectSample_object_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern double flash_sampler_NewObjectSample_size_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox native_script_function_flash_sampler_clearSamples_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox native_script_function_flash_sampler_startSampling_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox native_script_function_flash_sampler_stopSampling_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox native_script_function_flash_sampler_pauseSampling_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox native_script_function_flash_sampler_sampleInternalAllocs_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox native_script_function_flash_sampler__setSamplerCallback_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern double native_script_function_flash_sampler_getSize_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox native_script_function_flash_sampler_getMemberNames_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox native_script_function_flash_sampler_getSamples_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern double native_script_function_flash_sampler_getSampleCount_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern double native_script_function_flash_sampler__getInvocationCount_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox native_script_function_flash_sampler_isGetterSetter_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox native_script_function_flash_sampler_getLexicalScopes_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox native_script_function_flash_sampler_getSavedThis_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox native_script_function_flash_sampler_getMasterString_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_trace_Trace_setLevel_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_trace_Trace_getLevel_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_trace_Trace_setListener_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_trace_Trace_getListener_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_utils_Dictionary_private_init_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_JObject_create_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_JObject_createArray_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_JObject_toArray_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_JObject_constructorSignature_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_JObject_methodSignature_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_JObject_fieldSignature_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern double avmplus_MI_plus_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_exit_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_exec_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_getAvmplusVersion_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_getFeatures_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_getRunmode_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_trace_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_write_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_debugger_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_isDebugger_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_getTimer_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_private_getArgv_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_readLine_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern double avmplus_System_totalMemory_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern double avmplus_System_freeMemory_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern double avmplus_System_privateMemory_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_forceFullCollection_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_queueCollection_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_ns_example_nstest_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_isGlobal_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_swfVersion_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_apiVersion_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_disposeXML_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_File_exists_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_File_read_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_File_write_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_File_readByteArray_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_File_writeByteArray_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);

#ifdef VMCFG_INDIRECT_NATIVE_THUNKS

extern AvmBox shell_toplevel_s2a_oos_rest_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_JObject_methodSignature_thunk  shell_toplevel_s2a_oos_rest_thunk

extern AvmBox shell_toplevel_func_s2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_flash_sampler_getMasterString_thunk  shell_toplevel_func_s2a_os_thunk

extern AvmBox shell_toplevel_func_v2a_oo_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_flash_sampler__setSamplerCallback_thunk  shell_toplevel_func_v2a_oo_thunk

extern double shell_toplevel_d2d_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_System_freeMemory_get_thunk  shell_toplevel_d2d_o_thunk
#define avmplus_System_privateMemory_get_thunk  shell_toplevel_d2d_o_thunk
#define avmplus_System_totalMemory_get_thunk  shell_toplevel_d2d_o_thunk
#define flash_sampler_NewObjectSample_size_get_thunk  shell_toplevel_d2d_o_thunk

extern AvmBox shell_toplevel_a2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_Domain_getClass_thunk  shell_toplevel_a2a_os_thunk
#define avmplus_File_readByteArray_thunk  shell_toplevel_a2a_os_thunk

extern AvmBox shell_toplevel_func_b2a_oao_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_flash_sampler_isGetterSetter_thunk  shell_toplevel_func_b2a_oao_thunk

extern AvmBox shell_toplevel_a2a_oo_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_JObject_toArray_thunk  shell_toplevel_a2a_oo_thunk
#define flash_trace_Trace_setListener_thunk  shell_toplevel_a2a_oo_thunk

extern AvmBox shell_toplevel_s2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_System_getAvmplusVersion_thunk  shell_toplevel_s2a_o_thunk
#define avmplus_System_getFeatures_thunk  shell_toplevel_s2a_o_thunk
#define avmplus_System_getRunmode_thunk  shell_toplevel_s2a_o_thunk
#define avmplus_System_readLine_thunk  shell_toplevel_s2a_o_thunk

extern AvmBox shell_toplevel_func_v2a_ob_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_flash_sampler_sampleInternalAllocs_thunk  shell_toplevel_func_v2a_ob_thunk

extern AvmBox shell_toplevel_v2a_oss_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_File_write_thunk  shell_toplevel_v2a_oss_thunk

extern double shell_toplevel_func_d2d_oa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_flash_sampler_getSize_thunk  shell_toplevel_func_d2d_oa_thunk

extern AvmBox shell_toplevel_func_v2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_flash_sampler_clearSamples_thunk  shell_toplevel_func_v2a_o_thunk
#define native_script_function_flash_sampler_pauseSampling_thunk  shell_toplevel_func_v2a_o_thunk
#define native_script_function_flash_sampler_startSampling_thunk  shell_toplevel_func_v2a_o_thunk
#define native_script_function_flash_sampler_stopSampling_thunk  shell_toplevel_func_v2a_o_thunk

extern AvmBox shell_toplevel_u2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get_thunk  shell_toplevel_u2a_o_thunk
#define avmplus_System_getTimer_thunk  shell_toplevel_u2a_o_thunk

extern AvmBox shell_toplevel_s2a_os_rest_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_JObject_constructorSignature_thunk  shell_toplevel_s2a_os_rest_thunk

extern double shell_toplevel_func_d2d_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_flash_sampler_getSampleCount_thunk  shell_toplevel_func_d2d_o_thunk

extern AvmBox shell_toplevel_i2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_System_apiVersion_get_thunk  shell_toplevel_i2a_o_thunk
#define avmplus_System_swfVersion_get_thunk  shell_toplevel_i2a_o_thunk

extern AvmBox shell_toplevel_s2a_oos_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_JObject_fieldSignature_thunk  shell_toplevel_s2a_oos_thunk

extern AvmBox shell_toplevel_i2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_System_exec_thunk  shell_toplevel_i2a_os_thunk

extern AvmBox shell_toplevel_b2a_oa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_System_isGlobal_thunk  shell_toplevel_b2a_oa_thunk

extern AvmBox shell_toplevel_s2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_File_read_thunk  shell_toplevel_s2a_os_thunk

extern AvmBox shell_toplevel_func_a2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_flash_sampler_getSamples_thunk  shell_toplevel_func_a2a_o_thunk

extern AvmBox shell_toplevel_a2a_os_rest_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_JObject_create_thunk  shell_toplevel_a2a_os_rest_thunk

extern AvmBox shell_toplevel_func_a2a_oo_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_flash_sampler_getLexicalScopes_thunk  shell_toplevel_func_a2a_oo_thunk
#define native_script_function_flash_sampler_getSavedThis_thunk  shell_toplevel_func_a2a_oo_thunk

extern AvmBox shell_toplevel_b2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_File_exists_thunk  shell_toplevel_b2a_os_thunk

extern AvmBox shell_toplevel_a2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_Domain_currentDomain_get_thunk  shell_toplevel_a2a_o_thunk
#define avmplus_Domain_domainMemory_get_thunk  shell_toplevel_a2a_o_thunk
#define avmplus_System_private_getArgv_thunk  shell_toplevel_a2a_o_thunk
#define flash_sampler_NewObjectSample_object_get_thunk  shell_toplevel_a2a_o_thunk
#define flash_trace_Trace_getListener_thunk  shell_toplevel_a2a_o_thunk

extern AvmBox shell_toplevel_a2a_oou_opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_Domain_loadBytes_thunk  shell_toplevel_a2a_oou_opti0_thunk

extern AvmBox shell_toplevel_v2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_System_debugger_thunk  shell_toplevel_v2a_o_thunk
#define avmplus_System_forceFullCollection_thunk  shell_toplevel_v2a_o_thunk
#define avmplus_System_ns_example_nstest_thunk  shell_toplevel_v2a_o_thunk
#define avmplus_System_queueCollection_thunk  shell_toplevel_v2a_o_thunk

extern double shell_toplevel_d2d_od_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_MI_plus_thunk  shell_toplevel_d2d_od_thunk

extern AvmBox shell_toplevel_v2a_ob_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define flash_utils_Dictionary_private_init_thunk  shell_toplevel_v2a_ob_thunk

extern AvmBox shell_toplevel_i2a_oi_opti2_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define flash_trace_Trace_getLevel_thunk  shell_toplevel_i2a_oi_opti2_thunk

extern AvmBox shell_toplevel_a2a_oii_opti2_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define flash_trace_Trace_setLevel_thunk  shell_toplevel_a2a_oii_opti2_thunk

extern AvmBox shell_toplevel_b2a_oso_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_File_writeByteArray_thunk  shell_toplevel_b2a_oso_thunk

extern AvmBox shell_toplevel_a2a_ooio_optakAvmThunkNull_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_JObject_createArray_thunk  shell_toplevel_a2a_ooio_optakAvmThunkNull_thunk

extern AvmBox shell_toplevel_v2a_oo_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_Domain_domainMemory_set_thunk  shell_toplevel_v2a_oo_thunk
#define avmplus_Domain_private_init_thunk  shell_toplevel_v2a_oo_thunk
#define avmplus_System_disposeXML_thunk  shell_toplevel_v2a_oo_thunk
#define avmplus_System_trace_thunk  shell_toplevel_v2a_oo_thunk

extern AvmBox shell_toplevel_b2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_System_isDebugger_thunk  shell_toplevel_b2a_o_thunk

extern AvmBox shell_toplevel_v2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_System_write_thunk  shell_toplevel_v2a_os_thunk

extern AvmBox shell_toplevel_v2a_oi_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_System_exit_thunk  shell_toplevel_v2a_oi_thunk

extern double shell_toplevel_func_d2d_oaou_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_flash_sampler__getInvocationCount_thunk  shell_toplevel_func_d2d_oaou_thunk

extern AvmBox shell_toplevel_func_a2a_oab_optbfalse_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_flash_sampler_getMemberNames_thunk  shell_toplevel_func_a2a_oab_optbfalse_thunk

#endif // VMCFG_INDIRECT_NATIVE_THUNKS

class SlotOffsetsAndAsserts;
// avmplus::MI$
//-----------------------------------------------------------
class _avmshell_MIClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_MIClass \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::_avmshell_MIClassSlots EmptySlotsStruct_MIClass
//-----------------------------------------------------------

// avmplus::MI
//-----------------------------------------------------------
class _avmshell_MIObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_MIObject \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::_avmshell_MIObjectSlots EmptySlotsStruct_MIObject
//-----------------------------------------------------------

// avmplus::System$
//-----------------------------------------------------------
class _avmshell_SystemClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE ArrayObject* get_argv() const { return m_argv; }
private:
    DRCWB(ArrayObject*) m_argv;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceLocation(&m_argv);
    }
};
#define DECLARE_SLOTS_SystemClass \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE ArrayObject* get_argv() const { return m_slots_SystemClass.get_argv(); } \
    private: \
        avmplus::NativeID::_avmshell_SystemClassSlots m_slots_SystemClass
//-----------------------------------------------------------

// avmplus::File$
//-----------------------------------------------------------
class _avmshell_FileClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_FileClass \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::_avmshell_FileClassSlots EmptySlotsStruct_FileClass
//-----------------------------------------------------------

// avmplus::Domain$
//-----------------------------------------------------------
class DomainClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_DomainClass
};
#define DECLARE_SLOTS_DomainClass \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::DomainClassSlots EmptySlotsStruct_DomainClass
//-----------------------------------------------------------

// avmplus::Domain
//-----------------------------------------------------------
class DomainObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_DomainObject
};
#define DECLARE_SLOTS_DomainObject \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::DomainObjectSlots EmptySlotsStruct_DomainObject
//-----------------------------------------------------------

// flash.sampler::StackFrame$
//-----------------------------------------------------------
class StackFrameClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_StackFrameClass \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::StackFrameClassSlots EmptySlotsStruct_StackFrameClass
//-----------------------------------------------------------

// flash.sampler::StackFrame
//-----------------------------------------------------------
class StackFrameObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE uint32_t get_line() const { return m_line; }
    REALLY_INLINE void set_line(uint32_t newVal) { m_line = newVal; }
    REALLY_INLINE AvmString get_name() const { return m_name; }
    REALLY_INLINE void set_name(AvmString newVal) { m_name = newVal; }
    REALLY_INLINE AvmString get_file() const { return m_file; }
    REALLY_INLINE void set_file(AvmString newVal) { m_file = newVal; }
    REALLY_INLINE double get_scriptID() const { return m_scriptID; }
    REALLY_INLINE void set_scriptID(double newVal) { m_scriptID = newVal; }
private:
    uint32_t m_line;
    DRCWB(AvmString) m_name;
    DRCWB(AvmString) m_file;
    double m_scriptID;
};
#define DECLARE_SLOTS_StackFrameObject \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE uint32_t get_line() const { return m_slots_StackFrameObject.get_line(); } \
        REALLY_INLINE void set_line(uint32_t newVal) { m_slots_StackFrameObject.set_line(newVal); } \
        REALLY_INLINE AvmString get_name() const { return m_slots_StackFrameObject.get_name(); } \
        REALLY_INLINE void set_name(AvmString newVal) { m_slots_StackFrameObject.set_name(newVal); } \
        REALLY_INLINE AvmString get_file() const { return m_slots_StackFrameObject.get_file(); } \
        REALLY_INLINE void set_file(AvmString newVal) { m_slots_StackFrameObject.set_file(newVal); } \
        REALLY_INLINE double get_scriptID() const { return m_slots_StackFrameObject.get_scriptID(); } \
        REALLY_INLINE void set_scriptID(double newVal) { m_slots_StackFrameObject.set_scriptID(newVal); } \
    private: \
        avmplus::NativeID::StackFrameObjectSlots m_slots_StackFrameObject
//-----------------------------------------------------------

// flash.sampler::Sample$
//-----------------------------------------------------------
class SampleClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_SampleClass \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::SampleClassSlots EmptySlotsStruct_SampleClass
//-----------------------------------------------------------

// flash.sampler::Sample
//-----------------------------------------------------------
class SampleObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE ArrayObject* get_stack() const { return m_stack; }
    REALLY_INLINE void set_stack(ArrayObject* newVal) { m_stack = newVal; }
    REALLY_INLINE double get_time() const { return m_time; }
    REALLY_INLINE void set_time(double newVal) { m_time = newVal; }
private:
    DRCWB(ArrayObject*) m_stack;
    double m_time;
};
#define DECLARE_SLOTS_SampleObject \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE ArrayObject* get_stack() const { return m_slots_SampleObject.get_stack(); } \
        REALLY_INLINE void set_stack(ArrayObject* newVal) { m_slots_SampleObject.set_stack(newVal); } \
        REALLY_INLINE double get_time() const { return m_slots_SampleObject.get_time(); } \
        REALLY_INLINE void set_time(double newVal) { m_slots_SampleObject.set_time(newVal); } \
    private: \
        avmplus::NativeID::SampleObjectSlots m_slots_SampleObject
//-----------------------------------------------------------

// flash.sampler::NewObjectSample$
//-----------------------------------------------------------
class NewObjectSampleClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_NewObjectSampleClass \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::NewObjectSampleClassSlots EmptySlotsStruct_NewObjectSampleClass
//-----------------------------------------------------------

// flash.sampler::NewObjectSample
//-----------------------------------------------------------
class NewObjectSampleObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE ClassClosure* get_type() const { return m_type; }
    REALLY_INLINE void set_type(ClassClosure* newVal) { m_type = newVal; }
    REALLY_INLINE double get_id() const { return m_id; }
    REALLY_INLINE void set_id(double newVal) { m_id = newVal; }
private:
    DRCWB(ClassClosure*) m_type;
    double m_id;
};
#define DECLARE_SLOTS_NewObjectSampleObject \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE ClassClosure* get_type() const { return m_slots_NewObjectSampleObject.get_type(); } \
        REALLY_INLINE void set_type(ClassClosure* newVal) { m_slots_NewObjectSampleObject.set_type(newVal); } \
        REALLY_INLINE double get_id() const { return m_slots_NewObjectSampleObject.get_id(); } \
        REALLY_INLINE void set_id(double newVal) { m_slots_NewObjectSampleObject.set_id(newVal); } \
    private: \
        avmplus::NativeID::NewObjectSampleObjectSlots m_slots_NewObjectSampleObject
//-----------------------------------------------------------

// flash.sampler::DeleteObjectSample$
//-----------------------------------------------------------
class DeleteObjectSampleClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_DeleteObjectSampleClass \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::DeleteObjectSampleClassSlots EmptySlotsStruct_DeleteObjectSampleClass
//-----------------------------------------------------------

// flash.sampler::DeleteObjectSample
//-----------------------------------------------------------
class DeleteObjectSampleObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE double get_id() const { return m_id; }
    REALLY_INLINE void set_id(double newVal) { m_id = newVal; }
    REALLY_INLINE double get_size() const { return m_size; }
    REALLY_INLINE void set_size(double newVal) { m_size = newVal; }
private:
    double m_id;
    double m_size;
};
#define DECLARE_SLOTS_DeleteObjectSampleObject \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE double get_id() const { return m_slots_DeleteObjectSampleObject.get_id(); } \
        REALLY_INLINE void set_id(double newVal) { m_slots_DeleteObjectSampleObject.set_id(newVal); } \
        REALLY_INLINE double get_size() const { return m_slots_DeleteObjectSampleObject.get_size(); } \
        REALLY_INLINE void set_size(double newVal) { m_slots_DeleteObjectSampleObject.set_size(newVal); } \
    private: \
        avmplus::NativeID::DeleteObjectSampleObjectSlots m_slots_DeleteObjectSampleObject
//-----------------------------------------------------------

// flash.trace::Trace$
//-----------------------------------------------------------
class TraceClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE int32_t get_OFF() const { return m_OFF; }
    REALLY_INLINE int32_t get_METHODS() const { return m_METHODS; }
    REALLY_INLINE int32_t get_METHODS_WITH_ARGS() const { return m_METHODS_WITH_ARGS; }
    REALLY_INLINE int32_t get_METHODS_AND_LINES() const { return m_METHODS_AND_LINES; }
    REALLY_INLINE int32_t get_METHODS_AND_LINES_WITH_ARGS() const { return m_METHODS_AND_LINES_WITH_ARGS; }
    REALLY_INLINE AvmBox get_FILE() const { return m_FILE; }
    REALLY_INLINE AvmBox get_LISTENER() const { return m_LISTENER; }
private:
    int32_t m_OFF;
    int32_t m_METHODS;
    int32_t m_METHODS_WITH_ARGS;
    int32_t m_METHODS_AND_LINES;
    int32_t m_METHODS_AND_LINES_WITH_ARGS;
    ATOM_WB m_FILE;
    ATOM_WB m_LISTENER;
};
#define DECLARE_SLOTS_TraceClass \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE int32_t get_OFF() const { return m_slots_TraceClass.get_OFF(); } \
        REALLY_INLINE int32_t get_METHODS() const { return m_slots_TraceClass.get_METHODS(); } \
        REALLY_INLINE int32_t get_METHODS_WITH_ARGS() const { return m_slots_TraceClass.get_METHODS_WITH_ARGS(); } \
        REALLY_INLINE int32_t get_METHODS_AND_LINES() const { return m_slots_TraceClass.get_METHODS_AND_LINES(); } \
        REALLY_INLINE int32_t get_METHODS_AND_LINES_WITH_ARGS() const { return m_slots_TraceClass.get_METHODS_AND_LINES_WITH_ARGS(); } \
        REALLY_INLINE AvmBox get_FILE() const { return m_slots_TraceClass.get_FILE(); } \
        REALLY_INLINE AvmBox get_LISTENER() const { return m_slots_TraceClass.get_LISTENER(); } \
    private: \
        avmplus::NativeID::TraceClassSlots m_slots_TraceClass
//-----------------------------------------------------------

// flash.utils::Dictionary$
//-----------------------------------------------------------
class DictionaryClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_DictionaryClass
};
#define DECLARE_SLOTS_DictionaryClass \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::DictionaryClassSlots EmptySlotsStruct_DictionaryClass
//-----------------------------------------------------------

// flash.utils::Dictionary
//-----------------------------------------------------------
class DictionaryObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
#define GC_TRIVIAL_TRACER_DictionaryObject
};
#define DECLARE_SLOTS_DictionaryObject \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::DictionaryObjectSlots EmptySlotsStruct_DictionaryObject
//-----------------------------------------------------------

// avmplus::JObject$
//-----------------------------------------------------------
class JObjectClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_JObjectClass \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::JObjectClassSlots EmptySlotsStruct_JObjectClass
//-----------------------------------------------------------

// avmplus::JObject
//-----------------------------------------------------------
class JObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_JObject \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::JObjectSlots EmptySlotsStruct_JObject
//-----------------------------------------------------------

} }
