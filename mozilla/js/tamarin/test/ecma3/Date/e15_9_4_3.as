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


    var SECTION = "15.9.4.3";
    var TITLE = "Date.UTC( year, month, date, hours, minutes, seconds, ms )";

    startTest();
    writeHeaderToLog(SECTION + " "+ TITLE);
    var testcases = getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;

	function MyDate() {
	    this.year = 0;
	    this.month = 0;
	    this.date = 0;
	    this.hours = 0;
	    this.minutes = 0;
	    this.seconds = 0;
	    this.ms = 0;
	}

	function utc( year, month, date, hours, minutes, seconds, ms ) {
	    d = new MyDate();
	    d.year      = Number(year);

	    if (month)
	        d.month     = Number(month);
	    if (date)
	        d.date      = Number(date);
	    if (hours)
	        d.hours     = Number(hours);
	    if (minutes)
	        d.minutes   = Number(minutes);
	    if (seconds)
	        d.seconds   = Number(seconds);
	    if (ms)
	        d.ms        = Number(ms);

	    if ( isNaN(d.year) && 0 <= ToInteger(d.year) && d.year <= 99 ) {
	        d.year = 1900 + ToInteger(d.year);
	    }

	    if (isNaN(month) || isNaN(year) || isNaN(date) || isNaN(hours) ||
	        isNaN(minutes) || isNaN(seconds) || isNaN(ms) ) {
	            d.year = Number.NaN;
	            d.month = Number.NaN;
	            d.date = Number.NaN;
	            d.hours = Number.NaN;
	            d.minutes = Number.NaN;
	            d.seconds = Number.NaN;
	            d.ms = Number.NaN;
	            d.value = Number.NaN;
	            d.time = Number.NaN;
	            d.day =Number.NaN;
	            return d;
	        }

	    d.day = MakeDay( d.year, d.month, d.date );
	    d.time = MakeTime( d.hours, d.minutes, d.seconds, d.ms );
	    d.value = (TimeClip( MakeDate(d.day,d.time)));

	    return d;
	}

	function UTCTime( t ) {
	    sign = ( t < 0 ) ? -1 : 1;
	    return ( (t +(TZ_DIFF*msPerHour)) );
	}

    // Dates around 1970

    addNewTestCase( Date.UTC( 1970,0,1,0,0,0,0),
                    "Date.UTC( 1970,0,1,0,0,0,0)",
                    utc(1970,0,1,0,0,0,0) );

    addNewTestCase( Date.UTC( 1969,11,31,23,59,59,999),
                    "Date.UTC( 1969,11,31,23,59,59,999)",
                    utc(1969,11,31,23,59,59,999) );
    addNewTestCase( Date.UTC( 1972,1,29,23,59,59,999),
                    "Date.UTC( 1972,1,29,23,59,59,999)",
                    utc(1972,1,29,23,59,59,999) );
    addNewTestCase( Date.UTC( 1972,2,1,23,59,59,999),
                    "Date.UTC( 1972,2,1,23,59,59,999)",
                    utc(1972,2,1,23,59,59,999) );
    addNewTestCase( Date.UTC( 1968,1,29,23,59,59,999),
                    "Date.UTC( 1968,1,29,23,59,59,999)",
                    utc(1968,1,29,23,59,59,999) );
    addNewTestCase( Date.UTC( 1968,2,1,23,59,59,999),
                    "Date.UTC( 1968,2,1,23,59,59,999)",
                    utc(1968,2,1,23,59,59,999) );
    addNewTestCase( Date.UTC( 1969,0,1,0,0,0,0),
                    "Date.UTC( 1969,0,1,0,0,0,0)",
                    utc(1969,0,1,0,0,0,0) );
    addNewTestCase( Date.UTC( 1969,11,31,23,59,59,1000),
                    "Date.UTC( 1969,11,31,23,59,59,1000)",
                    utc(1970,0,1,0,0,0,0) );
    addNewTestCase( Date.UTC( 1969,Number.NaN,31,23,59,59,999),
                    "Date.UTC( 1969,Number.NaN,31,23,59,59,999)",
                    utc(1969,Number.NaN,31,23,59,59,999) );

    // Dates around 2000

    addNewTestCase( Date.UTC( 1999,11,31,23,59,59,999),
                    "Date.UTC( 1999,11,31,23,59,59,999)",
                    utc(1999,11,31,23,59,59,999) );
    addNewTestCase( Date.UTC( 2000,0,1,0,0,0,0),
                    "Date.UTC( 2000,0,1,0,0,0,0)",
                    utc(2000,0,1,0,0,0,0) );

    // Dates around 1900
    addNewTestCase( Date.UTC( 1899,11,31,23,59,59,999),
                    "Date.UTC( 1899,11,31,23,59,59,999)",
                    utc(1899,11,31,23,59,59,999) );
    addNewTestCase( Date.UTC( 1900,0,1,0,0,0,0),
                    "Date.UTC( 1900,0,1,0,0,0,0)",
                    utc(1900,0,1,0,0,0,0) );
    addNewTestCase( Date.UTC( 1973,0,1,0,0,0,0),
                    "Date.UTC( 1973,0,1,0,0,0,0)",
                    utc(1973,0,1,0,0,0,0) );
    addNewTestCase( Date.UTC( 1776,6,4,12,36,13,111),
                    "Date.UTC( 1776,6,4,12,36,13,111)",
                    utc(1776,6,4,12,36,13,111) );
    addNewTestCase( Date.UTC( 2525,9,18,15,30,1,123),
                    "Date.UTC( 2525,9,18,15,30,1,123)",
                    utc(2525,9,18,15,30,1,123) );

    // Dates around 29 Feb 2000

    addNewTestCase( Date.UTC( 2000,1,29,0,0,0,0 ),
                    "Date.UTC( 2000,1,29,0,0,0,0 )",
                    utc(2000,1,29,0,0,0,0) );
    addNewTestCase( Date.UTC( 2000,1,29,8,0,0,0 ),
                    "Date.UTC( 2000,1,29,8,0,0,0 )",
                    utc(2000,1,29,8,0,0,0) );

    // Dates around 1 Jan 2005

    addNewTestCase( Date.UTC( 2005,0,1,0,0,0,0 ),
                    "Date.UTC( 2005,0,1,0,0,0,0 )",
                    utc(2005,0,1,0,0,0,0) );
    addNewTestCase( Date.UTC( 2004,11,31,16,0,0,0 ),
                    "Date.UTC( 2004,11,31,16,0,0,0 )",
                    utc(2004,11,31,16,0,0,0) );

	function addNewTestCase( DateCase, DateString, ExpectDate) {
	    DateCase = DateCase;

	    item = array.length;

	//    fixed_year = ( ExpectDate.year >=1900 || ExpectDate.year < 2000 ) ? ExpectDate.year - 1900 : ExpectDate.year;

	    array[item++] = new TestCase( SECTION, DateString,         ExpectDate.value,       DateCase );
	    array[item++] = new TestCase( SECTION, DateString,         ExpectDate.value,       DateCase );
	/*

	    array[item++] = new TestCase( SECTION, DateString+".getUTCFullYear()",        ExpectDate.year,   DateCase.getUTCFullYear() );
	    array[item++] = new TestCase( SECTION, DateString+".getUTCMonth()",         ExpectDate.month,  DateCase.getUTCMonth() );
	    array[item++] = new TestCase( SECTION, DateString+".getUTCDate()",          ExpectDate.date,   DateCase.getUTCDate() );
	    array[item++] = new TestCase( SECTION, DateString+".getUTCDay()",           ExpectDate.day,    DateCase.getUTCDay() );
	    array[item++] = new TestCase( SECTION, DateString+".getUTCHours()",         ExpectDate.hours,  DateCase.getUTCHours() );
	    array[item++] = new TestCase( SECTION, DateString+".getUTCMinutes()",       ExpectDate.minutes,DateCase.getUTCMinutes() );
	    array[item++] = new TestCase( SECTION, DateString+".getUTCSeconds()",       ExpectDate.seconds,DateCase.getUTCSeconds() );
	    array[item++] = new TestCase( SECTION, DateString+".getUTCMilliseconds()",  ExpectDate.ms,     DateCase.getUTCMilliseconds() );

	    array[item++] = new TestCase( SECTION, DateString+".getFullYear()",             ExpectDate.year,            DateCase.getFullYear() );
	    array[item++] = new TestCase( SECTION, DateString+".getMonth()",            ExpectDate.month,      DateCase.getMonth() );
	    array[item++] = new TestCase( SECTION, DateString+".getDate()",             ExpectDate.date,       DateCase.getDate() );
	//    array[item++] = new TestCase( SECTION, DateString+".getDay()",              ExpectDate.day,        DateCase.getDay() );
	    array[item++] = new TestCase( SECTION, DateString+".getHours()",            ExpectDate.hours,      DateCase.getHours() );
	    array[item++] = new TestCase( SECTION, DateString+".getMinutes()",          ExpectDate.minutes,    DateCase.getMinutes() );
	    array[item++] = new TestCase( SECTION, DateString+".getSeconds()",          ExpectDate.seconds,    DateCase.getSeconds() );
	    array[item++] = new TestCase( SECTION, DateString+".getMilliseconds()",     ExpectDate.ms,         DateCase.getMilliseconds() );
	*/
	}

    return ( array );
}
