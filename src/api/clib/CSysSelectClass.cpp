/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "avmshell.h"

namespace avmshell
{

    CSysSelectClass::CSysSelectClass(VTable *cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    CSysSelectClass::~CSysSelectClass()
    {
        
    }


    int CSysSelectClass::get_FD_SETSIZE() { return FD_SETSIZE; }


    /*static*/ void CSysSelectClass::_avm_FD_CLR(ScriptObject* self, int fd, Cfd_setObject* fdsetp)
    {
        Toplevel* toplevel = self->toplevel();

        if( !fdsetp )
        {
            toplevel->throwArgumentError(kNullArgumentError, "fdsetp");
        }

        VMPI_FD_CLR( fd, &fdsetp->fds );
    }

    /*static*/ int CSysSelectClass::_avm_FD_ISSET(ScriptObject* self, int fd, Cfd_setObject* fdsetp)
    {
        Toplevel* toplevel = self->toplevel();

        if( !fdsetp )
        {
            toplevel->throwArgumentError(kNullArgumentError, "fdsetp");
        }
        
        int result = VMPI_FD_ISSET( fd, &fdsetp->fds );

        return result;
    }

    /*static*/ void CSysSelectClass::_avm_FD_SET(ScriptObject* self, int fd, Cfd_setObject* fdsetp)
    {
        Toplevel* toplevel = self->toplevel();

        if( !fdsetp )
        {
            toplevel->throwArgumentError(kNullArgumentError, "fdsetp");
        }
        
        VMPI_FD_SET( fd, &fdsetp->fds );
    }

    /*static*/ void CSysSelectClass::_avm_FD_ZERO(ScriptObject* self, Cfd_setObject* fdsetp)
    {
        Toplevel* toplevel = self->toplevel();

        if( !fdsetp )
        {
            toplevel->throwArgumentError(kNullArgumentError, "fdsetp");
        }

        VMPI_FD_ZERO( &fdsetp->fds );
    }



    /*static*/ int CSysSelectClass::select(ScriptObject* self, int nfds, Cfd_setObject* readfds, Cfd_setObject* writefds, Cfd_setObject* errorfds, CtimevalObject* timeout)
    {
        Toplevel* toplevel = self->toplevel();

        if( !timeout )
        {
            toplevel->throwArgumentError(kNullArgumentError, "timeout");
        }

		struct timeval tv;
    	tv = timeout->toStruct();

        int result = -1;
        
        if( !readfds && !writefds && !errorfds )
        {
        	result = VMPI_select( nfds, NULL, NULL, NULL, &tv );
        }
        else if( !writefds && !errorfds )
        {
        	result = VMPI_select( nfds, &readfds->fds, NULL, NULL, &tv );
        }
        else if( !errorfds )
        {
        	result = VMPI_select( nfds, &readfds->fds, &writefds->fds, NULL, &tv );
        }
        else if( !writefds )
        {
        	result = VMPI_select( nfds, &readfds->fds, NULL, &errorfds->fds, &tv );
        }
        else if( !readfds )
        {
        	result = VMPI_select( nfds, NULL, &writefds->fds, &errorfds->fds, &tv );
        }
        else if( !readfds && !writefds )
        {
        	result = VMPI_select( nfds, NULL, NULL, &errorfds->fds, &tv );
        }
        else if( !readfds && !errorfds )
        {
        	result = VMPI_select( nfds, NULL, &writefds->fds, NULL, &tv );
        }
        else
        {
            result = VMPI_select( nfds, &readfds->fds, &writefds->fds, &errorfds->fds, &tv );
        }


        if( result != -1 )
        {
            timeout->fromStruct( tv );
        }

        return result;
    }


    /*static*/ bool CSysSelectClass::isReadable(ScriptObject*, int nfds, CErrorObject* err)
    {
        int status;
        fd_set fds;
        struct timeval tv;

        VMPI_FD_ZERO( &fds );
        VMPI_FD_SET( nfds, &fds );
        tv.tv_sec  = 0;
        tv.tv_usec = 0;

        status = VMPI_select( nfds+1, &fds, NULL, NULL, &tv );

        if( status < 0 )
        {
        	//printf( "readable status = %i\n", status );
            if( err )
            {
                err->call_apply( status );
            }
        }

        return VMPI_FD_ISSET( nfds, &fds ) ? true: false;
    }

    /*static*/ bool CSysSelectClass::isWritable(ScriptObject*, int nfds, CErrorObject* err)
    {
        int status;
        fd_set fds;
        struct timeval tv;

        VMPI_FD_ZERO( &fds );
        VMPI_FD_SET( nfds, &fds );
        tv.tv_sec  = 0;
        tv.tv_usec = 0;

        status = VMPI_select( nfds+1, NULL, &fds, NULL, &tv );

        if( status < 0 )
        {
        	//printf( "writable status = %i\n", status );
            if( err )
            {
                err->call_apply( status );
            }
        }

        return VMPI_FD_ISSET( nfds, &fds ) ? true: false;
    }

    /*static*/ bool CSysSelectClass::isExceptional(ScriptObject*, int nfds, CErrorObject* err)
    {
        int status;
        fd_set fds;
        struct timeval tv;

        VMPI_FD_ZERO( &fds );
        VMPI_FD_SET( nfds, &fds );
        tv.tv_sec  = 0;
        tv.tv_usec = 0;

        status = VMPI_select( nfds+1, NULL, NULL, &fds, &tv );

        if( status < 0 )
        {
        	//printf( "exceptional status = %i\n", status );
            if( err )
            {
                err->call_apply( status );
            }
        }

        return VMPI_FD_ISSET( nfds, &fds ) ? true: false;
    }




    //timeval
    CtimevalClass::CtimevalClass(VTable *vtable)
        : ClassClosure(vtable)
    {
        createVanillaPrototype();
    }

    CtimevalClass::~CtimevalClass()
    {
        //nothing to destroy
    }

    void CtimevalClass::dummy()
    {
        //does strictly nothing
    }


    CtimevalObject::CtimevalObject(VTable *vtable, ScriptObject *delegate)
        : ScriptObject(vtable, delegate)
    {}

    CtimevalObject::~CtimevalObject()
    {
        //nothing to destroy
    }

    void CtimevalObject::fromStruct(struct timeval tv)
    {
        this->set_tv_sec( tv.tv_sec );
        this->set_tv_usec( tv.tv_usec );
    }

    struct timeval CtimevalObject::toStruct()
    {
         struct timeval tv;
         tv.tv_sec  = this->get_tv_sec();
         tv.tv_usec = this->get_tv_usec();

         return tv;
    }

    //fd_set
    Cfd_setClass::Cfd_setClass(VTable *vtable)
        : ClassClosure(vtable)
    {
        createVanillaPrototype();
    }

    Cfd_setClass::~Cfd_setClass()
    {
        //nothing to destroy
    }

    void Cfd_setClass::dummy()
    {
        //does strictly nothing
    }


    Cfd_setObject::Cfd_setObject(VTable *vtable, ScriptObject *delegate)
        : ScriptObject(vtable, delegate)
    {}

    Cfd_setObject::~Cfd_setObject()
    {
        //nothing to destroy
    }

    void Cfd_setObject::dummy()
    {
        //does strictly nothing
    }

}
