/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "avmshell.h"

namespace avmshell
{

    CNetdbClass::CNetdbClass(VTable *cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    CNetdbClass::~CNetdbClass()
    {
        
    }


    int CNetdbClass::get_AI_PASSIVE() { return AI_PASSIVE; }
    int CNetdbClass::get_AI_CANONNAME() { return AI_CANONNAME; }
    int CNetdbClass::get_AI_NUMERICHOST() { return AI_NUMERICHOST; }
    int CNetdbClass::get_AI_NUMERICSERV() { return AI_NUMERICSERV; }
    int CNetdbClass::get_AI_V4MAPPED() { return AI_V4MAPPED; }
    int CNetdbClass::get_AI_ALL() { return AI_ALL; }
    int CNetdbClass::get_AI_ADDRCONFIG() { return AI_ADDRCONFIG; }

    /* TODO:
       define convert functions

       struct protoent* toProtoent( CprotoentObject* as3obj )
       CprotoentObject* fromProtoent( struct protoent* obj )
    */

    /*static*/ CprotoentObject* CNetdbClass::getprotobynumber(ScriptObject* self, int proto)
    {
        struct protoent *pp;

        pp = VMPI_getprotobynumber( proto );

        if( pp )
        {
            ShellToplevel* shelltop = (ShellToplevel*)self->toplevel();
            CprotoentClass *pc = shelltop->getShellClasses()->get_protoentClass();
            CprotoentObject *po = pc->constructObject();

            po->set_p_name( self->core()->newStringUTF8( pp->p_name ) );
            po->set_p_proto( pp->p_proto );

            Toplevel* toplevel = self->toplevel();
            ArrayObject *aliases = toplevel->arrayClass()->newArray();
            int count = 0;
            int i;
            for( i=0; pp->p_aliases[i] != NULL; ++i )
            {
                aliases->setUintProperty( count++, self->core()->newStringUTF8( pp->p_aliases[i] )->atom());
            }
            po->set_p_aliases( aliases );

            return po;
        }

        return NULL;
    }

    /*static*/ CprotoentObject* CNetdbClass::getprotoent(ScriptObject* self)
    {
        struct protoent *pp;

        pp = VMPI_getprotoent();

        if( pp )
        {
            ShellToplevel* shelltop = (ShellToplevel*)self->toplevel();
            CprotoentClass *pc = shelltop->getShellClasses()->get_protoentClass();
            CprotoentObject *po = pc->constructObject();

            po->set_p_name( self->core()->newStringUTF8( pp->p_name ) );
            po->set_p_proto( pp->p_proto );

            Toplevel* toplevel = self->toplevel();
            ArrayObject *aliases = toplevel->arrayClass()->newArray();
            int count = 0;
            int i;
            for( i=0; pp->p_aliases[i] != NULL; ++i )
            {
                aliases->setUintProperty( count++, self->core()->newStringUTF8( pp->p_aliases[i] )->atom());
            }
            po->set_p_aliases( aliases );

            return po;
        }

        return NULL;
    }

    /*static*/ ChostentObject* CNetdbClass::gethostent(ScriptObject* self)
    {
        struct hostent *hh;

        hh = VMPI_gethostent();

        if( hh )
        {
            ShellToplevel* shelltop = (ShellToplevel*)self->toplevel();
            ChostentClass *hc = shelltop->getShellClasses()->get_hostentClass();
            ChostentObject *ho = hc->constructObject();

            ho->set_h_name( self->core()->newStringUTF8( hh->h_name ) );
            
            Toplevel* toplevel = self->toplevel();
            ArrayObject *aliases = toplevel->arrayClass()->newArray();
            int count = 0;
            int i;
            for( i=0; hh->h_aliases[i] != NULL; ++i )
            {
                aliases->setUintProperty( count++, self->core()->newStringUTF8( hh->h_aliases[i] )->atom());
            }
            ho->set_h_aliases( aliases );

            ho->set_h_addrtype( hh->h_addrtype );
            ho->set_h_length( hh->h_length );

            ArrayObject *addrlist = toplevel->arrayClass()->newArray();
            count = 0;
            for( i=0; hh->h_addr_list[i] != NULL; ++i )
            {
                struct in_addr in;
                memcpy(&in.s_addr, hh->h_addr_list[i], sizeof (in.s_addr));
                addrlist->setUintProperty( count++, self->core()->newStringUTF8( inet_ntoa(in) )->atom());
            }
            ho->set_h_addr_list( addrlist );

            return ho;
        }

        return NULL;
    }





    ChostentClass::ChostentClass(VTable *vtable)
        : ClassClosure(vtable)
    {
        createVanillaPrototype();
    }

    ChostentClass::~ChostentClass()
    {
        //nothing to destroy
    }

    void ChostentClass::dummy()
    {
        //does strictly nothing
    }


    ChostentObject::ChostentObject(VTable *vtable, ScriptObject *delegate)
        : ScriptObject(vtable, delegate)
    {}

    ChostentObject::~ChostentObject()
    {
        //nothing to destroy
    }

    void ChostentObject::dummy()
    {
        //does strictly nothing
    }


    CprotoentClass::CprotoentClass(VTable *vtable)
        : ClassClosure(vtable)
    {
        createVanillaPrototype();
    }

    CprotoentClass::~CprotoentClass()
    {
        //nothing to destroy
    }

    void CprotoentClass::dummy()
    {
        //does strictly nothing
    }


    CprotoentObject::CprotoentObject(VTable *vtable, ScriptObject *delegate)
        : ScriptObject(vtable, delegate)
    {}

    CprotoentObject::~CprotoentObject()
    {
        //nothing to destroy
    }

    void CprotoentObject::dummy()
    {
        //does strictly nothing
    }

}
