/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package C.assert
{

    /**
     * @name <code>&lt;assert.h&gt;</code>
     * Verify program assertion.
     *
     * <p>
     * Defines the C preprocessor macro <code>assert()</code>.
     * 
     * The macro implements an assertion, which can be used to verify
     * assumptions made by the program and print a diagnostic message
     * if this assumption is <code>false</code>.
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/assert.h.html assert.h
     */

    /** @private */
    [native("::avmshell::CAssertClass::_debugBreak")]
    internal native function _debugBreak():void;

    /**
     * <p>
     * <b>NOT WORKING</b>
     * </p>
     * 
     * Insert program diagnostics.
     * 
     * <p>
     * The <code>assert()</code> macro shall insert diagnostics into programs;
     * it shall expand to a <code>void</code> expression.
     * </p>
     * 
     * <p>
     * When it is executed, if expression (which shall have a scalar type) is <code>false</code>
     * (that is, compares equal to <code>0</code>),
     * <code>assert()</code> shall write information about the particular call
     * that failed on stderr and shall call <code>abort()</code>.
     * </p>
     *
     * <p>
     * The information written about the call that failed shall include
     * the text of the argument, the name of the source file,
     * the source file line number, and the name of the enclosing function;
     * the latter are, respectively, the values of the preprocessing macros
     * <code>__FILE__</code> and <code>__LINE__</code>
     * and of the identifier <code>__func__</code>.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
     public function assert( expression:* ):void
     {
          /* NOTE:
             just a test for now
             we ll find a solution eventually
           */
          if( !expression )
          {
               _debugBreak();
          }
     }

}