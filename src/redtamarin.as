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
 *   Zwetan Kjukov <zwetan@gmail>.
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

package avmplus
{
    
    public class CompatibilityMode
    {
        public static const tamarin:uint     = 0;
        public static const redtamarin:uint  = 1;
        public static const flashPlayer:uint = 2;
    }
    
    [native(cls="RedtamarinClass", methods="auto")]
    public class redtamarin
    {
        /* note:
           the assert here is just an example,
           use it will crash the avmshell.
           
           ex:
           ﻿import avmplus.redtamarin;
           redtamarin.assert( 0 );
           
           result:
           redtamarin-trunk/src/shell/../extensions/RedtamarinClass.cpp:65:
           failed assertion `expression'
           ./test.sh: line 11: 58465 Abort trap   $avmshell test.abc
        */
        ﻿private native static function ___assert( expression:int ):void;
        
        private static var _compatibility:uint = CompatibilityMode.redtamarin;
        
        public static function assert( expression:int ):void
        {
            redtamarin.___assert( expression );
        }
        
        public static function get compatibility():uint
        {
            return _compatibility;
        }
        
        public static function set compatibility( mode:uint ):void
        {
            _compatibility = mode;
        }
        
        public static function get version():String
        {
            return "0.1.0." + parseInt( "$Rev$".split( " " )[1] );
        }
        
    }
    
}

