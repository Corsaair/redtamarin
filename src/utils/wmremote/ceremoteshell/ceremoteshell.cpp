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

// ceremoteshell.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <rapi.h>

typedef struct _wait_info
{
	HANDLE proc_id;
	DWORD dwTimeout;
} wait_info;

#define PROCESS_TIMEOUT 300000

int _tmain(int argc, _TCHAR* argv[])
{

  if (argc<2)
    return -1;

//	printf("starting...\n");
	// Initialize RAPI
	HRESULT hr = CeRapiInit();

	DWORD dwErr = 0;
	// Start avmshell with -redir
	DWORD dwAttr = CeGetFileAttributes(L"\\Program Files\\shell\\avmshell.exe");


//    printf("copying avmshell.exe...\n");
	// Filename will be passed last param
	HANDLE hFile = ::CreateFile(argv[argc-1], 
								GENERIC_READ, FILE_SHARE_READ,
								NULL, OPEN_EXISTING,
								FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile==INVALID_HANDLE_VALUE)
	{
        printf("unable to open avmshell.exe\n");
		dwErr = GetLastError();

		CeRapiUninit();
		return -1;
	}

	// remove the log file from previous run if it exists.
	// It is left in place in the event that you need to debug
	hr = CeDeleteFile(L"\\Temp\\avmfile.log");
//    printf("copying avmfile.abc...\n");

	// Create the file on the device in the temp directory
	WCHAR ceFilename[MAX_PATH];
	DWORD dwmblen = ::MultiByteToWideChar(CP_ACP, MB_COMPOSITE, argv[1], _tcslen(argv[1]), ceFilename, MAX_PATH); 
	ceFilename[dwmblen] = 0;


	WCHAR cePath[MAX_PATH];
	HANDLE ceFile = CeCreateFile(L"\\Temp\\avmfile.abc", GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL,NULL);

	if (ceFile==INVALID_HANDLE_VALUE)
	{
        printf("unable to open avmfile.abc\n");
		dwErr = GetLastError();
        CloseHandle(hFile);
		CeRapiUninit();
		return -1;
	}

	char localBuf[4096];
	DWORD dwBufsize=4096, dwFilesize = ::GetFileSize(hFile, NULL);
	if (dwFilesize<4096)
		dwBufsize = dwFilesize;


	DWORD dwCeBytes=0, dwRead;
	while (ReadFile(hFile, localBuf, dwBufsize, &dwRead, NULL))
	{
		BOOL bWrite = CeWriteFile(ceFile, (void*)localBuf, dwRead, &dwCeBytes, NULL);
		if (!bWrite)
		{
			dwErr = CeGetLastError();
		}
		dwFilesize -= dwRead;
		if (dwFilesize<4096)
			dwBufsize = dwFilesize;
		if (dwBufsize<=0)
			break;

	}
	dwErr = GetLastError();
	CeCloseHandle(ceFile);

	DWORD cbIn=0, cbOut;
	BYTE *pIn=NULL, *pOut;
	if (argc>2)
	{
		cbIn = 256;
		pIn = (BYTE*)LocalAlloc(LPTR, 256);
		strcpy((char*)pIn, argv[1]);
	}
//	printf("calling start avmshell...\n");
	hr = CeRapiInvoke( L"\\Windows\\avmremote.dll", L"StartAVMShell",
						cbIn, ( BYTE * ) pIn,  
						&cbOut, ( BYTE ** ) &pOut, NULL, 0);

	HANDLE hProcess = *(HANDLE*)pOut;
	LocalFree((HLOCAL)*pOut);
	if (pIn) LocalFree((HLOCAL)pIn);

	// Check every second (up to PROCESS_TIMEOUT)
	wait_info info;
	DWORD dwTimeout = 0;
	DWORD dwInterval = 1000;
	info.dwTimeout = dwInterval;
	info.proc_id = hProcess;
//	printf("calling wait for avmshell...\n");
	while (CeRapiInvoke(L"\\Windows\\avmremote.dll", L"WaitForAVMShell",
						sizeof(wait_info), (BYTE*)&info,  
						&cbOut, ( BYTE ** ) &pOut, NULL, 0)==S_OK)
	{
		// pOut should be the return code
		DWORD dwCode = *(DWORD*)pOut;
		LocalFree((HLOCAL)*pOut);

		if (dwCode==WAIT_TIMEOUT)
		{
			dwTimeout += dwInterval;
			if (dwTimeout>=PROCESS_TIMEOUT)
			{
				// Kill the process if we don't end in a decent amount of time (e.g. 60 seconds)
				CeRapiInvoke(L"\\Windows\\avmremote.dll", L"KillAVMShell",
								sizeof(HANDLE), (BYTE*)&hProcess,  
								&cbOut, ( BYTE ** ) &pOut, NULL, 0);
				break;
			}
			continue;
		}

		break;
	}
		

	// above may have failed!

	DWORD dwTickStart = ::GetTickCount();
	dwAttr = CeGetFileAttributes(L"\\Temp\\avmfile.log");
	if (dwAttr==-1)
	{
		printf("no output file\n");
		// no output file, test must have crashed
		//hr = CeDeleteFile(L"\\Temp\\avmfile.abc");
	
		// Uninitialize RAPI
		CeRapiUninit();

		return -1;
	}


	while (1)
	{
		if (::GetTickCount()>(dwTickStart+600000))
			break; // assume we failed after 10(?) minutes

		Sleep(100);
		dwAttr = CeGetFileAttributes(L"\\Temp\\avmfile.log");
		if (dwAttr==-1)
			continue;
		ceFile = CeCreateFile(L"\\Temp\\avmfile.log", GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		if (ceFile==INVALID_HANDLE_VALUE)
			continue;
		if (CeGetFileSize(ceFile, NULL)==0)
			continue;

		break;
	}

	// now delete 
	//hr = CeDeleteFile(L"\\Temp\\avmfile.abc");
	
	// dump the temp file to stdout - YUCK
	dwBufsize = 4096;
	dwFilesize = CeGetFileSize(ceFile, NULL);
	if (dwFilesize<4096)
		dwBufsize = dwFilesize;

	while (CeReadFile(ceFile, localBuf, dwBufsize, &dwRead, NULL))
	{
	
		fwrite((void*)localBuf, 1, dwRead, stdout);

		//hr = CeWriteFile(ceFile, (void*)localBuf, dwRead, &dwCeBytes, NULL);
		
		dwFilesize -= dwRead;
		if (dwFilesize<4096)
			dwBufsize = dwFilesize;
		if (dwBufsize<=0)
			break;
	}
	fflush(stdout);
	dwErr = GetLastError();
	CeCloseHandle(ceFile);

	// Uninitialize RAPI
	CeRapiUninit();

	return 0;
}

