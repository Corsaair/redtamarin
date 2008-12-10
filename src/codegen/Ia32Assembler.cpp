/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4 -*- */
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


#include "avmplus.h"
#ifdef AVMPLUS_MIR
#include "CodegenMIR.h"

namespace avmplus
{
	using namespace MMgc;

#ifdef AVMPLUS_IA32
#ifdef AVMPLUS_VERBOSE

	const char *CodegenMIR::gpregNames[] = {		
		"eax",
		"ecx",
		"edx",
		"ebx",
		"esp",
		"ebp",
		"esi",
		"edi"
	};

	const char *CodegenMIR::xmmregNames[] = {
		"xmm0",
		"xmm1",
		"xmm2",
		"xmm3",
		"xmm4",
		"xmm5",
		"xmm6",
		"xmm7"
	};

	const char *CodegenMIR::x87regNames[] = {
		"fst0",
		"fst1",
		"fst2",
		"fst3",
		"fst4",
		"fst5",
		"fst6",
		"fst7",
	};

#endif // AVMPLUS_VERBOSE
#endif // AVMPLUS_IA32

#ifdef AVMPLUS_IA32
	void CodegenMIR::MODRM(Register reg, Register operand)
	{
 		*mip++ = (MDInstruction)(3<<6 | reg<<3 | operand);
 	}

	void CodegenMIR::MODRM(Register reg, sintptr disp, Register base, int lshift, Register index)
 	{
 		// reg <-> disp[base+index<<lshift]
 		AvmAssert(lshift >= 0 && lshift <= 3);
 		if (disp == 0 && base != EBP) {
 			mip[0] = (MDInstruction)(     0<<6 |   reg<<3 | 4);		// ModR/M
 			mip[1] = (MDInstruction)(lshift<<6 | index<<3 | base);	// SIB
			mip += 2;
 		} else if (is8bit(disp)) {
 			mip[0] = (MDInstruction)(     1<<6 |   reg<<3 | 4);		// ModR/M
 			mip[1] = (MDInstruction)(lshift<<6 | index<<3 | base);	// SIB
			mip[2] = (MDInstruction)(disp);
 			mip += 3;
 		} else {
 			*(mip++) = (MDInstruction)(     2<<6 |   reg<<3 | 4);		// ModR/M
 			*(mip++) = (MDInstruction)(lshift<<6 | index<<3 | base);		// SIB
 			IMM32(disp);
 		}
 	}

	void CodegenMIR::MODRM(Register reg, sintptr disp, Register base)
 	{
 		// dest <-> disp[base]
		if (base == Unknown) {
			// disp = absolute addr
			*(mip++) = (MDInstruction)(0<<6 | reg<<3 | 5);
			IMM32(disp);
		}
 		else if (base == ESP) {
 			MODRM(reg, disp, base, 0, (Register)4); // index==4 means ignore index
 		}
		else if (disp == 0 && base != EBP) {
 			*(mip++) = (MDInstruction)(0<<6 | reg<<3 | base); // mod r/m
 		} else if (is8bit(disp)) {
 			*(mip++) = (MDInstruction)(1<<6 | reg<<3 | base); // mod r/m
 			*(mip++) = (MDInstruction)(disp);
 		} else {
 			*(mip++) = (MDInstruction)(2<<6 | reg<<3 | base); // mod r/m
 			IMM32(disp);
 		}
 	}

	void CodegenMIR::PUSH(sintptr imm)
 	{
		count_push();
		#ifdef AVMPLUS_VERBOSE
		if (verbose())
			core->console.format("    %A  push  %d\n", mip, imm);
		#endif /* AVMPLUS_VERBOSE */

		if (is8bit(imm)) {
			// push imm8 (sign extended)
			mip[0] = (MDInstruction)(0x6a);
			mip[1] = (MDInstruction)(imm);
			mip += 2;
 		} else {
			// push imm32
 			*mip++ = (MDInstruction)(0x68);
 			IMM32(imm);
 		}
 	}

