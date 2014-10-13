/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */


package
{

    /**
     * Defines methods and properties of the core ActionScript classes
     * that are fixed properties instead of prototype properties.
     * 
     * <p>
     * When you set the "-as3" compiler option to <code>true</code>
     * (which is the default setting in Flex Builder 2),
     * the AS3 namespace is automatically opened for all the core classes.
     * 
     * This means that an instance of a core class will use fixed properties
     * and methods instead of the versions of those same properties and methods
     * that are attached to the class's prototype object.
     * 
     * The use of fixed properties usually provides better performance,
     * but at the cost of backward compatibility with the ECMAScript edition 3
     * language specification (ECMA-262).
     * </p>
     * 
     * @langversion 3.0
     * @playerversion Flash 9
     * @playerversion AIR 1.0
     * 
     * @see Object Object class
     */
    public namespace AS3 = "http://adobe.com/AS3/2006/builtin";

    // Query whether a particular bugfix is in effect for this object.
    // information. Note that we use VM_INTERNAL to hide it from non-builtin code.
    /**
     * Query whether a particular bugfix is in effect for this object.
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     */
    [native("Toplevel::bugzilla")]
    [API(CONFIG::VM_INTERNAL)]
    public native function bugzilla(n:int):Boolean;

    /**
    * @name Toplevel Function Properties
    * Function properties of the global object (ECMA 15.1.2)
    */

    // {DontEnum} length=1
    /**
     * Decodes an encoded URI into a string.
     *
     * <p>
     * Returns a string in which all characters previously encoded by the <code>encodeURI</code>
     * function are restored to their unencoded representation.
     * </p>
     *
     * <p>
     * The following table shows the set of escape sequences that are not decoded
     * to characters by the <code>decodeURI</code> function.
     * 
     * Use <code>decodeURIComponent()</code> to decode the escape sequences in this table.
     * </p>
     *
     * <table class="innertable">
     * <tr>
     *   <th>Escape sequences not decoded</th>
     *   <th>Character equivalents</th>
     * </tr>
     * <tr>
     *   <td><code>%23</code></td>
     *   <td><code>#</code></td>
     * </tr>
     * <tr>
     *   <td><code>%24</code></td>
     *   <td><code>$</code></td>
     * </tr>
     * <tr>
     *   <td><code>%26</code></td>
     *   <td><code>&#38;</code></td>
     * </tr>
     * <tr>
     *   <td><code>%2B</code></td>
     *   <td><code>+</code></td>
     * </tr>
     * <tr>
     *   <td><code>%2C</code></td>
     *   <td><code>,</code></td>
     * </tr>
     * <tr>
     *   <td><code>%2F</code></td>
     *   <td><code>/</code></td>
     * </tr>
     * <tr>
     *   <td><code>%3A</code></td>
     *   <td><code>:</code></td>
     * </tr>
     * <tr>
     *   <td><code>%3B</code></td>
     *   <td><code>;</code></td>
     * </tr>
     * <tr>
     *   <td><code>%3D</code></td>
     *   <td><code>=</code></td>
     * </tr>
     * <tr>
     *   <td><code>%3F</code></td>
     *   <td><code>?</code></td>
     * </tr>
     * <tr>
     *   <td><code>%40</code></td>
     *   <td><code>&#64;</code></td>
     * </tr>
     * </table>
     *
     * @example
     * <listing>
     * package
     * {
     * import flash.display.Sprite;
     * 
     *     public class DecodeURIExample extends Sprite
     *     {
     *         public function DecodeURIExample()
     *         {
     *             var uri:String = "http://www.example.com/application.jsp?user=&lt;user name='some user'&gt;&lt;/user&gt;";
     *             var encoded:String = encodeURI(uri);
     *             var decoded:String = decodeURI(encoded);
     *             trace(uri);        // http://www.example.com/application.jsp?user=&lt;user name='some user'&gt;&lt;/user&gt;
     *             trace(encoded);    // http://www.example.com/application.jsp?user=%3Cuser%20name='some%20user'%3E%3C/user%3E
     *             trace(decoded);    // http://www.example.com/application.jsp?user=&lt;user name='some user'&gt;&lt;/user&gt;
     *         }
     *     }
     * }
     * </listing>
     * 
     * @param uri A string encoded with the <code>encodeURI</code> function.
     * @return A string in which all characters previously escaped by the <code>encodeURI</code>
     * function are restored to their unescaped representation.
     * 
     * @langversion 3.0
     * @playerversion Flash 9
     * @playerversion AIR 1.0
     *
     * @see #decodeURIComponent() decodeURIComponent()
     * @see encodeURI() encodeURI()
     * @see encodeURIComponent() encodeURIComponent()
     */
    [native("Toplevel::decodeURI")]
    public native function decodeURI(uri:String="undefined"):String

    // {DontEnum} length=1
    /**
     * Decodes an encoded URI component into a string.
     *
     * <p>
     * TODO
     * </p>
     * 
     * @langversion 3.0
     * @playerversion Flash 9
     * @playerversion AIR 1.0
     */
    [native("Toplevel::decodeURIComponent")]
    public native function decodeURIComponent(uri:String="undefined"):String

    // {DontEnum} length=1
    /**
     * Encodes a string into a valid URI (Uniform Resource Identifier).
     *
     * <p>
     * TODO
     * </p>
     * 
     * @langversion 3.0
     * @playerversion Flash 9
     * @playerversion AIR 1.0
     */
    [native("Toplevel::encodeURI")]
    public native function encodeURI(uri:String="undefined"):String

    // {DontEnum} length=1
    /**
     * Encodes a string into a valid URI component.
     *
     * <p>
     * TODO
     * </p>
     * 
     * @langversion 3.0
     * @playerversion Flash 9
     * @playerversion AIR 1.0
     */
    [native("Toplevel::encodeURIComponent")]
    public native function encodeURIComponent(uri:String="undefined"):String

    // {DontEnum} length=1
    /**
     * Returns <code>true</code> if the value is <code>NaN</code> (not a number).
     *
     * <p>
     * TODO
     * </p>
     * 
     * @langversion 3.0
     * @playerversion Flash 9
     * @playerversion AIR 1.0
     */
    [native("Toplevel::isNaN")]
    public native function isNaN(n:Number = void 0):Boolean

    // {DontEnum} length=1
    /**
     *
     * @langversion 3.0
     * @playerversion Flash 9
     * @playerversion AIR 1.0
     */
    [native("Toplevel::isFinite")]
    public native function isFinite(n:Number = void 0):Boolean

    // {DontEnum} length=1
    /**
     * Converts a string to an integer.
     *
     * <p>
     * TODO
     * </p>
     * 
     * @langversion 3.0
     * @playerversion Flash 9
     * @playerversion AIR 1.0
     */
    [native("Toplevel::parseInt")]
    public native function parseInt(s:String = "NaN", radix:int=0):Number

    // {DontEnum} length=1
    /**
     * Converts a string to a floating-point number.
     *
     * <p>
     * TODO
     * </p>
     * 
     * @langversion 3.0
     * @playerversion Flash 9
     * @playerversion AIR 1.0
     */
    [native("Toplevel::parseFloat")]
    public native function parseFloat(str:String = "NaN"):Number


    /**
    * @name ECMA-262 Appendix B.2 extensions
    * Extensions to ECMAScript, in ECMA-262 Appendix B.2
    */

    // {DontEnum} length=1
    /**
     * Converts the parameter to a string and encodes it in a URL-encoded format,
     * where most nonalphanumeric characters are replaced with <code>%</code> hexadecimal sequences.
     *
     * <p>
     * TODO
     * </p>
     * 
     * @langversion 3.0
     * @playerversion Flash 9
     * @playerversion AIR 1.0
     */
    [native("Toplevel::escape")]
    public native function escape(s:String="undefined"):String

    // {DontEnum} length=1
    /**
     * Evaluates the parameter <code>str</code> as a string,
     * decodes the string from URL-encoded format
     * (converting all hexadecimal sequences to ASCII characters),
     * and returns the string.
     *
     * <p>
     * TODO
     * </p>
     * 
     * @langversion 3.0
     * @playerversion Flash 9
     * @playerversion AIR 1.0
     */
    [native("Toplevel::unescape")]
    public native function unescape(s:String="undefined"):String

    // {DontEnum} length=1
    /**
     * Determines whether the specified string is a valid name
     * for an XML element or attribute.
     *
     * <p>
     * TODO
     * </p>
     * 
     * @langversion 3.0
     * @playerversion Flash 9
     * @playerversion AIR 1.0
     */
    [native("Toplevel::isXMLName")]
    public native function isXMLName(str=void 0):Boolean    // moved here from XML.as

    // value properties of global object (ECMA 15.1.1)

    // in E262, these are var {DontEnum,DontDelete}  but not ReadOnly
    // but in E327, these are {ReadOnly, DontEnum, DontDelete}
    // we choose to make them const ala E327

    // The initial value of NaN is NaN (section 8.5).
    // E262 { DontEnum, DontDelete}
    // E327 { DontEnum, DontDelete, ReadOnly}
    /**
     * A special member of the Number data type that represents a value
     * that is "not a number" (<code>NaN</code>).
     *
     * <p>
     * When a mathematical expression results in a value that cannot be expressed as a number,
     * the result is <code>NaN</code>.
     * The following list describes common expressions that result in <code>NaN</code>.
     * <ul>
     *   <li>
     *   Division by <code>0</code> results in <code>NaN</code> only if the divisor is also <code>0</code>.
     *   If the divisor is greater than <code>0</code>, division by <code>0</code> results in <code>Infinity</code>.
     *   If the divisor is less than <code>0</code>, division by <code>0</code> results in <code>-Infinity</code>;
     *   </li>
     *   <li>
     *   Square root of a negative number;
     *   </li>
     *   <li>
     *   The arcsine of a number outside the valid range of <code>0</code> to <code>1</code>;
     *   </li>
     *   <li>
     *   <code>Infinity</code> subtracted from <code>Infinity</code>;
     *   </li>
     *   <li>
     *   <code>Infinity</code> or <code>-Infinity</code> divided by <code>Infinity</code> or <code>-Infinity</code>;
     *   </li>
     *   <li>
     *   <code>Infinity</code> or <code>-Infinity</code> multiplied by <code>0</code>;
     *   </li>
     * </ul>
     * </p>
     *
     * <p>
     * The <code>NaN</code> value is not a member of the <code>int</code> or <code>uint</code> data types.
     * </p>
     *
     * <p>
     * The <code>NaN</code> value is not considered equal to any other value,
     * including <code>NaN</code>, which makes it impossible to use the equality operator
     * to test whether an expression is <code>NaN</code>.
     * To determine whether a number is the <code>NaN</code> function, use <code>isNaN()</code>.
     * </p>
     * 
     * @langversion 3.0
     * @playerversion Flash 9
     * @playerversion AIR 1.0
     *
     * @see #isNaN() isNaN()
     * @see Number#NaN Number.NaN
     */
    public const NaN:Number = 0/0;

    // The initial value of Infinity is +8 (section 8.5).
    // E262 { DontEnum, DontDelete}
    // E327 { DontEnum, DontDelete, ReadOnly}
    /**
     * A special value representing positive <code>Infinity</code>.
     *
     * <p>
     * The value of this constant is the same as <code>Number.POSITIVE_INFINITY</code>.
     * </p>
     *
     * @example
     * The result of division by <code>0</code> is <code>Infinity</code>,
     * but only when the divisor is a positive number.
     * <listing>
     * trace(0 / 0);  // NaN
     * trace(7 / 0);  // Infinity
     * trace(-7 / 0); // -Infinity
     * </listing>
     * 
     * @langversion 3.0
     * @playerversion Flash 9
     * @playerversion AIR 1.0
     *
     * @see Number#POSITIVE_INFINITY Number.POSITIVE_INFINITY
     */
    public const Infinity:Number = 1/0;

    // The initial value of undefined is undefined (section 8.1).
    // E262 { DontEnum, DontDelete}
    // E327 { DontEnum, DontDelete, ReadOnly}
    /**
     * A special value that applies to untyped variables that have not been initialized
     * or dynamic object properties that are not initialized.
     *
     * <p>
     * In ActionScript 3.0, only variables that are untyped can hold the value
     * <code>undefined</code>, which is not true in ActionScript 1.0 and ActionScript 2.0.
     * For example, both of the following variables are <code>undefined</code>
     * because they are untyped and unitialized:
     * <ul>
     *   <li><code>var foo;</code></li>
     *   <li><code>var bar:&#42;;</code></li>
     * </ul>
     * </p>
     *
     * <p>
     * The <code>undefined</code> value also applies to uninitialized
     * or undefined properties of dynamic objects.
     * For example, if an object is an instance of the Object class,
     * the value of any dynamically added property is <code>undefined</code>
     * until a value is assigned to that property.
     * </p>
     *
     * <p>
     * Results vary when <code>undefined</code> is used with various functions:
     * <ul>
     *   <li>
     *   The value returned by <code>String(undefined)</code> is <code>"undefined"</code> (<code>undefined</code> is converted to a string).
     *   </li>
     *   <li>
     *   The value returned by <code>Number(undefined)</code> is <code>NaN</code>.
     *   </li>
     *   <li>
     *   The value returned by <code>int(undefined)</code> and <code>uint(undefined)</code> is <code>0</code>.
     *   </li>
     *   <li>
     *   The value returned by <code>Object(undefined)</code> is a new Object instance.
     *   </li>
     *   <li>
     *   When the value <code>undefined</code> is assigned to a typed variable, the value is converted to the default value of the data type.
     *   </li>
     * </ul>
     * </p>
     *
     * <p>
     * Do not confuse <code>undefined</code> with <code>null</code>.
     * When <code>null</code> and <code>undefined</code> are compared with the
     * equality (<code>==</code>) operator, they compare as equal.
     * 
     * However, when <code>null</code> and <code>undefined</code> are compared with the
     * strict equality (<code>===</code>) operator, they compare as not equal.
     * </p>
     *
     * @example
     * In the following example, an untyped variable, <code>myVar</code> is declared but not initialized.
     * The value of <code>myVar</code> is <code>undefined</code> because the variable is untyped.
     * This is true whether the variable has no type annotation or uses the special (<code>&#42;</code>)
     * untyped annotation (<code>var myVar:&#42;;</code>).
     * <listing>
     * // trace value of untyped and uninitialized variable
     * var myVar;
     * trace(myVar); // undefined
     * </listing>
     *
     * <br/>
     * The same rule applies to uninitialized properties of a dynamic object.
     * For example, given an instance, <code>obj</code>, of the dynamic class <code>A</code>,
     * the value of <code>obj.propName</code>, which is an uninitialized property of
     * the <code>obj</code> instance, is <code>undefined</code>.
     * <listing>
     * dynamic class A {}
     * var obj:A = new A()
     * 
     * // trace undefined property of obj
     * trace(obj.propName); // undefined
     * </listing>
     * 
     * @langversion 3.0
     * @playerversion Flash 9
     * @playerversion AIR 1.0
     *
     * @see null null
     */
    public const undefined = void 0;

}
