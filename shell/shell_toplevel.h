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
    class ScriptObject; // avmplus::File
    class ScriptObject; // C.stdio::__stdio
    class ScriptObject; // C.socket::__socket
    class ScriptObject; // avmplus::System
    class ScriptObject; // avmplus::OperatingSystem
    class ScriptObject; // avmplus::FileSystem
    class ScriptObject; // flash.trace::Trace
    class ScriptObject; // C.stdlib::__stdlib
    class ScriptObject; // C.unistd::__unistd
    class ScriptObject; // C.string::__string
    class ScriptObject; // C.errno::__errno
    class StackFrameClass; // flash.sampler::StackFrame$
    class StackFrameObject; // flash.sampler::StackFrame
    class String; // String
    class TraceClass; // flash.trace::Trace$
}

namespace avmshell {
    class CErrnoClass; // C.errno::__errno$
    class CSocketClass; // C.socket::__socket$
    class CStringClass; // C.string::__string$
    class FileClass; // avmplus::File$
    class FileSystemClass; // avmplus::FileSystem$
    class OperatingSystemClass; // avmplus::OperatingSystem$
    class StdioClass; // C.stdio::__stdio$
    class StdlibClass; // C.stdlib::__stdlib$
    class SystemClass; // avmplus::System$
    class UnistdClass; // C.unistd::__unistd$
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
const uint32_t abcclass_avmplus_File = 0;
const uint32_t abcclass_flash_system_Capabilities = 1;
const uint32_t abcclass_avmplus_Domain = 2;
const uint32_t abcclass_flash_sampler_StackFrame = 3;
const uint32_t abcclass_flash_sampler_Sample = 4;
const uint32_t abcclass_flash_sampler_NewObjectSample = 5;
const uint32_t abcclass_flash_sampler_DeleteObjectSample = 6;
const uint32_t abcclass_flash_trace_Trace = 7;
const uint32_t abcclass_flash_utils_Dictionary = 8;
const uint32_t abcclass_C_stdlib___stdlib = 9;
const uint32_t abcclass_C_unistd___unistd = 10;
const uint32_t abcclass_C_string___string = 11;
const uint32_t abcclass_C_errno___errno = 12;
const uint32_t abcclass_C_stdio___stdio = 13;
const uint32_t abcclass_C_socket___socket = 14;
const uint32_t abcclass_avmplus_System = 15;
const uint32_t abcclass_avmplus_OperatingSystem = 16;
const uint32_t abcclass_avmplus_FileSystem = 17;
const uint32_t abcclass_flash_utils_Endian = 18;
const uint32_t abcclass_avmplus_JObject = 19;

/* methods */
const uint32_t avmplus_File_exists = 7;
const uint32_t avmplus_File_read = 8;
const uint32_t avmplus_File_write = 9;
const uint32_t avmplus_File_readByteArray = 10;
const uint32_t avmplus_File_writeByteArray = 11;
const uint32_t avmplus_Domain_currentDomain_get = 19;
const uint32_t avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get = 20;
const uint32_t avmplus_Domain_private_init = 21;
const uint32_t avmplus_Domain_loadBytes = 23;
const uint32_t avmplus_Domain_getClass = 24;
const uint32_t avmplus_Domain_domainMemory_get = 26;
const uint32_t avmplus_Domain_domainMemory_set = 27;
const uint32_t native_script_function_flash_sampler_getMasterString = 29;
const uint32_t native_script_function_flash_sampler_getSavedThis = 30;
const uint32_t native_script_function_flash_sampler_getLexicalScopes = 31;
const uint32_t native_script_function_flash_sampler_isGetterSetter = 32;
const uint32_t native_script_function_flash_sampler__getInvocationCount = 33;
const uint32_t native_script_function_flash_sampler_getSampleCount = 37;
const uint32_t native_script_function_flash_sampler_getSamples = 38;
const uint32_t native_script_function_flash_sampler_getMemberNames = 39;
const uint32_t native_script_function_flash_sampler_getSize = 40;
const uint32_t native_script_function_flash_sampler__setSamplerCallback = 41;
const uint32_t native_script_function_flash_sampler_sampleInternalAllocs = 44;
const uint32_t native_script_function_flash_sampler_pauseSampling = 45;
const uint32_t native_script_function_flash_sampler_stopSampling = 46;
const uint32_t native_script_function_flash_sampler_startSampling = 47;
const uint32_t native_script_function_flash_sampler_clearSamples = 48;
const uint32_t flash_sampler_NewObjectSample_object_get = 55;
const uint32_t flash_sampler_NewObjectSample_size_get = 56;
const uint32_t flash_trace_Trace_setLevel = 62;
const uint32_t flash_trace_Trace_getLevel = 63;
const uint32_t flash_trace_Trace_setListener = 64;
const uint32_t flash_trace_Trace_getListener = 65;
const uint32_t flash_utils_Dictionary_private_init = 69;
const uint32_t C_stdlib___stdlib_EXIT_SUCCESS_get = 80;
const uint32_t C_stdlib___stdlib_EXIT_FAILURE_get = 81;
const uint32_t C_stdlib___stdlib_abort = 82;
const uint32_t C_stdlib___stdlib_exit = 83;
const uint32_t C_stdlib___stdlib_getenv = 84;
const uint32_t C_stdlib___stdlib_setenv = 85;
const uint32_t C_stdlib___stdlib_unsetenv = 86;
const uint32_t C_stdlib___stdlib_realpath = 87;
const uint32_t C_stdlib___stdlib___system = 88;
const uint32_t C_unistd___unistd_F_OK_get = 103;
const uint32_t C_unistd___unistd_X_OK_get = 104;
const uint32_t C_unistd___unistd_W_OK_get = 105;
const uint32_t C_unistd___unistd_R_OK_get = 106;
const uint32_t C_unistd___unistd_S_IFMT_get = 107;
const uint32_t C_unistd___unistd_S_IFIFO_get = 108;
const uint32_t C_unistd___unistd_S_IFCHR_get = 109;
const uint32_t C_unistd___unistd_S_IFDIR_get = 110;
const uint32_t C_unistd___unistd_S_IFBLK_get = 111;
const uint32_t C_unistd___unistd_S_IFREG_get = 112;
const uint32_t C_unistd___unistd_S_IFLNK_get = 113;
const uint32_t C_unistd___unistd_S_IFSOCK_get = 114;
const uint32_t C_unistd___unistd_S_IRWXU_get = 115;
const uint32_t C_unistd___unistd_S_IRUSR_get = 116;
const uint32_t C_unistd___unistd_S_IWUSR_get = 117;
const uint32_t C_unistd___unistd_S_IXUSR_get = 118;
const uint32_t C_unistd___unistd_S_IRWXG_get = 119;
const uint32_t C_unistd___unistd_S_IRGRP_get = 120;
const uint32_t C_unistd___unistd_S_IWGRP_get = 121;
const uint32_t C_unistd___unistd_S_IXGRP_get = 122;
const uint32_t C_unistd___unistd_S_IRWXO_get = 123;
const uint32_t C_unistd___unistd_S_IROTH_get = 124;
const uint32_t C_unistd___unistd_S_IWOTH_get = 125;
const uint32_t C_unistd___unistd_S_IXOTH_get = 126;
const uint32_t C_unistd___unistd_S_IREAD_get = 127;
const uint32_t C_unistd___unistd_S_IWRITE_get = 128;
const uint32_t C_unistd___unistd_S_IEXEC_get = 129;
const uint32_t C_unistd___unistd_access = 130;
const uint32_t C_unistd___unistd_chdir = 131;
const uint32_t C_unistd___unistd_chmod = 132;
const uint32_t C_unistd___unistd_getcwd = 133;
const uint32_t C_unistd___unistd_gethostname = 134;
const uint32_t C_unistd___unistd_getlogin = 135;
const uint32_t C_unistd___unistd_getpid = 136;
const uint32_t C_unistd___unistd_mkdir = 137;
const uint32_t C_unistd___unistd_rmdir = 138;
const uint32_t C_unistd___unistd_sleep = 139;
const uint32_t C_unistd___unistd_unlink = 140;
const uint32_t C_string___string_strerror = 148;
const uint32_t C_string___string_strlen = 149;
const uint32_t C_errno___errno_EDOM_get = 155;
const uint32_t C_errno___errno_EILSEQ_get = 156;
const uint32_t C_errno___errno_ERANGE_get = 157;
const uint32_t C_errno___errno_EPERM_get = 158;
const uint32_t C_errno___errno_ENOENT_get = 159;
const uint32_t C_errno___errno_ESRCH_get = 160;
const uint32_t C_errno___errno_EINTR_get = 161;
const uint32_t C_errno___errno_EIO_get = 162;
const uint32_t C_errno___errno_ENXIO_get = 163;
const uint32_t C_errno___errno_E2BIG_get = 164;
const uint32_t C_errno___errno_ENOEXEC_get = 165;
const uint32_t C_errno___errno_EBADF_get = 166;
const uint32_t C_errno___errno_ECHILD_get = 167;
const uint32_t C_errno___errno_EAGAIN_get = 168;
const uint32_t C_errno___errno_ENOMEM_get = 169;
const uint32_t C_errno___errno_EACCES_get = 170;
const uint32_t C_errno___errno_EFAULT_get = 171;
const uint32_t C_errno___errno_EBUSY_get = 172;
const uint32_t C_errno___errno_EEXIST_get = 173;
const uint32_t C_errno___errno_EXDEV_get = 174;
const uint32_t C_errno___errno_ENODEV_get = 175;
const uint32_t C_errno___errno_ENOTDIR_get = 176;
const uint32_t C_errno___errno_EISDIR_get = 177;
const uint32_t C_errno___errno_EINVAL_get = 178;
const uint32_t C_errno___errno_ENFILE_get = 179;
const uint32_t C_errno___errno_EMFILE_get = 180;
const uint32_t C_errno___errno_ENOTTY_get = 181;
const uint32_t C_errno___errno_EFBIG_get = 182;
const uint32_t C_errno___errno_ENOSPC_get = 183;
const uint32_t C_errno___errno_ESPIPE_get = 184;
const uint32_t C_errno___errno_EROFS_get = 185;
const uint32_t C_errno___errno_EMLINK_get = 186;
const uint32_t C_errno___errno_EPIPE_get = 187;
const uint32_t C_errno___errno_EDEADLK_get = 188;
const uint32_t C_errno___errno_ENAMETOOLONG_get = 189;
const uint32_t C_errno___errno_ENOLCK_get = 190;
const uint32_t C_errno___errno_ENOSYS_get = 191;
const uint32_t C_errno___errno_ENOTEMPTY_get = 192;
const uint32_t C_errno___errno_ENETDOWN_get = 193;
const uint32_t C_errno___errno_ENETUNREACH_get = 194;
const uint32_t C_errno___errno_ENETRESET_get = 195;
const uint32_t C_errno___errno_ECONNABORTED_get = 196;
const uint32_t C_errno___errno_ECONNRESET_get = 197;
const uint32_t C_errno___errno_ENOBUFS_get = 198;
const uint32_t C_errno___errno_EISCONN_get = 199;
const uint32_t C_errno___errno_ENOTCONN_get = 200;
const uint32_t C_errno___errno_ESHUTDOWN_get = 201;
const uint32_t C_errno___errno_ETOOMANYREFS_get = 202;
const uint32_t C_errno___errno_ETIMEDOUT_get = 203;
const uint32_t C_errno___errno_ECONNREFUSED_get = 204;
const uint32_t C_errno___errno_errno_get = 205;
const uint32_t C_errno___errno_errno_set = 206;
const uint32_t C_stdio___stdio_FILENAME_MAX_get = 212;
const uint32_t C_stdio___stdio_PATH_MAX_get = 213;
const uint32_t C_stdio___stdio_remove = 214;
const uint32_t C_stdio___stdio_rename = 215;
const uint32_t C_socket___socket_SOCK_RAW_get = 221;
const uint32_t C_socket___socket_SOCK_STREAM_get = 222;
const uint32_t C_socket___socket_SOCK_DGRAM_get = 223;
const uint32_t C_socket___socket_SO_ACCEPTCONN_get = 224;
const uint32_t C_socket___socket_SO_BROADCAST_get = 225;
const uint32_t C_socket___socket_SO_DONTROUTE_get = 226;
const uint32_t C_socket___socket_SO_KEEPALIVE_get = 227;
const uint32_t C_socket___socket_SO_OOBINLINE_get = 228;
const uint32_t C_socket___socket_SO_RCVBUF_get = 229;
const uint32_t C_socket___socket_SO_RCVTIMEO_get = 230;
const uint32_t C_socket___socket_SO_REUSEADDR_get = 231;
const uint32_t C_socket___socket_SO_SNDBUF_get = 232;
const uint32_t C_socket___socket_SO_SNDTIMEO_get = 233;
const uint32_t C_socket___socket_SO_TYPE_get = 234;
const uint32_t C_socket___socket_SOMAXCONN_get = 235;
const uint32_t C_socket___socket_MSG_CTRUNC_get = 236;
const uint32_t C_socket___socket_MSG_DONTROUTE_get = 237;
const uint32_t C_socket___socket_MSG_OOB_get = 238;
const uint32_t C_socket___socket_MSG_PEEK_get = 239;
const uint32_t C_socket___socket_MSG_TRUNC_get = 240;
const uint32_t C_socket___socket_MSG_WAITALL_get = 241;
const uint32_t C_socket___socket_AF_INET_get = 242;
const uint32_t C_socket___socket_AF_INET6_get = 243;
const uint32_t C_socket___socket_AF_UNSPEC_get = 244;
const uint32_t C_socket___socket_SHUT_RD_get = 245;
const uint32_t C_socket___socket_SHUT_RDWR_get = 246;
const uint32_t C_socket___socket_SHUT_WR_get = 247;
const uint32_t C_socket___socket_IPPROTO_IP_get = 248;
const uint32_t C_socket___socket_IPPROTO_IPV6_get = 249;
const uint32_t C_socket___socket_IPPROTO_ICMP_get = 250;
const uint32_t C_socket___socket_IPPROTO_RAW_get = 251;
const uint32_t C_socket___socket_IPPROTO_TCP_get = 252;
const uint32_t C_socket___socket_IPPROTO_UDP_get = 253;
const uint32_t C_socket___socket_INADDR_ANY_get = 254;
const uint32_t C_socket___socket_INADDR_BROADCAST_get = 255;
const uint32_t C_socket___socket___gethostbyaddr = 256;
const uint32_t C_socket___socket___gethostbyname = 257;
const uint32_t avmplus_System_private_getArgv = 261;
const uint32_t avmplus_System_private_getStartupDirectory = 262;
const uint32_t avmplus_System_apiVersion_get = 263;
const uint32_t avmplus_System_programFilename_get = 266;
const uint32_t avmplus_System_swfVersion_get = 269;
const uint32_t avmplus_System_totalMemory_get = 270;
const uint32_t avmplus_System_freeMemory_get = 271;
const uint32_t avmplus_System_privateMemory_get = 272;
const uint32_t avmplus_System_private_popenRead = 276;
const uint32_t avmplus_System_getAvmplusVersion = 278;
const uint32_t avmplus_System_getFeatures = 280;
const uint32_t avmplus_System_getRunmode = 281;
const uint32_t avmplus_System_getTimer = 282;
const uint32_t avmplus_System_readLine = 283;
const uint32_t avmplus_System_trace = 284;
const uint32_t avmplus_System_write = 285;
const uint32_t avmplus_System_stdinLength_get = 287;
const uint32_t avmplus_System_stdinRead = 289;
const uint32_t avmplus_System_stdinReadAll = 290;
const uint32_t avmplus_System_stdoutWrite = 291;
const uint32_t avmplus_System_debugger = 292;
const uint32_t avmplus_System_isDebugger = 293;
const uint32_t avmplus_System_forceFullCollection = 294;
const uint32_t avmplus_System_queueCollection = 295;
const uint32_t avmplus_System_disposeXML = 296;
const uint32_t avmplus_OperatingSystem_private_getName = 301;
const uint32_t avmplus_OperatingSystem_private_getNodeName = 302;
const uint32_t avmplus_OperatingSystem_private_getRelease = 303;
const uint32_t avmplus_OperatingSystem_private_getVersion = 304;
const uint32_t avmplus_OperatingSystem_private_getMachine = 305;
const uint32_t avmplus_OperatingSystem_private_getVendorVersion = 306;
const uint32_t avmplus_OperatingSystem_private_getSystemLocale = 320;
const uint32_t avmplus_FileSystem_exists = 352;
const uint32_t avmplus_FileSystem_read = 353;
const uint32_t avmplus_FileSystem_write = 354;
const uint32_t avmplus_FileSystem_readByteArray = 355;
const uint32_t avmplus_FileSystem_writeByteArray = 356;
const uint32_t avmplus_FileSystem_getFileMode = 357;
const uint32_t avmplus_FileSystem_getFileSize = 358;
const uint32_t avmplus_FileSystem_getLastModifiedTime = 360;
const uint32_t avmplus_FileSystem_isRegularFile = 368;
const uint32_t avmplus_FileSystem_isDirectory = 370;
const uint32_t avmplus_FileSystem_listFiles = 383;
const uint32_t avmplus_FileSystem_getFreeDiskSpace = 392;
const uint32_t avmplus_FileSystem_getTotalDiskSpace = 393;
const uint32_t avmplus_JObject_create = 401;
const uint32_t avmplus_JObject_createArray = 402;
const uint32_t avmplus_JObject_toArray = 403;
const uint32_t avmplus_JObject_constructorSignature = 404;
const uint32_t avmplus_JObject_methodSignature = 405;
const uint32_t avmplus_JObject_fieldSignature = 406;

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
extern AvmBox C_stdlib___stdlib_EXIT_SUCCESS_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_stdlib___stdlib_EXIT_FAILURE_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_stdlib___stdlib_abort_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_stdlib___stdlib_exit_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_stdlib___stdlib_getenv_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_stdlib___stdlib_setenv_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_stdlib___stdlib_unsetenv_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_stdlib___stdlib_realpath_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_stdlib___stdlib___system_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_F_OK_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_X_OK_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_W_OK_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_R_OK_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_S_IFMT_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_S_IFIFO_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_S_IFCHR_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_S_IFDIR_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_S_IFBLK_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_S_IFREG_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_S_IFLNK_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_S_IFSOCK_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_S_IRWXU_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_S_IRUSR_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_S_IWUSR_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_S_IXUSR_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_S_IRWXG_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_S_IRGRP_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_S_IWGRP_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_S_IXGRP_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_S_IRWXO_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_S_IROTH_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_S_IWOTH_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_S_IXOTH_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_S_IREAD_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_S_IWRITE_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_S_IEXEC_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_access_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_chdir_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_chmod_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_getcwd_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_gethostname_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_getlogin_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_getpid_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_mkdir_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_rmdir_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_sleep_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_unlink_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_string___string_strerror_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_string___string_strlen_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_EDOM_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_EILSEQ_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_ERANGE_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_EPERM_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_ENOENT_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_ESRCH_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_EINTR_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_EIO_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_ENXIO_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_E2BIG_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_ENOEXEC_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_EBADF_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_ECHILD_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_EAGAIN_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_ENOMEM_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_EACCES_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_EFAULT_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_EBUSY_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_EEXIST_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_EXDEV_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_ENODEV_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_ENOTDIR_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_EISDIR_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_EINVAL_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_ENFILE_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_EMFILE_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_ENOTTY_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_EFBIG_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_ENOSPC_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_ESPIPE_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_EROFS_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_EMLINK_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_EPIPE_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_EDEADLK_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_ENAMETOOLONG_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_ENOLCK_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_ENOSYS_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_ENOTEMPTY_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_ENETDOWN_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_ENETUNREACH_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_ENETRESET_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_ECONNABORTED_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_ECONNRESET_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_ENOBUFS_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_EISCONN_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_ENOTCONN_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_ESHUTDOWN_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_ETOOMANYREFS_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_ETIMEDOUT_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_ECONNREFUSED_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_errno_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_errno___errno_errno_set_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_stdio___stdio_FILENAME_MAX_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_stdio___stdio_PATH_MAX_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_stdio___stdio_remove_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_stdio___stdio_rename_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_SOCK_RAW_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_SOCK_STREAM_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_SOCK_DGRAM_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_SO_ACCEPTCONN_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_SO_BROADCAST_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_SO_DONTROUTE_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_SO_KEEPALIVE_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_SO_OOBINLINE_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_SO_RCVBUF_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_SO_RCVTIMEO_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_SO_REUSEADDR_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_SO_SNDBUF_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_SO_SNDTIMEO_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_SO_TYPE_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_SOMAXCONN_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_MSG_CTRUNC_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_MSG_DONTROUTE_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_MSG_OOB_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_MSG_PEEK_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_MSG_TRUNC_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_MSG_WAITALL_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_AF_INET_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_AF_INET6_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_AF_UNSPEC_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_SHUT_RD_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_SHUT_RDWR_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_SHUT_WR_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_IPPROTO_IP_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_IPPROTO_IPV6_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_IPPROTO_ICMP_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_IPPROTO_RAW_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_IPPROTO_TCP_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_IPPROTO_UDP_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_INADDR_ANY_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket_INADDR_BROADCAST_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket___gethostbyaddr_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_socket___socket___gethostbyname_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_private_getArgv_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_private_getStartupDirectory_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_apiVersion_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_programFilename_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_swfVersion_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern double avmplus_System_totalMemory_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern double avmplus_System_freeMemory_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern double avmplus_System_privateMemory_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_private_popenRead_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_getAvmplusVersion_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_getFeatures_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_getRunmode_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_getTimer_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_readLine_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_trace_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_write_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern double avmplus_System_stdinLength_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_stdinRead_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_stdinReadAll_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_stdoutWrite_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_debugger_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_isDebugger_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_forceFullCollection_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_queueCollection_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_disposeXML_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_OperatingSystem_private_getName_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_OperatingSystem_private_getNodeName_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_OperatingSystem_private_getRelease_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_OperatingSystem_private_getVersion_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_OperatingSystem_private_getMachine_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_OperatingSystem_private_getVendorVersion_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_OperatingSystem_private_getSystemLocale_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_FileSystem_exists_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_FileSystem_read_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_FileSystem_write_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_FileSystem_readByteArray_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_FileSystem_writeByteArray_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_FileSystem_getFileMode_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern double avmplus_FileSystem_getFileSize_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_FileSystem_getLastModifiedTime_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_FileSystem_isRegularFile_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_FileSystem_isDirectory_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_FileSystem_listFiles_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern double avmplus_FileSystem_getFreeDiskSpace_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern double avmplus_FileSystem_getTotalDiskSpace_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_JObject_create_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_JObject_createArray_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_JObject_toArray_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_JObject_constructorSignature_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_JObject_methodSignature_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_JObject_fieldSignature_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
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
#define avmplus_System_stdinLength_get_thunk  shell_toplevel_d2d_o_thunk
#define avmplus_System_totalMemory_get_thunk  shell_toplevel_d2d_o_thunk
#define flash_sampler_NewObjectSample_size_get_thunk  shell_toplevel_d2d_o_thunk

extern AvmBox shell_toplevel_a2a_osb_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define C_socket___socket___gethostbyaddr_thunk  shell_toplevel_a2a_osb_thunk
#define C_socket___socket___gethostbyname_thunk  shell_toplevel_a2a_osb_thunk

extern AvmBox shell_toplevel_a2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_Domain_getClass_thunk  shell_toplevel_a2a_os_thunk
#define avmplus_FileSystem_getLastModifiedTime_thunk  shell_toplevel_a2a_os_thunk
#define avmplus_FileSystem_readByteArray_thunk  shell_toplevel_a2a_os_thunk
#define avmplus_File_readByteArray_thunk  shell_toplevel_a2a_os_thunk

extern AvmBox shell_toplevel_func_b2a_oao_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_flash_sampler_isGetterSetter_thunk  shell_toplevel_func_b2a_oao_thunk

extern AvmBox shell_toplevel_u2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define C_string___string_strlen_thunk  shell_toplevel_u2a_os_thunk

extern AvmBox shell_toplevel_a2a_ou_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_System_stdinRead_thunk  shell_toplevel_a2a_ou_thunk

extern AvmBox shell_toplevel_a2a_oo_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_JObject_toArray_thunk  shell_toplevel_a2a_oo_thunk
#define flash_trace_Trace_setListener_thunk  shell_toplevel_a2a_oo_thunk

extern AvmBox shell_toplevel_s2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define C_unistd___unistd_getcwd_thunk  shell_toplevel_s2a_o_thunk
#define C_unistd___unistd_gethostname_thunk  shell_toplevel_s2a_o_thunk
#define C_unistd___unistd_getlogin_thunk  shell_toplevel_s2a_o_thunk
#define avmplus_OperatingSystem_private_getMachine_thunk  shell_toplevel_s2a_o_thunk
#define avmplus_OperatingSystem_private_getName_thunk  shell_toplevel_s2a_o_thunk
#define avmplus_OperatingSystem_private_getNodeName_thunk  shell_toplevel_s2a_o_thunk
#define avmplus_OperatingSystem_private_getRelease_thunk  shell_toplevel_s2a_o_thunk
#define avmplus_OperatingSystem_private_getSystemLocale_thunk  shell_toplevel_s2a_o_thunk
#define avmplus_OperatingSystem_private_getVendorVersion_thunk  shell_toplevel_s2a_o_thunk
#define avmplus_OperatingSystem_private_getVersion_thunk  shell_toplevel_s2a_o_thunk
#define avmplus_System_getAvmplusVersion_thunk  shell_toplevel_s2a_o_thunk
#define avmplus_System_getFeatures_thunk  shell_toplevel_s2a_o_thunk
#define avmplus_System_getRunmode_thunk  shell_toplevel_s2a_o_thunk
#define avmplus_System_private_getStartupDirectory_thunk  shell_toplevel_s2a_o_thunk
#define avmplus_System_programFilename_get_thunk  shell_toplevel_s2a_o_thunk
#define avmplus_System_readLine_thunk  shell_toplevel_s2a_o_thunk

extern AvmBox shell_toplevel_func_v2a_ob_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_flash_sampler_sampleInternalAllocs_thunk  shell_toplevel_func_v2a_ob_thunk

extern AvmBox shell_toplevel_v2a_oss_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_FileSystem_write_thunk  shell_toplevel_v2a_oss_thunk
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

extern AvmBox shell_toplevel_a2a_ooio_optakAvmThunkNull_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_JObject_createArray_thunk  shell_toplevel_a2a_ooio_optakAvmThunkNull_thunk

extern AvmBox shell_toplevel_s2a_os_rest_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_JObject_constructorSignature_thunk  shell_toplevel_s2a_os_rest_thunk

extern AvmBox shell_toplevel_a2a_osb_optbfalse_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_FileSystem_listFiles_thunk  shell_toplevel_a2a_osb_optbfalse_thunk

extern double shell_toplevel_func_d2d_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_flash_sampler_getSampleCount_thunk  shell_toplevel_func_d2d_o_thunk

extern AvmBox shell_toplevel_i2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define C_errno___errno_E2BIG_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EACCES_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EAGAIN_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EBADF_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EBUSY_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ECHILD_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ECONNABORTED_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ECONNREFUSED_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ECONNRESET_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EDEADLK_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EDOM_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EEXIST_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EFAULT_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EFBIG_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EILSEQ_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EINTR_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EINVAL_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EIO_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EISCONN_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EISDIR_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EMFILE_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EMLINK_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENAMETOOLONG_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENETDOWN_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENETRESET_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENETUNREACH_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENFILE_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENOBUFS_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENODEV_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENOENT_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENOEXEC_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENOLCK_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENOMEM_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENOSPC_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENOSYS_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENOTCONN_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENOTDIR_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENOTEMPTY_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENOTTY_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENXIO_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EPERM_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EPIPE_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ERANGE_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EROFS_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ESHUTDOWN_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ESPIPE_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ESRCH_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ETIMEDOUT_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ETOOMANYREFS_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EXDEV_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_errno_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_AF_INET6_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_AF_INET_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_AF_UNSPEC_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_INADDR_ANY_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_INADDR_BROADCAST_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_IPPROTO_ICMP_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_IPPROTO_IPV6_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_IPPROTO_IP_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_IPPROTO_RAW_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_IPPROTO_TCP_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_IPPROTO_UDP_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_MSG_CTRUNC_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_MSG_DONTROUTE_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_MSG_OOB_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_MSG_PEEK_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_MSG_TRUNC_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_MSG_WAITALL_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SHUT_RDWR_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SHUT_RD_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SHUT_WR_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SOCK_DGRAM_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SOCK_RAW_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SOCK_STREAM_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SOMAXCONN_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SO_ACCEPTCONN_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SO_BROADCAST_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SO_DONTROUTE_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SO_KEEPALIVE_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SO_OOBINLINE_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SO_RCVBUF_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SO_RCVTIMEO_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SO_REUSEADDR_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SO_SNDBUF_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SO_SNDTIMEO_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SO_TYPE_get_thunk  shell_toplevel_i2a_o_thunk
#define C_stdio___stdio_FILENAME_MAX_get_thunk  shell_toplevel_i2a_o_thunk
#define C_stdio___stdio_PATH_MAX_get_thunk  shell_toplevel_i2a_o_thunk
#define C_stdlib___stdlib_EXIT_FAILURE_get_thunk  shell_toplevel_i2a_o_thunk
#define C_stdlib___stdlib_EXIT_SUCCESS_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_F_OK_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_R_OK_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IEXEC_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IFBLK_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IFCHR_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IFDIR_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IFIFO_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IFLNK_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IFMT_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IFREG_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IFSOCK_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IREAD_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IRGRP_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IROTH_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IRUSR_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IRWXG_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IRWXO_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IRWXU_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IWGRP_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IWOTH_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IWRITE_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IWUSR_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IXGRP_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IXOTH_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IXUSR_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_W_OK_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_X_OK_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_getpid_thunk  shell_toplevel_i2a_o_thunk
#define avmplus_System_apiVersion_get_thunk  shell_toplevel_i2a_o_thunk
#define avmplus_System_swfVersion_get_thunk  shell_toplevel_i2a_o_thunk

extern double shell_toplevel_d2d_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_FileSystem_getFileSize_thunk  shell_toplevel_d2d_os_thunk
#define avmplus_FileSystem_getFreeDiskSpace_thunk  shell_toplevel_d2d_os_thunk
#define avmplus_FileSystem_getTotalDiskSpace_thunk  shell_toplevel_d2d_os_thunk

extern AvmBox shell_toplevel_i2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define C_stdio___stdio_remove_thunk  shell_toplevel_i2a_os_thunk
#define C_stdlib___stdlib___system_thunk  shell_toplevel_i2a_os_thunk
#define C_stdlib___stdlib_unsetenv_thunk  shell_toplevel_i2a_os_thunk
#define C_unistd___unistd_chdir_thunk  shell_toplevel_i2a_os_thunk
#define C_unistd___unistd_mkdir_thunk  shell_toplevel_i2a_os_thunk
#define C_unistd___unistd_rmdir_thunk  shell_toplevel_i2a_os_thunk
#define C_unistd___unistd_unlink_thunk  shell_toplevel_i2a_os_thunk
#define avmplus_FileSystem_getFileMode_thunk  shell_toplevel_i2a_os_thunk

extern AvmBox shell_toplevel_s2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define C_stdlib___stdlib_getenv_thunk  shell_toplevel_s2a_os_thunk
#define C_stdlib___stdlib_realpath_thunk  shell_toplevel_s2a_os_thunk
#define avmplus_FileSystem_read_thunk  shell_toplevel_s2a_os_thunk
#define avmplus_File_read_thunk  shell_toplevel_s2a_os_thunk
#define avmplus_System_private_popenRead_thunk  shell_toplevel_s2a_os_thunk

extern AvmBox shell_toplevel_func_a2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_flash_sampler_getSamples_thunk  shell_toplevel_func_a2a_o_thunk

extern AvmBox shell_toplevel_a2a_os_rest_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_JObject_create_thunk  shell_toplevel_a2a_os_rest_thunk

extern AvmBox shell_toplevel_func_a2a_oo_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_flash_sampler_getLexicalScopes_thunk  shell_toplevel_func_a2a_oo_thunk
#define native_script_function_flash_sampler_getSavedThis_thunk  shell_toplevel_func_a2a_oo_thunk

extern AvmBox shell_toplevel_b2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_FileSystem_exists_thunk  shell_toplevel_b2a_os_thunk
#define avmplus_FileSystem_isDirectory_thunk  shell_toplevel_b2a_os_thunk
#define avmplus_FileSystem_isRegularFile_thunk  shell_toplevel_b2a_os_thunk
#define avmplus_File_exists_thunk  shell_toplevel_b2a_os_thunk

extern AvmBox shell_toplevel_a2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_Domain_currentDomain_get_thunk  shell_toplevel_a2a_o_thunk
#define avmplus_Domain_domainMemory_get_thunk  shell_toplevel_a2a_o_thunk
#define avmplus_System_private_getArgv_thunk  shell_toplevel_a2a_o_thunk
#define avmplus_System_stdinReadAll_thunk  shell_toplevel_a2a_o_thunk
#define flash_sampler_NewObjectSample_object_get_thunk  shell_toplevel_a2a_o_thunk
#define flash_trace_Trace_getListener_thunk  shell_toplevel_a2a_o_thunk

extern AvmBox shell_toplevel_i2a_ossi_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define C_stdlib___stdlib_setenv_thunk  shell_toplevel_i2a_ossi_thunk

extern AvmBox shell_toplevel_a2a_oou_opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_Domain_loadBytes_thunk  shell_toplevel_a2a_oou_opti0_thunk

extern AvmBox shell_toplevel_s2a_oi_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define C_string___string_strerror_thunk  shell_toplevel_s2a_oi_thunk

extern AvmBox shell_toplevel_i2a_oss_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define C_stdio___stdio_rename_thunk  shell_toplevel_i2a_oss_thunk

extern AvmBox shell_toplevel_v2a_ob_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define flash_utils_Dictionary_private_init_thunk  shell_toplevel_v2a_ob_thunk

extern AvmBox shell_toplevel_i2a_oi_opti2_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define flash_trace_Trace_getLevel_thunk  shell_toplevel_i2a_oi_opti2_thunk

extern AvmBox shell_toplevel_a2a_oii_opti2_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define flash_trace_Trace_setLevel_thunk  shell_toplevel_a2a_oii_opti2_thunk

extern AvmBox shell_toplevel_b2a_oso_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_FileSystem_writeByteArray_thunk  shell_toplevel_b2a_oso_thunk
#define avmplus_File_writeByteArray_thunk  shell_toplevel_b2a_oso_thunk

extern AvmBox shell_toplevel_s2a_oos_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_JObject_fieldSignature_thunk  shell_toplevel_s2a_oos_thunk

extern AvmBox shell_toplevel_v2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define C_stdlib___stdlib_abort_thunk  shell_toplevel_v2a_o_thunk
#define avmplus_System_debugger_thunk  shell_toplevel_v2a_o_thunk
#define avmplus_System_forceFullCollection_thunk  shell_toplevel_v2a_o_thunk
#define avmplus_System_queueCollection_thunk  shell_toplevel_v2a_o_thunk

extern AvmBox shell_toplevel_v2a_oo_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_Domain_domainMemory_set_thunk  shell_toplevel_v2a_oo_thunk
#define avmplus_Domain_private_init_thunk  shell_toplevel_v2a_oo_thunk
#define avmplus_System_disposeXML_thunk  shell_toplevel_v2a_oo_thunk
#define avmplus_System_stdoutWrite_thunk  shell_toplevel_v2a_oo_thunk
#define avmplus_System_trace_thunk  shell_toplevel_v2a_oo_thunk

extern AvmBox shell_toplevel_v2a_ou_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define C_unistd___unistd_sleep_thunk  shell_toplevel_v2a_ou_thunk

extern AvmBox shell_toplevel_v2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_System_write_thunk  shell_toplevel_v2a_os_thunk

extern AvmBox shell_toplevel_v2a_oi_opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define C_stdlib___stdlib_exit_thunk  shell_toplevel_v2a_oi_opti0_thunk

extern AvmBox shell_toplevel_b2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_System_isDebugger_thunk  shell_toplevel_b2a_o_thunk

extern AvmBox shell_toplevel_v2a_oi_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define C_errno___errno_errno_set_thunk  shell_toplevel_v2a_oi_thunk

extern AvmBox shell_toplevel_i2a_osi_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define C_unistd___unistd_access_thunk  shell_toplevel_i2a_osi_thunk
#define C_unistd___unistd_chmod_thunk  shell_toplevel_i2a_osi_thunk

extern double shell_toplevel_func_d2d_oaou_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_flash_sampler__getInvocationCount_thunk  shell_toplevel_func_d2d_oaou_thunk

extern AvmBox shell_toplevel_func_a2a_oab_optbfalse_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_flash_sampler_getMemberNames_thunk  shell_toplevel_func_a2a_oab_optbfalse_thunk

#endif // VMCFG_INDIRECT_NATIVE_THUNKS

class SlotOffsetsAndAsserts;
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

// C.stdlib::__stdlib$
//-----------------------------------------------------------
class _avmshell_StdlibClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_StdlibClass \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::_avmshell_StdlibClassSlots EmptySlotsStruct_StdlibClass
//-----------------------------------------------------------

// C.unistd::__unistd$
//-----------------------------------------------------------
class _avmshell_UnistdClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_UnistdClass \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::_avmshell_UnistdClassSlots EmptySlotsStruct_UnistdClass
//-----------------------------------------------------------

// C.string::__string$
//-----------------------------------------------------------
class _avmshell_CStringClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_CStringClass \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::_avmshell_CStringClassSlots EmptySlotsStruct_CStringClass
//-----------------------------------------------------------

// C.errno::__errno$
//-----------------------------------------------------------
class _avmshell_CErrnoClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_CErrnoClass \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::_avmshell_CErrnoClassSlots EmptySlotsStruct_CErrnoClass
//-----------------------------------------------------------

// C.stdio::__stdio$
//-----------------------------------------------------------
class _avmshell_StdioClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_StdioClass \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::_avmshell_StdioClassSlots EmptySlotsStruct_StdioClass
//-----------------------------------------------------------

// C.socket::__socket$
//-----------------------------------------------------------
class _avmshell_CSocketClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_CSocketClass \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::_avmshell_CSocketClassSlots EmptySlotsStruct_CSocketClass
//-----------------------------------------------------------

// avmplus::System$
//-----------------------------------------------------------
class _avmshell_SystemClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE ArrayObject* get_private__API() const { return m_private__API; }
    REALLY_INLINE void set_private__API(ArrayObject* newVal) { m_private__API = newVal; }
    REALLY_INLINE ArrayObject* get_argv() const { return m_argv; }
    REALLY_INLINE AvmString get_startupDirectory() const { return m_startupDirectory; }
    REALLY_INLINE AvmString get_private__shell() const { return m_private__shell; }
    REALLY_INLINE void set_private__shell(AvmString newVal) { m_private__shell = newVal; }
private:
    DRCWB(ArrayObject*) m_private__API;
    DRCWB(ArrayObject*) m_argv;
    DRCWB(AvmString) m_startupDirectory;
    DRCWB(AvmString) m_private__shell;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceLocation(&m_private__API);
        gc->TraceLocation(&m_argv);
        gc->TraceLocation(&m_startupDirectory);
        gc->TraceLocation(&m_private__shell);
    }
};
#define DECLARE_SLOTS_SystemClass \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE ArrayObject* get_private__API() const { return m_slots_SystemClass.get_private__API(); } \
        REALLY_INLINE void set_private__API(ArrayObject* newVal) { m_slots_SystemClass.set_private__API(newVal); } \
        REALLY_INLINE ArrayObject* get_argv() const { return m_slots_SystemClass.get_argv(); } \
        REALLY_INLINE AvmString get_startupDirectory() const { return m_slots_SystemClass.get_startupDirectory(); } \
        REALLY_INLINE AvmString get_private__shell() const { return m_slots_SystemClass.get_private__shell(); } \
        REALLY_INLINE void set_private__shell(AvmString newVal) { m_slots_SystemClass.set_private__shell(newVal); } \
    private: \
        avmplus::NativeID::_avmshell_SystemClassSlots m_slots_SystemClass
