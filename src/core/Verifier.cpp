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

#if defined AVMPLUS_MIR
	#include "../codegen/CodegenMIR.h"
	#define JIT_ONLY(x) x
	#define MIR_ONLY(x) x
	#define LIR_ONLY(x)
#elif defined FEATURE_NANOJIT
	#include "../codegen/CodegenLIR.h"
	#define JIT_ONLY(x) x
	#define MIR_ONLY(x) 
	#define LIR_ONLY(x) x
#else
	#define JIT_ONLY(x) 
	#define MIR_ONLY(x) 
	#define LIR_ONLY(x) 
#endif

#include "FrameState.h"

#ifdef AVMPLUS_WORD_CODE
    #define XLAT_ONLY(x) x
#else
    #define XLAT_ONLY(x)
#endif

namespace avmplus
{
#undef DEBUG_EARLY_BINDING

#ifdef AVMPLUS_WORD_CODE
	inline WordOpcode wordCode(AbcOpcode opcode) {
		return (WordOpcode)opcodeInfo[opcode].wordCode;
	}
#endif
	
	Verifier::Verifier(MethodInfo* info, Toplevel* toplevel
#ifdef AVMPLUS_VERBOSE
		, bool secondTry
#endif
		)
	{
#ifdef AVMPLUS_VERBOSE
		this->secondTry = secondTry;
#endif
		this->info   = info;
		this->core   = info->core();
		this->pool   = info->pool;
		this->toplevel = toplevel;
#ifdef AVMPLUS_WORD_CODE
		this->translator = NULL;
		this->num_caches = 0;
		this->next_cache = 0;
		this->caches = NULL;
#endif

		#if defined FEATURE_BUFFER_GUARD && defined AVMPLUS_MIR
		this->growthGuard = 0;
		#endif /* FEATURE_BUFFER_GUARD && AVMPLUS_MIR */

		#ifdef AVMPLUS_VERBOSE
		this->verbose = pool->verbose || (info->flags & AbstractFunction::VERBOSE_VERIFY);
		#endif

		const byte* pos = info->body_pos;
		max_stack = AvmCore::readU30(pos);
		local_count = AvmCore::readU30(pos);
		int init_scope_depth = AvmCore::readU30(pos);
		int max_scope_depth = AvmCore::readU30(pos);
		max_scope = max_scope_depth - init_scope_depth;

		stackBase = scopeBase + max_scope;
		frameSize = stackBase + max_stack;

		if ((init_scope_depth < 0) || (max_scope_depth < 0) || (max_stack < 0) || 
			(max_scope < 0) || (local_count < 0) || (frameSize < 0) || (stackBase < 0))
			verifyFailed(kCorruptABCError);

		code_length = AvmCore::readU30(pos);

		code_pos = pos;

		pos += code_length;
		
		exceptions_pos = pos;

		blockStates = NULL;
		state       = NULL;
		labelCount = 0;

		if (info->declaringTraits == NULL)
		{
			// scope hasn't been captured yet.
			verifyFailed(kCannotVerifyUntilReferencedError);
		}
	}

	Verifier::~Verifier()
	{
#ifdef AVMPLUS_WORD_CODE
		delete [] caches;
		caches = NULL;
#endif
		if (blockStates)
		{
			MMgc::GC* gc = core->GetGC();
			for(int i=0, n=blockStates->size(); i<n; i++)
			{
				FrameState* state = blockStates->at(i);
				if (state)
				{
					gc->Free(state);
				}
			}
			blockStates->clear();
			delete blockStates;
		}
	}

