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
 * The Original Code is mozilla.org code.
 *
 * The Initial Developer of the Original Code is
 * Netscape Communications Corporation.
 * Portions created by the Initial Developer are Copyright (C) 1998
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   pschwartau@netscape.com
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
/*
 * Date: 06 February 2001
 *
 * SUMMARY:  Arose from Bugzilla bug 67773:
 * "Regular subexpressions followed by + failing to run to completion"
 *
 * See http://bugzilla.mozilla.org/show_bug.cgi?id=67773
 * See http://bugzilla.mozilla.org/show_bug.cgi?id=69989
 */
//-------------------------------------------------------------------------------------------------
var SECTION = "eregress_67773";
var VERSION = "";
var TITLE   = "Testing regular subexpressions followed by ? or +\n";
var bug = "67773";

startTest();
writeHeaderToLog(SECTION + " " + TITLE);
var testcases = getTestCases();
test();

function getTestCases() {
	var array = new Array();
	var item = 0;

	var cnSingleSpace = ' ';
	var status = '';
	var pattern = '';
	var string = '';
	var actualmatch = '';
	var expectedmatch = '';


	pattern = /^(\S+)?( ?)(B+)$/;  //single space before second ? character
	    status = inSection(1);
	    string = 'AAABBB AAABBB ';  //single space at middle and at end -
	    actualmatch = string.match(pattern);
	    expectedmatch = null;
	    array[item++] = new TestCase(SECTION, status, expectedmatch, actualmatch);

	    status = inSection(2);
	    string = 'AAABBB BBB';  //single space in the middle
	    actualmatch = string.match(pattern);
	    expectedmatch = Array(string,  'AAABBB', cnSingleSpace,  'BBB');
	    array[item++] = new TestCase(SECTION, status, expectedmatch.toString(), actualmatch.toString());

	    status = inSection(3);
	    string = 'AAABBB AAABBB';  //single space in the middle
	    actualmatch = string.match(pattern);
	    expectedmatch = null;
	    array[item++] = new TestCase(SECTION, status, expectedmatch, actualmatch);


	pattern = /^(A+B)+$/;
	    status = inSection(4);
	    string = 'AABAAB';
	    actualmatch = string.match(pattern);
	    expectedmatch = Array(string,  'AAB');
	    array[item++] = new TestCase(SECTION, status, expectedmatch.toString(), actualmatch.toString());

	    status = inSection(5);
	    string = 'ABAABAAAAAAB';
	    actualmatch = string.match(pattern);
	    expectedmatch = Array(string,  'AAAAAAB');
	    array[item++] = new TestCase(SECTION, status, expectedmatch.toString(), actualmatch.toString());

	    status = inSection(6);
	    string = 'ABAABAABAB';
	    actualmatch = string.match(pattern);
	    expectedmatch = Array(string,  'AB');
	    array[item++] = new TestCase(SECTION, status, expectedmatch.toString(), actualmatch.toString());

	    status = inSection(7);
	    string = 'ABAABAABABB';
	    actualmatch = string.match(pattern);
	    expectedmatch = null;   // because string doesn't match at end
	    array[item++] = new TestCase(SECTION, status, expectedmatch, actualmatch);


	pattern = /^(A+1)+$/;
	    status = inSection(8);
	    string = 'AA1AA1';
	    actualmatch = string.match(pattern);
	    expectedmatch = Array(string,  'AA1');
	    array[item++] = new TestCase(SECTION, status, expectedmatch.toString(), actualmatch.toString());


	pattern = /^(\w+\-)+$/;
	    status = inSection(9);
	    string = '';
	    actualmatch = string.match(pattern);
	    expectedmatch = null;
	    array[item++] = new TestCase(SECTION, status, expectedmatch, actualmatch);

	    status = inSection(10);
	    string = 'bla-';
	    actualmatch = string.match(pattern);
	    expectedmatch = Array(string, string);
	    array[item++] = new TestCase(SECTION, status, expectedmatch.toString(), actualmatch.toString());

	    status = inSection(11);
	    string = 'bla-bla';  // hyphen missing at end -
	    actualmatch = string.match(pattern);
	    expectedmatch = null;  //because string doesn't match at end
	    array[item++] = new TestCase(SECTION, status, expectedmatch, actualmatch);

	    status = inSection(12);
	    string = 'bla-bla-';
	    actualmatch = string.match(pattern);
	    expectedmatch = Array(string, 'bla-');
	    array[item++] = new TestCase(SECTION, status, expectedmatch.toString(), actualmatch.toString());


	pattern = /^(\S+)+(A+)$/;
	    status = inSection(13);
	    string = 'asdldflkjAAA';
	    actualmatch = string.match(pattern);
	    expectedmatch = Array(string, 'asdldflkjAA', 'A');
	    array[item++] = new TestCase(SECTION, status, expectedmatch.toString(), actualmatch.toString());

	    status = inSection(14);
	    string = 'asdldflkj AAA'; // space in middle
	    actualmatch = string.match(pattern);
	    expectedmatch = null;  //because of the space
	    array[item++] = new TestCase(SECTION, status, expectedmatch, actualmatch);


	pattern = /^(\S+)+(\d+)$/;
	    status = inSection(15);
	    string = 'asdldflkj122211';
	    actualmatch = string.match(pattern);
	    expectedmatch = Array(string, 'asdldflkj12221', '1');
	    array[item++] = new TestCase(SECTION, status, expectedmatch.toString(), actualmatch.toString());

	    status = inSection(16);
	    string = 'asdldflkj1111111aaa1';
	    actualmatch = string.match(pattern);
	    expectedmatch = Array(string, 'asdldflkj1111111aaa', '1');
	    array[item++] = new TestCase(SECTION, status, expectedmatch.toString(), actualmatch.toString());


	/*
	 * This one comes from Stephen Ostermiller.
	 * See http://bugzilla.mozilla.org/show_bug.cgi?id=69989
	 */
	pattern = /^[A-Za-z0-9]+((\.|-)[A-Za-z0-9]+)+$/;
	    status = inSection(17);
	    string = 'some.host.tld';
	    actualmatch = string.match(pattern);
	    expectedmatch = Array(string, '.tld', '.');
	    array[item++] = new TestCase(SECTION, status, expectedmatch.toString(), actualmatch.toString());


	return array;
}