//-----------------------------------------------------------

// avmplus::OperatingSystem$
//-----------------------------------------------------------
class _avmshell_OperatingSystemClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE AvmString get_private_UNKNOWN() const { return m_private_UNKNOWN; }
    REALLY_INLINE AvmString get_private_EMPTY() const { return m_private_EMPTY; }
    REALLY_INLINE AvmString get_private__name() const { return m_private__name; }
    REALLY_INLINE void set_private__name(AvmString newVal) { m_private__name = newVal; }
    REALLY_INLINE AvmString get_private__nodename() const { return m_private__nodename; }
    REALLY_INLINE void set_private__nodename(AvmString newVal) { m_private__nodename = newVal; }
    REALLY_INLINE AvmString get_private__hostname() const { return m_private__hostname; }
    REALLY_INLINE void set_private__hostname(AvmString newVal) { m_private__hostname = newVal; }
    REALLY_INLINE AvmString get_private__release() const { return m_private__release; }
    REALLY_INLINE void set_private__release(AvmString newVal) { m_private__release = newVal; }
    REALLY_INLINE AvmString get_private__version() const { return m_private__version; }
    REALLY_INLINE void set_private__version(AvmString newVal) { m_private__version = newVal; }
    REALLY_INLINE AvmString get_private__machine() const { return m_private__machine; }
    REALLY_INLINE void set_private__machine(AvmString newVal) { m_private__machine = newVal; }
    REALLY_INLINE AvmString get_private__vendor() const { return m_private__vendor; }
    REALLY_INLINE void set_private__vendor(AvmString newVal) { m_private__vendor = newVal; }
    REALLY_INLINE AvmString get_private__vendorname() const { return m_private__vendorname; }
    REALLY_INLINE void set_private__vendorname(AvmString newVal) { m_private__vendorname = newVal; }
    REALLY_INLINE AvmString get_private__vendorversion() const { return m_private__vendorversion; }
    REALLY_INLINE void set_private__vendorversion(AvmString newVal) { m_private__vendorversion = newVal; }
    REALLY_INLINE AvmString get_private__vendordescription() const { return m_private__vendordescription; }
    REALLY_INLINE void set_private__vendordescription(AvmString newVal) { m_private__vendordescription = newVal; }
    REALLY_INLINE AvmString get_private__codename() const { return m_private__codename; }
    REALLY_INLINE void set_private__codename(AvmString newVal) { m_private__codename = newVal; }
    REALLY_INLINE AvmString get_private__username() const { return m_private__username; }
    REALLY_INLINE void set_private__username(AvmString newVal) { m_private__username = newVal; }
    REALLY_INLINE AvmString get_private__linuxDistribID() const { return m_private__linuxDistribID; }
    REALLY_INLINE void set_private__linuxDistribID(AvmString newVal) { m_private__linuxDistribID = newVal; }
    REALLY_INLINE AvmString get_private__linuxDistribRelease() const { return m_private__linuxDistribRelease; }
    REALLY_INLINE void set_private__linuxDistribRelease(AvmString newVal) { m_private__linuxDistribRelease = newVal; }
    REALLY_INLINE AvmString get_private__linuxDistribCodename() const { return m_private__linuxDistribCodename; }
    REALLY_INLINE void set_private__linuxDistribCodename(AvmString newVal) { m_private__linuxDistribCodename = newVal; }
    REALLY_INLINE AvmString get_private__linuxDistribDescription() const { return m_private__linuxDistribDescription; }
    REALLY_INLINE void set_private__linuxDistribDescription(AvmString newVal) { m_private__linuxDistribDescription = newVal; }
    REALLY_INLINE ArrayObject* get_private__linuxReleaseFiles() const { return m_private__linuxReleaseFiles; }
    REALLY_INLINE void set_private__linuxReleaseFiles(ArrayObject* newVal) { m_private__linuxReleaseFiles = newVal; }
    REALLY_INLINE AvmString get_private__macProductBuildVersion() const { return m_private__macProductBuildVersion; }
    REALLY_INLINE void set_private__macProductBuildVersion(AvmString newVal) { m_private__macProductBuildVersion = newVal; }
    REALLY_INLINE AvmString get_private__macSystemVersionFile() const { return m_private__macSystemVersionFile; }
    REALLY_INLINE void set_private__macSystemVersionFile(AvmString newVal) { m_private__macSystemVersionFile = newVal; }