	/**
	 * (done) branches stay in code block
	 * (done) branches end on even instr boundaries
	 * (done) all local var operands stay inside [0..max_locals-1]
	 * (done) no illegal opcodes
	 * (done) cpool refs are inside [1..cpool_size-1]
	 * (done) converging paths have same stack depth
	 * (done) operand stack stays inside [0..max_stack-1]
	 * (done) locals defined before use
	 * (done) scope stack stays bounded
	 * (done) getScopeObject never exceeds [0..info->maxScopeDepth()-1]
	 * (done) global slots limits obeyed [0..var_count-1]
	 * (done) callstatic method limits obeyed [0..method_count-1]
	 * (done) cpool refs are correct type
	 * (done) make sure we don't fall off end of function
	 * (done) slot based ops are ok (slot must be legal)
 	 * (done) propref ops are ok: usage on actual type compatible with ref type.
	 * dynamic lookup ops are ok (type must not have that binding & must be dynamic)
     * dont access superclass state in ctor until super ctor called.
	 * @param pool
	 * @param info
	 */
#if defined AVMPLUS_MIR
    void Verifier::verify(CodegenMIR * volatile jit)
#elif defined FEATURE_NANOJIT
	void Verifier::verify(CodegenLIR * volatile jit)
#else
    void Verifier::verify()
#endif
	{		
		SAMPLE_FRAME("[verify]", core);

		#ifdef AVMPLUS_VERBOSE
		if (verbose)
            core->console << "verify " << info << '\n';
		secondTry = false;
		#endif

		info->localCount = local_count;
		info->maxScopeDepth = max_scope;
#ifdef AVMPLUS_64BIT
		info->frameSize = frameSize;
#else
		// The interpreter wants this to be padded to a doubleword boundary because
		// it allocates two objects in a single alloca() request - the frame and
		// auxiliary storage, in that order - and wants the second object to be
		// doubleword aligned.
		info->frameSize = (frameSize + 1) & ~1;
#endif
#ifndef AVMPLUS_WORD_CODE
		// For word code, it is set by the WordcodeTranslator epilogue
		info->codeStart = code_pos;
#endif
		
#ifdef AVMPLUS_WORD_CODE
	   // If MIR generation fails due to OOM then we must translate anyhow,
	   // FIXME - logic for that looks unclear.
	   // Also unclear if any of the existing logic is working, since none
	   // of it can really handle running out of memory anyhow.
	   // FIXME - if MIR generation doesn't fail, then we've translated for
	   // no good reason.
#    ifdef AVMPLUS_DIRECT_THREADED
		this->translator = new WordcodeEmitter(info, interpGetOpcodeLabels());
#    else
        // the jit can fail, and we dont want to have to re-run the verifier
        // until we know it's safe to do so, so run jit & translator concurrently.
        //this->translator = jit ? 0 : new WordcodeEmitter(info);
		this->translator = new WordcodeEmitter(info);
#    endif
	    WordcodeTranslator *translator = this->translator;
		caches = new uint32_t[5];
		num_caches = 5;
#endif

		JIT_ONLY( this->jit = jit; )
		if ( (state = newFrameState()) == 0 ){
			verifyFailed(kCorruptABCError);
		}
		for (int i=0, n=frameSize; i < n; i++)
			state->setType(i, NULL);

		if (info->flags & AbstractFunction::NEED_REST)
		{
			// param_count+1 <= max_reg
			checkLocal(info->param_count+1);

			state->setType(info->param_count+1, ARRAY_TYPE, true);

			#ifdef AVMPLUS_VERBOSE
			if (verbose && (info->flags & AbstractFunction::NEED_ARGUMENTS))
			{
				// warning, NEED_ARGUMENTS wins
				core->console << "WARNING, NEED_REST overrides NEED_ARGUMENTS when both are set\n";
			}
			#endif
		}
		else if (info->flags & AbstractFunction::NEED_ARGUMENTS)
		{
			// param_count+1 <= max_reg
			checkLocal(info->param_count+1);

			// E3 style arguments array is an Object, E4 says Array, E4 wins...
			state->setType(info->param_count+1, ARRAY_TYPE, true);
		}
		else
		{
			// param_count <= max_reg
			checkLocal(info->param_count);
		}

		// initialize method param types.
		// We already verified param_count is a legal register so
		// don't checkLocal(i) inside the loop.
		// AbstractFunction::verify takes care of resolving param&return type
		// names to Traits pointers, and resolving optional param default values.
		for (int i=0, n=info->param_count; i <= n; i++)
		{
			bool notNull = (i==0); // this is not null, but other params could be
			state->setType(i, info->paramTraits(i), notNull);
		}

		// initial scope chain types 
		int outer_depth = 0;

		ScopeTypeChain* scope = info->declaringTraits->scope;
		if (!scope && info->declaringTraits->init != info)
		{
			// this can occur when an activation scope inside a class instance method
			// contains a nested getter, setter, or method.  In that case the scope 
			// is not captured when the containing function is verified.  This isn't a
			// bug because such nested functions aren't suppported by AS3.  This
			// verify error is how we don't let those constructs run.
			verifyFailed(kNoScopeError, core->toErrorString(info));
		}

		state->scopeDepth = outer_depth;

		// resolve catch block types
		parseExceptionHandlers();
		XLAT_ONLY( if (translator) translator->computeExceptionFixups() );

		// Save initial state
		FrameState* initialState = newFrameState();
		if( !initialState->init(state) ) 
			verifyFailed(kCorruptABCError);

		int actualCount = 0;
		bool blockEnd = false;    // extended basic block ending

		// always load the entry state, no merge on second pass
		state->init(initialState);

#ifdef FEATURE_BUFFER_GUARD
		#ifdef AVMPLUS_MIR
		// allow the jit buffer to grow dynamically
		GrowthGuard guard(jit ? jit->mirBuffer : NULL);
		this->growthGuard = &guard;
		#endif //AVMPLUS_MIR
#endif /* FEATURE_BUFFER_GUARD */

		TRY(core, kCatchAction_Rethrow){

		#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
		if (jit)
		{
			if( !jit->prologue(state) ) 
			{
				if (!jit->overflow)
					verifyFailed(kCorruptABCError);

				// we're out of code memory so try to carry on with interpreter
				jit = 0;
				this->jit = 0;
			}
		}
		#endif

        PERFM_NVPROF("abc-bytes", code_length);

		int size;
		for (const byte* pc = code_pos, *code_end=code_pos+code_length; pc < code_end; pc += size)
		{
			SAMPLE_CHECK();
            PERFM_NVPROF("abc-verify", 1);

		    JIT_ONLY(if (jit && jit->overflow) {
				jit = 0;
				this->jit = 0;
			})
			
			XLAT_ONLY( if (translator) translator->fixExceptionsAndLabels(pc); )
			
			AbcOpcode opcode = (AbcOpcode) *pc;
			if (opcodeInfo[opcode].operandCount == -1)
				verifyFailed(kIllegalOpcodeError, core->toErrorString(info), core->toErrorString(opcode), core->toErrorString((int)(pc-code_pos)));

			if (opcode == OP_label)
			{
				// insert a label here
				getFrameState((int)(pc-code_pos))->targetOfBackwardsBranch = true;
			}

			bool unreachable = false;
			FrameState* blockState;
			if ( blockStates && (blockState = blockStates->get((uintptr)pc)) != 0 )
			{
				// send a bbend prior to the merge
				JIT_ONLY( if (jit) jit->emitBlockEnd(state); )

				if (!blockEnd || !blockState->initialized)
				{
					checkTarget(pc); 
				}

				#ifdef AVMPLUS_VERBOSE
				if (verbose)
					core->console << "B" << (pc - code_pos) << ":\n";
				#endif

				// now load the merged state
				state->init(blockState);
				state->targetOfBackwardsBranch = blockState->targetOfBackwardsBranch;
				state->pc = pc - code_pos;

				// found the start of a new basic block
				JIT_ONLY( if (jit) jit->emitBlockStart(state); )

				state->targetOfBackwardsBranch = false;

				actualCount++;
				blockEnd = false;

				if (!blockState->targetOfBackwardsBranch)
				{
                    #ifdef FEATURE_NANOJIT
                        // fixme: CodegenLIR wants to do all patching in epilog() so we cannot
                        // free the block early.
                        if (!jit) {
					        blockStates->remove((uintptr)pc);
					        core->GetGC()->Free(blockState);
                        }
                    #else
                        // jit and translator are okay with this
						blockStates->remove((uintptr)pc);
						core->GetGC()->Free(blockState);
                    #endif
				}
			}
			else
			{
				if (blockEnd)
				{
					// the next instruction is not reachable because it comes after
					// a jump, throw, or return, and there are no branch targets
					// inbetween the branch/jump/return and this instruction.
					// So, don't verify it.
					unreachable = true;
				}
			}

			state->pc = pc - code_pos;
			int sp = state->sp();

			if (info->exceptions)
			{
				JIT_ONLY( bool mirSavedState = false; )
				for (int i=0, n=info->exceptions->exception_count; i < n; i++)
				{
					ExceptionHandler* handler = &info->exceptions->exceptions[i];
					if (pc >= code_pos + handler->from && pc <= code_pos + handler->to)
					{
						// Set the insideTryBlock flag, so the codegen can
						// react appropriately.
						state->insideTryBlock = true;

						// If this instruction can throw exceptions, add an edge to
						// the catch handler.
						if (opcodeInfo[opcode].canThrow || pc == code_pos + handler->from)
						{
							// TODO check stack is empty because catch handlers assume so.
							int saveStackDepth = state->stackDepth;
							int saveScopeDepth = state->scopeDepth;
							state->stackDepth = 0;
							state->scopeDepth = outer_depth;
							Value stackEntryZero = state->stackValue(0);

							JIT_ONLY(if (jit && !mirSavedState) {
								jit->emitBlockEnd(state);
								mirSavedState = true;
							})

							// add edge from try statement to catch block
							const byte* target = code_pos + handler->target;
							// atom received as *, will coerce to correct type in catch handler.
							state->push(NULL);

                            MIR_ONLY(if (jit) jit->localSet(stackBase, jit->exAtom);)

							checkTarget(target);
 							state->pop();

							state->stackDepth = saveStackDepth;
							state->scopeDepth = saveScopeDepth;
							state->stackValue(0) = stackEntryZero;

							// Search forward for OP_killreg in the try block
							// Set these registers to killed in the catch state
							if (pc == code_pos + handler->from)
							{
								FrameState *catchState = blockStates->get((uintptr)target);
								AvmAssert(catchState != 0);

                                for (const byte *temp = pc; temp <= code_pos + handler->to; )
								{
                                    if( *temp == OP_lookupswitch )
                                    {
                                        // Variable length instruction
										const byte *temp2 = temp+4;
                                        const int case_count = toplevel->readU30(temp2)+1;
										temp += AvmCore::calculateInstructionWidth(temp) + 3*case_count;
                                    }
									else
									{
										// If this instruction is OP_killreg, kill the register
										// in the catch block state too
										if (*temp == OP_kill)
										{
											const byte* temp2 = temp+1;
											int local = toplevel->readU30(temp2);
											if (local >= local_count)
												verifyFailed(kInvalidRegisterError, core->toErrorString(local));
											Value& v = catchState->value(local);
											v.notNull = false;
											v.traits = NULL;
											v.killed = true;
										}
										temp += AvmCore::calculateInstructionWidth(temp);
									}
								}
							}
						}							
					}
					
					if (pc == code_pos + handler->target)
					{
						emitCoerce(handler->traits, sp);
					}
				}
			}
			unsigned int imm30=0, imm30b=0;
			int imm8=0, imm24=0;

			const byte* nextpc = pc;
            AvmCore::readOperands(nextpc, imm30, imm24, imm30b, imm8);
			// make sure U30 operands are within bounds.
			if (opcode != OP_pushshort && ((imm30|imm30b) & 0xc0000000))
			{
				// don't report error if first operand of abs_jump (pc) is large.
				if (opcode != OP_abs_jump || (imm30b & 0xc0000000))
				{
					verifyFailed(kCorruptABCError);
				}
			}
			size = int(nextpc-pc);
			if (pc+size > code_end)
				verifyFailed(kLastInstExceedsCodeSizeError);

			#ifdef AVMPLUS_VERBOSE
			if (verbose) 
			{
				showState(state, pc, unreachable);
			}
			#endif

			if (unreachable)
			{
				// Even if unreachable, we have to properly advance
				// past the variable-sized OP_lookupswitch
				if (opcode == OP_lookupswitch)
					size += 3*(imm30b+1);

				continue;
			}

			switch (opcode)
			{
			case OP_iflt:
			case OP_ifle:
			case OP_ifnlt:
			case OP_ifnle:
			case OP_ifgt:
			case OP_ifge:
			case OP_ifngt:
			case OP_ifnge:
			case OP_ifeq:
			case OP_ifstricteq:
			case OP_ifne:
			case OP_ifstrictne:
			{
				checkStack(2,0);
				JIT_ONLY( int lhs = sp-1; )
				state->pop();
				state->pop();
				JIT_ONLY( if (jit) jit->emitIf(state, opcode, state->pc+size+imm24, lhs, lhs+1); )
				checkTarget(nextpc+imm24);
				XLAT_ONLY( if (translator) translator->emitRelativeJump(pc, wordCode(opcode)) );
				break;
			}

			case OP_iftrue:
			case OP_iffalse:
			{
				checkStack(1,0);
				int cond = sp;
				emitCoerce(BOOLEAN_TYPE, cond);
				state->pop();
				JIT_ONLY( if (jit) jit->emitIf(state, opcode, state->pc+size+imm24, cond, 0); )
				checkTarget(nextpc+imm24);
				XLAT_ONLY( if (translator) translator->emitRelativeJump(pc, wordCode(opcode)) );
				break;
			}

			case OP_jump:
			{
				//checkStack(0,0)
				JIT_ONLY( if (jit) jit->emit(state, opcode, state->pc+size+imm24); )
				checkTarget(nextpc+imm24);	// target block;
				blockEnd = true;
				XLAT_ONLY( if (translator) translator->emitRelativeJump(pc, WOP_jump) );
				break;
			}

			case OP_lookupswitch: 
			{
				checkStack(1,0);
				peekType(INT_TYPE);
				const uint32_t count = imm30b;
				JIT_ONLY( if (jit) jit->emit(state, opcode, state->pc+imm24, count); )

				state->pop();

				checkTarget(pc+imm24);
				uint32_t case_count = 1 + count;
				if (pc + size + 3*case_count > code_end) 
					verifyFailed(kLastInstExceedsCodeSizeError);

				for (uint32_t i=0; i < case_count; i++) {
					int off = AvmCore::readS24(pc+size);
					checkTarget(pc+off);
					size += 3;
				}
				blockEnd = true;
				XLAT_ONLY( if (translator) translator->emitLookupswitch(pc) );
				break;
			}

			case OP_throw:
			{
				checkStack(1,0);
				// [ggrossman] it is legal to throw anything at all; don't check
				JIT_ONLY( if (jit) jit->emit(state, opcode, sp); )
				state->pop();
				blockEnd = true;
				XLAT_ONLY( if (translator) translator->emitOp0(pc, WOP_throw) );
				break;
			}

			case OP_returnvalue:
			{
				checkStack(1,0);

				JIT_ONLY( if (jit) {
					Traits* returnTraits = info->returnTraits();
					emitCoerce(returnTraits, sp);
					jit->emit(state, opcode, sp);
				})
				// make sure stack state is updated, since verifier scans
				// straight through to the next block.
				state->pop();
				blockEnd = true;
				XLAT_ONLY( if (translator) translator->emitOp0(pc, WOP_returnvalue) );
				break;
			}

			case OP_returnvoid: 
			{
				//checkStack(1,0)
				JIT_ONLY( if (jit) jit->emit(state, opcode); )
				blockEnd = true;
				XLAT_ONLY( if (translator) translator->emitOp0(pc, WOP_returnvoid) );
				break;
			}

			case OP_pushnull:
				checkStack(0,1);
				JIT_ONLY( if (jit) jit->emitIntConst(state, sp+1, 0); )
				state->push(NULL_TYPE);
				XLAT_ONLY( if (translator) translator->emitOp0(pc, WOP_pushnull) );
				break;

			case OP_pushundefined:
				checkStack(0,1);
				JIT_ONLY( if (jit) jit->emitIntConst(state, sp+1, undefinedAtom); )
				state->push(VOID_TYPE);
				XLAT_ONLY( if (translator) translator->emitOp0(pc, WOP_pushundefined) );
				break;

			case OP_pushtrue:
				checkStack(0,1);
				JIT_ONLY( if (jit) jit->emitIntConst(state, sp+1, 1); )
				state->push(BOOLEAN_TYPE, true);
				XLAT_ONLY( if (translator) translator->emitOp0(pc, WOP_pushtrue) );
				break;

			case OP_pushfalse:
				checkStack(0,1);
				JIT_ONLY( if (jit) jit->emitIntConst(state, sp+1, 0); )
				state->push(BOOLEAN_TYPE, true);
				XLAT_ONLY( if (translator) translator->emitOp0(pc, WOP_pushfalse) );
				break;

			case OP_pushnan:
				checkStack(0,1);
				JIT_ONLY( if (jit) jit->emitDoubleConst(state, sp+1, (double*)(core->kNaN & ~7)); )
				state->push(NUMBER_TYPE, true);
				XLAT_ONLY( if (translator) translator->emitOp0(pc, WOP_pushnan) );
				break;

			case OP_pushshort:
				checkStack(0,1);
				JIT_ONLY( if (jit) jit->emitIntConst(state, sp+1, (signed short)imm30); )
				state->push(INT_TYPE, true);
				XLAT_ONLY( if (translator) translator->emitPushshort(pc) );
				break;

			case OP_pushbyte:
				checkStack(0,1);
				JIT_ONLY( if (jit) jit->emitIntConst(state, sp+1, (signed char)imm8); )
				state->push(INT_TYPE, true);
				XLAT_ONLY( if (translator) translator->emitPushbyte(pc) );
				break;

			case OP_debugfile:
			{
				//checkStack(0,0)
				#if defined(DEBUGGER) || defined(VTUNE)
				JIT_ONLY( Atom filename = ) checkCpoolOperand(imm30, kStringType);
				JIT_ONLY( if (jit) jit->emit(state, opcode, (uintptr)AvmCore::atomToString(filename)); )
				#endif
#ifdef DEBUGGER
				XLAT_ONLY( if (translator) translator->emitOp1(pc, WOP_debugfile) );
#endif
				break;
			}

			case OP_dxns:
			{
				//checkStack(0,0)
				if (!info->isFlagSet(AbstractFunction::SETS_DXNS))
					verifyFailed(kIllegalSetDxns, core->toErrorString(info));
				JIT_ONLY( Atom uri = ) checkCpoolOperand(imm30, kStringType);
				JIT_ONLY( if (jit) jit->emit(state, opcode, (uintptr)AvmCore::atomToString(uri)); )
				XLAT_ONLY( if (translator) translator->emitOp1(pc, WOP_dxns) );
				break;
			}

			case OP_dxnslate:
			{
				checkStack(1,0);
				if (!info->isFlagSet(AbstractFunction::SETS_DXNS))
					verifyFailed(kIllegalSetDxns, core->toErrorString(info));
				// codgeen will call intern on the input atom.
				JIT_ONLY( if (jit) jit->emit(state, opcode, sp); )
				state->pop();
				XLAT_ONLY( if (translator) translator->emitOp0(pc, WOP_dxnslate) );
				break;
			}

			case OP_pushstring: 
			{
				checkStack(0,1);
				uint32_t index = imm30;
				if (index == 0 || index >= pool->constantStringCount)
					verifyFailed(kCpoolIndexRangeError, core->toErrorString(index), core->toErrorString(pool->constantStringCount));

				Stringp value = pool->cpool_string[index];
				JIT_ONLY( if (jit) jit->emitIntConst(state, sp+1, (uintptr)value); )
				state->push(STRING_TYPE, value != NULL);
				XLAT_ONLY( if (translator) translator->emitOp1(pc, WOP_pushstring) );
				break;
			}

			case OP_pushint: 
			{
				checkStack(0,1);
				uint32_t index = imm30;
				if (index == 0 || index >= pool->constantIntCount)
					verifyFailed(kCpoolIndexRangeError, core->toErrorString(index), core->toErrorString(pool->constantIntCount));
				
				JIT_ONLY( if (jit) jit->emitIntConst(state, sp+1, pool->cpool_int[index]); )
				state->push(INT_TYPE,true);
				XLAT_ONLY( if (translator) translator->emitPushint(pc) );
				break;
			}
			case OP_pushuint: 
			{
				checkStack(0,1);
				uint32_t index = imm30;
				if (index == 0 || index >= pool->constantUIntCount)
					verifyFailed(kCpoolIndexRangeError, core->toErrorString(index), core->toErrorString(pool->constantUIntCount));
				
				JIT_ONLY( if (jit) jit->emitIntConst(state, sp+1, pool->cpool_uint[index]); )
				state->push(UINT_TYPE,true);
				XLAT_ONLY( if (translator) translator->emitPushuint(pc) );
				break;
			}
			case OP_pushdouble: 
			{
				checkStack(0,1);
				uint32_t index = imm30;
				if (index == 0 || index >= pool->constantDoubleCount)
					verifyFailed(kCpoolIndexRangeError, core->toErrorString(index), core->toErrorString(pool->constantDoubleCount));
				
				JIT_ONLY( if (jit) jit->emitDoubleConst(state, sp+1, pool->cpool_double[index]); )
				state->push(NUMBER_TYPE, true);
				XLAT_ONLY( if (translator) translator->emitOp1(pc, WOP_pushdouble) );
				break;
			}

			case OP_pushnamespace: 
			{
				checkStack(0,1);
				uint32_t index = imm30;
				if (index == 0 || index >= pool->constantNsCount)
					verifyFailed(kCpoolIndexRangeError, core->toErrorString(index), core->toErrorString(pool->constantNsCount));

				Namespace* value = pool->cpool_ns[index];
				JIT_ONLY( if (jit) jit->emitIntConst(state, sp+1, (uintptr)value); )
				state->push(NAMESPACE_TYPE, value != NULL);
				XLAT_ONLY( if (translator) translator->emitOp1(pc, WOP_pushnamespace) );
				break;
			}

			case OP_setlocal:
			{
				checkStack(1,0);
				checkLocal(imm30);
				JIT_ONLY( if (jit) jit->emitCopy(state, sp, imm30); )
				Value &v = state->stackTop();
				state->setType(imm30, v.traits, v.notNull);
				state->pop();
				XLAT_ONLY( if (translator) translator->emitOp1(pc, WOP_setlocal) );
				break;
			}

			case OP_setlocal0:
			case OP_setlocal1:
			case OP_setlocal2:
			case OP_setlocal3:				
			{
				int localno = opcode-OP_setlocal0;
				checkStack(1,0);
				checkLocal(localno);
				JIT_ONLY( if (jit) jit->emitCopy(state, sp, localno); )
				Value &v = state->stackTop();
				state->setType(localno, v.traits, v.notNull);
				state->pop();
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
				XLAT_ONLY( if (translator) translator->emitOp1(WOP_setlocal, localno) );
#else
				XLAT_ONLY( if (translator) translator->emitOp0(pc, wordCode(opcode)) );
#endif
				break;
			}

			case OP_getlocal:
			{
				checkStack(0,1);
				Value& v = checkLocal(imm30);
				JIT_ONLY( if (jit) jit->emitCopy(state, imm30, sp+1); )
				state->push(v);
				XLAT_ONLY( if (translator) translator->emitOp1(pc, WOP_getlocal) );
				break;
			}

			case OP_getlocal0:
			case OP_getlocal1:
			case OP_getlocal2:
			case OP_getlocal3:
			{
				int localno = opcode-OP_getlocal0;
				checkStack(0,1);
				Value& v = checkLocal(localno);
				JIT_ONLY( if (jit) jit->emitCopy(state, localno, sp+1); )
				state->push(v);
#ifdef AVMPLUS_PEEPHOLE_OPTIMIZER
				XLAT_ONLY( if (translator) translator->emitOp1(WOP_getlocal, localno) );
#else
				XLAT_ONLY( if (translator) translator->emitOp0(pc, wordCode(opcode)) );
#endif
				break;
			}
			
			case OP_kill:
			{
				//checkStack(0,0)
				Value &v = checkLocal(imm30);
				JIT_ONLY( if (jit) jit->emitKill(state, imm30); )
				v.notNull = false;
				v.traits = NULL;
				// No sense in emitting this for the interpreter, as all
				// stacked values are atoms and fully type checked
				break;
			}

			case OP_inclocal:
			case OP_declocal:
			{
				//checkStack(0,0);
				checkLocal(imm30);
				emitCoerce(NUMBER_TYPE, imm30);
				JIT_ONLY( if (jit) jit->emit(state, opcode, imm30, opcode==OP_inclocal ? 1 : -1, NUMBER_TYPE); )
				XLAT_ONLY( if (translator) translator->emitOp1(pc, wordCode(opcode)) );
				break;
			}

			case OP_inclocal_i:
			case OP_declocal_i:
			{
				//checkStack(0,0);
				checkLocal(imm30);
				emitCoerce(INT_TYPE, imm30);
				JIT_ONLY( if (jit) jit->emit(state, opcode, imm30, opcode==OP_inclocal_i ? 1 : -1, INT_TYPE); )
				XLAT_ONLY( if (translator) translator->emitOp1(pc, wordCode(opcode)) );
				break;
			}

			case OP_newfunction: 
			{
				checkStack(0,1);
				AbstractFunction* f = checkMethodInfo(imm30);

				// Duplicate function definitions can happen with well formed ABC data.  We need
				// to clear out data on AbstractionFunction so it can correctly be re-initialized.
				// If our old function is ever used incorrectly, we throw an verify error in 
				// MethodEnv::coerceEnter.
				if (f->declaringTraits)
				{
					f->flags &= ~AbstractFunction::LINKED;
					f->declaringTraits = NULL;
				}
				f->setParamType(0, NULL);
				f->makeIntoPrototypeFunction(toplevel);
				Traits* ftraits = f->declaringTraits;
				// make sure the traits of the base vtable matches the base traits
				// This is also caught by an assert in VTable.cpp, however that turns
				// out to be too late and may cause crashes
				if(toplevel->functionClass != 0 &&
                   ftraits->base != toplevel->functionClass->ivtable()->traits ){
					AvmAssertMsg(0, "Verify failed:OP_newfunction");
 					if (toplevel->verifyErrorClass() != NULL)
 						verifyFailed(kInvalidBaseClassError);
				}
				int extraScopes = state->scopeDepth;
				ftraits->scope = ScopeTypeChain::create(core->GetGC(), scope, extraScopes);
				for (int i=0,j=scope->size, n=state->scopeDepth; i < n; i++, j++)
				{
					ftraits->scope->setScopeAt(j, state->scopeValue(i).traits, state->scopeValue(i).isWith);
				}

				if (f->activationTraits)
				{
					// ISSUE - if nested functions, need to capture scope, not make a copy
					f->activationTraits->scope = ftraits->scope;
				}

				#ifdef AVMPLUS_VERIFYALL
				core->enq(f);
				#endif
				
				JIT_ONLY( if (jit) {
					jit->emitSetDxns(state);
					jit->emit(state, opcode, imm30, sp+1, ftraits);
				})

				state->push(ftraits, true);
				XLAT_ONLY( if (translator) translator->emitOp1(pc, WOP_newfunction) );
				break;
			}

			case OP_getlex:
			{
				if (state->scopeDepth + scope->size == 0)
				{
					verifyFailed(kFindVarWithNoScopeError);
				}
				Multiname multiname;
				checkConstantMultiname(imm30, multiname);
				checkStackMulti(0, 1, &multiname);
				if (multiname.isRuntime())
					verifyFailed(kIllegalOpMultinameError, core->toErrorString(opcode), core->toErrorString(&multiname));
				emitFindProperty(OP_findpropstrict, multiname, imm30);
				emitGetProperty(multiname, 1, imm30);
				break;
			}

			case OP_findpropstrict:
			case OP_findproperty:
			{
				if (state->scopeDepth + scope->size == 0)
				{
					verifyFailed(kFindVarWithNoScopeError);
				}
				Multiname multiname;
				checkConstantMultiname(imm30, multiname);
				checkStackMulti(0, 1, &multiname);
				emitFindProperty(opcode, multiname, imm30);
				break;
			}

			case OP_newclass: 
			{
				checkStack(1, 1);
				// must be a CONSTANT_Multiname
				Traits* ctraits = checkClassInfo(imm30);

				// the actual result type will be the static traits of the new class.
				
				// make sure the traits came from this pool.  they have to because
				// the class_index operand is resolved from the current pool.
				AvmAssert(ctraits->pool == pool);

				Traits *itraits = ctraits->itraits;

				int captureScopes = state->scopeDepth;

				ScopeTypeChain* cscope = ScopeTypeChain::create(core->GetGC(), scope, captureScopes, 1);
				int j=scope->size;
				for (int i=0, n=state->scopeDepth; i < n; i++, j++)
				{
					cscope->setScopeAt(j, state->scopeValue(i).traits, state->scopeValue(i).isWith);
				}

				// add a type constraint for the "this" scope of static methods
				cscope->setScopeAt(state->scopeDepth, ctraits, false);

				if (state->scopeDepth > 0)
				{
					// innermost scope must be the base class object or else createInstance()
					// will malfunction because it will use the wrong [base] class object to
					// construct the instance.  See ScriptObject::createInstance()
					Traits* baseCTraits = state->scopeValue(state->scopeDepth-1).traits;
					if (!baseCTraits || baseCTraits->itraits != itraits->base)
						verifyFailed(kCorruptABCError);
				}

				ScopeTypeChain* iscope = ScopeTypeChain::create(core->GetGC(), cscope, 1, 1);
				iscope->setScopeAt(iscope->size-1, ctraits, false);

				// add a type constraint for the "this" scope of instance methods
				iscope->setScopeAt(iscope->size, itraits, false);

				ctraits->scope = cscope;
				itraits->scope = iscope;

				ctraits->resolveSignatures(toplevel);
				itraits->resolveSignatures(toplevel);

				#ifdef AVMPLUS_VERIFYALL
				core->enq(ctraits);
				core->enq(itraits);
				#endif

				// make sure base class is really a class
				JIT_ONLY( if (jit) {
					jit->emitSetDxns(state);
					emitCoerce(CLASS_TYPE, state->sp());
					jit->emit(state, opcode, (uintptr)(void*)pool->cinits[imm30], sp, ctraits);
				})
				state->pop_push(1, ctraits, true);
				XLAT_ONLY( if (translator) translator->emitOp1(pc, WOP_newclass) );
				break;
			}

			case OP_finddef: 
			{
				// must be a CONSTANT_Multiname.
				Multiname multiname;
				checkConstantMultiname(imm30, multiname);
				checkStackMulti(0, 1, &multiname);

				if (!multiname.isBinding())
				{
					// error, def name must be CT constant, regular name
					verifyFailed(kIllegalOpMultinameError, core->toErrorString(opcode), core->toErrorString(&multiname));
				}

				AbstractFunction* script = (AbstractFunction*)pool->getNamedScript(&multiname);
				if (script != (AbstractFunction*)BIND_NONE && script != (AbstractFunction*)BIND_AMBIGUOUS)
				{
					// found a single matching traits
					JIT_ONLY( if (jit) jit->emit(state, opcode, (uintptr)&multiname, sp+1, script->declaringTraits); )
					state->push(script->declaringTraits, true);
				}
				else
				{
					// no traits, or ambiguous reference.  use Object, anticipating
					// a runtime exception
					JIT_ONLY( if (jit) jit->emit(state, opcode, (uintptr)&multiname, sp+1, OBJECT_TYPE); )
					state->push(OBJECT_TYPE, true);
				}
				XLAT_ONLY( if (translator) translator->emitOp1(pc, WOP_finddef) );
				break;
			}

			case OP_setproperty:
			case OP_initproperty:
			{
				// stack in: object [ns] [name] value
				Multiname multiname;
				checkConstantMultiname(imm30, multiname); // CONSTANT_Multiname
				checkStackMulti(2, 0, &multiname);

				uint32_t n=2;
				checkPropertyMultiname(n, multiname);
				Value& obj = state->peek(n);

				JIT_ONLY( int ptrIndex = sp-(n-1); )
				JIT_ONLY( if (jit) emitCheckNull(ptrIndex); )

				Binding b = toplevel->getBinding(obj.traits, &multiname);
				bool needsSetContext = true;
				Traits* propTraits = readBinding(obj.traits, b);
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT || defined AVMPLUS_WORD_CODE
				if (AvmCore::isSlotBinding(b) && /*jit &&*/
					// it's a var, or a const being set from the init function
					(!AvmCore::isConstBinding(b) || 
						obj.traits->init == info && opcode == OP_initproperty))
				{
					emitCoerce(propTraits, state->sp());
					MIR_ONLY( if (jit) jit->emit(state, OP_setslot, AvmCore::bindingToSlotId(b), ptrIndex, propTraits); );
					LIR_ONLY( if (jit) jit->emitSetslot(state, OP_setslot, AvmCore::bindingToSlotId(b), ptrIndex); );
					XLAT_ONLY( if (translator) translator->emitOp1( WOP_setslot, AvmCore::bindingToSlotId(b)+1 ) );
					state->pop(n);
					break;
				}
				// else: setting const from illegal context, fall through
				#else
				(void)propTraits;
				#endif
				
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				// If it's an accessor that we can early bind, do so.
				// Note that this cannot be done on String or Namespace,
				// since those are represented by non-ScriptObjects
				if (jit && AvmCore::hasSetterBinding(b))
				{
					// early bind to the setter
					int disp_id = AvmCore::bindingToSetterId(b);
					const TraitsBindingsp objtd = obj.traits->getTraitsBindings();
					AbstractFunction *f = objtd->getMethod(disp_id);
					AvmAssert(f != NULL);
					emitCoerceArgs(f, 1);
					jit->emitSetContext(state, f);
					Traits* result = f->returnTraits();
					if (!obj.traits->isInterface)
						jit->emitCall(state, OP_callmethod, disp_id, 1, result);
					else
						jit->emitCall(state, OP_callinterface, f->iid(), 1, result);
					state->pop(n);
					goto setproperty_end;
				}
				#endif

				#ifdef DEBUG_EARLY_BINDING
				core->console << "verify setproperty " << obj.traits << " " << &multiname->getName() << " from within " << info << "\n";
				#endif

				if( obj.traits == VECTORINT_TYPE  || obj.traits == VECTORUINT_TYPE ||
					obj.traits == VECTORDOUBLE_TYPE )
				{
					bool attr = multiname.isAttr();
					Traits* indexType = state->value(state->sp()-1).traits;

					bool maybeIntegerIndex = !attr && multiname.isRtname() && multiname.contains(core->publicNamespace);

					if( maybeIntegerIndex && (indexType == UINT_TYPE || indexType == INT_TYPE) )
					{
						needsSetContext = false;
						if(obj.traits == VECTORINT_TYPE)
							emitCoerce(INT_TYPE, state->sp());
						else if(obj.traits == VECTORUINT_TYPE)
							emitCoerce(UINT_TYPE, state->sp());
						else if(obj.traits == VECTORDOUBLE_TYPE)
							emitCoerce(NUMBER_TYPE, state->sp());
					}
				}

				// not a var binding or early bindable accessor
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				if (jit)
				{
					if (needsSetContext)
						jit->emitSetContext(state, NULL);
					jit->emit(state, opcode, (uintptr)&multiname);
				}
				#endif
				state->pop(n);
#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
			setproperty_end:
#endif
				XLAT_ONLY( if (translator) translator->emitOp1(pc, wordCode(opcode)) );
				break;
			}

			case OP_getproperty:
			{
				// stack in: object [ns [name]]
				// stack out: value
				Multiname multiname;
				checkConstantMultiname(imm30, multiname); // CONSTANT_Multiname
				checkStackMulti(1, 1, &multiname);
				uint32_t n=1;
				checkPropertyMultiname(n, multiname);
				emitGetProperty(multiname, n, imm30);
				break;
			}

			case OP_getdescendants:
			{
				// stack in: object [ns] [name]
				// stack out: value
				Multiname multiname;
				checkConstantMultiname(imm30, multiname);
				checkStackMulti(1, 1, &multiname);
				uint32_t n=1;
				checkPropertyMultiname(n, multiname);
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				if (jit)
				{
					emitCheckNull(sp-(n-1));
					jit->emit(state, opcode, (uintptr)&multiname, 0, NULL);
				}
				#endif
				state->pop_push(n, NULL);
				XLAT_ONLY( if (translator) translator->emitOp1(pc, WOP_getdescendants) );
				break;
			}

			case OP_checkfilter:
			{
				// stack in: object 
				// stack out: object
				checkStack(1, 1);
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				if (jit)
				{
					emitCheckNull(state->sp());
					jit->emit(state, opcode, state->sp(), 0, NULL);
				}
				#endif
				XLAT_ONLY( if (translator) translator->emitOp0(pc, WOP_checkfilter) );
				break;
			}

			case OP_deleteproperty:
			{
				Multiname multiname;
				checkConstantMultiname(imm30, multiname);
				checkStackMulti(1, 1, &multiname);
				uint32_t n=1;
				checkPropertyMultiname(n, multiname);
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				if (jit) 
				{
					emitCheckNull(sp-(n-1));
					jit->emit(state, opcode, (uintptr)&multiname, 0, BOOLEAN_TYPE);
				}
				#endif
				state->pop_push(n, BOOLEAN_TYPE);
				XLAT_ONLY( if (translator) translator->emitOp1(pc, WOP_deleteproperty) );
				break;
			}

			case OP_astype:
			{
				checkStack(1, 1);
				// resolve operand into a traits, and push that type.
				Traits *t = checkTypeName(imm30);// CONSTANT_Multiname
				int index = sp;
				Traits* rhs = state->value(index).traits;
				if (!canAssign(t, rhs) || !Traits::isMachineCompatible(t, rhs))
				{
					Traits* resultType = t;
					// result is typed value or null, so if type can't hold null,
					// then result type is Object. 
					if (t && t->isMachineType())
						resultType = OBJECT_TYPE;
					JIT_ONLY( if (jit) jit->emit(state, OP_astype, (uintptr)t, index, resultType); )
					state->pop_push(1, t);
				}
				XLAT_ONLY( if (translator) translator->emitOp1(pc, WOP_astype) );
				break;
			}

			case OP_astypelate:
			{
				checkStack(2,1);
				Value& classValue = state->peek(1); // rhs - class
				Traits* ct = classValue.traits;
				Traits* t = NULL;
				if (ct && (t=ct->itraits) != 0)
					if (t->isMachineType())
						t = OBJECT_TYPE;

				JIT_ONLY( if (jit) jit->emit(state, opcode, 0, 0, t); )
				state->pop_push(2, t);
				XLAT_ONLY( if (translator) translator->emitOp0(pc, WOP_astypelate) );
				break;
			}

			case OP_coerce:
			{
				checkStack(1,1);
				// resolve operand into a traits, and push that type.
				emitCoerce(checkTypeName(imm30), sp);
				XLAT_ONLY( if (translator) translator->emitOp1(pc, WOP_coerce) );
				break;
			}

			case OP_convert_b:
			case OP_coerce_b:
			{
				checkStack(1,1);
				emitCoerce(BOOLEAN_TYPE, sp);
				XLAT_ONLY( if (translator) translator->emitOp0(pc, wordCode(opcode)) );
				break;
			}

			case OP_coerce_o:
			{
				checkStack(1,1);
				emitCoerce(OBJECT_TYPE, sp);
				XLAT_ONLY( if (translator) translator->emitOp0(pc, WOP_coerce_o) );
				break;
			}

			case OP_coerce_a:
			{
				checkStack(1,1);
				emitCoerce(NULL, sp);
				// We decided that the word code will not be the basis for
				// LIR/MIR generation, so there's no sense in emitting a coerce_a
				// instruction for the interpreter here - since all stacked
				// values in the interpreter are atoms already.
				break;
			}

			case OP_convert_i:
			case OP_coerce_i:
			{
				checkStack(1,1);
				emitCoerce(INT_TYPE, sp);
				XLAT_ONLY( if (translator) translator->emitOp0(pc, wordCode(opcode)) );
				break;
			}

			case OP_convert_u:
			case OP_coerce_u:
			{
				checkStack(1,1);
				emitCoerce(UINT_TYPE, sp);
				XLAT_ONLY( if (translator) translator->emitOp0(pc, wordCode(opcode)) );
				break;
			}

			case OP_convert_d:
			case OP_coerce_d:
			{
				checkStack(1,1);
				emitCoerce(NUMBER_TYPE, sp);
				XLAT_ONLY( if (translator) translator->emitOp0(pc, wordCode(opcode)) );
				break;
			}

			case OP_coerce_s:
			{
				checkStack(1,1);
				emitCoerce(STRING_TYPE, sp);
				XLAT_ONLY( if (translator) translator->emitOp0(pc, WOP_coerce_s) );
				break;
			}

			case OP_istype: 
			{
				checkStack(1,1);
				// resolve operand into a traits, and test if value is that type
				JIT_ONLY( Traits* itraits = ) checkTypeName(imm30); // CONSTANT_Multiname
				JIT_ONLY( if (jit) jit->emit(state, opcode, (uintptr)itraits, sp, BOOLEAN_TYPE); )
				state->pop();
				state->pop();
				state->push(OBJECT_TYPE);
				state->push(INT_TYPE);
				XLAT_ONLY( if (translator) translator->emitOp1(pc, WOP_istype) );
				break;
			}

			case OP_istypelate: 
			{
				checkStack(2,1);
				JIT_ONLY( if (jit) jit->emit(state, opcode, 0, 0, BOOLEAN_TYPE); )
				// TODO if the only common base type of lhs,rhs is Object, then result is always false
				state->pop_push(2, BOOLEAN_TYPE);
				XLAT_ONLY( if (translator) translator->emitOp0(pc, WOP_istypelate) );
				break;
			}

			case OP_convert_o:
			{	
				checkStack(1,1);
				// ISSUE should result be Object, laundering the type?
				// ToObject throws an exception on null and undefined, so after this runs we
				// know the value is safe to dereference.
				JIT_ONLY( if (jit) emitCheckNull(sp); )
				XLAT_ONLY( if (translator) translator->emitOp0(pc, WOP_convert_o) );
				break;
			}

			case OP_convert_s: 
			case OP_esc_xelem: 
			case OP_esc_xattr:
			{
				checkStack(1,1);
				// this is the ECMA ToString and ToXMLString operators, so the result must not be null
				// (ToXMLString is split into two variants - escaping elements and attributes)
				emitToString(opcode, sp);
				XLAT_ONLY( if (translator) translator->emitOp0(pc, wordCode(opcode)) );
				break;
			}

			case OP_callstatic: 
			{
				AbstractFunction* m = checkMethodInfo(imm30);
				JIT_ONLY( int method_id = m->method_id; )
				const uint32_t argc = imm30b;

				checkStack(argc+1, 1);

				if (!m->paramTraits(0))
				{
					verifyFailed(kDanglingFunctionError, core->toErrorString(m), core->toErrorString(info));
				}

				#ifdef AVMPLUS_VERIFYALL
				core->enq(m);
				#endif

				emitCoerceArgs(m, argc);
				
				Traits* resultType = m->returnTraits();
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				if (jit)
				{
					emitCheckNull(sp-argc);
					jit->emitSetContext(state, m);
					jit->emitCall(state, OP_callstatic, method_id, argc, resultType);
				}
				#endif
				state->pop_push(argc+1, resultType);
				XLAT_ONLY( if (translator) translator->emitOp2(pc, WOP_callstatic) );
				break;
			}

			case OP_call: 
			{
				const uint32_t argc = imm30;
				checkStack(argc+2, 1);
				// don't need null check, AvmCore::call() uses toFunction() for null check.
				
				/* 
					TODO optimizations
					    - if this is a class closure for a non-native type, call == coerce
						- if this is a function closure, try early binding using the traits->call sig
						- optimize simple cases of casts to builtin types
				*/
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				if (jit) 
				{
					jit->emitSetContext(state, NULL);
					jit->emit(state, opcode, argc, 0, NULL);
				}
				#endif
				state->pop_push(argc+2, NULL);
				XLAT_ONLY( if (translator) translator->emitOp1(pc, WOP_call) );
				break;
			}

			case OP_construct: 
			{
				// in: ctor arg1..N
				// out: obj
				const uint32_t argc = imm30;
				checkStack(argc+1, 1);
				Traits* ctraits = state->peek(argc+1).traits;
				// don't need null check, AvmCore::construct() uses toFunction() for null check.
				Traits* itraits = ctraits ? ctraits->itraits : NULL;
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				if (jit)
				{
					jit->emitSetContext(state, NULL);
					jit->emit(state, opcode, argc, 0, itraits);
				}
				#endif
				state->pop_push(argc+1, itraits, true);
				XLAT_ONLY( if (translator) translator->emitOp1(pc, WOP_construct) );
				break;
			}

			case OP_callmethod: 
			{
				/*
					OP_callmethod will always throw a verify error.  that's on purpose, it's a 
					last minute change before we shipped FP9 and was necessary when we added methods to class Object.
					 
					since then we realized that OP_callmethod need only have failed when used outside
					of the builtin abc, but it's a moot point now.  We dont have to worry about it.
					 
					code has since been simplified but existing failure modes preserved.
				*/
				const uint32_t argc = imm30b;
				const int disp_id = imm30-1;
				checkStack(argc+1,1);
				if (disp_id >= 0)
				{
					Value& obj = state->peek(argc+1);
					if( !obj.traits ) 
						verifyFailed(kCorruptABCError);
					else
						verifyFailed(kIllegalEarlyBindingError, core->toErrorString(obj.traits));
				}
				else
				{
					verifyFailed(kZeroDispIdError);
				}
				break;
			}

			case OP_callproperty: 
			case OP_callproplex: 
			case OP_callpropvoid:
			{
				// stack in: obj [ns [name]] args
				// stack out: result
				const uint32_t argc = imm30b;
				Multiname multiname;
				checkConstantMultiname(imm30, multiname);
				checkStackMulti(argc+1, 1, &multiname);

				checkCallMultiname(opcode, &multiname);

				uint32_t n = argc+1; // index of receiver
				checkPropertyMultiname(n, multiname);

				emitCallproperty(opcode, sp, multiname, imm30, imm30b);
				break;
			}

			case OP_constructprop: 
			{
				// stack in: obj [ns [name]] args
				const uint32_t argc = imm30b;
				Multiname multiname;
				checkConstantMultiname(imm30, multiname);
				checkStackMulti(argc+1, 1, &multiname);

				checkCallMultiname(opcode, &multiname);

				uint32_t n = argc+1; // index of receiver
				checkPropertyMultiname(n, multiname);

				Value& obj = state->peek(n); // make sure object is there
				JIT_ONLY( if (jit) emitCheckNull(sp-(n-1)); )

				#ifdef DEBUG_EARLY_BINDING
				//core->console << "verify constructprop " << t << " " << multiname->getName() << " from within " << info << "\n";
				#endif

				Binding b = toplevel->getBinding(obj.traits, &multiname);
				
				if (AvmCore::isSlotBinding(b))
				{
					JIT_ONLY( int slot_id = AvmCore::bindingToSlotId(b); )
					Traits* ctraits = readBinding(obj.traits, b);
					MIR_ONLY( if (jit) jit->emit(state, OP_getslot, slot_id, sp-(n-1), ctraits); )
					LIR_ONLY( if (jit) jit->emitGetslot(state, slot_id, sp-(n-1), ctraits); )
					obj.notNull = false;
					obj.traits = ctraits;
					Traits* itraits = ctraits ? ctraits->itraits : NULL;
					#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
					if (jit)
					{
						jit->emitSetContext(state, NULL);
						if( itraits && !itraits->hasCustomConstruct && itraits->init->argcOk(argc))
						{
							emitCheckNull(sp-(n-1));
							emitCoerceArgs(itraits->init, argc, true);
							jit->emitCall(state, OP_construct, 0, argc, itraits);
						}
						else
						{
							jit->emit(state, OP_construct, argc, 0, itraits);
						}
					}
					#endif
					state->pop_push(argc+1, itraits, true);
					goto constructprop_end;
				}

				// don't know the binding now, resolve at runtime
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				if (jit) 
				{
					jit->emitSetContext(state, NULL);
					jit->emit(state, opcode, (uintptr)&multiname, argc, NULL);
				}
				#endif
				state->pop_push(n, NULL);
			constructprop_end:
				XLAT_ONLY( if (translator) translator->emitOp2(pc, WOP_constructprop) );
				break;
			}

			case OP_applytype: 
			{
				// in: factory arg1..N
				// out: type
				const uint32_t argc = imm30;
				checkStack(argc+1, 1);
				// * is ok for the type, as Vector classes have no statics
				// when we implement type parameters fully, we should do something here.
				Traits* itraits = NULL;
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				if (jit)
				{
					jit->emitSetContext(state, NULL);
					jit->emit(state, opcode, argc, 0, itraits);
				}
				#endif
				state->pop_push(argc+1, itraits, true);
				XLAT_ONLY( if (translator) translator->emitOp1(pc, WOP_applytype) );
				break;
			}

			case OP_callsuper: 
			case OP_callsupervoid:
			{
				// stack in: obj [ns [name]] args
				const uint32_t argc = imm30b;
				Multiname multiname;
				checkConstantMultiname(imm30, multiname);
				checkStackMulti(argc+1, 1, &multiname);

				if (multiname.isAttr())
					verifyFailed(kIllegalOpMultinameError, core->toErrorString(&multiname));
				
				uint32_t n = argc+1; // index of receiver
				checkPropertyMultiname(n, multiname);

				JIT_ONLY( if (jit) emitCheckNull(sp-(n-1)); )
				Traits* base = emitCoerceSuper(sp-(n-1));
				const TraitsBindingsp basetd = base->getTraitsBindings();

				Binding b = toplevel->getBinding(base, &multiname);
				if (AvmCore::isMethodBinding(b))
				{
					int disp_id = AvmCore::bindingToMethodId(b);
					AbstractFunction* m = basetd->getMethod(disp_id);
					if( !m ) verifyFailed(kCorruptABCError);
					emitCoerceArgs(m, argc);
					Traits* resultType = m->returnTraits();
					#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
					if (jit) 
					{
						jit->emitSetContext(state, m);
						jit->emitCall(state, OP_callsuperid, disp_id, argc, resultType);
					}
					#endif
					state->pop_push(n, resultType);
					if (opcode == OP_callsupervoid)
						state->pop();
					goto callsuper_end;
				}

				#ifdef DEBUG_EARLY_BINDING
				core->console << "verify callsuper " << base << " " << multiname.getName() << " from within " << info << "\n";
				#endif

				// TODO optimize other cases
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				if (jit)
				{
					jit->emitSetContext(state, NULL);
					jit->emit(state, opcode, (uintptr)&multiname, argc, NULL);
				}
				#endif
				state->pop_push(n, NULL);
				if (opcode == OP_callsupervoid)
					state->pop();
			callsuper_end:
				XLAT_ONLY( if (translator) translator->emitOp2(pc, wordCode(opcode)) );
				break;
			}

			case OP_getsuper:
			{
				// stack in: obj [ns [name]]
				// stack out: value
				Multiname multiname;
				checkConstantMultiname(imm30, multiname);
				checkStackMulti(1, 1, &multiname);
				uint32_t n=1;
				checkPropertyMultiname(n, multiname);

				if (multiname.isAttr())
					verifyFailed(kIllegalOpMultinameError, core->toErrorString(&multiname));

				int ptrIndex = sp-(n-1);
				Traits* base = emitCoerceSuper(ptrIndex);

				Binding b = toplevel->getBinding(base, &multiname);
				Traits* propType = readBinding(base, b);
				
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				if (jit)
				{
					emitCheckNull(ptrIndex);

					if (AvmCore::isSlotBinding(b))
					{
						int slot_id = AvmCore::bindingToSlotId(b);
						MIR_ONLY(if (jit) jit->emit(state, OP_getslot, slot_id, ptrIndex, propType);)
						LIR_ONLY(if (jit) jit->emitGetslot(state, slot_id, ptrIndex, propType);)
						state->pop_push(n, propType);
						goto getsuper_end;
					}

					if (AvmCore::hasGetterBinding(b))
					{
						// Invoke the getter
						int disp_id = AvmCore::bindingToGetterId(b);
						const TraitsBindingsp basetd = base->getTraitsBindings();
						AbstractFunction *f = basetd->getMethod(disp_id);
						AvmAssert(f != NULL);
						emitCoerceArgs(f, 0);
						Traits* resultType = f->returnTraits();
						if (jit) 
						{
							jit->emitSetContext(state, f);
							jit->emitCall(state, OP_callsuperid, disp_id, 0, resultType);
						}
						state->pop_push(n, resultType);
						goto getsuper_end;
					}
				}
				#endif // AVMPLUS_MIR || FEATURE_NANOJIT

				#ifdef DEBUG_EARLY_BINDING
				core->console << "verify getsuper " << base << " " << multiname.getName() << " from within " << info << "\n";
				#endif
				
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				if (jit) 
				{
					jit->emitSetContext(state, NULL);
					jit->emit(state, opcode, (uintptr)&multiname, 0, propType);
				}
				#endif
				state->pop_push(n, propType);
#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
			getsuper_end:
#endif
				XLAT_ONLY( if (translator) translator->emitOp1(pc, WOP_getsuper) );
				break;
			}

			case OP_setsuper:
			{
				// stack in: obj [ns [name]] value
				Multiname multiname;
				checkConstantMultiname(imm30, multiname);
				checkStackMulti(2, 0, &multiname);
				uint32_t n=2;
				checkPropertyMultiname(n, multiname);

				if (multiname.isAttr())
					verifyFailed(kIllegalOpMultinameError, core->toErrorString(&multiname));

				int ptrIndex = sp-(n-1);
				JIT_ONLY( Traits* base = ) emitCoerceSuper(ptrIndex);
				
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				if (jit)
				{
					emitCheckNull(ptrIndex);

					const TraitsBindingsp basetd = base->getTraitsBindings();
					Binding b = toplevel->getBinding(base, &multiname);
					Traits* propType = readBinding(base, b);

					if (AvmCore::isSlotBinding(b))
					{
						if (AvmCore::isVarBinding(b))
						{
							int slot_id = AvmCore::bindingToSlotId(b);
							emitCoerce(propType, sp);
							MIR_ONLY(jit->emit(state, OP_setslot, slot_id, ptrIndex);)
							LIR_ONLY(jit->emitSetslot(state, OP_setslot, slot_id, ptrIndex);)
						}
						// else, it's a readonly slot so ignore
						state->pop(n);
						goto setsuper_end;
					}

					if (AvmCore::isAccessorBinding(b))
					{
						if (AvmCore::hasSetterBinding(b))
						{
							// Invoke the setter
							int disp_id = AvmCore::bindingToSetterId(b);
							AbstractFunction *f = basetd->getMethod(disp_id);
							AvmAssert(f != NULL);
							emitCoerceArgs(f, 1);
							jit->emitSetContext(state, f);
							jit->emitCall(state, OP_callsuperid, disp_id, 1, f->returnTraits());
						}
						// else, ignore write to readonly accessor
						state->pop(n);
						goto setsuper_end;
					}

					#ifdef DEBUG_EARLY_BINDING
					core->console << "verify setsuper " << base << " " << multiname.getName() << " from within " << info << "\n";
					#endif

					jit->emitSetContext(state, NULL);
					jit->emit(state, opcode, (uintptr)&multiname);
				}
				#endif // AVMPLUS_MIR || FEATURE_NANOJIT

				state->pop(n);
#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
			setsuper_end:
#endif
				XLAT_ONLY( if (translator) translator->emitOp1(pc, WOP_setsuper) );
				break;
			}

			case OP_constructsuper:
			{
				// stack in: obj, args ...
				const uint32_t argc = imm30;
				checkStack(argc+1, 0);

				int ptrIndex = sp-argc;
				Traits* baseTraits = emitCoerceSuper(ptrIndex); // check receiver

				AbstractFunction *f = baseTraits->init;
				AvmAssert(f != NULL);

				emitCoerceArgs(f, argc);
				
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				if (jit)
				{
					jit->emitSetContext(state, f);
					emitCheckNull(ptrIndex);
					jit->emitCall(state, opcode, 0, argc, VOID_TYPE);
				}
				#endif

				state->pop(argc+1);
				// this is a true void call, no result to push.
				XLAT_ONLY( if (translator) translator->emitOp1(pc, WOP_constructsuper) );
				break;
			}

			case OP_newobject: 
			{
				uint32_t argc = imm30;
				checkStack(2*argc, 1);
				int n=0;
				while (argc-- > 0)
				{
					n += 2;
					peekType(STRING_TYPE, n); // name; will call intern on it 
				}
				JIT_ONLY( if (jit) jit->emit(state, opcode, imm30, 0, OBJECT_TYPE); )
				state->pop_push(n, OBJECT_TYPE, true);
				XLAT_ONLY( if (translator) translator->emitOp1(pc, WOP_newobject) );
				break;
			}

			case OP_newarray: 
			{
				const uint32_t argc = imm30;
				checkStack(argc, 1);
				JIT_ONLY( if (jit) jit->emit(state, opcode, argc, 0, ARRAY_TYPE); )
				state->pop_push(argc, ARRAY_TYPE, true);
				XLAT_ONLY( if (translator) translator->emitOp1(pc, WOP_newarray) );
				break;
			}

			case OP_pushscope: 
			{
				checkStack(1,0);
				Traits* scopeTraits = state->peek().traits;
				
				if (state->scopeDepth+1 > max_scope) 
					verifyFailed(kScopeStackOverflowError);
				
				if (scope->fullsize > (scope->size+state->scopeDepth))
				{
					// extra constraints on type of pushscope allowed
					Traits* requiredType = scope->getScopeTraitsAt(scope->size+state->scopeDepth);
					if (!scopeTraits || !scopeTraits->containsInterface(requiredType))
					{
						verifyFailed(kIllegalOperandTypeError, core->toErrorString(scopeTraits), core->toErrorString(requiredType));
					}
				}
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				if (jit)
				{
					emitCheckNull(sp);
					jit->emitCopy(state, sp, scopeBase+state->scopeDepth);
				}
				#endif
				state->pop();
				state->setType(scopeBase+state->scopeDepth, scopeTraits, true, false);
				state->scopeDepth++;
				XLAT_ONLY( if (translator) translator->emitOp0(pc, WOP_pushscope) );
				break;
			}

			case OP_pushwith: 
			{
				checkStack(1,0);
				Traits* scopeTraits = state->peek().traits;
				
				if (state->scopeDepth+1 > max_scope) 
					verifyFailed(kScopeStackOverflowError);

				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				if (jit)
				{
					emitCheckNull(sp);
					jit->emitCopy(state, sp, scopeBase+state->scopeDepth);
				}
				#endif
				state->pop();
				state->setType(scopeBase+state->scopeDepth, scopeTraits, true, true);

				if (state->withBase == -1)
				{
					state->withBase = state->scopeDepth;
				}
					
				state->scopeDepth++;
				XLAT_ONLY( if (translator) translator->emitOp0(pc, WOP_pushwith) );
				break;
			}

			case OP_newactivation: 
			{
				if (!(info->flags & AbstractFunction::NEED_ACTIVATION))
				{
					verifyFailed(kInvalidNewActivationError);
				}
				//AvmAssert(!info->activationTraits->dynamic);
				// [ed] does the vm really care if an activation object is dynamic or not?
				checkStack(0, 1);
				JIT_ONLY( if (jit) jit->emit(state, opcode, 0, 0, info->activationTraits); )
				state->push(info->activationTraits, true);
				XLAT_ONLY( if (translator) translator->emitOp0(pc, WOP_newactivation) );
				break;
			}

			case OP_newcatch: 
			{
				const int index = imm30;

				/*if (!(info->flags & AbstractFunction::NEED_ACTIVATION))
				{
					verifyFailed(kInvalidNewActivationError);
				}*/

				if (index < 0 || !info->exceptions || index >= info->exceptions->exception_count)
				{
					// todo better error msg
					verifyFailed(kInvalidNewActivationError);
				}
					
				ExceptionHandler* handler = &info->exceptions->exceptions[index];
				
				checkStack(0, 1);
				JIT_ONLY( if (jit) jit->emit(state, opcode, 0, 0, handler->scopeTraits); )
				state->push(handler->scopeTraits, true);
				XLAT_ONLY( if (translator) translator->emitOp1(pc, WOP_newcatch) );
				break;
			}
			
			case OP_popscope:
			{
				//checkStack(0,0)
				// no code to emit
				if (state->scopeDepth-- <= outer_depth)
				{
					verifyFailed(kScopeStackUnderflowError);
				}
				#ifdef DEBUGGER
				JIT_ONLY( if (jit) jit->emitKill(state, scopeBase + state->scopeDepth); )
				#endif
				if (state->withBase >= state->scopeDepth)
				{
					state->withBase = -1;
				}
				XLAT_ONLY( if (translator) translator->emitOp0(pc, WOP_popscope) );
				break;
			}

			case OP_getscopeobject: 
			{
				checkStack(0,1);
				int scope_index = imm8;
				// local scope
				if (scope_index >= state->scopeDepth)
					verifyFailed(kGetScopeObjectBoundsError, core->toErrorString(imm8));
				
				JIT_ONLY( if (jit) jit->emitCopy(state, scopeBase+scope_index, sp+1); )
				// this will copy type and all attributes too
				state->push(state->scopeValue(scope_index));
				XLAT_ONLY( if (translator) translator->emitGetscopeobject(pc) );
				break;
			}

            case OP_getouterscope:
            {
				checkStack(0,1);
				int scope_index = imm30;
				emitGetOuterScope(scope_index);
				XLAT_ONLY( if (translator) translator->emitOp1(pc, WOP_getouterscope) );
                break;
            }

			case OP_getglobalscope: 
			{
				checkStack(0,1);
				emitGetGlobalScope();
				XLAT_ONLY( if (translator) translator->emitOp0(pc, WOP_getglobalscope) );
				break;
			}
			
			case OP_getglobalslot: 
			{
				checkStack(0,1);
				emitGetGlobalScope();
				emitGetSlot(imm30-1);
				XLAT_ONLY( if (translator) translator->emitOp1(pc, WOP_getglobalslot) );
				break;
			}

			case OP_setglobalslot: 
			{
				if (!state->scopeDepth && !scope->size)
				{
					verifyFailed(kNoGlobalScopeError);
				}
				Traits *globalTraits = scope->size > 0 ? scope->getScopeTraitsAt(0) : state->scopeValue(0).traits;
				checkStack(1,0);
				checkEarlySlotBinding(globalTraits);
				JIT_ONLY( Traits* slotTraits = ) checkSlot(globalTraits, imm30-1);
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				if (jit)
				{
					emitCoerce(slotTraits, state->sp());
					jit->emit(state, opcode, imm30-1, sp, slotTraits);
				}
				#endif
				state->pop();
				XLAT_ONLY( if (translator) translator->emitOp1(pc, WOP_setglobalslot) );
				break;
			}
			
			case OP_getslot:
			{
				checkStack(1,1);
				emitGetSlot(imm30-1);
				XLAT_ONLY( if (translator) translator->emitOp1(pc, WOP_getslot) );
				break;
			}

			case OP_setslot: 
			{
				checkStack(2,0);
				emitSetSlot(imm30-1);
				XLAT_ONLY( if (translator) translator->emitOp1(pc, WOP_setslot) );
				break;
			}

			case OP_pop:
			{
				checkStack(1,0);
				state->pop();
				XLAT_ONLY( if (translator) translator->emitOp0(pc, WOP_pop) );
				break;
			}

			case OP_dup: 
			{
				checkStack(1, 2);
				Value& v = state->peek();
				JIT_ONLY( if (jit) jit->emitCopy(state, sp, sp+1); )
				state->push(v);
				XLAT_ONLY( if (translator) translator->emitOp0(pc, WOP_dup) );
				break;
			}

			case OP_swap: 
			{
				checkStack(2,2);
				emitSwap();
				XLAT_ONLY( if (translator) translator->emitOp0(pc, WOP_swap) );
				break;
			}

			case OP_lessthan:
			case OP_greaterthan:
			case OP_lessequals:
			case OP_greaterequals:
			{
				checkStack(2,1);
				emitCompare(opcode);
				XLAT_ONLY( if (translator) translator->emitOp0(pc, wordCode(opcode)) );
				break;
			}

			case OP_equals:
			case OP_strictequals:
			case OP_instanceof:
			case OP_in:
			{
				checkStack(2,1);
				JIT_ONLY( if (jit) jit->emit(state, opcode, 0, 0, BOOLEAN_TYPE); )
				state->pop_push(2, BOOLEAN_TYPE);
				XLAT_ONLY( if (translator) translator->emitOp0(pc, wordCode(opcode)) );
				break;
			}

			case OP_not:
				checkStack(1,1);
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				if (jit)
				{
					emitCoerce(BOOLEAN_TYPE, sp);
					jit->emit(state, opcode, sp);
				}
				#endif
				state->pop_push(1, BOOLEAN_TYPE);
				XLAT_ONLY( if (translator) translator->emitOp0(pc, WOP_not) );
				break;

			case OP_add: 
			{
				checkStack(2,1);
				Value& rhs = state->peek(1);
				Value& lhs = state->peek(2);
				Traits* lhst = lhs.traits;
				Traits* rhst = rhs.traits;
				// Note that for correctness the inference of the result type must
				// remain even in the non-JIT case
				if (lhst == STRING_TYPE && lhs.notNull || rhst == STRING_TYPE && rhs.notNull)
				{
					#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
					if (jit)
					{
						emitToString(OP_convert_s, sp-1);
						emitToString(OP_convert_s, sp);
						jit->emit(state, OP_concat, 0, 0, STRING_TYPE);
					}
					#endif
					state->pop_push(2, STRING_TYPE, true);
				}
				else if (lhst && lhst->isNumeric() && rhst && rhst->isNumeric())
				{
					#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
					if (jit)
					{
						emitCoerce(NUMBER_TYPE, sp-1);
						emitCoerce(NUMBER_TYPE, sp);
						jit->emit(state, OP_add_d, 0, 0, NUMBER_TYPE);
					}
					#endif
					state->pop_push(2, NUMBER_TYPE);
				}
				else
				{
					JIT_ONLY( if (jit) jit->emit(state, OP_add, 0, 0, OBJECT_TYPE); )
					// dont know if it will return number or string, but neither will be null.
					state->pop_push(2,OBJECT_TYPE, true);
				}
				XLAT_ONLY( if (translator) translator->emitOp0(pc, WOP_add) );
				break;
			}

			case OP_modulo:
			case OP_subtract:
			case OP_divide:
			case OP_multiply:
				checkStack(2,1);
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				if (jit)
				{
					emitCoerce(NUMBER_TYPE, sp-1); // convert LHS to number
					emitCoerce(NUMBER_TYPE, sp); // convert RHS to number
					jit->emit(state, opcode, 0, 0, NUMBER_TYPE);
				}
				#endif
				state->pop_push(2, NUMBER_TYPE);
				XLAT_ONLY( if (translator) translator->emitOp0(pc, wordCode(opcode)) );
				break;

			case OP_negate:
				checkStack(1,1);
				emitCoerce(NUMBER_TYPE, sp);
				JIT_ONLY( if (jit) jit->emit(state, opcode, sp, 0, NUMBER_TYPE); )
				XLAT_ONLY( if (translator) translator->emitOp0(pc, WOP_negate) );
				break;

			case OP_increment:
			case OP_decrement:
				checkStack(1,1);
				emitCoerce(NUMBER_TYPE, sp);
				JIT_ONLY( if (jit) jit->emit(state, opcode, sp, opcode == OP_increment ? 1 : -1, NUMBER_TYPE); )
				XLAT_ONLY( if (translator) translator->emitOp0(pc, wordCode(opcode)) );
				break;

			case OP_increment_i:
			case OP_decrement_i:
				checkStack(1,1);
				emitCoerce(INT_TYPE, sp);
				JIT_ONLY( if (jit) jit->emit(state, opcode, state->sp(), opcode == OP_increment_i ? 1 : -1, INT_TYPE); )
				XLAT_ONLY( if (translator) translator->emitOp0(pc, wordCode(opcode)) );
				break;

			case OP_add_i:
			case OP_subtract_i:
			case OP_multiply_i:
				checkStack(2,1);
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				if (jit)
				{
					emitCoerce(INT_TYPE, sp-1);
					emitCoerce(INT_TYPE, sp);
					jit->emit(state, opcode, 0, 0, INT_TYPE);
				}
				#endif
				state->pop_push(2, INT_TYPE);
				XLAT_ONLY( if (translator) translator->emitOp0(pc, wordCode(opcode)) );
				break;

			case OP_negate_i:
				checkStack(1,1);
				emitCoerce(INT_TYPE, sp);
				JIT_ONLY( if (jit) jit->emit(state, opcode, sp, 0, INT_TYPE); )
				XLAT_ONLY( if (translator) translator->emitOp0(pc, WOP_negate_i) );
				break;

			case OP_bitand:
			case OP_bitor:
			case OP_bitxor:
				checkStack(2,1);
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				if (jit)
				{
					emitCoerce(INT_TYPE, sp-1);
					emitCoerce(INT_TYPE, sp);
					jit->emit(state, opcode, 0, 0, INT_TYPE);
				}
				#endif
				state->pop_push(2, INT_TYPE);
				XLAT_ONLY( if (translator) translator->emitOp0(pc, wordCode(opcode)) );
				break;

			// ISSUE do we care if shift amount is signed or not?  we mask 
			// the result so maybe it doesn't matter.
			// CN says see tests e11.7.2, 11.7.3, 9.6
			case OP_lshift:
			case OP_rshift:
				checkStack(2,1);
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				if (jit)
				{
					emitCoerce(INT_TYPE, sp-1); // lhs
					emitCoerce(UINT_TYPE, sp); // rhs
					jit->emit(state, opcode, 0, 0, INT_TYPE);
				}
				#endif
				state->pop_push(2, INT_TYPE);
				XLAT_ONLY( if (translator) translator->emitOp0(pc, wordCode(opcode)) );
				break;

			case OP_urshift:
				checkStack(2,1);
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				if (jit)
				{
					emitCoerce(UINT_TYPE, sp-1); // lhs
					emitCoerce(UINT_TYPE, sp); // rhs
					jit->emit(state, opcode, 0, 0, UINT_TYPE);
				}
				#endif
				state->pop_push(2, UINT_TYPE);
				XLAT_ONLY( if (translator) translator->emitOp0(pc, WOP_urshift) );
				break;

			case OP_bitnot:
				checkStack(1,1);
				emitCoerce(INT_TYPE, sp); // lhs
				JIT_ONLY( if (jit) jit->emit(state, opcode, sp, 0, INT_TYPE); )
				XLAT_ONLY( if (translator) translator->emitOp0(pc, WOP_bitnot) );
				break;

			case OP_typeof:
			{
				checkStack(1,1);
				JIT_ONLY( if (jit) jit->emit(state, opcode, sp, 0, STRING_TYPE); )
				state->pop_push(1, STRING_TYPE, true);
				XLAT_ONLY( if (translator) translator->emitOp0(pc, WOP_typeof) );
				break;
			}

			case OP_nop:
				break;
					
			case OP_debug:
#ifdef DEBUGGER
				XLAT_ONLY( if (translator) translator->emitDebug(pc) );
#endif
				break;
					
			case OP_label:
				XLAT_ONLY( if (translator) translator->emitLabel(pc) );
				break;

			case OP_debugline:
				#if defined(DEBUGGER) || defined(VTUNE)
				// we actually do generate code for these, in debugger mode
				JIT_ONLY( if (jit) jit->emit(state, opcode, imm30); )
				#endif
#ifdef DEBUGGER
				XLAT_ONLY( if (translator) translator->emitOp1(pc, WOP_debugline) );
#endif
				break;

			case OP_nextvalue:
			case OP_nextname:
			{
				checkStack(2,1);
				peekType(INT_TYPE,1);
				JIT_ONLY( if (jit) jit->emit(state, opcode, 0, 0, NULL); )
				state->pop_push(2, NULL);
				XLAT_ONLY( if (translator) translator->emitOp0(pc, wordCode(opcode)) );
				break;
			}

			case OP_hasnext:
			{
				checkStack(2,1);
				peekType(INT_TYPE,1);
				JIT_ONLY( if (jit) jit->emit(state, opcode, 0, 0, INT_TYPE); )
				state->pop_push(2, INT_TYPE);
				XLAT_ONLY( if (translator) translator->emitOp0(pc, WOP_hasnext) );
				break;
			}

			case OP_hasnext2:
			{
				checkStack(0,1);
				checkLocal(imm30);
				Value& v = checkLocal(imm30b);
				if (imm30 == imm30b)
				{
					verifyFailed(kInvalidHasNextError);
				}
				if (v.traits != INT_TYPE)
				{
					verifyFailed(kIllegalOperandTypeError, core->toErrorString(v.traits), core->toErrorString(INT_TYPE));
				}
				JIT_ONLY( if (jit) jit->emit(state, opcode, imm30, imm30b, BOOLEAN_TYPE); )
				state->setType(imm30, NULL, false);
				state->push(BOOLEAN_TYPE);
				XLAT_ONLY( if (translator) translator->emitOp2(pc, WOP_hasnext2) );
				break;
			}


#ifdef AVMPLUS_MOPS
			// sign extends
			case OP_sxi1:
			case OP_sxi8:
			case OP_sxi16:
			{
				checkStack(1,1);
				emitCoerce(INT_TYPE, sp);
				JIT_ONLY( if (jit) jit->emit(state, opcode, sp, 0, INT_TYPE); )
				state->pop_push(1, INT_TYPE);
				XLAT_ONLY( if (translator) translator->emitOp0(pc, wordCode(opcode)); )
				break;
			}

			// loads
			case OP_li8:
			case OP_li16:
			case OP_li32:
			case OP_lf32:
			case OP_lf64:
			{
				Traits* result = (opcode == OP_lf32 || opcode == OP_lf64) ? NUMBER_TYPE : INT_TYPE;
				checkStack(1,1);
				emitCoerce(INT_TYPE, sp);
				JIT_ONLY( if (jit) jit->emit(state, opcode, sp, 0, result); )
				state->pop_push(1, result);
				XLAT_ONLY( if (translator) translator->emitOp0(pc, wordCode(opcode)); )
				break;
			}

			// stores
			case OP_si8:
			case OP_si16:
			case OP_si32:
			case OP_sf32:
			case OP_sf64:
			{
				checkStack(2,0);
				#if defined(AVMPLUS_MIR) || defined(FEATURE_NANOJIT)
				if (jit)
				{
					emitCoerce((opcode == OP_sf32 || opcode == OP_sf64) ? NUMBER_TYPE : INT_TYPE, sp-1);
					emitCoerce(INT_TYPE, sp);
					jit->emit(state, opcode, 0, 0, VOID_TYPE);
				}
				#endif
				state->pop(2);
				XLAT_ONLY( if (translator) translator->emitOp0(pc, wordCode(opcode)); )
				break;
			}
#endif

			case OP_abs_jump:
			{
				// first ensure the executing code isn't user code (only VM generated abc can use this op)
				if(pool->isCodePointer(pc))
				{
					verifyFailed(kIllegalOpcodeError, core->toErrorString(info), core->toErrorString(OP_abs_jump), core->toErrorString((int)(pc-code_pos)));
				}

				#ifdef AVMPLUS_64BIT
				const byte* new_pc = (const byte *) (uintptr(imm30) | (((uintptr) imm30b) << 32));
				const byte* new_code_end = new_pc + AvmCore::readU30 (nextpc);
				#else
				const byte* new_pc = (const byte*) imm30;
				const byte* new_code_end = new_pc + imm30b;
				#endif

				// now ensure target points to within pool's script buffer
				if(!pool->isCodePointer(new_pc))
				{
					verifyFailed(kIllegalOpcodeError, core->toErrorString(info), core->toErrorString(OP_abs_jump), core->toErrorString((int)(pc-code_pos)));
				}

				// FIXME: what other verification steps should we do here?

				pc = code_pos = new_pc;
				code_end = new_code_end;
				size = 0;
				
				//set jit abcStart/End
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				if(jit) {
					jit->abcStart = pc;
					jit->abcEnd = code_end;
					//core->GetGC()->Free((void*) info->body_pos);
					//info->body_pos = NULL;
				}
				#endif

				exceptions_pos = code_end;
				code_length = int(code_end - pc);
				parseExceptionHandlers();
				XLAT_ONLY( if (translator) translator->emitAbsJump(pc) );  // the new PC
				break;
			}

			default:
				// size was nonzero, but no case handled the opcode.  someone asleep at the wheel!
				AvmAssert(false);
			}
			
			JIT_ONLY( if (jit) jit->opcodeVerified(opcode, state); )
		}
		
		if (!blockEnd)
		{
			verifyFailed(kCannotFallOffMethodError);
		}
		if (blockStates && actualCount != labelCount) 
		{
			verifyFailed(kInvalidBranchTargetError);
		}

#ifdef AVMPLUS_WORD_CODE
		if (translator) {
			info->word_code.cache_size = next_cache;
			translator->epilogue();
			delete translator;
		}
#endif
        JIT_ONLY(if (jit) jit->epilogue(state);)
			
		#ifdef FEATURE_BUFFER_GUARD
		#ifdef AVMPLUS_MIR
		growthGuard = NULL;
		#endif
		#endif

		} CATCH (Exception *exception) {

			// clean up growthGuard
#ifdef FEATURE_BUFFER_GUARD
#ifdef AVMPLUS_MIR
		    // Make sure the GrowthGuard is unregistered
			if (growthGuard)
			{
					growthGuard->~GrowthGuard();
//					growthGuard = NULL;
			}
#endif
#endif
		XLAT_ONLY( if (translator) delete translator; )
			// re-throw exception
			core->throwException(exception);
		}
		END_CATCH
		END_TRY
	}

