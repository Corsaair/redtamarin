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
 * Portions created by the Initial Developer are Copyright (C) 2004-2006
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

#ifndef __avmplus_CallStackNode__
#define __avmplus_CallStackNode__

namespace avmplus
{
#ifdef FEATURE_SAMPLER
	/**
	 * The CallStackNode class tracks the call stack of executing
	 * ActionScript code.  It is used for debugger stack dumps
	 * and also to keep track of the security contexts of
	 * running code.  There is a master CallStackNode object on
	 * AvmCore, which is maintained by MethodInfo::enter as
	 * methods enter and exit.
	 *
	 * A single CallStackNode object represents a level of the
	 * call stack.  It tracks the currently executing method,
	 * and the source file and line number if debug info
	 * is available.
	 *
	 * CallStackNode objects get strung together into linked
	 * lists to represent a full call stack.  Entering a
	 * method adds a new element to core->stackTrace's
	 * linked list; exiting a method removes it.
	 *
	 * As OP_debugfile and OP_debugline opcodes are encountered,
	 * the file and line number information in the current
	 * CallStackNode object is updated.
	 *
	 * CallStackNode objects are "semi-immutable."  The file
	 * and line number information can be updated until someone
	 * wants to snapshot the CallStackNode.  To snapshot, the
	 * "freeze" method is called.  This freezes the entire
	 * linked list.  Once a CallStackNode is frozen, it cannot
	 * be directly modified... a clone must be made of it,
	 * and then the clone can be modified.
	 *
	 * The "semi-immutable" aspect is to support AVM+ heap
	 * profiling.  Every ScriptObject will point to the
	 * CallStackNode at time of allocation, so that the developer
	 * can figure out the call stack where an object was
	 * created.  The semi-immutability makes it possible to
	 * conserve memory, by having many ScriptObjects point to
	 * the same CallStackNode chain, or chains containing common
	 * CallStackNode elements.
	 */
	class CallStackNode
	{
	public:

		void init(MethodEnv*				env
			#ifdef DEBUGGER
					, Atom*					framep
					, Traits**				frameTraits
					, int					argc
					, void*				    ap
					, intptr_t volatile*	eip
					, int32_t volatile*		scopeDepth
				    , bool                  boxed
			#endif
				);

		void init(AvmCore* core, Stringp name);

		/**
		 * Constructs a new CallStackNode.  The method executing and
		 * the CallStackNode representing the previous call stack
		 * must be specified.  The source file and line number
		 * will be unset, initially.
		 * @param info the currently executing method
		 * @param next the CallStackNode representing the previous
		 *             call stack
		 * @param  ap  the arguments pointer.  This is an Atom* if
		 *             'boxed' is true, and an uint32_t* otherwise.
		 */
		inline explicit CallStackNode(MethodEnv*				env
								#ifdef DEBUGGER
										, Atom*					framep
										, Traits**				frameTraits
										, int					argc
										, void*					ap
										, intptr_t volatile*	eip
										, int32_t volatile*		scopeDepth
									    , bool                  boxed = false
								#endif
								)
		{
		#ifdef DEBUGGER
			init(env, framep, frameTraits, argc, ap, eip, scopeDepth, boxed);
		#else
			init(env);
		#endif
		}

	#ifdef FEATURE_SAMPLER
		// ctor used only for Sampling (no MethodEnv)
		inline explicit CallStackNode(AvmCore* core, const char* name)
		{
			init(core, core ? core->sampler()->getFakeFunctionName(name) : NULL);
		}
	#endif

	#ifdef DEBUGGER
		// ctor used only for verify (no MethodEnv)
		inline explicit CallStackNode(AvmCore* core, Stringp name)
		{
			init(core, name);
		}
	#endif

		// dummy ctor we can use to construct an uninitalized version -- useful for the thunks, which
		// will construct one and immediately call initialize (via debugEnter) so there's no need to
		// redundantly fill in fields.
		enum Empty { kEmpty = 0 };
		inline explicit CallStackNode(Empty) { }

		~CallStackNode();

		// Does exactly what the destructor does, but on an arbitrary object.
		void reset();
		
		void sampleCheck() { if (m_core) m_core->sampler()->sampleCheck(); }

#ifdef DEBUGGER
		void** scopeBase(); // with MIR, array members are (ScriptObject*); with interpreter, they are (Atom).
#endif

		void exit();

