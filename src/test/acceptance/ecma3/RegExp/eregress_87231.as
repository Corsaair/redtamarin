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
 * Date: 22 June 2001
 *
 * SUMMARY:  Regression test for Bugzilla bug 87231:
 * "Regular expression /(A)?(A.*)/ picks 'A' twice"
 *
 * See http://bugzilla.mozilla.org/show_bug.cgi?id=87231
 * Key case:
 *
 *            pattern = /^(A)?(A.*)$/;
 *            string = 'A';
 *            expectedmatch = Array('A', '', 'A');
 *
 *
 * We expect the 1st subexpression (A)? NOT to consume the single 'A'.
 * Recall that "?" means "match 0 or 1 times". Here, it should NOT do
 * greedy matching: it should match 0 times instead of 1. This allows
 * the 2nd subexpression to make the only match it can: the single 'A'.
 * Such "altruism" is the only way there can be a successful global match...
 */
//-------------------------------------------------------------------------------------------------

var SECTION = "eregress_87231";
var VERSION = "";
var TITLE   = "Testing regular expression /(A)?(A.*)/";
var bug = "87231";

startTest();
writeHeaderToLog(SECTION + " " + TITLE);
var testcases = getTestCases();
test();

function getTestCases() {
	var array = new Array();
	var item = 0;

var cnEmptyString = '';
var status = '';
var pattern = '';
var string = '';
var actualmatch = '';
var expectedmatch = '';


pattern = /^(A)?(A.*)$/;
    status = inSection(1);
    string = 'AAA';
    actualmatch = string.match(pattern);
    expectedmatch = Array('AAA', 'A', 'AA');
    array[item++] = new TestCase(SECTION, status, expectedmatch.toString(), actualmatch.toString());

    status = inSection(2);
    string = 'AA';
    actualmatch = string.match(pattern);
    expectedmatch = Array('AA', 'A', 'A');
    array[item++] = new TestCase(SECTION, status, expectedmatch.toString(), actualmatch.toString());

    status = inSection(3);
    string = 'A';
    actualmatch = string.match(pattern);
    expectedmatch = Array('A', undefined, 'A'); // 'altruistic' case: see above
    array[item++] = new TestCase(SECTION, status, expectedmatch.toString(), actualmatch.toString());


pattern = /(A)?(A.*)/;
var strL = 'zxcasd;fl\\\  ^';
var strR = 'aaAAaaaf;lrlrzs';

    status = inSection(4);
    string =  strL + 'AAA' + strR;
    actualmatch = string.match(pattern);
    expectedmatch = Array('AAA' + strR, 'A', 'AA' + strR);
    array[item++] = new TestCase(SECTION, status, expectedmatch.toString(), actualmatch.toString());

    status = inSection(5);
    string =  strL + 'AA' + strR;
    actualmatch = string.match(pattern);
    expectedmatch = Array('AA' + strR, 'A', 'A' + strR);
    array[item++] = new TestCase(SECTION, status, expectedmatch.toString(), actualmatch.toString());

    status = inSection(6);
    string =  strL + 'A' + strR;
    actualmatch = string.match(pattern);
    expectedmatch = Array('A' + strR, undefined, 'A' + strR); // 'altruistic' case: see above
    array[item++] = new TestCase(SECTION, status, expectedmatch.toString(), actualmatch.toString());

	return array;
}
