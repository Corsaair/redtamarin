/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package C.limits
{

    /** @internal */
    [native(cls="::avmshell::CLimitsClass", methods="auto", construct="none")]
    [Inspectable(environment="none")]
    internal class __limits
    {
        public native static function get PATH_MAX():int;

    }

     //ARG_MAX

     //ATEXIT_MAX

     //HOST_NAME_MAX

     //LOGIN_NAME_MAX

     //OPEN_MAX

     //RTSIG_MAX

     //STREAM_MAX

     //SYMLOOP_MAX

     //NAME_MAX

    /**
     * Maximum number of bytes the implementation will store as a pathname
     * in a user-supplied buffer of unspecified size, including the terminating null character.
     * 
     * <p>
     * Minimum number the implementation will accept as the maximum number of bytes in a pathname.
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public const PATH_MAX:int = __limits.PATH_MAX;
    
    //SYMLINK_MAX


}