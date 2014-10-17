/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_CLimitsClass__
#define __avmshell_CLimitsClass__

namespace avmshell
{
    using namespace avmplus;

    class CLimitsClass : public ClassClosure
    {
    public:
        CLimitsClass(VTable* cvtable);
        ~CLimitsClass();
        
        int get_CHAR_BIT();
        int get_CHAR_MAX();
        int get_CHAR_MIN();
        int get_INT_MAX();
        int get_INT_MIN();
        double get_LLONG_MAX();
        double get_LLONG_MIN();
        int get_LONG_BIT();
        double get_LONG_MAX();
        double get_LONG_MIN();
        int get_SCHAR_MAX();
        int get_SCHAR_MIN();
        int get_SHRT_MAX();
        int get_SHRT_MIN();
        int get_UCHAR_MAX();
        uint32_t get_UINT_MAX();
        double get_ULLONG_MAX();
        uint32_t get_ULONG_MAX();
        int get_USHRT_MAX();
        int get_WORD_BIT();

        int get_ARG_MAX();
        int get_ATEXIT_MAX();
        int get_CHILD_MAX();
        int get_LINK_MAX();
        int get_MAX_CANON();
        int get_MAX_INPUT();
        int get_NAME_MAX();
        int get_NGROUPS_MAX();
        int get_OPEN_MAX();
        int get_PATH_MAX();
        int get_PIPE_BUF();
        double get_SSIZE_MAX();
        int get_STREAM_MAX();
        int get_TZNAME_MAX();

        int get_MB_LEN_MAX();
        double get_SIZE_MAX();
        int get_SYMLINK_MAX();

        int get_AIO_LISTIO_MAX();
        int get_AIO_MAX();
        int get_AIO_PRIO_DELTA_MAX();
        int get_DELAYTIMER_MAX();
        int get_HOST_NAME_MAX();
        int get_LOGIN_NAME_MAX();
        int get_MQ_OPEN_MAX();
        int get_MQ_PRIO_MAX();

        int get_PAGESIZE();
        int get_PAGE_SIZE();
        int get_RE_DUP_MAX();
        int get_RTSIG_MAX();
        int get_SEM_NSEMS_MAX();
        int get_SEM_VALUE_MAX();
        int get_SIGQUEUE_MAX();
        int get_SS_REPL_MAX();

        int get_SYMLOOP_MAX();
        int get_TIMER_MAX();
        int get_TRACE_EVENT_NAME_MAX();
        int get_TRACE_NAME_MAX();
        int get_TRACE_SYS_MAX();
        int get_TRACE_USER_EVENT_MAX();
        int get_TTY_NAME_MAX();

        int get__POSIX_ARG_MAX();
        int get__POSIX_CHILD_MAX();
        int get__POSIX_LINK_MAX();
        int get__POSIX_MAX_CANON();
        int get__POSIX_MAX_INPUT();
        int get__POSIX_NAME_MAX();
        int get__POSIX_NGROUPS_MAX();
        int get__POSIX_OPEN_MAX();
        int get__POSIX_PATH_MAX();
        int get__POSIX_PIPE_BUF();
        int get__POSIX_SSIZE_MAX();
        int get__POSIX_STREAM_MAX();
        int get__POSIX_TZNAME_MAX();
        int get__POSIX_SYMLINK_MAX();

        int get__POSIX_AIO_LISTIO_MAX();
        int get__POSIX_AIO_MAX();
        int get__POSIX_DELAYTIMER_MAX();
        int get__POSIX_HOST_NAME_MAX();
        int get__POSIX_LOGIN_NAME_MAX();
        int get__POSIX_MQ_OPEN_MAX();
        int get__POSIX_MQ_PRIO_MAX();

        int get__POSIX_RE_DUP_MAX();
        int get__POSIX_RTSIG_MAX();
        int get__POSIX_SEM_NSEMS_MAX();
        int get__POSIX_SEM_VALUE_MAX();
        int get__POSIX_SIGQUEUE_MAX();
        int get__POSIX_SS_REPL_MAX();

        int get__POSIX_SYMLOOP_MAX();
        int get__POSIX_TIMER_MAX();
        int get__POSIX_TRACE_EVENT_NAME_MAX();
        int get__POSIX_TRACE_NAME_MAX();
        int get__POSIX_TRACE_SYS_MAX();
        int get__POSIX_TRACE_USER_EVENT_MAX();
        int get__POSIX_TTY_NAME_MAX();
        
        DECLARE_SLOTS_CLimitsClass;
    };

}

#endif /* __avmshell_CLimitsClass__ */

