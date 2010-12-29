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

namespace avmplus { namespace NativeID {

const uint32_t shell_toplevel_abc_class_count = 18;
const uint32_t shell_toplevel_abc_script_count = 13;
const uint32_t shell_toplevel_abc_method_count = 292;
const uint32_t shell_toplevel_abc_length = 15825;

/* thunks (45 unique signatures, 201 total) */

#ifndef VMCFG_INDIRECT_NATIVE_THUNKS

AvmBox avmplus_Domain_currentDomain_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    DomainClass* const obj = (DomainClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    DomainObject* const ret = obj->get_currentDomain();
    return (AvmBox) ret;
}
AvmBox avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    DomainClass* const obj = (DomainClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    uint32_t const ret = obj->get_MIN_DOMAIN_MEMORY_LENGTH();
    return (AvmBox) ret;
}
AvmBox avmplus_Domain_private_init_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    DomainObject* const obj = (DomainObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->init(
        (DomainObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
AvmBox avmplus_Domain_loadBytes_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmObject
    };
    (void)env;
    DomainObject* const obj = (DomainObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBox const ret = obj->loadBytes(
        (ByteArrayObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
        , (argc < 2 ? AvmThunkCoerce_int32_t_uint32_t(0) : AvmThunkUnbox_uint32_t(argv[argoff2]))
    );
    return (AvmBox) ret;
}
AvmBox avmplus_Domain_getClass_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    DomainObject* const obj = (DomainObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    ClassClosure* const ret = obj->getClass(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox avmplus_Domain_domainMemory_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    DomainObject* const obj = (DomainObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    ByteArrayObject* const ret = obj->get_domainMemory();
    return (AvmBox) ret;
}
AvmBox avmplus_Domain_domainMemory_set_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    DomainObject* const obj = (DomainObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->set_domainMemory(
        (ByteArrayObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
AvmBox flash_sampler_NewObjectSample_object_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    NewObjectSampleObject* const obj = (NewObjectSampleObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBox const ret = obj->get_object();
    return (AvmBox) ret;
}
double flash_sampler_NewObjectSample_size_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    NewObjectSampleObject* const obj = (NewObjectSampleObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    double const ret = obj->get_size();
    return ret;
}
AvmBox native_script_function_flash_sampler_clearSamples_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    SamplerScript::clearSamples(obj);
    return kAvmThunkUndefined;
}
AvmBox native_script_function_flash_sampler_startSampling_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    SamplerScript::startSampling(obj);
    return kAvmThunkUndefined;
}
AvmBox native_script_function_flash_sampler_stopSampling_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    SamplerScript::stopSampling(obj);
    return kAvmThunkUndefined;
}
AvmBox native_script_function_flash_sampler_pauseSampling_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    SamplerScript::pauseSampling(obj);
    return kAvmThunkUndefined;
}
AvmBox native_script_function_flash_sampler_sampleInternalAllocs_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    SamplerScript::sampleInternalAllocs(obj
        , AvmThunkUnbox_AvmBool32(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
AvmBox native_script_function_flash_sampler__setSamplerCallback_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    SamplerScript::_setSamplerCallback(obj
        , (FunctionObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
double native_script_function_flash_sampler_getSize_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    double const ret = SamplerScript::getSize(obj
        , AvmThunkUnbox_AvmBox(argv[argoff1])
    );
    return ret;
}
AvmBox native_script_function_flash_sampler_getMemberNames_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmBox
    };
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBox const ret = SamplerScript::getMemberNames(obj
        , AvmThunkUnbox_AvmBox(argv[argoff1])
        , (argc < 2 ? false : AvmThunkUnbox_AvmBool32(argv[argoff2]))
    );
    return (AvmBox) ret;
}
AvmBox native_script_function_flash_sampler_getSamples_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBox const ret = SamplerScript::getSamples(obj);
    return (AvmBox) ret;
}
double native_script_function_flash_sampler_getSampleCount_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    double const ret = SamplerScript::getSampleCount(obj);
    return ret;
}
double native_script_function_flash_sampler__getInvocationCount_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmBox
        , argoff3 = argoff2 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    double const ret = SamplerScript::_getInvocationCount(obj
        , AvmThunkUnbox_AvmBox(argv[argoff1])
        , (QNameObject*)AvmThunkUnbox_AvmObject(argv[argoff2])
        , AvmThunkUnbox_uint32_t(argv[argoff3])
    );
    return ret;
}
AvmBox native_script_function_flash_sampler_isGetterSetter_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmBox
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBool32 const ret = SamplerScript::isGetterSetter(obj
        , AvmThunkUnbox_AvmBox(argv[argoff1])
        , (QNameObject*)AvmThunkUnbox_AvmObject(argv[argoff2])
    );
    return (AvmBox) ret;
}
AvmBox native_script_function_flash_sampler_getLexicalScopes_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    ArrayObject* const ret = SamplerScript::getLexicalScopes(obj
        , (FunctionObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox native_script_function_flash_sampler_getSavedThis_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBox const ret = SamplerScript::getSavedThis(obj
        , (FunctionObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox native_script_function_flash_sampler_getMasterString_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = SamplerScript::getMasterString(obj
        , AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox flash_trace_Trace_setLevel_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_int32_t
    };
    (void)env;
    TraceClass* const obj = (TraceClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBox const ret = obj->setLevel(
        AvmThunkUnbox_int32_t(argv[argoff1])
        , (argc < 2 ? 2 : AvmThunkUnbox_int32_t(argv[argoff2]))
    );
    return (AvmBox) ret;
}
AvmBox flash_trace_Trace_getLevel_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)env;
    TraceClass* const obj = (TraceClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->getLevel(
        (argc < 1 ? 2 : AvmThunkUnbox_int32_t(argv[argoff1]))
    );
    return (AvmBox) ret;
}
AvmBox flash_trace_Trace_setListener_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    TraceClass* const obj = (TraceClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBox const ret = obj->setListener(
        (FunctionObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox flash_trace_Trace_getListener_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    TraceClass* const obj = (TraceClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    FunctionObject* const ret = obj->getListener();
    return (AvmBox) ret;
}
AvmBox flash_utils_Dictionary_private_init_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    DictionaryObject* const obj = (DictionaryObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->init(
        AvmThunkUnbox_AvmBool32(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
AvmBox C_stdlib___stdlib_EXIT_SUCCESS_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::StdlibClass* const obj = (::avmshell::StdlibClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_EXIT_SUCCESS();
    return (AvmBox) ret;
}
AvmBox C_stdlib___stdlib_EXIT_FAILURE_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::StdlibClass* const obj = (::avmshell::StdlibClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_EXIT_FAILURE();
    return (AvmBox) ret;
}
AvmBox C_stdlib___stdlib_abort_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::StdlibClass* const obj = (::avmshell::StdlibClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->abort();
    return kAvmThunkUndefined;
}
AvmBox C_stdlib___stdlib_exit_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)env;
    ::avmshell::StdlibClass* const obj = (::avmshell::StdlibClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->exit(
        (argc < 1 ? 0 : AvmThunkUnbox_int32_t(argv[argoff1]))
    );
    return kAvmThunkUndefined;
}
AvmBox C_stdlib___stdlib_getenv_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::StdlibClass* const obj = (::avmshell::StdlibClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->getenv(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox C_stdlib___stdlib_setenv_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmString
        , argoff3 = argoff2 + AvmThunkArgSize_AvmString
    };
    (void)argc;
    (void)env;
    ::avmshell::StdlibClass* const obj = (::avmshell::StdlibClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->setenv(
        AvmThunkUnbox_AvmString(argv[argoff1])
        , AvmThunkUnbox_AvmString(argv[argoff2])
        , AvmThunkUnbox_int32_t(argv[argoff3])
    );
    return (AvmBox) ret;
}
AvmBox C_stdlib___stdlib_unsetenv_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::StdlibClass* const obj = (::avmshell::StdlibClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->unsetenv(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox C_stdlib___stdlib_realpath_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::StdlibClass* const obj = (::avmshell::StdlibClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->realpath(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox C_stdlib___stdlib___system_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::StdlibClass* const obj = (::avmshell::StdlibClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->__system(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_F_OK_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_F_OK();
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_X_OK_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_X_OK();
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_W_OK_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_W_OK();
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_R_OK_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_R_OK();
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_S_IFMT_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_S_IFMT();
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_S_IFIFO_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_S_IFIFO();
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_S_IFCHR_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_S_IFCHR();
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_S_IFDIR_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_S_IFDIR();
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_S_IFBLK_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_S_IFBLK();
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_S_IFREG_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_S_IFREG();
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_S_IFLNK_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_S_IFLNK();
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_S_IFSOCK_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_S_IFSOCK();
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_S_IRWXU_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_S_IRWXU();
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_S_IRUSR_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_S_IRUSR();
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_S_IWUSR_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_S_IWUSR();
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_S_IXUSR_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_S_IXUSR();
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_S_IRWXG_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_S_IRWXG();
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_S_IRGRP_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_S_IRGRP();
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_S_IWGRP_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_S_IWGRP();
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_S_IXGRP_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_S_IXGRP();
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_S_IRWXO_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_S_IRWXO();
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_S_IROTH_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_S_IROTH();
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_S_IWOTH_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_S_IWOTH();
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_S_IXOTH_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_S_IXOTH();
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_S_IREAD_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_S_IREAD();
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_S_IWRITE_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_S_IWRITE();
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_S_IEXEC_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_S_IEXEC();
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_access_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmString
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->access(
        AvmThunkUnbox_AvmString(argv[argoff1])
        , AvmThunkUnbox_int32_t(argv[argoff2])
    );
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_chdir_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->chdir(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_chmod_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmString
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->chmod(
        AvmThunkUnbox_AvmString(argv[argoff1])
        , AvmThunkUnbox_int32_t(argv[argoff2])
    );
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_getcwd_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->getcwd();
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_gethostname_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->gethostname();
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_getlogin_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->getlogin();
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_mkdir_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->mkdir(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_rmdir_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->rmdir(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox C_unistd___unistd_sleep_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->sleep(
        AvmThunkUnbox_uint32_t(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
AvmBox C_unistd___unistd_unlink_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->unlink(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox C_string___string_strerror_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::CStringClass* const obj = (::avmshell::CStringClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->strerror(
        AvmThunkUnbox_int32_t(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox C_string___string_strlen_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::CStringClass* const obj = (::avmshell::CStringClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    uint32_t const ret = obj->strlen(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox C_errno___errno_EDOM_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_EDOM();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_EILSEQ_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_EILSEQ();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_ERANGE_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_ERANGE();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_EPERM_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_EPERM();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_ENOENT_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_ENOENT();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_ESRCH_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_ESRCH();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_EINTR_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_EINTR();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_EIO_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_EIO();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_ENXIO_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_ENXIO();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_E2BIG_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_E2BIG();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_ENOEXEC_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_ENOEXEC();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_EBADF_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_EBADF();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_ECHILD_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_ECHILD();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_EAGAIN_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_EAGAIN();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_ENOMEM_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_ENOMEM();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_EACCES_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_EACCES();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_EFAULT_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_EFAULT();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_EBUSY_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_EBUSY();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_EEXIST_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_EEXIST();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_EXDEV_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_EXDEV();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_ENODEV_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_ENODEV();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_ENOTDIR_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_ENOTDIR();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_EISDIR_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_EISDIR();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_EINVAL_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_EINVAL();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_ENFILE_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_ENFILE();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_EMFILE_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_EMFILE();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_ENOTTY_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_ENOTTY();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_EFBIG_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_EFBIG();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_ENOSPC_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_ENOSPC();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_ESPIPE_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_ESPIPE();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_EROFS_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_EROFS();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_EMLINK_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_EMLINK();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_EPIPE_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_EPIPE();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_EDEADLK_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_EDEADLK();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_ENAMETOOLONG_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_ENAMETOOLONG();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_ENOLCK_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_ENOLCK();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_ENOSYS_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_ENOSYS();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_ENOTEMPTY_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_ENOTEMPTY();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_ENETDOWN_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_ENETDOWN();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_ENETUNREACH_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_ENETUNREACH();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_ENETRESET_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_ENETRESET();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_ECONNABORTED_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_ECONNABORTED();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_ECONNRESET_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_ECONNRESET();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_ENOBUFS_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_ENOBUFS();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_EISCONN_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_EISCONN();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_ENOTCONN_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_ENOTCONN();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_ESHUTDOWN_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_ESHUTDOWN();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_ETOOMANYREFS_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_ETOOMANYREFS();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_ETIMEDOUT_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_ETIMEDOUT();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_ECONNREFUSED_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_ECONNREFUSED();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_errno_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_errno();
    return (AvmBox) ret;
}
AvmBox C_errno___errno_errno_set_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::CErrnoClass* const obj = (::avmshell::CErrnoClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->set_errno(
        AvmThunkUnbox_int32_t(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
AvmBox C_stdio___stdio_FILENAME_MAX_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::StdioClass* const obj = (::avmshell::StdioClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_FILENAME_MAX();
    return (AvmBox) ret;
}
AvmBox C_stdio___stdio_PATH_MAX_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::StdioClass* const obj = (::avmshell::StdioClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_PATH_MAX();
    return (AvmBox) ret;
}
AvmBox C_stdio___stdio_remove_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::StdioClass* const obj = (::avmshell::StdioClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->remove(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox C_stdio___stdio_rename_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmString
    };
    (void)argc;
    (void)env;
    ::avmshell::StdioClass* const obj = (::avmshell::StdioClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->rename(
        AvmThunkUnbox_AvmString(argv[argoff1])
        , AvmThunkUnbox_AvmString(argv[argoff2])
    );
    return (AvmBox) ret;
}
AvmBox C_socket___socket_SOCK_RAW_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_SOCK_RAW();
    return (AvmBox) ret;
}
AvmBox C_socket___socket_SOCK_STREAM_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_SOCK_STREAM();
    return (AvmBox) ret;
}
AvmBox C_socket___socket_SOCK_DGRAM_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_SOCK_DGRAM();
    return (AvmBox) ret;
}
AvmBox C_socket___socket_SO_ACCEPTCONN_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_SO_ACCEPTCONN();
    return (AvmBox) ret;
}
AvmBox C_socket___socket_SO_BROADCAST_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_SO_BROADCAST();
    return (AvmBox) ret;
}
AvmBox C_socket___socket_SO_DONTROUTE_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_SO_DONTROUTE();
    return (AvmBox) ret;
}
AvmBox C_socket___socket_SO_KEEPALIVE_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_SO_KEEPALIVE();
    return (AvmBox) ret;
}
AvmBox C_socket___socket_SO_OOBINLINE_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_SO_OOBINLINE();
    return (AvmBox) ret;
}
AvmBox C_socket___socket_SO_RCVBUF_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_SO_RCVBUF();
    return (AvmBox) ret;
}
AvmBox C_socket___socket_SO_RCVTIMEO_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_SO_RCVTIMEO();
    return (AvmBox) ret;
}
AvmBox C_socket___socket_SO_REUSEADDR_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_SO_REUSEADDR();
    return (AvmBox) ret;
}
AvmBox C_socket___socket_SO_SNDBUF_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_SO_SNDBUF();
    return (AvmBox) ret;
}
AvmBox C_socket___socket_SO_SNDTIMEO_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_SO_SNDTIMEO();
    return (AvmBox) ret;
}
AvmBox C_socket___socket_SO_TYPE_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_SO_TYPE();
    return (AvmBox) ret;
}
AvmBox C_socket___socket_SOMAXCONN_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_SOMAXCONN();
    return (AvmBox) ret;
}
AvmBox C_socket___socket_MSG_CTRUNC_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_MSG_CTRUNC();
    return (AvmBox) ret;
}
AvmBox C_socket___socket_MSG_DONTROUTE_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_MSG_DONTROUTE();
    return (AvmBox) ret;
}
AvmBox C_socket___socket_MSG_OOB_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_MSG_OOB();
    return (AvmBox) ret;
}
AvmBox C_socket___socket_MSG_PEEK_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_MSG_PEEK();
    return (AvmBox) ret;
}
AvmBox C_socket___socket_MSG_TRUNC_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_MSG_TRUNC();
    return (AvmBox) ret;
}
AvmBox C_socket___socket_MSG_WAITALL_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_MSG_WAITALL();
    return (AvmBox) ret;
}
AvmBox C_socket___socket_AF_INET_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_AF_INET();
    return (AvmBox) ret;
}
AvmBox C_socket___socket_AF_INET6_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_AF_INET6();
    return (AvmBox) ret;
}
AvmBox C_socket___socket_AF_UNSPEC_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_AF_UNSPEC();
    return (AvmBox) ret;
}
AvmBox C_socket___socket_SHUT_RD_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_SHUT_RD();
    return (AvmBox) ret;
}
AvmBox C_socket___socket_SHUT_RDWR_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_SHUT_RDWR();
    return (AvmBox) ret;
}
AvmBox C_socket___socket_SHUT_WR_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_SHUT_WR();
    return (AvmBox) ret;
}
AvmBox C_socket___socket_IPPROTO_IP_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_IPPROTO_IP();
    return (AvmBox) ret;
}
AvmBox C_socket___socket_IPPROTO_IPV6_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_IPPROTO_IPV6();
    return (AvmBox) ret;
}
AvmBox C_socket___socket_IPPROTO_ICMP_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_IPPROTO_ICMP();
    return (AvmBox) ret;
}
AvmBox C_socket___socket_IPPROTO_RAW_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_IPPROTO_RAW();
    return (AvmBox) ret;
}
AvmBox C_socket___socket_IPPROTO_TCP_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_IPPROTO_TCP();
    return (AvmBox) ret;
}
AvmBox C_socket___socket_IPPROTO_UDP_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_IPPROTO_UDP();
    return (AvmBox) ret;
}
AvmBox C_socket___socket_INADDR_ANY_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_INADDR_ANY();
    return (AvmBox) ret;
}
AvmBox C_socket___socket_INADDR_BROADCAST_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_INADDR_BROADCAST();
    return (AvmBox) ret;
}
AvmBox C_socket___socket___gethostbyaddr_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmString
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    ArrayObject* const ret = obj->__gethostbyaddr(
        AvmThunkUnbox_AvmString(argv[argoff1])
        , AvmThunkUnbox_AvmBool32(argv[argoff2])
    );
    return (AvmBox) ret;
}
AvmBox C_socket___socket___gethostbyname_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmString
    };
    (void)argc;
    (void)env;
    ::avmshell::CSocketClass* const obj = (::avmshell::CSocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    ArrayObject* const ret = obj->__gethostbyname(
        AvmThunkUnbox_AvmString(argv[argoff1])
        , AvmThunkUnbox_AvmBool32(argv[argoff2])
    );
    return (AvmBox) ret;
}
AvmBox avmplus_JObject_create_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    const uint32_t argoffV = argoff1 + AvmThunkArgSize_AvmString;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    JObject* const ret = obj->create(
        AvmThunkUnbox_AvmString(argv[argoff1])
        , (argc <= 1 ? NULL : argv + argoffV)
        , (argc <= 1 ? 0 : argc - 1)
    );
    return (AvmBox) ret;
}
AvmBox avmplus_JObject_createArray_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmObject
        , argoff3 = argoff2 + AvmThunkArgSize_int32_t
    };
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    JObject* const ret = obj->createArray(
        (JObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
        , AvmThunkUnbox_int32_t(argv[argoff2])
        , (ArrayObject*)(argc < 3 ? AvmThunkCoerce_AvmBox_AvmObject(kAvmThunkNull) : (ArrayObject*)AvmThunkUnbox_AvmObject(argv[argoff3]))
    );
    return (AvmBox) ret;
}
AvmBox avmplus_JObject_toArray_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    ArrayObject* const ret = obj->toArray(
        (JObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox avmplus_JObject_constructorSignature_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    const uint32_t argoffV = argoff1 + AvmThunkArgSize_AvmString;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->constructorSignature(
        AvmThunkUnbox_AvmString(argv[argoff1])
        , (argc <= 1 ? NULL : argv + argoffV)
        , (argc <= 1 ? 0 : argc - 1)
    );
    return (AvmBox) ret;
}
AvmBox avmplus_JObject_methodSignature_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmObject
    };
    const uint32_t argoffV = argoff2 + AvmThunkArgSize_AvmString;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->methodSignature(
        (JObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
        , AvmThunkUnbox_AvmString(argv[argoff2])
        , (argc <= 2 ? NULL : argv + argoffV)
        , (argc <= 2 ? 0 : argc - 2)
    );
    return (AvmBox) ret;
}
AvmBox avmplus_JObject_fieldSignature_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->fieldSignature(
        (JObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
        , AvmThunkUnbox_AvmString(argv[argoff2])
    );
    return (AvmBox) ret;
}
AvmBox avmplus_System_exit_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->exit(
        AvmThunkUnbox_int32_t(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
AvmBox avmplus_System_exec_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->exec(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox avmplus_System_getAvmplusVersion_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->getAvmplusVersion();
    return (AvmBox) ret;
}
AvmBox avmplus_System_getFeatures_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->getFeatures();
    return (AvmBox) ret;
}
AvmBox avmplus_System_getRunmode_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->getRunmode();
    return (AvmBox) ret;
}
AvmBox avmplus_System_trace_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->trace(
        (ArrayObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
AvmBox avmplus_System_write_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->write(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
AvmBox avmplus_System_debugger_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->debugger();
    return kAvmThunkUndefined;
}
AvmBox avmplus_System_isDebugger_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBool32 const ret = obj->isDebugger();
    return (AvmBox) ret;
}
AvmBox avmplus_System_getTimer_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    uint32_t const ret = obj->getTimer();
    return (AvmBox) ret;
}
AvmBox avmplus_System_private_getArgv_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    ArrayObject* const ret = obj->getArgv();
    return (AvmBox) ret;
}
AvmBox avmplus_System_readLine_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->readLine();
    return (AvmBox) ret;
}
double avmplus_System_totalMemory_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    double const ret = obj->get_totalMemory();
    return ret;
}
double avmplus_System_freeMemory_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    double const ret = obj->get_freeMemory();
    return ret;
}
double avmplus_System_privateMemory_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    double const ret = obj->get_privateMemory();
    return ret;
}
AvmBox avmplus_System_forceFullCollection_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->forceFullCollection();
    return kAvmThunkUndefined;
}
AvmBox avmplus_System_queueCollection_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->queueCollection();
    return kAvmThunkUndefined;
}
AvmBox avmplus_System_swfVersion_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_swfVersion();
    return (AvmBox) ret;
}
AvmBox avmplus_System_apiVersion_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_apiVersion();
    return (AvmBox) ret;
}
AvmBox avmplus_System_disposeXML_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->disposeXML(
        (XMLObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
AvmBox avmplus_File_exists_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBool32 const ret = obj->exists(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox avmplus_File_read_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->read(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox avmplus_File_write_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmString
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->write(
        AvmThunkUnbox_AvmString(argv[argoff1])
        , AvmThunkUnbox_AvmString(argv[argoff2])
    );
    return kAvmThunkUndefined;
}
AvmBox avmplus_File_readByteArray_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    ByteArrayObject* const ret = obj->readByteArray(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox avmplus_File_writeByteArray_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmString
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBool32 const ret = obj->writeByteArray(
        AvmThunkUnbox_AvmString(argv[argoff1])
        , (ByteArrayObject*)AvmThunkUnbox_AvmObject(argv[argoff2])
    );
    return (AvmBox) ret;
}

#else // VMCFG_INDIRECT_NATIVE_THUNKS

// avmplus_JObject_methodSignature
AvmBox shell_toplevel_s2a_oos_rest_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmObject
    };
    const uint32_t argoffV = argoff2 + AvmThunkArgSize_AvmString;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->methodSignature(
        (JObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
        , AvmThunkUnbox_AvmString(argv[argoff2])
        , (argc <= 2 ? NULL : argv + argoffV)
        , (argc <= 2 ? 0 : argc - 2)
    );
    return (AvmBox) ret;
}

// native_script_function_flash_sampler_getMasterString
AvmBox shell_toplevel_func_s2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = SamplerScript::getMasterString(obj
        , AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}

// native_script_function_flash_sampler__setSamplerCallback
AvmBox shell_toplevel_func_v2a_oo_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    SamplerScript::_setSamplerCallback(obj
        , (FunctionObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
    );
    return kAvmThunkUndefined;
}

// avmplus_System_freeMemory_get
// avmplus_System_privateMemory_get
// avmplus_System_totalMemory_get
// flash_sampler_NewObjectSample_size_get
double shell_toplevel_d2d_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    typedef AvmRetType_double (AvmObjectT::*FuncType)();
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (*(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])).*(func))(
    );
}

