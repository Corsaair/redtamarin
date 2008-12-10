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

#ifndef __avmplus_CodegenMIR__
#define __avmplus_CodegenMIR__

#ifdef PERFM
#include "../vprof/vprof.h" 
#define count_instr() _nvprof("x86",1)
#define count_ret() _nvprof("x86-ret",1) count_instr()
#define count_push() _nvprof("x86-push",1) count_instr()
#define count_pop() _nvprof("x86-pop",1) count_instr()
#define count_st() _nvprof("x86-st",1) count_instr()
#define count_stq() _nvprof("x86-stq",1) count_instr()
#define count_ld() _nvprof("x86-ld",1) count_instr()
#define count_ldq() _nvprof("x86-ldq",1) count_instr()
#define count_call() _nvprof("x86-call",1) count_instr()
#define count_calli() _nvprof("x86-ld",1); _nvprof("x86-calli",1) count_instr()
#define count_prolog() _nvprof("x86-prolog",1) count_instr()
#define count_alu() _nvprof("x86-alu",1) count_instr()
#define count_mov() _nvprof("x86-mov",1) count_instr()
#define count_fpu() _nvprof("x86-fpu",1) count_instr()
#define count_jmp() _nvprof("x86-jmp",1) count_instr()
#define count_jcc() _nvprof("x86-jcc",1) count_instr()
#define count_thunk() _nvprof("x86-thunk",1) count_instr()
#define count_imt() _nvprof("x86-imt",1) count_instr()
#define count_fpuld() _nvprof("x86-ldq",1); _nvprof("x86-fpu",1); count_instr()
#define count_aluld() _nvprof("x86-ld",1); _nvprof("x86-alu",1); count_instr()
#define count_pushld() _nvprof("x86-ld",1); _nvprof("x86-push",1); count_instr()
#define count_jmpld() _nvprof("x86-ld",1); _nvprof("x86-jmp",1); count_instr()
#define count_leave() _nvprof("x86-alu",1); _nvprof("x86-pop",1); count_instr()
#else
#define count_instr() 
#define count_ret() 
#define count_push() 
#define count_pop()
#define count_st() 
#define count_stq()
#define count_ld() 
#define count_ldq() 
#define count_call()
#define count_calli() 
#define count_prolog()
#define count_alu()
#define count_mov()
#define count_fpu()
#define count_jmp()
#define count_jcc()
#define count_thunk()
#define count_imt() 
#define count_fpuld()
#define count_aluld() 
#define count_pushld() 
#define count_jmpld()
#define count_leave()
#endif

namespace avmplus
{
#ifdef AVMPLUS_MOPS
	#ifdef AVMPLUS_IA32
	#ifndef AVMPLUS_64BIT
	#define HAVE_MIR_SMOPS 1
	#endif
	#endif
#endif

	// bit insert and extraction macros.  
	// usage   v - variable, h - high bit number. l - lower bit number, q qunatity to insert
	// E.g.  pull out bits 6..2 of a variable BIT_EXTRACT(v,6,2).... 0xxx xx00 
	// wanring bit insert does not mask off upper bits of q, so you must make sure that
	// the value of q is legal given h and l.
	// BIT_VALUE_FIT can be used to determine if a value can be represeted by the
	// specified number of bits.
	#define BIT_INSERT(v,h,l,q)    ( ( ( ((unsigned)v)&~(((1L<<((h+1)-(l))) - 1L)<<(l)) ) | ((q)<<(l)) ) )
	#define BIT_EXTRACT(v,h,l)     ( ( ((unsigned)v)&(((1L<<((h+1)-(l))) - 1L)<<(l)) ) >>(l) )
	#define BIT_VALUE_FITS(v,n)    ( BIT_EXTRACT(v,n-1,0) == (v) )

	// rounding v up to the given 2^ quantity
	#define BIT_ROUND_UP(v,q)      ( (((uintptr)v)+(q)-1) & ~((q)-1) )

	#ifdef VTUNE
	class LineNumberRecord : public MMgc::GCObject
	{
	public:
		LineNumberRecord(Stringp fn, uint32 ln)
		: filename(fn)
		, lineno(ln)
		{ }

       String*  filename;
       uint32_t lineno;
	}; 

	class JITCodeInfo : public MMgc::GCObject
	{
	public:
		JITCodeInfo(MMgc::GC* gc) : lineNumTable(gc,512) {}

		MethodInfo* method;
		SortedIntMap<LineNumberRecord*> lineNumTable;       // populated during code generation 
		uintptr startAddr;
		uintptr endAddr;
		iJIT_Method_NIDS* vtune;            // vtune record inlined in code (if any)
		uint32_t sid;  // code info id

		LineNumberRecord* add(MMgc::GC* gc, uintptr_t loc, Stringp file, uint32_t line)
		{
			LineNumberRecord* record = new (gc) LineNumberRecord(file,line);
			lineNumTable.put(loc,record);
			return record;
		}

		void clear() 
		{
			lineNumTable.clear();
			method = 0;
			vtune = 0;
			startAddr = 0;
			endAddr = 0;
		}
	};
	#endif /* VTUNE */

	inline unsigned int rmask(int r) {
		return 1 << r;
	}

	class FrameState;
		
