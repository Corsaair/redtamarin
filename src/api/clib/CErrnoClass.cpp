/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "avmshell.h"

namespace avmshell
{

    CErrnoClass::CErrnoClass(VTable *cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    CErrnoClass::~CErrnoClass()
    {
        
    }

    int CErrnoClass::get_EPERM() { return EPERM; }
    int CErrnoClass::get_ENOENT() { return ENOENT; }
    int CErrnoClass::get_ESRCH() { return ESRCH; }
    int CErrnoClass::get_EINTR() { return EINTR; }
    int CErrnoClass::get_EIO() { return EIO; }
    int CErrnoClass::get_ENXIO() { return ENXIO; }
    int CErrnoClass::get_E2BIG() { return E2BIG; }
    int CErrnoClass::get_ENOEXEC() { return ENOEXEC; }
    int CErrnoClass::get_EBADF() { return EBADF; }
    int CErrnoClass::get_ECHILD() { return ECHILD; }
    int CErrnoClass::get_EAGAIN() { return EAGAIN; }
    int CErrnoClass::get_ENOMEM() { return ENOMEM; }
    int CErrnoClass::get_EACCES() { return EACCES; }
    int CErrnoClass::get_EFAULT() { return EFAULT; }
    int CErrnoClass::get_ENOTBLK() { return ENOTBLK; }
    int CErrnoClass::get_EBUSY() { return EBUSY; }
    int CErrnoClass::get_EEXIST() { return EEXIST; }
    int CErrnoClass::get_EXDEV() { return EXDEV; }
    int CErrnoClass::get_ENODEV() { return ENODEV; }
    int CErrnoClass::get_ENOTDIR() { return ENOTDIR; }
    int CErrnoClass::get_EISDIR() { return EISDIR; }
    int CErrnoClass::get_EINVAL() { return EINVAL; }
    int CErrnoClass::get_ENFILE() { return ENFILE; }
    int CErrnoClass::get_EMFILE() { return EMFILE; }
    int CErrnoClass::get_ENOTTY() { return ENOTTY; }
    int CErrnoClass::get_ETXTBSY() { return ETXTBSY; }
    int CErrnoClass::get_EFBIG() { return EFBIG; }
    int CErrnoClass::get_ENOSPC() { return ENOSPC; }
    int CErrnoClass::get_ESPIPE() { return ESPIPE; }
    int CErrnoClass::get_EROFS() { return EROFS; }
    int CErrnoClass::get_EMLINK() { return EMLINK; }
    int CErrnoClass::get_EPIPE() { return EPIPE; }
    int CErrnoClass::get_EDOM() { return EDOM; }
    int CErrnoClass::get_ERANGE() { return ERANGE; }

    int CErrnoClass::get_EDEADLK() { return EDEADLK; }
    int CErrnoClass::get_ENAMETOOLONG() { return ENAMETOOLONG; }
    int CErrnoClass::get_ENOLCK() { return ENOLCK; }
    int CErrnoClass::get_ENOSYS() { return ENOSYS; }
    int CErrnoClass::get_ENOTEMPTY() { return ENOTEMPTY; }
    int CErrnoClass::get_ELOOP() { return ELOOP; }
    int CErrnoClass::get_EWOULDBLOCK() { return EWOULDBLOCK; }
    int CErrnoClass::get_ENOMSG() { return ENOMSG; }
    int CErrnoClass::get_EIDRM() { return EIDRM; }

    int CErrnoClass::get_EDEADLOCK() { return EDEADLOCK; }
    
    int CErrnoClass::get_ENOSTR() { return ENOSTR; }
    int CErrnoClass::get_ENODATA() { return ENODATA; }
    int CErrnoClass::get_ETIME() { return ETIME; }
    int CErrnoClass::get_ENOSR() { return ENOSR; }
    int CErrnoClass::get_ENOLINK() { return ENOLINK; }
    int CErrnoClass::get_EBADMSG() { return EBADMSG; }
    int CErrnoClass::get_EOVERFLOW() { return EOVERFLOW; }
    int CErrnoClass::get_EILSEQ() { return EILSEQ; }
    int CErrnoClass::get_ENOTSOCK() { return ENOTSOCK; }
    int CErrnoClass::get_EDESTADDRREQ() { return EDESTADDRREQ; }
    int CErrnoClass::get_EMSGSIZE() { return EMSGSIZE; }
    int CErrnoClass::get_EPROTO() { return EPROTO; }
    int CErrnoClass::get_EPROTOTYPE() { return EPROTOTYPE; }
    int CErrnoClass::get_ENOPROTOOPT() { return ENOPROTOOPT; }
    int CErrnoClass::get_EPROTONOSUPPORT() { return EPROTONOSUPPORT; }
    int CErrnoClass::get_EOPNOTSUPP() { return EOPNOTSUPP; }
    int CErrnoClass::get_EAFNOSUPPORT() { return EAFNOSUPPORT; }
    int CErrnoClass::get_EADDRINUSE() { return EADDRINUSE; }
    int CErrnoClass::get_EADDRNOTAVAIL() { return EADDRNOTAVAIL; }
    int CErrnoClass::get_ENETDOWN() { return ENETDOWN; }
    int CErrnoClass::get_ENETUNREACH() { return ENETUNREACH; }
    int CErrnoClass::get_ENETRESET() { return ENETRESET; }
    int CErrnoClass::get_ECONNABORTED() { return ECONNABORTED; }
    int CErrnoClass::get_ECONNRESET() { return ECONNRESET; }
    int CErrnoClass::get_ENOBUFS() { return ENOBUFS; }
    int CErrnoClass::get_EISCONN() { return EISCONN; }
    int CErrnoClass::get_ENOTCONN() { return ENOTCONN; }
    int CErrnoClass::get_ETIMEDOUT() { return ETIMEDOUT; }
    int CErrnoClass::get_ECONNREFUSED() { return ECONNREFUSED; }
    int CErrnoClass::get_EHOSTUNREACH() { return EHOSTUNREACH; }
    int CErrnoClass::get_EALREADY() { return EALREADY; }
    int CErrnoClass::get_EINPROGRESS() { return EINPROGRESS; }
    int CErrnoClass::get_ECANCELED() { return ECANCELED; }
    int CErrnoClass::get_EOWNERDEAD() { return EOWNERDEAD; }
    int CErrnoClass::get_ENOTRECOVERABLE() { return ENOTRECOVERABLE; }

    int CErrnoClass::get_EREMOTE() { return EREMOTE; }
    int CErrnoClass::get_EUSERS() { return EUSERS; }
    int CErrnoClass::get_ESOCKTNOSUPPORT() { return ESOCKTNOSUPPORT; }
    int CErrnoClass::get_EPFNOSUPPORT() { return EPFNOSUPPORT; }
    int CErrnoClass::get_ESHUTDOWN() { return ESHUTDOWN; }
    int CErrnoClass::get_ETOOMANYREFS() { return ETOOMANYREFS; }
    int CErrnoClass::get_EHOSTDOWN() { return EHOSTDOWN; }
    int CErrnoClass::get_ESTALE() { return ESTALE; }
    int CErrnoClass::get_EDQUOT() { return EDQUOT; }

    int CErrnoClass::get_EMULTIHOP() { return EMULTIHOP; }

    int CErrnoClass::get_ECHRNG() { return ECHRNG; }
    int CErrnoClass::get_EL2NSYNC() { return EL2NSYNC; }
    int CErrnoClass::get_EL3HLT() { return EL3HLT; }
    int CErrnoClass::get_EL3RST() { return EL3RST; }
    int CErrnoClass::get_ELNRNG() { return ELNRNG; }
    int CErrnoClass::get_EUNATCH() { return EUNATCH; }
    int CErrnoClass::get_ENOCSI() { return ENOCSI; }
    int CErrnoClass::get_EL2HLT() { return EL2HLT; }
    int CErrnoClass::get_EBADE() { return EBADE; }
    int CErrnoClass::get_EBADR() { return EBADR; }
    int CErrnoClass::get_EXFULL() { return EXFULL; }
    int CErrnoClass::get_ENOANO() { return ENOANO; }
    int CErrnoClass::get_EBADRQC() { return EBADRQC; }
    int CErrnoClass::get_EBADSLT() { return EBADSLT; }
    int CErrnoClass::get_EBFONT() { return EBFONT; }
    int CErrnoClass::get_ENONET() { return ENONET; }
    int CErrnoClass::get_ENOPKG() { return ENOPKG; }
    int CErrnoClass::get_EADV() { return EADV; }
    int CErrnoClass::get_ESRMNT() { return ESRMNT; }
    int CErrnoClass::get_ECOMM() { return ECOMM; }
    int CErrnoClass::get_EDOTDOT() { return EDOTDOT; }
    int CErrnoClass::get_ENOTUNIQ() { return ENOTUNIQ; }
    int CErrnoClass::get_EBADFD() { return EBADFD; }
    int CErrnoClass::get_EREMCHG() { return EREMCHG; }
    int CErrnoClass::get_ELIBACC() { return ELIBACC; }
    int CErrnoClass::get_ELIBBAD() { return ELIBBAD; }
    int CErrnoClass::get_ELIBSCN() { return ELIBSCN; }
    int CErrnoClass::get_ELIBMAX() { return ELIBMAX; }
    int CErrnoClass::get_ELIBEXEC() { return ELIBEXEC; }
    int CErrnoClass::get_ERESTART() { return ERESTART; }
    int CErrnoClass::get_ESTRPIPE() { return ESTRPIPE; }
    int CErrnoClass::get_EUCLEAN() { return EUCLEAN; }
    int CErrnoClass::get_ENOTNAM() { return ENOTNAM; }
    int CErrnoClass::get_ENAVAIL() { return ENAVAIL; }
    int CErrnoClass::get_EISNAM() { return EISNAM; }
    int CErrnoClass::get_EREMOTEIO() { return EREMOTEIO; }
    int CErrnoClass::get_ENOMEDIUM() { return ENOMEDIUM; }
    int CErrnoClass::get_EMEDIUMTYPE() { return EMEDIUMTYPE; }
    int CErrnoClass::get_ENOKEY() { return ENOKEY; }
    int CErrnoClass::get_EKEYEXPIRED() { return EKEYEXPIRED; }
    int CErrnoClass::get_EKEYREVOKED() { return EKEYREVOKED; }
    int CErrnoClass::get_EKEYREJECTED() { return EKEYREJECTED; }
    int CErrnoClass::get_ERFKILL() { return ERFKILL; }
    int CErrnoClass::get_EHWPOISON() { return EHWPOISON; }



    int CErrnoClass::_GetErrno()
    {
        return VMPI_get_errno();
    }
    
    void CErrnoClass::_SetErrno(int value)
    {
        VMPI_set_errno( value );
    }



    /*CErrorClass::CErrorClass(VTable *vtable)
        : NativeErrorClass(vtable)
    {
        createVanillaPrototype();
    }*/

    /*CErrorClass::~CErrorClass()
    {
        //nothing to destroy
    }*/

    /*void CErrorClass::dummy()
    {
        //does strictly nothing
    }*/


    /*CErrorObject::CErrorObject(VTable *vtable, ScriptObject *delegate)
        : ErrorObject(vtable, delegate)
    {}*/

    /*CErrorObject::~CErrorObject()
    {
        //nothing to destroy
    }*/

    /*void CErrorObject::dummy()
    {
        //does strictly nothing
    }*/

}
