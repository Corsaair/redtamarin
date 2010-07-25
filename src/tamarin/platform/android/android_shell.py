#!/usr/bin/env python
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

import os,re,sys,subprocess


# find all connected devices
devices=[]
cmd='adb devices'
p=subprocess.Popen(cmd,shell=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE)
(stdout,stderr)=p.communicate()
for line in stdout.split('\n'):
    tokens=line.split()
    if len(tokens)==2 and tokens[1]=='device':
        devices.append(tokens[0])

if len(sys.argv)==1 or sys.argv[1]=='-Dversion':
    if len(sys.argv)==1:
        arg=""
    else:
        arg=sys.argv[1]
    cmd="adb -s %s shell \"cd /data/app;./avmshell %s\"" % (devices[0],arg)
    p=subprocess.Popen(cmd,shell=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE)
    (stdout,stderr)=p.communicate()
    print(stdout)
    sys.exit(0)

args=""
adbargs=""
if len(devices)>1:
    adbargs="-s %s" % devices[0]
threadid=0
androidid=None
filelist=[]
for arg in sys.argv[1:]:
    if arg.startswith("--threadid="):
        try:
            threadid=int(arg[11:])
        except:
            print(sys.exc_info)
            sys.exit(1)
    elif arg.startswith("--androidid="):
        androidid=arg[12:]
        adbargs="-s %s" % androidid
    elif re.search(".abc",arg):
        flatfile=os.path.basename(arg)
        filelist.append(arg)
        cmd="adb %s push %s /data/app/%s" % (adbargs,arg,flatfile)
        p=subprocess.Popen(cmd,shell=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE)
        p.communicate()
        args+=" %s" % flatfile
    else:
        args+=" %s" % arg


cmd="adb %s shell \"/data/app/android_runner.sh %s\"" % (adbargs,args)
p=subprocess.Popen(cmd,shell=True,stdout=subprocess.PIPE,stderr=subprocess.PIPE)
(stdout,stderr)=p.communicate()
for line in stdout.split('\n'):
    if re.search("EXITCODE=",line):
        exitcode=1
        try:
            exitcode=int(line[line.find("EXITCODE=")+9:])
        except:
            print(sys.exc_info())
        sys.exit(exitcode)
    else:
        print(line)
print("error: stdout did not contain EXITCODE=")
sys.exit(1)
