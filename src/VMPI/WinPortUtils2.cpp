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

#include "avmplus.h"

//for C.errno
//#include <errno.h> //already included in win32-platform2.h



// ---- utilities ---- 

/*
* Utility function that convert Windows errror to errno
* from: UNIXem: UNIX Emulation Library for Win32
*       http://synesis.com.au/software/unixem.html
*/
int errno_from_Win32(unsigned long w32Err)
{
    struct errmap_t
    {
        unsigned long   w32Err;
        int             eerrno;
    };

    static const struct errmap_t    errmap[] = 
    {
        /*   1 */       {   ERROR_INVALID_FUNCTION          ,   EINVAL          }
        /*   2 */   ,   {   ERROR_FILE_NOT_FOUND            ,   ENOENT          }
        /*   3 */   ,   {   ERROR_PATH_NOT_FOUND            ,   ENOENT          }
        /*   4 */   ,   {   ERROR_TOO_MANY_OPEN_FILES       ,   EMFILE          }
        /*   5 */   ,   {   ERROR_ACCESS_DENIED             ,   EACCES          }
        /*   6 */   ,   {   ERROR_INVALID_HANDLE            ,   EBADF           }
        /*   7 */   ,   {   ERROR_ARENA_TRASHED             ,   ENOMEM          }
        /*   8 */   ,   {   ERROR_NOT_ENOUGH_MEMORY         ,   ENOMEM          }
        /*   9 */   ,   {   ERROR_INVALID_BLOCK             ,   ENOMEM          }
        /*  10 */   ,   {   ERROR_BAD_ENVIRONMENT           ,   E2BIG           }
        /*  11 */   ,   {   ERROR_BAD_FORMAT                ,   ENOEXEC         }
        /*  12 */   ,   {   ERROR_INVALID_ACCESS            ,   EINVAL          }
        /*  13 */   ,   {   ERROR_INVALID_DATA              ,   EINVAL          }
        /*  14 */   ,   {   ERROR_OUTOFMEMORY               ,   ENOMEM          }
        /*  15 */   ,   {   ERROR_INVALID_DRIVE             ,   ENOENT          }
        /*  16 */   ,   {   ERROR_CURRENT_DIRECTORY         ,   ECURDIR         }
        /*  17 */   ,   {   ERROR_NOT_SAME_DEVICE           ,   EXDEV           }
        /*  18 */   ,   {   ERROR_NO_MORE_FILES             ,   ENOENT          }
        /*  19 */   ,   {   ERROR_WRITE_PROTECT             ,   EROFS           }
        /*  20 */   ,   {   ERROR_BAD_UNIT                  ,   ENXIO           }
        /*  21 */   ,   {   ERROR_NOT_READY                 ,   EBUSY           }
        /*  22 */   ,   {   ERROR_BAD_COMMAND               ,   EIO             }
        /*  23 */   ,   {   ERROR_CRC                       ,   EIO             }
        /*  24 */   ,   {   ERROR_BAD_LENGTH                ,   EIO             }
        /*  25 */   ,   {   ERROR_SEEK                      ,   EIO             }
        /*  26 */   ,   {   ERROR_NOT_DOS_DISK              ,   EIO             }
        /*  27 */   ,   {   ERROR_SECTOR_NOT_FOUND          ,   ENXIO           }
        /*  28 */   ,   {   ERROR_OUT_OF_PAPER              ,   EBUSY           }
        /*  29 */   ,   {   ERROR_WRITE_FAULT               ,   EIO             }
        /*  30 */   ,   {   ERROR_READ_FAULT                ,   EIO             }
        /*  31 */   ,   {   ERROR_GEN_FAILURE               ,   EIO             }
        /*  32 */   ,   {   ERROR_SHARING_VIOLATION         ,   EAGAIN          }
        /*  33 */   ,   {   ERROR_LOCK_VIOLATION            ,   EACCES          }
        /*  34 */   ,   {   ERROR_WRONG_DISK                ,   ENXIO           }
        /*  35 */   ,   {   35                              ,   ENFILE          }
        /*  36 */   ,   {   ERROR_SHARING_BUFFER_EXCEEDED   ,   ENFILE          }
        /*  37 */   ,   {   ERROR_HANDLE_EOF                ,   EINVAL          }
        /*  38 */   ,   {   ERROR_HANDLE_DISK_FULL          ,   ENOSPC          }
        /*  39 */   ,   {   0                               ,   0               }
        /*  40 */   ,   {   0                               ,   0               }
        /*  41 */   ,   {   0                               ,   0               }
        /*  42 */   ,   {   0                               ,   0               }
        /*  43 */   ,   {   0                               ,   0               }
        /*  44 */   ,   {   0                               ,   0               }
        /*  45 */   ,   {   0                               ,   0               }
        /*  46 */   ,   {   0                               ,   0               }
        /*  47 */   ,   {   0                               ,   0               }
        /*  48 */   ,   {   0                               ,   0               }
        /*  49 */   ,   {   0                               ,   0               }
        /*  50 */   ,   {   ERROR_NOT_SUPPORTED             ,   ENOSYS          }
        /*  51 */   ,   {   0                               ,   0               }
        /*  52 */   ,   {   0                               ,   0               }
        /*  53 */   ,   {   ERROR_BAD_NETPATH               ,   ENOENT          }
        /*  54 */   ,   {   0                               ,   0               }
        /*  55 */   ,   {   0                               ,   0               }
        /*  56 */   ,   {   0                               ,   0               }
        /*  57 */   ,   {   0                               ,   0               }
        /*  58 */   ,   {   0                               ,   0               }
        /*  59 */   ,   {   0                               ,   0               }
        /*  60 */   ,   {   0                               ,   0               }
        /*  61 */   ,   {   0                               ,   0               }
        /*  62 */   ,   {   0                               ,   0               }
        /*  63 */   ,   {   0                               ,   0               }
        /*  64 */   ,   {   0                               ,   0               }
        /*  65 */   ,   {   ERROR_NETWORK_ACCESS_DENIED     ,   EACCES          }
        /*  66 */   ,   {   0                               ,   0               }
        /*  67 */   ,   {   ERROR_BAD_NET_NAME              ,   ENOENT          }
        /*  68 */   ,   {   0                               ,   0               }
        /*  69 */   ,   {   0                               ,   0               }
        /*  70 */   ,   {   0                               ,   0               }
        /*  71 */   ,   {   0                               ,   0               }
        /*  72 */   ,   {   0                               ,   0               }
        /*  73 */   ,   {   0                               ,   0               }
        /*  74 */   ,   {   0                               ,   0               }
        /*  75 */   ,   {   0                               ,   0               }
        /*  76 */   ,   {   0                               ,   0               }
        /*  77 */   ,   {   0                               ,   0               }
        /*  78 */   ,   {   0                               ,   0               }
        /*  79 */   ,   {   0                               ,   0               }
        /*  80 */   ,   {   ERROR_FILE_EXISTS               ,   EEXIST          }
        /*  81 */   ,   {   0                               ,   0               }
        /*  82 */   ,   {   ERROR_CANNOT_MAKE               ,   EACCES          }
        /*  83 */   ,   {   ERROR_FAIL_I24                  ,   EACCES          }
        /*  84 */   ,   {   0                               ,   0               }
        /*  85 */   ,   {   0                               ,   0               }
        /*  86 */   ,   {   0                               ,   0               }
        /*  87 */   ,   {   ERROR_INVALID_PARAMETER         ,   EINVAL          }
        /*  88 */   ,   {   0                               ,   0               }
        /*  89 */   ,   {   ERROR_NO_PROC_SLOTS             ,   EAGAIN          }
        /*  90 */   ,   {   0                               ,   0               }
        /*  91 */   ,   {   0                               ,   0               }
        /*  92 */   ,   {   0                               ,   0               }
        /*  93 */   ,   {   0                               ,   0               }
        /*  94 */   ,   {   0                               ,   0               }
        /*  95 */   ,   {   0                               ,   0               }
        /*  96 */   ,   {   0                               ,   0               }
        /*  97 */   ,   {   0                               ,   0               }
        /*  98 */   ,   {   0                               ,   0               }
        /*  99 */   ,   {   0                               ,   0               }
        /* 100 */   ,   {   0                               ,   0               }
        /* 101 */   ,   {   0                               ,   0               }
        /* 102 */   ,   {   0                               ,   0               }
        /* 103 */   ,   {   0                               ,   0               }
        /* 104 */   ,   {   0                               ,   0               }
        /* 105 */   ,   {   0                               ,   0               }
        /* 106 */   ,   {   0                               ,   0               }
        /* 107 */   ,   {   0                               ,   0               }
        /* 108 */   ,   {   ERROR_DRIVE_LOCKED              ,   EACCES          }
        /* 109 */   ,   {   ERROR_BROKEN_PIPE               ,   EPIPE           }
        /* 110 */   ,   {   0                               ,   0               }
        /* 111 */   ,   {   ERROR_BUFFER_OVERFLOW           ,   ENAMETOOLONG    }
        /* 112 */   ,   {   ERROR_DISK_FULL                 ,   ENOSPC          }
        /* 113 */   ,   {   0                               ,   0               }
        /* 114 */   ,   {   ERROR_INVALID_TARGET_HANDLE     ,   EBADF           }
        /* 115 */   ,   {   0                               ,   0               }
        /* 116 */   ,   {   0                               ,   0               }
        /* 117 */   ,   {   0                               ,   0               }
        /* 118 */   ,   {   0                               ,   0               }
        /* 119 */   ,   {   0                               ,   0               }
        /* 120 */   ,   {   0                               ,   0               }
        /* 121 */   ,   {   0                               ,   0               }
        /* 122 */   ,   {   0                               ,   0               }
        /* 123 */   ,   {   ERROR_INVALID_NAME              ,   ENOENT          }
        /* 124 */   ,   {   ERROR_INVALID_HANDLE            ,   EINVAL          }
        /* 125 */   ,   {   0                               ,   0               }
        /* 126 */   ,   {   0                               ,   0               }
        /* 127 */   ,   {   0                               ,   0               }
        /* 128 */   ,   {   ERROR_WAIT_NO_CHILDREN          ,   ECHILD          }
        /* 129 */   ,   {   ERROR_CHILD_NOT_COMPLETE        ,   ECHILD          }
        /* 130 */   ,   {   ERROR_DIRECT_ACCESS_HANDLE      ,   EBADF           }
        /* 131 */   ,   {   ERROR_NEGATIVE_SEEK             ,   EINVAL          }
        /* 132 */   ,   {   ERROR_SEEK_ON_DEVICE            ,   EACCES          }
        /* 133 */   ,   {   0                               ,   0               }
        /* 134 */   ,   {   0                               ,   0               }
        /* 135 */   ,   {   0                               ,   0               }
        /* 136 */   ,   {   0                               ,   0               }
        /* 137 */   ,   {   0                               ,   0               }
        /* 138 */   ,   {   0                               ,   0               }
        /* 139 */   ,   {   0                               ,   0               }
        /* 140 */   ,   {   0                               ,   0               }
        /* 141 */   ,   {   0                               ,   0               }
        /* 142 */   ,   {   0                               ,   0               }
        /* 143 */   ,   {   0                               ,   0               }
        /* 144 */   ,   {   0                               ,   0               }
        /* 145 */   ,   {   ERROR_DIR_NOT_EMPTY             ,   ENOTEMPTY       }
        /* 146 */   ,   {   0                               ,   0               }
        /* 147 */   ,   {   0                               ,   0               }
        /* 148 */   ,   {   0                               ,   0               }
        /* 149 */   ,   {   0                               ,   0               }
        /* 150 */   ,   {   0                               ,   0               }
        /* 151 */   ,   {   0                               ,   0               }
        /* 152 */   ,   {   0                               ,   0               }
        /* 153 */   ,   {   0                               ,   0               }
        /* 154 */   ,   {   0                               ,   0               }
        /* 155 */   ,   {   0                               ,   0               }
        /* 156 */   ,   {   0                               ,   0               }
        /* 157 */   ,   {   0                               ,   0               }
        /* 158 */   ,   {   ERROR_NOT_LOCKED                ,   EACCES          }
        /* 159 */   ,   {   0                               ,   0               }
        /* 160 */   ,   {   0                               ,   0               }
        /* 161 */   ,   {   ERROR_BAD_PATHNAME              ,   ENOENT          }
        /* 162 */   ,   {   0                               ,   0               }
        /* 163 */   ,   {   0                               ,   0               }
        /* 164 */   ,   {   ERROR_MAX_THRDS_REACHED         ,   EAGAIN          }
        /* 165 */   ,   {   0                               ,   0               }
        /* 166 */   ,   {   0                               ,   0               }
        /* 167 */   ,   {   ERROR_LOCK_FAILED               ,   EACCES          }
        /* 168 */   ,   {   0                               ,   0               }
        /* 169 */   ,   {   0                               ,   0               }
        /* 170 */   ,   {   0                               ,   0               }
        /* 171 */   ,   {   0                               ,   0               }
        /* 172 */   ,   {   0                               ,   0               }
        /* 173 */   ,   {   0                               ,   0               }
        /* 174 */   ,   {   0                               ,   0               }
        /* 175 */   ,   {   0                               ,   0               }
        /* 176 */   ,   {   0                               ,   0               }
        /* 177 */   ,   {   0                               ,   0               }
        /* 178 */   ,   {   0                               ,   0               }
        /* 179 */   ,   {   0                               ,   0               }
        /* 180 */   ,   {   0                               ,   0               }
        /* 181 */   ,   {   0                               ,   0               }
        /* 182 */   ,   {   0                               ,   0               }
        /* 183 */   ,   {   ERROR_ALREADY_EXISTS            ,   EEXIST          }
        /* 184 */   ,   {   0                               ,   0               }
        /* 185 */   ,   {   0                               ,   0               }
        /* 186 */   ,   {   0                               ,   0               }
        /* 187 */   ,   {   0                               ,   0               }
        /* 188 */   ,   {   0                               ,   0               }
        /* 189 */   ,   {   0                               ,   0               }
        /* 190 */   ,   {   0                               ,   0               }
        /* 191 */   ,   {   0                               ,   0               }
        /* 192 */   ,   {   0                               ,   0               }
        /* 193 */   ,   {   0                               ,   0               }
        /* 194 */   ,   {   0                               ,   0               }
        /* 195 */   ,   {   0                               ,   0               }
        /* 196 */   ,   {   0                               ,   0               }
        /* 197 */   ,   {   0                               ,   0               }
        /* 198 */   ,   {   0                               ,   0               }
        /* 199 */   ,   {   0                               ,   0               }

        /* 206 */   ,   {   ERROR_FILENAME_EXCED_RANGE      ,   ENAMETOOLONG    }

        /* 215 */   ,   {   ERROR_NESTING_NOT_ALLOWED       ,   EAGAIN          }

        /* 267 */   ,   {   ERROR_DIRECTORY                 ,   ENOTDIR         }

        /* 997 */   ,   {   ERROR_IO_PENDING                ,   EBUSY           }

        /* 1816 */  ,   {   ERROR_NOT_ENOUGH_QUOTA          ,   ENOMEM          }
    };

    size_t  i;

    for(i = 0; i < NUM_ELEMENTS(errmap); ++i)
    {
        if(w32Err == errmap[i].w32Err)
        {
            return errmap[i].eerrno;
        }
    }

    //assert(!"Unrecognised value");

    return EINVAL;
}

