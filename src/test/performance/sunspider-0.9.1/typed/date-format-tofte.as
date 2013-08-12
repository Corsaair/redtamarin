package {

function arrayExists(array:Array, x:*):Boolean {
    for (var i:uint = 0; i < array.length; i++) {
        if (array[i] == x) return true;
    }
    return false;
}

function formatDate (self:Date, input:String, time:uint = 0) {
    // formatDate :
    // a PHP date like function, for formatting date strings
    // See: http://www.php.net/date
    //
    // input : format string
    // time : epoch time (seconds, and optional)
    //
    // if time is not passed, formatting is based on
    // the current "this" date object's set time.
    //
    // supported:
    // a, A, B, d, D, F, g, G, h, H, i, j, l (lowercase L), L,
    // m, M, n, O, r, s, S, t, U, w, W, y, Y, z
    //
    // unsupported:
    // I (capital i), T, Z

    var switches:Array =    ["a", "A", "B", "d", "D", "F", "g", "G", "h", "H",
                       "i", "j", "l", "L", "m", "M", "n", "O", "r", "s",
                       "S", "t", "U", "w", "W", "y", "Y", "z"];
    // js code called eval("a"+"()")
    var switchFunctions:Object = new Object();
    switchFunctions["a"] = a;
    switchFunctions["A"] = A;
    switchFunctions["B"] = B;
    switchFunctions["d"] = d;
    switchFunctions["D"] = D;
    switchFunctions["F"] = F;
    switchFunctions["g"] = g;
    switchFunctions["G"] = G;
    switchFunctions["h"] = h;
    switchFunctions["H"] = H;
    switchFunctions["i"] = i;
    switchFunctions["j"] = j;
    switchFunctions["l"] = l;
    switchFunctions["L"] = L;
    switchFunctions["m"] = m;
    switchFunctions["M"] = M;
    switchFunctions["n"] = n;
    switchFunctions["O"] = O;
    switchFunctions["r"] = r;
    switchFunctions["s"] = s;
    switchFunctions["S"] = S;
    switchFunctions["t"] = t;
    switchFunctions["U"] = U;
    switchFunctions["w"] = w;
    switchFunctions["W"] = W;
    switchFunctions["y"] = y;
    switchFunctions["Y"] = Y;
    switchFunctions["z"] = z;
    
    var daysLong:Array =    ["Sunday", "Monday", "Tuesday", "Wednesday",
                       "Thursday", "Friday", "Saturday"];
    var daysShort:Array =   ["Sun", "Mon", "Tue", "Wed",
                       "Thu", "Fri", "Sat"];
    var monthsShort:Array = ["Jan", "Feb", "Mar", "Apr",
                       "May", "Jun", "Jul", "Aug", "Sep",
                       "Oct", "Nov", "Dec"];
    var monthsLong:Array =  ["January", "February", "March", "April",
                       "May", "June", "July", "August", "September",
                       "October", "November", "December"];
    var daysSuffix:Array = ["st", "nd", "rd", "th", "th", "th", "th", // 1st - 7th
                      "th", "th", "th", "th", "th", "th", "th", // 8th - 14th
                      "th", "th", "th", "th", "th", "th", "st", // 15th - 21st
                      "nd", "rd", "th", "th", "th", "th", "th", // 22nd - 28th
                      "th", "th", "st"];                        // 29th - 31st

    function a():String {
        // Lowercase Ante meridiem and Post meridiem
        return self.getHours() > 11? "pm" : "am";
    }
    function A():String {
        // Uppercase Ante meridiem and Post meridiem
        return self.getHours() > 11? "PM" : "AM";
    }

    function B():String{
        // Swatch internet time. code simply grabbed from ppk,
        // since I was feeling lazy:
        // http://www.xs4all.nl/~ppk/js/beat.html
        var off:uint = (self.getTimezoneOffset() + 60)*60;
        var theSeconds:uint = (self.getHours() * 3600) +
                         (self.getMinutes() * 60) +
                          self.getSeconds() + off;
        var beat:uint = Math.floor(theSeconds/86.4);
        if (beat > 1000) beat -= 1000;
        if (beat < 0) beat += 1000;
        var beatStr:String = String(beat);
        if ((""+beatStr).length == 1) return "00"+beatStr;
        if ((""+beatStr).length == 2) return "0"+beatStr;
        return beatStr
    }
    
    function d():String {
        // Day of the month, 2 digits with leading zeros
        return new String(self.getDate()).length == 1?
        "0"+self.getDate() : String(self.getDate());
    }
    function D():String {
        // A textual representation of a day, three letters
        return daysShort[self.getDay()];
    }
    function F():String {
        // A full textual representation of a month
        return monthsLong[self.getMonth()];
    }
    function g():uint {
        // 12-hour format of an hour without leading zeros
        return self.getHours() > 12? self.getHours()-12 : self.getHours();
    }
    function G():uint {
        // 24-hour format of an hour without leading zeros
        return self.getHours();
    }
    function h():String {
        // 12-hour format of an hour with leading zeros
        if (self.getHours() > 12) {
          var s:String = new String(self.getHours()-12);
          return s.length == 1?
          "0"+ (self.getHours()-12) : String(self.getHours()-12);
        } else {
          var s:String = new String(self.getHours());
          return s.length == 1?
          "0"+self.getHours() : String(self.getHours());
        }
    }
    function H():String {
        // 24-hour format of an hour with leading zeros
        return new String(self.getHours()).length == 1?
        "0"+self.getHours() : String(self.getHours());
    }
    function i():String {
        // Minutes with leading zeros
        return new String(self.getMinutes()).length == 1?
        "0"+self.getMinutes() : String(self.getMinutes());
    }
    function j():uint {
        // Day of the month without leading zeros
        return self.getDate();
    }
    function l():String {
        // A full textual representation of the day of the week
        return daysLong[self.getDay()];
    }
    function L():Boolean {
        // leap year or not. 1 if leap year, 0 if not.
        // the logic should match iso's 8601 standard.
        var y_ = Y();
        if (
            (y_ % 4 == 0 && y_ % 100 != 0) ||
            (y_ % 4 == 0 && y_ % 100 == 0 && y_ % 400 == 0)
            ) {
            return 1;
        } else {
            return 0;
        }
    }
    function m():String {
        // Numeric representation of a month, with leading zeros
        return self.getMonth() < 9?
        "0"+(self.getMonth()+1) :
        String(self.getMonth()+1);
    }
    function M():String {
        // A short textual representation of a month, three letters
        return monthsShort[self.getMonth()];
    }
    function n():uint {
        // Numeric representation of a month, without leading zeros
        return self.getMonth()+1;
    }
    function O():String {
        // Difference to Greenwich time (GMT) in hours
        var os = Math.abs(self.getTimezoneOffset());
        var h = ""+Math.floor(os/60);
        var m = ""+(os%60);
        h.length == 1? h = "0"+h:1;
        m.length == 1? m = "0"+m:1;
        return self.getTimezoneOffset() < 0 ? "+"+h+m : "-"+h+m;
    }
    function r():String {
        // RFC 822 formatted date
        var r:String; // result
        //  Thu    ,     21          Dec         2000
        r = D() + ", " + j() + " " + M() + " " + Y() +
        //        16     :    01     :    07          +0200
            " " + H() + ":" + i() + ":" + s() + " " + O();
        return r;
    }
    function S():String {
        // English ordinal suffix for the day of the month, 2 characters
        return daysSuffix[self.getDate()-1];
    }
    function s():String {
        // Seconds, with leading zeros
        return new String(self.getSeconds()).length == 1?
        "0"+self.getSeconds() : String(self.getSeconds());
    }
    function t():uint {

        // thanks to Matt Bannon for some much needed code-fixes here!
        var daysinmonths = [null,31,28,31,30,31,30,31,31,30,31,30,31];
        if (L()==1 && n()==2) return 29; // leap day
        return daysinmonths[n()];
    }
    function U():uint {
        // Seconds since the Unix Epoch (January 1 1970 00:00:00 GMT)
        return Math.round(self.getTime()/1000);
    }
    function W():uint {
        // Weeknumber, as per ISO specification:
        // http://www.cl.cam.ac.uk/~mgk25/iso-time.html
        
        // if the day is three days before newyears eve,
        // there's a chance it's "week 1" of next year.
        // here we check for that.
        var beforeNY:uint = 364+L() - z();
        var afterNY:uint  = z();
        var weekday:uint = w()!=0?w()-1:6; // makes sunday (0), into 6.
        if (beforeNY <= 2 && weekday <= 2-beforeNY) {
            return 1;
        }
        // similarly, if the day is within threedays of newyears
        // there's a chance it belongs in the old year.
        var ny:Date = new Date("January 1 " + Y() + " 00:00:00");
        var nyDay:uint = ny.getDay()!=0?ny.getDay()-1:6;
        if (
            (afterNY <= 2) &&
            (nyDay >=4)  &&
            (afterNY >= (6-nyDay))
            ) {
            // Since I'm not sure we can just always return 53,
            // i call the function here again, using the last day
            // of the previous year, as the date, and then just
            // return that week.
            var prevNY:Date = new Date("December 31 " + (Y()-1) + " 00:00:00");
            return prevNY.formatDate("W");
        }
        
        // week 1, is the week that has the first thursday in it.
        // note that this value is not zero index.
        if (nyDay <= 3) {
            // first day of the year fell on a thursday, or earlier.
            return 1 + Math.floor( ( z() + nyDay ) / 7 );
        } else {
            // first day of the year fell on a friday, or later.
            return 1 + Math.floor( ( z() - ( 7 - nyDay ) ) / 7 );
        }
    }
    function w():uint {
        // Numeric representation of the day of the week
        return self.getDay();
    }
    
    function Y():uint {
        // A full numeric representation of a year, 4 digits

        // we first check, if getFullYear is supported. if it
        // is, we just use that. ppks code is nice, but wont
        // work with dates outside 1900-2038, or something like that
        if ((new Date()).getFullYear) {
            var newDate:Date = new Date("Jan 1 2001");
            var x:uint = newDate.getFullYear();
            if (x == 2001) {
                // i trust the method now
                return self.getFullYear();
            }
        }
        // else, do this:
        // codes thanks to ppk:
        // http://www.xs4all.nl/~ppk/js/introdate.html
        var x:uint = self.getYear();
        var y:uint = x % 100;
        y += (y < 38) ? 2000 : 1900;
        return y;
    }
    function y():String {
        // A two-digit representation of a year
        var y:String = Y()+"";
        return y.substring(y.length-2,y.length);
    }
    function z():uint {
        // The day of the year, zero indexed! 0 through 366
        var t:Date = new Date("January 1 " + Y() + " 00:00:00");
        var diff:uint = self.getTime() - t.getTime();
        return Math.floor(diff/1000/60/60/24);
    }
        
    if (time) {
        // save time
        var prevTime:uint = self.getTime();
        self.setTime(time);
    }
    
    var ia:Array = input.split("");
    var ij:uint = 0;
    while (ia[ij]) {
        if (ia[ij] == "\\") {
            // this is our way of allowing users to escape stuff
            ia.splice(ij,1);
        } else {
            if (arrayExists(switches,ia[ij])) {
                ia[ij] = switchFunctions[ia[ij]](); //eval(ia[ij] + "()");
            }
        }
        ij++;
    }
    // reset time, back to what it was
    if (prevTime) {
        self.setTime(prevTime);
    }
    return ia.join("");
}   // function formatDate

// main entry point for running testcase
function runTest():void{

var date:Date = new Date("1/1/2007 1:11:11");

for (var i:uint = 0; i < 500; ++i) {
    var shortFormat:String = formatDate(date, "Y-m-d");
    var longFormat:String = formatDate(date, "l, F d, Y g:i:s A");
    date.setTime(date.getTime() + 84266956);
}
} //runTest()

// warm up run of testcase
runTest();
var startTime:uint = new Date().getTime();
runTest();
var time:uint = new Date().getTime() - startTime;
print("metric time " + time);

} // package