/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


package
{
    // No instancegc, value is primitive.

    [native(cls="NumberClass", classgc="exact", instance="double", methods="auto", construct="override")]
    public final class Number
    {
        // Number.length = 1 per ES3
        // E262 {ReadOnly, DontDelete, DontEnum }
        public static const length:int = 1;

        // E262 {DontEnum, DontDelete, ReadOnly}
        public static const NaN               :Number = 0/0;
        public static const NEGATIVE_INFINITY :Number = -1/0;
        public static const POSITIVE_INFINITY :Number = 1/0;
        public static const MIN_VALUE         :Number = _minValue(); // typically: 4.9e-324
        public static const MAX_VALUE         :Number = 1.7976931348623158e+308;

        // The following constants correspond to the constants on Math, but we add them to Number to make
        // Number, float, and float4 behave similarly.
        [API(CONFIG::SWF_16)]
        public static const E       :Number = 2.718281828459045;
        [API(CONFIG::SWF_16)]
        public static const LN10    :Number = 2.302585092994046;
        [API(CONFIG::SWF_16)]
        public static const LN2     :Number = 0.6931471805599453;
        [API(CONFIG::SWF_16)]
        public static const LOG10E  :Number = 0.4342944819032518;
        [API(CONFIG::SWF_16)]
        public static const LOG2E   :Number = 1.442695040888963387;
        [API(CONFIG::SWF_16)]
        public static const PI      :Number = 3.141592653589793;
        [API(CONFIG::SWF_16)]
        public static const SQRT1_2 :Number = 0.7071067811865476;
        [API(CONFIG::SWF_16)]
        public static const SQRT2   :Number = 1.4142135623730951;

        // The following methods correspond to the methods on Math, but we add them to Number to make
        // Number, float, and float4 behave similarly.
        [API(CONFIG::SWF_16)]
        public native static function abs   (x:Number)   :Number;
        [API(CONFIG::SWF_16)]
        public native static function acos  (x:Number)   :Number;
        [API(CONFIG::SWF_16)]
        public native static function asin  (x:Number)   :Number;
        [API(CONFIG::SWF_16)]
        public native static function atan  (x:Number)   :Number;
        [API(CONFIG::SWF_16)]
        public native static function ceil  (x:Number)   :Number;
        [API(CONFIG::SWF_16)]
        public native static function cos   (x:Number)   :Number;
        [API(CONFIG::SWF_16)]
        public native static function exp   (x:Number)   :Number;
        [API(CONFIG::SWF_16)]
        public native static function floor (x:Number)   :Number;
        [API(CONFIG::SWF_16)]
        public native static function log   (x:Number)   :Number;
        [API(CONFIG::SWF_16)]
        public native static function round (x:Number)   :Number;
        [API(CONFIG::SWF_16)]
        public native static function sin   (x:Number)   :Number;
        [API(CONFIG::SWF_16)]
        public native static function sqrt  (x:Number)   :Number;
        [API(CONFIG::SWF_16)]
        public native static function tan   (x:Number)   :Number;

        [API(CONFIG::SWF_16)]
        public native static function atan2 (y:Number, x:Number):Number;
        [API(CONFIG::SWF_16)]
        public native static function pow   (x:Number, y:Number):Number;

        // max() and min() follow Math, for now; float does it differently however, 
        // requiring zero or more arguments and having "length" properties of value zero.
        [API(CONFIG::SWF_16)]
        public native static function max    (x:Number = NEGATIVE_INFINITY, y:Number = NEGATIVE_INFINITY, ... rest):Number;
        [API(CONFIG::SWF_16)]
        public native static function min    (x:Number = POSITIVE_INFINITY, y:Number = POSITIVE_INFINITY, ... rest):Number;

        [API(CONFIG::SWF_16)]
        public native static function random ():Number;
        
        // these must match the same constants in MathUtils
        private static const DTOSTR_FIXED:int = 1;
        private static const DTOSTR_PRECISION:int = 2;
        private static const DTOSTR_EXPONENTIAL:int = 3;

        private static native function _numberToString(n:Number, radix:int):String;
        private static native function _convert(n:Number, precision:int, mode:int):String;
        private static native function _minValue():Number;

        AS3 function toString(radix=10):String {
            return _numberToString(this,radix)
        }
        AS3 function valueOf():Number { return this }

        prototype.toLocaleString =
        prototype.toString = function (radix=10):String
        {
            if (this === prototype) return "0"

            if (!(this is Number))
                Error.throwError( TypeError, 1004 /*kInvokeOnIncompatibleObjectError*/, "Number.prototype.toString" );

            return _numberToString(this, radix)
        };

        prototype.valueOf = function()
        {
            if (this === prototype) return 0
            if (!(this is Number))
                Error.throwError( TypeError, 1004 /*kInvokeOnIncompatibleObjectError*/, "Number.prototype.valueOf" );
            return this;
        };

        AS3 function toExponential(p=0):String
        {
            return _convert(this, int(p), DTOSTR_EXPONENTIAL)
        }
        prototype.toExponential = function(p=0):String
        {
            return _convert(Number(this), int(p), DTOSTR_EXPONENTIAL)
        };

        AS3 function toPrecision(p=0):String
        {
            if (p == undefined)
                return this.toString();

            return _convert(this, int(p), DTOSTR_PRECISION)
        }
        prototype.toPrecision = function(p=0):String
        {
            if (p == undefined)
                return this.toString();

            return _convert(Number(this), int(p), DTOSTR_PRECISION)
        };

        AS3 function toFixed(p=0):String
        {
            return _convert(this, int(p), DTOSTR_FIXED)
        }
        prototype.toFixed = function(p=0):String
        {
            return _convert(Number(this), int(p), DTOSTR_FIXED)
        };

        // Dummy constructor function - This is neccessary so the compiler can do arg # checking for the ctor in strict mode
        // The code for the actual ctor is in NumberClass::construct in the avmplus
        public function Number(value = 0)
        {}

        _dontEnumPrototype(prototype);
    }

    // No instancegc, value is primitive.
   
    [native(cls="IntClass", classgc="exact", instance="int32_t", methods="auto", construct="override")]
    public final class int
    {
        // based on Number: E262 {ReadOnly, DontDelete, DontEnum}
        public static const MIN_VALUE:int = -0x80000000;
        public static const MAX_VALUE:int =  0x7fffffff;

        // Number.length = 1 per ES3
        // E262 {ReadOnly, DontDelete, DontEnum }
        public static const length:int = 1

        AS3 function toString(radix=10):String {
            return Number(this).AS3::toString(radix)
        }
        AS3 function valueOf():int { return this }

        prototype.toLocaleString =
        prototype.toString = function toString(radix=10):String
        {
            if (this === prototype) return "0"
            if (!(this is int))
                Error.throwError( TypeError, 1004 /*kInvokeOnIncompatibleObjectError*/, "int.prototype.toString" );
            return Number(this).toString(radix)
        }

        prototype.valueOf = function()
        {
            if (this === prototype) return 0
            if (!(this is int))
                Error.throwError( TypeError, 1004 /*kInvokeOnIncompatibleObjectError*/, "int.prototype.valueOf" );
            return this
        }

        AS3 function toExponential(p=0):String
        {
            return Number(this).AS3::toExponential(p)
        }
        prototype.toExponential = function(p=0):String
        {
            return Number(this).AS3::toExponential(p)
        }

        AS3 function toPrecision(p=0):String
        {
            return Number(this).AS3::toPrecision(p)
        }
        prototype.toPrecision = function(p=0):String
        {
            return Number(this).AS3::toPrecision(p)
        }

        AS3 function toFixed(p=0):String
        {
            return Number(this).AS3::toFixed(p)
        }
        prototype.toFixed = function(p=0):String
        {
            return Number(this).AS3::toFixed(p)
        }

        // Dummy constructor function - This is neccessary so the compiler can do arg # checking for the ctor in strict mode
        // The code for the actual ctor is in IntClass::construct in the avmplus
        public function int(value = 0)
        {}

        _dontEnumPrototype(prototype);
    }

    // No instancegc, value is primitive.

    [native(cls="UIntClass", classgc="exact", instance="uint32_t", methods="auto", construct="override")]
    public final class uint
    {
        // based on Number: E262 {ReadOnly, DontDelete, DontEnum}
        public static const MIN_VALUE:uint = 0;
        public static const MAX_VALUE:uint = 0xffffffff;

        // Number.length = 1 per ES3
        // E262 {ReadOnly, DontDelete, DontEnum}
        public static const length:int = 1

        AS3 function toString(radix=10):String {
            return Number(this).AS3::toString(radix)
        }
        AS3 function valueOf():uint { return this }

        prototype.toLocaleString =
        prototype.toString = function toString(radix=10):String
        {
            if (this === prototype) return "0"
            if (!(this is Number))
                Error.throwError( TypeError, 1004 /*kInvokeOnIncompatibleObjectError*/, "uint.prototype.toString" );
            return Number(this).toString(radix)
        }

        prototype.valueOf = function()
        {
            if (this === prototype) return 0
            if (!(this is uint))
                Error.throwError( TypeError, 1004 /*kInvokeOnIncompatibleObjectError*/, "uint.prototype.valueOf" );
            return this
        }

        AS3 function toExponential(p=0):String
        {
            return Number(this).AS3::toExponential(p)
        }
        prototype.toExponential = function(p=0):String
        {
            return Number(this).AS3::toExponential(p)
        }

        AS3 function toPrecision(p=0):String
        {
            return Number(this).AS3::toPrecision(p)
        }
        prototype.toPrecision = function(p=0):String
        {
            return Number(this).AS3::toPrecision(p)
        }

        AS3 function toFixed(p=0):String
        {
            return Number(this).AS3::toFixed(p)
        }
        prototype.toFixed = function(p=0):String
        {
            return Number(this).AS3::toFixed(p)
        }

        // Dummy constructor function - This is neccessary so the compiler can do arg # checking for the ctor in strict mode
        // The code for the actual ctor is in UIntClass::construct in the avmplus
        public function uint(value = 0)
        {}

        _dontEnumPrototype(prototype);
    }
}
