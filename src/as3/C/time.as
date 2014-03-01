/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package C.time
{

    /** @internal */
    [native(cls="::avmshell::CTimeClass", methods="auto", construct="none")]
    [Inspectable(environment="none")]
    internal class __time
    {
        public native static function get CLOCKS_PER_SEC():int;

    }

    /**
     * The number of processor clocks per second.
     * 
     * <p>
     * A number used to convert the value returned by the <code>clock()</code> function into seconds.
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const CLOCKS_PER_SEC:int = __time.CLOCKS_PER_SEC;
    

}