static int setenv_with_putenv(const char *name, const char *value)
{
    if(NULL != strchr(name, '='))
    {
        errno = EINVAL;
        return -1;
    }
    else
    {
        size_t  nameLen     =   VMPI_strlen(name);
        size_t  valueLen    =   VMPI_strlen(value);
        size_t  required    =   1 + nameLen + 1 + valueLen;
        char    buffer_[101];
        char    *buffer     =   (NUM_ELEMENTS(buffer_) < required)
                                    ? (char*)malloc(required * sizeof(char))
                                    : &buffer_[0];

        if(NULL == buffer)
        {
            errno = ENOMEM;
            return -1;
        }
        else
        {
            int r;
            (void)VMPI_strncpy(&buffer[0], name, nameLen);
            buffer[nameLen] = '=';
            buffer[nameLen + 1] = '\0';
            (void)VMPI_strncpy(&buffer[nameLen + 1], value, valueLen);
            buffer[nameLen + 1 + valueLen] = '\0';

            r = _putenv(&buffer[0]);

            if(buffer != &buffer_[0])
            {
                VMPI_free(buffer);
            }

            return r;
        }
    }
}


int WIN32_SocketStart(int major, int minor)
{
    WSADATA wsaData;
    WORD wVersionRequested;
    int err;
    
    wVersionRequested = MAKEWORD(major, minor);
    err = WSAStartup(wVersionRequested, &wsaData);
    
    if (err != 0) {
        printf("WSAStartup failed with error: %d\n", err);
        return 1;
    }

    return 0;
}

