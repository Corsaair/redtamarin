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

namespace avmplus
{
#ifdef AVMPLUS_WORD_CODE
	using namespace MMgc;
	
	class TranslatedCode : public GCObject
	{
	public:
		uintptr_t data[1];  // more follows
	};

#ifdef AVMPLUS_DIRECT_THREADED
	WordcodeEmitter::WordcodeEmitter(MethodInfo* info, void** opcode_labels)
#else
	WordcodeEmitter::WordcodeEmitter(MethodInfo* info)
#endif
		: WordcodeTranslator()
		, info(info)
		, core(info->core())
		, backpatches(NULL)
		, labels(NULL)
		, exception_fixes(NULL)
		, buffers(NULL)
		, buffer_offset(0)
		, spare_buffer(NULL)
#ifdef AVMPLUS_DIRECT_THREADED
		, opcode_labels(opcode_labels)
#endif
		, exceptions_consumed(false)
		, dest(NULL)
		, dest_limit(NULL)
		, pool(NULL)
		, code_start(NULL)
	{
		AvmAssert(info != NULL);

		const byte* pos = info->body_pos;
		AvmCore::skipU30(pos, 5);  // max_stack, local_count, init_scope_depth, max_scope_depth, code_length
		code_start = pos;
		pool = info->pool;
		
		boot();
	}

#ifdef AVMPLUS_SELFTEST
#  ifdef AVMPLUS_DIRECT_THREADED
	WordcodeEmitter::WordcodeEmitter(AvmCore* core, uint8_t* code_start, void** opcode_labels)
#  else
	WordcodeEmitter::WordcodeEmitter(AvmCore* core, uint8_t* code_start)
#  endif

		: WordcodeTranslator()
		, info(info)
		, core(core)
		, backpatches(NULL)
		, labels(NULL)
		, exception_fixes(NULL)
		, buffers(NULL)
		, buffer_offset(0)
		, spare_buffer(NULL)
#ifdef AVMPLUS_DIRECT_THREADED
		, opcode_labels(opcode_labels)
#endif
		, exceptions_consumed(false)
		, dest(NULL)
		, dest_limit(NULL)
		, pool(NULL)
		, code_start(code_start)
	{
		boot();
	}
	
#endif // AVMPLUS_SELFTEST
	
	void WordcodeEmitter::boot() {
		if (pool != NULL && pool->word_code.cpool_mn == NULL)
			pool->word_code.cpool_mn = new (sizeof(PrecomputedMultinames) + (pool->constantMnCount - 1)*sizeof(Multiname)) PrecomputedMultinames(core->GetGC(), pool);
		computeExceptionFixups();
		refill();
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
		peepInit();
#endif
	}
	
	WordcodeEmitter::~WordcodeEmitter()
	{
		cleanup();
	}

#define DELETE_LIST(T, v) \
	do { \
		T* tmp1 = v; \
		while (tmp1 != NULL) { \
			T* tmp2 = tmp1; \
			tmp1 = tmp1->next; \
			delete tmp2; \
		} \
		v = NULL; \
	} while (0)
	
	void WordcodeEmitter::cleanup() 
	{
		DELETE_LIST(backpatch_info, backpatches);
		DELETE_LIST(label_info, labels);
		DELETE_LIST(catch_info, exception_fixes);
		DELETE_LIST(buffer_info, buffers);
		if (spare_buffer) {
			delete spare_buffer;
			spare_buffer = NULL;
		}
	}
	
	void WordcodeEmitter::refill() 
	{
		if (buffers != NULL) {
			buffers->entries_used = int(dest - buffers->data);
			buffer_offset += buffers->entries_used;
		}
		buffer_info* b;
		if (spare_buffer != NULL) {
			b = spare_buffer;
			spare_buffer = NULL;
		}
		else
			b = new buffer_info;
		b->next = buffers;
		buffers = b;
		dest = b->data;
		dest_limit = dest + sizeof(b->data)/sizeof(b->data[0]);
	}
	
	void WordcodeEmitter::emitRelativeOffset(uintptr_t base_offset, const uint8_t *base_pc, intptr_t offset) 
	{
		if (offset < 0) {
			// There must be a label for the target location
			uintptr_t old_offset = uintptr_t((base_pc - code_start) + offset);
			label_info* l = labels;
			while (l != NULL && l->old_offset != old_offset)
				l = l->next;
			AvmAssert(l != NULL);
			*dest++ = l->new_offset - base_offset;
		}
		else
			makeAndInsertBackpatch(base_pc + offset, base_offset);
	}
	
