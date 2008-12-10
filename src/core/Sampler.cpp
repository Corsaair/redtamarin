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

// Adobe patent application tracking #P721, entitled Application Profiling, inventors: T. Reilly

#ifdef FEATURE_SAMPLER
namespace avmplus
{
	using namespace MMgc;

	Sampler::Sampler(GC *gc) : allocId(1), sampling(true),
			autoStartSampling(false), samplingNow(false), samplingAllAllocs(false), takeSample(0),
			numSamples(0), currentSample(NULL), timerHandle(0), lastAllocSample(0),
			uids(1024), ptrSamples(0), callback(0), runningCallback(false), m_fakeMethodNames(gc)
	{
		samples = new (gc) GrowableBuffer(gc->GetGCHeap());
	}

	void Sampler::setCore(AvmCore *core)
	{
		this->core = core;
	}

	Sampler::~Sampler()
	{
		stopSampling();
		Sampler* gc_sampler = MMgc::m_sampler;
		if(gc_sampler == this)
			MMgc::m_sampler = NULL;
		delete samples;
		samples = 0;
	}

	void Sampler::init(bool sampling, bool autoStart)
	{
		this->sampling = sampling;
		this->autoStartSampling = autoStart;
	}

	byte *Sampler::getSamples(uint32 &num)
	{
		num = numSamples;
		byte *start = samples->start();
		return start;
	}

	void Sampler::sample()
	{		
		AvmAssertMsg(sampling, "How did we get here if sampling is disabled?");
		if(!samplingNow || !core->callStack || !sampleSpaceCheck())
			return;	
		writeRawSample(RAW_SAMPLE);
		numSamples++;
	}

	int Sampler::sampleSpaceCheck(bool callback_ok)
	{
		if(!samples->start())
			return 0;

		uint32 sampleSize = sizeof(Sample);
		uint32 callStackDepth = core->callStack ? core->callStack->depth() : 0;
		sampleSize += callStackDepth * sizeof(StackTrace::Element);
		sampleSize += sizeof(uint64) * 2;
		if( callback && callback_ok && !runningCallback && currentSample+sampleSize+samples->size()/3 > samples->end() 
			&& !core->GetGC()->Collecting() 
#ifdef MMGC_DRC
			&& !core->GetGC()->Reaping()
#endif
			)		{
			runningCallback = true;
			pauseSampling();
			Atom args[1] = { nullObjectAtom };
			Atom ret = callback->call(0, args);
			if( ret == falseAtom)
				stopSampling();
			else
				startSampling();
			runningCallback = false;
		}
		while(currentSample + sampleSize > samples->uncommitted()) {
			samples->grow();
			if(currentSample + sampleSize > samples->uncommitted()) {
/*
#ifdef AVMPLUS_VERBOSE
				core->console << "****** Exhausted Sample Buffer *******\n";
#endif
*/
				// exhausted buffer
				stopSampling();
				return 0;
			}
		}
		return 1;
	}

	void Sampler::writeRawSample(SampleType sampleType)
	{
		CallStackNode *csn = core->callStack;
		uint32 depth = csn ? csn->depth() : 0;
		byte *p = currentSample;
		write(p, GC::ticksToMicros(GC::GetPerformanceCounter()));
		write(p, sampleType);
		if(sampleType != DELETED_OBJECT_SAMPLE)
		{
			//if(depth == 0)
			//	AvmDebugMsg(false, "Please add SAMPLE_FRAME's to give this allocation some context.");
			write(p, depth);
			while(csn)
			{
				write(p, csn->info());
				write(p, csn->envname());
				// FIXME: can filename can be stored in the AbstractInfo?
#ifdef DEBUGGER
				write(p, csn->filename());
				write(p, csn->linenum());
#else
				write(p, 0);
				write(p, 0);
#endif
#ifdef AVMPLUS_64BIT
				AvmAssert(sizeof(StackTrace::Element) == sizeof(AbstractFunction *) + sizeof(Stringp) + sizeof(Stringp) + sizeof(int32_t) + sizeof(int32_t));
				write(p, (int) 0); // structure padding
#endif
				csn = csn->next();
				depth--;
			}
			AvmAssert(depth == 0);
		}
		// padding to keep 8 byte alignment
		align(p);
		currentSample = p;
		takeSample = 0;
	}

