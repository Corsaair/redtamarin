/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "avmshell.h"

namespace avmshell
{

    FileSystemClass::FileSystemClass(VTable *cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    FileSystemClass::~FileSystemClass()
    {
        
    }

    /*bool FileSystemClass::isWindowsStore()
    {
        #if AVMSYSTEM_WINDOWSSTOREAPP
        return true;
        #endif

        return false;
    }*/

    Stringp FileSystemClass::read(Stringp filename)
    {
        Toplevel* toplevel = this->toplevel();
        AvmCore* core = this->core();

        if (!filename) {
            toplevel->throwArgumentError(kNullArgumentError, "filename");
        }
        StUTF8String filenameUTF8(filename);
        File* fp = Platform::GetInstance()->createFile();
        if(!fp || !fp->open(filenameUTF8.c_str(), File::OPEN_READ))
        {
            if(fp)
            {
                Platform::GetInstance()->destroyFile(fp);
            }

            toplevel->throwError(kFileOpenError, filename);
        }

        int64_t fileSize = fp->size();
        if(fileSize >= (int64_t)INT32_T_MAX) //File APIs cannot handle files > 2GB
        {
            toplevel->throwRangeError(kOutOfRangeError, filename);
        }

        int len = (int)fileSize;

        // Avoid avmStackAlloc - the buffer can be large and the memory is non-pointer-containing,
        // but the GC will scan it conservatively.
        uint8_t* c = (uint8_t*)core->gc->Alloc(len+1);
        
        len = (int)fp->read(c, len); //need to force since the string creation functions expect an int
        c[len] = 0;

        fp->close();
        Platform::GetInstance()->destroyFile(fp);

        Stringp ret = NULL;

        if (len >= 3)
        {
            // UTF8 BOM
            if ((c[0] == 0xef) && (c[1] == 0xbb) && (c[2] == 0xbf))
            {
                ret = core->newStringUTF8((const char*)c + 3, len - 3);
            }
            else if ((c[0] == 0xfe) && (c[1] == 0xff))
            {
                //UTF-16 big endian
                c += 2;
                len = (len - 2) >> 1;
                ret = core->newStringEndianUTF16(/*littleEndian*/false, (wchar*)(void*)c, len);
            }
            else if ((c[0] == 0xff) && (c[1] == 0xfe))
            {
                //UTF-16 little endian
                c += 2;
                len = (len - 2) >> 1;
                ret = core->newStringEndianUTF16(/*littleEndian*/true, (wchar*)(void*)c, len);
            }
        }

        if (ret == NULL)
        {
            // Use newStringUTF8() with "strict" explicitly set to false to mimick old,
            // buggy behavior, where malformed UTF-8 sequences are stored as single characters.
            ret = core->newStringUTF8((const char*)c, len, false);
        }

        core->gc->Free(c);
        return ret;
    }
    
}
