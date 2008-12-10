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
 * The Original Code is [Open Source Virtual Machine.].
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


#define SIG1(r,a1) (nanojit::ARGSIZE_##r | nanojit::ARGSIZE_##a1<<2)
#define SIG2(r,a2,a1) (SIG1(r,a1) | nanojit::ARGSIZE_##a2<<4)
#define SIG3(r,a3,a2,a1) (SIG2(r,a2,a1) | nanojit::ARGSIZE_##a3<<6)
#define SIG4(r,a4,a3,a2,a1) (SIG3(r,a3,a2,a1) | nanojit::ARGSIZE_##a4<<8)
#define SIG5(r,a5,a4,a3,a2,a1) (SIG4(r,a4,a3,a2,a1) | nanojit::ARGSIZE_##a5<<10)
#define SIG6(r,a6,a5,a4,a3,a2,a1) (SIG5(r,a5,a4,a3,a2,a1) | nanojit::ARGSIZE_##a6<<12)
#define SIG7(r,a7,a6,a5,a4,a3,a2,a1) (SIG6(r,a6,a5,a4,a3,a2,a1) | nanojit::ARGSIZE_##a7<<14)
#define SIG8(r,a8,a7,a6,a5,a4,a3,a2,a1) (SIG7(r,a7,a6,a5,a4,a3,a2,a1) | nanojit::ARGSIZE_##a8<<16)

#define FUNCTIONID(n) &ci_##n

#ifdef NJ_VERBOSE
    #define DEFINE_CALLINFO(f,sig,cse,fold,abi,name) \
        static const CallInfo ci_##name = { f, sig, cse, fold, abi, #name };
#else
    #define DEFINE_CALLINFO(f,sig,cse,fold,abi,name) \
        static const CallInfo ci_##name = { f, sig, cse, fold, abi };
#endif

#define D_I   SIG1(F,LO)
#define D_D   SIG1(F,F)
#define I_I   SIG1(LO,LO)
#define I_D   SIG1(LO,F)
#define I_DD  SIG2(LO,F,F)
#define D_DD  SIG2(F,F,F)
#define I_II  SIG2(LO,LO,LO)
#define D_II  SIG2(F,LO,LO)
#define I_ID  SIG2(LO,LO,F)
#define I_III SIG3(LO,LO,LO,LO)
#define I_IID SIG3(LO,LO,LO,F)
#define I_IDI SIG3(LO,LO,F,LO)
#define D_III SIG3(F,LO,LO,LO)
#define I_I4  SIG4(LO,LO,LO,LO,LO)
#define D_I4  SIG4(F,LO,LO,LO,LO)
#define I_I5  SIG5(LO,LO,LO,LO,LO,LO)
#define I_I6  SIG6(LO,LO,LO,LO,LO,LO,LO)
#define I_I7  SIG7(LO,LO,LO,LO,LO,LO,LO,LO)
#define I_I8  SIG8(LO,LO,LO,LO,LO,LO,LO,LO,LO)

#if _MSC_VER
	#define ABI_FUNCTION ABI_CDECL
	#define ABI_METHOD   ABI_THISCALL
#else
	// gcc, probably
	#define ABI_FUNCTION ABI_CDECL
	#define ABI_METHOD   ABI_CDECL
#endif

#define FUNCTION(f, sig, name) \
    DEFINE_CALLINFO(f,sig,0,0,ABI_FUNCTION,name)
#define CSEFUNCTION(f, sig, name) \
    DEFINE_CALLINFO(f,sig,1,0,ABI_FUNCTION,name)

#define METHOD(f, sig, name) \
    DEFINE_CALLINFO(f,sig,0,0,ABI_METHOD,name)