	void CodegenMIR::MOV(Register dest, sintptr imm32) 
	{
		count_mov();
		#ifdef AVMPLUS_VERBOSE
		if (verbose())
			core->console.format("    %A  mov   %R, %d\n", mip, dest, imm32);
		#endif /* AVMPLUS_VERBOSE */

		// mov reg, imm32
		*mip++ = (MDInstruction)(0xb8 | dest);
		IMM32(imm32);
	}

	void CodegenMIR::MOV(sintptr disp, Register base, sintptr imm, bool /*unused*/) 
	{
		count_st();
		#ifdef AVMPLUS_VERBOSE
		if (verbose())
			core->console.format("    %A  mov   %d(%R), %d\n", mip, disp, base, imm);
		#endif /* AVMPLUS_VERBOSE */

		// mov disp[base], imm32
 		*mip++ = 0xc7;
 		MODRM((Register)0, disp, base);
 		IMM32(imm);
	}

	void CodegenMIR::ALU (byte op, Register reg, sintptr imm)
 	{
		#ifdef AVMPLUS_VERBOSE
		if (verbose())
		{
			const char *opstr="?";
			switch(op) {
			case 0x2d: opstr = "sub  "; break;
			case 0x05: opstr = "add  "; break;
			case 0x25: opstr = "and  "; break;
			case 0x35: opstr = "xor  "; break;
			case 0x0d: opstr = "or   "; break;
			case 0x3d: opstr = "cmp  "; break;
			}
			core->console.format("    %A  %s %R, %d\n", mip, opstr, reg, imm);
		}
		#endif

 		if (is8bit(imm)) {
			// <op> reg, imm8
 			mip[0] = (MDInstruction)(0x83);
 			mip[1] = (MDInstruction)(3<<6 | op&~7 | reg);
 			mip[2] = (MDInstruction)(imm);
			mip+=3;
 		} else {
 			if (reg == EAX) {
				// <op> eax, imm32
 				*mip++ = (MDInstruction)(op);
 			} else {
				// <op> reg, imm32
 				mip[0] = (MDInstruction)(0x81);
 				mip[1] = (MDInstruction)(3<<6 | op&~7 | reg);
				mip+=2;
 			}
 			IMM32(imm);
 		}
 	}

	void CodegenMIR::ALU(int op, Register r, Register rhs)
	{
		#ifdef AVMPLUS_VERBOSE
		if (verbose())
		{
			switch(op) {
			case 0x2b: core->console.format("    %A  sub   %R, %R\n", mip, r, rhs); break;
			case 0x03: core->console.format("    %A  add   %R, %R\n", mip, r, rhs); break;
			case 0x23: core->console.format("    %A  and   %R, %R\n", mip, r, rhs); break;
			case 0x33: core->console.format("    %A  xor   %R, %R\n", mip, r, rhs); break;
			case 0x0b: core->console.format("    %A  or    %R, %R\n", mip, r, rhs); break;
			case 0x3b: core->console.format("    %A  cmp   %R, %R\n", mip, r, rhs); break;
			case 0xaf: core->console.format("    %A  imul  %R, %R\n", mip, r, rhs); break;
			case 0x85: core->console.format("    %A  test  %R, %R\n", mip, r, rhs); break;
			case 0xf7: core->console.format("    %A  neg   %R\n", mip, rhs); break;
			case 0x87: core->console.format("    %A  xchg  %R, %R\n", mip, r, rhs); break;
			case 0x8b: core->console.format("    %A  mov   %R, %R\n", mip, r, rhs); break;
			}
		}
		#endif /* AVMPLUS_VERBOSE */

		*mip++ = (MDInstruction)(op); 
		MODRM(r, rhs);
	}

