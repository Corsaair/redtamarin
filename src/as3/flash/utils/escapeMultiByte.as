/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.utils
{
    
    /**
     * Returns an escaped copy of the input string encoded as either UTF-8 or system code page,
     * depending on the value of System.useCodePage.
     * 
     * Use of System.useCodePage allows legacy content encoded in local code pages to be accessed
     * by the runtime, but only on systems using that legacy code page.
     * 
     * For example, Japanese data encoded as <code>Shift-JIS</code> will only be escaped
     * and unescaped properly on an OS using a Japanese default code page.
     * 
     * @param value The string to be escaped.
     * @return An escaped copy of the input string.
     * If System.useCodePage is <code>true</code>, the escaped string is encoded in the system code page.
     * If System.useCodePage is <code>false</code>, the escaped string is encoded in UTF-8.
     * For example, the input string "Crüe" will be escaped as "Cr%C3%BCe" on all systems
     * if System.useCodePage is <code>false</code>.
     * If system.useCodePage is <code>true</code>, and the system uses a Latin code page,
     * "Crüe" will be escaped as "Cr%FCe".
     * If the system uses a non Latin code page that does not contain the letter 'ü'
     * the result will probably be "Cr?e".
     * Unescaping "Cr%C3%BCe" with System.useCodePage set to <code>true</code> will produce different
     * undesired results on different systems, such as "CrÃ¼e" on a Latin system.
     * Similarly, unescaping "Cr%FCe" with System.useCodePage set to <code>false</code> could produce
     * "Cre" or "Cr?e" or other variations depending on the code page of the system.
     * 
	 * @playerversion Flash 9
	 * @playerversion AIR 1.0
	 * @langversion 3.0
     */
    public function escapeMultiByte( value:String ):String
    {
        throw new Error( "not implemented" );
        return "";
    }
}
