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

namespace avmshell {
    class ByteArrayClass; //flash.utils::ByteArray$
    class ByteArrayObject; //flash.utils::ByteArray
    class CErrnoClass; //C.errno::__errno$
    class CSocketClass; //C.socket::__socket$
    class CStringClass; //C.string::__string$
    class DomainClass; //avmplus::Domain$
    class DomainObject; //avmplus::Domain
    class FileClass; //avmplus::File$
    class FileSystemClass; //avmplus::FileSystem$
    class OperatingSystemClass; //avmplus::OperatingSystem$
    class SocketClass; //avmplus::Socket$
    class SocketObject; //avmplus::Socket
    class StdioClass; //C.stdio::__stdio$
    class StdlibClass; //C.stdlib::__stdlib$
    class SystemClass; //avmplus::System$
    class UnistdClass; //C.unistd::__unistd$
}

namespace avmplus {
    class ArrayObject; //Array
    class ClassClosure; //Class
    class DeleteObjectSampleClass; //flash.sampler::DeleteObjectSample$
    class DeleteObjectSampleObject; //flash.sampler::DeleteObjectSample
    class DictionaryClass; //flash.utils::Dictionary$
    class DictionaryObject; //flash.utils::Dictionary
    class JObject; //avmplus::JObject
    class JObjectClass; //avmplus::JObject$
    class NewObjectSampleClass; //flash.sampler::NewObjectSample$
    class NewObjectSampleObject; //flash.sampler::NewObjectSample
    class SampleClass; //flash.sampler::Sample$
    class SampleObject; //flash.sampler::Sample
    class ScriptObject; //avmplus::OperatingSystem
    class StackFrameClass; //flash.sampler::StackFrame$
    class StackFrameObject; //flash.sampler::StackFrame
    class String; //String
    class TraceClass; //flash.trace::Trace$
}