void WIN32_SocketStop()
{
    /* note:
       it would be a bad idea to call the WSA cleanup in the middle of code execution
       the function is here but not used, in Platform.h for WIN32
       when exit() is called we also call WSACleanup(), much cleaner approach imho

       Also we could also suppress the need to call WIN32_SocketStart
       by calling it by default in the start() function of Platform.h
       not sure how it can affect memory/load to automatically call it
       if no socket related code is used
    */
    WSACleanup();
}


char *VMPI_int2char(int n)
{
    char buffer[100];
    char *value;
    size_t size;

    size  = VMPI_sprintf( buffer, "%d", n ) * sizeof(char);
    value = (char*) VMPI_alloc( size+1 );
    VMPI_strcpy( value, buffer );
    
    return value;
}

char *VMPI_getLocale()
{
    //get the Environment's default locale
    return setlocale( LC_ALL, "" );
}

// ---- utilities ---- END


// ---- POSIX compatibility layer ---- 

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
            result->d_type = (dir->info.attrib & _A_SUBDIR) ? DT_DIR : DT_UNKNOWN;
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

int uname(struct utsname *uts)
{
    enum
    {
        Win95,
        Win98,
        WinNT,
        WinUnknown
    };
    
    typedef BOOL (WINAPI *PGPI)(DWORD, DWORD, DWORD, DWORD, PDWORD);
    
    OSVERSIONINFOEX osver;
    SYSTEM_INFO sysinfo;
    PGPI pGPI;
    DWORD nodelen;
    DWORD os = WinUnknown;
    DWORD dwType;
    
    VMPI_memset(uts, 0, sizeof(*uts));
    
    osver.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
    GetVersionEx((OSVERSIONINFO *) &osver);
    GetSystemInfo(&sysinfo);
    
    VMPI_strcpy(uts->sysname, "Win32"); //we always want to be WIN32
    
    // Test for the specific product, and we create the version, eg: {windows_type} {suite_mask} {product_info} {service_pack}
    switch( osver.dwPlatformId )
    {
        case VER_PLATFORM_WIN32_NT:
        if(osver.dwMajorVersion == 3) {
            if(osver.dwMinorVersion == 51) {
                VMPI_strcpy(uts->version, "Windows NT 3.51");
            }
            else {
                VMPI_strcpy(uts->version, "Windows NT 3x");
            }
        }
        else if(osver.dwMajorVersion == 4) {
            if(osver.dwMinorVersion == 0) {
                VMPI_strcpy(uts->version, "Windows NT 4");
            }
            else {
                VMPI_strcpy(uts->version, "Windows NT 4x");
            }
        }
        else if((osver.dwMajorVersion == 5) && (osver.dwMinorVersion == 0)) {
            VMPI_strcpy(uts->version, "Windows 2000 ");
            if(osver.wProductType == VER_NT_WORKSTATION) {
                VMPI_strcat(uts->version, "Professional");
            }
            else if(osver.wSuiteMask & VER_SUITE_DATACENTER) {
                VMPI_strcat(uts->version, "Datacenter Server");
            }
            else if(osver.wSuiteMask & VER_SUITE_ENTERPRISE) {
                VMPI_strcat(uts->version, "Advanced Server");
            }
            else {
                VMPI_strcat(uts->version, "Server");
            }
        }
        else if((osver.dwMajorVersion == 5) && (osver.dwMinorVersion == 1)) {
            VMPI_strcpy(uts->version, "Windows XP ");
            if(GetSystemMetrics(SM_MEDIACENTER)) {
                VMPI_strcat(uts->version, "Media Center Edition");
            }
            else if(GetSystemMetrics(SM_STARTER)) {
                VMPI_strcat(uts->version, "Starter Edition");
            }
            else if(GetSystemMetrics(SM_TABLETPC)) {
                VMPI_strcat(uts->version, "Tablet PC Edition");
            }
            else if(osver.wSuiteMask & VER_SUITE_PERSONAL) {
                VMPI_strcat(uts->version, "Home Edition");
            }
            else {
                VMPI_strcat(uts->version, "Professional");
            }
        }
        else if((osver.dwMajorVersion == 5) && (osver.dwMinorVersion == 2)) {
            if(GetSystemMetrics(SM_SERVERR2)) {
                VMPI_strcpy(uts->version, "Windows Server 2003 R2, ");
            }
            else if(osver.wSuiteMask & VER_SUITE_STORAGE_SERVER) {
                VMPI_strcpy(uts->version, "Windows Storage Server 2003");
            }
            else if(osver.wSuiteMask & VER_SUITE_WH_SERVER) {
                VMPI_strcpy(uts->version, "Windows Home Server");
            }
            else if((osver.wProductType == VER_NT_WORKSTATION) && (sysinfo.wProcessorArchitecture==PROCESSOR_ARCHITECTURE_AMD64)) {
                VMPI_strcpy(uts->version, "Windows XP Professional x64 Edition");
            }
            else {
                VMPI_strcpy(uts->version, "Windows Server 2003, ");
            }
            
            if(osver.wProductType != VER_NT_WORKSTATION) {
                if(sysinfo.wProcessorArchitecture==PROCESSOR_ARCHITECTURE_IA64) {
                    if(osver.wSuiteMask & VER_SUITE_DATACENTER) {
                        VMPI_strcat(uts->version, "Datacenter Edition for Itanium-based Systems");
                    }
                    else if(osver.wSuiteMask & VER_SUITE_ENTERPRISE) {
                        VMPI_strcat(uts->version, "Enterprise Edition for Itanium-based Systems");
                    }
                }
                else if(sysinfo.wProcessorArchitecture==PROCESSOR_ARCHITECTURE_AMD64) {
                    if(osver.wSuiteMask & VER_SUITE_DATACENTER) {
                        VMPI_strcat(uts->version, "Datacenter x64 Edition");
                    }
                    else if(osver.wSuiteMask & VER_SUITE_ENTERPRISE) {
                        VMPI_strcat(uts->version, "Enterprise x64 Edition");
                    }
                    else {
                        VMPI_strcat(uts->version, "Standard x64 Edition");
                    }
                }
                else {
                    if(osver.wSuiteMask & VER_SUITE_COMPUTE_SERVER) {
                        VMPI_strcat(uts->version, "Compute Cluster Edition");
                    }
                    else if(osver.wSuiteMask & VER_SUITE_DATACENTER) {
                        VMPI_strcat(uts->version, "Datacenter Edition");
                    }
                    else if(osver.wSuiteMask & VER_SUITE_ENTERPRISE) {
                        VMPI_strcat(uts->version, "Enterprise Edition");
                    }
                    else if(osver.wSuiteMask & VER_SUITE_BLADE) {
                        VMPI_strcat(uts->version, "Web Edition");
                    }
                    else {
                        VMPI_strcat(uts->version, "Standard Edition");
                    }
                }
            }
        }
        else if(osver.dwMajorVersion == 6) {
            if(osver.dwMinorVersion == 0) {
                if(osver.wProductType == VER_NT_WORKSTATION) {
                    VMPI_strcpy(uts->version, "Windows Vista ");
                }
                else {
                    VMPI_strcpy(uts->version, "Windows Server 2008 ");
                }
            }
            
            if(osver.dwMinorVersion == 1) {
                if(osver.wProductType == VER_NT_WORKSTATION) {
                    VMPI_strcpy(uts->version, "Windows 7 ");
                }
                else {
                    VMPI_strcpy(uts->version, "Windows Server 2008 R2 ");
                }
            }
            
            pGPI = (PGPI) GetProcAddress(GetModuleHandle(TEXT("kernel32.dll")), "GetProductInfo");
            pGPI(osver.dwMajorVersion, osver.dwMinorVersion, 0, 0, &dwType);
            
            switch( dwType )
            {
                case PRODUCT_ULTIMATE:
                VMPI_strcat(uts->version, "Ultimate Edition");
                break;
                
                case PRODUCT_PROFESSIONAL:
                VMPI_strcat(uts->version, "Professional");
                break;
                
                case PRODUCT_HOME_PREMIUM:
                VMPI_strcat(uts->version, "Home Premium Edition");
                break;
                
                case PRODUCT_HOME_BASIC:
                VMPI_strcat(uts->version, "Home Basic Edition");
                break;
                
                case PRODUCT_ENTERPRISE:
                VMPI_strcat(uts->version, "Enterprise Edition");
                break;
                
                case PRODUCT_BUSINESS:
                VMPI_strcat(uts->version, "Business Edition");
                break;
                
                case PRODUCT_STARTER:
                VMPI_strcat(uts->version, "Starter Edition");
                break;
                
                case PRODUCT_CLUSTER_SERVER:
                VMPI_strcat(uts->version, "Cluster Server Edition");
                break;
                
                case PRODUCT_DATACENTER_SERVER:
                VMPI_strcat(uts->version, "Datacenter Edition");
                break;
                
                case PRODUCT_DATACENTER_SERVER_CORE:
                VMPI_strcat(uts->version, "Datacenter Edition (core installation)");
                break;
                
                case PRODUCT_ENTERPRISE_SERVER:
                VMPI_strcat(uts->version, "Enterprise Edition");
                break;
                
                case PRODUCT_ENTERPRISE_SERVER_CORE:
                VMPI_strcat(uts->version, "Enterprise Edition (core installation)");
                break;
                
                case PRODUCT_ENTERPRISE_SERVER_IA64:
                VMPI_strcat(uts->version, "Enterprise Edition for Itanium-based Systems");
                break;
                
                case PRODUCT_SMALLBUSINESS_SERVER:
                VMPI_strcat(uts->version, "Small Business Server");
                break;
                
                case PRODUCT_SMALLBUSINESS_SERVER_PREMIUM:
                VMPI_strcat(uts->version, "Small Business Server Premium Edition");
                break;
                
                case PRODUCT_STANDARD_SERVER:
                VMPI_strcat(uts->version, "Standard Edition");
                break;
                
                case PRODUCT_STANDARD_SERVER_CORE:
                VMPI_strcat(uts->version, "Standard Edition (core installation)");
                break;
                
                case PRODUCT_WEB_SERVER:
                VMPI_strcat(uts->version, "Web Server Edition");
                break;
            }
        }
        os = WinNT;
        break;
        
        case VER_PLATFORM_WIN32_WINDOWS:
        if((osver.dwMajorVersion == 4) && (osver.dwMinorVersion >= 10)) {
            if(osver.dwMinorVersion >= 90) {
                VMPI_strcpy(uts->version, "Windows ME");
            }
            else if((osver.dwMinorVersion == 10) && (osver.dwBuildNumber >= 2183)) {
                VMPI_strcpy(uts->version, "Windows 98 Second Edition");
            }
            else if(osver.dwMinorVersion == 10) {
                VMPI_strcpy(uts->version, "Windows 98");
            }
            os = Win98;
        }
        else {
            if((osver.dwMinorVersion < 10) && (osver.dwBuildNumber > 1080)) {
                VMPI_strcpy(uts->version, "Windows 95 OEM Service Release 2");
            }
            else if(osver.dwMinorVersion == 0) {
                VMPI_strcpy(uts->version, "Windows 95");
            }
            os = Win95;
        }
        break;
        
        /*
        case VER_PLATFORM_WIN32_CE:
        VMPI_sprintf(uts->version, "Windows CE %ld.%02ld", osver.dwMajorVersion, osver.dwMinorVersion);
        break;
        */
        
        case VER_PLATFORM_WIN32s:
        VMPI_strcpy(uts->version, "Windows");
        break;
    }
    
    // Include service pack (if any).
    if(osver.wServicePackMajor > 0) {
        VMPI_strcat(uts->version, " ");
        VMPI_strcat(uts->version, osver.szCSDVersion); //ex: "Service Pack 3"
    }
    
    // We create the release, eg: {major}.{minor} build {build}
    VMPI_sprintf(uts->release, "%ld.%ld build %ld", osver.dwMajorVersion, osver.dwMinorVersion, osver.dwBuildNumber & 0xFFFF);
    
    // We create the machine, from the processor infos
    switch( sysinfo.wProcessorArchitecture )
    {
        case PROCESSOR_ARCHITECTURE_PPC:
        VMPI_strcpy(uts->machine, "ppc");
        break;
        
        case PROCESSOR_ARCHITECTURE_ALPHA:
        VMPI_strcpy(uts->machine, "alpha");
        break;
        
        case PROCESSOR_ARCHITECTURE_MIPS:
        VMPI_strcpy(uts->machine, "mips");
        break;
        
        case PROCESSOR_ARCHITECTURE_INTEL:
        switch( os )
        {
            case Win95:
            case Win98:
            switch( sysinfo.dwProcessorType )
            {
                case PROCESSOR_INTEL_386:
                case PROCESSOR_INTEL_486:
                case PROCESSOR_INTEL_PENTIUM:
                VMPI_sprintf(uts->machine, "i%ld", sysinfo.dwProcessorType);
                break;
                
                default:
                VMPI_strcpy(uts->machine, "i386");
                break;
            }
            break;
            
            case WinNT:
            VMPI_sprintf(uts->machine, "i%d86", sysinfo.wProcessorLevel);
            break;
        }
        break;
        
        default:
        VMPI_strcpy(uts->machine, "unknown");
        break;
    }
    
    // We create the nodename.
    nodelen = sizeof(uts->nodename) - 1;
    GetComputerName(uts->nodename, &nodelen);
    
    return 0;
}

