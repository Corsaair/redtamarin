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

'''
Act as a proxy for calls the adb. During automated testing we have
seen the adb process hang and not return for no apparet reason. Subsequent
calls of the exact same adb command to the same device will suceed. The
purpose of this is to handle all calls to adb, kill the adb call if the
execution time takes long than a specififed number of seconds and repeat
the call a specified number of times.
'''


import os,re,sys,subprocess,killableprocess,datetime,tempfile


def main(argv=None):
    if argv is None:
        argv = sys.argv[1:] # don't include the script name

    ADB_TIMEOUT=os.getenv('ADB_TIMEOUT', 120)
    ADB_MAX_ATTEMPTS=os.getenv('ADB_MAX_ATTEMPTS', 2)
    attempt=0

    args=""
    for arg in argv:
        args+=" %s" % arg


    cmd="adb %s" % (args)
    #print "cmd: %s" % cmd
    while attempt < ADB_MAX_ATTEMPTS:

        attempt=attempt+1
        # Need to call the subprocess using a file object for stdout. There have been
        # problems with the OS blocking when large amounts of data is being returned
        # in stdout when making the call to adb. Poth processes must be buffering and
        # causing the process to become blocked.
        f = tempfile.NamedTemporaryFile(delete=False)
        p=killableprocess.Popen(cmd, shell=True, stdout=f ,stderr=subprocess.PIPE)
        try:
            p.wait(ADB_TIMEOUT)
        except OSError:
            '''
            We have seen the following error happen in the build system, so guard against
            this error and just treat like a timeout and retry the call
                "killableprocess.py", line 177, in kill
                    os.killpg(self.pid, signal.SIGKILL)
                    OSError: [Errno 3] No such process
            '''
            p.returncode = 127
        f.flush()
        f.close()

        # -9 and 127 are returned by killableprocess when a timeout happens
        if  p.returncode == -9 or p.returncode == 127:
            failure=file('/tmp/adb_failures', 'a')
            failure.write('%s, %s, %s\n' % (datetime.datetime.now(), attempt, cmd))
            failure.flush()
            failure.close()
            continue

        stdout=""
        outfile = open(f.name, 'r')
        for line in outfile:
            stdout+=line
        outfile.close()
        os.unlink(f.name)
        return stdout

if __name__ == "__main__":
    print main()



