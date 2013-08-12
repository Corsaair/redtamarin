/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
import com.adobe.test.Assert;


/*
 * Date: 03 December 2000
 *
 *
 * SUMMARY:  This test arose from Bugzilla bug 57043:
 * "Negative integers as object properties: strange behavior!"
 *
 * We check that object properties may be indexed by signed
 * numeric literals, as in assignments like obj[-1] = 'Hello'
 *
 * NOTE: it should not matter whether we provide the literal with
 * quotes around it or not; e.g. these should be equivalent:
 *
 *                                    obj[-1]  = 'Hello'
 *                                    obj['-1']  = 'Hello'
 */
//-----------------------------------------------------------------------------
var gTestfile = 'regress-57043.js';
var BUGNUMBER = 57043;
var summary = 'Indexing object properties by signed numerical literals -'
  var statprefix = 'Adding a property to test object with an index of ';
var statsuffix =  ', testing it now -';
var propprefix = 'This is property ';
var obj = new Object();
var status = ''; var actual = ''; var expect = ''; var value = '';


//  various indices to try -
var index = Array(-5000, -507, -3, -2, -1, 0, 1, 2, 3);


//-------------------------------------------------------------------------------------------------
addtestcases();
//-------------------------------------------------------------------------------------------------


function addtestcases()
{

  //printBugNumber(BUGNUMBER);
  //printStatus (summary);

  for (j in index) {testProperty(index[j]);}


}


function testProperty(i)
{
  status = getStatus(i);

  // try to assign a property using the given index -
  obj[i] = value = (propprefix  +  i);
 
  // try to read the property back via the index (as number) -
  expect = value;
  actual = obj[i];
  Assert.expectEq(summary, expect, actual);

  // try to read the property back via the index as string -
  expect = value;
  actual = obj[String(i)];
  Assert.expectEq(summary, expect, actual);
}


function getStatus(i)
{
  return (statprefix  +  i  +  statsuffix);
}

