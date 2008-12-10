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

#ifndef __avmplus_StringClass__
#define __avmplus_StringClass__


namespace avmplus
{
	/**
	 * class StringClass
	 */
    class StringClass : public ClassClosure
    {
	public:
		StringClass(VTable* cvtable);

		// this = argv[0]
		// arg1 = argv[1]
		// argN = argv[argc]
        Atom call(int argc, Atom* argv);

		// this = argv[0] (ignored)
		// arg1 = argv[1]
		// argN = argv[argc]
		Atom construct(int argc, Atom* argv);
		
		// native methods.  see String.as
		ArrayObject* _match(Stringp s, Atom pattern);
		Stringp _replace(Stringp in, Atom pattern, Atom replacementAtom);
		int _search(Stringp in, Atom regexpAtom);
		ArrayObject* _split(Stringp in, Atom delimAtom, uint32 limit);

		// defined via rest args to allow length = 1 and support calling with no args... ES3 spec says length = 1
		Stringp AS3_fromCharCode(Atom *argv, int argc);

		inline Stringp fromCharCode(Atom *argv, int argc) { return AS3_fromCharCode(argv, argc); }
	};
}

#endif /* __avmplus_StringClass__ */
