/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package C.spawn
{
    
    /** @internal */
    /*[native(cls="::avmshell::CSpawnClass", methods="auto", construct="none")]
    [Inspectable(environment="none")]
    internal class __spawn
    {
        public native static function dummy():void;
    }*/

    /**
     *
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CSpawnClass::spawn")]
    public native function spawn( pid:pid_t, path:String, argv:Array, envp:Array ):int;

    /**
     *
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("::avmshell::CSpawnClass::spawnp")]
    public native function spawnp( pid:pid_t, file:String, argv:Array, envp:Array ):int;

    /**
     * Used with <code>waitpid()</code> to pass by reference the <code>stat_loc</code> integer,
     * here instead of directly passing by reference an integer (as possible in C, and not possible in AS3)
     * we pass by reference an object which contains the property <code>stat_loc</code> of type integer.
     * 
     */
    [native(cls="::avmshell::Cpid_tClass", instance="::avmshell::Cpid_tObject", methods="auto")]
    public class pid_t
    {
        public var value:int;

        public function valueOf():int
        {
            return value;
        }

        public function toString():String
        {
            return String(value);
        }
    }

}
