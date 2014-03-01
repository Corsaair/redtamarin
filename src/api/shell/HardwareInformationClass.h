/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __avmshell_HardwareInformationClass__
#define __avmshell_HardwareInformationClass__

namespace avmshell
{
    using namespace avmplus;

    class HardwareInformationClass : public ClassClosure
    {
    public:
        HardwareInformationClass(VTable* cvtable);
        ~HardwareInformationClass();
        
        uint32_t _getProcessorCountAtBoot();
        double _getMemorySize();
        double _getMemoryUsage();
        double _getMemoryPeakUsage();
        
        DECLARE_SLOTS_HardwareInformationClass;
    };

}

#endif /* __avmshell_HardwareInformationClass__ */

