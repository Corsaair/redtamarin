/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "nanojit.h"

namespace nanojit
{
    using namespace avmplus;
    #ifdef FEATURE_NANOJIT
        
    const uint8_t repKinds[] = {
#define OP___(op, repKind, retType, isCse) \
        LRK_##repKind,
#include "LIRopcode.tbl"
#undef OP___
        0
    };

    const LTy retTypes[] = {
#define OP___(op, repKind, retType, isCse) \
        LTy_##retType,
#include "LIRopcode.tbl"
#undef OP___
        LTy_V
    };

    const uint8_t insSizes[] = {
#define OP___(op, repKind, retType, isCse) \
        sizeof(LIns##repKind),
#include "LIRopcode.tbl"
#undef OP___
        0
    };

    const int8_t isCses[] = {
#define OP___(op, repKind, retType, isCse) \
        isCse,
#include "LIRopcode.tbl"
#undef OP___
        0
    };

    // LIR verbose specific
    #ifdef NJ_VERBOSE

    const char* lirNames[] = {
#define OP___(op, repKind, retType, isCse) \
        #op,
#include "LIRopcode.tbl"
#undef OP___
        NULL
    };

    #endif /* NANOJIT_VERBOSE */

    template <class FILTER> uint32_t CallInfo::countArgs() const {
        uint32_t argc = 0;
        uint32_t argt = _typesig;
        argt >>= TYPESIG_FIELDSZB;      // remove retType
        while (argt) {
            ArgType a = ArgType(argt & TYPESIG_FIELDMASK);
            if (FILTER::doCount(a))
                argc++;
            argt >>= TYPESIG_FIELDSZB;
        }
        return argc;
    }

    struct AllArgs    { static bool doCount(ArgType)   { return true; } };
    struct IntArgs    { static bool doCount(ArgType a) { return a == ARGTYPE_I || a == ARGTYPE_UI; } };
    struct FloatArgs  { static bool doCount(ArgType a) { return a == ARGTYPE_F; } };
    struct Float4Args { static bool doCount(ArgType a) { return a == ARGTYPE_F4; } };

    uint32_t CallInfo::count_args() const {
        return countArgs<AllArgs>();
    }

    uint32_t CallInfo::count_int_args() const {
        return countArgs<IntArgs>();
    }

    uint32_t CallInfo::count_float_args() const {
        return countArgs<FloatArgs>();
    }
    
    uint32_t CallInfo::count_float4_args() const {
        return countArgs<Float4Args>();
    }

    uint32_t CallInfo::getArgTypes(ArgType* argTypes) const
    {
        uint32_t argc = 0;
        uint32_t argt = _typesig;
        argt >>= TYPESIG_FIELDSZB;      // remove retType
        while (argt) {
            ArgType a = ArgType(argt & TYPESIG_FIELDMASK);
            argTypes[argc] = a;
            argc++;
            argt >>= TYPESIG_FIELDSZB;
        }
        return argc;
    }

    // implementation
#ifdef NJ_VERBOSE
    void ReverseLister::finish()
    {
        _logc->printf("\n");
        _logc->printf("=== BEGIN %s ===\n", _title);
        int j = 0;
        for (Seq<char*>* p = _strs.get(); p != NULL; p = p->tail)
            _logc->printf("  %02d: %s\n", j++, p->head);
        _logc->printf("=== END %s ===\n", _title);
        _logc->printf("\n");
    }

    LIns* ReverseLister::read()
    {
        // This check is necessary to avoid printing the LIR_start multiple
        // times due to lookahead in Assembler::gen().
        if (_prevIns && _prevIns->isop(LIR_start))
            return _prevIns;
        LIns* ins = in->read();
        InsBuf b;
        const char* str = _printer->formatIns(&b, ins);
        char* cpy = new (_alloc) char[strlen(str)+1];
        VMPI_strcpy(cpy, str);
        _strs.insert(cpy);
        _prevIns = ins;
        return ins;
    }


    // build a control flow graph that can be used for display
    CfgLister::CfgLister(LirFilter* in, Allocator& alloc, CfgMode mode)
        : LirFilter(in), _alloc(alloc), _alt(alloc), _edges(alloc), _vertices(alloc), _ids(alloc), _mode(mode)
    {
        _count = 1;  // real programmers start with 1
        _prior = 0;
    }

    LIns* CfgLister::read()
    {
        bool priorAsVertex = false; // true, implies that the last processed instruction is a vertex

        LIns *ins = in->read();
        _ids.put(ins, _count++);

        LOpcode op = ins->opcode();
        LIns* target;
        switch (op) {
        case LIR_j:
        case LIR_jt:
        case LIR_jf:
        case LIR_addjovi:
        case LIR_subjovi:
        case LIR_muljovi:
        CASE64(LIR_addjovq:)
        CASE64(LIR_subjovq:)
            target = ins->getTarget();
            addEdge(ins, target);
            _vertices.put(target, true);
            priorAsVertex = (_mode == CFG_BB);
            break;

        case LIR_jtbl: {
            uint32_t tableSize = ins->getTableSize();
            NanoAssert(tableSize > 0);
            for (uint32_t i = 0; i < tableSize; i++) {
                target = ins->getTarget(i);
                addEdge(ins, target);
                _vertices.put(target, true);
            }
            priorAsVertex = (_mode == CFG_BB);
            break;
        }
        default:
            ;
        }

        // each instruction is a vertex in mode CFG_INS (except imm's which are ignored)
        priorAsVertex = ( _prior && _mode == CFG_INS && !_prior->isImmAny() ) ? true : priorAsVertex;

        if (_prior && priorAsVertex)
            _vertices.put(_prior,true);

        _prior = ins;
        return ins;
    }

    void CfgLister::addEdge(LIns* from, LIns* to)
    {
        InsList* list = _edges.get(from);
        if (!list) {
            list = new (_alloc) InsList(_alloc);
            _edges.put(from,list);
        }
        NanoAssert( from && to && (from != to) ); // valid instructions
        NanoAssert( _ids.containsKey(to) || to->isop(LIR_label) ); // we should have seen the instruction already or its a backwards jump to label
        list->add(to);

        // identify both sides of edge to later allow them to be re-mapped to other instructions
        _alt.put(from,from);
        _alt.put(to,to);
    }

    uint32_t CfgLister::node2id(LIns* i)
    {
        NanoAssert( _ids.containsKey(i) );
        uint32_t id = _ids.get(i);
        return _count - id;
    }

    const char* CfgLister::nodeName(LIns* i, InsBuf& b, LInsPrinter* printer)
    {
        // short names used in block per instruction mode
        const char* str = ( _mode == CFG_INS ) ? printer->lirNameMap->lookupName(i) : 0;
        str = !str ? printer->formatIns(&b, i) : str;
        return str;
    }

    const char* CfgLister::nodeShape(LIns* i, InsSet* pseudos)
    {
        const char* shape = "roundrectangle";
        if (i->isGuard())
            shape = "hexagon";
        else if ( pseudos->containsKey(i) )
            shape = "ellipse";
        else if ( edgeCountOf(i) > 1 )
            shape = "diamond";
        return shape;
    }

    uint32_t CfgLister::edgeCountOf(LIns* i)
    {
        uint32_t a = 0;
        Seq<LIns*>* l = _edges.get(i) ? _edges.get(i)->get() : 0;
        for(; l; l=l->tail)
            a++;
        return a;
    }

    void CfgLister::printGmlCfg(FILE* f, LInsPrinter* printer, InsSet* makeProxyNodesFor)
    {
        fprintf(f, "graph [ directed 1 hierarchic 1\n");

        // now on the 2nd pass, walk each instruction and add
        // it to a list until we reach the top of the block,
        // at which point we print out the node contents.
        // We also track any incoming edges into any instruction
        // of this node and map them to the top instruction of the node,
        // so that our edges get displayed correctly.
        InsList n(_alloc);          // running list of instruction for the block
        InsSet incoming(_alloc);    // running list of incoming edges into the block
        bool last = true;           // true, when we're processing the last instruction of a block
        LIns* priorBlock = 0;       // prior block that was just processed.

        LirReader rdr(finalIns());
        LIns* ins = rdr.read();
        for (; !ins->isop(LIR_start); ins = rdr.read())
        {
            // if last instruction of the block is not terminal then add a fall-thru edge
            if (priorBlock && last)
            {
                last = false;
                LOpcode op = ins->opcode();
                if ( !ins->isUnConditionalBranch() && !isRetOpcode(op))
                    addEdge(ins, priorBlock); // fall-thru
            }

            // process new block?
            if ( _vertices.containsKey(ins) )
            {
                // re-map all incoming edges to any instruction in the block, to the blocks' first instruction
                InsSet::Iter inc(incoming);
                while(inc.next())
                    _alt.put(inc.key(), ins);

                n.insert(ins);
                printNode(f, &n, printer, makeProxyNodesFor);

                // ready to process the next block
                n.clear();
                incoming.clear();
                priorBlock = ins;
                last = true;
            }
            else
            {
                // add the instruction to our running list and note any incoming edges to the instruction
                bool ignore = ins->isImmAny();
                if (!ignore)
                    n.insert(ins);
                if ( _alt.containsKey(ins) )
                    incoming.put(ins,true);
            }
        }

        // after once against re-mapping all edges, print the final node
        InsSet::Iter inc(incoming);
        while(inc.next())
            _alt.put(inc.key(), ins);

        n.insert(ins);
        printNode(f, &n, printer, makeProxyNodesFor);

        // now write out the edge list
        printEdges(f, printer, makeProxyNodesFor);
        fprintf(f, "]\n");
    }

    // prints a node that consists of a sequence of instructions, the first of which is used
    // to populate the node attributes, such as shape.
    void CfgLister::printNode(FILE* f, InsList* nodeIns, LInsPrinter* printer, InsSet* pseudo)
    {
        // first instruction in the list is the 'node ins'
        Seq<LIns*>* list = nodeIns->get();
        LIns* ins = list->head;

        InsBuf str;
        uint32_t id = node2id(ins);
        const char* text = nodeName(ins, str, printer);
        const char* shape = nodeShape(ins, pseudo);
        gmlNodePrefix(f, id, shape);
        gmlNodeTextLine(f, text, 0);

        for (list=list->tail; list; list=list->tail)
        {
            LIns* i = list->head;
            text = nodeName(i, str, printer);
            gmlNodeTextLine(f, text, 1);
        }

        gmlNodeSuffix(f);
    }

    void CfgLister::printEdges(FILE* f, LInsPrinter* printer, InsSet* makeProxyNodesFor)
    {
        uint32_t pseudoId = (uint32_t)~0; // ids for proxy nodes
        LIns*  src = NULL;
        InsBuf str;
        HashMap<LIns*, InsList*>::Iter ite(_edges);
        while(ite.next())
        {
            LIns* origSrc = ite.key();
            src = _alt.containsKey(origSrc) ? _alt.get(origSrc) : src;
            uint32_t sid = node2id(src);
            Seq<LIns*>* l = ite.value()->get();
            while (l)
            {
                LIns* origDst = l->head;
                LIns* dst = _alt.get(origDst); // destination mapping
                uint32_t did = node2id(dst);

                bool proxyNode = makeProxyNodesFor->containsKey(origDst);
                if (_mode != CFG_INS && proxyNode)
                {
                    // in most modes, edges to proxies are ignored.
                    l = l->tail;
                    continue;
                }

                // do we want to add a pseudo node for destination; removes clutter from the graph
                if (proxyNode)
                {
                    did = --pseudoId;
                    gmlNode(f, did, "ellipse", nodeName(dst, str, printer));
                    NanoAssert(did > _count);  // graph is too large to render correctly
                }

                const char* str_dashed = "dashed";
                const char* str_solid  = "solid";
                const char* str_red = "#E00000";
                const char* str_gray = "#AAAAAA";

                const char* text = 0;
                const char* style = str_dashed;
                const char* fill = str_gray;
                const char* width = 0;

                if ( origSrc->isConditionalBranch() )
                {
                    bool explicitEdge = origSrc->getTarget() == origDst;
                    if (explicitEdge)
                    {
                        // this is the non fall-thru edge
                        style = str_solid;
                        fill = 0; //default fill
                        text = origSrc->isop(LIR_jf) ? "0" : "1";
                    }
                    else
                    {
                        // not taken edge
                        text = origSrc->isop(LIR_jf) ? "1" : "0";
                    }
                }
                if (did < sid)
                {
                    // 'backwards' movements are red and large by default
                    style = str_solid;
                    fill = str_red;
                    width = "2";
                }
                gmlEdge(f, sid, did, style, fill, width, text);
                l = l->tail;
            }
        }
    }

    void CfgLister::gmlNodePrefix(FILE* f, uint32_t id, const char* shape)
    {
        fprintf(f, "  node [\n");
        fprintf(f, "    id %d\n", id);
        fprintf(f, "    graphics [\n");
        fprintf(f, "      type \"%s\"\n", shape);
        fprintf(f, "    ]\n");
        fprintf(f, "    LabelGraphics [\n");
        fprintf(f, "      alignment \"left\"\n");
        fprintf(f, "      fontName  \"Consolas\"\n");
        fprintf(f, "      anchor    \"tl\"\n"); // Top Left
        fprintf(f, "      text      \"");
    }

    void CfgLister::gmlNodeTextLine(FILE* f, const char* text, int32_t tabCount)
    {
        while(tabCount-->0)
           fprintf(f, "\t");
        fprintf(f, "%s\n", text);
    }

    void CfgLister::gmlNodeSuffix(FILE* f)
    {
        fprintf(f, "      \"\n");
        fprintf(f, "    ]\n");
        fprintf(f, "  ]\n");
    }

    void CfgLister::gmlNode(FILE* f, uint32_t id, const char* shape, const char* title)
    {
        fprintf(f, "  node [\n");
        fprintf(f, "    id %d\n", id);
        fprintf(f, "    graphics [\n");
        fprintf(f, "      type \"%s\"\n", shape);
        fprintf(f, "    ]\n");
        fprintf(f, "    LabelGraphics [\n");
        fprintf(f, "      text      \"%s\"\n", title);
        fprintf(f, "      alignment \"left\"\n");
        fprintf(f, "      fontName  \"Consolas\"\n");
        fprintf(f, "      anchor    \"tl\"\n"); // Top Left
        fprintf(f, "    ]\n");
        fprintf(f, "  ]\n");
    }

    void CfgLister::gmlEdge(FILE* f, uint32_t srcId, uint32_t dstId, const char* style, const char* fill, const char* width, const char* text)
    {
        fprintf(f, "  edge [\n");
        fprintf(f, "    source %d\n", srcId);
        fprintf(f, "    target %d\n", dstId);
        fprintf(f, "    graphics [\n");
        fprintf(f, "      arrow \"last\"\n");
        if (style) fprintf(f, "      style \"%s\"\n", style);
        if (fill)  fprintf(f, "      fill \"%s\"\n", fill);
        if (width) fprintf(f, "      width %s\n", width);
        fprintf(f, "    ]\n");
        fprintf(f, "    LabelGraphics [\n");
        if (text) fprintf(f, "      text      \"%s\"\n", text);
        fprintf(f, "      model     \"three_center\"\n");
        fprintf(f, "      fontStyle \"bold\"\n");
        fprintf(f, "    ]\n");
        fprintf(f, "  ]\n");
    }

#endif

    // LCompressedBuffer
    LirBuffer::LirBuffer(Allocator& alloc) :
#ifdef NJ_VERBOSE
          printer(NULL),
#endif
          abi(ABI_FASTCALL), state(NULL), param1(NULL), sp(NULL), rp(NULL),
          _allocator(alloc)
    {
        clear();
    }

    void LirBuffer::clear()
    {
        // clear the stats, etc
        _unused = 0;
        _limit = 0;
        _stats.lir = 0;
        for (int i = 0; i < NumSavedRegs; ++i)
            savedRegs[i] = NULL;
        chunkAlloc();
    }

    void LirBuffer::chunkAlloc()
    {
        _unused = (uintptr_t) _allocator.alloc(CHUNK_SZB);
        NanoAssert(_unused != 0); // Allocator.alloc() never returns null. See Allocator.h
        NanoAssert(0 == _unused % sizeof(void*)); // Require word alignment.
        _limit = _unused + CHUNK_SZB;
    }

    int32_t LirBuffer::insCount()
    {
        return _stats.lir;
    }

    // Allocate a new page, and write the first instruction to it -- a skip
    // linking to last instruction of the previous page.
    void LirBuffer::moveToNewChunk(uintptr_t addrOfLastLInsOnCurrentChunk)
    {
        chunkAlloc();
        // Link LIR stream back to prior instruction.
        // Unlike all the ins*() functions, we don't call makeRoom() here
        // because we know we have enough space, having just started a new
        // page.
        LInsSk* insSk = (LInsSk*)_unused;
        LIns*   ins   = insSk->getLIns();
        ins->initLInsSk((LIns*)addrOfLastLInsOnCurrentChunk);
        _unused += sizeof(LInsSk);
        NanoAssert(0 == _unused % sizeof(void*)); // Require word alignment.
        verbose_only(_stats.lir++);
    }

    // Make room for a single instruction.
    uintptr_t LirBuffer::makeRoom(size_t szB)
    {
        // Make sure the size is ok
        NanoAssert(0 == szB % sizeof(void*));
#ifdef NANOJIT_64BIT
        NanoAssert(sizeof(LIns) <= szB && szB <= sizeof(LInsOp4));  // LInsOp4 is the biggest one
#else
        NanoAssert(sizeof(LIns) <= szB && szB <= sizeof(LInsF4));  // LInsF4 is the biggest one
#endif
        NanoAssert(_unused < _limit);

        debug_only( bool moved = false; )

        // If the instruction won't fit on the current chunk, get a new chunk
        if (_unused + szB > _limit) {
            uintptr_t addrOfLastLInsOnChunk = _unused - sizeof(LIns);
            moveToNewChunk(addrOfLastLInsOnChunk);
            debug_only( moved = true; )
        }

        // We now know that we are on a chunk that has the requested amount of
        // room: record the starting address of the requested space and bump
        // the pointer.
        uintptr_t startOfRoom = _unused;
        _unused += szB;
        NanoAssert(0 == _unused % sizeof(void*)); // Require word alignment.
        verbose_only(_stats.lir++);             // count the instruction

        // If there's no more space on this chunk, move to a new one.
        // (This will only occur if the asked-for size filled up exactly to
        // the end of the chunk.)  This ensures that next time we enter this
        // function, _unused won't be pointing one byte past the end of
        // the chunk, which would break everything.
        if (_unused >= _limit) {
            // Check we used exactly the remaining space
            NanoAssert(_unused == _limit);
            NanoAssert(!moved);     // shouldn't need to moveToNewChunk twice
            uintptr_t addrOfLastLInsOnChunk = _unused - sizeof(LIns);
            moveToNewChunk(addrOfLastLInsOnChunk);
        }

        // Make sure it's word-aligned.
        NanoAssert(0 == startOfRoom % sizeof(void*));
        return startOfRoom;
    }

    LIns* LirBufWriter::insStore(LOpcode op, LIns* val, LIns* base, int32_t d, AccSet accSet)
    {
        if (isS16(d)) {
            LInsSt* insSt = (LInsSt*)_buf->makeRoom(sizeof(LInsSt));
            LIns*   ins   = insSt->getLIns();
            ins->initLInsSt(op, val, base, d, accSet);
            return ins;
        } else {
            // If the displacement is more than 16 bits, put it in a separate instruction.
            return insStore(op, val, ins2(LIR_addp, base, insImmWord(d)), 0, accSet);
        }
    }

    LIns* LirBufWriter::ins0(LOpcode op)
    {
        LInsOp0* insOp0 = (LInsOp0*)_buf->makeRoom(sizeof(LInsOp0));
        LIns*    ins    = insOp0->getLIns();
        ins->initLInsOp0(op);
        return ins;
    }

    LIns* LirBufWriter::ins1(LOpcode op, LIns* o1)
    {
        LInsOp1* insOp1 = (LInsOp1*)_buf->makeRoom(sizeof(LInsOp1));
        LIns*    ins    = insOp1->getLIns();
        ins->initLInsOp1(op, o1);
        return ins;
    }

    LIns* LirBufWriter::ins2(LOpcode op, LIns* o1, LIns* o2)
    {
        LInsOp2* insOp2 = (LInsOp2*)_buf->makeRoom(sizeof(LInsOp2));
        LIns*    ins    = insOp2->getLIns();
        ins->initLInsOp2(op, o1, o2);
        return ins;
    }

    LIns* LirBufWriter::ins3(LOpcode op, LIns* o1, LIns* o2, LIns* o3)
    {
        LInsOp3* insOp3 = (LInsOp3*)_buf->makeRoom(sizeof(LInsOp3));
        LIns*    ins    = insOp3->getLIns();
        ins->initLInsOp3(op, o1, o2, o3);
        return ins;
    }
    
    LIns* LirBufWriter::ins4(LOpcode op, LIns* o1, LIns* o2, LIns* o3, LIns* o4)
    {
        LInsOp4* insOp4 = (LInsOp4*)_buf->makeRoom(sizeof(LInsOp4));
        LIns*    ins    = insOp4->getLIns();
        ins->initLInsOp4(op, o1, o2, o3, o4);
        return ins;
    }
    
    LIns* LirBufWriter::insLoad(LOpcode op, LIns* base, int32_t d, AccSet accSet, LoadQual loadQual)
    {
        if (isS16(d)) {
            LInsLd* insLd = (LInsLd*)_buf->makeRoom(sizeof(LInsLd));
            LIns*   ins   = insLd->getLIns();
            ins->initLInsLd(op, base, d, accSet, loadQual);
            return ins;
        } else {
            // If the displacement is more than 16 bits, put it in a separate instruction.
            // Note that CseFilter::insLoad() also does this, so this will
            // only occur if CseFilter has been removed from the pipeline.
            return insLoad(op, ins2(LIR_addp, base, insImmWord(d)), 0, accSet, loadQual);
        }
    }

    LIns* LirBufWriter::insGuard(LOpcode op, LIns* c, GuardRecord *gr)
    {
        debug_only( if (LIR_x == op || LIR_xbarrier == op) NanoAssert(!c); )
        return ins2(op, c, (LIns*)gr);
    }

    LIns* LirBufWriter::insGuardXov(LOpcode op, LIns* a, LIns* b, GuardRecord *gr)
    {
        return ins3(op, a, b, (LIns*)gr);
    }

    LIns* LirBufWriter::insBranch(LOpcode op, LIns* condition, LIns* toLabel)
    {
        NanoAssert((op == LIR_j && !condition) ||
                   ((op == LIR_jf || op == LIR_jt || op == LIR_brsavpc) && condition));
        return ins2(op, condition, toLabel);
    }

    LIns* LirBufWriter::insBranchJov(LOpcode op, LIns* a, LIns* b, LIns* toLabel)
    {
        return ins3(op, a, b, toLabel);
    }

    LIns* LirBufWriter::insJtbl(LIns* index, uint32_t size)
    {
        LInsJtbl* insJtbl = (LInsJtbl*) _buf->makeRoom(sizeof(LInsJtbl));
        LIns**    table   = new (_buf->_allocator) LIns*[size];
        LIns*     ins     = insJtbl->getLIns();
        VMPI_memset(table, 0, size * sizeof(LIns*));
        ins->initLInsJtbl(index, size, table);
        return ins;
    }

    LIns* LirBufWriter::insAlloc(int32_t size)
    {
        size = (size+3)>>2; // # of required 32bit words
        LInsIorF* insIorF = (LInsIorF*)_buf->makeRoom(sizeof(LInsIorF));
        LIns*  ins  = insIorF->getLIns();
        ins->initLInsIorF(LIR_allocp, size);
        return ins;
    }

    LIns* LirBufWriter::insParam(int32_t arg, int32_t kind)
    {
        LInsP* insP = (LInsP*)_buf->makeRoom(sizeof(LInsP));
        LIns*  ins  = insP->getLIns();
        ins->initLInsP(arg, kind);
        if (kind) {
            NanoAssert(arg < NumSavedRegs);
            _buf->savedRegs[arg] = ins;
        }
        return ins;
    }

    LIns* LirBufWriter::insImmI(int32_t imm)
    {
        LInsIorF* insIorF = (LInsIorF*)_buf->makeRoom(sizeof(LInsIorF));
        LIns*  ins  = insIorF->getLIns();
        ins->initLInsIorF(LIR_immi, imm);
        return ins;
    }

    LIns* LirBufWriter::insImmF(float f)
    {
        union{
            float flt;
            int32_t i;
        } u;
        u.flt = f;
        LInsIorF* insIorF = (LInsIorF*)_buf->makeRoom(sizeof(LInsIorF));
        LIns*  ins  = insIorF->getLIns();
        ins->initLInsIorF(LIR_immf, u.i);
        return ins;
    }

    LIns* LirBufWriter::insSafe(LOpcode op, void *payload)
    {
        LInsSafe* insS = (LInsSafe*)_buf->makeRoom(sizeof(LInsSafe));
        LIns*  ins  = insS->getLIns();
        ins->initLInsSafe(op, payload);
        return ins;
    }

#ifdef NANOJIT_64BIT
    LIns* LirBufWriter::insImmQ(uint64_t imm)
    {
        LInsQorD* insQorD = (LInsQorD*)_buf->makeRoom(sizeof(LInsQorD));
        LIns*     ins     = insQorD->getLIns();
        ins->initLInsQorD(LIR_immq, imm);
        return ins;
    }
#endif

    LIns* LirBufWriter::insImmD(double d)
    {
        LInsQorD* insQorD = (LInsQorD*)_buf->makeRoom(sizeof(LInsQorD));
        LIns*     ins     = insQorD->getLIns();
        union {
            double d;
            uint64_t q;
        } u;
        u.d = d;
        ins->initLInsQorD(LIR_immd, u.q);
        return ins;
    }

    LIns* LirBufWriter::insImmF4(const float4_t& f4)
    {
        LInsF4* insF4 = (LInsF4*)_buf->makeRoom(sizeof(LInsF4));
        LIns*  ins  = insF4->getLIns();
        ins->initLInsF4(LIR_immf4, f4);
        return ins;
    }

    LIns* LirBufWriter::insComment(const char* str)
    {
        // Allocate space for and copy the string.  We use the same allocator
        // as the normal LIR buffers so it has the same lifetime.
        char* str2 = (char*)_buf->_allocator.alloc(VMPI_strlen(str) + 1);
        VMPI_strcpy(str2, str);
        return ins1(LIR_comment, (LIns*)str);
    }

    LIns* LirBufWriter::insSkip(LIns* skipTo)
    {
        LInsSk* insSk = (LInsSk*)_buf->makeRoom(sizeof(LInsSk));
        LIns*   ins   = insSk->getLIns();
        ins->initLInsSk(skipTo);
        return ins;
    }

    LIns* LirBufWriter::insSwz(LIns* a, uint8_t mask)
    {
        LInsOp1b* ins1b = (LInsOp1b*)_buf->makeRoom(sizeof(LInsOp1b));
        LIns*  ins  = ins1b->getLIns();
        ins->initLInsOp1b(LIR_swzf4, a, mask);
        return ins;
    }

    LOpcode arithOpcodeD2I(LOpcode op)
    {
        switch (op) {
        case LIR_negd:  return LIR_negi;
        case LIR_addd:  return LIR_addi;
        case LIR_subd:  return LIR_subi;
        case LIR_muld:  return LIR_muli;
        default:        NanoAssert(0); return LIR_skip;
        }
    }

#ifdef NANOJIT_64BIT
    LOpcode cmpOpcodeI2Q(LOpcode op)
    {
        switch (op) {
        case LIR_eqi:    return LIR_eqq;
        case LIR_lti:    return LIR_ltq;
        case LIR_gti:    return LIR_gtq;
        case LIR_lei:    return LIR_leq;
        case LIR_gei:    return LIR_geq;
        case LIR_ltui:   return LIR_ltuq;
        case LIR_gtui:   return LIR_gtuq;
        case LIR_leui:   return LIR_leuq;
        case LIR_geui:   return LIR_geuq;
        default:        NanoAssert(0); return LIR_skip;
        }
    }
#endif

    LOpcode cmpOpcodeD2I(LOpcode op)
    {
        switch (op) {
        case LIR_eqd:    return LIR_eqi;
        case LIR_ltd:    return LIR_lti;
        case LIR_gtd:    return LIR_gti;
        case LIR_led:    return LIR_lei;
        case LIR_ged:    return LIR_gei;
        default:        NanoAssert(0); return LIR_skip;
        }
    }

    LOpcode cmpOpcodeD2UI(LOpcode op)
    {
        switch (op) {
        case LIR_eqd:    return LIR_eqi;
        case LIR_ltd:    return LIR_ltui;
        case LIR_gtd:    return LIR_gtui;
        case LIR_led:    return LIR_leui;
        case LIR_ged:    return LIR_geui;
        default:        NanoAssert(0); return LIR_skip;
        }
    }

    
    // This is never called, but that's ok because it contains only static
    // assertions.
    void LIns::staticSanityCheck()
    {
        // LIns must be word-sized.
        NanoStaticAssert(sizeof(LIns) == 1*sizeof(void*));

        // LInsXYZ have expected sizes too.
        NanoStaticAssert(sizeof(LInsOp0)  == 1*sizeof(void*));
        NanoStaticAssert(sizeof(LInsOp1)  == 2*sizeof(void*));
        NanoStaticAssert(sizeof(LInsOp2)  == 3*sizeof(void*));
        NanoStaticAssert(sizeof(LInsOp3)  == 4*sizeof(void*));
        NanoStaticAssert(sizeof(LInsLd)   == 3*sizeof(void*));
        NanoStaticAssert(sizeof(LInsSt)   == 4*sizeof(void*));
        NanoStaticAssert(sizeof(LInsSk)   == 2*sizeof(void*));
        NanoStaticAssert(sizeof(LInsC)    == 3*sizeof(void*));
        NanoStaticAssert(sizeof(LInsP)    == 2*sizeof(void*));
        NanoStaticAssert(sizeof(LInsIorF) == 2*sizeof(void*));
    #if defined NANOJIT_64BIT
        NanoStaticAssert(sizeof(LInsQorD) == 2*sizeof(void*));
        NanoStaticAssert(sizeof(LInsF4)   == 3*sizeof(void*));
    #else
        NanoStaticAssert(sizeof(LInsQorD) == 3*sizeof(void*));
        NanoStaticAssert(sizeof(LInsF4  ) == 5*sizeof(void*));
    #endif
        NanoStaticAssert(sizeof(LInsJtbl) == 4*sizeof(void*));

        // oprnd_1 must be in the same position in LIns{Op1,Op2,Op3,Ld,St,Jtbl}
        // because oprnd1() is used for all of them.
        #define OP1OFFSET (offsetof(LInsOp1,  ins) - offsetof(LInsOp1,  oprnd_1))
        NanoStaticAssert( OP1OFFSET == (offsetof(LInsOp2,  ins) - offsetof(LInsOp2,  oprnd_1)) );
        NanoStaticAssert( OP1OFFSET == (offsetof(LInsOp3,  ins) - offsetof(LInsOp3,  oprnd_1)) );
        NanoStaticAssert( OP1OFFSET == (offsetof(LInsLd,   ins) - offsetof(LInsLd,   oprnd_1)) );
        NanoStaticAssert( OP1OFFSET == (offsetof(LInsSt,   ins) - offsetof(LInsSt,   oprnd_1)) );
        NanoStaticAssert( OP1OFFSET == (offsetof(LInsJtbl, ins) - offsetof(LInsJtbl, oprnd_1)) );

        // oprnd_2 must be in the same position in LIns{Op2,Op3,St}
        // because oprnd2() is used for all of them.
        #define OP2OFFSET (offsetof(LInsOp2, ins) - offsetof(LInsOp2, oprnd_2))
        NanoStaticAssert( OP2OFFSET == (offsetof(LInsOp3, ins) - offsetof(LInsOp3, oprnd_2)) );
        NanoStaticAssert( OP2OFFSET == (offsetof(LInsSt,  ins) - offsetof(LInsSt,  oprnd_2)) );
        NanoStaticAssert(LIR_eqf==LIR_eqd+6);
        NanoStaticAssert(LIR_ltf==LIR_ltd+6);
        NanoStaticAssert(LIR_gtf==LIR_gtd+6);
        NanoStaticAssert(LIR_lef==LIR_led+6);
        NanoStaticAssert(LIR_gef==LIR_ged+6);
    }

    void LIns::overwriteWithSkip(LIns* skipTo)
    {
        // Ensure the instruction is at least as big as a LIR_skip.
        NanoAssert(insSizes[opcode()] >= insSizes[LIR_skip]);
        initLInsSk(skipTo);
    }

    bool insIsS16(LIns* i)
    {
        if (i->isImmI()) {
            int c = i->immI();
            return isS16(c);
        }
        if (i->isCmov()) {
            return insIsS16(i->oprnd2()) && insIsS16(i->oprnd3());
        }
        if (i->isCmp())
            return true;
        // many other possibilities too.
        return false;
    }

    LIns* ExprFilter::ins1(LOpcode v, LIns* oprnd)
    {
        switch (v) {
#ifdef NANOJIT_64BIT
        case LIR_q2i:
            if (oprnd->isImmQ())
                return insImmI(oprnd->immQlo());
            break;
        case LIR_i2q:
            if (oprnd->isImmI())
                return insImmQ(int64_t(int32_t(oprnd->immI())));
            break;
        case LIR_ui2uq:
            if (oprnd->isImmI())
                return insImmQ(uint64_t(uint32_t(oprnd->immI())));
            break;
        case LIR_dasq:
            if (oprnd->isop(LIR_qasd))
                return oprnd->oprnd1();
            break;
        case LIR_qasd:
            if (oprnd->isop(LIR_dasq))
                return oprnd->oprnd1();
            break;
#endif
#if NJ_SOFTFLOAT_SUPPORTED
        case LIR_dlo2i:
            if (oprnd->isImmD())
                return insImmI(oprnd->immDlo());
            if (oprnd->isop(LIR_ii2d))
                return oprnd->oprnd1();
            break;
        case LIR_dhi2i:
            if (oprnd->isImmD())
                return insImmI(oprnd->immDhi());
            if (oprnd->isop(LIR_ii2d))
                return oprnd->oprnd2();
            break;
#endif
        case LIR_noti:
            if (oprnd->isImmI())
                return insImmI(~oprnd->immI());
        involution:
            if (v == oprnd->opcode())
                return oprnd->oprnd1();
            break;
        case LIR_negi:
            if (oprnd->isImmI())
                return insImmI(-oprnd->immI());
            if (oprnd->isop(LIR_subi)) // -(a-b) = b-a
                return out->ins2(LIR_subi, oprnd->oprnd2(), oprnd->oprnd1());
            goto involution;
        case LIR_negd:
            if (oprnd->isImmD())
                return insImmD(-oprnd->immD());
            if (oprnd->isop(LIR_subd))
                return out->ins2(LIR_subd, oprnd->oprnd2(), oprnd->oprnd1());
            goto involution;
        case LIR_negf:
            if (oprnd->isImmF())
                return insImmF(-oprnd->immF());
            if (oprnd->isop(LIR_subf))
                return out->ins2(LIR_subf, oprnd->oprnd2(), oprnd->oprnd1());
            goto involution;
        case LIR_negf4:
            if (oprnd->isImmF4()) {
                // Use -0 here so that negating 0 produces -0.
                float4_t zero = { -0.0, -0.0, -0.0, -0.0 };
                return insImmF4(f4_sub(zero, oprnd->immF4()));
            }
            if (oprnd->isop(LIR_subf4))
                return out->ins2(LIR_subf4, oprnd->oprnd2(), oprnd->oprnd1());
            goto involution;
        case LIR_i2d:
            if (oprnd->isImmI())
                return insImmD(oprnd->immI());
            // Nb: i2d(d2i(x)) != x
            break;
#if defined NANOJIT_64BIT
        case LIR_q2d:
            if (oprnd->isImmQ())
                return insImmD(double(oprnd->immQ()));
            break;
#endif
        case LIR_d2i:
            if (oprnd->isImmD())
                return insImmI(int32_t(oprnd->immD()));
            if (oprnd->isop(LIR_i2d))
                return oprnd->oprnd1();
#if defined NANOJIT_64BIT
            if (oprnd->isop(LIR_q2d))
                return insImmI(int32_t(oprnd->immQ()));
#endif
            break;
        case LIR_ui2d:
            if (oprnd->isImmI())
                return insImmD(uint32_t(oprnd->immI()));
            break;
        case LIR_absd:
        case LIR_absf:
        case LIR_absf4:
            if (oprnd->opcode() == v)
                return oprnd; // abs(abs(x)) = abs(x)
            break;
        default:
            ;
        }

        return out->ins1(v, oprnd);
    }

    // This is an ugly workaround for an apparent compiler
    // bug; in VC2008, compiling with optimization on
    // will produce spurious errors if this code is inlined
    // into ExprFilter::ins2(). See https://bugzilla.mozilla.org/show_bug.cgi?id=538504
    inline double do_join(int32_t c1, int32_t c2)
    {
        union {
            double d;
            uint64_t u64;
        } u;
        u.u64 = uint32_t(c1) | uint64_t(c2)<<32;
        return u.d;
    }

    LIns* ExprFilter::ins2(LOpcode v, LIns* oprnd1, LIns* oprnd2)
    {
        NanoAssert(oprnd1 && oprnd2);

        //-------------------------------------------------------------------
        // Folding where the two operands are equal
        //-------------------------------------------------------------------
        if (oprnd1 == oprnd2) {
            // The operands are equal.
            switch (v) {
            case LIR_xori:
            case LIR_subi:
            case LIR_ltui:
            case LIR_gtui:
            case LIR_gti:
            case LIR_lti:
                return insImmI(0);

            case LIR_ori:
            case LIR_andi:
                return oprnd1;

            case LIR_lei:
            case LIR_leui:
            case LIR_gei:
            case LIR_geui:
                return insImmI(1);      // (x <= x) == 1; (x >= x) == 1

            default:
                break;
            }
        }

        //-------------------------------------------------------------------
        // Folding where both operands are immediates, grouped by type
        //-------------------------------------------------------------------
        if (oprnd1->isImmI() && oprnd2->isImmI()) {
            // The operands are both int immediates.
            int32_t c1 = oprnd1->immI();
            int32_t c2 = oprnd2->immI();
            double d;
            int32_t r;

            switch (v) {
#if NJ_SOFTFLOAT_SUPPORTED
            case LIR_ii2d:  return insImmD(do_join(c1, c2));
#endif
            case LIR_eqi:   return insImmI(c1 == c2);
            case LIR_lti:   return insImmI(c1 <  c2);
            case LIR_gti:   return insImmI(c1 >  c2);
            case LIR_lei:   return insImmI(c1 <= c2);
            case LIR_gei:   return insImmI(c1 >= c2);
            case LIR_ltui:  return insImmI(uint32_t(c1) <  uint32_t(c2));
            case LIR_gtui:  return insImmI(uint32_t(c1) >  uint32_t(c2));
            case LIR_leui:  return insImmI(uint32_t(c1) <= uint32_t(c2));
            case LIR_geui:  return insImmI(uint32_t(c1) >= uint32_t(c2));

            case LIR_lshi:  return insImmI(c1 << (c2 & 0x1f));
            case LIR_rshi:  return insImmI(c1 >> (c2 & 0x1f));
            case LIR_rshui: return insImmI(uint32_t(c1) >> (c2 & 0x1f));

            case LIR_ori:   return insImmI(c1 | c2);
            case LIR_andi:  return insImmI(c1 & c2);
            case LIR_xori:  return insImmI(c1 ^ c2);

            case LIR_addi:  d = double(c1) + double(c2);    goto fold;
            case LIR_subi:  d = double(c1) - double(c2);    goto fold;
            case LIR_muli:  d = double(c1) * double(c2);    goto fold;
            fold:
                // Make sure the constant expression doesn't overflow.  This
                // probably isn't necessary, because the C++ overflow
                // behaviour is very likely to be the same as the machine code
                // overflow behaviour, but we do it just to be safe.
                r = int32_t(d);
                if (r == d)
                    return insImmI(r);
                break;

#if defined NANOJIT_IA32 || defined NANOJIT_X64
            case LIR_divi:
            case LIR_modi:
                // We can't easily fold div and mod, since folding div makes it
                // impossible to calculate the mod that refers to it. The
                // frontend shouldn't emit div and mod with constant operands.
                NanoAssert(0);
#endif
            default:
                break;
            }

#ifdef NANOJIT_64BIT
        } else if (oprnd1->isImmQ() && oprnd2->isImmQ()) {
            // The operands are both quad immediates.
            int64_t c1 = oprnd1->immQ();
            int64_t c2 = oprnd2->immQ();
            static const int64_t MIN_INT64 = int64_t(0x8000000000000000LL);
            static const int64_t MAX_INT64 = int64_t(0x7FFFFFFFFFFFFFFFLL);

            switch (v) {
            case LIR_eqq:   return insImmI(c1 == c2);
            case LIR_ltq:   return insImmI(c1 <  c2);
            case LIR_gtq:   return insImmI(c1 >  c2);
            case LIR_leq:   return insImmI(c1 <= c2);
            case LIR_geq:   return insImmI(c1 >= c2);
            case LIR_ltuq:  return insImmI(uint64_t(c1) <  uint64_t(c2));
            case LIR_gtuq:  return insImmI(uint64_t(c1) >  uint64_t(c2));
            case LIR_leuq:  return insImmI(uint64_t(c1) <= uint64_t(c2));
            case LIR_geuq:  return insImmI(uint64_t(c1) >= uint64_t(c2));

            case LIR_orq:   return insImmQ(c1 | c2);
            case LIR_andq:  return insImmQ(c1 & c2);
            case LIR_xorq:  return insImmQ(c1 ^ c2);

            // Nb: LIR_rshq, LIR_lshq and LIR_rshuq aren't here because their
            // RHS is an int.  They are below.

            case LIR_addq:
                // Overflow is only possible if both values are positive or
                // both negative.  Just like the 32-bit case, this check
                // probably isn't necessary, because the C++ overflow
                // behaviour is very likely to be the same as the machine code
                // overflow behaviour, but we do it just to be safe.
                if (c1 > 0 && c2 > 0) {
                    // Overflows if: c1 + c2 > MAX_INT64
                    // Re-express to avoid overflow in the check: c1 > MAX_INT64 - c2
                    if (c1 > MAX_INT64 - c2)
                        break;                  // overflow
                } else if (c1 < 0 && c2 < 0) {
                    // Overflows if: c1 + c2 < MIN_INT64
                    // Re-express to avoid overflow in the check: c1 < MIN_INT64 - c2
                    if (c1 < MIN_INT64 - c2)
                        break;                  // overflow
                }
                return insImmQ(c1 + c2);

            case LIR_subq:
                // Overflow is only possible if one value is positive and one
                // negative.
                if (c1 > 0 && c2 < 0) {
                    // Overflows if: c1 - c2 > MAX_INT64
                    // Re-express to avoid overflow in the check: c1 > MAX_INT64 + c2
                    if (c1 > MAX_INT64 + c2)
                        break;                  // overflow
                } else if (c1 < 0 && c2 > 0) {
                    // Overflows if: c1 - c2 < MIN_INT64
                    // Re-express to avoid overflow in the check: c1 < MIN_INT64 + c2
                    if (c1 < MIN_INT64 + c2)
                        break;                  // overflow
                }
                return insImmQ(c1 - c2);

            default:
                break;
            }

        } else if (oprnd1->isImmQ() && oprnd2->isImmI()) {
            // The first operand is a quad immediate, the second is an int
            // immediate.
            int64_t c1 = oprnd1->immQ();
            int32_t c2 = oprnd2->immI();

            switch (v) {
            case LIR_lshq:  return insImmQ(c1 << (c2 & 0x3f));
            case LIR_rshq:  return insImmQ(c1 >> (c2 & 0x3f));
            case LIR_rshuq: return insImmQ(uint64_t(c1) >> (c2 & 0x3f));

            default:        break;
            }
#endif  // NANOJIT_64BIT

        } else if (oprnd1->isImmD() && oprnd2->isImmD()) {
            // The operands are both double immediates.
            double c1 = oprnd1->immD();
            double c2 = oprnd2->immD();
            switch (v) {
            case LIR_eqd:   return insImmI(c1 == c2);
            case LIR_ltd:   return insImmI(c1 <  c2);
            case LIR_gtd:   return insImmI(c1 >  c2);
            case LIR_led:   return insImmI(c1 <= c2);
            case LIR_ged:   return insImmI(c1 >= c2);

            case LIR_addd:  return insImmD(c1 + c2);
            case LIR_subd:  return insImmD(c1 - c2);
            case LIR_muld:  return insImmD(c1 * c2);
            case LIR_divd:  return insImmD(c1 / c2);

            default:        break;
            }
        } 
        else if (oprnd1->isImmF() && oprnd2->isImmF()) {
            // The operands are both single-precision float immediates.
            float c1 = oprnd1->immF();
            float c2 = oprnd2->immF();
            switch (v) {
                case LIR_eqf:   return insImmI(c1 == c2);
                case LIR_ltf:   return insImmI(c1 <  c2);
                case LIR_gtf:   return insImmI(c1 >  c2);
                case LIR_lef:   return insImmI(c1 <= c2);
                case LIR_gef:   return insImmI(c1 >= c2);
                    
                case LIR_addf:  return insImmF(c1 + c2);
                case LIR_subf:  return insImmF(c1 - c2);
                case LIR_mulf:  return insImmF(c1 * c2);
                case LIR_divf:  return insImmF(c1 / c2);
                    
                default:        break;
            }
        }
        else if (oprnd1->isImmF4() && oprnd2->isImmF4()) {
            // The operands are both vectors of four single-precision float immediates.
            float4_t c1 = oprnd1->immF4();
            float4_t c2 = oprnd2->immF4();
            switch (v) {
                case LIR_eqf4:  return insImmI(f4_eq_i(c1, c2));
                    
                case LIR_addf4: return insImmF4(f4_add(c1, c2));
                case LIR_subf4: return insImmF4(f4_sub(c1, c2));
                case LIR_mulf4: return insImmF4(f4_mul(c1, c2));
                case LIR_divf4: return insImmF4(f4_div(c1, c2));

                default:        break;
            }
        }
        
        //-------------------------------------------------------------------
        // If only one operand is an immediate, make sure it's on the RHS, if possible
        //-------------------------------------------------------------------
        if (oprnd1->isImmAny() && !oprnd2->isImmAny()) {
            switch (v) {
            case LIR_eqi:
            CASE64(LIR_eqq:)
            case LIR_eqd:
            case LIR_eqf:
            case LIR_eqf4:
            case LIR_addi:
            CASE64(LIR_addq:)
            case LIR_addd:
            case LIR_addf:
            case LIR_addf4:
            case LIR_muli:
            case LIR_muld:
            case LIR_mulf:
            case LIR_mulf4:
            case LIR_andi:
            CASE64(LIR_andq:)
            case LIR_ori:
            CASE64(LIR_orq:)
            case LIR_xori:
            CASE64(LIR_xorq:) {
                // move immediate to RHS
                LIns* t = oprnd2;
                oprnd2 = oprnd1;
                oprnd1 = t;
                break;
            }
            default:
                if (isCmpOpcode(v)) {
                    // move immediate to RHS, swap the operator
                    LIns *t = oprnd2;
                    oprnd2 = oprnd1;
                    oprnd1 = t;
                    v = invertCmpOpcode(v);
                }
                break;
            }
        }

        //-------------------------------------------------------------------
        // Folding where the RHS is an immediate
        //-------------------------------------------------------------------
        if (oprnd2->isImmI()) {
            // The second operand is an int immediate.
            int c = oprnd2->immI();
            switch (v) {
            case LIR_addi:
                if (oprnd1->isop(LIR_addi) && oprnd1->oprnd2()->isImmI()) {
                    // add(add(x,c1),c2) => add(x,c1+c2)
                    c += oprnd1->oprnd2()->immI();
                    oprnd2 = insImmI(c);
                    oprnd1 = oprnd1->oprnd1();
                }
                break;

            case LIR_subi:
                if (oprnd1->isop(LIR_addi) && oprnd1->oprnd2()->isImmI()) {
                    // sub(add(x,c1),c2) => add(x,c1-c2)
                    c = oprnd1->oprnd2()->immI() - c;
                    oprnd2 = insImmI(c);
                    oprnd1 = oprnd1->oprnd1();
                    v = LIR_addi;
                }
                break;

            case LIR_rshi:
                if (c == 16 && oprnd1->isop(LIR_lshi) &&
                    oprnd1->oprnd2()->isImmI(16) &&
                    insIsS16(oprnd1->oprnd1()))
                {
                    // rsh(lhs(x,16),16) == x, if x is S16
                    return oprnd1->oprnd1();
                }
                break;

            default:
                break;
            }

            if (c == 0) {
                switch (v) {
                case LIR_addi:
                case LIR_ori:
                case LIR_xori:
                case LIR_subi:
                case LIR_lshi:
                case LIR_rshi:
                case LIR_rshui:
                CASE64(LIR_lshq:)   // These are here because their RHS is an int
                CASE64(LIR_rshq:)
                CASE64(LIR_rshuq:)
                    return oprnd1;

                case LIR_andi:
                case LIR_muli:
                case LIR_ltui: // unsigned < 0 -> always false
                    return oprnd2;

                case LIR_geui: // unsigned >= 0 -> always true
                    return insImmI(1);

                case LIR_eqi:
                    if (oprnd1->isop(LIR_ori) &&
                        oprnd1->oprnd2()->isImmI() &&
                        oprnd1->oprnd2()->immI() != 0)
                    {
                        // (x or c) != 0 if c != 0
                        return insImmI(0);
                    }

                default:
                    break;
                }

            } else if (c == -1) {
                switch (v) {
                case LIR_ori:  return oprnd2;       // x | -1 = -1
                case LIR_andi: return oprnd1;       // x & -1 = x
                case LIR_gtui: return insImmI(0);   // u32 >  0xffffffff -> always false
                case LIR_leui: return insImmI(1);   // u32 <= 0xffffffff -> always true
                default:       break;
                }

            } else if (c == 1) {
                if (oprnd1->isCmp()) {
                    switch (v) {
                    case LIR_ori:   return oprnd2;      // 0or1 | 1 = 1   (and oprnd2 == 1)
                    case LIR_andi:  return oprnd1;      // 0or1 & 1 = 0or1
                    case LIR_gtui:  return insImmI(0);  // 0or1 > 1 -> always false
                    default:        break;
                    }
                } else if (v == LIR_muli) {
                    return oprnd1;          // x * 1 = x
                }
            }

#ifdef NANOJIT_64BIT
        } else if (oprnd2->isImmQ()) {
            // The second operand is a quad immediate.
            int64_t c = oprnd2->immQ();
            if (c == 0) {
                switch (v) {
                case LIR_addq:
                case LIR_orq:
                case LIR_xorq:
                case LIR_subq:
                    return oprnd1;

                case LIR_andq:
                    return oprnd2;

                case LIR_ltuq: // unsigned < 0 -> always false
                    return insImmI(0);

                case LIR_geuq: // unsigned >= 0 -> always true
                    return insImmI(1);

                default:
                    break;
                }

            } else if (c == -1) {
                switch (v) {
                case LIR_orq:  return oprnd2;       // x | -1 = -1
                case LIR_andq: return oprnd1;       // x & -1 = x
                case LIR_gtuq: return insImmI(0);   // u64 >  0xffffffffffffffff -> always false
                case LIR_leuq: return insImmI(1);   // u64 <= 0xffffffffffffffff -> always true
                default:       break;
                }

            } else if (c == 1) {
                if (oprnd1->isCmp()) {
                    switch (v) {
                    case LIR_orq:   return oprnd2;      // 0or1 | 1 = 1   (and oprnd2 == 1)
                    case LIR_andq:  return oprnd1;      // 0or1 & 1 = 0or1
                    case LIR_gtuq:  return insImmI(0);  // 0or1 > 1 -> always false
                    default:        break;
                    }
                }
            }
#endif  // NANOJIT_64BIT
        }

#if NJ_SOFTFLOAT_SUPPORTED
        //-------------------------------------------------------------------
        // SoftFloat-specific folding
        //-------------------------------------------------------------------
        LIns* ins;
        if (v == LIR_ii2d && oprnd1->isop(LIR_dlo2i) && oprnd2->isop(LIR_dhi2i) &&
            (ins = oprnd1->oprnd1()) == oprnd2->oprnd1())
        {
            // qjoin(qlo(x),qhi(x)) == x
            return ins;
        }
#endif

        //-------------------------------------------------------------------
        // No folding possible
        //-------------------------------------------------------------------
        return out->ins2(v, oprnd1, oprnd2);
    }

    LIns* ExprFilter::ins3(LOpcode v, LIns* oprnd1, LIns* oprnd2, LIns* oprnd3)
    {
        NanoAssert(oprnd1 && oprnd2 && oprnd3);
        NanoAssert(isCmovOpcode(v));
        if (oprnd2 == oprnd3) {
            // c ? a : a => a
            return oprnd2;
        }
        if (oprnd1->isImmI()) {
            // immediate ? x : y => return x or y depending on immediate
            return oprnd1->immI() ? oprnd2 : oprnd3;
        }
        if (oprnd1->isop(LIR_eqi) &&
            ((oprnd1->oprnd2() == oprnd2 && oprnd1->oprnd1() == oprnd3) ||
             (oprnd1->oprnd1() == oprnd2 && oprnd1->oprnd2() == oprnd3))) {
            // (y == x) ? x : y  =>  y
            // (x == y) ? x : y  =>  y
            return oprnd3;
        }

        return out->ins3(v, oprnd1, oprnd2, oprnd3);
    }

    LIns* ExprFilter::ins4(LOpcode v, LIns* oprnd1, LIns* oprnd2, LIns* oprnd3, LIns* oprnd4)
    {
        NanoAssert(oprnd1 && oprnd2 && oprnd3 && oprnd4);
        NanoAssert(v == LIR_ffff2f4);
        if (oprnd1 == oprnd2 && oprnd1 == oprnd3 && oprnd1 == oprnd4)
            return out->ins1(LIR_f2f4, oprnd1); 
        return out->ins4(v, oprnd1, oprnd2, oprnd3, oprnd4);
    }        
    
    LIns* ExprFilter::insGuard(LOpcode v, LIns* c, GuardRecord *gr)
    {
        if (v == LIR_xt || v == LIR_xf) {
            if (c->isImmI()) {
                if ((v == LIR_xt && !c->immI()) || (v == LIR_xf && c->immI())) {
                    return 0; // no guard needed
                } else {
#ifdef JS_TRACER
                    // We're emitting a guard that will always fail. Any code
                    // emitted after this guard is dead code.  But it won't be
                    // optimized away, and it could indicate a performance
                    // problem or other bug, so assert in debug builds.
                    NanoAssertMsg(0, "Constantly false guard detected");
#endif
                    return out->insGuard(LIR_x, NULL, gr);
                }
            } else {
                while (c->isop(LIR_eqi) && c->oprnd1()->isCmp() && c->oprnd2()->isImmI(0)) {
                    // xt(eq(cmp,0)) => xf(cmp)   or   xf(eq(cmp,0)) => xt(cmp)
                    v = invertCondGuardOpcode(v);
                    c = c->oprnd1();
                }
            }
        }
        return out->insGuard(v, c, gr);
    }

    // Simplify operator if possible.  Always return NULL if overflow is possible.

    LIns* ExprFilter::simplifyOverflowArith(LOpcode op, LIns** opnd1, LIns** opnd2)
    {
        LIns* oprnd1 = *opnd1;
        LIns* oprnd2 = *opnd2;

        if (oprnd1->isImmI() && oprnd2->isImmI()) {
            int32_t c1 = oprnd1->immI();
            int32_t c2 = oprnd2->immI();
            double d = 0.0;

            // The code below attempts to perform the operation while
            // detecting overflow.  For multiplication, we may unnecessarily
            // infer a possible overflow due to the insufficient integer
            // range of the double type.

            switch (op) {
            case LIR_addjovi:
            case LIR_addxovi:    d = double(c1) + double(c2);    break;
            case LIR_subjovi:
            case LIR_subxovi:    d = double(c1) - double(c2);    break;
            case LIR_muljovi:
            case LIR_mulxovi:    d = double(c1) * double(c2);    break;
            default:             NanoAssert(0);                  break;
            }
            int32_t r = int32_t(d);
            if (r == d)
                return insImmI(r);

        } else if (oprnd1->isImmI() && !oprnd2->isImmI()) {
            switch (op) {
            case LIR_addjovi:
            case LIR_addxovi:
            case LIR_muljovi:
            case LIR_mulxovi: {
                // swap operands, moving immediate to RHS
                LIns* t = oprnd2;
                oprnd2 = oprnd1;
                oprnd1 = t;
                // swap actual arguments in caller as well
                *opnd1 = oprnd1;
                *opnd2 = oprnd2;
                break;
            }
            case LIR_subjovi:
            case LIR_subxovi:
                break;
            default:
                NanoAssert(0);
            }
        }

        if (oprnd2->isImmI()) {
            int c = oprnd2->immI();
            if (c == 0) {
                switch (op) {
                case LIR_addjovi:
                case LIR_addxovi:
                case LIR_subjovi:
                case LIR_subxovi:
                    return oprnd1;
                case LIR_muljovi:
                case LIR_mulxovi:
                    return oprnd2;
                default:
                    ;
                }
            } else if (c == 1 && (op == LIR_muljovi || op == LIR_mulxovi)) {
                return oprnd1;
            }
        }

        return NULL;
    }

    LIns* ExprFilter::insGuardXov(LOpcode op, LIns* oprnd1, LIns* oprnd2, GuardRecord *gr)
    {
        LIns* simplified = simplifyOverflowArith(op, &oprnd1, &oprnd2);
        if (simplified)
            return simplified;

        return out->insGuardXov(op, oprnd1, oprnd2, gr);
    }

    LIns* ExprFilter::insBranch(LOpcode v, LIns *c, LIns *t)
    {
        if (v == LIR_jt || v == LIR_jf) {
            if (c->isImmI()) {
                if ((v == LIR_jt && !c->immI()) || (v == LIR_jf && c->immI())) {
                    return 0; // no jump needed
                } else {
#ifdef JS_TRACER
                    // We're emitting a branch that will always be taken.  This may
                    // result in dead code that will not be optimized away, and
                    // could indicate a performance problem or other bug, so assert
                    // in debug builds.
                    NanoAssertMsg(0, "Constantly taken branch detected");
#endif
                    return out->insBranch(LIR_j, NULL, t);
                }
            } else {
                while (c->isop(LIR_eqi) && c->oprnd1()->isCmp() && c->oprnd2()->isImmI(0)) {
                    // jt(eq(cmp,0)) => jf(cmp)   or   jf(eq(cmp,0)) => jt(cmp)
                    v = invertCondJmpOpcode(v);
                    c = c->oprnd1();
                }
            }
        }
        return out->insBranch(v, c, t);
    }

    LIns* ExprFilter::insBranchJov(LOpcode op, LIns* oprnd1, LIns* oprnd2, LIns* target)
    {
        LIns* simplified = simplifyOverflowArith(op, &oprnd1, &oprnd2);
        if (simplified)
            return simplified;

        return out->insBranchJov(op, oprnd1, oprnd2, target);
    }

    LIns* ExprFilter::insLoad(LOpcode op, LIns* base, int32_t off, AccSet accSet, LoadQual loadQual) {
        if (base->isImmP() && !isS8(off)) {
            // if the effective address is constant, then transform:
            // ld const[bigconst] => ld (const+bigconst)[0]
            // note: we don't do this optimization for <8bit field offsets,
            // under the assumption that we're more likely to CSE-match the
            // constant base address if we dont const-fold small offsets.
            uintptr_t p = (uintptr_t)base->immP() + off;
            return out->insLoad(op, insImmP((void*)p), 0, accSet, loadQual);
        }
        return out->insLoad(op, base, off, accSet, loadQual);
    }

    LIns* LirWriter::insStore(LIns* value, LIns* base, int32_t d, AccSet accSet)
    {
        // Determine which kind of store should be used for 'value' based on
        // its type.
        LOpcode op = LOpcode(0);
        switch (value->retType()) {
        case LTy_I: op = LIR_sti;   break;
#ifdef NANOJIT_64BIT
        case LTy_Q: op = LIR_stq;   break;
#endif
        case LTy_F: op = LIR_stf;   break;
        case LTy_F4:op = LIR_stf4;  break;
        case LTy_D: op = LIR_std;   break;
        case LTy_V: NanoAssert(0);  break;
        default:    NanoAssert(0);  break;
        }
        return insStore(op, value, base, d, accSet);
    }

    LIns* LirWriter::insChoose(LIns* cond, LIns* iftrue, LIns* iffalse, bool use_cmov)
    {
        // 'cond' must be a conditional, unless it has been optimized to 0 or
        // 1.  In that case make it an ==0 test and flip the branches.  It'll
        // get constant-folded by ExprFilter subsequently.
        if (!cond->isCmp()) {
            NanoAssert(cond->isImmI());
            cond = insEqI_0(cond);
            LIns* tmp = iftrue;
            iftrue = iffalse;
            iffalse = tmp;
        }

        if (use_cmov) {
            LOpcode op = LIR_cmovi;
            if (iftrue->isI() && iffalse->isI()) {
                op = LIR_cmovi;
#ifdef NANOJIT_64BIT
            } else if (iftrue->isQ() && iffalse->isQ()) {
                op = LIR_cmovq;
#endif
            } else if (iftrue->isF() && iffalse->isF()) {
                op = LIR_cmovf;
            } else if (iftrue->isF4() && iffalse->isF4()) {
                op = LIR_cmovf4;
            } else if (iftrue->isD() && iffalse->isD()) {
                op = LIR_cmovd;
            } else {
                NanoAssert(0);  // type error
            }
            return ins3(op, cond, iftrue, iffalse);
        }

        LIns* ncond = ins1(LIR_negi, cond); // cond ? -1 : 0
        return ins2(LIR_ori,
                    ins2(LIR_andi, iftrue, ncond),
                    ins2(LIR_andi, iffalse, ins1(LIR_noti, ncond)));
    }

    LIns* LirBufWriter::insCall(const CallInfo *ci, LIns* args[])
    {
        LOpcode op = getCallOpcode(ci);
#if NJ_SOFTFLOAT_SUPPORTED
        // SoftFloat: convert LIR_calld to LIR_calli.
        if (_config.soft_float && op == LIR_calld)
            op = LIR_calli;
#endif

        int32_t argc = ci->count_args();
        NanoAssert(argc <= (int)MAXARGS);

        // Allocate space for and copy the arguments.  We use the same
        // allocator as the normal LIR buffers so it has the same lifetime.
        // Nb: this must be kept in sync with arg().
        LIns** args2 = (LIns**)_buf->_allocator.alloc(argc * sizeof(LIns*));
        memcpy(args2, args, argc * sizeof(LIns*));

        // Allocate and write the call instruction.
        LInsC* insC = (LInsC*)_buf->makeRoom(sizeof(LInsC));
        LIns*  ins  = insC->getLIns();
        ins->initLInsC(op, args2, ci);
        NanoAssert(!ins->isInReg());
        return ins;
    }

    using namespace avmplus;

    StackFilter::StackFilter(LirFilter *in, Allocator& alloc, LIns* sp)
        : LirFilter(in), sp(sp), stk(alloc), top(0)
    {}

    // If we see a sequence like this:
    //
    //   sti sp[0]
    //   ...
    //   sti sp[0]
    //
    // where '...' contains no guards, we can remove the first store.  Also,
    // because stack entries are eight bytes each (we check this), if we have
    // this:
    //
    //   stfi sp[0]
    //   ...
    //   sti sp[0]
    //
    // we can again remove the first store -- even though the second store
    // doesn't clobber the high four bytes -- because we know the entire value
    // stored by the first store is dead.
    //
    LIns* StackFilter::read()
    {
        for (;;) {
            LIns* ins = in->read();

            if (ins->isStore()) {
                LIns* base = ins->oprnd2();
                if (base == sp) {
                    // 'disp' must be eight-aligned because each stack entry is 8 bytes.
                    NanoAssert((ins->disp() & 0x7) == 0);

                    int d = ins->disp() >> 3;
                    if (d >= top) {
                        continue;
                    } else {
                        d = top - d;
                        if (stk.get(d)) {
                            continue;
                        } else {
                            stk.set(d);
                        }
                    }
                }
            }
            /*
             * NB: If there is a backward branch other than the loop-restart branch, this is
             * going to be wrong. Unfortunately there doesn't seem to be an easy way to detect
             * such branches. Just do not create any.
             *
             * The isLive() call is valid because liveness will have been
             * computed by Assembler::gen() for every instruction following
             * this guard.
             */
            else if (ins->isGuard() && ins->isLive()) {
                stk.reset();
                top = getTop(ins);
                top >>= 3;
            }

            return ins;
        }
    }

#ifdef NJ_VERBOSE
    class RetiredEntry
    {
    public:
        Seq<LIns*>* live;
        LIns* i;
        RetiredEntry(): live(NULL), i(NULL) {}
    };

    class LiveTable
    {
        Allocator& alloc;
    public:
        HashMap<LIns*, LIns*> live;
        SeqBuilder<RetiredEntry*> retired;
        int retiredCount;
        int maxlive;
        LiveTable(Allocator& alloc)
            : alloc(alloc)
            , live(alloc)
            , retired(alloc)
            , retiredCount(0)
            , maxlive(0)
        { }

        void add(LIns* ins, LIns* use) {
            if (!ins->isImmAny() && !live.containsKey(ins)) {
                NanoAssert(size_t(ins->opcode()) < sizeof(lirNames) / sizeof(lirNames[0]));
                live.put(ins,use);
            }
        }

        void retire(LIns* i) {
            RetiredEntry *e = new (alloc) RetiredEntry();
            e->i = i;
            InsList livelist(alloc);
            HashMap<LIns*, LIns*>::Iter iter(live);
            int live_count = 0;
            while (iter.next()) {
                LIns* ins = iter.key();
                if (!ins->isV()) {
                    live_count++;
                    livelist.insert(ins);
                }
            }
            e->live = livelist.get();
            if (live_count > maxlive)
                maxlive = live_count;

            live.remove(i);
            retired.insert(e);
            retiredCount++;
        }

        bool contains(LIns* i) {
            return live.containsKey(i);
        }
    };

    /*
     * traverse the LIR buffer and discover which instructions are live
     * by starting from instructions with side effects (stores, calls, branches)
     * and marking instructions used by them.  Works bottom-up, in one pass.
     * if showLiveRefs == true, also print the set of live expressions next to
     * each instruction
     */
    void live(LirFilter* in, Allocator& alloc, Fragment *frag, LogControl *logc)
    {
        // traverse backwards to find live exprs and a few other stats.

        LiveTable live(alloc);
        uint32_t exits = 0;
        int total = 0;
        if (frag->lirbuf->state)
            live.add(frag->lirbuf->state, 0);
        for (LIns* ins = in->read(); !ins->isop(LIR_start); ins = in->read())
        {
            total++;

            // First handle instructions that are always live (ie. those that
            // don't require being marked as live), eg. those with
            // side-effects.  We ignore LIR_paramp.
            if (ins->isLive() && !ins->isop(LIR_paramp))
            {
                live.add(ins, 0);
                if (ins->isGuard())
                    exits++;
            }

            // now propagate liveness
            if (live.contains(ins))
            {
                live.retire(ins);

                switch (ins->opcode()) {
                case LIR_skip:
                    NanoAssertMsg(0, "Shouldn't see LIR_skip");
                    break;

                case LIR_start:
                case LIR_regfence:
                case LIR_pushstate:
                case LIR_popstate:
                case LIR_memfence:
                case LIR_restorepc:
                case LIR_paramp:
                case LIR_x:
                case LIR_xbarrier:
                case LIR_j:
                case LIR_label:
                case LIR_immi:
                CASE64(LIR_immq:)
                case LIR_immd:
                case LIR_immf:
                case LIR_immf4:
                case LIR_allocp:
                case LIR_comment:
                    // No operands, do nothing.
                    break;

                case LIR_ldi:
                CASE64(LIR_ldq:)
                case LIR_ldd:
                case LIR_ldf:
                case LIR_ldf4:
                case LIR_lduc2ui:
                case LIR_ldus2ui:
                case LIR_ldc2i:
                case LIR_lds2i:
                case LIR_ldf2d:
                case LIR_reti:
                CASE64(LIR_retq:)
                case LIR_retd:
                case LIR_retf:
                case LIR_retf4:
                case LIR_livei:
                CASE64(LIR_liveq:)
                case LIR_lived:
                case LIR_livef:
                case LIR_livef4:
                case LIR_xt:
                case LIR_xf:
                case LIR_jt:
                case LIR_jf:
				case LIR_brsavpc:
                case LIR_jtbl:
                case LIR_negi:
                case LIR_noti:
                case LIR_negd:
                case LIR_negf:
                case LIR_negf4:
                case LIR_absd:
                case LIR_absf:
                case LIR_absf4:
                case LIR_recipf:
                case LIR_recipf4:
                case LIR_rsqrtf:
                case LIR_rsqrtf4:
                case LIR_sqrtf:
                case LIR_sqrtf4:
                case LIR_sqrtd:
                CASESF(LIR_dlo2i:)
                CASESF(LIR_dhi2i:)
                CASESF(LIR_hcalli:)
                CASE64(LIR_i2q:)
                CASE64(LIR_ui2uq:)
                case LIR_i2d:
                CASE64(LIR_q2d:)
                case LIR_ui2d:
                case LIR_i2f:
                case LIR_ui2f:
                case LIR_d2f:
                case LIR_f2d:
                case LIR_f2f4:
                case LIR_f4x:
                case LIR_f4y:
                case LIR_f4z:
                case LIR_f4w:
                case LIR_swzf4:
                CASE64(LIR_q2i:)
                case LIR_d2i:
                CASE64(LIR_dasq:)
                CASE64(LIR_qasd:)
                CASE86(LIR_modi:)
                    live.add(ins->oprnd1(), 0);
                    break;

                case LIR_sti:
                CASE64(LIR_stq:)
                case LIR_std:
                case LIR_stf:
                case LIR_stf4:
                case LIR_sti2c:
                case LIR_sti2s:
                case LIR_std2f:
                case LIR_eqi:
                case LIR_lti:
                case LIR_gti:
                case LIR_lei:
                case LIR_gei:
                case LIR_ltui:
                case LIR_gtui:
                case LIR_leui:
                case LIR_geui:
                case LIR_eqd:
                case LIR_ltd:
                case LIR_gtd:
                case LIR_led:
                case LIR_ged:
                case LIR_eqf:
                case LIR_ltf:
                case LIR_gtf:
                case LIR_lef:
                case LIR_gef:
                case LIR_eqf4:
                CASE64(LIR_eqq:)
                CASE64(LIR_ltq:)
                CASE64(LIR_gtq:)
                CASE64(LIR_leq:)
                CASE64(LIR_geq:)
                CASE64(LIR_ltuq:)
                CASE64(LIR_gtuq:)
                CASE64(LIR_leuq:)
                CASE64(LIR_geuq:)
                case LIR_lshi:
                case LIR_rshi:
                case LIR_rshui:
                CASE64(LIR_lshq:)
                CASE64(LIR_rshq:)
                CASE64(LIR_rshuq:)
                case LIR_addi:
                case LIR_subi:
                case LIR_muli:
                case LIR_addxovi:
                case LIR_subxovi:
                case LIR_mulxovi:
                case LIR_addjovi:
                case LIR_subjovi:
                case LIR_muljovi:
                CASE86(LIR_divi:)
                case LIR_addd:
                case LIR_subd:
                case LIR_muld:
                case LIR_divd:
                case LIR_addf:
                case LIR_subf:
                case LIR_mulf:
                case LIR_divf:
                case LIR_addf4:
                case LIR_subf4:
                case LIR_mulf4:
                case LIR_divf4:
                case LIR_dotf4:
                case LIR_dotf3:
                case LIR_dotf2:
                case LIR_minf4:
                case LIR_maxf4:
                case LIR_cmpgtf4:
                case LIR_cmpgef4:
                case LIR_cmpltf4:
                case LIR_cmplef4:
                case LIR_cmpeqf4:
                case LIR_cmpnef4:
                CASE64(LIR_addq:)
                CASE64(LIR_subq:)
                CASE64(LIR_addjovq:)
                CASE64(LIR_subjovq:)
                case LIR_andi:
                case LIR_ori:
                case LIR_xori:
                CASE64(LIR_andq:)
                CASE64(LIR_orq:)
                CASE64(LIR_xorq:)
                CASESF(LIR_ii2d:)
                case LIR_file:
                case LIR_line:
                    live.add(ins->oprnd1(), 0);
                    live.add(ins->oprnd2(), 0);
                    break;

                case LIR_cmovi:
                CASE64(LIR_cmovq:)
                case LIR_cmovd:
                case LIR_cmovf:
                case LIR_cmovf4:
                    live.add(ins->oprnd1(), 0);
                    live.add(ins->oprnd2(), 0);
                    live.add(ins->oprnd3(), 0);
                    break;
                case LIR_ffff2f4:
                    live.add(ins->oprnd1(), 0);
                    live.add(ins->oprnd2(), 0);
                    live.add(ins->oprnd3(), 0);
                    live.add(ins->oprnd4(), 0);
                    break;
                        
                case LIR_callv:
                case LIR_calli:
                CASE64(LIR_callq:)
                case LIR_calld:
                case LIR_callf:
                case LIR_callf4:
                    for (int i = 0, argc = ins->argc(); i < argc; i++)
                        live.add(ins->arg(i), 0);
                    break;

                default:
                    NanoAssertMsgf(0, "unhandled opcode: %d", ins->opcode());
                    break;
                }
            }
        }

        logc->printf("  Live instruction count %d, total %u, max pressure %d\n",
                     live.retiredCount, total, live.maxlive);
        if (exits > 0)
            logc->printf("  Side exits %u\n", exits);
        logc->printf("  Showing LIR instructions with live-after variables\n");
        logc->printf("\n");

        // print live exprs, going forwards
        LInsPrinter *printer = frag->lirbuf->printer;
        bool newblock = true;
        for (Seq<RetiredEntry*>* p = live.retired.get(); p != NULL; p = p->tail) {
            RetiredEntry* e = p->head;
            InsBuf ib;
            RefBuf rb;
            char livebuf[4000], *s=livebuf;
            *s = 0;
            if (!newblock && e->i->isop(LIR_label)) {
                logc->printf("\n");
            }
            newblock = false;
            for (Seq<LIns*>* p = e->live; p != NULL; p = p->tail) {
                VMPI_strcpy(s, printer->formatRef(&rb, p->head));
                s += VMPI_strlen(s);
                *s++ = ' '; *s = 0;
                NanoAssert(s < livebuf+sizeof(livebuf));
            }
            /* If the LIR insn is pretty short, print it and its
               live-after set on the same line.  If not, put
               live-after set on a new line, suitably indented. */
            const char* insn_text = printer->formatIns(&ib, e->i);
            if (VMPI_strlen(insn_text) >= 30-2) {
                logc->printf("  %-30s\n  %-30s %s\n", insn_text, "", livebuf);
            } else {
                logc->printf("  %-30s %s\n", insn_text, livebuf);
            }

            if (e->i->isGuard() || e->i->isBranch() || e->i->isRet()) {
                logc->printf("\n");
                newblock = true;
            }
        }
    }

    void LirNameMap::addNameWithSuffix(LIns* ins, const char *name, int suffix,
                                       bool ignoreOneSuffix) {
        NanoAssert(!names.containsKey(ins));
        const int N = 100;
        char name2[N];
        if (suffix == 1 && ignoreOneSuffix) {
            VMPI_snprintf(name2, N, "%s", name);                // don't add '1' suffix
        } else if (VMPI_isdigit(name[VMPI_strlen(name)-1])) {
            VMPI_snprintf(name2, N, "%s_%d", name, suffix);     // use '_' to avoid confusion
        } else {
            VMPI_snprintf(name2, N, "%s%d", name, suffix);      // normal case
        }

        char *copy = new (alloc) char[VMPI_strlen(name2)+1];
        VMPI_strcpy(copy, name2);
        Entry *e = new (alloc) Entry(copy);
        names.put(ins, e);
    }

    void LirNameMap::addName(LIns* ins, const char* name) {
        // The lookup may succeed, ie. we may already have a name for this
        // instruction.  This can happen because of CSE.  Eg. if we have this:
        //
        //   ins = addName("foo", insImmI(0))
        //
        // that assigns the name "foo1" to 'ins'.  If we later do this:
        //
        //   ins2 = addName("foo", insImmI(0))
        //
        // then CSE will cause 'ins' and 'ins2' to be equal.  So 'ins2'
        // already has a name ("foo1") and there's no need to generate a new
        // name "foo2".
        //
        if (!names.containsKey(ins)) {
            Str* str = new (alloc) Str(alloc, name);
            int suffix = namecounts.add(*str);
            addNameWithSuffix(ins, name, suffix, /*ignoreOneSuffix*/true);
        }
    }

    const char* LirNameMap::createName(LIns* ins) {
        if (ins->isCall()) {
#if NJ_SOFTFLOAT_SUPPORTED
            if (ins->isop(LIR_hcalli)) {
                ins = ins->oprnd1();    // we've presumably seen the other half already
            } else
#endif
            {
                if (!names.containsKey(ins))
                    addNameWithSuffix(ins, ins->callInfo()->_name, funccounts.add(ins->callInfo()),
                                      /*ignoreOneSuffix*/false);
            }
        } else {
            if (!names.containsKey(ins))
                addNameWithSuffix(ins, lirNames[ins->opcode()], lircounts.add(ins->opcode()),
                                  /*ignoreOneSuffix*/false);

        }
        return names.get(ins)->name;
    }

    const char* LirNameMap::lookupName(LIns* ins)
    {
        Entry* e = names.get(ins);
        return e ? e->name : NULL;
    }

    char* LInsPrinter::formatAccSet(RefBuf* buf, AccSet accSet) {
        if (accSet == ACCSET_NONE) {
            VMPI_sprintf(buf->buf, ".none");
        } else if (accSet == ACCSET_ALL) {
            VMPI_sprintf(buf->buf, ".all");
        } else {
            char* b = buf->buf;
            b[0] = 0;
            // The AccSet may contain bits set for regions not used by the
            // embedding, if any have been specified via
            // (ACCSET_ALL & ~ACCSET_XYZ).  So only print those that are
            // relevant.
            for (int i = 0; i < EMB_NUM_USED_ACCS; i++) {
                if (accSet & (1 << i)) {
                    VMPI_strcat(b, ".");
                    VMPI_strcat(b, accNames[i]);
                    accSet &= ~(1 << i);
                }
            }
            NanoAssert(VMPI_strlen(b) < buf->len);
        }
        return buf->buf;
    }

    char* LInsPrinter::formatImmI(RefBuf* buf, int32_t c) {
        if (-10000 < c && c < 10000) {
            VMPI_snprintf(buf->buf, buf->len, "%d", c);
        } else {
#if !defined NANOJIT_64BIT
            formatAddr(buf, (void*)c);
#else
            VMPI_snprintf(buf->buf, buf->len, "0x%x", (unsigned int)c);
#endif
        }
        return buf->buf;
    }

#if defined NANOJIT_64BIT
    char* LInsPrinter::formatImmQ(RefBuf* buf, uint64_t c) {
        if (-10000 < (int64_t)c && c < 10000) {
            VMPI_snprintf(buf->buf, buf->len, "%dLL", (int)c);
        } else {
            formatAddr(buf, (void*)c);
        }
        return buf->buf;
    }
#endif

    char* LInsPrinter::formatImmD(RefBuf* buf, double c) {
        VMPI_snprintf(buf->buf, buf->len, "%g", c);
        return buf->buf;
    }

    char* LInsPrinter::formatAddr(RefBuf* buf, void* p)
    {
        char*   name;
        int32_t offset;
        addrNameMap->lookupAddr(p, name, offset);

        if (name) {
            if (offset != 0) {
                VMPI_snprintf(buf->buf, buf->len, "%p %s+%d", p, name, offset);
            } else {
                VMPI_snprintf(buf->buf, buf->len, "%p %s", p, name);
            }
        } else {
            VMPI_snprintf(buf->buf, buf->len, "%p", p);
        }

        return buf->buf;
    }

    char* LInsPrinter::formatRef(RefBuf* buf, LIns *ref, bool showImmValue)
    {
        // Give 'ref' a name if it doesn't have one.
        const char* name = lirNameMap->lookupName(ref);
        if (!name) {
            name = lirNameMap->createName(ref);
        }

        // Put it in the buffer.  If it's an immediate, show the value if
        // showImmValue==true.  (This facility allows us to print immediate
        // values when they're used but not when they're def'd, ie. we don't
        // want "immi1/*1*/ = immi 1".)
        RefBuf buf2;
        if (ref->isImmI() && showImmValue) {
            VMPI_snprintf(buf->buf, buf->len, "%s/*%s*/", name, formatImmI(&buf2, ref->immI()));
        }
#ifdef NANOJIT_64BIT
        else if (ref->isImmQ() && showImmValue) {
            VMPI_snprintf(buf->buf, buf->len, "%s/*%s*/", name, formatImmQ(&buf2, ref->immQ()));
        }
#endif
        else if (ref->isImmD() && showImmValue) {
            VMPI_snprintf(buf->buf, buf->len, "%s/*%s*/", name, formatImmD(&buf2, ref->immD()));
        } 
        else if (ref->isImmF() && showImmValue) { // float is printed as a double
            VMPI_snprintf(buf->buf, buf->len, "%s/*%s*/", name, formatImmD(&buf2, ref->immF()));
        }
        else if (ref->isImmF4() && showImmValue) { // float4 is printed as an array of 4 double values
            RefBuf bufx, bufy, bufz, bufw;
            float4_t v = ref->immF4();
            VMPI_snprintf(buf->buf, buf->len, "%s/*%s,%s,%s,%s*/", name, formatImmD(&bufx,f4_x(v)),
                          formatImmD(&bufy,f4_y(v)), formatImmD(&bufz,f4_z(v)), formatImmD(&bufw,f4_w(v)));
        }
        else {
            VMPI_snprintf(buf->buf, buf->len, "%s", name);
        }

        return buf->buf;
    }

    char* LInsPrinter::formatIns(InsBuf* buf, LIns* i)
    {
        char *s = buf->buf;
        size_t n = buf->len;
        RefBuf b1, b2, b3, b4, b5;
        LOpcode op = i->opcode();
        switch (op)
        {
            case LIR_immi:
                VMPI_snprintf(s, n, "%s = %s %s", formatRef(&b1, i, /*showImmValue*/false),
                              lirNames[op], formatImmI(&b2, i->immI()));
                break;

#ifdef NANOJIT_64BIT
            case LIR_immq:
                VMPI_snprintf(s, n, "%s = %s %s", formatRef(&b1, i, /*showImmValue*/false),
                              lirNames[op], formatImmQ(&b2, i->immQ()));
                break;
#endif

            case LIR_immf:
                VMPI_snprintf(s, n, "%s = %s %s", formatRef(&b1, i, /*showImmValue*/false),
                              lirNames[op], formatImmD(&b2, i->immF()));
                break;

            case LIR_immf4:{
                RefBuf b5;
                float4_t v = i->immF4();
                VMPI_snprintf(s, n, "%s = %s %s,%s,%s,%s", formatRef(&b1, i, /*showImmValue*/false),
                    lirNames[op], formatImmD(&b2, f4_x(v)), formatImmD(&b3, f4_y(v)), formatImmD(&b4, f4_z(v)), formatImmD(&b5, f4_w(v)));
                break;
            }

            case LIR_immd:
                VMPI_snprintf(s, n, "%s = %s %s", formatRef(&b1, i, /*showImmValue*/false),
                    lirNames[op], formatImmD(&b2, i->immD()));
                break;
                
            case LIR_allocp:
                VMPI_snprintf(s, n, "%s = %s %d", formatRef(&b1, i), lirNames[op], i->size());
                break;

            case LIR_start:
            case LIR_regfence:
	        case LIR_pushstate:
	        case LIR_popstate:
            case LIR_memfence:
            case LIR_restorepc:
                VMPI_snprintf(s, n, "%s", lirNames[op]);
                break;

            case LIR_callv:
            case LIR_calli:
            CASE64(LIR_callq:)
            case LIR_calld: 
            case LIR_callf:
            case LIR_callf4:
            {
                const CallInfo* call = i->callInfo();
                int32_t argc = i->argc();
                int32_t m = int32_t(n);     // Windows doesn't have 'ssize_t'
                if (call->isIndirect())
                    m -= VMPI_snprintf(s, m, "%s = %s%s [%s] ( ", formatRef(&b1, i), lirNames[op],
                                       formatAccSet(&b2, call->_storeAccSet),
                                       formatRef(&b3, i->arg(--argc)));
                else
                    m -= VMPI_snprintf(s, m, "%s = %s%s #%s ( ", formatRef(&b1, i), lirNames[op],
                                       formatAccSet(&b2, call->_storeAccSet), call->_name);
                if (m < 0) break;
                for (int32_t j = argc - 1; j >= 0; j--) {
                    s += VMPI_strlen(s);
                    m -= VMPI_snprintf(s, m, "%s ",formatRef(&b2, i->arg(j)));
                    if (m < 0) break;
                }
                s += VMPI_strlen(s);
                m -= VMPI_snprintf(s, m, ")");
                break;
            }

            case LIR_jtbl: {
                int32_t m = int32_t(n);     // Windows doesn't have 'ssize_t'
                m -= VMPI_snprintf(s, m, "%s %s [ ", lirNames[op], formatRef(&b1, i->oprnd1()));
                if (m < 0) break;
                for (uint32_t j = 0, sz = i->getTableSize(); j < sz; j++) {
                    LIns* target = i->getTarget(j);
                    s += VMPI_strlen(s);
                    m -= VMPI_snprintf(s, m, "%s ", target ? formatRef(&b2, target) : "unpatched");
                    if (m < 0) break;
                }
                s += VMPI_strlen(s);
                m -= VMPI_snprintf(s, m, "]");
                break;
            }

            case LIR_paramp: {
                uint32_t arg = i->paramArg();
                if (!i->paramKind()) {
                    if (arg < sizeof(RegAlloc::argRegs)/sizeof(RegAlloc::argRegs[0])) {
                        VMPI_snprintf(s, n, "%s = %s %d %s", formatRef(&b1, i), lirNames[op],
                            arg, gpn(RegAlloc::argRegs[arg]));
                    } else {
                        VMPI_snprintf(s, n, "%s = %s %d", formatRef(&b1, i), lirNames[op], arg);
                    }
                } else {
                    VMPI_snprintf(s, n, "%s = %s %d %s", formatRef(&b1, i), lirNames[op],
                        arg, gpn(RegAlloc::savedRegs[arg]));
                }
                break;
            }

            case LIR_label:
                VMPI_snprintf(s, n, "%s:", formatRef(&b1, i));
                break;

            case LIR_jt:
            case LIR_jf:
			case LIR_brsavpc:
                VMPI_snprintf(s, n, "%s %s -> %s", lirNames[op], formatRef(&b1, i->oprnd1()),
                    i->oprnd2() ? formatRef(&b2, i->oprnd2()) : "unpatched");
                break;

            case LIR_j:
                VMPI_snprintf(s, n, "%s -> %s", lirNames[op],
                    i->oprnd2() ? formatRef(&b1, i->oprnd2()) : "unpatched");
                break;

            case LIR_livei:
            case LIR_lived:
            case LIR_livef:
            case LIR_livef4:
            CASE64(LIR_liveq:)
            case LIR_reti:
            CASE64(LIR_retq:)
            case LIR_retd:
            case LIR_retf:
            case LIR_retf4:
                VMPI_snprintf(s, n, "%s %s", lirNames[op], formatRef(&b1, i->oprnd1()));
                break;

            CASESF(LIR_hcalli:)
            case LIR_negi:
            case LIR_negd:
            case LIR_negf:
            case LIR_negf4:
            case LIR_absd:
            case LIR_absf:
            case LIR_absf4:
            case LIR_sqrtd:
            case LIR_sqrtf:
            case LIR_sqrtf4:
            case LIR_rsqrtf:
            case LIR_rsqrtf4:
            case LIR_recipf:
            case LIR_recipf4:
            case LIR_i2d:
            CASE64(LIR_q2d:)
            case LIR_ui2d:
            case LIR_i2f:
            case LIR_ui2f:
            case LIR_f4x:
            case LIR_f4y:
            case LIR_f4z:
            case LIR_f4w:
            case LIR_f2f4:
            CASESF(LIR_dlo2i:)
            CASESF(LIR_dhi2i:)
            case LIR_noti:
            CASE86(LIR_modi:)
            CASE64(LIR_i2q:)
            CASE64(LIR_ui2uq:)
            CASE64(LIR_q2i:)
            case LIR_d2i:
            case LIR_d2f:
            case LIR_f2d:
            case LIR_f2i:
            CASE64(LIR_dasq:)
            CASE64(LIR_qasd:)
                VMPI_snprintf(s, n, "%s = %s %s", formatRef(&b1, i), lirNames[op],
                             formatRef(&b2, i->oprnd1()));
                break;

            case LIR_x:
            case LIR_xt:
            case LIR_xf:
            case LIR_xbarrier:
                formatGuard(buf, i);
                break;

            case LIR_addxovi:
            case LIR_subxovi:
            case LIR_mulxovi:
                formatGuardXov(buf, i);
                break;

            case LIR_addjovi:
            case LIR_subjovi:
            case LIR_muljovi:
            CASE64(LIR_addjovq:)
            CASE64(LIR_subjovq:)
                VMPI_snprintf(s, n, "%s = %s %s, %s ; ovf -> %s", formatRef(&b1, i), lirNames[op],
                    formatRef(&b2, i->oprnd1()),
                    formatRef(&b3, i->oprnd2()),
                    i->oprnd3() ? formatRef(&b4, i->oprnd3()) : "unpatched");
                break;

            case LIR_addi:       CASE64(LIR_addq:)
            case LIR_subi:       CASE64(LIR_subq:)
            case LIR_muli:
            CASE86(LIR_divi:)
            case LIR_addd:
            case LIR_subd:
            case LIR_muld:
            case LIR_divd:
            case LIR_addf:
            case LIR_subf:
            case LIR_mulf:
            case LIR_divf:
            case LIR_addf4:
            case LIR_subf4:
            case LIR_mulf4:
            case LIR_divf4:
            case LIR_dotf4:
            case LIR_dotf3:
            case LIR_dotf2:
            case LIR_minf4:
            case LIR_maxf4:
            case LIR_cmpgtf4:
            case LIR_cmpgef4:
            case LIR_cmpltf4:
            case LIR_cmplef4:
            case LIR_cmpeqf4:
            case LIR_cmpnef4:
            case LIR_andi:       CASE64(LIR_andq:)
            case LIR_ori:        CASE64(LIR_orq:)
            case LIR_xori:       CASE64(LIR_xorq:)
            case LIR_lshi:       CASE64(LIR_lshq:)
            case LIR_rshi:       CASE64(LIR_rshq:)
            case LIR_rshui:      CASE64(LIR_rshuq:)
            case LIR_eqi:        CASE64(LIR_eqq:)
            case LIR_lti:        CASE64(LIR_ltq:)
            case LIR_lei:        CASE64(LIR_leq:)
            case LIR_gti:        CASE64(LIR_gtq:)
            case LIR_gei:        CASE64(LIR_geq:)
            case LIR_ltui:       CASE64(LIR_ltuq:)
            case LIR_leui:       CASE64(LIR_leuq:)
            case LIR_gtui:       CASE64(LIR_gtuq:)
            case LIR_geui:       CASE64(LIR_geuq:)
            case LIR_eqd:
            case LIR_ltd:
            case LIR_led:
            case LIR_gtd:
            case LIR_ged:
            case LIR_eqf4:
            case LIR_eqf:
            case LIR_ltf:
            case LIR_lef:
            case LIR_gtf:
            case LIR_gef:
#if NJ_SOFTFLOAT_SUPPORTED
            case LIR_ii2d:
#endif
                VMPI_snprintf(s, n, "%s = %s %s, %s", formatRef(&b1, i), lirNames[op],
                    formatRef(&b2, i->oprnd1()),
                    formatRef(&b3, i->oprnd2()));
                break;

            CASE64(LIR_cmovq:)
            case LIR_cmovi:
            case LIR_cmovd:
            case LIR_cmovf:
            case LIR_cmovf4:
                VMPI_snprintf(s, n, "%s = %s %s ? %s : %s", formatRef(&b1, i), lirNames[op],
                    formatRef(&b2, i->oprnd1()),
                    formatRef(&b3, i->oprnd2()),
                    formatRef(&b4, i->oprnd3()));
                break;

            case LIR_ffff2f4:
                VMPI_snprintf(s, n, "%s =(%s)= %s %s %s %s", formatRef(&b1, i), lirNames[op],
                              formatRef(&b2, i->oprnd1()),
                              formatRef(&b3, i->oprnd2()),
                              formatRef(&b4, i->oprnd3()),
                              formatRef(&b5, i->oprnd4()));
                break;
                
            case LIR_ldi:
            CASE64(LIR_ldq:)
            case LIR_ldd:
            case LIR_ldf:
            case LIR_ldf4:
            case LIR_lduc2ui:
            case LIR_ldus2ui:
            case LIR_ldc2i:
            case LIR_lds2i:
            case LIR_ldf2d: {
                const char* qualStr;
                switch (i->loadQual()) {
                case LOAD_CONST:        qualStr = "/c"; break;
                case LOAD_NORMAL:       qualStr = "";   break;
                case LOAD_VOLATILE:     qualStr = "/v"; break;
                default: NanoAssert(0); qualStr = "/?"; break;
                }
                VMPI_snprintf(s, n, "%s = %s%s%s %s[%d]", formatRef(&b1, i), lirNames[op],
                    formatAccSet(&b2, i->accSet()), qualStr, formatRef(&b3, i->oprnd1()),
                    i->disp());
                break;
            }

            case LIR_sti:
            CASE64(LIR_stq:)
            case LIR_std:
            case LIR_stf:
            case LIR_stf4:
            case LIR_sti2c:
            case LIR_sti2s:
            case LIR_std2f:
                VMPI_snprintf(s, n, "%s%s %s[%d] = %s", lirNames[op],
                    formatAccSet(&b1, i->accSet()),
                    formatRef(&b2, i->oprnd2()),
                    i->disp(),
                    formatRef(&b3, i->oprnd1()));
                break;

            case LIR_comment:
                VMPI_snprintf(s, n, "------------------------------ # %s", (char*)i->oprnd1());
                break;

            case LIR_swzf4:
                VMPI_snprintf(s, n, "%s %s, %d|%d|%d|%d", lirNames[LIR_swzf4],
                              formatRef(&b1, i->oprnd1()),
                              i->mask() >> 0 & 3,
                              i->mask() >> 2 & 3,
                              i->mask() >> 4 & 3,
                              i->mask() >> 6 & 3);
                break;

            case LIR_safe:
            case LIR_endsafe:
                VMPI_snprintf(s, n, "%s", (char*)lirNames[op]);
                break;

            default:
                NanoAssertMsgf(0, "Can't handle opcode %s\n", lirNames[op]);
                break;
        }
        return buf->buf;
    }
#endif

    CseFilter::CseFilter(LirWriter *out, uint8_t embNumUsedAccs, Allocator& alloc)
        : LirWriter(out),
          EMB_NUM_USED_ACCS(embNumUsedAccs),
          CSE_NUM_USED_ACCS(EMB_NUM_USED_ACCS + 2),
          CSE_ACC_CONST(    EMB_NUM_USED_ACCS + 0),
          CSE_ACC_MULTIPLE( EMB_NUM_USED_ACCS + 1),
          storesSinceLastLoad(ACCSET_NONE),
          alloc(alloc),
          knownCmpValues(alloc),
          suspended(0),
          initOOM(false)
    {
        m_findNL[NLImmISmall] = &CseFilter::findImmISmall;
        m_findNL[NLImmILarge] = &CseFilter::findImmILarge;
        m_findNL[NLImmF]      = &CseFilter::findImmF;
        m_findNL[NLImmQ]      = PTR_SIZE(NULL, &CseFilter::findImmQ);
        m_findNL[NLImmD]      = &CseFilter::findImmD;
        m_findNL[NL1]         = &CseFilter::find1;
        m_findNL[NL2]         = &CseFilter::find2;
        m_findNL[NL3]         = &CseFilter::find3;
        m_findNL[NL4]         = &CseFilter::find4;
        m_findNL[NLCall]      = &CseFilter::findCall;
        m_findNL[NLImmF4]     = &CseFilter::findImmF4;

        m_capNL[NLImmISmall]  = 17;   // covers 0..16, which is over half the cases for TraceMonkey
        m_capNL[NLImmILarge]  = 64;
        m_capNL[NLImmF]       = 16;
        m_capNL[NLImmQ]       = PTR_SIZE(0, 16);
        m_capNL[NLImmD]       = 16;
        m_capNL[NL1]          = 256;
        m_capNL[NL2]          = 512;
        m_capNL[NL3]          = 16;
        m_capNL[NL4]          = 16;
        m_capNL[NLCall]       = 64;
        m_capNL[NLImmF4]      = 16; 

        // The largish allocations are fallible, the small ones are
        // infallible.  See the comment on initOOM's declaration for why.

        for (NLKind nlkind = NLFirst; nlkind <= NLLast; nlkind = nextNLKind(nlkind)) {
            m_listNL[nlkind] = (LIns**)alloc.fallibleAlloc(sizeof(LIns*) * m_capNL[nlkind]);
            if (!m_listNL[nlkind]) {
                initOOM = true;
                return;
            }
            m_usedNL[nlkind] = 1; // Force memset in clearAll().
        }

        // Note that this allocates the CONST and MULTIPLE tables as well.
        for (CseAcc a = 0; a < CSE_NUM_USED_ACCS; a++) {
            m_capL[a] = 16;
            m_listL[a] = (LIns**)alloc.fallibleAlloc(sizeof(LIns*) * m_capL[a]);
            if (!m_listL[a]) {
                initOOM = true;
                return;
            }
            m_usedL[a] = 1; // Force memset(0) in first clearAll().
        }

        clearAll();
    }

    // Inlined/separated version of SuperFastHash.
    // This content is copyrighted by Paul Hsieh.
    // For reference see: http://www.azillionmonkeys.com/qed/hash.html
    //
    inline uint32_t CseFilter::hash8(uint32_t hash, const uint8_t data)
    {
        hash += data;
        hash ^= hash << 10;
        hash += hash >> 1;
        return hash;
    }

    inline uint32_t CseFilter::hash32(uint32_t hash, const uint32_t data)
    {
        const uint32_t dlo = data & 0xffff;
        const uint32_t dhi = data >> 16;
        hash += dlo;
        const uint32_t tmp = (dhi << 11) ^ hash;
        hash = (hash << 16) ^ tmp;
        hash += hash >> 11;
        return hash;
    }

    inline uint32_t CseFilter::hashptr(uint32_t hash, const void* data)
    {
#ifdef NANOJIT_64BIT
        hash = hash32(hash, uint32_t(uintptr_t(data) >> 32));
        hash = hash32(hash, uint32_t(uintptr_t(data)));
        return hash;
#else
        return hash32(hash, uint32_t(data));
#endif
    }

    inline uint32_t CseFilter::hashfinish(uint32_t hash)
    {
        /* Force "avalanching" of final 127 bits */
        hash ^= hash << 3;
        hash += hash >> 5;
        hash ^= hash << 4;
        hash += hash >> 17;
        hash ^= hash << 25;
        hash += hash >> 6;
        return hash;
    }

    void CseFilter::clearNL(NLKind nlkind) {
        if (m_usedNL[nlkind] > 0) {
            VMPI_memset(m_listNL[nlkind], 0, sizeof(LIns*)*m_capNL[nlkind]);
            m_usedNL[nlkind] = 0;
        }
    }

    void CseFilter::clearL(CseAcc a) {
        if (m_usedL[a] > 0) {
            VMPI_memset(m_listL[a], 0, sizeof(LIns*)*m_capL[a]);
            m_usedL[a] = 0;
        }
    }

    void CseFilter::clearAll() {
        for (NLKind nlkind = NLFirst; nlkind <= NLLast; nlkind = nextNLKind(nlkind))
            clearNL(nlkind);

        // Note that this clears the CONST and MULTIPLE load tables as well.
        for (CseAcc a = 0; a < CSE_NUM_USED_ACCS; a++)
            clearL(a);

        knownCmpValues.clear();
    }

    inline uint32_t CseFilter::hashImmI(int32_t a) {
        return hashfinish(hash32(0, a));
    }

    inline uint32_t CseFilter::hashImmF4(const float4_t& a) {
        const uint32_t* up = reinterpret_cast<const uint32_t*>(&a);

        uint32_t hash = hash32(0, up[0]);
                 hash = hash32(hash,up[1]);
                 hash = hash32(hash,up[2]);
                 hash = hash32(hash,up[3]);

        return hashfinish(hash);
    }

    inline uint32_t CseFilter::hashImmQorD(uint64_t a) {
        uint32_t hash = hash32(0, uint32_t(a >> 32));
        return hashfinish(hash32(hash, uint32_t(a)));
    }

    inline uint32_t CseFilter::hash1(LOpcode op, LIns* a) {
        uint32_t hash = hash8(0, uint8_t(op));
        return hashfinish(hashptr(hash, a));
    }

    inline uint32_t CseFilter::hash2(LOpcode op, LIns* a, LIns* b) {
        uint32_t hash = hash8(0, uint8_t(op));
        hash = hashptr(hash, a);
        return hashfinish(hashptr(hash, b));
    }

    inline uint32_t CseFilter::hash3(LOpcode op, LIns* a, LIns* b, LIns* c) {
        uint32_t hash = hash8(0, uint8_t(op));
        hash = hashptr(hash, a);
        hash = hashptr(hash, b);
        return hashfinish(hashptr(hash, c));
    }

    inline uint32_t CseFilter::hash4(LOpcode op, LIns* a, LIns* b, LIns* c, LIns* d) {
        uint32_t hash = hash8(0, uint8_t(op));
        hash = hashptr(hash, a);
        hash = hashptr(hash, b);
        hash = hashptr(hash, c);
        return hashfinish(hashptr(hash, d));
    }
    
    // Nb: no need to hash the load's MiniAccSet because each every load goes
    // into a table where all the loads have the same MiniAccSet.
    inline uint32_t CseFilter::hashLoad(LOpcode op, LIns* a, int32_t d) {
        uint32_t hash = hash8(0, uint8_t(op));
        hash = hashptr(hash, a);
        return hashfinish(hash32(hash, d));
    }

    inline uint32_t CseFilter::hashCall(const CallInfo *ci, uint32_t argc, LIns* args[]) {
        uint32_t hash = hashptr(0, ci);
        for (int32_t j=argc-1; j >= 0; j--)
            hash = hashptr(hash,args[j]);
        return hashfinish(hash);
    }

    bool CseFilter::growNL(NLKind nlkind)
    {
        NanoAssert(nlkind != NLImmISmall);
        const uint32_t oldcap = m_capNL[nlkind];
        m_capNL[nlkind] <<= 1;
        // We make this allocation fallible because it's potentially large and
        // easy to recover from.  If it fails, we won't add any more
        // instructions to the table and some CSE opportunities may be missed.
        LIns** tmp = (LIns**)alloc.fallibleAlloc(sizeof(LIns*) * m_capNL[nlkind]);
        if (tmp) {
            LIns** oldlist = m_listNL[nlkind];
            m_listNL[nlkind] = tmp;
            VMPI_memset(m_listNL[nlkind], 0, m_capNL[nlkind] * sizeof(LIns*));
            find_t find = m_findNL[nlkind];
            for (uint32_t i = 0; i < oldcap; i++) {
                LIns* ins = oldlist[i];
                if (!ins) continue;
                uint32_t j = (this->*find)(ins);
                NanoAssert(!m_listNL[nlkind][j]);
                m_listNL[nlkind][j] = ins;
            }
            return true;
        } else {
            m_capNL[nlkind] = oldcap;
            return false;
        }
    }

    bool CseFilter::growL(CseAcc cseAcc)
    {
        const uint32_t oldcap = m_capL[cseAcc];
        m_capL[cseAcc] <<= 1;
        LIns** tmp = (LIns**)alloc.fallibleAlloc(sizeof(LIns*) * m_capL[cseAcc]);
        if (tmp) {
            LIns** oldlist = m_listL[cseAcc];
            m_listL[cseAcc] = tmp;
            VMPI_memset(m_listL[cseAcc], 0, m_capL[cseAcc] * sizeof(LIns*));
            find_t find = &CseFilter::findLoad;
            for (uint32_t i = 0; i < oldcap; i++) {
                LIns* ins = oldlist[i];
                if (!ins) continue;
                uint32_t j = (this->*find)(ins);
                NanoAssert(!m_listL[cseAcc][j]);
                m_listL[cseAcc][j] = ins;
            }
            return true;
        } else {
            m_capL[cseAcc] = oldcap;
            return false;
        }
    }

    void CseFilter::addNLImmISmall(LIns* ins, uint32_t k)
    {
        NanoAssert(!initOOM);
        if (suspended) return;
        NLKind nlkind = NLImmISmall;
        NanoAssert(k < m_capNL[nlkind]);
        NanoAssert(!m_listNL[nlkind][k]);
        m_usedNL[nlkind]++;
        m_listNL[nlkind][k] = ins;
    }

    void CseFilter::addNL(NLKind nlkind, LIns* ins, uint32_t k)
    {
        NanoAssert(!initOOM);
        if (suspended) return;
        NanoAssert(!m_listNL[nlkind][k]);
        m_usedNL[nlkind]++;
        m_listNL[nlkind][k] = ins;
        if ((m_usedNL[nlkind] * 4) >= (m_capNL[nlkind] * 3)) {  // load factor of 0.75
            bool ok = growNL(nlkind);
            if (!ok) {
                // OOM: undo the insertion.
                m_usedNL[nlkind]--;
                m_listNL[nlkind][k] = NULL;
            }
        }
    }

    void CseFilter::addL(LIns* ins, uint32_t k)
    {
        NanoAssert(!initOOM);
        if (suspended) return;
        CseAcc cseAcc = miniAccSetToCseAcc(ins->miniAccSet(), ins->loadQual());
        NanoAssert(!m_listL[cseAcc][k]);
        m_usedL[cseAcc]++;
        m_listL[cseAcc][k] = ins;
        if ((m_usedL[cseAcc] * 4) >= (m_capL[cseAcc] * 3)) {  // load factor of 0.75
            bool ok = growL(cseAcc);
            if (!ok) {
                // OOM: undo the insertion.
                m_usedL[cseAcc]--;
                m_listL[cseAcc][k] = NULL;
            }
        }
    }

    inline LIns* CseFilter::findImmISmall(int32_t a, uint32_t &k)
    {
        // This one is a direct array lookup rather than a hashtable lookup.
        NLKind nlkind = NLImmISmall;
        k = a;
        LIns* ins = m_listNL[nlkind][k];
        NanoAssert(!ins || ins->isImmI(a));
        return ins;
    }

    uint32_t CseFilter::findImmISmall(LIns* ins)
    {
        uint32_t k;
        findImmISmall(ins->immI(), k);
        return k;
    }

    inline LIns* CseFilter::findImmILarge(int32_t a, uint32_t &k)
    {
        NLKind nlkind = NLImmILarge;
        const uint32_t bitmask = m_capNL[nlkind] - 1;
        k = hashImmI(a) & bitmask;
        uint32_t n = 1;
        while (true) {
            LIns* ins = m_listNL[nlkind][k];
            if (!ins)
                return NULL;
            NanoAssert(ins->isImmI());
            if (ins->immI() == a)
                return ins;
            // Quadratic probe:  h(k,i) = h(k) + 0.5i + 0.5i^2, which gives the
            // sequence h(k), h(k)+1, h(k)+3, h(k)+6, h+10, ...  This is a
            // good sequence for 2^n-sized tables as the values h(k,i) for i
            // in [0,m - 1] are all distinct so termination is guaranteed.
            // See http://portal.acm.org/citation.cfm?id=360737 and
            // http://en.wikipedia.org/wiki/Quadratic_probing (fetched
            // 06-Nov-2009) for more details.
            k = (k + n) & bitmask;
            n += 1;
        }
    }

    uint32_t CseFilter::findImmILarge(LIns* ins)
    {
        uint32_t k;
        findImmILarge(ins->immI(), k);
        return k;
    }

#ifdef NANOJIT_64BIT
    inline LIns* CseFilter::findImmQ(uint64_t a, uint32_t &k)
    {
        NLKind nlkind = NLImmQ;
        const uint32_t bitmask = m_capNL[nlkind] - 1;
        k = hashImmQorD(a) & bitmask;
        uint32_t n = 1;
        while (true) {
            LIns* ins = m_listNL[nlkind][k];
            if (!ins)
                return NULL;
            NanoAssert(ins->isImmQ());
            if (ins->immQ() == a)
                return ins;
            k = (k + n) & bitmask;
            n += 1;
        }
    }

    uint32_t CseFilter::findImmQ(LIns* ins)
    {
        uint32_t k;
        findImmQ(ins->immQ(), k);
        return k;
    }
#endif

    inline LIns* CseFilter::findImmD(uint64_t a, uint32_t &k)
    {
        NLKind nlkind = NLImmD;
        const uint32_t bitmask = m_capNL[nlkind] - 1;
        k = hashImmQorD(a) & bitmask;
        uint32_t n = 1;
        while (true) {
            LIns* ins = m_listNL[nlkind][k];
            if (!ins)
                return NULL;
            NanoAssert(ins->isImmD());
            if (ins->immDasQ() == a)
                return ins;
            k = (k + n) & bitmask;
            n += 1;
        }
    }

    uint32_t CseFilter::findImmD(LIns* ins)
    {
        // Use bitwise (integer) comparison.
        uint32_t k;
        findImmD(ins->immDasQ(), k);
        return k;
    }

    inline LIns* CseFilter::findImmF(int32_t a, uint32_t &k)
    {
        NLKind nlkind = NLImmF;
        const uint32_t bitmask = m_capNL[nlkind] - 1;
        uint32_t n = 1;

        k = hashImmI(a) & bitmask;
        while (true) {
            LIns* ins = m_listNL[nlkind][k];
            if (!ins)
                return NULL;
            NanoAssert(ins->isImmF());
            if (ins->immFasI() == a)
                return ins;
            k = (k + n) & bitmask;
            n += 1;
        }
    }

    uint32_t CseFilter::findImmF(LIns* ins)
    {
        NanoAssert(ins->isImmF());

        // Use bitwise (integer) comparison.
        uint32_t k;
        findImmF(ins->immFasI(), k);
        return k;
    }
    
    inline LIns* CseFilter::findImmF4(const float4_t& a, uint32_t &k)
    {
        NLKind nlkind = NLImmF4;
        const uint32_t bitmask = m_capNL[nlkind] - 1;
        uint32_t n = 1;

        k = hashImmF4(a) & bitmask;
        while (true) {
            LIns* ins = m_listNL[nlkind][k];
            if (!ins)
                return NULL;
            NanoAssert(ins->isImmF4());
            float4_t b = ins->immF4();
            // Use bitwise comparison, as we do for floats and doubles.
            if (VMPI_memcmp(&a, &b, sizeof(float4_t))==0)
                return ins;
            k = (k + n) & bitmask;
            n += 1;
        }
    }

    uint32_t CseFilter::findImmF4(LIns* ins)
    {
        NanoAssert(ins->isImmF4());

        uint32_t k;
        findImmF4(ins->immF4(), k);
        return k;
    }

    inline LIns* CseFilter::find1(LOpcode op, LIns* a, uint32_t &k)
    {
        NLKind nlkind = NL1;
        const uint32_t bitmask = m_capNL[nlkind] - 1;
        k = hash1(op, a) & bitmask;
        uint32_t n = 1;
        while (true) {
            LIns* ins = m_listNL[nlkind][k];
            if (!ins)
                return NULL;
            if (ins->isop(op) && ins->oprnd1() == a)
                return ins;
            k = (k + n) & bitmask;
            n += 1;
        }
    }

    uint32_t CseFilter::find1(LIns* ins)
    {
        uint32_t k;
        find1(ins->opcode(), ins->oprnd1(), k);
        return k;
    }

    inline LIns* CseFilter::find2(LOpcode op, LIns* a, LIns* b, uint32_t &k)
    {
        NLKind nlkind = NL2;
        const uint32_t bitmask = m_capNL[nlkind] - 1;
        k = hash2(op, a, b) & bitmask;
        uint32_t n = 1;
        while (true) {
            LIns* ins = m_listNL[nlkind][k];
            if (!ins)
                return NULL;
            if (ins->isop(op) && ins->oprnd1() == a && ins->oprnd2() == b)
                return ins;
            k = (k + n) & bitmask;
            n += 1;
        }
    }

    uint32_t CseFilter::find2(LIns* ins)
    {
        uint32_t k;
        find2(ins->opcode(), ins->oprnd1(), ins->oprnd2(), k);
        return k;
    }

    inline LIns* CseFilter::find3(LOpcode op, LIns* a, LIns* b, LIns* c, uint32_t &k)
    {
        NLKind nlkind = NL3;
        const uint32_t bitmask = m_capNL[nlkind] - 1;
        k = hash3(op, a, b, c) & bitmask;
        uint32_t n = 1;
        while (true) {
            LIns* ins = m_listNL[nlkind][k];
            if (!ins)
                return NULL;
            if (ins->isop(op) && ins->oprnd1() == a && ins->oprnd2() == b && ins->oprnd3() == c)
                return ins;
            k = (k + n) & bitmask;
            n += 1;
        }
    }

    uint32_t CseFilter::find3(LIns* ins)
    {
        uint32_t k;
        find3(ins->opcode(), ins->oprnd1(), ins->oprnd2(), ins->oprnd3(), k);
        return k;
    }

    inline LIns* CseFilter::find4(LOpcode op, LIns* a, LIns* b, LIns* c, LIns* d, uint32_t &k)
    {
        NLKind nlkind = NL4;
        const uint32_t bitmask = m_capNL[nlkind] - 1;
        k = hash4(op, a, b, c, d) & bitmask;
        uint32_t n = 1;
        while (true) {
            LIns* ins = m_listNL[nlkind][k];
            if (!ins)
                return NULL;
            if (ins->isop(op) && ins->oprnd1() == a && ins->oprnd2() == b && ins->oprnd3() == c && ins->oprnd4() == d)
                return ins;
            k = (k + n) & bitmask;
            n += 1;
        }
    }
    
    uint32_t CseFilter::find4(LIns* ins)
    {
        uint32_t k;
        find4(ins->opcode(), ins->oprnd1(), ins->oprnd2(), ins->oprnd3(), ins->oprnd4(), k);
        return k;
    }
        
    inline LIns* CseFilter::findLoad(LOpcode op, LIns* a, int32_t d, MiniAccSet miniAccSet,
                                     LoadQual loadQual, uint32_t &k)
    {
        CseAcc cseAcc = miniAccSetToCseAcc(miniAccSet, loadQual);
        const uint32_t bitmask = m_capL[cseAcc] - 1;
        k = hashLoad(op, a, d) & bitmask;
        uint32_t n = 1;
        while (true) {
            LIns* ins = m_listL[cseAcc][k];
            if (!ins)
                return NULL;
            // All the loads in this table should have the same miniAccSet and
            // loadQual.
            NanoAssert(miniAccSetToCseAcc(ins->miniAccSet(), ins->loadQual()) == cseAcc &&
                       ins->loadQual() == loadQual);
            if (ins->isop(op) && ins->oprnd1() == a && ins->disp() == d)
                return ins;
            k = (k + n) & bitmask;
            n += 1;
        }
    }

    uint32_t CseFilter::findLoad(LIns* ins)
    {
        uint32_t k;
        findLoad(ins->opcode(), ins->oprnd1(), ins->disp(), ins->miniAccSet(), ins->loadQual(), k);
        return k;
    }

    bool argsmatch(LIns* ins, uint32_t argc, LIns* args[])
    {
        for (uint32_t j=0; j < argc; j++)
            if (ins->arg(j) != args[j])
                return false;
        return true;
    }

    inline LIns* CseFilter::findCall(const CallInfo *ci, uint32_t argc, LIns* args[], uint32_t &k)
    {
        NLKind nlkind = NLCall;
        const uint32_t bitmask = m_capNL[nlkind] - 1;
        k = hashCall(ci, argc, args) & bitmask;
        uint32_t n = 1;
        while (true) {
            LIns* ins = m_listNL[nlkind][k];
            if (!ins)
                return NULL;
            if (ins->isCall() && ins->callInfo() == ci && argsmatch(ins, argc, args))
                return ins;
            k = (k + n) & bitmask;
            n += 1;
        }
    }

    uint32_t CseFilter::findCall(LIns* ins)
    {
        LIns* args[MAXARGS];
        uint32_t argc = ins->argc();
        NanoAssert(argc < MAXARGS);
        for (uint32_t j=0; j < argc; j++)
            args[j] = ins->arg(j);
        uint32_t k;
        findCall(ins->callInfo(), argc, args, k);
        return k;
    }

    LIns* CseFilter::insImmI(int32_t imm)
    {
        uint32_t k;
        LIns* ins;
        if (0 <= imm && imm < int32_t(m_capNL[NLImmISmall])) {
            ins = findImmISmall(imm, k);
            if (!ins) {
                ins = out->insImmI(imm);
                addNLImmISmall(ins, k);
            }
        } else {
            ins = findImmILarge(imm, k);
            if (!ins) {
                ins = out->insImmI(imm);
                addNL(NLImmILarge, ins, k);
            }
        }
        // We assume that downstream stages do not modify the instruction, so
        // that we can insert 'ins' into slot 'k'.  Check this.
        NanoAssert(ins->isop(LIR_immi) && ins->immI() == imm);
        return ins;
    }

    LIns* CseFilter::insSafe(LOpcode op, void *payload) {
        return out->insSafe(op, payload);
    }

#ifdef NANOJIT_64BIT
    LIns* CseFilter::insImmQ(uint64_t q)
    {
        uint32_t k;
        LIns* ins = findImmQ(q, k);
        if (!ins) {
            ins = out->insImmQ(q);
            addNL(NLImmQ, ins, k);
        }
        NanoAssert(ins->isop(LIR_immq) && ins->immQ() == q);
        return ins;
    }
#endif

    LIns* CseFilter::insImmD(double d)
    {
        uint32_t k;
        // Doubles must be compared bitwise in order to correctly
        // distinguish 0 and -0.  See bug 527288.
        union {
            double d;
            uint64_t u64;
        } u;
        u.d = d;
        LIns* ins = findImmD(u.u64, k);
        if (!ins) {
            ins = out->insImmD(d);
            addNL(NLImmD, ins, k);
        }
        NanoAssert(ins->isop(LIR_immd) && ins->immDasQ() == u.u64);
        return ins;
    }

    LIns* CseFilter::insImmF(float f)
    {
        uint32_t k;
        // Floats must be compared bitwise in order to correctly
        // distinguish 0 and -0.  Also, we wish for NaNs to compare
        // as equal, though we may in some cases distinguish different
        // NaN values unnecessarily.
        union {
            float flt;
            int32_t i;
        } u;
        u.flt = f;
        LIns* ins = findImmF(u.i, k);
        if (!ins) {
            ins = out->insImmF(f);
            addNL(NLImmF, ins, k);
        }
        NanoAssert(ins->isop(LIR_immf) && ins->immFasI() == u.i);
        return ins;
    }
    
    LIns* CseFilter::insImmF4(const float4_t& f4)
    {
        uint32_t k;
        LIns* ins = findImmF4(f4, k);
        if (!ins) {
            ins = out->insImmF4(f4);
            addNL(NLImmF4, ins, k);
        }
#ifdef DEBUG
        NanoAssert(ins->isop(LIR_immf4));
        // We must use bitwise comparision here in order
        // to correctly distinguish 0 and -0.  See also the
        // remarks for Float.
        float4_t other = ins->immF4();
        NanoAssert(VMPI_memcmp( &f4, &other, sizeof(float4_t)) == 0);
#endif
        return ins;
    }

    LIns* CseFilter::ins0(LOpcode op)
    {
        if (op == LIR_label && !suspended)
            clearAll();
        return out->ins0(op);
    }

    LIns* CseFilter::ins1(LOpcode op, LIns* a)
    {
        LIns* ins;
        if (isCseOpcode(op)) {
            uint32_t k;
            ins = find1(op, a, k);
            if (!ins) {
                ins = out->ins1(op, a);
                addNL(NL1, ins, k);
            }
        } else {
            ins = out->ins1(op, a);
        }
        NanoAssert(ins->isop(op) && ins->oprnd1() == a);
        return ins;
    }

    LIns* CseFilter::ins2(LOpcode op, LIns* a, LIns* b)
    {
        LIns* ins;
        NanoAssert(isCseOpcode(op));
        uint32_t k;
        ins = find2(op, a, b, k);
        if (!ins) {
            ins = out->ins2(op, a, b);
            addNL(NL2, ins, k);
        } else if (ins->isCmp()) {
            if (knownCmpValues.containsKey(ins)) {
                // We've seen this comparison before, and it was previously
                // used in a guard, so we know what its value must be at this
                // point.  Replace it with a constant.
                NanoAssert(ins->isCmp());
                bool cmpValue = knownCmpValues.get(ins);
                return insImmI(cmpValue ? 1 : 0);
            }
        }
        NanoAssert(ins->isop(op) && ins->oprnd1() == a && ins->oprnd2() == b);
        return ins;
    }

    LIns* CseFilter::ins3(LOpcode op, LIns* a, LIns* b, LIns* c)
    {
        NanoAssert(isCseOpcode(op));
        uint32_t k;
        LIns* ins = find3(op, a, b, c, k);
        if (!ins) {
            ins = out->ins3(op, a, b, c);
            addNL(NL3, ins, k);
        }
        NanoAssert(ins->isop(op) && ins->oprnd1() == a && ins->oprnd2() == b && ins->oprnd3() == c);
        return ins;
    }

    LIns* CseFilter::ins4(LOpcode op, LIns* a, LIns* b, LIns* c, LIns* d)
    {
        NanoAssert(isCseOpcode(op));
        uint32_t k;
        LIns* ins = find4(op, a, b, c, d, k);
        if (!ins) {
            ins = out->ins4(op, a, b, c, d);
            addNL(NL4, ins, k);
        }
        NanoAssert(ins->isop(op) && ins->oprnd1() == a && ins->oprnd2() == b && ins->oprnd3() == c && ins->oprnd4() == d);
        return ins;
    }
    
    LIns* CseFilter::insLoad(LOpcode op, LIns* base, int32_t disp, AccSet accSet, LoadQual loadQual)
    {
        LIns* ins;
        if (isS16(disp)) {
            if (storesSinceLastLoad != ACCSET_NONE) {
                // Clear all normal (excludes CONST and MULTIPLE) loads
                // aliased by stores and calls since the last time we were in
                // this function.  Aliased loads must be cleared even when CSE
                // is suspended.
                AccSet a = storesSinceLastLoad & ((1 << EMB_NUM_USED_ACCS) - 1);
                while (a) {
                    int acc = msbSet32(a);
                    clearL((CseAcc)acc);
                    a &= ~(1 << acc);
                }

                // No need to clear CONST loads (those in the CSE_ACC_CONST table).

                // Multi-region loads must be treated conservatively -- we
                // always clear all of them.
                clearL(CSE_ACC_MULTIPLE);

                storesSinceLastLoad = ACCSET_NONE;
            }

            if (loadQual == LOAD_VOLATILE) {
                // Volatile loads are never CSE'd, don't bother looking for
                // them or inserting them in the table.
                ins = out->insLoad(op, base, disp, accSet, loadQual);
            } else {
                uint32_t k;
                ins = findLoad(op, base, disp, compressAccSet(accSet), loadQual, k);
                if (!ins) {
                    ins = out->insLoad(op, base, disp, accSet, loadQual);
                    addL(ins, k);
                }
            }
            // Nb: must compare miniAccSets, not AccSets, because the AccSet
            // stored in the load may have lost info if it's multi-region.
            NanoAssert(ins->isop(op) && ins->oprnd1() == base && ins->disp() == disp &&
                       ins->miniAccSet().val == compressAccSet(accSet).val &&
                       ins->loadQual() == loadQual);
        } else {
            // If the displacement is more than 16 bits, put it in a separate
            // instruction.  Nb: LirBufWriter also does this, we do it here
            // too because CseFilter relies on LirBufWriter not changing code.
            ins = insLoad(op, ins2(LIR_addp, base, insImmWord(disp)), 0, accSet, loadQual);
        }
        return ins;
    }

    LIns* CseFilter::insStore(LOpcode op, LIns* value, LIns* base, int32_t disp, AccSet accSet)
    {
        LIns* ins;
        if (isS16(disp)) {
            storesSinceLastLoad |= accSet;
            ins = out->insStore(op, value, base, disp, accSet);
            NanoAssert(ins->isop(op) && ins->oprnd1() == value && ins->oprnd2() == base &&
                       ins->disp() == disp && ins->accSet() == accSet);
        } else {
            // If the displacement is more than 16 bits, put it in a separate
            // instruction.  Nb: LirBufWriter also does this, we do it here
            // too because CseFilter relies on LirBufWriter not changing code.
            ins = insStore(op, value, ins2(LIR_addp, base, insImmWord(disp)), 0, accSet);
        }
        return ins;
    }

    LIns* CseFilter::insGuard(LOpcode op, LIns* c, GuardRecord *gr)
    {
        // LIR_xt and LIR_xf guards are CSEable.  Note that we compare the
        // opcode and condition when determining if two guards are equivalent
        // -- in find1() and hash1() -- but we do *not* compare the
        // GuardRecord.  This works because:
        // - If guard 1 is taken (exits) then guard 2 is never reached, so
        //   guard 2 can be removed.
        // - If guard 1 is not taken then neither is guard 2, so guard 2 can
        //   be removed.
        //
        // The underlying assumptions that are required for this to be safe:
        // - There's never a path from the side exit of guard 1 back to guard
        //   2;  for tree-shaped fragments this should be true.
        // - GuardRecords do not contain information other than what is needed
        //   to execute a successful exit.  That is currently true.
        // - The CSE algorithm will always keep guard 1 and remove guard 2
        //   (not vice versa).  The current algorithm does this.
        //
        LIns* ins;
        if (isCseOpcode(op)) {
            // conditional guard
            uint32_t k;
            ins = find1(op, c, k);
            if (!ins) {
                ins = out->insGuard(op, c, gr);
                addNL(NL1, ins, k);
            }
            // After this guard, we know that 'c's result was true (if
            // op==LIR_xf) or false (if op==LIR_xt), else we would have
            // exited.  Record this fact in case 'c' occurs again.
            if (!suspended) {
                bool c_value = (op == LIR_xt ? false : true);
                knownCmpValues.put(c, c_value);
            }
        } else {
            ins = out->insGuard(op, c, gr);
        }
        NanoAssert(ins->isop(op) && ins->oprnd1() == c);
        return ins;
    }

    LIns* CseFilter::insGuardXov(LOpcode op, LIns* a, LIns* b, GuardRecord *gr)
    {
        // LIR_*xov are CSEable.  See CseFilter::insGuard() for details.
        NanoAssert(isCseOpcode(op));
        // conditional guard
        uint32_t k;
        LIns* ins = find2(op, a, b, k);
        if (!ins) {
            ins = out->insGuardXov(op, a, b, gr);
            addNL(NL2, ins, k);
        }
        NanoAssert(ins->isop(op) && ins->oprnd1() == a && ins->oprnd2() == b);
        return ins;
    }

    // There is no CseFilter::insBranchJov(), as LIR_*jov* are not CSEable.

    LIns* CseFilter::insCall(const CallInfo *ci, LIns* args[])
    {
        LIns* ins;
        uint32_t argc = ci->count_args();
        if (ci->_isPure) {
            NanoAssert(ci->_storeAccSet == ACCSET_NONE);
            uint32_t k;
            ins = findCall(ci, argc, args, k);
            if (!ins) {
                ins = out->insCall(ci, args);
                addNL(NLCall, ins, k);
            }
        } else {
            // We only need to worry about aliasing if !ci->_isPure.
            storesSinceLastLoad |= ci->_storeAccSet;
            ins = out->insCall(ci, args);
        }
        NanoAssert(ins->isCall() && ins->callInfo() == ci && argsmatch(ins, argc, args));
        NanoAssert(!ins->isInReg());
        return ins;
    }

    LIns* CseFilter::insSwz(LIns* a, uint8_t mask) {
        NanoAssert(isCseOpcode(LIR_swzf4));
        // todo: add hashtable for swizzle ops.
        return out->insSwz(a, mask);
    }

    // Interval analysis can be done much more accurately than we do here.
    // For speed and simplicity in a number of cases (eg. LIR_andi, LIR_rshi)
    // we just look for easy-to-handle (but common!) cases such as when the
    // RHS is a constant;  in practice this gives good results.  It also cuts
    // down the amount of backwards traversals we have to do, which is good.
    //
    // 'lim' also limits the number of backwards traversals;  it's decremented
    // on each recursive call and we give up when it reaches zero.  This
    // prevents possible time blow-ups in long expression chains.  We don't
    // check 'lim' at the top of this function, as you might expect, because
    // the behaviour when the limit is reached depends on the opcode.
    //
    Interval Interval::of(LIns* ins, int lim)
    {
        switch (ins->opcode()) {
        case LIR_immi: {
            int32_t i = ins->immI();
            return Interval(i, i);
        }

        case LIR_ldc2i:   return Interval(  -128,   127);
        case LIR_lduc2ui: return Interval(     0,   255);
        case LIR_lds2i:   return Interval(-32768, 32767);
        case LIR_ldus2ui: return Interval(     0, 65535);

        case LIR_addi:
        case LIR_addxovi:
        case LIR_addjovi:
            if (lim > 0)
                return add(of(ins->oprnd1(), lim-1), of(ins->oprnd2(), lim-1));
            goto overflow;

        case LIR_subi:
        case LIR_subxovi:
        case LIR_subjovi:
            if (lim > 0)
                return sub(of(ins->oprnd1(), lim-1), of(ins->oprnd2(), lim-1));
            goto overflow;

        case LIR_negi:
            if (lim > 0)
                return sub(Interval(0, 0), of(ins->oprnd1(), lim-1));
            goto overflow;

        case LIR_muli:
        case LIR_mulxovi:
        case LIR_muljovi:
            if (lim > 0)
                return mul(of(ins->oprnd1(), lim), of(ins->oprnd2(), lim));
            goto overflow;

        case LIR_andi: {
            // Only handle one common case accurately, for speed and simplicity.
            if (ins->oprnd2()->isImmI() && ins->oprnd2()->immI() > 0) {
                // Example:  andi [lo,hi], 0xffff --> [0, 0xffff]
                return Interval(0, ins->oprnd2()->immI());
            }
            goto worst_non_overflow;
        }

        case LIR_rshui: {
            // Only handle one common case accurately, for speed and simplicity.
            if (ins->oprnd2()->isImmI() && lim > 0) {
                Interval x = of(ins->oprnd1(), lim-1);
                int32_t y = ins->oprnd2()->immI() & 0x1f;   // we only use the bottom 5 bits
                NanoAssert(x.isSane());
                if (!x.hasOverflowed && (x.lo >= 0 || y > 0)) {
                    // If LHS is non-negative or RHS is positive, the result is
                    // non-negative because the top bit must be zero.
                    // Example:  rshui [0,hi], 16 --> [0, hi>>16]
                    return Interval(0, x.hi >> y);
                }
            }
            goto worst_non_overflow;
        }

        case LIR_rshi: {
            // Only handle one common case accurately, for speed and simplicity.
            if (ins->oprnd2()->isImmI()) {
                // Example:  rshi [lo,hi], 16 --> [32768, 32767]
                int32_t y = ins->oprnd2()->immI() & 0x1f;   // we only use the bottom 5 bits
                return Interval(-(1 << (31 - y)),
                                 (1 << (31 - y)) - 1);
            }
            goto worst_non_overflow;
        }

#if defined NANOJIT_IA32 || defined NANOJIT_X64
        case LIR_modi: {
            NanoAssert(ins->oprnd1()->isop(LIR_divi));
            LIns* op2 = ins->oprnd1()->oprnd2();
            // Only handle one common case accurately, for speed and simplicity.
            if (op2->isImmI() && op2->immI() != 0) {
                int32_t y = op2->immI();
                int32_t absy = (y >= 0) ? y : -y;
                // The result must smaller in magnitude than 'y'.
                // Example:  modi [lo,hi], 5 --> [-4, 4]
                return Interval(-absy + 1, absy - 1);
            }
            goto worst_non_overflow;
        }
#endif

        case LIR_cmovi: {
            if (lim > 0) {
                Interval x = of(ins->oprnd2(), lim-1);
                Interval y = of(ins->oprnd3(), lim-1);
                NanoAssert(x.isSane() && y.isSane());
                if (!x.hasOverflowed && !y.hasOverflowed)
                    return Interval(NJ_MIN(x.lo, y.lo), NJ_MAX(x.hi, y.hi));
            }
            goto overflow;
        }

        case LIR_eqi:   CASE64(LIR_eqq:)
        case LIR_lti:   CASE64(LIR_ltq:)
        case LIR_lei:   CASE64(LIR_leq:)
        case LIR_gti:   CASE64(LIR_gtq:)
        case LIR_gei:   CASE64(LIR_geq:)
        case LIR_ltui:  CASE64(LIR_ltuq:)
        case LIR_leui:  CASE64(LIR_leuq:)
        case LIR_gtui:  CASE64(LIR_gtuq:)
        case LIR_geui:  CASE64(LIR_geuq:)
        case LIR_eqd:
        case LIR_ltd:
        case LIR_led:
        case LIR_gtd:
        case LIR_ged:
        case LIR_eqf4:
        case LIR_eqf:
        case LIR_ltf:
        case LIR_lef:
        case LIR_gtf:
        case LIR_gef:
            return Interval(0, 1);

        CASE32(LIR_paramp:)
        case LIR_ldi:
        case LIR_noti:
        case LIR_ori:
        case LIR_xori:
        case LIR_lshi:
        CASE86(LIR_divi:)
        case LIR_calli:
        case LIR_reti:
        CASE64(LIR_q2i:)
        case LIR_d2i:
        case LIR_f2i:
        CASESF(LIR_dlo2i:)
        CASESF(LIR_dhi2i:)
        CASESF(LIR_hcalli:)
            goto worst_non_overflow;

        default:
            NanoAssertMsgf(0, "%s", lirNames[ins->opcode()]);
        }

      overflow:
        return OverflowInterval();

      worst_non_overflow:
        // Only cases that cannot overflow should reach here, ie. not add/sub/mul.
        return Interval(I32_MIN, I32_MAX);
    }

    Interval Interval::add(Interval x, Interval y) {
        NanoAssert(x.isSane() && y.isSane());

        if (x.hasOverflowed || y.hasOverflowed)
            return OverflowInterval();

        // Nb: the bounds in x and y are known to fit in 32 bits (isSane()
        // checks that) so x.lo+y.lo and x.hi+y.hi are guaranteed to fit
        // in 64 bits.  This also holds for the other cases below such as
        // sub() and mul().
        return Interval(x.lo + y.lo, x.hi + y.hi);
    }

    Interval Interval::sub(Interval x, Interval y) {
        NanoAssert(x.isSane() && y.isSane());

        if (x.hasOverflowed || y.hasOverflowed)
            return OverflowInterval();

        return Interval(x.lo - y.hi, x.hi - y.lo);
    }

    Interval Interval::mul(Interval x, Interval y) {
        NanoAssert(x.isSane() && y.isSane());

        if (x.hasOverflowed || y.hasOverflowed)
            return OverflowInterval();

        int64_t a = x.lo * y.lo;
        int64_t b = x.lo * y.hi;
        int64_t c = x.hi * y.lo;
        int64_t d = x.hi * y.hi;
        return Interval(NJ_MIN(NJ_MIN(a, b), NJ_MIN(c, d)),
                        NJ_MAX(NJ_MAX(a, b), NJ_MAX(c, d)));
    }

#if NJ_SOFTFLOAT_SUPPORTED
    static int32_t FASTCALL d2i(double d)           { return (int32_t) d; }
    static double FASTCALL i2d(int32_t i)           { return i; }
    static double FASTCALL ui2d(uint32_t u)         { return u; }
    static double FASTCALL negd(double a)           { return -a; }
    static double FASTCALL addd(double a, double b) { return a + b; }
    static double FASTCALL subd(double a, double b) { return a - b; }
    static double FASTCALL muld(double a, double b) { return a * b; }
    static double FASTCALL divd(double a, double b) { return a / b; }
    static int32_t FASTCALL eqd(double a, double b) { return a == b; }
    static int32_t FASTCALL ltd(double a, double b) { return a <  b; }
    static int32_t FASTCALL gtd(double a, double b) { return a >  b; }
    static int32_t FASTCALL led(double a, double b) { return a <= b; }
    static int32_t FASTCALL ged(double a, double b) { return a >= b; }

    #define SIG_I_D     CallInfo::typeSig1(ARGTYPE_I, ARGTYPE_D)
    #define SIG_D_I     CallInfo::typeSig1(ARGTYPE_D, ARGTYPE_I)
    #define SIG_D_UI    CallInfo::typeSig1(ARGTYPE_D, ARGTYPE_UI)
    #define SIG_D_D     CallInfo::typeSig1(ARGTYPE_D, ARGTYPE_D)
    #define SIG_D_DD    CallInfo::typeSig2(ARGTYPE_D, ARGTYPE_D, ARGTYPE_D)
    #define SIG_B_DD    CallInfo::typeSig2(ARGTYPE_B, ARGTYPE_D, ARGTYPE_D)

    #define SF_CALLINFO(name, typesig) \
        static const CallInfo name##_ci = \
            { (intptr_t)&name, typesig, ABI_FASTCALL, /*isPure*/1, ACCSET_NONE verbose_only(, #name) }

    SF_CALLINFO(d2i,  SIG_I_D);
    SF_CALLINFO(i2d,  SIG_D_I);
    SF_CALLINFO(ui2d, SIG_D_UI);
    SF_CALLINFO(negd, SIG_D_D);
    SF_CALLINFO(addd, SIG_D_DD);
    SF_CALLINFO(subd, SIG_D_DD);
    SF_CALLINFO(muld, SIG_D_DD);
    SF_CALLINFO(divd, SIG_D_DD);
    SF_CALLINFO(eqd,  SIG_B_DD);
    SF_CALLINFO(ltd,  SIG_B_DD);
    SF_CALLINFO(gtd,  SIG_B_DD);
    SF_CALLINFO(led,  SIG_B_DD);
    SF_CALLINFO(ged,  SIG_B_DD);

    SoftFloatOps::SoftFloatOps()
    {
        memset(opmap, 0, sizeof(opmap));
        opmap[LIR_d2i] = &d2i_ci;
        opmap[LIR_i2d] = &i2d_ci;
#if defined NANOJIT_64BIT
        omap[LIR_q2d] = &q2d_ci;        // Will need to be implemented...
#endif
        opmap[LIR_ui2d] = &ui2d_ci;
        opmap[LIR_negd] = &negd_ci;
        opmap[LIR_addd] = &addd_ci;
        opmap[LIR_subd] = &subd_ci;
        opmap[LIR_muld] = &muld_ci;
        opmap[LIR_divd] = &divd_ci;
        opmap[LIR_eqd] = &eqd_ci;
        opmap[LIR_ltd] = &ltd_ci;
        opmap[LIR_gtd] = &gtd_ci;
        opmap[LIR_led] = &led_ci;
        opmap[LIR_ged] = &ged_ci;
    }

    const SoftFloatOps softFloatOps;

    SoftFloatFilter::SoftFloatFilter(LirWriter *out) : LirWriter(out)
    {}

    LIns* SoftFloatFilter::split(LIns *a) {
        if (a->isD() && !a->isop(LIR_ii2d)) {
            // all F64 args must be qjoin's for soft-float
            a = ins2(LIR_ii2d, ins1(LIR_dlo2i, a), ins1(LIR_dhi2i, a));
        }
        return a;
    }

    LIns* SoftFloatFilter::split(const CallInfo *call, LIns* args[]) {
        LIns *lo = out->insCall(call, args);
        LIns *hi = out->ins1(LIR_hcalli, lo);
        return out->ins2(LIR_ii2d, lo, hi);
    }

    LIns* SoftFloatFilter::callD1(const CallInfo *call, LIns *a) {
        LIns *args[] = { split(a) };
        return split(call, args);
    }

    LIns* SoftFloatFilter::callI1(const CallInfo *call, LIns *a) {
        LIns *args[] = { split(a) };
        return out->insCall(call, args);
    }

    LIns* SoftFloatFilter::callD2(const CallInfo *call, LIns *a, LIns *b) {
        LIns *args[] = { split(b), split(a) };
        return split(call, args);
    }

    LIns* SoftFloatFilter::cmpD(const CallInfo *call, LIns *a, LIns *b) {
        LIns *args[] = { split(b), split(a) };
        return out->ins2(LIR_eqi, out->insCall(call, args), out->insImmI(1));
    }

    LIns* SoftFloatFilter::ins1(LOpcode op, LIns *a) {
        const CallInfo *ci = softFloatOps.opmap[op];
        if (ci) {
            NanoAssertMsg(ci->returnType() != ARGTYPE_F, "Softfloat not implemented yet for single precision floats.");
            if (ci->returnType() == ARGTYPE_D)            
                return callD1(ci, a);
            else
                return callI1(ci, a);
        }
        NanoAssertMsg(op!=LIR_retf, "Softfloat not implemented yet for single precision floats.");
        if (op == LIR_retd)
            return out->ins1(op, split(a));
        return out->ins1(op, a);
    }

    LIns* SoftFloatFilter::ins2(LOpcode op, LIns *a, LIns *b) {
        const CallInfo *ci = softFloatOps.opmap[op];
        if (ci) {
            if (isCmpDOpcode(op))
                return cmpD(ci, a, b);
            return callD2(ci, a, b);
        }
        return out->ins2(op, a, b);
    }

    LIns* SoftFloatFilter::insCall(const CallInfo *ci, LIns* args[]) {
        uint32_t nArgs = ci->count_args();
        for (uint32_t i = 0; i < nArgs; i++)
            args[i] = split(args[i]);

        if (ci->returnType() == ARGTYPE_D) {
            // This function returns a double as two 32bit values, so replace
            // call with qjoin(qhi(call), call).
            return split(ci, args);
        }
        return out->insCall(ci, args);
    }
#endif // NJ_SOFTFLOAT_SUPPORTED


    #endif /* FEATURE_NANOJIT */

#if defined(NJ_VERBOSE)
    AddrNameMap::AddrNameMap(Allocator& a)
        : allocator(a), names(a)
    {}

    void AddrNameMap::addAddrRange(const void *p, size_t size, size_t align, const char *name)
    {
        if (!this || names.containsKey(p))
            return;
        char* copy = new (allocator) char[VMPI_strlen(name)+1];
        VMPI_strcpy(copy, name);
        Entry *e = new (allocator) Entry(copy, size << align, align);
        names.put(p, e);
    }

    void AddrNameMap::lookupAddr(void *p, char*& name, int32_t& offset)
    {
        const void *start = names.findNear(p);
        if (start) {
            Entry *e = names.get(start);
            const void *end = (const char*)start + e->size;
            if (p == start) {
                name = e->name;
                offset = 0;
            }
            else if (p > start && p < end) {
                name = e->name;
                offset = int32_t(intptr_t(p)-intptr_t(start)) >> e->align;
            }
            else {
                name = NULL;
                offset = 0;
            }
        } else {
            name = NULL;
            offset = 0;
        }
    }

    // ---------------------------------------------------------------
    // START debug-logging definitions
    // ---------------------------------------------------------------

    void LogControl::printf( const char* format, ... )
    {
        va_list vargs;
        va_start(vargs, format);
        vfprintf(stdout, format, vargs);
        va_end(vargs);
        // Flush every line immediately so that if crashes occur in generated
        // code we won't lose any output.
        fflush(stdout);
    }

#endif // NJ_VERBOSE


#ifdef FEATURE_NANOJIT
#ifdef DEBUG
    const char* ValidateWriter::type2string(LTy type)
    {
        switch (type) {
        case LTy_V:                     return "void";
        case LTy_I:                     return "int";
#ifdef NANOJIT_64BIT
        case LTy_Q:                     return "quad";
#endif
        case LTy_F:                     return "float";
        case LTy_F4:                    return "float4";
        case LTy_D:                     return "double";
        default:       NanoAssert(0);   return "???";
        }
    }

    void ValidateWriter::typeCheckArgs(LOpcode op, int nArgs, LTy formals[], LIns* args[])
    {
        NanoAssert(nArgs >= 0);

        // Type-check the arguments.
        for (int i = 0; i < nArgs; i++) {
            LTy formal = formals[i];
            LTy actual = args[i]->retType();
            if (formal != actual) {
                // Assert on a type error.  The disadvantage of doing this (as
                // opposed to printing a message and continuing) is that at
                // most one type error will be detected per run.  But type
                // errors should be rare, and assertion failures are certain
                // to be caught by test suites whereas error messages may not
                // be.
                NanoAssertMsgf(0,
                    "LIR type error (%s): arg %d of '%s' is '%s' "
                    "which has type %s (expected %s)",
                    whereInPipeline, i+1, lirNames[op],
                    lirNames[args[i]->opcode()],
                    type2string(actual), type2string(formal));
            }
        }
    }

    void ValidateWriter::errorStructureShouldBe(LOpcode op, const char* argDesc, int argN,
                                                LIns* arg, const char* shouldBeDesc)
    {
        NanoAssertMsgf(0,
            "LIR structure error (%s): %s %d of '%s' is '%s' (expected %s)",
            whereInPipeline, argDesc, argN,
            lirNames[op], lirNames[arg->opcode()], shouldBeDesc);
    }

    void ValidateWriter::errorAccSet(const char* what, AccSet accSet, const char* shouldDesc)
    {
        RefBuf b;
        NanoAssertMsgf(0,
            "LIR AccSet error (%s): '%s' AccSet is '%s'; %s",
            whereInPipeline, what, printer->formatAccSet(&b, accSet), shouldDesc);
    }

    void ValidateWriter::errorLoadQual(const char* what, LoadQual loadQual)
    {
        NanoAssertMsgf(0,
            "LIR LoadQual error (%s): '%s' loadQual is '%d'",
            whereInPipeline, what, loadQual);
    }

    void ValidateWriter::checkLInsIsACondOrConst(LOpcode op, int argN, LIns* ins)
    {
        // We could introduce a LTy_B32 type in the type system but that's a
        // bit weird because its representation is identical to LTy_I.  It's
        // easier to just do this check structurally.  Also, optimization can
        // cause the condition to become a LIR_immi.
        if (!ins->isCmp() && !ins->isImmI())
            errorStructureShouldBe(op, "argument", argN, ins, "a condition or 32-bit constant");
    }

    void ValidateWriter::checkLInsIsNull(LOpcode op, int argN, LIns* ins)
    {
        if (ins)
            errorStructureShouldBe(op, "argument", argN, ins, NULL);
    }

    void ValidateWriter::checkLInsHasOpcode(LOpcode op, int argN, LIns* ins, LOpcode op2)
    {
        if (!ins->isop(op2))
            errorStructureShouldBe(op, "argument", argN, ins, lirNames[op2]);
    }

    ValidateWriter::ValidateWriter(LirWriter *out, LInsPrinter* printer, const char* where)
        : LirWriter(out), printer(printer), whereInPipeline(where),
          checkAccSetExtras(0)
    {}

    LIns* ValidateWriter::insLoad(LOpcode op, LIns* base, int32_t d, AccSet accSet,
                                  LoadQual loadQual)
    {
        checkAccSet(op, base, d, accSet);

        switch (loadQual) {
        case LOAD_CONST:
        case LOAD_NORMAL:
        case LOAD_VOLATILE:
            break;
        default:
            errorLoadQual(lirNames[op], loadQual);
            break;
        }


        int nArgs = 1;
        LTy formals[1] = { LTy_P };
        LIns* args[1] = { base };

        switch (op) {
        case LIR_ldi:
        case LIR_ldd:
        case LIR_lduc2ui:
        case LIR_ldus2ui:
        case LIR_ldc2i:
        case LIR_lds2i:
        case LIR_ldf2d:
        case LIR_ldf:
        case LIR_ldf4:
        CASE64(LIR_ldq:)
            break;
        default:
            NanoAssert(0);
        }

        typeCheckArgs(op, nArgs, formals, args);

        return out->insLoad(op, base, d, accSet, loadQual);
    }

    LIns* ValidateWriter::insStore(LOpcode op, LIns* value, LIns* base, int32_t d, AccSet accSet)
    {
        checkAccSet(op, base, d, accSet);

        int nArgs = 2;
        LTy formals[2] = { LTy_V, LTy_P };     // LTy_V is overwritten shortly
        LIns* args[2] = { value, base };

        switch (op) {
        case LIR_sti2c:
        case LIR_sti2s:
        case LIR_sti:
            formals[0] = LTy_I;
            break;

#ifdef NANOJIT_64BIT
        case LIR_stq:
            formals[0] = LTy_Q;
            break;
#endif
        case LIR_stf:
            formals[0] = LTy_F;
            break;

        case LIR_stf4:
            formals[0] = LTy_F4;
            break;

        case LIR_std:
        case LIR_std2f:
            formals[0] = LTy_D;
            break;

        default:
            NanoAssert(0);
        }

        typeCheckArgs(op, nArgs, formals, args);

        return out->insStore(op, value, base, d, accSet);
    }

    LIns* ValidateWriter::ins0(LOpcode op)
    {
        switch (op) {
        case LIR_start:
        case LIR_regfence:
        case LIR_label:
        case LIR_pushstate:
        case LIR_popstate:
        case LIR_memfence:
        case LIR_restorepc:
            break;
        default:
            NanoAssert(0);
        }

        // No args to type-check.

        return out->ins0(op);
    }

    LIns* ValidateWriter::ins1(LOpcode op, LIns* a)
    {
        int nArgs = 1;
        LTy formals[1];
        LIns* args[1] = { a };

        switch (op) {
        case LIR_negi:
        case LIR_noti:
        case LIR_i2d:
        case LIR_ui2d:
        case LIR_i2f:
        case LIR_ui2f:
        case LIR_livei:
        case LIR_reti:
            formals[0] = LTy_I;
            break;

#ifdef NANOJIT_64BIT
        case LIR_i2q:
        case LIR_ui2uq:
            formals[0] = LTy_I;
            break;

        case LIR_q2d:
        case LIR_q2i:
        case LIR_qasd:
        case LIR_retq:
        case LIR_liveq:
            formals[0] = LTy_Q;
            break;
#endif

#if defined NANOJIT_IA32 || defined NANOJIT_X64
        case LIR_modi:       // see LIRopcode.tbl for why 'mod' is unary
            checkLInsHasOpcode(op, 1, a, LIR_divi);
            formals[0] = LTy_I;
            break;
#endif

#if NJ_SOFTFLOAT_SUPPORTED
        case LIR_dlo2i:
        case LIR_dhi2i:
            formals[0] = LTy_D;
            break;

        case LIR_hcalli:
            // The operand of a LIR_hcalli is LIR_calli, even though the
            // function being called has a return type of LTy_D.
            checkLInsHasOpcode(op, 1, a, LIR_calli);
            formals[0] = LTy_I;
            break;
#endif

        case LIR_negd:
        case LIR_absd:
        case LIR_sqrtd:
        case LIR_retd:
        case LIR_lived:
        case LIR_d2i:
        case LIR_d2f:
        CASE64(LIR_dasq:)
            formals[0] = LTy_D;
            break;

        case LIR_negf4:
        case LIR_absf4:
        case LIR_recipf4:
        case LIR_rsqrtf4:
        case LIR_sqrtf4:
        case LIR_retf4:
        case LIR_livef4:
        case LIR_f4x:
        case LIR_f4y:
        case LIR_f4z:
        case LIR_f4w:
            formals[0] = LTy_F4;
            break;

        case LIR_negf:
        case LIR_absf:
        case LIR_recipf:
        case LIR_rsqrtf:
        case LIR_sqrtf:
        case LIR_retf:
        case LIR_livef:
        case LIR_f2i:
        case LIR_f2d:
        case LIR_f2f4:
            formals[0] = LTy_F;
            break;
                
        case LIR_file:
        case LIR_line:
        case LIR_pc:
            // Ignore for the moment.  really we do know the operand types.
            nArgs = 0;
            break;

        default:
            NanoAssertMsgf(0, "%s\n", lirNames[op]);
        }

        typeCheckArgs(op, nArgs, formals, args);

        return out->ins1(op, a);
    }

    LIns* ValidateWriter::ins2(LOpcode op, LIns* a, LIns* b)
    {
        int nArgs = 2;
        LTy formals[2];
        LIns* args[2] = { a, b };

        switch (op) {
        case LIR_addi:
        case LIR_subi:
        case LIR_muli:
        CASE86(LIR_divi:)
        case LIR_andi:
        case LIR_ori:
        case LIR_xori:
        case LIR_lshi:
        case LIR_rshi:
        case LIR_rshui:
        case LIR_eqi:
        case LIR_lti:
        case LIR_gti:
        case LIR_lei:
        case LIR_gei:
        case LIR_ltui:
        case LIR_gtui:
        case LIR_leui:
        case LIR_geui:
            formals[0] = LTy_I;
            formals[1] = LTy_I;
            break;

#if NJ_SOFTFLOAT_SUPPORTED
        case LIR_ii2d:
            formals[0] = LTy_I;
            formals[1] = LTy_I;
            break;
#endif

#ifdef NANOJIT_64BIT
        case LIR_andq:
        case LIR_orq:
        case LIR_xorq:
        case LIR_addq:
        case LIR_subq:
        case LIR_eqq:
        case LIR_ltq:
        case LIR_gtq:
        case LIR_leq:
        case LIR_geq:
        case LIR_ltuq:
        case LIR_gtuq:
        case LIR_leuq:
        case LIR_geuq:
            formals[0] = LTy_Q;
            formals[1] = LTy_Q;
            break;

        case LIR_lshq:
        case LIR_rshq:
        case LIR_rshuq:
            formals[0] = LTy_Q;
            formals[1] = LTy_I;
            break;
#endif

        case LIR_addd:
        case LIR_subd:
        case LIR_muld:
        case LIR_divd:
        case LIR_eqd:
        case LIR_gtd:
        case LIR_ltd:
        case LIR_led:
        case LIR_ged:
            formals[0] = LTy_D;
            formals[1] = LTy_D;
            break;

        case LIR_addf:
        case LIR_subf:
        case LIR_mulf:
        case LIR_divf:
        case LIR_eqf:
        case LIR_gtf:
        case LIR_ltf:
        case LIR_lef:
        case LIR_gef:
            formals[0] = LTy_F;
            formals[1] = LTy_F;
            break;

        case LIR_addf4:
        case LIR_subf4:
        case LIR_mulf4:
        case LIR_divf4:
        case LIR_eqf4:
        case LIR_dotf4:
        case LIR_dotf3:
        case LIR_dotf2:
        case LIR_maxf4:
        case LIR_minf4:
        case LIR_cmpgtf4:
        case LIR_cmpgef4:
        case LIR_cmpltf4:
        case LIR_cmplef4:
        case LIR_cmpeqf4:
        case LIR_cmpnef4:
            formals[0] = LTy_F4;
            formals[1] = LTy_F4;
            break;
                
        default:
            NanoAssert(0);
        }

        typeCheckArgs(op, nArgs, formals, args);

        return out->ins2(op, a, b);
    }

    LIns* ValidateWriter::ins3(LOpcode op, LIns* a, LIns* b, LIns* c)
    {
        int nArgs = 3;
        LTy formals[3] = { LTy_I, LTy_V, LTy_V };   // LTy_V gets overwritten
        LIns* args[3] = { a, b, c };

        switch (op) {
        case LIR_cmovi:
            checkLInsIsACondOrConst(op, 1, a);
            formals[1] = LTy_I;
            formals[2] = LTy_I;
            break;

#ifdef NANOJIT_64BIT
        case LIR_cmovq:
            checkLInsIsACondOrConst(op, 1, a);
            formals[1] = LTy_Q;
            formals[2] = LTy_Q;
            break;
#endif

        case LIR_cmovd:
            checkLInsIsACondOrConst(op, 1, a);
            formals[1] = LTy_D;
            formals[2] = LTy_D;
            break;

        case LIR_cmovf:
            checkLInsIsACondOrConst(op, 1, a);
            formals[1] = LTy_F;
            formals[2] = LTy_F;
            break;
                
        case LIR_cmovf4:
            checkLInsIsACondOrConst(op, 1, a);
            formals[1] = LTy_F4;
            formals[2] = LTy_F4;
            break;

        default:
            NanoAssert(0);
        }

        typeCheckArgs(op, nArgs, formals, args);

        return out->ins3(op, a, b, c);
    }

    LIns* ValidateWriter::ins4(LOpcode op, LIns* a, LIns* b, LIns* c, LIns* d)
    {
        NanoAssert(op == LIR_ffff2f4);
        int nArgs = 4;
        LTy formals[4] = { LTy_F, LTy_F, LTy_F, LTy_F };   // LTy_V gets overwritten
        LIns* args[4] = { a, b, c, d };
        typeCheckArgs(op, nArgs, formals, args);
        return out->ins4(op, a, b, c, d);
    }
        
    LIns* ValidateWriter::insParam(int32_t arg, int32_t kind)
    {
        return out->insParam(arg, kind);
    }

    LIns* ValidateWriter::insImmI(int32_t imm)
    {
        return out->insImmI(imm);
    }

    LIns* ValidateWriter::insSafe(LOpcode op, void *payload) {
        return out->insSafe(op, payload);
    }

#ifdef NANOJIT_64BIT
    LIns* ValidateWriter::insImmQ(uint64_t imm)
    {
        return out->insImmQ(imm);
    }
#endif

    LIns* ValidateWriter::insImmD(double d)
    {
        return out->insImmD(d);
    }

    LIns* ValidateWriter::insImmF(float f)
    {
        return out->insImmF(f);
    }
    
    LIns* ValidateWriter::insImmF4(const float4_t& f)
    {
        return out->insImmF4(f);
    }

    static const char* argtypeNames[] = {
        "void",     // ARGTYPE_V  = 0
        "int32_t",  // ARGTYPE_I  = 1
        "uint32_t", // ARGTYPE_UI = 2
        "uint64_t", // ARGTYPE_Q  = 3
        "double",   // ARGTYPE_D  = 4
        "float",    // ARGTYPE_F  = 5
        "float4",   // ARGTYPE_F4 = 6
    };

    LIns* ValidateWriter::insCall(const CallInfo *ci, LIns* args0[])
    {
        ArgType argTypes[MAXARGS];
        uint32_t nArgs = ci->getArgTypes(argTypes);
        LTy formals[MAXARGS];
        LIns* args[MAXARGS];    // in left-to-right order, unlike args0[]

        LOpcode op = getCallOpcode(ci);
        ArgType retType = ci->returnType();

        if ((op == LIR_callv) != (retType == ARGTYPE_V) ||
            (op == LIR_calli) != (retType == ARGTYPE_UI ||
                                  retType == ARGTYPE_I) ||
#ifdef NANOJIT_64BIT
            (op == LIR_callq) != (retType == ARGTYPE_Q) ||
#endif
            (op == LIR_callf) != (retType == ARGTYPE_F) ||
            (op == LIR_callf4) != (retType == ARGTYPE_F4) ||
            (op == LIR_calld) != (retType == ARGTYPE_D)) {
            NanoAssertMsgf(0,
                "LIR structure error (%s): return type mismatch: opcode %s with %s return type",
                whereInPipeline, lirNames[op], argtypeNames[retType]);
        }

        if (op == LIR_callv && ci->_isPure) {
            // Since nobody can use the result of a void call, any pure call
            // would just be dead.  This is probably a mistake.
            NanoAssertMsgf(0,
                "LIR structure error (%s): LIR_callv must only be used with nonpure functions.",
                whereInPipeline);
        }

        if (ci->_isPure && ci->_storeAccSet != ACCSET_NONE)
            errorAccSet(ci->_name, ci->_storeAccSet, "it should be ACCSET_NONE for pure functions");

        // This loop iterates over the args from right-to-left (because arg()
        // and getArgTypes() use right-to-left order), but puts the results
        // into formals[] and args[] in left-to-right order so that arg
        // numbers in error messages make sense to the user.
        for (uint32_t i = 0; i < nArgs; i++) {
            uint32_t i2 = nArgs - i - 1;    // converts right-to-left to left-to-right
            switch (argTypes[i]) {
            case ARGTYPE_I:
            case ARGTYPE_UI:        formals[i2] = LTy_I;   break;
#ifdef NANOJIT_64BIT
            case ARGTYPE_Q:         formals[i2] = LTy_Q;   break;
#endif
            case ARGTYPE_F:         formals[i2] = LTy_F;   break;
            case ARGTYPE_F4:        formals[i2] = LTy_F4;  break;
            case ARGTYPE_D:         formals[i2] = LTy_D;   break;
            default: NanoAssertMsgf(0, "%d %s\n", argTypes[i],ci->_name); formals[i2] = LTy_V;  break;
            }
            args[i2] = args0[i];
        }

        typeCheckArgs(op, nArgs, formals, args);

        return out->insCall(ci, args0);
    }

    LIns* ValidateWriter::insGuard(LOpcode op, LIns *cond, GuardRecord *gr)
    {
        int nArgs = -1;     // init to shut compilers up
        LTy formals[1];
        LIns* args[1];

        switch (op) {
        case LIR_x:
        case LIR_xbarrier:
            checkLInsIsNull(op, 1, cond);
            nArgs = 0;
            break;

        case LIR_xt:
        case LIR_xf:
            checkLInsIsACondOrConst(op, 1, cond);
            nArgs = 1;
            formals[0] = LTy_I;
            args[0] = cond;
            break;

        default:
            NanoAssert(0);
        }

        typeCheckArgs(op, nArgs, formals, args);

        return out->insGuard(op, cond, gr);
    }

    LIns* ValidateWriter::insGuardXov(LOpcode op, LIns* a, LIns* b, GuardRecord* gr)
    {
        int nArgs = 2;
        LTy formals[2] = { LTy_I, LTy_I };
        LIns* args[2] = { a, b };

        switch (op) {
        case LIR_addxovi:
        case LIR_subxovi:
        case LIR_mulxovi:
            break;

        default:
            NanoAssert(0);
        }

        typeCheckArgs(op, nArgs, formals, args);

        return out->insGuardXov(op, a, b, gr);
    }

    LIns* ValidateWriter::insBranch(LOpcode op, LIns* cond, LIns* to)
    {
        int nArgs = -1;     // init to shut compilers up
        LTy formals[1];
        LIns* args[1];

        switch (op) {
        case LIR_j:
            checkLInsIsNull(op, 1, cond);
            nArgs = 0;
            break;

        case LIR_jt:
        case LIR_jf:
            checkLInsIsACondOrConst(op, 1, cond);
            nArgs = 1;
            formals[0] = LTy_I;
            args[0] = cond;
            break;

	case LIR_brsavpc:
            nArgs = 1;
            formals[0] = LTy_I;
            args[0] = cond;
            break;

        default:
            NanoAssert(0);
        }

        // We check that target is a label in ValidateReader because it may
        // not have been set here.

        typeCheckArgs(op, nArgs, formals, args);

        return out->insBranch(op, cond, to);
    }

    LIns* ValidateWriter::insBranchJov(LOpcode op, LIns* a, LIns* b, LIns* to)
    {
        int nArgs = 2;
        LTy formals[2];
        LIns* args[2] = { a, b };

        switch (op) {
        case LIR_addjovi:
        case LIR_subjovi:
        case LIR_muljovi:
            formals[0] = LTy_I;
            formals[1] = LTy_I;
            break;

#ifdef NANOJIT_64BIT
        case LIR_addjovq:
        case LIR_subjovq:
            formals[0] = LTy_Q;
            formals[1] = LTy_Q;
            break;
#endif
        default:
            NanoAssert(0);
        }

        // We check that target is a label in ValidateReader because it may
        // not have been set here.

        typeCheckArgs(op, nArgs, formals, args);

        return out->insBranchJov(op, a, b, to);
    }

    LIns* ValidateWriter::insAlloc(int32_t size)
    {
        return out->insAlloc(size);
    }

    LIns* ValidateWriter::insJtbl(LIns* index, uint32_t size)
    {
        int nArgs = 1;
        LTy formals[1] = { LTy_I };
        LIns* args[1] = { index };

        typeCheckArgs(LIR_jtbl, nArgs, formals, args);

        // We check that all jump table entries are labels in ValidateReader
        // because they won't have been set here.

        return out->insJtbl(index, size);
    }

    ValidateReader::ValidateReader(LirFilter* in) : LirFilter(in)
        {}

    LIns* ValidateReader::read()
    {
        LIns *ins = in->read();
        switch (ins->opcode()) {
        case LIR_jt:
        case LIR_jf:
        case LIR_j:
            NanoAssert(ins->getTarget() && ins->oprnd2()->isop(LIR_label));
            break;

        case LIR_addjovi:
        case LIR_subjovi:
        case LIR_muljovi:
        CASE64(LIR_addjovq:)
        CASE64(LIR_subjovq:)
            NanoAssert(ins->getTarget() && ins->oprnd3()->isop(LIR_label));
            break;

        case LIR_jtbl: {
            uint32_t tableSize = ins->getTableSize();
            NanoAssert(tableSize > 0);
            for (uint32_t i = 0; i < tableSize; i++) {
                LIns* target = ins->getTarget(i);
                NanoAssert(target);
                NanoAssert(target->isop(LIR_label));
            }
            break;
        }
        default:
            ;
        }
        return ins;
    }

    LIns* ValidateWriter::insSwz(LIns* a, uint8_t mask)
    {
        LTy formals[] = { LTy_F4 };
        LIns* args[] = { a };
        typeCheckArgs(LIR_swzf4, 1, formals, args);
        return out->insSwz(a, mask);
    }
#endif
#endif

}
