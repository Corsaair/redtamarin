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


package 
{
	[native(cls="NamespaceClass", instance="Namespace", methods="auto")]
	public final class Namespace
	{
		// E262 {ReadOnly,DontDelete,DontEnum}
		// E357 length = 2
		public static const length = 2 
		
		// E357 {DontDelete, ReadOnly}
		public native function get prefix()

		// E357 {DontDelete, ReadOnly}
		public native function get uri():String

		AS3 function valueOf():String { return uri }

		prototype.valueOf = function():String
		{
			if (this === prototype) return ""
			var n:Namespace = this
			return n.uri;
		}

		AS3 function toString():String
		{
			return uri
		}
		
		prototype.toString = function ():String
		{
			if (this === prototype) return ""
			var n:Namespace = this
			return n.uri;
		}

        // Dummy constructor function - This is neccessary so the compiler can do arg # checking for the ctor in strict mode
        // The code for the actual ctor is in NamespaceClass::construct in the avmplus
        public function Namespace(prefix = void 0, uri = void 0 )
        {}
        
        _dontEnumPrototype(prototype);
	}
}
