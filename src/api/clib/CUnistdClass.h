/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_CUnistdClass__
#define __avmshell_CUnistdClass__

namespace avmshell
{
    using namespace avmplus;

    class CUnistdClass : public ClassClosure
    {
    public:
        CUnistdClass(VTable* cvtable);
        ~CUnistdClass();

        int get_F_OK();
        int get_X_OK();
        int get_W_OK();
        int get_R_OK();
        

        static int access(ScriptObject* self, Stringp path, int mode);
        //alarm()
        static int chdir(ScriptObject* self, Stringp path);
        //chown()
        static int close(ScriptObject*, int fildes);
        //confstr()
        //crypt()
        static int dup(ScriptObject*, int fildes);
        static int dup2(ScriptObject*, int fildes, int fildes2);
        //_exit()
        //encrypt()
        static int execl(ScriptObject* self, Stringp path, Atom* argv, int argc);
        static int execle(ScriptObject* self, Stringp path, Atom* argv, int argc);
        static int execlp(ScriptObject* self, Stringp file, Atom* argv, int argc);
        static int execv(ScriptObject* self, Stringp path, ArrayObject* argv);
        static int execve(ScriptObject* self, Stringp path, ArrayObject* argv, ArrayObject* envp);
        static int execvp(ScriptObject* self, Stringp file, ArrayObject* argv);
        //faccessat()
        //fchdir()
        //fchown()
        //fchownat()
        //fdatasync()
        //fexecve()
        //static int fork();
        //fpathconf()
        static int fsync(ScriptObject*, int fildes);
        static int ftruncate(ScriptObject*, int fildes, uint32_t length);
        //getcwd()
        //getegid()
        //geteuid()
        //getgid()
        //getgroups()
        //gethostid()
        //gethostname()
        //getlogin()
        //getlogin_r()
        //getopt()
        //getpgid()
        //getpgrp()
        //getpid()
        //getppid()
        //getsid()
        //getuid()
        //isatty()
        //lchown()
        //link()
        //linkat()
        //lockf()
        //lseek()
        //nice()
        //pathconf()
        //pause()
        //pipe()
        //pread()
        //pwrite()
        //read()
        //readlink()
        //readlinkat()
        //rmdir()
        //setegid()
        //seteuid()
        //setgid()
        //setpgid()
        //setpgrp()
        //setregid()
        //setreuid()
        //setsid()
        //seyuid()
        //sleep()
        //swab()
        //symlink()
        //symlinkat()
        //sync()
        //sysconf()
        //tcgetpgrp()
        //tcsetpgrp()
        //truncate()
        //ttyname()
        //ttyname_r()
        //unlink()
        //unlinkat()
        //write()



        //int access(avmplus::Stringp path, int mode);
        //int chdir(avmplus::Stringp path);
        //int chmod(avmplus::Stringp path, int mode);
        avmplus::Stringp getcwd();
        avmplus::Stringp gethostname();
        avmplus::Stringp getlogin();
        int getpid();
        //int mkdir(avmplus::Stringp path);
        int rmdir(avmplus::Stringp path);
        void sleep(int milliseconds);
        int unlink(avmplus::Stringp path);


        DECLARE_SLOTS_CUnistdClass;
    };

}

#endif /* __avmshell_CUnistdClass__ */

