/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
import com.adobe.test.Assert;


var gTestfile = 'regress-475645-02.js';
//-----------------------------------------------------------------------------
var BUGNUMBER = 475645;
var summary = 'Do not crash @ nanojit::LIns::isop';
var actual = '';
var expect = '';


//-----------------------------------------------------------------------------
addtestcases();
//-----------------------------------------------------------------------------

function addtestcases()
{

  //printBugNumber(BUGNUMBER);
  //printStatus (summary);



  if (typeof window != 'undefined')
  {
    var q = (function () { });
    window.addEventListener("load", q, false);
    window.onerror = q;
    arr = new Array();
    pic = r = new Array;
    h = t = 7;
    var pics = "";
    pic[2] = "";
    for (i=1; i < pic.length; i++)
    {
      try
      {
        if(pics=="")
          pics=pic[i];
        else
          (pic[i]-1 & pic[i].i("") == 1);
      }
      catch(ex)
      {
      }
      arr[i]='';
    }
  }



  Assert.expectEq(summary, expect, actual);


}

