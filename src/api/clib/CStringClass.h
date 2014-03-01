/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_CStringClass__
#define __avmshell_CStringClass__

namespace avmshell
{
	using namespace avmplus;

    class CStringClass : public ClassClosure
    {
    public:
        CStringClass(VTable* cvtable);
        ~CStringClass();

        //memccpy()
        //VMPI_memchr()
        //VMPI_memcmp()
        //VMPI_memcpy()
        //VMPI_memmove()
        //VMPI_memset()
        //stpcpy()
        //stpncpy()
        //VMPI_strcat() //AS3
        //VMPI_strchr() //AS3
        static int strcmp(ScriptObject* self, Stringp s1, Stringp s2);
        static int strcoll(ScriptObject* self, Stringp s1, Stringp s2);
        //strcoll_l()
        //VMPI_strcpy()
        //strcspn()
        //VMPI_strdup()
        static Stringp strerror(ScriptObject* self, int errnum);
        //strerror_l()
        //strerror_r()
        //static unsigned strlen(ScriptObject* self, Stringp str); //AS3
        //strmode() //AS3
        //VMPI_strncat() //AS3
        //VMPI_strncmp() //AS3
        //VMPI_strncpy()
        //strndup()
        //strnlen()
        //stroctal() //AS3
        //strpbrk() //AS3
        //VMPI_strrchr() //AS3
        //strsignal()
        //strsigno()
        static int strspn(ScriptObject* self, Stringp s1, Stringp s2);
        //VMPI_strstr() //AS3
        //strtok() //AS3
        //strtok_r()
        //strxfrm()
        //strxfrm_l()
        

        //DECLARE_SLOTS_CStringClass;
    };

}

#endif /* __avmshell_CStringClass__ */

