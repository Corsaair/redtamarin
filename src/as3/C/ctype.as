/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package C.ctype
{

    /**
     * @name <code>&lt;ctype.h&gt;</code>
     * Character types.
     * 
     * <p>
     * C character classification is an operation provided
     * by a group of functions in the ANSI C Standard Library
     * for the C programming language.
     * 
     * These functions are used to test characters for membership
     * in a particular class of characters, such as alphabetic characters,
     * control characters, etc. Both single-byte, and wide characters are supported.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/ctype.h.html ctype.h
     */
    
    /** @internal */
    [native(cls="::avmshell::CTypeClass", methods="auto", construct="none")]
    [Inspectable(environment="none")]
    internal class __ctype
    {
        public native static function _avm_isalnum( c:int ):int;
        public native static function _avm_isalpha( c:int ):int;
        public native static function _avm_isascii( c:int ):int;
        public native static function _avm_isblank( c:int ):int;
        public native static function _avm_iscntrl( c:int ):int;
        public native static function _avm_isdigit( c:int ):int;
        public native static function _avm_isgraph( c:int ):int;
        public native static function _avm_islower( c:int ):int;
        public native static function _avm_isprint( c:int ):int;
        public native static function _avm_ispunct( c:int ):int;
        public native static function _avm_isspace( c:int ):int;
        public native static function _avm_isupper( c:int ):int;
        public native static function _avm_isxdigit( c:int ):int;

        public native static function _avm_toascii( c:int ):int;
        public native static function _avm_tolower( c:int ):int;
        public native static function _avm_toupper( c:int ):int;
    }

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
    public function isalnum( c:int ):int
    {
        return __ctype._avm_isalnum( c );
    }

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
    public function isalpha( c:int ):int
    {
        return __ctype._avm_isalpha( c );
    }

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
    public function isascii( c:int ):int
    {
        return __ctype._avm_isascii( c );
    }

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
    public function isblank( c:int ):int
    {
        return __ctype._avm_isblank( c );
    }

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
    public function iscntrl( c:int ):int
    {
        return __ctype._avm_iscntrl( c );
    }

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
    public function isdigit( c:int ):int
    {
        return __ctype._avm_isdigit( c );
    }

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
    public function isgraph( c:int ):int
    {
        return __ctype._avm_isgraph( c );
    }

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
    public function islower( c:int ):int
    {
        return __ctype._avm_islower( c );
    }

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
    public function isprint( c:int ):int
    {
        return __ctype._avm_isprint( c );
    }

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
    public function ispunct( c:int ):int
    {
        return __ctype._avm_ispunct( c );
    }

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
    public function isspace( c:int ):int
    {
        return __ctype._avm_isspace( c );
    }

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
    public function isupper( c:int ):int
    {
        return __ctype._avm_isupper( c );
    }

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
    public function isxdigit( c:int ):int
    {
        return __ctype._avm_isxdigit( c );
    }

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
    public function toascii( c:int ):int
    {
        return __ctype._avm_toascii( c );
    }

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
    public function tolower( c:int ):int
    {
        return __ctype._avm_tolower( c );
    }

    /** 
     * Transliterate lowercase characters to uppercase.
     *
     * @param c The character code value.
     * @return the function shall return the uppercase letter corresponding to the argument passed;
     * otherwise, they shall return the argument unchanged.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see String#charCodeAt()
     */
    public function toupper( c:int ):int
    {
        return __ctype._avm_toupper( c );
    }

}