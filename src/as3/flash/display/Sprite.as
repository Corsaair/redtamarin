/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.display
{
    /**
     * The Sprite class is a basic display list building block: 
     * a display list node that can display graphics and can also contain children.
     * 
     * @langversion 3.0
     * @playerversion Flash 9
     * @playerversion AIR 1.0
     */
    public class Sprite
    {
        
        /**
         * Creates a new Sprite instance.
         * 
         * <p>
         * After you create the Sprite instance,
         * call the <code>DisplayObjectContainer.addChild()</code>
         * or <code>DisplayObjectContainer.addChildAt()</code> method
         * to add the Sprite to a parent <code>DisplayObjectContainer</code>.
         * </p>
         * 
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         */
        public function Sprite()
        {
            super();
        }

    }
}