	void Verifier::checkPropertyMultiname(uint32_t &depth, Multiname &multiname)
	{
		if (multiname.isRtname())
		{
			if (multiname.isQName())
			{
				// a.ns::@[name] or a.ns::[name]
				peekType(STRING_TYPE, depth++);
			}
			else
			{
				// a.@[name] or a[name]
				depth++;
			}
		}

		if (multiname.isRtns())
		{
			peekType(NAMESPACE_TYPE, depth++);
		}
	}

	void Verifier::emitCallproperty(AbcOpcode opcode, int& sp, Multiname& multiname, uint32_t multiname_index, uint32_t argc)
	{
		uint32_t n = argc+1;
		Traits* t = state->peek(n).traits;
		
		Binding b = toplevel->getBinding(t, &multiname);
		if (t)
			t->resolveSignatures(toplevel);

		JIT_ONLY( if (jit) emitCheckNull(sp-(n-1)) );
		
		if (emitCallpropertyMethod(opcode, t, b, multiname, multiname_index, argc))
			goto callproperty_done;
		
		if (emitCallpropertySlot(opcode, sp, t, b, argc))
			goto callproperty_done;
		
		// don't know the binding now, resolve at runtime
		XLAT_ONLY( if (translator) translator->emitOp2(wordCode(opcode), multiname_index, argc) );
		JIT_ONLY( if (jit) {
				      jit->emitSetContext(state, NULL);
				      jit->emit(state, opcode, (uintptr)&multiname, argc, NULL);
				   });
		
		// If early binding then the state will have been updated, so this will be skipped
		state->pop_push(n, NULL);
		if (opcode == OP_callpropvoid)
			state->pop();
		
	callproperty_done:
		;
#ifdef DEBUG_EARLY_BINDING
		core->console << "verify callproperty " << t << " " << multiname->getName() << " from within " << info << "\n";
#endif
	}

