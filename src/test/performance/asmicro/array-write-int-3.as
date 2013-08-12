/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var DESC = "Write int from local into dense Array with var+const expression.  Compare array-write-int-1.";
include "driver.as"

function array_write_int(iter: int): Array
{
    // It will become initialized after the first iteration but it's more honest
    // to initialize it here, to try to ensure denseness.
    var a: Array = new Array(1000);
    for ( var k:int = 0 ; k < 1000 ; k++ )
        a[k] = 0;

    // Please do not change the type annotations
    var v0: int = 1;
    var v1: int = 2;
    var v2: int = 3;
    var v3: int = 4;
    var v4: int = 5;
    for ( var i:int = 0 ; i < iter ; i++ ) {
        for ( var j:int = 0 ; j < 1000 ; j += 5 ) {
            a[j+0] = v0;
            a[j+1] = v1;
            a[j+2] = v2;
            a[j+3] = v3;
            a[j+4] = v4;
        }
    }
    if (a.length != 1000) throw "WROTE PAST END";
    return a;
}

TEST(function () { array_write_int(1000); }, "array-write-int-3");
