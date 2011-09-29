#!/usr/bin/env python
# -*- Mode: Python; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*-
# vi: set ts=4 sw=4 expandtab:

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
# Portions created by the Initial Developer are Copyright (C) 2004-2006
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
# ***** END LICENSE BLOCK *****

import os
import shutil
import sys

classpath = os.environ.get('ASC')
if classpath == None:
    classpath = "../utils/asc.jar"
    #print "ERROR: ASC environment variable must point to asc.jar"
    #exit(1)

def mv(oldfile, newfile):
    shutil.copyfile(oldfile,newfile)
    os.remove(oldfile)

def rm(file):
    os.remove(file)

javacmd = "java -ea -DAS3 -DAVMPLUS -classpath "+classpath
asc = javacmd+" macromedia.asc.embedding.ScriptCompiler "

print("ASC="+classpath)
print("Building shell_toplevel...")

configs = ""

classes  = ""

classes += " Domain.as"
classes += " shell_toplevel.as"
classes += " ../extensions/Sampler.as"
classes += " ../extensions/Trace.as"
classes += " ../extensions/Dictionary.as"

# redtamarin API
classes += " ../as3/clib/C/stdlib.as"
classes += " ../as3/clib/C/unistd.as"
classes += " ../as3/clib/C/string.as"
classes += " ../as3/clib/C/errno.as"
classes += " ../as3/clib/C/stdio.as"
classes += " ../as3/clib/C/socket.as"
classes += " ../as3/shell/avmplus/profiles/Profile.as"
classes += " ../as3/shell/avmplus/profiles/TamarinProfile.as"
classes += " ../as3/shell/avmplus/profiles/RedTamarinProfile.as"
classes += " ../as3/shell/avmplus/profiles/FlashPlayerProfile.as"
classes += " ../as3/shell/avmplus/profiles/AIRProfile.as"
classes += " ../as3/shell/avmplus/profiles/DesktopProfile.as"
classes += " ../as3/shell/avmplus/profiles/ExtendedDesktopProfile.as"
classes += " ../as3/shell/avmplus/profiles/MobileDeviceProfile.as"
classes += " ../as3/shell/avmplus/profiles/TVProfile.as"
classes += " ../as3/shell/avmplus/profiles/ExtendedTVProfile.as"
classes += " ../as3/shell/avmplus/System.as"
classes += " ../as3/shell/avmplus/OperatingSystem.as"
classes += " ../as3/shell/avmplus/FileSystem.as"
classes += " ../as3/shell/avmplus/Socket.as"
classes += " ../as3/shell/avmplus/StandardStream.as"
classes += " ../as3/shell/avmplus/StandardStreamOut.as"
classes += " ../as3/shell/avmplus/StandardStreamErr.as"
classes += " ../as3/shell/avmplus/StandardStreamIn.as"
classes += " ../as3/avmglue/flash/utils/flash_proxy.as"
classes += " ../as3/avmglue/flash/utils/IExternalizable.as"
classes += " ../as3/avmglue/flash/utils/CompressionAlgorithm.as"
classes += " ../as3/avmglue/flash/utils/describeType.as"
classes += " ../as3/avmglue/flash/utils/getDefinitionByName.as"
classes += " ../as3/avmglue/flash/utils/getQualifiedClassName.as"
classes += " ../as3/avmglue/flash/utils/getQualifiedSuperclassName.as"
classes += " ../as3/avmglue/flash/utils/getTimer.as"
classes += ""

classes += " Endian.as"
classes += " Java.as"

# compile builtins
# os.system(asc+" -abcfuture -import ../core/builtin.abc -builtin "+configs+"-apiversioning -out shell_toplevel shell_toplevel.as Domain.as ../extensions/Sampler.as ../extensions/Trace.as ../extensions/Dictionary.as Endian.as Java.as")

os.system(asc+" -abcfuture -import ../core/builtin.abc -builtin "+configs+"-apiversioning -out shell_toplevel"+classes)


print("Generating native thunks...")
os.system("python ../utils/nativegen.py ../core/builtin.abc shell_toplevel.abc")

mv("shell_toplevel.cpp2", "shell_toplevel.cpp")
mv("shell_toplevel.h2", "shell_toplevel.h")

print("Done.")
