/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/* machine generated file -- do not edit */

namespace avmplus { namespace NativeID {

const uint32_t shell_toplevel_abc_class_count = 31;
const uint32_t shell_toplevel_abc_script_count = 3;
const uint32_t shell_toplevel_abc_method_count = 404;
const uint32_t shell_toplevel_abc_length = 26154;

/* thunks (239 total) */
avmplus::Atom C_errno___errno_EDOM_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_EDOM();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_EDOM_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_EDOM_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_EILSEQ_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_EILSEQ();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_EILSEQ_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_EILSEQ_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_ERANGE_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_ERANGE();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_ERANGE_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_ERANGE_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_EPERM_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_EPERM();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_EPERM_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_EPERM_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_ENOENT_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_ENOENT();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_ENOENT_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_ENOENT_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_ESRCH_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_ESRCH();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_ESRCH_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_ESRCH_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_EINTR_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_EINTR();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_EINTR_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_EINTR_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_EIO_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_EIO();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_EIO_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_EIO_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_ENXIO_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_ENXIO();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_ENXIO_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_ENXIO_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_E2BIG_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_E2BIG();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_E2BIG_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_E2BIG_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_ENOEXEC_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_ENOEXEC();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_ENOEXEC_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_ENOEXEC_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_EBADF_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_EBADF();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_EBADF_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_EBADF_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_ECHILD_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_ECHILD();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_ECHILD_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_ECHILD_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_EAGAIN_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_EAGAIN();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_EAGAIN_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_EAGAIN_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_ENOMEM_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_ENOMEM();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_ENOMEM_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_ENOMEM_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_EACCES_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_EACCES();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_EACCES_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_EACCES_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_EFAULT_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_EFAULT();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_EFAULT_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_EFAULT_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_EBUSY_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_EBUSY();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_EBUSY_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_EBUSY_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_EEXIST_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_EEXIST();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_EEXIST_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_EEXIST_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_EXDEV_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_EXDEV();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_EXDEV_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_EXDEV_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_ENODEV_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_ENODEV();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_ENODEV_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_ENODEV_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_ENOTDIR_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_ENOTDIR();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_ENOTDIR_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_ENOTDIR_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_EISDIR_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_EISDIR();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_EISDIR_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_EISDIR_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_EINVAL_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_EINVAL();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_EINVAL_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_EINVAL_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_ENFILE_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_ENFILE();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_ENFILE_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_ENFILE_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_EMFILE_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_EMFILE();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_EMFILE_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_EMFILE_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_ENOTTY_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_ENOTTY();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_ENOTTY_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_ENOTTY_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_EFBIG_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_EFBIG();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_EFBIG_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_EFBIG_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_ENOSPC_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_ENOSPC();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_ENOSPC_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_ENOSPC_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_ESPIPE_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_ESPIPE();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_ESPIPE_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_ESPIPE_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_EROFS_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_EROFS();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_EROFS_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_EROFS_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_EMLINK_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_EMLINK();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_EMLINK_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_EMLINK_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_EPIPE_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_EPIPE();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_EPIPE_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_EPIPE_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_EDEADLK_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_EDEADLK();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_EDEADLK_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_EDEADLK_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_ENAMETOOLONG_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_ENAMETOOLONG();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_ENAMETOOLONG_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_ENAMETOOLONG_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_ENOLCK_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_ENOLCK();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_ENOLCK_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_ENOLCK_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_ENOSYS_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_ENOSYS();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_ENOSYS_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_ENOSYS_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_ENOTEMPTY_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_ENOTEMPTY();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_ENOTEMPTY_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_ENOTEMPTY_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_EWOULDBLOCK_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_EWOULDBLOCK();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_EWOULDBLOCK_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_EWOULDBLOCK_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_EINPROGRESS_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_EINPROGRESS();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_EINPROGRESS_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_EINPROGRESS_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_EALREADY_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_EALREADY();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_EALREADY_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_EALREADY_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_EDESTADDRREQ_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_EDESTADDRREQ();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_EDESTADDRREQ_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_EDESTADDRREQ_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_EMSGSIZE_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_EMSGSIZE();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_EMSGSIZE_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_EMSGSIZE_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_EPROTOTYPE_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_EPROTOTYPE();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_EPROTOTYPE_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_EPROTOTYPE_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_ENOPROTOOPT_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_ENOPROTOOPT();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_ENOPROTOOPT_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_ENOPROTOOPT_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_EADDRINUSE_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_EADDRINUSE();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_EADDRINUSE_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_EADDRINUSE_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_EADDRNOTAVAIL_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_EADDRNOTAVAIL();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_EADDRNOTAVAIL_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_EADDRNOTAVAIL_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_ENETDOWN_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_ENETDOWN();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_ENETDOWN_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_ENETDOWN_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_ENETUNREACH_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_ENETUNREACH();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_ENETUNREACH_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_ENETUNREACH_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_ENETRESET_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_ENETRESET();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_ENETRESET_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_ENETRESET_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_ECONNABORTED_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_ECONNABORTED();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_ECONNABORTED_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_ECONNABORTED_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_ECONNRESET_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_ECONNRESET();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_ECONNRESET_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_ECONNRESET_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_ENOBUFS_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_ENOBUFS();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_ENOBUFS_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_ENOBUFS_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_EISCONN_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_EISCONN();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_EISCONN_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_EISCONN_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_ENOTCONN_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_ENOTCONN();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_ENOTCONN_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_ENOTCONN_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_ESHUTDOWN_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_ESHUTDOWN();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_ESHUTDOWN_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_ESHUTDOWN_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_ETOOMANYREFS_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_ETOOMANYREFS();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_ETOOMANYREFS_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_ETOOMANYREFS_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_ETIMEDOUT_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_ETIMEDOUT();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_ETIMEDOUT_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_ETIMEDOUT_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_ECONNREFUSED_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_ECONNREFUSED();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_ECONNREFUSED_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_ECONNREFUSED_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_ELOOP_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_ELOOP();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_ELOOP_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_ELOOP_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_EHOSTDOWN_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_EHOSTDOWN();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_EHOSTDOWN_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_EHOSTDOWN_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_EHOSTUNREACH_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->get_EHOSTUNREACH();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_EHOSTUNREACH_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_EHOSTUNREACH_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_GetErrno_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    int32_t const ret = obj->GetErrno();
    return avmplus::Atom(ret);
}
avmplus::Atom C_errno___errno_GetErrno_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_GetErrno_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_errno___errno_SetErrno_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    int32_t arg1 = AvmThunkUnbox_INT(int32_t, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::CErrnoClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CErrnoClass*, argv[argoff0]);
    obj->SetErrno(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom C_errno___errno_SetErrno_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_errno___errno_SetErrno_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_stdlib___stdlib_EXIT_SUCCESS_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CStdlibClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CStdlibClass*, argv[argoff0]);
    int32_t const ret = obj->get_EXIT_SUCCESS();
    return avmplus::Atom(ret);
}
avmplus::Atom C_stdlib___stdlib_EXIT_SUCCESS_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_stdlib___stdlib_EXIT_SUCCESS_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_stdlib___stdlib_EXIT_FAILURE_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CStdlibClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CStdlibClass*, argv[argoff0]);
    int32_t const ret = obj->get_EXIT_FAILURE();
    return avmplus::Atom(ret);
}
avmplus::Atom C_stdlib___stdlib_EXIT_FAILURE_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_stdlib___stdlib_EXIT_FAILURE_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_stdlib___stdlib_abort_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CStdlibClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CStdlibClass*, argv[argoff0]);
    obj->abort();
    return undefinedAtom;
}
avmplus::Atom C_stdlib___stdlib_abort_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_stdlib___stdlib_abort_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_stdlib___stdlib_exit_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    int32_t arg1 = (argc < 1 ? 0 : AvmThunkUnbox_INT(int32_t, argv[argoff1]));
    (void)env;
    avmshell::CStdlibClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CStdlibClass*, argv[argoff0]);
    obj->exit(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom C_stdlib___stdlib_exit_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_stdlib___stdlib_exit_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_stdlib___stdlib_getenv_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::CStdlibClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CStdlibClass*, argv[argoff0]);
    avmplus::String* const ret = obj->getenv(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom C_stdlib___stdlib_getenv_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_stdlib___stdlib_getenv_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_stdlib___stdlib_setenv_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_STRING
        , argoff3 = argoff2 + AvmThunkArgSize_STRING
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    avmplus::String* arg2 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff2]);
    int32_t arg3 = AvmThunkUnbox_INT(int32_t, argv[argoff3]);
    (void)argc;
    (void)env;
    avmshell::CStdlibClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CStdlibClass*, argv[argoff0]);
    int32_t const ret = obj->setenv(
        arg1
        , arg2
        , arg3
    );
    return avmplus::Atom(ret);
}
avmplus::Atom C_stdlib___stdlib_setenv_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_stdlib___stdlib_setenv_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_stdlib___stdlib_unsetenv_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::CStdlibClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CStdlibClass*, argv[argoff0]);
    int32_t const ret = obj->unsetenv(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom C_stdlib___stdlib_unsetenv_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_stdlib___stdlib_unsetenv_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_stdlib___stdlib_realpath_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::CStdlibClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CStdlibClass*, argv[argoff0]);
    avmplus::String* const ret = obj->realpath(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom C_stdlib___stdlib_realpath_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_stdlib___stdlib_realpath_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_stdlib___stdlib___system_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::CStdlibClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CStdlibClass*, argv[argoff0]);
    int32_t const ret = obj->__system(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom C_stdlib___stdlib___system_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_stdlib___stdlib___system_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_F_OK_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    int32_t const ret = obj->get_F_OK();
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_F_OK_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_F_OK_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_X_OK_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    int32_t const ret = obj->get_X_OK();
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_X_OK_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_X_OK_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_W_OK_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    int32_t const ret = obj->get_W_OK();
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_W_OK_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_W_OK_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_R_OK_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    int32_t const ret = obj->get_R_OK();
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_R_OK_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_R_OK_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_S_IFMT_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    int32_t const ret = obj->get_S_IFMT();
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_S_IFMT_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_S_IFMT_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_S_IFIFO_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    int32_t const ret = obj->get_S_IFIFO();
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_S_IFIFO_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_S_IFIFO_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_S_IFCHR_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    int32_t const ret = obj->get_S_IFCHR();
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_S_IFCHR_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_S_IFCHR_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_S_IFDIR_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    int32_t const ret = obj->get_S_IFDIR();
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_S_IFDIR_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_S_IFDIR_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_S_IFBLK_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    int32_t const ret = obj->get_S_IFBLK();
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_S_IFBLK_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_S_IFBLK_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_S_IFREG_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    int32_t const ret = obj->get_S_IFREG();
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_S_IFREG_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_S_IFREG_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_S_IFLNK_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    int32_t const ret = obj->get_S_IFLNK();
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_S_IFLNK_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_S_IFLNK_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_S_IFSOCK_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    int32_t const ret = obj->get_S_IFSOCK();
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_S_IFSOCK_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_S_IFSOCK_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_S_IRWXU_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    int32_t const ret = obj->get_S_IRWXU();
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_S_IRWXU_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_S_IRWXU_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_S_IRUSR_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    int32_t const ret = obj->get_S_IRUSR();
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_S_IRUSR_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_S_IRUSR_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_S_IWUSR_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    int32_t const ret = obj->get_S_IWUSR();
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_S_IWUSR_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_S_IWUSR_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_S_IXUSR_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    int32_t const ret = obj->get_S_IXUSR();
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_S_IXUSR_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_S_IXUSR_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_S_IRWXG_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    int32_t const ret = obj->get_S_IRWXG();
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_S_IRWXG_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_S_IRWXG_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_S_IRGRP_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    int32_t const ret = obj->get_S_IRGRP();
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_S_IRGRP_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_S_IRGRP_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_S_IWGRP_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    int32_t const ret = obj->get_S_IWGRP();
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_S_IWGRP_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_S_IWGRP_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_S_IXGRP_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    int32_t const ret = obj->get_S_IXGRP();
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_S_IXGRP_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_S_IXGRP_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_S_IRWXO_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    int32_t const ret = obj->get_S_IRWXO();
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_S_IRWXO_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_S_IRWXO_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_S_IROTH_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    int32_t const ret = obj->get_S_IROTH();
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_S_IROTH_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_S_IROTH_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_S_IWOTH_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    int32_t const ret = obj->get_S_IWOTH();
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_S_IWOTH_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_S_IWOTH_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_S_IXOTH_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    int32_t const ret = obj->get_S_IXOTH();
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_S_IXOTH_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_S_IXOTH_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_S_IREAD_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    int32_t const ret = obj->get_S_IREAD();
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_S_IREAD_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_S_IREAD_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_S_IWRITE_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    int32_t const ret = obj->get_S_IWRITE();
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_S_IWRITE_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_S_IWRITE_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_S_IEXEC_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    int32_t const ret = obj->get_S_IEXEC();
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_S_IEXEC_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_S_IEXEC_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_access_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_STRING
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    int32_t arg2 = AvmThunkUnbox_INT(int32_t, argv[argoff2]);
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    int32_t const ret = obj->access(
        arg1
        , arg2
    );
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_access_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_access_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_chdir_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    int32_t const ret = obj->chdir(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_chdir_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_chdir_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_chmod_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_STRING
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    int32_t arg2 = AvmThunkUnbox_INT(int32_t, argv[argoff2]);
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    int32_t const ret = obj->chmod(
        arg1
        , arg2
    );
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_chmod_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_chmod_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_getcwd_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    avmplus::String* const ret = obj->getcwd();
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_getcwd_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_getcwd_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_gethostname_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    avmplus::String* const ret = obj->gethostname();
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_gethostname_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_gethostname_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_getlogin_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    avmplus::String* const ret = obj->getlogin();
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_getlogin_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_getlogin_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_getpid_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    int32_t const ret = obj->getpid();
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_getpid_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_getpid_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_mkdir_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    int32_t const ret = obj->mkdir(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_mkdir_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_mkdir_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_rmdir_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    int32_t const ret = obj->rmdir(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_rmdir_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_rmdir_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_sleep_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    uint32_t arg1 = AvmThunkUnbox_UINT(uint32_t, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    obj->sleep(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom C_unistd___unistd_sleep_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_sleep_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_unistd___unistd_unlink_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::CUnistdClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CUnistdClass*, argv[argoff0]);
    int32_t const ret = obj->unlink(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom C_unistd___unistd_unlink_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_unistd___unistd_unlink_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_string___string_strerror_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    int32_t arg1 = AvmThunkUnbox_INT(int32_t, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::CStringClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CStringClass*, argv[argoff0]);
    avmplus::String* const ret = obj->strerror(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom C_string___string_strerror_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_string___string_strerror_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_string___string_strlen_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::CStringClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CStringClass*, argv[argoff0]);
    uint32_t const ret = obj->strlen(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom C_string___string_strlen_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_string___string_strlen_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_stdio___stdio_FILENAME_MAX_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CStdioClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CStdioClass*, argv[argoff0]);
    int32_t const ret = obj->get_FILENAME_MAX();
    return avmplus::Atom(ret);
}
avmplus::Atom C_stdio___stdio_FILENAME_MAX_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_stdio___stdio_FILENAME_MAX_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_stdio___stdio_PATH_MAX_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CStdioClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CStdioClass*, argv[argoff0]);
    int32_t const ret = obj->get_PATH_MAX();
    return avmplus::Atom(ret);
}
avmplus::Atom C_stdio___stdio_PATH_MAX_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_stdio___stdio_PATH_MAX_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_stdio___stdio_NONBLOCKING_DISABLE_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CStdioClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CStdioClass*, argv[argoff0]);
    int32_t const ret = obj->get_NONBLOCKING_DISABLE();
    return avmplus::Atom(ret);
}
avmplus::Atom C_stdio___stdio_NONBLOCKING_DISABLE_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_stdio___stdio_NONBLOCKING_DISABLE_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_stdio___stdio_NONBLOCKING_ENABLE_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CStdioClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CStdioClass*, argv[argoff0]);
    int32_t const ret = obj->get_NONBLOCKING_ENABLE();
    return avmplus::Atom(ret);
}
avmplus::Atom C_stdio___stdio_NONBLOCKING_ENABLE_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_stdio___stdio_NONBLOCKING_ENABLE_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_stdio___stdio_O_TEXT_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CStdioClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CStdioClass*, argv[argoff0]);
    int32_t const ret = obj->get_O_TEXT();
    return avmplus::Atom(ret);
}
avmplus::Atom C_stdio___stdio_O_TEXT_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_stdio___stdio_O_TEXT_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_stdio___stdio_O_BINARY_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CStdioClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CStdioClass*, argv[argoff0]);
    int32_t const ret = obj->get_O_BINARY();
    return avmplus::Atom(ret);
}
avmplus::Atom C_stdio___stdio_O_BINARY_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_stdio___stdio_O_BINARY_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_stdio___stdio_remove_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::CStdioClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CStdioClass*, argv[argoff0]);
    int32_t const ret = obj->remove(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom C_stdio___stdio_remove_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_stdio___stdio_remove_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_stdio___stdio_rename_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_STRING
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    avmplus::String* arg2 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff2]);
    (void)argc;
    (void)env;
    avmshell::CStdioClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CStdioClass*, argv[argoff0]);
    int32_t const ret = obj->rename(
        arg1
        , arg2
    );
    return avmplus::Atom(ret);
}
avmplus::Atom C_stdio___stdio_rename_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_stdio___stdio_rename_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_stdio___stdio_con_stream_mode_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    int32_t arg1 = AvmThunkUnbox_INT(int32_t, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::CStdioClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CStdioClass*, argv[argoff0]);
    obj->con_stream_mode(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom C_stdio___stdio_con_stream_mode_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_stdio___stdio_con_stream_mode_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_stdio___stdio_con_trans_mode_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    int32_t arg1 = AvmThunkUnbox_INT(int32_t, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::CStdioClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CStdioClass*, argv[argoff0]);
    obj->con_trans_mode(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom C_stdio___stdio_con_trans_mode_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_stdio___stdio_con_trans_mode_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_stdio___stdio_kbhit_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CStdioClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CStdioClass*, argv[argoff0]);
    int32_t const ret = obj->kbhit();
    return avmplus::Atom(ret);
}
avmplus::Atom C_stdio___stdio_kbhit_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_stdio___stdio_kbhit_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom native_script_function_C_stdio2__rename2_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_STRING
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    avmplus::String* arg2 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff2]);
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    int32_t const ret = ::avmshell::CStdioClass::rename2(obj
        , arg1
        , arg2
    );
    return avmplus::Atom(ret);
}
avmplus::Atom native_script_function_C_stdio2__rename2_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = native_script_function_C_stdio2__rename2_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket_SOCK_RAW_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    int32_t const ret = obj->get_SOCK_RAW();
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket_SOCK_RAW_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket_SOCK_RAW_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket_SOCK_STREAM_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    int32_t const ret = obj->get_SOCK_STREAM();
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket_SOCK_STREAM_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket_SOCK_STREAM_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket_SOCK_DGRAM_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    int32_t const ret = obj->get_SOCK_DGRAM();
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket_SOCK_DGRAM_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket_SOCK_DGRAM_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket_SO_ACCEPTCONN_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    int32_t const ret = obj->get_SO_ACCEPTCONN();
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket_SO_ACCEPTCONN_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket_SO_ACCEPTCONN_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket_SO_BROADCAST_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    int32_t const ret = obj->get_SO_BROADCAST();
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket_SO_BROADCAST_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket_SO_BROADCAST_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket_SO_DONTROUTE_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    int32_t const ret = obj->get_SO_DONTROUTE();
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket_SO_DONTROUTE_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket_SO_DONTROUTE_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket_SO_KEEPALIVE_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    int32_t const ret = obj->get_SO_KEEPALIVE();
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket_SO_KEEPALIVE_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket_SO_KEEPALIVE_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket_SO_OOBINLINE_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    int32_t const ret = obj->get_SO_OOBINLINE();
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket_SO_OOBINLINE_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket_SO_OOBINLINE_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket_SO_RCVBUF_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    int32_t const ret = obj->get_SO_RCVBUF();
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket_SO_RCVBUF_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket_SO_RCVBUF_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket_SO_RCVTIMEO_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    int32_t const ret = obj->get_SO_RCVTIMEO();
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket_SO_RCVTIMEO_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket_SO_RCVTIMEO_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket_SO_REUSEADDR_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    int32_t const ret = obj->get_SO_REUSEADDR();
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket_SO_REUSEADDR_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket_SO_REUSEADDR_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket_SO_SNDBUF_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    int32_t const ret = obj->get_SO_SNDBUF();
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket_SO_SNDBUF_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket_SO_SNDBUF_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket_SO_SNDTIMEO_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    int32_t const ret = obj->get_SO_SNDTIMEO();
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket_SO_SNDTIMEO_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket_SO_SNDTIMEO_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket_SO_TYPE_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    int32_t const ret = obj->get_SO_TYPE();
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket_SO_TYPE_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket_SO_TYPE_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket_MSG_CTRUNC_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    int32_t const ret = obj->get_MSG_CTRUNC();
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket_MSG_CTRUNC_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket_MSG_CTRUNC_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket_MSG_DONTROUTE_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    int32_t const ret = obj->get_MSG_DONTROUTE();
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket_MSG_DONTROUTE_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket_MSG_DONTROUTE_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket_MSG_OOB_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    int32_t const ret = obj->get_MSG_OOB();
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket_MSG_OOB_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket_MSG_OOB_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket_MSG_PEEK_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    int32_t const ret = obj->get_MSG_PEEK();
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket_MSG_PEEK_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket_MSG_PEEK_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket_MSG_TRUNC_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    int32_t const ret = obj->get_MSG_TRUNC();
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket_MSG_TRUNC_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket_MSG_TRUNC_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket_MSG_WAITALL_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    int32_t const ret = obj->get_MSG_WAITALL();
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket_MSG_WAITALL_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket_MSG_WAITALL_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket_MSG_DONTWAIT_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    int32_t const ret = obj->get_MSG_DONTWAIT();
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket_MSG_DONTWAIT_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket_MSG_DONTWAIT_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket_AF_INET_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    int32_t const ret = obj->get_AF_INET();
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket_AF_INET_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket_AF_INET_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket_AF_INET6_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    int32_t const ret = obj->get_AF_INET6();
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket_AF_INET6_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket_AF_INET6_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket_AF_UNSPEC_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    int32_t const ret = obj->get_AF_UNSPEC();
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket_AF_UNSPEC_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket_AF_UNSPEC_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket_SHUT_RD_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    int32_t const ret = obj->get_SHUT_RD();
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket_SHUT_RD_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket_SHUT_RD_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket_SHUT_RDWR_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    int32_t const ret = obj->get_SHUT_RDWR();
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket_SHUT_RDWR_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket_SHUT_RDWR_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket_SHUT_WR_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    int32_t const ret = obj->get_SHUT_WR();
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket_SHUT_WR_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket_SHUT_WR_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket_IPPROTO_IP_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    int32_t const ret = obj->get_IPPROTO_IP();
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket_IPPROTO_IP_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket_IPPROTO_IP_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket_IPPROTO_IPV6_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    int32_t const ret = obj->get_IPPROTO_IPV6();
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket_IPPROTO_IPV6_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket_IPPROTO_IPV6_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket_IPPROTO_ICMP_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    int32_t const ret = obj->get_IPPROTO_ICMP();
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket_IPPROTO_ICMP_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket_IPPROTO_ICMP_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket_IPPROTO_RAW_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    int32_t const ret = obj->get_IPPROTO_RAW();
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket_IPPROTO_RAW_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket_IPPROTO_RAW_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket_IPPROTO_TCP_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    int32_t const ret = obj->get_IPPROTO_TCP();
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket_IPPROTO_TCP_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket_IPPROTO_TCP_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket_IPPROTO_UDP_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    int32_t const ret = obj->get_IPPROTO_UDP();
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket_IPPROTO_UDP_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket_IPPROTO_UDP_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket_SOMAXCONN_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    int32_t const ret = obj->get_SOMAXCONN();
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket_SOMAXCONN_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket_SOMAXCONN_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket___gethostbyaddr_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_STRING
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    avmplus::bool32 arg2 = AvmThunkUnbox_BOOLEAN(avmplus::bool32, argv[argoff2]);
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    avmplus::ArrayObject* const ret = obj->__gethostbyaddr(
        arg1
        , arg2
    );
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket___gethostbyaddr_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket___gethostbyaddr_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket___gethostbyname_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_STRING
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    avmplus::bool32 arg2 = AvmThunkUnbox_BOOLEAN(avmplus::bool32, argv[argoff2]);
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    avmplus::ArrayObject* const ret = obj->__gethostbyname(
        arg1
        , arg2
    );
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket___gethostbyname_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket___gethostbyname_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket___getpeername_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    int32_t arg1 = AvmThunkUnbox_INT(int32_t, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    avmplus::String* const ret = obj->__getpeername(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket___getpeername_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket___getpeername_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom C_socket___socket___getsockname_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    int32_t arg1 = AvmThunkUnbox_INT(int32_t, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::CSocketClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::CSocketClass*, argv[argoff0]);
    avmplus::String* const ret = obj->__getsockname(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom C_socket___socket___getsockname_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = C_socket___socket___getsockname_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Program_private_getArgv_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::ProgramClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ProgramClass*, argv[argoff0]);
    avmplus::ArrayObject* const ret = obj->getArgv();
    return avmplus::Atom(ret);
}
avmplus::Atom shell_Program_private_getArgv_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Program_private_getArgv_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Program_private_popenRead_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::ProgramClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ProgramClass*, argv[argoff0]);
    avmplus::String* const ret = obj->popenRead(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom shell_Program_private_popenRead_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Program_private_popenRead_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Program_apiVersion_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::ProgramClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ProgramClass*, argv[argoff0]);
    int32_t const ret = obj->get_apiVersion();
    return avmplus::Atom(ret);
}
avmplus::Atom shell_Program_apiVersion_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Program_apiVersion_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Program_programFilename_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::ProgramClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ProgramClass*, argv[argoff0]);
    avmplus::String* const ret = obj->get_programFilename();
    return avmplus::Atom(ret);
}
avmplus::Atom shell_Program_programFilename_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Program_programFilename_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Program_swfVersion_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::ProgramClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ProgramClass*, argv[argoff0]);
    int32_t const ret = obj->get_swfVersion();
    return avmplus::Atom(ret);
}
avmplus::Atom shell_Program_swfVersion_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Program_swfVersion_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
double shell_Program_totalMemory_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::ProgramClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ProgramClass*, argv[argoff0]);
    double const ret = obj->get_totalMemory();
    return double(ret);
}
double shell_Program_totalMemory_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    double retVal = shell_Program_totalMemory_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
double shell_Program_freeMemory_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::ProgramClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ProgramClass*, argv[argoff0]);
    double const ret = obj->get_freeMemory();
    return double(ret);
}
double shell_Program_freeMemory_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    double retVal = shell_Program_freeMemory_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
double shell_Program_privateMemory_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::ProgramClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ProgramClass*, argv[argoff0]);
    double const ret = obj->get_privateMemory();
    return double(ret);
}
double shell_Program_privateMemory_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    double retVal = shell_Program_privateMemory_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Program_eval_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::ProgramClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ProgramClass*, argv[argoff0]);
    obj->eval(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom shell_Program_eval_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Program_eval_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Program_exec_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::ProgramClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ProgramClass*, argv[argoff0]);
    int32_t const ret = obj->exec(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom shell_Program_exec_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Program_exec_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Program_exit_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    int32_t arg1 = (argc < 1 ? -1 : AvmThunkUnbox_INT(int32_t, argv[argoff1]));
    (void)env;
    avmshell::ProgramClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ProgramClass*, argv[argoff0]);
    obj->exit(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom shell_Program_exit_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Program_exit_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Program_getAvmplusVersion_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::ProgramClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ProgramClass*, argv[argoff0]);
    avmplus::String* const ret = obj->getAvmplusVersion();
    return avmplus::Atom(ret);
}
avmplus::Atom shell_Program_getAvmplusVersion_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Program_getAvmplusVersion_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Program_getEnviron_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::ProgramClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ProgramClass*, argv[argoff0]);
    avmplus::ArrayObject* const ret = obj->getEnviron();
    return avmplus::Atom(ret);
}
avmplus::Atom shell_Program_getEnviron_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Program_getEnviron_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Program_getFeatures_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::ProgramClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ProgramClass*, argv[argoff0]);
    avmplus::String* const ret = obj->getFeatures();
    return avmplus::Atom(ret);
}
avmplus::Atom shell_Program_getFeatures_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Program_getFeatures_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
double shell_Program_getNanosecondTimer_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::ProgramClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ProgramClass*, argv[argoff0]);
    double const ret = obj->getNanosecondTimer();
    return double(ret);
}
double shell_Program_getNanosecondTimer_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    double retVal = shell_Program_getNanosecondTimer_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Program_getRunmode_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::ProgramClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ProgramClass*, argv[argoff0]);
    avmplus::String* const ret = obj->getRunmode();
    return avmplus::Atom(ret);
}
avmplus::Atom shell_Program_getRunmode_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Program_getRunmode_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Program_getTimer_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::ProgramClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ProgramClass*, argv[argoff0]);
    uint32_t const ret = obj->getTimer();
    return avmplus::Atom(ret);
}
avmplus::Atom shell_Program_getTimer_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Program_getTimer_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Program_readLine_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::ProgramClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ProgramClass*, argv[argoff0]);
    avmplus::String* const ret = obj->readLine();
    return avmplus::Atom(ret);
}
avmplus::Atom shell_Program_readLine_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Program_readLine_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Program_sleep_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    int32_t arg1 = AvmThunkUnbox_INT(int32_t, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::ProgramClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ProgramClass*, argv[argoff0]);
    obj->sleep(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom shell_Program_sleep_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Program_sleep_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Program_trace_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::ArrayObject* arg1 = (avmplus::ArrayObject*)AvmThunkUnbox_OBJECT(avmplus::ArrayObject*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::ProgramClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ProgramClass*, argv[argoff0]);
    obj->trace(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom shell_Program_trace_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Program_trace_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Program_write_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::ProgramClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ProgramClass*, argv[argoff0]);
    obj->write(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom shell_Program_write_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Program_write_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Program_debugger_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::ProgramClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ProgramClass*, argv[argoff0]);
    obj->debugger();
    return undefinedAtom;
}
avmplus::Atom shell_Program_debugger_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Program_debugger_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Program_isDebugger_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::ProgramClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ProgramClass*, argv[argoff0]);
    bool const ret = obj->isDebugger();
    return avmplus::Atom(ret);
}
avmplus::Atom shell_Program_isDebugger_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Program_isDebugger_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Program_forceFullCollection_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::ProgramClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ProgramClass*, argv[argoff0]);
    obj->forceFullCollection();
    return undefinedAtom;
}
avmplus::Atom shell_Program_forceFullCollection_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Program_forceFullCollection_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Program_queueCollection_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::ProgramClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ProgramClass*, argv[argoff0]);
    obj->queueCollection();
    return undefinedAtom;
}
avmplus::Atom shell_Program_queueCollection_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Program_queueCollection_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Program_pauseForGCIfCollectionImminent_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    double arg1 = (argc < 1 ? 0.75 : AvmThunkUnbox_DOUBLE(double, argv[argoff1]));
    (void)env;
    avmshell::ProgramClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ProgramClass*, argv[argoff0]);
    obj->pauseForGCIfCollectionImminent(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom shell_Program_pauseForGCIfCollectionImminent_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Program_pauseForGCIfCollectionImminent_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Program_disposeXML_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::XMLObject* arg1 = (avmplus::XMLObject*)AvmThunkUnbox_OBJECT(avmplus::XMLObject*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::ProgramClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ProgramClass*, argv[argoff0]);
    obj->disposeXML(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom shell_Program_disposeXML_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Program_disposeXML_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Program_isGlobal_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::Atom arg1 = AvmThunkUnbox_ATOM(avmplus::Atom, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::ProgramClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ProgramClass*, argv[argoff0]);
    bool const ret = obj->isGlobal(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom shell_Program_isGlobal_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Program_isGlobal_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Program_is64bit_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::ProgramClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ProgramClass*, argv[argoff0]);
    bool const ret = obj->is64bit();
    return avmplus::Atom(ret);
}
avmplus::Atom shell_Program_is64bit_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Program_is64bit_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Program_isIntptr_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::Atom arg1 = AvmThunkUnbox_ATOM(avmplus::Atom, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::ProgramClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ProgramClass*, argv[argoff0]);
    bool const ret = obj->isIntptr(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom shell_Program_isIntptr_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Program_isIntptr_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Program_canonicalizeNumber_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::Atom arg1 = AvmThunkUnbox_ATOM(avmplus::Atom, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::ProgramClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ProgramClass*, argv[argoff0]);
    avmplus::Atom const ret = obj->canonicalizeNumber(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom shell_Program_canonicalizeNumber_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Program_canonicalizeNumber_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Program_deopt_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    int32_t arg1 = AvmThunkUnbox_INT(int32_t, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::ProgramClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ProgramClass*, argv[argoff0]);
    obj->deopt(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom shell_Program_deopt_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Program_deopt_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Program_runInSafepoint_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::FunctionObject* arg1 = (avmplus::FunctionObject*)AvmThunkUnbox_OBJECT(avmplus::FunctionObject*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::ProgramClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ProgramClass*, argv[argoff0]);
    obj->runInSafepoint(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom shell_Program_runInSafepoint_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Program_runInSafepoint_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Domain_currentDomain_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmplus::DomainClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::DomainClass*, argv[argoff0]);
    avmplus::DomainObject* const ret = obj->get_currentDomain();
    return avmplus::Atom(ret);
}
avmplus::Atom shell_Domain_currentDomain_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Domain_currentDomain_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Domain_MIN_DOMAIN_MEMORY_LENGTH_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmplus::DomainClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::DomainClass*, argv[argoff0]);
    uint32_t const ret = obj->get_MIN_DOMAIN_MEMORY_LENGTH();
    return avmplus::Atom(ret);
}
avmplus::Atom shell_Domain_MIN_DOMAIN_MEMORY_LENGTH_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Domain_MIN_DOMAIN_MEMORY_LENGTH_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Domain_private_init_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::DomainObject* arg1 = (avmplus::DomainObject*)AvmThunkUnbox_OBJECT(avmplus::DomainObject*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmplus::DomainObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::DomainObject*, argv[argoff0]);
    obj->init(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom shell_Domain_private_init_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Domain_private_init_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Domain_loadBytes_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_OBJECT
    };
    avmplus::ByteArrayObject* arg1 = (avmplus::ByteArrayObject*)AvmThunkUnbox_OBJECT(avmplus::ByteArrayObject*, argv[argoff1]);
    uint32_t arg2 = (argc < 2 ? AvmThunkCoerce_INT_UINT(0) : AvmThunkUnbox_UINT(uint32_t, argv[argoff2]));
    (void)env;
    avmplus::DomainObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::DomainObject*, argv[argoff0]);
    avmplus::Atom const ret = obj->loadBytes(
        arg1
        , arg2
    );
    return avmplus::Atom(ret);
}
avmplus::Atom shell_Domain_loadBytes_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Domain_loadBytes_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Domain_getClass_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmplus::DomainObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::DomainObject*, argv[argoff0]);
    avmplus::ClassClosure* const ret = obj->getClass(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom shell_Domain_getClass_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Domain_getClass_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Domain_domainMemory_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmplus::DomainObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::DomainObject*, argv[argoff0]);
    avmplus::ByteArrayObject* const ret = obj->get_domainMemory();
    return avmplus::Atom(ret);
}
avmplus::Atom shell_Domain_domainMemory_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Domain_domainMemory_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_Domain_domainMemory_set_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::ByteArrayObject* arg1 = (avmplus::ByteArrayObject*)AvmThunkUnbox_OBJECT(avmplus::ByteArrayObject*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmplus::DomainObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::DomainObject*, argv[argoff0]);
    obj->set_domainMemory(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom shell_Domain_domainMemory_set_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_Domain_domainMemory_set_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_FileIO_exists_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::FileClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::FileClass*, argv[argoff0]);
    bool const ret = obj->exists(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom shell_FileIO_exists_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_FileIO_exists_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_FileIO_read_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::FileClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::FileClass*, argv[argoff0]);
    avmplus::String* const ret = obj->read(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom shell_FileIO_read_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_FileIO_read_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_FileIO_write_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_STRING
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    avmplus::String* arg2 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff2]);
    (void)argc;
    (void)env;
    avmshell::FileClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::FileClass*, argv[argoff0]);
    obj->write(
        arg1
        , arg2
    );
    return undefinedAtom;
}
avmplus::Atom shell_FileIO_write_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_FileIO_write_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_FileIO_readByteArray_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::FileClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::FileClass*, argv[argoff0]);
    avmplus::ByteArrayObject* const ret = obj->readByteArray(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom shell_FileIO_readByteArray_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_FileIO_readByteArray_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom shell_FileIO_writeByteArray_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_STRING
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    avmplus::ByteArrayObject* arg2 = (avmplus::ByteArrayObject*)AvmThunkUnbox_OBJECT(avmplus::ByteArrayObject*, argv[argoff2]);
    (void)argc;
    (void)env;
    avmshell::FileClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::FileClass*, argv[argoff0]);
    bool const ret = obj->writeByteArray(
        arg1
        , arg2
    );
    return avmplus::Atom(ret);
}
avmplus::Atom shell_FileIO_writeByteArray_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = shell_FileIO_writeByteArray_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_sampler_NewObjectSample_object_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmplus::NewObjectSampleObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::NewObjectSampleObject*, argv[argoff0]);
    avmplus::Atom const ret = obj->get_object();
    return avmplus::Atom(ret);
}
avmplus::Atom flash_sampler_NewObjectSample_object_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = flash_sampler_NewObjectSample_object_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
double flash_sampler_NewObjectSample_size_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmplus::NewObjectSampleObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::NewObjectSampleObject*, argv[argoff0]);
    double const ret = obj->get_size();
    return double(ret);
}
double flash_sampler_NewObjectSample_size_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    double retVal = flash_sampler_NewObjectSample_size_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom native_script_function_flash_sampler_clearSamples_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    SamplerScript::clearSamples(obj);
    return undefinedAtom;
}
avmplus::Atom native_script_function_flash_sampler_clearSamples_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = native_script_function_flash_sampler_clearSamples_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom native_script_function_flash_sampler_startSampling_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    SamplerScript::startSampling(obj);
    return undefinedAtom;
}
avmplus::Atom native_script_function_flash_sampler_startSampling_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = native_script_function_flash_sampler_startSampling_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom native_script_function_flash_sampler_stopSampling_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    SamplerScript::stopSampling(obj);
    return undefinedAtom;
}
avmplus::Atom native_script_function_flash_sampler_stopSampling_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = native_script_function_flash_sampler_stopSampling_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom native_script_function_flash_sampler_pauseSampling_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    SamplerScript::pauseSampling(obj);
    return undefinedAtom;
}
avmplus::Atom native_script_function_flash_sampler_pauseSampling_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = native_script_function_flash_sampler_pauseSampling_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom native_script_function_flash_sampler_sampleInternalAllocs_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::bool32 arg1 = AvmThunkUnbox_BOOLEAN(avmplus::bool32, argv[argoff1]);
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    SamplerScript::sampleInternalAllocs(obj
        , arg1
    );
    return undefinedAtom;
}
avmplus::Atom native_script_function_flash_sampler_sampleInternalAllocs_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = native_script_function_flash_sampler_sampleInternalAllocs_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom native_script_function_flash_sampler__setSamplerCallback_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::FunctionObject* arg1 = (avmplus::FunctionObject*)AvmThunkUnbox_OBJECT(avmplus::FunctionObject*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    SamplerScript::_setSamplerCallback(obj
        , arg1
    );
    return undefinedAtom;
}
avmplus::Atom native_script_function_flash_sampler__setSamplerCallback_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = native_script_function_flash_sampler__setSamplerCallback_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
double native_script_function_flash_sampler_getSize_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::Atom arg1 = AvmThunkUnbox_ATOM(avmplus::Atom, argv[argoff1]);
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    double const ret = SamplerScript::getSize(obj
        , arg1
    );
    return double(ret);
}
double native_script_function_flash_sampler_getSize_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    double retVal = native_script_function_flash_sampler_getSize_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom native_script_function_flash_sampler_getMemberNames_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_ATOM
    };
    avmplus::Atom arg1 = AvmThunkUnbox_ATOM(avmplus::Atom, argv[argoff1]);
    avmplus::bool32 arg2 = (argc < 2 ? false : AvmThunkUnbox_BOOLEAN(avmplus::bool32, argv[argoff2]));
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    avmplus::Atom const ret = SamplerScript::getMemberNames(obj
        , arg1
        , arg2
    );
    return avmplus::Atom(ret);
}
avmplus::Atom native_script_function_flash_sampler_getMemberNames_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = native_script_function_flash_sampler_getMemberNames_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom native_script_function_flash_sampler__getSamples_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::ClassClosure* arg1 = (avmplus::ClassClosure*)AvmThunkUnbox_OBJECT(avmplus::ClassClosure*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    avmplus::Atom const ret = SamplerScript::_getSamples(obj
        , arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom native_script_function_flash_sampler__getSamples_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = native_script_function_flash_sampler__getSamples_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
double native_script_function_flash_sampler_getSampleCount_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    double const ret = SamplerScript::getSampleCount(obj);
    return double(ret);
}
double native_script_function_flash_sampler_getSampleCount_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    double retVal = native_script_function_flash_sampler_getSampleCount_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
double native_script_function_flash_sampler__getInvocationCount_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_ATOM
        , argoff3 = argoff2 + AvmThunkArgSize_OBJECT
    };
    avmplus::Atom arg1 = AvmThunkUnbox_ATOM(avmplus::Atom, argv[argoff1]);
    avmplus::QNameObject* arg2 = (avmplus::QNameObject*)AvmThunkUnbox_OBJECT(avmplus::QNameObject*, argv[argoff2]);
    uint32_t arg3 = AvmThunkUnbox_UINT(uint32_t, argv[argoff3]);
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    double const ret = SamplerScript::_getInvocationCount(obj
        , arg1
        , arg2
        , arg3
    );
    return double(ret);
}
double native_script_function_flash_sampler__getInvocationCount_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    double retVal = native_script_function_flash_sampler__getInvocationCount_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom native_script_function_flash_sampler_isGetterSetter_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_ATOM
    };
    avmplus::Atom arg1 = AvmThunkUnbox_ATOM(avmplus::Atom, argv[argoff1]);
    avmplus::QNameObject* arg2 = (avmplus::QNameObject*)AvmThunkUnbox_OBJECT(avmplus::QNameObject*, argv[argoff2]);
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    bool const ret = SamplerScript::isGetterSetter(obj
        , arg1
        , arg2
    );
    return avmplus::Atom(ret);
}
avmplus::Atom native_script_function_flash_sampler_isGetterSetter_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = native_script_function_flash_sampler_isGetterSetter_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom native_script_function_flash_sampler_getLexicalScopes_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::FunctionObject* arg1 = (avmplus::FunctionObject*)AvmThunkUnbox_OBJECT(avmplus::FunctionObject*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    avmplus::ArrayObject* const ret = SamplerScript::getLexicalScopes(obj
        , arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom native_script_function_flash_sampler_getLexicalScopes_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = native_script_function_flash_sampler_getLexicalScopes_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom native_script_function_flash_sampler_getSavedThis_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::FunctionObject* arg1 = (avmplus::FunctionObject*)AvmThunkUnbox_OBJECT(avmplus::FunctionObject*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    avmplus::Atom const ret = SamplerScript::getSavedThis(obj
        , arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom native_script_function_flash_sampler_getSavedThis_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = native_script_function_flash_sampler_getSavedThis_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom native_script_function_flash_sampler_getMasterString_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmplus::ScriptObject* const obj = AvmThunkUnbox_AvmReceiver(avmplus::ScriptObject*, argv[argoff0]);
    avmplus::String* const ret = SamplerScript::getMasterString(obj
        , arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom native_script_function_flash_sampler_getMasterString_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = native_script_function_flash_sampler_getMasterString_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_trace_Trace_setLevel_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_INT
    };
    int32_t arg1 = AvmThunkUnbox_INT(int32_t, argv[argoff1]);
    int32_t arg2 = (argc < 2 ? 2 : AvmThunkUnbox_INT(int32_t, argv[argoff2]));
    (void)env;
    avmplus::TraceClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::TraceClass*, argv[argoff0]);
    avmplus::Atom const ret = obj->setLevel(
        arg1
        , arg2
    );
    return avmplus::Atom(ret);
}
avmplus::Atom flash_trace_Trace_setLevel_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = flash_trace_Trace_setLevel_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_trace_Trace_getLevel_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    int32_t arg1 = (argc < 1 ? 2 : AvmThunkUnbox_INT(int32_t, argv[argoff1]));
    (void)env;
    avmplus::TraceClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::TraceClass*, argv[argoff0]);
    int32_t const ret = obj->getLevel(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom flash_trace_Trace_getLevel_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = flash_trace_Trace_getLevel_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_trace_Trace_setListener_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::FunctionObject* arg1 = (avmplus::FunctionObject*)AvmThunkUnbox_OBJECT(avmplus::FunctionObject*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmplus::TraceClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::TraceClass*, argv[argoff0]);
    avmplus::Atom const ret = obj->setListener(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom flash_trace_Trace_setListener_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = flash_trace_Trace_setListener_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_trace_Trace_getListener_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmplus::TraceClass* const obj = AvmThunkUnbox_AvmReceiver(avmplus::TraceClass*, argv[argoff0]);
    avmplus::FunctionObject* const ret = obj->getListener();
    return avmplus::Atom(ret);
}
avmplus::Atom flash_trace_Trace_getListener_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = flash_trace_Trace_getListener_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_Worker_pr_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::ShellWorkerClass* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ShellWorkerClass*, argv[argoff0]);
    obj->pr(
        arg1
    );
    return undefinedAtom;
}
avmplus::Atom flash_system_Worker_pr_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = flash_system_Worker_pr_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_Worker_state_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::ShellWorkerObject* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ShellWorkerObject*, argv[argoff0]);
    avmplus::String* const ret = obj->get_state();
    return avmplus::Atom(ret);
}
avmplus::Atom flash_system_Worker_state_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = flash_system_Worker_state_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_Worker_start_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::ShellWorkerObject* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ShellWorkerObject*, argv[argoff0]);
    obj->start();
    return undefinedAtom;
}
avmplus::Atom flash_system_Worker_start_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = flash_system_Worker_start_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_Worker_isParentOf_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmshell::ShellWorkerObject* arg1 = (avmshell::ShellWorkerObject*)AvmThunkUnbox_OBJECT(avmshell::ShellWorkerObject*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::ShellWorkerObject* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ShellWorkerObject*, argv[argoff0]);
    bool const ret = obj->isParentOf(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom flash_system_Worker_isParentOf_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = flash_system_Worker_isParentOf_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_Worker_isPrimordial_get_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::ShellWorkerObject* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ShellWorkerObject*, argv[argoff0]);
    bool const ret = obj->get_isPrimordial();
    return avmplus::Atom(ret);
}
avmplus::Atom flash_system_Worker_isPrimordial_get_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = flash_system_Worker_isPrimordial_get_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_Worker_setSharedProperty_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
        , argoff2 = argoff1 + AvmThunkArgSize_STRING
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    avmplus::Atom arg2 = AvmThunkUnbox_ATOM(avmplus::Atom, argv[argoff2]);
    (void)argc;
    (void)env;
    avmshell::ShellWorkerObject* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ShellWorkerObject*, argv[argoff0]);
    obj->setSharedProperty(
        arg1
        , arg2
    );
    return undefinedAtom;
}
avmplus::Atom flash_system_Worker_setSharedProperty_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = flash_system_Worker_setSharedProperty_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_Worker_getSharedProperty_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::String* arg1 = AvmThunkUnbox_STRING(avmplus::String*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::ShellWorkerObject* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ShellWorkerObject*, argv[argoff0]);
    avmplus::Atom const ret = obj->getSharedProperty(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom flash_system_Worker_getSharedProperty_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = flash_system_Worker_getSharedProperty_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_Worker_terminate_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::ShellWorkerObject* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ShellWorkerObject*, argv[argoff0]);
    bool const ret = obj->terminate();
    return avmplus::Atom(ret);
}
avmplus::Atom flash_system_Worker_terminate_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = flash_system_Worker_terminate_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_WorkerDomain_private_createWorkerFromByteArrayInternal_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
        , argoff1 = argoff0 + AvmThunkArgSize_OBJECT
    };
    avmplus::ByteArrayObject* arg1 = (avmplus::ByteArrayObject*)AvmThunkUnbox_OBJECT(avmplus::ByteArrayObject*, argv[argoff1]);
    (void)argc;
    (void)env;
    avmshell::ShellWorkerDomainObject* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ShellWorkerDomainObject*, argv[argoff0]);
    avmshell::ShellWorkerObject* const ret = obj->createWorkerFromByteArrayInternal(
        arg1
    );
    return avmplus::Atom(ret);
}
avmplus::Atom flash_system_WorkerDomain_private_createWorkerFromByteArrayInternal_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = flash_system_WorkerDomain_private_createWorkerFromByteArrayInternal_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}
avmplus::Atom flash_system_WorkerDomain_listWorkers_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    enum {
        argoff0 = 0
    };
    (void)argc;
    (void)env;
    avmshell::ShellWorkerDomainObject* const obj = AvmThunkUnbox_AvmReceiver(avmshell::ShellWorkerDomainObject*, argv[argoff0]);
    avmplus::ObjectVectorObject* const ret = obj->listWorkers();
    return avmplus::Atom(ret);
}
avmplus::Atom flash_system_WorkerDomain_listWorkers_sampler_thunk(MethodEnv* env, uint32_t argc, Atom* argv)
{
    Namespace* dxns = env->core()->dxns();
    MethodFrame frame;
    frame.enter(env->core(), env);
    frame.setDxns(dxns);
    avmplus::Atom retVal = flash_system_WorkerDomain_listWorkers_thunk(env, argc, argv);
    frame.exit(env->core());
    return retVal;
}

class SlotOffsetsAndAsserts
{
public:
    #ifdef DEBUG
    static uint32_t getSlotOffset(Traits* t, int nameId);
    static uint32_t getMethodIndex(Traits* t, int nameId);
    static uint32_t getGetterIndex(Traits* t, int nameId);
    static uint32_t getSetterIndex(Traits* t, int nameId);
    #endif // DEBUG
    enum {
        kSlotsOffset_avmshell_CErrnoClass = 0,
        kSlotsOffset_avmplus___errnoObject = 0,
        kSlotsOffset_avmplus_ErrorNumberClass = 0,
        kSlotsOffset_avmplus_ErrorNumberObject = offsetof(avmplus::ErrorNumberObject, m_slots_ErrorNumberObject),
        kSlotsOffset_avmplus_CErrorClass = 0,
        kSlotsOffset_avmplus_CErrorObject = 0,
        kSlotsOffset_avmshell_CStdlibClass = 0,
        kSlotsOffset_avmplus___stdlibObject = 0,
        kSlotsOffset_avmshell_CUnistdClass = 0,
        kSlotsOffset_avmplus___unistdObject = 0,
        kSlotsOffset_avmshell_CStringClass = 0,
        kSlotsOffset_avmplus___stringObject = 0,
        kSlotsOffset_avmshell_CStdioClass = 0,
        kSlotsOffset_avmplus___stdioObject = 0,
        kSlotsOffset_avmshell_CSocketClass = 0,
        kSlotsOffset_avmplus___socketObject = 0,
        kSlotsOffset_avmshell_ProgramClass = offsetof(avmshell::ProgramClass, m_slots_ProgramClass),
        kSlotsOffset_avmplus_ProgramObject = 0,
        kSlotsOffset_avmplus_DomainClass = 0,
        kSlotsOffset_avmplus_DomainObject = 0,
        kSlotsOffset_avmshell_FileClass = 0,
        kSlotsOffset_avmplus_FileIOObject = 0,
        kSlotsOffset_avmplus_EnvironmentClass = 0,
        kSlotsOffset_avmplus_EnvironmentObject = offsetof(avmplus::EnvironmentObject, m_slots_EnvironmentObject),
        kSlotsOffset_avmplus_EndianClass = offsetof(avmplus::EndianClass, m_slots_EndianClass),
        kSlotsOffset_avmplus_EndianObject = 0,
        kSlotsOffset_avmplus_CapabilitiesClass = 0,
        kSlotsOffset_avmplus_CapabilitiesObject = 0,
        kSlotsOffset_avmplus_StackFrameClass = 0,
        kSlotsOffset_avmplus_StackFrameObject = offsetof(avmplus::StackFrameObject, m_slots_StackFrameObject),
        kSlotsOffset_avmplus_SampleClass = 0,
        kSlotsOffset_avmplus_SampleObject = offsetof(avmplus::SampleObject, m_slots_SampleObject),
        kSlotsOffset_avmplus_ClassFactoryClass = offsetof(avmplus::ClassFactoryClass, m_slots_ClassFactoryClass),
        kSlotsOffset_avmplus_ClassFactoryObject = 0,
        kSlotsOffset_avmplus_TraceClass = offsetof(avmplus::TraceClass, m_slots_TraceClass),
        kSlotsOffset_avmplus_TraceObject = 0,
        kSlotsOffset_avmplus_WorkerStateClass = offsetof(avmplus::WorkerStateClass, m_slots_WorkerStateClass),
        kSlotsOffset_avmplus_WorkerStateObject = 0,
        kSlotsOffset_avmshell_ShellWorkerClass = offsetof(avmshell::ShellWorkerClass, m_slots_ShellWorkerClass),
        kSlotsOffset_avmshell_ShellWorkerObject = offsetof(avmshell::ShellWorkerObject, m_slots_ShellWorkerObject),
        kSlotsOffset_avmplus_WorkerEventClass = offsetof(avmplus::WorkerEventClass, m_slots_WorkerEventClass),
        kSlotsOffset_avmplus_WorkerEventObject = offsetof(avmplus::WorkerEventObject, m_slots_WorkerEventObject),
        kSlotsOffset_avmshell_ShellWorkerDomainClass = offsetof(avmshell::ShellWorkerDomainClass, m_slots_ShellWorkerDomainClass),
        kSlotsOffset_avmshell_ShellWorkerDomainObject = 0,
        kSlotsOffset_avmplus_SystemClass = offsetof(avmplus::SystemClass, m_slots_SystemClass),
        kSlotsOffset_avmplus_SystemObject = 0,
        kSlotsOffset_avmplus_ScriptTimeoutErrorClass = 0,
        kSlotsOffset_avmplus_ScriptTimeoutErrorObject = 0,
        kSlotsOffset_avmplus_StackOverflowErrorClass = 0,
        kSlotsOffset_avmplus_StackOverflowErrorObject = 0,
        kSlotsOffset_avmplus_InvalidSWFErrorClass = 0,
        kSlotsOffset_avmplus_InvalidSWFErrorObject = 0,
        kSlotsOffset_avmplus_SQLErrorOperationClass = offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass),
        kSlotsOffset_avmplus_SQLErrorOperationObject = 0,
        kSlotsOffset_avmplus_SQLErrorClass = 0,
        kSlotsOffset_avmplus_SQLErrorObject = offsetof(avmplus::SQLErrorObject, m_slots_SQLErrorObject),
        kSlotsOffset_avmplus_DRMManagerErrorClass = 0,
        kSlotsOffset_avmplus_DRMManagerErrorObject = offsetof(avmplus::DRMManagerErrorObject, m_slots_DRMManagerErrorObject),
        kSlotsOffset_avmplus_NewObjectSampleClass = 0,
        kSlotsOffset_avmplus_NewObjectSampleObject = offsetof(avmplus::NewObjectSampleObject, m_slots_NewObjectSampleObject),
        kSlotsOffset_avmplus_DeleteObjectSampleClass = 0,
        kSlotsOffset_avmplus_DeleteObjectSampleObject = offsetof(avmplus::DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject),
        kSlotsOffset_fnord
    };
    #ifdef DEBUG
    static void check_avmshell_CErrnoClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_ErrorNumberClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_CErrorClass(Traits* ctraits, Traits* itraits);
    static void check_avmshell_CStdlibClass(Traits* ctraits, Traits* itraits);
    static void check_avmshell_CUnistdClass(Traits* ctraits, Traits* itraits);
    static void check_avmshell_CStringClass(Traits* ctraits, Traits* itraits);
    static void check_avmshell_CStdioClass(Traits* ctraits, Traits* itraits);
    static void check_avmshell_CSocketClass(Traits* ctraits, Traits* itraits);
    static void check_avmshell_ProgramClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_DomainClass(Traits* ctraits, Traits* itraits);
    static void check_avmshell_FileClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_EnvironmentClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_EndianClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_CapabilitiesClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_StackFrameClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_SampleClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_ClassFactoryClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_TraceClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_WorkerStateClass(Traits* ctraits, Traits* itraits);
    static void check_avmshell_ShellWorkerClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_WorkerEventClass(Traits* ctraits, Traits* itraits);
    static void check_avmshell_ShellWorkerDomainClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_SystemClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_ScriptTimeoutErrorClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_StackOverflowErrorClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_InvalidSWFErrorClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_SQLErrorOperationClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_SQLErrorClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_DRMManagerErrorClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_NewObjectSampleClass(Traits* ctraits, Traits* itraits);
    static void check_avmplus_DeleteObjectSampleClass(Traits* ctraits, Traits* itraits);
    #endif
};
#ifdef DEBUG
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmshell_CErrnoClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_ErrorNumberClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::ErrorNumberObject, m_slots_ErrorNumberObject) == kSlotsOffset_avmplus_ErrorNumberObject);
    MMGC_STATIC_ASSERT(offsetof(avmplus::ErrorNumberObject, m_slots_ErrorNumberObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::ErrorNumberObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(itraits, 155) == (offsetof(avmplus::ErrorNumberObject, m_slots_ErrorNumberObject) + offsetof(avmplus_ErrorNumberObjectSlots, m_private__value)));
    AvmAssert(getGetterIndex(itraits, 156) == 3); // value
    AvmAssert(getSetterIndex(itraits, 156) == 4); // value
    AvmAssert(getMethodIndex(itraits, 157) == 5); // valueOf
    AvmAssert(getMethodIndex(itraits, 158) == 6); // toString
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_CErrorClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmshell_CStdlibClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmshell_CUnistdClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmshell_CStringClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmshell_CStdioClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmshell_CSocketClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmshell_ProgramClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmshell::ProgramClass, m_slots_ProgramClass) == kSlotsOffset_avmshell_ProgramClass);
    MMGC_STATIC_ASSERT(offsetof(avmshell::ProgramClass, m_slots_ProgramClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmshell::ProgramClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(ctraits, 290) == (offsetof(avmshell::ProgramClass, m_slots_ProgramClass) + offsetof(avmshell_ProgramClassSlots, m_private__API)));
    AvmAssert(getSlotOffset(ctraits, 291) == (offsetof(avmshell::ProgramClass, m_slots_ProgramClass) + offsetof(avmshell_ProgramClassSlots, m_private__shell)));
    AvmAssert(getSlotOffset(ctraits, 295) == (offsetof(avmshell::ProgramClass, m_slots_ProgramClass) + offsetof(avmshell_ProgramClassSlots, m_argv)));
    AvmAssert(getSlotOffset(ctraits, 296) == (offsetof(avmshell::ProgramClass, m_slots_ProgramClass) + offsetof(avmshell_ProgramClassSlots, m_startupDirectory)));
    AvmAssert(getSlotOffset(ctraits, 297) == (offsetof(avmshell::ProgramClass, m_slots_ProgramClass) + offsetof(avmshell_ProgramClassSlots, m_enableThrowCError)));
    AvmAssert(getMethodIndex(ctraits, 292) == 5); // private::getArgv
    AvmAssert(getMethodIndex(ctraits, 293) == 6); // private::popenRead
    AvmAssert(getMethodIndex(ctraits, 294) == 7); // private::_findShell
    AvmAssert(getGetterIndex(ctraits, 298) == 8); // apiVersion
    AvmAssert(getGetterIndex(ctraits, 299) == 10); // apiAlias
    AvmAssert(getGetterIndex(ctraits, 300) == 12); // pid
    AvmAssert(getGetterIndex(ctraits, 301) == 14); // programFilename
    AvmAssert(getGetterIndex(ctraits, 302) == 16); // shell
    AvmAssert(getGetterIndex(ctraits, 303) == 18); // swfVersion
    AvmAssert(getGetterIndex(ctraits, 304) == 20); // totalMemory
    AvmAssert(getGetterIndex(ctraits, 305) == 22); // freeMemory
    AvmAssert(getGetterIndex(ctraits, 306) == 24); // privateMemory
    AvmAssert(getGetterIndex(ctraits, 307) == 26); // workingDirectory
    AvmAssert(getSetterIndex(ctraits, 307) == 27); // workingDirectory
    AvmAssert(getMethodIndex(ctraits, 308) == 28); // throwCError
    AvmAssert(getMethodIndex(ctraits, 309) == 29); // eval
    AvmAssert(getMethodIndex(ctraits, 310) == 30); // exec
    AvmAssert(getMethodIndex(ctraits, 170) == 31); // exit
    AvmAssert(getMethodIndex(ctraits, 311) == 32); // popen
    AvmAssert(getMethodIndex(ctraits, 312) == 33); // getAvmplusVersion
    AvmAssert(getMethodIndex(ctraits, 313) == 34); // getEnviron
    AvmAssert(getMethodIndex(ctraits, 314) == 35); // getRedtamarinVersion
    AvmAssert(getMethodIndex(ctraits, 315) == 36); // getFeatures
    AvmAssert(getMethodIndex(ctraits, 316) == 37); // getNanosecondTimer
    AvmAssert(getMethodIndex(ctraits, 317) == 38); // getRunmode
    AvmAssert(getMethodIndex(ctraits, 318) == 39); // getTimer
    AvmAssert(getMethodIndex(ctraits, 319) == 40); // readLine
    AvmAssert(getMethodIndex(ctraits, 213) == 41); // sleep
    AvmAssert(getMethodIndex(ctraits, 320) == 42); // trace
    AvmAssert(getMethodIndex(ctraits, 321) == 43); // write
    AvmAssert(getMethodIndex(ctraits, 322) == 44); // writeLine
    AvmAssert(getMethodIndex(ctraits, 323) == 45); // debugger
    AvmAssert(getMethodIndex(ctraits, 324) == 46); // isDebugger
    AvmAssert(getMethodIndex(ctraits, 325) == 47); // forceFullCollection
    AvmAssert(getMethodIndex(ctraits, 326) == 48); // queueCollection
    AvmAssert(getMethodIndex(ctraits, 327) == 49); // pauseForGCIfCollectionImminent
    AvmAssert(getMethodIndex(ctraits, 328) == 50); // disposeXML
    AvmAssert(getMethodIndex(ctraits, 329) == 51); // isGlobal
    AvmAssert(getMethodIndex(ctraits, 330) == 52); // is64bit
    AvmAssert(getMethodIndex(ctraits, 331) == 53); // isIntptr
    AvmAssert(getMethodIndex(ctraits, 332) == 54); // canonicalizeNumber
    AvmAssert(getMethodIndex(ctraits, 333) == 55); // deopt
    AvmAssert(getMethodIndex(ctraits, 334) == 56); // runInSafepoint
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_DomainClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmshell_FileClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_EnvironmentClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::EnvironmentObject, m_slots_EnvironmentObject) == kSlotsOffset_avmplus_EnvironmentObject);
    MMGC_STATIC_ASSERT(offsetof(avmplus::EnvironmentObject, m_slots_EnvironmentObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::EnvironmentObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(itraits, 372) == (offsetof(avmplus::EnvironmentObject, m_slots_EnvironmentObject) + offsetof(avmplus_EnvironmentObjectSlots, m_private__vars)));
    AvmAssert(getSlotOffset(itraits, 373) == (offsetof(avmplus::EnvironmentObject, m_slots_EnvironmentObject) + offsetof(avmplus_EnvironmentObjectSlots, m_private__idx)));
    AvmAssert(getSlotOffset(itraits, 374) == (offsetof(avmplus::EnvironmentObject, m_slots_EnvironmentObject) + offsetof(avmplus_EnvironmentObjectSlots, m_private__env)));
    AvmAssert(getMethodIndex(itraits, 375) == 13); // private::_parse
    AvmAssert(getMethodIndex(itraits, 376) == 5); // http://www.adobe.com/2006/actionscript/flash/proxy::callProperty
    AvmAssert(getMethodIndex(itraits, 377) == 7); // http://www.adobe.com/2006/actionscript/flash/proxy::deleteProperty
    AvmAssert(getMethodIndex(itraits, 378) == 3); // http://www.adobe.com/2006/actionscript/flash/proxy::getProperty
    AvmAssert(getMethodIndex(itraits, 379) == 4); // http://www.adobe.com/2006/actionscript/flash/proxy::setProperty
    AvmAssert(getMethodIndex(itraits, 380) == 6); // http://www.adobe.com/2006/actionscript/flash/proxy::hasProperty
    AvmAssert(getMethodIndex(itraits, 381) == 9); // http://www.adobe.com/2006/actionscript/flash/proxy::nextNameIndex
    AvmAssert(getMethodIndex(itraits, 382) == 10); // http://www.adobe.com/2006/actionscript/flash/proxy::nextName
    AvmAssert(getMethodIndex(itraits, 383) == 11); // http://www.adobe.com/2006/actionscript/flash/proxy::nextValue
    AvmAssert(getGetterIndex(itraits, 384) == 14); // length
    AvmAssert(getMethodIndex(itraits, 385) == 16); // refresh
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_EndianClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::EndianClass, m_slots_EndianClass) == kSlotsOffset_avmplus_EndianClass);
    MMGC_STATIC_ASSERT(offsetof(avmplus::EndianClass, m_slots_EndianClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::EndianClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(ctraits, 995) == (offsetof(avmplus::EndianClass, m_slots_EndianClass) + offsetof(avmplus_EndianClassSlots, m_BIG_ENDIAN)));
    AvmAssert(getSlotOffset(ctraits, 996) == (offsetof(avmplus::EndianClass, m_slots_EndianClass) + offsetof(avmplus_EndianClassSlots, m_LITTLE_ENDIAN)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_CapabilitiesClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_StackFrameClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::StackFrameObject, m_slots_StackFrameObject) == kSlotsOffset_avmplus_StackFrameObject);
    MMGC_STATIC_ASSERT(offsetof(avmplus::StackFrameObject, m_slots_StackFrameObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::StackFrameObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(itraits, 1005) == (offsetof(avmplus::StackFrameObject, m_slots_StackFrameObject) + offsetof(avmplus_StackFrameObjectSlots, m_name)));
    AvmAssert(getSlotOffset(itraits, 1006) == (offsetof(avmplus::StackFrameObject, m_slots_StackFrameObject) + offsetof(avmplus_StackFrameObjectSlots, m_file)));
    AvmAssert(getSlotOffset(itraits, 1007) == (offsetof(avmplus::StackFrameObject, m_slots_StackFrameObject) + offsetof(avmplus_StackFrameObjectSlots, m_line)));
    AvmAssert(getSlotOffset(itraits, 1008) == (offsetof(avmplus::StackFrameObject, m_slots_StackFrameObject) + offsetof(avmplus_StackFrameObjectSlots, m_scriptID)));
    AvmAssert(getMethodIndex(itraits, 158) == 3); // toString
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_SampleClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::SampleObject, m_slots_SampleObject) == kSlotsOffset_avmplus_SampleObject);
    MMGC_STATIC_ASSERT(offsetof(avmplus::SampleObject, m_slots_SampleObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::SampleObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(itraits, 1010) == (offsetof(avmplus::SampleObject, m_slots_SampleObject) + offsetof(avmplus_SampleObjectSlots, m_time)));
    AvmAssert(getSlotOffset(itraits, 1011) == (offsetof(avmplus::SampleObject, m_slots_SampleObject) + offsetof(avmplus_SampleObjectSlots, m_stack)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_ClassFactoryClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::ClassFactoryClass, m_slots_ClassFactoryClass) == kSlotsOffset_avmplus_ClassFactoryClass);
    MMGC_STATIC_ASSERT(offsetof(avmplus::ClassFactoryClass, m_slots_ClassFactoryClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::ClassFactoryClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(ctraits, 1017) == (offsetof(avmplus::ClassFactoryClass, m_slots_ClassFactoryClass) + offsetof(avmplus_ClassFactoryClassSlots, m_StackFrameClass)));
    AvmAssert(getSlotOffset(ctraits, 1018) == (offsetof(avmplus::ClassFactoryClass, m_slots_ClassFactoryClass) + offsetof(avmplus_ClassFactoryClassSlots, m_SampleClass)));
    AvmAssert(getSlotOffset(ctraits, 1019) == (offsetof(avmplus::ClassFactoryClass, m_slots_ClassFactoryClass) + offsetof(avmplus_ClassFactoryClassSlots, m_DeleteObjectSampleClass)));
    AvmAssert(getSlotOffset(ctraits, 1020) == (offsetof(avmplus::ClassFactoryClass, m_slots_ClassFactoryClass) + offsetof(avmplus_ClassFactoryClassSlots, m_NewObjectSampleClass)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_TraceClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::TraceClass, m_slots_TraceClass) == kSlotsOffset_avmplus_TraceClass);
    MMGC_STATIC_ASSERT(offsetof(avmplus::TraceClass, m_slots_TraceClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::TraceClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(ctraits, 1029) == (offsetof(avmplus::TraceClass, m_slots_TraceClass) + offsetof(avmplus_TraceClassSlots, m_OFF)));
    AvmAssert(getSlotOffset(ctraits, 1030) == (offsetof(avmplus::TraceClass, m_slots_TraceClass) + offsetof(avmplus_TraceClassSlots, m_METHODS)));
    AvmAssert(getSlotOffset(ctraits, 1031) == (offsetof(avmplus::TraceClass, m_slots_TraceClass) + offsetof(avmplus_TraceClassSlots, m_METHODS_WITH_ARGS)));
    AvmAssert(getSlotOffset(ctraits, 1032) == (offsetof(avmplus::TraceClass, m_slots_TraceClass) + offsetof(avmplus_TraceClassSlots, m_METHODS_AND_LINES)));
    AvmAssert(getSlotOffset(ctraits, 1033) == (offsetof(avmplus::TraceClass, m_slots_TraceClass) + offsetof(avmplus_TraceClassSlots, m_METHODS_AND_LINES_WITH_ARGS)));
    AvmAssert(getSlotOffset(ctraits, 1034) == (offsetof(avmplus::TraceClass, m_slots_TraceClass) + offsetof(avmplus_TraceClassSlots, m_FILE)));
    AvmAssert(getSlotOffset(ctraits, 1035) == (offsetof(avmplus::TraceClass, m_slots_TraceClass) + offsetof(avmplus_TraceClassSlots, m_LISTENER)));
    AvmAssert(getMethodIndex(ctraits, 1036) == 5); // setLevel
    AvmAssert(getMethodIndex(ctraits, 1037) == 6); // getLevel
    AvmAssert(getMethodIndex(ctraits, 1038) == 7); // setListener
    AvmAssert(getMethodIndex(ctraits, 1039) == 8); // getListener
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_WorkerStateClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::WorkerStateClass, m_slots_WorkerStateClass) == kSlotsOffset_avmplus_WorkerStateClass);
    MMGC_STATIC_ASSERT(offsetof(avmplus::WorkerStateClass, m_slots_WorkerStateClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::WorkerStateClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(ctraits, 1054) == (offsetof(avmplus::WorkerStateClass, m_slots_WorkerStateClass) + offsetof(avmplus_WorkerStateClassSlots, m_NEW)));
    AvmAssert(getSlotOffset(ctraits, 1055) == (offsetof(avmplus::WorkerStateClass, m_slots_WorkerStateClass) + offsetof(avmplus_WorkerStateClassSlots, m_RUNNING)));
    AvmAssert(getSlotOffset(ctraits, 1056) == (offsetof(avmplus::WorkerStateClass, m_slots_WorkerStateClass) + offsetof(avmplus_WorkerStateClassSlots, m_TERMINATED)));
    AvmAssert(getSlotOffset(ctraits, 1057) == (offsetof(avmplus::WorkerStateClass, m_slots_WorkerStateClass) + offsetof(avmplus_WorkerStateClassSlots, m_FAILED)));
    AvmAssert(getSlotOffset(ctraits, 1058) == (offsetof(avmplus::WorkerStateClass, m_slots_WorkerStateClass) + offsetof(avmplus_WorkerStateClassSlots, m_ABORTED)));
    AvmAssert(getSlotOffset(ctraits, 1059) == (offsetof(avmplus::WorkerStateClass, m_slots_WorkerStateClass) + offsetof(avmplus_WorkerStateClassSlots, m_EXCEPTION)));
    AvmAssert(getMethodIndex(ctraits, 1060) == 5); // code
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmshell_ShellWorkerClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmshell::ShellWorkerClass, m_slots_ShellWorkerClass) == kSlotsOffset_avmshell_ShellWorkerClass);
    MMGC_STATIC_ASSERT(offsetof(avmshell::ShellWorkerClass, m_slots_ShellWorkerClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmshell::ShellWorkerClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(ctraits, 1066) == (offsetof(avmshell::ShellWorkerClass, m_slots_ShellWorkerClass) + offsetof(avmshell_ShellWorkerClassSlots, m_private_m_current)));
    AvmAssert(getGetterIndex(ctraits, 1064) == 5); // current
    AvmAssert(getMethodIndex(ctraits, 1065) == 7); // pr
    MMGC_STATIC_ASSERT(offsetof(avmshell::ShellWorkerObject, m_slots_ShellWorkerObject) == kSlotsOffset_avmshell_ShellWorkerObject);
    MMGC_STATIC_ASSERT(offsetof(avmshell::ShellWorkerObject, m_slots_ShellWorkerObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmshell::ShellWorkerObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(itraits, 1074) == (offsetof(avmshell::ShellWorkerObject, m_slots_ShellWorkerObject) + offsetof(avmshell_ShellWorkerObjectSlots, m_private_m_byteCode)));
    AvmAssert(getGetterIndex(itraits, 1067) == 3); // state
    AvmAssert(getMethodIndex(itraits, 1068) == 5); // start
    AvmAssert(getMethodIndex(itraits, 1069) == 6); // isParentOf
    AvmAssert(getGetterIndex(itraits, 1070) == 7); // isPrimordial
    AvmAssert(getMethodIndex(itraits, 1071) == 9); // setSharedProperty
    AvmAssert(getMethodIndex(itraits, 1072) == 10); // getSharedProperty
    AvmAssert(getMethodIndex(itraits, 1073) == 11); // terminate
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_WorkerEventClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::WorkerEventClass, m_slots_WorkerEventClass) == kSlotsOffset_avmplus_WorkerEventClass);
    MMGC_STATIC_ASSERT(offsetof(avmplus::WorkerEventClass, m_slots_WorkerEventClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::WorkerEventClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(ctraits, 1079) == (offsetof(avmplus::WorkerEventClass, m_slots_WorkerEventClass) + offsetof(avmplus_WorkerEventClassSlots, m_WORKER_STATE)));
    MMGC_STATIC_ASSERT(offsetof(avmplus::WorkerEventObject, m_slots_WorkerEventObject) == kSlotsOffset_avmplus_WorkerEventObject);
    MMGC_STATIC_ASSERT(offsetof(avmplus::WorkerEventObject, m_slots_WorkerEventObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::WorkerEventObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(itraits, 1083) == (offsetof(avmplus::WorkerEventObject, m_slots_WorkerEventObject) + offsetof(avmplus_WorkerEventObjectSlots, m_private_m_previousState)));
    AvmAssert(getSlotOffset(itraits, 1084) == (offsetof(avmplus::WorkerEventObject, m_slots_WorkerEventObject) + offsetof(avmplus_WorkerEventObjectSlots, m_private_m_currentState)));
    AvmAssert(getSlotOffset(itraits, 1085) == (offsetof(avmplus::WorkerEventObject, m_slots_WorkerEventObject) + offsetof(avmplus_WorkerEventObjectSlots, m_flash_system_m_target)));
    AvmAssert(getGetterIndex(itraits, 1080) == 3); // currentState
    AvmAssert(getGetterIndex(itraits, 1081) == 5); // previousState
    AvmAssert(getGetterIndex(itraits, 1082) == 7); // target
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmshell_ShellWorkerDomainClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmshell::ShellWorkerDomainClass, m_slots_ShellWorkerDomainClass) == kSlotsOffset_avmshell_ShellWorkerDomainClass);
    MMGC_STATIC_ASSERT(offsetof(avmshell::ShellWorkerDomainClass, m_slots_ShellWorkerDomainClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmshell::ShellWorkerDomainClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(ctraits, 1092) == (offsetof(avmshell::ShellWorkerDomainClass, m_slots_ShellWorkerDomainClass) + offsetof(avmshell_ShellWorkerDomainClassSlots, m_private_m_current)));
    AvmAssert(getGetterIndex(ctraits, 1064) == 5); // current
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_SystemClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::SystemClass, m_slots_SystemClass) == kSlotsOffset_avmplus_SystemClass);
    MMGC_STATIC_ASSERT(offsetof(avmplus::SystemClass, m_slots_SystemClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::SystemClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(ctraits, 1108) == (offsetof(avmplus::SystemClass, m_slots_SystemClass) + offsetof(avmplus_SystemClassSlots, m_private__useCodePage)));
    AvmAssert(getMethodIndex(ctraits, 1109) == 5); // setClipboard
    AvmAssert(getGetterIndex(ctraits, 304) == 6); // totalMemory
    AvmAssert(getGetterIndex(ctraits, 1110) == 8); // totalMemoryNumber
    AvmAssert(getGetterIndex(ctraits, 305) == 10); // freeMemory
    AvmAssert(getGetterIndex(ctraits, 306) == 12); // privateMemory
    AvmAssert(getGetterIndex(ctraits, 1111) == 14); // useCodePage
    AvmAssert(getSetterIndex(ctraits, 1111) == 15); // useCodePage
    AvmAssert(getGetterIndex(ctraits, 1112) == 16); // vmVersion
    AvmAssert(getMethodIndex(ctraits, 1113) == 18); // pause
    AvmAssert(getMethodIndex(ctraits, 1114) == 19); // resume
    AvmAssert(getMethodIndex(ctraits, 170) == 20); // exit
    AvmAssert(getMethodIndex(ctraits, 1115) == 21); // gc
    AvmAssert(getMethodIndex(ctraits, 328) == 22); // disposeXML
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_ScriptTimeoutErrorClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_StackOverflowErrorClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_InvalidSWFErrorClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_SQLErrorOperationClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass) == kSlotsOffset_avmplus_SQLErrorOperationClass);
    MMGC_STATIC_ASSERT(offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::SQLErrorOperationClass) <= 0xFFFF);
    AvmAssert(getSlotOffset(ctraits, 1142) == (offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass) + offsetof(avmplus_SQLErrorOperationClassSlots, m_ANALYZE)));
    AvmAssert(getSlotOffset(ctraits, 1143) == (offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass) + offsetof(avmplus_SQLErrorOperationClassSlots, m_ATTACH)));
    AvmAssert(getSlotOffset(ctraits, 1144) == (offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass) + offsetof(avmplus_SQLErrorOperationClassSlots, m_BEGIN)));
    AvmAssert(getSlotOffset(ctraits, 1145) == (offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass) + offsetof(avmplus_SQLErrorOperationClassSlots, m_CLOSE)));
    AvmAssert(getSlotOffset(ctraits, 1146) == (offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass) + offsetof(avmplus_SQLErrorOperationClassSlots, m_COMMIT)));
    AvmAssert(getSlotOffset(ctraits, 1147) == (offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass) + offsetof(avmplus_SQLErrorOperationClassSlots, m_COMPACT)));
    AvmAssert(getSlotOffset(ctraits, 1148) == (offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass) + offsetof(avmplus_SQLErrorOperationClassSlots, m_DEANALYZE)));
    AvmAssert(getSlotOffset(ctraits, 1149) == (offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass) + offsetof(avmplus_SQLErrorOperationClassSlots, m_DETACH)));
    AvmAssert(getSlotOffset(ctraits, 1150) == (offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass) + offsetof(avmplus_SQLErrorOperationClassSlots, m_EXECUTE)));
    AvmAssert(getSlotOffset(ctraits, 1151) == (offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass) + offsetof(avmplus_SQLErrorOperationClassSlots, m_OPEN)));
    AvmAssert(getSlotOffset(ctraits, 1152) == (offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass) + offsetof(avmplus_SQLErrorOperationClassSlots, m_REENCRYPT)));
    AvmAssert(getSlotOffset(ctraits, 1153) == (offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass) + offsetof(avmplus_SQLErrorOperationClassSlots, m_RELEASE_SAVEPOINT)));
    AvmAssert(getSlotOffset(ctraits, 1154) == (offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass) + offsetof(avmplus_SQLErrorOperationClassSlots, m_ROLLBACK)));
    AvmAssert(getSlotOffset(ctraits, 1155) == (offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass) + offsetof(avmplus_SQLErrorOperationClassSlots, m_ROLLBACK_TO_SAVEPOINT)));
    AvmAssert(getSlotOffset(ctraits, 1156) == (offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass) + offsetof(avmplus_SQLErrorOperationClassSlots, m_SCHEMA)));
    AvmAssert(getSlotOffset(ctraits, 1157) == (offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass) + offsetof(avmplus_SQLErrorOperationClassSlots, m_SET_SAVEPOINT)));
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_SQLErrorClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::SQLErrorObject, m_slots_SQLErrorObject) == kSlotsOffset_avmplus_SQLErrorObject);
    MMGC_STATIC_ASSERT(offsetof(avmplus::SQLErrorObject, m_slots_SQLErrorObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::SQLErrorObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(itraits, 1164) == (offsetof(avmplus::SQLErrorObject, m_slots_SQLErrorObject) + offsetof(avmplus_SQLErrorObjectSlots, m_private__operation)));
    AvmAssert(getSlotOffset(itraits, 1165) == (offsetof(avmplus::SQLErrorObject, m_slots_SQLErrorObject) + offsetof(avmplus_SQLErrorObjectSlots, m_private__details)));
    AvmAssert(getSlotOffset(itraits, 1166) == (offsetof(avmplus::SQLErrorObject, m_slots_SQLErrorObject) + offsetof(avmplus_SQLErrorObjectSlots, m_private__detailID)));
    AvmAssert(getSlotOffset(itraits, 1167) == (offsetof(avmplus::SQLErrorObject, m_slots_SQLErrorObject) + offsetof(avmplus_SQLErrorObjectSlots, m_private__detailArguments)));
    AvmAssert(getGetterIndex(itraits, 1168) == 6); // operation
    AvmAssert(getGetterIndex(itraits, 1169) == 8); // details
    AvmAssert(getGetterIndex(itraits, 1170) == 10); // detailID
    AvmAssert(getGetterIndex(itraits, 1171) == 12); // detailArguments
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_DRMManagerErrorClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::DRMManagerErrorObject, m_slots_DRMManagerErrorObject) == kSlotsOffset_avmplus_DRMManagerErrorObject);
    MMGC_STATIC_ASSERT(offsetof(avmplus::DRMManagerErrorObject, m_slots_DRMManagerErrorObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::DRMManagerErrorObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(itraits, 1175) == (offsetof(avmplus::DRMManagerErrorObject, m_slots_DRMManagerErrorObject) + offsetof(avmplus_DRMManagerErrorObjectSlots, m_private__subErrorID)));
    AvmAssert(getGetterIndex(itraits, 1176) == 6); // subErrorID
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_NewObjectSampleClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::NewObjectSampleObject, m_slots_NewObjectSampleObject) == kSlotsOffset_avmplus_NewObjectSampleObject);
    MMGC_STATIC_ASSERT(offsetof(avmplus::NewObjectSampleObject, m_slots_NewObjectSampleObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::NewObjectSampleObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(itraits, 1178) == (offsetof(avmplus::NewObjectSampleObject, m_slots_NewObjectSampleObject) + offsetof(avmplus_NewObjectSampleObjectSlots, m_id)));
    AvmAssert(getSlotOffset(itraits, 1179) == (offsetof(avmplus::NewObjectSampleObject, m_slots_NewObjectSampleObject) + offsetof(avmplus_NewObjectSampleObjectSlots, m_type)));
    AvmAssert(getGetterIndex(itraits, 1180) == 3); // object
    AvmAssert(getGetterIndex(itraits, 1181) == 5); // size
}
REALLY_INLINE void SlotOffsetsAndAsserts::check_avmplus_DeleteObjectSampleClass(Traits* ctraits, Traits* itraits)
{
    (void)ctraits; (void)itraits;
    MMGC_STATIC_ASSERT(offsetof(avmplus::DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) == kSlotsOffset_avmplus_DeleteObjectSampleObject);
    MMGC_STATIC_ASSERT(offsetof(avmplus::DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) <= 0xFFFF);
    MMGC_STATIC_ASSERT(sizeof(avmplus::DeleteObjectSampleObject) <= 0xFFFF);
    AvmAssert(getSlotOffset(itraits, 1178) == (offsetof(avmplus::DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) + offsetof(avmplus_DeleteObjectSampleObjectSlots, m_id)));
    AvmAssert(getSlotOffset(itraits, 1181) == (offsetof(avmplus::DeleteObjectSampleObject, m_slots_DeleteObjectSampleObject) + offsetof(avmplus_DeleteObjectSampleObjectSlots, m_size)));
}
#endif // DEBUG


AVMTHUNK_BEGIN_NATIVE_TABLES(shell_toplevel)

    AVMTHUNK_BEGIN_NATIVE_METHODS(shell_toplevel)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_C_stdio2__rename2, ::avmshell::CStdioClass::rename2)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EDOM_get, avmshell::CErrnoClass::get_EDOM)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EILSEQ_get, avmshell::CErrnoClass::get_EILSEQ)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ERANGE_get, avmshell::CErrnoClass::get_ERANGE)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EPERM_get, avmshell::CErrnoClass::get_EPERM)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENOENT_get, avmshell::CErrnoClass::get_ENOENT)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ESRCH_get, avmshell::CErrnoClass::get_ESRCH)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EINTR_get, avmshell::CErrnoClass::get_EINTR)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EIO_get, avmshell::CErrnoClass::get_EIO)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENXIO_get, avmshell::CErrnoClass::get_ENXIO)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_E2BIG_get, avmshell::CErrnoClass::get_E2BIG)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENOEXEC_get, avmshell::CErrnoClass::get_ENOEXEC)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EBADF_get, avmshell::CErrnoClass::get_EBADF)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ECHILD_get, avmshell::CErrnoClass::get_ECHILD)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EAGAIN_get, avmshell::CErrnoClass::get_EAGAIN)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENOMEM_get, avmshell::CErrnoClass::get_ENOMEM)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EACCES_get, avmshell::CErrnoClass::get_EACCES)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EFAULT_get, avmshell::CErrnoClass::get_EFAULT)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EBUSY_get, avmshell::CErrnoClass::get_EBUSY)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EEXIST_get, avmshell::CErrnoClass::get_EEXIST)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EXDEV_get, avmshell::CErrnoClass::get_EXDEV)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENODEV_get, avmshell::CErrnoClass::get_ENODEV)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENOTDIR_get, avmshell::CErrnoClass::get_ENOTDIR)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EISDIR_get, avmshell::CErrnoClass::get_EISDIR)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EINVAL_get, avmshell::CErrnoClass::get_EINVAL)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENFILE_get, avmshell::CErrnoClass::get_ENFILE)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EMFILE_get, avmshell::CErrnoClass::get_EMFILE)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENOTTY_get, avmshell::CErrnoClass::get_ENOTTY)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EFBIG_get, avmshell::CErrnoClass::get_EFBIG)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENOSPC_get, avmshell::CErrnoClass::get_ENOSPC)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ESPIPE_get, avmshell::CErrnoClass::get_ESPIPE)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EROFS_get, avmshell::CErrnoClass::get_EROFS)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EMLINK_get, avmshell::CErrnoClass::get_EMLINK)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EPIPE_get, avmshell::CErrnoClass::get_EPIPE)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EDEADLK_get, avmshell::CErrnoClass::get_EDEADLK)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENAMETOOLONG_get, avmshell::CErrnoClass::get_ENAMETOOLONG)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENOLCK_get, avmshell::CErrnoClass::get_ENOLCK)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENOSYS_get, avmshell::CErrnoClass::get_ENOSYS)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENOTEMPTY_get, avmshell::CErrnoClass::get_ENOTEMPTY)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EWOULDBLOCK_get, avmshell::CErrnoClass::get_EWOULDBLOCK)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EINPROGRESS_get, avmshell::CErrnoClass::get_EINPROGRESS)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EALREADY_get, avmshell::CErrnoClass::get_EALREADY)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EDESTADDRREQ_get, avmshell::CErrnoClass::get_EDESTADDRREQ)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EMSGSIZE_get, avmshell::CErrnoClass::get_EMSGSIZE)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EPROTOTYPE_get, avmshell::CErrnoClass::get_EPROTOTYPE)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENOPROTOOPT_get, avmshell::CErrnoClass::get_ENOPROTOOPT)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EADDRINUSE_get, avmshell::CErrnoClass::get_EADDRINUSE)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EADDRNOTAVAIL_get, avmshell::CErrnoClass::get_EADDRNOTAVAIL)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENETDOWN_get, avmshell::CErrnoClass::get_ENETDOWN)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENETUNREACH_get, avmshell::CErrnoClass::get_ENETUNREACH)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENETRESET_get, avmshell::CErrnoClass::get_ENETRESET)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ECONNABORTED_get, avmshell::CErrnoClass::get_ECONNABORTED)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ECONNRESET_get, avmshell::CErrnoClass::get_ECONNRESET)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENOBUFS_get, avmshell::CErrnoClass::get_ENOBUFS)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EISCONN_get, avmshell::CErrnoClass::get_EISCONN)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ENOTCONN_get, avmshell::CErrnoClass::get_ENOTCONN)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ESHUTDOWN_get, avmshell::CErrnoClass::get_ESHUTDOWN)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ETOOMANYREFS_get, avmshell::CErrnoClass::get_ETOOMANYREFS)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ETIMEDOUT_get, avmshell::CErrnoClass::get_ETIMEDOUT)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ECONNREFUSED_get, avmshell::CErrnoClass::get_ECONNREFUSED)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_ELOOP_get, avmshell::CErrnoClass::get_ELOOP)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EHOSTDOWN_get, avmshell::CErrnoClass::get_EHOSTDOWN)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_EHOSTUNREACH_get, avmshell::CErrnoClass::get_EHOSTUNREACH)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_GetErrno, avmshell::CErrnoClass::GetErrno)
        AVMTHUNK_NATIVE_METHOD(C_errno___errno_SetErrno, avmshell::CErrnoClass::SetErrno)
        AVMTHUNK_NATIVE_METHOD(C_stdlib___stdlib_EXIT_SUCCESS_get, avmshell::CStdlibClass::get_EXIT_SUCCESS)
        AVMTHUNK_NATIVE_METHOD(C_stdlib___stdlib_EXIT_FAILURE_get, avmshell::CStdlibClass::get_EXIT_FAILURE)
        AVMTHUNK_NATIVE_METHOD(C_stdlib___stdlib_abort, avmshell::CStdlibClass::abort)
        AVMTHUNK_NATIVE_METHOD(C_stdlib___stdlib_exit, avmshell::CStdlibClass::exit)
        AVMTHUNK_NATIVE_METHOD(C_stdlib___stdlib_getenv, avmshell::CStdlibClass::getenv)
        AVMTHUNK_NATIVE_METHOD(C_stdlib___stdlib_setenv, avmshell::CStdlibClass::setenv)
        AVMTHUNK_NATIVE_METHOD(C_stdlib___stdlib_unsetenv, avmshell::CStdlibClass::unsetenv)
        AVMTHUNK_NATIVE_METHOD(C_stdlib___stdlib_realpath, avmshell::CStdlibClass::realpath)
        AVMTHUNK_NATIVE_METHOD(C_stdlib___stdlib___system, avmshell::CStdlibClass::__system)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_F_OK_get, avmshell::CUnistdClass::get_F_OK)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_X_OK_get, avmshell::CUnistdClass::get_X_OK)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_W_OK_get, avmshell::CUnistdClass::get_W_OK)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_R_OK_get, avmshell::CUnistdClass::get_R_OK)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IFMT_get, avmshell::CUnistdClass::get_S_IFMT)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IFIFO_get, avmshell::CUnistdClass::get_S_IFIFO)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IFCHR_get, avmshell::CUnistdClass::get_S_IFCHR)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IFDIR_get, avmshell::CUnistdClass::get_S_IFDIR)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IFBLK_get, avmshell::CUnistdClass::get_S_IFBLK)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IFREG_get, avmshell::CUnistdClass::get_S_IFREG)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IFLNK_get, avmshell::CUnistdClass::get_S_IFLNK)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IFSOCK_get, avmshell::CUnistdClass::get_S_IFSOCK)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IRWXU_get, avmshell::CUnistdClass::get_S_IRWXU)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IRUSR_get, avmshell::CUnistdClass::get_S_IRUSR)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IWUSR_get, avmshell::CUnistdClass::get_S_IWUSR)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IXUSR_get, avmshell::CUnistdClass::get_S_IXUSR)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IRWXG_get, avmshell::CUnistdClass::get_S_IRWXG)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IRGRP_get, avmshell::CUnistdClass::get_S_IRGRP)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IWGRP_get, avmshell::CUnistdClass::get_S_IWGRP)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IXGRP_get, avmshell::CUnistdClass::get_S_IXGRP)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IRWXO_get, avmshell::CUnistdClass::get_S_IRWXO)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IROTH_get, avmshell::CUnistdClass::get_S_IROTH)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IWOTH_get, avmshell::CUnistdClass::get_S_IWOTH)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IXOTH_get, avmshell::CUnistdClass::get_S_IXOTH)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IREAD_get, avmshell::CUnistdClass::get_S_IREAD)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IWRITE_get, avmshell::CUnistdClass::get_S_IWRITE)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_S_IEXEC_get, avmshell::CUnistdClass::get_S_IEXEC)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_access, avmshell::CUnistdClass::access)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_chdir, avmshell::CUnistdClass::chdir)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_chmod, avmshell::CUnistdClass::chmod)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_getcwd, avmshell::CUnistdClass::getcwd)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_gethostname, avmshell::CUnistdClass::gethostname)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_getlogin, avmshell::CUnistdClass::getlogin)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_getpid, avmshell::CUnistdClass::getpid)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_mkdir, avmshell::CUnistdClass::mkdir)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_rmdir, avmshell::CUnistdClass::rmdir)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_sleep, avmshell::CUnistdClass::sleep)
        AVMTHUNK_NATIVE_METHOD(C_unistd___unistd_unlink, avmshell::CUnistdClass::unlink)
        AVMTHUNK_NATIVE_METHOD(C_string___string_strerror, avmshell::CStringClass::strerror)
        AVMTHUNK_NATIVE_METHOD(C_string___string_strlen, avmshell::CStringClass::strlen)
        AVMTHUNK_NATIVE_METHOD(C_stdio___stdio_FILENAME_MAX_get, avmshell::CStdioClass::get_FILENAME_MAX)
        AVMTHUNK_NATIVE_METHOD(C_stdio___stdio_PATH_MAX_get, avmshell::CStdioClass::get_PATH_MAX)
        AVMTHUNK_NATIVE_METHOD(C_stdio___stdio_NONBLOCKING_DISABLE_get, avmshell::CStdioClass::get_NONBLOCKING_DISABLE)
        AVMTHUNK_NATIVE_METHOD(C_stdio___stdio_NONBLOCKING_ENABLE_get, avmshell::CStdioClass::get_NONBLOCKING_ENABLE)
        AVMTHUNK_NATIVE_METHOD(C_stdio___stdio_O_TEXT_get, avmshell::CStdioClass::get_O_TEXT)
        AVMTHUNK_NATIVE_METHOD(C_stdio___stdio_O_BINARY_get, avmshell::CStdioClass::get_O_BINARY)
        AVMTHUNK_NATIVE_METHOD(C_stdio___stdio_remove, avmshell::CStdioClass::remove)
        AVMTHUNK_NATIVE_METHOD(C_stdio___stdio_rename, avmshell::CStdioClass::rename)
        AVMTHUNK_NATIVE_METHOD(C_stdio___stdio_con_stream_mode, avmshell::CStdioClass::con_stream_mode)
        AVMTHUNK_NATIVE_METHOD(C_stdio___stdio_con_trans_mode, avmshell::CStdioClass::con_trans_mode)
        AVMTHUNK_NATIVE_METHOD(C_stdio___stdio_kbhit, avmshell::CStdioClass::kbhit)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SOCK_RAW_get, avmshell::CSocketClass::get_SOCK_RAW)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SOCK_STREAM_get, avmshell::CSocketClass::get_SOCK_STREAM)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SOCK_DGRAM_get, avmshell::CSocketClass::get_SOCK_DGRAM)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SO_ACCEPTCONN_get, avmshell::CSocketClass::get_SO_ACCEPTCONN)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SO_BROADCAST_get, avmshell::CSocketClass::get_SO_BROADCAST)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SO_DONTROUTE_get, avmshell::CSocketClass::get_SO_DONTROUTE)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SO_KEEPALIVE_get, avmshell::CSocketClass::get_SO_KEEPALIVE)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SO_OOBINLINE_get, avmshell::CSocketClass::get_SO_OOBINLINE)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SO_RCVBUF_get, avmshell::CSocketClass::get_SO_RCVBUF)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SO_RCVTIMEO_get, avmshell::CSocketClass::get_SO_RCVTIMEO)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SO_REUSEADDR_get, avmshell::CSocketClass::get_SO_REUSEADDR)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SO_SNDBUF_get, avmshell::CSocketClass::get_SO_SNDBUF)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SO_SNDTIMEO_get, avmshell::CSocketClass::get_SO_SNDTIMEO)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SO_TYPE_get, avmshell::CSocketClass::get_SO_TYPE)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_MSG_CTRUNC_get, avmshell::CSocketClass::get_MSG_CTRUNC)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_MSG_DONTROUTE_get, avmshell::CSocketClass::get_MSG_DONTROUTE)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_MSG_OOB_get, avmshell::CSocketClass::get_MSG_OOB)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_MSG_PEEK_get, avmshell::CSocketClass::get_MSG_PEEK)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_MSG_TRUNC_get, avmshell::CSocketClass::get_MSG_TRUNC)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_MSG_WAITALL_get, avmshell::CSocketClass::get_MSG_WAITALL)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_MSG_DONTWAIT_get, avmshell::CSocketClass::get_MSG_DONTWAIT)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_AF_INET_get, avmshell::CSocketClass::get_AF_INET)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_AF_INET6_get, avmshell::CSocketClass::get_AF_INET6)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_AF_UNSPEC_get, avmshell::CSocketClass::get_AF_UNSPEC)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SHUT_RD_get, avmshell::CSocketClass::get_SHUT_RD)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SHUT_RDWR_get, avmshell::CSocketClass::get_SHUT_RDWR)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SHUT_WR_get, avmshell::CSocketClass::get_SHUT_WR)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_IPPROTO_IP_get, avmshell::CSocketClass::get_IPPROTO_IP)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_IPPROTO_IPV6_get, avmshell::CSocketClass::get_IPPROTO_IPV6)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_IPPROTO_ICMP_get, avmshell::CSocketClass::get_IPPROTO_ICMP)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_IPPROTO_RAW_get, avmshell::CSocketClass::get_IPPROTO_RAW)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_IPPROTO_TCP_get, avmshell::CSocketClass::get_IPPROTO_TCP)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_IPPROTO_UDP_get, avmshell::CSocketClass::get_IPPROTO_UDP)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket_SOMAXCONN_get, avmshell::CSocketClass::get_SOMAXCONN)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket___gethostbyaddr, avmshell::CSocketClass::__gethostbyaddr)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket___gethostbyname, avmshell::CSocketClass::__gethostbyname)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket___getpeername, avmshell::CSocketClass::__getpeername)
        AVMTHUNK_NATIVE_METHOD(C_socket___socket___getsockname, avmshell::CSocketClass::__getsockname)
        AVMTHUNK_NATIVE_METHOD(shell_Program_private_getArgv, avmshell::ProgramClass::getArgv)
        AVMTHUNK_NATIVE_METHOD(shell_Program_private_popenRead, avmshell::ProgramClass::popenRead)
        AVMTHUNK_NATIVE_METHOD(shell_Program_apiVersion_get, avmshell::ProgramClass::get_apiVersion)
        AVMTHUNK_NATIVE_METHOD(shell_Program_programFilename_get, avmshell::ProgramClass::get_programFilename)
        AVMTHUNK_NATIVE_METHOD(shell_Program_swfVersion_get, avmshell::ProgramClass::get_swfVersion)
        AVMTHUNK_NATIVE_METHOD(shell_Program_totalMemory_get, avmshell::ProgramClass::get_totalMemory)
        AVMTHUNK_NATIVE_METHOD(shell_Program_freeMemory_get, avmshell::ProgramClass::get_freeMemory)
        AVMTHUNK_NATIVE_METHOD(shell_Program_privateMemory_get, avmshell::ProgramClass::get_privateMemory)
        AVMTHUNK_NATIVE_METHOD(shell_Program_eval, avmshell::ProgramClass::eval)
        AVMTHUNK_NATIVE_METHOD(shell_Program_exec, avmshell::ProgramClass::exec)
        AVMTHUNK_NATIVE_METHOD(shell_Program_exit, avmshell::ProgramClass::exit)
        AVMTHUNK_NATIVE_METHOD(shell_Program_getAvmplusVersion, avmshell::ProgramClass::getAvmplusVersion)
        AVMTHUNK_NATIVE_METHOD(shell_Program_getEnviron, avmshell::ProgramClass::getEnviron)
        AVMTHUNK_NATIVE_METHOD(shell_Program_getFeatures, avmshell::ProgramClass::getFeatures)
        AVMTHUNK_NATIVE_METHOD(shell_Program_getNanosecondTimer, avmshell::ProgramClass::getNanosecondTimer)
        AVMTHUNK_NATIVE_METHOD(shell_Program_getRunmode, avmshell::ProgramClass::getRunmode)
        AVMTHUNK_NATIVE_METHOD(shell_Program_getTimer, avmshell::ProgramClass::getTimer)
        AVMTHUNK_NATIVE_METHOD(shell_Program_readLine, avmshell::ProgramClass::readLine)
        AVMTHUNK_NATIVE_METHOD(shell_Program_sleep, avmshell::ProgramClass::sleep)
        AVMTHUNK_NATIVE_METHOD(shell_Program_trace, avmshell::ProgramClass::trace)
        AVMTHUNK_NATIVE_METHOD(shell_Program_write, avmshell::ProgramClass::write)
        AVMTHUNK_NATIVE_METHOD(shell_Program_debugger, avmshell::ProgramClass::debugger)
        AVMTHUNK_NATIVE_METHOD(shell_Program_isDebugger, avmshell::ProgramClass::isDebugger)
        AVMTHUNK_NATIVE_METHOD(shell_Program_forceFullCollection, avmshell::ProgramClass::forceFullCollection)
        AVMTHUNK_NATIVE_METHOD(shell_Program_queueCollection, avmshell::ProgramClass::queueCollection)
        AVMTHUNK_NATIVE_METHOD(shell_Program_pauseForGCIfCollectionImminent, avmshell::ProgramClass::pauseForGCIfCollectionImminent)
        AVMTHUNK_NATIVE_METHOD(shell_Program_disposeXML, avmshell::ProgramClass::disposeXML)
        AVMTHUNK_NATIVE_METHOD(shell_Program_isGlobal, avmshell::ProgramClass::isGlobal)
        AVMTHUNK_NATIVE_METHOD(shell_Program_is64bit, avmshell::ProgramClass::is64bit)
        AVMTHUNK_NATIVE_METHOD(shell_Program_isIntptr, avmshell::ProgramClass::isIntptr)
        AVMTHUNK_NATIVE_METHOD(shell_Program_canonicalizeNumber, avmshell::ProgramClass::canonicalizeNumber)
        AVMTHUNK_NATIVE_METHOD(shell_Program_deopt, avmshell::ProgramClass::deopt)
        AVMTHUNK_NATIVE_METHOD(shell_Program_runInSafepoint, avmshell::ProgramClass::runInSafepoint)
        AVMTHUNK_NATIVE_METHOD(shell_Domain_currentDomain_get, avmplus::DomainClass::get_currentDomain)
        AVMTHUNK_NATIVE_METHOD(shell_Domain_MIN_DOMAIN_MEMORY_LENGTH_get, avmplus::DomainClass::get_MIN_DOMAIN_MEMORY_LENGTH)
        AVMTHUNK_NATIVE_METHOD(shell_Domain_private_init, avmplus::DomainObject::init)
        AVMTHUNK_NATIVE_METHOD(shell_Domain_loadBytes, avmplus::DomainObject::loadBytes)
        AVMTHUNK_NATIVE_METHOD(shell_Domain_getClass, avmplus::DomainObject::getClass)
        AVMTHUNK_NATIVE_METHOD(shell_Domain_domainMemory_get, avmplus::DomainObject::get_domainMemory)
        AVMTHUNK_NATIVE_METHOD(shell_Domain_domainMemory_set, avmplus::DomainObject::set_domainMemory)
        AVMTHUNK_NATIVE_METHOD(shell_FileIO_exists, avmshell::FileClass::exists)
        AVMTHUNK_NATIVE_METHOD(shell_FileIO_read, avmshell::FileClass::read)
        AVMTHUNK_NATIVE_METHOD(shell_FileIO_write, avmshell::FileClass::write)
        AVMTHUNK_NATIVE_METHOD(shell_FileIO_readByteArray, avmshell::FileClass::readByteArray)
        AVMTHUNK_NATIVE_METHOD(shell_FileIO_writeByteArray, avmshell::FileClass::writeByteArray)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_getMasterString, SamplerScript::getMasterString)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_getSavedThis, SamplerScript::getSavedThis)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_getLexicalScopes, SamplerScript::getLexicalScopes)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_isGetterSetter, SamplerScript::isGetterSetter)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler__getInvocationCount, SamplerScript::_getInvocationCount)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_getSampleCount, SamplerScript::getSampleCount)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler__getSamples, SamplerScript::_getSamples)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_getMemberNames, SamplerScript::getMemberNames)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_getSize, SamplerScript::getSize)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler__setSamplerCallback, SamplerScript::_setSamplerCallback)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_sampleInternalAllocs, SamplerScript::sampleInternalAllocs)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_pauseSampling, SamplerScript::pauseSampling)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_stopSampling, SamplerScript::stopSampling)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_startSampling, SamplerScript::startSampling)
        AVMTHUNK_NATIVE_FUNCTION(native_script_function_flash_sampler_clearSamples, SamplerScript::clearSamples)
        AVMTHUNK_NATIVE_METHOD(flash_trace_Trace_setLevel, avmplus::TraceClass::setLevel)
        AVMTHUNK_NATIVE_METHOD(flash_trace_Trace_getLevel, avmplus::TraceClass::getLevel)
        AVMTHUNK_NATIVE_METHOD(flash_trace_Trace_setListener, avmplus::TraceClass::setListener)
        AVMTHUNK_NATIVE_METHOD(flash_trace_Trace_getListener, avmplus::TraceClass::getListener)
        AVMTHUNK_NATIVE_METHOD(flash_system_Worker_pr, avmshell::ShellWorkerClass::pr)
        AVMTHUNK_NATIVE_METHOD(flash_system_Worker_state_get, avmshell::ShellWorkerObject::get_state)
        AVMTHUNK_NATIVE_METHOD(flash_system_Worker_start, avmshell::ShellWorkerObject::start)
        AVMTHUNK_NATIVE_METHOD(flash_system_Worker_isParentOf, avmshell::ShellWorkerObject::isParentOf)
        AVMTHUNK_NATIVE_METHOD(flash_system_Worker_isPrimordial_get, avmshell::ShellWorkerObject::get_isPrimordial)
        AVMTHUNK_NATIVE_METHOD(flash_system_Worker_setSharedProperty, avmshell::ShellWorkerObject::setSharedProperty)
        AVMTHUNK_NATIVE_METHOD(flash_system_Worker_getSharedProperty, avmshell::ShellWorkerObject::getSharedProperty)
        AVMTHUNK_NATIVE_METHOD(flash_system_Worker_terminate, avmshell::ShellWorkerObject::terminate)
        AVMTHUNK_NATIVE_METHOD(flash_system_WorkerDomain_private_createWorkerFromByteArrayInternal, avmshell::ShellWorkerDomainObject::createWorkerFromByteArrayInternal)
        AVMTHUNK_NATIVE_METHOD(flash_system_WorkerDomain_listWorkers, avmshell::ShellWorkerDomainObject::listWorkers)
        AVMTHUNK_NATIVE_METHOD(flash_sampler_NewObjectSample_object_get, avmplus::NewObjectSampleObject::get_object)
        AVMTHUNK_NATIVE_METHOD(flash_sampler_NewObjectSample_size_get, avmplus::NewObjectSampleObject::get_size)
    AVMTHUNK_END_NATIVE_METHODS()

    AVMTHUNK_BEGIN_NATIVE_CLASSES(shell_toplevel)
        AVMTHUNK_NATIVE_CLASS(abcclass_C_errno___errno, CErrnoClass, avmshell::CErrnoClass, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_CErrnoClass, avmplus::__errnoObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus___errnoObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_C_errno_ErrorNumber, ErrorNumberClass, avmplus::ErrorNumberClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_ErrorNumberClass, avmplus::ErrorNumberObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_ErrorNumberObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_C_errno_CError, CErrorClass, avmplus::CErrorClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_CErrorClass, avmplus::CErrorObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_CErrorObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_C_stdlib___stdlib, CStdlibClass, avmshell::CStdlibClass, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_CStdlibClass, avmplus::__stdlibObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus___stdlibObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_C_unistd___unistd, CUnistdClass, avmshell::CUnistdClass, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_CUnistdClass, avmplus::__unistdObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus___unistdObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_C_string___string, CStringClass, avmshell::CStringClass, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_CStringClass, avmplus::__stringObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus___stringObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_C_stdio___stdio, CStdioClass, avmshell::CStdioClass, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_CStdioClass, avmplus::__stdioObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus___stdioObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_C_socket___socket, CSocketClass, avmshell::CSocketClass, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_CSocketClass, avmplus::__socketObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus___socketObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_shell_Program, ProgramClass, avmshell::ProgramClass, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_ProgramClass, avmplus::ProgramObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_ProgramObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_shell_Domain, DomainClass, avmplus::DomainClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_DomainClass, avmplus::DomainObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_DomainObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_shell_FileIO, FileClass, avmshell::FileClass, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_FileClass, avmplus::FileIOObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_FileIOObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_shell_Environment, EnvironmentClass, avmplus::EnvironmentClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_EnvironmentClass, avmplus::EnvironmentObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_EnvironmentObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_utils_Endian, EndianClass, avmplus::EndianClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_EndianClass, avmplus::EndianObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_EndianObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_system_Capabilities, CapabilitiesClass, avmplus::CapabilitiesClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_CapabilitiesClass, avmplus::CapabilitiesObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_CapabilitiesObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_StackFrame, StackFrameClass, avmplus::StackFrameClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_StackFrameClass, avmplus::StackFrameObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_StackFrameObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_Sample, SampleClass, avmplus::SampleClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_SampleClass, avmplus::SampleObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_SampleObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_ClassFactory, ClassFactoryClass, avmplus::ClassFactoryClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_ClassFactoryClass, avmplus::ClassFactoryObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_ClassFactoryObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_trace_Trace, TraceClass, avmplus::TraceClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_TraceClass, avmplus::TraceObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_TraceObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_system_WorkerState, WorkerStateClass, avmplus::WorkerStateClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_WorkerStateClass, avmplus::WorkerStateObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_WorkerStateObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_system_Worker, ShellWorkerClass, avmshell::ShellWorkerClass, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_ShellWorkerClass, avmshell::ShellWorkerObject, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_ShellWorkerObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_system_WorkerEvent, WorkerEventClass, avmplus::WorkerEventClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_WorkerEventClass, avmplus::WorkerEventObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_WorkerEventObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_system_WorkerDomain, ShellWorkerDomainClass, avmshell::ShellWorkerDomainClass, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_ShellWorkerDomainClass, avmshell::ShellWorkerDomainObject, SlotOffsetsAndAsserts::kSlotsOffset_avmshell_ShellWorkerDomainObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_system_System, SystemClass, avmplus::SystemClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_SystemClass, avmplus::SystemObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_SystemObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_errors_ScriptTimeoutError, ScriptTimeoutErrorClass, avmplus::ScriptTimeoutErrorClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_ScriptTimeoutErrorClass, avmplus::ScriptTimeoutErrorObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_ScriptTimeoutErrorObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_errors_StackOverflowError, StackOverflowErrorClass, avmplus::StackOverflowErrorClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_StackOverflowErrorClass, avmplus::StackOverflowErrorObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_StackOverflowErrorObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_errors_InvalidSWFError, InvalidSWFErrorClass, avmplus::InvalidSWFErrorClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_InvalidSWFErrorClass, avmplus::InvalidSWFErrorObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_InvalidSWFErrorObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_errors_SQLErrorOperation, SQLErrorOperationClass, avmplus::SQLErrorOperationClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_SQLErrorOperationClass, avmplus::SQLErrorOperationObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_SQLErrorOperationObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_errors_SQLError, SQLErrorClass, avmplus::SQLErrorClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_SQLErrorClass, avmplus::SQLErrorObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_SQLErrorObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_errors_DRMManagerError, DRMManagerErrorClass, avmplus::DRMManagerErrorClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_DRMManagerErrorClass, avmplus::DRMManagerErrorObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_DRMManagerErrorObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_NewObjectSample, NewObjectSampleClass, avmplus::NewObjectSampleClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_NewObjectSampleClass, avmplus::NewObjectSampleObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_NewObjectSampleObject, false, false, false)
        AVMTHUNK_NATIVE_CLASS(abcclass_flash_sampler_DeleteObjectSample, DeleteObjectSampleClass, avmplus::DeleteObjectSampleClass, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_DeleteObjectSampleClass, avmplus::DeleteObjectSampleObject, SlotOffsetsAndAsserts::kSlotsOffset_avmplus_DeleteObjectSampleObject, false, false, false)
    AVMTHUNK_END_NATIVE_CLASSES()

AVMTHUNK_END_NATIVE_TABLES()

AVMTHUNK_DEFINE_NATIVE_INITIALIZER(shell_toplevel)

/* abc */
const uint8_t shell_toplevel_abc_data[26154] = {
  16,   0,  46,   0,   7, 255, 255, 255, 255,  15,   0,   2,   1,   3,   4,   0,
   2,   0,   0,   0,   0,   0,   0, 232,  63, 234,   4,   0,   7,  80, 114, 111,
 103, 114,  97, 109,  15, 114, 101, 100, 116,  97, 109,  97, 114, 105, 110,  46,
  97, 115,  36,  49,   5, 115, 104, 101, 108, 108,   5, 100, 101, 111, 112, 116,
   4, 118, 111, 105, 100,   8, 114, 101,  97, 100,  76, 105, 110, 101,   6,  83,
 116, 114, 105, 110, 103,   8, 103, 101, 116,  84, 105, 109, 101, 114,   4, 117,
 105, 110, 116,   5, 116, 114,  97,  99, 101,   6,  68, 111, 109,  97, 105, 110,
  13,  99, 117, 114, 114, 101, 110, 116,  68, 111, 109,  97, 105, 110,   8, 103,
 101, 116,  67, 108,  97, 115, 115,   5,  67, 108,  97, 115, 115,   8, 100, 101,
  98, 117, 103, 103, 101, 114,   8,  95,  95, 115, 111,  99, 107, 101, 116,   8,
  67,  46, 115, 111,  99, 107, 101, 116,  13,  95,  95, 103, 101, 116, 115, 111,
  99, 107, 110,  97, 109, 101,   3, 105, 110, 116,  13,  95,  95, 103, 101, 116,
 112, 101, 101, 114, 110,  97, 109, 101,  15,  95,  95, 103, 101, 116, 104, 111,
 115, 116,  98, 121, 110,  97, 109, 101,   5,  65, 114, 114,  97, 121,   7,  66,
 111, 111, 108, 101,  97, 110,  15,  95,  95, 103, 101, 116, 104, 111, 115, 116,
  98, 121,  97, 100, 100, 114,   8,  95, 114, 101, 110,  97, 109, 101,  50,   8,
  67,  46, 115, 116, 100, 105, 111,  50,   7,  67,  46, 101, 114, 114, 110, 111,
  17, 101, 110,  97,  98, 108, 101,  84, 104, 114, 111, 119,  67,  69, 114, 114,
 111, 114,   5, 101, 114, 114, 110, 111,   5, 118,  97, 108, 117, 101,  11, 116,
 104, 114, 111, 119,  67,  69, 114, 114, 111, 114,   7,  95,  95, 115, 116, 100,
 105, 111,   7,  67,  46, 115, 116, 100, 105, 111,   5, 107,  98, 104, 105, 116,
  14,  99, 111, 110,  95, 116, 114,  97, 110, 115,  95, 109, 111, 100, 101,  15,
  99, 111, 110,  95, 115, 116, 114, 101,  97, 109,  95, 109, 111, 100, 101,   6,
 114, 101, 110,  97, 109, 101,   6, 114, 101, 109, 111, 118, 101,   1,  45,   1,
 100,   1,  99,   1,  98,   1, 108,   1, 112,   1, 115,   1,  63,   6,  83,  95,
  73,  70,  77,  84,   8,  67,  46, 115, 116, 114, 105, 110, 103,   8,  67,  46,
 117, 110, 105, 115, 116, 100,   7,  83,  95,  73,  70,  82,  69,  71,   7,  83,
  95,  73,  70,  68,  73,  82,   7,  83,  95,  73,  70,  67,  72,  82,   7,  83,
  95,  73,  70,  66,  76,  75,   7,  83,  95,  73,  70,  76,  78,  75,   7,  83,
  95,  73,  70,  73,  70,  79,   8,  83,  95,  73,  70,  83,  79,  67,  75,   8,
  70, 117, 110,  99, 116, 105, 111, 110,   7,  83,  95,  73,  82,  85,  83,  82,
   1, 114,   7,  83,  95,  73,  87,  85,  83,  82,   1, 119,   7,  83,  95,  73,
  88,  85,  83,  82,   1, 120,   7,  83,  95,  73,  82,  71,  82,  80,   7,  83,
  95,  73,  87,  71,  82,  80,   7,  83,  95,  73,  88,  71,  82,  80,   7,  83,
  95,  73,  82,  79,  84,  72,   7,  83,  95,  73,  87,  79,  84,  72,   7,  83,
  95,  73,  88,  79,  84,  72,   4, 106, 111, 105, 110,   4, 109, 111, 100, 101,
   1, 110,   5, 102, 116, 121, 112, 101,   8,  95,  95, 115, 116, 114, 105, 110,
 103,   6, 115, 116, 114, 108, 101, 110,   8, 115, 116, 114, 101, 114, 114, 111,
 114,   8,  95,  95, 117, 110, 105, 115, 116, 100,   6, 117, 110, 108, 105, 110,
 107,   5, 115, 108, 101, 101, 112,   5, 114, 109, 100, 105, 114,   5, 109, 107,
 100, 105, 114,   6, 103, 101, 116, 112, 105, 100,   8, 103, 101, 116, 108, 111,
 103, 105, 110,  11, 103, 101, 116, 104, 111, 115, 116, 110,  97, 109, 101,   6,
 103, 101, 116,  99, 119, 100,   5,  99, 104, 109, 111, 100,   5,  99, 104, 100,
 105, 114,   6,  97,  99,  99, 101, 115, 115,   8,  95,  95, 115, 116, 100, 108,
 105,  98,   8,  67,  46, 115, 116, 100, 108, 105,  98,   8,  95,  95, 115, 121,
 115, 116, 101, 109,   8, 114, 101,  97, 108, 112,  97, 116, 104,   8, 117, 110,
 115, 101, 116, 101, 110, 118,   6, 115, 101, 116, 101, 110, 118,   6, 103, 101,
 116, 101, 110, 118,  12,  69,  88,  73,  84,  95,  83,  85,  67,  67,  69,  83,
  83,   4, 101, 120, 105, 116,   5,  97,  98, 111, 114, 116,  15,  67,  46, 101,
 114, 114, 110, 111,  58,  95,  95, 101, 114, 114, 110, 111,   3, 238, 138, 148,
   4,  69,  68,  79,  77,   6,  69,  73,  76,  83,  69,  81,   6,  69,  82,  65,
  78,  71,  69,   5,  69,  80,  69,  82,  77,   6,  69,  78,  79,  69,  78,  84,
   5,  69,  83,  82,  67,  72,   5,  69,  73,  78,  84,  82,   3,  69,  73,  79,
   5,  69,  78,  88,  73,  79,   5,  69,  50,  66,  73,  71,   7,  69,  78,  79,
  69,  88,  69,  67,   5,  69,  66,  65,  68,  70,   6,  69,  67,  72,  73,  76,
  68,   6,  69,  65,  71,  65,  73,  78,   6,  69,  78,  79,  77,  69,  77,   6,
  69,  65,  67,  67,  69,  83,   6,  69,  70,  65,  85,  76,  84,   5,  69,  66,
  85,  83,  89,   6,  69,  69,  88,  73,  83,  84,   5,  69,  88,  68,  69,  86,
   6,  69,  78,  79,  68,  69,  86,   7,  69,  78,  79,  84,  68,  73,  82,   6,
  69,  73,  83,  68,  73,  82,   6,  69,  73,  78,  86,  65,  76,   6,  69,  78,
  70,  73,  76,  69,   6,  69,  77,  70,  73,  76,  69,   6,  69,  78,  79,  84,
  84,  89,   5,  69,  70,  66,  73,  71,   6,  69,  78,  79,  83,  80,  67,   6,
  69,  83,  80,  73,  80,  69,   5,  69,  82,  79,  70,  83,   6,  69,  77,  76,
  73,  78,  75,   5,  69,  80,  73,  80,  69,   7,  69,  68,  69,  65,  68,  76,
  75,  12,  69,  78,  65,  77,  69,  84,  79,  79,  76,  79,  78,  71,   6,  69,
  78,  79,  76,  67,  75,   6,  69,  78,  79,  83,  89,  83,   9,  69,  78,  79,
  84,  69,  77,  80,  84,  89,  11,  69,  87,  79,  85,  76,  68,  66,  76,  79,
  67,  75,  11,  69,  73,  78,  80,  82,  79,  71,  82,  69,  83,  83,   8,  69,
  65,  76,  82,  69,  65,  68,  89,  12,  69,  68,  69,  83,  84,  65,  68,  68,
  82,  82,  69,  81,   8,  69,  77,  83,  71,  83,  73,  90,  69,  10,  69,  80,
  82,  79,  84,  79,  84,  89,  80,  69,  11,  69,  78,  79,  80,  82,  79,  84,
  79,  79,  80,  84,  10,  69,  65,  68,  68,  82,  73,  78,  85,  83,  69,  13,
  69,  65,  68,  68,  82,  78,  79,  84,  65,  86,  65,  73,  76,   8,  69,  78,
  69,  84,  68,  79,  87,  78,  11,  69,  78,  69,  84,  85,  78,  82,  69,  65,
  67,  72,   9,  69,  78,  69,  84,  82,  69,  83,  69,  84,  12,  69,  67,  79,
  78,  78,  65,  66,  79,  82,  84,  69,  68,  10,  69,  67,  79,  78,  78,  82,
  69,  83,  69,  84,   7,  69,  78,  79,  66,  85,  70,  83,   7,  69,  73,  83,
  67,  79,  78,  78,   8,  69,  78,  79,  84,  67,  79,  78,  78,   9,  69,  83,
  72,  85,  84,  68,  79,  87,  78,  12,  69,  84,  79,  79,  77,  65,  78,  89,
  82,  69,  70,  83,   9,  69,  84,  73,  77,  69,  68,  79,  85,  84,  12,  69,
  67,  79,  78,  78,  82,  69,  70,  85,  83,  69,  68,   5,  69,  76,  79,  79,
  80,   9,  69,  72,  79,  83,  84,  68,  79,  87,  78,  12,  69,  72,  79,  83,
  84,  85,  78,  82,  69,  65,  67,  72,   8,  71, 101, 116,  69, 114, 114, 110,
 111,   8,  83, 101, 116,  69, 114, 114, 110, 111,   7,  95,  95, 101, 114, 114,
 110, 111,   6,  79,  98, 106, 101,  99, 116,  19,  67,  46, 101, 114, 114, 110,
 111,  58,  69, 114, 114, 111, 114,  78, 117, 109,  98, 101, 114,   6,  95, 118,
  97, 108, 117, 101,   7, 118,  97, 108, 117, 101,  79, 102,   8, 116, 111,  83,
 116, 114, 105, 110, 103,  11,  69, 114, 114, 111, 114,  78, 117, 109,  98, 101,
 114,  14,  67,  46, 101, 114, 114, 110, 111,  58,  67,  69, 114, 114, 111, 114,
   9, 112, 114, 111, 116, 111, 116, 121, 112, 101,   5,  69, 114, 114, 111, 114,
   6,  67,  69, 114, 114, 111, 114,   4, 110,  97, 109, 101,   7,  95, 101, 114,
 114, 109,  97, 112,  17,  67,  46, 115, 116, 100, 108, 105,  98,  58,  95,  95,
 115, 116, 100, 108, 105,  98,  12,  69,  88,  73,  84,  95,  70,  65,  73,  76,
  85,  82,  69,  17,  67,  46, 117, 110, 105, 115, 116, 100,  58,  95,  95, 117,
 110, 105, 115, 116, 100,   4,  70,  95,  79,  75,   4,  88,  95,  79,  75,   4,
  87,  95,  79,  75,   4,  82,  95,  79,  75,   7,  83,  95,  73,  82,  87,  88,
  85,   7,  83,  95,  73,  82,  87,  88,  71,   7,  83,  95,  73,  82,  87,  88,
  79,   7,  83,  95,  73,  82,  69,  65,  68,   8,  83,  95,  73,  87,  82,  73,
  84,  69,   7,  83,  95,  73,  69,  88,  69,  67,  17,  67,  46, 115, 116, 114,
 105, 110, 103,  58,  95,  95, 115, 116, 114, 105, 110, 103,  15,  67,  46, 115,
 116, 100, 105, 111,  58,  95,  95, 115, 116, 100, 105, 111,  12,  70,  73,  76,
  69,  78,  65,  77,  69,  95,  77,  65,  88,   8,  80,  65,  84,  72,  95,  77,
  65,  88,  19,  78,  79,  78,  66,  76,  79,  67,  75,  73,  78,  71,  95,  68,
  73,  83,  65,  66,  76,  69,  18,  78,  79,  78,  66,  76,  79,  67,  75,  73,
  78,  71,  95,  69,  78,  65,  66,  76,  69,   6,  79,  95,  84,  69,  88,  84,
   8,  79,  95,  66,  73,  78,  65,  82,  89,  17,  67,  46, 115, 111,  99, 107,
 101, 116,  58,  95,  95, 115, 111,  99, 107, 101, 116,   8,  83,  79,  67,  75,
  95,  82,  65,  87,  11,  83,  79,  67,  75,  95,  83,  84,  82,  69,  65,  77,
  10,  83,  79,  67,  75,  95,  68,  71,  82,  65,  77,  13,  83,  79,  95,  65,
  67,  67,  69,  80,  84,  67,  79,  78,  78,  12,  83,  79,  95,  66,  82,  79,
  65,  68,  67,  65,  83,  84,  12,  83,  79,  95,  68,  79,  78,  84,  82,  79,
  85,  84,  69,  12,  83,  79,  95,  75,  69,  69,  80,  65,  76,  73,  86,  69,
  12,  83,  79,  95,  79,  79,  66,  73,  78,  76,  73,  78,  69,   9,  83,  79,
  95,  82,  67,  86,  66,  85,  70,  11,  83,  79,  95,  82,  67,  86,  84,  73,
  77,  69,  79,  12,  83,  79,  95,  82,  69,  85,  83,  69,  65,  68,  68,  82,
   9,  83,  79,  95,  83,  78,  68,  66,  85,  70,  11,  83,  79,  95,  83,  78,
  68,  84,  73,  77,  69,  79,   7,  83,  79,  95,  84,  89,  80,  69,  10,  77,
  83,  71,  95,  67,  84,  82,  85,  78,  67,  13,  77,  83,  71,  95,  68,  79,
  78,  84,  82,  79,  85,  84,  69,   7,  77,  83,  71,  95,  79,  79,  66,   8,
  77,  83,  71,  95,  80,  69,  69,  75,   9,  77,  83,  71,  95,  84,  82,  85,
  78,  67,  11,  77,  83,  71,  95,  87,  65,  73,  84,  65,  76,  76,  12,  77,
  83,  71,  95,  68,  79,  78,  84,  87,  65,  73,  84,   7,  65,  70,  95,  73,
  78,  69,  84,   8,  65,  70,  95,  73,  78,  69,  84,  54,   9,  65,  70,  95,
  85,  78,  83,  80,  69,  67,   7,  83,  72,  85,  84,  95,  82,  68,   9,  83,
  72,  85,  84,  95,  82,  68,  87,  82,   7,  83,  72,  85,  84,  95,  87,  82,
  10,  73,  80,  80,  82,  79,  84,  79,  95,  73,  80,  12,  73,  80,  80,  82,
  79,  84,  79,  95,  73,  80,  86,  54,  12,  73,  80,  80,  82,  79,  84,  79,
  95,  73,  67,  77,  80,  11,  73,  80,  80,  82,  79,  84,  79,  95,  82,  65,
  87,  11,  73,  80,  80,  82,  79,  84,  79,  95,  84,  67,  80,  11,  73,  80,
  80,  82,  79,  84,  79,  95,  85,  68,  80,   9,  83,  79,  77,  65,  88,  67,
  79,  78,  78,  13, 115, 104, 101, 108, 108,  58,  80, 114, 111, 103, 114,  97,
 109,   4,  95,  65,  80,  73,   4,  97, 114, 103, 118,   7, 103, 101, 116,  65,
 114, 103, 118,  16, 115, 116,  97, 114, 116, 117, 112,  68, 105, 114, 101,  99,
 116, 111, 114, 121,   6,  70,  80,  95,  57,  95,  48,   7,  65,  73,  82,  95,
  49,  95,  48,   7,  70,  80,  95,  49,  48,  95,  48,   7,  65,  73,  82,  95,
  49,  95,  53,   9,  65,  73,  82,  95,  49,  95,  53,  95,  49,  10,  70,  80,
  95,  49,  48,  95,  48,  95,  51,  50,   9,  65,  73,  82,  95,  49,  95,  53,
  95,  50,   7,  70,  80,  95,  49,  48,  95,  49,   7,  65,  73,  82,  95,  50,
  95,  48,   7,  65,  73,  82,  95,  50,  95,  53,   7,  70,  80,  95,  49,  48,
  95,  50,   7,  65,  73,  82,  95,  50,  95,  54,   6,  83,  87,  70,  95,  49,
  50,   7,  65,  73,  82,  95,  50,  95,  55,   6,  83,  87,  70,  95,  49,  51,
   7,  65,  73,  82,  95,  51,  95,  48,   6,  83,  87,  70,  95,  49,  52,   7,
  65,  73,  82,  95,  51,  95,  49,   6,  83,  87,  70,  95,  49,  53,   7,  65,
  73,  82,  95,  51,  95,  50,   6,  83,  87,  70,  95,  49,  54,   7,  65,  73,
  82,  95,  51,  95,  51,   6,  83,  87,  70,  95,  49,  55,   7,  65,  73,  82,
  95,  51,  95,  52,   6,  83,  87,  70,  95,  49,  56,   7,  65,  73,  82,  95,
  51,  95,  53,   6,  83,  87,  70,  95,  49,  57,   7,  65,  73,  82,  95,  51,
  95,  54,  11,  86,  77,  95,  73,  78,  84,  69,  82,  78,  65,  76,   5,  83,
  72,  69,  76,  76,  10,  97, 112, 105,  86, 101, 114, 115, 105, 111, 110,   6,
  95, 115, 104, 101, 108, 108,  10,  95, 102, 105, 110, 100,  83, 104, 101, 108,
 108,   6,  78, 117, 109,  98, 101, 114,   9, 112, 111, 112, 101, 110,  82, 101,
  97, 100,   5,  48,  46,  52,  46,  48,   1,  10,   5, 119, 114, 105, 116, 101,
   3,  88,  77,  76,   8,  97, 112, 105,  65, 108, 105,  97, 115,   3, 112, 105,
 100,  15, 112, 114, 111, 103, 114,  97, 109,  70, 105, 108, 101, 110,  97, 109,
 101,  10, 115, 119, 102,  86, 101, 114, 115, 105, 111, 110,  11, 116, 111, 116,
  97, 108,  77, 101, 109, 111, 114, 121,  10, 102, 114, 101, 101,  77, 101, 109,
 111, 114, 121,  13, 112, 114, 105, 118,  97, 116, 101,  77, 101, 109, 111, 114,
 121,  16, 119, 111, 114, 107, 105, 110, 103,  68, 105, 114, 101,  99, 116, 111,
 114, 121,   4, 101, 118,  97, 108,   4, 101, 120, 101,  99,   5, 112, 111, 112,
 101, 110,  17, 103, 101, 116,  65, 118, 109, 112, 108, 117, 115,  86, 101, 114,
 115, 105, 111, 110,  10, 103, 101, 116,  69, 110, 118, 105, 114, 111, 110,  20,
 103, 101, 116,  82, 101, 100, 116,  97, 109,  97, 114, 105, 110,  86, 101, 114,
 115, 105, 111, 110,  11, 103, 101, 116,  70, 101,  97, 116, 117, 114, 101, 115,
  18, 103, 101, 116,  78,  97, 110, 111, 115, 101,  99, 111, 110, 100,  84, 105,
 109, 101, 114,  10, 103, 101, 116,  82, 117, 110, 109, 111, 100, 101,   9, 119,
 114, 105, 116, 101,  76, 105, 110, 101,  10, 105, 115,  68, 101,  98, 117, 103,
 103, 101, 114,  19, 102, 111, 114,  99, 101,  70, 117, 108, 108,  67, 111, 108,
 108, 101,  99, 116, 105, 111, 110,  15, 113, 117, 101, 117, 101,  67, 111, 108,
 108, 101,  99, 116, 105, 111, 110,  30, 112,  97, 117, 115, 101,  70, 111, 114,
  71,  67,  73, 102,  67, 111, 108, 108, 101,  99, 116, 105, 111, 110,  73, 109,
 109, 105, 110, 101, 110, 116,  10, 100, 105, 115, 112, 111, 115, 101,  88,  77,
  76,   8, 105, 115,  71, 108, 111,  98,  97, 108,   7, 105, 115,  54,  52,  98,
 105, 116,   8, 105, 115,  73, 110, 116, 112, 116, 114,  18,  99,  97, 110, 111,
 110, 105,  99,  97, 108, 105, 122, 101,  78, 117, 109,  98, 101, 114,  14, 114,
 117, 110,  73, 110,  83,  97, 102, 101, 112, 111, 105, 110, 116,  12, 115, 104,
 101, 108, 108,  58,  68, 111, 109,  97, 105, 110,   4, 105, 110, 105, 116,  11,
 102, 108,  97, 115, 104,  46, 117, 116, 105, 108, 115,   9,  66, 121, 116, 101,
  65, 114, 114,  97, 121,   6,  70, 105, 108, 101,  73,  79,  13, 114, 101,  97,
 100,  66, 121, 116, 101,  65, 114, 114,  97, 121,   9, 108, 111,  97, 100,  66,
 121, 116, 101, 115,  24,  77,  73,  78,  95,  68,  79,  77,  65,  73,  78,  95,
  77,  69,  77,  79,  82,  89,  95,  76,  69,  78,  71,  84,  72,   4, 108, 111,
  97, 100,  12, 100, 111, 109,  97, 105, 110,  77, 101, 109, 111, 114, 121,  12,
 115, 104, 101, 108, 108,  58,  70, 105, 108, 101,  73,  79,   6, 101, 120, 105,
 115, 116, 115,   4, 114, 101,  97, 100,  14, 119, 114, 105, 116, 101,  66, 121,
 116, 101,  65, 114, 114,  97, 121,  17, 115, 104, 101, 108, 108,  58,  69, 110,
 118, 105, 114, 111, 110, 109, 101, 110, 116,  17, 102, 108,  97, 115, 104,  46,
 117, 116, 105, 108, 115,  58,  80, 114, 111, 120, 121,  16,  69, 110, 118, 105,
 114, 111, 110, 109, 101, 110, 116,  32,  99, 116, 111, 114,   7, 114, 101, 102,
 114, 101, 115, 104,   5,  95, 118,  97, 114, 115,   6, 108, 101, 110, 103, 116,
 104,   1,  61,   7, 105, 110, 100, 101, 120,  79, 102,   6, 115, 117,  98, 115,
 116, 114,   9, 115, 117,  98, 115, 116, 114, 105, 110, 103,   4,  95, 101, 110,
 118,   4,  95, 105, 100, 120,  27,  69, 110, 118, 105, 114, 111, 110, 109, 101,
 110, 116,  32,  99,  97, 108, 108,  80, 114, 111, 112, 101, 114, 116, 121,  32,
  45,  32,   2,  40,  32,   2,  44,  32,   2,  32,  41,  11, 104,  97, 115,  80,
 114, 111, 112, 101, 114, 116, 121,   6,  95, 112,  97, 114, 115, 101,  50, 104,
 116, 116, 112,  58,  47,  47, 119, 119, 119,  46,  97, 100, 111,  98, 101,  46,
  99, 111, 109,  47,  50,  48,  48,  54,  47,  97,  99, 116, 105, 111, 110, 115,
  99, 114, 105, 112, 116,  47, 102, 108,  97, 115, 104,  47, 112, 114, 111, 120,
 121,  12,  99,  97, 108, 108,  80, 114, 111, 112, 101, 114, 116, 121,  14, 100,
 101, 108, 101, 116, 101,  80, 114, 111, 112, 101, 114, 116, 121,  11, 103, 101,
 116,  80, 114, 111, 112, 101, 114, 116, 121,  11, 115, 101, 116,  80, 114, 111,
 112, 101, 114, 116, 121,  13, 110, 101, 120, 116,  78,  97, 109, 101,  73, 110,
 100, 101, 120,   8, 110, 101, 120, 116,  78,  97, 109, 101,   9, 110, 101, 120,
 116,  86,  97, 108, 117, 101,  11,  69, 110, 118, 105, 114, 111, 110, 109, 101,
 110, 116,   5,  80, 114, 111, 120, 121,  11,  73, 110, 115, 112, 101,  99, 116,
  97,  98, 108, 101,  11, 101, 110, 118, 105, 114, 111, 110, 109, 101, 110, 116,
   4, 110, 111, 110, 101,   6, 110,  97, 116, 105, 118, 101,   3,  99, 108, 115,
  23,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  67,  69, 114,
 114, 110, 111,  67, 108,  97, 115, 115,   7, 109, 101, 116, 104, 111, 100, 115,
   4,  97, 117, 116, 111,   9,  99, 111, 110, 115, 116, 114, 117,  99, 116,  10,
  67,  46, 101, 114, 114, 110, 111, 238, 138, 148,  24,  58,  58,  97, 118, 109,
 115, 104, 101, 108, 108,  58,  58,  67,  83, 116, 100, 108, 105,  98,  67, 108,
  97, 115, 115,  11,  67,  46, 115, 116, 100, 108, 105,  98, 238, 138, 148,   6,
 115, 121, 115, 116, 101, 109,  24,  58,  58,  97, 118, 109, 115, 104, 101, 108,
 108,  58,  58,  67,  85, 110, 105, 115, 116, 100,  67, 108,  97, 115, 115,  11,
  67,  46, 117, 110, 105, 115, 116, 100, 238, 138, 148,  24,  58,  58,  97, 118,
 109, 115, 104, 101, 108, 108,  58,  58,  67,  83, 116, 114, 105, 110, 103,  67,
 108,  97, 115, 115,  11,  67,  46, 115, 116, 114, 105, 110, 103, 238, 138, 148,
   7, 115, 116, 114, 109, 111, 100, 101,  23,  58,  58,  97, 118, 109, 115, 104,
 101, 108, 108,  58,  58,  67,  83, 116, 100, 105, 111,  67, 108,  97, 115, 115,
  10,  67,  46, 115, 116, 100, 105, 111, 238, 138, 148,  32,  58,  58,  97, 118,
 109, 115, 104, 101, 108, 108,  58,  58,  67,  83, 116, 100, 105, 111,  67, 108,
  97, 115, 115,  58,  58, 114, 101, 110,  97, 109, 101,  50,  11,  67,  46, 115,
 116, 100, 105, 111,  50, 238, 138, 148,   7, 114, 101, 110,  97, 109, 101,  50,
  24,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  67,  83, 111,
  99, 107, 101, 116,  67, 108,  97, 115, 115,  11,  67,  46, 115, 111,  99, 107,
 101, 116, 238, 138, 148,  13, 103, 101, 116, 104, 111, 115, 116,  98, 121,  97,
 100, 100, 114,  13, 103, 101, 116, 104, 111, 115, 116,  98, 121, 110,  97, 109,
 101,  11, 103, 101, 116, 112, 101, 101, 114, 110,  97, 109, 101,  11, 103, 101,
 116, 115, 111,  99, 107, 110,  97, 109, 101,   8, 115, 104, 101, 108, 108, 238,
 138, 148,  24,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  80,
 114, 111, 103, 114,  97, 109,  67, 108,  97, 115, 115,   7,  99, 108,  97, 115,
 115, 103,  99,   5, 101, 120,  97,  99, 116,  11,  68, 111, 109,  97, 105, 110,
  67, 108,  97, 115, 115,   2, 103,  99,   8, 105, 110, 115, 116,  97, 110,  99,
 101,  12,  68, 111, 109,  97, 105, 110,  79,  98, 106, 101,  99, 116,  21,  58,
  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,  58,  70, 105, 108, 101,  67,
 108,  97, 115, 115,  14, 103, 101, 116,  67, 108,  97, 115, 115,  66, 121,  78,
  97, 109, 101,   5, 112, 114, 105, 110, 116,   5,  81,  78,  97, 109, 101,  19,
  95, 103, 101, 116,  73, 110, 118, 111,  99,  97, 116, 105, 111, 110,  67, 111,
 117, 110, 116,  12,  97, 118, 109, 103, 108, 117, 101,  46,  97, 115,  36,  50,
  13, 102, 108,  97, 115, 104,  46, 115,  97, 109, 112, 108, 101, 114,  11,  95,
 103, 101, 116,  83,  97, 109, 112, 108, 101, 115,   1, 102,   1, 101,   3, 114,
 101, 116,  19,  95, 115, 101, 116,  83,  97, 109, 112, 108, 101, 114,  67,  97,
 108, 108,  98,  97,  99, 107,   7, 119, 114,  97, 112, 112, 101, 114,  18, 102,
 108,  97, 115, 104,  46, 117, 116, 105, 108, 115,  58,  69, 110, 100, 105,  97,
 110,  10,  66,  73,  71,  95,  69,  78,  68,  73,  65,  78,   9,  98, 105, 103,
  69, 110, 100, 105,  97, 110,  13,  76,  73,  84,  84,  76,  69,  95,  69,  78,
  68,  73,  65,  78,  12, 108, 105, 116, 116, 108, 101,  69, 110, 100, 105,  97,
 110,   6,  69, 110, 100, 105,  97, 110,  25, 102, 108,  97, 115, 104,  46, 115,
 121, 115, 116, 101, 109,  58,  67,  97, 112,  97,  98, 105, 108, 105, 116, 105,
 101, 115,   7,  65,  86,  77,  80, 108, 117, 115,   6,  83, 121, 115, 116, 101,
 109,   7,  97, 118, 109, 112, 108, 117, 115,  12, 102, 108,  97, 115, 104,  46,
 115, 121, 115, 116, 101, 109,  10, 112, 108,  97, 121, 101, 114,  84, 121, 112,
 101,  12,  67,  97, 112,  97,  98, 105, 108, 105, 116, 105, 101, 115,  24, 102,
 108,  97, 115, 104,  46, 115,  97, 109, 112, 108, 101, 114,  58,  83, 116,  97,
  99, 107,  70, 114,  97, 109, 101,   2,  40,  41,   4, 102, 105, 108, 101,   1,
  91,   1,  58,   4, 108, 105, 110, 101,   1,  93,   8, 115,  99, 114, 105, 112,
 116,  73,  68,  10,  83, 116,  97,  99, 107,  70, 114,  97, 109, 101,  20, 102,
 108,  97, 115, 104,  46, 115,  97, 109, 112, 108, 101, 114,  58,  83,  97, 109,
 112, 108, 101,   4, 116, 105, 109, 101,   5, 115, 116,  97,  99, 107,   6,  83,
  97, 109, 112, 108, 101,  26, 102, 108,  97, 115, 104,  46, 115,  97, 109, 112,
 108, 101, 114,  58,  67, 108,  97, 115, 115,  70,  97,  99, 116, 111, 114, 121,
  15,  83, 116,  97,  99, 107,  70, 114,  97, 109, 101,  67, 108,  97, 115, 115,
  11,  83,  97, 109, 112, 108, 101,  67, 108,  97, 115, 115,  23,  68, 101, 108,
 101, 116, 101,  79,  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  67,
 108,  97, 115, 115,  20,  78, 101, 119,  79,  98, 106, 101,  99, 116,  83,  97,
 109, 112, 108, 101,  67, 108,  97, 115, 115,  12,  67, 108,  97, 115, 115,  70,
  97,  99, 116, 111, 114, 121,  17, 102, 108,  97, 115, 104,  46, 116, 114,  97,
  99, 101,  58,  84, 114,  97,  99, 101,   3,  79,  70,  70,   7,  77,  69,  84,
  72,  79,  68,  83,  17,  77,  69,  84,  72,  79,  68,  83,  95,  87,  73,  84,
  72,  95,  65,  82,  71,  83,  17,  77,  69,  84,  72,  79,  68,  83,  95,  65,
  78,  68,  95,  76,  73,  78,  69,  83,  27,  77,  69,  84,  72,  79,  68,  83,
  95,  65,  78,  68,  95,  76,  73,  78,  69,  83,  95,  87,  73,  84,  72,  95,
  65,  82,  71,  83,   4,  70,  73,  76,  69,   8,  76,  73,  83,  84,  69,  78,
  69,  82,   8, 115, 101, 116,  76, 101, 118, 101, 108,   8, 103, 101, 116,  76,
 101, 118, 101, 108,  11, 115, 101, 116,  76, 105, 115, 116, 101, 110, 101, 114,
  11, 103, 101, 116,  76, 105, 115, 116, 101, 110, 101, 114,  11, 102, 108,  97,
 115, 104,  46, 116, 114,  97,  99, 101,   5,  84, 114,  97,  99, 101,  24, 102,
 108,  97, 115, 104,  46, 115, 121, 115, 116, 101, 109,  58,  87, 111, 114, 107,
 101, 114,  83, 116,  97, 116, 101,   3,  78,  69,  87,   3, 110, 101, 119,   7,
  82,  85,  78,  78,  73,  78,  71,   7, 114, 117, 110, 110, 105, 110, 103,  10,
  84,  69,  82,  77,  73,  78,  65,  84,  69,  68,  10, 116, 101, 114, 109, 105,
 110,  97, 116, 101, 100,   6,  70,  65,  73,  76,  69,  68,   6, 102,  97, 105,
 108, 101, 100,   7,  65,  66,  79,  82,  84,  69,  68,   7,  97,  98, 111, 114,
 116, 101, 100,   9,  69,  88,  67,  69,  80,  84,  73,  79,  78,   9, 101, 120,
  99, 101, 112, 116, 105, 111, 110,  19, 110, 111, 116,  32,  97, 110,  32, 101,
 110, 117, 109,  32, 118,  97, 108, 117, 101,  58,  32,   4,  99, 111, 100, 101,
  11,  87, 111, 114, 107, 101, 114,  83, 116,  97, 116, 101,  19, 102, 108,  97,
 115, 104,  46, 115, 121, 115, 116, 101, 109,  58,  87, 111, 114, 107, 101, 114,
   9, 109,  95,  99, 117, 114, 114, 101, 110, 116,   6,  87, 111, 114, 107, 101,
 114,   7,  99, 117, 114, 114, 101, 110, 116,   2, 112, 114,   5, 115, 116,  97,
 116, 101,   5, 115, 116,  97, 114, 116,  10, 105, 115,  80,  97, 114, 101, 110,
 116,  79, 102,  12, 105, 115,  80, 114, 105, 109, 111, 114, 100, 105,  97, 108,
  17, 115, 101, 116,  83, 104,  97, 114, 101, 100,  80, 114, 111, 112, 101, 114,
 116, 121,  17, 103, 101, 116,  83, 104,  97, 114, 101, 100,  80, 114, 111, 112,
 101, 114, 116, 121,   9, 116, 101, 114, 109, 105, 110,  97, 116, 101,  10, 109,
  95,  98, 121, 116, 101,  67, 111, 100, 101,  24, 102, 108,  97, 115, 104,  46,
 115, 121, 115, 116, 101, 109,  58,  87, 111, 114, 107, 101, 114,  69, 118, 101,
 110, 116,  12,  87,  79,  82,  75,  69,  82,  95,  83,  84,  65,  84,  69,  11,
 119, 111, 114, 107, 101, 114,  83, 116,  97, 116, 101,  15, 109,  95, 112, 114,
 101, 118, 105, 111, 117, 115,  83, 116,  97, 116, 101,  14, 109,  95,  99, 117,
 114, 114, 101, 110, 116,  83, 116,  97, 116, 101,   8, 109,  95, 116,  97, 114,
 103, 101, 116,  12,  99, 117, 114, 114, 101, 110, 116,  83, 116,  97, 116, 101,
  13, 112, 114, 101, 118, 105, 111, 117, 115,  83, 116,  97, 116, 101,   6, 116,
  97, 114, 103, 101, 116,  11,  87, 111, 114, 107, 101, 114,  69, 118, 101, 110,
 116,  25, 102, 108,  97, 115, 104,  46, 115, 121, 115, 116, 101, 109,  58,  87,
 111, 114, 107, 101, 114,  68, 111, 109,  97, 105, 110,  12,  87, 111, 114, 107,
 101, 114,  68, 111, 109,  97, 105, 110,  33,  99, 114, 101,  97, 116, 101,  87,
 111, 114, 107, 101, 114,  70, 114, 111, 109,  66, 121, 116, 101,  65, 114, 114,
  97, 121,  73, 110, 116, 101, 114, 110,  97, 108,  11,  95,  95,  65,  83,  51,
  95,  95,  46, 118, 101,  99,   6,  86, 101,  99, 116, 111, 114,  25,  99, 114,
 101,  97, 116, 101,  87, 111, 114, 107, 101, 114,  70, 114, 111, 109,  66, 121,
 116, 101,  65, 114, 114,  97, 121,  26,  99, 114, 101,  97, 116, 101,  87, 111,
 114, 107, 101, 114,  70, 114, 111, 109,  80, 114, 105, 109, 111, 114, 100, 105,
  97, 108,  11, 108, 105, 115, 116,  87, 111, 114, 107, 101, 114, 115,  19, 102,
 108,  97, 115, 104,  46, 115, 121, 115, 116, 101, 109,  58,  83, 121, 115, 116,
 101, 109,  17, 116, 111, 116,  97, 108,  77, 101, 109, 111, 114, 121,  78, 117,
 109,  98, 101, 114,  12,  95, 117, 115, 101,  67, 111, 100, 101,  80,  97, 103,
 101,  12, 115, 101, 116,  67, 108, 105, 112,  98, 111,  97, 114, 100,  11, 117,
 115, 101,  67, 111, 100, 101,  80,  97, 103, 101,   9, 118, 109,  86, 101, 114,
 115, 105, 111, 110,   5, 112,  97, 117, 115, 101,   6, 114, 101, 115, 117, 109,
 101,  31, 102, 108,  97, 115, 104,  46, 101, 114, 114, 111, 114, 115,  58,  83,
  99, 114, 105, 112, 116,  84, 105, 109, 101, 111, 117, 116,  69, 114, 114, 111,
 114,  12, 102, 108,  97, 115, 104,  46, 101, 114, 114, 111, 114, 115,  18,  83,
  99, 114, 105, 112, 116,  84, 105, 109, 101, 111, 117, 116,  69, 114, 114, 111,
 114,  31, 102, 108,  97, 115, 104,  46, 101, 114, 114, 111, 114, 115,  58,  83,
 116,  97,  99, 107,  79, 118, 101, 114, 102, 108, 111, 119,  69, 114, 114, 111,
 114,  18,  83, 116,  97,  99, 107,  79, 118, 101, 114, 102, 108, 111, 119,  69,
 114, 114, 111, 114,  28, 102, 108,  97, 115, 104,  46, 101, 114, 114, 111, 114,
 115,  58,  73, 110, 118,  97, 108, 105, 100,  83,  87,  70,  69, 114, 114, 111,
 114,  15,  73, 110, 118,  97, 108, 105, 100,  83,  87,  70,  69, 114, 114, 111,
 114,  30, 102, 108,  97, 115, 104,  46, 101, 114, 114, 111, 114, 115,  58,  83,
  81,  76,  69, 114, 114, 111, 114,  79, 112, 101, 114,  97, 116, 105, 111, 110,
   7,  65,  78,  65,  76,  89,  90,  69,   7,  97, 110,  97, 108, 121, 122, 101,
   6,  65,  84,  84,  65,  67,  72,   6,  97, 116, 116,  97,  99, 104,   5,  66,
  69,  71,  73,  78,   5,  98, 101, 103, 105, 110,   5,  67,  76,  79,  83,  69,
   5,  99, 108, 111, 115, 101,   6,  67,  79,  77,  77,  73,  84,   6,  99, 111,
 109, 109, 105, 116,   7,  67,  79,  77,  80,  65,  67,  84,   7,  99, 111, 109,
 112,  97,  99, 116,   9,  68,  69,  65,  78,  65,  76,  89,  90,  69,   9, 100,
 101,  97, 110,  97, 108, 121, 122, 101,   6,  68,  69,  84,  65,  67,  72,   6,
 100, 101, 116,  97,  99, 104,   7,  69,  88,  69,  67,  85,  84,  69,   7, 101,
 120, 101,  99, 117, 116, 101,   4,  79,  80,  69,  78,   4, 111, 112, 101, 110,
   9,  82,  69,  69,  78,  67,  82,  89,  80,  84,   9, 114, 101, 101, 110,  99,
 114, 121, 112, 116,  17,  82,  69,  76,  69,  65,  83,  69,  95,  83,  65,  86,
  69,  80,  79,  73,  78,  84,  16, 114, 101, 108, 101,  97, 115, 101,  83,  97,
 118, 101, 112, 111, 105, 110, 116,   8,  82,  79,  76,  76,  66,  65,  67,  75,
   8, 114, 111, 108, 108,  98,  97,  99, 107,  21,  82,  79,  76,  76,  66,  65,
  67,  75,  95,  84,  79,  95,  83,  65,  86,  69,  80,  79,  73,  78,  84,  19,
 114, 111, 108, 108,  98,  97,  99, 107,  84, 111,  83,  97, 118, 101, 112, 111,
 105, 110, 116,   6,  83,  67,  72,  69,  77,  65,   6, 115,  99, 104, 101, 109,
  97,  13,  83,  69,  84,  95,  83,  65,  86,  69,  80,  79,  73,  78,  84,  12,
 115, 101, 116,  83,  97, 118, 101, 112, 111, 105, 110, 116,   3, 238, 138, 149,
   3,  65,  80,  73,   3,  54,  54,  49,   3, 238, 138, 151,   3,  54,  54,  51,
   3, 238, 138, 156,   3,  54,  54,  56,  17,  83,  81,  76,  69, 114, 114, 111,
 114,  79, 112, 101, 114,  97, 116, 105, 111, 110,  21, 102, 108,  97, 115, 104,
  46, 101, 114, 114, 111, 114, 115,  58,  83,  81,  76,  69, 114, 114, 111, 114,
   8,  83,  81,  76,  69, 114, 114, 111, 114,  10,  95, 111, 112, 101, 114,  97,
 116, 105, 111, 110,   8,  95, 100, 101, 116,  97, 105, 108, 115,   9,  95, 100,
 101, 116,  97, 105, 108,  73,  68,  16,  95, 100, 101, 116,  97, 105, 108,  65,
 114, 103, 117, 109, 101, 110, 116, 115,   9, 111, 112, 101, 114,  97, 116, 105,
 111, 110,   7, 100, 101, 116,  97, 105, 108, 115,   8, 100, 101, 116,  97, 105,
 108,  73,  68,  15, 100, 101, 116,  97, 105, 108,  65, 114, 103, 117, 109, 101,
 110, 116, 115,  28, 102, 108,  97, 115, 104,  46, 101, 114, 114, 111, 114, 115,
  58,  68,  82,  77,  77,  97, 110,  97, 103, 101, 114,  69, 114, 114, 111, 114,
  15,  68,  82,  77,  77,  97, 110,  97, 103, 101, 114,  69, 114, 114, 111, 114,
  11,  95, 115, 117,  98,  69, 114, 114, 111, 114,  73,  68,  10, 115, 117,  98,
  69, 114, 114, 111, 114,  73,  68,  29, 102, 108,  97, 115, 104,  46, 115,  97,
 109, 112, 108, 101, 114,  58,  78, 101, 119,  79,  98, 106, 101,  99, 116,  83,
  97, 109, 112, 108, 101,   2, 105, 100,   4, 116, 121, 112, 101,   6, 111,  98,
 106, 101,  99, 116,   4, 115, 105, 122, 101,  15,  78, 101, 119,  79,  98, 106,
 101,  99, 116,  83,  97, 109, 112, 108, 101,  32, 102, 108,  97, 115, 104,  46,
 115,  97, 109, 112, 108, 101, 114,  58,  68, 101, 108, 101, 116, 101,  79,  98,
 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  18,  68, 101, 108, 101, 116,
 101,  79,  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  14, 102, 108,
  97, 115, 104,  46, 117, 116, 105, 108, 115, 238, 138, 148,  15, 102, 108,  97,
 115, 104,  46, 115, 121, 115, 116, 101, 109, 238, 138, 148,  16, 102, 108,  97,
 115, 104,  46, 115,  97, 109, 112, 108, 101, 114, 238, 138, 148,  21,  78, 101,
 119,  79,  98, 106, 101,  99, 116,  83,  97, 109, 112, 108, 101,  79,  98, 106,
 101,  99, 116,  12,  99, 108, 101,  97, 114,  83,  97, 109, 112, 108, 101, 115,
  27,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58,
  99, 108, 101,  97, 114,  83,  97, 109, 112, 108, 101, 115,  13, 115, 116,  97,
 114, 116,  83,  97, 109, 112, 108, 105, 110, 103,  28,  83,  97, 109, 112, 108,
 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 115, 116,  97, 114, 116,  83,
  97, 109, 112, 108, 105, 110, 103,  12, 115, 116, 111, 112,  83,  97, 109, 112,
 108, 105, 110, 103,  27,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105,
 112, 116,  58,  58, 115, 116, 111, 112,  83,  97, 109, 112, 108, 105, 110, 103,
  13, 112,  97, 117, 115, 101,  83,  97, 109, 112, 108, 105, 110, 103,  28,  83,
  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 112,  97,
 117, 115, 101,  83,  97, 109, 112, 108, 105, 110, 103,  20, 115,  97, 109, 112,
 108, 101,  73, 110, 116, 101, 114, 110,  97, 108,  65, 108, 108, 111,  99, 115,
  35,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58,
 115,  97, 109, 112, 108, 101,  73, 110, 116, 101, 114, 110,  97, 108,  65, 108,
 108, 111,  99, 115,  18, 115, 101, 116,  83,  97, 109, 112, 108, 101, 114,  67,
  97, 108, 108,  98,  97,  99, 107,  34,  83,  97, 109, 112, 108, 101, 114,  83,
  99, 114, 105, 112, 116,  58,  58,  95, 115, 101, 116,  83,  97, 109, 112, 108,
 101, 114,  67,  97, 108, 108,  98,  97,  99, 107,   7, 103, 101, 116,  83, 105,
 122, 101,  22,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,
  58,  58, 103, 101, 116,  83, 105, 122, 101,  14, 103, 101, 116,  77, 101, 109,
  98, 101, 114,  78,  97, 109, 101, 115,  29,  83,  97, 109, 112, 108, 101, 114,
  83,  99, 114, 105, 112, 116,  58,  58, 103, 101, 116,  77, 101, 109,  98, 101,
 114,  78,  97, 109, 101, 115,  10, 103, 101, 116,  83,  97, 109, 112, 108, 101,
 115,  26,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,
  58,  95, 103, 101, 116,  83,  97, 109, 112, 108, 101, 115,  14, 103, 101, 116,
  83,  97, 109, 112, 108, 101,  67, 111, 117, 110, 116,  29,  83,  97, 109, 112,
 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 103, 101, 116,  83,  97,
 109, 112, 108, 101,  67, 111, 117, 110, 116,  18, 103, 101, 116,  73, 110, 118,
 111,  99,  97, 116, 105, 111, 110,  67, 111, 117, 110, 116,  24, 103, 101, 116,
  83, 101, 116, 116, 101, 114,  73, 110, 118, 111,  99,  97, 116, 105, 111, 110,
  67, 111, 117, 110, 116,  24, 103, 101, 116,  71, 101, 116, 116, 101, 114,  73,
 110, 118, 111,  99,  97, 116, 105, 111, 110,  67, 111, 117, 110, 116,  34,  83,
  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58,  95, 103,
 101, 116,  73, 110, 118, 111,  99,  97, 116, 105, 111, 110,  67, 111, 117, 110,
 116,  14, 105, 115,  71, 101, 116, 116, 101, 114,  83, 101, 116, 116, 101, 114,
  29,  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58,
 105, 115,  71, 101, 116, 116, 101, 114,  83, 101, 116, 116, 101, 114,  16, 103,
 101, 116,  76, 101, 120, 105,  99,  97, 108,  83,  99, 111, 112, 101, 115,  31,
  83,  97, 109, 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 103,
 101, 116,  76, 101, 120, 105,  99,  97, 108,  83,  99, 111, 112, 101, 115,  12,
 103, 101, 116,  83,  97, 118, 101, 100,  84, 104, 105, 115,  27,  83,  97, 109,
 112, 108, 101, 114,  83,  99, 114, 105, 112, 116,  58,  58, 103, 101, 116,  83,
  97, 118, 101, 100,  84, 104, 105, 115,  15, 103, 101, 116,  77,  97, 115, 116,
 101, 114,  83, 116, 114, 105, 110, 103,  30,  83,  97, 109, 112, 108, 101, 114,
  83,  99, 114, 105, 112, 116,  58,  58, 103, 101, 116,  77,  97, 115, 116, 101,
 114,  83, 116, 114, 105, 110, 103,   3,  54,  56,  56,  14, 102, 108,  97, 115,
 104,  46, 116, 114,  97,  99, 101, 238, 138, 148,  10,  84, 114,  97,  99, 101,
  67, 108,  97, 115, 115,  15, 102, 108,  97, 115, 104,  46, 115, 121, 115, 116,
 101, 109, 238, 138, 170,   3,  54,  56,  50,  28,  58,  58,  97, 118, 109, 115,
 104, 101, 108, 108,  58,  58,  83, 104, 101, 108, 108,  87, 111, 114, 107, 101,
 114,  67, 108,  97, 115, 115,  29,  58,  58,  97, 118, 109, 115, 104, 101, 108,
 108,  58,  58,  83, 104, 101, 108, 108,  87, 111, 114, 107, 101, 114,  79,  98,
 106, 101,  99, 116,  34,  58,  58,  97, 118, 109, 115, 104, 101, 108, 108,  58,
  58,  83, 104, 101, 108, 108,  87, 111, 114, 107, 101, 114,  68, 111, 109,  97,
 105, 110,  67, 108,  97, 115, 115,  35,  58,  58,  97, 118, 109, 115, 104, 101,
 108, 108,  58,  58,  83, 104, 101, 108, 108,  87, 111, 114, 107, 101, 114,  68,
 111, 109,  97, 105, 110,  79,  98, 106, 101,  99, 116,  15, 102, 108,  97, 115,
 104,  46, 101, 114, 114, 111, 114, 115, 238, 138, 148,  15, 102, 108,  97, 115,
 104,  46, 101, 114, 114, 111, 114, 115, 238, 138, 149,  15, 102, 108,  97, 115,
 104,  46, 101, 114, 114, 111, 114, 115, 238, 138, 151, 136,   1,   5,   3,  22,
   1,  23,   1,  22,   4,  23,   4,  22,  18,  23,  18,  22,  27,  23,  27,  22,
  28,  22,  34,  23,  34,  22,  49,  23,  49,  22,  50,  23,  50,  22,  91,  23,
  91,   5, 100,  22, 101,  23,  28,  24, 100,   5, 168,   1,  24, 168,   1,  26,
 168,   1,  26, 167,   1,   5, 173,   1,  24, 173,   1,  26, 173,   1,  26, 175,
   1,   5, 179,   1,  24, 179,   1,   5, 181,   1,  24, 181,   1,   5, 192,   1,
  24, 192,   1,   5, 193,   1,  24, 193,   1,   5, 200,   1,  24, 200,   1,   5,
 235,   1,  24, 235,   1,  26, 235,   1,   5, 179,   2,  24, 179,   2,  26, 179,
   2,  22, 181,   2,   5, 189,   2,  24, 189,   2,   5, 193,   2,  24, 193,   2,
  26, 193,   2,  26, 194,   2,   8, 211,   2,  22, 230,   2,  22, 232,   2,  22,
 235,   2,  22, 237,   2,  22, 240,   2,  22, 242,   2,  22, 245,   2,  22, 250,
   2,   5, 135,   3,  22, 136,   3,  23, 136,   3,   5, 143,   3,  24, 143,   3,
   5, 149,   3,  22, 152,   3,  22, 153,   3,  23, 153,   3,  24, 149,   3,  26,
 149,   3,   5, 156,   3,  24, 156,   3,  26, 156,   3,   5, 165,   3,  24, 165,
   3,   5, 169,   3,  24, 169,   3,   5, 175,   3,  22, 187,   3,  24, 175,   3,
   5, 189,   3,  24, 189,   3,  26, 189,   3,   5, 205,   3,  24, 205,   3,  26,
 205,   3,   5, 218,   3,  24, 218,   3,  26, 218,   3,   5, 228,   3,  24, 228,
   3,  26, 228,   3,  22, 231,   3,   5, 236,   3,  24, 236,   3,  26, 236,   3,
   5, 244,   3,  22, 245,   3,  23, 245,   3,  24, 244,   3,  26, 244,   3,   5,
 247,   3,  24, 247,   3,  26, 247,   3,   5, 249,   3,  24, 249,   3,  26, 249,
   3,   5, 251,   3,  22, 156,   4,  22, 159,   4,  22, 161,   4,  24, 251,   3,
   5, 164,   4,  24, 164,   4,  26, 164,   4,   5, 174,   4,  24, 174,   4,  26,
 174,   4,   5, 178,   4,  24, 178,   4,   5, 184,   4,  24, 184,   4,  23, 181,
   2,  23, 187,   3,  22, 186,   4,  22, 187,   4,  22, 188,   4,  22, 223,   4,
  22, 225,   4,  22, 231,   4,  22, 232,   4,  22, 233,   4,  83,   4,   1,   2,
   3,   4,   4,   1,   2,   4,   5,   4,   1,   2,   6,   7,   5,   1,   2,   8,
   9,  10,   6,   1,   2,   4,   8,   9,  10,   4,   1,   2,  11,  12,   5,   1,
   2,  13,  14,  15,   1,  14,   4,   1,   2,  15,  16,   4,   1,   2,  17,  18,
   1,  20,   9,   1,   2,  10,  13,  21,  23,  24,  25,  26,   1,  23,  10,   1,
   2,  10,  13,  21,  26,  27,  28,  29,  30,  11,   1,   2,   4,   5,  10,  15,
  17,  26,  41,  42,  43,   1,  41,   8,   1,   2,   4,   5,  26,  44,  45,  46,
   1,  44,   9,   1,   2,   4,   5,  26,  50,  51,  52,  53,   1,  50,   1,  54,
   1,  21,   5,   1,   2,  10,  13,  21,   1,  10,   1,  18,   1,  16,   1,  12,
   1,   7,   1,   4,   7,   1,   2,   4,   5,  10,  15,  17,   5,   1,   2,   4,
   5,  47,   2,   1,   2,   1,  17,   1,  15,   1,  11,   1,   6,   1,  55,   1,
  56,   1,  57,   1,  58,   1,  59,   1,   9,   1,  60,   1,  61,   1,  62,   4,
   2,  63,  64,  65,   1,  65,   8,   2,  26,  63,  68,  70,  71,  72,  73,   8,
   2,  26,  63,  64,  65,  74,  75,  76,   8,   2,  26,  63,  70,  71,  84,  85,
  86,   8,   2,  26,  63,  70,  71,  87,  88,  89,   1,  87,   8,   2,  26,  63,
  70,  71,  90,  91,  92,   1,  90,   1,  71,   8,   2,  26,  63,  70,  71,  93,
  94,  95,   1,  93,   8,   2,  26,  63,  70,  71,  97,  98,  99,   9,   2,   4,
  26,  63,  70,  71,  97,  98,  99,   1,  97,   9,   2,  26,  30,  63, 100, 101,
 102, 103, 104,   9,   2,  26,  30,  63, 101, 102, 105, 106, 107,   9,   2,  26,
  30,  63, 101, 102, 108, 109, 110,   1, 112,   1, 113,   1, 114,   9,   2,  26,
  30,  63, 101, 102, 116, 117, 118,   1, 116,   9,   2,  26,  30,  63, 101, 102,
 119, 120, 121,   1, 119,   4,   2,  47,  63, 126,   4,   2,  63,  70,  71,   4,
   2,  63,  82, 127,   4,   2,  63, 101, 102,   1, 128,   1,   1, 129,   1,   1,
 130,   1,   1, 131,   1,   1, 132,   1,   1, 133,   1,   1, 134,   1,   1, 135,
   1, 205,   9,   9,   2,   1,   9,   5,   1,   7,   2,   6,   9,   7,   1,   7,
   2,   8,   9,   9,   1,   7,   2,  10,   9,  11,   1,   9,  12,   1,   9,  13,
   1,   9,  14,   1,   7,   2,  15,   9,   2,   2,   9,  16,   2,   9,  17,   3,
   9,  19,   3,   7,   2,  20,   9,  21,   3,   9,  22,   3,   7,   2,  23,   7,
   2,  24,   9,  25,   3,   9,  26,   4,   9,   2,   5,   9,  29,   4,   9,  30,
   4,   9,  31,   4,   9,  32,   4,   9,  33,   6,   9,  35,   6,   9,  36,   6,
   9,  37,   6,   9,  38,   6,   9,  39,   6,   9,  48,   7,   9,  51,   7,   9,
  52,   7,   9,  53,   7,   9,  54,   7,   9,  55,   7,   9,  56,   7,   9,  57,
   7,   9,  23,   7,   7,   2,  58,  27,   7,   9,  59,   7,   9,  61,   7,   9,
  63,   7,   9,  65,   7,   9,  66,   7,   9,  67,   7,   9,  68,   7,   9,  69,
   7,   9,  70,   7,   9,  71,   7,   9,  72,   8,   9,  73,   8,   9,  74,   8,
   9,  75,   7,   9,  76,   7,   9,  77,   7,   9,  78,   9,   9,  79,   9,   9,
  80,   9,   9,  81,   9,   9,  82,   9,   9,  83,   9,   9,  84,   9,   9,  85,
   9,   9,  86,   9,   9,  87,   9,   9,  88,   9,   9,  89,   9,   9,  90,  10,
   9,  92,  10,   9,  93,  10,   9,  94,  10,   9,  95,  10,   9,  96,  10,   9,
  97,  10,   9,  98,  10,   9,  99,  10,   9, 102,  11,   9, 103,  11,   9, 104,
  11,   9, 105,  11,   9, 106,  11,   9, 107,  11,   9, 108,  11,   9, 109,  11,
   9, 110,  11,   9, 111,  11,   9, 112,  11,   9, 113,  11,   9, 114,  11,   9,
 115,  11,   9, 116,  11,   9, 117,  11,   9, 118,  11,   9, 119,  11,   9, 120,
  11,   9, 121,  11,   9, 122,  11,   9, 123,  11,   9, 124,  11,   9, 125,  11,
   9, 126,  11,   9, 127,  11,   9, 128,   1,  11,   9, 129,   1,  11,   9, 130,
   1,  11,   9, 131,   1,  11,   9, 132,   1,  11,   9, 133,   1,  11,   9, 134,
   1,  11,   9, 135,   1,  11,   9, 136,   1,  11,   9, 137,   1,  11,   9, 138,
   1,  11,   9, 139,   1,  11,   9, 140,   1,  11,   9, 141,   1,  11,   9, 142,
   1,  11,   9, 143,   1,  11,   9, 144,   1,  11,   9, 145,   1,  11,   9, 146,
   1,  11,   9, 147,   1,  11,   9, 148,   1,  11,   9, 149,   1,  11,   9, 150,
   1,  11,   9, 151,   1,  11,   9, 152,   1,  11,   9, 153,   1,  11,   9, 154,
   1,  11,   9, 155,   1,  11,   9, 156,   1,  11,   9, 157,   1,  11,   9, 158,
   1,  11,   9, 159,   1,  11,   9, 160,   1,  11,   9, 161,   1,  11,   9, 162,
   1,  11,   9, 163,   1,  11,   9, 164,   1,  11,   9, 165,   1,  11,   7,  21,
 166,   1,   7,   2, 167,   1,   9, 166,   1,  12,   9, 164,   1,  12,   9, 169,
   1,  12,   9, 165,   1,  12,   9,  31,  12,   9,  77,  12,   9, 169,   1,  13,
   9,  31,  11,   9, 170,   1,  11,   9, 171,   1,  11,   7,  10, 172,   1,   9,
 174,   1,  14,   9, 177,   1,  14,   9,  77,  14,   9, 178,   1,  14,  27,  14,
   7,  10, 176,   1,   7,   2, 175,   1,   9,  97,  11,   9, 180,   1,  11,   9,
  99,  11,   9,  98,  11,   9,  96,  11,   9,  95,  11,   9,  94,  11,   9,  93,
  11,   9,  92,  11,   7,  18,  90,   9, 182,   1,  11,   9, 183,   1,  11,   9,
 184,   1,  11,   9, 185,   1,  11,   9,  48,  11,   9,  56,  11,   9,  53,  11,
   9,  52,  11,   9,  54,  11,   9,  51,  11,   9,  55,  11,   9,  57,  11,   9,
 186,   1,  11,   9,  59,  11,   9,  61,  11,   9,  63,  11,   9, 187,   1,  11,
   9,  65,  11,   9,  66,  11,   9,  67,  11,   9, 188,   1,  11,   9,  68,  11,
   9,  69,  11,   9,  70,  11,   9, 189,   1,  11,   9, 190,   1,  11,   9, 191,
   1,  11,   9,  89,  11,   9,  88,  11,   9,  87,  11,   9,  86,  11,   9,  85,
  11,   9,  84,  11,   9,  83,  11,   9,  82,  11,   9,  81,  11,   9,  80,  11,
   9,  79,  11,   7,  16,  78,   9,  77,  11,   9,  76,  11,   7,  14,  75,   9,
 194,   1,  11,   9, 195,   1,  11,   9, 196,   1,  11,   9, 197,   1,  11,   9,
 198,   1,  11,   9, 199,   1,  11,   9,  39,  11,   9,  38,  11,   9,  37,  11,
   9,  36,  11,   9,  35,  11,   7,  12,  33,   9, 201,   1,  11,   9, 202,   1,
  11,   9, 203,   1,  11,   9, 204,   1,  11,   9, 205,   1,  11,   9, 206,   1,
  11,   9, 207,   1,  11,   9, 208,   1,  11,   9, 209,   1,  11,   9, 210,   1,
  11,   9, 211,   1,  11,   9, 212,   1,  11,   9, 213,   1,  11,   9, 214,   1,
  11,   9, 215,   1,  11,   9, 216,   1,  11,   9, 217,   1,  11,   9, 218,   1,
  11,   9, 219,   1,  11,   9, 220,   1,  11,   9, 221,   1,  11,   9, 222,   1,
  11,   9, 223,   1,  11,   9, 224,   1,  11,   9, 225,   1,  11,   9, 226,   1,
  11,   9, 227,   1,  11,   9, 228,   1,  11,   9, 229,   1,  11,   9, 230,   1,
  11,   9, 231,   1,  11,   9, 232,   1,  11,   9, 233,   1,  11,   9, 234,   1,
  11,   9,  25,  11,   9,  22,  11,   9,  21,  11,   9,  19,  11,   7,   7,  17,
   7,  41, 236,   1,   7,   2, 237,   1,   9, 238,   1,  15,   7,   2, 239,   1,
   9,  86,  15,   7,   2,  29,   9, 236,   1,  15,  27,  15,   9,  96,  15,   9,
 142,   2,  15,   9,  83,  15,   9, 143,   2,  15,   9, 144,   2,  15,   7,   2,
 145,   2,   9,  88,  15,   9, 176,   1,  15,   9, 146,   2,  15,   9,   2,  15,
   9, 149,   2,  15,   7,   2, 150,   2,   9, 236,   1,  16,   9, 143,   2,  16,
   9, 238,   1,  16,   9, 146,   2,  16,   9, 144,   2,  16,   9, 237,   1,  11,
   9, 239,   1,  11,   9,  29,  11,   9, 142,   2,  11,   9, 151,   2,  11,   9,
 152,   2,  11,   9, 153,   2,  11,   9,   4,  11,   9, 154,   2,  11,   9, 155,
   2,  11,   9, 156,   2,  11,   9, 157,   2,  11,   9, 158,   2,  11,   9,  32,
  11,   9, 159,   2,  11,   9, 160,   2,  11,   9, 161,   2,  11,   9, 162,   2,
  11,   9, 163,   2,  11,   9, 164,   2,  11,   9, 165,   2,  11,   9, 166,   2,
  11,   9, 167,   2,  11,   9,   9,  11,   9,   7,  11,   9,  11,  11,   9, 149,
   2,  11,   9, 168,   2,  11,   9,  16,  11,   9, 169,   2,  11,   9, 170,   2,
  11,   9, 171,   2,  11,   9, 172,   2,  11,   9, 173,   2,  11,   9, 174,   2,
  11,   9, 175,   2,  11,   9, 176,   2,  11,   9, 177,   2,  11,   9,   5,  11,
   9, 178,   2,  11,   7,   4,   2,   7,   4,  12,   9, 180,   2,  17,   7,  47,
 182,   2,   9, 183,   2,  17,   9, 184,   2,  17,   9, 185,   2,  17,   9,  13,
  11,   9, 186,   2,  11,   9, 180,   2,  18,   9, 185,   2,  11,   9,  14,  11,
   9, 187,   2,  11,   9, 188,   2,  11,   9, 190,   2,  11,   9, 191,   2,  11,
   9, 184,   2,  11,   9, 192,   2,  11,   7,   4, 183,   2,   9,  11,  19,   9,
 196,   2,  19,   9, 197,   2,  19,   9, 198,   2,  19,  27,  19,   9, 200,   2,
  19,   9, 201,   2,  19,   9, 202,   2,  19,   9, 203,   2,  19,   9, 204,   2,
  19,   9,  71,  19,   9, 209,   2,  19,   9,   8,  19,   9,   2,  19,   9, 163,
   2,  19,   9,  23,  19,   9, 167,   1,  19,   9, 210,   2,  19,   9, 197,   2,
  20,   9, 204,   2,  20,   9, 203,   2,  20,   9, 210,   2,  20,   9, 212,   2,
  21,   9, 213,   2,  21,   9, 214,   2,  21,   9, 215,   2,  21,   9, 209,   2,
  21,   9, 216,   2,  21,   9, 217,   2,  21,   9, 218,   2,  21,   9, 198,   2,
  11,   9, 196,   2,  11,   7,   4, 219,   2,   7,  47, 220,   2,   9, 166,   1,
  22,   9, 167,   1,  23,   9, 172,   1,  24,   9, 176,   1,  24,   9, 175,   1,
  23,   9,  90,  25,   9, 167,   1,  10,   9,  78,  26,   9, 167,   1,   9,   9,
  75,   8,   9, 167,   1,   7,   9,  33,  27,   9, 167,   1,   6,   9,  17,  28,
   9, 167,   1,   3,   9,   2,  29,   9, 167,   1,  30,   9,  12,  29,   9, 167,
   1,   2,   9, 183,   2,  29,   9, 219,   2,  29,   9, 220,   2,  31,   9, 102,
  24,   9, 166,   1,  23,   9, 102,  23,   7,  10, 102,   9, 103,  24,   9, 103,
  23,   7,  10, 103,   9, 104,  24,   9, 104,  23,   7,  10, 104,   9, 105,  24,
   9, 105,  23,   7,  10, 105,   9, 106,  24,   9, 106,  23,   7,  10, 106,   9,
 107,  24,   9, 107,  23,   7,  10, 107,   9, 108,  24,   9, 108,  23,   7,  10,
 108,   9, 109,  24,   9, 109,  23,   7,  10, 109,   9, 110,  24,   9, 110,  23,
   7,  10, 110,   9, 111,  24,   9, 111,  23,   7,  10, 111,   9, 112,  24,   9,
 112,  23,   7,  10, 112,   9, 113,  24,   9, 113,  23,   7,  10, 113,   9, 114,
  24,   9, 114,  23,   7,  10, 114,   9, 115,  24,   9, 115,  23,   7,  10, 115,
   9, 116,  24,   9, 116,  23,   7,  10, 116,   9, 117,  24,   9, 117,  23,   7,
  10, 117,   9, 118,  24,   9, 118,  23,   7,  10, 118,   9, 119,  24,   9, 119,
  23,   7,  10, 119,   9, 120,  24,   9, 120,  23,   7,  10, 120,   9, 121,  24,
   9, 121,  23,   7,  10, 121,   9, 122,  24,   9, 122,  23,   7,  10, 122,   9,
 123,  24,   9, 123,  23,   7,  10, 123,   9, 124,  24,   9, 124,  23,   7,  10,
 124,   9, 125,  24,   9, 125,  23,   7,  10, 125,   9, 126,  24,   9, 126,  23,
   7,  10, 126,   9, 127,  24,   9, 127,  23,   7,  10, 127,   9, 128,   1,  24,
   9, 128,   1,  23,   7,  10, 128,   1,   9, 129,   1,  24,   9, 129,   1,  23,
   7,  10, 129,   1,   9, 130,   1,  24,   9, 130,   1,  23,   7,  10, 130,   1,
   9, 131,   1,  24,   9, 131,   1,  23,   7,  10, 131,   1,   9, 132,   1,  24,
   9, 132,   1,  23,   7,  10, 132,   1,   9, 133,   1,  24,   9, 133,   1,  23,
   7,  10, 133,   1,   9, 134,   1,  24,   9, 134,   1,  23,   7,  10, 134,   1,
   9, 135,   1,  24,   9, 135,   1,  23,   7,  10, 135,   1,   9, 136,   1,  24,
   9, 136,   1,  23,   7,  10, 136,   1,   9, 137,   1,  24,   9, 137,   1,  23,
   7,  10, 137,   1,   9, 138,   1,  24,   9, 138,   1,  23,   7,  10, 138,   1,
   9, 139,   1,  24,   9, 139,   1,  23,   7,  10, 139,   1,   9, 140,   1,  24,
   9, 140,   1,  23,   7,  10, 140,   1,   9, 141,   1,  24,   9, 141,   1,  23,
   7,  10, 141,   1,   9, 142,   1,  24,   9, 142,   1,  23,   7,  10, 142,   1,
   9, 143,   1,  24,   9, 143,   1,  23,   7,  10, 143,   1,   9, 144,   1,  24,
   9, 144,   1,  23,   7,  10, 144,   1,   9, 145,   1,  24,   9, 145,   1,  23,
   7,  10, 145,   1,   9, 146,   1,  24,   9, 146,   1,  23,   7,  10, 146,   1,
   9, 147,   1,  24,   9, 147,   1,  23,   7,  10, 147,   1,   9, 148,   1,  24,
   9, 148,   1,  23,   7,  10, 148,   1,   9, 149,   1,  24,   9, 149,   1,  23,
   7,  10, 149,   1,   9, 150,   1,  24,   9, 150,   1,  23,   7,  10, 150,   1,
   9, 151,   1,  24,   9, 151,   1,  23,   7,  10, 151,   1,   9, 152,   1,  24,
   9, 152,   1,  23,   7,  10, 152,   1,   9, 153,   1,  24,   9, 153,   1,  23,
   7,  10, 153,   1,   9, 154,   1,  24,   9, 154,   1,  23,   7,  10, 154,   1,
   9, 155,   1,  24,   9, 155,   1,  23,   7,  10, 155,   1,   9, 156,   1,  24,
   9, 156,   1,  23,   7,  10, 156,   1,   9, 157,   1,  24,   9, 157,   1,  23,
   7,  10, 157,   1,   9, 158,   1,  24,   9, 158,   1,  23,   7,  10, 158,   1,
   9, 159,   1,  24,   9, 159,   1,  23,   7,  10, 159,   1,   9, 160,   1,  24,
   9, 160,   1,  23,   7,  10, 160,   1,   9, 161,   1,  24,   9, 161,   1,  23,
   7,  10, 161,   1,   9, 162,   1,  24,   9, 162,   1,  23,   7,  10, 162,   1,
   9, 163,   1,  24,   9, 163,   1,  23,   7,  10, 163,   1,   9,  30,  24,   9,
 172,   1,  23,   7,  10,  30,   9,  30,  23,   9,  31,  23,   9, 178,   1,  22,
   7,  21, 178,   1,   9, 178,   1,  23,  27,  32,   9,  97,  33,   7,  17,  97,
   9, 180,   1,  33,   9, 180,   1,  10,   7,  17, 180,   1,   9, 182,   1,  34,
   9, 182,   1,   9,   7,  15, 182,   1,   9, 183,   1,  34,   9, 183,   1,   9,
   7,  15, 183,   1,   9, 184,   1,  34,   9, 184,   1,   9,   7,  15, 184,   1,
   9, 185,   1,  34,   9, 185,   1,   9,   7,  15, 185,   1,   9,  48,  34,   9,
  48,   9,   7,  15,  48,   9,  56,  34,   9,  56,   9,   7,  15,  56,   9,  53,
  34,   9,  53,   9,   7,  15,  53,   9,  52,  34,   9,  52,   9,   7,  15,  52,
   9,  54,  34,   9,  54,   9,   7,  15,  54,   9,  51,  34,   9,  51,   9,   7,
  15,  51,   9,  55,  34,   9,  55,   9,   7,  15,  55,   9,  57,  34,   9,  57,
   9,   7,  15,  57,   9, 186,   1,  34,   9, 186,   1,   9,   7,  15, 186,   1,
   9,  59,  34,   9,  59,   9,   7,  15,  59,   9,  61,  34,   9,  61,   9,   7,
  15,  61,   9,  63,  34,   9,  63,   9,   7,  15,  63,   9, 187,   1,  34,   9,
 187,   1,   9,   7,  15, 187,   1,   9,  65,  34,   9,  65,   9,   7,  15,  65,
   9,  66,  34,   9,  66,   9,   7,  15,  66,   9,  67,  34,   9,  67,   9,   7,
  15,  67,   9, 188,   1,  34,   9, 188,   1,   9,   7,  15, 188,   1,   9,  68,
  34,   9,  68,   9,   7,  15,  68,   9,  69,  34,   9,  69,   9,   7,  15,  69,
   9,  70,  34,   9,  70,   9,   7,  15,  70,   9, 189,   1,  34,   9, 189,   1,
   9,   7,  15, 189,   1,   9, 190,   1,  34,   9, 190,   1,   9,   7,  15, 190,
   1,   9, 191,   1,  34,   7,  15, 191,   1,   9, 194,   1,  35,   9, 194,   1,
   6,   7,  11, 194,   1,   9, 195,   1,  35,   9, 195,   1,   6,   7,  11, 195,
   1,   9, 196,   1,  35,   9, 196,   1,   6,   7,  11, 196,   1,   9, 197,   1,
  35,   9, 197,   1,   6,   7,  11, 197,   1,   9, 198,   1,  35,   9, 198,   1,
   6,   7,  11, 198,   1,   9, 199,   1,  35,   9, 199,   1,   6,   7,  11, 199,
   1,   9, 201,   1,  36,   9, 201,   1,   3,   7,   6, 201,   1,   9, 202,   1,
  36,   9, 202,   1,   3,   7,   6, 202,   1,   9, 203,   1,  36,   9, 203,   1,
   3,   7,   6, 203,   1,   9, 204,   1,  36,   9, 204,   1,   3,   7,   6, 204,
   1,   9, 205,   1,  36,   9, 205,   1,   3,   7,   6, 205,   1,   9, 206,   1,
  36,   9, 206,   1,   3,   7,   6, 206,   1,   9, 207,   1,  36,   9, 207,   1,
   3,   7,   6, 207,   1,   9, 208,   1,  36,   9, 208,   1,   3,   7,   6, 208,
   1,   9, 209,   1,  36,   9, 209,   1,   3,   7,   6, 209,   1,   9, 210,   1,
  36,   9, 210,   1,   3,   7,   6, 210,   1,   9, 211,   1,  36,   9, 211,   1,
   3,   7,   6, 211,   1,   9, 212,   1,  36,   9, 212,   1,   3,   7,   6, 212,
   1,   9, 213,   1,  36,   9, 213,   1,   3,   7,   6, 213,   1,   9, 214,   1,
  36,   9, 214,   1,   3,   7,   6, 214,   1,   9, 215,   1,  36,   9, 215,   1,
   3,   7,   6, 215,   1,   9, 216,   1,  36,   9, 216,   1,   3,   7,   6, 216,
   1,   9, 217,   1,  36,   9, 217,   1,   3,   7,   6, 217,   1,   9, 218,   1,
  36,   9, 218,   1,   3,   7,   6, 218,   1,   9, 219,   1,  36,   9, 219,   1,
   3,   7,   6, 219,   1,   9, 220,   1,  36,   9, 220,   1,   3,   7,   6, 220,
   1,   9, 221,   1,  36,   9, 221,   1,   3,   7,   6, 221,   1,   9, 222,   1,
  36,   9, 222,   1,   3,   7,   6, 222,   1,   9, 223,   1,  36,   9, 223,   1,
   3,   7,   6, 223,   1,   9, 224,   1,  36,   9, 224,   1,   3,   7,   6, 224,
   1,   9, 225,   1,  36,   9, 225,   1,   3,   7,   6, 225,   1,   9, 226,   1,
  36,   9, 226,   1,   3,   7,   6, 226,   1,   9, 227,   1,  36,   9, 227,   1,
   3,   7,   6, 227,   1,   9, 228,   1,  36,   9, 228,   1,   3,   7,   6, 228,
   1,   9, 229,   1,  36,   9, 229,   1,   3,   7,   6, 229,   1,   9, 230,   1,
  36,   9, 230,   1,   3,   7,   6, 230,   1,   9, 231,   1,  36,   9, 231,   1,
   3,   7,   6, 231,   1,   9, 232,   1,  36,   9, 232,   1,   3,   7,   6, 232,
   1,   9, 233,   1,  36,   9, 233,   1,   3,   7,   6, 233,   1,   9, 234,   1,
  36,   9, 234,   1,   3,   7,   6, 234,   1,   9, 102,  37,   9, 103,  37,   9,
 104,  37,   9, 105,  37,   9, 106,  37,   9, 107,  37,   9, 108,  37,   9, 109,
  37,   9, 110,  37,   9, 111,  37,   9, 112,  37,   9, 113,  37,   9, 114,  37,
   9, 115,  37,   9, 116,  37,   9, 117,  37,   9, 118,  37,   9, 119,  37,   9,
 120,  37,   9, 121,  37,   9, 122,  37,   9, 123,  37,   9, 124,  37,   9, 125,
  37,   9, 126,  37,   9, 127,  37,   9, 128,   1,  37,   9, 129,   1,  37,   9,
 130,   1,  37,   9, 131,   1,  37,   9, 132,   1,  37,   9, 133,   1,  37,   9,
 134,   1,  37,   9, 135,   1,  37,   9, 136,   1,  37,   9, 137,   1,  37,   9,
 138,   1,  37,   9, 139,   1,  37,   9, 140,   1,  37,   9, 141,   1,  37,   9,
 142,   1,  37,   9, 143,   1,  37,   9, 144,   1,  37,   9, 145,   1,  37,   9,
 146,   1,  37,   9, 147,   1,  37,   9, 148,   1,  37,   9, 149,   1,  37,   9,
 150,   1,  37,   9, 151,   1,  37,   9, 152,   1,  37,   9, 153,   1,  37,   9,
 154,   1,  37,   9, 155,   1,  37,   9, 156,   1,  37,   9, 157,   1,  37,   9,
 158,   1,  37,   9, 159,   1,  37,   9, 160,   1,  37,   9, 161,   1,  37,   9,
 162,   1,  37,   9, 163,   1,  37,   9,  30,  37,   9, 172,   1,  37,   9, 176,
   1,  37,   9,  97,  38,   9, 180,   1,  38,   9,  99,  38,   9,  98,  38,   9,
  96,  38,   9,  95,  38,   9,  94,  38,   9,  93,  38,   9, 233,   2,  38,   9,
 182,   1,  39,   9, 183,   1,  39,   9, 184,   1,  39,   9, 185,   1,  39,   9,
  48,  39,   9,  56,  39,   9,  53,  39,   9,  52,  39,   9,  54,  39,   9,  51,
  39,   9,  55,  39,   9,  57,  39,   9, 186,   1,  39,   9,  59,  39,   9,  61,
  39,   9,  63,  39,   9, 187,   1,  39,   9,  65,  39,   9,  66,  39,   9,  67,
  39,   9, 188,   1,  39,   9,  68,  39,   9,  69,  39,   9,  70,  39,   9, 189,
   1,  39,   9, 190,   1,  39,   9, 191,   1,  39,   9,  89,  39,   9,  88,  39,
   9,  87,  39,   9,  86,  39,   9,  85,  39,   9,  84,  39,   9,  83,  39,   9,
  82,  39,   9,  81,  39,   9,  80,  39,   9,  79,  39,   9,  77,  40,   9,  76,
  40,   9, 238,   2,  40,   9, 194,   1,  41,   9, 195,   1,  41,   9, 196,   1,
  41,   9, 197,   1,  41,   9, 198,   1,  41,   9, 199,   1,  41,   9,  39,  41,
   9,  38,  41,   9,  37,  41,   9,  36,  41,   9,  35,  41,   9,  26,  42,   9,
 243,   2,  43,   9, 201,   1,  44,   9, 202,   1,  44,   9, 203,   1,  44,   9,
 204,   1,  44,   9, 205,   1,  44,   9, 206,   1,  44,   9, 207,   1,  44,   9,
 208,   1,  44,   9, 209,   1,  44,   9, 210,   1,  44,   9, 211,   1,  44,   9,
 212,   1,  44,   9, 213,   1,  44,   9, 214,   1,  44,   9, 215,   1,  44,   9,
 216,   1,  44,   9, 217,   1,  44,   9, 218,   1,  44,   9, 219,   1,  44,   9,
 220,   1,  44,   9, 221,   1,  44,   9, 222,   1,  44,   9, 223,   1,  44,   9,
 224,   1,  44,   9, 225,   1,  44,   9, 226,   1,  44,   9, 227,   1,  44,   9,
 228,   1,  44,   9, 229,   1,  44,   9, 230,   1,  44,   9, 231,   1,  44,   9,
 232,   1,  44,   9, 233,   1,  44,   9, 234,   1,  44,   9, 246,   2,  44,   9,
 247,   2,  44,   9, 248,   2,  44,   9, 249,   2,  44,   9,   2,  45,   9,  12,
  45,   9, 183,   2,  45,   9,  16,  45,   9, 219,   2,  45,   9, 131,   3,  11,
   9, 132,   3,  11,   7,   2, 133,   3,   9, 134,   3,  46,   9, 137,   3,  46,
   9, 138,   3,  46,   7,   2, 139,   3,   9, 140,   3,  47,   9, 141,   3,  46,
   9, 138,   3,  47,   9, 142,   3,  47,   7,   2, 144,   3,   7,   2, 146,   3,
   9, 144,   3,  11,   9, 146,   3,  11,   7,  47, 148,   3,   7,  69, 151,   3,
   9, 169,   2,  48,   9, 154,   3,  11,   7,  70, 155,   3,   9, 177,   1,  49,
   9, 158,   3,  49,   9, 161,   3,  49,   9, 177,   1,  11,   9, 158,   3,  11,
   9, 161,   3,  11,   9, 163,   3,  11,   7,  64, 164,   3,   9, 166,   3,  11,
   9, 167,   3,  11,   7,  64, 168,   3,   7,   2, 170,   3,   7,   2, 171,   3,
   7,   2, 172,   3,   7,   2, 173,   3,   9, 170,   3,  11,   9, 171,   3,  11,
   9, 172,   3,  11,   9, 173,   3,  11,   7,  65, 174,   3,   7,   2, 176,   3,
   7,   2, 177,   3,   7,   2, 178,   3,   7,   2, 179,   3,   7,   2, 180,   3,
   7,   2, 181,   3,   7,   2, 182,   3,   9, 176,   3,  11,   9, 177,   3,  11,
   9, 178,   3,  11,   9, 179,   3,  11,   9, 180,   3,  11,   9, 181,   3,  11,
   9, 182,   3,  11,   9, 183,   3,  11,   9, 184,   3,  11,   9, 185,   3,  11,
   9, 186,   3,  11,   7,  82, 188,   3,   7,   2, 190,   3,   7,   2, 192,   3,
   7,   2, 194,   3,   7,   2, 196,   3,   7,   2, 198,   3,   7,   2, 200,   3,
   9, 190,   3,  50,   9, 192,   3,  50,   9, 194,   3,  50,   9, 196,   3,  50,
   9, 198,   3,  50,   9, 200,   3,  50,   9, 175,   1,  50,   9, 190,   3,  11,
   9, 192,   3,  11,   9, 194,   3,  11,   9, 196,   3,  11,   9, 198,   3,  11,
   9, 200,   3,  11,   9, 203,   3,  11,   7,  70, 204,   3,   9, 206,   3,  51,
   7,  70, 207,   3,   9, 208,   3,  11,   9, 209,   3,  11,   9, 206,   3,  52,
   9, 210,   3,  11,   9, 211,   3,  11,   9, 212,   3,  11,   9, 213,   3,  11,
   9, 214,   3,  11,   9, 215,   3,  11,   9, 216,   3,  11,   9, 217,   3,  52,
   7,   2, 219,   3,   9, 221,   3,  53,   9, 222,   3,  53,   9, 223,   3,  53,
   9, 219,   3,  11,   9, 224,   3,  11,   9, 225,   3,  11,   9, 226,   3,  11,
   9, 221,   3,  54,   9, 222,   3,  54,   9, 223,   3,  55,   7,  70, 227,   3,
   9, 206,   3,  56,   7,  70, 229,   3,   9, 230,   3,  56,   7,  96, 232,   3,
  29, 194,   8,   1, 167,   8,   9, 206,   3,  57,   9, 233,   3,  11,   9, 234,
   3,  11,   9, 230,   3,  57,   9, 235,   3,  11,   9, 237,   3,  58,   9,  10,
  58,   9,   2,  59,   9, 155,   2,  58,   9, 156,   2,  58,   9, 157,   2,  58,
   9, 238,   3,  58,   9, 162,   2,  58,   9,  98,  58,   9, 170,   2,  58,   9,
 173,   2,  58,   9, 238,   3,  60,   9, 239,   3,  11,   9, 237,   3,  11,   9,
 240,   3,  11,   9, 241,   3,  11,   9, 242,   3,  11,   9, 243,   3,  11,   9,
 255,   2,  11,   7,  70, 151,   3,   9, 174,   1,  61,   9, 177,   1,  61,   7,
 101, 246,   3,   9, 174,   1,  62,   9, 177,   1,  62,   7, 101, 248,   3,   9,
 174,   1,  63,   9, 177,   1,  63,   7, 101, 250,   3,   7,   2, 252,   3,   7,
   2, 254,   3,   7,   2, 128,   4,   7,   2, 130,   4,   7,   2, 132,   4,   7,
   2, 134,   4,   7,   2, 136,   4,   7,   2, 138,   4,   7,   2, 140,   4,   7,
   2, 142,   4,   7,   2, 144,   4,   7,   2, 146,   4,   7,   2, 148,   4,   7,
   2, 150,   4,   7,   2, 152,   4,   7,   2, 154,   4,   9, 252,   3,  64,   9,
 254,   3,  64,   9, 128,   4,  64,   9, 130,   4,  64,   9, 132,   4,  64,   9,
 134,   4,  64,   9, 136,   4,  64,   9, 138,   4,  64,   9, 140,   4,  64,   9,
 142,   4,  64,   9, 144,   4,  65,   9, 146,   4,  66,   9, 148,   4,  64,   9,
 150,   4,  66,   9, 152,   4,  64,   9, 154,   4,  66,   7, 101, 163,   4,   9,
 177,   1,  67,   9, 166,   4,  67,   9, 167,   4,  67,   9, 168,   4,  67,   9,
 169,   4,  67,   9, 166,   4,  68,   9, 167,   4,  68,   9, 168,   4,  68,   9,
 169,   4,  68,   9, 170,   4,  64,   9, 171,   4,  64,   9, 172,   4,  64,   9,
 173,   4,  64,   7, 101, 165,   4,   9, 177,   1,  69,   9, 176,   4,  69,   9,
 176,   4,  70,   9, 177,   4,  65,   7, 101, 175,   4,   9, 179,   4,  11,   9,
 180,   4,  11,   9, 181,   4,  11,   9, 182,   4,  11,   7,  64, 183,   4,   7,
  64, 185,   4,   9, 167,   1,  71,   9, 167,   1,  72,   9, 167,   1,  46,   9,
 167,   1,  73,   9, 175,   1,  74,   9, 167,   1,  74,   9, 148,   3,  75,   9,
 155,   3,  76,   9, 164,   3,  77,   9, 168,   3,  77,   9, 183,   4,  77,   9,
 185,   4,  77,   9, 190,   4,  77,   9, 192,   4,  77,   9, 194,   4,  77,   9,
 196,   4,  77,   9, 198,   4,  77,   9, 200,   4,  77,   9, 141,   3,  47,   9,
 202,   4,  77,   9, 204,   4,  77,   9, 206,   4,  77,   9, 137,   3,  47,   9,
 208,   4,  77,   9, 210,   4,  77,   9, 211,   4,  77,   9, 212,   4,  77,   9,
 134,   3,  47,   9, 214,   4,  77,   9, 216,   4,  77,   9, 218,   4,  77,   9,
 220,   4,  77,   9, 174,   3,  47,   9, 188,   3,  78,   9, 204,   3,  79,   9,
 207,   3,  76,   9, 227,   3,  76,   9, 229,   3,  76,   9, 151,   3,  76,   9,
 246,   3,  80,   9, 248,   3,  80,   9, 250,   3,  80,   9, 163,   4,  81,   9,
 165,   4,  81,   9, 175,   4,  82, 148,   3,   0,   0,   1,   0,   1,   3,   0,
   1,   0,   0,   5,   1,   0,   0,   7,   1,   0,   0,   3,   1,   4,   0,   3,
   1,   4,   1,  12,   5,   1,   0,   0,   3,   1,   0,   1,   5,  17,   1,   0,
   1,   5,  17,   1,   0,   2,  20,   5,  21,   1,   8,   1,  10,  10,   2,  20,
   5,  21,   1,   8,   1,  10,  10,   2,  17,   5,   5,   1,   0,   2,  17,   5,
   5,   1,  32,   0,  17,   1,   0,   1,   3,  17,   1,   0,   1,   3,  17,   1,
   0,   2,  17,   5,   5,   1,   0,   1,  17,   5,   1,   0,   1,   5,  17,   1,
   0,   1,   5,  17,   1,   2,   1,   7,   5,   1,   0,   1,   5,  17,   1,   0,
   1,  17,   5,   1,   0,   1,   3,   7,   1,   0,   1,  17,   5,   1,   0,   1,
  17,   5,   1,   0,   0,  17,   1,   0,   0,   5,   1,   0,   0,   5,   1,   0,
   0,   5,   1,   0,   2,  17,   5,  17,   1,   0,   1,  17,   5,   1,   0,   2,
  17,   5,  17,   1,   0,   1,  17,   5,   1,   0,   1,   5,   5,   1,   0,   1,
  17,   5,   1,   0,   3,  17,   5,   5,  21,   1,   8,   1,  10,  10,   1,   5,
   5,   1,   0,   1,   3,  17,   1,   8,   1,   1,   3,   0,   3,   1,   0,   0,
   0,   1,   0,   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,
  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,
  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,
  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,
  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,
  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,
  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,
  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,
  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,
  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,
  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,
  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,
  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,
  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,
  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,
  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   1,
   3,  17,   1,  32,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,
   0,  17,   1,   0,   1,   3,  17,   1,   0,   0,  17,   1,   0,   0,   5,   1,
   0,   0,   0,   1,   0,   1,   0,  17,   1,   8,   1,   2,   3,   0,   0,   1,
   0,   0,  17,   1,  32,   0,  17,   1,  32,   0,   3,   1,  32,   1,   3,  17,
   1,  40,   1,   2,   3,   1,   5,   5,   1,  32,   3,  17,   5,   5,  17,   1,
  32,   1,  17,   5,   1,  32,   1,   5,   5,   1,  32,   1,  17,   5,   1,  32,
   0,   0,   1,   0,   0,   0,   1,   0,   0,  17,   1,  32,   0,  17,   1,  32,
   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,
   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,
   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,
   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,
   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,
   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,
   0,  17,   1,  32,   2,  17,   5,  17,   1,  32,   1,  17,   5,   1,  32,   2,
  17,   5,  17,   1,  32,   0,   5,   1,  32,   0,   5,   1,  32,   0,   5,   1,
  32,   0,  17,   1,  32,   1,  17,   5,   1,  32,   1,  17,   5,   1,  32,   1,
   3,   7,   1,  32,   1,  17,   5,   1,  32,   0,   0,   1,   0,   0,   0,   1,
   0,   1,   5,  17,   1,  32,   1,   7,   5,   1,  32,   0,   0,   1,   0,   0,
   0,   1,   0,   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,
  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   1,  17,   5,   1,  32,
   2,  17,   5,   5,   1,  32,   1,   3,  17,   1,  32,   1,   3,  17,   1,  32,
   0,  17,   1,  32,   0,   0,   1,   0,   0,   0,   1,   0,   0,  17,   1,  32,
   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,
   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,
   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,
   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,
   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,
   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,
   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,
   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,   0,  17,   1,  32,
   0,  17,   1,  32,   2,  20,   5,  21,   1,  32,   2,  20,   5,  21,   1,  32,
   1,   5,  17,   1,  32,   1,   5,  17,   1,  32,   0,   0,   1,   0,   0,   0,
   1,   0,   0,  20,   1,  32,   1,   5,   5,   1,  32,   0,   5,   1,   0,   0,
  17,   1,  32,   0,   5,   1,   0,   0,  17,   1,   0,   0,   5,   1,  32,   0,
   5,   1,   0,   0,  17,   1,  32,   0, 155,   2,   1,  32,   0, 155,   2,   1,
  32,   0, 155,   2,   1,  32,   0,   5,   1,   0,   1,   3,   5,   1,   0,   1,
   3,  17,   1,   0,   1,   3,   5,   1,  32,   1,  17,   5,   1,  32,   1,   3,
  17,   1,  40,   1,   1,   3,   1,   5,   5,   1,   0,   0,   5,   1,  32,   0,
  20,   1,  32,   0,   5,   1,   0,   0,   5,   1,  32,   0, 155,   2,   1,  32,
   0,   5,   1,  32,   0,   7,   1,  32,   0,   5,   1,  32,   1,   3,  17,   1,
  32,   1,   3,  20,   1,  32,   1,   3,   5,   1,  32,   1,   3,   5,   1,   0,
   0,   3,   1,  32,   0,  21,   1,  32,   0,   3,   1,  32,   0,   3,   1,  32,
   1,   3, 155,   2,   1,  40,   1,   1,   6,   1,   3, 161,   2,   1,  32,   1,
  21, 148,   1,   1,  32,   0,  21,   1,  32,   1,  21,   0,   1,  32,   1,   0,
   0,   1,  32,   1,   3,  17,   1,  32,   1,   3,  44,   1,  32,   0,   0,   1,
   0,   0,   0,   1,   0,   0, 208,   2,   1,  32,   0,   7,   1,  32,   1,   3,
 208,   2,   1,  32,   1,   0, 208,   2,   1,   0,   2,   0, 210,   2,   7,   1,
  40,   1,   2,   3,   1,  12,   5,   1,  32,   2,   0,   5,   7,   1,   8,   1,
   2,   3,   0, 210,   2,   1,  32,   1,   0, 210,   2,   1,  32,   0,   0,   1,
   0,   1,  21,   5,   1,  32,   1,   5,   5,   1,  32,   2,   3,   5,   5,   1,
  32,   1, 210,   2,   5,   1,  32,   2,  21,   5, 210,   2,   1,  32,   0,   0,
   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   3,   1,   0,   1,   0,
   0,   1,   4,   1,  21,   0,   1,   0,   1,   0,   0,   1,   0,   2,   3,   0,
   0,   1,   0,   1,  21,   0,   1,   0,   1,  17,  17,   1,   0,   1,   5,  17,
   1,   0,   1,   0,  17,   1,   0,   0,   7,   1,   0,   0,   3,   1,   0,   0,
   0,   1,   0,   1,   5,   5,   1,  32,   1, 148,   1,  44,   1,  32,   1,  20,
  44,   1,  32,   2,  21, 148,   1, 216,   7,   1,  32,   3, 155,   2, 148,   1,
 216,   7,   7,   1,  32,   2, 155,   2, 148,   1, 216,   7,   1,   0,   2, 155,
   2, 148,   1, 216,   7,   1,   0,   2, 155,   2, 148,   1, 216,   7,   1,   0,
   0, 155,   2,   1,  32,   1, 148,   1,  12,   1,  32,   0, 148,   1,   1,   0,
   2, 148,   1, 148,   1,  21,   1,  40,   1,  10,  10,   1, 155,   2,   0,   1,
  32,   1,   3,  44,   1,  32,   0,   0,   1,   2,   1,   3,  44,   1,   2,   1,
   3,  21,   1,  32,   0,   3,   1,  32,   0,   3,   1,  32,   0,   3,   1,  32,
   0,   3,   1,  32,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   5,   1,   0,   0,  21,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   5,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,
   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   2,   0,  17,  17,
   1,  40,   1,   3,   3,   1,  17,  17,   1,  40,   1,   3,   3,   1,   0,  44,
   1,  32,   0,  44,   1,  32,   0,   0,   1,   0,   0,   0,   1,   0,   1,  17,
   5,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0, 167,   8,   1,   0,
   1,   3,   5,   1,  32,   0,   0,   1,   0,   0,   5,   1,  32,   0,   3,   1,
  32,   1,  21, 167,   8,   1,  32,   0,  21,   1,  32,   2,   3,   5,   0,   1,
  32,   1,   0,   5,   1,  32,   0,  21,   1,  32,   0,   0,   1,   0,   2,   0,
   5,   5,   1,   0,   0,   5,   1,   0,   0,   5,   1,   0,   0, 148,   1,   1,
   0,   0,   0,   1,   0,   0, 192,   8,   1,   0,   0,   0,   1,   0,   1, 167,
   8, 210,   2,   1,   0,   0, 167,   8,   1,   0,   1, 167,   8, 210,   2,   1,
  32,   0, 195,   8,   1,  32,   0,   0,   1,   0,   1,   3,   5,   1,   0,   0,
   7,   1,   0,   0, 155,   2,   1,   0,   0, 155,   2,   1,   0,   0, 155,   2,
   1,   0,   0,  21,   1,   0,   1,   3,  21,   1,   0,   0,   5,   1,   0,   0,
   3,   1,   0,   0,   3,   1,   0,   1,   3,   7,   1,   0,   0,   3,   1,   0,
   1,   3, 161,   2,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   1,   0,
   5,   1,   8,   1,   1,   1,   0,   0,   1,   0,   1,   0,   5,   1,   8,   1,
   1,   1,   0,   0,   1,   0,   2,   0,   5,  17,   1,   8,   2,   1,   1,   2,
   3,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   6,   0,   5,
   5,   5,  17,  17,  20,   1,   8,   5,   1,   1,   1,   1,   2,   3,   1,   3,
  12,  12,   0,   5,   1,   0,   0,   5,   1,   0,   0,  17,   1,   0,   0,  20,
   1,   0,   0,   0,   1,   0,   3,   0,   5,  17,  17,   1,   0,   0,  17,   1,
   0,   0,   0,   1,   0,   0,   0,   1,  32,   0, 155,   2,   1,  32,   0,   0,
   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,   0,   0,   1,   0,  35, 221,
   2,   1, 222,   2, 223,   2, 224,   2,   3, 225,   2, 227,   2, 229,   2, 226,
   2, 228,   2, 223,   2, 224,   2,   3, 225,   2, 227,   2, 229,   2, 231,   2,
 228,   2, 223,   2, 224,   2,   3, 225,   2, 227,   2, 229,   2, 234,   2, 228,
   2, 223,   2, 224,   2,   3, 225,   2, 227,   2, 229,   2, 236,   2, 228,   2,
 223,   2, 224,   2,   3, 225,   2, 227,   2, 229,   2, 239,   2, 228,   2, 223,
   2, 224,   2,   1,   0, 241,   2, 224,   2,   3, 225,   2, 227,   2, 229,   2,
 244,   2, 228,   2, 223,   2, 224,   2,   4, 225,   2, 252,   2, 227,   2, 229,
   2, 251,   2, 253,   2, 228,   2, 223,   2, 224,   2,   4, 225,   2, 255,   2,
 128,   3, 227,   2, 254,   2, 253,   2, 129,   3, 228,   2, 224,   2,   3, 225,
   2, 227,   2, 229,   2, 130,   3, 228,   2, 223,   2, 157,   4,   1,   0, 158,
   4, 157,   4,   1,   0, 160,   4, 157,   4,   1,   0, 162,   4, 224,   2,   3,
 225,   2, 128,   3, 227,   2, 173,   3, 189,   4, 228,   2, 224,   2,   1,   0,
 191,   4, 224,   2,   1,   0, 193,   4, 224,   2,   1,   0, 195,   4, 224,   2,
   1,   0, 197,   4, 224,   2,   1,   0, 199,   4, 224,   2,   1,   0, 201,   4,
 224,   2,   1,   0, 203,   4, 224,   2,   1,   0, 205,   4, 224,   2,   1,   0,
 207,   4, 224,   2,   1,   0, 209,   4, 224,   2,   1,   0, 213,   4, 224,   2,
   1,   0, 215,   4, 224,   2,   1,   0, 217,   4, 224,   2,   1,   0, 219,   4,
 224,   2,   1,   0, 221,   4, 157,   4,   1,   0, 222,   4, 224,   2,   3, 225,
   2, 227,   2, 229,   2, 224,   4, 228,   2, 223,   2, 157,   4,   1,   0, 226,
   4, 224,   2,   4, 225,   2, 128,   3, 227,   2, 229,   2, 227,   4, 228,   4,
 228,   2, 224,   2, 224,   2,   3, 225,   2, 128,   3, 227,   2, 229,   4, 230,
   4, 228,   2,  31, 147,   1, 148,   1,   9,  22,   0, 106,   0, 159,   1, 148,
   1,   9,  24,   0, 108,   5, 155,   1,   0,   0,  17,   0, 156,   1,   2,   0,
 109, 156,   1,   3,   0, 110, 157,   1,   1,   0, 111, 158,   1,   1,   0, 112,
 165,   1, 166,   1,   8,  28,   0, 114,   0, 176,   1, 148,   1,   9,  32,   0,
 125,   0, 215,   1, 148,   1,   9,  34,   0, 165,   1,   0, 218,   1, 148,   1,
   9,  36,   0, 169,   1,   0, 230,   1, 148,   1,   9,  38,   0, 182,   1,   0,
 141,   2, 148,   1,   9,  40,   0, 222,   1,   0, 207,   2, 148,   1,   9,  42,
   0, 139,   2,   0, 208,   2, 148,   1,   9,  45,   0, 144,   2,   6, 216,   2,
   1,   0, 143,   2, 217,   2,   1,   0, 145,   2, 218,   2,   1,   0, 146,   2,
 219,   2,   1,   0, 147,   2, 220,   2,   2,   0, 148,   2, 220,   2,   3,   0,
 149,   2, 225,   2, 148,   1,   9,  49,   0, 156,   2,   0, 130,   3, 131,   3,
   8,  51,   0, 158,   2,  14, 244,   2,   0,   0,  20,   0, 245,   2,   0,   0,
  20,   0, 246,   2,   0,   0, 148,   1,   0, 247,   2,   1,   0, 159,   2, 248,
   2,  33,   0, 160,   2, 249,   2,  33,   0, 161,   2, 250,   2,  33,   0, 162,
   2, 251,   2,  33,   0, 163,   2, 252,   2,  33,   0, 164,   2, 253,   2,  33,
   0, 165,   2, 254,   2,  33,   0, 166,   2, 255,   2,  33,   0, 167,   2, 128,
   3,   2,   0, 168,   2, 129,   3,   1,   0, 169,   2, 229,   7, 148,   1,   9,
  67,   0, 193,   2,   0, 233,   7, 148,   1,  11,  72,   0, 197,   2,   0, 241,
   7, 148,   1,  11,  75,   0, 200,   2,   5, 237,   7,   6,   0,   5,   0, 238,
   7,   6,   0,   5,   0, 239,   7,   6,   0,   7,   0, 240,   7,   6,   0, 155,
   2,   0, 158,   1,   1,   0, 199,   2, 244,   7, 148,   1,   9,  78,   0, 202,
   2,   2, 242,   7,   6,   0, 155,   2,   0, 243,   7,   6,   0,  20,   0, 253,
   7, 148,   1,  11,  80,   0, 204,   2,   0, 144,   8, 148,   1,   9,  83,   0,
 210,   2,   0, 165,   8, 148,   1,  11,  85,   0, 213,   2,   0, 167,   8, 148,
   1,  11,  88,   0, 217,   2,   8, 171,   8,   2,   0, 218,   2, 172,   8,   1,
   0, 219,   2, 173,   8,   1,   0, 220,   2, 174,   8,   2,   0, 221,   2, 175,
   8,   1,   0, 222,   2, 176,   8,   1,   0, 223,   2, 177,   8,   1,   0, 224,
   2, 178,   8,   0,   0, 210,   2,   0, 190,   8, 148,   1,  11,  91,   0, 226,
   2,   6, 184,   8,   2,   0, 227,   2, 185,   8,   2,   0, 228,   2, 186,   8,
   2,   0, 229,   2, 187,   8,   0,   0,   5,   0, 188,   8,   0,   0,   5,   0,
 189,   8,   0,   0, 148,   1,   0, 192,   8, 148,   1,  11,  94,   0, 232,   2,
   4, 197,   8,   1,   0, 233,   2, 198,   8,   1,   0, 234,   2, 199,   8,   1,
   0, 235,   2, 200,   8,   1,   0, 236,   2, 220,   8, 148,   1,  11,  98,   0,
 251,   2,   0, 223,   8, 166,   1,   8, 103,   0, 253,   2,   0, 226,   8, 166,
   1,   8, 106,   0, 255,   2,   0, 229,   8, 166,   1,   8, 109,   0, 129,   3,
   0, 134,   9, 148,   1,   9, 115,   0, 131,   3,   0, 148,   9, 166,   1,   9,
 117,   0, 133,   3,   8, 140,   9,   0,   0,   5,   0, 141,   9,   0,   0,   5,
   0, 142,   9,   0,   0,  17,   0, 143,   9,   0,   0,  20,   0, 144,   9,  66,
   0, 134,   3,   1,  11, 145,   9,  66,   0, 135,   3,   1,  11, 146,   9,  66,
   0, 136,   3,   1,  11, 147,   9,  66,   0, 137,   3,   1,  11, 153,   9, 166,
   1,   9, 120,   0, 139,   3,   2, 151,   9,   0,   0,  17,   0, 152,   9,  66,
   0, 140,   3,   1,  12, 158,   9, 244,   7,  11, 123,   0, 144,   3,   4, 154,
   9,   6,   0, 155,   2,   0, 155,   9,   6,   0,  12,   0, 156,   9,   2,   0,
 142,   3, 157,   9,   2,   0, 143,   3, 159,   9, 244,   7,  11, 125,   0, 146,
   3,   2, 154,   9,   6,   0, 155,   2,   0, 157,   9,   6,   0, 155,   2,   0,
  41,  64,  83,  18,   3,  42,  84,  18,   4,  43,  85,  18,   5,  44,  86,  18,
   6,  45,  87,  18,   7,  46,  88,  18,   8,  47,  89,  18,   9,  48,  90,  18,
  10,  49,  91,  18,  11,  50,  92,  18,  12,  51,  93,  18,  13,  52,  94,  18,
  14,  53,  95,  18,  15,  54,  96,  18,  16,  55,  97,  18,  17,  56,  98,  18,
  18,  57,  99,  18,  19,  58, 100,  18,  20,  59, 101,  18,  21,  60, 102,  18,
  22,  61, 103,  18,  23,  62, 104,  18,  24,  63, 105,  18,  25,  64, 106,  18,
  26,  65, 107,  18,  27,  66, 108,  18,  28,  67, 109,  18,  29,  68, 110,  18,
  30,  69, 111,  18,  31,  70, 112,  18,  32,  71, 113,  18,  33,  72, 114,  18,
  34,  73, 115,  18,  35,  74, 116,  18,  36,  75, 117,  18,  37,  76, 118,  18,
  38,  77, 119,  18,  39,  78, 120,  18,  40,  79, 121,  18,  41,  80, 122,  18,
  42,  81, 123,  18,  43,  82, 124,  18,  44,  83, 125,  18,  45,  84, 126,  18,
  46,  85, 127,  18,  47,  86, 128,   1,  18,  48,  87, 129,   1,  18,  49,  88,
 130,   1,  18,  50,  89, 131,   1,  18,  51,  90, 132,   1,  18,  52,  91, 133,
   1,  18,  53,  92, 134,   1,  18,  54,  93, 135,   1,  18,  55,  94, 136,   1,
  18,  56,  95, 137,   1,  18,  57,  96, 138,   1,  18,  58,  97, 139,   1,  18,
  59,  98, 140,   1,  18,  60,  99, 141,   1,  18,  61, 100, 142,   1,  18,  62,
 101, 143,   1,  18,  63, 102, 144,   1,  18,  64, 103, 145,   1,  17,  65, 104,
 146,   1,  17,  66, 105, 107,   0, 113,   0, 115,   9, 167,   1,  18,   3, 116,
 168,   1,  18,   4, 117, 169,   1,  17,   5, 118, 170,   1,  17,   6, 119, 171,
   1,  17,   7, 120, 172,   1,  17,   8, 121, 173,   1,  17,   9, 122, 174,   1,
  17,  10, 123, 175,   1,  17,  11, 124, 126,  38, 177,   1,  18,   3, 127, 178,
   1,  18,   4, 128,   1, 179,   1,  18,   5, 129,   1, 180,   1,  18,   6, 130,
   1, 181,   1,  18,   7, 131,   1, 182,   1,  18,   8, 132,   1, 183,   1,  18,
   9, 133,   1, 184,   1,  18,  10, 134,   1, 185,   1,  18,  11, 135,   1, 186,
   1,  18,  12, 136,   1, 187,   1,  18,  13, 137,   1, 188,   1,  18,  14, 138,
   1, 189,   1,  18,  15, 139,   1, 190,   1,  18,  16, 140,   1, 191,   1,  18,
  17, 141,   1, 192,   1,  18,  18, 142,   1, 193,   1,  18,  19, 143,   1, 194,
   1,  18,  20, 144,   1, 195,   1,  18,  21, 145,   1, 196,   1,  18,  22, 146,
   1, 197,   1,  18,  23, 147,   1, 198,   1,  18,  24, 148,   1, 199,   1,  18,
  25, 149,   1, 200,   1,  18,  26, 150,   1, 201,   1,  18,  27, 151,   1, 202,
   1,  18,  28, 152,   1, 203,   1,  18,  29, 153,   1, 204,   1,  17,  30, 154,
   1, 205,   1,  17,  31, 155,   1, 206,   1,  17,  32, 156,   1, 207,   1,  17,
  33, 157,   1, 208,   1,  17,  34, 158,   1, 209,   1,  17,  35, 159,   1, 210,
   1,  17,  36, 160,   1, 211,   1,  17,  37, 161,   1, 212,   1,  17,  38, 162,
   1, 213,   1,  17,  39, 163,   1, 214,   1,  17,  40, 164,   1, 166,   1,   2,
 216,   1,  17,   3, 167,   1, 217,   1,  17,   4, 168,   1, 170,   1,  11, 219,
   1,  18,   3, 171,   1, 220,   1,  18,   4, 172,   1, 221,   1,  18,   5, 173,
   1, 222,   1,  18,   6, 174,   1, 223,   1,  18,   7, 175,   1, 224,   1,  18,
   8, 176,   1, 225,   1,  17,   9, 177,   1, 226,   1,  17,  10, 178,   1, 227,
   1,  17,  11, 179,   1, 228,   1,  17,  12, 180,   1, 229,   1,  17,  13, 181,
   1, 183,   1,  38, 231,   1,  18,   3, 184,   1, 232,   1,  18,   4, 185,   1,
 233,   1,  18,   5, 186,   1, 234,   1,  18,   6, 187,   1, 235,   1,  18,   7,
 188,   1, 236,   1,  18,   8, 189,   1, 237,   1,  18,   9, 190,   1, 238,   1,
  18,  10, 191,   1, 239,   1,  18,  11, 192,   1, 240,   1,  18,  12, 193,   1,
 241,   1,  18,  13, 194,   1, 242,   1,  18,  14, 195,   1, 243,   1,  18,  15,
 196,   1, 244,   1,  18,  16, 197,   1, 245,   1,  18,  17, 198,   1, 246,   1,
  18,  18, 199,   1, 247,   1,  18,  19, 200,   1, 248,   1,  18,  20, 201,   1,
 249,   1,  18,  21, 202,   1, 250,   1,  18,  22, 203,   1, 251,   1,  18,  23,
 204,   1, 252,   1,  18,  24, 205,   1, 253,   1,  18,  25, 206,   1, 254,   1,
  18,  26, 207,   1, 255,   1,  18,  27, 208,   1, 128,   2,  18,  28, 209,   1,
 129,   2,  18,  29, 210,   1, 130,   2,  18,  30, 211,   1, 131,   2,  18,  31,
 212,   1, 132,   2,  18,  32, 213,   1, 133,   2,  18,  33, 214,   1, 134,   2,
  18,  34, 215,   1, 135,   2,  18,  35, 216,   1, 136,   2,  18,  36, 217,   1,
 137,   2,  17,  37, 218,   1, 138,   2,  17,  38, 219,   1, 139,   2,  17,  39,
 220,   1, 140,   2,  17,  40, 221,   1, 223,   1,  48, 162,   2,   0,   1,  20,
   0, 163,   2,   0,   2,   5,   0, 164,   2,  17,   3, 224,   1, 165,   2,  17,
   4, 225,   1, 166,   2,  17,   5, 226,   1, 167,   2,   6,   3,  20,   0, 168,
   2,   6,   4,   5,   0, 169,   2,   0,   5,  21,  10,  10, 170,   2,  18,   6,
 227,   1, 171,   2,  18,   7, 228,   1, 172,   2,  18,   8, 229,   1, 173,   2,
  18,   9, 230,   1, 174,   2,  18,  10, 231,   1, 175,   2,  18,  11, 232,   1,
 176,   2,  18,  12, 233,   1, 177,   2,  18,  13, 234,   1, 178,   2,  18,  14,
 235,   1, 179,   2,  18,  15, 236,   1, 179,   2,  19,  16, 237,   1, 180,   2,
  17,  17, 238,   1, 181,   2,  17,  18, 239,   1, 182,   2,  17,  19, 240,   1,
 170,   1,  17,  20, 241,   1, 183,   2,  17,  21, 242,   1, 184,   2,  17,  22,
 243,   1, 185,   2,  17,  23, 244,   1, 186,   2,  17,  24, 245,   1, 187,   2,
  17,  25, 246,   1, 188,   2,  17,  26, 247,   1, 189,   2,  17,  27, 248,   1,
 190,   2,  17,  28, 249,   1, 191,   2,  17,  29, 250,   1, 213,   1,  17,  30,
 251,   1, 192,   2,  17,  31, 252,   1, 193,   2,  17,  32, 253,   1, 194,   2,
  17,  33, 254,   1, 195,   2,  17,  34, 255,   1, 196,   2,  17,  35, 128,   2,
 197,   2,  17,  36, 129,   2, 198,   2,  17,  37, 130,   2, 199,   2,  17,  38,
 131,   2, 200,   2,  17,  39, 132,   2, 201,   2,  17,  40, 133,   2, 202,   2,
  17,  41, 134,   2, 203,   2,  17,  42, 135,   2, 204,   2,  17,  43, 136,   2,
 205,   2,  17,  44, 137,   2, 206,   2,  17,  45, 138,   2, 140,   2,   2, 214,
   2,  18,   3, 141,   2, 215,   2,  18,   4, 142,   2, 150,   2,   5, 221,   2,
  17,   3, 151,   2, 222,   2,  17,   4, 152,   2, 193,   2,  17,   5, 153,   2,
 223,   2,  17,   6, 154,   2, 224,   2,  17,   7, 155,   2, 157,   2,   0, 192,
   2,   2, 227,   7,   6,   1,   5, 145,   3,   1, 228,   7,   6,   2,   5, 147,
   3,   1, 194,   2,   2, 232,   7,  18,   3, 195,   2, 196,   2,  18,   4, 196,
   2, 198,   2,   0, 201,   2,   0, 203,   2,   4, 249,   7,   6,   1,  12,   0,
 250,   7,   6,   2,  12,   0, 251,   7,   6,   3,  12,   0, 252,   7,   6,   4,
  12,   0, 205,   2,  11, 133,   8,   6,   1,  17,   2,   3, 134,   8,   6,   2,
  17,   4,   3, 135,   8,   6,   3,  17,   3,   3, 136,   8,   6,   4,  17,   5,
   3, 137,   8,   6,   5,  17,   6,   3, 138,   8,   6,   6,   0,   4,   3, 139,
   8,   6,   7,   0,   3,   3, 140,   8,  17,   3, 206,   2, 141,   8,  17,   4,
 207,   2, 142,   8,  17,   5, 208,   2, 143,   8,  17,   6, 209,   2, 211,   2,
   7, 158,   8,   6,   1,   5, 191,   3,   1, 159,   8,   6,   2,   5, 193,   3,
   1, 160,   8,   6,   3,   5, 195,   3,   1, 161,   8,   6,   4,   5, 197,   3,
   1, 162,   8,   6,   5,   5, 199,   3,   1, 163,   8,   6,   6,   5, 201,   3,
   1, 164,   8,  17,   3, 212,   2, 214,   2,   3, 168,   8,  18,   3, 215,   2,
 169,   8,  17,   4, 216,   2, 170,   8,   0,   1, 167,   8,   0, 225,   2,   1,
 183,   8,   6,   1,   5, 220,   3,   1, 230,   2,   2, 168,   8,  18,   3, 231,
   2, 196,   8,   0,   1, 192,   8,   0, 237,   2,  14, 212,   8,   0,   1,  21,
   0, 213,   8,  17,   3, 238,   2, 176,   2,  18,   4, 239,   2, 214,   8,  18,
   5, 240,   2, 177,   2,  18,   6, 241,   2, 178,   2,  18,   7, 242,   2, 215,
   8,  18,   8, 243,   2, 215,   8,  19,   9, 244,   2, 216,   8,  18,  10, 245,
   2, 217,   8,  17,  11, 246,   2, 218,   8,  17,  12, 247,   2, 170,   1,  17,
  13, 248,   2, 219,   8,  17,  14, 249,   2, 200,   2,  17,  15, 250,   2, 252,
   2,   0, 254,   2,   0, 128,   3,   0, 130,   3,  16, 246,   8,  70,   1,   5,
 253,   3,   1,   1,  11, 247,   8,  70,   2,   5, 255,   3,   1,   1,  11, 248,
   8,  70,   3,   5, 129,   4,   1,   1,  11, 249,   8,  70,   4,   5, 131,   4,
   1,   1,  11, 250,   8,  70,   5,   5, 133,   4,   1,   1,  11, 251,   8,  70,
   6,   5, 135,   4,   1,   1,  11, 252,   8,  70,   7,   5, 137,   4,   1,   1,
  11, 253,   8,  70,   8,   5, 139,   4,   1,   1,  11, 254,   8,  70,   9,   5,
 141,   4,   1,   1,  11, 255,   8,  70,  10,   5, 143,   4,   1,   1,  11, 128,
   9,  70,  11,   5, 145,   4,   1,   1,  12, 129,   9,  70,  12,   5, 147,   4,
   1,   1,  13, 130,   9,  70,  13,   5, 149,   4,   1,   1,  11, 131,   9,  70,
  14,   5, 151,   4,   1,   1,  13, 132,   9,  70,  15,   5, 153,   4,   1,   1,
  11, 133,   9,  70,  16,   5, 155,   4,   1,   1,  13, 132,   3,   0, 138,   3,
   0, 141,   3,   0, 145,   3,   0,   3, 170,   2, 184,   1, 132,   3,  68,   0,
   0,   2,   0,   1, 171,   6,   6,   0,  17,   0, 172,   6,   6,   0,  17,   0,
 173,   6,   6,   0,  17,   0, 174,   6,   6,   0,  17,   0, 175,   6,   6,   0,
  17,   0, 176,   6,   6,   0,  17,   0, 177,   6,   6,   0,  17,   0, 178,   6,
   6,   0,  17,   0, 179,   6,   6,   0,  17,   0, 180,   6,   6,   0,  17,   0,
 181,   6,   6,   0,  17,   0, 182,   6,   6,   0,  17,   0, 183,   6,   6,   0,
  17,   0, 184,   6,   6,   0,  17,   0, 185,   6,   6,   0,  17,   0, 186,   6,
   6,   0,  17,   0, 187,   6,   6,   0,  17,   0, 188,   6,   6,   0,  17,   0,
 189,   6,   6,   0,  17,   0, 190,   6,   6,   0,  17,   0, 191,   6,   6,   0,
  17,   0, 192,   6,   6,   0,  17,   0, 193,   6,   6,   0,  17,   0, 194,   6,
   6,   0,  17,   0, 195,   6,   6,   0,  17,   0, 196,   6,   6,   0,  17,   0,
 197,   6,   6,   0,  17,   0, 198,   6,   6,   0,  17,   0, 199,   6,   6,   0,
  17,   0, 200,   6,   6,   0,  17,   0, 201,   6,   6,   0,  17,   0, 202,   6,
   6,   0,  17,   0, 203,   6,   6,   0,  17,   0, 204,   6,   6,   0,  17,   0,
 205,   6,   6,   0,  17,   0, 206,   6,   6,   0,  17,   0, 207,   6,   6,   0,
  17,   0, 208,   6,   6,   0,  17,   0, 209,   6,   6,   0,  17,   0, 210,   6,
   6,   0,  17,   0, 211,   6,   6,   0,  17,   0, 212,   6,   6,   0,  17,   0,
 213,   6,   6,   0,  17,   0, 214,   6,   6,   0,  17,   0, 215,   6,   6,   0,
  17,   0, 216,   6,   6,   0,  17,   0, 217,   6,   6,   0,  17,   0, 218,   6,
   6,   0,  17,   0, 219,   6,   6,   0,  17,   0, 220,   6,   6,   0,  17,   0,
 221,   6,   6,   0,  17,   0, 222,   6,   6,   0,  17,   0, 223,   6,   6,   0,
  17,   0, 224,   6,   6,   0,  17,   0, 225,   6,   6,   0,  17,   0, 226,   6,
   6,   0,  17,   0, 227,   6,   6,   0,  17,   0, 228,   6,   6,   0,  17,   0,
 229,   6,   6,   0,  17,   0, 230,   6,   6,   0,  17,   0, 231,   6,   6,   0,
  17,   0, 232,   6,   6,   0,  17,   0, 233,   6,   6,   0, 159,   1,   0, 234,
   6,   4,   0,   1, 218,   4,   6,   0, 148,   1,   0, 235,   6,   4,   0,   2,
 137,   3,  68,   0,   3,   2,   0,   2, 236,   6,   6,   0,  17,   0, 237,   6,
   6,   0,  17,   0, 238,   6,   1,   1,  40, 239,   6,   1,   2,  39, 240,   6,
   1,   3,  38, 241,   6,   1,   4,  37, 242,   6,   1,   5,  36, 243,   6,   1,
   6,  35, 244,   6,   1,   7,  34, 139,   3,  68,   0,   4,   2,   0,   3, 245,
   6,   6,   0,  17,   0, 246,   6,   6,   0,  17,   0, 247,   6,   6,   0,  17,
   0, 248,   6,   6,   0,  17,   0, 249,   6,   6,   0,  17,   0, 250,   6,   6,
   0,  17,   0, 251,   6,   6,   0,  17,   0, 252,   6,   6,   0,  17,   0, 253,
   6,   6,   0,  17,   0, 254,   6,   6,   0,  17,   0, 255,   6,   6,   0,  17,
   0, 128,   7,   6,   0,  17,   0, 129,   7,   6,   0,  17,   0, 130,   7,   6,
   0,  17,   0, 131,   7,   6,   0,  17,   0, 132,   7,   6,   0,  17,   0, 133,
   7,   6,   0,  17,   0, 134,   7,   6,   0,  17,   0, 135,   7,   6,   0,  17,
   0, 136,   7,   6,   0,  17,   0, 137,   7,   6,   0,  17,   0, 138,   7,   6,
   0,  17,   0, 139,   7,   6,   0,  17,   0, 140,   7,   6,   0,  17,   0, 141,
   7,   6,   0,  17,   0, 142,   7,   6,   0,  17,   0, 143,   7,   6,   0,  17,
   0, 144,   7,   1,   8,  33, 145,   7,   1,   9,  32, 146,   7,   1,  10,  31,
 147,   7,   1,  11,  30, 148,   7,   1,  12,  29, 149,   7,   1,  13,  28, 150,
   7,   1,  14,  27, 151,   7,   1,  15,  26, 152,   7,   1,  16,  25, 153,   7,
   1,  17,  24, 154,   7,   1,  18,  23, 141,   3,  68,   0,   5,   2,   0,   4,
 155,   7,   1,  19,  22, 156,   7,   1,  20,  21, 157,   7,   1,  21,  20, 143,
   3,  68,   0,   6,   2,   0,   5, 158,   7,   6,   0,  17,   0, 159,   7,   6,
   0,  17,   0, 160,   7,   6,   0,  17,   0, 161,   7,   6,   0,  17,   0, 162,
   7,   6,   0,  17,   0, 163,   7,   6,   0,  17,   0, 164,   7,   1,  22,  18,
 165,   7,   1,  23,  17, 166,   7,   1,  24,  16, 167,   7,   1,  25,  15, 168,
   7,   1,  26,  14, 169,   7,  65,  27,  13,   1,   6, 170,   7,   1,  28,  12,
 145,   3,  68,   0,   7,   2,   0,   7, 171,   7,   6,   0,  17,   0, 172,   7,
   6,   0,  17,   0, 173,   7,   6,   0,  17,   0, 174,   7,   6,   0,  17,   0,
 175,   7,   6,   0,  17,   0, 176,   7,   6,   0,  17,   0, 177,   7,   6,   0,
  17,   0, 178,   7,   6,   0,  17,   0, 179,   7,   6,   0,  17,   0, 180,   7,
   6,   0,  17,   0, 181,   7,   6,   0,  17,   0, 182,   7,   6,   0,  17,   0,
 183,   7,   6,   0,  17,   0, 184,   7,   6,   0,  17,   0, 185,   7,   6,   0,
  17,   0, 186,   7,   6,   0,  17,   0, 187,   7,   6,   0,  17,   0, 188,   7,
   6,   0,  17,   0, 189,   7,   6,   0,  17,   0, 190,   7,   6,   0,  17,   0,
 191,   7,   6,   0,  17,   0, 192,   7,   6,   0,  17,   0, 193,   7,   6,   0,
  17,   0, 194,   7,   6,   0,  17,   0, 195,   7,   6,   0,  17,   0, 196,   7,
   6,   0,  17,   0, 197,   7,   6,   0,  17,   0, 198,   7,   6,   0,  17,   0,
 199,   7,   6,   0,  17,   0, 200,   7,   6,   0,  17,   0, 201,   7,   6,   0,
  17,   0, 202,   7,   6,   0,  17,   0, 203,   7,   6,   0,  17,   0, 204,   7,
   6,   0,  17,   0, 205,   7,   1,  29,  11, 206,   7,   1,  30,  10, 207,   7,
   1,  31,   9, 208,   7,   1,  32,   8, 209,   7,  68,   0,   8,   1,   8, 210,
   7,  68,   0,   9,   1,   9, 211,   7,  68,   0,  10,   1,  10, 212,   7,   1,
  33,   7, 213,   7,   4,   0,  11, 214,   7,   1,  34,   6, 215,   7,   1,  35,
   5, 192,   2,   1,  36,   4, 190,   2,   1,  37,   3, 191,   2,   1,  38,   2,
 205,   2,   1,  39,   1, 147,   3,  39, 166,   9,   4,   1,  12, 167,   9,   4,
   2,  13, 168,   9,   4,   3,  14, 169,   9,   4,   4,  15, 170,   9,  68,   5,
  29,   1,  14, 171,   9,   4,   6,  30, 172,   9,  65,  40, 191,   2,   1,  15,
 173,   9,  65,  41, 190,   2,   1,  16, 174,   9,  65,  42, 189,   2,   1,  17,
 175,   9,  65,  43, 188,   2,   1,  18, 176,   9,  65,  44, 187,   2,   1,  19,
 177,   9,   1,  45, 186,   2, 178,   9,  65,  46, 184,   2,   1,  20, 179,   9,
  65,  47, 183,   2,   1,  21, 180,   9,  65,  48, 182,   2,   1,  22, 181,   9,
   1,  49, 181,   2, 182,   9,  65,  50, 180,   2,   1,  23, 183,   9,  65,  51,
 179,   2,   1,  24, 184,   9,   1,  52, 178,   2, 185,   9,   1,  53, 177,   2,
 186,   9,   1,  54, 176,   2, 187,   9,  65,  55, 175,   2,   1,  25, 188,   9,
  65,  56, 174,   2,   1,  26, 189,   9,  65,  57, 173,   2,   1,  27, 190,   9,
  65,  58, 172,   2,   1,  28, 191,   9,  65,  59, 171,   2,   1,  29, 192,   9,
  68,   7,  16,   1,  30, 193,   9,  68,   8,  17,   1,  31, 194,   9,  68,   9,
  18,   1,  32, 195,   9,  68,  10,  19,   1,  33, 196,   9,   4,  11,  20, 197,
   9,  68,  12,  21,   1,  34, 198,   9,   4,  13,  22, 199,   9,   4,  14,  23,
 200,   9,   4,  15,  24, 201,   9,   4,  16,  25, 202,   9,  68,  17,  26,   1,
  11, 203,   9,  68,  18,  27,   1,  11, 204,   9,  68,  19,  28,   1,  12,   0,
   0, 165,   1,   0,   1,   1,   1,   2,   3, 208,  48,  71,   0,   0,   1,   2,
   2,   1,   2,  12, 208,  48,  93,   1, 102,   1, 209,  70,   2,   1,  41,  71,
   0,   0,   2,   1,   1,   1,   2,  10, 208,  48,  93,   1, 102,   1,  70,   4,
   0,  72,   0,   0,   3,   1,   1,   1,   2,  10, 208,  48,  93,   1, 102,   1,
  70,   6,   0,  72,   0,   0,   4,   2,   2,   1,   2,  12, 208,  48,  93,   1,
 102,   1, 209,  70,   8,   1,  41,  71,   0,   0,   5,   2,   2,   1,   2,  12,
 208,  48,  93,   1, 102,   1, 209,  70,   8,   1,  41,  71,   0,   0,   6,   2,
   2,   1,   2,  13, 208,  48,  93,   9, 102,   9, 102,  10, 209,  70,  11,   1,
  72,   0,   0,   7,   1,   1,   1,   2,  11, 208,  48,  93,  13, 102,  13,  70,
  14,   0,  41,  71,   0,   0,   8,   2,   2,   1,   2,  11, 208,  48,  93,  15,
 102,  15, 209,  70,  16,   1,  72,   0,   0,   9,   2,   2,   1,   2,  11, 208,
  48,  93,  15, 102,  15, 209,  70,  18,   1,  72,   0,   0,  10,   3,   3,   1,
   2,  12, 208,  48,  93,  15, 102,  15, 209, 210,  70,  19,   2,  72,   0,   0,
  11,   3,   3,   1,   2,  12, 208,  48,  93,  15, 102,  15, 209, 210,  70,  22,
   2,  72,   0,   0,  12,   3,   4,   1,   2,  50, 208,  48,  93,  23, 209, 210,
  70,  23,   2, 115, 215, 211,  36,   0, 173, 118,  42, 118,  18,   8,   0,   0,
  41,  93,  24, 102,  24, 102,  25, 118,  18,  14,   0,   0,  93,  24, 102,  24,
  93,  26, 102,  26, 102,  27,  70,  28,   1,  41, 211,  72,   0,   0,  14,   1,
   1,   1,   2,  10, 208,  48,  93,  29, 102,  29,  70,  30,   0,  72,   0,   0,
  15,   2,   2,   1,   2,  11, 208,  48,  93,  29, 102,  29, 209,  70,  31,   1,
  72,   0,   0,  16,   2,   2,   1,   2,  11, 208,  48,  93,  29, 102,  29, 209,
  70,  32,   1,  72,   0,   0,  17,   3,   3,   1,   2,  12, 208,  48,  93,  29,
 102,  29, 209, 210,  70,  33,   2,  72,   0,   0,  18,   2,   2,   1,   2,  11,
 208,  48,  93,  29, 102,  29, 209,  70,  34,   1,  72,   0,   0,  19,   2,   3,
   2,   2, 196,   1,  16,  36,   0,   0,   9,  44,  40,  72,   9,  44,  41,  72,
   9,  44,  42,  72,   9,  44,  43,  72,   9,  44,  44,  72,   9,  44,  45,  72,
   9,  44,  46,  72,   9,  44,  47,  72,  16, 156,   0,   0, 209,  93,  35, 102,
  35, 168, 214,  93,  36, 102,  36, 210,  26,   6,   0,   0,  37,   0,  16, 103,
   0,   0,  93,  37, 102,  37, 210,  26,   6,   0,   0,  37,   1,  16,  88,   0,
   0,  93,  38, 102,  38, 210,  26,   6,   0,   0,  37,   2,  16,  73,   0,   0,
  93,  39, 102,  39, 210,  26,   6,   0,   0,  37,   3,  16,  58,   0,   0,  93,
  40, 102,  40, 210,  26,   6,   0,   0,  37,   4,  16,  43,   0,   0,  93,  41,
 102,  41, 210,  26,   6,   0,   0,  37,   5,  16,  28,   0,   0,  93,  42, 102,
  42, 210,  26,   6,   0,   0,  37,   6,  16,  13,   0,   0,  39,  18,   6,   0,
   0,  37,   7,  16,   2,   0,   0,  37,   7,   8,   2,  27, 121, 255, 255,   7,
  93, 255, 255,  97, 255, 255, 101, 255, 255, 105, 255, 255, 109, 255, 255, 113,
 255, 255, 117, 255, 255, 121, 255, 255,   0,   0,  20,   5,   3,   2,   4, 221,
   2, 208,  48,  87,  42, 214,  48, 101,   1, 209, 109,   1, 101,   1,  93,  43,
  36,  10,  74,  43,   1, 128,  20, 109,   2, 101,   1,  64,  19, 128,  44, 109,
   3, 101,   1, 108,   2,  36,   0, 101,   1, 108,   3, 100, 101,   1, 108,   1,
  65,   1,  97,  45, 101,   1, 108,   2,  36,   1, 101,   1, 108,   1,  93,  46,
 102,  46, 168, 118,  18,   7,   0,   0,  44,  60, 130,  16,   3,   0,   0,  44,
  40, 130,  97,  45, 101,   1, 108,   2,  36,   2, 101,   1, 108,   1,  93,  47,
 102,  47, 168, 118,  18,   7,   0,   0,  44,  62, 130,  16,   3,   0,   0,  44,
  40, 130,  97,  45, 101,   1, 108,   2,  36,   3, 101,   1, 108,   1,  93,  48,
 102,  48, 168, 118,  18,   7,   0,   0,  44,  64, 130,  16,   3,   0,   0,  44,
  40, 130,  97,  45, 101,   1, 108,   2,  36,   4, 101,   1, 108,   1,  93,  49,
 102,  49, 168, 118,  18,   7,   0,   0,  44,  60, 130,  16,   3,   0,   0,  44,
  40, 130,  97,  45, 101,   1, 108,   2,  36,   5, 101,   1, 108,   1,  93,  50,
 102,  50, 168, 118,  18,   7,   0,   0,  44,  62, 130,  16,   3,   0,   0,  44,
  40, 130,  97,  45, 101,   1, 108,   2,  36,   6, 101,   1, 108,   1,  93,  51,
 102,  51, 168, 118,  18,   7,   0,   0,  44,  64, 130,  16,   3,   0,   0,  44,
  40, 130,  97,  45, 101,   1, 108,   2,  36,   7, 101,   1, 108,   1,  93,  52,
 102,  52, 168, 118,  18,   7,   0,   0,  44,  60, 130,  16,   3,   0,   0,  44,
  40, 130,  97,  45, 101,   1, 108,   2,  36,   8, 101,   1, 108,   1,  93,  53,
 102,  53, 168, 118,  18,   7,   0,   0,  44,  62, 130,  16,   3,   0,   0,  44,
  40, 130,  97,  45, 101,   1, 108,   2,  36,   9, 101,   1, 108,   1,  93,  54,
 102,  54, 168, 118,  18,   7,   0,   0,  44,  64, 130,  16,   3,   0,   0,  44,
  40, 130,  97,  45, 101,   1, 108,   2,  44,   1,  70,  55,   1,  72,   0,   3,
  56,   0,   1,  17,   0,  57,   0,   2,  20,   0,  58,   0,   3,  44,   0,  21,
   2,   2,   1,   2,  11, 208,  48,  93,  59, 102,  59, 209,  70,  60,   1,  72,
   0,   0,  22,   2,   2,   1,   2,  11, 208,  48,  93,  59, 102,  59, 209,  70,
  61,   1,  72,   0,   0,  23,   2,   2,   1,   2,  11, 208,  48,  93,  62, 102,
  62, 209,  70,  63,   1,  72,   0,   0,  24,   2,   2,   1,   2,  12, 208,  48,
  93,  62, 102,  62, 209,  70,  64,   1,  41,  71,   0,   0,  25,   2,   2,   1,
   2,  11, 208,  48,  93,  62, 102,  62, 209,  70,  65,   1,  72,   0,   0,  26,
   2,   2,   1,   2,  11, 208,  48,  93,  62, 102,  62, 209,  70,  66,   1,  72,
   0,   0,  27,   1,   1,   1,   2,  10, 208,  48,  93,  62, 102,  62,  70,  67,
   0,  72,   0,   0,  28,   1,   1,   1,   2,  10, 208,  48,  93,  62, 102,  62,
  70,  68,   0,  72,   0,   0,  29,   1,   1,   1,   2,  10, 208,  48,  93,  62,
 102,  62,  70,  69,   0,  72,   0,   0,  30,   1,   1,   1,   2,  10, 208,  48,
  93,  62, 102,  62,  70,  70,   0,  72,   0,   0,  31,   3,   3,   1,   2,  12,
 208,  48,  93,  62, 102,  62, 209, 210,  70,  71,   2,  72,   0,   0,  32,   2,
   2,   1,   2,  11, 208,  48,  93,  62, 102,  62, 209,  70,  72,   1,  72,   0,
   0,  33,   3,   3,   1,   2,  12, 208,  48,  93,  62, 102,  62, 209, 210,  70,
  73,   2,  72,   0,   0,  34,   2,   2,   1,   2,  11, 208,  48,  93,  74, 102,
  74, 209,  70,  75,   1,  72,   0,   0,  35,   2,   2,   1,   2,  11, 208,  48,
  93,  74, 102,  74, 209,  70,  76,   1,  72,   0,   0,  36,   2,   2,   1,   2,
  11, 208,  48,  93,  74, 102,  74, 209,  70,  77,   1,  72,   0,   0,  37,   4,
   5,   1,   2,  29, 208,  48,  36,   0, 115,  99,   4, 211,  18,   5,   0,   0,
  36,   1, 115,  99,   4,  93,  74, 102,  74, 209, 210,  98,   4,  70,  78,   3,
  72,   0,   0,  38,   2,   2,   1,   2,  11, 208,  48,  93,  74, 102,  74, 209,
  70,  79,   1,  72,   0,   0,  39,   2,   2,   1,   2,  25, 208,  48, 209,  36,
 255,  20,   6,   0,   0,  93,  80, 102,  80, 115, 213,  93,  74, 102,  74, 209,
  70,  81,   1,  41,  71,   0,   0,  40,   1,   1,   1,   2,  11, 208,  48,  93,
  74, 102,  74,  70,  82,   0,  41,  71,   0,   0,  41,   1,   1,   3,   4,   3,
 208,  48,  71,   0,   0, 106,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,
  71,   0,   0, 107,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 108,   1,
   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 109,   2,   1,   4,
   5,  21, 208,  48, 208,  93, 149,   1, 102, 149,   1,  70, 150,   1,   0, 104,
 151,   1, 208, 102, 151,   1,  72,   0,   0, 110,   2,   2,   4,   5,  23, 208,
  48, 208, 209, 104, 151,   1,  93, 149,   1, 102, 149,   1, 208, 102, 151,   1,
  70, 152,   1,   1,  41,  71,   0,   0, 111,   1,   1,   4,   5,   7, 208,  48,
 208, 102, 153,   1,  72,   0,   0, 112,   2,   1,   4,   5,  14, 208,  48,  93,
 154,   1, 208, 102, 153,   1,  70, 154,   1,   1,  72,   0,   0, 113,   2,   1,
   4,   5,  15, 208,  48,  93, 160,   1, 102, 160,   1,  44, 176,   1,  97, 161,
   1,  71,   0,   0, 114,   3,   2,   5,   6,  61, 208,  48, 208,  93, 162,   1,
 209,  70, 162,   1,   1, 209,  73,   2,  93, 163,   1, 102, 163,   1, 209, 102,
 164,   1, 118,  18,  18,   0,   0, 208,  93, 163,   1, 102, 163,   1, 209, 102,
 164,   1, 104, 161,   1,  16,  13,   0,   0, 208,  93, 160,   1, 102, 160,   1,
 102, 161,   1, 104, 161,   1,  71,   0,   0, 115,   1,   1,   3,   4,   3, 208,
  48,  71,   0,   0, 125,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,
   0,   0, 126,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 165,   1,   1,
   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 166,   1,   1,   1,
   3,   4,   3, 208,  48,  71,   0,   0, 169,   1,   1,   1,   4,   5,   6, 208,
  48, 208,  73,   0,  71,   0,   0, 170,   1,   1,   1,   3,   4,   3, 208,  48,
  71,   0,   0, 182,   1,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,
   0,   0, 183,   1,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 222,   1,
   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 223,   1,   3,
   1,   3,   4, 223,   3, 208,  48,  94, 142,   2,  86,   0,  97, 142,   2,  94,
 143,   2,  93, 144,   2,  70, 144,   2,   0, 104, 143,   2,  94, 145,   2,  93,
 146,   2,  70, 146,   2,   0, 104, 145,   2,  94, 147,   2,  39,  97, 147,   2,
  93, 148,   2, 102, 148,   2,  37, 148,   5,  44, 240,   1,  97, 149,   2,  93,
 148,   2, 102, 148,   2,  37, 149,   5,  44, 241,   1,  97, 149,   2,  93, 148,
   2, 102, 148,   2,  37, 150,   5,  44, 242,   1,  97, 149,   2,  93, 148,   2,
 102, 148,   2,  37, 151,   5,  44, 243,   1,  97, 149,   2,  93, 148,   2, 102,
 148,   2,  37, 152,   5,  44, 244,   1,  97, 149,   2,  93, 148,   2, 102, 148,
   2,  37, 153,   5,  44, 245,   1,  97, 149,   2,  93, 148,   2, 102, 148,   2,
  37, 154,   5,  44, 246,   1,  97, 149,   2,  93, 148,   2, 102, 148,   2,  37,
 155,   5,  44, 247,   1,  97, 149,   2,  93, 148,   2, 102, 148,   2,  37, 156,
   5,  44, 248,   1,  97, 149,   2,  93, 148,   2, 102, 148,   2,  37, 157,   5,
  44, 249,   1,  97, 149,   2,  93, 148,   2, 102, 148,   2,  37, 158,   5,  44,
 250,   1,  97, 149,   2,  93, 148,   2, 102, 148,   2,  37, 159,   5,  44, 251,
   1,  97, 149,   2,  93, 148,   2, 102, 148,   2,  37, 160,   5,  44, 252,   1,
  97, 149,   2,  93, 148,   2, 102, 148,   2,  37, 161,   5,  44, 253,   1,  97,
 149,   2,  93, 148,   2, 102, 148,   2,  37, 162,   5,  44, 254,   1,  97, 149,
   2,  93, 148,   2, 102, 148,   2,  37, 163,   5,  44, 255,   1,  97, 149,   2,
  93, 148,   2, 102, 148,   2,  37, 164,   5,  44, 128,   2,  97, 149,   2,  93,
 148,   2, 102, 148,   2,  37, 165,   5,  44, 129,   2,  97, 149,   2,  93, 148,
   2, 102, 148,   2,  37, 166,   5,  44, 130,   2,  97, 149,   2,  93, 148,   2,
 102, 148,   2,  37, 167,   5,  44, 131,   2,  97, 149,   2,  93, 148,   2, 102,
 148,   2,  37, 168,   5,  44, 132,   2,  97, 149,   2,  93, 148,   2, 102, 148,
   2,  37, 169,   5,  44, 133,   2,  97, 149,   2,  93, 148,   2, 102, 148,   2,
  37, 170,   5,  44, 134,   2,  97, 149,   2,  93, 148,   2, 102, 148,   2,  37,
 171,   5,  44, 135,   2,  97, 149,   2,  93, 148,   2, 102, 148,   2,  37, 172,
   5,  44, 136,   2,  97, 149,   2,  93, 148,   2, 102, 148,   2,  37, 173,   5,
  44, 137,   2,  97, 149,   2,  93, 148,   2, 102, 148,   2,  37, 174,   5,  44,
 138,   2,  97, 149,   2,  93, 148,   2, 102, 148,   2,  37, 175,   5,  44, 139,
   2,  97, 149,   2,  93, 148,   2, 102, 148,   2,  37, 176,   5,  44, 140,   2,
  97, 149,   2,  71,   0,   0, 226,   1,   2,   2,   3,   4,  20, 208,  48,  44,
   1, 133, 213,  93, 150,   2,  44, 141,   2,  70, 150,   2,   1, 133, 213, 209,
  72,   0,   0, 228,   1,   2,   1,   3,   4,  18, 208,  48,  93, 148,   2, 102,
 148,   2,  93, 151,   2, 102, 151,   2, 102, 149,   2,  72,   0,   0, 229,   1,
   1,   1,   3,   4,  10, 208,  48,  93, 152,   2,  70, 152,   2,   0,  72,   0,
   0, 231,   1,   2,   1,   3,   4,  40, 208,  48,  93, 153,   2, 102, 153,   2,
 118,  18,   7,   0,   0,  93, 153,   2, 102, 153,   2,  72,  94, 153,   2,  93,
 154,   2,  70, 154,   2,   0,  97, 153,   2,  93, 153,   2, 102, 153,   2,  72,
   0,   0, 236,   1,   1,   1,   3,   4,  10, 208,  48,  93, 146,   2,  70, 146,
   2,   0,  72,   0,   0, 237,   1,   2,   2,   3,   4,  12, 208,  48,  93, 156,
   2, 209,  70, 156,   2,   1,  41,  71,   0,   0, 238,   1,   2,   2,   3,   4,
  11, 208,  48,  93, 157,   2, 209,  74, 157,   2,   1,   3,   0,   0, 242,   1,
   2,   2,   3,   4,  11, 208,  48,  93, 158,   2, 209,  70, 158,   2,   1,  72,
   0,   0, 245,   1,   1,   1,   3,   4,   6, 208,  48,  44, 147,   2,  72,   0,
   0, 254,   1,   3,   2,   3,   4,  19, 208,  48,  93, 159,   2, 102, 159,   2,
 209,  44, 148,   2, 160,  70, 160,   2,   1,  41,  71,   0,   0, 139,   2,   1,
   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 140,   2,   1,   1,
   3,   4,   3, 208,  48,  71,   0,   0, 144,   2,   2,   2,   4,   5,  13, 208,
  48, 208,  73,   0, 208, 209,  70, 209,   2,   1,  41,  71,   0,   0, 147,   2,
   3,   3,   4,   5,  20, 208,  48, 208,  93, 211,   2, 102, 211,   2, 209,  70,
 212,   2,   1, 210,  70, 213,   2,   2,  72,   0,   0, 150,   2,   1,   1,   3,
   4,   3, 208,  48,  71,   0,   0, 156,   2,   1,   1,   4,   5,   6, 208,  48,
 208,  73,   0,  71,   0,   0, 157,   2,   1,   1,   4,   5,   3, 208,  48,  71,
   0,   0, 158,   2,   2,   1,   5,   6,  23, 208,  48, 208,  73,   0,  93, 226,
   2,  44, 195,   2,  70, 226,   2,   1,  41, 208,  70, 227,   2,   0,  41,  71,
   0,   0, 159,   2,   3,   7,   5,   6, 117, 208,  48,  36,   0, 116, 213,  32,
 133, 215,  36,   0,  99,   4,  32, 133,  99,   5,  32, 133,  99,   6, 208, 102,
 228,   2, 102, 229,   2, 116, 214,  36,   0, 116, 213,  16,  72,   0,   0,   9,
 208, 102, 228,   2, 209, 102, 230,   2, 133, 215, 211,  44, 199,   2,  70, 231,
   2,   1, 115,  99,   4, 211,  36,   0,  98,   4,  70, 232,   2,   2, 133,  99,
   5, 211,  98,   4,  36,   1, 160,  70, 233,   2,   1, 133,  99,   6, 208, 102,
 234,   2,  98,   5,  98,   6,  97, 230,   2, 208, 102, 235,   2, 209,  98,   5,
  97, 230,   2, 209, 145, 116, 213, 209, 210,  21, 178, 255, 255,  71,   0,   0,
 160,   2,   4,   3,   5,   6,  33, 208,  48,  93, 226,   2,  44, 205,   2, 209,
 160,  44, 206,   2, 160, 210,  44, 207,   2,  70, 236,   2,   1, 160,  44, 208,
   2, 160,  70, 226,   2,   1,  41,  71,   0,   0, 161,   2,   2,   2,   5,   6,
  11, 208,  48, 208, 102, 234,   2, 209, 106, 230,   2,  72,   0,   0, 162,   2,
   2,   2,   5,   6,  11, 208,  48, 208, 102, 234,   2, 209, 102, 230,   2,  72,
   0,   0, 163,   2,   3,   3,   5,   6,  25, 208,  48,  93, 237,   2, 209,  70,
 237,   2,   1, 118,  18,   9,   0,   0, 208, 102, 234,   2, 209, 210,  97, 230,
   2,  71,   0,   0, 164,   2,   2,   2,   5,   6,   9, 208,  48, 209, 208, 102,
 234,   2, 180,  72,   0,   0, 165,   2,   3,   2,   5,   6,  25, 208,  48, 209,
 208, 102, 235,   2, 102, 229,   2,  36,   1, 161,  14,   3,   0,   0,  36,   0,
  72, 209,  36,   1, 160,  72,   0,   0, 166,   2,   4,   2,   5,   6,  21, 208,
  48,  93, 238,   2, 208, 102, 235,   2, 209,  36,   1, 161, 102, 230,   2,  70,
 238,   2,   1,  72,   0,   0, 167,   2,   5,   2,   5,   6,  28, 208,  48,  93,
 238,   2, 208, 102, 234,   2, 208, 102, 235,   2, 209,  36,   1, 161, 102, 230,
   2, 102, 230,   2,  70, 238,   2,   1,  72,   0,   0, 168,   2,   1,   1,   5,
   6,  10, 208,  48, 208, 102, 235,   2, 102, 229,   2,  72,   0,   0, 169,   2,
   2,   1,   5,   6,  63, 208,  48, 208,  93, 239,   2, 102, 239,   2,  70, 240,
   2,   0, 104, 228,   2, 208, 102, 235,   2, 118,  18,   9,   0,   0, 208, 102,
 235,   2,  36,   0,  97, 229,   2, 208,  93, 241,   2,  74, 241,   2,   0, 104,
 235,   2, 208,  93, 242,   2,  74, 242,   2,   0, 104, 234,   2, 208,  70, 243,
   2,   0,  41,  71,   0,   0, 170,   2,   4,   3,   1,   4, 247,  18, 208,  48,
  93, 132,   3,  93, 148,   1, 102, 148,   1,  48,  93, 133,   3, 102, 133,   3,
  88,   0,  29, 104, 147,   1,  93, 134,   3,  93, 148,   1, 102, 148,   1,  48,
  93, 133,   3, 102, 133,   3,  88,   1,  29, 104, 159,   1,  93, 135,   3,  93,
 148,   1, 102, 148,   1,  48,  93, 166,   1, 102, 166,   1,  48,  93, 136,   3,
 102, 136,   3,  88,   2,  29,  29, 104, 165,   1,  93, 137,   3,  93, 148,   1,
 102, 148,   1,  48,  93, 138,   3, 102, 138,   3,  88,   3,  29, 104, 176,   1,
  93, 139,   3,  93, 148,   1, 102, 148,   1,  48,  93, 140,   3, 102, 140,   3,
  88,   4,  29, 104, 215,   1,  93, 141,   3,  93, 148,   1, 102, 148,   1,  48,
  93, 142,   3, 102, 142,   3,  88,   5,  29, 104, 218,   1,  93, 143,   3,  93,
 148,   1, 102, 148,   1,  48,  93, 144,   3, 102, 144,   3,  88,   6,  29, 104,
 230,   1,  93, 145,   3,  93, 148,   1, 102, 148,   1,  48,  93, 146,   3, 102,
 146,   3,  88,   7,  29, 104, 141,   2,  93, 147,   3,  93, 148,   1, 102, 148,
   1,  48,  93, 148,   3, 102, 148,   3,  88,   8,  29, 104, 207,   2,  93, 149,
   3,  93, 148,   1, 102, 148,   1,  48,  93, 150,   3, 102, 150,   3,  88,   9,
  29, 104, 208,   2,  93, 151,   3,  93, 148,   1, 102, 148,   1,  48,  93, 150,
   3, 102, 150,   3,  88,  10,  29, 104, 225,   2,  93, 152,   3,  93, 148,   1,
 102, 148,   1,  48,  93, 131,   3, 102, 131,   3,  48,  93, 153,   3, 102, 153,
   3,  88,  11,  29,  29, 104, 130,   3,  93, 154,   3,  93, 155,   3, 102, 155,
   3, 102, 156,   3, 104, 157,   3,  93, 158,   3,  93, 155,   3, 102, 155,   3,
 102, 159,   3, 104, 160,   3,  93, 161,   3,  93, 155,   3, 102, 155,   3, 102,
 162,   3, 104, 163,   3,  93, 164,   3,  93, 155,   3, 102, 155,   3, 102, 165,
   3, 104, 166,   3,  93, 167,   3,  93, 155,   3, 102, 155,   3, 102, 168,   3,
 104, 169,   3,  93, 170,   3,  93, 155,   3, 102, 155,   3, 102, 171,   3, 104,
 172,   3,  93, 173,   3,  93, 155,   3, 102, 155,   3, 102, 174,   3, 104, 175,
   3,  93, 176,   3,  93, 155,   3, 102, 155,   3, 102, 177,   3, 104, 178,   3,
  93, 179,   3,  93, 155,   3, 102, 155,   3, 102, 180,   3, 104, 181,   3,  93,
 182,   3,  93, 155,   3, 102, 155,   3, 102, 183,   3, 104, 184,   3,  93, 185,
   3,  93, 155,   3, 102, 155,   3, 102, 186,   3, 104, 187,   3,  93, 188,   3,
  93, 155,   3, 102, 155,   3, 102, 189,   3, 104, 190,   3,  93, 191,   3,  93,
 155,   3, 102, 155,   3, 102, 192,   3, 104, 193,   3,  93, 194,   3,  93, 155,
   3, 102, 155,   3, 102, 195,   3, 104, 196,   3,  93, 197,   3,  93, 155,   3,
 102, 155,   3, 102, 198,   3, 104, 199,   3,  93, 200,   3,  93, 155,   3, 102,
 155,   3, 102, 201,   3, 104, 202,   3,  93, 203,   3,  93, 155,   3, 102, 155,
   3, 102, 204,   3, 104, 205,   3,  93, 206,   3,  93, 155,   3, 102, 155,   3,
 102, 207,   3, 104, 208,   3,  93, 209,   3,  93, 155,   3, 102, 155,   3, 102,
 210,   3, 104, 211,   3,  93, 212,   3,  93, 155,   3, 102, 155,   3, 102, 213,
   3, 104, 214,   3,  93, 215,   3,  93, 155,   3, 102, 155,   3, 102, 216,   3,
 104, 217,   3,  93, 218,   3,  93, 155,   3, 102, 155,   3, 102, 219,   3, 104,
 220,   3,  93, 221,   3,  93, 155,   3, 102, 155,   3, 102, 222,   3, 104, 223,
   3,  93, 224,   3,  93, 155,   3, 102, 155,   3, 102, 225,   3, 104, 226,   3,
  93, 227,   3,  93, 155,   3, 102, 155,   3, 102, 228,   3, 104, 229,   3,  93,
 230,   3,  93, 155,   3, 102, 155,   3, 102, 231,   3, 104, 232,   3,  93, 233,
   3,  93, 155,   3, 102, 155,   3, 102, 234,   3, 104, 235,   3,  93, 236,   3,
  93, 155,   3, 102, 155,   3, 102, 237,   3, 104, 238,   3,  93, 239,   3,  93,
 155,   3, 102, 155,   3, 102, 240,   3, 104, 241,   3,  93, 242,   3,  93, 155,
   3, 102, 155,   3, 102, 243,   3, 104, 244,   3,  93, 245,   3,  93, 155,   3,
 102, 155,   3, 102, 246,   3, 104, 247,   3,  93, 248,   3,  93, 155,   3, 102,
 155,   3, 102, 249,   3, 104, 250,   3,  93, 251,   3,  93, 155,   3, 102, 155,
   3, 102, 252,   3, 104, 253,   3,  93, 254,   3,  93, 155,   3, 102, 155,   3,
 102, 255,   3, 104, 128,   4,  93, 129,   4,  93, 155,   3, 102, 155,   3, 102,
 130,   4, 104, 131,   4,  93, 132,   4,  93, 155,   3, 102, 155,   3, 102, 133,
   4, 104, 134,   4,  93, 135,   4,  93, 155,   3, 102, 155,   3, 102, 136,   4,
 104, 137,   4,  93, 138,   4,  93, 155,   3, 102, 155,   3, 102, 139,   4, 104,
 140,   4,  93, 141,   4,  93, 155,   3, 102, 155,   3, 102, 142,   4, 104, 143,
   4,  93, 144,   4,  93, 155,   3, 102, 155,   3, 102, 145,   4, 104, 146,   4,
  93, 147,   4,  93, 155,   3, 102, 155,   3, 102, 148,   4, 104, 149,   4,  93,
 150,   4,  93, 155,   3, 102, 155,   3, 102, 151,   4, 104, 152,   4,  93, 153,
   4,  93, 155,   3, 102, 155,   3, 102, 154,   4, 104, 155,   4,  93, 156,   4,
  93, 155,   3, 102, 155,   3, 102, 157,   4, 104, 158,   4,  93, 159,   4,  93,
 155,   3, 102, 155,   3, 102, 160,   4, 104, 161,   4,  93, 162,   4,  93, 155,
   3, 102, 155,   3, 102, 163,   4, 104, 164,   4,  93, 165,   4,  93, 155,   3,
 102, 155,   3, 102, 166,   4, 104, 167,   4,  93, 168,   4,  93, 155,   3, 102,
 155,   3, 102, 169,   4, 104, 170,   4,  93, 171,   4,  93, 155,   3, 102, 155,
   3, 102, 172,   4, 104, 173,   4,  93, 174,   4,  93, 155,   3, 102, 155,   3,
 102, 175,   4, 104, 176,   4,  93, 177,   4,  93, 155,   3, 102, 155,   3, 102,
 178,   4, 104, 179,   4,  93, 180,   4,  93, 155,   3, 102, 155,   3, 102, 181,
   4, 104, 182,   4,  93, 183,   4,  93, 155,   3, 102, 155,   3, 102, 184,   4,
 104, 185,   4,  93, 186,   4,  93, 155,   3, 102, 155,   3, 102, 187,   4, 104,
 188,   4,  93, 189,   4,  93, 155,   3, 102, 155,   3, 102, 190,   4, 104, 191,
   4,  93, 192,   4,  93, 155,   3, 102, 155,   3, 102, 193,   4, 104, 194,   4,
  93, 195,   4,  93, 155,   3, 102, 155,   3, 102, 196,   4, 104, 197,   4,  93,
 198,   4,  93, 155,   3, 102, 155,   3, 102, 199,   4, 104, 200,   4,  93, 201,
   4,  93, 155,   3, 102, 155,   3, 102, 202,   4, 104, 203,   4,  93, 204,   4,
  93, 155,   3, 102, 155,   3, 102, 205,   4, 104, 206,   4,  93, 207,   4,  93,
 155,   3, 102, 155,   3, 102, 208,   4, 104, 209,   4,  93, 210,   4,  93, 155,
   3, 102, 155,   3, 102, 211,   4, 104, 212,   4,  93, 213,   4,  93, 214,   4,
  74, 214,   4,   0, 104, 215,   4,  93, 216,   4, 102, 216,   4,  36,   0,  97,
 217,   4,  93, 218,   4,  85,   0, 104, 219,   4,  93, 220,   4, 102, 220,   4,
  93, 156,   3, 102, 156,   3,  44, 102,  97, 221,   4,  93, 220,   4, 102, 220,
   4,  93, 159,   3, 102, 159,   3,  44, 103,  97, 221,   4,  93, 220,   4, 102,
 220,   4,  93, 162,   3, 102, 162,   3,  44, 104,  97, 221,   4,  93, 220,   4,
 102, 220,   4,  93, 165,   3, 102, 165,   3,  44, 105,  97, 221,   4,  93, 220,
   4, 102, 220,   4,  93, 168,   3, 102, 168,   3,  44, 106,  97, 221,   4,  93,
 220,   4, 102, 220,   4,  93, 171,   3, 102, 171,   3,  44, 107,  97, 221,   4,
  93, 220,   4, 102, 220,   4,  93, 174,   3, 102, 174,   3,  44, 108,  97, 221,
   4,  93, 220,   4, 102, 220,   4,  93, 177,   3, 102, 177,   3,  44, 109,  97,
 221,   4,  93, 220,   4, 102, 220,   4,  93, 180,   3, 102, 180,   3,  44, 110,
  97, 221,   4,  93, 220,   4, 102, 220,   4,  93, 183,   3, 102, 183,   3,  44,
 111,  97, 221,   4,  93, 220,   4, 102, 220,   4,  93, 186,   3, 102, 186,   3,
  44, 112,  97, 221,   4,  93, 220,   4, 102, 220,   4,  93, 192,   3, 102, 192,
   3,  44, 114,  97, 221,   4,  93, 220,   4, 102, 220,   4,  93, 195,   3, 102,
 195,   3,  44, 115,  97, 221,   4,  93, 220,   4, 102, 220,   4,  93, 198,   3,
 102, 198,   3,  44, 116,  97, 221,   4,  93, 220,   4, 102, 220,   4,  93, 201,
   3, 102, 201,   3,  44, 117,  97, 221,   4,  93, 220,   4, 102, 220,   4,  93,
 204,   3, 102, 204,   3,  44, 118,  42, 214,  97, 221,   4, 210,   8,   2, 130,
 213,  93, 222,   4,  93,  74, 102,  74, 102,  80, 104, 223,   4,  93, 224,   4,
  93,  74, 102,  74, 102, 225,   4, 104, 226,   4,  93, 227,   4,  93,  62, 102,
  62, 102, 228,   4, 104, 229,   4,  93, 230,   4,  93,  62, 102,  62, 102, 231,
   4, 104, 232,   4,  93, 233,   4,  93,  62, 102,  62, 102, 234,   4, 104, 235,
   4,  93, 236,   4,  93,  62, 102,  62, 102, 237,   4, 104, 238,   4,  93, 239,
   4,  93,  62, 102,  62, 102, 240,   4, 104, 241,   4,  93, 242,   4,  93,  62,
 102,  62, 102, 243,   4, 104, 244,   4,  93, 245,   4,  93,  62, 102,  62, 102,
 246,   4, 104, 247,   4,  93, 248,   4,  93,  62, 102,  62, 102, 249,   4, 104,
 250,   4,  93, 251,   4,  93,  62, 102,  62, 102, 252,   4, 104, 253,   4,  93,
 254,   4,  93,  62, 102,  62, 102, 255,   4, 104, 128,   5,  93, 129,   5,  93,
  62, 102,  62, 102, 130,   5, 104, 131,   5,  93, 132,   5,  93,  62, 102,  62,
 102, 133,   5, 104, 134,   5,  93, 135,   5,  93,  62, 102,  62, 102, 136,   5,
 104, 137,   5,  93, 138,   5,  93,  62, 102,  62, 102, 139,   5, 104, 140,   5,
  93, 141,   5,  93,  62, 102,  62, 102, 142,   5, 104, 143,   5,  93, 144,   5,
  93,  62, 102,  62, 102, 145,   5, 104, 146,   5,  93, 147,   5,  93,  62, 102,
  62, 102, 148,   5, 104, 149,   5,  93, 150,   5,  93,  62, 102,  62, 102, 151,
   5, 104, 152,   5,  93, 153,   5,  93,  62, 102,  62, 102, 154,   5, 104, 155,
   5,  93, 156,   5,  93,  62, 102,  62, 102, 157,   5, 104, 158,   5,  93, 159,
   5,  93,  62, 102,  62, 102, 160,   5, 104, 161,   5,  93, 162,   5,  93,  62,
 102,  62, 102, 163,   5, 104, 164,   5,  93, 165,   5,  93,  62, 102,  62, 102,
 166,   5, 104, 167,   5,  93, 168,   5,  93,  62, 102,  62, 102, 169,   5, 104,
 170,   5,  93, 171,   5,  93,  62, 102,  62, 102, 172,   5, 104, 173,   5,  93,
 174,   5,  93,  62, 102,  62, 102, 175,   5, 104, 176,   5,  93, 177,   5,  93,
  62, 102,  62, 102, 237,   4, 104, 178,   5,  93, 179,   5,  93,  29, 102,  29,
 102, 180,   5, 104, 181,   5,  93, 182,   5,  93,  29, 102,  29, 102, 183,   5,
 104, 184,   5,  93, 185,   5,  93,  29, 102,  29, 102, 186,   5, 104, 187,   5,
  93, 188,   5,  93,  29, 102,  29, 102, 189,   5, 104, 190,   5,  93, 191,   5,
  93,  29, 102,  29, 102, 192,   5, 104, 193,   5,  93, 194,   5,  93,  29, 102,
  29, 102, 195,   5, 104, 196,   5,  93, 197,   5,  93,  15, 102,  15, 102, 198,
   5, 104, 199,   5,  93, 200,   5,  93,  15, 102,  15, 102, 201,   5, 104, 202,
   5,  93, 203,   5,  93,  15, 102,  15, 102, 204,   5, 104, 205,   5,  93, 206,
   5,  93,  15, 102,  15, 102, 207,   5, 104, 208,   5,  93, 209,   5,  93,  15,
 102,  15, 102, 210,   5, 104, 211,   5,  93, 212,   5,  93,  15, 102,  15, 102,
 213,   5, 104, 214,   5,  93, 215,   5,  93,  15, 102,  15, 102, 216,   5, 104,
 217,   5,  93, 218,   5,  93,  15, 102,  15, 102, 219,   5, 104, 220,   5,  93,
 221,   5,  93,  15, 102,  15, 102, 222,   5, 104, 223,   5,  93, 224,   5,  93,
  15, 102,  15, 102, 225,   5, 104, 226,   5,  93, 227,   5,  93,  15, 102,  15,
 102, 228,   5, 104, 229,   5,  93, 230,   5,  93,  15, 102,  15, 102, 231,   5,
 104, 232,   5,  93, 233,   5,  93,  15, 102,  15, 102, 234,   5, 104, 235,   5,
  93, 236,   5,  93,  15, 102,  15, 102, 237,   5, 104, 238,   5,  93, 239,   5,
  93,  15, 102,  15, 102, 240,   5, 104, 241,   5,  93, 242,   5,  93,  15, 102,
  15, 102, 243,   5, 104, 244,   5,  93, 245,   5,  93,  15, 102,  15, 102, 246,
   5, 104, 247,   5,  93, 248,   5,  93,  15, 102,  15, 102, 249,   5, 104, 250,
   5,  93, 251,   5,  93,  15, 102,  15, 102, 252,   5, 104, 253,   5,  93, 254,
   5,  93,  15, 102,  15, 102, 255,   5, 104, 128,   6,  93, 129,   6,  93,  15,
 102,  15, 102, 130,   6, 104, 131,   6,  93, 132,   6,  93,  15, 102,  15, 102,
 133,   6, 104, 134,   6,  93, 135,   6,  93,  15, 102,  15, 102, 136,   6, 104,
 137,   6,  93, 138,   6,  93,  15, 102,  15, 102, 139,   6, 104, 140,   6,  93,
 141,   6,  93,  15, 102,  15, 102, 142,   6, 104, 143,   6,  93, 144,   6,  93,
  15, 102,  15, 102, 145,   6, 104, 146,   6,  93, 147,   6,  93,  15, 102,  15,
 102, 148,   6, 104, 149,   6,  93, 150,   6,  93,  15, 102,  15, 102, 151,   6,
 104, 152,   6,  93, 153,   6,  93,  15, 102,  15, 102, 154,   6, 104, 155,   6,
  93, 156,   6,  93,  15, 102,  15, 102, 157,   6, 104, 158,   6,  93, 159,   6,
  93,  15, 102,  15, 102, 160,   6, 104, 161,   6,  93, 162,   6,  93,  15, 102,
  15, 102, 163,   6, 104, 164,   6,  93, 165,   6,  93,  15, 102,  15, 102, 166,
   6, 104, 167,   6,  93, 168,   6,  93,  15, 102,  15, 102, 169,   6, 104, 170,
   6, 209,  72,   8,   1,   0,   0, 176,   2,   4,   3,   1,   2,  14, 208,  48,
  93, 217,   7, 209, 210,  36,   1,  70, 217,   7,   3,  72,   0,   0, 177,   2,
   4,   3,   1,   2,  14, 208,  48,  93, 217,   7, 209, 210,  36,   2,  70, 217,
   7,   3,  72,   0,   0, 178,   2,   4,   3,   1,   2,  14, 208,  48,  93, 217,
   7, 209, 210,  36,   0,  70, 217,   7,   3,  72,   0,   0, 181,   2,   2,   1,
   1,   2,  13, 208,  48,  93, 218,   7, 100, 108,   7,  70, 218,   7,   1,  72,
   0,   0, 185,   2,   3,   3,   3,   6,  47,  87,  42, 213,  48, 101,   0,  38,
 118, 109,   1,  93, 219,   7,  76, 219,   7,   0,  41,  16,  20,   0,   0, 209,
  48,  90,   0,  42, 214,  42,  48,  43, 109,   1, 101,   0,  39, 118, 109,   1,
  29,   8,   2, 101,   0, 108,   1,  72,   1,  10,  18,  22,   0, 220,   7,   1,
 221,   7,   0,   1,  21,   0, 186,   2,   2,   3,   2,   4,  60, 208,  48,  87,
  42, 214,  48, 101,   1,  33, 130, 109,   2, 101,   1, 209, 109,   1, 101,   1,
 108,   1,  32,  19,  24,   0,   0, 101,   1,  64, 185,   2, 130, 109,   2,  93,
 222,   7, 101,   1, 108,   2,  70, 222,   7,   1,  41,  16,   9,   0,   0,  93,
 222,   7,  32,  70, 222,   7,   1,  41,  71,   0,   2, 223,   7,   0,   1,  44,
   0, 224,   7,   0,   2,   0,   0, 192,   2,   2,   1,   3,   4,  21, 208,  48,
  94, 225,   7,  44, 145,   3, 104, 225,   7,  94, 226,   7,  44, 147,   3, 104,
 226,   7,  71,   0,   0, 193,   2,   1,   1,   4,   5,   6, 208,  48, 208,  73,
   0,  71,   0,   0, 194,   2,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,
 195,   2,   1,   1,   3,   4,   6, 208,  48,  44, 150,   3,  72,   0,   0, 196,
   2,   1,   1,   3,   4,  13, 208,  48,  93, 230,   7, 102, 230,   7,  70, 231,
   7,   0,  72,   0,   0, 197,   2,   1,   1,   4,   5,   6, 208,  48, 208,  73,
   0,  71,   0,   0, 198,   2,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,
 199,   2,   3,   1,   4,   5,  50, 208,  48, 208, 102, 234,   7,  44, 157,   3,
 160, 208, 102, 235,   7, 118,  18,  26,   0,   0,  44, 159,   3, 208, 102, 235,
   7, 160,  44, 160,   3, 160, 208, 102, 236,   7, 160,  44, 162,   3, 160, 130,
  16,   3,   0,   0,  44,   1, 130, 160,  72,   0,   0, 200,   2,   1,   1,   4,
   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 201,   2,   1,   1,   3,   4,
   3, 208,  48,  71,   0,   0, 202,   2,   1,   1,   4,   5,   6, 208,  48, 208,
  73,   0,  71,   0,   0, 203,   2,   2,   1,   3,   4,  39, 208,  48,  94, 245,
   7, 100, 108,   3, 104, 245,   7,  94, 246,   7, 100, 108,   4, 104, 246,   7,
  94, 247,   7, 100, 108,   6, 104, 247,   7,  94, 248,   7, 100, 108,   5, 104,
 248,   7,  71,   0,   0, 204,   2,   1,   1,   4,   5,   6, 208,  48, 208,  73,
   0,  71,   0,   0, 205,   2,   2,   1,   3,   4,  59, 208,  48,  94, 254,   7,
  36,   0, 104, 254,   7,  94, 255,   7,  36,   1, 104, 255,   7,  94, 128,   8,
  36,   2, 104, 128,   8,  94, 129,   8,  36,   3, 104, 129,   8,  94, 130,   8,
  36,   4, 104, 130,   8,  94, 131,   8,  36,   1, 104, 131,   8,  94, 132,   8,
  36,   2, 104, 132,   8,  71,   0,   0, 210,   2,   1,   1,   4,   5,   6, 208,
  48, 208,  73,   0,  71,   0,   0, 211,   2,   2,   1,   3,   4,  57, 208,  48,
  94, 145,   8,  44, 191,   3, 104, 145,   8,  94, 146,   8,  44, 193,   3, 104,
 146,   8,  94, 147,   8,  44, 195,   3, 104, 147,   8,  94, 148,   8,  44, 197,
   3, 104, 148,   8,  94, 149,   8,  44, 199,   3, 104, 149,   8,  94, 150,   8,
  44, 201,   3, 104, 150,   8,  71,   0,   0, 212,   2,   3,   2,   3,   4,  99,
 208,  48, 209,  93, 151,   8, 102, 151,   8,  20,   3,   0,   0,  36,   1,  72,
 209,  93, 152,   8, 102, 152,   8,  20,   3,   0,   0,  36,   2,  72, 209,  93,
 153,   8, 102, 153,   8,  20,   3,   0,   0,  36,   3,  72, 209,  93, 154,   8,
 102, 154,   8,  20,   3,   0,   0,  36,   4,  72, 209,  93, 155,   8, 102, 155,
   8,  20,   3,   0,   0,  36,   5,  72, 209,  93, 156,   8, 102, 156,   8,  20,
   3,   0,   0,  36,   6,  72,  93, 157,   8,  44, 202,   3, 209, 160,  70, 157,
   8,   1,   3,   0,   0, 213,   2,   1,   1,   4,   5,   6, 208,  48, 208,  73,
   0,  71,   0,   0, 214,   2,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0,
 215,   2,   1,   1,   3,   4,   9, 208,  48,  93, 166,   8, 102, 166,   8,  72,
   0,   0, 217,   2,   1,   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,
   0, 225,   2,   2,   1,   3,   4,  12, 208,  48,  94, 179,   8,  44, 220,   3,
 104, 179,   8,  71,   0,   0, 226,   2,   2,   3,   4,   5,  16, 208,  48, 208,
  73,   0, 208, 209, 104, 180,   8, 208, 210, 104, 181,   8,  71,   0,   0, 227,
   2,   1,   1,   4,   5,   7, 208,  48, 208, 102, 181,   8,  72,   0,   0, 228,
   2,   1,   1,   4,   5,   7, 208,  48, 208, 102, 180,   8,  72,   0,   0, 229,
   2,   1,   1,   4,   5,   7, 208,  48, 208, 102, 182,   8,  72,   0,   0, 230,
   2,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 231,   2,   1,   1,   3,
   4,   9, 208,  48,  93, 191,   8, 102, 191,   8,  72,   0,   0, 232,   2,   1,
   1,   4,   5,   6, 208,  48, 208,  73,   0,  71,   0,   0, 233,   2,   2,   2,
   4,   5,   9, 208,  48, 208, 209,  70, 193,   8,   1,  72,   0,   0, 234,   2,
   2,   1,   4,   5,   9, 208,  48, 208,  32,  70, 193,   8,   1,  72,   0,   0,
 237,   2,   1,   1,   3,   4,   3, 208,  48,  71,   0,   0, 238,   2,   1,   2,
   3,   4,   3, 208,  48,  71,   0,   0, 239,   2,   2,   1,   3,   4,  16, 208,
  48,  93, 201,   8, 102, 201,   8,  93, 202,   8, 102, 202,   8, 135,  72,   0,
   0, 240,   2,   1,   1,   3,   4,  12, 208,  48,  93, 203,   8, 102, 203,   8,
 102, 204,   8,  72,   0,   0, 241,   2,   1,   1,   3,   4,  12, 208,  48,  93,
 203,   8, 102, 203,   8, 102, 205,   8,  72,   0,   0, 242,   2,   1,   1,   3,
   4,  12, 208,  48,  93, 203,   8, 102, 203,   8, 102, 206,   8,  72,   0,   0,
 243,   2,   1,   1,   3,   4,   9, 208,  48,  93, 207,   8, 102, 207,   8,  72,
   0,   0, 244,   2,   2,   2,   3,   4,  10, 208,  48,  94, 207,   8, 209,  97,
 207,   8,  71,   0,   0, 245,   2,   1,   1,   3,   4,  13, 208,  48,  93, 203,
   8, 102, 203,   8,  70, 208,   8,   0,  72,   0,   0, 246,   2,   1,   1,   3,
   4,   3, 208,  48,  71,   0,   0, 247,   2,   1,   1,   3,   4,   3, 208,  48,
  71,   0,   0, 248,   2,   2,   2,   3,   4,  15, 208,  48,  93, 203,   8, 102,
 203,   8, 209,  70, 209,   8,   1,  41,  71,   0,   0, 249,   2,   1,   1,   3,
   4,  14, 208,  48,  93, 203,   8, 102, 203,   8,  70, 210,   8,   0,  41,  71,
   0,   0, 250,   2,   2,   2,   3,   4,  15, 208,  48,  93, 203,   8, 102, 203,
   8, 209,  70, 211,   8,   1,  41,  71,   0,   0, 251,   2,   1,   1,   4,   5,
   6, 208,  48, 208,  73,   0,  71,   0,   0, 252,   2,   2,   1,   4,   5,  15,
 208,  48,  93, 221,   8, 102, 221,   8,  44, 246,   3,  97, 222,   8,  71,   0,
   0, 253,   2,   2,   2,   5,   6,  20, 208,  48, 208, 209,  73,   1, 208,  93,
 221,   8, 102, 221,   8, 102, 222,   8, 104, 222,   8,  71,   0,   0, 254,   2,
   2,   1,   4,   5,  15, 208,  48,  93, 224,   8, 102, 224,   8,  44, 248,   3,
  97, 225,   8,  71,   0,   0, 255,   2,   2,   2,   5,   6,  20, 208,  48, 208,
 209,  73,   1, 208,  93, 224,   8, 102, 224,   8, 102, 225,   8, 104, 225,   8,
  71,   0,   0, 128,   3,   2,   1,   4,   5,  15, 208,  48,  93, 227,   8, 102,
 227,   8,  44, 250,   3,  97, 228,   8,  71,   0,   0, 129,   3,   3,   3,   5,
   6,  21, 208,  48, 208, 209, 210,  73,   2, 208,  93, 227,   8, 102, 227,   8,
 102, 228,   8, 104, 228,   8,  71,   0,   0, 130,   3,   2,   1,   3,   4, 147,
   1, 208,  48,  94, 230,   8,  44, 253,   3, 104, 230,   8,  94, 231,   8,  44,
 255,   3, 104, 231,   8,  94, 232,   8,  44, 129,   4, 104, 232,   8,  94, 233,
   8,  44, 131,   4, 104, 233,   8,  94, 234,   8,  44, 133,   4, 104, 234,   8,
  94, 235,   8,  44, 135,   4, 104, 235,   8,  94, 236,   8,  44, 137,   4, 104,
 236,   8,  94, 237,   8,  44, 139,   4, 104, 237,   8,  94, 238,   8,  44, 141,
   4, 104, 238,   8,  94, 239,   8,  44, 143,   4, 104, 239,   8,  94, 240,   8,
  44, 145,   4, 104, 240,   8,  94, 241,   8,  44, 147,   4, 104, 241,   8,  94,
 242,   8,  44, 149,   4, 104, 242,   8,  94, 243,   8,  44, 151,   4, 104, 243,
   8,  94, 244,   8,  44, 153,   4, 104, 244,   8,  94, 245,   8,  44, 155,   4,
 104, 245,   8,  71,   0,   0, 131,   3,   1,   1,   4,   5,   6, 208,  48, 208,
  73,   0,  71,   0,   0, 132,   3,   1,   1,   4,   5,   3, 208,  48,  71,   0,
   0, 133,   3,   3,   7,   5,   6,  51, 208,  48, 208, 211,  98,   4,  73,   2,
 208,  44, 165,   4, 104, 135,   9,  98,   6, 150,  18,   6,   0,   0,  86,   0,
 128,  20,  99,   6, 208, 209, 104, 136,   9, 208, 210, 104, 137,   9, 208,  98,
   5, 104, 138,   9, 208,  98,   6, 104, 139,   9,  71,   0,   0, 134,   3,   1,
   1,   5,   6,   7, 208,  48, 208, 102, 136,   9,  72,   0,   0, 135,   3,   1,
   1,   5,   6,   7, 208,  48, 208, 102, 137,   9,  72,   0,   0, 136,   3,   1,
   1,   5,   6,   7, 208,  48, 208, 102, 138,   9,  72,   0,   0, 137,   3,   1,
   1,   5,   6,   7, 208,  48, 208, 102, 139,   9,  72,   0,   0, 138,   3,   1,
   1,   4,   5,   3, 208,  48,  71,   0,   0, 139,   3,   3,   4,   5,   6,  20,
 208,  48, 208, 209, 210,  73,   2, 208,  44, 175,   4, 104, 149,   9, 208, 211,
 104, 150,   9,  71,   0,   0, 140,   3,   1,   1,   5,   6,   7, 208,  48, 208,
 102, 150,   9,  72,   0,   0, 141,   3,   1,   1,   4,   5,   3, 208,  48,  71,
   0,   0, 144,   3,   1,   1,   5,   6,   6, 208,  48, 208,  73,   0,  71,   0,
   0, 145,   3,   1,   1,   4,   5,   3, 208,  48,  71,   0,   0, 146,   3,   1,
   1,   5,   6,   6, 208,  48, 208,  73,   0,  71,   0,   0, 147,   3,   2,   1,
   1,   4, 196,   3, 208,  48, 101,   0,  93, 148,   1, 102, 148,   1,  48,  93,
 160,   9, 102, 160,   9,  88,  12,  29, 104, 229,   7, 101,   0,  93, 148,   1,
 102, 148,   1,  48,  93, 161,   9, 102, 161,   9,  88,  13,  29, 104, 233,   7,
 101,   0,  93, 148,   1, 102, 148,   1,  48,  93, 162,   9, 102, 162,   9,  88,
  14,  29, 104, 241,   7, 101,   0,  93, 148,   1, 102, 148,   1,  48,  93, 162,
   9, 102, 162,   9,  88,  15,  29, 104, 244,   7, 101,   0,  93, 148,   1, 102,
 148,   1,  48,  93, 244,   7, 102, 244,   7,  48, 100, 108,   4,  88,  29,  29,
  29, 104, 158,   9, 101,   0,  93, 148,   1, 102, 148,   1,  48,  93, 244,   7,
 102, 244,   7,  48, 100, 108,   4,  88,  30,  29,  29, 104, 159,   9, 101,   0,
  93, 148,   1, 102, 148,   1,  48,  93, 162,   9, 102, 162,   9,  88,  16,  29,
 104, 253,   7, 101,   0,  93, 148,   1, 102, 148,   1,  48,  93, 163,   9, 102,
 163,   9,  88,  17,  29, 104, 144,   8, 101,   0,  93, 148,   1, 102, 148,   1,
  48,  93, 161,   9, 102, 161,   9,  88,  18,  29, 104, 165,   8, 101,   0,  93,
 148,   1, 102, 148,   1,  48,  93, 161,   9, 102, 161,   9,  88,  19,  29, 104,
 167,   8, 101,   0,  93, 148,   1, 102, 148,   1,  48,  93, 161,   9, 102, 161,
   9,  88,  20,  29, 104, 190,   8, 101,   0,  93, 148,   1, 102, 148,   1,  48,
  93, 161,   9, 102, 161,   9,  88,  21,  29, 104, 192,   8, 101,   0,  93, 148,
   1, 102, 148,   1,  48,  93, 161,   9, 102, 161,   9,  88,  22,  29, 104, 220,
   8, 101,   0,  93, 148,   1, 102, 148,   1,  48,  93, 166,   1, 102, 166,   1,
  48,  93, 164,   9, 102, 164,   9,  88,  23,  29,  29, 104, 223,   8, 101,   0,
  93, 148,   1, 102, 148,   1,  48,  93, 166,   1, 102, 166,   1,  48,  93, 164,
   9, 102, 164,   9,  88,  24,  29,  29, 104, 226,   8, 101,   0,  93, 148,   1,
 102, 148,   1,  48,  93, 166,   1, 102, 166,   1,  48,  93, 164,   9, 102, 164,
   9,  88,  25,  29,  29, 104, 229,   8, 101,   0,  93, 148,   1, 102, 148,   1,
  48,  93, 165,   9, 102, 165,   9,  88,  26,  29, 104, 134,   9, 101,   0,  93,
 148,   1, 102, 148,   1,  48,  93, 166,   1, 102, 166,   1,  48,  93, 164,   9,
 102, 164,   9,  88,  27,  29,  29, 104, 148,   9, 101,   0,  93, 148,   1, 102,
 148,   1,  48,  93, 166,   1, 102, 166,   1,  48,  93, 164,   9, 102, 164,   9,
  88,  28,  29,  29, 104, 153,   9,  71,   0,   0};


/* versioned_uris */
const char* const shell_toplevel_versioned_uris[] = {
    "C.errno", // [660]
    "C.socket", // [660]
    "C.stdio", // [660]
    "C.stdio2", // [660]
    "C.stdlib", // [660]
    "C.string", // [660]
    "C.unistd", // [660]
    "__AS3__.vec", // [660]
    "avm2.intrinsics.memory", // [684]
    "avmplus", // [660]
    "flash.concurrent", // [684]
    "flash.errors", // [660, 661, 663]
    "flash.net", // [660]
    "flash.sampler", // [660]
    "flash.system", // [660, 682]
    "flash.trace", // [660]
    "flash.utils", // [660]
    "shell", // [660]
    NULL
};

#ifdef VMCFG_AOT
extern "C" const struct {
    const char* const n_0; avmplus::DomainClass* const m_0;
    const char* const n_1; avmplus::DomainObject* const m_1;
    const char* const n_2; avmplus::NewObjectSampleClass* const m_2;
    const char* const n_3; avmplus::NewObjectSampleObject* const m_3;
    const char* const n_4; avmplus::TraceClass* const m_4;
    const char* const n_5; avmshell::CErrnoClass* const m_5;
    const char* const n_6; avmshell::CSocketClass* const m_6;
    const char* const n_7; avmshell::CStdioClass* const m_7;
    const char* const n_8; avmshell::CStdlibClass* const m_8;
    const char* const n_9; avmshell::CStringClass* const m_9;
    const char* const n_10; avmshell::CUnistdClass* const m_10;
    const char* const n_11; avmshell::FileClass* const m_11;
    const char* const n_12; avmshell::ProgramClass* const m_12;
    const char* const n_13; avmshell::ShellWorkerClass* const m_13;
    const char* const n_14; avmshell::ShellWorkerDomainClass* const m_14;
    const char* const n_15; avmshell::ShellWorkerDomainObject* const m_15;
    const char* const n_16; avmshell::ShellWorkerObject* const m_16;
} aotABCTypes_shell_toplevel = {
    "DomainClass", 0,
    "DomainObject", 0,
    "NewObjectSampleClass", 0,
    "NewObjectSampleObject", 0,
    "TraceClass", 0,
    "::avmshell::CErrnoClass", 0,
    "::avmshell::CSocketClass", 0,
    "::avmshell::CStdioClass", 0,
    "::avmshell::CStdlibClass", 0,
    "::avmshell::CStringClass", 0,
    "::avmshell::CUnistdClass", 0,
    "::avmshell::FileClass", 0,
    "::avmshell::ProgramClass", 0,
    "::avmshell::ShellWorkerClass", 0,
    "::avmshell::ShellWorkerDomainClass", 0,
    "::avmshell::ShellWorkerDomainObject", 0,
    "::avmshell::ShellWorkerObject", 0,
};
#endif
} }
/*static*/ avmplus::ClassClosure* FASTCALL avmshell::CErrnoClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = ClassClosure::cantInstantiateCreateInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmshell::CErrnoClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmshell_CErrnoClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::CErrnoClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::__errnoObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::__errnoObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER___errnoObject
    m_slots___errnoObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::__errnoObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::ErrorNumberClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::ErrorNumberClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::ErrorNumberClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_ErrorNumberClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::ErrorNumberClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::ErrorNumberObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::ErrorNumberClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::ErrorNumberClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_ErrorNumberClass
    m_slots_ErrorNumberClass.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::ErrorNumberClass::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::ErrorNumberObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::ErrorNumberObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_ErrorNumberObject
    m_slots_ErrorNumberObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::ErrorNumberObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::CErrorClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::CErrorClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::CErrorClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_CErrorClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::CErrorClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::CErrorObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::CErrorClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::CErrorClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_CErrorClass
    m_slots_CErrorClass.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::CErrorClass::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::CErrorObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ErrorObject::construct(argc, argv); } )
bool avmplus::CErrorObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_CErrorObject
    m_slots_CErrorObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ErrorObject::gcTrace(gc, 0);
    (void)(avmplus_ErrorObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::CErrorObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ErrorObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmshell::CStdlibClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = ClassClosure::cantInstantiateCreateInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmshell::CStdlibClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmshell_CStdlibClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::CStdlibClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::__stdlibObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::__stdlibObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER___stdlibObject
    m_slots___stdlibObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::__stdlibObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmshell::CUnistdClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = ClassClosure::cantInstantiateCreateInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmshell::CUnistdClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmshell_CUnistdClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::CUnistdClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::__unistdObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::__unistdObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER___unistdObject
    m_slots___unistdObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::__unistdObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmshell::CStringClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = ClassClosure::cantInstantiateCreateInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmshell::CStringClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmshell_CStringClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::CStringClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::__stringObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::__stringObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER___stringObject
    m_slots___stringObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::__stringObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmshell::CStdioClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = ClassClosure::cantInstantiateCreateInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmshell::CStdioClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmshell_CStdioClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::CStdioClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::__stdioObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::__stdioObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER___stdioObject
    m_slots___stdioObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::__stdioObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmshell::CSocketClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = ClassClosure::cantInstantiateCreateInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmshell::CSocketClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmshell_CSocketClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::CSocketClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::__socketObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::__socketObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER___socketObject
    m_slots___socketObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::__socketObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmshell::ProgramClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = ClassClosure::cantInstantiateCreateInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmshell::ProgramClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmshell_ProgramClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::ProgramClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::ProgramObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::ProgramObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_ProgramObject
    m_slots_ProgramObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::ProgramObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::DomainClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::DomainClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::DomainClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_DomainClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::DomainClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::DomainObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::DomainClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::DomainObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmshell::FileClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = ClassClosure::cantInstantiateCreateInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmshell::FileClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmshell_FileClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::FileClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::FileIOObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::FileIOObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_FileIOObject
    m_slots_FileIOObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::FileIOObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::EnvironmentClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::EnvironmentClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::EnvironmentClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_EnvironmentClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::EnvironmentClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::EnvironmentObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::EnvironmentClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::EnvironmentClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_EnvironmentClass
    m_slots_EnvironmentClass.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::EnvironmentClass::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::EnvironmentObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ProxyObject::construct(argc, argv); } )
bool avmplus::EnvironmentObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_EnvironmentObject
    m_slots_EnvironmentObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ProxyObject::gcTrace(gc, 0);
    (void)(avmplus_ProxyObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
const uint32_t avmplus::EnvironmentObject::gcTracePointerOffsets[] = {
    offsetof(avmplus::EnvironmentObject, m_slots_EnvironmentObject.m_private__vars),
    offsetof(avmplus::EnvironmentObject, m_slots_EnvironmentObject.m_private__idx),
    offsetof(avmplus::EnvironmentObject, m_slots_EnvironmentObject.m_private__env),
    0};
MMgc::GCTracerCheckResult avmplus::EnvironmentObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ProxyObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::GC::CheckOffsetIsInList(off,gcTracePointerOffsets,3);
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::EndianClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::EndianClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::EndianClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_EndianClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::EndianClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::EndianObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::EndianClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::EndianClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_EndianClass
    m_slots_EndianClass.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
const uint32_t avmplus::EndianClass::gcTracePointerOffsets[] = {
    offsetof(avmplus::EndianClass, m_slots_EndianClass.m_BIG_ENDIAN),
    offsetof(avmplus::EndianClass, m_slots_EndianClass.m_LITTLE_ENDIAN),
    0};
MMgc::GCTracerCheckResult avmplus::EndianClass::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::GC::CheckOffsetIsInList(off,gcTracePointerOffsets,2);
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::EndianObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::EndianObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_EndianObject
    m_slots_EndianObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::EndianObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::CapabilitiesClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::CapabilitiesClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::CapabilitiesClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_CapabilitiesClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::CapabilitiesClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::CapabilitiesObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::CapabilitiesClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::CapabilitiesClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_CapabilitiesClass
    m_slots_CapabilitiesClass.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::CapabilitiesClass::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::CapabilitiesObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::CapabilitiesObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_CapabilitiesObject
    m_slots_CapabilitiesObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::CapabilitiesObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::StackFrameClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::StackFrameClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::StackFrameClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_StackFrameClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::StackFrameClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::StackFrameObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::StackFrameClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::StackFrameClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_StackFrameClass
    m_slots_StackFrameClass.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::StackFrameClass::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::StackFrameObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::StackFrameObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_StackFrameObject
    m_slots_StackFrameObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
const uint32_t avmplus::StackFrameObject::gcTracePointerOffsets[] = {
    offsetof(avmplus::StackFrameObject, m_slots_StackFrameObject.m_name),
    offsetof(avmplus::StackFrameObject, m_slots_StackFrameObject.m_file),
    0};
MMgc::GCTracerCheckResult avmplus::StackFrameObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::GC::CheckOffsetIsInList(off,gcTracePointerOffsets,2);
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::SampleClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::SampleClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::SampleClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_SampleClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::SampleClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::SampleObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::SampleClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::SampleClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_SampleClass
    m_slots_SampleClass.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::SampleClass::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::SampleObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::SampleObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_SampleObject
    m_slots_SampleObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
const uint32_t avmplus::SampleObject::gcTracePointerOffsets[] = {
    offsetof(avmplus::SampleObject, m_slots_SampleObject.m_stack),
    0};
MMgc::GCTracerCheckResult avmplus::SampleObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::GC::CheckOffsetIsInList(off,gcTracePointerOffsets,1);
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::ClassFactoryClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::ClassFactoryClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::ClassFactoryClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_ClassFactoryClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::ClassFactoryClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::ClassFactoryObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::ClassFactoryClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::ClassFactoryClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_ClassFactoryClass
    m_slots_ClassFactoryClass.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
const uint32_t avmplus::ClassFactoryClass::gcTracePointerOffsets[] = {
    offsetof(avmplus::ClassFactoryClass, m_slots_ClassFactoryClass.m_StackFrameClass),
    offsetof(avmplus::ClassFactoryClass, m_slots_ClassFactoryClass.m_SampleClass),
    offsetof(avmplus::ClassFactoryClass, m_slots_ClassFactoryClass.m_DeleteObjectSampleClass),
    offsetof(avmplus::ClassFactoryClass, m_slots_ClassFactoryClass.m_NewObjectSampleClass),
    0};
MMgc::GCTracerCheckResult avmplus::ClassFactoryClass::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::GC::CheckOffsetIsInList(off,gcTracePointerOffsets,4);
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::ClassFactoryObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::ClassFactoryObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_ClassFactoryObject
    m_slots_ClassFactoryObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::ClassFactoryObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::TraceClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = ClassClosure::cantInstantiateCreateInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmplus::TraceClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_TraceClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::TraceClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::TraceObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::TraceObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_TraceObject
    m_slots_TraceObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::TraceObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::WorkerStateClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::WorkerStateClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::WorkerStateClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_WorkerStateClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::WorkerStateClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::WorkerStateObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::WorkerStateClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::WorkerStateClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_WorkerStateClass
    m_slots_WorkerStateClass.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
const uint32_t avmplus::WorkerStateClass::gcTracePointerOffsets[] = {
    offsetof(avmplus::WorkerStateClass, m_slots_WorkerStateClass.m_NEW),
    offsetof(avmplus::WorkerStateClass, m_slots_WorkerStateClass.m_RUNNING),
    offsetof(avmplus::WorkerStateClass, m_slots_WorkerStateClass.m_TERMINATED),
    offsetof(avmplus::WorkerStateClass, m_slots_WorkerStateClass.m_FAILED),
    offsetof(avmplus::WorkerStateClass, m_slots_WorkerStateClass.m_ABORTED),
    offsetof(avmplus::WorkerStateClass, m_slots_WorkerStateClass.m_EXCEPTION),
    0};
MMgc::GCTracerCheckResult avmplus::WorkerStateClass::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::GC::CheckOffsetIsInList(off,gcTracePointerOffsets,6);
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::WorkerStateObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::WorkerStateObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_WorkerStateObject
    m_slots_WorkerStateObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::WorkerStateObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmshell::ShellWorkerClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = ClassClosure::cantInstantiateCreateInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmshell::ShellWorkerClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmshell_ShellWorkerClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmshell::ShellWorkerClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmshell::ShellWorkerObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::ShellWorkerClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::ShellWorkerObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::WorkerEventClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::WorkerEventClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::WorkerEventClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_WorkerEventClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::WorkerEventClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::WorkerEventObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::WorkerEventClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::WorkerEventClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_WorkerEventClass
    m_slots_WorkerEventClass.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
const uint32_t avmplus::WorkerEventClass::gcTracePointerOffsets[] = {
    offsetof(avmplus::WorkerEventClass, m_slots_WorkerEventClass.m_WORKER_STATE),
    0};
MMgc::GCTracerCheckResult avmplus::WorkerEventClass::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::GC::CheckOffsetIsInList(off,gcTracePointerOffsets,1);
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::WorkerEventObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::WorkerEventObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_WorkerEventObject
    m_slots_WorkerEventObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
const uint32_t avmplus::WorkerEventObject::gcTracePointerOffsets[] = {
    offsetof(avmplus::WorkerEventObject, m_slots_WorkerEventObject.m_private_m_previousState),
    offsetof(avmplus::WorkerEventObject, m_slots_WorkerEventObject.m_private_m_currentState),
    offsetof(avmplus::WorkerEventObject, m_slots_WorkerEventObject.m_flash_system_m_target),
    0};
MMgc::GCTracerCheckResult avmplus::WorkerEventObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::GC::CheckOffsetIsInList(off,gcTracePointerOffsets,3);
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmshell::ShellWorkerDomainClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmshell::ShellWorkerDomainClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmshell::ShellWorkerDomainClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmshell_ShellWorkerDomainClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmshell::ShellWorkerDomainClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmshell::ShellWorkerDomainObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::ShellWorkerDomainClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmshell::ShellWorkerDomainObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::SystemClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::SystemClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::SystemClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_SystemClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::SystemClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::SystemObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::SystemClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::SystemClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_SystemClass
    m_slots_SystemClass.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::SystemClass::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::SystemObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::SystemObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_SystemObject
    m_slots_SystemObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::SystemObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::ScriptTimeoutErrorClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::ScriptTimeoutErrorClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::ScriptTimeoutErrorClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_ScriptTimeoutErrorClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::ScriptTimeoutErrorClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::ScriptTimeoutErrorObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::ScriptTimeoutErrorClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::ScriptTimeoutErrorClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_ScriptTimeoutErrorClass
    m_slots_ScriptTimeoutErrorClass.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::ScriptTimeoutErrorClass::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::ScriptTimeoutErrorObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ErrorObject::construct(argc, argv); } )
bool avmplus::ScriptTimeoutErrorObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_ScriptTimeoutErrorObject
    m_slots_ScriptTimeoutErrorObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ErrorObject::gcTrace(gc, 0);
    (void)(avmplus_ErrorObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::ScriptTimeoutErrorObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ErrorObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::StackOverflowErrorClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::StackOverflowErrorClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::StackOverflowErrorClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_StackOverflowErrorClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::StackOverflowErrorClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::StackOverflowErrorObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::StackOverflowErrorClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::StackOverflowErrorClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_StackOverflowErrorClass
    m_slots_StackOverflowErrorClass.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::StackOverflowErrorClass::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::StackOverflowErrorObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ErrorObject::construct(argc, argv); } )
bool avmplus::StackOverflowErrorObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_StackOverflowErrorObject
    m_slots_StackOverflowErrorObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ErrorObject::gcTrace(gc, 0);
    (void)(avmplus_ErrorObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::StackOverflowErrorObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ErrorObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::InvalidSWFErrorClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::InvalidSWFErrorClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::InvalidSWFErrorClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_InvalidSWFErrorClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::InvalidSWFErrorClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::InvalidSWFErrorObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::InvalidSWFErrorClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::InvalidSWFErrorClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_InvalidSWFErrorClass
    m_slots_InvalidSWFErrorClass.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::InvalidSWFErrorClass::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::InvalidSWFErrorObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ErrorObject::construct(argc, argv); } )
bool avmplus::InvalidSWFErrorObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_InvalidSWFErrorObject
    m_slots_InvalidSWFErrorObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ErrorObject::gcTrace(gc, 0);
    (void)(avmplus_ErrorObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::InvalidSWFErrorObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ErrorObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::SQLErrorOperationClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::SQLErrorOperationClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::SQLErrorOperationClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_SQLErrorOperationClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::SQLErrorOperationClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::SQLErrorOperationObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::SQLErrorOperationClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::SQLErrorOperationClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_SQLErrorOperationClass
    m_slots_SQLErrorOperationClass.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
const uint32_t avmplus::SQLErrorOperationClass::gcTracePointerOffsets[] = {
    offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass.m_ANALYZE),
    offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass.m_ATTACH),
    offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass.m_BEGIN),
    offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass.m_CLOSE),
    offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass.m_COMMIT),
    offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass.m_COMPACT),
    offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass.m_DEANALYZE),
    offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass.m_DETACH),
    offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass.m_EXECUTE),
    offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass.m_OPEN),
    offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass.m_REENCRYPT),
    offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass.m_RELEASE_SAVEPOINT),
    offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass.m_ROLLBACK),
    offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass.m_ROLLBACK_TO_SAVEPOINT),
    offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass.m_SCHEMA),
    offsetof(avmplus::SQLErrorOperationClass, m_slots_SQLErrorOperationClass.m_SET_SAVEPOINT),
    0};
MMgc::GCTracerCheckResult avmplus::SQLErrorOperationClass::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::GC::CheckOffsetIsInList(off,gcTracePointerOffsets,16);
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::SQLErrorOperationObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ScriptObject::construct(argc, argv); } )
bool avmplus::SQLErrorOperationObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_SQLErrorOperationObject
    m_slots_SQLErrorOperationObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ScriptObject::gcTrace(gc, 0);
    (void)(avmplus_ScriptObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::SQLErrorOperationObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ScriptObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::SQLErrorClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::SQLErrorClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::SQLErrorClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_SQLErrorClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::SQLErrorClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::SQLErrorObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::SQLErrorClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::SQLErrorClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_SQLErrorClass
    m_slots_SQLErrorClass.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::SQLErrorClass::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::SQLErrorObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ErrorObject::construct(argc, argv); } )
bool avmplus::SQLErrorObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_SQLErrorObject
    m_slots_SQLErrorObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ErrorObject::gcTrace(gc, 0);
    (void)(avmplus_ErrorObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
const uint32_t avmplus::SQLErrorObject::gcTracePointerOffsets[] = {
    offsetof(avmplus::SQLErrorObject, m_slots_SQLErrorObject.m_private__operation),
    offsetof(avmplus::SQLErrorObject, m_slots_SQLErrorObject.m_private__details),
    offsetof(avmplus::SQLErrorObject, m_slots_SQLErrorObject.m_private__detailArguments),
    0};
MMgc::GCTracerCheckResult avmplus::SQLErrorObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ErrorObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::GC::CheckOffsetIsInList(off,gcTracePointerOffsets,3);
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::DRMManagerErrorClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::DRMManagerErrorClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::DRMManagerErrorClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_DRMManagerErrorClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::DRMManagerErrorClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::DRMManagerErrorObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::DRMManagerErrorClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::DRMManagerErrorClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_DRMManagerErrorClass
    m_slots_DRMManagerErrorClass.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::DRMManagerErrorClass::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::DRMManagerErrorObject::construct(int argc, avmplus::Atom* argv) { return avmplus::ErrorObject::construct(argc, argv); } )
bool avmplus::DRMManagerErrorObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_DRMManagerErrorObject
    m_slots_DRMManagerErrorObject.gcTracePrivateProperties(gc);
#endif
    avmplus::ErrorObject::gcTrace(gc, 0);
    (void)(avmplus_ErrorObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::DRMManagerErrorObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ErrorObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::NewObjectSampleClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::NewObjectSampleClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), cvtable->getExtraSize()) avmplus::NewObjectSampleClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_NewObjectSampleClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::NewObjectSampleClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), cls->getExtraSize()) avmplus::NewObjectSampleObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::NewObjectSampleClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::NewObjectSampleObject::construct(int argc, avmplus::Atom* argv) { return avmplus::SampleObject::construct(argc, argv); } )
/*static*/ avmplus::ClassClosure* FASTCALL avmplus::DeleteObjectSampleClass::createClassClosure(avmplus::VTable* cvtable)
{
    cvtable->ivtable->createInstanceProc = avmplus::DeleteObjectSampleClass::createInstanceProc;
    ClassClosure* const cc = new (cvtable->gc(), MMgc::kExact, cvtable->getExtraSize()) avmplus::DeleteObjectSampleClass(cvtable);
    AvmThunk_DEBUG_ONLY( avmplus::NativeID::SlotOffsetsAndAsserts::check_avmplus_DeleteObjectSampleClass(cc->traits(), cc->traits()->itraits); )
    return cc;
}
/*static*/ avmplus::ScriptObject* FASTCALL avmplus::DeleteObjectSampleClass::createInstanceProc(avmplus::ClassClosure* cls)
{
    return new (cls->gc(), MMgc::kExact, cls->getExtraSize()) avmplus::DeleteObjectSampleObject(cls->ivtable(), cls->prototypePtr());
}
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::DeleteObjectSampleClass::construct(int argc, avmplus::Atom* argv) { return avmplus::ClassClosure::construct(argc, argv); } )
bool avmplus::DeleteObjectSampleClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_DeleteObjectSampleClass
    m_slots_DeleteObjectSampleClass.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::DeleteObjectSampleClass::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
AvmThunk_DEBUG_ONLY( avmplus::Atom avmplus::DeleteObjectSampleObject::construct(int argc, avmplus::Atom* argv) { return avmplus::SampleObject::construct(argc, argv); } )
bool avmplus::DeleteObjectSampleObject::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_DeleteObjectSampleObject
    m_slots_DeleteObjectSampleObject.gcTracePrivateProperties(gc);
#endif
    avmplus::SampleObject::gcTrace(gc, 0);
    (void)(avmplus_SampleObject_isExactInterlock != 0);
    return false;
}
#ifdef DEBUG
MMgc::GCTracerCheckResult avmplus::DeleteObjectSampleObject::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if ((result = avmplus::SampleObject::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound) return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG
