/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/* machine generated file -- do not edit */

#ifndef _H_nativegen_classes_builtin
#define _H_nativegen_classes_builtin

namespace avmplus {

//-----------------------------------------------------------
// Errors
//-----------------------------------------------------------
class ErrorsObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::ErrorsClass;
    REALLY_INLINE explicit ErrorsObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit ErrorsObject(const ErrorsObject&); // unimplemented
    void operator=(const ErrorsObject&); // unimplemented
};

#define avmplus_ErrorsObject_isExactInterlock 1
//-----------------------------------------------------------
// Errors$
//-----------------------------------------------------------
class ErrorsClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::ErrorsObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::ErrorsObject>((avmplus::ErrorsObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::ErrorsObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::ErrorsObject>((avmplus::ErrorsObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::ErrorsObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::ErrorsObject>((avmplus::ErrorsObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::ErrorsObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::ErrorsObject>((avmplus::ErrorsObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::ErrorsObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::ErrorsObject>((avmplus::ErrorsObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::Atom get_kOutOfMemoryError() const { return m_slots_ErrorsClass.m_kOutOfMemoryError; }
    REALLY_INLINE void setconst_kOutOfMemoryError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kOutOfMemoryError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kNotImplementedError() const { return m_slots_ErrorsClass.m_kNotImplementedError; }
    REALLY_INLINE void setconst_kNotImplementedError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kNotImplementedError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kInvalidPrecisionError() const { return m_slots_ErrorsClass.m_kInvalidPrecisionError; }
    REALLY_INLINE void setconst_kInvalidPrecisionError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kInvalidPrecisionError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kInvalidRadixError() const { return m_slots_ErrorsClass.m_kInvalidRadixError; }
    REALLY_INLINE void setconst_kInvalidRadixError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kInvalidRadixError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kInvokeOnIncompatibleObjectError() const { return m_slots_ErrorsClass.m_kInvokeOnIncompatibleObjectError; }
    REALLY_INLINE void setconst_kInvokeOnIncompatibleObjectError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kInvokeOnIncompatibleObjectError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kArrayIndexNotIntegerError() const { return m_slots_ErrorsClass.m_kArrayIndexNotIntegerError; }
    REALLY_INLINE void setconst_kArrayIndexNotIntegerError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kArrayIndexNotIntegerError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kCallOfNonFunctionError() const { return m_slots_ErrorsClass.m_kCallOfNonFunctionError; }
    REALLY_INLINE void setconst_kCallOfNonFunctionError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kCallOfNonFunctionError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kConstructOfNonFunctionError() const { return m_slots_ErrorsClass.m_kConstructOfNonFunctionError; }
    REALLY_INLINE void setconst_kConstructOfNonFunctionError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kConstructOfNonFunctionError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kAmbiguousBindingError() const { return m_slots_ErrorsClass.m_kAmbiguousBindingError; }
    REALLY_INLINE void setconst_kAmbiguousBindingError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kAmbiguousBindingError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kConvertNullToObjectError() const { return m_slots_ErrorsClass.m_kConvertNullToObjectError; }
    REALLY_INLINE void setconst_kConvertNullToObjectError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kConvertNullToObjectError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kConvertUndefinedToObjectError() const { return m_slots_ErrorsClass.m_kConvertUndefinedToObjectError; }
    REALLY_INLINE void setconst_kConvertUndefinedToObjectError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kConvertUndefinedToObjectError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kIllegalOpcodeError() const { return m_slots_ErrorsClass.m_kIllegalOpcodeError; }
    REALLY_INLINE void setconst_kIllegalOpcodeError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kIllegalOpcodeError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kLastInstExceedsCodeSizeError() const { return m_slots_ErrorsClass.m_kLastInstExceedsCodeSizeError; }
    REALLY_INLINE void setconst_kLastInstExceedsCodeSizeError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kLastInstExceedsCodeSizeError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kFindVarWithNoScopeError() const { return m_slots_ErrorsClass.m_kFindVarWithNoScopeError; }
    REALLY_INLINE void setconst_kFindVarWithNoScopeError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kFindVarWithNoScopeError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kClassNotFoundError() const { return m_slots_ErrorsClass.m_kClassNotFoundError; }
    REALLY_INLINE void setconst_kClassNotFoundError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kClassNotFoundError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kIllegalSetDxns() const { return m_slots_ErrorsClass.m_kIllegalSetDxns; }
    REALLY_INLINE void setconst_kIllegalSetDxns(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kIllegalSetDxns = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kDescendentsError() const { return m_slots_ErrorsClass.m_kDescendentsError; }
    REALLY_INLINE void setconst_kDescendentsError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kDescendentsError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kScopeStackOverflowError() const { return m_slots_ErrorsClass.m_kScopeStackOverflowError; }
    REALLY_INLINE void setconst_kScopeStackOverflowError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kScopeStackOverflowError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kScopeStackUnderflowError() const { return m_slots_ErrorsClass.m_kScopeStackUnderflowError; }
    REALLY_INLINE void setconst_kScopeStackUnderflowError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kScopeStackUnderflowError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kGetScopeObjectBoundsError() const { return m_slots_ErrorsClass.m_kGetScopeObjectBoundsError; }
    REALLY_INLINE void setconst_kGetScopeObjectBoundsError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kGetScopeObjectBoundsError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kCannotFallOffMethodError() const { return m_slots_ErrorsClass.m_kCannotFallOffMethodError; }
    REALLY_INLINE void setconst_kCannotFallOffMethodError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kCannotFallOffMethodError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kInvalidBranchTargetError() const { return m_slots_ErrorsClass.m_kInvalidBranchTargetError; }
    REALLY_INLINE void setconst_kInvalidBranchTargetError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kInvalidBranchTargetError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kIllegalVoidError() const { return m_slots_ErrorsClass.m_kIllegalVoidError; }
    REALLY_INLINE void setconst_kIllegalVoidError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kIllegalVoidError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kStackOverflowError() const { return m_slots_ErrorsClass.m_kStackOverflowError; }
    REALLY_INLINE void setconst_kStackOverflowError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kStackOverflowError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kStackUnderflowError() const { return m_slots_ErrorsClass.m_kStackUnderflowError; }
    REALLY_INLINE void setconst_kStackUnderflowError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kStackUnderflowError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kInvalidRegisterError() const { return m_slots_ErrorsClass.m_kInvalidRegisterError; }
    REALLY_INLINE void setconst_kInvalidRegisterError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kInvalidRegisterError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kSlotExceedsCountError() const { return m_slots_ErrorsClass.m_kSlotExceedsCountError; }
    REALLY_INLINE void setconst_kSlotExceedsCountError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kSlotExceedsCountError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kMethodInfoExceedsCountError() const { return m_slots_ErrorsClass.m_kMethodInfoExceedsCountError; }
    REALLY_INLINE void setconst_kMethodInfoExceedsCountError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kMethodInfoExceedsCountError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kDispIdExceedsCountError() const { return m_slots_ErrorsClass.m_kDispIdExceedsCountError; }
    REALLY_INLINE void setconst_kDispIdExceedsCountError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kDispIdExceedsCountError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kDispIdUndefinedError() const { return m_slots_ErrorsClass.m_kDispIdUndefinedError; }
    REALLY_INLINE void setconst_kDispIdUndefinedError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kDispIdUndefinedError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kStackDepthUnbalancedError() const { return m_slots_ErrorsClass.m_kStackDepthUnbalancedError; }
    REALLY_INLINE void setconst_kStackDepthUnbalancedError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kStackDepthUnbalancedError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kScopeDepthUnbalancedError() const { return m_slots_ErrorsClass.m_kScopeDepthUnbalancedError; }
    REALLY_INLINE void setconst_kScopeDepthUnbalancedError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kScopeDepthUnbalancedError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kCpoolIndexRangeError() const { return m_slots_ErrorsClass.m_kCpoolIndexRangeError; }
    REALLY_INLINE void setconst_kCpoolIndexRangeError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kCpoolIndexRangeError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kCpoolEntryWrongTypeError() const { return m_slots_ErrorsClass.m_kCpoolEntryWrongTypeError; }
    REALLY_INLINE void setconst_kCpoolEntryWrongTypeError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kCpoolEntryWrongTypeError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kCheckTypeFailedError() const { return m_slots_ErrorsClass.m_kCheckTypeFailedError; }
    REALLY_INLINE void setconst_kCheckTypeFailedError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kCheckTypeFailedError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kIllegalSuperCallError() const { return m_slots_ErrorsClass.m_kIllegalSuperCallError; }
    REALLY_INLINE void setconst_kIllegalSuperCallError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kIllegalSuperCallError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kCannotAssignToMethodError() const { return m_slots_ErrorsClass.m_kCannotAssignToMethodError; }
    REALLY_INLINE void setconst_kCannotAssignToMethodError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kCannotAssignToMethodError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kRedefinedError() const { return m_slots_ErrorsClass.m_kRedefinedError; }
    REALLY_INLINE void setconst_kRedefinedError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kRedefinedError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kCannotVerifyUntilReferencedError() const { return m_slots_ErrorsClass.m_kCannotVerifyUntilReferencedError; }
    REALLY_INLINE void setconst_kCannotVerifyUntilReferencedError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kCannotVerifyUntilReferencedError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kCantUseInstanceofOnNonObjectError() const { return m_slots_ErrorsClass.m_kCantUseInstanceofOnNonObjectError; }
    REALLY_INLINE void setconst_kCantUseInstanceofOnNonObjectError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kCantUseInstanceofOnNonObjectError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kIsTypeMustBeClassError() const { return m_slots_ErrorsClass.m_kIsTypeMustBeClassError; }
    REALLY_INLINE void setconst_kIsTypeMustBeClassError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kIsTypeMustBeClassError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kInvalidMagicError() const { return m_slots_ErrorsClass.m_kInvalidMagicError; }
    REALLY_INLINE void setconst_kInvalidMagicError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kInvalidMagicError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kInvalidCodeLengthError() const { return m_slots_ErrorsClass.m_kInvalidCodeLengthError; }
    REALLY_INLINE void setconst_kInvalidCodeLengthError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kInvalidCodeLengthError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kInvalidMethodInfoFlagsError() const { return m_slots_ErrorsClass.m_kInvalidMethodInfoFlagsError; }
    REALLY_INLINE void setconst_kInvalidMethodInfoFlagsError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kInvalidMethodInfoFlagsError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kUnsupportedTraitsKindError() const { return m_slots_ErrorsClass.m_kUnsupportedTraitsKindError; }
    REALLY_INLINE void setconst_kUnsupportedTraitsKindError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kUnsupportedTraitsKindError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kMethodInfoOrderError() const { return m_slots_ErrorsClass.m_kMethodInfoOrderError; }
    REALLY_INLINE void setconst_kMethodInfoOrderError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kMethodInfoOrderError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kMissingEntryPointError() const { return m_slots_ErrorsClass.m_kMissingEntryPointError; }
    REALLY_INLINE void setconst_kMissingEntryPointError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kMissingEntryPointError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kPrototypeTypeError() const { return m_slots_ErrorsClass.m_kPrototypeTypeError; }
    REALLY_INLINE void setconst_kPrototypeTypeError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kPrototypeTypeError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kConvertToPrimitiveError() const { return m_slots_ErrorsClass.m_kConvertToPrimitiveError; }
    REALLY_INLINE void setconst_kConvertToPrimitiveError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kConvertToPrimitiveError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kIllegalEarlyBindingError() const { return m_slots_ErrorsClass.m_kIllegalEarlyBindingError; }
    REALLY_INLINE void setconst_kIllegalEarlyBindingError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kIllegalEarlyBindingError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kInvalidURIError() const { return m_slots_ErrorsClass.m_kInvalidURIError; }
    REALLY_INLINE void setconst_kInvalidURIError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kInvalidURIError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kIllegalOverrideError() const { return m_slots_ErrorsClass.m_kIllegalOverrideError; }
    REALLY_INLINE void setconst_kIllegalOverrideError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kIllegalOverrideError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kIllegalExceptionHandlerError() const { return m_slots_ErrorsClass.m_kIllegalExceptionHandlerError; }
    REALLY_INLINE void setconst_kIllegalExceptionHandlerError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kIllegalExceptionHandlerError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kWriteSealedError() const { return m_slots_ErrorsClass.m_kWriteSealedError; }
    REALLY_INLINE void setconst_kWriteSealedError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kWriteSealedError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kIllegalSlotError() const { return m_slots_ErrorsClass.m_kIllegalSlotError; }
    REALLY_INLINE void setconst_kIllegalSlotError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kIllegalSlotError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kIllegalOperandTypeError() const { return m_slots_ErrorsClass.m_kIllegalOperandTypeError; }
    REALLY_INLINE void setconst_kIllegalOperandTypeError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kIllegalOperandTypeError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kClassInfoOrderError() const { return m_slots_ErrorsClass.m_kClassInfoOrderError; }
    REALLY_INLINE void setconst_kClassInfoOrderError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kClassInfoOrderError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kClassInfoExceedsCountError() const { return m_slots_ErrorsClass.m_kClassInfoExceedsCountError; }
    REALLY_INLINE void setconst_kClassInfoExceedsCountError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kClassInfoExceedsCountError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kNumberOutOfRangeError() const { return m_slots_ErrorsClass.m_kNumberOutOfRangeError; }
    REALLY_INLINE void setconst_kNumberOutOfRangeError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kNumberOutOfRangeError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kWrongArgumentCountError() const { return m_slots_ErrorsClass.m_kWrongArgumentCountError; }
    REALLY_INLINE void setconst_kWrongArgumentCountError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kWrongArgumentCountError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kCannotCallMethodAsConstructor() const { return m_slots_ErrorsClass.m_kCannotCallMethodAsConstructor; }
    REALLY_INLINE void setconst_kCannotCallMethodAsConstructor(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kCannotCallMethodAsConstructor = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kUndefinedVarError() const { return m_slots_ErrorsClass.m_kUndefinedVarError; }
    REALLY_INLINE void setconst_kUndefinedVarError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kUndefinedVarError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kFunctionConstructorError() const { return m_slots_ErrorsClass.m_kFunctionConstructorError; }
    REALLY_INLINE void setconst_kFunctionConstructorError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kFunctionConstructorError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kIllegalNativeMethodBodyError() const { return m_slots_ErrorsClass.m_kIllegalNativeMethodBodyError; }
    REALLY_INLINE void setconst_kIllegalNativeMethodBodyError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kIllegalNativeMethodBodyError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kCannotMergeTypesError() const { return m_slots_ErrorsClass.m_kCannotMergeTypesError; }
    REALLY_INLINE void setconst_kCannotMergeTypesError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kCannotMergeTypesError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kReadSealedError() const { return m_slots_ErrorsClass.m_kReadSealedError; }
    REALLY_INLINE void setconst_kReadSealedError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kReadSealedError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kCallNotFoundError() const { return m_slots_ErrorsClass.m_kCallNotFoundError; }
    REALLY_INLINE void setconst_kCallNotFoundError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kCallNotFoundError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kAlreadyBoundError() const { return m_slots_ErrorsClass.m_kAlreadyBoundError; }
    REALLY_INLINE void setconst_kAlreadyBoundError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kAlreadyBoundError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kZeroDispIdError() const { return m_slots_ErrorsClass.m_kZeroDispIdError; }
    REALLY_INLINE void setconst_kZeroDispIdError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kZeroDispIdError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kDuplicateDispIdError() const { return m_slots_ErrorsClass.m_kDuplicateDispIdError; }
    REALLY_INLINE void setconst_kDuplicateDispIdError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kDuplicateDispIdError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kConstWriteError() const { return m_slots_ErrorsClass.m_kConstWriteError; }
    REALLY_INLINE void setconst_kConstWriteError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kConstWriteError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kMathNotFunctionError() const { return m_slots_ErrorsClass.m_kMathNotFunctionError; }
    REALLY_INLINE void setconst_kMathNotFunctionError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kMathNotFunctionError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kMathNotConstructorError() const { return m_slots_ErrorsClass.m_kMathNotConstructorError; }
    REALLY_INLINE void setconst_kMathNotConstructorError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kMathNotConstructorError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kWriteOnlyError() const { return m_slots_ErrorsClass.m_kWriteOnlyError; }
    REALLY_INLINE void setconst_kWriteOnlyError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kWriteOnlyError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kIllegalOpMultinameError() const { return m_slots_ErrorsClass.m_kIllegalOpMultinameError; }
    REALLY_INLINE void setconst_kIllegalOpMultinameError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kIllegalOpMultinameError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kIllegalNativeMethodError() const { return m_slots_ErrorsClass.m_kIllegalNativeMethodError; }
    REALLY_INLINE void setconst_kIllegalNativeMethodError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kIllegalNativeMethodError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kIllegalNamespaceError() const { return m_slots_ErrorsClass.m_kIllegalNamespaceError; }
    REALLY_INLINE void setconst_kIllegalNamespaceError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kIllegalNamespaceError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kReadSealedErrorNs() const { return m_slots_ErrorsClass.m_kReadSealedErrorNs; }
    REALLY_INLINE void setconst_kReadSealedErrorNs(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kReadSealedErrorNs = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kNoDefaultNamespaceError() const { return m_slots_ErrorsClass.m_kNoDefaultNamespaceError; }
    REALLY_INLINE void setconst_kNoDefaultNamespaceError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kNoDefaultNamespaceError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kXMLPrefixNotBound() const { return m_slots_ErrorsClass.m_kXMLPrefixNotBound; }
    REALLY_INLINE void setconst_kXMLPrefixNotBound(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kXMLPrefixNotBound = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kXMLBadQName() const { return m_slots_ErrorsClass.m_kXMLBadQName; }
    REALLY_INLINE void setconst_kXMLBadQName(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kXMLBadQName = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kXMLUnterminatedElementTag() const { return m_slots_ErrorsClass.m_kXMLUnterminatedElementTag; }
    REALLY_INLINE void setconst_kXMLUnterminatedElementTag(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kXMLUnterminatedElementTag = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kXMLOnlyWorksWithOneItemLists() const { return m_slots_ErrorsClass.m_kXMLOnlyWorksWithOneItemLists; }
    REALLY_INLINE void setconst_kXMLOnlyWorksWithOneItemLists(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kXMLOnlyWorksWithOneItemLists = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kXMLAssignmentToIndexedXMLNotAllowed() const { return m_slots_ErrorsClass.m_kXMLAssignmentToIndexedXMLNotAllowed; }
    REALLY_INLINE void setconst_kXMLAssignmentToIndexedXMLNotAllowed(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kXMLAssignmentToIndexedXMLNotAllowed = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kXMLMarkupMustBeWellFormed() const { return m_slots_ErrorsClass.m_kXMLMarkupMustBeWellFormed; }
    REALLY_INLINE void setconst_kXMLMarkupMustBeWellFormed(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kXMLMarkupMustBeWellFormed = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kXMLAssigmentOneItemLists() const { return m_slots_ErrorsClass.m_kXMLAssigmentOneItemLists; }
    REALLY_INLINE void setconst_kXMLAssigmentOneItemLists(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kXMLAssigmentOneItemLists = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kXMLMalformedElement() const { return m_slots_ErrorsClass.m_kXMLMalformedElement; }
    REALLY_INLINE void setconst_kXMLMalformedElement(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kXMLMalformedElement = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kXMLUnterminatedCData() const { return m_slots_ErrorsClass.m_kXMLUnterminatedCData; }
    REALLY_INLINE void setconst_kXMLUnterminatedCData(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kXMLUnterminatedCData = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kXMLUnterminatedXMLDecl() const { return m_slots_ErrorsClass.m_kXMLUnterminatedXMLDecl; }
    REALLY_INLINE void setconst_kXMLUnterminatedXMLDecl(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kXMLUnterminatedXMLDecl = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kXMLUnterminatedDocTypeDecl() const { return m_slots_ErrorsClass.m_kXMLUnterminatedDocTypeDecl; }
    REALLY_INLINE void setconst_kXMLUnterminatedDocTypeDecl(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kXMLUnterminatedDocTypeDecl = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kXMLUnterminatedComment() const { return m_slots_ErrorsClass.m_kXMLUnterminatedComment; }
    REALLY_INLINE void setconst_kXMLUnterminatedComment(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kXMLUnterminatedComment = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kXMLUnterminatedAttribute() const { return m_slots_ErrorsClass.m_kXMLUnterminatedAttribute; }
    REALLY_INLINE void setconst_kXMLUnterminatedAttribute(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kXMLUnterminatedAttribute = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kXMLUnterminatedElement() const { return m_slots_ErrorsClass.m_kXMLUnterminatedElement; }
    REALLY_INLINE void setconst_kXMLUnterminatedElement(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kXMLUnterminatedElement = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kXMLUnterminatedProcessingInstruction() const { return m_slots_ErrorsClass.m_kXMLUnterminatedProcessingInstruction; }
    REALLY_INLINE void setconst_kXMLUnterminatedProcessingInstruction(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kXMLUnterminatedProcessingInstruction = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kXMLNamespaceWithPrefixAndNoURI() const { return m_slots_ErrorsClass.m_kXMLNamespaceWithPrefixAndNoURI; }
    REALLY_INLINE void setconst_kXMLNamespaceWithPrefixAndNoURI(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kXMLNamespaceWithPrefixAndNoURI = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kRegExpFlagsArgumentError() const { return m_slots_ErrorsClass.m_kRegExpFlagsArgumentError; }
    REALLY_INLINE void setconst_kRegExpFlagsArgumentError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kRegExpFlagsArgumentError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kNoScopeError() const { return m_slots_ErrorsClass.m_kNoScopeError; }
    REALLY_INLINE void setconst_kNoScopeError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kNoScopeError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kIllegalDefaultValue() const { return m_slots_ErrorsClass.m_kIllegalDefaultValue; }
    REALLY_INLINE void setconst_kIllegalDefaultValue(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kIllegalDefaultValue = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kCannotExtendFinalClass() const { return m_slots_ErrorsClass.m_kCannotExtendFinalClass; }
    REALLY_INLINE void setconst_kCannotExtendFinalClass(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kCannotExtendFinalClass = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kXMLDuplicateAttribute() const { return m_slots_ErrorsClass.m_kXMLDuplicateAttribute; }
    REALLY_INLINE void setconst_kXMLDuplicateAttribute(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kXMLDuplicateAttribute = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kCorruptABCError() const { return m_slots_ErrorsClass.m_kCorruptABCError; }
    REALLY_INLINE void setconst_kCorruptABCError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kCorruptABCError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kInvalidBaseClassError() const { return m_slots_ErrorsClass.m_kInvalidBaseClassError; }
    REALLY_INLINE void setconst_kInvalidBaseClassError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kInvalidBaseClassError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kDanglingFunctionError() const { return m_slots_ErrorsClass.m_kDanglingFunctionError; }
    REALLY_INLINE void setconst_kDanglingFunctionError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kDanglingFunctionError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kCannotExtendError() const { return m_slots_ErrorsClass.m_kCannotExtendError; }
    REALLY_INLINE void setconst_kCannotExtendError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kCannotExtendError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kCannotImplementError() const { return m_slots_ErrorsClass.m_kCannotImplementError; }
    REALLY_INLINE void setconst_kCannotImplementError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kCannotImplementError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kCoerceArgumentCountError() const { return m_slots_ErrorsClass.m_kCoerceArgumentCountError; }
    REALLY_INLINE void setconst_kCoerceArgumentCountError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kCoerceArgumentCountError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kInvalidNewActivationError() const { return m_slots_ErrorsClass.m_kInvalidNewActivationError; }
    REALLY_INLINE void setconst_kInvalidNewActivationError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kInvalidNewActivationError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kNoGlobalScopeError() const { return m_slots_ErrorsClass.m_kNoGlobalScopeError; }
    REALLY_INLINE void setconst_kNoGlobalScopeError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kNoGlobalScopeError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kNotConstructorError() const { return m_slots_ErrorsClass.m_kNotConstructorError; }
    REALLY_INLINE void setconst_kNotConstructorError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kNotConstructorError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kApplyError() const { return m_slots_ErrorsClass.m_kApplyError; }
    REALLY_INLINE void setconst_kApplyError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kApplyError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kXMLInvalidName() const { return m_slots_ErrorsClass.m_kXMLInvalidName; }
    REALLY_INLINE void setconst_kXMLInvalidName(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kXMLInvalidName = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kXMLIllegalCyclicalLoop() const { return m_slots_ErrorsClass.m_kXMLIllegalCyclicalLoop; }
    REALLY_INLINE void setconst_kXMLIllegalCyclicalLoop(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kXMLIllegalCyclicalLoop = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kDeleteTypeError() const { return m_slots_ErrorsClass.m_kDeleteTypeError; }
    REALLY_INLINE void setconst_kDeleteTypeError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kDeleteTypeError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kDeleteSealedError() const { return m_slots_ErrorsClass.m_kDeleteSealedError; }
    REALLY_INLINE void setconst_kDeleteSealedError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kDeleteSealedError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kDuplicateMethodBodyError() const { return m_slots_ErrorsClass.m_kDuplicateMethodBodyError; }
    REALLY_INLINE void setconst_kDuplicateMethodBodyError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kDuplicateMethodBodyError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kIllegalInterfaceMethodBodyError() const { return m_slots_ErrorsClass.m_kIllegalInterfaceMethodBodyError; }
    REALLY_INLINE void setconst_kIllegalInterfaceMethodBodyError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kIllegalInterfaceMethodBodyError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kFilterError() const { return m_slots_ErrorsClass.m_kFilterError; }
    REALLY_INLINE void setconst_kFilterError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kFilterError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kInvalidHasNextError() const { return m_slots_ErrorsClass.m_kInvalidHasNextError; }
    REALLY_INLINE void setconst_kInvalidHasNextError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kInvalidHasNextError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kOutOfRangeError() const { return m_slots_ErrorsClass.m_kOutOfRangeError; }
    REALLY_INLINE void setconst_kOutOfRangeError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kOutOfRangeError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kVectorFixedError() const { return m_slots_ErrorsClass.m_kVectorFixedError; }
    REALLY_INLINE void setconst_kVectorFixedError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kVectorFixedError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kTypeAppOfNonParamType() const { return m_slots_ErrorsClass.m_kTypeAppOfNonParamType; }
    REALLY_INLINE void setconst_kTypeAppOfNonParamType(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kTypeAppOfNonParamType = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kWrongTypeArgCountError() const { return m_slots_ErrorsClass.m_kWrongTypeArgCountError; }
    REALLY_INLINE void setconst_kWrongTypeArgCountError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kWrongTypeArgCountError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kJSONCyclicStructure() const { return m_slots_ErrorsClass.m_kJSONCyclicStructure; }
    REALLY_INLINE void setconst_kJSONCyclicStructure(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kJSONCyclicStructure = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kJSONInvalidReplacer() const { return m_slots_ErrorsClass.m_kJSONInvalidReplacer; }
    REALLY_INLINE void setconst_kJSONInvalidReplacer(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kJSONInvalidReplacer = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kJSONInvalidParseInput() const { return m_slots_ErrorsClass.m_kJSONInvalidParseInput; }
    REALLY_INLINE void setconst_kJSONInvalidParseInput(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kJSONInvalidParseInput = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kFileOpenError() const { return m_slots_ErrorsClass.m_kFileOpenError; }
    REALLY_INLINE void setconst_kFileOpenError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kFileOpenError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kFileWriteError() const { return m_slots_ErrorsClass.m_kFileWriteError; }
    REALLY_INLINE void setconst_kFileWriteError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kFileWriteError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kScriptTimeoutError() const { return m_slots_ErrorsClass.m_kScriptTimeoutError; }
    REALLY_INLINE void setconst_kScriptTimeoutError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kScriptTimeoutError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kScriptTerminatedError() const { return m_slots_ErrorsClass.m_kScriptTerminatedError; }
    REALLY_INLINE void setconst_kScriptTerminatedError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kScriptTerminatedError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kEndOfFileError() const { return m_slots_ErrorsClass.m_kEndOfFileError; }
    REALLY_INLINE void setconst_kEndOfFileError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kEndOfFileError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kStringIndexOutOfBoundsError() const { return m_slots_ErrorsClass.m_kStringIndexOutOfBoundsError; }
    REALLY_INLINE void setconst_kStringIndexOutOfBoundsError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kStringIndexOutOfBoundsError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kInvalidRangeError() const { return m_slots_ErrorsClass.m_kInvalidRangeError; }
    REALLY_INLINE void setconst_kInvalidRangeError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kInvalidRangeError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kNullArgumentError() const { return m_slots_ErrorsClass.m_kNullArgumentError; }
    REALLY_INLINE void setconst_kNullArgumentError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kNullArgumentError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kInvalidArgumentError() const { return m_slots_ErrorsClass.m_kInvalidArgumentError; }
    REALLY_INLINE void setconst_kInvalidArgumentError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kInvalidArgumentError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kArrayFilterNonNullObjectError() const { return m_slots_ErrorsClass.m_kArrayFilterNonNullObjectError; }
    REALLY_INLINE void setconst_kArrayFilterNonNullObjectError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kArrayFilterNonNullObjectError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kWorkerAlreadyStarted() const { return m_slots_ErrorsClass.m_kWorkerAlreadyStarted; }
    REALLY_INLINE void setconst_kWorkerAlreadyStarted(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kWorkerAlreadyStarted = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kFailedWorkerCannotBeRestarted() const { return m_slots_ErrorsClass.m_kFailedWorkerCannotBeRestarted; }
    REALLY_INLINE void setconst_kFailedWorkerCannotBeRestarted(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kFailedWorkerCannotBeRestarted = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kWorkerTerminated() const { return m_slots_ErrorsClass.m_kWorkerTerminated; }
    REALLY_INLINE void setconst_kWorkerTerminated(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kWorkerTerminated = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kMutextNotLocked() const { return m_slots_ErrorsClass.m_kMutextNotLocked; }
    REALLY_INLINE void setconst_kMutextNotLocked(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kMutextNotLocked = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kConditionInvalidTimeout() const { return m_slots_ErrorsClass.m_kConditionInvalidTimeout; }
    REALLY_INLINE void setconst_kConditionInvalidTimeout(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kConditionInvalidTimeout = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kConditionCannotNotify() const { return m_slots_ErrorsClass.m_kConditionCannotNotify; }
    REALLY_INLINE void setconst_kConditionCannotNotify(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kConditionCannotNotify = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kConditionCannotNotifyAll() const { return m_slots_ErrorsClass.m_kConditionCannotNotifyAll; }
    REALLY_INLINE void setconst_kConditionCannotNotifyAll(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kConditionCannotNotifyAll = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kConditionCannotWait() const { return m_slots_ErrorsClass.m_kConditionCannotWait; }
    REALLY_INLINE void setconst_kConditionCannotWait(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kConditionCannotWait = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kConditionCannotBeInitialized() const { return m_slots_ErrorsClass.m_kConditionCannotBeInitialized; }
    REALLY_INLINE void setconst_kConditionCannotBeInitialized(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kConditionCannotBeInitialized = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kMutexCannotBeInitialized() const { return m_slots_ErrorsClass.m_kMutexCannotBeInitialized; }
    REALLY_INLINE void setconst_kMutexCannotBeInitialized(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kMutexCannotBeInitialized = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kWorkerIllegalCallToStart() const { return m_slots_ErrorsClass.m_kWorkerIllegalCallToStart; }
    REALLY_INLINE void setconst_kWorkerIllegalCallToStart(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kWorkerIllegalCallToStart = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kInvalidParamError() const { return m_slots_ErrorsClass.m_kInvalidParamError; }
    REALLY_INLINE void setconst_kInvalidParamError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kInvalidParamError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kParamRangeError() const { return m_slots_ErrorsClass.m_kParamRangeError; }
    REALLY_INLINE void setconst_kParamRangeError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kParamRangeError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kNullPointerError() const { return m_slots_ErrorsClass.m_kNullPointerError; }
    REALLY_INLINE void setconst_kNullPointerError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kNullPointerError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kInvalidEnumError() const { return m_slots_ErrorsClass.m_kInvalidEnumError; }
    REALLY_INLINE void setconst_kInvalidEnumError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kInvalidEnumError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kCantInstantiateError() const { return m_slots_ErrorsClass.m_kCantInstantiateError; }
    REALLY_INLINE void setconst_kCantInstantiateError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kCantInstantiateError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kEOFError() const { return m_slots_ErrorsClass.m_kEOFError; }
    REALLY_INLINE void setconst_kEOFError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kEOFError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kCompressedDataError() const { return m_slots_ErrorsClass.m_kCompressedDataError; }
    REALLY_INLINE void setconst_kCompressedDataError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kCompressedDataError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kEmptyStringError() const { return m_slots_ErrorsClass.m_kEmptyStringError; }
    REALLY_INLINE void setconst_kEmptyStringError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kEmptyStringError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kProxyGetPropertyError() const { return m_slots_ErrorsClass.m_kProxyGetPropertyError; }
    REALLY_INLINE void setconst_kProxyGetPropertyError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kProxyGetPropertyError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kProxySetPropertyError() const { return m_slots_ErrorsClass.m_kProxySetPropertyError; }
    REALLY_INLINE void setconst_kProxySetPropertyError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kProxySetPropertyError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kProxyCallPropertyError() const { return m_slots_ErrorsClass.m_kProxyCallPropertyError; }
    REALLY_INLINE void setconst_kProxyCallPropertyError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kProxyCallPropertyError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kProxyHasPropertyError() const { return m_slots_ErrorsClass.m_kProxyHasPropertyError; }
    REALLY_INLINE void setconst_kProxyHasPropertyError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kProxyHasPropertyError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kProxyDeletePropertyError() const { return m_slots_ErrorsClass.m_kProxyDeletePropertyError; }
    REALLY_INLINE void setconst_kProxyDeletePropertyError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kProxyDeletePropertyError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kProxyGetDescendantsError() const { return m_slots_ErrorsClass.m_kProxyGetDescendantsError; }
    REALLY_INLINE void setconst_kProxyGetDescendantsError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kProxyGetDescendantsError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kProxyNextNameIndexError() const { return m_slots_ErrorsClass.m_kProxyNextNameIndexError; }
    REALLY_INLINE void setconst_kProxyNextNameIndexError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kProxyNextNameIndexError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kProxyNextNameError() const { return m_slots_ErrorsClass.m_kProxyNextNameError; }
    REALLY_INLINE void setconst_kProxyNextNameError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kProxyNextNameError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kProxyNextValueError() const { return m_slots_ErrorsClass.m_kProxyNextValueError; }
    REALLY_INLINE void setconst_kProxyNextValueError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kProxyNextValueError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kInvalidArrayLengthError() const { return m_slots_ErrorsClass.m_kInvalidArrayLengthError; }
    REALLY_INLINE void setconst_kInvalidArrayLengthError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kInvalidArrayLengthError = newVal; }
public:
    REALLY_INLINE avmplus::Atom get_kReadExternalNotImplementedError() const { return m_slots_ErrorsClass.m_kReadExternalNotImplementedError; }
    REALLY_INLINE void setconst_kReadExternalNotImplementedError(avmplus::Atom newVal) { m_slots_ErrorsClass.m_kReadExternalNotImplementedError = newVal; }
private:
    avmplus::NativeID::avmplus_ErrorsClassSlots m_slots_ErrorsClass;
protected:
    inline explicit ErrorsClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit ErrorsClass(const ErrorsClass&); // unimplemented
    void operator=(const ErrorsClass&); // unimplemented
};

#define avmplus_ErrorsClass_isExactInterlock 1
//-----------------------------------------------------------
// JSON
//-----------------------------------------------------------
class JSONObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::JSONClass;
    REALLY_INLINE explicit JSONObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit JSONObject(const JSONObject&); // unimplemented
    void operator=(const JSONObject&); // unimplemented
};

#define avmplus_JSONObject_isExactInterlock 1
//-----------------------------------------------------------
// Walker
//-----------------------------------------------------------
class WalkerObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    REALLY_INLINE avmplus::FunctionObject* get_reviver() const { return m_slots_WalkerObject.m_reviver; }
    REALLY_INLINE void set_reviver(avmplus::FunctionObject* newVal) { m_slots_WalkerObject.m_reviver = newVal; }
private:
    avmplus::NativeID::avmplus_WalkerObjectSlots m_slots_WalkerObject;
protected:
    friend class avmplus::WalkerClass;
    REALLY_INLINE explicit WalkerObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit WalkerObject(const WalkerObject&); // unimplemented
    void operator=(const WalkerObject&); // unimplemented
};

#define avmplus_WalkerObject_isExactInterlock 1
//-----------------------------------------------------------
// Walker$
//-----------------------------------------------------------
class WalkerClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::WalkerObject> constructObject(GCRef<avmplus::FunctionObject> arg1)
    {
        avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(1, args);
        return GCRef<avmplus::WalkerObject>((avmplus::WalkerObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::WalkerObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::WalkerObject>((avmplus::WalkerObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::WalkerObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::WalkerObject>((avmplus::WalkerObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::WalkerObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::WalkerObject>((avmplus::WalkerObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::WalkerObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::WalkerObject>((avmplus::WalkerObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit WalkerClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit WalkerClass(const WalkerClass&); // unimplemented
    void operator=(const WalkerClass&); // unimplemented
};

#define avmplus_WalkerClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.utils::IDataInput
//-----------------------------------------------------------
class IDataInputInterface : public avmplus::ScriptObject
{
public:
    inline uint32_t call_get_bytesAvailable()
    {
        PoolObject* pool = toplevel()->abcEnv()->pool();
        const avmplus::Multiname* const mn = pool->precomputedMultiname(1723);
        avmplus::Atom const result = this->toplevel()->getproperty(this->atom(), mn, this->vtable);
        return avmplus::AvmCore::toUInt32(result);
    }
    inline GCRef<avmplus::String> call_get_endian()
    {
        PoolObject* pool = toplevel()->abcEnv()->pool();
        const avmplus::Multiname* const mn = pool->precomputedMultiname(1726);
        avmplus::Atom const result = this->toplevel()->getproperty(this->atom(), mn, this->vtable);
        return GCRef<avmplus::String>(avmplus::AvmCore::atomToString(result));
    }
    inline uint32_t call_get_objectEncoding()
    {
        PoolObject* pool = toplevel()->abcEnv()->pool();
        const avmplus::Multiname* const mn = pool->precomputedMultiname(1725);
        avmplus::Atom const result = this->toplevel()->getproperty(this->atom(), mn, this->vtable);
        return avmplus::AvmCore::toUInt32(result);
    }
    inline bool call_readBoolean()
    {
        PoolObject* pool = toplevel()->abcEnv()->pool();
        const avmplus::Multiname* const mn = pool->precomputedMultiname(1711);
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->toplevel()->callproperty(this->atom(), mn, 0, args, this->vtable);
        return ((result) != avmplus::falseAtom);
    }
    inline int32_t call_readByte()
    {
        PoolObject* pool = toplevel()->abcEnv()->pool();
        const avmplus::Multiname* const mn = pool->precomputedMultiname(1712);
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->toplevel()->callproperty(this->atom(), mn, 0, args, this->vtable);
        return avmplus::AvmCore::integer(result);
    }
    inline void call_readBytes(GCRef<avmplus::ByteArrayObject> arg1, uint32_t arg2, uint32_t arg3)
    {
        avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core()));
        PoolObject* pool = toplevel()->abcEnv()->pool();
        const avmplus::Multiname* const mn = pool->precomputedMultiname(1710);
        avmplus::Atom args[4] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1.reinterpretCast<avmplus::ScriptObject>()->atom(), core->uintToAtom(arg2), core->uintToAtom(arg3) };
        avmplus::Atom const result = this->toplevel()->callproperty(this->atom(), mn, 3, args, this->vtable);
        AvmAssert(result == undefinedAtom); (void)result;
    }
    inline double call_readDouble()
    {
        PoolObject* pool = toplevel()->abcEnv()->pool();
        const avmplus::Multiname* const mn = pool->precomputedMultiname(1719);
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->toplevel()->callproperty(this->atom(), mn, 0, args, this->vtable);
        return avmplus::AvmCore::number(result);
    }
    inline double call_readFloat()
    {
        PoolObject* pool = toplevel()->abcEnv()->pool();
        const avmplus::Multiname* const mn = pool->precomputedMultiname(1718);
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->toplevel()->callproperty(this->atom(), mn, 0, args, this->vtable);
        return avmplus::AvmCore::number(result);
    }
    inline int32_t call_readInt()
    {
        PoolObject* pool = toplevel()->abcEnv()->pool();
        const avmplus::Multiname* const mn = pool->precomputedMultiname(1716);
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->toplevel()->callproperty(this->atom(), mn, 0, args, this->vtable);
        return avmplus::AvmCore::integer(result);
    }
    inline GCRef<avmplus::String> call_readMultiByte(uint32_t arg1, GCRef<avmplus::String> arg2)
    {
        avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core()));
        PoolObject* pool = toplevel()->abcEnv()->pool();
        const avmplus::Multiname* const mn = pool->precomputedMultiname(1720);
        avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->uintToAtom(arg1), arg2->atom() };
        avmplus::Atom const result = this->toplevel()->callproperty(this->atom(), mn, 2, args, this->vtable);
        return GCRef<avmplus::String>(avmplus::AvmCore::atomToString(result));
    }
    inline avmplus::Atom call_readObject()
    {
        PoolObject* pool = toplevel()->abcEnv()->pool();
        const avmplus::Multiname* const mn = pool->precomputedMultiname(1724);
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->toplevel()->callproperty(this->atom(), mn, 0, args, this->vtable);
        return result;
    }
    inline int32_t call_readShort()
    {
        PoolObject* pool = toplevel()->abcEnv()->pool();
        const avmplus::Multiname* const mn = pool->precomputedMultiname(1714);
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->toplevel()->callproperty(this->atom(), mn, 0, args, this->vtable);
        return avmplus::AvmCore::integer(result);
    }
    inline GCRef<avmplus::String> call_readUTF()
    {
        PoolObject* pool = toplevel()->abcEnv()->pool();
        const avmplus::Multiname* const mn = pool->precomputedMultiname(1721);
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->toplevel()->callproperty(this->atom(), mn, 0, args, this->vtable);
        return GCRef<avmplus::String>(avmplus::AvmCore::atomToString(result));
    }
    inline GCRef<avmplus::String> call_readUTFBytes(uint32_t arg1)
    {
        avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core()));
        PoolObject* pool = toplevel()->abcEnv()->pool();
        const avmplus::Multiname* const mn = pool->precomputedMultiname(1722);
        avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), core->uintToAtom(arg1) };
        avmplus::Atom const result = this->toplevel()->callproperty(this->atom(), mn, 1, args, this->vtable);
        return GCRef<avmplus::String>(avmplus::AvmCore::atomToString(result));
    }
    inline uint32_t call_readUnsignedByte()
    {
        PoolObject* pool = toplevel()->abcEnv()->pool();
        const avmplus::Multiname* const mn = pool->precomputedMultiname(1713);
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->toplevel()->callproperty(this->atom(), mn, 0, args, this->vtable);
        return avmplus::AvmCore::toUInt32(result);
    }
    inline uint32_t call_readUnsignedInt()
    {
        PoolObject* pool = toplevel()->abcEnv()->pool();
        const avmplus::Multiname* const mn = pool->precomputedMultiname(1717);
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->toplevel()->callproperty(this->atom(), mn, 0, args, this->vtable);
        return avmplus::AvmCore::toUInt32(result);
    }
    inline uint32_t call_readUnsignedShort()
    {
        PoolObject* pool = toplevel()->abcEnv()->pool();
        const avmplus::Multiname* const mn = pool->precomputedMultiname(1715);
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->toplevel()->callproperty(this->atom(), mn, 0, args, this->vtable);
        return avmplus::AvmCore::toUInt32(result);
    }
    inline void call_set_endian(GCRef<avmplus::String> arg1)
    {
        PoolObject* pool = toplevel()->abcEnv()->pool();
        const avmplus::Multiname* const mn = pool->precomputedMultiname(1726);
        this->toplevel()->setproperty(this->atom(), mn, arg1->atom(), this->vtable);
        avmplus::Atom const result = undefinedAtom;
        AvmAssert(result == undefinedAtom); (void)result;
    }
    inline void call_set_objectEncoding(uint32_t arg1)
    {
        avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core()));
        PoolObject* pool = toplevel()->abcEnv()->pool();
        const avmplus::Multiname* const mn = pool->precomputedMultiname(1725);
        this->toplevel()->setproperty(this->atom(), mn, core->uintToAtom(arg1), this->vtable);
        avmplus::Atom const result = undefinedAtom;
        AvmAssert(result == undefinedAtom); (void)result;
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::IDataInputClass;
    REALLY_INLINE explicit IDataInputInterface(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit IDataInputInterface(const IDataInputInterface&); // unimplemented
    void operator=(const IDataInputInterface&); // unimplemented
};

//-----------------------------------------------------------
// flash.utils::IDataInput$
//-----------------------------------------------------------
class IDataInputClass : public avmplus::ClassClosure
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
    REALLY_INLINE GCRef<avmplus::IDataInputInterface> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::IDataInputInterface>((avmplus::IDataInputInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IDataInputInterface> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::IDataInputInterface>((avmplus::IDataInputInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IDataInputInterface> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::IDataInputInterface>((avmplus::IDataInputInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IDataInputInterface> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::IDataInputInterface>((avmplus::IDataInputInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit IDataInputClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit IDataInputClass(const IDataInputClass&); // unimplemented
    void operator=(const IDataInputClass&); // unimplemented
};

//-----------------------------------------------------------
// flash.utils::IDataOutput
//-----------------------------------------------------------
class IDataOutputInterface : public avmplus::ScriptObject
{
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::IDataOutputClass;
    REALLY_INLINE explicit IDataOutputInterface(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit IDataOutputInterface(const IDataOutputInterface&); // unimplemented
    void operator=(const IDataOutputInterface&); // unimplemented
};

//-----------------------------------------------------------
// flash.utils::IDataOutput$
//-----------------------------------------------------------
class IDataOutputClass : public avmplus::ClassClosure
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
    REALLY_INLINE GCRef<avmplus::IDataOutputInterface> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::IDataOutputInterface>((avmplus::IDataOutputInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IDataOutputInterface> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::IDataOutputInterface>((avmplus::IDataOutputInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IDataOutputInterface> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::IDataOutputInterface>((avmplus::IDataOutputInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IDataOutputInterface> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::IDataOutputInterface>((avmplus::IDataOutputInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit IDataOutputClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit IDataOutputClass(const IDataOutputClass&); // unimplemented
    void operator=(const IDataOutputClass&); // unimplemented
};

//-----------------------------------------------------------
// flash.net::IDynamicPropertyOutput
//-----------------------------------------------------------
class IDynamicPropertyOutputInterface : public avmplus::ScriptObject
{
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::IDynamicPropertyOutputClass;
    REALLY_INLINE explicit IDynamicPropertyOutputInterface(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit IDynamicPropertyOutputInterface(const IDynamicPropertyOutputInterface&); // unimplemented
    void operator=(const IDynamicPropertyOutputInterface&); // unimplemented
};

//-----------------------------------------------------------
// flash.net::IDynamicPropertyOutput$
//-----------------------------------------------------------
class IDynamicPropertyOutputClass : public avmplus::ClassClosure
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
    REALLY_INLINE GCRef<avmplus::IDynamicPropertyOutputInterface> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::IDynamicPropertyOutputInterface>((avmplus::IDynamicPropertyOutputInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IDynamicPropertyOutputInterface> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::IDynamicPropertyOutputInterface>((avmplus::IDynamicPropertyOutputInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IDynamicPropertyOutputInterface> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::IDynamicPropertyOutputInterface>((avmplus::IDynamicPropertyOutputInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IDynamicPropertyOutputInterface> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::IDynamicPropertyOutputInterface>((avmplus::IDynamicPropertyOutputInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit IDynamicPropertyOutputClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit IDynamicPropertyOutputClass(const IDynamicPropertyOutputClass&); // unimplemented
    void operator=(const IDynamicPropertyOutputClass&); // unimplemented
};

//-----------------------------------------------------------
// flash.net::IDynamicPropertyWriter
//-----------------------------------------------------------
class IDynamicPropertyWriterInterface : public avmplus::ScriptObject
{
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::IDynamicPropertyWriterClass;
    REALLY_INLINE explicit IDynamicPropertyWriterInterface(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit IDynamicPropertyWriterInterface(const IDynamicPropertyWriterInterface&); // unimplemented
    void operator=(const IDynamicPropertyWriterInterface&); // unimplemented
};

//-----------------------------------------------------------
// flash.net::IDynamicPropertyWriter$
//-----------------------------------------------------------
class IDynamicPropertyWriterClass : public avmplus::ClassClosure
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
    REALLY_INLINE GCRef<avmplus::IDynamicPropertyWriterInterface> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::IDynamicPropertyWriterInterface>((avmplus::IDynamicPropertyWriterInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IDynamicPropertyWriterInterface> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::IDynamicPropertyWriterInterface>((avmplus::IDynamicPropertyWriterInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IDynamicPropertyWriterInterface> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::IDynamicPropertyWriterInterface>((avmplus::IDynamicPropertyWriterInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IDynamicPropertyWriterInterface> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::IDynamicPropertyWriterInterface>((avmplus::IDynamicPropertyWriterInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit IDynamicPropertyWriterClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit IDynamicPropertyWriterClass(const IDynamicPropertyWriterClass&); // unimplemented
    void operator=(const IDynamicPropertyWriterClass&); // unimplemented
};

//-----------------------------------------------------------
// flash.utils::IExternalizable
//-----------------------------------------------------------
class IExternalizableInterface : public avmplus::ScriptObject
{
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::IExternalizableClass;
    REALLY_INLINE explicit IExternalizableInterface(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit IExternalizableInterface(const IExternalizableInterface&); // unimplemented
    void operator=(const IExternalizableInterface&); // unimplemented
};

//-----------------------------------------------------------
// flash.utils::IExternalizable$
//-----------------------------------------------------------
class IExternalizableClass : public avmplus::ClassClosure
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
    REALLY_INLINE GCRef<avmplus::IExternalizableInterface> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::IExternalizableInterface>((avmplus::IExternalizableInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IExternalizableInterface> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::IExternalizableInterface>((avmplus::IExternalizableInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IExternalizableInterface> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::IExternalizableInterface>((avmplus::IExternalizableInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IExternalizableInterface> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::IExternalizableInterface>((avmplus::IExternalizableInterface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit IExternalizableClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit IExternalizableClass(const IExternalizableClass&); // unimplemented
    void operator=(const IExternalizableClass&); // unimplemented
};

//-----------------------------------------------------------
// flash.net::ObjectEncoding
//-----------------------------------------------------------
class ObjectEncodingObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::ObjectEncodingClass;
    REALLY_INLINE explicit ObjectEncodingObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit ObjectEncodingObject(const ObjectEncodingObject&); // unimplemented
    void operator=(const ObjectEncodingObject&); // unimplemented
};

#define avmplus_ObjectEncodingObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.errors::IOError
//-----------------------------------------------------------
class IOErrorObject : public avmplus::ErrorObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::IOErrorClass;
    REALLY_INLINE explicit IOErrorObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ErrorObject(ivtable, delegate) {}
private:
    explicit IOErrorObject(const IOErrorObject&); // unimplemented
    void operator=(const IOErrorObject&); // unimplemented
};

#define avmplus_IOErrorObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.errors::IOError$
//-----------------------------------------------------------
class IOErrorClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::IOErrorObject> constructObject(GCRef<avmplus::String> arg1, int32_t arg2)
    {
        avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core()));
        avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom(), core->intToAtom(arg2) };
        avmplus::Atom const result = this->construct(2, args);
        return GCRef<avmplus::IOErrorObject>((avmplus::IOErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::IOErrorObject> constructObject(GCRef<avmplus::String> arg1)
    {
        avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom() };
        avmplus::Atom const result = this->construct(1, args);
        return GCRef<avmplus::IOErrorObject>((avmplus::IOErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::IOErrorObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::IOErrorObject>((avmplus::IOErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::IOErrorObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::IOErrorObject>((avmplus::IOErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IOErrorObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::IOErrorObject>((avmplus::IOErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IOErrorObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::IOErrorObject>((avmplus::IOErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IOErrorObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::IOErrorObject>((avmplus::IOErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit IOErrorClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit IOErrorClass(const IOErrorClass&); // unimplemented
    void operator=(const IOErrorClass&); // unimplemented
};

#define avmplus_IOErrorClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.errors::MemoryError
//-----------------------------------------------------------
class MemoryErrorObject : public avmplus::ErrorObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::MemoryErrorClass;
    REALLY_INLINE explicit MemoryErrorObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ErrorObject(ivtable, delegate) {}
private:
    explicit MemoryErrorObject(const MemoryErrorObject&); // unimplemented
    void operator=(const MemoryErrorObject&); // unimplemented
};

#define avmplus_MemoryErrorObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.errors::MemoryError$
//-----------------------------------------------------------
class MemoryErrorClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::MemoryErrorObject> constructObject(GCRef<avmplus::String> arg1, int32_t arg2)
    {
        avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core()));
        avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom(), core->intToAtom(arg2) };
        avmplus::Atom const result = this->construct(2, args);
        return GCRef<avmplus::MemoryErrorObject>((avmplus::MemoryErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::MemoryErrorObject> constructObject(GCRef<avmplus::String> arg1)
    {
        avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom() };
        avmplus::Atom const result = this->construct(1, args);
        return GCRef<avmplus::MemoryErrorObject>((avmplus::MemoryErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::MemoryErrorObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::MemoryErrorObject>((avmplus::MemoryErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::MemoryErrorObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::MemoryErrorObject>((avmplus::MemoryErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::MemoryErrorObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::MemoryErrorObject>((avmplus::MemoryErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::MemoryErrorObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::MemoryErrorObject>((avmplus::MemoryErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::MemoryErrorObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::MemoryErrorObject>((avmplus::MemoryErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit MemoryErrorClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit MemoryErrorClass(const MemoryErrorClass&); // unimplemented
    void operator=(const MemoryErrorClass&); // unimplemented
};

#define avmplus_MemoryErrorClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.errors::IllegalOperationError
//-----------------------------------------------------------
class IllegalOperationErrorObject : public avmplus::ErrorObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::IllegalOperationErrorClass;
    REALLY_INLINE explicit IllegalOperationErrorObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ErrorObject(ivtable, delegate) {}
private:
    explicit IllegalOperationErrorObject(const IllegalOperationErrorObject&); // unimplemented
    void operator=(const IllegalOperationErrorObject&); // unimplemented
};

#define avmplus_IllegalOperationErrorObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.errors::IllegalOperationError$
//-----------------------------------------------------------
class IllegalOperationErrorClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::IllegalOperationErrorObject> constructObject(GCRef<avmplus::String> arg1, int32_t arg2)
    {
        avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core()));
        avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom(), core->intToAtom(arg2) };
        avmplus::Atom const result = this->construct(2, args);
        return GCRef<avmplus::IllegalOperationErrorObject>((avmplus::IllegalOperationErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::IllegalOperationErrorObject> constructObject(GCRef<avmplus::String> arg1)
    {
        avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom() };
        avmplus::Atom const result = this->construct(1, args);
        return GCRef<avmplus::IllegalOperationErrorObject>((avmplus::IllegalOperationErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::IllegalOperationErrorObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::IllegalOperationErrorObject>((avmplus::IllegalOperationErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::IllegalOperationErrorObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::IllegalOperationErrorObject>((avmplus::IllegalOperationErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IllegalOperationErrorObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::IllegalOperationErrorObject>((avmplus::IllegalOperationErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IllegalOperationErrorObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::IllegalOperationErrorObject>((avmplus::IllegalOperationErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IllegalOperationErrorObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::IllegalOperationErrorObject>((avmplus::IllegalOperationErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit IllegalOperationErrorClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit IllegalOperationErrorClass(const IllegalOperationErrorClass&); // unimplemented
    void operator=(const IllegalOperationErrorClass&); // unimplemented
};

#define avmplus_IllegalOperationErrorClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.errors::EOFError
//-----------------------------------------------------------
class EOFErrorObject : public avmplus::IOErrorObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::EOFErrorClass;
    REALLY_INLINE explicit EOFErrorObject(VTable* ivtable, ScriptObject* delegate) : avmplus::IOErrorObject(ivtable, delegate) {}
private:
    explicit EOFErrorObject(const EOFErrorObject&); // unimplemented
    void operator=(const EOFErrorObject&); // unimplemented
};

#define avmplus_EOFErrorObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.errors::EOFError$
//-----------------------------------------------------------
class EOFErrorClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::EOFErrorObject> constructObject(GCRef<avmplus::String> arg1, int32_t arg2)
    {
        avmplus::AvmCore* const core = ((avmplus::AvmCore*)(this->core()));
        avmplus::Atom args[3] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom(), core->intToAtom(arg2) };
        avmplus::Atom const result = this->construct(2, args);
        return GCRef<avmplus::EOFErrorObject>((avmplus::EOFErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::EOFErrorObject> constructObject(GCRef<avmplus::String> arg1)
    {
        avmplus::Atom args[2] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom(), arg1->atom() };
        avmplus::Atom const result = this->construct(1, args);
        return GCRef<avmplus::EOFErrorObject>((avmplus::EOFErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    inline GCRef<avmplus::EOFErrorObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::EOFErrorObject>((avmplus::EOFErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::EOFErrorObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::EOFErrorObject>((avmplus::EOFErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::EOFErrorObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::EOFErrorObject>((avmplus::EOFErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::EOFErrorObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::EOFErrorObject>((avmplus::EOFErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::EOFErrorObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::EOFErrorObject>((avmplus::EOFErrorObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit EOFErrorClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit EOFErrorClass(const EOFErrorClass&); // unimplemented
    void operator=(const EOFErrorClass&); // unimplemented
};

#define avmplus_EOFErrorClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.utils::CompressionAlgorithm
//-----------------------------------------------------------
class CompressionAlgorithmObject : public avmplus::ScriptObject
{
    GC_DECLARE_EXACT_METHODS
public:
    AvmThunk_DEBUG_ONLY( virtual avmplus::Atom construct(int argc, avmplus::Atom* argv); )
private:
    AvmThunk_DEBUG_ONLY( virtual void createInstance() { AvmAssert(0); } )
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::CompressionAlgorithmClass;
    REALLY_INLINE explicit CompressionAlgorithmObject(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit CompressionAlgorithmObject(const CompressionAlgorithmObject&); // unimplemented
    void operator=(const CompressionAlgorithmObject&); // unimplemented
};

#define avmplus_CompressionAlgorithmObject_isExactInterlock 1
//-----------------------------------------------------------
// flash.utils::CompressionAlgorithm$
//-----------------------------------------------------------
class CompressionAlgorithmClass : public avmplus::ClassClosure
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
    inline GCRef<avmplus::CompressionAlgorithmObject> constructObject()
    {
        avmplus::Atom args[1] = { thisRef.reinterpretCast<avmplus::ScriptObject>()->atom() };
        avmplus::Atom const result = this->construct(0, args);
        return GCRef<avmplus::CompressionAlgorithmObject>((avmplus::CompressionAlgorithmObject*)(avmplus::AvmCore::atomToScriptObject(result)));
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
    REALLY_INLINE GCRef<avmplus::CompressionAlgorithmObject> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::CompressionAlgorithmObject>((avmplus::CompressionAlgorithmObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::CompressionAlgorithmObject> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::CompressionAlgorithmObject>((avmplus::CompressionAlgorithmObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::CompressionAlgorithmObject> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::CompressionAlgorithmObject>((avmplus::CompressionAlgorithmObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::CompressionAlgorithmObject> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::CompressionAlgorithmObject>((avmplus::CompressionAlgorithmObject*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
public:
    REALLY_INLINE avmplus::String* get_ZLIB() const { return m_slots_CompressionAlgorithmClass.m_ZLIB; }
    REALLY_INLINE void setconst_ZLIB(avmplus::String* newVal) { m_slots_CompressionAlgorithmClass.m_ZLIB = newVal; }
public:
    REALLY_INLINE avmplus::String* get_DEFLATE() const { return m_slots_CompressionAlgorithmClass.m_DEFLATE; }
    REALLY_INLINE void setconst_DEFLATE(avmplus::String* newVal) { m_slots_CompressionAlgorithmClass.m_DEFLATE = newVal; }
public:
    REALLY_INLINE avmplus::String* get_LZMA() const { return m_slots_CompressionAlgorithmClass.m_LZMA; }
    REALLY_INLINE void setconst_LZMA(avmplus::String* newVal) { m_slots_CompressionAlgorithmClass.m_LZMA = newVal; }
private:
    avmplus::NativeID::avmplus_CompressionAlgorithmClassSlots m_slots_CompressionAlgorithmClass;
protected:
    inline explicit CompressionAlgorithmClass(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit CompressionAlgorithmClass(const CompressionAlgorithmClass&); // unimplemented
    void operator=(const CompressionAlgorithmClass&); // unimplemented
};

#define avmplus_CompressionAlgorithmClass_isExactInterlock 1
//-----------------------------------------------------------
// flash.utils::IDataInput2
//-----------------------------------------------------------
class IDataInput2Interface : public avmplus::ScriptObject
{
public:
    REALLY_INLINE GCRef<avmplus::IDataInputInterface> as_IDataInputInterface()
    {
        return GCRef<avmplus::IDataInputInterface>((avmplus::IDataInputInterface*)this);
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::IDataInput2Class;
    REALLY_INLINE explicit IDataInput2Interface(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit IDataInput2Interface(const IDataInput2Interface&); // unimplemented
    void operator=(const IDataInput2Interface&); // unimplemented
};

//-----------------------------------------------------------
// flash.utils::IDataInput2$
//-----------------------------------------------------------
class IDataInput2Class : public avmplus::ClassClosure
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
    REALLY_INLINE GCRef<avmplus::IDataInput2Interface> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::IDataInput2Interface>((avmplus::IDataInput2Interface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IDataInput2Interface> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::IDataInput2Interface>((avmplus::IDataInput2Interface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IDataInput2Interface> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::IDataInput2Interface>((avmplus::IDataInput2Interface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IDataInput2Interface> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::IDataInput2Interface>((avmplus::IDataInput2Interface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit IDataInput2Class(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit IDataInput2Class(const IDataInput2Class&); // unimplemented
    void operator=(const IDataInput2Class&); // unimplemented
};

//-----------------------------------------------------------
// flash.utils::IDataOutput2
//-----------------------------------------------------------
class IDataOutput2Interface : public avmplus::ScriptObject
{
public:
    REALLY_INLINE GCRef<avmplus::IDataOutputInterface> as_IDataOutputInterface()
    {
        return GCRef<avmplus::IDataOutputInterface>((avmplus::IDataOutputInterface*)this);
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    friend class avmplus::IDataOutput2Class;
    REALLY_INLINE explicit IDataOutput2Interface(VTable* ivtable, ScriptObject* delegate) : avmplus::ScriptObject(ivtable, delegate) {}
private:
    explicit IDataOutput2Interface(const IDataOutput2Interface&); // unimplemented
    void operator=(const IDataOutput2Interface&); // unimplemented
};

//-----------------------------------------------------------
// flash.utils::IDataOutput2$
//-----------------------------------------------------------
class IDataOutput2Class : public avmplus::ClassClosure
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
    REALLY_INLINE GCRef<avmplus::IDataOutput2Interface> asType(avmplus::Atom value)
    {
        avmplus::Atom const result = asTypeImpl(value);
        return GCRef<avmplus::IDataOutput2Interface>((avmplus::IDataOutput2Interface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IDataOutput2Interface> asType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = asTypeImpl(value->atom());
        return GCRef<avmplus::IDataOutput2Interface>((avmplus::IDataOutput2Interface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IDataOutput2Interface> coerceToType(avmplus::Atom value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value);
        return GCRef<avmplus::IDataOutput2Interface>((avmplus::IDataOutput2Interface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
    REALLY_INLINE GCRef<avmplus::IDataOutput2Interface> coerceToType(GCRef<avmplus::ScriptObject> value)
    {
        avmplus::Atom const result = coerceToTypeImpl(value->atom());
        return GCRef<avmplus::IDataOutput2Interface>((avmplus::IDataOutput2Interface*)(avmplus::AvmCore::atomToScriptObject(result)));
    }
private:
    friend class avmplus::NativeID::SlotOffsetsAndAsserts;
protected:
    inline explicit IDataOutput2Class(VTable* cvtable) : avmplus::ClassClosure(cvtable) { createVanillaPrototype(); }
private:
    explicit IDataOutput2Class(const IDataOutput2Class&); // unimplemented
    void operator=(const IDataOutput2Class&); // unimplemented
};

}

#endif // _H_nativegen_classes_builtin
