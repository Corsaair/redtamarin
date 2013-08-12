/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/*
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/licenses/publicdomain/
 * Contributor: Blake Kaplan
 */
import com.adobe.test.Assert;

var gTestfile = 'regress-386030.js';
//-----------------------------------------------------------------------------
var BUGNUMBER = 386030;
var summary = 'Array.reduce should ignore holes';
var actual = '';
var expect = '';

//printBugNumber(BUGNUMBER);
//printStatus (summary);

function add(a, b) { return a + b; }
function testreduce(v) { return v == 3 ? "PASS" : "FAIL"; }

expect = 'PASS';

try {
  a = new Array(2);
  a[1] = 3;
  actual = testreduce(a.reduce(add));
} catch (e) {
  actual = "FAIL, reduce";
}

Assert.expectEq(summary, expect, actual);
//reportCompare(expect, actual, summary +
// ': 1');

try {
  a = new Array(2);
  a[0] = 3;
  actual = testreduce(a.reduceRight(add));
} catch (e) {
  actual = "FAIL, reduceRight";
}

Assert.expectEq(summary, expect, actual);
//reportCompare(expect, actual, summary +
// ': 2');

try {
  a = new Array(2);
  a.reduce(add);
  actual = "FAIL, empty reduce";
} catch (e) {
  actual = "PASS";
}

Assert.expectEq(summary, expect, actual);
//reportCompare(expect, actual, summary +
// ': 3');

try {
  a = new Array(2);
  print(a.reduceRight(add));
  actual = "FAIL, empty reduceRight";
} catch (e) {
  actual = "PASS";
}

Assert.expectEq(summary, expect, actual);
//reportCompare(expect, actual, summary +
// ': 4');


