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

#ifdef DARWIN
#include <Carbon/Carbon.h>
#endif

namespace avmplus
{
	using namespace MMgc;

#ifdef AVMPLUS_PPC
#ifdef AVMPLUS_VERBOSE

	const char *CodegenMIR::gpregNames[] = {
		"r0",
		"sp",
		"rtoc",
		"r3",
		"r4",
		"r5",
		"r6",
		"r7",
		"r8",
		"r9",
		"r10",
		"r11",
		"r12",
		"r13",
		"r14",
		"r15",
		"r16",
		"r17",
		"r18",
		"r19",
		"r20",
		"r21",
		"r22",
		"r23",
		"r24",
		"r25",
		"r26",
		"r27",
		"r28",
		"r29",
		"r30",
		"r31"
	};

	const char *CodegenMIR::fpregNames[] = {
		"f0",		
		"f1",
		"f2",
		"f3",
		"f4",
		"f5",
		"f6",
		"f7",
		"f8",
		"f9",
		"f10",
		"f11",
		"f12",
		"f13",
		"f14",
		"f15",
		"f16",
		"f17",
		"f18",
		"f19",
		"f20",
		"f21",
		"f22",
		"f23",
		"f24",
		"f25",
		"f26",
		"f27",
		"f28",
		"f29",
		"f30",
		"f31"
	};


#endif

	void CodegenMIR::MR(Register dst, Register src, bool dot)
	{
        #ifdef AVMPLUS_VERBOSE
		if (pool->verbose) {
			if (dot)	core->console.format("    %A  mr.   %R, %R\n", mip, dst, src);
			else		core->console.format("    %A  mr    %R, %R\n", mip, dst, src);
		}
        #endif /* AVMPLUS_VERBOSE */
		*mip++ = 0x7C000378 | (src<<21) | (dst<<16) | (src<<11) | (int)dot;
	}

	void CodegenMIR::FpUnary(int op, Register dst, Register src)
	{
        #ifdef AVMPLUS_VERBOSE
		if (pool->verbose) {
			switch (op) {
			case 0x90: core->console.format("    %A  fmr   %F, %F\n", mip, dst, src); break;
			case 0x50: core->console.format("    %A  fneg  %F, %F\n", mip, dst, src); break;
			}
		}
        #endif /* AVMPLUS_VERBOSE */
		*mip++ = 0xFC000000 | (dst<<21) | (src<<11) | op;
	}

