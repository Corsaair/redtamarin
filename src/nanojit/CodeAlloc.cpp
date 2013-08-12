/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "nanojit.h"

//#define DOPROF
#include "../vprof/vprof.h"

#ifdef FEATURE_NANOJIT

namespace nanojit
{
    static const bool verbose = false;
#if defined VMCFG_VTUNE || defined VMCFG_SHARK
    // Profilers get confused by non-contiguous functions,
    // so make the allocation size huge to avoid non-contiguous methods
    static const int pagesPerAlloc = 256; // 1MB
#elif defined(NANOJIT_ARM) || defined(NANOJIT_THUMB2)
    // ARM requires single-page allocations, due to the constant pool that
    // lives on each page that must be reachable by a 4KB pc-relative load.
    static const int pagesPerAlloc = 1; // 4KB
#else
    static const int pagesPerAlloc = 16; // 64KB
#endif

    // Sanity checks that should remain enabled in release builds.
    #define ABORT_UNLESS(cond) do { NanoAssert(cond); if (!(cond)) VMPI_abort(); } while(0)

    CodeAlloc::CodeAlloc(const Config* config)
        : heapblocks(0)
        , availblocks(0)
        , totalAllocated(0)
        , bytesPerPage(VMPI_getVMPageSize())
        , bytesPerAlloc(pagesPerAlloc * bytesPerPage)
        , _config(config)
    {
    }

    CodeAlloc::~CodeAlloc() {
        reset();
    }

    void CodeAlloc::reset() {
        // give all memory back to gcheap.  Assumption is that all
        // code is done being used by now.
        for (CodeList* hb = heapblocks; hb != 0; ) {
            _nvprof("free page",1);
            CodeList* next = hb->next;
            CodeList* fb = firstBlock(hb);
            markBlockWrite(fb);
            freeCodeChunk(fb, bytesPerAlloc);
            totalAllocated -= bytesPerAlloc;
            hb = next;
        }
        NanoAssert(!totalAllocated);
        heapblocks = availblocks = 0;
    }

    CodeList* CodeAlloc::firstBlock(CodeList* term) {
        // use uintptr_t, rather than char*, to avoid "increases required alignment" warning
        uintptr_t end = (uintptr_t)alignUp(term, bytesPerPage);
        return (CodeList*) (end - (uintptr_t)bytesPerAlloc);
    }

    static int round(size_t x) {
        return (int)((x + 512) >> 10);
    }

    void CodeAlloc::getStats(size_t& total, size_t& frag_size, size_t& free_size) {
        total = 0;
        frag_size = 0;
        free_size = 0;
        int free_count = 0;
        for (CodeList* hb = heapblocks; hb != 0; hb = hb->next) {
            total += bytesPerAlloc;
            for (CodeList* b = hb->lower; b != 0; b = b->lower) {
                if (b->isFree) {
                    free_count++;
                    free_size += b->blockSize();
                    if (b->size() < minAllocSize)
                        frag_size += b->blockSize();
                }
            }
        }
    }

    void CodeAlloc::logStats() {
        size_t total, frag_size, free_size;
        getStats(total, frag_size, free_size);
        avmplus::AvmLog("code-heap: %dk free %dk fragmented %d\n",
            round(total), round(free_size), frag_size);
    }

    inline void CodeAlloc::markBlockWrite(CodeList* b) {
        NanoAssert(b->terminator != NULL);
        CodeList* term = b->terminator;
        if (term->isExec) {
            markCodeChunkWrite(firstBlock(term), bytesPerAlloc);
            term->isExec = false;
        }
    }