	bool Verifier::emitCallpropertyMethod(AbcOpcode opcode, Traits* t, Binding b, Multiname& multiname, uint32_t multiname_index, uint32_t argc) 
	{
#ifndef AVMPLUS_WORD_CODE
		(void)multiname_index;
#endif
		if (!AvmCore::isMethodBinding(b))
			return false;

		uint32_t n = argc+1;
		
		const TraitsBindingsp tb = t->getTraitsBindings();

		if (t == core->traits.math_ctraits)
			b = findMathFunction(tb, multiname, b, argc);
		else if (t == core->traits.string_itraits)
			b = findStringFunction(tb, multiname, b, argc);
		
		int disp_id = AvmCore::bindingToMethodId(b);
		AbstractFunction* m = tb->getMethod(disp_id);
		
		if (!m->argcOk(argc))
			return false;
		
		Traits* resultType = m->returnTraits();

#if defined AVMPLUS_WORD_CODE	
		if (translator)
		{
			if (t->isInterface) 
			{
				// OPTIMIZEME - early-bind OP_callinterface for the interpreter
				// The interpreter currently does not handle OP_callinterface at all.
				
				// We model the effect of returning 'false' from the present
				// method.  We can't just return 'false' here because we must
				// emit good code for the JIT (below).  So do what must be done 
				// and then return 'true'.

				translator->emitOp2(wordCode(opcode), multiname_index, argc);
				// OK to keep the resultType here, even if we don't exploit it.
				// Actually it's necessary - type modeling must not depend on the
				// execution engine, so we can't set it to NULL.
			}
			else
			{
				translator->emitOp2(WOP_callmethod, disp_id+1, argc);
				if (opcode == OP_callpropvoid)
					translator->emitOp0(WOP_pop);
			}
		}
#endif
#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
		if (jit)
		{
			emitCoerceArgs(m, argc);
			jit->emitSetContext(state, m);
			if (!t->isInterface)
				jit->emitCall(state, OP_callmethod, disp_id, argc, resultType);
			else
				jit->emitCall(state, OP_callinterface, m->iid(), argc, resultType);
		}
#endif
		state->pop_push(n, resultType);
		if (opcode == OP_callpropvoid)
			state->pop();
		return true;
	}
	
