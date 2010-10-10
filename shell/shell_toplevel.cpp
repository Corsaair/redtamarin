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

const uint32_t shell_toplevel_abc_class_count = 22;
const uint32_t shell_toplevel_abc_script_count = 17;
const uint32_t shell_toplevel_abc_method_count = 425;
const uint32_t shell_toplevel_abc_length = 26551;

/* thunks (54 unique signatures, 265 total) */

#ifndef VMCFG_INDIRECT_NATIVE_THUNKS

AvmBox avmplus_Domain_currentDomain_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::DomainClass* const obj = (::avmshell::DomainClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    ::avmshell::DomainObject* const ret = obj->get_currentDomain();
    return (AvmBox) ret;
}
AvmBox avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::DomainClass* const obj = (::avmshell::DomainClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
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
    ::avmshell::DomainObject* const obj = (::avmshell::DomainObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->init(
        (::avmshell::DomainObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
AvmBox avmplus_Domain_loadBytes_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::DomainObject* const obj = (::avmshell::DomainObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBox const ret = obj->loadBytes(
        (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
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
    ::avmshell::DomainObject* const obj = (::avmshell::DomainObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
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
    ::avmshell::DomainObject* const obj = (::avmshell::DomainObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    ::avmshell::ByteArrayObject* const ret = obj->get_domainMemory();
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
    ::avmshell::DomainObject* const obj = (::avmshell::DomainObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->set_domainMemory(
        (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
AvmBox flash_utils_ByteArray_readFile_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::ByteArrayClass* const obj = (::avmshell::ByteArrayClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    ::avmshell::ByteArrayObject* const ret = obj->readFile(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox flash_utils_ByteArray_writeFile_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::ByteArrayObject* const obj = (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->writeFile(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
AvmBox flash_utils_ByteArray_readBytes_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmObject
        , argoff3 = argoff2 + AvmThunkArgSize_uint32_t
    };
    (void)env;
    ::avmshell::ByteArrayObject* const obj = (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->readBytes(
        (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
        , (argc < 2 ? AvmThunkCoerce_int32_t_uint32_t(0) : AvmThunkUnbox_uint32_t(argv[argoff2]))
        , (argc < 3 ? AvmThunkCoerce_int32_t_uint32_t(0) : AvmThunkUnbox_uint32_t(argv[argoff3]))
    );
    return kAvmThunkUndefined;
}
AvmBox flash_utils_ByteArray_writeBytes_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmObject
        , argoff3 = argoff2 + AvmThunkArgSize_uint32_t
    };
    (void)env;
    ::avmshell::ByteArrayObject* const obj = (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->writeBytes(
        (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
        , (argc < 2 ? AvmThunkCoerce_int32_t_uint32_t(0) : AvmThunkUnbox_uint32_t(argv[argoff2]))
        , (argc < 3 ? AvmThunkCoerce_int32_t_uint32_t(0) : AvmThunkUnbox_uint32_t(argv[argoff3]))
    );
    return kAvmThunkUndefined;
}
AvmBox flash_utils_ByteArray_writeBoolean_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::ByteArrayObject* const obj = (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->writeBoolean(
        AvmThunkUnbox_AvmBool32(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
AvmBox flash_utils_ByteArray_writeByte_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::ByteArrayObject* const obj = (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->writeByte(
        AvmThunkUnbox_int32_t(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
AvmBox flash_utils_ByteArray_writeShort_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::ByteArrayObject* const obj = (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->writeShort(
        AvmThunkUnbox_int32_t(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
AvmBox flash_utils_ByteArray_writeInt_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::ByteArrayObject* const obj = (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->writeInt(
        AvmThunkUnbox_int32_t(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
AvmBox flash_utils_ByteArray_writeUnsignedInt_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::ByteArrayObject* const obj = (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->writeUnsignedInt(
        AvmThunkUnbox_uint32_t(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
AvmBox flash_utils_ByteArray_writeFloat_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::ByteArrayObject* const obj = (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->writeFloat(
        AvmThunkUnbox_double(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
AvmBox flash_utils_ByteArray_writeDouble_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::ByteArrayObject* const obj = (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->writeDouble(
        AvmThunkUnbox_double(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
AvmBox flash_utils_ByteArray_writeUTF_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::ByteArrayObject* const obj = (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->writeUTF(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
AvmBox flash_utils_ByteArray_writeUTFBytes_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::ByteArrayObject* const obj = (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->writeUTFBytes(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
AvmBox flash_utils_ByteArray_readBoolean_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::ByteArrayObject* const obj = (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBool32 const ret = obj->readBoolean();
    return (AvmBox) ret;
}
AvmBox flash_utils_ByteArray_readByte_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::ByteArrayObject* const obj = (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->readByte();
    return (AvmBox) ret;
}
AvmBox flash_utils_ByteArray_readUnsignedByte_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::ByteArrayObject* const obj = (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    uint32_t const ret = obj->readUnsignedByte();
    return (AvmBox) ret;
}
AvmBox flash_utils_ByteArray_readShort_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::ByteArrayObject* const obj = (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->readShort();
    return (AvmBox) ret;
}
AvmBox flash_utils_ByteArray_readUnsignedShort_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::ByteArrayObject* const obj = (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    uint32_t const ret = obj->readUnsignedShort();
    return (AvmBox) ret;
}
AvmBox flash_utils_ByteArray_readInt_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::ByteArrayObject* const obj = (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->readInt();
    return (AvmBox) ret;
}
AvmBox flash_utils_ByteArray_readUnsignedInt_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::ByteArrayObject* const obj = (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    uint32_t const ret = obj->readUnsignedInt();
    return (AvmBox) ret;
}
double flash_utils_ByteArray_readFloat_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::ByteArrayObject* const obj = (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    double const ret = obj->readFloat();
    return ret;
}
double flash_utils_ByteArray_readDouble_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::ByteArrayObject* const obj = (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    double const ret = obj->readDouble();
    return ret;
}
AvmBox flash_utils_ByteArray_readUTF_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::ByteArrayObject* const obj = (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->readUTF();
    return (AvmBox) ret;
}
AvmBox flash_utils_ByteArray_readUTFBytes_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::ByteArrayObject* const obj = (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->readUTFBytes(
        AvmThunkUnbox_uint32_t(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox flash_utils_ByteArray_length_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::ByteArrayObject* const obj = (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    uint32_t const ret = obj->get_length();
    return (AvmBox) ret;
}
AvmBox flash_utils_ByteArray_length_set_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::ByteArrayObject* const obj = (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->set_length(
        AvmThunkUnbox_uint32_t(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
AvmBox flash_utils_ByteArray_private_zlib_compress_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::ByteArrayObject* const obj = (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->zlib_compress();
    return kAvmThunkUndefined;
}
AvmBox flash_utils_ByteArray_private_zlib_uncompress_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::ByteArrayObject* const obj = (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->zlib_uncompress();
    return kAvmThunkUndefined;
}
AvmBox flash_utils_ByteArray_private__toString_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::ByteArrayObject* const obj = (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->_toString();
    return (AvmBox) ret;
}
AvmBox flash_utils_ByteArray_bytesAvailable_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::ByteArrayObject* const obj = (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    uint32_t const ret = obj->get_bytesAvailable();
    return (AvmBox) ret;
}
AvmBox flash_utils_ByteArray_position_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::ByteArrayObject* const obj = (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    uint32_t const ret = obj->get_position();
    return (AvmBox) ret;
}
AvmBox flash_utils_ByteArray_position_set_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::ByteArrayObject* const obj = (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->set_position(
        AvmThunkUnbox_uint32_t(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
AvmBox flash_utils_ByteArray_endian_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::ByteArrayObject* const obj = (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->get_endian();
    return (AvmBox) ret;
}
AvmBox flash_utils_ByteArray_endian_set_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::ByteArrayObject* const obj = (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->set_endian(
        AvmThunkUnbox_AvmString(argv[argoff1])
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
AvmBox avmplus_FileSystem_exists_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::FileSystemClass* const obj = (::avmshell::FileSystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBool32 const ret = obj->exists(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox avmplus_FileSystem_read_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::FileSystemClass* const obj = (::avmshell::FileSystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->read(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox avmplus_FileSystem_write_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmString
    };
    (void)argc;
    (void)env;
    ::avmshell::FileSystemClass* const obj = (::avmshell::FileSystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->write(
        AvmThunkUnbox_AvmString(argv[argoff1])
        , AvmThunkUnbox_AvmString(argv[argoff2])
    );
    return kAvmThunkUndefined;
}
AvmBox avmplus_FileSystem_getFileMode_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::FileSystemClass* const obj = (::avmshell::FileSystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->getFileMode(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox avmplus_FileSystem_isRegularFile_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::FileSystemClass* const obj = (::avmshell::FileSystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBool32 const ret = obj->isRegularFile(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox avmplus_FileSystem_isDirectory_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::FileSystemClass* const obj = (::avmshell::FileSystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBool32 const ret = obj->isDirectory(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox avmplus_FileSystem_listFiles_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmString
    };
    (void)env;
    ::avmshell::FileSystemClass* const obj = (::avmshell::FileSystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    ArrayObject* const ret = obj->listFiles(
        AvmThunkUnbox_AvmString(argv[argoff1])
        , (argc < 2 ? false : AvmThunkUnbox_AvmBool32(argv[argoff2]))
    );
    return (AvmBox) ret;
}
double avmplus_FileSystem_getFreeDiskSpace_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::FileSystemClass* const obj = (::avmshell::FileSystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    double const ret = obj->getFreeDiskSpace(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return ret;
}
double avmplus_FileSystem_getTotalDiskSpace_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::FileSystemClass* const obj = (::avmshell::FileSystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    double const ret = obj->getTotalDiskSpace(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return ret;
}
AvmBox avmplus_OperatingSystem_private_getName_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::OperatingSystemClass* const obj = (::avmshell::OperatingSystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->getName();
    return (AvmBox) ret;
}
AvmBox avmplus_OperatingSystem_private_getNodeName_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::OperatingSystemClass* const obj = (::avmshell::OperatingSystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->getNodeName();
    return (AvmBox) ret;
}
AvmBox avmplus_OperatingSystem_private_getRelease_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::OperatingSystemClass* const obj = (::avmshell::OperatingSystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->getRelease();
    return (AvmBox) ret;
}
AvmBox avmplus_OperatingSystem_private_getVersion_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::OperatingSystemClass* const obj = (::avmshell::OperatingSystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->getVersion();
    return (AvmBox) ret;
}
AvmBox avmplus_OperatingSystem_private_getMachine_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::OperatingSystemClass* const obj = (::avmshell::OperatingSystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->getMachine();
    return (AvmBox) ret;
}
AvmBox avmplus_OperatingSystem_private_getVendorVersion_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::OperatingSystemClass* const obj = (::avmshell::OperatingSystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->getVendorVersion();
    return (AvmBox) ret;
}
AvmBox avmplus_OperatingSystem_private_getUserName_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::OperatingSystemClass* const obj = (::avmshell::OperatingSystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->getUserName();
    return (AvmBox) ret;
}
AvmBox avmplus_Socket_lastError_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SocketClass* const obj = (::avmshell::SocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_lastError();
    return (AvmBox) ret;
}
AvmBox avmplus_Socket_private_name2ip_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::SocketClass* const obj = (::avmshell::SocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->name2ip(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox avmplus_Socket_ip2name_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::SocketClass* const obj = (::avmshell::SocketClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->ip2name(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox avmplus_Socket_private_lastDataSent_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SocketObject* const obj = (::avmshell::SocketObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get_lastDataSent();
    return (AvmBox) ret;
}
AvmBox avmplus_Socket_private_receivedBuffer_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SocketObject* const obj = (::avmshell::SocketObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->get_receivedBuffer();
    return (AvmBox) ret;
}
AvmBox avmplus_Socket_private_receivedBinary_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SocketObject* const obj = (::avmshell::SocketObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    ::avmshell::ByteArrayObject* const ret = obj->get_receivedBinary();
    return (AvmBox) ret;
}
AvmBox avmplus_Socket_private_isValid_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SocketObject* const obj = (::avmshell::SocketObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBool32 const ret = obj->isValid();
    return (AvmBox) ret;
}
AvmBox avmplus_Socket_private__customSocket_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_int32_t
        , argoff3 = argoff2 + AvmThunkArgSize_int32_t
    };
    (void)argc;
    (void)env;
    ::avmshell::SocketObject* const obj = (::avmshell::SocketObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->_customSocket(
        AvmThunkUnbox_int32_t(argv[argoff1])
        , AvmThunkUnbox_int32_t(argv[argoff2])
        , AvmThunkUnbox_int32_t(argv[argoff3])
    );
    return kAvmThunkUndefined;
}
AvmBox avmplus_Socket_private__connect_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmString
    };
    (void)argc;
    (void)env;
    ::avmshell::SocketObject* const obj = (::avmshell::SocketObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBool32 const ret = obj->_connect(
        AvmThunkUnbox_AvmString(argv[argoff1])
        , AvmThunkUnbox_AvmString(argv[argoff2])
    );
    return (AvmBox) ret;
}
AvmBox avmplus_Socket_private__close_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SocketObject* const obj = (::avmshell::SocketObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBool32 const ret = obj->_close();
    return (AvmBox) ret;
}
AvmBox avmplus_Socket_private__send_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmString
    };
    (void)env;
    ::avmshell::SocketObject* const obj = (::avmshell::SocketObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->_send(
        AvmThunkUnbox_AvmString(argv[argoff1])
        , (argc < 2 ? 0 : AvmThunkUnbox_int32_t(argv[argoff2]))
    );
    return (AvmBox) ret;
}
AvmBox avmplus_Socket_private__sendBinary_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmObject
    };
    (void)env;
    ::avmshell::SocketObject* const obj = (::avmshell::SocketObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->_sendBinary(
        (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
        , (argc < 2 ? 0 : AvmThunkUnbox_int32_t(argv[argoff2]))
    );
    return (AvmBox) ret;
}
AvmBox avmplus_Socket_private__receive_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)env;
    ::avmshell::SocketObject* const obj = (::avmshell::SocketObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->_receive(
        (argc < 1 ? 0 : AvmThunkUnbox_int32_t(argv[argoff1]))
    );
    return (AvmBox) ret;
}
AvmBox avmplus_Socket_private__receiveBinary_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)env;
    ::avmshell::SocketObject* const obj = (::avmshell::SocketObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->_receiveBinary(
        (argc < 1 ? 0 : AvmThunkUnbox_int32_t(argv[argoff1]))
    );
    return (AvmBox) ret;
}
AvmBox avmplus_Socket_private__bind_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::SocketObject* const obj = (::avmshell::SocketObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBool32 const ret = obj->_bind(
        AvmThunkUnbox_int32_t(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox avmplus_Socket_private__listen_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::SocketObject* const obj = (::avmshell::SocketObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBool32 const ret = obj->_listen(
        AvmThunkUnbox_int32_t(argv[argoff1])
    );
    return (AvmBox) ret;
}
AvmBox avmplus_Socket_private__accept_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SocketObject* const obj = (::avmshell::SocketObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    ::avmshell::SocketObject* const ret = obj->_accept();
    return (AvmBox) ret;
}
AvmBox avmplus_Socket_private__type_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SocketObject* const obj = (::avmshell::SocketObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->get__type();
    return (AvmBox) ret;
}
AvmBox avmplus_Socket_reuseAddress_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SocketObject* const obj = (::avmshell::SocketObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBool32 const ret = obj->get_reuseAddress();
    return (AvmBox) ret;
}
AvmBox avmplus_Socket_reuseAddress_set_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::SocketObject* const obj = (::avmshell::SocketObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->set_reuseAddress(
        AvmThunkUnbox_AvmBool32(argv[argoff1])
    );
    return kAvmThunkUndefined;
}
AvmBox avmplus_Socket_broadcast_get_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SocketObject* const obj = (::avmshell::SocketObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBool32 const ret = obj->get_broadcast();
    return (AvmBox) ret;
}
AvmBox avmplus_Socket_broadcast_set_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::SocketObject* const obj = (::avmshell::SocketObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->set_broadcast(
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
AvmBox avmplus_System_private_getExecPath_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    ::avmshell::SystemClass* const obj = (::avmshell::SystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->getExecPath();
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

// avmplus_Socket_private__send
AvmBox shell_toplevel_i2a_osi_opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmString
    };
    (void)env;
    ::avmshell::SocketObject* const obj = (::avmshell::SocketObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->_send(
        AvmThunkUnbox_AvmString(argv[argoff1])
        , (argc < 2 ? 0 : AvmThunkUnbox_int32_t(argv[argoff2]))
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

// flash_sampler_NewObjectSample_size_get
// avmplus_System_freeMemory_get
// avmplus_System_privateMemory_get
// flash_utils_ByteArray_readFloat
// avmplus_System_totalMemory_get
// flash_utils_ByteArray_readDouble
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

// flash_utils_ByteArray_writeBytes
// flash_utils_ByteArray_readBytes
AvmBox shell_toplevel_v2a_oouu_opti0_opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmObject
        , argoff3 = argoff2 + AvmThunkArgSize_uint32_t
    };
    typedef AvmRetType_void (AvmObjectT::*FuncType)(AvmObject, uint32_t, uint32_t);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    (*(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])).*(func))(
        AvmThunkUnbox_AvmObject(argv[argoff1])
        , (argc < 2 ? AvmThunkCoerce_int32_t_uint32_t(0) : AvmThunkUnbox_uint32_t(argv[argoff2]))
        , (argc < 3 ? AvmThunkCoerce_int32_t_uint32_t(0) : AvmThunkUnbox_uint32_t(argv[argoff3]))
    );
    return kAvmThunkUndefined;
}

// flash_utils_ByteArray_readFile
// avmplus_Domain_getClass
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

// C_errno___errno_errno_set
// flash_utils_ByteArray_writeByte
// avmplus_System_exit
// flash_utils_ByteArray_writeInt
// flash_utils_ByteArray_writeShort
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

// avmplus_System_readLine
// avmplus_Socket_private_receivedBuffer_get
// avmplus_OperatingSystem_private_getMachine
// avmplus_OperatingSystem_private_getVendorVersion
// flash_utils_ByteArray_endian_get
// C_unistd___unistd_gethostname
// flash_utils_ByteArray_readUTF
// flash_utils_ByteArray_private__toString
// avmplus_OperatingSystem_private_getName
// avmplus_OperatingSystem_private_getRelease
// avmplus_System_private_getExecPath
// avmplus_OperatingSystem_private_getVersion
// avmplus_System_getAvmplusVersion
// C_unistd___unistd_getlogin
// C_unistd___unistd_getcwd
// avmplus_OperatingSystem_private_getUserName
// avmplus_OperatingSystem_private_getNodeName
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

// avmplus_FileSystem_write
// avmplus_File_write
AvmBox shell_toplevel_v2a_oss_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmString
    };
    (void)argc;
    typedef AvmRetType_void (AvmObjectT::*FuncType)(AvmString, AvmString);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    (*(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])).*(func))(
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

// native_script_function_flash_sampler_pauseSampling
// native_script_function_flash_sampler_clearSamples
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

// flash_utils_ByteArray_readUnsignedShort
// flash_utils_ByteArray_bytesAvailable_get
// flash_utils_ByteArray_length_get
// flash_utils_ByteArray_readUnsignedInt
// flash_utils_ByteArray_readUnsignedByte
// avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get
// avmplus_System_getTimer
// flash_utils_ByteArray_position_get
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

// C_socket___socket___gethostbyname
// C_socket___socket___gethostbyaddr
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

// avmplus_FileSystem_listFiles
AvmBox shell_toplevel_a2a_osb_optbfalse_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmString
    };
    (void)env;
    ::avmshell::FileSystemClass* const obj = (::avmshell::FileSystemClass*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    ArrayObject* const ret = obj->listFiles(
        AvmThunkUnbox_AvmString(argv[argoff1])
        , (argc < 2 ? false : AvmThunkUnbox_AvmBool32(argv[argoff2]))
    );
    return (AvmBox) ret;
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

// C_errno___errno_ENXIO_get
// C_socket___socket_SHUT_RDWR_get
// C_socket___socket_SOMAXCONN_get
// C_errno___errno_EPIPE_get
// C_errno___errno_ETIMEDOUT_get
// flash_utils_ByteArray_readShort
// C_unistd___unistd_S_IRWXG_get
// C_errno___errno_ENETUNREACH_get
// C_socket___socket_SO_RCVBUF_get
// C_socket___socket_SO_TYPE_get
// C_errno___errno_ENODEV_get
// C_errno___errno_ESPIPE_get
// C_errno___errno_EINVAL_get
// C_errno___errno_ESHUTDOWN_get
// C_stdio___stdio_PATH_MAX_get
// C_socket___socket_SO_KEEPALIVE_get
// C_unistd___unistd_S_IEXEC_get
// avmplus_Socket_private__type_get
// C_socket___socket_AF_INET6_get
// C_errno___errno_ECHILD_get
// C_stdlib___stdlib_EXIT_SUCCESS_get
// C_errno___errno_EINTR_get
// C_errno___errno_ECONNRESET_get
// C_errno___errno_ENOENT_get
// C_errno___errno_EISDIR_get
// C_unistd___unistd_W_OK_get
// C_errno___errno_ENOTTY_get
// C_errno___errno_EILSEQ_get
// C_socket___socket_SOCK_RAW_get
// C_errno___errno_ENOLCK_get
// C_socket___socket_INADDR_BROADCAST_get
// C_unistd___unistd_S_IWUSR_get
// C_errno___errno_EFAULT_get
// C_socket___socket_MSG_WAITALL_get
// C_socket___socket_SO_DONTROUTE_get
// C_unistd___unistd_S_IRWXO_get
// C_errno___errno_EMLINK_get
// C_errno___errno_ENOTEMPTY_get
// C_socket___socket_SO_OOBINLINE_get
// C_socket___socket_IPPROTO_IPV6_get
// C_errno___errno_EACCES_get
// C_socket___socket_SO_SNDTIMEO_get
// C_unistd___unistd_S_IRGRP_get
// C_socket___socket_SO_SNDBUF_get
// C_unistd___unistd_S_IFIFO_get
// C_errno___errno_EEXIST_get
// C_errno___errno_ENETRESET_get
// C_unistd___unistd_S_IFSOCK_get
// C_socket___socket_MSG_DONTROUTE_get
// C_socket___socket_MSG_TRUNC_get
// C_socket___socket_SO_RCVTIMEO_get
// C_stdio___stdio_FILENAME_MAX_get
// C_errno___errno_EBADF_get
// C_errno___errno_ENOBUFS_get
// flash_utils_ByteArray_readInt
// C_unistd___unistd_S_IWRITE_get
// C_errno___errno_ENFILE_get
// C_errno___errno_E2BIG_get
// C_unistd___unistd_F_OK_get
// C_unistd___unistd_S_IROTH_get
// C_unistd___unistd_S_IXUSR_get
// C_errno___errno_ECONNREFUSED_get
// C_errno___errno_EDOM_get
// C_errno___errno_EFBIG_get
// C_unistd___unistd_S_IWGRP_get
// C_errno___errno_ECONNABORTED_get
// C_socket___socket_IPPROTO_TCP_get
// C_socket___socket_SO_REUSEADDR_get
// C_unistd___unistd_S_IXGRP_get
// C_errno___errno_ENETDOWN_get
// C_errno___errno_EIO_get
// C_errno___errno_errno_get
// C_socket___socket_AF_UNSPEC_get
// C_socket___socket_SOCK_DGRAM_get
// C_socket___socket_IPPROTO_IP_get
// C_unistd___unistd_S_IFREG_get
// C_errno___errno_ENOSYS_get
// C_unistd___unistd_S_IFBLK_get
// C_errno___errno_EDEADLK_get
// C_unistd___unistd_S_IRWXU_get
// C_socket___socket_SOCK_STREAM_get
// C_unistd___unistd_S_IFCHR_get
// C_unistd___unistd_S_IWOTH_get
// C_socket___socket_IPPROTO_UDP_get
// C_unistd___unistd_S_IXOTH_get
// C_socket___socket_SO_ACCEPTCONN_get
// C_unistd___unistd_S_IFLNK_get
// C_errno___errno_ENOSPC_get
// C_socket___socket_INADDR_ANY_get
// C_socket___socket_SHUT_RD_get
// C_unistd___unistd_S_IFMT_get
// C_errno___errno_ESRCH_get
// C_errno___errno_ENOMEM_get
// C_errno___errno_ENAMETOOLONG_get
// C_socket___socket_MSG_CTRUNC_get
// C_unistd___unistd_R_OK_get
// flash_utils_ByteArray_readByte
// C_unistd___unistd_S_IREAD_get
// C_errno___errno_EISCONN_get
// C_socket___socket_AF_INET_get
// C_errno___errno_EROFS_get
// C_socket___socket_SO_BROADCAST_get
// C_errno___errno_EMFILE_get
// avmplus_Socket_lastError_get
// C_socket___socket_MSG_OOB_get
// C_errno___errno_ERANGE_get
// avmplus_Socket_private_lastDataSent_get
// C_socket___socket_SHUT_WR_get
// C_socket___socket_IPPROTO_ICMP_get
// C_socket___socket_MSG_PEEK_get
// C_unistd___unistd_X_OK_get
// C_errno___errno_ENOEXEC_get
// C_errno___errno_ENOTDIR_get
// C_errno___errno_EXDEV_get
// C_unistd___unistd_S_IRUSR_get
// C_stdlib___stdlib_EXIT_FAILURE_get
// C_errno___errno_ENOTCONN_get
// C_errno___errno_EAGAIN_get
// C_unistd___unistd_S_IFDIR_get
// C_errno___errno_EBUSY_get
// C_errno___errno_ETOOMANYREFS_get
// C_socket___socket_IPPROTO_RAW_get
// C_errno___errno_EPERM_get
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

// avmplus_FileSystem_getTotalDiskSpace
// avmplus_FileSystem_getFreeDiskSpace
double shell_toplevel_d2d_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    typedef AvmRetType_double (AvmObjectT::*FuncType)(AvmString);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (*(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])).*(func))(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
}

// C_stdio___stdio_remove
// avmplus_FileSystem_getFileMode
// C_unistd___unistd_rmdir
// avmplus_System_exec
// C_unistd___unistd_mkdir
// C_stdlib___stdlib_unsetenv
// C_stdlib___stdlib___system
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
// avmplus_Socket_ip2name
// C_stdlib___stdlib_realpath
// avmplus_Socket_private_name2ip
// avmplus_File_read
// avmplus_FileSystem_read
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

// avmplus_Socket_private__sendBinary
AvmBox shell_toplevel_i2a_ooi_opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmObject
    };
    (void)env;
    ::avmshell::SocketObject* const obj = (::avmshell::SocketObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    int32_t const ret = obj->_sendBinary(
        (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmObject(argv[argoff1])
        , (argc < 2 ? 0 : AvmThunkUnbox_int32_t(argv[argoff2]))
    );
    return (AvmBox) ret;
}

// flash_utils_ByteArray_readUTFBytes
AvmBox shell_toplevel_s2a_ou_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    (void)env;
    ::avmshell::ByteArrayObject* const obj = (::avmshell::ByteArrayObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmString const ret = obj->readUTFBytes(
        AvmThunkUnbox_uint32_t(argv[argoff1])
    );
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

// native_script_function_flash_sampler_getSavedThis
// native_script_function_flash_sampler_getLexicalScopes
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

// avmplus_Socket_private__listen
// avmplus_Socket_private__bind
AvmBox shell_toplevel_b2a_oi_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    typedef AvmRetType_AvmBool32 (AvmObjectT::*FuncType)(int32_t);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (AvmBox)(*(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])).*(func))(
        AvmThunkUnbox_int32_t(argv[argoff1])
    );
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

// avmplus_FileSystem_isRegularFile
// avmplus_FileSystem_isDirectory
// avmplus_FileSystem_exists
// avmplus_File_exists
AvmBox shell_toplevel_b2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    typedef AvmRetType_AvmBool32 (AvmObjectT::*FuncType)(AvmString);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (AvmBox)(*(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])).*(func))(
        AvmThunkUnbox_AvmString(argv[argoff1])
    );
}

// avmplus_Domain_currentDomain_get
// avmplus_System_private_getArgv
// avmplus_Socket_private_receivedBinary_get
// flash_trace_Trace_getListener
// avmplus_Socket_private__accept
// flash_sampler_NewObjectSample_object_get
// avmplus_Domain_domainMemory_get
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

// avmplus_Socket_private__customSocket
AvmBox shell_toplevel_v2a_oiii_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_int32_t
        , argoff3 = argoff2 + AvmThunkArgSize_int32_t
    };
    (void)argc;
    (void)env;
    ::avmshell::SocketObject* const obj = (::avmshell::SocketObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    obj->_customSocket(
        AvmThunkUnbox_int32_t(argv[argoff1])
        , AvmThunkUnbox_int32_t(argv[argoff2])
        , AvmThunkUnbox_int32_t(argv[argoff3])
    );
    return kAvmThunkUndefined;
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

// flash_utils_ByteArray_writeDouble
// flash_utils_ByteArray_writeFloat
AvmBox shell_toplevel_v2a_od_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    typedef AvmRetType_void (AvmObjectT::*FuncType)(double);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    (*(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])).*(func))(
        AvmThunkUnbox_double(argv[argoff1])
    );
    return kAvmThunkUndefined;
}

// avmplus_Socket_private__receive
// avmplus_Socket_private__receiveBinary
AvmBox shell_toplevel_i2a_oi_opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    typedef AvmRetType_int32_t (AvmObjectT::*FuncType)(int32_t);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (AvmBox)(*(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])).*(func))(
        (argc < 1 ? 0 : AvmThunkUnbox_int32_t(argv[argoff1]))
    );
}

// avmplus_Socket_reuseAddress_set
// avmplus_Socket_broadcast_set
// flash_utils_ByteArray_writeBoolean
// flash_utils_Dictionary_private_init
AvmBox shell_toplevel_v2a_ob_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    typedef AvmRetType_void (AvmObjectT::*FuncType)(AvmBool32);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    (*(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])).*(func))(
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

// avmplus_Domain_domainMemory_set
// avmplus_System_trace
// avmplus_Domain_private_init
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

// flash_utils_ByteArray_private_zlib_compress
// flash_utils_ByteArray_private_zlib_uncompress
// avmplus_System_forceFullCollection
// avmplus_System_debugger
// avmplus_System_queueCollection
// C_stdlib___stdlib_abort
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

// flash_utils_ByteArray_position_set
// C_unistd___unistd_sleep
// flash_utils_ByteArray_length_set
// flash_utils_ByteArray_writeUnsignedInt
AvmBox shell_toplevel_v2a_ou_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    typedef AvmRetType_void (AvmObjectT::*FuncType)(uint32_t);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    (*(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])).*(func))(
        AvmThunkUnbox_uint32_t(argv[argoff1])
    );
    return kAvmThunkUndefined;
}

// avmplus_Socket_private_isValid
// avmplus_Socket_broadcast_get
// flash_utils_ByteArray_readBoolean
// avmplus_Socket_reuseAddress_get
// avmplus_System_isDebugger
// avmplus_Socket_private__close
AvmBox shell_toplevel_b2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    typedef AvmRetType_AvmBool32 (AvmObjectT::*FuncType)();
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    return (AvmBox)(*(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])).*(func))(
    );
}

// flash_utils_ByteArray_writeUTF
// flash_utils_ByteArray_endian_set
// flash_utils_ByteArray_writeFile
// avmplus_System_write
// flash_utils_ByteArray_writeUTFBytes
AvmBox shell_toplevel_v2a_os_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
    };
    (void)argc;
    typedef AvmRetType_void (AvmObjectT::*FuncType)(AvmString);
    const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_METHOD_HANDLER(env));
    (*(AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0])).*(func))(
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

// avmplus_Socket_private__connect
AvmBox shell_toplevel_b2a_oss_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_AvmObject
        , argoff2 = argoff1 + AvmThunkArgSize_AvmString
    };
    (void)argc;
    (void)env;
    ::avmshell::SocketObject* const obj = (::avmshell::SocketObject*)AvmThunkUnbox_AvmReceiver(AvmObject, argv[argoff0]);
    AvmBool32 const ret = obj->_connect(
        AvmThunkUnbox_AvmString(argv[argoff1])
        , AvmThunkUnbox_AvmString(argv[argoff2])
    );
    return (AvmBox) ret;
}

// C_unistd___unistd_chmod
// C_unistd___unistd_access
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

// avmplus_JObject_toArray
// avmplus_Domain_loadBytes
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

#endif // VMCFG_INDIRECT_NATIVE_THUNKS

class SlotOffsetsAndAsserts
{
private:
    static uint32_t getSlotOffset(Traits* t, int nameId);
public:
    static const uint16_t s_slotsOffsetSystemClass = offsetof(::avmshell::SystemClass, m_slots_SystemClass);
    static const uint16_t s_slotsOffsetScriptObject = 0;
    static void doSystemClassAsserts(Traits* cTraits, Traits* iTraits);
    static const uint16_t s_slotsOffsetFileClass = 0;
    static void doFileClassAsserts(Traits* cTraits, Traits* iTraits);
    static const uint16_t s_slotsOffsetDomainClass = 0;
    static const uint16_t s_slotsOffsetDomainObject = 0;
    static void doDomainClassAsserts(Traits* cTraits, Traits* iTraits);
    static const uint16_t s_slotsOffsetByteArrayClass = 0;
    static const uint16_t s_slotsOffsetByteArrayObject = 0;
    static void doByteArrayClassAsserts(Traits* cTraits, Traits* iTraits);
    static const uint16_t s_slotsOffsetStackFrameClass = 0;
    static const uint16_t s_slotsOffsetStackFrameObject = offsetof(StackFrameObject, m_slots_StackFrameObject);
    static void doStackFrameClassAsserts(Traits* cTraits, Traits* iTraits);
    static const uint16_t s_slotsOffsetSampleClass = 0;
    static const uint16_t s_slotsOffsetSampleObject = offsetof(SampleObject, m_slots_SampleObject);
    static void doSampleClassAsserts(Traits* cTraits, Traits* iTraits);
    static const uint16_t s_slotsOffsetNewObjectSampleClass = 0;
    static const uint16_t s_slotsOffsetNewObjectSampleObject = offsetof(NewObjectSampleObject, m_slots_NewObjectSampleObject);
    static void doNewObjectSampleClassAsserts(Traits* cTraits, Traits* iTraits);
    static const uint16_t s_slotsOffsetDeleteObjectSampleClass = 0;
    static const uint16_t s_slotsOffsetDeleteObjectSampleObject = offsetof(DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject);
    static void doDeleteObjectSampleClassAsserts(Traits* cTraits, Traits* iTraits);
    static const uint16_t s_slotsOffsetTraceClass = offsetof(TraceClass, m_slots_TraceClass);
    static void doTraceClassAsserts(Traits* cTraits, Traits* iTraits);
    static const uint16_t s_slotsOffsetDictionaryClass = 0;
    static const uint16_t s_slotsOffsetDictionaryObject = 0;
    static void doDictionaryClassAsserts(Traits* cTraits, Traits* iTraits);
    static const uint16_t s_slotsOffsetStdlibClass = 0;
    static void doStdlibClassAsserts(Traits* cTraits, Traits* iTraits);
    static const uint16_t s_slotsOffsetUnistdClass = 0;
    static void doUnistdClassAsserts(Traits* cTraits, Traits* iTraits);
    static const uint16_t s_slotsOffsetCStringClass = 0;
    static void doCStringClassAsserts(Traits* cTraits, Traits* iTraits);
    static const uint16_t s_slotsOffsetCErrnoClass = 0;
    static void doCErrnoClassAsserts(Traits* cTraits, Traits* iTraits);
    static const uint16_t s_slotsOffsetStdioClass = 0;
    static void doStdioClassAsserts(Traits* cTraits, Traits* iTraits);
    static const uint16_t s_slotsOffsetCSocketClass = 0;
    static void doCSocketClassAsserts(Traits* cTraits, Traits* iTraits);
    static const uint16_t s_slotsOffsetFileSystemClass = 0;
    static void doFileSystemClassAsserts(Traits* cTraits, Traits* iTraits);
    static const uint16_t s_slotsOffsetOperatingSystemClass = offsetof(::avmshell::OperatingSystemClass, m_slots_OperatingSystemClass);
    static void doOperatingSystemClassAsserts(Traits* cTraits, Traits* iTraits);
    static const uint16_t s_slotsOffsetSocketClass = 0;
    static const uint16_t s_slotsOffsetSocketObject = offsetof(::avmshell::SocketObject, m_slots_SocketObject);
    static void doSocketClassAsserts(Traits* cTraits, Traits* iTraits);
    static const uint16_t s_slotsOffsetJObjectClass = 0;
    static const uint16_t s_slotsOffsetJObject = 0;
    static void doJObjectClassAsserts(Traits* cTraits, Traits* iTraits);
};
REALLY_INLINE void SlotOffsetsAndAsserts::doSystemClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    MMGC_STATIC_ASSERT(offsetof(::avmshell::SystemClass, m_slots_SystemClass) == s_slotsOffsetSystemClass);
    MMGC_STATIC_ASSERT(offsetof(::avmshell::SystemClass, m_slots_SystemClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(::avmshell::SystemClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(cTraits, 31) == (offsetof(::avmshell::SystemClass, m_slots_SystemClass) + offsetof(_avmshell_SystemClassSlots, m_argv)));
    AvmAssert(getSlotOffset(cTraits, 33) == (offsetof(::avmshell::SystemClass, m_slots_SystemClass) + offsetof(_avmshell_SystemClassSlots, m_executablePath)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::doFileClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::FileClass::EmptySlotsStruct_FileClass) >= 0);
}
REALLY_INLINE void SlotOffsetsAndAsserts::doDomainClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::DomainClass::EmptySlotsStruct_DomainClass) >= 0);
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::DomainObject::EmptySlotsStruct_DomainObject) >= 0);
}
REALLY_INLINE void SlotOffsetsAndAsserts::doByteArrayClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::ByteArrayClass::EmptySlotsStruct_ByteArrayClass) >= 0);
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::ByteArrayObject::EmptySlotsStruct_ByteArrayObject) >= 0);
}
REALLY_INLINE void SlotOffsetsAndAsserts::doStackFrameClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(StackFrameClass::EmptySlotsStruct_StackFrameClass) >= 0);
    MMGC_STATIC_ASSERT(offsetof(StackFrameObject, m_slots_StackFrameObject) == s_slotsOffsetStackFrameObject);
    MMGC_STATIC_ASSERT(offsetof(StackFrameObject, m_slots_StackFrameObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(StackFrameObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(iTraits, 133) == (offsetof(StackFrameObject, m_slots_StackFrameObject) + offsetof(StackFrameObjectSlots, m_name)));
    AvmAssert(getSlotOffset(iTraits, 134) == (offsetof(StackFrameObject, m_slots_StackFrameObject) + offsetof(StackFrameObjectSlots, m_file)));
    AvmAssert(getSlotOffset(iTraits, 135) == (offsetof(StackFrameObject, m_slots_StackFrameObject) + offsetof(StackFrameObjectSlots, m_line)));
    AvmAssert(getSlotOffset(iTraits, 136) == (offsetof(StackFrameObject, m_slots_StackFrameObject) + offsetof(StackFrameObjectSlots, m_scriptID)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::doSampleClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(SampleClass::EmptySlotsStruct_SampleClass) >= 0);
    MMGC_STATIC_ASSERT(offsetof(SampleObject, m_slots_SampleObject) == s_slotsOffsetSampleObject);
    MMGC_STATIC_ASSERT(offsetof(SampleObject, m_slots_SampleObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(SampleObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(iTraits, 138) == (offsetof(SampleObject, m_slots_SampleObject) + offsetof(SampleObjectSlots, m_time)));
    AvmAssert(getSlotOffset(iTraits, 139) == (offsetof(SampleObject, m_slots_SampleObject) + offsetof(SampleObjectSlots, m_stack)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::doNewObjectSampleClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(NewObjectSampleClass::EmptySlotsStruct_NewObjectSampleClass) >= 0);
    MMGC_STATIC_ASSERT(offsetof(NewObjectSampleObject, m_slots_NewObjectSampleObject) == s_slotsOffsetNewObjectSampleObject);
    MMGC_STATIC_ASSERT(offsetof(NewObjectSampleObject, m_slots_NewObjectSampleObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(NewObjectSampleObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(iTraits, 141) == (offsetof(NewObjectSampleObject, m_slots_NewObjectSampleObject) + offsetof(NewObjectSampleObjectSlots, m_id)));
    AvmAssert(getSlotOffset(iTraits, 142) == (offsetof(NewObjectSampleObject, m_slots_NewObjectSampleObject) + offsetof(NewObjectSampleObjectSlots, m_type)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::doDeleteObjectSampleClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(DeleteObjectSampleClass::EmptySlotsStruct_DeleteObjectSampleClass) >= 0);
    MMGC_STATIC_ASSERT(offsetof(DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) == s_slotsOffsetDeleteObjectSampleObject);
    MMGC_STATIC_ASSERT(offsetof(DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(DeleteObjectSampleObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(iTraits, 141) == (offsetof(DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) + offsetof(DeleteObjectSampleObjectSlots, m_id)));
    AvmAssert(getSlotOffset(iTraits, 144) == (offsetof(DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) + offsetof(DeleteObjectSampleObjectSlots, m_size)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::doTraceClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    MMGC_STATIC_ASSERT(offsetof(TraceClass, m_slots_TraceClass) == s_slotsOffsetTraceClass);
    MMGC_STATIC_ASSERT(offsetof(TraceClass, m_slots_TraceClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(TraceClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(cTraits, 178) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_OFF)));
    AvmAssert(getSlotOffset(cTraits, 179) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_METHODS)));
    AvmAssert(getSlotOffset(cTraits, 180) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_METHODS_WITH_ARGS)));
    AvmAssert(getSlotOffset(cTraits, 181) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_METHODS_AND_LINES)));
    AvmAssert(getSlotOffset(cTraits, 182) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_METHODS_AND_LINES_WITH_ARGS)));
    AvmAssert(getSlotOffset(cTraits, 183) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_FILE)));
    AvmAssert(getSlotOffset(cTraits, 184) == (offsetof(TraceClass, m_slots_TraceClass) + offsetof(TraceClassSlots, m_LISTENER)));
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
REALLY_INLINE void SlotOffsetsAndAsserts::doFileSystemClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::FileSystemClass::EmptySlotsStruct_FileSystemClass) >= 0);
}
REALLY_INLINE void SlotOffsetsAndAsserts::doOperatingSystemClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    MMGC_STATIC_ASSERT(offsetof(::avmshell::OperatingSystemClass, m_slots_OperatingSystemClass) == s_slotsOffsetOperatingSystemClass);
    MMGC_STATIC_ASSERT(offsetof(::avmshell::OperatingSystemClass, m_slots_OperatingSystemClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(::avmshell::OperatingSystemClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(cTraits, 857) == (offsetof(::avmshell::OperatingSystemClass, m_slots_OperatingSystemClass) + offsetof(_avmshell_OperatingSystemClassSlots, m_private_UNKNOWN)));
    AvmAssert(getSlotOffset(cTraits, 858) == (offsetof(::avmshell::OperatingSystemClass, m_slots_OperatingSystemClass) + offsetof(_avmshell_OperatingSystemClassSlots, m_private_EMPTY)));
    AvmAssert(getSlotOffset(cTraits, 859) == (offsetof(::avmshell::OperatingSystemClass, m_slots_OperatingSystemClass) + offsetof(_avmshell_OperatingSystemClassSlots, m_private__name)));
    AvmAssert(getSlotOffset(cTraits, 860) == (offsetof(::avmshell::OperatingSystemClass, m_slots_OperatingSystemClass) + offsetof(_avmshell_OperatingSystemClassSlots, m_private__nodename)));
    AvmAssert(getSlotOffset(cTraits, 861) == (offsetof(::avmshell::OperatingSystemClass, m_slots_OperatingSystemClass) + offsetof(_avmshell_OperatingSystemClassSlots, m_private__hostname)));
    AvmAssert(getSlotOffset(cTraits, 862) == (offsetof(::avmshell::OperatingSystemClass, m_slots_OperatingSystemClass) + offsetof(_avmshell_OperatingSystemClassSlots, m_private__release)));
    AvmAssert(getSlotOffset(cTraits, 863) == (offsetof(::avmshell::OperatingSystemClass, m_slots_OperatingSystemClass) + offsetof(_avmshell_OperatingSystemClassSlots, m_private__version)));
    AvmAssert(getSlotOffset(cTraits, 864) == (offsetof(::avmshell::OperatingSystemClass, m_slots_OperatingSystemClass) + offsetof(_avmshell_OperatingSystemClassSlots, m_private__machine)));
    AvmAssert(getSlotOffset(cTraits, 870) == (offsetof(::avmshell::OperatingSystemClass, m_slots_OperatingSystemClass) + offsetof(_avmshell_OperatingSystemClassSlots, m_private__vendor)));
    AvmAssert(getSlotOffset(cTraits, 871) == (offsetof(::avmshell::OperatingSystemClass, m_slots_OperatingSystemClass) + offsetof(_avmshell_OperatingSystemClassSlots, m_private__vendorname)));
    AvmAssert(getSlotOffset(cTraits, 872) == (offsetof(::avmshell::OperatingSystemClass, m_slots_OperatingSystemClass) + offsetof(_avmshell_OperatingSystemClassSlots, m_private__vendorversion)));
    AvmAssert(getSlotOffset(cTraits, 873) == (offsetof(::avmshell::OperatingSystemClass, m_slots_OperatingSystemClass) + offsetof(_avmshell_OperatingSystemClassSlots, m_private__vendordescription)));
    AvmAssert(getSlotOffset(cTraits, 874) == (offsetof(::avmshell::OperatingSystemClass, m_slots_OperatingSystemClass) + offsetof(_avmshell_OperatingSystemClassSlots, m_private__codename)));
    AvmAssert(getSlotOffset(cTraits, 876) == (offsetof(::avmshell::OperatingSystemClass, m_slots_OperatingSystemClass) + offsetof(_avmshell_OperatingSystemClassSlots, m_private__username)));
    AvmAssert(getSlotOffset(cTraits, 879) == (offsetof(::avmshell::OperatingSystemClass, m_slots_OperatingSystemClass) + offsetof(_avmshell_OperatingSystemClassSlots, m_private__linuxDistribID)));
    AvmAssert(getSlotOffset(cTraits, 880) == (offsetof(::avmshell::OperatingSystemClass, m_slots_OperatingSystemClass) + offsetof(_avmshell_OperatingSystemClassSlots, m_private__linuxDistribRelease)));
    AvmAssert(getSlotOffset(cTraits, 881) == (offsetof(::avmshell::OperatingSystemClass, m_slots_OperatingSystemClass) + offsetof(_avmshell_OperatingSystemClassSlots, m_private__linuxDistribCodename)));
    AvmAssert(getSlotOffset(cTraits, 882) == (offsetof(::avmshell::OperatingSystemClass, m_slots_OperatingSystemClass) + offsetof(_avmshell_OperatingSystemClassSlots, m_private__linuxDistribDescription)));
    AvmAssert(getSlotOffset(cTraits, 883) == (offsetof(::avmshell::OperatingSystemClass, m_slots_OperatingSystemClass) + offsetof(_avmshell_OperatingSystemClassSlots, m_private__linuxReleaseFiles)));
    AvmAssert(getSlotOffset(cTraits, 885) == (offsetof(::avmshell::OperatingSystemClass, m_slots_OperatingSystemClass) + offsetof(_avmshell_OperatingSystemClassSlots, m_private__macProductBuildVersion)));
    AvmAssert(getSlotOffset(cTraits, 886) == (offsetof(::avmshell::OperatingSystemClass, m_slots_OperatingSystemClass) + offsetof(_avmshell_OperatingSystemClassSlots, m_private__macSystemVersionFile)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::doSocketClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(::avmshell::SocketClass::EmptySlotsStruct_SocketClass) >= 0);
    MMGC_STATIC_ASSERT(offsetof(::avmshell::SocketObject, m_slots_SocketObject) == s_slotsOffsetSocketObject);
    MMGC_STATIC_ASSERT(offsetof(::avmshell::SocketObject, m_slots_SocketObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(::avmshell::SocketObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(iTraits, 960) == (offsetof(::avmshell::SocketObject, m_slots_SocketObject) + offsetof(_avmshell_SocketObjectSlots, m_private__localAddress)));
    AvmAssert(getSlotOffset(iTraits, 961) == (offsetof(::avmshell::SocketObject, m_slots_SocketObject) + offsetof(_avmshell_SocketObjectSlots, m_private__localPort)));
    AvmAssert(getSlotOffset(iTraits, 962) == (offsetof(::avmshell::SocketObject, m_slots_SocketObject) + offsetof(_avmshell_SocketObjectSlots, m_private__remoteAddress)));
    AvmAssert(getSlotOffset(iTraits, 963) == (offsetof(::avmshell::SocketObject, m_slots_SocketObject) + offsetof(_avmshell_SocketObjectSlots, m_private__remotePort)));
    AvmAssert(getSlotOffset(iTraits, 964) == (offsetof(::avmshell::SocketObject, m_slots_SocketObject) + offsetof(_avmshell_SocketObjectSlots, m_private__connected)));
    AvmAssert(getSlotOffset(iTraits, 965) == (offsetof(::avmshell::SocketObject, m_slots_SocketObject) + offsetof(_avmshell_SocketObjectSlots, m_private__bound)));
    AvmAssert(getSlotOffset(iTraits, 966) == (offsetof(::avmshell::SocketObject, m_slots_SocketObject) + offsetof(_avmshell_SocketObjectSlots, m_private__listening)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::doJObjectClassAsserts(Traits* cTraits, Traits* iTraits)
{
    (void)cTraits; (void)iTraits;
    // MMGC_STATIC_ASSERT(sizeof(JObjectClass::EmptySlotsStruct_JObjectClass) >= 0);
    // MMGC_STATIC_ASSERT(sizeof(JObject::EmptySlotsStruct_JObject) >= 0);
}

AVMTHUNK_NATIVE_CLASS_GLUE(SystemClass, ::avmshell::SystemClass, SlotOffsetsAndAsserts::doSystemClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(FileClass, ::avmshell::FileClass, SlotOffsetsAndAsserts::doFileClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(DomainClass, ::avmshell::DomainClass, SlotOffsetsAndAsserts::doDomainClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(ByteArrayClass, ::avmshell::ByteArrayClass, SlotOffsetsAndAsserts::doByteArrayClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(StackFrameClass, StackFrameClass, SlotOffsetsAndAsserts::doStackFrameClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(SampleClass, SampleClass, SlotOffsetsAndAsserts::doSampleClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(NewObjectSampleClass, NewObjectSampleClass, SlotOffsetsAndAsserts::doNewObjectSampleClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(DeleteObjectSampleClass, DeleteObjectSampleClass, SlotOffsetsAndAsserts::doDeleteObjectSampleClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(TraceClass, TraceClass, SlotOffsetsAndAsserts::doTraceClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(DictionaryClass, DictionaryClass, SlotOffsetsAndAsserts::doDictionaryClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(StdlibClass, ::avmshell::StdlibClass, SlotOffsetsAndAsserts::doStdlibClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(UnistdClass, ::avmshell::UnistdClass, SlotOffsetsAndAsserts::doUnistdClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(CStringClass, ::avmshell::CStringClass, SlotOffsetsAndAsserts::doCStringClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(CErrnoClass, ::avmshell::CErrnoClass, SlotOffsetsAndAsserts::doCErrnoClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(StdioClass, ::avmshell::StdioClass, SlotOffsetsAndAsserts::doStdioClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(CSocketClass, ::avmshell::CSocketClass, SlotOffsetsAndAsserts::doCSocketClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(FileSystemClass, ::avmshell::FileSystemClass, SlotOffsetsAndAsserts::doFileSystemClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(OperatingSystemClass, ::avmshell::OperatingSystemClass, SlotOffsetsAndAsserts::doOperatingSystemClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(SocketClass, ::avmshell::SocketClass, SlotOffsetsAndAsserts::doSocketClassAsserts)
AVMTHUNK_NATIVE_CLASS_GLUE(JObjectClass, JObjectClass, SlotOffsetsAndAsserts::doJObjectClassAsserts)

AVMTHUNK_BEGIN_NATIVE_TABLES(shell_toplevel)

    AVMTHUNK_BEGIN_NATIVE_METHODS(shell_toplevel)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_exit, ::avmshell::SystemClass::exit)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_exec, ::avmshell::SystemClass::exec)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_getAvmplusVersion, ::avmshell::SystemClass::getAvmplusVersion)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_trace, ::avmshell::SystemClass::trace)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_write, ::avmshell::SystemClass::write)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_debugger, ::avmshell::SystemClass::debugger)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_isDebugger, ::avmshell::SystemClass::isDebugger)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_getTimer, ::avmshell::SystemClass::getTimer)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_private_getArgv, ::avmshell::SystemClass::getArgv)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_private_getExecPath, ::avmshell::SystemClass::getExecPath)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_readLine, ::avmshell::SystemClass::readLine)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_totalMemory_get, ::avmshell::SystemClass::get_totalMemory)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_freeMemory_get, ::avmshell::SystemClass::get_freeMemory)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_privateMemory_get, ::avmshell::SystemClass::get_privateMemory)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_forceFullCollection, ::avmshell::SystemClass::forceFullCollection)
        AVMTHUNK_NATIVE_METHOD(avmplus_System_queueCollection, ::avmshell::SystemClass::queueCollection)
        AVMTHUNK_NATIVE_METHOD(avmplus_File_exists, ::avmshell::FileClass::exists)
        AVMTHUNK_NATIVE_METHOD(avmplus_File_read, ::avmshell::FileClass::read)
        AVMTHUNK_NATIVE_METHOD(avmplus_File_write, ::avmshell::FileClass::write)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_currentDomain_get, ::avmshell::DomainClass::get_currentDomain)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_MIN_DOMAIN_MEMORY_LENGTH_get, ::avmshell::DomainClass::get_MIN_DOMAIN_MEMORY_LENGTH)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_private_init, ::avmshell::DomainObject::init)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_loadBytes, ::avmshell::DomainObject::loadBytes)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_getClass, ::avmshell::DomainObject::getClass)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_domainMemory_get, ::avmshell::DomainObject::get_domainMemory)
        AVMTHUNK_NATIVE_METHOD(avmplus_Domain_domainMemory_set, ::avmshell::DomainObject::set_domainMemory)
        AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_readFile, ::avmshell::ByteArrayClass::readFile)
        AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_writeFile, ::avmshell::ByteArrayObject::writeFile)
        AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_readBytes, ::avmshell::ByteArrayObject::readBytes)
        AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_writeBytes, ::avmshell::ByteArrayObject::writeBytes)
        AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_writeBoolean, ::avmshell::ByteArrayObject::writeBoolean)
        AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_writeByte, ::avmshell::ByteArrayObject::writeByte)
        AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_writeShort, ::avmshell::ByteArrayObject::writeShort)
        AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_writeInt, ::avmshell::ByteArrayObject::writeInt)
        AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_writeUnsignedInt, ::avmshell::ByteArrayObject::writeUnsignedInt)
        AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_writeFloat, ::avmshell::ByteArrayObject::writeFloat)
        AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_writeDouble, ::avmshell::ByteArrayObject::writeDouble)
        AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_writeUTF, ::avmshell::ByteArrayObject::writeUTF)
        AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_writeUTFBytes, ::avmshell::ByteArrayObject::writeUTFBytes)
        AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_readBoolean, ::avmshell::ByteArrayObject::readBoolean)
        AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_readByte, ::avmshell::ByteArrayObject::readByte)
        AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_readUnsignedByte, ::avmshell::ByteArrayObject::readUnsignedByte)
        AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_readShort, ::avmshell::ByteArrayObject::readShort)
        AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_readUnsignedShort, ::avmshell::ByteArrayObject::readUnsignedShort)
        AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_readInt, ::avmshell::ByteArrayObject::readInt)
        AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_readUnsignedInt, ::avmshell::ByteArrayObject::readUnsignedInt)
        AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_readFloat, ::avmshell::ByteArrayObject::readFloat)
        AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_readDouble, ::avmshell::ByteArrayObject::readDouble)
        AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_readUTF, ::avmshell::ByteArrayObject::readUTF)
        AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_readUTFBytes, ::avmshell::ByteArrayObject::readUTFBytes)
        AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_length_get, ::avmshell::ByteArrayObject::get_length)
        AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_length_set, ::avmshell::ByteArrayObject::set_length)
        AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_private_zlib_compress, ::avmshell::ByteArrayObject::zlib_compress)
        AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_private_zlib_uncompress, ::avmshell::ByteArrayObject::zlib_uncompress)
        AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_private__toString, ::avmshell::ByteArrayObject::_toString)
        AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_bytesAvailable_get, ::avmshell::ByteArrayObject::get_bytesAvailable)
        AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_position_get, ::avmshell::ByteArrayObject::get_position)
        AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_position_set, ::avmshell::ByteArrayObject::set_position)
        AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_endian_get, ::avmshell::ByteArrayObject::get_endian)
        AVMTHUNK_NATIVE_METHOD(flash_utils_ByteArray_endian_set, ::avmshell::ByteArrayObject::set_endian)
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
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_chmod, ::avmshell::UnistdClass::chmod)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_getcwd, ::avmshell::UnistdClass::getcwd)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_gethostname, ::avmshell::UnistdClass::gethostname)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_getlogin, ::avmshell::UnistdClass::getlogin)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_mkdir, ::avmshell::UnistdClass::mkdir)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_rmdir, ::avmshell::UnistdClass::rmdir)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_sleep, ::avmshell::UnistdClass::sleep)
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
        AVMTHUNK_NATIVE_METHOD(avmplus_FileSystem_exists, ::avmshell::FileSystemClass::exists)
        AVMTHUNK_NATIVE_METHOD(avmplus_FileSystem_read, ::avmshell::FileSystemClass::read)
        AVMTHUNK_NATIVE_METHOD(avmplus_FileSystem_write, ::avmshell::FileSystemClass::write)
        AVMTHUNK_NATIVE_METHOD(avmplus_FileSystem_getFileMode, ::avmshell::FileSystemClass::getFileMode)
        AVMTHUNK_NATIVE_METHOD(avmplus_FileSystem_isRegularFile, ::avmshell::FileSystemClass::isRegularFile)
        AVMTHUNK_NATIVE_METHOD(avmplus_FileSystem_isDirectory, ::avmshell::FileSystemClass::isDirectory)
        AVMTHUNK_NATIVE_METHOD(avmplus_FileSystem_listFiles, ::avmshell::FileSystemClass::listFiles)
        AVMTHUNK_NATIVE_METHOD(avmplus_FileSystem_getFreeDiskSpace, ::avmshell::FileSystemClass::getFreeDiskSpace)
        AVMTHUNK_NATIVE_METHOD(avmplus_FileSystem_getTotalDiskSpace, ::avmshell::FileSystemClass::getTotalDiskSpace)
        AVMTHUNK_NATIVE_METHOD(avmplus_OperatingSystem_private_getName, ::avmshell::OperatingSystemClass::getName)
        AVMTHUNK_NATIVE_METHOD(avmplus_OperatingSystem_private_getNodeName, ::avmshell::OperatingSystemClass::getNodeName)
        AVMTHUNK_NATIVE_METHOD(avmplus_OperatingSystem_private_getRelease, ::avmshell::OperatingSystemClass::getRelease)
        AVMTHUNK_NATIVE_METHOD(avmplus_OperatingSystem_private_getVersion, ::avmshell::OperatingSystemClass::getVersion)
        AVMTHUNK_NATIVE_METHOD(avmplus_OperatingSystem_private_getMachine, ::avmshell::OperatingSystemClass::getMachine)
        AVMTHUNK_NATIVE_METHOD(avmplus_OperatingSystem_private_getVendorVersion, ::avmshell::OperatingSystemClass::getVendorVersion)
        AVMTHUNK_NATIVE_METHOD(avmplus_OperatingSystem_private_getUserName, ::avmshell::OperatingSystemClass::getUserName)
        AVMTHUNK_NATIVE_METHOD(avmplus_Socket_lastError_get, ::avmshell::SocketClass::get_lastError)
        AVMTHUNK_NATIVE_METHOD(avmplus_Socket_private_name2ip, ::avmshell::SocketClass::name2ip)
        AVMTHUNK_NATIVE_METHOD(avmplus_Socket_ip2name, ::avmshell::SocketClass::ip2name)
        AVMTHUNK_NATIVE_METHOD(avmplus_Socket_private_lastDataSent_get, ::avmshell::SocketObject::get_lastDataSent)
        AVMTHUNK_NATIVE_METHOD(avmplus_Socket_private_receivedBuffer_get, ::avmshell::SocketObject::get_receivedBuffer)
        AVMTHUNK_NATIVE_METHOD(avmplus_Socket_private_receivedBinary_get, ::avmshell::SocketObject::get_receivedBinary)
        AVMTHUNK_NATIVE_METHOD(avmplus_Socket_private_isValid, ::avmshell::SocketObject::isValid)
        AVMTHUNK_NATIVE_METHOD(avmplus_Socket_private__customSocket, ::avmshell::SocketObject::_customSocket)
        AVMTHUNK_NATIVE_METHOD(avmplus_Socket_private__connect, ::avmshell::SocketObject::_connect)
        AVMTHUNK_NATIVE_METHOD(avmplus_Socket_private__close, ::avmshell::SocketObject::_close)
        AVMTHUNK_NATIVE_METHOD(avmplus_Socket_private__send, ::avmshell::SocketObject::_send)
        AVMTHUNK_NATIVE_METHOD(avmplus_Socket_private__sendBinary, ::avmshell::SocketObject::_sendBinary)
        AVMTHUNK_NATIVE_METHOD(avmplus_Socket_private__receive, ::avmshell::SocketObject::_receive)
        AVMTHUNK_NATIVE_METHOD(avmplus_Socket_private__receiveBinary, ::avmshell::SocketObject::_receiveBinary)
        AVMTHUNK_NATIVE_METHOD(avmplus_Socket_private__bind, ::avmshell::SocketObject::_bind)
        AVMTHUNK_NATIVE_METHOD(avmplus_Socket_private__listen, ::avmshell::SocketObject::_listen)
        AVMTHUNK_NATIVE_METHOD(avmplus_Socket_private__accept, ::avmshell::SocketObject::_accept)
        AVMTHUNK_NATIVE_METHOD(avmplus_Socket_private__type_get, ::avmshell::SocketObject::get__type)
        AVMTHUNK_NATIVE_METHOD(avmplus_Socket_reuseAddress_get, ::avmshell::SocketObject::get_reuseAddress)
        AVMTHUNK_NATIVE_METHOD(avmplus_Socket_reuseAddress_set, ::avmshell::SocketObject::set_reuseAddress)
        AVMTHUNK_NATIVE_METHOD(avmplus_Socket_broadcast_get, ::avmshell::SocketObject::get_broadcast)
        AVMTHUNK_NATIVE_METHOD(avmplus_Socket_broadcast_set, ::avmshell::SocketObject::set_broadcast)
        AVMTHUNK_NATIVE_METHOD(avmplus_JObject_create, JObjectClass::create)
        AVMTHUNK_NATIVE_METHOD(avmplus_JObject_createArray, JObjectClass::createArray)
        AVMTHUNK_NATIVE_METHOD(avmplus_JObject_toArray, JObjectClass::toArray)
        AVMTHUNK_NATIVE_METHOD(avmplus_JObject_constructorSignature, JObjectClass::constructorSignature)
        AVMTHUNK_NATIVE_METHOD(avmplus_JObject_methodSignature, JObjectClass::methodSignature)
        AVMTHUNK_NATIVE_METHOD(avmplus_JObject_fieldSignature, JObjectClass::fieldSignature)
    AVMTHUNK_END_NATIVE_METHODS()

    AVMTHUNK_BEGIN_NATIVE_CLASSES(shell_toplevel)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_System, SystemClass, ::avmshell::SystemClass, SlotOffsetsAndAsserts::s_slotsOffsetSystemClass, ScriptObject, SlotOffsetsAndAsserts::s_slotsOffsetScriptObject)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_File, FileClass, ::avmshell::FileClass, SlotOffsetsAndAsserts::s_slotsOffsetFileClass, ScriptObject, SlotOffsetsAndAsserts::s_slotsOffsetScriptObject)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_Domain, DomainClass, ::avmshell::DomainClass, SlotOffsetsAndAsserts::s_slotsOffsetDomainClass, ::avmshell::DomainObject, SlotOffsetsAndAsserts::s_slotsOffsetDomainObject)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_utils_ByteArray, ByteArrayClass, ::avmshell::ByteArrayClass, SlotOffsetsAndAsserts::s_slotsOffsetByteArrayClass, ::avmshell::ByteArrayObject, SlotOffsetsAndAsserts::s_slotsOffsetByteArrayObject)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_StackFrame, StackFrameClass, StackFrameClass, SlotOffsetsAndAsserts::s_slotsOffsetStackFrameClass, StackFrameObject, SlotOffsetsAndAsserts::s_slotsOffsetStackFrameObject)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_Sample, SampleClass, SampleClass, SlotOffsetsAndAsserts::s_slotsOffsetSampleClass, SampleObject, SlotOffsetsAndAsserts::s_slotsOffsetSampleObject)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_NewObjectSample, NewObjectSampleClass, NewObjectSampleClass, SlotOffsetsAndAsserts::s_slotsOffsetNewObjectSampleClass, NewObjectSampleObject, SlotOffsetsAndAsserts::s_slotsOffsetNewObjectSampleObject)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_DeleteObjectSample, DeleteObjectSampleClass, DeleteObjectSampleClass, SlotOffsetsAndAsserts::s_slotsOffsetDeleteObjectSampleClass, DeleteObjectSampleObject, SlotOffsetsAndAsserts::s_slotsOffsetDeleteObjectSampleObject)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_trace_Trace, TraceClass, TraceClass, SlotOffsetsAndAsserts::s_slotsOffsetTraceClass, ScriptObject, SlotOffsetsAndAsserts::s_slotsOffsetScriptObject)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_utils_Dictionary, DictionaryClass, DictionaryClass, SlotOffsetsAndAsserts::s_slotsOffsetDictionaryClass, DictionaryObject, SlotOffsetsAndAsserts::s_slotsOffsetDictionaryObject)
        AVMTHUNK_NATIVE_CLASS(abcclass_C_stdlib___stdlib, StdlibClass, ::avmshell::StdlibClass, SlotOffsetsAndAsserts::s_slotsOffsetStdlibClass, ScriptObject, SlotOffsetsAndAsserts::s_slotsOffsetScriptObject)
        AVMTHUNK_NATIVE_CLASS(abcclass_C_unistd___unistd, UnistdClass, ::avmshell::UnistdClass, SlotOffsetsAndAsserts::s_slotsOffsetUnistdClass, ScriptObject, SlotOffsetsAndAsserts::s_slotsOffsetScriptObject)
        AVMTHUNK_NATIVE_CLASS(abcclass_C_string___string, CStringClass, ::avmshell::CStringClass, SlotOffsetsAndAsserts::s_slotsOffsetCStringClass, ScriptObject, SlotOffsetsAndAsserts::s_slotsOffsetScriptObject)
        AVMTHUNK_NATIVE_CLASS(abcclass_C_errno___errno, CErrnoClass, ::avmshell::CErrnoClass, SlotOffsetsAndAsserts::s_slotsOffsetCErrnoClass, ScriptObject, SlotOffsetsAndAsserts::s_slotsOffsetScriptObject)
        AVMTHUNK_NATIVE_CLASS(abcclass_C_stdio___stdio, StdioClass, ::avmshell::StdioClass, SlotOffsetsAndAsserts::s_slotsOffsetStdioClass, ScriptObject, SlotOffsetsAndAsserts::s_slotsOffsetScriptObject)
        AVMTHUNK_NATIVE_CLASS(abcclass_C_socket___socket, CSocketClass, ::avmshell::CSocketClass, SlotOffsetsAndAsserts::s_slotsOffsetCSocketClass, ScriptObject, SlotOffsetsAndAsserts::s_slotsOffsetScriptObject)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_FileSystem, FileSystemClass, ::avmshell::FileSystemClass, SlotOffsetsAndAsserts::s_slotsOffsetFileSystemClass, ScriptObject, SlotOffsetsAndAsserts::s_slotsOffsetScriptObject)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_OperatingSystem, OperatingSystemClass, ::avmshell::OperatingSystemClass, SlotOffsetsAndAsserts::s_slotsOffsetOperatingSystemClass, ScriptObject, SlotOffsetsAndAsserts::s_slotsOffsetScriptObject)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_Socket, SocketClass, ::avmshell::SocketClass, SlotOffsetsAndAsserts::s_slotsOffsetSocketClass, ::avmshell::SocketObject, SlotOffsetsAndAsserts::s_slotsOffsetSocketObject)
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_JObject, JObjectClass, JObjectClass, SlotOffsetsAndAsserts::s_slotsOffsetJObjectClass, JObject, SlotOffsetsAndAsserts::s_slotsOffsetJObject)
    AVMTHUNK_END_NATIVE_CLASSES()