   void CodeAlloc::alloc(NIns* &start, NIns* &end, size_t byteLimit) {
        if (!availblocks) {
            // no free mem, get more
            addMem();
        }

        // grab a block
        NanoAssert(!byteLimit || byteLimit > blkSpaceFor(2));  // if a limit is imposed it must be bigger than 2x minimum block size (see below)
        markBlockWrite(availblocks);
        CodeList* b = removeBlock(availblocks);

        // limit imposed (byteLimit > 0) and the block is too big?  then break it apart
        if (byteLimit > 0 && b->size() > byteLimit) {

            size_t consume;   // # bytes to extract from the free block

            // enough space to carve out a perfectly sized blk?  (leaving at least a full free blk)
            if (b->size() >= byteLimit + headerSpaceFor(1) + blkSpaceFor(1)) {
                // yes, then take exactly what we need
                consume = byteLimit + headerSpaceFor(1);
            } else {
                // no, then we should only take the min amount
                consume = blkSpaceFor(1);

                // ... and since b->size() > byteLimit && byteLimit > blkSpaceFor(2)
                NanoAssert( b->size() > blkSpaceFor(2) );
                NanoAssert( b->size() - consume > blkSpaceFor(1) );  // thus, we know that at least 1 blk left.
            }

            // break block into 2 pieces, returning the lower portion to the free list
            ABORT_UNLESS(b->higher->lower == b);
            ABORT_UNLESS(b->terminator->end == 0);
            ABORT_UNLESS(b->terminator->terminator == 0);
            CodeList* higher = b->higher;
            b->end = (NIns*) ( (uintptr_t)b->end - consume );
            CodeList* b1 = b->higher;
            higher->lower = b1;
            b1->higher = higher;
            b1->lower = b;
            b1->terminator = b->terminator;
            NanoAssert(b->size() > minAllocSize);
            addBlock(availblocks, b);  // put back the rest of the block
            b = b1;
        }
        NanoAssert(b->size() >= minAllocSize);
        b->next = 0; // not technically needed (except for debug builds), but good hygiene.
        b->isFree = false;
        start = b->start();
        end = b->end;
        if (verbose)
            avmplus::AvmLog("CodeAlloc(%p).alloc %p-%p %d\n", this, start, end, int(end-start));
        debug_only(sanity_check();)
    }

    void CodeAlloc::free(NIns* start, NIns *end) {
        NanoAssert(heapblocks);
        CodeList *blk = getBlock(start, end);
        if (verbose)
            avmplus::AvmLog("free %p-%p %d\n", start, end, (int)blk->size());

        NanoAssert(!blk->isFree);

        // coalesce adjacent blocks.
        bool already_on_avail_list;

        if (blk->lower && blk->lower->isFree) {
            // combine blk into blk->lower (destroy blk)
            CodeList* lower = blk->lower;
            CodeList* higher = blk->higher;
            already_on_avail_list = lower->size() >= minAllocSize;
            ABORT_UNLESS(lower->higher == blk);
            ABORT_UNLESS(higher->lower == blk);
            lower->higher = higher;
            higher->lower = lower;
            blk = lower;
        }
        else
            already_on_avail_list = false;

        // the last block in each heapblock is a terminator block,
        // which is never free, therefore blk->higher != null
        if (blk->higher->isFree) {
            CodeList *higher = blk->higher->higher;
            CodeList *coalescedBlock = blk->higher;

            if ( coalescedBlock->size() >= minAllocSize ) {
                // Unlink coalescedBlock from the available block chain.
                if ( availblocks == coalescedBlock ) {
                    removeBlock(availblocks);
                }
                else {
                    CodeList* free_block = availblocks;
                    while (free_block->next != coalescedBlock) {
                        NanoAssert(free_block->size() >= minAllocSize);
                        NanoAssert(free_block->isFree);
                        NanoAssert(free_block->next);
                        free_block = free_block->next;
                    }
                    NanoAssert(free_block->next == coalescedBlock);
                    free_block->next = coalescedBlock->next;
                }
            }

            // combine blk->higher into blk (destroy coalescedBlock)
            ABORT_UNLESS(coalescedBlock->higher->lower == coalescedBlock);
            ABORT_UNLESS(coalescedBlock->lower->higher == coalescedBlock);
            blk->higher = higher;
            higher->lower = blk;
        }
        blk->isFree = true;
        NanoAssert(!blk->lower || !blk->lower->isFree);
        NanoAssert(blk->higher && !blk->higher->isFree);
        //memset(blk->start(), 0xCC, blk->size()); // INT 3 instruction
        if ( !already_on_avail_list && blk->size() >= minAllocSize )
            addBlock(availblocks, blk);

        NanoAssert(heapblocks);
        debug_only(sanity_check();)
    }

    void CodeAlloc::freeAll(CodeList* &code) {
        while (code) {
            CodeList *b = removeBlock(code);
            free(b->start(), b->end);
        }
    }

