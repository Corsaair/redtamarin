/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.utils
{
    
    /**
     * Returns an unescaped copy of the input string,
     * which is decoded from either system code page page or UTF-8 depending on the value of System.useCodePage.
     * Use of System.useCodePage allows legacy content encoded in local code pages to be accessed by the runtime,
     * but only on systems using that legacy code page.
     * For example, Japanese data encoded as <code>Shift-JIS</code> will only be escaped and unescaped properly
     * on an OS using a Japanese default code page.
     * 
     * @param value The escaped string to be unescaped.
     * @return An unescaped copy of the input string.
     * If System.useCodePage is <code>true</code>, the escaped string is decoded from the system code page.
     * If System.useCodePage is <code>false</code>, the escaped string is decoded from UTF-8.
     * For example, if the input string is "Crüe" and System.useCodePage is <code>false</code>,
     * the result will be "CrÃ¼e" on all systems.
     * If System.useCodePage is <code>true</code> and the input string is "Cr%FCe",
     * and the system uses a Latin code page, the result will also be "CrÃ¼e".
     * Unescaping "Cr%C3%BCe" with System.useCodePage set to <code>true</code> will produce different
     * undesired results on different systems, such as "CrÃÂ¼e" on a Latin system.
     * Similarly, unescaping "Cr%FCe" with System.useCodePage set to <code>false</code> could produce
     * "Cre" or "Cr?e" or other variations depending on the code page of the system.
     * 
	 * @playerversion Flash 9
	 * @playerversion AIR 1.0
	 * @langversion 3.0
     */
    public function unescapeMultiByte( value:String ):String
    {
        throw new Error( "not implemented" );
        return "";
    }
}
