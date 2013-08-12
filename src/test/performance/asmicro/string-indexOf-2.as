/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var DESC = "String.prototype.indexOf, finding character at the end of a long string";
include "driver.as"

function loop():void {
    loop2("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
}

function loop2(s:String):int {
    var v:int;
    for ( var i:uint=0 ; i < 100000 ; i++ )
        v = s.indexOf("9");
    return v;
}

TEST(loop, "string-indexOf-2");
