/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/* machine generated file -- do not edit */

#ifndef _H_nativegen_classes_shell_toplevel
#define _H_nativegen_classes_shell_toplevel

namespace avmplus {

//-----------------------------------------------------------
// C.errno::__errno
//-----------------------------------------------------------
class __errnoObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmshell::CErrnoClass;
    REALLY_INLINE explicit __errnoObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit __errnoObject(const __errnoObject&); // unimplemented
    void operator=(const __errnoObject&); // unimplemented
};

#define avmplus___errnoObject_isExactInterlock 1
//-----------------------------------------------------------
// C.errno::ErrorNumber
//-----------------------------------------------------------
class ErrorNumberObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    REALLY_INLINE int32_t get__value() const { return m_slots_ErrorNumberObject.m_private__value; }
    REALLY_INLINE void set__value(int32_t newVal) { m_slots_ErrorNumberObject.m_private__value = newVal; }
private:
    avmplus::NativeID::avmplus_ErrorNumberObjectSlots m_slots_ErrorNumberObject;
protected:
    friend class avmplus::ErrorNumberClass;
    REALLY_INLINE explicit ErrorNumberObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit ErrorNumberObject(const ErrorNumberObject&); // unimplemented
    void operator=(const ErrorNumberObject&); // unimplemented
};

