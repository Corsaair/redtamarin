/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

/* machine generated file via utils/exactgc.as -- do not edit */

namespace avmshell
{

#ifdef DEBUG
MMgc::GCTracerCheckResult ProgramClass::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if((result = avmplus::ClassClosure::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound)
        return result;
    return MMgc::kOffsetNotFound;
}
#endif // DEBUG

bool ProgramClass::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
#ifndef GC_TRIVIAL_TRACER_ProgramClass
    m_slots_ProgramClass.gcTracePrivateProperties(gc);
#endif
    avmplus::ClassClosure::gcTrace(gc, 0);
    (void)(avmplus_ClassClosure_isExactInterlock != 0);
    return false;
}


#if defined(DEBUGGER)

#ifdef DEBUG
const uint32_t DebugCLI::gcTracePointerOffsets[] = {
    offsetof(DebugCLI, currentFile),
    offsetof(DebugCLI, firstBreakAction),
    offsetof(DebugCLI, lastBreakAction),
    0};

MMgc::GCTracerCheckResult DebugCLI::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if((result = avmplus::Debugger::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound)
        return result;
    return MMgc::GC::CheckOffsetIsInList(off,gcTracePointerOffsets,3);
}
#endif // DEBUG

bool DebugCLI::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
    avmplus::Debugger::gcTrace(gc, 0);
    (void)(avmplus_Debugger_isExactInterlock != 0);
    gc->TraceLocation(&currentFile);
    gc->TraceLocation(&firstBreakAction);
    gc->TraceLocation(&lastBreakAction);
    return false;
}

#endif // defined(DEBUGGER)


#ifdef DEBUG
const uint32_t ShellToplevel::gcTracePointerOffsets[] = {
    offsetof(ShellToplevel, shellClasses),
    0};

MMgc::GCTracerCheckResult ShellToplevel::gcTraceOffsetIsTraced(uint32_t off) const
{
    MMgc::GCTracerCheckResult result;
    (void)off;
    (void)result;
    if((result = avmplus::Toplevel::gcTraceOffsetIsTraced(off)) != MMgc::kOffsetNotFound)
        return result;
    return MMgc::GC::CheckOffsetIsInList(off,gcTracePointerOffsets,1);
}
#endif // DEBUG

bool ShellToplevel::gcTrace(MMgc::GC* gc, size_t _xact_cursor)
{
    (void)gc;
    (void)_xact_cursor;
    avmplus::Toplevel::gcTrace(gc, 0);
    (void)(avmplus_Toplevel_isExactInterlock != 0);
    gc->TraceLocation(&shellClasses);
    return false;
}


}
