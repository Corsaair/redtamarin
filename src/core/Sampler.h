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

#ifndef __avmplus_Sampler__
#define __avmplus_Sampler__

namespace avmplus
{
#ifdef FEATURE_SAMPLER

	// This structure is used to read/write data to the sample stream.
	// The fields are written out to the sample stream as they are defined here.  
	struct Sample
	{
		uint64 micros;
		uint32 sampleType;
		union {
			// not filled in for sampleType==DELETED_OBJECT_SAMPLE
			struct {
				// Number of StackTraceElements in the trace
				uint32 depth;
				// Beginning of an array of StackTraceElement.  Basically, an AbstractFunction*, Stringp, Stringp, uint32 for each entry. 
				void *trace; 
			} stack;
			// deleted object size record, instead of stack
			uint64 size; 
		};
		// filled for DELETED_OBJECT_SAMPLE + NEW_OBJECT_SAMPLE
		uint64 id; 

		// Following three fields are only filled in for sampleType==NEW_OBJECT_SAMPLE or NEW_AUX_SAMPLE
		// They are not present in the sample stream for other sample types
		uintptr typeOrVTable;
		void *ptr;
		uint64 alloc_size; // size for new mem sample
	};

	class Sampler
	{
	public:
		Sampler(MMgc::GC *);
		~Sampler();

		enum SampleType 
		{ 
			RAW_SAMPLE=0x55555555,
			NEW_OBJECT_SAMPLE=0xaaaaaaaa, 
			DELETED_OBJECT_SAMPLE=0xdddddddd,
			NEW_AUX_SAMPLE=0xeeeeeeee
		};
		
		// are we sampling at all
		bool sampling;

		// if true we call startSampling as early as possible during startup
		bool autoStartSampling;

		// should use opaque Cursor type instead of byte*
		byte *getSamples(uint32 &num);
		void readSample(byte *&p, Sample &s);
		
		void setCore(AvmCore *core);
		void init(bool sampling, bool autoStart);
		void sampleCheck() { if(takeSample) sample(); }

		uint64 recordAllocationInfo(AvmPlusScriptableObject *obj, uintptr typeOrVTable);
		uint64 recordAllocationSample(void* item, uint64 size, bool callback_ok = true);
		void recordDeallocationSample(const void* item, uint64 size);

		void startSampling();
		void stopSampling();
		void clearSamples();
		void pauseSampling();

		void sampleInternalAllocs(bool b);

		void setCallback(ScriptObject* callback);

		
		// called by VM after initBuiltin's
		void initSampling();

		void createFakeFunction(const char *name);
		Stringp getFakeFunctionName(const char* name);

		void presweep();
		void postsweep();

		uint32 sampleCount() const { return numSamples; }
		bool activelySampling() { return samplingNow; }
		
	private:	
		
		static void inline align(byte*&b)
		{
			if((sintptr)b & 4)
			{
#ifdef DEBUG
				*(int32*)b = 0xaaaaaaaa;
#endif
				b += sizeof(int32);
			}
		}
		
		template<class T>
		static void inline read(byte *&p, T &u)
		{
			u = *(T*)p;
			p += sizeof(T);
		}

		template<class T>
		static void inline write(byte *&p, T u)
		{
			*(T*)p = u;
			p += sizeof(T);
		}
		
		
		AvmCore *core;

		uint64 allocId;
				
		bool samplingNow;
		bool samplingAllAllocs;
		int takeSample;
		uint32 numSamples;
		GrowableBuffer* samples;
		byte *currentSample;
		byte *lastAllocSample;
		bool runningCallback;
		DRC(ScriptObject*) callback;
		void sample();

		uintptr timerHandle;
		MMgc::GCHashtable uids;
		MMgc::GCHashtable* ptrSamples;
		
		void rewind(byte*&b, uint32 amount)
		{
			b -= amount;
		}

		int sampleSpaceCheck(bool callback_ok = true);
		
		void writeRawSample(SampleType sampleType);

	private:
		List<Stringp> m_fakeMethodNames; 
	};

#define SAMPLE_FRAME(_strp, _core) avmplus::CallStackNode __fcsn((avmplus::AvmCore*)_core, _strp)
#define SAMPLE_CHECK()  __fcsn.sampleCheck();

#else

#define SAMPLE_FRAME(_x, _s) 
#define SAMPLE_CHECK()

#endif // DEBUGGER
}
#endif // __avmplus_Sampler__