    void CodeAlloc::flushICache(CodeList* &blocks) {
        for (CodeList *b = blocks; b != 0; b = b->next)
            flushICache(b->start(), b->size());
    }

#if defined(AVMPLUS_UNIX) && (defined(NANOJIT_ARM) || defined(NANOJIT_THUMB2))
#if defined(__APPLE__)
#include <libkern/OSCacheControl.h>
#else
#include <asm/unistd.h>
extern "C" void __clear_cache(char *BEG, char *END);
#endif
#endif

#if defined(AVMPLUS_UNIX) && defined(NANOJIT_MIPS)
#include <asm/cachectl.h>
extern  "C" int cacheflush(char *addr, int nbytes, int cache);
#endif

#ifdef AVMPLUS_SPARC
// Note: the linux #define provided by the compiler.
#ifdef linux  // bugzilla 502369
void sync_instruction_memory(caddr_t v, u_int len)
{
    caddr_t end = v + len;
    caddr_t p = v;
    while (p < end) {
        asm("flush %0" : : "r" (p));
        p += 32;
    }
}
#else
extern  "C" void sync_instruction_memory(caddr_t v, u_int len);
#endif
#endif

#if defined NANOJIT_IA32 || defined NANOJIT_X64
    // intel chips have dcache/icache interlock
    void CodeAlloc::flushICache(void *start, size_t len) {
        // Tell Valgrind that new code has been generated, and it must flush
        // any translations it has for the memory range generated into.
        (void)start;
        (void)len;
        VALGRIND_DISCARD_TRANSLATIONS(start, len);
    }
#elif (defined(NANOJIT_ARM) || defined(NANOJIT_THUMB2)) && defined WIN32
    void CodeAlloc::flushICache(void *start, size_t len) {
        FlushInstructionCache(GetCurrentProcess(), start, len);
    }

#elif defined NANOJIT_ARM && defined DARWIN
    void CodeAlloc::flushICache(void *, size_t) {
        VMPI_debugBreak();
    }

#elif defined AVMPLUS_MAC && defined NANOJIT_PPC

#  ifdef NANOJIT_64BIT
    extern "C" void sys_icache_invalidate(const void*, size_t len);
    extern "C" void sys_dcache_flush(const void*, size_t len);

    // mac 64bit requires 10.5 so use that api
    void CodeAlloc::flushICache(void *start, size_t len) {
        sys_dcache_flush(start, len);
        sys_icache_invalidate(start, len);
    }
#  else
    // mac ppc 32 could be 10.0 or later
    // uses MakeDataExecutable() from Carbon api, OSUtils.h
    // see http://developer.apple.com/documentation/Carbon/Reference/Memory_Manag_nt_Utilities/Reference/reference.html#//apple_ref/c/func/MakeDataExecutable
    void CodeAlloc::flushICache(void *start, size_t len) {
        MakeDataExecutable(start, len);
    }
#  endif

#elif defined NANOJIT_ARM && defined VMCFG_SYMBIAN
    void CodeAlloc::flushICache(void *ptr, size_t len) {
        uint32_t start = (uint32_t)ptr;
        uint32_t rangeEnd = start + len;
        User::IMB_Range((TAny*)start, (TAny*)rangeEnd);
    }

#elif defined AVMPLUS_SPARC
    // fixme: sync_instruction_memory is a solaris api, test for solaris not sparc
    void CodeAlloc::flushICache(void *start, size_t len) {
            sync_instruction_memory((char*)start, len);
    }

#elif defined NANOJIT_SH4
#include <asm/cachectl.h> /* CACHEFLUSH_*, */
#include <sys/syscall.h>  /* __NR_cacheflush, */
    void CodeAlloc::flushICache(void *start, size_t len) {
        syscall(__NR_cacheflush, start, len, CACHEFLUSH_D_WB | CACHEFLUSH_I);
    }

#elif defined(AVMPLUS_UNIX) && defined(NANOJIT_MIPS)
    void CodeAlloc::flushICache(void *start, size_t len) {
        // FIXME Use synci on MIPS32R2
        cacheflush((char *)start, len, BCACHE);
    }

#elif defined AVMPLUS_UNIX
    #ifdef ANDROID
    void CodeAlloc::flushICache(void *start, size_t len) {
        cacheflush((int)start, (int)start + len, 0);
    }
    #elif defined(AVMPLUS_ARM) && defined(__APPLE__)
    void CodeAlloc::flushICache(void *start, size_t len) {
        sys_dcache_flush(start, len);
    }
    #else
    // fixme: __clear_cache is a libgcc feature, test for libgcc or gcc
    void CodeAlloc::flushICache(void *start, size_t len) {
        __clear_cache((char*)start, (char*)start + len);
    }
    #endif
#endif // AVMPLUS_MAC && NANOJIT_PPC

