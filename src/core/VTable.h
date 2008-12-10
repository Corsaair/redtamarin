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

#ifndef __avmplus_VTable__
#define __avmplus_VTable__


namespace avmplus
{
#ifdef AVMPLUS_TRAITS_MEMTRACK
	class VTable : public MMgc::GCFinalizedObject
#else
	class VTable : public MMgc::GCObject
#endif
	{
		MethodEnv *makeMethodEnv(AbstractFunction *method);
		void addInterface(AbstractFunction* virt, int disp_id);

	public:
		VTable(Traits* traits, VTable* base, ScopeChain* scope, AbcEnv* abcEnv, Toplevel* toplevel);
#ifdef AVMPLUS_TRAITS_MEMTRACK 
		virtual ~VTable();
#endif
		void resolveSignatures();

		inline size_t getExtraSize() const { return traits->getExtraSize(); }
		inline MMgc::GC *gc() const { return traits->core->GetGC(); }

#ifdef AVMPLUS_VERBOSE
		Stringp format(AvmCore* core) const
		{
			return traits->format(core);
		}
#endif

#ifdef DEBUGGER
		uint32 size() const;
#endif

	// ------------------------ DATA SECTION BEGIN
	public:
		DWB(AbcEnv*) abcEnv;
		DRCWB(Toplevel*) toplevel;   // not const because native ClassClosure ctors modify it
		DWB(MethodEnv*) call;
		DWB(MethodEnv*) init;
		DWB(ScopeChain*) scope;
		DWB(VTable*) base;
		DWB(VTable*) ivtable;
		Traits* const traits;
		bool linked;	// @todo -- surely there's a spare bit we can use for this.
		bool pad[3];

#if defined(AVMPLUS_MIR) || defined(FEATURE_NANOJIT)
		MethodEnv* imt[Traits::IMT_SIZE];
#endif
		MethodEnv* methods[1]; // virtual method table
	// ------------------------ DATA SECTION END
	};

}

#endif // __avmplus_VTable__

