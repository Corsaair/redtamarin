/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "avmshell.h"

namespace avmshell
{

    CSysSocketClass::CSysSocketClass(VTable *cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    CSysSocketClass::~CSysSocketClass()
    {
        
    }


    int CSysSocketClass::get_SOCK_DGRAM() { return SOCK_DGRAM; }
    int CSysSocketClass::get_SOCK_RAW() { return SOCK_RAW; }
    int CSysSocketClass::get_SOCK_SEQPACKET() { return SOCK_SEQPACKET; }
    int CSysSocketClass::get_SOCK_STREAM() { return SOCK_STREAM; }

    int CSysSocketClass::get_SOL_SOCKET() { return SOL_SOCKET; }

    int CSysSocketClass::get_SO_ACCEPTCONN() { return SO_ACCEPTCONN; }
    int CSysSocketClass::get_SO_BROADCAST() { return SO_BROADCAST; }
    int CSysSocketClass::get_SO_DEBUG() { return SO_DEBUG; }
    int CSysSocketClass::get_SO_DONTROUTE() { return SO_DONTROUTE; }
    int CSysSocketClass::get_SO_ERROR() { return SO_ERROR; }
    int CSysSocketClass::get_SO_KEEPALIVE() { return SO_KEEPALIVE; }
    int CSysSocketClass::get_SO_LINGER() { return SO_LINGER; }
    int CSysSocketClass::get_SO_OOBINLINE() { return SO_OOBINLINE; }
    int CSysSocketClass::get_SO_RCVBUF() { return SO_RCVBUF; }
    int CSysSocketClass::get_SO_RCVLOWAT() { return SO_RCVLOWAT; }
    int CSysSocketClass::get_SO_RCVTIMEO() { return SO_RCVTIMEO; }
    int CSysSocketClass::get_SO_REUSEADDR() { return SO_REUSEADDR; }
    int CSysSocketClass::get_SO_SNDBUF() { return SO_SNDBUF; }
    int CSysSocketClass::get_SO_SNDLOWAT() { return SO_SNDLOWAT; }
    int CSysSocketClass::get_SO_SNDTIMEO() { return SO_SNDTIMEO; }
    int CSysSocketClass::get_SO_TYPE() { return SO_TYPE; }

    int CSysSocketClass::get_SOMAXCONN() { return SOMAXCONN; }

    int CSysSocketClass::get_MSG_CTRUNC() { return MSG_CTRUNC; }
    int CSysSocketClass::get_MSG_DONTROUTE() { return MSG_DONTROUTE; }
    int CSysSocketClass::get_MSG_EOR() { return MSG_EOR; }
    int CSysSocketClass::get_MSG_OOB() { return MSG_OOB; }
    int CSysSocketClass::get_MSG_NOSIGNAL() { return MSG_NOSIGNAL; }
    //int CSysSocketClass::get_MSG_NOSIGNAL() { return -1; }
    int CSysSocketClass::get_MSG_PEEK() { return MSG_PEEK; }
    int CSysSocketClass::get_MSG_TRUNC() { return MSG_TRUNC; }
    int CSysSocketClass::get_MSG_WAITALL() { return MSG_WAITALL; }

    int CSysSocketClass::get_AF_INET() { return AF_INET; }
    int CSysSocketClass::get_AF_INET6() { return AF_INET6; }
    int CSysSocketClass::get_AF_UNIX() { return AF_UNIX; }
    int CSysSocketClass::get_AF_UNSPEC() { return AF_UNSPEC; }

    int CSysSocketClass::get_SHUT_RD() { return SHUT_RD; }
    int CSysSocketClass::get_SHUT_RDWR() { return SHUT_RDWR; }
    int CSysSocketClass::get_SHUT_WR() { return SHUT_WR; }


    int CSysSocketClass::accept4(int socket, CSockaddr_inObject* address)
    {
        int result;

        if( !address )
        {
            result = VMPI_accept( socket, NULL, NULL );
        }
        else
        {
            struct sockaddr_in sockaddr4;
            socklen_t addr_size;

            addr_size = sizeof( sockaddr4 );
            result = VMPI_accept( socket, (struct sockaddr *)&sockaddr4, &addr_size );

            if( result != -1 )
            {
                address->fromStruct( sockaddr4 );
            }

        }

        return result;
    }

    int CSysSocketClass::accept6(int socket, CSockaddr_in6Object* address)
    {
        int result = -1;

        if( !address )
        {
            result = VMPI_accept( socket, NULL, NULL );
        }
        else
        {
            struct sockaddr_in6 sockaddr6;
            socklen_t addr_size = sizeof sockaddr6;

            int result = VMPI_accept( socket, (struct sockaddr *)&sockaddr6, &addr_size );

            if( result != -1 )
            {
                address->fromStruct( sockaddr6 );
            }
        }

        return result;
    }

    int CSysSocketClass::bind4(int socket, CSockaddr_inObject* address)
    {
        //Toplevel* toplevel = this->toplevel();
        //AvmCore* core = toplevel->core();

        if( !address )
        {
            toplevel()->throwArgumentError(kNullArgumentError, "address");
        }

        struct sockaddr_in sockaddr4;
        sockaddr4 = address->toStruct();

        return VMPI_bind( socket, (struct sockaddr *)&sockaddr4, sizeof sockaddr4 );
    }

    int CSysSocketClass::bind6(int socket, CSockaddr_in6Object* address)
    {
        if( !address )
        {
            toplevel()->throwArgumentError(kNullArgumentError, "address");
        }

        struct sockaddr_in6 sockaddr6;
        sockaddr6 = address->toStruct();

        return VMPI_bind( socket, (struct sockaddr *)&sockaddr6, sizeof sockaddr6 );
    }

    int CSysSocketClass::connect4(int socket, CSockaddr_inObject* address)
    {
        if( !address )
        {
            toplevel()->throwArgumentError(kNullArgumentError, "address");
        }

        struct sockaddr_in sockaddr4;
        sockaddr4 = address->toStruct();

        int result = VMPI_connect( socket, (struct sockaddr *)&sockaddr4, sizeof sockaddr4 );

        if( result != -1 )
        {
            address->fromStruct( sockaddr4 );
        }

        return result;
    }

    int CSysSocketClass::connect6(int socket, CSockaddr_in6Object* address)
    {
        if( !address )
        {
            toplevel()->throwArgumentError(kNullArgumentError, "address");
        }

        struct sockaddr_in6 sockaddr6;
        sockaddr6 = address->toStruct();

        int result = VMPI_connect( socket, (struct sockaddr *)&sockaddr6, sizeof sockaddr6 );

        if( result != -1 )
        {
            address->fromStruct( sockaddr6 );
        }

        return result;
    }

    int CSysSocketClass::getpeername4(int socket, CSockaddr_inObject* address)
    {
        if( !address )
        {
            toplevel()->throwArgumentError(kNullArgumentError, "address");
        }

        struct sockaddr_in sockaddr4;
        socklen_t addr_size = sizeof sockaddr4;

        int result = VMPI_getpeername( socket, (struct sockaddr *)&sockaddr4, &addr_size );

        if( result != -1 )
        {
            address->fromStruct( sockaddr4 );
        }

        return result;
    }

    int CSysSocketClass::getpeername6(int socket, CSockaddr_in6Object* address)
    {
        if( !address )
        {
            toplevel()->throwArgumentError(kNullArgumentError, "address");
        }

        struct sockaddr_in6 sockaddr6;
        socklen_t addr_size = sizeof sockaddr6;

        int result = VMPI_getpeername( socket, (struct sockaddr *)&sockaddr6, &addr_size );

        if( result != -1 )
        {
            address->fromStruct( sockaddr6 );
        }

        return result;
    }

    int CSysSocketClass::getsockname4(int socket, CSockaddr_inObject* address)
    {
        if( !address )
        {
            toplevel()->throwArgumentError(kNullArgumentError, "address");
        }

        struct sockaddr_in sockaddr4;
        socklen_t addr_size = sizeof sockaddr4;

        int result = VMPI_getsockname( socket, (struct sockaddr *)&sockaddr4, &addr_size );

        if( result != -1 )
        {
            address->fromStruct( sockaddr4 );
        }

        return result;
    }

    int CSysSocketClass::getsockname6(int socket, CSockaddr_in6Object* address)
    {
        if( !address )
        {
            toplevel()->throwArgumentError(kNullArgumentError, "address");
        }

        struct sockaddr_in6 sockaddr6;
        socklen_t addr_size = sizeof sockaddr6;

        int result = VMPI_getsockname( socket, (struct sockaddr *)&sockaddr6, &addr_size );

        if( result != -1 )
        {
            address->fromStruct( sockaddr6 );
        }

        return result;
    }

    int CSysSocketClass::getsockoptint(int socket, int level, int option_name, ByteArrayObject* option_value)
    {
        int value     = 0;
        socklen_t len = sizeof( value );

        //printf( "before value = %i\n", value );
        //int result = VMPI_getsockopt( socket, level, option_name, &value, (socklen_t *)&len );
        int result = VMPI_getsockopt( socket, level, option_name, &value, &len );
        //printf( " after value = %i\n", value );
        //printf( "      result = %i\n", result );

        if( result != -1 )
        {
            option_value->clear(); //does set pos=0
            option_value->writeObject( core()->intToAtom( value ) );
            //option_value->writeObject( value );
            //option_value->set_position(0);
            /*
            if( value == 0 )
            {
                option_value->writeObject( 0 );
            }
            else if( value > 0 )
            {
                option_value->writeObject( 1 );
            }
            */
        }

        return result;
    }

    int CSysSocketClass::recvfrom4(int socket, ByteArrayObject* bytes, CSockaddr_inObject* address, int len, int flags)
    {
        Toplevel* toplevel = this->toplevel();
        AvmCore* core = toplevel->core();

        if( !bytes )
        {
            toplevel->throwArgumentError(kNullArgumentError, "bytes");
        }

        if( !address )
        {
            toplevel->throwArgumentError(kNullArgumentError, "address");
        }

        if(len >= INT32_T_MAX) //Socket APIs cannot handle files > 2GB
        {
            Stringp errormsg = core->newStringUTF8( "buffer size bigger than 2GB" );
            toplevel->throwRangeError(kOutOfRangeError, errormsg);
        }

        if( len <= 0 )
        {
            //read 0 return 0
            return 0;
        }

        unsigned char *data = mmfx_new_array( unsigned char, len+1);

        struct sockaddr_in sockaddr4;
        socklen_t addr_size;

        sockaddr4 = address->toStruct();
        addr_size = sizeof( sockaddr4 );

        int result = VMPI_recvfrom( socket, data, len, flags, (struct sockaddr *)&sockaddr4, &addr_size );

        if( result > 0 )
        {
            bytes->GetByteArray().Write(data, (uint32_t) result);
            //bytes->set_position(0);
        }

        if( result != -1 )
        {
            address->fromStruct( sockaddr4 );
        }

        mmfx_delete_array( data );

        return result;
    }

    int CSysSocketClass::recvfrom6(int socket, ByteArrayObject* bytes, CSockaddr_in6Object* address, int len, int flags)
    {
        Toplevel* toplevel = this->toplevel();
        AvmCore* core = toplevel->core();

        if( !bytes )
        {
            toplevel->throwArgumentError(kNullArgumentError, "bytes");
        }

        if( !address )
        {
            toplevel->throwArgumentError(kNullArgumentError, "address");
        }

        if(len >= INT32_T_MAX) //Socket APIs cannot handle files > 2GB
        {
            Stringp errormsg = core->newStringUTF8( "buffer size bigger than 2GB" );
            toplevel->throwRangeError(kOutOfRangeError, errormsg);
        }

        if( len <= 0 )
        {
            //read 0 return 0
            return 0;
        }

        unsigned char *data = mmfx_new_array( unsigned char, len+1);

        struct sockaddr_in6 sockaddr6;
        socklen_t addr_size;

        sockaddr6 = address->toStruct();
        addr_size = sizeof( sockaddr6 );

        int result = VMPI_recvfrom( socket, data, len, flags, (struct sockaddr *)&sockaddr6, &addr_size );

        if( result > 0 )
        {
            bytes->GetByteArray().Write(data, (uint32_t) result);
            //bytes->set_position(0);
        }

        if( result != -1 )
        {
            address->fromStruct( sockaddr6 );
        }

        mmfx_delete_array( data );

        return result;
    }


    int CSysSocketClass::sendto4(int socket, ByteArrayObject* bytes, CSockaddr_inObject* address, int flags, uint32_t buffer)
    {
        Toplevel* toplevel = this->toplevel();
        AvmCore* core = toplevel->core();

        if( !bytes )
        {
            toplevel->throwArgumentError(kNullArgumentError, "bytes");
        }

        if( !address )
        {
            toplevel->throwArgumentError(kNullArgumentError, "address");
        }

        uint32_t byteslen = bytes->GetByteArray().GetLength();

        if( (buffer > 0) && (buffer < byteslen) )
        {
            byteslen = buffer;
        }

        if(byteslen >= (uint32_t)INT32_T_MAX) //Socket APIs cannot handle files > 2GB
        {
            Stringp errormsg = core->newStringUTF8( "buffer size bigger than 2GB" );
            toplevel->throwRangeError(kOutOfRangeError, errormsg);
        }

        bytes->set_position(0);
        unsigned char *data = mmfx_new_array( unsigned char, byteslen+1);
        bytes->GetByteArray().Read(data, (uint32_t) byteslen);

        struct sockaddr_in sockaddr4;
        sockaddr4 = address->toStruct();

        int result = VMPI_sendto( socket, data, byteslen, flags, (struct sockaddr *)&sockaddr4, sizeof sockaddr4 );

        if( result != -1 )
        {
            address->fromStruct( sockaddr4 );
        }

        mmfx_delete_array( data );

        return result;
    }

    int CSysSocketClass::sendto6(int socket, ByteArrayObject* bytes, CSockaddr_in6Object* address, int flags, uint32_t buffer)
    {
        Toplevel* toplevel = this->toplevel();
        AvmCore* core = toplevel->core();

        if( !bytes )
        {
            toplevel->throwArgumentError(kNullArgumentError, "bytes");
        }

        if( !address )
        {
            toplevel->throwArgumentError(kNullArgumentError, "address");
        }

        uint32_t byteslen = bytes->GetByteArray().GetLength();

        if( (buffer > 0) && (buffer < byteslen) )
        {
            byteslen = buffer;
        }

        if(byteslen >= (uint32_t)INT32_T_MAX) //Socket APIs cannot handle files > 2GB
        {
            Stringp errormsg = core->newStringUTF8( "buffer size bigger than 2GB" );
            toplevel->throwRangeError(kOutOfRangeError, errormsg);
        }

        bytes->set_position(0);
        unsigned char *data = mmfx_new_array( unsigned char, byteslen+1);
        bytes->GetByteArray().Read(data, (uint32_t) byteslen);

        struct sockaddr_in6 sockaddr6;
        sockaddr6 = address->toStruct();

        int result = VMPI_sendto( socket, data, byteslen, flags, (struct sockaddr *)&sockaddr6, sizeof sockaddr6 );

        if( result != -1 )
        {
            address->fromStruct( sockaddr6 );
        }

        return result;
    }

    int CSysSocketClass::setsockoptint(int socket, int level, int option_name, int option_value)
    {
        int value = option_value;
        int len   = sizeof( value );

        int result = VMPI_setsockopt( socket, level, option_name, &value, len );

        return result;
    }



    /*static*/ int CSysSocketClass::listen(ScriptObject*, int socket, int backlog)
    {
        return VMPI_listen( socket, backlog );
    }

    /*static*/ int CSysSocketClass::recv(ScriptObject* self, int socket, ByteArrayObject* bytes, int len, int flags)
    {
        Toplevel* toplevel = self->toplevel();

        if( !bytes )
        {
            toplevel->throwArgumentError(kNullArgumentError, "bytes");
        }

        uint32_t maxlen = (uint32_t)len;

        if(maxlen >= (uint32_t)INT32_T_MAX) //Socket APIs cannot handle files > 2GB
        {
            Stringp errormsg = self->core()->newStringUTF8( "buffer size bigger than 2GB" );
            toplevel->throwRangeError(kOutOfRangeError, errormsg);
        }

        if( len <= 0 )
        {
            //read 0 return 0
            return 0;
        }

        unsigned char *data = mmfx_new_array( unsigned char, len+1);

        int result = VMPI_recv( socket, data, len, flags );

        if( result > 0 )
        {
            bytes->GetByteArray().Write(data, (uint32_t) result);
            //bytes->set_position(0);
        }

        mmfx_delete_array( data );

        return result;
    }

    /*static*/ int CSysSocketClass::send(ScriptObject* self, int socket, ByteArrayObject* bytes, int flags, uint32_t buffer)
    {
        Toplevel* toplevel = self->toplevel();

        if( !bytes )
        {
            toplevel->throwArgumentError(kNullArgumentError, "bytes");
        }

        uint32_t byteslen = bytes->GetByteArray().GetLength();

        if( (buffer > 0) && (buffer < byteslen) )
        {
            byteslen = buffer;
        }

        if(byteslen >= (uint32_t)INT32_T_MAX) //Socket APIs cannot handle files > 2GB
        {
            Stringp errormsg = self->core()->newStringUTF8( "buffer size bigger than 2GB" );
            toplevel->throwRangeError(kOutOfRangeError, errormsg);
        }

        if( byteslen <= 0 )
        {
            //the bytearray is empty
            return 0;
        }

        bytes->set_position(0);
        unsigned char *data = mmfx_new_array( unsigned char, byteslen+1);
        bytes->GetByteArray().Read(data, (uint32_t) byteslen);

        int result = VMPI_send( socket, data, byteslen, flags );

        mmfx_delete_array( data );

        return result;
    }

    /*static*/ int CSysSocketClass::shutdown(ScriptObject*, int socket, int how)
    {
        return VMPI_shutdown( socket, how );
    }

    /*static*/ int CSysSocketClass::sockatmark(ScriptObject*, int s)
    {
        return VMPI_sockatmark( s );
    }

    /*static*/ int CSysSocketClass::socket(ScriptObject*, int domain, int type, int protocol)
    {
        return VMPI_socket( domain, type, protocol );
    }

    /*static*/ int CSysSocketClass::socketpair(ScriptObject* self, int domain, int type, int protocol, ArrayObject* sockets)
    {
        Toplevel* toplevel = self->toplevel();
        AvmCore* core = toplevel->core();

        if( !sockets )
        {
            toplevel->throwArgumentError(kNullArgumentError, "sockets");
        }

        int fd[2];
        int result = VMPI_socketpair( domain, type, protocol, fd );

        if( result != -1 )
        {
            sockets->setUintProperty( 0, core->intToAtom( fd[0] ) );
            sockets->setUintProperty( 1, core->intToAtom( fd[1] ) );
        }

        return result;
    }




    //sockaddr
    CsockaddrClass::CsockaddrClass(VTable *vtable)
        : ClassClosure(vtable)
    {
        createVanillaPrototype();
    }

    CsockaddrClass::~CsockaddrClass()
    {
        //nothing to destroy
    }

    void CsockaddrClass::dummy()
    {
        //does strictly nothing
    }


    CsockaddrObject::CsockaddrObject(VTable *vtable, ScriptObject *delegate)
        : ScriptObject(vtable, delegate)
    {}

    CsockaddrObject::~CsockaddrObject()
    {
        //nothing to destroy
    }

    void CsockaddrObject::dummy()
    {
        //does strictly nothing
    }

}
