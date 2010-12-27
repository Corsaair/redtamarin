#!/bin/bash
# -*- Mode: sh; indent-tabs-mode: nil; tab-width: 4 -*-
# vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5)
# ***** BEGIN LICENSE BLOCK *****
# Version: MPL 1.1/GPL 2.0/LGPL 2.1
#
# The contents of this file are subject to the Mozilla Public License Version
# 1.1 (the "License"); you may not use this file except in compliance with
# the License. You may obtain a copy of the License at
# http://www.mozilla.org/MPL/
#
# Software distributed under the License is distributed on an "AS IS" basis,
# WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
# for the specific language governing rights and limitations under the
# License.
#
# The Original Code is [Open Source Virtual Machine.].
#
# The Initial Developer of the Original Code is
# Adobe System Incorporated.
# Portions created by the Initial Developer are Copyright (C) 2010
# the Initial Developer. All Rights Reserved.
#
# Contributor(s):
#   Adobe AS3 Team
#
# Alternatively, the contents of this file may be used under the terms of
# either the GNU General Public License Version 2 or later (the "GPL"), or
# the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
# in which case the provisions of the GPL or the LGPL are applicable instead
# of those above. If you wish to allow use of your version of this file only
# under the terms of either the GPL or the LGPL, and not to allow others to
# use your version of this file under the terms of the MPL, indicate your
# decision by deleting the provisions above and replace them with the notice
# and other provisions required by the GPL or the LGPL. If you do not delete
# the provisions above, a recipient may use your version of this file under
# the terms of any one of the MPL, the GPL or the LGPL.
#
# ***** END LICENSE BLOCK ***** */
# acts as a proxy to remotely run abc files on android using adb, returns shell output to stdout
# usage: ./android_shell.sh <vmargs> file.abc
# assumes the android shell is deployed to /data/app/avmshell
#
filelist=""
flatfilelist=""
adbargs=
id=

if [ "$1" = "" ] || [ "$1" = "-Dversion" ]
then
    # Since the adb-shell-deployer ensures that ALL devices are setup with the same shell
    # we just need to find one device to query
    adboutput=`adb devices`
    deviceid=''
    IFS=$'\n'
    for i in ${adboutput}; do
        if echo $i | grep -q 'device$'; then
            deviceid=`echo $i | awk '{print $1}'`
            break
        fi
    done
    unset IFS
    adb -s ${deviceid} shell "cd /data/app;./avmshell $1"
else
    args=""
    for a in $*
    do
       echo "$a" | grep -q "\-\-threadid="
       res=$?
       if [ "$res" = "0" ]
       then
           logid=`echo $a | awk -F= '{print $2}'`
       else
           echo "$a" | grep -q "\-\-androidid="
           res=$?
           if [ "$res" = "0" ]
           then
               id=`echo $a | awk -F= '{print $2}'`
               adbargs="-s $id"
           else
               echo "$a" | grep -q ".*\.abc"
               res=$?
               if [ "$res" = "0" ]
               then
                   file=$a
                   flatfile=`basename $a`
                   filelist="$filelist $flatfile"
                   adb $adbargs push $file /data/app/$flatfile 2> /dev/null
                   args="$args $flatfile"
               else
                   args="$args $a"
               fi
           fi
       fi
    done
    # workaround for adb not returning exit code, run a shell script and print exit code to stdout
    echo adb $adbargs shell "/data/app/android_runner.sh $args" > /tmp/stdout${id}-${logid}
    adb $adbargs shell "/data/app/android_runner.sh $args" > /tmp/stdout${id}-${logid}
    ret=`cat /tmp/stdout${id}-${logid} | grep "EXITCODE=" | awk -F= '{printf("%d",$2)}'`
    for a in $filelist
    do
        adb $adbargs shell "rm /data/app/$a"
    done
    # remove the EXITCODE from the stdout before returning it so that exact output matching will be fine
    tr -d '\r' < /tmp/stdout${id}-${logid} | sed 's/^EXITCODE=[0-9][0-9]*//g' > /tmp/stdout_clean${id}-${logid}
    cat /tmp/stdout_clean${id}-${logid}
    rm -f /tmp/stdout${id}-${logid} /tmp/stdout_clean${id}-${logid}
    exit $ret
fi
