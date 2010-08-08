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
const uint32_t shell_toplevel_abc_method_count = 237;
const uint32_t shell_toplevel_abc_length = 11360;

/* thunks (45 unique signatures, 151 total) */

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
// avmplus_System_private_getExecPath
// flash_utils_ByteArray_endian_get
// flash_utils_ByteArray_readUTF
// flash_utils_ByteArray_private__toString
// avmplus_System_getAvmplusVersion
// C_unistd___unistd_getcwd
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

// C_errno___errno_ENFILE_get
// C_errno___errno_E2BIG_get
// C_errno___errno_ENOTTY_get
// C_errno___errno_ENXIO_get
// C_errno___errno_ESRCH_get
// C_unistd___unistd_F_OK_get
// C_errno___errno_EILSEQ_get
// C_errno___errno_EPIPE_get
// C_errno___errno_ENOMEM_get
// C_errno___errno_ENAMETOOLONG_get
// C_errno___errno_EDOM_get
// flash_utils_ByteArray_readShort
// C_errno___errno_EFBIG_get
// C_unistd___unistd_R_OK_get
// flash_utils_ByteArray_readByte
// C_errno___errno_EFAULT_get
// C_errno___errno_EIO_get
// C_errno___errno_EROFS_get
// C_errno___errno_ENODEV_get
// C_errno___errno_EMLINK_get
// C_errno___errno_ENOTEMPTY_get
// C_errno___errno_EMFILE_get
// C_errno___errno_errno_get
// C_errno___errno_EDEADLK_get
// C_errno___errno_ERANGE_get
// C_errno___errno_EACCES_get
// C_errno___errno_ENOSPC_get
// C_errno___errno_EBUSY_get
// C_errno___errno_ENOSYS_get
// C_errno___errno_ENOEXEC_get
// C_stdio___stdio_PATH_MAX_get
// C_errno___errno_EEXIST_get
// C_errno___errno_ESPIPE_get
// C_errno___errno_EINVAL_get
// C_errno___errno_ENOTDIR_get
// C_errno___errno_EXDEV_get
// C_errno___errno_ENOLCK_get
// C_stdio___stdio_FILENAME_MAX_get
// C_errno___errno_EBADF_get
// C_stdlib___stdlib_EXIT_FAILURE_get
// C_errno___errno_EAGAIN_get
// C_errno___errno_ECHILD_get
// flash_utils_ByteArray_readInt
// C_unistd___unistd_X_OK_get
// C_stdlib___stdlib_EXIT_SUCCESS_get
// C_errno___errno_EINTR_get
// C_unistd___unistd_W_OK_get
// C_errno___errno_ENOENT_get
// C_errno___errno_EISDIR_get
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
// C_stdlib___stdlib_unsetenv
// C_unistd___unistd_rmdir
// avmplus_System_exec
// C_unistd___unistd_mkdir
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

// C_stdlib___stdlib_realpath
// C_stdlib___stdlib_getenv
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

// flash_trace_Trace_getListener
// avmplus_System_private_getArgv
// flash_sampler_NewObjectSample_object_get
// avmplus_Domain_currentDomain_get
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

// flash_utils_ByteArray_readBoolean
// avmplus_System_isDebugger
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

// C_unistd___unistd_access
AvmBox shell_toplevel_i2a_osi_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv)
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
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_access, ::avmshell::UnistdClass::access)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_getcwd, ::avmshell::UnistdClass::getcwd)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_mkdir, ::avmshell::UnistdClass::mkdir)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_rmdir, ::avmshell::UnistdClass::rmdir)
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
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_errno_get, ::avmshell::CErrnoClass::get_errno)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_errno_set, ::avmshell::CErrnoClass::set_errno)
        AVMTHUNK_NATIVE_METHOD(C_stdio___stdio_FILENAME_MAX_get, ::avmshell::StdioClass::get_FILENAME_MAX)
        AVMTHUNK_NATIVE_METHOD(C_stdio___stdio_PATH_MAX_get, ::avmshell::StdioClass::get_PATH_MAX)
        AVMTHUNK_NATIVE_METHOD(C_stdio___stdio_remove, ::avmshell::StdioClass::remove)
        AVMTHUNK_NATIVE_METHOD(C_stdio___stdio_rename, ::avmshell::StdioClass::rename)
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
        AVMTHUNK_NATIVE_CLASS(abcclass_avmplus_JObject, JObjectClass, JObjectClass, SlotOffsetsAndAsserts::s_slotsOffsetJObjectClass, JObject, SlotOffsetsAndAsserts::s_slotsOffsetJObject)
    AVMTHUNK_END_NATIVE_CLASSES()

AVMTHUNK_END_NATIVE_TABLES()

AVMTHUNK_DEFINE_NATIVE_INITIALIZER(shell_toplevel)