// C_socket___socket___gethostbyaddr
// C_socket___socket___gethostbyname
AvmBox shell_toplevel_a2a_osb_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmString
    };
    (void)argc;
    typedef AvmRetType_AvmBox (AvmObjectT::*FuncType)(AvmString, AvmBool32);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (AvmBox)(*(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])).*(func))(
        AvmThunkUnbox_AvmString(argv[argoff1])
        , AvmThunkUnbox_AvmBool32(argv[argoff2])
    );
}

// avmplus_Domain_getClass
// avmplus_File_readByteArray
AvmBox shell_toplevel_a2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    typedef AvmRetType_AvmBox (AvmObjectT::*FuncType)(AvmString);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (AvmBox)(*(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])).*(func))(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
}

// native_script_function_flash_sampler_isGetterSetter
AvmBox shell_toplevel_func_b2a_oao_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmBox
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBool32 const ret = SamplerScript::isGetterSetter(obj
        , AvmThunkUnbox_AvmBox(argv[argoff1])
        , (QNameObject*)AvmThunkUnbox_AvmObject(argv[argoff2])
    );
    return (AvmBox) ret;
}

// C_string___string_strlen
AvmBox shell_toplevel_u2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::CStringClass* const obj = (::avmshell::CStringClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    uint32_t const ret = obj->strlen(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}

// avmplus_JObject_toArray
// flash_trace_Trace_setListener
AvmBox shell_toplevel_a2a_oo_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    typedef AvmRetType_AvmBox (AvmObjectT::*FuncType)(AvmObject);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (AvmBox)(*(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])).*(func))(
        AvmThunkUnbox_AvmObject(argv[argoff1])
    );
}

// C_unistd___unistd_getcwd
// C_unistd___unistd_gethostname
// C_unistd___unistd_getlogin
// avmplus_System_getAvmplusVersion
// avmplus_System_getFeatures
// avmplus_System_getRunmode
// avmplus_System_readLine
AvmBox shell_toplevel_s2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    typedef AvmRetType_AvmString (AvmObjectT::*FuncType)();
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (AvmBox)(*(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])).*(func))(
    );
}

// native_script_function_flash_sampler_sampleInternalAllocs
AvmBox shell_toplevel_func_v2a_ob_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    SamplerScript::sampleInternalAllocs(obj
        , AvmThunkUnbox_AvmBool32(argv[argoff1])
    );
    return kAvmThunkUndefined;
}

// avmplus_File_write
AvmBox shell_toplevel_v2a_oss_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmString
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->write(
        AvmThunkUnbox_AvmString(argv[argoff1])
        , AvmThunkUnbox_AvmString(argv[argoff2])
    );
    return kAvmThunkUndefined;
}

// native_script_function_flash_sampler_getSize
double shell_toplevel_func_d2d_oa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    double const ret = SamplerScript::getSize(obj
        , AvmThunkUnbox_AvmBox(argv[argoff1])
    );
    return ret;
}

// native_script_function_flash_sampler_clearSamples
// native_script_function_flash_sampler_pauseSampling
// native_script_function_flash_sampler_startSampling
// native_script_function_flash_sampler_stopSampling
AvmBox shell_toplevel_func_v2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    typedef AvmRetType_void (*FuncType)(AvmObject);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_FUNCTION_HANDLER(env));
    (*func)(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])
    );
    return kAvmThunkUndefined;
}

// avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get
// avmplus_System_getTimer
AvmBox shell_toplevel_u2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    typedef AvmRetType_uint32_t (AvmObjectT::*FuncType)();
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (AvmBox)(*(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])).*(func))(
    );
}

// avmplus_JObject_createArray
AvmBox shell_toplevel_a2a_ooio_optakAvmThunkNull_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmObject
        , argoff3 = argoff2 + AvmThunkArgSize_int32_t
    };
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    JObject* const ret = obj->createArray(
        (JObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
        , AvmThunkUnbox_int32_t(argv[argoff2])
        , (ArrayObject*)(argc < 3 ? AvmThunkCoerce_AvmBox_AvmObject(kAvmThunkNull) : (ArrayObject*)AvmThunkUnbox_AvmObject(argv[argoff3]))
    );
    return (AvmBox) ret;
}

// avmplus_JObject_constructorSignature
AvmBox shell_toplevel_s2a_os_rest_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    const uint32_t argoffV = argoff1 + AvmThunkArgSize_AvmString;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->constructorSignature(
        AvmThunkUnbox_AvmString(argv[argoff1])
        , (argc <= 1 ? NULL : argv + argoffV)
        , (argc <= 1 ? 0 : argc - 1)
    );
    return (AvmBox) ret;
}

// native_script_function_flash_sampler_getSampleCount
double shell_toplevel_func_d2d_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    double const ret = SamplerScript::getSampleCount(obj);
    return ret;
}

// C_errno___errno_E2BIG_get
// C_errno___errno_EACCES_get
// C_errno___errno_EAGAIN_get
// C_errno___errno_EBADF_get
// C_errno___errno_EBUSY_get
// C_errno___errno_ECHILD_get
// C_errno___errno_ECONNABORTED_get
// C_errno___errno_ECONNREFUSED_get
// C_errno___errno_ECONNRESET_get
// C_errno___errno_EDEADLK_get
// C_errno___errno_EDOM_get
// C_errno___errno_EEXIST_get
// C_errno___errno_EFAULT_get
// C_errno___errno_EFBIG_get
// C_errno___errno_EILSEQ_get
// C_errno___errno_EINTR_get
// C_errno___errno_EINVAL_get
// C_errno___errno_EIO_get
// C_errno___errno_EISCONN_get
// C_errno___errno_EISDIR_get
// C_errno___errno_EMFILE_get
// C_errno___errno_EMLINK_get
// C_errno___errno_ENAMETOOLONG_get
// C_errno___errno_ENETDOWN_get
// C_errno___errno_ENETRESET_get
// C_errno___errno_ENETUNREACH_get
// C_errno___errno_ENFILE_get
// C_errno___errno_ENOBUFS_get
// C_errno___errno_ENODEV_get
// C_errno___errno_ENOENT_get
// C_errno___errno_ENOEXEC_get
// C_errno___errno_ENOLCK_get
// C_errno___errno_ENOMEM_get
// C_errno___errno_ENOSPC_get
// C_errno___errno_ENOSYS_get
// C_errno___errno_ENOTCONN_get
// C_errno___errno_ENOTDIR_get
// C_errno___errno_ENOTEMPTY_get
// C_errno___errno_ENOTTY_get
// C_errno___errno_ENXIO_get
// C_errno___errno_EPERM_get
// C_errno___errno_EPIPE_get
// C_errno___errno_ERANGE_get
// C_errno___errno_EROFS_get
// C_errno___errno_ESHUTDOWN_get
// C_errno___errno_ESPIPE_get
// C_errno___errno_ESRCH_get
// C_errno___errno_ETIMEDOUT_get
// C_errno___errno_ETOOMANYREFS_get
// C_errno___errno_EXDEV_get
// C_errno___errno_errno_get
// C_socket___socket_AF_INET6_get
// C_socket___socket_AF_INET_get
// C_socket___socket_AF_UNSPEC_get
// C_socket___socket_INADDR_ANY_get
// C_socket___socket_INADDR_BROADCAST_get
// C_socket___socket_IPPROTO_ICMP_get
// C_socket___socket_IPPROTO_IPV6_get
// C_socket___socket_IPPROTO_IP_get
// C_socket___socket_IPPROTO_RAW_get
// C_socket___socket_IPPROTO_TCP_get
// C_socket___socket_IPPROTO_UDP_get
// C_socket___socket_MSG_CTRUNC_get
// C_socket___socket_MSG_DONTROUTE_get
// C_socket___socket_MSG_OOB_get
// C_socket___socket_MSG_PEEK_get
// C_socket___socket_MSG_TRUNC_get
// C_socket___socket_MSG_WAITALL_get
// C_socket___socket_SHUT_RDWR_get
// C_socket___socket_SHUT_RD_get
// C_socket___socket_SHUT_WR_get
// C_socket___socket_SOCK_DGRAM_get
// C_socket___socket_SOCK_RAW_get
// C_socket___socket_SOCK_STREAM_get
// C_socket___socket_SOMAXCONN_get
// C_socket___socket_SO_ACCEPTCONN_get
// C_socket___socket_SO_BROADCAST_get
// C_socket___socket_SO_DONTROUTE_get
// C_socket___socket_SO_KEEPALIVE_get
// C_socket___socket_SO_OOBINLINE_get
// C_socket___socket_SO_RCVBUF_get
// C_socket___socket_SO_RCVTIMEO_get
// C_socket___socket_SO_REUSEADDR_get
// C_socket___socket_SO_SNDBUF_get
// C_socket___socket_SO_SNDTIMEO_get
// C_socket___socket_SO_TYPE_get
// C_stdio___stdio_FILENAME_MAX_get
// C_stdio___stdio_PATH_MAX_get
// C_stdlib___stdlib_EXIT_FAILURE_get
// C_stdlib___stdlib_EXIT_SUCCESS_get
// C_unistd___unistd_F_OK_get
// C_unistd___unistd_R_OK_get
// C_unistd___unistd_S_IEXEC_get
// C_unistd___unistd_S_IFBLK_get
// C_unistd___unistd_S_IFCHR_get
// C_unistd___unistd_S_IFDIR_get
// C_unistd___unistd_S_IFIFO_get
// C_unistd___unistd_S_IFLNK_get
// C_unistd___unistd_S_IFMT_get
// C_unistd___unistd_S_IFREG_get
// C_unistd___unistd_S_IFSOCK_get
// C_unistd___unistd_S_IREAD_get
// C_unistd___unistd_S_IRGRP_get
// C_unistd___unistd_S_IROTH_get
// C_unistd___unistd_S_IRUSR_get
// C_unistd___unistd_S_IRWXG_get
// C_unistd___unistd_S_IRWXO_get
// C_unistd___unistd_S_IRWXU_get
// C_unistd___unistd_S_IWGRP_get
// C_unistd___unistd_S_IWOTH_get
// C_unistd___unistd_S_IWRITE_get
// C_unistd___unistd_S_IWUSR_get
// C_unistd___unistd_S_IXGRP_get
// C_unistd___unistd_S_IXOTH_get
// C_unistd___unistd_S_IXUSR_get
// C_unistd___unistd_W_OK_get
// C_unistd___unistd_X_OK_get
// avmplus_System_apiVersion_get
// avmplus_System_swfVersion_get
AvmBox shell_toplevel_i2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    typedef AvmRetType_int32_t (AvmObjectT::*FuncType)();
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (AvmBox)(*(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])).*(func))(
    );
}

// avmplus_JObject_fieldSignature
AvmBox shell_toplevel_s2a_oos_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->fieldSignature(
        (JObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
        , AvmThunkUnbox_AvmString(argv[argoff2])
    );
    return (AvmBox) ret;
}

// C_stdio___stdio_remove
// C_stdlib___stdlib___system
// C_stdlib___stdlib_unsetenv
// C_unistd___unistd_chdir
// C_unistd___unistd_mkdir
// C_unistd___unistd_rmdir
// C_unistd___unistd_unlink
// avmplus_System_exec
AvmBox shell_toplevel_i2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    typedef AvmRetType_int32_t (AvmObjectT::*FuncType)(AvmString);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (AvmBox)(*(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])).*(func))(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
}

// C_stdlib___stdlib_getenv
// C_stdlib___stdlib_realpath
// avmplus_File_read
AvmBox shell_toplevel_s2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    typedef AvmRetType_AvmString (AvmObjectT::*FuncType)(AvmString);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (AvmBox)(*(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])).*(func))(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
}

// native_script_function_flash_sampler_getSamples
AvmBox shell_toplevel_func_a2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBox const ret = SamplerScript::getSamples(obj);
    return (AvmBox) ret;
}

// avmplus_JObject_create
AvmBox shell_toplevel_a2a_os_rest_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    const uint32_t argoffV = argoff1 + AvmThunkArgSize_AvmString;
    (void)env;
    JObjectClass* const obj = (JObjectClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    JObject* const ret = obj->create(
        AvmThunkUnbox_AvmString(argv[argoff1])
        , (argc <= 1 ? NULL : argv + argoffV)
        , (argc <= 1 ? 0 : argc - 1)
    );
    return (AvmBox) ret;
}

// native_script_function_flash_sampler_getLexicalScopes
// native_script_function_flash_sampler_getSavedThis
AvmBox shell_toplevel_func_a2a_oo_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    typedef AvmRetType_AvmBox (*FuncType)(AvmObject, AvmObject);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_FUNCTION_HANDLER(env));
    return (AvmBox)(*func)(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])
        , AvmThunkUnbox_AvmObject(argv[argoff1])
    );
}

// avmplus_File_exists
AvmBox shell_toplevel_b2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBool32 const ret = obj->exists(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}

// avmplus_Domain_currentDomain_get
// avmplus_Domain_domainMemory_get
// avmplus_System_private_getArgv
// flash_sampler_NewObjectSample_object_get
// flash_trace_Trace_getListener
AvmBox shell_toplevel_a2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    typedef AvmRetType_AvmBox (AvmObjectT::*FuncType)();
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (AvmBox)(*(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])).*(func))(
    );
}

// C_stdlib___stdlib_setenv
AvmBox shell_toplevel_i2a_ossi_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmString
        , argoff3 = argoff2 + AvmThunkArgSize_AvmString
    };
    (void)argc;
    (void)env;
    ::avmshell::StdlibClass* const obj = (::avmshell::StdlibClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->setenv(
        AvmThunkUnbox_AvmString(argv[argoff1])
        , AvmThunkUnbox_AvmString(argv[argoff2])
        , AvmThunkUnbox_int32_t(argv[argoff3])
    );
    return (AvmBox) ret;
}

// avmplus_Domain_loadBytes
AvmBox shell_toplevel_a2a_oou_opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmObject
    };
    (void)env;
    DomainObject* const obj = (DomainObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBox const ret = obj->loadBytes(
        (ByteArrayObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
        , (argc < 2 ? AvmThunkCoerce_int32_t_uint32_t(0) : AvmThunkUnbox_uint32_t(argv[argoff2]))
    );
    return (AvmBox) ret;
}

// C_string___string_strerror
AvmBox shell_toplevel_s2a_oi_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::CStringClass* const obj = (::avmshell::CStringClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->strerror(
        AvmThunkUnbox_int32_t(argv[argoff1])
    );
    return (AvmBox) ret;
}

// C_stdio___stdio_rename
AvmBox shell_toplevel_i2a_oss_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmString
    };
    (void)argc;
    (void)env;
    ::avmshell::StdioClass* const obj = (::avmshell::StdioClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->rename(
        AvmThunkUnbox_AvmString(argv[argoff1])
        , AvmThunkUnbox_AvmString(argv[argoff2])
    );
    return (AvmBox) ret;
}

// flash_utils_Dictionary_private_init
AvmBox shell_toplevel_v2a_ob_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    DictionaryObject* const obj = (DictionaryObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->init(
        AvmThunkUnbox_AvmBool32(argv[argoff1])
    );
    return kAvmThunkUndefined;
}

// flash_trace_Trace_getLevel
AvmBox shell_toplevel_i2a_oi_opti2_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)env;
    TraceClass* const obj = (TraceClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->getLevel(
        (argc < 1 ? 2 : AvmThunkUnbox_int32_t(argv[argoff1]))
    );
    return (AvmBox) ret;
}

// flash_trace_Trace_setLevel
AvmBox shell_toplevel_a2a_oii_opti2_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_int32_t
    };
    (void)env;
    TraceClass* const obj = (TraceClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBox const ret = obj->setLevel(
        AvmThunkUnbox_int32_t(argv[argoff1])
        , (argc < 2 ? 2 : AvmThunkUnbox_int32_t(argv[argoff2]))
    );
    return (AvmBox) ret;
}

// avmplus_File_writeByteArray
AvmBox shell_toplevel_b2a_oso_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmString
    };
    (void)argc;
    (void)env;
    ::avmshell::FileClass* const obj = (::avmshell::FileClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBool32 const ret = obj->writeByteArray(
        AvmThunkUnbox_AvmString(argv[argoff1])
        , (ByteArrayObject*)AvmThunkUnbox_AvmObject(argv[argoff2])
    );
    return (AvmBox) ret;
}

// C_stdlib___stdlib_abort
// avmplus_System_debugger
// avmplus_System_forceFullCollection
// avmplus_System_queueCollection
AvmBox shell_toplevel_v2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    typedef AvmRetType_void (AvmObjectT::*FuncType)();
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    (*(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])).*(func))(
    );
    return kAvmThunkUndefined;
}

// avmplus_Domain_domainMemory_set
// avmplus_Domain_private_init
// avmplus_System_disposeXML
// avmplus_System_trace
AvmBox shell_toplevel_v2a_oo_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    typedef AvmRetType_void (AvmObjectT::*FuncType)(AvmObject);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    (*(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])).*(func))(
        AvmThunkUnbox_AvmObject(argv[argoff1])
    );
    return kAvmThunkUndefined;
}

// C_unistd___unistd_sleep
AvmBox shell_toplevel_v2a_ou_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::UnistdClass* const obj = (::avmshell::UnistdClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->sleep(
        AvmThunkUnbox_uint32_t(argv[argoff1])
    );
    return kAvmThunkUndefined;
}

// avmplus_System_write
AvmBox shell_toplevel_v2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->write(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return kAvmThunkUndefined;
}

// C_stdlib___stdlib_exit
AvmBox shell_toplevel_v2a_oi_opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)env;
    ::avmshell::StdlibClass* const obj = (::avmshell::StdlibClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->exit(
        (argc < 1 ? 0 : AvmThunkUnbox_int32_t(argv[argoff1]))
    );
    return kAvmThunkUndefined;
}

// avmplus_System_isDebugger
AvmBox shell_toplevel_b2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBool32 const ret = obj->isDebugger();
    return (AvmBox) ret;
}

// C_errno___errno_errno_set
// avmplus_System_exit
AvmBox shell_toplevel_v2a_oi_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    typedef AvmRetType_void (AvmObjectT::*FuncType)(int32_t);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    (*(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])).*(func))(
        AvmThunkUnbox_int32_t(argv[argoff1])
    );
    return kAvmThunkUndefined;
}

// C_unistd___unistd_access
// C_unistd___unistd_chmod
AvmBox shell_toplevel_i2a_osi_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmString
    };
    (void)argc;
    typedef AvmRetType_int32_t (AvmObjectT::*FuncType)(AvmString, int32_t);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (AvmBox)(*(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])).*(func))(
        AvmThunkUnbox_AvmString(argv[argoff1])
        , AvmThunkUnbox_int32_t(argv[argoff2])
    );
}

// native_script_function_flash_sampler__getInvocationCount
double shell_toplevel_func_d2d_oaou_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmBox
        , argoff3 = argoff2 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    double const ret = SamplerScript::_getInvocationCount(obj
        , AvmThunkUnbox_AvmBox(argv[argoff1])
        , (QNameObject*)AvmThunkUnbox_AvmObject(argv[argoff2])
        , AvmThunkUnbox_uint32_t(argv[argoff3])
    );
    return ret;
}

// native_script_function_flash_sampler_getMemberNames
AvmBox shell_toplevel_func_a2a_oab_optbfalse_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmBox
    };
    (void)env;
    ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBox const ret = SamplerScript::getMemberNames(obj
        , AvmThunkUnbox_AvmBox(argv[argoff1])
        , (argc < 2 ? false : AvmThunkUnbox_AvmBool32(argv[argoff2]))
    );
    return (AvmBox) ret;
}

#endif // VMCFG_INDIRECT_NATIVE_THUNKS

