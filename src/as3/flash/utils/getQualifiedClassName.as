/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.utils
{
    import avmplus.*;
    
    /**
     * Returns the fully qualified class name of an object.
     * 
     * @param value The object for which a fully qualified class name is desired.
     * Any ActionScript value may be passed to this method including all available ActionScript types,
     * object instances, primitive types such as uint, and class objects.
     * @return  A string containing the fully qualified class name.
     * 
	 * @playerversion Flash 9
	 * @playerversion AIR 1.0
	 * @langversion 3.0
     *
     * @see flash.utils#describeType() describeType()
     * @see flash.utils#getQualifiedSuperclassName() getQualifiedSuperclassName()
     */
    public function getQualifiedClassName( value:* ):String
    {
        return avmplus.getQualifiedClassName( value );
    }
}