namespace avmplus { namespace NativeID {

extern const uint32_t shell_toplevel_abc_class_count;
extern const uint32_t shell_toplevel_abc_script_count;
extern const uint32_t shell_toplevel_abc_method_count;
extern const uint32_t shell_toplevel_abc_length;
extern const uint8_t shell_toplevel_abc_data[];
AVMTHUNK_DECLARE_NATIVE_INITIALIZER(shell_toplevel)

/* classes */
const uint32_t abcclass_avmplus_System = 0;
const uint32_t abcclass_avmplus_File = 1;
const uint32_t abcclass_flash_system_Capabilities = 2;
const uint32_t abcclass_avmplus_Domain = 3;
const uint32_t abcclass_flash_utils_ByteArray = 4;
const uint32_t abcclass_flash_sampler_StackFrame = 5;
const uint32_t abcclass_flash_sampler_Sample = 6;
const uint32_t abcclass_flash_sampler_NewObjectSample = 7;
const uint32_t abcclass_flash_sampler_DeleteObjectSample = 8;
const uint32_t abcclass_flash_trace_Trace = 9;
const uint32_t abcclass_flash_utils_Dictionary = 10;
const uint32_t abcclass_C_stdlib___stdlib = 11;
const uint32_t abcclass_C_unistd___unistd = 12;
const uint32_t abcclass_C_string___string = 13;
const uint32_t abcclass_C_errno___errno = 14;
const uint32_t abcclass_C_stdio___stdio = 15;
const uint32_t abcclass_C_socket___socket = 16;
const uint32_t abcclass_avmplus_FileSystem = 17;
const uint32_t abcclass_avmplus_OperatingSystem = 18;
const uint32_t abcclass_avmplus_Socket = 19;
const uint32_t abcclass_flash_utils_Endian = 20;
const uint32_t abcclass_avmplus_JObject = 21;

/* methods */
const uint32_t avmplus_System_exit = 7;
const uint32_t avmplus_System_exec = 8;
const uint32_t avmplus_System_getAvmplusVersion = 9;
const uint32_t avmplus_System_trace = 10;
const uint32_t avmplus_System_write = 11;
const uint32_t avmplus_System_debugger = 12;
const uint32_t avmplus_System_isDebugger = 13;
const uint32_t avmplus_System_getTimer = 14;
const uint32_t avmplus_System_private_getArgv = 15;
const uint32_t avmplus_System_private_getExecPath = 16;
const uint32_t avmplus_System_readLine = 17;
const uint32_t avmplus_System_totalMemory_get = 18;
const uint32_t avmplus_System_freeMemory_get = 19;
const uint32_t avmplus_System_privateMemory_get = 20;
const uint32_t avmplus_System_forceFullCollection = 21;
const uint32_t avmplus_System_queueCollection = 22;
const uint32_t avmplus_File_exists = 25;
const uint32_t avmplus_File_read = 26;
const uint32_t avmplus_File_write = 27;
const uint32_t avmplus_Domain_currentDomain_get = 37;
const uint32_t avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get = 38;
const uint32_t avmplus_Domain_private_init = 39;
const uint32_t avmplus_Domain_loadBytes = 41;
const uint32_t avmplus_Domain_getClass = 42;
const uint32_t avmplus_Domain_domainMemory_get = 44;
const uint32_t avmplus_Domain_domainMemory_set = 45;
const uint32_t flash_utils_ByteArray_readFile = 48;
const uint32_t flash_utils_ByteArray_writeFile = 49;
const uint32_t flash_utils_ByteArray_readBytes = 50;
const uint32_t flash_utils_ByteArray_writeBytes = 51;
const uint32_t flash_utils_ByteArray_writeBoolean = 52;
const uint32_t flash_utils_ByteArray_writeByte = 53;
const uint32_t flash_utils_ByteArray_writeShort = 54;
const uint32_t flash_utils_ByteArray_writeInt = 55;
const uint32_t flash_utils_ByteArray_writeUnsignedInt = 56;
const uint32_t flash_utils_ByteArray_writeFloat = 57;
const uint32_t flash_utils_ByteArray_writeDouble = 58;
const uint32_t flash_utils_ByteArray_writeUTF = 59;
const uint32_t flash_utils_ByteArray_writeUTFBytes = 60;
const uint32_t flash_utils_ByteArray_readBoolean = 61;
const uint32_t flash_utils_ByteArray_readByte = 62;
const uint32_t flash_utils_ByteArray_readUnsignedByte = 63;
const uint32_t flash_utils_ByteArray_readShort = 64;
const uint32_t flash_utils_ByteArray_readUnsignedShort = 65;
const uint32_t flash_utils_ByteArray_readInt = 66;
const uint32_t flash_utils_ByteArray_readUnsignedInt = 67;
const uint32_t flash_utils_ByteArray_readFloat = 68;
const uint32_t flash_utils_ByteArray_readDouble = 69;
const uint32_t flash_utils_ByteArray_readUTF = 70;
const uint32_t flash_utils_ByteArray_readUTFBytes = 71;
const uint32_t flash_utils_ByteArray_length_get = 72;
const uint32_t flash_utils_ByteArray_length_set = 73;
const uint32_t flash_utils_ByteArray_private_zlib_compress = 74;
const uint32_t flash_utils_ByteArray_private_zlib_uncompress = 76;
const uint32_t flash_utils_ByteArray_private__toString = 78;
const uint32_t flash_utils_ByteArray_bytesAvailable_get = 80;
const uint32_t flash_utils_ByteArray_position_get = 81;
const uint32_t flash_utils_ByteArray_position_set = 82;
const uint32_t flash_utils_ByteArray_endian_get = 83;
const uint32_t flash_utils_ByteArray_endian_set = 84;
const uint32_t native_script_function_flash_sampler_getMasterString = 87;
const uint32_t native_script_function_flash_sampler_getSavedThis = 88;
const uint32_t native_script_function_flash_sampler_getLexicalScopes = 89;
const uint32_t native_script_function_flash_sampler_isGetterSetter = 90;
const uint32_t native_script_function_flash_sampler__getInvocationCount = 91;
const uint32_t native_script_function_flash_sampler_getSampleCount = 95;
const uint32_t native_script_function_flash_sampler_getSamples = 96;
const uint32_t native_script_function_flash_sampler_getMemberNames = 97;
const uint32_t native_script_function_flash_sampler_getSize = 98;
const uint32_t native_script_function_flash_sampler__setSamplerCallback = 99;
const uint32_t native_script_function_flash_sampler_sampleInternalAllocs = 102;
const uint32_t native_script_function_flash_sampler_pauseSampling = 103;
const uint32_t native_script_function_flash_sampler_stopSampling = 104;
const uint32_t native_script_function_flash_sampler_startSampling = 105;
const uint32_t native_script_function_flash_sampler_clearSamples = 106;
const uint32_t flash_sampler_NewObjectSample_object_get = 113;
const uint32_t flash_sampler_NewObjectSample_size_get = 114;
const uint32_t flash_trace_Trace_setLevel = 120;
const uint32_t flash_trace_Trace_getLevel = 121;
const uint32_t flash_trace_Trace_setListener = 122;
const uint32_t flash_trace_Trace_getListener = 123;
const uint32_t flash_utils_Dictionary_private_init = 127;
const uint32_t C_stdlib___stdlib_EXIT_SUCCESS_get = 138;
const uint32_t C_stdlib___stdlib_EXIT_FAILURE_get = 139;
const uint32_t C_stdlib___stdlib_abort = 140;
const uint32_t C_stdlib___stdlib_exit = 141;
const uint32_t C_stdlib___stdlib_getenv = 142;
const uint32_t C_stdlib___stdlib_setenv = 143;
const uint32_t C_stdlib___stdlib_unsetenv = 144;
const uint32_t C_stdlib___stdlib_realpath = 145;
const uint32_t C_stdlib___stdlib___system = 146;
const uint32_t C_unistd___unistd_F_OK_get = 158;
const uint32_t C_unistd___unistd_X_OK_get = 159;
const uint32_t C_unistd___unistd_W_OK_get = 160;
const uint32_t C_unistd___unistd_R_OK_get = 161;
const uint32_t C_unistd___unistd_S_IFMT_get = 162;
const uint32_t C_unistd___unistd_S_IFIFO_get = 163;
const uint32_t C_unistd___unistd_S_IFCHR_get = 164;
const uint32_t C_unistd___unistd_S_IFDIR_get = 165;
const uint32_t C_unistd___unistd_S_IFBLK_get = 166;
const uint32_t C_unistd___unistd_S_IFREG_get = 167;
const uint32_t C_unistd___unistd_S_IFLNK_get = 168;
const uint32_t C_unistd___unistd_S_IFSOCK_get = 169;
const uint32_t C_unistd___unistd_S_IRWXU_get = 170;
const uint32_t C_unistd___unistd_S_IRUSR_get = 171;
const uint32_t C_unistd___unistd_S_IWUSR_get = 172;
const uint32_t C_unistd___unistd_S_IXUSR_get = 173;
const uint32_t C_unistd___unistd_S_IRWXG_get = 174;
const uint32_t C_unistd___unistd_S_IRGRP_get = 175;
const uint32_t C_unistd___unistd_S_IWGRP_get = 176;
const uint32_t C_unistd___unistd_S_IXGRP_get = 177;
const uint32_t C_unistd___unistd_S_IRWXO_get = 178;
const uint32_t C_unistd___unistd_S_IROTH_get = 179;
const uint32_t C_unistd___unistd_S_IWOTH_get = 180;
const uint32_t C_unistd___unistd_S_IXOTH_get = 181;
const uint32_t C_unistd___unistd_S_IREAD_get = 182;
const uint32_t C_unistd___unistd_S_IWRITE_get = 183;
const uint32_t C_unistd___unistd_S_IEXEC_get = 184;
const uint32_t C_unistd___unistd_access = 185;
const uint32_t C_unistd___unistd_chmod = 186;
const uint32_t C_unistd___unistd_getcwd = 187;
const uint32_t C_unistd___unistd_gethostname = 188;
const uint32_t C_unistd___unistd_getlogin = 189;
const uint32_t C_unistd___unistd_mkdir = 190;
const uint32_t C_unistd___unistd_rmdir = 191;
const uint32_t C_unistd___unistd_sleep = 192;
const uint32_t C_string___string_strerror = 200;
const uint32_t C_string___string_strlen = 201;
const uint32_t C_errno___errno_EDOM_get = 207;
const uint32_t C_errno___errno_EILSEQ_get = 208;
const uint32_t C_errno___errno_ERANGE_get = 209;
const uint32_t C_errno___errno_EPERM_get = 210;
const uint32_t C_errno___errno_ENOENT_get = 211;
const uint32_t C_errno___errno_ESRCH_get = 212;
const uint32_t C_errno___errno_EINTR_get = 213;
const uint32_t C_errno___errno_EIO_get = 214;
const uint32_t C_errno___errno_ENXIO_get = 215;
const uint32_t C_errno___errno_E2BIG_get = 216;
const uint32_t C_errno___errno_ENOEXEC_get = 217;
const uint32_t C_errno___errno_EBADF_get = 218;
const uint32_t C_errno___errno_ECHILD_get = 219;
const uint32_t C_errno___errno_EAGAIN_get = 220;
const uint32_t C_errno___errno_ENOMEM_get = 221;
const uint32_t C_errno___errno_EACCES_get = 222;
const uint32_t C_errno___errno_EFAULT_get = 223;
const uint32_t C_errno___errno_EBUSY_get = 224;
const uint32_t C_errno___errno_EEXIST_get = 225;
const uint32_t C_errno___errno_EXDEV_get = 226;
const uint32_t C_errno___errno_ENODEV_get = 227;
const uint32_t C_errno___errno_ENOTDIR_get = 228;
const uint32_t C_errno___errno_EISDIR_get = 229;
const uint32_t C_errno___errno_EINVAL_get = 230;
const uint32_t C_errno___errno_ENFILE_get = 231;
const uint32_t C_errno___errno_EMFILE_get = 232;
const uint32_t C_errno___errno_ENOTTY_get = 233;
const uint32_t C_errno___errno_EFBIG_get = 234;
const uint32_t C_errno___errno_ENOSPC_get = 235;
const uint32_t C_errno___errno_ESPIPE_get = 236;
const uint32_t C_errno___errno_EROFS_get = 237;
const uint32_t C_errno___errno_EMLINK_get = 238;
const uint32_t C_errno___errno_EPIPE_get = 239;
const uint32_t C_errno___errno_EDEADLK_get = 240;
const uint32_t C_errno___errno_ENAMETOOLONG_get = 241;
const uint32_t C_errno___errno_ENOLCK_get = 242;
const uint32_t C_errno___errno_ENOSYS_get = 243;
const uint32_t C_errno___errno_ENOTEMPTY_get = 244;
const uint32_t C_errno___errno_ENETDOWN_get = 245;
const uint32_t C_errno___errno_ENETUNREACH_get = 246;
const uint32_t C_errno___errno_ENETRESET_get = 247;
const uint32_t C_errno___errno_ECONNABORTED_get = 248;
const uint32_t C_errno___errno_ECONNRESET_get = 249;
const uint32_t C_errno___errno_ENOBUFS_get = 250;
const uint32_t C_errno___errno_EISCONN_get = 251;
const uint32_t C_errno___errno_ENOTCONN_get = 252;
const uint32_t C_errno___errno_ESHUTDOWN_get = 253;
const uint32_t C_errno___errno_ETOOMANYREFS_get = 254;
const uint32_t C_errno___errno_ETIMEDOUT_get = 255;
const uint32_t C_errno___errno_ECONNREFUSED_get = 256;
const uint32_t C_errno___errno_errno_get = 257;
const uint32_t C_errno___errno_errno_set = 258;
const uint32_t C_stdio___stdio_FILENAME_MAX_get = 264;
const uint32_t C_stdio___stdio_PATH_MAX_get = 265;
const uint32_t C_stdio___stdio_remove = 266;
const uint32_t C_stdio___stdio_rename = 267;
const uint32_t C_socket___socket_SOCK_RAW_get = 271;
const uint32_t C_socket___socket_SOCK_STREAM_get = 272;
const uint32_t C_socket___socket_SOCK_DGRAM_get = 273;
const uint32_t C_socket___socket_SO_ACCEPTCONN_get = 274;
const uint32_t C_socket___socket_SO_BROADCAST_get = 275;
const uint32_t C_socket___socket_SO_DONTROUTE_get = 276;
const uint32_t C_socket___socket_SO_KEEPALIVE_get = 277;
const uint32_t C_socket___socket_SO_OOBINLINE_get = 278;
const uint32_t C_socket___socket_SO_RCVBUF_get = 279;
const uint32_t C_socket___socket_SO_RCVTIMEO_get = 280;
const uint32_t C_socket___socket_SO_REUSEADDR_get = 281;
const uint32_t C_socket___socket_SO_SNDBUF_get = 282;
const uint32_t C_socket___socket_SO_SNDTIMEO_get = 283;
const uint32_t C_socket___socket_SO_TYPE_get = 284;
const uint32_t C_socket___socket_SOMAXCONN_get = 285;
const uint32_t C_socket___socket_MSG_CTRUNC_get = 286;
const uint32_t C_socket___socket_MSG_DONTROUTE_get = 287;
const uint32_t C_socket___socket_MSG_OOB_get = 288;
const uint32_t C_socket___socket_MSG_PEEK_get = 289;
const uint32_t C_socket___socket_MSG_TRUNC_get = 290;
const uint32_t C_socket___socket_MSG_WAITALL_get = 291;
const uint32_t C_socket___socket_AF_INET_get = 292;
const uint32_t C_socket___socket_AF_INET6_get = 293;
const uint32_t C_socket___socket_AF_UNSPEC_get = 294;
const uint32_t C_socket___socket_SHUT_RD_get = 295;
const uint32_t C_socket___socket_SHUT_RDWR_get = 296;
const uint32_t C_socket___socket_SHUT_WR_get = 297;
const uint32_t C_socket___socket_IPPROTO_IP_get = 298;
const uint32_t C_socket___socket_IPPROTO_IPV6_get = 299;
const uint32_t C_socket___socket_IPPROTO_ICMP_get = 300;
const uint32_t C_socket___socket_IPPROTO_RAW_get = 301;
const uint32_t C_socket___socket_IPPROTO_TCP_get = 302;
const uint32_t C_socket___socket_IPPROTO_UDP_get = 303;
const uint32_t C_socket___socket_INADDR_ANY_get = 304;
const uint32_t C_socket___socket_INADDR_BROADCAST_get = 305;
const uint32_t avmplus_FileSystem_exists = 309;
const uint32_t avmplus_FileSystem_read = 310;
const uint32_t avmplus_FileSystem_write = 311;
const uint32_t avmplus_FileSystem_getFileMode = 312;
const uint32_t avmplus_FileSystem_isRegularFile = 316;
const uint32_t avmplus_FileSystem_isDirectory = 317;
const uint32_t avmplus_FileSystem_listFiles = 318;
const uint32_t avmplus_FileSystem_getFreeDiskSpace = 319;
const uint32_t avmplus_FileSystem_getTotalDiskSpace = 320;
const uint32_t avmplus_OperatingSystem_private_getName = 327;
const uint32_t avmplus_OperatingSystem_private_getNodeName = 328;
const uint32_t avmplus_OperatingSystem_private_getRelease = 329;
const uint32_t avmplus_OperatingSystem_private_getVersion = 330;
const uint32_t avmplus_OperatingSystem_private_getMachine = 331;
const uint32_t avmplus_OperatingSystem_private_getVendorVersion = 332;
const uint32_t avmplus_OperatingSystem_private_getUserName = 333;
const uint32_t avmplus_Socket_lastError_get = 362;
const uint32_t avmplus_Socket_private_lastDataSent_get = 364;
const uint32_t avmplus_Socket_private_receivedBuffer_get = 365;
const uint32_t avmplus_Socket_private_receivedBinary_get = 366;
const uint32_t avmplus_Socket_private_isValid = 367;
const uint32_t avmplus_Socket_private__customSocket = 368;
const uint32_t avmplus_Socket_private__connect = 369;
const uint32_t avmplus_Socket_private__close = 370;
const uint32_t avmplus_Socket_private__send = 371;
const uint32_t avmplus_Socket_private__sendBinary = 372;
const uint32_t avmplus_Socket_private__receive = 373;
const uint32_t avmplus_Socket_private__receiveBinary = 374;
const uint32_t avmplus_Socket_private__bind = 375;
const uint32_t avmplus_Socket_private__listen = 376;
const uint32_t avmplus_Socket_private__accept = 377;
const uint32_t avmplus_Socket_private__type_get = 383;
const uint32_t avmplus_Socket_reuseAddress_get = 385;
const uint32_t avmplus_Socket_reuseAddress_set = 386;
const uint32_t avmplus_Socket_broadcast_get = 387;
const uint32_t avmplus_Socket_broadcast_set = 388;
const uint32_t avmplus_JObject_create = 409;
const uint32_t avmplus_JObject_createArray = 410;
const uint32_t avmplus_JObject_toArray = 411;
const uint32_t avmplus_JObject_constructorSignature = 412;
const uint32_t avmplus_JObject_methodSignature = 413;
const uint32_t avmplus_JObject_fieldSignature = 414;

extern AvmBox avmplus_Domain_currentDomain_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_Domain_private_init_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_Domain_loadBytes_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_Domain_getClass_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_Domain_domainMemory_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_Domain_domainMemory_set_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_utils_ByteArray_readFile_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_utils_ByteArray_writeFile_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_utils_ByteArray_readBytes_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_utils_ByteArray_writeBytes_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_utils_ByteArray_writeBoolean_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_utils_ByteArray_writeByte_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_utils_ByteArray_writeShort_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_utils_ByteArray_writeInt_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_utils_ByteArray_writeUnsignedInt_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_utils_ByteArray_writeFloat_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_utils_ByteArray_writeDouble_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_utils_ByteArray_writeUTF_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_utils_ByteArray_writeUTFBytes_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_utils_ByteArray_readBoolean_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_utils_ByteArray_readByte_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_utils_ByteArray_readUnsignedByte_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_utils_ByteArray_readShort_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_utils_ByteArray_readUnsignedShort_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_utils_ByteArray_readInt_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_utils_ByteArray_readUnsignedInt_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern double flash_utils_ByteArray_readFloat_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern double flash_utils_ByteArray_readDouble_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_utils_ByteArray_readUTF_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_utils_ByteArray_readUTFBytes_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_utils_ByteArray_length_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_utils_ByteArray_length_set_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_utils_ByteArray_private_zlib_compress_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_utils_ByteArray_private_zlib_uncompress_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_utils_ByteArray_private__toString_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_utils_ByteArray_bytesAvailable_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_utils_ByteArray_position_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_utils_ByteArray_position_set_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_utils_ByteArray_endian_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox flash_utils_ByteArray_endian_set_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
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
extern AvmBox C_unistd___unistd_chmod_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_getcwd_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_gethostname_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_getlogin_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_mkdir_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_rmdir_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox C_unistd___unistd_sleep_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
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
extern AvmBox avmplus_FileSystem_exists_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_FileSystem_read_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_FileSystem_write_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_FileSystem_getFileMode_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_FileSystem_isRegularFile_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_FileSystem_isDirectory_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_FileSystem_listFiles_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern double avmplus_FileSystem_getFreeDiskSpace_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern double avmplus_FileSystem_getTotalDiskSpace_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_OperatingSystem_private_getName_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_OperatingSystem_private_getNodeName_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_OperatingSystem_private_getRelease_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_OperatingSystem_private_getVersion_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_OperatingSystem_private_getMachine_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_OperatingSystem_private_getVendorVersion_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_OperatingSystem_private_getUserName_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_Socket_lastError_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_Socket_private_lastDataSent_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_Socket_private_receivedBuffer_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_Socket_private_receivedBinary_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_Socket_private_isValid_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_Socket_private__customSocket_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_Socket_private__connect_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_Socket_private__close_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_Socket_private__send_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_Socket_private__sendBinary_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_Socket_private__receive_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_Socket_private__receiveBinary_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_Socket_private__bind_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_Socket_private__listen_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_Socket_private__accept_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_Socket_private__type_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_Socket_reuseAddress_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_Socket_reuseAddress_set_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_Socket_broadcast_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_Socket_broadcast_set_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_JObject_create_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_JObject_createArray_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_JObject_toArray_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_JObject_constructorSignature_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_JObject_methodSignature_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_JObject_fieldSignature_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_exit_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_exec_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_getAvmplusVersion_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_trace_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_write_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_debugger_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_isDebugger_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_getTimer_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_private_getArgv_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_private_getExecPath_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_readLine_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern double avmplus_System_totalMemory_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern double avmplus_System_freeMemory_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern double avmplus_System_privateMemory_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_forceFullCollection_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_System_queueCollection_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_File_exists_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_File_read_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
extern AvmBox avmplus_File_write_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);

#ifdef VMCFG_INDIRECT_NATIVE_THUNKS

extern AvmBox shell_toplevel_s2a_oos_rest_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_JObject_methodSignature_thunk  shell_toplevel_s2a_oos_rest_thunk

extern AvmBox shell_toplevel_func_s2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_flash_sampler_getMasterString_thunk  shell_toplevel_func_s2a_os_thunk

extern AvmBox shell_toplevel_func_v2a_oo_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_flash_sampler__setSamplerCallback_thunk  shell_toplevel_func_v2a_oo_thunk

extern double shell_toplevel_d2d_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define flash_sampler_NewObjectSample_size_get_thunk  shell_toplevel_d2d_o_thunk
#define avmplus_System_freeMemory_get_thunk  shell_toplevel_d2d_o_thunk
#define avmplus_System_privateMemory_get_thunk  shell_toplevel_d2d_o_thunk
#define flash_utils_ByteArray_readFloat_thunk  shell_toplevel_d2d_o_thunk
#define avmplus_System_totalMemory_get_thunk  shell_toplevel_d2d_o_thunk
#define flash_utils_ByteArray_readDouble_thunk  shell_toplevel_d2d_o_thunk

extern AvmBox shell_toplevel_v2a_oouu_opti0_opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define flash_utils_ByteArray_writeBytes_thunk  shell_toplevel_v2a_oouu_opti0_opti0_thunk
#define flash_utils_ByteArray_readBytes_thunk  shell_toplevel_v2a_oouu_opti0_opti0_thunk

extern AvmBox shell_toplevel_a2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define flash_utils_ByteArray_readFile_thunk  shell_toplevel_a2a_os_thunk
#define avmplus_Domain_getClass_thunk  shell_toplevel_a2a_os_thunk

extern AvmBox shell_toplevel_func_b2a_oao_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_flash_sampler_isGetterSetter_thunk  shell_toplevel_func_b2a_oao_thunk

extern AvmBox shell_toplevel_u2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define C_string___string_strlen_thunk  shell_toplevel_u2a_os_thunk

extern AvmBox shell_toplevel_v2a_oi_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define C_errno___errno_errno_set_thunk  shell_toplevel_v2a_oi_thunk
#define flash_utils_ByteArray_writeByte_thunk  shell_toplevel_v2a_oi_thunk
#define avmplus_System_exit_thunk  shell_toplevel_v2a_oi_thunk
#define flash_utils_ByteArray_writeInt_thunk  shell_toplevel_v2a_oi_thunk
#define flash_utils_ByteArray_writeShort_thunk  shell_toplevel_v2a_oi_thunk

extern AvmBox shell_toplevel_s2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_System_readLine_thunk  shell_toplevel_s2a_o_thunk
#define avmplus_Socket_private_receivedBuffer_get_thunk  shell_toplevel_s2a_o_thunk
#define avmplus_OperatingSystem_private_getMachine_thunk  shell_toplevel_s2a_o_thunk
#define avmplus_OperatingSystem_private_getVendorVersion_thunk  shell_toplevel_s2a_o_thunk
#define flash_utils_ByteArray_endian_get_thunk  shell_toplevel_s2a_o_thunk
#define C_unistd___unistd_gethostname_thunk  shell_toplevel_s2a_o_thunk
#define flash_utils_ByteArray_readUTF_thunk  shell_toplevel_s2a_o_thunk
#define flash_utils_ByteArray_private__toString_thunk  shell_toplevel_s2a_o_thunk
#define avmplus_OperatingSystem_private_getName_thunk  shell_toplevel_s2a_o_thunk
#define avmplus_OperatingSystem_private_getRelease_thunk  shell_toplevel_s2a_o_thunk
#define avmplus_System_private_getExecPath_thunk  shell_toplevel_s2a_o_thunk
#define avmplus_OperatingSystem_private_getVersion_thunk  shell_toplevel_s2a_o_thunk
#define avmplus_System_getAvmplusVersion_thunk  shell_toplevel_s2a_o_thunk
#define C_unistd___unistd_getlogin_thunk  shell_toplevel_s2a_o_thunk
#define C_unistd___unistd_getcwd_thunk  shell_toplevel_s2a_o_thunk
#define avmplus_OperatingSystem_private_getUserName_thunk  shell_toplevel_s2a_o_thunk
#define avmplus_OperatingSystem_private_getNodeName_thunk  shell_toplevel_s2a_o_thunk

extern AvmBox shell_toplevel_func_a2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_flash_sampler_getSamples_thunk  shell_toplevel_func_a2a_o_thunk

extern AvmBox shell_toplevel_v2a_oss_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_FileSystem_write_thunk  shell_toplevel_v2a_oss_thunk
#define avmplus_File_write_thunk  shell_toplevel_v2a_oss_thunk

extern double shell_toplevel_func_d2d_oa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_flash_sampler_getSize_thunk  shell_toplevel_func_d2d_oa_thunk

extern AvmBox shell_toplevel_s2a_os_rest_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_JObject_constructorSignature_thunk  shell_toplevel_s2a_os_rest_thunk

extern AvmBox shell_toplevel_func_a2a_oab_optbfalse_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_flash_sampler_getMemberNames_thunk  shell_toplevel_func_a2a_oab_optbfalse_thunk

extern AvmBox shell_toplevel_a2a_oii_opti2_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define flash_trace_Trace_setLevel_thunk  shell_toplevel_a2a_oii_opti2_thunk

extern AvmBox shell_toplevel_func_v2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_flash_sampler_pauseSampling_thunk  shell_toplevel_func_v2a_o_thunk
#define native_script_function_flash_sampler_clearSamples_thunk  shell_toplevel_func_v2a_o_thunk
#define native_script_function_flash_sampler_startSampling_thunk  shell_toplevel_func_v2a_o_thunk
#define native_script_function_flash_sampler_stopSampling_thunk  shell_toplevel_func_v2a_o_thunk

extern AvmBox shell_toplevel_u2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define flash_utils_ByteArray_readUnsignedShort_thunk  shell_toplevel_u2a_o_thunk
#define flash_utils_ByteArray_bytesAvailable_get_thunk  shell_toplevel_u2a_o_thunk
#define flash_utils_ByteArray_length_get_thunk  shell_toplevel_u2a_o_thunk
#define flash_utils_ByteArray_readUnsignedInt_thunk  shell_toplevel_u2a_o_thunk
#define flash_utils_ByteArray_readUnsignedByte_thunk  shell_toplevel_u2a_o_thunk
#define avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get_thunk  shell_toplevel_u2a_o_thunk
#define avmplus_System_getTimer_thunk  shell_toplevel_u2a_o_thunk
#define flash_utils_ByteArray_position_get_thunk  shell_toplevel_u2a_o_thunk

extern AvmBox shell_toplevel_a2a_ooio_optakAvmThunkNull_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_JObject_createArray_thunk  shell_toplevel_a2a_ooio_optakAvmThunkNull_thunk

extern AvmBox shell_toplevel_i2a_osi_opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_Socket_private__send_thunk  shell_toplevel_i2a_osi_opti0_thunk

extern AvmBox shell_toplevel_a2a_osb_optbfalse_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_FileSystem_listFiles_thunk  shell_toplevel_a2a_osb_optbfalse_thunk

extern AvmBox shell_toplevel_func_v2a_ob_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_flash_sampler_sampleInternalAllocs_thunk  shell_toplevel_func_v2a_ob_thunk

extern AvmBox shell_toplevel_i2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define C_errno___errno_ENXIO_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SHUT_RDWR_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SOMAXCONN_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EPIPE_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ETIMEDOUT_get_thunk  shell_toplevel_i2a_o_thunk
#define flash_utils_ByteArray_readShort_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IRWXG_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENETUNREACH_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SO_RCVBUF_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SO_TYPE_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENODEV_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ESPIPE_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EINVAL_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ESHUTDOWN_get_thunk  shell_toplevel_i2a_o_thunk
#define C_stdio___stdio_PATH_MAX_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SO_KEEPALIVE_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IEXEC_get_thunk  shell_toplevel_i2a_o_thunk
#define avmplus_Socket_private__type_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_AF_INET6_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ECHILD_get_thunk  shell_toplevel_i2a_o_thunk
#define C_stdlib___stdlib_EXIT_SUCCESS_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EINTR_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ECONNRESET_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENOENT_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EISDIR_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_W_OK_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENOTTY_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EILSEQ_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SOCK_RAW_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENOLCK_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_INADDR_BROADCAST_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IWUSR_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EFAULT_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_MSG_WAITALL_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SO_DONTROUTE_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IRWXO_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EMLINK_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENOTEMPTY_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SO_OOBINLINE_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_IPPROTO_IPV6_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EACCES_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SO_SNDTIMEO_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IRGRP_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SO_SNDBUF_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IFIFO_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EEXIST_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENETRESET_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IFSOCK_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_MSG_DONTROUTE_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_MSG_TRUNC_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SO_RCVTIMEO_get_thunk  shell_toplevel_i2a_o_thunk
#define C_stdio___stdio_FILENAME_MAX_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EBADF_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENOBUFS_get_thunk  shell_toplevel_i2a_o_thunk
#define flash_utils_ByteArray_readInt_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IWRITE_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENFILE_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_E2BIG_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_F_OK_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IROTH_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IXUSR_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ECONNREFUSED_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EDOM_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EFBIG_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IWGRP_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ECONNABORTED_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_IPPROTO_TCP_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SO_REUSEADDR_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IXGRP_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENETDOWN_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EIO_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_errno_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_AF_UNSPEC_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SOCK_DGRAM_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_IPPROTO_IP_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IFREG_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENOSYS_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IFBLK_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EDEADLK_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IRWXU_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SOCK_STREAM_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IFCHR_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IWOTH_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_IPPROTO_UDP_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IXOTH_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SO_ACCEPTCONN_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IFLNK_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENOSPC_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_INADDR_ANY_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SHUT_RD_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IFMT_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ESRCH_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENOMEM_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENAMETOOLONG_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_MSG_CTRUNC_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_R_OK_get_thunk  shell_toplevel_i2a_o_thunk
#define flash_utils_ByteArray_readByte_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IREAD_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EISCONN_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_AF_INET_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EROFS_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SO_BROADCAST_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EMFILE_get_thunk  shell_toplevel_i2a_o_thunk
#define avmplus_Socket_lastError_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_MSG_OOB_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ERANGE_get_thunk  shell_toplevel_i2a_o_thunk
#define avmplus_Socket_private_lastDataSent_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_SHUT_WR_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_IPPROTO_ICMP_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_MSG_PEEK_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_X_OK_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENOEXEC_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENOTDIR_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EXDEV_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IRUSR_get_thunk  shell_toplevel_i2a_o_thunk
#define C_stdlib___stdlib_EXIT_FAILURE_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ENOTCONN_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EAGAIN_get_thunk  shell_toplevel_i2a_o_thunk
#define C_unistd___unistd_S_IFDIR_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EBUSY_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_ETOOMANYREFS_get_thunk  shell_toplevel_i2a_o_thunk
#define C_socket___socket_IPPROTO_RAW_get_thunk  shell_toplevel_i2a_o_thunk
#define C_errno___errno_EPERM_get_thunk  shell_toplevel_i2a_o_thunk

extern double shell_toplevel_d2d_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_FileSystem_getTotalDiskSpace_thunk  shell_toplevel_d2d_os_thunk
#define avmplus_FileSystem_getFreeDiskSpace_thunk  shell_toplevel_d2d_os_thunk

extern AvmBox shell_toplevel_i2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define C_stdio___stdio_remove_thunk  shell_toplevel_i2a_os_thunk
#define avmplus_FileSystem_getFileMode_thunk  shell_toplevel_i2a_os_thunk
#define C_unistd___unistd_rmdir_thunk  shell_toplevel_i2a_os_thunk
#define avmplus_System_exec_thunk  shell_toplevel_i2a_os_thunk
#define C_unistd___unistd_mkdir_thunk  shell_toplevel_i2a_os_thunk
#define C_stdlib___stdlib_unsetenv_thunk  shell_toplevel_i2a_os_thunk
#define C_stdlib___stdlib___system_thunk  shell_toplevel_i2a_os_thunk

extern AvmBox shell_toplevel_s2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_FileSystem_read_thunk  shell_toplevel_s2a_os_thunk
#define C_stdlib___stdlib_realpath_thunk  shell_toplevel_s2a_os_thunk
#define C_stdlib___stdlib_getenv_thunk  shell_toplevel_s2a_os_thunk
#define avmplus_File_read_thunk  shell_toplevel_s2a_os_thunk

extern AvmBox shell_toplevel_i2a_ooi_opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_Socket_private__sendBinary_thunk  shell_toplevel_i2a_ooi_opti0_thunk

extern AvmBox shell_toplevel_s2a_ou_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define flash_utils_ByteArray_readUTFBytes_thunk  shell_toplevel_s2a_ou_thunk

extern AvmBox shell_toplevel_a2a_os_rest_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_JObject_create_thunk  shell_toplevel_a2a_os_rest_thunk

extern AvmBox shell_toplevel_func_a2a_oo_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_flash_sampler_getSavedThis_thunk  shell_toplevel_func_a2a_oo_thunk
#define native_script_function_flash_sampler_getLexicalScopes_thunk  shell_toplevel_func_a2a_oo_thunk

extern AvmBox shell_toplevel_b2a_oi_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_Socket_private__listen_thunk  shell_toplevel_b2a_oi_thunk
#define avmplus_Socket_private__bind_thunk  shell_toplevel_b2a_oi_thunk

extern double shell_toplevel_func_d2d_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_flash_sampler_getSampleCount_thunk  shell_toplevel_func_d2d_o_thunk

extern AvmBox shell_toplevel_b2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_FileSystem_isRegularFile_thunk  shell_toplevel_b2a_os_thunk
#define avmplus_FileSystem_isDirectory_thunk  shell_toplevel_b2a_os_thunk
#define avmplus_FileSystem_exists_thunk  shell_toplevel_b2a_os_thunk
#define avmplus_File_exists_thunk  shell_toplevel_b2a_os_thunk

extern AvmBox shell_toplevel_a2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_Domain_currentDomain_get_thunk  shell_toplevel_a2a_o_thunk
#define avmplus_System_private_getArgv_thunk  shell_toplevel_a2a_o_thunk
#define avmplus_Socket_private_receivedBinary_get_thunk  shell_toplevel_a2a_o_thunk
#define flash_trace_Trace_getListener_thunk  shell_toplevel_a2a_o_thunk
#define avmplus_Socket_private__accept_thunk  shell_toplevel_a2a_o_thunk
#define flash_sampler_NewObjectSample_object_get_thunk  shell_toplevel_a2a_o_thunk
#define avmplus_Domain_domainMemory_get_thunk  shell_toplevel_a2a_o_thunk

extern AvmBox shell_toplevel_v2a_oiii_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_Socket_private__customSocket_thunk  shell_toplevel_v2a_oiii_thunk

extern AvmBox shell_toplevel_i2a_ossi_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define C_stdlib___stdlib_setenv_thunk  shell_toplevel_i2a_ossi_thunk

extern AvmBox shell_toplevel_s2a_oi_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define C_string___string_strerror_thunk  shell_toplevel_s2a_oi_thunk

extern AvmBox shell_toplevel_i2a_oss_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define C_stdio___stdio_rename_thunk  shell_toplevel_i2a_oss_thunk

extern AvmBox shell_toplevel_v2a_od_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define flash_utils_ByteArray_writeDouble_thunk  shell_toplevel_v2a_od_thunk
#define flash_utils_ByteArray_writeFloat_thunk  shell_toplevel_v2a_od_thunk

extern AvmBox shell_toplevel_i2a_oi_opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_Socket_private__receive_thunk  shell_toplevel_i2a_oi_opti0_thunk
#define avmplus_Socket_private__receiveBinary_thunk  shell_toplevel_i2a_oi_opti0_thunk

extern AvmBox shell_toplevel_v2a_ob_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_Socket_reuseAddress_set_thunk  shell_toplevel_v2a_ob_thunk
#define avmplus_Socket_broadcast_set_thunk  shell_toplevel_v2a_ob_thunk
#define flash_utils_ByteArray_writeBoolean_thunk  shell_toplevel_v2a_ob_thunk
#define flash_utils_Dictionary_private_init_thunk  shell_toplevel_v2a_ob_thunk

extern AvmBox shell_toplevel_i2a_oi_opti2_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define flash_trace_Trace_getLevel_thunk  shell_toplevel_i2a_oi_opti2_thunk

extern AvmBox shell_toplevel_v2a_oo_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_Domain_domainMemory_set_thunk  shell_toplevel_v2a_oo_thunk
#define avmplus_System_trace_thunk  shell_toplevel_v2a_oo_thunk
#define avmplus_Domain_private_init_thunk  shell_toplevel_v2a_oo_thunk

extern AvmBox shell_toplevel_s2a_oos_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_JObject_fieldSignature_thunk  shell_toplevel_s2a_oos_thunk

extern AvmBox shell_toplevel_v2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define flash_utils_ByteArray_private_zlib_compress_thunk  shell_toplevel_v2a_o_thunk
#define flash_utils_ByteArray_private_zlib_uncompress_thunk  shell_toplevel_v2a_o_thunk
#define avmplus_System_forceFullCollection_thunk  shell_toplevel_v2a_o_thunk
#define avmplus_System_debugger_thunk  shell_toplevel_v2a_o_thunk
#define avmplus_System_queueCollection_thunk  shell_toplevel_v2a_o_thunk
#define C_stdlib___stdlib_abort_thunk  shell_toplevel_v2a_o_thunk

extern AvmBox shell_toplevel_v2a_ou_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define flash_utils_ByteArray_position_set_thunk  shell_toplevel_v2a_ou_thunk
#define C_unistd___unistd_sleep_thunk  shell_toplevel_v2a_ou_thunk
#define flash_utils_ByteArray_length_set_thunk  shell_toplevel_v2a_ou_thunk
#define flash_utils_ByteArray_writeUnsignedInt_thunk  shell_toplevel_v2a_ou_thunk

extern AvmBox shell_toplevel_b2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_Socket_private_isValid_thunk  shell_toplevel_b2a_o_thunk
#define avmplus_Socket_broadcast_get_thunk  shell_toplevel_b2a_o_thunk
#define flash_utils_ByteArray_readBoolean_thunk  shell_toplevel_b2a_o_thunk
#define avmplus_Socket_reuseAddress_get_thunk  shell_toplevel_b2a_o_thunk
#define avmplus_System_isDebugger_thunk  shell_toplevel_b2a_o_thunk
#define avmplus_Socket_private__close_thunk  shell_toplevel_b2a_o_thunk

extern AvmBox shell_toplevel_v2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define flash_utils_ByteArray_writeUTF_thunk  shell_toplevel_v2a_os_thunk
#define flash_utils_ByteArray_endian_set_thunk  shell_toplevel_v2a_os_thunk
#define flash_utils_ByteArray_writeFile_thunk  shell_toplevel_v2a_os_thunk
#define avmplus_System_write_thunk  shell_toplevel_v2a_os_thunk
#define flash_utils_ByteArray_writeUTFBytes_thunk  shell_toplevel_v2a_os_thunk

extern AvmBox shell_toplevel_v2a_oi_opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define C_stdlib___stdlib_exit_thunk  shell_toplevel_v2a_oi_opti0_thunk

extern AvmBox shell_toplevel_b2a_oss_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_Socket_private__connect_thunk  shell_toplevel_b2a_oss_thunk

extern AvmBox shell_toplevel_i2a_osi_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define C_unistd___unistd_chmod_thunk  shell_toplevel_i2a_osi_thunk
#define C_unistd___unistd_access_thunk  shell_toplevel_i2a_osi_thunk

extern double shell_toplevel_func_d2d_oaou_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define native_script_function_flash_sampler__getInvocationCount_thunk  shell_toplevel_func_d2d_oaou_thunk

extern AvmBox shell_toplevel_a2a_oo_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_JObject_toArray_thunk  shell_toplevel_a2a_oo_thunk
#define avmplus_Domain_loadBytes_thunk  shell_toplevel_a2a_oo_thunk
#define flash_trace_Trace_setListener_thunk  shell_toplevel_a2a_oo_thunk

#endif // VMCFG_INDIRECT_NATIVE_THUNKS

class SlotOffsetsAndAsserts;
// avmplus::System$
//-----------------------------------------------------------
class _avmshell_SystemClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE ArrayObject* get_argv() const { return m_argv; }
    REALLY_INLINE AvmString get_executablePath() const { return m_executablePath; }
private:
    ArrayObject* m_argv;
    AvmString m_executablePath;
};
#define DECLARE_SLOTS_SystemClass \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE ArrayObject* get_argv() const { return m_slots_SystemClass.get_argv(); } \
        REALLY_INLINE AvmString get_executablePath() const { return m_slots_SystemClass.get_executablePath(); } \
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
class _avmshell_DomainClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_DomainClass \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::_avmshell_DomainClassSlots EmptySlotsStruct_DomainClass
//-----------------------------------------------------------