	/**
	 * The CodegenMIR class is a dynamic code generator which translates
	 * AVM+ bytecodes into an architecture neutral intermediate representation
	 * suitable for common subexpression elimination, inlining, and register
	 * allocation.
	 */
	class CodegenMIR
	#ifdef AVMPLUS_ARM
		: public ArmAssembler
	#endif
	{
		AvmCore * const core;
		PoolObject * const pool;
		MethodInfo * const info;
		FrameState *state;

		#ifdef AVMPLUS_MAC_CARBON
		static int setjmpDummy(jmp_buf buf);
		static int setjmpAddress;
		static void setjmpInit();
		#endif

	public:

		/** set to true if the no more memory. */
		bool overflow;

#if HAVE_MIR_SMOPS
		// the lower two bits of the displacement
		// of a "sized" load or store indicate
		// size and sign extension info...
		// masks and bits for said...
		enum
		{
			SMOP_F32 = 0, // 32 bit float sized MOP
			SMOP_SX = 1, // sign extend bit
			SMOP_I8 = 0, // 8 bit MOP
			SMOP_I8SX = SMOP_I8 | SMOP_SX, // 8 bit sign extend MOP
			SMOP_I16 = 2, // 16 bit MOP
			SMOP_I16SX = SMOP_I16 | SMOP_SX, // 16 bit sign extend MOP
			SMOP_MASK = 3, // mask for sized memory ops
			SMOP_BITS = 2 // bits in sized memory ops
		};
#endif
		static const int MIR_float = 0x40;		// result is double
		static const int MIR_oper  = 0x80;		// eligible for cse

		typedef unsigned int MirOpcode;
		enum
		{
			MIR_bb      = 2,
			MIR_jmpt	= 3,				// offset, size
			MIR_cm		= 4,				// count, imm32  - call method
			MIR_cs		= 5,				// count, imm32  - call static
			MIR_ci		= 6,				// count, ptr	 - call indirect
			MIR_icmp 	= 7,				// ptr, imm32
			MIR_ucmp	= 8,				// ptr, imm32
			MIR_fcmp	= 9,				// ptr, imm32
			MIR_jeq		= 10,				// ptr, imm32
			MIR_jne		= 11,				// ptr, imm32
			MIR_ret		= 12,				// ptr
			MIR_jmp		= 13,				// ptr
			MIR_jmpi	= 14,				// ptr, disp
			MIR_st		= 15,				// ptr, disp, ptr
			MIR_arg     = 16,				// pos | reg - defines methods incoming arguments
			MIR_def		= 17,				// 
			MIR_use		= 18,				// 
			MIR_usea	= 19,				// imm32
			MIR_alloc   = 20,
			MIR_addp	= 21,     // no cse add for adjusted builtin ScriptObject ptrs (NOT 64-bit related)
			MIR_ld      = 22,				// non-optimizable load
			MIR_jlt     = 23,
			MIR_jle		= 24,
			MIR_jnlt	= 25,
			MIR_jnle	= 26,
			MIR_file	= 27,
			MIR_line	= 28,
			MIR_st32	= 29,
#ifdef AVMPLUS_64BIT
			MIR_ld32	= 30,
			MIR_ld32u	= 31,
#else
			MIR_ld32	= MIR_ld,
			MIR_ld32u	= MIR_ld,
#endif
#if HAVE_MIR_SMOPS            
			// like regular loads or stores except lower 2 bits of disp indicate size / sign extend info
			// using bits from SMOP_xxx
			MIR_sld		= 32,				// sized memory load
			MIR_sst		= 33,				// sized memory store
#endif

#if defined(AVMPLUS_IA32) || defined(AVMPLUS_AMD64)
			MIR_d2i		= 36,				// cvttsd2si for SSE2
#endif

			MIR_imm		= 1  | MIR_oper,	// 0,imm32
			MIR_imul	= 2  | MIR_oper,
			MIR_neg		= 3  | MIR_oper,	// ptr, ptr
			MIR_cmop    = 4  | MIR_oper,    // MIR_cm|oper, call method w/out side effects
			MIR_csop    = 5  | MIR_oper,    // MIR_cs|oper, call static method w/out side effects
			MIR_lsh		= 6  | MIR_oper,	// <<
			MIR_rsh		= 7  | MIR_oper,	// >>
			MIR_ush		= 8  | MIR_oper,	// >>>
			MIR_and		= 9  | MIR_oper,
			MIR_or		= 10 | MIR_oper,
			MIR_xor		= 11 | MIR_oper,
			MIR_add		= 12 | MIR_oper,
			MIR_sub		= 13 | MIR_oper,	// ptr, ptr
			MIR_eq		= 14 | MIR_oper,
			MIR_le		= 15 | MIR_oper,
			MIR_lt		= 16 | MIR_oper,
			MIR_ne		= 17 | MIR_oper,
			MIR_lea		= 18 | MIR_oper,	// ptr, disp

#if HAVE_MIR_SMOPS
			MIR_sx8		= 19 | MIR_oper,	// 8 bit sign extend
			MIR_sx16	= 20 | MIR_oper,	// 16 bit sign extend
			// range check for memory access and bless for raw access
			// oprnd1 is the base expression
			// disp holds the range for which the expression is checked
			// where the low 16 bits are a signed 16 bit value
			// representing the base of the range and the high
			// 16 bits are a signed 16 bit value representing the
			// bound of the range
			// TODO add a struct to Op's oprnd2 union that holds signed
			// 16 bit high / lo?  mildly complicated but doable
			MIR_maddr	= 21 | MIR_oper,
#endif
			MIR_ldop    = 22 | MIR_oper,    // ptr, disp (optimizable)
#if HAVE_MIR_SMOPS
			MIR_sldop	= 27 | MIR_oper,	// optimizable sized memory load
#endif

#ifdef AVMPLUS_64BIT
			MIR_orp     = 23 | MIR_oper,	// ptr sized OR operation
			MIR_andp    = 24 | MIR_oper,	// ptr sized AND operation
#else
			MIR_orp     = MIR_or,			// ptr sized OR operation (same on 32-bit systems)
			MIR_andp    = MIR_and,			// ptr sized AND operation (same on 32-bit systems)
#endif

			// After this point are all instructions that return a double-sized
			// result.
			MIR_fcm		= 4  | MIR_float,	// count, imm32 - call method, float return
			MIR_fcs		= 5  | MIR_float,	// count, imm32 - call static, float return
			MIR_fci		= 6	 | MIR_float,	// count, addr - call indirect, float return

			MIR_fdef    = 17 | MIR_float,   // defines value of variable as floating point
			MIR_fuse    = 18 | MIR_float,   // 

			MIR_fld		= 22 | MIR_float,	// float load
#if HAVE_MIR_SMOPS
			MIR_fsld	= 32 | MIR_float,	// sized memory float load
#endif


			MIR_i2d		= 1  | MIR_float | MIR_oper,	// ptr
			MIR_fneg	= 2  | MIR_float | MIR_oper,	// ptr
			MIR_u2d		= 3  | MIR_float | MIR_oper,
			MIR_fcmop   = 4  | MIR_float | MIR_oper,
			MIR_fcsop   = 5  | MIR_float | MIR_oper,
			MIR_fadd	= 6  | MIR_float | MIR_oper,	// ptr, ptr
			MIR_fsub	= 7  | MIR_float | MIR_oper,	// ptr, ptr
			MIR_fmul	= 8  | MIR_float | MIR_oper,	// ptr, ptr
			MIR_fdiv	= 9  | MIR_float | MIR_oper,	// ptr, ptr
			
			MIR_fldop   = 22 | MIR_float | MIR_oper,	// ptr, disp (optimizable load)

#if HAVE_MIR_SMOPS
			MIR_fsldop	= 32 | MIR_float | MIR_oper,	// sized memory float load (optimizable)
			// MIR_last should be one greater than the highest opcode value.
			MIR_last	= 33 | MIR_float | MIR_oper
#else
			MIR_last	= 23 | MIR_float | MIR_oper // highest ordinal value possible
#endif

		};

		enum ArgNumber {
			_env = 0,
			_argc = 1, 
			_ap = 2
		};
		// ia32 offset = 4*ArgNumber+4

		/**
		 * Constructor.  Initializes the generator for building a method
		 */
		CodegenMIR(MethodInfo* info);

		/**
		 * Constructor for use with emitImtThunk
		 */
		CodegenMIR(PoolObject* pool);

		~CodegenMIR();

		/* Frees our MIR buffers when needed. */
		void clearMIRBuffers();

		/**
		 * Generates code for the method info.  The bytecode is translated
		 * into native machine code and the TURBO flag is set
		 * on the MethodInfo.  The original bytecode is retained for debugging.
		 * @param info method to compile
		 */
		void epilogue(FrameState* state);
		bool prologue(FrameState* state);
		void emitCall(FrameState* state, AbcOpcode opcode, sintptr method_id, int argc, Traits* result);
		void emit(FrameState* state, AbcOpcode opcode, uintptr op1=0, uintptr op2=0, Traits* result=NULL);
		void emitIf(FrameState* state, AbcOpcode opcode, sintptr target, int lhs, int rhs);
		void emitSwap(FrameState* state, int i, int j);
		void emitCopy(FrameState* state, int src, int dest);
		void emitGetscope(FrameState* state, int scope, int dest);
		void emitKill(FrameState* state, int i);
		void emitBlockStart(FrameState* state);
		void emitBlockEnd(FrameState* state);
		void emitIntConst(FrameState* state, int index, uintptr c);
		void emitDoubleConst(FrameState* state, int index, double* pd);
		void emitCoerce(FrameState* state, int index, Traits* type);
		void emitDoubleToInteger(int index);
		void emitCheckNull(FrameState* state, int index);
		void emitSetContext(FrameState* state, AbstractFunction* f);
		void emitSetDxns(FrameState* state);
		void merge(int, const Value& current, Value& target);
		void opcodeVerified(AbcOpcode /*opcode*/, FrameState* /*state*/) {}

#ifdef AVMPLUS_VERBOSE
		bool verbose();
#endif

#ifndef FEATURE_BUFFER_GUARD
		bool checkOverflow();
#endif

		/**
		 * Generates code for a native method thunk.
		 */
		void* emitImtThunk(ImtBuilder::ImtEntry *e);

	private:

		void emitPrep(AbcOpcode opcode);

		const byte *abcStart;
		const byte *abcEnd;

		//
		// helpers called by generated code
		//
		static Atom coerce_o(Atom v);

		#ifdef AVMPLUS_ARM
		//
		// ARM needs helpers for floating point
		//
		static double fadd(double x, double y);
		static double fsub(double x, double y);
		static double fmul(double x, double y);
		static double fdiv(double x, double y);
		static int    fcmp(double x, double y);
		static double i2d(int i);
		static double u2d(uint32 i);
		#endif
	
	public:

		#ifdef AVMPLUS_SPARC

		#ifdef AVMPLUS_VERBOSE
		static const char *gpregNames[];
		static const char *fpregNames[];
		#endif

		typedef unsigned Register;
		static const int MAX_REGISTERS = 32;
		enum
		{
			R0  = 0,
			R1  = 1,
			R2  = 2,
			R3  = 3,
			R4  = 4,
			R5  = 5,
			R6  = 6,
			R7  = 7,
			R8  = 8,
			R9  = 9,
			R10 = 10,						
			R11 = 11,						
			R12 = 12,						
			R13 = 13,						
			R14 = 14,						
			R15 = 15,						
			R16 = 16,						
			R17 = 17,						
			R18 = 18,						
			R19 = 19,						
			R20 = 20,						
			R21 = 21,						
			R22 = 22,						
			R23 = 23,						
			R24 = 24,						
			R25 = 25,						
			R26 = 26,						
			R27 = 27,						
			R28 = 28,						
			R29 = 29,						
			R30 = 30,
			R31 = 31,			

			SP  = 14,
			FP  = 30,

			G0  = 0,
			G1  = 1,
			G2  = 2,
			G3  = 3,
			G4  = 4,
			G5  = 5,
			G6  = 6,
			G7  = 7,

			O0  = 8,
			O1  = 9,
			O2  = 10,
			O3  = 11,
			O4  = 12,
			O5  = 13,
			O6  = 14,
			O7  = 15,

			L0  = 16,
			L1  = 17,
			L2  = 18,
			L3  = 19,
			L4  = 20,
			L5  = 21,
			L6  = 22,
			L7  = 23,

			I0  = 24,
			I1  = 25,
			I2  = 26,
			I3  = 27,
			I4  = 28,
			I5  = 29,
			I6  = 30,
			I7  = 31,

			F0  = 0,
			F1  = 1,
			F2  = 2,
			F3  = 3,
			F4  = 4,
			F5  = 5,
			F6  = 6,
			F7  = 7,
			F8  = 8,
			F9  = 9,
			F10 = 10,						
			F11 = 11,						
			F12 = 12,						
			F13 = 13,						
			F14 = 14,						
			F15 = 15,						
			F16 = 16,						
			F17 = 17,						
			F18 = 18,						
			F19 = 19,						
			F20 = 20,						
			F21 = 21,						
			F22 = 22,						
			F23 = 23,						
			F24 = 24,						
			F25 = 25,						
			F26 = 26,						
			F27 = 27,						
			F28 = 28,						
			F29 = 29,						
			F30 = 30,
			F31 = 31,
			Unknown = 0x7F

		};
		#endif //AVMPLUS_SPARC

		//
		// Register allocation stuff follows
		// Encoded in 7b quantity
		//

		#ifdef AVMPLUS_PPC

		#ifdef AVMPLUS_VERBOSE
		static const char *gpregNames[];
		static const char *fpregNames[];
		#endif
		
		typedef enum {
			CR0 = 0,
			CR1 = 1,
			CR2 = 2,
			CR3 = 3,			
			CR4 = 4,
			CR5 = 5,
			CR6 = 6,
			CR7 = 7
		} ConditionRegister;

		// These are used as register numbers in various parts of the code
		static const int MAX_REGISTERS = 32;
		enum
		{
			// general purpose 32bit regs
			R0  = 0, // scratch or the value 0
			SP  = 1, // stack pointer
			RTOC= 2, // toc pointer
			R3  = 3, // this, return value
			R4  = 4,
			R5  = 5,
			R6  = 6,
			R7  = 7,
			R8  = 8,
			R9  = 9,
			R10 = 10,						
			R11 = 11,						
			R12 = 12,						
			R13 = 13,						
			R14 = 14,						
			R15 = 15,						
			R16 = 16,						
			R17 = 17,						
			R18 = 18,						
			R19 = 19,						
			R20 = 20,						
			R21 = 21,						
			R22 = 22,						
			R23 = 23,						
			R24 = 24,						
			R25 = 25,						
			R26 = 26,						
			R27 = 27,						
			R28 = 28,						
			R29 = 29,						
			R30 = 30,
			R31 = 31,			

			// FP regs
			F0  = 0,
			F1  = 1,
			F2  = 2,
			F3  = 3,
			F4  = 4,
			F5  = 5,
			F6  = 6,
			F7  = 7,
			F8  = 8,
			F9  = 9,
			F10 = 10,						
			F11 = 11,						
			F12 = 12,						
			F13 = 13,						
			F14 = 14,						
			F15 = 15,						
			F16 = 16,						
			F17 = 17,						
			F18 = 18,						
			F19 = 19,						
			F20 = 20,						
			F21 = 21,						
			F22 = 22,						
			F23 = 23,						
			F24 = 24,						
			F25 = 25,						
			F26 = 26,						
			F27 = 27,						
			F28 = 28,						
			F29 = 29,						
			F30 = 30,
			F31 = 31,

			// special purpose registers (SPR)
			LR  = 8,
			CTR = 9,

			Unknown = 0x7f
		};
		typedef unsigned Register;
		#endif

		#ifdef AVMPLUS_ARM
		static const int MAX_REGISTERS = 16;
        #endif
		
		#ifdef AVMPLUS_IA32

		#ifdef AVMPLUS_VERBOSE
		static const char *gpregNames[];
		static const char *xmmregNames[];
		static const char *x87regNames[];
		#endif

		#ifdef _MAC
		byte *patch_esp_padding;
		#endif

		// These are used as register numbers in various parts of the code
		static const int MAX_REGISTERS = 8;

		typedef enum
		{
			// general purpose 32bit regs
			EAX = 0, // return value, scratch
			ECX = 1, // this, scratch
			EDX = 2, // scratch
			EBX = 3,
			ESP = 4, // stack pointer
			EBP = 5, // frame pointer
			ESI = 6,
			EDI = 7,

			SP = 4, // alias SP to ESP to match PPC name
 
			// SSE regs
			XMM0 = 0,
			XMM1 = 1,
			XMM2 = 2,
			XMM3 = 3,
			XMM4 = 4,
			XMM5 = 5,
			XMM6 = 6,
			XMM7 = 7,

			// X87 regs
			FST0 = 0,
			FST1 = 1,
			FST2 = 2,
			FST3 = 3,
			FST4 = 4,
			FST5 = 5,
			FST6 = 6,
			FST7 = 7,

			#ifdef SOLARIS
			Unknown = 0x7f
			#else
			Unknown = -1
			#endif
		} 
		Register;
		#endif

		#if defined (AVMPLUS_AMD64)

		#ifdef AVMPLUS_VERBOSE
		static const char *gpregNames[];
		static const char *xmmregNames[];
		static const char *x87regNames[];
		#endif

		#ifdef _MAC
		byte *patch_esp_padding;
		#endif

		// These are used as register numbers in various parts of the code
		static const int MAX_REGISTERS = 24;

		typedef enum
		{
			// 64bit - at this point, I'm not sure if we'll be using EAX, etc as registers
			// or whether this numbering scheme is correct.  For some generated ASM, usage
			// of RAX implies a REX prefix byte to define the 64-bit operand.  But the ModRM
			// byte stays the same (EAX=RAX in the encoding)
			
			// general purpose 32bit regs
			EAX = 0, // return value, scratch
			ECX = 1, // this, scratch
			EDX = 2, // scratch
			EBX = 3,
			ESP = 4, // stack pointer
			EBP = 5, // frame pointer
			ESI = 6,
			EDI = 7,
			
			RAX = 8, // return value, scratch
			RCX = 9, // this, scratch
			RDX = 10, // scratch
			RBX = 11,
			RSP = 12, // stack pointer
			RBP = 13, // frame pointer
			RSI = 14,
			RDI = 15,
			
			R8 = 16,
			R9 = 17,
			R10 = 18,
			R11 = 19,
			R12 = 20,
			R13 = 21,
			R14 = 22,
			R15 = 23,

			SP = 12, // alias SP to RSP to match PPC name
 
			// SSE regs
			XMM0 = 0,
			XMM1 = 1,
			XMM2 = 2,
			XMM3 = 3,
			XMM4 = 4,
			XMM5 = 5,
			XMM6 = 6,
			XMM7 = 7,
			XMM8 = 8,
			XMM9 = 9,
			XMM10 = 10,
			XMM11 = 11,
			XMM12 = 12,
			XMM13 = 13,
			XMM14 = 14,
			XMM15 = 15,

			// !!@ remove all float support?  SSE2 is always available
			// X87 regs
			FST0 = 0,
			FST1 = 1,
			FST2 = 2,
			FST3 = 3,
			FST4 = 4,
			FST5 = 5,
			FST6 = 6,
			FST7 = 7,

			#ifdef SOLARIS
			Unknown = 0x7f
			#else
			Unknown = -1
			#endif
		} 
		Register;
		#endif // AVMPLUS_AMD64

		/**
		 * MIR instruction
		 * 
		 * This structure contains the definition of the instruction format.
		 * Generally instructions take 1 or 2 operands.  MIR_st is the
		 * the ONLY instruction that takes 3 operands.    The form
		 * of the operands (or type) is instruction dependent.  Each instruction 
		 * expects the operands to be in a specific form.  For example, MIR_add
		 * expects 2 operands which are pointers to other instructions.  Debug 
		 * builds will check operand types for conformance, but Release builds 
		 * will have no type checking; consider yourself warned!
		 * 
		 * During MIR generation we keep track of various details about the use
		 * of the instruction.  Such as whether its result is needed across a 
		 * function call and which instruction last uses the result of each
		 * instruction; lastUse.  The lastUse field of every instruction 
		 * is updated as instructions are generated.  In the case of MIR_st
		 * no result is generated and thus lastUse can be overlayed with oprnd3.
		 * 
		 * During machine dependent code generation oprnd2 is clobbered and
		 * the current register / stack position is maintained within this field.
		 */

		class OP
		{
		public:

			/** opcode */
			MirOpcode code:8;

			/** register assigned to this expr, or Unknown */
			Register reg:7;	

			/** flag indicating if result is used after call, so we prefer callee-saved regs */
			uint32 liveAcrossCall:1;

			/** link to a previous expr with the same opcode, for finding CSE's */
			uint32 prevcse:16;

			union
			{
				OP* oprnd1;			// 1st operand of instruction
				OP* base;			// base ptr for load/store/lea/jmpi
				uint32 argc;		// arg count, for calls
				sintptr pos;		// position of spilled value, or position of label
			};

			union
			{
				OP* oprnd2;			// 2nd operand of instruction	
				sintptr addr;		// call addr or pc addr
				int32 size;			// alloca size, table size
				sintptr imm;		// imm value if const
				sintptr disp;		// immediate signed displacement for load/store/lea/jmpi
				OP* target;			// branch target
				OP* join;			// def joined to
				uint32 *nextPatch;
			};

			union
			{
				OP* value;			// value to store in MIR_st
				OP* lastUse;		// OP that uses this expr furthest in the future (end of live range)
				OP* args[1];		// arg array, for call ops.  arg[1] is the
									// first arg, which will run over into the 
									// space of subsequent ops.
			};

			int isDouble() const {
				return code & MIR_float;
			}

			int spillSize() const {
				#ifdef AVMPLUS_AMD64
				return code == MIR_alloc ? ((size<8)?8:(MirOpcode)size) : (MirOpcode)8;
				#else
				return code == MIR_alloc ? size : (code & MIR_float) ? 8 : 4;
				#endif
			}

			int isDirty() const {
				return code != MIR_imm && pos == InvalidPos;
			}

		};

		class MirLabel
		{
		public:
			OP* bb;
			OP** nextPatchIns;
			MirLabel() {
				bb = 0;
				nextPatchIns = 0;
			}
		};

		class MdLabel
		{
		public:
			sintptr value;
			uint32* nextPatch;	/* linked list of patch locations, where next address is an offset in the instruction */
			MdLabel() {
				value = 0;
				nextPatch = 0;
			}
		};

		#ifdef AVMPLUS_VERBOSE
		void buildFlowGraph();
		void formatOpcode(PrintWriter& buffer, OP* op, PoolObject* pool, MMgc::GCHashtable* names);
	    void formatInsOperand(PrintWriter& buffer, OP* oprnd);
	    void formatOperand(PrintWriter& buffer, OP* oprnd);
		static MMgc::GCHashtable* initMethodNames(AvmCore* core);
		#endif //AVMPLUS_VERBOSE

		void emitMD();

		OP* exAtom;

	#ifdef VTUNE
       bool hasDebugInfo;
       JITCodeInfo* jitInfo;
	#endif /* VTUNE */

	private:
		#define COREADDR(f) coreAddr((int (AvmCore::*)())(&f))
		#define GCADDR(f) gcAddr((int (MMgc::GC::*)())(&f))
		#define ENVADDR(f) envAddr((int (MethodEnv::*)())(&f))
		#define TOPLEVELADDR(f) toplevelAddr((int (Toplevel::*)())(&f))
		#define SCRIPTADDR(f) scriptAddr((int (ScriptObject::*)())(&f))
		#define ARRAYADDR(f) arrayAddr((int (ArrayObject::*)())(&f))
		#define VECTORINTADDR(f) vectorIntAddr((int (IntVectorObject::*)())(&f))
		#define VECTORUINTADDR(f) vectorUIntAddr((int (UIntVectorObject::*)())(&f))
		#define VECTORDOUBLEADDR(f) vectorDoubleAddr((int (DoubleVectorObject::*)())(&f))
		#define VECTOROBJADDR(f) vectorObjAddr((int (ObjectVectorObject::*)())(&f))
		#define EFADDR(f)   efAddr((int (ExceptionFrame::*)())(&f))
		#define DEBUGGERADDR(f)   debuggerAddr((int (Debugger::*)())(&f))
		#define CLASSCLOSUREADDR(f)   classClosureAddr((int (ClassClosure::*)())(&f))

		static sintptr coreAddr( int (AvmCore::*f)() );
		static sintptr gcAddr( int (MMgc::GC::*f)() );
		static sintptr envAddr( int (MethodEnv::*f)() );
		static sintptr toplevelAddr( int (Toplevel::*f)() );
	#ifdef DEBUGGER
		static sintptr debuggerAddr( int (Debugger::*f)() );
	#endif
		static sintptr efAddr( int (ExceptionFrame::*f)() );
		static sintptr scriptAddr( int (ScriptObject::*f)() );
		static sintptr arrayAddr( int (ArrayObject::*f)() );
		static sintptr classClosureAddr( int (ClassClosure::*f)() );
		static sintptr vectorIntAddr(int (IntVectorObject::*f)() );
		static sintptr vectorUIntAddr(int (UIntVectorObject::*f)() );
		static sintptr vectorDoubleAddr(int (DoubleVectorObject::*f)() );
		static sintptr vectorObjAddr(int (ObjectVectorObject::*f)() );

		friend class Verifier;

		// MIR instruction buffer
		OP* ip;
		OP* ipStart;
		OP* ipEnd;
		uintptr mirBuffSize;
		int expansionFactor;
		GrowableBuffer* mirBuffer;

		byte*	 code;
		uintptr*  casePtr;
		int		 case_count;

		#ifdef AVMPLUS_SPARC
		typedef uint32 MDInstruction;
		#define PREV_MD_INS(m) (m-1)
		#endif

		#ifdef AVMPLUS_PPC
		typedef uint32 MDInstruction;
		#define PREV_MD_INS(m) (m-1)
		#endif

		#ifdef AVMPLUS_ARM
		#define PREV_MD_INS(m) (m-1)
		#endif
		
		#ifdef AVMPLUS_IA32
		typedef byte MDInstruction;
		#define PREV_MD_INS(m) (m-4)
		// for intel and our purposes previous instruction is 4 bytes prior to m; used for patching 32bit target addresses
		#endif

		#ifdef AVMPLUS_AMD64
		typedef byte MDInstruction;
		#define PREV_MD_INS(m) (m-4)
		#define PREV_MD_INS_64(m) (m-8)
		// for intel and our purposes previous instruction is 4 bytes prior to m; used for patching 32bit target addresses
		#endif
		
        #if !defined(AVMPLUS_ARM)
		// machine specific instruction buffer
		MDInstruction* mip;
		MDInstruction* mipStart;
		#endif
	
		MDInstruction* mipEnd;

		uint32 arg_index;

		void	mirLabel(MirLabel& l, OP* bb); 
		void	mirPatchPtr(OP** targetp, sintptr pc);		/* patch the location 'where' with the 32b value of the label */
		void	mirPatchPtr(OP** targetp, MirLabel& l);
		void	mirPatch(OP* i, sintptr pc);

		void	mdLabel(MdLabel* l, void* v);			/* machine specific version of position label (will trigger patching) */
		void	mdLabel(OP* l, void* v);			/* machine specific version of position label (will trigger patching) */
		void	mdPatch(void* where, MdLabel* l);		/* machine specific version for patch the location 'where' with the 32b value of the label */
		void	mdPatch(void* where, OP* l);		/* machine specific version for patch the location 'where' with the 32b value of the label */
		void	mdApplyPatch(uint32* where, sintptr labelvalue); /* patch label->value into where */

		void    mdPatchPreviousOp(OP* ins) {
			mdPatch( PREV_MD_INS(mip), ins );
		}

		void    mdPatchPrevious(MdLabel* l) {
			mdPatch( PREV_MD_INS(mip), l );
		}

		class StackCheck
		{
		public:
			uintptr *patchStackSize;
			MdLabel  resumeLabel;
			MdLabel  overflowLabel;

			StackCheck() {
				patchStackSize = NULL;
			}
		};

		StackCheck stackCheck;
		
		MdLabel  patch_end;
		
		MirLabel npe_label;
		MirLabel interrupt_label;
		bool interruptable;
		
		#if defined (AVMPLUS_IA32) || defined(AVMPLUS_AMD64)
		// stack probe for win32
		void emitAllocaProbe(int growthAmt, MdLabel* returnTo);
		#endif /* AVMPLUS_IA32 or AVMPLUS_AMD64 */

		#ifdef AVMPLUS_ARM
		uint32 *patch_stmfd;
		uint32 *patch_frame_size;

		/**
		 * Compute the size of the ARM callee area.  Must be done
		 * after the generation of MIR opcodes.
		 */
		int calleeAreaSize() const { return 8*maxArgCount; }

		int countBits(uint32);
        #endif

		#ifdef AVMPLUS_SPARC
		OP *beginCatch_start;
		OP *beginCatch_end;
		uint32 *patch_frame_size;
		/**
		 * Compute the size of the PPC callee area.  Must be done
		 * after the generation of MIR opcodes.
		 */
		int calleeAreaSize() const { return 8*maxArgCount; }

		// This helper exists on SPARC only to minimize the code size
		// of the generated code for stack overflow checks
		static void stackOverflow(MethodEnv *env);
		#endif
		
		#ifdef AVMPLUS_PPC
		uint32 *patch_stmw;
		uint32 *patch_stwu;

		/**
		 * Compute the size of the PPC callee area.  Must be done
		 * after the generation of MIR opcodes.
		 */
		int calleeAreaSize() const { return 8*maxArgCount; }
		
		// This helper exists on PPC only to minimize the code size
		// of the generated code for stack overflow checks
		static void stackOverflow(MethodEnv *env);
	    #endif
		
		#ifdef AVMPLUS_AMD64
		int calleeAreaSize() const { return ((maxArgCount>4) ? (8*maxArgCount) : 32); }
		#endif

		uint32  maxArgCount;        // most number of arguments used in a call

#if (defined(_DEBUG)) && HAVE_MIR_SMOPS
		// raw memory stats
		static int		totalRangeChecks;
		static int		implicitMaddrDisps;
		static int		singleCmpRangeChecks;
		static int		doubleCmpRangeChecks;
#endif
		// pointer to list of argument definitions
		OP* methodArgs; 
		OP* calleeVars;
		Register framep;

		// stack space reserved by MIR_alloca instruction in prologue for locals, exception frame and Multiname
		OP*  _save_eip;
		OP*  _ef;
		OP*  dxns;
		OP*  dxnsAddrSave; // methods that set dxns need to save/restore

		#if (defined DEBUGGER || defined FEATURE_SAMPLER)
		OP*  _callStackNode;
		#endif
		#ifdef DEBUGGER
		OP*  localPtrs;		// array of local_count + max_scope (holds locals and scopes)
		OP*  localTraits;	// array of local_count (holds snapshot of Traits* per local)
		#endif

		// track last function call issued
		OP* lastFunctionCall;

		// track last pc value we generated a store for
		sintptr lastPcSave;

#if HAVE_MIR_SMOPS
		// path address for last range check failure
		// (jmp's exsiting address will be a pointer
		// to the previous patch... saves a few bytes
		// over a general label)
		uint32 *lastMOPRangeCheckJmp;

		// makes the calling convention a little easier
		static void mopRangeCheckFailedShim(const MethodEnv *env)
			{ env->mopRangeCheckFailed(); }

		// implicit disp used by maddr op to optimize range check...
		// this value is applied to the expression being range checked
		// so, if this returns 4 for a given mir_maddr(x), the result of
		// the mir_maddr will be (x - 4) such that 4 must be added to
		// the displacement used by any load or store using this
		// mir_maddr as the address
		int32 maddrImplicitDisp(OP *op);
		// try to opimize an MIR_maddr for a memory op with the given size
		// for a = (x + 12), will return maddr(x, [-12, -8)) (assuming 32 bit op)
		// and set *disp to 12
		// asm pseudo code:

		// ** materialize "x" in eax
		// ** range check eax against [-12, -8)
		// ** mov ebx, [eax+12+globalMemBase] ; add folded into here

		// so the load/store can just add 12 to its disp and skip the extra math
		// if this optimization failed it would be more like:

		// ** materialize "x" in eax
		// ** add eax, 12 ; add actually happens
		// ** range check eax against [0, 4)
		// ** mov ebx, [eax+globalMemBase]

		// returns an OP and fills in *disp on success
		OP *maddrOpt(OP *a, int32 size, int32 *disp);
#endif
		// cse table which prevents duplicate instructions in the same bb
		OP* cseTable[MIR_last];
		OP* firstCse;

#ifdef DEBUGGER
		void extendDefLifetime(OP* current);
#endif

		void saveState();

		OP* defIns(OP* v);
		OP* useIns(OP* def, sintptr i);

		OP* undefConst;

		// frame state helpers
		OP*		localGet(uintptr i);
		void	localSet(uintptr i, OP* o);
		OP*		loadAtomRep(uintptr i);

		OP*	  InsAt(int nbr)  { return ipStart+nbr; }
		int	  InsNbr(OP* ins)	 { AvmAssert(ins >= ipStart); return ((int)(ins-ipStart)); }
		OP*   InsConst(uintptr value) { return Ins(MIR_imm, value); }
		OP*   InsAlloc(size_t s) { return Ins(MIR_alloc, (int32)s); }
		void  InsDealloc(OP* alloc);
		OP*   ldargIns(ArgNumber arg) { return &methodArgs[arg]; }

		OP*   Ins(MirOpcode code, uintptr v=0);
		OP*   Ins(MirOpcode code, OP* a1, uintptr a2);
		OP*   Ins(MirOpcode code, OP* a1, OP* a2=0);
		OP*	  defineArgInsPos(int spOffset);
		OP*	  defineArgInsReg(Register r);
		OP*   binaryIns(MirOpcode code, OP* a1, OP* a2);
		
		OP*   loadIns(MirOpcode _code, sintptr _disp, OP* _base);

		OP*   cmpOptimization (int lhs, int rhs);

		OP*   i2dIns(OP* v);
		OP*   u2dIns(OP* v);
		OP*   fcmpIns(OP* a1, OP* a2);
		OP*   binaryFcmpIns(OP* a1, OP* a2);

		OP*   cmpLt(int lhs, int rhs);
		OP*   cmpLe(int lhs, int rhs);
		OP*	  cmpEq(sintptr funcaddr, int lhs, int rhs);

		void  storeIns(MirOpcode _code, OP* v, uintptr disp, OP* base);
		void  storeIns(OP* v, uintptr disp, OP* base, bool force32=false);

		OP*   leaIns(sintptr disp, OP* base);
		OP*   callIns(sintptr addr, uint32 argCount, MirOpcode code);
		OP*   callIndirect(MirOpcode code, OP* target, uint32 argCount, ...);
		OP*   callIns(MirOpcode code, sintptr addr, uint32 argCount, ...);
		OP*   promoteNumberIns(Traits* t, int i);

		OP*   loadVTable(int base_index);
		OP*   loadToplevel(OP* env);

		// simple cse within BBs
		OP*   cseMatch(MirOpcode code, OP* a1, OP* a2=0);

		// dead code search
		void markDead(OP* ins);
		bool usedInState(OP* ins);

		void argIns(OP* a);

		OP*  storeAtomArgs(int count, int startAt);
		OP*  storeAtomArgs(OP* receiver, int count, int startAt);

		void updateUse(OP* currentIns, OP* op, Register hint=Unknown);

		void extendLastUse(OP* use, sintptr targetpc);
		void extendLastUse(OP* ins, OP* use, OP* target);

		OP*  atomToNativeRep(Traits* t, OP* atom);
		OP*  atomToNativeRep(int i, OP* atom);
		bool isPointer(int i);
		bool isDouble(int i);
		OP*  ptrToNativeRep(Traits*, OP* ptr);

		OP*  initMultiname(Multiname* multiname, int& csp, bool isDelete = false);

#ifdef DEBUGGER
		void emitSampleCheck();
#endif

		//
		// -- MD Specific stuff
		//
		void generate();
		void generatePrologue();
		void generateEpilogue();
		void bindMethod(AbstractFunction* f);
#ifdef AVMPLUS_JIT_READONLY
		void makeCodeExecutable();
#endif /* AVMPLUS_JIT_READONLY */

		bool	ensureMDBufferCapacity(PoolObject* pool, size_t s);  // only if buffer guard is not used
		byte*	getMDBuffer(PoolObject* pool);	// 
		size_t	estimateMDBufferReservation(PoolObject* pool, const int expansionFactor); 

		/**
		 * Information about the activation record for the method is built up 
		 * as we generate machine code.  As part of the prologue, we issue
		 * a stack adjustment instruction and then later patch the adjustment
		 * value.  Temporary values can be placed into the AR as method calls
		 * are issued.   Also MIR_alloca instructions will consume space.
		 */
		class AR
		{
		public:
			AR(MMgc::GC *gc) : temps(gc) {}
			List<OP*>		temps;				/* list of active temps */
			int				size;				/* current # of bytes consumed by the temps */
			int				highwatermark;		/* max size of temps */
			MDInstruction*	adjustmentIns;		/* AR sizing instruction to patch */
		};

		AR activation;

		static const int InvalidPos = -1;  /* invalid spill position  */

		void reserveStackSpace(OP* ins, bool bAlign=false);

		#ifdef AVMPLUS_VERBOSE
		void displayStackTable();
		#endif //AVMPLUS_VERBOSE

    	#ifdef AVMPLUS_PPC
	    static const int kLinkageAreaSize = 24;
    	#endif

    	#ifdef AVMPLUS_SPARC
	    static const int kLinkageAreaSize = 68;
    	#endif

		// converts an instructions 'pos' field to a stack pointer relative displacement
		int stackPos(OP* ins);

		// structures for register allocator
		class RegInfo 
		{
		public:
			uint32 free;
			uint32 calleeSaved; // 1 = callee-saved, 0=caller-saved
#ifdef AVMPLUS_PPC
			unsigned LowerBound;
#endif
#ifdef AVMPLUS_ARM
			unsigned nonVolatileMask;
#endif
			OP* active[MAX_REGISTERS];  // active[r] = OP that defines r

			OP* findLastActive(int set);
			void flushCallerActives(uint32 flushmask);

			RegInfo() 
			{
				clear();
			}

			void clear()
			{
				free = 0;
				memset(active, 0, MAX_REGISTERS * sizeof(OP*));
			}

			uint32 isFree(Register r) 
			{
				return free & rmask(r);
			}

			/**
			* Add a register to the free list for the allocator.
			*
			*   IMPORTANT
			* 
			*  This is a necessary call when freeing a register.
			*/
			void addFree(Register r)
			{
				AvmAssert(!isFree(r));
				free |= rmask(r);
			}

			void removeFree(Register r)
			{
				AvmAssert(isFree(r));
				free &= ~rmask(r);
			}

			// if an instruction is no longer in use retire it
			void expire(OP* ins, OP* currentIns)
			{
				if (ins->reg != Unknown && ins->lastUse <= currentIns)
					retire(ins);
			}

			void expireAll(OP* currentIns)
			{
				for(int i=0; i<MAX_REGISTERS; i++)
				{
					OP* ins = active[i];
					if (ins && ins->lastUse <= currentIns)
						retire(ins);
				}
			}

			// instruction gives up the register it is currently bound to, adding it back to the free list,
			// removing it from the active list
			void retire(OP* ins)
			{
				AvmAssert(active[ins->reg] == ins);
				retire(ins->reg);
				ins->reg = Unknown;
			}

			void retire(Register r)
			{
				#ifdef _MSC_VER
				__assume(r>0);
				#endif //#ifdef _MSC_VER
				AvmAssert(r != Unknown);
				AvmAssert(active[r] != NULL);
				active[r] = NULL;
				free |= rmask(r);
			}
			/**
			 * add the register provided in v->reg to the active list
			 * IMPORTANT: this is a necessary call when allocating a register
			 */
			void addActive(OP* v)
			{
				//addActiveCount++;
				AvmAssert(active[v->reg] == NULL);
				active[v->reg] = v;
			}

			/**
			* Remove a register from the active list without
			* spilling its contents.
			* 
			* The caller MUST eventually call addFree()
			* or regs.addActive() in order to add the register
			* back to the freelist or back onto the active list.
			* 
			* It is the responsibility of the caller to update 
			* the reg field of the instruction.
			* 
			* @param r - register to remove from free list
			* @param forAlloctor - DO NOT USE, for allocator only
			* 
			* @return the instruction for which the register
			* was retaining a value.
			*/
			void removeActive(Register r)
			{
				#ifdef _MSC_VER
				__assume(r>0);
				#endif //#ifdef _MSC_VER
				//registerReleaseCount++;
				AvmAssert(r != Unknown);
				AvmAssert(active[r] != NULL);

				// remove the given register from the active list
				active[r] = NULL;
			}

			#ifdef _DEBUG
			int count;
			int countFree()
			{
				int _count = 0;
				for(int i=0;i<MAX_REGISTERS; i++)
					_count += ( (free & rmask(i)) == 0) ? 0 : 1;
				return _count;
			}
			int countActive()
			{
				int _count = 0;
				for(int i=0;i<MAX_REGISTERS; i++)
					_count += (active[i] == 0) ? 0 : 1;
				return _count;
			}

			void checkCount()
			{
				AvmAssert(count == (countActive() + countFree()));
			}
			void checkActives(OP* current);
			#endif //_DEBUG

		};

		// all registers that we use
		RegInfo gpregs;
		RegInfo fpregs;

		#ifdef AVMPLUS_VERBOSE
		void showRegisterStats(RegInfo& regs);
		#endif //AVMPLUS_VERBOSE

		// register active/freelist routines
		Register registerAllocSpecific(RegInfo& regs, Register r);
		Register registerAllocAny(RegInfo& regs, OP* ins);
		Register registerAllocFromSet(RegInfo& regs, int set);

#if HAVE_MIR_SMOPS
#if defined(AVMPLUS_IA32) || defined(AVMPLUS_AMD64)		
		// find (but don't allocate) an appropriate 8 bit-able
		// register to use with the value
		// (eax | ebx | ecx | edx)
		Register registerFor8Bit(RegInfo &regs, OP* value);
#endif
#endif
		Register registerAlloc(RegInfo& regs, OP* ins, Register r)
		{
			return r == Unknown 
				? registerAllocAny(regs, ins)
				: registerAllocSpecific(regs, r);
		}

		uint32 spillCallerRegisters(OP* ins, RegInfo& regs, uint32 live);
		void spillTmps(OP* target);

		Register InsPrepResult(RegInfo& regs, OP* ins, int exclude=0);

		void setResultReg(RegInfo& regs, OP* ins, Register reg) 
		{
			ins->reg = reg;
			ins->pos = InvalidPos;
			regs.addActive(ins);
		}

		// MD instruction generators for spill/remat
		void spill(OP* ins);
		void rematerialize(OP* ins);
		void copyToStack(OP* ins, Register r);

		// spill and argument code for MD calls
		int prepCallArgsOntoStack(OP* ip, OP* postCall);

		void InsRegisterPrepA(OP* insRes, RegInfo& regsA, OP* insA, Register& reqdA);
		void InsRegisterPrepAB(OP* insRes, RegInfo& regsA, OP* insA, Register& reqdA, RegInfo& regsB, OP* insB, Register& reqdB);

		// prepare the registers in the best possible fashion for issuing the given instruction
		inline void InsPrep_A_IN_REQ_B_IN_WRONG(RegInfo& regs, OP* insA, Register& reqdA, OP* insB, Register& reqdB);
		inline void InsPrep_A_IN_REQ_B_OUT_REQ(RegInfo& regs, OP* insA, Register& reqdA, OP* insB, Register& reqdB);
		inline void InsPrep_A_IN_REQ_B_OUT_ANY(RegInfo& regs, OP* insA, Register& reqdA, OP* insB, Register& reqdB);
#if 0
		inline void InsPrep_A_IN_WRONG_B_IN_WRONG(RegInfo& regs, OP* insA, Register& reqdA, OP* insB, Register& reqdB);
#endif
		inline void InsPrep_A_IN_WRONG_B_IN_ANY(RegInfo& regs, OP* insA, Register& reqdA, OP* insB, Register& reqdB);
		inline void InsPrep_A_IN_WRONG_B_OUT(RegInfo& regs, OP* insA, Register& reqdA, OP* insB, Register& reqdB);
		inline void InsPrep_A_IN_ANY_B_OUT(RegInfo& regs, OP* insA, Register& reqdA, OP* insB, Register& reqdB);
		inline void InsPrep_A_OUT_B_OUT(RegInfo& regs, OP* insA, Register& reqdA, OP* insB, Register& reqdB);

		void moveR2R(OP* ins, Register src, Register dst);

		// Returns true if immediate folding can be used
		bool canImmFold(OP *ins, OP *imm) const;

		#ifdef AVMPLUS_SPARC

		void CALL(int offset);
		void Format_2_1(Register rd, int op2, int imm22);
		void Format_2_2(int a, int cond, int op2, int disp22);
		void Format_2_3(int a, int cond, int op2, int cc1, int cc0, int p, int disp19);
		void Format_2_4(int a, int rcond, int op2, int d16hi, int p, Register rs1, int d16lo);
		void Format_3(int op1, Register rd, int op3, int bits19);
		void Format_3_1(int op1, Register rd, int op3, Register rs1, int bit8, Register rs2);
		void Format_3_1I(int op1, Register rd, int op3, Register rs1, int simm13);
		void Format_3_2(int op1, Register rd, int op3, Register rs1, int rcond, Register rs2);
		void Format_3_2I(int op1, Register rd, int op3, Register rs1, int rcond, int simm10);
		void Format_3_3(int op1, Register rd, int op3, Register rs1, int cmask, int mmask);
		void Format_3_4(int op1, Register rd, int op3, int bits19);
		void Format_3_5(int op1, Register rd, int op3, Register rs1, int x, Register rs2);
		void Format_3_6(int op1, Register rd, int op3, Register rs1, int shcnt32);
		void Format_3_7(int op1, Register rd, int op3, Register rs1, int shcnt64);
		void Format_3_8(int op1, Register rd, int op3, Register rs1, int bits9, Register rs2);
		void Format_3_9(int op1, int cc1, int cc0, int op3, Register rs1, int bits9, Register rs2);
		void Format_4_1(Register rd, int op3, Register rs1, int cc1, int cc0, Register rs2);
		void Format_4_1I(Register rd, int op3, Register rs1, int cc1, int cc0, int simm11);
		void Format_4_2(Register rd, int op3, int cc2, int cond, int cc1, int cc0, Register rs2);
		void Format_4_2I(Register rd, int op3, int cc2, int cond, int cc1, int cc0, int simm11);
		void Format_4_3(Register rd, int op3, Register rs1, int cc1, int cc0, int swap_trap);
		void Format_4_4(Register rd, int op3, Register rs1, int rcond, int opf_low, Register rs2);
		void Format_4_5(Register rd, int op3, int cond, int opf_cc, int opf_low, Register rs2);

		void ADD(Register rs1, Register rs2, Register rd);
		void ADDI(Register rs1, int simm13, Register rd);
		void AND(Register rs1, Register rs2, Register rd);
		void ANDI(Register rs1, int simm13, Register rd);
		void BA(int a, int dsp22);
		void BE(int a, int dsp22);
		void BG(int a, int dsp22);
		void BGU(int a, int dsp22);
		void BGE(int a, int dsp22);
		void BGEU(int a, int dsp22);
		void BL(int a, int dsp22);
		void BLU(int a, int dsp22);
		void BLE(int a, int dsp22);
		void BLEU(int a, int dsp22);
		void BNE(int a, int dsp22);
		void FABSS(Register rs2, Register rd);
		void FADDD(Register rs1, Register rs2, Register rd);
		void FBE(int a, int dsp22);
		void FBNE(int a, int dsp22);
		void FBUE(int a, int dsp22);
		void FBG(int a, int dsp22);
		void FBUG(int a, int dsp22);
		void FBGE(int a, int dsp22);
		void FBUGE(int a, int dsp22);
		void FBL(int a, int dsp22);
		void FBLE(int a, int dsp22);
		void FCMPD(Register rs1, Register rs2);
		void FSUBD(Register rs1, Register rs2, Register rd);
		void FMULD(Register rs1, Register rs2, Register rd);
		void FDIVD(Register rs1, Register rs2, Register rd);
		void FMOVD(Register rs2, Register rd);
		void FNEGD(Register rs2, Register rd);
		void FITOD(Register rs2, Register rd);
		void JMPL(Register rs1, Register rs2, Register rd);
		void JMPLI(Register rs1, int simm13, Register rd);
		void LDF(Register rs1, Register rs2, Register rd);
		void LDFI(Register rs1, int simm13, Register rd);
		void LDSW(Register rs1, Register rs2, Register rd);
		void LDSWI(Register rs1, int simm13, Register rd);
		void MULX(Register rs1, Register rs2, Register rd);
		void MULXI(Register rs1, int simm13, Register rd);
		void NOP();
		void OR(Register rs1, Register rs2, Register rd);
		void ORI(Register rs1, int simm13, Register rd);
		void RD(Register rs1, Register rd);
		void RESTORE(Register rs1, Register rs2, Register rd);
		void SAVEI(Register rs1, int simm13, Register rd);
		// Acturally it is sethi(%hi(value), rd). I don't if it is good to do so.
		void SETHI(int imm22, Register rd);
		void SLL(Register rs1, Register rs2, Register rd);
		void SLLI(Register rs1, int shcnt32, Register rd);
		void SRA(Register rs1, Register rs2, Register rd);
		void SRAI(Register rs1, int shcnt32, Register rd);
		void SRL(Register rs1, Register rs2, Register rd);
		void SRLI(Register rs1, int shcnt32, Register rd);
		void STF(Register rd, Register rs1, Register rs2);
		void STFI(Register rd, int simm13, Register rs1);
		void STW(Register rd, Register rs2, Register rs1);
		void STWI(Register rd, int simm13, Register rs1);
		void SUBCC(Register rs1, Register rs2, Register rd);
		void SUBCCI(Register rs1, int simm13, Register rd);
		void SUB(Register rs1, Register rs2, Register rd);
		void SUBI(Register rs1, int simm13, Register rd);
		void XOR(Register rs1, Register rs2, Register rd);
		void XORI(Register rs1, int simm13, Register rd);

		// Returns true if imm below 13-bit unsigned immediate)
		inline bool isIMM13(int imm) const
		{
			return imm <= 4095 && imm >= -4096;
		}


		void SET32(int imm32, Register rd)
		{
			if(isIMM13(imm32)) {
				ORI(G0, imm32, rd);
			}
			else {
				SETHI(imm32, rd);
				ORI(rd, imm32 & 0x3FF, rd);
			}
		}

		void STDF32(Register rd, int imm32, Register rs1)
		{
			if(isIMM13(imm32+4)) {
				STFI(rd, imm32, rs1);
				STFI(rd+1, imm32+4, rs1);
			}
			else {
				SET32(imm32, L0);
				STF(rd, L0, rs1);
				SET32(imm32+4, L0);
				STW(rd+1, L0, rs1);
			}
		}

		void LDDF32(Register rs1, int imm32, Register rd)
		{
			if(isIMM13(imm32+4)) {
				LDFI(rs1, imm32, rd);
				LDFI(rs1, imm32+4, rd+1);
			}
			else {
				SET32(imm32, L0);
				LDF(rs1, L0, rd);
				SET32(imm32+4, L0);
				LDF(rs1, L0, rd+1);
			}
		}

		void STW32(Register rd, int imm32, Register rs1)
		{
			if(isIMM13(imm32)) {
				STWI(rd, imm32, rs1);
			}
			else {
				SET32(imm32, L0);
				STW(rd, L0, rs1);
			}
		}

		void LDSW32(Register rs1, int imm32, Register rd)
		{
			if(isIMM13(imm32)) {
				LDSWI(rs1, imm32, rd);
			}
			else {
				SET32(imm32, L0);
				LDSW(rs1, L0, rd);
			}
		}

		void ADDI32(Register rs1, int imm32, Register rd)
		{
			if(isIMM13(imm32)) {
				ADDI(rs1, imm32, rd);
			}
			else {
				SET32(imm32, L0);
				ADD(rs1, L0, rd);
			}
		}

		void patchRelativeBranch(uint32 *patch_ip, uint32 *target_ip)
			{
				int offset = target_ip-patch_ip;
				*patch_ip &= 0xFFC00000;
				*patch_ip |= (offset & 0x3FFFFF);
			}

		#endif // AVMPLUS_SPARC


		#ifdef AVMPLUS_PPC
		//
		// PowerPC code generation
		//

		void GpBinary(int op, Register dst, Register src1, Register src2);
		void ADD(Register dst, Register src1, Register src2)	{ GpBinary(0x214, dst, src1, src2); }
		void MULLW(Register dst, Register src1, Register src2)	{ GpBinary(0x1D6, dst, src1, src2); }
		void AND(Register dst, Register src1, Register src2)	{ GpBinary(0x038, src1, dst, src2); }
		void SUB(Register dst, Register src1, Register src2)	{ GpBinary(0x050, dst, src2, src1); } // z = x - y is encoded as subf z,y,x 
		void SLW(Register dst, Register src, Register shift)	{ GpBinary(0x030, src, dst, shift); }

		void FpUnary(int op, Register dst, Register src);
		void FMR(Register dst, Register src)	{ FpUnary(0x90, dst, src); }
		void FNEG(Register dst, Register src)	{ FpUnary(0x50, dst, src); }

		void MR(Register dst, Register src, bool dot=false);
		void MR_dot(Register dst, Register src) { MR(dst,src,true); }

		void NEG(Register dst, Register src);
		void LWZ(Register dst, int disp, Register base);
		void LWZX(Register dst, Register rA, Register rB);
		void LFD(Register dst, int disp, Register base);
		void LFDX(Register dst, Register rA, Register rB);
		void STFD(Register src, int disp, Register dst);
		void STFDX(Register src, Register rA, Register rB);
		void LMW(Register dst, int disp, Register base);
		void STW(Register src, int disp, Register base);
		void STWX(Register src, Register rA, Register rB);
		void RLWINM(Register dst, Register src, int shift, int begin, int end);
		void SLWI(Register dst, Register src, int shift);
		void SRW(Register dst, Register src, Register shift);
		void SRWI(Register dst, Register src, int shift);
		void SRAW(Register dst, Register src, Register shift);
		void SRAWI(Register dst, Register src, int shift);
		void ADDI(Register dst, Register src, int imm16);
		void ADDIS(Register dst, Register src, int imm16);
		void SI(Register dst, Register src, int imm16);
		void CMP(ConditionRegister CR, Register regA, Register regB);
		void CMPI(ConditionRegister CR, Register src, int imm16);
		void LI(Register reg, int imm16);
		void LIS(Register reg, int imm16);
		void ORI(Register dst, Register src, int imm16);
		void ORIS(Register dst, Register src, int imm16);
		void ANDI_dot(Register dst, Register src, int imm16);
		void CMPL(ConditionRegister CR, Register regA, Register regB);
		void CMPLI(ConditionRegister CR, Register src, int imm16);
		void FCMPU(ConditionRegister CR, Register regA, Register regB);
		void MFCR(Register dst);
		void CROR(int crbD, int crbA, int crbB);
		void CRNOT(int crbD, int crbA);
		void XORI(Register dst, Register src, int imm16);
		void XORIS(Register dst, Register src, int imm16);
		void XOR(Register dst, Register src1, Register src2);
		void FADD(Register dst, Register src1, Register src2);
		void FSUB(Register dst, Register src1, Register src2);
		void FMUL(Register dst, Register src1, Register src2);
		void FDIV(Register dst, Register src1, Register src2);
		void OR(Register dst, Register src1, Register src2);
		void STMW(Register start, int disp, Register base);
		void STWU(Register dst, int disp, Register base);
		void STWUX(Register rS, Register rA, Register rB);

		void Movspr(int op, Register r, Register spr);
		void MTCTR(Register reg)	{ Movspr(0x7C0003A6, reg, CTR); }
		void MTLR(Register reg)		{ Movspr(0x7C0003A6, reg, LR); }
		void MFLR(Register reg)		{ Movspr(0x7C0002A6, reg, LR); }

		void BR(int op, int addr);
		void B(int offset)	{ BR(0, offset); }
		void BL(int offset) { BR(1, offset); }
		void BA(int addr)	{ BR(2, addr); }
		void BLA(int addr)  { BR(3, addr); }

		void Bcc(int op, ConditionRegister cr, int offset, bool hint=false);
		void BEQ(ConditionRegister cr, int offset, bool hint=false) { Bcc(0x4182, cr, offset, hint); }
		void BNE(ConditionRegister cr, int offset, bool hint=false) { Bcc(0x4082, cr, offset, hint); }
		void BLE(ConditionRegister cr, int offset, bool hint=false) { Bcc(0x4081, cr, offset, hint); }
		void BGT(ConditionRegister cr, int offset, bool hint=false) { Bcc(0x4181, cr, offset, hint); }
		void BLT(ConditionRegister cr, int offset, bool hint=false) { Bcc(0x4180, cr, offset, hint); }
		void BGE(ConditionRegister cr, int offset, bool hint=false) { Bcc(0x4080, cr, offset, hint); }
		void BDNZ(ConditionRegister cr, int offset, bool hint=false){ Bcc(0x4200, cr, offset, hint); }

		void Simple(int op);
		void BLR()		{ Simple(0x4E800020); }
		void BCTR()		{ Simple(0x4E800420); }
		void BCTRL()	{ Simple(0x4E800421); }
		void NOP()		{ Simple(0x60000000); }

		void patchRelativeBranch(uint32 *patch_ip, uint32 *target_ip)
		{
			int offset = (target_ip-patch_ip)*4;
			*patch_ip &= ~0xFFFC;
			*patch_ip |= offset;
		}
		
		// Load and store macros that take 32-bit offsets.
		// R0 will be used for the offset if needed.
		inline bool IsSmallDisplacement(int disp) const
		{
			return (uint32)(disp+0x8000) < 0x10000;
		}
		
		// Returns whether displacement fits in 26-bit
		// branch displacement (B, BL, BLA instructions)
		inline bool IsBranchDisplacement(int disp) const
		{
			return (uint32)(disp+0x2000000) < 0x4000000;
		}

		// Returns true if imm will fit in the SIMM field of
		// a PowerPC instruction (16-bit signed immediate)
		inline bool isSIMM(int imm) const
		{
			return !((imm + 0x8000) & 0xFFFF0000);
		}

		// Returns true if imm will fit in the UIMM field of
		// a PowerPC instruction (16-bit unsigned immediate)
		inline bool isUIMM(int imm) const
		{
			return !(imm & 0xFFFF0000);
		}

		void LWZ32(Register dst, int disp, Register base)
		{
			if (IsSmallDisplacement(disp))
			{
				LWZ(dst, disp, base);
			}
			else
			{
				LI32(R0, disp);
				LWZX(dst, base, R0);
			}
		}
		
		void STW32(Register src, int disp, Register dst)
		{
			if (IsSmallDisplacement(disp))
			{
				STW(src, disp, dst);
			}
			else
			{
				LI32(R0, disp);
				STWX(src, dst, R0);
			}
		}
		
		void LFD32(Register dst, int disp, Register base)
		{
			if (IsSmallDisplacement(disp))
			{
				LFD(dst, disp, base);
			}
			else
			{
				LI32(R0, disp);
				LFDX(dst, base, R0);
			}
		}
		
		void STFD32(Register src, int disp, Register dst)
		{
			if (IsSmallDisplacement(disp))
			{
				STFD(src, disp, dst);
			}
			else
			{
				LI32(R0, disp);
				STFDX(src, dst, R0);
			}
		}

		void ADDI32(Register dst, Register src, int imm32)
		{
			if (IsSmallDisplacement(imm32))
			{
				ADDI(dst, src, imm32);
			}
			else
			{
				LI32(R0, imm32);
				ADD(dst, src, R0);
			}
		}
		
		int HIWORD(int value) { return (value>>16)&0xFFFF; }
		int LOWORD(int value) { return value&0xFFFF; }

		// Macro to emit the right sequence for
		// loading an immediate 32-bit value
		void LI32(Register reg, int imm32)
		{
			if (imm32 & 0xFFFF0000) {
				LIS(reg, HIWORD(imm32));
				ORI(reg, reg, LOWORD(imm32));
			} else {
				if (imm32 & 0x8000) {
					// todo
					LI(reg, 0);
					ORI(reg, reg, imm32);
				} else {
					LI(reg, imm32);
				}
			}
		}
		
		//
		// End PowerPC code generation
		//
        #elif defined(AVMPLUS_IA32) || defined(AVMPLUS_AMD64)		
		//   ---------------------------------------------------
		// 
		//    IA32 specific stuff follows
		//
		//   ---------------------------------------------------

		bool x87Dirty;

		#ifdef AVMPLUS_VERBOSE
		unsigned x87Top:3;
		#endif

		bool is8bit(int i)
		{
			return ((signed char)i) == i;
		}

		void IMM32(int imm32) 
		{
			*(int*)mip = imm32;
			mip += 4;
		}

		void MODRM(Register reg, sintptr disp, Register base, int lshift, Register index);
		void MODRM(Register reg, sintptr disp, Register base);
		void MODRM(Register reg, Register operand);

		void ALU(int op);
		void RET()				{ count_ret(); ALU(0xc3); }
		void LEAVE()			{ count_leave(); ALU(0xc9); }
		void NOP()				{ count_instr(); ALU(0x90); }
		#ifdef AVMPLUS_64BIT
		void PUSH(Register r);
		void POP(Register r);
		#else
		void PUSH(Register r)	{ count_push(); ALU(0x50|r); }
		void POP(Register r)	{ count_pop(); ALU(0x58|r); }
		#endif
		void LAHF()				{ count_alu(); ALU(0x9F); }

		void PUSH(sintptr imm);

		void MOV (Register dest, sintptr imm32);
		void MOV (sintptr disp, Register base, sintptr imm, bool b32=false);
		
		// sse data transfer

		// sse math
		void SSE(int op, Register dest, Register src);
		void ADDSD(Register dest, Register src)		{ count_fpu(); SSE(0xf20f58, dest, src); }
		void SUBSD(Register dest, Register src)		{ count_fpu(); SSE(0xf20f5c, dest, src); }
		void MULSD(Register dest, Register src)		{ count_fpu(); SSE(0xf20f59, dest, src); }
		void DIVSD(Register dest, Register src)		{ count_fpu(); SSE(0xf20f5e, dest, src); }
		void CVTTSD2SI(Register dest, Register src)	{ count_fpu(); SSE(0xf20f2c, dest, src); }
		void CVTSI2SD(Register dest, Register src)	{ count_fpu(); SSE(0xf20f2a, dest, src); }
		void UCOMISD(Register xmm1, Register xmm2)	{ count_fpu(); SSE(0x660f2e, xmm1, xmm2); }
		void MOVAPD(Register dest, Register src)	{ count_mov(); SSE(0x660f28, dest, src); }
		void MOVD (Register xmm1, Register src)		{ count_mov(); SSE(0x660F6E, xmm1, src); }
#if HAVE_MIR_SMOPS
		void CVTPD2PS(Register dest, Register src)	{ count_fpu(); SSE(0x660f5a, dest, src); }
		void CVTPS2PD(Register dest, Register src)	{ count_fpu(); ALU2(0x0f5a, dest, src); }
#endif

		void XORPD(Register dest, uintptr src);
#ifdef AVMPLUS_AMD64
		void XORPD(Register dest, Register src);
#endif

		void SSE(int op, Register r, sintptr disp, Register base);
		void ADDSD(Register r, sintptr disp, Register base)		{ count_fpuld(); SSE(0xf20f58, r, disp, base); }
		void SUBSD(Register r, sintptr disp, Register base)		{ count_fpuld(); SSE(0xf20f5C, r, disp, base); }
		void MULSD(Register r, sintptr disp, Register base)		{ count_fpuld(); SSE(0xf20f59, r, disp, base); }
		void DIVSD(Register r, sintptr disp, Register base)		{ count_fpuld(); SSE(0xf20f5E, r, disp, base); }
#if HAVE_MIR_SMOPS
		void MOVSS(Register r, sintptr disp, Register base)		{ count_ldq(); SSE(0xf30f10, r, disp, base); }
		void MOVSS(sintptr disp, Register base, Register r)		{ count_stq(); SSE(0xf30f11, r, disp, base); }
#endif
		void MOVSD(Register r, sintptr disp, Register base)		{ count_ldq(); SSE(0xf20f10, r, disp, base); }
		void MOVSD(sintptr disp, Register base, Register r)		{ count_stq(); SSE(0xf20f11, r, disp, base); }
#ifdef AVMPLUS_AMD64
		void MOVSD (Register xmm1, Register src)		{ count_mov(); SSE(0xf20f10, xmm1, src); }
#endif
		void CVTSI2SD(Register r, sintptr disp, Register base)	{ count_fpuld(); SSE(0xf20f2a, r, disp, base); }

		void ALU (byte op, Register reg, sintptr imm);
		void ADD(Register reg, sintptr imm) { count_alu(); ALU(0x05, reg, imm); }
#ifdef AVMPLUS_AMD64
		void ADD64(Register reg, sintptr imm) { count_alu(); ALU64(0x05, reg, imm); }
		void ALU64 (byte op, Register reg, sintptr imm);
		void SUB64(Register reg, sintptr imm) { count_alu(); ALU64(0x2d, reg, imm); }
		void SUB64(Register lhs, Register rhs)	{ count_alu(); ALU64(0x2b, lhs, rhs); }
		void OR64 (Register reg, sintptr imm) { count_alu(); ALU64(0x0d, reg, imm); }
		void OR64 (Register lhs, Register rhs)	{ count_alu(); ALU64(0x0b, lhs, rhs); }
		void AND64(Register reg, sintptr imm) { count_alu(); ALU64(0x25, reg, imm); }
		void AND64(Register lhs, Register rhs)	{ count_alu(); ALU64(0x23, lhs, rhs); }
		void CMP64(Register lhs, Register rhs)	{ count_alu(); ALU64(0x3b, lhs, rhs); }
#endif
		void SUB(Register reg, sintptr imm) { count_alu(); ALU(0x2d, reg, imm); }
		void AND(Register reg, sintptr imm) { count_alu(); ALU(0x25, reg, imm); }
		void XOR(Register reg, sintptr imm) { count_alu(); ALU(0x35, reg, imm); }
		void OR (Register reg, sintptr imm) { count_alu(); ALU(0x0d, reg, imm); }
		void CMP(Register reg, sintptr imm) { count_alu(); ALU(0x3d, reg, imm); }
		void IMUL(Register dst, sintptr imm);

		void ALU (int op, Register lhs_dest, Register rhs);
		void OR (Register lhs, Register rhs)	{ count_alu(); ALU(0x0b, lhs, rhs); }
		void AND(Register lhs, Register rhs)	{ count_alu(); ALU(0x23, lhs, rhs); }
		void XOR(Register lhs, Register rhs)	{ count_alu(); ALU(0x33, lhs, rhs); }
		void ADD(Register lhs, Register rhs)	{ count_alu(); ALU(0x03, lhs, rhs); }
		void CMP(Register lhs, Register rhs)	{ count_alu(); ALU(0x3b, lhs, rhs); }
		void SUB(Register lhs, Register rhs)	{ count_alu(); ALU(0x2b, lhs, rhs); }
		void TEST(Register lhs, Register rhs)	{ count_alu(); ALU(0x85, lhs, rhs); }
		void NEG(Register reg)					{ count_alu(); ALU(0xf7, (Register)3, reg); }
		void SHR(Register reg, Register /*amt*/)	{ count_alu(); ALU(0xd3, (Register)5, reg); } // unsigned >> ecx
		void SAR(Register reg, Register /*amt*/)	{ count_alu(); ALU(0xd3, (Register)7, reg); } // signed >> ecx
		void SHL(Register reg, Register /*amt*/)	{ count_alu(); ALU(0xd3, (Register)4, reg); } // unsigned << ecx
		#ifndef AVMPLUS_AMD64
		void XCHG(Register rA, Register rB)		{ count_mov(); ALU(0x87, rA, rB); }
		void MOV (Register dest, Register src)	{ count_mov(); ALU(0x8b, dest, src); }
		#endif

		void ALU2(int op, Register lhs_dest, Register rhs);
		void IMUL(Register lhs, Register rhs) { count_alu(); ALU2(0x0faf, lhs, rhs); }

		void SETB  (Register reg)	{ count_alu(); ALU2(0x0f92, reg, reg); }
		void SETNB (Register reg)	{ count_alu(); ALU2(0x0f93, reg, reg); }
		void SETE  (Register reg)	{ count_alu(); ALU2(0x0f94, reg, reg); }
		void SETNE (Register reg)	{ count_alu(); ALU2(0x0f95, reg, reg); }
		void SETBE (Register reg)	{ count_alu(); ALU2(0x0f96, reg, reg); }
		void SETNBE(Register reg)	{ count_alu(); ALU2(0x0f97, reg, reg); }
		void SETNP (Register reg)	{ count_alu(); ALU2(0x0f9b, reg, reg); }
		void SETP  (Register reg)	{ count_alu(); ALU2(0x0f9a, reg, reg); }
		void SETL  (Register reg)	{ count_alu(); ALU2(0x0f9C, reg, reg); }
		void SETLE (Register reg)	{ count_alu(); ALU2(0x0f9E, reg, reg); }
		void MOVZX_r8 (Register dest, Register src) { count_alu(); ALU2(0x0fb6, dest, src); }
#if HAVE_MIR_SMOPS
		void MOVSX_r8 (Register dest, Register src) { count_alu(); ALU2(0x0fbe, dest, src); }
		void MOVSX_r16 (Register dest, Register src) { count_alu(); ALU2(0x0fbf, dest, src); }
#endif

		void ALU(int op, Register r, sintptr disp, Register base);

		void TEST(sintptr disp, Register base, Register r)	{ count_aluld(); ALU(0x85, r, disp, base); }

#ifdef AVMPLUS_AMD64
		void LEA(Register r, sintptr disp, Register base)	{ count_alu(); ALU64(0x8d, r, disp, base); }
#else
		void LEA(Register r, sintptr disp, Register base)	{ count_alu(); ALU(0x8d, r, disp, base); }
#endif
		void CALL(sintptr disp, Register base)				{ count_calli(); ALU(0xff, (Register)2, disp, base); }
#ifdef AVMPLUS_AMD64
		void JMP(sintptr disp, Register base)				{ count_jmpld(); ALU64(0xff, (Register)4, disp, base); }
#else
		void JMP(sintptr disp, Register base)				{ count_jmpld(); ALU(0xff, (Register)4, disp, base); }
#endif
		void PUSH(sintptr disp, Register base)				{ count_pushld(); ALU(0xff, (Register)6, disp, base); }
		#ifndef AVMPLUS_AMD64
		void MOV (sintptr disp, Register base, Register r)  { count_st(); ALU(0x89, r, disp, base); }
		void MOV (Register r, sintptr disp, Register base)  { count_ld(); ALU(0x8b, r, disp, base); }
		#endif

		#ifdef AVMPLUS_AMD64
		void ALU64 (int op, Register lhs_dest, Register rhs);
		void ALU64(int op, Register r, sintptr disp, Register base);

		void ADD64(Register lhs, Register rhs)	{ ALU64(0x03, lhs, rhs); }

		void CVTSI2SD64(Register dest, Register src); 

		void XCHG(Register rA, Register rB)		{ ALU64(0x87, rA, rB); }
		void MOV (Register dest, Register src)	{ ALU64(0x8b, dest, src); }

		void MOV (sintptr disp, Register base, Register r)  { ALU64(0x89, r, disp, base); }
		void MOV (Register r, sintptr disp, Register base)  { ALU64(0x8b, r, disp, base); }

		void MOV32(Register r, sintptr disp, Register base)		{ ALU(0x8b, r, disp, base); }
		void MOV32(sintptr disp, Register base, Register r)		{ ALU(0x89, r, disp, base); }
		void MOV32(sintptr disp, Register base, sintptr imm)	{ MOV(disp,base,imm,true);}

		void MOVSXD (Register r, sintptr disp, Register base)	{ ALU64(0x63, r, disp, base); }
		void MOVSXD (Register dest, Register src)				{ ALU64(0x63, dest, src); }
		void IMM64(int64 imm64) 
		{
			*(int64*)mip = imm64;
			mip += 8;
		}
		void REX(Register a,  Register b=RAX, bool set64bit=true);
		
		static bool is32bit(sintptr i)
		{
			return ((int32)i) == i;
		}
			
		#endif // AVMPLUS_AMD64

#if HAVE_MIR_SMOPS
		void MOV_8 (sintptr disp, Register base, Register r)  { count_st(); ALU(0x88, r, disp, base); }
		void MOV_16 (sintptr disp, Register base, Register r)  { count_st(); ALU(0x6689, r, disp, base); }
		void MOVSX_8 (Register r, sintptr disp, Register base)  { count_ld(); ALU(0x0fbe, r, disp, base); }
		void MOVSX_16 (Register r, sintptr disp, Register base)  { count_ld(); ALU(0x0fbf, r, disp, base); }
		void MOVZX_8 (Register r, sintptr disp, Register base)  { count_ld(); ALU(0x0fb6, r, disp, base); }
		void MOVZX_16 (Register r, sintptr disp, Register base)  { count_ld(); ALU(0x0fb7, r, disp, base); }
#endif // HAVE_MIR_SMOPS

		void SHIFT(int op, Register reg, int imm8);
		void SAR(Register reg, int imm8) { count_alu(); SHIFT(7, reg, imm8); } // signed >> imm
		void SHR(Register reg, int imm8) { count_alu(); SHIFT(5, reg, imm8); } // unsigned >> imm
		void SHL(Register reg, int imm8) { count_alu(); SHIFT(4, reg, imm8); } // unsigned << imm
		void TEST_AH(uint8 imm8);

		void JCC (byte op, sintptr offset);
		void JB  (sintptr offset) { count_jcc(); JCC(0x02, offset); }	
		void JNB (sintptr offset) { count_jcc(); JCC(0x03, offset); }
		void JE  (sintptr offset) { count_jcc(); JCC(0x04, offset); }
		void JNE (sintptr offset) { count_jcc(); JCC(0x05, offset); }
		void JBE (sintptr offset) { count_jcc(); JCC(0x06, offset); }	
		void JNBE(sintptr offset) { count_jcc(); JCC(0x07, offset); }
		void JP  (sintptr offset) { count_jcc(); JCC(0x0A, offset); }
		void JNP (sintptr offset) { count_jcc(); JCC(0x0B, offset); }
		void JL  (sintptr offset) { count_jcc(); JCC(0x0C, offset); }
		void JNL (sintptr offset) { count_jcc(); JCC(0x0D, offset); }
		void JLE (sintptr offset) { count_jcc(); JCC(0x0E, offset); }
		void JNLE(sintptr offset) { count_jcc(); JCC(0x0F, offset); }
		void JMP (sintptr offset);
		void CALL(sintptr offset);

		void FPU(int op, sintptr disp, Register base);
#if HAVE_MIR_SMOPS
		void FSTD(sintptr disp, Register base)  { count_stq(); FPU(0xd902, disp, base); }
#endif
		void FSTQ(sintptr disp, Register base)  { count_stq(); FPU(0xdd02, disp, base); }
		void FSTPQ(sintptr disp, Register base) { count_stq(); FPU(0xdd03, disp, base); }
		void FCOM(sintptr disp, Register base)	{ count_fpuld(); FPU(0xdc02, disp, base); } 
#if HAVE_MIR_SMOPS
		void FLDD(sintptr disp, Register base)  { count_fpuld(); x87Dirty=true; FPU(0xd900, disp, base); }
#endif
		void FLDQ(sintptr disp, Register base)  { count_ldq(); x87Dirty=true; FPU(0xdd00, disp, base); }
		void FILDQ(sintptr disp, Register base)	{ count_fpuld(); x87Dirty=true; FPU(0xdf05, disp, base); }
		void FILD(sintptr disp, Register base)  { count_fpuld(); x87Dirty=true; FPU(0xdb00, disp, base); }
		void FADDQ(sintptr disp, Register base) { count_fpuld(); FPU(0xdc00, disp, base); }
		void FSUBQ(sintptr disp, Register base) { count_fpuld(); FPU(0xdc04, disp, base); }
		void FMULQ(sintptr disp, Register base) { count_fpuld(); FPU(0xdc01, disp, base); }
		void FDIVQ(sintptr disp, Register base) { count_fpuld(); FPU(0xdc06, disp, base); }

		void FPU(int op, Register r);
		void FFREE(Register r)	{ count_fpu(); FPU(0xddc0, r); }
		void FSTP(Register r)	{ count_fpu(); FPU(0xddd8, r); }
		void FADDQ(Register r)	{ count_fpu(); FPU(0xd8c0, r); }
		void FSUBQ(Register r)	{ count_fpu(); FPU(0xd8e0, r); }
		void FMULQ(Register r)	{ count_fpu(); FPU(0xd8c8, r); }
		void FDIVQ(Register r)	{ count_fpu(); FPU(0xd8f0, r); }

		void FPU(int op);
		void FUCOMP()		{ count_fpu(); FPU(0xdde9); }
		void FCHS()			{ count_fpu(); FPU(0xd9e0); }
		void FNSTSW_AX()	{ count_fpu(); FPU(0xdfe0); }
		void EMMS()			{ count_fpu(); FPU(0x0f77); x87Dirty=false;  }
		#endif // IA32 or AMD64

		
		// macros

		// windows ia32 calling conventions
		// - args pushed right-to-left
		// - EAX, ECX, EDX are scratch registers
		// - result in EAX (32bit) or EAX:EDX (64bit)

		// cdecl calling conventions:
		//  - caller pops args

		// thiscall calling conventions:
		//  - this in ECX
		//  - callee pops args

		// stdcall calling conventions
		//  - callee pops args

		// fastcall calling conventions
		//  - first 2 args in ECX, EDX
		//  - callee pops args
		
		/** call a method using a relative offset */
		void thincall(sintptr addr) 
		{
			#ifdef AVMPLUS_SPARC
			int disp = addr - (int)mip;
			CALL(disp);
			NOP();
			#endif

			#ifdef AVMPLUS_PPC
			int disp = addr - (int)mip;
			if (IsBranchDisplacement(disp)) {
				// Use relative branch if possible
				BL(disp);
			} else if (IsBranchDisplacement(addr)) {
				// Use absolute branch if possible
				// Note: address will be sign-extended.
				BLA (addr);
			} else {
				// Otherwise, use register-based branched
				LI32(R12, addr);
				MTCTR(R12);
				BCTRL();
			}
            #endif

			#ifdef AVMPLUS_ARM
			int disp = (MDInstruction*)addr - mip - 2;
			if (!(disp & 0xFF000000))
			{
				// Branch displacement fits in 24-bits, use BL instruction.
				BL(addr - (int)mip);
			}
			else
			{
				// Branch displacement doesn't fit
				MOV_imm32(IP, addr);
				MOV(LR, PC);
				MOV(PC, IP);
			}
			#endif
			
			#ifdef AVMPLUS_IA32
			CALL (addr - (5+(int)mip));
			#endif
			
			#ifdef AVMPLUS_AMD64
			int64 offset = addr - (5+(uintptr)mip);
			if (is32bit(offset))
				CALL (addr - (5+(uintptr)mip));
			else
			{
				MOV(R11, addr);
				MOV(-8, RSP, R11);
				LEA(R11, -8, RSP);

				// CALL code
				*mip++ = 0x4D; //64-bit mode
				*mip++ = 0xFF;
				*mip++ = 0x13; // call address in [R11]
			}
			#endif
		}

		bool isCodeContextChanged() const;
	};

