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
 *   leon.sha@sun.com
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


#include "avmplus.h"

#ifdef AVMPLUS_MIR

#include "CodegenMIR.h"
#include "../core/FrameState.h"

#ifdef DARWIN
    #if defined(AVMPLUS_MAC_CARBON)
		#include <Carbon/Carbon.h>
	#endif
#endif

#if defined(WIN32) && defined(AVMPLUS_ARM)
#include <cmnintrin.h>
#endif

#ifdef _MSC_VER
#if !defined (AVMPLUS_ARM)
extern "C"
{
	int __cdecl _setjmp3(jmp_buf jmpbuf, int arg);
}
#else
//!!@WindowsMobile..can't get setjmp to link
extern "C"
{
	int __cdecl _setjmp3(jmp_buf jmpbuf, int arg)
	{
		(void) jmpbuf;
		(void) arg;
		return 0;
	}
}
#include <setjmp.h>
jmp_buf buf;
#endif // AVMPLUS_ARM
#endif // _MSC_VER

#ifdef AVMPLUS_ARM
#ifdef _MSC_VER
#define RETURN_METHOD_PTR(_class, _method) \
return *((int*)&_method);
#else
#define RETURN_METHOD_PTR(_class, _method) \
union { \
    int (_class::*bar)(); \
    int foo[2]; \
}; \
bar = _method; \
return foo[1];
#endif

#elif defined AVMPLUS_MAC
#if !TARGET_RT_MAC_MACHO
// CodeWarrior makes us jump through some hoops
// to dereference pointer->method...
// Convert pointer->method to integer for Carbon.
#define RETURN_METHOD_PTR(_class, _method) \
int foo; \
asm("lwz %0,0(r5)" : "=r" (foo)); \
return foo;
#else
#define RETURN_METHOD_PTR(_class, _method) \
union { \
    int (_class::*bar)(); \
    sintptr foo; \
}; \
bar = _method; \
return foo;
#endif

#else
#define RETURN_METHOD_PTR(_class, _method) \
return *((sintptr*)&_method);
#endif

// VOID variant
#ifdef AVMPLUS_ARM
#ifdef _MSC_VER
#define RETURN_VOID_METHOD_PTR(_class, _method) \
return *((int*)&_method);
#else
#define RETURN_VOID_METHOD_PTR(_class, _method) \
union { \
    void (_class::*bar)(); \
    int foo[2]; \
}; \
bar = _method; \
return foo[1];
#endif

#elif defined AVMPLUS_MAC
#if !TARGET_RT_MAC_MACHO
// CodeWarrior makes us jump through some hoops
// to dereference pointer->method...
// Convert pointer->method to integer for Carbon.
#define RETURN_VOID_METHOD_PTR(_class, _method) \
int foo; \
asm("lwz %0,0(r5)" : "=r" (foo)); \
return foo;
#else
#define RETURN_VOID_METHOD_PTR(_class, _method) \
union { \
    void (_class::*bar)(); \
    sintptr foo; \
}; \
bar = _method; \
return foo;
#endif

#else
#define RETURN_VOID_METHOD_PTR(_class, _method) \
return *((sintptr*)&_method);
#endif

#ifdef AVMPLUS_SPARC
extern  "C"
{
	void sync_instruction_memory(caddr_t v, u_int len);
}
#endif

#ifdef PERFM
#include "../vprof/vprof.h"
#endif /* PERFM */

#ifdef AVMPLUS_64BIT
#define AVMCORE_integer			AvmCore::integer64
#define AVMCORE_integer_i		AvmCore::integer64_i
#define AVMCORE_integer_d		AvmCore::integer64_d
#define AVMCORE_integer_d_sse2	AvmCore::integer64_d_sse2
#else
#define AVMCORE_integer			AvmCore::integer
#define AVMCORE_integer_i		AvmCore::integer_i
#define AVMCORE_integer_d		AvmCore::integer_d
#define AVMCORE_integer_d_sse2	AvmCore::integer_d_sse2
#endif
namespace avmplus
{
	#ifdef VTUNE
       extern void VTune_RegisterMethod(AvmCore* core, JITCodeInfo* inf); 
	#endif  // VTUNE

		sintptr CodegenMIR::coreAddr( int (AvmCore::*f)() )
		{
			RETURN_METHOD_PTR(AvmCore, f);
		}

		sintptr CodegenMIR::gcAddr( int (MMgc::GC::*f)() )
		{
			RETURN_METHOD_PTR(MMgc::GC, f);
		}
		
		sintptr CodegenMIR::envAddr( int (MethodEnv::*f)() )
		{
			RETURN_METHOD_PTR(MethodEnv, f);
		}

		sintptr CodegenMIR::toplevelAddr( int (Toplevel::*f)() )
		{
			RETURN_METHOD_PTR(Toplevel, f);
		}

	#ifdef DEBUGGER
		sintptr CodegenMIR::debuggerAddr( int (Debugger::*f)() )
		{
			RETURN_METHOD_PTR(Debugger, f);
		}		
	#endif /* DEBUGGER */

		sintptr CodegenMIR::scriptAddr(int (ScriptObject::*f)())
		{
			RETURN_METHOD_PTR(ScriptObject, f);
		}

		sintptr CodegenMIR::arrayAddr(int (ArrayObject::*f)())
		{
			RETURN_METHOD_PTR(ArrayObject, f);
		}

		sintptr CodegenMIR::vectorIntAddr(int (IntVectorObject::*f)())
		{
			RETURN_METHOD_PTR(IntVectorObject, f);
		}

		sintptr CodegenMIR::vectorUIntAddr(int (UIntVectorObject::*f)())
		{
			RETURN_METHOD_PTR(UIntVectorObject, f);
		}

		sintptr CodegenMIR::vectorDoubleAddr(int (DoubleVectorObject::*f)())
		{
			RETURN_METHOD_PTR(DoubleVectorObject, f);
		}

		sintptr CodegenMIR::vectorObjAddr(int (ObjectVectorObject::*f)())
		{
			RETURN_METHOD_PTR(ObjectVectorObject, f);
		}
		sintptr CodegenMIR::efAddr( int (ExceptionFrame::*f)() )
		{
			RETURN_METHOD_PTR(ExceptionFrame, f);
		}
	
		sintptr CodegenMIR::classClosureAddr(int (ClassClosure::*f)())
		{
			RETURN_METHOD_PTR(ClassClosure, f);
		}

	using namespace MMgc;
	#ifdef AVMPLUS_MIR

	#ifdef AVMPLUS_SYMBIAN
	static const int mir_buffer_reserve_size =	1*1024*1024;	// 2MB
	#else
	static const int mir_buffer_reserve_size =	32*1024*1024;	// 32MB
	#endif
	static const int mir_buffer_size_min	 =	1024*1024;		// 1MB

	#ifdef AVMPLUS_AMD64
	static const int prologue_size = 65536; 
	#else
	static const int prologue_size = 32768; //3840;
	#endif
	static const int epilogue_size = 208;

	#ifndef AVMPLUS_MAC
		#define FUNCADDR(addr) (uintptr)addr
	#else
		#if TARGET_RT_MAC_MACHO
			#define FUNCADDR(addr) (uintptr)addr
		#else
			#define FUNCADDR(addr) (*((uintptr*)addr))	
		#endif
	#endif

#ifdef AVMPLUS_VERBOSE
#ifndef AVMPLUS_SYMBIAN
	const char *mirNames[CodegenMIR::MIR_last];
#endif
#endif /* AVMPLUS_VERBOSE */

	#if defined(_MSC_VER) && !defined(AVMPLUS_ARM)
	#define SETJMP ((uintptr)_setjmp3)
	#else
		#ifdef AVMPLUS_MAC_CARBON
			#define SETJMP setjmpAddress
		#else
			#ifdef UNDER_CE
			//!!@WindowsMobile
				#define SETJMP ((uintptr)_setjmp3)
			#else
				#define SETJMP ((uintptr)setjmp)
			#endif
		#endif
	#endif /* _MSC_VER */



	/**
	 * 3 instruction formats 
	 *
	 *  format 1  : oprnd1 = 0 and value = imm32
	 *  format 2  : oprnd1 = ptr | imm8 and value = imm32 (conditional branches oprnd1 = ptr [MIR_cm / MIR_cs / MIR_fcm / MIR_fcs] oprnd1 = imm8)
	 *  format 3  : oprnd1 = ptr  oprnd2 / oprnd3 are optional ptr (only MIR_st should use oprnd3)
	 */

	// format 1
	OP* CodegenMIR::Ins(MirOpcode code, uintptr v)
	{
		OP* ip = this->ip;
#ifndef FEATURE_BUFFER_GUARD
		if (checkOverflow())
			return ip;
#endif /* FEATURE_BUFFER_GUARD */

		AvmAssert(code < MIR_last);
		OP* o = 0;

		if (core->config.cseopt && (code & MIR_oper))
			o = cseMatch(code, 0, (OP*) v);

		if (o == 0)
		{
			ip->code = code;
			ip->oprnd1 = 0; // not used
			ip->imm = v;
			ip->lastUse = 0;
			//ip->prevcse = 0;
			ip->liveAcrossCall = 0;
			ip->reg = Unknown;
#ifdef AVMPLUS_VERBOSE
			if (verbose())
			{
				core->console << "       @"<< InsNbr(ip)<<"\t";
				formatOpcode(core->console, ip, pool, core->codegenMethodNames);
				core->console <<"\n";
			}
#endif /* AVMPLUS_VERBOSE */
			o = ip++;
			ip->prevcse = 0;
			this->ip = ip;
		}
		return o;
	}

	// format 2
	OP* CodegenMIR::Ins(MirOpcode code, OP* a1, uintptr v2)
	{
		OP* ip = this->ip;
#ifndef FEATURE_BUFFER_GUARD
		if (checkOverflow())
			return ip;
#endif /* FEATURE_BUFFER_GUARD */

		AvmAssert(code < MIR_last);
		OP* o = 0;

#ifdef AVMPLUS_64BIT
		if (core->config.cseopt && ((code & MIR_oper) || (code&~MIR_float)==MIR_ld || (code&~MIR_float)==MIR_ld32 || (code&~MIR_float)==MIR_ld32u
#else
		if (core->config.cseopt && ((code & MIR_oper) || (code&~MIR_float)==MIR_ld
#endif
#if HAVE_MIR_SMOPS
			|| (code&~MIR_float)==MIR_sld
#endif
                             ))
			o = cseMatch(code, a1, (OP*) v2);

		if (o == 0)
		{
			ip->code = code;
			ip->lastUse = 0;
			ip->oprnd1 = a1;
			ip->disp = v2;
			ip->liveAcrossCall = 0;
			ip->reg = Unknown;
			//ip->prevcse = 0;
#ifdef AVMPLUS_VERBOSE
			if (verbose())
			{
				core->console << "       @"<<InsNbr(ip)<<"\t";
				formatOpcode(core->console, ip, pool, core->codegenMethodNames);
				core->console << "\n";
			}
#endif /* AVMPLUS_VERBOSE */
			o = ip++;
			ip->prevcse = 0;
			this->ip = ip;
			if (a1)
				updateUse(o, a1);
		}
		return o;
	}

	OP* CodegenMIR::Ins(MirOpcode code, OP* a1, OP* a2)
	{
		OP* ip = this->ip;
#ifndef FEATURE_BUFFER_GUARD
		if (checkOverflow())
			return ip;
#endif /* FEATURE_BUFFER_GUARD */

		AvmAssert(code < MIR_last);
		OP* o = 0;

		if (core->config.cseopt && (code & MIR_oper))
			o = cseMatch(code, a1, a2);

		if (o == 0)
		{
			ip->code = code;
			ip->lastUse = 0;
			ip->oprnd1 = a1;
			ip->oprnd2 = a2;
			ip->liveAcrossCall = 0;
			ip->reg = Unknown;
			//ip->prevcse = 0;
#ifdef AVMPLUS_VERBOSE
			if (verbose())
			{
				core->console << "       @"<<InsNbr(ip)<<"\t";
				formatOpcode(core->console, ip, pool, core->codegenMethodNames);
				core->console  << "\n";
			}
#endif /* AVMPLUS_VERBOSE */
			o = ip++;
			ip->prevcse = 0;
			this->ip = ip;
			if (a1)
				updateUse(o, a1);
			if (a2)
				updateUse(o, a2);
		}
		return o;
	}

	void CodegenMIR::argIns(OP* arg)
	{
		// leave arg1 empty and use binaryIns so second arg has special treatment
		// if it is an immediate value
		OP* call = this->ip-1;

		AvmAssert((call->code&~MIR_float&~MIR_oper) == MIR_cm 
			|| (call->code&~MIR_float&~MIR_oper) == MIR_cs
			|| (call->code&~MIR_float) == MIR_ci);
		AvmAssert(arg_index <= call->argc);

		call->args[arg_index] = arg;

		if (arg)
		{
			Register hint = Unknown; 
			bool canFold = canImmFold(call, arg);

			// processor specific register hints
			#ifdef AVMPLUS_IA32
			if (!canFold && arg_index == 1 && (call->code&~MIR_float&~MIR_oper) == MIR_cm)
				hint = ECX;
			#endif //AVMPLUS_IA32
			#ifdef AVMPLUS_AMD64
			#ifndef _WIN64
			if (!canFold && arg_index == 1 && (call->code&~MIR_float&~MIR_oper) == MIR_cm)
				hint = RDI;
			#else //#ifndef _WIN64
			if (!canFold && arg_index == 1 && (call->code&~MIR_float&~MIR_oper) == MIR_cm)
				hint = RCX;
			#endif //#ifndef _WIN64
			#endif //AVMPLUS_AMD64			

			if (!canFold)
				updateUse(call, arg, hint);
		}

		// after the last arg, move ip to skip args
		if (++arg_index > call->argc)
		{
			lastFunctionCall = call;
			this->ip = call + (call->argc+7)/4;  // NB. DCE depends on this layout!
			#ifdef AVMPLUS_VERBOSE
			if (verbose())
				core->console << "@" << (arg ? InsNbr(arg) : -1) << ")\n";
			#endif //AVMPLUS_VERBOSE
		}
		#ifdef AVMPLUS_VERBOSE
		else
		{
			if (verbose())
				core->console << "@" << (arg ? InsNbr(arg) : -1) << ", ";
		}
		#endif // AVMPLUS_VERBOSE 
	}

	OP* CodegenMIR::loadIns(MirOpcode _code, sintptr _disp, OP* _base)
	{
#ifdef AVMPLUS_AMD64
		if (_code == MIR_ldop && !is32bit(_disp))
			AvmAssert(0);
#endif

#if HAVE_MIR_SMOPS
#ifdef AVMPLUS_64BIT
		AvmAssert((_code & ~MIR_float & ~MIR_oper) == MIR_ld
			|| (_code & ~MIR_float & ~MIR_oper) == MIR_sld
			|| (_code & ~MIR_float & ~MIR_oper) == MIR_ld32
			|| (_code & ~MIR_float & ~MIR_oper) == MIR_ld32u
			);
#else
		AvmAssert((_code & ~MIR_float & ~MIR_oper) == MIR_ld
			|| (_code & ~MIR_float & ~MIR_oper) == MIR_sld
			);
#endif
#else
#ifdef AVMPLUS_64BIT
		AvmAssert((_code & ~MIR_float & ~MIR_oper) == MIR_ld
			|| (_code & ~MIR_float & ~MIR_oper) == MIR_ld32
			|| (_code & ~MIR_float & ~MIR_oper) == MIR_ld32u
			);
#else
		AvmAssert((_code & ~MIR_float & ~MIR_oper) == MIR_ld
			);
#endif
#endif
		return Ins(_code, _base, _disp);
	}

	OP* CodegenMIR::binaryIns(MirOpcode code, OP* a1, OP* a2)
	{
		#ifdef AVMPLUS_ARM
		// On ARM, MIR_fadd/fsub/fmul/fdiv are helper functions
		switch (code)
		{
		case MIR_fadd:
			return callIns(MIR_fcsop, FUNCADDR(CodegenMIR::fadd), 2, a1, a2);			
		case MIR_fsub:
			return callIns(MIR_fcsop, FUNCADDR(CodegenMIR::fsub), 2, a1, a2);
		case MIR_fmul:
			return callIns(MIR_fcsop, FUNCADDR(CodegenMIR::fmul), 2, a1, a2);
		case MIR_fdiv:
			return callIns(MIR_fcsop, FUNCADDR(CodegenMIR::fdiv), 2, a1, a2);
		}
		#endif
		
		if (a1->code == MIR_imm && a2->code == MIR_imm)
		{
			// constant folding
			switch (code)
			{
			case MIR_or:	
#ifdef AVMPLUS_AMD64
			case MIR_orp:
#endif
				return InsConst(a1->imm | a2->imm);
			case MIR_and:	
#ifdef AVMPLUS_AMD64
			case MIR_andp:
#endif
				return InsConst(a1->imm & a2->imm);
			default: break;
			}
		}

		OP* ip = this->ip;
#ifndef FEATURE_BUFFER_GUARD
		if (checkOverflow())
			return ip;
#endif /* FEATURE_BUFFER_GUARD */

		AvmAssert(code < MIR_last);
		OP* o = 0;

		if (core->config.cseopt && (code & MIR_oper))
			o = cseMatch(code, a1, a2);

		if (o == 0)
		{
			ip->code = code;
			ip->lastUse = 0;
			ip->oprnd1 = a1;
			ip->oprnd2 = a2;
			ip->liveAcrossCall = 0;
			ip->reg = Unknown;
			//ip->prevcse = 0;
#ifdef AVMPLUS_VERBOSE
			if (verbose())
			{
				core->console << "       @"<<InsNbr(ip)<<"\t";
				formatOpcode(core->console, ip, pool, core->codegenMethodNames);
				core->console << "\n";
			}
#endif /* AVMPLUS_VERBOSE */
			o = ip++;
			ip->prevcse = 0;
			this->ip = ip;

			if (a1)
				updateUse(o, a1);
			if (a2 && !canImmFold(o, a2))
				updateUse(o, a2);
		}
		return o;
	}

	/**
	 * A simple CSE-like optimzer that works by identifing 
	 * identical instructions used in the same basic block.
	 * When we hit a match we simply return the instruction
	 * number without generating a new MIR instruction.
	 * 
	 * This code may generate more spills across MIR function 
	 * calls, but the underlying assumption is that a 
	 * spill/remateralize pair is less expensive than 
	 * re-generating the value.	
	 */
	OP* CodegenMIR::cseMatch(MirOpcode code, OP* a1, OP* a2)
	{
		int count=0;
		OP* ins = cseTable[code];
		OP* stop = firstCse; // start of EBB

		while (ins >= stop)
		{
			AvmAssert(ins->code == code);
			// address check ranges don't factor in
			// as they're updated on match
			if (ins->code == code &&
				ins->oprnd1 == a1 &&
				(ins->oprnd2 == a2
#if HAVE_MIR_SMOPS
				|| code == MIR_maddr
#endif
				))
			{
				#ifdef AVMPLUS_VERBOSE
				if (verbose())
					core->console  << "        \tcse   @" << InsNbr(ins) << "\n";
				#endif /* AVMPLUS_VERBOSE */
#if HAVE_MIR_SMOPS
				// update range for memory address operation
				if(code == MIR_maddr)
				{
					int32 mn1 = (int32)a2 >> 16;
					int32 mx1 = ((int32)a2 << 16) >> 16;
					int32 mn2 = (int32)ins->oprnd2 >> 16;
					int32 mx2 = ((int32)ins->oprnd2 << 16) >> 16;
					int32 mn = mn1 < mn2 ? mn1 : mn2;
					int32 mx = mx1 > mx2 ? mx1 : mx2;

					ins->imm = (mn << 16) | (mx & 0xffff);
				}
#endif
				return ins;
			}

			if (count++ < 20 && ins->prevcse)
				ins -= ins->prevcse;
			else
				break;
		}

		ins = cseTable[code];
		if (ins >= stop && ip-ins <= 0xFFFF)
			ip->prevcse = ip-ins;
		else
			ip->prevcse = 0;
		cseTable[code] = ip;

		return 0;
	}

	/**
	 * Check to see if the given instruction is used in our state
	 */
	bool CodegenMIR::usedInState(OP* ins)
	{
		for (int i=0, n=state->sp()/*verifier->frameSize*/; i < n; i++)
		{
			Value& v = state->value(i);
			if (ins == v.ins)
				return true;
		}
		return false;
	}

	/**
	 * Dead code eliminator.  Given an instruction we mark it
	 * as unused.  The operands of the instruction are then 
	 * placed on a list wherein we search backwards through the
	 * code looking for references.  If we reach the instruction
	 * that generated the data and found no other use of the reference
	 * then we mark it as unsed.  We continue this process all
	 * until no more instructions are in the list.
	 */
	void CodegenMIR::markDead(OP* ins)
	{
		if (!core->config.dceopt)
			return;

		// if there is already a use or its stored in state then don't kill it
		if (ins->lastUse || usedInState(ins))
			return;

		List<OP*> search(4);
		search.add(ins);

		OP* currIns = ins;  // start the search from the given instruction
		OP* stop = firstCse;  // the search MUST end prior to a bb start

		while(!search.isEmpty() && currIns >= stop)
		{
			AvmAssert(currIns > stop);  // we should not cross this border

			//core->console  << "  currIns  @" << InsNbr(currIns) << " stop @" << InsNbr(stop) << "\n";

			int n = search.size();
			for(int i=n-1; i>=0; i--)
			{
				OP* elm = search.get(i);
				if (elm == currIns)
				{
					// no need to search for it anymore
					search.removeAt(i);

					// we hit the instruction and didn't see a ref for 
					// elm, therefore it has no other use. 
					elm->lastUse = 0;

					// clear out the instruction if its in the cse table
					if (cseTable[elm->code] == elm)
						cseTable[elm->code] = 0;

					#ifdef AVMPLUS_VERBOSE
					if (verbose())
						core->console  << "     \tdead   @" << InsNbr(elm) << "\n";
					#endif //AVMPLUS_VERBOSE

					// now inspect it to see if its operands should be added as well
					if (elm->code & MIR_oper)
					{
						if (elm->oprnd1 < currIns && elm->oprnd1 > stop )
						{
							// looks promising but not confirmed yet
							OP* inspect = elm->oprnd1;
							if ( (inspect->lastUse == elm)  &&
								 (inspect->code & MIR_oper) &&
								 (inspect->code != MIR_imm) &&
								 !usedInState(inspect) )
							{
								//looks good to add
								search.add(inspect);
								//core->console  << " search.1 @" << InsNbr(inspect) << "\n";
							}
						}

						if (elm->oprnd2 < currIns && elm->oprnd2 > stop )
						{
							// looks promising but not confirmed yet
							OP* inspect = elm->oprnd2;
							if ( (inspect->lastUse == elm)  &&
								 (inspect->code & MIR_oper) &&
								 (inspect->code != MIR_imm) &&
								 !usedInState(inspect) )
							{
								// yup looks good to add
								search.add(inspect);
								//core->console  << " search.2 @" << InsNbr(inspect) << "\n";
							}
						}
					}
				}
				else
				{
					bool remove = false;

					/**
					 * Be ultra conservative and just check every 32 bit value over the 16 Bytes
					 * but only check the last slot (which contains lastUse) if the instruction 
					 * looks like a store or a call
					 */
					#ifdef AVMPLUS_64BIT
					AvmAssert(sizeof(OP) == 32);
					#else
					AvmAssert(sizeof(OP) == 16);
					#endif
					uintptr* slot = (uintptr*)currIns;
					if (*slot == (uintptr)elm || *(slot+1) == (uintptr)elm || *(slot+2) == (uintptr)elm) 
					{
						remove = true;
					}
					else if ( ( ((currIns->code == MIR_st) ||
#if HAVE_MIR_SMOPS
                                 (currIns->code == MIR_sst) ||
#endif
                                 (currIns->code == MIR_st32)) ||
								((currIns->code&~MIR_float&~MIR_oper) == MIR_cm) ||
							    ((currIns->code&~MIR_float&~MIR_oper) == MIR_cs) ||
							    ((currIns->code&~MIR_float) == MIR_ci) ) &&
							  (*(slot+3) == (uintptr)elm) )
					{
						remove = true;
					}

					// its being used by this instruction (most likely) so we can't mark it dead
					if (remove)
					{
						elm->lastUse = currIns;
						search.removeAt(i);
						//core->console  << " found @" << InsNbr(elm) << "\n";
					}
				}
			}

			// move to the previous instruction
			currIns--;
		}
	}

	/**
 	 * ---------------------------------
	 * Instruction convenience functions 
	 * ---------------------------------
	 */

	/**
	 * Define an incoming method argument that resides on the stack.
	 * The spOffset value is the position of the arg relative to 
	 * stack pointer at the start of the method.
	 */
	OP* CodegenMIR::defineArgInsPos(int pos)
	{
		OP* op = Ins(MIR_arg);
		op->pos = -pos - op->spillSize();
		return op;
	}

	/**
	 * Define an incoming method argument that resides in a register.
	 */
	OP* CodegenMIR::defineArgInsReg(Register r)
	{
		OP* op = Ins(MIR_arg, (int)r);
		op->reg = r;
		return op;
	}

	// store to register + offset
	void CodegenMIR::storeIns(OP* value, uintptr disp, OP* base, bool force32)
	{
		storeIns(force32?MIR_st32:MIR_st, value, disp, base);
	}

	// store to register + offset
	void CodegenMIR::storeIns(MirOpcode _code, OP* value, uintptr disp, OP* base)
	{
#if HAVE_MIR_SMOPS
		AvmAssert(_code == MIR_st || _code == MIR_sst || _code == MIR_st32);
#else
		AvmAssert(_code == MIR_st || _code == MIR_st32);
#endif
		OP* ip = this->ip;
#ifndef FEATURE_BUFFER_GUARD
		if (checkOverflow())
			return;
#endif /* FEATURE_BUFFER_GUARD */

		if (base && base->code == MIR_imm) {
			disp += base->imm;
			base = 0;
		}

		// invalidate any previous loads
		if (value->isDouble())
		{
			cseTable[MIR_fld] = 0;
#if HAVE_MIR_SMOPS
			cseTable[MIR_fsld] = 0;
#endif
		}
		else
		{
			cseTable[MIR_ld] = 0;
#if HAVE_MIR_SMOPS
			cseTable[MIR_sld] = 0;
#endif
#ifdef AVMPLUS_64BIT
			cseTable[MIR_ld32] = 0;
			cseTable[MIR_ld32u] = 0;
#endif
		}

#if HAVE_MIR_SMOPS
		// MIR_sst uses lower 2 bits for size / sign extend info
		AvmAssert(_code == MIR_sst || (disp % 4) == 0);
#else
		AvmAssert((disp % 4) == 0);
#endif
		ip->code =_code;
		ip->base = base;
		ip->disp = disp;
		ip->value = value;
		ip->liveAcrossCall = 0;

#ifdef AVMPLUS_VERBOSE
		if (verbose())
		{
			core->console << "       @"<<InsNbr(ip)<<"\t";
			formatOpcode(core->console, ip, pool, core->codegenMethodNames);
			core->console << "\n";
		}
#endif /* AVMPLUS_VERBOSE */

		OP* o = ip++;
		ip->prevcse = 0;
		this->ip = ip;
		if (base)
			updateUse(o, base);

		if (!canImmFold(o, value))
			updateUse(o, value);
	}

	OP* CodegenMIR::defIns(OP* value)
	{
		return Ins(value->isDouble() ? (MirOpcode)MIR_fdef : (MirOpcode)MIR_def, value);
	}

	OP* CodegenMIR::useIns(OP* def, sintptr i)
	{
		while (def->join)
			def = def->join;
		return Ins(def->isDouble() ? (MirOpcode)MIR_fuse : (MirOpcode)MIR_use, def, i);
	}

	// address calc instruction
	OP* CodegenMIR::leaIns(sintptr disp, OP* base)
	{
		AvmAssert((disp % 4) == 0);

		return Ins(MIR_lea, base, disp);
	}

	// call 
	OP* CodegenMIR::callIns(MirOpcode code, sintptr addr, uint32 argCount, ...)
	{
		// if this is a pure operator function
		if (core->config.cseopt && (code&MIR_oper))
		{
#ifndef FEATURE_BUFFER_GUARD
			if (checkOverflow())
				return ip;
#endif /* FEATURE_BUFFER_GUARD */

			int count=0;
			OP* ins = cseTable[code];
			while (ins >= firstCse)
			{
				AvmAssert(ins->code == code);
				if (ins->argc == argCount && 
					ins->addr == addr)
				{
					// previous call is in this BB and argc/addr match
					va_list ap;
					va_start(ap, argCount);
					uint32 i=1;
					for (; i <= argCount && ins; i++)
					{
						OP* arg = va_arg(ap, OP*);
						OP* arg2 = ins->args[i];
						if (arg2 != arg)
							break;
					}
					va_end(ap);

					if (i == argCount+1)
					{
						#ifdef AVMPLUS_VERBOSE
						if (verbose())
							core->console << "        \tcse   @" << InsNbr(ins) << "\n";
						#endif /* AVMPLUS_VERBOSE */
						return ins;
					}
				}
				if (count++ < 20 && ins->prevcse)
					ins -= ins->prevcse;
				else
					break;
			}
			ins = cseTable[code];
			if (ins >= firstCse && ip-ins <= 0xFFFF)
				ip->prevcse = ip-ins;
			else
				ip->prevcse = 0;
			cseTable[code] = ip;
		}

		OP* result = callIns(addr, argCount, code);
		va_list ap;
		va_start(ap, argCount);
		while (argCount-- > 0)
			argIns(va_arg(ap, OP*));
		va_end(ap);

		// clear this out so a call that changes the backing store won't get reuse a stale
		// (and possibly insecure) mchecked value
#if HAVE_MIR_SMOPS
		// could theoretically not do this if we're an oper...
		cseTable[MIR_maddr] = 0;
#endif
		return result;
	}

	OP* CodegenMIR::callIns(sintptr addr, uint32 argCount, MirOpcode code)
	{
		#ifdef DEBUGGER
		if (!(code & MIR_oper))
			saveState();
		#endif

		OP* ip = this->ip;
#ifndef FEATURE_BUFFER_GUARD
		if (checkOverflow())
			return ip;
#endif /* FEATURE_BUFFER_GUARD */

		// ensure it's actually a call
		AvmAssert((code&~MIR_float&~MIR_oper) == MIR_cm || (code&~MIR_float&~MIR_oper) == MIR_cs);

		if (argCount > maxArgCount) 
			maxArgCount = argCount;

		if (!(code & MIR_oper)) 
		{
			// call could have side effects, ignore any previous loads
			cseTable[MIR_fld] = 0;
			cseTable[MIR_ld] = 0;
			#ifdef AVMPLUS_64BIT
			cseTable[MIR_ld32] = 0;
			cseTable[MIR_ld32u] = 0;
			#endif
#if HAVE_MIR_SMOPS
			cseTable[MIR_fsld] = 0;
			cseTable[MIR_sld] = 0;
#endif
		}

		ip->code = code;
		ip->lastUse = 0;
		ip->argc = argCount;
		ip->addr = addr;
		ip->liveAcrossCall = 0;
		ip->reg = Unknown;
		//ip->prevcse = 0;

		#ifdef AVMPLUS_VERBOSE
		#ifdef _DEBUG
//		const char *nameCheck = (const char *)core->codegenMethodNames->get(ip->addr); 
//		AvmAssertMsg((Atom)(nameCheck) != undefinedAtom && nameCheck, "Add method name to codegenMethodNames table\n");
		#endif // DEBUG
		if (verbose())
		{
			core->console << "       @"<<InsNbr(ip)
#ifndef AVMPLUS_SYMBIAN
				<<"\t" << mirNames[ip->code]
#endif
				<<" ";
			const char *name; 
			if ( ((Atom)(name = (const char *)core->codegenMethodNames->get(ip->addr)) != undefinedAtom) && name )
			{
				core->console << name;
			}
			else
			{
				AvmAssertMsg(false, "Add method name to codegenMethodNames table\n");
				core->console.writeHexAddr(ip->addr);
			}
			core->console << " (";

			if (argCount == 0)
				core->console << ")\n";
		}
		#endif /* AVMPLUS_VERBOSE */

		arg_index = 1;
		OP* where = ip++;
		ip->prevcse = 0;
		this->ip = ip;
		if (argCount == 0)
			lastFunctionCall = where;// + (argCount+3)/4; // look past the last fnc arg

		#ifdef DEBUGGER
		if (!(code & MIR_oper))
			extendDefLifetime(where);
		#endif

		// clear this out so a call that changes the backing store won't get reuse a stale
		// (and possibly insecure) mchecked value
#if HAVE_MIR_SMOPS
		// could theoretically not do this if we're an oper...
		cseTable[MIR_maddr] = 0;
#endif
		return where;
	}

	OP* CodegenMIR::callIndirect(MirOpcode code, OP* target, uint32 argCount, ...)
	{
		#ifdef DEBUGGER
		if (!(code & MIR_oper))
			saveState();
		#endif

		OP* ip = this->ip;
#ifndef FEATURE_BUFFER_GUARD
		if (checkOverflow())
			return ip;
#endif /* FEATURE_BUFFER_GUARD */

		// ensure it's actually a call
		AvmAssert(code == MIR_ci || code == MIR_fci);

		if (argCount > maxArgCount) 
			maxArgCount = argCount;

		// call could have side effects, ignore any previous loads
		cseTable[MIR_fld] = 0;
		cseTable[MIR_ld] = 0;
		#ifdef AVMPLUS_64BIT
		cseTable[MIR_ld32] = 0;
		cseTable[MIR_ld32u] = 0;
		#endif
#if HAVE_MIR_SMOPS
		cseTable[MIR_fsld] = 0;
		cseTable[MIR_sld] = 0;
#endif
		ip->code = code;
		ip->lastUse = 0;
		ip->argc = argCount;
		ip->target = target;
		ip->liveAcrossCall = 0;
		ip->reg = Unknown;

		#ifdef AVMPLUS_VERBOSE
		if (verbose())
		{
			core->console << "       @"<<InsNbr(ip)
#ifndef AVMPLUS_SYMBIAN
				<< "\t" << mirNames[ip->code] 
#endif
				<< " @" << InsNbr(target)
				<< " (";
			if (argCount == 0)
				core->console << ")\n";
		}
		#endif /* AVMPLUS_VERBOSE */

		arg_index = 1;
		OP* where = ip++;
		ip->prevcse = 0;
		this->ip = ip;

		// peek through the lea since MD callindirect can use disp+reg
		if (target->code == MIR_lea)
			target = target->base;

#ifdef AVMPLUS_IA32
		Register hint = ECX;
#else
		Register hint = Unknown;
#endif
		updateUse(where, target, hint);	
		lastFunctionCall = where;// + (argCount+3)/4; // look past the last fnc arg

		// args
		va_list ap;
		va_start(ap, argCount);
		while (argCount-- > 0)
			argIns(va_arg(ap, OP*));
		va_end(ap);

		#ifdef DEBUGGER
		if (!(code & MIR_oper))
			extendDefLifetime(where);
		#endif

		// clear this out so a call that changes the backing store won't get reuse a stale
		// (and possibly insecure) mchecked value
#if HAVE_MIR_SMOPS
		// could theoretically not do this if we're an oper...
		cseTable[MIR_maddr] = 0;
#endif
		return where;
	}

	OP* CodegenMIR::localGet(uintptr i)				
	{
		Value& v = state->value(i);
		OP* op = v.ins;
		if (op && ((op->code&~MIR_float)==MIR_def))
			v.ins = op = useIns(op, i);
		return op;
	}

	void  CodegenMIR::localSet(uintptr i, OP* o)	
	{
		Value &v = state->value(i);
		v.ins = o;
		v.stored = false;

		#ifdef VERBOSE_LOCALS
		core->console << "  lset " << (double)i << "  ";
		formatOpcode(core->console, o, pool, core->codegenMethodNames);
		core->console <<"\n";
		#endif
	}

	OP* CodegenMIR::atomToNativeRep(int i, OP* atom)
	{
		return atomToNativeRep(state->value(i).traits, atom);
	}

	OP* CodegenMIR::ptrToNativeRep(Traits*t, OP* ptr)
	{
		if (t->isMachineType())
		{
			return binaryIns(MIR_orp, ptr, InsConst(kObjectType));
		}
		return ptr;
	}

	bool CodegenMIR::isPointer(int i)
	{
		return !state->value(i).traits->isMachineType();
	}

	bool CodegenMIR::isDouble(int i)
	{
		return state->value(i).traits == NUMBER_TYPE;
	}

	OP* CodegenMIR::loadAtomRep(uintptr i)
	{
		Value& v = state->value(i);
		Traits* t = v.traits;
		OP* native = localGet(i);

		if (!t || t == OBJECT_TYPE || t == VOID_TYPE)
		{
			return native;
		}
		
		// short circuit immediates
		if (native->code == MIR_imm)
		{
			if (t == INT_TYPE)
			{
				Atom a = core->intToAtom(int(native->imm));
				if(AvmCore::isInteger(a))
					return InsConst(a);
			}

			if (t == UINT_TYPE)
			{
				Atom a = core->uintToAtom(uint32(native->imm));
				if(AvmCore::isInteger(a))
					return InsConst(a);
			}

			if (t == BOOLEAN_TYPE)
			{
				return InsConst(native->imm ? trueAtom : falseAtom);
			}

			if (!t->isMachineType() && native->imm == 0)
			{
				return InsConst(nullObjectAtom);
			}
		}

		if (t == NUMBER_TYPE)
		{
			sintptr funcaddr = COREADDR(AvmCore::doubleToAtom);
#ifdef AVMPLUS_IA32
			if (core->config.sse2)
				funcaddr = COREADDR(AvmCore::doubleToAtom_sse2);
#endif
			return callIns(MIR_cmop, funcaddr, 2, InsConst((uintptr)core), native);
		}
		if (t == INT_TYPE)
		{
			return callIns(MIR_cmop, COREADDR(AvmCore::intToAtom), 2,
				InsConst((uintptr)core), native);
		}
		if (t == UINT_TYPE)
		{
			return callIns(MIR_cmop, COREADDR(AvmCore::uintToAtom), 2,
				InsConst((uintptr)core), native);
		}
		if (t == BOOLEAN_TYPE)
		{
			OP* i1 = binaryIns(MIR_lsh, native, InsConst(3));
			return binaryIns(MIR_or, i1, InsConst(kBooleanType));
		}

		// possibly null pointers
		if (t == STRING_TYPE)
		{
			return binaryIns(MIR_orp, native, InsConst(kStringType));
		}
		if (t == NAMESPACE_TYPE)
		{
			return binaryIns(MIR_orp, native, InsConst(kNamespaceType));
		}

		return binaryIns(MIR_orp, native, InsConst(kObjectType));
	}

	OP* CodegenMIR::storeAtomArgs(int count, int index)
	{
		#ifdef AVMPLUS_VERBOSE
		if (verbose())
			core->console << "        	store boxed args\n";
		#endif
		OP* ap = InsAlloc(sizeof(Atom)*count);
		for (int i=0; i < count; i++)
		{
			OP* v = loadAtomRep(index++);
			storeIns(v, sizeof(Atom)*i, ap);
		}
		return ap;
	}

	OP* CodegenMIR::storeAtomArgs(OP* receiver, int count, int index)
	{
		#ifdef AVMPLUS_VERBOSE
		if (verbose())
			core->console << "        	store args\n";
		#endif
		OP* ap = InsAlloc(sizeof(Atom)*(count+1));
		storeIns(receiver, 0, ap);
		for (int i=1; i <= count; i++)
		{
			OP* v = loadAtomRep(index++);
			storeIns(v, sizeof(Atom)*i, ap);
		}
		return ap;
	}

#ifdef DEBUGGER
    /**
     * ensure all def's are live to this point (current).
     * this is used to ensure variables are visible to the
     * debugger even after the end of their normal live range
     */
	void CodegenMIR::extendDefLifetime(OP* current)
	{
		for (int i=0, n=state->verifier->local_count; i < n; i++)
		{
			OP* def = state->value(i).ins;
			if (!def)
				continue;
			if ((def->code & ~MIR_float) == MIR_use)
				def = def->oprnd1;
			AvmAssert(def && (def->code & ~MIR_float) == MIR_def);
			while (def->join)
				def = def->join;
			def->lastUse = current;
		}
	}
#endif

	void CodegenMIR::saveState()
	{
#ifdef AVMPLUS_VERBOSE
		if (verbose())
			core->console << "    save state\n";
#endif
		// locals and scopes
		int stackBase = state->verifier->stackBase;
		int scopeTop = state->verifier->scopeBase+state->scopeDepth;
		for (int i=0, n = stackBase+state->stackDepth; i < n; i++)
		{
			#ifndef DEBUGGER
			if (i >= scopeTop && i < stackBase)
			{
				// not live
				continue;
			}
			#endif
			Value& v = state->value(i);
			if (v.stored)
			{
				// unused
				if ((v.ins->code & ~MIR_float) == MIR_use && v.ins->disp == i)
				{
					// used but not changed, revert to unused def
					v.ins = v.ins->oprnd1;
				}
				continue;
			}

			// changed

			// store the stack elements onto the real stack
			if (v.ins)
			{
				v.ins = defIns(v.ins);
				v.stored = true;

				#ifdef DEBUGGER
				// store the traits ptr so the debugger knows what was stored.
				if (i < state->verifier->local_count)
				{
					storeIns(InsConst((uintptr)v.traits ), i*sizeof(Traits*), localTraits);
					storeIns(Ins(MIR_usea, v.ins), i*sizeof(void*), localPtrs);
				}
				else if (i >= state->verifier->scopeBase && i < state->verifier->scopeBase + state->verifier->max_scope) 
				{
					OP* scope;

					if (i < scopeTop)
					{
						Value& v = state->value(i);
						Traits* t = v.traits;

						if (t == VOID_TYPE || t == INT_TYPE || t == UINT_TYPE || t == BOOLEAN_TYPE ||
							t == NUMBER_TYPE || t == STRING_TYPE || t == NAMESPACE_TYPE)
						{
							scope = InsConst(0);
						}
						else
						{
							scope = Ins(MIR_use, v.ins);
						}
					}
					else // not live
					{
						// warning, v.traits are garbage at this point, so don't use them
						scope = InsConst(0);
					}

					storeIns(scope, i * sizeof(void*), localPtrs);
				}
				#endif //DEBUGGER
			}
		}
	}

	void CodegenMIR::updateUse(OP* currentIns, OP* ins, Register hint)
	{
		AvmAssert(currentIns < ip);
		AvmAssert((ins->code&~MIR_float) != MIR_def || ins->join == 0);

		ins->lastUse = currentIns;

		if (ins < lastFunctionCall && currentIns > lastFunctionCall)
		{
			// if the def occured prior to our last know function call then it
			// means that we need the value to survive past the function
			ins->liveAcrossCall = true;
		}

		if (hint != Unknown && !ins->liveAcrossCall && ins->code != MIR_arg)
			ins->reg = hint;
	}

	// position label at OP->target (will trigger patching)
	void CodegenMIR::mirPatch(OP* i, sintptr targetpc)
	{
		mirPatchPtr(&i->target, targetpc);
        if (targetpc < state->pc) {
            // this is a backwards jump, extend live vars to the jump
            // so they are live through the whole loop body
			extendLastUse(i, targetpc);
	}
	}

    /**
     * extend the live range of a single variable that is used in 
     * a loop, but defined before the loop, to make sure it's live
     * through the whole loop.
     */
	void CodegenMIR::extendLastUse(OP* ins, OP* use, OP* target)
	{
		if (!ins)
			return;
		if ((ins->code & ~MIR_float) == MIR_def)
			while (ins->join)
				ins = ins->join;
        if (ins < target && target < ins->lastUse) {
            // ins is defined before the loop header (target)
            // and used inside the loop, so extend it to the
            // loop jump point (use)
			ins->lastUse = use;
	}
	}

    /**
     * extend the live range of variables that are used in a loop
     * to make sure the range extends to the bottom of the loop
     */
	void CodegenMIR::extendLastUse(OP* use, sintptr targetpc)
	{
		// if target of the branch is in the middle of any
		// live range, extend the live range to include
		// the branch

		FrameState* targetState = state->verifier->getFrameState(targetpc);
		MirLabel &l = targetState->label;
		OP* target = l.bb;
		AvmAssert(target && target->code == MIR_bb);

		// check the args
#ifdef AVMPLUS_AMD64
#ifndef _WIN64
		for(int i=0; i<6; i++)
#else //#ifdef _WIN64
		for(int i=0; i<4; i++)
#endif //#ifdef _WIN64
#else
		for(int i=0; i<3; i++)
#endif
			extendLastUse(&methodArgs[i], use, target);

		// check the frame state variables
		for (int i=0, n=targetState->verifier->frameSize; i < n; i++)
			extendLastUse(targetState->value(i).ins, use, target);

		extendLastUse(undefConst, use, target);

		// other misc, re-usable expressions
		if (info->exceptions)
			extendLastUse(exAtom, use, target);
	}

	void CodegenMIR::InsDealloc(OP* alloc)
	{
		AvmAssert(alloc->code == MIR_alloc);
		alloc->lastUse = ip-1;
	}

	CodegenMIR::CodegenMIR(PoolObject* p)
		: core(p->core), pool(p), info(NULL), activation(p->core->GetGC())
	{
		mirBuffer = NULL;
		state = NULL;
		framep = SP;
		interruptable = true;
		overflow = false;

		#if defined(AVMPLUS_IA32) && defined(_MAC)
		patch_esp_padding = NULL;
		#endif

		#ifdef AVMPLUS_SPARC
		beginCatch_start = NULL;
		beginCatch_end = NULL;
		#endif
		
		#ifdef AVMPLUS_ARM
		#ifdef AVMPLUS_VERBOSE
		this->verboseFlag = pool->verbose;
		#endif
		this->console = &core->console;
		#endif		

		#ifdef VTUNE
		hasDebugInfo = false;
       jitInfo = new (core->GetGC()) JITCodeInfo(core->GetGC());
		#endif /* VTUNE */
	}

	CodegenMIR::CodegenMIR(MethodInfo* i)
		: core(i->core()), pool(i->pool), info(i), activation(i->core()->GetGC())
	{
		state = NULL;
		framep = SP;
 		interruptable = true;

		#ifdef AVMPLUS_MAC_CARBON
		setjmpInit();
		#endif

		#if defined(AVMPLUS_IA32) && defined(_MAC)
		patch_esp_padding = NULL;
		#endif

		#ifdef AVMPLUS_ARM
		// Hack for debugging
		//pool->verbose = true;
		#endif
		
		#ifdef AVMPLUS_ARM
		#ifdef AVMPLUS_VERBOSE
		this->verboseFlag = pool->verbose;
		#endif
		this->console = &core->console;
		#endif		

		abcStart = NULL;
		abcEnd   = NULL;
		casePtr = NULL;
		ipStart = NULL;

		#ifdef AVMPLUS_ARM
		patch_frame_size = NULL;
		patch_stmfd = NULL;
		gpregs.nonVolatileMask  = 0;
		fpregs.nonVolatileMask  = 0;
		#endif

		#ifdef AVMPLUS_SPARC
		patch_frame_size = NULL;
		beginCatch_start = NULL;
		beginCatch_end = NULL;
		#endif

		#ifdef AVMPLUS_PPC
		gpregs.LowerBound = Unknown;
		fpregs.LowerBound = Unknown;
		patch_stwu = NULL;
		patch_stmw = NULL;
		#endif

		expansionFactor = 1;

		// get a buffer from the global list
		mirBuffer = core->requestMirBuffer();
		overflow = (mirBuffer) ? false : true; // if no buffer then we have no room

		#ifdef VTUNE
		hasDebugInfo = false;
       jitInfo = new (core->GetGC()) JITCodeInfo(core->GetGC());
		#endif /* VTUNE */
	}

	CodegenMIR::~CodegenMIR()
	{
		//if (arg_count > 0)
		//	core->console << "mir_arg " << arg_count << " of " << InsNbr(ip) << "\n";
		//arg_count = 0;

		clearMIRBuffers();
	}

	void CodegenMIR::clearMIRBuffers()
	{
		// free scratch buffers explicitly.  None of these have any pointers
		// in them, and none of them will have escaped into other objects.
		// freeing them now reduces GC pressure at startup time.

		// return the buffer back to the global list
		if (mirBuffer)
		{
			if (mirBuffer->size() > 0)
				mirBuffer->shrinkTo(mir_buffer_size_min);
			core->releaseMirBuffer(mirBuffer);
		}
	}
	
	#ifdef AVMPLUS_MAC_CARBON
	int CodegenMIR::setjmpAddress = 0;

	extern "C" int __setjmp();
	
	asm int CodegenMIR::setjmpDummy(jmp_buf buf)
	{
		b __setjmp;	
	}
	
	void CodegenMIR::setjmpInit()
	{
		// CodeWarrior defies all reasonable efforts to get
		// the address of __vec_setjmp.  So, we resort to
		// a crude hack: We'll search the actual code
		// of setjmpDummy for the branch instruction.
		if (setjmpAddress == 0)
		{
			setjmpAddress = *((int*)&setjmpDummy);
		}
	}
	#endif

#ifdef AVMPLUS_VERBOSE
	GCHashtable* CodegenMIR::initMethodNames(AvmCore* /*core*/)
	{
		#ifdef AVMPLUS_MAC_CARBON
		// setjmpInit() is also called in the constructor, but initMethodNames() is
		// a static function and thus may get called before the constructor.
		setjmpInit();
		#endif

		// make sure we can do bit masking on the call opcodes.
		AvmAssert(MIR_cmop == (MIR_cm|MIR_oper));
		AvmAssert(MIR_csop == (MIR_cs|MIR_oper));
		AvmAssert(MIR_fcm == (MIR_cm|MIR_float));
		AvmAssert(MIR_fcs == (MIR_cs|MIR_float));
		AvmAssert(MIR_fcmop == (MIR_cm|MIR_float|MIR_oper));
		AvmAssert(MIR_fcsop == (MIR_cs|MIR_float|MIR_oper));

		AvmAssert(MIR_last <= 256); // we have only 8 bits to use


		// first init our own opcode names
#ifndef AVMPLUS_SYMBIAN
		mirNames[MIR_bb]    = "bb   ";
		mirNames[MIR_imm]   = "imm  ";
		mirNames[MIR_ld]    = "ld   ";
		#ifdef AVMPLUS_64BIT
		mirNames[MIR_ld32]  = "ld32   ";
		mirNames[MIR_ld32u]  = "ld32u   ";
		#endif
#if HAVE_MIR_SMOPS
		mirNames[MIR_sld]   = "sld  ";
		mirNames[MIR_sst]   = "sst  ";
		mirNames[MIR_sx8]   = "sx8  ";
		mirNames[MIR_sx16]   = "sx16 ";
		mirNames[MIR_maddr]   = "maddr";
		mirNames[MIR_sldop]   = "sldop";
		mirNames[MIR_fsldop]   = "fsldop";
#endif
		mirNames[MIR_fld]   = "fld  ";
		mirNames[MIR_ldop]  = "ldop ";
		mirNames[MIR_fldop] = "fldop";
		mirNames[MIR_st]    = "st   ";
		mirNames[MIR_st32]  = "st32   ";
		mirNames[MIR_arg]   = "arg  ";
		mirNames[MIR_cm]    = "cm   ";
		mirNames[MIR_cs]    = "cs   ";
		mirNames[MIR_ci]    = "ci   ";
		mirNames[MIR_neg]   = "neg  ";
		mirNames[MIR_lsh]   = "lsh  ";
		mirNames[MIR_rsh]   = "rsh  ";
		mirNames[MIR_ush]   = "ush  ";
		mirNames[MIR_and]   = "and  ";
		mirNames[MIR_or]    = "or   ";
		mirNames[MIR_xor]   = "xor  ";
		mirNames[MIR_add]   = "add  ";
		mirNames[MIR_addp]  = "addp ";
#if defined (AVMPLUS_AMD64)
		mirNames[MIR_orp]	= "orp ";
		mirNames[MIR_andp]	= "andp ";
#endif
#if defined(AVMPLUS_IA32) || defined (AVMPLUS_AMD64)
		mirNames[MIR_d2i]   = "d2i  ";
#endif
		mirNames[MIR_sub]   = "sub  ";
		mirNames[MIR_imul]  = "imul ";
		mirNames[MIR_icmp]  = "icmp ";
		mirNames[MIR_ucmp]  = "ucmp ";
		mirNames[MIR_fcmp]  = "fcmp ";
		mirNames[MIR_jeq]   = "jeq  ";
		mirNames[MIR_jne]   = "jne  ";
		mirNames[MIR_jlt]   = "jlt  ";
		mirNames[MIR_jle]   = "jle  ";
		mirNames[MIR_jnlt]  = "jnlt ";
		mirNames[MIR_jnle]  = "jnle ";
		mirNames[MIR_ret]   = "ret  ";
		mirNames[MIR_jmp]   = "jmp  ";
		mirNames[MIR_jmpi]  = "jmpi ";
		mirNames[MIR_jmpt]  = "jmpt ";
		mirNames[MIR_le]    = "le   ";
		mirNames[MIR_lt]    = "lt   ";
		mirNames[MIR_eq]    = "eq   ";
		mirNames[MIR_ne]    = "ne   ";
		mirNames[MIR_lea]   = "lea  ";
		mirNames[MIR_alloc] = "alloc";
		mirNames[MIR_def]   = "def  ";
		mirNames[MIR_fdef]  = "fdef ";
		mirNames[MIR_use]   = "use  ";
		mirNames[MIR_fuse]  = "fuse ";
		mirNames[MIR_usea]	= "usea ";
		mirNames[MIR_fcm]   = "fcm  ";
		mirNames[MIR_fcs]   = "fcs  ";
		mirNames[MIR_fci]   = "fci  ";
		mirNames[MIR_i2d]   = "i2d  ";
		mirNames[MIR_u2d]   = "u2d  ";		
		mirNames[MIR_fadd]  = "fadd ";
		mirNames[MIR_fsub]  = "fsub ";
		mirNames[MIR_fmul]  = "fmul ";
		mirNames[MIR_fdiv]  = "fdiv ";
		mirNames[MIR_fneg]  = "fneg ";
		mirNames[MIR_cmop]  = "cmop ";
		mirNames[MIR_csop]  = "csop ";
		mirNames[MIR_fcmop] = "fcmop";
		mirNames[MIR_fcsop] = "fcsop";
#endif
		GCHashtable* names = new GCHashtable();

		#ifdef DEBUGGER
		names->add(ENVADDR(MethodEnv::sendEnter), "MethodEnv::sendEnter");
		names->add(ENVADDR(MethodEnv::sendExit), "MethodEnv::sendExit");
		names->add(DEBUGGERADDR(Debugger::debugFile), "Debugger::debugFile");
		names->add(DEBUGGERADDR(Debugger::debugLine), "Debugger::debugLine");
		names->add(DEBUGGERADDR(Debugger::_debugMethod), "Debugger::_debugMethod");
		#endif

		#if (defined DEBUGGER || defined FEATURE_SAMPLER )
		names->add(ENVADDR(MethodEnv::debugEnter), "MethodEnv::debugEnter");
		names->add(ENVADDR(MethodEnv::debugExit), "MethodEnv::debugExit");
		names->add(COREADDR(AvmCore::sampleCheck), "AvmCore::sampleCheck");
		#endif

		names->add(FUNCADDR(AvmCore::atomWriteBarrier), "AvmCore::atomWriteBarrier");
		names->add(GCADDR(GC::writeBarrierRC), "GC::writeBarrierRC");
		names->add(GCADDR(GC::WriteBarrierTrap), "GCADDR(GC::WriteBarrierTrap)");

		// type -> atom conversions
		names->add(COREADDR(AvmCore::intToAtom), "AvmCore::intToAtom");
		names->add(COREADDR(AvmCore::doubleToAtom), "AvmCore::doubleToAtom");
		names->add(COREADDR(AvmCore::uintToAtom), "AvmCore::uintToAtom");

		// atom -> type conversions
		names->add(COREADDR(AVMCORE_integer), "AVMCORE_integer");
		names->add(FUNCADDR(AVMCORE_integer_i), "AVMCORE_integer_i");
		names->add(FUNCADDR(AVMCORE_integer_d), "AVMCORE_integer_d");
#if defined(AVMPLUS_IA32) || defined(AVMPLUS_AMD64)
		names->add(FUNCADDR(AVMCORE_integer_d_sse2), "AVMCORE_integer_d_sse2");
#endif // defined(AVMPLUS_IA32) || defined(AVMPLUS_AMD64)

#ifdef AVMPLUS_64BIT
		names->add(COREADDR(AvmCore::integer), "AvmCore::integer");
		names->add(FUNCADDR(AvmCore::integer_i), "AvmCore::integer_i");
		names->add(FUNCADDR(AvmCore::integer_d), "AvmCore::integer_d");
		names->add(FUNCADDR(AvmCore::integer_d_sse2), "AvmCore::integer_d_sse2");
#endif // AVMPLUS_64BIT

		names->add(FUNCADDR(AvmCore::number_d), "AvmCore::number_d");
		names->add(COREADDR(AvmCore::number), "AvmCore::number");
		names->add(FUNCADDR(AvmCore::integer_u), "AvmCore::integer_u");
		names->add(COREADDR(AvmCore::string), "AvmCore::string");
		names->add(COREADDR(AvmCore::intToString), "AvmCore::intToString");
		names->add(COREADDR(AvmCore::uintToString), "AvmCore::uintToString");
		names->add(COREADDR(AvmCore::doubleToString), "AvmCore::doubleToString");
		names->add(COREADDR(AvmCore::coerce_s), "AvmCore::coerce_s");
		names->add(COREADDR(AvmCore::ToXMLString), "AvmCore::ToXMLString");
		names->add(COREADDR(AvmCore::boolean), "AvmCore::boolean");

		// operator helpers
		names->add(COREADDR(AvmCore::concatStrings), "AvmCore::concatStrings");
		names->add(TOPLEVELADDR(Toplevel::toVTable), "Toplevel::toVTable");
		names->add(ENVADDR(MethodEnv::newfunction), "MethodEnv::newfunction");
		names->add(ENVADDR(MethodEnv::newclass), "MethodEnv::newclass");
		names->add(ENVADDR(MethodEnv::findproperty), "MethodEnv::findproperty");
		names->add(TOPLEVELADDR(Toplevel::op_call), "Toplevel::op_call");
		names->add(TOPLEVELADDR(Toplevel::op_construct), "Toplevel::op_construct");
		names->add(TOPLEVELADDR(Toplevel::callproperty), "Toplevel::callproperty");
		names->add(TOPLEVELADDR(Toplevel::constructprop), "Toplevel::constructprop");
		names->add(ENVADDR(MethodEnv::callsuper), "MethodEnv::callsuper");
		names->add(ENVADDR(MethodEnv::op_newobject), "MethodEnv::op_newobject");
		names->add(SCRIPTADDR(ArrayClass::newarray), "ArrayClass::newarray");
		names->add(ENVADDR(MethodEnv::createRestHelper), "MethodEnv::createRestHelper");
		names->add(ENVADDR(MethodEnv::getpropertyHelper), "MethodEnv::getpropertyHelper");
		names->add(ENVADDR(MethodEnv::setpropertyHelper), "MethodEnv::setpropertyHelper");
		names->add(ENVADDR(MethodEnv::initpropertyHelper), "MethodEnv::initpropertyHelper");
		names->add(COREADDR(AvmCore::initMultinameLate), "AvmCore::initMultinameLate");
		names->add(ENVADDR(MethodEnv::initMultinameLateForDelete), "MethodEnv::initMultinameLateForDelete");
		names->add(ENVADDR(MethodEnv::newcatch), "MethodEnv::newcatch");
		names->add(ENVADDR(MethodEnv::createArgumentsHelper), "MethodEnv::createArgumentsHelper");
		names->add(FUNCADDR(CodegenMIR::coerce_o), "CodegenMIR::coerce_o");
#ifdef AVMPLUS_ARM
		names->add(FUNCADDR(CodegenMIR::fadd), "CodegenMIR::fadd");
		names->add(FUNCADDR(CodegenMIR::fsub), "CodegenMIR::fsub");
		names->add(FUNCADDR(CodegenMIR::fmul), "CodegenMIR::fmul");
		names->add(FUNCADDR(CodegenMIR::fdiv), "CodegenMIR::fdiv");
		names->add(FUNCADDR(CodegenMIR::fcmp), "CodegenMIR::fcmp");		
		names->add(FUNCADDR(CodegenMIR::i2d), "CodegenMIR::i2d");
		names->add(FUNCADDR(CodegenMIR::u2d), "CodegenMIR::u2d");								
#endif /* AVMPLUS_ARM */
#if defined AVMPLUS_PPC || defined AVMPLUS_SPARC
		names->add(FUNCADDR(CodegenMIR::stackOverflow), "CodegenMIR::stackOverflow");
#endif /* AVMPLUS_PPC */
		names->add(FUNCADDR(MathUtils::mod), "MathUtils::mod");
		names->add(COREADDR(AvmCore::newPublicNamespace), "AvmCore::newPublicNamespace");

#if defined(AVMPLUS_IA32) || defined(AVMPLUS_AMD64)
		names->add(COREADDR(AvmCore::doubleToAtom_sse2), "AvmCore::doubleToAtom_sse2");
#endif
		names->add(ENVADDR (MethodEnv::finddef), "MethodEnv::finddef");
		names->add(ENVADDR (MethodEnv::finddefNsset), "MethodEnv::finddefNsset");
		names->add(ENVADDR (MethodEnv::finddefNs), "MethodEnv::finddefNs");
		names->add(COREADDR(AvmCore::_typeof), "AvmCore::_typeof");
		names->add(COREADDR(AvmCore::throwAtom), "AvmCore::throwAtom");
		names->add(ENVADDR(MethodEnv::getsuper), "MethodEnv::getsuper");
		names->add(ENVADDR(MethodEnv::setsuper), "MethodEnv::setsuper");
		names->add(ENVADDR(MethodEnv::nextname), "MethodEnv::nextname");
		names->add(ENVADDR(MethodEnv::nextvalue), "MethodEnv::nextvalue");
		names->add(ENVADDR(MethodEnv::hasnext), "MethodEnv::hasnext");
		names->add(ENVADDR(MethodEnv::hasnextproto), "MethodEnv::hasnextproto");
		names->add(ENVADDR(MethodEnv::getdescendants), "MethodEnv::getdescendants");
		names->add(ENVADDR(MethodEnv::getdescendantslate), "MethodEnv::getdescendantslate");
		names->add(TOPLEVELADDR(Toplevel::setproperty), "Toplevel::setproperty");
		names->add(ENVADDR(MethodEnv::initproperty), "MethodEnv::initproperty");
		names->add(ENVADDR(MethodEnv::setpropertylate_i), "MethodEnv::setpropertylate_i");
		names->add(ENVADDR(MethodEnv::setpropertylate_u), "MethodEnv::setpropertylate_u");
		names->add(COREADDR(AvmCore::equals), "AvmCore::equals");
		names->add(COREADDR(AvmCore::stricteq), "AvmCore::stricteq");
		names->add(COREADDR(AvmCore::compare), "AvmCore::compare");
		names->add(TOPLEVELADDR(Toplevel::add2), "Toplevel::add2");
		names->add(COREADDR(AvmCore::intern), "AvmCore::intern");
		names->add(ENVADDR(MethodEnv::internRtns), "MethodEnv::internRtns");
		names->add(TOPLEVELADDR(Toplevel::coerce), "Toplevel::coerce");
		names->add(TOPLEVELADDR(Toplevel::coerceobj), "Toplevel::coerceobj");
		names->add(ENVADDR(MethodEnv::coerceAtom2SO), "MethodEnv::coerceAtom2SO");
		names->add(COREADDR(AvmCore::toUInt32), "AvmCore::toUInt32");
		names->add(COREADDR(AvmCore::istypeAtom), "AvmCore::istypeAtom");

		names->add(COREADDR(AvmCore::astype), "AvmCore::astype");
		names->add(TOPLEVELADDR(Toplevel::instanceof), "Toplevel::instanceof");
		names->add(TOPLEVELADDR(Toplevel::getproperty), "Toplevel::getproperty");
		names->add(ARRAYADDR(ArrayObject::_getUintProperty), "ArrayObject::_getUintProperty");
		names->add(ARRAYADDR(ArrayObject::_getIntProperty), "ArrayObject::_getIntProperty");
		names->add(ARRAYADDR(ArrayObject::_setUintProperty), "ArrayObject::_setUintProperty");
		names->add(ARRAYADDR(ArrayObject::_setIntProperty), "ArrayObject::_setIntProperty");
		names->add(ENVADDR(MethodEnv::getpropertylate_i), "MethodEnv::getpropertylate_i");
		names->add(ENVADDR(MethodEnv::getpropertylate_u), "MethodEnv::getpropertylate_u");
		names->add(ENVADDR(MethodEnv::npe), "MethodEnv::npe");
		names->add(ENVADDR(MethodEnv::nullcheck), "MethodEnv::nullcheck");
		names->add(ENVADDR(MethodEnv::interrupt), "MethodEnv::interrupt");
		names->add(TOPLEVELADDR(Toplevel::toClassITraits), "Toplevel::toClassITraits");
		names->add(COREADDR(AvmCore::newObject), "AvmCore::newObject");
		names->add(ENVADDR(MethodEnv::newActivation), "MethodEnv::newActivation");
		names->add(ENVADDR(MethodEnv::delproperty), "MethodEnv::delproperty");
		names->add(ENVADDR(MethodEnv::delpropertyHelper), "MethodEnv::delpropertyHelper");
		names->add(TOPLEVELADDR(Toplevel::in_operator), "Toplevel::in_operator");

		// exception handling
		names->add(COREADDR(AvmCore::beginCatch), "AvmCore::beginCatch");
		names->add(EFADDR(ExceptionFrame::beginTry), "ExceptionFrame::beginTry");
		names->add(EFADDR(ExceptionFrame::endTry), "ExceptionFrame::endTry");
		names->add(SETJMP, "setjmp");

		// Vector support
		names->add(VECTORDOUBLEADDR(DoubleVectorObject::_getNativeIntProperty), "DoubleVectorObject::_getNativeIntProperty");
		names->add(VECTORINTADDR(IntVectorObject::_getNativeIntProperty), "IntVectorObject::_getNativeIntProperty");
		names->add(VECTORUINTADDR(UIntVectorObject::_getNativeIntProperty), "UIntVectorObject::_getNativeIntProperty");
		names->add(VECTORDOUBLEADDR(DoubleVectorObject::_getNativeUintProperty), "DoubleVectorObject::_getNativeUintProperty");
		names->add(VECTORINTADDR(IntVectorObject::_getNativeUintProperty), "IntVectorObject::_getNativeUintProperty");
		names->add(VECTORUINTADDR(UIntVectorObject::_getNativeUintProperty), "UIntVectorObject::_getNativeUintProperty");

		names->add(VECTOROBJADDR(ObjectVectorObject::_getIntProperty), "ObjectVectorObject::_getIntProperty");
		names->add(VECTOROBJADDR(ObjectVectorObject::_getUintProperty), "ObjectVectorObject::_getUintProperty");
		names->add(VECTOROBJADDR(ObjectVectorObject::_setIntProperty), "ObjectVectorObject::_setIntProperty");
		names->add(VECTOROBJADDR(ObjectVectorObject::_setUintProperty), "ObjectVectorObject::_setUintProperty");

		names->add(VECTORDOUBLEADDR(DoubleVectorObject::_setNativeIntProperty), "DoubleVectorObject::_setNativeIntProperty");
		names->add(VECTORINTADDR(IntVectorObject::_setNativeIntProperty), "IntVectorObject::_getNativeIntProperty");
		names->add(VECTORUINTADDR(UIntVectorObject::_setNativeIntProperty), "UIntVectorObject::_setNativeIntProperty");
		names->add(VECTORDOUBLEADDR(DoubleVectorObject::_setNativeUintProperty), "DoubleVectorObject::_setNativeUintProperty");
		names->add(VECTORINTADDR(IntVectorObject::_setNativeUintProperty), "IntVectorObject::_setNativeUintProperty");
		names->add(VECTORUINTADDR(UIntVectorObject::_setNativeUintProperty), "UIntVectorObject::_setNativeUintProperty");
		names->add(TOPLEVELADDR(Toplevel::op_applytype), "Toplevel::op_applytype");

		names->add(CLASSCLOSUREADDR(ClassClosure::newInstance), "ClassClosure::newInstance");

		names->add(ENVADDR(MethodEnv::checkfilter), "MethodEnv::checkfilter");
		names->add(COREADDR(AvmCore::EscapeAttributeValue), "AvmCore::EscapeAttributeValue");

		return names;
	}
#endif

	Atom CodegenMIR::coerce_o(Atom v)
	{
		return v == undefinedAtom ? nullObjectAtom : v;
	}

#if defined AVMPLUS_PPC || defined AVMPLUS_SPARC
	// This helper function exists only on PowerPC in order to
	// minimize the code size of generated stack overflow checks.
	// It is static and takes only one parameter, env.
	// The env parameter goes into R3, which is where it also goes
	// in a JIT-ted function's method signature (env, argc, ap)
	// This enables us to not move any registers around.
	void CodegenMIR::stackOverflow(MethodEnv *env)
	{
		env->core()->stackOverflow(env);		
	}
#endif

#ifdef AVMPLUS_ARM
	double CodegenMIR::fadd(double x, double y)
	{
		return x+y;
	}
	
	double CodegenMIR::fsub(double x, double y)
	{
		return x-y;
	}

	double CodegenMIR::fmul(double x, double y)
	{
		return x*y;
	}

	double CodegenMIR::fdiv(double x, double y)
	{
		return x/y;
	}
	
	int   CodegenMIR::fcmp(double x, double y)
	{
		if (x<y)
		{
			return -1;
		}
		else if (x>y)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
	double CodegenMIR::i2d(int i)
	{
		return (double)i;
	}
	
	double CodegenMIR::u2d(uint32 i)
	{
		return (double)i;
	}
#endif /* AVMPLUS_ARM */

#ifndef FEATURE_BUFFER_GUARD
	bool CodegenMIR::checkOverflow()
	{
		if (overflow)
			return overflow;

		// if this fails, we aren't estimating a big enough space for MIR
		uintptr curSize = (uintptr)ip-(uintptr)ipStart;
		if (curSize >= mirBuffSize)
		{
			// start over with bigger buffer.
			expansionFactor *= 2;
			overflow = true;
		}
		return overflow;
	}
#endif

	OP* CodegenMIR::atomToNativeRep(Traits* t, OP* atom)
	{
		if (!t || t == OBJECT_TYPE || t == VOID_TYPE)
		{
			return atom;
		}
		else if (t == NUMBER_TYPE)
		{
			if (atom->code == MIR_imm) {
				Atom a = atom->imm;
				if (AvmCore::isDouble(a)) {
					return loadIns(MIR_fldop, a&~7, 0);
				} else {
					AvmAssert(AvmCore::isInteger(a));
					return i2dIns(InsConst(a>>3));
				}
			} else {
				return callIns(MIR_fcsop, FUNCADDR(AvmCore::number_d), 1, atom);
			}
		}
		else if (t == INT_TYPE)
		{
			if (atom->code == MIR_imm)
				return InsConst(AVMCORE_integer_i(atom->imm));
			else
				return callIns(MIR_csop, FUNCADDR(AVMCORE_integer_i), 1, atom);
		}
		else if (t == UINT_TYPE)
		{
			if (atom->code == MIR_imm)
				return InsConst(AvmCore::integer_u(atom->imm));
			else
				return callIns(MIR_csop, FUNCADDR(AvmCore::integer_u), 1, atom);
		}
		else if (t == BOOLEAN_TYPE)
		{
			if (atom->code == MIR_imm)
				return InsConst(urshift(atom->imm,3));
			else
				return binaryIns(MIR_ush, atom, InsConst(3));
		}
		else
		{
			// pointer type
			if (atom->code == MIR_imm)
				return InsConst(atom->imm & ~7);
			else
				return binaryIns(MIR_andp, atom, InsConst(uintptr(~7)));
		}
		
#ifdef __GNUC__
		return 0;	// satisfy GCC, although we should never get here
#endif
	}

	// f(env, argc, instance, argv)
	bool CodegenMIR::prologue(FrameState* state)
	{
		this->state = state;
		if (overflow) return false;

		abcStart = state->verifier->code_pos;
		abcEnd   = abcStart + state->verifier->code_length;

		#ifdef AVMPLUS_SPARC
		// we count maxArgCount in doubles.
		// 3 covers O0-O5. This is really a waste of stack.
		maxArgCount = 3;
		#elif defined AVMPLUS_PPC
		// On PowerPC, maxArgCount should initially be 4,
		// because any varargs routine will immediately
		// store r3...r10 into the PPC callee area.
		// So, the callee area must always be big enough
		// to accomodate r3...r10.
		// Because we count maxArgCount in doubles, 4 is
		// sufficient to cover r3...r10.
		maxArgCount = 4;
		#else
		maxArgCount = 0;
		#endif

		// buffer is empty reserve some space in it
		overflow = false;
		if (mirBuffer->size() == 0)
			mirBuffer->reserve(expansionFactor * mir_buffer_reserve_size);

#ifndef FEATURE_BUFFER_GUARD 
		// if we aren't growing the buffer dynamically then commit a whole bunch of it
		mirBuffSize = sizeof(OP) * (40*expansionFactor*(abcEnd-abcStart)) + epilogue_size + prologue_size;  // MIR instructions
		mirBuffSize = BIT_ROUND_UP(mirBuffSize, mirBuffer->pageSize());
		mirBuffer->growBy(mirBuffSize);
#endif /* FEATURE_BUFFER_GUARD */

		case_count = 0;

		// reset to start of buffer
		ipStart = (OP*) mirBuffer->getPos();
		if (!ipStart)
		{
			overflow = true;
			return false;
		}

		// align the start of the buffer to OP and get ready to generate mir
		ip = ipStart = (OP*) BIT_ROUND_UP(ipStart, sizeof(OP));

		// reset the cse engine
		memset(cseTable, 0, sizeof(OP*)*MIR_last);
		firstCse = ip;

		// instruction # of last function call
		lastFunctionCall = 0;

		// last pc value that we generated a store for 
		lastPcSave = 0;

#if HAVE_MIR_SMOPS
		// last jmp address of a memory range check
		lastMOPRangeCheckJmp = 0;
#endif
		//
		// mir to define incoming method arguments.  Stack 
		// frame allocations follow.
		//

		#ifdef AVMPLUS_VERBOSE
		if (verbose())
			core->console << "    define incoming args\n";
		#endif

		#ifdef AVMPLUS_IA32
		// callee saved args
		calleeVars = defineArgInsReg(EBX);
		            defineArgInsReg(ESI);
		            defineArgInsReg(EDI);
		// incoming args either in a register or stack position relative to stack on entry
		methodArgs = defineArgInsPos(4);
					 defineArgInsPos(8);
					 defineArgInsPos(12);
        #endif /* AVMPLUS_IA32 */

		#ifdef AVMPLUS_AMD64
		#ifdef _WIN64
		calleeVars = defineArgInsReg(R12);
					defineArgInsReg(R13);
					defineArgInsReg(R14);
					defineArgInsReg(R15);
					defineArgInsReg(RDI);
					defineArgInsReg(RSI);
					defineArgInsReg(RBX);
		methodArgs = defineArgInsReg(RCX);
					defineArgInsReg(RDX);
					defineArgInsReg(R8);
					defineArgInsReg(R9);
		#else
		// 64bit - non Windows...completely wrong
		// callee saved args
		calleeVars = defineArgInsReg(R12);
		             defineArgInsReg(R13);
		             defineArgInsReg(R14);
		             defineArgInsReg(R15);
		             defineArgInsReg(RBX);
		methodArgs = defineArgInsReg(RDI);
					 defineArgInsReg(RSI);
					 defineArgInsReg(RDX);
					 defineArgInsReg(RCX);
					 defineArgInsReg(R8);
					 defineArgInsReg(R9);
		#endif	/* _WIN64 */
        #endif /* AVMPLUS_AMD64 */

		#ifdef AVMPLUS_SPARC
		calleeVars = NULL;
		methodArgs = defineArgInsReg(I0);
					 defineArgInsReg(I1);
					 defineArgInsReg(I2);
		#endif /* AVMPLUS_SPARC */

        #ifdef AVMPLUS_PPC
		calleeVars = NULL;
		methodArgs = defineArgInsReg(R3);
					 defineArgInsReg(R4);
					 defineArgInsReg(R5);
		#endif /* AVMPLUS_PPC */

		#ifdef AVMPLUS_ARM
		calleeVars = NULL;
		methodArgs = defineArgInsReg(R0);
					 defineArgInsReg(R1);
					 defineArgInsReg(R2);
        #endif
					 
		#ifdef DEBUGGER
		#ifdef AVMPLUS_VERBOSE
		if (verbose())
			core->console << "    alloc local traits\n";
		#endif
		#endif //DEBUGGER
		
		#ifdef DEBUGGER
		// pointers to traits so that the debugger can decode the locals
		// IMPORTANT don't move this around unless you change MethodInfo::boxLocals()
		localTraits = InsAlloc(state->verifier->local_count * sizeof(Traits*));
		localPtrs = InsAlloc((state->verifier->local_count + state->verifier->max_scope) * sizeof(void*));
		#endif //DEBUGGER | FEATURE_SAMPLER

		// whether this sequence is interruptable or not.
		interruptable = (info->flags & AbstractFunction::NON_INTERRUPTABLE) ? false : true;
		
		// then space for the exception frame, be safe if its an init stub
		if (info->isFlagSet(AbstractFunction::HAS_EXCEPTIONS))
		{
			#ifdef AVMPLUS_VERBOSE
			if (verbose())
				core->console << "    alloc exception frame\n";
			#endif
			// [_save_eip][ExceptionFrame]
			// offsets of local vars, rel to current ESP
			_save_eip = InsAlloc(sizeof(byte*));
			_ef       = InsAlloc(sizeof(ExceptionFrame));
		}

		if (info->setsDxns())
		{
			#ifdef AVMPLUS_VERBOSE
			if (verbose())
				core->console << "    alloc saved dxns\n";
			#endif

			dxns = InsAlloc(sizeof(Namespace*));
		}

		#ifdef DEBUGGER
		#ifdef AVMPLUS_VERBOSE
		if (verbose())
			core->console << "    alloc CallStackNode\n";
		#endif
		#endif

		#if (defined DEBUGGER || defined FEATURE_SAMPLER)
		// Allocate space for the call stack
		_callStackNode = InsAlloc(sizeof(CallStackNode));
		#endif
		
		if (info->setsDxns())
		{
			#ifdef AVMPLUS_VERBOSE
			if (verbose())
				core->console << "    init dxns\n";
			#endif

			// dxns = env->vtable->scope->defaultXmlNamespace
			OP* declVTable = loadIns(MIR_ldop, offsetof(MethodEnv, vtable), ldargIns(_env));
			OP* scope = loadIns(MIR_ldop, offsetof(VTable, scope), declVTable);
			OP* capturedDxns = loadIns(MIR_ldop, offsetof(ScopeChain, defaultXmlNamespace), scope);
			storeIns(capturedDxns, 0, dxns);

			// dxnsSave = AvmCore::dxnsAddr
			dxnsAddrSave = loadIns(MIR_ldop, offsetof(AvmCore, dxnsAddr), InsConst((uintptr)core));
		}

		for (int i=0, n = state->verifier->stackBase+state->stackDepth; i < n; i++)
		{
			Value& v = state->value(i);
			v.ins = 0;
			v.stored = false;
		}

		//
		// copy args to local frame
		//

		// copy required args, and initialize optional args.
		// this whole section only applies to functions that actually
		// have arguments.

		OP* apArg = ldargIns(_ap);
		if (info->flags & AbstractFunction::HAS_OPTIONAL)
		{
			#ifdef AVMPLUS_VERBOSE
			if (verbose())
				core->console << "    required and optional args\n";
			#endif

			// compute offset of first optional arg
			int offset = 0;
			for (int i=0, n=info->param_count-info->optional_count; i <= n; i++)
			{
				if (info->paramTraits(i) == NUMBER_TYPE)
				{
					offset += 8;
				}
				else
				{
#ifdef AVMPLUS_64BIT
					offset += 8;
#else
					offset += 4;
#endif
				}
			}

			// now copy the default optional values
			OP* argcarg = ldargIns(_argc);
			for (int i=0, n=info->optional_count; i < n; i++)
			{
				// first set the local[p+1] = defaultvalue
				int param = i + info->param_count - info->optional_count; // 0..N
				int loc = param+1;

				#ifdef AVMPLUS_VERBOSE
				if (verbose())
					core->console << "    init optional param " << loc << "\n";
				#endif

				OP* defaultVal = InsConst(info->getDefaultValue(i));
				defaultVal = defIns(atomToNativeRep(loc, defaultVal));
				
				// then generate: if (argc > p) local[p+1] = arg[p+1]
				OP* cmp = binaryIns(MIR_icmp, argcarg, InsConst((int32)param));
				OP* br = Ins(MIR_jle, cmp); // will patch
				OP* arg;
				if (isDouble(loc))
				{
					arg = loadIns(MIR_fldop, offset, apArg);
					offset += 8;
				}
				else
				{
					arg = loadIns(MIR_ldop, offset, apArg);
#ifdef AVMPLUS_64BIT
					offset += 8;
#else
					offset += 4;
#endif
				}
				arg = defIns(arg);
				arg->join = defaultVal;
				localSet(loc, defaultVal);

				br->target = Ins(MIR_bb);

				firstCse = ip;
			}
		}
		else
		{
			// !HAS_OPTIONAL
			AvmAssert(info->optional_count == 0);
		}

		// now set up the required args (we can ignore argc)
		// for (int i=0, n=param_count; i <= n; i++)
		//     framep[i] = argv[i];
		int offset = 0;
		for (int i=0, n=info->param_count-info->optional_count; i <= n; i++)
		{
			#ifdef AVMPLUS_VERBOSE
			if (verbose())
				core->console << "    param " << i << "\n";
			#endif
			Traits* t = info->paramTraits(i);
			OP* arg; 
			if (t == NUMBER_TYPE)
			{
				arg = loadIns(MIR_fldop, offset, apArg);
				localSet(i, arg);
				offset += 8;
			}
			else
			{
				arg = loadIns(MIR_ldop, offset, apArg);
				localSet(i, arg);
#ifdef AVMPLUS_AMD64
				offset += 8;
#else
				offset += 4;
#endif
			}
		}

		if (info->flags & AbstractFunction::UNBOX_THIS)
		{
			localSet(0, atomToNativeRep(0, localGet(0)));
		}

		int firstLocal = 1+info->param_count;

		// capture remaining args
		if (info->flags & AbstractFunction::NEED_REST)
		{
			#ifdef AVMPLUS_VERBOSE
			if (verbose())
				core->console << "    create rest\n";
			#endif

			//framep[info->param_count+1] = createRest(env, argv, argc);
			OP* argcArg = ldargIns(_argc);
			OP* apArg = ldargIns(_ap);

			// use csop so if rest value never used, we don't bother creating array
			OP* rest = callIns(MIR_cmop, ENVADDR(MethodEnv::createRestHelper), 3, 
				ldargIns(_env), argcArg, apArg);

			localSet(firstLocal, rest);
			firstLocal++;
		}
		else if (info->flags & AbstractFunction::NEED_ARGUMENTS)
		{
			#ifdef AVMPLUS_VERBOSE
			if (verbose())
				core->console << "    create arguments\n";
			#endif

			//framep[info->param_count+1] = createArguments(env, argv, argc);
			OP* argcArg = ldargIns(_argc);
			OP* apArg = ldargIns(_ap);

			// use csop so if arguments never used, we don't create it
			OP* arguments = callIns(MIR_cmop, ENVADDR(MethodEnv::createArgumentsHelper), 3, 
				ldargIns(_env), argcArg, apArg);

			localSet(firstLocal, arguments);
			firstLocal++;
		}

		undefConst = InsConst(undefinedAtom);
		if (firstLocal < state->verifier->local_count)
		{
			// set remaining locals to undefined
			for (int i=firstLocal, n=state->verifier->local_count; i < n; i++)
			{
				if(!(state->value(i).traits == NULL)){ // expecting *
 					AvmAssertMsg(0,"(state->value(i).traits != NULL)");
 					return false; // fail verify
 				}
				localSet(i, undefConst);
			}
		}

		#ifdef DEBUGGER

		for (int i=state->verifier->scopeBase; i<state->verifier->scopeBase+state->verifier->max_scope; ++i)
		{
			localSet(i, undefConst);
		}

		#ifdef AVMPLUS_VERBOSE
		if (verbose())
			core->console << "    debug_enter\n";
		#endif

		callIns(MIR_cm, ENVADDR(MethodEnv::debugEnter), 8,
			ldargIns(_env), ldargIns(_argc), ldargIns(_ap), // for sendEnter
			leaIns(0, localTraits), InsConst(state->verifier->local_count), // for clearing traits pointers
			leaIns(0, _callStackNode), 
			leaIns(0, localPtrs),
			info->hasExceptions() ? leaIns(0, _save_eip) : InsConst(0)
			);
		#else
		#ifdef FEATURE_SAMPLER
		callIns(MIR_cm, ENVADDR(MethodEnv::debugEnter), 8,
			ldargIns(_env), ldargIns(_argc), ldargIns(_ap), // for sendEnter
			InsConst(0), InsConst(state->verifier->local_count), // for clearing traits pointers
			leaIns(0, _callStackNode), 
			InsConst(0),
			info->hasExceptions() ? leaIns(0, _save_eip) : InsConst(0)
			);
		#endif
		#endif // DEBUGGER


		if (info->isFlagSet(AbstractFunction::HAS_EXCEPTIONS))
		{
			#ifdef AVMPLUS_VERBOSE
			if (verbose())
				core->console << "    exception setup\n";
			#endif

			// _ef.beginTry(core);
			callIns(MIR_cm, EFADDR(ExceptionFrame::beginTry), 2,
				leaIns(0,_ef), InsConst((uintptr)core));

			// spill prior to jmp so that our stack is cleared of 
			// any transient locals.
			saveState();

			// force the locals to be clean for the setjmp call
			Ins(MIR_bb);
			firstCse = ip;
			
			// Exception* _ee = setjmp(_ef.jmpBuf);
			// ISSUE this needs to be a cdecl call
			OP* jmpbuf = leaIns(offsetof(ExceptionFrame, jmpbuf), _ef);
#if defined(AVMPLUS_AMD64) && !defined(_WIN64)
			OP* ei = callIns(MIR_cs, SETJMP, 2, jmpbuf, InsConst(0));
			OP* ee = loadIns(MIR_ld, (uintptr)&ExceptionFrame::lptr, ei);
#else //#if defined(AVMPLUS_AMD64) && !defined(_WIN64)
			OP* ee = callIns(MIR_cs, SETJMP, 2,
				jmpbuf, InsConst(0));
#endif // #if defined(AVMPLUS_AMD64) && !defined(_WIN64)

#ifdef AVMPLUS_SPARC
			beginCatch_start = ee;
#endif

			// if (setjmp() == 0) goto start
			OP* cond = binaryIns(MIR_ucmp, ee, InsConst(0));
			OP* exBranch = Ins(MIR_jeq, cond);

			// exception case
			exAtom = loadIns(MIR_ld, offsetof(Exception, atom), ee);
			// need to convert exception from atom to native rep, at top of 
			// catch handler.  can't do it here because it could be any type.

			// _ef.beginCatch()
			// ISSUE why do we have to redefine ef? it is NULL when exception happens
			OP* pc = loadIns(MIR_ld, 0, _save_eip);
			OP* handler = callIns(MIR_cm, COREADDR(AvmCore::beginCatch), 5,
				InsConst((uintptr)core), leaIns(0,_ef), InsConst((uintptr)info), pc, ee);

#ifdef AVMPLUS_SPARC
			beginCatch_end = handler;
#endif

			// jump to catch handler
			Ins(MIR_jmpi, handler, (int32)offsetof(ExceptionHandler, target));

			// target of conditional
			exBranch->target = Ins(MIR_bb);

			// don't want cse's to live past indirect jumps
			firstCse = ip;
		}

		// If interrupts are enabled, generate an interrupt check.
		// This ensures at least one interrupt check per method.
		if (interruptable && core->config.interrupts)
		{
			if (state->insideTryBlock)
				storeIns(InsConst(state->pc), 0, _save_eip);

			OP* interrupted = loadIns(MIR_ld, (uintptr)&core->interrupted, NULL);
			OP* br = Ins(MIR_jne, binaryIns(MIR_ucmp, interrupted, InsConst(0)));
			mirPatchPtr(&br->target, interrupt_label);
		}

		InsAlloc(0);

		return true;
	}

	void CodegenMIR::emitCopy(FrameState* state, int src, int dest)
	{
		this->state = state;
		// local[dest] = local[src]
		localSet(dest, localGet(src));
	}

	void CodegenMIR::emitGetscope(FrameState* state, int scope_index, int dest)
	{
		this->state = state;
		Traits* t = info->declaringTraits->scope->getScopeTraitsAt(scope_index);
		OP* declVTable = loadIns(MIR_ldop, offsetof(MethodEnv, vtable), ldargIns(_env));
		OP* scope = loadIns(MIR_ldop, offsetof(VTable, scope), declVTable);
		OP* scopeobj = loadIns(MIR_ldop, offsetof(ScopeChain, scopes) + scope_index*sizeof(Atom), scope);
		localSet(dest, atomToNativeRep(t, scopeobj));
	}

	void CodegenMIR::emitSwap(FrameState* state, int i, int j)
	{
		this->state = state;
		OP* a = localGet(i);
		OP* b = localGet(j);
		localSet(i, b);
		localSet(j, a);
	}

	void CodegenMIR::emitKill(FrameState* state, int i)
	{
		this->state = state;
		localSet(i, undefConst);
	}

	void CodegenMIR::emitSetContext(FrameState *state, AbstractFunction *f)
	{
		this->state = state;
		//
		// initialize the code context
		//
		if (isCodeContextChanged())
		{
 			if (!f || f->usesCallerContext())
			{
				#ifdef AVMPLUS_VERBOSE
				if (verbose())
					core->console << "        	set code context\n";
				#endif

				// core->codeContext = env;
				storeIns(ldargIns(_env), (uintptr)&core->codeContextAtom, 0);
			}

			if (!f || f->usesDefaultXmlNamespace())
			{
				emitSetDxns(state);

				// used to dump all functions that still say they required DXNS code
				#if 0//def _DEBUG
				if (f && (f->flags & AbstractFunction::NATIVE))
				{
					StringBuffer buffer(core);		
					const wchar *foo = f->name->c_str();
					buffer << "function is:" << foo << "\r\n";

					AvmDebugMsg (false, buffer.c_str());
					//core->console << " f->
				}
				#endif
			}
		}
	}

	void CodegenMIR::emitSetDxns(FrameState* state)
	{
		this->state = state;

		OP* dxnsAddr;

		#ifdef AVMPLUS_VERBOSE
		if (verbose())
			core->console << "        	set dxns addr\n";
		#endif
		if (info->isFlagSet(AbstractFunction::SETS_DXNS))
		{
			dxnsAddr = leaIns(0,dxns);
		}
		else
		{
			// dxnsAddr = &env->vtable->scope->defaultXmlNamespace
			OP* env = ldargIns(_env);
			OP* declVTable = loadIns(MIR_ldop, offsetof(MethodEnv, vtable), env);
			OP* scope = loadIns(MIR_ldop, offsetof(VTable, scope), declVTable);
			dxnsAddr = leaIns(offsetof(ScopeChain, defaultXmlNamespace), scope);
		}

		storeIns(dxnsAddr, (uintptr)&core->dxnsAddr, 0);
	}

	void CodegenMIR::merge(int, const Value& current, Value& target)
	{
		if (target.ins != current.ins)
		{
			AvmAssert(current.ins->code == target.ins->code);
			AvmAssert((target.ins->code&~MIR_float) == MIR_def);

			OP* t = target.ins;
			while (t->join)	t = t->join;

			OP* c = current.ins;
			while (c->join)	c = c->join;

			// t and c are both original defs now.  one needs to be joined
			// to the other based on which one came first.
			// lastUse is the end of the combined live range of all defs
			// we can see.

			if (c < t)
			{
				#ifdef AVMPLUS_VERBOSE
				if (verbose())
					core->console << "     f @" << InsNbr(t) << "->join = @" << InsNbr(c) << "\n";
				#endif

				t->join = c;
				if (t->lastUse > c->lastUse)
					c->lastUse = t->lastUse;
				t->lastUse = 0;
				target.ins = c;
			}
			else if (c > t)
			{
				#ifdef AVMPLUS_VERBOSE
				if (verbose())
					core->console << "     b @" << InsNbr(c) << "->join = @" << InsNbr(t) << "\n";
				#endif

				c->join = t;
				if (c->lastUse > t->lastUse)
					t->lastUse = c->lastUse;
				c->lastUse = 0;
			}
		}
	}


	void CodegenMIR::emitBlockStart(FrameState* state)
	{
		// our new extended BB now starts here, this means that any branch targets
		// should hit the next instruction our bb start instruction
		OP* bb = Ins(MIR_bb); // mark start of block
		firstCse = ip;

		// get a label for our block start and tie it to this location
		mirLabel(state->verifier->getFrameState(state->pc)->label, bb);

		lastFunctionCall = 0;  // reset location of last function call

		// If this is a backwards branch, generate an interrupt check.
		// current verifier state, includes tack pointer.
		if (interruptable && core->config.interrupts && state->targetOfBackwardsBranch)
		{
			if (state->insideTryBlock)
				storeIns(InsConst(state->pc), 0, _save_eip);

			OP* interrupted = loadIns(MIR_ld, (uintptr)&core->interrupted, NULL);
			OP* br = Ins(MIR_jne, binaryIns(MIR_ucmp, interrupted, InsConst(0)));
			mirPatchPtr(&br->target, interrupt_label);
		}
	}

	void CodegenMIR::emitBlockEnd(FrameState* state)
	{
		this->state = state;

#ifdef AVMPLUS_VERBOSE
		if (verbose())
			core->console << "       block end\n";
#endif

		// our eBB now terminates.  For all branch instructions we are
		// able to detect this situation and have already generated the 
		// correct spill code prior to the jump, only for the case where 
		// the pc is a target of a jump do we not know enough during emit() 
		// to do this.  The Verifier tracks this information and merges
		// the states across the various blocks generating this op prior
		// to the merge.  After this emit, we should receive an emitBlockStart()
		// from the Verifier.
		saveState();
	}

	void CodegenMIR::emitIntConst(FrameState* state, int index, uintptr c)
	{
		this->state = state;
		localSet(index, InsConst(c));
	}

	void CodegenMIR::emitDoubleConst(FrameState* state, int index, double* pd)
	{
		this->state = state;
		localSet(index, loadIns(MIR_fldop, (uintptr)pd, NULL));
	}

	void CodegenMIR::emitDoubleToInteger (int loc)
	{
	#if defined(AVMPLUS_IA32) || defined (AVMPLUS_AMD64)
		if (core->config.sse2)
		{
			// Not AVMCORE_integer_d_sse2 so we are sure we call the version that returns a 32-bit result
			localSet(loc, callIns(MIR_csop, FUNCADDR(AvmCore::integer_d_sse2), 1, localGet(loc)));
		}
		else
	#endif
		{
			localSet(loc, callIns(MIR_csop, FUNCADDR(AVMCORE_integer_d), 1, localGet(loc)));
		}
	}

	void CodegenMIR::emitCoerce(FrameState* state, int loc, Traits* result)
	{
		this->state = state;
		emitPrep(OP_coerce);

		Value& value = state->value(loc);
		Traits* in = value.traits;

		if (result == NULL)
		{
			// coerce to * is simple, we just save the atom rep.
			localSet(loc, loadAtomRep(loc));
		}
		else if (result == OBJECT_TYPE)
		{
			if (in == NULL || in == VOID_TYPE)
			{
				// value already boxed but we need to coerce undefined->null
				if (!value.notNull)
					localSet(loc, callIns(MIR_csop, FUNCADDR(CodegenMIR::coerce_o), 1,
										localGet(loc)));
			}
			else
			{
				// value cannot be undefined so just box it
				localSet(loc, loadAtomRep(loc));
			}
		}
		else if (!result->isMachineType() && in == NULL_TYPE)
		{
			// do nothing, it's fine to coerce null to a pointer type
		}
		else if (result == NUMBER_TYPE)
		{
			if (in && in->isNumeric() || in == BOOLEAN_TYPE)
			{
				localSet(loc, promoteNumberIns(in, loc));
			}
			else
			{
				// * -> Number
				localSet(loc, callIns(MIR_fcmop, COREADDR(AvmCore::number), 2,
					InsConst((uintptr)core), loadAtomRep(loc)));
			}
		}
		else if (result == INT_TYPE)
		{
			if (in == UINT_TYPE || in == BOOLEAN_TYPE)
			{
				//do nothing
			}
			else if (in == NUMBER_TYPE)
			{
				OP* ins = value.ins;
				if (ins != NULL && ins->code == MIR_fadd &&
					(ins->oprnd1->code == MIR_u2d || ins->oprnd1->code == MIR_i2d) &&
					(ins->oprnd2->code == MIR_u2d || ins->oprnd2->code == MIR_i2d))
				{
					// old: int(fadd(Number(int),Number(int)))
					// new: iadd(int,int)
					OP* orig = value.ins;
					localSet(loc, binaryIns(MIR_add, ins->oprnd1->oprnd1, ins->oprnd2->oprnd1));
					markDead(orig);
				}
				else if (ins != NULL && ins->code == MIR_fsub &&
					(ins->oprnd1->code == MIR_u2d || ins->oprnd1->code == MIR_i2d) &&
					(ins->oprnd2->code == MIR_u2d || ins->oprnd2->code == MIR_i2d))
				{
					OP* orig = value.ins;
					localSet(loc, binaryIns(MIR_sub, ins->oprnd1->oprnd1, ins->oprnd2->oprnd1));
					markDead(orig);
				}
				else if (ins != NULL && ins->code == MIR_fmul &&
					(ins->oprnd1->code == MIR_u2d || ins->oprnd1->code == MIR_i2d) &&
					(ins->oprnd2->code == MIR_u2d || ins->oprnd2->code == MIR_i2d))
				{
					OP* orig = value.ins;
					localSet(loc, binaryIns(MIR_imul, ins->oprnd1->oprnd1, ins->oprnd2->oprnd1));
					markDead(orig);
				}
				else if (ins != NULL && ((ins->code == MIR_i2d) || (ins->code == MIR_u2d)))
				{
					OP* orig = value.ins;
					localSet(loc, ins->oprnd1);
					markDead(orig);
				}
				else
				{
					emitDoubleToInteger (loc);
				}
			}
			else
			{
				// * -> int
				localSet(loc, callIns(MIR_cmop, COREADDR(AVMCORE_integer), 2,
					InsConst((uintptr)core), loadAtomRep(loc)));
			}
		}
		else if (result == UINT_TYPE)
		{
			if (in == INT_TYPE || in == BOOLEAN_TYPE)
			{
				//do nothing
			}
			else if (in == NUMBER_TYPE)
			{
				OP* ins = value.ins;
				if (ins != NULL && ins->code == MIR_fadd &&
					(ins->oprnd1->code == MIR_u2d || ins->oprnd1->code == MIR_i2d) &&
					(ins->oprnd2->code == MIR_u2d || ins->oprnd2->code == MIR_i2d))
				{
					// old: uint(fadd(Number(uint),Number(uint)))
					// new: iadd(int,int)
					OP* orig = value.ins;
					localSet(loc, binaryIns(MIR_add, ins->oprnd1->oprnd1, ins->oprnd2->oprnd1));
					markDead(orig);
				}
				else if (ins != NULL && ins->code == MIR_fsub &&
					(ins->oprnd1->code == MIR_u2d || ins->oprnd1->code == MIR_i2d) &&
					(ins->oprnd2->code == MIR_u2d || ins->oprnd2->code == MIR_i2d))
				{
					OP* orig = value.ins;
					localSet(loc, binaryIns(MIR_sub, ins->oprnd1->oprnd1, ins->oprnd2->oprnd1));
					markDead(orig);
				}
				else if (ins != NULL && ins->code == MIR_fmul &&
					(ins->oprnd1->code == MIR_u2d || ins->oprnd1->code == MIR_i2d) &&
					(ins->oprnd2->code == MIR_u2d || ins->oprnd2->code == MIR_i2d))
				{
					OP* orig = value.ins;
					localSet(loc, binaryIns(MIR_imul, ins->oprnd1->oprnd1, ins->oprnd2->oprnd1));
					markDead(orig);
				}
				else if (ins != NULL && ((ins->code == MIR_i2d) || (ins->code == MIR_u2d)))
				{
					OP* orig = value.ins;
					localSet(loc, ins->oprnd1);
					markDead(orig);
				}
				else
				{
					emitDoubleToInteger (loc);
				}
			}
			else
			{
				// * -> uint
				localSet(loc, callIns(MIR_cmop, COREADDR(AvmCore::toUInt32), 2,
					InsConst((uintptr)core), loadAtomRep(loc)));
			}
		}
		else if (result == BOOLEAN_TYPE)
		{
			if (in == NUMBER_TYPE)
			{
				localSet(loc, Ins(MIR_ne, binaryFcmpIns(
					localGet(loc), i2dIns(InsConst(0)))));
			}
			else if (in == INT_TYPE || in == UINT_TYPE || (in && !in->notDerivedObjectOrXML()))
			{
				localSet(loc, Ins(MIR_ne, binaryIns(MIR_icmp, 
					localGet(loc), InsConst(0))));
			}
			else
			{
				// * -> Boolean
				localSet(loc, callIns(MIR_cmop, COREADDR(AvmCore::boolean), 2,
					InsConst((uintptr)core), loadAtomRep(loc)));
			}
		}
		else if (result == STRING_TYPE)
		{
			if (in == INT_TYPE)
			{
				localSet(loc, callIns(MIR_cmop, COREADDR(AvmCore::intToString), 2,
					InsConst((uintptr)core), localGet(loc)));
			}
			else if (in == UINT_TYPE)
			{
				localSet(loc, callIns(MIR_cmop, COREADDR(AvmCore::uintToString), 2,
					InsConst((uintptr)core), localGet(loc)));
			}
			else if (in == NUMBER_TYPE)
			{
				localSet(loc, callIns(MIR_cmop, COREADDR(AvmCore::doubleToString), 2,
					InsConst((uintptr)core), localGet(loc)));
			}
#ifndef AVMPLUS_64BIT // can't do this because core->booleanString is a 64-bit value
			else if (in == BOOLEAN_TYPE)
			{
				// load "true" or "false"
#ifdef AVMPLUS_64BIT
				OP *index = binaryIns(MIR_lsh, localGet(loc), InsConst(3));
#else
				OP *index = binaryIns(MIR_lsh, localGet(loc), InsConst(2));
#endif
				localSet(loc, loadIns(MIR_ldop, (uintptr)&core->booleanStrings, index));
			}
#endif
			else if (value.notNull)
			{
				// not eligible for CSE, and we know it's not null/undefined
				localSet(loc, callIns(MIR_cm, COREADDR(AvmCore::string), 2,
					InsConst((uintptr)core), loadAtomRep(loc)));
			}
			else
			{
				localSet(loc, callIns(MIR_cm, COREADDR(AvmCore::coerce_s), 2,
					InsConst((uintptr)core), loadAtomRep(loc)));
			}
		}
		else if (in && !in->isMachineType() && !result->isMachineType()
			   && in != STRING_TYPE && in != NAMESPACE_TYPE)
		{
			OP* toplevel = loadToplevel(ldargIns(_env));
			// coerceobj is void, but we mustn't optimize it out; verifier only calls it when required
			callIns(MIR_cm, TOPLEVELADDR(Toplevel::coerceobj), 3,
				toplevel, localGet(loc), InsConst((uintptr)result));
			// the input pointer has now been checked but it's still the same value.
			// verifier remembers this fact by updating the verify time type.
		}
		else if (!result->isMachineType() && result != NAMESPACE_TYPE)
		{
			// result is a ScriptObject based type.
			localSet(loc, callIns(MIR_cm, ENVADDR(MethodEnv::coerceAtom2SO), 3,
				ldargIns(_env), loadAtomRep(loc), InsConst((uintptr)result)));
		}
		else
		{
			OP* value = loadAtomRep(loc);
			OP* toplevel = loadToplevel(ldargIns(_env));
			// sp[0] = toplevel->coerce(sp[0], traits)
			OP* out = callIns(MIR_cmop, TOPLEVELADDR(Toplevel::coerce), 3,
				toplevel,
				value,
				InsConst((uintptr)result));

			// store the result
			localSet(loc, atomToNativeRep(result, out));
		}
	}

	void CodegenMIR::emitCheckNull(FrameState* state, int index)
	{
		this->state = state;
		emitPrep(OP_convert_o);

		// The result is either unchanged or an exception is thrown, so 
		// we don't save the result.  This is the null pointer check.
		Traits* t = state->value(index).traits;
		if (!t || t == OBJECT_TYPE || t == VOID_TYPE)
		{
			// checking atom for null or undefined (AvmCore::isNullOrUndefined())
			OP* value = localGet(index);
			callIns(MIR_cm, ENVADDR(MethodEnv::nullcheck), 2, ldargIns(_env), value);
		}
		else if (!t->isMachineType())
		{
			// checking pointer for null
			OP* value = localGet(index);
			OP* br = Ins(MIR_jeq, binaryIns(MIR_ucmp, value, InsConst(0))); // will be patched
			mirPatchPtr(&br->target, npe_label);
		}
		// else: number, int, uint, and boolean, are never null
	}

	void CodegenMIR::emitPrep(AbcOpcode opcode)
	{
		(void)opcode;

		// update bytecode ip if necessary
		if (state->insideTryBlock && lastPcSave != state->pc)
		{
			storeIns(InsConst(state->pc), 0, _save_eip);
			lastPcSave = state->pc;
		}
	}

	void CodegenMIR::emitCall(FrameState *state, AbcOpcode opcode, sintptr method_id, int argc, Traits* result)
	{
		this->state = state;
		emitPrep(opcode);

		int sp = state->sp();

		int dest = sp-argc;
		int objDisp = dest;

		// make sure null check happened.
		AvmAssert(state->value(objDisp).notNull);

		OP *method = NULL;
		OP *iid = NULL;
		switch (opcode)
		{
		case OP_constructsuper:
		{
			// env->vtable->base->init->enter32v(argc, ...);
			OP* envArg = ldargIns(_env);
			OP* vtable = loadIns(MIR_ldop, offsetof(MethodEnv, vtable), envArg);
			OP* base = loadIns(MIR_ldop, offsetof(VTable,base), vtable);
			method = loadIns(MIR_ldop, offsetof(VTable,init), base);
			break;
		}
		case OP_callmethod:
		{
			// stack in:  obj arg1..N
			// stack out: result
			// sp[-argc] = callmethod(disp_id, argc, ...);
			// method_id is disp_id of virtual method
			OP* vtable = loadVTable(objDisp);
			method = loadIns(MIR_ldop, offsetof(VTable, methods)+sizeof(uintptr)*method_id, vtable);
			break;
		}
		case OP_callsuperid:
		{
			// stack in: obj arg1..N
			// stack out: result
			// method_id is disp_id of super method
			OP* declvtable = loadIns(MIR_ldop, offsetof(MethodEnv, vtable), ldargIns(_env));
			OP* basevtable = loadIns(MIR_ldop, offsetof(VTable, base), declvtable);
			method = loadIns(MIR_ldop, offsetof(VTable, methods)+sizeof(uintptr)*method_id, basevtable);
			break;
		}
		case OP_callstatic:
		{
			// stack in: obj arg1..N
			// stack out: result

			OP* vtable = loadIns(MIR_ldop, offsetof(MethodEnv, vtable), ldargIns(_env));
			OP* abcenv = loadIns(MIR_ldop, offsetof(VTable, abcEnv), vtable);
			method = loadIns(MIR_ldop, offsetof(AbcEnv,m_methods)+sizeof(uintptr)*method_id, abcenv);
			break;
		}
		case OP_callinterface:
		{
			// method_id is pointer to interface method name (multiname)
			int index = int(method_id % Traits::IMT_SIZE);
			OP* vtable = loadVTable(objDisp);
			method = loadIns(MIR_ldop, offsetof(VTable, imt)+sizeof(uintptr)*index, vtable);
			iid = InsConst(method_id);
			break;
		}
		case OP_construct:
		{
			// stack in: ctor arg1..N
			// stack out: newinstance
			OP* vtable = loadVTable(objDisp);
			OP* ivtable = loadIns(MIR_ldop, offsetof(VTable, ivtable), vtable);
			method = loadIns(MIR_ldop, offsetof(VTable, init), ivtable);

			OP* inst = callIns(MIR_cm, CLASSCLOSUREADDR(ClassClosure::newInstance),1, localGet(objDisp));
			localSet(dest, inst);

			break;
		}
		default:
			AvmAssert(false);
		}

		// store args for the call
		int index = objDisp;
		OP* ap = InsAlloc(4);
		int disp = 0;
		for (int i=0; i <= argc; i++)
		{
			OP* v = localGet(index++);
			storeIns(v, disp, ap);
			disp += v->spillSize();
		}
		// patch the size to what we actually need
		ap->size = disp;

		OP* target = leaIns(offsetof(MethodEnv, impl32), method);
		OP* apAddr = leaIns(0, ap);

		OP* out = callIndirect(result==NUMBER_TYPE ? MIR_fci : MIR_ci, target, 4, 
			method, InsConst(argc), apAddr, iid);

		InsDealloc(ap);

		if (opcode != OP_constructsuper && opcode != OP_construct)
		{
			localSet(dest, out);
		}
	}

	void CodegenMIR::emit(FrameState* state, AbcOpcode opcode, uintptr op1, uintptr op2, Traits* result)
	{
		this->state = state;
		emitPrep(opcode);

		int sp = state->sp();

		switch (opcode)
		{
			case OP_jump:
			{
				// spill everything first
				sintptr targetpc = op1;

				saveState();
				
#ifdef DEBUGGER
				if(core->sampling() && targetpc < state->pc)
				{
					emitSampleCheck();
				}
#endif

				// relative branch
				OP* p = Ins(MIR_jmp); // will be patched

				mirPatch(p, targetpc);
				break;
			}

			case OP_lookupswitch:
			{
				//int index = integer(*(sp--));
				//pc += readS24(index < readU16(pc+4) ? 
				//	(pc+6+3*index) :	// matched case
				//	(pc+1));			// default
				int count = int(1 + op2);
				sintptr targetpc = op1;

				AvmAssert(state->value(sp).traits == INT_TYPE);

				saveState();

				OP* input = localGet(sp);
				OP* cmp = binaryIns(MIR_ucmp, input, InsConst(count));
				OP* p = Ins(MIR_jnlt, cmp); // will be patched
				mirPatch(p, targetpc);

				// now for non-default
#ifdef AVMPLUS_64BIT
				OP* offset = binaryIns(MIR_lsh, input, InsConst(3)); // const mul by 8
#else
				OP* offset = binaryIns(MIR_lsh, input, InsConst(2)); // const mul by 4
#endif

				//OP* target = loadIns((int)casePtr, offset);
				OP* jmpt = Ins(MIR_jmpt, offset, count); // indirect jump using jmp table

				// fill in case address entries. These are absolute bytecode offsets
				// that later we will resolve to absolute machine addresses.
				// we can't do it now because they could be forward branches
				const byte* pc = 4 + abcStart + state->pc;
                AvmCore::readU30(pc);

				for (int i=0; i < count; i++)
				{
					sintptr off = state->pc + AvmCore::readS24(pc+3*i);
					mirPatchPtr(&jmpt->args[i+1], off);	// patch case table 
					if (off < state->pc)
						extendLastUse(jmpt, off);
				}
				#ifdef AVMPLUS_64BIT
				AvmAssert(sizeof(OP) == 32);
				#else
				AvmAssert(sizeof(OP)==16); // jump table size calc relies on this
				#endif
				ip += (count+3)/4; // skip jump table
				case_count += count;

				// don't want cse's to live past indirect jumps
				firstCse = ip;
				break;
			}

			case OP_setglobalslot:
			case OP_setslot:
			case OP_getslot:
			{
				Traits* t;
				OP* ptr;
				sintptr ptr_index;
				
				if (opcode == OP_getslot || opcode == OP_setslot)
				{
					ptr_index = op2;
					t = state->value(ptr_index).traits;
					ptr = localGet(ptr_index);
					AvmAssert(state->value(ptr_index).notNull);
					AvmAssert(isPointer((int)ptr_index)); // obj
				}
				else
				{
					ScopeTypeChain* scopeTypes = info->declaringTraits->scope;
					if (scopeTypes->size == 0)
					{
						// no captured scopes, so scope 0 is a local scope
						ptr_index = state->verifier->scopeBase;
						t = state->value(ptr_index).traits;
						ptr = localGet(ptr_index);
						AvmAssert(state->value(ptr_index).notNull);
						AvmAssert(isPointer((int)ptr_index)); // obj
					}
					else
					{
						t = scopeTypes->getScopeTraitsAt(0);
						OP* declVTable = loadIns(MIR_ldop, offsetof(MethodEnv, vtable), ldargIns(_env));
						OP* scope = loadIns(MIR_ldop, offsetof(VTable, scope), declVTable);
						OP* scopeobj = loadIns(MIR_ld, offsetof(ScopeChain, scopes) + 0*sizeof(Atom), scope);
						ptr = atomToNativeRep(t, scopeobj);
					}				
				}

				int slot = int(op1);

				AvmAssert(t->isResolved());
				const TraitsBindingsp tb = t->getTraitsBindings();
				int offset = tb->getSlotOffset(slot);
				
				OP *unoffsetPtr = ptr;
				if (t->pool->isBuiltin && !t->final)
				{
					// t's slots aren't locked in, so we have to adjust for the actual runtime
					// traits->m_sizeofInstance.
					OP* vtable = loadIns(MIR_ldop, offsetof(ScriptObject,vtable), ptr);
					OP* traits = loadIns(MIR_ldop, offsetof(VTable,traits), vtable);
					offset -= (int)(t->m_sizeofInstance);
					AvmAssert(sizeof(t->m_sizeofInstance) == 4);
					OP* sizeofInstance = loadIns(MIR_ld32u, offsetof(Traits, m_sizeofInstance), traits);
					ptr = binaryIns(MIR_addp, sizeofInstance, ptr);
				}

				if (opcode == OP_getslot) 
				{
					// get
					if (result == NUMBER_TYPE)
						localSet(op2, loadIns(MIR_fld, offset, ptr));
					else
					{
						#ifdef AVMPLUS_64BIT
						// Could be signed or unsigned 
						Traits* slotType = tb->getSlotTraits(slot);
						if (slotType==INT_TYPE) //signed
							localSet(op2, loadIns(MIR_ld32, offset, ptr));
						else if (slotType==UINT_TYPE || slotType==BOOLEAN_TYPE) // unsigned
							localSet(op2, loadIns(MIR_ld32u, offset, ptr));
						else
							localSet(op2, loadIns(MIR_ld, offset, ptr));
						#else
						localSet(op2, loadIns(MIR_ld, offset, ptr));
						#endif
					}
				} 
				else
				{
					// set
					OP* value = localGet(sp);					

					#ifndef MMGC_DRC
					storeIns(value, offset, ptr);
					#endif

					#ifdef WRITE_BARRIERS
					// if storing to a pointer-typed slot, inline a WB
					Traits* slotType = tb->getSlotTraits(slot);

					if (core->GetGC()->incremental &&
						(!slotType || !slotType->isMachineType() || slotType == OBJECT_TYPE))
					{
						#ifdef MMGC_DRC
						MirOpcode op = MIR_cm;
						sintptr wbAddr = GCADDR(GC::writeBarrierRC);
						if(slotType == NULL || slotType == OBJECT_TYPE) {
							// use fast atom wb
							// TODO: inline pointer check
							op = MIR_cs;
							wbAddr = FUNCADDR(AvmCore::atomWriteBarrier);
						}
						callIns(op, wbAddr, 4, 
								InsConst((uintptr)core->GetGC()), 
								unoffsetPtr, 
								leaIns(offset, ptr),
								value);
						#else // !DRC
						// use non-substitute WB
						callIns(MIR_cm, GCADDR(GC::WriteBarrierTrap), 3, 
								InsConst((int)core->gc), 
								unoffsetPtr,
								(slotType && slotType != OBJECT_TYPE) ? value :
								binaryIns(MIR_and, value, InsConst(~7)));
						#endif
					}					
					#ifdef MMGC_DRC
					else {
#ifdef AVMPLUS_AMD64
					if (slotType==INT_TYPE || slotType==UINT_TYPE || slotType==BOOLEAN_TYPE)
					{
						// Need to force a 32-bit store here, since we
						// are storing into a 32-bit slot
						storeIns(value, offset, ptr, true);
					}
					else
#endif
						storeIns(value, offset, ptr);
					}
					#endif //MMGC_DRC
					#endif //WRITE_BARRIERS
				}
				break;
			}

			case OP_returnvoid:
			case OP_returnvalue:
			{
				// ISSUE if a method has multiple returns this causes some bloat

				// restore AvmCore::dxnsAddr if we set it to a stack addr in our frame
				if(info->setsDxns()) {
					storeIns(dxnsAddrSave, (uintptr)&core->dxnsAddr, 0);
				}

				#if (defined DEBUGGER || defined FEATURE_SAMPLER )
				callIns(MIR_cm, ENVADDR(MethodEnv::debugExit), 2,
					ldargIns(_env), leaIns(0, _callStackNode));
				
				#ifdef DEBUGGER
				// now we toast the cse and restore contents in order to 
				// ensure that any variable modifications made by the debugger
				// will be pulled in.
				firstCse = ip;
				#endif // DEBUGGER

				#endif // DEBUGGER || FEATURE_SAMPLER

				if (info->exceptions)
				{
					// _ef.endTry();
					OP* ef = leaIns(0, _ef);
					callIns(MIR_cm, EFADDR(ExceptionFrame::endTry), 1,
						ef);
				}

				OP* retvalue;
				if (opcode == OP_returnvalue)
				{
					// already coerced to required native type
					retvalue = localGet(op1);
				}
				else
				{
					retvalue = undefConst;
					Traits* t = info->returnTraits();
					if (t && t != VOID_TYPE)
					{
						// implicitly coerce undefined to the return type
						OP* toplevel = loadToplevel(ldargIns(_env));
						retvalue = callIns(MIR_cmop, TOPLEVELADDR(Toplevel::coerce), 3,
							toplevel, retvalue, InsConst((uintptr)t));
						retvalue = atomToNativeRep(t, retvalue);
					}
				}
#ifdef AVMPLUS_IA32
				OP* ret = Ins(MIR_ret, retvalue);
				// try to make sure return value ends up in EAX
				if (!retvalue->isDouble())
					updateUse(ret, ret->oprnd1, EAX);
#elif defined(AVMPLUS_AMD64)
				OP* ret = Ins(MIR_ret, retvalue);
				// try to make sure return value ends up in RAX
				if (!retvalue->isDouble())
					updateUse(ret, ret->oprnd1, RAX);
#else
				Ins(MIR_ret, retvalue);
#endif
				break;
			}

			case OP_typeof:
			{
				//sp[0] = typeof(sp[0]);
				OP* value = loadAtomRep(op1);
				OP* i3 = callIns(MIR_cmop, COREADDR(AvmCore::_typeof), 2,
					InsConst((uintptr)core), value);
				AvmAssert(result == STRING_TYPE);
				localSet(op1, i3);
				break;
			}

			case OP_not:
			{
				AvmAssert(state->value(op1).traits == BOOLEAN_TYPE);

				OP* value = localGet(op1);
				OP* i3 = binaryIns(MIR_xor, value, InsConst(1));
				localSet(op1, i3);
				break;
			}

			case OP_negate:
			{
				OP* in = localGet(op1);
				OP* out = Ins(MIR_fneg, in);
				localSet(op1, out);
				break;
			}

			case OP_negate_i:
			{
				//framep[op1] = -framep[op1]
				AvmAssert(state->value(op1).traits == INT_TYPE);
				OP* value = localGet(op1);
				OP* i2 = Ins(MIR_neg, value);  // -number  
				localSet(op1, i2);
				break;
			}

			case OP_increment:
			case OP_decrement:
			case OP_inclocal:
			case OP_declocal:
			{
				OP* in = localGet(op1);
				OP* inc = i2dIns(InsConst(op2)); // 1 or -1
				OP* out = binaryIns(MIR_fadd, in, inc);
				localSet(op1, out);
				break;
			}

			case OP_inclocal_i:
			case OP_declocal_i:
			case OP_increment_i:
			case OP_decrement_i:
			{
				AvmAssert(state->value(op1).traits == INT_TYPE);
				OP* in = localGet(op1);
				OP* out = binaryIns(MIR_add, in, InsConst(op2));
				localSet(op1, out);
				break;
			}

			case OP_bitnot:
			{
				// *sp = core->intToAtom(~integer(*sp));
				AvmAssert(state->value(op1).traits == INT_TYPE);
				OP* value = localGet(op1);
				OP* out = binaryIns(MIR_xor, value, InsConst(uintptr(~0)));
				localSet(op1, out);
				break;
			}

			case OP_modulo:
			{
				OP* lhs = localGet(sp-1);
				OP* rhs = localGet(sp);
				OP* out = callIns(MIR_fcsop, FUNCADDR(MathUtils::mod), 2,
					lhs, rhs);
				localSet(sp-1,	out);
				break;
			}

			case OP_add_d:
			case OP_subtract:
			case OP_subtract_i:
			case OP_add_i:
			case OP_multiply:
			case OP_multiply_i:
			case OP_divide:
			case OP_lshift:
			case OP_rshift:
			case OP_urshift:
			case OP_bitand:
			case OP_bitor:
			case OP_bitxor:
			{
				MirOpcode mircode=MIR_last;
				switch (opcode) {
					case OP_bitxor:     mircode = MIR_xor;  break;
					case OP_bitor:      mircode = MIR_or;   break;
					case OP_bitand:     mircode = MIR_and;  break;
					case OP_urshift:    mircode = MIR_ush;  break;
					case OP_rshift:     mircode = MIR_rsh;  break;
					case OP_lshift:     mircode = MIR_lsh;  break;
					case OP_divide:     mircode = MIR_fdiv; break;
					case OP_multiply:   mircode = MIR_fmul; break;
					case OP_multiply_i: mircode = MIR_imul; break;
					case OP_add_i:      mircode = MIR_add;  break;
					case OP_subtract_i: mircode = MIR_sub;  break;
					case OP_subtract:   mircode = MIR_fsub; break;
					case OP_add_d:      mircode = MIR_fadd; break;
					default: break;
				}
				OP* lhs = localGet(sp-1);
				OP* rhs = localGet(sp);
				OP* out = binaryIns(mircode, lhs, rhs);
				localSet(sp-1, out);
				break;
			}

			case OP_throw:
			{
				// flush it all out
				OP* value = loadAtomRep(op1);
				saveState();
				//throwAtom(*sp--);
				callIns(MIR_cm, COREADDR(AvmCore::throwAtom), 2,
					InsConst((uintptr)core), value);
				break;
			}

			case OP_getsuper:
			{
				// stack in: obj [ns [name]]
				// stack out: value
				// sp[0] = env->getsuper(sp[0], multiname)
				int objDisp = sp;
				OP* multi = initMultiname((Multiname*)op1, objDisp);
				AvmAssert(state->value(objDisp).notNull);

				OP* obj = loadAtomRep(objDisp);

				OP* i3 = callIns(MIR_cm, ENVADDR(MethodEnv::getsuper), 3,
					ldargIns(_env), obj, leaIns(0,multi));

				InsDealloc(multi);

				i3 = atomToNativeRep(result, i3);
				localSet(objDisp, i3);
				break;
			}

			case OP_setsuper:
			{
				// stack in: obj [ns [name]] value
				// stack out: nothing
				// core->setsuper(sp[-1], multiname, sp[0], env->vtable->base)
				int objDisp = sp-1;
				OP* multi = initMultiname((Multiname*)op1, objDisp);
				AvmAssert(state->value(objDisp).notNull);

				OP* obj = loadAtomRep(objDisp);
				OP* value = loadAtomRep(sp);

				callIns(MIR_cm, ENVADDR(MethodEnv::setsuper), 4,
					ldargIns(_env), obj, leaIns(0, multi), value);

				InsDealloc(multi);
				break;
			}

			case OP_nextname:
			case OP_nextvalue:
			{
				// sp[-1] = next[name|value](sp[-1], sp[0]);
				OP* obj = loadAtomRep(sp-1);
				AvmAssert(state->value(sp).traits == INT_TYPE);
				OP* index = localGet(sp);
				OP* i1 = callIns(MIR_cm, (opcode == OP_nextname) ? ENVADDR(MethodEnv::nextname) : ENVADDR(MethodEnv::nextvalue), 3,
					ldargIns(_env), obj, index);
				localSet(sp-1, atomToNativeRep(result, i1));
				break;
			}

			case OP_hasnext: 
			{
				// sp[-1] = hasnext(sp[-1], sp[0]);
				OP* obj = loadAtomRep(sp-1);
				AvmAssert(state->value(sp).traits == INT_TYPE);
				OP* index = localGet(sp);
				OP* i1 = callIns(MIR_cm, ENVADDR(MethodEnv::hasnext), 3,
					ldargIns(_env), obj, index);
				AvmAssert(result == INT_TYPE);
				localSet(sp-1, i1);
				break;
			}

			case OP_hasnext2: 
			{
				OP* obj = InsAlloc(sizeof(Atom));
				OP* index = InsAlloc(sizeof(int));
				storeIns(loadAtomRep(op1), 0, obj);
				storeIns(localGet(op2), 0, index);
				OP* i1 = callIns(MIR_cm, ENVADDR(MethodEnv::hasnextproto), 3,
									 ldargIns(_env), leaIns(0, obj), leaIns(0, index));
				localSet(op1, loadIns(MIR_ldop, 0, obj));
				localSet(op2, loadIns(MIR_ldop, 0, index));
				AvmAssert(result == BOOLEAN_TYPE);
				localSet(sp+1, i1);
				InsDealloc(obj);
				InsDealloc(index);
				break;
			}
			
			
			case OP_sxi1:
			case OP_sxi8:
			case OP_sxi16:
				//framep[op1] = sext framep[op1]
			{
				AvmAssert(state->value(op1).traits == INT_TYPE);
#if HAVE_MIR_SMOPS
				if(opcode == OP_sxi16 || opcode == OP_sxi8)
				{
					Value& value = state->value(op1);
					OP* a = value.ins;
					// optimize cases like sxi8(li8(x))
					if((opcode == OP_sxi8 &&
						(a->code & ~MIR_oper) == MIR_sld &&
						(a->disp & (SMOP_MASK ^ SMOP_SX)) == SMOP_I8) ||
						(opcode == OP_sxi16 &&
						(a->code & ~MIR_oper) == MIR_sld &&
						(a->disp & (SMOP_MASK ^ SMOP_SX)) == SMOP_I16))
					{
						localSet(op1, loadIns(a->code, a->disp | SMOP_SX, a->base));
						markDead(a);
					}
					else
					{
						OP* val = localGet(op1);
						OP* res = Ins((opcode == OP_sxi8) ? MIR_sx8 : MIR_sx16, val);
						localSet(op1, res);
					}
				}
				else
#endif
				{
					// straightforward shift based sign extension
					OP* val = localGet(op1);
					enum { WORDSIZE = 32 }; // TODO maybe switch on 64 bit systems
					OP* sh = InsConst(opcode == OP_sxi16 ? (WORDSIZE - 16) : opcode == OP_sxi8 ? (WORDSIZE - 8) : (WORDSIZE - 1));
					OP* shl = binaryIns(MIR_lsh, val, sh);
					OP* res = binaryIns(MIR_rsh, shl, sh);
					localSet(op1, res);
				}

				break;
			}
			case OP_li8:
			case OP_li16:
			case OP_li32:
			case OP_lf32:
			case OP_lf64:
				//framep[op1] = *framep[op1]
			{
				AvmAssert(state->value(op1).traits == INT_TYPE);
#if HAVE_MIR_SMOPS
				// case where we have MIR instructions for
				// sized loads
				int32 size;

  				switch(opcode)
   				{
   				default:
   					AvmAssert(false); // shouldn't get here
   					// fall through
   				case OP_li8:
   					size = 1;
   					break;
   				case OP_li16:
   					size = 2;
   					break;
   				case OP_li32:
   				case OP_lf32:
   					size = 4;
   					break;
   				case OP_lf64:
   					size = 8;
   					break;
   				}

				Value& value = state->value(op1);
				OP* a = value.ins;
				int32 disp2;
				// try to get an optimized mir_maddr...
				OP* maddrO = maddrOpt(a, size, &disp2);

				if(maddrO)
				{
					// success! dink disp2 (displacement given to actual load)
					// with the sign extend / size bits
					MirOpcode code;
					switch(opcode)
					{
					default:
						AvmAssert(false); // shouldn't get here
						// fall through
					case OP_li8:
						code = MIR_sld;
						disp2 |= SMOP_I8;
						break;
					case OP_li16:
						code = MIR_sld;
						disp2 |= SMOP_I16;
						break;
					case OP_li32:
						code = MIR_ld;
						break;
					case OP_lf32:
						code = MIR_fsld;
						disp2 |= SMOP_F32;
						break;
					case OP_lf64:
						code = MIR_fld;
						break;
					}
					// and create the load
					OP *result = loadIns(code, disp2, maddrO);
					localSet(op1, result);
					// and get rid of the original addr as maddrOpt
					// optimized for us!
					markDead(a);
					break;
				}

				// straightforward case...
				OP* addr = localGet(op1);
				// just range check [0,size) and have no displacement
				// in the actual load
				OP* maddr = Ins(MIR_maddr, addr, size);
				OP* i2;

  				switch(opcode)
   				{
   				default:
   					AvmAssert(false); // shouldn't get here
   					// fall through
   				case OP_li8:
   					i2 = loadIns(MIR_sld, SMOP_I8, maddr);
   					break;
   				case OP_li16:
   					i2 = loadIns(MIR_sld, SMOP_I16, maddr);
   					break;
   				case OP_li32:
   					i2 = loadIns(MIR_ld, 0, maddr);
   					break;
   				case OP_lf32:
   					i2 = loadIns(MIR_fsld, SMOP_F32, maddr);
   					break;
   				case OP_lf64:
   					i2 = loadIns(MIR_fld, 0, maddr);
   					break;
   				}

				localSet(op1, i2);
#else
				// no MIR help... use helper functions
				OP* addr = localGet(op1);
				OP* i2;
				bool isFloat = false;
				sintptr helper;

				switch(opcode)
				{
				default:
					AvmAssert(false); // shouldn't get here
					// fall through
#ifdef AVMPLUS_64BIT
				case OP_li8:
					helper = ENVADDR(MethodEnv::li8_64);
					break;
				case OP_li16:
					helper = ENVADDR(MethodEnv::li16_64);
					break;
				case OP_li32:
					helper = ENVADDR(MethodEnv::li32_64);
					break;
#else
				case OP_li8:
					helper = ENVADDR(MethodEnv::li8);
					break;
				case OP_li16:
					helper = ENVADDR(MethodEnv::li16);
					break;
				case OP_li32:
					helper = ENVADDR(MethodEnv::li32);
					break;
#endif
				case OP_lf32:
					helper = ENVADDR(MethodEnv::lf32);
					isFloat = true;
					break;
				case OP_lf64:
					helper = ENVADDR(MethodEnv::lf64);
					isFloat = true;
					break;
				}
				i2 = callIns(isFloat ? MIR_fcm : MIR_cm,
					helper, 2, ldargIns(_env), addr);
				localSet(op1, i2);
#endif
				break;
			}

			// these implementations are VERY similar to the
			// OP_li8, etc. versions which are decently commented
			case OP_si8:
			case OP_si16:
			case OP_si32:
			case OP_sf32:
			case OP_sf64:
			{
				OP* svalue = localGet(sp-1);
#if HAVE_MIR_SMOPS
				int32 size;

  				switch(opcode)
   				{
   				default:
   					AvmAssert(false); // shouldn't get here
   					// fall through
   				case OP_si8:
   					size = 1;
   					break;
   				case OP_si16:
   					size = 2;
   					break;
   				case OP_si32:
   				case OP_sf32:
   					size = 4;
   					break;
   				case OP_sf64:
   					size = 8;
   					break;
   				}

				Value& value = state->value(sp);
				OP* a = value.ins;
				int32 disp2;
				OP* maddrO = maddrOpt(a, size, &disp2);
				// store(maddr(x + y),z) -> store(maddr(x),z+y) with updated range checking
				if(maddrO)
				{
					MirOpcode code;
					switch(opcode)
					{
					default:
						AvmAssert(false); // shouldn't get here
						// fall through
					case OP_si8:
						code = MIR_sst;
						disp2 |= SMOP_I8;
						break;
					case OP_si16:
						code = MIR_sst;
						disp2 |= SMOP_I16;
						break;
					case OP_sf64:
					case OP_si32:
						code = MIR_st;
						break;
					case OP_sf32:
						code = MIR_sst;
						disp2 |= SMOP_F32;
						break;
					}
					storeIns(code, svalue, disp2, maddrO);
					emitKill(state, sp);
					markDead(a);
					break;
				}

				OP* addr = localGet(sp);
				OP* maddr = Ins(MIR_maddr, addr, size);

				switch(opcode)
				{
				default:
					AvmAssert(false); // shouldn't get here
					// fall through
				case OP_si8:
					storeIns(MIR_sst, svalue, SMOP_I8, maddr);
					break;
				case OP_si16:
					storeIns(MIR_sst, svalue, SMOP_I16, maddr);
					break;
				case OP_si32:
					storeIns(MIR_st, svalue, 0, maddr);
					break;
				case OP_sf32:
					storeIns(MIR_sst, svalue, SMOP_F32, maddr);
					break;
				case OP_sf64:
					storeIns(MIR_st, svalue, 0, maddr);
					break;
				}
#else
				OP* addr = localGet(sp);
				sintptr helper;

				switch(opcode)
				{
				default:
					AvmAssert(false); // shouldn't get here
					// fall through
				case OP_si8:
					helper = ENVADDR(MethodEnv::si8);
					break;
				case OP_si16:
					helper = ENVADDR(MethodEnv::si16);
					break;
				case OP_si32:
					helper = ENVADDR(MethodEnv::si32);
					break;
				case OP_sf32:
					helper = ENVADDR(MethodEnv::sf32);
					break;
				case OP_sf64:
					helper = ENVADDR(MethodEnv::sf64);
					break;
				}
				callIns(MIR_cm, helper, 3, ldargIns(_env), svalue, addr);
#endif
				break;
			}

			case OP_newfunction:
			{
				//sp[0] = core->newfunction(env, body, _scopeBase, scopeDepth);
 				AbstractFunction* func = pool->getMethodInfo((uint32)op1);
				int extraScopes = state->scopeDepth;

				// prepare scopechain args for call
				OP* ap = storeAtomArgs(extraScopes, state->verifier->scopeBase);

				OP* envArg = ldargIns(_env);
				OP* vtable = loadIns(MIR_ldop, offsetof(MethodEnv, vtable), envArg);
				OP* outer = loadIns(MIR_ldop, offsetof(VTable, scope), vtable);
				OP* argv = leaIns(0, ap);

				OP* i3 = callIns(MIR_cm, ENVADDR(MethodEnv::newfunction), 4,
					envArg, InsConst((uintptr)func), outer, argv);

				InsDealloc(ap);

				AvmAssert(!result->isMachineType());
				localSet(op2, i3);
				break;
			}

			case OP_call:
			{
				// stack in: method obj arg1..N
				// sp[-argc-1] = call(env, sp[-argc], argc, ...)
				int argc = int(op1);
				int funcDisp = sp - argc - 1;
				int dest = funcDisp;

				// convert args to Atom[] for the call
				OP* func = loadAtomRep(funcDisp);
				OP* ap = storeAtomArgs(loadAtomRep(funcDisp+1), argc, funcDisp+2);

				OP* toplevel = loadToplevel(ldargIns(_env));
				OP* argv = leaIns(0, ap);

				OP* i3 = callIns(MIR_cm, TOPLEVELADDR(Toplevel::op_call), 4, 
					toplevel, func, InsConst(argc), argv);

				InsDealloc(ap);

				localSet(dest, atomToNativeRep(result, i3));
				break;
			}

			case OP_callproperty:
			case OP_callproplex:
			case OP_callpropvoid:
			{
				// stack in: obj [ns [name]] arg1..N
				// stack out: result

				int argc = int(op2);
				// obj = sp[-argc]
				//tempAtom = callproperty(env, name, toVTable(obj), argc, ...);
				//	*(sp -= argc) = tempAtom;
				int argv = sp-argc+1;

				int baseDisp = sp-argc;
				OP* multi = initMultiname((Multiname*)op1, baseDisp);

				AvmAssert(state->value(baseDisp).notNull);

				// convert args to Atom[] for the call
				OP* base = loadAtomRep(baseDisp);
				OP* receiver = opcode == OP_callproplex ? InsConst(nullObjectAtom) : base;
				OP* ap = storeAtomArgs(receiver, argc, argv);

				OP* vtable = loadVTable(baseDisp);
				OP* toplevel = loadToplevel(ldargIns(_env));
				OP* atomv = leaIns(0, ap);

				OP* out = callIns(MIR_cm, TOPLEVELADDR(Toplevel::callproperty), 6,
					toplevel, base, leaIns(0, multi), InsConst(argc), atomv, vtable);

				InsDealloc(ap);
				InsDealloc(multi);

				localSet(baseDisp, atomToNativeRep(result, out));
				break;
			}

			case OP_constructprop:
			{
				// stack in: obj [ns [name]] arg1..N
				// stack out: result

				int argc = int(op2);
				// obj = sp[-argc]
				//tempAtom = callproperty(env, name, toVTable(obj), argc, ...);
				//	*(sp -= argc) = tempAtom;
				int argv = sp-argc+1;

				int objDisp = sp-argc;
				OP* multi = initMultiname((Multiname*)op1, objDisp);
				AvmAssert(state->value(objDisp).notNull);

				// convert args to Atom[] for the call
				OP* obj = loadAtomRep(objDisp);
				OP* vtable = loadVTable(objDisp);
				OP* ap = storeAtomArgs(obj, argc, argv);

				OP* toplevel = loadToplevel(ldargIns(_env));
				OP* atomv = leaIns(0, ap);
				OP* i3 = callIns(MIR_cm, TOPLEVELADDR(Toplevel::constructprop), 5,
					toplevel, leaIns(0, multi), InsConst(argc), atomv, vtable);

				InsDealloc(ap);
				InsDealloc(multi);

				localSet(objDisp, atomToNativeRep(result, i3));
				break;
			}

			case OP_callsuper:
			case OP_callsupervoid:
			{
				// stack in: obj [ns [name]] arg1..N
				// stack out: result
				// null check must have already happened.
				//	tempAtom = callsuper(multiname, obj, sp-argc+1, argc, vtable->base);
				int argc = int(op2);
				int argv = sp - argc + 1;
				int objDisp = sp - argc;
				OP* multi = initMultiname((Multiname*)op1, objDisp);
				AvmAssert(state->value(objDisp).notNull);

				// convert args to Atom[] for the call
				OP* obj = loadAtomRep(objDisp);

				OP* ap = storeAtomArgs(obj, argc, argv);

				OP* atomv = leaIns(0, ap);
				OP* i3 = callIns(MIR_cm, ENVADDR(MethodEnv::callsuper), 4,
					ldargIns(_env), leaIns(0, multi), InsConst(argc), atomv);

				InsDealloc(ap);
				InsDealloc(multi);

				localSet(objDisp, atomToNativeRep(result, i3));
				break;
			}

			case OP_construct:
 			{
				// stack in: method arg1..N
				// sp[-argc] = construct(env, sp[-argc], argc, null, arg1..N)
 				int argc = int(op1);
 				int funcDisp = sp - argc;
 				int dest = funcDisp;

				OP* func = loadAtomRep(funcDisp);

				// convert args to Atom[] for the call
				OP* ap = storeAtomArgs(InsConst(nullObjectAtom), argc, funcDisp+1);

				OP* toplevel = loadToplevel(ldargIns(_env));
				OP* argv = leaIns(0, ap);

				OP* i3 = callIns(MIR_cm, TOPLEVELADDR(Toplevel::op_construct), 4,
					toplevel, func, InsConst(argc), argv);

				InsDealloc(ap);

				localSet(dest, atomToNativeRep(result, i3));
				break;
 			}

			case OP_applytype:
			{
				// stack in: method arg1..N
				// sp[-argc] = applytype(env, sp[-argc], argc, null, arg1..N)
				int argc = int(op1);
				int funcDisp = sp - argc;
				int dest = funcDisp;
				int arg0 = sp - argc + 1;

				OP* func = loadAtomRep(funcDisp);

				// convert args to Atom[] for the call
				OP* ap = storeAtomArgs(argc, arg0);

				OP* toplevel = loadToplevel(ldargIns(_env));
				OP* argv = leaIns(0, ap);

				OP* i3 = callIns(MIR_cm, TOPLEVELADDR(Toplevel::op_applytype), 4,
					toplevel, func, InsConst(argc), argv);

				InsDealloc(ap);

				localSet(dest, atomToNativeRep(result, i3));
				break;
			}

			case OP_newobject:
			{
 				// result = env->op_newobject(sp, argc)
 				int argc = int(op1);
 				int dest = sp - (2*argc-1);
				int arg0 = dest;

				// convert args to Atom for the call[]
				OP* ap = storeAtomArgs(2*argc, arg0);

				OP* i3 = callIns(MIR_cm, ENVADDR(MethodEnv::op_newobject), 3,
#ifdef AVMPLUS_64BIT
					ldargIns(_env), leaIns(8*(2*argc-1), ap), InsConst(argc));
#else
					ldargIns(_env), leaIns(4*(2*argc-1), ap), InsConst(argc));
#endif
				InsDealloc(ap);

				localSet(dest, ptrToNativeRep(result, i3));
				break;
			}

			case OP_newactivation:
			{
 				// result = core->newObject(env->activation, NULL);
 				int dest = sp+1;

				OP* envArg = ldargIns(_env);
				OP* activation = callIns(MIR_cm, ENVADDR(MethodEnv::newActivation), 1, envArg);
				localSet(dest, ptrToNativeRep(result, activation));
				break;
			}

			case OP_newcatch:
			{
 				// result = core->newObject(env->activation, NULL);
 				int dest = sp+1;

				OP* activation = callIns(MIR_cm, ENVADDR(MethodEnv::newcatch), 2, 
										 ldargIns(_env), InsConst((uintptr)result));

				localSet(dest, ptrToNativeRep(result, activation));
				break;
			}

 			case OP_newarray:
 			{
				// sp[-argc+1] = core->arrayClass->newarray(sp-argc+1, argc)
 				int argc = int(op1);
 				int arg0 = sp - 1*argc+1;

				// convert array elements to Atom[]
				OP* ap = storeAtomArgs(argc, arg0);
				OP* toplevel = loadToplevel(ldargIns(_env));
				OP* arrayClass = loadIns(MIR_ldop, offsetof(Toplevel,arrayClass), toplevel);
				OP* i3 = callIns(MIR_cm, SCRIPTADDR(ArrayClass::newarray), 3,
					arrayClass, leaIns(0,ap), InsConst(argc));
				InsDealloc(ap);

				AvmAssert(!result->isMachineType());
				localSet(arg0, i3);
				break;
 			}

			case OP_newclass:
			{
				// sp[0] = core->newclass(env, cinit, scopeBase, scopeDepth, base)
				sintptr cinit = op1;
				int localindex = int(op2);
				int extraScopes = state->scopeDepth;

				OP* envArg = ldargIns(_env);
				OP* vtable = loadIns(MIR_ldop, offsetof(MethodEnv, vtable), envArg);
				OP* outer = loadIns(MIR_ldop, offsetof(VTable, scope), vtable);
				OP* base = localGet(localindex);

				// prepare scopechain args for call
				OP* ap = storeAtomArgs(extraScopes, state->verifier->scopeBase);
				OP* argv = leaIns(0, ap);

				OP* i3 = callIns(MIR_cm, ENVADDR(MethodEnv::newclass), 5, 
					envArg, InsConst((sintptr)cinit), base, outer, argv);
				InsDealloc(ap);

				AvmAssert(!result->isMachineType());
				localSet(localindex, i3);
				break;
			}

			case OP_getdescendants:
			{
				// stack in: obj [ns [name]]
				// stack out: value
				//sp[0] = core->getdescendants(sp[0], name);
				int objDisp = sp;
				Multiname* multiname = (Multiname*) op1;

				OP* envArg = ldargIns(_env);
				OP* out;
				OP* multi = initMultiname(multiname, objDisp);
				OP* obj = loadAtomRep(objDisp);
				AvmAssert(state->value(objDisp).notNull);

				out = callIns(MIR_cm, ENVADDR(MethodEnv::getdescendants), 3,
					envArg, obj, leaIns(0, multi));

				InsDealloc(multi);
				localSet(objDisp, atomToNativeRep(result, out));
				break;
			}

			case OP_checkfilter:
			{
				// stack in: obj 
				// stack out: obj
				OP* envArg = ldargIns(_env);
				OP* value = loadAtomRep(op1);

				callIns(MIR_cm, ENVADDR(MethodEnv::checkfilter), 2,
					envArg, value);

				break;
			}

			case OP_findpropstrict: 
			case OP_findproperty: 
			{
				// stack in: [ns [name]]
				// stack out: obj
				// sp[1] = env->findproperty(scopeBase, scopedepth, name, strict)
				int dest = sp;
				OP* multi = initMultiname((Multiname*)op1, dest);
				dest++;
				int extraScopes = state->scopeDepth;

				// prepare scopechain args for call
				OP* ap = storeAtomArgs(extraScopes, state->verifier->scopeBase);

				OP* envArg = ldargIns(_env);
				OP* vtable = loadIns(MIR_ldop, offsetof(MethodEnv,vtable), envArg);
				OP* outer = loadIns(MIR_ldop, offsetof(VTable,scope), vtable);

				OP* withBase;
				if (state->withBase == -1)
				{
					withBase = InsConst(0);
				}
				else
				{
					withBase = leaIns(state->withBase*sizeof(Atom), ap);
				}
	
				// 		return env->findproperty(outer, argv, extraScopes, name, strict);

				OP* i3 = callIns(MIR_cm, ENVADDR(MethodEnv::findproperty), 7, 
					envArg, outer, leaIns(0,ap), InsConst(extraScopes), leaIns(0, multi), 
					InsConst((int32)(opcode == OP_findpropstrict)),
					withBase);

				InsDealloc(ap);
				InsDealloc(multi);

				localSet(dest, atomToNativeRep(result, i3));
				break;
			}

			case OP_finddef: 
			{
				// stack in: 
				// stack out: obj
				// framep[op2] = env->finddef(name)
				Multiname* multiname = (Multiname*) op1;
				sintptr dest = op2;
				OP* name = InsConst((uintptr)multiname->getName());
				OP* out;

				AvmAssert(multiname->isBinding());
				if (multiname->isNsset())
				{
					out = callIns(MIR_cmop, ENVADDR(MethodEnv::finddefNsset), 3,
						ldargIns(_env),
						InsConst((uintptr)multiname->getNsset()),
						name);
				}
				else
				{
					out = callIns(MIR_cmop, ENVADDR(MethodEnv::finddefNs), 3,
						ldargIns(_env),
						InsConst((uintptr)multiname->getNamespace()),
						name);
				}
				localSet(dest, ptrToNativeRep(result, out));
				break;
			}

			case OP_getproperty:
			{
				// stack in: obj [ns] [name]
				// stack out: value
				// obj=sp[0]
				//sp[0] = env->getproperty(obj, multiname);

				Multiname* multiname = (Multiname*)op1;
				bool attr = multiname->isAttr();
				Traits* indexType = state->value(sp).traits;
				int objDisp = sp;

				bool maybeIntegerIndex = !attr && multiname->isRtname() && multiname->contains(core->publicNamespace);

				if (maybeIntegerIndex && indexType == INT_TYPE)
				{
					bool valIsAtom = true;
					OP* index = localGet(objDisp--);
					
					if (multiname->isRtns())
					{
						// Discard runtime namespace
						objDisp--;
					}
					
					Traits* objType = state->value(objDisp).traits;

					OP *value;
					if (objType == ARRAY_TYPE || (objType!= NULL && objType->containsInterface(VECTOROBJ_TYPE)) )
					{
						value = callIns(MIR_cm, (objType==ARRAY_TYPE ? 
												ARRAYADDR(ArrayObject::_getIntProperty) :
												VECTOROBJADDR(ObjectVectorObject::_getIntProperty)), 2,
							localGet(sp-1), index);
					}
					else if( objType == VECTORINT_TYPE || objType == VECTORUINT_TYPE)
					{
						if( result == INT_TYPE || result == UINT_TYPE)
						{
							value = callIns(MIR_cm, (objType==VECTORINT_TYPE ? 
													VECTORINTADDR(IntVectorObject::_getNativeIntProperty) :
													VECTORUINTADDR(UIntVectorObject::_getNativeIntProperty)), 2,
							localGet(sp-1), index);
							valIsAtom = false;
						}
						else
						{
							value = callIns(MIR_cm, (objType==VECTORINT_TYPE ? 
													VECTORINTADDR(IntVectorObject::_getIntProperty) :
													VECTORUINTADDR(UIntVectorObject::_getIntProperty)), 2,
							localGet(sp-1), index);
						}
					}
					else if( objType == VECTORDOUBLE_TYPE )
					{
						if( result == NUMBER_TYPE )
						{
							value = callIns(MIR_fcm, VECTORDOUBLEADDR(DoubleVectorObject::_getNativeIntProperty), 2,
								localGet(sp-1), index);
							valIsAtom = false;
						}
						else
						{
							value = callIns(MIR_cm, VECTORDOUBLEADDR(DoubleVectorObject::_getIntProperty), 2,
								localGet(sp-1), index);
						}
					}
					else
					{
						value = callIns(MIR_cm, ENVADDR(MethodEnv::getpropertylate_i), 3,
							ldargIns(_env), loadAtomRep(sp-1), index);
					}

					localSet(sp-1, valIsAtom?atomToNativeRep(result, value):value);
				}
				else if (maybeIntegerIndex && indexType == UINT_TYPE)
				{
					bool valIsAtom = true;

					OP* index = localGet(objDisp--);
					
					if (multiname->isRtns())
					{
						// Discard runtime namespace
						objDisp--;
					}
					
					Traits* objType = state->value(objDisp).traits;

					OP *value;
					if (objType == ARRAY_TYPE || (objType!= NULL && objType->containsInterface(VECTOROBJ_TYPE)))
					{
						value = callIns(MIR_cm, (objType==ARRAY_TYPE ? 
												ARRAYADDR(ArrayObject::_getUintProperty) :
												VECTOROBJADDR(ObjectVectorObject::_getUintProperty)), 2,
							localGet(sp-1), index);
					}
					else if( objType == VECTORINT_TYPE || objType == VECTORUINT_TYPE )
					{
						if( result == INT_TYPE || result == UINT_TYPE )
						{
							value = callIns(MIR_cm, (objType==VECTORINT_TYPE ?
													VECTORINTADDR(IntVectorObject::_getNativeUintProperty) :
													VECTORUINTADDR(UIntVectorObject::_getNativeUintProperty)), 2,
							localGet(sp-1), index);
							valIsAtom = false;
						}
						else
						{
							value = callIns(MIR_cm, (objType==VECTORINT_TYPE ?
													VECTORINTADDR(IntVectorObject::_getUintProperty) : 
													VECTORUINTADDR(UIntVectorObject::_getUintProperty)), 2,
							localGet(sp-1), index);
						}
					}
					else if( objType == VECTORDOUBLE_TYPE )
					{
						if( result == NUMBER_TYPE )//|| result == UINT_TYPE)
						{
							value = callIns(MIR_fcm, VECTORDOUBLEADDR(DoubleVectorObject::_getNativeUintProperty), 2,
								localGet(sp-1), index);
							valIsAtom = false;
						}
						else
						{
							value = callIns(MIR_cm, VECTORDOUBLEADDR(DoubleVectorObject::_getUintProperty), 2,
								localGet(sp-1), index);
						}
					}
					else
					{
						value = callIns(MIR_cm, ENVADDR(MethodEnv::getpropertylate_u), 3,
							ldargIns(_env), loadAtomRep(sp-1), index);
					}

					localSet(sp-1, valIsAtom?atomToNativeRep(result, value):value);
				}
				else if (maybeIntegerIndex && indexType != STRING_TYPE)
				{
					OP* _tempname = InsAlloc(sizeof(Multiname));

					// copy the flags
					OP* mFlag = InsConst(multiname->ctFlags());
					storeIns(mFlag, offsetof(Multiname,flags), _tempname);

					OP* index = loadAtomRep(objDisp--);
					AvmAssert(state->value(objDisp).notNull);

					OP* obj = loadAtomRep(objDisp);

					// copy the compile-time namespace to the temp multiname
					OP* mSpace = InsConst((uintptr)multiname->ns);
					storeIns(mSpace, offsetof(Multiname, ns), _tempname);

					OP *multi = leaIns(0, _tempname);

					OP* value = callIns(MIR_cm, ENVADDR(MethodEnv::getpropertyHelper), 5,
									    ldargIns(_env), obj, multi, loadVTable(objDisp), index);

					InsDealloc(_tempname);

					localSet(objDisp, atomToNativeRep(result, value));
				}
				else
				{
					OP* multi = initMultiname((Multiname*)op1, objDisp);
					AvmAssert(state->value(objDisp).notNull);

					OP* vtable = loadVTable(objDisp);
					OP* obj = loadAtomRep(objDisp);
					OP* toplevel = loadToplevel(ldargIns(_env));

					//return toplevel->getproperty(obj, name, toplevel->toVTable(obj));
					OP* value = callIns(MIR_cm, TOPLEVELADDR(Toplevel::getproperty), 4,
										toplevel, obj, leaIns(0, multi), vtable);

					InsDealloc(multi);

					localSet(objDisp, atomToNativeRep(result, value));
				}
				break;
			}

			case OP_initproperty:
			case OP_setproperty:
			{
				// stack in: obj [ns] [name] value
				// stack out:
				// obj = sp[-1]
				//env->setproperty(obj, multiname, sp[0], toVTable(obj));
				//OP* value = loadAtomRep(sp);

				Multiname* multiname = (Multiname*)op1;
				bool attr = multiname->isAttr();
				Traits* indexType = state->value(sp-1).traits;
				Traits* valueType = state->value(sp).traits;
				int objDisp = sp-1;

				bool maybeIntegerIndex = !attr && multiname->isRtname() && multiname->contains(core->publicNamespace);

				if (maybeIntegerIndex && indexType == INT_TYPE)
				{
					OP* index = localGet(objDisp--);
					
					if (multiname->isRtns())
					{
						// Discard runtime namespace
						objDisp--;
					}
					
					Traits* objType = state->value(objDisp).traits;

					if (objType == ARRAY_TYPE || (objType!= NULL && objType->containsInterface(VECTOROBJ_TYPE)))
					{
						OP* value = loadAtomRep(sp);
						callIns(MIR_cm, (objType==ARRAY_TYPE ? 
										ARRAYADDR(ArrayObject::_setIntProperty) :
										VECTOROBJADDR(ObjectVectorObject::_setIntProperty)), 3,
							localGet(objDisp), index, value);
					}
					else if(objType == VECTORINT_TYPE || objType == VECTORUINT_TYPE )
					{
						if( valueType == INT_TYPE )
						{
							OP* value = localGet(sp);
							callIns(MIR_cm, (objType==VECTORINT_TYPE ? 
											VECTORINTADDR(IntVectorObject::_setNativeIntProperty) :
											VECTORUINTADDR(UIntVectorObject::_setNativeIntProperty)),
											3,
											localGet(objDisp), index, value);
						}
						else if( valueType == UINT_TYPE )
						{
							OP* value = localGet(sp);
							callIns(MIR_cm, (objType==VECTORINT_TYPE ? 
											VECTORINTADDR(IntVectorObject::_setNativeIntProperty) :
											VECTORUINTADDR(UIntVectorObject::_setNativeIntProperty)), 
											3,
											localGet(objDisp), index, value);
						}
						else
						{
							OP* value = loadAtomRep(sp);
							value = callIns(MIR_cm, (objType==VECTORINT_TYPE ? 
													VECTORINTADDR(IntVectorObject::_setIntProperty) :
													VECTORUINTADDR(UIntVectorObject::_setIntProperty)), 
													3,
													localGet(objDisp), index, value);
						}
					}
					else if(objType == VECTORDOUBLE_TYPE)
					{
						if( valueType == NUMBER_TYPE )
						{
							OP* value = localGet(sp);
							callIns(MIR_cm, VECTORDOUBLEADDR(DoubleVectorObject::_setNativeIntProperty), 3,
								localGet(objDisp), index, value);
						}
						else
						{
							OP* value = loadAtomRep(sp);
							value = callIns(MIR_cm, VECTORDOUBLEADDR(DoubleVectorObject::_setIntProperty), 3,
								localGet(objDisp), index, value);
						}
					}
					else
					{
						OP* value = loadAtomRep(sp);
						callIns(MIR_cm, ENVADDR(MethodEnv::setpropertylate_i), 4,
							ldargIns(_env), loadAtomRep(objDisp), index, value);
					}
				}
				else if (maybeIntegerIndex && indexType == UINT_TYPE)
				{
					OP* index = localGet(objDisp--);
					
					if (multiname->isRtns())
					{
						// Discard runtime namespace
						objDisp--;
					}
					
					Traits* objType = state->value(objDisp).traits;

					if (objType == ARRAY_TYPE || (objType!= NULL && objType->containsInterface(VECTOROBJ_TYPE)))
					{
						OP* value = loadAtomRep(sp);
						callIns(MIR_cm, (objType==ARRAY_TYPE ? 
										ARRAYADDR(ArrayObject::_setUintProperty) :
										VECTOROBJADDR(ObjectVectorObject::_setUintProperty)), 3,
							localGet(objDisp), index, value);
					}
					else if(objType == VECTORINT_TYPE || objType == VECTORUINT_TYPE )
					{
						if( valueType == INT_TYPE )
						{
							OP* value = localGet(sp);
							callIns(MIR_cm, (objType==VECTORINT_TYPE ? 
											VECTORINTADDR(IntVectorObject::_setNativeUintProperty) :
											VECTORUINTADDR(UIntVectorObject::_setNativeUintProperty)),
											3,
											localGet(objDisp), index, value);
						}
						else if( valueType == UINT_TYPE )
						{
							OP* value = localGet(sp);
							callIns(MIR_cm, (objType==VECTORINT_TYPE ? 
											VECTORINTADDR(IntVectorObject::_setNativeUintProperty) :
											VECTORUINTADDR(UIntVectorObject::_setNativeUintProperty)), 
											3,
											localGet(objDisp), index, value);
						}
						else
						{
							OP* value = loadAtomRep(sp);
							value = callIns(MIR_cm, (objType==VECTORINT_TYPE ? 
													VECTORINTADDR(IntVectorObject::_setUintProperty) :
													VECTORUINTADDR(UIntVectorObject::_setUintProperty)), 
													3,
													localGet(objDisp), index, value);
						}
					}
					else if(objType == VECTORDOUBLE_TYPE)
					{
						if( valueType == NUMBER_TYPE )
						{
							OP* value = localGet(sp);
							callIns(MIR_cm, VECTORDOUBLEADDR(DoubleVectorObject::_setNativeUintProperty), 3,
								localGet(objDisp), index, value);
						}
						else
						{
							OP* value = loadAtomRep(sp);
							value = callIns(MIR_cm, VECTORDOUBLEADDR(DoubleVectorObject::_setUintProperty), 3,
								localGet(objDisp), index, value);
						}
					}
					else
					{
						OP* value = loadAtomRep(sp);
						callIns(MIR_cm, ENVADDR(MethodEnv::setpropertylate_u), 4,
							ldargIns(_env), loadAtomRep(objDisp), index, value);
					}
				}
				else if (maybeIntegerIndex)
				{
					OP* value = loadAtomRep(sp);
					OP* _tempname = InsAlloc(sizeof(Multiname));

					// copy the flags
					OP* mFlag = InsConst(multiname->ctFlags());
					storeIns(mFlag, offsetof(Multiname,flags), _tempname);

					OP* index = loadAtomRep(objDisp--);
					AvmAssert(state->value(objDisp).notNull);

					OP* vtable = loadVTable(objDisp);
					OP* obj = loadAtomRep(objDisp);
					OP* envarg = ldargIns(_env);

					// copy the compile-time namespace to the temp multiname
					OP* mSpace = InsConst((uintptr)multiname->ns);
					storeIns(mSpace, offsetof(Multiname, ns), _tempname);

					OP *multi = leaIns(0, _tempname);

					sintptr func = opcode==OP_setproperty ? ENVADDR(MethodEnv::setpropertyHelper) :
														ENVADDR(MethodEnv::initpropertyHelper);
					callIns(MIR_cm, func, 6,
							envarg, obj, multi, value, vtable, index);

					InsDealloc(_tempname);

					localSet(objDisp, atomToNativeRep(result, value));
				}
				else
				{
					OP* value = loadAtomRep(sp);
					OP* multi = initMultiname((Multiname*)op1, objDisp);
					AvmAssert(state->value(objDisp).notNull);

					OP* vtable = loadVTable(objDisp);
					OP* obj = loadAtomRep(objDisp);
					OP* envarg = ldargIns(_env);

					if (OP_setproperty)
					{
						OP* toplevel = loadToplevel(envarg);
						callIns(MIR_cm, TOPLEVELADDR(Toplevel::setproperty), 5,
										toplevel, obj, leaIns(0, multi), value, vtable);
					}
					else
					{
						callIns(MIR_cm, ENVADDR(MethodEnv::initproperty), 5,
							envarg, obj, leaIns(0, multi), value, vtable);
					}

					InsDealloc(multi);
				}
				break;
			}

			case OP_deleteproperty:
			{
				// stack in: obj [ns] [name]
				// stack out: Boolean
				//sp[0] = delproperty(sp[0], multiname);
				int objDisp = sp;
				Multiname *multiname = (Multiname*)op1;
				if(!multiname->isRtname()) {
					OP* multi = initMultiname(multiname, objDisp, true);

					OP* obj = loadAtomRep(objDisp);
					
					OP* i3 = callIns(MIR_cm, ENVADDR(MethodEnv::delproperty), 3,
						ldargIns(_env), obj, leaIns(0, multi));

					InsDealloc(multi);

					localSet(objDisp, atomToNativeRep(result, i3));
				} else {
					OP* _tempname = InsAlloc(sizeof(Multiname));

					// copy the flags
					OP* mFlag = InsConst(multiname->ctFlags());
					storeIns(mFlag, offsetof(Multiname,flags), _tempname);

					OP* index = loadAtomRep(objDisp--);

					if( !multiname->isRtns() )
					{
						// copy the compile-time namespace to the temp multiname
						OP* mSpace = InsConst((uintptr)multiname->ns);
						storeIns(mSpace, offsetof(Multiname, ns), _tempname);
					}
					else
					{
						// intern the runtime namespace and copy to the temp multiname
						OP* nsAtom = loadAtomRep(objDisp--);
						OP* internNs = callIns(MIR_cm, ENVADDR(MethodEnv::internRtns), 2,
							ldargIns(_env), nsAtom);

						storeIns(internNs, offsetof(Multiname,ns), _tempname);
					}

					AvmAssert(state->value(objDisp).notNull);
					OP* obj = loadAtomRep(objDisp);

					OP *multi = leaIns(0, _tempname);

					OP* value = callIns(MIR_cm, ENVADDR(MethodEnv::delpropertyHelper), 4,
									    ldargIns(_env), obj, multi, index);

					InsDealloc(_tempname);

					localSet(objDisp, atomToNativeRep(result, value));
				}
				break;
			}

			case OP_convert_s:
			{
				localSet(op1, callIns(MIR_cm, COREADDR(AvmCore::string), 2,
					InsConst((uintptr)core), loadAtomRep(op1)));
				break;
			}

			case OP_esc_xelem: // ToXMLString will call EscapeElementValue
			{
				//sp[0] = core->ToXMLString(sp[0]);
				OP* value = loadAtomRep(op1);
				OP* i3 = callIns(MIR_cmop, COREADDR(AvmCore::ToXMLString), 2,
					InsConst((uintptr)core), value);
				AvmAssert(result == STRING_TYPE);
				localSet(op1, i3);
				break;
			}

			case OP_esc_xattr:
			{
				//sp[0] = core->EscapeAttributeValue(sp[0]);
				OP* value = loadAtomRep(op1);
				OP* i3 = callIns(MIR_cmop, COREADDR(AvmCore::EscapeAttributeValue), 2,
					InsConst((uintptr)core), value);
				AvmAssert(result == STRING_TYPE);
				localSet(op1, i3);
				break;
			}

			case OP_astype:
			{
				// sp[0] = core->astype(sp[0], traits)
				OP* obj = loadAtomRep(op2);
				OP* i1 = callIns(MIR_cmop, COREADDR(AvmCore::astype), 3,
					InsConst((uintptr)core),
					obj,
					InsConst(op1)); // traits

				i1 = atomToNativeRep(result, i1);
				localSet(op2, i1);
				break;
			}

			case OP_astypelate:
			{
				//sp[-1] = astype(sp[-1], toClassITraits(sp[0]));
				//sp--;
				OP* type = loadAtomRep(sp);

				OP* itraits = callIns(MIR_cmop, TOPLEVELADDR(Toplevel::toClassITraits), 2,
					loadToplevel(ldargIns(_env)), type);

				OP* obj = loadAtomRep(sp-1);

				OP* i3 = callIns(MIR_cmop, COREADDR(AvmCore::astype), 3,
					InsConst((uintptr)core), obj, itraits);

				i3 = atomToNativeRep(result, i3);
				localSet(sp-1, i3);
				break;
			}


			case OP_add:
			{
				OP* lhs = loadAtomRep(sp-1);
				OP* rhs = loadAtomRep(sp);
				OP* toplevel = loadToplevel(ldargIns(_env));
				OP* out = callIns(MIR_cm, TOPLEVELADDR(Toplevel::add2), 3,
					toplevel, lhs, rhs);
				localSet(sp-1, atomToNativeRep(result, out));
				break;
			}

			case OP_concat:
			{
				OP* lhs = localGet(sp-1);
				OP* rhs = localGet(sp);
				OP* out = callIns(MIR_cmop, COREADDR(AvmCore::concatStrings), 3,
					InsConst((uintptr)core), lhs, rhs);
				localSet(sp-1,	out);
				break;
			}

			case OP_equals:
			{
				AvmAssert(result == BOOLEAN_TYPE);
				localSet(sp-1, Ins(MIR_eq, cmpEq(COREADDR(AvmCore::equals), sp-1, sp)));
				break;
			}

			case OP_strictequals:
			{
				AvmAssert(result == BOOLEAN_TYPE);
				localSet(sp-1, Ins(MIR_eq, cmpEq(COREADDR(AvmCore::stricteq), sp-1, sp)));
				break;
			}

			case OP_lessthan:
			{
				AvmAssert(result == BOOLEAN_TYPE);
				localSet(sp-1, Ins(MIR_lt, cmpLt(sp-1, sp)));
				break;
			}

			case OP_lessequals:
			{
				AvmAssert(result == BOOLEAN_TYPE);
				localSet(sp-1, Ins(MIR_le, cmpLe(sp-1, sp)));
				break;
			}

			case OP_greaterthan:
			{
				AvmAssert(result == BOOLEAN_TYPE);
				localSet(sp-1, Ins(MIR_lt, cmpLt(sp, sp-1)));
				break;
			}

			case OP_greaterequals: 
			{
				AvmAssert(result == BOOLEAN_TYPE);
				localSet(sp-1, Ins(MIR_le, cmpLe(sp, sp-1)));
				break;
			}

			case OP_instanceof:
			{
				OP* lhs = loadAtomRep(sp-1);
				OP* rhs = loadAtomRep(sp);
				OP* toplevel = loadToplevel(ldargIns(_env));
				OP* out = callIns(MIR_cm, TOPLEVELADDR(Toplevel::instanceof), 3,
					toplevel, lhs, rhs);
				out = atomToNativeRep(result, out);
				localSet(sp-1,	out);
				break;
			}

			case OP_in:
			{
				OP* lhs = loadAtomRep(sp-1);
				OP* rhs = loadAtomRep(sp);
				OP* toplevel = loadToplevel(ldargIns(_env));
				OP* out = callIns(MIR_cm, TOPLEVELADDR(Toplevel::in_operator), 3,
					toplevel, lhs, rhs);
				out = atomToNativeRep(result, out);
				localSet(sp-1, out);
				break;
			}

			case OP_istype:
			{			
				// expects a CONSTANT_Multiname cpool index
				// used when operator "is" RHS is a compile-time type constant
				//sp[0] = istype(sp[0], itraits);
				OP* obj = loadAtomRep(op2);
				OP* itraits = InsConst(op1);
				OP* out = callIns(MIR_cm, COREADDR(AvmCore::istypeAtom), 3,
					InsConst((uintptr)core), obj, itraits);
				out = atomToNativeRep(result, out);
				localSet(op2, out);
				break;
			}

			case OP_istypelate:
			{
				//sp[-1] = istype(sp[-1], toClassITraits(sp[0]));
				//sp--;
				OP* type = loadAtomRep(sp);

				OP* traits = callIns(MIR_cmop, TOPLEVELADDR(Toplevel::toClassITraits), 2,
					loadToplevel(ldargIns(_env)), type);

				OP* obj = loadAtomRep(sp-1);

				OP* i3 = callIns(MIR_cm, COREADDR(AvmCore::istypeAtom), 3,
					InsConst((uintptr)core), obj, traits);

				i3 = atomToNativeRep(result, i3);
				localSet(sp-1, i3);
				break;
			}

			case OP_dxns:
			{
				OP* uri = InsConst(op1); // uri
				OP* ns = callIns(MIR_cm, 
					COREADDR(AvmCore::newPublicNamespace), 
					2, 
					InsConst((uintptr)core), 
					uri);
				storeIns(ns, 0, dxns);
				break;
			}

			case OP_dxnslate:
			{
				OP* atom = loadAtomRep(op1);				
				OP* uri = callIns(MIR_cm, COREADDR(AvmCore::intern), 2,
					InsConst((uintptr)core), atom);
				OP* ns = callIns(MIR_cm, 
					COREADDR(AvmCore::newPublicNamespace), 
					2, 
					InsConst((uintptr)core), 
					uri);
				storeIns(ns, 0, dxns);
				break;
			}

			/*
			 * debugger instructions 
			 */
			case OP_debugfile:
			{
			#ifdef DEBUGGER
				// todo refactor api's so we don't have to pass argv/argc
				OP* debugger = loadIns(MIR_ldop, offsetof(AvmCore, debugger),
											InsConst((uintptr)core));
				callIns(MIR_cm, DEBUGGERADDR(Debugger::debugFile), 2,
						debugger,
						InsConst(op1));
			#endif // DEBUGGER
			#ifdef VTUNE
				Ins(MIR_file, op1);
			#endif /* VTUNE */
				break;
		    }

			case OP_debugline:
			{
			#ifdef DEBUGGER
				// todo refactor api's so we don't have to pass argv/argc
				OP* debugger = loadIns(MIR_ldop, offsetof(AvmCore, debugger),
											InsConst((uintptr)core));
				callIns(MIR_cm, DEBUGGERADDR(Debugger::debugLine), 2,
						debugger,
						InsConst(op1));
			#endif // DEBUGGER
			#ifdef VTUNE
				Ins(MIR_line, op1);
				hasDebugInfo = true;
			#endif /* VTUNE */
				break;
			}
			#endif // DEBUGGER

			default:
			{
				AvmAssert(false); // unsupported
			}
		}

	} // emit()

	void CodegenMIR::emitIf(FrameState *state, AbcOpcode opcode, sintptr target, int a, int b)
	{
		this->state = state;

#ifdef DEBUGGER
		if(core->sampling() && target < state->pc)
		{
			emitSampleCheck();
		}
#endif

		// 
		// compile instructions that cannot throw exceptions before we add exception handling logic
		//

		// op1 = abc opcode target
		// op2 = what local var contains condition

		// spill all, dont include cond since it gets consumed
		// UBER IMPORTANT we need to spill prior to compare since
		// mir MD generations needs compare and branch to be adjacent.
		OP* cond;
		MirOpcode br;
		
		switch (opcode)
		{
		case OP_iftrue:
			br = MIR_jne;
			cond = binaryIns(MIR_icmp, localGet(a), InsConst(0));
			break;
		case OP_iffalse:
			br = MIR_jeq;
			cond = binaryIns(MIR_icmp, localGet(a), InsConst(0));
			break;
		case OP_iflt:
			br = MIR_jlt;
			cond = cmpLt(a, b);
			break;
		case OP_ifnlt:
			br = MIR_jnlt;
			cond = cmpLt(a, b);
			break;
		case OP_ifle:
			br = MIR_jle;
			cond = cmpLe(a, b);
			break;
		case OP_ifnle:
			br = MIR_jnle;
			cond = cmpLe(a, b);
			break;
		case OP_ifgt:  // a>b === b<a
			br = MIR_jlt;
			cond = cmpLt(b, a);
			break;
		case OP_ifngt: // !(a>b) === !(b<a)
			br = MIR_jnlt;
			cond = cmpLt(b, a);
			break;
		case OP_ifge:  // a>=b === b<=a
			br = MIR_jle;
			cond = cmpLe(b, a);
			break;
		case OP_ifnge: // !(a>=b) === !(a<=b)
			br = MIR_jnle;
			cond = cmpLe(b, a);
			break;
		case OP_ifeq:
			br = MIR_jeq;
			cond = cmpEq(COREADDR(AvmCore::equals), a, b);
			break;
		case OP_ifne:
			br = MIR_jne;
			cond = cmpEq(COREADDR(AvmCore::equals), a, b);
			break;
		case OP_ifstricteq:
			br = MIR_jeq;
			cond = cmpEq(COREADDR(AvmCore::stricteq), a, b);
			break;
		case OP_ifstrictne:
			br = MIR_jne;
			cond = cmpEq(COREADDR(AvmCore::stricteq), a, b);
			break;
		default:
			AvmAssert(false);
			return;
		}

		saveState();

		OP* p = Ins(br, cond); // will be patched

		mirPatch(p, target);
	} // emitIf()

	OP* CodegenMIR::i2dIns(OP* v)
	{
		#ifdef AVMPLUS_ARM
		return callIns(MIR_fcsop, FUNCADDR(CodegenMIR::i2d), 1, v);
		#else
		return Ins(MIR_i2d, v);
		#endif
	}

	OP* CodegenMIR::u2dIns(OP* v)
	{
		#ifdef AVMPLUS_ARM
		return callIns(MIR_fcsop, FUNCADDR(CodegenMIR::u2d), 1, v);
		#else
		return Ins(MIR_u2d, v);
		#endif
	}

	OP* CodegenMIR::fcmpIns(OP* a1, OP* a2)
	{
		#ifdef AVMPLUS_ARM
		return Ins(MIR_icmp, callIns(MIR_csop, FUNCADDR(CodegenMIR::fcmp), 2, a1, a2), InsConst(0));
		#else
		return Ins(MIR_fcmp, a1, a2);
		#endif
	}

	OP* CodegenMIR::binaryFcmpIns(OP* a1, OP* a2)
	{
		#ifdef AVMPLUS_ARM
		return binaryIns(MIR_icmp, callIns(MIR_csop, FUNCADDR(CodegenMIR::fcmp), 2, a1, a2), InsConst(0));
		#else
		return binaryIns(MIR_fcmp, a1, a2);
		#endif
	}
	
	// Faster compares for ints, uint, doubles
	OP* CodegenMIR::cmpOptimization (int lhsi, int rhsi)
	{
		Traits* lht = state->value(lhsi).traits;
		Traits* rht = state->value(rhsi).traits;

		if (lht == rht && lht == INT_TYPE)
		{
			OP* lhs = localGet(lhsi);
			OP* rhs = localGet(rhsi);
			return binaryIns(MIR_icmp, lhs, rhs);
		}
		else if (lht == rht && lht == UINT_TYPE)
		{
			OP* lhs = localGet(lhsi);
			OP* rhs = localGet(rhsi);
			return binaryIns(MIR_ucmp, lhs, rhs);
		}
		else if (lht && lht->isNumeric() && rht && rht->isNumeric())
		{
			// If we're comparing a uint to an int and the int is a non-negative
			// integer constant, don't promote to doubles for the compare
			if ((lht == UINT_TYPE) && (rht == INT_TYPE))
			{
				OP* lhs = localGet(lhsi);
				OP* rhs = localGet(rhsi);
				#if 0//no longer true with our 32-bit math: def AVMPLUS_AMD64
				// 32-bit signed and unsigned values fit in our 64-bit registers
				// so we can simply do a signed compare with mixed int/uint types
				return binaryIns(MIR_icmp, lhs, rhs);
				#else
				if (rhs->code == MIR_imm && rhs->imm >= 0)
				{
					return binaryIns(MIR_ucmp, lhs, rhs);
				}
				#endif
			}
			else if ((lht == INT_TYPE) && (rht == UINT_TYPE))
			{
				OP* lhs = localGet(lhsi);
				OP* rhs = localGet(rhsi);
				#if 0//no longer true with our 32-bit math: def AVMPLUS_AMD64
				// 32-bit signed and unsigned values fit in our 64-bit registers
				// so we can simply do a signed compare with mixed int/uint types
				return binaryIns(MIR_icmp, lhs, rhs);
				#else
				if (lhs->code == MIR_imm && lhs->imm >= 0)
				{
					return binaryIns(MIR_ucmp, lhs, rhs);
				}
				#endif
			}

			OP* lhs = promoteNumberIns(lht, lhsi);
			OP* rhs = promoteNumberIns(rht, rhsi);
			return fcmpIns(lhs, rhs);
		}

		return NULL;
	}

	// set cc's for < operator
	OP* CodegenMIR::cmpLt(int lhsi, int rhsi)
	{
		OP *result = cmpOptimization (lhsi, rhsi);
		if (result)
			return result;

		AvmAssert(trueAtom == 13);
		AvmAssert(falseAtom == 5);
		AvmAssert(undefinedAtom == 4);
		OP* lhs = loadAtomRep(lhsi);
		OP* rhs = loadAtomRep(rhsi);
		OP* atom = callIns(MIR_cm, COREADDR(AvmCore::compare), 3,
			InsConst((uintptr)core), lhs, rhs);

		// caller will use jlt for (a<b) and jge for !(a<b)
		// compare          ^8    <8 
		// true       1101  0101   y 
		// false      0101  1101   n 
		// undefined  0100  1100   n 

		OP* c = InsConst(8);
		return binaryIns(MIR_icmp, binaryIns(MIR_xor, atom, c), c);
	}

	OP* CodegenMIR::cmpLe(int lhsi, int rhsi)
	{
		OP *result = cmpOptimization (lhsi, rhsi);
		if (result)
			return result;

		OP* lhs = loadAtomRep(lhsi);
		OP* rhs = loadAtomRep(rhsi);
		OP* atom = callIns(MIR_cm, COREADDR(AvmCore::compare), 3,
			InsConst((uintptr)core), rhs, lhs);

		// assume caller will use jle for (a<=b) and jgt for !(a<=b)
		// compare          ^1    <=4
		// true       1101  1100  n
		// false      0101  0100  y
		// undefined  0100  0101  n

		OP* c2 = InsConst(1);
		OP* c4 = InsConst(4);
		return binaryIns(MIR_icmp, binaryIns(MIR_xor, atom, c2), c4);
	}

	OP* CodegenMIR::cmpEq(sintptr funcaddr, int lhsi, int rhsi)
	{
		OP *result = cmpOptimization (lhsi, rhsi);
		if (result)
			return result;

		Traits* lht = state->value(lhsi).traits;
		Traits* rht = state->value(rhsi).traits;
		
		// If we have null and a type that is derived from an Object (but not Object or XML)
		// we can optimize our equal comparison down to a simple ptr comparison. This also
		// works when both types are derived Object types.
		if (((lht == NULL_TYPE) && (rht && !rht->notDerivedObjectOrXML())) || 
			((rht == NULL_TYPE) && (lht && !lht->notDerivedObjectOrXML())) ||
			((rht && !rht->notDerivedObjectOrXML()) && (lht && !lht->notDerivedObjectOrXML())))
		{
			OP* lhs = localGet(lhsi);
			OP* rhs = localGet(rhsi);
			return binaryIns(MIR_ucmp, lhs, rhs);
		}
		else
		{
			OP* lhs = loadAtomRep(lhsi);
			OP* rhs = loadAtomRep(rhsi);
			OP* out = callIns(MIR_cm, funcaddr, 
				3, InsConst((uintptr)core), lhs, rhs);

			// assume caller will use MIR_jeq or MIR_jne
			return binaryIns(MIR_icmp, out, InsConst(trueAtom));
		}
	}

	void CodegenMIR::epilogue(FrameState *state)
	{
		this->state = state;

#ifdef AVMPLUS_SPARC
		if(beginCatch_start && beginCatch_end) {
			beginCatch_end->lastUse = ip;
			for (OP* temp_ip = beginCatch_start; temp_ip <= beginCatch_end; temp_ip++) {
				switch(temp_ip->code) {
				case MIR_cs:
				case MIR_cm:
				case MIR_ld:
				case MIR_lea:
					temp_ip->lastUse = ip;
				}
			}
		}
#endif

		if (calleeVars)
		{
			calleeVars[0].lastUse = ip;
			calleeVars[1].lastUse = ip;
			calleeVars[2].lastUse = ip;
			#ifdef AVMPLUS_AMD64
			calleeVars[3].lastUse = ip;
			calleeVars[4].lastUse = ip;
			#ifdef _WIN64
			calleeVars[5].lastUse = ip;
			calleeVars[6].lastUse = ip;
			#endif //#ifdef _WIN64
			#endif
		}

		if (info->setsDxns()) {
			InsDealloc(dxns);
		}

		// exceptions dealloc
		if (info->exceptions)
		{
			InsDealloc(_ef);
			InsDealloc(_save_eip);
		}

		#ifdef DEBUGGER
		InsDealloc(localPtrs);
		InsDealloc(localTraits);
		#endif

		#if (defined DEBUGGER || defined FEATURE_SAMPLER)
		InsDealloc(_callStackNode);
		#endif

		if (npe_label.nextPatchIns)
		{
			mirLabel(npe_label, Ins(MIR_bb));
			callIns(MIR_cm, ENVADDR(MethodEnv::npe), 1, ldargIns(_env));
		}

		if (interrupt_label.nextPatchIns)
		{
			mirLabel(interrupt_label, Ins(MIR_bb));
			callIns(MIR_cm, ENVADDR(MethodEnv::interrupt), 1, ldargIns(_env));
		}

		// ending block
		firstCse = ipEnd = ip;

		// bail if no room in the buffer.  
#ifndef FEATURE_BUFFER_GUARD
		if (checkOverflow())
			return;
#endif /* FEATURE_BUFFER_GUARD */

		// We do this patching at the end since the verifier needs the unaltered 
		// exception target just in case we hit a backedge and regen
		if (info->exceptions)
		{
			for (int i=0, n=info->exceptions->exception_count; i < n; i++)
			{
				ExceptionHandler* h = &info->exceptions->exceptions[i];
				AvmAssertMsg(state->verifier->getFrameState(h->target)->label.bb != NULL, "Exception target address MUST have been resolved");
				sintptr *p = &h->target;
				OP** p2 = (OP**) p;
				mirPatchPtr(p2, h->target );
			}
		}

       // this is not fatal but its good to know if our epilogue estimation code is off.
		#ifdef AVMPLUS_VERBOSE
		if (core->config.bbgraph)
			buildFlowGraph();
		#endif /* AVMPLUS_VERBOSE */
	}

	#ifdef AVMPLUS_VERBOSE
	void CodegenMIR::buildFlowGraph()
	{
		// walk through all the BBs building a flow graph for the mir.
		// BBs are labelled by instruction number.
		OP* begin = ipStart;
		OP* end = ipEnd;

		core->console << "digraph \"" << info->name << "\" {\n";
        core->console << "ratio=fill\n";
        core->console << "ranksep=.1\n";
        core->console << "nodesep=.2\n";
        core->console << "rankdir=LR\n";
        core->console << "edge [arrowsize=.7,labeldistance=1.0,labelangle=-45,labelfontsize=9]\n";
        core->console << "node [fontsize=9,shape=box,width=.2,height=.2]\n";

		bool blockDone = false;
		OP* blockStart = begin;
 
		SortedIntMap<int*> bbNums;
		sintptr bbNum = 1;
		OP* ins = begin;

		// start and end
		bbNums.put(0, (int*)bbNum++);
		bbNums.put(end-begin, (int*)bbNum++);

		core->console << "BB0_entry [label=\"BB0_entry\"]\n";
		core->console << "BB0_entry -> BB" << (int)1 << "_" << (int)(0) << " [weight=2] \n"; 
		//blockDone = true;
		while(ins <= end)
		{
			int opcode = ins->code;
			switch(opcode)
			{
				case MIR_bb:
				{
					uintptr prev = blockStart-begin;
					uintptr bbprev = (uintptr) ( (bbNums.get(prev) > (int*)0) ? bbNums.get(prev) : bbNums.put(prev, (int*)bbNum++) );
					uintptr current = ins-begin;
					uintptr bbcurrent = (uintptr) ( (bbNums.get(current) > (int*)0) ? bbNums.get(current) : bbNums.put(current, (int*)bbNum++) );

					if (!blockDone)
					{
						// fall through
						core->console << "BB" << (int)bbprev << "_" << (int)prev << " -> BB" << (int)bbcurrent << "_" << (int)current << " [weight=2] \n"; 
						blockDone = true;
					}
					core->console << "BB" << (int)bbcurrent << "_" << (int)current << "[label=\"BB" << (int)bbcurrent << "_" << (int)current << "\"]\n";
					blockStart = ins;
					blockDone = false;
					break;
				}

				case MIR_ret:
				{
					uintptr prev = blockStart-begin;
					uintptr bbprev = (uintptr) ( (bbNums.get(prev) > (int*)0) ? bbNums.get(prev) : bbNums.put(prev, (int*)bbNum++) );
					uintptr bbexit = (uintptr) bbNums.get(end-begin);
					core->console << "BB" << (int)bbprev << "_" << (int)prev << " -> BB" << (int)bbexit<< "_" << (int)(end-begin) << " [weight=2] \n"; 
					blockDone = true;
					break;
				}

				case MIR_jmpi:
				case MIR_jmpt:
				{
					// indirect jump *[(disp)+base]
					AvmAssert(ins->base != NULL);
					//int* location = (int*)(ins->tn.value + insValue[opr2ins(ins->oprnd_1)]);
					//ins = ((OP*)*location)-1;  // computed location, anticipating ins++ below
					//blockDone = true;
					break;
				}

				case MIR_jmp:
				{
					// immediate jump
					OP* target = ins->target; // target is absolute, -1 anticipates ins++ below
					uintptr t = target - begin;
					uintptr prev = blockStart-begin;
					AvmAssert(target->code == MIR_bb);
					uintptr bbprev = (uintptr) ( (bbNums.get(prev) > (int*)0) ? bbNums.get(prev) : bbNums.put(prev, (int*)bbNum++) );
					uintptr bbt = (uintptr) ( (bbNums.get(t) > (int*)0) ? bbNums.get(t) : bbNums.put(t, (int*)bbNum++) );

					core->console << "BB" << (int)bbprev << "_" << (int)prev << " -> BB" << (int)bbt << "_" << (int)t << " [weight=2] \n"; 
					blockDone = true;
					break;
				}

				case MIR_jeq:
				case MIR_jne:
				case MIR_jlt:
				case MIR_jle:
				case MIR_jnle:
				case MIR_jnlt:
				{
					OP* target = ins->target; // target is absolute
					uintptr t = target - begin;
					uintptr prev = blockStart-begin;
					uintptr bbprev = (uintptr) ( (bbNums.get(prev) > (int*)0) ? bbNums.get(prev) : bbNums.put(prev, (int*)bbNum++) );
					uintptr bbt = (uintptr) ( (bbNums.get(t) > (int*)0) ? bbNums.get(t) : bbNums.put(t, (int*)bbNum++) );
					uintptr next = ins+1-begin;
					uintptr bbnext = (uintptr) ( (bbNums.get(next) > (int*)0) ? bbNums.get(next) : bbNums.put(next, (int*)bbNum++) );
					AvmAssert(target->code == MIR_bb);

					core->console << "BB" << (int)bbprev << "_" << (int)prev << " -> BB" << (int)bbt << "_" << (int)t << " [taillabel=T] \n"; 
					core->console << "BB" << (int)bbprev << "_" << (int)prev << " -> BB" << (int)bbnext << "_" << (int)next << " [taillabel=F,weight=2] \n"; 

					// The verifier works with extended basics so, we don't have a bb start for
					// the next instruction 
					core->console << "BB" << (int)bbnext << "_" << (int)next << "[label=\"BB" << (int)bbnext << "_" << (int)next << "\"]\n";
					blockStart = ins+1;
					blockDone = false;
					break;
				}

				default:
					break;
			}
			ins++;
		}

		uintptr prev = blockStart-begin;
		uintptr bbprev = (uintptr) ( (bbNums.get(prev) > (int*)0) ? bbNums.get(prev) : bbNums.put(prev, (int*)bbNum++) );
		uintptr current = ins-begin-1;
		uintptr bbcurrent = (uintptr) ( (bbNums.get(current) > (int*)0) ? bbNums.get(current) : bbNums.put(current, (int*)bbNum++) );
		if (!blockDone)
		{
			core->console << "BB" << (int)bbprev << "_" << (int)prev << " -> BB" << (int)bbcurrent << "_" << (int)current << " [weight=2] \n"; 
		}
		core->console << "BB" << (int)bbcurrent << "_" << (int)current << "[label=\"BB" << (int)bbcurrent << "_" << (int)current << "\"]\n";
		core->console << "BB" << (int)bbcurrent << "_" << (int)current << " -> BB" << (int)(bbNum) << "_exit" << " [weight=2] \n"; 
		core->console << "}\n";
	}
	#endif /* AVMPLUS_VERBOSE */

	OP* CodegenMIR::initMultiname(Multiname* multiname, int& csp, bool isDelete /*=false*/)
	{
#ifdef AVMPLUS_VERBOSE
		if (verbose())
			core->console << "        	init multiname\n";
#endif
		OP* _tempname = InsAlloc(sizeof(Multiname));

		// copy the flags
		OP* mFlag = InsConst(multiname->ctFlags());
		storeIns(mFlag, offsetof(Multiname,flags), _tempname);

		OP* nameAtom = NULL;
		
		if (multiname->isRtname())
		{
			nameAtom = loadAtomRep(csp--);			
		}
		else
		{
			// copy the compile-time name to the temp name
			OP* mName = InsConst((uintptr)multiname->name);
			storeIns(mName, offsetof(Multiname,name), _tempname);
		}

		if (multiname->isRtns())
		{
			// intern the runtime namespace and copy to the temp multiname
			OP* nsAtom = loadAtomRep(csp--);
			OP* internNs = callIns(MIR_cm, ENVADDR(MethodEnv::internRtns), 2,
				ldargIns(_env), nsAtom);

			storeIns(internNs, offsetof(Multiname,ns), _tempname);
		}
		else
		{
			// copy the compile-time namespace to the temp multiname
			OP* mSpace = InsConst((uintptr)multiname->ns);
			storeIns(mSpace, offsetof(Multiname, ns), _tempname);
		}

		// Call initMultinameLate as the last step, since if a runtime
		// namespace is present, initMultinameLate may clobber it if a
		// QName is provided as index.
		if (nameAtom)
		{
			if (isDelete)
			{
				callIns(MIR_cm, ENVADDR(MethodEnv::initMultinameLateForDelete), 3,
						ldargIns(_env),
						leaIns(0, _tempname),
						nameAtom);
			}
			else
			{
				callIns(MIR_cm, COREADDR(AvmCore::initMultinameLate), 3,
						InsConst((uintptr)core),
						leaIns(0, _tempname),
						nameAtom);
			}				
		}

		return _tempname;
	}

	OP* CodegenMIR::loadToplevel(OP* env)
	{
		OP* vtable = loadIns(MIR_ldop, offsetof(MethodEnv, vtable), env);
		return loadIns(MIR_ldop, offsetof(VTable, toplevel), vtable);
	}

	OP* CodegenMIR::loadVTable(int i)
	{
		AvmAssert(state->value(i).notNull);
		Traits* t = state->value(i).traits;

		if (t && !t->isMachineType() && t != STRING_TYPE && t != NAMESPACE_TYPE && t != NULL_TYPE)
		{
			// must be a pointer to a scriptobject, and we've done the n
			// all other types are ScriptObject, and we've done the null check
			return loadIns(MIR_ldop, offsetof(ScriptObject, vtable), localGet(i));
		}

		OP* toplevel = loadToplevel(ldargIns(_env));

		int offset;
		if (t == NAMESPACE_TYPE)	offset = offsetof(Toplevel, namespaceClass);
		else if (t == STRING_TYPE)	offset = offsetof(Toplevel, stringClass);
		else if (t == BOOLEAN_TYPE)	offset = offsetof(Toplevel, booleanClass);
		else if (t == NUMBER_TYPE)	offset = offsetof(Toplevel, numberClass);
		else if (t == INT_TYPE)		offset = offsetof(Toplevel, intClass);
		else if (t == UINT_TYPE)	offset = offsetof(Toplevel, uintClass);
		else 
		{
			// *, Object or Void
			OP* obj = loadAtomRep(i);
			return callIns(MIR_cmop, TOPLEVELADDR(Toplevel::toVTable), 2,
					toplevel, obj);
		}

		// now offset != -1 and we are returning a primitive vtable

		OP* cc = loadIns(MIR_ldop, offset, toplevel);
		OP* cvtable = loadIns(MIR_ldop, offsetof(ClassClosure, vtable), cc);
		return loadIns(MIR_ldop, offsetof(VTable, ivtable), cvtable);
	}

	OP* CodegenMIR::promoteNumberIns(Traits* t, int i)
	{
		if (t == NUMBER_TYPE)
		{
			return localGet(i);
		}
		if (t == INT_TYPE || t == BOOLEAN_TYPE)
		{
			return i2dIns(localGet(i));
		}
		if (t == UINT_TYPE)
		{
			return u2dIns(localGet(i));
		}
		AvmAssert(false);
		return NULL;
	}

#ifdef AVMPLUS_VERBOSE

	void CodegenMIR::formatInsOperand(PrintWriter& buffer, OP* opr)
	{
		if (opr)
			buffer.format("@%d", opr-ipStart);
		else
			buffer << "0";
	}

	void CodegenMIR::formatOperand(PrintWriter& buffer, OP* opr)
	{
		if (!opr)
		{
			buffer.format("?");
		}
		else 
		{
			formatInsOperand(buffer, opr);
		}
	}

    void CodegenMIR::formatOpcode(PrintWriter& buffer, OP* op, PoolObject* /*pool*/, GCHashtable* names)
    {

		switch (op->code)
		{
			case MIR_cm:
			case MIR_cs:
			case MIR_fcm:
			case MIR_fcs:
			case MIR_cmop:
			case MIR_csop:
			case MIR_fcmop:
			case MIR_fcsop:
			{
#ifndef AVMPLUS_SYMBIAN
				buffer << mirNames[op->code] << " ";
#endif
				const char *name; 
				if (names != NULL && ((uintptr)(name = (const char *)names->get(op->addr)) != (uintptr)undefinedAtom) && name )
				{
					buffer << name;
				}
				else
				{
					//AvmAssert(false);
					buffer.writeHexAddr(op->addr);
				}
				uint32 argc = op->argc;
				buffer << " (";

				// now dump the params
				for(uint32 i=1; i<=argc; i++)
				{
					formatInsOperand(buffer, op->args[i]);
					if (i+1 <= argc)
						buffer << ", ";
				}
				buffer << ")";
				break;
			}

			case MIR_fci:
			case MIR_ci:
			{
#ifndef AVMPLUS_SYMBIAN
				buffer << mirNames[op->code] << " ";
#endif
				formatInsOperand(buffer, op->target);
				uint32 argc = op->argc;
				buffer << " (";

				// now dump the params
				for(uint32 i=1; i<=argc; i++)
				{
					formatInsOperand(buffer, op->args[i]);
					if (i+1 <= argc)
						buffer << ", ";
				}

				buffer << ")";
				break;
			}

#if HAVE_MIR_SMOPS // TODO disp will show wrong
			case MIR_sld:
			case MIR_fsld:
			case MIR_sldop:
			case MIR_fsldop:
#endif
			case MIR_ld:
#ifdef AVMPLUS_64BIT
			case MIR_ld32:
			case MIR_ld32u:
#endif
			case MIR_ldop:
			case MIR_fld:
			case MIR_fldop:
			case MIR_lea:
			{
#ifndef AVMPLUS_SYMBIAN
				buffer << mirNames[op->code] << " ";
#endif
				buffer << int(op->disp) << "(";
				formatInsOperand(buffer, op->oprnd1);
				buffer << ")";
				break;
			}

#if HAVE_MIR_SMOPS // TODO disp will show wrong
			case MIR_sst:
#endif
			case MIR_st:
			case MIR_st32:
			{
#ifndef AVMPLUS_SYMBIAN
				buffer << mirNames[op->code] << " ";
#endif
				buffer << int(op->disp) << "(";
				formatInsOperand(buffer, op->oprnd1);
				buffer << ")";
				buffer << " <- ";
				formatInsOperand(buffer, op->value);
				break;
			}

			case MIR_imm:
			case MIR_alloc:
			case MIR_line:
#ifndef AVMPLUS_SYMBIAN
				buffer << mirNames[op->code] << " " << (int)op->imm;
#endif
				break;

			case MIR_file:
#ifndef AVMPLUS_SYMBIAN
				buffer << mirNames[op->code] << " " << (String*)op->imm;
#endif
				break;
				
			case MIR_arg:
#ifndef AVMPLUS_SYMBIAN
				buffer << mirNames[op->code] << " ";
#endif
				#ifdef AVMPLUS_ARM
				if (op->reg != Unknown)
					buffer << regNames[op->reg];
				else
					buffer << (int)op->pos;
				#else
				if (op->reg != Unknown)
					buffer << gpregNames[op->reg];
				else
					buffer << (int)op->pos;
				#endif
				break;

			case MIR_def:
			case MIR_fdef:
#ifndef AVMPLUS_SYMBIAN
				buffer << mirNames[op->code] << " ";
#endif
				formatInsOperand(buffer, op->oprnd1);
				if (op->join) {
					buffer << " joined to " ;
					formatInsOperand(buffer, op->join);
				}
				break;

			case MIR_use:
			case MIR_fuse:
#ifndef AVMPLUS_SYMBIAN
				buffer << mirNames[op->code] << " ";
#endif
				formatInsOperand(buffer, op->oprnd1);
				buffer << " [" << int(op->disp) << "]";
				break;

			case MIR_jmpt: {
#ifndef AVMPLUS_SYMBIAN
				buffer << mirNames[op->code] << " (";
#endif
				formatInsOperand(buffer, op->base);
				buffer << ") [";
				for (int i=1; i <= op->size; i++) {
					formatInsOperand(buffer, op->args[i]);
					if (i+1 <= op->size)
						buffer << ", ";
				}
				buffer << "]";
				break;
			}

			case MIR_jmpi:
#ifndef AVMPLUS_SYMBIAN
				buffer << mirNames[op->code] << " -> " << int(op->disp) << "(";
#endif
				formatInsOperand(buffer, op->base);
				buffer << ")";
				break;

			case MIR_jmp:
#ifndef AVMPLUS_SYMBIAN
				buffer << mirNames[op->code] << " -> ";
#endif
				formatInsOperand(buffer, op->target);
				break;

			case MIR_jeq:
			case MIR_jne:
			case MIR_jlt:
			case MIR_jle:
			case MIR_jnle:
			case MIR_jnlt:
#ifndef AVMPLUS_SYMBIAN
				buffer << mirNames[op->code] << " ";
#endif
				formatInsOperand(buffer, op->oprnd1);
				buffer << " -> ";
				formatInsOperand(buffer, op->target);
				break;

			case MIR_bb:
#ifndef AVMPLUS_SYMBIAN
				buffer << mirNames[op->code];
#endif
				break;

			default:
#ifndef AVMPLUS_SYMBIAN
				buffer << mirNames[op->code] << " ";
#endif
				if (op->oprnd1 == 0)
				{
					buffer << " 0x" << hexAddr(op->imm);
				}
				else
				{
					OP* opr = op->oprnd1;
					formatInsOperand(buffer, opr);

					opr = op->oprnd2;
					if (opr == 0) 
					{
						break;
					}
					else 
					{
						buffer << " ";
						formatInsOperand(buffer, opr);
					}
					// no other instruction should use operand3
					//opr = op->value;
				}
				break;
		}
		if (op->liveAcrossCall)
			buffer << " spans call";
    }
	#endif /* AVMPLUS_VERBOSE */


	void CodegenMIR::generatePrologue()
	{
		count_prolog();
		// empty the activation record, ready for code gen
		activation.size = 0;
		activation.temps.clear();
		activation.highwatermark = 0;

		// point to the start of MIR code that we will be converting
		ip = ipStart;
		
		// get a pointer to a machine code buffer
		code = getMDBuffer(pool);

		// place the case table at the beginning of the md buffer
		casePtr = (uintptr*)&code[0];

		mipStart = mip = (MDInstruction*) (casePtr+case_count);

		// If this jump is more than 1 page, we need to poke every page
		if (mipStart > (MDInstruction*)((byte*)casePtr+mirBuffer->pageSize()))
		{
			byte* page_ptr = (byte*)casePtr;
			while (page_ptr < (byte*)mipStart)
			{
				*page_ptr = 0;
				page_ptr += mirBuffer->pageSize();
			}
		}
		mipEnd = 0;

		#ifdef VTUNE
		// squeeze our vtune record in between the case table and the start of code 
		if (hasDebugInfo)
		{
           iJIT_Method_NIDS* vtune = (iJIT_Method_NIDS*) (casePtr+case_count);
			vtune->method_id = iJIT_GetNewMethodID();
			vtune->stack_id = 0;
			vtune->method_name = 0;   // @todo moh said this could be empty ?!?
           jitInfo->vtune = vtune;     
           mipStart = mip = (MDInstruction*) (vtune+1);
       }
		#endif /* VTUNE */

		// make sure we have enough space for our prologue 
		// technically should be from casePtr but we ask for a bit more room
		if (!ensureMDBufferCapacity(pool, md_prologue_size + (byte*)mipStart-&code[0] ))
			return;
		
		// clear the registers 
		gpregs.clear();
		fpregs.clear();

		#ifdef AVMPLUS_SPARC
		// add scratch registers to our free list for the allocator
		// I6 is the frame pointer, I don't know what I7 for.
		// L0 is avoided for temp use.
		gpregs.calleeSaved = rmask(L1) | rmask(L2) | rmask(L3)
						   | rmask(L4) | rmask(L5) | rmask(L6) | rmask(L7)
						   | rmask(I0) | rmask(I1) | rmask(I2) | rmask(I3)
						   | rmask(I4) | rmask(I5);

		fpregs.calleeSaved = 0;

		// avoid O6, since it's the stack pointer.
		// Also I don't know what O7 for.
		gpregs.free = gpregs.calleeSaved
						   | rmask(O0)  | rmask(O1) | rmask(O2) | rmask(O3)
						   | rmask(O4)  | rmask(O5);

		// Also we only handle double here use only even float register.
		fpregs.free = fpregs.calleeSaved
						   | rmask(F0) | rmask(F2)  | rmask(F4)  | rmask(F6)
						   | rmask(F8) | rmask(F10) | rmask(F12) | rmask(F14)
						   | rmask(F16)| rmask(F18) | rmask(F20) | rmask(F22)
						   | rmask(F24)| rmask(F26) | rmask(F28);

        #endif /* AVMPLUS_SPARC */

		#ifdef AVMPLUS_PPC
		// add scratch registers to our free list for the allocator
		gpregs.calleeSaved = rmask(R13) | rmask(R14) | rmask(R15) | rmask(R16)
						   | rmask(R17) | rmask(R18) | rmask(R19) | rmask(R20)
						   | rmask(R21) | rmask(R22) | rmask(R23) | rmask(R24)
						   | rmask(R25) | rmask(R26) | rmask(R27) | rmask(R28)
						   | rmask(R29) | rmask(R30) | rmask(R31);

		fpregs.calleeSaved =			  rmask(F14) | rmask(F15) | rmask(F16)
						   | rmask(F17) | rmask(F18) | rmask(F19) | rmask(F20)
						   | rmask(F21) | rmask(F22) | rmask(F23) | rmask(F24)
						   | rmask(F25) | rmask(F26) | rmask(F27) | rmask(F28)
						   | rmask(F29) | rmask(F30) | rmask(F31);

		// avoid R0, since it isn't totally general purpose.
		// avoid R1, since it's the stack pointer.
		// avoid R2, since it's the TOC pointer.
		gpregs.free = gpregs.calleeSaved
						   | rmask(R3)  | rmask(R4) | rmask(R5) | rmask(R6)
						   | rmask(R7)  | rmask(R8) | rmask(R9) | rmask(R10)
						   | rmask(R11) | rmask(R12);

		// avoid F0, it's a scratch temp used by MD generator
		fpregs.free = fpregs.calleeSaved
						   | rmask(F1) | rmask(F2)  | rmask(F3)  | rmask(F4)
						   | rmask(F5) | rmask(F6)  | rmask(F7)  | rmask(F8)
						   | rmask(F9) | rmask(F10) | rmask(F11) | rmask(F12)
						   | rmask(F13);

        #endif /* AVMPLUS_PPC */

		#ifdef AVMPLUS_ARM
		// add scratch registers to our free list for the allocator

		// R4-R10 are callee-saved, but R4-R5 form our one FP "pseudo-register"
		gpregs.calleeSaved = rmask(R6) | rmask(R7)  | rmask(R8)  | rmask(R9) | rmask(R10);
		fpregs.calleeSaved = 0;

		// Avoid IP, since we'll use it for our own temporary purposes
		// Avoid FP since it's the frame pointer
		// Avoid LR since it's the link register
		// Avoid SP since it's the stack pointer
		// Avoid PC since it's the program counter
		gpregs.free = gpregs.calleeSaved | rmask(R0) | rmask(R1) | rmask(R2) | rmask(R3);
		fpregs.free = fpregs.calleeSaved | rmask(F0);
        #endif /* AVMPLUS_ARM */

		#ifdef AVMPLUS_IA32
		// add scratch registers to our free list for the allocator
		gpregs.calleeSaved = rmask(EBX) | rmask(ESI) | rmask(EDI);

		fpregs.calleeSaved = 0; // all fp regs are caller-saved

		gpregs.free = gpregs.calleeSaved
					| rmask(EAX) | rmask(ECX) | rmask(EDX);

		if (core->config.sse2)
		{
			fpregs.free = fpregs.calleeSaved
						| rmask(XMM0) | rmask(XMM1) | rmask(XMM2) | rmask(XMM3)
						| rmask(XMM4) | rmask(XMM5) | rmask(XMM6) | rmask(XMM7);
		}
		else
		{
			fpregs.free = fpregs.calleeSaved | rmask(FST0);
		}

		#endif

		#ifdef AVMPLUS_AMD64
		#ifdef _WIN64
		// add scratch registers to our free list for the allocator
		gpregs.calleeSaved = rmask(R12) | rmask(R13) | rmask(R14) | rmask(R15) | rmask(RBX) | rmask(RSI) | rmask(RDI);

		fpregs.calleeSaved = 0; // all fp regs are caller-saved

		gpregs.free = gpregs.calleeSaved
					| rmask(RAX) | rmask(RCX) | rmask(RDX) | rmask(R8) | rmask(R9); // | rmask(R10) | rmask(R11);

		if (core->config.sse2)
		{
			fpregs.free = fpregs.calleeSaved
						| rmask(XMM0) | rmask(XMM1) | rmask(XMM2) | rmask(XMM3)
						| rmask(XMM4) | rmask(XMM5) | rmask(XMM6) | rmask(XMM7);
		}
		else
		{
			fpregs.free = fpregs.calleeSaved | rmask(FST0);
		}
		#else
		// add scratch registers to our free list for the allocator
		gpregs.calleeSaved = rmask(R12) | rmask(R13) | rmask(R14) | rmask(R15) | rmask(RBX);

		fpregs.calleeSaved = 0; // all fp regs are caller-saved

		gpregs.free = gpregs.calleeSaved
					| rmask(RAX) | rmask(RCX) | rmask(RDX) | rmask(RSI) | rmask(RDI) | rmask(R8) | rmask(R9);

		if (core->config.sse2)
		{
			fpregs.free = fpregs.calleeSaved
						| rmask(XMM0) | rmask(XMM1) | rmask(XMM2) | rmask(XMM3)
						| rmask(XMM4) | rmask(XMM5) | rmask(XMM6) | rmask(XMM7);
		}
		else
		{
			fpregs.free = fpregs.calleeSaved | rmask(FST0);
		}
		#endif

		#endif
		
		#ifdef _DEBUG
		// keep a tally of the registers to check that our allocator works correctly
		gpregs.count = gpregs.countFree();
		fpregs.count = fpregs.countFree();
		gpregs.checkCount();
		fpregs.checkCount();
		#endif /* _DEBUG */

		#ifdef AVMPLUS_SPARC
		patch_frame_size = mip;
		NOP(); /* This nop is for stack size beyong 4096. */
		NOP();
		SAVEI(SP, 0, SP);

		if (core->minstack)
		{
			SET32((int)&core->minstack, L0);
			LDSWI(L0, 0, L1);
			stackCheck.patchStackSize = (uintptr_t*)mip;
			NOP();
			SUBCC(SP, L1, G0);
			BL(1, 0);
			mdPatchPrevious(&stackCheck.overflowLabel);
			NOP();
			mdLabel(&stackCheck.resumeLabel, mip);
		}
 		#endif /* AVMPLUS_SPARC */

		#ifdef AVMPLUS_PPC
		MFLR (R0);
		STW(R0, 8, SP);

		if (core->minstack)
		{
			LI32(R11, (int)&core->minstack);
			LWZ(R12, 0, R11);
			stackCheck.patchStackSize = (uintptr_t*)mip;
			NOP();
			NOP();
			CMPL(CR7, SP, R12);
			BLT(CR7, 0);
			NOP();
			
			mdPatchPrevious(&stackCheck.overflowLabel);
			mdLabel(&stackCheck.resumeLabel, mip);
		}
		
		// This is where a stmw instruction will go, if needed
		patch_stmw = mip;
		NOP ();

		// This NOP instruction will be turned into a BLA to
		// store the nonvolatile FPU registers, if needed.
		NOP ();

		// This is where a stwu or li32+stwux instruction will go
		patch_stwu = mip;
		NOP();
		NOP();
		NOP();
        #endif /* AVMPLUS_PPC */

		#ifdef AVMPLUS_ARM
		// Reserve 4 bytes to store the stack frame size
		patch_frame_size = mip++;

		// If stack overflow check is used, reserve 4 bytes for
		// minimum stack value.
		if (core->minstack)
		{
			stackCheck.patchStackSize = mip;			
			mip++;
		}

		// Adjust mipStart to be after these constants.
		mipStart = mip;

		if (core->minstack)
		{
			LDR (IP, -12, PC);
			CMP (SP, IP);
			SET_CONDITION_CODE(LT);
			B(0);
			SET_CONDITION_CODE(AL);
			mdPatchPrevious(&stackCheck.overflowLabel);
			mdLabel(&stackCheck.resumeLabel, mip);
		}			
		
		// prologue
		MOV     (IP, SP);

		// save callee-saved registers
		patch_stmfd = mip;
		STMFD_bang (SP, FP_mask | IP_mask | LR_mask | PC_mask);
		SUB_imm8 (FP, IP, 4);

		// the frame size will be updated later
		LDR (IP, (int)patch_frame_size-(int)mip-8, PC);
		SUB (SP, SP, IP);
		#endif // AVMPLUS_ARM
		
		#ifdef AVMPLUS_IA32

			#ifdef VTUNE
               if (jitInfo->vtune && (core->VTuneStatus == iJIT_CALLGRAPH_ON)) 
				{
					MDInstruction* VTmip = mip;

                   MOV(EAX, (sintptr)jitInfo->vtune);
					PUSH(EAX);
					PUSH(0x13);
			
					void * funcptr = (void*)&iJIT_NotifyEvent;
					CALL((int)funcptr-((int)VTmip+13));

					ADD(ESP, 8);
				}
			#endif  //VTUNE

		if (core->minstack)
		{
			// Check the stack
			CMP(ESP, 0x7FFFFFFF);
			stackCheck.patchStackSize = (uintptr*)PREV_MD_INS(mip);
			JB(0x7FFFFFFF);
			mdPatchPrevious(&stackCheck.overflowLabel);
			mdLabel(&stackCheck.resumeLabel, mip);
		}

		PUSH (EBP);
		MOV(EBP,ESP); // copy of ESP before adjust
		SUB(ESP, 0x7FFFFFFF);  // force 32bit operand for instruction
		activation.adjustmentIns = PREV_MD_INS(mip);  // patch location
		for (int i=0; i < 3; i++)
			methodArgs[i].pos -= 4;
		framep = EBP;

		#ifdef AVMPLUS_VERBOSE
		x87Top = 0;
		#endif

		x87Dirty = false;

		#endif /* AVMPLUS_IA32 */

		#ifdef AVMPLUS_AMD64

		if (core->minstack)
		{
			// Check the stack
			MOV(R11, 0x7FFFFFFFFFFF); // 0x7FFFFFFFFFFF = 64-bit placeholder
			stackCheck.patchStackSize = (uintptr*)PREV_MD_INS_64(mip);
			CMP64(RSP, R11);	
			JB(0x7FFFFFFF); // 0x7FFFFFFF = placeholder
			mdPatchPrevious(&stackCheck.overflowLabel);
			mdLabel(&stackCheck.resumeLabel, mip);
		}

		PUSH (RBP);
		MOV(RBP,RSP); // copy of RSP before adjust
		SUB64(RSP, 0x7FFFFFFF);  // 0x7FFFFFFF == force 32bit operand for instruction (adjustment should never overflow 32-bits)
		activation.adjustmentIns = PREV_MD_INS(mip);  // patch location
#ifdef _WIN64
		for (int i=0; i < 4; i++)
			methodArgs[i].pos -= 8;
#endif //#ifdef _WIN64
		framep = RBP;

		#ifdef AVMPLUS_VERBOSE
		x87Top = 0;
		#endif

		x87Dirty = false;

		#endif /* AVMPLUS_AMD64 */
		
		#ifdef _DEBUG
		// not terminal but good to know if our prologue estimation is off
		uintptr actual = (uintptr)mip - (uintptr)mipStart;
		AvmAssertMsg( actual <= (uintptr)md_prologue_size, "Increase md_prologue_size estimate\n");
		#endif /* _DEBUG */
	}

#ifdef AVMPLUS_ARM

	/* Returns the number of bits set in val. 
	 * For a derivation of this algorithm, see 
	 * "Algorithms and data structures with applications to  
	 *  graphics and geometry", by Jurg Nievergelt and Klaus Hinrichs, 
	 *  Prentice Hall, 1993. 
	 */ 
	int CodegenMIR::countBits(uint32 value)
	{
		value -= (value & 0xaaaaaaaaL) >> 1; 
		value =  (value & 0x33333333L) + ((value >> 2) & 0x33333333L); 
		value =  (value + (value >> 4)) & 0x0f0f0f0fL; 
		value += value >> 8;      
		value += value >> 16;     
		return (int)value & 0xff; 
	}
#endif

	void CodegenMIR::generateEpilogue()
	{
		// make sure we have committed the memory we are going to use for the epilogue
		if (!ensureMDBufferCapacity(pool, md_epilogue_size))
			return;

#ifdef AVMPLUS_VERBOSE
			if (verbose())
				core->console << "epilogue:\n";
#endif
		
		// mark location of epilogue start, we need it for patching return opcodes

		MDInstruction* mipEpilog = mip;
		(void)mipEpilog;
		
		if (patch_end.nextPatch)
			mdLabel(&patch_end, mip);

		#ifdef AVMPLUS_SPARC
		int stackSize = activation.highwatermark;
		int frameSize = stackSize+calleeAreaSize()+kLinkageAreaSize;
		frameSize = BIT_ROUND_UP(frameSize, 8);
		if (frameSize <= 4096)
			*(patch_frame_size + 2) |= (-frameSize & 0x1FFF);
		else {
			MDInstruction* mipTemp = mip;
			mip = patch_frame_size;
			SETHI(-frameSize, G1);
			ORI(G1, -frameSize & 0x3FF, G1);
			*mip |= G1;
			*mip &= 0xFFFFDFFF;
			mip = mipTemp;
		}

		ORI(O0, 0, I0);
		JMPLI(I7, 8, G0); //ret
		RESTORE(G0, G0, G0); //restore

		if (core->minstack)
		{
			// Patch the stack oveflow check's frame size
			uint32 *savedMip = mip;
			mip = stackCheck.patchStackSize;
			ADDI32(L1, activation.highwatermark, L1);
			mip = savedMip;

#ifdef AVMPLUS_VERBOSE
			if (verbose())
				core->console << "stackOverflow:\n";
#endif
			mdLabel(&stackCheck.overflowLabel, mip);

			OR(I0, G0, O0);
			thincall(FUNCADDR(CodegenMIR::stackOverflow));
			BA(1, 0);
			mdPatchPrevious(&stackCheck.resumeLabel);
			NOP();
		}

		#endif // AVMPLUS_SPARC

		#ifdef AVMPLUS_PPC
		int stackSize = activation.highwatermark;
		int nonVolatileAreaSize = 0;
		if (gpregs.LowerBound != Unknown) {
			nonVolatileAreaSize += 4*(R31-gpregs.LowerBound+1);
		}
		if (fpregs.LowerBound != Unknown) {
			nonVolatileAreaSize += 8*(F31-fpregs.LowerBound+1);

			// Make sure it's aligned on quadword boundary
			nonVolatileAreaSize = BIT_ROUND_UP(nonVolatileAreaSize,8);
		}

		uint32 *save_mip = mip;
		if (gpregs.LowerBound != Unknown) {
			mip = patch_stmw;
			STMW((Register)gpregs.LowerBound, -(R31-gpregs.LowerBound+1)*4, SP);
			mip = save_mip;
		}

		int frameSize = stackSize+calleeAreaSize()+kLinkageAreaSize+nonVolatileAreaSize;

		// The PowerPC stack pointer must always be quadword (16-byte)
		// aligned.
		frameSize = BIT_ROUND_UP(frameSize, 16);
		mip = patch_stwu;
		if (IsSmallDisplacement(frameSize))
		{
			STWU(SP, -frameSize, SP);
		}
		else
		{
			LI32(R0, -frameSize);
			STWUX(SP, SP, R0);
		}
		mip = save_mip;
		
		// epilogue
		LWZ (SP, 0, SP);
		LWZ (R0, 8, SP);
		MTLR (R0);
		if (fpregs.LowerBound != Unknown) {
			int offset = -nonVolatileAreaSize;
			for (int i = fpregs.LowerBound; i<=F31; i++) {
				LFD ((Register)i, offset, SP);
				offset += 8;
			}
		}
		if (gpregs.LowerBound != Unknown) {
			LMW ((Register)gpregs.LowerBound, -(32-gpregs.LowerBound)*4, SP);
		}
		BLR ();
		mipEnd = mip;

		// At this point, we generate the code to store
		// the nonvolatile floating point registers if needed,
		// and patch the prologue to jump here.
		if (fpregs.LowerBound != Unknown) {
			uint32 *stfd_addr = mip;
			int offset = -nonVolatileAreaSize;
			for (int i = fpregs.LowerBound; i<=F31; i++) {
				STFD ((Register)i, offset, SP);
				offset += 8;
			}
			BLR();

			// Add jump to store instructions
			int disp = (int)stfd_addr - (int)(patch_stmw+1);
			AvmAssert(disp < 0x2000000);
			patch_stmw[1] = 0x48000001 | disp;
		}

		if (core->minstack)
		{
			// Patch the stack oveflow check's frame size
			uint32 *savedMip = mip;
			mip = (uint32*)stackCheck.patchStackSize;
			ADDI32(R12, R12, activation.highwatermark);
			mip = savedMip;

			// Patch the jump to jump to here, and generate
			// the call to the exception handler.
			mdLabel(&stackCheck.overflowLabel, mip);

			// We haven't set up the real stack frame yet,
			// so we need a temporary one so we can call
			// stackOverflow.
			const int kTempFrameSize = 24+4*3; // linkage + 1 callee param + 2 saved args
			STWU(SP, -kTempFrameSize, SP);
			
			STW(R3, 24, SP); // set callee area
			STW(R4, 28, SP); // save args
			STW(R5, 32, SP);
			thincall(FUNCADDR(CodegenMIR::stackOverflow));
			LWZ(R3, 24, SP); // restore parameters
			LWZ(R4, 28, SP);
			LWZ(R5, 32, SP);

			// Tear down temporary stack frame
			LWZ(SP, 0, SP);
			
			B(0);
			mdPatchPrevious(&stackCheck.resumeLabel);
		}
		#endif
			
		#ifdef AVMPLUS_ARM
		int stackSize = activation.highwatermark;

		int frameSize = stackSize+calleeAreaSize();

		// Patch the frame size
		*patch_frame_size = frameSize;

		// Patch the STMFD instruction
		*patch_stmfd |= gpregs.nonVolatileMask;
		
		// epilogue
		int nonVolatileCount = countBits(gpregs.nonVolatileMask);
		SUB_imm8 (SP, FP, 12 + nonVolatileCount * 4);
		LDMFD (SP, gpregs.nonVolatileMask | FP_mask | SP_mask | PC_mask);
		mipEnd = mip;
		
		// Patch stack overflow check
		if (core->minstack)
		{
			// Patch the stack overflow check's frame size
			*(stackCheck.patchStackSize) = core->minstack + activation.highwatermark;

#ifdef AVMPLUS_VERBOSE
			if (verbose())
				core->console << "stackOverflow:\n";
#endif
			if (!pool->stackOverflowHandler)
			{
				pool->stackOverflowHandler = (int)mip;

				// Save the parameters to the method
				STMFD_bang (SP, R0_mask | R1_mask | R2_mask | LR_mask);				
				
				MOV(R1, R0); // env
				MOV_imm32(R0, (int)core);
				thincall(COREADDR(AvmCore::_stackOverflow));

				// If we got here, we're already in a stack overflow
				// and the VM wants us to ignore that fact so
				// we can construct the error object.
				
				// Restore the parameters to the method, and return.
				LDMFD_bang (SP, R0_mask | R1_mask | R2_mask | PC_mask);
			}
			// Patch the jump to jump to here, and generate
			// the call to the exception handler

			mdLabel(&stackCheck.overflowLabel, mip);

			// Save LR
			STMFD_bang (SP, LR_mask);
			
			thincall(pool->stackOverflowHandler);

			// Restore LR
			LDMFD_bang (SP, LR_mask);
			
			B(0);
			mdPatchPrevious(&stackCheck.resumeLabel);
		}
		#endif

        #ifdef AVMPLUS_IA32
		MdLabel patch_probe_stack, patch_probe_return;
		uint32 arSize = 0;
		if (framep == EBP)
		{
			// adjust esp by our activation record size
			arSize = uint32(BIT_ROUND_UP(activation.highwatermark, 16));

			#ifdef _MAC
			// On Mac, the stack size must be 16-byte aligned.
			// - We start off with 4 bytes of callee area, for the
			//   caller's return address.
			// - We then PUSH EBP, for 8 bytes of callee area.
			// - The amount we then subtract from ESP needs to leave
			//   ESP 16-byte aligned
			// - We just aligned arSize to 16, so add 8 to get the
			//   whole shebang aligned to 16
			arSize += 8;
			#endif

			// now patch the SUB(ESP, size) instruction in
			// the prologue.
			// 
			// if stack > 1 page then we need to touch each page
			// since windows expects stack to grow page by page.
			// 
			MDInstruction* current = mip;
			if (arSize > mirBuffer->pageSize())
			{
				// clobber the entire SUB(ESP, size) with a jmp to code that does
				// adjusts the stack and tickles each page in order
				mip = activation.adjustmentIns - 2; // -2 to step on the sub instruction, which is 6B long
				JMP(0x7FFFFFFF);					// jmp takes 5 bytes
				mdPatchPrevious(&patch_probe_stack);   // mark the location for patching
				NOP();								// 1 byte converted to nop
				mdLabel(&patch_probe_return, mip);	// mark where we want to return to 
			}
			else
			{
				// only need to adjust the SUB(ESP, ) instruction
				mip = activation.adjustmentIns;
				IMM32(arSize);
			}
			mip = current;

			for (int i=0; i < 3; i++) {
				OP* v = &calleeVars[i];
				if (v->reg == Unknown && v->pos != InvalidPos) {
					v->reg = (Register) v->imm;
					rematerialize(v);
				}
			}

			#ifdef VTUNE
               if (jitInfo->vtune && (core->VTuneStatus == iJIT_CALLGRAPH_ON)) 
				{
					MDInstruction* VTmip = mip+1;

					PUSH(EAX);
                   MOV(EAX, (sintptr)jitInfo->vtune);
					PUSH(EAX);
					PUSH(0x14);
			
					void * funcptr = (void*)&iJIT_NotifyEvent;
					CALL((int)funcptr-((int)VTmip+13));
	
					ADD(ESP, 8);
					POP(EAX);
				}
			#endif  //VTUNE


			//ADD(ESP, arSize); 
			//POP  (EBP);
			LEAVE(); // leave:  esp = ebp, pop ebp
		}
		RET  ();

#if HAVE_MIR_SMOPS
		sintptr mopCheckLoc;

		if(lastMOPRangeCheckJmp)
		{
			mopCheckLoc = (sintptr)mip;

#if DBG_MADDR && defined(_DEBUG)
			ALU(0xcc); // breakpoint
#endif

			// generate for every method to eke out
			// a bit more branch prediction accuracy
#ifdef _MAC
			// we never return so we can cheese the alignment
			// (a single mir_maddr may generate two jumps so using
			// the typical mirLabel stuff is problematic)
			AND(ESP, 0xfffffff0);
			SUB(ESP, 12);
#endif
			PUSH(8, framep); // env
#if DBG_MADDR && defined(_DEBUG)
			// make up a call frame
			POP(EAX); // env
			PUSH(EBP);
			MOV(EBP, ESP);
			PUSH(EAX); // env
#endif
			thincall((sintptr)&mopRangeCheckFailedShim);
#ifdef _DEBUG
			ALU(0xcc); // breakpoint
#endif

			while(lastMOPRangeCheckJmp)
			{
				uint32 *cur = lastMOPRangeCheckJmp;
				lastMOPRangeCheckJmp = (uint32 *)*cur;
				mdApplyPatch(cur, mopCheckLoc);
			}
#ifdef _DEBUG
			lastMOPRangeCheckJmp = NULL;
#endif
		}
#endif
		mipEnd = mip;

		// Patch stack overflow check
		if (core->minstack)
		{
			// Patch the stack overflow check's frame size
			*(stackCheck.patchStackSize) = core->minstack + activation.highwatermark;

#ifdef AVMPLUS_VERBOSE
			if (verbose())
				core->console << "stackOverflow:\n";
#endif
			if (!pool->stackOverflowHandler)
			{
				pool->stackOverflowHandler = (sintptr)mip;

				#ifdef AVMPLUS_64BIT
				AvmAssertMsg (true, "need 64-bit implementation\n");
				#elif defined(_MAC)
				// Stack must be aligned at 16-byte boundary for MacOS X ABI.
				// The method did a CALL to stackOverflowHandler, so we're already
				// 4 bytes pushed from the original 16-byte stack alignment.
				PUSH(8, ESP); // env
				PUSH((int)core);
				// _stackOverflow is needed because gcc can't take address
				// of a virtual method
				thincall(COREADDR(AvmCore::_stackOverflow));
				ADD(ESP, 8);

                #elif defined(AVMPLUS_CDECL)
				// gcc version (Linux)
				PUSH(8, ESP); // env
				PUSH((int)core);
				// _stackOverflow is needed because gcc can't take address
				// of a virtual method
				thincall(COREADDR(AvmCore::_stackOverflow));
				ADD(ESP, 8);

				#else
				// Windows version
				PUSH(8, ESP);  // env
				MOV(ECX, (int)core);
				thincall(COREADDR(AvmCore::stackOverflow));
				#endif

				RET();
			}
			// Patch the jump to jump to here, and generate
			// the call to the exception handler
			mdLabel(&stackCheck.overflowLabel, mip);
			thincall(pool->stackOverflowHandler);
			JMP(0x7FFFFFFF);
			mdPatchPrevious(&stackCheck.resumeLabel);
		}

		// > 1 page stack growth
		if (patch_probe_stack.nextPatch)
		{
			// patch the jmp _probe expression to the current
			// location where we emit the probe code
			mdLabel(&patch_probe_stack, mip);
			emitAllocaProbe(arSize, &patch_probe_return);
		}

		#endif /* AVMPLUS_IA32 */
		
        #ifdef AVMPLUS_AMD64
		MdLabel patch_probe_stack, patch_probe_return;
		uint32 arSize = 0;
		if (framep == RBP)
		{
			// adjust esp by our activation record size
			arSize = ((((int32)(activation.highwatermark + calleeAreaSize()))+(15))&~(15));

			// Stack size must be 16-byte aligned.
			// - We start off with 8 bytes of callee area, for the
			//   caller's return address.
			// - We then PUSH RBP, for 16 bytes of callee area.
			// - The amount we then subtract from ESP needs to leave
			//   ESP 16-byte aligned
			// - We just aligned arSize to 16, so add 8 to get the
			//   whole shebang aligned to 16
			//arSize += 8;

			// now patch the SUB(RSP, size) instruction in
			// the prologue.
			// 
			// if stack > 1 page then we need to touch each page
			// since windows expects stack to grow page by page.
			// 
			MDInstruction* current = mip;
			if (arSize > mirBuffer->pageSize())
			{
				// clobber the entire SUB(ESP, size) with a jmp to code that does
				// adjusts the stack and tickles each page in order
				mip = activation.adjustmentIns - 2; // -2 to step on the sub instruction, which is 6B long
				JMP(0x7FFFFFFF);					// jmp takes 5 bytes
				mdPatchPrevious(&patch_probe_stack);   // mark the location for patching
				NOP();								// 1 byte converted to nop
				mdLabel(&patch_probe_return, mip);	// mark where we want to return to 
			}
			else
			{
				// only need to adjust the SUB(ESP, ) instruction
				mip = activation.adjustmentIns;
				IMM32(arSize);
			}
			mip = current;

#ifndef _WIN64
			for (int i=0; i < 5; i++) {
#else //#ifdef _WIN64
			for (int i=0; i < 7; i++) {
#endif //#ifdef _WIN64
				OP* v = &calleeVars[i];
				if (v->reg == Unknown && v->pos != InvalidPos) {
					v->reg = (Register) v->imm;
					rematerialize(v);
				}
			}

			ADD(RSP, arSize); 
			POP  (RBP);
			//ALU(0xc9); // leave:  esp = ebp, pop ebp
		}
		RET  ();

		// Patch stack overflow check
		if (core->minstack)
		{
			// Patch the stack overflow check's frame size
			*(stackCheck.patchStackSize) = core->minstack + activation.highwatermark;

#ifdef AVMPLUS_VERBOSE
			if (verbose())
				core->console << "stackOverflow:\n";
#endif
			if (!pool->stackOverflowHandler)
			{
				pool->stackOverflowHandler = (uintptr)mip;

				#ifdef _MAC
					// Stack must be aligned at 16-byte boundary for MacOS X ABI.
					// The method did a CALL to stackOverflowHandler, so we're already
					// 4 bytes pushed from the original 16-byte stack alignment.
					PUSH(8, RSP); // env
					PUSH((sintptr)core);
					// _stackOverflow is needed because gcc can't take address
					// of a virtual method
					thincall(COREADDR(AvmCore::_stackOverflow));
					ADD64(RSP, 8);
                #elif defined(AVMPLUS_CDECL)
					// gcc version (Linux)
					PUSH(8, RSP); // env
					PUSH((sintptr)core);
					// _stackOverflow is needed because gcc can't take address
					// of a virtual method
					thincall(COREADDR(AvmCore::_stackOverflow));
					ADD64(RSP, 8);
				#else
				#ifndef _WIN64
					// Linux version
					PUSH(RDI);
					PUSH(RSI);
					SUB64(RSP, 16);
					MOV(RSI, RDI);  // env
					MOV(RDI, (sintptr)core);
					thincall(COREADDR(AvmCore::_stackOverflow));
					ADD64(RSP, 16);
					POP(RSI);
					POP(RDI);
				#else //#ifndef _WIN64
					// Windows version
					PUSH(RCX);
					PUSH(RDX);
					SUB64(RSP, 16);
					MOV(RDX, RCX);  // env
					MOV(RCX, (sintptr)core);
					thincall(COREADDR(AvmCore::stackOverflow));
					ADD64(RSP, 16);
					POP(RDX);
					POP(RCX);
				#endif //#ifndef _WIN64
				#endif

				RET();
			}
			// Patch the jump to jump to here, and generate
			// the call to the exception handler
			mdLabel(&stackCheck.overflowLabel, mip);
			thincall(pool->stackOverflowHandler);
			JMP(0x7FFFFFFF);
			mdPatchPrevious(&stackCheck.resumeLabel);
		}

		// > 1 page stack growth
		if (patch_probe_stack.nextPatch)
		{
			// patch the jmp _probe expression to the current
			// location where we emit the probe code
			mdLabel(&patch_probe_stack, mip);
			emitAllocaProbe(arSize, &patch_probe_return);
		}

		#endif /* AVMPLUS_AMD64 */
		
		// fix case tables.  Each entry contains the absolute bytecode
		// offset, we replace with absolute machine address
		// now that the code buffer is at a known starting address.
		uintptr* mdCasePtr = (uintptr*) &code[0];
		for(int i=0, n=case_count; i<n; i++, mdCasePtr++)
		{
			OP* ins = (OP*)*mdCasePtr;
			AvmAssertMsg(ins->code == MIR_bb && ins->pos != 0, "Case target MUST have been resolved by this point");
			*mdCasePtr = ins->pos;
		}

		// patch up the exception table
		if (info->exceptions)
		{
			// update exception tables for this method
			for (int i=0, n=info->exceptions->exception_count; i < n; i++)
			{
				ExceptionHandler* h = &info->exceptions->exceptions[i];
				OP* label = (OP*) h->target;
				AvmAssertMsg(label->code == MIR_bb && label->pos != 0, "Exception target MUST have been resolved by this point");
				h->target = label->pos;
			}
		}

		// mark method as been JIT'd
		info->flags |= AbstractFunction::TURBO;
			
		uintptr mipEnd = (uintptr) mip;
		(void)mipEnd;

		bindMethod(info);

#ifndef AVMPLUS_JIT_READONLY
		#if defined(_MAC) && defined(AVMPLUS_PPC)
		// Tell the OS that this buffer contains executable code.
		// This is required since machines like the G4 have dual
		// cache designs.
		MakeDataExecutable(mipStart, mipEnd-(int)mipStart);
		#endif /* _MAC && AVMPLUS_PPC */
#endif /* AVMPLUS_JIT_READONLY */

		#ifdef _DEBUG
		// not terminal but good to know if our epilogue estimation is off
		uintptr actual_epilogue_size = ( (uintptr)mipEnd - (uintptr)mipEpilog );
		AvmAssertMsg( actual_epilogue_size <= (uintptr)md_epilogue_size , "Increase md_epilogue_size estimate\n");
		if ((byte*)mipEnd >= pool->codeBuffer->end())
			AvmAssert(false);
		#endif /* DEBUG */

#if HAVE_MIR_SMOPS
	  // did these get patched?
	  AvmAssert(!lastMOPRangeCheckJmp);
#endif
	}

	/**
	 * Generic register allocation routine.
	 *
	 *   Pick a register for allocation and attempt to keep it 
	 *   live for as long as the instructions' lastUse field dictates. 
	 *   Optionally one can specify a particular register to be allocated.
	 *
	 *      IMPORTANT
	 * 
	 *   The caller is responsible for updating the reg field of the 
	 *   instruction.   For example,  ins->reg = registerAlloc(ins);
	 *	 And then calling either regs.addActive(ins) which adds the 
	 *   register to the active list or calling addFree() which
	 *   places the register back on the freelist .  Failure to do so 
	 *   will cause registers to leak from the allocators' view.
	 *
	 *   This function will always provide a register and may spill
	 *   in order to get one. 
	 * 
	 * @param ins    - instruction for which the register is to be used
	 * @param r      - particular register to obtain.
	 */

	CodegenMIR::Register CodegenMIR::registerAllocSpecific(RegInfo& regs, Register r)
	{
		AvmAssert(r != Unknown);
		if (regs.isFree(r))
		{
			// found the requested register on the free list
			//removeRegCount++;
			regs.removeFree(r);
		}
		else
		{
			// remove from active list, and spill it
			//removeRegCount++;
			OP* vic = regs.active[r];
			AvmAssert(vic != NULL);
			AvmAssert(vic->reg == r);

			#ifdef AVMPLUS_VERBOSE
			if (verbose() && vic->isDirty())
				core->console << "STEAL specific @" << InsNbr(vic) << "\n";
			#endif

			spill(vic);
			vic->reg = Unknown;
			regs.removeActive(r);
		}

	    #ifdef AVMPLUS_ARM
		// If the register allocated is nonvolatile, add it
		// to the mask.
		if (&regs == &gpregs)
		{
			regs.nonVolatileMask |= (rmask(r) & regs.calleeSaved);
		}
		else
		{
			gpregs.nonVolatileMask |= R4_mask | R5_mask;
		}
		#endif
		
		#ifdef AVMPLUS_PPC
		// Remember what was the lowest nonvolatile register
		// for stmw/lmw
		if ((rmask(r) & regs.calleeSaved) && r < regs.LowerBound)
			regs.LowerBound = r;
		#endif

		return r;
	}

	CodegenMIR::Register CodegenMIR::InsPrepResult(RegInfo& regs, OP* ins, int exclude)
	{
		Register r = ins->reg;
		int set = regs.free & ~exclude;

		if (r == Unknown) 
		{
			r = registerAllocAny(regs, ins);
		}
		else if (!(regs.free & rmask(r)) && set) 
		{
			// someone's using the one we want but there are other free regs.
			OP* vic = regs.active[r];
			vic->reg = registerAllocFromSet(regs, set);
			regs.addActive(vic);
			regs.removeActive(r);
			moveR2R(vic, r, vic->reg);
			// now r is free
		}
		else
		{
			registerAllocSpecific(regs, r);
		}
		setResultReg(regs, ins, r);
		return r;
	}

#if HAVE_MIR_SMOPS
#if defined(AVMPLUS_IA32) || defined(AVMPLUS_AMD64)		
	CodegenMIR::Register CodegenMIR::registerFor8Bit(RegInfo& regs, OP* value)
	{
		Register r;

		AvmAssert(&regs == &gpregs);
		// can only do 8 bit truncations
		// with these regs
		int set = EAX | EBX | ECX | EDX;

		// keep the register in the value if it's compatible
		if(set & rmask(value->reg))
			r = value->reg;
		// otherwise take a free reg
		else if(regs.free & set)
		{
			set &= regs.free;
			int i=0;
			while (!(set & rmask(i)))
				i ++;
			r = (Register)i;
		}
		// otherwise do a scan
		else
			r = regs.findLastActive(set)->reg;
		return r;
	}
#endif
#endif

	CodegenMIR::Register CodegenMIR::registerAllocAny(RegInfo& regs, OP* ins)
	{
		Register r = Unknown;

		int set = ins->liveAcrossCall ? regs.calleeSaved : ~regs.calleeSaved;
		if (set == 0) set = -1;

		if (!regs.free)
		{
			// nothing free, steal one from from desired set
			// LSRA says pick the one with the furthest use
			OP* vic = regs.findLastActive(set);

			if (!vic)
			{
				set = -1;
				vic = regs.findLastActive(set);
				AvmAssert(vic != NULL);
			}
			
			#ifdef AVMPLUS_VERBOSE
			if (verbose() && vic->isDirty())
				core->console << "STEAL any @" << InsNbr(vic) <<"\n";
			#endif

			spill(vic);
			regs.retire(vic);
		}

		// ok we have at least 1 free register so let's try to pick 
		// the best one given the profile of the instruction 

		if (!(set &= regs.free))
		{
			// desired register class is not free so pick first of any class
			set = regs.free;
		}

		AvmAssert(set != 0);

		r = registerAllocFromSet(regs, set);
		
		return r;
	}

	CodegenMIR::Register CodegenMIR::registerAllocFromSet(RegInfo& regs, int set)
	{
	#ifdef AVMPLUS_PPC

		// On PowerPC, prefer higher registers, to minimize
		// size of nonvolatile area that must be saved.
		register int i;
		#ifdef __GNUC__
		asm ("cntlzw %0,%1" : "=r" (i) : "r" (set));
		#else // __GNUC__
		// Soothe Codewarrior's upset soul
		register uint32 in = set;
		asm 
		{
			cntlzw i,in;
		}
		#endif // __GNUC__
		i = 31-i;
		regs.free &= ~rmask(i);

		// Remember what was the lowest nonvolatile register
		// for stmw/lmw
		if ((rmask(i) & regs.calleeSaved) && i < (int)regs.LowerBound)
			regs.LowerBound = i;

		return (Register) i;

	#elif defined(AVMPLUS_WIN32)

		#ifdef AVMPLUS_AMD64
			unsigned long index;
			_BitScanForward(&index, set);
			regs.free &= ~rmask(index);
			return (Register)index;
		#elif AVMPLUS_ARM
		// need to implement faster way
		int i=0;
		while (!(set & rmask(i)))
			i ++;
		regs.free &= ~rmask(i);
		return (Register) i;
		#else
		// TODO: translate to AT&T notation for Macintel
		Register r;
		_asm
		{
			mov ecx, regs
			bsf eax, set				// i = first bit set
			btr RegInfo::free[ecx], eax	// free &= ~rmask(i)
			mov r, eax
		}
		return r;
		#endif
	#elif defined(_MAC) && (defined(AVMPLUS_IA32) || defined(AVMPLUS_AMD64))
		Register r;
		asm(
			"bsf	%1, %%eax\n\t"
			"btr	%%eax, %2\n\t"
			"movl	%%eax, %0\n\t"
			: "=m"(r) : "m"(set), "m"(regs.free) : "%eax", "memory" );
		return r;
    #elif defined AVMPLUS_ARM

#ifdef UNDER_CE
		// need to implement faster way
		int i=0;
		while (!(set & rmask(i)))
			i ++;
		regs.free &= ~rmask(i);
		return (Register) i;

#elif defined (__ARMCC__)
		register int i;
		__asm { clz i,set }
		i = 31 - i;
		regs.free &= ~rmask(i);
#else
		// Note: The clz instruction only works on armv5 and up.
		register int i;
		asm("clz %0,%1" : "=r" (i) : "r" (set));
		i = 31-i;
		regs.free &= ~rmask(i);
#endif

		// If the register allocated is nonvolatile, add it
		// to the mask.
		if (&regs == &gpregs)
		{
			regs.nonVolatileMask |= (rmask(i) & regs.calleeSaved);
		}
		else
		{
			gpregs.nonVolatileMask |= R4_mask | R5_mask;
		}

		return (Register) i;		
		
	#else  // generic algorithm

		int i=0;
		while (!(set & rmask(i)))
			i ++;
		regs.free &= ~rmask(i);

		return (Register) i;
		
	#endif
	}


	/**
	 * Prep an instruction for issuance.  
	 * 
	 * Here's where we perform the guts of deciding which registers should
	 * be bound to which operands for a given instruction.   The restrictions
	 * are defined by registers called reqdA/B, which contain register requirements
	 * for each A/B instruction.  'Unknown' is used to denote that there are 
	 * no register requirements for the instruction.
	 *
	 * Once this call returns all provided operand instructions are 
	 * guaranteeed to be available in registers.   The reqd variables will be
	 * filled with the registers to be used for the MD instruction.
	 * 
	 * @param insA/B  - operands that are required for MD instruction
	 * @param reqdA/B - IN: specific MD register reservations that must occur for the instruction
	 *                  OUT:the actual register assigned for the instruction 
	 */


	// preperation for a single operand and a result
	void CodegenMIR::InsRegisterPrepA(OP* insRes, RegInfo& regsA, OP* insA, Register& reqdA)
	{
		AvmAssert(insRes != 0);
		AvmAssert(insA != 0);

		if (insA->lastUse <= insRes)
			insA->liveAcrossCall = 0;

		// a single instruction?
		Register rA = insA->reg;
		if (rA == Unknown)
		{
			// curr |= (_OUT)
			AvmAssert(rA == Unknown);
			insA->reg = registerAlloc(regsA, insA, reqdA);

			AvmAssert(insA->reg != Unknown);				
			regsA.addActive(insA);
			rematerialize(insA);
		}
		else
		{
			if (reqdA == Unknown)
			{
				//curr |= (IN_ANY);
				AvmAssert(rA != Unknown);
			}
			else if (reqdA == rA)
			{
				//curr |= (IN_REQ);
			}
			else 
			{
				AvmAssert(reqdA != Unknown);
				//curr |= (IN_WRONG);

				// free A and realloc
				regsA.retire(rA);
				insA->reg = registerAllocSpecific(regsA, reqdA);
				AvmAssert(insA->reg != rA);
				moveR2R(insA, rA, insA->reg);
				regsA.addActive(insA);
			}
		}
		reqdA = insA->reg;

		// now we've done the input registers let pick one for the result
		// but first we need to update the state of the allocator
		// to reflect the fact that the instruction is complete
		
		regsA.expire(insA, insRes);
	}

	// preperation for two operands A and B and a result
	void CodegenMIR::InsRegisterPrepAB(OP* insRes, RegInfo& regsA, OP* insA, Register& reqdA, RegInfo& regsB, OP* insB, Register& reqdB)
	{
		AvmAssert( !(reqdA != Unknown && reqdB != Unknown) );

		/**
		 * Each input may be in 1 of 4 possible states.  IN_REQ, IN_WRONG, IN_ANY, OUT
		 * 
		 * In the main switch we concern ourselves with only 2 inputs; A and B.  This
		 * is because we only need to deal with a maximum of 2 input instructions at a time
		 * That is insA and insB.
		 * 
		 * We really have 5 possible states, since we also have OUT_REQ and OUT_ANY.
		 * But 2 inputs by 5 states gives a total of 25 states, which is a little too painful
		 * to enumerate, so we combine the OUT states together, giving a 4x4 matrix. 
		 * We take advantage of the fact that its symmetrical so we don't need to 
		 * complete all cells within it; only 8 are needed (belch!).  We can 
		 * swap A, B and proceed accordingly; that's what all the ugly #defines are for.
		 */
		AvmAssert(insRes != 0);
		AvmAssert(insA != 0);
		AvmAssert(insB != 0);

		if (&regsA != &regsB)
		{
			// allocating from different sets of regs is easy
			InsRegisterPrepA(insRes, regsA,   insA,   reqdA);
			InsRegisterPrepA(insRes, regsB,   insB,   reqdB);
			return;
		}

		if (insA->lastUse <= insRes) insA->liveAcrossCall = 0;
		if (insB->lastUse <= insRes) insB->liveAcrossCall = 0;

		/*
		 * Handle the special case where insA and insB are the same.
		 * This happens when things like 2+2 are encountered.
		 */
		if (insA == insB) 
		{
			if (reqdB != Unknown)
				reqdA = reqdB;

			InsRegisterPrepA(insRes, regsA, insA, reqdA);
			reqdB = reqdA;
			return;
		}

		RegInfo& regs = regsA; // same as regsB

		// classify A first 
		if (insA->reg == Unknown)
		{
			// curr |= (_OUT)
			if (insB->reg == Unknown)
			{
				//curr |= (_OUT);
				InsPrep_A_OUT_B_OUT(regs, insA, reqdA, insB, reqdB);
			}
			else
			{
				// IN
				if (reqdB == Unknown)
				{
					//curr |= (IN_ANY);
					#define InsPrep_A_OUT_B_IN_ANY(regs, iA, rA, iB, rB) InsPrep_A_IN_ANY_B_OUT(regs, iB, rB, iA, rA)
					InsPrep_A_OUT_B_IN_ANY(regs, insA, reqdA, insB, reqdB);
				}
				else if (reqdB == insB->reg)
				{
					//curr |= (IN_REQ);
					#define InsPrep_A_OUT_ANY_B_IN_REQ(regs, iA, rA, iB, rB) InsPrep_A_IN_REQ_B_OUT_ANY(regs, iB, rB, iA, rA)
					#define InsPrep_A_OUT_REQ_B_IN_REQ(regs, iA, rA, iB, rB) InsPrep_A_IN_REQ_B_OUT_REQ(regs, iB, rB, iA, rA)
					if (reqdA == Unknown)
    					InsPrep_A_OUT_ANY_B_IN_REQ(regs, insA, reqdA, insB, reqdB);
					else
    					InsPrep_A_OUT_REQ_B_IN_REQ(regs, insA, reqdA, insB, reqdB);
				}
				else 
				{
					//curr |= (IN_WRONG);
					#define InsPrep_A_OUT_B_IN_WRONG(regs, iA, rA, iB, rB) InsPrep_A_IN_WRONG_B_OUT(regs, iB, rB, iA, rA)
					InsPrep_A_OUT_B_IN_WRONG(regs, insA, reqdA, insB, reqdB);
				}
			}
		}
		else
		{
			if (reqdA == Unknown)
			{
				//curr |= (IN_ANY);
				if (insB->reg == Unknown)
				{
					// curr |= (_OUT)
					InsPrep_A_IN_ANY_B_OUT(regs, insA, reqdA, insB, reqdB);
				}
				else
				{
					// IN
					if (reqdB == Unknown)
					{
						//curr |= (IN_ANY);
						reqdA = insA->reg;
						reqdB = insB->reg;
					}
					else if (reqdB == insB->reg)
					{
						//curr |= (IN_REQ);
						reqdA = insA->reg;
					}
					else 
					{
						//curr |= (IN_WRONG);
						#define InsPrep_A_IN_ANY_B_IN_WRONG(regs, iA, rA, iB, rB) InsPrep_A_IN_WRONG_B_IN_ANY(regs, iB, rB, iA, rA)
						InsPrep_A_IN_ANY_B_IN_WRONG(regs, insA, reqdA, insB, reqdB);
					}
				}
			}
			else if (reqdA == insA->reg)
			{
				//curr |= (IN_REQ);
				if (insB->reg == Unknown)
				{
					// curr |= (_OUT)
					if (reqdB == Unknown)      
						InsPrep_A_IN_REQ_B_OUT_ANY(regs, insA, reqdA, insB, reqdB);
					else
						InsPrep_A_IN_REQ_B_OUT_REQ(regs, insA, reqdA, insB, reqdB);
				}
				else
				{
					// IN
					if (reqdB == Unknown)
					{
						//curr |= (IN_ANY);
						reqdB = insB->reg;
					}
					else if (reqdB == insB->reg)
					{
						//curr |= (IN_REQ);
						// nothing to do
					}
					else 
					{
						//curr |= (IN_WRONG);
						InsPrep_A_IN_REQ_B_IN_WRONG(regs, insA, reqdA, insB, reqdB);
					}
				}
			}
			else 
			{
				//curr |= (IN_WRONG);
				if (insB->reg == Unknown)
				{
					// curr |= (_OUT)
					InsPrep_A_IN_WRONG_B_OUT(regs, insA, reqdA, insB, reqdB);
				}
				else
				{
					// IN
					if (reqdB == Unknown)
					{
						//curr |= (IN_ANY);
						InsPrep_A_IN_WRONG_B_IN_ANY(regs, insA, reqdA, insB, reqdB);
					}
					else if (reqdB == insB->reg)
					{
						//curr |= (IN_REQ);
						#define InsPrep_A_IN_WRONG_B_IN_REQ(regs, iA, rA, iB, rB) InsPrep_A_IN_REQ_B_IN_WRONG(regs, iB, rB, iA, rA)
						InsPrep_A_IN_WRONG_B_IN_REQ(regs, insA, reqdA, insB, reqdB);
					}
					else 
					{
						//curr |= (IN_WRONG);
						AvmAssert(false);  // this case is not needed, since no current MD instruction 
										// requests specific registers for both A and B
#if 0
						InsPrep_A_IN_WRONG_B_IN_WRONG(regs, insA, reqdA, insB, reqdB);
#endif
					}
				}
			}
		}

		// now we've done the input registers 
		// we need to update the state of the allocator
		// to reflect the fact that the instruction is complete
		regsA.expire(insA, insRes);
		regsB.expire(insB, insRes);
	}
	
	void CodegenMIR::InsPrep_A_IN_REQ_B_IN_WRONG(RegInfo& regs, OP* insA, Register& reqdA, OP* insB, Register& reqdB)
	{
		AvmAssert(insA->reg == reqdA);
		AvmAssert(insB->reg != reqdB);
		AvmAssert(reqdA != Unknown);
		AvmAssert(reqdB != Unknown);
		AvmAssert(reqdA != reqdB);   // not supported!
		(void)insA;
		(void)reqdA;

		// free B and realloc
		Register rB = insB->reg;
		regs.retire(rB);
		insB->reg = registerAllocSpecific(regs, reqdB);
		AvmAssert(insB->reg != insA->reg);
		moveR2R(insB, rB, insB->reg);

		regs.addActive(insB);
		AvmAssert(reqdA == insA->reg);
		AvmAssert(reqdB == insB->reg);
	}
	
	void CodegenMIR::InsPrep_A_IN_REQ_B_OUT_REQ(RegInfo& regs, OP* insA, Register& reqdA, OP* insB, Register& reqdB)
	{
		AvmAssert(insA->reg == reqdA);
		AvmAssert(insB->reg == Unknown);
		AvmAssert(reqdA != Unknown);
		AvmAssert(reqdB != Unknown);
		AvmAssert(reqdA != reqdB);   // can't have A and B both be the same register
		(void)insA;
		(void)reqdA;

		insB->reg = registerAllocSpecific(regs, reqdB);

		AvmAssert(insB->reg != insA->reg);
		
		regs.addActive(insB);
		rematerialize(insB);

		AvmAssert(insA->reg == reqdA);
		AvmAssert(insA->reg == reqdB);
	}
	
	void CodegenMIR::InsPrep_A_IN_REQ_B_OUT_ANY(RegInfo& regs, OP* insA, Register& reqdA, OP* insB, Register& reqdB)
	{
		AvmAssert(insA->reg == reqdA);
		AvmAssert(insB->reg == Unknown);
		AvmAssert(reqdA != Unknown);
		AvmAssert(reqdB == Unknown);
		(void)reqdA;

		// insA has the required register, and we need one for B. 
		Register rA = insA->reg;

		// if there are free regs, we know rA wont be chosen.  Otherwise, 
		// when all regs are in use, allocating B could spill rA. we dont want that
		// so we take A out of the active list so its ignored by stealLastActive().

		AvmAssert(regs.active[rA] == insA);
		regs.active[rA] = NULL; // force allocator to choose something other than rA
		insB->reg = registerAllocAny(regs, insB);
		regs.active[rA] = insA;

		AvmAssert(insA->reg == rA); // make sure insA wasn't spilled
		AvmAssert(insB->reg != Unknown && insB->reg != rA); // make sure insB got a different register

		regs.addActive(insB);
		rematerialize(insB);
		reqdB = insB->reg;
	}
	
#if 0
	void CodegenMIR::InsPrep_A_IN_WRONG_B_IN_WRONG(RegInfo& regs, OP* insA, Register& reqdA, OP* insB, Register& reqdB)
	{
		AvmAssert(insA->reg != reqdA);
		AvmAssert(insB->reg != reqdB);
		AvmAssert(reqdA != Unknown);
		AvmAssert(reqdB != Unknown);
		AvmAssert(reqdA != reqdB);   // not supported!

		Register rA = insA->reg;
		Register rB = insB->reg;
		regs.retire(rA);
		regs.retire(rB);

		//@todo not quite correct as allocator may wish
		// to spill A for B, meaning we'd A should be in a temp
		insA->reg = registerAllocSpecific(regs, reqdA);
		insB->reg = registerAllocSpecific(regs, reqdB);
		AvmAssert(insA->reg != insB->reg);
		if (rA == insB->reg && rB == insA->reg)
		{
			// swap	A and B
			AvmAssert(false);  // not supported!
		}
		else if (rA == insB->reg)
		{
			// A current register is going to be 
			// used by insB, so we need to clear
			// it out before clobbering it. 
			moveR2R(insA, rA, insA->reg);
			moveR2R(insB, rB, insB->reg);
		}				
		else
		{
			// we know that the above doesn't apply so 
			// it safe to clobber insB's register.
			moveR2R(insB, rB, insB->reg);
			moveR2R(insA, rA, insA->reg);
		}				
		regs.addActive(insA);
		regs.addActive(insB);
		reqdA = insA->reg;
		reqdB = insB->reg;
	}
#endif
	
	void CodegenMIR::InsPrep_A_IN_WRONG_B_IN_ANY(RegInfo& regs, OP* insA, Register& reqdA, OP* insB, Register& reqdB)
	{
		Register rA = insA->reg;
		Register rB = insB->reg;

		AvmAssert(rA != Unknown);
		AvmAssert(rA != reqdA);
		AvmAssert(rB != Unknown);
		AvmAssert(reqdA != Unknown);
		AvmAssert(reqdB == Unknown);


		regs.retire(rA); // take A off active list and return to free list
		insA->reg = registerAllocSpecific(regs, reqdA);

		if (reqdA == rB) 
		{
			// All we need to do is swap A and B
			registerAllocSpecific(regs, rA);
			#ifdef AVMPLUS_SPARC
			moveR2R(insA, rA, L0);
			moveR2R(insA, rB, rA);
			moveR2R(insA, L0, rB);
            #endif /* AVMPLUS_SPARC */

			#ifdef AVMPLUS_PPC
			moveR2R(insA, rA, R0);
			moveR2R(insA, rB, rA);
			moveR2R(insA, R0, rB);
            #endif /* AVMPLUS_PPC */

			#ifdef AVMPLUS_ARM
			moveR2R(insA, rA, R0);
			moveR2R(insA, rB, rA);
			moveR2R(insA, R0, rB);
			#endif /* AVMPLUS_ARM */
			
			#if defined(AVMPLUS_IA32) || defined(AMVPLUS_AMD64)
			XCHG(rA, rB);
			#endif /* AVMPLUS_IA32 */

			rB = rA;
			regs.addFree(rA);
		}
		else 
		{
			// kicked out B?
			if (rB == insA->reg)
			{
				// allocator spilled rB and gave it to A, so we need a temp register for B
				Register t = registerAllocAny(regs, insB);
				moveR2R(insB, rB, t);
				insB->reg = rB = t;
				regs.addActive(insB);
			}
			moveR2R(insA, rA, insA->reg);
		}
		
		regs.addActive(insA);
		AvmAssert(insA->reg == reqdA);//reqdA = insA->reg;
		reqdB = rB;
	}
	
	void CodegenMIR::InsPrep_A_IN_WRONG_B_OUT(RegInfo& regs,
		OP* insA, Register& reqdA,
		OP* insB, Register& reqdB
		)
	{
		AvmAssert(insA->reg != reqdA);
		AvmAssert(insB->reg == Unknown);
		AvmAssert(reqdA != Unknown);

		// get A now either use rA for B or alloc it
		Register rA = insA->reg;

		regs.removeActive(rA);
		insA->reg = registerAllocSpecific(regs, reqdA);

		if (reqdB == Unknown)
		{
			insB->reg = rA;
		}
		else
		{
			AvmAssert(reqdB != Unknown);
			regs.addFree(rA); // back to the freelist
			insB->reg = registerAllocSpecific(regs, reqdB);
		}

		moveR2R(insA, rA, insA->reg);

		regs.addActive(insA);
		regs.addActive(insB);
		rematerialize(insB);

		AvmAssert(reqdA == insA->reg);
		reqdB = insB->reg;
	}

	// A_IN_ANY 
	/*
	case A_IN_ANY_B_IN_REQ:
		swapAB(A_IN_REQ_B_IN_ANY);
		break;

	case A_IN_ANY_B_IN_WRONG:
		swapAB(A_IN_WRONG_B_IN_ANY);
		break;
	*/
	
	void CodegenMIR::InsPrep_A_IN_ANY_B_OUT(RegInfo& regs, OP* insA, Register& reqdA, OP* insB, Register& reqdB)
	{
		AvmAssert(insA->reg != Unknown);
		AvmAssert(insB->reg == Unknown);
		AvmAssert(reqdA == Unknown);

		Register rA = insA->reg;
		insB->reg = registerAlloc(regs, insB, reqdB);

		// A/B conflict?
		if (rA == insB->reg && insA->isDouble() == insB->isDouble())
		{
			// allocator spilled rA and gave it to B, so we need a temp register for A
			Register t = registerAllocAny(regs, insA);
			moveR2R(insA, rA, t);
			insA->reg = rA = t;
			regs.addActive(insA);
		}

		regs.addActive(insB);
		rematerialize(insB);
		reqdA = rA;
		reqdB = insB->reg;
	}
	
	// A_OUT
	/*
	case A_OUT_B_IN_REQ:
		swapAB(A_IN_REQ_B_OUT);
		break;

	case A_OUT_B_IN_WRONG:
		swapAB(A_IN_WRONG_B_OUT);
		break;

	case A_OUT_B_IN_ANY:
		swapAB(A_IN_ANY_B_OUT);
		break;
	*/

	void CodegenMIR::InsPrep_A_OUT_B_OUT(RegInfo& regs, OP* insA, Register& reqdA, OP* insB, Register& reqdB)
	{	
		AvmAssert(insA->reg == Unknown);
		AvmAssert(insB->reg == Unknown);

		// if there are requirements order it
		// @todo not quite correct since A alloc may spill
		// B and visa versa, should use a temp.
		if (reqdA != Unknown)
		{
			insA->reg = registerAllocSpecific(regs, reqdA);
			insB->reg = registerAlloc(regs, insB, reqdB);
		}
		else
		{
			insB->reg = registerAlloc(regs, insB, reqdB);
			reqdA = insA->reg = registerAllocAny(regs, insA);
		}
		regs.addActive(insA);
		regs.addActive(insB);

		AvmAssert(insA->isDouble() != insB->isDouble() || insA->reg != insB->reg);
		rematerialize(insA);
		rematerialize(insB);
		reqdB = insB->reg;
	}

	// instruction type specific machine regiser to register move 
	void CodegenMIR::moveR2R(OP* ins, Register src, Register dst)
	{
		#ifdef AVMPLUS_SPARC
		if (ins->isDouble())
			FMOVD(src, dst);
		else
			OR(src, G0, dst);
		#endif /* AVMPLUS_SPARC */

		#ifdef AVMPLUS_PPC
		if (ins->isDouble())
			FMR(dst, src);
		else
			MR(dst, src);
		#endif /* AVMPLUS_PPC */

		#ifdef AVMPLUS_ARM
		// There is only one FP register in ARM, so this should never
		// be entered.
		(void) ins;
		AvmAssert(!ins->isDouble());
		MOV(dst, src);
		#endif /* AVMPLUS_ARM */

		#ifdef AVMPLUS_IA32
		AvmAssert(src != Unknown && dst != Unknown && src != dst);
		AvmAssert(!ins->isDouble() || core->config.sse2);
		if (ins->isDouble())
			MOVAPD(dst, src);
		else
			MOV(dst, src);
		#endif /* AVMPLUS_IA32 */
		
		#ifdef AVMPLUS_AMD64
		AvmAssert(src != Unknown && dst != Unknown && src != dst);
		AvmAssert(!ins->isDouble() || core->config.sse2);
		if (ins->isDouble())
			MOVAPD(dst, src);
		else
			MOV(dst, src);
		#endif /* AVMPLUS_IA32 */		
	}

	/**
	 * A register has already been picked to spill and now we do the deed
	 * This is the final act which will most likely generate MD instructions 
	 * and will update stack information for the instruction unless it 
	 * does not require stack storage.  
	 * 
	 * WARNING: It is up to the caller to clear the register information.
	 *          For example ins->reg = Unknown;
	 */
	void CodegenMIR::spill(OP* ins)
	{
		AvmAssert(ins->reg != Unknown);

		// first we want to make sure we don't spill easily 
		// rematerializable values including ones already on the stack
		if (ins->isDirty())
		{
			reserveStackSpace(ins);
			copyToStack(ins, ins->reg);		
		}
	}

	/**
	 * Place the value contained in a register on to the stack.
	 */
	void CodegenMIR::copyToStack(OP* ins, Register r)
	{
		int disp = stackPos(ins);
		#ifdef AVMPLUS_SPARC
		if (ins->isDouble())
			STDF32(r, disp, SP);    // r => d(SP)
		else
			STW32(r, disp, SP);    // r => d(SP)
        #endif /* AVMPLUS_SPARC */

		#ifdef AVMPLUS_PPC
		if (ins->isDouble())
			STFD32( r, disp, SP );    // r => d(SP)
		else
			STW32( r, disp, SP );    // r => d(SP)
        #endif /* AVMPLUS_PPC */

		#ifdef AVMPLUS_ARM
		if (ins->isDouble())
		{
			// The one FP "register" on ARM is R4-R5
			STR(R4, disp,   SP);
			STR(R5, disp+4, SP);
		}
		else
		{
			STR(r, disp, SP);
		}
		#endif /* AVMPLUS_ARM */

		#if defined (AVMPLUS_IA32) || defined(AVMPLUS_AMD64)
		if (!ins->isDouble()) {
			MOV(disp, framep, r);// r => d(EBP)
		} else if (core->config.sse2) {
			MOVSD(disp, framep, r); // r => d(EBP)
		} else {
			FSTQ(disp, framep);
		}
        #endif /* AVMPLUS_IA32 or AVMPLUS_AMD64 */
	}

	/**
	 * This method proceeds to place the value generated by the given 
	 * instruction into the register specified in the reg field of ins
	 * 
	 * This is the final act which will most likely generate MD instructions 
	 * 
	 * WARNING: It is up to the caller to have previously allocated a register
	 *          for this instruction and to have updated the register 
	 *			information.  For example op->reg = EAX;
	 */
	void CodegenMIR::rematerialize(OP* ins)
	{
		// in order to rematerializable values we need a 
		// stack position and a register number
		AvmAssert(ins->reg != Unknown);

		// It is believed that alloca is never rematerialized
		// into a register; special handling would be needed.
		AvmAssert(ins->code != MIR_alloc);

		if (ins->code == MIR_imm)
		{
			uint32 v = uint32(ins->imm);
			Register r =  ins->reg;
			#ifdef AVMPLUS_SPARC
			// todo add faster case for v=0? okay but make sure not to set cc's
			SET32(v, r);
			#endif

			#ifdef AVMPLUS_PPC
			// todo add faster case for v=0? okay but make sure not to set cc's
			LI32(r, v);
			#endif

			#ifdef AVMPLUS_ARM
			MOV_imm32(r, v);
			#endif
			
			#if defined (AVMPLUS_IA32)
			MOV(r, v);		// mov imm => r
			// [ed 12/4/05] when v==0, don't use XOR(r,r) because that sets cc's which
			// can screw up a later branch
			#endif /* AVMPLUS_PPC */ 

			#if defined (AVMPLUS_AMD64)
			(void)v;
			int64 v64 = int64(ins->imm);
			MOV(r, v64);
			#endif
		}
		else
		{
			// Must have already spilled it or located it on the stack
			AvmAssert(ins->pos != InvalidPos);
			int disp = stackPos(ins);

			// now generate the MD code for the stack move
			#ifdef AVMPLUS_SPARC
			if ( ins->isDouble() )
				LDDF32(SP, disp, ins->reg);   // argN(SP) => r
			else
				LDSW32(SP, disp, ins->reg);   // argN(SP) => r
			#endif

			// now generate the MD code for the stack move
			#ifdef AVMPLUS_PPC
			if ( ins->isDouble() )
				LFD32(ins->reg, disp, SP);   // argN(SP) => r
			else
				LWZ32(ins->reg, disp, SP);   // argN(SP) => r
			#endif

			#ifdef AVMPLUS_ARM
			if (ins->isDouble())
			{
				// We currently support one FP pseudo-register on ARM
				AvmAssert(ins->reg == F0);

				LDR(R4, disp,   SP);
				LDR(R5, disp+4, SP);
			}
			else
			{
				LDR(ins->reg, disp, SP);
			}
			#endif

			#if defined (AVMPLUS_IA32) || defined(AVMPLUS_AMD64)
			if ( ins->isDouble() )
			{
				Register r = ins->reg;
				(void)r;
				if (core->config.sse2)
				{
					MOVSD(ins->reg, disp, framep);     // argN(ESP) => r
				}
				else
				{
					AvmAssert(r == FST0);
					FFREE(FST7);
					FLDQ(disp, framep);
				}
			}
			else
			{
				MOV(ins->reg, disp, framep);  // argN(ESP) => r
			}
			#endif
		}
	}

#ifdef _DEBUG
	void CodegenMIR::RegInfo::checkActives(OP* current)
	{
		for (int i=0; i < MAX_REGISTERS; i++)
		{
			OP* ins = active[i];
			AvmAssert(!ins || ins->lastUse > current);
		}
	}
#endif

	uint32 CodegenMIR::spillCallerRegisters(OP* current, RegInfo& regs, uint32 live)
	{
		AvmAssert(live);
		AvmAssert((live&regs.calleeSaved) == 0);  // we're only spill scratch regs
		uint32 flush = 0;
		int saved = regs.calleeSaved;

		for (int i=0; i < MAX_REGISTERS; i++)
		{
			OP* ins;
			if ((rmask(i) & live) && (ins = regs.active[i]) != 0 && ins->lastUse > current)
			{
				int freesaved = saved & regs.free;
				if (freesaved) 
				{
					// use a free calleeSaved reg
					Register r = registerAllocFromSet(regs, freesaved);
					moveR2R(ins, ins->reg, r);
					regs.retire(ins);
					ins->reg = r;
					regs.addActive(ins);
					continue;
				}
				
				if (saved && ins->isDirty())
				{
					// steal a saved reg
					OP* vic = regs.findLastActive(saved);
					if (ins->lastUse < vic->lastUse)
					{
						spill(vic);
						Register r = vic->reg;
						regs.removeActive(r);
						vic->reg = Unknown;
						moveR2R(ins, ins->reg, r);
						regs.retire(ins);
						ins->reg = r;
						regs.addActive(ins);
						continue;
					}
				}

				#ifdef AVMPLUS_VERBOSE
				if (verbose() && ins->isDirty())
					core->console << "SAVE scratch @" << InsNbr(ins) << "\n";
				#endif
				spill(ins);
				flush |= rmask(i);
			}
		}
		return flush;
	}

	/**
	 * Remove any caller save registers from the active list
	 * and remove any register settings on them.
	 */
	void CodegenMIR::RegInfo::flushCallerActives(uint32 flush)
	{
		AvmAssert(flush);
		for (int i=0; i < MAX_REGISTERS; i++)
			if (rmask(i) & flush)
				retire(active[i]);
	}

	int CodegenMIR::prepCallArgsOntoStack(OP* call, OP* postCall)
	{
		// postCall >= call && postCall < next
		int argc = call->argc;

		// spill any registers live after the call (args are placed after the call)
		// This call will not free the registers so that we're able to put 
		// the args on the stack without rematerializing them.

		uint32 livegp;
		if ((livegp = ~gpregs.calleeSaved & ~gpregs.free) != 0)
			livegp = spillCallerRegisters(postCall, gpregs, livegp);

		uint32 livefp;
		if ((livefp = ~fpregs.calleeSaved & ~fpregs.free) != 0)
			livefp = spillCallerRegisters(postCall, fpregs, livefp);

		#ifdef AVMPLUS_SPARC
		int GPRIndex = O0;
		int FPRIndex = F2;
		int offset = kLinkageAreaSize;
		for(int i=1; i<=argc; i++)
		{
			OP*		argVal	 = call->args[i];
			bool	isDouble = argVal->isDouble();
			RegInfo *argRegs;

			Register r;
			if (isDouble) 
			{
				r = (FPRIndex > F28) ? F0 : registerAllocSpecific(fpregs, (Register)FPRIndex);
				FPRIndex += 2;
				GPRIndex += 2;
				offset += 8;
				argRegs = &fpregs;
				livefp &= ~rmask(r);
			} 
			else 
			{
				// Note: R11 is used as the temp for a stack-based argument,
				// since R0 is needed for large-displacement stack offsets
				r = registerAllocSpecific(gpregs, (GPRIndex > O5) ? L1 : (Register)GPRIndex);
				GPRIndex++;
				offset += 4;
				argRegs = &gpregs;
				livegp &= ~rmask(r);
			}
			
			if (argVal->reg == Unknown)
			{
				argVal->reg = r;
				rematerialize(argVal);
				argVal->reg = Unknown;
			}
			else
			{
				// wrong spot
				moveR2R(argVal, argVal->reg, r);
			}

			if (isDouble) {
				STDF32(r, offset-8, SP);

				// We might be calling a varargs function.
				// So, make sure the GPR's are also loaded with
				// the value, or the stack contains it.
				if (GPRIndex-2 <= O5) {
					LDSW32(SP, offset-8, (Register)(GPRIndex-2));
				}
				if (GPRIndex-1 <= O5) {
					LDSW32(SP, offset-4, (Register)(GPRIndex-1));
				}
			} else {
				// For non-FP values, store on the stack only
				// if we've exhausted GPR's.
				if (r == L1) {
					STW32(r, offset-4, SP);
				}
			}

			if (r != F0) {
				argRegs->addFree(r);				
			}
		}
		int at = 0;
		#endif // AVMPLUS_SPARC
		#ifdef AVMPLUS_PPC

		int GPRIndex = R3;
		int FPRIndex = F1;
		int offset = kLinkageAreaSize;
		for(int i=1; i<=argc; i++)
		{
			OP*		argVal	 = call->args[i];
			bool	isDouble = argVal->isDouble();
			RegInfo *argRegs;

			Register r;
			if (isDouble) 
			{
				r = (FPRIndex >= F14) ? (Register)F0 : registerAllocSpecific(fpregs, (Register)FPRIndex);
				FPRIndex++;
				GPRIndex += 2;
				offset += 8;
				argRegs = &fpregs;
				livefp &= ~rmask(r);
			} 
			else 
			{
				// Note: R11 is used as the temp for a stack-based argument,
				// since R0 is needed for large-displacement stack offsets
				r = registerAllocSpecific(gpregs, (GPRIndex >= R11) ? (Register)R11 : (Register)GPRIndex);
				GPRIndex++;
				offset += 4;
				argRegs = &gpregs;
				livegp &= ~rmask(r);
			}
			
			if (argVal->reg == Unknown)
			{
				argVal->reg = r;
				rematerialize(argVal);
				argVal->reg = Unknown;
			}
			else
			{
				// wrong spot
				moveR2R(argVal, argVal->reg, r);
			}

			if (isDouble) {
				STFD32(r, offset-8, SP);

				// We might be calling a varargs function.
				// So, make sure the GPR's are also loaded with
				// the value, or the stack contains it.
				if (GPRIndex-2 <= R10) {
					LWZ32((Register)(GPRIndex-2), offset-8, SP);
				}
				if (GPRIndex-1 <= R10) {
					LWZ32((Register)(GPRIndex-1), offset-4, SP);
				}
			} else {
				// For non-FP values, store on the stack only
				// if we've exhausted GPR's.
				if (r == R11) {
					STW32(r, offset-4, SP);
				}
			}

			if (r != F0) {
				argRegs->addFree(r);				
			}
		}
		int at = 0;
		#endif

		#ifdef AVMPLUS_ARM
		int GPRIndex = R0;
		int offset = -16; // Don't store into stack until R0-R3 exhausted
		for(int i=1; i<=argc; i++)
		{
			OP*		argVal	 = call->args[i];
			bool	isDouble = (argVal->isDouble()? true : false);
			RegInfo *argRegs;

			Register r;
			if (isDouble) 
			{
				r = registerAllocSpecific(fpregs, F0);
				GPRIndex += 2;
				offset += 8;
				argRegs = &fpregs;
				livefp &= ~rmask(r);
			}
			else 
			{
				// Note: IP is used as the temp for a stack-based argument
				r = registerAllocSpecific(gpregs, (GPRIndex > R3) ? R10 : (Register)GPRIndex);
				GPRIndex++;
				offset += 4;
				argRegs = &gpregs;
				livegp &= ~rmask(r);
			}

			if (argVal->reg == Unknown)
			{
				argVal->reg = r;
				rematerialize(argVal);
				argVal->reg = Unknown;
			}
			else
			{
				// wrong spot
				moveR2R(argVal, argVal->reg, r);
			}

			if (isDouble) {
				// Store F0's lower half into stack or register
				if (GPRIndex-2 > R3)
				{
					STR(R4, offset-8, SP);
				}
				else
				{
					MOV((Register)(GPRIndex-2), R4);
				}

				// Store F0's upper half into stack or register
				if (GPRIndex-1 > R3)
				{
					STR(R5, offset-4, SP);
				}
				else
				{
					MOV((Register)(GPRIndex-1), R5);
				}
			} else {
				// For non-FP values, store on the stack only
				// if we've exhausted GPR's.
				if (r == R10) {
					STR(r, offset-4, SP);
				}
			}

			argRegs->addFree(r);
		}
		int at = 0;
		#endif
		
		#if defined(AVMPLUS_AMD64)

		#ifdef _DEBUG
		for (uint32 k=0; k < activation.temps.size(); k++)
		{
			OP* ins = activation.temps[k];
			if (stackPos(ins) > 0 || stackPos(ins)==0 && ins->spillSize()>0)
			{
				#ifdef AVMPLUS_VERBOSE
				displayStackTable();
				#endif
				AvmAssert(false);
			}
		}
		#endif

#ifndef _WIN64
		const int REGCOUNT = 6;
		const Register intRegUsage[] = {RDI, RSI, RDX, RCX, R8, R9};
		const int FLOATREGCOUNT = 8;
		const Register floatRegUsage[] = {XMM0, XMM1, XMM2, XMM3, XMM4, XMM5, XMM6, XMM7};
		int GPRIndex = 0;
		int FloatIndex = 0;
#else //#if defined(_WIN64)
		// First 4 args into RCX, RDX, R8, R9, then the rest on
		// the stack
		const int REGCOUNT = 4;
		const Register intRegUsage[] = {RCX, RDX, R8, R9};
		const Register floatRegUsage[] = {XMM0, XMM1, XMM2, XMM3};
		// Need to make room on stack for ALL params (even the ones in registers)
		int at = -((((int32)(8*argc))+(15))&~(15));
		int GPRIndex = 0;
#endif //#if defined(_WIN64)

		int offset = -8;
		for(int i=0; i<argc; i++)
		{
			OP*		argVal	 = call->args[i+1];
			bool	isDouble = (argVal->isDouble()? true : false);
			RegInfo *argRegs;

			Register r;
			if (isDouble) 
			{
				#ifndef _WIN64
				r = registerAllocSpecific(fpregs, floatRegUsage[FloatIndex]);
				FloatIndex++;
				if ( FloatIndex > FLOATREGCOUNT ) {
					offset += 8;
				}
				#else //#ifndef _WIN64
				r = registerAllocSpecific(fpregs, floatRegUsage[GPRIndex]);
				GPRIndex++;
				offset += 8;
				#endif //#ifndef _WIN64
				argRegs = &fpregs;
				livefp &= ~rmask(r);
			}
			else 
			{
				// Value might already be in the correct register
				if (argVal->reg != ((GPRIndex >= REGCOUNT) ? R11 : (Register)intRegUsage[GPRIndex]))
				{
					// Note: R11 is used as the temp for a stack-based argument
					if (GPRIndex >= REGCOUNT)
						r = R11; //registerAllocSpecific(gpregs, R11);
					else
					{
#if 0
						r = registerAllocSpecific(gpregs, (Register)intRegUsage[GPRIndex]);
#else
						r = (Register)intRegUsage[GPRIndex];
						if (gpregs.isFree(r))
							gpregs.removeFree(r);
						else
						{
							// remove from active list, and spill it
							OP* vic = gpregs.active[r];
							AvmAssert(vic != NULL);
							AvmAssert(vic->reg == r);

							// use a free non-volatile reg if there is one available
							int freesaved = gpregs.calleeSaved & gpregs.free;
							if (freesaved)
							{
								// use a free calleeSaved reg
								Register newr = registerAllocFromSet(gpregs, freesaved);
								moveR2R(vic, vic->reg, newr);
								gpregs.retire(vic);
								vic->reg = newr;
								gpregs.addActive(vic);
								gpregs.removeFree(r);
							}
							else
							{
								spill(vic);
								vic->reg = Unknown;
								gpregs.removeActive(r);
							}
						}


#endif
					}
					GPRIndex++;
#ifndef _WIN64
					if (GPRIndex > REGCOUNT) {
						offset += 8;
					}
#else //#ifndef _WIN64
					offset += 8;
#endif //#ifndef _WIN64
					argRegs = &gpregs;
					livegp &= ~rmask(r);
				}
				else
				{
					GPRIndex++;
#ifndef _WIN64
					if (GPRIndex > REGCOUNT) {
						offset += 8;
					}
#else //#ifndef _WIN64
					offset += 8;
#endif //#ifndef _WIN64
					argRegs = &gpregs;
					continue;
				}
			}

			if (argVal->reg == Unknown)
			{
				argVal->reg = r;
				rematerialize(argVal);
				argVal->reg = Unknown;

				if (r == R11)
					MOV(offset, RSP, r);
			}
			else
			{
				if (r == R11)
					MOV(offset, RSP, argVal->reg);
				else // wrong spot ??
					moveR2R(argVal, argVal->reg, r);
			}

			// R11 is temp, don't add to free list
			if (r!=R11)
				argRegs->addFree(r);
		}
		#ifndef _WIN64
		int at = -((((int32)(offset+8))+(15))&~(15));
		#endif //#ifndef _WIN64
		#endif // AVMPLUS_AMD64

		#if defined (AVMPLUS_IA32)

		#ifdef _DEBUG
		for (uint32 k=0; k < activation.temps.size(); k++)
		{
			OP* ins = activation.temps[k];
			if (stackPos(ins) > 0 || stackPos(ins)==0 && ins->spillSize()>0)
			{
				#ifdef AVMPLUS_VERBOSE
				displayStackTable();
				#endif
				AvmAssert(false);
			}
		}
		#endif

		// anything that needs spilling has been spilled.  now we can just
		// push things onto the stack in reverse order, and stuff the last
		// arg into ECX if it's a method call.

		int adj = 0;
		int stop = (call->code & ~MIR_float & ~MIR_oper) == MIR_cm ? 2 : 1;
		for(int i=argc; i >= stop; i--)
		{
			OP*	p = call->args[i];
			Register r = p->reg;

			#ifdef AVMPLUS_VERBOSE
			if (verbose())
				core->console << "    arg @" << InsNbr(p) << "\n";
			#endif

			if (p->code == MIR_imm)
			{
				PUSH (p->imm);
				adj += 4;
			}
			else if (r != Unknown)
			{
				if (p->isDouble())
				{
					if (core->config.sse2)
					{
						MOVSD (-8, ESP, r);
						SUB   (ESP, 8);
						adj += 8;
					}
					else
					{
						AvmAssert(r == FST0);
						FSTQ (-8, ESP);
						SUB  (ESP,8);
						adj += 8;
					}
				}
				else
				{
					// push gp reg
					PUSH (r);
					adj += 4;
				}
			}
			else
			{
				AvmAssert(p->pos != InvalidPos);
				int disp = stackPos(p);
				if (framep == ESP) disp += adj;
				if (p->isDouble())
				{
					// push double from stack frame
					PUSH(disp+4, framep);
					if (disp == ESP) disp += 4;
					PUSH(disp, framep);
					adj += 8;
				}
				else
				{
					// push 32bits from memory to stack
					PUSH(disp, framep);
					adj += 4;
				}
			}
		}

		if (stop == 2)
		{
			// put last arg in ECX
			AvmAssert(argc >= 1);
			OP* p = call->args[1];
			AvmAssert(!p->isDouble());

#ifdef AVMPLUS_VERBOSE
			if (verbose())
			{
				core->console << "    arg @" << InsNbr(p) << "\n";
			}
#endif

			OP* ecx = gpregs.active[ECX];
			if (ecx != p)
			{
				if (ecx)
				{
					// will have been spilled already if needed.
					gpregs.retire(ecx);
					livegp &= ~rmask(ECX);
				}

				// now ECX is free

				if (p->reg == Unknown)
				{
					// need to load into ECX
					if (p->code == MIR_imm)
						MOV (ECX, p->imm);
					else {
						int disp = stackPos(p);
						if (framep == ESP) disp += adj;
						MOV(ECX, disp, framep);
					}
				}
				else
				{
					// need to move from another register to ECX
					moveR2R(p, p->reg, ECX);
				}
			}
		}

		int at = -adj;

		#endif
		
		// remove caller saved registers, since we have already spilled
		// and emited them as args.  
		if (livegp)
			gpregs.flushCallerActives(livegp);
		if (livefp)
			fpregs.flushCallerActives(livefp);

		// note our final stack position
		return at;
	}

	// converts an instructions 'pos' field to a stack pointer relative displacement
	int CodegenMIR::stackPos(OP* ins)
	{
		#ifdef AVMPLUS_SPARC
		return ins->pos + kLinkageAreaSize + calleeAreaSize();
		#endif

		#ifdef AVMPLUS_PPC
		return ins->pos + kLinkageAreaSize + calleeAreaSize();
		#endif

        #ifdef AVMPLUS_ARM
		return ins->pos + calleeAreaSize();
        #endif
		
		#if defined (AVMPLUS_IA32) || defined(AVMPLUS_AMD64)
		return int(-ins->pos - ins->spillSize()); 
		#endif
	}

	/**
	 * Find a location on the stack in which the result
	 * of the given instruction can be safely put.
	 */
	void CodegenMIR::reserveStackSpace(OP* forIns, bool bAlign)
	{
		(void)bAlign;
		// search the stack for a spot which is
		// free and is large enough
		sintptr at = InvalidPos;
		int bytes = forIns->spillSize();
		int n=activation.temps.size();

		if (n == 0)
		{
			#ifdef AVMPLUS_IA32
			
			#ifdef _MAC
			if (patch_esp_padding)
			{
				SUB(ESP,0);
				patch_esp_padding = mip-1;
			}
			#endif /* _MAC */
			#endif /* AVMPLUS_IA32 */
		}
		else
		{
			for(int i=0; i < n; i++)
			{
				OP* ins = activation.temps.get(i);

				// if space is vacant see if its a good match
				if (ins->lastUse < ip && bytes == ins->spillSize())
				{
					at = ins->pos;
					// can't do this b/c the value may be extracted later like for npe code
					//ins->pos = InvalidPos; // record that we stole the stack slot
					activation.temps.set(i, forIns); // replacement entry
					break;
				}
			}
		}

		// if no hits then 'alloc' a new spot making sure 8B quantities are correctly addressed
		if (at == InvalidPos)
		{
			// record stack position before growth
			at = activation.size;

#ifdef AVMPLUS_AMD64
			if (bAlign)
			{
				// needs to be 16-byte aligned on stack
				int32 newSize = ((((int32)(activation.size+bytes))+(15))&~(15));
				bytes += (newSize - activation.size - bytes);
			}

#endif
			// new entry grows the table / stack
			activation.size += bytes;

			activation.temps.add(forIns);
			
			// ensure our watermark is updated
			int lastPos = int(at + bytes);
			if ( lastPos > activation.highwatermark)
				activation.highwatermark = lastPos;
		}

		// update its location on the stack
		AvmAssert(at >= 0);
		forIns->pos = at;
		AvmAssert(at == forIns->pos); // check for sign extension bugs

		#ifdef AVMPLUS_VERBOSE
		if (verbose())
		{
			core->console << "                         alloca " << bytes << " at " << int(at) 
				      << " for @" << int(forIns-ipStart) 
				<< " activation.size " << activation.size << "\n";
			displayStackTable();
		}
		#endif //DEBUGGER
	}

	/**
	 * This code ensures any live temp at target are copied to a spill
	 * location before an upcoming block beginning or block end.  The register
	 * is still allocated and available for use after the call.
	 */
	void CodegenMIR::spillTmps(OP* target)
	{
		if (target < ip)
		{
			// code already emitted for target, no point to spill
			return;
		}

		for (int i=0; i < MAX_REGISTERS; i++)
		{
			OP* ins;
			if ((ins = gpregs.active[i]) != 0 && ins->lastUse > target) {
				#ifdef AVMPLUS_VERBOSE
				if (verbose() && ins->isDirty())
					core->console << "SAVE temp @" << InsNbr(ins) << "\n";
				#endif
				spill(ins);
			}
		}
		for (int i=0; i < MAX_REGISTERS; i++)
		{
			OP* ins;
			if ((ins = fpregs.active[i]) != 0 && ins->lastUse > target) {
				#ifdef AVMPLUS_VERBOSE
				if (verbose() && ins->isDirty())
					core->console << "SAVE temp @" << InsNbr(ins) << "\n";
				#endif
				spill(ins);
			}
		}
	}

	void CodegenMIR::emitMD()
	{
		#ifdef AVMPLUS_VERBOSE
		if (verbose())
		{
			core->console << "generate " << info << "\n";
		}
		#endif

        PERFM_NTPROF("compile");

		/* 
		* Use access exceptions to manage our buffer growth.  We
		* reserve a large region of memory and write to it freely
		* without concern and when we hit a page that hasn't been 
		* commited we fault, our handler commits the page and we
		* continue on.
		* Rather slick, no?  Well, its just a slither of 
		* brilliance from mastermind garyg's noggin.
		*/
#ifdef FEATURE_BUFFER_GUARD
		GrowthGuard* growthGuard = 0;
		TRY(core, kCatchAction_Rethrow)
		{
		// put a guard against buffer growth
		GrowthGuard guard(pool->codeBuffer);
		growthGuard = &guard;
#endif /* FEATURE_BUFFER_GUARD */

		generatePrologue();
		generate();
		generateEpilogue();

		// get rid of pages for any part of the buffer that was not used.
		pool->codeBuffer->decommitUnused();

#ifdef DEBUGGER
		info->codeSize = int((mip - mipStart) * sizeof(MDInstruction));
#endif

		#ifdef VTUNE
       if (jitInfo->vtune && !overflow) {
           jitInfo->method = info;
           jitInfo->startAddr = (uintptr_t)mipStart;
           jitInfo->endAddr = (uintptr_t)mipEnd;
           VTune_RegisterMethod(core, jitInfo);
       }
       jitInfo->clear();
		#endif /* VTUNE */    

#ifdef FEATURE_BUFFER_GUARD // no buffer guard in Carbon builds
		}
		CATCH(Exception *exception)
		{
			if (growthGuard)
			{
				growthGuard->~GrowthGuard();
			}
			core->throwException(exception);
		}
		END_CATCH
		END_TRY
#endif // FEATURE_BUFFER_GUARD

        PERFM_TPROF_END();
		PERFM_NVPROF("mir bytes", size_t(ip)-size_t(ipStart));
		PERFM_NVPROF("mir", ip-ipStart);
		PERFM_NVPROF("code", size_t(mip)-size_t(casePtr));
	}

#ifdef FEATURE_BUFFER_GUARD
	bool CodegenMIR::ensureMDBufferCapacity(PoolObject* pool, size_t s) 
	{
		// with buffer guard enabled we ONLY need to check that we don't run
		// off the buffer.  We let the exception handler grow the buffer for us  
		byte* until = (byte*)mip + s;
		byte* end = pool->codeBuffer->end();
		if (until >= end)
		{
			overflow = true;
		}
		return !overflow; 
	} 
#else
	bool CodegenMIR::ensureMDBufferCapacity(PoolObject* pool, size_t s)
	{
		byte* until = (byte*)mip + s;
		byte* uncommitted = pool->codeBuffer->uncommitted();
		while (until >= uncommitted)
		{
			// committed last page and still want more!
			if (uncommitted == pool->codeBuffer->end())
			{
				// dead 
				overflow = true;
				break;
			}
			uncommitted = pool->codeBuffer->grow();
		}
		return !overflow;
	}
#endif /* FEATURE_BUFFER_GUARD */

	byte* CodegenMIR::getMDBuffer(PoolObject* pool)
	{
		if (pool->codeBuffer->size() == 0)
		{
			// compute amount of space we should reserve.
#ifdef AVMPLUS_64BIT
			int		expansionFactor = 50; // 64-bit needs a little more room for large bytecode (64-bit displacement constants, etc.)
#else
			int		expansionFactor = 40; //this constant was initially part of estimateMDBufferReservation()
#endif
			byte	*pMem = NULL;
			size_t	size = 0;
			
			do
			{
				size = estimateMDBufferReservation(pool, expansionFactor);
				pMem = pool->codeBuffer->reserve(size);
				if(pMem)
					break; // success!
				else
					expansionFactor /= 2; // gradually reduce expansionFactor if we can not reserve so much memory
			}
			while(expansionFactor >=5 ); // do not give up until expansionFactor is too small

		}
#ifdef AVMPLUS_JIT_READONLY
		else
		{
			// make the first page read/write but not executable.
			// do not clobber a guard page, if present.
			if (pool->codeBuffer->getPos() != pool->codeBuffer->uncommitted())
			{
				MMgc::GCHeap* heap = core->GetGC()->GetGCHeap();
				heap->SetPageProtection(pool->codeBuffer->getPos(), 1, true, true);
			}
		}
#endif /* AVMPLUS_JIT_READONLY */
		
		return pool->codeBuffer->getPos();
	}

	/**
	 * compute an estimate for MD reservation
	 */
	/*static*/ size_t CodegenMIR::estimateMDBufferReservation(PoolObject* pool, const int expansionFactor)
	{
		// compute the size of the buffer based on # methods and expansion.

		// Having a large expansion factor here doesn't negatively impact us 
		// as we will be reserving virtual address space based on this 
		// number but not commiting the pages until we need them.
		// So any unused virutal address space will be returned to the OS
		// for later use.
		//
		// What is important is that we place a large enough estimate
		// in here that we NEVER overflow the buffer.   Overflowing
		// means we redo the generation which is a massive performance hit.

		int size = 0;
		for(uint32 i=0, n=pool->methodCount; i < n; i++)
		{
			AbstractFunction* fnc = pool->getMethodInfo(i);
			if (fnc->hasMethodBody())
			{
				MethodInfo* mi = (MethodInfo*)fnc;
				const byte *pos = mi->body_pos;

				if (pos)
				{
					AvmCore::readU30(pos); // max_stack
					AvmCore::readU30(pos); // local_count
					AvmCore::readU30(pos); // init_scope_depth
					AvmCore::readU30(pos); // max_scope_depth

					int bytecodeSize = AvmCore::readU30(pos);

                    if(!pool->isCodePointer(pos))
					{
						// sanity check
						unsigned int imm30 = 0, imm30b = 0;
						int imm24 = 0, imm8 = 0;
						const byte *end = pos + bytecodeSize;
						while(pos < end) 
						{
							if (*pos == OP_abs_jump)
							{
								pos++; // skip the 0xEE OP_abs_jump opcode
								AvmCore::readU30(pos); // read the pc value (see abs_jump() in abcgen.h)
								#ifdef AVMPLUS_64BIT
								AvmCore::readU30(pos); // read the pc value (see abs_jump() in abcgen.h)
								#endif
								// real code size
								size += expansionFactor * AvmCore::readU30(pos);
								break;
							}
							AvmCore::readOperands(pos, imm30, imm24, imm30b, imm8);
						}
					}
					
					size += expansionFactor * bytecodeSize ;
					size += md_prologue_size + md_epilogue_size;
					//size += caseCount*sizeof(int);   @todo we don't have access to case counts!!!
				}
			}
			else
			{
				// reserve size for native thunk
				size += md_native_thunk_size;
			}
		}
		return size;
	}

#if defined(_MAC) && !TARGET_RT_MAC_MACHO
	static uint32 get_rtoc()
	{
		asm { mr r3, r2; }
	}
#endif
	
	void CodegenMIR::bindMethod(AbstractFunction* f)
	{
		#ifdef AVMPLUS_ARM
		flushDataCache(&code[0], (int)mip - (int)&code[0]);
		#endif
		
		// save code pointers on MethodInfo		
		ReadOnlyScriptBufferImpl* buff = new (core->GetGC()) ReadOnlyScriptBufferImpl(code, (uintptr)mip - (uintptr)&code[0]);
		ScriptBuffer sc(buff);

#if defined(_MAC) && !TARGET_RT_MAC_MACHO
		// Write the code pointer for the ABI's benefit
		mip = (MDInstruction*) ((size_t)mip+7 & ~7); // align on 8
		*mip++ = (uint32)mipStart;
		*mip++ = get_rtoc();
#endif

		
#if defined(_MAC) && !TARGET_RT_MAC_MACHO
		f->impl32 = *(AtomMethodProc*) &(mip - 2);
//		f->impl32 = (int (*)(MethodEnv*, int, uint32 *)) (mip-2);
#else
		typedef Atom (*AtomMethodProc)(MethodEnv*, int, uint32 *);
        union {
			MDInstruction *mipStartU;
			AtomMethodProc atomMethodProcU;
		};
		mipStartU = mipStart;
		f->impl32 = atomMethodProcU;
#endif
		// lock in the next available location in the buffer (16B aligned)
		PoolObject* pool = f->pool;
		byte* nextMethodStart = (byte*) BIT_ROUND_UP((size_t)mip, 16);
		pool->codeBuffer->setPos( nextMethodStart );

#ifdef AVMPLUS_JIT_READONLY
		makeCodeExecutable();
#endif /* AVMPLUS_JIT_READONLY */
	}

#ifdef AVMPLUS_JIT_READONLY
	void CodegenMIR::makeCodeExecutable()
	{
		#if defined(_MAC) && defined(AVMPLUS_PPC)
		// Tell the OS that this buffer contains executable code.
		// This is required since machines like the G4 have dual
		// cache designs.
		MakeDataExecutable(mipStart, (int)mip - (int)mipStart);
		#endif /* _MAC && AVMPLUS_PPC */

		#ifdef AVMPLUS_SPARC
		sync_instruction_memory((char *)mipStart, (int)mip - (int)mipStart);
		#endif /* AVMPLUS_PPC */
		
		// make the code executable
		MMgc::GCHeap* heap = core->GetGC()->GetGCHeap();
		heap->SetPageProtection(mipStart, (uintptr)mip - (uintptr)mipStart, true, false);
	}
#endif /* AVMPLUS_JIT_READONLY */

	//
	// The md versions of patching place the relative offset of the next into the patch location
	// as opposed to placing the address itself.  This is done mainly to conserve bits since we
	// can only use the lower 26 bits of the PPC instruction for patch information.
	// (Same applies to ARM, but on ARM 28 bits are available.)
	//
#ifdef AVMPLUS_PPC
	#define MD_PATCH_LOCATION_SET(w,o) AvmAssertMsg(BIT_VALUE_FITS(o,26), "Branch offset exceeds 26 bits; illegal for PPC"); *w = BIT_INSERT(*w,25,0,o)
	#define MD_PATCH_LOCATION_GET(w) BIT_EXTRACT(*w,25,0)
#elif defined AVMPLUS_SPARC
	#define MD_PATCH_LOCATION_SET(w,o) *w &= 0xFFC00000; *w |= o&0x3FFFFF;
	#define MD_PATCH_LOCATION_GET(w) *w & 0x3FFFFF;
#elif defined AVMPLUS_ARM
	#define MD_PATCH_LOCATION_SET(w,o) AvmAssertMsg(BIT_VALUE_FITS(o,28), "Branch offset exceeds 28 bits; illegal for PPC"); *w = BIT_INSERT(*w,27,0,o)
	#define MD_PATCH_LOCATION_GET(w) BIT_EXTRACT(*w,27,0)	
#else
	#define MD_PATCH_LOCATION_SET(w,o) *w = o;
	#define MD_PATCH_LOCATION_GET(w) *w;
#endif


	void CodegenMIR::generate()
	{
		SAMPLE_FRAME("[generate]", core);

		// stuff used to track which page in the buffer we are on.
		const static int maxBytesPerMIRIns = 16*8;  // maximum # of bytes needed by the buffer per MIR instruction (16 machine instructions x 8B)

		if (overflow)
			return;

		uintptr threshold = (uintptr)pool->codeBuffer->uncommitted() - maxBytesPerMIRIns;

		#ifdef _DEBUG
		// used to track the maximum number of bytes generated per MIR instruction
		MDInstruction* lastMip = mip;
		#endif /*_DEBUG */

		#ifdef VTUNE
		Stringp currentFile = 0;
		uint32  currentLine = 0; 
		#endif /* VTUNE */
        
		// linked list of instructions that need to be spilled prior to a branch.
		AvmAssert(ip == ipStart);
		while(ip < ipEnd)
		{
			SAMPLE_CHECK();
			MirOpcode mircode = ip->code;

			#ifdef AVMPLUS_VERBOSE
			if (verbose() && mircode != MIR_bb)
			{
				core->console << "\n@" << InsNbr(ip) << " ";
				formatOpcode(core->console, ip, pool, core->codegenMethodNames);
				core->console << "\n";
			}
			#endif // AVMPLUS_VERBOSE

			#ifdef _DEBUG
			// if this assert fires increase 'maxBytesPerMIRIns' to at least (mip - lastMip)
			//	AvmAssert(false);
			lastMip = mip;
			#endif /* _DEBUG */

			// now check to see if we are about to go over a page boundary 
			if ( (uintptr)mip > threshold)
			{
#ifndef FEATURE_BUFFER_GUARD
				// if no buffer guards then we need to manually grow
				pool->codeBuffer->grow();
#endif /* FEATURE_BUFFER_GUARD */
				ensureMDBufferCapacity(pool, maxBytesPerMIRIns);
				threshold = (uintptr)pool->codeBuffer->uncommitted() - maxBytesPerMIRIns;

				// check for buffer overrun
				if (overflow)
				{
					// so we've pretty much hit the end of our reseved 
					// virtual memory region.  This means that our estimate
					// for code space is off and we need to retune.
					// PLEASE DO SO NOW!!!  THIS SHOULD NOT HAPPEN.
					return;
				}
			}

			switch(mircode)
			{
				case MIR_bb:
				{
					// spill tmps, if any
					spillTmps(ip);

					// now retire any active registers since MIR-bb is
					// typically where control flows merge

					for(int i=0; i<MAX_REGISTERS; i++)
					{
						OP* live = gpregs.active[i];
						if (live)
							gpregs.retire(live);
					}
					for(int i=0; i<MAX_REGISTERS; i++)
					{
						OP* live = fpregs.active[i];
						if (live)
							fpregs.retire(live);
					}

					#ifdef AVMPLUS_VERBOSE
					// put this here so that jump target prints out correctly.
					if (verbose())
					{
						core->console << "\n@" << InsNbr(ip) << " ";
						formatOpcode(core->console, ip, pool, core->codegenMethodNames);
						core->console << "\n";
					}
					#endif // AVMPLUS_VERBOSE

					mdLabel(ip, mip);
					break;
				}
				case MIR_alloc:
				{
					// note the alloc, actual act is delayed; see above
					reserveStackSpace(ip, true);
					break;
				}
				#ifdef VTUNE
				case MIR_file:
				{
					// current file gets set.
					currentFile = (Stringp)ip->imm;
					break;
				}
				case MIR_line:
				{
					// note the alloc, actual act is delayed; see above					
					currentLine = (uint32)ip->imm;

					// add the current line/file info to our table tracking such stuff
                   jitInfo->add(core->GetGC(),(uintptr_t)mip,currentFile,currentLine);
					break;
				}
				#endif /* VTUNE */
				case MIR_def:
				case MIR_fdef:
				{
					OP* join = ip->join;
					AvmAssert(join == 0 || join < ip);
					AvmAssert(join == 0 || ip->lastUse == 0);

					OP* value = ip->oprnd1;
					RegInfo& regs = mircode==MIR_fdef ? fpregs : gpregs;

					// walk back to earliest def
					while (join && join->join)
						join = join->join;

					// now, join is the original definition of
					// the variable, and we want to overwrite it with
					// the new variable's value.

					if (join)
					{
						// ip is not the first def, so use join
						if (join->lastUse >= ip)
						{
							// save expr in joined def's storage, not ours.
							Register r = Unknown;
							InsRegisterPrepA(ip, regs, value, r);
							if (join->reg != Unknown) {
								moveR2R(ip, r, join->reg);
							}
							if (join->pos != InvalidPos) {
								copyToStack(join, r);
							}
						}
						else
						{
							regs.expire(value,ip);
						}
					}
					else
					{
						// this is the first def.  just make a copy of the expr.
						if (ip->lastUse > ip)
						{
							Register r = Unknown;
							InsRegisterPrepA(ip, regs, value, r);
							if (value->lastUse == ip) {
								registerAllocSpecific(regs, r);
							} else {
								Register r2 = registerAllocAny(regs, ip);
								if (r2 != r)
									moveR2R(ip, r, r2);
								r = r2;
							}
							setResultReg(regs, ip, r);
							spill(ip);
						}
						else
						{
							regs.expire(value, ip);
						}
					}
					break;
				}

				case MIR_use:
				case MIR_fuse:
				{
					OP* def = ip->oprnd1;

					RegInfo& regs = mircode==MIR_fuse ? fpregs : gpregs;

					if (ip->lastUse)
					{
						OP* d = def;
						while (d->join)
							d = d->join;

						Register r = Unknown;
						InsRegisterPrepA(ip, regs, d, r);
						registerAllocSpecific(regs, r);
						setResultReg(regs, ip, r);
					}

					regs.expire(def, ip);
					while ( (def = def->join ) != 0 )
						regs.expire(def, ip);

					break;
				}

				case MIR_arg:
				{
					if (!ip->lastUse)
					{
						ip->reg = Unknown; // if arg was preassigned a reg, cancel that.
						break;
					}

					if (ip->reg != Unknown)
					{
						// allocate the register we preassigned
						registerAllocSpecific(gpregs, ip->reg);
						// toast pos so that spill will push it to the stack in some fixed location
						setResultReg(gpregs, ip, ip->reg);
					}

					break;
				}
				case MIR_imm:
				{
					ip->reg = Unknown;
					ip->pos = InvalidPos;
					// if anyone uses imm in reg, it will prep it on demand
					break;
				}
				case MIR_lea:
				{
					if (!ip->lastUse)
					{
						break;
					}

					OP* base = ip->base;
					sintptr disp = ip->disp;

					if (base->code == MIR_alloc)
					{
						Register r = InsPrepResult(gpregs, ip);

						// pos field of alloca contains stack pos
						disp += stackPos(base);
						#ifdef AVMPLUS_SPARC
						ADDI32(framep, disp, r);
						#endif

						#ifdef AVMPLUS_PPC
						ADDI32(r, framep, disp);
						#endif

						#ifdef AVMPLUS_ARM
						if (!(disp&0xFFFF0000))
						{
							ADD_imm16(r, SP, disp);
						}
						else
						{
							MOV_imm32(IP, disp);
							ADD(r, IP, SP);
						}
						#endif
						
						#if defined (AVMPLUS_IA32) || defined(AVMPLUS_AMD64)
						LEA(r, disp, framep);
						#endif
					}
					else
					{
						// adding an offset to a real pointer.
						Register rBase = Unknown;
						InsRegisterPrepA(ip, gpregs, base, rBase);
						AvmAssert(rBase != Unknown);
						Register r = InsPrepResult(gpregs, ip, rmask(rBase));

						#ifdef AVMPLUS_SPARC
						ADDI32(rBase, disp, r);
						#endif

						#ifdef AVMPLUS_PPC
						ADDI32(r, rBase, disp);
						#endif

						#ifdef AVMPLUS_ARM
						if (!(disp&0xFFFF0000))
						{
							ADD_imm16(r, rBase, disp);
						}
						else
						{
							MOV_imm32(IP, disp);
							ADD(r, IP, rBase);
						}
						#endif
					
						#if defined (AVMPLUS_IA32) || defined(AVMPLUS_AMD64)
						LEA(r, disp, rBase);
						#endif
					}
					break;
				}


#if HAVE_MIR_SMOPS
				case MIR_maddr:
				{
					OP* lhs = ip->oprnd1; // lhs

#if (defined(_DEBUG))
					totalRangeChecks++;
#endif
					if (!ip->lastUse)
					{
						gpregs.expire(lhs, ip);
						break;
					}

					#if defined(AVMPLUS_IA32) || defined(AVMPLUS_AMD64)
					Register r = Unknown;
					InsRegisterPrepA(ip, gpregs, lhs, r);
					registerAllocSpecific(gpregs, r);

					int32 mn = ip->imm >> 16;
					int32 mx = (ip->imm << 16) >> 16;
					int32 idisp = maddrImplicitDisp(ip);

					if(idisp)
					{
#if (defined(_DEBUG))
						implicitMaddrDisps++;
#endif
						mn += idisp;
						mx += idisp;
						if(idisp < 0)
							SUB(r, idisp);
						else
							ADD(r, -idisp);
						AvmAssert(!mn);
					}
					if(!mn && mx <= Domain::GLOBAL_MEMORY_MIN_SIZE) // range is zero through something
					{
#if (defined(_DEBUG))
						singleCmpRangeChecks++;
#endif
						CMP(r, 0x80000000); // ensure 32 bit
						uint32 *p32 = (uint32 *)(mip - 4);
						*p32 = pool->domain->globalMemorySize - mx;
						pool->domain->addGlobalMemorySizeRef(p32);
						#if DBG_MADDR && defined(_DEBUG) && defined(AVMPLUS_IA32)
						CALL(0);
						#endif
						JNBE(0x80000000); // ensure 32 bit
						// link range check jumps
						p32 = (uint32 *)(mip - 4);
						*p32 = (uint32)lastMOPRangeCheckJmp;
						lastMOPRangeCheckJmp = p32;
						#if DBG_MADDR && defined(_DEBUG) && defined(AVMPLUS_IA32)
						ADD(ESP, 4);
						#endif
					}
					else
					{
						AvmAssert(!idisp);
#if (defined(_DEBUG))
						doubleCmpRangeChecks++;
#endif
						CMP(r, -mn);
						#if DBG_MADDR && defined(_DEBUG) && defined(AVMPLUS_IA32)
						CALL(0);
						#endif
						JL(0x80000000); // ensure 32 bit
						// link range check jumps
						uint32 *p32 = (uint32 *)(mip - 4);
						*p32 = (uint32)lastMOPRangeCheckJmp;
						lastMOPRangeCheckJmp = p32;
						#if DBG_MADDR && defined(_DEBUG) && defined(AVMPLUS_IA32)
						ADD(ESP, 4);
						#endif

						CMP(r, 0x80000000); // ensure 32 bit
						p32 = (uint32 *)(mip - 4);
						*p32 = pool->domain->globalMemorySize - mx;
						pool->domain->addGlobalMemorySizeRef(p32);
 						#if DBG_MADDR && defined(_DEBUG) && defined(AVMPLUS_IA32)
						CALL(0);
						#endif
						JNLE(0x80000000); // ensure 32 bit
						// link range check jumps
						p32 = (uint32 *)(mip - 4);
						*p32 = (uint32)lastMOPRangeCheckJmp;
						lastMOPRangeCheckJmp = p32;
						#if DBG_MADDR && defined(_DEBUG) && defined(AVMPLUS_IA32)
						ADD(ESP, 4);
						#endif
					}

					#endif

					#if defined(AVMPLUS_PPC) || defined(AVMPLUS_ARM)
					#error Not implemented
					#endif
					
					setResultReg(gpregs, ip, r);
					break;
				}
				case MIR_sx8:
				case MIR_sx16:
				{
					OP* lhs = ip->oprnd1; // lhs

					if (!ip->lastUse)
					{
						gpregs.expire(lhs, ip);
						break;
					}

					#if defined(AVMPLUS_IA32) || defined(AVMPLUS_AMD64)

					Register r = ip->code == MIR_sx8 ? registerFor8Bit(gpregs, lhs) : Unknown;
					InsRegisterPrepA(ip, gpregs, lhs, r);
					registerAllocSpecific(gpregs, r);

					if(ip->code == MIR_sx8)
						MOVSX_r8(r, r);
					if(ip->code == MIR_sx16)
						MOVSX_r16(r, r);

					#endif

					#if defined(AVMPLUS_PPC) || defined(AVMPLUS_ARM)
					#error Not implemented
					#endif
					
					setResultReg(gpregs, ip, r);
					break;
				}
				case MIR_sld:
				case MIR_sldop:
				case MIR_fsld:
				case MIR_fsldop:
				{
					OP* addr = ip->oprnd1;

					// no immediate or stack relative variants
					AvmAssert(addr && addr->code != MIR_alloc);

					// don't generate it if its not used
					if (!ip->lastUse)
					{
						gpregs.expire(addr, ip);
						break;
					}
					// 2 bits of size / sign extend info
					int disp = ip->disp & ~SMOP_MASK;
					// real displacement if disp is modified to ensure 3 bit disp
					int realDisp = disp;
					int size = ip->disp & SMOP_MASK;

					if(addr->code == MIR_maddr)
					{
#ifdef AVMPLUS_AMD64
						if (!is32bit(disp))
							AvmAssert(0);
#endif
						realDisp += (intptr_t)pool->domain->globalMemoryBase;
						realDisp += maddrImplicitDisp(addr);
						disp = 0x80000000; // ensure 32 bit
					}
					RegInfo& regs = ip->isDouble() ? fpregs : gpregs;
					Register r;
					Register rSrc = Unknown;

					InsRegisterPrepA(ip, gpregs, addr, rSrc);
					r = InsPrepResult(regs, ip, rmask(rSrc));

					#ifdef AVMPLUS_IA32
					if (ip->isDouble()) 
					{
						// only 32 bit float w/o sign-extend here
						AvmAssert(size == SMOP_F32);
						if (core->config.sse2)
						{
							MOVSS(r, disp, rSrc);
						}
						else
						{
							AvmAssert(r == FST0);
							FFREE(FST7);
							FLDD(disp, rSrc);
						}
					}
					else
					{
						switch(size)
						{
						default:
							AvmAssert(false);
							// fall through
						case SMOP_I8: // 8 bit zero-ext
							MOVZX_8(r, disp, rSrc);
							break;
						case SMOP_I8SX: // 8 bit sign-ext
							MOVSX_8(r, disp, rSrc);
							break;
						case SMOP_I16: // 16 bit zero-ext
							MOVZX_16(r, disp, rSrc);
							break;
						case SMOP_I16SX: // 16 bit sign-ext
							MOVSX_16(r, disp, rSrc);
							break;
						}
					}
					unsigned char **pdisp = (unsigned char **)(mip - 4);
					if(disp != realDisp)
					{
						AvmAssert((int)*pdisp == disp);
						AvmAssert(addr->code == MIR_maddr);
						*pdisp = (unsigned char *)realDisp;
					}
					if(addr->code == MIR_maddr)
						pool->domain->addGlobalMemoryBaseRef(pdisp);
					if(ip->isDouble() && core->config.sse2)
						CVTPS2PD(r, r);
					#endif
					#if defined(AVMPLUS_PPC) || defined(AVMPLUS_ARM)
					#error Not implemented
					#endif
					break;
				}
				case MIR_sst:
				{
					OP* addr = ip->base;
					OP* value = ip->value;

					// no immediate or stack relative variants
					AvmAssert(addr && addr->code != MIR_alloc);

					// 2 bits of size / sign extend info
					int disp = ip->disp & ~SMOP_MASK;
					// real displacement if disp is modified to ensure 3 bit disp
					int realDisp = disp;
					int size = ip->disp & SMOP_MASK;

					if(addr->code == MIR_maddr)
					{
#ifdef AVMPLUS_AMD64
						if (!is32bit(disp))
							AvmAssert(0);
#endif
						realDisp += (intptr_t)pool->domain->globalMemoryBase;
						realDisp += maddrImplicitDisp(addr);
						disp = 0x80000000; // ensure 32 bit
					}
					RegInfo& regs = value->isDouble() ? fpregs : gpregs;
					Register r = Unknown;
					Register rDst = Unknown;

					AvmAssert(!(size & SMOP_SX));
					#ifdef AVMPLUS_IA32
					if(!value->isDouble() && size == SMOP_I8)
						r = registerFor8Bit(gpregs, value);

					InsRegisterPrepAB(ip, regs, value, r, gpregs, addr, rDst);

					if (value->isDouble()) 
					{
						// only 32 bit float w/o sign-extend here
						AvmAssert(size == SMOP_F32);
						if (core->config.sse2)
						{
							Register rTrunc = registerAllocAny(regs, ip);
							CVTPD2PS(rTrunc, r);
							MOVSS(disp, rDst, rTrunc);
							regs.addFree(rTrunc);
						}
						else
						{
							AvmAssert(r == FST0);
							FFREE(FST7);
							FSTD(disp, rDst);
						}
					}
					else
					{
						switch(size)
						{
						default:
							AvmAssert(false);
							// fall through
						case SMOP_I8: // 8 bit trunc
							MOV_8(disp, rDst, r);
							break;
						case SMOP_I16: // 16 bit trunc
							MOV_16(disp, rDst, r);
							break;
						}
					}
					unsigned char **pdisp = (unsigned char **)(mip - 4);
					if(disp != realDisp)
					{
						AvmAssert((int)*pdisp == disp);
						AvmAssert(addr->code == MIR_maddr);
						*pdisp = (unsigned char *)realDisp;
					}
					if(addr->code == MIR_maddr)
						pool->domain->addGlobalMemoryBaseRef(pdisp);
					#endif
					#if defined(AVMPLUS_PPC) || defined(AVMPLUS_ARM)
					#error Not implemented
					#endif
					break;
				}
#endif /* HAVE_MIR_SMOPS */
				case MIR_ld:
#ifdef AVMPLUS_64BIT
				case MIR_ld32:
				case MIR_ld32u:
#endif
				case MIR_ldop:
				case MIR_fld:
				case MIR_fldop:
				{
					OP* addr = ip->oprnd1;

					// don't generate it if its not used
					if (!ip->lastUse)
					{
						if (addr)
							gpregs.expire(addr, ip);
						break;
					}

					// address + offset
					sintptr disp = ip->disp;
					// real displacement if disp is modified to ensure 3 bit disp
					sintptr realDisp = disp;

					RegInfo& regs = ip->isDouble() ? fpregs : gpregs;

					// load up our requirements and send off to 
					// the smart-ass allocator.  If its a stack
					// based access then we can ignore the addr operand.
					Register r;
					Register rSrc = Unknown;

					if (!addr)
					{
						// disp = absolute immediate address
						r = InsPrepResult(regs, ip);
						// rSrc = Unknown
					}
					else if (addr->code == MIR_alloc)
					{
						r = InsPrepResult(regs, ip);

						// stack based access get position from alloca instruction, which obtains
						// its offset from being in the stackEntry list.  The instruction may also 
						// contain an optional offset which we need to add.

						disp += stackPos(addr);
                        realDisp = disp;

						rSrc = framep;
					}
					else
					{
						// memory op? tack on offset to backing store
#if HAVE_MIR_SMOPS
						if(addr->code == MIR_maddr)
						{
#ifdef AVMPLUS_AMD64
							if (!is32bit(disp))
								AvmAssert(0);
#endif
							realDisp += (intptr_t)pool->domain->globalMemoryBase;
							realDisp += maddrImplicitDisp(addr);
							disp = 0x80000000; // ensure 32 bit
						}
#endif
						InsRegisterPrepA(ip, gpregs, addr, rSrc);
						r = InsPrepResult(regs, ip, rmask(rSrc));
					}

					#ifdef AVMPLUS_SPARC
					if (ip->isDouble()) {
						LDDF32(rSrc, disp, r);
					} else {
						LDSW32(rSrc, disp, r);
					}
					#endif

					#ifdef AVMPLUS_PPC
					if (ip->isDouble()) {
						LFD32(r, disp, rSrc);
					} else {
						LWZ32(r, disp, rSrc);
					}
					#endif

					#ifdef AVMPLUS_ARM
					if (rSrc == Unknown)
					{
						rSrc = IP;
						MOV_imm32(IP, disp);
						disp = 0;
					}
						
					if (ip->isDouble())
					{
						// There is one FP pseudo-register on ARM
						LDR(R4, disp,   rSrc);
						LDR(R5, disp+4, rSrc);
					}
					else
					{
						LDR(r, disp, rSrc);
					}
					#endif
					
					#if defined(AVMPLUS_IA32) || defined(AVMPLUS_AMD64)
					if (ip->isDouble()) 
					{
#ifdef AVMPLUS_AMD64
						if ( !is32bit(disp) ) {
							MOV(R11,disp);
							if (rSrc != Unknown) ADD64(R11,rSrc);
							if (core->config.sse2) {
								MOVSD(r, 0, R11);
							} else {
								AvmAssert(r == FST0);
								FFREE(FST7);
								FSTQ(0, R11);
							}
						} else
#endif //#ifdef AVMPLUS_AMD64
						if (core->config.sse2)
						{
							MOVSD(r, disp, rSrc);
						}
						else
						{
							AvmAssert(r == FST0);
							FFREE(FST7);
							FLDQ(disp, rSrc);
						}
					}
					else
					{
#ifdef AVMPLUS_64BIT
						if ( !is32bit(disp) ) {
							MOV(R11,disp);
							if (rSrc != Unknown) ADD64(R11,rSrc);
							if (mircode==MIR_ld32u) {
								MOV32(r, 0, R11);
							} else if (mircode==MIR_ld32) {
								MOVSXD(r, 0, R11);
							} else {
								MOV(r, 0, R11);
							}
						} else if (mircode==MIR_ld32u)
							MOV32(r, disp, rSrc);
						else if (mircode==MIR_ld32)
							MOVSXD(r, disp, rSrc);
						else
							MOV(r, disp, rSrc);
#else
						MOV(r, disp, rSrc);
#endif
					}
					#endif

					unsigned char **pdisp = (unsigned char **)(mip - 4);
					if(disp != realDisp)
					{
						AvmAssert((sintptr)*pdisp == disp);
#if HAVE_MIR_SMOPS
						AvmAssert(addr->code == MIR_maddr);
#endif
						*pdisp = (unsigned char *)realDisp;
					}
					// memory op?  remember it for updates
#if HAVE_MIR_SMOPS
					if(addr && addr->code == MIR_maddr)
						pool->domain->addGlobalMemoryBaseRef(pdisp);
#endif
					break;
				}

				// get address of def
				case MIR_usea:
				{
					// address + offset
					OP* def = ip->oprnd1;

					AvmAssert((def->code & ~MIR_float) == MIR_def);
					while (def->join)
						def = def->join;

					// make sure def is on stack
					if (def->reg != Unknown) {
						#ifdef AVMPLUS_VERBOSE
						if (verbose() && def->isDirty())
							core->console << "SAVE def @" << InsNbr(def) << "\n";
						#endif
						spill(def);
					}
					RegInfo &defregs = def->isDouble() ? fpregs : gpregs;
					defregs.expire(def, ip);

					Register r = InsPrepResult(gpregs, ip);

					#ifdef AVMPLUS_SPARC
					ADDI32(framep, stackPos(def), r);
					#endif

					#ifdef AVMPLUS_PPC
					ADDI32(r, framep, stackPos(def));
					#endif

					#ifdef AVMPLUS_ARM
					int disp = stackPos(def);
					if (!(disp&0xFFFF0000))
					{
						ADD_imm16(r, framep, disp);
					}
					else
					{
						MOV_imm32(IP, disp);
						ADD(r, IP, framep);
					}
					#endif
					
					#if defined (AVMPLUS_IA32) || defined(AVMPLUS_AMD64)
					LEA (r, stackPos(def), framep);
					#endif
					break;
				}

				case MIR_st:
				case MIR_st32:
				{
					// address + offset
					OP* value = ip->value; // value
					OP* addr = ip->base;
					sintptr disp = ip->disp;
					// real displacement if disp is modified to ensure 3 bit disp
					sintptr realDisp = disp;
					// add to mip to point to byte IMMEDIATELY FOLLOWING disp
					int mipAdjust = 0;

					// load up our requirements and send off to 
					// the smart-ass allocator.  If its a stack
					// based access we can ignore the addr operand.
					Register rValue = Unknown;
					Register rDst = Unknown;

					RegInfo& regsValue = value->isDouble() ? fpregs : gpregs;

					#ifdef AVMPLUS_SPARC

					if (!addr)
					{
						// disp = absolute immediate address
						InsRegisterPrepA(ip, regsValue, value, rValue);
					}
					else if (addr->code == MIR_alloc)
					{
						InsRegisterPrepA(ip, regsValue, value, rValue);
						rDst = SP;
						disp += stackPos(addr);
					}
					else
					{
						InsRegisterPrepAB(ip, regsValue, value, rValue, gpregs, addr, rDst);
					}
					
					if (value->isDouble())
					{
						STDF32(rValue, disp, rDst);
					}
					else
					{
						STW32(rValue, disp, rDst);
					}
					
					#endif // AVMPLUS_SPARC
					#ifdef AVMPLUS_PPC

					if (!addr)
					{
						// disp = absolute immediate address
						InsRegisterPrepA(ip, regsValue, value, rValue);
						// rDst = Unknown
					}
					else if (addr->code == MIR_alloc)
					{
						InsRegisterPrepA(ip, regsValue, value, rValue);
						rDst = SP;
						disp += stackPos(addr);
                        realDisp = disp;
					}
					else
					{
						// memory op? tack on offset to backing store
#if HAVE_MIR_SMOPS
						if(addr->code == MIR_maddr)
						{
#ifdef AVMPLUS_AMD64
							if (!is32bit(disp))
								AvmAssert(0);
#endif
							realDisp += (intptr_t)pool->domain->globalMemoryBase;
							realDisp += maddrImplicitDisp(addr);
							disp = 0x80000000; // ensure 32 bit
						}
#endif
						InsRegisterPrepAB(ip, regsValue, value, rValue, gpregs, addr, rDst);
					}
					
					if (value->isDouble())
					{
						STFD32(rValue, disp, rDst);
					}
					else
					{
						STW32(rValue, disp, rDst);
					}
					
					#endif

					#ifdef AVMPLUS_ARM
					if (!addr)
					{
						// disp = absolute immediate address
						InsRegisterPrepA(ip, regsValue, value, rValue);

						rDst = IP;
						MOV_imm32(IP, disp);
						disp = realDisp = 0;
					}
					else if (addr->code == MIR_alloc)
					{
						InsRegisterPrepA(ip, regsValue, value, rValue);
						rDst = SP;
						disp += stackPos(addr);
                        realDisp = disp;
					}
					else
					{
						// memory op? tack on offset to backing store
#if HAVE_MIR_SMOPS
						if(addr->code == MIR_maddr)
						{
#ifdef AVMPLUS_AMD64
							if (!is32bit(disp))
								AvmAssert(0);
#endif
							realDisp += (intptr_t)pool->domain->globalMemoryBase;
							realDisp += maddrImplicitDisp(addr);
							disp = 0x80000000; // ensure 32 bit
						}
#endif
						InsRegisterPrepAB(ip, regsValue, value, rValue, gpregs, addr, rDst);
					}
					
					if (value->isDouble())
					{
						AvmAssert(rValue == F0);
						STR(R4, disp,   rDst);
						STR(R5, disp+4, rDst);
					}
					else
					{
						STR(rValue, disp, rDst);
					}
					#endif
					
					#if defined (AVMPLUS_IA32) || defined(AVMPLUS_AMD64)
					
					if (!addr) 
					{
						// disp = absolute immediate address
						InsRegisterPrepA(ip, regsValue, value, rValue);
						// rDst = Unknown
					}
					else if (addr->code == MIR_alloc)
					{
						if (!canImmFold(ip, value)) //value->code != MIR_imm)
							InsRegisterPrepA(ip, regsValue, value, rValue);

						rDst = framep;
						disp += stackPos(addr);
						realDisp = disp;
					}
					else
					{
						// memory op? tack on offset to backing store
#if HAVE_MIR_SMOPS
						if(addr->code == MIR_maddr)
						{
#ifdef AVMPLUS_AMD64
							if (!is32bit(disp))
								AvmAssert(0);
#endif
							realDisp += (intptr_t)pool->domain->globalMemoryBase;
							realDisp += maddrImplicitDisp(addr);
							disp = 0x80000000; // ensure 32 bit
						}
#endif
						if (!canImmFold(ip,value)) //value->code != MIR_imm)
							InsRegisterPrepAB(ip, regsValue, value, rValue, gpregs, addr, rDst);
						else
							InsRegisterPrepA(ip, gpregs, addr, rDst);
					}

					if (value->isDouble())
					{
#ifdef AVMPLUS_AMD64
						if ( !is32bit(disp) ) {
							MOV(R11,disp);
							if ( rDst != Unknown ) ADD64(R11,rDst);
							if (core->config.sse2) {
								MOVSD(0, R11, rValue);
							} else {
								AvmAssert(rValue == FST0);
								FSTQ(0, R11);
							}
						} else
#endif //#ifdef AVMPLUS_AMD64
						if (core->config.sse2) {
							MOVSD(disp, rDst, rValue);
						} else {
							AvmAssert(rValue == FST0);
							FSTQ(disp, rDst);
						}
					}
					else
					{
						if (canImmFold(ip, value)) //value->code == MIR_imm)
						{
#ifdef AVMPLUS_AMD64
							AvmAssert(is32bit(disp));
#endif //#ifdef AVMPLUS_AMD64
							// can fold immediate value
							if (value->reg != Unknown) {
								#ifdef AVMPLUS_AMD64
								if (mircode==MIR_st32)
									MOV32(disp, rDst, value->reg);	// imm value in reg
								else
								#endif
								MOV(disp, rDst, value->reg);	// imm value in reg
							} else {
								#ifdef AVMPLUS_AMD64
								if (mircode==MIR_st32)
									MOV32(disp, rDst, value->imm);	// imm value
								else
								#endif
								MOV(disp, rDst, value->imm);	// imm value
								// this instruction will NOT have the displacement as the last
								// word...  it will have the immediate value so account for that
								mipAdjust -= 4;
							}
						}
						else
						{
							// computed value in reg
#ifdef AVMPLUS_AMD64
							if (mircode==MIR_st32) {
								if ( !is32bit(disp) ) {
									MOV(R11,disp);
									if ( rDst != Unknown ) ADD64(R11,rDst);
									MOV32(0,R11,(Register)rValue);
								} else {
									MOV32(disp, rDst, rValue);
								}
							} else if ( !is32bit(disp) ) {
								MOV(R11,disp);
								if ( rDst != Unknown ) ADD64(R11,rDst);
								MOV(0,R11,(Register)rValue);
							} else
#endif
							MOV(disp, rDst, (Register)rValue);
						}
					}

					#endif // AVMPLUS_IA32

					unsigned char **pdisp = (unsigned char **)(mip - 4 + mipAdjust);

					if(disp != realDisp)
					{
						AvmAssert((sintptr)*pdisp == disp);
#if HAVE_MIR_SMOPS
						AvmAssert(addr->code == MIR_maddr);
#endif
						*pdisp = (unsigned char *)realDisp;
					}
					// memory op?  remember it for updates
#if HAVE_MIR_SMOPS
					if(addr && addr->code == MIR_maddr)
						pool->domain->addGlobalMemoryBaseRef(pdisp);
#endif
					break;
				}
				case MIR_lsh:
				case MIR_rsh:
				case MIR_ush:
				{
					OP* lhs = ip->oprnd1; // lhs			
					OP* rhs = ip->oprnd2; // rhs

					if (!ip->lastUse)
					{
						gpregs.expire(lhs, ip);
						gpregs.expire(rhs, ip);
						break;
					}

					// rhs could be imm or reg

					#ifdef AVMPLUS_SPARC

					if (canImmFold(ip, rhs))
					{
						Register rLhs = Unknown;
						InsRegisterPrepA(ip, gpregs, lhs, rLhs);
						AvmAssert(rLhs != Unknown);
						Register r = InsPrepResult(gpregs, ip);

						int shift = rhs->imm&0x1F;
						if (shift)
						{
							if (mircode == MIR_lsh)
								SLLI(rLhs, rhs->imm&0x1F, r);
							else if (mircode == MIR_rsh)
								SRAI(rLhs, rhs->imm&0x1F, r);
							else // MIR_ush
								SRLI(rLhs, rhs->imm&0x1F, r);
						}
						else
						{
							ORI(rLhs, 0, r);
						}
					}
					else
					{
						Register rLhs = Unknown;
						Register rRhs = Unknown;
						InsRegisterPrepAB(ip, gpregs, lhs, rLhs, gpregs, rhs, rRhs);
						Register r = registerAllocAny(gpregs, ip);
						setResultReg(gpregs, ip, r);

						ANDI(rRhs, 0x1F, rRhs);
						if (mircode==MIR_lsh)
							SLL(rLhs, rRhs, r);
						else if (mircode==MIR_rsh)
							SRA(rLhs, rRhs, r);
						else // MIR_ush
							SRL(rLhs, rRhs, r);
					}
					
					#endif // AVMPLUS_SPARC
					#ifdef AVMPLUS_PPC

					if (canImmFold(ip, rhs))
					{
						Register rLhs = Unknown;
						InsRegisterPrepA(ip, gpregs, lhs, rLhs);
						AvmAssert(rLhs != Unknown);
						Register r = InsPrepResult(gpregs, ip);

						int shift = rhs->imm&0x1F;
						if (shift)
						{
							if (mircode == MIR_lsh)
								SLWI(r, rLhs, rhs->imm&0x1F);
							else if (mircode == MIR_rsh)
								SRAWI(r, rLhs, rhs->imm&0x1F);
							else // MIR_ush
								SRWI(r, rLhs, rhs->imm&0x1F);
						}
						else
						{
							MR(r, rLhs);
						}
					}
					else
					{
						Register rLhs = Unknown;
						Register rRhs = Unknown;
						InsRegisterPrepAB(ip, gpregs, lhs, rLhs, gpregs, rhs, rRhs);
						Register r = registerAllocAny(gpregs, ip);
						setResultReg(gpregs, ip, r);

						ANDI_dot(rRhs, rRhs, 0x1F);
						if (mircode==MIR_lsh)
							SLW(r, rLhs, rRhs);
						else if (mircode==MIR_rsh)
							SRAW(r, rLhs, rRhs);
						else // MIR_ush
							SRW(r, rLhs, rRhs);
					}
					
					#endif

					#ifdef AVMPLUS_ARM
					Register r = Unknown;
					if (canImmFold(ip, rhs))
					{
						Register rLhs = Unknown;
						InsRegisterPrepA(ip, gpregs, lhs, rLhs);
						AvmAssert(rLhs != Unknown);
						r = registerAllocAny(gpregs, ip);
						setResultReg(gpregs, ip, r);

						if (mircode==MIR_lsh)
							LSL_i(r, rLhs, rhs->imm&0x1F);
						else if (mircode==MIR_rsh)
							LSR_i(r, rLhs, rhs->imm&0x1F);
						else // MIR_ush
							ASR_i(r, rLhs, rhs->imm&0x1F);
					}
					else
					{
						Register rLhs = Unknown;
						Register rRhs = Unknown;
						InsRegisterPrepAB(ip, gpregs, lhs, rLhs, gpregs, rhs, rRhs);
						r = registerAllocAny(gpregs, ip);
						setResultReg(gpregs, ip, r);

						AND_imm8(rRhs, rRhs, 0x1F);
						if (mircode==MIR_lsh)
							LSL(r, rLhs, rRhs);
						else if (mircode==MIR_rsh)
							ASR(r, rLhs, rRhs);
						else // MIR_ush
							LSR(r, rLhs, rRhs);
					}
					#endif
					
					#if defined(AVMPLUS_IA32) || defined(AVMPLUS_AMD64)
					
					Register r = Unknown;
					if (canImmFold(ip, rhs))
					{
						InsRegisterPrepA(ip, gpregs, lhs, r);
						AvmAssert(r != Unknown);
						registerAllocSpecific(gpregs, r);
						setResultReg(gpregs, ip, r);

						if (mircode==MIR_lsh)
							SHL(r, int(rhs->imm));
						else if (mircode==MIR_rsh)
							SAR(r, int(rhs->imm));
						else // MIR_ush
							SHR(r, int(rhs->imm));
					}
					else
					{
						#ifdef AVMPLUS_AMD64
						Register rRhs = RCX;
						#else
						Register rRhs = ECX;
						#endif

						InsRegisterPrepAB(ip, gpregs, lhs, r, gpregs, rhs, rRhs);
						AvmAssert(r != Unknown);
						registerAllocSpecific(gpregs, r);
						setResultReg(gpregs, ip, r);

						#ifdef AVMPLUS_AMD64
						AvmAssert(rRhs == RCX);
						#else
						AvmAssert(rRhs == ECX);						
						#endif
						if (mircode==MIR_lsh)
							SHL(r, rRhs);
						else if (mircode==MIR_rsh)
							SAR(r, rRhs);
						else // MIR_ush
							SHR(r, rRhs);
					}
					#endif
					break;
				}

				case MIR_fneg:
				{
					OP* lhs = ip->oprnd1; // lhs

					if (!ip->lastUse)
					{
						fpregs.expire(lhs, ip);
						break;
					}

					#ifdef AVMPLUS_SPARC
					Register rLhs = Unknown;
					InsRegisterPrepA(ip, fpregs, lhs, rLhs);
					Register r = registerAllocAny(fpregs, ip);

					FNEGD(rLhs, r);

					#endif

					#ifdef AVMPLUS_PPC

					Register rLhs = Unknown;
					InsRegisterPrepA(ip, fpregs, lhs, rLhs);
					Register r = registerAllocAny(fpregs, ip);

					FNEG(r,rLhs);

					#endif

					#ifdef AVMPLUS_ARM
					Register r = Unknown;
					InsRegisterPrepA(ip, fpregs, lhs, r);
					AvmAssert(r == F0);
					registerAllocSpecific(fpregs, r);
					MOV_imm32(IP, 0x80000000);
					EOR(R4, R4, IP);
					#endif
					
					#if defined (AVMPLUS_IA32) || defined(AVMPLUS_AMD64)

					Register r = Unknown;
					InsRegisterPrepA(ip, fpregs, lhs, r);
					AvmAssert(r != Unknown);
					registerAllocSpecific(fpregs, r);

					if (core->config.sse2)
					{
#ifdef AVMPLUS_AMD64
						// use R11 as temp, need a temp XMM reg
						Register rSrc = registerAllocAny(fpregs, lhs);
						MOV(R11, (uintptr)0x8000000000000000);						
						MOVD(rSrc, R11);
						XORPD(r, (Register)rSrc);
						fpregs.addFree(rSrc);
#else
						#if defined(AVMPLUS_WIN32)
						static __declspec(align(16)) uint32 negateMask[] = {0,0x80000000,0,0};
						#elif defined __SUNPRO_CC
						static uint32 temp[] = {0,0,0,0, 0,0,0};
						static uint32 *negateMask = (uint32 *)BIT_ROUND_UP(temp, 16);
						negateMask[1] = 0x80000000;
						#else
						static uint32 __attribute__ ((aligned (16))) negateMask[] = {0,0x80000000,0,0};
						#endif
						XORPD(r,(uintptr)negateMask);
#endif
					}
					else
					{
						AvmAssert(r == FST0);
						AvmAssert(x87Dirty);
						FCHS();
					}
					#endif

					setResultReg(fpregs, ip, r);

					break;
				}
				
				case MIR_neg:
				{
					OP* lhs = ip->oprnd1; // lhs

					if (!ip->lastUse)
					{
						gpregs.expire(lhs, ip);
						break;
					}
					#ifdef AVMPLUS_SPARC
					Register rLhs = Unknown;
					InsRegisterPrepA(ip, gpregs, lhs, rLhs);
					Register r = registerAllocAny(gpregs, ip);

					SUB(G0, rLhs, r);

					#endif

					#ifdef AVMPLUS_PPC
					
					Register rLhs = Unknown;
					InsRegisterPrepA(ip, gpregs, lhs, rLhs);
					Register r = registerAllocAny(gpregs, ip);

					NEG(r,rLhs);

					#endif

					#ifdef AVMPLUS_ARM
					Register rLhs = Unknown;
					InsRegisterPrepA(ip, gpregs, lhs, rLhs);
					//InsRegisterPrepRes(gpregs, ip, r, rLhs, NO_RESTRICTIONS);
					Register r = registerAllocAny(gpregs, ip);
					RSB_imm8(r,rLhs,0);
					#endif
					
					#if defined(AVMPLUS_IA32) || defined(AVMPLUS_AMD64)

					Register r = Unknown;
					InsRegisterPrepA(ip, gpregs, lhs, r);
					registerAllocSpecific(gpregs, r);

					NEG(r);

					#endif
					
					setResultReg(gpregs, ip, r);
					break;
				}

#ifdef AVMPLUS_AMD64
				case MIR_andp:
				case MIR_orp:
#endif

				case MIR_and:
				case MIR_or:
				case MIR_xor:
				case MIR_add:
				case MIR_addp:
				case MIR_sub:
				case MIR_imul:
				{
					OP* lhs = ip->oprnd1; // lhs				
					OP* rhs = ip->oprnd2; // rhs

					if (!ip->lastUse)
					{
						gpregs.expire(lhs, ip);
						gpregs.expire(rhs, ip);
						break;
					}

					#ifndef AVMPLUS_AMD64
					// these are the same from a MD perspective
					if(mircode == MIR_addp)
						mircode = MIR_add;	
					#endif

					// rhs could be imm or reg

					#ifdef AVMPLUS_SPARC

					Register rD = Unknown;
					if (canImmFold(ip, rhs))
					{
						Register rLhs = Unknown;
						InsRegisterPrepA(ip, gpregs, lhs, rLhs);
						rD = registerAllocAny(gpregs, ip);

						AvmAssert(rLhs != Unknown);

						if (mircode == MIR_and)
							ANDI(rLhs, rhs->imm, rD);
						else if (mircode == MIR_or)
							ORI(rLhs, rhs->imm, rD);
						else if (mircode == MIR_xor)
							XORI(rLhs, rhs->imm, rD);
						else if (mircode == MIR_add)
							ADDI(rLhs, rhs->imm, rD);
						else if (mircode == MIR_sub)
							SUBI(rLhs, rhs->imm, rD);
						else if (mircode == MIR_imul)
							MULXI(rLhs, rhs->imm, rD);
					}
					else
					{
						Register rLhs = Unknown;
						Register rRhs = Unknown;
						InsRegisterPrepAB(ip, gpregs, lhs, rLhs, gpregs, rhs, rRhs);
						rD = registerAllocAny(gpregs, ip);

						AvmAssert(rLhs != Unknown);
						AvmAssert(rRhs != Unknown);
						if (mircode == MIR_and)
							AND(rLhs, rRhs, rD);
						else if (mircode == MIR_or)
							OR (rLhs, rRhs, rD);
						else if (mircode == MIR_xor)
							XOR(rLhs, rRhs, rD);
						else if (mircode == MIR_add)
							ADD(rLhs, rRhs, rD);
						else if (mircode == MIR_sub)
							SUB(rLhs, rRhs, rD);
						else if (mircode == MIR_imul)
							MULX(rLhs, rRhs, rD);
					}

					#endif

					#ifdef AVMPLUS_PPC

					Register rD = Unknown;
					if (canImmFold(ip, rhs))
					{
						Register rLhs = Unknown;
						InsRegisterPrepA(ip, gpregs, lhs, rLhs);
						rD = registerAllocAny(gpregs, ip);

						AvmAssert(rLhs != Unknown);

						if (mircode == MIR_and)
							ANDI_dot(rD, rLhs, rhs->imm);
						else if (mircode == MIR_or) {
							Register rSrc = rLhs;
							if (!rhs->imm || rhs->imm & 0xFFFF) {
								ORI(rD, rSrc, rhs->imm&0xFFFF);
								rSrc = rD;
							}
							if (rhs->imm & 0xFFFF0000) {
								ORIS(rD, rSrc, (rhs->imm>>16)&0xFFFF);
							}
						} else if (mircode == MIR_xor) {
							Register rSrc = rLhs;
							if (!rhs->imm || rhs->imm & 0xFFFF) {
								XORI(rD, rSrc, rhs->imm&0xFFFF);
								rSrc = rD;
							}
							if (rhs->imm & 0xFFFF0000) {
								XORIS(rD, rSrc, (rhs->imm>>16)&0xFFFF);
							}
						} else if (mircode == MIR_add)
							ADDI(rD, rLhs, rhs->imm);
						else if (mircode == MIR_sub)
							ADDI(rD, rLhs, -rhs->imm);
					}
					else
					{
						Register rLhs = Unknown;
						Register rRhs = Unknown;
						InsRegisterPrepAB(ip, gpregs, lhs, rLhs, gpregs, rhs, rRhs);
						rD = registerAllocAny(gpregs, ip);

						AvmAssert(rLhs != Unknown);
						AvmAssert(rRhs != Unknown);
						if (mircode == MIR_and)
							AND(rD, rLhs, rRhs);
						else if (mircode == MIR_or)
							OR (rD, rLhs, rRhs);
						else if (mircode == MIR_xor)
							XOR(rD, rLhs, rRhs);
						else if (mircode == MIR_add)
							ADD(rD, rLhs, rRhs);
						else if (mircode == MIR_sub)
							SUB(rD, rLhs, rRhs);
						else if (mircode == MIR_imul)
							MULLW(rD, rLhs, rRhs);
					}
					
					#endif

					#ifdef AVMPLUS_ARM
					Register rD = Unknown;
					if (canImmFold(ip, rhs))
					{
						Register rLhs = Unknown;
						InsRegisterPrepA(ip, gpregs, lhs, rLhs);
						rD = registerAllocAny(gpregs, ip);

						AvmAssert(rLhs != Unknown);

						if (mircode == MIR_and)
							AND_imm8(rD, rLhs, rhs->imm);
						else if (mircode == MIR_or)
							ORR_imm8(rD, rLhs, rhs->imm);
						else if (mircode == MIR_xor)
							EOR_imm8(rD, rLhs, rhs->imm);
						else if (mircode == MIR_add)
							ADD_imm16(rD, rLhs, rhs->imm);
						else if (mircode == MIR_sub)
							SUB_imm8(rD, rLhs, rhs->imm);
					}
					else
					{
						Register rLhs = Unknown;
						Register rRhs = Unknown;
						InsRegisterPrepAB(ip, gpregs, lhs, rLhs, gpregs, rhs, rRhs);
						//InsRegisterPrepRes(gpregs, ip, r, rLhs, NO_RESTRICTIONS);
						rD = registerAllocAny(gpregs, ip);

						AvmAssert(rLhs != Unknown);
						AvmAssert(rRhs != Unknown);
						if (mircode == MIR_and)
							AND(rD, rLhs, rRhs);
						else if (mircode == MIR_or)
							ORR(rD, rLhs, rRhs);
						else if (mircode == MIR_xor)
							EOR(rD, rLhs, rRhs);
						else if (mircode == MIR_add)
							ADD(rD, rLhs, rRhs);
						else if (mircode == MIR_sub)
							SUB(rD, rLhs, rRhs);
						else if (mircode == MIR_imul)
							MUL(rD, rLhs, rRhs);
					}
					#endif
					
					#if defined (AVMPLUS_IA32) || defined(AVMPLUS_AMD64)

					Register rA = Unknown;
					Register rD;
					if (canImmFold(ip, rhs))
					{
						InsRegisterPrepA(ip, gpregs, lhs, rA);
						if (gpregs.free & rmask(rA)) {
							registerAllocSpecific(gpregs, rD=rA);
						} else {
							rD = registerAllocAny(gpregs, ip);
							if (rD != rA)
								moveR2R(ip, rA, rD);
						}

						if (mircode == MIR_and)
						{
							AND(rD, rhs->imm);
						}
						else if (mircode == MIR_or)
						{
							OR (rD, rhs->imm);
						}
						else if (mircode == MIR_xor)
						{
							XOR(rD, rhs->imm);
						}
						else if (mircode == MIR_add)
						{
							ADD(rD, rhs->imm);
						}
						#ifdef AVMPLUS_AMD64
						else if (mircode == MIR_addp)
						{
							ADD64(rD, rhs->imm);
						}
						else if (mircode == MIR_orp)
						{
							OR64(rD, rhs->imm);
						}
						else if (mircode == MIR_andp)
						{
							AND64(rD, rhs->imm);
						}
						#endif
						else if (mircode == MIR_sub)
						{
							SUB(rD, rhs->imm);
						}
						else if (mircode == MIR_imul)
						{
							IMUL(rD, rhs->imm);
						}
					}
					else
					{
						Register rB = Unknown;
						InsRegisterPrepAB(ip, gpregs, lhs, rA, gpregs, rhs, rB);
						registerAllocSpecific(gpregs, rD=rA);

						AvmAssert(rA != Unknown);						
						AvmAssert(rB != Unknown);						
						if (mircode == MIR_and)
							AND(rD, rB);
						else if (mircode == MIR_or)
							OR (rD, rB);
						else if (mircode == MIR_xor)
							XOR(rD, rB);
						else if (mircode == MIR_add)
							ADD(rD, rB);
						#ifdef AVMPLUS_AMD64
						else if (mircode == MIR_addp)
							ADD64(rD, rB);
						else if (mircode == MIR_orp)
							OR64(rD, rB);
						else if (mircode == MIR_andp)
							AND64(rD, rB);
						#endif
						else if (mircode == MIR_sub)
							SUB(rD, rB);
						else if (mircode == MIR_imul)
							IMUL(rD, rB);
					}

                    #endif						

					setResultReg(gpregs, ip, rD);
					break;
				}

				case MIR_eq:
				case MIR_ne:
				case MIR_lt:
				case MIR_le:
				{
					OP* cond = ip->oprnd1;
					AvmAssert(cond != NULL);
					AvmAssert(cond->code == MIR_icmp || cond->code == MIR_ucmp || cond->code == MIR_fcmp);
					(void)cond;
					if (!ip->lastUse)
						break;

					// WARNING: MIR_ne is not the same as !MIR_eq. if unordered, MIR_ne = false 

					// rhs could be imm or reg
					#ifdef AVMPLUS_SPARC
					
					Register r = registerAllocAny(gpregs, ip);

					if (cond->code != MIR_fcmp) {
						switch (mircode) {
						case MIR_ne:
							ORI(G0, 0, r);
							BNE(1, 2);
							ORI(G0, 0x1, r);
							break;
						case MIR_eq:
							ORI(G0, 0, r);
							BE(1, 2);
							ORI(G0, 0x1, r);
							break;
						case MIR_lt:
							ORI(G0, 0, r);
							if( cond->code == MIR_ucmp)
								BLU(1, 2);
							else
								BL(1, 2);
							ORI(G0, 0x1, r);
							break;
						case MIR_le:
							ORI(G0, 0, r);
							if( cond->code == MIR_ucmp)
								BLEU(1, 2);
							else
								BLE(1, 2);
							ORI(G0, 0x1, r);
							break;
						default:
							AvmAssert(false);
							break;
						}
					} else {
						switch (mircode) {
						case MIR_ne:
							ORI(G0, 0x1, r);
							FBUE(1, 2);
							ORI(G0, 0, r);
							break;
						case MIR_eq:
							ORI(G0, 0, r);
							FBE(1, 2);
							ORI(G0, 0x1, r);
							break;
						case MIR_lt:
							ORI(G0, 0, r);
							FBL(1, 2);
							ORI(G0, 0x1, r);
							break;
						case MIR_le:
							ORI(G0, 0, r);
							FBLE(1, 2);
							ORI(G0, 0x1, r);
							break;
						default:
							AvmAssert(false);
							break;
						}
					} 
					setResultReg(gpregs,ip,r);

					#endif // AVMPLUS_SPARC

					#ifdef AVMPLUS_IA32
					registerAllocSpecific(gpregs, EAX);
					if (cond->code != MIR_fcmp)
					{
						// previous icmp or ucmp set EFLAGS
						if (mircode == MIR_eq) {
							SETE(EAX);
						} else if (mircode == MIR_ne) {
							SETNE(EAX);
						} else if (mircode == MIR_lt) {
							if (cond->code == MIR_icmp)
								SETL(EAX);
							else
								SETB(EAX);
						} else {
							if (cond->code == MIR_icmp)
								SETLE(EAX);
							else
								SETBE(EAX);
						}
					}
					else
					{
						if (core->config.sse2) 
						{
							// previous MIR_fcmp set EFLAGS
							// remember, UCOMISD args were reversed so we can test CF=0

							if (mircode == MIR_lt) {
								SETNBE(EAX);
							} else if (mircode == MIR_le) {
								SETNB(EAX);
							} else if (mircode == MIR_ne) {
								SETNE(EAX);
							} else { // MIR_eq
								LAHF();
								TEST_AH(0x44);
								SETNP(EAX);
							}
						}
						else
						{
							// previous MIR_fcmp set FPU status flags
							FNSTSW_AX();
							if (mircode == MIR_ne) {
								TEST_AH(0x44);
								SETE(EAX);
							} else {
								if (mircode == MIR_lt)
									TEST_AH(0x05);
								else if (mircode == MIR_le)
									TEST_AH(0x41);
								else // MIR_eq
									TEST_AH(0x44);
								SETNP(EAX);
							}
						}
					}
					MOVZX_r8(EAX, EAX);  // sign extend AL to EAX
					setResultReg(gpregs, ip, EAX);
					#endif

					#ifdef AVMPLUS_AMD64
					registerAllocSpecific(gpregs, RAX);
					if (cond->code != MIR_fcmp)
					{
						// previous icmp or ucmp set EFLAGS
						if (mircode == MIR_eq) {
							SETE(RAX);
						} else if (mircode == MIR_ne) {
							SETNE(RAX);
						} else if (mircode == MIR_lt) {
							if (cond->code == MIR_icmp)
								SETL(RAX);
							else
								SETB(RAX);
						} else {
							if (cond->code == MIR_icmp)
								SETLE(RAX);
							else
								SETBE(RAX);
						}
					}
					else
					{
						if (core->config.sse2) 
						{
							// previous MIR_fcmp set EFLAGS
							// remember, UCOMISD args were reversed so we can test CF=0

							if (mircode == MIR_lt) {
								SETNBE(RAX);
							} else if (mircode == MIR_le) {
								SETNB(RAX);
							} else if (mircode == MIR_ne) {
								SETNE(RAX);
							} else { // MIR_eq
								LAHF();
								TEST_AH(0x44);
								SETNP(RAX);
							}
						}
						else
						{
							// previous MIR_fcmp set FPU status flags
							FNSTSW_AX();
							if (mircode == MIR_ne) {
								TEST_AH(0x44);
								SETE(RAX);
							} else {
								if (mircode == MIR_lt)
									TEST_AH(0x05);
								else if (mircode == MIR_le)
									TEST_AH(0x41);
								else // MIR_eq
									TEST_AH(0x44);
								SETNP(RAX);
							}
						}
					}
					MOVZX_r8(RAX, RAX);  // sign extend AL to EAX
					setResultReg(gpregs, ip, RAX);
                    
					#endif

					#ifdef AVMPLUS_ARM
					Register r = registerAllocAny(gpregs, ip);
					bool isUnsigned = (cond->code == MIR_ucmp);
					AvmAssert(r != Unknown);

					MOV_imm8 (r, 0);
					switch (mircode) {
					case MIR_lt:
						SET_CONDITION_CODE(isUnsigned ? CC : LT);
						break;
					case MIR_le:
						SET_CONDITION_CODE(isUnsigned ? LS : LE);
						break;
					case MIR_eq:
						SET_CONDITION_CODE(EQ);
						break;
					case MIR_ne:
						SET_CONDITION_CODE(NE);
						break;
					}
					MOV_imm8 (r, 1);
					SET_CONDITION_CODE (AL);

					setResultReg(gpregs, ip, r);
					#endif
					
					#ifdef AVMPLUS_PPC
					
					Register r = registerAllocAny(gpregs, ip);
					// ppc has CMP/CMPL/FCMP for int/uint/double, CR bits are same for each
					switch (mircode) {
					case MIR_ne:
						CROR(28,29,28); // true if <0 or >0, false if 0 or NaN
						MFCR(r);
						RLWINM(r,r,29,31,31);
						break;
					case MIR_eq:
						MFCR(r);
						RLWINM(r,r,31,31,31);
						break;
					case MIR_lt:
						MFCR(r);
						RLWINM(r,r,29,31,31);
						break;
					case MIR_le:
						CROR(30,28,30);
						MFCR(r);
						RLWINM(r,r,31,31,31);
						break;
					default:
						AvmAssert(false);
						break;
					}
					setResultReg(gpregs,ip,r);

					#endif // ppc
					break;
				}

			    case MIR_fadd:
			    case MIR_fsub:
				case MIR_fmul:
			    case MIR_fdiv:
				{
					OP* lhs = ip->oprnd1; // lhs				
					OP* rhs = ip->oprnd2; // rhs

					if (!ip->lastUse)
					{
						fpregs.expire(lhs, ip);
						fpregs.expire(rhs, ip);
						break;
					}

					// rhs could be imm or reg
					#ifdef AVMPLUS_SPARC

					Register rLhs= Unknown;
					Register rRhs = Unknown;

					InsRegisterPrepAB(ip, fpregs, lhs, rLhs, fpregs, rhs, rRhs);
					Register r = registerAllocAny(fpregs, ip);

					AvmAssert(rLhs != Unknown);
					AvmAssert(rRhs != Unknown);
					switch (mircode) {
					case MIR_fadd:
						FADDD(rLhs, rRhs, r);
						break;
					case MIR_fsub:
						FSUBD(rLhs, rRhs, r);
						break;
					case MIR_fmul:
						FMULD(rLhs, rRhs, r);
						break;
					case MIR_fdiv:
						FDIVD(rLhs, rRhs, r);
						break;
					default:
						break;
					}
					setResultReg(fpregs,ip,r);

					#endif //AVMPLUS_SPARC

					// rhs could be imm or reg
                    #ifdef AVMPLUS_PPC

					Register rLhs= Unknown;
					Register rRhs = Unknown;

					InsRegisterPrepAB(ip, fpregs, lhs, rLhs, fpregs, rhs, rRhs);
					Register r = registerAllocAny(fpregs, ip);

					AvmAssert(rLhs != Unknown);
					AvmAssert(rRhs != Unknown);
					switch (mircode) {
					case MIR_fadd:
						FADD(r, rLhs, rRhs);
						break;
					case MIR_fsub:
						FSUB(r, rLhs, rRhs);
						break;
					case MIR_fmul:
						FMUL(r, rLhs, rRhs);
						break;
					case MIR_fdiv:
						FDIV(r, rLhs, rRhs);
						break;
					default:
						break;
					}
					setResultReg(fpregs,ip,r);

                    #endif

					#ifdef AVMPLUS_ARM
					// On ARM, these are helper functions and will never be generated
					// directly.
					AvmAssert(false);
					#endif
					
					#if defined(AVMPLUS_IA32) || defined(AVMPLUS_AMD64)
					
					Register r = Unknown;

					if (core->config.sse2) 
					{
						if (rhs->reg == Unknown && rhs->pos != InvalidPos)
						{
							// rhs value is in memory, put lhs in reg and do R-M operation
							InsRegisterPrepA(ip, fpregs, lhs, r);
							registerAllocSpecific(fpregs, r);

							int disp = stackPos(rhs);
							switch (mircode) {
							case MIR_fadd:
								ADDSD(r, disp, framep);
								break;
							case MIR_fsub:
								SUBSD(r, disp, framep);
								break;
							case MIR_fmul:
								MULSD(r, disp, framep);
								break;
							case MIR_fdiv:
								DIVSD(r, disp, framep);
								break;
							}
						}
						else
						{
							// put lhs & rhs in regs, then do R-R operation
							Register rRhs = Unknown;
							InsRegisterPrepAB(ip, fpregs, lhs, r, fpregs, rhs, rRhs);

							//registerAllocSpecific(fpregs, r);
							if (fpregs.free & rmask(r)) {
								// L is free, use that
								registerAllocSpecific(fpregs, r);
							} else if (fpregs.free & ~rmask(rRhs)) {
								// use any other free except R
								Register rD = registerAllocFromSet(fpregs, fpregs.free & ~rmask(rRhs));
								if (rD != r) {
									moveR2R(ip, r, rD);
									r = rD;
								}
							} else {
								// steal L for result
								registerAllocSpecific(fpregs, r);
							}

							AvmAssert(rRhs != Unknown);
							switch (mircode) {
							case MIR_fadd:
								ADDSD(r, rRhs);
								break;
							case MIR_fsub:
								SUBSD(r, rRhs);
								break;
							case MIR_fmul:
								MULSD(r, rRhs);
								break;
							case MIR_fdiv:
								DIVSD(r, rRhs);
								break;
							}
						}
						setResultReg(fpregs,ip,r);
					} 
					else 
					{
						// x87
						InsRegisterPrepA(ip, fpregs, lhs, r);
						registerAllocSpecific(fpregs, r);

						AvmAssert(r == FST0);
						AvmAssert(rhs->reg == Unknown);
						if (rhs == lhs)
						{
							// x = x (op) x, x in st(0)
							switch (mircode) {
							case MIR_fadd:
								FADDQ(r);		// stack = [lhs+rhs]
								break;
							case MIR_fsub:
								FSUBQ(r);		// stack = [lhs-rhs]
								break;
							case MIR_fmul:
								FMULQ(r);		// stack = [lhs*rhs]
								break;
							case MIR_fdiv:
								FDIVQ(r);		// stack = [lhs/rhs]
								break;
							}
						}
						else
						{
							// rhs in memory
							AvmAssert(rhs->pos != InvalidPos);
							int rhs_disp = stackPos(rhs);	// stack = [lhs]
							switch (mircode) {
							case MIR_fadd:
								FADDQ(rhs_disp, framep);		// stack = [lhs+rhs]
								break;
							case MIR_fsub:
								FSUBQ(rhs_disp, framep);		// stack = [lhs-rhs]
								break;
							case MIR_fmul:
								FMULQ(rhs_disp, framep);		// stack = [lhs*rhs]
								break;
							case MIR_fdiv:
								FDIVQ(rhs_disp, framep);		// stack = [lhs/rhs]
								break;
							}
						}
						setResultReg(fpregs,ip,r);
					}
					#endif
					break;
				}
				
				case MIR_icmp:
				case MIR_ucmp:
				{
					// actual results are in condition codes, so make sure next mir op is
					// a branch that uses them.. otherwise the condition codes are invalid
					OP* lhs = ip->oprnd1; // lhs				
					OP* rhs = ip->oprnd2; // rhs

					if (!ip->lastUse)
					{
						gpregs.expire(lhs, ip);
						gpregs.expire(rhs, ip);
						break;
					}

					#ifdef AVMPLUS_SPARC

					if (canImmFold(ip, rhs))
					{
						// 13-bit immediate values can use SUBCCI
						// instead of SUBCC
						Register rLhs = Unknown;
						InsRegisterPrepA(ip, gpregs, lhs, rLhs);
						AvmAssert(rLhs != Unknown);
						SUBCCI(rLhs, rhs->imm, G0);
					}
					else
					{
						Register rLhs = Unknown;
						Register rRhs = Unknown;
						InsRegisterPrepAB(ip, gpregs, lhs, rLhs, gpregs, rhs, rRhs);
						AvmAssert(rRhs != Unknown);
						AvmAssert(rLhs != Unknown);
						SUBCC(rLhs, rRhs, G0);
					}

					#endif // AVMPLUS_SPARC
					#ifdef AVMPLUS_PPC

					if (canImmFold(ip, rhs))
					{
						// 16-bit immediate values can use cmpi
						// instead of cmp
						Register rLhs = Unknown;
						InsRegisterPrepA(ip, gpregs, lhs, rLhs);
						AvmAssert(rLhs != Unknown);

						if (mircode == MIR_icmp)
							CMPI(CR7, rLhs, rhs->imm);
						else
							CMPLI(CR7, rLhs, rhs->imm);
					}
					else
					{
						Register rLhs = Unknown;
						Register rRhs = Unknown;
						InsRegisterPrepAB(ip, gpregs, lhs, rLhs, gpregs, rhs, rRhs);
						AvmAssert(rRhs != Unknown);
						AvmAssert(rLhs != Unknown);

						if (mircode == MIR_icmp)
							CMP(CR7, rLhs, rRhs);
						else
							CMPL(CR7, rLhs, rRhs);
					}

					#endif

					#ifdef AVMPLUS_ARM
					Register rLhs = Unknown;
					Register rRhs = Unknown;
					InsRegisterPrepAB(ip, gpregs, lhs, rLhs, gpregs, rhs, rRhs);
					AvmAssert(rRhs != Unknown);
					AvmAssert(rLhs != Unknown);

					CMP(rLhs, rRhs);
					#endif
					
					#if defined(AVMPLUS_IA32) || defined(AVMPLUS_AMD64)

					if (canImmFold(ip, rhs))
					{
						Register rLhs = Unknown;
						InsRegisterPrepA(ip, gpregs, lhs, rLhs);
						AvmAssert(rLhs != Unknown);
						if (rhs->imm == 0)
							TEST(rLhs,rLhs);
						else
							CMP(rLhs, rhs->imm);
					}
					else
					{
						Register rLhs= Unknown;
						Register rRhs = Unknown;
						InsRegisterPrepAB(ip, gpregs, lhs, rLhs, gpregs, rhs, rRhs);
						AvmAssert(rRhs != Unknown);
						AvmAssert(rLhs != Unknown);

						CMP(rLhs, rRhs);
					}

					#endif

					ip->reg = Unknown;
					ip->pos = Unknown;
					break;
				}

				case MIR_fcmp:
				{
					// actual results are in condition codes, so make sure next mir op is
					// a branch that uses them.. otherwise the condition codes are invalid
					OP* lhs = ip->oprnd1; // lhs				
					OP* rhs = ip->oprnd2; // rhs

					if (!ip->lastUse)
					{
						fpregs.expire(lhs, ip);
						fpregs.expire(rhs, ip);
						break;
					}

					#ifdef AVMPLUS_SPARC

					Register rLhs = Unknown;
					Register rRhs = Unknown;
					InsRegisterPrepAB(ip, fpregs, lhs, rLhs, fpregs, rhs, rRhs);
					FCMPD(rLhs, rRhs);

					#endif //AVMPLUS_SPARC

					#ifdef AVMPLUS_PPC

					Register rLhs = Unknown;
					Register rRhs = Unknown;
					InsRegisterPrepAB(ip, fpregs, lhs, rLhs, fpregs, rhs, rRhs);
					FCMPU(CR7, rLhs, rRhs);

					#endif

					#ifdef AVMPLUS_ARM
					// This is implemented by a helper function in ARM and should
					// not be generated directly.
					AvmAssert(false);
                    #endif
					
					#if defined(AVMPLUS_IA32) || defined(AVMPLUS_AMD64)

					if (core->config.sse2) 
					{
						Register rLhs = Unknown;
						Register rRhs = Unknown;

						// we reverse the args here, so our SSE2 jlt, jle operators
						// can use JA/JAE and JBE/JB operators to get the right
						// answer for unordered results w/out using LAHF+TEST
						InsRegisterPrepAB(ip, fpregs, rhs, rRhs, fpregs, lhs, rLhs);

						AvmAssert(rLhs != Unknown);
						AvmAssert(rRhs != Unknown);

						UCOMISD(rRhs, rLhs);
						// sets EFLAGS based on float compare
					}
					else
					{
						Register rLhs = Unknown;
						InsRegisterPrepA(ip, fpregs, lhs, rLhs);
						AvmAssert(rLhs == FST0);

						AvmAssert(rhs->reg == Unknown);
						if (rhs == lhs)
						{
							rhs->reg = rLhs;
							spill(rhs);
						}

						AvmAssert(rhs->pos != InvalidPos);

						FCOM(stackPos(rhs), framep);
					}

					#endif

					ip->reg = Unknown;
					ip->pos = Unknown;
					break;
				}

				case MIR_jeq:
				case MIR_jne:
				case MIR_jlt:
				case MIR_jle:
				case MIR_jnle:
				case MIR_jnlt:
				{
					OP* target = ip->target;
					spillTmps(target);
					// this is the instruction of the compare.
					MirOpcode cc = ip->oprnd1->code;
					AvmAssert(cc == MIR_icmp || cc == MIR_ucmp || cc == MIR_fcmp);

					#ifdef AVMPLUS_SPARC
					
					if (cc != MIR_fcmp) {
						switch (mircode) {
						case MIR_jne:
							BNE(0, 0);
							break;
						case MIR_jeq:
							BE(0, 0);
							break;
						case MIR_jlt:
							if( cc == MIR_ucmp)
								BLU(0, 0);
							else
								BL(0, 0);
							break;
						case MIR_jle:
							if( cc == MIR_ucmp)
								BLEU(0, 0);
							else
								BLE(0, 0);
							break;
						case MIR_jnlt:
							if( cc == MIR_ucmp)
								BGEU(0, 0);
							else
								BGE(0, 0);
							break;
						case MIR_jnle:
							if( cc == MIR_ucmp)
								BGU(0, 0);
							else
								BG(0, 0);
							break;
						default:
							AvmAssert(false);
							break;
						}
					} else {
						switch (mircode) {
						case MIR_jne:
							FBNE(0, 0);
							break;
						case MIR_jeq:
							FBE(0, 0);
							break;
						case MIR_jlt:
							FBL(0, 0);
							break;
						case MIR_jle:
							FBLE(0, 0);
							break;
						case MIR_jnlt:
							FBUGE(0, 0);
							break;
						case MIR_jnle:
							FBUG(0, 0);
							break;
						default:
							AvmAssert(false);
							break;
						}
					} 

					#endif // AVMPLUS_SPARC

					#if defined(AVMPLUS_IA32) || defined(AVMPLUS_AMD64)

					if (cc != MIR_fcmp)
					{
						switch (mircode) {
						case MIR_jeq:
							JE(0x7FFFFFFF);
							break;
						case MIR_jne:
							JNE(0x7FFFFFFF);
							break;
						case MIR_jlt:
							if (cc == MIR_icmp)	JL (0x7FFFFFFF);
							else                JB (0x7FFFFFFF);
							break;
						case MIR_jle:
							if (cc == MIR_icmp) JLE(0x7FFFFFFF);
							else                JBE(0x7FFFFFFF);
							break;
						case MIR_jnle:
							if (cc == MIR_icmp) JNLE(0x7FFFFFFF);
							else                JNBE(0x7FFFFFFF);
							break;
						case MIR_jnlt:
							if (cc == MIR_icmp) JNL(0x7FFFFFFF);
							else				JNB(0x7FFFFFFF);
							break;
						default:
							AvmAssert(false);  // default case here to shut compiler up
							break;
						}
					}
					else
					{
						#ifdef AVMPLUS_IA32
						int AX_REG = EAX;
						#else
						int AX_REG = RAX;
						#endif
						if (core->config.sse2)
						{
							// previous fcmp set EFLAGS using UCOMISD
							// result  Z P C
							// ?       1 1 1
							// >       0 0 0
							// <       0 0 1
							// =       1 0 0

							// move flags to AH  (bit7 S Z 0 A 0 P 1 C bit0)
							switch (mircode) {
							case MIR_jne:
							case MIR_jeq:
								registerAllocSpecific(gpregs, (Register)AX_REG);
								LAHF();
								TEST_AH(0x44);
								gpregs.addFree((Register)AX_REG);
								if (mircode == MIR_jne)
									JP  (0x7FFFFFFF);
								else
									JNP (0x7FFFFFFF);
								break;
							case MIR_jlt:
								JNBE (0x7FFFFFF);
								break;
							case MIR_jnlt:  
								JBE  (0x7FFFFFF);
								break;
							case MIR_jle:
								JNB  (0x7FFFFFF);
								break;
							case MIR_jnle:
								JB   (0x7FFFFFF);
								break;
							}
						}
						else
						{
							// previous fcmp set FPU status using FUCOMP
							registerAllocSpecific(gpregs, (Register)AX_REG);
							FNSTSW_AX();
							switch (mircode) {
							case MIR_jeq:
								TEST_AH(0x44);
								JNP(0x7FFFFFFF);
								break;
							case MIR_jne:
								TEST_AH(0x44);
								JP(0x7FFFFFFF);
								break;
							case MIR_jlt:
								TEST_AH(0x05);
								JNP(0x7FFFFFF);
								break;
							case MIR_jnlt:
								TEST_AH(0x05);
								JP(0x7FFFFFF);
								break;
							case MIR_jle:
								TEST_AH(0x41);
								JNP(0x7FFFFFF);
								break;
							case MIR_jnle:
								TEST_AH(0x41);
								JP(0x7FFFFFF);
								break;
							}
							gpregs.addFree((Register)AX_REG);
						}
					}
					#endif

					#ifdef AVMPLUS_ARM
					// We need 32 bits of space to store the patch
					// offset.
					// So, the sense of the branch will be inverted,
					// and we'll jump around the real unconditional
					// branch instruction.
					bool isUnsigned = (cc == MIR_ucmp);
					switch (mircode) {
					case MIR_jeq:
						SET_CONDITION_CODE(EQ);
						break;
					case MIR_jne:
						SET_CONDITION_CODE(NE);
						break;
					case MIR_jlt:
						SET_CONDITION_CODE(isUnsigned ? CC : LT);
						break;
					case MIR_jle:
						SET_CONDITION_CODE(isUnsigned ? LS : LE);
						break;
					case MIR_jnle:
						SET_CONDITION_CODE(isUnsigned ? HI : GT);
						break;
					case MIR_jnlt:
						SET_CONDITION_CODE(isUnsigned ? CS : GE);
						break;
					default:
						AvmAssert(false);  // default case here to shut compiler up
						break;
					}
					B(0);
					SET_CONDITION_CODE(AL);

					#endif
					
					#ifdef AVMPLUS_PPC
					// Branch prediction: If the y bit in the instruction is 0,
					// backwards branch is predicted taken, forwards not taken.
					bool hint = false; // predict true for back branch
					switch (mircode) {
					case MIR_jeq:
						BEQ(CR7,0,hint);
						NOP(); // space if displacement greater than 16 bits
						break;
					case MIR_jne:
						BNE(CR7,0,hint);
						NOP(); // space if displacement greater than 16 bits
						break;
					case MIR_jlt:
						BLT(CR7,0,hint);
						NOP(); // space if displacement greater than 16 bits
						break;
					case MIR_jle:
						if (cc == MIR_fcmp) {
							CROR(30,28,30);
							BEQ(CR7,0,hint);
						} else {
							BLE(CR7,0,hint);
						}
						NOP(); // space if displacement greater than 16 bits
						break;
					case MIR_jnle:
						if (cc == MIR_fcmp) {
							CROR(30,28,30); // Z = Z|N
							BNE(CR7,0,hint);
						} else {
							BGT(CR7,0,hint);
						}
						NOP(); // space if displacement greater than 16 bits
						break;
					case MIR_jnlt:
						BGE(CR7,0,hint);
						NOP(); // space if displacement greater than 16 bits
						break;
					default:
						AvmAssert(false);  // default case here to shut compiler up
						break;
					}

					#endif

					mdPatchPreviousOp(target);

					#ifdef AVMPLUS_SPARC
					NOP();
					#endif

					gpregs.expireAll(ip);
					fpregs.expireAll(ip);
					break;
				}

				case MIR_ret:
				{
					OP* value = ip->oprnd1;

					#if defined (AVMPLUS_IA32) || defined(AVMPLUS_AMD64)
					if (!value->isDouble())
					{
						if (x87Dirty || !core->config.sse2) {
							EMMS();
						}
						#ifdef AVMPLUS_AMD64
						// force oprnd1 into RAX
						Register rRet = RAX;
						InsRegisterPrepA(ip, gpregs, value, rRet);
						AvmAssert(rRet == RAX);
						#else
						// force oprnd1 into EAX
						Register rRet = EAX;
						InsRegisterPrepA(ip, gpregs, value, rRet);
						AvmAssert(rRet == EAX);
						#endif
					}
					else
					{
						// force oprnd1 into ST(0)
						if (core->config.sse2)
						{
							if (x87Dirty)
								EMMS();
							if (value->pos != InvalidPos) {
								#ifdef AVMPLUS_AMD64
								MOVSD(XMM0, stackPos(value), framep);
								#else
								FLDQ(stackPos(value), framep);
								#endif
							} else {
								AvmAssert(value->reg != Unknown);
								#ifdef AVMPLUS_AMD64
								MOVSD(XMM0, value->reg);
								#else
								MOVSD(-8, ESP, value->reg);
								FLDQ(-8, ESP);
								#endif
							}
						}
						else
						{
							if (value->reg != Unknown)
								spill(value);
							EMMS();
							FLDQ(stackPos(value), framep);
						}
						fpregs.expire(value, ip);
					}
					#endif

					#ifdef AVMPLUS_ARM
					// force oprnd1 into R0/F0
					Register rRet;
					RegInfo *regs;
					if (value->isDouble()) {
						rRet = F0;
						regs = &fpregs;
					} else {
						rRet = R0;
						regs = &gpregs;
					}
					InsRegisterPrepA(ip, *regs, value, rRet);
					AvmAssert(rRet == (value->isDouble() ? F0 : R0));

					if (value->isDouble())
					{
						#ifdef AVMPLUS_IYONIX
						// Move from R4-R5 to FPU register F0
						STMFD_bang(SP, R4_mask | R5_mask);
						// LDFD F0, [SP, 0]
						IMM32(0xED1D8100);
						ADD_imm8(SP, SP, 8);
						#else
						// Kludge:
						// Copy contents of F0 into R0-R1 where
						// ARM ABI expects it
						MOV (R0, R4);
						MOV (R1, R5);
						#endif
					}
					#endif
					
					#ifdef AVMPLUS_PPC
					// force oprnd1 into R3/F1 
					Register rRet;
					RegInfo *regs;
					if (value->isDouble()) {
						rRet = F1;
						regs = &fpregs;
					} else {
						rRet = R3;
						regs = &gpregs;
					}
					InsRegisterPrepA(ip, *regs, value, rRet);
					#endif

					#ifdef AVMPLUS_SPARC
					// force oprnd1 into R3/F1 
					Register rRet;
					RegInfo *regs;
					if (value->isDouble()) {
						rRet = F0;
						regs = &fpregs;
					} else {
						rRet = O0;
						regs = &gpregs;
					}
					InsRegisterPrepA(ip, *regs, value, rRet);
					#endif // AVMPLUS_SPARC

					if (ip+1 < ipEnd)
					{
						#ifdef AVMPLUS_SPARC
						BA(0, 0);
						mdPatchPrevious(&patch_end);
						NOP();
						#endif

						#ifdef AVMPLUS_PPC
						B (0); // jump to epilogue
						mdPatchPrevious(&patch_end);
						#endif

						#ifdef AVMPLUS_ARM
						B (8); // jump to epilogue
						mdPatchPrevious(&patch_end);
						#endif
						
						#if defined(AVMPLUS_IA32) || defined(AVMPLUS_AMD64)
						JMP  (0x7FFFFFFF); // jump to epilogue
						mdPatchPrevious(&patch_end);
						#endif
					}
					break;
				}
				case MIR_jmp:
				{
					// if we have any outstanding temporaries then spill them now.
					OP* target = ip->target;
					spillTmps(target);

					if (!(target == ip+1 || target==ip+2 && ip[1].code==MIR_bb))
					{
						#ifdef AVMPLUS_SPARC
						BA(0, 0);
						mdPatchPreviousOp(target);
						NOP();
						#endif

						#ifdef AVMPLUS_PPC
						B (0);
						mdPatchPreviousOp(target);
						#endif

					    #ifdef AVMPLUS_ARM
					    B (8);
					    mdPatchPreviousOp(ip->target);
					    #endif
						
						#if defined(AVMPLUS_IA32) || defined(AVMPLUS_AMD64)
						JMP(0x7FFFFFFF);
						mdPatchPreviousOp(target);
						#endif
					}

					gpregs.expireAll(ip);
					fpregs.expireAll(ip);
					break;
				}

				case MIR_jmpt:
				{
					// copy MIR case table entries to MD case table
					uintptr disp = (uintptr)casePtr;
					for (int i=1, n=ip->size; i <= n; i++) {
						OP* target = ip->args[i];
						spillTmps(target);
						*casePtr++ = (uintptr)target;
					}

					// The pattern for an indirect jump is the following:
					//    MIR_jmpt  [1] size targets[size]
					//
					// where [1] is the variable offset to be added to the md table address
					Register r = Unknown;
					InsRegisterPrepA(ip, gpregs, ip->base, r);
					AvmAssert(r != Unknown);

					#ifdef AVMPLUS_SPARC
					// Maybe not correct.
					LDSW32(r, disp, L0);
					JMPL(G0, L0, G0);
					NOP();
					#endif

					#ifdef AVMPLUS_PPC
					LI32 (R0, disp);
					// Note: LWZX(rD,rA,rB) rB can be R0 
					LWZX (R0, r, R0);
					MTCTR (R0);
					BCTR ();
					#endif

					#ifdef AVMPLUS_ARM
					LDR (IP, disp, r);
					MOV (PC, IP);
					#endif
					
					#ifdef AVMPLUS_IA32
					JMP (disp, r);
					#endif

					#ifdef AVMPLUS_AMD64
					MOV (R11, disp);
					ADD64 (R11, r);
					JMP (0, R11);
					#endif
					
					gpregs.expireAll(ip);
					fpregs.expireAll(ip);

					// skip MIR case table
					ip += (ip->size+3)/4;

					break;
				}

				case MIR_jmpi:
				{			
					// if we have any outstanding temporaries then spill them now.
					spillTmps(ip);

					// The pattern for an indirect jump is the following:
					//    MIR_jmpi  [1] imm32
					//
					// where [1] is the variable offset to be added to the base imm32 value
					// so we need to modify the imm32 to be relative to our buffer.
					Register rTbl = Unknown;
					InsRegisterPrepA(ip, gpregs, ip->base, rTbl);
					AvmAssert(rTbl != Unknown);

					#ifdef AVMPLUS_SPARC
					// Maybe not correct.
					LDSW32(rTbl, ip->disp, L0);
					JMPL(G0, L0, G0);
					NOP();
					#endif

					// jump table is absolute addr, not in MIR code
					#ifdef AVMPLUS_PPC						
					LI32 (R0, ip->disp);
					// Note: LWZX(rD,rA,rB) rB can be R0 
					LWZX (R0, rTbl, R0);
					MTCTR (R0);
					BCTR ();
					#endif

					#ifdef AVMPLUS_ARM
					LDR (IP, ip->disp, rTbl);
					MOV (PC, IP);
					#endif
					
					#ifdef AVMPLUS_IA32
					JMP (ip->disp, rTbl);
					#endif

					#ifdef AVMPLUS_AMD64
					JMP (ip->disp, rTbl);
					#endif

					gpregs.expireAll(ip);
					fpregs.expireAll(ip);
					break;
				}

	#if defined(AVMPLUS_IA32) || defined (AVMPLUS_AMD64)
				case MIR_d2i:
				{
					OP* v = ip->oprnd1; // float to convert

					// !!@ not sure
					if (!ip->lastUse)
					{
						fpregs.expire(v, ip);
						break;
					}

					Register vReg = Unknown;
					InsRegisterPrepA(ip, fpregs, v, vReg);
					Register r = registerAllocAny(gpregs, ip);

					// expire fpregs?

					CVTTSD2SI(r, vReg);
					
					setResultReg(gpregs, ip, r);
				}
				break;
#endif
				case MIR_i2d:
				{
					OP* v = ip->oprnd1; // int to convert

					if (!ip->lastUse)
					{
						gpregs.expire(v, ip);
						break;
					}

					Register r = Unknown;

					#ifdef AVMPLUS_SPARC

					Register vReg = Unknown;
					InsRegisterPrepA(ip, gpregs, v, vReg);
					r = registerAllocAny(fpregs, ip);

					int disp = -8;
					STWI(vReg, disp, SP);
					LDDF32(SP, disp, r);
					FITOD(r, r);
					setResultReg(fpregs,ip,r);

					#endif

					#ifdef AVMPLUS_PPC
					Register vReg = Unknown;
					InsRegisterPrepA(ip, gpregs, v, vReg);
					r = registerAllocAny(fpregs, ip);

					ADDIS (R0, R0, 0x4330);
					STW (R0, 12, SP);
					ADDIS (R0, R0, 0x8000);
					STW (R0, 16, SP);
					LFD (F0, 12, SP);
					XORIS (R0, vReg, 0x8000);
					STW (R0, 16, SP);
					LFD (r, 12, SP);
					FSUB (r, r, F0);

					setResultReg(fpregs, ip, r);
					#endif

					#ifdef AVMPLUS_ARM
					// On ARM, MIR_i2d is never generated directly
					AvmAssert(false);
					#endif
					
					#if defined (AVMPLUS_IA32) || defined(AVMPLUS_AMD64)
					if (core->config.sse2) 
					{
						// see if we can convert right off stack
						if (v->reg == Unknown && v->pos != InvalidPos)
						{
							// only reserve the output don't put input into a register
							gpregs.expire(v, ip);
							r = registerAllocAny(fpregs, ip);
							CVTSI2SD(r, stackPos(v), framep);
						}
						else
						{
							// input already in a register
							Register vReg = Unknown;
							InsRegisterPrepA(ip, gpregs, v, vReg);
							r = registerAllocAny(fpregs, ip);

							CVTSI2SD(r, vReg);
						}
						setResultReg(fpregs, ip, r);
					} 
					else 
					{
						// FILD only works off the stack, so we must get
						// the value on the stack if it isn't already there.
						if (canImmFold(ip, v))
						{
							// Use temporay space on stack for immediate.
							// make sure esp is uptodate

							r = registerAllocAny(fpregs, ip);

							AvmAssert(r==FST0);

							if (v->reg == Unknown)
								MOV  (-4, ESP, v->imm);
							else
								MOV  (-4, ESP, v->reg);
							FFREE(FST7);
							FILD (-4, ESP);

							gpregs.expire(v, ip);
							setResultReg(fpregs,ip,r);
							break;
						}
						else if (v->reg != Unknown)
						{
							// Value is in register; spill onto stack.
							spill(v);
							gpregs.expire(v, ip);
							r = registerAllocAny(fpregs, ip);
						}
						else
						{
							// value on stack
							AvmAssert(v->pos != InvalidPos);

							// get a fp reg for result.
							gpregs.expire(v, ip);
							r = registerAllocAny(fpregs, ip);
						}
						
						// Now load it into fpu, doing int->double conversion
						AvmAssert(r == FST0);
						FFREE(FST7);
						FILD(stackPos(v), framep);
						setResultReg(fpregs, ip, r);
					}
					#endif /* AVMPLUS_PPC */
					break;
				}

				case MIR_u2d:
				{
					OP* v = ip->oprnd1; // int to convert

					if (!ip->lastUse)
					{
						gpregs.expire(v, ip);
						break;
					}

					Register r = Unknown;

					#ifdef AVMPLUS_SPARC

					Register vReg = Unknown;
					Register rTemp = F30;
					InsRegisterPrepA(ip, gpregs, v, vReg);
					r = registerAllocAny(fpregs, ip);
					int disp = -8;

					SETHI(0x43300000, G1);
					STWI(G1, disp, SP);
					STWI(vReg, disp+4, SP);
					LDDF32(SP, disp, rTemp);

					STWI(G0, disp+4, SP);
					LDDF32(SP, disp, r);

					FSUBD(rTemp, r, r);
					FABSS(r, r);

					setResultReg(fpregs,ip,r);

					#endif

					#ifdef AVMPLUS_PPC
					Register vReg = Unknown;
					InsRegisterPrepA(ip, gpregs, v, vReg);
					r = registerAllocAny(fpregs, ip);

					ADDIS (R0, R0, 0x4330);
					STW (R0, 12, SP);
					STW (vReg, 16, SP);
					LFD (r, 12, SP);
					LI (R0, 0);
					STW (R0, 16, SP);
					LFD (F0, 12, SP);
					FSUB (r, r, F0);

					setResultReg(fpregs, ip, r);
					#endif

					#ifdef AVMPLUS_ARM
					// On ARM, MIR_u2d is never generated directly
					AvmAssert(false);
					#endif
					
					#if defined (AVMPLUS_IA32) || defined(AVMPLUS_AMD64)
					Register vReg = Unknown;
					InsRegisterPrepA(ip, gpregs, v, vReg);
					r = registerAllocAny(fpregs, ip);

					#ifdef AVMPLUS_AMD64
					CVTSI2SD64(r, vReg);
					#else

					if (core->config.sse2)
					{
						static const double k_NEGONE = 2147483648.0;
						SUB (vReg, 0x80000000);
						CVTSI2SD(r, vReg);
						ADD (vReg, 0x80000000);
						ADDSD(r, (uintptr) &k_NEGONE, Unknown); 
					}
					else
					{
						// We're doing 32-bit moves here
						int disp = -8;
						MOV (disp+4, ESP, 0);			// high 32 bits = 0
						MOV (disp, ESP, (Register)(vReg&0x7));	// low 32 bits = unsigned value
						AvmAssert(r == FST0);
						FFREE(FST7);
						FILDQ(disp, ESP);
					}					
					#endif

					setResultReg(fpregs,ip,r);
                    #endif
					break;
				}
				
				case MIR_cmop:
				case MIR_csop:
				case MIR_fcmop:
				case MIR_fcsop:

					if (!ip->lastUse)
					{
						// if it's a pure operator call and it's not used, skip it
						int argc = ip->argc;
						OP* postCall = ip + (argc+3)/4;
						for (int i=1; i <= argc; i++)
						{
							OP* argval = ip->args[i];
							RegInfo& regs = argval->isDouble() ? fpregs : gpregs;
							regs.expire(argval, postCall);
						}
						ip = postCall;
						break;
					}
					// else fall through and generate the call

				case MIR_ci:
				case MIR_fci:
				case MIR_cm:
				case MIR_cs:
				case MIR_fcm:
				case MIR_fcs:
				{
					uint32 argc = ip->argc;

					// point to call instruction
					OP* call = ip;
					OP* postCall = call+(argc+3)/4;

					// buffer protection
					const static int maxBytesPerArg = 16;
					if (!ensureMDBufferCapacity(pool, argc*maxBytesPerArg))
						return;

					// dump all the args to the stack
					#ifdef _DEBUG
					MDInstruction* startingMip = mip;
					#endif /*_DEBUG*/

					#ifdef AVMPLUS_IA32
					Register r = ECX;
					Register rHint = EDX; // for interface dispatch
					#endif

					#ifdef AVMPLUS_AMD64
					#ifndef _WIN64
					Register r = RDI;
					Register rHint = RCX; // for interface dispatch
					#else //#ifndef _WIN64
					Register r = RCX;
					Register rHint = R9; // for interface dispatch
					#endif //#ifndef _WIN64
					#endif

					#ifdef AVMPLUS_ARM
					Register r = R0;
					Register rHint = R3; // for interface dispatch
					#endif
					
					#ifdef AVMPLUS_PPC
					Register r = R3;
					Register rHint = R6;
					#endif

					#ifdef AVMPLUS_SPARC
					Register r = O0;
					Register rHint = O3;
					#endif

					sintptr disp = 0;
					OP* base = NULL;
					if ((mircode & ~MIR_float) == MIR_ci)
					{
						OP* hint = call->args[argc];
						call->argc--;
						if (hint) {
							InsRegisterPrepA(call, gpregs, hint, rHint);
						}

						if (call->target->code == MIR_lea)
						{
							// fold the add into an addressing mode
							disp = call->target->disp;
							base = call->target->base;
						}
						else
						{
							base = call->target;
						}

						// force base reg into ECX
						InsRegisterPrepA(ip-1, gpregs, base, r);
					}

					#ifdef AVMPLUS_IA32
						#ifdef _MAC
						// MacOS X ABI requires 16-byte stack alignment.
						// Add a SUB instruction so we can insert some padding later.
						SUB(ESP, 0);
						patch_esp_padding = mip-1;
						#endif
					#endif					
					int at = prepCallArgsOntoStack(call, postCall);
					(void) at;

					// make sure we are accurate in our bytes / argument estimate
					#ifdef _DEBUG
					lastMip = mip; // ignore the args 
					if ((startingMip - mip) > (int)argc*maxBytesPerArg)
						AvmAssert(false);
					#endif /*_DEBUG*/

					// now update the allocator by expiring actives 
					ip = postCall;

					#ifdef AVMPLUS_SPARC
					if ((mircode & ~MIR_float) != MIR_ci)
					{
						// direct call
						thincall(call->addr);
					}
					else
					{
						// Maybe not correct.
						LDSW32(r, disp, L0);
						JMPL(G0, L0, 15);
						NOP();
					}
					#endif

					#ifdef AVMPLUS_PPC

					if ((mircode & ~MIR_float) != MIR_ci)
					{
						// direct call
						thincall(call->addr);
					}
					else
					{
						// indirect call
						AvmAssert(r != Unknown);
						LWZ32(R12, disp, r);
						#if !TARGET_RT_MAC_MACHO
						LWZ(R0, 0, R12);
						MTCTR(R0);
						#else
						MTCTR(R12);
						#endif
						BCTRL();
					}

					#endif

					#ifdef AVMPLUS_ARM
					if ((mircode & ~MIR_float) != MIR_ci)
					{
						// direct call
						thincall(call->addr);
					}
					else
					{
						// indirect call
						AvmAssert(r != Unknown);
						if (disp > -4096 && disp < 4096)
						{
							MOV(LR, PC);
							LDR(PC, disp, r);
						}
						else
						{
							LDR(IP, disp, r);
							MOV(LR, PC);
							MOV(PC, IP);
						}
						gpregs.expire(base,ip);
						// expire IMT reg
						if (gpregs.active[R3])
							gpregs.expire(gpregs.active[R3],ip);

					}
					#endif
					
					#ifdef AVMPLUS_IA32

					if (x87Dirty || !core->config.sse2)
						EMMS();

					#ifdef AVMPLUS_CDECL
					if ((mircode & ~MIR_float & ~MIR_oper) == MIR_cm)
					{
						PUSH(ECX);
						at -= 4;
					}
					#endif
					
					if ((mircode & ~MIR_float) != MIR_ci)
					{
						// direct call
						thincall(call->addr);
					}
					else
					{
						// indirect call
						AvmAssert(r != Unknown);
						CALL(disp, r);
					}

					#ifdef _MAC
					// See if additional padding is needed.
					int calleeAreaSize = -at;
					int alignedCalleeAreaSize = (calleeAreaSize+15) & ~15;
					int padding = alignedCalleeAreaSize - calleeAreaSize;
					if (padding > 0)
					{
						*patch_esp_padding = (byte)padding;
						at -= padding;
					}
					patch_esp_padding = NULL;
					#endif
					
					#ifdef AVMPLUS_CDECL
					if (at != 0)
						ADD(ESP, -at);
					#else
					if ((mircode & ~MIR_float & ~MIR_oper) != MIR_cm)
					{
						// cdecl calling convention, caller did not restore the stack
						if (at != 0)
							ADD(ESP, -at);
					}
					#endif

					if (mircode & MIR_float)
						x87Dirty = true;

					#endif

					// expire all regs.  technically it should just be ones
					#ifdef AVMPLUS_AMD64

					if (x87Dirty || !core->config.sse2)
						EMMS();
					

					if ((mircode & ~MIR_float) != MIR_ci)
					{
						// direct call
						thincall(call->addr);
					}
					else
					{
						// indirect call
						AvmAssert(r != Unknown);
						CALL(disp, r);
					}

					// avoid compiler warning
					(void)at;

					#ifdef _MAC
					// See if additional padding is needed.
					int calleeAreaSize = -at;
					int alignedCalleeAreaSize = (calleeAreaSize+15) & ~15;
					int padding = alignedCalleeAreaSize - calleeAreaSize;
					if (padding > 0)
					{
						*patch_esp_padding = (byte)padding;
						at -= padding;
					}
					patch_esp_padding = NULL;
					#endif
					
					if (mircode & MIR_float)
						x87Dirty = true;

					#endif


					// expire all regs.  technically it should just be ones
					// holding args (and base, and imt id), however in DEBUGGER
					// builds, MIR_def's may be extended so this is more robust.
					gpregs.expireAll(ip);
					fpregs.expireAll(ip);

					if (call->lastUse)
					{
						// result is used, so save it.

						if (!(mircode & MIR_float))
						{

							#ifdef AVMPLUS_SPARC
							setResultReg(gpregs, call, registerAllocSpecific(gpregs, O0));
							#endif

							// 32bit result
							#ifdef AVMPLUS_PPC
							setResultReg(gpregs, call, registerAllocSpecific(gpregs, R3));
							#endif

							#ifdef AVMPLUS_ARM
							setResultReg(gpregs, call, registerAllocSpecific(gpregs, R0));
							#endif
							
							#ifdef AVMPLUS_IA32
							registerAllocSpecific(gpregs, EAX);
							setResultReg(gpregs, call, EAX);
							#endif

							#ifdef AVMPLUS_AMD64
							registerAllocSpecific(gpregs, RAX);
							setResultReg(gpregs, call, RAX);
							#endif
						}
						else 
						{
							#ifdef AVMPLUS_SPARC
							setResultReg(fpregs, call, registerAllocSpecific(fpregs, F0));
							#endif

							// floating point result
							#ifdef AVMPLUS_PPC
							setResultReg(fpregs, call, registerAllocSpecific(fpregs, F1));
							#endif

							#ifdef AVMPLUS_ARM

							#ifdef AVMPLUS_IYONIX
							// Move from FPU register F0 to R4-R5
							// STFD F0, [SP, -#8]!
							IMM32(0xED2D8102);
							LDMFD_bang(SP, R4_mask | R5_mask);
							#else
							// Must move the FP result from R0-R1 to R4-R5
							MOV(R4, R0);
							MOV(R5, R1);
							#endif
							
							setResultReg(fpregs, call, registerAllocSpecific(fpregs, F0));
							#endif
							
							#if defined(AVMPLUS_IA32) || defined(AVMPLUS_AMD64)
							if (core->config.sse2)
							{
#ifdef AVMPLUS_IA32
								// dump it to the stack since we will need it in an XMM reg
								reserveStackSpace(call);
								int disp = stackPos(call);
								FSTPQ(disp, framep);// save st0 on stack, pop.  fpu is now "clean"
								call->reg = Unknown;
								x87Dirty = false;
#else // AVMPLUS_AMD64
								// result is already in XMM0
								setResultReg(fpregs, call, registerAllocSpecific(fpregs, XMM0));
								//x87Dirty = false;
#endif
							}
							else
							{
								// leave result on the stack, for future use.
								setResultReg(fpregs, call, registerAllocSpecific(fpregs, FST0));
							}
							#endif
						}
					}
					else
					{
						// result not used, don't allocate anything

						#if defined(AVMPLUS_IA32) || defined(AVMPLUS_AMD64)
						if (mircode & MIR_float)
						{
							// need to pop the FPU result, or else a sequence of floating point calls
							// can cause it to overflow and generate #IND values in callee functions
							FSTP (FST0);
							x87Dirty = false;
						}
						#endif
					}
					break;
				}

				default:
					AvmAssert(false);
					break;
			}

			// check we didn't gain or lose registers 
			#ifdef _DEBUG
			gpregs.checkCount();
			fpregs.checkCount();
			gpregs.checkActives(ip);
			fpregs.checkActives(ip);
			#endif

            #ifdef AVMPLUS_VERBOSE
			showRegisterStats(gpregs);
			showRegisterStats(fpregs);
			#endif // AVMPLUS_VERBOSE

			ip++;
		}
	}

	#ifdef AVMPLUS_VERBOSE
	void CodegenMIR::showRegisterStats(RegInfo& regs)
	{
		if(!verbose())
			return;

		// track # registers used and use counts
		int active_size=0;
		for (int i=0; i < MAX_REGISTERS; i++)
			if (regs.active[i])
				active_size++;

		// dump out a register map
      
		// any regs?
        if (active_size > 0)
            core->console << "                                 active: ";

        #ifdef AVMPLUS_SPARC
        const char **regnames = (&regs != &fpregs) ? gpregNames : fpregNames;
        #endif

        #if defined(AVMPLUS_PPC)
        const char **regnames = (&regs != &fpregs) ? gpregNames : fpregNames;
        #elif defined(AVMPLUS_ARM)
		const char *const *regnames = regNames;
        #elif defined(AVMPLUS_IA32) || defined(AVMPLUS_AMD64)
		const char **regnames = (&regs != &fpregs) ? gpregNames :
					core->config.sse2 ? xmmregNames : x87regNames;
        #endif

        for(int k=0; k < MAX_REGISTERS; k++)
        {
            OP* ins = regs.active[k];
            if (ins)
            {
                int defined = InsNbr(ins);
                int lastUsed = InsNbr(ins->lastUse);
                core->console << regnames[k] << "(" << defined << "-" << lastUsed << ") ";
            }
        }
        if (!regs.free)
            core->console << " *"; // no more registers available
        //if (stolen)
        //  core->console << " +"; // stolen register on this line
        if (active_size > 0)
            core->console << "\n";

#ifdef AVMPLUS_IA32
		if (regnames == x87regNames)
			core->console << "                                 top = " << (int)x87Top << "\n";
#endif
	}

	/**
	 * Dumps the contents of the stack table 
	 */
	void CodegenMIR::displayStackTable()
	{
		int size = activation.temps.size();
		core->console << "                           stacksize " << (int)activation.size << " entries " << (int)size << "\n";
		for(int i=0; i<size; i++)
		{
			OP* ins = activation.temps[i];
			core->console << "                           " << stackPos(ins) 
				<< "("<<gpregNames[framep]<<") ";
			if (ins->lastUse >= ip)
			{
#ifndef AVMPLUS_SYMBIAN
				core->console << "(" << InsNbr(ins) 
					<< "-" << InsNbr(ins->lastUse)
					<< ") " << mirNames[ins->code];
#endif
			}
			core->console << "\n";
		}
	}
	#endif //AVMPLUS_VERBOSE


	OP* CodegenMIR::RegInfo::findLastActive(int set)
	{
		AvmAssert(set != 0);
		OP* vic = 0;
		for (int i=0; i < MAX_REGISTERS; i++)
		{
			if (set & rmask(i)) {
				OP* ins = active[i];
				if (ins && (!vic || ins->lastUse > vic->lastUse))
					vic = ins;
			}
		}
		return vic;
	}
	
	bool CodegenMIR::isCodeContextChanged() const
	{
		return pool->domain->base != NULL;
	}

	/* set position of label (will trigger patching) */
	void CodegenMIR::mirLabel(MirLabel& l, OP* bb)
	{
		l.bb = bb;
		OP** np = l.nextPatchIns;
		l.nextPatchIns = NULL;
		while(np)
		{
			OP** targetp = np;
			np = (OP**)*targetp;
			*targetp = bb;
		}
	}

	/* patch the location 'where' with the value of the label */
	void CodegenMIR::mirPatchPtr(OP** targetp, sintptr pc)
	{
		mirPatchPtr(targetp, state->verifier->getFrameState(pc)->label);
	}

	void CodegenMIR::mirPatchPtr(OP** targetp, MirLabel& l)
	{
		// either patch it now if we know the location of label or add it to the chain
		if (l.bb)
		{
			*targetp = l.bb;
		}
		else
		{
			*targetp = (OP*)l.nextPatchIns;
			l.nextPatchIns = targetp;
		}
	}

	/* set position of label (will trigger patching) */
	void CodegenMIR::mdLabel(MdLabel* l, void* v)
	{
		l->value = (uintptr)v;
		while(l->nextPatch)
		{
			uint32* ins = l->nextPatch; // next patch is a pointer
			uint32 off = MD_PATCH_LOCATION_GET(ins); // offset to next patch location
			l->nextPatch = (off == 0) ? 0 : (uint32*)((MDInstruction*)ins - off);   // we store offsets of next patch in the patch location
			mdApplyPatch(ins, l->value);
		}
	}

	void CodegenMIR::mdLabel(OP* l, void* v)
	{
		AvmAssert(l->code == MIR_bb);
		l->pos = (uintptr)v;
		while(l->nextPatch)
		{
			uint32* ins = l->nextPatch; // next patch is a pointer
			uint32 off = MD_PATCH_LOCATION_GET(ins); // offset to next patch location
			l->nextPatch = (off == 0) ? 0 : (uint32*)((MDInstruction*)ins - off);   // we store offsets of next patch in the patch location
			mdApplyPatch(ins, l->pos);
		}
	}

	void CodegenMIR::mdPatch(void* v, MdLabel* l)
	{
		// either patch it now if we know the location of label or add it to the chain
		uint32* where = (uint32*)v;
		if (l->value)
		{
			mdApplyPatch(where, l->value);
		}
		else
		{
			AvmAssertMsg(where > l->nextPatch, "patch points must be increasing addresses");
			uint32 off = uint32((l->nextPatch == 0) ? 0 : (MDInstruction*)where - (MDInstruction*)(l->nextPatch));
			MD_PATCH_LOCATION_SET(where, off);
			l->nextPatch = where;
		}
	}

	void CodegenMIR::mdPatch(void* v, OP* l)
	{
		// either patch it now if we know the location of label or add it to the chain
		AvmAssert(l->code == MIR_bb);
		uint32* where = (uint32*)v;
		if (l->pos)
		{
			mdApplyPatch(where, l->pos);
		}
		else
		{
			AvmAssertMsg(where > l->nextPatch, "patch points must be increasing addresses");
			uint32 off = uint32((l->nextPatch == 0) ? 0 : (MDInstruction*)where - (MDInstruction*)(l->nextPatch));
			MD_PATCH_LOCATION_SET(where, off);
			l->nextPatch = where;
		}
	}

	void CodegenMIR::mdApplyPatch(uint32* where, sintptr labelvalue)
	{
		#ifdef AVMPLUS_SPARC
		MDInstruction* savedMip = mip;
		mip = (MDInstruction* )where;

		// displacement relative to our patch address
		int disp = (byte*)labelvalue - (byte*)mip;

		mip[0] &= 0xFFC00000;
		mip[0] |= (disp>>2)&0x3FFFFF;
		mip = savedMip;
		#endif

        #ifdef AVMPLUS_PPC
		MDInstruction* savedMip = mip;
		mip = (MDInstruction* )where;

		// displacement relative to our patch address
		int disp = (byte*)labelvalue - (byte*)mip;
		
		const int B_opcode = 0x48000000;
		const int NOP_opcode = 0x60000000;

		// mip is either directly pointing at the instruction 
		// or its pointing one instruction after the branch.  
		// In the case of it being the same instruction the upper 
		// bits will be 18 (B instruction).
		if ( (*mip >> 26) == 18 )
		{
			int disp = (byte*)labelvalue - (byte*)mip;

			// The biggest branch displacement we can deal with
			// is 26 bits.  If branches get bigger than that (+/- 3MB),
			// need to go to 32-bit jumps via CTR.
			AvmAssert(IsBranchDisplacement(disp));

			// unconditional branch, 26-bit offset
			*mip = B_opcode | (disp&0x3FFFFFF);
		}
		else
		{
			// If the displacement fits in 16 bits, use the ordinary
			// branch instruction.
			if (IsSmallDisplacement(disp+4)) 
			{
				// Add 4 from displacement, since now we're branching
				// relative to our true instruction 
				disp += 4;

				mip[-1] |= (disp&0xFFFF);
				mip[0] = NOP_opcode;
			} 
			else 
			{
				// Otherwise, invert the conditional branch, and use the NOP
				// that we put after the branch to do an unconditional branch,
				// which supports a 26-bit displacement.

				// invert conditional and hint, set offset = 8
				const int COND_HINT_MASK = 0x01200000;
				mip[-1] = (mip[-1]^COND_HINT_MASK) | 8;
				
				// The biggest branch displacement we can deal with
				// is 26 bits.  If branches get bigger than that (+/- 3MB),
				// need to go to 32-bit jumps via CTR.
				AvmAssert(IsBranchDisplacement(disp));
				
				// unconditional branch, 26-bit offset
				mip[0] = B_opcode | (disp&0x3FFFFFF);
			}
		}
		mip = savedMip;
        #endif

		#if defined (AVMPLUS_IA32) || defined(AVMPLUS_AMD64)
		MDInstruction* savedMip = mip;
		mip = (MDInstruction* )where;
		IMM32( int(labelvalue-(uintptr)mip-4) );   // relative branch	(minus the size of the immediate)
		mip = savedMip;
        #endif /* AVMPLUS_IA32 */

		#ifdef AVMPLUS_ARM
		MDInstruction* savedMip = mip;
		mip = (MDInstruction* )where;

		// displacement relative to our patch address
		int disp = (byte*)labelvalue - (byte*)mip;

		// Clobber everything but the condition code
		*mip &= 0xF0000000;

		// Write in the branch instruction
		*mip |= 0x0A000000 | ((disp-8)>>2)&0xFFFFFF;

		mip = savedMip;
		#endif
	}

#ifdef DEBUGGER
	void CodegenMIR::emitSampleCheck()
	{
		/* @todo  inlined sample check doesn't work, help! 
			OP* takeSample = loadIns(MIR_ld, (int)&core->takeSample, NULL);
			OP* br = Ins(MIR_jeq, binaryIns(MIR_ucmp, takeSample, InsConst(0)));
			callIns(MIR_cm, COREADDR(AvmCore::sample), 1, InsConst((int32)core));
			br->target = Ins(MIR_bb);
		*/
		callIns(MIR_cm, COREADDR(AvmCore::sampleCheck), 1, InsConst((uintptr)core));
	}
#endif

#ifdef AVMPLUS_VERBOSE
	bool CodegenMIR::verbose() 
	{
		return state && state->verifier->verbose || pool->verbose;
	}
#endif

#if HAVE_MIR_SMOPS
	int32 CodegenMIR::maddrImplicitDisp(OP *op)
	{
		AvmAssert(op->code == MIR_maddr);
		int32 mn = op->imm >> 16;
		int32 mx = (op->imm << 16) >> 16;

		AvmAssert(mx > mn);
		// if the whole range can fit into the min size,
		// we can move the range from [mn, mx) to 
		// [0, (mx-mn) ) and use only one unsigned compare
		// to range check and then factor the adjustment
		// into the actual loads and stores
		if((mx - mn) <= Domain::GLOBAL_MEMORY_MIN_SIZE)
			return -mn;
		return 0;
}

	OP *CodegenMIR::maddrOpt(OP *a, int32 size, int32 *disp)
	{
		if((a->code == MIR_add ||
			a->code == MIR_sub) &&
			((a->oprnd1->code == MIR_imm &&
			!(a->oprnd1->imm % 4)) || 
			(a->oprnd2->code == MIR_imm &&
			!(a->oprnd2->imm % 4))
			))
		{
			OP* imm;
			OP* notImm;
			
			if(a->oprnd1->code == MIR_imm)
			{
				imm = a->oprnd1;
				notImm = a->oprnd2;
			}
			else
			{
				imm = a->oprnd2;
				notImm = a->oprnd1;
			}
			int32 mn = 0;
			int32 mx = size;
			int32 disp2 = (a->code == MIR_sub) ? -imm->imm : imm->imm;
			mn += disp2;
			mx += disp2;
			// both going to fit in 15 bits?
			if((mn << 17) >> 17 == mn && (mx << 17) >> 17 == mx)
			{
				*disp = disp2;
				return Ins(MIR_maddr, notImm, (mn << 16) | (mx & 0xffff));
			}
		}
		return NULL;
}

#endif
#if (defined(_DEBUG)) && HAVE_MIR_SMOPS
		// raw memory stats
	int CodegenMIR::totalRangeChecks = 0;
	int CodegenMIR::implicitMaddrDisps = 0;
	int CodegenMIR::singleCmpRangeChecks = 0;
	int CodegenMIR::doubleCmpRangeChecks = 0;
#endif
}
#endif // AVMPLUS_MIR
