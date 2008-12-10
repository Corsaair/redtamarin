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
 * Portions created by the Initial Developer are Copyright (C) 2005-2006
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

package {

import flash.sampler.*
import avmplus.*

var SECTION = "Sampling";
var VERSION = "AS3";
var TITLE   = "Test the Invocation methods of Sampling api";

var isdebugger = System.isDebugger();

startTest();
writeHeaderToLog("Sampling api "+TITLE);

var objs:Array=new Array();
public class testclass {
    var string_instance:String;
    var int_instance:int;
    var bool_instance:Boolean;
    public var public_str:String;
    private var private_str:String;

    static var static_string:String;
    public static var public_static_string:String;
    private static var private_static_string:String;

    function testclass(s:String) { 
        this.string_instance=s;
    }
    function func() {}
    public function publicfunction() {}
    private function privatefunction() {}
    private var _getset:int;
    public function get getset():int {
        return _getset;
    }
    public function set getset(n:int):void {
        _getset=n;
    }
    public function get getonly():int {
        return 10;
    }
    public function set setonly(n:int):void {
    }
}
function simpleLoop() {
    for (var i:int=0;i<10;i++) {
       objs.push(new testclass(""+i));
    }
}

sampleInternalAllocs(true);
startSampling();
simpleLoop();
pauseSampling();

var names1=getMemberNames(testclass,true);
var namestable:Object=new Object();

var items1:Array=[];
for each (var item1 in names1) {
    items1.push(item1.toString());
    namestable[item1.toString()]=item1;
}
items1.sort();
/*
print("getMemberNames,instanceNames=true");
for (var i=0;i<items1.length;i++) {
    print(items1[i]);
}
*/


if (isdebugger) {
    AddTestCase(
        "getMemberNamesWithInstancesLength: returns member names, instanceNames=true",
        15,
        items1.length
    );
    AddTestCase(
        'getMemberNamesWithInstancesLength: returns member names, instanceNames=true',
        'bool_instance,func,getonly,getset,http://adobe.com/AS3/2006/builtin::hasOwnProperty,http://adobe.com/AS3/2006/builtin::isPrototypeOf,http://adobe.com/AS3/2006/builtin::propertyIsEnumerable,int_instance,public_str,publicfunction,setonly,string_instance,testclass::_getset,testclass::private_str,testclass::privatefunction',
        items1.toString()
    );
} else {
    AddTestCase(
        "getMemberNamesWithInstancesLength: returns member names, instanceNames=true",
        0,
        items1.length
    );
    AddTestCase(
        'getMemberNamesWithInstancesLength: returns member names, instanceNames=true',
        '',
        items1.toString()
    );
}

var names2=getMemberNames(testclass,false);

var items2:Array=[];
for each (var item2 in names2) {
    items2.push(item2.toString());
}
items2.sort();
if (isdebugger) {
    AddTestCase(
        "getMemberNamesWithInstancesLength: returns member names, instanceNames=true",
        7,
        items2.length
    );
    AddTestCase(
        'getMemberNamesWithInstancesLength: returns member names, instanceNames=true',
        'http://adobe.com/AS3/2006/builtin::hasOwnProperty,http://adobe.com/AS3/2006/builtin::isPrototypeOf,http://adobe.com/AS3/2006/builtin::propertyIsEnumerable,prototype,public_static_string,static_string,testclass::private_static_string',
        items2.toString()
    );

    AddTestCase(
        "getInvocationCountConstructor",
        1,
        getInvocationCount(testclass,null)
    );
    AddTestCase(
        "getInvocationCountFunc0: function not called invocation is 0",
        0,
        getInvocationCount(testclass,namestable['func'])
    );
}
// call the function 4 times
objs[0].func();
objs[0].func();
objs[1].func();
objs[2].func();
if (isdebugger) {
    AddTestCase(
        "getInvocationCountFunc4: call function 4 times",
        4,
        getInvocationCount(testclass,namestable['func'])
    );
    AddTestCase(
        "getInvocationCountVar: instance variable returns -1 on invocation count",
        -1,
        getInvocationCount(testclass,namestable['public_str'])
    );
    
    AddTestCase(
        "isGetterSetterForBoth: isGetterSetter for function with get and set",
        true,
        isGetterSetter(testclass,namestable['getset'])
    );
    AddTestCase(
        "isGetterSetterSetOnly: isGetterSetter for function with set only",
        true,
        isGetterSetter(testclass,namestable['setonly'])
    );
    AddTestCase(
        "isGetterSetterGetOnly: isGetterSetter for function with get only",
        true,
        isGetterSetter(testclass,namestable['getonly'])
    );
    AddTestCase(
        "isGetterSetterInstanceVar: isGetterSetter for instance variable",
        false,
        isGetterSetter(testclass,namestable['public_str'])
    );
    AddTestCase(
        "isGetterSetterFunction: isGetterSetter for a standard function",
         false,
         isGetterSetter(testclass,namestable['func'])
    );
}
var value;
objs[0].getset=5;
value=objs[0].getset;
objs[1].getset=5;
value=objs[1].getset;
objs[1].setonly=5;
value=objs[1].getonly;
objs[0].setonly=5;
value=objs[0].getonly;

if (isdebugger) {
    AddTestCase(
        "getGetterInvocationCount: function getter and setter",
        2,
        getGetterInvocationCount(testclass,namestable['getset'])
    );
    AddTestCase(
        "getGetterInvocationCount: function setonly",
        -1,
        getGetterInvocationCount(testclass,namestable['setonly'])
    );
    AddTestCase(
        "getGetterInvocationCount: function getonly",
        2,
        getGetterInvocationCount(testclass,namestable['getonly'])
    );
    AddTestCase(
        "getSetterInvocationCount: function getter and setter",
        2,
        getSetterInvocationCount(testclass,namestable['getset'])
    );
    AddTestCase(
        "getSetterInvocationCount: function setonly",
        2,
        getSetterInvocationCount(testclass,namestable['setonly'])
    );
    AddTestCase(
        "getSetterInvocationCount: function getonly",
        -1,
        getSetterInvocationCount(testclass,namestable['getonly'])
    );
    AddTestCase(
        "getGetterInvocationCount: function",
        4, // ??
        getGetterInvocationCount(testclass,namestable['func'])
    );
    AddTestCase(
        "getSetterInvocationCount: function",
        4,  // ??
        getSetterInvocationCount(testclass,namestable['func'])
    );
    AddTestCase(
        "getSize: get size on getter/setter function",
        true,
        getSize(namestable['getset'])>0
    );
    AddTestCase(
        "getSize: get size on private instance variable",
        true,
        getSize(namestable['testclass::_getset'])>0
    );
}
test();

}