	void CodegenMIR::ALU2(int op, Register r, Register rhs)
	{
		#ifdef AVMPLUS_VERBOSE
		if (verbose())
		{
			switch(op) {
			case 0x0faf: core->console.format("    %A  imul  %R, %R\n", mip, r, rhs); break;
			case 0x0f92: core->console.format("    %A  setb  %R\n", mip, r); break;
			case 0x0f93: core->console.format("    %A  setnb %R\n", mip, r); break;
			case 0x0f94: core->console.format("    %A  sete  %R\n", mip, r); break;
			case 0x0f95: core->console.format("    %A  setne %R\n", mip, r); break;
			case 0x0f96: core->console.format("    %A  setbe %R\n", mip, r); break;
			case 0x0f97: core->console.format("    %A  setnbe %R\n", mip, r); break;
			case 0x0f9a: core->console.format("    %A  setp  %R\n", mip, r); break;
			case 0x0f9b: core->console.format("    %A  setnp %R\n", mip, r); break;
			case 0x0f9C: core->console.format("    %A  setl  %R\n", mip, r); break;
			case 0x0f9E: core->console.format("    %A  setle %R\n", mip, r); break;
			case 0x0fb6: core->console.format("    %A  movzx_r8 %R, %R\n", mip, r, rhs);
			case 0x0fbe: core->console.format("    %A  movsx_r8 %R, %R\n", mip, r, rhs);
			case 0x0fbf: core->console.format("    %A  movsx_r16 %R, %R\n", mip, r, rhs);
			}
		}
		#endif /* AVMPLUS_VERBOSE */

		mip[0] = (MDInstruction)(op>>8);
		mip[1] = (MDInstruction)(op); 
		mip += 2;
		MODRM(r, rhs);
	}

	void CodegenMIR::SSE(int op, Register dest, Register src)
	{
		#ifdef AVMPLUS_VERBOSE
		if (verbose())
		{
			switch(op) {
			case 0xf20f58: core->console.format("    %A  addsd %F, %F\n", mip, dest, src); break;
			case 0xf20f5c: core->console.format("    %A  subsd %F, %F\n", mip, dest, src); break;
			case 0xf20f59: core->console.format("    %A  mulsd %F, %F\n", mip, dest, src); break;
			case 0xf20f5e: core->console.format("    %A  divsd %F, %F\n", mip, dest, src); break;
			case 0xf20f2a: core->console.format("    %A  cvtsi2sd %F, %R\n", mip, dest, src); break;
			case 0xf20f2c: core->console.format("    %A  cvttsd2si %F, %R\n", mip, dest, src); break;
			case 0x660f28: core->console.format("    %A  movapd %F, %F\n", mip, dest, src); break;
			case 0x660f2e: core->console.format("    %A  ucomisd %F, %F\n", mip, dest, src); break;
			}
		}
		#endif /* AVMPLUS_VERBOSE */

 		mip[0] = (MDInstruction)(op>>16);
		mip[1] = (MDInstruction)(op>>8);
		mip[2] = (MDInstruction)(op);
		mip += 3;
		MODRM(dest, src);
	}

	void CodegenMIR::SSE(int op, Register r, sintptr disp, Register base)
	{
		#ifdef AVMPLUS_VERBOSE
		if (verbose())
		{
			switch(op) {
			case 0xf20f58: core->console.format("    %A  addsd %F, %d(%R)\n", mip, r, disp, base); break;
			case 0xf20f5c: core->console.format("    %A  subsd %F, %d(%R)\n", mip, r, disp, base); break;
			case 0xf20f59: core->console.format("    %A  mulsd %F, %d(%R)\n", mip, r, disp, base); break;
			case 0xf20f5e: core->console.format("    %A  divsd %F, %d(%R)\n", mip, r, disp, base); break;
			case 0xf30f10: core->console.format("    %A  movss %F, %d(%R)\n", mip, r, disp, base); break;
			case 0xf30f11: core->console.format("    %A  movss %d(%R), %F\n", mip, disp, base, r); break;
			case 0xf20f10: core->console.format("    %A  movsd %F, %d(%R)\n", mip, r, disp, base); break;
			case 0xf20f11: core->console.format("    %A  movsd %d(%R), %F\n", mip, disp, base, r); break;
			case 0xf20f2a: core->console.format("    %A  cvtsi2sd %F, %d(%R)\n", mip, r, disp, base); break;
			}
		}
		#endif /* AVMPLUS_VERBOSE */

 		mip[0] = (MDInstruction)(op>>16);
		mip[1] = (MDInstruction)(op>>8);
		mip[2] = (MDInstruction)(op);
		mip += 3;
 		MODRM(r, disp, base);
	}
	
