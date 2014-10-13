/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_CErrnoClass__
#define __avmshell_CErrnoClass__

namespace avmshell
{
    using namespace avmplus;

    class CErrnoClass : public ClassClosure
    {
    public:
        CErrnoClass(VTable* cvtable);
        ~CErrnoClass();
        
        int get_EPERM();
        int get_ENOENT();
        int get_ESRCH();
        int get_EINTR();
        int get_EIO();
        int get_ENXIO();
        int get_E2BIG();
        int get_ENOEXEC();
        int get_EBADF();
        int get_ECHILD();
        int get_EAGAIN();
        int get_ENOMEM();
        int get_EACCES();
        int get_EFAULT();
        int get_ENOTBLK();
        int get_EBUSY();
        int get_EEXIST();
        int get_EXDEV();
        int get_ENODEV();
        int get_ENOTDIR();
        int get_EISDIR();
        int get_EINVAL();
        int get_ENFILE();
        int get_EMFILE();
        int get_ENOTTY();
        int get_ETXTBSY();
        int get_EFBIG();
        int get_ENOSPC();
        int get_ESPIPE();
        int get_EROFS();
        int get_EMLINK();
        int get_EPIPE();
        int get_EDOM();
        int get_ERANGE();

        int get_EDEADLK();
        int get_ENAMETOOLONG();
        int get_ENOLCK();
        int get_ENOSYS();
        int get_ENOTEMPTY();
        int get_ELOOP();
        int get_EWOULDBLOCK();
        int get_ENOMSG();
        int get_EIDRM();

        int get_EDEADLOCK();

        int get_ENOSTR();
        int get_ENODATA();
        int get_ETIME();
        int get_ENOSR();
        int get_ENOLINK();
        int get_EBADMSG();
        int get_EOVERFLOW();
        int get_EILSEQ();
        int get_ENOTSOCK();
        int get_EDESTADDRREQ();
        int get_EMSGSIZE();
        int get_EPROTO();
        int get_EPROTOTYPE();
        int get_ENOPROTOOPT();
        int get_EPROTONOSUPPORT();
        int get_EOPNOTSUPP();
        int get_EAFNOSUPPORT();
        int get_EADDRINUSE();
        int get_EADDRNOTAVAIL();
        int get_ENETDOWN();
        int get_ENETUNREACH();
        int get_ENETRESET();
        int get_ECONNABORTED();
        int get_ECONNRESET();
        int get_ENOBUFS();
        int get_EISCONN();
        int get_ENOTCONN();
        int get_ETIMEDOUT();
        int get_ECONNREFUSED();
        int get_EHOSTUNREACH();
        int get_EALREADY();
        int get_EINPROGRESS();
        int get_ECANCELED();
        int get_EOWNERDEAD();
        int get_ENOTRECOVERABLE();

        int get_EREMOTE();
        int get_EUSERS();
        int get_ESOCKTNOSUPPORT();
        int get_EPFNOSUPPORT();
        int get_ESHUTDOWN();
        int get_ETOOMANYREFS();
        int get_EHOSTDOWN();
        int get_ESTALE();
        int get_EDQUOT();

        int get_EMULTIHOP();

        int get_ECHRNG();
        int get_EL2NSYNC();
        int get_EL3HLT();
        int get_EL3RST();
        int get_ELNRNG();
        int get_EUNATCH();
        int get_ENOCSI();
        int get_EL2HLT();
        int get_EBADE();
        int get_EBADR();
        int get_EXFULL();
        int get_ENOANO();
        int get_EBADRQC();
        int get_EBADSLT();
        int get_EBFONT();
        int get_ENONET();
        int get_ENOPKG();
        int get_EADV();
        int get_ESRMNT();
        int get_ECOMM();
        int get_EDOTDOT();
        int get_ENOTUNIQ();
        int get_EBADFD();
        int get_EREMCHG();
        int get_ELIBACC();
        int get_ELIBBAD();
        int get_ELIBSCN();
        int get_ELIBMAX();
        int get_ELIBEXEC();
        int get_ERESTART();
        int get_ESTRPIPE();
        int get_EUCLEAN();
        int get_ENOTNAM();
        int get_ENAVAIL();
        int get_EISNAM();
        int get_EREMOTEIO();
        int get_ENOMEDIUM();
        int get_EMEDIUMTYPE();
        int get_ENOKEY();
        int get_EKEYEXPIRED();
        int get_EKEYREVOKED();
        int get_EKEYREJECTED();
        int get_ERFKILL();
        int get_EHWPOISON();


        int _GetErrno();
        void _SetErrno(int value);

        DECLARE_SLOTS_CErrnoClass;
    };




    class CErrorClass : public NativeErrorClass
    {
    public:
        CErrorClass(VTable* vtable) : NativeErrorClass(vtable) {};
        /*~CErrorClass();*/

        /*void dummy();*/

    private:
        DECLARE_SLOTS_CErrorClass;
    };

    class CErrorObject : public ErrorObject
    {
    public:
        CErrorObject(VTable *vtable, ScriptObject *delegate) : ErrorObject(vtable, delegate) {};
        /*~CErrorObject();*/

        /*void dummy();*/

    private:
        DECLARE_SLOTS_CErrorObject;
    };

}

#endif /* __avmshell_CErrnoClass__ */

