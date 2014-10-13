/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/* machine generated file -- do not edit */

#ifndef _H_nativegen_classes_shell_toplevel
#define _H_nativegen_classes_shell_toplevel

namespace avmplus {

//-----------------------------------------------------------
// C.ctype::__ctype
//-----------------------------------------------------------
class __ctypeObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmshell::CTypeClass;
    REALLY_INLINE explicit __ctypeObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit __ctypeObject(const __ctypeObject&); // unimplemented
    void operator=(const __ctypeObject&); // unimplemented
};

#define avmplus___ctypeObject_isExactInterlock 1
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
    REALLY_INLINE uint32_t get__value() const { return m_slots_ErrorNumberObject.m_private__value; }
    REALLY_INLINE void set__value(uint32_t newVal) { m_slots_ErrorNumberObject.m_private__value = newVal; }
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
// C.limits::__limits
//-----------------------------------------------------------
class __limitsObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmshell::CLimitsClass;
    REALLY_INLINE explicit __limitsObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit __limitsObject(const __limitsObject&); // unimplemented
    void operator=(const __limitsObject&); // unimplemented
};

#define avmplus___limitsObject_isExactInterlock 1
//-----------------------------------------------------------
// C.locale::__locale
//-----------------------------------------------------------
class __localeObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmshell::CLocaleClass;
    REALLY_INLINE explicit __localeObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit __localeObject(const __localeObject&); // unimplemented
    void operator=(const __localeObject&); // unimplemented
};

#define avmplus___localeObject_isExactInterlock 1
//-----------------------------------------------------------
// C.signal::__signal
//-----------------------------------------------------------
class __signalObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmshell::CSignalClass;
    REALLY_INLINE explicit __signalObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit __signalObject(const __signalObject&); // unimplemented
    void operator=(const __signalObject&); // unimplemented
};

#define avmplus___signalObject_isExactInterlock 1
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
// C.time::__time
//-----------------------------------------------------------
class __timeObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmshell::CTimeClass;
    REALLY_INLINE explicit __timeObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit __timeObject(const __timeObject&); // unimplemented
    void operator=(const __timeObject&); // unimplemented
};

#define avmplus___timeObject_isExactInterlock 1
//-----------------------------------------------------------
// C.time::tm
//-----------------------------------------------------------
class tmObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE int32_t get_tm_sec() const { return m_slots_tmObject.m_tm_sec; }
    REALLY_INLINE void set_tm_sec(int32_t newVal) { m_slots_tmObject.m_tm_sec = newVal; }
public:
    REALLY_INLINE int32_t get_tm_min() const { return m_slots_tmObject.m_tm_min; }
    REALLY_INLINE void set_tm_min(int32_t newVal) { m_slots_tmObject.m_tm_min = newVal; }
public:
    REALLY_INLINE int32_t get_tm_hour() const { return m_slots_tmObject.m_tm_hour; }
    REALLY_INLINE void set_tm_hour(int32_t newVal) { m_slots_tmObject.m_tm_hour = newVal; }
public:
    REALLY_INLINE int32_t get_tm_mday() const { return m_slots_tmObject.m_tm_mday; }
    REALLY_INLINE void set_tm_mday(int32_t newVal) { m_slots_tmObject.m_tm_mday = newVal; }
public:
    REALLY_INLINE int32_t get_tm_mon() const { return m_slots_tmObject.m_tm_mon; }
    REALLY_INLINE void set_tm_mon(int32_t newVal) { m_slots_tmObject.m_tm_mon = newVal; }
public:
    REALLY_INLINE int32_t get_tm_year() const { return m_slots_tmObject.m_tm_year; }
    REALLY_INLINE void set_tm_year(int32_t newVal) { m_slots_tmObject.m_tm_year = newVal; }
public:
    REALLY_INLINE int32_t get_tm_wday() const { return m_slots_tmObject.m_tm_wday; }
    REALLY_INLINE void set_tm_wday(int32_t newVal) { m_slots_tmObject.m_tm_wday = newVal; }
public:
    REALLY_INLINE int32_t get_tm_yday() const { return m_slots_tmObject.m_tm_yday; }
    REALLY_INLINE void set_tm_yday(int32_t newVal) { m_slots_tmObject.m_tm_yday = newVal; }
public:
    REALLY_INLINE int32_t get_tm_isdst() const { return m_slots_tmObject.m_tm_isdst; }
    REALLY_INLINE void set_tm_isdst(int32_t newVal) { m_slots_tmObject.m_tm_isdst = newVal; }
private:
    avmplus::NativeID::avmplus_tmObjectSlots m_slots_tmObject;
protected:
    friend class avmplus::tmClass;
    REALLY_INLINE explicit tmObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit tmObject(const tmObject&); // unimplemented
    void operator=(const tmObject&); // unimplemented
};

