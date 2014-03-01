/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.utils
{
    import avmplus.*;
    
    /**
     * Produces an XML object that describes the ActionScript object named as the parameter of the method.
     * This method implements the programming concept of <i>reflection</i> for the ActionScript language.
     * 
     * 
     * <p>
     * If the <code>value</code> parameter is an instance of a type,
     * the returned XML object includes all the instance properties of that type,
     * but does not include any static properties.
     * You can check for this condition when you parse the XML object by examining
     * the value of the <code>&lt;type&gt;</code> tag's <code>isStatic</code> attribute,
     * which is <code>false</code> when the <code>value</code> parameter is an instance of a type.
     * </p>
     *
     * <p>
     * To obtain the static properties of a type, pass the type itself for the <code>value</code> parameter.
     * The returned XML object includes not only the type's static properties, but also all of its instance properties.
     * The instance properties are nested inside a tag named <code>&lt;factory&gt;</code> to distinguish them
     * from the static properties.
     * In this case, the <code>isStatic</code> attribute of the <code>&lt;type&gt;</code> tag is <code>true</code>.
     * </p>
     *
     * <p>
     * <b>Note: </b> If you need only to traverse an object's inheritance hierarchy and do not need the other
     * information provided by <code>describeType()</code>, use the <code>getQualifiedClassName()</code> and
     * <code>getQualifiedSuperclassName()</code> functions instead.
     * </p>
     * 
     * <p>
     * The following table describes some of the tags and attributes of the XML object generated
     * by <code>describeType()</code> (all class and interface names returned are in fully qualified format):
     * 
     * <table class="innertable">
     * <tr>
     *      <th>Tag</th>
     *      <th>Attribute</th>
     *      <th>Description</th>
     * </tr>
     * <tr>
     *      <td>&lt;type&gt;</td>
     *      <td> </td>
     *      <td>The root tag of the XML object.</td>
     * </tr>
     * <tr>
     *      <td> </td>
     *      <td>name</td>
     *      <td>The name of the ActionScript object's data type.</td>
     * </tr>
     * <tr>
     *      <td> </td>
     *      <td>base</td>
     *      <td>The immediate superclass of the ActionScript object's defining class. If the ActionScript object is a class object, the value is <code>Class</code>.</td>
     * </tr>
     * <tr>
     *      <td> </td>
     *      <td>isDynamic</td>
     *      <td><code>true</code> if the ActionScript object's defining class is dynamic; <code>false</code> otherwise. If the ActionScript object is a class object, the value is <code>true</code> because the Class class is dynamic.</td>
     * </tr>
     * <tr>
     *      <td> </td>
     *      <td>isFinal</td>
     *      <td><code>true</code> if the ActionScript object's defining class is final; <code>false</code> otherwise.</td>
     * </tr>
     * <tr>
     *      <td> </td>
     *      <td>isStatic</td>
     *      <td><code>true</code> if the ActionScript object is a class object or constructor function; <code>false</code> otherwise. This attribute is named <code>isStatic</code> because if it is <code>true</code>, any tags that are not nested inside the <code>factory</code> tag are static.</td>
     * </tr>
     * <tr>
     *      <td>&lt;extendsClass&gt;</td>
     *      <td> </td>
     *      <td>There is a separate <code>extendsClass</code> tag for each superclass of the ActionScript object's defining class.</td>
     * </tr>
     * <tr>
     *      <td> </td>
     *      <td>type</td>
     *      <td>The name of a superclass that the ActionScript object's defining class extends.</td>
     * </tr>
     * <tr>
     *      <td>&lt;implementsInterface&gt;</td>
     *      <td> </td>
     *      <td>There is a separate <code>implementsInterface</code> tag for each interface implemented by the ActionScript object's defining class or any of its superclasses.</td>
     * </tr>
     * <tr>
     *      <td> </td>
     *      <td>type</td>
     *      <td>The name of an interface that the ActionScript object's defining class implements.</td>
     * </tr>
     * <tr>
     *      <td>&lt;accessor&gt;</td>
     *      <td> </td>
     *      <td>An accessor is a property defined by getter and setter functions.</td>
     * </tr>
     * <tr>
     *      <td> </td>
     *      <td>name</td>
     *      <td>The name of the accessor.</td>
     * </tr>
     * <tr>
     *      <td> </td>
     *      <td>access</td>
     *      <td>The access rights of the property. Possible values include <code>readonly</code>, <code>writeonly</code>, and <code>readwrite</code>.</td>
     * </tr>
     * <tr>
     *      <td> </td>
     *      <td>type</td>
     *      <td>The data type of the property.</td>
     * </tr>
     * <tr>
     *      <td> </td>
     *      <td>declaredBy</td>
     *      <td>The class that contains the associated getter or setter functions.</td>
     * </tr>
     * <tr>
     *      <td>&lt;constant&gt;</td>
     *      <td> </td>
     *      <td>A constant is a property defined with the <code>const</code> statement.</td>
     * </tr>
     * <tr>
     *      <td> </td>
     *      <td>name</td>
     *      <td>The name of the constant.</td>
     * </tr>
     * <tr>
     *      <td> </td>
     *      <td>type</td>
     *      <td>The data type of the constant.</td>
     * </tr>
     * <tr>
     *      <td>&lt;method&gt;</td>
     *      <td> </td>
     *      <td>A method is a function declared as part of a class definition.</td>
     * </tr>
     * <tr>
     *      <td> </td>
     *      <td>name</td>
     *      <td>The name of the method.</td>
     * </tr>
     * <tr>
     *      <td> </td>
     *      <td>declaredBy</td>
     *      <td>The class that contains the method definition.</td>
     * </tr>
     * <tr>
     *      <td> </td>
     *      <td>returnType</td>
     *      <td>The data type of the method's return value.</td>
     * </tr>
     * <tr>
     *      <td>&lt;parameter&gt;</td>
     *      <td> </td>
     *      <td>There is a separate <code>parameter</code> tag for each parameter that a method defines. This tag is always nested inside a <code>&lt;method&gt;</code> tag.</td>
     * </tr>
     * <tr>
     *      <td> </td>
     *      <td>index</td>
     *      <td>A number corresponding to the order in which the parameter appears in the method's parameter list. The first parameter has a value of 1.</td>
     * </tr>
     * <tr>
     *      <td> </td>
     *      <td>type</td>
     *      <td>The data type of the parameter.</td>
     * </tr>
     * <tr>
     *      <td> </td>
     *      <td>optional</td>
     *      <td><code>true</code> if the parameter is optional; <code>false</code> otherwise.</td>
     * </tr>
     * <tr>
     *      <td>&lt;variable&gt;</td>
     *      <td> </td>
     *      <td>A variable is a property defined with the <code>var</code> statement.</td>
     * </tr>
     * <tr>
     *      <td> </td>
     *      <td>name</td>
     *      <td>The name of the variable.</td>
     * </tr>
     * <tr>
     *      <td> </td>
     *      <td>type</td>
     *      <td>The data type of the variable.</td>
     * </tr>
     * <tr>
     *      <td>&lt;factory&gt;</td>
     *      <td> </td>
     *      <td>If the ActionScript object is a class object or constructor function, all instance properties and methods are nested inside this tag. If the <code>isStatic</code> attribute of the <code>&lt;type&gt;</code> tag is <code>true</code>, all properties and methods that are not nested within the <code>&lt;factory&gt;</code> tag are static. This tag appears only if the ActionScript object is a class object or constructor function.</td>
     * </tr>
     * </table>
     * </p>
     * 
     * @example
     * <listing>
     * package
     * {
     *      import flash.display.Sprite;
     *      import flash.utils.describeType;
     * 
     *      public class DescribeTypeExample extends Sprite
     *      {
     *          public function DescribeTypeExample()
     *          {
     *              var child:Sprite = new Sprite();
     *              var description:XML = describeType( child );
     *              trace( description..accessor.&#64;name.toXMLString() );
     *          }
     *      }
     * }
     * </listing>
     * 
     * @param value The object for which a type description is desired.
     * Any ActionScript value may be passed to this method including all available ActionScript
     * types, object instances, primitive types such as uint, and class objects.
     * @return An XML object containing details about the object that was passed in as a parameter.
     * It provides the following information about the object:
     * <ul>
     *   <li>The class of the object</li>
     *   <li>The attributes of the class</li>
     *   <li>The inheritance tree from the class to its base classes</li>
     *   <li>The interfaces implemented by the class</li>
     *   <li>The declared instance properties of the class</li>
     *   <li>The declared static properties of the class</li>
     *   <li>The instance methods of the class</li>
     *   <li>The static methods of the class</li>
     *   <li>For each method of the class, the name, number of parameters, return type, and parameter types</li>
     * </ul>
     * 
	 * @playerversion Flash 9
	 * @playerversion AIR 1.0
	 * @langversion 3.0
     *
     * @see flash.utils#getQualifiedClassName() getQualifiedClassName()
     * @see flash.utils#getQualifiedSuperclassName() getQualifiedSuperclassName()
     */
    public function describeType( value:* ):XML
    {
        return avmplus.describeType( value, FLASH10_FLAGS );
    }
}
