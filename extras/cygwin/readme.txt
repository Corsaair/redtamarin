cygwin .bash_profile
====================

For the courageous who wants to compile redtamarin from sources under Windows

here an example of configuration:

Under Windows 7 64-bit

1) install Microsoft Visual C++ 2010 Express
   this will install all the Microsoft toolchain to compile C/C++

2) install the Windows SDK v7.0A
   this will install the 64-bit versions of the Microsoft toolchain

3) install cygwin
   we do not compile from cmd.exe
   we do compile from cygwin, there is no other way

4) configure cygwin
   in the user home folder add a .bash_profile file
   so when the redtamarin compilation run
   the build know where to find the different tools

copy either _bash_profile32.txt or _bash_profile64.txt
to .bash_profile


here the catch, you can not compile 32-bit and 64-bit targets at the same time

you will need to update the .bahs_profile and reload cygwin shell
each time you change from 32-bit to 64-bit or vise versa



You can find free versions of Microsoft Visual Studio Express here
http://www.visualstudio.com/en-us/products/visual-studio-express-vs.aspx

the current builds of redtamarin are compiled
- under Windows 7 Ultimate SP1 64-bit
- with Microsoft Visual C++ 2010 Express
- with Windows SDK v7.0A

yes those versions are a bit old and are probably not available anymore to download
so the current equivalent of "Microsoft Visual C++ 2010 Express"
should be "Microsoft Visual C++ 2013 for Windows"
if you do try to use this version to compile redtamarin
you will HAVE TO update the cygwin .bahs_profile to point to the correct paths


OR you can simply download and install "Microsoft Visual C++ 2010 Express"
http://www.visualstudio.com/downloads/download-visual-studio-vs#DownloadFamilies_4