    void CodeAlloc::addBlock(CodeList* &blocks, CodeList* b) {
        NanoAssert(b->terminator != NULL);  // should not be mucking with terminator blocks
        b->next = blocks;
        blocks = b;
    }

    void CodeAlloc::addMem() {
        void *mem = allocCodeChunk(bytesPerAlloc); // allocations never fail
        totalAllocated += bytesPerAlloc;
        NanoAssert(mem != NULL); // see allocCodeChunk contract in CodeAlloc.h
        _nvprof("alloc page", uintptr_t(mem)>>12);

        CodeList* b = (CodeList*)mem;
        b->lower = 0;
        b->next = 0;
        b->end = (NIns*) (uintptr_t(mem) + bytesPerAlloc - sizeofMinBlock);
        b->isFree = true;

        // create a tiny terminator block, add to fragmented list, this way
        // all other blocks have a valid block at b->higher
        CodeList* terminator = b->higher;
        b->terminator = terminator;
        terminator->lower = b;
        terminator->end = 0; // this is how we identify the terminator
        terminator->isFree = false;
        terminator->isExec = false;
        terminator->terminator = 0;
        debug_only(sanity_check();)

        // add terminator to heapblocks list so we can track whole blocks
        terminator->next = heapblocks;
        heapblocks = terminator;

        addBlock(availblocks, b); // add to free list
    }

    CodeList* CodeAlloc::getBlock(NIns* start, NIns* end) {
        CodeList* b = (CodeList*) (uintptr_t(start) - offsetof(CodeList, code));
        NanoAssert(b->end == end && b->next == 0); (void) end;
        return b;
    }

    CodeList* CodeAlloc::removeBlock(CodeList* &blocks) {
        CodeList* b = blocks;
        NanoAssert(b != NULL);
        NanoAssert(b->terminator != NULL);  // should not be mucking with terminator blocks
        blocks = b->next;
        b->next = 0;
        return b;
    }

    void CodeAlloc::add(CodeList* &blocks, NIns* start, NIns* end) {
        addBlock(blocks, getBlock(start, end));
    }

    /**
     * split a block by freeing the hole in the middle defined by [holeStart,holeEnd),
     * and adding the used prefix and suffix parts to the blocks CodeList.
     */
    void CodeAlloc::addRemainder(CodeList* &blocks, NIns* start, NIns* end, NIns* holeStart, NIns* holeEnd) {
        NanoAssert(start < end && start <= holeStart && holeStart <= holeEnd && holeEnd <= end);
        // shrink the hole by aligning holeStart forward and holeEnd backward
        holeStart = (NIns*) ((uintptr_t(holeStart) + sizeof(NIns*)-1) & ~(sizeof(NIns*)-1));
        holeEnd = (NIns*) (uintptr_t(holeEnd) & ~(sizeof(NIns*)-1));
        // hole needs to be big enough for 2 headers + 1 block of free space (subtraction not used in check to avoid wraparound)
        size_t minHole = headerSpaceFor(2) + blkSpaceFor(1);
        if (uintptr_t(holeEnd) < minHole + uintptr_t(holeStart) ) {
            // the hole is too small to make a new free block and a new used block. just keep
            // the whole original block and don't free anything.
            add(blocks, start, end);
        } else if (holeStart == start && holeEnd == end) {
            // totally empty block.  free whole start-end range
            this->free(start, end);
        } else if (holeStart == start) {
            // hole is lower-aligned with start, so just need one new block
            // b1 b2
            CodeList* b1 = getBlock(start, end);
            CodeList* b2 = (CodeList*) (uintptr_t(holeEnd) - offsetof(CodeList, code));
            b2->terminator = b1->terminator;
            b2->isFree = false;
            b2->next = 0;
            b2->higher = b1->higher;
            b2->lower = b1;
            b2->higher->lower = b2;
            b1->higher = b2;
            debug_only(sanity_check();)
            this->free(b1->start(), b1->end);
            addBlock(blocks, b2);
        } else if (holeEnd == end) {
            // hole is right-aligned with end, just need one new block
            // todo
            NanoAssert(false);
        } else {
            // there's enough space left to split into three blocks (two new ones)
            CodeList* b1 = getBlock(start, end);
            CodeList* b2 = (CodeList*) (void*) holeStart;
            CodeList* b3 = (CodeList*) (uintptr_t(holeEnd) - offsetof(CodeList, code));
            b1->higher = b2;
            b2->lower = b1;
            b2->higher = b3;
            b2->isFree = false; // redundant, since we're about to free, but good hygiene
            b2->terminator = b1->terminator;
            b3->lower = b2;
            b3->end = end;
            b3->isFree = false;
            b3->higher->lower = b3;
            b3->terminator = b1->terminator;
            b2->next = 0;
            b3->next = 0;
            debug_only(sanity_check();)
            this->free(b2->start(), b2->end);
            addBlock(blocks, b3);
            addBlock(blocks, b1);
        }
    }

#ifdef PERFM
    // This method is used only for profiling purposes.
    // See CodegenLIR::emitMD() in Tamarin for an example.