// avmplus::Domain
//-----------------------------------------------------------
class _avmshell_DomainObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_DomainObject \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::_avmshell_DomainObjectSlots EmptySlotsStruct_DomainObject
//-----------------------------------------------------------

// flash.utils::ByteArray$
//-----------------------------------------------------------
class _avmshell_ByteArrayClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_ByteArrayClass \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::_avmshell_ByteArrayClassSlots EmptySlotsStruct_ByteArrayClass
//-----------------------------------------------------------

// flash.utils::ByteArray
//-----------------------------------------------------------
class _avmshell_ByteArrayObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_ByteArrayObject \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::_avmshell_ByteArrayObjectSlots EmptySlotsStruct_ByteArrayObject
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
    void set_line(uint32_t newVal);
    REALLY_INLINE AvmString get_name() const { return m_name; }
    void set_name(StackFrameObject* obj, AvmString newVal);
    REALLY_INLINE AvmString get_file() const { return m_file; }
    void set_file(StackFrameObject* obj, AvmString newVal);
    REALLY_INLINE double get_scriptID() const { return m_scriptID; }
    void set_scriptID(double newVal);
private:
    uint32_t m_line;
    AvmString m_name;
    AvmString m_file;
    double m_scriptID;
};
REALLY_INLINE void StackFrameObjectSlots::set_line(uint32_t newVal) { m_line = newVal; }
REALLY_INLINE void StackFrameObjectSlots::set_name(StackFrameObject* obj, AvmString newVal)
{
    WBRC(((ScriptObject*)obj)->gc(), obj, &m_name, newVal);
}
REALLY_INLINE void StackFrameObjectSlots::set_file(StackFrameObject* obj, AvmString newVal)
{
    WBRC(((ScriptObject*)obj)->gc(), obj, &m_file, newVal);
}
REALLY_INLINE void StackFrameObjectSlots::set_scriptID(double newVal) { m_scriptID = newVal; }
#define DECLARE_SLOTS_StackFrameObject \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE uint32_t get_line() const { return m_slots_StackFrameObject.get_line(); } \
        REALLY_INLINE void set_line(uint32_t newVal) { m_slots_StackFrameObject.set_line(newVal); } \
        REALLY_INLINE AvmString get_name() const { return m_slots_StackFrameObject.get_name(); } \
        REALLY_INLINE void set_name(AvmString newVal) { m_slots_StackFrameObject.set_name(this, newVal); } \
        REALLY_INLINE AvmString get_file() const { return m_slots_StackFrameObject.get_file(); } \
        REALLY_INLINE void set_file(AvmString newVal) { m_slots_StackFrameObject.set_file(this, newVal); } \
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
    void set_stack(SampleObject* obj, ArrayObject* newVal);
    REALLY_INLINE double get_time() const { return m_time; }
    void set_time(double newVal);
