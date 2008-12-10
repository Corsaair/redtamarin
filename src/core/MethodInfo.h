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

#ifndef __avmplus_MethodInfo__
#define __avmplus_MethodInfo__


namespace avmplus
{
#ifdef DEBUGGER
	class AbcFile;
#endif

	/**
	 * The MethodInfo class represents a method or function written
	 * in ActionScript code.
	 */
	class MethodInfo : public AbstractFunction
	{
	public:
#ifdef DEBUGGER
		AbcFile* getFile() { return file; }
		void setFile(AbcFile* file) { this->file = file; }

		Stringp getLocalName(int index) const;
		Stringp getArgName(int index) const;
		Stringp getRegName(int index) const;
		void setRegName(int index, Stringp name);

		void boxLocals(void* src, int srcPos, Traits** traitArr, Atom* dest, int destPos, int length);
		void unboxLocals(Atom* src, int srcPos, Traits** traitArr, void* dest, int destPos, int length);
#endif // DEBUGGER
		
#ifdef AVMPLUS_WORD_CODE
		struct 
		{
			const uintptr_t *body_pos; // NULL iff not yet translated
			DWB(GCObject*) code_anchor;  // The object that contains the code pointed to by body_pos
			int cache_size;              // Number of items in lookup cache
			// We write this once, in WordcodeTranslator, with an explicit WB.  so no DWB.
			// The contents are the same as the 'exceptions' structure below, except the 'from', 'to', and 'target' fields.
			ExceptionHandlerTable* exceptions;
		} word_code;
#endif

		MethodInfo();

		static Atom verifyEnter(MethodEnv* env, int argc, uint32 *ap);

		void verify(Toplevel* toplevel);
        void setInterpImpl();

#ifdef DEBUGGER
		virtual uint32 size() const;
		void initLocalNames();
#endif // DEBUGGER

	// ------------------------ DATA SECTION BEGIN
	public:
		const uint8_t*			body_pos;
		ExceptionHandlerTable*	exceptions;			// we write this once, in Verifier, with an explicit WB.  so no DWB.
		uint32_t				frameSize;			// total size of frame in number of Atoms
		uint32_t				localCount;			// maximum number of local registers
		uint32_t				maxScopeDepth;		// maximum depth of local scope stack
#ifdef AVMPLUS_WORD_CODE
		const uintptr_t*        codeStart;			// pointer to first instruction
#else
		const uint8_t*			codeStart;			// ditto
#endif
#ifdef DEBUGGER
	protected:
		DWB(AbcFile*)			file;				// the abc file from which this method came
		DWB(Stringp*)			localNames;			// array of names for args and locals in framep order
	public:
		int32_t					firstSourceLine;	// source line number where function starts
		int32_t					lastSourceLine;		// source line number where function ends
		int32_t					offsetInAbc;		// offset in abc file
		uint32_t				codeSize;			// abc size pre-jit, native size post jit
		int32_t					local_count;		// FIXME: merge with localCount above; this one may be visible to a debugger?
		int32_t					max_scopes;			// FIXME: merge with maxScopeDepth above; this one is not used by the VM but may be visible to a debugger?
#endif
	// ------------------------ DATA SECTION END
	};
}

#endif /* __avmplus_MethodInfo__ */