#define avmplus_tmObject_isExactInterlock 1
//-----------------------------------------------------------
// C.time::tm$
//-----------------------------------------------------------
class tmClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::tmObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::tmObject>((avmplus::tmObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::tmObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::tmObject>((avmplus::tmObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::tmObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::tmObject>((avmplus::tmObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::tmObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::tmObject>((avmplus::tmObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::tmObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::tmObject>((avmplus::tmObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit tmClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit tmClass(const tmClass&); // unimplemented
    void operator=(const tmClass&); // unimplemented
};

#define avmplus_tmClass_isExactInterlock 1
//-----------------------------------------------------------
// C.time::timespec
//-----------------------------------------------------------
class timespecObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE int32_t get_tv_sec() const { return m_slots_timespecObject.m_tv_sec; }
    REALLY_INLINE void set_tv_sec(int32_t newVal) { m_slots_timespecObject.m_tv_sec = newVal; }
public:
    REALLY_INLINE double get_tv_nsec() const { return m_slots_timespecObject.m_tv_nsec; }
    REALLY_INLINE void set_tv_nsec(double newVal) { m_slots_timespecObject.m_tv_nsec = newVal; }
private:
    avmplus::NativeID::avmplus_timespecObjectSlots m_slots_timespecObject;
protected:
    friend class avmplus::timespecClass;
    REALLY_INLINE explicit timespecObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit timespecObject(const timespecObject&); // unimplemented
    void operator=(const timespecObject&); // unimplemented
};

#define avmplus_timespecObject_isExactInterlock 1
//-----------------------------------------------------------
// C.time::timespec$
//-----------------------------------------------------------
class timespecClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::timespecObject> constructObject(int32_t arg1, double arg2)
    {
        avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core()));
        avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->intToAtom(arg1), core->doubleToAtom(arg2) };
        avmplus::Atom const result = this->construct(2, args);
        return GCRef<avmplus::timespecObject>((avmplus::timespecObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::timespecObject> constructObject(int32_t arg1)
    {
        avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core()));
        avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->intToAtom(arg1) };
        avmplus::Atom const result = this->construct(1, args);
        return GCRef<avmplus::timespecObject>((avmplus::timespecObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::timespecObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::timespecObject>((avmplus::timespecObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::timespecObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::timespecObject>((avmplus::timespecObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::timespecObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::timespecObject>((avmplus::timespecObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::timespecObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::timespecObject>((avmplus::timespecObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::timespecObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::timespecObject>((avmplus::timespecObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit timespecClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit timespecClass(const timespecClass&); // unimplemented
    void operator=(const timespecClass&); // unimplemented
};

#define avmplus_timespecClass_isExactInterlock 1
//-----------------------------------------------------------
// C.time::itimerspec
//-----------------------------------------------------------
class itimerspecObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::timespecObject* get_it_interval() const { return m_slots_itimerspecObject.m_it_interval; }
    REALLY_INLINE void set_it_interval(avmplus::timespecObject* newVal) { m_slots_itimerspecObject.m_it_interval = newVal; }
public:
    REALLY_INLINE avmplus::timespecObject* get_it_value() const { return m_slots_itimerspecObject.m_it_value; }
    REALLY_INLINE void set_it_value(avmplus::timespecObject* newVal) { m_slots_itimerspecObject.m_it_value = newVal; }
private:
    avmplus::NativeID::avmplus_itimerspecObjectSlots m_slots_itimerspecObject;
protected:
    friend class avmplus::itimerspecClass;
    REALLY_INLINE explicit itimerspecObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit itimerspecObject(const itimerspecObject&); // unimplemented
    void operator=(const itimerspecObject&); // unimplemented
};

#define avmplus_itimerspecObject_isExactInterlock 1
//-----------------------------------------------------------
// C.time::itimerspec$
//-----------------------------------------------------------
class itimerspecClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::itimerspecObject> constructObject(GCRef<avmplus::timespecObject> arg1, GCRef<avmplus::timespecObject> arg2)
    {
        avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1.reinterpretCast<avmplus::ScriptObject>()->atom(), arg2.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(2, args);
        return GCRef<avmplus::itimerspecObject>((avmplus::itimerspecObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::itimerspecObject> constructObject(GCRef<avmplus::timespecObject> arg1)
    {
        avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(1, args);
        return GCRef<avmplus::itimerspecObject>((avmplus::itimerspecObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::itimerspecObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::itimerspecObject>((avmplus::itimerspecObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::itimerspecObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::itimerspecObject>((avmplus::itimerspecObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::itimerspecObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::itimerspecObject>((avmplus::itimerspecObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::itimerspecObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::itimerspecObject>((avmplus::itimerspecObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::itimerspecObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::itimerspecObject>((avmplus::itimerspecObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit itimerspecClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit itimerspecClass(const itimerspecClass&); // unimplemented
    void operator=(const itimerspecClass&); // unimplemented
};

#define avmplus_itimerspecClass_isExactInterlock 1
//-----------------------------------------------------------
// C.arpa.inet::__inet
//-----------------------------------------------------------
class __inetObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmshell::CArpaInetClass;
    REALLY_INLINE explicit __inetObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit __inetObject(const __inetObject&); // unimplemented
    void operator=(const __inetObject&); // unimplemented
};

#define avmplus___inetObject_isExactInterlock 1
//-----------------------------------------------------------
// C.fcntl::__fcntl
//-----------------------------------------------------------
class __fcntlObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmshell::CFcntlClass;
    REALLY_INLINE explicit __fcntlObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit __fcntlObject(const __fcntlObject&); // unimplemented
    void operator=(const __fcntlObject&); // unimplemented
};

#define avmplus___fcntlObject_isExactInterlock 1
//-----------------------------------------------------------
// C.netdb::__netdb
//-----------------------------------------------------------
class __netdbObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmshell::CNetdbClass;
    REALLY_INLINE explicit __netdbObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit __netdbObject(const __netdbObject&); // unimplemented
    void operator=(const __netdbObject&); // unimplemented
};

#define avmplus___netdbObject_isExactInterlock 1
//-----------------------------------------------------------
// C.netdb::netent
//-----------------------------------------------------------
class netentObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::netentClass;
    REALLY_INLINE explicit netentObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit netentObject(const netentObject&); // unimplemented
    void operator=(const netentObject&); // unimplemented
};

#define avmplus_netentObject_isExactInterlock 1
//-----------------------------------------------------------
// C.netdb::netent$
//-----------------------------------------------------------
class netentClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::netentObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::netentObject>((avmplus::netentObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::netentObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::netentObject>((avmplus::netentObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::netentObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::netentObject>((avmplus::netentObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::netentObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::netentObject>((avmplus::netentObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::netentObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::netentObject>((avmplus::netentObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit netentClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit netentClass(const netentClass&); // unimplemented
    void operator=(const netentClass&); // unimplemented
};

#define avmplus_netentClass_isExactInterlock 1
//-----------------------------------------------------------
// C.netdb::servent
//-----------------------------------------------------------
class serventObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::serventClass;
    REALLY_INLINE explicit serventObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit serventObject(const serventObject&); // unimplemented
    void operator=(const serventObject&); // unimplemented
};

#define avmplus_serventObject_isExactInterlock 1
//-----------------------------------------------------------
// C.netdb::servent$
//-----------------------------------------------------------
class serventClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::serventObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::serventObject>((avmplus::serventObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::serventObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::serventObject>((avmplus::serventObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::serventObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::serventObject>((avmplus::serventObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::serventObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::serventObject>((avmplus::serventObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::serventObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::serventObject>((avmplus::serventObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit serventClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit serventClass(const serventClass&); // unimplemented
    void operator=(const serventClass&); // unimplemented
};

#define avmplus_serventClass_isExactInterlock 1
//-----------------------------------------------------------
// C.netinet::__netinet
//-----------------------------------------------------------
class __netinetObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmshell::CNetinetInClass;
    REALLY_INLINE explicit __netinetObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit __netinetObject(const __netinetObject&); // unimplemented
    void operator=(const __netinetObject&); // unimplemented
};

#define avmplus___netinetObject_isExactInterlock 1
//-----------------------------------------------------------
// C.netinet::ipv6_mreq
//-----------------------------------------------------------
class ipv6_mreqObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE uint32_t get_ipv6mr_interface() const { return m_slots_ipv6_mreqObject.m_ipv6mr_interface; }
    REALLY_INLINE void set_ipv6mr_interface(uint32_t newVal) { m_slots_ipv6_mreqObject.m_ipv6mr_interface = newVal; }
public:
    REALLY_INLINE avmshell::CIn6_AddrObject* get_ipv6mr_multiaddr() const { return m_slots_ipv6_mreqObject.m_ipv6mr_multiaddr; }
    REALLY_INLINE void set_ipv6mr_multiaddr(avmshell::CIn6_AddrObject* newVal) { m_slots_ipv6_mreqObject.m_ipv6mr_multiaddr = newVal; }
private:
    avmplus::NativeID::avmplus_ipv6_mreqObjectSlots m_slots_ipv6_mreqObject;
protected:
    friend class avmplus::ipv6_mreqClass;
    REALLY_INLINE explicit ipv6_mreqObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit ipv6_mreqObject(const ipv6_mreqObject&); // unimplemented
    void operator=(const ipv6_mreqObject&); // unimplemented
};

#define avmplus_ipv6_mreqObject_isExactInterlock 1
//-----------------------------------------------------------
// C.netinet::ipv6_mreq$
//-----------------------------------------------------------
class ipv6_mreqClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::ipv6_mreqObject> constructObject(GCRef<avmshell::CIn6_AddrObject> arg1, uint32_t arg2)
    {
        avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core()));
        avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1.reinterpretCast<avmplus::ScriptObject>()->atom(), core->uintToAtom(arg2) };
        avmplus::Atom const result = this->construct(2, args);
        return GCRef<avmplus::ipv6_mreqObject>((avmplus::ipv6_mreqObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::ipv6_mreqObject> constructObject(GCRef<avmshell::CIn6_AddrObject> arg1)
    {
        avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(1, args);
        return GCRef<avmplus::ipv6_mreqObject>((avmplus::ipv6_mreqObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::ipv6_mreqObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::ipv6_mreqObject>((avmplus::ipv6_mreqObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::ipv6_mreqObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::ipv6_mreqObject>((avmplus::ipv6_mreqObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::ipv6_mreqObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::ipv6_mreqObject>((avmplus::ipv6_mreqObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::ipv6_mreqObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::ipv6_mreqObject>((avmplus::ipv6_mreqObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::ipv6_mreqObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::ipv6_mreqObject>((avmplus::ipv6_mreqObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit ipv6_mreqClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit ipv6_mreqClass(const ipv6_mreqClass&); // unimplemented
    void operator=(const ipv6_mreqClass&); // unimplemented
};

#define avmplus_ipv6_mreqClass_isExactInterlock 1
//-----------------------------------------------------------
// C.sys.select::__select
//-----------------------------------------------------------
class __selectObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmshell::CSysSelectClass;
    REALLY_INLINE explicit __selectObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit __selectObject(const __selectObject&); // unimplemented
    void operator=(const __selectObject&); // unimplemented
};

#define avmplus___selectObject_isExactInterlock 1
//-----------------------------------------------------------
// C.sys.socket::__socket
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
    friend class avmshell::CSysSocketClass;
    REALLY_INLINE explicit __socketObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit __socketObject(const __socketObject&); // unimplemented
    void operator=(const __socketObject&); // unimplemented
};

#define avmplus___socketObject_isExactInterlock 1
//-----------------------------------------------------------
// C.sys.socket::sockaddr_storage
//-----------------------------------------------------------
class sockaddr_storageObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE uint32_t get_ss_family() const { return m_slots_sockaddr_storageObject.m_ss_family; }
    REALLY_INLINE void set_ss_family(uint32_t newVal) { m_slots_sockaddr_storageObject.m_ss_family = newVal; }
private:
    avmplus::NativeID::avmplus_sockaddr_storageObjectSlots m_slots_sockaddr_storageObject;
protected:
    friend class avmplus::sockaddr_storageClass;
    REALLY_INLINE explicit sockaddr_storageObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit sockaddr_storageObject(const sockaddr_storageObject&); // unimplemented
    void operator=(const sockaddr_storageObject&); // unimplemented
};

#define avmplus_sockaddr_storageObject_isExactInterlock 1
//-----------------------------------------------------------
// C.sys.socket::sockaddr_storage$
//-----------------------------------------------------------
class sockaddr_storageClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::sockaddr_storageObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::sockaddr_storageObject>((avmplus::sockaddr_storageObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::sockaddr_storageObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::sockaddr_storageObject>((avmplus::sockaddr_storageObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::sockaddr_storageObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::sockaddr_storageObject>((avmplus::sockaddr_storageObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::sockaddr_storageObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::sockaddr_storageObject>((avmplus::sockaddr_storageObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::sockaddr_storageObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::sockaddr_storageObject>((avmplus::sockaddr_storageObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit sockaddr_storageClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit sockaddr_storageClass(const sockaddr_storageClass&); // unimplemented
    void operator=(const sockaddr_storageClass&); // unimplemented
};

#define avmplus_sockaddr_storageClass_isExactInterlock 1
//-----------------------------------------------------------
// C.sys.socket::msghdr
//-----------------------------------------------------------
class msghdrObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE int32_t get_msg_namelen() const { return m_slots_msghdrObject.m_msg_namelen; }
    REALLY_INLINE void set_msg_namelen(int32_t newVal) { m_slots_msghdrObject.m_msg_namelen = newVal; }
public:
    REALLY_INLINE int32_t get_msg_iovlen() const { return m_slots_msghdrObject.m_msg_iovlen; }
    REALLY_INLINE void set_msg_iovlen(int32_t newVal) { m_slots_msghdrObject.m_msg_iovlen = newVal; }
public:
    REALLY_INLINE int32_t get_msg_controllen() const { return m_slots_msghdrObject.m_msg_controllen; }
    REALLY_INLINE void set_msg_controllen(int32_t newVal) { m_slots_msghdrObject.m_msg_controllen = newVal; }
public:
    REALLY_INLINE int32_t get_msg_flags() const { return m_slots_msghdrObject.m_msg_flags; }
    REALLY_INLINE void set_msg_flags(int32_t newVal) { m_slots_msghdrObject.m_msg_flags = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_msg_name() const { return m_slots_msghdrObject.m_msg_name; }
    REALLY_INLINE void set_msg_name(avmplus::Atom newVal) { m_slots_msghdrObject.m_msg_name = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_msg_iov() const { return m_slots_msghdrObject.m_msg_iov; }
    REALLY_INLINE void set_msg_iov(avmplus::Atom newVal) { m_slots_msghdrObject.m_msg_iov = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_msg_control() const { return m_slots_msghdrObject.m_msg_control; }
    REALLY_INLINE void set_msg_control(avmplus::Atom newVal) { m_slots_msghdrObject.m_msg_control = newVal; }
private:
    avmplus::NativeID::avmplus_msghdrObjectSlots m_slots_msghdrObject;
protected:
    friend class avmplus::msghdrClass;
    REALLY_INLINE explicit msghdrObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit msghdrObject(const msghdrObject&); // unimplemented
    void operator=(const msghdrObject&); // unimplemented
};

#define avmplus_msghdrObject_isExactInterlock 1
//-----------------------------------------------------------
// C.sys.socket::msghdr$
//-----------------------------------------------------------
class msghdrClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::msghdrObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::msghdrObject>((avmplus::msghdrObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::msghdrObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::msghdrObject>((avmplus::msghdrObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::msghdrObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::msghdrObject>((avmplus::msghdrObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::msghdrObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::msghdrObject>((avmplus::msghdrObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::msghdrObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::msghdrObject>((avmplus::msghdrObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit msghdrClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit msghdrClass(const msghdrClass&); // unimplemented
    void operator=(const msghdrClass&); // unimplemented
};

#define avmplus_msghdrClass_isExactInterlock 1
//-----------------------------------------------------------
// C.sys.stat::__stat
//-----------------------------------------------------------
class __statObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmshell::CSysStatClass;
    REALLY_INLINE explicit __statObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit __statObject(const __statObject&); // unimplemented
    void operator=(const __statObject&); // unimplemented
};

#define avmplus___statObject_isExactInterlock 1
//-----------------------------------------------------------
// C.sys.utsname::utsname
//-----------------------------------------------------------
class utsnameObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::String* get_sysname() const { return m_slots_utsnameObject.m_sysname; }
    REALLY_INLINE void set_sysname(avmplus::String* newVal) { m_slots_utsnameObject.m_sysname = newVal; }
public:
    REALLY_INLINE avmplus::String* get_nodename() const { return m_slots_utsnameObject.m_nodename; }
    REALLY_INLINE void set_nodename(avmplus::String* newVal) { m_slots_utsnameObject.m_nodename = newVal; }
public:
    REALLY_INLINE avmplus::String* get_release() const { return m_slots_utsnameObject.m_release; }
    REALLY_INLINE void set_release(avmplus::String* newVal) { m_slots_utsnameObject.m_release = newVal; }
public:
    REALLY_INLINE avmplus::String* get_version() const { return m_slots_utsnameObject.m_version; }
    REALLY_INLINE void set_version(avmplus::String* newVal) { m_slots_utsnameObject.m_version = newVal; }
public:
    REALLY_INLINE avmplus::String* get_machine() const { return m_slots_utsnameObject.m_machine; }
    REALLY_INLINE void set_machine(avmplus::String* newVal) { m_slots_utsnameObject.m_machine = newVal; }
private:
    avmplus::NativeID::avmplus_utsnameObjectSlots m_slots_utsnameObject;
protected:
    friend class avmplus::utsnameClass;
    REALLY_INLINE explicit utsnameObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit utsnameObject(const utsnameObject&); // unimplemented
    void operator=(const utsnameObject&); // unimplemented
};

#define avmplus_utsnameObject_isExactInterlock 1
//-----------------------------------------------------------
// C.sys.utsname::utsname$
//-----------------------------------------------------------
class utsnameClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::utsnameObject> constructObject(GCRef<avmplus::String> arg1, GCRef<avmplus::String> arg2, GCRef<avmplus::String> arg3, GCRef<avmplus::String> arg4, GCRef<avmplus::String> arg5)
    {
        avmplus::Atom args[6] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom(), arg2->atom(), arg3->atom(), arg4->atom(), arg5->atom() };
        avmplus::Atom const result = this->construct(5, args);
        return GCRef<avmplus::utsnameObject>((avmplus::utsnameObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::utsnameObject> constructObject(GCRef<avmplus::String> arg1, GCRef<avmplus::String> arg2, GCRef<avmplus::String> arg3, GCRef<avmplus::String> arg4)
    {
        avmplus::Atom args[5] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom(), arg2->atom(), arg3->atom(), arg4->atom() };
        avmplus::Atom const result = this->construct(4, args);
        return GCRef<avmplus::utsnameObject>((avmplus::utsnameObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::utsnameObject> constructObject(GCRef<avmplus::String> arg1, GCRef<avmplus::String> arg2, GCRef<avmplus::String> arg3)
    {
        avmplus::Atom args[4] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom(), arg2->atom(), arg3->atom() };
        avmplus::Atom const result = this->construct(3, args);
        return GCRef<avmplus::utsnameObject>((avmplus::utsnameObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::utsnameObject> constructObject(GCRef<avmplus::String> arg1, GCRef<avmplus::String> arg2)
    {
        avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom(), arg2->atom() };
        avmplus::Atom const result = this->construct(2, args);
        return GCRef<avmplus::utsnameObject>((avmplus::utsnameObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::utsnameObject> constructObject(GCRef<avmplus::String> arg1)
    {
        avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom() };
        avmplus::Atom const result = this->construct(1, args);
        return GCRef<avmplus::utsnameObject>((avmplus::utsnameObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::utsnameObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::utsnameObject>((avmplus::utsnameObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::utsnameObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::utsnameObject>((avmplus::utsnameObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::utsnameObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::utsnameObject>((avmplus::utsnameObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::utsnameObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::utsnameObject>((avmplus::utsnameObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::utsnameObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::utsnameObject>((avmplus::utsnameObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit utsnameClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit utsnameClass(const utsnameClass&); // unimplemented
    void operator=(const utsnameClass&); // unimplemented
};

#define avmplus_utsnameClass_isExactInterlock 1
//-----------------------------------------------------------
// C.sys.wait::__wait
//-----------------------------------------------------------
class __waitObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmshell::CSysWaitClass;
    REALLY_INLINE explicit __waitObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit __waitObject(const __waitObject&); // unimplemented
    void operator=(const __waitObject&); // unimplemented
};

#define avmplus___waitObject_isExactInterlock 1
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
// shell::Runtime
//-----------------------------------------------------------
class RuntimeObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmshell::RuntimeClass;
    REALLY_INLINE explicit RuntimeObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit RuntimeObject(const RuntimeObject&); // unimplemented
    void operator=(const RuntimeObject&); // unimplemented
};

#define avmplus_RuntimeObject_isExactInterlock 1
//-----------------------------------------------------------
// shell::Diagnostics
//-----------------------------------------------------------
class DiagnosticsObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmshell::DiagnosticsClass;
    REALLY_INLINE explicit DiagnosticsObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit DiagnosticsObject(const DiagnosticsObject&); // unimplemented
    void operator=(const DiagnosticsObject&); // unimplemented
};

#define avmplus_DiagnosticsObject_isExactInterlock 1
//-----------------------------------------------------------
// shell::HardwareInformation
//-----------------------------------------------------------
class HardwareInformationObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmshell::HardwareInformationClass;
    REALLY_INLINE explicit HardwareInformationObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit HardwareInformationObject(const HardwareInformationObject&); // unimplemented
    void operator=(const HardwareInformationObject&); // unimplemented
};

#define avmplus_HardwareInformationObject_isExactInterlock 1
//-----------------------------------------------------------
// shell::OperatingSystem
//-----------------------------------------------------------
class OperatingSystemObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmshell::OperatingSystemClass;
    REALLY_INLINE explicit OperatingSystemObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit OperatingSystemObject(const OperatingSystemObject&); // unimplemented
    void operator=(const OperatingSystemObject&); // unimplemented
};

#define avmplus_OperatingSystemObject_isExactInterlock 1
//-----------------------------------------------------------
// shell::FileSystem
//-----------------------------------------------------------
class FileSystemObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmshell::FileSystemClass;
    REALLY_INLINE explicit FileSystemObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit FileSystemObject(const FileSystemObject&); // unimplemented
    void operator=(const FileSystemObject&); // unimplemented
};

#define avmplus_FileSystemObject_isExactInterlock 1
//-----------------------------------------------------------
// shell::RunMode
//-----------------------------------------------------------
class RunModeObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::RunModeClass;
    REALLY_INLINE explicit RunModeObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit RunModeObject(const RunModeObject&); // unimplemented
    void operator=(const RunModeObject&); // unimplemented
};

#define avmplus_RunModeObject_isExactInterlock 1
//-----------------------------------------------------------
// shell::RunMode$
//-----------------------------------------------------------
class RunModeClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::RunModeObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::RunModeObject>((avmplus::RunModeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::RunModeObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::RunModeObject>((avmplus::RunModeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::RunModeObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::RunModeObject>((avmplus::RunModeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::RunModeObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::RunModeObject>((avmplus::RunModeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::RunModeObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::RunModeObject>((avmplus::RunModeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::String* get_UNKNOWN() const { return m_slots_RunModeClass.m_UNKNOWN; }
    REALLY_INLINE void setconst_UNKNOWN(avmplus::String* newVal) { m_slots_RunModeClass.m_UNKNOWN = newVal; }
public:
    REALLY_INLINE avmplus::String* get_MIXED() const { return m_slots_RunModeClass.m_MIXED; }
    REALLY_INLINE void setconst_MIXED(avmplus::String* newVal) { m_slots_RunModeClass.m_MIXED = newVal; }
public:
    REALLY_INLINE avmplus::String* get_JITORDIE() const { return m_slots_RunModeClass.m_JITORDIE; }
    REALLY_INLINE void setconst_JITORDIE(avmplus::String* newVal) { m_slots_RunModeClass.m_JITORDIE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_JIT() const { return m_slots_RunModeClass.m_JIT; }
    REALLY_INLINE void setconst_JIT(avmplus::String* newVal) { m_slots_RunModeClass.m_JIT = newVal; }
public:
    REALLY_INLINE avmplus::String* get_INTERP() const { return m_slots_RunModeClass.m_INTERP; }
    REALLY_INLINE void setconst_INTERP(avmplus::String* newVal) { m_slots_RunModeClass.m_INTERP = newVal; }
private:
    avmplus::NativeID::avmplus_RunModeClassSlots m_slots_RunModeClass;
protected:
    inline explicit RunModeClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit RunModeClass(const RunModeClass&); // unimplemented
    void operator=(const RunModeClass&); // unimplemented
};

#define avmplus_RunModeClass_isExactInterlock 1
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
// shell::BinaryData
//-----------------------------------------------------------
class BinaryDataObject : public avmplus::ByteArrayObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::BinaryDataClass;
    REALLY_INLINE explicit BinaryDataObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ByteArrayObject(ivtable, delegate) {}
private:
    explicit BinaryDataObject(const BinaryDataObject&); // unimplemented
    void operator=(const BinaryDataObject&); // unimplemented
};

#define avmplus_BinaryDataObject_isExactInterlock 1
//-----------------------------------------------------------
// shell::BinaryData$
//-----------------------------------------------------------
class BinaryDataClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::BinaryDataObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::BinaryDataObject>((avmplus::BinaryDataObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::BinaryDataObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::BinaryDataObject>((avmplus::BinaryDataObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::BinaryDataObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::BinaryDataObject>((avmplus::BinaryDataObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::BinaryDataObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::BinaryDataObject>((avmplus::BinaryDataObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::BinaryDataObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::BinaryDataObject>((avmplus::BinaryDataObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit BinaryDataClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit BinaryDataClass(const BinaryDataClass&); // unimplemented
    void operator=(const BinaryDataClass&); // unimplemented
};

#define avmplus_BinaryDataClass_isExactInterlock 1
//-----------------------------------------------------------
// shell.async::EventLoop
//-----------------------------------------------------------
class EventLoopInterface : public avmplus::ScriptObject
{
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::EventLoopClass;
    REALLY_INLINE explicit EventLoopInterface(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit EventLoopInterface(const EventLoopInterface&); // unimplemented
    void operator=(const EventLoopInterface&); // unimplemented
};

//-----------------------------------------------------------
// shell.async::EventLoop$
//-----------------------------------------------------------
class EventLoopClass : public avmplus::ClassClosure
{
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::EventLoopInterface> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::EventLoopInterface>((avmplus::EventLoopInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::EventLoopInterface> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::EventLoopInterface>((avmplus::EventLoopInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::EventLoopInterface> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::EventLoopInterface>((avmplus::EventLoopInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::EventLoopInterface> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::EventLoopInterface>((avmplus::EventLoopInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit EventLoopClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit EventLoopClass(const EventLoopClass&); // unimplemented
    void operator=(const EventLoopClass&); // unimplemented
};

//-----------------------------------------------------------
// flash.accessibility::ISearchableText
//-----------------------------------------------------------
class ISearchableTextInterface : public avmplus::ScriptObject
{
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::ISearchableTextClass;
    REALLY_INLINE explicit ISearchableTextInterface(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit ISearchableTextInterface(const ISearchableTextInterface&); // unimplemented
    void operator=(const ISearchableTextInterface&); // unimplemented
};

//-----------------------------------------------------------
// flash.accessibility::ISearchableText$
//-----------------------------------------------------------
class ISearchableTextClass : public avmplus::ClassClosure
{
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::ISearchableTextInterface> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::ISearchableTextInterface>((avmplus::ISearchableTextInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::ISearchableTextInterface> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::ISearchableTextInterface>((avmplus::ISearchableTextInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::ISearchableTextInterface> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::ISearchableTextInterface>((avmplus::ISearchableTextInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::ISearchableTextInterface> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::ISearchableTextInterface>((avmplus::ISearchableTextInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit ISearchableTextClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit ISearchableTextClass(const ISearchableTextClass&); // unimplemented
    void operator=(const ISearchableTextClass&); // unimplemented
};

//-----------------------------------------------------------
// flash.accessibility::ISimpleTextSelection
//-----------------------------------------------------------
class ISimpleTextSelectionInterface : public avmplus::ScriptObject
{
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::ISimpleTextSelectionClass;
    REALLY_INLINE explicit ISimpleTextSelectionInterface(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit ISimpleTextSelectionInterface(const ISimpleTextSelectionInterface&); // unimplemented
    void operator=(const ISimpleTextSelectionInterface&); // unimplemented
};

//-----------------------------------------------------------
// flash.accessibility::ISimpleTextSelection$
//-----------------------------------------------------------
class ISimpleTextSelectionClass : public avmplus::ClassClosure
{
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::ISimpleTextSelectionInterface> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::ISimpleTextSelectionInterface>((avmplus::ISimpleTextSelectionInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::ISimpleTextSelectionInterface> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::ISimpleTextSelectionInterface>((avmplus::ISimpleTextSelectionInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::ISimpleTextSelectionInterface> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::ISimpleTextSelectionInterface>((avmplus::ISimpleTextSelectionInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::ISimpleTextSelectionInterface> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::ISimpleTextSelectionInterface>((avmplus::ISimpleTextSelectionInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit ISimpleTextSelectionClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit ISimpleTextSelectionClass(const ISimpleTextSelectionClass&); // unimplemented
    void operator=(const ISimpleTextSelectionClass&); // unimplemented
};

//-----------------------------------------------------------
// flash.accessibility::Accessibility
//-----------------------------------------------------------
class AccessibilityObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::AccessibilityClass;
    REALLY_INLINE explicit AccessibilityObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit AccessibilityObject(const AccessibilityObject&); // unimplemented
    void operator=(const AccessibilityObject&); // unimplemented
};

#define avmplus_AccessibilityObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.accessibility::Accessibility$
//-----------------------------------------------------------
class AccessibilityClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::AccessibilityObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::AccessibilityObject>((avmplus::AccessibilityObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::AccessibilityObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::AccessibilityObject>((avmplus::AccessibilityObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::AccessibilityObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::AccessibilityObject>((avmplus::AccessibilityObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::AccessibilityObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::AccessibilityObject>((avmplus::AccessibilityObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::AccessibilityObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::AccessibilityObject>((avmplus::AccessibilityObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit AccessibilityClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit AccessibilityClass(const AccessibilityClass&); // unimplemented
    void operator=(const AccessibilityClass&); // unimplemented
};

#define avmplus_AccessibilityClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.accessibility::AccessibilityImplementation
//-----------------------------------------------------------
class AccessibilityImplementationObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE uint32_t get_errno() const { return m_slots_AccessibilityImplementationObject.m_errno; }
    REALLY_INLINE void set_errno(uint32_t newVal) { m_slots_AccessibilityImplementationObject.m_errno = newVal; }
public:
    REALLY_INLINE bool get_stub() const { return m_slots_AccessibilityImplementationObject.m_stub != 0; }
    REALLY_INLINE void set_stub(avmplus::bool32 newVal) { m_slots_AccessibilityImplementationObject.m_stub = newVal; }
private:
    avmplus::NativeID::avmplus_AccessibilityImplementationObjectSlots m_slots_AccessibilityImplementationObject;
protected:
    friend class avmplus::AccessibilityImplementationClass;
    REALLY_INLINE explicit AccessibilityImplementationObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit AccessibilityImplementationObject(const AccessibilityImplementationObject&); // unimplemented
    void operator=(const AccessibilityImplementationObject&); // unimplemented
};

#define avmplus_AccessibilityImplementationObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.accessibility::AccessibilityImplementation$
//-----------------------------------------------------------
class AccessibilityImplementationClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::AccessibilityImplementationObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::AccessibilityImplementationObject>((avmplus::AccessibilityImplementationObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::AccessibilityImplementationObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::AccessibilityImplementationObject>((avmplus::AccessibilityImplementationObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::AccessibilityImplementationObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::AccessibilityImplementationObject>((avmplus::AccessibilityImplementationObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::AccessibilityImplementationObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::AccessibilityImplementationObject>((avmplus::AccessibilityImplementationObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::AccessibilityImplementationObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::AccessibilityImplementationObject>((avmplus::AccessibilityImplementationObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit AccessibilityImplementationClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit AccessibilityImplementationClass(const AccessibilityImplementationClass&); // unimplemented
    void operator=(const AccessibilityImplementationClass&); // unimplemented
};

#define avmplus_AccessibilityImplementationClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.accessibility::AccessibilityProperties
//-----------------------------------------------------------
class AccessibilityPropertiesObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE bool get_silent() const { return m_slots_AccessibilityPropertiesObject.m_silent != 0; }
    REALLY_INLINE void set_silent(avmplus::bool32 newVal) { m_slots_AccessibilityPropertiesObject.m_silent = newVal; }
public:
    REALLY_INLINE bool get_forceSimple() const { return m_slots_AccessibilityPropertiesObject.m_forceSimple != 0; }
    REALLY_INLINE void set_forceSimple(avmplus::bool32 newVal) { m_slots_AccessibilityPropertiesObject.m_forceSimple = newVal; }
public:
    REALLY_INLINE bool get_noAutoLabeling() const { return m_slots_AccessibilityPropertiesObject.m_noAutoLabeling != 0; }
    REALLY_INLINE void set_noAutoLabeling(avmplus::bool32 newVal) { m_slots_AccessibilityPropertiesObject.m_noAutoLabeling = newVal; }
public:
    REALLY_INLINE avmplus::String* get_name() const { return m_slots_AccessibilityPropertiesObject.m_name; }
    REALLY_INLINE void set_name(avmplus::String* newVal) { m_slots_AccessibilityPropertiesObject.m_name = newVal; }
public:
    REALLY_INLINE avmplus::String* get_description() const { return m_slots_AccessibilityPropertiesObject.m_description; }
    REALLY_INLINE void set_description(avmplus::String* newVal) { m_slots_AccessibilityPropertiesObject.m_description = newVal; }
public:
    REALLY_INLINE avmplus::String* get_shortcut() const { return m_slots_AccessibilityPropertiesObject.m_shortcut; }
    REALLY_INLINE void set_shortcut(avmplus::String* newVal) { m_slots_AccessibilityPropertiesObject.m_shortcut = newVal; }
private:
    avmplus::NativeID::avmplus_AccessibilityPropertiesObjectSlots m_slots_AccessibilityPropertiesObject;
protected:
    friend class avmplus::AccessibilityPropertiesClass;
    REALLY_INLINE explicit AccessibilityPropertiesObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit AccessibilityPropertiesObject(const AccessibilityPropertiesObject&); // unimplemented
    void operator=(const AccessibilityPropertiesObject&); // unimplemented
};

#define avmplus_AccessibilityPropertiesObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.accessibility::AccessibilityProperties$
//-----------------------------------------------------------
class AccessibilityPropertiesClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::AccessibilityPropertiesObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::AccessibilityPropertiesObject>((avmplus::AccessibilityPropertiesObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::AccessibilityPropertiesObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::AccessibilityPropertiesObject>((avmplus::AccessibilityPropertiesObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::AccessibilityPropertiesObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::AccessibilityPropertiesObject>((avmplus::AccessibilityPropertiesObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::AccessibilityPropertiesObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::AccessibilityPropertiesObject>((avmplus::AccessibilityPropertiesObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::AccessibilityPropertiesObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::AccessibilityPropertiesObject>((avmplus::AccessibilityPropertiesObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit AccessibilityPropertiesClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit AccessibilityPropertiesClass(const AccessibilityPropertiesClass&); // unimplemented
    void operator=(const AccessibilityPropertiesClass&); // unimplemented
};

#define avmplus_AccessibilityPropertiesClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.data::EncryptedLocalStore
//-----------------------------------------------------------
class EncryptedLocalStoreObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::EncryptedLocalStoreClass;
    REALLY_INLINE explicit EncryptedLocalStoreObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit EncryptedLocalStoreObject(const EncryptedLocalStoreObject&); // unimplemented
    void operator=(const EncryptedLocalStoreObject&); // unimplemented
};

#define avmplus_EncryptedLocalStoreObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.data::EncryptedLocalStore$
//-----------------------------------------------------------
class EncryptedLocalStoreClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::EncryptedLocalStoreObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::EncryptedLocalStoreObject>((avmplus::EncryptedLocalStoreObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::EncryptedLocalStoreObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::EncryptedLocalStoreObject>((avmplus::EncryptedLocalStoreObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::EncryptedLocalStoreObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::EncryptedLocalStoreObject>((avmplus::EncryptedLocalStoreObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::EncryptedLocalStoreObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::EncryptedLocalStoreObject>((avmplus::EncryptedLocalStoreObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::EncryptedLocalStoreObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::EncryptedLocalStoreObject>((avmplus::EncryptedLocalStoreObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit EncryptedLocalStoreClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit EncryptedLocalStoreClass(const EncryptedLocalStoreClass&); // unimplemented
    void operator=(const EncryptedLocalStoreClass&); // unimplemented
};

#define avmplus_EncryptedLocalStoreClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.data::SQLCollationType
//-----------------------------------------------------------
class SQLCollationTypeObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::SQLCollationTypeClass;
    REALLY_INLINE explicit SQLCollationTypeObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit SQLCollationTypeObject(const SQLCollationTypeObject&); // unimplemented
    void operator=(const SQLCollationTypeObject&); // unimplemented
};

#define avmplus_SQLCollationTypeObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.data::SQLCollationType$
//-----------------------------------------------------------
class SQLCollationTypeClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::SQLCollationTypeObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::SQLCollationTypeObject>((avmplus::SQLCollationTypeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::SQLCollationTypeObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::SQLCollationTypeObject>((avmplus::SQLCollationTypeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLCollationTypeObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::SQLCollationTypeObject>((avmplus::SQLCollationTypeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLCollationTypeObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::SQLCollationTypeObject>((avmplus::SQLCollationTypeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLCollationTypeObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::SQLCollationTypeObject>((avmplus::SQLCollationTypeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit SQLCollationTypeClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit SQLCollationTypeClass(const SQLCollationTypeClass&); // unimplemented
    void operator=(const SQLCollationTypeClass&); // unimplemented
};

#define avmplus_SQLCollationTypeClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.data::SQLColumnNameStyle
//-----------------------------------------------------------
class SQLColumnNameStyleObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::SQLColumnNameStyleClass;
    REALLY_INLINE explicit SQLColumnNameStyleObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit SQLColumnNameStyleObject(const SQLColumnNameStyleObject&); // unimplemented
    void operator=(const SQLColumnNameStyleObject&); // unimplemented
};

#define avmplus_SQLColumnNameStyleObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.data::SQLColumnNameStyle$
//-----------------------------------------------------------
class SQLColumnNameStyleClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::SQLColumnNameStyleObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::SQLColumnNameStyleObject>((avmplus::SQLColumnNameStyleObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::SQLColumnNameStyleObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::SQLColumnNameStyleObject>((avmplus::SQLColumnNameStyleObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLColumnNameStyleObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::SQLColumnNameStyleObject>((avmplus::SQLColumnNameStyleObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLColumnNameStyleObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::SQLColumnNameStyleObject>((avmplus::SQLColumnNameStyleObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLColumnNameStyleObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::SQLColumnNameStyleObject>((avmplus::SQLColumnNameStyleObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit SQLColumnNameStyleClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit SQLColumnNameStyleClass(const SQLColumnNameStyleClass&); // unimplemented
    void operator=(const SQLColumnNameStyleClass&); // unimplemented
};

#define avmplus_SQLColumnNameStyleClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.data::SQLColumnSchema
//-----------------------------------------------------------
class SQLColumnSchemaObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::SQLColumnSchemaClass;
    REALLY_INLINE explicit SQLColumnSchemaObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit SQLColumnSchemaObject(const SQLColumnSchemaObject&); // unimplemented
    void operator=(const SQLColumnSchemaObject&); // unimplemented
};

#define avmplus_SQLColumnSchemaObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.data::SQLColumnSchema$
//-----------------------------------------------------------
class SQLColumnSchemaClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::SQLColumnSchemaObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::SQLColumnSchemaObject>((avmplus::SQLColumnSchemaObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::SQLColumnSchemaObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::SQLColumnSchemaObject>((avmplus::SQLColumnSchemaObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLColumnSchemaObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::SQLColumnSchemaObject>((avmplus::SQLColumnSchemaObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLColumnSchemaObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::SQLColumnSchemaObject>((avmplus::SQLColumnSchemaObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLColumnSchemaObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::SQLColumnSchemaObject>((avmplus::SQLColumnSchemaObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit SQLColumnSchemaClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit SQLColumnSchemaClass(const SQLColumnSchemaClass&); // unimplemented
    void operator=(const SQLColumnSchemaClass&); // unimplemented
};

#define avmplus_SQLColumnSchemaClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.data::SQLConnection
//-----------------------------------------------------------
class SQLConnectionObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::SQLConnectionClass;
    REALLY_INLINE explicit SQLConnectionObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit SQLConnectionObject(const SQLConnectionObject&); // unimplemented
    void operator=(const SQLConnectionObject&); // unimplemented
};

#define avmplus_SQLConnectionObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.data::SQLConnection$
//-----------------------------------------------------------
class SQLConnectionClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::SQLConnectionObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::SQLConnectionObject>((avmplus::SQLConnectionObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::SQLConnectionObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::SQLConnectionObject>((avmplus::SQLConnectionObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLConnectionObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::SQLConnectionObject>((avmplus::SQLConnectionObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLConnectionObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::SQLConnectionObject>((avmplus::SQLConnectionObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLConnectionObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::SQLConnectionObject>((avmplus::SQLConnectionObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit SQLConnectionClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit SQLConnectionClass(const SQLConnectionClass&); // unimplemented
    void operator=(const SQLConnectionClass&); // unimplemented
};

#define avmplus_SQLConnectionClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.data::SQLIndexSchema
//-----------------------------------------------------------
class SQLIndexSchemaObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::SQLIndexSchemaClass;
    REALLY_INLINE explicit SQLIndexSchemaObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit SQLIndexSchemaObject(const SQLIndexSchemaObject&); // unimplemented
    void operator=(const SQLIndexSchemaObject&); // unimplemented
};

#define avmplus_SQLIndexSchemaObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.data::SQLIndexSchema$
//-----------------------------------------------------------
class SQLIndexSchemaClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::SQLIndexSchemaObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::SQLIndexSchemaObject>((avmplus::SQLIndexSchemaObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::SQLIndexSchemaObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::SQLIndexSchemaObject>((avmplus::SQLIndexSchemaObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLIndexSchemaObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::SQLIndexSchemaObject>((avmplus::SQLIndexSchemaObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLIndexSchemaObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::SQLIndexSchemaObject>((avmplus::SQLIndexSchemaObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLIndexSchemaObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::SQLIndexSchemaObject>((avmplus::SQLIndexSchemaObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit SQLIndexSchemaClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit SQLIndexSchemaClass(const SQLIndexSchemaClass&); // unimplemented
    void operator=(const SQLIndexSchemaClass&); // unimplemented
};

#define avmplus_SQLIndexSchemaClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.data::SQLMode
//-----------------------------------------------------------
class SQLModeObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::SQLModeClass;
    REALLY_INLINE explicit SQLModeObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit SQLModeObject(const SQLModeObject&); // unimplemented
    void operator=(const SQLModeObject&); // unimplemented
};

#define avmplus_SQLModeObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.data::SQLMode$
//-----------------------------------------------------------
class SQLModeClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::SQLModeObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::SQLModeObject>((avmplus::SQLModeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::SQLModeObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::SQLModeObject>((avmplus::SQLModeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLModeObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::SQLModeObject>((avmplus::SQLModeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLModeObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::SQLModeObject>((avmplus::SQLModeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLModeObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::SQLModeObject>((avmplus::SQLModeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit SQLModeClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit SQLModeClass(const SQLModeClass&); // unimplemented
    void operator=(const SQLModeClass&); // unimplemented
};

#define avmplus_SQLModeClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.data::SQLResult
//-----------------------------------------------------------
class SQLResultObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::SQLResultClass;
    REALLY_INLINE explicit SQLResultObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit SQLResultObject(const SQLResultObject&); // unimplemented
    void operator=(const SQLResultObject&); // unimplemented
};

#define avmplus_SQLResultObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.data::SQLResult$
//-----------------------------------------------------------
class SQLResultClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::SQLResultObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::SQLResultObject>((avmplus::SQLResultObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::SQLResultObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::SQLResultObject>((avmplus::SQLResultObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLResultObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::SQLResultObject>((avmplus::SQLResultObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLResultObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::SQLResultObject>((avmplus::SQLResultObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLResultObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::SQLResultObject>((avmplus::SQLResultObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit SQLResultClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit SQLResultClass(const SQLResultClass&); // unimplemented
    void operator=(const SQLResultClass&); // unimplemented
};

#define avmplus_SQLResultClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.data::SQLSchema
//-----------------------------------------------------------
class SQLSchemaObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::SQLSchemaClass;
    REALLY_INLINE explicit SQLSchemaObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit SQLSchemaObject(const SQLSchemaObject&); // unimplemented
    void operator=(const SQLSchemaObject&); // unimplemented
};

#define avmplus_SQLSchemaObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.data::SQLSchema$
//-----------------------------------------------------------
class SQLSchemaClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::SQLSchemaObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::SQLSchemaObject>((avmplus::SQLSchemaObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::SQLSchemaObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::SQLSchemaObject>((avmplus::SQLSchemaObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLSchemaObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::SQLSchemaObject>((avmplus::SQLSchemaObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLSchemaObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::SQLSchemaObject>((avmplus::SQLSchemaObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLSchemaObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::SQLSchemaObject>((avmplus::SQLSchemaObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit SQLSchemaClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit SQLSchemaClass(const SQLSchemaClass&); // unimplemented
    void operator=(const SQLSchemaClass&); // unimplemented
};

#define avmplus_SQLSchemaClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.data::SQLSchemaResult
//-----------------------------------------------------------
class SQLSchemaResultObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::SQLSchemaResultClass;
    REALLY_INLINE explicit SQLSchemaResultObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit SQLSchemaResultObject(const SQLSchemaResultObject&); // unimplemented
    void operator=(const SQLSchemaResultObject&); // unimplemented
};

#define avmplus_SQLSchemaResultObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.data::SQLSchemaResult$
//-----------------------------------------------------------
class SQLSchemaResultClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::SQLSchemaResultObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::SQLSchemaResultObject>((avmplus::SQLSchemaResultObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::SQLSchemaResultObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::SQLSchemaResultObject>((avmplus::SQLSchemaResultObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLSchemaResultObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::SQLSchemaResultObject>((avmplus::SQLSchemaResultObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLSchemaResultObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::SQLSchemaResultObject>((avmplus::SQLSchemaResultObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLSchemaResultObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::SQLSchemaResultObject>((avmplus::SQLSchemaResultObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit SQLSchemaResultClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit SQLSchemaResultClass(const SQLSchemaResultClass&); // unimplemented
    void operator=(const SQLSchemaResultClass&); // unimplemented
};

#define avmplus_SQLSchemaResultClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.data::SQLStatement
//-----------------------------------------------------------
class SQLStatementObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::SQLStatementClass;
    REALLY_INLINE explicit SQLStatementObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit SQLStatementObject(const SQLStatementObject&); // unimplemented
    void operator=(const SQLStatementObject&); // unimplemented
};

#define avmplus_SQLStatementObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.data::SQLStatement$
//-----------------------------------------------------------
class SQLStatementClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::SQLStatementObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::SQLStatementObject>((avmplus::SQLStatementObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::SQLStatementObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::SQLStatementObject>((avmplus::SQLStatementObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLStatementObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::SQLStatementObject>((avmplus::SQLStatementObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLStatementObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::SQLStatementObject>((avmplus::SQLStatementObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLStatementObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::SQLStatementObject>((avmplus::SQLStatementObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit SQLStatementClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit SQLStatementClass(const SQLStatementClass&); // unimplemented
    void operator=(const SQLStatementClass&); // unimplemented
};

#define avmplus_SQLStatementClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.data::SQLTableSchema
//-----------------------------------------------------------
class SQLTableSchemaObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::SQLTableSchemaClass;
    REALLY_INLINE explicit SQLTableSchemaObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit SQLTableSchemaObject(const SQLTableSchemaObject&); // unimplemented
    void operator=(const SQLTableSchemaObject&); // unimplemented
};

#define avmplus_SQLTableSchemaObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.data::SQLTableSchema$
//-----------------------------------------------------------
class SQLTableSchemaClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::SQLTableSchemaObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::SQLTableSchemaObject>((avmplus::SQLTableSchemaObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::SQLTableSchemaObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::SQLTableSchemaObject>((avmplus::SQLTableSchemaObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLTableSchemaObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::SQLTableSchemaObject>((avmplus::SQLTableSchemaObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLTableSchemaObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::SQLTableSchemaObject>((avmplus::SQLTableSchemaObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLTableSchemaObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::SQLTableSchemaObject>((avmplus::SQLTableSchemaObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit SQLTableSchemaClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit SQLTableSchemaClass(const SQLTableSchemaClass&); // unimplemented
    void operator=(const SQLTableSchemaClass&); // unimplemented
};

#define avmplus_SQLTableSchemaClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.data::SQLTransactionLockType
//-----------------------------------------------------------
class SQLTransactionLockTypeObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::SQLTransactionLockTypeClass;
    REALLY_INLINE explicit SQLTransactionLockTypeObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit SQLTransactionLockTypeObject(const SQLTransactionLockTypeObject&); // unimplemented
    void operator=(const SQLTransactionLockTypeObject&); // unimplemented
};

#define avmplus_SQLTransactionLockTypeObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.data::SQLTransactionLockType$
//-----------------------------------------------------------
class SQLTransactionLockTypeClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::SQLTransactionLockTypeObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::SQLTransactionLockTypeObject>((avmplus::SQLTransactionLockTypeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::SQLTransactionLockTypeObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::SQLTransactionLockTypeObject>((avmplus::SQLTransactionLockTypeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLTransactionLockTypeObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::SQLTransactionLockTypeObject>((avmplus::SQLTransactionLockTypeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLTransactionLockTypeObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::SQLTransactionLockTypeObject>((avmplus::SQLTransactionLockTypeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLTransactionLockTypeObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::SQLTransactionLockTypeObject>((avmplus::SQLTransactionLockTypeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit SQLTransactionLockTypeClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit SQLTransactionLockTypeClass(const SQLTransactionLockTypeClass&); // unimplemented
    void operator=(const SQLTransactionLockTypeClass&); // unimplemented
};

#define avmplus_SQLTransactionLockTypeClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.data::SQLTriggerSchema
//-----------------------------------------------------------
class SQLTriggerSchemaObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::SQLTriggerSchemaClass;
    REALLY_INLINE explicit SQLTriggerSchemaObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit SQLTriggerSchemaObject(const SQLTriggerSchemaObject&); // unimplemented
    void operator=(const SQLTriggerSchemaObject&); // unimplemented
};

#define avmplus_SQLTriggerSchemaObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.data::SQLTriggerSchema$
//-----------------------------------------------------------
class SQLTriggerSchemaClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::SQLTriggerSchemaObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::SQLTriggerSchemaObject>((avmplus::SQLTriggerSchemaObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::SQLTriggerSchemaObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::SQLTriggerSchemaObject>((avmplus::SQLTriggerSchemaObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLTriggerSchemaObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::SQLTriggerSchemaObject>((avmplus::SQLTriggerSchemaObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLTriggerSchemaObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::SQLTriggerSchemaObject>((avmplus::SQLTriggerSchemaObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLTriggerSchemaObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::SQLTriggerSchemaObject>((avmplus::SQLTriggerSchemaObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit SQLTriggerSchemaClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit SQLTriggerSchemaClass(const SQLTriggerSchemaClass&); // unimplemented
    void operator=(const SQLTriggerSchemaClass&); // unimplemented
};

#define avmplus_SQLTriggerSchemaClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.data::SQLViewSchema
//-----------------------------------------------------------
class SQLViewSchemaObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::SQLViewSchemaClass;
    REALLY_INLINE explicit SQLViewSchemaObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit SQLViewSchemaObject(const SQLViewSchemaObject&); // unimplemented
    void operator=(const SQLViewSchemaObject&); // unimplemented
};

#define avmplus_SQLViewSchemaObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.data::SQLViewSchema$
//-----------------------------------------------------------
class SQLViewSchemaClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::SQLViewSchemaObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::SQLViewSchemaObject>((avmplus::SQLViewSchemaObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::SQLViewSchemaObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::SQLViewSchemaObject>((avmplus::SQLViewSchemaObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLViewSchemaObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::SQLViewSchemaObject>((avmplus::SQLViewSchemaObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLViewSchemaObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::SQLViewSchemaObject>((avmplus::SQLViewSchemaObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SQLViewSchemaObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::SQLViewSchemaObject>((avmplus::SQLViewSchemaObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit SQLViewSchemaClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit SQLViewSchemaClass(const SQLViewSchemaClass&); // unimplemented
    void operator=(const SQLViewSchemaClass&); // unimplemented
};

#define avmplus_SQLViewSchemaClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.display::IBitmapDrawable
//-----------------------------------------------------------
class IBitmapDrawableInterface : public avmplus::ScriptObject
{
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::IBitmapDrawableClass;
    REALLY_INLINE explicit IBitmapDrawableInterface(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit IBitmapDrawableInterface(const IBitmapDrawableInterface&); // unimplemented
    void operator=(const IBitmapDrawableInterface&); // unimplemented
};

//-----------------------------------------------------------
// flash.display::IBitmapDrawable$
//-----------------------------------------------------------
class IBitmapDrawableClass : public avmplus::ClassClosure
{
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::IBitmapDrawableInterface> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::IBitmapDrawableInterface>((avmplus::IBitmapDrawableInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IBitmapDrawableInterface> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::IBitmapDrawableInterface>((avmplus::IBitmapDrawableInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IBitmapDrawableInterface> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::IBitmapDrawableInterface>((avmplus::IBitmapDrawableInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IBitmapDrawableInterface> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::IBitmapDrawableInterface>((avmplus::IBitmapDrawableInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit IBitmapDrawableClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit IBitmapDrawableClass(const IBitmapDrawableClass&); // unimplemented
    void operator=(const IBitmapDrawableClass&); // unimplemented
};

//-----------------------------------------------------------
// flash.display::IDrawCommand
//-----------------------------------------------------------
class IDrawCommandInterface : public avmplus::ScriptObject
{
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::IDrawCommandClass;
    REALLY_INLINE explicit IDrawCommandInterface(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit IDrawCommandInterface(const IDrawCommandInterface&); // unimplemented
    void operator=(const IDrawCommandInterface&); // unimplemented
};

//-----------------------------------------------------------
// flash.display::IDrawCommand$
//-----------------------------------------------------------
class IDrawCommandClass : public avmplus::ClassClosure
{
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::IDrawCommandInterface> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::IDrawCommandInterface>((avmplus::IDrawCommandInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IDrawCommandInterface> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::IDrawCommandInterface>((avmplus::IDrawCommandInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IDrawCommandInterface> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::IDrawCommandInterface>((avmplus::IDrawCommandInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IDrawCommandInterface> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::IDrawCommandInterface>((avmplus::IDrawCommandInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit IDrawCommandClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit IDrawCommandClass(const IDrawCommandClass&); // unimplemented
    void operator=(const IDrawCommandClass&); // unimplemented
};

//-----------------------------------------------------------
// flash.display::IGraphicsData
//-----------------------------------------------------------
class IGraphicsDataInterface : public avmplus::ScriptObject
{
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::IGraphicsDataClass;
    REALLY_INLINE explicit IGraphicsDataInterface(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit IGraphicsDataInterface(const IGraphicsDataInterface&); // unimplemented
    void operator=(const IGraphicsDataInterface&); // unimplemented
};

//-----------------------------------------------------------
// flash.display::IGraphicsData$
//-----------------------------------------------------------
class IGraphicsDataClass : public avmplus::ClassClosure
{
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::IGraphicsDataInterface> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::IGraphicsDataInterface>((avmplus::IGraphicsDataInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IGraphicsDataInterface> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::IGraphicsDataInterface>((avmplus::IGraphicsDataInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IGraphicsDataInterface> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::IGraphicsDataInterface>((avmplus::IGraphicsDataInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IGraphicsDataInterface> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::IGraphicsDataInterface>((avmplus::IGraphicsDataInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit IGraphicsDataClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit IGraphicsDataClass(const IGraphicsDataClass&); // unimplemented
    void operator=(const IGraphicsDataClass&); // unimplemented
};

//-----------------------------------------------------------
// flash.display::IGraphicsFill
//-----------------------------------------------------------
class IGraphicsFillInterface : public avmplus::ScriptObject
{
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::IGraphicsFillClass;
    REALLY_INLINE explicit IGraphicsFillInterface(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit IGraphicsFillInterface(const IGraphicsFillInterface&); // unimplemented
    void operator=(const IGraphicsFillInterface&); // unimplemented
};

//-----------------------------------------------------------
// flash.display::IGraphicsFill$
//-----------------------------------------------------------
class IGraphicsFillClass : public avmplus::ClassClosure
{
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::IGraphicsFillInterface> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::IGraphicsFillInterface>((avmplus::IGraphicsFillInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IGraphicsFillInterface> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::IGraphicsFillInterface>((avmplus::IGraphicsFillInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IGraphicsFillInterface> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::IGraphicsFillInterface>((avmplus::IGraphicsFillInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IGraphicsFillInterface> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::IGraphicsFillInterface>((avmplus::IGraphicsFillInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit IGraphicsFillClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit IGraphicsFillClass(const IGraphicsFillClass&); // unimplemented
    void operator=(const IGraphicsFillClass&); // unimplemented
};

//-----------------------------------------------------------
// flash.display::IGraphicsPath
//-----------------------------------------------------------
class IGraphicsPathInterface : public avmplus::ScriptObject
{
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::IGraphicsPathClass;
    REALLY_INLINE explicit IGraphicsPathInterface(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit IGraphicsPathInterface(const IGraphicsPathInterface&); // unimplemented
    void operator=(const IGraphicsPathInterface&); // unimplemented
};

//-----------------------------------------------------------
// flash.display::IGraphicsPath$
//-----------------------------------------------------------
class IGraphicsPathClass : public avmplus::ClassClosure
{
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::IGraphicsPathInterface> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::IGraphicsPathInterface>((avmplus::IGraphicsPathInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IGraphicsPathInterface> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::IGraphicsPathInterface>((avmplus::IGraphicsPathInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IGraphicsPathInterface> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::IGraphicsPathInterface>((avmplus::IGraphicsPathInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IGraphicsPathInterface> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::IGraphicsPathInterface>((avmplus::IGraphicsPathInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit IGraphicsPathClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit IGraphicsPathClass(const IGraphicsPathClass&); // unimplemented
    void operator=(const IGraphicsPathClass&); // unimplemented
};

//-----------------------------------------------------------
// flash.display::IGraphicsStroke
//-----------------------------------------------------------
class IGraphicsStrokeInterface : public avmplus::ScriptObject
{
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::IGraphicsStrokeClass;
    REALLY_INLINE explicit IGraphicsStrokeInterface(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit IGraphicsStrokeInterface(const IGraphicsStrokeInterface&); // unimplemented
    void operator=(const IGraphicsStrokeInterface&); // unimplemented
};

//-----------------------------------------------------------
// flash.display::IGraphicsStroke$
//-----------------------------------------------------------
class IGraphicsStrokeClass : public avmplus::ClassClosure
{
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::IGraphicsStrokeInterface> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::IGraphicsStrokeInterface>((avmplus::IGraphicsStrokeInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IGraphicsStrokeInterface> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::IGraphicsStrokeInterface>((avmplus::IGraphicsStrokeInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IGraphicsStrokeInterface> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::IGraphicsStrokeInterface>((avmplus::IGraphicsStrokeInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IGraphicsStrokeInterface> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::IGraphicsStrokeInterface>((avmplus::IGraphicsStrokeInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit IGraphicsStrokeClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit IGraphicsStrokeClass(const IGraphicsStrokeClass&); // unimplemented
    void operator=(const IGraphicsStrokeClass&); // unimplemented
};

//-----------------------------------------------------------
// flash.display::ActionScriptVersion
//-----------------------------------------------------------
class ActionScriptVersionObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::ActionScriptVersionClass;
    REALLY_INLINE explicit ActionScriptVersionObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit ActionScriptVersionObject(const ActionScriptVersionObject&); // unimplemented
    void operator=(const ActionScriptVersionObject&); // unimplemented
};

#define avmplus_ActionScriptVersionObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.display::ActionScriptVersion$
//-----------------------------------------------------------
class ActionScriptVersionClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::ActionScriptVersionObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::ActionScriptVersionObject>((avmplus::ActionScriptVersionObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::ActionScriptVersionObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::ActionScriptVersionObject>((avmplus::ActionScriptVersionObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::ActionScriptVersionObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::ActionScriptVersionObject>((avmplus::ActionScriptVersionObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::ActionScriptVersionObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::ActionScriptVersionObject>((avmplus::ActionScriptVersionObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::ActionScriptVersionObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::ActionScriptVersionObject>((avmplus::ActionScriptVersionObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE uint32_t get_ACTIONSCRIPT2() const { return m_slots_ActionScriptVersionClass.m_ACTIONSCRIPT2; }
    REALLY_INLINE void setconst_ACTIONSCRIPT2(uint32_t newVal) { m_slots_ActionScriptVersionClass.m_ACTIONSCRIPT2 = newVal; }
public:
    REALLY_INLINE uint32_t get_ACTIONSCRIPT3() const { return m_slots_ActionScriptVersionClass.m_ACTIONSCRIPT3; }
    REALLY_INLINE void setconst_ACTIONSCRIPT3(uint32_t newVal) { m_slots_ActionScriptVersionClass.m_ACTIONSCRIPT3 = newVal; }
private:
    avmplus::NativeID::avmplus_ActionScriptVersionClassSlots m_slots_ActionScriptVersionClass;
protected:
    inline explicit ActionScriptVersionClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit ActionScriptVersionClass(const ActionScriptVersionClass&); // unimplemented
    void operator=(const ActionScriptVersionClass&); // unimplemented
};

#define avmplus_ActionScriptVersionClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.display::PixelSnapping
//-----------------------------------------------------------
class PixelSnappingObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::PixelSnappingClass;
    REALLY_INLINE explicit PixelSnappingObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit PixelSnappingObject(const PixelSnappingObject&); // unimplemented
    void operator=(const PixelSnappingObject&); // unimplemented
};

#define avmplus_PixelSnappingObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.display::PixelSnapping$
//-----------------------------------------------------------
class PixelSnappingClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::PixelSnappingObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::PixelSnappingObject>((avmplus::PixelSnappingObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::PixelSnappingObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::PixelSnappingObject>((avmplus::PixelSnappingObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::PixelSnappingObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::PixelSnappingObject>((avmplus::PixelSnappingObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::PixelSnappingObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::PixelSnappingObject>((avmplus::PixelSnappingObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::PixelSnappingObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::PixelSnappingObject>((avmplus::PixelSnappingObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::String* get_NEVER() const { return m_slots_PixelSnappingClass.m_NEVER; }
    REALLY_INLINE void setconst_NEVER(avmplus::String* newVal) { m_slots_PixelSnappingClass.m_NEVER = newVal; }
public:
    REALLY_INLINE avmplus::String* get_ALWAYS() const { return m_slots_PixelSnappingClass.m_ALWAYS; }
    REALLY_INLINE void setconst_ALWAYS(avmplus::String* newVal) { m_slots_PixelSnappingClass.m_ALWAYS = newVal; }
public:
    REALLY_INLINE avmplus::String* get_AUTO() const { return m_slots_PixelSnappingClass.m_AUTO; }
    REALLY_INLINE void setconst_AUTO(avmplus::String* newVal) { m_slots_PixelSnappingClass.m_AUTO = newVal; }
private:
    avmplus::NativeID::avmplus_PixelSnappingClassSlots m_slots_PixelSnappingClass;
protected:
    inline explicit PixelSnappingClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit PixelSnappingClass(const PixelSnappingClass&); // unimplemented
    void operator=(const PixelSnappingClass&); // unimplemented
};

#define avmplus_PixelSnappingClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.display::PNGEncoderOptions
//-----------------------------------------------------------
class PNGEncoderOptionsObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE bool get_fastCompression() const { return m_slots_PNGEncoderOptionsObject.m_fastCompression != 0; }
    REALLY_INLINE void set_fastCompression(avmplus::bool32 newVal) { m_slots_PNGEncoderOptionsObject.m_fastCompression = newVal; }
private:
    avmplus::NativeID::avmplus_PNGEncoderOptionsObjectSlots m_slots_PNGEncoderOptionsObject;
protected:
    friend class avmplus::PNGEncoderOptionsClass;
    REALLY_INLINE explicit PNGEncoderOptionsObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit PNGEncoderOptionsObject(const PNGEncoderOptionsObject&); // unimplemented
    void operator=(const PNGEncoderOptionsObject&); // unimplemented
};

#define avmplus_PNGEncoderOptionsObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.display::PNGEncoderOptions$
//-----------------------------------------------------------
class PNGEncoderOptionsClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::PNGEncoderOptionsObject> constructObject(bool arg1)
    {
        avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), ((arg1) ? trueAtom : falseAtom) };
        avmplus::Atom const result = this->construct(1, args);
        return GCRef<avmplus::PNGEncoderOptionsObject>((avmplus::PNGEncoderOptionsObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::PNGEncoderOptionsObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::PNGEncoderOptionsObject>((avmplus::PNGEncoderOptionsObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::PNGEncoderOptionsObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::PNGEncoderOptionsObject>((avmplus::PNGEncoderOptionsObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::PNGEncoderOptionsObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::PNGEncoderOptionsObject>((avmplus::PNGEncoderOptionsObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::PNGEncoderOptionsObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::PNGEncoderOptionsObject>((avmplus::PNGEncoderOptionsObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::PNGEncoderOptionsObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::PNGEncoderOptionsObject>((avmplus::PNGEncoderOptionsObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit PNGEncoderOptionsClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit PNGEncoderOptionsClass(const PNGEncoderOptionsClass&); // unimplemented
    void operator=(const PNGEncoderOptionsClass&); // unimplemented
};

#define avmplus_PNGEncoderOptionsClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.display::Scene
//-----------------------------------------------------------
class SceneObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    REALLY_INLINE int32_t get__numFrames() const { return m_slots_SceneObject.m_private__numFrames; }
    REALLY_INLINE void set__numFrames(int32_t newVal) { m_slots_SceneObject.m_private__numFrames = newVal; }
protected:
    REALLY_INLINE avmplus::String* get__name() const { return m_slots_SceneObject.m_private__name; }
    REALLY_INLINE void set__name(avmplus::String* newVal) { m_slots_SceneObject.m_private__name = newVal; }
protected:
    REALLY_INLINE avmplus::ArrayObject* get__labels() const { return m_slots_SceneObject.m_private__labels; }
    REALLY_INLINE void set__labels(avmplus::ArrayObject* newVal) { m_slots_SceneObject.m_private__labels = newVal; }
private:
    avmplus::NativeID::avmplus_SceneObjectSlots m_slots_SceneObject;
protected:
    friend class avmplus::SceneClass;
    REALLY_INLINE explicit SceneObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit SceneObject(const SceneObject&); // unimplemented
    void operator=(const SceneObject&); // unimplemented
};

#define avmplus_SceneObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.display::Scene$
//-----------------------------------------------------------
class SceneClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::SceneObject> constructObject(GCRef<avmplus::String> arg1, GCRef<avmplus::ArrayObject> arg2, int32_t arg3)
    {
        avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core()));
        avmplus::Atom args[4] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom(), arg2.reinterpretCast<avmplus::ScriptObject>()->atom(), core->intToAtom(arg3) };
        avmplus::Atom const result = this->construct(3, args);
        return GCRef<avmplus::SceneObject>((avmplus::SceneObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::SceneObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::SceneObject>((avmplus::SceneObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SceneObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::SceneObject>((avmplus::SceneObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SceneObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::SceneObject>((avmplus::SceneObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SceneObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::SceneObject>((avmplus::SceneObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit SceneClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit SceneClass(const SceneClass&); // unimplemented
    void operator=(const SceneClass&); // unimplemented
};

#define avmplus_SceneClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.display::StageAlign
//-----------------------------------------------------------
class StageAlignObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::StageAlignClass;
    REALLY_INLINE explicit StageAlignObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit StageAlignObject(const StageAlignObject&); // unimplemented
    void operator=(const StageAlignObject&); // unimplemented
};

#define avmplus_StageAlignObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.display::StageAlign$
//-----------------------------------------------------------
class StageAlignClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::StageAlignObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::StageAlignObject>((avmplus::StageAlignObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::StageAlignObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::StageAlignObject>((avmplus::StageAlignObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::StageAlignObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::StageAlignObject>((avmplus::StageAlignObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::StageAlignObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::StageAlignObject>((avmplus::StageAlignObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::StageAlignObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::StageAlignObject>((avmplus::StageAlignObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::String* get_TOP() const { return m_slots_StageAlignClass.m_TOP; }
    REALLY_INLINE void setconst_TOP(avmplus::String* newVal) { m_slots_StageAlignClass.m_TOP = newVal; }
public:
    REALLY_INLINE avmplus::String* get_LEFT() const { return m_slots_StageAlignClass.m_LEFT; }
    REALLY_INLINE void setconst_LEFT(avmplus::String* newVal) { m_slots_StageAlignClass.m_LEFT = newVal; }
public:
    REALLY_INLINE avmplus::String* get_BOTTOM() const { return m_slots_StageAlignClass.m_BOTTOM; }
    REALLY_INLINE void setconst_BOTTOM(avmplus::String* newVal) { m_slots_StageAlignClass.m_BOTTOM = newVal; }
public:
    REALLY_INLINE avmplus::String* get_RIGHT() const { return m_slots_StageAlignClass.m_RIGHT; }
    REALLY_INLINE void setconst_RIGHT(avmplus::String* newVal) { m_slots_StageAlignClass.m_RIGHT = newVal; }
public:
    REALLY_INLINE avmplus::String* get_TOP_LEFT() const { return m_slots_StageAlignClass.m_TOP_LEFT; }
    REALLY_INLINE void setconst_TOP_LEFT(avmplus::String* newVal) { m_slots_StageAlignClass.m_TOP_LEFT = newVal; }
public:
    REALLY_INLINE avmplus::String* get_TOP_RIGHT() const { return m_slots_StageAlignClass.m_TOP_RIGHT; }
    REALLY_INLINE void setconst_TOP_RIGHT(avmplus::String* newVal) { m_slots_StageAlignClass.m_TOP_RIGHT = newVal; }
public:
    REALLY_INLINE avmplus::String* get_BOTTOM_LEFT() const { return m_slots_StageAlignClass.m_BOTTOM_LEFT; }
    REALLY_INLINE void setconst_BOTTOM_LEFT(avmplus::String* newVal) { m_slots_StageAlignClass.m_BOTTOM_LEFT = newVal; }
public:
    REALLY_INLINE avmplus::String* get_BOTTOM_RIGHT() const { return m_slots_StageAlignClass.m_BOTTOM_RIGHT; }
    REALLY_INLINE void setconst_BOTTOM_RIGHT(avmplus::String* newVal) { m_slots_StageAlignClass.m_BOTTOM_RIGHT = newVal; }
private:
    avmplus::NativeID::avmplus_StageAlignClassSlots m_slots_StageAlignClass;
protected:
    inline explicit StageAlignClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit StageAlignClass(const StageAlignClass&); // unimplemented
    void operator=(const StageAlignClass&); // unimplemented
};

#define avmplus_StageAlignClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.display::StageAspectRatio
//-----------------------------------------------------------
class StageAspectRatioObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::StageAspectRatioClass;
    REALLY_INLINE explicit StageAspectRatioObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit StageAspectRatioObject(const StageAspectRatioObject&); // unimplemented
    void operator=(const StageAspectRatioObject&); // unimplemented
};

#define avmplus_StageAspectRatioObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.display::StageAspectRatio$
//-----------------------------------------------------------
class StageAspectRatioClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::StageAspectRatioObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::StageAspectRatioObject>((avmplus::StageAspectRatioObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::StageAspectRatioObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::StageAspectRatioObject>((avmplus::StageAspectRatioObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::StageAspectRatioObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::StageAspectRatioObject>((avmplus::StageAspectRatioObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::StageAspectRatioObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::StageAspectRatioObject>((avmplus::StageAspectRatioObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::StageAspectRatioObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::StageAspectRatioObject>((avmplus::StageAspectRatioObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::String* get_ANY() const { return m_slots_StageAspectRatioClass.m_ANY; }
    REALLY_INLINE void setconst_ANY(avmplus::String* newVal) { m_slots_StageAspectRatioClass.m_ANY = newVal; }
public:
    REALLY_INLINE avmplus::String* get_LANDSCAPE() const { return m_slots_StageAspectRatioClass.m_LANDSCAPE; }
    REALLY_INLINE void setconst_LANDSCAPE(avmplus::String* newVal) { m_slots_StageAspectRatioClass.m_LANDSCAPE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_PORTRAIT() const { return m_slots_StageAspectRatioClass.m_PORTRAIT; }
    REALLY_INLINE void setconst_PORTRAIT(avmplus::String* newVal) { m_slots_StageAspectRatioClass.m_PORTRAIT = newVal; }
private:
    avmplus::NativeID::avmplus_StageAspectRatioClassSlots m_slots_StageAspectRatioClass;
protected:
    inline explicit StageAspectRatioClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit StageAspectRatioClass(const StageAspectRatioClass&); // unimplemented
    void operator=(const StageAspectRatioClass&); // unimplemented
};

#define avmplus_StageAspectRatioClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.display::StageDisplayState
//-----------------------------------------------------------
class StageDisplayStateObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::StageDisplayStateClass;
    REALLY_INLINE explicit StageDisplayStateObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit StageDisplayStateObject(const StageDisplayStateObject&); // unimplemented
    void operator=(const StageDisplayStateObject&); // unimplemented
};

#define avmplus_StageDisplayStateObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.display::StageDisplayState$
//-----------------------------------------------------------
class StageDisplayStateClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::StageDisplayStateObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::StageDisplayStateObject>((avmplus::StageDisplayStateObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::StageDisplayStateObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::StageDisplayStateObject>((avmplus::StageDisplayStateObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::StageDisplayStateObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::StageDisplayStateObject>((avmplus::StageDisplayStateObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::StageDisplayStateObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::StageDisplayStateObject>((avmplus::StageDisplayStateObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::StageDisplayStateObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::StageDisplayStateObject>((avmplus::StageDisplayStateObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::String* get_FULL_SCREEN() const { return m_slots_StageDisplayStateClass.m_FULL_SCREEN; }
    REALLY_INLINE void setconst_FULL_SCREEN(avmplus::String* newVal) { m_slots_StageDisplayStateClass.m_FULL_SCREEN = newVal; }
public:
    REALLY_INLINE avmplus::String* get_FULL_SCREEN_INTERACTIVE() const { return m_slots_StageDisplayStateClass.m_FULL_SCREEN_INTERACTIVE; }
    REALLY_INLINE void setconst_FULL_SCREEN_INTERACTIVE(avmplus::String* newVal) { m_slots_StageDisplayStateClass.m_FULL_SCREEN_INTERACTIVE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_NORMAL() const { return m_slots_StageDisplayStateClass.m_NORMAL; }
    REALLY_INLINE void setconst_NORMAL(avmplus::String* newVal) { m_slots_StageDisplayStateClass.m_NORMAL = newVal; }
private:
    avmplus::NativeID::avmplus_StageDisplayStateClassSlots m_slots_StageDisplayStateClass;
protected:
    inline explicit StageDisplayStateClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit StageDisplayStateClass(const StageDisplayStateClass&); // unimplemented
    void operator=(const StageDisplayStateClass&); // unimplemented
};

#define avmplus_StageDisplayStateClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.display::StageOrientation
//-----------------------------------------------------------
class StageOrientationObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::StageOrientationClass;
    REALLY_INLINE explicit StageOrientationObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit StageOrientationObject(const StageOrientationObject&); // unimplemented
    void operator=(const StageOrientationObject&); // unimplemented
};

#define avmplus_StageOrientationObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.display::StageOrientation$
//-----------------------------------------------------------
class StageOrientationClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::StageOrientationObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::StageOrientationObject>((avmplus::StageOrientationObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::StageOrientationObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::StageOrientationObject>((avmplus::StageOrientationObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::StageOrientationObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::StageOrientationObject>((avmplus::StageOrientationObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::StageOrientationObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::StageOrientationObject>((avmplus::StageOrientationObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::StageOrientationObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::StageOrientationObject>((avmplus::StageOrientationObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::String* get_DEFAULT() const { return m_slots_StageOrientationClass.m_DEFAULT; }
    REALLY_INLINE void setconst_DEFAULT(avmplus::String* newVal) { m_slots_StageOrientationClass.m_DEFAULT = newVal; }
public:
    REALLY_INLINE avmplus::String* get_ROTATED_LEFT() const { return m_slots_StageOrientationClass.m_ROTATED_LEFT; }
    REALLY_INLINE void setconst_ROTATED_LEFT(avmplus::String* newVal) { m_slots_StageOrientationClass.m_ROTATED_LEFT = newVal; }
public:
    REALLY_INLINE avmplus::String* get_ROTATED_RIGHT() const { return m_slots_StageOrientationClass.m_ROTATED_RIGHT; }
    REALLY_INLINE void setconst_ROTATED_RIGHT(avmplus::String* newVal) { m_slots_StageOrientationClass.m_ROTATED_RIGHT = newVal; }
public:
    REALLY_INLINE avmplus::String* get_UNKNOWN() const { return m_slots_StageOrientationClass.m_UNKNOWN; }
    REALLY_INLINE void setconst_UNKNOWN(avmplus::String* newVal) { m_slots_StageOrientationClass.m_UNKNOWN = newVal; }
public:
    REALLY_INLINE avmplus::String* get_UPSIDE_DOWN() const { return m_slots_StageOrientationClass.m_UPSIDE_DOWN; }
    REALLY_INLINE void setconst_UPSIDE_DOWN(avmplus::String* newVal) { m_slots_StageOrientationClass.m_UPSIDE_DOWN = newVal; }
private:
    avmplus::NativeID::avmplus_StageOrientationClassSlots m_slots_StageOrientationClass;
protected:
    inline explicit StageOrientationClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit StageOrientationClass(const StageOrientationClass&); // unimplemented
    void operator=(const StageOrientationClass&); // unimplemented
};

#define avmplus_StageOrientationClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.display::StageQuality
//-----------------------------------------------------------
class StageQualityObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::StageQualityClass;
    REALLY_INLINE explicit StageQualityObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit StageQualityObject(const StageQualityObject&); // unimplemented
    void operator=(const StageQualityObject&); // unimplemented
};

#define avmplus_StageQualityObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.display::StageQuality$
//-----------------------------------------------------------
class StageQualityClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::StageQualityObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::StageQualityObject>((avmplus::StageQualityObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::StageQualityObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::StageQualityObject>((avmplus::StageQualityObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::StageQualityObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::StageQualityObject>((avmplus::StageQualityObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::StageQualityObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::StageQualityObject>((avmplus::StageQualityObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::StageQualityObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::StageQualityObject>((avmplus::StageQualityObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::String* get_LOW() const { return m_slots_StageQualityClass.m_LOW; }
    REALLY_INLINE void setconst_LOW(avmplus::String* newVal) { m_slots_StageQualityClass.m_LOW = newVal; }
public:
    REALLY_INLINE avmplus::String* get_MEDIUM() const { return m_slots_StageQualityClass.m_MEDIUM; }
    REALLY_INLINE void setconst_MEDIUM(avmplus::String* newVal) { m_slots_StageQualityClass.m_MEDIUM = newVal; }
public:
    REALLY_INLINE avmplus::String* get_HIGH() const { return m_slots_StageQualityClass.m_HIGH; }
    REALLY_INLINE void setconst_HIGH(avmplus::String* newVal) { m_slots_StageQualityClass.m_HIGH = newVal; }
public:
    REALLY_INLINE avmplus::String* get_BEST() const { return m_slots_StageQualityClass.m_BEST; }
    REALLY_INLINE void setconst_BEST(avmplus::String* newVal) { m_slots_StageQualityClass.m_BEST = newVal; }
public:
    REALLY_INLINE avmplus::String* get_HIGH_8X8() const { return m_slots_StageQualityClass.m_HIGH_8X8; }
    REALLY_INLINE void setconst_HIGH_8X8(avmplus::String* newVal) { m_slots_StageQualityClass.m_HIGH_8X8 = newVal; }
public:
    REALLY_INLINE avmplus::String* get_HIGH_8X8_LINEAR() const { return m_slots_StageQualityClass.m_HIGH_8X8_LINEAR; }
    REALLY_INLINE void setconst_HIGH_8X8_LINEAR(avmplus::String* newVal) { m_slots_StageQualityClass.m_HIGH_8X8_LINEAR = newVal; }
public:
    REALLY_INLINE avmplus::String* get_HIGH_16X16() const { return m_slots_StageQualityClass.m_HIGH_16X16; }
    REALLY_INLINE void setconst_HIGH_16X16(avmplus::String* newVal) { m_slots_StageQualityClass.m_HIGH_16X16 = newVal; }
public:
    REALLY_INLINE avmplus::String* get_HIGH_16X16_LINEAR() const { return m_slots_StageQualityClass.m_HIGH_16X16_LINEAR; }
    REALLY_INLINE void setconst_HIGH_16X16_LINEAR(avmplus::String* newVal) { m_slots_StageQualityClass.m_HIGH_16X16_LINEAR = newVal; }
private:
    avmplus::NativeID::avmplus_StageQualityClassSlots m_slots_StageQualityClass;
protected:
    inline explicit StageQualityClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit StageQualityClass(const StageQualityClass&); // unimplemented
    void operator=(const StageQualityClass&); // unimplemented
};

#define avmplus_StageQualityClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.display::StageScaleMode
//-----------------------------------------------------------
class StageScaleModeObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::StageScaleModeClass;
    REALLY_INLINE explicit StageScaleModeObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit StageScaleModeObject(const StageScaleModeObject&); // unimplemented
    void operator=(const StageScaleModeObject&); // unimplemented
};

#define avmplus_StageScaleModeObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.display::StageScaleMode$
//-----------------------------------------------------------
class StageScaleModeClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::StageScaleModeObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::StageScaleModeObject>((avmplus::StageScaleModeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::StageScaleModeObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::StageScaleModeObject>((avmplus::StageScaleModeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::StageScaleModeObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::StageScaleModeObject>((avmplus::StageScaleModeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::StageScaleModeObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::StageScaleModeObject>((avmplus::StageScaleModeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::StageScaleModeObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::StageScaleModeObject>((avmplus::StageScaleModeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::String* get_SHOW_ALL() const { return m_slots_StageScaleModeClass.m_SHOW_ALL; }
    REALLY_INLINE void setconst_SHOW_ALL(avmplus::String* newVal) { m_slots_StageScaleModeClass.m_SHOW_ALL = newVal; }
public:
    REALLY_INLINE avmplus::String* get_EXACT_FIT() const { return m_slots_StageScaleModeClass.m_EXACT_FIT; }
    REALLY_INLINE void setconst_EXACT_FIT(avmplus::String* newVal) { m_slots_StageScaleModeClass.m_EXACT_FIT = newVal; }
public:
    REALLY_INLINE avmplus::String* get_NO_BORDER() const { return m_slots_StageScaleModeClass.m_NO_BORDER; }
    REALLY_INLINE void setconst_NO_BORDER(avmplus::String* newVal) { m_slots_StageScaleModeClass.m_NO_BORDER = newVal; }
public:
    REALLY_INLINE avmplus::String* get_NO_SCALE() const { return m_slots_StageScaleModeClass.m_NO_SCALE; }
    REALLY_INLINE void setconst_NO_SCALE(avmplus::String* newVal) { m_slots_StageScaleModeClass.m_NO_SCALE = newVal; }
private:
    avmplus::NativeID::avmplus_StageScaleModeClassSlots m_slots_StageScaleModeClass;
protected:
    inline explicit StageScaleModeClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit StageScaleModeClass(const StageScaleModeClass&); // unimplemented
    void operator=(const StageScaleModeClass&); // unimplemented
};

#define avmplus_StageScaleModeClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.display::SWFVersion
//-----------------------------------------------------------
class SWFVersionObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::SWFVersionClass;
    REALLY_INLINE explicit SWFVersionObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit SWFVersionObject(const SWFVersionObject&); // unimplemented
    void operator=(const SWFVersionObject&); // unimplemented
};

#define avmplus_SWFVersionObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.display::SWFVersion$
//-----------------------------------------------------------
class SWFVersionClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::SWFVersionObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::SWFVersionObject>((avmplus::SWFVersionObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::SWFVersionObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::SWFVersionObject>((avmplus::SWFVersionObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SWFVersionObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::SWFVersionObject>((avmplus::SWFVersionObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SWFVersionObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::SWFVersionObject>((avmplus::SWFVersionObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SWFVersionObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::SWFVersionObject>((avmplus::SWFVersionObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE uint32_t get_FLASH1() const { return m_slots_SWFVersionClass.m_FLASH1; }
    REALLY_INLINE void setconst_FLASH1(uint32_t newVal) { m_slots_SWFVersionClass.m_FLASH1 = newVal; }
public:
    REALLY_INLINE uint32_t get_FLASH2() const { return m_slots_SWFVersionClass.m_FLASH2; }
    REALLY_INLINE void setconst_FLASH2(uint32_t newVal) { m_slots_SWFVersionClass.m_FLASH2 = newVal; }
public:
    REALLY_INLINE uint32_t get_FLASH3() const { return m_slots_SWFVersionClass.m_FLASH3; }
    REALLY_INLINE void setconst_FLASH3(uint32_t newVal) { m_slots_SWFVersionClass.m_FLASH3 = newVal; }
public:
    REALLY_INLINE uint32_t get_FLASH4() const { return m_slots_SWFVersionClass.m_FLASH4; }
    REALLY_INLINE void setconst_FLASH4(uint32_t newVal) { m_slots_SWFVersionClass.m_FLASH4 = newVal; }
public:
    REALLY_INLINE uint32_t get_FLASH5() const { return m_slots_SWFVersionClass.m_FLASH5; }
    REALLY_INLINE void setconst_FLASH5(uint32_t newVal) { m_slots_SWFVersionClass.m_FLASH5 = newVal; }
public:
    REALLY_INLINE uint32_t get_FLASH6() const { return m_slots_SWFVersionClass.m_FLASH6; }
    REALLY_INLINE void setconst_FLASH6(uint32_t newVal) { m_slots_SWFVersionClass.m_FLASH6 = newVal; }
public:
    REALLY_INLINE uint32_t get_FLASH7() const { return m_slots_SWFVersionClass.m_FLASH7; }
    REALLY_INLINE void setconst_FLASH7(uint32_t newVal) { m_slots_SWFVersionClass.m_FLASH7 = newVal; }
public:
    REALLY_INLINE uint32_t get_FLASH8() const { return m_slots_SWFVersionClass.m_FLASH8; }
    REALLY_INLINE void setconst_FLASH8(uint32_t newVal) { m_slots_SWFVersionClass.m_FLASH8 = newVal; }
public:
    REALLY_INLINE uint32_t get_FLASH9() const { return m_slots_SWFVersionClass.m_FLASH9; }
    REALLY_INLINE void setconst_FLASH9(uint32_t newVal) { m_slots_SWFVersionClass.m_FLASH9 = newVal; }
public:
    REALLY_INLINE uint32_t get_FLASH10() const { return m_slots_SWFVersionClass.m_FLASH10; }
    REALLY_INLINE void setconst_FLASH10(uint32_t newVal) { m_slots_SWFVersionClass.m_FLASH10 = newVal; }
public:
    REALLY_INLINE uint32_t get_FLASH11() const { return m_slots_SWFVersionClass.m_FLASH11; }
    REALLY_INLINE void setconst_FLASH11(uint32_t newVal) { m_slots_SWFVersionClass.m_FLASH11 = newVal; }
public:
    REALLY_INLINE uint32_t get_FLASH12() const { return m_slots_SWFVersionClass.m_FLASH12; }
    REALLY_INLINE void setconst_FLASH12(uint32_t newVal) { m_slots_SWFVersionClass.m_FLASH12 = newVal; }
public:
    REALLY_INLINE uint32_t get_FLASH13() const { return m_slots_SWFVersionClass.m_FLASH13; }
    REALLY_INLINE void setconst_FLASH13(uint32_t newVal) { m_slots_SWFVersionClass.m_FLASH13 = newVal; }
public:
    REALLY_INLINE uint32_t get_FLASH14() const { return m_slots_SWFVersionClass.m_FLASH14; }
    REALLY_INLINE void setconst_FLASH14(uint32_t newVal) { m_slots_SWFVersionClass.m_FLASH14 = newVal; }
public:
    REALLY_INLINE uint32_t get_FLASH15() const { return m_slots_SWFVersionClass.m_FLASH15; }
    REALLY_INLINE void setconst_FLASH15(uint32_t newVal) { m_slots_SWFVersionClass.m_FLASH15 = newVal; }
public:
    REALLY_INLINE uint32_t get_FLASH16() const { return m_slots_SWFVersionClass.m_FLASH16; }
    REALLY_INLINE void setconst_FLASH16(uint32_t newVal) { m_slots_SWFVersionClass.m_FLASH16 = newVal; }
public:
    REALLY_INLINE uint32_t get_FLASH17() const { return m_slots_SWFVersionClass.m_FLASH17; }
    REALLY_INLINE void setconst_FLASH17(uint32_t newVal) { m_slots_SWFVersionClass.m_FLASH17 = newVal; }
public:
    REALLY_INLINE uint32_t get_FLASH18() const { return m_slots_SWFVersionClass.m_FLASH18; }
    REALLY_INLINE void setconst_FLASH18(uint32_t newVal) { m_slots_SWFVersionClass.m_FLASH18 = newVal; }
public:
    REALLY_INLINE uint32_t get_FLASH19() const { return m_slots_SWFVersionClass.m_FLASH19; }
    REALLY_INLINE void setconst_FLASH19(uint32_t newVal) { m_slots_SWFVersionClass.m_FLASH19 = newVal; }
private:
    avmplus::NativeID::avmplus_SWFVersionClassSlots m_slots_SWFVersionClass;
protected:
    inline explicit SWFVersionClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit SWFVersionClass(const SWFVersionClass&); // unimplemented
    void operator=(const SWFVersionClass&); // unimplemented
};

#define avmplus_SWFVersionClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.display::TriangleCulling
//-----------------------------------------------------------
class TriangleCullingObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::TriangleCullingClass;
    REALLY_INLINE explicit TriangleCullingObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit TriangleCullingObject(const TriangleCullingObject&); // unimplemented
    void operator=(const TriangleCullingObject&); // unimplemented
};

#define avmplus_TriangleCullingObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.display::TriangleCulling$
//-----------------------------------------------------------
class TriangleCullingClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::TriangleCullingObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::TriangleCullingObject>((avmplus::TriangleCullingObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::TriangleCullingObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::TriangleCullingObject>((avmplus::TriangleCullingObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::TriangleCullingObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::TriangleCullingObject>((avmplus::TriangleCullingObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::TriangleCullingObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::TriangleCullingObject>((avmplus::TriangleCullingObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::TriangleCullingObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::TriangleCullingObject>((avmplus::TriangleCullingObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::String* get_NONE() const { return m_slots_TriangleCullingClass.m_NONE; }
    REALLY_INLINE void setconst_NONE(avmplus::String* newVal) { m_slots_TriangleCullingClass.m_NONE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_POSITIVE() const { return m_slots_TriangleCullingClass.m_POSITIVE; }
    REALLY_INLINE void setconst_POSITIVE(avmplus::String* newVal) { m_slots_TriangleCullingClass.m_POSITIVE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_NEGATIVE() const { return m_slots_TriangleCullingClass.m_NEGATIVE; }
    REALLY_INLINE void setconst_NEGATIVE(avmplus::String* newVal) { m_slots_TriangleCullingClass.m_NEGATIVE = newVal; }
private:
    avmplus::NativeID::avmplus_TriangleCullingClassSlots m_slots_TriangleCullingClass;
protected:
    inline explicit TriangleCullingClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit TriangleCullingClass(const TriangleCullingClass&); // unimplemented
    void operator=(const TriangleCullingClass&); // unimplemented
};

#define avmplus_TriangleCullingClass_isExactInterlock 1
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
// flash.events::IEventDispatcher
//-----------------------------------------------------------
class IEventDispatcherInterface : public avmplus::ScriptObject
{
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::IEventDispatcherClass;
    REALLY_INLINE explicit IEventDispatcherInterface(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit IEventDispatcherInterface(const IEventDispatcherInterface&); // unimplemented
    void operator=(const IEventDispatcherInterface&); // unimplemented
};

//-----------------------------------------------------------
// flash.events::IEventDispatcher$
//-----------------------------------------------------------
class IEventDispatcherClass : public avmplus::ClassClosure
{
public:
    REALLY_INLINE bool isType(avmplus::Atom value)
    {
        return isTypeImpl(value);
    }
    REALLY_INLINE bool isType(GCRef<avmplus::ScriptObject> value)
    {
        return isTypeImpl(value->atom());
    }
    REALLY_INLINE GCRef<avmplus::IEventDispatcherInterface> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::IEventDispatcherInterface>((avmplus::IEventDispatcherInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IEventDispatcherInterface> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::IEventDispatcherInterface>((avmplus::IEventDispatcherInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IEventDispatcherInterface> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::IEventDispatcherInterface>((avmplus::IEventDispatcherInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IEventDispatcherInterface> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::IEventDispatcherInterface>((avmplus::IEventDispatcherInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit IEventDispatcherClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit IEventDispatcherClass(const IEventDispatcherClass&); // unimplemented
    void operator=(const IEventDispatcherClass&); // unimplemented
};

//-----------------------------------------------------------
// flash.events::Event
//-----------------------------------------------------------
class EventObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    REALLY_INLINE bool get__bubbles() const { return m_slots_EventObject.m_private__bubbles != 0; }
    REALLY_INLINE void set__bubbles(avmplus::bool32 newVal) { m_slots_EventObject.m_private__bubbles = newVal; }
protected:
    REALLY_INLINE bool get__cancelable() const { return m_slots_EventObject.m_private__cancelable != 0; }
    REALLY_INLINE void set__cancelable(avmplus::bool32 newVal) { m_slots_EventObject.m_private__cancelable = newVal; }
protected:
    REALLY_INLINE uint32_t get__currentphase() const { return m_slots_EventObject.m_private__currentphase; }
    REALLY_INLINE void set__currentphase(uint32_t newVal) { m_slots_EventObject.m_private__currentphase = newVal; }
protected:
    REALLY_INLINE avmplus::String* get__type() const { return m_slots_EventObject.m_private__type; }
    REALLY_INLINE void set__type(avmplus::String* newVal) { m_slots_EventObject.m_private__type = newVal; }
protected:
    REALLY_INLINE avmplus::Atom get__target() const { return m_slots_EventObject.m_private__target; }
    REALLY_INLINE void set__target(avmplus::Atom newVal) { m_slots_EventObject.m_private__target = newVal; }
protected:
    REALLY_INLINE avmplus::Atom get__currenttarget() const { return m_slots_EventObject.m_private__currenttarget; }
    REALLY_INLINE void set__currenttarget(avmplus::Atom newVal) { m_slots_EventObject.m_private__currenttarget = newVal; }
protected:
    REALLY_INLINE avmplus::Atom get__preventdefault() const { return m_slots_EventObject.m_private__preventdefault; }
    REALLY_INLINE void set__preventdefault(avmplus::Atom newVal) { m_slots_EventObject.m_private__preventdefault = newVal; }
private:
    avmplus::NativeID::avmplus_EventObjectSlots m_slots_EventObject;
protected:
    friend class avmplus::EventClass;
    REALLY_INLINE explicit EventObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit EventObject(const EventObject&); // unimplemented
    void operator=(const EventObject&); // unimplemented
};

#define avmplus_EventObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.events::Event$
//-----------------------------------------------------------
class EventClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::EventObject> constructObject(GCRef<avmplus::String> arg1, bool arg2, bool arg3)
    {
        avmplus::Atom args[4] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom(), ((arg2) ? trueAtom : falseAtom), ((arg3) ? trueAtom : falseAtom) };
        avmplus::Atom const result = this->construct(3, args);
        return GCRef<avmplus::EventObject>((avmplus::EventObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::EventObject> constructObject(GCRef<avmplus::String> arg1, bool arg2)
    {
        avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom(), ((arg2) ? trueAtom : falseAtom) };
        avmplus::Atom const result = this->construct(2, args);
        return GCRef<avmplus::EventObject>((avmplus::EventObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::EventObject> constructObject(GCRef<avmplus::String> arg1)
    {
        avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom() };
        avmplus::Atom const result = this->construct(1, args);
        return GCRef<avmplus::EventObject>((avmplus::EventObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::EventObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::EventObject>((avmplus::EventObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::EventObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::EventObject>((avmplus::EventObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::EventObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::EventObject>((avmplus::EventObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::EventObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::EventObject>((avmplus::EventObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::String* get_ACTIVATE() const { return m_slots_EventClass.m_ACTIVATE; }
    REALLY_INLINE void setconst_ACTIVATE(avmplus::String* newVal) { m_slots_EventClass.m_ACTIVATE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_ADDED() const { return m_slots_EventClass.m_ADDED; }
    REALLY_INLINE void setconst_ADDED(avmplus::String* newVal) { m_slots_EventClass.m_ADDED = newVal; }
public:
    REALLY_INLINE avmplus::String* get_ADDED_TO_STAGE() const { return m_slots_EventClass.m_ADDED_TO_STAGE; }
    REALLY_INLINE void setconst_ADDED_TO_STAGE(avmplus::String* newVal) { m_slots_EventClass.m_ADDED_TO_STAGE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_CANCEL() const { return m_slots_EventClass.m_CANCEL; }
    REALLY_INLINE void setconst_CANCEL(avmplus::String* newVal) { m_slots_EventClass.m_CANCEL = newVal; }
public:
    REALLY_INLINE avmplus::String* get_CHANGE() const { return m_slots_EventClass.m_CHANGE; }
    REALLY_INLINE void setconst_CHANGE(avmplus::String* newVal) { m_slots_EventClass.m_CHANGE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_CLEAR() const { return m_slots_EventClass.m_CLEAR; }
    REALLY_INLINE void setconst_CLEAR(avmplus::String* newVal) { m_slots_EventClass.m_CLEAR = newVal; }
public:
    REALLY_INLINE avmplus::String* get_CLOSE() const { return m_slots_EventClass.m_CLOSE; }
    REALLY_INLINE void setconst_CLOSE(avmplus::String* newVal) { m_slots_EventClass.m_CLOSE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_COMPLETE() const { return m_slots_EventClass.m_COMPLETE; }
    REALLY_INLINE void setconst_COMPLETE(avmplus::String* newVal) { m_slots_EventClass.m_COMPLETE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_CONNECT() const { return m_slots_EventClass.m_CONNECT; }
    REALLY_INLINE void setconst_CONNECT(avmplus::String* newVal) { m_slots_EventClass.m_CONNECT = newVal; }
public:
    REALLY_INLINE avmplus::String* get_COPY() const { return m_slots_EventClass.m_COPY; }
    REALLY_INLINE void setconst_COPY(avmplus::String* newVal) { m_slots_EventClass.m_COPY = newVal; }
public:
    REALLY_INLINE avmplus::String* get_CUT() const { return m_slots_EventClass.m_CUT; }
    REALLY_INLINE void setconst_CUT(avmplus::String* newVal) { m_slots_EventClass.m_CUT = newVal; }
public:
    REALLY_INLINE avmplus::String* get_DEACTIVATE() const { return m_slots_EventClass.m_DEACTIVATE; }
    REALLY_INLINE void setconst_DEACTIVATE(avmplus::String* newVal) { m_slots_EventClass.m_DEACTIVATE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_ENTER_FRAME() const { return m_slots_EventClass.m_ENTER_FRAME; }
    REALLY_INLINE void setconst_ENTER_FRAME(avmplus::String* newVal) { m_slots_EventClass.m_ENTER_FRAME = newVal; }
public:
    REALLY_INLINE avmplus::String* get_FRAME_CONSTRUCTED() const { return m_slots_EventClass.m_FRAME_CONSTRUCTED; }
    REALLY_INLINE void setconst_FRAME_CONSTRUCTED(avmplus::String* newVal) { m_slots_EventClass.m_FRAME_CONSTRUCTED = newVal; }
public:
    REALLY_INLINE avmplus::String* get_EXIT_FRAME() const { return m_slots_EventClass.m_EXIT_FRAME; }
    REALLY_INLINE void setconst_EXIT_FRAME(avmplus::String* newVal) { m_slots_EventClass.m_EXIT_FRAME = newVal; }
public:
    REALLY_INLINE avmplus::String* get_FRAME_LABEL() const { return m_slots_EventClass.m_FRAME_LABEL; }
    REALLY_INLINE void setconst_FRAME_LABEL(avmplus::String* newVal) { m_slots_EventClass.m_FRAME_LABEL = newVal; }
public:
    REALLY_INLINE avmplus::String* get_ID3() const { return m_slots_EventClass.m_ID3; }
    REALLY_INLINE void setconst_ID3(avmplus::String* newVal) { m_slots_EventClass.m_ID3 = newVal; }
public:
    REALLY_INLINE avmplus::String* get_INIT() const { return m_slots_EventClass.m_INIT; }
    REALLY_INLINE void setconst_INIT(avmplus::String* newVal) { m_slots_EventClass.m_INIT = newVal; }
public:
    REALLY_INLINE avmplus::String* get_MOUSE_LEAVE() const { return m_slots_EventClass.m_MOUSE_LEAVE; }
    REALLY_INLINE void setconst_MOUSE_LEAVE(avmplus::String* newVal) { m_slots_EventClass.m_MOUSE_LEAVE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_OPEN() const { return m_slots_EventClass.m_OPEN; }
    REALLY_INLINE void setconst_OPEN(avmplus::String* newVal) { m_slots_EventClass.m_OPEN = newVal; }
public:
    REALLY_INLINE avmplus::String* get_PASTE() const { return m_slots_EventClass.m_PASTE; }
    REALLY_INLINE void setconst_PASTE(avmplus::String* newVal) { m_slots_EventClass.m_PASTE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_REMOVED() const { return m_slots_EventClass.m_REMOVED; }
    REALLY_INLINE void setconst_REMOVED(avmplus::String* newVal) { m_slots_EventClass.m_REMOVED = newVal; }
public:
    REALLY_INLINE avmplus::String* get_REMOVED_FROM_STAGE() const { return m_slots_EventClass.m_REMOVED_FROM_STAGE; }
    REALLY_INLINE void setconst_REMOVED_FROM_STAGE(avmplus::String* newVal) { m_slots_EventClass.m_REMOVED_FROM_STAGE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_RENDER() const { return m_slots_EventClass.m_RENDER; }
    REALLY_INLINE void setconst_RENDER(avmplus::String* newVal) { m_slots_EventClass.m_RENDER = newVal; }
public:
    REALLY_INLINE avmplus::String* get_RESIZE() const { return m_slots_EventClass.m_RESIZE; }
    REALLY_INLINE void setconst_RESIZE(avmplus::String* newVal) { m_slots_EventClass.m_RESIZE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_SCROLL() const { return m_slots_EventClass.m_SCROLL; }
    REALLY_INLINE void setconst_SCROLL(avmplus::String* newVal) { m_slots_EventClass.m_SCROLL = newVal; }
public:
    REALLY_INLINE avmplus::String* get_TEXT_INTERACTION_MODE_CHANGE() const { return m_slots_EventClass.m_TEXT_INTERACTION_MODE_CHANGE; }
    REALLY_INLINE void setconst_TEXT_INTERACTION_MODE_CHANGE(avmplus::String* newVal) { m_slots_EventClass.m_TEXT_INTERACTION_MODE_CHANGE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_SELECT() const { return m_slots_EventClass.m_SELECT; }
    REALLY_INLINE void setconst_SELECT(avmplus::String* newVal) { m_slots_EventClass.m_SELECT = newVal; }
public:
    REALLY_INLINE avmplus::String* get_SELECT_ALL() const { return m_slots_EventClass.m_SELECT_ALL; }
    REALLY_INLINE void setconst_SELECT_ALL(avmplus::String* newVal) { m_slots_EventClass.m_SELECT_ALL = newVal; }
public:
    REALLY_INLINE avmplus::String* get_SOUND_COMPLETE() const { return m_slots_EventClass.m_SOUND_COMPLETE; }
    REALLY_INLINE void setconst_SOUND_COMPLETE(avmplus::String* newVal) { m_slots_EventClass.m_SOUND_COMPLETE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_TAB_CHILDREN_CHANGE() const { return m_slots_EventClass.m_TAB_CHILDREN_CHANGE; }
    REALLY_INLINE void setconst_TAB_CHILDREN_CHANGE(avmplus::String* newVal) { m_slots_EventClass.m_TAB_CHILDREN_CHANGE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_TAB_ENABLED_CHANGE() const { return m_slots_EventClass.m_TAB_ENABLED_CHANGE; }
    REALLY_INLINE void setconst_TAB_ENABLED_CHANGE(avmplus::String* newVal) { m_slots_EventClass.m_TAB_ENABLED_CHANGE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_TAB_INDEX_CHANGE() const { return m_slots_EventClass.m_TAB_INDEX_CHANGE; }
    REALLY_INLINE void setconst_TAB_INDEX_CHANGE(avmplus::String* newVal) { m_slots_EventClass.m_TAB_INDEX_CHANGE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_UNLOAD() const { return m_slots_EventClass.m_UNLOAD; }
    REALLY_INLINE void setconst_UNLOAD(avmplus::String* newVal) { m_slots_EventClass.m_UNLOAD = newVal; }
public:
    REALLY_INLINE avmplus::String* get_FULLSCREEN() const { return m_slots_EventClass.m_FULLSCREEN; }
    REALLY_INLINE void setconst_FULLSCREEN(avmplus::String* newVal) { m_slots_EventClass.m_FULLSCREEN = newVal; }
public:
    REALLY_INLINE avmplus::String* get_CONTEXT3D_CREATE() const { return m_slots_EventClass.m_CONTEXT3D_CREATE; }
    REALLY_INLINE void setconst_CONTEXT3D_CREATE(avmplus::String* newVal) { m_slots_EventClass.m_CONTEXT3D_CREATE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_TEXTURE_READY() const { return m_slots_EventClass.m_TEXTURE_READY; }
    REALLY_INLINE void setconst_TEXTURE_READY(avmplus::String* newVal) { m_slots_EventClass.m_TEXTURE_READY = newVal; }
public:
    REALLY_INLINE avmplus::String* get_VIDEO_FRAME() const { return m_slots_EventClass.m_VIDEO_FRAME; }
    REALLY_INLINE void setconst_VIDEO_FRAME(avmplus::String* newVal) { m_slots_EventClass.m_VIDEO_FRAME = newVal; }
public:
    REALLY_INLINE avmplus::String* get_SUSPEND() const { return m_slots_EventClass.m_SUSPEND; }
    REALLY_INLINE void setconst_SUSPEND(avmplus::String* newVal) { m_slots_EventClass.m_SUSPEND = newVal; }
public:
    REALLY_INLINE avmplus::String* get_CHANNEL_MESSAGE() const { return m_slots_EventClass.m_CHANNEL_MESSAGE; }
    REALLY_INLINE void setconst_CHANNEL_MESSAGE(avmplus::String* newVal) { m_slots_EventClass.m_CHANNEL_MESSAGE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_CHANNEL_STATE() const { return m_slots_EventClass.m_CHANNEL_STATE; }
    REALLY_INLINE void setconst_CHANNEL_STATE(avmplus::String* newVal) { m_slots_EventClass.m_CHANNEL_STATE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_WORKER_STATE() const { return m_slots_EventClass.m_WORKER_STATE; }
    REALLY_INLINE void setconst_WORKER_STATE(avmplus::String* newVal) { m_slots_EventClass.m_WORKER_STATE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_CLOSING() const { return m_slots_EventClass.m_CLOSING; }
    REALLY_INLINE void setconst_CLOSING(avmplus::String* newVal) { m_slots_EventClass.m_CLOSING = newVal; }
public:
    REALLY_INLINE avmplus::String* get_EXITING() const { return m_slots_EventClass.m_EXITING; }
    REALLY_INLINE void setconst_EXITING(avmplus::String* newVal) { m_slots_EventClass.m_EXITING = newVal; }
public:
    REALLY_INLINE avmplus::String* get_DISPLAYING() const { return m_slots_EventClass.m_DISPLAYING; }
    REALLY_INLINE void setconst_DISPLAYING(avmplus::String* newVal) { m_slots_EventClass.m_DISPLAYING = newVal; }
public:
    REALLY_INLINE avmplus::String* get_PREPARING() const { return m_slots_EventClass.m_PREPARING; }
    REALLY_INLINE void setconst_PREPARING(avmplus::String* newVal) { m_slots_EventClass.m_PREPARING = newVal; }
public:
    REALLY_INLINE avmplus::String* get_NETWORK_CHANGE() const { return m_slots_EventClass.m_NETWORK_CHANGE; }
    REALLY_INLINE void setconst_NETWORK_CHANGE(avmplus::String* newVal) { m_slots_EventClass.m_NETWORK_CHANGE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_USER_IDLE() const { return m_slots_EventClass.m_USER_IDLE; }
    REALLY_INLINE void setconst_USER_IDLE(avmplus::String* newVal) { m_slots_EventClass.m_USER_IDLE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_USER_PRESENT() const { return m_slots_EventClass.m_USER_PRESENT; }
    REALLY_INLINE void setconst_USER_PRESENT(avmplus::String* newVal) { m_slots_EventClass.m_USER_PRESENT = newVal; }
public:
    REALLY_INLINE avmplus::String* get_STANDARD_OUTPUT_CLOSE() const { return m_slots_EventClass.m_STANDARD_OUTPUT_CLOSE; }
    REALLY_INLINE void setconst_STANDARD_OUTPUT_CLOSE(avmplus::String* newVal) { m_slots_EventClass.m_STANDARD_OUTPUT_CLOSE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_STANDARD_ERROR_CLOSE() const { return m_slots_EventClass.m_STANDARD_ERROR_CLOSE; }
    REALLY_INLINE void setconst_STANDARD_ERROR_CLOSE(avmplus::String* newVal) { m_slots_EventClass.m_STANDARD_ERROR_CLOSE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_STANDARD_INPUT_CLOSE() const { return m_slots_EventClass.m_STANDARD_INPUT_CLOSE; }
    REALLY_INLINE void setconst_STANDARD_INPUT_CLOSE(avmplus::String* newVal) { m_slots_EventClass.m_STANDARD_INPUT_CLOSE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_HTML_BOUNDS_CHANGE() const { return m_slots_EventClass.m_HTML_BOUNDS_CHANGE; }
    REALLY_INLINE void setconst_HTML_BOUNDS_CHANGE(avmplus::String* newVal) { m_slots_EventClass.m_HTML_BOUNDS_CHANGE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_HTML_RENDER() const { return m_slots_EventClass.m_HTML_RENDER; }
    REALLY_INLINE void setconst_HTML_RENDER(avmplus::String* newVal) { m_slots_EventClass.m_HTML_RENDER = newVal; }
public:
    REALLY_INLINE avmplus::String* get_HTML_DOM_INITIALIZE() const { return m_slots_EventClass.m_HTML_DOM_INITIALIZE; }
    REALLY_INLINE void setconst_HTML_DOM_INITIALIZE(avmplus::String* newVal) { m_slots_EventClass.m_HTML_DOM_INITIALIZE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_LOCATION_CHANGE() const { return m_slots_EventClass.m_LOCATION_CHANGE; }
    REALLY_INLINE void setconst_LOCATION_CHANGE(avmplus::String* newVal) { m_slots_EventClass.m_LOCATION_CHANGE = newVal; }
private:
    avmplus::NativeID::avmplus_EventClassSlots m_slots_EventClass;
protected:
    inline explicit EventClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit EventClass(const EventClass&); // unimplemented
    void operator=(const EventClass&); // unimplemented
};

#define avmplus_EventClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.filesystem::FileMode
//-----------------------------------------------------------
class FileModeObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::FileModeClass;
    REALLY_INLINE explicit FileModeObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit FileModeObject(const FileModeObject&); // unimplemented
    void operator=(const FileModeObject&); // unimplemented
};

#define avmplus_FileModeObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.filesystem::FileMode$
//-----------------------------------------------------------
class FileModeClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::FileModeObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::FileModeObject>((avmplus::FileModeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::FileModeObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::FileModeObject>((avmplus::FileModeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::FileModeObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::FileModeObject>((avmplus::FileModeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::FileModeObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::FileModeObject>((avmplus::FileModeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::FileModeObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::FileModeObject>((avmplus::FileModeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::String* get_READ() const { return m_slots_FileModeClass.m_READ; }
    REALLY_INLINE void setconst_READ(avmplus::String* newVal) { m_slots_FileModeClass.m_READ = newVal; }
public:
    REALLY_INLINE avmplus::String* get_WRITE() const { return m_slots_FileModeClass.m_WRITE; }
    REALLY_INLINE void setconst_WRITE(avmplus::String* newVal) { m_slots_FileModeClass.m_WRITE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_UPDATE() const { return m_slots_FileModeClass.m_UPDATE; }
    REALLY_INLINE void setconst_UPDATE(avmplus::String* newVal) { m_slots_FileModeClass.m_UPDATE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_APPEND() const { return m_slots_FileModeClass.m_APPEND; }
    REALLY_INLINE void setconst_APPEND(avmplus::String* newVal) { m_slots_FileModeClass.m_APPEND = newVal; }
private:
    avmplus::NativeID::avmplus_FileModeClassSlots m_slots_FileModeClass;
protected:
    inline explicit FileModeClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit FileModeClass(const FileModeClass&); // unimplemented
    void operator=(const FileModeClass&); // unimplemented
};

#define avmplus_FileModeClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.filesystem::FileStream
//-----------------------------------------------------------
class FileStreamObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::FileStreamClass;
    REALLY_INLINE explicit FileStreamObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit FileStreamObject(const FileStreamObject&); // unimplemented
    void operator=(const FileStreamObject&); // unimplemented
};

#define avmplus_FileStreamObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.filesystem::FileStream$
//-----------------------------------------------------------
class FileStreamClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::FileStreamObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::FileStreamObject>((avmplus::FileStreamObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::FileStreamObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::FileStreamObject>((avmplus::FileStreamObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::FileStreamObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::FileStreamObject>((avmplus::FileStreamObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::FileStreamObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::FileStreamObject>((avmplus::FileStreamObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::FileStreamObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::FileStreamObject>((avmplus::FileStreamObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit FileStreamClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit FileStreamClass(const FileStreamClass&); // unimplemented
    void operator=(const FileStreamClass&); // unimplemented
};

#define avmplus_FileStreamClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.geom::Orientation3D
//-----------------------------------------------------------
class Orientation3DObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::Orientation3DClass;
    REALLY_INLINE explicit Orientation3DObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit Orientation3DObject(const Orientation3DObject&); // unimplemented
    void operator=(const Orientation3DObject&); // unimplemented
};

#define avmplus_Orientation3DObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.geom::Orientation3D$
//-----------------------------------------------------------
class Orientation3DClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::Orientation3DObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::Orientation3DObject>((avmplus::Orientation3DObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::Orientation3DObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::Orientation3DObject>((avmplus::Orientation3DObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::Orientation3DObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::Orientation3DObject>((avmplus::Orientation3DObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::Orientation3DObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::Orientation3DObject>((avmplus::Orientation3DObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::Orientation3DObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::Orientation3DObject>((avmplus::Orientation3DObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::String* get_EULER_ANGLES() const { return m_slots_Orientation3DClass.m_EULER_ANGLES; }
    REALLY_INLINE void setconst_EULER_ANGLES(avmplus::String* newVal) { m_slots_Orientation3DClass.m_EULER_ANGLES = newVal; }
public:
    REALLY_INLINE avmplus::String* get_AXIS_ANGLE() const { return m_slots_Orientation3DClass.m_AXIS_ANGLE; }
    REALLY_INLINE void setconst_AXIS_ANGLE(avmplus::String* newVal) { m_slots_Orientation3DClass.m_AXIS_ANGLE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_QUATERNION() const { return m_slots_Orientation3DClass.m_QUATERNION; }
    REALLY_INLINE void setconst_QUATERNION(avmplus::String* newVal) { m_slots_Orientation3DClass.m_QUATERNION = newVal; }
private:
    avmplus::NativeID::avmplus_Orientation3DClassSlots m_slots_Orientation3DClass;
protected:
    inline explicit Orientation3DClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit Orientation3DClass(const Orientation3DClass&); // unimplemented
    void operator=(const Orientation3DClass&); // unimplemented
};

#define avmplus_Orientation3DClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.geom::Point
//-----------------------------------------------------------
class PointObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE double get_x() const { return m_slots_PointObject.m_x; }
    REALLY_INLINE void set_x(double newVal) { m_slots_PointObject.m_x = newVal; }
public:
    REALLY_INLINE double get_y() const { return m_slots_PointObject.m_y; }
    REALLY_INLINE void set_y(double newVal) { m_slots_PointObject.m_y = newVal; }
private:
    avmplus::NativeID::avmplus_PointObjectSlots m_slots_PointObject;
protected:
    friend class avmplus::PointClass;
    REALLY_INLINE explicit PointObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit PointObject(const PointObject&); // unimplemented
    void operator=(const PointObject&); // unimplemented
};

#define avmplus_PointObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.geom::Point$
//-----------------------------------------------------------
class PointClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::PointObject> constructObject(double arg1, double arg2)
    {
        avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core()));
        avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->doubleToAtom(arg1), core->doubleToAtom(arg2) };
        avmplus::Atom const result = this->construct(2, args);
        return GCRef<avmplus::PointObject>((avmplus::PointObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::PointObject> constructObject(double arg1)
    {
        avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core()));
        avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->doubleToAtom(arg1) };
        avmplus::Atom const result = this->construct(1, args);
        return GCRef<avmplus::PointObject>((avmplus::PointObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::PointObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::PointObject>((avmplus::PointObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::PointObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::PointObject>((avmplus::PointObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::PointObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::PointObject>((avmplus::PointObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::PointObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::PointObject>((avmplus::PointObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::PointObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::PointObject>((avmplus::PointObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit PointClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit PointClass(const PointClass&); // unimplemented
    void operator=(const PointClass&); // unimplemented
};

#define avmplus_PointClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.geom::Rectangle
//-----------------------------------------------------------
class RectangleObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE double get_x() const { return m_slots_RectangleObject.m_x; }
    REALLY_INLINE void set_x(double newVal) { m_slots_RectangleObject.m_x = newVal; }
public:
    REALLY_INLINE double get_y() const { return m_slots_RectangleObject.m_y; }
    REALLY_INLINE void set_y(double newVal) { m_slots_RectangleObject.m_y = newVal; }
public:
    REALLY_INLINE double get_width() const { return m_slots_RectangleObject.m_width; }
    REALLY_INLINE void set_width(double newVal) { m_slots_RectangleObject.m_width = newVal; }
public:
    REALLY_INLINE double get_height() const { return m_slots_RectangleObject.m_height; }
    REALLY_INLINE void set_height(double newVal) { m_slots_RectangleObject.m_height = newVal; }
private:
    avmplus::NativeID::avmplus_RectangleObjectSlots m_slots_RectangleObject;
protected:
    friend class avmplus::RectangleClass;
    REALLY_INLINE explicit RectangleObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit RectangleObject(const RectangleObject&); // unimplemented
    void operator=(const RectangleObject&); // unimplemented
};

#define avmplus_RectangleObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.geom::Rectangle$
//-----------------------------------------------------------
class RectangleClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::RectangleObject> constructObject(double arg1, double arg2, double arg3, double arg4)
    {
        avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core()));
        avmplus::Atom args[5] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->doubleToAtom(arg1), core->doubleToAtom(arg2), core->doubleToAtom(arg3), core->doubleToAtom(arg4) };
        avmplus::Atom const result = this->construct(4, args);
        return GCRef<avmplus::RectangleObject>((avmplus::RectangleObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::RectangleObject> constructObject(double arg1, double arg2, double arg3)
    {
        avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core()));
        avmplus::Atom args[4] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->doubleToAtom(arg1), core->doubleToAtom(arg2), core->doubleToAtom(arg3) };
        avmplus::Atom const result = this->construct(3, args);
        return GCRef<avmplus::RectangleObject>((avmplus::RectangleObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::RectangleObject> constructObject(double arg1, double arg2)
    {
        avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core()));
        avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->doubleToAtom(arg1), core->doubleToAtom(arg2) };
        avmplus::Atom const result = this->construct(2, args);
        return GCRef<avmplus::RectangleObject>((avmplus::RectangleObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::RectangleObject> constructObject(double arg1)
    {
        avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core()));
        avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->doubleToAtom(arg1) };
        avmplus::Atom const result = this->construct(1, args);
        return GCRef<avmplus::RectangleObject>((avmplus::RectangleObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::RectangleObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::RectangleObject>((avmplus::RectangleObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::RectangleObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::RectangleObject>((avmplus::RectangleObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::RectangleObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::RectangleObject>((avmplus::RectangleObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::RectangleObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::RectangleObject>((avmplus::RectangleObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::RectangleObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::RectangleObject>((avmplus::RectangleObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit RectangleClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit RectangleClass(const RectangleClass&); // unimplemented
    void operator=(const RectangleClass&); // unimplemented
};

#define avmplus_RectangleClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.net::URLRequest
//-----------------------------------------------------------
class URLRequestObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    REALLY_INLINE avmplus::ArrayObject* get__requestHeaders() const { return m_slots_URLRequestObject.m_private__requestHeaders; }
    REALLY_INLINE void set__requestHeaders(avmplus::ArrayObject* newVal) { m_slots_URLRequestObject.m_private__requestHeaders = newVal; }
protected:
    REALLY_INLINE avmplus::String* get__userAgent() const { return m_slots_URLRequestObject.m_private__userAgent; }
    REALLY_INLINE void set__userAgent(avmplus::String* newVal) { m_slots_URLRequestObject.m_private__userAgent = newVal; }
private:
    avmplus::NativeID::avmplus_URLRequestObjectSlots m_slots_URLRequestObject;
protected:
    friend class avmplus::URLRequestClass;
    REALLY_INLINE explicit URLRequestObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit URLRequestObject(const URLRequestObject&); // unimplemented
    void operator=(const URLRequestObject&); // unimplemented
};

#define avmplus_URLRequestObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.net::URLRequest$
//-----------------------------------------------------------
class URLRequestClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::URLRequestObject> constructObject(GCRef<avmplus::String> arg1)
    {
        avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom() };
        avmplus::Atom const result = this->construct(1, args);
        return GCRef<avmplus::URLRequestObject>((avmplus::URLRequestObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::URLRequestObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::URLRequestObject>((avmplus::URLRequestObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::URLRequestObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::URLRequestObject>((avmplus::URLRequestObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::URLRequestObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::URLRequestObject>((avmplus::URLRequestObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::URLRequestObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::URLRequestObject>((avmplus::URLRequestObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::URLRequestObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::URLRequestObject>((avmplus::URLRequestObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    REALLY_INLINE uint32_t get_kInvalidParamError() const { return m_slots_URLRequestClass.m_private_kInvalidParamError; }
    REALLY_INLINE void setconst_kInvalidParamError(uint32_t newVal) { m_slots_URLRequestClass.m_private_kInvalidParamError = newVal; }
private:
    avmplus::NativeID::avmplus_URLRequestClassSlots m_slots_URLRequestClass;
protected:
    inline explicit URLRequestClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit URLRequestClass(const URLRequestClass&); // unimplemented
    void operator=(const URLRequestClass&); // unimplemented
};

#define avmplus_URLRequestClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.net::URLRequestDefaults
//-----------------------------------------------------------
class URLRequestDefaultsObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::URLRequestDefaultsClass;
    REALLY_INLINE explicit URLRequestDefaultsObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit URLRequestDefaultsObject(const URLRequestDefaultsObject&); // unimplemented
    void operator=(const URLRequestDefaultsObject&); // unimplemented
};

#define avmplus_URLRequestDefaultsObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.net::URLRequestDefaults$
//-----------------------------------------------------------
class URLRequestDefaultsClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::URLRequestDefaultsObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::URLRequestDefaultsObject>((avmplus::URLRequestDefaultsObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::URLRequestDefaultsObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::URLRequestDefaultsObject>((avmplus::URLRequestDefaultsObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::URLRequestDefaultsObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::URLRequestDefaultsObject>((avmplus::URLRequestDefaultsObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::URLRequestDefaultsObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::URLRequestDefaultsObject>((avmplus::URLRequestDefaultsObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::URLRequestDefaultsObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::URLRequestDefaultsObject>((avmplus::URLRequestDefaultsObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    REALLY_INLINE uint32_t get_kApplicationFeatureSecurityError() const { return m_slots_URLRequestDefaultsClass.m_private_kApplicationFeatureSecurityError; }
    REALLY_INLINE void setconst_kApplicationFeatureSecurityError(uint32_t newVal) { m_slots_URLRequestDefaultsClass.m_private_kApplicationFeatureSecurityError = newVal; }
protected:
    REALLY_INLINE bool get__followRedirects() const { return m_slots_URLRequestDefaultsClass.m_private__followRedirects != 0; }
    REALLY_INLINE void set__followRedirects(avmplus::bool32 newVal) { m_slots_URLRequestDefaultsClass.m_private__followRedirects = newVal; }
protected:
    REALLY_INLINE bool get__manageCookies() const { return m_slots_URLRequestDefaultsClass.m_private__manageCookies != 0; }
    REALLY_INLINE void set__manageCookies(avmplus::bool32 newVal) { m_slots_URLRequestDefaultsClass.m_private__manageCookies = newVal; }
protected:
    REALLY_INLINE bool get__authenticate() const { return m_slots_URLRequestDefaultsClass.m_private__authenticate != 0; }
    REALLY_INLINE void set__authenticate(avmplus::bool32 newVal) { m_slots_URLRequestDefaultsClass.m_private__authenticate = newVal; }
protected:
    REALLY_INLINE bool get__useCache() const { return m_slots_URLRequestDefaultsClass.m_private__useCache != 0; }
    REALLY_INLINE void set__useCache(avmplus::bool32 newVal) { m_slots_URLRequestDefaultsClass.m_private__useCache = newVal; }
protected:
    REALLY_INLINE bool get__cacheResponse() const { return m_slots_URLRequestDefaultsClass.m_private__cacheResponse != 0; }
    REALLY_INLINE void set__cacheResponse(avmplus::bool32 newVal) { m_slots_URLRequestDefaultsClass.m_private__cacheResponse = newVal; }
protected:
    REALLY_INLINE avmplus::String* get__userAgent() const { return m_slots_URLRequestDefaultsClass.m_private__userAgent; }
    REALLY_INLINE void set__userAgent(avmplus::String* newVal) { m_slots_URLRequestDefaultsClass.m_private__userAgent = newVal; }
protected:
    REALLY_INLINE avmplus::Atom get__loginCredentials() const { return m_slots_URLRequestDefaultsClass.m_private__loginCredentials; }
    REALLY_INLINE void set__loginCredentials(avmplus::Atom newVal) { m_slots_URLRequestDefaultsClass.m_private__loginCredentials = newVal; }
protected:
    REALLY_INLINE avmplus::String* get__defaultUserAgent() const { return m_slots_URLRequestDefaultsClass.m_private__defaultUserAgent; }
    REALLY_INLINE void set__defaultUserAgent(avmplus::String* newVal) { m_slots_URLRequestDefaultsClass.m_private__defaultUserAgent = newVal; }
protected:
    REALLY_INLINE double get__idleTimeout() const { return m_slots_URLRequestDefaultsClass.m_private__idleTimeout; }
    REALLY_INLINE void set__idleTimeout(double newVal) { m_slots_URLRequestDefaultsClass.m_private__idleTimeout = newVal; }
private:
    avmplus::NativeID::avmplus_URLRequestDefaultsClassSlots m_slots_URLRequestDefaultsClass;
protected:
    inline explicit URLRequestDefaultsClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit URLRequestDefaultsClass(const URLRequestDefaultsClass&); // unimplemented
    void operator=(const URLRequestDefaultsClass&); // unimplemented
};

#define avmplus_URLRequestDefaultsClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.net::URLRequestHeader
//-----------------------------------------------------------
class URLRequestHeaderObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::String* get_name() const { return m_slots_URLRequestHeaderObject.m_name; }
    REALLY_INLINE void set_name(avmplus::String* newVal) { m_slots_URLRequestHeaderObject.m_name = newVal; }
public:
    REALLY_INLINE avmplus::String* get_value() const { return m_slots_URLRequestHeaderObject.m_value; }
    REALLY_INLINE void set_value(avmplus::String* newVal) { m_slots_URLRequestHeaderObject.m_value = newVal; }
private:
    avmplus::NativeID::avmplus_URLRequestHeaderObjectSlots m_slots_URLRequestHeaderObject;
protected:
    friend class avmplus::URLRequestHeaderClass;
    REALLY_INLINE explicit URLRequestHeaderObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit URLRequestHeaderObject(const URLRequestHeaderObject&); // unimplemented
    void operator=(const URLRequestHeaderObject&); // unimplemented
};

#define avmplus_URLRequestHeaderObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.net::URLRequestHeader$
//-----------------------------------------------------------
class URLRequestHeaderClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::URLRequestHeaderObject> constructObject(GCRef<avmplus::String> arg1, GCRef<avmplus::String> arg2)
    {
        avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom(), arg2->atom() };
        avmplus::Atom const result = this->construct(2, args);
        return GCRef<avmplus::URLRequestHeaderObject>((avmplus::URLRequestHeaderObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::URLRequestHeaderObject> constructObject(GCRef<avmplus::String> arg1)
    {
        avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom() };
        avmplus::Atom const result = this->construct(1, args);
        return GCRef<avmplus::URLRequestHeaderObject>((avmplus::URLRequestHeaderObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::URLRequestHeaderObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::URLRequestHeaderObject>((avmplus::URLRequestHeaderObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::URLRequestHeaderObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::URLRequestHeaderObject>((avmplus::URLRequestHeaderObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::URLRequestHeaderObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::URLRequestHeaderObject>((avmplus::URLRequestHeaderObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::URLRequestHeaderObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::URLRequestHeaderObject>((avmplus::URLRequestHeaderObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::URLRequestHeaderObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::URLRequestHeaderObject>((avmplus::URLRequestHeaderObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit URLRequestHeaderClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit URLRequestHeaderClass(const URLRequestHeaderClass&); // unimplemented
    void operator=(const URLRequestHeaderClass&); // unimplemented
};

#define avmplus_URLRequestHeaderClass_isExactInterlock 1
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
    REALLY_INLINE avmplus::String* get__ARCH() const { return m_slots_CapabilitiesClass.m_private__ARCH; }
    REALLY_INLINE void set__ARCH(avmplus::String* newVal) { m_slots_CapabilitiesClass.m_private__ARCH = newVal; }
protected:
    REALLY_INLINE avmplus::String* get__M() const { return m_slots_CapabilitiesClass.m_private__M; }
    REALLY_INLINE void set__M(avmplus::String* newVal) { m_slots_CapabilitiesClass.m_private__M = newVal; }
protected:
    REALLY_INLINE avmplus::String* get__PR32() const { return m_slots_CapabilitiesClass.m_private__PR32; }
    REALLY_INLINE void set__PR32(avmplus::String* newVal) { m_slots_CapabilitiesClass.m_private__PR32 = newVal; }
protected:
    REALLY_INLINE avmplus::String* get__PR64() const { return m_slots_CapabilitiesClass.m_private__PR64; }
    REALLY_INLINE void set__PR64(avmplus::String* newVal) { m_slots_CapabilitiesClass.m_private__PR64 = newVal; }
private:
    avmplus::NativeID::avmplus_CapabilitiesClassSlots m_slots_CapabilitiesClass;
protected:
    inline explicit CapabilitiesClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit CapabilitiesClass(const CapabilitiesClass&); // unimplemented
    void operator=(const CapabilitiesClass&); // unimplemented
};

#define avmplus_CapabilitiesClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.system::Security
//-----------------------------------------------------------
class SecurityObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::SecurityClass;
    REALLY_INLINE explicit SecurityObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit SecurityObject(const SecurityObject&); // unimplemented
    void operator=(const SecurityObject&); // unimplemented
};

#define avmplus_SecurityObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.system::Security$
//-----------------------------------------------------------
class SecurityClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::SecurityObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::SecurityObject>((avmplus::SecurityObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::SecurityObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::SecurityObject>((avmplus::SecurityObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SecurityObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::SecurityObject>((avmplus::SecurityObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SecurityObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::SecurityObject>((avmplus::SecurityObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SecurityObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::SecurityObject>((avmplus::SecurityObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    REALLY_INLINE avmplus::String* get__sandboxType() const { return m_slots_SecurityClass.m_private__sandboxType; }
    REALLY_INLINE void set__sandboxType(avmplus::String* newVal) { m_slots_SecurityClass.m_private__sandboxType = newVal; }
public:
    REALLY_INLINE avmplus::String* get_REMOTE() const { return m_slots_SecurityClass.m_REMOTE; }
    REALLY_INLINE void setconst_REMOTE(avmplus::String* newVal) { m_slots_SecurityClass.m_REMOTE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_LOCAL_WITH_FILE() const { return m_slots_SecurityClass.m_LOCAL_WITH_FILE; }
    REALLY_INLINE void setconst_LOCAL_WITH_FILE(avmplus::String* newVal) { m_slots_SecurityClass.m_LOCAL_WITH_FILE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_LOCAL_WITH_NETWORK() const { return m_slots_SecurityClass.m_LOCAL_WITH_NETWORK; }
    REALLY_INLINE void setconst_LOCAL_WITH_NETWORK(avmplus::String* newVal) { m_slots_SecurityClass.m_LOCAL_WITH_NETWORK = newVal; }
public:
    REALLY_INLINE avmplus::String* get_LOCAL_TRUSTED() const { return m_slots_SecurityClass.m_LOCAL_TRUSTED; }
    REALLY_INLINE void setconst_LOCAL_TRUSTED(avmplus::String* newVal) { m_slots_SecurityClass.m_LOCAL_TRUSTED = newVal; }
public:
    REALLY_INLINE avmplus::String* get_APPLICATION() const { return m_slots_SecurityClass.m_APPLICATION; }
    REALLY_INLINE void setconst_APPLICATION(avmplus::String* newVal) { m_slots_SecurityClass.m_APPLICATION = newVal; }
private:
    avmplus::NativeID::avmplus_SecurityClassSlots m_slots_SecurityClass;
protected:
    inline explicit SecurityClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit SecurityClass(const SecurityClass&); // unimplemented
    void operator=(const SecurityClass&); // unimplemented
};

#define avmplus_SecurityClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.system::SecurityPrivilege
//-----------------------------------------------------------
class SecurityPrivilegeObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::SecurityPrivilegeClass;
    REALLY_INLINE explicit SecurityPrivilegeObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit SecurityPrivilegeObject(const SecurityPrivilegeObject&); // unimplemented
    void operator=(const SecurityPrivilegeObject&); // unimplemented
};

#define avmplus_SecurityPrivilegeObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.system::SecurityPrivilege$
//-----------------------------------------------------------
class SecurityPrivilegeClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::SecurityPrivilegeObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::SecurityPrivilegeObject>((avmplus::SecurityPrivilegeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::SecurityPrivilegeObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::SecurityPrivilegeObject>((avmplus::SecurityPrivilegeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SecurityPrivilegeObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::SecurityPrivilegeObject>((avmplus::SecurityPrivilegeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SecurityPrivilegeObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::SecurityPrivilegeObject>((avmplus::SecurityPrivilegeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::SecurityPrivilegeObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::SecurityPrivilegeObject>((avmplus::SecurityPrivilegeObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::Atom get_FILE() const { return m_slots_SecurityPrivilegeClass.m_FILE; }
    REALLY_INLINE void setconst_FILE(avmplus::Atom newVal) { m_slots_SecurityPrivilegeClass.m_FILE = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_FILE_READ() const { return m_slots_SecurityPrivilegeClass.m_FILE_READ; }
    REALLY_INLINE void setconst_FILE_READ(avmplus::Atom newVal) { m_slots_SecurityPrivilegeClass.m_FILE_READ = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_FILE_WRITE() const { return m_slots_SecurityPrivilegeClass.m_FILE_WRITE; }
    REALLY_INLINE void setconst_FILE_WRITE(avmplus::Atom newVal) { m_slots_SecurityPrivilegeClass.m_FILE_WRITE = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_FILE_APPSTORE() const { return m_slots_SecurityPrivilegeClass.m_FILE_APPSTORE; }
    REALLY_INLINE void setconst_FILE_APPSTORE(avmplus::Atom newVal) { m_slots_SecurityPrivilegeClass.m_FILE_APPSTORE = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_FILE_PATHACCESS() const { return m_slots_SecurityPrivilegeClass.m_FILE_PATHACCESS; }
    REALLY_INLINE void setconst_FILE_PATHACCESS(avmplus::Atom newVal) { m_slots_SecurityPrivilegeClass.m_FILE_PATHACCESS = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_FILE_TEMP() const { return m_slots_SecurityPrivilegeClass.m_FILE_TEMP; }
    REALLY_INLINE void setconst_FILE_TEMP(avmplus::Atom newVal) { m_slots_SecurityPrivilegeClass.m_FILE_TEMP = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_FILE_WRITE_RESOURCE() const { return m_slots_SecurityPrivilegeClass.m_FILE_WRITE_RESOURCE; }
    REALLY_INLINE void setconst_FILE_WRITE_RESOURCE(avmplus::Atom newVal) { m_slots_SecurityPrivilegeClass.m_FILE_WRITE_RESOURCE = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_HTTP_ALL() const { return m_slots_SecurityPrivilegeClass.m_HTTP_ALL; }
    REALLY_INLINE void setconst_HTTP_ALL(avmplus::Atom newVal) { m_slots_SecurityPrivilegeClass.m_HTTP_ALL = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_HTML() const { return m_slots_SecurityPrivilegeClass.m_HTML; }
    REALLY_INLINE void setconst_HTML(avmplus::Atom newVal) { m_slots_SecurityPrivilegeClass.m_HTML = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_WINDOW() const { return m_slots_SecurityPrivilegeClass.m_WINDOW; }
    REALLY_INLINE void setconst_WINDOW(avmplus::Atom newVal) { m_slots_SecurityPrivilegeClass.m_WINDOW = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_SCREEN() const { return m_slots_SecurityPrivilegeClass.m_SCREEN; }
    REALLY_INLINE void setconst_SCREEN(avmplus::Atom newVal) { m_slots_SecurityPrivilegeClass.m_SCREEN = newVal; }
private:
    avmplus::NativeID::avmplus_SecurityPrivilegeClassSlots m_slots_SecurityPrivilegeClass;
protected:
    inline explicit SecurityPrivilegeClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit SecurityPrivilegeClass(const SecurityPrivilegeClass&); // unimplemented
    void operator=(const SecurityPrivilegeClass&); // unimplemented
};

#define avmplus_SecurityPrivilegeClass_isExactInterlock 1
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
    friend class avmshell::SystemClass;
    REALLY_INLINE explicit SystemObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit SystemObject(const SystemObject&); // unimplemented
    void operator=(const SystemObject&); // unimplemented
};

#define avmplus_SystemObject_isExactInterlock 1
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
// shell.async::CoreEventLoop
//-----------------------------------------------------------
class CoreEventLoopObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    REALLY_INLINE GCRef<avmplus::EventLoopInterface> as_EventLoopInterface()
    {
        return GCRef<avmplus::EventLoopInterface>((avmplus::EventLoopInterface*)this);
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    REALLY_INLINE bool get__running() const { return m_slots_CoreEventLoopObject.m_private__running != 0; }
    REALLY_INLINE void set__running(avmplus::bool32 newVal) { m_slots_CoreEventLoopObject.m_private__running = newVal; }
protected:
    REALLY_INLINE uint32_t get__frequency() const { return m_slots_CoreEventLoopObject.m_private__frequency; }
    REALLY_INLINE void set__frequency(uint32_t newVal) { m_slots_CoreEventLoopObject.m_private__frequency = newVal; }
protected:
    REALLY_INLINE uint32_t get__started() const { return m_slots_CoreEventLoopObject.m_private__started; }
    REALLY_INLINE void set__started(uint32_t newVal) { m_slots_CoreEventLoopObject.m_private__started = newVal; }
protected:
    REALLY_INLINE uint32_t get__elapsed() const { return m_slots_CoreEventLoopObject.m_private__elapsed; }
    REALLY_INLINE void set__elapsed(uint32_t newVal) { m_slots_CoreEventLoopObject.m_private__elapsed = newVal; }
protected:
    REALLY_INLINE uint32_t get__frame() const { return m_slots_CoreEventLoopObject.m_private__frame; }
    REALLY_INLINE void set__frame(uint32_t newVal) { m_slots_CoreEventLoopObject.m_private__frame = newVal; }
protected:
    REALLY_INLINE avmplus::ArrayObject* get__timers() const { return m_slots_CoreEventLoopObject.m_private__timers; }
    REALLY_INLINE void set__timers(avmplus::ArrayObject* newVal) { m_slots_CoreEventLoopObject.m_private__timers = newVal; }
protected:
    REALLY_INLINE avmplus::FunctionObject* get__callback() const { return m_slots_CoreEventLoopObject.m_private__callback; }
    REALLY_INLINE void set__callback(avmplus::FunctionObject* newVal) { m_slots_CoreEventLoopObject.m_private__callback = newVal; }
private:
    avmplus::NativeID::avmplus_CoreEventLoopObjectSlots m_slots_CoreEventLoopObject;
protected:
    friend class avmplus::CoreEventLoopClass;
    REALLY_INLINE explicit CoreEventLoopObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit CoreEventLoopObject(const CoreEventLoopObject&); // unimplemented
    void operator=(const CoreEventLoopObject&); // unimplemented
};

#define avmplus_CoreEventLoopObject_isExactInterlock 1
//-----------------------------------------------------------
// shell.async::CoreEventLoop$
//-----------------------------------------------------------
class CoreEventLoopClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::CoreEventLoopObject> constructObject(uint32_t arg1)
    {
        avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core()));
        avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->uintToAtom(arg1) };
        avmplus::Atom const result = this->construct(1, args);
        return GCRef<avmplus::CoreEventLoopObject>((avmplus::CoreEventLoopObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::CoreEventLoopObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::CoreEventLoopObject>((avmplus::CoreEventLoopObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::CoreEventLoopObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::CoreEventLoopObject>((avmplus::CoreEventLoopObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::CoreEventLoopObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::CoreEventLoopObject>((avmplus::CoreEventLoopObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::CoreEventLoopObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::CoreEventLoopObject>((avmplus::CoreEventLoopObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::CoreEventLoopObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::CoreEventLoopObject>((avmplus::CoreEventLoopObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit CoreEventLoopClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit CoreEventLoopClass(const CoreEventLoopClass&); // unimplemented
    void operator=(const CoreEventLoopClass&); // unimplemented
};

#define avmplus_CoreEventLoopClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.events::EventDispatcher
//-----------------------------------------------------------
class EventDispatcherObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
public:
    REALLY_INLINE GCRef<avmplus::IEventDispatcherInterface> as_IEventDispatcherInterface()
    {
        return GCRef<avmplus::IEventDispatcherInterface>((avmplus::IEventDispatcherInterface*)this);
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    REALLY_INLINE avmplus::IEventDispatcherInterface* get__target() const { return m_slots_EventDispatcherObject.m_private__target; }
    REALLY_INLINE void set__target(avmplus::IEventDispatcherInterface* newVal) { m_slots_EventDispatcherObject.m_private__target = newVal; }
public:
    REALLY_INLINE avmplus::ArrayObject* get__listeners() const { return m_slots_EventDispatcherObject.m__listeners; }
    REALLY_INLINE void set__listeners(avmplus::ArrayObject* newVal) { m_slots_EventDispatcherObject.m__listeners = newVal; }
public:
    REALLY_INLINE avmplus::ArrayObject* get__listenersNames() const { return m_slots_EventDispatcherObject.m__listenersNames; }
    REALLY_INLINE void set__listenersNames(avmplus::ArrayObject* newVal) { m_slots_EventDispatcherObject.m__listenersNames = newVal; }
public:
    REALLY_INLINE avmplus::ArrayObject* get__listenersCalls() const { return m_slots_EventDispatcherObject.m__listenersCalls; }
    REALLY_INLINE void set__listenersCalls(avmplus::ArrayObject* newVal) { m_slots_EventDispatcherObject.m__listenersCalls = newVal; }
private:
    avmplus::NativeID::avmplus_EventDispatcherObjectSlots m_slots_EventDispatcherObject;
protected:
    friend class avmplus::EventDispatcherClass;
    REALLY_INLINE explicit EventDispatcherObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit EventDispatcherObject(const EventDispatcherObject&); // unimplemented
    void operator=(const EventDispatcherObject&); // unimplemented
};

#define avmplus_EventDispatcherObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.events::EventDispatcher$
//-----------------------------------------------------------
class EventDispatcherClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::EventDispatcherObject> constructObject(GCRef<avmplus::IEventDispatcherInterface> arg1)
    {
        avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(1, args);
        return GCRef<avmplus::EventDispatcherObject>((avmplus::EventDispatcherObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::EventDispatcherObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::EventDispatcherObject>((avmplus::EventDispatcherObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::EventDispatcherObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::EventDispatcherObject>((avmplus::EventDispatcherObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::EventDispatcherObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::EventDispatcherObject>((avmplus::EventDispatcherObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::EventDispatcherObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::EventDispatcherObject>((avmplus::EventDispatcherObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::EventDispatcherObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::EventDispatcherObject>((avmplus::EventDispatcherObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::ArrayObject* get__objectlist() const { return m_slots_EventDispatcherClass.m__objectlist; }
    REALLY_INLINE void set__objectlist(avmplus::ArrayObject* newVal) { m_slots_EventDispatcherClass.m__objectlist = newVal; }
public:
    REALLY_INLINE avmplus::ArrayObject* get__objectmap() const { return m_slots_EventDispatcherClass.m__objectmap; }
    REALLY_INLINE void set__objectmap(avmplus::ArrayObject* newVal) { m_slots_EventDispatcherClass.m__objectmap = newVal; }
private:
    avmplus::NativeID::avmplus_EventDispatcherClassSlots m_slots_EventDispatcherClass;
protected:
    inline explicit EventDispatcherClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit EventDispatcherClass(const EventDispatcherClass&); // unimplemented
    void operator=(const EventDispatcherClass&); // unimplemented
};

#define avmplus_EventDispatcherClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.events::HTTPStatusEvent
//-----------------------------------------------------------
class HTTPStatusEventObject : public avmplus::EventObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    REALLY_INLINE int32_t get__status() const { return m_slots_HTTPStatusEventObject.m_private__status; }
    REALLY_INLINE void set__status(int32_t newVal) { m_slots_HTTPStatusEventObject.m_private__status = newVal; }
protected:
    REALLY_INLINE bool get__redirected() const { return m_slots_HTTPStatusEventObject.m_private__redirected != 0; }
    REALLY_INLINE void set__redirected(avmplus::bool32 newVal) { m_slots_HTTPStatusEventObject.m_private__redirected = newVal; }
protected:
    REALLY_INLINE avmplus::ArrayObject* get__responseHeaders() const { return m_slots_HTTPStatusEventObject.m_private__responseHeaders; }
    REALLY_INLINE void set__responseHeaders(avmplus::ArrayObject* newVal) { m_slots_HTTPStatusEventObject.m_private__responseHeaders = newVal; }
protected:
    REALLY_INLINE avmplus::String* get__responseUrl() const { return m_slots_HTTPStatusEventObject.m_private__responseUrl; }
    REALLY_INLINE void set__responseUrl(avmplus::String* newVal) { m_slots_HTTPStatusEventObject.m_private__responseUrl = newVal; }
private:
    avmplus::NativeID::avmplus_HTTPStatusEventObjectSlots m_slots_HTTPStatusEventObject;
protected:
    friend class avmplus::HTTPStatusEventClass;
    REALLY_INLINE explicit HTTPStatusEventObject(VTable* ivtable, ScriptObject* delegate) : avmplus::EventObject(ivtable, delegate) {}
private:
    explicit HTTPStatusEventObject(const HTTPStatusEventObject&); // unimplemented
    void operator=(const HTTPStatusEventObject&); // unimplemented
};

#define avmplus_HTTPStatusEventObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.events::HTTPStatusEvent$
//-----------------------------------------------------------
class HTTPStatusEventClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::HTTPStatusEventObject> constructObject(GCRef<avmplus::String> arg1, bool arg2, bool arg3, int32_t arg4, bool arg5)
    {
        avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core()));
        avmplus::Atom args[6] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom(), ((arg2) ? trueAtom : falseAtom), ((arg3) ? trueAtom : falseAtom), core->intToAtom(arg4), ((arg5) ? trueAtom : falseAtom) };
        avmplus::Atom const result = this->construct(5, args);
        return GCRef<avmplus::HTTPStatusEventObject>((avmplus::HTTPStatusEventObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::HTTPStatusEventObject> constructObject(GCRef<avmplus::String> arg1, bool arg2, bool arg3, int32_t arg4)
    {
        avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core()));
        avmplus::Atom args[5] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom(), ((arg2) ? trueAtom : falseAtom), ((arg3) ? trueAtom : falseAtom), core->intToAtom(arg4) };
        avmplus::Atom const result = this->construct(4, args);
        return GCRef<avmplus::HTTPStatusEventObject>((avmplus::HTTPStatusEventObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::HTTPStatusEventObject> constructObject(GCRef<avmplus::String> arg1, bool arg2, bool arg3)
    {
        avmplus::Atom args[4] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom(), ((arg2) ? trueAtom : falseAtom), ((arg3) ? trueAtom : falseAtom) };
        avmplus::Atom const result = this->construct(3, args);
        return GCRef<avmplus::HTTPStatusEventObject>((avmplus::HTTPStatusEventObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::HTTPStatusEventObject> constructObject(GCRef<avmplus::String> arg1, bool arg2)
    {
        avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom(), ((arg2) ? trueAtom : falseAtom) };
        avmplus::Atom const result = this->construct(2, args);
        return GCRef<avmplus::HTTPStatusEventObject>((avmplus::HTTPStatusEventObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::HTTPStatusEventObject> constructObject(GCRef<avmplus::String> arg1)
    {
        avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom() };
        avmplus::Atom const result = this->construct(1, args);
        return GCRef<avmplus::HTTPStatusEventObject>((avmplus::HTTPStatusEventObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::HTTPStatusEventObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::HTTPStatusEventObject>((avmplus::HTTPStatusEventObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::HTTPStatusEventObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::HTTPStatusEventObject>((avmplus::HTTPStatusEventObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::HTTPStatusEventObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::HTTPStatusEventObject>((avmplus::HTTPStatusEventObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::HTTPStatusEventObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::HTTPStatusEventObject>((avmplus::HTTPStatusEventObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::String* get_HTTP_STATUS() const { return m_slots_HTTPStatusEventClass.m_HTTP_STATUS; }
    REALLY_INLINE void setconst_HTTP_STATUS(avmplus::String* newVal) { m_slots_HTTPStatusEventClass.m_HTTP_STATUS = newVal; }
public:
    REALLY_INLINE avmplus::String* get_HTTP_RESPONSE_STATUS() const { return m_slots_HTTPStatusEventClass.m_HTTP_RESPONSE_STATUS; }
    REALLY_INLINE void setconst_HTTP_RESPONSE_STATUS(avmplus::String* newVal) { m_slots_HTTPStatusEventClass.m_HTTP_RESPONSE_STATUS = newVal; }
private:
    avmplus::NativeID::avmplus_HTTPStatusEventClassSlots m_slots_HTTPStatusEventClass;
protected:
    inline explicit HTTPStatusEventClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit HTTPStatusEventClass(const HTTPStatusEventClass&); // unimplemented
    void operator=(const HTTPStatusEventClass&); // unimplemented
};

#define avmplus_HTTPStatusEventClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.events::TimerEvent
//-----------------------------------------------------------
class TimerEventObject : public avmplus::EventObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::TimerEventClass;
    REALLY_INLINE explicit TimerEventObject(VTable* ivtable, ScriptObject* delegate) : avmplus::EventObject(ivtable, delegate) {}
private:
    explicit TimerEventObject(const TimerEventObject&); // unimplemented
    void operator=(const TimerEventObject&); // unimplemented
};

#define avmplus_TimerEventObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.events::TimerEvent$
//-----------------------------------------------------------
class TimerEventClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::TimerEventObject> constructObject(GCRef<avmplus::String> arg1, bool arg2, bool arg3)
    {
        avmplus::Atom args[4] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom(), ((arg2) ? trueAtom : falseAtom), ((arg3) ? trueAtom : falseAtom) };
        avmplus::Atom const result = this->construct(3, args);
        return GCRef<avmplus::TimerEventObject>((avmplus::TimerEventObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::TimerEventObject> constructObject(GCRef<avmplus::String> arg1, bool arg2)
    {
        avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom(), ((arg2) ? trueAtom : falseAtom) };
        avmplus::Atom const result = this->construct(2, args);
        return GCRef<avmplus::TimerEventObject>((avmplus::TimerEventObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::TimerEventObject> constructObject(GCRef<avmplus::String> arg1)
    {
        avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom() };
        avmplus::Atom const result = this->construct(1, args);
        return GCRef<avmplus::TimerEventObject>((avmplus::TimerEventObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::TimerEventObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::TimerEventObject>((avmplus::TimerEventObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::TimerEventObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::TimerEventObject>((avmplus::TimerEventObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::TimerEventObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::TimerEventObject>((avmplus::TimerEventObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::TimerEventObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::TimerEventObject>((avmplus::TimerEventObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::String* get_TIMER() const { return m_slots_TimerEventClass.m_TIMER; }
    REALLY_INLINE void setconst_TIMER(avmplus::String* newVal) { m_slots_TimerEventClass.m_TIMER = newVal; }
public:
    REALLY_INLINE avmplus::String* get_TIMER_COMPLETE() const { return m_slots_TimerEventClass.m_TIMER_COMPLETE; }
    REALLY_INLINE void setconst_TIMER_COMPLETE(avmplus::String* newVal) { m_slots_TimerEventClass.m_TIMER_COMPLETE = newVal; }
private:
    avmplus::NativeID::avmplus_TimerEventClassSlots m_slots_TimerEventClass;
protected:
    inline explicit TimerEventClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit TimerEventClass(const TimerEventClass&); // unimplemented
    void operator=(const TimerEventClass&); // unimplemented
};

#define avmplus_TimerEventClass_isExactInterlock 1
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
//-----------------------------------------------------------
// flash.utils::Timer
//-----------------------------------------------------------
class TimerObject : public avmplus::EventDispatcherObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    REALLY_INLINE int32_t get__repeatCount() const { return m_slots_TimerObject.m_private__repeatCount; }
    REALLY_INLINE void set__repeatCount(int32_t newVal) { m_slots_TimerObject.m_private__repeatCount = newVal; }
protected:
    REALLY_INLINE int32_t get__iteration() const { return m_slots_TimerObject.m_private__iteration; }
    REALLY_INLINE void set__iteration(int32_t newVal) { m_slots_TimerObject.m_private__iteration = newVal; }
protected:
    REALLY_INLINE bool get__running() const { return m_slots_TimerObject.m_private__running != 0; }
    REALLY_INLINE void set__running(avmplus::bool32 newVal) { m_slots_TimerObject.m_private__running = newVal; }
public:
    REALLY_INLINE uint32_t get__started() const { return m_slots_TimerObject.m__started; }
    REALLY_INLINE void set__started(uint32_t newVal) { m_slots_TimerObject.m__started = newVal; }
public:
    REALLY_INLINE uint32_t get__elapsed() const { return m_slots_TimerObject.m__elapsed; }
    REALLY_INLINE void set__elapsed(uint32_t newVal) { m_slots_TimerObject.m__elapsed = newVal; }
protected:
    REALLY_INLINE avmplus::FunctionObject* get__closure() const { return m_slots_TimerObject.m_private__closure; }
    REALLY_INLINE void set__closure(avmplus::FunctionObject* newVal) { m_slots_TimerObject.m_private__closure = newVal; }
protected:
    REALLY_INLINE double get__delay() const { return m_slots_TimerObject.m_private__delay; }
    REALLY_INLINE void set__delay(double newVal) { m_slots_TimerObject.m_private__delay = newVal; }
private:
    avmplus::NativeID::avmplus_TimerObjectSlots m_slots_TimerObject;
protected:
    friend class avmplus::TimerClass;
    REALLY_INLINE explicit TimerObject(VTable* ivtable, ScriptObject* delegate) : avmplus::EventDispatcherObject(ivtable, delegate) {}
private:
    explicit TimerObject(const TimerObject&); // unimplemented
    void operator=(const TimerObject&); // unimplemented
};

#define avmplus_TimerObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.utils::Timer$
//-----------------------------------------------------------
class TimerClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::TimerObject> constructObject(double arg1, int32_t arg2)
    {
        avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core()));
        avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->doubleToAtom(arg1), core->intToAtom(arg2) };
        avmplus::Atom const result = this->construct(2, args);
        return GCRef<avmplus::TimerObject>((avmplus::TimerObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::TimerObject> constructObject(double arg1)
    {
        avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core()));
        avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->doubleToAtom(arg1) };
        avmplus::Atom const result = this->construct(1, args);
        return GCRef<avmplus::TimerObject>((avmplus::TimerObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::TimerObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::TimerObject>((avmplus::TimerObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::TimerObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::TimerObject>((avmplus::TimerObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::TimerObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::TimerObject>((avmplus::TimerObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::TimerObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::TimerObject>((avmplus::TimerObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit TimerClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit TimerClass(const TimerClass&); // unimplemented
    void operator=(const TimerClass&); // unimplemented
};

#define avmplus_TimerClass_isExactInterlock 1
}

#endif // _H_nativegen_classes_shell_toplevel