    size_t CodeAlloc::size(const CodeList* blocks) {
        size_t size = 0;
        for (const CodeList* b = blocks; b != 0; b = b->next)
            size += int((uintptr_t)b->end - (uintptr_t)b);
        return size;
    }
#endif

    size_t CodeAlloc::size() {
        return totalAllocated;
    }

    // check that all block neighbors are correct
    #ifdef _DEBUG
    void CodeAlloc::sanity_check() {
        for (CodeList* hb = heapblocks; hb != 0; hb = hb->next) {
            NanoAssert(hb->higher == 0);
            for (CodeList* b = hb->lower; b != 0; b = b->lower) {
                NanoAssert(b->higher->lower == b);
            }
            if (_config->check_page_flags) {
                bool b = checkChunkMark(firstBlock(hb), bytesPerAlloc, hb->isExec);
                NanoAssertMsg(b, "Chunk access mode differs from that expected");
            }
        }
        for (CodeList* avail = this->availblocks; avail; avail = avail->next) {
            NanoAssert(avail->isFree && avail->size() >= minAllocSize);
        }

        #if CROSS_CHECK_FREE_LIST
        for(CodeList* term = heapblocks; term; term = term->next) {
            for(CodeList* hb = term->lower; hb; hb = hb->lower) {
                if (hb->isFree && hb->size() >= minAllocSize) {
                    bool found_on_avail = false;
                    for (CodeList* avail = this->availblocks; !found_on_avail && avail; avail = avail->next) {
                        found_on_avail = avail == hb;
                    }

                    NanoAssert(found_on_avail);
                }
            }
        }
        for (CodeList* avail = this->availblocks; avail; avail = avail->next) {
            bool found_in_heapblocks = false;
            for(CodeList* term = heapblocks; !found_in_heapblocks && term; term = term->next) {
                for(CodeList* hb = term->lower; !found_in_heapblocks && hb; hb = hb->lower) {
                    found_in_heapblocks = hb == avail;
                }
            }
            NanoAssert(found_in_heapblocks);
        }
        #endif /* CROSS_CHECK_FREE_LIST */
    }
    #endif

    // Loop through a list of blocks marking the chunks executable.  If we encounter
    // multiple blocks in the same chunk, only the first block will cause the
    // chunk to become executable, the other calls will no-op (isExec flag checked)
    void CodeAlloc::markExec(CodeList* &blocks) {
        for (CodeList *b = blocks; b != 0; b = b->next) {
            markChunkExec(b->terminator);
        }
    }

    // Variant of markExec(CodeList*) that walks all heapblocks (i.e. chunks) marking
    // each one executable.   On systems where bytesPerAlloc is low (i.e. have lots
    // of elements in the list) this can be expensive.
    void CodeAlloc::markAllExec() {
        for (CodeList* hb = heapblocks; hb != NULL; hb = hb->next) {
            markChunkExec(hb);
        }
    }

    // make an entire chunk executable
    void CodeAlloc::markChunkExec(CodeList* term) {
        NanoAssert(term->terminator == NULL);
        if (!term->isExec) {
            term->isExec = true;
            markCodeChunkExec(firstBlock(term), bytesPerAlloc);
        }
        debug_only(sanity_check();)
    }
}
#endif // FEATURE_NANOJIT
