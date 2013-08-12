/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/* machine generated file -- do not edit */

#ifndef _H_nativegen_header_shell_toplevel
#define _H_nativegen_header_shell_toplevel

namespace avmplus {
    class ArrayObject; // Array
    class ByteArrayObject; // flash.utils::ByteArray
    class CErrorClass; // C.errno::CError$
    class CErrorObject; // C.errno::CError
    class CapabilitiesClass; // flash.system::Capabilities$
    class CapabilitiesObject; // flash.system::Capabilities
    class ClassClosure; // Class
    class ClassFactoryClass; // flash.sampler::ClassFactory$
    class ClassFactoryObject; // flash.sampler::ClassFactory
    class DRMManagerErrorClass; // flash.errors::DRMManagerError$
    class DRMManagerErrorObject; // flash.errors::DRMManagerError
    class DeleteObjectSampleClass; // flash.sampler::DeleteObjectSample$
    class DeleteObjectSampleObject; // flash.sampler::DeleteObjectSample
    class DomainClass; // shell::Domain$
    class DomainObject; // shell::Domain
    class EndianClass; // flash.utils::Endian$
    class EndianObject; // flash.utils::Endian
    class EnvironmentClass; // shell::Environment$
    class EnvironmentObject; // shell::Environment
    class ErrorNumberClass; // C.errno::ErrorNumber$
    class ErrorNumberObject; // C.errno::ErrorNumber
    class FileIOObject; // shell::FileIO
    class InvalidSWFErrorClass; // flash.errors::InvalidSWFError$
    class InvalidSWFErrorObject; // flash.errors::InvalidSWFError
    class NewObjectSampleClass; // flash.sampler::NewObjectSample$
    class NewObjectSampleObject; // flash.sampler::NewObjectSample
    class ProgramObject; // shell::Program
    class SQLErrorClass; // flash.errors::SQLError$
    class SQLErrorObject; // flash.errors::SQLError
    class SQLErrorOperationClass; // flash.errors::SQLErrorOperation$
    class SQLErrorOperationObject; // flash.errors::SQLErrorOperation
    class SampleClass; // flash.sampler::Sample$
    class SampleObject; // flash.sampler::Sample
    class ScriptTimeoutErrorClass; // flash.errors::ScriptTimeoutError$
    class ScriptTimeoutErrorObject; // flash.errors::ScriptTimeoutError
    class StackFrameClass; // flash.sampler::StackFrame$
    class StackFrameObject; // flash.sampler::StackFrame
    class StackOverflowErrorClass; // flash.errors::StackOverflowError$
    class StackOverflowErrorObject; // flash.errors::StackOverflowError
    class String; // String
    class SystemClass; // flash.system::System$
    class SystemObject; // flash.system::System
    class TraceClass; // flash.trace::Trace$
    class TraceObject; // flash.trace::Trace
    class WorkerEventClass; // flash.system::WorkerEvent$
    class WorkerEventObject; // flash.system::WorkerEvent
    class WorkerStateClass; // flash.system::WorkerState$
    class WorkerStateObject; // flash.system::WorkerState
    class __errnoObject; // C.errno::__errno
    class __socketObject; // C.socket::__socket
    class __stdioObject; // C.stdio::__stdio
    class __stdlibObject; // C.stdlib::__stdlib
    class __stringObject; // C.string::__string
    class __unistdObject; // C.unistd::__unistd
}