	// machine dependent buffer sizing information try to use 4B aligned values
	#ifdef AVMPLUS_SPARC
	// TODO for sparc.
	static const int md_prologue_size		= 96;
	static const int md_epilogue_size		= 280;
	static const int md_native_thunk_size	= 1024;
	#endif

	#ifdef AVMPLUS_PPC
	static const int md_prologue_size		= 96;
	static const int md_epilogue_size		= 280;
	static const int md_native_thunk_size	= 1024;
	#endif

	#ifdef AVMPLUS_ARM
	static const int md_prologue_size		= 256;
	static const int md_epilogue_size		= 128;
	static const int md_native_thunk_size	= 1024;
    #endif /* AVMPLUS_ARM */
	
	#ifdef AVMPLUS_IA32
#ifdef VTUNE
	static const int md_prologue_size		= 64;
	static const int md_epilogue_size		= 256;
#else
	static const int md_prologue_size		= 32;
	static const int md_epilogue_size		= 128;
#endif // VTUNE

	static const int md_native_thunk_size	= 256;
	#endif /* AVMPLUS_PPC */
	
	#ifdef AVMPLUS_AMD64
	static const int md_prologue_size		= 128;
	static const int md_epilogue_size		= 256;
	static const int md_native_thunk_size	= 512;
	#endif /* AVMPLUS_PPC */

	typedef CodegenMIR::MirLabel CodegenLabel;
	typedef CodegenMIR::OP OP;
	typedef CodegenMIR Cogen;
}
#endif /* __avmplus_CodegenMIR__ */