	void WordcodeEmitter::makeAndInsertBackpatch(const uint8_t* target_pc, uintptr_t patch_offset)
	{
		// Leave a backpatch for the target location.  Backpatches are sorted in
		// increasing address order always.
		backpatch_info* b = new backpatch_info;
		b->target_pc = target_pc;
		b->patch_loc = dest;
		b->patch_offset = patch_offset;
		backpatch_info* q = backpatches;
		backpatch_info* qq = NULL;
		while (q != NULL && q->target_pc < b->target_pc) {
			qq = q;
			q = q->next;
		}
		if (qq == NULL) {
			b->next = backpatches;
			backpatches = b;
		}
		else {
			b->next = q;
			qq->next = b;
		}
		*dest++ = 0x80000000U;
	}
	
	void WordcodeEmitter::computeExceptionFixups() 
	{
		if (info == NULL || info->exceptions == NULL)
			return;
		
		DELETE_LIST(catch_info, exception_fixes);
		
		ExceptionHandlerTable* old_table = info->exceptions;
		int exception_count = old_table->exception_count;
		size_t extra = sizeof(ExceptionHandler)*(exception_count - 1);
		ExceptionHandlerTable* new_table = new (core->GetGC(), extra) ExceptionHandlerTable(exception_count);
		
		// Insert items in the exn list for from, to, and target, with the pc pointing
		// to the correct triggering instruction in the ABC and the update loc
		// pointing to the location to be patched; and a flag is_int_offset (if false
		// it's a intptr_t).
		
		for ( int i=0 ; i < exception_count ; i++ ) {
			
			new_table->exceptions[i].traits = old_table->exceptions[i].traits;
			new_table->exceptions[i].scopeTraits = old_table->exceptions[i].scopeTraits;
			
			catch_info* p[3];
			
			p[0] = new catch_info;
			p[0]->pc = code_start + info->exceptions->exceptions[i].from;
			p[0]->is_target = false;
			p[0]->fixup_loc = (void*)&(new_table->exceptions[i].from);
			
			p[1] = new catch_info;
			p[1]->pc = code_start + info->exceptions->exceptions[i].to;
			p[1]->is_target = false;
			p[1]->fixup_loc = (void*)&(new_table->exceptions[i].to);
			
			p[2] = new catch_info;
			p[2]->pc = code_start + info->exceptions->exceptions[i].target;
			p[2]->is_target = true;
			p[2]->fixup_loc = (void*)&(new_table->exceptions[i].target);
			
			if (p[0]->pc > p[1]->pc) {
				catch_info* tmp = p[0];
				p[0] = p[1];
				p[1] = tmp;
			}
			if (p[1]->pc > p[2]->pc) {
				catch_info* tmp = p[1];
				p[1] = p[2];
				p[2] = tmp;
			}
			if (p[0]->pc > p[1]->pc) {
				catch_info* tmp = p[0];
				p[0] = p[1];
				p[1] = tmp;
			}
			
			int j=0;
			catch_info* e = exception_fixes;
			catch_info* ee = NULL;
			while (j < 3 && e != NULL) {
				if (e->pc > p[j]->pc) {
					if (ee == NULL) 
						exception_fixes = p[j];
					else 
						ee->next = p[j];
					p[j]->next = e;
					e = p[j];
					j++;
				}
				else {
					ee = e;
					e = e->next;
				}
			}
			while (j < 3) {
				if (ee == NULL) 
					exception_fixes = p[j];
				else 
					ee->next = p[j];
				p[j]->next = e;
				ee = p[j];
				j++;
			}
		}
		
		WB(core->GetGC(), info, &info->word_code.exceptions, new_table);
		
#ifdef _DEBUG
		if (exception_fixes != NULL) {
			catch_info* ee = exception_fixes;
			catch_info* e = ee->next;
			AvmAssert(ee->pc <= e->pc);
			ee = e;
			e = e->next;
		}
#endif
	}

	void WordcodeEmitter::fixExceptionsAndLabels(const uint8_t *pc) 
	{
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
		// Do not optimize across control flow targets, so flush the peephole window here
		if (exception_fixes != NULL && exception_fixes->pc == pc || backpatches != NULL && backpatches->target_pc == pc)
			peepFlush();
#endif

		while (exception_fixes != NULL && exception_fixes->pc <= pc) {
			AvmAssert(exception_fixes->pc == pc);
			exceptions_consumed = true;
			if (exception_fixes->is_target)
				*(intptr_t*)(exception_fixes->fixup_loc) = (intptr_t)(buffer_offset + (dest - buffers->data));
			else
				*(int*)(exception_fixes->fixup_loc) = (int)(buffer_offset + (dest - buffers->data));
			catch_info* tmp = exception_fixes;
			exception_fixes = exception_fixes->next;
			delete tmp;
		}
		
		while (backpatches != NULL && backpatches->target_pc <= pc) {
			AvmAssert(backpatches->target_pc == pc);
			AvmAssert(*backpatches->patch_loc == 0x80000000U);
			*backpatches->patch_loc = (intptr_t)buffer_offset + (intptr_t)(dest - buffers->data) - (intptr_t)backpatches->patch_offset;
			backpatch_info* tmp = backpatches;
			backpatches = backpatches->next;
			delete tmp;
		}
	}
	
#define CHECK(n) \
		if (dest+n > dest_limit) refill();