const char* VMPI_inet_ntop(int af, const void* src, char* dst, int cnt)
{
    struct sockaddr_in srcaddr;
    
    VMPI_memset(&srcaddr, 0, sizeof(struct sockaddr_in));
    VMPI_memcpy(&(srcaddr.sin_addr), src, sizeof(srcaddr.sin_addr));
    
    switch( af )
    {
        case AF_INET:
        srcaddr.sin_family = AF_INET;
        break;
        
        case AF_INET6:
        srcaddr.sin_family = AF_INET6;
        break;
    }
    
    
    if(WSAAddressToString((struct sockaddr*) &srcaddr, sizeof(struct sockaddr_in), 0, dst, (LPDWORD) &cnt) != 0)
    {
        DWORD rv = WSAGetLastError();
        printf("WSAAddressToString() : %d\n",rv);
        return NULL;
    }
    
    return dst;
}

// ---- POSIX compatibility layer ---- END


// ---- C.stdlib ---- 

int VMPI_setenv(const char *name, const char *value, int overwrite)
{
    if(!overwrite)
    {
        //VMPI_log("getenv = [");
        //VMPI_log(VMPI_getenv(name));
        //VMPI_log("]\n");
        if(NULL != VMPI_getenv(name))
        {
            return 0;
        }
    }

    return setenv_with_putenv(name, value);
}

