cygwin helpers for Windows Developers
=====================================

The Developer Environment Windows Setup is fully documented here
https://github.com/Corsaair/redtamarin/wiki/WindowsSetup

To make it easier to have everythign installed you can use
redtamarin-dev-setup.bat

which is almsot the same as redtamarin-setup.bat
with those 2 differences
  - more Cygwin packages are installed by default
  - the _profile file is copied as your .profile

Because this setup will happen before you install Visual Studio, Java and other SDK
a lot of environment variables may not be right or could be simply broken

You will have to open this .profile
and review the following environment variables
  - JAVA_HOME
  - ANT_HOME
  - WPKG_OPTIONS
  - REDTAMARIN_SDK
  - VS_HOME_PATH
  - VS_HOME
  - VS_SDK

Usage
-----

  - read [Windows Setup](https://github.com/Corsaair/redtamarin/wiki/WindowsSetup)
  - while reading, when you reach the part **Command-line**
    download https://raw.githubusercontent.com/corsaair/redtamarin/master/extras/cygwin/redtamarin-dev-setup.bat
  - open a command prompt (cmd.exe) and run redtamarin-dev-setup.bat
  - go trough the end of redtamarin-dev-setup.bat
    till you reach "DEVELOPERS COMPLETE for Windows 64-bit"
  - keep reading "Windows Setup" and installign stuff
  - when you install Java, then go back to your .profile and edit JAVA_HOME
  - rinse and repeat till the end of the "Windows Setup"


Profile Commands
----------------

The .profile installed gives you some more commands

$ build32
change your profile setup to build 32-bit executable with MSVC

$ build64
change your profile setup to build 64-bit executable with MSVC

$ vsarch
show a message to indicate wchi compilation architecture is setup for MSVC
for ex: "Visual Studio is setup for 64-bit compilation"

Also if your CPU have multicores you can edit the
environment variable CL_MPCount

by default CL_MPCount=4 (for a dual core CPU)
the general formula is to multiply by 2 your number of cores

You can know tour number of cores with
$ echo $NUMBER_OF_PROCESSORS



Quick Tutorial on How to Compile Redtamarin
-------------------------------------------

First you need to configure the ant build
Copy build/common.properties to build/user.properties

edit build/user.properties

build.binaries = true
build.32bit = true
build.64bit = false
build.release = false
build.debug = false
build.debugger = true

this indicate you want to build the redshell debug debugger in 32-bit

in the root of the redtamarin project

be sure you are using a 32-bit config
$ build32

now run the build
$ ant

if all goes well this should compile a redshell_dd.exe
that you can find in /bin-release/windows/32/debugger/


Now if you want to build both a 32-bit and 64-bit executable
you will need to use the build/build32and64 helper

just run the build with
$ build/build32and64

with the config in build/user.properties
it will produce 2 executables

redshell_dd.exe 32-bit that you can find in
/bin-release/windows/32/debugger/

and

redshell_dd.exe 64-bit that you can find in
/bin-release/windows/64/debugger/


build32and64 is just a little bash script
that basically do this
$ build32
$ ant -Dbuild.32bit=true -Dbuild.64bit=false

and that
$ build64
$ ant -Dbuild.32bit=false -Dbuild.64bit=true