	void Sampler::readSample(byte *&p, Sample &s)
	{
		memset(&s, 0, sizeof(Sample));
		read(p, s.micros);
		read(p, s.sampleType);
		AvmAssertMsg(s.sampleType == RAW_SAMPLE || 
				s.sampleType == NEW_OBJECT_SAMPLE || 
				s.sampleType == DELETED_OBJECT_SAMPLE ||
				s.sampleType == NEW_AUX_SAMPLE, "Sample stream corruption.\n");

		if(s.sampleType != DELETED_OBJECT_SAMPLE)
		{
			read(p, s.stack.depth);
			s.stack.trace = p;
#ifndef AVMPLUS_64BIT
			AvmAssert(sizeof(StackTrace::Element) == sizeof(AbstractFunction *) + sizeof(Stringp) + sizeof(Stringp) + sizeof(int32_t));
#else
			// Extra int because of the structure padding
			AvmAssert(sizeof(StackTrace::Element) == sizeof(AbstractFunction *) + sizeof(Stringp) + sizeof(Stringp) + sizeof(int32_t) + sizeof(int32_t));
#endif
			p += s.stack.depth * sizeof(StackTrace::Element);
		}
		// padding to keep 8 byte alignment
		align(p);
		if(s.sampleType != Sampler::RAW_SAMPLE)
		{
			read(p, s.id);
			if(s.sampleType == Sampler::NEW_OBJECT_SAMPLE || s.sampleType == Sampler::NEW_AUX_SAMPLE)
			{
				read(p, s.ptr);
				read(p, s.typeOrVTable);
				read(p, s.alloc_size);
			}
			else 
			{
				read(p, s.size);
			}
		}
	}

	uint64 Sampler::recordAllocationSample(void* item, uint64 size, bool callback_ok)
	{
		AvmAssertMsg(sampling, "How did we get here if sampling is disabled?");
		if(!samplingNow)
			return 0;

		if(!samplingAllAllocs)
			return 0;

		if(!sampleSpaceCheck(callback_ok))
			return 0;

		(void)item;

		lastAllocSample = currentSample;
		writeRawSample(NEW_AUX_SAMPLE);
		uint64 uid = allocId++;
		samplingNow = false;
		uids.add(GetRealPointer(item), (void*)uid);
		samplingNow = true;
		write(currentSample, uid);
		write(currentSample, item);
		write(currentSample, (uintptr)0);
		write(currentSample, size);

		AvmAssertMsg((uintptr)currentSample % 4 == 0, "Alignment should have occurred at end of raw sample.\n");
		numSamples++;

		return uid; 
	}

	uint64 Sampler::recordAllocationInfo(AvmPlusScriptableObject *obj, uintptr typeOrVTable)
	{
		AvmAssertMsg(sampling, "How did we get here if sampling is disabled?");
		if(!samplingNow)
			return 0;

		if( !samplingAllAllocs )
		{
			// Turn on momentarily to record the alloc for this object.
			samplingAllAllocs = true;
			recordAllocationSample(obj, 0);
			samplingAllAllocs = false;
		}

		byte* old_sample = lastAllocSample;
		Sample s;
		readSample(old_sample, s);
		old_sample = lastAllocSample;

#ifdef DEBUGGER					
		if(typeOrVTable < 7 && core->codeContext() && core->codeContext()->domainEnv()) {
			// and in toplevel
			// FIXME 64bit
			typeOrVTable |= (uint32)(uintptr_t)core->codeContext()->domainEnv()->toplevel();
		}
#endif
		AvmAssertMsg(s.sampleType == NEW_AUX_SAMPLE, "Sample stream corrupt - can only add info to an AUX sample.\n");
		AvmAssertMsg(s.ptr == (void*)obj, "Sample stream corrupt - last sample is not for same object.\n");

		byte* pos = currentSample;
		currentSample = old_sample;
		// Rewrite the sample as a NEW_OBJECT_SAMPLE
		writeRawSample(NEW_OBJECT_SAMPLE);

		write(currentSample, s.id);

		samplingNow = false;
		AvmAssertMsg( ptrSamples->get(GetRealPointer(obj))==0, "Missing dealloc sample - same memory alloc'ed twice.\n");
		ptrSamples->add(GetRealPointer(obj), currentSample);
		samplingNow = true;

		write(currentSample, s.ptr);

		write(currentSample, typeOrVTable);
		write(currentSample, s.alloc_size);

		AvmAssertMsg((uintptr)currentSample % 4 == 0, "Alignment should have occurred at end of raw sample.\n");
		currentSample = pos;

		return s.id;
	}

