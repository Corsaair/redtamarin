/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
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
* Portions created by the Initial Developer are Copyright (C) 2004-2006
* the Initial Developer. All Rights Reserved.
*
* Contributor(s):
*   Adobe AS3 Team. Modified by Shengnan Cong@Intel.
*   Tamarin. Refactored by Rick Reitmaier
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
#include "avmplus.h"


#ifdef VMCFG_VTUNE
#include "CodegenLIR.h"

namespace vtune
{
    using namespace avmplus;
    static bool vtune_init = false;
    static iJIT_IsProfilingActiveFlags vtuneStatus;
    static iJIT_Method_Load ML;
    static NIns *endAddr;
    uint32_t line_cap;

    void dumpVTuneMethodInfo(iJIT_Method_Load* ML)
    {
        AvmLog("method_id = %d\n", ML->method_id);
        AvmLog("method_name = %s\n", ML->method_name);
        AvmLog("method_load_address = %p\n", ML->method_load_address);
        AvmLog("method_size = %d\n", ML->method_size);
        AvmLog("line_number_size = %d\n", ML->line_number_size);
        AvmLog("line_number_table = %p\n", ML->line_number_table);

        if (ML->line_number_table)
        {
            AvmLog("\tline\toffset\n");
            LineNumberInfo* lines = ML->line_number_table;
            for (int j = 0; j < (int) ML->line_number_size; j++) {
                AvmLog("\t%d\t%d\n", lines[j].LineNumber, lines[j].Offset);
           }
        }

        AvmLog("class_id = %u\n", ML->class_id);
        AvmLog("class_file_name = '%s'\n", ML->class_file_name);
        AvmLog("source_file_name = '%s'\n", ML->source_file_name);
        AvmLog("user_data = %p\n", ML->user_data);
        AvmLog("user_data_size %u\n", ML->user_data_size);
        AvmLog("\n");
   }

    static int indexOf(const char *s, char c) {
        const char *found = strchr(s, c);
        return found ? found - s : -1;
    }
    static int lastIndexOf(const char *s, char c) {
        const char *found = strrchr(s, c);
        return found ? found - s : -1;
    }

    /**
       * parse a given MethodInfo.format() 'ed name and provide
       * the starting and ending indcies of each
     * @return true, if a class name exists
     */
    bool locateNames(const char *name, int* idx)
    {
        bool hasClass = true;
        VMPI_memset(idx,0,sizeof(*idx));
        if (!name)
            return false;

        // class
        // idx[0] = 0;
        if ((idx[1]=indexOf(name, '.')) >= 0)
            hasClass = false;  // match means no class name
        else if ((idx[1]=indexOf(name, '$')) >=0)
            idx[1]; // match
        else if ((idx[1]=indexOf(name, '/')) >= 0)
            idx[1]; // match
        else
            hasClass = false;  // nothing looks like a class here

        // method
        if ((idx[2]=lastIndexOf(name, '/')) >= 0)
            idx[2]++;  // match
        else if ((idx[2]=lastIndexOf(name, ':')) >= 0)
            idx[2]++;  // match
        else
            ;  // idx[2] = 0;
        idx[3] = strlen(name);

        return hasClass;
    }

    static char *substring(const char *str, int start, int end) {
        int len = end - start;
        char *s = (char*) VMPI_alloc(len+1);
        strncpy(s, str+start, len);
        s[len] = 0;
        return s;
    }

   void vtuneCallback(void *, iJIT_ModeFlags flags) {
        printf("XXXXXXXXX mode changed %x\n", flags);
    }

    /** initialize vtune interface one time only */
    void *vtuneInit(avmplus::String* methodName) {
        if (!vtune_init) {
            iJIT_RegisterCallbackEx(0, vtuneCallback);
            vtune_init = true;
            vtuneStatus = iJIT_IsProfilingActive();
            printf("\nVTUNE STATUS %x\n\n", vtuneStatus);
        }
        StUTF8String namebuf(methodName);
        const char *name = namebuf.c_str();
        int idx[4];
        bool hasClass = locateNames(name, idx);
        AvmAssert(ML.env == 0);
        ML.env = iJDE_JittingAPI;
        ML.method_id = iJIT_GetNewMethodID();
        ML.method_name = substring(name, idx[2], idx[3]);
        if (hasClass) {
            ML.class_file_name = substring(name, idx[0], idx[1]);
        }
        line_cap = 0;
        return &ML;
   }

    // free stuff
    void vtuneCleanup(void*) {
        if (ML.env) {
            if (ML.class_file_name)
                VMPI_free(ML.class_file_name);
            if (ML.method_name)
                VMPI_free(ML.method_name);
            if (ML.source_file_name)
                VMPI_free(ML.source_file_name);
            if (ML.line_number_table)
                VMPI_free(ML.line_number_table);
            memset(&ML, 0, sizeof(ML));
        }
    }

    void fixupLines() {
        // vtune wants lines in sorted order.
        // fixme: sorted by offset or sorted by line?  guessing offset.
        // table is in order of decreasing offsets.  We need to adjust the
        // offsets relative to start, and put them in increasing order.
        pLineNumberInfo table = ML.line_number_table;
        uint32_t count = ML.line_number_size;
        uint32_t middle = count / 2;
        uint32_t adj = ML.method_size;
        for (uint32_t i=0, j=count-1; i < middle; i++, j--) {
            table[i].Offset += adj;
            table[j].Offset += adj;
            LineNumberInfo temp = table[i];
            table[i] = table[j];
            table[j] = temp;
        }
        if (count & 1) {
            // odd number of entries, middle entry didn't move or get updated
            table[middle].Offset += adj;
        }
    }

    /** tell profiler where the method starts */
    void vtuneStart(void* h, nanojit::NIns* start) {
        AvmAssert(endAddr != 0 && endAddr > start);
        ML.method_load_address = start;
        ML.method_size = (char*)endAddr - (char*)start;

        fixupLines();
        if (ML.line_number_size > 0)
           dumpVTuneMethodInfo(&ML); // Uncommented to debug VTune
        iJIT_NotifyEvent(iJVM_EVENT_TYPE_METHOD_LOAD_FINISHED, &ML);
        vtuneCleanup(h);
    }

    void vtuneEnd(void*, NIns* end) {
        endAddr = end;
    }

    void vtuneFile(void*, void* fn) {
        StUTF8String st((String*)fn);
        const char *filename = st.c_str();
        ML.source_file_name = substring(filename, 0, strlen(filename));
    }

    void vtuneLine(void*, int line, NIns *pos) {
        if (!line_cap) {
            line_cap = 4;
            ML.line_number_table = (pLineNumberInfo) VMPI_alloc(line_cap * sizeof(LineNumberInfo));
        } else if (ML.line_number_size == line_cap) {
            line_cap *= 2;
            pLineNumberInfo table = (pLineNumberInfo) VMPI_alloc(line_cap * sizeof(LineNumberInfo));
            memcpy(table, ML.line_number_table, ML.line_number_size*sizeof(LineNumberInfo));
            VMPI_free(ML.line_number_table);
            ML.line_number_table = table;
        }

        // record offset from end for now, will adjust later once we have
        // the start address.
        pLineNumberInfo li = &ML.line_number_table[ML.line_number_size];
        ML.line_number_size++;
        li->LineNumber = line;
        li->Offset = (char*)pos - (char*)endAddr;
    }
  }

#endif /* VMCFG_VTUNE */
