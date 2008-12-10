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
    var SECTION = "15.9.5.35-1";
    var VERSION = "ECMA_1";
    startTest();

    writeHeaderToLog( SECTION + " Date.prototype.setUTCMonth(mon [,date] ) ");
    var testcases:Array=getTestCases();
    test();

function getTestCases() {
    var array = new Array();
    var item = 0;
    
//    addNewTestCase( "TDATE = new Date(0);(TDATE).setUTCMonth(0);TDATE",
	var TDATE:Date = new Date(0);
	(TDATE).setUTCMonth(0);
	addNewTestCase( TDATE,
                    UTCDateFromTime(SetUTCMonth(0,0)),
                    LocalDateFromTime(SetUTCMonth(0,0)) );

   // addNewTestCase( "TDATE = new Date(0);(TDATE).setUTCMonth(11);TDATE",
	var TDATE:Date = new Date(0);
	(TDATE).setUTCMonth(11);
	 addNewTestCase(TDATE,
		    UTCDateFromTime(SetUTCMonth(0,11)),
                    LocalDateFromTime(SetUTCMonth(0,11)) );

//    addNewTestCase( "TDATE = new Date(0);(TDATE).setUTCMonth(3,4);TDATE",
	var TDATE:Date = new Date(0);
	(TDATE).setUTCMonth(3,4);
      addNewTestCase(TDATE,
		    UTCDateFromTime(SetUTCMonth(0,3,4)),
                    LocalDateFromTime(SetUTCMonth(0,3,4)) );

    
    
    function addNewTestCase( DateString, UTCDate, LocalDate) {
       
           DateCase = DateString ;	  	
    
    //    fixed_year = ( ExpectDate.year >=1900 || ExpectDate.year < 2000 ) ? ExpectDate.year - 1900 : ExpectDate.year;
    
        array[item++] = new TestCase( SECTION, "DateString+.getTime()",             UTCDate.value,       DateCase.getTime() );
        array[item++] = new TestCase( SECTION, "DateString+.valueOf()",             UTCDate.value,       DateCase.valueOf() );
    
        array[item++] = new TestCase( SECTION, "DateString+.getUTCFullYear()",      UTCDate.year,    DateCase.getUTCFullYear() );
        array[item++] = new TestCase( SECTION, "DateString+.getUTCMonth()",         UTCDate.month,  DateCase.getUTCMonth() );
        array[item++] = new TestCase( SECTION, "DateString+.getUTCDate()",          UTCDate.date,   DateCase.getUTCDate() );
        array[item++] = new TestCase( SECTION, "DateString+.getUTCDay()",           UTCDate.day,    DateCase.getUTCDay() );
        array[item++] = new TestCase( SECTION, "DateString+.getUTCHours()",         UTCDate.hours,  DateCase.getUTCHours() );
        array[item++] = new TestCase( SECTION, "DateString+.getUTCMinutes()",       UTCDate.minutes,DateCase.getUTCMinutes() );
        array[item++] = new TestCase( SECTION, "DateString+.getUTCSeconds()",       UTCDate.seconds,DateCase.getUTCSeconds() );
        array[item++] = new TestCase( SECTION, "DateString+.getUTCMilliseconds()",  UTCDate.ms,     DateCase.getUTCMilliseconds() );
    
        array[item++] = new TestCase( SECTION, "DateString+.getFullYear()",         LocalDate.year,       DateCase.getFullYear() );
        array[item++] = new TestCase( SECTION, "DateString+.getMonth()",            LocalDate.month,      DateCase.getMonth() );

	//Allow for DST variation on different platforms (osx) - see https://bugzilla.mozilla.org/show_bug.cgi?id=401898
	var date = DateCase.getDate();
	if (LocalDate.date == (date+1)) date++;
        array[item++] = new TestCase( SECTION, DateString+".getDate()",             LocalDate.date,       date);

	var day = DateCase.getDay();
	if (LocalDate.day == (day+1)) day++;
        array[item++] = new TestCase( SECTION, DateString+".getDay()",              LocalDate.day,        day );

	var hours = DateCase.getHours();
	if (LocalDate.hours == (hours+1)) {
		hours++;
	} else if (hours == 23 && LocalDate.hours == 0) {
		hours = 0;
	}
        array[item++] = new TestCase( SECTION, DateString+".getHours()",            LocalDate.hours,      hours );

        array[item++] = new TestCase( SECTION, "DateString+.getMinutes()",          LocalDate.minutes,    DateCase.getMinutes() );
        array[item++] = new TestCase( SECTION, "DateString+.getSeconds()",          LocalDate.seconds,    DateCase.getSeconds() );
        array[item++] = new TestCase( SECTION, "DateString+.getMilliseconds()",     LocalDate.ms,         DateCase.getMilliseconds() );
    
       array[item++] = new TestCase( SECTION,
                                          "DateString+.toString=Object.prototype.toString;+DateString+.toString()",
                                          "[object Date]",(DateCase.myToString=Object.prototype.toString,DateCase.myToString()) );
    
        DateCase.toString = Object.prototype.toString;
    	array[item++]  =new TestCase(SECTION,"DateCase.toString = Object.prototype.toString; DateCase.toString()","[object Date]", DateCase.toString() );
       
    
    }
    return array;
}
    
function MyDate() {
    this.year = 0;
    this.month = 0;
    this.date = 0;
    this.hours = 0;
    this.minutes = 0;
    this.seconds = 0;
    this.ms = 0;
}
function LocalDateFromTime(t) {
    t = LocalTime(t);
    return ( MyDateFromTime(t) );
}
function UTCDateFromTime(t) {
 return ( MyDateFromTime(t) );
}
function MyDateFromTime( t ) {
    var d = new MyDate();
    d.year = YearFromTime(t);
    d.month = MonthFromTime(t);
    d.date = DateFromTime(t);
    d.hours = HourFromTime(t);
    d.minutes = MinFromTime(t);
    d.seconds = SecFromTime(t);
    d.ms = msFromTime(t);

    d.time = MakeTime( d.hours, d.minutes, d.seconds, d.ms );
    d.value = TimeClip( MakeDate( MakeDay( d.year, d.month, d.date ), d.time ) );
    d.day = WeekDay( d.value );

    return (d);
}
function SetUTCMonth( t, month, date ) {
    var T       = t;
    var MONTH   = Number( month );
    var DATE    = ( date == void 0) ? DateFromTime(T) : Number( date );

    var RESULT4 = MakeDay(YearFromTime(T), MONTH, DATE );
    var RESULT5 = MakeDate( RESULT4, TimeWithinDay(T));

    return ( TimeClip(RESULT5) );
}