private:
    ArrayObject* m_stack;
    double m_time;
};
REALLY_INLINE void SampleObjectSlots::set_stack(SampleObject* obj, ArrayObject* newVal)
{
    WBRC(((ScriptObject*)obj)->gc(), obj, &m_stack, newVal);
}
REALLY_INLINE void SampleObjectSlots::set_time(double newVal) { m_time = newVal; }
#define DECLARE_SLOTS_SampleObject \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE ArrayObject* get_stack() const { return m_slots_SampleObject.get_stack(); } \
        REALLY_INLINE void set_stack(ArrayObject* newVal) { m_slots_SampleObject.set_stack(this, newVal); } \
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
    void set_type(NewObjectSampleObject* obj, ClassClosure* newVal);
    REALLY_INLINE double get_id() const { return m_id; }
    void set_id(double newVal);
private:
    ClassClosure* m_type;
    double m_id;
};
REALLY_INLINE void NewObjectSampleObjectSlots::set_type(NewObjectSampleObject* obj, ClassClosure* newVal)
{
    WBRC(((ScriptObject*)obj)->gc(), obj, &m_type, newVal);
}
REALLY_INLINE void NewObjectSampleObjectSlots::set_id(double newVal) { m_id = newVal; }
#define DECLARE_SLOTS_NewObjectSampleObject \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE ClassClosure* get_type() const { return m_slots_NewObjectSampleObject.get_type(); } \
        REALLY_INLINE void set_type(ClassClosure* newVal) { m_slots_NewObjectSampleObject.set_type(this, newVal); } \
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
    void set_id(double newVal);
    REALLY_INLINE double get_size() const { return m_size; }
    void set_size(double newVal);
