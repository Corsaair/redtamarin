/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "avmshell.h"

namespace avmshell
{

    CLimitsClass::CLimitsClass(VTable *cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    CLimitsClass::~CLimitsClass()
    {
        
    }

    int CLimitsClass::get_CHAR_BIT() { return CHAR_BIT; }
    int CLimitsClass::get_CHAR_MAX() { return CHAR_MAX; }
    int CLimitsClass::get_CHAR_MIN() { return CHAR_MIN; }
    int CLimitsClass::get_INT_MAX() { return INT_MAX; }
    int CLimitsClass::get_INT_MIN() { return INT_MIN; }
    double CLimitsClass::get_LLONG_MAX() { return (double) LLONG_MAX; }
    double CLimitsClass::get_LLONG_MIN() { return (double) LLONG_MIN; }
    int CLimitsClass::get_LONG_BIT() { return LONG_BIT; }
    double CLimitsClass::get_LONG_MAX() { return (double) LONG_MAX; }
    double CLimitsClass::get_LONG_MIN() { return (double) LONG_MIN; }
    int CLimitsClass::get_SCHAR_MAX() { return SCHAR_MAX; }
    int CLimitsClass::get_SCHAR_MIN() { return SCHAR_MIN; }
    int CLimitsClass::get_SHRT_MAX() { return SHRT_MAX; }
    int CLimitsClass::get_SHRT_MIN() { return SHRT_MIN; }
    int CLimitsClass::get_UCHAR_MAX() { return UCHAR_MAX; }
    uint32_t CLimitsClass::get_UINT_MAX() { return (uint32_t) UINT_MAX; }
    double CLimitsClass::get_ULLONG_MAX() { return (double) ULLONG_MAX; }
    uint32_t CLimitsClass::get_ULONG_MAX() { return (uint32_t) ULONG_MAX; }
    int CLimitsClass::get_USHRT_MAX() { return USHRT_MAX; }
    int CLimitsClass::get_WORD_BIT() { return WORD_BIT; }

    int CLimitsClass::get_ARG_MAX() { return ARG_MAX; }
    int CLimitsClass::get_ATEXIT_MAX() { return ATEXIT_MAX; }
    int CLimitsClass::get_CHILD_MAX() { return CHILD_MAX; }
    int CLimitsClass::get_LINK_MAX() { return LINK_MAX; }
    int CLimitsClass::get_MAX_CANON() { return MAX_CANON; }
    int CLimitsClass::get_MAX_INPUT() { return MAX_INPUT; }
    int CLimitsClass::get_NAME_MAX() { return NAME_MAX; }
    int CLimitsClass::get_NGROUPS_MAX() { return NGROUPS_MAX; }
    int CLimitsClass::get_OPEN_MAX() { return OPEN_MAX; }
    int CLimitsClass::get_PATH_MAX() { return PATH_MAX; }
    int CLimitsClass::get_PIPE_BUF() { return PIPE_BUF; }
    double CLimitsClass::get_SSIZE_MAX() { return (double) SSIZE_MAX; }
    int CLimitsClass::get_STREAM_MAX() { return STREAM_MAX; }
    int CLimitsClass::get_TZNAME_MAX() { return TZNAME_MAX; }

    int CLimitsClass::get_MB_LEN_MAX() { return MB_LEN_MAX; }
    double CLimitsClass::get_SIZE_MAX() { return (double) SIZE_MAX; }
    int CLimitsClass::get_SYMLINK_MAX() { return SYMLINK_MAX; }

    int CLimitsClass::get_AIO_LISTIO_MAX() { return AIO_LISTIO_MAX; }
    int CLimitsClass::get_AIO_MAX() { return AIO_MAX; }
    int CLimitsClass::get_AIO_PRIO_DELTA_MAX() { return AIO_PRIO_DELTA_MAX; }
    int CLimitsClass::get_DELAYTIMER_MAX() { return DELAYTIMER_MAX; }
    int CLimitsClass::get_HOST_NAME_MAX() { return HOST_NAME_MAX; }
    int CLimitsClass::get_LOGIN_NAME_MAX() { return LOGIN_NAME_MAX; }
    int CLimitsClass::get_MQ_OPEN_MAX() { return MQ_OPEN_MAX; }
    int CLimitsClass::get_MQ_PRIO_MAX() { return MQ_PRIO_MAX; }

    int CLimitsClass::get_PAGESIZE() { return PAGESIZE; }
    int CLimitsClass::get_PAGE_SIZE() { return PAGE_SIZE; }
    int CLimitsClass::get_RE_DUP_MAX() { return RE_DUP_MAX; }
    int CLimitsClass::get_RTSIG_MAX() { return RTSIG_MAX; }
    int CLimitsClass::get_SEM_NSEMS_MAX() { return SEM_NSEMS_MAX; }
    int CLimitsClass::get_SEM_VALUE_MAX() { return SEM_VALUE_MAX; }
    int CLimitsClass::get_SIGQUEUE_MAX() { return SIGQUEUE_MAX; }
    int CLimitsClass::get_SS_REPL_MAX() { return SS_REPL_MAX; }

    int CLimitsClass::get_SYMLOOP_MAX() { return SYMLOOP_MAX; }
    int CLimitsClass::get_TIMER_MAX() { return TIMER_MAX; }
    int CLimitsClass::get_TRACE_EVENT_NAME_MAX() { return TRACE_EVENT_NAME_MAX; }
    int CLimitsClass::get_TRACE_NAME_MAX() { return TRACE_NAME_MAX; }
    int CLimitsClass::get_TRACE_SYS_MAX() { return TRACE_SYS_MAX; }
    int CLimitsClass::get_TRACE_USER_EVENT_MAX() { return TRACE_USER_EVENT_MAX; }
    int CLimitsClass::get_TTY_NAME_MAX() { return TTY_NAME_MAX; }

    int CLimitsClass::get__POSIX_ARG_MAX() { return _POSIX_ARG_MAX; }
    int CLimitsClass::get__POSIX_CHILD_MAX() { return _POSIX_CHILD_MAX; }
    int CLimitsClass::get__POSIX_LINK_MAX() { return _POSIX_LINK_MAX; }
    int CLimitsClass::get__POSIX_MAX_CANON() { return _POSIX_MAX_CANON; }
    int CLimitsClass::get__POSIX_MAX_INPUT() { return _POSIX_MAX_INPUT; }
    int CLimitsClass::get__POSIX_NAME_MAX() { return _POSIX_NAME_MAX; }
	int CLimitsClass::get__POSIX_NGROUPS_MAX() { return _POSIX_NGROUPS_MAX; }
	int CLimitsClass::get__POSIX_OPEN_MAX() { return _POSIX_OPEN_MAX; }
	int CLimitsClass::get__POSIX_PATH_MAX() { return _POSIX_PATH_MAX; }
	int CLimitsClass::get__POSIX_PIPE_BUF() { return _POSIX_PIPE_BUF; }
	int CLimitsClass::get__POSIX_SSIZE_MAX() { return _POSIX_SSIZE_MAX; }
	int CLimitsClass::get__POSIX_STREAM_MAX() { return _POSIX_STREAM_MAX; }
	int CLimitsClass::get__POSIX_TZNAME_MAX() { return _POSIX_TZNAME_MAX; }
	int CLimitsClass::get__POSIX_SYMLINK_MAX() { return _POSIX_SYMLINK_MAX; }

	int CLimitsClass::get__POSIX_AIO_LISTIO_MAX() { return _POSIX_AIO_LISTIO_MAX; }
	int CLimitsClass::get__POSIX_AIO_MAX() { return _POSIX_AIO_MAX; }
	int CLimitsClass::get__POSIX_DELAYTIMER_MAX() { return _POSIX_DELAYTIMER_MAX; }
	int CLimitsClass::get__POSIX_HOST_NAME_MAX() { return _POSIX_HOST_NAME_MAX; }
	int CLimitsClass::get__POSIX_LOGIN_NAME_MAX() { return _POSIX_LOGIN_NAME_MAX; }
	int CLimitsClass::get__POSIX_MQ_OPEN_MAX() { return _POSIX_MQ_OPEN_MAX; }
	int CLimitsClass::get__POSIX_MQ_PRIO_MAX() { return _POSIX_MQ_PRIO_MAX; }

	int CLimitsClass::get__POSIX_RE_DUP_MAX() { return _POSIX_RE_DUP_MAX; }
	int CLimitsClass::get__POSIX_RTSIG_MAX() { return _POSIX_RTSIG_MAX; }
	int CLimitsClass::get__POSIX_SEM_NSEMS_MAX() { return _POSIX_SEM_NSEMS_MAX; }
	int CLimitsClass::get__POSIX_SEM_VALUE_MAX() { return _POSIX_SEM_VALUE_MAX; }
	int CLimitsClass::get__POSIX_SIGQUEUE_MAX() { return _POSIX_SIGQUEUE_MAX; }
	int CLimitsClass::get__POSIX_SS_REPL_MAX() { return _POSIX_SS_REPL_MAX; }

	int CLimitsClass::get__POSIX_SYMLOOP_MAX() { return _POSIX_SYMLOOP_MAX; }
	int CLimitsClass::get__POSIX_TIMER_MAX() { return _POSIX_TIMER_MAX; }
	int CLimitsClass::get__POSIX_TRACE_EVENT_NAME_MAX() { return _POSIX_TRACE_EVENT_NAME_MAX; }
	int CLimitsClass::get__POSIX_TRACE_NAME_MAX() { return _POSIX_TRACE_NAME_MAX; }
	int CLimitsClass::get__POSIX_TRACE_SYS_MAX() { return _POSIX_TRACE_SYS_MAX; }
	int CLimitsClass::get__POSIX_TRACE_USER_EVENT_MAX() { return _POSIX_TRACE_USER_EVENT_MAX; }
	int CLimitsClass::get__POSIX_TTY_NAME_MAX() { return _POSIX_TTY_NAME_MAX; }


}