	// These take no arguments
	void WordcodeEmitter::emitOp0(const uint8_t *pc, WordOpcode opcode) {
#ifdef _DEBUG
		AvmAssert(wopAttrs[opcode].width == 1);
#endif // _DEBUG
		(void)pc;
		CHECK(1);
		*dest++ = NEW_OPCODE(opcode);
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
		peep(opcode, dest-1);
#endif
	}

	// These take one U30 argument
	void WordcodeEmitter::emitOp1(const uint8_t *pc, WordOpcode opcode)
	{
#ifdef _DEBUG
		AvmAssert(wopAttrs[opcode].width == 2);
#endif // _DEBUG
		CHECK(2);
		pc++;
		*dest++ = NEW_OPCODE(opcode);
		*dest++ = (intptr_t)(int32_t)AvmCore::readU30(pc);
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
		peep(opcode, dest-2);
#endif
	}
	
	// These take one U30 argument, and the argument is explicitly passed here (result of optimization)
	void WordcodeEmitter::emitOp1(WordOpcode opcode, uint32_t operand)
	{
#ifdef _DEBUG
		AvmAssert(wopAttrs[opcode].width == 2);
#endif // _DEBUG
		CHECK(2);
		*dest++ = NEW_OPCODE(opcode);
		*dest++ = (intptr_t)(int32_t)operand;
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
		peep(opcode, dest-2);
#endif
	}
	
	// These take two U30 arguments
	void WordcodeEmitter::emitOp2(const uint8_t *pc, WordOpcode opcode)
	{
#ifdef _DEBUG
		AvmAssert(wopAttrs[opcode].width == 3);
#endif
		CHECK(3);
		pc++;
		*dest++ = NEW_OPCODE(opcode);
		*dest++ = (intptr_t)(int32_t)AvmCore::readU30(pc);
		*dest++ = (intptr_t)(int32_t)AvmCore::readU30(pc);
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
		peep(opcode, dest-3);
#endif
	}
	
	void WordcodeEmitter::emitOp2(WordOpcode opcode, uint32_t op1, uint32_t op2)
	{
#ifdef _DEBUG
		AvmAssert(wopAttrs[opcode].width == 3);
#endif
		CHECK(3);
		*dest++ = NEW_OPCODE(opcode);
		*dest++ = (intptr_t)(int32_t)op1;
		*dest++ = (intptr_t)(int32_t)op2;
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
		peep(opcode, dest-3);
#endif
	}

	
	// These take one S24 argument that is PC-relative.  If the offset is negative
	// then the target must be a LABEL instruction, and we can just look it up.
	// Otherwise, we enter the target offset into an ordered list with the current
	// transformed PC and the location to backpatch.
	void WordcodeEmitter::emitRelativeJump(const uint8_t *pc, WordOpcode opcode)
	{
#ifdef _DEBUG
		AvmAssert(wopAttrs[opcode].jumps);
#endif
		CHECK(2);
		pc++;
		intptr_t offset = (intptr_t)AvmCore::readS24(pc);
		pc += 3;
		*dest++ = NEW_OPCODE(opcode);
		uintptr_t base_offset = uintptr_t(buffer_offset + (dest - buffers->data) + 1);
		emitRelativeOffset(base_offset, pc, offset);
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
		peep(opcode, dest-2);
		AvmAssert(state == 0);		// Never allow a jump instruction to be in the middle of a match
#endif
	}
	
	void WordcodeEmitter::emitLabel(const uint8_t *pc) 
	{
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
		// Do not optimize across control control flow targets, so flush the peephole window here.
		peepFlush();
#endif
		label_info* l = new label_info;
		l->old_offset = uint32_t(pc - code_start);
		l->new_offset = uint32_t(buffer_offset + (dest - buffers->data));
		l->next = labels;
		labels = l;
	}

#ifdef DEBUGGER
	void WordcodeEmitter::emitDebug(const uint8_t *pc) 
	{
		CHECK(5);
		pc++;
		uint8_t debug_type = *pc++;
		uint32_t index = AvmCore::readU30(pc);
		uint8_t reg = *pc++;
		uint32_t extra = AvmCore::readU30(pc);
		// 4 separate operands to match the value in the operand count table,
		// though obviously we could pack debug_type and reg into one word and
		// we could also omit extra.
		*dest++ = NEW_OPCODE(OP_debug);
		*dest++ = debug_type;
		*dest++ = (intptr_t)(int32_t)index;
		*dest++ = (intptr_t)(int32_t)reg;
		*dest++ = (intptr_t)(int32_t)extra;
	}
#endif
	
	void WordcodeEmitter::emitPushbyte(const uint8_t *pc) 
	{
		CHECK(2);
		pc++;
		*dest++ = NEW_OPCODE(WOP_pushbits);
		*dest++ = (intptr_t)(((int8_t)*pc++) << 3) | kIntegerType;
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
		peep(WOP_pushbits, dest-2);
#endif
	}
	
	void WordcodeEmitter::emitPushshort(const uint8_t *pc) 
	{
		CHECK(2);
		pc++;
		*dest++ = NEW_OPCODE(WOP_pushbits);
		*dest++ = (intptr_t)((int16_t)AvmCore::readU30(pc) << 3) | kIntegerType;
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
		peep(WOP_pushbits, dest-2);
#endif
	}
	
	void WordcodeEmitter::emitGetscopeobject(const uint8_t *pc) 
	{
		CHECK(2);
		pc++;
		*dest++ = NEW_OPCODE(OP_getscopeobject);
		*dest++ = *pc++;
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
		peep(OP_getscopeobject, dest-2);
#endif
	}
	
	void WordcodeEmitter::emitPushint(const uint8_t *pc)
	{
		// FIXME: wrong for 64-bit, we want 32 bits of payload
		pc++;
		int32_t value = pool->cpool_int[AvmCore::readU30(pc)];
		if ((value & 0xF0000000U) == 0xF0000000U || (value & 0xF0000000U) == 0) {
			CHECK(2);
			*dest++ = NEW_OPCODE(WOP_pushbits);
			*dest++ = (value << 3) | kIntegerType;
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
			peep(WOP_pushbits, dest-2);
#endif
		}
		else {
			union {
				double d;
				uint32_t bits[2];
			} v;
			v.d = (double)value;
			CHECK(3);
			*dest++ = NEW_OPCODE(WOP_push_doublebits);
			*dest++ = v.bits[0];
			*dest++ = v.bits[1];
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
			peep(WOP_push_doublebits, dest-3);
#endif
		}
	}

	void WordcodeEmitter::emitPushuint(const uint8_t *pc)
	{
		// FIXME: wrong for 64-bit, we want 32 bits of payload
		pc++;
		uint32_t value = pool->cpool_uint[AvmCore::readU30(pc)];
		if ((value & 0xF0000000U) == 0) {
			CHECK(2);
			*dest++ = NEW_OPCODE(WOP_pushbits);
			*dest++ = (value << 3) | kIntegerType;
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
			peep(WOP_pushbits, dest-2);
#endif
		}
		else {
			union {
				double d;
				uint32_t bits[2];
			} v;
			v.d = (double)value;
			CHECK(3);
			*dest++ = NEW_OPCODE(WOP_push_doublebits);
			*dest++ = v.bits[0];
			*dest++ = v.bits[1];
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
			peep(WOP_push_doublebits, dest-3);
#endif
		}
	}
	
	void WordcodeEmitter::emitLookupswitch(const uint8_t *pc)
	{
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
		// Avoid a lot of hair by flushing before LOOKUPSWITCH and not peepholing after.
		peepFlush();
#endif
		const uint8_t* base_pc = pc;
		pc++;
		uint32_t base_offset = uint32_t(buffer_offset + (dest - buffers->data));
		intptr_t default_offset = AvmCore::readS24(pc);
		pc += 3;
		uint32_t case_count = AvmCore::readU30(pc);
		CHECK(3);
		*dest++ = NEW_OPCODE(OP_lookupswitch);
		emitRelativeOffset(base_offset, base_pc, default_offset);
		*dest++ = case_count;
		
		for ( uint32_t i=0 ; i <= case_count ; i++ ) {
			intptr_t offset = AvmCore::readS24(pc);
			pc += 3;
			CHECK(1);
			emitRelativeOffset(base_offset, base_pc, offset);
		}
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
		// need a forward declaration for toplevel.
//		AvmAssert(toplevel[OP_lookupswitch] == 0);
#endif
	}
	
	// 'OP_abs_jump' is an ABC-only construct, it boils away in the translation,
	// both here and to MIR/LIR.  It says: My first operand (one word in 32-bit
	// mode, two words in 64-bit mode) is a raw pointer into a buffer of ABC code.
	// My second operand is the number of bytes of code starting at that address.
	// Continue translating from that address as if it were a linear part
	// of the current code vector.  In other words, it's a forwarding pointer.
	