int VMPI_unsetenv(const char *name)
{
    return setenv_with_putenv(name, "");
}

char *VMPI_realpath(char const *path)
{
    /* note:
       if the path does not exists the path will still resolve
       and does not set errno to ENOENT "No such file or directory"
    */
    char* full = NULL;
    char* result = NULL;
    
    if( VMPI_access(path, F_OK) ) {
        errno = ENOENT;
        return NULL;
    }
    
    //char *_fullpath( char *absPath, const char *relPath, size_t maxLength );
    result = _fullpath( full, path, PATH_MAX );
    //and from this point 'full' is fuxored and 'result' is all good
    
    if( result != NULL ) {
        return result;
    }
    
    return NULL; 
}

// ---- C.stdlib ---- END


// ---- C.unistd ---- 

int VMPI_chmod(const char *path, int mode)
{
    return _chmod(path, (mode_t)mode);
}

int VMPI_mkdir(const char *path)
{
    return _mkdir(path);
}

void VMPI_sleep(int milliseconds)
{
    Sleep(milliseconds);
}

void VMPI_getUserName(char *username)
{
    DWORD bufsize = 256;
    GetUserName(username, &bufsize);
}

int VMPI_gethostname(char *name, int namelen)
{
    int result = -1;
    
    if( WIN32_SocketStart(2,2) == 0 ) {
        result = ::gethostname(name, namelen);
    }
    
    return result;
}

