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
 * Portions created by the Initial Developer are Copyright (C) 1993-2006
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


#ifndef __avmplus_NativeFunction__
#define __avmplus_NativeFunction__

namespace avmplus
{
	typedef avmplus::AbcEnv* AvmInstance;
	typedef avmplus::ScriptObject* AvmObject;
	typedef avmplus::String* AvmString;
	typedef avmplus::Namespace* AvmNamespace;
	typedef avmplus::Atom AvmBox;
	typedef avmplus::MethodEnv* AvmMethodEnv;
	typedef int32_t AvmBool32;

	#define kAvmThunkNull		nullObjectAtom
	#define kAvmThunkUndefined	undefinedAtom

	#define kAvmThunkInfinity		(MathUtils::infinity())
	#define kAvmThunkNegInfinity	(MathUtils::neg_infinity())
	#define kAvmThunkNaN			(MathUtils::nan())
	
	typedef AvmObject		AvmRetType_AvmObject;
	typedef bool			AvmRetType_AvmBool32;	// bools are passed in as int32, but returned as bool, for historic reasons
	typedef int32_t			AvmRetType_int32_t;
	typedef uint32_t		AvmRetType_uint32_t;
	typedef AvmNamespace	AvmRetType_AvmNamespace;
	typedef AvmBox			AvmRetType_AvmBox;
	typedef AvmString		AvmRetType_AvmString;
	typedef void			AvmRetType_void;
	typedef double			AvmRetType_double;

	typedef avmplus::ScriptObject AvmObjectT;
	typedef avmplus::String AvmStringT;
	typedef avmplus::Namespace AvmNamespaceT;