	void CodegenMIR::NEG(Register dst, Register src)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  neg %R, %R\n", mip, dst, src);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0x7C0000D0 | (dst<<21) | (src<<16);
	}

	void CodegenMIR::BR(int op, int addr)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose) {
			switch (op) {
			case 0: core->console.format("    %A  b     %A\n", mip, (uint32)mip+addr); break;
			case 1: core->console.format("    %A  bl    %A\n", mip, (uint32)mip+addr); break;
			case 2: core->console.format("    %A  ba    %A\n", mip, addr);
			case 3: core->console.format("    %A  bla   %A\n", mip, addr);
			}
		}
        #endif /* AVMPLUS_VERBOSE */
		*mip++ = 0x48000000 | op | (addr&0x3FFFFFC);
	}

	void CodegenMIR::GpBinary(int op, Register dst, Register src1, Register src2)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose) {
			switch (op) {
			case 0x214: core->console.format("    %A  add   %R, %R, %R\n", mip, dst, src1, src2); break;
			case 0x1D6: core->console.format("    %A  mullw %R, %R, %R\n", mip, dst, src1, src2); break;
			case 0x038: core->console.format("    %A  and   %R, %R, %R\n", mip, src1, dst, src2); break;
			case 0x050: core->console.format("    %A  sub   %R, %R, %R\n", mip, dst, src2, src1); break; // z = x - y is encoded as subf z,y,x 
			case 0x030: core->console.format("    %A  slw   %R, %R, %R\n", mip, src1, dst, src2); break;
			}
		}
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0x7C000000 | (dst<<21) | (src1<<16) | (src2<<11) | op;
	}
	
	void CodegenMIR::CMP(ConditionRegister CR, Register regA, Register regB)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  cmp cr%d, %R, %R\n", mip, CR, regA, regB);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0x7C000000 | (CR<<23) | (regA<<16) | (regB<<11);		
	}

	void CodegenMIR::CMPI(ConditionRegister CR, Register regA, int imm16)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  cmpi cr%d, %R, %d\n", mip, CR, regA, imm16);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0x2C000000 | (CR<<23) | (regA<<16) | (imm16&0xFFFF);
	}
	
	void CodegenMIR::CMPLI(ConditionRegister CR, Register regA, int imm16)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  cmpli cr%d, %R, %d\n", mip, CR, regA, imm16);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0x28000000 | (CR<<23) | (regA<<16) | (imm16&0xFFFF);
	}
	
	void CodegenMIR::CMPL(ConditionRegister CR, Register regA, Register regB)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  cmpl cr%d, %R, %R\n", mip, CR, regA, regB);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0x7C000040 | (CR<<23) | (regA<<16) | (regB<<11);		
	}

	void CodegenMIR::FCMPU(ConditionRegister CR, Register regA, Register regB)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  fcmpu cr%d, %F, %F\n", mip, CR, regA, regB);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0xFC000000 | (CR<<23) | (regA<<16) | (regB<<11);		
	}
	
	void CodegenMIR::RLWINM(Register dst, Register src, int shift, int begin, int end)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  rlwinm %R, %R, %d, %d, %d\n", mip, dst, src, shift, begin, end);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0x54000000 | (src<<21) | (dst<<16) | (shift<<11) | (begin<<6) | (end<<1);
	}
	
	void CodegenMIR::SLWI(Register dst, Register src, int shift)
	{
		AvmAssert(shift > 0 && shift < 32);
		RLWINM(dst, src, shift, 0, 31-shift);
	}

	void CodegenMIR::SRWI(Register dst, Register src, int shift)
	{
		AvmAssert(shift > 0 && shift < 32);
		RLWINM(dst, src, 32-shift, shift, 31);
	}
	
	void CodegenMIR::SRW(Register dst, Register src, Register shift)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  srw %R, %R, %R\n", mip, dst, src, shift);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0x7C000430 | (src<<21) | (dst<<16) | (shift<<11);
	}

	void CodegenMIR::SRAW(Register dst, Register src, Register shift)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  sraw %R, %R, %R\n", mip, dst, src, shift);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0x7C000630 | (src<<21) | (dst<<16) | (shift<<11);		
	}
	
	void CodegenMIR::SRAWI(Register dst, Register src, int shift)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  srawi %R, %R, %d\n", mip, dst, src, shift);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0x7C000670 | (src<<21) | (dst<<16) | (shift<<11);		
	}

	void CodegenMIR::LI(Register dst, int imm16)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  li %R, %d\n", mip, dst, imm16);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0x38000000 | (dst<<21) | (0<<16) | (imm16&0xFFFF);
	}
	
	void CodegenMIR::LIS(Register dst, int imm16)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  lis %R, %d\n", mip, dst, imm16);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0x3C000000 | (dst<<21) | (0<<16) | (imm16&0xFFFF);
	}
	
	void CodegenMIR::ADDI(Register dst, Register src, int imm16)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  addi %R, %R, %d\n", mip, dst, src, imm16);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0x38000000 | (dst<<21) | (src<<16) | (imm16&0xFFFF);		
	}

	void CodegenMIR::ADDIS(Register dst, Register src, int imm16)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  addis %R, %R, %d\n", mip, dst, src, imm16);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0x3C000000 | (dst<<21) | (src<<16) | (imm16&0xFFFF);		
	}

	void CodegenMIR::ORI(Register dst, Register src, int imm16)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  ori %R, %R, %d\n", mip, dst, src, imm16);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0x60000000 | (src<<21) | (dst<<16) | (imm16&0xFFFF);		
	}

	void CodegenMIR::ORIS(Register dst, Register src, int imm16)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  oris %R, %R, %d\n", mip, dst, src, imm16);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0x64000000 | (src<<21) | (dst<<16) | (imm16&0xFFFF);		
	}
	
	void CodegenMIR::ANDI_dot(Register dst, Register src, int imm16)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  andi. %R, %R, %d\n", mip, dst, src, imm16);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0x70000000 | (src<<21) | (dst<<16) | (imm16&0xFFFF);
	}

	void CodegenMIR::XORI(Register dst, Register src, int imm16)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  xori %R, %R, %d\n", mip, dst, src, imm16);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0x68000000 | (src<<21) | (dst<<16) | (imm16&0xFFFF);		
	}

	void CodegenMIR::XORIS(Register dst, Register src, int imm16)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  xoris %R, %R, %d\n", mip, dst, src, imm16);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0x6C000000 | (src<<21) | (dst<<16) | (imm16&0xFFFF);		
	}
	
	void CodegenMIR::OR(Register dst, Register src1, Register src2)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  or %R, %R, %R\n", mip, dst, src1, src2);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0x7C000378 | (src1<<21) | (dst<<16) | (src2<<11);		
	}

	void CodegenMIR::FADD(Register dst, Register src1, Register src2)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  fadd %F, %F, %F\n", mip, dst, src1, src2);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0xFC00002A | (dst<<21) | (src1<<16) | (src2<<11);
	}
	
	void CodegenMIR::FSUB(Register dst, Register src1, Register src2)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  fsub %F, %F, %F\n", mip, dst, src1, src2);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0xFC000028 | (dst<<21) | (src1<<16) | (src2<<11);
	}

	void CodegenMIR::FMUL(Register dst, Register src1, Register src2)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  fmul %F, %F, %F\n", mip, dst, src1, src2);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0xFC000032 | (dst<<21) | (src1<<16) | (src2<<6);
	}

	void CodegenMIR::FDIV(Register dst, Register src1, Register src2)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  fdiv %F, %F, %F\n", mip, dst, src1, src2);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0xFC000024 | (dst<<21) | (src1<<16) | (src2<<11);
	}
	
	void CodegenMIR::XOR(Register dst, Register src1, Register src2)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  xor %R, %R, %R\n", mip, dst, src1, src2);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0x7C000278 | (src1<<21) | (dst<<16) | (src2<<11);		
	}
	
	void CodegenMIR::SI(Register dst, Register src, int imm16)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  si %R, %R, %d\n", mip, dst, src, imm16);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0x30000000 | (dst<<21) | (src<<16) | (-imm16&0xFFFF);		
	}
	
	void CodegenMIR::LWZ(Register dst, int disp, Register base)
	{
		if (base == Unknown)
		{
			base = R0;
		}
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  lwz %R, %d(%R)\n", mip, dst, disp, base);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0x80000000 | (dst<<21) | (base<<16) | (disp&0xFFFF);
	}

	void CodegenMIR::LWZX(Register dst, Register rA, Register rB)
	{
		if (rA == Unknown)
		{
			rA = R0;
		}
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  lwzx %R, %R(%R)\n", mip, dst, rA, rB);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0x7C00002E | (dst<<21) | (rA<<16) | (rB<<11);
	}

	void CodegenMIR::STW(Register src, int disp, Register base)
	{
		if (base == Unknown)
		{
			base = R0;
		}
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  stw %R, %d(%R)\n", mip, src, disp, base);
        #endif /* AVMPLUS_VERBOSE */		
		if (base == Unknown)
			base = R0;
		*mip++ = 0x90000000 | (src<<21) | (base<<16) | (disp&0xFFFF);
	}

	void CodegenMIR::STWX(Register src, Register rA, Register rB)
	{
		if (rA == Unknown)
		{
			rA = R0;
		}
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  stwx %R, %R(%R)\n", mip, src, rA, rB);
        #endif /* AVMPLUS_VERBOSE */		
		if (rA == Unknown)
			rA = R0;
		*mip++ = 0x7C00012E | (src<<21) | (rA<<16) | (rB<<11);
	}
	
	void CodegenMIR::STMW(Register start, int disp, Register base)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  stmw %R, %d(%R)\n", mip, start, disp, base);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0xBC000000 | (start<<21) | (base<<16) | (disp&0xFFFF);
	}

	void CodegenMIR::LFD(Register dst, int disp, Register base)
	{
		if (base == Unknown)
		{
			base = R0;
		}
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  lfd %F, %d(%R)\n", mip, dst, disp, base);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0xC8000000 | (dst<<21) | (base<<16) | (disp&0xFFFF);
	}

	void CodegenMIR::LFDX(Register dst, Register rA, Register rB)
	{
		if (rA == Unknown)
		{
			rA = R0;
		}
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  lfdx %F, %R, %R\n", mip, dst, rA, rB);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0x7C0004AE | (dst<<21) | (rA<<16) | (rB<<11);
	}
	
	void CodegenMIR::STFD(Register src, int disp, Register base)
	{
		if (base == Unknown)
		{
			base = R0;
		}
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  stfd %F, %d(%R)\n", mip, src, disp, base);
        #endif /* AVMPLUS_VERBOSE */		
		if (base == Unknown) base = R0;
		*mip++ = 0xD8000000 | (src<<21) | (base<<16) | (disp&0xFFFF);
	}

	void CodegenMIR::STFDX(Register src, Register rA, Register rB)
	{
		if (rA == Unknown)
		{
			rA = R0;
		}
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  stfdx %F, %R, %R\n", mip, src, rA, rB);
        #endif /* AVMPLUS_VERBOSE */		
		if (rA == Unknown) rA = R0;
		*mip++ = 0x7C0005AE | (src<<21) | (rA<<16) | (rB<<11);
	}	
	
	void CodegenMIR::LMW(Register dst, int disp, Register base)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  lmw %R, %d(%R)\n", mip, dst, disp, base);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0xB8000000 | (dst<<21) | (base<<16) | (disp&0xFFFF);		
	}
	
	void CodegenMIR::STWU(Register dst, int disp, Register base)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  stwu %R, %d(%R)\n", mip, dst, disp, base);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0x94000000 | (base<<21) | (dst<<16) | (disp&0xFFFF);		
	}

	void CodegenMIR::STWUX(Register rS, Register rA, Register rB)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  stwux %R, %R, %R\n", mip, rS, rA, rB);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0x7C00016E | (rS<<21) | (rA<<16) | (rB<<11);
	}

	void CodegenMIR::MFCR(Register dst)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  mfcr %R\n", mip, dst);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0x7C000026 | (dst<<21);
	}

	void CodegenMIR::CROR(int crbD, int crbA, int crbB)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  cror %d, %d, %d\n", mip, crbD, crbA, crbB);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0x4C000382 | (crbD<<21) | (crbA<<16) | (crbB<<11);
	}

	void CodegenMIR::CRNOT(int crbD, int crbA)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  crnot %d, %d\n", mip, crbD, crbA);
        #endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0x4C000042 | (crbD<<21) | (crbA<<16) | (crbA<<11);
	}

	void CodegenMIR::Movspr(int op, Register r, Register spr)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose) {
			switch (op|spr<<16) {
			case 0x7C0003A6|CTR<<16: core->console.format("    %A  mtctr %R\n", mip, r); break;
			case 0x7C0003A6|LR <<16: core->console.format("    %A  mtlr  %R\n", mip, r); break;
			case 0x7C0002A6|LR <<16: core->console.format("    %A  mflr  %R\n", mip, r); break;
			}
		}
        #endif /* AVMPLUS_VERBOSE */

		*mip++ = op | (r<<21) | (spr<<16);
	}

	void CodegenMIR::Bcc(int op, ConditionRegister cr, int offset, bool hint)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose) {
			switch (op) {
			case 0x4182: core->console.format("    %A  beq   %A\n", mip, (uint32)mip+offset); break;
			case 0x4082: core->console.format("    %A  bne   %A\n", mip, (uint32)mip+offset); break;
			case 0x4081: core->console.format("    %A  ble   %A\n", mip, (uint32)mip+offset); break;
			case 0x4181: core->console.format("    %A  bgt   %A\n", mip, (uint32)mip+offset); break;
			case 0x4180: core->console.format("    %A  blt   %A\n", mip, (uint32)mip+offset); break;
			case 0x4080: core->console.format("    %A  bge   %A\n", mip, (uint32)mip+offset); break;
			case 0x4200: core->console.format("    %A  bdnz  %A\n", mip, (uint32)mip+offset); break;
			}
		}
        #endif /* AVMPLUS_VERBOSE */
		*mip++ = op<<16 | (offset&0xFFFF) | (hint<<21) | (cr<<18);
	}

	void CodegenMIR::Simple(int op)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose) {
			switch(op) {
			case 0x4E800020: core->console.format("    %A  blr\n", mip); break;
			case 0x4E800420: core->console.format("    %A  bctr\n", mip); break;
			case 0x4E800421: core->console.format("    %A  bctrl\n", mip); break;
			case 0x60000000: core->console.format("    %A  nop\n", mip); break;
			}
		}
        #endif // AVMPLUS_VERBOSE		
		*mip++ = op;
	}

	bool CodegenMIR::canImmFold(OP *ins, OP *imm) const
	{
		if (imm->code != MIR_imm)
			return false;
		switch (ins->code)
		{
		case MIR_lsh:
		case MIR_rsh:
		case MIR_ush:
		case MIR_or:
		case MIR_xor:
			// can be any 32-bit immediate
			return true;
		case MIR_and:
		case MIR_ucmp:
			// must be 16-bit unsigned immediate
			return isUIMM(imm->imm);
		case MIR_icmp:
		case MIR_add:
		case MIR_sub:
			// must be 16-bit signed immediate
			return isSIMM(imm->imm);
		default:
			return false;
		}
	}

