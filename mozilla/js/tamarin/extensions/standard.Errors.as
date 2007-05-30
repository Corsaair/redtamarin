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
    
    /* Enum: Errors
     */
    public class Errors
        {
        
        /* property: EPERM
            Operation not permitted.
         */
        public static const EPERM:int = 1;
        
        /* property: ENOENT
            No such file or directory.
         */
        public static const ENOENT:int = 2;
        
        /* property: ESRCH
            No such process.
         */
        public static const ESRCH:int = 3;
        
        /* property: EINTR
            Interrupted function.
         */
        public static const EINTR:int = 4;
        
        /* property: EIO
            I/O error.
         */
        public static const EIO:int = 5;
        
        /* property: ENXIO
            No such device or address.
         */
        public static const ENXIO:int = 6;
        
        /* property: E2BIG
            Argument list too long.
         */
        public static const E2BIG:int = 7;
        
        /* property: ENOEXEC
            Exec format error.
         */
        public static const ENOEXEC:int = 8;
        
        /* property: EBADF
            Bad file number.
         */
        public static const EBADF:int = 9;
        
        /* property: ECHILD
            No spawned processes.
         */
        public static const ECHILD:int = 10;
        
        /* property: EAGAIN
            No more processes or not enough memory or maximum nesting level reached.
         */
        public static const EAGAIN:int = 11;
        
        /* property: ENOMEM
            Not enough memory.
         */
        public static const ENOMEM:int = 12;
        
        /* property: EACCESS
            permission denied.
         */
        public static const EACCESS:int = 13;
        
        /* property: EFAULT
            Bad address.
         */
        public static const EFAULT:int = 14;
        
        /* property: EBUSY
            Device or ressource busy.
         */
        public static const EBUSY:int = 16;
        
        /* property: EEXIST
            File exists.
         */
        public static const EEXIST:int = 17;
        
        /* property: EXDEV
            Cross-device link.
         */
        public static const EXDEV:int = 18;
        
        /* property: ENODEV
            No such device.
         */
        public static const ENODEV:int = 19;
        
        /* property: ENOTDIR
            Not a directory.
         */
        public static const ENOTDIR:int = 20;
        
        /* property: EISDIR
            Is a directory.
         */
        public static const EISDIR:int = 21;
        
        /* property: EINVAL
            Invalid argument.
         */
        public static const EINVAL:int = 22;
        
        /* property: ENFILE
            Too many files open in system.
         */
        public static const ENFILE:int = 23;
        
        /* property: EMFILE
            Too many open files.
         */
        public static const EMFILE:int = 24;
        
        /* property: ENOTTY
            Inappropriate I/O control operation.
         */
        public static const ENOTTY:int = 25;
        
        /* property: EFBIG
            File too large.
         */
        public static const EFBIG:int = 27;
        
        /* property: ENOSPC
            No space left on device.
         */
        public static const ENOSPC:int = 28;
        
        /* property: ESPIPE
            Invalid seek.
         */
        public static const ESPIPE:int = 29;
        
        /* property: EROFS
            Read-only file system.
         */
        public static const EROFS:int = 30;
        
        /* property: EMLINK
            Too many links.
         */
        public static const EMLINK:int = 31;
        
        /* property: EPIPE
            Broken pipe.
         */
        public static const EPIPE:int = 32;
        
        /* property: EDOM
            Math argument.
         */
        public static const EDOM:int = 33;
        
        /* property: ERANGE
            Result too large.
         */
        public static const ERANGE:int = 34;
        
        /* property: EDEADLOCK
            Ressource deadlock would occur.
         */
        public static const EDEADLOCK:int = 36;
        
        /* property: ENAMETOOLONG
            Filename too long.
         */
        public static const ENAMETOOLONG:int = 38;
        
        /* property: ENOLCK
            No locks available.
         */
        public static const ENOLCK:int = 39;
        
        /* property: ENOSYS
            Function not supported.
         */
        public static const ENOSYS:int = 40;
        
        /* property: ENOTEMPTY
            Directory not empty.
         */
        public static const ENOTEMPTY:int = 41;
        
        /* property: EILSEQ
            Illegal byte sequence.
         */
        public static const EILSEQ:int = 42;
        
        /* property: STRUNCATE
            String was truncated.
         */
        public static const STRUNCATE:int = 80;
        
        }
    
    }
 