// ---- C.unistd ---- END


// ---- C.stdio ---- 

void VMPI_con_stream_mode(int state)
{
    DWORD mode;
    HANDLE hstdin;
    
    hstdin  = GetStdHandle(STD_INPUT_HANDLE);
    GetConsoleMode( hstdin,  &mode );
    
    if (state==NONBLOCKING_ENABLE)
    {
        mode &= ~(ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT);
        SetConsoleMode( hstdin , mode );
    }
    else if (state==NONBLOCKING_DISABLE)
    {
        mode |= ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT;
        SetConsoleMode( hstdin , mode );
    }
    
    FlushConsoleInputBuffer( hstdin );
}

void VMPI_con_trans_mode(int state)
{
    _setmode( _fileno( stdin ), state );
    _setmode( _fileno( stdout ), state );
}

int VMPI_kbhit()
{
    return _kbhit();
}

// ---- C.stdio ---- END


// ---- C.socket ---- 

struct hostent *VMPI_gethostbyaddr(const char *addr)
{
    struct in_addr data_addr = { 0 };
    
    if( WIN32_SocketStart(2,2) == 0 ) {
        data_addr.s_addr = inet_addr(addr);
        return gethostbyaddr((char *) &data_addr, 4, AF_INET);
    }
    
    return NULL;
}


