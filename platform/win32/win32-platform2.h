/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* -*- tab-width: 4 -*- */
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

#ifndef __avmplus_win32_platform2__
#define __avmplus_win32_platform2__

#include <errno.h>

#define VMPI_strerror    ::strerror


//a lot of definitions to align with POSIX
#if !defined(ECURDIR)
  #define ECURDIR          EACCES
#endif /* !ECURDIR */
#if !defined(ENOSYS)
  #define ENOSYS           EPERM
#endif /* !ENOSYS */

#if !defined(ENETDOWN)
  #define ENETDOWN         WSAENETDOWN
#endif /* !ENETDOWN */

#if !defined(ENETUNREACH)
  #define ENETUNREACH      WSAENETUNREACH
#endif /* !ENETUNREACH */

#if !defined(ENETRESET)
  #define ENETRESET        WSAENETRESET
#endif /* !ENETRESET */

#if !defined(ECONNABORTED)
  #define ECONNABORTED     WSAECONNABORTED
#endif /* !ECONNABORTED */

#if !defined(ECONNRESET)
  #define ECONNRESET       WSAECONNRESET
#endif /* !ECONNRESET */

#if !defined(ENOBUFS)
  #define ENOBUFS          WSAENOBUFS
#endif /* !ENOBUFS */

#if !defined(EISCONN)
  #define EISCONN          WSAEISCONN
#endif /* !EISCONN */

#if !defined(ENOTCONN)
  #define ENOTCONN         WSAENOTCONN
#endif /* !ENOTCONN */

#if !defined(ESHUTDOWN)
  #define ESHUTDOWN        WSAESHUTDOWN
#endif /* !ESHUTDOWN */

#if !defined(ETOOMANYREFS)
  #define ETOOMANYREFS     WSAETOOMANYREFS
#endif /* !ETOOMANYREFS */

#if !defined(ETIMEDOUT)
  #define ETIMEDOUT        WSAETIMEDOUT
#endif /* !ETIMEDOUT */

#if !defined(ECONNREFUSED)
  #define ECONNREFUSED     WSAECONNREFUSED
#endif /* !ECONNREFUSED */

#if !defined(SHUT_RD)
  #define SHUT_RD          SD_RECEIVE
#endif /* !SHUT_RD */

#if !defined(SHUT_RDWR)
  #define SHUT_RDWR        SD_BOTH
#endif /* !SHUT_RDWR */

#if !defined(SHUT_WR)
  #define SHUT_WR          SD_SEND
#endif /* !SHUT_WR */

#if !defined(FILENAME_MAX)
  #define FILENAME_MAX   _MAX_FNAME
#endif /* !FILENAME_MAX */

#if !defined(PATH_MAX)
  #define PATH_MAX       _MAX_PATH
#endif /* !PATH_MAX */


#endif // __avmplus_win32_platform2__