	void WordcodeEmitter::emitAbsJump(const uint8_t *new_pc)
	{
		code_start = new_pc;
		
		// When performing a jump:
		//  - require that backpatches and labels no longer reference the old
		//    code vector; those sets must both be empty.  (We could clear out
		//    labels, alternatively, but that appears not to be required.)
		//  - recompute all the exception information, and require that none of it
		//    has been consumed -- this is the only thing that makes sense, and appears
		//    to be the view the verifier sanctions.  (A full definition for the
		//    semantics of abs_jump is sorely needed.)
		
		AvmAssert(!exceptions_consumed);
		AvmAssert(backpatches == NULL);
		AvmAssert(labels == NULL);
		computeExceptionFixups();
	}
	
	uint32 WordcodeEmitter::epilogue(uintptr_t** code_result)
	{
		AvmAssert(backpatches == NULL);
		AvmAssert(exception_fixes == NULL);
		
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
		peepFlush();
#endif

		buffers->entries_used = uint32_t(dest - buffers->data);
		uint32_t total_size = buffer_offset + buffers->entries_used;
		
		TranslatedCode* code_anchor = (TranslatedCode*)core->GetGC()->Alloc(sizeof(TranslatedCode) + (total_size - 1)*sizeof(uintptr_t), GC::kZero);
		uintptr_t* code = code_anchor->data;
		
		// reverse the list of buffers
		buffer_info* first = buffers;
		buffer_info* next = first->next;
		first->next = NULL;
		while (next != NULL) {
			buffer_info* tmp = next->next;
			next->next = first;
			first = next;
			next = tmp;
		}
		buffers = first;
		
		// move the data
		uintptr_t* ptr = code;
		while (first != NULL) {
			memcpy(ptr, first->data, first->entries_used*sizeof(uintptr_t));
			ptr += first->entries_used;
			first = first->next;
		}
		AvmAssert(ptr == code + total_size);
		
		if (info != NULL) {
			info->word_code.code_anchor = code_anchor;
			info->codeStart = code;
#ifdef SUPERWORD_PROFILING
			WordcodeTranslator::swprofCode(code, code + total_size);
#endif
		}
		
		cleanup();
		if (code_result != NULL)
			*code_result = code;
		return total_size;
	}

#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
	
