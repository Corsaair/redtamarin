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
    var SECTION = "15.1.2.7";
    var VERSION = "ECMA_1";
    startTest();
    var TITLE   = "isFinite( x )";

    var BUGNUMBER= "77391";

    writeHeaderToLog( SECTION + " "+ TITLE);

    var testcases = getTestCases();

    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

    array[item++] = new TestCase( SECTION, "isFinite.length",      1,                  isFinite.length );
    //array[item++] = new TestCase( SECTION, "isFinite.length = null; isFinite.length",   1,      eval("isFinite.length=null; isFinite.length") );

    var thisError:String = "no error";
    try
    {
        isFinite.length=null;
    }
    catch(e:ReferenceError)
    {
        thisError = e.toString();
    }
    finally
    {
        array[item++] = new TestCase(SECTION, "isFinite.length = null", "ReferenceError: Error #1074", referenceError(thisError));
    }
    array[item++] = new TestCase( SECTION, "delete isFinite.length",                    false,  delete isFinite.length );
    //array[item++] = new TestCase( SECTION, "delete isFinite.length; isFinite.length",   1,      eval("delete isFinite.length; isFinite.length") );
    delete isFinite.length;
    array[item++] = new TestCase( SECTION, "delete isFinite.length; isFinite.length",   1, isFinite.length);

    var MYPROPS='';
    for ( var p in isFinite ) {
       MYPROPS += p;
    }


    array[item++] = new TestCase( SECTION, "var MYPROPS='', for ( var p in isFinite ) { MYPROPS+= p }, MYPROPS",    "", MYPROPS );

    array[item++] = new TestCase( SECTION,  "isFinite()",           false,              isFinite() );
    array[item++] = new TestCase( SECTION, "isFinite( null )",      true,              isFinite(null) );
    array[item++] = new TestCase( SECTION, "isFinite( void 0 )",    false,             isFinite(void 0) );
    array[item++] = new TestCase( SECTION, "isFinite( false )",     true,              isFinite(false) );
    array[item++] = new TestCase( SECTION, "isFinite( true)",       true,              isFinite(true) );
    array[item++] = new TestCase( SECTION, "isFinite( ' ' )",       true,              isFinite( " " ) );

    array[item++] = new TestCase( SECTION, "isFinite( new Boolean(true) )",     true,   isFinite(new Boolean(true)) );
    array[item++] = new TestCase( SECTION, "isFinite( new Boolean(false) )",    true,   isFinite(new Boolean(false)) );

    array[item++] = new TestCase( SECTION, "isFinite( 0 )",        true,              isFinite(0) );
    array[item++] = new TestCase( SECTION, "isFinite( 1 )",        true,              isFinite(1) );
    array[item++] = new TestCase( SECTION, "isFinite( 2 )",        true,              isFinite(2) );
    array[item++] = new TestCase( SECTION, "isFinite( 3 )",        true,              isFinite(3) );
    array[item++] = new TestCase( SECTION, "isFinite( 4 )",        true,              isFinite(4) );
    array[item++] = new TestCase( SECTION, "isFinite( 5 )",        true,              isFinite(5) );
    array[item++] = new TestCase( SECTION, "isFinite( 6 )",        true,              isFinite(6) );
    array[item++] = new TestCase( SECTION, "isFinite( 7 )",        true,              isFinite(7) );
    array[item++] = new TestCase( SECTION, "isFinite( 8 )",        true,              isFinite(8) );
    array[item++] = new TestCase( SECTION, "isFinite( 9 )",        true,              isFinite(9) );

    array[item++] = new TestCase( SECTION, "isFinite( '0' )",        true,              isFinite('0') );
    array[item++] = new TestCase( SECTION, "isFinite( '1' )",        true,              isFinite('1') );
    array[item++] = new TestCase( SECTION, "isFinite( '2' )",        true,              isFinite('2') );
    array[item++] = new TestCase( SECTION, "isFinite( '3' )",        true,              isFinite('3') );
    array[item++] = new TestCase( SECTION, "isFinite( '4' )",        true,              isFinite('4') );
    array[item++] = new TestCase( SECTION, "isFinite( '5' )",        true,              isFinite('5') );
    array[item++] = new TestCase( SECTION, "isFinite( '6' )",        true,              isFinite('6') );
    array[item++] = new TestCase( SECTION, "isFinite( '7' )",        true,              isFinite('7') );
    array[item++] = new TestCase( SECTION, "isFinite( '8' )",        true,              isFinite('8') );
    array[item++] = new TestCase( SECTION, "isFinite( '9' )",        true,              isFinite('9') );

    array[item++] = new TestCase( SECTION, "isFinite( 0x0a )",    true,                 isFinite( 0x0a ) );
    array[item++] = new TestCase( SECTION, "isFinite( 0xaa )",    true,                 isFinite( 0xaa ) );
    array[item++] = new TestCase( SECTION, "isFinite( 0x0A )",    true,                 isFinite( 0x0A ) );
    array[item++] = new TestCase( SECTION, "isFinite( 0xAA )",    true,                 isFinite( 0xAA ) );

    array[item++] = new TestCase( SECTION, "isFinite( '0x0a' )",    true,               isFinite( "0x0a" ) );
    array[item++] = new TestCase( SECTION, "isFinite( '0xaa' )",    true,               isFinite( "0xaa" ) );
    array[item++] = new TestCase( SECTION, "isFinite( '0x0A' )",    true,               isFinite( "0x0A" ) );
    array[item++] = new TestCase( SECTION, "isFinite( '0xAA' )",    true,               isFinite( "0xAA" ) );

    array[item++] = new TestCase( SECTION, "isFinite( 077 )",       true,               isFinite( 077 ) );
    array[item++] = new TestCase( SECTION, "isFinite( '077' )",     true,               isFinite( "077" ) );

    array[item++] = new TestCase( SECTION, "isFinite( new String('Infinity') )",        false,      isFinite(new String("Infinity")) );
    array[item++] = new TestCase( SECTION, "isFinite( new String('-Infinity') )",       false,      isFinite(new String("-Infinity")) );

    array[item++] = new TestCase( SECTION, "isFinite( 'Infinity' )",        false,      isFinite("Infinity") );
    array[item++] = new TestCase( SECTION, "isFinite( '-Infinity' )",       false,      isFinite("-Infinity") );
    array[item++] = new TestCase( SECTION, "isFinite( Number.POSITIVE_INFINITY )",  false,  isFinite(Number.POSITIVE_INFINITY) );
    array[item++] = new TestCase( SECTION, "isFinite( Number.NEGATIVE_INFINITY )",  false,  isFinite(Number.NEGATIVE_INFINITY) );
    array[item++] = new TestCase( SECTION, "isFinite( Number.NaN )",                false,  isFinite(Number.NaN) );

    array[item++] = new TestCase( SECTION, "isFinite( Infinity )",  false,  isFinite(Infinity) );
    array[item++] = new TestCase( SECTION, "isFinite( -Infinity )",  false,  isFinite(-Infinity) );
    array[item++] = new TestCase( SECTION, "isFinite( NaN )",                false,  isFinite(NaN) );


    array[item++] = new TestCase( SECTION, "isFinite( Number.MAX_VALUE )",          true,  isFinite(Number.MAX_VALUE) );
    array[item++] = new TestCase( SECTION, "isFinite( Number.MIN_VALUE )",          true,  isFinite(Number.MIN_VALUE) );

    return ( array );
}
