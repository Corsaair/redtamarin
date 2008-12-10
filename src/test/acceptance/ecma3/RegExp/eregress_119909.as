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
 * The Original Code is [Open Source Virtual Machine].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2005-2006
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
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
 * ***** END LICENSE BLOCK *****
*
*
* Date:    14 Jan 2002
* SUMMARY: Shouldn't crash on regexps with many nested parentheses
* See http://bugzilla.mozilla.org/show_bug.cgi?id=119909
*
*/
//-----------------------------------------------------------------------------

var SECTION = "eregress_119909";
var VERSION = "";
var TITLE   = "Shouldn't crash on regexps with many nested parentheses";
var bug = "119909";

startTest();
writeHeaderToLog(SECTION + " " + TITLE);
var testcases = getTestCases();
test();

function getTestCases() {
	var array = new Array();
	var item = 0;

	var NO_BACKREFS = false;
	var DO_BACKREFS = true;


	//--------------------------------------------------

	testThis(500, NO_BACKREFS, 'hello', 'goodbye');
	testThis(500, DO_BACKREFS, 'hello', 'goodbye');

	//--------------------------------------------------

	/*
	 * Creates a regexp pattern like (((((((((hello)))))))))
	 * and tests str.search(), str.match(), str.replace()
	 */
	function testThis(numParens, doBackRefs, strOriginal, strReplace)
	{
	  var openParen = doBackRefs? '(' : '(?:';
	  var closeParen = ')';
	  var pattern = '';

	  for (var i=0; i<numParens; i++) {pattern += openParen;}
	  pattern += strOriginal;
	  for (i=0; i<numParens; i++) {pattern += closeParen;}
	  var re = new RegExp(pattern);
	
	  if (doBackRefs) {
		  var res = strOriginal.search(re);
		  array[item++] = new TestCase(SECTION, "strOriginal.search(re)", -1, res);

		  res = strOriginal.match(re);
		  array[item++] = new TestCase(SECTION, "strOriginal.match(re)", null, res);

		  res = strOriginal.replace(re, strReplace);
		  array[item++] = new TestCase(SECTION, "strOriginal.replace(re, strReplace)", "hello", res);
	  } else {
	  	  var res = strOriginal.search(re);
		  array[item++] = new TestCase(SECTION, "strOriginal.search(re)", 0, res);

		  res = strOriginal.match(re);
		  //Get the first element to compare
		  res = res[0];
		  array[item++] = new TestCase(SECTION, "strOriginal.match(re)", 'hello', res);

		  res = strOriginal.replace(re, strReplace);
		  array[item++] = new TestCase(SECTION, "strOriginal.replace(re, strReplace)", "goodbye", res);
	
	  }
	}

	return array;
}