	bool Verifier::emitCallpropertySlot(AbcOpcode opcode, int& sp, Traits* t, Binding b, uint32_t argc) 
	{
		if (!AvmCore::isSlotBinding(b) || argc != 1)
			return false;
		
		const TraitsBindingsp tb = t->getTraitsBindings();

		int slot_id = AvmCore::bindingToSlotId(b);
		Traits* slotType = tb->getSlotTraits(slot_id);
		
		if (slotType == core->traits.int_ctraits)
		{
			JIT_ONLY( if (jit) emitCoerce(INT_TYPE, sp) );
			XLAT_ONLY( if (translator) translator->emitOp0(WOP_convert_i) );
			state->setType(sp, INT_TYPE, true); 
			goto fast_path;
		}
		if (slotType == core->traits.uint_ctraits)
		{
			JIT_ONLY( if (jit) emitCoerce(UINT_TYPE, sp) );
			XLAT_ONLY( if (translator) translator->emitOp0(WOP_convert_u) );
			state->setType(sp, UINT_TYPE, true);
			goto fast_path;
		}
		if (slotType == core->traits.number_ctraits)
		{
			JIT_ONLY( if (jit) emitCoerce(NUMBER_TYPE, sp) );
			XLAT_ONLY( if (translator) translator->emitOp0(WOP_convert_d) );
			state->setType(sp, NUMBER_TYPE, true);
			goto fast_path;
		}
		if (slotType == core->traits.boolean_ctraits)
		{
			JIT_ONLY( if (jit) emitCoerce(BOOLEAN_TYPE, sp) );
			XLAT_ONLY( if (translator) translator->emitOp0(WOP_convert_b) );
			state->setType(sp, BOOLEAN_TYPE, true); 
			goto fast_path;
		}
		if (slotType == core->traits.string_ctraits)
		{
			JIT_ONLY( if (jit) emitToString(OP_convert_s, sp) );
			XLAT_ONLY( if (translator) translator->emitOp0(WOP_convert_s) );
			state->setType(sp, STRING_TYPE, true); 
			goto fast_path;
		}
#if	defined AVMPLUS_MIR || defined FEATURE_NANOJIT
		if (jit && slotType && slotType->base == CLASS_TYPE && slotType->getCreateClassClosureProc() == NULL)
		{
			// is this a user defined class?  A(1+ args) means coerce to A
			AvmAssert(slotType->itraits != NULL);
			emitCoerce(slotType->itraits, state->sp());
			goto fast_path2;
		}
#endif
		return false;
	
	fast_path:
#if defined AVMPLUS_WORD_CODE
		if (translator)
		{
			if (opcode == OP_callpropvoid)
			{
				translator->emitOp0(WOP_pop);  // result
				translator->emitOp0(WOP_pop);  // function
			}
			else
			{
				translator->emitOp0(WOP_swap); // function on top
				translator->emitOp0(WOP_pop);  //   and discard it
			}
		}
#endif
#if	defined AVMPLUS_MIR || defined FEATURE_NANOJIT
	fast_path2:
#endif
		emitNip();
		if (opcode == OP_callpropvoid)
			state->pop();
		return true;
	}