	// Peephole optimization.
	//
	//
	// DESCRIPTION.  This is a deterministic state machine driven peephole optimizer.  The  
	// machine attempts to match a set of patterns against a prefix of the instruction 
	// stream, replacing matched patterns by new strings of instructions (usually shorter
	// or faster ones) -- a "reduction".  A reduction is possible when the machine enters
	// a final state.  However, the machine is greedy and may leave the final state 
	// looking for a longer match.  As the longer match may fail, the machine maintains
	// a stack of final states it may backtrack to.  A match may fail in two ways, either
	// because a state is reached from which there is no move to a final state on the
	// actual input, or if a final state is reached but the guard condition for the
	// state is not satisfied.  The guard is only tested when the machine is ready to
	// commit; for that reason, a stack of backtrack states is required (instead of a
	// single backtrack state).  The guard is mixed in with the commit code in order to
	// keep code size down, though it probably does not matter much.
	//
	// Instructions inserted by reductions are not subject to repeated matching (though
	// they could be).
	//
	// In order to handle patterns that are subpatterns but not prefixes of other patterns,
	// a special failure transition is encoded in each state and used if the matcher fails
	// at that state.
	//
	// The peephole optimizer function peep() /must/ be called every time an instruction 
	// has been emitted to the instruction stream, as the state machine in the peephole
	// optimizer tracks the emitted instruction stream (it does not inspect it repeatedly).
	// The operands to peep() are the symbolic opcode that was just emitted and the address
	// at which that opcode was emitted.  The function peep() drives the state machine.
	//
	// If optimization must not cross some instruction boundary (for example it must not
	// merge the instruction at a control flow target with the previous instruction)
	// then peepFlush() must be called before instructions are emitted for the point beyond
	// the boundary.  This must also be called at the end of the instruction stream, and for
	// instructions that must not appear in the peephole window (currently only LOOKUPSWITCH).
	//
	// The tables 'states', 'transitions', and 'toplevel' are generated by the program 
	// utils/peephole.as based on the patterns described in core/peephole.tbl, which are
	// in turn hand-selected with aid of the dynamic instruction profiling infrastructure
	// built into Tamarin - see comments in utils/superwordprof.c for help on how to use that.
	//
	// It is possible to optimize the entry to peep(), the in-line test is 
	//
	//     state==0 && toplevel[toplevel_index] == 0
	//
	// where toplevel_index is computed from the opcode, maybe worth simplifying that in 
	// order to make this test faster.  Anyhow, if the test is true then peep() need 
	// not be called as there will not be a state transition.  This factoid may be useful
	// if emitOp0, emitOp1, and emitOp2 are in-lined into the verifier.
	//
	//
	// OPTIMALITY.  We wish to establish that if there is a stream of instructions s1, s2, ...
	// and patterns p1, p2, ... then (a) if some p matches a prefix of the stream then
	// the algorithm finds the match; (b) if several p match a prefix of the stream then
	// (one of) the longest p is chosen, subject to guard evaluation; (c) the
	// properties (a) and (b) hold for the remainder of the stream when the instructions
	// matching the pattern are removed from the stream; and (d) the properties (a) and (b)
	// hold for the remainder of the stream if no patterns match the prefix and the first
	// instruction is removed from the stream.
	//
	// Note that the optimality result - if established - does not imply that the "best"
	// match (the one that produces the fewest instructions, or the one that minimizes
	// stack pointer updates, or maximizes intra-instruction optimization in the C compiler,
	// or is best according to any criteria like that) is found, since a best match can
	// sometimes be obtained by choosing a shorter match against a prefix in order
	// to make a longer match possible subsequently.  It only implies that we do as well
	// as we can with a greedy matching strategy.
	//
	// Sketch of proof of optimality:
	//
	// To establish (a) and (b), note that the automaton tracks the prefix of the instruction
	// stream and stacks all accepting states.  If it reaches a state without a successor
	// (whether it's successor-less or the input has no transition from the current state) 
	// then the stacked states are tried in longest-first (reverse) order, and the longest
	// match wins.  (The failure state is not visited if there are accepting stacked states,
	// and does not interfere.)
	// 
	// To establish (c), note that the automaton consumes exactly the instructions that
	// were matched, then sets state=0 and re-emits the non-matched instructions, running
	// the automaton by calling peep() for each non-matched instruction.  If this succeeds 
	// then (a) and (b) apply; if it fails, (d) applies.  Either way the automaton
	// eventually consumes all of the originally non-matching instructions, after which it
	// is once again driven by instructions pushed into the peephole window.
	//
	// To establish (d), note that the automaton makes a failure transition if no match
	// could be made, and that the failure transition by construction (see utils/peephole.as)
	// discards the fewest possible instructions from the prefix of the stream: those that 
	// will not match any pattern, given that the present pattern failed.  Thus matching
	// will start at the earlies possible point, and (a), (b), (c), or (d) apply.
	//
	// Then, observe that peepFlush() commits to the longest match possible at the time
	// it is called, and then skips the remaining instructions.  By definition, the
	// skipped instructions cannot be matched (or they would have been part of the "longest
	// match possible").  Thus peepFlush() preserve (a) and (b).
	//
	// Finally, observe that peepFlush() is called following the last instruction emitted
	// in order to commit to the longest prefix of the instructions still in the peephole
	// window.
	
	void WordcodeEmitter::peepInit()
	{
		state = 0;
	}
	
	// Replace old instructions with new words of code.  This is tail called from the 
	// generated commit() function (see peephole.cpp).
	//
	// Invariants here:
	//
	//   - Lookupswitch never appears in the peephole window (reduces complexity
	//     and guarantees we won't ever have more than one buffer boundary crossing)
	//
	//   - Relative branch instructions only ever appear as the last instruction in 
	//     the window.  At that point, if it is a forward branch, then the backpatch
	//     may not be the first backpatch in the list, but it will usually be near
	//     the beginning (most branches are short).  Backpatches are uniquely 
	//     identified by the patch location they point to so it's always safe to
	//     remove one if we're squashing a branch instruction.
	//
	//     That means that if the peephole optimizer processes a branch instruction
	//     then it /must/ reduce at that point, it can't wait until the next
	//     instruction even if the current state is a final state.
	//
	//   - If the optimizer inserts a branch then the address in the branch must
	//     be absolute.  If the branch is backward it must be the negative of the
	//     absolute word offset of the target.  If the branch is forward it must
	//     be the positive absolute ABC byte offset of the branch target; a backpatch
	//     structure will be created in the latter case.
	
