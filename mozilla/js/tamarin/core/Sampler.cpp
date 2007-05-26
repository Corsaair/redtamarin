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

#ifdef DEBUGGER
namespace avmplus
{
	using namespace MMgc;

	Sampler::Sampler()
	{
		// fixed (AvmCore) memory, clear out
		memset(this, 0, sizeof(Sampler));
		allocId = 1;
	}

	Sampler::~Sampler()
	{
		stopSampling();
		delete samples;
	}

	void Sampler::init(bool sampling, bool autoStart)
	{
		this->sampling = sampling;
		this->autoStartSampling = autoStart;
		if(sampling)
		{
			if (!samples)
			{
				samples = new (core->GetGC()) GrowableBuffer(core->GetGC()->GetGCHeap());
				fakeMethodInfos = new (core->GetGC()) Hashtable(core->GetGC());
				stackTraces = (StackTrace**)core->GetGC()->Alloc(sizeof(StackTrace*) * 1024, GC::kZero);
				currentSample = samples->reserve(64 * 4096 * 4096);
			}
		}
	}

	byte *Sampler::getSamples(uint32 &num)
	{
		num = numSamples;
		byte *start = samples ? samples->start() : NULL;
		return start;
	}

	void Sampler::sample()
	{
		if(!sampling || !samplingNow || !core->callStack)
			return;
	
		writeRawSample(RAW_SAMPLE);
		numSamples++;
	}

	void Sampler::sampleSpaceCheck()
	{
		uint32 sampleSize = sizeof(Sample);
		uint32 callStackDepth = core->callStack ? core->callStack->depth : 0;
		sampleSize += callStackDepth * sizeof(StackTrace::Element);
		sampleSize += sizeof(uint64) * 2;
		if(currentSample + sampleSize > samples->uncommitted()) {
			samples->grow();
			if(currentSample + sampleSize > samples->uncommitted()) {
				// exhausted buffer
				return;
			}
		}
	}

	void Sampler::writeRawSample(SampleType sampleType)
	{
		if(!sampling || !samplingNow)
			return;
		sampleSpaceCheck();
		CallStackNode *csn = core->callStack;
		uint32 depth = csn ? csn->depth : 0;
		byte *p = currentSample;
		write(p, GC::ticksToMicros(GC::GetPerformanceCounter()));
		write(p, sampleType);
		if(sampleType != DELETED_OBJECT_SAMPLE)
		{
			write(p, depth);
			while(csn)
			{
				write(p, (uintptr)csn->info);
				// FIXME: can filename can be stored in the AbstractInfo?
				write(p, csn->filename);
				write(p, csn->linenum);
				csn = csn->next;
				depth--;
			}
			AvmAssert(depth == 0);
		}
		// padding to keep 8 byte alignment
		align(p);
		currentSample = p;
		takeSample = 0;
	}

	void Sampler::readRawSample(byte *&p, Sample &s)
	{
		read(p, s.micros);
		read(p, s.type);
		AvmAssertMsg(s.type == RAW_SAMPLE || s.type == NEW_OBJECT_SAMPLE || s.type == DELETED_OBJECT_SAMPLE, "Sample stream corruption.\n");
		if(s.type != DELETED_OBJECT_SAMPLE)
		{
			read(p, s.depth);
			s.trace = p;
			p += s.depth * sizeof(StackTrace::Element);
		}
		// padding to keep 8 byte alignment
		align(p);
	}

	uint64 Sampler::recordAllocationSample(AvmPlusScriptableObject *obj, Traits *traits)
	{
		if(!sampling || !samplingNow)
			return 0;

		sampleSpaceCheck();
		writeRawSample(NEW_OBJECT_SAMPLE);
		write(currentSample, allocId++);
		// disable sampling across weak ref alloc
		// TODO: investigate not pounding on weak refs
		AvmAssert(sampling);
		sampling = false;
		GCWeakRef *weakRef = obj->GetWeakRef();
		AvmAssertMsg(weakRef != NULL, "Null weak reference when recording allocation sample.\n");
		write(currentSample, weakRef);
		sampling = true;
		write(currentSample, traits);
		AvmAssertMsg((uintptr)currentSample % 4 == 0, "Alignment should have occurred at end of raw sample.\n");
		numSamples++;

		return allocId-1; // GetWeakRef might cause GC which will traverse samples, ++ early
	}

