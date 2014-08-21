/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "avmshell.h"

namespace avmshell
{

    CSysStatClass::CSysStatClass(VTable *cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    CSysStatClass::~CSysStatClass()
    {
        
    }

    int CSysStatClass::mkdir(Stringp path, int mode)
    {
        if (!path) {
            toplevel()->throwArgumentError(kNullArgumentError, "path");
        }

        #ifdef AVMSYSTEM_WIN32
            StUTF16String pathUTF16(path);
            return VMPI_mkdir16( pathUTF16.c_str(), mode );
        #else
            StUTF8String pathUTF8(path);
            return VMPI_mkdir( pathUTF8.c_str(), mode );
        #endif
    }






    /*static*/ int CSysStatClass::chmod(ScriptObject* self, Stringp path, int mode)
    {
        Toplevel* toplevel = self->toplevel();

        if (!path) {
            toplevel->throwArgumentError(kNullArgumentError, "path");
        }

        #ifdef AVMSYSTEM_WIN32
            StUTF16String pathUTF16(path);
            return VMPI_chmod16( pathUTF16.c_str(), mode );
        #else
            StUTF8String pathUTF8(path);
            return VMPI_chmod( pathUTF8.c_str(), mode );
        #endif
    }

    /*static*/ int CSysStatClass::fstat(ScriptObject* self, int fildes, CStatusObject* buf)
    {
        Toplevel* toplevel = self->toplevel();

        if (!buf) {
            toplevel->throwArgumentError(kNullArgumentError, "buf");
        }

        struct stat statbuf;
        int result = VMPI_fstat( fildes, &statbuf );

        if( result != -1 )
        {
            buf->set_st_dev( statbuf.st_dev );
            buf->set_st_ino( statbuf.st_ino );
            buf->set_st_mode( statbuf.st_mode );
            buf->set_st_nlink( statbuf.st_nlink );
            buf->set_st_uid( statbuf.st_uid );
            buf->set_st_gid( statbuf.st_gid );
            buf->set_st_rdev( statbuf.st_rdev );
            buf->set_st_size( (double) statbuf.st_size );
            buf->set_st_atime( (double) statbuf.st_atime );
            buf->set_st_mtime( (double) statbuf.st_mtime );
            buf->set_st_ctime( (double) statbuf.st_ctime );
        }

        return result;
    }

    /*static*/ int CSysStatClass::stat(ScriptObject* self, Stringp path, CStatusObject* buf)
    {
        Toplevel* toplevel = self->toplevel();

        if (!path) {
            toplevel->throwArgumentError(kNullArgumentError, "path");
        }

        if (!buf) {
            toplevel->throwArgumentError(kNullArgumentError, "buf");
        }

        struct stat statbuf;

        #ifdef AVMSYSTEM_WIN32
            StUTF16String pathUTF16(path);
            int result = VMPI_stat16( pathUTF16.c_str(), &statbuf );
        #else
            StUTF8String pathUTF8(path);
            int result = VMPI_stat( pathUTF8.c_str(), &statbuf );
        #endif

        if( result != -1 )
        {
            buf->set_st_dev( statbuf.st_dev );
            buf->set_st_ino( statbuf.st_ino );
            buf->set_st_mode( statbuf.st_mode );
            buf->set_st_nlink( statbuf.st_nlink );
            buf->set_st_uid( statbuf.st_uid );
            buf->set_st_gid( statbuf.st_gid );
            buf->set_st_rdev( statbuf.st_rdev );
            buf->set_st_size( (double) statbuf.st_size );
            buf->set_st_atime( (double) statbuf.st_atime );
            buf->set_st_mtime( (double) statbuf.st_mtime );
            buf->set_st_ctime( (double) statbuf.st_ctime );
        }

        return result;
    }

    /*static*/ int CSysStatClass::umask(ScriptObject*, int cmask)
    {
        return VMPI_umask( cmask );
    }



    CStatusClass::CStatusClass(VTable *vtable)
        : ClassClosure(vtable)
    {
        createVanillaPrototype();
    }

    CStatusClass::~CStatusClass()
    {
        //nothing to destroy
    }

    void CStatusClass::dummy()
    {
        //does strictly nothing
    }


    CStatusObject::CStatusObject(VTable *vtable, ScriptObject *delegate)
        : ScriptObject(vtable, delegate)
    {}

    CStatusObject::~CStatusObject()
    {
        //nothing to destroy
    }

    void CStatusObject::dummy()
    {
        //does strictly nothing
    }

}
