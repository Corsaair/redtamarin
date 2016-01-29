/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "avmshell.h"

namespace avmshell
{

    HardwareInformationClass::HardwareInformationClass(VTable *cvtable)
        : ClassClosure(cvtable)
    {
        createVanillaPrototype();
    }

    HardwareInformationClass::~HardwareInformationClass()
    {
        
    }

    uint32_t HardwareInformationClass::_getProcessorCountAtBoot()
    {
        //Linux/OSX
        //use sysconf(_SC_NPROCESSORS_CONF);
        //
        //Windows
        //use systemInfo.dwNumberOfProcessors
        return (uint32_t)VMPI_processorQtyAtBoot();
    }

    /*
    double HardwareInformationClass::_getPerformanceFrequency()
    {
        return (double)VMPI_getPerformanceFrequency();
    }

    double HardwareInformationClass::_getPerformanceCounter()
    {
        return (double)VMPI_getPerformanceCounter();
    }

    double HardwareInformationClass::_getPerformanceClockTicks()
    {
        return VMPI_getPerformanceClockTicks();
    }
    */


    double HardwareInformationClass::_getMemorySize()
    {
        return VMPI_SystemMemorySize();
    }

    double HardwareInformationClass::_getMemoryFree()
    {
        return VMPI_SystemMemoryFree();
    }

    double HardwareInformationClass::_getProcMemoryUsage()
    {
        return VMPI_ProcessMemoryUse();
    }

    double HardwareInformationClass::_getProcMemoryPeakUsage()
    {
        return VMPI_ProcessMemoryPeak();
    }

}