// ---- C.socket ---- END

// ---- avmplus.System ---- 

double VMPI_getStdinFileLength()
{
    int stdinHandle = _fileno(stdin);
    struct _stat stats;
    _fstat(stdinHandle, &stats);
    return stats.st_size;
}

// ---- avmplus.System ---- END


// ---- avmplus.OperatingSystem ---- 

//OperatingSystem.getName()
void VMPI_getOperatingSystemName(char *name)
{
    utsname info;
    const char *osname;
    
    if( uname(&info) < 0 ) {
        osname = "";
    }
    else {
        osname = info.sysname;
    }
    
    VMPI_strcpy( name, osname );
}

//OperatingSystem.getNodeName()
void VMPI_getOperatingSystemNodeName(char *nodename)
{
    utsname info;
    const char *osnodename;
    
    if( uname(&info) < 0 ) {
        osnodename = "";
    }
    else {
        osnodename = info.nodename;
    }
    
    VMPI_strcpy( nodename, osnodename );
}

//OperatingSystem.getRelease()
void VMPI_getOperatingSystemRelease(char *release)
{
    utsname info;
    const char *osrelease;
    
    if( uname(&info) < 0 ) {
        osrelease = "";
    }
    else {
        osrelease = info.release;
    }
    
    VMPI_strcpy( release, osrelease );
}