	void Sampler::recordDeallocationSample(uint64 id)
	{
		if(!sampling || !samplingNow)
			return;
	
		sampleSpaceCheck();
		writeRawSample(DELETED_OBJECT_SAMPLE);
		write(currentSample, id);
		AvmAssertMsg((uintptr)currentSample % 4 == 0, "Alignment should have occurred at end of raw sample.\n");
		numSamples++;
	}

	void Sampler::clearSamples()
	{
		currentSample = samples->start();
		numSamples = 0;
	}

	void Sampler::startSampling()
	{
		if(!sampling || samplingNow)
			return;

		numSamples = 0;
		samplingNow = true;
		if(!samples->start()) {
			currentSample = samples->reserve(64 * 4096 * 4096);
		}
		timerHandle = OSDep::startIntWriteTimer(1, &takeSample);
	}

	void Sampler::stopSampling()
	{
		if(!sampling || !samplingNow)
			return;
		OSDep::stopTimer(timerHandle);
		samplingNow = false;
	}

	void Sampler::initSampling()
	{
		if(sampling) {
			if(autoStartSampling) {
				startSampling();
			}
		}
	}

	void Sampler::rehashTraces(int newSize)
	{
		uint32 oldNumTraces = numTraces;
		numTraces = 0;
		StackTrace **oldStackTraces = stackTraces;
		stackTraces = (StackTrace**)core->GetGC()->Calloc(newSize, sizeof(StackTrace*), GC::kZero);

		uint32 bitMask = newSize-1;

		for(uint32 i=0, n=oldNumTraces; i<n; i++)
		{
			StackTrace *t = oldStackTraces[i];
			if(t)
			{
				uint32 j = (StackTrace::hashCode(t->elements, t->depth)&0x7FFFFFFF) & bitMask;
				uint32 n = 7;
				while (stackTraces[j] != NULL) {
					j = (j + (n++)) & bitMask; // quadratic probe
				}
				stackTraces[j] = t;
			}
		}
		numTraces = oldNumTraces;
	}

	int Sampler::findTrace(void /*StackTrace::Element*/ *ve, int depth)
	{
		StackTrace::Element *e = (StackTrace::Element*)ve;
		uint32 sizeTraces = core->GetGC()->Size(stackTraces)/sizeof(StackTrace*);
		uint32 shift = AvmCore::FindOneBit(sizeTraces);
		uint32 bitMask = (1<<shift)-1;
		if(numTraces*4 > bitMask*3)
		{
			rehashTraces((bitMask+1)*2);
			sizeTraces = core->GetGC()->Size(stackTraces)/sizeof(StackTrace*);
			shift = AvmCore::FindOneBit(sizeTraces);
			bitMask = (1<<shift)-1;
		}

		uintptr hashCode = StackTrace::hashCode(e, depth);
		uint32 j = (hashCode&0x7FFFFFFF) & bitMask;
		uint32 n = 7;
		while (stackTraces[j] != NULL && !stackTraces[j]->equals(e,depth)) {
			j = (j + (n++)) & bitMask; // quadratic probe
		}
		return j;
	}

	StackTrace* Sampler::getStackTrace(void /*StackTrace::Element*/ *ve, int depth)
	{
		StackTrace::Element *e = (StackTrace::Element*)ve;
		int i = findTrace(e, depth);
		StackTrace *t = stackTraces[i];
		if(t)
			return t;

		int extra = depth > 0 ? sizeof(StackTrace::Element) * (depth-1) : 0;
		t = new (core->GetGC(), extra) StackTrace();
		t->depth = depth;
		memcpy(t->elements, e, extra + sizeof(StackTrace::Element));
		stackTraces[i] = t;
		numTraces++;
		return t;
	}

