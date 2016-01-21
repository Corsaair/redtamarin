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
     * The minimum value of a character (Non-POSIX extension).
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4.1
     * 
     * @see http://en.wikipedia.org/wiki/ASCII ASCII (Wikipedia)
     */
    public const MIN_VALUE:int = 0x00;

    /**
     * The maximum value of a character (Non-POSIX extension).
     * 
     * <p>
     * For the first set, here is a map of how the original 127-character ASCII set
     * is considered by each function (an x indicates that the function returns true
     * on that character)
     * 
     * <table class="innertable">
     * <tr>
     *      <th>ASCII values</th>
     *      <th>characters</th>
     *      <th>iscntrl</th>
     *      <th>isblank</th>
     *      <th>isspace</th>
     *      <th>isupper</th>
     *      <th>islower</th>
     *      <th>isalpha</th>
     *      <th>isdigit</th>
     *      <th>isxdigit</th>
     *      <th>isalnum</th>
     *      <th>ispunct</th>
     *      <th>isgraph</th>
     *      <th>isprint</th>
     * </tr>
     * 
     * <tr>
     *      <td>0x00.. 0x08</td>
     *      <td>NUL, (other control codes)</td>
     *      <td>x</td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     * </tr>
     * 
     * <tr>
     *      <td>0x09</td>
     *      <td>tab ('\t')</td>
     *      <td>x</td>
     *      <td>x</td>
     *      <td>x</td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     * </tr>
     * 
     * <tr>
     *      <td>0x0A.. 0x0D</td>
     *      <td>(white-space control codes: '\f','\v','\n','\r')</td>
     *      <td>x</td>
     *      <td> </td>
     *      <td>x</td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     * </tr>
     * 
     * <tr>
     *      <td>0x0E.. 0x1F</td>
     *      <td>(other control codes)</td>
     *      <td>x</td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     * </tr>
     * 
     * <tr>
     *      <td>0x20</td>
     *      <td>space (' ')</td>
     *      <td> </td>
     *      <td>x</td>
     *      <td>x</td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td>x</td>
     * </tr>
     * 
     * <tr>
     *      <td>0x21.. 0x2F</td>
     *      <td>!"#$%&#38;'()&#42;+,-./</td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td>x</td>
     *      <td>x</td>
     *      <td>x</td>
     * </tr>
     * 
     * <tr>
     *      <td>0x30.. 0x39</td>
     *      <td>0123456789</td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td>x</td>
     *      <td>x</td>
     *      <td>x</td>
     *      <td> </td>
     *      <td>x</td>
     *      <td>x</td>
     * </tr>
     * 
     * <tr>
     *      <td>0x3A.. 0x40</td>
     *      <td>:;&lt;=&gt;?&#64;</td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td>x</td>
     *      <td>x</td>
     *      <td>x</td>
     * </tr>
     * 
     * <tr>
     *      <td>0x41.. 0x46</td>
     *      <td>ABCDEF</td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td>x</td>
     *      <td> </td>
     *      <td>x</td>
     *      <td> </td>
     *      <td>x</td>
     *      <td>x</td>
     *      <td> </td>
     *      <td>x</td>
     *      <td>x</td>
     * </tr>
     * 
     * <tr>
     *      <td>0x47.. 0x5A</td>
     *      <td>GHIJKLMNOPQRSTUVWXYZ</td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td>x</td>
     *      <td> </td>
     *      <td>x</td>
     *      <td> </td>
     *      <td> </td>
     *      <td>x</td>
     *      <td> </td>
     *      <td>x</td>
     *      <td>x</td>
     * </tr>
     * 
     * <tr>
     *      <td>0x5B.. 0x60</td>
     *      <td>[\]^_`</td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td>x</td>
     *      <td>x</td>
     *      <td>x</td>
     * </tr>
     * 
     * <tr>
     *      <td>0x61.. 0x66</td>
     *      <td>abcdef</td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td>x</td>
     *      <td>x</td>
     *      <td> </td>
     *      <td>x</td>
     *      <td>x</td>
     *      <td> </td>
     *      <td>x</td>
     *      <td>x</td>
     * </tr>
     * 
     * <tr>
     *      <td>0x67.. 0x7A</td>
     *      <td>ghijklmnopqrstuvwxyz</td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td>x</td>
     *      <td>x</td>
     *      <td> </td>
     *      <td> </td>
     *      <td>x</td>
     *      <td> </td>
     *      <td>x</td>
     *      <td>x</td>
     * </tr>
     * 
     * <tr>
     *      <td>0x7B.. 0x7E</td>
     *      <td>{|}~</td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td>x</td>
     *      <td>x</td>
     *      <td>x</td>
     * </tr>
     * 
     * <tr>
     *      <td>0x7F</td>
     *      <td>(DEL)</td>
     *      <td>x</td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     *      <td> </td>
     * </tr>
     * 
     * </table>
     * 
     * The characters in the extended character set (above 0x7F) may belong to
     * diverse categories depending on the locale and the platform.
     * As a general rule, ispunct, isgraph and isprint return true on these for
     * the standard C locale on most platforms supporting extended character sets.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion AVM 0.4.1
     * 
     * @see http://www.cplusplus.com/reference/cctype/ cctype ASCII chars map
     */
    public const MAX_VALUE:int = 0x7F;

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