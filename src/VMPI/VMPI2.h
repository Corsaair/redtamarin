/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
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
 * Portions created by the Initial Developer are Copyright (C) 1993-2006
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
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

#ifndef __avmplus_VMPI2__
#define __avmplus_VMPI2__

extern char *VMPI_int2char(int n);

extern char *VMPI_getLocale();

// ---- C.stdlib ---- 

/**
 * wrapper around setenv function
 * @return 0 if successful
 */
extern int VMPI_setenv(const char *name, const char *value, int overwrite);

/**
 * wrapper around unsetenv function
 * @return 0 if successful
 */
extern int VMPI_unsetenv(const char *name);

/**
 * wrapper around realpath function
 * @return resolved path
 */
extern char *VMPI_realpath(char const *path);

// ---- C.stdlib ---- END


// ---- C.unistd ---- 

extern int VMPI_chmod(const char *path, int mode);

/**
 * wrapper around mkdir function to create a directory
 * @return 0 if successful
 */
extern int VMPI_mkdir(const char *path);

extern void VMPI_sleep(int milliseconds);

extern void VMPI_getUserName(char *username);

// ---- C.unistd ---- END


// ---- C.stdio ---- 

extern void VMPI_con_stream_mode(int state);
extern void VMPI_con_trans_mode(int state);
extern int VMPI_kbhit();

// ---- C.stdio ---- 


// ---- C.socket ---- 

extern struct hostent *VMPI_gethostbyaddr(const char *addr);

// ---- C.socket ---- END


// ---- avmplus.System ---- 

extern double VMPI_getStdinFileLength();

// ---- avmplus.System ---- END


// ---- avmplus.OperatingSystem ---- 

extern void VMPI_getOperatingSystemName(char *name);

extern void VMPI_getOperatingSystemNodeName(char *nodename);

extern void VMPI_getOperatingSystemRelease(char *release);

extern void VMPI_getOperatingSystemVersion(char *version);

extern void VMPI_getOperatingSystemMachine(char *machine);

extern void VMPI_getOperatingSystemVersionNumbers(int *major, int *minor, int *bugfix);

// ---- avmplus.OperatingSystem ---- END


// ---- avmplus.FileSystem ---- 

extern int VMPI_getLogicalDrives();

extern int VMPI_getFileMode(const char *path);

extern double VMPI_getFileSize(const char *path);

extern double VMPI_getFileLastModifiedTime(const char *path);

extern bool VMPI_isRegularFile(const char *path);

extern bool VMPI_isDirectory(const char *path);

extern bool VMPI_isAttributeHidden(const char *path);

extern double VMPI_getFreeDiskSpace(const char *path);

extern double VMPI_getTotalDiskSpace(const char *path);

// ---- avmplus.FileSystem ---- END
#endif /* __avmplus_VMPI2__ */