class SlotOffsetsAndAsserts
{
private:
    static uint32_t getSlotOffset(Traits* t, int nameId);
public:
    // This exists solely to silence a warning (generally GCC 4.4+):
    // "all member functions in class SlotOffsetsAndAsserts are private"
    static inline void do_nothing();
    static const uint16_t s_slotsOffsetSystemClass = offsetof(::avmshell::SystemClass, m_slots_SystemClass);
    static const uint16_t s_slotsOffsetScriptObject = 0;
    #ifdef DEBUG
    static void doSystemClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
    static const uint16_t s_slotsOffsetFileClass = 0;
    #ifdef DEBUG
    static void doFileClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
    static const uint16_t s_slotsOffsetDomainClass = 0;
    static const uint16_t s_slotsOffsetDomainObject = 0;
    #ifdef DEBUG
    static void doDomainClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
    static const uint16_t s_slotsOffsetStackFrameClass = 0;
    static const uint16_t s_slotsOffsetStackFrameObject = offsetof(StackFrameObject, m_slots_StackFrameObject);
    #ifdef DEBUG
    static void doStackFrameClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
    static const uint16_t s_slotsOffsetSampleClass = 0;
    static const uint16_t s_slotsOffsetSampleObject = offsetof(SampleObject, m_slots_SampleObject);
    #ifdef DEBUG
    static void doSampleClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
    static const uint16_t s_slotsOffsetNewObjectSampleClass = 0;
    static const uint16_t s_slotsOffsetNewObjectSampleObject = offsetof(NewObjectSampleObject, m_slots_NewObjectSampleObject);
    #ifdef DEBUG
    static void doNewObjectSampleClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
    static const uint16_t s_slotsOffsetDeleteObjectSampleClass = 0;
    static const uint16_t s_slotsOffsetDeleteObjectSampleObject = offsetof(DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject);
    #ifdef DEBUG
    static void doDeleteObjectSampleClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
    static const uint16_t s_slotsOffsetTraceClass = offsetof(TraceClass, m_slots_TraceClass);
    #ifdef DEBUG
    static void doTraceClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
    static const uint16_t s_slotsOffsetDictionaryClass = 0;
    static const uint16_t s_slotsOffsetDictionaryObject = 0;
    #ifdef DEBUG
    static void doDictionaryClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
    static const uint16_t s_slotsOffsetStdlibClass = 0;
    #ifdef DEBUG
    static void doStdlibClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
    static const uint16_t s_slotsOffsetUnistdClass = 0;
    #ifdef DEBUG
    static void doUnistdClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
    static const uint16_t s_slotsOffsetCStringClass = 0;
    #ifdef DEBUG
    static void doCStringClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
    static const uint16_t s_slotsOffsetCErrnoClass = 0;
    #ifdef DEBUG
    static void doCErrnoClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
    static const uint16_t s_slotsOffsetStdioClass = 0;
    #ifdef DEBUG
    static void doStdioClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
    static const uint16_t s_slotsOffsetCSocketClass = 0;
    #ifdef DEBUG
    static void doCSocketClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
    static const uint16_t s_slotsOffsetJObjectClass = 0;
    static const uint16_t s_slotsOffsetJObject = 0;
    #ifdef DEBUG
    static void doJObjectClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
};
#ifdef DEBUG
REALLY_INLINE void SlotOffsetsAndAsserts::doSystemClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    MMGC_STATIC_ASSERT(offsetof(::avmshell::SystemClass, m_slots_SystemClass) == s_slotsOffsetSystemClass);
    MMGC_STATIC_ASSERT(offsetof(::avmshell::SystemClass, m_slots_SystemClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(::avmshell::SystemClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(cTraits, 32) == (offsetof(::avmshell::SystemClass, m_slots_SystemClass) + offsetof(_avmshell_SystemClassSlots, m_argv)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::doFileClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::FileClass::EmptySlotsStruct_FileClass) >= 0);
}
REALLY_INLINE void SlotOffsetsAndAsserts::doDomainClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(DomainClass::EmptySlotsStruct_DomainClass) >= 0);
    // MMGC_STATIC_ASSERT(sizeof(DomainObject::EmptySlotsStruct_DomainObject) >= 0);
}
REALLY_INLINE void SlotOffsetsAndAsserts::doStackFrameClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(StackFrameClass::EmptySlotsStruct_StackFrameClass) >= 0);
    MMGC_STATIC_ASSERT(offsetof(StackFrameObject, m_slots_StackFrameObject) == s_slotsOffsetStackFrameObject);
    MMGC_STATIC_ASSERT(offsetof(StackFrameObject, m_slots_StackFrameObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(StackFrameObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(iTraits, 93) == (offsetof(StackFrameObject, m_slots_StackFrameObject) + offsetof(StackFrameObjectSlots, m_name)));
    AvmAssert(getSlotOffset(iTraits, 94) == (offsetof(StackFrameObject, m_slots_StackFrameObject) + offsetof(StackFrameObjectSlots, m_file)));
    AvmAssert(getSlotOffset(iTraits, 95) == (offsetof(StackFrameObject, m_slots_StackFrameObject) + offsetof(StackFrameObjectSlots, m_line)));
    AvmAssert(getSlotOffset(iTraits, 96) == (offsetof(StackFrameObject, m_slots_StackFrameObject) + offsetof(StackFrameObjectSlots, m_scriptID)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::doSampleClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(SampleClass::EmptySlotsStruct_SampleClass) >= 0);
    MMGC_STATIC_ASSERT(offsetof(SampleObject, m_slots_SampleObject) == s_slotsOffsetSampleObject);
    MMGC_STATIC_ASSERT(offsetof(SampleObject, m_slots_SampleObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(SampleObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(iTraits, 99) == (offsetof(SampleObject, m_slots_SampleObject) + offsetof(SampleObjectSlots, m_time)));
    AvmAssert(getSlotOffset(iTraits, 100) == (offsetof(SampleObject, m_slots_SampleObject) + offsetof(SampleObjectSlots, m_stack)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::doNewObjectSampleClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(NewObjectSampleClass::EmptySlotsStruct_NewObjectSampleClass) >= 0);
    MMGC_STATIC_ASSERT(offsetof(NewObjectSampleObject, m_slots_NewObjectSampleObject) == s_slotsOffsetNewObjectSampleObject);
    MMGC_STATIC_ASSERT(offsetof(NewObjectSampleObject, m_slots_NewObjectSampleObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(NewObjectSampleObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(iTraits, 102) == (offsetof(NewObjectSampleObject, m_slots_NewObjectSampleObject) + offsetof(NewObjectSampleObjectSlots, m_id)));
    AvmAssert(getSlotOffset(iTraits, 103) == (offsetof(NewObjectSampleObject, m_slots_NewObjectSampleObject) + offsetof(NewObjectSampleObjectSlots, m_type)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::doDeleteObjectSampleClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(DeleteObjectSampleClass::EmptySlotsStruct_DeleteObjectSampleClass) >= 0);
    MMGC_STATIC_ASSERT(offsetof(DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) == s_slotsOffsetDeleteObjectSampleObject);
    MMGC_STATIC_ASSERT(offsetof(DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(DeleteObjectSampleObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(iTraits, 102) == (offsetof(DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) + offsetof(DeleteObjectSampleObjectSlots, m_id)));
    AvmAssert(getSlotOffset(iTraits, 105) == (offsetof(DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) + offsetof(DeleteObjectSampleObjectSlots, m_size)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::doTraceClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    MMGC_STATIC_ASSERT(offsetof(TraceClass, m_slots_TraceClass) == s_slotsOffsetTraceClass);
    MMGC_STATIC_ASSERT(offsetof(TraceClass, m_slots_TraceClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(TraceClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(cTraits, 139) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_OFF)));
    AvmAssert(getSlotOffset(cTraits, 140) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_METHODS)));
    AvmAssert(getSlotOffset(cTraits, 141) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_METHODS_WITH_ARGS)));
    AvmAssert(getSlotOffset(cTraits, 142) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_METHODS_AND_LINES)));
    AvmAssert(getSlotOffset(cTraits, 143) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_METHODS_AND_LINES_WITH_ARGS)));
    AvmAssert(getSlotOffset(cTraits, 144) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_FILE)));
    AvmAssert(getSlotOffset(cTraits, 145) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_LISTENER)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::doDictionaryClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(DictionaryClass::EmptySlotsStruct_DictionaryClass) >= 0);
    // MMGC_STATIC_ASSERT(sizeof(DictionaryObject::EmptySlotsStruct_DictionaryObject) >= 0);
}
REALLY_INLINE void SlotOffsetsAndAsserts::doStdlibClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::StdlibClass::EmptySlotsStruct_StdlibClass) >= 0);
}
REALLY_INLINE void SlotOffsetsAndAsserts::doUnistdClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::UnistdClass::EmptySlotsStruct_UnistdClass) >= 0);
}
REALLY_INLINE void SlotOffsetsAndAsserts::doCStringClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::CStringClass::EmptySlotsStruct_CStringClass) >= 0);
}
REALLY_INLINE void SlotOffsetsAndAsserts::doCErrnoClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::CErrnoClass::EmptySlotsStruct_CErrnoClass) >= 0);
}
REALLY_INLINE void SlotOffsetsAndAsserts::doStdioClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::StdioClass::EmptySlotsStruct_StdioClass) >= 0);
}
REALLY_INLINE void SlotOffsetsAndAsserts::doCSocketClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::CSocketClass::EmptySlotsStruct_CSocketClass) >= 0);
}
REALLY_INLINE void SlotOffsetsAndAsserts::doJObjectClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(JObjectClass::EmptySlotsStruct_JObjectClass) >= 0);
    // MMGC_STATIC_ASSERT(sizeof(JObject::EmptySlotsStruct_JObject) >= 0);
}
#endif // DEBUG

AVMTHUNK_NATIVE_CLASS_GLUE_EXACT(SystemClass, ::avmshell::SystemClass, SlotOffsetsAndAsserts::doSystemClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(FileClass, ::avmshell::FileClass, SlotOffsetsAndAsserts::doFileClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE_EXACT(DomainClass, DomainClass, SlotOffsetsAndAsserts::doDomainClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(StackFrameClass, StackFrameClass, SlotOffsetsAndAsserts::doStackFrameClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(SampleClass, SampleClass, SlotOffsetsAndAsserts::doSampleClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(NewObjectSampleClass, NewObjectSampleClass, SlotOffsetsAndAsserts::doNewObjectSampleClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(DeleteObjectSampleClass, DeleteObjectSampleClass, SlotOffsetsAndAsserts::doDeleteObjectSampleClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(TraceClass, TraceClass, SlotOffsetsAndAsserts::doTraceClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE_EXACT(DictionaryClass, DictionaryClass, SlotOffsetsAndAsserts::doDictionaryClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(StdlibClass, ::avmshell::StdlibClass, SlotOffsetsAndAsserts::doStdlibClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(UnistdClass, ::avmshell::UnistdClass, SlotOffsetsAndAsserts::doUnistdClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(CStringClass, ::avmshell::CStringClass, SlotOffsetsAndAsserts::doCStringClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(CErrnoClass, ::avmshell::CErrnoClass, SlotOffsetsAndAsserts::doCErrnoClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(StdioClass, ::avmshell::StdioClass, SlotOffsetsAndAsserts::doStdioClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(CSocketClass, ::avmshell::CSocketClass, SlotOffsetsAndAsserts::doCSocketClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(JObjectClass, JObjectClass, SlotOffsetsAndAsserts::doJObjectClassAsserts)

AVMTHUNK_BEGIN_NATIVE_TABLES(shell_toplevel)

    AVMTHUNK_BEGIN_NATIVE_METHODS(shell_toplevel)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_exit, ::avmshell::SystemClass::exit)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_exec, ::avmshell::SystemClass::exec)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_getAvmplusVersion, ::avmshell::SystemClass::getAvmplusVersion)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_getFeatures, ::avmshell::SystemClass::getFeatures)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_getRunmode, ::avmshell::SystemClass::getRunmode)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_trace, ::avmshell::SystemClass::trace)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_write, ::avmshell::SystemClass::write)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_debugger, ::avmshell::SystemClass::debugger)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_isDebugger, ::avmshell::SystemClass::isDebugger)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_getTimer, ::avmshell::SystemClass::getTimer)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_private_getArgv, ::avmshell::SystemClass::getArgv)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_readLine, ::avmshell::SystemClass::readLine)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_totalMemory_get, ::avmshell::SystemClass::get_totalMemory)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_freeMemory_get, ::avmshell::SystemClass::get_freeMemory)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_privateMemory_get, ::avmshell::SystemClass::get_privateMemory)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_forceFullCollection, ::avmshell::SystemClass::forceFullCollection)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_queueCollection, ::avmshell::SystemClass::queueCollection)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_swfVersion_get, ::avmshell::SystemClass::get_swfVersion)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_apiVersion_get, ::avmshell::SystemClass::get_apiVersion)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_disposeXML, ::avmshell::SystemClass::disposeXML)
        AVMTHUNK_NATIVE_METHOD(avmplus_File_exists, ::avmshell::FileClass::exists)
        AVMTHUNK_NATIVE_METHOD(avmplus_File_read, ::avmshell::FileClass::read)
        AVMTHUNK_NATIVE_METHOD(avmplus_File_write, ::avmshell::FileClass::write)
        AVMTHUNK_NATIVE_METHOD(avmplus_File_readByteArray, ::avmshell::FileClass::readByteArray)
        AVMTHUNK_NATIVE_METHOD(avmplus_File_writeByteArray, ::avmshell::FileClass::writeByteArray)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_currentDomain_get, DomainClass::get_currentDomain)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get, DomainClass::get_MIN_DOMAIN_MEMORY_LENGTH)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_private_init, DomainObject::init)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_loadBytes, DomainObject::loadBytes)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_getClass, DomainObject::getClass)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_domainMemory_get, DomainObject::get_domainMemory)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_domainMemory_set, DomainObject::set_domainMemory)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_getMasterString, SamplerScript::getMasterString)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_getSavedThis, SamplerScript::getSavedThis)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_getLexicalScopes, SamplerScript::getLexicalScopes)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_isGetterSetter, SamplerScript::isGetterSetter)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler__getInvocationCount, SamplerScript::_getInvocationCount)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_getSampleCount, SamplerScript::getSampleCount)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_getSamples, SamplerScript::getSamples)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_getMemberNames, SamplerScript::getMemberNames)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_getSize, SamplerScript::getSize)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler__setSamplerCallback, SamplerScript::_setSamplerCallback)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_sampleInternalAllocs, SamplerScript::sampleInternalAllocs)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_pauseSampling, SamplerScript::pauseSampling)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_stopSampling, SamplerScript::stopSampling)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_startSampling, SamplerScript::startSampling)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_clearSamples, SamplerScript::clearSamples)
        AVMTHUNK_NATIVE_METHOD(flash_sampler_NewObjectSample_object_get, NewObjectSampleObject::get_object)
        AVMTHUNK_NATIVE_METHOD(flash_sampler_NewObjectSample_size_get, NewObjectSampleObject::get_size)
        AVMTHUNK_NATIVE_METHOD(flash_trace_Trace_setLevel, TraceClass::setLevel)
        AVMTHUNK_NATIVE_METHOD(flash_trace_Trace_getLevel, TraceClass::getLevel)
        AVMTHUNK_NATIVE_METHOD(flash_trace_Trace_setListener, TraceClass::setListener)
        AVMTHUNK_NATIVE_METHOD(flash_trace_Trace_getListener, TraceClass::getListener)
        AVMTHUNK_NATIVE_METHOD(flash_utils_Dictionary_private_init, DictionaryObject::init)
        AVMTHUNK_NATIVE_METHOD(C_stdlib___stdlib_EXIT_SUCCESS_get, ::avmshell::StdlibClass::get_EXIT_SUCCESS)
        AVMTHUNK_NATIVE_METHOD(C_stdlib___stdlib_EXIT_FAILURE_get, ::avmshell::StdlibClass::get_EXIT_FAILURE)
        AVMTHUNK_NATIVE_METHOD(C_stdlib___stdlib_abort, ::avmshell::StdlibClass::abort)
        AVMTHUNK_NATIVE_METHOD(C_stdlib___stdlib_exit, ::avmshell::StdlibClass::exit)
        AVMTHUNK_NATIVE_METHOD(C_stdlib___stdlib_getenv, ::avmshell::StdlibClass::getenv)
        AVMTHUNK_NATIVE_METHOD(C_stdlib___stdlib_setenv, ::avmshell::StdlibClass::setenv)
        AVMTHUNK_NATIVE_METHOD(C_stdlib___stdlib_unsetenv, ::avmshell::StdlibClass::unsetenv)
        AVMTHUNK_NATIVE_METHOD(C_stdlib___stdlib_realpath, ::avmshell::StdlibClass::realpath)
        AVMTHUNK_NATIVE_METHOD(C_stdlib___stdlib___system, ::avmshell::StdlibClass::__system)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_F_OK_get, ::avmshell::UnistdClass::get_F_OK)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_X_OK_get, ::avmshell::UnistdClass::get_X_OK)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_W_OK_get, ::avmshell::UnistdClass::get_W_OK)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_R_OK_get, ::avmshell::UnistdClass::get_R_OK)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IFMT_get, ::avmshell::UnistdClass::get_S_IFMT)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IFIFO_get, ::avmshell::UnistdClass::get_S_IFIFO)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IFCHR_get, ::avmshell::UnistdClass::get_S_IFCHR)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IFDIR_get, ::avmshell::UnistdClass::get_S_IFDIR)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IFBLK_get, ::avmshell::UnistdClass::get_S_IFBLK)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IFREG_get, ::avmshell::UnistdClass::get_S_IFREG)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IFLNK_get, ::avmshell::UnistdClass::get_S_IFLNK)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IFSOCK_get, ::avmshell::UnistdClass::get_S_IFSOCK)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IRWXU_get, ::avmshell::UnistdClass::get_S_IRWXU)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IRUSR_get, ::avmshell::UnistdClass::get_S_IRUSR)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IWUSR_get, ::avmshell::UnistdClass::get_S_IWUSR)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IXUSR_get, ::avmshell::UnistdClass::get_S_IXUSR)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IRWXG_get, ::avmshell::UnistdClass::get_S_IRWXG)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IRGRP_get, ::avmshell::UnistdClass::get_S_IRGRP)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IWGRP_get, ::avmshell::UnistdClass::get_S_IWGRP)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IXGRP_get, ::avmshell::UnistdClass::get_S_IXGRP)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IRWXO_get, ::avmshell::UnistdClass::get_S_IRWXO)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IROTH_get, ::avmshell::UnistdClass::get_S_IROTH)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IWOTH_get, ::avmshell::UnistdClass::get_S_IWOTH)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IXOTH_get, ::avmshell::UnistdClass::get_S_IXOTH)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IREAD_get, ::avmshell::UnistdClass::get_S_IREAD)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IWRITE_get, ::avmshell::UnistdClass::get_S_IWRITE)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IEXEC_get, ::avmshell::UnistdClass::get_S_IEXEC)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_access, ::avmshell::UnistdClass::access)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_chdir, ::avmshell::UnistdClass::chdir)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_chmod, ::avmshell::UnistdClass::chmod)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_getcwd, ::avmshell::UnistdClass::getcwd)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_gethostname, ::avmshell::UnistdClass::gethostname)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_getlogin, ::avmshell::UnistdClass::getlogin)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_mkdir, ::avmshell::UnistdClass::mkdir)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_rmdir, ::avmshell::UnistdClass::rmdir)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_sleep, ::avmshell::UnistdClass::sleep)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_unlink, ::avmshell::UnistdClass::unlink)
        AVMTHUNK_NATIVE_METHOD(C_string___string_strerror, ::avmshell::CStringClass::strerror)
        AVMTHUNK_NATIVE_METHOD(C_string___string_strlen, ::avmshell::CStringClass::strlen)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EDOM_get, ::avmshell::CErrnoClass::get_EDOM)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EILSEQ_get, ::avmshell::CErrnoClass::get_EILSEQ)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ERANGE_get, ::avmshell::CErrnoClass::get_ERANGE)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EPERM_get, ::avmshell::CErrnoClass::get_EPERM)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENOENT_get, ::avmshell::CErrnoClass::get_ENOENT)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ESRCH_get, ::avmshell::CErrnoClass::get_ESRCH)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EINTR_get, ::avmshell::CErrnoClass::get_EINTR)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EIO_get, ::avmshell::CErrnoClass::get_EIO)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENXIO_get, ::avmshell::CErrnoClass::get_ENXIO)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_E2BIG_get, ::avmshell::CErrnoClass::get_E2BIG)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENOEXEC_get, ::avmshell::CErrnoClass::get_ENOEXEC)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EBADF_get, ::avmshell::CErrnoClass::get_EBADF)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ECHILD_get, ::avmshell::CErrnoClass::get_ECHILD)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EAGAIN_get, ::avmshell::CErrnoClass::get_EAGAIN)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENOMEM_get, ::avmshell::CErrnoClass::get_ENOMEM)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EACCES_get, ::avmshell::CErrnoClass::get_EACCES)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EFAULT_get, ::avmshell::CErrnoClass::get_EFAULT)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EBUSY_get, ::avmshell::CErrnoClass::get_EBUSY)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EEXIST_get, ::avmshell::CErrnoClass::get_EEXIST)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EXDEV_get, ::avmshell::CErrnoClass::get_EXDEV)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENODEV_get, ::avmshell::CErrnoClass::get_ENODEV)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENOTDIR_get, ::avmshell::CErrnoClass::get_ENOTDIR)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EISDIR_get, ::avmshell::CErrnoClass::get_EISDIR)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EINVAL_get, ::avmshell::CErrnoClass::get_EINVAL)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENFILE_get, ::avmshell::CErrnoClass::get_ENFILE)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EMFILE_get, ::avmshell::CErrnoClass::get_EMFILE)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENOTTY_get, ::avmshell::CErrnoClass::get_ENOTTY)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EFBIG_get, ::avmshell::CErrnoClass::get_EFBIG)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENOSPC_get, ::avmshell::CErrnoClass::get_ENOSPC)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ESPIPE_get, ::avmshell::CErrnoClass::get_ESPIPE)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EROFS_get, ::avmshell::CErrnoClass::get_EROFS)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EMLINK_get, ::avmshell::CErrnoClass::get_EMLINK)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EPIPE_get, ::avmshell::CErrnoClass::get_EPIPE)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EDEADLK_get, ::avmshell::CErrnoClass::get_EDEADLK)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENAMETOOLONG_get, ::avmshell::CErrnoClass::get_ENAMETOOLONG)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENOLCK_get, ::avmshell::CErrnoClass::get_ENOLCK)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENOSYS_get, ::avmshell::CErrnoClass::get_ENOSYS)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENOTEMPTY_get, ::avmshell::CErrnoClass::get_ENOTEMPTY)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENETDOWN_get, ::avmshell::CErrnoClass::get_ENETDOWN)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENETUNREACH_get, ::avmshell::CErrnoClass::get_ENETUNREACH)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENETRESET_get, ::avmshell::CErrnoClass::get_ENETRESET)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ECONNABORTED_get, ::avmshell::CErrnoClass::get_ECONNABORTED)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ECONNRESET_get, ::avmshell::CErrnoClass::get_ECONNRESET)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENOBUFS_get, ::avmshell::CErrnoClass::get_ENOBUFS)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EISCONN_get, ::avmshell::CErrnoClass::get_EISCONN)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENOTCONN_get, ::avmshell::CErrnoClass::get_ENOTCONN)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ESHUTDOWN_get, ::avmshell::CErrnoClass::get_ESHUTDOWN)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ETOOMANYREFS_get, ::avmshell::CErrnoClass::get_ETOOMANYREFS)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ETIMEDOUT_get, ::avmshell::CErrnoClass::get_ETIMEDOUT)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ECONNREFUSED_get, ::avmshell::CErrnoClass::get_ECONNREFUSED)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_errno_get, ::avmshell::CErrnoClass::get_errno)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_errno_set, ::avmshell::CErrnoClass::set_errno)
        AVMTHUNK_NATIVE_METHOD(C_stdio___stdio_FILENAME_MAX_get, ::avmshell::StdioClass::get_FILENAME_MAX)
        AVMTHUNK_NATIVE_METHOD(C_stdio___stdio_PATH_MAX_get, ::avmshell::StdioClass::get_PATH_MAX)
        AVMTHUNK_NATIVE_METHOD(C_stdio___stdio_remove, ::avmshell::StdioClass::remove)
        AVMTHUNK_NATIVE_METHOD(C_stdio___stdio_rename, ::avmshell::StdioClass::rename)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SOCK_RAW_get, ::avmshell::CSocketClass::get_SOCK_RAW)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SOCK_STREAM_get, ::avmshell::CSocketClass::get_SOCK_STREAM)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SOCK_DGRAM_get, ::avmshell::CSocketClass::get_SOCK_DGRAM)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SO_ACCEPTCONN_get, ::avmshell::CSocketClass::get_SO_ACCEPTCONN)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SO_BROADCAST_get, ::avmshell::CSocketClass::get_SO_BROADCAST)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SO_DONTROUTE_get, ::avmshell::CSocketClass::get_SO_DONTROUTE)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SO_KEEPALIVE_get, ::avmshell::CSocketClass::get_SO_KEEPALIVE)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SO_OOBINLINE_get, ::avmshell::CSocketClass::get_SO_OOBINLINE)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SO_RCVBUF_get, ::avmshell::CSocketClass::get_SO_RCVBUF)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SO_RCVTIMEO_get, ::avmshell::CSocketClass::get_SO_RCVTIMEO)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SO_REUSEADDR_get, ::avmshell::CSocketClass::get_SO_REUSEADDR)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SO_SNDBUF_get, ::avmshell::CSocketClass::get_SO_SNDBUF)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SO_SNDTIMEO_get, ::avmshell::CSocketClass::get_SO_SNDTIMEO)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SO_TYPE_get, ::avmshell::CSocketClass::get_SO_TYPE)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SOMAXCONN_get, ::avmshell::CSocketClass::get_SOMAXCONN)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_MSG_CTRUNC_get, ::avmshell::CSocketClass::get_MSG_CTRUNC)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_MSG_DONTROUTE_get, ::avmshell::CSocketClass::get_MSG_DONTROUTE)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_MSG_OOB_get, ::avmshell::CSocketClass::get_MSG_OOB)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_MSG_PEEK_get, ::avmshell::CSocketClass::get_MSG_PEEK)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_MSG_TRUNC_get, ::avmshell::CSocketClass::get_MSG_TRUNC)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_MSG_WAITALL_get, ::avmshell::CSocketClass::get_MSG_WAITALL)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_AF_INET_get, ::avmshell::CSocketClass::get_AF_INET)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_AF_INET6_get, ::avmshell::CSocketClass::get_AF_INET6)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_AF_UNSPEC_get, ::avmshell::CSocketClass::get_AF_UNSPEC)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SHUT_RD_get, ::avmshell::CSocketClass::get_SHUT_RD)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SHUT_RDWR_get, ::avmshell::CSocketClass::get_SHUT_RDWR)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SHUT_WR_get, ::avmshell::CSocketClass::get_SHUT_WR)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_IPPROTO_IP_get, ::avmshell::CSocketClass::get_IPPROTO_IP)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_IPPROTO_IPV6_get, ::avmshell::CSocketClass::get_IPPROTO_IPV6)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_IPPROTO_ICMP_get, ::avmshell::CSocketClass::get_IPPROTO_ICMP)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_IPPROTO_RAW_get, ::avmshell::CSocketClass::get_IPPROTO_RAW)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_IPPROTO_TCP_get, ::avmshell::CSocketClass::get_IPPROTO_TCP)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_IPPROTO_UDP_get, ::avmshell::CSocketClass::get_IPPROTO_UDP)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_INADDR_ANY_get, ::avmshell::CSocketClass::get_INADDR_ANY)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_INADDR_BROADCAST_get, ::avmshell::CSocketClass::get_INADDR_BROADCAST)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket___gethostbyaddr, ::avmshell::CSocketClass::__gethostbyaddr)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket___gethostbyname, ::avmshell::CSocketClass::__gethostbyname)
        AVMTHUNK_NATIVE_METHOD(avmplus_JObject_create, JObjectClass::create)
        AVMTHUNK_NATIVE_METHOD(avmplus_JObject_createArray, JObjectClass::createArray)
        AVMTHUNK_NATIVE_METHOD(avmplus_JObject_toArray, JObjectClass::toArray)
        AVMTHUNK_NATIVE_METHOD(avmplus_JObject_constructorSignature, JObjectClass::constructorSignature)
        AVMTHUNK_NATIVE_METHOD(avmplus_JObject_methodSignature, JObjectClass::methodSignature)
        AVMTHUNK_NATIVE_METHOD(avmplus_JObject_fieldSignature, JObjectClass::fieldSignature)
    AVMTHUNK_END_NATIVE_METHODS()

    AVMTHUNK_BEGIN_NATIVE_CLASSES(shell_toplevel)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_System, SystemClass, ::avmshell::SystemClass, SlotOffsetsAndAsserts::s_slotsOffsetSystemClass, ScriptObject, SlotOffsetsAndAsserts::s_slotsOffsetScriptObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_File, FileClass, ::avmshell::FileClass, SlotOffsetsAndAsserts::s_slotsOffsetFileClass, ScriptObject, SlotOffsetsAndAsserts::s_slotsOffsetScriptObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_Domain, DomainClass, DomainClass, SlotOffsetsAndAsserts::s_slotsOffsetDomainClass, DomainObject, SlotOffsetsAndAsserts::s_slotsOffsetDomainObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_StackFrame, StackFrameClass, StackFrameClass, SlotOffsetsAndAsserts::s_slotsOffsetStackFrameClass, StackFrameObject, SlotOffsetsAndAsserts::s_slotsOffsetStackFrameObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_Sample, SampleClass, SampleClass, SlotOffsetsAndAsserts::s_slotsOffsetSampleClass, SampleObject, SlotOffsetsAndAsserts::s_slotsOffsetSampleObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_NewObjectSample, NewObjectSampleClass, NewObjectSampleClass, SlotOffsetsAndAsserts::s_slotsOffsetNewObjectSampleClass, NewObjectSampleObject, SlotOffsetsAndAsserts::s_slotsOffsetNewObjectSampleObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_DeleteObjectSample, DeleteObjectSampleClass, DeleteObjectSampleClass, SlotOffsetsAndAsserts::s_slotsOffsetDeleteObjectSampleClass, DeleteObjectSampleObject, SlotOffsetsAndAsserts::s_slotsOffsetDeleteObjectSampleObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_trace_Trace, TraceClass, TraceClass, SlotOffsetsAndAsserts::s_slotsOffsetTraceClass, ScriptObject, SlotOffsetsAndAsserts::s_slotsOffsetScriptObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_utils_Dictionary, DictionaryClass, DictionaryClass, SlotOffsetsAndAsserts::s_slotsOffsetDictionaryClass, DictionaryObject, SlotOffsetsAndAsserts::s_slotsOffsetDictionaryObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_C_stdlib___stdlib, StdlibClass, ::avmshell::StdlibClass, SlotOffsetsAndAsserts::s_slotsOffsetStdlibClass, ScriptObject, SlotOffsetsAndAsserts::s_slotsOffsetScriptObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_C_unistd___unistd, UnistdClass, ::avmshell::UnistdClass, SlotOffsetsAndAsserts::s_slotsOffsetUnistdClass, ScriptObject, SlotOffsetsAndAsserts::s_slotsOffsetScriptObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_C_string___string, CStringClass, ::avmshell::CStringClass, SlotOffsetsAndAsserts::s_slotsOffsetCStringClass, ScriptObject, SlotOffsetsAndAsserts::s_slotsOffsetScriptObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_C_errno___errno, CErrnoClass, ::avmshell::CErrnoClass, SlotOffsetsAndAsserts::s_slotsOffsetCErrnoClass, ScriptObject, SlotOffsetsAndAsserts::s_slotsOffsetScriptObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_C_stdio___stdio, StdioClass, ::avmshell::StdioClass, SlotOffsetsAndAsserts::s_slotsOffsetStdioClass, ScriptObject, SlotOffsetsAndAsserts::s_slotsOffsetScriptObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_C_socket___socket, CSocketClass, ::avmshell::CSocketClass, SlotOffsetsAndAsserts::s_slotsOffsetCSocketClass, ScriptObject, SlotOffsetsAndAsserts::s_slotsOffsetScriptObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_JObject, JObjectClass, JObjectClass, SlotOffsetsAndAsserts::s_slotsOffsetJObjectClass, JObject, SlotOffsetsAndAsserts::s_slotsOffsetJObject, false)
    AVMTHUNK_END_NATIVE_CLASSES()

