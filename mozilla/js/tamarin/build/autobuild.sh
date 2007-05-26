#!/bin/sh
(set -o igncr) 2>/dev/null && set -o igncr; # comment is needed

revision=$1
test "$revision" = "" && revision="cyclone_${USER}_`date +%Y-%m-%d_%H-%m`"
test "$revision" = "autobuild" && {
  revision="`hostname``date +%Y-%m-%d_%H-%m`"
}

test "$FILEDROP" = "" && {
  FILEDROP=/w/builds/tamarin
}

basedir=`dirname $0`

$basedir/build.sh nondebugger $revision

test -d "$FILEDROP/$revision" ||
  mkdir "$FILEDROP/$revision"
cp $basedir/../platform/win32/obj_8/shell/Release/avmplus.exe $FILEDROP/$revision
cp $basedir/../platform/win32/obj_8/shell/Debug/avmplus_d.exe $FILEDROP/$revision
wget -q -O wget-result.txt "http://10.59.3.68/cgi-bin/updatebuild.pl?build=$revision&os=windows&name=tamarin"
