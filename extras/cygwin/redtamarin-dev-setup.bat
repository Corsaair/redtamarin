@ECHO OFF
REM -- Redtamarin Windows Environment Setup
REM -- for DEVELOPERS
REM -- This will install the following:
REM -- 1) Cygwin
REM --    https://cygwin.com/
REM -- 2) Cygwin Packages
REM --    bash,bash-completion,mintty,ncurses,which,
REM --    nano,wget,hostname,openssh
REM --    diffutils,patchutils
REM --    subversion,subversion-tools
REM --    git,git-completion,git-svn
REM --    mercurial
REM -- 3) apt-cyg - Cygwin Package Manager
REM --    https://github.com/transcode-open/apt-cyg
REM -- 4) Wpkg - Microsoft Windows Packager
REM --    http://windowspackager.org/

SETLOCAL

REM -- Change to the directory of the executing batch file
CD %~dp0
ECHO *** Redtamarin Windows Environment Setup
PAUSE

REM -- Detect 64-bit or 32-bit system
SET WINBIT=32
IF "%PROCESSOR_ARCHITECTURE%" == "AMD64" (
    SET WINBIT=64
) ELSE IF "%PROCESSOR_ARCHITEW6432%" == "AMD64" (
    SET WINBIT=64
)

IF "%WINBIT%" == "64" (
    SET CYGWIN_URL=https://cygwin.com/setup-x86_64.exe
) ELSE (
    SET CYGWIN_URL=https://cygwin.com/setup-x86.exe
)

REM -- Download Cywin setup exe
ECHO *** Downloading Cygwin
SET TARGET_EXE=%~dp0setup.exe
SET DOWNLOAD_CMD="(new-object System.Net.WebClient).DownloadFile( '%CYGWIN_URL%', '%TARGET_EXE%' )"
PowerShell.exe -Command "%DOWNLOAD_CMD%"

REM -- Configure our paths
REM -- by default we use a US mirror in California
REM -- other mirrors can be found https://cygwin.com/mirrors.html
SET SITE=http://mirrors.kernel.org/sourceware/cygwin/
SET LOCALDIR=%LOCALAPPDATA%/cygwin
SET ROOTDIR=C:/cygwin
SET APTCYG_URL=https://raw.githubusercontent.com/corsaair/redtamarin/master/extras/cygwin/apt-cyg

REM -- These are the cygwin packages we will install
SET PACKAGES=bash,bash-completion,mintty,ncurses,which
SET PACKAGES=%PACKAGES%,nano,wget,hostname,openssh
SET PACKAGES=%PACKAGES%,diffutils,patchutils
SET PACKAGES=%PACKAGES%,subversion,subversion-tools
SET PACKAGES=%PACKAGES%,git,git-completion,git-svn
SET PACKAGES=%PACKAGES%,mercurial


REM -- Install Cygwin and default packages
ECHO *** Installing Cygwin
ECHO *** and default packages
ECHO *** %PACKAGES%
ECHO *** wait for the Cygwin installer to complete
setup.exe -q -D -L -d -g -o -s %SITE% -l "%LOCALDIR%" -R "%ROOTDIR%" -C Base -P %PACKAGES%
PAUSE
ECHO *** Cygwin and packages installed

REM -- Install Apt-cyg
ECHO *** Downloading and Installing apt-cyg
set PATH=%ROOTDIR%/bin;%PATH%
%ROOTDIR%/bin/bash.exe -c 'wget -P /bin %APTCYG_URL%'
%ROOTDIR%/bin/bash.exe -c 'chmod +x /bin/apt-cyg'
ECHO *** apt-cyg installed
PAUSE

REM -- Configure Cygwin
ECHO *** to configure Cygwin we need to open another window
ECHO *** this will create your home directory for Cygwin
ECHO *** in the other window wait for the files to be created
ECHO *** then type 'exit' and ENTER to close it
PAUSE
start cmd.exe /C %ROOTDIR%/Cygwin.bat
ECHO *** Cygwin is now configured
PAUSE

REM -- Install WPKG
ECHO *** Downloading and Installing wpkg
REM -- even if flagged as 'amd64' this is 32-bit executable
REM -- PE32 executable (GUI) Intel 80386, for MS Windows, Nullsoft Installer self-extracting archive
SET WPKG_URL=http://downloads.sourceforge.net/project/unigw/wpkg/1.0.0/wpkg-1.0.0-amd64.exe
%ROOTDIR%/bin/bash.exe -c 'wget %WPKG_URL%'
%ROOTDIR%/bin/bash.exe -c 'chmod +x wpkg-1.0.0-amd64.exe'
ECHO *** follow the wpkg installer instructions
wpkg-1.0.0-amd64.exe
PAUSE
ECHO *** wpkg installed
PAUSE
ECHO *** Configuring wpkg for cygwin
%ROOTDIR%/bin/bash.exe -c 'cp /cygdrive/c/WPKG/wpkg_static.exe /bin/wpkg.exe'
%ROOTDIR%/bin/bash.exe -c "echo $'' >> ~/.bash_profile"
%ROOTDIR%/bin/bash.exe -c "echo $'# Redtamarin Windows Environment Setup' >> ~/.bash_profile"
%ROOTDIR%/bin/bash.exe -c "echo $'export WPKG_OPTIONS=\'--root c:/cygwin --admindir c:/WPKG/var/lib/wpkg\'' >> ~/.bash_profile"
%ROOTDIR%/bin/bash.exe -c "echo $'' >> ~/.bash_profile"
%ROOTDIR%/bin/bash.exe -c "echo $'' >> ~/.profile"
%ROOTDIR%/bin/bash.exe -c "echo $'# Redtamarin Windows Environment Setup' >> ~/.profile"
%ROOTDIR%/bin/bash.exe -c "echo $'export WPKG_OPTIONS=\'--root c:/cygwin --admindir c:/WPKG/var/lib/wpkg\'' >> ~/.profile"
%ROOTDIR%/bin/bash.exe -c "echo $'' >> ~/.profile"
ECHO *** wpkg configured for cygwin
ECHO *** see WPKG_OPTIONS in ~/.profile and ~/.bash_profile
PAUSE
ECHO *** Configuring ~/.profile for Redtamarin Development
ECHO *** your current ~/.profile will be saved as ~/_profile_before
%ROOTDIR%/bin/bash.exe -c 'mv ~/.profile ~/_profile_before'
%ROOTDIR%/bin/bash.exe -c 'wget https://raw.githubusercontent.com/corsaair/redtamarin/master/extras/cygwin/_profile'
%ROOTDIR%/bin/bash.exe -c 'mv ~/_profile ~/.profile'
ECHO *** Configuration done
PAUSE
ECHO.
ECHO.
ECHO *** Redtamarin Windows Environment Setup
ECHO *** DEVELOPERS COMPLETE for Windows %WINBIT%-bit
ECHO.
ENDLOCAL
PAUSE
EXIT /B 0