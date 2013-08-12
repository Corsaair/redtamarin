/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
import com.adobe.test.Assert;

gTestfile = 'everything.js';

/**
   Filename:     everything.js
   Description:  'Tests regular expressions'

   Author:       Nick Lerissa
   Date:         March 24, 1998
*/

// var SECTION = 'As described in Netscape doc "Whats new in JavaScript 1.2"';
// var VERSION = 'no version';
// var TITLE   = 'RegExp';



// 'Sally and Fred are sure to come.'.match(/^[a-z\s]*/i)
Assert.expectEq (  "'Sally and Fred are sure to come'.match(/^[a-z\\s]*/i)",
           String(["Sally and Fred are sure to come"]), String('Sally and Fred are sure to come'.match(/^[a-z\s]*/i)));

// 'test123W+xyz'.match(new RegExp('^[a-z]*[0-9]+[A-Z]?.(123|xyz)$'))
Assert.expectEq (  "'test123W+xyz'.match(new RegExp('^[a-z]*[0-9]+[A-Z]?.(123|xyz)$'))",
           String(["test123W+xyz","xyz"]), String('test123W+xyz'.match(new RegExp('^[a-z]*[0-9]+[A-Z]?.(123|xyz)$'))));

// 'number one 12365 number two 9898'.match(/(\d+)\D+(\d+)/)
Assert.expectEq (  "'number one 12365 number two 9898'.match(/(\d+)\D+(\d+)/)",
           String(["12365 number two 9898","12365","9898"]), String('number one 12365 number two 9898'.match(/(\d+)\D+(\d+)/)));

var simpleSentence = /(\s?[^\!\?\.]+[\!\?\.])+/;
// 'See Spot run.'.match(simpleSentence)
Assert.expectEq (  "'See Spot run.'.match(simpleSentence)",
           String(["See Spot run.","See Spot run."]), String('See Spot run.'.match(simpleSentence)));

// 'I like it. What's up? I said NO!'.match(simpleSentence)
Assert.expectEq (  "'I like it. What's up? I said NO!'.match(simpleSentence)",
           String(["I like it. What's up? I said NO!",' I said NO!']), String('I like it. What\'s up? I said NO!'.match(simpleSentence)));

// 'the quick brown fox jumped over the lazy dogs'.match(/((\w+)\s*)+/)
Assert.expectEq (  "'the quick brown fox jumped over the lazy dogs'.match(/((\\w+)\\s*)+/)",
           String(['the quick brown fox jumped over the lazy dogs','dogs','dogs']),String('the quick brown fox jumped over the lazy dogs'.match(/((\w+)\s*)+/)));