#define CSEMETHOD(f, sig, name) \
    DEFINE_CALLINFO(f,sig,1,0,ABI_METHOD,name)

    FUNCTION(CALL_INDIRECT, I_III, calli)
    FUNCTION(FCALL_INDIRECT, D_III, fcalli)
    FUNCTION(CALL_IMT, I_I4, callimt)
    FUNCTION(FCALL_IMT, D_I4, fcallimt)

    METHOD(ENVADDR(MethodEnv::newActivation), I_I, newActivation)
    METHOD(ENVADDR(MethodEnv::newcatch), I_II, newcatch)
    METHOD(ENVADDR(MethodEnv::newfunction), I_I4, newfunction)
    METHOD(TOPLEVELADDR(Toplevel::op_call), I_I4, op_call)
    METHOD(TOPLEVELADDR(Toplevel::callproperty), I_I6, callproperty)
    CSEMETHOD(TOPLEVELADDR(Toplevel::coerce), I_III, coerce)
    METHOD(ENVADDR(MethodEnv::npe), I_I, npe)
    METHOD(ENVADDR(MethodEnv::interrupt), I_I, interrupt)
    METHOD(ENVADDR(MethodEnv::nextname), I_III, nextname)
    METHOD(ENVADDR(MethodEnv::nextvalue), I_III, nextvalue)
    METHOD(ENVADDR(MethodEnv::hasnext), I_III, hasnext)
    METHOD(COREADDR(AvmCore::coerce_s), I_II, coerce_s)
    METHOD(COREADDR(AvmCore::string), I_II, string)
    METHOD(TOPLEVELADDR(Toplevel::coerceobj), I_III, coerceobj)
    METHOD(ENVADDR(MethodEnv::coerceAtom2SO), I_III, coerceAtom2SO)
    CSEMETHOD(COREADDR(AvmCore::doubleToString), I_ID, doubleToString)
    CSEMETHOD(COREADDR(AvmCore::uintToString), I_II, uintToString) 
    CSEMETHOD(COREADDR(AvmCore::intToString), I_II, intToString) 
    CSEMETHOD(COREADDR(AvmCore::doubleToAtom), I_ID, doubleToAtom)
    CSEMETHOD(COREADDR(AvmCore::boolean), I_II, boolean)
    CSEMETHOD(COREADDR(AvmCore::toUInt32), I_II, toUInt32)
    CSEFUNCTION(FUNCADDR(AVMCORE_integer_d), I_D, integer_d)
    CSEFUNCTION(FUNCADDR(AVMCORE_integer_i), I_I, integer_i)
    CSEFUNCTION(FUNCADDR(AvmCore::number_d), D_I, number_d)
    CSEFUNCTION(FUNCADDR(AvmCore::integer_u), I_I, integer_u)
    CSEMETHOD(COREADDR(AVMCORE_integer), I_II, integer)
    CSEMETHOD(COREADDR(AvmCore::number), D_II, number)
    METHOD(ENVADDR(MethodEnv::hasnextproto), I_III, hasnextproto)
    METHOD(ENVADDR(MethodEnv::nullcheck), I_II, nullcheck)
    CSEMETHOD(TOPLEVELADDR(Toplevel::toVTable), I_II, toVTable)
    METHOD(TOPLEVELADDR(Toplevel::setproperty), I_I5, setproperty)
    METHOD(ENVADDR(MethodEnv::initproperty), I_I5, initproperty)
    METHOD(COREADDR(AvmCore::newPublicNamespace), I_II, newPublicNamespace)
    METHOD(COREADDR(AvmCore::intern), I_II, intern)
    METHOD(COREADDR(AvmCore::istypeAtom), I_III, istypeAtom)
    CSEMETHOD(TOPLEVELADDR(Toplevel::toClassITraits), I_II, toClassITraits)
    METHOD(TOPLEVELADDR(Toplevel::in_operator), I_III, in)
    METHOD(TOPLEVELADDR(Toplevel::instanceof), I_III, instanceof)
    CSEMETHOD(COREADDR(AvmCore::stricteq), I_III, stricteq)
    METHOD(COREADDR(AvmCore::equals), I_III, equals)
    CSEMETHOD(COREADDR(AvmCore::concatStrings), I_III, concatStrings)
    METHOD(TOPLEVELADDR(Toplevel::add2), I_III, add2)
    CSEMETHOD(COREADDR(AvmCore::astype), I_III, astype)
    CSEMETHOD(COREADDR(AvmCore::EscapeAttributeValue), I_II, EscapeAttributeValue)
    CSEMETHOD(COREADDR(AvmCore::ToXMLString), I_II, ToXMLString)
    METHOD(ENVADDR(MethodEnv::delpropertyHelper), I_I4, delpropertyHelper)
    METHOD(ENVADDR(MethodEnv::internRtns), I_II, internRtns)
    METHOD(ENVADDR(MethodEnv::delproperty), I_III, delproperty)
    METHOD(ENVADDR(MethodEnv::setpropertyHelper), I_I6, setpropertyHelper)
    METHOD(ENVADDR(MethodEnv::initpropertyHelper), I_I6, initpropertyHelper)
    METHOD(ENVADDR(MethodEnv::setpropertylate_u), I_I4, setpropertylate_u)
    METHOD(VECTORDOUBLEADDR(DoubleVectorObject::_setUintProperty), I_III, DoubleVectorObject_setUintProperty)
    METHOD(VECTORDOUBLEADDR(DoubleVectorObject::_setNativeUintProperty), I_IID, DoubleVectorObject_setNativeUintProperty)
    METHOD(VECTORINTADDR(IntVectorObject::_setUintProperty), I_III, IntVectorObject_setUintProperty)
    METHOD(VECTORUINTADDR(UIntVectorObject::_setUintProperty), I_III, UIntVectorObject_setUintProperty)
    METHOD(VECTORINTADDR(IntVectorObject::_setNativeUintProperty), I_III, IntVectorObject_setNativeUintProperty)
    METHOD(VECTORUINTADDR(UIntVectorObject::_setNativeUintProperty), I_III, UIntVectorObject_setNativeUintProperty)
    METHOD(ARRAYADDR(ArrayObject::_setUintProperty), I_III, ArrayObject_setUintProperty)
    METHOD(VECTOROBJADDR(ObjectVectorObject::_setUintProperty), I_III, ObjectVectorObject_setUintProperty)
    METHOD(ENVADDR(MethodEnv::setpropertylate_i), I_I4, setpropertylate_i)
    METHOD(VECTORDOUBLEADDR(DoubleVectorObject::_setIntProperty), I_III, DoubleVectorObject_setIntProperty)
    METHOD(VECTORDOUBLEADDR(DoubleVectorObject::_setNativeIntProperty), I_IID, DoubleVectorObject_setNativeIntProperty)
    METHOD(VECTORINTADDR(IntVectorObject::_setIntProperty), I_III, IntVectorObject_setIntProperty)
    METHOD(VECTORUINTADDR(UIntVectorObject::_setIntProperty), I_III, UIntVectorObject_setIntProperty)
    METHOD(VECTORINTADDR(IntVectorObject::_setNativeIntProperty), I_III, IntVectorObject_setNativeIntProperty)
    METHOD(VECTORUINTADDR(UIntVectorObject::_setNativeIntProperty), I_III, UIntVectorObject_setNativeIntProperty)
    METHOD(ARRAYADDR(ArrayObject::_setIntProperty), I_III, ArrayObject_setIntProperty)
    METHOD(VECTOROBJADDR(ObjectVectorObject::_setIntProperty), I_III, ObjectVectorObject_setIntProperty)
    METHOD(TOPLEVELADDR(Toplevel::getproperty), I_I4, getproperty)
    METHOD(ENVADDR(MethodEnv::getpropertyHelper), I_I5, getpropertyHelper)
    METHOD(ENVADDR(MethodEnv::getpropertylate_u), I_III, getpropertylate_u)
    METHOD(VECTORDOUBLEADDR(DoubleVectorObject::_getUintProperty), I_II, DoubleVectorObject_getUintProperty)
    METHOD(VECTORDOUBLEADDR(DoubleVectorObject::_getNativeUintProperty), D_II, DoubleVectorObject_getNativeUintProperty)
    METHOD(VECTORINTADDR(IntVectorObject::_getUintProperty), I_II, IntVectorObject_getUintProperty)
    METHOD(VECTORUINTADDR(UIntVectorObject::_getUintProperty), I_II, UIntVectorObject_getUintProperty)
    METHOD(VECTORINTADDR(IntVectorObject::_getNativeUintProperty), I_II, IntVectorObject_getNativeUintProperty)
    METHOD(VECTORUINTADDR(UIntVectorObject::_getNativeUintProperty), I_II, UIntVectorObject_getNativeUintProperty)
    METHOD(ARRAYADDR(ArrayObject::_getUintProperty), I_II, ArrayObject_getUintProperty)
    METHOD(VECTOROBJADDR(ObjectVectorObject::_getUintProperty), I_II, ObjectVectorObject_getUintProperty)
    METHOD(ENVADDR(MethodEnv::getpropertylate_i), I_III, getpropertylate_i)
    METHOD(VECTORDOUBLEADDR(DoubleVectorObject::_getIntProperty), I_II, DoubleVectorObject_getIntProperty)
    METHOD(VECTORDOUBLEADDR(DoubleVectorObject::_getNativeIntProperty), D_II, DoubleVectorObject_getNativeIntProperty)
    METHOD(VECTORINTADDR(IntVectorObject::_getIntProperty), I_II, IntVectorObject_getIntProperty)
    METHOD(VECTORUINTADDR(UIntVectorObject::_getIntProperty), I_II, UIntVectorObject_getIntProperty)
    METHOD(VECTORINTADDR(IntVectorObject::_getNativeIntProperty), I_II, IntVectorObject_getNativeIntProperty)
    METHOD(VECTORUINTADDR(UIntVectorObject::_getNativeIntProperty), I_II, UIntVectorObject_getNativeIntProperty)
    METHOD(ARRAYADDR(ArrayObject::_getIntProperty), I_II, ArrayObject_getIntProperty)
    METHOD(VECTOROBJADDR(ObjectVectorObject::_getIntProperty), I_II, ObjectVectorObject_getIntProperty)
    CSEMETHOD(ENVADDR(MethodEnv::finddefNs), I_III, finddefNs)
    CSEMETHOD(ENVADDR(MethodEnv::finddefNsset), I_III, finddefNsset)
    METHOD(ENVADDR(MethodEnv::findproperty), I_I7, findproperty)
    METHOD(ENVADDR(MethodEnv::checkfilter), I_II, checkfilter)
    METHOD(ENVADDR(MethodEnv::getdescendants), I_III, getdescendants)
    METHOD(ENVADDR(MethodEnv::newclass), I_I5, newclass)
    METHOD(SCRIPTADDR(ArrayClass::newarray), I_III, newarray)
    METHOD(ENVADDR(MethodEnv::op_newobject), I_III, op_newobject)
    METHOD(TOPLEVELADDR(Toplevel::op_applytype), I_I4, op_applytype)
    METHOD(TOPLEVELADDR(Toplevel::op_construct), I_I4, op_construct)
    METHOD(ENVADDR(MethodEnv::callsuper), I_I4, callsuper)
    METHOD(TOPLEVELADDR(Toplevel::constructprop), I_I5, constructprop)
    METHOD(ENVADDR(MethodEnv::setsuper), I_I4, setsuper)
    METHOD(ENVADDR(MethodEnv::getsuper), I_III, getsuper)
    METHOD(COREADDR(AvmCore::throwAtom), I_II, throwAtom)
    CSEFUNCTION(FUNCADDR(MathUtils::mod), D_DD, mod)
    CSEMETHOD(COREADDR(AvmCore::_typeof), I_II, typeof)
    FUNCTION(FUNCADDR(AvmCore::atomWriteBarrier), I_I4, atomWriteBarrier)
    METHOD(GCADDR(GC::writeBarrierRC), I_I4, writeBarrierRC)
    CSEMETHOD(COREADDR(AvmCore::uintToAtom), I_II, uintToAtom)
    CSEMETHOD(COREADDR(AvmCore::intToAtom), I_II, intToAtom)
    METHOD(COREADDR(AvmCore::compare), I_III, compare)
    CSEMETHOD(ENVADDR(MethodEnv::createRestHelper), I_III, createRestHelper)
    CSEMETHOD(ENVADDR(MethodEnv::createArgumentsHelper), I_III, createArgumentsHelper)
    METHOD(COREADDR(AvmCore::initMultinameLate), I_III, initMultinameLate)
    METHOD(ENVADDR(MethodEnv::initMultinameLateForDelete), I_III, initMultinameLateForDelete)
    CSEFUNCTION(FUNCADDR(MathUtils::doubleToBool), I_D, doubleToBool)
    METHOD(CLASSCLOSUREADDR(ClassClosure::newInstance), I_I, newInstance)
    METHOD(ENVADDR(MethodEnv::stkover), I_I, stkover)

    METHOD(EFADDR(ExceptionFrame::endTry), I_I, endTry)
    METHOD(EFADDR(ExceptionFrame::beginTry), I_II, beginTry)
    FUNCTION(SETJMP, I_II, fsetjmp)
    METHOD(COREADDR(AvmCore::beginCatch), I_I5, beginCatch)