	void Sampler::recordDeallocationSample(const void* item, uint64 size)
	{
		AvmAssertMsg(sampling, "How did we get here if sampling is disabled?");
		AvmAssert(item != 0);
		// recordDeallocationSample doesn't honor the samplingNow flag
		// this is to avoid dropping deleted object samples when sampling is paused.
		uint64 uid = (uint64)uids.get(item);
		// If we didn't find a UID then this wasn't memory that the sampler knew was allocated
		if(uid && sampleSpaceCheck(false)) {

			
//			if( !uid )
//				uid = (uint64)-1;

			writeRawSample(DELETED_OBJECT_SAMPLE);
			write(currentSample, uid);
			write(currentSample, size);

			numSamples++;

			AvmAssertMsg((uintptr)currentSample % 4 == 0, "Alignment should have occurred at end of raw sample.\n");
		}

		// Nuke the ptr in the sample stream for the newobject sample
		if( samples->start() )
		{

		byte* oldptr = 0;
		if( (oldptr = (byte*)ptrSamples->get(item)) != 0 )
		{
#ifdef _DEBUG
				void* oldval = 0;
				read(oldptr, oldval);
				AvmAssertMsg(GetRealPointer(oldval)==item, "Sample stream corrupt, dealloc doesn't point to correct address");
				rewind(oldptr, sizeof(void*));
#endif
			write(oldptr, (void*)0);
			ptrSamples->remove(item);
		}
		}
		if(uid)
			uids.remove(item);
	}

	void Sampler::clearSamples()
	{
		//samples->free();
		currentSample = samples->start();
		GCHashtable* t = ptrSamples;
		ptrSamples = new MMgc::GCHashtable(4096);
		delete t;
		numSamples = 0;
	}

	void Sampler::startSampling()
	{
		if(!sampling || samplingNow)
			return;

		{
			init(sampling, autoStartSampling);
		}

		if (!currentSample)
		{
			int megs=16;
			while(!currentSample && megs > 0) {
				currentSample = samples->reserve(megs * 1024 * 1024);
				megs >>= 1;
			}
			if(!currentSample) {
				sampling = autoStartSampling = false;
				samples->free();
				return;
			}
		}
		
		if( !ptrSamples ) 
		{
			ptrSamples = new MMgc::GCHashtable(1024);
		}

		MMgc::sampling = true;
		samplingNow = true;
		if(timerHandle == 0)
			timerHandle = OSDep::startIntWriteTimer(1, &takeSample);
	}

	void Sampler::pauseSampling()
	{
		if(!sampling || !samplingNow)
			return;
		samplingNow = false;
	}

	void Sampler::sampleInternalAllocs(bool b)
	{
		samplingAllAllocs = b;
	}

	void Sampler::setCallback(ScriptObject* callback)
	{
		this->callback = callback;
	}

	void Sampler::stopSampling()
	{
		if(!sampling)
			return;

		if(timerHandle != 0) {
			OSDep::stopTimer(timerHandle);
			timerHandle = 0;
		}

		samples->free();

		if( ptrSamples ) {
			delete ptrSamples;
			ptrSamples = 0;
		}

		MMgc::sampling = false;
		samplingNow = false;
		numSamples = 0;
		currentSample = NULL;
	}

	void Sampler::initSampling()
	{
		if(!sampling)
			return;

		// prime fake function table

		createFakeFunction("XML");
		createFakeFunction("Array");
		createFakeFunction("Date");

		createFakeFunction("[mark]");
		createFakeFunction("[sweep]");
		createFakeFunction("[reap]");
		createFakeFunction("[generate]");
		createFakeFunction("[verify]");
		createFakeFunction("[newclass]");

		createFakeFunction("[activation-object]");

		if(autoStartSampling) {
			startSampling();
		}
		return;
	}

	void Sampler::createFakeFunction(const char *name)
	{
		if(!sampling)
			return;

		Stringp s = core->constantString(name);
		// save it in m_fakeMethodNames just to be sure it isn't cleared from the intern-name list.
		if (m_fakeMethodNames.indexOf(s) < 0)
			m_fakeMethodNames.add(s);
	}

	Stringp Sampler::getFakeFunctionName(const char* name)
	{
		// this can't make any allocations, it's called from sensitive areas (like from 
		// the GC marking routines).  For one we'll recurse but also GC state can get messed
		// up if for instance the allocation triggers a collection
		Stringp name_str = core->findInternedString(name, (int)strlen(name));
		if (name_str != NULL)
		{
			sampleCheck();
		}
		return name_str;
	}

	/* sample data has pointers need to scan */
	void Sampler::presweep()
	{
		uint32 num;
		byte *p = getSamples(num);
		for(uint32 i=0; i < num ; i++)
		{
			Sample s;
			readSample(p, s);			
			if(s.sampleType == NEW_OBJECT_SAMPLE) {
				// keep all weak refs and type's live, in postsweep we'll erase our weak refs
				// to objects that were finalized.  we can't nuke them here b/c pushing the
				// types could cause currently unmarked things to become live
				if (s.typeOrVTable > 7 && !GC::GetMark((void*)s.typeOrVTable))
				{
					GCWorkItem item((void*)s.typeOrVTable, (uint32)GC::Size((void*)s.typeOrVTable), true);
					core->gc->PushWorkItem(item);
				}
			}
		}
	}

	void Sampler::postsweep()
	{
	}
}
#endif