	void CodegenMIR::XORPD(Register dest, uintptr addr) 
	{
		count_fpuld();
		#ifdef AVMPLUS_VERBOSE
		if (verbose())
			core->console.format("    %A  xorpd %F, %A\n", mip, dest, addr);
		#endif /* AVMPLUS_VERBOSE */

		// xorpd dest, m128
 		mip[0] = (MDInstruction)(0x66);
		mip[1] = (MDInstruction)(0x0f);
		mip[2] = (MDInstruction)(0x57);
		mip[3] = (MDInstruction)((dest<<3) | 5);
		mip += 4;
		IMM32(addr);
	}

	void CodegenMIR::IMUL(Register dst, sintptr imm)
	{
		count_alu();
		#ifdef AVMPLUS_VERBOSE
		if (verbose())
			core->console.format("    %A  imul  %R, %d\n", mip, dst, imm);
		#endif /* AVMPLUS_VERBOSE */

		if (is8bit(imm))
		{
			*mip++ = (MDInstruction)(0x6b);
			MODRM(dst,dst);
			*mip++ = (MDInstruction)(imm);
		}
		else
		{
			*mip++ = (MDInstruction)(0x69);
			MODRM(dst, dst);
			IMM32(imm);
		}
	}

	void CodegenMIR::ALU(int op)
	{
		#ifdef AVMPLUS_VERBOSE
		if (verbose())
		{
			switch(op) {
			case 0xc9: core->console.format("    %A  leave\n", mip); break;
			case 0xc3: core->console.format("    %A  ret\n", mip); break;
			case 0x90: core->console.format("    %A  nop\n", mip); break;
			case 0x9f: core->console.format("    %A  lahf\n", mip); break;
			case 0x50: case 0x51: case 0x52: case 0x53: case 0x54: case 0x55: case 0x56: case 0x57:
				core->console.format("    %A  push  %R\n", mip, op&7);
				break;
			case 0x58: case 0x59: case 0x5A: case 0x5B: case 0x5C: case 0x5D: case 0x5E: case 0x5F:
				core->console.format("    %A  pop   %R\n", mip, op&7);
				break;
			}
		}
		#endif /* AVMPLUS_VERBOSE */
		*mip++ = (MDInstruction)(op);
	}

	void CodegenMIR::SHIFT(int op, Register r, int imm8)
	{
		#ifdef AVMPLUS_VERBOSE
		if (verbose())
		{
			const char *opstr = "?";
			switch (op) {
			case 7: opstr = "sar  "; break;
			case 5: opstr = "shr  "; break;
			case 4: opstr = "shl  "; break;
			}
			core->console.format("    %A  %s %R, %d\n", mip, opstr, r, imm8);
		}
		#endif /* AVMPLUS_VERBOSE */

		*mip++ = (MDInstruction)(0xc1);
		MODRM((Register)op, r);
		*mip++ = (MDInstruction)(imm8);
	}