AVMTHUNK_END_NATIVE_TABLES()

AVMTHUNK_DEFINE_NATIVE_INITIALIZER(shell_toplevel)

/* abc */
const uint8_t shell_toplevel_abc_data[26551] = {
  16,   0,  46,   0,   7,   0,   2,   1,   3,   4, 255, 255, 255, 255,  15,   0,
   0, 227,   4,   6,  83, 121, 115, 116, 101, 109,  19, 115, 104, 101, 108, 108,
  95, 116, 111, 112, 108, 101, 118, 101, 108,  46,  97, 115,  36,  49,   0,   7,
  97, 118, 109, 112, 108, 117, 115,   8, 114, 101,  97, 100,  76, 105, 110, 101,
   6,  83, 116, 114, 105, 110, 103,   8, 103, 101, 116,  84, 105, 109, 101, 114,
   4, 117, 105, 110, 116,   5, 116, 114,  97,  99, 101,   4, 118, 111, 105, 100,
   6,  68, 111, 109,  97, 105, 110,  13,  99, 117, 114, 114, 101, 110, 116,  68,
 111, 109,  97, 105, 110,   8, 103, 101, 116,  67, 108,  97, 115, 115,   5,  67,
 108,  97, 115, 115,   8, 100, 101,  98, 117, 103, 103, 101, 114,  14,  97, 118,
 109, 112, 108, 117, 115,  58,  83, 121, 115, 116, 101, 109,   4,  97, 114, 103,
 118,   7, 103, 101, 116,  65, 114, 103, 118,   6,  79,  98, 106, 101,  99, 116,
  14, 101, 120, 101,  99, 117, 116,  97,  98, 108, 101,  80,  97, 116, 104,  11,
 103, 101, 116,  69, 120, 101,  99,  80,  97, 116, 104,   3, 105, 110, 116,   5,
  65, 114, 114,  97, 121,   7,  66, 111, 111, 108, 101,  97, 110,   6,  78, 117,
 109,  98, 101, 114,   3, 238, 138, 148,   4, 101, 120, 105, 116,   4, 101, 120,
 101,  99,  17, 103, 101, 116,  65, 118, 109, 112, 108, 117, 115,  86, 101, 114,
 115, 105, 111, 110,   5, 119, 114, 105, 116, 101,  10, 105, 115,  68, 101,  98,
 117, 103, 103, 101, 114,  11, 116, 111, 116,  97, 108,  77, 101, 109, 111, 114,
 121,  10, 102, 114, 101, 101,  77, 101, 109, 111, 114, 121,  13, 112, 114, 105,
 118,  97, 116, 101,  77, 101, 109, 111, 114, 121,  19, 102, 111, 114,  99, 101,
  70, 117, 108, 108,  67, 111, 108, 108, 101,  99, 116, 105, 111, 110,  15, 113,
 117, 101, 117, 101,  67, 111, 108, 108, 101,  99, 116, 105, 111, 110,  12,  97,
 118, 109, 112, 108, 117, 115,  58,  70, 105, 108, 101,   9,  66, 121, 116, 101,
  65, 114, 114,  97, 121,  11, 102, 108,  97, 115, 104,  46, 117, 116, 105, 108,
 115,   8, 114, 101,  97, 100,  70, 105, 108, 101,   9, 119, 114, 105, 116, 101,
  70, 105, 108, 101,   6, 101, 120, 105, 115, 116, 115,   4, 114, 101,  97, 100,
  15, 102, 105, 108, 101,  84, 111,  66, 121, 116, 101,  65, 114, 114,  97, 121,
  14, 119, 114, 105, 116, 101,  66, 121, 116, 101,  65, 114, 114,  97, 121,   4,
  70, 105, 108, 101,  25, 102, 108,  97, 115, 104,  46, 115, 121, 115, 116, 101,
 109,  58,  67,  97, 112,  97,  98, 105, 108, 105, 116, 105, 101, 115,   7,  65,
  86,  77,  80, 108, 117, 115,  12, 102, 108,  97, 115, 104,  46, 115, 121, 115,
 116, 101, 109,  10, 112, 108,  97, 121, 101, 114,  84, 121, 112, 101,  12,  67,
  97, 112,  97,  98, 105, 108, 105, 116, 105, 101, 115,  10,  97, 118, 109, 112,
 108, 117, 115, 238, 138, 148,   6, 110,  97, 116, 105, 118, 101,   3,  99, 108,
 115,  23,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  83, 121,
 115, 116, 101, 109,  67, 108,  97, 115, 115,   7, 109, 101, 116, 104, 111, 100,
 115,   4,  97, 117, 116, 111,  21,  58,  58,  97, 118, 109, 115, 104, 101, 108,
 108,  58,  58,  70, 105, 108, 101,  67, 108,  97, 115, 115,  15, 102, 108,  97,
 115, 104,  46, 115, 121, 115, 116, 101, 109, 238, 138, 148,  14, 103, 101, 116,
  67, 108,  97, 115, 115,  66, 121,  78,  97, 109, 101,   5, 112, 114, 105, 110,
 116,  14,  97, 118, 109, 112, 108, 117, 115,  58,  68, 111, 109,  97, 105, 110,
   4, 105, 110, 105, 116,  11,  68, 111, 109,  97, 105, 110,  46,  97, 115,  36,
  50,   9, 108, 111,  97, 100,  66, 121, 116, 101, 115,  24,  77,  73,  78,  95,
  68,  79,  77,  65,  73,  78,  95,  77,  69,  77,  79,  82,  89,  95,  76,  69,
  78,  71,  84,  72,   4, 108, 111,  97, 100,  12, 100, 111, 109,  97, 105, 110,
  77, 101, 109, 111, 114, 121,  23,  58,  58,  97, 118, 109, 115, 104, 101, 108,
 108,  58,  58,  68, 111, 109,  97, 105, 110,  67, 108,  97, 115, 115,   8, 105,
 110, 115, 116,  97, 110,  99, 101,  24,  58,  58,  97, 118, 109, 115, 104, 101,
 108, 108,  58,  58,  68, 111, 109,  97, 105, 110,  79,  98, 106, 101,  99, 116,
  21, 102, 108,  97, 115, 104,  46, 117, 116, 105, 108, 115,  58,  66, 121, 116,
 101,  65, 114, 114,  97, 121,  13, 122, 108, 105,  98,  95,  99, 111, 109, 112,
 114, 101, 115, 115,  14,  66, 121, 116, 101,  65, 114, 114,  97, 121,  46,  97,
 115,  36,  51,  15, 122, 108, 105,  98,  95, 117, 110,  99, 111, 109, 112, 114,
 101, 115, 115,   9,  95, 116, 111,  83, 116, 114, 105, 110, 103,   9, 114, 101,
  97, 100,  66, 121, 116, 101, 115,  10, 119, 114, 105, 116, 101,  66, 121, 116,
 101, 115,  12, 119, 114, 105, 116, 101,  66, 111, 111, 108, 101,  97, 110,   9,
 119, 114, 105, 116, 101,  66, 121, 116, 101,  10, 119, 114, 105, 116, 101,  83,
 104, 111, 114, 116,   8, 119, 114, 105, 116, 101,  73, 110, 116,  16, 119, 114,
 105, 116, 101,  85, 110, 115, 105, 103, 110, 101, 100,  73, 110, 116,  10, 119,
 114, 105, 116, 101,  70, 108, 111,  97, 116,  11, 119, 114, 105, 116, 101,  68,
 111, 117,  98, 108, 101,   8, 119, 114, 105, 116, 101,  85,  84,  70,  13, 119,
 114, 105, 116, 101,  85,  84,  70,  66, 121, 116, 101, 115,  11, 114, 101,  97,
 100,  66, 111, 111, 108, 101,  97, 110,   8, 114, 101,  97, 100,  66, 121, 116,
 101,  16, 114, 101,  97, 100,  85, 110, 115, 105, 103, 110, 101, 100,  66, 121,
 116, 101,   9, 114, 101,  97, 100,  83, 104, 111, 114, 116,  17, 114, 101,  97,
 100,  85, 110, 115, 105, 103, 110, 101, 100,  83, 104, 111, 114, 116,   7, 114,
 101,  97, 100,  73, 110, 116,  15, 114, 101,  97, 100,  85, 110, 115, 105, 103,
 110, 101, 100,  73, 110, 116,   9, 114, 101,  97, 100,  70, 108, 111,  97, 116,
  10, 114, 101,  97, 100,  68, 111, 117,  98, 108, 101,   7, 114, 101,  97, 100,
  85,  84,  70,  12, 114, 101,  97, 100,  85,  84,  70,  66, 121, 116, 101, 115,
   6, 108, 101, 110, 103, 116, 104,   8,  99, 111, 109, 112, 114, 101, 115, 115,
  10, 117, 110,  99, 111, 109, 112, 114, 101, 115, 115,   8, 116, 111,  83, 116,
 114, 105, 110, 103,  14,  98, 121, 116, 101, 115,  65, 118,  97, 105, 108,  97,
  98, 108, 101,   8, 112, 111, 115, 105, 116, 105, 111, 110,   6, 101, 110, 100,
 105,  97, 110,  14, 102, 108,  97, 115, 104,  46, 117, 116, 105, 108, 115, 238,
 138, 148,  26,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  66,
 121, 116, 101,  65, 114, 114,  97, 121,  67, 108,  97, 115, 115,  27,  58,  58,
  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  66, 121, 116, 101,  65, 114,
 114,  97, 121,  79,  98, 106, 101,  99, 116,   8,  70, 117, 110,  99, 116, 105,
 111, 110,   5,  81,  78,  97, 109, 101,  19,  95, 103, 101, 116,  73, 110, 118,
 111,  99,  97, 116, 105, 111, 110,  67, 111, 117, 110, 116,  12,  83,  97, 109,
 112, 108, 101, 114,  46,  97, 115,  36,  52,  13, 102, 108,  97, 115, 104,  46,
 115,  97, 109, 112, 108, 101, 114,   1, 102,   1, 101,   3, 114, 101, 116,  19,
  95, 115, 101, 116,  83,  97, 109, 112, 108, 101, 114,  67,  97, 108, 108,  98,
  97,  99, 107,   7, 119, 114,  97, 112, 112, 101, 114,  24, 102, 108,  97, 115,
 104,  46, 115,  97, 109, 112, 108, 101, 114,  58,  83, 116,  97,  99, 107,  70,
 114,  97, 109, 101,   4, 110,  97, 109, 101,   2,  40,  41,   4, 102, 105, 108,
 101,   1,  91,   1,  58,   4, 108, 105, 110, 101,   1,  93,   8, 115,  99, 114,
 105, 112, 116,  73,  68,  10,  83, 116,  97,  99, 107,  70, 114,  97, 109, 101,
  20, 102, 108,  97, 115, 104,  46, 115,  97, 109, 112, 108, 101, 114,  58,  83,
  97, 109, 112, 108, 101,   4, 116, 105, 109, 101,   5, 115, 116,  97,  99, 107,
   6,  83,  97, 109, 112, 108, 101,  29, 102, 108,  97, 115, 104,  46, 115,  97,
 109, 112, 108, 101, 114,  58,  78, 101, 119,  79,  98, 106, 101,  99, 116,  83,
  97, 109, 112, 108, 101,   2, 105, 100,   4, 116, 121, 112, 101,   6, 111,  98,
 106, 101,  99, 116,   4, 115, 105, 122, 101,  15,  78, 101, 119,  79,  98, 106,
 101,  99, 116,  83,  97, 109, 112, 108, 101,  32, 102, 108,  97, 115, 104,  46,
 115,  97, 109, 112, 108, 101, 114,  58,  68, 101, 108, 101, 116, 101,  79,  98,
 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  18,  68, 101, 108, 101, 116,
 101,  79,  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  16, 102, 108,
  97, 115, 104,  46, 115,  97, 109, 112, 108, 101, 114, 238, 138, 148,  15,  83,
 116,  97,  99, 107,  70, 114,  97, 109, 101,  67, 108,  97, 115, 115,  16,  83,
 116,  97,  99, 107,  70, 114,  97, 109, 101,  79,  98, 106, 101,  99, 116,  12,
  99, 111, 110, 115, 116, 115, 101, 116, 116, 101, 114, 115,   4, 116, 114, 117,
 101,  11,  83,  97, 109, 112, 108, 101,  67, 108,  97, 115, 115,  12,  83,  97,
 109, 112, 108, 101,  79,  98, 106, 101,  99, 116,  20,  78, 101, 119,  79,  98,
 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  67, 108,  97, 115, 115,  21,
  78, 101, 119,  79,  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  79,
  98, 106, 101,  99, 116,  23,  68, 101, 108, 101, 116, 101,  79,  98, 106, 101,
  99, 116,  83,  97, 109, 112, 108, 101,  67, 108,  97, 115, 115,  24,  68, 101,
 108, 101, 116, 101,  79,  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,
  79,  98, 106, 101,  99, 116,  12,  99, 108, 101,  97, 114,  83,  97, 109, 112,
 108, 101, 115,  27,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112,
 116,  58,  58,  99, 108, 101,  97, 114,  83,  97, 109, 112, 108, 101, 115,  13,
 115, 116,  97, 114, 116,  83,  97, 109, 112, 108, 105, 110, 103,  28,  83,  97,
 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 115, 116,  97,
 114, 116,  83,  97, 109, 112, 108, 105, 110, 103,  12, 115, 116, 111, 112,  83,
  97, 109, 112, 108, 105, 110, 103,  27,  83,  97, 109, 112, 108, 101, 114,  83,
  99, 114, 105, 112, 116,  58,  58, 115, 116, 111, 112,  83,  97, 109, 112, 108,
 105, 110, 103,  13, 112,  97, 117, 115, 101,  83,  97, 109, 112, 108, 105, 110,
 103,  28,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,
  58, 112,  97, 117, 115, 101,  83,  97, 109, 112, 108, 105, 110, 103,  20, 115,
  97, 109, 112, 108, 101,  73, 110, 116, 101, 114, 110,  97, 108,  65, 108, 108,
 111,  99, 115,  35,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112,
 116,  58,  58, 115,  97, 109, 112, 108, 101,  73, 110, 116, 101, 114, 110,  97,
 108,  65, 108, 108, 111,  99, 115,  18, 115, 101, 116,  83,  97, 109, 112, 108,
 101, 114,  67,  97, 108, 108,  98,  97,  99, 107,  34,  83,  97, 109, 112, 108,
 101, 114,  83,  99, 114, 105, 112, 116,  58,  58,  95, 115, 101, 116,  83,  97,
 109, 112, 108, 101, 114,  67,  97, 108, 108,  98,  97,  99, 107,   7, 103, 101,
 116,  83, 105, 122, 101,  22,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114,
 105, 112, 116,  58,  58, 103, 101, 116,  83, 105, 122, 101,  14, 103, 101, 116,
  77, 101, 109,  98, 101, 114,  78,  97, 109, 101, 115,  29,  83,  97, 109, 112,
 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 103, 101, 116,  77, 101,
 109,  98, 101, 114,  78,  97, 109, 101, 115,  10, 103, 101, 116,  83,  97, 109,
 112, 108, 101, 115,  25,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105,
 112, 116,  58,  58, 103, 101, 116,  83,  97, 109, 112, 108, 101, 115,  14, 103,
 101, 116,  83,  97, 109, 112, 108, 101,  67, 111, 117, 110, 116,  29,  83,  97,
 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 103, 101, 116,
  83,  97, 109, 112, 108, 101,  67, 111, 117, 110, 116,  18, 103, 101, 116,  73,
 110, 118, 111,  99,  97, 116, 105, 111, 110,  67, 111, 117, 110, 116,  24, 103,
 101, 116,  83, 101, 116, 116, 101, 114,  73, 110, 118, 111,  99,  97, 116, 105,
 111, 110,  67, 111, 117, 110, 116,  24, 103, 101, 116,  71, 101, 116, 116, 101,
 114,  73, 110, 118, 111,  99,  97, 116, 105, 111, 110,  67, 111, 117, 110, 116,
  34,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58,
  95, 103, 101, 116,  73, 110, 118, 111,  99,  97, 116, 105, 111, 110,  67, 111,
 117, 110, 116,  14, 105, 115,  71, 101, 116, 116, 101, 114,  83, 101, 116, 116,
 101, 114,  29,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,
  58,  58, 105, 115,  71, 101, 116, 116, 101, 114,  83, 101, 116, 116, 101, 114,
  16, 103, 101, 116,  76, 101, 120, 105,  99,  97, 108,  83,  99, 111, 112, 101,
 115,  31,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,
  58, 103, 101, 116,  76, 101, 120, 105,  99,  97, 108,  83,  99, 111, 112, 101,
 115,  12, 103, 101, 116,  83,  97, 118, 101, 100,  84, 104, 105, 115,  27,  83,
  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 103, 101,
 116,  83,  97, 118, 101, 100,  84, 104, 105, 115,  15, 103, 101, 116,  77,  97,
 115, 116, 101, 114,  83, 116, 114, 105, 110, 103,  30,  83,  97, 109, 112, 108,
 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 103, 101, 116,  77,  97, 115,
 116, 101, 114,  83, 116, 114, 105, 110, 103,  17, 102, 108,  97, 115, 104,  46,
 116, 114,  97,  99, 101,  58,  84, 114,  97,  99, 101,   3,  79,  70,  70,   7,
  77,  69,  84,  72,  79,  68,  83,  17,  77,  69,  84,  72,  79,  68,  83,  95,
  87,  73,  84,  72,  95,  65,  82,  71,  83,  17,  77,  69,  84,  72,  79,  68,
  83,  95,  65,  78,  68,  95,  76,  73,  78,  69,  83,  27,  77,  69,  84,  72,
  79,  68,  83,  95,  65,  78,  68,  95,  76,  73,  78,  69,  83,  95,  87,  73,
  84,  72,  95,  65,  82,  71,  83,   4,  70,  73,  76,  69,   8,  76,  73,  83,
  84,  69,  78,  69,  82,   8, 115, 101, 116,  76, 101, 118, 101, 108,   8, 103,
 101, 116,  76, 101, 118, 101, 108,  11, 115, 101, 116,  76, 105, 115, 116, 101,
 110, 101, 114,  11, 103, 101, 116,  76, 105, 115, 116, 101, 110, 101, 114,  11,
 102, 108,  97, 115, 104,  46, 116, 114,  97,  99, 101,   5,  84, 114,  97,  99,
 101,  10,  84, 114,  97,  99, 101,  46,  97, 115,  36,  53,  10,  84, 114,  97,
  99, 101,  67, 108,  97, 115, 115,  22, 102, 108,  97, 115, 104,  46, 117, 116,
 105, 108, 115,  58,  68, 105,  99, 116, 105, 111, 110,  97, 114, 121,  15,  68,
 105,  99, 116, 105, 111, 110,  97, 114, 121,  46,  97, 115,  36,  54,  10,  68,
 105,  99, 116, 105, 111, 110,  97, 114, 121,  15,  68, 105,  99, 116, 105, 111,
 110,  97, 114, 121,  67, 108,  97, 115, 115,  16,  68, 105,  99, 116, 105, 111,
 110,  97, 114, 121,  79,  98, 106, 101,  99, 116,   8,  95,  95, 115, 121, 115,
 116, 101, 109,  11, 115, 116, 100, 108, 105,  98,  46,  97, 115,  36,  55,   8,
  67,  46, 115, 116, 100, 108, 105,  98,   8, 114, 101,  97, 108, 112,  97, 116,
 104,   8, 117, 110, 115, 101, 116, 101, 110, 118,   6, 115, 101, 116, 101, 110,
 118,   6, 103, 101, 116, 101, 110, 118,   5,  97,  98, 111, 114, 116,  17,  67,
  46, 115, 116, 100, 108, 105,  98,  58,  95,  95, 115, 116, 100, 108, 105,  98,
  12,  69,  88,  73,  84,  95,  83,  85,  67,  67,  69,  83,  83,  12,  69,  88,
  73,  84,  95,  70,  65,  73,  76,  85,  82,  69,   8,  95,  95, 115, 116, 100,
 108, 105,  98,  23,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,
  83, 116, 100, 108, 105,  98,  67, 108,  97, 115, 115,   6, 115, 121, 115, 116,
 101, 109,   8,  95,  95, 117, 110, 105, 115, 116, 100,  11, 117, 110, 105, 115,
 116, 100,  46,  97, 115,  36,  56,   8,  67,  46, 117, 110, 105, 115, 116, 100,
   5, 115, 108, 101, 101, 112,   5,  99, 104, 109, 111, 100,   5, 114, 109, 100,
 105, 114,   5, 109, 107, 100, 105, 114,   8, 103, 101, 116, 108, 111, 103, 105,
 110,  11, 103, 101, 116, 104, 111, 115, 116, 110,  97, 109, 101,   6, 103, 101,
 116,  99, 119, 100,   6,  97,  99,  99, 101, 115, 115,  17,  67,  46, 117, 110,
 105, 115, 116, 100,  58,  95,  95, 117, 110, 105, 115, 116, 100,   4,  70,  95,
  79,  75,   4,  88,  95,  79,  75,   4,  87,  95,  79,  75,   4,  82,  95,  79,
  75,   6,  83,  95,  73,  70,  77,  84,   7,  83,  95,  73,  70,  73,  70,  79,
   7,  83,  95,  73,  70,  67,  72,  82,   7,  83,  95,  73,  70,  68,  73,  82,
   7,  83,  95,  73,  70,  66,  76,  75,   7,  83,  95,  73,  70,  82,  69,  71,
   7,  83,  95,  73,  70,  76,  78,  75,   8,  83,  95,  73,  70,  83,  79,  67,
  75,   7,  83,  95,  73,  82,  87,  88,  85,   7,  83,  95,  73,  82,  85,  83,
  82,   7,  83,  95,  73,  87,  85,  83,  82,   7,  83,  95,  73,  88,  85,  83,
  82,   7,  83,  95,  73,  82,  87,  88,  71,   7,  83,  95,  73,  82,  71,  82,
  80,   7,  83,  95,  73,  87,  71,  82,  80,   7,  83,  95,  73,  88,  71,  82,
  80,   7,  83,  95,  73,  82,  87,  88,  79,   7,  83,  95,  73,  82,  79,  84,
  72,   7,  83,  95,  73,  87,  79,  84,  72,   7,  83,  95,  73,  88,  79,  84,
  72,   7,  83,  95,  73,  82,  69,  65,  68,   8,  83,  95,  73,  87,  82,  73,
  84,  69,   7,  83,  95,  73,  69,  88,  69,  67,  23,  58,  58,  97, 118, 109,
 115, 104, 101, 108, 108,  58,  58,  85, 110, 105, 115, 116, 100,  67, 108,  97,
 115, 115,   1,  45,   1, 100,   1,  99,   1,  98,   1, 108,   1, 112,   1, 115,
   1,  63,  11, 115, 116, 114, 105, 110, 103,  46,  97, 115,  36,  57,   8,  67,
  46, 115, 116, 114, 105, 110, 103,   1, 114,   1, 119,   1, 120,   4, 106, 111,
 105, 110,   4, 109, 111, 100, 101,   1, 110,   5, 102, 116, 121, 112, 101,   8,
  95,  95, 115, 116, 114, 105, 110, 103,   6, 115, 116, 114, 108, 101, 110,   8,
 115, 116, 114, 101, 114, 114, 111, 114,  17,  67,  46, 115, 116, 114, 105, 110,
 103,  58,  95,  95, 115, 116, 114, 105, 110, 103,  24,  58,  58,  97, 118, 109,
 115, 104, 101, 108, 108,  58,  58,  67,  83, 116, 114, 105, 110, 103,  67, 108,
  97, 115, 115,   7, 115, 116, 114, 109, 111, 100, 101,   7,  95,  95, 101, 114,
 114, 110, 111,  11, 101, 114, 114, 110, 111,  46,  97, 115,  36,  49,  48,   7,
  67,  46, 101, 114, 114, 110, 111,   5, 101, 114, 114, 110, 111,  15,  67,  46,
 101, 114, 114, 110, 111,  58,  95,  95, 101, 114, 114, 110, 111,   4,  69,  68,
  79,  77,   6,  69,  73,  76,  83,  69,  81,   6,  69,  82,  65,  78,  71,  69,
   5,  69,  80,  69,  82,  77,   6,  69,  78,  79,  69,  78,  84,   5,  69,  83,
  82,  67,  72,   5,  69,  73,  78,  84,  82,   3,  69,  73,  79,   5,  69,  78,
  88,  73,  79,   5,  69,  50,  66,  73,  71,   7,  69,  78,  79,  69,  88,  69,
  67,   5,  69,  66,  65,  68,  70,   6,  69,  67,  72,  73,  76,  68,   6,  69,
  65,  71,  65,  73,  78,   6,  69,  78,  79,  77,  69,  77,   6,  69,  65,  67,
  67,  69,  83,   6,  69,  70,  65,  85,  76,  84,   5,  69,  66,  85,  83,  89,
   6,  69,  69,  88,  73,  83,  84,   5,  69,  88,  68,  69,  86,   6,  69,  78,
  79,  68,  69,  86,   7,  69,  78,  79,  84,  68,  73,  82,   6,  69,  73,  83,
  68,  73,  82,   6,  69,  73,  78,  86,  65,  76,   6,  69,  78,  70,  73,  76,
  69,   6,  69,  77,  70,  73,  76,  69,   6,  69,  78,  79,  84,  84,  89,   5,
  69,  70,  66,  73,  71,   6,  69,  78,  79,  83,  80,  67,   6,  69,  83,  80,
  73,  80,  69,   5,  69,  82,  79,  70,  83,   6,  69,  77,  76,  73,  78,  75,
   5,  69,  80,  73,  80,  69,   7,  69,  68,  69,  65,  68,  76,  75,  12,  69,
  78,  65,  77,  69,  84,  79,  79,  76,  79,  78,  71,   6,  69,  78,  79,  76,
  67,  75,   6,  69,  78,  79,  83,  89,  83,   9,  69,  78,  79,  84,  69,  77,
  80,  84,  89,   8,  69,  78,  69,  84,  68,  79,  87,  78,  11,  69,  78,  69,
  84,  85,  78,  82,  69,  65,  67,  72,   9,  69,  78,  69,  84,  82,  69,  83,
  69,  84,  12,  69,  67,  79,  78,  78,  65,  66,  79,  82,  84,  69,  68,  10,
  69,  67,  79,  78,  78,  82,  69,  83,  69,  84,   7,  69,  78,  79,  66,  85,
  70,  83,   7,  69,  73,  83,  67,  79,  78,  78,   8,  69,  78,  79,  84,  67,
  79,  78,  78,   9,  69,  83,  72,  85,  84,  68,  79,  87,  78,  12,  69,  84,
  79,  79,  77,  65,  78,  89,  82,  69,  70,  83,   9,  69,  84,  73,  77,  69,
  68,  79,  85,  84,  12,  69,  67,  79,  78,  78,  82,  69,  70,  85,  83,  69,
  68,  23,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  67,  69,
 114, 114, 110, 111,  67, 108,  97, 115, 115,   6, 114, 101, 110,  97, 109, 101,
  11, 115, 116, 100, 105, 111,  46,  97, 115,  36,  49,  49,   7,  67,  46, 115,
 116, 100, 105, 111,   6, 114, 101, 109, 111, 118, 101,  15,  67,  46, 115, 116,
 100, 105, 111,  58,  95,  95, 115, 116, 100, 105, 111,  12,  70,  73,  76,  69,
  78,  65,  77,  69,  95,  77,  65,  88,   8,  80,  65,  84,  72,  95,  77,  65,
  88,   7,  95,  95, 115, 116, 100, 105, 111,  22,  58,  58,  97, 118, 109, 115,
 104, 101, 108, 108,  58,  58,  83, 116, 100, 105, 111,  67, 108,  97, 115, 115,
   8,  95,  95, 115, 111,  99, 107, 101, 116,  12, 115, 111,  99, 107, 101, 116,
  46,  97, 115,  36,  49,  50,   8,  67,  46, 115, 111,  99, 107, 101, 116,  15,
  95,  95, 103, 101, 116, 104, 111, 115, 116,  98, 121, 110,  97, 109, 101,  15,
  95,  95, 103, 101, 116, 104, 111, 115, 116,  98, 121,  97, 100, 100, 114,  17,
  67,  46, 115, 111,  99, 107, 101, 116,  58,  95,  95, 115, 111,  99, 107, 101,
 116,   8,  83,  79,  67,  75,  95,  82,  65,  87,  11,  83,  79,  67,  75,  95,
  83,  84,  82,  69,  65,  77,  10,  83,  79,  67,  75,  95,  68,  71,  82,  65,
  77,  13,  83,  79,  95,  65,  67,  67,  69,  80,  84,  67,  79,  78,  78,  12,
  83,  79,  95,  66,  82,  79,  65,  68,  67,  65,  83,  84,  12,  83,  79,  95,
  68,  79,  78,  84,  82,  79,  85,  84,  69,  12,  83,  79,  95,  75,  69,  69,
  80,  65,  76,  73,  86,  69,  12,  83,  79,  95,  79,  79,  66,  73,  78,  76,
  73,  78,  69,   9,  83,  79,  95,  82,  67,  86,  66,  85,  70,  11,  83,  79,
  95,  82,  67,  86,  84,  73,  77,  69,  79,  12,  83,  79,  95,  82,  69,  85,
  83,  69,  65,  68,  68,  82,   9,  83,  79,  95,  83,  78,  68,  66,  85,  70,
  11,  83,  79,  95,  83,  78,  68,  84,  73,  77,  69,  79,   7,  83,  79,  95,
  84,  89,  80,  69,   9,  83,  79,  77,  65,  88,  67,  79,  78,  78,  10,  77,
  83,  71,  95,  67,  84,  82,  85,  78,  67,  13,  77,  83,  71,  95,  68,  79,
  78,  84,  82,  79,  85,  84,  69,   7,  77,  83,  71,  95,  79,  79,  66,   8,
  77,  83,  71,  95,  80,  69,  69,  75,   9,  77,  83,  71,  95,  84,  82,  85,
  78,  67,  11,  77,  83,  71,  95,  87,  65,  73,  84,  65,  76,  76,   7,  65,
  70,  95,  73,  78,  69,  84,   8,  65,  70,  95,  73,  78,  69,  84,  54,   9,
  65,  70,  95,  85,  78,  83,  80,  69,  67,   7,  83,  72,  85,  84,  95,  82,
  68,   9,  83,  72,  85,  84,  95,  82,  68,  87,  82,   7,  83,  72,  85,  84,
  95,  87,  82,  10,  73,  80,  80,  82,  79,  84,  79,  95,  73,  80,  12,  73,
  80,  80,  82,  79,  84,  79,  95,  73,  80,  86,  54,  12,  73,  80,  80,  82,
  79,  84,  79,  95,  73,  67,  77,  80,  11,  73,  80,  80,  82,  79,  84,  79,
  95,  82,  65,  87,  11,  73,  80,  80,  82,  79,  84,  79,  95,  84,  67,  80,
  11,  73,  80,  80,  82,  79,  84,  79,  95,  85,  68,  80,  10,  73,  78,  65,
  68,  68,  82,  95,  65,  78,  89,  16,  73,  78,  65,  68,  68,  82,  95,  66,
  82,  79,  65,  68,  67,  65,  83,  84,  24,  58,  58,  97, 118, 109, 115, 104,
 101, 108, 108,  58,  58,  67,  83, 111,  99, 107, 101, 116,  67, 108,  97, 115,
 115,  13, 103, 101, 116, 104, 111, 115, 116,  98, 121,  97, 100, 100, 114,  13,
 103, 101, 116, 104, 111, 115, 116,  98, 121, 110,  97, 109, 101,  18,  97, 118,
 109, 112, 108, 117, 115,  58,  70, 105, 108, 101,  83, 121, 115, 116, 101, 109,
  16,  70, 105, 108, 101,  83, 121, 115, 116, 101, 109,  46,  97, 115,  36,  49,
  51,  16, 103, 101, 116,  70, 114, 101, 101,  68, 105, 115, 107,  83, 112,  97,
  99, 101,  17, 103, 101, 116,  84, 111, 116,  97, 108,  68, 105, 115, 107,  83,
 112,  97,  99, 101,  11, 103, 101, 116,  70, 105, 108, 101,  77, 111, 100, 101,
   9,  99,  97, 110,  65,  99,  99, 101, 115, 115,   8,  99,  97, 110,  87, 114,
 105, 116, 101,   7,  99,  97, 110,  82, 101,  97, 100,  13, 105, 115,  82, 101,
 103, 117, 108,  97, 114,  70, 105, 108, 101,  11, 105, 115,  68, 105, 114, 101,
  99, 116, 111, 114, 121,   9, 108, 105, 115, 116,  70, 105, 108, 101, 115,  16,
 103, 101, 116,  85, 115, 101, 100,  68, 105, 115, 107,  83, 112,  97,  99, 101,
  10,  70, 105, 108, 101,  83, 121, 115, 116, 101, 109,  27,  58,  58,  97, 118,
 109, 115, 104, 101, 108, 108,  58,  58,  70, 105, 108, 101,  83, 121, 115, 116,
 101, 109,  67, 108,  97, 115, 115,  23,  97, 118, 109, 112, 108, 117, 115,  58,
  79, 112, 101, 114,  97, 116, 105, 110, 103,  83, 121, 115, 116, 101, 109,   7,
  85,  78,  75,  78,  79,  87,  78,   7,  85, 110, 107, 110, 111, 119, 110,   5,
  69,  77,  80,  84,  89,  18,  95, 108, 105, 110, 117, 120,  82, 101, 108, 101,
  97, 115, 101,  70, 105, 108, 101, 115,  16,  47, 101, 116,  99,  47, 108, 115,
  98,  45, 114, 101, 108, 101,  97, 115, 101,  19,  47, 101, 116,  99,  47, 114,
 101, 100, 104,  97, 116,  45, 114, 101, 108, 101,  97, 115, 101,  17,  47, 101,
 116,  99,  47,  83, 117,  83,  69,  45, 114, 101, 108, 101,  97, 115, 101,  19,
  47, 101, 116,  99,  47, 110, 111, 118, 101, 108, 108,  45, 114, 101, 108, 101,
  97, 115, 101,  21,  47, 101, 116,  99,  47, 109,  97, 110, 100, 114,  97, 107,
 101,  45, 114, 101, 108, 101,  97, 115, 101,  19,  47, 101, 116,  99,  47, 100,
 101,  98, 105,  97, 110,  95, 118, 101, 114, 115, 105, 111, 110,  21,  95, 109,
  97,  99,  83, 121, 115, 116, 101, 109,  86, 101, 114, 115, 105, 111, 110,  70,
 105, 108, 101,  48,  47,  83, 121, 115, 116, 101, 109,  47,  76, 105,  98, 114,
  97, 114, 121,  47,  67, 111, 114, 101,  83, 101, 114, 118, 105,  99, 101, 115,
  47,  83, 121, 115, 116, 101, 109,  86, 101, 114, 115, 105, 111, 110,  46, 112,
 108, 105, 115, 116,   5,  65, 112, 112, 108, 101,   9,  77, 105,  99, 114, 111,
 115, 111, 102, 116,  21,  79, 112, 101, 114,  97, 116, 105, 110, 103,  83, 121,
 115, 116, 101, 109,  46,  97, 115,  36,  49,  52,   6,  68,  97, 114, 119, 105,
 110,   5,  87, 105, 110,  51,  50,   1,  10,   5, 115, 112, 108, 105, 116,  15,
  95, 108, 105, 110, 117, 120,  68, 105, 115, 116, 114, 105,  98,  73,  68,   1,
  61,  20,  95, 108, 105, 110, 117, 120,  68, 105, 115, 116, 114, 105,  98,  82,
 101, 108, 101,  97, 115, 101,  21,  95, 108, 105, 110, 117, 120,  68, 105, 115,
 116, 114, 105,  98,  67, 111, 100, 101, 110,  97, 109, 101,  24,  95, 108, 105,
 110, 117, 120,  68, 105, 115, 116, 114, 105,  98,  68, 101, 115,  99, 114, 105,
 112, 116, 105, 111, 110,   1,  34,   7, 105, 110, 100, 101, 120,  79, 102,   7,
 114, 101, 108, 101,  97, 115, 101,  30,  60, 107, 101, 121,  62,  80, 114, 111,
 100, 117,  99, 116,  66, 117, 105, 108, 100,  86, 101, 114, 115, 105, 111, 110,
  60,  47, 107, 101, 121,  62,   8,  60, 115, 116, 114, 105, 110, 103,  62,   9,
  60,  47, 115, 116, 114, 105, 110, 103,  62,  23,  95, 109,  97,  99,  80, 114,
 111, 100, 117,  99, 116,  66, 117, 105, 108, 100,  86, 101, 114, 115, 105, 111,
 110,   9, 115, 117,  98, 115, 116, 114, 105, 110, 103,   8,  77,  97,  99,  32,
  79,  83,  32,  88,  22, 103, 101, 116,  86, 101, 110, 100, 111, 114,  78,  97,
 109, 101,  77, 105,  99, 114, 111, 115, 111, 102, 116,  22,  95, 112,  97, 114,
 115, 101,  76, 105, 110, 117, 120,  82, 101, 108, 101,  97, 115, 101,  70, 105,
 108, 101,   6, 118, 101, 110, 100, 111, 114,   5,  76, 105, 110, 117, 120,   7,
 118, 101, 114, 115, 105, 111, 110,  10,  87, 105, 110, 100, 111, 119, 115,  32,
  57,  53,  10,  87, 105, 110, 100, 111, 119, 115,  32,  57,  56,  10,  87, 105,
 110, 100, 111, 119, 115,  32,  77,  69,  10,  87, 105, 110, 100, 111, 119, 115,
  32,  78,  84,  10,  87, 105, 110, 100, 111, 119, 115,  32,  88,  80,  12,  87,
 105, 110, 100, 111, 119, 115,  32,  50,  48,  48,  48,  22,  87, 105, 110, 100,
 111, 119, 115,  32,  83, 101, 114, 118, 101, 114,  32,  50,  48,  48,  51,  32,
  82,  50,  19,  87, 105, 110, 100, 111, 119, 115,  32,  83, 101, 114, 118, 101,
 114,  32,  50,  48,  48,  51,  13,  87, 105, 110, 100, 111, 119, 115,  32,  86,
 105, 115, 116,  97,  22,  87, 105, 110, 100, 111, 119, 115,  32,  83, 101, 114,
 118, 101, 114,  32,  50,  48,  48,  56,  32,  82,  50,  19,  87, 105, 110, 100,
 111, 119, 115,  32,  83, 101, 114, 118, 101, 114,  32,  50,  48,  48,  56,   9,
  87, 105, 110, 100, 111, 119, 115,  32,  55,   7,  87, 105, 110, 100, 111, 119,
 115,  16, 103, 101, 116,  86, 101, 110, 100, 111, 114,  86, 101, 114, 115, 105,
 111, 110,  25, 103, 101, 116,  86, 101, 110, 100, 111, 114,  68, 101, 115,  99,
 114, 105, 112, 116, 105, 111, 110,  65, 112, 112, 108, 101,  29, 103, 101, 116,
  86, 101, 110, 100, 111, 114,  68, 101, 115,  99, 114, 105, 112, 116, 105, 111,
 110,  77, 105,  99, 114, 111, 115, 111, 102, 116,  25, 103, 101, 116,  86, 101,
 110, 100, 111, 114,  68, 101, 115,  99, 114, 105, 112, 116, 105, 111, 110,  76,
 105, 110, 117, 120,  10, 118, 101, 110, 100, 111, 114,  78,  97, 109, 101,   1,
  32,  13, 118, 101, 110, 100, 111, 114,  86, 101, 114, 115, 105, 111, 110,   2,
  32,  40,   8,  99, 111, 100, 101,  78,  97, 109, 101,  20,  95, 112,  97, 114,
 115, 101,  77,  97,  99,  86, 101, 114, 115, 105, 111, 110,  70, 105, 108, 101,
   6,  98, 117, 105, 108, 100,  32,   1,  41,  16, 103, 101, 116,  67, 111, 100,
 101,  78,  97, 109, 101,  65, 112, 112, 108, 101,  20, 103, 101, 116,  67, 111,
 100, 101,  78,  97, 109, 101,  77, 105,  99, 114, 111, 115, 111, 102, 116,   1,
  46,   8, 112,  97, 114, 115, 101,  73, 110, 116,   7,  67, 104, 101, 101, 116,
  97, 104,   4,  80, 117, 109,  97,   6,  74,  97, 103, 117,  97, 114,   7,  80,
  97, 110, 116, 104, 101, 114,   5,  84, 105, 103, 101, 114,   7,  76, 101, 111,
 112,  97, 114, 100,  12,  83, 110, 111, 119,  32,  76, 101, 111, 112,  97, 114,
 100,  32,  87, 105, 110, 100, 111, 119, 115,  32,  57,  53,  32,  79,  69,  77,
  32,  83, 101, 114, 118, 105,  99, 101,  32,  82, 101, 108, 101,  97, 115, 101,
  32,  50,   7,  68, 101, 116, 114, 111, 105, 116,   7,  67, 104, 105,  99,  97,
 103, 111,   7,  77, 101, 109, 112, 104, 105, 115,   8,  87, 104, 105, 115, 116,
 108, 101, 114,  10,  77, 101, 109, 112, 104, 105, 115,  32,  78,  84,  12,  87,
 105, 110, 100, 111, 119, 115,  32,  50,  48,  48,  51,  15,  87, 104, 105, 115,
 116, 108, 101, 114,  32,  83, 101, 114, 118, 101, 114,   8,  76, 111, 110, 103,
 104, 111, 114, 110,  12,  87, 105, 110, 100, 111, 119, 115,  32,  50,  48,  48,
  56,  15,  76, 111, 110, 103, 104, 111, 114, 110,  32,  83, 101, 114, 118, 101,
 114,   6,  86, 105, 101, 110, 110,  97,   5,  95, 110,  97, 109, 101,   7, 103,
 101, 116,  78,  97, 109, 101,   9,  95, 117, 115, 101, 114, 110,  97, 109, 101,
  11, 103, 101, 116,  85, 115, 101, 114,  78,  97, 109, 101,   9,  95, 110, 111,
 100, 101, 110,  97, 109, 101,  11, 103, 101, 116,  78, 111, 100, 101,  78,  97,
 109, 101,   9,  95, 104, 111, 115, 116, 110,  97, 109, 101,   8,  95, 114, 101,
 108, 101,  97, 115, 101,  10, 103, 101, 116,  82, 101, 108, 101,  97, 115, 101,
   8,  95, 118, 101, 114, 115, 105, 111, 110,  10, 103, 101, 116,  86, 101, 114,
 115, 105, 111, 110,   8,  95, 109,  97,  99, 104, 105, 110, 101,  10, 103, 101,
 116,  77,  97,  99, 104, 105, 110, 101,   7,  95, 118, 101, 110, 100, 111, 114,
  12, 103, 101, 116,  86, 101, 110, 100, 111, 114,  65, 108, 108,  11,  95, 118,
 101, 110, 100, 111, 114, 110,  97, 109, 101,  16, 103, 101, 116,  86, 101, 110,
 100, 111, 114,  78,  97, 109, 101,  65, 108, 108,  14,  95, 118, 101, 110, 100,
 111, 114, 118, 101, 114, 115, 105, 111, 110,  19, 103, 101, 116,  86, 101, 110,
 100, 111, 114,  86, 101, 114, 115, 105, 111, 110,  65, 108, 108,  18,  95, 118,
 101, 110, 100, 111, 114, 100, 101, 115,  99, 114, 105, 112, 116, 105, 111, 110,
  23, 103, 101, 116,  86, 101, 110, 100, 111, 114,  68, 101, 115,  99, 114, 105,
 112, 116, 105, 111, 110,  65, 108, 108,   9,  95,  99, 111, 100, 101, 110,  97,
 109, 101,  14, 103, 101, 116,  67, 111, 100, 101,  78,  97, 109, 101,  65, 108,
 108,   8, 117, 115, 101, 114, 110,  97, 109, 101,   8, 110, 111, 100, 101, 110,
  97, 109, 101,   8, 104, 111, 115, 116, 110,  97, 109, 101,   7, 109,  97,  99,
 104, 105, 110, 101,  17, 118, 101, 110, 100, 111, 114,  68, 101, 115,  99, 114,
 105, 112, 116, 105, 111, 110,  15,  79, 112, 101, 114,  97, 116, 105, 110, 103,
  83, 121, 115, 116, 101, 109,  32,  58,  58,  97, 118, 109, 115, 104, 101, 108,
 108,  58,  58,  79, 112, 101, 114,  97, 116, 105, 110, 103,  83, 121, 115, 116,
 101, 109,  67, 108,  97, 115, 115,  14,  97, 118, 109, 112, 108, 117, 115,  58,
  83, 111,  99, 107, 101, 116,   7, 110,  97, 109, 101,  50, 105, 112,  12,  83,
 111,  99, 107, 101, 116,  46,  97, 115,  36,  49,  53,  15,  73,  80,  32,  97,
 100, 100, 114, 101, 115, 115, 101, 115,  32,  61,  32,   1, 124,   6, 115, 117,
  98, 115, 116, 114,   7, 105, 112,  50, 110,  97, 109, 101,  12, 104, 111, 115,
 116, 110,  97, 109, 101, 115,  32,  61,  32,  13,  95,  99, 117, 115, 116, 111,
 109,  83, 111,  99, 107, 101, 116,   6,  83, 111,  99, 107, 101, 116,   7, 105,
 115,  86,  97, 108, 105, 100,  10,  95,  99, 111, 110, 110, 101,  99, 116, 101,
 100,   6,  95,  98, 111, 117, 110, 100,  10,  95, 108, 105, 115, 116, 101, 110,
 105, 110, 103,   3, 114,  97, 119,   6, 115, 116, 114, 101,  97, 109,   8, 100,
  97, 116,  97, 103, 114,  97, 109,   5,  95, 116, 121, 112, 101,  10,  95, 108,
 111,  99,  97, 108,  80, 111, 114, 116,  13,  95, 108, 111,  99,  97, 108,  65,
 100, 100, 114, 101, 115, 115,  11,  95, 114, 101, 109, 111, 116, 101,  80, 111,
 114, 116,  14,  95, 114, 101, 109, 111, 116, 101,  65, 100, 100, 114, 101, 115,
 115,   8,  95,  99, 111, 110, 110, 101,  99, 116,   5,  69, 114, 114, 111, 114,
   9, 108,  97, 115, 116,  69, 114, 114, 111, 114,   9,  99, 111, 110, 110, 101,
  99, 116, 101, 100,   6,  95,  99, 108, 111, 115, 101,  20,  97,  32, 112, 114,
 111,  98, 108, 101, 109,  32, 111,  99,  99, 117, 114, 101, 100,  32,  61,  32,
   3,  32,  58,  32,   5,  95, 115, 101, 110, 100,  11,  95, 115, 101, 110, 100,
  66, 105, 110,  97, 114, 121,  16,  83, 101, 110, 116,  32, 119, 104, 111, 108,
 101,  32, 100,  97, 116,  97,  32,   6,  32,  98, 121, 116, 101, 115,   7,  99,
 111, 110, 110, 101,  99, 116,   4, 115, 101, 110, 100,  25, 115, 101, 110, 100,
  84, 111,  40,  41,  32,  99, 111, 117, 108, 100,  32, 110, 111, 116,  32, 114,
 101,  97,  99, 104,  32,   8,  95, 114, 101,  99, 101, 105, 118, 101,  14, 114,
 101,  99, 101, 105, 118, 101, 100,  66, 117, 102, 102, 101, 114,  33,  67, 111,
 110, 110, 101,  99, 116, 105, 111, 110,  32,  99, 108, 111, 115, 101, 100,  32,
  98, 121,  32, 114, 101, 109, 111, 116, 101,  32, 112, 101, 101, 114,  46,  14,
  95, 114, 101,  99, 101, 105, 118, 101,  66, 105, 110,  97, 114, 121,  14, 114,
 101,  99, 101, 105, 118, 101, 100,  66, 105, 110,  97, 114, 121,   7, 114, 101,
  99, 101, 105, 118, 101,  30, 114, 101,  99, 101, 105, 118, 101,  70, 114, 111,
 109,  40,  41,  32,  99, 111, 117, 108, 100,  32, 110, 111, 116,  32, 114, 101,
  97,  99, 104,  32,   5,  95,  98, 105, 110, 100,  13,  98, 105, 110, 100,  32,
 116, 111,  32, 112, 111, 114, 116,  32,   5,  95, 112, 111, 114, 116,   7,  95,
 108, 105, 115, 116, 101, 110,   7,  95,  97,  99,  99, 101, 112, 116,  12,  97,
 118, 109, 112, 108, 117, 115,  58, 104,  97,  99, 107,  14, 103, 101, 116,  73,
  80,  65, 100, 100, 114, 101, 115, 115, 101, 115,  12, 103, 101, 116,  72, 111,
 115, 116, 110,  97, 109, 101, 115,  12, 108,  97, 115, 116,  68,  97, 116,  97,
  83, 101, 110, 116,   5, 118,  97, 108, 105, 100,   5,  98, 111, 117, 110, 100,
   9, 108, 105, 115, 116, 101, 110, 105, 110, 103,  12, 114, 101, 117, 115, 101,
  65, 100, 100, 114, 101, 115, 115,   9,  98, 114, 111,  97, 100,  99,  97, 115,
 116,   9, 108, 111,  99,  97, 108,  80, 111, 114, 116,  12, 108, 111,  99,  97,
 108,  65, 100, 100, 114, 101, 115, 115,  10, 114, 101, 109, 111, 116, 101,  80,
 111, 114, 116,  13, 114, 101, 109, 111, 116, 101,  65, 100, 100, 114, 101, 115,
 115,   5,  99, 108, 111, 115, 101,  10, 115, 101, 110, 100,  66, 105, 110,  97,
 114, 121,   6, 115, 101, 110, 100,  84, 111,  13, 114, 101,  99, 101, 105, 118,
 101,  66, 105, 110,  97, 114, 121,  11, 114, 101,  99, 101, 105, 118, 101,  70,
 114, 111, 109,   4,  98, 105, 110, 100,   6, 108, 105, 115, 116, 101, 110,   6,
  97,  99,  99, 101, 112, 116,   4, 104,  97,  99, 107,  23,  58,  58,  97, 118,
 109, 115, 104, 101, 108, 108,  58,  58,  83, 111,  99, 107, 101, 116,  67, 108,
  97, 115, 115,  24,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,
  83, 111,  99, 107, 101, 116,  79,  98, 106, 101,  99, 116,  18, 102, 108,  97,
 115, 104,  46, 117, 116, 105, 108, 115,  58,  69, 110, 100, 105,  97, 110,  10,
  66,  73,  71,  95,  69,  78,  68,  73,  65,  78,   9,  98, 105, 103,  69, 110,
 100, 105,  97, 110,  13,  76,  73,  84,  84,  76,  69,  95,  69,  78,  68,  73,
  65,  78,  12, 108, 105, 116, 116, 108, 101,  69, 110, 100, 105,  97, 110,   6,
  69, 110, 100, 105,  97, 110,  12,  69, 110, 100, 105,  97, 110,  46,  97, 115,
  36,  49,  54,  15,  97, 118, 109, 112, 108, 117, 115,  58,  74,  79,  98, 106,
 101,  99, 116,   7,  74,  79,  98, 106, 101,  99, 116,   6,  99, 114, 101,  97,
 116, 101,  11,  99, 114, 101,  97, 116, 101,  65, 114, 114,  97, 121,   7, 116,
 111,  65, 114, 114,  97, 121,  20,  99, 111, 110, 115, 116, 114, 117,  99, 116,
 111, 114,  83, 105, 103, 110,  97, 116, 117, 114, 101,  15, 109, 101, 116, 104,
 111, 100,  83, 105, 103, 110,  97, 116, 117, 114, 101,  14, 102, 105, 101, 108,
 100,  83, 105, 103, 110,  97, 116, 117, 114, 101,  10,  74,  97, 118,  97,  46,
  97, 115,  36,  49,  55,  12,  74,  79,  98, 106, 101,  99, 116,  67, 108,  97,
 115, 115, 103,   5,   2,  22,   3,  23,   3,  22,   4,  23,   4,   5,  16,  24,
  16,  26,  16,  26,  19,  22,  26,   5,  37,  24,  37,  26,  37,  22,  39,   5,
  47,  22,  49,  23,  49,  24,  47,  26,  47,  22,  52,  22,  59,   5,  62,   5,
  64,  24,  62,  26,  62,   5,  72,   5,  74,  23,  39,  24,  72,  26,  72,  22,
 106,   5, 112,  22, 113,  23, 113,   5, 119,  24, 119,  26, 119,   5, 129,   1,
  24, 129,   1,   5, 133,   1,  24, 133,   1,   5, 139,   1,  24, 139,   1,  22,
 141,   1,   5, 184,   1,  22, 196,   1,  24, 184,   1,   5, 198,   1,  23, 196,
   1,   5, 200,   1,   5, 201,   1,  24, 200,   1,  26, 200,   1,   5, 206,   1,
  22, 207,   1,  23, 207,   1,   5, 213,   1,  24, 213,   1,   5, 220,   1,  22,
 221,   1,  23, 221,   1,   5, 230,   1,  24, 230,   1,   5, 139,   2,  22, 140,
   2,  23, 140,   2,   5, 151,   2,  24, 151,   2,   5, 155,   2,  22, 156,   2,
  23, 156,   2,   5, 158,   2,  24, 158,   2,   5, 211,   2,  22, 212,   2,  23,
 212,   2,   5, 214,   2,  24, 214,   2,   5, 220,   2,  22, 221,   2,  23, 221,
   2,   5, 224,   2,  24, 224,   2,   5, 135,   3,   5, 136,   3,  24, 135,   3,
  26, 135,   3,   5, 149,   3,   5, 164,   3,  24, 149,   3,  26, 149,   3,   5,
 138,   4,   5, 140,   4,  24, 138,   4,  26, 138,   4,  23, 186,   4,   5, 210,
   4,  24, 210,   4,   5, 216,   4,   5, 217,   4,  24, 217,   4,   5, 225,   4,
  62,   4,   1,   2,   3,   4,   4,   1,   2,   4,   5,   8,   1,   2,   4,   5,
   6,   7,   8,   9,   1,  10,   1,   6,   9,   1,   2,   4,   5,   9,  11,  12,
  13,  14,   8,   1,   2,   4,   5,   9,  11,  12,  13,   9,   1,   2,   4,   9,
  15,  16,  17,  18,  19,   1,   4,   1,  16,   5,   1,   2,   4,  16,  17,   1,
  20,   1,  21,   8,   2,   4,   5,   9,  22,  23,  24,  25,   9,   2,   4,   5,
   9,  14,  22,  23,  24,  25,   1,  22,   4,   2,   4,   5,  23,   8,   2,   9,
  14,  26,  27,  28,  29,  30,   1,  26,   1,  14,   4,   2,  14,  27,  28,   1,
  31,   4,   2,  32,  33,  34,   1,  34,   8,   2,   9,  32,  33,  34,  35,  36,
  37,   1,  44,   4,   2,  46,  48,  49,   1,  46,   8,   2,   9,  14,  28,  50,
  51,  52,  53,   1,  50,   4,   2,  14,  28,  51,   4,   2,  54,  55,  56,   1,
  56,   1,  55,   4,   2,  59,  60,  61,   1,  61,   1,  60,   5,   2,  60,  64,
  65,  66,   1,  66,   1,  65,   4,   2,  69,  70,  71,   1,  71,   1,  70,   4,
   2,  74,  75,  76,   1,  76,   1,  75,   4,   2,  79,  80,  81,   1,  81,   1,
  80,   9,   2,   4,   5,   9,  60,  84,  85,  86,  87,  10,   2,   4,   5,   9,
  14,  60,  84,  85,  86,  87,   5,   2,   4,   5,  60,  85,   9,   2,   4,   5,
   9,  60,  88,  89,  90,  91,   1,  88,   5,   2,   4,   5,  60,  89,  11,   2,
   4,   5,   9,  65,  70,  80,  92,  93,  94,  95,   1,  92,   1,  96,   7,   2,
   4,   5,  65,  70,  80,  93,   4,   2,  14,  28,  99,   4,   2,   4,   5, 102,
 255,   7,   9,   1,   1,   9,   5,   1,   7,   2,   6,   9,   7,   1,   7,   2,
   8,   9,   9,   1,   7,   2,  10,   9,  11,   1,   9,  12,   1,   9,  13,   1,
   7,   2,  14,   9,   1,   2,   9,  15,   2,   7,   2,  17,   9,  18,   3,   7,
   2,  20,   9,  21,   3,   7,   2,  22,   7,   2,  23,   7,   2,  24,   7,   2,
  25,   9,  27,   4,   9,  28,   4,   9,  29,   4,   9,   9,   4,   9,  30,   4,
   9,  15,   4,   9,  31,   4,   9,   7,   4,   9,  18,   5,   9,  17,   4,   9,
  21,   5,   9,  20,   4,   9,   5,   4,   9,  32,   4,   9,  33,   4,   9,  34,
   4,   9,  35,   4,   9,  36,   4,   7,   4,   1,   7,   2,  19,   9,  38,   6,
   9,  40,   7,   7,  14,  38,   9,  41,   7,   9,  42,   4,   9,  43,   4,   9,
  44,   4,   9,  45,   4,   7,   4,  46,   9,   1,   8,   9,  31,   8,   9,  50,
   4,   7,  16,  51,   9,   1,   9,   9,  19,   2,   9,  46,   9,   9,  51,  10,
   9,  19,  11,   9,   1,  12,   9,  46,  12,   9,  15,  12,   9,  51,  13,   9,
  60,   4,   9,  61,   4,   7,   4,  11,   9,  63,  14,   9,  38,  15,   9,  40,
  14,   9,  65,  14,   9,  12,   4,   9,  66,   4,   9,  63,  16,   9,  65,   4,
   9,  13,   4,   9,  67,   4,   9,  68,   4,   9,  11,   9,   9,  19,  17,   9,
  11,  12,   9,  73,  18,   9,  75,  18,   9,  76,  18,   9,  40,   4,   9,  41,
   4,   9,  77,   4,   9,  78,   4,   9,  79,   4,   9,  80,   4,   9,  81,   4,
   9,  82,   4,   9,  83,   4,   9,  84,   4,   9,  85,   4,   9,  86,   4,   9,
  87,   4,   9,  88,   4,   9,  89,   4,   9,  90,   4,   9,  91,   4,   9,  92,
   4,   9,  93,   4,   9,  94,   4,   9,  95,   4,   9,  96,   4,   9,  97,   4,
   9,  98,   4,   9,  99,   4,   9,  73,  19,   9, 100,   4,   9,  75,  19,   9,
 101,   4,   9,  76,  19,   9, 102,   4,   9, 103,   4,   9, 104,   4,   9, 105,
   4,   9,  38,  20,   9,  19,  21,   9,  38,  22,   7,   2, 109,   7,   2, 110,
   9, 111,  23,   9, 114,  23,   7,   2, 115,   9, 116,  24,   9, 117,  23,   9,
 114,  24,   9, 118,  24,   9, 120,  25,   9, 122,  25,   9, 125,  25,   9, 120,
   4,   9, 122,   4,   9, 125,   4,   9, 127,   4,   7,  33, 128,   1,   9, 130,
   1,   4,   9, 131,   1,   4,   7,  33, 132,   1,   9, 134,   1,   4,   9, 135,
   1,   4,   9, 136,   1,   4,   9, 137,   1,   4,   7,  33, 138,   1,   7,  33,
 140,   1,   9,  19,  23,   9, 128,   1,  26,   9, 132,   1,  26,   9, 138,   1,
  26,   9, 140,   1,  26,   9, 152,   1,  26,   9, 154,   1,  26,   9, 156,   1,
  26,   9, 158,   1,  26,   9, 160,   1,  26,   9, 162,   1,  26,   9, 117,  24,
   9, 164,   1,  26,   9, 166,   1,  26,   9, 168,   1,  26,   9, 170,   1,  26,
   9, 172,   1,  26,   9, 173,   1,  26,   9, 174,   1,  26,   9, 111,  24,   9,
 176,   1,  26,   9, 178,   1,  26,   9, 180,   1,  26,   9, 182,   1,  26,   7,
   2, 185,   1,   7,   2, 186,   1,   7,   2, 187,   1,   7,   2, 188,   1,   7,
   2, 189,   1,   7,   2, 190,   1,   7,   2, 191,   1,   9, 185,   1,   4,   9,
 186,   1,   4,   9, 187,   1,   4,   9, 188,   1,   4,   9, 189,   1,   4,   9,
 190,   1,   4,   9, 191,   1,   4,   9, 192,   1,   4,   9, 193,   1,   4,   9,
 194,   1,   4,   9, 195,   1,   4,   7,  46, 197,   1,   9,  19,  27,   9, 197,
   1,  28,   9,  63,  29,   9,  63,  30,   7,  14, 202,   1,   9,  19,  31,   9,
 202,   1,  22,   9, 205,   1,  32,   9, 208,   1,  32,   9, 209,   1,  32,   9,
 210,   1,  32,   9, 211,   1,  32,   9,  27,  32,   9, 212,   1,  32,   9, 214,
   1,   4,   9, 215,   1,   4,   9, 212,   1,   4,   9, 211,   1,   4,   9, 210,
   1,   4,   9, 209,   1,   4,   9, 208,   1,   4,   9, 205,   1,   4,   7,  56,
 216,   1,   9,  19,  32,   9, 214,   1,  32,   7,  55, 214,   1,   9, 215,   1,
  32,   7,  55, 215,   1,   9, 216,   1,  33,   9, 214,   1,  34,   9, 215,   1,
  34,   9, 212,   1,  34,   9,  27,  34,   9, 211,   1,  34,   9, 210,   1,  34,
   9, 209,   1,  34,   9, 208,   1,  34,   9, 218,   1,  34,   9, 219,   1,  35,
   9, 222,   1,  35,   9, 223,   1,  35,   9, 224,   1,  35,   9, 225,   1,  35,
   9, 226,   1,  35,   9, 227,   1,  35,   9, 228,   1,  35,   9, 229,   1,  35,
   9, 231,   1,   4,   9, 232,   1,   4,   9, 233,   1,   4,   9, 234,   1,   4,
   9, 235,   1,   4,   9, 236,   1,   4,   9, 237,   1,   4,   9, 238,   1,   4,
   9, 239,   1,   4,   9, 240,   1,   4,   9, 241,   1,   4,   9, 242,   1,   4,
   9, 243,   1,   4,   9, 244,   1,   4,   9, 245,   1,   4,   9, 246,   1,   4,
   9, 247,   1,   4,   9, 248,   1,   4,   9, 249,   1,   4,   9, 250,   1,   4,
   9, 251,   1,   4,   9, 252,   1,   4,   9, 253,   1,   4,   9, 254,   1,   4,
   9, 255,   1,   4,   9, 128,   2,   4,   9, 129,   2,   4,   9, 229,   1,   4,
   9, 223,   1,   4,   9, 228,   1,   4,   9, 227,   1,   4,   9, 226,   1,   4,
   9, 225,   1,   4,   9, 224,   1,   4,   9, 222,   1,   4,   7,  61, 219,   1,
   9, 219,   1,  36,   9,  19,  35,   9, 231,   1,  37,   9, 231,   1,  35,   7,
  60, 231,   1,   9, 232,   1,  37,   9, 232,   1,  35,   7,  60, 232,   1,   9,
 233,   1,  37,   9, 233,   1,  35,   7,  60, 233,   1,   9, 234,   1,  37,   9,
 234,   1,  35,   7,  60, 234,   1,   9, 235,   1,  37,   9, 235,   1,  35,   7,
  60, 235,   1,   9, 236,   1,  37,   9, 236,   1,  35,   7,  60, 236,   1,   9,
 237,   1,  37,   9, 237,   1,  35,   7,  60, 237,   1,   9, 238,   1,  37,   9,
 238,   1,  35,   7,  60, 238,   1,   9, 239,   1,  37,   9, 239,   1,  35,   7,
  60, 239,   1,   9, 240,   1,  37,   9, 240,   1,  35,   7,  60, 240,   1,   9,
 241,   1,  37,   9, 241,   1,  35,   7,  60, 241,   1,   9, 242,   1,  37,   9,
 242,   1,  35,   7,  60, 242,   1,   9, 243,   1,  37,   9, 243,   1,  35,   7,
  60, 243,   1,   9, 244,   1,  37,   9, 244,   1,  35,   7,  60, 244,   1,   9,
 245,   1,  37,   9, 245,   1,  35,   7,  60, 245,   1,   9, 246,   1,  37,   9,
 246,   1,  35,   7,  60, 246,   1,   9, 247,   1,  37,   9, 247,   1,  35,   7,
  60, 247,   1,   9, 248,   1,  37,   9, 248,   1,  35,   7,  60, 248,   1,   9,
 249,   1,  37,   9, 249,   1,  35,   7,  60, 249,   1,   9, 250,   1,  37,   9,
 250,   1,  35,   7,  60, 250,   1,   9, 251,   1,  37,   9, 251,   1,  35,   7,
  60, 251,   1,   9, 252,   1,  37,   9, 252,   1,  35,   7,  60, 252,   1,   9,
 253,   1,  37,   9, 253,   1,  35,   7,  60, 253,   1,   9, 254,   1,  37,   9,
 254,   1,  35,   7,  60, 254,   1,   9, 255,   1,  37,   9, 255,   1,  35,   7,
  60, 255,   1,   9, 128,   2,  37,   9, 128,   2,  35,   7,  60, 128,   2,   9,
 129,   2,  37,   7,  60, 129,   2,   9, 229,   1,  37,   9, 228,   1,  37,   9,
 227,   1,  37,   9, 226,   1,  37,   9, 225,   1,  37,   9, 224,   1,  37,   9,
 223,   1,  37,   9, 222,   1,  37,   9, 235,   1,  38,   9, 240,   1,  38,   9,
 238,   1,  38,   9, 237,   1,  38,   9, 239,   1,  38,   9, 241,   1,  38,   9,
 236,   1,  38,   9, 242,   1,  38,   9,  23,  38,  27,  38,   9, 244,   1,  38,
   9, 245,   1,  38,   9, 246,   1,  38,   9, 248,   1,  38,   9, 249,   1,  38,
   9, 250,   1,  38,   9, 252,   1,  38,   9, 253,   1,  38,   9, 254,   1,  38,
   9, 144,   2,  38,   9, 145,   2,  39,   9, 146,   2,  39,   9, 147,   2,  39,
   9, 148,   2,  38,   9, 149,   2,  38,   9, 150,   2,  38,   9, 150,   2,   4,
   9, 149,   2,   4,   7,  66, 148,   2,   9, 148,   2,  39,   9,  19,  38,   9,
 150,   2,  40,   9, 149,   2,  40,   9, 153,   2,  40,   9, 154,   2,  41,   9,
 157,   2,  41,   9, 159,   2,   4,   9, 160,   2,   4,   9, 161,   2,   4,   9,
 162,   2,   4,   9, 163,   2,   4,   9, 164,   2,   4,   9, 165,   2,   4,   9,
 166,   2,   4,   9, 167,   2,   4,   9, 168,   2,   4,   9, 169,   2,   4,   9,
 170,   2,   4,   9, 171,   2,   4,   9, 172,   2,   4,   9, 173,   2,   4,   9,
 174,   2,   4,   9, 175,   2,   4,   9, 176,   2,   4,   9, 177,   2,   4,   9,
 178,   2,   4,   9, 179,   2,   4,   9, 180,   2,   4,   9, 181,   2,   4,   9,
 182,   2,   4,   9, 183,   2,   4,   9, 184,   2,   4,   9, 185,   2,   4,   9,
 186,   2,   4,   9, 187,   2,   4,   9, 188,   2,   4,   9, 189,   2,   4,   9,
 190,   2,   4,   9, 191,   2,   4,   9, 192,   2,   4,   9, 193,   2,   4,   9,
 194,   2,   4,   9, 195,   2,   4,   9, 196,   2,   4,   9, 197,   2,   4,   9,
 198,   2,   4,   9, 199,   2,   4,   9, 200,   2,   4,   9, 201,   2,   4,   9,
 202,   2,   4,   9, 203,   2,   4,   9, 204,   2,   4,   9, 205,   2,   4,   9,
 206,   2,   4,   9, 207,   2,   4,   9, 208,   2,   4,   9, 157,   2,   4,   7,
  71, 154,   2,   9, 154,   2,  42,   9,  19,  41,   9, 159,   2,  43,   9, 159,
   2,  41,   7,  70, 159,   2,   9, 160,   2,  43,   9, 160,   2,  41,   7,  70,
 160,   2,   9, 161,   2,  43,   9, 161,   2,  41,   7,  70, 161,   2,   9, 162,
   2,  43,   9, 162,   2,  41,   7,  70, 162,   2,   9, 163,   2,  43,   9, 163,
   2,  41,   7,  70, 163,   2,   9, 164,   2,  43,   9, 164,   2,  41,   7,  70,
 164,   2,   9, 165,   2,  43,   9, 165,   2,  41,   7,  70, 165,   2,   9, 166,
   2,  43,   9, 166,   2,  41,   7,  70, 166,   2,   9, 167,   2,  43,   9, 167,
   2,  41,   7,  70, 167,   2,   9, 168,   2,  43,   9, 168,   2,  41,   7,  70,
 168,   2,   9, 169,   2,  43,   9, 169,   2,  41,   7,  70, 169,   2,   9, 170,
   2,  43,   9, 170,   2,  41,   7,  70, 170,   2,   9, 171,   2,  43,   9, 171,
   2,  41,   7,  70, 171,   2,   9, 172,   2,  43,   9, 172,   2,  41,   7,  70,
 172,   2,   9, 173,   2,  43,   9, 173,   2,  41,   7,  70, 173,   2,   9, 174,
   2,  43,   9, 174,   2,  41,   7,  70, 174,   2,   9, 175,   2,  43,   9, 175,
   2,  41,   7,  70, 175,   2,   9, 176,   2,  43,   9, 176,   2,  41,   7,  70,
 176,   2,   9, 177,   2,  43,   9, 177,   2,  41,   7,  70, 177,   2,   9, 178,
   2,  43,   9, 178,   2,  41,   7,  70, 178,   2,   9, 179,   2,  43,   9, 179,
   2,  41,   7,  70, 179,   2,   9, 180,   2,  43,   9, 180,   2,  41,   7,  70,
 180,   2,   9, 181,   2,  43,   9, 181,   2,  41,   7,  70, 181,   2,   9, 182,
   2,  43,   9, 182,   2,  41,   7,  70, 182,   2,   9, 183,   2,  43,   9, 183,
   2,  41,   7,  70, 183,   2,   9, 184,   2,  43,   9, 184,   2,  41,   7,  70,
 184,   2,   9, 185,   2,  43,   9, 185,   2,  41,   7,  70, 185,   2,   9, 186,
   2,  43,   9, 186,   2,  41,   7,  70, 186,   2,   9, 187,   2,  43,   9, 187,
   2,  41,   7,  70, 187,   2,   9, 188,   2,  43,   9, 188,   2,  41,   7,  70,
 188,   2,   9, 189,   2,  43,   9, 189,   2,  41,   7,  70, 189,   2,   9, 190,
   2,  43,   9, 190,   2,  41,   7,  70, 190,   2,   9, 191,   2,  43,   9, 191,
   2,  41,   7,  70, 191,   2,   9, 192,   2,  43,   9, 192,   2,  41,   7,  70,
 192,   2,   9, 193,   2,  43,   9, 193,   2,  41,   7,  70, 193,   2,   9, 194,
   2,  43,   9, 194,   2,  41,   7,  70, 194,   2,   9, 195,   2,  43,   9, 195,
   2,  41,   7,  70, 195,   2,   9, 196,   2,  43,   9, 196,   2,  41,   7,  70,
 196,   2,   9, 197,   2,  43,   9, 197,   2,  41,   7,  70, 197,   2,   9, 198,
   2,  43,   9, 198,   2,  41,   7,  70, 198,   2,   9, 199,   2,  43,   9, 199,
   2,  41,   7,  70, 199,   2,   9, 200,   2,  43,   9, 200,   2,  41,   7,  70,
 200,   2,   9, 201,   2,  43,   9, 201,   2,  41,   7,  70, 201,   2,   9, 202,
   2,  43,   9, 202,   2,  41,   7,  70, 202,   2,   9, 203,   2,  43,   9, 203,
   2,  41,   7,  70, 203,   2,   9, 204,   2,  43,   9, 204,   2,  41,   7,  70,
 204,   2,   9, 205,   2,  43,   9, 205,   2,  41,   7,  70, 205,   2,   9, 206,
   2,  43,   9, 206,   2,  41,   7,  70, 206,   2,   9, 207,   2,  43,   9, 207,
   2,  41,   7,  70, 207,   2,   9, 208,   2,  43,   9, 208,   2,  41,   7,  70,
 208,   2,   9, 157,   2,  43,   9, 210,   2,  44,   9, 213,   2,  44,   9, 215,
   2,   4,   9, 216,   2,   4,   9, 213,   2,   4,   9, 210,   2,   4,   7,  76,
 217,   2,   9,  19,  44,   9, 215,   2,  44,   7,  75, 215,   2,   9, 216,   2,
  44,   7,  75, 216,   2,   9, 217,   2,  45,   9, 215,   2,  46,   9, 216,   2,
  46,   9, 213,   2,  46,   9, 210,   2,  46,   9, 219,   2,  47,   9, 222,   2,
  47,   9, 223,   2,  47,   9, 225,   2,   4,   9, 226,   2,   4,   9, 227,   2,
   4,   9, 228,   2,   4,   9, 229,   2,   4,   9, 230,   2,   4,   9, 231,   2,
   4,   9, 232,   2,   4,   9, 233,   2,   4,   9, 234,   2,   4,   9, 235,   2,
   4,   9, 236,   2,   4,   9, 237,   2,   4,   9, 238,   2,   4,   9, 239,   2,
   4,   9, 240,   2,   4,   9, 241,   2,   4,   9, 242,   2,   4,   9, 243,   2,
   4,   9, 244,   2,   4,   9, 245,   2,   4,   9, 246,   2,   4,   9, 247,   2,
   4,   9, 248,   2,   4,   9, 249,   2,   4,   9, 250,   2,   4,   9, 251,   2,
   4,   9, 252,   2,   4,   9, 253,   2,   4,   9, 254,   2,   4,   9, 255,   2,
   4,   9, 128,   3,   4,   9, 129,   3,   4,   9, 130,   3,   4,   9, 131,   3,
   4,   9, 223,   2,   4,   9, 222,   2,   4,   7,  81, 219,   2,   9, 219,   2,
  48,   9,  19,  47,   9, 225,   2,  49,   9, 225,   2,  47,   7,  80, 225,   2,
   9, 226,   2,  49,   9, 226,   2,  47,   7,  80, 226,   2,   9, 227,   2,  49,
   9, 227,   2,  47,   7,  80, 227,   2,   9, 228,   2,  49,   9, 228,   2,  47,
   7,  80, 228,   2,   9, 229,   2,  49,   9, 229,   2,  47,   7,  80, 229,   2,
   9, 230,   2,  49,   9, 230,   2,  47,   7,  80, 230,   2,   9, 231,   2,  49,
   9, 231,   2,  47,   7,  80, 231,   2,   9, 232,   2,  49,   9, 232,   2,  47,
   7,  80, 232,   2,   9, 233,   2,  49,   9, 233,   2,  47,   7,  80, 233,   2,
   9, 234,   2,  49,   9, 234,   2,  47,   7,  80, 234,   2,   9, 235,   2,  49,
   9, 235,   2,  47,   7,  80, 235,   2,   9, 236,   2,  49,   9, 236,   2,  47,
   7,  80, 236,   2,   9, 237,   2,  49,   9, 237,   2,  47,   7,  80, 237,   2,
   9, 238,   2,  49,   9, 238,   2,  47,   7,  80, 238,   2,   9, 239,   2,  49,
   9, 239,   2,  47,   7,  80, 239,   2,   9, 240,   2,  49,   9, 240,   2,  47,
   7,  80, 240,   2,   9, 241,   2,  49,   9, 241,   2,  47,   7,  80, 241,   2,
   9, 242,   2,  49,   9, 242,   2,  47,   7,  80, 242,   2,   9, 243,   2,  49,
   9, 243,   2,  47,   7,  80, 243,   2,   9, 244,   2,  49,   9, 244,   2,  47,
   7,  80, 244,   2,   9, 245,   2,  49,   9, 245,   2,  47,   7,  80, 245,   2,
   9, 246,   2,  49,   9, 246,   2,  47,   7,  80, 246,   2,   9, 247,   2,  49,
   9, 247,   2,  47,   7,  80, 247,   2,   9, 248,   2,  49,   9, 248,   2,  47,
   7,  80, 248,   2,   9, 249,   2,  49,   9, 249,   2,  47,   7,  80, 249,   2,
   9, 250,   2,  49,   9, 250,   2,  47,   7,  80, 250,   2,   9, 251,   2,  49,
   9, 251,   2,  47,   7,  80, 251,   2,   9, 252,   2,  49,   9, 252,   2,  47,
   7,  80, 252,   2,   9, 253,   2,  49,   9, 253,   2,  47,   7,  80, 253,   2,
   9, 254,   2,  49,   9, 254,   2,  47,   7,  80, 254,   2,   9, 255,   2,  49,
   9, 255,   2,  47,   7,  80, 255,   2,   9, 128,   3,  49,   9, 128,   3,  47,
   7,  80, 128,   3,   9, 129,   3,  49,   9, 129,   3,  47,   7,  80, 129,   3,
   9, 130,   3,  49,   9, 130,   3,  47,   7,  80, 130,   3,   9, 131,   3,  49,
   9, 131,   3,  47,   7,  80, 131,   3,   9, 133,   3,  49,   9, 134,   3,  49,
   9, 229,   1,  50,   9, 231,   1,  50,   9, 233,   1,  50,   9, 234,   1,  50,
   9, 137,   3,  50,   9, 138,   3,  50,   9,  38,  51,   9,  40,  50,   9,  41,
  50,   9, 139,   3,   4,   9, 140,   3,   4,   9, 141,   3,   4,   9, 142,   3,
   4,   9, 143,   3,   4,   9, 144,   3,   4,   9, 145,   3,   4,   9, 137,   3,
   4,   9, 138,   3,   4,   9, 146,   3,   4,   7,   4, 147,   3,   9, 147,   3,
   9,   9,  19,  52,   9, 147,   3,  12,   7,  88, 150,   3,   7,  88, 152,   3,
   7,  88, 153,   3,   7,  88, 160,   3,   9, 120,  53,   9, 153,   3,  53,  27,
  53,   9, 147,   3,  53,   9,  42,  53,   9,  43,  53,   9,  99,  53,   9, 168,
   3,  53,   9, 169,   3,  53,   9, 171,   3,  53,   9, 172,   3,  53,   9, 173,
   3,  53,   9, 175,   3,  53,   9, 144,   2,  53,   9, 176,   3,  53,   9, 150,
   3,  53,   9, 160,   3,  53,   9, 180,   3,  53,   9, 181,   3,  53,   9, 152,
   3,  53,   9, 183,   3,  53,   9, 184,   3,  53,   9, 185,   3,  53,   9, 187,
   3,  53,   9, 201,   3,  53,   9, 202,   3,  53,   9, 203,   3,  53,   9, 204,
   3,  53,   9, 205,   3,  53,   9, 207,   3,  53,   9, 209,   3,  53,   9, 210,
   3,  53,   9, 213,   3,  53,   9, 214,   3,  53,   9, 216,   3,  53,   9, 236,
   3,  53,   9, 237,   3,  53,   9, 238,   3,  53,   9, 239,   3,  53,   9, 240,
   3,  53,   9, 241,   3,  53,   9, 242,   3,  53,   9, 227,   1,  53,   9, 243,
   3,  53,   9, 244,   3,  53,   9, 245,   3,  53,   9, 246,   3,  53,   9, 247,
   3,  53,   9, 248,   3,  53,   9, 249,   3,  53,   9, 250,   3,  53,   9, 251,
   3,  53,   9, 252,   3,  53,   9, 253,   3,  53,   9, 254,   3,  53,   9, 255,
   3,  53,   9, 128,   4,  53,   9, 129,   4,  53,   9, 130,   4,  53,   9, 150,
   3,  54,   9, 152,   3,  54,   9, 236,   3,  54,   9, 240,   3,  54,   9, 242,
   3,  54,   9, 243,   3,  54,   9, 245,   3,  54,   9, 247,   3,  54,   9, 237,
   3,  54,   9, 241,   3,  54,   9, 244,   3,  54,   9, 246,   3,  54,   9, 248,
   3,  54,   9, 249,   3,  54,   9, 251,   3,  54,   9, 253,   3,  54,   9, 255,
   3,  54,   9, 129,   4,  54,   9, 201,   3,  54,   9, 238,   3,  54,   9, 239,
   3,  54,   9, 250,   3,  54,   9, 169,   3,  54,   9, 171,   3,  54,   9, 172,
   3,  54,   9, 173,   3,  54,   9, 153,   3,  54,   9, 184,   3,  54,   9, 180,
   3,  54,   9, 160,   3,  54,   9, 210,   3,  54,   9, 252,   3,  54,   9, 183,
   3,  54,   9, 254,   3,  54,   9, 128,   4,  54,   9, 202,   3,  54,   9, 203,
   3,  54,   9, 204,   3,  54,   9, 130,   4,  54,   9, 213,   3,  54,   9, 214,
   3,  54,   9, 131,   4,   4,   9, 132,   4,   4,   9, 133,   4,   4,   9, 176,
   3,   4,   9, 187,   3,   4,   9, 134,   4,   4,   9, 185,   3,   4,   9, 205,
   3,   4,   9, 207,   3,   4,   9, 135,   4,   4,   9, 209,   3,   4,   7,   4,
 136,   4,   9,  19,  55,   9, 136,   4,  12,   9, 139,   4,  56,   9,   9,  56,
   9, 175,   3,  56,   9,  99,  56,   9, 143,   4,  56,   9, 168,   3,  56,   9,
 144,   4,  56,   9, 146,   4,  56,   7,   4, 147,   4,   9, 148,   4,  56,   9,
 149,   4,  56,   9, 150,   4,  56,   9, 151,   4,  56,   9, 155,   4,  56,   9,
 225,   2,  56,   9, 226,   2,  56,   9, 227,   2,  56,   9, 156,   4,  56,   9,
 157,   4,  56,   9, 158,   4,  56,   9, 159,   4,  56,   9,   6,  56,   9, 160,
   4,  56,   9, 161,   4,  56,   9, 150,   2,  56,   9, 162,   4,  56,   9, 163,
   4,  56,   9, 164,   4,  56,   9, 204,   2,  56,   9, 167,   4,  56,   9, 168,
   4,  56,   9, 171,   4,  56,   9, 172,   4,  56,   9, 174,   4,  56,   9, 175,
   4,  56,   9, 177,   4,  56,   9, 178,   4,  56,   9, 179,   4,  56,   9, 181,
   4,  56,   9, 183,   4,  56,   9, 184,   4,  56,   9, 185,   4,  56,   7,  96,
 163,   4,   9, 162,   4,   4,   9, 139,   4,  57,   9, 187,   4,   4,   9, 144,
   4,   4,   9, 188,   4,   4,   9, 157,   4,  57,   9, 156,   4,  57,   9, 159,
   4,  57,   9, 158,   4,  57,   9, 149,   4,  57,   9, 150,   4,  57,   9, 151,
   4,  57,   9, 189,   4,  57,   9, 175,   4,  57,   9, 178,   4,  57,   9, 148,
   4,  57,   9, 146,   4,  57,   9, 160,   4,  57,   9, 164,   4,  57,   9, 167,
   4,  57,   9, 168,   4,  57,   9, 174,   4,  57,   9, 177,   4,  57,   9, 181,
   4,  57,   9, 184,   4,  57,   9, 185,   4,  57,   9, 190,   4,   4,   9, 163,
   4,   4,   9, 163,   4,  58,   9, 191,   4,   4,   9, 192,   4,   4,   9, 155,
   4,  57,   9, 193,   4,   4,   9, 194,   4,   4,   9, 195,   4,   4,   9, 196,
   4,   4,   9, 197,   4,   4,   9, 198,   4,   4,   9, 171,   4,   4,   9, 199,
   4,   4,   9, 172,   4,   4,   9, 200,   4,   4,   9, 201,   4,   4,   9, 179,
   4,   4,   9, 202,   4,   4,   9, 203,   4,   4,   9, 204,   4,   4,   9, 205,
   4,   4,   9, 206,   4,   4,   9,  19,  59,   9, 207,   4,  12,   9, 147,   4,
  12,   7,   2, 211,   4,   7,   2, 213,   4,   9, 211,   4,   4,   9, 213,   4,
   4,   7,  14, 215,   4,   9,  19,  60,   9, 215,   4,  22,   7,   4, 218,   4,
   9, 219,   4,   4,   9, 220,   4,   4,   9, 221,   4,   4,   9, 222,   4,   4,
   9, 223,   4,   4,   9, 224,   4,   4,   9,  19,  61,   9, 218,   4,  12, 169,
   3,   0,   3,   3,   0,   0,   5,   3,   0,   0,   7,   3,   4,   0,   7,   3,
   4,   1,  11,   3,   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   1,   7,
  18,   3,  32,   1,  18,   3,   3,  32,   0,   3,   3,  32,   1,   7,  19,   3,
  32,   1,   7,   3,   3,  32,   0,   7,   3,  32,   0,  20,   3,  32,   0,   5,
   3,  32,   0,  19,   3,  32,   0,   3,   3,  32,   0,   3,   3,  32,   0,  21,
   3,  32,   0,  21,   3,  32,   0,  21,   3,  32,   0,   7,   3,  32,   0,   7,
   3,  32,   0,   0,   3,   0,   0,   0,   3,   0,   1,  20,   3,   3,  32,   1,
   3,   3,   3,  32,   2,   7,   3,   3,   3,  32,   2,  44,   3,  20,   3,   0,
   2,  20,   3,  44,   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   0,   3,
   3,   0,   0,  20,   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   0,   0,
   3,   0,   0,  66,   3,  32,   0,   5,   3,  32,   1,   7,  66,   3,  32,   1,
   0,  66,   3,   0,   1,   0,  44,   3,  32,   1,  11,   3,   3,  32,   1,   0,
   3,   3,   0,   0,  44,   3,  32,   1,   0,  44,   3,  32,   0,   0,   3,   0,
   0,   0,   3,   0,   1,  44,   3,   3,  32,   1,   7,   3,   3,  32,   3,   7,
  44,   5,   5,   3,  40,   2,   1,   3,   1,   3,   3,   7,  44,   5,   5,   3,
  40,   2,   1,   3,   1,   3,   1,   7,  20,   3,  32,   1,   7,  18,   3,  32,
   1,   7,  18,   3,  32,   1,   7,  18,   3,  32,   1,   7,   5,   3,  32,   1,
   7,  21,   3,  32,   1,   7,  21,   3,  32,   1,   7,   3,   3,  32,   1,   7,
   3,   3,  32,   0,  20,   3,  32,   0,  18,   3,  32,   0,   5,   3,  32,   0,
  18,   3,  32,   0,   5,   3,  32,   0,  18,   3,  32,   0,   5,   3,  32,   0,
  21,   3,  32,   0,  21,   3,  32,   0,   3,   3,  32,   1,   3,   5,   3,  32,
   0,   5,   3,  32,   1,   7,   5,   3,  32,   0,   7,   3,  32,   0,   7,   3,
   0,   0,   7,   3,  32,   0,   7,   3,   0,   0,   3,   3,  32,   0,   3,   3,
   0,   0,   5,   3,  32,   0,   5,   3,  32,   1,   7,   5,   3,  32,   0,   3,
   3,  32,   1,   7,   3,   3,  32,   0,   0,   3,   0,   0,   0,   3,   0,   1,
   3,   3,   3,  32,   1,  41, 121,   3,  32,   1,  19, 121,   3,  32,   2,  20,
  41, 122,   3,  32,   3,  21,  41, 122,   5,   3,  32,   2,  21,  41, 122,   3,
   0,   2,  21,  41, 122,   3,   0,   2,  21,  41, 122,   3,   0,   0,  21,   3,
  32,   0,  41,   3,  32,   2,  41,  41,  20,   3,  40,   1,  10,  10,   1,  21,
   0,   3,  32,   1,   7, 121,   3,  32,   0,   0,   3,   2,   1,   7, 121,   3,
   2,   1,   7,  20,   3,  32,   0,   7,   3,  32,   0,   7,   3,  32,   0,   7,
   3,  32,   0,   7,   3,  32,   0,   0,   3,   0,   0,   3,   3,   0,   0,   0,
   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   0,   0,
   3,  32,   0,  21,   3,  32,   0,   0,   3,   0,   0,   0,   3,   0,   0,   0,
   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   2,   0,  18,  18,   3,  40,
   1,   2,   3,   1,  18,  18,   3,  40,   1,   2,   3,   1,   0, 121,   3,  32,
   0, 121,   3,  32,   0,   0,   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,
   1,   7,  20,   3,  32,   1,   0,  20,   3,   8,   1,  10,  10,   0,   0,   3,
   0,   1,  18,   3,   3,   0,   1,   3,   3,   3,   0,   1,  18,   3,   3,   0,
   3,   0,   3,   3,  20,   3,   8,   1,  10,  10,   1,   3,   3,   3,   0,   1,
   7,  18,   3,   8,   1,   1,   3,   0,   7,   3,   0,   0,   0,   3,   0,   0,
  18,   3,  32,   0,  18,   3,  32,   0,   7,   3,  32,   1,   7,  18,   3,  40,
   1,   1,   3,   1,   3,   3,   3,  32,   3,  18,   3,   3,  18,   3,  32,   1,
  18,   3,   3,  32,   1,   3,   3,   3,  32,   1,  18,   3,   3,  32,   0,   0,
   3,   0,   0,   0,   3,   0,   1,   7,   5,   3,   0,   2,  18,   3,  18,   3,
   0,   1,  18,   3,   3,   0,   1,  18,   3,   3,   0,   0,   3,   3,   0,   0,
   3,   3,   0,   0,   3,   3,   0,   2,  18,   3,  18,   3,   0,   0,   0,   3,
   0,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,
  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,
  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,
  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,
  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,
  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,
  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   2,  18,   3,
  18,   3,  32,   2,  18,   3,  18,   3,  32,   0,   3,   3,  32,   0,   3,   3,
  32,   0,   3,   3,  32,   1,  18,   3,   3,  32,   1,  18,   3,   3,  32,   1,
   7,   5,   3,  32,   0,   0,   3,   0,   0,   0,   3,   0,   1,   3,  18,   3,
   0,   1,   3,  18,   3,   2,   1,   5,   3,   3,   0,   1,   3,  18,   3,   0,
   0,   0,   3,   0,   1,   3,  18,   3,  32,   1,   5,   3,   3,  32,   0,   0,
   3,   0,   0,   0,   3,   0,   1,   7,  18,   3,   0,   0,  18,   3,   0,   0,
   0,   3,   0,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,
  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,
  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,
  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,
  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,
  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,
  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,
  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,
  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,
  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,
  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,
  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,
  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   1,
   7,  18,   3,  32,   0,   0,   3,   0,   0,   0,   3,   0,   2,  18,   3,   3,
   3,   0,   1,  18,   3,   3,   0,   0,   0,   3,   0,   0,  18,   3,  32,   0,
  18,   3,  32,   1,  18,   3,   3,  32,   2,  18,   3,   3,   3,  32,   0,   0,
   3,   0,   0,   0,   3,   0,   2,  19,   3,  20,   3,   8,   1,  10,  10,   2,
  19,   3,  20,   3,   8,   1,  10,  10,   0,   0,   3,   0,   0,  18,   3,  32,
   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,
   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,
   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,
   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,
   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,
   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,
   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,
   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,
   0,  18,   3,  32,   0,  18,   3,  32,   2,  19,   3,  20,   3,  32,   2,  19,
   3,  20,   3,  32,   0,   0,   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,
   1,  20,   3,   3,  32,   1,   3,   3,   3,  32,   2,   7,   3,   3,   3,  32,
   1,  18,   3,   3,  32,   1,  20,   3,   3,   0,   1,  20,   3,   3,   0,   1,
  20,   3,   3,   0,   1,  20,   3,   3,  32,   1,  20,   3,   3,  32,   2,  19,
   3,  20,   3,  40,   1,  10,  10,   1,  21,   3,   3,  32,   1,  21,   3,   3,
  32,   1,  21,   3,   3,   0,   1,  44,   3,   3,   0,   2,   7,   3,  44,   3,
   0,   0,   0,   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   0,   3,   3,
  32,   0,   3,   3,  32,   0,   3,   3,  32,   0,   3,   3,  32,   0,   3,   3,
  32,   0,   3,   3,  32,   0,   3,   3,  32,   0,   3,   3,   0,   0,   7,   3,
   0,   0,   7,   3,   0,   0,   3,   3,   0,   0,   3,   3,   0,   0,   3,   3,
   0,   0,   3,   3,   0,   0,   3,   3,   0,   0,   3,   3,   0,   0,   3,   3,
   0,   0,   3,   3,   0,   0,   3,   3,   0,   0,   3,   3,   0,   0,   3,   3,
   0,   0,   3,   3,   0,   0,   3,   3,   0,   0,   3,   3,   0,   0,   3,   3,
   0,   0,   3,   3,   0,   0,   3,   3,   0,   0,   3,   3,   0,   0,   3,   3,
   0,   0,   3,   3,   0,   0,   3,   3,   0,   0,   3,   3,   0,   0,   0,   3,
   0,   0,   0,   3,   0,   0,   0,   3,   0,   0,  18,   3,  32,   1,   3,   3,
   3,  32,   1,  19,   3,   3,   0,   1,   3,   3,   3,  32,   1,  19,   3,   3,
   0,   3,   0,  18,  18,  18,   3,   8,   3,   6,   3,   6,   3,   6,   3,   0,
  18,   3,  32,   0,   3,   3,  32,   0,  44,   3,  32,   0,  20,   3,  32,   3,
   7,  18,  18,  18,   3,  32,   2,  20,   3,   3,   3,  32,   0,  20,   3,  32,
   2,  18,   3,  18,   3,  40,   1,   1,   3,   2,  18,  44,  18,   3,  40,   1,
   1,   3,   1,  18,  18,   3,  40,   1,   1,   3,   1,  18,  18,   3,  40,   1,
   1,   3,   1,  20,  18,   3,  32,   1,  20,  18,   3,  32,   0, 152,   7,   3,
  32,   0,  20,   3,   0,   0,  20,   3,   0,   1,   7,  20,   3,   0,   0,  20,
   3,   0,   0,  20,   3,   0,   0,  18,   3,  32,   0,   3,   3,   0,   0,  20,
   3,  32,   1,   7,  20,   3,  32,   0,  20,   3,  32,   1,   7,  20,   3,  32,
   0,  18,   3,   0,   0,   3,   3,   0,   0,  18,   3,   0,   0,   3,   3,   0,
   2,   7,   3,  18,   3,   0,   0,   7,   3,   0,   2,   7,   3,  18,   3,   8,
   1,   1,   3,   2,   7,  44,  18,   3,   8,   1,   1,   3,   4,   7,   3,  18,
   3,  18,   3,   8,   1,   1,   3,   1,   3,  18,   3,   8,   1,   1,   3,   1,
  44,  18,   3,   8,   1,   1,   3,   3,   3,   3,  18,  18,   3,   8,   1,   1,
   3,   1,  20,   5,   3,   0,   1,  20,   5,   3,   8,   1,   1,   3,   0, 152,
   7,   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   0,
   0,   3,   0,   0,   0,   3,   0,   1, 246,   7,   3,   3,  36,   3, 246,   7,
 246,   7,  18,  19,   3,  40,   1,  12,  12,   1,  19, 246,   7,   3,  32,   1,
   3,   3,   3,  36,   2,   3, 246,   7,   3,   3,  36,   2,   3, 246,   7,   3,
   3,  32,   0,   0,   3,   0,   0,   0,   3,   0,  35,  53,   2,  54,  56,  55,
  57,  53,   2,  54,  56,  58,  57,  53,   3,  54,  70,  56,  69,  71,  57,  53,
   3,  54,  70,  56, 107, 108,  57,  53,   4,  54,  70,  56, 144,   1, 142,   1,
 143,   1,  57, 145,   1,  53,   4,  54,  70,  56, 144,   1, 146,   1, 147,   1,
  57, 145,   1,  53,   4,  54,  70,  56, 144,   1, 148,   1, 149,   1,  57, 145,
   1,  53,   4,  54,  70,  56, 144,   1, 150,   1, 151,   1,  57, 145,   1,  53,
   1,   0, 153,   1,  53,   1,   0, 155,   1,  53,   1,   0, 157,   1,  53,   1,
   0, 159,   1,  53,   1,   0, 161,   1,  53,   1,   0, 163,   1,  53,   1,   0,
 165,   1,  53,   1,   0, 167,   1,  53,   1,   0, 169,   1,  53,   1,   0, 171,
   1,  53,   1,   0, 175,   1,  53,   1,   0, 177,   1,  53,   1,   0, 179,   1,
  53,   1,   0, 181,   1,  53,   1,   0, 183,   1,  53,   2,  54,  56, 199,   1,
  57,  53,   3,  54,  70,  56, 203,   1, 204,   1,  57,  53,   2,  54,  56, 217,
   1,  57,  53,   2,  54,  56, 130,   2,  57,  53,   2,  54,  56, 152,   2,  57,
  53,   2,  54,  56, 209,   2,  57,  53,   2,  54,  56, 218,   2,  57,  53,   2,
  54,  56, 132,   3,  57,  53,   2,  54,  56, 148,   3,  57,  53,   2,  54,  56,
 137,   4,  57,  53,   3,  54,  70,  56, 208,   4, 209,   4,  57,  53,   3,  54,
  70,  56, 226,   4, 218,   4,  57,  22,  40,  41,   9,   7,   0,  23,   0,  50,
  41,   9,  12,   0,  30,   0,  54,  41,  11,  18,   0,  34,   0,  66,  41,   9,
  24,   0,  40,   6,  73,   1,   0,  39,  74,   1,   0,  41,  75,   1,   0,  42,
  76,   1,   0,  43,  77,   2,   0,  44,  77,   3,   0,  45,  44,  41,   9,  29,
   0,  85,  36,  85,   1,   0,  49,  86,   1,   0,  50,  87,   1,   0,  51,  88,
   1,   0,  52,  89,   1,   0,  53,  90,   1,   0,  54,  91,   1,   0,  55,  92,
   1,   0,  56,  93,   1,   0,  57,  94,   1,   0,  58,  95,   1,   0,  59,  96,
   1,   0,  60,  97,   1,   0,  61,  98,   1,   0,  62,  99,   1,   0,  63, 100,
   1,   0,  64, 101,   1,   0,  65, 102,   1,   0,  66, 103,   1,   0,  67, 104,
   1,   0,  68, 105,   1,   0,  69, 106,   1,   0,  70, 107,   1,   0,  71, 108,
   2,   0,  72, 108,   3,   0,  73, 109,   1,   0,  74, 110,   1,   0,  75, 111,
   1,   0,  76, 112,   1,   0,  77, 113,   1,   0,  78, 114,   1,   0,  79, 115,
   2,   0,  80, 116,   2,   0,  81, 116,   3,   0,  82, 117,   2,   0,  83, 117,
   3,   0,  84, 137,   1,  41,  11,  36,   0, 109,   5, 133,   1,   6,   0,   3,
   0, 134,   1,   6,   0,   3,   0, 135,   1,   6,   0,   5,   0, 136,   1,   6,
   0,  21,   0, 114,   1,   0, 108, 140,   1,  41,   9,  39,   0, 111,   2, 138,
   1,   6,   0,  21,   0, 139,   1,   6,   0,  19,   0, 145,   1, 140,   1,  11,
  41,   0, 115,   4, 141,   1,   6,   0,  21,   0, 142,   1,   6,   0,  11,   0,
 143,   1,   2,   0, 113, 144,   1,   2,   0, 114, 146,   1, 140,   1,  11,  43,
   0, 117,   2, 141,   1,   6,   0,  21,   0, 144,   1,   6,   0,  21,   0, 189,
   1,  41,   9,  47,   0, 124,   0, 194,   1,  41,   8,  52,   0, 128,   1,   1,
 193,   1,   1,   0, 127, 212,   1,  41,   9,  58,   0, 147,   1,   0, 144,   2,
  41,   9,  63,   0, 193,   1,   0, 135,   3,  41,   9,  68,   0, 202,   1,   0,
 194,   3,  41,   9,  73,   0, 131,   2,   0, 226,   4,  41,   9,  78,   0, 140,
   2,   0, 149,   5,  41,   9,  83,   0, 182,   2,   0, 150,   6,  41,   9,  86,
   0, 200,   2,   0, 141,   7,  41,   9,  90,   0, 235,   2,   0, 152,   7,  41,
   9,  94,   0, 243,   2,  47, 192,   7,   0,   0,   3,   0, 193,   7,   0,   0,
  18,   0, 194,   7,   0,   0,   3,   0, 195,   7,   0,   0,  18,   0, 196,   7,
   0,   0,  20,  10,  10, 197,   7,   0,   0,  20,  10,  10, 198,   7,   0,   0,
  20,  10,  10, 199,   7,   2,   0, 244,   2, 200,   7,   2,   0, 245,   2, 201,
   7,   2,   0, 246,   2, 202,   7,   1,   0, 247,   2, 203,   7,   1,   0, 248,
   2, 204,   7,   1,   0, 249,   2, 205,   7,   1,   0, 250,   2, 206,   7,   1,
   0, 251,   2, 207,   7,   1,   0, 252,   2, 208,   7,   1,   0, 253,   2, 209,
   7,   1,   0, 254,   2, 210,   7,   1,   0, 255,   2, 211,   7,   1,   0, 128,
   3, 212,   7,   1,   0, 129,   3, 213,   7,   2,   0, 130,   3, 214,   7,   2,
   0, 131,   3, 215,   7,   3,   0, 132,   3, 216,   7,   2,   0, 133,   3, 217,
   7,   2,   0, 134,   3, 218,   7,   2,   0, 135,   3, 142,   1,   2,   0, 136,
   3, 219,   7,   2,   0, 137,   3, 219,   7,   3,   0, 138,   3, 220,   7,   2,
   0, 139,   3, 220,   7,   3,   0, 140,   3, 221,   7,   2,   0, 141,   3, 222,
   7,   2,   0, 142,   3, 223,   7,   2,   0, 143,   3, 224,   7,   2,   0, 144,
   3, 225,   7,   1,   0, 145,   3, 226,   7,   1,   0, 146,   3, 227,   7,   1,
   0, 147,   3, 228,   7,   1,   0, 148,   3, 229,   7,   1,   0, 149,   3, 230,
   7,   1,   0, 150,   3, 231,   7,   1,   0, 151,   3, 232,   7,   1,   0, 152,
   3, 233,   7,   1,   0, 153,   3, 234,   7,   1,   0, 154,   3, 235,   7,   1,
   0, 155,   3, 243,   7,  41,   9,  98,   0, 158,   3,   0, 246,   7,  41,   9,
 101,   0, 167,   3,   0,   6,  18,  22,  17,   3,   7,  23,  17,   4,   8,  24,
  17,   5,   9,  25,  17,   6,  10,  26,  17,   7,  11,  27,  17,   8,  12,  28,
  17,   9,  13,  29,  17,  10,  14,  30,  17,  11,  15,  31,   6,   1,  19,   0,
  32,  17,  12,  16,  33,   6,   2,   3,   0,  34,  17,  13,  17,  35,  18,  14,
  18,  36,  18,  15,  19,  37,  18,  16,  20,  38,  17,  17,  21,  39,  17,  18,
  22,  24,   5,  46,  17,   3,  25,  47,  17,   4,  26,  26,  17,   5,  27,  48,
  17,   6,  28,  49,  17,   7,  29,  31,   2,  53,  18,   3,  32,  28,  18,   4,
  33,  36,   2,  71,  18,   3,  37,  72,  18,   4,  38,  47,   1,  84,  17,   3,
  48, 107,   0, 110,   0, 112,   0, 116,   0, 119,  11, 178,   1,   6,   1,  18,
   1,   3, 179,   1,   6,   2,  18,   3,   3, 180,   1,   6,   3,  18,   2,   3,
 181,   1,   6,   4,  18,   4,   3, 182,   1,   6,   5,  18,   5,   3, 183,   1,
   6,   6,   0,   3,   3, 184,   1,   6,   7,   0,   2,   3, 185,   1,  17,   3,
 120, 186,   1,  17,   4, 121, 187,   1,  17,   5, 122, 188,   1,  17,   6, 123,
 126,   0, 137,   1,   9, 204,   1,  18,   3, 138,   1, 205,   1,  18,   4, 139,
   1, 206,   1,  17,   5, 140,   1,  22,  17,   6, 141,   1, 207,   1,  17,   7,
 142,   1, 208,   1,  17,   8, 143,   1, 209,   1,  17,   9, 144,   1, 210,   1,
  17,  10, 145,   1, 211,   1,  17,  11, 146,   1, 157,   1,  35, 237,   1,  18,
   3, 158,   1, 238,   1,  18,   4, 159,   1, 239,   1,  18,   5, 160,   1, 240,
   1,  18,   6, 161,   1, 241,   1,  18,   7, 162,   1, 242,   1,  18,   8, 163,
   1, 243,   1,  18,   9, 164,   1, 244,   1,  18,  10, 165,   1, 245,   1,  18,
  11, 166,   1, 246,   1,  18,  12, 167,   1, 247,   1,  18,  13, 168,   1, 248,
   1,  18,  14, 169,   1, 249,   1,  18,  15, 170,   1, 250,   1,  18,  16, 171,
   1, 251,   1,  18,  17, 172,   1, 252,   1,  18,  18, 173,   1, 253,   1,  18,
  19, 174,   1, 254,   1,  18,  20, 175,   1, 255,   1,  18,  21, 176,   1, 128,
   2,  18,  22, 177,   1, 129,   2,  18,  23, 178,   1, 130,   2,  18,  24, 179,
   1, 131,   2,  18,  25, 180,   1, 132,   2,  18,  26, 181,   1, 133,   2,  18,
  27, 182,   1, 134,   2,  18,  28, 183,   1, 135,   2,  18,  29, 184,   1, 136,
   2,  17,  30, 185,   1, 137,   2,  17,  31, 186,   1, 138,   2,  17,  32, 187,
   1, 139,   2,  17,  33, 188,   1, 140,   2,  17,  34, 189,   1, 141,   2,  17,
  35, 190,   1, 142,   2,  17,  36, 191,   1, 143,   2,  17,  37, 192,   1, 199,
   1,   2, 133,   3,  17,   3, 200,   1, 134,   3,  17,   4, 201,   1, 206,   1,
  52, 143,   3,  18,   3, 207,   1, 144,   3,  18,   4, 208,   1, 145,   3,  18,
   5, 209,   1, 146,   3,  18,   6, 210,   1, 147,   3,  18,   7, 211,   1, 148,
   3,  18,   8, 212,   1, 149,   3,  18,   9, 213,   1, 150,   3,  18,  10, 214,
   1, 151,   3,  18,  11, 215,   1, 152,   3,  18,  12, 216,   1, 153,   3,  18,
  13, 217,   1, 154,   3,  18,  14, 218,   1, 155,   3,  18,  15, 219,   1, 156,
   3,  18,  16, 220,   1, 157,   3,  18,  17, 221,   1, 158,   3,  18,  18, 222,
   1, 159,   3,  18,  19, 223,   1, 160,   3,  18,  20, 224,   1, 161,   3,  18,
  21, 225,   1, 162,   3,  18,  22, 226,   1, 163,   3,  18,  23, 227,   1, 164,
   3,  18,  24, 228,   1, 165,   3,  18,  25, 229,   1, 166,   3,  18,  26, 230,
   1, 167,   3,  18,  27, 231,   1, 168,   3,  18,  28, 232,   1, 169,   3,  18,
  29, 233,   1, 170,   3,  18,  30, 234,   1, 171,   3,  18,  31, 235,   1, 172,
   3,  18,  32, 236,   1, 173,   3,  18,  33, 237,   1, 174,   3,  18,  34, 238,
   1, 175,   3,  18,  35, 239,   1, 176,   3,  18,  36, 240,   1, 177,   3,  18,
  37, 241,   1, 178,   3,  18,  38, 242,   1, 179,   3,  18,  39, 243,   1, 180,
   3,  18,  40, 244,   1, 181,   3,  18,  41, 245,   1, 182,   3,  18,  42, 246,
   1, 183,   3,  18,  43, 247,   1, 184,   3,  18,  44, 248,   1, 185,   3,  18,
  45, 249,   1, 186,   3,  18,  46, 250,   1, 187,   3,  18,  47, 251,   1, 188,
   3,  18,  48, 252,   1, 189,   3,  18,  49, 253,   1, 190,   3,  18,  50, 254,
   1, 191,   3,  18,  51, 255,   1, 192,   3,  18,  52, 128,   2, 193,   3,  18,
  53, 129,   2, 193,   3,  19,  54, 130,   2, 135,   2,   4, 222,   4,  18,   3,
 136,   2, 223,   4,  18,   4, 137,   2, 224,   4,  17,   5, 138,   2, 225,   4,
  17,   6, 139,   2, 144,   2,  37, 240,   4,  18,   3, 145,   2, 241,   4,  18,
   4, 146,   2, 242,   4,  18,   5, 147,   2, 243,   4,  18,   6, 148,   2, 244,
   4,  18,   7, 149,   2, 245,   4,  18,   8, 150,   2, 246,   4,  18,   9, 151,
   2, 247,   4,  18,  10, 152,   2, 248,   4,  18,  11, 153,   2, 249,   4,  18,
  12, 154,   2, 250,   4,  18,  13, 155,   2, 251,   4,  18,  14, 156,   2, 252,
   4,  18,  15, 157,   2, 253,   4,  18,  16, 158,   2, 254,   4,  18,  17, 159,
   2, 255,   4,  18,  18, 160,   2, 128,   5,  18,  19, 161,   2, 129,   5,  18,
  20, 162,   2, 130,   5,  18,  21, 163,   2, 131,   5,  18,  22, 164,   2, 132,
   5,  18,  23, 165,   2, 133,   5,  18,  24, 166,   2, 134,   5,  18,  25, 167,
   2, 135,   5,  18,  26, 168,   2, 136,   5,  18,  27, 169,   2, 137,   5,  18,
  28, 170,   2, 138,   5,  18,  29, 171,   2, 139,   5,  18,  30, 172,   2, 140,
   5,  18,  31, 173,   2, 141,   5,  18,  32, 174,   2, 142,   5,  18,  33, 175,
   2, 143,   5,  18,  34, 176,   2, 144,   5,  18,  35, 177,   2, 145,   5,  18,
  36, 178,   2, 146,   5,  18,  37, 179,   2, 147,   5,  17,  38, 180,   2, 148,
   5,  17,  39, 181,   2, 184,   2,  15,  46,  17,   3, 185,   2,  47,  17,   4,
 186,   2,  26,  17,   5, 187,   2, 140,   6,  17,   6, 188,   2, 141,   6,  17,
   7, 189,   2, 142,   6,  17,   8, 190,   2, 143,   6,  17,   9, 191,   2, 144,
   6,  17,  10, 192,   2, 145,   6,  17,  11, 193,   2, 146,   6,  17,  12, 194,
   2, 147,   6,  17,  13, 195,   2, 148,   6,  17,  14, 196,   2, 149,   6,  17,
  15, 197,   2,  48,  17,  16, 198,   2,  49,  17,  17, 199,   2, 202,   2,  53,
 217,   6,   6,   1,   3, 151,   3,   1, 218,   6,   6,   2,   3,   3,   1, 219,
   6,   0,   3,   3,   0, 220,   6,   0,   4,   3,   0, 221,   6,   0,   5,   3,
   0, 222,   6,   0,   6,   3,   0, 223,   6,   0,   7,   3,   0, 224,   6,   0,
   8,   3,   0, 225,   6,  17,   3, 203,   2, 226,   6,  17,   4, 204,   2, 227,
   6,  17,   5, 205,   2, 228,   6,  17,   6, 206,   2, 229,   6,  17,   7, 207,
   2, 230,   6,   0,   9,   3,   0, 231,   6,   0,  10,   3,   0, 232,   6,   0,
  11,   3,   0, 233,   6,   0,  12,   3,   0, 234,   6,   0,  13,   3,   0, 235,
   6,  17,   8, 208,   2, 236,   6,   0,  14,   3,   0, 237,   6,  17,   9, 209,
   2, 238,   6,  17,  10, 210,   2, 239,   6,   0,  15,   3,   0, 240,   6,   0,
  16,   3,   0, 241,   6,   0,  17,   3,   0, 242,   6,   0,  18,   3,   0, 243,
   6,   0,  19,  19,   0, 244,   6,  17,  11, 211,   2, 245,   6,   0,  20,   3,
   0, 246,   6,   0,  21,   3, 161,   3,   1, 247,   6,  17,  12, 212,   2, 248,
   6,  17,  13, 213,   2, 249,   6,  17,  14, 214,   2, 250,   6,  17,  15, 215,
   2, 251,   6,  17,  16, 216,   2, 252,   6,  17,  17, 217,   2, 253,   6,  17,
  18, 218,   2, 254,   6,  17,  19, 219,   2, 255,   6,  17,  20, 220,   2, 128,
   7,  17,  21, 221,   2, 129,   7,  17,  22, 222,   2, 133,   1,  18,  23, 223,
   2, 130,   7,  18,  24, 224,   2, 131,   7,  18,  25, 225,   2, 132,   7,  18,
  26, 226,   2, 133,   7,  18,  27, 227,   2, 134,   7,  18,  28, 228,   2, 135,
   7,  18,  29, 229,   2, 136,   7,  18,  30, 230,   2, 137,   7,  18,  31, 231,
   2, 138,   7,  18,  32, 232,   2, 139,   7,  18,  33, 233,   2, 140,   7,  18,
  34, 234,   2, 237,   2,   5, 187,   7,  18,   3, 238,   2, 188,   7,  17,   4,
 239,   2, 189,   7,  17,   5, 240,   2, 190,   7,  17,   6, 241,   2, 191,   7,
  17,   7, 242,   2, 157,   3,   2, 241,   7,   6,   1,   3, 212,   4,   1, 242,
   7,   6,   2,   3, 214,   4,   1, 160,   3,   6, 247,   7,  17,   3, 161,   3,
 248,   7,  17,   4, 162,   3, 249,   7,  17,   5, 163,   3, 250,   7,  17,   6,
 164,   3, 251,   7,  17,   7, 165,   3, 252,   7,  17,   8, 166,   3,  17,  46,
   1,  80,  68,   0,   3,   1,   2,  86,   1, 120,  68,   0,   4,   1,   3, 118,
  23, 148,   1,  68,   1,   5,   1,   4, 149,   1,  68,   2,   6,   1,   5, 150,
   1,  68,   3,   7,   1,   6, 151,   1,  68,   4,   8,   1,   7, 152,   1,  65,
   7, 106,   1,   8, 153,   1,  65,   8, 105,   1,   9, 154,   1,  65,   9, 104,
   1,  10, 155,   1,  65,  10, 103,   1,  11, 156,   1,  65,  11, 102,   1,  12,
 157,   1,   1,  12, 101, 158,   1,  65,  13,  99,   1,  13, 159,   1,  65,  14,
  98,   1,  14, 160,   1,  65,  15,  97,   1,  15, 161,   1,  65,  16,  96,   1,
  16, 162,   1,  65,  17,  95,   1,  17, 163,   1,   1,  18,  94, 164,   1,   1,
  19,  93, 165,   1,   1,  20,  92, 166,   1,  65,  21,  91,   1,  18, 167,   1,
  65,  22,  90,   1,  19, 168,   1,  65,  23,  89,   1,  20, 169,   1,  65,  24,
  88,   1,  21, 170,   1,  65,  25,  87,   1,  22, 125,   1, 191,   1,  68,   1,
   9,   1,  23, 129,   1,   1, 196,   1,  68,   1,  10,   1,  24, 148,   1,  10,
 218,   1,  68,   1,  11,   1,  25, 219,   1,   6,   2,  18,   0, 220,   1,   6,
   3,  18,   0, 221,   1,   1,  26, 136,   1, 222,   1,   1,  27, 135,   1, 223,
   1,   1,  28, 134,   1, 224,   1,   1,  29, 133,   1, 225,   1,   1,  30, 132,
   1, 226,   1,   1,  31, 131,   1, 227,   1,   1,  32, 130,   1, 194,   1,  36,
 145,   2,  68,   0,  12,   1,  26, 147,   2,   6,   0,  18,   0, 150,   2,   6,
   0,  18,   0, 153,   2,   6,   0,  18,   0, 156,   2,   6,   0,  18,   0, 159,
   2,   6,   0,  18,   0, 162,   2,   6,   0,  18,   0, 165,   2,   6,   0,  18,
   0, 168,   2,   6,   0,  18,   0, 171,   2,   6,   0,  18,   0, 174,   2,   6,
   0,  18,   0, 177,   2,   6,   0,  18,   0, 180,   2,   6,   0,  18,   0, 183,
   2,   6,   0,  18,   0, 186,   2,   6,   0,  18,   0, 189,   2,   6,   0,  18,
   0, 192,   2,   6,   0,  18,   0, 195,   2,   6,   0,  18,   0, 198,   2,   6,
   0,  18,   0, 201,   2,   6,   0,  18,   0, 204,   2,   6,   0,  18,   0, 207,
   2,   6,   0,  18,   0, 210,   2,   6,   0,  18,   0, 213,   2,   6,   0,  18,
   0, 216,   2,   6,   0,  18,   0, 219,   2,   6,   0,  18,   0, 222,   2,   6,
   0,  18,   0, 225,   2,   6,   0,  18,   0, 227,   2,   1,  33, 156,   1, 228,
   2,   1,  34, 155,   1, 229,   2,   1,  35, 154,   1, 230,   2,   1,  36, 153,
   1, 231,   2,   1,  37, 152,   1, 232,   2,   1,  38, 151,   1, 233,   2,   1,
  39, 150,   1, 234,   2,   1,  40, 149,   1, 203,   1,   4, 136,   3,  68,   0,
  13,   1,  27, 138,   3,   1,  41, 198,   1, 139,   3,   1,  42, 197,   1, 140,
   3,   1,  43, 196,   1, 132,   2,  53, 195,   3,  68,   0,  14,   1,  28, 197,
   3,   6,   0,  18,   0, 200,   3,   6,   0,  18,   0, 203,   3,   6,   0,  18,
   0, 206,   3,   6,   0,  18,   0, 209,   3,   6,   0,  18,   0, 212,   3,   6,
   0,  18,   0, 215,   3,   6,   0,  18,   0, 218,   3,   6,   0,  18,   0, 221,
   3,   6,   0,  18,   0, 224,   3,   6,   0,  18,   0, 227,   3,   6,   0,  18,
   0, 230,   3,   6,   0,  18,   0, 233,   3,   6,   0,  18,   0, 236,   3,   6,
   0,  18,   0, 239,   3,   6,   0,  18,   0, 242,   3,   6,   0,  18,   0, 245,
   3,   6,   0,  18,   0, 248,   3,   6,   0,  18,   0, 251,   3,   6,   0,  18,
   0, 254,   3,   6,   0,  18,   0, 129,   4,   6,   0,  18,   0, 132,   4,   6,
   0,  18,   0, 135,   4,   6,   0,  18,   0, 138,   4,   6,   0,  18,   0, 141,
   4,   6,   0,  18,   0, 144,   4,   6,   0,  18,   0, 147,   4,   6,   0,  18,
   0, 150,   4,   6,   0,  18,   0, 153,   4,   6,   0,  18,   0, 156,   4,   6,
   0,  18,   0, 159,   4,   6,   0,  18,   0, 162,   4,   6,   0,  18,   0, 165,
   4,   6,   0,  18,   0, 168,   4,   6,   0,  18,   0, 171,   4,   6,   0,  18,
   0, 174,   4,   6,   0,  18,   0, 177,   4,   6,   0,  18,   0, 180,   4,   6,
   0,  18,   0, 183,   4,   6,   0,  18,   0, 186,   4,   6,   0,  18,   0, 189,
   4,   6,   0,  18,   0, 192,   4,   6,   0,  18,   0, 195,   4,   6,   0,  18,
   0, 198,   4,   6,   0,  18,   0, 201,   4,   6,   0,  18,   0, 204,   4,   6,
   0,  18,   0, 207,   4,   6,   0,  18,   0, 210,   4,   6,   0,  18,   0, 213,
   4,   6,   0,  18,   0, 216,   4,   6,   0,  18,   0, 219,   4,   2,  44, 205,
   1, 219,   4,   3,  45, 204,   1, 141,   2,   5, 232,   4,  68,   1,  15,   1,
  29, 233,   4,   6,   2,  18,   0, 234,   4,   6,   3,  18,   0, 235,   4,   1,
  46, 134,   2, 236,   4,   1,  47, 133,   2, 183,   2,  38, 150,   5,  68,   0,
  16,   1,  30, 152,   5,   6,   0,  18,   0, 155,   5,   6,   0,  18,   0, 158,
   5,   6,   0,  18,   0, 161,   5,   6,   0,  18,   0, 164,   5,   6,   0,  18,
   0, 167,   5,   6,   0,  18,   0, 170,   5,   6,   0,  18,   0, 173,   5,   6,
   0,  18,   0, 176,   5,   6,   0,  18,   0, 179,   5,   6,   0,  18,   0, 182,
   5,   6,   0,  18,   0, 185,   5,   6,   0,  18,   0, 188,   5,   6,   0,  18,
   0, 191,   5,   6,   0,  18,   0, 194,   5,   6,   0,  18,   0, 197,   5,   6,
   0,  18,   0, 200,   5,   6,   0,  18,   0, 203,   5,   6,   0,  18,   0, 206,
   5,   6,   0,  18,   0, 209,   5,   6,   0,  18,   0, 212,   5,   6,   0,  18,
   0, 215,   5,   6,   0,  18,   0, 218,   5,   6,   0,  18,   0, 221,   5,   6,
   0,  18,   0, 224,   5,   6,   0,  18,   0, 227,   5,   6,   0,  18,   0, 230,
   5,   6,   0,  18,   0, 233,   5,   6,   0,  18,   0, 236,   5,   6,   0,  18,
   0, 239,   5,   6,   0,  18,   0, 242,   5,   6,   0,  18,   0, 245,   5,   6,
   0,  18,   0, 248,   5,   6,   0,  18,   0, 251,   5,   6,   0,  18,   0, 254,
   5,   6,   0,  18,   0, 129,   6,   1,  48, 143,   2, 130,   6,   1,  49, 142,
   2, 201,   2,   1, 153,   6,  68,   0,  17,   1,  31, 236,   2,   1, 143,   7,
  68,   1,  18,   1,  32, 156,   3,   2, 237,   7,   6,   1,   0,  96,   8, 238,
   7,  68,   2,  19,   1,  33, 159,   3,   1, 245,   7,   4,   1,  20, 168,   3,
   1, 254,   7,  68,   1,  21,   1,  34,  35,   9,  60,  68,   0,   0,   1,   0,
  61,  68,   0,   1,   1,   1,  62,   1,   1,   5,  63,   4,   0,   2,  64,   1,
   2,   4,  65,   1,   3,   3,  25,   1,   4,   2,  29,   1,   5,   1,  34,   1,
   6,   0, 160,   1,   0,   1,   1,   1,   2,  10, 208,  48,  93,   1, 102,   1,
  70,   2,   0,  72,   0,   0,   1,   1,   1,   1,   2,  10, 208,  48,  93,   1,
 102,   1,  70,   4,   0,  72,   0,   0,   2,   2,   2,   1,   2,  12, 208,  48,
  93,   1, 102,   1, 209,  70,   6,   1,  41,  71,   0,   0,   3,   2,   2,   1,
   2,  12, 208,  48,  93,   1, 102,   1, 209,  70,   6,   1,  41,  71,   0,   0,
   4,   2,   2,   1,   2,  13, 208,  48,  93,   8, 102,   8, 102,   9, 209,  70,
  10,   1,  72,   0,   0,   5,   1,   1,   1,   2,  11, 208,  48,  93,  12, 102,
  12,  70,  13,   0,  41,  71,   0,   0,   6,   2,   1,   3,   4,  21, 208,  48,
  94,  14,  93,  15,  70,  15,   0, 104,  14,  94,  16,  93,  17,  70,  17,   0,
 104,  16,  71,   0,   0,  23,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,
  71,   0,   0,  24,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,  28,   2,
   3,   3,   4,  11, 208,  48,  93,  42, 102,  42, 209,  70,  43,   1,  72,   0,
   0,  29,   2,   3,   3,   4,  10, 208,  48, 210, 209,  70,  45,   1,  41,  38,
  72,   0,   0,  30,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,
   0,  31,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,  32,   1,   1,   3,
   4,   5, 208,  48,  44,  48,  72,   0,   0,  33,   1,   1,   3,   4,  10, 208,
  48,  93,  51, 102,  51,  70,  52,   0,  72,   0,   0,  34,   1,   1,   4,   5,
   6, 208,  48, 208,  73,   0,  71,   0,   0,  35,   2,   1,   1,   3,  51, 208,
  48,  93,  55,  93,  41, 102,  41,  48,  93,  56, 102,  56,  88,   0,  29, 104,
  40,  93,  57,  93,  41, 102,  41,  48,  93,  56, 102,  56,  88,   1,  29, 104,
  50,  93,  58,  93,  41, 102,  41,  48,  93,  59, 102,  59,  88,   2,  29, 104,
  54,  71,   0,   0,  36,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,  40,
   2,   2,   4,   5,  12, 208,  48, 208,  73,   0, 208, 209,  70,  67,   1,  41,
  71,   0,   0,  43,   3,   2,   4,   5,  15, 208,  48, 208,  93,  68, 102,  68,
 209,  70,  69,   1,  70,  70,   1,  72,   0,   0,  46,   2,   1,   1,   3,  19,
 208,  48,  93,  78,  93,  41, 102,  41,  48,  93,  79, 102,  79,  88,   3,  29,
 104,  66,  71,   0,   0,  47,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,
  75,   1,   1,   4,   5,   8, 208,  48, 208,  70,  81,   0,  41,  71,   0,   0,
  77,   1,   1,   4,   5,   8, 208,  48, 208,  70,  82,   0,  41,  71,   0,   0,
  79,   1,   1,   4,   5,   7, 208,  48, 208,  70,  83,   0,  72,   0,   0,  85,
   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,  86,   2,   1,
   1,   3,  19, 208,  48,  93, 118,  93,  41, 102,  41,  48,  93, 119, 102, 119,
  88,   4,  29, 104,  44,  71,   0,   0,  92,   4,   3,   1,   2,  12, 208,  48,
  93, 123, 209, 210,  36,   1,  70, 123,   3,  72,   0,   0,  93,   4,   3,   1,
   2,  12, 208,  48,  93, 123, 209, 210,  36,   2,  70, 123,   3,  72,   0,   0,
  94,   4,   3,   1,   2,  12, 208,  48,  93, 123, 209, 210,  36,   0,  70, 123,
   3,  72,   0,   0, 100,   3,   3,   3,   6,  45,  87,  42, 213,  48, 101,   0,
  38, 118, 109,   1,  93, 124,  76, 124,   0,  41,  16,  20,   0,   0, 209,  48,
  90,   0,  42, 214,  42,  48,  43, 109,   1, 101,   0,  39, 118, 109,   1,  29,
   8,   2, 101,   0, 108,   1,  72,   1,  10,  16,  20,   0, 125,   1, 126,   0,
   1,  20,   0, 101,   2,   3,   2,   4,  55, 208,  48,  87,  42, 214,  48, 101,
   1,  33, 130, 109,   2, 101,   1, 209, 109,   1, 101,   1, 108,   1,  32,  19,
  21,   0,   0, 101,   1,  64, 100, 130, 109,   2,  93, 127, 101,   1, 108,   2,
  70, 127,   1,  41,  16,   7,   0,   0,  93, 127,  32,  70, 127,   1,  41,  71,
   0,   2, 128,   1,   0,   1, 121,   0, 129,   1,   0,   2,   0,   0, 107,   1,
   1,   3,   4,   3, 208,  48,  71,   0,   0, 108,   3,   1,   4,   5,  46, 208,
  48, 208, 102, 130,   1,  44, 121, 160, 208, 102, 131,   1, 118,  18,  23,   0,
   0,  44, 123, 208, 102, 131,   1, 160,  44, 124, 160, 208, 102, 132,   1, 160,
  44, 126, 160, 130,  16,   3,   0,   0,  44,   3, 130, 160,  72,   0,   0, 109,
   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 110,   1,   1,
   3,   4,   3, 208,  48,  71,   0,   0, 111,   1,   1,   4,   5,   6, 208,  48,
 208,  73,   0,  71,   0,   0, 112,   1,   1,   4,   5,   3, 208,  48,  71,   0,
   0, 115,   1,   1,   5,   6,   6, 208,  48, 208,  73,   0,  71,   0,   0, 116,
   1,   1,   4,   5,   3, 208,  48,  71,   0,   0, 117,   1,   1,   5,   6,   6,
 208,  48, 208,  73,   0,  71,   0,   0, 118,   2,   1,   1,   4,  89, 208,  48,
 101,   0,  93,  41, 102,  41,  48,  93, 147,   1, 102, 147,   1,  88,   5,  29,
 104, 137,   1, 101,   0,  93,  41, 102,  41,  48,  93, 147,   1, 102, 147,   1,
  88,   6,  29, 104, 140,   1, 101,   0,  93,  41, 102,  41,  48,  93, 140,   1,
 102, 140,   1,  48, 100, 108,   2,  88,   7,  29,  29, 104, 145,   1, 101,   0,
  93,  41, 102,  41,  48,  93, 140,   1, 102, 140,   1,  48, 100, 108,   2,  88,
   8,  29,  29, 104, 146,   1,  71,   0,   0, 119,   2,   1,   3,   4,  59, 208,
  48,  94, 171,   1,  36,   0, 104, 171,   1,  94, 172,   1,  36,   1, 104, 172,
   1,  94, 173,   1,  36,   2, 104, 173,   1,  94, 174,   1,  36,   3, 104, 174,
   1,  94, 175,   1,  36,   4, 104, 175,   1,  94, 176,   1,  36,   1, 104, 176,
   1,  94, 177,   1,  36,   2, 104, 177,   1,  71,   0,   0, 124,   1,   1,   4,
   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 125,   2,   1,   1,   3,  22,
 208,  48, 101,   0,  93,  41, 102,  41,  48,  93, 190,   1, 102, 190,   1,  88,
   9,  29, 104, 189,   1,  71,   0,   0, 126,   1,   1,   3,   4,   3, 208,  48,
  71,   0,   0, 128,   1,   2,   2,   4,   5,  13, 208,  48, 208,  73,   0, 208,
 209,  70, 192,   1,   1,  41,  71,   0,   0, 129,   1,   2,   1,   1,   3,  22,
 208,  48, 101,   0,  93,  41, 102,  41,  48,  93, 195,   1, 102, 195,   1,  88,
  10,  29, 104, 194,   1,  71,   0,   0, 130,   1,   2,   2,   1,   2,  11, 208,
  48, 100, 108,   1, 209,  70, 197,   1,   1,  72,   0,   0, 131,   1,   2,   2,
   1,   2,  11, 208,  48, 100, 108,   1, 209,  70, 198,   1,   1,  72,   0,   0,
 132,   1,   2,   2,   1,   2,  11, 208,  48, 100, 108,   1, 209,  70, 199,   1,
   1,  72,   0,   0, 133,   1,   4,   5,   1,   2,  29, 208,  48,  36,   0, 115,
  99,   4, 211,  18,   5,   0,   0,  36,   1, 115,  99,   4, 100, 108,   1, 209,
 210,  98,   4,  70, 200,   1,   3,  72,   0,   0, 134,   1,   2,   2,   1,   2,
  11, 208,  48, 100, 108,   1, 209,  70, 201,   1,   1,  72,   0,   0, 135,   1,
   2,   2,   1,   2,  12, 208,  48, 100, 108,   1, 209,  70, 202,   1,   1,  41,
  71,   0,   0, 136,   1,   1,   1,   1,   2,  11, 208,  48, 100, 108,   1,  70,
 203,   1,   0,  41,  71,   0,   0, 137,   1,   1,   1,   3,   4,   3, 208,  48,
  71,   0,   0, 147,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,
   0,   0, 148,   1,   2,   1,   1,   3,  44, 208,  48, 101,   0,  93,  41, 102,
  41,  48,  93, 213,   1, 102, 213,   1,  88,  11,  29, 104, 212,   1, 101,   0,
 100, 108,   1, 102, 214,   1, 104, 215,   1, 101,   0, 100, 108,   1, 102, 216,
   1, 104, 217,   1,  71,   0,   0, 149,   1,   2,   2,   1,   2,  15, 208,  48,
  93, 228,   1, 102, 228,   1, 209,  70, 229,   1,   1,  41,  71,   0,   0, 150,
   1,   3,   3,   1,   2,  15, 208,  48,  93, 228,   1, 102, 228,   1, 209, 210,
  70, 230,   1,   2,  72,   0,   0, 151,   1,   2,   2,   1,   2,  14, 208,  48,
  93, 228,   1, 102, 228,   1, 209,  70, 231,   1,   1,  72,   0,   0, 152,   1,
   2,   2,   1,   2,  14, 208,  48,  93, 228,   1, 102, 228,   1, 209,  70, 232,
   1,   1,  72,   0,   0, 153,   1,   1,   1,   1,   2,  13, 208,  48,  93, 228,
   1, 102, 228,   1,  70, 233,   1,   0,  72,   0,   0, 154,   1,   1,   1,   1,
   2,  13, 208,  48,  93, 228,   1, 102, 228,   1,  70, 234,   1,   0,  72,   0,
   0, 155,   1,   1,   1,   1,   2,  13, 208,  48,  93, 228,   1, 102, 228,   1,
  70, 235,   1,   0,  72,   0,   0, 156,   1,   3,   3,   1,   2,  15, 208,  48,
  93, 228,   1, 102, 228,   1, 209, 210,  70, 236,   1,   2,  72,   0,   0, 157,
   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 193,   1,   1,   1,   4,
   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 194,   1,   2,   1,   1,   3,
 172,   3, 208,  48,  93, 145,   2,  93,  41, 102,  41,  48,  93, 146,   2, 102,
 146,   2,  88,  12,  29, 104, 144,   2,  93, 147,   2,  93, 228,   1, 102, 228,
   1, 102, 148,   2, 104, 149,   2,  93, 150,   2,  93, 228,   1, 102, 228,   1,
 102, 151,   2, 104, 152,   2,  93, 153,   2,  93, 228,   1, 102, 228,   1, 102,
 154,   2, 104, 155,   2,  93, 156,   2,  93, 228,   1, 102, 228,   1, 102, 157,
   2, 104, 158,   2,  93, 159,   2,  93, 228,   1, 102, 228,   1, 102, 160,   2,
 104, 161,   2,  93, 162,   2,  93, 228,   1, 102, 228,   1, 102, 163,   2, 104,
 164,   2,  93, 165,   2,  93, 228,   1, 102, 228,   1, 102, 166,   2, 104, 167,
   2,  93, 168,   2,  93, 228,   1, 102, 228,   1, 102, 169,   2, 104, 170,   2,
  93, 171,   2,  93, 228,   1, 102, 228,   1, 102, 172,   2, 104, 173,   2,  93,
 174,   2,  93, 228,   1, 102, 228,   1, 102, 175,   2, 104, 176,   2,  93, 177,
   2,  93, 228,   1, 102, 228,   1, 102, 178,   2, 104, 179,   2,  93, 180,   2,
  93, 228,   1, 102, 228,   1, 102, 181,   2, 104, 182,   2,  93, 183,   2,  93,
 228,   1, 102, 228,   1, 102, 184,   2, 104, 185,   2,  93, 186,   2,  93, 228,
   1, 102, 228,   1, 102, 187,   2, 104, 188,   2,  93, 189,   2,  93, 228,   1,
 102, 228,   1, 102, 190,   2, 104, 191,   2,  93, 192,   2,  93, 228,   1, 102,
 228,   1, 102, 193,   2, 104, 194,   2,  93, 195,   2,  93, 228,   1, 102, 228,
   1, 102, 196,   2, 104, 197,   2,  93, 198,   2,  93, 228,   1, 102, 228,   1,
 102, 199,   2, 104, 200,   2,  93, 201,   2,  93, 228,   1, 102, 228,   1, 102,
 202,   2, 104, 203,   2,  93, 204,   2,  93, 228,   1, 102, 228,   1, 102, 205,
   2, 104, 206,   2,  93, 207,   2,  93, 228,   1, 102, 228,   1, 102, 208,   2,
 104, 209,   2,  93, 210,   2,  93, 228,   1, 102, 228,   1, 102, 211,   2, 104,
 212,   2,  93, 213,   2,  93, 228,   1, 102, 228,   1, 102, 214,   2, 104, 215,
   2,  93, 216,   2,  93, 228,   1, 102, 228,   1, 102, 217,   2, 104, 218,   2,
  93, 219,   2,  93, 228,   1, 102, 228,   1, 102, 220,   2, 104, 221,   2,  93,
 222,   2,  93, 228,   1, 102, 228,   1, 102, 223,   2, 104, 224,   2,  93, 225,
   2,  93, 228,   1, 102, 228,   1, 102, 157,   2, 104, 226,   2,  71,   0,   0,
 195,   1,   2,   3,   2,   2, 220,   1,  16,  44,   0,   0,   9,  44, 131,   2,
  72,   9,  44, 132,   2,  72,   9,  44, 133,   2,  72,   9,  44, 134,   2,  72,
   9,  44, 135,   2,  72,   9,  44, 136,   2,  72,   9,  44, 137,   2,  72,   9,
  44, 138,   2,  72,  16, 172,   0,   0, 209,  93, 235,   2, 102, 235,   2, 168,
 214,  93, 236,   2, 102, 236,   2, 210,  26,   6,   0,   0,  37,   0,  16, 115,
   0,   0,  93, 237,   2, 102, 237,   2, 210,  26,   6,   0,   0,  37,   1,  16,
  98,   0,   0,  93, 238,   2, 102, 238,   2, 210,  26,   6,   0,   0,  37,   2,
  16,  81,   0,   0,  93, 239,   2, 102, 239,   2, 210,  26,   6,   0,   0,  37,
   3,  16,  64,   0,   0,  93, 240,   2, 102, 240,   2, 210,  26,   6,   0,   0,
  37,   4,  16,  47,   0,   0,  93, 241,   2, 102, 241,   2, 210,  26,   6,   0,
   0,  37,   5,  16,  30,   0,   0,  93, 242,   2, 102, 242,   2, 210,  26,   6,
   0,   0,  37,   6,  16,  13,   0,   0,  39,  18,   6,   0,   0,  37,   7,  16,
   2,   0,   0,  37,   7,   8,   2,  27, 104, 255, 255,   7,  69, 255, 255,  74,
 255, 255,  79, 255, 255,  84, 255, 255,  89, 255, 255,  94, 255, 255,  99, 255,
 255, 104, 255, 255,   0,   0, 196,   1,   5,   3,   2,   4, 143,   3, 208,  48,
  87,  42, 214,  48, 101,   1, 209, 109,   1, 101,   1,  93, 243,   2,  36,  10,
  74, 243,   2,   1, 128,  19, 109,   2, 101,   1,  64, 195,   1, 128, 121, 109,
   3, 101,   1, 108,   2,  36,   0, 101,   1, 108,   3, 100, 101,   1, 108,   1,
  65,   1,  97, 244,   2, 101,   1, 108,   2,  36,   1, 101,   1, 108,   1,  93,
 245,   2, 102, 245,   2, 168, 118,  18,   8,   0,   0,  44, 141,   2, 130,  16,
   4,   0,   0,  44, 131,   2, 130,  97, 244,   2, 101,   1, 108,   2,  36,   2,
 101,   1, 108,   1,  93, 246,   2, 102, 246,   2, 168, 118,  18,   8,   0,   0,
  44, 142,   2, 130,  16,   4,   0,   0,  44, 131,   2, 130,  97, 244,   2, 101,
   1, 108,   2,  36,   3, 101,   1, 108,   1,  93, 247,   2, 102, 247,   2, 168,
 118,  18,   8,   0,   0,  44, 143,   2, 130,  16,   4,   0,   0,  44, 131,   2,
 130,  97, 244,   2, 101,   1, 108,   2,  36,   4, 101,   1, 108,   1,  93, 248,
   2, 102, 248,   2, 168, 118,  18,   8,   0,   0,  44, 141,   2, 130,  16,   4,
   0,   0,  44, 131,   2, 130,  97, 244,   2, 101,   1, 108,   2,  36,   5, 101,
   1, 108,   1,  93, 249,   2, 102, 249,   2, 168, 118,  18,   8,   0,   0,  44,
 142,   2, 130,  16,   4,   0,   0,  44, 131,   2, 130,  97, 244,   2, 101,   1,
 108,   2,  36,   6, 101,   1, 108,   1,  93, 250,   2, 102, 250,   2, 168, 118,
  18,   8,   0,   0,  44, 143,   2, 130,  16,   4,   0,   0,  44, 131,   2, 130,
  97, 244,   2, 101,   1, 108,   2,  36,   7, 101,   1, 108,   1,  93, 251,   2,
 102, 251,   2, 168, 118,  18,   8,   0,   0,  44, 141,   2, 130,  16,   4,   0,
   0,  44, 131,   2, 130,  97, 244,   2, 101,   1, 108,   2,  36,   8, 101,   1,
 108,   1,  93, 252,   2, 102, 252,   2, 168, 118,  18,   8,   0,   0,  44, 142,
   2, 130,  16,   4,   0,   0,  44, 131,   2, 130,  97, 244,   2, 101,   1, 108,
   2,  36,   9, 101,   1, 108,   1,  93, 253,   2, 102, 253,   2, 168, 118,  18,
   8,   0,   0,  44, 143,   2, 130,  16,   4,   0,   0,  44, 131,   2, 130,  97,
 244,   2, 101,   1, 108,   2,  44,   3,  70, 254,   2,   1,  72,   0,   3, 255,
   2,   0,   1,  18,   0, 128,   3,   0,   2,  19,   0, 129,   3,   0,   3, 121,
   0, 197,   1,   2,   2,   1,   2,  14, 208,  48,  93, 130,   3, 102, 130,   3,
 209,  70, 131,   3,   1,  72,   0,   0, 198,   1,   2,   2,   1,   2,  14, 208,
  48,  93, 130,   3, 102, 130,   3, 209,  70, 132,   3,   1,  72,   0,   0, 199,
   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 202,   1,   1,   1,   4,
   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 203,   1,   2,   1,   1,   3,
  23, 208,  48,  93, 136,   3,  93,  41, 102,  41,  48,  93, 137,   3, 102, 137,
   3,  88,  13,  29, 104, 135,   3,  71,   0,   0, 204,   1,   2,   2,   1,   2,
  13, 208,  48,  93, 141,   3, 102, 141,   3, 209,  97, 142,   3,  71,   0,   0,
 205,   1,   1,   1,   1,   2,  12, 208,  48,  93, 141,   3, 102, 141,   3, 102,
 142,   3,  72,   0,   0, 206,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,
   0, 131,   2,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,
 132,   2,   2,   1,   1,   3, 133,   6, 208,  48,  93, 195,   3,  93,  41, 102,
  41,  48,  93, 196,   3, 102, 196,   3,  88,  14,  29, 104, 194,   3,  93, 197,
   3,  93, 141,   3, 102, 141,   3, 102, 198,   3, 104, 199,   3,  93, 200,   3,
  93, 141,   3, 102, 141,   3, 102, 201,   3, 104, 202,   3,  93, 203,   3,  93,
 141,   3, 102, 141,   3, 102, 204,   3, 104, 205,   3,  93, 206,   3,  93, 141,
   3, 102, 141,   3, 102, 207,   3, 104, 208,   3,  93, 209,   3,  93, 141,   3,
 102, 141,   3, 102, 210,   3, 104, 211,   3,  93, 212,   3,  93, 141,   3, 102,
 141,   3, 102, 213,   3, 104, 214,   3,  93, 215,   3,  93, 141,   3, 102, 141,
   3, 102, 216,   3, 104, 217,   3,  93, 218,   3,  93, 141,   3, 102, 141,   3,
 102, 219,   3, 104, 220,   3,  93, 221,   3,  93, 141,   3, 102, 141,   3, 102,
 222,   3, 104, 223,   3,  93, 224,   3,  93, 141,   3, 102, 141,   3, 102, 225,
   3, 104, 226,   3,  93, 227,   3,  93, 141,   3, 102, 141,   3, 102, 228,   3,
 104, 229,   3,  93, 230,   3,  93, 141,   3, 102, 141,   3, 102, 231,   3, 104,
 232,   3,  93, 233,   3,  93, 141,   3, 102, 141,   3, 102, 234,   3, 104, 235,
   3,  93, 236,   3,  93, 141,   3, 102, 141,   3, 102, 237,   3, 104, 238,   3,
  93, 239,   3,  93, 141,   3, 102, 141,   3, 102, 240,   3, 104, 241,   3,  93,
 242,   3,  93, 141,   3, 102, 141,   3, 102, 243,   3, 104, 244,   3,  93, 245,
   3,  93, 141,   3, 102, 141,   3, 102, 246,   3, 104, 247,   3,  93, 248,   3,
  93, 141,   3, 102, 141,   3, 102, 249,   3, 104, 250,   3,  93, 251,   3,  93,
 141,   3, 102, 141,   3, 102, 252,   3, 104, 253,   3,  93, 254,   3,  93, 141,
   3, 102, 141,   3, 102, 255,   3, 104, 128,   4,  93, 129,   4,  93, 141,   3,
 102, 141,   3, 102, 130,   4, 104, 131,   4,  93, 132,   4,  93, 141,   3, 102,
 141,   3, 102, 133,   4, 104, 134,   4,  93, 135,   4,  93, 141,   3, 102, 141,
   3, 102, 136,   4, 104, 137,   4,  93, 138,   4,  93, 141,   3, 102, 141,   3,
 102, 139,   4, 104, 140,   4,  93, 141,   4,  93, 141,   3, 102, 141,   3, 102,
 142,   4, 104, 143,   4,  93, 144,   4,  93, 141,   3, 102, 141,   3, 102, 145,
   4, 104, 146,   4,  93, 147,   4,  93, 141,   3, 102, 141,   3, 102, 148,   4,
 104, 149,   4,  93, 150,   4,  93, 141,   3, 102, 141,   3, 102, 151,   4, 104,
 152,   4,  93, 153,   4,  93, 141,   3, 102, 141,   3, 102, 154,   4, 104, 155,
   4,  93, 156,   4,  93, 141,   3, 102, 141,   3, 102, 157,   4, 104, 158,   4,
  93, 159,   4,  93, 141,   3, 102, 141,   3, 102, 160,   4, 104, 161,   4,  93,
 162,   4,  93, 141,   3, 102, 141,   3, 102, 163,   4, 104, 164,   4,  93, 165,
   4,  93, 141,   3, 102, 141,   3, 102, 166,   4, 104, 167,   4,  93, 168,   4,
  93, 141,   3, 102, 141,   3, 102, 169,   4, 104, 170,   4,  93, 171,   4,  93,
 141,   3, 102, 141,   3, 102, 172,   4, 104, 173,   4,  93, 174,   4,  93, 141,
   3, 102, 141,   3, 102, 175,   4, 104, 176,   4,  93, 177,   4,  93, 141,   3,
 102, 141,   3, 102, 178,   4, 104, 179,   4,  93, 180,   4,  93, 141,   3, 102,
 141,   3, 102, 181,   4, 104, 182,   4,  93, 183,   4,  93, 141,   3, 102, 141,
   3, 102, 184,   4, 104, 185,   4,  93, 186,   4,  93, 141,   3, 102, 141,   3,
 102, 187,   4, 104, 188,   4,  93, 189,   4,  93, 141,   3, 102, 141,   3, 102,
 190,   4, 104, 191,   4,  93, 192,   4,  93, 141,   3, 102, 141,   3, 102, 193,
   4, 104, 194,   4,  93, 195,   4,  93, 141,   3, 102, 141,   3, 102, 196,   4,
 104, 197,   4,  93, 198,   4,  93, 141,   3, 102, 141,   3, 102, 199,   4, 104,
 200,   4,  93, 201,   4,  93, 141,   3, 102, 141,   3, 102, 202,   4, 104, 203,
   4,  93, 204,   4,  93, 141,   3, 102, 141,   3, 102, 205,   4, 104, 206,   4,
  93, 207,   4,  93, 141,   3, 102, 141,   3, 102, 208,   4, 104, 209,   4,  93,
 210,   4,  93, 141,   3, 102, 141,   3, 102, 211,   4, 104, 212,   4,  93, 213,
   4,  93, 141,   3, 102, 141,   3, 102, 214,   4, 104, 215,   4,  93, 216,   4,
  93, 141,   3, 102, 141,   3, 102, 217,   4, 104, 218,   4,  71,   0,   0, 133,
   2,   3,   3,   1,   2,  12, 208,  48, 100, 108,   1, 209, 210,  70, 220,   4,
   2,  72,   0,   0, 134,   2,   2,   2,   1,   2,  11, 208,  48, 100, 108,   1,
 209,  70, 221,   4,   1,  72,   0,   0, 135,   2,   1,   1,   3,   4,   3, 208,
  48,  71,   0,   0, 140,   2,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,
  71,   0,   0, 141,   2,   2,   1,   1,   3,  44, 208,  48, 101,   0,  93,  41,
 102,  41,  48,  93, 227,   4, 102, 227,   4,  88,  15,  29, 104, 226,   4, 101,
   0, 100, 108,   1, 102, 228,   4, 104, 229,   4, 101,   0, 100, 108,   1, 102,
 230,   4, 104, 231,   4,  71,   0,   0, 142,   2,   3,   3,   1,   2,  15, 208,
  48,  93, 237,   4, 102, 237,   4, 209, 210,  70, 238,   4,   2,  72,   0,   0,
 143,   2,   3,   3,   1,   2,  15, 208,  48,  93, 237,   4, 102, 237,   4, 209,
 210,  70, 239,   4,   2,  72,   0,   0, 144,   2,   1,   1,   3,   4,   3, 208,
  48,  71,   0,   0, 182,   2,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,
  71,   0,   0, 183,   2,   2,   1,   1,   3, 164,   4, 208,  48,  93, 150,   5,
  93,  41, 102,  41,  48,  93, 151,   5, 102, 151,   5,  88,  16,  29, 104, 149,
   5,  93, 152,   5,  93, 237,   4, 102, 237,   4, 102, 153,   5, 104, 154,   5,
  93, 155,   5,  93, 237,   4, 102, 237,   4, 102, 156,   5, 104, 157,   5,  93,
 158,   5,  93, 237,   4, 102, 237,   4, 102, 159,   5, 104, 160,   5,  93, 161,
   5,  93, 237,   4, 102, 237,   4, 102, 162,   5, 104, 163,   5,  93, 164,   5,
  93, 237,   4, 102, 237,   4, 102, 165,   5, 104, 166,   5,  93, 167,   5,  93,
 237,   4, 102, 237,   4, 102, 168,   5, 104, 169,   5,  93, 170,   5,  93, 237,
   4, 102, 237,   4, 102, 171,   5, 104, 172,   5,  93, 173,   5,  93, 237,   4,
 102, 237,   4, 102, 174,   5, 104, 175,   5,  93, 176,   5,  93, 237,   4, 102,
 237,   4, 102, 177,   5, 104, 178,   5,  93, 179,   5,  93, 237,   4, 102, 237,
   4, 102, 180,   5, 104, 181,   5,  93, 182,   5,  93, 237,   4, 102, 237,   4,
 102, 183,   5, 104, 184,   5,  93, 185,   5,  93, 237,   4, 102, 237,   4, 102,
 186,   5, 104, 187,   5,  93, 188,   5,  93, 237,   4, 102, 237,   4, 102, 189,
   5, 104, 190,   5,  93, 191,   5,  93, 237,   4, 102, 237,   4, 102, 192,   5,
 104, 193,   5,  93, 194,   5,  93, 237,   4, 102, 237,   4, 102, 195,   5, 104,
 196,   5,  93, 197,   5,  93, 237,   4, 102, 237,   4, 102, 198,   5, 104, 199,
   5,  93, 200,   5,  93, 237,   4, 102, 237,   4, 102, 201,   5, 104, 202,   5,
  93, 203,   5,  93, 237,   4, 102, 237,   4, 102, 204,   5, 104, 205,   5,  93,
 206,   5,  93, 237,   4, 102, 237,   4, 102, 207,   5, 104, 208,   5,  93, 209,
   5,  93, 237,   4, 102, 237,   4, 102, 210,   5, 104, 211,   5,  93, 212,   5,
  93, 237,   4, 102, 237,   4, 102, 213,   5, 104, 214,   5,  93, 215,   5,  93,
 237,   4, 102, 237,   4, 102, 216,   5, 104, 217,   5,  93, 218,   5,  93, 237,
   4, 102, 237,   4, 102, 219,   5, 104, 220,   5,  93, 221,   5,  93, 237,   4,
 102, 237,   4, 102, 222,   5, 104, 223,   5,  93, 224,   5,  93, 237,   4, 102,
 237,   4, 102, 225,   5, 104, 226,   5,  93, 227,   5,  93, 237,   4, 102, 237,
   4, 102, 228,   5, 104, 229,   5,  93, 230,   5,  93, 237,   4, 102, 237,   4,
 102, 231,   5, 104, 232,   5,  93, 233,   5,  93, 237,   4, 102, 237,   4, 102,
 234,   5, 104, 235,   5,  93, 236,   5,  93, 237,   4, 102, 237,   4, 102, 237,
   5, 104, 238,   5,  93, 239,   5,  93, 237,   4, 102, 237,   4, 102, 240,   5,
 104, 241,   5,  93, 242,   5,  93, 237,   4, 102, 237,   4, 102, 243,   5, 104,
 244,   5,  93, 245,   5,  93, 237,   4, 102, 237,   4, 102, 246,   5, 104, 247,
   5,  93, 248,   5,  93, 237,   4, 102, 237,   4, 102, 249,   5, 104, 250,   5,
  93, 251,   5,  93, 237,   4, 102, 237,   4, 102, 252,   5, 104, 253,   5,  93,
 254,   5,  93, 237,   4, 102, 237,   4, 102, 255,   5, 104, 128,   6,  71,   0,
   0, 184,   2,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 189,   2,   3,
   2,   3,   4,  20, 208,  48,  93, 131,   6, 209,  93, 132,   6, 102, 132,   6,
  70, 131,   6,   2,  36,   0, 171,  72,   0,   0, 190,   2,   3,   2,   3,   4,
  20, 208,  48,  93, 131,   6, 209,  93, 133,   6, 102, 133,   6,  70, 131,   6,
   2,  36,   0, 171,  72,   0,   0, 191,   2,   3,   2,   3,   4,  20, 208,  48,
  93, 131,   6, 209,  93, 134,   6, 102, 134,   6,  70, 131,   6,   2,  36,   0,
 171,  72,   0,   0, 197,   2,   2,   4,   3,   4,  52, 208,  48,  93, 135,   6,
 209,  70, 135,   6,   1, 117, 214,  93, 136,   6, 209,  70, 136,   6,   1, 117,
 215, 210,  36, 255, 171, 150, 118,  42, 118,  18,   7,   0,   0,  41, 211,  36,
 255, 171, 150, 118,  18,   4,   0,   0, 211, 210, 161,  72,  36, 255,  72,   0,
   0, 198,   2,   2,   2,   3,   4,  14, 208,  48,  93, 137,   6, 102, 137,   6,
 209,  70, 138,   6,   1,  72,   0,   0, 199,   2,   2,   3,   3,   4,  10, 208,
  48, 210, 209,  70, 139,   6,   1,  41,  71,   0,   0, 200,   2,   1,   1,   4,
   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 201,   2,   2,   1,   1,   3,
  23, 208,  48,  93, 151,   6,  93,  41, 102,  41,  48,  93, 152,   6, 102, 152,
   6,  88,  17,  29, 104, 150,   6,  71,   0,   0, 202,   2,   7,   1,   3,   4,
  55, 208,  48,  94, 154,   6,  44, 151,   3, 104, 154,   6,  94, 155,   6,  44,
   3, 104, 155,   6,  94, 156,   6,  44, 154,   3,  44, 155,   3,  44, 156,   3,
  44, 157,   3,  44, 158,   3,  44, 159,   3,  86,   6,  97, 156,   6,  94, 157,
   6,  44, 161,   3,  97, 157,   6,  71,   0,   0, 210,   2,   2,   2,   3,   4,
  92, 208,  48,  16,  22,   0,   0,   9,  44, 162,   3,  72,   9,  44, 163,   3,
  72,   9,  93, 158,   6, 102, 158,   6,  72,  16,  64,   0,   0,  93, 158,   6,
 102, 158,   6, 213,  44, 165,   3, 209,  26,   6,   0,   0,  37,   0,  16,  27,
   0,   0,  44, 166,   3, 209,  26,   6,   0,   0,  37,   1,  16,  13,   0,   0,
  39,  18,   6,   0,   0,  37,   2,  16,   2,   0,   0,  37,   2,   8,   1,  27,
 194, 255, 255,   2, 184, 255, 255, 189, 255, 255, 194, 255, 255,   0,   0, 211,
   2,   3,   5,   3,   4, 171,   2, 208,  48,  32, 133, 213,  32, 133, 214,  36,
   0, 116, 215,  32, 128,  19,  99,   4,  36,   0, 116, 215,  16,  49,   0,   0,
   9,  93, 159,   6, 102, 159,   6, 211, 102, 160,   6, 133, 213,  93, 161,   6,
 102, 161,   6, 209,  70, 162,   6,   1,  18,  17,   0,   0,  93, 161,   6, 102,
 161,   6, 209,  70, 163,   6,   1, 133, 214,  16,  18,   0,   0, 211, 145, 116,
 215, 211,  93, 159,   6, 102, 159,   6, 102, 164,   6,  21, 193, 255, 255, 210,
 118,  18, 160,   0,   0, 210,  44, 167,   3,  70, 165,   6,   1, 128,  19,  99,
   4,  94, 166,   6,  98,   4,  36,   0, 102, 160,   6,  44, 170,   3,  70, 165,
   6,   1,  36,   1, 102, 160,   6,  97, 166,   6,  94, 167,   6,  98,   4,  36,
   1, 102, 160,   6,  44, 170,   3,  70, 165,   6,   1,  36,   1, 102, 160,   6,
  97, 167,   6,  94, 168,   6,  98,   4,  36,   2, 102, 160,   6,  44, 170,   3,
  70, 165,   6,   1,  36,   1, 102, 160,   6,  97, 168,   6,  94, 169,   6,  98,
   4,  36,   3, 102, 160,   6,  44, 170,   3,  70, 165,   6,   1,  36,   1, 102,
 160,   6,  97, 169,   6,  93, 169,   6, 102, 169,   6,  44, 174,   3,  70, 170,
   6,   1,  36, 255,  14,  25,   0,   0,  94, 169,   6,  93, 169,   6, 102, 169,
   6,  44, 174,   3,  70, 165,   6,   1,  44,   3,  70, 171,   6,   1,  97, 169,
   6,  16,  44,   0,   0,  94, 166,   6,  93, 158,   6, 102, 158,   6,  97, 166,
   6,  94, 167,   6,  93, 172,   6, 102, 172,   6,  97, 167,   6,  94, 168,   6,
  93, 173,   6, 102, 173,   6,  97, 168,   6,  94, 169,   6,  44,   3,  97, 169,
   6,  71,   0,   0, 212,   2,   4,   6,   3,   4, 134,   1, 208,  48,  32, 133,
 214,  32, 133, 215,  36,   0,  99,   4,  36,   0,  99,   5,  93, 174,   6, 102,
 174,   6, 133, 213,  93, 161,   6, 102, 161,   6, 209,  70, 162,   6,   1,  18,
  13,   0,   0,  93, 161,   6, 102, 161,   6, 209,  70, 163,   6,   1, 133, 214,
 210, 118,  18,  63,   0,   0, 210,  44, 177,   3,  70, 165,   6,   1,  36,   1,
 102, 160,   6, 133, 215, 211,  44, 178,   3,  70, 170,   6,   1, 115,  99,   4,
 211,  44, 179,   3,  70, 170,   6,   1, 115,  99,   5,  94, 175,   6, 211,  98,
   4,  44, 178,   3, 102, 164,   6, 160,  98,   5,  70, 176,   6,   2,  97, 175,
   6,  16,  12,   0,   0,  94, 175,   6,  93, 177,   6, 102, 177,   6,  97, 175,
   6,  71,   0,   0, 213,   2,   2,   2,   3,   4, 147,   1, 208,  48,  16,  60,
   0,   0,   9,  44, 182,   3,  72,   9,  93, 178,   6,  70, 178,   6,   0,  72,
   9,  93, 166,   6, 102, 166,   6, 118,  18,   7,   0,   0,  93, 166,   6, 102,
 166,   6,  72,  93, 179,   6,  70, 179,   6,   0,  41,  93, 166,   6, 102, 166,
   6,  72,   9,  93, 158,   6, 102, 158,   6,  72,  16,  81,   0,   0,  93, 180,
   6, 102, 180,   6, 213,  44, 162,   3, 209,  26,   6,   0,   0,  37,   0,  16,
  41,   0,   0,  44, 163,   3, 209,  26,   6,   0,   0,  37,   1,  16,  27,   0,
   0,  44, 186,   3, 209,  26,   6,   0,   0,  37,   2,  16,  13,   0,   0,  39,
  18,   6,   0,   0,  37,   3,  16,   2,   0,   0,  37,   3,   8,   1,  27, 180,
 255, 255,   3, 132, 255, 255, 137, 255, 255, 146, 255, 255, 180, 255, 255,   0,
   0, 214,   2,   2,   1,   3,   4, 154,   2, 208,  48,  93, 181,   6, 102, 181,
   6,  44, 188,   3,  70, 170,   6,   1,  36, 255,  14,   4,   0,   0,  44, 188,
   3,  72,  93, 181,   6, 102, 181,   6,  44, 189,   3,  70, 170,   6,   1,  36,
 255,  14,   4,   0,   0,  44, 189,   3,  72,  93, 181,   6, 102, 181,   6,  44,
 190,   3,  70, 170,   6,   1,  36, 255,  14,   4,   0,   0,  44, 190,   3,  72,
  93, 181,   6, 102, 181,   6,  44, 191,   3,  70, 170,   6,   1,  36, 255,  14,
   4,   0,   0,  44, 191,   3,  72,  93, 181,   6, 102, 181,   6,  44, 192,   3,
  70, 170,   6,   1,  36, 255,  14,   4,   0,   0,  44, 192,   3,  72,  93, 181,
   6, 102, 181,   6,  44, 193,   3,  70, 170,   6,   1,  36, 255,  14,   4,   0,
   0,  44, 193,   3,  72,  93, 181,   6, 102, 181,   6,  44, 194,   3,  70, 170,
   6,   1,  36, 255,  14,   4,   0,   0,  44, 194,   3,  72,  93, 181,   6, 102,
 181,   6,  44, 195,   3,  70, 170,   6,   1,  36, 255,  14,   4,   0,   0,  44,
 195,   3,  72,  93, 181,   6, 102, 181,   6,  44, 196,   3,  70, 170,   6,   1,
  36, 255,  14,   4,   0,   0,  44, 196,   3,  72,  93, 181,   6, 102, 181,   6,
  44, 197,   3,  70, 170,   6,   1,  36, 255,  14,   4,   0,   0,  44, 197,   3,
  72,  93, 181,   6, 102, 181,   6,  44, 198,   3,  70, 170,   6,   1,  36, 255,
  14,   4,   0,   0,  44, 198,   3,  72,  93, 181,   6, 102, 181,   6,  44, 199,
   3,  70, 170,   6,   1,  36, 255,  14,   4,   0,   0,  44, 199,   3,  72,  44,
 200,   3,  72,   0,   0, 215,   2,   2,   2,   3,   4, 142,   1, 208,  48,  16,
  55,   0,   0,   9,  93, 182,   6,  70, 182,   6,   0,  72,   9,  93, 167,   6,
 102, 167,   6, 118,  18,   7,   0,   0,  93, 167,   6, 102, 167,   6,  72,  93,
 179,   6,  70, 179,   6,   0,  41,  93, 167,   6, 102, 167,   6,  72,   9,  93,
 181,   6, 102, 181,   6,  72,  16,  81,   0,   0,  93, 180,   6, 102, 180,   6,
 213,  44, 162,   3, 209,  26,   6,   0,   0,  37,   0,  16,  41,   0,   0,  44,
 163,   3, 209,  26,   6,   0,   0,  37,   1,  16,  27,   0,   0,  44, 186,   3,
 209,  26,   6,   0,   0,  37,   2,  16,  13,   0,   0,  39,  18,   6,   0,   0,
  37,   3,  16,   2,   0,   0,  37,   3,   8,   1,  27, 180, 255, 255,   3, 137,
 255, 255, 137, 255, 255, 146, 255, 255, 180, 255, 255,   0,   0, 216,   2,   2,
   2,   3,   4, 126, 208,  48,  16,  39,   0,   0,   9,  93, 183,   6,  70, 183,
   6,   0,  72,   9,  93, 184,   6,  70, 184,   6,   0,  72,   9,  93, 185,   6,
  70, 185,   6,   0,  72,   9,  93, 177,   6, 102, 177,   6,  72,  16,  81,   0,
   0,  93, 180,   6, 102, 180,   6, 213,  44, 162,   3, 209,  26,   6,   0,   0,
  37,   0,  16,  41,   0,   0,  44, 163,   3, 209,  26,   6,   0,   0,  37,   1,
  16,  27,   0,   0,  44, 186,   3, 209,  26,   6,   0,   0,  37,   2,  16,  13,
   0,   0,  39,  18,   6,   0,   0,  37,   3,  16,   2,   0,   0,  37,   3,   8,
   1,  27, 180, 255, 255,   3, 153, 255, 255, 162, 255, 255, 171, 255, 255, 180,
 255, 255,   0,   0, 217,   2,   3,   2,   3,   4, 178,   1, 208,  48,  32, 133,
 213,  93, 180,   6, 102, 180,   6,  44,   3, 171, 150, 118,  42, 118,  18,  12,
   0,   0,  41,  93, 186,   6, 102, 186,   6,  44,   3, 171, 150, 118,  18, 133,
   0,   0,  93, 180,   6, 102, 180,   6,  44, 206,   3, 160,  93, 186,   6, 102,
 186,   6, 160,  44, 206,   3, 160,  93, 187,   6, 102, 187,   6, 160, 133, 213,
 209,  44, 208,   3, 160, 133, 213,  93, 188,   6, 102, 188,   6,  93, 173,   6,
 102, 173,   6,  19,  14,   0,   0, 209,  93, 188,   6, 102, 188,   6,  44, 206,
   3, 160, 160, 133, 213,  93, 175,   6, 102, 175,   6, 150,  18,   8,   0,   0,
  93, 189,   6,  70, 189,   6,   0,  41,  93, 175,   6, 102, 175,   6,  93, 177,
   6, 102, 177,   6,  19,  22,   0,   0, 209,  44, 211,   3,  93, 175,   6, 102,
 175,   6, 160,  44, 212,   3, 160, 160, 133, 213,  16,   7,   0,   0, 209,  44,
 212,   3, 160, 133, 213, 209,  72,  93, 177,   6, 102, 177,   6,  72,   0,   0,
 218,   2,   3,   2,   3,   4, 117, 208,  48,  32, 133, 213,  93, 180,   6, 102,
 180,   6,  44,   3, 171, 150, 118,  42, 118,  18,  12,   0,   0,  41,  93, 181,
   6, 102, 181,   6,  44,   3, 171, 150, 118,  18,  72,   0,   0,  93, 180,   6,
 102, 180,   6,  44, 206,   3, 160,  93, 181,   6, 102, 181,   6, 160, 133, 213,
 209,  44, 208,   3, 160, 133, 213,  93, 188,   6, 102, 188,   6,  93, 173,   6,
 102, 173,   6,  19,  14,   0,   0, 209,  93, 188,   6, 102, 188,   6,  44, 206,
   3, 160, 160, 133, 213, 209,  93, 172,   6, 102, 172,   6,  44, 212,   3, 160,
 160, 133, 213, 209,  72,  93, 177,   6, 102, 177,   6,  72,   0,   0, 219,   2,
   3,   2,   3,   4, 119, 208,  48,  32, 133, 213,  93, 169,   6, 102, 169,   6,
 150,  18,   8,   0,   0,  93, 179,   6,  70, 179,   6,   0,  41,  93, 169,   6,
 102, 169,   6, 118,  42, 118,  18,  16,   0,   0,  41,  93, 169,   6, 102, 169,
   6,  93, 177,   6, 102, 177,   6, 171, 150, 118,  18,  55,   0,   0,  93, 180,
   6, 102, 180,   6,  44, 206,   3, 160,  93, 169,   6, 102, 169,   6, 160, 133,
 213,  93, 188,   6, 102, 188,   6,  93, 173,   6, 102, 173,   6,  19,  18,   0,
   0, 209,  44, 208,   3,  93, 188,   6, 102, 188,   6, 160,  44, 212,   3, 160,
 160, 133, 213, 209,  72,  93, 177,   6, 102, 177,   6,  72,   0,   0, 220,   2,
   2,   2,   3,   4, 151,   1, 208,  48,  16,  64,   0,   0,   9,  93, 190,   6,
  70, 190,   6,   0,  72,   9,  93, 191,   6,  70, 191,   6,   0,  72,   9,  93,
 168,   6, 102, 168,   6, 118,  18,   7,   0,   0,  93, 168,   6, 102, 168,   6,
  72,  93, 179,   6,  70, 179,   6,   0,  41,  93, 168,   6, 102, 168,   6,  72,
   9,  93, 173,   6, 102, 173,   6,  72,  16,  81,   0,   0,  93, 180,   6, 102,
 180,   6, 213,  44, 162,   3, 209,  26,   6,   0,   0,  37,   0,  16,  41,   0,
   0,  44, 163,   3, 209,  26,   6,   0,   0,  37,   1,  16,  27,   0,   0,  44,
 186,   3, 209,  26,   6,   0,   0,  37,   2,  16,  13,   0,   0,  39,  18,   6,
   0,   0,  37,   3,  16,   2,   0,   0,  37,   3,   8,   1,  27, 180, 255, 255,
   3, 128, 255, 255, 137, 255, 255, 146, 255, 255, 180, 255, 255,   0,   0, 221,
   2,   3,   5,   3,   4, 130,   2, 208,  48,  93, 187,   6, 102, 187,   6,  44,
 215,   3,  70, 165,   6,   1, 128,  19, 213,  93, 192,   6, 209,  36,   0, 102,
 160,   6,  70, 192,   6,   1, 116, 214,  93, 192,   6, 209,  36,   1, 102, 160,
   6,  70, 192,   6,   1, 116, 215, 210,  36,  10,  20, 196,   0,   0,  16,  47,
   0,   0,   9,  44, 217,   3,  72,   9,  44, 218,   3,  72,   9,  44, 219,   3,
  72,   9,  44, 220,   3,  72,   9,  44, 221,   3,  72,   9,  44, 222,   3,  72,
   9,  44, 223,   3,  72,   9,  93, 173,   6, 102, 173,   6,  72,  16, 145,   0,
   0, 211,  99,   4,  36,   0,  98,   4,  26,   6,   0,   0,  37,   0,  16,  97,
   0,   0,  36,   1,  98,   4,  26,   6,   0,   0,  37,   1,  16,  83,   0,   0,
  36,   2,  98,   4,  26,   6,   0,   0,  37,   2,  16,  69,   0,   0,  36,   3,
  98,   4,  26,   6,   0,   0,  37,   3,  16,  55,   0,   0,  36,   4,  98,   4,
  26,   6,   0,   0,  37,   4,  16,  41,   0,   0,  36,   5,  98,   4,  26,   6,
   0,   0,  37,   5,  16,  27,   0,   0,  36,   6,  98,   4,  26,   6,   0,   0,
  37,   6,  16,  13,   0,   0,  39,  18,   6,   0,   0,  37,   7,  16,   2,   0,
   0,  37,   7,   8,   4,  27, 128, 255, 255,   7,  93, 255, 255,  98, 255, 255,
 103, 255, 255, 108, 255, 255, 113, 255, 255, 118, 255, 255, 123, 255, 255, 128,
 255, 255,  93, 173,   6, 102, 173,   6,  72,   0,   0, 222,   2,   2,   1,   3,
   4, 216,   1, 208,  48,  93, 181,   6, 102, 181,   6,  44, 224,   3,  70, 170,
   6,   1,  36, 255,  14,   4,   0,   0,  44, 225,   3,  72,  93, 181,   6, 102,
 181,   6,  44, 188,   3,  70, 170,   6,   1,  36, 255,  14,   4,   0,   0,  44,
 226,   3,  72,  93, 181,   6, 102, 181,   6,  44, 189,   3,  70, 170,   6,   1,
  36, 255,  14,   4,   0,   0,  44, 227,   3,  72,  93, 181,   6, 102, 181,   6,
  44, 192,   3,  70, 170,   6,   1,  36, 255,  14,   4,   0,   0,  44, 228,   3,
  72,  93, 181,   6, 102, 181,   6,  44, 193,   3,  70, 170,   6,   1,  36, 255,
  14,   4,   0,   0,  44, 229,   3,  72,  93, 181,   6, 102, 181,   6,  44, 230,
   3,  70, 170,   6,   1,  36, 255,  14,   4,   0,   0,  44, 231,   3,  72,  93,
 181,   6, 102, 181,   6,  44, 196,   3,  70, 170,   6,   1,  36, 255,  14,   4,
   0,   0,  44, 232,   3,  72,  93, 181,   6, 102, 181,   6,  44, 233,   3,  70,
 170,   6,   1,  36, 255,  14,   4,   0,   0,  44, 234,   3,  72,  93, 181,   6,
 102, 181,   6,  44, 199,   3,  70, 170,   6,   1,  36, 255,  14,   4,   0,   0,
  44, 235,   3,  72,  93, 173,   6, 102, 173,   6,  72,   0,   0, 223,   2,   2,
   1,   3,   4,  40, 208,  48,  93, 193,   6, 102, 193,   6, 118,  18,   7,   0,
   0,  93, 193,   6, 102, 193,   6,  72,  94, 193,   6,  93, 194,   6,  70, 194,
   6,   0,  97, 193,   6,  93, 193,   6, 102, 193,   6,  72,   0,   0, 224,   2,
   2,   1,   3,   4,  40, 208,  48,  93, 195,   6, 102, 195,   6, 118,  18,   7,
   0,   0,  93, 195,   6, 102, 195,   6,  72,  94, 195,   6,  93, 196,   6,  70,
 196,   6,   0,  97, 195,   6,  93, 195,   6, 102, 195,   6,  72,   0,   0, 225,
   2,   2,   1,   3,   4,  40, 208,  48,  93, 197,   6, 102, 197,   6, 118,  18,
   7,   0,   0,  93, 197,   6, 102, 197,   6,  72,  94, 197,   6,  93, 198,   6,
  70, 198,   6,   0,  97, 197,   6,  93, 197,   6, 102, 197,   6,  72,   0,   0,
 226,   2,   2,   1,   3,   4,  40, 208,  48,  93, 199,   6, 102, 199,   6, 118,
  18,   7,   0,   0,  93, 199,   6, 102, 199,   6,  72,  94, 199,   6,  93, 200,
   6,  70, 200,   6,   0,  97, 199,   6,  93, 199,   6, 102, 199,   6,  72,   0,
   0, 227,   2,   2,   1,   3,   4,  40, 208,  48,  93, 201,   6, 102, 201,   6,
 118,  18,   7,   0,   0,  93, 201,   6, 102, 201,   6,  72,  94, 201,   6,  93,
 202,   6,  70, 202,   6,   0,  97, 201,   6,  93, 201,   6, 102, 201,   6,  72,
   0,   0, 228,   2,   2,   1,   3,   4,  40, 208,  48,  93, 203,   6, 102, 203,
   6, 118,  18,   7,   0,   0,  93, 203,   6, 102, 203,   6,  72,  94, 203,   6,
  93, 204,   6,  70, 204,   6,   0,  97, 203,   6,  93, 203,   6, 102, 203,   6,
  72,   0,   0, 229,   2,   2,   1,   3,   4,  40, 208,  48,  93, 205,   6, 102,
 205,   6, 118,  18,   7,   0,   0,  93, 205,   6, 102, 205,   6,  72,  94, 205,
   6,  93, 206,   6,  70, 206,   6,   0,  97, 205,   6,  93, 205,   6, 102, 205,
   6,  72,   0,   0, 230,   2,   2,   1,   3,   4,  40, 208,  48,  93, 207,   6,
 102, 207,   6, 118,  18,   7,   0,   0,  93, 207,   6, 102, 207,   6,  72,  94,
 207,   6,  93, 208,   6,  70, 208,   6,   0,  97, 207,   6,  93, 207,   6, 102,
 207,   6,  72,   0,   0, 231,   2,   2,   1,   3,   4,  40, 208,  48,  93, 209,
   6, 102, 209,   6, 118,  18,   7,   0,   0,  93, 209,   6, 102, 209,   6,  72,
  94, 209,   6,  93, 210,   6,  70, 210,   6,   0,  97, 209,   6,  93, 209,   6,
 102, 209,   6,  72,   0,   0, 232,   2,   2,   1,   3,   4,  40, 208,  48,  93,
 211,   6, 102, 211,   6, 118,  18,   7,   0,   0,  93, 211,   6, 102, 211,   6,
  72,  94, 211,   6,  93, 212,   6,  70, 212,   6,   0,  97, 211,   6,  93, 211,
   6, 102, 211,   6,  72,   0,   0, 233,   2,   2,   1,   3,   4,  40, 208,  48,
  93, 213,   6, 102, 213,   6, 118,  18,   7,   0,   0,  93, 213,   6, 102, 213,
   6,  72,  94, 213,   6,  93, 214,   6,  70, 214,   6,   0,  97, 213,   6,  93,
 213,   6, 102, 213,   6,  72,   0,   0, 234,   2,   2,   1,   3,   4,  40, 208,
  48,  93, 215,   6, 102, 215,   6, 118,  18,   7,   0,   0,  93, 215,   6, 102,
 215,   6,  72,  94, 215,   6,  93, 216,   6,  70, 216,   6,   0,  97, 215,   6,
  93, 215,   6, 102, 215,   6,  72,   0,   0, 235,   2,   1,   1,   4,   5,   6,
 208,  48, 208,  73,   0,  71,   0,   0, 236,   2,   2,   1,   1,   3,  22, 208,
  48, 101,   0,  93,  41, 102,  41,  48,  93, 142,   7, 102, 142,   7,  88,  18,
  29, 104, 141,   7,  71,   0,   0, 237,   2,   1,   1,   3,   4,   3, 208,  48,
  71,   0,   0, 240,   2,   4,   3,   3,   4,  85, 208,  48,  93, 144,   7, 209,
  70, 144,   7,   1, 133, 214,  93, 145,   7,  44, 141,   4, 210, 160,  70, 145,
   7,   1,  41, 210,  44, 142,   4,  70, 146,   7,   1,  36, 255,  14,  43,   0,
   0, 210,  36,   0, 210, 102, 147,   7,  36,   1, 161,  70, 148,   7,   2, 133,
 214, 210,  44, 142,   4,  70, 146,   7,   1,  36, 255,  14,   9,   0,   0, 210,
  44, 142,   4,  70, 149,   7,   1,  72, 210,  86,   1,  72,  86,   0,  72,   0,
   0, 242,   2,   3,   3,   3,   4,  28, 208,  48,  93, 150,   7, 209,  70, 150,
   7,   1, 133, 214,  93, 145,   7,  44, 145,   4, 210, 160,  70, 145,   7,   1,
  41,  86,   0,  72,   0,   0, 243,   2,   4,   4,   4,   5,  48, 208,  48, 208,
  73,   0, 209,  36, 255, 175, 118,  42, 118,  18,   6,   0,   0,  41, 210,  36,
 255, 175, 118,  42, 118,  18,   6,   0,   0,  41, 211,  36, 255, 175, 118,  18,
   9,   0,   0, 208, 209, 210, 211,  70, 151,   7,   3,  41,  71,   0,   0, 130,
   3,   1,   1,   4,   5,   8, 208,  48, 208,  70, 153,   7,   0,  72,   0,   0,
 131,   3,   1,   1,   4,   5,   7, 208,  48, 208, 102, 154,   7,  72,   0,   0,
 132,   3,   2,   2,   4,   5,   8, 208,  48, 208, 209, 104, 154,   7,  71,   0,
   0, 133,   3,   1,   1,   4,   5,   7, 208,  48, 208, 102, 155,   7,  72,   0,
   0, 134,   3,   1,   1,   4,   5,   7, 208,  48, 208, 102, 156,   7,  72,   0,
   0, 136,   3,   2,   2,   4,   5, 115, 208,  48,  16,  20,   0,   0,   9,  44,
 152,   4,  72,   9,  44, 153,   4,  72,   9,  44, 154,   4,  72,   9,  16,  88,
   0,   0, 208, 102, 157,   7, 213,  93, 158,   7, 102, 158,   7, 209,  26,   6,
   0,   0,  37,   0,  16,  47,   0,   0,  93, 159,   7, 102, 159,   7, 209,  26,
   6,   0,   0,  37,   1,  16,  30,   0,   0,  93, 160,   7, 102, 160,   7, 209,
  26,   6,   0,   0,  37,   2,  16,  13,   0,   0,  39,  18,   6,   0,   0,  37,
   3,  16,   2,   0,   0,  37,   3,   8,   1,  27, 180, 255, 255,   3, 165, 255,
 255, 170, 255, 255, 175, 255, 255, 180, 255, 255,  71,   0,   0, 141,   3,   1,
   1,   4,   5,   7, 208,  48, 208, 102, 161,   7,  72,   0,   0, 142,   3,   1,
   1,   4,   5,   7, 208,  48, 208, 102, 162,   7,  72,   0,   0, 143,   3,   1,
   1,   4,   5,   7, 208,  48, 208, 102, 163,   7,  72,   0,   0, 144,   3,   1,
   1,   4,   5,   7, 208,  48, 208, 102, 164,   7,  72,   0,   0, 145,   3,   4,
   3,   4,   5,  54, 208,  48, 208, 209,  93, 165,   7, 210,  70, 165,   7,   1,
  70, 166,   7,   2, 150,  18,  27,   0,   0,  93, 167,   7,  93, 168,   7,  93,
 169,   7, 102, 169,   7,  70, 168,   7,   1,  93, 169,   7, 102, 169,   7,  74,
 167,   7,   2,   3, 208,  38, 104, 154,   7,  71,   0,   0, 146,   3,   4,   2,
   4,   5, 159,   1, 208,  48, 208, 102, 170,   7, 150,  18,   1,   0,   0,  71,
 208,  70, 171,   7,   0, 150,  18, 121,   0,   0,  16,  51,   0,   0,   9,  16,
 112,   0,   0,   9,  16, 107,   0,   0,   9,  93, 145,   7,  44, 165,   4,  93,
 169,   7, 102, 169,   7, 160,  44, 166,   4, 160,  93, 168,   7,  93, 169,   7,
 102, 169,   7,  70, 168,   7,   1, 160,  70, 145,   7,   1,  41,  16,  66,   0,
   0,  93, 169,   7, 102, 169,   7, 213,  36,   0, 209,  26,   6,   0,   0,  37,
   0,  16,  30,   0,   0,  93, 172,   7, 102, 172,   7, 209,  26,   6,   0,   0,
  37,   1,  16,  13,   0,   0,  39,  18,   6,   0,   0,  37,   2,  16,   2,   0,
   0,  37,   2,   8,   1,  27, 163, 255, 255,   2, 153, 255, 255, 158, 255, 255,
 163, 255, 255, 208,  39, 104, 154,   7, 208,  39, 104, 155,   7, 208,  39, 104,
 156,   7,  71,   0,   0, 147,   3,   3,   3,   4,   5,  53, 208,  48, 208, 102,
 170,   7, 150,  18,   1,   0,   0,  71, 208, 209, 210,  70, 173,   7,   2,  36,
 255,  20,  27,   0,   0,  93, 167,   7,  93, 168,   7,  93, 169,   7, 102, 169,
   7,  70, 168,   7,   1,  93, 169,   7, 102, 169,   7,  74, 167,   7,   2,   3,
  71,   0,   0, 148,   3,   3,   3,   4,   5,  73, 208,  48, 208, 102, 170,   7,
 150,  18,   1,   0,   0,  71, 208, 209, 210,  70, 174,   7,   2,  36, 255,  20,
  27,   0,   0,  93, 167,   7,  93, 168,   7,  93, 169,   7, 102, 169,   7,  70,
 168,   7,   1,  93, 169,   7, 102, 169,   7,  74, 167,   7,   2,   3,  93, 145,
   7,  44, 169,   4, 209, 102, 147,   7, 160,  44, 170,   4, 160,  70, 145,   7,
   1,  41,  71,   0,   0, 149,   3,   3,   5,   4,   5,  50, 208,  48, 208, 209,
 210,  70, 175,   7,   2,  41, 208, 102, 170,   7,  18,  13,   0,   0, 208, 211,
  98,   4,  70, 176,   7,   2,  41,  16,  18,   0,   0,  93, 145,   7,  44, 173,
   4, 209, 160,  44, 124, 160, 210, 160,  70, 145,   7,   1,  41,  71,   0,   0,
 150,   3,   2,   4,   4,   5,  57, 208,  48, 208, 102, 170,   7, 150,  18,   1,
   0,   0,  71,  44,   3, 133, 214, 208, 209,  70, 177,   7,   1, 115, 215, 210,
 208, 102, 178,   7, 160, 133, 214, 211,  36,   0,  20,  16,   0,   0,  93, 145,
   7,  44, 176,   4,  70, 145,   7,   1,  41, 208,  39, 104, 154,   7, 210,  72,
   0,   0, 151,   3,   2,   4,   4,   5,  56, 208,  48,  32, 128,  44, 214, 208,
 102, 170,   7, 150,  18,   1,   0,   0,  71, 208, 209,  70, 179,   7,   1, 115,
 215, 208, 102, 180,   7, 128,  44, 214, 211,  36,   0,  20,  16,   0,   0,  93,
 145,   7,  44, 176,   4,  70, 145,   7,   1,  41, 208,  39, 104, 154,   7, 210,
  72,   0,   0, 152,   3,   3,   4,   4,   5,  46, 208,  48, 208, 209, 210,  70,
 175,   7,   2,  41, 208, 102, 170,   7,  18,   7,   0,   0, 208, 211,  70, 181,
   7,   1,  72,  93, 145,   7,  44, 180,   4, 209, 160,  44, 124, 160, 210, 160,
  70, 145,   7,   1,  41,  44,   3,  72,   0,   0, 153,   3,   3,   3,   4,   5,
  42, 208,  48, 208, 209,  70, 182,   7,   1, 118, 214, 210,  18,  25,   0,   0,
  93, 145,   7,  44, 182,   4, 209, 160,  70, 145,   7,   1,  41, 208,  38, 104,
 155,   7,  94, 183,   7, 209,  97, 183,   7, 210,  72,   0,   0, 154,   3,   2,
   3,   4,   5,  22, 208,  48, 208, 209,  70, 184,   7,   1, 118, 214, 210,  18,
   5,   0,   0, 208,  38, 104, 156,   7, 210,  72,   0,   0, 155,   3,   2,   2,
   4,   5,  29, 208,  48, 208,  70, 185,   7,   0, 128, 152,   7, 213, 209, 118,
  18,  10,   0,   0, 208,  38,  97, 186,   7, 209,  38,  97, 186,   7, 209,  72,
   0,   0, 156,   3,   2,   1,   1,   3,  22, 208,  48, 101,   0,  93,  41, 102,
  41,  48,  93, 236,   7, 102, 236,   7,  88,  19,  29, 104, 152,   7,  71,   0,
   0, 157,   3,   2,   1,   3,   4,  21, 208,  48,  94, 239,   7,  44, 212,   4,
 104, 239,   7,  94, 240,   7,  44, 214,   4, 104, 240,   7,  71,   0,   0, 158,
   3,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 159,   3,
   2,   1,   1,   3,  22, 208,  48, 101,   0,  93,  41, 102,  41,  48,  93, 244,
   7, 102, 244,   7,  88,  20,  29, 104, 243,   7,  71,   0,   0, 160,   3,   1,
   1,   3,   4,   3, 208,  48,  71,   0,   0, 167,   3,   1,   1,   4,   5,   6,
 208,  48, 208,  73,   0,  71,   0,   0, 168,   3,   2,   1,   1,   3,  22, 208,
  48, 101,   0,  93,  41, 102,  41,  48,  93, 253,   7, 102, 253,   7,  88,  21,
  29, 104, 246,   7,  71,   0,   0};

} }
