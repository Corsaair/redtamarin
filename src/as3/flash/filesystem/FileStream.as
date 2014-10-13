/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.filesystem
{
    
    /**
     * A FileStream object is used to read and write files.
     * Files can be opened synchronously by calling the <code>open()</code> method
     * or asynchronously by calling the <code>openAsync()</code> method.
     * 
     * @langversion 3.0
     * @playerversion AIR 1.0
     */
    [API(AVMGLUE::AIR_1_0)]
    public class FileStream
    {
        
        /**
         * Creates a FileStream object.
         * Use the <code>open()</code> or <code>openAsync()</code> method to open a file.
         *
         * @langversion 3.0
         * @playerversion AIR 1.0
         */
        [API(AVMGLUE::AIR_1_0)]
        public function FileStream()
        {
            super();

        }

        /**
         * Opens the FileStream object synchronously,
         * pointing to the <code>file</code> specified by the file parameter.
         *
         * <p>
         * If the FileStream object is already open, calling the method closes the file
         * before opening and no further events (including <code>close</code>) are delivered
         * for the previously opened file.
         * </p>
         *
         * <p>
         * On systems that support file locking, a file opened in "write" or "update" mode
         * (<code>FileMode.WRITE</code> or <code>FileMode.UPDATE</code>) is not readable
         * until it is closed.
         * </p>
         *
         * <p>
         * Once you are done performing operations on the file, call the <code>close()</code> method
         * of the FileStream object.
         * Some operating systems limit the number of concurrently open files.
         * </p>
         *
         * @example
         * <p>
         * The following code shows how to synchronously open a test.txt file in the Apollo Test
         * subdirectory of the user's documents directory and then read the file into a string,
         * using the system character set as the text encoding.
         * </p>
         * 
         * <listing>
         * import flash.filesystem.&#42;;
         * 
         * var file:File = File.documentsDirectory;
         * file = file.resolvePath("Apollo Test/test.txt");
         * var fileStream:FileStream = new FileStream();
         * fileStream.open(file, FileMode.READ);
         * var str:String = fileStream.readMultiByte(file.size, File.systemCharset);
         * trace(str);
         * fileStream.close();
         * 
         * </listing>
         * 
         * @param file The File object specifying the file to open.
         * @param fileMode A string from the FileMode class that defines the capabilities
         *                 of the FileStream, such as the ability to read from or write to the file.
         *
         * @throws IOError The file does not exist; you do not have adequate permissions to open the file;
         *                 you are opening a file for read access, and you do not have read permissions;
         *                 or you are opening a file for write access, and you do not have write permissions.
         * 
         * @throws SecurityError The file location is in the application directory,
         *                       and the <code>fileMode</code> parameter is set to
         *                       "append", "update", or "write" mode.
         * 
         * @langversion 3.0
         * @playerversion AIR 1.0
         */
        [API(AVMGLUE::AIR_1_0)]
        public function open( file:File, fileMode:String ):void
        {

        }

        /**
         * Opens the FileStream object asynchronously,
         * pointing to the file specified by the <code>file</code> parameter.
         *
         * @param file The File object specifying the file to open.
         * @param fileMode A string from the FileMode class that defines the capabilities
         *                 of the FileStream, such as the ability to read from or write to the file.
         * 
         * @langversion 3.0
         * @playerversion AIR 1.0
         */
        [API(AVMGLUE::AIR_1_0)]
        public function openAsync( file:File, fileMode:String ):void
        {

        }

        /**
         * Truncates the file at the position specified by
         * the <code>position</code> property of the FileStream object.
         *
         * <p>
         * Bytes from the position specified by the <code>position</code> property
         * to the end of the file are deleted.
         * The file must be open for writing.
         * </p>
         *
         * @example
         * <p>
         * The following code synchronously opens a test.txt file in the Apollo Test subdirectory
         * of the user's documents directory and then trims the file to 100 characters in length
         * if it is longer than 100 characters.
         * </p>
         * 
         * <listing>
         * import flash.filesystem.&#42;;
         * 
         * var file:File = File.documentsDirectory;
         * file = file.resolvePath("Apollo Test/test.txt");
         * var fileStream:FileStream = new FileStream();
         * fileStream.open(file, FileMode.UPDATE);
         * if (file.size &gt; 100) {
         *     fileStream.position = 100;
         *     fileStream.truncate();
         * }
         * fileStream.close();
         * 
         * </listing>
         *
         * <p>
         * The following code <i>asynchronously</i> opens a test.txt file in the Apollo Test subdirectory
         * of the user's documents directory, and then trims the file to 100 characters in length
         * if it is longer than 100 characters.
         * </p>
         *
         * <listing>
         * import flash.filesystem.&#42;;
         * 
         * var file:File = File.documentsDirectory;
         * file = file.resolvePath("Apollo Test/test.txt");
         * var fileStream:FileStream = new FileStream();
         * fileStream.openAsync(file, FileMode.UPDATE);
         * trace("start", file.size);
         * if (file.size &gt; 100) {
         *     fileStream.position = 100;
         *     fileStream.truncate();
         * }
         * fileStream.addEventListener(Event.CLOSE, fileClosed);
         * fileStream.close();
         * function fileClosed(event:Event):void {
         *     trace("closed", file.size);
         * }
         * 
         * </listing>
         * 
         * @throws IllegalOperationError The file is not open for writing.
         * 
         * @langversion 3.0
         * @playerversion AIR 1.0
         */
        [API(AVMGLUE::AIR_1_0)]
        public function truncate():void
        {

        }

        /**
         * Closes the FileStream object.
         *
         * @langversion 3.0
         * @playerversion AIR 1.0
         */
        [API(AVMGLUE::AIR_1_0)]
        public function close():void
        {

        }
    }
}