	typedef AvmBox (*AvmThunkNativeThunker)(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
	typedef void (ScriptObject::*AvmThunkNativeHandler)();

	#define AvmThunkUnbox_AvmObject(r)		((ScriptObject*)(r))
	#define AvmThunkUnbox_AvmBool32(r)		((r) != 0)
	#define AvmThunkUnbox_int32_t(r)		int32_t(r)
	#define AvmThunkUnbox_uint32_t(r)		uint32_t(r)
	#define AvmThunkUnbox_AvmNamespace(r)	((Namespace*)(r))
	#define AvmThunkUnbox_AvmBox(r)			(r)
	#define AvmThunkUnbox_AvmString(r)		((String*)(r))
	#define AvmThunkUnbox_void(r)			(error ??? illegal)
	#define AvmThunkUnbox_double(r)			AvmThunkUnbox_double_impl(&(r))

	#define AvmThunkArgSize_AvmObject		1
	#define AvmThunkArgSize_AvmBool32		1
	#define AvmThunkArgSize_int32_t			1
	#define AvmThunkArgSize_uint32_t		1
	#define AvmThunkArgSize_AvmNamespace	1
	#define AvmThunkArgSize_AvmBox			1
	#define AvmThunkArgSize_AvmString		1
	#define AvmThunkArgSize_void			(error ??? illegal)
#ifdef AVMPLUS_64BIT
	#define AvmThunkArgSize_double			1
#else
	#define AvmThunkArgSize_double			2
#endif

	inline double AvmThunkUnbox_double_impl(const AvmBox* b)
	{
	#if defined(AVMPLUS_64BIT)
		AvmAssert(sizeof(AvmBox) == sizeof(double));
		return *(const double*)b;
	#elif defined(AVMPLUS_UNALIGNED_ACCESS)
		AvmAssert(sizeof(AvmBox)*2 == sizeof(double));
		return *(const double*)b;
	#else
		AvmAssert(sizeof(AvmBox)*2 == sizeof(double));
		union {
			double d;
			AvmBox b[2];
		} u;
		// @todo, does this need endian attention?
		u.b[0] = b[0];
		u.b[1] = b[1];
		return u.d;
	#endif
	}

	// trick, since values are compile-time known we usually don't need to call intToAtom, can statically transform them
	// good for ints and ints currently
	#define AvmThunkCanBeSmallIntAtom(v)	(!((v) & 0xF0000000))
	#define AvmThunkSmallIntAtom(v)			((((Atom)(v))<<3) | kIntegerType)
		
	// note, this isn't complete -- only the ones currently needed are defined.
	// expand as necessary. macros to take advantage of the fact that most
	// args are compile-time constants.
	#define AvmThunkCoerce_int32_t_double(v)	double(v)
	#define AvmThunkCoerce_int32_t_uint32_t(v)	uint32_t(v)
	#define AvmThunkCoerce_int32_t_AvmBox(v)	(AvmThunkCanBeSmallIntAtom(v) ? AvmThunkSmallIntAtom(v) : env->core()->intAtom(v))

	#define AvmThunkCoerce_uint32_t_double(v)	double(v)
	#define AvmThunkCoerce_uint32_t_int32_t(v)	int32_t(v)
	#define AvmThunkCoerce_uint32_t_AvmBox(v)	(AvmThunkCanBeSmallIntAtom(v) ? AvmThunkSmallIntAtom(v) : env->core()->intAtom(v))

	#define AvmThunkCoerce_AvmBool32_AvmBox(v)	((v) ? trueAtom : falseAtom)

#ifdef _DEBUG
	inline double AvmThunkCoerce_AvmBox_double(AvmBox v) { AvmAssert((v) == kAvmThunkUndefined); (void)v; return kAvmThunkNaN; }
	inline AvmString AvmThunkCoerce_AvmBox_AvmString(AvmBox v) { AvmAssert((v) == kAvmThunkUndefined || (v) == kAvmThunkNull); (void)v; return NULL; }
	inline AvmObject AvmThunkCoerce_AvmBox_AvmObject(AvmBox v) { AvmAssert((v) == kAvmThunkUndefined || (v) == kAvmThunkNull); (void)v; return NULL; }
#else
	#define AvmThunkCoerce_AvmBox_double(v)		(kAvmThunkNaN)
	#define AvmThunkCoerce_AvmBox_AvmString(v)	(NULL)
	#define AvmThunkCoerce_AvmBox_AvmObject(v)	(NULL)
#endif

	#define AvmThunkCoerce_AvmString_AvmBox(v)	((v) ? (v)->atom() : nullStringAtom)

	#define AvmThunkConstant_AvmString(v)		(env->method->pool->cpool_string[v])
	
	#define AVMTHUNK_GET_HANDLER(env)	(static_cast<NativeMethod*>((env)->method)->handler)
#ifdef AVMPLUS_LEGACY_NATIVE_MAPS
	#define AVMTHUNK_GET_COOKIE(env)	(static_cast<NativeMethod*>((env)->method)->cookie)
#endif

#ifdef DEBUGGER
	#define AVMTHUNK_DEBUG_ENTER(env)	CallStackNode csn(CallStackNode::kEmpty); (env)->debugEnter(argc, (uint32_t*)argv, 0, 0, &csn, 0, 0); 
	#define AVMTHUNK_DEBUG_EXIT(env)	(env)->debugExit(&csn);
#else
	#define AVMTHUNK_DEBUG_ENTER(env)	
	#define AVMTHUNK_DEBUG_EXIT(env)	
#endif

	struct NativeMethodInfo
	{
	public:
		AvmThunkNativeHandler handler;
		AvmThunkNativeThunker thunker;
#ifndef AVMPLUS_NO_STATIC_POINTERS
		int32_t method_id;
#endif
#ifdef AVMPLUS_LEGACY_NATIVE_MAPS
		int32_t cookie;
		int32_t flags;
#endif
	};

    struct NativeScriptInfo
	{
	public:
		CreateGlobalObjectProc createGlobalObject;
#ifdef AVMPLUS_LEGACY_NATIVE_MAPS
		const NativeMethodInfo* nativeMap;
#endif
#ifndef AVMPLUS_NO_STATIC_POINTERS
		int32_t script_id;
#endif
		uint32_t sizeofInstance;
	};

	struct NativeClassInfo
	{
	public:
		CreateClassClosureProc createClassClosure;
#ifdef AVMPLUS_LEGACY_NATIVE_MAPS
		const NativeMethodInfo* nativeMap;
#endif
#ifndef AVMPLUS_NO_STATIC_POINTERS
		int32_t class_id;
#endif
		uint32_t sizeofClass;
		uint32_t sizeofInstance;
	};


	class NativeMethod : public AbstractFunction
	{
	public:
		NativeMethod(AvmThunkNativeThunker thunker, AvmThunkNativeHandler handler);
		virtual ~NativeMethod() {}
		static Atom verifyEnter(MethodEnv* env, int argc, uint32 *ap);
		virtual void verify(Toplevel* toplevel);

	// ------------------------ DATA SECTION BEGIN
	public:
		AvmThunkNativeThunker thunker;
		AvmThunkNativeHandler handler;
#ifdef AVMPLUS_LEGACY_NATIVE_MAPS
		int32_t cookie;
#endif
	// ------------------------ DATA SECTION END
	};

	// ---------------

	class NativeInitializer
	{
	public:
		NativeInitializer(AvmCore* core, 
			const uint8_t* abcData,
			uint32_t abcDataLen,
			uint32_t methodCount,
			uint32_t classCount,
			uint32_t scriptCount);

		~NativeInitializer();

		PoolObject* parseBuiltinABC(const List<Stringp, LIST_RCObjects>* includes = NULL);

		NativeMethod* newNativeMethod(uint32_t i) const;
	
		#ifdef AVMPLUS_NO_STATIC_POINTERS
			typedef void (*FillInProc)(NativeMethodInfo* m, NativeClassInfo* c, NativeScriptInfo* s);
			void fillIn(FillInProc p);
			inline const NativeClassInfo* get_class(uint32_t i) const { AvmAssert(i < classCount); return &classes[i]; }
			inline const NativeScriptInfo* get_script(uint32_t i) const { AvmAssert(i < scriptCount); return &scripts[i]; }
		#else
			void fillInMethods(const NativeMethodInfo* methodEntry);
			void fillInClasses(const NativeClassInfo* classEntry);
			void fillInScripts(const NativeScriptInfo* scriptEntry);
			inline const NativeClassInfo* get_class(uint32_t i) const { AvmAssert(i < classCount); return classes[i]; }
			inline const NativeScriptInfo* get_script(uint32_t i) const { AvmAssert(i < scriptCount); return scripts[i]; }
		#endif
		
	private:
		#ifdef AVMPLUS_NO_STATIC_POINTERS
			typedef NativeMethodInfo MethodType;
			typedef NativeClassInfo ClassType;
			typedef NativeScriptInfo ScriptType;
			inline const NativeMethodInfo* get_method(uint32_t i) const { AvmAssert(i < methodCount); return &methods[i]; }
		#else
			typedef const NativeMethodInfo* MethodType;
			typedef const NativeClassInfo* ClassType;
			typedef const NativeScriptInfo* ScriptType;
			inline const NativeMethodInfo* get_method(uint32_t i) const { AvmAssert(i < methodCount); return methods[i]; }
		#endif

	private:
		AvmCore* const			core;
		const uint8_t* const	abcData;
		uint32_t const			abcDataLen;
		MethodType* const		methods;
		ClassType* const		classes;
		ScriptType* const		scripts;
		const uint32_t			methodCount;
		const uint32_t			classCount;
		const uint32_t			scriptCount;
	};

	#define _NATIVE_METHOD_CAST_PTR(CLS, PTR) \
		reinterpret_cast<AvmThunkNativeHandler>((void(CLS::*)())(PTR))

	#define AVMTHUNK_NATIVE_SCRIPT_GLUE(SCRIPTCLS) \
		static ScriptObject* SCRIPTCLS##_createGlobalObject(VTable* vtable, ScriptObject* delegate) \
		{ return new (vtable->gc(), vtable->getExtraSize()) SCRIPTCLS(vtable, delegate); } 

	#define AVMTHUNK_NATIVE_CLASS_GLUE(CLS) \
		static ClassClosure* CLS##_createClassClosure(VTable* cvtable) \
		{ return new (cvtable->gc(), cvtable->getExtraSize()) CLS(cvtable); } 

	#define AVMTHUNK_DECLARE_NATIVE_INITIALIZER(NAME) \
		extern PoolObject* initBuiltinABC_##NAME(AvmCore* core, const List<Stringp, LIST_RCObjects>* includes);

#ifdef AVMPLUS_NO_STATIC_POINTERS

	#define AVMTHUNK_BEGIN_NATIVE_TABLES(NAME) \
		static void fillIn_##NAME(NativeMethodInfo* m, NativeClassInfo* c, NativeScriptInfo* s) { 

	#define AVMTHUNK_END_NATIVE_TABLES() \
		}
	