#define avmplus_ErrorNumberObject_isExactInterlock 1
//-----------------------------------------------------------
// C.errno::ErrorNumber$
//-----------------------------------------------------------
class ErrorNumberClass : public avmplus::ClassClosure
{
    GC_DECLARE_EXACT_METHODS
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    inline GCRef<avmplus::ErrorNumberObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::ErrorNumberObject>((avmplus::ErrorNumberObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::ErrorNumberObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::ErrorNumberObject>((avmplus::ErrorNumberObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::ErrorNumberObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::ErrorNumberObject>((avmplus::ErrorNumberObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::ErrorNumberObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::ErrorNumberObject>((avmplus::ErrorNumberObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::ErrorNumberObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::ErrorNumberObject>((avmplus::ErrorNumberObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit ErrorNumberClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit ErrorNumberClass(const ErrorNumberClass&); // unimplemented
    void operator=(const ErrorNumberClass&); // unimplemented
};

#define avmplus_ErrorNumberClass_isExactInterlock 1
//-----------------------------------------------------------
// C.errno::CError
//-----------------------------------------------------------
class CErrorObject : public avmplus::ErrorObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::CErrorClass;
    REALLY_INLINE explicit CErrorObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ErrorObject(ivtable, delegate) {}
private:
    explicit CErrorObject(const CErrorObject&); // unimplemented
    void operator=(const CErrorObject&); // unimplemented
};

#define avmplus_CErrorObject_isExactInterlock 1
//-----------------------------------------------------------
// C.errno::CError$
//-----------------------------------------------------------
class CErrorClass : public avmplus::ClassClosure
{
    GC_DECLARE_EXACT_METHODS
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    inline GCRef<avmplus::CErrorObject> constructObject(int32_t arg1)
    {
        avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core()));
        avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->intToAtom(arg1) };
        avmplus::Atom const result = this->construct(1, args);
        return GCRef<avmplus::CErrorObject>((avmplus::CErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::CErrorObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::CErrorObject>((avmplus::CErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::CErrorObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::CErrorObject>((avmplus::CErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::CErrorObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::CErrorObject>((avmplus::CErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::CErrorObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::CErrorObject>((avmplus::CErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::CErrorObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::CErrorObject>((avmplus::CErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit CErrorClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit CErrorClass(const CErrorClass&); // unimplemented
    void operator=(const CErrorClass&); // unimplemented
};

#define avmplus_CErrorClass_isExactInterlock 1
//-----------------------------------------------------------
// C.stdlib::__stdlib
//-----------------------------------------------------------
class __stdlibObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmshell::CStdlibClass;
    REALLY_INLINE explicit __stdlibObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit __stdlibObject(const __stdlibObject&); // unimplemented
    void operator=(const __stdlibObject&); // unimplemented
};

#define avmplus___stdlibObject_isExactInterlock 1
//-----------------------------------------------------------
// C.unistd::__unistd
//-----------------------------------------------------------
class __unistdObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmshell::CUnistdClass;
    REALLY_INLINE explicit __unistdObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit __unistdObject(const __unistdObject&); // unimplemented
    void operator=(const __unistdObject&); // unimplemented
};

#define avmplus___unistdObject_isExactInterlock 1
//-----------------------------------------------------------
// C.string::__string
//-----------------------------------------------------------
class __stringObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmshell::CStringClass;
    REALLY_INLINE explicit __stringObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit __stringObject(const __stringObject&); // unimplemented
    void operator=(const __stringObject&); // unimplemented
};

#define avmplus___stringObject_isExactInterlock 1
//-----------------------------------------------------------
// C.stdio::__stdio
//-----------------------------------------------------------
class __stdioObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmshell::CStdioClass;
    REALLY_INLINE explicit __stdioObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit __stdioObject(const __stdioObject&); // unimplemented
    void operator=(const __stdioObject&); // unimplemented
};

#define avmplus___stdioObject_isExactInterlock 1
//-----------------------------------------------------------
// C.socket::__socket
//-----------------------------------------------------------
class __socketObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmshell::CSocketClass;
    REALLY_INLINE explicit __socketObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit __socketObject(const __socketObject&); // unimplemented
    void operator=(const __socketObject&); // unimplemented
};

#define avmplus___socketObject_isExactInterlock 1
//-----------------------------------------------------------
// shell::Program
//-----------------------------------------------------------
class ProgramObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmshell::ProgramClass;
    REALLY_INLINE explicit ProgramObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit ProgramObject(const ProgramObject&); // unimplemented
    void operator=(const ProgramObject&); // unimplemented
};

#define avmplus_ProgramObject_isExactInterlock 1
//-----------------------------------------------------------
// shell::FileIO
//-----------------------------------------------------------
class FileIOObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmshell::FileClass;
    REALLY_INLINE explicit FileIOObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit FileIOObject(const FileIOObject&); // unimplemented
    void operator=(const FileIOObject&); // unimplemented
};

#define avmplus_FileIOObject_isExactInterlock 1
//-----------------------------------------------------------
// shell::Environment
//-----------------------------------------------------------
class EnvironmentObject : public avmplus::ProxyObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    REALLY_INLINE avmplus::ArrayObject* get__vars() const { return m_slots_EnvironmentObject.m_private__vars; }
    REALLY_INLINE void set__vars(avmplus::ArrayObject* newVal) { m_slots_EnvironmentObject.m_private__vars = newVal; }
protected:
    REALLY_INLINE avmplus::ArrayObject* get__idx() const { return m_slots_EnvironmentObject.m_private__idx; }
    REALLY_INLINE void set__idx(avmplus::ArrayObject* newVal) { m_slots_EnvironmentObject.m_private__idx = newVal; }
protected:
    REALLY_INLINE avmplus::Atom get__env() const { return m_slots_EnvironmentObject.m_private__env; }
    REALLY_INLINE void set__env(avmplus::Atom newVal) { m_slots_EnvironmentObject.m_private__env = newVal; }
private:
    avmplus::NativeID::avmplus_EnvironmentObjectSlots m_slots_EnvironmentObject;
protected:
    friend class avmplus::EnvironmentClass;
    REALLY_INLINE explicit EnvironmentObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ProxyObject(ivtable, delegate) {}
private:
    explicit EnvironmentObject(const EnvironmentObject&); // unimplemented
    void operator=(const EnvironmentObject&); // unimplemented
};

#define avmplus_EnvironmentObject_isExactInterlock 1
//-----------------------------------------------------------
// shell::Environment$
//-----------------------------------------------------------
class EnvironmentClass : public avmplus::ClassClosure
{
    GC_DECLARE_EXACT_METHODS
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    inline GCRef<avmplus::EnvironmentObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::EnvironmentObject>((avmplus::EnvironmentObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::EnvironmentObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::EnvironmentObject>((avmplus::EnvironmentObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::EnvironmentObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::EnvironmentObject>((avmplus::EnvironmentObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::EnvironmentObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::EnvironmentObject>((avmplus::EnvironmentObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::EnvironmentObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::EnvironmentObject>((avmplus::EnvironmentObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit EnvironmentClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit EnvironmentClass(const EnvironmentClass&); // unimplemented
    void operator=(const EnvironmentClass&); // unimplemented
};

#define avmplus_EnvironmentClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.utils::Endian
//-----------------------------------------------------------
class EndianObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::EndianClass;
    REALLY_INLINE explicit EndianObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit EndianObject(const EndianObject&); // unimplemented
    void operator=(const EndianObject&); // unimplemented
};

#define avmplus_EndianObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.utils::Endian$
//-----------------------------------------------------------
class EndianClass : public avmplus::ClassClosure
{
    GC_DECLARE_EXACT_METHODS
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    inline GCRef<avmplus::EndianObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::EndianObject>((avmplus::EndianObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::EndianObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::EndianObject>((avmplus::EndianObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::EndianObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::EndianObject>((avmplus::EndianObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::EndianObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::EndianObject>((avmplus::EndianObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::EndianObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::EndianObject>((avmplus::EndianObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::String* get_BIG_ENDIAN() const { return m_slots_EndianClass.m_BIG_ENDIAN; }
    REALLY_INLINE void setconst_BIG_ENDIAN(avmplus::String* newVal) { m_slots_EndianClass.m_BIG_ENDIAN = newVal; }
public:
    REALLY_INLINE avmplus::String* get_LITTLE_ENDIAN() const { return m_slots_EndianClass.m_LITTLE_ENDIAN; }
    REALLY_INLINE void setconst_LITTLE_ENDIAN(avmplus::String* newVal) { m_slots_EndianClass.m_LITTLE_ENDIAN = newVal; }
private:
    avmplus::NativeID::avmplus_EndianClassSlots m_slots_EndianClass;
protected:
    inline explicit EndianClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit EndianClass(const EndianClass&); // unimplemented
    void operator=(const EndianClass&); // unimplemented
};

#define avmplus_EndianClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.system::Capabilities
//-----------------------------------------------------------
class CapabilitiesObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::CapabilitiesClass;
    REALLY_INLINE explicit CapabilitiesObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit CapabilitiesObject(const CapabilitiesObject&); // unimplemented
    void operator=(const CapabilitiesObject&); // unimplemented
};

#define avmplus_CapabilitiesObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.system::Capabilities$
//-----------------------------------------------------------
class CapabilitiesClass : public avmplus::ClassClosure
{
    GC_DECLARE_EXACT_METHODS
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    inline GCRef<avmplus::CapabilitiesObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::CapabilitiesObject>((avmplus::CapabilitiesObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::CapabilitiesObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::CapabilitiesObject>((avmplus::CapabilitiesObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::CapabilitiesObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::CapabilitiesObject>((avmplus::CapabilitiesObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::CapabilitiesObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::CapabilitiesObject>((avmplus::CapabilitiesObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::CapabilitiesObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::CapabilitiesObject>((avmplus::CapabilitiesObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit CapabilitiesClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit CapabilitiesClass(const CapabilitiesClass&); // unimplemented
    void operator=(const CapabilitiesClass&); // unimplemented
};

#define avmplus_CapabilitiesClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.sampler::StackFrame
//-----------------------------------------------------------
class StackFrameObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE uint32_t get_line() const { return m_slots_StackFrameObject.m_line; }
    REALLY_INLINE void setconst_line(uint32_t newVal) { m_slots_StackFrameObject.m_line = newVal; }
public:
    REALLY_INLINE avmplus::String* get_name() const { return m_slots_StackFrameObject.m_name; }
    REALLY_INLINE void setconst_name(avmplus::String* newVal) { m_slots_StackFrameObject.m_name = newVal; }
public:
    REALLY_INLINE avmplus::String* get_file() const { return m_slots_StackFrameObject.m_file; }
    REALLY_INLINE void setconst_file(avmplus::String* newVal) { m_slots_StackFrameObject.m_file = newVal; }
public:
    REALLY_INLINE double get_scriptID() const { return m_slots_StackFrameObject.m_scriptID; }
    REALLY_INLINE void setconst_scriptID(double newVal) { m_slots_StackFrameObject.m_scriptID = newVal; }
private:
    avmplus::NativeID::avmplus_StackFrameObjectSlots m_slots_StackFrameObject;
protected:
    friend class avmplus::StackFrameClass;
    REALLY_INLINE explicit StackFrameObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit StackFrameObject(const StackFrameObject&); // unimplemented
    void operator=(const StackFrameObject&); // unimplemented
};

#define avmplus_StackFrameObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.sampler::StackFrame$
//-----------------------------------------------------------
class StackFrameClass : public avmplus::ClassClosure
{
    GC_DECLARE_EXACT_METHODS
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    inline GCRef<avmplus::StackFrameObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::StackFrameObject>((avmplus::StackFrameObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::StackFrameObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::StackFrameObject>((avmplus::StackFrameObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::StackFrameObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::StackFrameObject>((avmplus::StackFrameObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::StackFrameObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::StackFrameObject>((avmplus::StackFrameObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::StackFrameObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::StackFrameObject>((avmplus::StackFrameObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit StackFrameClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit StackFrameClass(const StackFrameClass&); // unimplemented
    void operator=(const StackFrameClass&); // unimplemented
};

#define avmplus_StackFrameClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.sampler::Sample
//-----------------------------------------------------------
class SampleObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::ArrayObject* get_stack() const { return m_slots_SampleObject.m_stack; }
    REALLY_INLINE void setconst_stack(avmplus::ArrayObject* newVal) { m_slots_SampleObject.m_stack = newVal; }
public:
    REALLY_INLINE double get_time() const { return m_slots_SampleObject.m_time; }
    REALLY_INLINE void setconst_time(double newVal) { m_slots_SampleObject.m_time = newVal; }
private:
    avmplus::NativeID::avmplus_SampleObjectSlots m_slots_SampleObject;
protected:
    friend class avmplus::SampleClass;
    REALLY_INLINE explicit SampleObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit SampleObject(const SampleObject&); // unimplemented
    void operator=(const SampleObject&); // unimplemented
};

#define avmplus_SampleObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.sampler::Sample$
//-----------------------------------------------------------
class SampleClass : public avmplus::ClassClosure
{
    GC_DECLARE_EXACT_METHODS
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    inline GCRef<avmplus::SampleObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::SampleObject>((avmplus::SampleObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::SampleObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::SampleObject>((avmplus::SampleObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SampleObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::SampleObject>((avmplus::SampleObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SampleObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::SampleObject>((avmplus::SampleObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SampleObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::SampleObject>((avmplus::SampleObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit SampleClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit SampleClass(const SampleClass&); // unimplemented
    void operator=(const SampleClass&); // unimplemented
};

#define avmplus_SampleClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.sampler::ClassFactory
//-----------------------------------------------------------
class ClassFactoryObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::ClassFactoryClass;
    REALLY_INLINE explicit ClassFactoryObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit ClassFactoryObject(const ClassFactoryObject&); // unimplemented
    void operator=(const ClassFactoryObject&); // unimplemented
};

#define avmplus_ClassFactoryObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.sampler::ClassFactory$
//-----------------------------------------------------------
class ClassFactoryClass : public avmplus::ClassClosure
{
    GC_DECLARE_EXACT_METHODS
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    inline GCRef<avmplus::ClassFactoryObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::ClassFactoryObject>((avmplus::ClassFactoryObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::ClassFactoryObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::ClassFactoryObject>((avmplus::ClassFactoryObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::ClassFactoryObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::ClassFactoryObject>((avmplus::ClassFactoryObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::ClassFactoryObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::ClassFactoryObject>((avmplus::ClassFactoryObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::ClassFactoryObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::ClassFactoryObject>((avmplus::ClassFactoryObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::ClassClosure* get_StackFrameClass() const { return m_slots_ClassFactoryClass.m_StackFrameClass; }
    REALLY_INLINE void setconst_StackFrameClass(avmplus::ClassClosure* newVal) { m_slots_ClassFactoryClass.m_StackFrameClass = newVal; }
public:
    REALLY_INLINE avmplus::ClassClosure* get_SampleClass() const { return m_slots_ClassFactoryClass.m_SampleClass; }
    REALLY_INLINE void setconst_SampleClass(avmplus::ClassClosure* newVal) { m_slots_ClassFactoryClass.m_SampleClass = newVal; }
public:
    REALLY_INLINE avmplus::ClassClosure* get_DeleteObjectSampleClass() const { return m_slots_ClassFactoryClass.m_DeleteObjectSampleClass; }
    REALLY_INLINE void setconst_DeleteObjectSampleClass(avmplus::ClassClosure* newVal) { m_slots_ClassFactoryClass.m_DeleteObjectSampleClass = newVal; }
public:
    REALLY_INLINE avmplus::ClassClosure* get_NewObjectSampleClass() const { return m_slots_ClassFactoryClass.m_NewObjectSampleClass; }
    REALLY_INLINE void setconst_NewObjectSampleClass(avmplus::ClassClosure* newVal) { m_slots_ClassFactoryClass.m_NewObjectSampleClass = newVal; }
private:
    avmplus::NativeID::avmplus_ClassFactoryClassSlots m_slots_ClassFactoryClass;
protected:
    inline explicit ClassFactoryClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit ClassFactoryClass(const ClassFactoryClass&); // unimplemented
    void operator=(const ClassFactoryClass&); // unimplemented
};

#define avmplus_ClassFactoryClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.trace::Trace
//-----------------------------------------------------------
class TraceObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::TraceClass;
    REALLY_INLINE explicit TraceObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit TraceObject(const TraceObject&); // unimplemented
    void operator=(const TraceObject&); // unimplemented
};

#define avmplus_TraceObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.system::WorkerState
//-----------------------------------------------------------
class WorkerStateObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::WorkerStateClass;
    REALLY_INLINE explicit WorkerStateObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit WorkerStateObject(const WorkerStateObject&); // unimplemented
    void operator=(const WorkerStateObject&); // unimplemented
};

#define avmplus_WorkerStateObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.system::WorkerState$
//-----------------------------------------------------------
class WorkerStateClass : public avmplus::ClassClosure
{
    GC_DECLARE_EXACT_METHODS
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    inline GCRef<avmplus::WorkerStateObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::WorkerStateObject>((avmplus::WorkerStateObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::WorkerStateObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::WorkerStateObject>((avmplus::WorkerStateObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::WorkerStateObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::WorkerStateObject>((avmplus::WorkerStateObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::WorkerStateObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::WorkerStateObject>((avmplus::WorkerStateObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::WorkerStateObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::WorkerStateObject>((avmplus::WorkerStateObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::String* get_NEW() const { return m_slots_WorkerStateClass.m_NEW; }
    REALLY_INLINE void setconst_NEW(avmplus::String* newVal) { m_slots_WorkerStateClass.m_NEW = newVal; }
public:
    REALLY_INLINE avmplus::String* get_RUNNING() const { return m_slots_WorkerStateClass.m_RUNNING; }
    REALLY_INLINE void setconst_RUNNING(avmplus::String* newVal) { m_slots_WorkerStateClass.m_RUNNING = newVal; }
public:
    REALLY_INLINE avmplus::String* get_TERMINATED() const { return m_slots_WorkerStateClass.m_TERMINATED; }
    REALLY_INLINE void setconst_TERMINATED(avmplus::String* newVal) { m_slots_WorkerStateClass.m_TERMINATED = newVal; }
public:
    REALLY_INLINE avmplus::String* get_FAILED() const { return m_slots_WorkerStateClass.m_FAILED; }
    REALLY_INLINE void setconst_FAILED(avmplus::String* newVal) { m_slots_WorkerStateClass.m_FAILED = newVal; }
public:
    REALLY_INLINE avmplus::String* get_ABORTED() const { return m_slots_WorkerStateClass.m_ABORTED; }
    REALLY_INLINE void setconst_ABORTED(avmplus::String* newVal) { m_slots_WorkerStateClass.m_ABORTED = newVal; }
public:
    REALLY_INLINE avmplus::String* get_EXCEPTION() const { return m_slots_WorkerStateClass.m_EXCEPTION; }
    REALLY_INLINE void setconst_EXCEPTION(avmplus::String* newVal) { m_slots_WorkerStateClass.m_EXCEPTION = newVal; }
private:
    avmplus::NativeID::avmplus_WorkerStateClassSlots m_slots_WorkerStateClass;
protected:
    inline explicit WorkerStateClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit WorkerStateClass(const WorkerStateClass&); // unimplemented
    void operator=(const WorkerStateClass&); // unimplemented
};

#define avmplus_WorkerStateClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.system::WorkerEvent
//-----------------------------------------------------------
class WorkerEventObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    REALLY_INLINE avmplus::String* get_m_previousState() const { return m_slots_WorkerEventObject.m_private_m_previousState; }
    REALLY_INLINE void set_m_previousState(avmplus::String* newVal) { m_slots_WorkerEventObject.m_private_m_previousState = newVal; }
protected:
    REALLY_INLINE avmplus::String* get_m_currentState() const { return m_slots_WorkerEventObject.m_private_m_currentState; }
    REALLY_INLINE void set_m_currentState(avmplus::String* newVal) { m_slots_WorkerEventObject.m_private_m_currentState = newVal; }
protected:
    REALLY_INLINE avmplus::Atom get_m_target() const { return m_slots_WorkerEventObject.m_flash_system_m_target; }
    REALLY_INLINE void set_m_target(avmplus::Atom newVal) { m_slots_WorkerEventObject.m_flash_system_m_target = newVal; }
private:
    avmplus::NativeID::avmplus_WorkerEventObjectSlots m_slots_WorkerEventObject;
protected:
    friend class avmplus::WorkerEventClass;
    REALLY_INLINE explicit WorkerEventObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit WorkerEventObject(const WorkerEventObject&); // unimplemented
    void operator=(const WorkerEventObject&); // unimplemented
};

#define avmplus_WorkerEventObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.system::WorkerEvent$
//-----------------------------------------------------------
class WorkerEventClass : public avmplus::ClassClosure
{
    GC_DECLARE_EXACT_METHODS
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    inline GCRef<avmplus::WorkerEventObject> constructObject(GCRef<avmplus::String> arg1, GCRef<avmplus::String> arg2)
    {
        avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom(), arg2->atom() };
        avmplus::Atom const result = this->construct(2, args);
        return GCRef<avmplus::WorkerEventObject>((avmplus::WorkerEventObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::WorkerEventObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::WorkerEventObject>((avmplus::WorkerEventObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::WorkerEventObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::WorkerEventObject>((avmplus::WorkerEventObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::WorkerEventObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::WorkerEventObject>((avmplus::WorkerEventObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::WorkerEventObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::WorkerEventObject>((avmplus::WorkerEventObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::String* get_WORKER_STATE() const { return m_slots_WorkerEventClass.m_WORKER_STATE; }
    REALLY_INLINE void setconst_WORKER_STATE(avmplus::String* newVal) { m_slots_WorkerEventClass.m_WORKER_STATE = newVal; }
private:
    avmplus::NativeID::avmplus_WorkerEventClassSlots m_slots_WorkerEventClass;
protected:
    inline explicit WorkerEventClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit WorkerEventClass(const WorkerEventClass&); // unimplemented
    void operator=(const WorkerEventClass&); // unimplemented
};

#define avmplus_WorkerEventClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.system::System
//-----------------------------------------------------------
class SystemObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::SystemClass;
    REALLY_INLINE explicit SystemObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit SystemObject(const SystemObject&); // unimplemented
    void operator=(const SystemObject&); // unimplemented
};

#define avmplus_SystemObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.system::System$
//-----------------------------------------------------------
class SystemClass : public avmplus::ClassClosure
{
    GC_DECLARE_EXACT_METHODS
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    inline GCRef<avmplus::SystemObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::SystemObject>((avmplus::SystemObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::SystemObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::SystemObject>((avmplus::SystemObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SystemObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::SystemObject>((avmplus::SystemObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SystemObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::SystemObject>((avmplus::SystemObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SystemObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::SystemObject>((avmplus::SystemObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    REALLY_INLINE bool get__useCodePage() const { return m_slots_SystemClass.m_private__useCodePage != 0; }
    REALLY_INLINE void set__useCodePage(avmplus::bool32 newVal) { m_slots_SystemClass.m_private__useCodePage = newVal; }
private:
    avmplus::NativeID::avmplus_SystemClassSlots m_slots_SystemClass;
protected:
    inline explicit SystemClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit SystemClass(const SystemClass&); // unimplemented
    void operator=(const SystemClass&); // unimplemented
};

#define avmplus_SystemClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.errors::ScriptTimeoutError
//-----------------------------------------------------------
class ScriptTimeoutErrorObject : public avmplus::ErrorObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::ScriptTimeoutErrorClass;
    REALLY_INLINE explicit ScriptTimeoutErrorObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ErrorObject(ivtable, delegate) {}
private:
    explicit ScriptTimeoutErrorObject(const ScriptTimeoutErrorObject&); // unimplemented
    void operator=(const ScriptTimeoutErrorObject&); // unimplemented
};

#define avmplus_ScriptTimeoutErrorObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.errors::ScriptTimeoutError$
//-----------------------------------------------------------
class ScriptTimeoutErrorClass : public avmplus::ClassClosure
{
    GC_DECLARE_EXACT_METHODS
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    inline GCRef<avmplus::ScriptTimeoutErrorObject> constructObject(GCRef<avmplus::String> arg1)
    {
        avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom() };
        avmplus::Atom const result = this->construct(1, args);
        return GCRef<avmplus::ScriptTimeoutErrorObject>((avmplus::ScriptTimeoutErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::ScriptTimeoutErrorObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::ScriptTimeoutErrorObject>((avmplus::ScriptTimeoutErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::ScriptTimeoutErrorObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::ScriptTimeoutErrorObject>((avmplus::ScriptTimeoutErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::ScriptTimeoutErrorObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::ScriptTimeoutErrorObject>((avmplus::ScriptTimeoutErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::ScriptTimeoutErrorObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::ScriptTimeoutErrorObject>((avmplus::ScriptTimeoutErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::ScriptTimeoutErrorObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::ScriptTimeoutErrorObject>((avmplus::ScriptTimeoutErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit ScriptTimeoutErrorClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit ScriptTimeoutErrorClass(const ScriptTimeoutErrorClass&); // unimplemented
    void operator=(const ScriptTimeoutErrorClass&); // unimplemented
};

#define avmplus_ScriptTimeoutErrorClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.errors::StackOverflowError
//-----------------------------------------------------------
class StackOverflowErrorObject : public avmplus::ErrorObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::StackOverflowErrorClass;
    REALLY_INLINE explicit StackOverflowErrorObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ErrorObject(ivtable, delegate) {}
private:
    explicit StackOverflowErrorObject(const StackOverflowErrorObject&); // unimplemented
    void operator=(const StackOverflowErrorObject&); // unimplemented
};

#define avmplus_StackOverflowErrorObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.errors::StackOverflowError$
//-----------------------------------------------------------
class StackOverflowErrorClass : public avmplus::ClassClosure
{
    GC_DECLARE_EXACT_METHODS
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    inline GCRef<avmplus::StackOverflowErrorObject> constructObject(GCRef<avmplus::String> arg1)
    {
        avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom() };
        avmplus::Atom const result = this->construct(1, args);
        return GCRef<avmplus::StackOverflowErrorObject>((avmplus::StackOverflowErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::StackOverflowErrorObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::StackOverflowErrorObject>((avmplus::StackOverflowErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::StackOverflowErrorObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::StackOverflowErrorObject>((avmplus::StackOverflowErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::StackOverflowErrorObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::StackOverflowErrorObject>((avmplus::StackOverflowErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::StackOverflowErrorObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::StackOverflowErrorObject>((avmplus::StackOverflowErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::StackOverflowErrorObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::StackOverflowErrorObject>((avmplus::StackOverflowErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit StackOverflowErrorClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit StackOverflowErrorClass(const StackOverflowErrorClass&); // unimplemented
    void operator=(const StackOverflowErrorClass&); // unimplemented
};

#define avmplus_StackOverflowErrorClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.errors::InvalidSWFError
//-----------------------------------------------------------
class InvalidSWFErrorObject : public avmplus::ErrorObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::InvalidSWFErrorClass;
    REALLY_INLINE explicit InvalidSWFErrorObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ErrorObject(ivtable, delegate) {}
private:
    explicit InvalidSWFErrorObject(const InvalidSWFErrorObject&); // unimplemented
    void operator=(const InvalidSWFErrorObject&); // unimplemented
};

#define avmplus_InvalidSWFErrorObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.errors::InvalidSWFError$
//-----------------------------------------------------------
class InvalidSWFErrorClass : public avmplus::ClassClosure
{
    GC_DECLARE_EXACT_METHODS
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    inline GCRef<avmplus::InvalidSWFErrorObject> constructObject(GCRef<avmplus::String> arg1, int32_t arg2)
    {
        avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core()));
        avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom(), core->intToAtom(arg2) };
        avmplus::Atom const result = this->construct(2, args);
        return GCRef<avmplus::InvalidSWFErrorObject>((avmplus::InvalidSWFErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::InvalidSWFErrorObject> constructObject(GCRef<avmplus::String> arg1)
    {
        avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom() };
        avmplus::Atom const result = this->construct(1, args);
        return GCRef<avmplus::InvalidSWFErrorObject>((avmplus::InvalidSWFErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::InvalidSWFErrorObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::InvalidSWFErrorObject>((avmplus::InvalidSWFErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::InvalidSWFErrorObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::InvalidSWFErrorObject>((avmplus::InvalidSWFErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::InvalidSWFErrorObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::InvalidSWFErrorObject>((avmplus::InvalidSWFErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::InvalidSWFErrorObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::InvalidSWFErrorObject>((avmplus::InvalidSWFErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::InvalidSWFErrorObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::InvalidSWFErrorObject>((avmplus::InvalidSWFErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit InvalidSWFErrorClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit InvalidSWFErrorClass(const InvalidSWFErrorClass&); // unimplemented
    void operator=(const InvalidSWFErrorClass&); // unimplemented
};

#define avmplus_InvalidSWFErrorClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.errors::SQLErrorOperation
//-----------------------------------------------------------
class SQLErrorOperationObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::SQLErrorOperationClass;
    REALLY_INLINE explicit SQLErrorOperationObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit SQLErrorOperationObject(const SQLErrorOperationObject&); // unimplemented
    void operator=(const SQLErrorOperationObject&); // unimplemented
};

#define avmplus_SQLErrorOperationObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.errors::SQLErrorOperation$
//-----------------------------------------------------------
class SQLErrorOperationClass : public avmplus::ClassClosure
{
    GC_DECLARE_EXACT_METHODS
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    inline GCRef<avmplus::SQLErrorOperationObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::SQLErrorOperationObject>((avmplus::SQLErrorOperationObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::SQLErrorOperationObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::SQLErrorOperationObject>((avmplus::SQLErrorOperationObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLErrorOperationObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::SQLErrorOperationObject>((avmplus::SQLErrorOperationObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLErrorOperationObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::SQLErrorOperationObject>((avmplus::SQLErrorOperationObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLErrorOperationObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::SQLErrorOperationObject>((avmplus::SQLErrorOperationObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::String* get_ANALYZE() const { return m_slots_SQLErrorOperationClass.m_ANALYZE; }
    REALLY_INLINE void setconst_ANALYZE(avmplus::String* newVal) { m_slots_SQLErrorOperationClass.m_ANALYZE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_ATTACH() const { return m_slots_SQLErrorOperationClass.m_ATTACH; }
    REALLY_INLINE void setconst_ATTACH(avmplus::String* newVal) { m_slots_SQLErrorOperationClass.m_ATTACH = newVal; }
public:
    REALLY_INLINE avmplus::String* get_BEGIN() const { return m_slots_SQLErrorOperationClass.m_BEGIN; }
    REALLY_INLINE void setconst_BEGIN(avmplus::String* newVal) { m_slots_SQLErrorOperationClass.m_BEGIN = newVal; }
public:
    REALLY_INLINE avmplus::String* get_CLOSE() const { return m_slots_SQLErrorOperationClass.m_CLOSE; }
    REALLY_INLINE void setconst_CLOSE(avmplus::String* newVal) { m_slots_SQLErrorOperationClass.m_CLOSE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_COMMIT() const { return m_slots_SQLErrorOperationClass.m_COMMIT; }
    REALLY_INLINE void setconst_COMMIT(avmplus::String* newVal) { m_slots_SQLErrorOperationClass.m_COMMIT = newVal; }
public:
    REALLY_INLINE avmplus::String* get_COMPACT() const { return m_slots_SQLErrorOperationClass.m_COMPACT; }
    REALLY_INLINE void setconst_COMPACT(avmplus::String* newVal) { m_slots_SQLErrorOperationClass.m_COMPACT = newVal; }
public:
    REALLY_INLINE avmplus::String* get_DEANALYZE() const { return m_slots_SQLErrorOperationClass.m_DEANALYZE; }
    REALLY_INLINE void setconst_DEANALYZE(avmplus::String* newVal) { m_slots_SQLErrorOperationClass.m_DEANALYZE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_DETACH() const { return m_slots_SQLErrorOperationClass.m_DETACH; }
    REALLY_INLINE void setconst_DETACH(avmplus::String* newVal) { m_slots_SQLErrorOperationClass.m_DETACH = newVal; }
public:
    REALLY_INLINE avmplus::String* get_EXECUTE() const { return m_slots_SQLErrorOperationClass.m_EXECUTE; }
    REALLY_INLINE void setconst_EXECUTE(avmplus::String* newVal) { m_slots_SQLErrorOperationClass.m_EXECUTE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_OPEN() const { return m_slots_SQLErrorOperationClass.m_OPEN; }
    REALLY_INLINE void setconst_OPEN(avmplus::String* newVal) { m_slots_SQLErrorOperationClass.m_OPEN = newVal; }
public:
    REALLY_INLINE avmplus::String* get_REENCRYPT() const { return m_slots_SQLErrorOperationClass.m_REENCRYPT; }
    REALLY_INLINE void setconst_REENCRYPT(avmplus::String* newVal) { m_slots_SQLErrorOperationClass.m_REENCRYPT = newVal; }
public:
    REALLY_INLINE avmplus::String* get_RELEASE_SAVEPOINT() const { return m_slots_SQLErrorOperationClass.m_RELEASE_SAVEPOINT; }
    REALLY_INLINE void setconst_RELEASE_SAVEPOINT(avmplus::String* newVal) { m_slots_SQLErrorOperationClass.m_RELEASE_SAVEPOINT = newVal; }
public:
    REALLY_INLINE avmplus::String* get_ROLLBACK() const { return m_slots_SQLErrorOperationClass.m_ROLLBACK; }
    REALLY_INLINE void setconst_ROLLBACK(avmplus::String* newVal) { m_slots_SQLErrorOperationClass.m_ROLLBACK = newVal; }
public:
    REALLY_INLINE avmplus::String* get_ROLLBACK_TO_SAVEPOINT() const { return m_slots_SQLErrorOperationClass.m_ROLLBACK_TO_SAVEPOINT; }
    REALLY_INLINE void setconst_ROLLBACK_TO_SAVEPOINT(avmplus::String* newVal) { m_slots_SQLErrorOperationClass.m_ROLLBACK_TO_SAVEPOINT = newVal; }
public:
    REALLY_INLINE avmplus::String* get_SCHEMA() const { return m_slots_SQLErrorOperationClass.m_SCHEMA; }
    REALLY_INLINE void setconst_SCHEMA(avmplus::String* newVal) { m_slots_SQLErrorOperationClass.m_SCHEMA = newVal; }
public:
    REALLY_INLINE avmplus::String* get_SET_SAVEPOINT() const { return m_slots_SQLErrorOperationClass.m_SET_SAVEPOINT; }
    REALLY_INLINE void setconst_SET_SAVEPOINT(avmplus::String* newVal) { m_slots_SQLErrorOperationClass.m_SET_SAVEPOINT = newVal; }
private:
    avmplus::NativeID::avmplus_SQLErrorOperationClassSlots m_slots_SQLErrorOperationClass;
protected:
    inline explicit SQLErrorOperationClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit SQLErrorOperationClass(const SQLErrorOperationClass&); // unimplemented
    void operator=(const SQLErrorOperationClass&); // unimplemented
};

#define avmplus_SQLErrorOperationClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.errors::SQLError
//-----------------------------------------------------------
class SQLErrorObject : public avmplus::ErrorObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    REALLY_INLINE int32_t get__detailID() const { return m_slots_SQLErrorObject.m_private__detailID; }
    REALLY_INLINE void set__detailID(int32_t newVal) { m_slots_SQLErrorObject.m_private__detailID = newVal; }
protected:
    REALLY_INLINE avmplus::String* get__operation() const { return m_slots_SQLErrorObject.m_private__operation; }
    REALLY_INLINE void set__operation(avmplus::String* newVal) { m_slots_SQLErrorObject.m_private__operation = newVal; }
protected:
    REALLY_INLINE avmplus::String* get__details() const { return m_slots_SQLErrorObject.m_private__details; }
    REALLY_INLINE void set__details(avmplus::String* newVal) { m_slots_SQLErrorObject.m_private__details = newVal; }
protected:
    REALLY_INLINE avmplus::ArrayObject* get__detailArguments() const { return m_slots_SQLErrorObject.m_private__detailArguments; }
    REALLY_INLINE void set__detailArguments(avmplus::ArrayObject* newVal) { m_slots_SQLErrorObject.m_private__detailArguments = newVal; }
private:
    avmplus::NativeID::avmplus_SQLErrorObjectSlots m_slots_SQLErrorObject;
protected:
    friend class avmplus::SQLErrorClass;
    REALLY_INLINE explicit SQLErrorObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ErrorObject(ivtable, delegate) {}
private:
    explicit SQLErrorObject(const SQLErrorObject&); // unimplemented
    void operator=(const SQLErrorObject&); // unimplemented
};

#define avmplus_SQLErrorObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.errors::SQLError$
//-----------------------------------------------------------
class SQLErrorClass : public avmplus::ClassClosure
{
    GC_DECLARE_EXACT_METHODS
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    inline GCRef<avmplus::SQLErrorObject> constructObject(GCRef<avmplus::String> arg1, GCRef<avmplus::String> arg2, GCRef<avmplus::String> arg3, int32_t arg4, int32_t arg5, GCRef<avmplus::ArrayObject> arg6)
    {
        avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core()));
        avmplus::Atom args[7] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom(), arg2->atom(), arg3->atom(), core->intToAtom(arg4), core->intToAtom(arg5), arg6.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(6, args);
        return GCRef<avmplus::SQLErrorObject>((avmplus::SQLErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::SQLErrorObject> constructObject(GCRef<avmplus::String> arg1, GCRef<avmplus::String> arg2, GCRef<avmplus::String> arg3, int32_t arg4, int32_t arg5)
    {
        avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core()));
        avmplus::Atom args[6] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom(), arg2->atom(), arg3->atom(), core->intToAtom(arg4), core->intToAtom(arg5) };
        avmplus::Atom const result = this->construct(5, args);
        return GCRef<avmplus::SQLErrorObject>((avmplus::SQLErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::SQLErrorObject> constructObject(GCRef<avmplus::String> arg1, GCRef<avmplus::String> arg2, GCRef<avmplus::String> arg3, int32_t arg4)
    {
        avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core()));
        avmplus::Atom args[5] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom(), arg2->atom(), arg3->atom(), core->intToAtom(arg4) };
        avmplus::Atom const result = this->construct(4, args);
        return GCRef<avmplus::SQLErrorObject>((avmplus::SQLErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::SQLErrorObject> constructObject(GCRef<avmplus::String> arg1, GCRef<avmplus::String> arg2, GCRef<avmplus::String> arg3)
    {
        avmplus::Atom args[4] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom(), arg2->atom(), arg3->atom() };
        avmplus::Atom const result = this->construct(3, args);
        return GCRef<avmplus::SQLErrorObject>((avmplus::SQLErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::SQLErrorObject> constructObject(GCRef<avmplus::String> arg1, GCRef<avmplus::String> arg2)
    {
        avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom(), arg2->atom() };
        avmplus::Atom const result = this->construct(2, args);
        return GCRef<avmplus::SQLErrorObject>((avmplus::SQLErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::SQLErrorObject> constructObject(GCRef<avmplus::String> arg1)
    {
        avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom() };
        avmplus::Atom const result = this->construct(1, args);
        return GCRef<avmplus::SQLErrorObject>((avmplus::SQLErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::SQLErrorObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::SQLErrorObject>((avmplus::SQLErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLErrorObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::SQLErrorObject>((avmplus::SQLErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLErrorObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::SQLErrorObject>((avmplus::SQLErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLErrorObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::SQLErrorObject>((avmplus::SQLErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit SQLErrorClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit SQLErrorClass(const SQLErrorClass&); // unimplemented
    void operator=(const SQLErrorClass&); // unimplemented
};

#define avmplus_SQLErrorClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.errors::DRMManagerError
//-----------------------------------------------------------
class DRMManagerErrorObject : public avmplus::ErrorObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    REALLY_INLINE int32_t get__subErrorID() const { return m_slots_DRMManagerErrorObject.m_private__subErrorID; }
    REALLY_INLINE void set__subErrorID(int32_t newVal) { m_slots_DRMManagerErrorObject.m_private__subErrorID = newVal; }
private:
    avmplus::NativeID::avmplus_DRMManagerErrorObjectSlots m_slots_DRMManagerErrorObject;
protected:
    friend class avmplus::DRMManagerErrorClass;
    REALLY_INLINE explicit DRMManagerErrorObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ErrorObject(ivtable, delegate) {}
private:
    explicit DRMManagerErrorObject(const DRMManagerErrorObject&); // unimplemented
    void operator=(const DRMManagerErrorObject&); // unimplemented
};

#define avmplus_DRMManagerErrorObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.errors::DRMManagerError$
//-----------------------------------------------------------
class DRMManagerErrorClass : public avmplus::ClassClosure
{
    GC_DECLARE_EXACT_METHODS
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    inline GCRef<avmplus::DRMManagerErrorObject> constructObject(GCRef<avmplus::String> arg1, int32_t arg2, int32_t arg3)
    {
        avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core()));
        avmplus::Atom args[4] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom(), core->intToAtom(arg2), core->intToAtom(arg3) };
        avmplus::Atom const result = this->construct(3, args);
        return GCRef<avmplus::DRMManagerErrorObject>((avmplus::DRMManagerErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::DRMManagerErrorObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::DRMManagerErrorObject>((avmplus::DRMManagerErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::DRMManagerErrorObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::DRMManagerErrorObject>((avmplus::DRMManagerErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::DRMManagerErrorObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::DRMManagerErrorObject>((avmplus::DRMManagerErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::DRMManagerErrorObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::DRMManagerErrorObject>((avmplus::DRMManagerErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit DRMManagerErrorClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit DRMManagerErrorClass(const DRMManagerErrorClass&); // unimplemented
    void operator=(const DRMManagerErrorClass&); // unimplemented
};

#define avmplus_DRMManagerErrorClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.sampler::DeleteObjectSample
//-----------------------------------------------------------
class DeleteObjectSampleObject : public avmplus::SampleObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE double get_id() const { return m_slots_DeleteObjectSampleObject.m_id; }
    REALLY_INLINE void setconst_id(double newVal) { m_slots_DeleteObjectSampleObject.m_id = newVal; }
public:
    REALLY_INLINE double get_size() const { return m_slots_DeleteObjectSampleObject.m_size; }
    REALLY_INLINE void setconst_size(double newVal) { m_slots_DeleteObjectSampleObject.m_size = newVal; }
private:
    avmplus::NativeID::avmplus_DeleteObjectSampleObjectSlots m_slots_DeleteObjectSampleObject;
protected:
    friend class avmplus::DeleteObjectSampleClass;
    REALLY_INLINE explicit DeleteObjectSampleObject(VTable* ivtable, ScriptObject* delegate) : avmplus::SampleObject(ivtable, delegate) {}
private:
    explicit DeleteObjectSampleObject(const DeleteObjectSampleObject&); // unimplemented
    void operator=(const DeleteObjectSampleObject&); // unimplemented
};

#define avmplus_DeleteObjectSampleObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.sampler::DeleteObjectSample$
//-----------------------------------------------------------
class DeleteObjectSampleClass : public avmplus::ClassClosure
{
    GC_DECLARE_EXACT_METHODS
public:
    static avmplus::ClassClosure* FASTCALL createClassClosure(avmplus::VTable* cvtable);
public:
    static avmplus::ScriptObject* FASTCALL createInstanceProc(avmplus::ClassClosure*);
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    inline GCRef<avmplus::DeleteObjectSampleObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::DeleteObjectSampleObject>((avmplus::DeleteObjectSampleObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::DeleteObjectSampleObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::DeleteObjectSampleObject>((avmplus::DeleteObjectSampleObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::DeleteObjectSampleObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::DeleteObjectSampleObject>((avmplus::DeleteObjectSampleObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::DeleteObjectSampleObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::DeleteObjectSampleObject>((avmplus::DeleteObjectSampleObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::DeleteObjectSampleObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::DeleteObjectSampleObject>((avmplus::DeleteObjectSampleObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit DeleteObjectSampleClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit DeleteObjectSampleClass(const DeleteObjectSampleClass&); // unimplemented
    void operator=(const DeleteObjectSampleClass&); // unimplemented
};

#define avmplus_DeleteObjectSampleClass_isExactInterlock 1
}

#endif // _H_nativegen_classes_shell_toplevel