private:
    double m_id;
    double m_size;
};
REALLY_INLINE void DeleteObjectSampleObjectSlots::set_id(double newVal) { m_id = newVal; }
REALLY_INLINE void DeleteObjectSampleObjectSlots::set_size(double newVal) { m_size = newVal; }
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
    Atom m_FILE;
    Atom m_LISTENER;
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

// avmplus::FileSystem$
//-----------------------------------------------------------
class _avmshell_FileSystemClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_FileSystemClass \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::_avmshell_FileSystemClassSlots EmptySlotsStruct_FileSystemClass
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
    void set_private__name(::avmshell::OperatingSystemClass* obj, AvmString newVal);
    REALLY_INLINE AvmString get_private__nodename() const { return m_private__nodename; }
    void set_private__nodename(::avmshell::OperatingSystemClass* obj, AvmString newVal);
    REALLY_INLINE AvmString get_private__hostname() const { return m_private__hostname; }
    void set_private__hostname(::avmshell::OperatingSystemClass* obj, AvmString newVal);
    REALLY_INLINE AvmString get_private__release() const { return m_private__release; }
    void set_private__release(::avmshell::OperatingSystemClass* obj, AvmString newVal);
    REALLY_INLINE AvmString get_private__version() const { return m_private__version; }
    void set_private__version(::avmshell::OperatingSystemClass* obj, AvmString newVal);
    REALLY_INLINE AvmString get_private__machine() const { return m_private__machine; }
    void set_private__machine(::avmshell::OperatingSystemClass* obj, AvmString newVal);
    REALLY_INLINE AvmString get_private__vendor() const { return m_private__vendor; }
    void set_private__vendor(::avmshell::OperatingSystemClass* obj, AvmString newVal);
    REALLY_INLINE AvmString get_private__vendorname() const { return m_private__vendorname; }
    void set_private__vendorname(::avmshell::OperatingSystemClass* obj, AvmString newVal);
    REALLY_INLINE AvmString get_private__vendorversion() const { return m_private__vendorversion; }
    void set_private__vendorversion(::avmshell::OperatingSystemClass* obj, AvmString newVal);
    REALLY_INLINE AvmString get_private__vendordescription() const { return m_private__vendordescription; }
    void set_private__vendordescription(::avmshell::OperatingSystemClass* obj, AvmString newVal);
    REALLY_INLINE AvmString get_private__codename() const { return m_private__codename; }
    void set_private__codename(::avmshell::OperatingSystemClass* obj, AvmString newVal);
    REALLY_INLINE AvmString get_private__username() const { return m_private__username; }
    void set_private__username(::avmshell::OperatingSystemClass* obj, AvmString newVal);
    REALLY_INLINE AvmString get_private__linuxDistribID() const { return m_private__linuxDistribID; }
    void set_private__linuxDistribID(::avmshell::OperatingSystemClass* obj, AvmString newVal);
    REALLY_INLINE AvmString get_private__linuxDistribRelease() const { return m_private__linuxDistribRelease; }
    void set_private__linuxDistribRelease(::avmshell::OperatingSystemClass* obj, AvmString newVal);
    REALLY_INLINE AvmString get_private__linuxDistribCodename() const { return m_private__linuxDistribCodename; }
    void set_private__linuxDistribCodename(::avmshell::OperatingSystemClass* obj, AvmString newVal);
    REALLY_INLINE AvmString get_private__linuxDistribDescription() const { return m_private__linuxDistribDescription; }
    void set_private__linuxDistribDescription(::avmshell::OperatingSystemClass* obj, AvmString newVal);
    REALLY_INLINE ArrayObject* get_private__linuxReleaseFiles() const { return m_private__linuxReleaseFiles; }
    void set_private__linuxReleaseFiles(::avmshell::OperatingSystemClass* obj, ArrayObject* newVal);
    REALLY_INLINE AvmString get_private__macProductBuildVersion() const { return m_private__macProductBuildVersion; }
    void set_private__macProductBuildVersion(::avmshell::OperatingSystemClass* obj, AvmString newVal);
    REALLY_INLINE AvmString get_private__macSystemVersionFile() const { return m_private__macSystemVersionFile; }
    void set_private__macSystemVersionFile(::avmshell::OperatingSystemClass* obj, AvmString newVal);