private:
    DRCWB(AvmString) m_private_UNKNOWN;
    DRCWB(AvmString) m_private_EMPTY;
    DRCWB(AvmString) m_private__name;
    DRCWB(AvmString) m_private__nodename;
    DRCWB(AvmString) m_private__hostname;
    DRCWB(AvmString) m_private__release;
    DRCWB(AvmString) m_private__version;
    DRCWB(AvmString) m_private__machine;
    DRCWB(AvmString) m_private__vendor;
    DRCWB(AvmString) m_private__vendorname;
    DRCWB(AvmString) m_private__vendorversion;
    DRCWB(AvmString) m_private__vendordescription;
    DRCWB(AvmString) m_private__codename;
    DRCWB(AvmString) m_private__username;
    DRCWB(AvmString) m_private__linuxDistribID;
    DRCWB(AvmString) m_private__linuxDistribRelease;
    DRCWB(AvmString) m_private__linuxDistribCodename;
    DRCWB(AvmString) m_private__linuxDistribDescription;
    DRCWB(ArrayObject*) m_private__linuxReleaseFiles;
    DRCWB(AvmString) m_private__macProductBuildVersion;
    DRCWB(AvmString) m_private__macSystemVersionFile;
};
#define DECLARE_SLOTS_OperatingSystemClass \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE AvmString get_private_UNKNOWN() const { return m_slots_OperatingSystemClass.get_private_UNKNOWN(); } \
        REALLY_INLINE AvmString get_private_EMPTY() const { return m_slots_OperatingSystemClass.get_private_EMPTY(); } \
        REALLY_INLINE AvmString get_private__name() const { return m_slots_OperatingSystemClass.get_private__name(); } \
        REALLY_INLINE void set_private__name(AvmString newVal) { m_slots_OperatingSystemClass.set_private__name(newVal); } \
        REALLY_INLINE AvmString get_private__nodename() const { return m_slots_OperatingSystemClass.get_private__nodename(); } \
        REALLY_INLINE void set_private__nodename(AvmString newVal) { m_slots_OperatingSystemClass.set_private__nodename(newVal); } \
        REALLY_INLINE AvmString get_private__hostname() const { return m_slots_OperatingSystemClass.get_private__hostname(); } \
        REALLY_INLINE void set_private__hostname(AvmString newVal) { m_slots_OperatingSystemClass.set_private__hostname(newVal); } \
        REALLY_INLINE AvmString get_private__release() const { return m_slots_OperatingSystemClass.get_private__release(); } \
        REALLY_INLINE void set_private__release(AvmString newVal) { m_slots_OperatingSystemClass.set_private__release(newVal); } \
        REALLY_INLINE AvmString get_private__version() const { return m_slots_OperatingSystemClass.get_private__version(); } \
        REALLY_INLINE void set_private__version(AvmString newVal) { m_slots_OperatingSystemClass.set_private__version(newVal); } \
        REALLY_INLINE AvmString get_private__machine() const { return m_slots_OperatingSystemClass.get_private__machine(); } \
        REALLY_INLINE void set_private__machine(AvmString newVal) { m_slots_OperatingSystemClass.set_private__machine(newVal); } \
        REALLY_INLINE AvmString get_private__vendor() const { return m_slots_OperatingSystemClass.get_private__vendor(); } \
        REALLY_INLINE void set_private__vendor(AvmString newVal) { m_slots_OperatingSystemClass.set_private__vendor(newVal); } \
        REALLY_INLINE AvmString get_private__vendorname() const { return m_slots_OperatingSystemClass.get_private__vendorname(); } \
        REALLY_INLINE void set_private__vendorname(AvmString newVal) { m_slots_OperatingSystemClass.set_private__vendorname(newVal); } \
        REALLY_INLINE AvmString get_private__vendorversion() const { return m_slots_OperatingSystemClass.get_private__vendorversion(); } \
        REALLY_INLINE void set_private__vendorversion(AvmString newVal) { m_slots_OperatingSystemClass.set_private__vendorversion(newVal); } \
        REALLY_INLINE AvmString get_private__vendordescription() const { return m_slots_OperatingSystemClass.get_private__vendordescription(); } \
        REALLY_INLINE void set_private__vendordescription(AvmString newVal) { m_slots_OperatingSystemClass.set_private__vendordescription(newVal); } \
        REALLY_INLINE AvmString get_private__codename() const { return m_slots_OperatingSystemClass.get_private__codename(); } \
        REALLY_INLINE void set_private__codename(AvmString newVal) { m_slots_OperatingSystemClass.set_private__codename(newVal); } \
        REALLY_INLINE AvmString get_private__username() const { return m_slots_OperatingSystemClass.get_private__username(); } \
        REALLY_INLINE void set_private__username(AvmString newVal) { m_slots_OperatingSystemClass.set_private__username(newVal); } \
        REALLY_INLINE AvmString get_private__linuxDistribID() const { return m_slots_OperatingSystemClass.get_private__linuxDistribID(); } \
        REALLY_INLINE void set_private__linuxDistribID(AvmString newVal) { m_slots_OperatingSystemClass.set_private__linuxDistribID(newVal); } \
        REALLY_INLINE AvmString get_private__linuxDistribRelease() const { return m_slots_OperatingSystemClass.get_private__linuxDistribRelease(); } \
        REALLY_INLINE void set_private__linuxDistribRelease(AvmString newVal) { m_slots_OperatingSystemClass.set_private__linuxDistribRelease(newVal); } \
        REALLY_INLINE AvmString get_private__linuxDistribCodename() const { return m_slots_OperatingSystemClass.get_private__linuxDistribCodename(); } \
        REALLY_INLINE void set_private__linuxDistribCodename(AvmString newVal) { m_slots_OperatingSystemClass.set_private__linuxDistribCodename(newVal); } \
        REALLY_INLINE AvmString get_private__linuxDistribDescription() const { return m_slots_OperatingSystemClass.get_private__linuxDistribDescription(); } \
        REALLY_INLINE void set_private__linuxDistribDescription(AvmString newVal) { m_slots_OperatingSystemClass.set_private__linuxDistribDescription(newVal); } \
        REALLY_INLINE ArrayObject* get_private__linuxReleaseFiles() const { return m_slots_OperatingSystemClass.get_private__linuxReleaseFiles(); } \
        REALLY_INLINE void set_private__linuxReleaseFiles(ArrayObject* newVal) { m_slots_OperatingSystemClass.set_private__linuxReleaseFiles(newVal); } \
        REALLY_INLINE AvmString get_private__macProductBuildVersion() const { return m_slots_OperatingSystemClass.get_private__macProductBuildVersion(); } \
        REALLY_INLINE void set_private__macProductBuildVersion(AvmString newVal) { m_slots_OperatingSystemClass.set_private__macProductBuildVersion(newVal); } \
        REALLY_INLINE AvmString get_private__macSystemVersionFile() const { return m_slots_OperatingSystemClass.get_private__macSystemVersionFile(); } \
        REALLY_INLINE void set_private__macSystemVersionFile(AvmString newVal) { m_slots_OperatingSystemClass.set_private__macSystemVersionFile(newVal); } \
    private: \
        avmplus::NativeID::_avmshell_OperatingSystemClassSlots m_slots_OperatingSystemClass
