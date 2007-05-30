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
 *   zwetan <zwetan@gmail.com>
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

#ifndef __avmshell_StandardClass__
#define __avmshell_StandardClass__


namespace avmshell
{
	/**
	 * A simple class providing native methods to the C standard libs.
	 */
	class StandardClass : public ClassClosure
	{
    public:
		StandardClass(VTable* cvtable);
		
		/**
		 * Implementation of errno
		 */
		int std_errno();

		/**
		 * Implementation of strerror
		 */
		Stringp std_strerror(int errnum);

		/**
		 * Implementation of getcwd
		 */
		Stringp std_getcwd();
		
		/**
		 * Implementation of getdcwd
		 */
		Stringp std_getdcwd(int drive);
		
		/**
		 * Implementation of chdir
		 */
		int std_chdir(Stringp pathname);
		
		/**
		 * Implementation of chdrive
		 */
		int std_chdrive(int newdrive);
		
		/**
		 * Implementation of getdrive
		 */
		int std_getdrive();
		
		/**
		 * Implementation of getdrives
		 */
		ArrayObject * std_getdrives();

		/**
		 * Implementation of sleep
		 */
		void std_sleep(double time);
		/**
		 * Implementation of fopen
		 */
		//Stringp fopen(Stringp filename, Stringp mode);
        
		DECLARE_NATIVE_MAP(StandardClass)
    };
}

#endif /* __avmshell_StandardClass__ */
