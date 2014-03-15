/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_CFcntlClass__
#define __avmshell_CFcntlClass__

namespace avmshell
{
    using namespace avmplus;

    class CFcntlClass : public ClassClosure
    {
    public:
        CFcntlClass(VTable* cvtable);
        ~CFcntlClass();

        int get_O_RDONLY();
        int get_O_WRONLY();
        int get_O_RDWR();
        int get_O_ACCMODE();

        int get_O_APPEND();
        int get_O_CREAT();
        int get_O_TRUNC();
        int get_O_EXCL();

        int get_O_EXEC();
        int get_O_CLOEXEC();
        int get_O_DIRECTORY();
        int get_O_NOFOLLOW();
        int get_O_NONBLOCK();
        int get_O_NOCTTY();
        int get_O_SEARCH();
        int get_O_TTY_INIT();

        int get_O_SYNC();
        int get_O_DSYNC();
        int get_O_RSYNC();
        int get_O_ASYNC();
        int get_O_FSYNC();

        int get_O_SHLOCK();
        int get_O_EXLOCK();
        
        int get_O_TEXT();
        int get_O_BINARY();
        int get_O_WTEXT();
        int get_O_U16TEXT();
        int get_O_U8TEXT();
        int get_O_RAW();
        int get_O_NOINHERIT();
        int get_O_TEMPORARY();
        int get_O_SHORT_LIVED();
        int get_O_SEQUENTIAL();
        int get_O_RANDOM();


        int get_F_DUPFD();
        int get_F_DUPFD_CLOEXEC();
        int get_F_GETFD();
        int get_F_SETFD();
        int get_F_GETFL();
        int get_F_SETFL();
        int get_F_GETOWN();
        int get_F_SETOWN();


        static int creat(ScriptObject* self, Stringp path, int mode);
        static int fcntl(ScriptObject*, int fildes, int cmd, int arg);
        static int open(ScriptObject* self, Stringp path, int oflag, int mode);
        static int openat(ScriptObject* self, int fd, Stringp path, int oflag, int mode);
        
        DECLARE_SLOTS_CFcntlClass;
    };



}

#endif /* __avmshell_CFcntlClass__ */