//-----------------------------------------------------------

// avmplus::FileSystem$
//-----------------------------------------------------------
class _avmshell_FileSystemClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE ArrayObject* get_private__win32_separators() const { return m_private__win32_separators; }
    REALLY_INLINE void set_private__win32_separators(ArrayObject* newVal) { m_private__win32_separators = newVal; }
    REALLY_INLINE AvmString get_private__win32_lineEnding() const { return m_private__win32_lineEnding; }
    REALLY_INLINE void set_private__win32_lineEnding(AvmString newVal) { m_private__win32_lineEnding = newVal; }
    REALLY_INLINE ArrayObject* get_private__posix_separators() const { return m_private__posix_separators; }
    REALLY_INLINE void set_private__posix_separators(ArrayObject* newVal) { m_private__posix_separators = newVal; }
    REALLY_INLINE AvmString get_private__posix_lineEnding() const { return m_private__posix_lineEnding; }
    REALLY_INLINE void set_private__posix_lineEnding(AvmString newVal) { m_private__posix_lineEnding = newVal; }
    REALLY_INLINE ArrayObject* get_private__commonDoubleExtensions() const { return m_private__commonDoubleExtensions; }
    REALLY_INLINE void set_private__commonDoubleExtensions(ArrayObject* newVal) { m_private__commonDoubleExtensions = newVal; }
    REALLY_INLINE AvmString get_currentDirectory() const { return m_currentDirectory; }
    REALLY_INLINE AvmString get_parentDirectory() const { return m_parentDirectory; }
    REALLY_INLINE AvmString get_private__homeDirectory() const { return m_private__homeDirectory; }
    REALLY_INLINE void set_private__homeDirectory(AvmString newVal) { m_private__homeDirectory = newVal; }
    REALLY_INLINE AvmString get_private__rootDirectory() const { return m_private__rootDirectory; }
    REALLY_INLINE void set_private__rootDirectory(AvmString newVal) { m_private__rootDirectory = newVal; }
    REALLY_INLINE AvmString get_extensionSeparator() const { return m_extensionSeparator; }
