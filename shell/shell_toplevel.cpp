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

const uint32_t shell_toplevel_abc_class_count = 39;
const uint32_t shell_toplevel_abc_script_count = 7;
const uint32_t shell_toplevel_abc_method_count = 237;
const uint32_t shell_toplevel_abc_length = 14011;

/* thunks (39 unique signatures, 63 total) */

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
double avmplus_MI_plus_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::MIObject* const obj = (::avmshell::MIObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    double const ret = obj->::avmshell::MIObjectImpl::plus(
        AvmThunkUnbox_double(argv[argoff1])
    );
    return ret;
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
AvmBox avmplus_System_ns_example_nstest_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->ns_example_nstest();
    return kAvmThunkUndefined;
}
AvmBox avmplus_System_isGlobal_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBool32 const ret = obj->isGlobal(
        AvmThunkUnbox_AvmBox(argv[argoff1])
    );
    return (AvmBox) ret;
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

// avmplus_System_exec
AvmBox shell_toplevel_i2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
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

// avmplus_System_isGlobal
AvmBox shell_toplevel_b2a_oa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBool32 const ret = obj->isGlobal(
        AvmThunkUnbox_AvmBox(argv[argoff1])
    );
    return (AvmBox) ret;
}

// avmplus_File_read
AvmBox shell_toplevel_s2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
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

// avmplus_System_debugger
// avmplus_System_forceFullCollection
// avmplus_System_ns_example_nstest
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

// avmplus_MI_plus
double shell_toplevel_d2d_od_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::MIObject* const obj = (::avmshell::MIObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    double const ret = obj->::avmshell::MIObjectImpl::plus(
        AvmThunkUnbox_double(argv[argoff1])
    );
    return ret;
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

// avmplus_System_exit
AvmBox shell_toplevel_v2a_oi_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
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
    static const uint16_t s_slotsOffsetMIClass = 0;
    static const uint16_t s_slotsOffsetMIObject = 0;
    #ifdef DEBUG
    static void doMIClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
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
    static const uint16_t s_slotsOffsetJObjectClass = 0;
    static const uint16_t s_slotsOffsetJObject = 0;
    #ifdef DEBUG
    static void doJObjectClassAsserts(Traits* cTraits, Traits* iTraits);
    #endif
};
#ifdef DEBUG
REALLY_INLINE void SlotOffsetsAndAsserts::doMIClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::MIClass::EmptySlotsStruct_MIClass) >= 0);
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::MIObject::EmptySlotsStruct_MIObject) >= 0);
}
REALLY_INLINE void SlotOffsetsAndAsserts::doSystemClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    MMGC_STATIC_ASSERT(offsetof(::avmshell::SystemClass, m_slots_SystemClass) == s_slotsOffsetSystemClass);
    MMGC_STATIC_ASSERT(offsetof(::avmshell::SystemClass, m_slots_SystemClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(::avmshell::SystemClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(cTraits, 39) == (offsetof(::avmshell::SystemClass, m_slots_SystemClass) + offsetof(_avmshell_SystemClassSlots, m_argv)));
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
    AvmAssert(getSlotOffset(iTraits, 342) == (offsetof(StackFrameObject, m_slots_StackFrameObject) + offsetof(StackFrameObjectSlots, m_name)));
    AvmAssert(getSlotOffset(iTraits, 343) == (offsetof(StackFrameObject, m_slots_StackFrameObject) + offsetof(StackFrameObjectSlots, m_file)));
    AvmAssert(getSlotOffset(iTraits, 344) == (offsetof(StackFrameObject, m_slots_StackFrameObject) + offsetof(StackFrameObjectSlots, m_line)));
    AvmAssert(getSlotOffset(iTraits, 345) == (offsetof(StackFrameObject, m_slots_StackFrameObject) + offsetof(StackFrameObjectSlots, m_scriptID)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::doSampleClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(SampleClass::EmptySlotsStruct_SampleClass) >= 0);
    MMGC_STATIC_ASSERT(offsetof(SampleObject, m_slots_SampleObject) == s_slotsOffsetSampleObject);
    MMGC_STATIC_ASSERT(offsetof(SampleObject, m_slots_SampleObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(SampleObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(iTraits, 348) == (offsetof(SampleObject, m_slots_SampleObject) + offsetof(SampleObjectSlots, m_time)));
    AvmAssert(getSlotOffset(iTraits, 349) == (offsetof(SampleObject, m_slots_SampleObject) + offsetof(SampleObjectSlots, m_stack)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::doNewObjectSampleClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(NewObjectSampleClass::EmptySlotsStruct_NewObjectSampleClass) >= 0);
    MMGC_STATIC_ASSERT(offsetof(NewObjectSampleObject, m_slots_NewObjectSampleObject) == s_slotsOffsetNewObjectSampleObject);
    MMGC_STATIC_ASSERT(offsetof(NewObjectSampleObject, m_slots_NewObjectSampleObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(NewObjectSampleObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(iTraits, 351) == (offsetof(NewObjectSampleObject, m_slots_NewObjectSampleObject) + offsetof(NewObjectSampleObjectSlots, m_id)));
    AvmAssert(getSlotOffset(iTraits, 352) == (offsetof(NewObjectSampleObject, m_slots_NewObjectSampleObject) + offsetof(NewObjectSampleObjectSlots, m_type)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::doDeleteObjectSampleClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(DeleteObjectSampleClass::EmptySlotsStruct_DeleteObjectSampleClass) >= 0);
    MMGC_STATIC_ASSERT(offsetof(DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) == s_slotsOffsetDeleteObjectSampleObject);
    MMGC_STATIC_ASSERT(offsetof(DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(DeleteObjectSampleObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(iTraits, 351) == (offsetof(DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) + offsetof(DeleteObjectSampleObjectSlots, m_id)));
    AvmAssert(getSlotOffset(iTraits, 354) == (offsetof(DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) + offsetof(DeleteObjectSampleObjectSlots, m_size)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::doTraceClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    MMGC_STATIC_ASSERT(offsetof(TraceClass, m_slots_TraceClass) == s_slotsOffsetTraceClass);
    MMGC_STATIC_ASSERT(offsetof(TraceClass, m_slots_TraceClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(TraceClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(cTraits, 388) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_OFF)));
    AvmAssert(getSlotOffset(cTraits, 389) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_METHODS)));
    AvmAssert(getSlotOffset(cTraits, 390) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_METHODS_WITH_ARGS)));
    AvmAssert(getSlotOffset(cTraits, 391) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_METHODS_AND_LINES)));
    AvmAssert(getSlotOffset(cTraits, 392) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_METHODS_AND_LINES_WITH_ARGS)));
    AvmAssert(getSlotOffset(cTraits, 393) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_FILE)));
    AvmAssert(getSlotOffset(cTraits, 394) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_LISTENER)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::doDictionaryClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(DictionaryClass::EmptySlotsStruct_DictionaryClass) >= 0);
    // MMGC_STATIC_ASSERT(sizeof(DictionaryObject::EmptySlotsStruct_DictionaryObject) >= 0);
}
REALLY_INLINE void SlotOffsetsAndAsserts::doJObjectClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(JObjectClass::EmptySlotsStruct_JObjectClass) >= 0);
    // MMGC_STATIC_ASSERT(sizeof(JObject::EmptySlotsStruct_JObject) >= 0);
}
#endif // DEBUG