	// ---------------

	#define AVMTHUNK_BEGIN_NATIVE_METHODS(NAME) 

	#define _AVMTHUNK_NATIVE_METHOD(CLS, METHID, IMPL) \
		m[METHID].handler = _NATIVE_METHOD_CAST_PTR(CLS, &IMPL); \
		m[METHID].thunker = (AvmThunkNativeThunker)avmplus::NativeID::METHID##_thunk; 

	#define AVMTHUNK_NATIVE_METHOD(METHID, IMPL) \
		_AVMTHUNK_NATIVE_METHOD(ScriptObject, METHID, IMPL)

	#define AVMTHUNK_NATIVE_METHOD_STRING(METHID, IMPL) \
		_AVMTHUNK_NATIVE_METHOD(avmplus::String, METHID, IMPL)

	#define AVMTHUNK_NATIVE_METHOD_NAMESPACE(METHID, IMPL) \
		_AVMTHUNK_NATIVE_METHOD(avmplus::Namespace, METHID, IMPL)

	#define AVMTHUNK_END_NATIVE_METHODS() 

	// ---------------

	#define AVMTHUNK_BEGIN_NATIVE_SCRIPTS(NAME) 

	#define AVMTHUNK_NATIVE_SCRIPT(SCRIPTID, SCRIPTCLS) \
		s[SCRIPTID].createGlobalObject = (CreateGlobalObjectProc)SCRIPTCLS##_createGlobalObject; \
		s[SCRIPTID].sizeofInstance = sizeof(SCRIPTCLS); 