	bool WordcodeEmitter::replace(uint32_t old_instr, uint32_t new_words, bool jump_has_been_translated) 
	{
		// Undo any relative offsets in the last instruction, if that wasn't done by
		// the commit code.

		if (isJumpInstruction(O[nextI - 1]) && !jump_has_been_translated)
			undoRelativeOffsetInJump();
		
		// Catenate unconsumed instructions onto R (it's easier than struggling with
		// moving instructions across buffer boundaries)

		uint32_t k = new_words;
		for ( uint32_t n=old_instr ; n < nextI ; n++ ) {
			uint32_t len = calculateInstructionWidth(O[n]);
			S[k] = O[n];
			for ( uint32_t j=0 ; j < len ; j++ )
				R[k++] = I[n][j];
		}
		
		// Unlink the last buffer segment if we took everything from it, push it onto
		// a reserve (there can only ever be one free).  We know I[nextI-1] points into the
		// current buffer, so check if I[0] is between the start of the buffer and
		// the last instruction.
		
		if (!(buffers->data <= I[0] && I[0] <= I[nextI-1])) {
			spare_buffer = buffers;
			buffers = buffers->next;
			spare_buffer->next = NULL;
			dest_limit = buffers->data + sizeof(buffers->data)/sizeof(buffers->data[0]);
			buffer_offset -= buffers->entries_used;
		}
		dest = I[0];
		
		// Emit the various instructions from new_data, handling branches specially.
		//
		// At this point the instance variables state, I, O, nextI, backtrack_stack,
		// and backtrack_idx are dead, and all the data we need for emitting the
		// instructions are in S and R.  In addition, dest has been rolled back and
		// points to the address of the first instruction in the peephole window, and
		// nothing is live in the code buffer beyond that point.  It's as if we are
		// in a context where we're just emitting instructions.
		//
		// Consequently, we set state to 0 and start emitting instructions from S/R
		// normally, calling peep() after each instruction that was not replaced by
		// the current action.  This works without having local copies of S and R
		// because peephole optimization cannot insert a replacement sequence that is 
		// longer than the matched sequence; so the segments of S and R used by any
		// recursive match will not affect what we're doing here.  Furthermore, 'dest'
		// is shared between this match and recursive matches, so if a recursive match
		// shortens the instruction sequence the correct value of dest will be used
		// when we get back to the present invocation of replace().

		// Reset the machine.
		
		state = 0;
		
		uint32_t i=0;
		while (i < k) {
			uintptr_t op = S[i];
			uintptr_t width = calculateInstructionWidth(op);
			CHECK(width);
			if (isJumpInstruction(op)) {
				*dest++ = R[i++];
				int32_t offset = int32_t(R[i++]);
				if (offset >= 0) {
					// Forward jump
					// Install a new backpatch structure
					makeAndInsertBackpatch(code_start + offset, uint32_t(buffer_offset + (dest + (width - 1) - buffers->data)));
				}
				else {
					// Backward jump
					// Compute new jump offset
					*dest = -int32_t(buffer_offset + (dest + (width - 1) - buffers->data) + offset);
					dest++;
				}
				if (width >= 3)
					*dest++ = R[i++];
				if (width >= 4)
					*dest++ = R[i++];
				AvmAssert(width <= 4);
			}
			else {
				switch (width) {
					default:
						AvmAssert(!"Can't happen");
					case 1:
						*dest++ = R[i++];
						break;
					case 2:
						*dest++ = R[i++];
						*dest++ = R[i++];
						break;
					case 3:
						*dest++ = R[i++];
						*dest++ = R[i++];
						*dest++ = R[i++];
						break;
					case 5:  // OP_debug
						*dest++ = R[i++];
						*dest++ = R[i++];
						*dest++ = R[i++];
						*dest++ = R[i++];
						*dest++ = R[i++];
						break;
				}
			}
			if (i-width >= new_words)
				peep((uint32_t)op, dest-width);
		}
		
		return true;  // always
	}

	void WordcodeEmitter::undoRelativeOffsetInJump()
	{
		AvmAssert(isJumpInstruction(O[nextI - 1]));
		AvmAssert(I[nextI - 1] + 2 == dest);
		
		uintptr_t offset = I[nextI - 1][1];
		if (offset == 0x80000000U) {
			// Forward branch, must find and nuke the backpatch
			backpatch_info *b = backpatches;
			backpatch_info *b2 = NULL;
			while (b != NULL && b->patch_loc != &I[nextI - 1][1])
				b2 = b, b = b->next;
			AvmAssert(b != NULL);
			if (b2 == NULL)
				backpatches = b->next;
			else
				b2->next = b->next;
			// b is unlinked
			// Install the ABC byte offset from the backpatch structure (will be positive)
			I[nextI - 1][1] = uint32_t(b->target_pc - code_start);
			delete b;
		}
		else {
			// Backward branch
			AvmAssert((int32_t)I[nextI - 1][1] < 0);
			// Install the negative of the absolute word offset of the target
			I[nextI - 1][1] = -int32_t(buffer_offset + (dest - buffers->data) + (int32_t)I[nextI - 1][1]);
		}
	}