AVMTHUNK_NATIVE_CLASS_GLUE(MIClass, ::avmshell::MIClass, SlotOffsetsAndAsserts::doMIClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE_EXACT(SystemClass, ::avmshell::SystemClass, SlotOffsetsAndAsserts::doSystemClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(FileClass, ::avmshell::FileClass, SlotOffsetsAndAsserts::doFileClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE_EXACT(DomainClass, DomainClass, SlotOffsetsAndAsserts::doDomainClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(StackFrameClass, StackFrameClass, SlotOffsetsAndAsserts::doStackFrameClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(SampleClass, SampleClass, SlotOffsetsAndAsserts::doSampleClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(NewObjectSampleClass, NewObjectSampleClass, SlotOffsetsAndAsserts::doNewObjectSampleClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(DeleteObjectSampleClass, DeleteObjectSampleClass, SlotOffsetsAndAsserts::doDeleteObjectSampleClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(TraceClass, TraceClass, SlotOffsetsAndAsserts::doTraceClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE_EXACT(DictionaryClass, DictionaryClass, SlotOffsetsAndAsserts::doDictionaryClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(JObjectClass, JObjectClass, SlotOffsetsAndAsserts::doJObjectClassAsserts)

AVMTHUNK_BEGIN_NATIVE_TABLES(shell_toplevel)

    AVMTHUNK_BEGIN_NATIVE_METHODS(shell_toplevel)
        AVMTHUNK_NATIVE_METHOD(avmplus_MI_plus, ::avmshell::MIObjectImpl::plus)
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
        AVMTHUNK_NATIVE_METHOD(avmplus_System_ns_example_nstest, ::avmshell::SystemClass::ns_example_nstest)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_isGlobal, ::avmshell::SystemClass::isGlobal)
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
        AVMTHUNK_NATIVE_METHOD(avmplus_JObject_create, JObjectClass::create)
        AVMTHUNK_NATIVE_METHOD(avmplus_JObject_createArray, JObjectClass::createArray)
        AVMTHUNK_NATIVE_METHOD(avmplus_JObject_toArray, JObjectClass::toArray)
        AVMTHUNK_NATIVE_METHOD(avmplus_JObject_constructorSignature, JObjectClass::constructorSignature)
        AVMTHUNK_NATIVE_METHOD(avmplus_JObject_methodSignature, JObjectClass::methodSignature)
        AVMTHUNK_NATIVE_METHOD(avmplus_JObject_fieldSignature, JObjectClass::fieldSignature)
    AVMTHUNK_END_NATIVE_METHODS()

    AVMTHUNK_BEGIN_NATIVE_CLASSES(shell_toplevel)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_MI, MIClass, ::avmshell::MIClass, SlotOffsetsAndAsserts::s_slotsOffsetMIClass, ::avmshell::MIObject, SlotOffsetsAndAsserts::s_slotsOffsetMIObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_System, SystemClass, ::avmshell::SystemClass, SlotOffsetsAndAsserts::s_slotsOffsetSystemClass, ScriptObject, SlotOffsetsAndAsserts::s_slotsOffsetScriptObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_File, FileClass, ::avmshell::FileClass, SlotOffsetsAndAsserts::s_slotsOffsetFileClass, ScriptObject, SlotOffsetsAndAsserts::s_slotsOffsetScriptObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_Domain, DomainClass, DomainClass, SlotOffsetsAndAsserts::s_slotsOffsetDomainClass, DomainObject, SlotOffsetsAndAsserts::s_slotsOffsetDomainObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_StackFrame, StackFrameClass, StackFrameClass, SlotOffsetsAndAsserts::s_slotsOffsetStackFrameClass, StackFrameObject, SlotOffsetsAndAsserts::s_slotsOffsetStackFrameObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_Sample, SampleClass, SampleClass, SlotOffsetsAndAsserts::s_slotsOffsetSampleClass, SampleObject, SlotOffsetsAndAsserts::s_slotsOffsetSampleObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_NewObjectSample, NewObjectSampleClass, NewObjectSampleClass, SlotOffsetsAndAsserts::s_slotsOffsetNewObjectSampleClass, NewObjectSampleObject, SlotOffsetsAndAsserts::s_slotsOffsetNewObjectSampleObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_DeleteObjectSample, DeleteObjectSampleClass, DeleteObjectSampleClass, SlotOffsetsAndAsserts::s_slotsOffsetDeleteObjectSampleClass, DeleteObjectSampleObject, SlotOffsetsAndAsserts::s_slotsOffsetDeleteObjectSampleObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_trace_Trace, TraceClass, TraceClass, SlotOffsetsAndAsserts::s_slotsOffsetTraceClass, ScriptObject, SlotOffsetsAndAsserts::s_slotsOffsetScriptObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_utils_Dictionary, DictionaryClass, DictionaryClass, SlotOffsetsAndAsserts::s_slotsOffsetDictionaryClass, DictionaryObject, SlotOffsetsAndAsserts::s_slotsOffsetDictionaryObject, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_JObject, JObjectClass, JObjectClass, SlotOffsetsAndAsserts::s_slotsOffsetJObjectClass, JObject, SlotOffsetsAndAsserts::s_slotsOffsetJObject, false)
    AVMTHUNK_END_NATIVE_CLASSES()

AVMTHUNK_END_NATIVE_TABLES()

AVMTHUNK_DEFINE_NATIVE_INITIALIZER(shell_toplevel)

/* abc */
const uint8_t shell_toplevel_abc_data[14011] = {
  16,   0,  46,   0,  13, 148,   5, 149,   5, 150,   5, 151,   5, 152,   5, 153,
   5, 154,   5,   0,   2,   1,   3,   4,   0,   0, 197,   2,   0,   4, 118, 111,
 105, 100,   7,  66, 111, 111, 108, 101,  97, 110,   6,  83, 121, 115, 116, 101,
 109,  19, 115, 104, 101, 108, 108,  95, 116, 111, 112, 108, 101, 118, 101, 108,
  46,  97, 115,  36,  49,   7,  97, 118, 109, 112, 108, 117, 115,   8, 114, 101,
  97, 100,  76, 105, 110, 101,   6,  83, 116, 114, 105, 110, 103,   8, 103, 101,
 116,  84, 105, 109, 101, 114,   4, 117, 105, 110, 116,   5, 116, 114,  97,  99,
 101,   6,  68, 111, 109,  97, 105, 110,  13,  99, 117, 114, 114, 101, 110, 116,
  68, 111, 109,  97, 105, 110,   8, 103, 101, 116,  67, 108,  97, 115, 115,   5,
  67, 108,  97, 115, 115,   8, 100, 101,  98, 117, 103, 103, 101, 114,  13,  97,
 118, 109, 112, 108, 117, 115,  58,  73,  84, 101, 115, 116,   4, 116, 101, 115,
 116,   5,  73,  84, 101, 115, 116,  13,  97, 118, 109, 112, 108, 117, 115,  58,
  67,  84, 101, 115, 116,   3, 238, 138, 148,   5,  67,  84, 101, 115, 116,   6,
  79,  98, 106, 101,  99, 116,  10,  97, 118, 109, 112, 108, 117, 115,  58,  77,
  73,   6,  78, 117, 109,  98, 101, 114,   4, 112, 108, 117, 115,   2,  77,  73,
  14,  97, 118, 109, 112, 108, 117, 115,  58,  83, 121, 115, 116, 101, 109,   4,
  97, 114, 103, 118,   7, 103, 101, 116,  65, 114, 103, 118,   3, 105, 110, 116,
   5,  65, 114, 114,  97, 121,   3,  88,  77,  76,   4, 101, 120, 105, 116,   3,
 102, 111, 111,   4, 101, 120, 101,  99,   3,  98,  97, 114,   4,  97, 116, 116,
 114,   8, 119, 104,  97, 116, 101, 118, 101, 114,  17, 103, 101, 116,  65, 118,
 109, 112, 108, 117, 115,  86, 101, 114, 115, 105, 111, 110,  11, 103, 101, 116,
  70, 101,  97, 116, 117, 114, 101, 115,  10, 103, 101, 116,  82, 117, 110, 109,
 111, 100, 101,   5, 119, 114, 105, 116, 101,  10, 105, 115,  68, 101,  98, 117,
 103, 103, 101, 114,  11, 116, 111, 116,  97, 108,  77, 101, 109, 111, 114, 121,
  10, 102, 114, 101, 101,  77, 101, 109, 111, 114, 121,  13, 112, 114, 105, 118,
  97, 116, 101,  77, 101, 109, 111, 114, 121,  19, 102, 111, 114,  99, 101,  70,
 117, 108, 108,  67, 111, 108, 108, 101,  99, 116, 105, 111, 110,  15, 113, 117,
 101, 117, 101,  67, 111, 108, 108, 101,  99, 116, 105, 111, 110,  22, 104, 116,
 116, 112,  58,  47,  47, 119, 119, 119,  46, 101, 120,  97, 109, 112, 108, 101,
  46,  99, 111, 109,   6, 110, 115, 116, 101, 115, 116,   8, 105, 115,  71, 108,
 111,  98,  97, 108,  10, 115, 119, 102,  86, 101, 114, 115, 105, 111, 110,  10,
  97, 112, 105,  86, 101, 114, 115, 105, 111, 110,  10, 100, 105, 115, 112, 111,
 115, 101,  88,  77,  76,  12,  97, 118, 109, 112, 108, 117, 115,  58,  70, 105,
 108, 101,  11, 102, 108,  97, 115, 104,  46, 117, 116, 105, 108, 115,   9,  66,
 121, 116, 101,  65, 114, 114,  97, 121,   6, 101, 120, 105, 115, 116, 115,   4,
 114, 101,  97, 100,  13, 114, 101,  97, 100,  66, 121, 116, 101,  65, 114, 114,
  97, 121,  14, 119, 114, 105, 116, 101,  66, 121, 116, 101,  65, 114, 114,  97,
 121,   4,  70, 105, 108, 101,  25, 102, 108,  97, 115, 104,  46, 115, 121, 115,
 116, 101, 109,  58,  67,  97, 112,  97,  98, 105, 108, 105, 116, 105, 101, 115,
   7,  65,  86,  77,  80, 108, 117, 115,  12, 102, 108,  97, 115, 104,  46, 115,
 121, 115, 116, 101, 109,  10, 112, 108,  97, 121, 101, 114,  84, 121, 112, 101,
  12,  67,  97, 112,  97,  98, 105, 108, 105, 116, 105, 101, 115,  21,  97, 118,
 109, 115, 104, 101, 108, 108,  58, 112, 117,  98, 108, 105,  99,  95,  99, 108,
  97, 115, 115,  10, 112, 117,  98, 108, 105,  99,  95, 118,  97, 114,  17, 112,
 117,  98, 108, 105,  99,  95, 118,  97, 114,  95,  70,  80,  95,  57,  95,  48,
   3,  65,  80,  73,   3,  54,  54,  48,   3, 238, 138, 149,  18, 112, 117,  98,
 108, 105,  99,  95, 118,  97, 114,  95,  65,  73,  82,  95,  49,  95,  48,   3,
  54,  54,  49,   3, 238, 138, 150,  18, 112, 117,  98, 108, 105,  99,  95, 118,
  97, 114,  95,  70,  80,  95,  49,  48,  95,  48,   3,  54,  54,  50,   3, 238,
 138, 151,  18, 112, 117,  98, 108, 105,  99,  95, 118,  97, 114,  95,  65,  73,
  82,  95,  49,  95,  53,   3,  54,  54,  51,   3, 238, 138, 152,  20, 112, 117,
  98, 108, 105,  99,  95, 118,  97, 114,  95,  65,  73,  82,  95,  49,  95,  53,
  95,  49,   3,  54,  54,  52,   3, 238, 138, 153,  21, 112, 117,  98, 108, 105,
  99,  95, 118,  97, 114,  95,  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,
   3,  54,  54,  53,   3, 238, 138, 154,  20, 112, 117,  98, 108, 105,  99,  95,
 118,  97, 114,  95,  65,  73,  82,  95,  49,  95,  53,  95,  50,   3,  54,  54,
  54,  26, 112, 117,  98, 108, 105,  99,  95, 118,  97, 114,  95,  65,  73,  82,
  95,  49,  95,  48,  95,  70,  80,  95,  49,  48,  95,  48,  27, 112, 117,  98,
 108, 105,  99,  95, 118,  97, 114,  95,  65,  73,  82,  95,  49,  95,  53,  95,
  50,  95,  70,  80,  95,  57,  95,  48,  38, 112, 117,  98, 108, 105,  99,  95,
 118,  97, 114,  95,  65,  73,  82,  95,  49,  95,  53,  95,  49,  95,  70,  80,
  95,  49,  48,  95,  48,  95,  65,  73,  82,  95,  49,  95,  53,  95,  50,  44,
 112, 117,  98, 108, 105,  99,  95, 118,  97, 114,  95,  70,  80,  95,  49,  48,
  95,  48,  95,  51,  50,  95,  70,  80,  95,  57,  95,  48,  95,  65,  73,  82,
  95,  49,  95,  48,  95,  70,  80,  95,  49,  48,  95,  48,  12, 112, 117,  98,
 108, 105,  99,  95,  99, 111, 110, 115, 116,  19, 112, 117,  98, 108, 105,  99,
  95,  99, 111, 110, 115, 116,  95,  70,  80,  95,  57,  95,  48,  20, 112, 117,
  98, 108, 105,  99,  95,  99, 111, 110, 115, 116,  95,  65,  73,  82,  95,  49,
  95,  48,  20, 112, 117,  98, 108, 105,  99,  95,  99, 111, 110, 115, 116,  95,
  70,  80,  95,  49,  48,  95,  48,  20, 112, 117,  98, 108, 105,  99,  95,  99,
 111, 110, 115, 116,  95,  65,  73,  82,  95,  49,  95,  53,  22, 112, 117,  98,
 108, 105,  99,  95,  99, 111, 110, 115, 116,  95,  65,  73,  82,  95,  49,  95,
  53,  95,  49,  23, 112, 117,  98, 108, 105,  99,  95,  99, 111, 110, 115, 116,
  95,  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,  22, 112, 117,  98, 108,
 105,  99,  95,  99, 111, 110, 115, 116,  95,  65,  73,  82,  95,  49,  95,  53,
  95,  50,  28, 112, 117,  98, 108, 105,  99,  95,  99, 111, 110, 115, 116,  95,
  65,  73,  82,  95,  49,  95,  48,  95,  70,  80,  95,  49,  48,  95,  48,  29,
 112, 117,  98, 108, 105,  99,  95,  99, 111, 110, 115, 116,  95,  65,  73,  82,
  95,  49,  95,  53,  95,  50,  95,  70,  80,  95,  57,  95,  48,  40, 112, 117,
  98, 108, 105,  99,  95,  99, 111, 110, 115, 116,  95,  65,  73,  82,  95,  49,
  95,  53,  95,  49,  95,  70,  80,  95,  49,  48,  95,  48,  95,  65,  73,  82,
  95,  49,  95,  53,  95,  50,  46, 112, 117,  98, 108, 105,  99,  95,  99, 111,
 110, 115, 116,  95,  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,  95,  70,
  80,  95,  57,  95,  48,  95,  65,  73,  82,  95,  49,  95,  48,  95,  70,  80,
  95,  49,  48,  95,  48,  15, 112, 117,  98, 108, 105,  99,  95, 102, 117, 110,
  99, 116, 105, 111, 110,  22, 112, 117,  98, 108, 105,  99,  95, 102, 117, 110,
  99, 116, 105, 111, 110,  95,  70,  80,  95,  57,  95,  48,  23, 112, 117,  98,
 108, 105,  99,  95, 102, 117, 110,  99, 116, 105, 111, 110,  95,  65,  73,  82,
  95,  49,  95,  48,  23, 112, 117,  98, 108, 105,  99,  95, 102, 117, 110,  99,
 116, 105, 111, 110,  95,  70,  80,  95,  49,  48,  95,  48,  23, 112, 117,  98,
 108, 105,  99,  95, 102, 117, 110,  99, 116, 105, 111, 110,  95,  65,  73,  82,
  95,  49,  95,  53,  25, 112, 117,  98, 108, 105,  99,  95, 102, 117, 110,  99,
 116, 105, 111, 110,  95,  65,  73,  82,  95,  49,  95,  53,  95,  49,  26, 112,
 117,  98, 108, 105,  99,  95, 102, 117, 110,  99, 116, 105, 111, 110,  95,  70,
  80,  95,  49,  48,  95,  48,  95,  51,  50,  25, 112, 117,  98, 108, 105,  99,
  95, 102, 117, 110,  99, 116, 105, 111, 110,  95,  65,  73,  82,  95,  49,  95,
  53,  95,  50,  31, 112, 117,  98, 108, 105,  99,  95, 102, 117, 110,  99, 116,
 105, 111, 110,  95,  65,  73,  82,  95,  49,  95,  48,  95,  70,  80,  95,  49,
  48,  95,  48,  32, 112, 117,  98, 108, 105,  99,  95, 102, 117, 110,  99, 116,
 105, 111, 110,  95,  65,  73,  82,  95,  49,  95,  53,  95,  50,  95,  70,  80,
  95,  57,  95,  48,  43, 112, 117,  98, 108, 105,  99,  95, 102, 117, 110,  99,
 116, 105, 111, 110,  95,  65,  73,  82,  95,  49,  95,  53,  95,  49,  95,  70,
  80,  95,  49,  48,  95,  48,  95,  65,  73,  82,  95,  49,  95,  53,  95,  50,
  49, 112, 117,  98, 108, 105,  99,  95, 102, 117, 110,  99, 116, 105, 111, 110,
  95,  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,  95,  70,  80,  95,  57,
  95,  48,  95,  65,  73,  82,  95,  49,  95,  48,  95,  70,  80,  95,  49,  48,
  95,  48,  13, 112, 117,  98, 108, 105,  99,  95, 103, 101, 116, 115, 101, 116,
  20, 112, 117,  98, 108, 105,  99,  95, 103, 101, 116, 115, 101, 116,  95,  70,
  80,  95,  57,  95,  48,  21, 112, 117,  98, 108, 105,  99,  95, 103, 101, 116,
 115, 101, 116,  95,  65,  73,  82,  95,  49,  95,  48,  21, 112, 117,  98, 108,
 105,  99,  95, 103, 101, 116, 115, 101, 116,  95,  70,  80,  95,  49,  48,  95,
  48,  21, 112, 117,  98, 108, 105,  99,  95, 103, 101, 116, 115, 101, 116,  95,
  65,  73,  82,  95,  49,  95,  53,  23, 112, 117,  98, 108, 105,  99,  95, 103,
 101, 116, 115, 101, 116,  95,  65,  73,  82,  95,  49,  95,  53,  95,  49,  24,
 112, 117,  98, 108, 105,  99,  95, 103, 101, 116, 115, 101, 116,  95,  70,  80,
  95,  49,  48,  95,  48,  95,  51,  50,  23, 112, 117,  98, 108, 105,  99,  95,
 103, 101, 116, 115, 101, 116,  95,  65,  73,  82,  95,  49,  95,  53,  95,  50,
  29, 112, 117,  98, 108, 105,  99,  95, 103, 101, 116, 115, 101, 116,  95,  65,
  73,  82,  95,  49,  95,  48,  95,  70,  80,  95,  49,  48,  95,  48,  30, 112,
 117,  98, 108, 105,  99,  95, 103, 101, 116, 115, 101, 116,  95,  65,  73,  82,
  95,  49,  95,  53,  95,  50,  95,  70,  80,  95,  57,  95,  48,  41, 112, 117,
  98, 108, 105,  99,  95, 103, 101, 116, 115, 101, 116,  95,  65,  73,  82,  95,
  49,  95,  53,  95,  49,  95,  70,  80,  95,  49,  48,  95,  48,  95,  65,  73,
  82,  95,  49,  95,  53,  95,  50,  47, 112, 117,  98, 108, 105,  99,  95, 103,
 101, 116, 115, 101, 116,  95,  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,
  95,  70,  80,  95,  57,  95,  48,  95,  65,  73,  82,  95,  49,  95,  48,  95,
  70,  80,  95,  49,  48,  95,  48,   8,  97, 118, 109, 115, 104, 101, 108, 108,
  12, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  28,  97, 118,
 109, 115, 104, 101, 108, 108,  58, 112, 117,  98, 108, 105,  99,  95,  99, 108,
  97, 115, 115,  95,  70,  80,  95,  57,  95,  48,  19, 112, 117,  98, 108, 105,
  99,  95,  99, 108,  97, 115, 115,  95,  70,  80,  95,  57,  95,  48,  29,  97,
 118, 109, 115, 104, 101, 108, 108,  58, 112, 117,  98, 108, 105,  99,  95,  99,
 108,  97, 115, 115,  95,  65,  73,  82,  95,  49,  95,  48,  20, 112, 117,  98,
 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  65,  73,  82,  95,  49,  95,
  48,  29,  97, 118, 109, 115, 104, 101, 108, 108,  58, 112, 117,  98, 108, 105,
  99,  95,  99, 108,  97, 115, 115,  95,  70,  80,  95,  49,  48,  95,  48,  20,
 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  70,  80,  95,
  49,  48,  95,  48,  29,  97, 118, 109, 115, 104, 101, 108, 108,  58, 112, 117,
  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  65,  73,  82,  95,  49,
  95,  53,  20, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,
  65,  73,  82,  95,  49,  95,  53,  31,  97, 118, 109, 115, 104, 101, 108, 108,
  58, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  65,  73,
  82,  95,  49,  95,  53,  95,  49,  22, 112, 117,  98, 108, 105,  99,  95,  99,
 108,  97, 115, 115,  95,  65,  73,  82,  95,  49,  95,  53,  95,  49,  32,  97,
 118, 109, 115, 104, 101, 108, 108,  58, 112, 117,  98, 108, 105,  99,  95,  99,
 108,  97, 115, 115,  95,  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,  23,
 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  70,  80,  95,
  49,  48,  95,  48,  95,  51,  50,  31,  97, 118, 109, 115, 104, 101, 108, 108,
  58, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  65,  73,
  82,  95,  49,  95,  53,  95,  50,  22, 112, 117,  98, 108, 105,  99,  95,  99,
 108,  97, 115, 115,  95,  65,  73,  82,  95,  49,  95,  53,  95,  50,  37,  97,
 118, 109, 115, 104, 101, 108, 108,  58, 112, 117,  98, 108, 105,  99,  95,  99,
 108,  97, 115, 115,  95,  65,  73,  82,  95,  49,  95,  48,  95,  70,  80,  95,
  49,  48,  95,  48,  28, 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115,
 115,  95,  65,  73,  82,  95,  49,  95,  48,  95,  70,  80,  95,  49,  48,  95,
  48,  38,  97, 118, 109, 115, 104, 101, 108, 108,  58, 112, 117,  98, 108, 105,
  99,  95,  99, 108,  97, 115, 115,  95,  65,  73,  82,  95,  49,  95,  53,  95,
  50,  95,  70,  80,  95,  57,  95,  48,  29, 112, 117,  98, 108, 105,  99,  95,
  99, 108,  97, 115, 115,  95,  65,  73,  82,  95,  49,  95,  53,  95,  50,  95,
  70,  80,  95,  57,  95,  48,  49,  97, 118, 109, 115, 104, 101, 108, 108,  58,
 112, 117,  98, 108, 105,  99,  95,  99, 108,  97, 115, 115,  95,  65,  73,  82,
  95,  49,  95,  53,  95,  49,  95,  70,  80,  95,  49,  48,  95,  48,  95,  65,
  73,  82,  95,  49,  95,  53,  95,  50,  40, 112, 117,  98, 108, 105,  99,  95,
  99, 108,  97, 115, 115,  95,  65,  73,  82,  95,  49,  95,  53,  95,  49,  95,
  70,  80,  95,  49,  48,  95,  48,  95,  65,  73,  82,  95,  49,  95,  53,  95,
  50,  55,  97, 118, 109, 115, 104, 101, 108, 108,  58, 112, 117,  98, 108, 105,
  99,  95,  99, 108,  97, 115, 115,  95,  70,  80,  95,  49,  48,  95,  48,  95,
  51,  50,  95,  70,  80,  95,  57,  95,  48,  95,  65,  73,  82,  95,  49,  95,
  48,  95,  70,  80,  95,  49,  48,  95,  48,  46, 112, 117,  98, 108, 105,  99,
  95,  99, 108,  97, 115, 115,  95,  70,  80,  95,  49,  48,  95,  48,  95,  51,
  50,  95,  70,  80,  95,  57,  95,  48,  95,  65,  73,  82,  95,  49,  95,  48,
  95,  70,  80,  95,  49,  48,  95,  48,  16, 112, 117,  98, 108, 105,  99,  95,
 105, 110, 116, 101, 114, 102,  97,  99, 101,  23, 112, 117,  98, 108, 105,  99,
  95, 105, 110, 116, 101, 114, 102,  97,  99, 101,  95,  70,  80,  95,  57,  95,
  48,  24, 112, 117,  98, 108, 105,  99,  95, 105, 110, 116, 101, 114, 102,  97,
  99, 101,  95,  65,  73,  82,  95,  49,  95,  48,  24, 112, 117,  98, 108, 105,
  99,  95, 105, 110, 116, 101, 114, 102,  97,  99, 101,  95,  70,  80,  95,  49,
  48,  95,  48,  24, 112, 117,  98, 108, 105,  99,  95, 105, 110, 116, 101, 114,
 102,  97,  99, 101,  95,  65,  73,  82,  95,  49,  95,  53,  26, 112, 117,  98,
 108, 105,  99,  95, 105, 110, 116, 101, 114, 102,  97,  99, 101,  95,  65,  73,
  82,  95,  49,  95,  53,  95,  49,  27, 112, 117,  98, 108, 105,  99,  95, 105,
 110, 116, 101, 114, 102,  97,  99, 101,  95,  70,  80,  95,  49,  48,  95,  48,
  95,  51,  50,  26, 112, 117,  98, 108, 105,  99,  95, 105, 110, 116, 101, 114,
 102,  97,  99, 101,  95,  65,  73,  82,  95,  49,  95,  53,  95,  50,  32, 112,
 117,  98, 108, 105,  99,  95, 105, 110, 116, 101, 114, 102,  97,  99, 101,  95,
  65,  73,  82,  95,  49,  95,  48,  95,  70,  80,  95,  49,  48,  95,  48,  33,
 112, 117,  98, 108, 105,  99,  95, 105, 110, 116, 101, 114, 102,  97,  99, 101,
  95,  65,  73,  82,  95,  49,  95,  53,  95,  50,  95,  70,  80,  95,  57,  95,
  48,  44, 112, 117,  98, 108, 105,  99,  95, 105, 110, 116, 101, 114, 102,  97,
  99, 101,  95,  65,  73,  82,  95,  49,  95,  53,  95,  49,  95,  70,  80,  95,
  49,  48,  95,  48,  95,  65,  73,  82,  95,  49,  95,  53,  95,  50,  50, 112,
 117,  98, 108, 105,  99,  95, 105, 110, 116, 101, 114, 102,  97,  99, 101,  95,
  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,  95,  70,  80,  95,  57,  95,
  48,  95,  65,  73,  82,  95,  49,  95,  48,  95,  70,  80,  95,  49,  48,  95,
  48,  10,  65,  80,  73,  95,  70,  80,  95,  57,  95,  48,  11,  65,  80,  73,
  95,  65,  73,  82,  95,  49,  95,  48,  11,  65,  80,  73,  95,  70,  80,  95,
  49,  48,  95,  48,  11,  65,  80,  73,  95,  65,  73,  82,  95,  49,  95,  53,
  13,  65,  80,  73,  95,  65,  73,  82,  95,  49,  95,  53,  95,  49,  14,  65,
  80,  73,  95,  70,  80,  95,  49,  48,  95,  48,  95,  51,  50,  13,  65,  80,
  73,  95,  65,  73,  82,  95,  49,  95,  53,  95,  50,  10, 110, 115,  95, 101,
 120,  97, 109, 112, 108, 101,   6, 110,  97, 116, 105, 118, 101,   3,  99, 108,
 115,  19,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  77,  73,
  67, 108,  97, 115, 115,   8, 105, 110, 115, 116,  97, 110,  99, 101,  20,  58,
  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  77,  73,  79,  98, 106,
 101,  99, 116,   7, 109, 101, 116, 104, 111, 100, 115,  24,  58,  58,  97, 118,
 109, 115, 104, 101, 108, 108,  58,  58,  77,  73,  79,  98, 106, 101,  99, 116,
  73, 109, 112, 108,  10,  97, 118, 109, 112, 108, 117, 115, 238, 138, 148,  23,
  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  83, 121, 115, 116,
 101, 109,  67, 108,  97, 115, 115,   7,  99, 108,  97, 115, 115, 103,  99,   5,
 101, 120,  97,  99, 116,   4,  97, 117, 116, 111,  21,  58,  58,  97, 118, 109,
 115, 104, 101, 108, 108,  58,  58,  70, 105, 108, 101,  67, 108,  97, 115, 115,
  15, 102, 108,  97, 115, 104,  46, 115, 121, 115, 116, 101, 109, 238, 138, 148,
  14, 103, 101, 116,  67, 108,  97, 115, 115,  66, 121,  78,  97, 109, 101,   5,
 112, 114, 105, 110, 116,  11,  97, 118, 109, 115, 104, 101, 108, 108, 238, 138,
 148,  11,  97, 118, 109, 115, 104, 101, 108, 108, 238, 138, 149,  11,  97, 118,
 109, 115, 104, 101, 108, 108, 238, 138, 150,  11,  97, 118, 109, 115, 104, 101,
 108, 108, 238, 138, 151,  11,  97, 118, 109, 115, 104, 101, 108, 108, 238, 138,
 152,  11,  97, 118, 109, 115, 104, 101, 108, 108, 238, 138, 153,  11,  97, 118,
 109, 115, 104, 101, 108, 108, 238, 138, 154,  14,  97, 118, 109, 112, 108, 117,
 115,  58,  68, 111, 109,  97, 105, 110,   4, 105, 110, 105, 116,  11,  68, 111,
 109,  97, 105, 110,  46,  97, 115,  36,  50,   9, 108, 111,  97, 100,  66, 121,
 116, 101, 115,  24,  77,  73,  78,  95,  68,  79,  77,  65,  73,  78,  95,  77,
  69,  77,  79,  82,  89,  95,  76,  69,  78,  71,  84,  72,   4, 108, 111,  97,
 100,  12, 100, 111, 109,  97, 105, 110,  77, 101, 109, 111, 114, 121,  11,  68,
 111, 109,  97, 105, 110,  67, 108,  97, 115, 115,   2, 103,  99,  12,  68, 111,
 109,  97, 105, 110,  79,  98, 106, 101,  99, 116,   8,  70, 117, 110,  99, 116,
 105, 111, 110,   5,  81,  78,  97, 109, 101,  19,  95, 103, 101, 116,  73, 110,
 118, 111,  99,  97, 116, 105, 111, 110,  67, 111, 117, 110, 116,  12,  83,  97,
 109, 112, 108, 101, 114,  46,  97, 115,  36,  51,  13, 102, 108,  97, 115, 104,
  46, 115,  97, 109, 112, 108, 101, 114,   1, 102,   1, 101,   3, 114, 101, 116,
  19,  95, 115, 101, 116,  83,  97, 109, 112, 108, 101, 114,  67,  97, 108, 108,
  98,  97,  99, 107,   7, 119, 114,  97, 112, 112, 101, 114,  24, 102, 108,  97,
 115, 104,  46, 115,  97, 109, 112, 108, 101, 114,  58,  83, 116,  97,  99, 107,
  70, 114,  97, 109, 101,   4, 110,  97, 109, 101,   2,  40,  41,   4, 102, 105,
 108, 101,   1,  91,   1,  58,   4, 108, 105, 110, 101,   1,  93,   8, 115,  99,
 114, 105, 112, 116,  73,  68,   8, 116, 111,  83, 116, 114, 105, 110, 103,  10,
  83, 116,  97,  99, 107,  70, 114,  97, 109, 101,  20, 102, 108,  97, 115, 104,
  46, 115,  97, 109, 112, 108, 101, 114,  58,  83,  97, 109, 112, 108, 101,   4,
 116, 105, 109, 101,   5, 115, 116,  97,  99, 107,   6,  83,  97, 109, 112, 108,
 101,  29, 102, 108,  97, 115, 104,  46, 115,  97, 109, 112, 108, 101, 114,  58,
  78, 101, 119,  79,  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,   2,
 105, 100,   4, 116, 121, 112, 101,   6, 111,  98, 106, 101,  99, 116,   4, 115,
 105, 122, 101,  15,  78, 101, 119,  79,  98, 106, 101,  99, 116,  83,  97, 109,
 112, 108, 101,  32, 102, 108,  97, 115, 104,  46, 115,  97, 109, 112, 108, 101,
 114,  58,  68, 101, 108, 101, 116, 101,  79,  98, 106, 101,  99, 116,  83,  97,
 109, 112, 108, 101,  18,  68, 101, 108, 101, 116, 101,  79,  98, 106, 101,  99,
 116,  83,  97, 109, 112, 108, 101,  16, 102, 108,  97, 115, 104,  46, 115,  97,
 109, 112, 108, 101, 114, 238, 138, 148,  15,  83, 116,  97,  99, 107,  70, 114,
  97, 109, 101,  67, 108,  97, 115, 115,  16,  83, 116,  97,  99, 107,  70, 114,
  97, 109, 101,  79,  98, 106, 101,  99, 116,  12,  99, 111, 110, 115, 116, 115,
 101, 116, 116, 101, 114, 115,   4, 116, 114, 117, 101,  11,  83,  97, 109, 112,
 108, 101,  67, 108,  97, 115, 115,  12,  83,  97, 109, 112, 108, 101,  79,  98,
 106, 101,  99, 116,  20,  78, 101, 119,  79,  98, 106, 101,  99, 116,  83,  97,
 109, 112, 108, 101,  67, 108,  97, 115, 115,  21,  78, 101, 119,  79,  98, 106,
 101,  99, 116,  83,  97, 109, 112, 108, 101,  79,  98, 106, 101,  99, 116,  23,
  68, 101, 108, 101, 116, 101,  79,  98, 106, 101,  99, 116,  83,  97, 109, 112,
 108, 101,  67, 108,  97, 115, 115,  24,  68, 101, 108, 101, 116, 101,  79,  98,
 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  79,  98, 106, 101,  99, 116,
  12,  99, 108, 101,  97, 114,  83,  97, 109, 112, 108, 101, 115,  27,  83,  97,
 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58,  99, 108, 101,
  97, 114,  83,  97, 109, 112, 108, 101, 115,  13, 115, 116,  97, 114, 116,  83,
  97, 109, 112, 108, 105, 110, 103,  28,  83,  97, 109, 112, 108, 101, 114,  83,
  99, 114, 105, 112, 116,  58,  58, 115, 116,  97, 114, 116,  83,  97, 109, 112,
 108, 105, 110, 103,  12, 115, 116, 111, 112,  83,  97, 109, 112, 108, 105, 110,
 103,  27,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,
  58, 115, 116, 111, 112,  83,  97, 109, 112, 108, 105, 110, 103,  13, 112,  97,
 117, 115, 101,  83,  97, 109, 112, 108, 105, 110, 103,  28,  83,  97, 109, 112,
 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 112,  97, 117, 115, 101,
  83,  97, 109, 112, 108, 105, 110, 103,  20, 115,  97, 109, 112, 108, 101,  73,
 110, 116, 101, 114, 110,  97, 108,  65, 108, 108, 111,  99, 115,  35,  83,  97,
 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 115,  97, 109,
 112, 108, 101,  73, 110, 116, 101, 114, 110,  97, 108,  65, 108, 108, 111,  99,
 115,  18, 115, 101, 116,  83,  97, 109, 112, 108, 101, 114,  67,  97, 108, 108,
  98,  97,  99, 107,  34,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105,
 112, 116,  58,  58,  95, 115, 101, 116,  83,  97, 109, 112, 108, 101, 114,  67,
  97, 108, 108,  98,  97,  99, 107,   7, 103, 101, 116,  83, 105, 122, 101,  22,
  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 103,
 101, 116,  83, 105, 122, 101,  14, 103, 101, 116,  77, 101, 109,  98, 101, 114,
  78,  97, 109, 101, 115,  29,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114,
 105, 112, 116,  58,  58, 103, 101, 116,  77, 101, 109,  98, 101, 114,  78,  97,
 109, 101, 115,  10, 103, 101, 116,  83,  97, 109, 112, 108, 101, 115,  25,  83,
  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 103, 101,
 116,  83,  97, 109, 112, 108, 101, 115,  14, 103, 101, 116,  83,  97, 109, 112,
 108, 101,  67, 111, 117, 110, 116,  29,  83,  97, 109, 112, 108, 101, 114,  83,
  99, 114, 105, 112, 116,  58,  58, 103, 101, 116,  83,  97, 109, 112, 108, 101,
  67, 111, 117, 110, 116,  18, 103, 101, 116,  73, 110, 118, 111,  99,  97, 116,
 105, 111, 110,  67, 111, 117, 110, 116,  24, 103, 101, 116,  83, 101, 116, 116,
 101, 114,  73, 110, 118, 111,  99,  97, 116, 105, 111, 110,  67, 111, 117, 110,
 116,  24, 103, 101, 116,  71, 101, 116, 116, 101, 114,  73, 110, 118, 111,  99,
  97, 116, 105, 111, 110,  67, 111, 117, 110, 116,  34,  83,  97, 109, 112, 108,
 101, 114,  83,  99, 114, 105, 112, 116,  58,  58,  95, 103, 101, 116,  73, 110,
 118, 111,  99,  97, 116, 105, 111, 110,  67, 111, 117, 110, 116,  14, 105, 115,
  71, 101, 116, 116, 101, 114,  83, 101, 116, 116, 101, 114,  29,  83,  97, 109,
 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 105, 115,  71, 101,
 116, 116, 101, 114,  83, 101, 116, 116, 101, 114,  16, 103, 101, 116,  76, 101,
 120, 105,  99,  97, 108,  83,  99, 111, 112, 101, 115,  31,  83,  97, 109, 112,
 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 103, 101, 116,  76, 101,
 120, 105,  99,  97, 108,  83,  99, 111, 112, 101, 115,  12, 103, 101, 116,  83,
  97, 118, 101, 100,  84, 104, 105, 115,  27,  83,  97, 109, 112, 108, 101, 114,
  83,  99, 114, 105, 112, 116,  58,  58, 103, 101, 116,  83,  97, 118, 101, 100,
  84, 104, 105, 115,  15, 103, 101, 116,  77,  97, 115, 116, 101, 114,  83, 116,
 114, 105, 110, 103,  30,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105,
 112, 116,  58,  58, 103, 101, 116,  77,  97, 115, 116, 101, 114,  83, 116, 114,
 105, 110, 103,  17, 102, 108,  97, 115, 104,  46, 116, 114,  97,  99, 101,  58,
  84, 114,  97,  99, 101,   3,  79,  70,  70,   7,  77,  69,  84,  72,  79,  68,
  83,  17,  77,  69,  84,  72,  79,  68,  83,  95,  87,  73,  84,  72,  95,  65,
  82,  71,  83,  17,  77,  69,  84,  72,  79,  68,  83,  95,  65,  78,  68,  95,
  76,  73,  78,  69,  83,  27,  77,  69,  84,  72,  79,  68,  83,  95,  65,  78,
  68,  95,  76,  73,  78,  69,  83,  95,  87,  73,  84,  72,  95,  65,  82,  71,
  83,   4,  70,  73,  76,  69,   8,  76,  73,  83,  84,  69,  78,  69,  82,   8,
 115, 101, 116,  76, 101, 118, 101, 108,   8, 103, 101, 116,  76, 101, 118, 101,
 108,  11, 115, 101, 116,  76, 105, 115, 116, 101, 110, 101, 114,  11, 103, 101,
 116,  76, 105, 115, 116, 101, 110, 101, 114,  11, 102, 108,  97, 115, 104,  46,
 116, 114,  97,  99, 101,   5,  84, 114,  97,  99, 101,  10,  84, 114,  97,  99,
 101,  46,  97, 115,  36,  52,  14, 102, 108,  97, 115, 104,  46, 116, 114,  97,
  99, 101, 238, 138, 148,  10,  84, 114,  97,  99, 101,  67, 108,  97, 115, 115,
  22, 102, 108,  97, 115, 104,  46, 117, 116, 105, 108, 115,  58,  68, 105,  99,
 116, 105, 111, 110,  97, 114, 121,  15,  68, 105,  99, 116, 105, 111, 110,  97,
 114, 121,  46,  97, 115,  36,  53,  10,  68, 105,  99, 116, 105, 111, 110,  97,
 114, 121,  14, 102, 108,  97, 115, 104,  46, 117, 116, 105, 108, 115, 238, 138,
 148,  15,  68, 105,  99, 116, 105, 111, 110,  97, 114, 121,  67, 108,  97, 115,
 115,  16,  68, 105,  99, 116, 105, 111, 110,  97, 114, 121,  79,  98, 106, 101,
  99, 116,  18, 102, 108,  97, 115, 104,  46, 117, 116, 105, 108, 115,  58,  69,
 110, 100, 105,  97, 110,  10,  66,  73,  71,  95,  69,  78,  68,  73,  65,  78,
   9,  98, 105, 103,  69, 110, 100, 105,  97, 110,  13,  76,  73,  84,  84,  76,
  69,  95,  69,  78,  68,  73,  65,  78,  12, 108, 105, 116, 116, 108, 101,  69,
 110, 100, 105,  97, 110,   6,  69, 110, 100, 105,  97, 110,  11,  69, 110, 100,
 105,  97, 110,  46,  97, 115,  36,  54,  15,  97, 118, 109, 112, 108, 117, 115,
  58,  74,  79,  98, 106, 101,  99, 116,   7,  74,  79,  98, 106, 101,  99, 116,
   6,  99, 114, 101,  97, 116, 101,  11,  99, 114, 101,  97, 116, 101,  65, 114,
 114,  97, 121,   7, 116, 111,  65, 114, 114,  97, 121,  20,  99, 111, 110, 115,
 116, 114, 117,  99, 116, 111, 114,  83, 105, 103, 110,  97, 116, 117, 114, 101,
  15, 109, 101, 116, 104, 111, 100,  83, 105, 103, 110,  97, 116, 117, 114, 101,
  14, 102, 105, 101, 108, 100,  83, 105, 103, 110,  97, 116, 117, 114, 101,   9,
  74,  97, 118,  97,  46,  97, 115,  36,  55,  12,  74,  79,  98, 106, 101,  99,
 116,  67, 108,  97, 115, 115, 101,  22,   1,   5,   5,  23,   1,  22,   6,  23,
   6,   8,  17,   5,  20,  22,  21,  24,  20,   5,  24,  24,  24,   5,  28,  24,
  28,  26,  28,  26,  23,   8,  50,   5,  56,  22,  57,  24,  56,   5,  64,  22,
  66,  23,  66,  24,  64,  26,  64,   5,  69,  22,  74,  22,  77,  22,  80,  22,
  83,  22,  86,  22,  89,  22, 132,   1,  24,  69,   5, 134,   1,  24, 134,   1,
   5, 136,   1,  24, 136,   1,   5, 138,   1,  24, 138,   1,   5, 140,   1,  24,
 140,   1,   5, 142,   1,  24, 142,   1,   5, 144,   1,  24, 144,   1,   5, 146,
   1,  24, 146,   1,   5, 148,   1,  24, 148,   1,   5, 150,   1,  24, 150,   1,
   5, 152,   1,  24, 152,   1,   5, 154,   1,  24, 154,   1,  23, 132,   1,  22,
 183,   1,  22, 189,   1,  22, 192,   1,  22, 193,   1,  22, 194,   1,  22, 195,
   1,  22, 196,   1,  22, 197,   1,  22, 198,   1,   5, 199,   1,   5, 201,   1,
  24, 199,   1,  26, 199,   1,   5, 212,   1,  22, 213,   1,  23, 213,   1,   5,
 219,   1,  24, 219,   1,  26, 219,   1,   5, 230,   1,  24, 230,   1,   5, 234,
   1,  24, 234,   1,   5, 240,   1,  24, 240,   1,  22, 242,   1,   5, 157,   2,
  22, 169,   2,  24, 157,   2,   5, 171,   2,  23, 169,   2,  22, 172,   2,   5,
 174,   2,   5, 175,   2,  23,  57,  24, 174,   2,  26, 174,   2,  22, 177,   2,
   5, 180,   2,  24, 180,   2,   5, 186,   2,   5, 187,   2,  24, 187,   2,   5,
 195,   2,  53,   4,   1,   2,   3,   4,   4,   1,   2,   4,   5,   1,   6,   1,
   8,   8,   1,   2,   4,   5,  12,  13,  14,  15,   1,  12,   1,  16,   9,   1,
   2,   4,  15,  20,  21,  22,  23,  24,   1,  26,   1,  27,   1,  28,   1,  29,
   1,  30,   1,  31,   2,  26,  27,   2,   8,  31,   3,  27,  29,  31,   4,   8,
  26,  27,  30,   1,   5,   1,   4,   1,  21,   5,   1,   2,   4,  21,  22,   1,
  32,   4,   1,   2,  32,  56,   1,  57,   1,  58,   1,  59,   1,  60,   1,  61,
   1,  62,   1,  63,   1,  64,   1,  65,   2,  60,  61,   2,  59,  65,   3,  61,
  63,  65,   4,  59,  60,  61,  64,   8,   1,   4,   5,  15,  66,  67,  68,  69,
   1,  66,   4,   1,   4,   5,  67,   4,   1,  70,  71,  72,   1,  72,   8,   1,
  15,  70,  71,  72,  73,  74,  75,   1,  82,   4,   1,  84,  86,  87,   1,  88,
   8,   1,  15,  18,  89,  90,  91,  92,  93,   1,  89,   4,   1,  18,  90,  91,
   1,  94,   4,   1,  18,  91,  97,   4,   1,   4,   5, 100, 167,   3,   7,   1,
   2,   7,   1,   3,   9,   4,   1,   9,   7,   1,   7,   1,   8,   9,   9,   1,
   7,   1,  10,   9,  11,   1,   9,  12,   1,   9,  13,   1,   9,  14,   1,   7,
   1,  15,   9,   4,   2,   9,  16,   2,   9,  18,   3,   7,   5,  19,   9,  18,
   4,   7,   5,  22,   7,   1,  23,   7,   1,  25,   9,  26,   4,   7,   5,  27,
   7,   1,  29,   9,  30,   5,   7,   1,  31,   7,   1,  32,   7,   1,  33,   9,
  34,   4,   9,  36,   4,   9,  40,   4,   9,  41,   4,   9,  42,   4,   9,  11,
   4,   9,  43,   4,   9,  16,   4,   9,  44,   4,   9,   9,   4,   9,  30,   6,
   9,  29,   4,   9,   7,   4,   9,  45,   4,   9,  46,   4,   9,  47,   4,   9,
  48,   4,   9,  49,   4,   9,  51,   7,   9,  52,   4,   9,  53,   4,   9,  54,
   4,   9,  55,   4,   7,   4,   4,   7,  18,  58,   9,  59,   4,   9,  60,   4,
   9,  61,   4,   9,  62,   4,   7,   4,  63,   9,   4,   8,   9,  44,   8,   9,
  67,   4,   7,  21,  68,   9,  70,   4,   9,  71,   4,   9,  75,   9,   9,  78,
  10,   9,  81,  11,   9,  84,  12,   9,  87,  13,   9,  90,  14,   9,  92,  15,
   9,  93,  16,   9,  94,  17,   9,  95,  18,   9,  96,   4,   9,  97,   4,   9,
  98,   9,   9,  99,  10,   9, 100,  11,   9, 101,  12,   9, 102,  13,   9, 103,
  14,   9, 104,  15,   9, 105,  16,   9, 106,  17,   9, 107,  18,   9, 108,   4,
   9, 109,   4,   9, 110,   9,   9, 111,  10,   9, 112,  11,   9, 113,  12,   9,
 114,  13,   9, 115,  14,   9, 116,  15,   9, 117,  16,   9, 118,  17,   9, 119,
  18,   9, 120,   4,   9, 121,   4,   9, 122,   9,   9, 123,  10,   9, 124,  11,
   9, 125,  12,   9, 126,  13,   9, 127,  14,   9, 128,   1,  15,   9, 129,   1,
  16,   9, 130,   1,  17,   9, 131,   1,  18,   7,  32, 133,   1,   7,  32, 135,
   1,   7,  32, 137,   1,   7,  32, 139,   1,   7,  32, 141,   1,   7,  32, 143,
   1,   7,  32, 145,   1,   7,  32, 147,   1,   7,  32, 149,   1,   7,  32, 151,
   1,   7,  32, 153,   1,   7,  32, 155,   1,   7,  32, 156,   1,   7,  32, 157,
   1,   7,  32, 158,   1,   7,  32, 159,   1,   7,  32, 160,   1,   7,  32, 161,
   1,   7,  32, 162,   1,   7,  32, 163,   1,   7,  32, 164,   1,   7,  32, 165,
   1,   7,  32, 166,   1,   7,  32, 167,   1,   9,  19,  19,   9,  22,  19,   9,
  23,   2,   9,  27,  19,   9,   4,  20,   9,  63,  20,   9,  68,  21,   9,  23,
  22,   9, 133,   1,  23,   9,  23,  24,   9, 135,   1,  23,   9, 137,   1,  23,
   9, 139,   1,  23,   9, 141,   1,  23,   9, 143,   1,  23,   9, 145,   1,  23,
   9, 147,   1,  23,   9, 149,   1,  23,   9, 151,   1,  23,   9, 153,   1,  23,
   9, 155,   1,  23,   9, 156,   1,  23,   9, 157,   1,  23,   9, 158,   1,  23,
   9, 159,   1,  23,   9, 160,   1,  23,   9, 161,   1,  23,   9, 162,   1,  23,
   9, 163,   1,  23,   9, 164,   1,  23,   9, 165,   1,  23,   9, 166,   1,  23,
   9, 167,   1,  23,   9, 168,   1,  23,   7,  32, 168,   1,   9, 169,   1,  23,
   7,  32, 169,   1,   9, 170,   1,  23,   7,  32, 170,   1,   9, 171,   1,  23,
   7,  32, 171,   1,   9, 172,   1,  23,   7,  32, 172,   1,   9, 173,   1,  23,
   7,  32, 173,   1,   9, 174,   1,  23,   7,  32, 174,   1,   9,  70,  23,   7,
  32,  70,   9,  71,  23,   7,  32,  71,   9,  75,  23,   7,  32,  75,   9,  78,
  23,   7,  32,  78,   9,  81,  23,   7,  32,  81,   9,  84,  23,   7,  32,  84,
   9,  87,  23,   7,  32,  87,   9,  90,  23,   7,  32,  90,   9,  92,  23,   7,
  32,  92,   9,  93,  23,   7,  32,  93,   9,  94,  23,   7,  32,  94,   9,  95,
  23,   7,  32,  95,   9,  96,  23,   7,  32,  96,   9,  97,  23,   7,  32,  97,
   9,  98,  23,   7,  32,  98,   9,  99,  23,   7,  32,  99,   9, 100,  23,   7,
  32, 100,   9, 101,  23,   7,  32, 101,   9, 102,  23,   7,  32, 102,   9, 103,
  23,   7,  32, 103,   9, 104,  23,   7,  32, 104,   9, 105,  23,   7,  32, 105,
   9, 106,  23,   7,  32, 106,   9, 107,  23,   7,  32, 107,   9, 175,   1,  19,
   9,   4,  25,   9,  63,  25,   9,  16,  25,   9,  68,  26,   9, 190,   1,   4,
   9, 191,   1,   4,   9, 168,   1,  27,   9, 169,   1,  27,   9, 170,   1,  27,
   9, 171,   1,  27,   9, 172,   1,  27,   9, 173,   1,  27,   9, 174,   1,  27,
   9,  70,  27,   9,  71,  27,   9,  75,  28,   9,  78,  29,   9,  81,  30,   9,
  84,  31,   9,  87,  32,   9,  90,  33,   9,  92,  34,   9,  93,  35,   9,  94,
  36,   9,  95,  37,   9,  96,  27,   9,  97,  27,   9,  98,  28,   9,  99,  29,
   9, 100,  30,   9, 101,  31,   9, 102,  32,   9, 103,  33,   9, 104,  34,   9,
 105,  35,   9, 106,  36,   9, 107,  37,   9, 108,  27,   9, 109,  27,   9, 110,
  28,   9, 111,  29,   9, 112,  30,   9, 113,  31,   9, 114,  32,   9, 115,  33,
   9, 116,  34,   9, 117,  35,   9, 118,  36,   9, 119,  37,   9, 120,  27,   9,
 121,  27,   9, 122,  28,   9, 123,  29,   9, 124,  30,   9, 125,  31,   9, 126,
  32,   9, 127,  33,   9, 128,   1,  34,   9, 129,   1,  35,   9, 130,   1,  36,
   9, 131,   1,  37,   9, 133,   1,  27,   9, 135,   1,  27,   9, 137,   1,  28,
   9, 139,   1,  29,   9, 141,   1,  30,   9, 143,   1,  31,   9, 145,   1,  32,
   9, 147,   1,  33,   9, 149,   1,  34,   9, 151,   1,  35,   9, 153,   1,  36,
   9, 155,   1,  37,   9, 156,   1,  27,   9, 157,   1,  27,   9, 158,   1,  28,
   9, 159,   1,  29,   9, 160,   1,  30,   9, 161,   1,  31,   9, 162,   1,  32,
   9, 163,   1,  33,   9, 164,   1,  34,   9, 165,   1,  35,   9, 166,   1,  36,
   9, 167,   1,  37,   7,   4,  12,   9, 200,   1,  38,   9,  63,  38,   9,  61,
  38,   9, 202,   1,  38,   9,  13,   4,   9, 203,   1,   4,   9, 200,   1,  39,
   9, 202,   1,   4,   9,  14,   4,   9, 204,   1,   4,   9, 205,   1,   4,   9,
  12,  20,   9,  23,  40,   9,  12,  25,   7,   1, 209,   1,   7,   1, 210,   1,
   9, 211,   1,  41,   9, 214,   1,  41,   7,   1, 215,   1,   9, 216,   1,  42,
   9, 217,   1,  41,   9, 214,   1,  42,   9, 218,   1,  42,   9, 220,   1,  43,
   9, 222,   1,  43,   9, 225,   1,  43,   9, 220,   1,   4,   9, 222,   1,   4,
   9, 225,   1,   4,   9, 227,   1,   4,   9, 228,   1,   4,   7,  71, 229,   1,
   9, 231,   1,   4,   9, 232,   1,   4,   7,  71, 233,   1,   9, 235,   1,   4,
   9, 236,   1,   4,   9, 237,   1,   4,   9, 238,   1,   4,   7,  71, 239,   1,
   7,  71, 241,   1,   9,  23,  41,   9, 229,   1,  44,   9, 233,   1,  44,   9,
 239,   1,  44,   9, 241,   1,  44,   9, 253,   1,  44,   9, 255,   1,  44,   9,
 129,   2,  44,   9, 131,   2,  44,   9, 133,   2,  44,   9, 135,   2,  44,   9,
 217,   1,  42,   9, 137,   2,  44,   9, 139,   2,  44,   9, 141,   2,  44,   9,
 143,   2,  44,   9, 145,   2,  44,   9, 146,   2,  44,   9, 147,   2,  44,   9,
 211,   1,  42,   9, 149,   2,  44,   9, 151,   2,  44,   9, 153,   2,  44,   9,
 155,   2,  44,   7,   1, 158,   2,   7,   1, 159,   2,   7,   1, 160,   2,   7,
   1, 161,   2,   7,   1, 162,   2,   7,   1, 163,   2,   7,   1, 164,   2,   9,
 158,   2,   4,   9, 159,   2,   4,   9, 160,   2,   4,   9, 161,   2,   4,   9,
 162,   2,   4,   9, 163,   2,   4,   9, 164,   2,   4,   9, 165,   2,   4,   9,
 166,   2,   4,   9, 167,   2,   4,   9, 168,   2,   4,   7,  84, 170,   2,   9,
  23,  45,   9, 170,   2,  46,   9, 200,   1,  47,   9, 200,   1,  48,   7,  18,
 176,   2,   9,  23,  49,   9, 176,   2,  50,   7,   1, 181,   2,   7,   1, 183,
   2,   9, 181,   2,   4,   9, 183,   2,   4,   7,  18, 185,   2,   9,  23,  51,
   9, 185,   2,  50,   7,   4, 188,   2,   9, 189,   2,   4,   9, 190,   2,   4,
   9, 191,   2,   4,   9, 192,   2,   4,   9, 193,   2,   4,   9, 194,   2,   4,
   9,  23,  52,   9, 188,   2,  25, 237,   1,   1,   1,   0,   1,   0,   1,   1,
   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,
   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,
   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,
   1,   1,   0,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,
   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,
   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,
   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,
   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,
   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,
   0,   0,   2,   1,   0,   0,   5,   1,   0,   0,   7,   1,   0,   0,   0,   1,
   4,   0,   0,   1,   4,   1,  12,   5,   1,   0,   0,   0,   1,   0,   0,   0,
   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,
   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   1,  20,  20,   1,  32,   0,
   0,   1,   0,   0,   0,   1,   0,   1,   1,  25,   1,  32,   1,  25,   5,   1,
  32,   0,   5,   1,  32,   0,   5,   1,  32,   0,   5,   1,  32,   1,   1,  26,
   1,  32,   1,   1,   5,   1,  32,   0,   1,   1,  32,   0,   2,   1,  32,   0,
   7,   1,  32,   0,  26,   1,  32,   0,   5,   1,  32,   0,  20,   1,  32,   0,
  20,   1,  32,   0,  20,   1,  32,   0,   1,   1,  32,   0,   1,   1,  32,   0,
   1,   1,  32,   1,   2,  19,   1,  32,   0,  25,   1,  32,   0,  25,   1,  32,
   1,   1,  27,   1,  32,   0,   0,   1,   0,   0,   0,   1,   0,   1,   2,   5,
   1,  32,   1,   5,   5,   1,  32,   2,   1,   5,   5,   1,  32,   1,  52,   5,
   1,  32,   2,   2,   5,  52,   1,  32,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   5,   1,   0,   0,   2,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,
   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,
   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,
   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,
   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,
   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,   0,   2,   1,   0,
   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,
   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,
   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,
   1,   0,   1,   1,   0,   1,   0,   1,   1,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,
   0, 187,   2,   1,  32,   0,   7,   1,  32,   1,   1, 187,   2,   1,  32,   1,
   0, 187,   2,   1,   0,   2,   0,  52,   7,   1,  40,   1,   8,   3,   1,  12,
   5,   1,  32,   2,   0,   5,   7,   1,   8,   1,   8,   3,   0,  52,   1,  32,
   1,   0,  52,   1,  32,   0,   0,   1,   0,   1,   5,   5,   1,  32,   1,  19,
 202,   2,   1,  32,   1,  26, 202,   2,   1,  32,   2,   2,  19, 203,   2,   1,
  32,   3,  20,  19, 203,   2,   7,   1,  32,   2,  20,  19, 203,   2,   1,   0,
   2,  20,  19, 203,   2,   1,   0,   2,  20,  19, 203,   2,   1,   0,   0,  20,
   1,  32,   0,  19,   1,  32,   2,  19,  19,   2,   1,  40,   1,  10,  10,   1,
  20,   0,   1,  32,   1,   1, 202,   2,   1,  32,   0,   0,   1,   2,   1,   1,
 202,   2,   1,   2,   1,   1,   2,   1,  32,   0,   1,   1,  32,   0,   1,   1,
  32,   0,   1,   1,  32,   0,   1,   1,  32,   0,   0,   1,   0,   0,   5,   1,
   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,
   0,   0,   0,   1,  32,   0,  20,   1,  32,   0,   0,   1,   0,   0,   0,   1,
   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   2,   0,  25,
  25,   1,  40,   1,   9,   3,   1,  25,  25,   1,  40,   1,   9,   3,   1,   0,
 202,   2,   1,  32,   0, 202,   2,   1,  32,   0,   0,   1,   0,   0,   0,   1,
   0,   0,   0,   1,   0,   1,   1,   2,   1,  32,   1,   0,   2,   1,   8,   1,
  10,  10,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,
   1,   0,   0,   0,   1,   0,   1, 158,   3,   5,   1,  36,   3, 158,   3, 158,
   3,  25,  26,   1,  40,   1,  12,  12,   1,  26, 158,   3,   1,  32,   1,   5,
   5,   1,  36,   2,   5, 158,   3,   5,   1,  36,   2,   5, 158,   3,   5,   1,
  32,   0,   0,   1,   0,   0,   0,   1,   0,  39,  35,   0,  37,   1,  38,  39,
  72,   1,   0,  73,  72,   1,   0,  76,  72,   1,   0,  79,  72,   1,   0,  82,
  72,   1,   0,  85,  72,   1,   0,  88,  72,   1,   0,  91,  72,   2,   0,   0,
  76,  79,  72,   2,   0,   0,  91,  73,  72,   3,   0,   0,   0,  85,  79,  91,
  72,   4,   0,   0,   0,   0,  88,  73,  76,  79, 176,   1,   3, 177,   1, 179,
   1, 181,   1, 178,   1, 180,   1, 182,   1, 176,   1,   3, 177,   1, 185,   1,
 181,   1, 184,   1, 186,   1, 187,   1, 176,   1,   2, 177,   1, 181,   1, 188,
   1, 187,   1, 176,   1,   4, 177,   1, 207,   1, 179,   1, 181,   1, 206,   1,
 186,   1, 208,   1, 187,   1, 176,   1,   4, 177,   1, 179,   1, 181,   1, 245,
   1, 243,   1, 244,   1, 187,   1, 246,   1, 176,   1,   4, 177,   1, 179,   1,
 181,   1, 245,   1, 247,   1, 248,   1, 187,   1, 246,   1, 176,   1,   4, 177,
   1, 179,   1, 181,   1, 245,   1, 249,   1, 250,   1, 187,   1, 246,   1, 176,
   1,   4, 177,   1, 179,   1, 181,   1, 245,   1, 251,   1, 252,   1, 187,   1,
 246,   1, 176,   1,   1,   0, 254,   1, 176,   1,   1,   0, 128,   2, 176,   1,
   1,   0, 130,   2, 176,   1,   1,   0, 132,   2, 176,   1,   1,   0, 134,   2,
 176,   1,   1,   0, 136,   2, 176,   1,   1,   0, 138,   2, 176,   1,   1,   0,
 140,   2, 176,   1,   1,   0, 142,   2, 176,   1,   1,   0, 144,   2, 176,   1,
   1,   0, 148,   2, 176,   1,   1,   0, 150,   2, 176,   1,   1,   0, 152,   2,
 176,   1,   1,   0, 154,   2, 176,   1,   1,   0, 156,   2, 176,   1,   2, 177,
   1, 181,   1, 173,   2, 187,   1, 176,   1,   4, 177,   1, 207,   1, 179,   1,
 181,   1, 178,   2, 186,   1, 179,   2, 187,   1, 176,   1,   3, 177,   1, 179,
   1, 181,   1, 196,   2, 188,   2, 187,   1,  39,  16,   0,   5,   0,  44,   1,
  15,   1,   0,  43,  18,  19,   9,   9,   0,  47,   1,  17,   1,   0,  46,  22,
  19,   9,  11,   0,  50,   1,  21,   1,   0,  49,  51,  19,   9,  13,   0,  74,
   0,  57,  19,   9,  19,   0,  81,   0,  61,  19,  11,  23,   0,  85,   0, 110,
  19,   9,  33,   0, 123,  60,  62,   0,   0,   2,  11,  11,  63,  64,   0,   2,
  11,  11,   1,   2,  64,  64,   0,   2,  11,  11,   1,   3,  65,  64,   0,   2,
  11,  11,   1,   4,  66,  64,   0,   2,  11,  11,   1,   5,  67,  64,   0,   2,
  11,  11,   1,   6,  68,  64,   0,   2,  11,  11,   1,   7,  69,  64,   0,   2,
  11,  11,   1,   8,  70,  64,   0,   2,  11,  11,   1,   9,  71,  64,   0,   2,
  11,  11,   1,  10,  72,  64,   0,   2,  11,  11,   1,  11,  73,  64,   0,   2,
  11,  11,   1,  12,  74,   6,   0,   2,  11,  11,  75,  70,   0,   2,  11,  11,
   1,   2,  76,  70,   0,   2,  11,  11,   1,   3,  77,  70,   0,   2,  11,  11,
   1,   4,  78,  70,   0,   2,  11,  11,   1,   5,  79,  70,   0,   2,  11,  11,
   1,   6,  80,  70,   0,   2,  11,  11,   1,   7,  81,  70,   0,   2,  11,  11,
   1,   8,  82,  70,   0,   2,  11,  11,   1,   9,  83,  70,   0,   2,  11,  11,
   1,  10,  84,  70,   0,   2,  11,  11,   1,  11,  85,  70,   0,   2,  11,  11,
   1,  12,  86,   1,   0,  87,  87,  65,   0,  88,   1,   2,  88,  65,   0,  89,
   1,   3,  89,  65,   0,  90,   1,   4,  90,  65,   0,  91,   1,   5,  91,  65,
   0,  92,   1,   6,  92,  65,   0,  93,   1,   7,  93,  65,   0,  94,   1,   8,
  94,  65,   0,  95,   1,   9,  95,  65,   0,  96,   1,  10,  96,  65,   0,  97,
   1,  11,  97,  65,   0,  98,   1,  12,  98,   2,   0,  99,  99,  66,   0, 100,
   1,   2, 100,  66,   0, 101,   1,   3, 101,  66,   0, 102,   1,   4, 102,  66,
   0, 103,   1,   5, 103,  66,   0, 104,   1,   6, 104,  66,   0, 105,   1,   7,
 105,  66,   0, 106,   1,   8, 106,  66,   0, 107,   1,   9, 107,  66,   0, 108,
   1,  10, 108,  66,   0, 109,   1,  11, 109,  66,   0, 110,   1,  12,  98,   3,
   0, 111,  99,  67,   0, 112,   1,   2, 100,  67,   0, 113,   1,   3, 101,  67,
   0, 114,   1,   4, 102,  67,   0, 115,   1,   5, 103,  67,   0, 116,   1,   6,
 104,  67,   0, 117,   1,   7, 105,  67,   0, 118,   1,   8, 106,  67,   0, 119,
   1,   9, 107,  67,   0, 120,   1,  10, 108,  67,   0, 121,   1,  11, 109,  67,
   0, 122,   1,  12, 111,  19,   9,  35,   0, 125,   0, 112,  19,   9,  37,   0,
 127,   0, 113,  19,   9,  39,   0, 129,   1,   0, 114,  19,   9,  41,   0, 131,
   1,   0, 115,  19,   9,  43,   0, 133,   1,   0, 116,  19,   9,  45,   0, 135,
   1,   0, 117,  19,   9,  47,   0, 137,   1,   0, 118,  19,   9,  49,   0, 139,
   1,   0, 119,  19,   9,  51,   0, 141,   1,   0, 120,  19,   9,  53,   0, 143,
   1,   0, 121,  19,   9,  55,   0, 145,   1,   0, 122,   0,   5,   0, 147,   1,
   0, 123,   0,   5,   0, 149,   1,   0, 124,   0,   5,   0, 151,   1,   0, 125,
   0,   5,   0, 153,   1,   0, 126,   0,   5,   0, 155,   1,   0, 127,   0,   5,
   0, 157,   1,   0, 128,   1,   0,   5,   0, 159,   1,   0, 129,   1,   0,   5,
   0, 161,   1,   0, 130,   1,   0,   5,   0, 163,   1,   0, 131,   1,   0,   5,
   0, 165,   1,   0, 132,   1,   0,   5,   0, 167,   1,   0, 133,   1,   0,   5,
   0, 169,   1,   0, 187,   2,  19,   9,  68,   0, 175,   1,   6, 194,   2,   1,
   0, 174,   1, 195,   2,   1,   0, 176,   1, 196,   2,   1,   0, 177,   1, 197,
   2,   1,   0, 178,   1, 198,   2,   2,   0, 179,   1, 198,   2,   3,   0, 180,
   1, 219,   2,  19,  11,  74,   0, 204,   1,   5, 214,   2,   6,   0,   5,   0,
 215,   2,   6,   0,   5,   0, 216,   2,   6,   0,   7,   0, 217,   2,   6,   0,
  20,   0, 218,   2,   1,   0, 203,   1, 222,   2,  19,   9,  77,   0, 206,   1,
   2, 220,   2,   6,   0,  20,   0, 221,   2,   6,   0,  26,   0, 227,   2, 222,
   2,  11,  79,   0, 210,   1,   4, 223,   2,   6,   0,  20,   0, 224,   2,   6,
   0,  12,   0, 225,   2,   2,   0, 208,   1, 226,   2,   2,   0, 209,   1, 228,
   2, 222,   2,  11,  81,   0, 212,   1,   2, 223,   2,   6,   0,  20,   0, 226,
   2,   6,   0,  20,   0, 143,   3,  19,   9,  85,   0, 219,   1,   0, 148,   3,
  19,   8,  92,   0, 223,   1,   1, 147,   3,   1,   0, 222,   1, 155,   3,  19,
   9,  96,   0, 226,   1,   0, 158,   3,  19,   9,  99,   0, 235,   1,   0,  42,
   0,  45,   0,  48,   0,  51,  23,  28,  81,   3,  52,   1,   0,  29,  81,   4,
  53,   1,   1,  30,  17,   5,  54,  31,  17,   6,  55,  32,  17,   7,  56,  33,
  17,   8,  57,  34,  17,   9,  58,  35,  17,  10,  59,  36,  17,  11,  60,  37,
  17,  12,  61,  38,  17,  13,  62,  39,   6,   1,  26,   0,  40,  17,  14,  63,
  41,  18,  15,  64,  42,  18,  16,  65,  43,  18,  17,  66,  44,  17,  18,  67,
  45,  17,  19,  68,  46,  17,  20,  69,  47,  17,  21,  70,  48,  18,  22,  71,
  49,  18,  23,  72,  50,  17,  24,  73,  75,   5,  53,  17,   3,  76,  54,  17,
   4,  77,  34,  17,   5,  78,  55,  17,   6,  79,  56,  17,   7,  80,  82,   2,
  60,  18,   3,  83,  36,  18,   4,  84,  86,   0, 124,   0, 126,   0, 128,   1,
   0, 130,   1,   0, 132,   1,   0, 134,   1,   0, 136,   1,   0, 138,   1,   0,
 140,   1,   0, 142,   1,   0, 144,   1,   0, 146,   1,   0, 148,   1,   0, 150,
   1,   0, 152,   1,   0, 154,   1,   0, 156,   1,   0, 158,   1,   0, 160,   1,
   0, 162,   1,   0, 164,   1,   0, 166,   1,   0, 168,   1,   0, 171,   1,   2,
 192,   2,  18,   3, 172,   1, 193,   2,  18,   4, 173,   1, 202,   1,   0, 205,
   1,   0, 207,   1,   0, 211,   1,   0, 214,   1,  11, 132,   3,   6,   1,  25,
   8,   3, 133,   3,   6,   2,  25,  10,   3, 134,   3,   6,   3,  25,   9,   3,
 135,   3,   6,   4,  25,  11,   3, 136,   3,   6,   5,  25,  12,   3, 137,   3,
   6,   6,   0,  10,   3, 138,   3,   6,   7,   0,   9,   3, 139,   3,  17,   3,
 215,   1, 140,   3,  17,   4, 216,   1, 141,   3,  17,   5, 217,   1, 142,   3,
  17,   6, 218,   1, 221,   1,   0, 225,   1,   2, 153,   3,   6,   1,   5, 182,
   2,   1, 154,   3,   6,   2,   5, 184,   2,   1, 228,   1,   6, 159,   3,  17,
   3, 229,   1, 160,   3,  17,   4, 230,   1, 161,   3,  17,   5, 231,   1, 162,
   3,  17,   6, 232,   1, 163,   3,  17,   7, 233,   1, 164,   3,  17,   8, 234,
   1,   7, 181,   1,   1, 201,   2,  68,   0,  30,   1,  16, 213,   1,  23, 230,
   2,  68,   1,  31,   1,  17, 231,   2,  68,   2,  32,   1,  18, 232,   2,  68,
   3,  33,   1,  19, 233,   2,  68,   4,  34,   1,  20, 234,   2,  65,  43, 201,
   1,   1,  21, 235,   2,  65,  44, 200,   1,   1,  22, 236,   2,  65,  45, 199,
   1,   1,  23, 237,   2,  65,  46, 198,   1,   1,  24, 238,   2,  65,  47, 197,
   1,   1,  25, 239,   2,   1,  48, 196,   1, 240,   2,  65,  49, 194,   1,   1,
  26, 241,   2,  65,  50, 193,   1,   1,  27, 242,   2,  65,  51, 192,   1,   1,
  28, 243,   2,  65,  52, 191,   1,   1,  29, 244,   2,  65,  53, 190,   1,   1,
  30, 245,   2,   1,  54, 189,   1, 246,   2,   1,  55, 188,   1, 247,   2,   1,
  56, 187,   1, 248,   2,  65,  57, 186,   1,   1,  31, 249,   2,  65,  58, 185,
   1,   1,  32, 250,   2,  65,  59, 184,   1,   1,  33, 251,   2,  65,  60, 183,
   1,   1,  34, 252,   2,  65,  61, 182,   1,   1,  35, 220,   1,   1, 145,   3,
  68,   1,  35,   1,  36, 224,   1,   1, 150,   3,  68,   1,  36,   1,  37, 227,
   1,   1, 157,   3,   4,   1,  37, 236,   1,   1, 166,   3,  68,   1,  38,   1,
  38, 170,   1, 104, 229,   1,   6,   0,   0,  16,   8, 134,   1,   4,   0,   0,
 135,   1,   4,   0,   1, 137,   1,  68,   0,   2,   1,  13, 230,   1,  68,   0,
   3,   1,  14, 231,   1,  68,   0,   4,   1,  15, 232,   1,   1,   1,  41, 233,
   1,   4,   0,   5, 234,   1,   1,   2,  40, 235,   1,   1,   3,  39,  33,   1,
   4,  38,  37,   1,   5,  37,  40,   1,   6,  36, 236,   1,   6,   0,   0,   1,
   3, 237,   1,   6,   0,   0,   2,   3, 238,   1,   6,   0,   0,   3,   3, 239,
   1,   6,   0,   0,   4,   3, 240,   1,   6,   0,   0,   5,   3, 241,   1,   6,
   0,   0,   6,   3, 242,   1,   6,   0,   0,   7,   3, 243,   1,   0,   0,   2,
   0, 244,   1,  64,   0,   2,   0,   1,   2, 245,   1,  64,   0,   2,   0,   1,
   3, 246,   1,  64,   0,   2,   0,   1,   4, 247,   1,  64,   0,   2,   0,   1,
   5, 248,   1,  64,   0,   2,   0,   1,   6, 249,   1,  64,   0,   2,   0,   1,
   7, 250,   1,  64,   0,   2,   0,   1,   8, 251,   1,  64,   0,   2,   0,   1,
   9, 252,   1,  64,   0,   2,   0,   1,  10, 253,   1,  64,   0,   2,   0,   1,
  11, 254,   1,  64,   0,   2,   0,   1,  12, 255,   1,   6,   0,   2,  11,  11,
 128,   2,  70,   0,   2,  11,  11,   1,   2, 129,   2,  70,   0,   2,  11,  11,
   1,   3, 130,   2,  70,   0,   2,  11,  11,   1,   4, 131,   2,  70,   0,   2,
  11,  11,   1,   5, 132,   2,  70,   0,   2,  11,  11,   1,   6, 133,   2,  70,
   0,   2,  11,  11,   1,   7, 134,   2,  70,   0,   2,  11,  11,   1,   8, 135,
   2,  70,   0,   2,  11,  11,   1,   9, 136,   2,  70,   0,   2,  11,  11,   1,
  10, 137,   2,  70,   0,   2,  11,  11,   1,  11, 138,   2,  70,   0,   2,  11,
  11,   1,  12, 139,   2,   1,   7,  35, 140,   2,  65,   8,  34,   1,   2, 141,
   2,  65,   9,  33,   1,   3, 142,   2,  65,  10,  32,   1,   4, 143,   2,  65,
  11,  31,   1,   5, 144,   2,  65,  12,  30,   1,   6, 145,   2,  65,  13,  29,
   1,   7, 146,   2,  65,  14,  28,   1,   8, 147,   2,  65,  15,  27,   1,   9,
 148,   2,  65,  16,  26,   1,  10, 149,   2,  65,  17,  25,   1,  11, 150,   2,
  65,  18,  24,   1,  12, 151,   2,   2,  19,  23, 152,   2,  66,  20,  22,   1,
   2, 153,   2,  66,  21,  21,   1,   3, 154,   2,  66,  22,  20,   1,   4, 155,
   2,  66,  23,  19,   1,   5, 156,   2,  66,  24,  18,   1,   6, 157,   2,  66,
  25,  17,   1,   7, 158,   2,  66,  26,  16,   1,   8, 159,   2,  66,  27,  15,
   1,   9, 160,   2,  66,  28,  14,   1,  10, 161,   2,  66,  29,  13,   1,  11,
 162,   2,  66,  30,  12,   1,  12, 151,   2,   3,  31,  11, 152,   2,  67,  32,
  10,   1,   2, 153,   2,  67,  33,   9,   1,   3, 154,   2,  67,  34,   8,   1,
   4, 155,   2,  67,  35,   7,   1,   5, 156,   2,  67,  36,   6,   1,   6, 157,
   2,  67,  37,   5,   1,   7, 158,   2,  67,  38,   4,   1,   8, 159,   2,  67,
  39,   3,   1,   9, 160,   2,  67,  40,   2,   1,  10, 161,   2,  67,  41,   1,
   1,  11, 162,   2,  67,  42,   0,   1,  12, 163,   2,   4,   0,   6, 164,   2,
  68,   0,   7,   1,   2, 165,   2,  68,   0,   8,   1,   3, 166,   2,  68,   0,
   9,   1,   4, 167,   2,  68,   0,  10,   1,   5, 168,   2,  68,   0,  11,   1,
   6, 169,   2,  68,   0,  12,   1,   7, 170,   2,  68,   0,  13,   1,   8, 171,
   2,  68,   0,  14,   1,   9, 172,   2,  68,   0,  15,   1,  10, 173,   2,  68,
   0,  16,   1,  11, 174,   2,  68,   0,  17,   1,  12, 175,   2,   4,   0,  18,
 176,   2,  68,   0,  19,   1,   2, 177,   2,  68,   0,  20,   1,   3, 178,   2,
  68,   0,  21,   1,   4, 179,   2,  68,   0,  22,   1,   5, 180,   2,  68,   0,
  23,   1,   6, 181,   2,  68,   0,  24,   1,   7, 182,   2,  68,   0,  25,   1,
   8, 183,   2,  68,   0,  26,   1,   9, 184,   2,  68,   0,  27,   1,  10, 185,
   2,  68,   0,  28,   1,  11, 186,   2,  68,   0,  29,   1,  12, 160,   1,   0,
   1,   2,   1,   2,   3, 208,  48,  71,   0,   0,   1,   1,   2,   1,   2,   3,
 208,  48,  71,   0,   0,   2,   1,   2,   1,   2,   3, 208,  48,  71,   0,   0,
   3,   1,   2,   1,   2,   3, 208,  48,  71,   0,   0,   4,   1,   2,   1,   2,
   3, 208,  48,  71,   0,   0,   5,   1,   2,   1,   2,   3, 208,  48,  71,   0,
   0,   6,   1,   2,   1,   2,   3, 208,  48,  71,   0,   0,   7,   1,   2,   1,
   2,   3, 208,  48,  71,   0,   0,   8,   1,   2,   1,   2,   3, 208,  48,  71,
   0,   0,   9,   1,   2,   1,   2,   3, 208,  48,  71,   0,   0,  10,   1,   2,
   1,   2,   3, 208,  48,  71,   0,   0,  11,   1,   2,   1,   2,   3, 208,  48,
  71,   0,   0,  12,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  13,
   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  14,   1,   1,   1,   2,
   4, 208,  48,  38,  72,   0,   0,  15,   1,   1,   1,   2,   4, 208,  48,  38,
  72,   0,   0,  16,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  17,
   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  18,   1,   1,   1,   2,
   4, 208,  48,  38,  72,   0,   0,  19,   1,   1,   1,   2,   4, 208,  48,  38,
  72,   0,   0,  20,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  21,
   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  22,   1,   1,   1,   2,
   4, 208,  48,  38,  72,   0,   0,  23,   1,   1,   1,   2,   4, 208,  48,  38,
  72,   0,   0,  24,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  25,
   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  26,   1,   1,   1,   2,
   4, 208,  48,  38,  72,   0,   0,  27,   1,   1,   1,   2,   4, 208,  48,  38,
  72,   0,   0,  28,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  29,
   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  30,   1,   1,   1,   2,
   4, 208,  48,  38,  72,   0,   0,  31,   1,   1,   1,   2,   4, 208,  48,  38,
  72,   0,   0,  32,   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  33,
   1,   1,   1,   2,   4, 208,  48,  38,  72,   0,   0,  34,   1,   1,   1,   2,
   4, 208,  48,  38,  72,   0,   0,  35,   1,   1,   1,   2,   4, 208,  48,  38,
  72,   0,   0,  36,   1,   1,   1,   2,  10, 208,  48,  93,   3, 102,   3,  70,
   4,   0,  72,   0,   0,  37,   1,   1,   1,   2,  10, 208,  48,  93,   3, 102,
   3,  70,   6,   0,  72,   0,   0,  38,   2,   2,   1,   2,  12, 208,  48,  93,
   3, 102,   3, 209,  70,   8,   1,  41,  71,   0,   0,  39,   2,   2,   1,   2,
  12, 208,  48,  93,   3, 102,   3, 209,  70,   8,   1,  41,  71,   0,   0,  40,
   2,   2,   1,   2,  13, 208,  48,  93,   9, 102,   9, 102,  10, 209,  70,  11,
   1,  72,   0,   0,  41,   1,   1,   1,   2,  11, 208,  48,  93,  13, 102,  13,
  70,  14,   0,  41,  71,   0,   0,  42,   0,   1,   3,   3,   1,  71,   0,   0,
  45,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,  46,   1,   1,   4,   5,
   3, 208,  48,  71,   0,   0,  47,   1,   1,   4,   5,   6, 208,  48, 208,  73,
   0,  71,   0,   0,  48,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,  50,
   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,  51,   2,   1,
   3,   4,  12, 208,  48,  94,  23,  93,  24,  70,  24,   0, 104,  23,  71,   0,
   0,  74,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,  75,
   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,  81,   1,   1,   4,   5,   6,
 208,  48, 208,  73,   0,  71,   0,   0,  82,   1,   1,   3,   4,   3, 208,  48,
  71,   0,   0,  83,   1,   1,   3,   4,   5, 208,  48,  44,  65,  72,   0,   0,
  84,   1,   1,   3,   4,  10, 208,  48,  93,  58, 102,  58,  70,  59,   0,  72,
   0,   0,  85,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,
  86,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,  87,   1,   1,   4,   5,
   4, 208,  48,  38,  72,   0,   0,  88,   1,   1,   4,   5,   4, 208,  48,  38,
  72,   0,   0,  89,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0,  90,
   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0,  91,   1,   1,   4,   5,
   4, 208,  48,  38,  72,   0,   0,  92,   1,   1,   4,   5,   4, 208,  48,  38,
  72,   0,   0,  93,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0,  94,
   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0,  95,   1,   1,   4,   5,
   4, 208,  48,  38,  72,   0,   0,  96,   1,   1,   4,   5,   4, 208,  48,  38,
  72,   0,   0,  97,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0,  98,
   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0,  99,   1,   1,   4,   5,
   4, 208,  48,  38,  72,   0,   0, 100,   1,   1,   4,   5,   4, 208,  48,  38,
  72,   0,   0, 101,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 102,
   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 103,   1,   1,   4,   5,
   4, 208,  48,  38,  72,   0,   0, 104,   1,   1,   4,   5,   4, 208,  48,  38,
  72,   0,   0, 105,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 106,
   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 107,   1,   1,   4,   5,
   4, 208,  48,  38,  72,   0,   0, 108,   1,   1,   4,   5,   4, 208,  48,  38,
  72,   0,   0, 109,   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 110,
   1,   1,   4,   5,   4, 208,  48,  38,  72,   0,   0, 111,   1,   2,   4,   5,
   3, 208,  48,  71,   0,   0, 112,   1,   2,   4,   5,   3, 208,  48,  71,   0,
   0, 113,   1,   2,   4,   5,   3, 208,  48,  71,   0,   0, 114,   1,   2,   4,
   5,   3, 208,  48,  71,   0,   0, 115,   1,   2,   4,   5,   3, 208,  48,  71,
   0,   0, 116,   1,   2,   4,   5,   3, 208,  48,  71,   0,   0, 117,   1,   2,
   4,   5,   3, 208,  48,  71,   0,   0, 118,   1,   2,   4,   5,   3, 208,  48,
  71,   0,   0, 119,   1,   2,   4,   5,   3, 208,  48,  71,   0,   0, 120,   1,
   2,   4,   5,   3, 208,  48,  71,   0,   0, 121,   1,   2,   4,   5,   3, 208,
  48,  71,   0,   0, 122,   1,   2,   4,   5,   3, 208,  48,  71,   0,   0, 123,
   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 124,   1,   1,
   3,   4,   3, 208,  48,  71,   0,   0, 125,   1,   1,   4,   5,   6, 208,  48,
 208,  73,   0,  71,   0,   0, 126,   1,   1,   3,   4,   3, 208,  48,  71,   0,
   0, 127,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 128,
   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 129,   1,   1,   1,   4,
   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 130,   1,   1,   1,   3,   4,
   3, 208,  48,  71,   0,   0, 131,   1,   1,   1,   4,   5,   6, 208,  48, 208,
  73,   0,  71,   0,   0, 132,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,
   0, 133,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,
 134,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 135,   1,   1,   1,
   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 136,   1,   1,   1,   3,
   4,   3, 208,  48,  71,   0,   0, 137,   1,   1,   1,   4,   5,   6, 208,  48,
 208,  73,   0,  71,   0,   0, 138,   1,   1,   1,   3,   4,   3, 208,  48,  71,
   0,   0, 139,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,
   0, 140,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 141,   1,   1,
   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 142,   1,   1,   1,
   3,   4,   3, 208,  48,  71,   0,   0, 143,   1,   1,   1,   4,   5,   6, 208,
  48, 208,  73,   0,  71,   0,   0, 144,   1,   1,   1,   3,   4,   3, 208,  48,
  71,   0,   0, 145,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,
   0,   0, 146,   1,   0,   1,   3,   3,   1,  71,   0,   0, 148,   1,   0,   1,
   3,   3,   1,  71,   0,   0, 150,   1,   0,   1,   3,   3,   1,  71,   0,   0,
 152,   1,   0,   1,   3,   3,   1,  71,   0,   0, 154,   1,   0,   1,   3,   3,
   1,  71,   0,   0, 156,   1,   0,   1,   3,   3,   1,  71,   0,   0, 158,   1,
   0,   1,   3,   3,   1,  71,   0,   0, 160,   1,   0,   1,   3,   3,   1,  71,
   0,   0, 162,   1,   0,   1,   3,   3,   1,  71,   0,   0, 164,   1,   0,   1,
   3,   3,   1,  71,   0,   0, 166,   1,   0,   1,   3,   3,   1,  71,   0,   0,
 168,   1,   0,   1,   3,   3,   1,  71,   0,   0, 170,   1,   2,   1,   1,   3,
 155,   5, 208,  48,  93, 134,   1,  32,  88,   0, 104,  16,  93, 135,   1,  93,
  19, 102,  19,  48,  93, 136,   1, 102, 136,   1,  88,   1,  29, 104,  18,  93,
 137,   1,  93,  19, 102,  19,  48,  93, 136,   1, 102, 136,   1,  88,   2,  29,
 104,  22,  93, 138,   1,  93,  19, 102,  19,  48,  93, 136,   1, 102, 136,   1,
  88,   3,  29, 104,  51,  93, 139,   1,  93,  19, 102,  19,  48,  93, 136,   1,
 102, 136,   1,  88,   4,  29, 104,  57,  93, 140,   1,  93,  19, 102,  19,  48,
  93, 141,   1, 102, 141,   1,  88,   5,  29, 104,  61,  93, 142,   1,  93,  19,
 102,  19,  48,  93, 143,   1, 102, 143,   1,  88,   6,  29, 104, 110,  93, 144,
   1,  93,  19, 102,  19,  48,  93, 143,   1, 102, 143,   1,  88,   7,  29, 104,
 111,  93, 145,   1,  93,  19, 102,  19,  48,  93, 143,   1, 102, 143,   1,  88,
   8,  29, 104, 112,  93, 146,   1,  93,  19, 102,  19,  48,  93, 143,   1, 102,
 143,   1,  88,   9,  29, 104, 113,  93, 147,   1,  93,  19, 102,  19,  48,  93,
 143,   1, 102, 143,   1,  88,  10,  29, 104, 114,  93, 148,   1,  93,  19, 102,
  19,  48,  93, 143,   1, 102, 143,   1,  88,  11,  29, 104, 115,  93, 149,   1,
  93,  19, 102,  19,  48,  93, 143,   1, 102, 143,   1,  88,  12,  29, 104, 116,
  93, 150,   1,  93,  19, 102,  19,  48,  93, 143,   1, 102, 143,   1,  88,  13,
  29, 104, 117,  93, 151,   1,  93,  19, 102,  19,  48,  93, 143,   1, 102, 143,
   1,  88,  14,  29, 104, 118,  93, 152,   1,  93,  19, 102,  19,  48,  93, 143,
   1, 102, 143,   1,  88,  15,  29, 104, 119,  93, 153,   1,  93,  19, 102,  19,
  48,  93, 143,   1, 102, 143,   1,  88,  16,  29, 104, 120,  93, 154,   1,  93,
  19, 102,  19,  48,  93, 143,   1, 102, 143,   1,  88,  17,  29, 104, 121,  93,
 155,   1,  32,  88,  18, 104, 122,  93, 156,   1,  32,  88,  19, 104, 123,  93,
 157,   1,  32,  88,  20, 104, 124,  93, 158,   1,  32,  88,  21, 104, 125,  93,
 159,   1,  32,  88,  22, 104, 126,  93, 160,   1,  32,  88,  23, 104, 127,  93,
 161,   1,  32,  88,  24, 104, 128,   1,  93, 162,   1,  32,  88,  25, 104, 129,
   1,  93, 163,   1,  32,  88,  26, 104, 130,   1,  93, 164,   1,  32,  88,  27,
 104, 131,   1,  93, 165,   1,  32,  88,  28, 104, 132,   1,  93, 166,   1,  32,
  88,  29, 104, 133,   1,  93, 167,   1,  37, 148,   5, 104, 168,   1,  93, 169,
   1,  37, 149,   5, 104, 170,   1,  93, 171,   1,  37, 150,   5, 104, 172,   1,
  93, 173,   1,  37, 151,   5, 104, 174,   1,  93, 175,   1,  37, 152,   5, 104,
 176,   1,  93, 177,   1,  37, 153,   5, 104, 178,   1,  93, 179,   1,  37, 154,
   5, 104, 180,   1,  93, 181,   1,  38,  97, 182,   1,  93, 183,   1,  38,  97,
 184,   1,  93, 185,   1,  38,  97, 186,   1,  93, 187,   1,  38,  97, 188,   1,
  93, 189,   1,  38,  97, 190,   1,  93, 191,   1,  38,  97, 192,   1,  93, 193,
   1,  38,  97, 194,   1,  93, 195,   1,  38,  97, 196,   1,  93, 197,   1,  38,
  97, 198,   1,  93, 199,   1,  38,  97, 200,   1,  93, 201,   1,  38,  97, 202,
   1,  93, 203,   1,  38,  97, 204,   1,  93, 205,   1,  38, 104, 206,   1,  93,
 207,   1,  38, 104, 208,   1,  93, 209,   1,  38, 104, 210,   1,  93, 211,   1,
  38, 104, 212,   1,  93, 213,   1,  38, 104, 214,   1,  93, 215,   1,  38, 104,
 216,   1,  93, 217,   1,  38, 104, 218,   1,  93, 219,   1,  38, 104, 220,   1,
  93, 221,   1,  38, 104, 222,   1,  93, 223,   1,  38, 104, 224,   1,  93, 225,
   1,  38, 104, 226,   1,  93, 227,   1,  38, 104, 228,   1,  71,   0,   0, 171,
   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 175,   1,   2,   2,   4,
   5,  13, 208,  48, 208,  73,   0, 208, 209,  70, 188,   2,   1,  41,  71,   0,
   0, 178,   1,   3,   3,   4,   5,  20, 208,  48, 208,  93, 189,   2, 102, 189,
   2, 209,  70, 190,   2,   1, 210,  70, 191,   2,   2,  72,   0,   0, 181,   1,
   2,   1,   1,   3,  23, 208,  48,  93, 199,   2,  93,  19, 102,  19,  48,  93,
 200,   2, 102, 200,   2,  88,  30,  29, 104, 187,   2,  71,   0,   0, 187,   1,
   4,   3,   1,   2,  14, 208,  48,  93, 204,   2, 209, 210,  36,   1,  70, 204,
   2,   3,  72,   0,   0, 188,   1,   4,   3,   1,   2,  14, 208,  48,  93, 204,
   2, 209, 210,  36,   2,  70, 204,   2,   3,  72,   0,   0, 189,   1,   4,   3,
   1,   2,  14, 208,  48,  93, 204,   2, 209, 210,  36,   0,  70, 204,   2,   3,
  72,   0,   0, 195,   1,   3,   3,   3,   6,  47,  87,  42, 213,  48, 101,   0,
  38, 118, 109,   1,  93, 205,   2,  76, 205,   2,   0,  41,  16,  20,   0,   0,
 209,  48,  90,   0,  42, 214,  42,  48,  43, 109,   1, 101,   0,  39, 118, 109,
   1,  29,   8,   2, 101,   0, 108,   1,  72,   1,  10,  18,  22,   0, 206,   2,
   1, 207,   2,   0,   1,   2,   0, 196,   1,   2,   3,   2,   4,  60, 208,  48,
  87,  42, 214,  48, 101,   1,  33, 130, 109,   2, 101,   1, 209, 109,   1, 101,
   1, 108,   1,  32,  19,  24,   0,   0, 101,   1,  64, 195,   1, 130, 109,   2,
  93, 208,   2, 101,   1, 108,   2,  70, 208,   2,   1,  41,  16,   9,   0,   0,
  93, 208,   2,  32,  70, 208,   2,   1,  41,  71,   0,   2, 209,   2,   0,   1,
 202,   2,   0, 210,   2,   0,   2,   0,   0, 202,   1,   1,   1,   3,   4,   3,
 208,  48,  71,   0,   0, 203,   1,   3,   1,   4,   5,  50, 208,  48, 208, 102,
 211,   2,  44, 221,   1, 160, 208, 102, 212,   2, 118,  18,  26,   0,   0,  44,
 223,   1, 208, 102, 212,   2, 160,  44, 224,   1, 160, 208, 102, 213,   2, 160,
  44, 226,   1, 160, 130,  16,   3,   0,   0,  44,   1, 130, 160,  72,   0,   0,
 204,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 205,
   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 206,   1,   1,   1,   4,
   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 207,   1,   1,   1,   4,   5,
   3, 208,  48,  71,   0,   0, 210,   1,   1,   1,   5,   6,   6, 208,  48, 208,
  73,   0,  71,   0,   0, 211,   1,   1,   1,   4,   5,   3, 208,  48,  71,   0,
   0, 212,   1,   1,   1,   5,   6,   6, 208,  48, 208,  73,   0,  71,   0,   0,
 213,   1,   2,   1,   1,   4,  89, 208,  48, 101,   0,  93,  19, 102,  19,  48,
  93, 229,   2, 102, 229,   2,  88,  31,  29, 104, 219,   2, 101,   0,  93,  19,
 102,  19,  48,  93, 229,   2, 102, 229,   2,  88,  32,  29, 104, 222,   2, 101,
   0,  93,  19, 102,  19,  48,  93, 222,   2, 102, 222,   2,  48, 100, 108,   2,
  88,  33,  29,  29, 104, 227,   2, 101,   0,  93,  19, 102,  19,  48,  93, 222,
   2, 102, 222,   2,  48, 100, 108,   2,  88,  34,  29,  29, 104, 228,   2,  71,
   0,   0, 214,   1,   2,   1,   3,   4,  59, 208,  48,  94, 253,   2,  36,   0,
 104, 253,   2,  94, 254,   2,  36,   1, 104, 254,   2,  94, 255,   2,  36,   2,
 104, 255,   2,  94, 128,   3,  36,   3, 104, 128,   3,  94, 129,   3,  36,   4,
 104, 129,   3,  94, 130,   3,  36,   1, 104, 130,   3,  94, 131,   3,  36,   2,
 104, 131,   3,  71,   0,   0, 219,   1,   1,   1,   4,   5,   6, 208,  48, 208,
  73,   0,  71,   0,   0, 220,   1,   2,   1,   1,   3,  22, 208,  48, 101,   0,
  93,  19, 102,  19,  48,  93, 144,   3, 102, 144,   3,  88,  35,  29, 104, 143,
   3,  71,   0,   0, 221,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,
 223,   1,   2,   2,   4,   5,  13, 208,  48, 208,  73,   0, 208, 209,  70, 146,
   3,   1,  41,  71,   0,   0, 224,   1,   2,   1,   1,   3,  22, 208,  48, 101,
   0,  93,  19, 102,  19,  48,  93, 149,   3, 102, 149,   3,  88,  36,  29, 104,
 148,   3,  71,   0,   0, 225,   1,   2,   1,   3,   4,  21, 208,  48,  94, 151,
   3,  44, 182,   2, 104, 151,   3,  94, 152,   3,  44, 184,   2, 104, 152,   3,
  71,   0,   0, 226,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,
   0,   0, 227,   1,   2,   1,   1,   3,  22, 208,  48, 101,   0,  93,  19, 102,
  19,  48,  93, 156,   3, 102, 156,   3,  88,  37,  29, 104, 155,   3,  71,   0,
   0, 228,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 235,   1,   1,
   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 236,   1,   2,   1,
   1,   3,  22, 208,  48, 101,   0,  93,  19, 102,  19,  48,  93, 165,   3, 102,
 165,   3,  88,  38,  29, 104, 158,   3,  71,   0,   0};


/* versioned_uris */
const char* const shell_toplevel_versioned_uris[] = {
    "__AS3__.vec", // [660]
    "avmplus", // [660]
    "avmshell", // [660, 661, 662, 663, 664, 665, 666]
    "flash.errors", // [660]
    "flash.sampler", // [660]
    "flash.system", // [660]
    "flash.trace", // [660]
    "flash.utils", // [660]
    NULL
};

} }