	void Verifier::emitCompare(AbcOpcode opcode)
	{
		// if either the LHS or RHS is a number type, then we know
		// it will be a numeric comparison.

		#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
		Value& rhs = state->peek(1);
		Value& lhs = state->peek(2);
		Traits *lhst = lhs.traits;
		Traits *rhst = rhs.traits;
		if (jit)
		{
			if (rhst && rhst->isNumeric() && lhst && !lhst->isNumeric())
			{
				// convert lhs to Number
				emitCoerce(NUMBER_TYPE, state->sp()-1);
			}
			else if (lhst && lhst->isNumeric() && rhst && !rhst->isNumeric())
			{
				// promote rhs to Number
				emitCoerce(NUMBER_TYPE, state->sp());
			}
			jit->emit(state, opcode, 0, 0, BOOLEAN_TYPE);
		}
		#else
		(void)opcode;
		#endif
		state->pop_push(2, BOOLEAN_TYPE);
	}

	void Verifier::emitFindProperty(AbcOpcode opcode, Multiname& multiname, uint32_t imm30)
	{
#ifndef AVMPLUS_WORD_CODE
		(void)imm30;
#endif
		XLAT_ONLY(bool no_translate = false);
		ScopeTypeChain* scope = info->declaringTraits->scope;
		if (multiname.isBinding())
		{
			int index = scopeBase + state->scopeDepth - 1;
			int base = scopeBase;
			if (scope->size == 0)
			{
				// if scope->size = 0, then global is a local
				// scope, and we dont want to early bind to global.
				base++;
			}
			for (; index >= base; index--)
			{
				Value& v = state->value(index);
				Binding b = toplevel->getBinding(v.traits, &multiname);
				if (b != BIND_NONE)
				{
					JIT_ONLY( if (jit) jit->emitCopy(state, index, state->sp()+1); )
					state->push(v);
					XLAT_ONLY( if (translator) translator->emitOp1(WOP_getscopeobject, index-scopeBase) );
					return;
				}
				if (v.isWith)
					break;  // with scope could have dynamic property
			}
			if (index < base)
			{
				// look at captured scope types
				for (index = scope->size-1; index > 0; index--)
				{
					Traits* t = scope->getScopeTraitsAt(index);
					Binding b = toplevel->getBinding(t, &multiname);
					if (b != BIND_NONE)
					{
						JIT_ONLY( if (jit) jit->emitGetscope(state, index, state->sp()+1); )
						state->push(t, true);
						XLAT_ONLY( if (translator) translator->emitOp1(WOP_getouterscope, index) );
						return;
					}
					if (scope->getScopeIsWithAt(index))
						break;  // with scope could have dynamic property
				}
				if (index <= 0)
				{
					// look at import table for a suitable script
					AbstractFunction* script = (AbstractFunction*)pool->getNamedScript(&multiname);
					if (script != (AbstractFunction*)BIND_NONE && script != (AbstractFunction*)BIND_AMBIGUOUS)
					{
						#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
						if (jit)
						{
							if (script == info)
							{
								// ISSUE what if there is an ambiguity at runtime? is VT too early to bind?
								// its defined here, use getscopeobject 0
								if (scope->size > 0)
									jit->emitGetscope(state, 0, state->sp()+1);
								else
									jit->emitCopy(state, scopeBase, state->sp()+1);
							}
							else // found a single matching traits
								jit->emit(state, OP_finddef, (uintptr)&multiname, state->sp()+1, script->declaringTraits);
						}
						#else
						(void)opcode;
						#endif
						state->push(script->declaringTraits, true);

						// OPTIMIZEME - more early binding for interpreter on findproperty!
						XLAT_ONLY(if (translator) translator->emitOp1(wordCode(opcode), imm30));

                        #ifdef AVMPLUS_VERIFYALL
                        core->enq(script);
                        core->enq(script->declaringTraits);
                        #endif

						return;
					}
#if defined AVMPLUS_WORD_CODE
					else {
						if (translator) {
							switch (opcode) {
								case OP_findproperty: 
									translator->emitOp2(WOP_findpropglobal, imm30, allocateCacheSlot(imm30));
									break;
								case OP_findpropstrict:
									translator->emitOp2(WOP_findpropglobalstrict, imm30, allocateCacheSlot(imm30));
									break;
								default:
									translator->emitOp1(wordCode(opcode), imm30);
									break;
							}
							no_translate = true;
						}
					}
#endif
				}
			}
		}

		uint32_t n=1;
		checkPropertyMultiname(n, multiname);
		JIT_ONLY( if (jit) jit->emit(state, opcode, (uintptr)&multiname, 0, OBJECT_TYPE); )
		state->pop_push(n-1, OBJECT_TYPE, true);
		XLAT_ONLY( if (translator && !no_translate) translator->emitOp1(wordCode(opcode), imm30) );
	}

#ifdef AVMPLUS_WORD_CODE
	// The cache structure is expected to be small in the normal case, so use a
	// linear list.  For some programs, notably classical JS programs, it may however
	// be larger, and we may need a more sophisticated structure.
	uint32_t Verifier::allocateCacheSlot(uint32_t imm30)
	{
		for ( int i=0 ; i < next_cache ; i++ )
			if (caches[i] == imm30)
				return i;
		if (next_cache == num_caches) {
			uint32_t* new_cache = new uint32_t[num_caches*2];
			memcpy(new_cache, caches, sizeof(uint32_t)*num_caches);
			delete [] caches;
			caches = new_cache;
			num_caches *= 2;
		}
		caches[next_cache] = imm30;
		return next_cache++;
	}
#endif // AVMPLUS_WORD_CODE

