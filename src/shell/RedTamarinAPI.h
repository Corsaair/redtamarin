/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef __redtamarin_api__
#define __redtamarin_api__

//CLIB

#include "CAssertClass.h" // ---- C.assert ---- 
#include "CTypeClass.h" // ---- C.ctype ---- 
#include "CErrnoClass.h" // ---- C.errno ---- 
// ---- C.float ---- 
#include "CLimitsClass.h" // ---- C.limits ---- 
#include "CLocaleClass.h" // ---- C.locale ---- 
// ---- C.math ---- 
// ---- C.setjmp ---- 
#include "CSignalClass.h" // ---- C.signal ---- 
// ---- C.stdarg ---- 
// ---- C.stddef ---- 
#include "CStdioClass.h" // ---- C.stdio ---- 
#include "CStdlibClass.h" // ---- C.stdlib ---- 
#include "CStringClass.h" // ---- C.string ---- 
#include "CTimeClass.h" // ---- C.time ---- 


#include "CConioClass.h" // ---- C.conio ---- 
// ---- C.cpio ---- 
#include "CDirentClass.h" // ---- C.dirent ---- 
#include "CFcntlClass.h" // ---- C.fcntl ---- 
// ---- C.grp ---- 
#include "CNetdbClass.h" // ---- C.netdb ---- 
#include "CNetinetInClass.h"
// ---- C.pthread ---- 
// ---- C.pwd ---- 
#include "CSpawnClass.h" // ---- C.spawn ---- 
// ---- C.sys.ipc ---- 
// ---- C.sys.mman ---- 
// ---- C.sys.msg ---- 
// ---- C.sys.sem ---- 
#include "CSysSocketClass.h" // ---- C.sys.socket ---- 
#include "CSysStatClass.h" // ---- C.sys.stat ---- 
// ---- C.sys.time ---- 
// ---- C.sys.types ---- 
// ---- C.sys.utsname ---- 
#include "CSysWaitClass.h" // ---- C.sys.wait ---- 
// ---- C.tar ---- 
// ---- C.termios ---- 
#include "CUnistdClass.h" // ---- C.unistd ---- 
// ---- C.utime ---- 

//old stuff
//#include "CSocketClass.h"


//RNL
#include "RuntimeClass.h"
#include "DiagnosticsClass.h"
#include "HardwareInformationClass.h"
#include "OperatingSystemClass.h"
#include "FileSystemClass.h"

//#include "RedTamarinProgramClass.h"
//

//#include "SocketClass.h"

//AVMGlue
#include "SystemClass.h"


#endif /* __redtamarin_api__ */