	void CodegenMIR::ALU(int op, Register r, sintptr disp, Register base)
	{
		#ifdef AVMPLUS_VERBOSE
		if (verbose())
		{
			switch (op)
			{
			case 0x85: core->console.format("    %A  test  %d(%R), %R\n", mip, disp, base, r); break;
			case 0x8d: core->console.format("    %A  lea   %R, %d(%R)\n", mip, r, disp, base); break;
			case 0x88: core->console.format("    %A  mov_8   %d(%R), %R\n", mip, disp, base, r); break;
			case 0x6689: core->console.format("    %A  mov_16   %d(%R), %R\n", mip, disp, base, r); break;
			case 0x89: core->console.format("    %A  mov   %d(%R), %R\n", mip, disp, base, r); break;
			case 0x8b: core->console.format("    %A  mov   %R, %d(%R)\n", mip, r, disp, base); break;
			case 0x0fbe: core->console.format("    %A  movsx_8   %R, %d(%R)\n", mip, r, disp, base); break;
			case 0x0fbf: core->console.format("    %A  movsx_16   %R, %d(%R)\n", mip, r, disp, base); break;
			case 0x0fb6: core->console.format("    %A  movzx_8   %R, %d(%R)\n", mip, r, disp, base); break;
			case 0x0fb7: core->console.format("    %A  movzx_16   %R, %d(%R)\n", mip, r, disp, base); break;
			case 0xff: 
				switch(r) {
				case 2: core->console.format("    %A  call  %d(%R)\n", mip, disp, base); break;
				case 4: core->console.format("    %A  jmp   %d(%R)\n", mip, disp, base); break;
				case 6: core->console.format("    %A  push  %d(%R)\n", mip, disp, base); break;
				}
			}
		}
		#endif /* AVMPLUS_VERBOSE */

		if(op >= 0x100)
			*mip++ = (MDInstruction)(op >> 8);
		*mip++ = (MDInstruction)(op) & 0xff;
		MODRM(r, disp, base);
	}

	void CodegenMIR::JCC(byte op, sintptr offset)
 	{
		#ifdef AVMPLUS_VERBOSE
		if (verbose())
		{
			const char *opstr="?";
			switch(op) {
			case 0x02: opstr = "jb   "; break;
			case 0x03: opstr = "jnb  "; break;
			case 0x04: opstr = "je   "; break;
			case 0x05: opstr = "jne  "; break;
			case 0x06: opstr = "jbe  "; break;
			case 0x07: opstr = "jnbe "; break;
			case 0x0a: opstr = "jp   "; break;
			case 0x0b: opstr = "jnp  "; break;
			case 0x0c: opstr = "jl   "; break;
			case 0x0d: opstr = "jnl  "; break;
			case 0x0e: opstr = "jle  "; break;
			case 0x0f: opstr = "jnle "; break;
			}
			core->console.format("    %A  %s %d\n", mip, opstr, offset);
		}
		#endif /* AVMPLUS_VERBOSE */

		// j<op> off32
		if (is8bit(offset)) {
			mip[0] = (MDInstruction)(0x70 | op);
			mip[1] = (MDInstruction)(offset);
			mip += 2;
		} else {
 			mip[0] = (MDInstruction)(0x0f);
 			mip[1] = (MDInstruction)(0x80 | op);
			mip+=2;
 			IMM32(offset);
		}
 	}
	
	void CodegenMIR::JMP(sintptr offset)
	{
		count_jmp();
		#ifdef AVMPLUS_VERBOSE
		if (verbose())
			core->console.format("    %A  jmp   %d\n", mip, offset);
		#endif /* AVMPLUS_VERBOSE */

		if (is8bit(offset)) {
			mip[0] = (MDInstruction)(0xeb);
			mip[1] = (MDInstruction)(offset);
			mip += 2;
		} else {
 			*mip++ = (MDInstruction)(0xe9);
 			IMM32(offset);
		}
	}

	void CodegenMIR::CALL(sintptr offset)
	{
		count_call();
		#ifdef AVMPLUS_VERBOSE
		if (verbose())
			core->console.format("    %A  call  %A\n", mip, offset+(int)(mip+5));
		#endif /* AVMPLUS_VERBOSE */

		*mip++ = 0xE8;
		IMM32(offset);
	}

