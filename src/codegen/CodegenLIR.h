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
 * Portions created by the Initial Developer are Copyright (C) 2004-2008
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

#ifndef __avmplus_CodegenLIR__
#define __avmplus_CodegenLIR__

using namespace MMgc;
#include "../nanojit/nanojit.h"

#ifdef DEBUGGER
#define DEBUGGER_ONLY(...) __VA_ARGS__
#else
#define DEBUGGER_ONLY(...)
#endif

namespace avmplus
{
	using namespace nanojit;

   #ifdef VTUNE
   class LineNumberRecord : public MMgc::GCObject
   {
       public:
           LineNumberRecord(Stringp fn, uint32_t ln)
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

	class MethodInfo;

	class CodegenLabel {
    public:
		LIns *bb;
		int preds;
        CodegenLabel() : bb(0), preds(0)
        {}
	};

    class PageMgr : public GCFinalizedObject {
    public:
        DWB(Fragmento*) frago;
        PageMgr();
        virtual ~PageMgr();
    };

    class Patch {
    public:
        LIns *br;
        CodegenLabel *label;
        Patch() : br(0), label(0) {}
        Patch(int) : br(0), label(0) {}
        Patch(LIns *br, CodegenLabel &l) : br(br), label(&l) {}
    };

    class CopyPropagation;

	class CodegenLIR {
	public:
		bool overflow;
		const byte *abcStart;
		const byte *abcEnd;

       #ifdef VTUNE
       bool hasDebugInfo;
       List<JITCodeInfo*,LIST_GCObjects> jitInfoList;
       List<LineNumberRecord*,LIST_GCObjects> jitPendingRecords;
       void jitPushInfo();
       JITCodeInfo* jitCurrentInfo();

       LineNumberRecord* jitAddRecord(uintptr_t pos, uint32_t filename, uint32_t line, bool pending=false);
       void jitFilenameUpdate(uint32_t filename);
       void jitLineNumUpdate(uint32_t line);
       void jitCodePosUpdate(uint32_t pos);
       #endif /* VTUNE */

	private:
        GC *gc;
        AvmCore *core;
        MethodInfo *info;
        PoolObject *pool;
        Fragment *frag;
		LirWriter *lirout;
		FrameState *state;
        LIns *vars, *varTraits, *varPtrs;
        LIns *env_param, *argc_param, *ap_param;
        LIns *_save_eip, *_ef;
        LIns *dxns, *dxnsAddrSave;
        LIns *csn;
        LIns *undefConst;
		LIns *coreAddr;
        bool interruptable;
        CodegenLabel interrupt_label, npe_label;
        intptr_t lastPcSave;
        List<Patch, LIST_NonGCObjects> patches;
        LIns *exBranch;
        LIns *setjmpResult;
        CopyPropagation *copier;
        int framesize;
		verbose_only(VerboseWriter *vbWriter;)

        LIns *InsAlloc(int32_t);
        void storeIns(LIns *val, int32_t disp, LIns *base, bool force32);
        LIns *InsConst(const void *p) { return InsConst((int32_t)p); }
        LIns *atomToNativeRep(int loc, LIns *i);
        LIns *atomToNativeRep(Traits *, LIns *i);
        LIns *ptrToNativeRep(Traits*, LIns*);
        LIns *loadAtomRep(int i);
        LIns *callIns(const CallInfo *, uint32_t argc, ...);
        LIns *leaIns(int32_t d, LIns *base);
        LIns *localGet(int i);
        LIns *localGetq(int i);
        LIns *localCopy(int i); // sniff's type
        LIns *branchIns(LOpcode op, LIns *cond);
        LIns *branchIns(LOpcode op, LIns *cond, uintptr_t targetpc);
        LIns *retIns(LIns *val);
        LIns *loadToplevel();
        LIns *initMultiname(Multiname* multiname, int& csp, bool isDelete =false);
        LIns *storeAtomArgs(int count, int index);
        LIns *storeAtomArgs(LIns *obj, int count, int index);
        LIns *promoteNumberIns(Traits *t, int i);
        LIns *loadVTable(int i);
    	LIns *cmpEq(const CallInfo *fid, int lhsi, int rhsi);
    	LIns *cmpLt(int lhsi, int rhsi);
    	LIns *cmpLe(int lhsi, int rhsi);
        LIns *cmpOptimization(int lhsi, int rhsi, LOpcode icmp, LOpcode ucmp, LOpcode fcmp);
        debug_only( bool isPointer(int i); )
        void label(CodegenLabel &label, LIns *bb);
        void emitPrep();
        void emitSampleCheck();
        bool verbose();
        void patchLater(LIns *br, CodegenLabel &);
        void patchLater(LIns *br, intptr_t pc);
        bool isCodeContextChanged() const;
        void mirLabel(CodegenLabel &l, LIns *target);
        void deadvars();
        void deadvars_analyze(SortedMap<LIns*, BitSet*, LIST_GCObjects> &labels);
        void deadvars_kill(SortedMap<LIns*, BitSet*, LIST_GCObjects> &labels);

