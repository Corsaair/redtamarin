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
 *   zwetan <zwetan@gmail.com>
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
 
 
 package standard
    {
    
    /* Enum: Operations
    */
    public class Operations
        {
        
        /* property: RDONLY
            Open for reading only.
         */
        public static const RDONLY:int = 0x0000;

        /* property: WRONLY
            Open for writing only.
         */
        public static const WRONLY:int = 0x0001;
        
        /* property: RDWR
            Open for reading and writing.
         */
        public static const RDWR:int = 0x0002;
        
        /* property: APPEND
            Writes done at eof.
         */
        public static const APPEND:int = 0x0008;
        
        /* property: CREAT
            Create and open file.
         */
        public static const CREAT:int = 0x0100;
        
        /* property: TRUNC
            Open and truncate.
         */
        public static const TRUNC:int = 0x0200;
        
        /* property: EXCL
            Open only if file doesn't already exist.
         */
        public static const EXCL:int = 0x0400;
        
        /* property: TEXT
            File mode is text (translated).
            
            note:
            Text files have <cr><lf> sequecnes translated to <lf> using read()
            and <lf> sequecnes translated to <cr><lf> using write().
         */
        public static const TEXT:int = 0x4000;
        
        /* property: BINARY
            File mode is binary (translated).
         */
        public static const BINARY:int = 0x8000;
        
        /* property: WTEXT
            File mode is UTF16 (translated).
         */
        public static const WTEXT:int = 0x10000;
        
        /* property: U16TEXT
            File mode is UTF16 no BOM (translated).
         */
        public static const U16TEXT:int = 0x20000;
        
        /* property: U8TEXT
            File mode is UTF8 no BOM (translated).
         */
        public static const U8TEXT:int = 0x40000;
        
        /* property: NOINHERIT
            Open handle inherit bit,
            child process doesn't inherit file.
         */
        public static const NOINHERIT:int = 0x0080;
        
        /* property: TEMPORARY
            Temporary file bit,
            file is deleted when last handle is closed.
         */
        public static const TEMPORARY:int = 0x0040;
        
        /* property: SHORTLIVED
            Temporary acces hint to indicate this is
            a temporary storage file, try not to flush.
         */
        public static const SHORTLIVED:int = 0x1000;
        
        /* property: SEQUENTIAL
            Sequential access hint,
            file access is primarily sequencial.
         */
        public static const SEQUENTIAL:int = 0x0020;
        
        /* property: RANDOM
            Random access hint,
            file access is primarily random.
         */
        public static const RANDOM:int = 0x0010;
        
        }
    
    }
    