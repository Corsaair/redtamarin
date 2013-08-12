/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


package
{
    //pseudo-final - no user class can extend Function
    [native(cls="FunctionClass", gc="exact", instance="FunctionObject", methods="auto", construct="instance")]
    dynamic public class Function
    {
        // Function.length = 1 per ES3
        // E262 {ReadOnly, DontDelete, DontEnum }
        public static const length:int = 1

        // E262 {DontDelete}
        // JS {DontEnum,DontDelete}
        public native function get prototype()
        public native function set prototype(p)

        // E262 {DontEnum, DontDelete, ReadOnly}
        public native function get length():int

        // called by native code to create empty functions used for
        // prototype and no-arg constructor.
        [API(CONFIG::VM_INTERNAL)]
        [cppcall]
        public static function createEmptyFunction():Function
        {
            return function() {}
        }

        /* cn:  Spidermonkey returns the actual source text of the function here.  The ES3
        //  standard only says:
            15.3.4.2 Function.prototype.toString ( )
            An implementation-dependent representation of the function is returned. This
            representation has the syntax of a FunctionDeclaration. Note in particular
            that the use and placement of white space, line terminators, and semicolons
            within the representation string is implementation-dependent.
            The toString function is not generic; it throws a TypeError exception if its this value is not a Function object.
            Therefore, it cannot be transferred to other kinds of objects for use as a method.
        //
        // We don't have the source text, so this impl follows the letter if not the intent
        //  of the spec.
        //
        // Note: we only honor the compact ES3/4 spec, which means
        //  we don't support new Function(stringArg) where stringArg is the text of
        //  the function to be compiled at runtime.  Returning the true text of the
        //  function in toString() seems to be a bookend to this feature to me, and
        //  thus shouldn't be in the compact specification either. */

        prototype.toLocaleString =
        prototype.toString = function():String
        {
            var f:Function = this
            return "function Function() {}"
        }

        AS3 native function call(thisArg=void 0, ...args)
        prototype.call = function(thisArg=void 0, ...args)
        {
            var f:Function = this
            return f.AS3::apply(thisArg, args)
        }

        AS3 native function apply(thisArg=void 0, argArray=void 0)
        prototype.apply = function(thisArg=void 0, argArray=void 0)
        {
            var f:Function = this
            return f.AS3::apply(thisArg, argArray)
        }

        _dontEnumPrototype(prototype);
    }
}

// not dynamic
[native(cls="MethodClosureClass", gc="exact", instance="MethodClosure", methods="auto", construct="instance")]
final class MethodClosure extends Function
{
    override public function get prototype()
    {
        return null
    }

    override public function set prototype(p)
    {
        Error.throwError( ReferenceError, 1074 /*kConstWriteError*/, "prototype", "MethodClosure" );
    }
}