	void Verifier::emitGetProperty(Multiname &multiname, int n, uint32_t imm30)
	{
#ifndef AVMPLUS_WORD_CODE
		(void)imm30;
#endif
		Value& obj = state->peek(n); // object

		JIT_ONLY( if (jit) emitCheckNull(state->sp()-(n-1)); )

		Binding b = toplevel->getBinding(obj.traits, &multiname);
		Traits* propType = readBinding(obj.traits, b);

		if (AvmCore::isSlotBinding(b))
		{
			// early bind to slot
			MIR_ONLY( if (jit) jit->emit(state, OP_getslot, AvmCore::bindingToSlotId(b), state->sp(), propType); )
			LIR_ONLY( if (jit) jit->emitGetslot(state, AvmCore::bindingToSlotId(b), state->sp(), propType); )
#ifdef AVMPLUS_WORD_CODE
			if (translator)
			{
				Traits* t = state->value(state->sp()).traits;
				int slot = int(AvmCore::bindingToSlotId(b));
				
				AvmAssert(t->isResolved());
				
				if (!(t->pool->isBuiltin && !t->final))
					translator->emitOp1(WOP_getslot, slot+1);
				else
					translator->emitOp1(WOP_getproperty, imm30);
			}
#endif
			state->pop_push(n, propType);
			return;
		}

		XLAT_ONLY( if (translator) translator->emitOp1(WOP_getproperty, imm30) );
		
		// Do early binding to accessors.
		if (AvmCore::hasGetterBinding(b))
		{
			// Invoke the getter
			int disp_id = AvmCore::bindingToGetterId(b);
			const TraitsBindingsp objtd = obj.traits->getTraitsBindings();
			AbstractFunction *f = objtd->getMethod(disp_id);
			AvmAssert(f != NULL);
			#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
			if (jit)
			{
				emitCoerceArgs(f, 0);
				jit->emitSetContext(state, f);
				if (!obj.traits->isInterface)
					jit->emitCall(state, OP_callmethod, disp_id, 0, propType);
				else
					jit->emitCall(state, OP_callinterface, f->iid(), 0, propType);
			}
			#else
			(void)f;
			#endif
			AvmAssert(propType == f->returnTraits());
			state->pop_push(n, propType);
			return;
		}

		#ifdef DEBUG_EARLY_BINDING
		core->console << "verify getproperty " << obj.traits << " " << multiname->getName() << " from within " << info << "\n";
		#endif

		bool needsSetContext = true;
		if( !propType )
		{
			if( obj.traits == VECTORINT_TYPE  || obj.traits == VECTORUINT_TYPE ||
				obj.traits == VECTORDOUBLE_TYPE )
			{
				bool attr = multiname.isAttr();
				Traits* indexType = state->value(state->sp()).traits;

				bool maybeIntegerIndex = !attr && multiname.isRtname() && multiname.contains(core->publicNamespace);

				if( maybeIntegerIndex && (indexType == UINT_TYPE || indexType == INT_TYPE) )
				{
					needsSetContext = false;
					if(obj.traits == VECTORINT_TYPE)
						propType = INT_TYPE;
					else if(obj.traits == VECTORUINT_TYPE)
						propType = UINT_TYPE;
					else if(obj.traits == VECTORDOUBLE_TYPE)
						propType = NUMBER_TYPE;
				}
			}
		}
		// default - do getproperty at runtime
		#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
		if (jit)
		{
			if (needsSetContext)
				jit->emitSetContext(state, NULL);
			jit->emit(state, OP_getproperty, (uintptr)&multiname, 0, propType);
		}
		#endif
		state->pop_push(n, propType);
	}

	void Verifier::emitGetGlobalScope()
	{
		ScopeTypeChain* scope = info->declaringTraits->scope;
		int captured_depth = scope->size;
		if (captured_depth > 0)
		{
			// enclosing scope
			JIT_ONLY( if (jit) jit->emitGetscope(state, 0, state->sp()+1); )
			state->push(scope->getScopeTraitsAt(0), true);
		}
		else
		{
			// local scope
			if (state->scopeDepth > 0)
			{
				JIT_ONLY( if (jit) jit->emitCopy(state, scopeBase, state->sp()+1); )
				// this will copy type and all attributes too
				state->push(state->scopeValue(0));
			}
			else
			{
				#ifdef _DEBUG
				if (pool->isBuiltin)
					core->console << "getglobalscope >= depth (0) "<< state->scopeDepth << "\n";
				#endif
				verifyFailed(kGetScopeObjectBoundsError, core->toErrorString(0));
			}
		}
	}

	void Verifier::emitGetOuterScope(int scope_index)
	{
		ScopeTypeChain* scope = info->declaringTraits->scope;
		int captured_depth = scope->size;
		if (captured_depth > 0)
		{
			// enclosing scope
			JIT_ONLY( if (jit) jit->emitGetscope(state, scope_index, state->sp()+1); )
			state->push(scope->getScopeTraitsAt(scope_index), true);
		}
		else
		{
			#ifdef _DEBUG
			if (pool->isBuiltin)
				core->console << "getouterscope >= depth (" << scope_index << " >= " << state->scopeDepth << ")\n";
			#endif
			verifyFailed(kGetScopeObjectBoundsError, core->toErrorString(0));
		}
	}

	void Verifier::emitGetSlot(int slot)
	{
		Value& obj = state->peek();
		checkEarlySlotBinding(obj.traits);
		Traits* slotTraits = checkSlot(obj.traits, slot);
        #if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
        if (jit) {
            int obj = state->sp();
            emitCheckNull(obj);
            MIR_ONLY(jit->emit(state, OP_getslot, slot, obj, slotTraits);)
            LIR_ONLY(jit->emitGetslot(state, slot, obj, slotTraits);)
        }
        #endif
		state->pop_push(1, slotTraits);
	}

	void Verifier::emitSetSlot(int slot)
	{
		Value& obj = state->peek(2); // object
		// if code isn't in pool, its our generated init function which we always
		// allow early binding on
		if(pool->isCodePointer(info->body_pos))
			checkEarlySlotBinding(obj.traits);
		JIT_ONLY( Traits* slotTraits = ) checkSlot(obj.traits, slot); 
		#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
		if (jit)
		{
			emitCoerce(slotTraits, state->sp());
			emitCheckNull(state->sp()-1);
			MIR_ONLY(jit->emit(state, OP_setslot, slot, state->sp()-1, slotTraits);)
            LIR_ONLY(jit->emitSetslot(state, OP_setslot, slot, state->sp()-1);)
		}
		#else
		(void)slot;
		#endif
		state->pop(2);
	}

    // ( x1 x2 -- x2 x1 )
	void Verifier::emitSwap()
	{
		JIT_ONLY( if (jit) jit->emitSwap(state, state->sp(), state->sp()-1); )
		Value v1 = state->peek(1);
		Value v2 = state->peek(2);
		state->pop(2);
		state->push(v1);
		state->push(v2);
	}

    // ( x1 x2 -- x2 )
    void Verifier::emitNip()
    {
        JIT_ONLY( if (jit) jit->emitCopy(state, state->sp(), state->sp()-1); )
        Value v = state->stackTop();
        state->pop(2);
        state->push(v);
    }

	FrameState *Verifier::getFrameState(sintptr targetpc)
	{
		const byte *target = code_pos + targetpc;
		FrameState *targetState;
		// get state for target address or create a new one if none exists
		if (!blockStates)
		{
			blockStates = new (core->GetGC()) SortedIntMap<FrameState*>(core->GetGC(), 128);
		}
		if ( (targetState = blockStates->get((uintptr)target)) == 0 ) 
		{
			targetState = newFrameState();
			targetState->pc = target - code_pos;
			blockStates->put((uintptr)target, targetState);
			labelCount++;
		}
		return targetState;
	}
	
	void Verifier::emitToString(AbcOpcode opcode, int i)
	{
		Traits *st = STRING_TYPE;
		Value& value = state->value(i);
		Traits *in = value.traits;
		if (in != st || !value.notNull || opcode != OP_convert_s)
		{
			#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
			if (jit)
			{
				if (opcode == OP_convert_s && in && 
					(value.notNull || in->isNumeric() || in == BOOLEAN_TYPE))
				{
					jit->emitCoerce(state, i, st);
				}
				else
				{
					jit->emit(state, opcode, i, 0, st);
				}
			}
			#endif
			value.traits = st;
			value.notNull = true;
		}
	}

#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
	void Verifier::emitCheckNull(int i)
	{
		Value& value = state->value(i);
		if (!value.notNull)
		{
			jit->emitCheckNull(state, i);
			for (int j=0, n = frameSize; j < n; j++) 
			{
				// also mark all copies of value.ins as non-null
				Value &v2 = state->value(j);
				if (v2.ins == value.ins)
					v2.notNull = true;
			}
		}
	}
#endif

	void Verifier::checkCallMultiname(AbcOpcode /*opcode*/, Multiname* name) const
	{
		if (name->isAttr())
		{
			verifyFailed(kIllegalOpMultinameError, core->toErrorString(name));
		}
	}

	Traits* Verifier::emitCoerceSuper(int index)
	{
		Traits* base = info->declaringTraits->base;
		if (base != NULL)
		{
			JIT_ONLY( if (jit) emitCoerce(base, index); )
		}
		else
		{
			verifyFailed(kIllegalSuperCallError, core->toErrorString(info));
		}
		(void)index;
		return base;
	}

	void Verifier::emitCoerce(Traits* target, int index)
	{
		Value &v = state->value(index);
		#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
        if (jit) {
    		Traits* rhs = v.traits;
		    if ((!canAssign(target, rhs) || !Traits::isMachineCompatible(target, rhs)))
    			jit->emitCoerce(state, index, target);
        }
		#endif
		state->setType(index, target, v.notNull);
	}

	Traits* Verifier::peekType(Traits* requiredType, int n)
	{
		Traits* t = state->peek(n).traits;
		if (t != requiredType)
		{
			verifyFailed(kIllegalOperandTypeError, core->toErrorString(t), core->toErrorString(requiredType));
		}
		return t;
	}

	void Verifier::checkEarlySlotBinding(Traits* t)
	{
		if (!t->allowEarlyBinding())
			verifyFailed(kIllegalEarlyBindingError, core->toErrorString(t));
	}

	void Verifier::emitCoerceArgs(AbstractFunction* m, int argc, bool isctor)
	{
		if (!m->argcOk(argc))
		{
			verifyFailed(kWrongArgumentCountError, core->toErrorString(m), core->toErrorString(m->requiredParamCount()), core->toErrorString(argc));
		}

		m->resolveSignature(toplevel);
	
		#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
		// coerce parameter types
		int n=1;
		while (argc > 0) 
		{
			if (jit)
			{
				Traits* target = (argc <= m->param_count) ? m->paramTraits(argc) : NULL;
				emitCoerce(target, state->sp()-(n-1));
			}
			argc--;
			n++;
		}

		// coerce receiver type
		if (jit && !isctor)  // don't coerce if this is for a ctor, since the ctor will be on the stack instead of the new object
			emitCoerce(m->paramTraits(0), state->sp()-(n-1));
		#else
		(void)isctor;
		#endif
	}

	bool Verifier::canAssign(Traits* lhs, Traits* rhs) const
	{
		if (!Traits::isMachineCompatible(lhs,rhs))
		{
			// no machine type is compatible with any other 
			return false;
		}

		if (!lhs)
			return true;

		// type on right must be same class or subclass of type on left.
		Traits* t = rhs;
		while (t != lhs && t != NULL)
			t = t->base;
		return t != NULL;
	}

	void Verifier::checkStack(uint32_t pop, uint32_t push)
	{
		if (uint32_t(state->stackDepth) < pop)
			verifyFailed(kStackUnderflowError);
		if (state->stackDepth-pop+push > uint32_t(max_stack))
			verifyFailed(kStackOverflowError);
	}

	void Verifier::checkStackMulti(uint32_t pop, uint32_t push, Multiname* m)
	{
		if (m->isRtname()) pop++;
		if (m->isRtns()) pop++;
		checkStack(pop,push);
	}

	Value& Verifier::checkLocal(int local)
	{
		if (local < 0 || local >= local_count)
			verifyFailed(kInvalidRegisterError, core->toErrorString(local));
		return state->value(local);
	}
	
	Traits* Verifier::checkSlot(Traits *traits, int imm30)
	{
        uint32_t slot = imm30;
		if (traits)
			traits->resolveSignatures(toplevel);
		TraitsBindingsp td = traits ? traits->getTraitsBindings() : NULL;
		const uint32_t count = td ? td->slotCount : 0;
        if (!traits || slot >= count)
		{
			verifyFailed(kSlotExceedsCountError, core->toErrorString(slot+1), core->toErrorString(count), core->toErrorString(traits));
		}
		return td->getSlotTraits(slot);
	}

	Traits* Verifier::readBinding(Traits* traits, Binding b)
	{
		if (traits)
			traits->resolveSignatures(toplevel);
		switch (AvmCore::bindingKind(b))
		{
		default:
			AvmAssert(false); // internal error - illegal binding type
		case BKIND_GET:
		case BKIND_GETSET:
		{
			int m = AvmCore::bindingToGetterId(b);
			AbstractFunction *f = traits->getTraitsBindings()->getMethod(m);
			return f->returnTraits();
		}
		case BKIND_SET:
			// TODO lookup type here. get/set must have same type.
		case BKIND_NONE:
			// dont know what this is
			// fall through
		case BKIND_METHOD:
			// extracted method or dynamic data, don't know which
			return NULL;
		case BKIND_VAR:
		case BKIND_CONST:
			return traits->getTraitsBindings()->getSlotTraits(AvmCore::bindingToSlotId(b));
		}
	}

	AbstractFunction* Verifier::checkMethodInfo(uint32_t id)
	{
		if (id >= pool->methodCount)
		{
            verifyFailed(kMethodInfoExceedsCountError, core->toErrorString(id), core->toErrorString(pool->methodCount));
			return NULL;
		}
		else
		{
			return pool->methods[id];
		}
	}

