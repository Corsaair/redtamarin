/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.filesystem
{
    
    /**
     * The FileMode class defines string constants used in the <code>fileMode</code> parameter
     * of the <code>open()</code> and <code>openAsync()</code> methods of the FileStream class.
     * The <code>fileMode</code> parameter of these methods determines the capabilities
     * available to the FileStream object once the file is opened.
     * 
     * <p>
     * The following capabilities are available, in various combinations,
     * based on the <code>fileMode</code> parameter value specified in the open method:
     * </p>
     * 
     * <ul>
     * <li>
     * Reading —
     * The FileStream object can read data from the file.
     * </li>
     * <li>
     * Writing —
     * The FileStream object can write data to the file.
     * </li>
     * <li>
     * Creating —
     * The FileStream object creates a nonexistent file upon opening.
     * </li>
     * <li>
     * Truncate upon opening —
     * Data in the file is deleted upon opening (before any data is written).
     * </li>
     * <li>
     * Append written data —
     * Data is always written to the end of the file (when any write method is called).
     * </li>
     * </ul>
     *
     * <p>
     * The following table shows the capabilities that each constant in the FileMode class provides
     * when applied as the <code>fileMode</code> parameter of an open method of a FileStream object:
     * </p>
     *
     * <table class="innertable">
     * <tr><th>FileMode constant</th><th>Reading</th><th>Writing</th><th>Creating</th><th>Truncate upon opening</th><th>Append written data</th></tr>
     * <tr><td><code>READ</code></td>  <td> • </td><td>   </td><td>   </td><td>   </td><td>   </td></tr>
     * <tr><td><code>WRITE</code></td> <td>   </td><td> • </td><td> • </td><td> • </td><td>   </td></tr>
     * <tr><td><code>APPEND</code></td><td>   </td><td> • </td><td> • </td><td>   </td><td> • </td></tr>
     * <tr><td><code>UPDATE</code></td><td>   </td><td> • </td><td> • </td><td>   </td><td>   </td></tr>
     * </table>
     * 
     * @langversion 3.0
     * @playerversion AIR 1.0
     */
    [API(AVMGLUE::AIR_1_0)]
    public class FileMode
    {
        
        /**
         * Used for a file to be opened in read-only mode.
         * The file must exist (missing files are not created).
         *
         * @langversion 3.0
         * @playerversion AIR 1.0
         */
        [API(AVMGLUE::AIR_1_0)]
        public static const READ:String   = "read";

        /**
         * Used for a file to be opened in write-only mode.
         * Upon opening, any nonexistent file is created,
         * and any existing file is truncated (its data is deleted).
         *
         * @langversion 3.0
         * @playerversion AIR 1.0
         */
        [API(AVMGLUE::AIR_1_0)]
        public static const WRITE:String  = "write";

        /**
         * Used for a file to be opened in read/write mode.
         * Upon opening, any nonexistent file is created.
         *
         * @langversion 3.0
         * @playerversion AIR 1.0
         */
        [API(AVMGLUE::AIR_1_0)]
        public static const UPDATE:String = "update";

        /**
         * Used for a file to be opened in write mode,
         * with all written data appended to the end of the file.
         * Upon opening, any nonexistent file is created.
         *
         * @langversion 3.0
         * @playerversion AIR 1.0
         */
        [API(AVMGLUE::AIR_1_0)]
        public static const APPEND:String = "append";

    }
}