//OperatingSystem.getVersion()
void VMPI_getOperatingSystemVersion(char *version)
{
    utsname info;
    const char *osversion;
    
    if( uname(&info) < 0 ) {
        osversion = "";
    }
    else {
        osversion = info.version;
    }

    VMPI_strcpy( version, osversion );
}

//OperatingSystem.getMachine()
void VMPI_getOperatingSystemMachine(char *machine)
{
    utsname info;
    const char *osmachine;
    
    if( uname(&info) < 0 ) {
        osmachine = "";
    }
    else {
        osmachine = info.machine;
    }
    
    VMPI_strcpy( machine, osmachine );
}

//OperatingSystem.getVendorVersion()
void VMPI_getOperatingSystemVersionNumbers(int *major, int *minor, int *bugfix)
{
    //OSVERSIONINFO osver;
    //osver.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
    //GetVersionEx(&osver);
    
    OSVERSIONINFOEX osver;
    osver.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
    GetVersionEx((OSVERSIONINFO *) &osver);
    
    *major  = (int)osver.dwMajorVersion;
    *minor  = (int)osver.dwMinorVersion;
    //*bugfix = (int)osver.dwBuildNumber;
    *bugfix = (int)osver.wServicePackMajor; //yeah we can consider a service pack as a bugfix!!
}

// ---- avmplus.OperatingSystem ---- END


// ---- avmplus.FileSystem ---- 

int VMPI_getLogicalDrives()
{
    DWORD drives = GetLogicalDrives();
    return (int)drives;
}

int VMPI_getFileMode(const char *path)
{
    struct _stat stats;
    _stat(path, &stats);

    //a directory is always X
    if( S_ISDIR(stats.st_mode) )
    {
        return (stats.st_mode | S_IXUSR | S_IXGRP | S_IXOTH);
    }
    else
    {
        return stats.st_mode;
    }
}

double VMPI_getFileSize(const char *path)
{
    struct _stat stats;
    _stat(path, &stats);
    return stats.st_size;
}

double VMPI_getFileLastModifiedTime(const char *path)
{
    struct _stat stats;
    _stat(path, &stats);
    return double( stats.st_mtime ) * 1000.0;
}

bool VMPI_isRegularFile(const char *path)
{
    return S_ISREG( VMPI_getFileMode(path) );
}

bool VMPI_isDirectory(const char *path)
{
    return S_ISDIR( VMPI_getFileMode(path) );
}

//bool VMPI_isSymbolicLink(const char *path)

bool VMPI_isAttributeHidden(const char *path)
{
    DWORD attrib = GetFileAttributes( path );
    
    if(attrib & FILE_ATTRIBUTE_HIDDEN) {
        return true;
    }
    
    return false;
}

double VMPI_getFreeDiskSpace(const char *path)
{
    ULARGE_INTEGER available;
    if(!GetDiskFreeSpaceEx(path, &available, NULL, NULL)) {
        return -1;
    }
    return static_cast<double>(available.QuadPart);
}

double VMPI_getTotalDiskSpace(const char *path)
{
    ULARGE_INTEGER total;
    if(!GetDiskFreeSpaceEx(path, NULL, &total, NULL)) {
        return -1;
    }
    return static_cast<double>(total.QuadPart);
}

// ---- avmplus.FileSystem ---- END



