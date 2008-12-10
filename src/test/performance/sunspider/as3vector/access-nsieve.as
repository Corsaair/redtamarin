
// The Great Computer Language Shootout
// http://shootout.alioth.debian.org/
//
// modified by Isaac Gouy

function pad(number:Number,width:Number):String{
   var s:String = number.toString();
   var prefixWidth:Number = width - s.length;
   if (prefixWidth>0){
      for (var i:int=1; i<=prefixWidth; i++) s = " " + s;
   }
   return s;
}

function nsieve(m:int, isPrime:Vector.<Boolean>):int{
   var i:int, k:int, count:int;

   for (i=2; i<=m; i++) { isPrime[i] = true; }
   count = 0;

   for (i=2; i<=m; i++){
      if (isPrime[i]) {
         for (k=i+i; k<=m; k+=i) isPrime[k] = false;
         count++;
      }
   }
   return count;
}

function sieve():int {
    var res:int;
    for (var i:int = 1; i <= 3; i++ ) {
        var m:int = (1<<i)*10000;
        var flags:Vector.<Boolean> = new Vector.<Boolean>(m+1,true);
        res=nsieve(m, flags);
    }
    return res;
}

var start:Number=new Date();
var res:int=sieve();
var totaltime:Number=new Date()-start;
if (res==7837) {
   print("metric time "+totaltime);
} else {
   print("error sieve() expecting 7837 got "+res);
}

