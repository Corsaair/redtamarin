#!/bin/sh
(set -o igncr) 2>/dev/null && set -o igncr; # comment is needed

process_builds()
{
  builds=$1
  case "$builds" in
    all)
      builds="Release Debug Release_Debugger Debug_Debugger"
      ;;
    nondebugger)
      builds="Release Debug"
      ;;
    debugger)
      builds="Release_Debugger Debug_Debugger"
      ;;
  esac
  export builds
}

restore_revision()
{
  mv -f $basedir/../core/avmplusVersion.h.backup $basedir/../core/avmplusVersion.h
}
update_revision()
{
  revision=$1
  echo "setting revision number to $revision"
  cp $basedir/../core/avmplusVersion.h $basedir/../core/avmplusVersion.h.backup
  chmod +w $basedir/../core/avmplusVersion.h
  sed --in-place "s/d684/$revision/g" $basedir/../core/avmplusVersion.h
  sed --in-place "s/684/$revision/g" $basedir/../core/avmplusVersion.h
}
set_build_name()
{
  case "$platform $version" in
    'CYGWIN_NT-5.1 Release'|'CYGWIN_NT-5.2 Release') 
          buildname=Release/avmplus.exe
          ;;
    'CYGWIN_NT-5.1 Debug'|'CYGWIN_NT-5.2 Debug') 
          buildname=Debug/avmplus_d.exe
          ;;
    'CYGWIN_NT-5.1 Release_Debugger'|'CYGWIN_NT-5.2 Release_Debugger') 
          buildname=Release_Debugger/avmplus_s.exe
          ;;
    'CYGWIN_NT-5.1 Debug_Debugger'|'CYGWIN_NT-5.2 Debug_Debugger') 
          buildname=Release/avmplus_sd.exe
          ;;
     *)
          echo "ERROR: unknown build '$platform $version'"
          exit 1
          ;;
  esac
  export buildname
}
build_windows() 
{
  version=$1
  test "$version" = "" && version=Release
  set_build_name
  cd $basedir/../platform/win32
  echo "building $version..."
  devenv avmplus_8.sln /build $version /out build.out
  res=$?
  cat build.out
  test "$res" = "0" || {
    echo "ERROR: devenv avmplus_8.sln /build $version FAILED, retval=$res"
    exit 1
  }
  test -f ./obj_8/shell/$buildname || {
    echo "ERROR: obj_8/shell/$buildname executable does not exist"
    exit 1
  }
}

builds=$1
revision=$2
test "$revision" = "" && revision="cyclone_${USER}_`date +%Y-%m-%d_%H-%m`"
test "$builds" = "" && builds="nondebugger"
basedir=`dirname $0`
test "$basedir" = "." && basedir=`pwd`

# load msvc setup if exists
test -f /usr/local/bin/msvc.sh && {
  . /usr/local/bin/msvc.sh
}

platform=`uname`
case "$platform" in
  'CYGWIN_NT-5.1'|'CYGWIN_NT-5.2') 
     update_revision $revision
     process_builds $builds
     # cleanup old builds
     test -d $basedir/../platform/obj_8 && rm -fr $basedir/../platform/obj_8
     test -f $basedir/../platform/build.out && rm $basedir/../build.out

     for b in $builds
     do
       build_windows $b
     done
     restore_revision
     echo "done"
     ;;
  *)
     echo "ERROR $platform is not supported"
     exit 1
     ;;
esac

exit 0