SSE2_ONLY(
    CSEMETHOD(COREADDR(AvmCore::doubleToAtom_sse2), I_ID, doubleToAtom_sse2)
    CSEFUNCTION(FUNCADDR(AvmCore::integer_d_sse2), I_D, integer_d_sse2)
)

#ifdef DEBUGGER
    METHOD(ENVADDR(MethodEnv::debugEnter), I_I8, debugEnter)
    METHOD(ENVADDR(MethodEnv::debugExit), I_II, debugExit)
    METHOD(DEBUGGERADDR(Debugger::debugFile), I_II, debugFile)
    METHOD(DEBUGGERADDR(Debugger::debugLine), I_II, debugLine)
    METHOD(COREADDR(AvmCore::sampleCheck), I_I, sampleCheck)
#endif

#ifdef AVMPLUS_MOPS
    METHOD(ENVADDR(MethodEnv::li8), I_II, li8)
    METHOD(ENVADDR(MethodEnv::li16), I_II, li16)
    METHOD(ENVADDR(MethodEnv::li32), I_II, li32)
    METHOD(ENVADDR(MethodEnv::lf32), D_II, lf32)
    METHOD(ENVADDR(MethodEnv::lf64), D_II, lf64)
    METHOD(ENVADDR(MethodEnv::si8), I_III, si8)
    METHOD(ENVADDR(MethodEnv::si16), I_III, si16)
    METHOD(ENVADDR(MethodEnv::si32), I_III, si32)
    METHOD(ENVADDR(MethodEnv::sf32), I_IDI, sf32)
    METHOD(ENVADDR(MethodEnv::sf64), I_IDI, sf64)
#endif
