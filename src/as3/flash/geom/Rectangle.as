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
    public class Rectangle
    {
        public var x:Number;
        public var y:Number;
        public var width:Number;
        public var height:Number;
        
        public function Rectangle( x:Number=0, y:Number=0, width:Number=0, height:Number=0 )
        {
            super();
            
            this.x      = x;
            this.y      = y;
            this.width  = width;
            this.height = height;
        }
        
        public function get left():Number { return x; }
        public function set left( value:Number ):void
        {
            x = value;
            width += x - value;
        }
        
        public function get right():Number { return x + width; }
        public function set right( value:Number ):void { width = value - x; }
        
        public function get top():Number { return y; }
        public function set top( value:Number ):void
        {
            y = value;
            height += y - value;
        }
        
        public function get bottom():Number { return y + height; }
        public function set bottom( value:Number ):void { height = value - y; }
        
        public function get topLeft():Point { return new Point( x, y ); }
        
        public function set topLeft( value:Point ):void
        {
            x = value.x;
            y = value.y;
            width  += x - value.x;
            height += y - value.y;
        }
        
        public function get bottomRight():Point { return new Point( right, bottom ); }
        public function set bottomRight( value:Point ):void
        {
            width  = value.x - x;
            height = value.y - y;
        }
        
        public function get size():Point { return new Point( width, height ); }
        public function set size( value:Point ):void
        {
            width  = value.x;
            height = value.y;
        }
        
        public function clone():Rectangle { return new Rectangle( x, y, width, height ); }
        
        public function isEmpty():Boolean { return (width <= 0) || (height <= 0); }
        
        public function setEmpty():void
        {
            x      = 0;
            y      = 0;
            width  = 0;
            height = 0;
        }
        
        public function inflate( dx:Number, dy:Number ):void
        {
            x -= dx;
            y -= dy;
            width  += 2 * dx;
            height += 2 * dy;
        }
        
        public function inflatePoint( point:Point ):void
        {
            x -= point.x;
            y -= point.y;
            width  += 2 * point.x;
            height += 2 * point.y;
        }
        
        public function offset(dx:Number, dy:Number):void
        {
            x += dx;
            y += dy;
        }
        
        public function offsetPoint(point:Point):void
        {
            x += point.x;
            y += point.y;
        }

        public function contains( x:Number, y:Number ):Boolean
        {
            return (x >= this.x) &&
                   (x < (this.x + this.width)) &&
                   (y >= this.y) &&
                   (y < (this.y + this.height));
        }
        
        public function containsPoint( point:Point ):Boolean
        {
            return (point.x >= x) &&
                   (point.x < (x + width)) &&
                   (point.y >= y) &&
                   (point.y < (y + height));
        }
        
        public function containsRect( rect:Rectangle ):Boolean
        {
            var r1:Number = rect.x + rect.width;
            var b1:Number = rect.y + rect.height;
            var r2:Number = x + width;
            var b2:Number = y + height;
            
            return (rect.x >= x) &&
                   (rect.x < r2) &&
                   (rect.y >= y) &&
                   (rect.y < b2) &&
                   (r1 > x) &&
                   (r1 <= r2) &&
                   (b1 > y) &&
                   (b1 <= b2);
        }
        
        public function intersection( toIntersect:Rectangle ):Rectangle
        {
            var result:Rectangle = new Rectangle();
            
            if( isEmpty() || toIntersect.isEmpty() )
            {
                result.setEmpty();
                return result;
            }
            
            result.x = Math.max( x, toIntersect.x );
            result.y = Math.max( y, toIntersect.y );
            result.width  = Math.min( (x + width), (toIntersect.x + toIntersect.width) ) - result.x;
            result.height = Math.min( (y + height), (toIntersect.y + toIntersect.height) ) - result.y;
            
            if( (result.width <= 0) || (result.height <= 0) ) { result.setEmpty(); }
            
            return result;
        }
        
        public function intersects( toIntersect:Rectangle ):Boolean
        {
            if( isEmpty() || toIntersect.isEmpty() ) { return false; }
            
            var resultx:Number = Math.max( x, toIntersect.x );
            var resulty:Number = Math.max( y, toIntersect.y );
            var resultwidth:Number  = Math.min( (x + width),  (toIntersect.x + toIntersect.width) ) - resultx;
            var resultheight:Number = Math.min( (y + height), (toIntersect.y + toIntersect.height) ) - resulty;
            
            if( (resultwidth <= 0) || (resultheight <= 0) ) { return false; }
            
            return true;
        }
        
        public function union( toUnion:Rectangle ):Rectangle
        {
            if( isEmpty() ) { return toUnion.clone(); };
            
            if( toUnion.isEmpty() ) { return clone(); };
            
            var r:Rectangle = new Rectangle();
                r.x = Math.min( x, toUnion.x );
                r.y = Math.min( y, toUnion.y );
                r.width  = Math.max( (x + width),  (toUnion.x + toUnion.width) ) - r.x;
                r.height = Math.max( (y + height), (toUnion.y + toUnion.height) ) - r.y;
            
            return r;
        }
        
        public function equals( toCompare:Rectangle ):Boolean
        {
            return (toCompare.x == x) &&
                   (toCompare.y == y) &&
                   (toCompare.width == width) &&
                   (toCompare.height == height);
        }
        
        public function toString():String { return "(x=" + x + ", y=" + y + ", w=" + width + ", h=" + height + ")"; }
    }
}