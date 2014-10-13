/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package C.cpio
{

    /**
     * @name <code>&lt;cpio.h&gt;</code>
     * cpio archive values.
     *
     * <p>
     * Magic numbers for the cpio archive format.
     * </p>
     *
     * @langversion 3.0
     * @playerversion AVM 0.4
     *
     * @see http://pubs.opengroup.org/onlinepubs/9699919799/basedefs/cpio.h.html cpio.h
     */

	/**
	 * Socket.
	 *
     * @langversion 3.0
     * @playerversion AVM 0.4
	 */
	public const C_ISSOCK:int = 0xC000; //oct: 0140000

	/**
	 * Symbolic link.
	 *
     * @langversion 3.0
     * @playerversion AVM 0.4
	 */
	public const C_ISLNK:int = 0xA000; //oct: 0120000

	/**
	 * Reserved.
	 *
     * @langversion 3.0
     * @playerversion AVM 0.4
	 */
	public const C_ISCTG:int = 0x9000; //oct: 0110000

	/**
	 * Regular file.
	 *
     * @langversion 3.0
     * @playerversion AVM 0.4
	 */
	public const C_ISREG:int = 0x8000; //oct: 0100000

	/**
	 * Block special.
	 *
     * @langversion 3.0
     * @playerversion AVM 0.4
	 */
	public const C_ISBLK:int = 0x6000; //oct: 0060000

	/**
	 * Directory.
	 *
     * @langversion 3.0
     * @playerversion AVM 0.4
	 */
	public const C_ISDIR:int = 0x4000; //oct: 0040000

	/**
	 * Character special.
	 *
     * @langversion 3.0
     * @playerversion AVM 0.4
	 */
	public const C_ISCHR:int = 0x2000; //oct: 0020000

	/**
	 * FIFO.
	 *
     * @langversion 3.0
     * @playerversion AVM 0.4
	 */
	public const C_ISFIFO:int = 0x1000; //oct: 0010000

	/**
	 * Set user ID.
	 *
     * @langversion 3.0
     * @playerversion AVM 0.4
	 */
	public const C_ISUID:int = 0x0800; //oct: 0004000

	/**
	 * Set group ID.
	 *
     * @langversion 3.0
     * @playerversion AVM 0.4
	 */
	public const C_ISGID:int = 0x0400; //oct: 0002000

	/**
	 * On directories, restricted deletion flag.
	 *
     * @langversion 3.0
     * @playerversion AVM 0.4
	 */
	public const C_ISVTX:int = 0x0200; //oct: 0001000

	/**
	 * Read by owner.
	 *
     * @langversion 3.0
     * @playerversion AVM 0.4
	 */
	public const C_IRUSR:int = 0x0100; //oct: 0000400

	/**
	 * Write by owner.
	 *
     * @langversion 3.0
     * @playerversion AVM 0.4
	 */
	public const C_IWUSR:int = 0x0080; //oct: 0000200

	/**
	 * Execute by owner.
	 *
     * @langversion 3.0
     * @playerversion AVM 0.4
	 */
	public const C_IXUSR:int = 0x0040; //oct: 0000100

	/**
	 * Read by group.
	 *
     * @langversion 3.0
     * @playerversion AVM 0.4
	 */
	public const C_IRGRP:int = 0x0020; //oct: 0000040

	/**
	 * Write by group.
	 *
     * @langversion 3.0
     * @playerversion AVM 0.4
	 */
	public const C_IWGRP:int = 0x0010; //oct: 0000020

	/**
	 * Execute by group.
	 *
     * @langversion 3.0
     * @playerversion AVM 0.4
	 */
	public const C_IXGRP:int = 0x0008; //oct: 0000010

	/**
	 * Read by others.
	 *
     * @langversion 3.0
     * @playerversion AVM 0.4
	 */
	public const C_IROTH:int = 0x0004; //oct: 0000004

	/**
	 * Write by others.
	 *
     * @langversion 3.0
     * @playerversion AVM 0.4
	 */
	public const C_IWOTH:int = 0x0002; //oct: 0000002

	/**
	 * Execute by others.
	 *
     * @langversion 3.0
     * @playerversion AVM 0.4
	 */
	public const C_IXOTH:int = 0x0001; //oct: 0000001


	/**
	 * Magic constant.
	 * 
     * @langversion 3.0
     * @playerversion AVM 0.4
	 */
	public const MAGIC:String = "070707";
	
    /**
     * @private
     * only here for asdocs
     */
    [Inspectable(environment="none")]
    internal function dummy():void
    {
        //do nothing
    }

}