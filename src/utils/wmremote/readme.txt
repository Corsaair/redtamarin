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
 * Portions created by the Initial Developer are Copyright (C) 2007-2008
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

Compiling Utilities:
* Add the following directory to the  VC++ Directories (Tools->Options->Projects and Solutions)
    
    Platform:               Win32
    Show Directories For:   Include files
    Directory:              C:\Program Files\Windows Mobile 6 SDK\Active

    Platform:               Win32
    Show Directories For:   Library files
    Directory:              C:\Program Files\Windows Mobile 6 SDK\Activesync\Lib

    Platform:               Windows Mobile 6 Profession SDK
    Show Directories For:   Include files
    Directory:              C:\Program Files\Windows Mobile 6 SDK\Active

    Platform:               Windows Mobile 6 Profession SDK
    Show Directories For:   Library files
    Directory:              C:\Program Files\Windows Mobile 6 SDK\Activesync\Lib



Unlocking the Device:
* Install the Microsoft Security Configuration Manager application 
http://www.microsoft.com/downloads/details.aspx?FamilyID=7E92628C-D587-47E0-908B-09FEE6EA517A&displaylang=en
* Provision the device with a "Security Off" configuration
* NOTE: You made need to provision the device twice in order for it to work. The first time it may fail, possibly just updating certificates. 


Shell Setup:
* Compile 
* Copy avmremote.dll into the "Windows" folder on the device
    + in activesync click on Explore
    + click My Windows Mobile/Windows
    + drag avmremote.dll there, confirm it's there and about 5k (matches filesize) 
* On device create the following directory /Program Files/shell
* Compile the avmplus shell for Windows Mobile or download from ftp://ftp.mozilla.org/pub/js/tamarin/builds/
* On desktop pc run ceremotedeployer.exe <path_to_avmshell_arm.exe>
* Confirm on device shell/avmshell.exe exists (It will be renamed to avmshell.exe on the device)
* Note: you can also manually copy avmshell.exe to /Program Files/shell (it must be called avmshell.exe)
* Confirm that the shell is running correctly on device
    + Download or build ceremoteshell.exe
    + On desktop pc run $> ceremoteshell.exe version.abc
    + This should return the version string from the shell that is on the device 