namespace avmshell {
    class CErrnoClass; // C.errno::__errno$
    class CSocketClass; // C.socket::__socket$
    class CStdioClass; // C.stdio::__stdio$
    class CStdlibClass; // C.stdlib::__stdlib$
    class CStringClass; // C.string::__string$
    class CUnistdClass; // C.unistd::__unistd$
    class FileClass; // shell::FileIO$
    class ProgramClass; // shell::Program$
    class ShellWorkerClass; // flash.system::Worker$
    class ShellWorkerDomainClass; // flash.system::WorkerDomain$
    class ShellWorkerDomainObject; // flash.system::WorkerDomain
    class ShellWorkerObject; // flash.system::Worker
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
const uint32_t abcclass_C_errno___errno = 0;
const uint32_t abcclass_C_errno_ErrorNumber = 1;
const uint32_t abcclass_C_errno_CError = 2;
const uint32_t abcclass_C_stdlib___stdlib = 3;
const uint32_t abcclass_C_unistd___unistd = 4;
const uint32_t abcclass_C_string___string = 5;
const uint32_t abcclass_C_stdio___stdio = 6;
const uint32_t abcclass_C_socket___socket = 7;
const uint32_t abcclass_shell_Program = 8;
const uint32_t abcclass_shell_Domain = 9;
const uint32_t abcclass_shell_FileIO = 10;
const uint32_t abcclass_shell_Environment = 11;
const uint32_t abcclass_flash_utils_Endian = 12;
const uint32_t abcclass_flash_system_Capabilities = 13;
const uint32_t abcclass_flash_sampler_StackFrame = 14;
const uint32_t abcclass_flash_sampler_Sample = 15;
const uint32_t abcclass_flash_sampler_ClassFactory = 16;
const uint32_t abcclass_flash_trace_Trace = 17;
const uint32_t abcclass_flash_system_WorkerState = 18;
const uint32_t abcclass_flash_system_Worker = 19;
const uint32_t abcclass_flash_system_WorkerEvent = 20;
const uint32_t abcclass_flash_system_WorkerDomain = 21;
const uint32_t abcclass_flash_system_System = 22;
const uint32_t abcclass_flash_errors_ScriptTimeoutError = 23;
const uint32_t abcclass_flash_errors_StackOverflowError = 24;
const uint32_t abcclass_flash_errors_InvalidSWFError = 25;
const uint32_t abcclass_flash_errors_SQLErrorOperation = 26;
const uint32_t abcclass_flash_errors_SQLError = 27;
const uint32_t abcclass_flash_errors_DRMManagerError = 28;
const uint32_t abcclass_flash_sampler_NewObjectSample = 29;
const uint32_t abcclass_flash_sampler_DeleteObjectSample = 30;

/* methods */
const uint32_t native_script_function_C_stdio2__rename2 = 13; // native
const uint32_t C_errno___errno_EDOM_get = 42; // native
const uint32_t C_errno___errno_EILSEQ_get = 43; // native
const uint32_t C_errno___errno_ERANGE_get = 44; // native
const uint32_t C_errno___errno_EPERM_get = 45; // native
const uint32_t C_errno___errno_ENOENT_get = 46; // native
const uint32_t C_errno___errno_ESRCH_get = 47; // native
const uint32_t C_errno___errno_EINTR_get = 48; // native
const uint32_t C_errno___errno_EIO_get = 49; // native
const uint32_t C_errno___errno_ENXIO_get = 50; // native
const uint32_t C_errno___errno_E2BIG_get = 51; // native
const uint32_t C_errno___errno_ENOEXEC_get = 52; // native
const uint32_t C_errno___errno_EBADF_get = 53; // native
const uint32_t C_errno___errno_ECHILD_get = 54; // native
const uint32_t C_errno___errno_EAGAIN_get = 55; // native
const uint32_t C_errno___errno_ENOMEM_get = 56; // native
const uint32_t C_errno___errno_EACCES_get = 57; // native
const uint32_t C_errno___errno_EFAULT_get = 58; // native
const uint32_t C_errno___errno_EBUSY_get = 59; // native
const uint32_t C_errno___errno_EEXIST_get = 60; // native
const uint32_t C_errno___errno_EXDEV_get = 61; // native
const uint32_t C_errno___errno_ENODEV_get = 62; // native
const uint32_t C_errno___errno_ENOTDIR_get = 63; // native
const uint32_t C_errno___errno_EISDIR_get = 64; // native
const uint32_t C_errno___errno_EINVAL_get = 65; // native
const uint32_t C_errno___errno_ENFILE_get = 66; // native
const uint32_t C_errno___errno_EMFILE_get = 67; // native
const uint32_t C_errno___errno_ENOTTY_get = 68; // native
const uint32_t C_errno___errno_EFBIG_get = 69; // native
const uint32_t C_errno___errno_ENOSPC_get = 70; // native
const uint32_t C_errno___errno_ESPIPE_get = 71; // native
const uint32_t C_errno___errno_EROFS_get = 72; // native
const uint32_t C_errno___errno_EMLINK_get = 73; // native
const uint32_t C_errno___errno_EPIPE_get = 74; // native
const uint32_t C_errno___errno_EDEADLK_get = 75; // native
const uint32_t C_errno___errno_ENAMETOOLONG_get = 76; // native
const uint32_t C_errno___errno_ENOLCK_get = 77; // native
const uint32_t C_errno___errno_ENOSYS_get = 78; // native
const uint32_t C_errno___errno_ENOTEMPTY_get = 79; // native
const uint32_t C_errno___errno_EWOULDBLOCK_get = 80; // native
const uint32_t C_errno___errno_EINPROGRESS_get = 81; // native
const uint32_t C_errno___errno_EALREADY_get = 82; // native
const uint32_t C_errno___errno_EDESTADDRREQ_get = 83; // native
const uint32_t C_errno___errno_EMSGSIZE_get = 84; // native
const uint32_t C_errno___errno_EPROTOTYPE_get = 85; // native
const uint32_t C_errno___errno_ENOPROTOOPT_get = 86; // native
const uint32_t C_errno___errno_EADDRINUSE_get = 87; // native
const uint32_t C_errno___errno_EADDRNOTAVAIL_get = 88; // native
const uint32_t C_errno___errno_ENETDOWN_get = 89; // native
const uint32_t C_errno___errno_ENETUNREACH_get = 90; // native
const uint32_t C_errno___errno_ENETRESET_get = 91; // native
const uint32_t C_errno___errno_ECONNABORTED_get = 92; // native
const uint32_t C_errno___errno_ECONNRESET_get = 93; // native
const uint32_t C_errno___errno_ENOBUFS_get = 94; // native
const uint32_t C_errno___errno_EISCONN_get = 95; // native
const uint32_t C_errno___errno_ENOTCONN_get = 96; // native
const uint32_t C_errno___errno_ESHUTDOWN_get = 97; // native
const uint32_t C_errno___errno_ETOOMANYREFS_get = 98; // native
const uint32_t C_errno___errno_ETIMEDOUT_get = 99; // native
const uint32_t C_errno___errno_ECONNREFUSED_get = 100; // native
const uint32_t C_errno___errno_ELOOP_get = 101; // native
const uint32_t C_errno___errno_EHOSTDOWN_get = 102; // native
const uint32_t C_errno___errno_EHOSTUNREACH_get = 103; // native
const uint32_t C_errno___errno_GetErrno = 104; // native
const uint32_t C_errno___errno_SetErrno = 105; // native
const uint32_t C_errno_ErrorNumber_value_get = 109; // abc
const uint32_t C_errno_ErrorNumber_value_set = 110; // abc
const uint32_t C_errno_ErrorNumber_valueOf = 111; // abc
const uint32_t C_errno_ErrorNumber_toString = 112; // abc
const uint32_t C_stdlib___stdlib_EXIT_SUCCESS_get = 116; // native
const uint32_t C_stdlib___stdlib_EXIT_FAILURE_get = 117; // native
const uint32_t C_stdlib___stdlib_abort = 118; // native
const uint32_t C_stdlib___stdlib_exit = 119; // native
const uint32_t C_stdlib___stdlib_getenv = 120; // native
const uint32_t C_stdlib___stdlib_setenv = 121; // native
const uint32_t C_stdlib___stdlib_unsetenv = 122; // native
const uint32_t C_stdlib___stdlib_realpath = 123; // native
const uint32_t C_stdlib___stdlib___system = 124; // native
const uint32_t C_unistd___unistd_F_OK_get = 127; // native
const uint32_t C_unistd___unistd_X_OK_get = 128; // native
const uint32_t C_unistd___unistd_W_OK_get = 129; // native
const uint32_t C_unistd___unistd_R_OK_get = 130; // native
const uint32_t C_unistd___unistd_S_IFMT_get = 131; // native
const uint32_t C_unistd___unistd_S_IFIFO_get = 132; // native
const uint32_t C_unistd___unistd_S_IFCHR_get = 133; // native
const uint32_t C_unistd___unistd_S_IFDIR_get = 134; // native
const uint32_t C_unistd___unistd_S_IFBLK_get = 135; // native
const uint32_t C_unistd___unistd_S_IFREG_get = 136; // native
const uint32_t C_unistd___unistd_S_IFLNK_get = 137; // native
const uint32_t C_unistd___unistd_S_IFSOCK_get = 138; // native
const uint32_t C_unistd___unistd_S_IRWXU_get = 139; // native
const uint32_t C_unistd___unistd_S_IRUSR_get = 140; // native
const uint32_t C_unistd___unistd_S_IWUSR_get = 141; // native
const uint32_t C_unistd___unistd_S_IXUSR_get = 142; // native
const uint32_t C_unistd___unistd_S_IRWXG_get = 143; // native
const uint32_t C_unistd___unistd_S_IRGRP_get = 144; // native
const uint32_t C_unistd___unistd_S_IWGRP_get = 145; // native
const uint32_t C_unistd___unistd_S_IXGRP_get = 146; // native
const uint32_t C_unistd___unistd_S_IRWXO_get = 147; // native
const uint32_t C_unistd___unistd_S_IROTH_get = 148; // native
const uint32_t C_unistd___unistd_S_IWOTH_get = 149; // native
const uint32_t C_unistd___unistd_S_IXOTH_get = 150; // native
const uint32_t C_unistd___unistd_S_IREAD_get = 151; // native
const uint32_t C_unistd___unistd_S_IWRITE_get = 152; // native
const uint32_t C_unistd___unistd_S_IEXEC_get = 153; // native
const uint32_t C_unistd___unistd_access = 154; // native
const uint32_t C_unistd___unistd_chdir = 155; // native
const uint32_t C_unistd___unistd_chmod = 156; // native
const uint32_t C_unistd___unistd_getcwd = 157; // native
const uint32_t C_unistd___unistd_gethostname = 158; // native
const uint32_t C_unistd___unistd_getlogin = 159; // native
const uint32_t C_unistd___unistd_getpid = 160; // native
const uint32_t C_unistd___unistd_mkdir = 161; // native
const uint32_t C_unistd___unistd_rmdir = 162; // native
const uint32_t C_unistd___unistd_sleep = 163; // native
const uint32_t C_unistd___unistd_unlink = 164; // native
const uint32_t C_string___string_strerror = 167; // native
const uint32_t C_string___string_strlen = 168; // native
const uint32_t C_stdio___stdio_FILENAME_MAX_get = 171; // native
const uint32_t C_stdio___stdio_PATH_MAX_get = 172; // native
const uint32_t C_stdio___stdio_NONBLOCKING_DISABLE_get = 173; // native
const uint32_t C_stdio___stdio_NONBLOCKING_ENABLE_get = 174; // native
const uint32_t C_stdio___stdio_O_TEXT_get = 175; // native
const uint32_t C_stdio___stdio_O_BINARY_get = 176; // native
const uint32_t C_stdio___stdio_remove = 177; // native
const uint32_t C_stdio___stdio_rename = 178; // native
const uint32_t C_stdio___stdio_con_stream_mode = 179; // native
const uint32_t C_stdio___stdio_con_trans_mode = 180; // native
const uint32_t C_stdio___stdio_kbhit = 181; // native
const uint32_t C_socket___socket_SOCK_RAW_get = 184; // native
const uint32_t C_socket___socket_SOCK_STREAM_get = 185; // native
const uint32_t C_socket___socket_SOCK_DGRAM_get = 186; // native
const uint32_t C_socket___socket_SO_ACCEPTCONN_get = 187; // native
const uint32_t C_socket___socket_SO_BROADCAST_get = 188; // native
const uint32_t C_socket___socket_SO_DONTROUTE_get = 189; // native
const uint32_t C_socket___socket_SO_KEEPALIVE_get = 190; // native
const uint32_t C_socket___socket_SO_OOBINLINE_get = 191; // native
const uint32_t C_socket___socket_SO_RCVBUF_get = 192; // native
const uint32_t C_socket___socket_SO_RCVTIMEO_get = 193; // native
const uint32_t C_socket___socket_SO_REUSEADDR_get = 194; // native
const uint32_t C_socket___socket_SO_SNDBUF_get = 195; // native
const uint32_t C_socket___socket_SO_SNDTIMEO_get = 196; // native
const uint32_t C_socket___socket_SO_TYPE_get = 197; // native
const uint32_t C_socket___socket_MSG_CTRUNC_get = 198; // native
const uint32_t C_socket___socket_MSG_DONTROUTE_get = 199; // native
const uint32_t C_socket___socket_MSG_OOB_get = 200; // native
const uint32_t C_socket___socket_MSG_PEEK_get = 201; // native
const uint32_t C_socket___socket_MSG_TRUNC_get = 202; // native
const uint32_t C_socket___socket_MSG_WAITALL_get = 203; // native
const uint32_t C_socket___socket_MSG_DONTWAIT_get = 204; // native
const uint32_t C_socket___socket_AF_INET_get = 205; // native
const uint32_t C_socket___socket_AF_INET6_get = 206; // native
const uint32_t C_socket___socket_AF_UNSPEC_get = 207; // native
const uint32_t C_socket___socket_SHUT_RD_get = 208; // native
const uint32_t C_socket___socket_SHUT_RDWR_get = 209; // native
const uint32_t C_socket___socket_SHUT_WR_get = 210; // native
const uint32_t C_socket___socket_IPPROTO_IP_get = 211; // native
const uint32_t C_socket___socket_IPPROTO_IPV6_get = 212; // native
const uint32_t C_socket___socket_IPPROTO_ICMP_get = 213; // native
const uint32_t C_socket___socket_IPPROTO_RAW_get = 214; // native
const uint32_t C_socket___socket_IPPROTO_TCP_get = 215; // native
const uint32_t C_socket___socket_IPPROTO_UDP_get = 216; // native
const uint32_t C_socket___socket_SOMAXCONN_get = 217; // native
const uint32_t C_socket___socket___gethostbyaddr = 218; // native
const uint32_t C_socket___socket___gethostbyname = 219; // native
const uint32_t C_socket___socket___getpeername = 220; // native
const uint32_t C_socket___socket___getsockname = 221; // native
const uint32_t shell_Program_private_getArgv = 224; // native
const uint32_t shell_Program_private_popenRead = 225; // native
const uint32_t shell_Program_private__findShell = 226; // abc
const uint32_t shell_Program_apiVersion_get = 227; // native
const uint32_t shell_Program_apiAlias_get = 228; // abc
const uint32_t shell_Program_pid_get = 229; // abc
const uint32_t shell_Program_programFilename_get = 230; // native
const uint32_t shell_Program_shell_get = 231; // abc
const uint32_t shell_Program_swfVersion_get = 232; // native
const uint32_t shell_Program_totalMemory_get = 233; // native
const uint32_t shell_Program_freeMemory_get = 234; // native
const uint32_t shell_Program_privateMemory_get = 235; // native
const uint32_t shell_Program_workingDirectory_get = 236; // abc
const uint32_t shell_Program_workingDirectory_set = 237; // abc
const uint32_t shell_Program_throwCError = 238; // abc
const uint32_t shell_Program_eval = 239; // native
const uint32_t shell_Program_exec = 240; // native
const uint32_t shell_Program_exit = 241; // native
const uint32_t shell_Program_popen = 242; // abc
const uint32_t shell_Program_getAvmplusVersion = 243; // native
const uint32_t shell_Program_getEnviron = 244; // native
const uint32_t shell_Program_getRedtamarinVersion = 245; // abc
const uint32_t shell_Program_getFeatures = 246; // native
const uint32_t shell_Program_getNanosecondTimer = 247; // native
const uint32_t shell_Program_getRunmode = 248; // native
const uint32_t shell_Program_getTimer = 249; // native
const uint32_t shell_Program_readLine = 250; // native
const uint32_t shell_Program_sleep = 251; // native
const uint32_t shell_Program_trace = 252; // native
const uint32_t shell_Program_write = 253; // native
const uint32_t shell_Program_writeLine = 254; // abc
const uint32_t shell_Program_debugger = 255; // native
const uint32_t shell_Program_isDebugger = 256; // native
const uint32_t shell_Program_forceFullCollection = 257; // native
const uint32_t shell_Program_queueCollection = 258; // native
const uint32_t shell_Program_pauseForGCIfCollectionImminent = 259; // native
const uint32_t shell_Program_disposeXML = 260; // native
const uint32_t shell_Program_isGlobal = 261; // native
const uint32_t shell_Program_is64bit = 262; // native
const uint32_t shell_Program_isIntptr = 263; // native
const uint32_t shell_Program_canonicalizeNumber = 264; // native
const uint32_t shell_Program_deopt = 265; // native
const uint32_t shell_Program_runInSafepoint = 266; // native
const uint32_t shell_Domain_currentDomain_get = 269; // native
const uint32_t shell_Domain_MIN_DOMAIN_MEMORY_LENGTH_get = 270; // native
const uint32_t shell_Domain_private_init = 271; // native
const uint32_t shell_Domain_loadBytes = 273; // native
const uint32_t shell_Domain_getClass = 274; // native
const uint32_t shell_Domain_load = 275; // abc
const uint32_t shell_Domain_domainMemory_get = 276; // native
const uint32_t shell_Domain_domainMemory_set = 277; // native
const uint32_t shell_FileIO_exists = 279; // native
const uint32_t shell_FileIO_read = 280; // native
const uint32_t shell_FileIO_write = 281; // native
const uint32_t shell_FileIO_readByteArray = 282; // native
const uint32_t shell_FileIO_writeByteArray = 283; // native
const uint32_t shell_Environment_private__parse = 287; // abc
const uint32_t shell_Environment_http___www_adobe_com_2006_actionscript_flash_proxy_callProperty = 288; // abc
const uint32_t shell_Environment_http___www_adobe_com_2006_actionscript_flash_proxy_deleteProperty = 289; // abc
const uint32_t shell_Environment_http___www_adobe_com_2006_actionscript_flash_proxy_getProperty = 290; // abc
const uint32_t shell_Environment_http___www_adobe_com_2006_actionscript_flash_proxy_setProperty = 291; // abc
const uint32_t shell_Environment_http___www_adobe_com_2006_actionscript_flash_proxy_hasProperty = 292; // abc
const uint32_t shell_Environment_http___www_adobe_com_2006_actionscript_flash_proxy_nextNameIndex = 293; // abc
const uint32_t shell_Environment_http___www_adobe_com_2006_actionscript_flash_proxy_nextName = 294; // abc
const uint32_t shell_Environment_http___www_adobe_com_2006_actionscript_flash_proxy_nextValue = 295; // abc
const uint32_t shell_Environment_length_get = 296; // abc
const uint32_t shell_Environment_refresh = 297; // abc
const uint32_t native_script_function_flash_sampler_getMasterString = 299; // native
const uint32_t native_script_function_flash_sampler_getSavedThis = 300; // native
const uint32_t native_script_function_flash_sampler_getLexicalScopes = 301; // native
const uint32_t native_script_function_flash_sampler_isGetterSetter = 302; // native
const uint32_t native_script_function_flash_sampler__getInvocationCount = 303; // native
const uint32_t native_script_function_flash_sampler_getSampleCount = 307; // native
const uint32_t native_script_function_flash_sampler__getSamples = 308; // native
const uint32_t native_script_function_flash_sampler_getMemberNames = 310; // native
const uint32_t native_script_function_flash_sampler_getSize = 311; // native
const uint32_t native_script_function_flash_sampler__setSamplerCallback = 312; // native
const uint32_t native_script_function_flash_sampler_sampleInternalAllocs = 315; // native
const uint32_t native_script_function_flash_sampler_pauseSampling = 316; // native
const uint32_t native_script_function_flash_sampler_stopSampling = 317; // native
const uint32_t native_script_function_flash_sampler_startSampling = 318; // native
const uint32_t native_script_function_flash_sampler_clearSamples = 319; // native
const uint32_t flash_system_Capabilities_playerType_get = 323; // abc
const uint32_t flash_system_Capabilities_isDebugger_get = 324; // abc
const uint32_t flash_sampler_StackFrame_toString = 327; // abc
const uint32_t flash_trace_Trace_setLevel = 334; // native
const uint32_t flash_trace_Trace_getLevel = 335; // native
const uint32_t flash_trace_Trace_setListener = 336; // native
const uint32_t flash_trace_Trace_getListener = 337; // native
const uint32_t flash_system_WorkerState_code = 340; // abc
const uint32_t flash_system_Worker_current_get = 343; // abc
const uint32_t flash_system_Worker_pr = 344; // native
const uint32_t flash_system_Worker_state_get = 346; // native
const uint32_t flash_system_Worker_start = 347; // native
const uint32_t flash_system_Worker_isParentOf = 348; // native
const uint32_t flash_system_Worker_isPrimordial_get = 349; // native
const uint32_t flash_system_Worker_setSharedProperty = 350; // native
const uint32_t flash_system_Worker_getSharedProperty = 351; // native
const uint32_t flash_system_Worker_terminate = 352; // native
const uint32_t flash_system_WorkerEvent_currentState_get = 355; // abc
const uint32_t flash_system_WorkerEvent_previousState_get = 356; // abc
const uint32_t flash_system_WorkerEvent_target_get = 357; // abc
const uint32_t flash_system_WorkerDomain_current_get = 359; // abc
const uint32_t flash_system_WorkerDomain_createWorkerFromByteArray = 361; // abc
const uint32_t flash_system_WorkerDomain_createWorkerFromPrimordial = 362; // abc
const uint32_t flash_system_WorkerDomain_private_createWorkerFromByteArrayInternal = 363; // native
const uint32_t flash_system_WorkerDomain_listWorkers = 364; // native
const uint32_t flash_system_System_setClipboard = 366; // abc
const uint32_t flash_system_System_totalMemory_get = 367; // abc
const uint32_t flash_system_System_totalMemoryNumber_get = 368; // abc
const uint32_t flash_system_System_freeMemory_get = 369; // abc
const uint32_t flash_system_System_privateMemory_get = 370; // abc
const uint32_t flash_system_System_useCodePage_get = 371; // abc
const uint32_t flash_system_System_useCodePage_set = 372; // abc
const uint32_t flash_system_System_vmVersion_get = 373; // abc
const uint32_t flash_system_System_pause = 374; // abc
const uint32_t flash_system_System_resume = 375; // abc
const uint32_t flash_system_System_exit = 376; // abc
const uint32_t flash_system_System_gc = 377; // abc
const uint32_t flash_system_System_disposeXML = 378; // abc
const uint32_t flash_errors_SQLError_operation_get = 390; // abc
const uint32_t flash_errors_SQLError_details_get = 391; // abc
const uint32_t flash_errors_SQLError_detailID_get = 392; // abc
const uint32_t flash_errors_SQLError_detailArguments_get = 393; // abc
const uint32_t flash_errors_DRMManagerError_subErrorID_get = 396; // abc
const uint32_t flash_sampler_NewObjectSample_object_get = 398; // native
const uint32_t flash_sampler_NewObjectSample_size_get = 399; // native

extern avmplus::Atom C_errno___errno_EDOM_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EDOM_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EILSEQ_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EILSEQ_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ERANGE_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ERANGE_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EPERM_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EPERM_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENOENT_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENOENT_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ESRCH_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ESRCH_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EINTR_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EINTR_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EIO_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EIO_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENXIO_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENXIO_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_E2BIG_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_E2BIG_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENOEXEC_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENOEXEC_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EBADF_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EBADF_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ECHILD_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ECHILD_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EAGAIN_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EAGAIN_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENOMEM_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENOMEM_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EACCES_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EACCES_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EFAULT_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EFAULT_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EBUSY_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EBUSY_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EEXIST_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EEXIST_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EXDEV_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EXDEV_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENODEV_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENODEV_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENOTDIR_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENOTDIR_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EISDIR_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EISDIR_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EINVAL_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EINVAL_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENFILE_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENFILE_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EMFILE_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EMFILE_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENOTTY_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENOTTY_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EFBIG_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EFBIG_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENOSPC_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENOSPC_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ESPIPE_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ESPIPE_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EROFS_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EROFS_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EMLINK_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EMLINK_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EPIPE_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EPIPE_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EDEADLK_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EDEADLK_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENAMETOOLONG_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENAMETOOLONG_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENOLCK_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENOLCK_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENOSYS_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENOSYS_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENOTEMPTY_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENOTEMPTY_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EWOULDBLOCK_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EWOULDBLOCK_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EINPROGRESS_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EINPROGRESS_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EALREADY_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EALREADY_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EDESTADDRREQ_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EDESTADDRREQ_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EMSGSIZE_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EMSGSIZE_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EPROTOTYPE_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EPROTOTYPE_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENOPROTOOPT_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENOPROTOOPT_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EADDRINUSE_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EADDRINUSE_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EADDRNOTAVAIL_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EADDRNOTAVAIL_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENETDOWN_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENETDOWN_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENETUNREACH_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENETUNREACH_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENETRESET_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENETRESET_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ECONNABORTED_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ECONNABORTED_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ECONNRESET_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ECONNRESET_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENOBUFS_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENOBUFS_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EISCONN_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EISCONN_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENOTCONN_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ENOTCONN_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ESHUTDOWN_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ESHUTDOWN_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ETOOMANYREFS_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ETOOMANYREFS_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ETIMEDOUT_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ETIMEDOUT_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ECONNREFUSED_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ECONNREFUSED_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ELOOP_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_ELOOP_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EHOSTDOWN_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EHOSTDOWN_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EHOSTUNREACH_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_EHOSTUNREACH_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_GetErrno_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_GetErrno_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_SetErrno_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_errno___errno_SetErrno_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdlib___stdlib_EXIT_SUCCESS_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdlib___stdlib_EXIT_SUCCESS_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdlib___stdlib_EXIT_FAILURE_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdlib___stdlib_EXIT_FAILURE_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdlib___stdlib_abort_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdlib___stdlib_abort_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdlib___stdlib_exit_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdlib___stdlib_exit_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdlib___stdlib_getenv_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdlib___stdlib_getenv_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdlib___stdlib_setenv_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdlib___stdlib_setenv_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdlib___stdlib_unsetenv_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdlib___stdlib_unsetenv_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdlib___stdlib_realpath_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdlib___stdlib_realpath_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdlib___stdlib___system_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdlib___stdlib___system_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_F_OK_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_F_OK_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_X_OK_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_X_OK_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_W_OK_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_W_OK_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_R_OK_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_R_OK_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IFMT_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IFMT_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IFIFO_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IFIFO_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IFCHR_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IFCHR_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IFDIR_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IFDIR_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IFBLK_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IFBLK_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IFREG_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IFREG_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IFLNK_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IFLNK_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IFSOCK_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IFSOCK_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IRWXU_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IRWXU_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IRUSR_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IRUSR_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IWUSR_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IWUSR_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IXUSR_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IXUSR_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IRWXG_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IRWXG_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IRGRP_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IRGRP_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IWGRP_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IWGRP_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IXGRP_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IXGRP_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IRWXO_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IRWXO_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IROTH_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IROTH_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IWOTH_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IWOTH_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IXOTH_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IXOTH_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IREAD_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IREAD_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IWRITE_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IWRITE_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IEXEC_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_S_IEXEC_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_access_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_access_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_chdir_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_chdir_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_chmod_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_chmod_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_getcwd_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_getcwd_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_gethostname_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_gethostname_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_getlogin_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_getlogin_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_getpid_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_getpid_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_mkdir_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_mkdir_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_rmdir_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_rmdir_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_sleep_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_sleep_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_unlink_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_unistd___unistd_unlink_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_string___string_strerror_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_string___string_strerror_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_string___string_strlen_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_string___string_strlen_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdio___stdio_FILENAME_MAX_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdio___stdio_FILENAME_MAX_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdio___stdio_PATH_MAX_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdio___stdio_PATH_MAX_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdio___stdio_NONBLOCKING_DISABLE_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdio___stdio_NONBLOCKING_DISABLE_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdio___stdio_NONBLOCKING_ENABLE_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdio___stdio_NONBLOCKING_ENABLE_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdio___stdio_O_TEXT_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdio___stdio_O_TEXT_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdio___stdio_O_BINARY_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdio___stdio_O_BINARY_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdio___stdio_remove_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdio___stdio_remove_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdio___stdio_rename_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdio___stdio_rename_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdio___stdio_con_stream_mode_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdio___stdio_con_stream_mode_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdio___stdio_con_trans_mode_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdio___stdio_con_trans_mode_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdio___stdio_kbhit_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_stdio___stdio_kbhit_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_C_stdio2__rename2_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_C_stdio2__rename2_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SOCK_RAW_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SOCK_RAW_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SOCK_STREAM_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SOCK_STREAM_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SOCK_DGRAM_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SOCK_DGRAM_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SO_ACCEPTCONN_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SO_ACCEPTCONN_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SO_BROADCAST_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SO_BROADCAST_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SO_DONTROUTE_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SO_DONTROUTE_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SO_KEEPALIVE_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SO_KEEPALIVE_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SO_OOBINLINE_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SO_OOBINLINE_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SO_RCVBUF_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SO_RCVBUF_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SO_RCVTIMEO_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SO_RCVTIMEO_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SO_REUSEADDR_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SO_REUSEADDR_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SO_SNDBUF_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SO_SNDBUF_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SO_SNDTIMEO_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SO_SNDTIMEO_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SO_TYPE_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SO_TYPE_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_MSG_CTRUNC_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_MSG_CTRUNC_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_MSG_DONTROUTE_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_MSG_DONTROUTE_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_MSG_OOB_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_MSG_OOB_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_MSG_PEEK_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_MSG_PEEK_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_MSG_TRUNC_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_MSG_TRUNC_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_MSG_WAITALL_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_MSG_WAITALL_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_MSG_DONTWAIT_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_MSG_DONTWAIT_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_AF_INET_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_AF_INET_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_AF_INET6_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_AF_INET6_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_AF_UNSPEC_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_AF_UNSPEC_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SHUT_RD_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SHUT_RD_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SHUT_RDWR_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SHUT_RDWR_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SHUT_WR_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SHUT_WR_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_IPPROTO_IP_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_IPPROTO_IP_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_IPPROTO_IPV6_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_IPPROTO_IPV6_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_IPPROTO_ICMP_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_IPPROTO_ICMP_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_IPPROTO_RAW_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_IPPROTO_RAW_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_IPPROTO_TCP_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_IPPROTO_TCP_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_IPPROTO_UDP_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_IPPROTO_UDP_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SOMAXCONN_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket_SOMAXCONN_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket___gethostbyaddr_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket___gethostbyaddr_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket___gethostbyname_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket___gethostbyname_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket___getpeername_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket___getpeername_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket___getsockname_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom C_socket___socket___getsockname_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_private_getArgv_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_private_getArgv_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_private_popenRead_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_private_popenRead_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_apiVersion_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_apiVersion_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_programFilename_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_programFilename_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_swfVersion_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_swfVersion_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double shell_Program_totalMemory_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double shell_Program_totalMemory_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double shell_Program_freeMemory_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double shell_Program_freeMemory_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double shell_Program_privateMemory_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double shell_Program_privateMemory_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_eval_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_eval_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_exec_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_exec_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_exit_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_exit_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_getAvmplusVersion_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_getAvmplusVersion_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_getEnviron_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_getEnviron_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_getFeatures_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_getFeatures_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double shell_Program_getNanosecondTimer_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double shell_Program_getNanosecondTimer_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_getRunmode_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_getRunmode_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_getTimer_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_getTimer_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_readLine_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_readLine_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_sleep_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_sleep_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_trace_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_trace_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_write_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_write_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_debugger_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_debugger_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_isDebugger_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_isDebugger_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_forceFullCollection_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_forceFullCollection_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_queueCollection_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_queueCollection_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_pauseForGCIfCollectionImminent_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_pauseForGCIfCollectionImminent_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_disposeXML_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_disposeXML_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_isGlobal_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_isGlobal_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_is64bit_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_is64bit_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_isIntptr_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_isIntptr_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_canonicalizeNumber_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_canonicalizeNumber_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_deopt_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_deopt_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_runInSafepoint_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Program_runInSafepoint_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Domain_currentDomain_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Domain_currentDomain_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Domain_MIN_DOMAIN_MEMORY_LENGTH_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Domain_MIN_DOMAIN_MEMORY_LENGTH_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Domain_private_init_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Domain_private_init_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Domain_loadBytes_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Domain_loadBytes_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Domain_getClass_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Domain_getClass_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Domain_domainMemory_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Domain_domainMemory_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Domain_domainMemory_set_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_Domain_domainMemory_set_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_FileIO_exists_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_FileIO_exists_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_FileIO_read_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_FileIO_read_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_FileIO_write_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_FileIO_write_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_FileIO_readByteArray_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_FileIO_readByteArray_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_FileIO_writeByteArray_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom shell_FileIO_writeByteArray_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_sampler_NewObjectSample_object_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_sampler_NewObjectSample_object_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double flash_sampler_NewObjectSample_size_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double flash_sampler_NewObjectSample_size_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_clearSamples_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_clearSamples_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_startSampling_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_startSampling_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_stopSampling_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_stopSampling_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_pauseSampling_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_pauseSampling_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_sampleInternalAllocs_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_sampleInternalAllocs_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler__setSamplerCallback_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler__setSamplerCallback_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double native_script_function_flash_sampler_getSize_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double native_script_function_flash_sampler_getSize_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_getMemberNames_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_getMemberNames_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler__getSamples_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler__getSamples_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double native_script_function_flash_sampler_getSampleCount_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double native_script_function_flash_sampler_getSampleCount_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double native_script_function_flash_sampler__getInvocationCount_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern double native_script_function_flash_sampler__getInvocationCount_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_isGetterSetter_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_isGetterSetter_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_getLexicalScopes_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_getLexicalScopes_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_getSavedThis_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_getSavedThis_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_getMasterString_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom native_script_function_flash_sampler_getMasterString_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_trace_Trace_setLevel_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_trace_Trace_setLevel_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_trace_Trace_getLevel_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_trace_Trace_getLevel_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_trace_Trace_setListener_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_trace_Trace_setListener_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_trace_Trace_getListener_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_trace_Trace_getListener_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_pr_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_pr_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_state_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_state_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_start_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_start_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_isParentOf_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_isParentOf_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_isPrimordial_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_isPrimordial_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_setSharedProperty_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_setSharedProperty_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_getSharedProperty_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_getSharedProperty_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_terminate_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_Worker_terminate_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_WorkerDomain_private_createWorkerFromByteArrayInternal_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_WorkerDomain_private_createWorkerFromByteArrayInternal_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_WorkerDomain_listWorkers_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
extern avmplus::Atom flash_system_WorkerDomain_listWorkers_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv);
class SlotOffsetsAndAsserts;
//-----------------------------------------------------------
// C.errno::__errno$
//-----------------------------------------------------------
class avmshell_CErrnoClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::CErrnoClass;
};
#define DECLARE_SLOTS_CErrnoClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::__errnoObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::__errnoObject>((avmplus::__errnoObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::__errnoObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::__errnoObject>((avmplus::__errnoObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::__errnoObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::__errnoObject>((avmplus::__errnoObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::__errnoObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::__errnoObject>((avmplus::__errnoObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// C.errno::__errno
//-----------------------------------------------------------
class avmplus___errnoObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::__errnoObject;
#define GC_TRIVIAL_TRACER___errnoObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// C.errno::ErrorNumber$
//-----------------------------------------------------------
class avmplus_ErrorNumberClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::ErrorNumberClass;
#define GC_TRIVIAL_TRACER_ErrorNumberClass
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// C.errno::ErrorNumber
//-----------------------------------------------------------
class avmplus_ErrorNumberObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::ErrorNumberObject;
private:
    int32_t m_private__value;