        LIns *loadIns(LOpcode op, int32_t disp, LIns *base) {
            return lirout->insLoad(op, base, disp);
        }
        LIns *Ins(LOpcode op) {
            return lirout->ins0(op);
        }
        LIns *Ins(LOpcode op, LIns *a) {
            return lirout->ins1(op, a);
        }
        void storeIns(LIns *val, int32_t disp, LIns *base) {
            lirout->store(val, base, disp);
        }
        LIns *i2dIns(LIns* v) {
            return lirout->ins1(LIR_i2f, v);
        }
        LIns *u2dIns(LIns* v) {
            return lirout->ins1(LIR_u2f, v);
        }
        LIns *binaryIns(LOpcode op, LIns *a, LIns *b) {
            return lirout->ins2(op,a,b); 
        }
        LIns *InsConst(int32_t c) {
            return lirout->insImm(c);
        }

		bool outOMem();
		
	public:
		CodegenLIR(MethodInfo* info);
        ~CodegenLIR();
		void clearMIRBuffers();
		void emitMD();
	    void formatOperand(PrintWriter& buffer, LIns* oprnd);
		void epilogue(FrameState* state);
		bool prologue(FrameState* state);
		void emitCall(FrameState* state, AbcOpcode opcode, intptr_t method_id, int argc, Traits* result);
		void emit(FrameState* state, AbcOpcode opcode, uintptr op1=0, uintptr op2=0, Traits* result=NULL);
		void emitIf(FrameState* state, AbcOpcode opcode, intptr_t target, int lhs, int rhs);
		void emitSwap(FrameState* state, int i, int j);
		void emitCopy(FrameState* state, int src, int dest);
		void emitGetscope(FrameState* state, int scope, int dest);
		void emitKill(FrameState* state, int i);
		void emitBlockStart(FrameState* state);
		void emitBlockEnd(FrameState* state);
		void emitIntConst(FrameState* state, int index, uintptr c);
		void emitDoubleConst(FrameState* state, int index, double* pd);
		void emitCoerce(FrameState* state, int index, Traits* type);
		void emitCheckNull(FrameState* state, int index);
		void emitSetContext(FrameState* state, AbstractFunction* f);
		void emitSetDxns(FrameState* state);
        void emitGetslot(FrameState*, int slot, int ptr_index, Traits *result);
        void emitSetslot(FrameState*, AbcOpcode opcode, int slot, int ptr_index);
		void merge(int i, const Value& current, Value& target);
		void localSet(int i, LIns* o);
		void opcodeVerified(AbcOpcode opcode, FrameState* state);
	};

	class CodegenIMT
	{
		PoolObject *pool;
		LIns *ap_param, *argc_param;
		void emitCall(LirWriter *lirout, LIns *vtable, ImtBuilder::ImtEntry *e);
	public:
		bool overflow;
		CodegenIMT(PoolObject *pool);
		~CodegenIMT();
		void clearMIRBuffers();
		void* emitImtThunk(ImtBuilder::ImtEntry *e);
	};
}

#endif /* __avmplus_CodegenLIR__ */
