/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "avmshell.h"

namespace avmshell
{

    CFcntlClass::CFcntlClass(VTable *cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    CFcntlClass::~CFcntlClass()
    {
        
    }


    int CFcntlClass::get_O_RDONLY() { return O_RDONLY; }
    int CFcntlClass::get_O_WRONLY() { return O_WRONLY; }
    int CFcntlClass::get_O_RDWR() { return O_RDWR; }
    int CFcntlClass::get_O_ACCMODE() { return O_ACCMODE; }

    int CFcntlClass::get_O_APPEND() { return O_APPEND; }
    int CFcntlClass::get_O_CREAT() { return O_CREAT; }
    int CFcntlClass::get_O_TRUNC() { return O_TRUNC; }
    int CFcntlClass::get_O_EXCL() { return O_EXCL; }

    int CFcntlClass::get_O_EXEC() { return O_EXEC; }
    int CFcntlClass::get_O_CLOEXEC() { return O_CLOEXEC; }
    int CFcntlClass::get_O_DIRECTORY() { return O_DIRECTORY; }
    int CFcntlClass::get_O_NOFOLLOW() { return O_NOFOLLOW; }
    int CFcntlClass::get_O_NONBLOCK() { return O_NONBLOCK; }
    int CFcntlClass::get_O_NOCTTY() { return O_NOCTTY; }
    int CFcntlClass::get_O_SEARCH() { return O_SEARCH; }
    int CFcntlClass::get_O_TTY_INIT() { return O_TTY_INIT; }

    int CFcntlClass::get_O_SYNC() { return O_SYNC; }
    int CFcntlClass::get_O_DSYNC() { return O_DSYNC; }
    int CFcntlClass::get_O_RSYNC() { return O_RSYNC; }
    int CFcntlClass::get_O_ASYNC() { return O_ASYNC; }
    int CFcntlClass::get_O_FSYNC() { return O_FSYNC; }

    int CFcntlClass::get_O_SHLOCK() { return O_SHLOCK; }
    int CFcntlClass::get_O_EXLOCK() { return O_EXLOCK; }

    int CFcntlClass::get_O_TEXT() { return O_TEXT; }
    int CFcntlClass::get_O_BINARY() { return O_BINARY; }
    int CFcntlClass::get_O_WTEXT() { return O_WTEXT; }
    int CFcntlClass::get_O_U16TEXT() { return O_U16TEXT; }
    int CFcntlClass::get_O_U8TEXT() { return O_U8TEXT; }
    int CFcntlClass::get_O_RAW() { return O_RAW; }
    int CFcntlClass::get_O_NOINHERIT() { return O_NOINHERIT; }
    int CFcntlClass::get_O_TEMPORARY() { return O_TEMPORARY; }
    int CFcntlClass::get_O_SHORT_LIVED() { return O_SHORT_LIVED; }
    int CFcntlClass::get_O_SEQUENTIAL() { return O_SEQUENTIAL; }
    int CFcntlClass::get_O_RANDOM() { return O_RANDOM; }


    int CFcntlClass::get_F_DUPFD() { return F_DUPFD; }
    int CFcntlClass::get_F_DUPFD_CLOEXEC() { return F_DUPFD_CLOEXEC; }
    int CFcntlClass::get_F_GETFD() { return F_GETFD; }
    int CFcntlClass::get_F_SETFD() { return F_SETFD; }
    int CFcntlClass::get_F_GETFL() { return F_GETFL; }
    int CFcntlClass::get_F_SETFL() { return F_SETFL; }
    int CFcntlClass::get_F_GETOWN() { return F_GETOWN; }
    int CFcntlClass::get_F_SETOWN() { return F_SETOWN; }


    /*static*/ int CFcntlClass::creat(ScriptObject* self, Stringp path, int mode)
    {
        Toplevel* toplevel = self->toplevel();

        if( !path )
        {
            toplevel->throwArgumentError(kNullArgumentError, "path");
        }
        
        StUTF8String pathUTF8(path);
        return VMPI_creat( pathUTF8.c_str(), mode );
    }

    /*static*/ int CFcntlClass::fcntl(ScriptObject*, int fildes, int cmd, int arg)
    {
        return VMPI_fcntl( fildes, cmd, arg );
    }

    /*static*/ int CFcntlClass::open(ScriptObject* self, Stringp path, int oflag, int mode)
    {
        Toplevel* toplevel = self->toplevel();

        if( !path )
        {
            toplevel->throwArgumentError(kNullArgumentError, "path");
        }
        
        StUTF8String pathUTF8(path);

        if( mode > -1 )
        {
            return VMPI_open( pathUTF8.c_str(), oflag, mode );    
        }
        else
        {
            return VMPI_open( pathUTF8.c_str(), oflag );
        }
    }

    /*static*/ int CFcntlClass::openat(ScriptObject* self, int fd, Stringp path, int oflag, int mode)
    {
        Toplevel* toplevel = self->toplevel();

        if( !path )
        {
            toplevel->throwArgumentError(kNullArgumentError, "path");
        }
        
        StUTF8String pathUTF8(path);
        return VMPI_openat( fd, pathUTF8.c_str(), oflag, mode );
    }

}
