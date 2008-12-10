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
#include "CodegenMIR.h"

namespace avmplus
{
	using namespace MMgc;

#ifdef AVMPLUS_SPARC
#ifdef AVMPLUS_VERBOSE
	const char *CodegenMIR::gpregNames[] = {
		"r0",
		"r1",
		"r2",
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
		case MIR_and:
		case MIR_ucmp:
		case MIR_icmp:
		case MIR_add:
		case MIR_sub:
		case MIR_imul:
			// must be 13-bit immediate
			return isIMM13(imm->imm);
		default:
			return false;
		}
	}

#ifndef MAX
#define MAX(x,y) ( (x)>(y)?(x):(y) )
#endif /* MAX */

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

		LDSWI(O2, 0, G1);
		LDSWI(G1, offsetof(ScriptObject, vtable), G2);
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
			if (isIMM13(iid))
			{
				SUBCCI(O3, iid, G0);
			}
			else
			{
				SET32(iid, G3);
				SUBCC(O3, G3, G0);
			}

			MDInstruction* patchip = mip;
			BNE(1, 0);
			NOP();
			LDSWI(G2, offsetof(VTable,methods)+4*e->disp_id, O0);
			LDSWI(O0, offsetof(MethodEnv, impl32), G4);
			JMPL(G0, G4, G0);
			NOP();
			patchRelativeBranch(patchip, mip);

			pool->core->gc->Free(e);
			e = next;
		}

		// last one is unconditional
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
		{
			core->console << "              disp_id="<< e->disp_id << " " << e->virt << "\n";
		}
		#endif
		LDSWI(G2, offsetof(VTable,methods)+4*e->disp_id, O0);
		LDSWI(O0, offsetof(MethodEnv, impl32), G4);
		JMPL(G0, G4, G0);
		NOP();

		MDInstruction *retval;
		
		retval = mipStart;

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

	void CodegenMIR::CALL(int offset)
	{
		#ifdef AVMPLUS_VERBOSE
		if (pool->verbose)
			core->console.format("    %A  call %d\n", mip, offset >> 2);
		#endif /* AVMPLUS_VERBOSE */		
		*mip++ = 0x40000000 | ((offset >> 2) & 0x3FFFFFFF);
	}

	void CodegenMIR::Format_2_1(Register rd, int op2, int imm22)
	{
		*mip++ = rd << 25 | op2 << 22 | (imm22 & 0x3FFFFF);
	}

	void CodegenMIR::Format_2_2(int a, int cond, int op2, int disp22)
	{
		Format_2_1((a & 0x1) << 4 | (cond & 0xF), op2, disp22);
	}

	void CodegenMIR::Format_2_3(int a, int cond, int op2, int cc1, int cc0, int p, int disp19)
	{
		Format_2_2(a, cond, op2, (cc1 & 0x1) << 21 | (cc0 & 0x1) << 20 | (p & 0x1) << 19 | (disp19 & 0x7FFFF));
	}

	void CodegenMIR::Format_2_4(int a, int rcond, int op2, int d16hi, int p, Register rs1, int d16lo)
	{
		Format_2_2(a, (rcond & 0x7), op2, (d16hi & 0x3) << 20 | (p & 0x1) << 19 | rs1 << 14 | (d16lo & 0x3FFF));
	}

	void CodegenMIR::Format_3(int op1, Register rd, int op3, int bits19)
	{
		*mip++ = op1 << 30 | rd << 25 | op3 << 19 | (bits19 & 0x7FFFF);
	}

	void CodegenMIR::Format_3_1(int op1, Register rd, int op3, Register rs1, int bit8, Register rs2)
	{
		Format_3(op1, rd, op3, rs1 << 14 | (bit8 & 0xFF) << 5 | rs2);
	}

	void CodegenMIR::Format_3_1I(int op1, Register rd, int op3, Register rs1, int simm13)
	{
		Format_3(op1, rd, op3, rs1 << 14 | 1 << 13 | (simm13 & 0x1FFF));
	}

	void CodegenMIR::Format_3_2(int op1, Register rd, int op3, Register rs1, int rcond, Register rs2)
	{
		Format_3(op1, rd, op3, rs1 << 14 | (rcond & 0x3) << 10 | rs2);
	}

	void CodegenMIR::Format_3_2I(int op1, Register rd, int op3, Register rs1, int rcond, int simm10)
	{
		Format_3(op1, rd, op3, rs1 << 14 | 1 << 13 | (rcond & 0x3) << 10 | (simm10 & 0x1FFF));
	}

	void CodegenMIR::Format_3_3(int op1, Register rd, int op3, Register rs1, int cmask, int mmask)
	{
		Format_3(op1, rd, op3, rs1 << 14 | 1 << 13 | (cmask & 0x7) << 5 | (mmask & 0xF));
	}

	void CodegenMIR::Format_3_4(int op1, Register rd, int op3, int bits19)
	{
		Format_3(op1, rd, op3, bits19);
	}

	void CodegenMIR::Format_3_5(int op1, Register rd, int op3, Register rs1, int x, Register rs2)
	{
		Format_3(op1, rd, op3, rs1 << 14 | (x & 0x1) << 12 | rs2);
	}

	void CodegenMIR::Format_3_6(int op1, Register rd, int op3, Register rs1, int shcnt32)
	{
		Format_3(op1, rd, op3, rs1 << 14 | 1 << 13 | (shcnt32 & 0x3F));
	}

	void CodegenMIR::Format_3_7(int op1, Register rd, int op3, Register rs1, int shcnt64)
	{
		Format_3(op1, rd, op3, rs1 << 14 | 1 << 13 | 1 << 12 | (shcnt64 & 0x7F));
	}

	void CodegenMIR::Format_3_8(int op1, Register rd, int op3, Register rs1, int bits9, Register rs2)
	{
		Format_3(op1, rd, op3, rs1 << 14 | (bits9 & 0x1FF) << 5 | rs2);
	}

	void CodegenMIR::Format_3_9(int op1, int cc1, int cc0, int op3, Register rs1, int bits9, Register rs2)
	{
		Format_3(op1, (cc1 & 0x1) << 1 | (cc0 & 0x1), op3, rs1 << 14 | (bits9 & 0x1FF) << 5 | rs2);
	}

	void CodegenMIR::Format_4_1(Register rd, int op3, Register rs1, int cc1, int cc0, Register rs2)
	{
		Format_3(2, rd, op3, rs1 << 14 | (cc1 & 0x1) << 12 | (cc0 & 0x1) << 11 | rs2);
	}

	void CodegenMIR::Format_4_1I(Register rd, int op3, Register rs1, int cc1, int cc0, int simm11)
	{
		Format_3(2, rd, op3, rs1 << 14 | (cc1 & 0x1) << 12 | 1 << 13 |(cc0 & 0x1) << 11 | (simm11 & 0x7FF));
	}

	void CodegenMIR::Format_4_2(Register rd, int op3, int cc2, int cond, int cc1, int cc0, Register rs2)
	{
		Format_3(2, rd, op3, (cc2 & 0x1) << 18 | (cond & 0xF) << 14 | (cc1 & 0x1) << 12 | (cc0 & 0x1) << 11 | rs2);
	}

	void CodegenMIR::Format_4_2I(Register rd, int op3, int cc2, int cond, int cc1, int cc0, int simm11)
	{
		Format_3(2, rd, op3, (cc2 & 0x1) << 18 | (cond & 0xF) << 14 | 1 << 13 | (cc1 & 0x1) << 12 | (cc0 & 0x1) << 11 | (simm11 & 0x7FF));
	}

	void CodegenMIR::Format_4_3(Register rd, int op3, Register rs1, int cc1, int cc0, int swap_trap)
	{
		Format_3(2, rd, op3, rs1 << 14 | 1 << 13 | (cc1 & 0x1) << 12 | (cc0 & 0x1) << 11 | (swap_trap & 0x7F));
	}

	void CodegenMIR::Format_4_4(Register rd, int op3, Register rs1, int rcond, int opf_low, Register rs2)
	{
		Format_3(2, rd, op3, rs1 << 14 | (rcond & 0x7) << 10 | (opf_low & 0x1F) << 5 | rs2);
	}

	void CodegenMIR::Format_4_5(Register rd, int op3, int cond, int opf_cc, int opf_low, Register rs2)
	{
		Format_3(2, rd, op3, (cond & 0xF) << 14 | (opf_cc & 0x7) << 11 | (opf_low & 0x3F) << 5 | rs2);
	}

	void CodegenMIR::ADD(Register rs1, Register rs2, Register rd)
	{
		Format_3_1(2, rd, 0, rs1, 0, rs2);
	}

	void CodegenMIR::ADDI(Register rs1, int simm13, Register rd)
	{
		Format_3_1I(2, rd, 0, rs1, simm13);
	}

	void CodegenMIR::AND(Register rs1, Register rs2, Register rd)
	{
		Format_3_1(2, rd, 0x1, rs1, 0, rs2);
	}

	void CodegenMIR::ANDI(Register rs1, int simm13, Register rd)
	{
		Format_3_1I(2, rd, 0x1, rs1, simm13);
	}

	void CodegenMIR::BA(int a, int dsp22)
	{
		Format_2_2(a, 0x8, 0x2, dsp22);
	}

	void CodegenMIR::BE(int a, int dsp22)
	{
		Format_2_2(a, 0x1, 0x2, dsp22);
	}

	void CodegenMIR::BG(int a, int dsp22)
	{
		Format_2_2(a, 0xA, 0x2, dsp22);
	}

	void CodegenMIR::BGU(int a, int dsp22)
	{
		Format_2_2(a, 0xC, 0x2, dsp22);
	}

	void CodegenMIR::BGE(int a, int dsp22)
	{
		Format_2_2(a, 0xB, 0x2, dsp22);
	}

	void CodegenMIR::BGEU(int a, int dsp22)
	{
		Format_2_2(a, 0xD, 0x2, dsp22);
	}

	void CodegenMIR::BL(int a, int dsp22)
	{
		Format_2_2(a, 0x3, 0x2, dsp22);
	}

	void CodegenMIR::BLU(int a, int dsp22)
	{
		Format_2_2(a, 0x5, 0x2, dsp22);
	}

	void CodegenMIR::BLE(int a, int dsp22)
	{
		Format_2_2(a, 0x2, 0x2, dsp22);
	}

	void CodegenMIR::BLEU(int a, int dsp22)
	{
		Format_2_2(a, 0x4, 0x2, dsp22);
	}

	void CodegenMIR::BNE(int a, int dsp22)
	{
		Format_2_2(a, 0x9, 0x2, dsp22);
	}

	void CodegenMIR::FABSS(Register rs2, Register rd)
	{
		Format_3_8(2, rd, 0x34, 0, 0x9, rs2);
	}

	void CodegenMIR::FADDD(Register rs1, Register rs2, Register rd)
	{
		Format_3_8(2, rd, 0x34, rs1, 0x42, rs2);
	}

	void CodegenMIR::FBE(int a, int dsp22)
	{
		Format_2_2(a, 0x9, 0x6, dsp22);
	}

	void CodegenMIR::FBNE(int a, int dsp22)
	{
		Format_2_2(a, 0x1, 0x6, dsp22);
	}

	void CodegenMIR::FBUE(int a, int dsp22)
	{
		Format_2_2(a, 0xA, 0x6, dsp22);
	}

	void CodegenMIR::FBG(int a, int dsp22)
	{
		Format_2_2(a, 0x6, 0x6, dsp22);
	}

	void CodegenMIR::FBUG(int a, int dsp22)
	{
		Format_2_2(a, 0x5, 0x6, dsp22);
	}

	void CodegenMIR::FBGE(int a, int dsp22)
	{
		Format_2_2(a, 0xB, 0x6, dsp22);
	}

	void CodegenMIR::FBUGE(int a, int dsp22)
	{
		Format_2_2(a, 0xC, 0x6, dsp22);
	}

	void CodegenMIR::FBL(int a, int dsp22)
	{
		Format_2_2(a, 0x4, 0x6, dsp22);
	}

	void CodegenMIR::FBLE(int a, int dsp22)
	{
		Format_2_2(a, 0xD, 0x6, dsp22);
	}

	void CodegenMIR::FCMPD(Register rs1, Register rs2)
	{
		Format_3_9(2, 0, 0, 0x35, rs1, 0x52, rs2);
	}

	void CodegenMIR::FSUBD(Register rs1, Register rs2, Register rd)
	{
		Format_3_8(2, rd, 0x34, rs1, 0x46, rs2);
	}

	void CodegenMIR::FMULD(Register rs1, Register rs2, Register rd)
	{
		Format_3_8(2, rd, 0x34, rs1, 0x4a, rs2);
	}

	void CodegenMIR::FDIVD(Register rs1, Register rs2, Register rd)
	{
		Format_3_8(2, rd, 0x34, rs1, 0x4e, rs2);
	}

	void CodegenMIR::FMOVD(Register rs2, Register rd)
	{
		Format_3_8(2, rd, 0x34, 0, 0x2, rs2);
	}

	void CodegenMIR::FNEGD(Register rs2, Register rd)
	{
		Format_3_8(2, rd, 0x34, 0, 0x6, rs2);
	}

	void CodegenMIR::FITOD(Register rs2, Register rd)
	{
		Format_3_8(2, rd, 0x34, 0, 0xc8, rs2);
	}

	void CodegenMIR::JMPL(Register rs1, Register rs2, Register rd)
	{
		Format_3_1(2, rd, 0x38, rs1, 0, rs2);
	}

	void CodegenMIR::JMPLI(Register rs1, int simm13, Register rd)
	{
		Format_3_1I(2, rd, 0x38, rs1, simm13);
	}

	void CodegenMIR::LDF(Register rs1, Register rs2, Register rd)
	{
		if(rs1 == Unknown)
			rs1 = G0;
		Format_3_1(3, rd, 0x20, rs1, 0, rs2);
	}

	void CodegenMIR::LDFI(Register rs1, int simm13, Register rd)
	{
		if(rs1 == Unknown)
			rs1 = G0;
		Format_3_1I(3, rd, 0x20, rs1, simm13);
	}

	void CodegenMIR::LDSW(Register rs1, Register rs2, Register rd)
	{
		if(rs1 == Unknown)
			rs1 = G0;
		Format_3_1(3, rd, 0x8, rs1, 0, rs2);
	}

	void CodegenMIR::LDSWI(Register rs1, int simm13, Register rd)
	{
		if(rs1 == Unknown)
			rs1 = G0;
		Format_3_1I(3, rd, 0x8, rs1, simm13);
	}

	void CodegenMIR::MULX(Register rs1, Register rs2, Register rd)
	{
		Format_3_1(2, rd, 0x9, rs1, 0, rs2);
	}

	void CodegenMIR::MULXI(Register rs1, int simm13, Register rd)
	{
		Format_3_1I(2, rd, 0x9, rs1, simm13);
	}

	void CodegenMIR::NOP()
	{
		Format_2_1(0, 0x4, 0);
	}

	void CodegenMIR::OR(Register rs1, Register rs2, Register rd)
	{
		Format_3_1(2, rd, 0x2, rs1, 0, rs2);
	}

	void CodegenMIR::ORI(Register rs1, int simm13, Register rd)
	{
		Format_3_1I(2, rd, 0x2, rs1, simm13);
	}

	void CodegenMIR::RD(Register rs1, Register rd)
	{
		Format_3_1(2, rd, 0x28, rs1, 0, 0);
	}

	void CodegenMIR::RESTORE(Register rs1, Register rs2, Register rd)
	{
		Format_3_1(2, rd, 0x3D, rs1, 0, rs2);
	}

	void CodegenMIR::SAVEI(Register rs1, int simm13, Register rd)
	{
		Format_3_1I(2, rd, 0x3C, rs1, simm13);
	}

	void CodegenMIR::SETHI(int imm22, Register rd)
	{
		Format_2_1(rd, 0x4, (imm22 >> 10));
	}

	void CodegenMIR::SLL(Register rs1, Register rs2, Register rd)
	{
		Format_3_5(2, rd, 0x25, rs1, 0, rs2);
	}

	void CodegenMIR::SLLI(Register rs1, int shcnt32, Register rd)
	{
		Format_3_6(2, rd, 0x25, rs1, shcnt32);
	}

	void CodegenMIR::SRA(Register rs1, Register rs2, Register rd)
	{
		Format_3_5(2, rd, 0x27, rs1, 0, rs2);
	}

	void CodegenMIR::SRAI(Register rs1, int shcnt32, Register rd)
	{
		Format_3_6(2, rd, 0x27, rs1, shcnt32);
	}

	void CodegenMIR::SRL(Register rs1, Register rs2, Register rd)
	{
		Format_3_5(2, rd, 0x26, rs1, 0, rs2);
	}

	void CodegenMIR::SRLI(Register rs1, int shcnt32, Register rd)
	{
		Format_3_6(2, rd, 0x26, rs1, shcnt32);
	}

	void CodegenMIR::STF(Register rd, Register rs1, Register rs2)
	{
		if(rs1 == Unknown)
			rs1 = G0;
		Format_3_1(3, rd, 0x24, rs1, 0, rs2);
	}

	void CodegenMIR::STFI(Register rd, int simm13, Register rs1)
	{
		if(rs1 == Unknown)
			rs1 = G0;
		Format_3_1I(3, rd, 0x24, rs1, simm13);
	}

	void CodegenMIR::STW(Register rd, Register rs2, Register rs1)
	{
		if(rs1 == Unknown)
			rs1 = G0;
		Format_3_1(3, rd, 0x4, rs1, 0, rs2);
	}

	void CodegenMIR::STWI(Register rd, int simm13, Register rs1)
	{
		if(rs1 == Unknown)
			rs1 = G0;
		Format_3_1I(3, rd, 0x4, rs1, simm13);
	}

	void CodegenMIR::SUBCC(Register rs1, Register rs2, Register rd)
	{
		Format_3_1(2, rd, 0x14, rs1, 0, rs2);
	}

	void CodegenMIR::SUBCCI(Register rs1, int simm13, Register rd)
	{
		Format_3_1I(2, rd, 0x14, rs1, simm13);
	}

	void CodegenMIR::SUB(Register rs1, Register rs2, Register rd)
	{
		Format_3_1(2, rd, 0x4, rs1, 0, rs2);
	}

	void CodegenMIR::SUBI(Register rs1, int simm13, Register rd)
	{
		Format_3_1I(2, rd, 0x4, rs1, simm13);
	}

	void CodegenMIR::XOR(Register rs1, Register rs2, Register rd)
	{
		Format_3_1(2, rd, 0x3, rs1, 0, rs2);
	}

	void CodegenMIR::XORI(Register rs1, int simm13, Register rd)
	{
		Format_3_1I(2, rd, 0x3, rs1, simm13);
	}

#endif //AVMPLUS_SPARC
}