private:
    AvmString m_private_UNKNOWN;
    AvmString m_private_EMPTY;
    AvmString m_private__name;
    AvmString m_private__nodename;
    AvmString m_private__hostname;
    AvmString m_private__release;
    AvmString m_private__version;
    AvmString m_private__machine;
    AvmString m_private__vendor;
    AvmString m_private__vendorname;
    AvmString m_private__vendorversion;
    AvmString m_private__vendordescription;
    AvmString m_private__codename;
    AvmString m_private__username;
    AvmString m_private__linuxDistribID;
    AvmString m_private__linuxDistribRelease;
    AvmString m_private__linuxDistribCodename;
    AvmString m_private__linuxDistribDescription;
    ArrayObject* m_private__linuxReleaseFiles;
    AvmString m_private__macProductBuildVersion;
    AvmString m_private__macSystemVersionFile;
};
REALLY_INLINE void _avmshell_OperatingSystemClassSlots::set_private__name(::avmshell::OperatingSystemClass* obj, AvmString newVal)
{
    WBRC(((ScriptObject*)obj)->gc(), obj, &m_private__name, newVal);
}
REALLY_INLINE void _avmshell_OperatingSystemClassSlots::set_private__nodename(::avmshell::OperatingSystemClass* obj, AvmString newVal)
{
    WBRC(((ScriptObject*)obj)->gc(), obj, &m_private__nodename, newVal);
}
REALLY_INLINE void _avmshell_OperatingSystemClassSlots::set_private__hostname(::avmshell::OperatingSystemClass* obj, AvmString newVal)
{
    WBRC(((ScriptObject*)obj)->gc(), obj, &m_private__hostname, newVal);
}
REALLY_INLINE void _avmshell_OperatingSystemClassSlots::set_private__release(::avmshell::OperatingSystemClass* obj, AvmString newVal)
{
    WBRC(((ScriptObject*)obj)->gc(), obj, &m_private__release, newVal);
}
REALLY_INLINE void _avmshell_OperatingSystemClassSlots::set_private__version(::avmshell::OperatingSystemClass* obj, AvmString newVal)
{
    WBRC(((ScriptObject*)obj)->gc(), obj, &m_private__version, newVal);
}
REALLY_INLINE void _avmshell_OperatingSystemClassSlots::set_private__machine(::avmshell::OperatingSystemClass* obj, AvmString newVal)
{
    WBRC(((ScriptObject*)obj)->gc(), obj, &m_private__machine, newVal);
}
REALLY_INLINE void _avmshell_OperatingSystemClassSlots::set_private__vendor(::avmshell::OperatingSystemClass* obj, AvmString newVal)
{
    WBRC(((ScriptObject*)obj)->gc(), obj, &m_private__vendor, newVal);
}
REALLY_INLINE void _avmshell_OperatingSystemClassSlots::set_private__vendorname(::avmshell::OperatingSystemClass* obj, AvmString newVal)
{
    WBRC(((ScriptObject*)obj)->gc(), obj, &m_private__vendorname, newVal);
}
REALLY_INLINE void _avmshell_OperatingSystemClassSlots::set_private__vendorversion(::avmshell::OperatingSystemClass* obj, AvmString newVal)
{
    WBRC(((ScriptObject*)obj)->gc(), obj, &m_private__vendorversion, newVal);
}
REALLY_INLINE void _avmshell_OperatingSystemClassSlots::set_private__vendordescription(::avmshell::OperatingSystemClass* obj, AvmString newVal)
{
    WBRC(((ScriptObject*)obj)->gc(), obj, &m_private__vendordescription, newVal);
}
REALLY_INLINE void _avmshell_OperatingSystemClassSlots::set_private__codename(::avmshell::OperatingSystemClass* obj, AvmString newVal)
{
    WBRC(((ScriptObject*)obj)->gc(), obj, &m_private__codename, newVal);
}
REALLY_INLINE void _avmshell_OperatingSystemClassSlots::set_private__username(::avmshell::OperatingSystemClass* obj, AvmString newVal)
{
    WBRC(((ScriptObject*)obj)->gc(), obj, &m_private__username, newVal);
}
REALLY_INLINE void _avmshell_OperatingSystemClassSlots::set_private__linuxDistribID(::avmshell::OperatingSystemClass* obj, AvmString newVal)
{
    WBRC(((ScriptObject*)obj)->gc(), obj, &m_private__linuxDistribID, newVal);
}
REALLY_INLINE void _avmshell_OperatingSystemClassSlots::set_private__linuxDistribRelease(::avmshell::OperatingSystemClass* obj, AvmString newVal)
{
    WBRC(((ScriptObject*)obj)->gc(), obj, &m_private__linuxDistribRelease, newVal);
}
REALLY_INLINE void _avmshell_OperatingSystemClassSlots::set_private__linuxDistribCodename(::avmshell::OperatingSystemClass* obj, AvmString newVal)
{
    WBRC(((ScriptObject*)obj)->gc(), obj, &m_private__linuxDistribCodename, newVal);
}
REALLY_INLINE void _avmshell_OperatingSystemClassSlots::set_private__linuxDistribDescription(::avmshell::OperatingSystemClass* obj, AvmString newVal)
{
    WBRC(((ScriptObject*)obj)->gc(), obj, &m_private__linuxDistribDescription, newVal);
}
REALLY_INLINE void _avmshell_OperatingSystemClassSlots::set_private__linuxReleaseFiles(::avmshell::OperatingSystemClass* obj, ArrayObject* newVal)
{
    WBRC(((ScriptObject*)obj)->gc(), obj, &m_private__linuxReleaseFiles, newVal);
}
REALLY_INLINE void _avmshell_OperatingSystemClassSlots::set_private__macProductBuildVersion(::avmshell::OperatingSystemClass* obj, AvmString newVal)
{
    WBRC(((ScriptObject*)obj)->gc(), obj, &m_private__macProductBuildVersion, newVal);
}
REALLY_INLINE void _avmshell_OperatingSystemClassSlots::set_private__macSystemVersionFile(::avmshell::OperatingSystemClass* obj, AvmString newVal)
{
    WBRC(((ScriptObject*)obj)->gc(), obj, &m_private__macSystemVersionFile, newVal);
}
#define DECLARE_SLOTS_OperatingSystemClass \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE AvmString get_private_UNKNOWN() const { return m_slots_OperatingSystemClass.get_private_UNKNOWN(); } \
        REALLY_INLINE AvmString get_private_EMPTY() const { return m_slots_OperatingSystemClass.get_private_EMPTY(); } \
        REALLY_INLINE AvmString get_private__name() const { return m_slots_OperatingSystemClass.get_private__name(); } \
        REALLY_INLINE void set_private__name(AvmString newVal) { m_slots_OperatingSystemClass.set_private__name(this, newVal); } \
        REALLY_INLINE AvmString get_private__nodename() const { return m_slots_OperatingSystemClass.get_private__nodename(); } \
        REALLY_INLINE void set_private__nodename(AvmString newVal) { m_slots_OperatingSystemClass.set_private__nodename(this, newVal); } \
        REALLY_INLINE AvmString get_private__hostname() const { return m_slots_OperatingSystemClass.get_private__hostname(); } \
        REALLY_INLINE void set_private__hostname(AvmString newVal) { m_slots_OperatingSystemClass.set_private__hostname(this, newVal); } \
        REALLY_INLINE AvmString get_private__release() const { return m_slots_OperatingSystemClass.get_private__release(); } \
        REALLY_INLINE void set_private__release(AvmString newVal) { m_slots_OperatingSystemClass.set_private__release(this, newVal); } \
        REALLY_INLINE AvmString get_private__version() const { return m_slots_OperatingSystemClass.get_private__version(); } \
        REALLY_INLINE void set_private__version(AvmString newVal) { m_slots_OperatingSystemClass.set_private__version(this, newVal); } \
        REALLY_INLINE AvmString get_private__machine() const { return m_slots_OperatingSystemClass.get_private__machine(); } \
        REALLY_INLINE void set_private__machine(AvmString newVal) { m_slots_OperatingSystemClass.set_private__machine(this, newVal); } \
        REALLY_INLINE AvmString get_private__vendor() const { return m_slots_OperatingSystemClass.get_private__vendor(); } \
        REALLY_INLINE void set_private__vendor(AvmString newVal) { m_slots_OperatingSystemClass.set_private__vendor(this, newVal); } \
        REALLY_INLINE AvmString get_private__vendorname() const { return m_slots_OperatingSystemClass.get_private__vendorname(); } \
        REALLY_INLINE void set_private__vendorname(AvmString newVal) { m_slots_OperatingSystemClass.set_private__vendorname(this, newVal); } \
        REALLY_INLINE AvmString get_private__vendorversion() const { return m_slots_OperatingSystemClass.get_private__vendorversion(); } \
        REALLY_INLINE void set_private__vendorversion(AvmString newVal) { m_slots_OperatingSystemClass.set_private__vendorversion(this, newVal); } \
        REALLY_INLINE AvmString get_private__vendordescription() const { return m_slots_OperatingSystemClass.get_private__vendordescription(); } \
        REALLY_INLINE void set_private__vendordescription(AvmString newVal) { m_slots_OperatingSystemClass.set_private__vendordescription(this, newVal); } \
        REALLY_INLINE AvmString get_private__codename() const { return m_slots_OperatingSystemClass.get_private__codename(); } \
        REALLY_INLINE void set_private__codename(AvmString newVal) { m_slots_OperatingSystemClass.set_private__codename(this, newVal); } \
        REALLY_INLINE AvmString get_private__username() const { return m_slots_OperatingSystemClass.get_private__username(); } \
        REALLY_INLINE void set_private__username(AvmString newVal) { m_slots_OperatingSystemClass.set_private__username(this, newVal); } \
        REALLY_INLINE AvmString get_private__linuxDistribID() const { return m_slots_OperatingSystemClass.get_private__linuxDistribID(); } \
        REALLY_INLINE void set_private__linuxDistribID(AvmString newVal) { m_slots_OperatingSystemClass.set_private__linuxDistribID(this, newVal); } \
        REALLY_INLINE AvmString get_private__linuxDistribRelease() const { return m_slots_OperatingSystemClass.get_private__linuxDistribRelease(); } \
        REALLY_INLINE void set_private__linuxDistribRelease(AvmString newVal) { m_slots_OperatingSystemClass.set_private__linuxDistribRelease(this, newVal); } \
        REALLY_INLINE AvmString get_private__linuxDistribCodename() const { return m_slots_OperatingSystemClass.get_private__linuxDistribCodename(); } \
        REALLY_INLINE void set_private__linuxDistribCodename(AvmString newVal) { m_slots_OperatingSystemClass.set_private__linuxDistribCodename(this, newVal); } \
        REALLY_INLINE AvmString get_private__linuxDistribDescription() const { return m_slots_OperatingSystemClass.get_private__linuxDistribDescription(); } \
        REALLY_INLINE void set_private__linuxDistribDescription(AvmString newVal) { m_slots_OperatingSystemClass.set_private__linuxDistribDescription(this, newVal); } \
        REALLY_INLINE ArrayObject* get_private__linuxReleaseFiles() const { return m_slots_OperatingSystemClass.get_private__linuxReleaseFiles(); } \
        REALLY_INLINE void set_private__linuxReleaseFiles(ArrayObject* newVal) { m_slots_OperatingSystemClass.set_private__linuxReleaseFiles(this, newVal); } \
        REALLY_INLINE AvmString get_private__macProductBuildVersion() const { return m_slots_OperatingSystemClass.get_private__macProductBuildVersion(); } \
        REALLY_INLINE void set_private__macProductBuildVersion(AvmString newVal) { m_slots_OperatingSystemClass.set_private__macProductBuildVersion(this, newVal); } \
        REALLY_INLINE AvmString get_private__macSystemVersionFile() const { return m_slots_OperatingSystemClass.get_private__macSystemVersionFile(); } \
        REALLY_INLINE void set_private__macSystemVersionFile(AvmString newVal) { m_slots_OperatingSystemClass.set_private__macSystemVersionFile(this, newVal); } \
    private: \
        avmplus::NativeID::_avmshell_OperatingSystemClassSlots m_slots_OperatingSystemClass
