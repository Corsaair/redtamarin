/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.utils
{
    import shell.Domain;
    
    /**
     * Returns a reference to the class object of the class specified by the <code>name</code> parameter.
     * 
     * @example
     * The following example uses the class <code>GetDefinitionByNameExample</code> to create
     * an orange square on the stage.
     * This is accomplished using the following steps:
     * <ol>
     *      <li>Variables for the background color of orange and size of 80 pixels are declared, which will later be used in drawing the square.</li>
     *      <li>Within the constructor, a variable <code>ClassReference</code> of type Class is assigned to Sprite.</li>
     *      <li>An instance of ClassReference called <code>instance</code> is instantiated.</li>
     *      <li>Since <code>instance</code> is, by reference, a Sprite object, a square can be drawn and added to the display list using the methods available to Sprite.</li>
     * </ol>
     * 
     * <listing>
     * package
     * {
     *      import flash.display.DisplayObject;
     *      import flash.display.Sprite;
     *      import flash.utils.getDefinitionByName;
     * 
     *      public class GetDefinitionByNameExample extends Sprite
     *      {
     *          private var bgColor:uint = 0xFFCC00;
     *          private var size:uint = 80;
     * 
     *          public function GetDefinitionByNameExample()
     *          {
     *              var ClassReference:Class = getDefinitionByName( "flash.display.Sprite" ) as Class;
     *              var instance:Object = new ClassReference();
     *              instance.graphics.beginFill( bgColor );
     *              instance.graphics.drawRect( 0, 0, size, size );
     *              instance.graphics.endFill();
     *              addChild( DisplayObject(instance) );
     *          }
     *      }
     * }
     * </listing>
     * 
     * @param name The name of a class.
     * @return Returns a reference to the class object of the class specified by the <code>name</code> parameter.
     *
     * @throws ReferenceError No public definition exists with the specified name.
     * 
	 * @playerversion Flash 9
	 * @playerversion AIR 1.0
	 * @langversion 3.0
     */
    public function getDefinitionByName( name:String ):Object
    {
        return Domain.currentDomain.getClass( name ) as Object;
    }
}