	void CodegenMIR::FPU(int op, Register r)
	{
		#ifdef AVMPLUS_VERBOSE
		if (verbose())
		{
			const char *opstr="?";
			switch(op) {
			case 0xddd8: opstr = "fstp "; x87Top++; break;
			case 0xddc0: opstr = "ffree"; x87Top++; break;
			case 0xd8c0: opstr = "faddq"; x87Top++; break;
			case 0xd8e0: opstr = "fsubq"; x87Top++; break;
			case 0xd8c8: opstr = "fmulq"; x87Top++; break;
			case 0xd8f0: opstr = "fdivq"; x87Top++; break;
			}
			core->console.format("    %A  %s %X\n", mip, opstr, r);
		}
		#endif /* AVMPLUS_VERBOSE */

		*mip++ = (MDInstruction)(op>>8);
		*mip++ = (MDInstruction)(op&255 | r);
	}

	void CodegenMIR::FPU(int op, sintptr disp, Register base)
	{
		#ifdef AVMPLUS_VERBOSE
		if (verbose())
		{
			const char *opstr="?";
			switch(op) {
			case 0xdc02: opstr = "fcom "; break;
			case 0xdd03: opstr = "fstpq"; x87Top++; break;
			case 0xd902: opstr = "fstd "; break;
			case 0xdd02: opstr = "fstq "; break;
			case 0xd900: opstr = "fldd "; x87Top++; break;
			case 0xdd00: opstr = "fldq "; x87Top++; break;
			case 0xdf05: opstr = "fildq"; x87Top--; break;
			case 0xdc00: opstr = "faddq"; break;
			case 0xdc04: opstr = "fsubq"; break;
			case 0xdc01: opstr = "fmulq"; break;
			case 0xdc06: opstr = "fdivq"; break;
			case 0xdb00: opstr = "fild "; x87Top--; break;
			}
			core->console.format("    %A  %s %d(%R)\n", mip, opstr, disp, base);
		}
		#endif /* AVMPLUS_VERBOSE */

		AvmAssert(x87Dirty);
		*mip++ = (MDInstruction)(op>>8);
		MODRM((Register)(op&0xff), disp, base);
	}

	void CodegenMIR::FPU(int op)
	{
		#ifdef AVMPLUS_VERBOSE
		if (verbose())
		{
			const char *opstr="?";
			switch(op) {
			case 0xdde9: opstr = "fucomp"; x87Top++; break;
			case 0xd9e0: opstr = "fchs "; break;
			case 0xdfe0: opstr = "fnstsw ax"; break;
			case 0x0f77: opstr = "emms "; x87Top=0; break;
			}
			core->console.format("    %A  %s\n", mip, opstr);
		}
		#endif /* AVMPLUS_VERBOSE */

		mip[0] = (MDInstruction)(op>>8);
		mip[1] = (MDInstruction)(op&255);
		mip += 2;
	}

	void CodegenMIR::TEST_AH(uint8 imm8)
	{
		count_alu();
        #ifdef AVMPLUS_VERBOSE
		if (verbose())
			core->console.format("    %A  test  ah, %d\n", mip, imm8);
        #endif // AVMPLUS_VERBOSE

		mip[0] = 0xf6;
		mip[1] = 0xc4;
		mip[2] = imm8;
		mip += 3;
	}

	bool CodegenMIR::canImmFold(OP *ins, OP *imm) const
	{
		bool can = false;
		if (imm->code == MIR_imm)
		{
			switch (ins->code)
			{
			case MIR_lsh:
			case MIR_rsh:
			case MIR_ush:
			case MIR_and:
			case MIR_or:
			case MIR_xor:
			case MIR_add:
			case MIR_sub:
		    case MIR_imul:
			case MIR_icmp:
			case MIR_ucmp:
			case MIR_i2d:
			case MIR_st:
				// can be any 32-bit immediate
				can = true;
				break;
			}
		}
		return can;
	}

