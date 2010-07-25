/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is [Open Source Virtual Machine.].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2004-2006
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Adobe AS3 Team
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */


package avmplus {

import flash.utils.ByteArray

[native(cls="::avmshell::DomainClass", instance="::avmshell::DomainObject", methods="auto")]
public class Domain
{
    private native function init(base:Domain):void;

    public function Domain(base:Domain)
    {
        init(base);
    }

    public native function loadBytes(byteArray:ByteArray);
    public native function getClass(className:String):Class;
    public native static function get currentDomain():Domain;

    public function load(filename:String)
    {
        return loadBytes(ByteArray.readFile(filename))
    }

    /**
     * Gets the minimum length of a ByteArray required to be used as
     * ApplicationDomain.globalMemory
     *
     * @tiptext
     * @playerversion Flash 10
     * @langversion 3.0
     */
    public native static function get MIN_DOMAIN_MEMORY_LENGTH():uint;

    /**
     * Gets and sets the ByteArray object on which global memory operations
     * will operate within this ApplicationDomain
     *
     * @tiptext
     * @playerversion Flash 10
     * @langversion 3.0
     */
    public native function get domainMemory():ByteArray;
    public native function set domainMemory(mem:ByteArray);
}

}
