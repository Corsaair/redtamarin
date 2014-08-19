/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_CStdioClass__
#define __avmshell_CStdioClass__

namespace avmshell
{
    using namespace avmplus;

    class CStdioClass : public ClassClosure
    {
    public:
        CStdioClass(VTable* cvtable);
        ~CStdioClass();

        int get_BUFSIZ();
        int get__IOFBF();
        int get__IOLBF();
        int get__IONBF();
        int get_SEEK_CUR();
        int get_SEEK_END();
        int get_SEEK_SET();
        int get_FILENAME_MAX();
        int get_FOPEN_MAX();
        int get_TMP_MAX();
        int get_EOF();

        CFILEObject* get_stdin();
        CFILEObject* get_stdout();
        CFILEObject* get_stderr();

        int _getc(CFILEObject* stream);
        int _getc_unlocked(CFILEObject* stream);
        int _getchar_unlocked();
        
        /* total=65, supported=35, not_supported=30 */
        static void clearerr(ScriptObject* self, CFILEObject* stream);
        //ctermid()
        //dprintf()
        static int fclose(ScriptObject* self, CFILEObject* stream);
        static CFILEObject* fdopen(ScriptObject* self, int fildes, Stringp mode);
        static int feof(ScriptObject* self, CFILEObject* stream);
        static int ferror(ScriptObject* self, CFILEObject* stream);
        static int fflush(ScriptObject* self, CFILEObject* stream);
        static int fgetc(ScriptObject* self, CFILEObject* stream);
        static int fgetpos(ScriptObject* self, CFILEObject* stream, Cfpos_tObject* pos);
        static Stringp fgets(ScriptObject* self, int n, CFILEObject* stream);
        static int fileno(ScriptObject* self, CFILEObject* stream);
        static void flockfile(ScriptObject* self, CFILEObject* file);
        static CFILEObject* fopen(ScriptObject* self, Stringp pathname, Stringp mode);
        //fprint()
        static int fputc(ScriptObject* self, int c, CFILEObject* stream);
        static int fputs(ScriptObject* self, Stringp s, CFILEObject* stream);
        static int fread(ScriptObject* self, ByteArrayObject* bytes, int nitems, CFILEObject* stream);
        static CFILEObject* freopen(ScriptObject* self, Stringp pathname, Stringp mode, CFILEObject* stream);
        //fscanf()
        static int fseek(ScriptObject* self, CFILEObject* stream, double offset, int whence);
        //fseeko()
        static int fsetpos(ScriptObject* self, CFILEObject* stream, Cfpos_tObject* pos);
        static double ftell(ScriptObject* self, CFILEObject* stream);
        //ftello()
        static int ftrylockfile(ScriptObject* self, CFILEObject* file);
        static void funlockfile(ScriptObject* self, CFILEObject* file);
        static int fwrite(ScriptObject* self, ByteArrayObject* bytes, int nitems, CFILEObject* stream);
        //getc()
        static int getchar(ScriptObject*);
        //getc_unlocked()
        //getchar_unlocked()
        //getdelim()
        //getline()
        //gets()
        //open_memstream()
        static int pclose(ScriptObject* self, CFILEObject* stream);
        static void perror(ScriptObject* self, Stringp s);
        static CFILEObject* popen(ScriptObject* self, Stringp command, Stringp mode);
        //printf()
        //static int putc(ScriptObject* self, int c, CFILEObject* stream);
        //static int putchar(ScriptObject* self, int c);
        //putc_unlocked()
        //putchar_unlocked()
        //static int puts(ScriptObject* self, Stringp s);
        static int remove(ScriptObject* self, Stringp path);
        static int rename(ScriptObject* self, Stringp oldname, Stringp newname);
        //renameat()
        static void rewind(ScriptObject* self, CFILEObject* stream);
        //scanf()
        //setbuf()
        //static int setvbuf(ScriptObject* self, CFILEObject* stream, int type, int size);
        //snprintf()
        //sprintf()
        //sscanf()
        //tempnam()
        //static CFILEObject* tmpfile(ScriptObject* self);
        //static Stringp tmpnam(ScriptObject* self);
        //static int ungetc(ScriptObject* self, int c, CFILEObject* stream);
        //vdprintf()
        //vfscanf()
        //vprintf()
        //vscanf()
        //vsnprintf()
        //vsprintf()
        //vsscanf()
        

        /* old stuff */
        //int get_PATH_MAX();
        //int get_NONBLOCKING_DISABLE();
        //int get_NONBLOCKING_ENABLE();
        //int get_O_TEXT();
        //int get_O_BINARY();

        //int remove(Stringp filename);
        //int rename(Stringp oldname, Stringp newname);
        //void con_stream_mode(int state);
        //void con_trans_mode(int state);
        //int kbhit();


        DECLARE_SLOTS_CStdioClass;
    };

    class CFILEClass : public ClassClosure
    {
    public:
        CFILEClass(VTable* vtable);
        ~CFILEClass();

        void dummy();

    private:
        DECLARE_SLOTS_CFILEClass;
    };

    class CFILEObject : public ScriptObject
    {
    public:
        CFILEObject(VTable *vtable, ScriptObject *delegate);
        ~CFILEObject();

        FILE* read();
        void write(FILE* value);

    private:
        FILE* _file;

        DECLARE_SLOTS_CFILEObject;
    };

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



}

#endif /* __avmshell_CStdioClass__ */

