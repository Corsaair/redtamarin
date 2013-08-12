/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/**
* The flash.error package contains error classes that are part of
* the Flash Player Application Programming Interface (API),
* rather than part of the ActionScript core language.
*/
package flash.errors
{
    /**
     * The IOError exception is thrown when some type of input or output failure occurs.
     * 
     * <p>For example, an IOError exception is thrown if a read/write operation is attempted on a
     * socket that has not connected or that has become disconnected.</p>
     *
     * @langversion ActionScript 3.0
     * @playerversion Flash Player 9
     * @playerversion AIR 1.0
    */
    public dynamic class IOError extends Error
    {
        public function IOError(message:String = "", id:int = 0)
        {
            super(message, id);
        }   
    }

    public dynamic class EOFError extends IOError
    {
        public function EOFError(message:String = "", id:int = 0)
        {
            super(message, id);
        }   
    }

    public dynamic class MemoryError extends Error
    {
        public function MemoryError(message:String = "", id:int = 0)
        {
            super(message, id);
        }   
    }

    /**
     * The IllegalOperationError exception is thrown when a method is not implemented
     * or the implementation doesn't cover the current usage.
     * 
     * @langversion ActionScript 3.0
     * @playerversion Flash Player 9
     * @playerversion AIR 1.0
     */
    public dynamic class IllegalOperationError extends Error
    {
        public function IllegalOperationError(message:String = "", id:int = 0)
        {
            super(message, id);
        }   
    }

    IOError.prototype.name                  = "IOError"
    MemoryError.prototype.name              = "MemoryError"
    EOFError.prototype.name                 = "EOFError"
    IllegalOperationError.prototype.name    = "IllegalOperationError"
}