AVMTHUNK_END_NATIVE_TABLES()

AVMTHUNK_DEFINE_NATIVE_INITIALIZER(shell_toplevel)

/* abc */
const uint8_t shell_toplevel_abc_data[15825] = {
  16,   0,  46,   0,   7,   0,   2,   1,   3,   4, 255, 255, 255, 255,  15,   0,
   0, 255,   2,   6,  83, 121, 115, 116, 101, 109,  19, 115, 104, 101, 108, 108,
  95, 116, 111, 112, 108, 101, 118, 101, 108,  46,  97, 115,  36,  49,   0,   7,
  97, 118, 109, 112, 108, 117, 115,   7,  67,  46, 101, 114, 114, 110, 111,   8,
 114, 101,  97, 100,  76, 105, 110, 101,   6,  83, 116, 114, 105, 110, 103,   8,
 103, 101, 116,  84, 105, 109, 101, 114,   4, 117, 105, 110, 116,   5, 116, 114,
  97,  99, 101,   6,  68, 111, 109,  97, 105, 110,  13,  99, 117, 114, 114, 101,
 110, 116,  68, 111, 109,  97, 105, 110,   8, 103, 101, 116,  67, 108,  97, 115,
 115,   5,  67, 108,  97, 115, 115,   8, 100, 101,  98, 117, 103, 103, 101, 114,
  14,  97, 118, 109, 112, 108, 117, 115,  58,  83, 121, 115, 116, 101, 109,   4,
  97, 114, 103, 118,   7, 103, 101, 116,  65, 114, 103, 118,   6,  79,  98, 106,
 101,  99, 116,   4, 118, 111, 105, 100,   3, 105, 110, 116,   5,  65, 114, 114,
  97, 121,   7,  66, 111, 111, 108, 101,  97, 110,   6,  78, 117, 109,  98, 101,
 114,   3,  88,  77,  76,   3, 238, 138, 148,   4, 101, 120, 105, 116,   4, 101,
 120, 101,  99,  17, 103, 101, 116,  65, 118, 109, 112, 108, 117, 115,  86, 101,
 114, 115, 105, 111, 110,  11, 103, 101, 116,  70, 101,  97, 116, 117, 114, 101,
 115,  10, 103, 101, 116,  82, 117, 110, 109, 111, 100, 101,   5, 119, 114, 105,
 116, 101,  10, 105, 115,  68, 101,  98, 117, 103, 103, 101, 114,  11, 116, 111,
 116,  97, 108,  77, 101, 109, 111, 114, 121,  10, 102, 114, 101, 101,  77, 101,
 109, 111, 114, 121,  13, 112, 114, 105, 118,  97, 116, 101,  77, 101, 109, 111,
 114, 121,  19, 102, 111, 114,  99, 101,  70, 117, 108, 108,  67, 111, 108, 108,
 101,  99, 116, 105, 111, 110,  15, 113, 117, 101, 117, 101,  67, 111, 108, 108,
 101,  99, 116, 105, 111, 110,  10, 115, 119, 102,  86, 101, 114, 115, 105, 111,
 110,  10,  97, 112, 105,  86, 101, 114, 115, 105, 111, 110,  10, 100, 105, 115,
 112, 111, 115, 101,  88,  77,  76,  12,  97, 118, 109, 112, 108, 117, 115,  58,
  70, 105, 108, 101,  11, 102, 108,  97, 115, 104,  46, 117, 116, 105, 108, 115,
   9,  66, 121, 116, 101,  65, 114, 114,  97, 121,   6, 101, 120, 105, 115, 116,
 115,   4, 114, 101,  97, 100,  13, 114, 101,  97, 100,  66, 121, 116, 101,  65,
 114, 114,  97, 121,  14, 119, 114, 105, 116, 101,  66, 121, 116, 101,  65, 114,
 114,  97, 121,   4,  70, 105, 108, 101,  25, 102, 108,  97, 115, 104,  46, 115,
 121, 115, 116, 101, 109,  58,  67,  97, 112,  97,  98, 105, 108, 105, 116, 105,
 101, 115,   7,  65,  86,  77,  80, 108, 117, 115,  12, 102, 108,  97, 115, 104,
  46, 115, 121, 115, 116, 101, 109,  10, 112, 108,  97, 121, 101, 114,  84, 121,
 112, 101,  12,  67,  97, 112,  97,  98, 105, 108, 105, 116, 105, 101, 115,   5,
 101, 114, 114, 110, 111,  10,  97, 118, 109, 112, 108, 117, 115, 238, 138, 148,
   6, 110,  97, 116, 105, 118, 101,   3,  99, 108, 115,  23,  58,  58,  97, 118,
 109, 115, 104, 101, 108, 108,  58,  58,  83, 121, 115, 116, 101, 109,  67, 108,
  97, 115, 115,   7,  99, 108,  97, 115, 115, 103,  99,   5, 101, 120,  97,  99,
 116,   7, 109, 101, 116, 104, 111, 100, 115,   4,  97, 117, 116, 111,  21,  58,
  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  70, 105, 108, 101,  67,
 108,  97, 115, 115,  15, 102, 108,  97, 115, 104,  46, 115, 121, 115, 116, 101,
 109, 238, 138, 148,  14, 103, 101, 116,  67, 108,  97, 115, 115,  66, 121,  78,
  97, 109, 101,   5, 112, 114, 105, 110, 116,  14,  97, 118, 109, 112, 108, 117,
 115,  58,  68, 111, 109,  97, 105, 110,   4, 105, 110, 105, 116,  11,  68, 111,
 109,  97, 105, 110,  46,  97, 115,  36,  50,   9, 108, 111,  97, 100,  66, 121,
 116, 101, 115,  24,  77,  73,  78,  95,  68,  79,  77,  65,  73,  78,  95,  77,
  69,  77,  79,  82,  89,  95,  76,  69,  78,  71,  84,  72,   4, 108, 111,  97,
 100,  12, 100, 111, 109,  97, 105, 110,  77, 101, 109, 111, 114, 121,  11,  68,
 111, 109,  97, 105, 110,  67, 108,  97, 115, 115,   2, 103,  99,   8, 105, 110,
 115, 116,  97, 110,  99, 101,  12,  68, 111, 109,  97, 105, 110,  79,  98, 106,
 101,  99, 116,   8,  70, 117, 110,  99, 116, 105, 111, 110,   5,  81,  78,  97,
 109, 101,  19,  95, 103, 101, 116,  73, 110, 118, 111,  99,  97, 116, 105, 111,
 110,  67, 111, 117, 110, 116,  12,  83,  97, 109, 112, 108, 101, 114,  46,  97,
 115,  36,  51,  13, 102, 108,  97, 115, 104,  46, 115,  97, 109, 112, 108, 101,
 114,   1, 102,   1, 101,   3, 114, 101, 116,  19,  95, 115, 101, 116,  83,  97,
 109, 112, 108, 101, 114,  67,  97, 108, 108,  98,  97,  99, 107,   7, 119, 114,
  97, 112, 112, 101, 114,  24, 102, 108,  97, 115, 104,  46, 115,  97, 109, 112,
 108, 101, 114,  58,  83, 116,  97,  99, 107,  70, 114,  97, 109, 101,   4, 110,
  97, 109, 101,   2,  40,  41,   4, 102, 105, 108, 101,   1,  91,   1,  58,   4,
 108, 105, 110, 101,   1,  93,   8, 115,  99, 114, 105, 112, 116,  73,  68,   8,
 116, 111,  83, 116, 114, 105, 110, 103,  10,  83, 116,  97,  99, 107,  70, 114,
  97, 109, 101,  20, 102, 108,  97, 115, 104,  46, 115,  97, 109, 112, 108, 101,
 114,  58,  83,  97, 109, 112, 108, 101,   4, 116, 105, 109, 101,   5, 115, 116,
  97,  99, 107,   6,  83,  97, 109, 112, 108, 101,  29, 102, 108,  97, 115, 104,
  46, 115,  97, 109, 112, 108, 101, 114,  58,  78, 101, 119,  79,  98, 106, 101,
  99, 116,  83,  97, 109, 112, 108, 101,   2, 105, 100,   4, 116, 121, 112, 101,
   6, 111,  98, 106, 101,  99, 116,   4, 115, 105, 122, 101,  15,  78, 101, 119,
  79,  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  32, 102, 108,  97,
 115, 104,  46, 115,  97, 109, 112, 108, 101, 114,  58,  68, 101, 108, 101, 116,
 101,  79,  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  18,  68, 101,
 108, 101, 116, 101,  79,  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,
  16, 102, 108,  97, 115, 104,  46, 115,  97, 109, 112, 108, 101, 114, 238, 138,
 148,  15,  83, 116,  97,  99, 107,  70, 114,  97, 109, 101,  67, 108,  97, 115,
 115,  16,  83, 116,  97,  99, 107,  70, 114,  97, 109, 101,  79,  98, 106, 101,
  99, 116,  12,  99, 111, 110, 115, 116, 115, 101, 116, 116, 101, 114, 115,   4,
 116, 114, 117, 101,  11,  83,  97, 109, 112, 108, 101,  67, 108,  97, 115, 115,
  12,  83,  97, 109, 112, 108, 101,  79,  98, 106, 101,  99, 116,  20,  78, 101,
 119,  79,  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  67, 108,  97,
 115, 115,  21,  78, 101, 119,  79,  98, 106, 101,  99, 116,  83,  97, 109, 112,
 108, 101,  79,  98, 106, 101,  99, 116,  23,  68, 101, 108, 101, 116, 101,  79,
  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  67, 108,  97, 115, 115,
  24,  68, 101, 108, 101, 116, 101,  79,  98, 106, 101,  99, 116,  83,  97, 109,
 112, 108, 101,  79,  98, 106, 101,  99, 116,  12,  99, 108, 101,  97, 114,  83,
  97, 109, 112, 108, 101, 115,  27,  83,  97, 109, 112, 108, 101, 114,  83,  99,
 114, 105, 112, 116,  58,  58,  99, 108, 101,  97, 114,  83,  97, 109, 112, 108,
 101, 115,  13, 115, 116,  97, 114, 116,  83,  97, 109, 112, 108, 105, 110, 103,
  28,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58,
 115, 116,  97, 114, 116,  83,  97, 109, 112, 108, 105, 110, 103,  12, 115, 116,
 111, 112,  83,  97, 109, 112, 108, 105, 110, 103,  27,  83,  97, 109, 112, 108,
 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 115, 116, 111, 112,  83,  97,
 109, 112, 108, 105, 110, 103,  13, 112,  97, 117, 115, 101,  83,  97, 109, 112,
 108, 105, 110, 103,  28,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105,
 112, 116,  58,  58, 112,  97, 117, 115, 101,  83,  97, 109, 112, 108, 105, 110,
 103,  20, 115,  97, 109, 112, 108, 101,  73, 110, 116, 101, 114, 110,  97, 108,
  65, 108, 108, 111,  99, 115,  35,  83,  97, 109, 112, 108, 101, 114,  83,  99,
 114, 105, 112, 116,  58,  58, 115,  97, 109, 112, 108, 101,  73, 110, 116, 101,
 114, 110,  97, 108,  65, 108, 108, 111,  99, 115,  18, 115, 101, 116,  83,  97,
 109, 112, 108, 101, 114,  67,  97, 108, 108,  98,  97,  99, 107,  34,  83,  97,
 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58,  95, 115, 101,
 116,  83,  97, 109, 112, 108, 101, 114,  67,  97, 108, 108,  98,  97,  99, 107,
   7, 103, 101, 116,  83, 105, 122, 101,  22,  83,  97, 109, 112, 108, 101, 114,
  83,  99, 114, 105, 112, 116,  58,  58, 103, 101, 116,  83, 105, 122, 101,  14,
 103, 101, 116,  77, 101, 109,  98, 101, 114,  78,  97, 109, 101, 115,  29,  83,
  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 103, 101,
 116,  77, 101, 109,  98, 101, 114,  78,  97, 109, 101, 115,  10, 103, 101, 116,
  83,  97, 109, 112, 108, 101, 115,  25,  83,  97, 109, 112, 108, 101, 114,  83,
  99, 114, 105, 112, 116,  58,  58, 103, 101, 116,  83,  97, 109, 112, 108, 101,
 115,  14, 103, 101, 116,  83,  97, 109, 112, 108, 101,  67, 111, 117, 110, 116,
  29,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58,
 103, 101, 116,  83,  97, 109, 112, 108, 101,  67, 111, 117, 110, 116,  18, 103,
 101, 116,  73, 110, 118, 111,  99,  97, 116, 105, 111, 110,  67, 111, 117, 110,
 116,  24, 103, 101, 116,  83, 101, 116, 116, 101, 114,  73, 110, 118, 111,  99,
  97, 116, 105, 111, 110,  67, 111, 117, 110, 116,  24, 103, 101, 116,  71, 101,
 116, 116, 101, 114,  73, 110, 118, 111,  99,  97, 116, 105, 111, 110,  67, 111,
 117, 110, 116,  34,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112,
 116,  58,  58,  95, 103, 101, 116,  73, 110, 118, 111,  99,  97, 116, 105, 111,
 110,  67, 111, 117, 110, 116,  14, 105, 115,  71, 101, 116, 116, 101, 114,  83,
 101, 116, 116, 101, 114,  29,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114,
 105, 112, 116,  58,  58, 105, 115,  71, 101, 116, 116, 101, 114,  83, 101, 116,
 116, 101, 114,  16, 103, 101, 116,  76, 101, 120, 105,  99,  97, 108,  83,  99,
 111, 112, 101, 115,  31,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105,
 112, 116,  58,  58, 103, 101, 116,  76, 101, 120, 105,  99,  97, 108,  83,  99,
 111, 112, 101, 115,  12, 103, 101, 116,  83,  97, 118, 101, 100,  84, 104, 105,
 115,  27,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,
  58, 103, 101, 116,  83,  97, 118, 101, 100,  84, 104, 105, 115,  15, 103, 101,
 116,  77,  97, 115, 116, 101, 114,  83, 116, 114, 105, 110, 103,  30,  83,  97,
 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 103, 101, 116,
  77,  97, 115, 116, 101, 114,  83, 116, 114, 105, 110, 103,  17, 102, 108,  97,
 115, 104,  46, 116, 114,  97,  99, 101,  58,  84, 114,  97,  99, 101,   3,  79,
  70,  70,   7,  77,  69,  84,  72,  79,  68,  83,  17,  77,  69,  84,  72,  79,
  68,  83,  95,  87,  73,  84,  72,  95,  65,  82,  71,  83,  17,  77,  69,  84,
  72,  79,  68,  83,  95,  65,  78,  68,  95,  76,  73,  78,  69,  83,  27,  77,
  69,  84,  72,  79,  68,  83,  95,  65,  78,  68,  95,  76,  73,  78,  69,  83,
  95,  87,  73,  84,  72,  95,  65,  82,  71,  83,   4,  70,  73,  76,  69,   8,
  76,  73,  83,  84,  69,  78,  69,  82,   8, 115, 101, 116,  76, 101, 118, 101,
 108,   8, 103, 101, 116,  76, 101, 118, 101, 108,  11, 115, 101, 116,  76, 105,
 115, 116, 101, 110, 101, 114,  11, 103, 101, 116,  76, 105, 115, 116, 101, 110,
 101, 114,  11, 102, 108,  97, 115, 104,  46, 116, 114,  97,  99, 101,   5,  84,
 114,  97,  99, 101,  10,  84, 114,  97,  99, 101,  46,  97, 115,  36,  52,  10,
  84, 114,  97,  99, 101,  67, 108,  97, 115, 115,  22, 102, 108,  97, 115, 104,
  46, 117, 116, 105, 108, 115,  58,  68, 105,  99, 116, 105, 111, 110,  97, 114,
 121,  15,  68, 105,  99, 116, 105, 111, 110,  97, 114, 121,  46,  97, 115,  36,
  53,  10,  68, 105,  99, 116, 105, 111, 110,  97, 114, 121,  14, 102, 108,  97,
 115, 104,  46, 117, 116, 105, 108, 115, 238, 138, 148,  15,  68, 105,  99, 116,
 105, 111, 110,  97, 114, 121,  67, 108,  97, 115, 115,  16,  68, 105,  99, 116,
 105, 111, 110,  97, 114, 121,  79,  98, 106, 101,  99, 116,   8,  95,  95, 115,
 121, 115, 116, 101, 109,  11, 115, 116, 100, 108, 105,  98,  46,  97, 115,  36,
  54,   8,  67,  46, 115, 116, 100, 108, 105,  98,   8, 114, 101,  97, 108, 112,
  97, 116, 104,   8, 117, 110, 115, 101, 116, 101, 110, 118,   6, 115, 101, 116,
 101, 110, 118,   6, 103, 101, 116, 101, 110, 118,   5,  97,  98, 111, 114, 116,
  17,  67,  46, 115, 116, 100, 108, 105,  98,  58,  95,  95, 115, 116, 100, 108,
 105,  98,  12,  69,  88,  73,  84,  95,  83,  85,  67,  67,  69,  83,  83,  12,
  69,  88,  73,  84,  95,  70,  65,  73,  76,  85,  82,  69,   8,  95,  95, 115,
 116, 100, 108, 105,  98,  11,  73, 110, 115, 112, 101,  99, 116,  97,  98, 108,
 101,  11, 101, 110, 118, 105, 114, 111, 110, 109, 101, 110, 116,   4, 110, 111,
 110, 101,  23,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  83,
 116, 100, 108, 105,  98,  67, 108,  97, 115, 115,   6, 115, 121, 115, 116, 101,
 109,   8,  95,  95, 117, 110, 105, 115, 116, 100,  11, 117, 110, 105, 115, 116,
 100,  46,  97, 115,  36,  55,   8,  67,  46, 117, 110, 105, 115, 116, 100,   6,
 117, 110, 108, 105, 110, 107,   5, 115, 108, 101, 101, 112,   5, 114, 109, 100,
 105, 114,   5, 109, 107, 100, 105, 114,   8, 103, 101, 116, 108, 111, 103, 105,
 110,  11, 103, 101, 116, 104, 111, 115, 116, 110,  97, 109, 101,   6, 103, 101,
 116,  99, 119, 100,   5,  99, 104, 109, 111, 100,   5,  99, 104, 100, 105, 114,
   6,  97,  99,  99, 101, 115, 115,  17,  67,  46, 117, 110, 105, 115, 116, 100,
  58,  95,  95, 117, 110, 105, 115, 116, 100,   4,  70,  95,  79,  75,   4,  88,
  95,  79,  75,   4,  87,  95,  79,  75,   4,  82,  95,  79,  75,   6,  83,  95,
  73,  70,  77,  84,   7,  83,  95,  73,  70,  73,  70,  79,   7,  83,  95,  73,
  70,  67,  72,  82,   7,  83,  95,  73,  70,  68,  73,  82,   7,  83,  95,  73,
  70,  66,  76,  75,   7,  83,  95,  73,  70,  82,  69,  71,   7,  83,  95,  73,
  70,  76,  78,  75,   8,  83,  95,  73,  70,  83,  79,  67,  75,   7,  83,  95,
  73,  82,  87,  88,  85,   7,  83,  95,  73,  82,  85,  83,  82,   7,  83,  95,
  73,  87,  85,  83,  82,   7,  83,  95,  73,  88,  85,  83,  82,   7,  83,  95,
  73,  82,  87,  88,  71,   7,  83,  95,  73,  82,  71,  82,  80,   7,  83,  95,
  73,  87,  71,  82,  80,   7,  83,  95,  73,  88,  71,  82,  80,   7,  83,  95,
  73,  82,  87,  88,  79,   7,  83,  95,  73,  82,  79,  84,  72,   7,  83,  95,
  73,  87,  79,  84,  72,   7,  83,  95,  73,  88,  79,  84,  72,   7,  83,  95,
  73,  82,  69,  65,  68,   8,  83,  95,  73,  87,  82,  73,  84,  69,   7,  83,
  95,  73,  69,  88,  69,  67,  23,  58,  58,  97, 118, 109, 115, 104, 101, 108,
 108,  58,  58,  85, 110, 105, 115, 116, 100,  67, 108,  97, 115, 115,   1,  45,
   1, 100,   1,  99,   1,  98,   1, 108,   1, 112,   1, 115,   1,  63,  11, 115,
 116, 114, 105, 110, 103,  46,  97, 115,  36,  56,   8,  67,  46, 115, 116, 114,
 105, 110, 103,   1, 114,   1, 119,   1, 120,   4, 106, 111, 105, 110,   4, 109,
 111, 100, 101,   1, 110,   5, 102, 116, 121, 112, 101,   6, 115, 116, 114, 108,
 101, 110,   8, 115, 116, 114, 101, 114, 114, 111, 114,  17,  67,  46, 115, 116,
 114, 105, 110, 103,  58,  95,  95, 115, 116, 114, 105, 110, 103,   8,  95,  95,
 115, 116, 114, 105, 110, 103,  24,  58,  58,  97, 118, 109, 115, 104, 101, 108,
 108,  58,  58,  67,  83, 116, 114, 105, 110, 103,  67, 108,  97, 115, 115,   7,
 115, 116, 114, 109, 111, 100, 101,   7,  95,  95, 101, 114, 114, 110, 111,  10,
 101, 114, 114, 110, 111,  46,  97, 115,  36,  57,  15,  67,  46, 101, 114, 114,
 110, 111,  58,  95,  95, 101, 114, 114, 110, 111,   4,  69,  68,  79,  77,   6,
  69,  73,  76,  83,  69,  81,   6,  69,  82,  65,  78,  71,  69,   5,  69,  80,
  69,  82,  77,   6,  69,  78,  79,  69,  78,  84,   5,  69,  83,  82,  67,  72,
   5,  69,  73,  78,  84,  82,   3,  69,  73,  79,   5,  69,  78,  88,  73,  79,
   5,  69,  50,  66,  73,  71,   7,  69,  78,  79,  69,  88,  69,  67,   5,  69,
  66,  65,  68,  70,   6,  69,  67,  72,  73,  76,  68,   6,  69,  65,  71,  65,
  73,  78,   6,  69,  78,  79,  77,  69,  77,   6,  69,  65,  67,  67,  69,  83,
   6,  69,  70,  65,  85,  76,  84,   5,  69,  66,  85,  83,  89,   6,  69,  69,
  88,  73,  83,  84,   5,  69,  88,  68,  69,  86,   6,  69,  78,  79,  68,  69,
  86,   7,  69,  78,  79,  84,  68,  73,  82,   6,  69,  73,  83,  68,  73,  82,
   6,  69,  73,  78,  86,  65,  76,   6,  69,  78,  70,  73,  76,  69,   6,  69,
  77,  70,  73,  76,  69,   6,  69,  78,  79,  84,  84,  89,   5,  69,  70,  66,
  73,  71,   6,  69,  78,  79,  83,  80,  67,   6,  69,  83,  80,  73,  80,  69,
   5,  69,  82,  79,  70,  83,   6,  69,  77,  76,  73,  78,  75,   5,  69,  80,
  73,  80,  69,   7,  69,  68,  69,  65,  68,  76,  75,  12,  69,  78,  65,  77,
  69,  84,  79,  79,  76,  79,  78,  71,   6,  69,  78,  79,  76,  67,  75,   6,
  69,  78,  79,  83,  89,  83,   9,  69,  78,  79,  84,  69,  77,  80,  84,  89,
   8,  69,  78,  69,  84,  68,  79,  87,  78,  11,  69,  78,  69,  84,  85,  78,
  82,  69,  65,  67,  72,   9,  69,  78,  69,  84,  82,  69,  83,  69,  84,  12,
  69,  67,  79,  78,  78,  65,  66,  79,  82,  84,  69,  68,  10,  69,  67,  79,
  78,  78,  82,  69,  83,  69,  84,   7,  69,  78,  79,  66,  85,  70,  83,   7,
  69,  73,  83,  67,  79,  78,  78,   8,  69,  78,  79,  84,  67,  79,  78,  78,
   9,  69,  83,  72,  85,  84,  68,  79,  87,  78,  12,  69,  84,  79,  79,  77,
  65,  78,  89,  82,  69,  70,  83,   9,  69,  84,  73,  77,  69,  68,  79,  85,
  84,  12,  69,  67,  79,  78,  78,  82,  69,  70,  85,  83,  69,  68,  23,  58,
  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  67,  69, 114, 114, 110,
 111,  67, 108,  97, 115, 115,   6, 114, 101, 110,  97, 109, 101,  11, 115, 116,
 100, 105, 111,  46,  97, 115,  36,  49,  48,   7,  67,  46, 115, 116, 100, 105,
 111,   6, 114, 101, 109, 111, 118, 101,  15,  67,  46, 115, 116, 100, 105, 111,
  58,  95,  95, 115, 116, 100, 105, 111,  12,  70,  73,  76,  69,  78,  65,  77,
  69,  95,  77,  65,  88,   8,  80,  65,  84,  72,  95,  77,  65,  88,   7,  95,
  95, 115, 116, 100, 105, 111,  22,  58,  58,  97, 118, 109, 115, 104, 101, 108,
 108,  58,  58,  83, 116, 100, 105, 111,  67, 108,  97, 115, 115,  15,  95,  95,
 103, 101, 116, 104, 111, 115, 116,  98, 121, 110,  97, 109, 101,  12, 115, 111,
  99, 107, 101, 116,  46,  97, 115,  36,  49,  49,   8,  67,  46, 115, 111,  99,
 107, 101, 116,  15,  95,  95, 103, 101, 116, 104, 111, 115, 116,  98, 121,  97,
 100, 100, 114,  17,  67,  46, 115, 111,  99, 107, 101, 116,  58,  95,  95, 115,
 111,  99, 107, 101, 116,   8,  83,  79,  67,  75,  95,  82,  65,  87,  11,  83,
  79,  67,  75,  95,  83,  84,  82,  69,  65,  77,  10,  83,  79,  67,  75,  95,
  68,  71,  82,  65,  77,  13,  83,  79,  95,  65,  67,  67,  69,  80,  84,  67,
  79,  78,  78,  12,  83,  79,  95,  66,  82,  79,  65,  68,  67,  65,  83,  84,
  12,  83,  79,  95,  68,  79,  78,  84,  82,  79,  85,  84,  69,  12,  83,  79,
  95,  75,  69,  69,  80,  65,  76,  73,  86,  69,  12,  83,  79,  95,  79,  79,
  66,  73,  78,  76,  73,  78,  69,   9,  83,  79,  95,  82,  67,  86,  66,  85,
  70,  11,  83,  79,  95,  82,  67,  86,  84,  73,  77,  69,  79,  12,  83,  79,
  95,  82,  69,  85,  83,  69,  65,  68,  68,  82,   9,  83,  79,  95,  83,  78,
  68,  66,  85,  70,  11,  83,  79,  95,  83,  78,  68,  84,  73,  77,  69,  79,
   7,  83,  79,  95,  84,  89,  80,  69,   9,  83,  79,  77,  65,  88,  67,  79,
  78,  78,  10,  77,  83,  71,  95,  67,  84,  82,  85,  78,  67,  13,  77,  83,
  71,  95,  68,  79,  78,  84,  82,  79,  85,  84,  69,   7,  77,  83,  71,  95,
  79,  79,  66,   8,  77,  83,  71,  95,  80,  69,  69,  75,   9,  77,  83,  71,
  95,  84,  82,  85,  78,  67,  11,  77,  83,  71,  95,  87,  65,  73,  84,  65,
  76,  76,   7,  65,  70,  95,  73,  78,  69,  84,   8,  65,  70,  95,  73,  78,
  69,  84,  54,   9,  65,  70,  95,  85,  78,  83,  80,  69,  67,   7,  83,  72,
  85,  84,  95,  82,  68,   9,  83,  72,  85,  84,  95,  82,  68,  87,  82,   7,
  83,  72,  85,  84,  95,  87,  82,  10,  73,  80,  80,  82,  79,  84,  79,  95,
  73,  80,  12,  73,  80,  80,  82,  79,  84,  79,  95,  73,  80,  86,  54,  12,
  73,  80,  80,  82,  79,  84,  79,  95,  73,  67,  77,  80,  11,  73,  80,  80,
  82,  79,  84,  79,  95,  82,  65,  87,  11,  73,  80,  80,  82,  79,  84,  79,
  95,  84,  67,  80,  11,  73,  80,  80,  82,  79,  84,  79,  95,  85,  68,  80,
  10,  73,  78,  65,  68,  68,  82,  95,  65,  78,  89,  16,  73,  78,  65,  68,
  68,  82,  95,  66,  82,  79,  65,  68,  67,  65,  83,  84,   8,  95,  95, 115,
 111,  99, 107, 101, 116,  24,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,
  58,  58,  67,  83, 111,  99, 107, 101, 116,  67, 108,  97, 115, 115,  13, 103,
 101, 116, 104, 111, 115, 116,  98, 121,  97, 100, 100, 114,  13, 103, 101, 116,
 104, 111, 115, 116,  98, 121, 110,  97, 109, 101,  18, 102, 108,  97, 115, 104,
  46, 117, 116, 105, 108, 115,  58,  69, 110, 100, 105,  97, 110,  10,  66,  73,
  71,  95,  69,  78,  68,  73,  65,  78,   9,  98, 105, 103,  69, 110, 100, 105,
  97, 110,  13,  76,  73,  84,  84,  76,  69,  95,  69,  78,  68,  73,  65,  78,
  12, 108, 105, 116, 116, 108, 101,  69, 110, 100, 105,  97, 110,   6,  69, 110,
 100, 105,  97, 110,  12,  69, 110, 100, 105,  97, 110,  46,  97, 115,  36,  49,
  50,  15,  97, 118, 109, 112, 108, 117, 115,  58,  74,  79,  98, 106, 101,  99,
 116,   7,  74,  79,  98, 106, 101,  99, 116,   6,  99, 114, 101,  97, 116, 101,
  11,  99, 114, 101,  97, 116, 101,  65, 114, 114,  97, 121,   7, 116, 111,  65,
 114, 114,  97, 121,  20,  99, 111, 110, 115, 116, 114, 117,  99, 116, 111, 114,
  83, 105, 103, 110,  97, 116, 117, 114, 101,  15, 109, 101, 116, 104, 111, 100,
  83, 105, 103, 110,  97, 116, 117, 114, 101,  14, 102, 105, 101, 108, 100,  83,
 105, 103, 110,  97, 116, 117, 114, 101,  10,  74,  97, 118,  97,  46,  97, 115,
  36,  49,  51,  12,  74,  79,  98, 106, 101,  99, 116,  67, 108,  97, 115, 115,
  85,   5,   2,  22,   3,  23,   3,  22,   4,  22,   5,  23,   4,   5,  16,  24,
  16,  26,  16,  26,  19,  22,  26,   5,  42,  22,  43,  24,  42,   5,  50,  22,
  52,  23,  52,  24,  50,  26,  50,  22,  56,  22,  65,   5,  68,   5,  70,  24,
  68,  26,  68,   5,  82,  22,  83,  23,  83,   5,  89,  24,  89,  26,  89,   5,
 100,  24, 100,   5, 104,  24, 104,   5, 110,  24, 110,  22, 112,   5, 155,   1,
  22, 167,   1,  24, 155,   1,   5, 169,   1,  23, 167,   1,   5, 171,   1,   5,
 172,   1,  23,  43,  24, 171,   1,  26, 171,   1,  22, 174,   1,   5, 178,   1,
  22, 179,   1,  23, 179,   1,   5, 185,   1,  24, 185,   1,   5, 195,   1,  22,
 196,   1,  23, 196,   1,   5, 207,   1,  24, 207,   1,   5, 244,   1,  22, 245,
   1,  23, 245,   1,   5, 255,   1,  24, 255,   1,   5, 132,   2,  23,   5,   5,
 133,   2,  24, 133,   2,   5, 186,   2,  22, 187,   2,  23, 187,   2,   5, 189,
   2,  24, 189,   2,   5, 195,   2,  22, 196,   2,  23, 196,   2,   5, 198,   2,
  24, 198,   2,   5, 238,   2,  24, 238,   2,   5, 244,   2,   5, 245,   2,  24,
 245,   2,   5, 253,   2,  45,   5,   1,   2,   3,   4,   5,   4,   1,   2,   4,
   6,   8,   1,   2,   4,   6,   7,   8,   9,  10,   1,  11,   1,   7,   9,   1,
   2,   4,  10,  15,  16,  17,  18,  19,   1,   4,   1,  16,   5,   1,   2,   4,
  16,  17,   1,  20,   1,  21,   8,   2,   4,   6,  10,  22,  23,  24,  25,   1,
  22,   4,   2,   4,   6,  23,   4,   2,  26,  27,  28,   1,  28,   8,   2,  10,
  26,  27,  28,  29,  30,  31,   1,  38,   4,   2,  40,  42,  43,   1,  40,   8,
   2,  10,  13,  44,  45,  46,  47,  48,   1,  44,   4,   2,  13,  45,  46,   1,
  49,   4,   2,  50,  51,  52,   1,  52,   1,  51,   4,   2,  55,  56,  57,   1,
  57,   1,  56,   5,   2,  56,  60,  61,  62,   1,  62,   1,  61,   4,   2,   5,
  65,  66,   1,  66,   1,   5,   4,   2,  69,  70,  71,   1,  71,   1,  70,   4,
   2,  74,  75,  76,   1,  76,   1,  75,   4,   2,  13,  46,  81,   4,   2,   4,
   6,  84, 240,   5,   9,   1,   1,   9,   6,   1,   7,   2,   7,   9,   8,   1,
   7,   2,   9,   9,  10,   1,   9,  11,   1,   9,  12,   1,   9,  13,   1,   7,
   2,  14,   9,   1,   2,   9,  15,   2,   7,   2,  17,   9,  18,   3,   7,   2,
  20,   7,   2,  21,   7,   2,  22,   7,   2,  23,   7,   2,  24,   7,   2,  25,
   9,  27,   4,   9,  28,   4,   9,  29,   4,   9,  30,   4,   9,  31,   4,   9,
  10,   4,   9,  32,   4,   9,  15,   4,   9,  33,   4,   9,   8,   4,   9,  18,
   5,   9,  17,   4,   9,   6,   4,   9,  34,   4,   9,  35,   4,   9,  36,   4,
   9,  37,   4,   9,  38,   4,   9,  39,   4,   9,  40,   4,   9,  41,   4,   7,
   4,   1,   7,   2,  19,   7,  13,  44,   9,  45,   4,   9,  46,   4,   9,  47,
   4,   9,  48,   4,   7,   4,  49,   9,   1,   6,   9,  33,   6,   9,  53,   4,
   7,  16,  54,   9,   1,   7,   9,  19,   2,   9,  49,   7,   9,  54,   8,   9,
  19,   9,   9,  55,   1,   9,   1,  10,   9,  49,  10,   9,  15,  10,   9,  54,
  11,   9,  66,   4,   9,  67,   4,   7,   4,  11,   9,  69,  12,   9,  49,  12,
   9,  47,  12,   9,  71,  12,   9,  12,   4,   9,  72,   4,   9,  69,  13,   9,
  71,   4,   9,  13,   4,   9,  73,   4,   9,  74,   4,   9,  11,   7,   9,  19,
  14,   9,  11,  10,   7,   2,  79,   7,   2,  80,   9,  81,  15,   9,  84,  15,
   7,   2,  85,   9,  86,  16,   9,  87,  15,   9,  84,  16,   9,  88,  16,   9,
  90,  17,   9,  92,  17,   9,  95,  17,   9,  90,   4,   9,  92,   4,   9,  95,
   4,   9,  97,   4,   9,  98,   4,   7,  27,  99,   9, 101,   4,   9, 102,   4,
   7,  27, 103,   9, 105,   4,   9, 106,   4,   9, 107,   4,   9, 108,   4,   7,
  27, 109,   7,  27, 111,   9,  19,  15,   9,  99,  18,   9, 103,  18,   9, 109,
  18,   9, 111,  18,   9, 123,  18,   9, 125,  18,   9, 127,  18,   9, 129,   1,
  18,   9, 131,   1,  18,   9, 133,   1,  18,   9,  87,  16,   9, 135,   1,  18,
   9, 137,   1,  18,   9, 139,   1,  18,   9, 141,   1,  18,   9, 143,   1,  18,
   9, 144,   1,  18,   9, 145,   1,  18,   9,  81,  16,   9, 147,   1,  18,   9,
 149,   1,  18,   9, 151,   1,  18,   9, 153,   1,  18,   7,   2, 156,   1,   7,
   2, 157,   1,   7,   2, 158,   1,   7,   2, 159,   1,   7,   2, 160,   1,   7,
   2, 161,   1,   7,   2, 162,   1,   9, 156,   1,   4,   9, 157,   1,   4,   9,
 158,   1,   4,   9, 159,   1,   4,   9, 160,   1,   4,   9, 161,   1,   4,   9,
 162,   1,   4,   9, 163,   1,   4,   9, 164,   1,   4,   9, 165,   1,   4,   9,
 166,   1,   4,   7,  40, 168,   1,   9,  19,  19,   9, 168,   1,  20,   9,  69,
  21,   9,  69,  22,   7,  13, 173,   1,   9,  19,  23,   9, 173,   1,  24,   9,
 177,   1,  25,   9, 180,   1,  25,   9, 181,   1,  25,   9, 182,   1,  25,   9,
 183,   1,  25,   9,  27,  25,   9, 184,   1,  25,   9, 186,   1,   4,   9, 187,
   1,   4,   9, 184,   1,   4,   9, 183,   1,   4,   9, 182,   1,   4,   9, 181,
   1,   4,   9, 180,   1,   4,   9, 177,   1,   4,   7,  52, 188,   1,   9,  19,
  25,   9, 186,   1,  25,   7,  51, 186,   1,   9, 187,   1,  25,   7,  51, 187,
   1,   9, 188,   1,  26,   9, 186,   1,  27,   9, 187,   1,  27,   9, 184,   1,
  27,   9,  27,  27,   9, 183,   1,  27,   9, 182,   1,  27,   9, 181,   1,  27,
   9, 180,   1,  27,   9, 193,   1,  27,   9, 194,   1,  28,   9, 197,   1,  28,
   9, 198,   1,  28,   9, 199,   1,  28,   9, 200,   1,  28,   9, 201,   1,  28,
   9, 202,   1,  28,   9, 203,   1,  28,   9, 204,   1,  28,   9, 205,   1,  28,
   9, 206,   1,  28,   9, 208,   1,   4,   9, 209,   1,   4,   9, 210,   1,   4,
   9, 211,   1,   4,   9, 212,   1,   4,   9, 213,   1,   4,   9, 214,   1,   4,
   9, 215,   1,   4,   9, 216,   1,   4,   9, 217,   1,   4,   9, 218,   1,   4,
   9, 219,   1,   4,   9, 220,   1,   4,   9, 221,   1,   4,   9, 222,   1,   4,
   9, 223,   1,   4,   9, 224,   1,   4,   9, 225,   1,   4,   9, 226,   1,   4,
   9, 227,   1,   4,   9, 228,   1,   4,   9, 229,   1,   4,   9, 230,   1,   4,
   9, 231,   1,   4,   9, 232,   1,   4,   9, 233,   1,   4,   9, 234,   1,   4,
   9, 206,   1,   4,   9, 205,   1,   4,   9, 204,   1,   4,   9, 203,   1,   4,
   9, 202,   1,   4,   9, 201,   1,   4,   9, 200,   1,   4,   9, 199,   1,   4,
   9, 198,   1,   4,   9, 197,   1,   4,   7,  57, 194,   1,   9, 194,   1,  29,
   9,  19,  28,   9, 208,   1,  30,   9, 208,   1,  28,   7,  56, 208,   1,   9,
 209,   1,  30,   9, 209,   1,  28,   7,  56, 209,   1,   9, 210,   1,  30,   9,
 210,   1,  28,   7,  56, 210,   1,   9, 211,   1,  30,   9, 211,   1,  28,   7,
  56, 211,   1,   9, 212,   1,  30,   9, 212,   1,  28,   7,  56, 212,   1,   9,
 213,   1,  30,   9, 213,   1,  28,   7,  56, 213,   1,   9, 214,   1,  30,   9,
 214,   1,  28,   7,  56, 214,   1,   9, 215,   1,  30,   9, 215,   1,  28,   7,
  56, 215,   1,   9, 216,   1,  30,   9, 216,   1,  28,   7,  56, 216,   1,   9,
 217,   1,  30,   9, 217,   1,  28,   7,  56, 217,   1,   9, 218,   1,  30,   9,
 218,   1,  28,   7,  56, 218,   1,   9, 219,   1,  30,   9, 219,   1,  28,   7,
  56, 219,   1,   9, 220,   1,  30,   9, 220,   1,  28,   7,  56, 220,   1,   9,
 221,   1,  30,   9, 221,   1,  28,   7,  56, 221,   1,   9, 222,   1,  30,   9,
 222,   1,  28,   7,  56, 222,   1,   9, 223,   1,  30,   9, 223,   1,  28,   7,
  56, 223,   1,   9, 224,   1,  30,   9, 224,   1,  28,   7,  56, 224,   1,   9,
 225,   1,  30,   9, 225,   1,  28,   7,  56, 225,   1,   9, 226,   1,  30,   9,
 226,   1,  28,   7,  56, 226,   1,   9, 227,   1,  30,   9, 227,   1,  28,   7,
  56, 227,   1,   9, 228,   1,  30,   9, 228,   1,  28,   7,  56, 228,   1,   9,
 229,   1,  30,   9, 229,   1,  28,   7,  56, 229,   1,   9, 230,   1,  30,   9,
 230,   1,  28,   7,  56, 230,   1,   9, 231,   1,  30,   9, 231,   1,  28,   7,
  56, 231,   1,   9, 232,   1,  30,   9, 232,   1,  28,   7,  56, 232,   1,   9,
 233,   1,  30,   9, 233,   1,  28,   7,  56, 233,   1,   9, 234,   1,  30,   7,
  56, 234,   1,   9, 206,   1,  30,   9, 205,   1,  30,   9, 204,   1,  30,   9,
 203,   1,  30,   9, 202,   1,  30,   9, 201,   1,  30,   9, 200,   1,  30,   9,
 199,   1,  30,   9, 198,   1,  30,   9, 197,   1,  30,   9, 212,   1,  31,   9,
 217,   1,  31,   9, 215,   1,  31,   9, 214,   1,  31,   9, 216,   1,  31,   9,
 218,   1,  31,   9, 213,   1,  31,   9, 219,   1,  31,   9,  22,  31,  27,  31,
   9, 221,   1,  31,   9, 222,   1,  31,   9, 223,   1,  31,   9, 225,   1,  31,
   9, 226,   1,  31,   9, 227,   1,  31,   9, 229,   1,  31,   9, 230,   1,  31,
   9, 231,   1,  31,   9, 249,   1,  31,   9, 250,   1,  32,   9, 251,   1,  32,
   9, 252,   1,  32,   9, 253,   1,  31,   9, 254,   1,  31,   9, 254,   1,   4,
   9, 253,   1,   4,   7,  62, 128,   2,   9,  19,  31,   9, 128,   2,  32,   9,
 254,   1,  33,   9, 253,   1,  33,   9, 130,   2,  33,   9, 131,   2,  34,   9,
  55,  34,   9, 134,   2,   4,   9, 135,   2,   4,   9, 136,   2,   4,   9, 137,
   2,   4,   9, 138,   2,   4,   9, 139,   2,   4,   9, 140,   2,   4,   9, 141,
   2,   4,   9, 142,   2,   4,   9, 143,   2,   4,   9, 144,   2,   4,   9, 145,
   2,   4,   9, 146,   2,   4,   9, 147,   2,   4,   9, 148,   2,   4,   9, 149,
   2,   4,   9, 150,   2,   4,   9, 151,   2,   4,   9, 152,   2,   4,   9, 153,
   2,   4,   9, 154,   2,   4,   9, 155,   2,   4,   9, 156,   2,   4,   9, 157,
   2,   4,   9, 158,   2,   4,   9, 159,   2,   4,   9, 160,   2,   4,   9, 161,
   2,   4,   9, 162,   2,   4,   9, 163,   2,   4,   9, 164,   2,   4,   9, 165,
   2,   4,   9, 166,   2,   4,   9, 167,   2,   4,   9, 168,   2,   4,   9, 169,
   2,   4,   9, 170,   2,   4,   9, 171,   2,   4,   9, 172,   2,   4,   9, 173,
   2,   4,   9, 174,   2,   4,   9, 175,   2,   4,   9, 176,   2,   4,   9, 177,
   2,   4,   9, 178,   2,   4,   9, 179,   2,   4,   9, 180,   2,   4,   9, 181,
   2,   4,   9, 182,   2,   4,   9, 183,   2,   4,   9,  55,   4,   7,  66, 131,
   2,   9, 131,   2,  35,   9,  19,  34,   9, 134,   2,  36,   9, 134,   2,  34,
   7,   5, 134,   2,   9, 135,   2,  36,   9, 135,   2,  34,   7,   5, 135,   2,
   9, 136,   2,  36,   9, 136,   2,  34,   7,   5, 136,   2,   9, 137,   2,  36,
   9, 137,   2,  34,   7,   5, 137,   2,   9, 138,   2,  36,   9, 138,   2,  34,
   7,   5, 138,   2,   9, 139,   2,  36,   9, 139,   2,  34,   7,   5, 139,   2,
   9, 140,   2,  36,   9, 140,   2,  34,   7,   5, 140,   2,   9, 141,   2,  36,
   9, 141,   2,  34,   7,   5, 141,   2,   9, 142,   2,  36,   9, 142,   2,  34,
   7,   5, 142,   2,   9, 143,   2,  36,   9, 143,   2,  34,   7,   5, 143,   2,
   9, 144,   2,  36,   9, 144,   2,  34,   7,   5, 144,   2,   9, 145,   2,  36,
   9, 145,   2,  34,   7,   5, 145,   2,   9, 146,   2,  36,   9, 146,   2,  34,
   7,   5, 146,   2,   9, 147,   2,  36,   9, 147,   2,  34,   7,   5, 147,   2,
   9, 148,   2,  36,   9, 148,   2,  34,   7,   5, 148,   2,   9, 149,   2,  36,
   9, 149,   2,  34,   7,   5, 149,   2,   9, 150,   2,  36,   9, 150,   2,  34,
   7,   5, 150,   2,   9, 151,   2,  36,   9, 151,   2,  34,   7,   5, 151,   2,
   9, 152,   2,  36,   9, 152,   2,  34,   7,   5, 152,   2,   9, 153,   2,  36,
   9, 153,   2,  34,   7,   5, 153,   2,   9, 154,   2,  36,   9, 154,   2,  34,
   7,   5, 154,   2,   9, 155,   2,  36,   9, 155,   2,  34,   7,   5, 155,   2,
   9, 156,   2,  36,   9, 156,   2,  34,   7,   5, 156,   2,   9, 157,   2,  36,
   9, 157,   2,  34,   7,   5, 157,   2,   9, 158,   2,  36,   9, 158,   2,  34,
   7,   5, 158,   2,   9, 159,   2,  36,   9, 159,   2,  34,   7,   5, 159,   2,
   9, 160,   2,  36,   9, 160,   2,  34,   7,   5, 160,   2,   9, 161,   2,  36,
   9, 161,   2,  34,   7,   5, 161,   2,   9, 162,   2,  36,   9, 162,   2,  34,
   7,   5, 162,   2,   9, 163,   2,  36,   9, 163,   2,  34,   7,   5, 163,   2,
   9, 164,   2,  36,   9, 164,   2,  34,   7,   5, 164,   2,   9, 165,   2,  36,
   9, 165,   2,  34,   7,   5, 165,   2,   9, 166,   2,  36,   9, 166,   2,  34,
   7,   5, 166,   2,   9, 167,   2,  36,   9, 167,   2,  34,   7,   5, 167,   2,
   9, 168,   2,  36,   9, 168,   2,  34,   7,   5, 168,   2,   9, 169,   2,  36,
   9, 169,   2,  34,   7,   5, 169,   2,   9, 170,   2,  36,   9, 170,   2,  34,
   7,   5, 170,   2,   9, 171,   2,  36,   9, 171,   2,  34,   7,   5, 171,   2,
   9, 172,   2,  36,   9, 172,   2,  34,   7,   5, 172,   2,   9, 173,   2,  36,
   9, 173,   2,  34,   7,   5, 173,   2,   9, 174,   2,  36,   9, 174,   2,  34,
   7,   5, 174,   2,   9, 175,   2,  36,   9, 175,   2,  34,   7,   5, 175,   2,
   9, 176,   2,  36,   9, 176,   2,  34,   7,   5, 176,   2,   9, 177,   2,  36,
   9, 177,   2,  34,   7,   5, 177,   2,   9, 178,   2,  36,   9, 178,   2,  34,
   7,   5, 178,   2,   9, 179,   2,  36,   9, 179,   2,  34,   7,   5, 179,   2,
   9, 180,   2,  36,   9, 180,   2,  34,   7,   5, 180,   2,   9, 181,   2,  36,
   9, 181,   2,  34,   7,   5, 181,   2,   9, 182,   2,  36,   9, 182,   2,  34,
   7,   5, 182,   2,   9, 183,   2,  36,   9, 183,   2,  34,   7,   5, 183,   2,
   9,  55,  36,   9, 185,   2,  37,   9, 188,   2,  37,   9, 190,   2,   4,   9,
 191,   2,   4,   9, 188,   2,   4,   9, 185,   2,   4,   7,  71, 192,   2,   9,
  19,  37,   9, 190,   2,  37,   7,  70, 190,   2,   9, 191,   2,  37,   7,  70,
 191,   2,   9, 192,   2,  38,   9, 190,   2,  39,   9, 191,   2,  39,   9, 188,
   2,  39,   9, 185,   2,  39,   9, 194,   2,  40,   9, 197,   2,  40,   9, 199,
   2,   4,   9, 200,   2,   4,   9, 201,   2,   4,   9, 202,   2,   4,   9, 203,
   2,   4,   9, 204,   2,   4,   9, 205,   2,   4,   9, 206,   2,   4,   9, 207,
   2,   4,   9, 208,   2,   4,   9, 209,   2,   4,   9, 210,   2,   4,   9, 211,
   2,   4,   9, 212,   2,   4,   9, 213,   2,   4,   9, 214,   2,   4,   9, 215,
   2,   4,   9, 216,   2,   4,   9, 217,   2,   4,   9, 218,   2,   4,   9, 219,
   2,   4,   9, 220,   2,   4,   9, 221,   2,   4,   9, 222,   2,   4,   9, 223,
   2,   4,   9, 224,   2,   4,   9, 225,   2,   4,   9, 226,   2,   4,   9, 227,
   2,   4,   9, 228,   2,   4,   9, 229,   2,   4,   9, 230,   2,   4,   9, 231,
   2,   4,   9, 232,   2,   4,   9, 233,   2,   4,   9, 197,   2,   4,   9, 194,
   2,   4,   7,  76, 234,   2,   9,  19,  40,   9, 199,   2,  40,   7,  75, 199,
   2,   9, 200,   2,  40,   7,  75, 200,   2,   9, 201,   2,  40,   7,  75, 201,
   2,   9, 202,   2,  40,   7,  75, 202,   2,   9, 203,   2,  40,   7,  75, 203,
   2,   9, 204,   2,  40,   7,  75, 204,   2,   9, 205,   2,  40,   7,  75, 205,
   2,   9, 206,   2,  40,   7,  75, 206,   2,   9, 207,   2,  40,   7,  75, 207,
   2,   9, 208,   2,  40,   7,  75, 208,   2,   9, 209,   2,  40,   7,  75, 209,
   2,   9, 210,   2,  40,   7,  75, 210,   2,   9, 211,   2,  40,   7,  75, 211,
   2,   9, 212,   2,  40,   7,  75, 212,   2,   9, 213,   2,  40,   7,  75, 213,
   2,   9, 214,   2,  40,   7,  75, 214,   2,   9, 215,   2,  40,   7,  75, 215,
   2,   9, 216,   2,  40,   7,  75, 216,   2,   9, 217,   2,  40,   7,  75, 217,
   2,   9, 218,   2,  40,   7,  75, 218,   2,   9, 219,   2,  40,   7,  75, 219,
   2,   9, 220,   2,  40,   7,  75, 220,   2,   9, 221,   2,  40,   7,  75, 221,
   2,   9, 222,   2,  40,   7,  75, 222,   2,   9, 223,   2,  40,   7,  75, 223,
   2,   9, 224,   2,  40,   7,  75, 224,   2,   9, 225,   2,  40,   7,  75, 225,
   2,   9, 226,   2,  40,   7,  75, 226,   2,   9, 227,   2,  40,   7,  75, 227,
   2,   9, 228,   2,  40,   7,  75, 228,   2,   9, 229,   2,  40,   7,  75, 229,
   2,   9, 230,   2,  40,   7,  75, 230,   2,   9, 231,   2,  40,   7,  75, 231,
   2,   9, 232,   2,  40,   7,  75, 232,   2,   9, 233,   2,  40,   7,  75, 233,
   2,   9, 234,   2,  41,   9, 199,   2,  42,   9, 200,   2,  42,   9, 201,   2,
  42,   9, 202,   2,  42,   9, 203,   2,  42,   9, 204,   2,  42,   9, 205,   2,
  42,   9, 206,   2,  42,   9, 207,   2,  42,   9, 208,   2,  42,   9, 209,   2,
  42,   9, 210,   2,  42,   9, 211,   2,  42,   9, 212,   2,  42,   9, 213,   2,
  42,   9, 214,   2,  42,   9, 215,   2,  42,   9, 216,   2,  42,   9, 217,   2,
  42,   9, 218,   2,  42,   9, 219,   2,  42,   9, 220,   2,  42,   9, 221,   2,
  42,   9, 222,   2,  42,   9, 223,   2,  42,   9, 224,   2,  42,   9, 225,   2,
  42,   9, 226,   2,  42,   9, 227,   2,  42,   9, 228,   2,  42,   9, 229,   2,
  42,   9, 230,   2,  42,   9, 231,   2,  42,   9, 232,   2,  42,   9, 233,   2,
  42,   9, 236,   2,  42,   9, 237,   2,  42,   7,   2, 239,   2,   7,   2, 241,
   2,   9, 239,   2,   4,   9, 241,   2,   4,   7,  13, 243,   2,   9,  19,  43,
   9, 243,   2,  24,   7,   4, 246,   2,   9, 247,   2,   4,   9, 248,   2,   4,
   9, 249,   2,   4,   9, 250,   2,   4,   9, 251,   2,   4,   9, 252,   2,   4,
   9,  19,  44,   9, 246,   2,  10, 164,   2,   0,   3,   3,   0,   0,   5,   3,
   0,   0,   0,   3,   4,   0,   0,   3,   4,   1,  10,   3,   3,   0,   0,   0,
   3,   0,   0,   0,   3,   0,   1,  15,  16,   3,  32,   1,  16,   3,   3,  32,
   0,   3,   3,  32,   0,   3,   3,  32,   0,   3,   3,  32,   1,  15,  17,   3,
  32,   1,  15,   3,   3,  32,   0,  15,   3,  32,   0,  18,   3,  32,   0,   5,
   3,  32,   0,  17,   3,  32,   0,   3,   3,  32,   0,  19,   3,  32,   0,  19,
   3,  32,   0,  19,   3,  32,   0,  15,   3,  32,   0,  15,   3,  32,   0,  16,
   3,  32,   0,  16,   3,  32,   1,  15,  20,   3,  32,   0,   0,   3,   0,   0,
   0,   3,   0,   1,  18,   3,   3,  32,   1,   3,   3,   3,  32,   2,  15,   3,
   3,   3,  32,   1,  44,   3,   3,  32,   2,  18,   3,  44,   3,  32,   0,   0,
   3,   0,   0,   0,   3,   0,   0,   3,   3,   0,   0,  18,   3,   0,   0,   0,
   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   0,  66,   3,  32,   0,   5,
   3,  32,   1,  15,  66,   3,  32,   1,   0,  66,   3,   0,   2,   0,  44,   5,
   3,  40,   1,   1,   3,   1,  10,   3,   3,  32,   2,   0,   3,   5,   3,   8,
   1,   1,   3,   0,  44,   3,  32,   1,   0,  44,   3,  32,   0,   0,   3,   0,
   1,   3,   3,   3,  32,   1,  43,  81,   3,  32,   1,  17,  81,   3,  32,   2,
  18,  43,  82,   3,  32,   3,  19,  43,  82,   5,   3,  32,   2,  19,  43,  82,
   3,   0,   2,  19,  43,  82,   3,   0,   2,  19,  43,  82,   3,   0,   0,  19,
   3,  32,   0,  43,   3,  32,   2,  43,  43,  18,   3,  40,   1,  10,  10,   1,
  19,   0,   3,  32,   1,  15,  81,   3,  32,   0,   0,   3,   2,   1,  15,  81,
   3,   2,   1,  15,  18,   3,  32,   0,  15,   3,  32,   0,  15,   3,  32,   0,
  15,   3,  32,   0,  15,   3,  32,   0,   0,   3,   0,   0,   3,   3,   0,   0,
   0,   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   0,
   0,   3,  32,   0,  19,   3,  32,   0,   0,   3,   0,   0,   0,   3,   0,   0,
   0,   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   2,   0,  16,  16,   3,
  40,   1,   2,   3,   1,  16,  16,   3,  40,   1,   2,   3,   1,   0,  81,   3,
  32,   0,  81,   3,  32,   0,   0,   3,   0,   0,   0,   3,   0,   0,   0,   3,
   0,   1,  15,  18,   3,  32,   1,   0,  18,   3,   8,   1,  10,  10,   0,   0,
   3,   0,   1,  16,   3,   3,   0,   1,   3,   3,   3,   0,   1,  16,   3,   3,
   0,   3,  16,   3,   3,  18,   3,   8,   1,  10,  10,   1,   3,   3,   3,   0,
   1,  15,  16,   3,   8,   1,   6,   3,   0,  15,   3,   0,   0,   0,   3,   0,
   0,  16,   3,  32,   0,  16,   3,  32,   0,  15,   3,  32,   1,  15,  16,   3,
  40,   1,   1,   3,   1,   3,   3,   3,  32,   3,  16,   3,   3,  16,   3,  32,
   1,  16,   3,   3,  32,   1,   3,   3,   3,  32,   1,  16,   3,   3,  32,   0,
   0,   3,   0,   0,   0,   3,   0,   1,  16,   3,   3,   0,   1,  15,   5,   3,
   0,   1,  16,   3,   3,   0,   1,  16,   3,   3,   0,   0,   3,   3,   0,   0,
   3,   3,   0,   0,   3,   3,   0,   2,  16,   3,  16,   3,   0,   1,  16,   3,
   3,   0,   2,  16,   3,  16,   3,   0,   0,   0,   3,   0,   0,  16,   3,  32,
   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,
   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,
   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,
   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,
   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,
   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,
   0,  16,   3,  32,   0,  16,   3,  32,   2,  16,   3,  16,   3,  32,   1,  16,
   3,   3,  32,   2,  16,   3,  16,   3,  32,   0,   3,   3,  32,   0,   3,   3,
  32,   0,   3,   3,  32,   1,  16,   3,   3,  32,   1,  16,   3,   3,  32,   1,
  15,   5,   3,  32,   1,  16,   3,   3,  32,   0,   0,   3,   0,   0,   0,   3,
   0,   1,   3,  16,   3,   0,   1,   3,  16,   3,   2,   1,   5,   3,   3,   0,
   1,   3,  16,   3,   0,   0,   0,   3,   0,   1,   3,  16,   3,  32,   1,   5,
   3,   3,  32,   0,   0,   3,   0,   0,   0,   3,   0,   1,  15,  16,   3,   0,
   0,  16,   3,   0,   0,   0,   3,   0,   0,  16,   3,  32,   0,  16,   3,  32,
   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,
   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,
   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,
   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,
   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,
   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,
   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,
   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,
   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,
   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,
   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,
   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,
   0,  16,   3,  32,   1,  15,  16,   3,  32,   0,   0,   3,   0,   0,   0,   3,
   0,   2,  16,   3,   3,   3,   0,   1,  16,   3,   3,   0,   0,   0,   3,   0,
   0,  16,   3,  32,   0,  16,   3,  32,   1,  16,   3,   3,  32,   2,  16,   3,
   3,   3,  32,   0,   0,   3,   0,   0,   0,   3,   0,   2,  17,   3,  18,   3,
   8,   1,  10,  10,   2,  17,   3,  18,   3,   8,   1,  10,  10,   0,   0,   3,
   0,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,
  32,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,
  32,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,
  32,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,
  32,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,
  32,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,
  32,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,
  32,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,
  32,   0,  16,   3,  32,   0,  16,   3,  32,   0,  16,   3,  32,   2,  17,   3,
  18,   3,  32,   2,  17,   3,  18,   3,  32,   0,   0,   3,   0,   0,   0,   3,
   0,   0,   0,   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   0,   0,   3,
   0,   1, 231,   5,   3,   3,  36,   3, 231,   5, 231,   5,  16,  17,   3,  40,
   1,  12,  12,   1,  17, 231,   5,   3,  32,   1,   3,   3,   3,  36,   2,   3,
 231,   5,   3,   3,  36,   2,   3, 231,   5,   3,   3,  32,   0,   0,   3,   0,
   0,   0,   3,   0,  32,  57,   3,  58,  60,  62,  59,  61,  63,  57,   2,  58,
  62,  64,  63,  57,   4,  58,  76,  77,  62,  75,  61,  78,  63,  57,   4,  58,
  77,  62, 115, 113, 114,  63, 116,  57,   4,  58,  77,  62, 115, 117, 118,  63,
 116,  57,   4,  58,  77,  62, 115, 119, 120,  63, 116,  57,   4,  58,  77,  62,
 115, 121, 122,  63, 116,  57,   1,   0, 124,  57,   1,   0, 126,  57,   1,   0,
 128,   1,  57,   1,   0, 130,   1,  57,   1,   0, 132,   1,  57,   1,   0, 134,
   1,  57,   1,   0, 136,   1,  57,   1,   0, 138,   1,  57,   1,   0, 140,   1,
  57,   1,   0, 142,   1,  57,   1,   0, 146,   1,  57,   1,   0, 148,   1,  57,
   1,   0, 150,   1,  57,   1,   0, 152,   1,  57,   1,   0, 154,   1,  57,   2,
  58,  62, 170,   1,  63,  57,   4,  58,  76,  77,  62, 175,   1,  61, 176,   1,
  63, 189,   1,   1, 190,   1, 191,   1,  57,   2,  58,  62, 192,   1,  63,  57,
   2,  58,  62, 235,   1,  63,  57,   2,  58,  62, 129,   2,  63,  57,   2,  58,
  62, 184,   2,  63,  57,   2,  58,  62, 193,   2,  63,  57,   2,  58,  62, 235,
   2,  63,  57,   3,  58,  77,  62, 254,   2, 246,   2,  63,  18,  42,  43,   9,
   8,   0,  27,   0,  49,  43,   9,  14,   0,  34,   0,  53,  43,  11,  18,   0,
  38,   0,  66,  43,   9,  24,   0,  44,   6,  73,   1,   0,  43,  74,   1,   0,
  45,  75,   1,   0,  46,  76,   1,   0,  47,  77,   2,   0,  48,  77,   3,   0,
  49,  98,  43,  11,  30,   0,  73,   5,  93,   6,   0,   3,   0,  94,   6,   0,
   3,   0,  95,   6,   0,   5,   0,  96,   6,   0,  19,   0,  97,   1,   0,  72,
 101,  43,   9,  33,   0,  75,   2,  99,   6,   0,  19,   0, 100,   6,   0,  17,
   0, 106, 101,  11,  35,   0,  79,   4, 102,   6,   0,  19,   0, 103,   6,   0,
  10,   0, 104,   2,   0,  77, 105,   2,   0,  78, 107, 101,  11,  37,   0,  81,
   2, 102,   6,   0,  19,   0, 105,   6,   0,  19,   0, 150,   1,  43,   9,  41,
   0,  88,   0, 155,   1,  43,   8,  47,   0,  92,   1, 154,   1,   1,   0,  91,
 173,   1,  43,   9,  54,   0, 111,   0, 237,   1,  43,   9,  59,   0, 161,   1,
   0, 229,   2,  43,   9,  64,   0, 170,   1,   0, 160,   3,  43,   9,  68,   0,
 227,   1,   0, 192,   4,  43,   9,  73,   0, 236,   1,   0, 242,   4,  43,   9,
  78,   0, 150,   2,   0, 228,   5,  43,   9,  80,   0, 153,   2,   0, 231,   5,
  43,   9,  83,   0, 162,   2,   0,   6,  21,  21,  17,   3,   7,  22,  17,   4,
   8,  23,  17,   5,   9,  24,  17,   6,  10,  25,  17,   7,  11,  26,  17,   8,
  12,  27,  17,   9,  13,  28,  17,  10,  14,  29,  17,  11,  15,  30,  17,  12,
  16,  31,  17,  13,  17,  32,   6,   1,  17,   0,  33,  17,  14,  18,  34,  18,
  15,  19,  35,  18,  16,  20,  36,  18,  17,  21,  37,  17,  18,  22,  38,  17,
  19,  23,  39,  18,  20,  24,  40,  18,  21,  25,  41,  17,  22,  26,  28,   5,
  45,  17,   3,  29,  46,  17,   4,  30,  27,  17,   5,  31,  47,  17,   6,  32,
  48,  17,   7,  33,  35,   2,  52,  18,   3,  36,  29,  18,   4,  37,  40,   2,
  71,  18,   3,  41,  72,  18,   4,  42,  71,   0,  74,   0,  76,   0,  80,   0,
  83,  11, 139,   1,   6,   1,  16,   1,   3, 140,   1,   6,   2,  16,   3,   3,
 141,   1,   6,   3,  16,   2,   3, 142,   1,   6,   4,  16,   4,   3, 143,   1,
   6,   5,  16,   5,   3, 144,   1,   6,   6,   0,   3,   3, 145,   1,   6,   7,
   0,   2,   3, 146,   1,  17,   3,  84, 147,   1,  17,   4,  85, 148,   1,  17,
   5,  86, 149,   1,  17,   6,  87,  90,   0, 101,   9, 165,   1,  18,   3, 102,
 166,   1,  18,   4, 103, 167,   1,  17,   5, 104,  21,  17,   6, 105, 168,   1,
  17,   7, 106, 169,   1,  17,   8, 107, 170,   1,  17,   9, 108, 171,   1,  17,
  10, 109, 172,   1,  17,  11, 110, 123,  37, 200,   1,  18,   3, 124, 201,   1,
  18,   4, 125, 202,   1,  18,   5, 126, 203,   1,  18,   6, 127, 204,   1,  18,
   7, 128,   1, 205,   1,  18,   8, 129,   1, 206,   1,  18,   9, 130,   1, 207,
   1,  18,  10, 131,   1, 208,   1,  18,  11, 132,   1, 209,   1,  18,  12, 133,
   1, 210,   1,  18,  13, 134,   1, 211,   1,  18,  14, 135,   1, 212,   1,  18,
  15, 136,   1, 213,   1,  18,  16, 137,   1, 214,   1,  18,  17, 138,   1, 215,
   1,  18,  18, 139,   1, 216,   1,  18,  19, 140,   1, 217,   1,  18,  20, 141,
   1, 218,   1,  18,  21, 142,   1, 219,   1,  18,  22, 143,   1, 220,   1,  18,
  23, 144,   1, 221,   1,  18,  24, 145,   1, 222,   1,  18,  25, 146,   1, 223,
   1,  18,  26, 147,   1, 224,   1,  18,  27, 148,   1, 225,   1,  18,  28, 149,
   1, 226,   1,  18,  29, 150,   1, 227,   1,  17,  30, 151,   1, 228,   1,  17,
  31, 152,   1, 229,   1,  17,  32, 153,   1, 230,   1,  17,  33, 154,   1, 231,
   1,  17,  34, 155,   1, 232,   1,  17,  35, 156,   1, 233,   1,  17,  36, 157,
   1, 234,   1,  17,  37, 158,   1, 235,   1,  17,  38, 159,   1, 236,   1,  17,
  39, 160,   1, 167,   1,   2, 227,   2,  17,   3, 168,   1, 228,   2,  17,   4,
 169,   1, 174,   1,  52, 237,   2,  18,   3, 175,   1, 238,   2,  18,   4, 176,
   1, 239,   2,  18,   5, 177,   1, 240,   2,  18,   6, 178,   1, 241,   2,  18,
   7, 179,   1, 242,   2,  18,   8, 180,   1, 243,   2,  18,   9, 181,   1, 244,
   2,  18,  10, 182,   1, 245,   2,  18,  11, 183,   1, 246,   2,  18,  12, 184,
   1, 247,   2,  18,  13, 185,   1, 248,   2,  18,  14, 186,   1, 249,   2,  18,
  15, 187,   1, 250,   2,  18,  16, 188,   1, 251,   2,  18,  17, 189,   1, 252,
   2,  18,  18, 190,   1, 253,   2,  18,  19, 191,   1, 254,   2,  18,  20, 192,
   1, 255,   2,  18,  21, 193,   1, 128,   3,  18,  22, 194,   1, 129,   3,  18,
  23, 195,   1, 130,   3,  18,  24, 196,   1, 131,   3,  18,  25, 197,   1, 132,
   3,  18,  26, 198,   1, 133,   3,  18,  27, 199,   1, 134,   3,  18,  28, 200,
   1, 135,   3,  18,  29, 201,   1, 136,   3,  18,  30, 202,   1, 137,   3,  18,
  31, 203,   1, 138,   3,  18,  32, 204,   1, 139,   3,  18,  33, 205,   1, 140,
   3,  18,  34, 206,   1, 141,   3,  18,  35, 207,   1, 142,   3,  18,  36, 208,
   1, 143,   3,  18,  37, 209,   1, 144,   3,  18,  38, 210,   1, 145,   3,  18,
  39, 211,   1, 146,   3,  18,  40, 212,   1, 147,   3,  18,  41, 213,   1, 148,
   3,  18,  42, 214,   1, 149,   3,  18,  43, 215,   1, 150,   3,  18,  44, 216,
   1, 151,   3,  18,  45, 217,   1, 152,   3,  18,  46, 218,   1, 153,   3,  18,
  47, 219,   1, 154,   3,  18,  48, 220,   1, 155,   3,  18,  49, 221,   1, 156,
   3,  18,  50, 222,   1, 157,   3,  18,  51, 223,   1, 158,   3,  18,  52, 224,
   1, 159,   3,  18,  53, 225,   1, 159,   3,  19,  54, 226,   1, 231,   1,   4,
 188,   4,  18,   3, 232,   1, 189,   4,  18,   4, 233,   1, 190,   4,  17,   5,
 234,   1, 191,   4,  17,   6, 235,   1, 240,   1,  37, 205,   4,  18,   3, 241,
   1, 206,   4,  18,   4, 242,   1, 207,   4,  18,   5, 243,   1, 208,   4,  18,
   6, 244,   1, 209,   4,  18,   7, 245,   1, 210,   4,  18,   8, 246,   1, 211,
   4,  18,   9, 247,   1, 212,   4,  18,  10, 248,   1, 213,   4,  18,  11, 249,
   1, 214,   4,  18,  12, 250,   1, 215,   4,  18,  13, 251,   1, 216,   4,  18,
  14, 252,   1, 217,   4,  18,  15, 253,   1, 218,   4,  18,  16, 254,   1, 219,
   4,  18,  17, 255,   1, 220,   4,  18,  18, 128,   2, 221,   4,  18,  19, 129,
   2, 222,   4,  18,  20, 130,   2, 223,   4,  18,  21, 131,   2, 224,   4,  18,
  22, 132,   2, 225,   4,  18,  23, 133,   2, 226,   4,  18,  24, 134,   2, 227,
   4,  18,  25, 135,   2, 228,   4,  18,  26, 136,   2, 229,   4,  18,  27, 137,
   2, 230,   4,  18,  28, 138,   2, 231,   4,  18,  29, 139,   2, 232,   4,  18,
  30, 140,   2, 233,   4,  18,  31, 141,   2, 234,   4,  18,  32, 142,   2, 235,
   4,  18,  33, 143,   2, 236,   4,  18,  34, 144,   2, 237,   4,  18,  35, 145,
   2, 238,   4,  18,  36, 146,   2, 239,   4,  18,  37, 147,   2, 240,   4,  17,
  38, 148,   2, 241,   4,  17,  39, 149,   2, 152,   2,   2, 226,   5,   6,   1,
   3, 240,   2,   1, 227,   5,   6,   2,   3, 242,   2,   1, 155,   2,   6, 232,
   5,  17,   3, 156,   2, 233,   5,  17,   4, 157,   2, 234,   5,  17,   5, 158,
   2, 235,   5,  17,   6, 159,   2, 236,   5,  17,   7, 160,   2, 237,   5,  17,
   8, 161,   2,  13,  50,   1,  80,  68,   0,   3,   1,   2,  82,  23, 109,  68,
   1,   4,   1,   3, 110,  68,   2,   5,   1,   4, 111,  68,   3,   6,   1,   5,
 112,  68,   4,   7,   1,   6, 113,  65,   7,  70,   1,   7, 114,  65,   8,  69,
   1,   8, 115,  65,   9,  68,   1,   9, 116,  65,  10,  67,   1,  10, 117,  65,
  11,  66,   1,  11, 118,   1,  12,  65, 119,  65,  13,  63,   1,  12, 120,  65,
  14,  62,   1,  13, 121,  65,  15,  61,   1,  14, 122,  65,  16,  60,   1,  15,
 123,  65,  17,  59,   1,  16, 124,   1,  18,  58, 125,   1,  19,  57, 126,   1,
  20,  56, 127,  65,  21,  55,   1,  17, 128,   1,  65,  22,  54,   1,  18, 129,
   1,  65,  23,  53,   1,  19, 130,   1,  65,  24,  52,   1,  20, 131,   1,  65,
  25,  51,   1,  21,  89,   1, 152,   1,  68,   1,   8,   1,  22,  93,   1, 157,
   1,  68,   1,   9,   1,  23, 112,  10, 179,   1,  68,   1,  10,   2,  24,  25,
 180,   1,   6,   2,  16,   0, 181,   1,   6,   3,  16,   0, 182,   1,   1,  26,
 100, 183,   1,   1,  27,  99, 184,   1,   1,  28,  98, 185,   1,   1,  29,  97,
 186,   1,   1,  30,  96, 187,   1,   1,  31,  95, 188,   1,   1,  32,  94, 162,
   1,  38, 238,   1,  68,   0,  11,   2,  24,  26, 240,   1,   6,   0,  16,   0,
 243,   1,   6,   0,  16,   0, 246,   1,   6,   0,  16,   0, 249,   1,   6,   0,
  16,   0, 252,   1,   6,   0,  16,   0, 255,   1,   6,   0,  16,   0, 130,   2,
   6,   0,  16,   0, 133,   2,   6,   0,  16,   0, 136,   2,   6,   0,  16,   0,
 139,   2,   6,   0,  16,   0, 142,   2,   6,   0,  16,   0, 145,   2,   6,   0,
  16,   0, 148,   2,   6,   0,  16,   0, 151,   2,   6,   0,  16,   0, 154,   2,
   6,   0,  16,   0, 157,   2,   6,   0,  16,   0, 160,   2,   6,   0,  16,   0,
 163,   2,   6,   0,  16,   0, 166,   2,   6,   0,  16,   0, 169,   2,   6,   0,
  16,   0, 172,   2,   6,   0,  16,   0, 175,   2,   6,   0,  16,   0, 178,   2,
   6,   0,  16,   0, 181,   2,   6,   0,  16,   0, 184,   2,   6,   0,  16,   0,
 187,   2,   6,   0,  16,   0, 190,   2,   6,   0,  16,   0, 192,   2,   1,  33,
 122, 193,   2,   1,  34, 121, 194,   2,   1,  35, 120, 195,   2,   1,  36, 119,
 196,   2,   1,  37, 118, 197,   2,   1,  38, 117, 198,   2,   1,  39, 116, 199,
   2,   1,  40, 115, 200,   2,   1,  41, 114, 201,   2,   1,  42, 113, 171,   1,
   4, 231,   2,  68,   1,  12,   2,  24,  27, 232,   2,   1,  43, 166,   1, 233,
   2,   1,  44, 165,   1, 234,   2,   1,  45, 164,   1, 228,   1,  53, 161,   3,
  68,   0,  13,   2,  24,  28, 163,   3,   6,   0,  16,   0, 166,   3,   6,   0,
  16,   0, 169,   3,   6,   0,  16,   0, 172,   3,   6,   0,  16,   0, 175,   3,
   6,   0,  16,   0, 178,   3,   6,   0,  16,   0, 181,   3,   6,   0,  16,   0,
 184,   3,   6,   0,  16,   0, 187,   3,   6,   0,  16,   0, 190,   3,   6,   0,
  16,   0, 193,   3,   6,   0,  16,   0, 196,   3,   6,   0,  16,   0, 199,   3,
   6,   0,  16,   0, 202,   3,   6,   0,  16,   0, 205,   3,   6,   0,  16,   0,
 208,   3,   6,   0,  16,   0, 211,   3,   6,   0,  16,   0, 214,   3,   6,   0,
  16,   0, 217,   3,   6,   0,  16,   0, 220,   3,   6,   0,  16,   0, 223,   3,
   6,   0,  16,   0, 226,   3,   6,   0,  16,   0, 229,   3,   6,   0,  16,   0,
 232,   3,   6,   0,  16,   0, 235,   3,   6,   0,  16,   0, 238,   3,   6,   0,
  16,   0, 241,   3,   6,   0,  16,   0, 244,   3,   6,   0,  16,   0, 247,   3,
   6,   0,  16,   0, 250,   3,   6,   0,  16,   0, 253,   3,   6,   0,  16,   0,
 128,   4,   6,   0,  16,   0, 131,   4,   6,   0,  16,   0, 134,   4,   6,   0,
  16,   0, 137,   4,   6,   0,  16,   0, 140,   4,   6,   0,  16,   0, 143,   4,
   6,   0,  16,   0, 146,   4,   6,   0,  16,   0, 149,   4,   6,   0,  16,   0,
 152,   4,   6,   0,  16,   0, 155,   4,   6,   0,  16,   0, 158,   4,   6,   0,
  16,   0, 161,   4,   6,   0,  16,   0, 164,   4,   6,   0,  16,   0, 167,   4,
   6,   0,  16,   0, 170,   4,   6,   0,  16,   0, 173,   4,   6,   0,  16,   0,
 176,   4,   6,   0,  16,   0, 179,   4,   6,   0,  16,   0, 182,   4,   6,   0,
  16,   0, 185,   4,   2,  46, 173,   1, 185,   4,   3,  47, 172,   1, 237,   1,
   5, 198,   4,  68,   1,  14,   2,  24,  29, 199,   4,   6,   2,  16,   0, 200,
   4,   6,   3,  16,   0, 201,   4,   1,  48, 230,   1, 202,   4,   1,  49, 229,
   1, 151,   2,  38, 186,   5,  68,   1,  15,   2,  24,  30, 187,   5,   6,   2,
  16,   0, 188,   5,   6,   3,  16,   0, 189,   5,   6,   4,  16,   0, 190,   5,
   6,   5,  16,   0, 191,   5,   6,   6,  16,   0, 192,   5,   6,   7,  16,   0,
 193,   5,   6,   8,  16,   0, 194,   5,   6,   9,  16,   0, 195,   5,   6,  10,
  16,   0, 196,   5,   6,  11,  16,   0, 197,   5,   6,  12,  16,   0, 198,   5,
   6,  13,  16,   0, 199,   5,   6,  14,  16,   0, 200,   5,   6,  15,  16,   0,
 201,   5,   6,  16,  16,   0, 202,   5,   6,  17,  16,   0, 203,   5,   6,  18,
  16,   0, 204,   5,   6,  19,  16,   0, 205,   5,   6,  20,  16,   0, 206,   5,
   6,  21,  16,   0, 207,   5,   6,  22,  16,   0, 208,   5,   6,  23,  16,   0,
 209,   5,   6,  24,  16,   0, 210,   5,   6,  25,  16,   0, 211,   5,   6,  26,
  16,   0, 212,   5,   6,  27,  16,   0, 213,   5,   6,  28,  16,   0, 214,   5,
   6,  29,  16,   0, 215,   5,   6,  30,  16,   0, 216,   5,   6,  31,  16,   0,
 217,   5,   6,  32,  16,   0, 218,   5,   6,  33,  16,   0, 219,   5,   6,  34,
  16,   0, 220,   5,   6,  35,  16,   0, 221,   5,   6,  36,  16,   0, 222,   5,
   1,  50, 239,   1, 223,   5,   1,  51, 238,   1, 154,   2,   1, 230,   5,   4,
   1,  16, 163,   2,   1, 239,   5,  68,   1,  17,   1,  31,  39,   9,  60,  68,
   0,   0,   1,   0,  61,  68,   0,   1,   1,   1,  62,   1,   1,   5,  63,   4,
   0,   2,  64,   1,   2,   4,  65,   1,   3,   3,  26,   1,   4,   2,  30,   1,
   5,   1,  33,   1,   6,   0,  91,   0,   1,   1,   1,   2,  10, 208,  48,  93,
   1, 102,   1,  70,   2,   0,  72,   0,   0,   1,   1,   1,   1,   2,  10, 208,
  48,  93,   1, 102,   1,  70,   4,   0,  72,   0,   0,   2,   2,   2,   1,   2,
  12, 208,  48,  93,   1, 102,   1, 209,  70,   6,   1,  41,  71,   0,   0,   3,
   2,   2,   1,   2,  12, 208,  48,  93,   1, 102,   1, 209,  70,   6,   1,  41,
  71,   0,   0,   4,   2,   2,   1,   2,  13, 208,  48,  93,   7, 102,   7, 102,
   8, 209,  70,   9,   1,  72,   0,   0,   5,   1,   1,   1,   2,  11, 208,  48,
  93,  11, 102,  11,  70,  12,   0,  41,  71,   0,   0,   6,   2,   1,   3,   4,
  12, 208,  48,  94,  13,  93,  14,  70,  14,   0, 104,  13,  71,   0,   0,  27,
   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,  28,   1,   1,
   3,   4,   3, 208,  48,  71,   0,   0,  34,   1,   1,   4,   5,   6, 208,  48,
 208,  73,   0,  71,   0,   0,  35,   1,   1,   3,   4,   3, 208,  48,  71,   0,
   0,  36,   1,   1,   3,   4,   5, 208,  48,  44,  51,  72,   0,   0,  37,   1,
   1,   3,   4,  10, 208,  48,  93,  50, 102,  50,  70,  51,   0,  72,   0,   0,
  38,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,  39,   3,
   3,   1,   3,  67, 208,  48,  93,  54,  93,  43, 102,  43,  48,  93,  55, 102,
  55,  88,   0,  29, 104,  42,  93,  56,  93,  43, 102,  43,  48,  93,  55, 102,
  55,  88,   1,  29, 104,  49,  93,  57,  93,  43, 102,  43,  48,  93,  58, 102,
  58,  88,   2,  29, 104,  53,  94,  59,  36,   0,  42, 214,  97,  59, 210,   8,
   2, 130, 213, 209,  72,   8,   1,   0,   0,  40,   1,   1,   3,   4,   3, 208,
  48,  71,   0,   0,  44,   2,   2,   4,   5,  12, 208,  48, 208,  73,   0, 208,
 209,  70,  67,   1,  41,  71,   0,   0,  47,   3,   3,   4,   5,  16, 208,  48,
 208,  93,  68, 102,  68, 209,  70,  69,   1, 210,  70,  70,   2,  72,   0,   0,
  50,   2,   1,   1,   3,  19, 208,  48,  93,  78,  93,  43, 102,  43,  48,  93,
  79, 102,  79,  88,   3,  29, 104,  66,  71,   0,   0,  56,   4,   3,   1,   2,
  12, 208,  48,  93,  83, 209, 210,  36,   1,  70,  83,   3,  72,   0,   0,  57,
   4,   3,   1,   2,  12, 208,  48,  93,  83, 209, 210,  36,   2,  70,  83,   3,
  72,   0,   0,  58,   4,   3,   1,   2,  12, 208,  48,  93,  83, 209, 210,  36,
   0,  70,  83,   3,  72,   0,   0,  64,   3,   3,   3,   6,  45,  87,  42, 213,
  48, 101,   0,  38, 118, 109,   1,  93,  84,  76,  84,   0,  41,  16,  20,   0,
   0, 209,  48,  90,   0,  42, 214,  42,  48,  43, 109,   1, 101,   0,  39, 118,
 109,   1,  29,   8,   2, 101,   0, 108,   1,  72,   1,  10,  16,  20,   0,  85,
   1,  86,   0,   1,  18,   0,  65,   2,   3,   2,   4,  55, 208,  48,  87,  42,
 214,  48, 101,   1,  33, 130, 109,   2, 101,   1, 209, 109,   1, 101,   1, 108,
   1,  32,  19,  21,   0,   0, 101,   1,  64,  64, 130, 109,   2,  93,  87, 101,
   1, 108,   2,  70,  87,   1,  41,  16,   7,   0,   0,  93,  87,  32,  70,  87,
   1,  41,  71,   0,   2,  88,   0,   1,  81,   0,  89,   0,   2,   0,   0,  71,
   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,  72,   3,   1,   4,   5,  42,
 208,  48, 208, 102,  90,  44,  91, 160, 208, 102,  91, 118,  18,  21,   0,   0,
  44,  93, 208, 102,  91, 160,  44,  94, 160, 208, 102,  92, 160,  44,  96, 160,
 130,  16,   3,   0,   0,  44,   3, 130, 160,  72,   0,   0,  73,   1,   1,   4,
   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,  74,   1,   1,   3,   4,   3,
 208,  48,  71,   0,   0,  75,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,
  71,   0,   0,  76,   1,   1,   4,   5,   3, 208,  48,  71,   0,   0,  79,   1,
   1,   5,   6,   6, 208,  48, 208,  73,   0,  71,   0,   0,  80,   1,   1,   4,
   5,   3, 208,  48,  71,   0,   0,  81,   1,   1,   5,   6,   6, 208,  48, 208,
  73,   0,  71,   0,   0,  82,   2,   1,   1,   4,  77, 208,  48, 101,   0,  93,
  43, 102,  43,  48,  93, 108, 102, 108,  88,   4,  29, 104,  98, 101,   0,  93,
  43, 102,  43,  48,  93, 108, 102, 108,  88,   5,  29, 104, 101, 101,   0,  93,
  43, 102,  43,  48,  93, 101, 102, 101,  48, 100, 108,   2,  88,   6,  29,  29,
 104, 106, 101,   0,  93,  43, 102,  43,  48,  93, 101, 102, 101,  48, 100, 108,
   2,  88,   7,  29,  29, 104, 107,  71,   0,   0,  83,   2,   1,   3,   4,  59,
 208,  48,  94, 132,   1,  36,   0, 104, 132,   1,  94, 133,   1,  36,   1, 104,
 133,   1,  94, 134,   1,  36,   2, 104, 134,   1,  94, 135,   1,  36,   3, 104,
 135,   1,  94, 136,   1,  36,   4, 104, 136,   1,  94, 137,   1,  36,   1, 104,
 137,   1,  94, 138,   1,  36,   2, 104, 138,   1,  71,   0,   0,  88,   1,   1,
   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,  89,   2,   1,   1,   3,
  22, 208,  48, 101,   0,  93,  43, 102,  43,  48,  93, 151,   1, 102, 151,   1,
  88,   8,  29, 104, 150,   1,  71,   0,   0,  90,   1,   1,   3,   4,   3, 208,
  48,  71,   0,   0,  92,   2,   2,   4,   5,  13, 208,  48, 208,  73,   0, 208,
 209,  70, 153,   1,   1,  41,  71,   0,   0,  93,   2,   1,   1,   3,  22, 208,
  48, 101,   0,  93,  43, 102,  43,  48,  93, 156,   1, 102, 156,   1,  88,   9,
  29, 104, 155,   1,  71,   0,   0,  94,   2,   2,   1,   2,  11, 208,  48, 100,
 108,   1, 209,  70, 158,   1,   1,  72,   0,   0,  95,   2,   2,   1,   2,  11,
 208,  48, 100, 108,   1, 209,  70, 159,   1,   1,  72,   0,   0,  96,   2,   2,
   1,   2,  11, 208,  48, 100, 108,   1, 209,  70, 160,   1,   1,  72,   0,   0,
  97,   4,   5,   1,   2,  29, 208,  48,  36,   0, 115,  99,   4, 211,  18,   5,
   0,   0,  36,   1, 115,  99,   4, 100, 108,   1, 209, 210,  98,   4,  70, 161,
   1,   3,  72,   0,   0,  98,   2,   2,   1,   2,  11, 208,  48, 100, 108,   1,
 209,  70, 162,   1,   1,  72,   0,   0,  99,   2,   2,   1,   2,  24, 208,  48,
 209,  36, 255,  20,   5,   0,   0, 100, 108,   2, 115, 213, 100, 108,   1, 209,
  70, 163,   1,   1,  41,  71,   0,   0, 100,   1,   1,   1,   2,  11, 208,  48,
 100, 108,   1,  70, 164,   1,   0,  41,  71,   0,   0, 101,   1,   1,   3,   4,
   3, 208,  48,  71,   0,   0, 111,   1,   1,   4,   5,   6, 208,  48, 208,  73,
   0,  71,   0,   0, 112,   2,   1,   1,   3,  44, 208,  48, 101,   0,  93,  43,
 102,  43,  48,  93, 174,   1, 102, 174,   1,  88,  10,  29, 104, 173,   1, 101,
   0, 100, 108,   1, 102, 175,   1, 104, 176,   1, 101,   0, 100, 108,   1, 102,
 177,   1, 104, 178,   1,  71,   0,   0, 113,   2,   2,   1,   2,  14, 208,  48,
  93, 189,   1, 102, 189,   1, 209,  70, 190,   1,   1,  72,   0,   0, 114,   2,
   2,   1,   2,  15, 208,  48,  93, 189,   1, 102, 189,   1, 209,  70, 191,   1,
   1,  41,  71,   0,   0, 115,   2,   2,   1,   2,  14, 208,  48,  93, 189,   1,
 102, 189,   1, 209,  70, 192,   1,   1,  72,   0,   0, 116,   2,   2,   1,   2,
  14, 208,  48,  93, 189,   1, 102, 189,   1, 209,  70, 193,   1,   1,  72,   0,
   0, 117,   1,   1,   1,   2,  13, 208,  48,  93, 189,   1, 102, 189,   1,  70,
 194,   1,   0,  72,   0,   0, 118,   1,   1,   1,   2,  13, 208,  48,  93, 189,
   1, 102, 189,   1,  70, 195,   1,   0,  72,   0,   0, 119,   1,   1,   1,   2,
  13, 208,  48,  93, 189,   1, 102, 189,   1,  70, 196,   1,   0,  72,   0,   0,
 120,   3,   3,   1,   2,  15, 208,  48,  93, 189,   1, 102, 189,   1, 209, 210,
  70, 197,   1,   2,  72,   0,   0, 121,   2,   2,   1,   2,  14, 208,  48,  93,
 189,   1, 102, 189,   1, 209,  70, 198,   1,   1,  72,   0,   0, 122,   3,   3,
   1,   2,  15, 208,  48,  93, 189,   1, 102, 189,   1, 209, 210,  70, 199,   1,
   2,  72,   0,   0, 123,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 161,
   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 162,   1,
   2,   1,   1,   3, 172,   3, 208,  48,  93, 238,   1,  93,  43, 102,  43,  48,
  93, 239,   1, 102, 239,   1,  88,  11,  29, 104, 237,   1,  93, 240,   1,  93,
 189,   1, 102, 189,   1, 102, 241,   1, 104, 242,   1,  93, 243,   1,  93, 189,
   1, 102, 189,   1, 102, 244,   1, 104, 245,   1,  93, 246,   1,  93, 189,   1,
 102, 189,   1, 102, 247,   1, 104, 248,   1,  93, 249,   1,  93, 189,   1, 102,
 189,   1, 102, 250,   1, 104, 251,   1,  93, 252,   1,  93, 189,   1, 102, 189,
   1, 102, 253,   1, 104, 254,   1,  93, 255,   1,  93, 189,   1, 102, 189,   1,
 102, 128,   2, 104, 129,   2,  93, 130,   2,  93, 189,   1, 102, 189,   1, 102,
 131,   2, 104, 132,   2,  93, 133,   2,  93, 189,   1, 102, 189,   1, 102, 134,
   2, 104, 135,   2,  93, 136,   2,  93, 189,   1, 102, 189,   1, 102, 137,   2,
 104, 138,   2,  93, 139,   2,  93, 189,   1, 102, 189,   1, 102, 140,   2, 104,
 141,   2,  93, 142,   2,  93, 189,   1, 102, 189,   1, 102, 143,   2, 104, 144,
   2,  93, 145,   2,  93, 189,   1, 102, 189,   1, 102, 146,   2, 104, 147,   2,
  93, 148,   2,  93, 189,   1, 102, 189,   1, 102, 149,   2, 104, 150,   2,  93,
 151,   2,  93, 189,   1, 102, 189,   1, 102, 152,   2, 104, 153,   2,  93, 154,
   2,  93, 189,   1, 102, 189,   1, 102, 155,   2, 104, 156,   2,  93, 157,   2,
  93, 189,   1, 102, 189,   1, 102, 158,   2, 104, 159,   2,  93, 160,   2,  93,
 189,   1, 102, 189,   1, 102, 161,   2, 104, 162,   2,  93, 163,   2,  93, 189,
   1, 102, 189,   1, 102, 164,   2, 104, 165,   2,  93, 166,   2,  93, 189,   1,
 102, 189,   1, 102, 167,   2, 104, 168,   2,  93, 169,   2,  93, 189,   1, 102,
 189,   1, 102, 170,   2, 104, 171,   2,  93, 172,   2,  93, 189,   1, 102, 189,
   1, 102, 173,   2, 104, 174,   2,  93, 175,   2,  93, 189,   1, 102, 189,   1,
 102, 176,   2, 104, 177,   2,  93, 178,   2,  93, 189,   1, 102, 189,   1, 102,
 179,   2, 104, 180,   2,  93, 181,   2,  93, 189,   1, 102, 189,   1, 102, 182,
   2, 104, 183,   2,  93, 184,   2,  93, 189,   1, 102, 189,   1, 102, 185,   2,
 104, 186,   2,  93, 187,   2,  93, 189,   1, 102, 189,   1, 102, 188,   2, 104,
 189,   2,  93, 190,   2,  93, 189,   1, 102, 189,   1, 102, 250,   1, 104, 191,
   2,  71,   0,   0, 163,   1,   2,   3,   2,   2, 220,   1,  16,  44,   0,   0,
   9,  44, 236,   1,  72,   9,  44, 237,   1,  72,   9,  44, 238,   1,  72,   9,
  44, 239,   1,  72,   9,  44, 240,   1,  72,   9,  44, 241,   1,  72,   9,  44,
 242,   1,  72,   9,  44, 243,   1,  72,  16, 172,   0,   0, 209,  93, 202,   2,
 102, 202,   2, 168, 214,  93, 203,   2, 102, 203,   2, 210,  26,   6,   0,   0,
  37,   0,  16, 115,   0,   0,  93, 204,   2, 102, 204,   2, 210,  26,   6,   0,
   0,  37,   1,  16,  98,   0,   0,  93, 205,   2, 102, 205,   2, 210,  26,   6,
   0,   0,  37,   2,  16,  81,   0,   0,  93, 206,   2, 102, 206,   2, 210,  26,
   6,   0,   0,  37,   3,  16,  64,   0,   0,  93, 207,   2, 102, 207,   2, 210,
  26,   6,   0,   0,  37,   4,  16,  47,   0,   0,  93, 208,   2, 102, 208,   2,
 210,  26,   6,   0,   0,  37,   5,  16,  30,   0,   0,  93, 209,   2, 102, 209,
   2, 210,  26,   6,   0,   0,  37,   6,  16,  13,   0,   0,  39,  18,   6,   0,
   0,  37,   7,  16,   2,   0,   0,  37,   7,   8,   2,  27, 104, 255, 255,   7,
  69, 255, 255,  74, 255, 255,  79, 255, 255,  84, 255, 255,  89, 255, 255,  94,
 255, 255,  99, 255, 255, 104, 255, 255,   0,   0, 164,   1,   5,   3,   2,   4,
 143,   3, 208,  48,  87,  42, 214,  48, 101,   1, 209, 109,   1, 101,   1,  93,
 210,   2,  36,  10,  74, 210,   2,   1, 128,  17, 109,   2, 101,   1,  64, 163,
   1, 128,  81, 109,   3, 101,   1, 108,   2,  36,   0, 101,   1, 108,   3, 100,
 101,   1, 108,   1,  65,   1,  97, 211,   2, 101,   1, 108,   2,  36,   1, 101,
   1, 108,   1,  93, 212,   2, 102, 212,   2, 168, 118,  18,   8,   0,   0,  44,
 246,   1, 130,  16,   4,   0,   0,  44, 236,   1, 130,  97, 211,   2, 101,   1,
 108,   2,  36,   2, 101,   1, 108,   1,  93, 213,   2, 102, 213,   2, 168, 118,
  18,   8,   0,   0,  44, 247,   1, 130,  16,   4,   0,   0,  44, 236,   1, 130,
  97, 211,   2, 101,   1, 108,   2,  36,   3, 101,   1, 108,   1,  93, 214,   2,
 102, 214,   2, 168, 118,  18,   8,   0,   0,  44, 248,   1, 130,  16,   4,   0,
   0,  44, 236,   1, 130,  97, 211,   2, 101,   1, 108,   2,  36,   4, 101,   1,
 108,   1,  93, 215,   2, 102, 215,   2, 168, 118,  18,   8,   0,   0,  44, 246,
   1, 130,  16,   4,   0,   0,  44, 236,   1, 130,  97, 211,   2, 101,   1, 108,
   2,  36,   5, 101,   1, 108,   1,  93, 216,   2, 102, 216,   2, 168, 118,  18,
   8,   0,   0,  44, 247,   1, 130,  16,   4,   0,   0,  44, 236,   1, 130,  97,
 211,   2, 101,   1, 108,   2,  36,   6, 101,   1, 108,   1,  93, 217,   2, 102,
 217,   2, 168, 118,  18,   8,   0,   0,  44, 248,   1, 130,  16,   4,   0,   0,
  44, 236,   1, 130,  97, 211,   2, 101,   1, 108,   2,  36,   7, 101,   1, 108,
   1,  93, 218,   2, 102, 218,   2, 168, 118,  18,   8,   0,   0,  44, 246,   1,
 130,  16,   4,   0,   0,  44, 236,   1, 130,  97, 211,   2, 101,   1, 108,   2,
  36,   8, 101,   1, 108,   1,  93, 219,   2, 102, 219,   2, 168, 118,  18,   8,
   0,   0,  44, 247,   1, 130,  16,   4,   0,   0,  44, 236,   1, 130,  97, 211,
   2, 101,   1, 108,   2,  36,   9, 101,   1, 108,   1,  93, 220,   2, 102, 220,
   2, 168, 118,  18,   8,   0,   0,  44, 248,   1, 130,  16,   4,   0,   0,  44,
 236,   1, 130,  97, 211,   2, 101,   1, 108,   2,  44,   3,  70, 221,   2,   1,
  72,   0,   3, 222,   2,   0,   1,  16,   0, 223,   2,   0,   2,  17,   0, 224,
   2,   0,   3,  81,   0, 165,   1,   2,   2,   1,   2,  11, 208,  48, 100, 108,
   1, 209,  70, 225,   2,   1,  72,   0,   0, 166,   1,   2,   2,   1,   2,  11,
 208,  48, 100, 108,   1, 209,  70, 226,   2,   1,  72,   0,   0, 167,   1,   1,
   1,   3,   4,   3, 208,  48,  71,   0,   0, 170,   1,   1,   1,   4,   5,   6,
 208,  48, 208,  73,   0,  71,   0,   0, 171,   1,   2,   1,   1,   3,  22, 208,
  48, 101,   0,  93,  43, 102,  43,  48,  93, 230,   2, 102, 230,   2,  88,  12,
  29, 104, 229,   2,  71,   0,   0, 172,   1,   2,   2,   1,   2,  13, 208,  48,
  93, 235,   2, 102, 235,   2, 209,  97, 236,   2,  71,   0,   0, 173,   1,   1,
   1,   1,   2,  12, 208,  48,  93, 235,   2, 102, 235,   2, 102, 236,   2,  72,
   0,   0, 174,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 227,   1,
   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 228,   1,   2,
   1,   1,   3, 133,   6, 208,  48,  93, 161,   3,  93,  43, 102,  43,  48,  93,
 162,   3, 102, 162,   3,  88,  13,  29, 104, 160,   3,  93, 163,   3,  93, 235,
   2, 102, 235,   2, 102, 164,   3, 104, 165,   3,  93, 166,   3,  93, 235,   2,
 102, 235,   2, 102, 167,   3, 104, 168,   3,  93, 169,   3,  93, 235,   2, 102,
 235,   2, 102, 170,   3, 104, 171,   3,  93, 172,   3,  93, 235,   2, 102, 235,
   2, 102, 173,   3, 104, 174,   3,  93, 175,   3,  93, 235,   2, 102, 235,   2,
 102, 176,   3, 104, 177,   3,  93, 178,   3,  93, 235,   2, 102, 235,   2, 102,
 179,   3, 104, 180,   3,  93, 181,   3,  93, 235,   2, 102, 235,   2, 102, 182,
   3, 104, 183,   3,  93, 184,   3,  93, 235,   2, 102, 235,   2, 102, 185,   3,
 104, 186,   3,  93, 187,   3,  93, 235,   2, 102, 235,   2, 102, 188,   3, 104,
 189,   3,  93, 190,   3,  93, 235,   2, 102, 235,   2, 102, 191,   3, 104, 192,
   3,  93, 193,   3,  93, 235,   2, 102, 235,   2, 102, 194,   3, 104, 195,   3,
  93, 196,   3,  93, 235,   2, 102, 235,   2, 102, 197,   3, 104, 198,   3,  93,
 199,   3,  93, 235,   2, 102, 235,   2, 102, 200,   3, 104, 201,   3,  93, 202,
   3,  93, 235,   2, 102, 235,   2, 102, 203,   3, 104, 204,   3,  93, 205,   3,
  93, 235,   2, 102, 235,   2, 102, 206,   3, 104, 207,   3,  93, 208,   3,  93,
 235,   2, 102, 235,   2, 102, 209,   3, 104, 210,   3,  93, 211,   3,  93, 235,
   2, 102, 235,   2, 102, 212,   3, 104, 213,   3,  93, 214,   3,  93, 235,   2,
 102, 235,   2, 102, 215,   3, 104, 216,   3,  93, 217,   3,  93, 235,   2, 102,
 235,   2, 102, 218,   3, 104, 219,   3,  93, 220,   3,  93, 235,   2, 102, 235,
   2, 102, 221,   3, 104, 222,   3,  93, 223,   3,  93, 235,   2, 102, 235,   2,
 102, 224,   3, 104, 225,   3,  93, 226,   3,  93, 235,   2, 102, 235,   2, 102,
 227,   3, 104, 228,   3,  93, 229,   3,  93, 235,   2, 102, 235,   2, 102, 230,
   3, 104, 231,   3,  93, 232,   3,  93, 235,   2, 102, 235,   2, 102, 233,   3,
 104, 234,   3,  93, 235,   3,  93, 235,   2, 102, 235,   2, 102, 236,   3, 104,
 237,   3,  93, 238,   3,  93, 235,   2, 102, 235,   2, 102, 239,   3, 104, 240,
   3,  93, 241,   3,  93, 235,   2, 102, 235,   2, 102, 242,   3, 104, 243,   3,
  93, 244,   3,  93, 235,   2, 102, 235,   2, 102, 245,   3, 104, 246,   3,  93,
 247,   3,  93, 235,   2, 102, 235,   2, 102, 248,   3, 104, 249,   3,  93, 250,
   3,  93, 235,   2, 102, 235,   2, 102, 251,   3, 104, 252,   3,  93, 253,   3,
  93, 235,   2, 102, 235,   2, 102, 254,   3, 104, 255,   3,  93, 128,   4,  93,
 235,   2, 102, 235,   2, 102, 129,   4, 104, 130,   4,  93, 131,   4,  93, 235,
   2, 102, 235,   2, 102, 132,   4, 104, 133,   4,  93, 134,   4,  93, 235,   2,
 102, 235,   2, 102, 135,   4, 104, 136,   4,  93, 137,   4,  93, 235,   2, 102,
 235,   2, 102, 138,   4, 104, 139,   4,  93, 140,   4,  93, 235,   2, 102, 235,
   2, 102, 141,   4, 104, 142,   4,  93, 143,   4,  93, 235,   2, 102, 235,   2,
 102, 144,   4, 104, 145,   4,  93, 146,   4,  93, 235,   2, 102, 235,   2, 102,
 147,   4, 104, 148,   4,  93, 149,   4,  93, 235,   2, 102, 235,   2, 102, 150,
   4, 104, 151,   4,  93, 152,   4,  93, 235,   2, 102, 235,   2, 102, 153,   4,
 104, 154,   4,  93, 155,   4,  93, 235,   2, 102, 235,   2, 102, 156,   4, 104,
 157,   4,  93, 158,   4,  93, 235,   2, 102, 235,   2, 102, 159,   4, 104, 160,
   4,  93, 161,   4,  93, 235,   2, 102, 235,   2, 102, 162,   4, 104, 163,   4,
  93, 164,   4,  93, 235,   2, 102, 235,   2, 102, 165,   4, 104, 166,   4,  93,
 167,   4,  93, 235,   2, 102, 235,   2, 102, 168,   4, 104, 169,   4,  93, 170,
   4,  93, 235,   2, 102, 235,   2, 102, 171,   4, 104, 172,   4,  93, 173,   4,
  93, 235,   2, 102, 235,   2, 102, 174,   4, 104, 175,   4,  93, 176,   4,  93,
 235,   2, 102, 235,   2, 102, 177,   4, 104, 178,   4,  93, 179,   4,  93, 235,
   2, 102, 235,   2, 102, 180,   4, 104, 181,   4,  93, 182,   4,  93, 235,   2,
 102, 235,   2, 102, 183,   4, 104, 184,   4,  71,   0,   0, 229,   1,   3,   3,
   1,   2,  12, 208,  48, 100, 108,   1, 209, 210,  70, 186,   4,   2,  72,   0,
   0, 230,   1,   2,   2,   1,   2,  11, 208,  48, 100, 108,   1, 209,  70, 187,
   4,   1,  72,   0,   0, 231,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,
   0, 236,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,
 237,   1,   2,   1,   1,   3,  44, 208,  48, 101,   0,  93,  43, 102,  43,  48,
  93, 193,   4, 102, 193,   4,  88,  14,  29, 104, 192,   4, 101,   0, 100, 108,
   1, 102, 194,   4, 104, 195,   4, 101,   0, 100, 108,   1, 102, 196,   4, 104,
 197,   4,  71,   0,   0, 238,   1,   3,   3,   1,   2,  12, 208,  48, 100, 108,
   1, 209, 210,  70, 203,   4,   2,  72,   0,   0, 239,   1,   3,   3,   1,   2,
  12, 208,  48, 100, 108,   1, 209, 210,  70, 204,   4,   2,  72,   0,   0, 240,
   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 150,   2,   1,   1,   4,
   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 151,   2,   2,   1,   1,   3,
 151,   3, 208,  48, 101,   0,  93,  43, 102,  43,  48,  93, 243,   4, 102, 243,
   4,  88,  15,  29, 104, 242,   4, 101,   0, 100, 108,   1, 102, 244,   4, 104,
 245,   4, 101,   0, 100, 108,   1, 102, 246,   4, 104, 247,   4, 101,   0, 100,
 108,   1, 102, 248,   4, 104, 249,   4, 101,   0, 100, 108,   1, 102, 250,   4,
 104, 251,   4, 101,   0, 100, 108,   1, 102, 252,   4, 104, 253,   4, 101,   0,
 100, 108,   1, 102, 254,   4, 104, 255,   4, 101,   0, 100, 108,   1, 102, 128,
   5, 104, 129,   5, 101,   0, 100, 108,   1, 102, 130,   5, 104, 131,   5, 101,
   0, 100, 108,   1, 102, 132,   5, 104, 133,   5, 101,   0, 100, 108,   1, 102,
 134,   5, 104, 135,   5, 101,   0, 100, 108,   1, 102, 136,   5, 104, 137,   5,
 101,   0, 100, 108,   1, 102, 138,   5, 104, 139,   5, 101,   0, 100, 108,   1,
 102, 140,   5, 104, 141,   5, 101,   0, 100, 108,   1, 102, 142,   5, 104, 143,
   5, 101,   0, 100, 108,   1, 102, 144,   5, 104, 145,   5, 101,   0, 100, 108,
   1, 102, 146,   5, 104, 147,   5, 101,   0, 100, 108,   1, 102, 148,   5, 104,
 149,   5, 101,   0, 100, 108,   1, 102, 150,   5, 104, 151,   5, 101,   0, 100,
 108,   1, 102, 152,   5, 104, 153,   5, 101,   0, 100, 108,   1, 102, 154,   5,
 104, 155,   5, 101,   0, 100, 108,   1, 102, 156,   5, 104, 157,   5, 101,   0,
 100, 108,   1, 102, 158,   5, 104, 159,   5, 101,   0, 100, 108,   1, 102, 160,
   5, 104, 161,   5, 101,   0, 100, 108,   1, 102, 162,   5, 104, 163,   5, 101,
   0, 100, 108,   1, 102, 164,   5, 104, 165,   5, 101,   0, 100, 108,   1, 102,
 166,   5, 104, 167,   5, 101,   0, 100, 108,   1, 102, 168,   5, 104, 169,   5,
 101,   0, 100, 108,   1, 102, 170,   5, 104, 171,   5, 101,   0, 100, 108,   1,
 102, 172,   5, 104, 173,   5, 101,   0, 100, 108,   1, 102, 174,   5, 104, 175,
   5, 101,   0, 100, 108,   1, 102, 176,   5, 104, 177,   5, 101,   0, 100, 108,
   1, 102, 178,   5, 104, 179,   5, 101,   0, 100, 108,   1, 102, 180,   5, 104,
 181,   5, 101,   0, 100, 108,   1, 102, 182,   5, 104, 183,   5, 101,   0, 100,
 108,   1, 102, 184,   5, 104, 185,   5,  71,   0,   0, 152,   2,   2,   1,   3,
   4,  21, 208,  48,  94, 224,   5,  44, 240,   2, 104, 224,   5,  94, 225,   5,
  44, 242,   2, 104, 225,   5,  71,   0,   0, 153,   2,   1,   1,   4,   5,   6,
 208,  48, 208,  73,   0,  71,   0,   0, 154,   2,   2,   1,   1,   3,  22, 208,
  48, 101,   0,  93,  43, 102,  43,  48,  93, 229,   5, 102, 229,   5,  88,  16,
  29, 104, 228,   5,  71,   0,   0, 155,   2,   1,   1,   3,   4,   3, 208,  48,
  71,   0,   0, 162,   2,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,
   0,   0, 163,   2,   2,   1,   1,   3,  22, 208,  48, 101,   0,  93,  43, 102,
  43,  48,  93, 238,   5, 102, 238,   5,  88,  17,  29, 104, 231,   5,  71,   0,
   0};


/* versioned_uris */
const char* const shell_toplevel_versioned_uris[] = {
    "__AS3__.vec", // [660]
    "avmplus", // [660]
    "flash.errors", // [660]
    "flash.sampler", // [660]
    "flash.system", // [660]
    "flash.utils", // [660]
    NULL
};

} }