#define GC_TRIVIAL_TRACER_ErrorNumberObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// C.errno::CError$
//-----------------------------------------------------------
class avmplus_CErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::CErrorClass;
#define GC_TRIVIAL_TRACER_CErrorClass
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// C.errno::CError
//-----------------------------------------------------------
class avmplus_CErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::CErrorObject;
#define GC_TRIVIAL_TRACER_CErrorObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// C.stdlib::__stdlib$
//-----------------------------------------------------------
class avmshell_CStdlibClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::CStdlibClass;
};
#define DECLARE_SLOTS_CStdlibClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::__stdlibObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::__stdlibObject>((avmplus::__stdlibObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::__stdlibObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::__stdlibObject>((avmplus::__stdlibObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::__stdlibObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::__stdlibObject>((avmplus::__stdlibObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::__stdlibObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::__stdlibObject>((avmplus::__stdlibObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// C.stdlib::__stdlib
//-----------------------------------------------------------
class avmplus___stdlibObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::__stdlibObject;
#define GC_TRIVIAL_TRACER___stdlibObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// C.unistd::__unistd$
//-----------------------------------------------------------
class avmshell_CUnistdClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::CUnistdClass;
};
#define DECLARE_SLOTS_CUnistdClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::__unistdObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::__unistdObject>((avmplus::__unistdObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::__unistdObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::__unistdObject>((avmplus::__unistdObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::__unistdObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::__unistdObject>((avmplus::__unistdObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::__unistdObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::__unistdObject>((avmplus::__unistdObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// C.unistd::__unistd
//-----------------------------------------------------------
class avmplus___unistdObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::__unistdObject;
#define GC_TRIVIAL_TRACER___unistdObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// C.string::__string$
//-----------------------------------------------------------
class avmshell_CStringClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::CStringClass;
};
#define DECLARE_SLOTS_CStringClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::__stringObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::__stringObject>((avmplus::__stringObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::__stringObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::__stringObject>((avmplus::__stringObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::__stringObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::__stringObject>((avmplus::__stringObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::__stringObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::__stringObject>((avmplus::__stringObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// C.string::__string
//-----------------------------------------------------------
class avmplus___stringObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::__stringObject;
#define GC_TRIVIAL_TRACER___stringObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// C.stdio::__stdio$
//-----------------------------------------------------------
class avmshell_CStdioClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::CStdioClass;
};
#define DECLARE_SLOTS_CStdioClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::__stdioObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::__stdioObject>((avmplus::__stdioObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::__stdioObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::__stdioObject>((avmplus::__stdioObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::__stdioObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::__stdioObject>((avmplus::__stdioObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::__stdioObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::__stdioObject>((avmplus::__stdioObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// C.stdio::__stdio
//-----------------------------------------------------------
class avmplus___stdioObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::__stdioObject;
#define GC_TRIVIAL_TRACER___stdioObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// C.socket::__socket$
//-----------------------------------------------------------
class avmshell_CSocketClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::CSocketClass;
};
#define DECLARE_SLOTS_CSocketClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::__socketObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::__socketObject>((avmplus::__socketObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::__socketObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::__socketObject>((avmplus::__socketObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::__socketObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::__socketObject>((avmplus::__socketObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::__socketObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::__socketObject>((avmplus::__socketObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// C.socket::__socket
//-----------------------------------------------------------
class avmplus___socketObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::__socketObject;
#define GC_TRIVIAL_TRACER___socketObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// shell::Program$
//-----------------------------------------------------------
class avmshell_ProgramClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::ProgramClass;
private:
    avmplus::bool32 m_enableThrowCError;
    MMgc::GCTraceableObject::GCMember<avmplus::ArrayObject> m_private__API;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_private__shell;
    MMgc::GCTraceableObject::GCMember<avmplus::ArrayObject> m_argv;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_startupDirectory;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceLocation(&m_private__API);
        gc->TraceLocation(&m_private__shell);
        gc->TraceLocation(&m_argv);
        gc->TraceLocation(&m_startupDirectory);
    }
};
#define DECLARE_SLOTS_ProgramClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::ProgramObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::ProgramObject>((avmplus::ProgramObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ProgramObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::ProgramObject>((avmplus::ProgramObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ProgramObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::ProgramObject>((avmplus::ProgramObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::ProgramObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::ProgramObject>((avmplus::ProgramObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE bool get_enableThrowCError() const { return m_slots_ProgramClass.m_enableThrowCError != 0; } \
        REALLY_INLINE void set_enableThrowCError(avmplus::bool32 newVal) { m_slots_ProgramClass.m_enableThrowCError = newVal; } \
    protected: \
        REALLY_INLINE avmplus::ArrayObject* get__API() const { return m_slots_ProgramClass.m_private__API; } \
        REALLY_INLINE void set__API(avmplus::ArrayObject* newVal) { m_slots_ProgramClass.m_private__API = newVal; } \
    protected: \
        REALLY_INLINE avmplus::String* get__shell() const { return m_slots_ProgramClass.m_private__shell; } \
        REALLY_INLINE void set__shell(avmplus::String* newVal) { m_slots_ProgramClass.m_private__shell = newVal; } \
    public: \
        REALLY_INLINE avmplus::ArrayObject* get_argv() const { return m_slots_ProgramClass.m_argv; } \
        REALLY_INLINE void setconst_argv(avmplus::ArrayObject* newVal) { m_slots_ProgramClass.m_argv = newVal; } \
    public: \
        REALLY_INLINE avmplus::String* get_startupDirectory() const { return m_slots_ProgramClass.m_startupDirectory; } \
        REALLY_INLINE void setconst_startupDirectory(avmplus::String* newVal) { m_slots_ProgramClass.m_startupDirectory = newVal; } \
    private: \
        avmplus::NativeID::avmshell_ProgramClassSlots m_slots_ProgramClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// shell::Program
