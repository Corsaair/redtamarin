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

#ifndef __avmplus_SamplerScript__
#define __avmplus_SamplerScript__

namespace avmplus
{
	class TraceClass : public ClassClosure
	{
    public:
		TraceClass(VTable* cvtable);

		int getLevel(int target);
		void setLevel(int lvl, int target);
		void setListener(ScriptObject* f);
		ScriptObject* getListener();
    };

	class SamplerScript : public ScriptObject
	{
	private:
		bool trusted() { return toplevel()->sampler_trusted(this); }
		
	public:
		SamplerScript(VTable *vtable, ScriptObject *delegate);

#ifdef FEATURE_SAMPLER
		static const uint32 GET=1;
		static const uint32 SET=2;
		double getSize(Atom o);
		Atom getMemberNames(Atom o, bool instanceNames);
		Atom getSamples();
		void clearSamples();
		void startSampling();
		void stopSampling();
		void pauseSampling();
		void sampleInternalAllocs(bool b);
		double getSampleCount();
		void _setSamplerCallback(ScriptObject *callback);

		double _getInvocationCount(Atom a, QNameObject* qname, uint32 type);
		ScriptObject *makeSample(Sample sample);
		bool isGetterSetter(Atom a, QNameObject* name);
	private:		
		DWB(VTable*) const sampleIteratorVTable;
		DWB(VTable*) const slotIteratorVTable;
		ClassClosure *getType(Atom typeOrVTable, const void *obj);
#else
		// stubs for release
		double getSize(Atom ) { return 0; }
		Atom getMemberNames(Atom, bool) { return undefinedAtom; }
		Atom getSamples() { return undefinedAtom; }
		void clearSamples() {}
		void startSampling() {}
		void stopSampling() {}
		void pauseSampling() {}
		double getSampleCount() { return -1; }
		double _getInvocationCount(Atom, QNameObject*, uint32) { return -1; }
		bool isGetterSetter(Atom, QNameObject*) { return false; }
		void sampleInternalAllocs(bool){};
		void _setSamplerCallback(ScriptObject *){};
#endif
	};

	class SampleClass : public ClassClosure
	{
	public:
		SampleClass(VTable *vtable);
		ScriptObject *createInstance(VTable *ivtable, ScriptObject *delegate);
		
		int typeOffset, stackOffset, timeOffset, idOffset, sizeOffset;
		int nameOffset, fileOffset, lineOffset;
	};
	typedef SampleClass DeleteObjectSampleClass;

	class SampleObject : public ScriptObject
	{
	public:
		SampleObject(VTable *vtable, ScriptObject *delegate);
	};
	typedef SampleObject DeleteObjectSampleObject;

	class NewObjectSampleObject : public SampleObject
	{
	public:
		NewObjectSampleObject(VTable *vtable, ScriptObject *delegate);
		Atom get_object();
		double get_size();
		void setRef(AvmPlusScriptableObject* o) { obj = o; }
		void setSize(uint64 s) { size = s; }
	private:
		DRCWB(AvmPlusScriptableObject*) obj;
		uint64 size;
	};

	class NewObjectSampleClass : public SampleClass
	{
	public:
		NewObjectSampleClass(VTable *vtable);
		ScriptObject *createInstance(VTable *ivtable, ScriptObject *delegate);
	};
}
#endif // __avmplus_SamplerScript__
