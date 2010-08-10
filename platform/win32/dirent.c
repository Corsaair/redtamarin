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
 * Portions created by the Initial Developer are Copyright (C) 2004-2006
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

/*
    Implementation of POSIX directory browsing functions and types for Win32.

    Author:  Kevlin Henney (kevlin@acm.org, kevlin@curbralan.com)
    History: Created March 1997. Updated June 2003.

    Copyright Kevlin Henney, 1997, 2003. All rights reserved.

    Permission to use, copy, modify, and distribute this software and its
    documentation for any purpose is hereby granted without fee, provided
    that this copyright and permissions notice appear in all copies and
    derivatives.

    This software is supplied "as is" without express or implied warranty.

    But that said, if there are any problems please get in touch.
*/

#include <dirent.h>
#include <errno.h>
#include <io.h> /* _findfirst and _findnext set errno if they return -1 */
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C"
{
#endif

struct DIR
{
    long                handle; /* -1 for failed rewind */
    struct _finddata_t  info;
    struct dirent       result; /* d_name null if first time */
    char                *name;  /* null-terminated char string */
};

DIR *opendir(const char *name)
{
    DIR *dir = 0;

    if(name && name[0]) {
        size_t base_length = strlen(name);
        const char *all = /* search pattern must end with suitable wildcard */
            strchr("/\\", name[base_length - 1]) ? "*" : "/*";

        if((dir = (DIR *) malloc(sizeof *dir)) != 0 &&
           (dir->name = (char *) malloc(base_length + strlen(all) + 1)) != 0) {
            strcat(strcpy(dir->name, name), all);

            if((dir->handle = (long) _findfirst(dir->name, &dir->info)) != -1) {
                dir->result.d_name = 0;
                dir->result.d_type = 0;
            }
            else  {
                free(dir->name);
                free(dir);
                dir = 0;
            }
        }
        else  {
            free(dir);
            dir   = 0;
            errno = ENOMEM;
        }
    }
    else {
        errno = EINVAL;
    }

    return dir;
}

int closedir(DIR *dir)
{
    int result = -1;

    if(dir) {
        if(dir->handle != -1) {
            result = _findclose(dir->handle);
        }

        free(dir->name);
        free(dir);
    }

    /* map all errors to EBADF */
    if(result == -1) {
        errno = EBADF;
    }

    return result;
}

struct dirent *readdir(DIR *dir)
{
    struct dirent *result = 0;

    if(dir && dir->handle != -1) {
        if(!dir->result.d_name || _findnext(dir->handle, &dir->info) != -1) {
            result         = &dir->result;
            result->d_name = dir->info.name;
            result->d_type = (dir->info.attrib == _A_SUBDIR) ? DT_DIR : DT_UNKNOWN;
        }
    }
    else {
        errno = EBADF;
    }

    return result;
}

void rewinddir(DIR *dir)
{
    if(dir && dir->handle != -1) {
        _findclose(dir->handle);
        dir->handle = (long) _findfirst(dir->name, &dir->info);
        dir->result.d_name = 0;
        dir->result.d_type = 0;
    }
    else {
        errno = EBADF;
    }
}

#ifdef __cplusplus
}
#endif



