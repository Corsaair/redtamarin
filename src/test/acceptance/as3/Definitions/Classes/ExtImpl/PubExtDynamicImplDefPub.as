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


var SECTION = "Definitions";       // provide a document reference (ie, ECMA section)
var VERSION = "Clean AS2";  // Version of JavaScript or ECMA
var TITLE   = "Extend Default Class Implement Default interface";       // Provide ECMA section title or a description
var BUGNUMBER = "";

startTest();                // leave this alone

/**
 * Calls to AddTestCase here. AddTestCase is a function that is defined
 * in shell.js and takes three arguments:
 * - a string representation of what is being tested
 * - the expected result
 * - the actual result
 *
 * For example, a test might look like this:
 *
 * var helloWorld = "Hello World";
 *
 * AddTestCase(
 * "var helloWorld = 'Hello World'",   // description of the test
 *  "Hello World",                     // expected result
 *  helloWorld );                      // actual result
 *
 */

import DynamicClass.*;

var PUBEXTDYNIMPLDEFPUB = new PubExtDynamicImplDefPub();

// *******************************************
// define default method from interface as a
// public method in the sub class
// *******************************************

//Should give an error

AddTestCase( "*** default(<empty>) method implemented interface ***", 1, 1 );
AddTestCase( "PUBEXTDYNIMPLDEFPUB.testGetSetBoolean(false)", false, PUBEXTDYNIMPLDEFPUB.testGetSetBoolean(false) );
AddTestCase( "PUBEXTDYNIMPLDEFPUB.testGetSetBoolean(true)", true, PUBEXTDYNIMPLDEFPUB.testGetSetBoolean(true) );

// *******************************************
// define public method from interface as a
// public method in the sub class
// *******************************************

AddTestCase( "*** public method implemented interface ***", 1, 1 );
AddTestCase( "PUBEXTDYNIMPLDEFPUB.testPubGetSetBoolean(false)", false, PUBEXTDYNIMPLDEFPUB.testPubGetSetBoolean(false) );
AddTestCase( "PUBEXTDYNIMPLDEFPUB.testPubGetSetBoolean(true)", true, PUBEXTDYNIMPLDEFPUB.testPubGetSetBoolean(true) );

//*******************************************
// access public method from outside of
// class
//
//*******************************************
var EXTDCLASS = new PubExtDynamicImplDefPub();
arr = new Array(1, 2, 3);

AddTestCase( "*** access public method from outside class ***", 1, 1 );
AddTestCase( "EXTDCLASS.setPubArray(arr), EXTDCLASS.pubArray", arr, (EXTDCLASS.setPubArray(arr), EXTDCLASS.pubArray) );

//*******************************************
// access public method from a default
// method of a sub class
//*******************************************

EXTDCLASS = new PubExtDynamicImplDefPub();
AddTestCase( "*** Access public method from default method of sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.testGetSubArray(arr)", arr, EXTDCLASS.testGetSubArray(arr) );

// <TODO>  fill in the rest of the cases here


// ********************************************
// access public method from a public
// method of a sub class
//
// ********************************************

EXTDCLASS = new PubExtDynamicImplDefPub();
AddTestCase( "*** Access public method from public method of sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.pubSubSetArray(arr), EXTDCLASS.pubSubGetArray()", arr, (EXTDCLASS.pubSubSetArray(arr), EXTDCLASS.pubSubGetArray()) );

// <TODO>  fill in the rest of the cases here

// ********************************************
// access public method from a private
// method of a sub class
//
// ********************************************

EXTDCLASS = new PubExtDynamicImplDefPub();
AddTestCase( "*** Access public method from private method of sub class ***", 1, 1 );
AddTestCase( "EXTDCLASS.testPrivSubArray(arr)", arr, EXTDCLASS.testPrivSubArray(arr) );

// <TODO>  fill in the rest of the cases here

test();       // leave this alone.  this executes the test cases and
              // displays results.
