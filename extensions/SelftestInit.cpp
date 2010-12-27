/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is [Open Source Virtual Machine.].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2008
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Adobe AS3 Team
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */
// Initialization code for generated selftest code
#include "avmshell.h"
namespace avmplus {
#ifdef VMCFG_SELFTEST
extern void create_avmplus_basics(AvmCore* core);
#if defined AVMPLUS_PEEPHOLE_OPTIMIZER
extern void create_avmplus_peephole(AvmCore* core);
#endif
#if defined AVMPLUS_WIN32
#if !defined VMCFG_ARM
extern void create_mmgc_bugzilla_543560(AvmCore* core);
#endif
#endif
extern void create_mmgc_bugzilla_575631(AvmCore* core);
#if defined AVMPLUS_64BIT && defined DEBUG
extern void create_mmgc_bugzilla_580603(AvmCore* core);
#endif
extern void create_mmgc_basics(AvmCore* core);
extern void create_mmgc_dependent(AvmCore* core);
extern void create_mmgc_finalize_uninit(AvmCore* core);
extern void create_mmgc_gcheap(AvmCore* core);
#if defined VMCFG_WORKERTHREADS
extern void create_mmgc_threads(AvmCore* core);
#endif
extern void create_mmgc_weakref(AvmCore* core);
extern void create_vmbase_concurrency(AvmCore* core);
extern void create_vmpi_threads(AvmCore* core);
void SelftestRunner::createGeneratedSelftestClasses() {
create_avmplus_basics(core);
#if defined AVMPLUS_PEEPHOLE_OPTIMIZER
create_avmplus_peephole(core);
#endif
#if defined AVMPLUS_WIN32
#if !defined VMCFG_ARM
create_mmgc_bugzilla_543560(core);
#endif
#endif
create_mmgc_bugzilla_575631(core);
#if defined AVMPLUS_64BIT && defined DEBUG
create_mmgc_bugzilla_580603(core);
#endif
create_mmgc_basics(core);
create_mmgc_dependent(core);
create_mmgc_finalize_uninit(core);
create_mmgc_gcheap(core);
#if defined VMCFG_WORKERTHREADS
create_mmgc_threads(core);
#endif
create_mmgc_weakref(core);
create_vmbase_concurrency(core);
create_vmpi_threads(core);
}
#endif // VMCFG_SELFTEST
}