private:
    DRCWB(ArrayObject*) m_private__win32_separators;
    DRCWB(AvmString) m_private__win32_lineEnding;
    DRCWB(ArrayObject*) m_private__posix_separators;
    DRCWB(AvmString) m_private__posix_lineEnding;
    DRCWB(ArrayObject*) m_private__commonDoubleExtensions;
    DRCWB(AvmString) m_currentDirectory;
    DRCWB(AvmString) m_parentDirectory;
    DRCWB(AvmString) m_private__homeDirectory;
    DRCWB(AvmString) m_private__rootDirectory;
    DRCWB(AvmString) m_extensionSeparator;
};
#define DECLARE_SLOTS_FileSystemClass \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE ArrayObject* get_private__win32_separators() const { return m_slots_FileSystemClass.get_private__win32_separators(); } \
        REALLY_INLINE void set_private__win32_separators(ArrayObject* newVal) { m_slots_FileSystemClass.set_private__win32_separators(newVal); } \
        REALLY_INLINE AvmString get_private__win32_lineEnding() const { return m_slots_FileSystemClass.get_private__win32_lineEnding(); } \
        REALLY_INLINE void set_private__win32_lineEnding(AvmString newVal) { m_slots_FileSystemClass.set_private__win32_lineEnding(newVal); } \
        REALLY_INLINE ArrayObject* get_private__posix_separators() const { return m_slots_FileSystemClass.get_private__posix_separators(); } \
        REALLY_INLINE void set_private__posix_separators(ArrayObject* newVal) { m_slots_FileSystemClass.set_private__posix_separators(newVal); } \
        REALLY_INLINE AvmString get_private__posix_lineEnding() const { return m_slots_FileSystemClass.get_private__posix_lineEnding(); } \
        REALLY_INLINE void set_private__posix_lineEnding(AvmString newVal) { m_slots_FileSystemClass.set_private__posix_lineEnding(newVal); } \
        REALLY_INLINE ArrayObject* get_private__commonDoubleExtensions() const { return m_slots_FileSystemClass.get_private__commonDoubleExtensions(); } \
        REALLY_INLINE void set_private__commonDoubleExtensions(ArrayObject* newVal) { m_slots_FileSystemClass.set_private__commonDoubleExtensions(newVal); } \
        REALLY_INLINE AvmString get_currentDirectory() const { return m_slots_FileSystemClass.get_currentDirectory(); } \
        REALLY_INLINE AvmString get_parentDirectory() const { return m_slots_FileSystemClass.get_parentDirectory(); } \
        REALLY_INLINE AvmString get_private__homeDirectory() const { return m_slots_FileSystemClass.get_private__homeDirectory(); } \
        REALLY_INLINE void set_private__homeDirectory(AvmString newVal) { m_slots_FileSystemClass.set_private__homeDirectory(newVal); } \
        REALLY_INLINE AvmString get_private__rootDirectory() const { return m_slots_FileSystemClass.get_private__rootDirectory(); } \
        REALLY_INLINE void set_private__rootDirectory(AvmString newVal) { m_slots_FileSystemClass.set_private__rootDirectory(newVal); } \
        REALLY_INLINE AvmString get_extensionSeparator() const { return m_slots_FileSystemClass.get_extensionSeparator(); } \
    private: \
        avmplus::NativeID::_avmshell_FileSystemClassSlots m_slots_FileSystemClass
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
