/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_CStdlibClass__
#define __avmshell_CStdlibClass__

namespace avmshell
{
    using namespace avmplus;

    class CStdlibClass : public ClassClosure
    {
    public:
        CStdlibClass(VTable* cvtable);
        ~CStdlibClass();

        int get_EXIT_SUCCESS();
        int get_EXIT_FAILURE();
        int get_RAND_MAX();
        int get_MB_CUR_MAX();

        //_Exit()
        //a641()
        //abort() //AS3
        //abs() //AS3
        //atexit() //AS3
        static double atof(ScriptObject* self, Stringp str);
        static int atoi(ScriptObject* self, Stringp str);
        static double atol(ScriptObject* self, Stringp str);
        //atoll() //AS3
        //bsearch()
        //calloc()
        static Cdiv_tObject* div(ScriptObject* self, int numer, int denom);
        //drand48()
        //erand48()
        //exit() //AS3
        //VMPI_free()
        static Stringp getenv(ScriptObject* self, Stringp name);
        //getsubopt()
        //grantpt()
        //initstate()
        //jrand48()
        //l64a()
        //labs() //AS3
        //lcong48()
        static Cldiv_tObject* ldiv(ScriptObject* self, double numer, double denom);
        //llabs() //AS3
        static Clldiv_tObject* lldiv(ScriptObject* self, double numer, double denom);
        //lrand48()
        //VMPI_malloc()
        static int mblen(ScriptObject* self, Stringp s, int i);
        //mbstowcs()
        //mbtowc()
        static Stringp mkdtemp(ScriptObject* self, Stringp templ);
        static int mkstemp(ScriptObject* self, Stringp templ);
        //mrand48()
        //nrand48()
        //posix_memalign()
        //posix_openpt()
        //ptsname()
        static int putenv(ScriptObject* self, Stringp name);
        //qsort()
        static int rand(ScriptObject*);
        //rand_r()
        //random()
        //realloc()
        static Stringp realpath(ScriptObject* self, Stringp path);
        //seed48()
        static int setenv(ScriptObject* self, Stringp name, Stringp value, bool overwrite);
        //setkey()
        //setstate()
        static void srand(ScriptObject*, unsigned seed);
        //srand48()
        //srandom()
        //strtod() //AS3
        //strtof() //AS3
        //VMPI_strtol() //AS3
        //strtold() //AS3
        //strtoll() //AS3
        //strtoul() //AS3
        //strtoull() //AS3
        static int system(ScriptObject*, Stringp command);
        //unlockpt()
        static int unsetenv(ScriptObject* self, Stringp name);
        //wcstombs()
        //wctomb()

        DECLARE_SLOTS_CStdlibClass;
    };


    class Cdiv_tClass : public ClassClosure
    {
    public:
        Cdiv_tClass(VTable* vtable);
        ~Cdiv_tClass();

        void dummy();

    private:
        DECLARE_SLOTS_Cdiv_tClass;
    };

    class Cdiv_tObject : public ScriptObject
    {
    public:
        Cdiv_tObject(VTable *vtable, ScriptObject *delegate);
        ~Cdiv_tObject();

        void dummy();

    private:
        DECLARE_SLOTS_Cdiv_tObject;
    };

    class Cldiv_tClass : public ClassClosure
    {
    public:
        Cldiv_tClass(VTable* vtable);
        ~Cldiv_tClass();

        void dummy();

    private:
        DECLARE_SLOTS_Cldiv_tClass;
    };

    class Cldiv_tObject : public ScriptObject
    {
    public:
        Cldiv_tObject(VTable *vtable, ScriptObject *delegate);
        ~Cldiv_tObject();

        void dummy();

    private:
        DECLARE_SLOTS_Cldiv_tObject;
    };

    class Clldiv_tClass : public ClassClosure
    {
    public:
        Clldiv_tClass(VTable* vtable);
        ~Clldiv_tClass();

        void dummy();

    private:
        DECLARE_SLOTS_Clldiv_tClass;
    };

    class Clldiv_tObject : public ScriptObject
    {
    public:
        Clldiv_tObject(VTable *vtable, ScriptObject *delegate);
        ~Clldiv_tObject();

        void dummy();

    private:
        DECLARE_SLOTS_Clldiv_tObject;
    };

}

#endif /* __avmshell_CStdlibClass__ */