	StackTrace* Sampler::getStackTrace()
	{
		if(core->callStack)
		{
			StackTrace::Element *elements = (StackTrace::Element*)alloca(core->callStack->depth * sizeof(StackTrace::Element));
			StackTrace::Element *e = elements;
			CallStackNode *curr = core->callStack;
			while (curr) {
				e->info	= curr->info;
				e->filename = curr->filename;
				e->linenum = curr->linenum;
				e++;
				curr = curr->next;
			}

			int i = findTrace(elements, core->callStack->depth);
			StackTrace *t = stackTraces[i];
			if(t)
				return t;
			StackTrace *st = core->newStackTrace();
			stackTraces[i] = st;
			numTraces++;
			return st;
		}
		return NULL;
	}

	AbstractFunction *Sampler::createFakeFunction(const char *name)
	{
		if(!sampling || !core->builtinPool)
			return NULL;

		// have to turn sampling off during allocations to avoid recursion
		AvmAssert(sampling);
		sampling = false;
		Stringp s = core->internAllocAscii(name);
		Atom a = fakeMethodInfos->get(s->atom());
		AbstractFunction *af = (AbstractFunction*)AvmCore::atomToGCObject(a);
		if(!af)
		{
			af = new (core->GetGC()) FakeAbstractFunction();
			a = AvmCore::gcObjectToAtom(af);
			fakeMethodInfos->add(s->atom(), a);
			af->name = s;
			af->pool = core->builtinPool;
		}
		sampling = true;
		sampleCheck();
		return af;
	}

	FakeCallStackNode::FakeCallStackNode(AvmCore *core, const char *name)
	{
		memset(this, 0, sizeof(FakeCallStackNode));
		this->core = core;
		if(core)
		{
			AbstractFunction *af = core->sampler()->createFakeFunction(name);
			if(af)
				initialize(NULL, af, NULL, NULL, 0, NULL, NULL);
			else {
				// this is how the dtor knows what to do
				this->core = NULL;
			}
		}
	}

	FakeCallStackNode::~FakeCallStackNode()
	{
		if(core)
		{
			exit();
			core->sampleCheck();
		}
	}

	/* sample data has pointers need to scan */
	void Sampler::presweep()
	{
		uint32 num;
		byte *p = getSamples(num);
		for(uint32 i=0; i < num ; i++)
		{
			Sample sample;
			readRawSample(p, sample);
			uint64 id;
			GCWeakRef *weakRef;
			Traits* type;
			if(sample.type != RAW_SAMPLE)
			{
				read(p, id);
				AvmAssert(id < allocId);
				if(id >= allocId) AvmAssert(false);
				if(sample.type == NEW_OBJECT_SAMPLE) {
					read(p, weakRef);
					// keep weak refs to objects still around
					if(weakRef)
					{
						if (weakRef->get() && GC::GetMark(weakRef->get()))
						{
							GC::SetMark(weakRef);
						}
						else
						{
							rewind(p, sizeof(GCWeakRef*));
							write(p, (uint32)0);
						}
					}
					read(p, type);
				}
			}
			align(p);
		}

		if(stackTraces)
		{
			uint32 n = GC::Size(stackTraces)/sizeof(StackTrace*);
			n = 1<<AvmCore::FindOneBit(n);
			bool rehash= false;
			for (uint32 i=0; i<n; i++)
			{
				if(stackTraces[i] && !GC::GetMark(stackTraces[i]))
				{
					rehash = true;
					stackTraces[i] = NULL;
				}
			}
			if(rehash)
				rehashTraces(n);
		}
	}

	void Sampler::postsweep()
	{
		uint32 num;
		byte *p = getSamples(num);

		for(uint32 i=0; i < num ; i++)
		{
			Sample sample;
			readRawSample(p, sample);
			uint64 id;
			GCWeakRef *weakRef;
			Traits* type;
			if(sample.type != RAW_SAMPLE)
			{
				read(p, id);
				AvmAssert(id < allocId);
				if(id >= allocId) AvmAssert(false);
				if(sample.type == NEW_OBJECT_SAMPLE) {
					read(p, weakRef);
					if(weakRef && !weakRef->get())
					{
						AvmDebugMsg(false, "Sampler::postsweep: found weak ref with null object.\n");
						rewind(p, sizeof(GCWeakRef*));
						write(p, (uint32)0);
					}
					read(p, type);
				}
			}
			align(p);
		}
	}
}
#endif
