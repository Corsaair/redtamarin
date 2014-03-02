/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "avmshell.h"

namespace avmshell
{

    CDirentClass::CDirentClass(VTable *cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    CDirentClass::~CDirentClass()
    {
        
    }
    

    /*static*/ int CDirentClass::closedir(ScriptObject* self, CDIRObject* dirp)
    {
        Toplevel* toplevel = self->toplevel();

        if( !dirp )
        {
            toplevel->throwArgumentError(kNullArgumentError, "dirp");
        }

        return VMPI_closedir( dirp->read() );
    }

    /*static*/ int CDirentClass::dirfd(ScriptObject* self, CDIRObject* dirp)
    {
        Toplevel* toplevel = self->toplevel();

        if( !dirp )
        {
            toplevel->throwArgumentError(kNullArgumentError, "dirp");
        }

        return VMPI_dirfd( dirp->read() );
    }

    /*static*/ CDIRObject* CDirentClass::fdopendir(ScriptObject* self, int fd)
    {
        DIR *dir = VMPI_fdopendir( fd );

        if( dir )
        {
            ShellToplevel* shelltop = (ShellToplevel*)self->toplevel();
            CDIRClass *dirc = shelltop->getShellClasses()->get_DIRClass();
            CDIRObject *diro = dirc->constructObject();

            diro->write( dir );
            return diro;
        }
        
        return NULL;
    }

    /*static*/ CDIRObject* CDirentClass::opendir(ScriptObject* self, Stringp dirname)
    {
        Toplevel* toplevel = self->toplevel();

        if( !dirname )
        {
            toplevel->throwArgumentError(kNullArgumentError, "dirname");
        }

        StUTF8String dirnameUTF8(dirname);
        DIR *dir = VMPI_opendir( dirnameUTF8.c_str() );

        if( dir )
        {
            ShellToplevel* shelltop = (ShellToplevel*)self->toplevel();
            CDIRClass *dirc = shelltop->getShellClasses()->get_DIRClass();
            CDIRObject *diro = dirc->constructObject();

            diro->write( dir );
            return diro;
        }
        
        return NULL;
    }

    /*static*/ CdirentObject* CDirentClass::readdir(ScriptObject* self, CDIRObject* dirp)
    {
        Toplevel* toplevel = self->toplevel();

        if( !dirp )
        {
            toplevel->throwArgumentError(kNullArgumentError, "dirp");
        }

        dirent *entry = VMPI_readdir( dirp->read() );

        if( entry )
        {
            ShellToplevel* shelltop = (ShellToplevel*)self->toplevel();
            CdirentClass *direc = shelltop->getShellClasses()->get_direntClass();
            CdirentObject *direo = direc->constructObject();

            direo->write( entry );

            AvmCore *core = self->core();

            direo->set_d_ino( entry->d_ino );
            direo->set_d_name( core->newStringUTF8( entry->d_name ) );

            return direo;
        }

        return NULL;
    }

    /*static*/ void CDirentClass::rewinddir(ScriptObject* self, CDIRObject* dirp)
    {
        Toplevel* toplevel = self->toplevel();

        if( !dirp )
        {
            toplevel->throwArgumentError(kNullArgumentError, "dirp");
        }

        VMPI_rewinddir( dirp->read() );
    }

    /*static*/ void CDirentClass::seekdir(ScriptObject* self, CDIRObject* dirp, double loc)
    {
        Toplevel* toplevel = self->toplevel();

        if( !dirp )
        {
            toplevel->throwArgumentError(kNullArgumentError, "dirp");
        }

        VMPI_seekdir( dirp->read(), loc );
    }

    /*static*/ double CDirentClass::telldir(ScriptObject* self, CDIRObject* dirp)
    {
        Toplevel* toplevel = self->toplevel();

        if( !dirp )
        {
            toplevel->throwArgumentError(kNullArgumentError, "dirp");
        }

        return (double)VMPI_telldir( dirp->read() );
    }





    CDIRClass::CDIRClass(VTable *vtable)
        : ClassClosure(vtable)
    {
        createVanillaPrototype();
    }

    CDIRClass::~CDIRClass()
    {
        //nothing to destroy
    }

    void CDIRClass::dummy()
    {
        //does strictly nothing
    }


    CDIRObject::CDIRObject(VTable *vtable, ScriptObject *delegate)
        : ScriptObject(vtable, delegate)
    {}

    CDIRObject::~CDIRObject()
    {
        //nothing to destroy
    }

    DIR* CDIRObject::read()
    {
        return _directory;
    }

    void CDIRObject::write(DIR* value)
    {
        _directory = value;
    }




    CdirentClass::CdirentClass(VTable *vtable)
        : ClassClosure(vtable)
    {
        createVanillaPrototype();
    }

    CdirentClass::~CdirentClass()
    {
        //nothing to destroy
    }

    void CdirentClass::dummy()
    {
        //does strictly nothing
    }


    CdirentObject::CdirentObject(VTable *vtable, ScriptObject *delegate)
        : ScriptObject(vtable, delegate)
    {}

    CdirentObject::~CdirentObject()
    {
        //nothing to destroy
    }

    dirent* CdirentObject::read()
    {
        return _entry;
    }

    void CdirentObject::write(dirent* value)
    {
        _entry = value;
    }



}
