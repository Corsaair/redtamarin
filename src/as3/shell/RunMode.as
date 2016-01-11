/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package shell
{

    /**
     * The RunMode class defines string constants for the names of Execution Engine run modes.
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public final class RunMode
    {

        /**
         * The unknown mode.
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public static const UNKNOWN:String = "unknown";

        /**
         * The <b>mixed</b> mode (interpreter + JIT) <code>default</code>.
         * 
         * <p>
         * This mode is governed by the "On-Stack Replacement" (OSR) threshold.
         * </p>
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public static const MIXED:String = "mixed";

        /**
         * The <b>JIT or die</b> mode (always use JIT, abort if JIT fails).
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public static const JITORDIE:String = "jitordie";

        /**
         * The <b>Just In Time</b> mode (always use JIT, never interp unless the JIT fails).
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public static const JIT:String = "jit";

        /**
         * The <b>interpreter</b> mode (never use JIT).
         * 
         * @langversion 3.0
         * @playerversion AVM 0.4
         */
        public static const INTERP:String = "interp";

    }

}