		inline CallStackNode* next() const { return m_next; }
		// WARNING, env() can return null if there are fake Sampler-only frames. You must always check for null.
		inline MethodEnv* env() const { return m_env; }
		// WARNING, info() can return null if there are fake Sampler-only frames. You must always check for null.
		inline AbstractFunction* info() const { return m_env ? m_env->method : NULL; }
		inline Stringp envname() const { return m_envname; }
		inline int32_t depth() const { return m_depth; }

#ifdef DEBUGGER
		inline intptr_t volatile* eip() const { return m_eip; }
		inline Stringp filename() const { return m_filename; }
		inline Atom* framep() const { return m_framep; }
		inline Traits** traits() const { return m_traits; }
		inline const uint32_t* ap() const { AvmAssert(!m_boxed); return m_ap; }
		inline const Atom* atomv() const { AvmAssert(m_boxed); return m_atomv; }
		inline const int32_t volatile* scopeDepth() const { return m_scopeDepth; }
		inline int argc() const { return m_argc; }
		inline int32_t linenum() const { return m_linenum; }
		inline bool boxed() const { return m_boxed; }

		inline void set_filename(Stringp s) { m_filename = s; }
		inline void set_linenum(int32_t i) { m_linenum = i; }
		inline void set_framep(Atom* fp) { m_framep = fp; }
#endif

		// Placement new and delete because the interpreter allocates CallStackNode
		// instances inside other data structures (think alloca storage that has been
		// allocated on the heap).
		//
		// The delete operator is required by some compilers in builds that compile with
		// exceptions enabled, but is never actually called.
		
		inline void* operator new(size_t, void* storage) { return storage; }
		inline void operator delete(void*) {}

	// ------------------------ DATA SECTION BEGIN
	private:	AvmCore*			m_core;
	private:	MethodEnv*			m_env;			// will be NULL if the element is from a fake CallStackNode
	private:	CallStackNode*		m_next;
	private:	Stringp				m_envname;		// same as m_env->method->name (except for fake CallStackNode)
	private:	int32_t				m_depth;
	#ifdef DEBUGGER
	private:	intptr_t volatile*	m_eip;			// ptr to where the current pc is stored
	private:	Stringp				m_filename;		// in the form "C:\path\to\package\root;package/package;filename"
	private:	Atom*				m_framep;		// pointer to top of AS registers
	private:	Traits**			m_traits;		// array of traits for AS registers
	private:	union {
					uint32_t*		m_ap;			// unboxed args, iff boxed == false
					Atom*			m_atomv;		// boxed args, iff boxed == true
				};
	private:	int32_t volatile*	m_scopeDepth;	// Only used by the interpreter! With MIR, look for NULL entires in the scopeBase array.
	private:	int32_t				m_argc;
	private:	int32_t				m_linenum;
	private:	bool				m_boxed;
	#endif
	// ------------------------ DATA SECTION END
	};

	class StackTrace : public MMgc::GCObject
	{
	public:
		Stringp format(AvmCore* core);

		/**
		 * The dump and format methods display a human-readable
		 * version of the stack trace.  To avoid thousands of
		 * lines of output, such as would happen in an infinite
		 * recursion, no more than kMaxDisplayDepth levels will
		 * be displayed.
		 */
		const static int kMaxDisplayDepth = 64;

		int depth;
		DRCWB(Stringp) stringRep;

		struct Element
		{
			AbstractFunction*	m_info;			// will be null for fake CallStackNode
			Stringp				m_name;			// same as m_info->name (except for fake CallStackNode)
			Stringp				m_filename;		// in the form "C:\path\to\package\root;package/package;filename"
		    int32_t				m_linenum;
		#ifdef AVMPLUS_64BIT
			int32_t				m_pad;
		#endif

			inline void set(const CallStackNode& csn) 
			{ 
				m_info		= csn.info();		// will be NULL if the element is from a fake CallStackNode
				m_name		= csn.envname();
			#ifdef DEBUGGER
				m_filename	= csn.filename();
				m_linenum	= csn.linenum();
			#else
				m_filename	= 0;
				m_linenum	= 0;
			#endif
			#ifdef AVMPLUS_64BIT
				m_pad		= 0;	// let's keep the stack nice and clean
			#endif
			}
			// WARNING, env() can return null if there are fake Sampler-only frames. You must always check for null.
			inline AbstractFunction* info() const { return m_info; }
			inline Stringp infoname() const { return m_name; }
			inline Stringp filename() const { return m_filename; }
			inline int32_t linenum() const { return m_linenum; }
		};
		bool equals(StackTrace::Element* e, int depth);
		static uintptr_t hashCode(StackTrace::Element* e, int depth);

		Element elements[1];
	private:
		void dumpFilename(Stringp filename, PrintWriter& out) const;
	};
		
#endif /* FEATURE_SAMPLER */
}

#endif /* __avmplus_CallStackNode__ */