	void WordcodeEmitter::peep(uint32_t opcode, uintptr_t* loc)
	{
		const peep_state_t *s;
		uint32_t limit, next_state;
		
		AvmAssert(opcode != OP_lookupswitch);

		if (state == 0) 
			goto initial_state;
		
		if (opcode == 0) {
			s = &states[state];
			goto accept;
		}
		
		// Search for a transition from the current state to a next
		// state on input 'opcode'.
		
		O[nextI] = opcode;
		I[nextI] = loc;
		nextI++;
		s = &states[state];
		limit = s->numTransitions;
		
		// The transition lists can get quite long for popular instructions like GETLOCAL;
		// binary search if it that might be profitable.
		
		if (limit > 4) {
			int32_t lo = s->transitionPtr;
			int32_t hi = lo + limit - 1;
			while (lo <= hi) {
				uint32_t mid = (unsigned)(lo + hi) / 2;
				uint32_t probe = transitions[mid].opcode;
				if (probe == opcode) {
					next_state = transitions[mid].next_state;
					goto found;
				}
				if (opcode < probe)
					hi = mid-1;
				else
					lo = mid+1;
			}
			next_state = 0;
		}
		else {
			const peep_transition_t* t = &transitions[s->transitionPtr];
			uint32_t i = 0;
			while (i < limit && t->opcode != opcode) 
				i++, t++;
			
			next_state = (i == limit) ? 0 : t->next_state;
		}
	found:
		
		if (next_state != 0) {

			// Advance
			//
			// There is a next state, so push the current state on the backtrack
			// stack if it is final, and move to the next state.  If that state has
			// successor states then return, as the search continues.  Otherwise, the
			// next state must be final and we try to accept.
			//
			// (The shortcut of checking the successors is necessary for correctness,
			// as otherwise the peephole window could contain a branch in the non-final
			// position.)
			
			if (s->guardAndAction != 0)
				backtrack_stack[backtrack_idx++] = state;

		advance:
			state = next_state;
			s = &states[state];
			if (s->numTransitions > 0)
				return;
			
			next_state = 0;
			AvmAssert(s->guardAndAction != 0);
		}

		// Accept
		//
		// The next state is 0.  Commit to 'state' if it is final; otherwise to 
		// successive backtrack states.  Committing means checking the guard
		// (which may fail, forcing further backtracking) and if the guard passes
		// then performing the transformation.  The commit function is generated,
		// see above; the replace logic is in the function replace() above.
		
	accept:
		if (s->guardAndAction && commit(s->guardAndAction)) 
			return;
		
		for ( int bi=backtrack_idx-1 ; bi >= 0 ; bi-- ) {
			const peep_state_t *b = &states[backtrack_stack[bi]];
			AvmAssert(b->guardAndAction != 0);
			if (commit(b->guardAndAction)) 
				return;
		}
		
		// If we could not accept or backtrack because of failing guards then
		// try the failure state, if defined.  We discard anything not relevant
		// to the failure state by shifting the window, so relevant instructions
		// always begin in offset 0 of the window.
		
		if (s->fail != 0) {
			shiftBuffers(s->failShift);
			next_state = s->fail;
			goto advance;
		}

		// If we failed to find an accepting state then fall through to initial_state
		// to reset the machine.  Resetting discards the first instruction only,
		// other cases - where larger shifts are possible - are handled above, because
		// in that case s->fail will be nonzero.
		//
		// After shifting, rerun the optimizer on the input buffer, since there may
		// be optimization opportunities there.

		shiftBuffers(1);
		if (nextI > 0) {
			replace(0, 0);
			peepFlush();
		}
		return;
		
	initial_state:
		AvmAssert(opcode < WOP_LAST+1);

		state = toplevel[opcode];  // may remain 0
		nextI = 0;
		backtrack_idx = 0;
		if (state != 0) {
			O[nextI] = opcode;
			I[nextI] = loc;
			nextI++;
		}
	}
	
 	void WordcodeEmitter::shiftBuffers(uint32_t shift) 
 	{
 		for ( uintptr_t i=0, limit=nextI-shift ; i < limit ; i++ ) {
 			I[i] = I[i+shift];
 			O[i] = O[i+shift];
 		}
 		nextI -= shift;
 		backtrack_idx = 0;  // We could do better if we knew how many final states to discard
 	}
 	
	void WordcodeEmitter::peepFlush()
	{
		peep(0, NULL);		// commits, but may start another match
		state = 0;			// ignore any partial match
	}

#endif  // AVMPLUS_PEEPHOLE_OPTIMIZER

#endif // AVMPLUS_WORD_CODE
}
