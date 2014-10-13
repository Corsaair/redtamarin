/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_CSysSocketClass__
#define __avmshell_CSysSocketClass__

namespace avmshell
{
    using namespace avmplus;

    class CSysSocketClass : public ClassClosure
    {
    public:
        CSysSocketClass(VTable* cvtable);
        ~CSysSocketClass();

        int get_SOCK_DGRAM();
        int get_SOCK_RAW();
        int get_SOCK_SEQPACKET();
        int get_SOCK_STREAM();

        int get_SOL_SOCKET();

        int get_SO_ACCEPTCONN();
        int get_SO_BROADCAST();
        int get_SO_DEBUG();
        int get_SO_DONTROUTE();
        int get_SO_ERROR();
        int get_SO_KEEPALIVE();
        int get_SO_LINGER();
        int get_SO_OOBINLINE();
        int get_SO_RCVBUF();
        int get_SO_RCVLOWAT();
        int get_SO_RCVTIMEO();
        int get_SO_REUSEADDR();
        int get_SO_SNDBUF();
        int get_SO_SNDLOWAT();
        int get_SO_SNDTIMEO();
        int get_SO_TYPE();

        int get_SOMAXCONN();

        int get_MSG_CTRUNC();
        int get_MSG_DONTROUTE();
        int get_MSG_EOR();
        int get_MSG_OOB();
        int get_MSG_NOSIGNAL();
        int get_MSG_PEEK();
        int get_MSG_TRUNC();
        int get_MSG_WAITALL();

        int get_AF_INET();
        int get_AF_INET6();
        int get_AF_UNIX();
        int get_AF_UNSPEC();

        int get_SHUT_RD();
        int get_SHUT_RDWR();
        int get_SHUT_WR();
        

        int accept4(int socket, CSockaddr_inObject* address);
        int accept6(int socket, CSockaddr_in6Object* address);
        int bind4(int socket, CSockaddr_inObject* address);
        int bind6(int socket, CSockaddr_in6Object* address);
        int connect4(int socket, CSockaddr_inObject* address);
        int connect6(int socket, CSockaddr_in6Object* address);
        int getpeername4(int socket, CSockaddr_inObject* address);
        int getpeername6(int socket, CSockaddr_in6Object* address);
        int getsockname4(int socket, CSockaddr_inObject* address);
        int getsockname6(int socket, CSockaddr_in6Object* address);
        int getsockoptint(int socket, int level, int option_name, ByteArrayObject* option_value);
        int recvfrom4(int socket, ByteArrayObject* bytes, CSockaddr_inObject* address, int len, int flags);
        int recvfrom6(int socket, ByteArrayObject* bytes, CSockaddr_in6Object* address, int len, int flags);
        int sendto4(int socket, ByteArrayObject* bytes, CSockaddr_inObject* address, int flags, uint32_t buffer);
        int sendto6(int socket, ByteArrayObject* bytes, CSockaddr_in6Object* address, int flags, uint32_t buffer);
        int setsockoptint(int socket, int level, int option_name, int option_value);


        //accept() -> accept4() / accept6()
        //bind() -> bind4() / bind6()
        //connect() -> connect4() / connect6()
        //getpeername() -> getpeername4() / getpeername6()
        //getsockname() -> getsockname4() / getsockname6()
        //getsockopt() -> getsockoptint() / ???
        static int listen(ScriptObject*, int socket, int backlog);
        static int recv(ScriptObject* self, int socket, ByteArrayObject* bytes, int len, int flags);
        //recvfrom() -> recvfrom4() / recvfrom6()
        //recvmsg()
        static int send(ScriptObject* self, int socket, ByteArrayObject* bytes, int flags, uint32_t buffer);
        //sendmsg()
        //sendto() -> sendto4() / sendto6()
        //setsockopt() -> setsockoptint() / ???
        static int shutdown(ScriptObject*, int socket, int how);
        static int sockatmark(ScriptObject*, int s);
        static int socket(ScriptObject*, int domain, int type, int protocol);
        static int socketpair(ScriptObject* self, int domain, int type, int protocol, ArrayObject* sockets);

        DECLARE_SLOTS_CSysSocketClass;
    };

    
    class CsockaddrClass : public ClassClosure
    {
    public:
        CsockaddrClass(VTable* vtable);
        ~CsockaddrClass();

        void dummy();

    private:
        DECLARE_SLOTS_CsockaddrClass;
    };

    class CsockaddrObject : public ScriptObject
    {
    public:
        CsockaddrObject(VTable *vtable, ScriptObject *delegate);
        ~CsockaddrObject();

        void dummy();

    private:
        DECLARE_SLOTS_CsockaddrObject;
    };

    /*
    class Cfpos_tClass : public ClassClosure
    {
    public:
        Cfpos_tClass(VTable* vtable);
        ~Cfpos_tClass();

        void dummy();

    private:
        DECLARE_SLOTS_Cfpos_tClass;
    };

    class Cfpos_tObject : public ScriptObject
    {
    public:
        Cfpos_tObject(VTable *vtable, ScriptObject *delegate);
        ~Cfpos_tObject();

        fpos_t read();
        void write(fpos_t value);

    private:
        fpos_t _pos;

        DECLARE_SLOTS_Cfpos_tObject;
    };
    */



}

#endif /* __avmshell_CSysSocketClass__ */

