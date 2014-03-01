/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is [Open Source Virtual Machine.].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2004-2006
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Adobe AS3 Team
 *   Zwetan Kjukov <zwetan@gmail.com>.
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

package flash.geom
{
    public class Point
    {
        public var x:Number;
        public var y:Number;
        
        public function Point( x:Number=0, y:Number=0 )
        {
            super();
            
            this.x = x;
            this.y = y;
        }
        
        public static function interpolate( pt1:Point, pt2:Point, f:Number ):Point
        {
            return new Point( (pt2.x + (f * (pt1.x - pt2.x))) , (pt2.y + (f * (pt1.y - pt2.y))) );
        }
        
        public static function distance( pt1:Point, pt2:Point ):Number { return pt1.subtract( pt2 ).length; }
        
        public static function polar( len:Number, angle:Number ):Point
        {
            return new Point( (len * Math.cos(angle)), (len * Math.sin(angle)) );
        }
        
        
        public function get length():Number { return Math.sqrt( (x * x) + (y * y) ); }
        
        public function clone():Point { return new Point( x, y ); }
        
        public function offset( dx:Number, dy:Number ):void { x += dx; y += dy; }
        
        public function equals( toCompare:Point ):Boolean { return (toCompare.x == x) && (toCompare.y == y); }
        
        public function subtract( v:Point ):Point { return new Point( (x - v.x), (y - v.y) ); }
        
        public function add( v:Point ):Point { return new Point( (x + v.x), (y + v.y) ); }
        
        public function normalize( thickness:Number ):void
        {
            var invD:Number = length;
            
            if (invD > 0)
            {
                invD = (thickness / invD);
                x *= invD;
                y *= invD;
            }
        }
        
        public function toString():String { return "(x=" + x + ", y=" + y + ")"; }
    }
}