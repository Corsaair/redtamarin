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

avm = os.environ.get('AVM')
if avm == None:
    print "ERROR: AVM environment variable must point to avm executable"
    exit(1)

classpath = os.environ.get('ASC')
if classpath == None:
    classpath = "../utils/asc.jar"

asfile = "../utils/exactgc.as"
abcfile = "../utils/exactgc.abc"

# TODO: Would be useful to conditionally compile here, if the abc does
# not exist or if the source is newer than the abc.  os.path.exists()
# and os.path.getmtime() can handle that.

print("Compiling exactgc script...")
if os.path.exists(abcfile):
    os.remove(abcfile)
os.system("java -jar " + classpath + " -import ../core/builtin.abc -import ../shell/shell_toplevel.abc -debug " + asfile)

# TODO: Would be useful to overwrite the output file only if the
# output file does not exist or if it has not changed.
# os.path.exists(), shutil.move(), os.remove(), and filecmp.cmp() will
# be handy.

# This is a mess, since DomainClass.{cpp,h} is in the avmplus namespace but the
# files reside with avmshell files.
print("Generating gcTrace methods...")
os.system(avm+" "+abcfile+" -- -ns avmshell -b avmshell-as3-gc.h -n avmshell-cpp-gc.h -i avmshell-gc-interlock.h shell_toplevel.as DebugCLI.h ShellCore.h SystemClass.h")
os.system(avm+" "+abcfile+" -- -b extensions-as3-gc.h -n extensions-cpp-gc.h -i extensions-gc-interlock.h DomainClass.h Domain.as ../extensions/*.h ../extensions/*.as")

print("Done.")
