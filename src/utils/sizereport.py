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
# The Original Code is [Open Source Virtual Machine].
#
# The Initial Developer of the Original Code is
# Adobe System Incorporated.
# Portions created by the Initial Developer are Copyright (C) 2008
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

import subprocess,sys,datetime
from os import environ
from glob import glob
from getopt import getopt
from os.path import basename,exists
from platform import system
from socket import *

file="../objdir-release/shell/avmshell.map"
#file="../platform/win32/obj_9/shell/Release/avmplus.map"
if 'MAPFILE' in environ:
    file=environ['MAPFILE'].strip()

globs = {'sizereport':'./sizereport', 'file': file, 'prefix':'', 'socketlog':False,'config':'unknown','verbose':False,'version':'unknown','serverHost':'10.60.48.47','serverPort':1188 }

def usage(c):
    print "usage: %s [options]" % basename(sys.argv[0])
    print " -m --map        specify map file to parse"
    print " -d --socketlog  log results to socketserver"
    print " -p --prefix     prefix for output line"
    print " --vmversion     version of vm for socket log"
    print " --config        configuration string for socket log"
    print " --verbose       enable verbose messages"
    exit(c)

def runSizeReport():
    p=subprocess.Popen(args=[globs['sizereport'],globs['file']], shell=False, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    (out,err)=p.communicate()
    exitcode=p.returncode
    if globs['verbose']:
        print 'finished running sizereport exit code=%d' % exitcode
	print 'output=%s' % out
    return (exitcode,out)

def printResult(out):
    print "%s SizeReport " % globs['prefix']
    for line in out.split('\n'):
        tokens=line.split()
        if len(tokens)>2:
            print "%s %-7s %-10s %-5s" % (globs['prefix'],tokens[0],tokens[1],tokens[2])

def saveResult(out):
    out="version: %s\n%s" % (globs['version'],out)
    open('lastsizereport.txt','w').writelines(out)

def printResultDiff(out):
    lastlines=open('lastsizereport.txt','r').readlines()
    lastdata={}
    for line in lastlines:
        tokens=line.split()
        if len(tokens)==2:
            print "curr version: %s\nprev version: %s" % (globs['version'],tokens[1])
        elif len(tokens)>2:
            lastdata[tokens[1]]=int(tokens[0])
    print "%-8s %-6s %-5s %-6s" % ('name','size','chg','percent')
    for line in out.split('\n'):
        tokens=line.split()
        if len(tokens)>1:
            if lastdata.has_key(tokens[1]):
                diff=int(tokens[0])-lastdata[tokens[1]]
                if diff>0:
                    res="+%s" % diff
                else:
                    res="%s" % diff
            else:
                res='n/a'
            print "%-8s %-6s %-5s %-6s" % (tokens[1],convertK(tokens[0]),res,tokens[2])

def printResultDiffSummary(out):                
    lastlines=open('lastsizereport.txt','r').readlines()
    lastdata={}
    for line in lastlines:
        tokens=line.split()
        if len(tokens)==2:
            print "%s curr version: %s\n%s prev version: %s" % (globs['prefix'],globs['version'],globs['prefix'],tokens[1])
        elif len(tokens)>2:
            lastdata[tokens[1]]=int(tokens[0])
    print "%s %-8s %-6s %s" % (globs['prefix'],"name","size","change")
    for line in out.split('\n'):
        tokens=line.split()
        if len(tokens)>1:
            if lastdata.has_key(tokens[1]):
                diff=int(tokens[0])-lastdata[tokens[1]]
                if diff==0:
                    print "%s %-8s %-6s nochange" % (globs['prefix'],tokens[1],convertK(tokens[0]))
                else:
                    if diff>0:
                        res="+%s" % convertK(diff)
                    else:
                        res="%s" % convertK(diff)
                    print "%s %-8s %-6s %s" % (globs['prefix'],tokens[1],convertK(tokens[0]),res)
            else:
                print "%s %-8s %-6s" % (globs['prefix'],tokens[1],convertK(tokens[0]))

def convertK(val):
    if abs(int(val))>1024:
        return "%dK" % (int(val)/1024)
    return val
                
def logResult(out):
    os = {'CYGWIN_NT-5.1':'WIN','CYGWIN_NT-5.2':'WIN','CYGWIN_NT-6.0-WOW64':'WIN','Windows':'WIN','Darwin':'MAC','Linux':'LNX','Solaris':'SOL','SunOS':'SOL',}[system()]
    msg=''
    date=datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    # for consistency in the performance report, pretend result came from windows performance host
    ip='10.60.147.246';
    for line in out.split('\n'):
        fields=line.split()
        if len(fields)>1:
            msg+='addresult2::sizereport/%s::memory::%s::0::%s::1::%s::%s::%s::%s::%s;' % (fields[1],fields[0],fields[0],os,globs['config'],globs['version'],date,ip)
    msg+='exit;'
    if globs['verbose']:
        print('sending result to socket server: %s' % msg)
    s = socket(AF_INET, SOCK_STREAM)    # create a TCP socket
    s.connect((globs['serverHost'], globs['serverPort'])) # connect to server on the port
    s.send("%s;exit\r\n" % msg)         # send the data
    data = s.recv(1024)
    s.close()
    print('finished sending results to socket server')

try:
    opts, args = getopt(sys.argv[1:], "m:dp:h",["map=","prefix=","config=","vmversion=","help","verbose","socketlog"])
except:
    usage(2)

if not args:
    args=["."]
for o,v in opts:
    if o in ("-m","--map"):
        globs['file']=v
    elif o in ("-p","--prefix"):
        globs['prefix']=v
    elif o in ("--vmversion"):
        globs['version']=v
    elif o in ("--config"):
        globs['config']=v
    elif o in ("-d","--socketlog"):
        globs['socketlog']=True
    elif o in ("--verbose"):
        globs['verbose']=True
    else:
        usage(2)

(exitcode,out)=runSizeReport()
if exitcode!=0:
    print "error bad exit code %d" % exitcode
    sys.exit(1)
if exists('lastsizereport.txt'):
    printResultDiff(out)
    if globs['prefix']!='':
        printResultDiffSummary(out)
else:
    printResult(out)
saveResult(out)
if globs['socketlog']:
    logResult(out)
