#!/usr/bin/env python
# -*- Mode: Python; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*-
# vi: set ts=4 sw=4 expandtab:

# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

import os
import shutil
import stat
import sys

def mv(oldfile, newfile):
    shutil.copyfile(oldfile,newfile)
    os.remove(oldfile)

def rm(file):
    if os.access(file, os.F_OK) == True:
        os.remove(file)

def warn_notwriteable(file):
    if os.path.exists(file) and not os.stat(file).st_mode & stat.S_IWUSR:
        print("warning: %s is not writeable" % file)
        return True
    return False

classpath = os.environ.get('ASC')
if classpath == None:
    classpath = "utils/asc.jar"
    print "ERROR: ASC environment variable must point to asc.jar"
    exit(1)

javacmd = "java -ea -DAS3 -DAVMPLUS -classpath "+classpath
asc = javacmd+" macromedia.asc.embedding.ScriptCompiler "

print("ASC="+classpath)
print("Building redtamarin...")

configs = "-config CONFIG::VMCFG_FLOAT=false -config AVMGLUE::REDTAMARIN=true"

builtin = "core/builtin.as core/Math.as core/Error.as core/flash_errors_classes.as core/Date.as core/RegExp.as core/JSON.as core/XML.as core/IDataInput.as core/IDataOutput.as core/ByteArray.as core/Proxy.as core/flash_net_classes.as core/Dictionary.as core/IDynamicPropertyOutput.as core/IDynamicPropertyWriter.as core/DynamicPropertyOutput.as core/ObjectInput.as core/ObjectOutput.as core/IExternalizable.as core/ObjectEncoding.as core/concurrent.as core/PromiseChannel.as"

redtamarin = " redtamarin.as"

os.system(asc + " -builtin -apiversioning " + configs + " -out redtamarin " + builtin + redtamarin )

rm("redtamarin.h")
rm("redtamarin.cpp")

print("Done.")