	/**
	 * For stacks that are bigger than one page we need to touch each page 
	 * since windows expects that the stack grows at most one page at time
	 * This code was *transcribed* from chkstk.asm
	 */
	void CodegenMIR::emitAllocaProbe(int growthAmt, MdLabel* returnTo)
	{
		#define _PAGESIZE_ 4096

		MDInstruction* label_loop;

			MOV(EAX, growthAmt);
	        MOV(ECX, ESP);			//      ; current stack pointer in ecx
			SUB(ESP, EAX);			//	    ; set the new stack pointer, needs to be done before probe for linux!

		label_loop = mip;
			SUB(ECX,_PAGESIZE_);    //      ; move down a page
			SUB(EAX,_PAGESIZE_);	//		; adjust request and...

			TEST(0, ECX, EAX);		//      ; ...probe it

			CMP(EAX,_PAGESIZE_);	//      ; more than one page requested?
			JNB(1);					//      ; no
			mip[-1] = (MDInstruction)(label_loop-mip);

			SUB(ECX,EAX);			//      ; move stack down by eax
			MOV(EAX,ESP);			//      ; save current tos and do a...
			ADD(EAX, growthAmt );   //      ; // not 100% sure if needed, but keep eax at the previous sp
		
			TEST(0, ECX, EAX);		//      ; ...probe in case a page was crossed

			JMP(0x7FFFFFFF);		//		; jmp back into mainline code
			mdPatchPrevious(returnTo);

		#undef _PAGESIZE_ 
	}
	
	void* CodegenMIR::emitImtThunk(ImtBuilder::ImtEntry *e)
	{
		count_imt();
		mip = mipStart = getMDBuffer(pool);
		if (!mip)
		{
			overflow = true;
			return NULL;
		}

#ifdef FEATURE_BUFFER_GUARD
		GrowthGuard guard(pool->codeBuffer);
#else
		if (!ensureMDBufferCapacity(pool, md_native_thunk_size))
			return NULL;
#endif /* FEATURE_BUFFER_GUARD */

		// the generated thunk does not call any helper methods, so we are
		// free to use eax, ecx, edx as scratch regs without touchning the
		// stack.

		// in: EDX = iid
		//     4(ESP) = MethodEnv
		//     8(ESP) = argc
		//    12(ESP) = ap
		//     0(ap)  = ScriptObject (concrete instance of class)
		
		// local register allocation:
		// eax = iid parameter
		// ecx = vtable of receiver obj

		const int _ap = 12;
		const int _env = 4;

#ifdef AVMPLUS_VERBOSE
		if (verbose())
		{
			core->console << "imt thunk\n";
		}
#endif

		MOV (ECX, _ap, ESP);		// ap
		MOV (ECX, 0, ECX);			// obj
		MOV (ECX, offsetof(ScriptObject, vtable), ECX); // vtable

		AvmAssert(e->next != NULL); // must have 2 or more entries

		while (e->next)
		{
			ImtBuilder::ImtEntry *next = e->next;

			#ifdef AVMPLUS_VERBOSE
			if (verbose())
			{
				core->console << "              disp_id="<< e->disp_id << " " << e->virt << "\n";
			}
			#endif
			CMP (EDX, e->virt->iid());
			JNE (1);
			byte* patchip = mip;
			MOV (EAX, offsetof(VTable,methods)+4*e->disp_id, ECX); // load concrete env
			MOV (_env, ESP, EAX);  // replace env before call
			JMP (offsetof(MethodEnv, impl32), EAX); // invoke real method indirectly
			patchip[-1] = (byte)(mip-patchip);

			pool->core->GetGC()->Free(e);
			e = next;
		}

		// last one is unconditional
		#ifdef AVMPLUS_VERBOSE
		if (verbose())
		{
			core->console << "              disp_id="<< e->disp_id << " " << e->virt << "\n";
		}
		#endif
		MOV (EAX, offsetof(VTable,methods)+4*e->disp_id, ECX); // load concrete env
		MOV (_env, ESP, EAX);  // replace env before call
		JMP (offsetof(MethodEnv, impl32), EAX); // invoke real method indirectly

#ifdef AVMPLUS_JIT_READONLY
		makeCodeExecutable();
#endif /* AVMPLUS_JIT_READONLY */
		
		// lock in the next available location in the buffer (16B aligned)
		pool->codeBuffer->setPos((byte*) ( (size_t)mip+15 & ~15 ));

		return mipStart;
	}

#endif /* AVMPLUS_IA32 */

}
#endif