//-----------------------------------------------------------
class avmplus_ProgramObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::ProgramObject;
#define GC_TRIVIAL_TRACER_ProgramObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// shell::Domain$
//-----------------------------------------------------------
class avmplus_DomainClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::DomainClass;
#define GC_TRIVIAL_TRACER_DomainClass
};
#define DECLARE_SLOTS_DomainClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::DomainObject> constructObject(GCRef<avmplus::DomainObject> arg1) \
        { \
            avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(1, args); \
            return GCRef<avmplus::DomainObject>((avmplus::DomainObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::DomainObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::DomainObject>((avmplus::DomainObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::DomainObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::DomainObject>((avmplus::DomainObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::DomainObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::DomainObject>((avmplus::DomainObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::DomainObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::DomainObject>((avmplus::DomainObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// shell::Domain
//-----------------------------------------------------------
class avmplus_DomainObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::DomainObject;
#define GC_TRIVIAL_TRACER_DomainObject
};
#define DECLARE_SLOTS_DomainObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// shell::FileIO$
//-----------------------------------------------------------
class avmshell_FileClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::FileClass;
};
#define DECLARE_SLOTS_FileClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::FileIOObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::FileIOObject>((avmplus::FileIOObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::FileIOObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::FileIOObject>((avmplus::FileIOObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::FileIOObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::FileIOObject>((avmplus::FileIOObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::FileIOObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::FileIOObject>((avmplus::FileIOObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// shell::FileIO
//-----------------------------------------------------------
class avmplus_FileIOObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::FileIOObject;
#define GC_TRIVIAL_TRACER_FileIOObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// shell::Environment$
//-----------------------------------------------------------
class avmplus_EnvironmentClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::EnvironmentClass;
#define GC_TRIVIAL_TRACER_EnvironmentClass
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// shell::Environment
//-----------------------------------------------------------
class avmplus_EnvironmentObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::EnvironmentObject;
private:
    MMgc::GCTraceableObject::GCMember<avmplus::ArrayObject> m_private__vars;
    MMgc::GCTraceableObject::GCMember<avmplus::ArrayObject> m_private__idx;
    avmplus::AtomWB m_private__env;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceLocation(&m_private__vars);
        gc->TraceLocation(&m_private__idx);
        gc->TraceAtom(&m_private__env);
    }
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.utils::Endian$
//-----------------------------------------------------------
class avmplus_EndianClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::EndianClass;
private:
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_BIG_ENDIAN;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_LITTLE_ENDIAN;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceLocation(&m_BIG_ENDIAN);
        gc->TraceLocation(&m_LITTLE_ENDIAN);
    }
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.utils::Endian
//-----------------------------------------------------------
class avmplus_EndianObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::EndianObject;
#define GC_TRIVIAL_TRACER_EndianObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.system::Capabilities$
//-----------------------------------------------------------
class avmplus_CapabilitiesClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::CapabilitiesClass;
#define GC_TRIVIAL_TRACER_CapabilitiesClass
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.system::Capabilities
//-----------------------------------------------------------
class avmplus_CapabilitiesObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::CapabilitiesObject;
#define GC_TRIVIAL_TRACER_CapabilitiesObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.sampler::StackFrame$
//-----------------------------------------------------------
class avmplus_StackFrameClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::StackFrameClass;
#define GC_TRIVIAL_TRACER_StackFrameClass
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.sampler::StackFrame
//-----------------------------------------------------------
class avmplus_StackFrameObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::StackFrameObject;
private:
    uint32_t m_line;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_name;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_file;
    double m_scriptID;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceLocation(&m_name);
        gc->TraceLocation(&m_file);
    }
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.sampler::Sample$
//-----------------------------------------------------------
class avmplus_SampleClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::SampleClass;
#define GC_TRIVIAL_TRACER_SampleClass
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.sampler::Sample
//-----------------------------------------------------------
class avmplus_SampleObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::SampleObject;
private:
    MMgc::GCTraceableObject::GCMember<avmplus::ArrayObject> m_stack;
    double m_time;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceLocation(&m_stack);
    }
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.sampler::ClassFactory$
//-----------------------------------------------------------
class avmplus_ClassFactoryClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::ClassFactoryClass;
private:
    MMgc::GCTraceableObject::GCMember<avmplus::ClassClosure> m_StackFrameClass;
    MMgc::GCTraceableObject::GCMember<avmplus::ClassClosure> m_SampleClass;
    MMgc::GCTraceableObject::GCMember<avmplus::ClassClosure> m_DeleteObjectSampleClass;
    MMgc::GCTraceableObject::GCMember<avmplus::ClassClosure> m_NewObjectSampleClass;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceLocation(&m_StackFrameClass);
        gc->TraceLocation(&m_SampleClass);
        gc->TraceLocation(&m_DeleteObjectSampleClass);
        gc->TraceLocation(&m_NewObjectSampleClass);
    }
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.sampler::ClassFactory
//-----------------------------------------------------------
class avmplus_ClassFactoryObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::ClassFactoryObject;
#define GC_TRIVIAL_TRACER_ClassFactoryObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.trace::Trace$
//-----------------------------------------------------------
class avmplus_TraceClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::TraceClass;
private:
    int32_t m_OFF;
    int32_t m_METHODS;
    int32_t m_METHODS_WITH_ARGS;
    int32_t m_METHODS_AND_LINES;
    int32_t m_METHODS_AND_LINES_WITH_ARGS;
    avmplus::AtomWB m_FILE;
    avmplus::AtomWB m_LISTENER;
};
#define DECLARE_SLOTS_TraceClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::TraceObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::TraceObject>((avmplus::TraceObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::TraceObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::TraceObject>((avmplus::TraceObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::TraceObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::TraceObject>((avmplus::TraceObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::TraceObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::TraceObject>((avmplus::TraceObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE int32_t get_OFF() const { return m_slots_TraceClass.m_OFF; } \
        REALLY_INLINE void setconst_OFF(int32_t newVal) { m_slots_TraceClass.m_OFF = newVal; } \
    public: \
        REALLY_INLINE int32_t get_METHODS() const { return m_slots_TraceClass.m_METHODS; } \
        REALLY_INLINE void setconst_METHODS(int32_t newVal) { m_slots_TraceClass.m_METHODS = newVal; } \
    public: \
        REALLY_INLINE int32_t get_METHODS_WITH_ARGS() const { return m_slots_TraceClass.m_METHODS_WITH_ARGS; } \
        REALLY_INLINE void setconst_METHODS_WITH_ARGS(int32_t newVal) { m_slots_TraceClass.m_METHODS_WITH_ARGS = newVal; } \
    public: \
        REALLY_INLINE int32_t get_METHODS_AND_LINES() const { return m_slots_TraceClass.m_METHODS_AND_LINES; } \
        REALLY_INLINE void setconst_METHODS_AND_LINES(int32_t newVal) { m_slots_TraceClass.m_METHODS_AND_LINES = newVal; } \
    public: \
        REALLY_INLINE int32_t get_METHODS_AND_LINES_WITH_ARGS() const { return m_slots_TraceClass.m_METHODS_AND_LINES_WITH_ARGS; } \
        REALLY_INLINE void setconst_METHODS_AND_LINES_WITH_ARGS(int32_t newVal) { m_slots_TraceClass.m_METHODS_AND_LINES_WITH_ARGS = newVal; } \
    public: \
        REALLY_INLINE avmplus::Atom get_FILE() const { return m_slots_TraceClass.m_FILE; } \
        REALLY_INLINE void setconst_FILE(avmplus::Atom newVal) { m_slots_TraceClass.m_FILE = newVal; } \
    public: \
        REALLY_INLINE avmplus::Atom get_LISTENER() const { return m_slots_TraceClass.m_LISTENER; } \
        REALLY_INLINE void setconst_LISTENER(avmplus::Atom newVal) { m_slots_TraceClass.m_LISTENER = newVal; } \
    private: \
        avmplus::NativeID::avmplus_TraceClassSlots m_slots_TraceClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.trace::Trace
//-----------------------------------------------------------
class avmplus_TraceObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::TraceObject;
#define GC_TRIVIAL_TRACER_TraceObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.system::WorkerState$
//-----------------------------------------------------------
class avmplus_WorkerStateClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::WorkerStateClass;
private:
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_NEW;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_RUNNING;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_TERMINATED;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_FAILED;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_ABORTED;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_EXCEPTION;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceLocation(&m_NEW);
        gc->TraceLocation(&m_RUNNING);
        gc->TraceLocation(&m_TERMINATED);
        gc->TraceLocation(&m_FAILED);
        gc->TraceLocation(&m_ABORTED);
        gc->TraceLocation(&m_EXCEPTION);
    }
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.system::WorkerState
//-----------------------------------------------------------
class avmplus_WorkerStateObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::WorkerStateObject;
#define GC_TRIVIAL_TRACER_WorkerStateObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.system::Worker$
//-----------------------------------------------------------
class avmshell_ShellWorkerClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::ShellWorkerClass;
private:
    MMgc::GCTraceableObject::GCMember<avmshell::ShellWorkerObject> m_private_m_current;
};
#define DECLARE_SLOTS_ShellWorkerClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmshell::ShellWorkerObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct_native(avmshell::ShellWorkerClass::createInstanceProc, 0, args); \
            return GCRef<avmshell::ShellWorkerObject>((avmshell::ShellWorkerObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmshell::ShellWorkerObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmshell::ShellWorkerObject>((avmshell::ShellWorkerObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::ShellWorkerObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmshell::ShellWorkerObject>((avmshell::ShellWorkerObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::ShellWorkerObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmshell::ShellWorkerObject>((avmshell::ShellWorkerObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::ShellWorkerObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmshell::ShellWorkerObject>((avmshell::ShellWorkerObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE avmshell::ShellWorkerObject* get_m_current() const { return m_slots_ShellWorkerClass.m_private_m_current; } \
        REALLY_INLINE void set_m_current(avmshell::ShellWorkerObject* newVal) { m_slots_ShellWorkerClass.m_private_m_current = newVal; } \
    private: \
        avmplus::NativeID::avmshell_ShellWorkerClassSlots m_slots_ShellWorkerClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.system::Worker
//-----------------------------------------------------------
class avmshell_ShellWorkerObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::ShellWorkerObject;
private:
    MMgc::GCTraceableObject::GCMember<avmplus::ByteArrayObject> m_private_m_byteCode;
};
#define DECLARE_SLOTS_ShellWorkerObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE avmplus::ByteArrayObject* get_m_byteCode() const { return m_slots_ShellWorkerObject.m_private_m_byteCode; } \
        REALLY_INLINE void set_m_byteCode(avmplus::ByteArrayObject* newVal) { m_slots_ShellWorkerObject.m_private_m_byteCode = newVal; } \
    private: \
        avmplus::NativeID::avmshell_ShellWorkerObjectSlots m_slots_ShellWorkerObject \

//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.system::WorkerEvent$
//-----------------------------------------------------------
class avmplus_WorkerEventClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::WorkerEventClass;
private:
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_WORKER_STATE;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceLocation(&m_WORKER_STATE);
    }
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.system::WorkerEvent
//-----------------------------------------------------------
class avmplus_WorkerEventObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::WorkerEventObject;
private:
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_private_m_previousState;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_private_m_currentState;
    avmplus::AtomWB m_flash_system_m_target;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceLocation(&m_private_m_previousState);
        gc->TraceLocation(&m_private_m_currentState);
        gc->TraceAtom(&m_flash_system_m_target);
    }
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.system::WorkerDomain$
//-----------------------------------------------------------
class avmshell_ShellWorkerDomainClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::ShellWorkerDomainClass;
private:
    MMgc::GCTraceableObject::GCMember<avmshell::ShellWorkerDomainObject> m_private_m_current;
};
#define DECLARE_SLOTS_ShellWorkerDomainClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmshell::ShellWorkerDomainObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmshell::ShellWorkerDomainObject>((avmshell::ShellWorkerDomainObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmshell::ShellWorkerDomainObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmshell::ShellWorkerDomainObject>((avmshell::ShellWorkerDomainObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::ShellWorkerDomainObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmshell::ShellWorkerDomainObject>((avmshell::ShellWorkerDomainObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::ShellWorkerDomainObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmshell::ShellWorkerDomainObject>((avmshell::ShellWorkerDomainObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmshell::ShellWorkerDomainObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmshell::ShellWorkerDomainObject>((avmshell::ShellWorkerDomainObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    protected: \
        REALLY_INLINE avmshell::ShellWorkerDomainObject* get_m_current() const { return m_slots_ShellWorkerDomainClass.m_private_m_current; } \
        REALLY_INLINE void set_m_current(avmshell::ShellWorkerDomainObject* newVal) { m_slots_ShellWorkerDomainClass.m_private_m_current = newVal; } \
    private: \
        avmplus::NativeID::avmshell_ShellWorkerDomainClassSlots m_slots_ShellWorkerDomainClass \

//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.system::WorkerDomain
//-----------------------------------------------------------
class avmshell_ShellWorkerDomainObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmshell::ShellWorkerDomainObject;
};
#define DECLARE_SLOTS_ShellWorkerDomainObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.system::System$
//-----------------------------------------------------------
class avmplus_SystemClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::SystemClass;
private:
    avmplus::bool32 m_private__useCodePage;
#define GC_TRIVIAL_TRACER_SystemClass
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.system::System
//-----------------------------------------------------------
class avmplus_SystemObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::SystemObject;
#define GC_TRIVIAL_TRACER_SystemObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.errors::ScriptTimeoutError$
//-----------------------------------------------------------
class avmplus_ScriptTimeoutErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::ScriptTimeoutErrorClass;
#define GC_TRIVIAL_TRACER_ScriptTimeoutErrorClass
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.errors::ScriptTimeoutError
//-----------------------------------------------------------
class avmplus_ScriptTimeoutErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::ScriptTimeoutErrorObject;
#define GC_TRIVIAL_TRACER_ScriptTimeoutErrorObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.errors::StackOverflowError$
//-----------------------------------------------------------
class avmplus_StackOverflowErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::StackOverflowErrorClass;
#define GC_TRIVIAL_TRACER_StackOverflowErrorClass
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.errors::StackOverflowError
//-----------------------------------------------------------
class avmplus_StackOverflowErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::StackOverflowErrorObject;
#define GC_TRIVIAL_TRACER_StackOverflowErrorObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.errors::InvalidSWFError$
//-----------------------------------------------------------
class avmplus_InvalidSWFErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::InvalidSWFErrorClass;
#define GC_TRIVIAL_TRACER_InvalidSWFErrorClass
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.errors::InvalidSWFError
//-----------------------------------------------------------
class avmplus_InvalidSWFErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::InvalidSWFErrorObject;
#define GC_TRIVIAL_TRACER_InvalidSWFErrorObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.errors::SQLErrorOperation$
//-----------------------------------------------------------
class avmplus_SQLErrorOperationClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::SQLErrorOperationClass;
private:
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_ANALYZE;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_ATTACH;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_BEGIN;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_CLOSE;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_COMMIT;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_COMPACT;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_DEANALYZE;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_DETACH;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_EXECUTE;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_OPEN;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_REENCRYPT;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_RELEASE_SAVEPOINT;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_ROLLBACK;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_ROLLBACK_TO_SAVEPOINT;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_SCHEMA;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_SET_SAVEPOINT;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceLocation(&m_ANALYZE);
        gc->TraceLocation(&m_ATTACH);
        gc->TraceLocation(&m_BEGIN);
        gc->TraceLocation(&m_CLOSE);
        gc->TraceLocation(&m_COMMIT);
        gc->TraceLocation(&m_COMPACT);
        gc->TraceLocation(&m_DEANALYZE);
        gc->TraceLocation(&m_DETACH);
        gc->TraceLocation(&m_EXECUTE);
        gc->TraceLocation(&m_OPEN);
        gc->TraceLocation(&m_REENCRYPT);
        gc->TraceLocation(&m_RELEASE_SAVEPOINT);
        gc->TraceLocation(&m_ROLLBACK);
        gc->TraceLocation(&m_ROLLBACK_TO_SAVEPOINT);
        gc->TraceLocation(&m_SCHEMA);
        gc->TraceLocation(&m_SET_SAVEPOINT);
    }
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.errors::SQLErrorOperation
//-----------------------------------------------------------
class avmplus_SQLErrorOperationObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::SQLErrorOperationObject;
#define GC_TRIVIAL_TRACER_SQLErrorOperationObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.errors::SQLError$
//-----------------------------------------------------------
class avmplus_SQLErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::SQLErrorClass;
#define GC_TRIVIAL_TRACER_SQLErrorClass
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.errors::SQLError
//-----------------------------------------------------------
class avmplus_SQLErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::SQLErrorObject;
private:
    int32_t m_private__detailID;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_private__operation;
    MMgc::GCTraceableObject::GCMember<avmplus::String> m_private__details;
    MMgc::GCTraceableObject::GCMember<avmplus::ArrayObject> m_private__detailArguments;
public:
    REALLY_INLINE void gcTracePrivateProperties(MMgc::GC* gc)
    {
        gc->TraceLocation(&m_private__operation);
        gc->TraceLocation(&m_private__details);
        gc->TraceLocation(&m_private__detailArguments);
    }
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.errors::DRMManagerError$
//-----------------------------------------------------------
class avmplus_DRMManagerErrorClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::DRMManagerErrorClass;
#define GC_TRIVIAL_TRACER_DRMManagerErrorClass
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.errors::DRMManagerError
//-----------------------------------------------------------
class avmplus_DRMManagerErrorObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::DRMManagerErrorObject;
private:
    int32_t m_private__subErrorID;
#define GC_TRIVIAL_TRACER_DRMManagerErrorObject
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.sampler::NewObjectSample$
//-----------------------------------------------------------
class avmplus_NewObjectSampleClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::NewObjectSampleClass;
};
#define DECLARE_SLOTS_NewObjectSampleClass \
    public: \
        static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable); \
    public: \
        static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*); \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    public: \
        inline GCRef<avmplus::NewObjectSampleObject> constructObject() \
        { \
            avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() }; \
            avmplus::Atom const result = this->construct(0, args); \
            return GCRef<avmplus::NewObjectSampleObject>((avmplus::NewObjectSampleObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    public: \
        REALLY_INLINE bool isType(avmplus::Atom value) \
        { \
            return isTypeImpl(value); \
        } \
        REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value) \
        { \
            return isTypeImpl(value->atom()); \
        } \
        REALLY_INLINE GCRef<avmplus::NewObjectSampleObject> asType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = asTypeImpl(value); \
            return GCRef<avmplus::NewObjectSampleObject>((avmplus::NewObjectSampleObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::NewObjectSampleObject> asType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = asTypeImpl(value->atom()); \
            return GCRef<avmplus::NewObjectSampleObject>((avmplus::NewObjectSampleObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::NewObjectSampleObject> coerceToType(avmplus::Atom value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value); \
            return GCRef<avmplus::NewObjectSampleObject>((avmplus::NewObjectSampleObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
        REALLY_INLINE GCRef<avmplus::NewObjectSampleObject> coerceToType(GCRef<avmplus::ScriptObject> value) \
        { \
            avmplus::Atom const result = coerceToTypeImpl(value->atom()); \
            return GCRef<avmplus::NewObjectSampleObject>((avmplus::NewObjectSampleObject*)(avmplus::AvmCore::atomToScriptObject(result))); \
        } \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \

//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.sampler::NewObjectSample
//-----------------------------------------------------------
class avmplus_NewObjectSampleObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::NewObjectSampleObject;
private:
    MMgc::GCTraceableObject::GCMember<avmplus::ClassClosure> m_type;
    double m_id;
};
#define DECLARE_SLOTS_NewObjectSampleObject \
    public: \
        AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); ) \
    private: \
        AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } ) \
    private: \
        friend class avmplus::NativeID::SlotOffsetsAndAsserts; \
    public: \
        REALLY_INLINE avmplus::ClassClosure* get_type() const { return m_slots_NewObjectSampleObject.m_type; } \
        REALLY_INLINE void setconst_type(avmplus::ClassClosure* newVal) { m_slots_NewObjectSampleObject.m_type = newVal; } \
    public: \
        REALLY_INLINE double get_id() const { return m_slots_NewObjectSampleObject.m_id; } \
        REALLY_INLINE void setconst_id(double newVal) { m_slots_NewObjectSampleObject.m_id = newVal; } \
    private: \
        avmplus::NativeID::avmplus_NewObjectSampleObjectSlots m_slots_NewObjectSampleObject \

//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.sampler::DeleteObjectSample$
//-----------------------------------------------------------
class avmplus_DeleteObjectSampleClassSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::DeleteObjectSampleClass;
#define GC_TRIVIAL_TRACER_DeleteObjectSampleClass
};
//-----------------------------------------------------------

//-----------------------------------------------------------
// flash.sampler::DeleteObjectSample
//-----------------------------------------------------------
class avmplus_DeleteObjectSampleObjectSlots
{
    friend class SlotOffsetsAndAsserts;
    friend class avmplus::DeleteObjectSampleObject;
private:
    double m_id;
    double m_size;
#define GC_TRIVIAL_TRACER_DeleteObjectSampleObject
};
//-----------------------------------------------------------

} }
namespace avmplus {

class shell_toplevelClassManifest : public avmplus::ClassManifestBase
{
    friend class avmplus::AvmCore;
    friend class avmplus::IntVectorClass;
    friend class avmplus::UIntVectorClass;
    FLOAT_ONLY(friend class avmplus::FloatVectorClass;)
    FLOAT_ONLY(friend class avmplus::Float4VectorClass;)
    friend class avmplus::DoubleVectorClass;
    friend class avmplus::ObjectVectorClass;
private:
    REALLY_INLINE shell_toplevelClassManifest(avmplus::ScriptEnv* e) : ClassManifestBase(31, e) { }
    REALLY_INLINE static shell_toplevelClassManifest* create(avmplus::ScriptEnv* e) { return new (MMgc::GC::GetGC(e), MMgc::kExact, sizeof(ClassClosure*)*30) shell_toplevelClassManifest(e); }
public:
    REALLY_INLINE GCRef<avmplus::CErrorClass> get_CErrorClass() { return (avmplus::CErrorClass*)(lazyInitClass(avmplus::NativeID::abcclass_C_errno_CError)); }
    REALLY_INLINE GCRef<avmplus::CapabilitiesClass> get_CapabilitiesClass() { return (avmplus::CapabilitiesClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_system_Capabilities)); }
    REALLY_INLINE GCRef<avmplus::ClassFactoryClass> get_ClassFactoryClass() { return (avmplus::ClassFactoryClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_sampler_ClassFactory)); }
    REALLY_INLINE GCRef<avmplus::DRMManagerErrorClass> get_DRMManagerErrorClass() { return (avmplus::DRMManagerErrorClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_errors_DRMManagerError)); }
    REALLY_INLINE GCRef<avmplus::DeleteObjectSampleClass> get_DeleteObjectSampleClass() { return (avmplus::DeleteObjectSampleClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_sampler_DeleteObjectSample)); }
    REALLY_INLINE GCRef<avmplus::DomainClass> get_DomainClass() { return (avmplus::DomainClass*)(lazyInitClass(avmplus::NativeID::abcclass_shell_Domain)); }
    REALLY_INLINE GCRef<avmplus::EndianClass> get_EndianClass() { return (avmplus::EndianClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_utils_Endian)); }
    REALLY_INLINE GCRef<avmplus::EnvironmentClass> get_EnvironmentClass() { return (avmplus::EnvironmentClass*)(lazyInitClass(avmplus::NativeID::abcclass_shell_Environment)); }
    REALLY_INLINE GCRef<avmplus::ErrorNumberClass> get_ErrorNumberClass() { return (avmplus::ErrorNumberClass*)(lazyInitClass(avmplus::NativeID::abcclass_C_errno_ErrorNumber)); }
    REALLY_INLINE GCRef<avmshell::FileClass> get_FileIOClass() { return (avmshell::FileClass*)(lazyInitClass(avmplus::NativeID::abcclass_shell_FileIO)); }
    REALLY_INLINE GCRef<avmplus::InvalidSWFErrorClass> get_InvalidSWFErrorClass() { return (avmplus::InvalidSWFErrorClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_errors_InvalidSWFError)); }
    REALLY_INLINE GCRef<avmplus::NewObjectSampleClass> get_NewObjectSampleClass() { return (avmplus::NewObjectSampleClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_sampler_NewObjectSample)); }
    REALLY_INLINE GCRef<avmshell::ProgramClass> get_ProgramClass() { return (avmshell::ProgramClass*)(lazyInitClass(avmplus::NativeID::abcclass_shell_Program)); }
    REALLY_INLINE GCRef<avmplus::SQLErrorClass> get_SQLErrorClass() { return (avmplus::SQLErrorClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_errors_SQLError)); }
    REALLY_INLINE GCRef<avmplus::SQLErrorOperationClass> get_SQLErrorOperationClass() { return (avmplus::SQLErrorOperationClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_errors_SQLErrorOperation)); }
    REALLY_INLINE GCRef<avmplus::SampleClass> get_SampleClass() { return (avmplus::SampleClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_sampler_Sample)); }
    REALLY_INLINE GCRef<avmplus::ScriptTimeoutErrorClass> get_ScriptTimeoutErrorClass() { return (avmplus::ScriptTimeoutErrorClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_errors_ScriptTimeoutError)); }
    REALLY_INLINE GCRef<avmplus::StackFrameClass> get_StackFrameClass() { return (avmplus::StackFrameClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_sampler_StackFrame)); }
    REALLY_INLINE GCRef<avmplus::StackOverflowErrorClass> get_StackOverflowErrorClass() { return (avmplus::StackOverflowErrorClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_errors_StackOverflowError)); }
    REALLY_INLINE GCRef<avmplus::SystemClass> get_SystemClass() { return (avmplus::SystemClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_system_System)); }
    REALLY_INLINE GCRef<avmplus::TraceClass> get_TraceClass() { return (avmplus::TraceClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_trace_Trace)); }
    REALLY_INLINE GCRef<avmshell::ShellWorkerClass> get_WorkerClass() { return (avmshell::ShellWorkerClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_system_Worker)); }
    REALLY_INLINE GCRef<avmshell::ShellWorkerDomainClass> get_WorkerDomainClass() { return (avmshell::ShellWorkerDomainClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_system_WorkerDomain)); }
    REALLY_INLINE GCRef<avmplus::WorkerEventClass> get_WorkerEventClass() { return (avmplus::WorkerEventClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_system_WorkerEvent)); }
    REALLY_INLINE GCRef<avmplus::WorkerStateClass> get_WorkerStateClass() { return (avmplus::WorkerStateClass*)(lazyInitClass(avmplus::NativeID::abcclass_flash_system_WorkerState)); }
    REALLY_INLINE GCRef<avmshell::CErrnoClass> get___errnoClass() { return (avmshell::CErrnoClass*)(lazyInitClass(avmplus::NativeID::abcclass_C_errno___errno)); }
    REALLY_INLINE GCRef<avmshell::CSocketClass> get___socketClass() { return (avmshell::CSocketClass*)(lazyInitClass(avmplus::NativeID::abcclass_C_socket___socket)); }
    REALLY_INLINE GCRef<avmshell::CStdioClass> get___stdioClass() { return (avmshell::CStdioClass*)(lazyInitClass(avmplus::NativeID::abcclass_C_stdio___stdio)); }
    REALLY_INLINE GCRef<avmshell::CStdlibClass> get___stdlibClass() { return (avmshell::CStdlibClass*)(lazyInitClass(avmplus::NativeID::abcclass_C_stdlib___stdlib)); }
    REALLY_INLINE GCRef<avmshell::CStringClass> get___stringClass() { return (avmshell::CStringClass*)(lazyInitClass(avmplus::NativeID::abcclass_C_string___string)); }
    REALLY_INLINE GCRef<avmshell::CUnistdClass> get___unistdClass() { return (avmshell::CUnistdClass*)(lazyInitClass(avmplus::NativeID::abcclass_C_unistd___unistd)); }
};
}
#endif // _H_nativegen_header_shell_toplevel