#ifndef MAX
#define MAX(x,y) ( (x)>(y)?(x):(y) )
#endif /* MAX */

#if !TARGET_RT_MAC_MACHO
	intptr_t nativeHandlerAddr(NativeMethod::Handler handler)
	{
		intptr_t result;
		asm("lwz %0,0(%%r5)" : "=r" (result));
		return result;
	}
#endif // !TARGET_RT_MAC_MACHO
	
#if !TARGET_RT_MAC_MACHO
	static uintptr_t get_rtoc()
	{
		uintptr_t result;
		asm ("mr %0, %%r2" : "=r" (result));
		return result;
	}
#endif // !TARGET_RT_MAC_MACHO

	void* CodegenMIR::emitImtThunk(ImtBuilder::ImtEntry *e)
	{
		mip = mipStart = (MDInstruction*)getMDBuffer(pool);

#ifdef FEATURE_BUFFER_GUARD
		GrowthGuard guard(pool->codeBuffer);
#else
		if (!ensureMDBufferCapacity(pool, md_native_thunk_size))
			return NULL;
#endif /* FEATURE_BUFFER_GUARD */

		// the generated thunk does not call any helper methods, so we are
		// free to use eax, ecx, edx as scratch regs without touchning the
		// stack.
		
		// in: R6 = iid
		//     R3 = MethodEnv
		//     R4 = argc
		//     R5 = ap
		//     0(ap)  = ScriptObject (concrete instance of class)
		
		// local register allocation:
		// R7 = iid parameter
		// R8 = vtable of receiver obj
		// R9 = temp

#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
		{
			core->console << "imt thunk\n";
		}
#endif

		LWZ (R9, 0, R5); // obj
		LWZ (R8, offsetof(ScriptObject, vtable), R9); // vtable

		AvmAssert(e->next != NULL); // must have 2 or more entries

		while (e->next)
		{
			ImtBuilder::ImtEntry *next = e->next;

			#ifdef AVMPLUS_VERBOSE
			if (pool->verbose)
			{
				core->console << "              disp_id="<< e->disp_id << " " << e->virt << "\n";
			}
			#endif
			int iid = e->virt->iid();
			if (isUIMM(iid))
			{
				CMPI (CR0, R6, iid);
			}
			else
			{
				LI32(R0, iid);
				CMP (CR0, R6, R0);
			}

			MDInstruction* patchip = mip;
			BNE (CR0, 0);
			LWZ (R3, offsetof(VTable,methods)+4*e->disp_id, R8); // load concrete env
			LWZ (R12, offsetof(MethodEnv, impl32), R3); // invoke real method indirectly
			#if !TARGET_RT_MAC_MACHO
			LWZ (R0, 0, R12);
			MTCTR (R0);
			#else
			MTCTR (R12);
			#endif
			BCTR ();
			patchRelativeBranch(patchip, mip);

			pool->core->GetGC()->Free(e);
			e = next;
		}

		// last one is unconditional
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
		{
			core->console << "              disp_id="<< e->disp_id << " " << e->virt << "\n";
		}
		#endif
		LWZ (R3, offsetof(VTable,methods)+4*e->disp_id, R8); // load concrete env
		LWZ (R12, offsetof(MethodEnv, impl32), R3); // invoke real method indirectly
		#if !TARGET_RT_MAC_MACHO
		LWZ (R0, 0, R12);
		MTCTR (R0);
		#else
		MTCTR (R12);
		#endif
		BCTR ();

		MDInstruction *retval;
		
#if !TARGET_RT_MAC_MACHO
		// Write the code pointer for the ABI's benefit
		mip = (MDInstruction*) ((size_t)mip+7 & ~7); // align on 8
		*mip++ = (uint32)mipStart;
		*mip++ = get_rtoc();

		retval = mip-2;
#else
		retval = mipStart;
#endif

#ifndef AVMPLUS_JIT_READONLY
		// Tell the OS that this buffer contains executable code.
		// This is required since machines like the G4 have dual
		// cache designs.
		MakeDataExecutable(mipStart, (int)mip-(int)mipStart);
#endif /* AVMPLUS_JIT_READONLY */
		
#ifdef AVMPLUS_JIT_READONLY
		makeCodeExecutable();
#endif /* AVMPLUS_JIT_READONLY */
		
		// lock in the next available location in the buffer (16B aligned)
		pool->codeBuffer->setPos((byte*) ( (size_t)mip+15 & ~15 ));

		return retval;
	}

#endif // AVMPLUS_PPC
}
#endif