//-----------------------------------------------------------

// avmplus::Socket$
//-----------------------------------------------------------
class _avmshell_SocketClassSlots
{
    friend class SlotOffsetsAndAsserts;
public:
private:
};
#define DECLARE_SLOTS_SocketClass \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
        typedef avmplus::NativeID::_avmshell_SocketClassSlots EmptySlotsStruct_SocketClass
//-----------------------------------------------------------

// avmplus::Socket
//-----------------------------------------------------------
class _avmshell_SocketObjectSlots
{
    friend class SlotOffsetsAndAsserts;
public:
    REALLY_INLINE int32_t get_private__localPort() const { return m_private__localPort; }
    void set_private__localPort(int32_t newVal);
    REALLY_INLINE int32_t get_private__remotePort() const { return m_private__remotePort; }
    void set_private__remotePort(int32_t newVal);
    REALLY_INLINE AvmBool32 get_private__connected() const { return m_private__connected; }
    void set_private__connected(AvmBool32 newVal);
    REALLY_INLINE AvmBool32 get_private__bound() const { return m_private__bound; }
    void set_private__bound(AvmBool32 newVal);
    REALLY_INLINE AvmBool32 get_private__listening() const { return m_private__listening; }
    void set_private__listening(AvmBool32 newVal);
    REALLY_INLINE AvmString get_private__localAddress() const { return m_private__localAddress; }
    void set_private__localAddress(::avmshell::SocketObject* obj, AvmString newVal);
    REALLY_INLINE AvmString get_private__remoteAddress() const { return m_private__remoteAddress; }
    void set_private__remoteAddress(::avmshell::SocketObject* obj, AvmString newVal);
private:
    int32_t m_private__localPort;
    int32_t m_private__remotePort;
    AvmBool32 m_private__connected;
    AvmBool32 m_private__bound;
    AvmBool32 m_private__listening;
    AvmString m_private__localAddress;
    AvmString m_private__remoteAddress;
};
REALLY_INLINE void _avmshell_SocketObjectSlots::set_private__localPort(int32_t newVal) { m_private__localPort = newVal; }
REALLY_INLINE void _avmshell_SocketObjectSlots::set_private__remotePort(int32_t newVal) { m_private__remotePort = newVal; }
REALLY_INLINE void _avmshell_SocketObjectSlots::set_private__connected(AvmBool32 newVal) { m_private__connected = newVal; }
REALLY_INLINE void _avmshell_SocketObjectSlots::set_private__bound(AvmBool32 newVal) { m_private__bound = newVal; }
REALLY_INLINE void _avmshell_SocketObjectSlots::set_private__listening(AvmBool32 newVal) { m_private__listening = newVal; }
REALLY_INLINE void _avmshell_SocketObjectSlots::set_private__localAddress(::avmshell::SocketObject* obj, AvmString newVal)
{
    WBRC(((ScriptObject*)obj)->gc(), obj, &m_private__localAddress, newVal);
}
REALLY_INLINE void _avmshell_SocketObjectSlots::set_private__remoteAddress(::avmshell::SocketObject* obj, AvmString newVal)
{
    WBRC(((ScriptObject*)obj)->gc(), obj, &m_private__remoteAddress, newVal);
}
#define DECLARE_SLOTS_SocketObject \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE int32_t get_private__localPort() const { return m_slots_SocketObject.get_private__localPort(); } \
        REALLY_INLINE void set_private__localPort(int32_t newVal) { m_slots_SocketObject.set_private__localPort(newVal); } \
        REALLY_INLINE int32_t get_private__remotePort() const { return m_slots_SocketObject.get_private__remotePort(); } \
        REALLY_INLINE void set_private__remotePort(int32_t newVal) { m_slots_SocketObject.set_private__remotePort(newVal); } \
        REALLY_INLINE AvmBool32 get_private__connected() const { return m_slots_SocketObject.get_private__connected(); } \
        REALLY_INLINE void set_private__connected(AvmBool32 newVal) { m_slots_SocketObject.set_private__connected(newVal); } \
        REALLY_INLINE AvmBool32 get_private__bound() const { return m_slots_SocketObject.get_private__bound(); } \
        REALLY_INLINE void set_private__bound(AvmBool32 newVal) { m_slots_SocketObject.set_private__bound(newVal); } \
        REALLY_INLINE AvmBool32 get_private__listening() const { return m_slots_SocketObject.get_private__listening(); } \
        REALLY_INLINE void set_private__listening(AvmBool32 newVal) { m_slots_SocketObject.set_private__listening(newVal); } \
        REALLY_INLINE AvmString get_private__localAddress() const { return m_slots_SocketObject.get_private__localAddress(); } \
        REALLY_INLINE void set_private__localAddress(AvmString newVal) { m_slots_SocketObject.set_private__localAddress(this, newVal); } \
        REALLY_INLINE AvmString get_private__remoteAddress() const { return m_slots_SocketObject.get_private__remoteAddress(); } \
        REALLY_INLINE void set_private__remoteAddress(AvmString newVal) { m_slots_SocketObject.set_private__remoteAddress(this, newVal); } \
    private: \
        avmplus::NativeID::_avmshell_SocketObjectSlots m_slots_SocketObject
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
