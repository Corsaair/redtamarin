/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package C
{
    import shell.Program;

    /**
     * @name (globals)
     * C global variables.
     *
     * <p>
     * 
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/functions/environ.html environ
     */
    
    /**
     * [argc description]
     * @return [description]
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function get argc():uint
    {
        return Program.argv.length + 1;
    }

    /**
     * [argv description]
     * @return [description]
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    public function get argv():Array
    {
        return [Program.filename].concat( Program.argv );
    }

    /**
     * Array of environment variables.
     * 
     * @return an Array of environment variables as strings.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/007908799/xsh/environ.html environ
     * @see http://pubs.opengroup.org/onlinepubs/007908799/xbd/envvar.html Environment Variables
     */
    public function get environ():Array
    {
        return Program.environ;
    }


}