/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.utils
{
    import avmplus.*;
    
    /**
     * Returns the fully qualified class name of the base class of the object specified by the <code>value</code> parameter.
     * This function provides a quicker way of retrieving the base class name than <code>describeType()</code>,
     * but also doesn't provide all the information <code>describeType()</code> does.
     * 
     * <p>
     * After you retrieve the name of a class with this function,
     * you can convert the class name to a class reference with the <code>getDefinitionByName()</code> function.
     * </p>
     *
     * <p>
     * <b>Note: </b> This function restricts itself to instance hierarchies,
     * whereas the <code>describeType()</code> function uses class object hierarchies
     * if the <code>value</code> parameter is a data type.
     * Calling <code>describeType()</code> on a data type returns the superclass based on the class object hierarchy,
     * in which all class objects inherit from Class.
     * The <code>getQualifiedSuperclassName()</code> function, however, ignores the class object hierarchy
     * and returns the superclass based on the more familiar instance hierarchy.
     * For example, calling <code>getQualifiedSuperclassName(String)</code> returns <code>Object</code>
     * although technically the String class object inherits from Class.
     * In other words, the results are the same whether you use an instance of a type or the type itself.
     * </p>
     * 
     * @param value The object
     * @return An XML object
     * 
	 * @playerversion Flash 9
	 * @playerversion AIR 1.0
	 * @langversion 3.0
     *
     * @see flash.utils#describeType() describeType()
     * @see flash.utils#getDefinitionByName() getDefinitionByName()
     * @see flash.utils#getQualifiedClassName() getQualifiedClassName()
     */
    public function getQualifiedSuperclassName( value:* ):String
    {
        return avmplus.getQualifiedSuperclassName( value );
    }
}
