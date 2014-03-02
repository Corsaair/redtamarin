/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "avmshell.h"

namespace avmshell
{

    CStdioClass::CStdioClass(VTable *cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    CStdioClass::~CStdioClass()
    {
        
    }


    int CStdioClass::get_BUFSIZ() { return BUFSIZ; }

    int CStdioClass::get__IOFBF() { return _IOFBF; }

    int CStdioClass::get__IOLBF() { return _IOLBF; }

    int CStdioClass::get__IONBF() { return _IONBF; }

    int CStdioClass::get_SEEK_CUR() { return SEEK_CUR; }

    int CStdioClass::get_SEEK_END() { return SEEK_END; }

    int CStdioClass::get_SEEK_SET() { return SEEK_SET; }

    int CStdioClass::get_FILENAME_MAX() { return FILENAME_MAX; }

    int CStdioClass::get_FOPEN_MAX() { return FOPEN_MAX; }

    int CStdioClass::get_TMP_MAX() { return TMP_MAX; }

    int CStdioClass::get_EOF() { return EOF; }


    CFILEObject* CStdioClass::get_stdin()
    {
        ShellToplevel* shelltop = (ShellToplevel*)this->toplevel();
        CFILEClass *fc = shelltop->getShellClasses()->get_FILEClass();
        CFILEObject *fo = fc->constructObject();
        fo->write( stdin );

        return fo;
    }

    CFILEObject* CStdioClass::get_stdout()
    {
        ShellToplevel* shelltop = (ShellToplevel*)this->toplevel();
        CFILEClass *fc = shelltop->getShellClasses()->get_FILEClass();
        CFILEObject *fo = fc->constructObject();
        fo->write( stdout );

        return fo;
    }
    
    CFILEObject* CStdioClass::get_stderr()
    {
        ShellToplevel* shelltop = (ShellToplevel*)this->toplevel();
        CFILEClass *fc = shelltop->getShellClasses()->get_FILEClass();
        CFILEObject *fo = fc->constructObject();
        fo->write( stderr );

        return fo;
    }



    /*static*/ void CStdioClass::clearerr(ScriptObject* self, CFILEObject* stream)
    {
        Toplevel* toplevel = self->toplevel();

        if( !stream )
        {
            toplevel->throwArgumentError(kNullArgumentError, "stream");
        }

        VMPI_clearerr( stream->read() );
    }

    /*static*/ int CStdioClass::fclose(ScriptObject* self, CFILEObject* stream)
    {
        Toplevel* toplevel = self->toplevel();

        if( !stream )
        {
            toplevel->throwArgumentError(kNullArgumentError, "stream");
        }

        return VMPI_fclose( stream->read() );
    }

    /*static*/ CFILEObject* CStdioClass::fdopen(ScriptObject* self, int fildes, Stringp mode)
    {
        Toplevel* toplevel = self->toplevel();
        
        if( !mode )
        {
            toplevel->throwArgumentError(kNullArgumentError, "mode");
        }

        StUTF8String modeUTF8(mode);
        FILE *f = VMPI_fdopen( fildes, modeUTF8.c_str() );

        if( f )
        {
            ShellToplevel* shelltop = (ShellToplevel*)self->toplevel();
            CFILEClass *fc = shelltop->getShellClasses()->get_FILEClass();
            CFILEObject *fo = fc->constructObject();

            fo->write( f );
            return fo;
        }
        
        return NULL;
    }

    /*static*/ int CStdioClass::feof(ScriptObject* self, CFILEObject* stream)
    {
        Toplevel* toplevel = self->toplevel();

        if( !stream )
        {
            toplevel->throwArgumentError(kNullArgumentError, "stream");
        }

        return VMPI_feof( stream->read() );
    }

    /*static*/ int CStdioClass::ferror(ScriptObject* self, CFILEObject* stream)
    {
        Toplevel* toplevel = self->toplevel();

        if( !stream )
        {
            toplevel->throwArgumentError(kNullArgumentError, "stream");
        }

        return VMPI_ferror( stream->read() );
    }

    /*static*/ int CStdioClass::fflush(ScriptObject* self, CFILEObject* stream)
    {
        Toplevel* toplevel = self->toplevel();

        if( !stream )
        {
            toplevel->throwArgumentError(kNullArgumentError, "stream");
        }

        return VMPI_fflush( stream->read() );
    }

    /*static*/ int CStdioClass::fgetc(ScriptObject* self, CFILEObject* stream)
    {
        Toplevel* toplevel = self->toplevel();

        if( !stream )
        {
            toplevel->throwArgumentError(kNullArgumentError, "stream");
        }

        return VMPI_fgetc( stream->read() );
    }

    /*static*/ int CStdioClass::fgetpos(ScriptObject* self, CFILEObject* stream, Cfpos_tObject* pos)
    {
        Toplevel* toplevel = self->toplevel();

        if( !stream )
        {
            toplevel->throwArgumentError(kNullArgumentError, "stream");
        }

        if( !pos )
        {
            toplevel->throwArgumentError(kNullArgumentError, "pos");
        }

        fpos_t newpos;
        int result = VMPI_fgetpos( stream->read(), &newpos );
        pos->write( newpos );

        return result;
    }

    /*static*/ Stringp CStdioClass::fgets(ScriptObject* self, int n, CFILEObject* stream)
    {
        Toplevel* toplevel = self->toplevel();

        if( !n )
        {
            toplevel->throwArgumentError(kNullArgumentError, "n");
        }

        if( !stream )
        {
            toplevel->throwArgumentError(kNullArgumentError, "stream");
        }

        char *s = new char[n];
        char *str = VMPI_fgets( s, n, stream->read() );

        if( str )
        {
            AvmCore* core = self->core();
            return core->newStringUTF8( str );
        }

        return NULL;
    }

    /*static*/ int CStdioClass::fileno(ScriptObject* self, CFILEObject* stream)
    {
        Toplevel* toplevel = self->toplevel();

        if( !stream )
        {
            toplevel->throwArgumentError(kNullArgumentError, "stream");
        }

        return VMPI_fileno( stream->read() );
    }

    /*static*/ void CStdioClass::flockfile(ScriptObject* self, CFILEObject* file)
    {
        Toplevel* toplevel = self->toplevel();

        if( !file )
        {
            toplevel->throwArgumentError(kNullArgumentError, "file");
        }

        VMPI_flockfile( file->read() );
    }


    /*static*/ CFILEObject* CStdioClass::fopen(ScriptObject* self, Stringp pathname, Stringp mode)
    {
        Toplevel* toplevel = self->toplevel();

        if( !pathname )
        {
            toplevel->throwArgumentError(kNullArgumentError, "pathname");
        }
        
        if( !mode )
        {
            toplevel->throwArgumentError(kNullArgumentError, "mode");
        }

        StUTF8String pathnameUTF8(pathname);
        StUTF8String modeUTF8(mode);
        FILE *f = VMPI_fopen( pathnameUTF8.c_str(), modeUTF8.c_str() );

        if( f )
        {
            ShellToplevel* shelltop = (ShellToplevel*)self->toplevel();
            CFILEClass *fc = shelltop->getShellClasses()->get_FILEClass();
            CFILEObject *fo = fc->constructObject();

            fo->write( f );
            return fo;
        }
        
        return NULL;
    }

    /*static*/ int CStdioClass::fputc(ScriptObject* self, int c, CFILEObject* stream)
    {
        Toplevel* toplevel = self->toplevel();
        
        if( !stream )
        {
            toplevel->throwArgumentError(kNullArgumentError, "stream");
        }

        return VMPI_fputc( c, stream->read() );
    }

    /*static*/ int CStdioClass::fputs(ScriptObject* self, Stringp s, CFILEObject* stream)
    {
        Toplevel* toplevel = self->toplevel();

        if( !s )
        {
            toplevel->throwArgumentError(kNullArgumentError, "s");
        }
        
        if( !stream )
        {
            toplevel->throwArgumentError(kNullArgumentError, "stream");
        }

        StUTF8String sUTF8(s);
        return VMPI_fputs( sUTF8.c_str(), stream->read() );
    }

    /*static*/ int CStdioClass::fread(ScriptObject* self, ByteArrayObject* bytes, int nitems, CFILEObject* stream)
    {
        Toplevel* toplevel = self->toplevel();

        if( !bytes )
        {
            toplevel->throwArgumentError(kNullArgumentError, "bytes");
        }
        
        if( !stream )
        {
            toplevel->throwArgumentError(kNullArgumentError, "stream");
        }
        
        if( nitems <= 0 )
        {
            return 0;
        }

        int64_t buffersize = (1 * nitems); //we read every 1 byte

        if( (uint64_t)buffersize >= UINT32_T_MAX ) //ByteArray APIs cannot handle files > 4GB
        {
            Stringp errormsg = self->core()->newStringUTF8( "buffer size bigger than 4GB" );
            toplevel->throwRangeError(kOutOfRangeError, errormsg);
        }

        uint32_t readsize = (uint32_t) buffersize;
        unsigned char *buffer = mmfx_new_array( unsigned char, readsize+1);

        int read = VMPI_fread( buffer, 1, nitems, stream->read() );
        
        if( read > 0 )
        {
            bytes->GetByteArray().Write(buffer, (uint32_t) read);
            bytes->set_position(0);
        }

        mmfx_delete_array( buffer );

        return read;
    }

    /*static*/ CFILEObject* CStdioClass::freopen(ScriptObject* self, Stringp pathname, Stringp mode, CFILEObject* stream)
    {
        Toplevel* toplevel = self->toplevel();

        if( !pathname )
        {
            toplevel->throwArgumentError(kNullArgumentError, "pathname");
        }
        
        if( !mode )
        {
            toplevel->throwArgumentError(kNullArgumentError, "mode");
        }

        if( !stream )
        {
            toplevel->throwArgumentError(kNullArgumentError, "stream");
        }

        StUTF8String pathnameUTF8(pathname);
        StUTF8String modeUTF8(mode);
        FILE *f = VMPI_freopen( pathnameUTF8.c_str(), modeUTF8.c_str(), stream->read() );

        if( f )
        {
            ShellToplevel* shelltop = (ShellToplevel*)self->toplevel();
            CFILEClass *fc = shelltop->getShellClasses()->get_FILEClass();
            CFILEObject *fo = fc->constructObject();

            fo->write( f );
            return fo;
        }
        
        return NULL;
    }

    /*static*/ int CStdioClass::fseek(ScriptObject* self, CFILEObject* stream, double offset, int whence)
    {
        Toplevel* toplevel = self->toplevel();

        if( !stream )
        {
            toplevel->throwArgumentError(kNullArgumentError, "stream");
        }

        return VMPI_fseek( stream->read(), (long) offset, whence );
    }

    /*static*/ int CStdioClass::fsetpos(ScriptObject* self, CFILEObject* stream, Cfpos_tObject* pos)
    {
        Toplevel* toplevel = self->toplevel();

        if( !stream )
        {
            toplevel->throwArgumentError(kNullArgumentError, "stream");
        }

        if( !pos )
        {
            toplevel->throwArgumentError(kNullArgumentError, "pos");
        }

        fpos_t oldpos = pos->read();
        return VMPI_fsetpos( stream->read(), &oldpos );
    }

    /*static*/ double CStdioClass::ftell(ScriptObject* self, CFILEObject* stream)
    {
        Toplevel* toplevel = self->toplevel();

        if( !stream )
        {
            toplevel->throwArgumentError(kNullArgumentError, "stream");
        }

        return VMPI_ftell( stream->read() );
    }

    /*static*/ int CStdioClass::ftrylockfile(ScriptObject* self, CFILEObject* file)
    {
        Toplevel* toplevel = self->toplevel();

        if( !file )
        {
            toplevel->throwArgumentError(kNullArgumentError, "file");
        }

        return VMPI_ftrylockfile( file->read() );
    }

    /*static*/ void CStdioClass::funlockfile(ScriptObject* self, CFILEObject* file)
    {
        Toplevel* toplevel = self->toplevel();

        if( !file )
        {
            toplevel->throwArgumentError(kNullArgumentError, "file");
        }

        VMPI_funlockfile( file->read() );
    }

    /*static*/ int CStdioClass::fwrite(ScriptObject* self, ByteArrayObject* bytes, int nitems, CFILEObject* stream)
    {
        Toplevel* toplevel = self->toplevel();

        if( !bytes )
        {
            toplevel->throwArgumentError(kNullArgumentError, "bytes");
        }
        
        if( !stream )
        {
            toplevel->throwArgumentError(kNullArgumentError, "stream");
        }
        
        if( nitems <= 0 )
        {
            return 0;
        }

        int64_t buffersize = (1 * nitems); //we write every 1 byte
        uint32_t byteslen = bytes->GetByteArray().GetLength();

        if( (uint64_t)buffersize >= UINT32_T_MAX ) //ByteArray APIs cannot handle files > 4GB
        {
            Stringp errormsg = self->core()->newStringUTF8( "buffer size bigger than 4GB" );
            toplevel->throwRangeError(kOutOfRangeError, errormsg);
        }

        if( byteslen <= 0 )
        {
            //the bytearray is empty
            return 0;
        }

        uint32_t available = byteslen - bytes->GetByteArray().GetPosition();

        if( available == 0 )
        {
            //the bytearray position is at the end
            return 0;
        }

        uint32_t writesize;

        if( available < (uint32_t) buffersize )
        {
            writesize = (uint32_t) available;
        }
        else if( available >= (uint32_t) buffersize )
        {
            writesize = (uint32_t) buffersize;
        }

        unsigned char *buffer = mmfx_new_array( unsigned char, writesize+1);
        bytes->GetByteArray().Read(buffer, (uint32_t) writesize);
        int writeitem = (int) writesize;

        int write = VMPI_fwrite( buffer, 1, writeitem, stream->read() );
        
        mmfx_delete_array( buffer );

        return write;
    }

    /*static*/ int CStdioClass::getc(ScriptObject* self, CFILEObject* stream)
    {
        Toplevel* toplevel = self->toplevel();

        if( !stream )
        {
            toplevel->throwArgumentError(kNullArgumentError, "stream");
        }

        return VMPI_getc( stream->read() );
    }

    /*static*/ int CStdioClass::getchar(ScriptObject*)
    {
        return VMPI_getchar();
    }

    int CStdioClass::_getc_unlocked(CFILEObject* stream)
    {
        if( !stream )
        {
            toplevel()->throwArgumentError(kNullArgumentError, "stream");
        }

        return VMPI_getc_unlocked( stream->read() );
    }

    int CStdioClass::_getchar_unlocked()
    {
        return VMPI_getchar_unlocked();
    }

    /*static*/ int CStdioClass::pclose(ScriptObject* self, CFILEObject* stream)
    {
        Toplevel* toplevel = self->toplevel();

        if( !stream )
        {
            toplevel->throwArgumentError(kNullArgumentError, "stream");
        }

        return VMPI_pclose( stream->read() );
    }


    /*static*/ void CStdioClass::perror(ScriptObject* self, Stringp s)
    {
        Toplevel* toplevel = self->toplevel();
        
        if( !s )
        {
            toplevel->throwArgumentError(kNullArgumentError, "s");
        }

        StUTF8String sUTF8(s);
        VMPI_perror( sUTF8.c_str() );
    }

    /*static*/ CFILEObject* CStdioClass::popen(ScriptObject* self, Stringp command, Stringp mode)
    {
        Toplevel* toplevel = self->toplevel();

        if( !command )
        {
            toplevel->throwArgumentError(kNullArgumentError, "command");
        }

        if( !mode )
        {
            toplevel->throwArgumentError(kNullArgumentError, "mode");
        }

        StUTF8String commandUTF8(command);
        StUTF8String modeUTF8(mode);
        FILE* f = VMPI_popen( commandUTF8.c_str(), modeUTF8.c_str() );

        if( f )
        {
            ShellToplevel* shelltop = (ShellToplevel*)self->toplevel();
            CFILEClass *fc = shelltop->getShellClasses()->get_FILEClass();
            CFILEObject *fo = fc->constructObject();
            
            fo->write( f );
            return fo;
        }
        
        return NULL;
    }





    /*static*/ int CStdioClass::rename(ScriptObject* self, Stringp oldname, Stringp newname)
    {
        Toplevel* toplevel = self->toplevel();
        
        if (!oldname) {
            toplevel->throwArgumentError(kNullArgumentError, "oldname");
        }
        
        if (!newname) {
            toplevel->throwArgumentError(kNullArgumentError, "newname");
        }
        
        StUTF8String oldnameUTF8(oldname);
        StUTF8String newnameUTF8(newname);
        return VMPI_rename(oldnameUTF8.c_str(), newnameUTF8.c_str());
    }

    /*static*/ void CStdioClass::rewind(ScriptObject* self, CFILEObject* stream)
    {
        Toplevel* toplevel = self->toplevel();

        if (!stream) {
            toplevel->throwArgumentError(kNullArgumentError, "stream");
        }

        VMPI_rewind( stream->read() );
    }




    CFILEClass::CFILEClass(VTable *vtable)
        : ClassClosure(vtable)
    {
        createVanillaPrototype();
    }

    CFILEClass::~CFILEClass()
    {
        //nothing to destroy
    }

    void CFILEClass::dummy()
    {
        //does strictly nothing
    }


    CFILEObject::CFILEObject(VTable *vtable, ScriptObject *delegate)
        : ScriptObject(vtable, delegate)
    {}

    CFILEObject::~CFILEObject()
    {
        //nothing to destroy
    }

    FILE* CFILEObject::read()
    {
        /*call_dummyTestRead();*/
        return _file;
    }

    void CFILEObject::write(FILE* value)
    {
        /*call_dummyTestWrite();*/
        _file = value;
    }


    Cfpos_tClass::Cfpos_tClass(VTable *vtable)
        : ClassClosure(vtable)
    {
        createVanillaPrototype();
    }

    Cfpos_tClass::~Cfpos_tClass()
    {
        //nothing to destroy
    }

    void Cfpos_tClass::dummy()
    {
        //does strictly nothing
    }

    Cfpos_tObject::Cfpos_tObject(VTable *vtable, ScriptObject *delegate)
        : ScriptObject(vtable, delegate)
    {}

    Cfpos_tObject::~Cfpos_tObject()
    {
        //nothing to destroy
    }

    fpos_t Cfpos_tObject::read()
    {
        return _pos;
    }

    void Cfpos_tObject::write(fpos_t value)
    {
        _pos = value;
    }








    /* old stuff */

    int CStdioClass::get_PATH_MAX()
    {
        return PATH_MAX;
    }

    int CStdioClass::get_NONBLOCKING_DISABLE()
    {
        return NONBLOCKING_DISABLE;
    }

    int CStdioClass::get_NONBLOCKING_ENABLE()
    {
        return NONBLOCKING_ENABLE;
    }

    /*int CStdioClass::get_O_TEXT()
    {
        return O_TEXT;
    }*/
    
    /*int CStdioClass::get_O_BINARY()
    {
        return O_BINARY;
    }*/

    


    int CStdioClass::remove(Stringp filename)
    {
        if (!filename) {
            toplevel()->throwArgumentError(kNullArgumentError, "filename");
        }

        StUTF8String filenameUTF8(filename);
        return VMPI_remove(filenameUTF8.c_str());
    }
    



    void CStdioClass::con_stream_mode(int state)
    {
        VMPI_con_stream_mode( state );
    }

    void CStdioClass::con_trans_mode(int state)
    {
        VMPI_con_trans_mode( state );
    }

    /*int CStdioClass::kbhit()
    {
        return VMPI_kbhit();
    }*/


}
