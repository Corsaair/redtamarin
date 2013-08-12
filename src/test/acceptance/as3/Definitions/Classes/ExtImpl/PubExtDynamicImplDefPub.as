/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


// var SECTION = "Definitions";       // provide a document reference (ie, ECMA section)
// var VERSION = "Clean AS2";  // Version of JavaScript or ECMA
// var TITLE   = "Extend Default Class Implement Default interface";       // Provide ECMA section title or a description
var BUGNUMBER = "";


/**
 * Calls to Assert.expectEq here. Assert.expectEq is a function that is defined
 * in shell.js and takes three arguments:
 * - a string representation of what is being tested
 * - the expected result
 * - the actual result
 *
 * For example, a test might look like this:
 *
 * var helloWorld = "Hello World";
 *
 * Assert.expectEq(
 * "var helloWorld = 'Hello World'",   // description of the test
 *  "Hello World",                     // expected result
 *  helloWorld );                      // actual result
 *
 */

import DynamicClass.*;

import com.adobe.test.Assert;
var PUBEXTDYNIMPLDEFPUB = new PubExtDynamicImplDefPub();

// *******************************************
// define default method from interface as a
// public method in the sub class
// *******************************************

//Should give an error

Assert.expectEq( "*** default(<empty>) method implemented interface ***", 1, 1 );
Assert.expectEq( "PUBEXTDYNIMPLDEFPUB.testGetSetBoolean(false)", false, PUBEXTDYNIMPLDEFPUB.testGetSetBoolean(false) );
Assert.expectEq( "PUBEXTDYNIMPLDEFPUB.testGetSetBoolean(true)", true, PUBEXTDYNIMPLDEFPUB.testGetSetBoolean(true) );

// *******************************************
// define public method from interface as a
// public method in the sub class
// *******************************************

Assert.expectEq( "*** public method implemented interface ***", 1, 1 );
Assert.expectEq( "PUBEXTDYNIMPLDEFPUB.testPubGetSetBoolean(false)", false, PUBEXTDYNIMPLDEFPUB.testPubGetSetBoolean(false) );
Assert.expectEq( "PUBEXTDYNIMPLDEFPUB.testPubGetSetBoolean(true)", true, PUBEXTDYNIMPLDEFPUB.testPubGetSetBoolean(true) );

//*******************************************
// access public method from outside of
// class
//
//*******************************************
var EXTDCLASS = new PubExtDynamicImplDefPub();
arr = new Array(1, 2, 3);

Assert.expectEq( "*** access public method from outside class ***", 1, 1 );
Assert.expectEq( "EXTDCLASS.setPubArray(arr), EXTDCLASS.pubArray", arr, (EXTDCLASS.setPubArray(arr), EXTDCLASS.pubArray) );

//*******************************************
// access public method from a default
// method of a sub class
//*******************************************

EXTDCLASS = new PubExtDynamicImplDefPub();
Assert.expectEq( "*** Access public method from default method of sub class ***", 1, 1 );
Assert.expectEq( "EXTDCLASS.testGetSubArray(arr)", arr, EXTDCLASS.testGetSubArray(arr) );

// <TODO>  fill in the rest of the cases here


// ********************************************
// access public method from a public
// method of a sub class
//
// ********************************************

EXTDCLASS = new PubExtDynamicImplDefPub();
Assert.expectEq( "*** Access public method from public method of sub class ***", 1, 1 );
Assert.expectEq( "EXTDCLASS.pubSubSetArray(arr), EXTDCLASS.pubSubGetArray()", arr, (EXTDCLASS.pubSubSetArray(arr), EXTDCLASS.pubSubGetArray()) );

// <TODO>  fill in the rest of the cases here

// ********************************************
// access public method from a private
// method of a sub class
//
// ********************************************

EXTDCLASS = new PubExtDynamicImplDefPub();
Assert.expectEq( "*** Access public method from private method of sub class ***", 1, 1 );
Assert.expectEq( "EXTDCLASS.testPrivSubArray(arr)", arr, EXTDCLASS.testPrivSubArray(arr) );

// <TODO>  fill in the rest of the cases here

              // displays results.
