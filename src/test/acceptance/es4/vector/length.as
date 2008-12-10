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
 * Portions created by the Initial Developer are Copyright (C) 2007-2008
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
/**
   Description:
   15.4.5.2 length
   The length property of this Array object is always numerically greater
   than the name of every property whose name is an array index.
*/

var SECTION = "15.4.5.2-1";
var VERSION = "ECMA_1";
startTest();
var TITLE   = "Vector.length";

writeHeaderToLog( SECTION + " "+ TITLE);


var v1=new Vector.<int>();
AddTestCase(	"length of empty vector",
		0,
		v1.length);

var v1=new Vector.<int>(1999);
AddTestCase(	"length of initialized vector of size 1999",
		1999,
		v1.length);

var v1=new Vector.<int>(1999);
v1.push(1);
AddTestCase(	"length of initialized vector",
		2000,
		v1.length);

var v1=new Vector.<int>();
for (var i=0;i<100;i++) v1[i]=i;
AddTestCase(	"length of empty vector with 100 elements set",
		100,
		v1.length);

var v1=new Vector.<int>(100,true);
AddTestCase(	"length of fixed size vector",
		100,
		v1.length);

var v1=new Vector.<int>();
for (var i=0;i<10;i++) v1[i]=i;
v1.length=5;
AddTestCase(	"reduce length of vector removes elements reduces length",
		5,
		v1.length);
AddTestCase(	"reduce length of vector removes elements past new length",
		"0,1,2,3,4",
		v1.toString());
v1.length=10;
AddTestCase(	"increase length of array with removed elements increases length",
		10,
		v1.length);
AddTestCase(	"increase length of array with removed elements adds empty elements",
		"0,1,2,3,4,0,0,0,0,0",
		v1.toString());

test();