	Traits* Verifier::checkClassInfo(uint32_t id)
	{
		if (id >= pool->classCount)
		{
            verifyFailed(kClassInfoExceedsCountError, core->toErrorString(id), core->toErrorString(pool->classCount));
			return NULL;
		}
		else
		{
			return pool->cinits[id]->declaringTraits;
		}
	}

	Traits* Verifier::checkTypeName(uint32_t index)
	{
		Multiname name;
		checkConstantMultiname(index, name); // CONSTANT_Multiname
		Traits *t = pool->getTraits(name, toplevel);
		if (t == NULL)
			verifyFailed(kClassNotFoundError, core->toErrorString(&name));
		else
			if( name.isParameterizedType() )
			{
				Traits* param_traits = name.getTypeParameter() ? checkTypeName(name.getTypeParameter()) : NULL ;
				t = pool->resolveParameterizedType(toplevel, t, param_traits);
			}
		return t;
	}

    AbstractFunction* Verifier::checkDispId(Traits* traits, uint32_t disp_id)
    {
		TraitsBindingsp td = traits->getTraitsBindings();
        if (disp_id > td->methodCount)
		{
            verifyFailed(kDispIdExceedsCountError, core->toErrorString(disp_id), core->toErrorString(td->methodCount), core->toErrorString(traits));
		}
		AbstractFunction* m = td->getMethod(disp_id);
		if (!m) 
		{
			verifyFailed(kDispIdUndefinedError, core->toErrorString(disp_id), core->toErrorString(traits));
		}
		return m;
    }

    void Verifier::verifyFailed(int errorID, Stringp arg1, Stringp arg2, Stringp arg3) const
    {
#ifdef FEATURE_BUFFER_GUARD
#ifdef AVMPLUS_MIR
		// Make sure the GrowthGuard is unregistered
		if (growthGuard)
		{
			growthGuard->~GrowthGuard();
		}
#endif
#endif

#ifdef AVMPLUS_VERBOSE
		if (!secondTry && !verbose)
		{
			// capture the verify trace even if verbose is false.
			Verifier v2(info, toplevel, true);
			v2.verbose = true;
			#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
			v2.verify(NULL);
			#else
			v2.verify();
			#endif
		}
#endif
		core->throwErrorV(toplevel->verifyErrorClass(), errorID, arg1, arg2, arg3);

		// This function throws, and should never return.
		AvmAssert(false);
    }

    void Verifier::checkTarget(const byte* target)
    {
		FrameState *targetState = getFrameState(target-code_pos);
		AvmAssert(targetState != 0);
		if (!targetState->initialized)
		{
			//if (verbose)
			//	core->console << "merge first target=" << targetState->pc << "\n";
            // first time visiting target block
			targetState->init(state);
			targetState->initialized = true;

			// if this label is a loop header then clear the notNull flag for
			// any state entry that might become null in the loop body.  this
			// prevents us from needing to re-verify the loop, at a cost of a
			// few more null pointer checks. 
			if (targetState->targetOfBackwardsBranch)
			{
				// null check on all locals
				for (int i=0, n=local_count; i < n; i++)
					targetState->value(i).notNull = false;

				// and all stack entries
				for (int i=stackBase, n=i+state->stackDepth; i < n; i++)
					targetState->value(i).notNull = false;

				// we don't have to clear notNull on scope stack entries because we
				// check for null in op_pushscope/pushwith
			}
			
			//if (verbose)
			//	showState(targetState, targetState->pc+code_pos, false);
        }
        else
        {
			/*if (verbose)
			{
				core->console << "merge current=" << state->pc << "\n";
				showState(state, code_pos+state->pc, false);
				core->console << "merge target=" << targetState->pc << "\n";
				showState(targetState, code_pos+targetState->pc, false);
			}*/

			// check matching stack depth
            if (state->stackDepth != targetState->stackDepth) 
			{
				verifyFailed(kStackDepthUnbalancedError, core->toErrorString((int)state->stackDepth), core->toErrorString((int)targetState->stackDepth));
			}

			// check matching scope chain depth
            if (state->scopeDepth != targetState->scopeDepth)
			{
				verifyFailed(kScopeDepthUnbalancedError, core->toErrorString(state->scopeDepth), core->toErrorString(targetState->scopeDepth));
			}

			// merge types of locals, scopes, and operands
			// ISSUE merge should preserve common interfaces even when
			// common supertype does not:
			//    class A implements I {}
			//    class B implements I {}
			//    var i:I = b ? new A : new B

			const int scopeTop  = scopeBase + targetState->scopeDepth;
			const int stackTop  = stackBase + targetState->stackDepth;
			Value* targetValues = &targetState->value(0);
			Value* curValues = &state->value(0);
			for (int i=0, n=stackTop; i < n; i++)
			{
				if (i >= scopeTop && i < stackBase) 
				{
					// invalid location, ignore it.
					continue;
				}

				Value& curValue = curValues[i];
				Value& targetValue = targetValues[i];
				if (curValue.killed || targetValue.killed) 
				{
					// this reg has been killed in one or both states;
					// ignore it.
					continue;
				}

				Traits* t1 = targetValue.traits;
				Traits* t2 = curValue.traits;
				bool isWith = curValue.isWith;

				if (isWith != targetValue.isWith) 
				{
					// failure: pushwith on one edge, pushscope on other edge, cannot merge.
					verifyFailed(kCannotMergeTypesError, core->toErrorString(t1), core->toErrorString(t2));
				}

				Traits* t3 = (t1 == t2) ? t1 : findCommonBase(t1, t2);
				
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				if (jit)
					jit->merge(i, curValue, targetValue);
				#endif // AVMPLUS_MIR || FEATURE_NANOJIT

				bool notNull = targetValue.notNull && curValue.notNull;
				if (targetState->pc < state->pc && 
					(t3 != t1 || t1 && !t1->isNumeric() && notNull != targetValue.notNull))
				{
					// failure: merge on back-edge
					verifyFailed(kCannotMergeTypesError, core->toErrorString(t1), core->toErrorString(t3));
				}

				// if we're targeting a label we can't propagate notNull since we don't yet know 
				// the state of all the other possible branches.  Another possible fix would be to 
				// enforce a null check at each branch to the target.
				if (targetState->targetOfBackwardsBranch)
					notNull = false;

				targetState->setType(i, t3, notNull, isWith);
			}

			/*if (verbose) {
				core->console << "after merge\n";
				showState(targetState, code_pos+targetState->pc, false);
			}*/
        }
    }

	/**
	 * find common base class of these two types
	 */
	Traits* Verifier::findCommonBase(Traits* t1, Traits* t2)
	{
		AvmAssert(t1 != t2);

		if (t1 == NULL) {
			// assume t1 is always non-null
			Traits *temp = t1;
			t1 = t2;
			t2 = temp;
		}

		if (!Traits::isMachineCompatible(t1,t2))
		{
			// these two types are incompatible machine types that require
			// coersions before the join node.
			verifyFailed(kCannotMergeTypesError, core->toErrorString(t1), core->toErrorString(t2));
		}

		if (t1 == NULL_TYPE && t2 && !t2->isMachineType())
		{
			// okay to merge null with pointer type
			return t2;
		}
		if (t2 == NULL_TYPE && t1 && !t1->isMachineType())
		{
			// okay to merge null with pointer type
			return t1;
		}

		// all commonBase flags start out false.  set the cb bits on 
		// t1 and its ancestors.
		Traits* t = t1;
		do t->commonBase = true;
		while ((t = t->base) != NULL);

		// now search t2 and its ancestors looking for the first cb=true
		t = t2;
		while (t != NULL && !t->commonBase) 
			t = t->base;

		Traits* common = t;

		// finally reset the cb bits to false for next time
		t = t1;
		do t->commonBase = false;
		while ((t = t->base) != NULL);

		// found common base, possibly *
		if (!Traits::isMachineCompatible(t1,common) || !Traits::isMachineCompatible(t2,common))
		{
			// these two types are incompatible types that require
			// coersions before the join node.
			verifyFailed(kCannotMergeTypesError, core->toErrorString(t1), core->toErrorString(t2));
		}
		return common;
	}

    Atom Verifier::checkCpoolOperand(uint32_t index, int requiredAtomType)
    {
		switch( requiredAtomType )
		{
		case kStringType:
			if( !index || index >= pool->constantStringCount )
			{
				verifyFailed(kCpoolIndexRangeError, core->toErrorString(index), core->toErrorString(pool->constantStringCount));
				return undefinedAtom;
			}
			return pool->cpool_string[index]->atom();

		case kObjectType:
			if( !index || index >= pool->constantMnCount )
			{
				verifyFailed(kCpoolIndexRangeError, core->toErrorString(index), core->toErrorString(pool->constantMnCount));
				return undefinedAtom;
			}
			return pool->cpool_mn[index];

		default:
			verifyFailed(kCpoolEntryWrongTypeError, core->toErrorString(index));
			return undefinedAtom;
		}
    }

	void Verifier::checkConstantMultiname(uint32_t index, Multiname& m)
	{
		checkCpoolOperand(index, kObjectType);
		pool->parseMultiname(m, index);
	}

	Binding Verifier::findMathFunction(TraitsBindingsp math, const Multiname& multiname, Binding b, int argc)
	{
		Stringp newname = core->internString(core->concatStrings(core->constantString("_"), multiname.getName()));
		Binding newb = math->findBinding(newname);
		if (AvmCore::isMethodBinding(newb))
		{
			int disp_id = AvmCore::bindingToMethodId(newb);
			AbstractFunction* newf = math->getMethod(disp_id);
			if (argc == newf->param_count)
			{
				for (int i=state->stackDepth-argc, n=state->stackDepth; i < n; i++)
				{
					Traits* t = state->stackValue(i).traits;
					if (!t || !t->isNumeric())
						return b;
				}
				b = newb;
			}
		}
		return b;
	}

	Binding Verifier::findStringFunction(TraitsBindingsp str, const Multiname& multiname, Binding b, int argc)
	{
		Stringp newname = core->internString(core->concatStrings(core->constantString("_"), multiname.getName()));
		Binding newb = str->findBinding(newname);
		if (AvmCore::isMethodBinding(newb))
		{
			int disp_id = AvmCore::bindingToMethodId(newb);
			AbstractFunction* newf = str->getMethod(disp_id);
			// We have all required parameters but not more than required.
			if ((argc >= (newf->param_count - newf->optional_count)) && (argc <= newf->param_count))
			{
				for (int i=state->stackDepth-argc, k = 1, n=state->stackDepth; i < n; i++, k++)
				{
					Traits* t = state->stackValue(i).traits;
					if (t != newf->paramTraits(k))
						return b;
				}
				b = newb;
			}
		}
		return b;
	}

	void Verifier::parseExceptionHandlers()
	{
		const byte* pos = exceptions_pos;
		int exception_count = toplevel->readU30(pos);

		if (exception_count != 0) 
		{
			size_t extra = sizeof(ExceptionHandler)*(exception_count-1);
			ExceptionHandlerTable* table = new (core->GetGC(), extra) ExceptionHandlerTable(exception_count);
			ExceptionHandler *handler = table->exceptions;
			for (int i=0; i<exception_count; i++) 
			{
				handler->from = toplevel->readU30(pos);
				handler->to = toplevel->readU30(pos);
				handler->target = toplevel->readU30(pos);

				const uint8_t* const scopePosInPool = pos;

				int type_index = toplevel->readU30(pos);
				Traits* t = type_index ? checkTypeName(type_index) : NULL;

				Multiname qn;
				int name_index = (pool->version != (46<<16|15)) ? toplevel->readU30(pos) : 0;
				if (name_index != 0)
				{
					pool->parseMultiname(qn, name_index);
				}

				#ifdef AVMPLUS_VERBOSE
				if (verbose)
				{
					core->console << "            exception["<<i<<"] from="<< handler->from
						<< " to=" << handler->to
						<< " target=" << (uint64_t)handler->target 
						<< " type=" << t
						<< " name=";
					if (name_index != 0)
					    core->console << qn;
					else
						core->console << "(none)";
					core->console << "\n";
				}
				#endif

				if (handler->from < 0 ||
					handler->to < handler->from ||
					handler->target < handler->to || 
					handler->target > code_length)
				{
					// illegal range in handler record
					verifyFailed(kIllegalExceptionHandlerError);
				}

				// handler->traits = t
				WB(core->GetGC(), table, &handler->traits, t);

				Traits* scopeTraits;
				
				if (name_index == 0)
				{
					scopeTraits = OBJECT_TYPE;
				}
				else
				{
					scopeTraits = Traits::newCatchTraits(toplevel, pool, scopePosInPool, qn.getName(), qn.getNamespace());
				}
				
				// handler->scopeTraits = scopeTraits
				WB(core->GetGC(), table, &handler->scopeTraits, scopeTraits);

				
				getFrameState(handler->target)->targetOfBackwardsBranch = true;

				handler++;
			}

			//info->exceptions = table;
			WB(core->GetGC(), info, &info->exceptions, table);
		}
		else
		{
			info->exceptions = NULL;
		}
	}

#ifdef AVMPLUS_VERBOSE
	/**
     * display contents of current stack frame only.
     */
    void Verifier::showState(FrameState *state, const byte* pc, bool unreachable)
    {
		// stack
		core->console << "                        stack:";
		for (int i=stackBase, n=state->sp(); i <= n; i++) {
			core->console << " ";
			printValue(state->value(i));
		}
		core->console << '\n';

        // scope chain
		core->console << "                        scope: ";
		if (info->declaringTraits->scope && info->declaringTraits->scope->size > 0)
		{
			core->console << "[";
			for (int i=0, n=info->declaringTraits->scope->size; i < n; i++)
			{
				Value v;
				v.traits = info->declaringTraits->scope->getScopeTraitsAt(i);
				v.isWith = info->declaringTraits->scope->getScopeIsWithAt(i);
				v.killed = false;
				v.notNull = true;
				#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
				v.ins = 0;
				#endif
				printValue(v);
				if (i+1 < n)
					core->console << " ";
			}
			core->console << "] ";
		}
		for (int i=scopeBase, n=stackBase; i < n; i++) 
		{
            if (i-scopeBase < state->scopeDepth)
                printValue(state->value(i));
            else
                core->console << "~";
			core->console << " ";
        }
		core->console << '\n';

        // locals
		core->console << "                         locals: ";
		for (int i=0, n=scopeBase; i < n; i++) {
            printValue(state->value(i));
			core->console << " ";
        }
		core->console << '\n';

		// opcode
		if (unreachable)
			core->console << "- ";
		else
			core->console << "  ";
		core->console << (uint64_t)state->pc << ':';
        core->formatOpcode(core->console, pc, (AbcOpcode)*pc, (int)(state->pc), pool);
		core->console << '\n';
    }

	void Verifier::printValue(Value& v)
	{
		Traits* t = v.traits;
		if (!t)
		{
			core->console << "*";
		}
		else
		{
			core->console << t->format(core);
			if (!t->isNumeric() && !v.notNull && t != BOOLEAN_TYPE && t != NULL_TYPE)
				core->console << "?";
		}
#if defined AVMPLUS_MIR || defined FEATURE_NANOJIT
		if (jit && v.ins)
			jit->formatOperand(core->console, v.ins);
#endif
	}

#endif /* AVMPLUS_VERBOSE */

	FrameState* Verifier::newFrameState()
	{
		size_t extra = (frameSize-1)*sizeof(Value);
		return new (core->GetGC(), extra) FrameState(this);
	}
}
