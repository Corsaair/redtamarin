/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package C.locale
{

    /**
     * @name <code>&lt;local.h&gt;</code>
     * Localization category macros.
     *
     * <p>
     * Defines macros and functions implementing basic
     * localization routines and specific information.
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/locale.h.html local.h
     */

    /** @internal */
    [native(cls="::avmshell::CLocaleClass", methods="auto", construct="none")]
    [Inspectable(environment="none")]
    internal class __locale
    {
        public native static function get LC_ALL():int;

    }

    /**
     * Affects everything.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const LC_ALL:int = __locale.LC_ALL;

    //Affects the behavior of regular expressions and the collation functions.
    //LC_COLLATE

    //Affects the behavior of regular expressions, character classification, character conversion functions, and wide-character functions.
    //LC_CTYPE

    //Affects the affirmative and negative response expressions returned by nl_langinfo() and the way message catalogs are located. It may also affect the behavior of functions that return or write message strings.
    //LC_MESSAGES

    //Affects the behavior of functions that handle monetary values.
    //LC_MONETARY

    //Affects the behavior of functions that handle numeric values.
    //LC_NUMERIC

    //Affects the behavior of the time conversion functions.
    //LC_TIME


    //char *setlocale(int category, const char *locale);
    /**
     * <p>
     * <b>NOT IMPLEMENTED</b>
     * </p>
     * 
     * [setlocale description]
     * @param  category [description]
     * @param  locale   [description]
     * @return          [description]
     */
    public function setlocale( category:int, locale:String ):String
    {
        //not implemented
        return null;
    }

    //struct lconv *localeconv(void);
    //function localeconv():lconv;

    //struct lconv
    //public class lconv

    /**
     * @private
     * only here for asdocs
     */
    [Inspectable(environment="none")]
    internal function dummy():void
    {
        //do nothing
    }
}