/* abc */
const uint8_t shell_toplevel_abc_data[11360] = {
  16,   0,  46,   0,   6,   0,   2,   1,   3,   4,   0,   0, 181,   2,   6,  83,
 121, 115, 116, 101, 109,  19, 115, 104, 101, 108, 108,  95, 116, 111, 112, 108,
 101, 118, 101, 108,  46,  97, 115,  36,  49,   0,   7,  97, 118, 109, 112, 108,
 117, 115,   8, 114, 101,  97, 100,  76, 105, 110, 101,   6,  83, 116, 114, 105,
 110, 103,   8, 103, 101, 116,  84, 105, 109, 101, 114,   4, 117, 105, 110, 116,
   5, 116, 114,  97,  99, 101,   4, 118, 111, 105, 100,   6,  68, 111, 109,  97,
 105, 110,  13,  99, 117, 114, 114, 101, 110, 116,  68, 111, 109,  97, 105, 110,
   8, 103, 101, 116,  67, 108,  97, 115, 115,   5,  67, 108,  97, 115, 115,   8,
 100, 101,  98, 117, 103, 103, 101, 114,  14,  97, 118, 109, 112, 108, 117, 115,
  58,  83, 121, 115, 116, 101, 109,   4,  97, 114, 103, 118,   7, 103, 101, 116,
  65, 114, 103, 118,   6,  79,  98, 106, 101,  99, 116,  14, 101, 120, 101,  99,
 117, 116,  97,  98, 108, 101,  80,  97, 116, 104,  11, 103, 101, 116,  69, 120,
 101,  99,  80,  97, 116, 104,   3, 105, 110, 116,   5,  65, 114, 114,  97, 121,
   7,  66, 111, 111, 108, 101,  97, 110,   6,  78, 117, 109,  98, 101, 114,   3,
 238, 138, 148,   4, 101, 120, 105, 116,   4, 101, 120, 101,  99,  17, 103, 101,
 116,  65, 118, 109, 112, 108, 117, 115,  86, 101, 114, 115, 105, 111, 110,   5,
 119, 114, 105, 116, 101,  10, 105, 115,  68, 101,  98, 117, 103, 103, 101, 114,
  11, 116, 111, 116,  97, 108,  77, 101, 109, 111, 114, 121,  10, 102, 114, 101,
 101,  77, 101, 109, 111, 114, 121,  13, 112, 114, 105, 118,  97, 116, 101,  77,
 101, 109, 111, 114, 121,  19, 102, 111, 114,  99, 101,  70, 117, 108, 108,  67,
 111, 108, 108, 101,  99, 116, 105, 111, 110,  15, 113, 117, 101, 117, 101,  67,
 111, 108, 108, 101,  99, 116, 105, 111, 110,  12,  97, 118, 109, 112, 108, 117,
 115,  58,  70, 105, 108, 101,   9,  66, 121, 116, 101,  65, 114, 114,  97, 121,
  11, 102, 108,  97, 115, 104,  46, 117, 116, 105, 108, 115,   8, 114, 101,  97,
 100,  70, 105, 108, 101,   9, 119, 114, 105, 116, 101,  70, 105, 108, 101,   6,
 101, 120, 105, 115, 116, 115,   4, 114, 101,  97, 100,  15, 102, 105, 108, 101,
  84, 111,  66, 121, 116, 101,  65, 114, 114,  97, 121,  14, 119, 114, 105, 116,
 101,  66, 121, 116, 101,  65, 114, 114,  97, 121,   4,  70, 105, 108, 101,  25,
 102, 108,  97, 115, 104,  46, 115, 121, 115, 116, 101, 109,  58,  67,  97, 112,
  97,  98, 105, 108, 105, 116, 105, 101, 115,   7,  65,  86,  77,  80, 108, 117,
 115,  12, 102, 108,  97, 115, 104,  46, 115, 121, 115, 116, 101, 109,  10, 112,
 108,  97, 121, 101, 114,  84, 121, 112, 101,  12,  67,  97, 112,  97,  98, 105,
 108, 105, 116, 105, 101, 115,  10,  97, 118, 109, 112, 108, 117, 115, 238, 138,
 148,   6, 110,  97, 116, 105, 118, 101,   3,  99, 108, 115,  23,  58,  58,  97,
 118, 109, 115, 104, 101, 108, 108,  58,  58,  83, 121, 115, 116, 101, 109,  67,
 108,  97, 115, 115,   7, 109, 101, 116, 104, 111, 100, 115,   4,  97, 117, 116,
 111,  21,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  70, 105,
 108, 101,  67, 108,  97, 115, 115,  15, 102, 108,  97, 115, 104,  46, 115, 121,
 115, 116, 101, 109, 238, 138, 148,  14, 103, 101, 116,  67, 108,  97, 115, 115,
  66, 121,  78,  97, 109, 101,   5, 112, 114, 105, 110, 116,  14,  97, 118, 109,
 112, 108, 117, 115,  58,  68, 111, 109,  97, 105, 110,   4, 105, 110, 105, 116,
  11,  68, 111, 109,  97, 105, 110,  46,  97, 115,  36,  50,   9, 108, 111,  97,
 100,  66, 121, 116, 101, 115,  24,  77,  73,  78,  95,  68,  79,  77,  65,  73,
  78,  95,  77,  69,  77,  79,  82,  89,  95,  76,  69,  78,  71,  84,  72,   4,
 108, 111,  97, 100,  12, 100, 111, 109,  97, 105, 110,  77, 101, 109, 111, 114,
 121,  23,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  68, 111,
 109,  97, 105, 110,  67, 108,  97, 115, 115,   8, 105, 110, 115, 116,  97, 110,
  99, 101,  24,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  68,
 111, 109,  97, 105, 110,  79,  98, 106, 101,  99, 116,  21, 102, 108,  97, 115,
 104,  46, 117, 116, 105, 108, 115,  58,  66, 121, 116, 101,  65, 114, 114,  97,
 121,  13, 122, 108, 105,  98,  95,  99, 111, 109, 112, 114, 101, 115, 115,  14,
  66, 121, 116, 101,  65, 114, 114,  97, 121,  46,  97, 115,  36,  51,  15, 122,
 108, 105,  98,  95, 117, 110,  99, 111, 109, 112, 114, 101, 115, 115,   9,  95,
 116, 111,  83, 116, 114, 105, 110, 103,   9, 114, 101,  97, 100,  66, 121, 116,
 101, 115,  10, 119, 114, 105, 116, 101,  66, 121, 116, 101, 115,  12, 119, 114,
 105, 116, 101,  66, 111, 111, 108, 101,  97, 110,   9, 119, 114, 105, 116, 101,
  66, 121, 116, 101,  10, 119, 114, 105, 116, 101,  83, 104, 111, 114, 116,   8,
 119, 114, 105, 116, 101,  73, 110, 116,  16, 119, 114, 105, 116, 101,  85, 110,
 115, 105, 103, 110, 101, 100,  73, 110, 116,  10, 119, 114, 105, 116, 101,  70,
 108, 111,  97, 116,  11, 119, 114, 105, 116, 101,  68, 111, 117,  98, 108, 101,
   8, 119, 114, 105, 116, 101,  85,  84,  70,  13, 119, 114, 105, 116, 101,  85,
  84,  70,  66, 121, 116, 101, 115,  11, 114, 101,  97, 100,  66, 111, 111, 108,
 101,  97, 110,   8, 114, 101,  97, 100,  66, 121, 116, 101,  16, 114, 101,  97,
 100,  85, 110, 115, 105, 103, 110, 101, 100,  66, 121, 116, 101,   9, 114, 101,
  97, 100,  83, 104, 111, 114, 116,  17, 114, 101,  97, 100,  85, 110, 115, 105,
 103, 110, 101, 100,  83, 104, 111, 114, 116,   7, 114, 101,  97, 100,  73, 110,
 116,  15, 114, 101,  97, 100,  85, 110, 115, 105, 103, 110, 101, 100,  73, 110,
 116,   9, 114, 101,  97, 100,  70, 108, 111,  97, 116,  10, 114, 101,  97, 100,
  68, 111, 117,  98, 108, 101,   7, 114, 101,  97, 100,  85,  84,  70,  12, 114,
 101,  97, 100,  85,  84,  70,  66, 121, 116, 101, 115,   6, 108, 101, 110, 103,
 116, 104,   8,  99, 111, 109, 112, 114, 101, 115, 115,  10, 117, 110,  99, 111,
 109, 112, 114, 101, 115, 115,   8, 116, 111,  83, 116, 114, 105, 110, 103,  14,
  98, 121, 116, 101, 115,  65, 118,  97, 105, 108,  97,  98, 108, 101,   8, 112,
 111, 115, 105, 116, 105, 111, 110,   6, 101, 110, 100, 105,  97, 110,  14, 102,
 108,  97, 115, 104,  46, 117, 116, 105, 108, 115, 238, 138, 148,  26,  58,  58,
  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  66, 121, 116, 101,  65, 114,
 114,  97, 121,  67, 108,  97, 115, 115,  27,  58,  58,  97, 118, 109, 115, 104,
 101, 108, 108,  58,  58,  66, 121, 116, 101,  65, 114, 114,  97, 121,  79,  98,
 106, 101,  99, 116,   8,  70, 117, 110,  99, 116, 105, 111, 110,   5,  81,  78,
  97, 109, 101,  19,  95, 103, 101, 116,  73, 110, 118, 111,  99,  97, 116, 105,
 111, 110,  67, 111, 117, 110, 116,  12,  83,  97, 109, 112, 108, 101, 114,  46,
  97, 115,  36,  52,  13, 102, 108,  97, 115, 104,  46, 115,  97, 109, 112, 108,
 101, 114,   1, 102,   1, 101,   3, 114, 101, 116,  19,  95, 115, 101, 116,  83,
  97, 109, 112, 108, 101, 114,  67,  97, 108, 108,  98,  97,  99, 107,   7, 119,
 114,  97, 112, 112, 101, 114,  24, 102, 108,  97, 115, 104,  46, 115,  97, 109,
 112, 108, 101, 114,  58,  83, 116,  97,  99, 107,  70, 114,  97, 109, 101,   4,
 110,  97, 109, 101,   2,  40,  41,   4, 102, 105, 108, 101,   1,  91,   1,  58,
   4, 108, 105, 110, 101,   1,  93,   8, 115,  99, 114, 105, 112, 116,  73,  68,
  10,  83, 116,  97,  99, 107,  70, 114,  97, 109, 101,  20, 102, 108,  97, 115,
 104,  46, 115,  97, 109, 112, 108, 101, 114,  58,  83,  97, 109, 112, 108, 101,
   4, 116, 105, 109, 101,   5, 115, 116,  97,  99, 107,   6,  83,  97, 109, 112,
 108, 101,  29, 102, 108,  97, 115, 104,  46, 115,  97, 109, 112, 108, 101, 114,
  58,  78, 101, 119,  79,  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,
   2, 105, 100,   4, 116, 121, 112, 101,   6, 111,  98, 106, 101,  99, 116,   4,
 115, 105, 122, 101,  15,  78, 101, 119,  79,  98, 106, 101,  99, 116,  83,  97,
 109, 112, 108, 101,  32, 102, 108,  97, 115, 104,  46, 115,  97, 109, 112, 108,
 101, 114,  58,  68, 101, 108, 101, 116, 101,  79,  98, 106, 101,  99, 116,  83,
  97, 109, 112, 108, 101,  18,  68, 101, 108, 101, 116, 101,  79,  98, 106, 101,
  99, 116,  83,  97, 109, 112, 108, 101,  16, 102, 108,  97, 115, 104,  46, 115,
  97, 109, 112, 108, 101, 114, 238, 138, 148,  15,  83, 116,  97,  99, 107,  70,
 114,  97, 109, 101,  67, 108,  97, 115, 115,  16,  83, 116,  97,  99, 107,  70,
 114,  97, 109, 101,  79,  98, 106, 101,  99, 116,  12,  99, 111, 110, 115, 116,
 115, 101, 116, 116, 101, 114, 115,   4, 116, 114, 117, 101,  11,  83,  97, 109,
 112, 108, 101,  67, 108,  97, 115, 115,  12,  83,  97, 109, 112, 108, 101,  79,
  98, 106, 101,  99, 116,  20,  78, 101, 119,  79,  98, 106, 101,  99, 116,  83,
  97, 109, 112, 108, 101,  67, 108,  97, 115, 115,  21,  78, 101, 119,  79,  98,
 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  79,  98, 106, 101,  99, 116,
  23,  68, 101, 108, 101, 116, 101,  79,  98, 106, 101,  99, 116,  83,  97, 109,
 112, 108, 101,  67, 108,  97, 115, 115,  24,  68, 101, 108, 101, 116, 101,  79,
  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  79,  98, 106, 101,  99,
 116,  12,  99, 108, 101,  97, 114,  83,  97, 109, 112, 108, 101, 115,  27,  83,
  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58,  99, 108,
 101,  97, 114,  83,  97, 109, 112, 108, 101, 115,  13, 115, 116,  97, 114, 116,
  83,  97, 109, 112, 108, 105, 110, 103,  28,  83,  97, 109, 112, 108, 101, 114,
  83,  99, 114, 105, 112, 116,  58,  58, 115, 116,  97, 114, 116,  83,  97, 109,
 112, 108, 105, 110, 103,  12, 115, 116, 111, 112,  83,  97, 109, 112, 108, 105,
 110, 103,  27,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,
  58,  58, 115, 116, 111, 112,  83,  97, 109, 112, 108, 105, 110, 103,  13, 112,
  97, 117, 115, 101,  83,  97, 109, 112, 108, 105, 110, 103,  28,  83,  97, 109,
 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 112,  97, 117, 115,
 101,  83,  97, 109, 112, 108, 105, 110, 103,  20, 115,  97, 109, 112, 108, 101,
  73, 110, 116, 101, 114, 110,  97, 108,  65, 108, 108, 111,  99, 115,  35,  83,
  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 115,  97,
 109, 112, 108, 101,  73, 110, 116, 101, 114, 110,  97, 108,  65, 108, 108, 111,
  99, 115,  18, 115, 101, 116,  83,  97, 109, 112, 108, 101, 114,  67,  97, 108,
 108,  98,  97,  99, 107,  34,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114,
 105, 112, 116,  58,  58,  95, 115, 101, 116,  83,  97, 109, 112, 108, 101, 114,
  67,  97, 108, 108,  98,  97,  99, 107,   7, 103, 101, 116,  83, 105, 122, 101,
  22,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58,
 103, 101, 116,  83, 105, 122, 101,  14, 103, 101, 116,  77, 101, 109,  98, 101,
 114,  78,  97, 109, 101, 115,  29,  83,  97, 109, 112, 108, 101, 114,  83,  99,
 114, 105, 112, 116,  58,  58, 103, 101, 116,  77, 101, 109,  98, 101, 114,  78,
  97, 109, 101, 115,  10, 103, 101, 116,  83,  97, 109, 112, 108, 101, 115,  25,
  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 103,
 101, 116,  83,  97, 109, 112, 108, 101, 115,  14, 103, 101, 116,  83,  97, 109,
 112, 108, 101,  67, 111, 117, 110, 116,  29,  83,  97, 109, 112, 108, 101, 114,
  83,  99, 114, 105, 112, 116,  58,  58, 103, 101, 116,  83,  97, 109, 112, 108,
 101,  67, 111, 117, 110, 116,  18, 103, 101, 116,  73, 110, 118, 111,  99,  97,
 116, 105, 111, 110,  67, 111, 117, 110, 116,  24, 103, 101, 116,  83, 101, 116,
 116, 101, 114,  73, 110, 118, 111,  99,  97, 116, 105, 111, 110,  67, 111, 117,
 110, 116,  24, 103, 101, 116,  71, 101, 116, 116, 101, 114,  73, 110, 118, 111,
  99,  97, 116, 105, 111, 110,  67, 111, 117, 110, 116,  34,  83,  97, 109, 112,
 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58,  95, 103, 101, 116,  73,
 110, 118, 111,  99,  97, 116, 105, 111, 110,  67, 111, 117, 110, 116,  14, 105,
 115,  71, 101, 116, 116, 101, 114,  83, 101, 116, 116, 101, 114,  29,  83,  97,
 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 105, 115,  71,
 101, 116, 116, 101, 114,  83, 101, 116, 116, 101, 114,  16, 103, 101, 116,  76,
 101, 120, 105,  99,  97, 108,  83,  99, 111, 112, 101, 115,  31,  83,  97, 109,
 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 103, 101, 116,  76,
 101, 120, 105,  99,  97, 108,  83,  99, 111, 112, 101, 115,  12, 103, 101, 116,
  83,  97, 118, 101, 100,  84, 104, 105, 115,  27,  83,  97, 109, 112, 108, 101,
 114,  83,  99, 114, 105, 112, 116,  58,  58, 103, 101, 116,  83,  97, 118, 101,
 100,  84, 104, 105, 115,  15, 103, 101, 116,  77,  97, 115, 116, 101, 114,  83,
 116, 114, 105, 110, 103,  30,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114,
 105, 112, 116,  58,  58, 103, 101, 116,  77,  97, 115, 116, 101, 114,  83, 116,
 114, 105, 110, 103,  17, 102, 108,  97, 115, 104,  46, 116, 114,  97,  99, 101,
  58,  84, 114,  97,  99, 101,   3,  79,  70,  70,   7,  77,  69,  84,  72,  79,
  68,  83,  17,  77,  69,  84,  72,  79,  68,  83,  95,  87,  73,  84,  72,  95,
  65,  82,  71,  83,  17,  77,  69,  84,  72,  79,  68,  83,  95,  65,  78,  68,
  95,  76,  73,  78,  69,  83,  27,  77,  69,  84,  72,  79,  68,  83,  95,  65,
  78,  68,  95,  76,  73,  78,  69,  83,  95,  87,  73,  84,  72,  95,  65,  82,
  71,  83,   4,  70,  73,  76,  69,   8,  76,  73,  83,  84,  69,  78,  69,  82,
   8, 115, 101, 116,  76, 101, 118, 101, 108,   8, 103, 101, 116,  76, 101, 118,
 101, 108,  11, 115, 101, 116,  76, 105, 115, 116, 101, 110, 101, 114,  11, 103,
 101, 116,  76, 105, 115, 116, 101, 110, 101, 114,  11, 102, 108,  97, 115, 104,
  46, 116, 114,  97,  99, 101,   5,  84, 114,  97,  99, 101,  10,  84, 114,  97,
  99, 101,  46,  97, 115,  36,  53,  10,  84, 114,  97,  99, 101,  67, 108,  97,
 115, 115,  22, 102, 108,  97, 115, 104,  46, 117, 116, 105, 108, 115,  58,  68,
 105,  99, 116, 105, 111, 110,  97, 114, 121,  15,  68, 105,  99, 116, 105, 111,
 110,  97, 114, 121,  46,  97, 115,  36,  54,  10,  68, 105,  99, 116, 105, 111,
 110,  97, 114, 121,  15,  68, 105,  99, 116, 105, 111, 110,  97, 114, 121,  67,
 108,  97, 115, 115,  16,  68, 105,  99, 116, 105, 111, 110,  97, 114, 121,  79,
  98, 106, 101,  99, 116,   8,  95,  95, 115, 121, 115, 116, 101, 109,  11, 115,
 116, 100, 108, 105,  98,  46,  97, 115,  36,  55,   8,  67,  46, 115, 116, 100,
 108, 105,  98,   8, 114, 101,  97, 108, 112,  97, 116, 104,   8, 117, 110, 115,
 101, 116, 101, 110, 118,   6, 115, 101, 116, 101, 110, 118,   6, 103, 101, 116,
 101, 110, 118,   5,  97,  98, 111, 114, 116,  17,  67,  46, 115, 116, 100, 108,
 105,  98,  58,  95,  95, 115, 116, 100, 108, 105,  98,  12,  69,  88,  73,  84,
  95,  83,  85,  67,  67,  69,  83,  83,  12,  69,  88,  73,  84,  95,  70,  65,
  73,  76,  85,  82,  69,   8,  95,  95, 115, 116, 100, 108, 105,  98,  23,  58,
  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  83, 116, 100, 108, 105,
  98,  67, 108,  97, 115, 115,   6, 115, 121, 115, 116, 101, 109,   5, 114, 109,
 100, 105, 114,  11, 117, 110, 105, 115, 116, 100,  46,  97, 115,  36,  56,   8,
  67,  46, 117, 110, 105, 115, 116, 100,   5, 109, 107, 100, 105, 114,   6, 103,
 101, 116,  99, 119, 100,   6,  97,  99,  99, 101, 115, 115,  17,  67,  46, 117,
 110, 105, 115, 116, 100,  58,  95,  95, 117, 110, 105, 115, 116, 100,   4,  70,
  95,  79,  75,   4,  88,  95,  79,  75,   4,  87,  95,  79,  75,   4,  82,  95,
  79,  75,   8,  95,  95, 117, 110, 105, 115, 116, 100,  23,  58,  58,  97, 118,
 109, 115, 104, 101, 108, 108,  58,  58,  85, 110, 105, 115, 116, 100,  67, 108,
  97, 115, 115,   6, 115, 116, 114, 108, 101, 110,  11, 115, 116, 114, 105, 110,
 103,  46,  97, 115,  36,  57,   8,  67,  46, 115, 116, 114, 105, 110, 103,   8,
 115, 116, 114, 101, 114, 114, 111, 114,  17,  67,  46, 115, 116, 114, 105, 110,
 103,  58,  95,  95, 115, 116, 114, 105, 110, 103,   8,  95,  95, 115, 116, 114,
 105, 110, 103,  24,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,
  67,  83, 116, 114, 105, 110, 103,  67, 108,  97, 115, 115,   5, 101, 114, 114,
 110, 111,  11, 101, 114, 114, 110, 111,  46,  97, 115,  36,  49,  48,   7,  67,
  46, 101, 114, 114, 110, 111,  15,  67,  46, 101, 114, 114, 110, 111,  58,  95,
  95, 101, 114, 114, 110, 111,   4,  69,  68,  79,  77,   6,  69,  73,  76,  83,
  69,  81,   6,  69,  82,  65,  78,  71,  69,   5,  69,  80,  69,  82,  77,   6,
  69,  78,  79,  69,  78,  84,   5,  69,  83,  82,  67,  72,   5,  69,  73,  78,
  84,  82,   3,  69,  73,  79,   5,  69,  78,  88,  73,  79,   5,  69,  50,  66,
  73,  71,   7,  69,  78,  79,  69,  88,  69,  67,   5,  69,  66,  65,  68,  70,
   6,  69,  67,  72,  73,  76,  68,   6,  69,  65,  71,  65,  73,  78,   6,  69,
  78,  79,  77,  69,  77,   6,  69,  65,  67,  67,  69,  83,   6,  69,  70,  65,
  85,  76,  84,   5,  69,  66,  85,  83,  89,   6,  69,  69,  88,  73,  83,  84,
   5,  69,  88,  68,  69,  86,   6,  69,  78,  79,  68,  69,  86,   7,  69,  78,
  79,  84,  68,  73,  82,   6,  69,  73,  83,  68,  73,  82,   6,  69,  73,  78,
  86,  65,  76,   6,  69,  78,  70,  73,  76,  69,   6,  69,  77,  70,  73,  76,
  69,   6,  69,  78,  79,  84,  84,  89,   5,  69,  70,  66,  73,  71,   6,  69,
  78,  79,  83,  80,  67,   6,  69,  83,  80,  73,  80,  69,   5,  69,  82,  79,
  70,  83,   6,  69,  77,  76,  73,  78,  75,   5,  69,  80,  73,  80,  69,   7,
  69,  68,  69,  65,  68,  76,  75,  12,  69,  78,  65,  77,  69,  84,  79,  79,
  76,  79,  78,  71,   6,  69,  78,  79,  76,  67,  75,   6,  69,  78,  79,  83,
  89,  83,   9,  69,  78,  79,  84,  69,  77,  80,  84,  89,   7,  95,  95, 101,
 114, 114, 110, 111,  23,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,
  58,  67,  69, 114, 114, 110, 111,  67, 108,  97, 115, 115,   6, 114, 101, 110,
  97, 109, 101,  11, 115, 116, 100, 105, 111,  46,  97, 115,  36,  49,  49,   7,
  67,  46, 115, 116, 100, 105, 111,   6, 114, 101, 109, 111, 118, 101,  15,  67,
  46, 115, 116, 100, 105, 111,  58,  95,  95, 115, 116, 100, 105, 111,  12,  70,
  73,  76,  69,  78,  65,  77,  69,  95,  77,  65,  88,   8,  80,  65,  84,  72,
  95,  77,  65,  88,   7,  95,  95, 115, 116, 100, 105, 111,  22,  58,  58,  97,
 118, 109, 115, 104, 101, 108, 108,  58,  58,  83, 116, 100, 105, 111,  67, 108,
  97, 115, 115,  18, 102, 108,  97, 115, 104,  46, 117, 116, 105, 108, 115,  58,
  69, 110, 100, 105,  97, 110,  10,  66,  73,  71,  95,  69,  78,  68,  73,  65,
  78,   9,  98, 105, 103,  69, 110, 100, 105,  97, 110,  13,  76,  73,  84,  84,
  76,  69,  95,  69,  78,  68,  73,  65,  78,  12, 108, 105, 116, 116, 108, 101,
  69, 110, 100, 105,  97, 110,   6,  69, 110, 100, 105,  97, 110,  12,  69, 110,
 100, 105,  97, 110,  46,  97, 115,  36,  49,  50,  15,  97, 118, 109, 112, 108,
 117, 115,  58,  74,  79,  98, 106, 101,  99, 116,   7,  74,  79,  98, 106, 101,
  99, 116,   6,  99, 114, 101,  97, 116, 101,  11,  99, 114, 101,  97, 116, 101,
  65, 114, 114,  97, 121,   7, 116, 111,  65, 114, 114,  97, 121,  20,  99, 111,
 110, 115, 116, 114, 117,  99, 116, 111, 114,  83, 105, 103, 110,  97, 116, 117,
 114, 101,  15, 109, 101, 116, 104, 111, 100,  83, 105, 103, 110,  97, 116, 117,
 114, 101,  14, 102, 105, 101, 108, 100,  83, 105, 103, 110,  97, 116, 117, 114,
 101,  10,  74,  97, 118,  97,  46,  97, 115,  36,  49,  51,  12,  74,  79,  98,
 106, 101,  99, 116,  67, 108,  97, 115, 115,  85,   5,   2,  22,   3,  23,   3,
  22,   4,  23,   4,   5,  16,  24,  16,  26,  16,  26,  19,  22,  26,   5,  37,
  24,  37,  26,  37,  22,  39,   5,  47,  22,  49,  23,  49,  24,  47,  26,  47,
  22,  52,  22,  59,   5,  62,   5,  64,  24,  62,  26,  62,   5,  72,   5,  74,
  23,  39,  24,  72,  26,  72,  22, 106,   5, 112,  22, 113,  23, 113,   5, 119,
  24, 119,  26, 119,   5, 129,   1,  24, 129,   1,   5, 133,   1,  24, 133,   1,
   5, 139,   1,  24, 139,   1,  22, 141,   1,   5, 184,   1,  22, 196,   1,  24,
 184,   1,   5, 198,   1,  23, 196,   1,   5, 200,   1,   5, 201,   1,  24, 200,
   1,  26, 200,   1,   5, 206,   1,  22, 207,   1,  23, 207,   1,   5, 213,   1,
  24, 213,   1,   5, 220,   1,  22, 221,   1,  23, 221,   1,   5, 225,   1,  24,
 225,   1,   5, 233,   1,  22, 234,   1,  23, 234,   1,   5, 236,   1,  24, 236,
   1,   5, 240,   1,  22, 241,   1,  23, 241,   1,   5, 242,   1,  24, 242,   1,
   5, 156,   2,  22, 157,   2,  23, 157,   2,   5, 159,   2,  24, 159,   2,   5,
 164,   2,  24, 164,   2,   5, 170,   2,   5, 171,   2,  24, 171,   2,   5, 179,
   2,  49,   4,   1,   2,   3,   4,   4,   1,   2,   4,   5,   8,   1,   2,   4,
   5,   6,   7,   8,   9,   1,  10,   1,   6,   9,   1,   2,   4,   5,   9,  11,
  12,  13,  14,   8,   1,   2,   4,   5,   9,  11,  12,  13,   9,   1,   2,   4,
   9,  15,  16,  17,  18,  19,   1,   4,   1,  16,   5,   1,   2,   4,  16,  17,
   1,  20,   1,  21,   8,   2,   4,   5,   9,  22,  23,  24,  25,   9,   2,   4,
   5,   9,  14,  22,  23,  24,  25,   1,  22,   4,   2,   4,   5,  23,   8,   2,
   9,  14,  26,  27,  28,  29,  30,   1,  26,   1,  14,   4,   2,  14,  27,  28,
   1,  31,   4,   2,  32,  33,  34,   1,  34,   8,   2,   9,  32,  33,  34,  35,
  36,  37,   1,  44,   4,   2,  46,  48,  49,   1,  46,   8,   2,   9,  14,  28,
  50,  51,  52,  53,   1,  50,   4,   2,  14,  28,  51,   4,   2,  54,  55,  56,
   1,  56,   1,  55,   4,   2,  59,  60,  61,   1,  61,   1,  60,   4,   2,  64,
  65,  66,   1,  66,   1,  65,   4,   2,  69,  70,  71,   1,  71,   1,  70,   4,
   2,  74,  75,  76,   1,  76,   1,  75,   4,   2,  14,  28,  81,   4,   2,   4,
   5,  84, 203,   3,   9,   1,   1,   9,   5,   1,   7,   2,   6,   9,   7,   1,
   7,   2,   8,   9,   9,   1,   7,   2,  10,   9,  11,   1,   9,  12,   1,   9,
  13,   1,   7,   2,  14,   9,   1,   2,   9,  15,   2,   7,   2,  17,   9,  18,
   3,   7,   2,  20,   9,  21,   3,   7,   2,  22,   7,   2,  23,   7,   2,  24,
   7,   2,  25,   9,  27,   4,   9,  28,   4,   9,  29,   4,   9,   9,   4,   9,
  30,   4,   9,  15,   4,   9,  31,   4,   9,   7,   4,   9,  18,   5,   9,  17,
   4,   9,  21,   5,   9,  20,   4,   9,   5,   4,   9,  32,   4,   9,  33,   4,
   9,  34,   4,   9,  35,   4,   9,  36,   4,   7,   4,   1,   7,   2,  19,   9,
  38,   6,   9,  40,   7,   7,  14,  38,   9,  41,   7,   9,  42,   4,   9,  43,
   4,   9,  44,   4,   9,  45,   4,   7,   4,  46,   9,   1,   8,   9,  31,   8,
   9,  50,   4,   7,  16,  51,   9,   1,   9,   9,  19,   2,   9,  46,   9,   9,
  51,  10,   9,  19,  11,   9,   1,  12,   9,  46,  12,   9,  15,  12,   9,  51,
  13,   9,  60,   4,   9,  61,   4,   7,   4,  11,   9,  63,  14,   9,  38,  15,
   9,  40,  14,   9,  65,  14,   9,  12,   4,   9,  66,   4,   9,  63,  16,   9,
  65,   4,   9,  13,   4,   9,  67,   4,   9,  68,   4,   9,  11,   9,   9,  19,
  17,   9,  11,  12,   9,  73,  18,   9,  75,  18,   9,  76,  18,   9,  40,   4,
   9,  41,   4,   9,  77,   4,   9,  78,   4,   9,  79,   4,   9,  80,   4,   9,
  81,   4,   9,  82,   4,   9,  83,   4,   9,  84,   4,   9,  85,   4,   9,  86,
   4,   9,  87,   4,   9,  88,   4,   9,  89,   4,   9,  90,   4,   9,  91,   4,
   9,  92,   4,   9,  93,   4,   9,  94,   4,   9,  95,   4,   9,  96,   4,   9,
  97,   4,   9,  98,   4,   9,  99,   4,   9,  73,  19,   9, 100,   4,   9,  75,
  19,   9, 101,   4,   9,  76,  19,   9, 102,   4,   9, 103,   4,   9, 104,   4,
   9, 105,   4,   9,  38,  20,   9,  19,  21,   9,  38,  22,   7,   2, 109,   7,
   2, 110,   9, 111,  23,   9, 114,  23,   7,   2, 115,   9, 116,  24,   9, 117,
  23,   9, 114,  24,   9, 118,  24,   9, 120,  25,   9, 122,  25,   9, 125,  25,
   9, 120,   4,   9, 122,   4,   9, 125,   4,   9, 127,   4,   7,  33, 128,   1,
   9, 130,   1,   4,   9, 131,   1,   4,   7,  33, 132,   1,   9, 134,   1,   4,
   9, 135,   1,   4,   9, 136,   1,   4,   9, 137,   1,   4,   7,  33, 138,   1,
   7,  33, 140,   1,   9,  19,  23,   9, 128,   1,  26,   9, 132,   1,  26,   9,
 138,   1,  26,   9, 140,   1,  26,   9, 152,   1,  26,   9, 154,   1,  26,   9,
 156,   1,  26,   9, 158,   1,  26,   9, 160,   1,  26,   9, 162,   1,  26,   9,
 117,  24,   9, 164,   1,  26,   9, 166,   1,  26,   9, 168,   1,  26,   9, 170,
   1,  26,   9, 172,   1,  26,   9, 173,   1,  26,   9, 174,   1,  26,   9, 111,
  24,   9, 176,   1,  26,   9, 178,   1,  26,   9, 180,   1,  26,   9, 182,   1,
  26,   7,   2, 185,   1,   7,   2, 186,   1,   7,   2, 187,   1,   7,   2, 188,
   1,   7,   2, 189,   1,   7,   2, 190,   1,   7,   2, 191,   1,   9, 185,   1,
   4,   9, 186,   1,   4,   9, 187,   1,   4,   9, 188,   1,   4,   9, 189,   1,
   4,   9, 190,   1,   4,   9, 191,   1,   4,   9, 192,   1,   4,   9, 193,   1,
   4,   9, 194,   1,   4,   9, 195,   1,   4,   7,  46, 197,   1,   9,  19,  27,
   9, 197,   1,  28,   9,  63,  29,   9,  63,  30,   7,  14, 202,   1,   9,  19,
  31,   9, 202,   1,  22,   9, 205,   1,  32,   9, 208,   1,  32,   9, 209,   1,
  32,   9, 210,   1,  32,   9, 211,   1,  32,   9,  27,  32,   9, 212,   1,  32,
   9, 214,   1,   4,   9, 215,   1,   4,   9, 212,   1,   4,   9, 211,   1,   4,
   9, 210,   1,   4,   9, 209,   1,   4,   9, 208,   1,   4,   9, 205,   1,   4,
   7,  56, 216,   1,   9,  19,  32,   9, 214,   1,  32,   7,  55, 214,   1,   9,
 215,   1,  32,   7,  55, 215,   1,   9, 216,   1,  33,   9, 214,   1,  34,   9,
 215,   1,  34,   9, 212,   1,  34,   9,  27,  34,   9, 211,   1,  34,   9, 210,
   1,  34,   9, 209,   1,  34,   9, 208,   1,  34,   9, 218,   1,  34,   9, 219,
   1,  35,   9, 222,   1,  35,   9, 223,   1,  35,   9, 224,   1,  35,   9, 226,
   1,   4,   9, 227,   1,   4,   9, 228,   1,   4,   9, 229,   1,   4,   9, 224,
   1,   4,   9, 223,   1,   4,   9, 222,   1,   4,   9, 219,   1,   4,   7,  61,
 230,   1,   9,  19,  35,   9, 226,   1,  35,   7,  60, 226,   1,   9, 227,   1,
  35,   7,  60, 227,   1,   9, 228,   1,  35,   7,  60, 228,   1,   9, 229,   1,
  35,   7,  60, 229,   1,   9, 230,   1,  36,   9, 226,   1,  37,   9, 227,   1,
  37,   9, 228,   1,  37,   9, 229,   1,  37,   9, 224,   1,  37,   9, 223,   1,
  37,   9, 222,   1,  37,   9, 219,   1,  37,   9, 232,   1,  38,   9, 235,   1,
  38,   9, 235,   1,   4,   9, 232,   1,   4,   7,  66, 237,   1,   9,  19,  38,
   9, 237,   1,  39,   9, 235,   1,  40,   9, 232,   1,  40,   9, 239,   1,  41,
   9, 243,   1,   4,   9, 244,   1,   4,   9, 245,   1,   4,   9, 246,   1,   4,
   9, 247,   1,   4,   9, 248,   1,   4,   9, 249,   1,   4,   9, 250,   1,   4,
   9, 251,   1,   4,   9, 252,   1,   4,   9, 253,   1,   4,   9, 254,   1,   4,
   9, 255,   1,   4,   9, 128,   2,   4,   9, 129,   2,   4,   9, 130,   2,   4,
   9, 131,   2,   4,   9, 132,   2,   4,   9, 133,   2,   4,   9, 134,   2,   4,
   9, 135,   2,   4,   9, 136,   2,   4,   9, 137,   2,   4,   9, 138,   2,   4,
   9, 139,   2,   4,   9, 140,   2,   4,   9, 141,   2,   4,   9, 142,   2,   4,
   9, 143,   2,   4,   9, 144,   2,   4,   9, 145,   2,   4,   9, 146,   2,   4,
   9, 147,   2,   4,   9, 148,   2,   4,   9, 149,   2,   4,   9, 150,   2,   4,
   9, 151,   2,   4,   9, 152,   2,   4,   9, 239,   1,   4,   7,  71, 153,   2,
   9,  19,  41,   9, 243,   1,  41,   7,  70, 243,   1,   9, 244,   1,  41,   7,
  70, 244,   1,   9, 245,   1,  41,   7,  70, 245,   1,   9, 246,   1,  41,   7,
  70, 246,   1,   9, 247,   1,  41,   7,  70, 247,   1,   9, 248,   1,  41,   7,
  70, 248,   1,   9, 249,   1,  41,   7,  70, 249,   1,   9, 250,   1,  41,   7,
  70, 250,   1,   9, 251,   1,  41,   7,  70, 251,   1,   9, 252,   1,  41,   7,
  70, 252,   1,   9, 253,   1,  41,   7,  70, 253,   1,   9, 254,   1,  41,   7,
  70, 254,   1,   9, 255,   1,  41,   7,  70, 255,   1,   9, 128,   2,  41,   7,
  70, 128,   2,   9, 129,   2,  41,   7,  70, 129,   2,   9, 130,   2,  41,   7,
  70, 130,   2,   9, 131,   2,  41,   7,  70, 131,   2,   9, 132,   2,  41,   7,
  70, 132,   2,   9, 133,   2,  41,   7,  70, 133,   2,   9, 134,   2,  41,   7,
  70, 134,   2,   9, 135,   2,  41,   7,  70, 135,   2,   9, 136,   2,  41,   7,
  70, 136,   2,   9, 137,   2,  41,   7,  70, 137,   2,   9, 138,   2,  41,   7,
  70, 138,   2,   9, 139,   2,  41,   7,  70, 139,   2,   9, 140,   2,  41,   7,
  70, 140,   2,   9, 141,   2,  41,   7,  70, 141,   2,   9, 142,   2,  41,   7,
  70, 142,   2,   9, 143,   2,  41,   7,  70, 143,   2,   9, 144,   2,  41,   7,
  70, 144,   2,   9, 145,   2,  41,   7,  70, 145,   2,   9, 146,   2,  41,   7,
  70, 146,   2,   9, 147,   2,  41,   7,  70, 147,   2,   9, 148,   2,  41,   7,
  70, 148,   2,   9, 149,   2,  41,   7,  70, 149,   2,   9, 150,   2,  41,   7,
  70, 150,   2,   9, 151,   2,  41,   7,  70, 151,   2,   9, 152,   2,  41,   7,
  70, 152,   2,   9, 153,   2,  42,   9, 243,   1,  43,   9, 244,   1,  43,   9,
 245,   1,  43,   9, 246,   1,  43,   9, 247,   1,  43,   9, 248,   1,  43,   9,
 249,   1,  43,   9, 250,   1,  43,   9, 251,   1,  43,   9, 252,   1,  43,   9,
 253,   1,  43,   9, 254,   1,  43,   9, 255,   1,  43,   9, 128,   2,  43,   9,
 129,   2,  43,   9, 130,   2,  43,   9, 131,   2,  43,   9, 132,   2,  43,   9,
 133,   2,  43,   9, 134,   2,  43,   9, 135,   2,  43,   9, 136,   2,  43,   9,
 137,   2,  43,   9, 138,   2,  43,   9, 139,   2,  43,   9, 140,   2,  43,   9,
 141,   2,  43,   9, 142,   2,  43,   9, 143,   2,  43,   9, 144,   2,  43,   9,
 145,   2,  43,   9, 146,   2,  43,   9, 147,   2,  43,   9, 148,   2,  43,   9,
 149,   2,  43,   9, 150,   2,  43,   9, 151,   2,  43,   9, 152,   2,  43,   9,
 239,   1,  43,   9, 155,   2,  44,   9, 158,   2,  44,   9, 160,   2,   4,   9,
 161,   2,   4,   9, 158,   2,   4,   9, 155,   2,   4,   7,  76, 162,   2,   9,
  19,  44,   9, 160,   2,  44,   7,  75, 160,   2,   9, 161,   2,  44,   7,  75,
 161,   2,   9, 162,   2,  45,   9, 160,   2,  46,   9, 161,   2,  46,   9, 158,
   2,  46,   9, 155,   2,  46,   7,   2, 165,   2,   7,   2, 167,   2,   9, 165,
   2,   4,   9, 167,   2,   4,   7,  14, 169,   2,   9,  19,  47,   9, 169,   2,
  22,   7,   4, 172,   2,   9, 173,   2,   4,   9, 174,   2,   4,   9, 175,   2,
   4,   9, 176,   2,   4,   9, 177,   2,   4,   9, 178,   2,   4,   9,  19,  48,
   9, 172,   2,  12, 237,   1,   0,   3,   3,   0,   0,   5,   3,   0,   0,   7,
   3,   4,   0,   7,   3,   4,   1,  11,   3,   3,   0,   0,   0,   3,   0,   0,
   0,   3,   0,   1,   7,  18,   3,  32,   1,  18,   3,   3,  32,   0,   3,   3,
  32,   1,   7,  19,   3,  32,   1,   7,   3,   3,  32,   0,   7,   3,  32,   0,
  20,   3,  32,   0,   5,   3,  32,   0,  19,   3,  32,   0,   3,   3,  32,   0,
   3,   3,  32,   0,  21,   3,  32,   0,  21,   3,  32,   0,  21,   3,  32,   0,
   7,   3,  32,   0,   7,   3,  32,   0,   0,   3,   0,   0,   0,   3,   0,   1,
  20,   3,   3,  32,   1,   3,   3,   3,  32,   2,   7,   3,   3,   3,  32,   2,
  44,   3,  20,   3,   0,   2,  20,   3,  44,   3,   0,   0,   0,   3,   0,   0,
   0,   3,   0,   0,   3,   3,   0,   0,  20,   3,   0,   0,   0,   3,   0,   0,
   0,   3,   0,   0,   0,   3,   0,   0,  66,   3,  32,   0,   5,   3,  32,   1,
   7,  66,   3,  32,   1,   0,  66,   3,   0,   1,   0,  44,   3,  32,   1,  11,
   3,   3,  32,   1,   0,   3,   3,   0,   0,  44,   3,  32,   1,   0,  44,   3,
  32,   0,   0,   3,   0,   0,   0,   3,   0,   1,  44,   3,   3,  32,   1,   7,
   3,   3,  32,   3,   7,  44,   5,   5,   3,  40,   2,   1,   3,   1,   3,   3,
   7,  44,   5,   5,   3,  40,   2,   1,   3,   1,   3,   1,   7,  20,   3,  32,
   1,   7,  18,   3,  32,   1,   7,  18,   3,  32,   1,   7,  18,   3,  32,   1,
   7,   5,   3,  32,   1,   7,  21,   3,  32,   1,   7,  21,   3,  32,   1,   7,
   3,   3,  32,   1,   7,   3,   3,  32,   0,  20,   3,  32,   0,  18,   3,  32,
   0,   5,   3,  32,   0,  18,   3,  32,   0,   5,   3,  32,   0,  18,   3,  32,
   0,   5,   3,  32,   0,  21,   3,  32,   0,  21,   3,  32,   0,   3,   3,  32,
   1,   3,   5,   3,  32,   0,   5,   3,  32,   1,   7,   5,   3,  32,   0,   7,
   3,  32,   0,   7,   3,   0,   0,   7,   3,  32,   0,   7,   3,   0,   0,   3,
   3,  32,   0,   3,   3,   0,   0,   5,   3,  32,   0,   5,   3,  32,   1,   7,
   5,   3,  32,   0,   3,   3,  32,   1,   7,   3,   3,  32,   0,   0,   3,   0,
   0,   0,   3,   0,   1,   3,   3,   3,  32,   1,  41, 121,   3,  32,   1,  19,
 121,   3,  32,   2,  20,  41, 122,   3,  32,   3,  21,  41, 122,   5,   3,  32,
   2,  21,  41, 122,   3,   0,   2,  21,  41, 122,   3,   0,   2,  21,  41, 122,
   3,   0,   0,  21,   3,  32,   0,  41,   3,  32,   2,  41,  41,  20,   3,  40,
   1,  10,  10,   1,  21,   0,   3,  32,   1,   7, 121,   3,  32,   0,   0,   3,
   2,   1,   7, 121,   3,   2,   1,   7,  20,   3,  32,   0,   7,   3,  32,   0,
   7,   3,  32,   0,   7,   3,  32,   0,   7,   3,  32,   0,   0,   3,   0,   0,
   3,   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   0,
   0,   3,   0,   0,   0,   3,  32,   0,  21,   3,  32,   0,   0,   3,   0,   0,
   0,   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   2,
   0,  18,  18,   3,  40,   1,   2,   3,   1,  18,  18,   3,  40,   1,   2,   3,
   1,   0, 121,   3,  32,   0, 121,   3,  32,   0,   0,   3,   0,   0,   0,   3,
   0,   0,   0,   3,   0,   1,   7,  20,   3,  32,   1,   0,  20,   3,   8,   1,
  10,  10,   0,   0,   3,   0,   1,  18,   3,   3,   0,   1,   3,   3,   3,   0,
   1,  18,   3,   3,   0,   3,   0,   3,   3,  20,   3,   8,   1,  10,  10,   1,
   3,   3,   3,   0,   1,   7,  18,   3,   8,   1,   1,   3,   0,   7,   3,   0,
   0,   0,   3,   0,   0,  18,   3,  32,   0,  18,   3,  32,   0,   7,   3,  32,
   1,   7,  18,   3,  40,   1,   1,   3,   1,   3,   3,   3,  32,   3,  18,   3,
   3,  18,   3,  32,   1,  18,   3,   3,  32,   1,   3,   3,   3,  32,   1,  18,
   3,   3,  32,   0,   0,   3,   0,   0,   0,   3,   0,   1,  18,   3,   3,   0,
   1,  18,   3,   3,   0,   0,   3,   3,   0,   2,  18,   3,  18,   3,   0,   0,
   0,   3,   0,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,
  18,   3,  32,   2,  18,   3,  18,   3,  32,   0,   3,   3,  32,   1,  18,   3,
   3,  32,   1,  18,   3,   3,  32,   0,   0,   3,   0,   0,   0,   3,   0,   1,
   5,   3,   3,   0,   1,   3,  18,   3,   0,   0,   0,   3,   0,   1,   3,  18,
   3,  32,   1,   5,   3,   3,  32,   0,   0,   3,   0,   0,   0,   3,   0,   1,
   7,  18,   3,   0,   0,  18,   3,   0,   0,   0,   3,   0,   0,  18,   3,  32,
   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,
   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,
   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,
   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,
   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,
   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,
   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,
   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,
   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,   0,  18,   3,  32,
   0,  18,   3,  32,   0,  18,   3,  32,   1,   7,  18,   3,  32,   0,   0,   3,
   0,   0,   0,   3,   0,   2,  18,   3,   3,   3,   0,   1,  18,   3,   3,   0,
   0,   0,   3,   0,   0,  18,   3,  32,   0,  18,   3,  32,   1,  18,   3,   3,
  32,   2,  18,   3,   3,   3,  32,   0,   0,   3,   0,   0,   0,   3,   0,   0,
   0,   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   0,   0,   3,   0,   1,
 194,   3,   3,   3,  36,   3, 194,   3, 194,   3,  18,  19,   3,  40,   1,  12,
  12,   1,  19, 194,   3,   3,  32,   1,   3,   3,   3,  36,   2,   3, 194,   3,
   3,   3,  36,   2,   3, 194,   3,   3,   3,  32,   0,   0,   3,   0,   0,   0,
   3,   0,  31,  53,   2,  54,  56,  55,  57,  53,   2,  54,  56,  58,  57,  53,
   3,  54,  70,  56,  69,  71,  57,  53,   3,  54,  70,  56, 107, 108,  57,  53,
   4,  54,  70,  56, 144,   1, 142,   1, 143,   1,  57, 145,   1,  53,   4,  54,
  70,  56, 144,   1, 146,   1, 147,   1,  57, 145,   1,  53,   4,  54,  70,  56,
 144,   1, 148,   1, 149,   1,  57, 145,   1,  53,   4,  54,  70,  56, 144,   1,
 150,   1, 151,   1,  57, 145,   1,  53,   1,   0, 153,   1,  53,   1,   0, 155,
   1,  53,   1,   0, 157,   1,  53,   1,   0, 159,   1,  53,   1,   0, 161,   1,
  53,   1,   0, 163,   1,  53,   1,   0, 165,   1,  53,   1,   0, 167,   1,  53,
   1,   0, 169,   1,  53,   1,   0, 171,   1,  53,   1,   0, 175,   1,  53,   1,
   0, 177,   1,  53,   1,   0, 179,   1,  53,   1,   0, 181,   1,  53,   1,   0,
 183,   1,  53,   2,  54,  56, 199,   1,  57,  53,   3,  54,  70,  56, 203,   1,
 204,   1,  57,  53,   2,  54,  56, 217,   1,  57,  53,   2,  54,  56, 231,   1,
  57,  53,   2,  54,  56, 238,   1,  57,  53,   2,  54,  56, 154,   2,  57,  53,
   2,  54,  56, 163,   2,  57,  53,   3,  54,  70,  56, 180,   2, 172,   2,  57,
  18,  40,  41,   9,   7,   0,  23,   0,  50,  41,   9,  12,   0,  30,   0,  54,
  41,  11,  18,   0,  34,   0,  66,  41,   9,  24,   0,  40,   6,  73,   1,   0,
  39,  74,   1,   0,  41,  75,   1,   0,  42,  76,   1,   0,  43,  77,   2,   0,
  44,  77,   3,   0,  45,  44,  41,   9,  29,   0,  85,  36,  85,   1,   0,  49,
  86,   1,   0,  50,  87,   1,   0,  51,  88,   1,   0,  52,  89,   1,   0,  53,
  90,   1,   0,  54,  91,   1,   0,  55,  92,   1,   0,  56,  93,   1,   0,  57,
  94,   1,   0,  58,  95,   1,   0,  59,  96,   1,   0,  60,  97,   1,   0,  61,
  98,   1,   0,  62,  99,   1,   0,  63, 100,   1,   0,  64, 101,   1,   0,  65,
 102,   1,   0,  66, 103,   1,   0,  67, 104,   1,   0,  68, 105,   1,   0,  69,
 106,   1,   0,  70, 107,   1,   0,  71, 108,   2,   0,  72, 108,   3,   0,  73,
 109,   1,   0,  74, 110,   1,   0,  75, 111,   1,   0,  76, 112,   1,   0,  77,
 113,   1,   0,  78, 114,   1,   0,  79, 115,   2,   0,  80, 116,   2,   0,  81,
 116,   3,   0,  82, 117,   2,   0,  83, 117,   3,   0,  84, 137,   1,  41,  11,
  36,   0, 109,   5, 133,   1,   6,   0,   3,   0, 134,   1,   6,   0,   3,   0,
 135,   1,   6,   0,   5,   0, 136,   1,   6,   0,  21,   0, 114,   1,   0, 108,
 140,   1,  41,   9,  39,   0, 111,   2, 138,   1,   6,   0,  21,   0, 139,   1,
   6,   0,  19,   0, 145,   1, 140,   1,  11,  41,   0, 115,   4, 141,   1,   6,
   0,  21,   0, 142,   1,   6,   0,  11,   0, 143,   1,   2,   0, 113, 144,   1,
   2,   0, 114, 146,   1, 140,   1,  11,  43,   0, 117,   2, 141,   1,   6,   0,
  21,   0, 144,   1,   6,   0,  21,   0, 189,   1,  41,   9,  47,   0, 124,   0,
 194,   1,  41,   8,  52,   0, 128,   1,   1, 193,   1,   1,   0, 127, 212,   1,
  41,   9,  58,   0, 147,   1,   0, 240,   1,  41,   9,  63,   0, 162,   1,   0,
 135,   2,  41,   9,  68,   0, 169,   1,   0, 180,   2,  41,   9,  73,   0, 214,
   1,   0, 176,   3,  41,   9,  78,   0, 223,   1,   0, 191,   3,  41,   9,  80,
   0, 226,   1,   0, 194,   3,  41,   9,  83,   0, 235,   1,   0,   6,  18,  22,
  17,   3,   7,  23,  17,   4,   8,  24,  17,   5,   9,  25,  17,   6,  10,  26,
  17,   7,  11,  27,  17,   8,  12,  28,  17,   9,  13,  29,  17,  10,  14,  30,
  17,  11,  15,  31,   6,   1,  19,   0,  32,  17,  12,  16,  33,   6,   2,   3,
   0,  34,  17,  13,  17,  35,  18,  14,  18,  36,  18,  15,  19,  37,  18,  16,
  20,  38,  17,  17,  21,  39,  17,  18,  22,  24,   5,  46,  17,   3,  25,  47,
  17,   4,  26,  26,  17,   5,  27,  48,  17,   6,  28,  49,  17,   7,  29,  31,
   2,  53,  18,   3,  32,  28,  18,   4,  33,  36,   2,  71,  18,   3,  37,  72,
  18,   4,  38,  47,   1,  84,  17,   3,  48, 107,   0, 110,   0, 112,   0, 116,
   0, 119,  11, 178,   1,   6,   1,  18,   1,   3, 179,   1,   6,   2,  18,   3,
   3, 180,   1,   6,   3,  18,   2,   3, 181,   1,   6,   4,  18,   4,   3, 182,
   1,   6,   5,  18,   5,   3, 183,   1,   6,   6,   0,   3,   3, 184,   1,   6,
   7,   0,   2,   3, 185,   1,  17,   3, 120, 186,   1,  17,   4, 121, 187,   1,
  17,   5, 122, 188,   1,  17,   6, 123, 126,   0, 137,   1,   9, 204,   1,  18,
   3, 138,   1, 205,   1,  18,   4, 139,   1, 206,   1,  17,   5, 140,   1,  22,
  17,   6, 141,   1, 207,   1,  17,   7, 142,   1, 208,   1,  17,   8, 143,   1,
 209,   1,  17,   9, 144,   1, 210,   1,  17,  10, 145,   1, 211,   1,  17,  11,
 146,   1, 153,   1,   8, 232,   1,  18,   3, 154,   1, 233,   1,  18,   4, 155,
   1, 234,   1,  18,   5, 156,   1, 235,   1,  18,   6, 157,   1, 236,   1,  17,
   7, 158,   1, 237,   1,  17,   8, 159,   1, 238,   1,  17,   9, 160,   1, 239,
   1,  17,  10, 161,   1, 166,   1,   2, 133,   2,  17,   3, 167,   1, 134,   2,
  17,   4, 168,   1, 173,   1,  40, 141,   2,  18,   3, 174,   1, 142,   2,  18,
   4, 175,   1, 143,   2,  18,   5, 176,   1, 144,   2,  18,   6, 177,   1, 145,
   2,  18,   7, 178,   1, 146,   2,  18,   8, 179,   1, 147,   2,  18,   9, 180,
   1, 148,   2,  18,  10, 181,   1, 149,   2,  18,  11, 182,   1, 150,   2,  18,
  12, 183,   1, 151,   2,  18,  13, 184,   1, 152,   2,  18,  14, 185,   1, 153,
   2,  18,  15, 186,   1, 154,   2,  18,  16, 187,   1, 155,   2,  18,  17, 188,
   1, 156,   2,  18,  18, 189,   1, 157,   2,  18,  19, 190,   1, 158,   2,  18,
  20, 191,   1, 159,   2,  18,  21, 192,   1, 160,   2,  18,  22, 193,   1, 161,
   2,  18,  23, 194,   1, 162,   2,  18,  24, 195,   1, 163,   2,  18,  25, 196,
   1, 164,   2,  18,  26, 197,   1, 165,   2,  18,  27, 198,   1, 166,   2,  18,
  28, 199,   1, 167,   2,  18,  29, 200,   1, 168,   2,  18,  30, 201,   1, 169,
   2,  18,  31, 202,   1, 170,   2,  18,  32, 203,   1, 171,   2,  18,  33, 204,
   1, 172,   2,  18,  34, 205,   1, 173,   2,  18,  35, 206,   1, 174,   2,  18,
  36, 207,   1, 175,   2,  18,  37, 208,   1, 176,   2,  18,  38, 209,   1, 177,
   2,  18,  39, 210,   1, 178,   2,  18,  40, 211,   1, 179,   2,  18,  41, 212,
   1, 179,   2,  19,  42, 213,   1, 218,   1,   4, 172,   3,  18,   3, 219,   1,
 173,   3,  18,   4, 220,   1, 174,   3,  17,   5, 221,   1, 175,   3,  17,   6,
 222,   1, 225,   1,   2, 189,   3,   6,   1,   3, 166,   2,   1, 190,   3,   6,
   2,   3, 168,   2,   1, 228,   1,   6, 195,   3,  17,   3, 229,   1, 196,   3,
  17,   4, 230,   1, 197,   3,  17,   5, 231,   1, 198,   3,  17,   6, 232,   1,
 199,   3,  17,   7, 233,   1, 200,   3,  17,   8, 234,   1,  13,  46,   1,  80,
  68,   0,   3,   1,   2,  86,   1, 120,  68,   0,   4,   1,   3, 118,  23, 148,
   1,  68,   1,   5,   1,   4, 149,   1,  68,   2,   6,   1,   5, 150,   1,  68,
   3,   7,   1,   6, 151,   1,  68,   4,   8,   1,   7, 152,   1,  65,   7, 106,
   1,   8, 153,   1,  65,   8, 105,   1,   9, 154,   1,  65,   9, 104,   1,  10,
 155,   1,  65,  10, 103,   1,  11, 156,   1,  65,  11, 102,   1,  12, 157,   1,
   1,  12, 101, 158,   1,  65,  13,  99,   1,  13, 159,   1,  65,  14,  98,   1,
  14, 160,   1,  65,  15,  97,   1,  15, 161,   1,  65,  16,  96,   1,  16, 162,
   1,  65,  17,  95,   1,  17, 163,   1,   1,  18,  94, 164,   1,   1,  19,  93,
 165,   1,   1,  20,  92, 166,   1,  65,  21,  91,   1,  18, 167,   1,  65,  22,
  90,   1,  19, 168,   1,  65,  23,  89,   1,  20, 169,   1,  65,  24,  88,   1,
  21, 170,   1,  65,  25,  87,   1,  22, 125,   1, 191,   1,  68,   1,   9,   1,
  23, 129,   1,   1, 196,   1,  68,   1,  10,   1,  24, 148,   1,  10, 218,   1,
  68,   1,  11,   1,  25, 219,   1,   6,   2,  18,   0, 220,   1,   6,   3,  18,
   0, 221,   1,   1,  26, 136,   1, 222,   1,   1,  27, 135,   1, 223,   1,   1,
  28, 134,   1, 224,   1,   1,  29, 133,   1, 225,   1,   1,  30, 132,   1, 226,
   1,   1,  31, 131,   1, 227,   1,   1,  32, 130,   1, 163,   1,   9, 250,   1,
  68,   1,  12,   1,  26, 251,   1,   6,   2,  18,   0, 252,   1,   6,   3,  18,
   0, 253,   1,   6,   4,  18,   0, 254,   1,   6,   5,  18,   0, 255,   1,   1,
  33, 152,   1, 128,   2,   1,  34, 151,   1, 129,   2,   1,  35, 150,   1, 130,
   2,   1,  36, 149,   1, 170,   1,   3, 137,   2,  68,   1,  13,   1,  27, 138,
   2,   1,  37, 165,   1, 139,   2,   1,  38, 164,   1, 215,   1,  41, 130,   3,
  68,   1,  14,   1,  28, 131,   3,   6,   2,  18,   0, 132,   3,   6,   3,  18,
   0, 133,   3,   6,   4,  18,   0, 134,   3,   6,   5,  18,   0, 135,   3,   6,
   6,  18,   0, 136,   3,   6,   7,  18,   0, 137,   3,   6,   8,  18,   0, 138,
   3,   6,   9,  18,   0, 139,   3,   6,  10,  18,   0, 140,   3,   6,  11,  18,
   0, 141,   3,   6,  12,  18,   0, 142,   3,   6,  13,  18,   0, 143,   3,   6,
  14,  18,   0, 144,   3,   6,  15,  18,   0, 145,   3,   6,  16,  18,   0, 146,
   3,   6,  17,  18,   0, 147,   3,   6,  18,  18,   0, 148,   3,   6,  19,  18,
   0, 149,   3,   6,  20,  18,   0, 150,   3,   6,  21,  18,   0, 151,   3,   6,
  22,  18,   0, 152,   3,   6,  23,  18,   0, 153,   3,   6,  24,  18,   0, 154,
   3,   6,  25,  18,   0, 155,   3,   6,  26,  18,   0, 156,   3,   6,  27,  18,
   0, 157,   3,   6,  28,  18,   0, 158,   3,   6,  29,  18,   0, 159,   3,   6,
  30,  18,   0, 160,   3,   6,  31,  18,   0, 161,   3,   6,  32,  18,   0, 162,
   3,   6,  33,  18,   0, 163,   3,   6,  34,  18,   0, 164,   3,   6,  35,  18,
   0, 165,   3,   6,  36,  18,   0, 166,   3,   6,  37,  18,   0, 167,   3,   6,
  38,  18,   0, 168,   3,   6,  39,  18,   0, 169,   3,   2,  39, 172,   1, 169,
   3,   3,  40, 171,   1, 224,   1,   5, 182,   3,  68,   1,  15,   1,  29, 183,
   3,   6,   2,  18,   0, 184,   3,   6,   3,  18,   0, 185,   3,   1,  41, 217,
   1, 186,   3,   1,  42, 216,   1, 227,   1,   1, 193,   3,   4,   1,  16, 236,
   1,   1, 202,   3,  68,   1,  17,   1,  30,  35,   9,  60,  68,   0,   0,   1,
   0,  61,  68,   0,   1,   1,   1,  62,   1,   1,   5,  63,   4,   0,   2,  64,
   1,   2,   4,  65,   1,   3,   3,  25,   1,   4,   2,  29,   1,   5,   1,  34,
   1,   6,   0,  86,   0,   1,   1,   1,   2,  10, 208,  48,  93,   1, 102,   1,
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
   1, 104, 217,   1,  71,   0,   0, 149,   1,   2,   2,   1,   2,  11, 208,  48,
 100, 108,   1, 209,  70, 228,   1,   1,  72,   0,   0, 150,   1,   2,   2,   1,
   2,  11, 208,  48, 100, 108,   1, 209,  70, 229,   1,   1,  72,   0,   0, 151,
   1,   1,   1,   1,   2,  10, 208,  48, 100, 108,   1,  70, 230,   1,   0,  72,
   0,   0, 152,   1,   3,   3,   1,   2,  12, 208,  48, 100, 108,   1, 209, 210,
  70, 231,   1,   2,  72,   0,   0, 153,   1,   1,   1,   3,   4,   3, 208,  48,
  71,   0,   0, 162,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,
   0,   0, 163,   1,   2,   1,   1,   3,  66, 208,  48, 101,   0,  93,  41, 102,
  41,  48,  93, 241,   1, 102, 241,   1,  88,  12,  29, 104, 240,   1, 101,   0,
 100, 108,   1, 102, 242,   1, 104, 243,   1, 101,   0, 100, 108,   1, 102, 244,
   1, 104, 245,   1, 101,   0, 100, 108,   1, 102, 246,   1, 104, 247,   1, 101,
   0, 100, 108,   1, 102, 248,   1, 104, 249,   1,  71,   0,   0, 164,   1,   2,
   2,   1,   2,  11, 208,  48, 100, 108,   1, 209,  70, 131,   2,   1,  72,   0,
   0, 165,   1,   2,   2,   1,   2,  11, 208,  48, 100, 108,   1, 209,  70, 132,
   2,   1,  72,   0,   0, 166,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,
   0, 169,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0,
 170,   1,   2,   1,   1,   3,  22, 208,  48, 101,   0,  93,  41, 102,  41,  48,
  93, 136,   2, 102, 136,   2,  88,  13,  29, 104, 135,   2,  71,   0,   0, 171,
   1,   2,   2,   1,   2,  10, 208,  48, 100, 108,   1, 209,  97, 140,   2,  71,
   0,   0, 172,   1,   1,   1,   1,   2,   9, 208,  48, 100, 108,   1, 102, 140,
   2,  72,   0,   0, 173,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,
 214,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 215,
   1,   2,   1,   1,   3, 184,   3, 208,  48, 101,   0,  93,  41, 102,  41,  48,
  93, 181,   2, 102, 181,   2,  88,  14,  29, 104, 180,   2, 101,   0, 100, 108,
   1, 102, 182,   2, 104, 183,   2, 101,   0, 100, 108,   1, 102, 184,   2, 104,
 185,   2, 101,   0, 100, 108,   1, 102, 186,   2, 104, 187,   2, 101,   0, 100,
 108,   1, 102, 188,   2, 104, 189,   2, 101,   0, 100, 108,   1, 102, 190,   2,
 104, 191,   2, 101,   0, 100, 108,   1, 102, 192,   2, 104, 193,   2, 101,   0,
 100, 108,   1, 102, 194,   2, 104, 195,   2, 101,   0, 100, 108,   1, 102, 196,
   2, 104, 197,   2, 101,   0, 100, 108,   1, 102, 198,   2, 104, 199,   2, 101,
   0, 100, 108,   1, 102, 200,   2, 104, 201,   2, 101,   0, 100, 108,   1, 102,
 202,   2, 104, 203,   2, 101,   0, 100, 108,   1, 102, 204,   2, 104, 205,   2,
 101,   0, 100, 108,   1, 102, 206,   2, 104, 207,   2, 101,   0, 100, 108,   1,
 102, 208,   2, 104, 209,   2, 101,   0, 100, 108,   1, 102, 210,   2, 104, 211,
   2, 101,   0, 100, 108,   1, 102, 212,   2, 104, 213,   2, 101,   0, 100, 108,
   1, 102, 214,   2, 104, 215,   2, 101,   0, 100, 108,   1, 102, 216,   2, 104,
 217,   2, 101,   0, 100, 108,   1, 102, 218,   2, 104, 219,   2, 101,   0, 100,
 108,   1, 102, 220,   2, 104, 221,   2, 101,   0, 100, 108,   1, 102, 222,   2,
 104, 223,   2, 101,   0, 100, 108,   1, 102, 224,   2, 104, 225,   2, 101,   0,
 100, 108,   1, 102, 226,   2, 104, 227,   2, 101,   0, 100, 108,   1, 102, 228,
   2, 104, 229,   2, 101,   0, 100, 108,   1, 102, 230,   2, 104, 231,   2, 101,
   0, 100, 108,   1, 102, 232,   2, 104, 233,   2, 101,   0, 100, 108,   1, 102,
 234,   2, 104, 235,   2, 101,   0, 100, 108,   1, 102, 236,   2, 104, 237,   2,
 101,   0, 100, 108,   1, 102, 238,   2, 104, 239,   2, 101,   0, 100, 108,   1,
 102, 240,   2, 104, 241,   2, 101,   0, 100, 108,   1, 102, 242,   2, 104, 243,
   2, 101,   0, 100, 108,   1, 102, 244,   2, 104, 245,   2, 101,   0, 100, 108,
   1, 102, 246,   2, 104, 247,   2, 101,   0, 100, 108,   1, 102, 248,   2, 104,
 249,   2, 101,   0, 100, 108,   1, 102, 250,   2, 104, 251,   2, 101,   0, 100,
 108,   1, 102, 252,   2, 104, 253,   2, 101,   0, 100, 108,   1, 102, 254,   2,
 104, 255,   2, 101,   0, 100, 108,   1, 102, 128,   3, 104, 129,   3,  71,   0,
   0, 216,   1,   3,   3,   1,   2,  12, 208,  48, 100, 108,   1, 209, 210,  70,
 170,   3,   2,  72,   0,   0, 217,   1,   2,   2,   1,   2,  11, 208,  48, 100,
 108,   1, 209,  70, 171,   3,   1,  72,   0,   0, 218,   1,   1,   1,   3,   4,
   3, 208,  48,  71,   0,   0, 223,   1,   1,   1,   4,   5,   6, 208,  48, 208,
  73,   0,  71,   0,   0, 224,   1,   2,   1,   1,   3,  44, 208,  48, 101,   0,
  93,  41, 102,  41,  48,  93, 177,   3, 102, 177,   3,  88,  15,  29, 104, 176,
   3, 101,   0, 100, 108,   1, 102, 178,   3, 104, 179,   3, 101,   0, 100, 108,
   1, 102, 180,   3, 104, 181,   3,  71,   0,   0, 225,   1,   2,   1,   3,   4,
  21, 208,  48,  94, 187,   3,  44, 166,   2, 104, 187,   3,  94, 188,   3,  44,
 168,   2, 104, 188,   3,  71,   0,   0, 226,   1,   1,   1,   4,   5,   6, 208,
  48, 208,  73,   0,  71,   0,   0, 227,   1,   2,   1,   1,   3,  22, 208,  48,
 101,   0,  93,  41, 102,  41,  48,  93, 192,   3, 102, 192,   3,  88,  16,  29,
 104, 191,   3,  71,   0,   0, 228,   1,   1,   1,   3,   4,   3, 208,  48,  71,
   0,   0, 235,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,
   0, 236,   1,   2,   1,   1,   3,  22, 208,  48, 101,   0,  93,  41, 102,  41,
  48,  93, 201,   3, 102, 201,   3,  88,  17,  29, 104, 194,   3,  71,   0,   0
};

} }
