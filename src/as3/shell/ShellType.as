/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package shell
{

    /**
     * The ShellType class defines string constants for the types of shell execution.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4.1
     */
    public final class ShellType
    {

        /**
         * The <b>runtime</b> type is when the code is executed by one of the <b>redshell</b> executables.
         * 
         * <p>
         * This mode is the default.
         * </p>
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4.1
         */
        public static const RUNTIME:String = "runtime";

        /**
         * The <b>projector/b> type is when the code is executed from within a projector executable.
         * 
         * <p>
         * A projector is the result of merging a redshell executable with ABC and/or SWF pre-compiled
         * code to produce a standaloen executable (static binary).
         * </p>
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4.1
         */
        public static const PROJECTOR:String = "projector";

        /**
         * The <b>script</b> type is when the code is dynamically evaluated by the runtime.
         * 
         * <p>
         * This mode is used by <b>as3shebang</b>.
         * </p>
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4.1
         */
        public static const SCRIPT:String = "script";

    }

}
