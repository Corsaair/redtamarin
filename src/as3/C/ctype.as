/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package C.ctype
{

    /** 
     * Test for an alphanumeric character.
     *
     * @param c The character code value.
     * @return the function shall return non-zero if <code>c</code> is an alphanumeric character;
     * otherwise, it shall return <code>0</code>.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see String#charCodeAt()
     */
    [native("::avmshell::CTypeClass::isalnum")]
    public native function isalnum( c:int ):int;

    /** 
     * Test for an alphabetic character.
     *
     * @param c The character code value.
     * @return the function shall return non-zero if <code>c</code> is an alphabetic character;
     * otherwise, it shall return <code>0</code>.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see String#charCodeAt()
     */
    [native("::avmshell::CTypeClass::isalpha")]
    public native function isalpha( c:int ):int;

    /** 
     * Test for a 7-bit US-ASCII character.
     *
     * @param c The character code value.
     * @return the function shall return non-zero if <code>c</code> is a 7-bit US-ASCII character code between 0 and octal 0177 inclusive;
     * otherwise, it shall return <code>0</code>.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see String#charCodeAt()
     */
    [native("::avmshell::CTypeClass::isascii")]
    public native function isascii( c:int ):int;

    /** 
     * Test for a blank character.
     *
     * @param c The character code value.
     * @return the function shall return non-zero if <code>c</code> is a blank character;
     * otherwise, it shall return <code>0</code>.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see String#charCodeAt()
     */
    [native("::avmshell::CTypeClass::isblank")]
    public native function isblank( c:int ):int;

    /** 
     * Test for a control character.
     *
     * @param c The character code value.
     * @return the function shall return non-zero if <code>c</code> is a control character;
     * otherwise, it shall return <code>0</code>.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see String#charCodeAt()
     */
    [native("::avmshell::CTypeClass::iscntrl")]
    public native function iscntrl( c:int ):int;

    /** 
     * Test for a decimal digit.
     *
     * @param c The character code value.
     * @return the function shall return non-zero if <code>c</code> is a decimal digit;
     * otherwise, it shall return <code>0</code>.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see String#charCodeAt()
     */
    [native("::avmshell::CTypeClass::isdigit")]
    public native function isdigit( c:int ):int;

    /** 
     * Test for a visible character.
     *
     * @param c The character code value.
     * @return the function shall return non-zero if <code>c</code> is a character with a visible representation;
     * otherwise, it shall return <code>0</code>.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see String#charCodeAt()
     */
    [native("::avmshell::CTypeClass::isgraph")]
    public native function isgraph( c:int ):int;

    /** 
     * Test for a lowercase letter.
     *
     * @param c The character code value.
     * @return the function shall return non-zero if <code>c</code> is a lowercase letter;
     * otherwise, it shall return <code>0</code>.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see String#charCodeAt()
     */
    [native("::avmshell::CTypeClass::islower")]
    public native function islower( c:int ):int;

    /** 
     * Test for a printable character.
     *
     * @param c The character code value.
     * @return the function shall return non-zero if <code>c</code> is a printable character;
     * otherwise, it shall return <code>0</code>.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see String#charCodeAt()
     */
    [native("::avmshell::CTypeClass::isprint")]
    public native function isprint( c:int ):int;

    /** 
     * Test for a punctuation character.
     *
     * @param c The character code value.
     * @return the function shall return non-zero if <code>c</code> is a punctuation character;
     * otherwise, it shall return <code>0</code>.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see String#charCodeAt()
     */
    [native("::avmshell::CTypeClass::ispunct")]
    public native function ispunct( c:int ):int;

    /** 
     * Test for a white-space character.
     *
     * @param c The character code value.
     * @return the function shall return non-zero if <code>c</code> is a white-space character;
     * otherwise, it shall return <code>0</code>.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see String#charCodeAt()
     */
    [native("::avmshell::CTypeClass::isspace")]
    public native function isspace( c:int ):int;

    /** 
     * Test for an uppercase letter.
     *
     * @param c The character code value.
     * @return the function shall return non-zero if <code>c</code> is an uppercase letter;
     * otherwise, it shall return <code>0</code>.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see String#charCodeAt()
     */
    [native("::avmshell::CTypeClass::isupper")]
    public native function isupper( c:int ):int;

    /** 
     * Test for a hexadecimal digit.
     *
     * @param c The character code value.
     * @return the function shall return non-zero if <code>c</code> is a hexadecimal digit;
     * otherwise, it shall return <code>0</code>.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see String#charCodeAt()
     */
    [native("::avmshell::CTypeClass::isxdigit")]
    public native function isxdigit( c:int ):int;

    /** 
     * Translate an integer to a 7-bit ASCII character.
     *
     * @param c The character code value.
     * @return the function shall return the value (<code>c &#38;0x7f</code>).
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see String#charCodeAt()
     */
    [native("::avmshell::CTypeClass::toascii")]
    public native function toascii( c:int ):int;

    /** 
     * Transliterate uppercase characters to lowercase.
     *
     * @param c The character code value.
     * @return the function shall return the lowercase letter corresponding to the argument passed;
     * otherwise, they shall return the argument unchanged.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see String#charCodeAt()
     */
    [native("::avmshell::CTypeClass::tolower")]
    public native function tolower( c:int ):int;

    /** 
     * Transliterate lowercase characters to uppercase.
     *
     * @param c The character code value.
     * @return the function shall return the uppercase letter corresponding to the argument passed;
     * otherwise, they shall return the argument unchanged..
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see String#charCodeAt()
     */
    [native("::avmshell::CTypeClass::toupper")]
    public native function toupper( c:int ):int;

}