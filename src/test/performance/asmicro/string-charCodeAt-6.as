/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

var DESC = "String.prototype.charCodeAt, characters are all ASCII, Number return, uint param";
include "driver.as"

function loop():void {
    loop2("abcdefghijklmnopqrstuvwxyz");
}

function loop2(s:String):Number {
    var v:Number;
    for ( var i:uint=0 ; i < 100000 ; i += 25 )
        for ( var j:uint=0 ; j < 25 ; j++ )
            v = s.charCodeAt(j);
    return v;
}

TEST(loop, "string-charCodeAt-6");
