/* -*- Mode: C++; c-basic-offset: 4; indent-tabs-mode: t; tab-width: 4 -*- */
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
 * The Original Code is [Open Source Virtual Machine].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2007
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
 
// avmremote.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include <rapi.h>

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    return TRUE;
}


STDAPI StartAVMShell(
   DWORD cbInput,
   BYTE  *pInput,
   DWORD *pcbOutput,
   BYTE  **ppOutput,
   IRAPIStream *pIRAPIStream )
{

	WCHAR cmdLine[256];
	if (cbInput>0)
	{
		WCHAR wOpt[64];
		int cnt = MultiByteToWideChar(CP_ACP, 0, (LPCSTR)pInput, cbInput, wOpt, 64);
		wcscpy(cmdLine, wOpt);
		wcscat(cmdLine, L" -log \\Temp\\avmfile.abc");
	}
	else
		wcscpy(cmdLine, L"-log \\Temp\\avmfile.abc");

	PROCESS_INFORMATION processInfo;
	// program live in \\Program Files\\shell\\avmshell.exe
	BOOL bResult = CreateProcess(L"\\Program Files\\shell\\avmshell.exe",
								cmdLine,
								NULL, NULL, FALSE,
								CREATE_NEW_CONSOLE,
								NULL, NULL, NULL,
								&processInfo);
	
	if (!bResult) {
		DebugBreak();
		return E_FAIL;
	}

	if (pcbOutput)
	{
		*ppOutput = (BYTE*)LocalAlloc(LPTR, sizeof(HANDLE));

		*(HANDLE*)*ppOutput = processInfo.hProcess;

		*pcbOutput = sizeof(HANDLE);
	}

	return S_OK;
}

typedef struct _wait_info
{
	HANDLE proc_id;
	DWORD dwTimeout;
} wait_info;

STDAPI WaitForAVMShell(
   DWORD cbInput,
   BYTE  *pInput,
   DWORD *pcbOutput,
   BYTE  **ppOutput,
   IRAPIStream *pIRAPIStream )
{
	if (cbInput!=sizeof(wait_info))
		return E_FAIL;

	wait_info* info = (wait_info*)pInput;

	DWORD dwWait = WaitForSingleObject(info->proc_id, info->dwTimeout);
	if (dwWait==WAIT_FAILED)
		return E_FAIL;

	*ppOutput = (BYTE*)LocalAlloc(LPTR, sizeof(DWORD));
	*((DWORD*)*ppOutput) = dwWait;
	*pcbOutput = sizeof(DWORD);

	return S_OK;
}

STDAPI KillAVMShell(
   DWORD cbInput,
   BYTE  *pInput,
   DWORD *pcbOutput,
   BYTE  **ppOutput,
   IRAPIStream *pIRAPIStream )
{
	HANDLE hProcess = (HANDLE)*pInput;
	TerminateProcess(hProcess, 0);

	return S_OK;
}