	#define AVMTHUNK_END_NATIVE_SCRIPTS() 

	// ---------------

	#define AVMTHUNK_BEGIN_NATIVE_CLASSES(NAME) 

	#define AVMTHUNK_NATIVE_CLASS(CLSID, CLS, INST) \
		c[CLSID].createClassClosure = (CreateClassClosureProc)CLS##_createClassClosure; \
		c[CLSID].sizeofClass = sizeof(CLS); \
		c[CLSID].sizeofInstance = sizeof(INST); 

	#define AVMTHUNK_END_NATIVE_CLASSES() 

	#define AVMTHUNK_DEFINE_NATIVE_INITIALIZER(NAME) \
		PoolObject* initBuiltinABC_##NAME(AvmCore* core, const List<Stringp, LIST_RCObjects>* includes) { \
			NativeInitializer ninit(core, \
				avmplus::NativeID::NAME##_abc_data, \
				avmplus::NativeID::NAME##_abc_length, \
				avmplus::NativeID::NAME##_abc_method_count, \
				avmplus::NativeID::NAME##_abc_class_count, \
				avmplus::NativeID::NAME##_abc_script_count); \
			ninit.fillIn(fillIn_##NAME); \
			return ninit.parseBuiltinABC(includes); \
		}

#else

	#define AVMTHUNK_BEGIN_NATIVE_TABLES(NAME)
	#define AVMTHUNK_END_NATIVE_TABLES()
	
	// ---------------

	#define AVMTHUNK_BEGIN_NATIVE_METHODS(NAME) \
		static const NativeMethodInfo NAME##_methodEntries[] = {
			
	#ifdef AVMPLUS_LEGACY_NATIVE_MAPS
		#define _EXTRA_METHOD(COOKIE,FLAGS) ,COOKIE,FLAGS
	#else
		#define _EXTRA_METHOD(COOKIE,FLAGS) 
	#endif

	#define _AVMTHUNK_NATIVE_METHOD(CLS, METHID, IMPL) \
		{ _NATIVE_METHOD_CAST_PTR(CLS, &IMPL), (AvmThunkNativeThunker)avmplus::NativeID::METHID##_thunk, avmplus::NativeID::METHID _EXTRA_METHOD(0, AbstractFunction::NEEDS_CODECONTEXT | AbstractFunction::NEEDS_DXNS) },

	#define AVMTHUNK_NATIVE_METHOD(METHID, IMPL) \
		_AVMTHUNK_NATIVE_METHOD(ScriptObject, METHID, IMPL)

	#define AVMTHUNK_NATIVE_METHOD_STRING(METHID, IMPL) \
		_AVMTHUNK_NATIVE_METHOD(avmplus::String, METHID, IMPL)

	#define AVMTHUNK_NATIVE_METHOD_NAMESPACE(METHID, IMPL) \
		_AVMTHUNK_NATIVE_METHOD(avmplus::Namespace, METHID, IMPL)

	#define AVMTHUNK_END_NATIVE_METHODS() \
		{ NULL, NULL, -1 _EXTRA_METHOD(0,0) } };

	// ---------------

	#define AVMTHUNK_BEGIN_NATIVE_SCRIPTS(NAME) \
		const avmplus::NativeScriptInfo NAME##_scriptEntries[] = {

	#ifdef AVMPLUS_LEGACY_NATIVE_MAPS
		#define _EXTRA_SCRIPT(MAP) MAP,
	#else
		#define _EXTRA_SCRIPT(MAP) 
	#endif

	#define AVMTHUNK_NATIVE_SCRIPT(SCRIPTID, SCRIPTCLS) \
		{ (CreateGlobalObjectProc)SCRIPTCLS##_createGlobalObject, _EXTRA_SCRIPT(NULL) SCRIPTID, sizeof(SCRIPTCLS) },

	#define AVMTHUNK_END_NATIVE_SCRIPTS() \
		{ NULL, _EXTRA_SCRIPT(NULL) -1, 0 } };

	// ---------------

	#define AVMTHUNK_BEGIN_NATIVE_CLASSES(NAME) \
		const NativeClassInfo NAME##_classEntries[] = {

	#ifdef AVMPLUS_LEGACY_NATIVE_MAPS
		#define _EXTRA_CLASS(MAP) MAP,
	#else
		#define _EXTRA_CLASS(MAP) 
	#endif

	#define AVMTHUNK_NATIVE_CLASS(CLSID, CLS, INST) \
		{ (CreateClassClosureProc)CLS##_createClassClosure, _EXTRA_CLASS(NULL) avmplus::NativeID::CLSID, sizeof(CLS), sizeof(INST) },

	#define AVMTHUNK_END_NATIVE_CLASSES() \
		{ NULL, _EXTRA_CLASS(NULL) -1, 0, 0 } };

	#define AVMTHUNK_DEFINE_NATIVE_INITIALIZER(NAME) \
		PoolObject* initBuiltinABC_##NAME(AvmCore* core, const List<Stringp, LIST_RCObjects>* includes) { \
			NativeInitializer ninit(core, \
				avmplus::NativeID::NAME##_abc_data, \
				avmplus::NativeID::NAME##_abc_length, \
				avmplus::NativeID::NAME##_abc_method_count, \
				avmplus::NativeID::NAME##_abc_class_count, \
				avmplus::NativeID::NAME##_abc_script_count); \
			ninit.fillInScripts(NAME##_scriptEntries); \
			ninit.fillInClasses(NAME##_classEntries); \
			ninit.fillInMethods(NAME##_methodEntries); \
			return ninit.parseBuiltinABC(includes); \
		}

#endif // AVMPLUS_NO_STATIC_POINTERS

	#define AVM_INIT_BUILTIN_ABC(MAPNAME, CORE, INCLUDES) \
		avmplus::NativeID::initBuiltinABC_##MAPNAME((CORE), (INCLUDES))

#ifdef AVMPLUS_LEGACY_NATIVE_MAPS

	#ifdef AVMPLUS_NO_STATIC_POINTERS
		#error "AVMPLUS_LEGACY_NATIVE_MAPS cannot be used in conjunction with AVMPLUS_NO_STATIC_POINTERS"
	#endif

	#define DECLARE_NATIVE_SCRIPTS()			/* nothing */
	#define DECLARE_NATIVE_CLASSES()			/* nothing */

	#define BEGIN_NATIVE_SCRIPTS(CLS) \
		const avmplus::NativeScriptInfo CLS##_scriptEntries[] = {

	#define NATIVE_SCRIPT(SCRIPTID, SCRIPTCLS) \
		{ (CreateGlobalObjectProc)SCRIPTCLS::createGlobalObject, SCRIPTCLS::natives, SCRIPTID, sizeof(SCRIPTCLS) },

	#define END_NATIVE_SCRIPTS() \
		{ NULL, NULL, -1, 0 } };
	
	#define BEGIN_NATIVE_CLASSES(CLS) \
		const NativeClassInfo CLS##_classEntries[] = {

	#define NATIVE_CLASS(CLSID, CLS, INST) \
		{ (CreateClassClosureProc)CLS::createClassClosure, CLS::natives, avmplus::NativeID::CLSID, sizeof(CLS), sizeof(INST) },

	#define END_NATIVE_CLASSES() \
		{ NULL, NULL, -1, 0, 0 } };

	#define BEGIN_NATIVE_MAP(CLS) \
		/*static*/ const NativeMethodInfo CLS::natives[] = {
		
	#define _NATIVE_METHOD_CAST_PTR(CLS, PTR) \
		reinterpret_cast<AvmThunkNativeHandler>((void(CLS::*)())(PTR))

	#define _NATIVE_METHOD(METHID, IMPL, fl) \
		{ _NATIVE_METHOD_CAST_PTR(ScriptObject, &IMPL), (AvmThunkNativeThunker)avmplus::NativeID::METHID##_thunk, avmplus::NativeID::METHID, 0, fl },

	#define _NATIVE_METHOD1(METHID, IMPL, fl, cookie) \
		{ _NATIVE_METHOD_CAST_PTR(ScriptObject, &IMPL), (AvmThunkNativeThunker)avmplus::NativeID::METHID##_thunkc, avmplus::NativeID::METHID, cookie, fl | AbstractFunction::NATIVE_COOKIE },

	#define NATIVE_METHOD(METHID, IMPL) \
		_NATIVE_METHOD(METHID, IMPL, AbstractFunction::NEEDS_CODECONTEXT | AbstractFunction::NEEDS_DXNS)
		
	#define NATIVE_METHOD_FLAGS(METHID, IMPL, fl) \
		_NATIVE_METHOD(METHID, IMPL, fl)

	#define NATIVE_METHOD1(METHID, IMPL, cookie) \
		_NATIVE_METHOD1(METHID, IMPL, AbstractFunction::NEEDS_CODECONTEXT | AbstractFunction::NEEDS_DXNS, cookie)
		
	#define NATIVE_METHOD1_FLAGS(METHID, IMPL, cookie, fl) \
		_NATIVE_METHOD1(METHID, IMPL, fl, cookie)

	#define END_NATIVE_MAP() \
		{ NULL, NULL, -1, 0, 0 } };

	#define DECLARE_NATIVE_MAP(_Class) \
		static ClassClosure* createClassClosure(VTable* cvtable) \
		{ return new (cvtable->gc(), cvtable->getExtraSize()) _Class(cvtable); } \
		static const NativeMethodInfo natives[];

	#define DECLARE_NATIVE_SCRIPT(_Script) \
		static ScriptObject* createGlobalObject(VTable* vtable, ScriptObject* delegate) \
		{ return new (vtable->gc(), vtable->getExtraSize()) _Script(vtable, delegate); } \
		static const NativeMethodInfo natives[];

	#define DECLARE_EXTERN_NATIVE_MAPS(MAPNAME) \
		extern const NativeScriptInfo MAPNAME##_scriptEntries[]; \
		extern const NativeClassInfo MAPNAME##_classEntries[]; 

	#define DECLARE_NATIVE_INITIALIZER(NAME, MAPNAME) \
		extern PoolObject* initBuiltinABC_##MAPNAME(AvmCore* core, const List<Stringp, LIST_RCObjects>* includes);

	#define DEFINE_NATIVE_INITIALIZER(NAME, MAPNAME) \
		PoolObject* initBuiltinABC_##MAPNAME(AvmCore* core, const List<Stringp, LIST_RCObjects>* includes) { \
			NativeInitializer ninit(core, \
				avmplus::NativeID::NAME##_abc_data, \
				avmplus::NativeID::NAME##_abc_length, \
				avmplus::NativeID::NAME##_abc_method_count, \
				avmplus::NativeID::NAME##_abc_class_count, \
				avmplus::NativeID::NAME##_abc_script_count); \
			ninit.fillInScripts(MAPNAME##_scriptEntries); \
			ninit.fillInClasses(MAPNAME##_classEntries); \
			ninit.fillInScripts(NAME##_scriptEntries); \
			ninit.fillInClasses(NAME##_classEntries); \
			ninit.fillInMethods(NAME##_methodEntries); \
			return ninit.parseBuiltinABC(includes); \
		}

#endif // AVMPLUS_LEGACY_NATIVE_MAPS

}	

#endif /* __avmplus_NativeFunction__ */
