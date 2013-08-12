/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
import com.adobe.test.Assert;
/*
 * Date: 22 October 2001
 *
 * SUMMARY: Regression test for Bugzilla bug 105972:
 * "/^.*?$/ will not match anything"
 *
 * See http://bugzilla.mozilla.org/show_bug.cgi?id=105972
 */
//-----------------------------------------------------------------------------

// var SECTION = "eregress_105972";
// var VERSION = "";
// var TITLE   = "Regression test for Bugzilla bug 105972";
// var bug = "105972";

var testcases = getTestCases();

function getTestCases() {
    var array = new Array();
    var item = 0;

    var cnEmptyString = '';
    var status = '';
    var pattern = '';
    var string = '';
    var actualmatch = '';
    var expectedmatch = '';


    /*
     * The bug: this match was coming up null in Rhino and SpiderMonkey.
     * It should match the whole string. The reason:
     *
     * The * operator is greedy, but *? is non-greedy: it will stop
     * at the simplest match it can find. But the pattern here asks us
     * to match till the end of the string. So the simplest match must
     * go all the way out to the end, and *? has no choice but to do it.
     */
 //    status = inSection(1);
    pattern = /^.*?$/;
    string = 'Hello World';
    actualmatch = string.match(pattern);
    expectedmatch = Array(string);
    array[item++] = Assert.expectEq( status, expectedmatch.toString(), actualmatch.toString());


    /*
     * Leave off the '$' condition - here we expect the empty string.
     * Unlike the above pattern, we don't have to match till the end of
     * the string, so the non-greedy operator *? doesn't try to...
     */
 //    status = inSection(2);
    pattern = /^.*?/;
    string = 'Hello World';
    actualmatch = string.match(pattern);
    expectedmatch = Array(cnEmptyString);
    array[item++] = Assert.expectEq( status, expectedmatch.toString(), actualmatch.toString());


    /*
     * Try '$' combined with an 'or' operator.
     *
     * The operator *? will consume the string from left to right,
     * attempting to satisfy the condition (:|$). When it hits ':',
     * the match will stop because the operator *? is non-greedy.
     *
     * The submatch $1 = (:|$) will contain the ':'
     */
 //    status = inSection(3);
    pattern = /^.*?(:|$)/;
    string = 'Hello: World';
    actualmatch = string.match(pattern);
    expectedmatch = Array('Hello:', ':');
    array[item++] = Assert.expectEq( status, expectedmatch.toString(), actualmatch.toString());


    /*
     * Again, '$' combined with an 'or' operator.
     *
     * The operator * will consume the string from left to right,
     * attempting to satisfy the condition (:|$). When it hits ':',
     * the match will not stop since * is greedy. The match will
     * continue until it hits $, the end-of-string boundary.
     *
     * The submatch $1 = (:|$) will contain the empty string
     * conceived to exist at the end-of-string boundary.
     */
 //    status = inSection(4);
    pattern = /^.*(:|$)/;
    string = 'Hello: World';
    actualmatch = string.match(pattern);
    expectedmatch = Array(string, cnEmptyString);
    array[item++] = Assert.expectEq( status, expectedmatch.toString(), actualmatch.toString());

    return array;
}
