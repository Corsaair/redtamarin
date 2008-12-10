#!/usr/bin/env python
#
# ***** BEGIN LICENSE BLOCK ***** 
# Version: MPL 1.1/GPL 2.0/LGPL 2.1 
#
# The contents of this file are subject to the Mozilla Public License Version 1.1 (the 
# 'License'); you may not use this file except in compliance with the License. You may obtain 
# a copy of the License at http://www.mozilla.org/MPL/ 
#
# Software distributed under the License is distributed on an 'AS IS' basis, WITHOUT 
# WARRANTY OF ANY KIND, either express or implied. See the License for the specific 
# language governing rights and limitations under the License. 
#
# modified by dschaffe@adobe.com for use with tamarin tests
# original file created by christine@netscape.com
#
# Alternatively, the contents of this file may be used under the terms of either the GNU 
# General Public License Version 2 or later (the 'GPL'), or the GNU Lesser General Public 
# License Version 2.1 or later (the 'LGPL'), in which case the provisions of the GPL or the 
# LGPL are applicable instead of those above. If you wish to allow use of your version of this 
# file only under the terms of either the GPL or the LGPL, and not to allow others to use your 
# version of this file under the terms of the MPL, indicate your decision by deleting provisions 
# above and replace them with the notice and other provisions required by the GPL or the 
# LGPL. If you do not delete the provisions above, a recipient may use your version of this file 
# under the terms of any one of the MPL, the GPL or the LGPL. 
# 
# ***** END LICENSE BLOCK ***** */
#
# simple script that executes tamarin certification tests.  you have to build the
# stand-alone, avmplus executable.  
# see http://developer.mozilla.org/en/docs/Tamarin_Build_Documentation 
#
# this is just a quick-n-dirty script.  for full reporting, you need to run
# the test driver, which requires java and is currently not available on
# mozilla.org.
#
# this test looks for an executable avmplus shell in
# %MOZ_SRC/mozilla/js/tamarin/platform/,
#

import os, os.path, sys, getopt, datetime, pipes, glob, itertools, tempfile, string, re, platform
from os.path import *
from os import getcwd,environ,walk
from datetime import datetime
from glob import glob
from sys import argv, exit
from getopt import getopt
from itertools import count
from subprocess import PIPE,STDOUT
from util.killableprocess import Popen
from time import time


globs = { 'avm':'', 'asc':'', 'builtinabc':'', 'shellabc':'','exclude':[],'config':'',
          'ascargs':'', 'vmargs':'', 'escbin':'', 'rebuildtests':False,
          'pexpect':True}
try:
    import pexpect
except ImportError:
    globs['pexpect'] = False


globs = { 'avm':'', 'asc':'', 'builtinabc':'', 'shellabc':'','exclude':[],'config':'',
          'ascargs':'', 'vmargs':'', 'escbin':'', 'rebuildtests':False,
          'pexpect':True}
try:
    import pexpect
except ImportError:
    globs['pexpect'] = False

verbose = False
timestamps = True
forcerebuild = False
runESC = False
runSource = False # Run the source file (.as, .js) instead of .abc
sourceExt = '.as' # can be changed to .js, .es ...
testTimeOut = -1 #by default tests will NOT timeout
debug = False


# default value for escbin
globs['escbin'] = '../../esc/bin/'

if 'AVM' in environ:
    globs['avm'] = environ['AVM'].strip()
if 'ASC' in environ:
    globs['asc'] = environ['ASC'].strip()
if 'GLOBALABC' in environ:
    globs['builtinabc'] = environ['GLOBALABC'].strip()
if 'BUILTINABC' in environ:
    globs['builtinabc'] = environ['BUILTINABC'].strip()
if 'SHELLABC' in environ:
    globs['shellabc'] = environ['SHELLABC'].strip()
if 'CVS' in environ:
    globs['exclude'] = ['CVS'].strip()
if 'CONFIG' in environ:
    globs['config'] = environ['CONFIG'].strip()
if 'ASCARGS' in environ:
    globs['ascargs'] = environ['ASCARGS'].strip()
if 'VMARGS' in environ:
    globs['vmargs'] = environ['VMARGS'].strip()
if 'ESCBIN' in environ:
    globs['escbin'] = environ['ESCBIN'].strip()

def verbose_print(m, start='', end=''):
    if verbose:
        js_print(m, start, end)

def err_print(m):
    js_print(m, '<font color=#990000>', '</font><br/>')

def js_print(m, start_tag='<p><tt>', end_tag='</tt></p>'):
    print m
    if js_output:
        js_output_f.write('%s %s %s\n' % (start_tag, m, end_tag))
        js_output_f.flush()

# yet another way to specify asc,avm,builtinabc ...from a file
pf = 'runtests.properties'
if os.path.exists(pf):
    verbose_print( 'reading properties from %s' % (pf) )
    fd = open(pf,'r')
    for l in fd:
        setting = l.strip().split('=')
        if l.startswith('#') or len(setting) < 2 or len(setting[1]) <= 0:
            continue
        val = setting[1].strip()
        option = setting[0].split('.')  # see if we have x.y = z
        nm = option[0].strip()
        if len(option) > 1:
            val = globs[nm] + ' ' + val  # concat
        globs[nm] = val
    fd.close()

def usage(c):
    print 'usage: %s [options] [tests]' % basename(argv[0])
    print ' -v --verbose       enable additional output'
    print ' -E --avm           avmplus command to use'
    print ' -a --asc           compiler to use'
    print ' -g --globalabc     DEPRECATED but still works - use builtin.abc (used to be location of global.abc)'
    print ' -b --builtinabc    location of builtin.abc'
    print ' -s --shellabc      location of shell_toplevel.abc'
    print ' -x --exclude       comma separated list of directories to skip'
    print ' -h --help          display help and exit'
    print ' -t --notime        do not generate timestamps (cleaner diffs)'
    print ' -f --forcerebuild  force rebuild all test files'
    print ' -c --config        sets the config string [default OS-tvm]'
    print '    --rebuildtests  rebuild the tests only - do not run against VM'
    print '    --esc           run esc instead of avm'
    print '    --escbin        location of esc/bin directory - defaults to ../../esc/bin'
    print '    --ext           set the testfile extension (defaults to .as)'
    print '    --ascargs       args to pass to asc on rebuild of test files'
    print '    --vmargs        args to pass to vm'
    print '    --timeout       max time to let a test run, in sec (default -1 = never timeout)'
    exit(c)

try:
    opts, args = getopt(argv[1:], 'vE:a:g:b:s:x:htfc:d', ['verbose','avm=','asc=','globalabc=','builtinabc=','shellabc=',
                'exclude=','help','notime','forcerebuild','config=','ascargs=','vmargs=',
                'ext=','timeout=','esc','escbin=', 'rebuildtests'])
except:
    usage(2)

if not args:
    args = ['.']
for o, v in opts:
    if o in ('-v', '--verbose'):
        verbose = True
    elif o in ('-h', '--help'):
        usage(0)
    elif o in ('-E', '--avm'):
        globs['avm'] = v
    elif o in ('-a', '--asc'):
        globs['asc'] = v
    elif o in ('-g', '--globalabc'):
        globs['builtinabc'] = v
    elif o in ('-b', '--builtinabc'):
        globs['builtinabc'] = v
    elif o in ('-s', '--shellabc'):
        globs['shellabc'] = v
    elif o in ('-x', '--exclude'):
        globs['exclude'] += v.split(',')
    elif o in ('-t', '--notime'):
        timestamps = False
    elif o in ('-f', '--forcerebuild'):
        forcerebuild = True
    elif o in ('-c', '--config'):
        globs['config'] = v
    elif o in ('--ascargs'):
        globs['ascargs'] = v
    elif o in ('--vmargs'):
        globs['vmargs'] = v
    elif o in ('--ext'):
        sourceExt = v
    elif o in ('--timeout'):
        testTimeOut=int(v)
    elif o in ('--esc'):
        runESC = True
    elif o in ('--escbin'):
        globs['escbin'] = v
    elif o in ('-d'):
        debug = True
    elif o in ('--rebuildtests'):
        globs['rebuildtests'] = True

exclude = globs['exclude']

def istest(f):
    return f.endswith(sourceExt) and basename(f) != ('shell'+sourceExt) and not f.endswith('Util'+sourceExt)

tests = [a for a in args if isfile(a) and istest(a)]
for a in [d for d in args if isdir(d) and not (basename(d) in exclude)]:
    for d, dirs, files in walk(a):
        tests += [join(d,f) for f in files if istest(f)]
        utils = [d for d in dirs if d+sourceExt in files]
        for x in [x for x in exclude+utils if x in dirs]:
            dirs.remove(x)

# set the output file name.  let's base its name on the date and platform,
# and give it a sequence number.

now = datetime.today()
for i in count(1):
    js_output = '%d-%s-%s.%d.html' % (now.year, str(now.month).zfill(2), str(now.day).zfill(2), i)
    if not isfile(js_output):
        break

print 'Writing results to %s' % js_output
js_output_f = open(js_output, 'w')

def verbose_print(m, start='', end=''):
  if verbose:
    js_print(m, start, end)

def err_print(m):
    js_print(m, '<font color=#990000>', '</font><br/>')

def js_print(m, start_tag='<p><tt>', end_tag='</tt></p>'):
    print m
    if js_output:
        js_output_f.write('%s %s %s\n' % (start_tag, m, end_tag))
        js_output_f.flush()

if timestamps:
    # get the start time
    start_time = datetime.today()
    js_print('Tamarin tests started: %s' % start_time)
#
# run the tests
#

allpasses=0
allfails=0
allunpass=0
allexpfails=0
allexceptions=0
allskips=0
alltimeouts=0
allasserts=0
failmsgs=[]
expfailmsgs=[]
unpassmsgs=[]
timeoutmsgs=[]
assertmsgs=[]

#setup absolute path of base dir to not have parents go beyond that
absArgPath = abspath(args[0])

def parents(d):
    while d != absArgPath and d != '':
        yield d
        d = dirname(d)
    yield d

# run a command and return its output
def run_pipe(cmd):
    if debug:
        print('cmd: %s' % cmd)
    p = Popen((cmd), shell=True, stdout=PIPE, stderr=STDOUT)
    output = p.stdout.readlines()
    starttime=time()
    exitCode = p.wait(testTimeOut) #abort if it takes longer than 60 seconds
    if exitCode < 0 and testTimeOut>-1 and time()-starttime>testTimeOut:  # process timed out
        return 'timedOut'
    return output
  
def list_match(list,test):
    for k in list:
        if re.search(k,test):
            return True
    return False
  
def dict_match(dict,test,value):
    for k in dict.keys():
        if re.search(k,test):
            if dict[k].has_key(value):
                return dict[k][value]

def parseArgStringToList(argStr):
    args = argStr.strip().split(' ')
    # recombine any args that have spaces in them
    argList = []
    for a in args:
        if a == '':
            pass
        elif a[0] == '-':
            argList.append(a)
        else:   # append the space and text to the last arg
            argList[len(argList)-1] += ' ' + a
    return argList

def parseAscArgs(ascArgFile, currentdir):
    # reads an .asc_args file and returns a tuple of the arg mode (override or merge) and a list of args
    f = open(ascArgFile,'r')
    while True: # skip comment lines
        ascargs = f.readline()
        if (ascargs[0] != '#'):
            break
    ascargs = ascargs.split(':')
    ascargs[0] = ascargs[0].strip()
    if (len(ascargs) == 1): #treat no keyword as a merge
        ascargs.insert(0,'merge')
    elif (ascargs[0] != 'override') or (ascargs[0] != 'merge'): # default to merge if mode not recognized
        ascargs[0] = 'merge'
    # replace the $DIR keyword with actual directory
    ascargs[1] = string.replace(ascargs[1], '$DIR', currentdir)
    if ascargs[1].find('$SHELLABC') != -1:  
        if not isfile(globs['shellabc']):   # TODO: not the best place to check for this
            exit('ERROR: shell.abc %s does not exist, SHELLABC environment variable or --shellabc must be set to shell_toplevel.abc' % globs['shellabc'])
        ascargs[1] = string.replace(ascargs[1], '$SHELLABC', globs['shellabc'])
    ascargs[1] = parseArgStringToList(ascargs[1])
    removeArgList = []
    argList = []
    for a in ascargs[1]:
        if a[0:3] == '-no':
            removeArgList.append(a[3:])
        else:
            argList.append(a)

    return ascargs[0], argList, removeArgList
    
def loadAscArgs(arglist,dir,file):
    # It is possible that file is actually a partial path rooted to acceptance,
    # so make sure that we are only dealing with the actual filename
    file = split(file)[1]
    mode = ''
    newArgList = []
    removeArgList = []
    # Loads an asc_args file and modifies arglist accordingly
    if file and isfile('%s/%s.asc_args' % (dir, file)):  #file takes precendence over directory
        mode, newArgList, removeArgList = parseAscArgs('%s/%s.asc_args' % (dir, file), dir)
    elif isfile(dir+'/dir.asc_args'):
        mode, newArgList, removeArgList = parseAscArgs(dir+'/dir.asc_args', dir)
    elif isfile('./dir.asc_args'):
        mode, newArgList, removeArgList = parseAscArgs('./dir.asc_args', './')
    
    if mode == 'merge':
        arglist.extend(newArgList)
    elif mode == 'override':
        arglist = newArgList
    # remove any duplicate args
    arglist = list(set(arglist))
    if removeArgList:
        for removeArg in removeArgList:
            try:
                arglist.remove(removeArg)
            except:
                pass

    
def compile_test(as_file):
    asc, builtinabc, shellabc, ascargs = globs['asc'], globs['builtinabc'], globs['shellabc'], globs['ascargs']
    if not isfile(asc):
        exit('ERROR: cannot build %s, ASC environment variable or --asc must be set to asc.jar' % as_file)
    if not isfile(builtinabc):
        exit('ERROR: builtin.abc (formerly global.abc) %s does not exist, BUILTINABC environment variable or --builtinabc must be set to builtin.abc' % builtinabc)

    if asc.endswith('.jar'):
        cmd = 'java -jar ' + asc
    else:
        cmd = asc
    
    arglist = parseArgStringToList(ascargs)

    (dir, file) = split(as_file)
    # look for .asc_args files to specify dir / file level compile args, arglist is passed by ref
    loadAscArgs(arglist, dir, as_file)
    
    cmd += ' -import %s' % builtinabc
    for arg in arglist:
        cmd += ' %s' % arg
    verbose_print('   compiling %s' % file)
    for p in parents(dir):
        shell = join(p,'shell'+sourceExt)
        if isfile(shell):
            cmd += ' -in ' + shell
            break
    (testdir, ext) = splitext(as_file)
    deps = glob(join(testdir,'*'+sourceExt))
    deps.sort()
    for util in deps + glob(join(dir,'*Util'+sourceExt)):
        cmd += ' -in %s' % string.replace(util, '$', '\$')
    try:
        f = run_pipe('%s %s' % (cmd,as_file))
        for line in f:
            verbose_print(line.strip())
    except:
        print 'Exception'

def compileWithAsh(tests):
    start_time = datetime.today()
    print("starting compile of %d tests at %s" % (len(tests),start_time))
    total=len(tests)
    counter=0
    if not globs['pexpect']:
        for test in tests:
            print 'compiling %s' % test
            compile_test(test)
            (testdir, ext) = splitext(test)
            if exists(testdir+".abc")==False:
                print("ERROR abc files %s.abc not created" % (testdir))
            counter += 1;
            print("%d remaining" % (total-counter))
    else:  #pexpect available
        child = pexpect.spawn("java -classpath %s macromedia.asc.embedding.Shell" % globs['asc'])
        child.logfile = sys.stdout
        child.expect("\(ash\)")
        child.expect("\(ash\)")

        for test in tests:
            arglist = parseArgStringToList(globs['ascargs'])
        
            (dir, file) = split(test)
            # look for .asc_args files to specify dir / file level compile args
            loadAscArgs(arglist, dir, file)
            
            cmd = "asc -import %s " % (globs['builtinabc'])
            for arg in arglist:
                cmd += ' %s' % arg
            
            for p in parents(dir):
                shell = join(p,"shell.as")
                if isfile(shell):
                    cmd += " -in " + shell
                    break
            (testdir, ext) = splitext(test)
            deps = glob(join(testdir,"*.as"))
            deps.sort()
            for util in deps + glob(join(dir,"*Util.as")):
                cmd += " -in %s" % string.replace(util, "$", "\$")
            cmd += " %s" % test
        
            if exists(testdir+".abc"):
                os.unlink(testdir+".abc")
        
            child.sendline(cmd)
            child.expect("\(ash\)")
            if exists(testdir+".abc")==False:
                print("ERROR abc files %s.abc not created" % (testdir))
            counter += 1;
            print("%d remaining, %s" % (total-counter,cmd))
    end_time = datetime.today()
    print("finished compile of %d tests at %s elapsed time is %s" % (len(tests),start_time,end_time-start_time))

def fail(abc, msg, failmsgs):
    msg = msg.strip()
    err_print('   %s' % msg)
    failmsgs += ['%s : %s' % (abc, msg)]

vmargs = globs['vmargs']
avm = globs['avm']

if (not globs['rebuildtests']) and (not avm): #don't need AVM if rebuilding tests
    exit('ERROR: cannot run %s, AVM environment variable or --avm must be set to avmplus' % avm)
    
js_print('Executing %d tests against vm: %s' % (len(tests), avm));

# Are we running esc - depends on a valid avm
if runESC:
    runSource = True
    # generate the executable cmd for esc
    #escAbcs = [f for f in os.listdir(globs['escbin']) if f.endswith('.abc')] #not all abcs are used for esc
    escAbcs = ['debug','util','bytes-tamarin','util-tamarin','lex-char','lex-token',
               'lex-scan','ast','ast-decode','parse','asm','abc','emit','cogen',
               'cogen-stmt','cogen-expr','esc-core','eval-support','esc-env','main']
    if not globs['escbin'].endswith('/'):
        globs['escbin'] += '/'
    for f in escAbcs:
        avm += ' %s%s.es.abc' % (globs['escbin'], f)
    avm += ' -- '
    avm += ' %s../test/spidermonkey-prefix.es' % globs['escbin']  #needed to run shell harness


def build_incfiles(as_file):
    files=[]
    (dir, file) = split(as_file)
    for p in parents(dir):
        shell = join(p,'shell'+sourceExt)
        if isfile(shell):
            files.append(shell)
    (testdir, ext) = splitext(as_file)
    for util in glob(join(testdir,'*'+sourceExt)) + glob(join(dir,'*Util'+sourceExt)):
        files.append(string.replace(util, "$", "\$"))
    return files



if globs['config'] == '':
    if not runSource:
        vmtype = 'release'
        f = run_pipe('%s' % avm)
        try:
            for line in f:
                if line.find('[-d]') != -1:
                    vmtype = 'releasedebugger'
                    break
        except:
            nop = True
      
    # ================================================
    # Determine the configruation if it has not been 
    # passed into the script:
    # {CPU_ARCH}-{OS}-{VM}-{VERSION}-{VMSWITCH}
    # ================================================
    try:
        ostype={'CYGWIN_NT-5.1':'win','CYGWIN_NT-5.2':'win','CYGWIN_NT-5.2-WOW64':'win64','CYGWIN_NT-6.0-WOW64':'win64','Windows':'win','Darwin':'mac','Linux':'lnx','SunOS':'sol',}[platform.system()]
    except:
        print("ERROR: os %s is unknown, expected values are (win,mac,lnx,sol), use runtests.py --config x86-win-tvm-release to manually set the configuration" % (platform.system()))
        exit(1)
    try:
        cputype={'i386':'x86','i686':'x86','i86pc':'x86','Power Macintosh':'ppc','sun4u':'x86','':'x86'}[platform.machine()]
    except:
        print("ERROR: cpu_arch '%s' is unknown, expected values are (x86,ppc), use runtests.py --config x86-win-tvm-release to manually set the configuration" % (platform.machine()))
        exit(1)
    globs['config'] = cputype+'-'+ostype+'-tvm-'+vmtype+vmargs
    
  
js_print('current configuration: %s' % globs['config'])


testnum = len(tests)
if globs['rebuildtests']:
    compileWithAsh(tests)
else:
    for ast in tests:
        if ast.startswith('./'):
            ast=ast[2:]
        testnum -= 1
        lpass = 0
        lfail = 0
        lexpfail = 0
        lunpass = 0
        ltimeout = 0
        lassert = 0
        dir = ast[0:ast.rfind('/')]
        root,ext = splitext(ast)
        if runSource:
            testName = ast
        else:
            testName = root + '.abc'
        settings=dict()
        names=None
        lines=[]
        includes=None
        if isfile(dir+'/testconfig.txt'):
            lines=open(dir+'/testconfig.txt').read().splitlines()
            for i in range(len(lines)):
                if not lines[i].startswith('#'):
                    lines[i] = '%s/%s' %(dir,lines[i])
        if isfile('./testconfig.txt'):
            for line in open('./testconfig.txt').read().splitlines():
                lines.append(line)
        for line in lines:
            if line.startswith('#') or len(line)==0:
                continue
            fields = line.split(',')
            for f in range(len(fields)):
                fields[f]=fields[f].strip()
            while len(fields)<4:
                fields.append('');
            names=fields[0].split(':')
            if len(names)==1:
                names.append('.*')
            rs='^%s$' % names[0]
            if re.search(fields[1],globs['config']) and fields[2]=='include':
                if includes==None:
                    includes=[]
                includes.append(fields[0])
            if re.search(rs,root) and re.search('^%s$' % fields[1],globs['config']):
                if not settings.has_key(names[1]):
                    settings[names[1]]={}
                settings[names[1]][fields[2]]=fields[3]
        if includes and not list_match(includes,root):
            continue
        js_print('%d running %s' % (testnum, ast), '<b>', '</b><br/>');
        if names and dict_match(settings,names[1],'skip'):
            js_print('  skipping')
            allskips += 1
            continue
        if forcerebuild and isfile(testName):
            os.unlink(testName)
        # load any asc_args files
        
        
        if not isfile(testName):
            compile_test(ast)
            if not isfile(testName):
                lfail += 1
                fail(testName, 'FAILED! file not found ' + testName, failmsgs)
        if runSource:
            incfiles=build_incfiles(testName)
            for incfile in incfiles:
                testName=incfile+" "+testName
                
        if isfile("%s.avm_args" % ast):
            testName = " %s %s" % (string.replace(open("%s.avm_args" % ast).readline(), "$DIR", dir), testName)
        
        f = run_pipe('%s %s %s' % (avm, vmargs, testName))
        if f == "timedOut":
            fail(testName, 'FAILED! Test Timed Out! Time out is set to %s s' % testTimeOut, timeoutmsgs)
            ltimeout += 1
        else:
            try:
                outputLines = []
                for line in f:
                    outputLines.append(line)
                    verbose_print(line.strip())
                    if 'Assertion failed:' in line:
                        lassert += 1
                        fail(testName, line, assertmsgs)
                    testcase=''
                    if len(line)>9:
                        testcase=line.strip()
                    if dict_match(settings,testcase,'skip'):
                        js_print('  skipping %s' % line.strip())
                        allskips+=1
                        continue
                    if 'PASSED!' in line:
                        res=dict_match(settings,testcase,'expectedfail')
                        if res:
                            fail(testName, 'unexpected pass: ' + line.strip() + ' reason: '+res, unpassmsgs)
                            lunpass += 1
                        else:
                            lpass += 1
                    if 'FAILED!' in line:
                        res=dict_match(settings,testcase,'expectedfail')
                        if res:
                            fail(testName, 'expected failure: ' + line.strip() + ' reason: '+res, expfailmsgs)
                            lexpfail += 1
                        else:
                            lfail += 1
                            fail(testName, line, failmsgs)
            except:
                print 'exception running avm'
                exit(-1)
            if lpass == 0 and lfail == 0 and lunpass==0 and lexpfail==0:
                res=dict_match(settings,'*','expectedfail')
                if res:
                    fail(testName, 'expected failure: FAILED contained no testcase messages reason: %s' % res,expfailmsgs)
                    lexpfail += 1
                else:
                    lfail = 1
                    fail(testName, '   FAILED contained no testcase messages - reason: %s' % string.join([l.strip() for l in outputLines], ' | '), failmsgs)
        
            allfails += lfail
            allpasses += lpass
            allexpfails += lexpfail
            allunpass += lunpass
            alltimeouts += ltimeout
            allasserts += lassert
            if lfail or lunpass:
                js_print('   FAILED passes:%d fails:%d unexpected passes: %d expected failures: %d' % (lpass,lfail,lunpass,lexpfail), '', '<br/>')
            else:
                js_print('   PASSED passes:%d fails:%d unexpected passes: %d expected failures: %d' % (lpass,lfail,lunpass,lexpfail), '', '<br/>')
    
    #
    # cleanup
    #
    
    if timeoutmsgs:
        js_print('\nTIMEOUTS:', '', '<br/>')
        for m in timeoutmsgs:
            js_print('  %s' % m, '', '<br/>')
    
    if failmsgs:
        js_print('\nFAILURES:', '', '<br/>')
        for m in failmsgs:
            js_print('  %s' % m, '', '<br/>')
    
    if expfailmsgs:
        js_print('\nEXPECTED FAILURES:', '', '<br/>')
        for m in expfailmsgs:
            js_print('  %s' % m, '', '<br/>')
    
    if unpassmsgs:
        js_print('\nUNEXPECTED PASSES:', '', '<br/>')
        for m in unpassmsgs:
            js_print('  %s' % m, '', '<br/>')

    if assertmsgs:
        js_print('\nASSERTIONS:', '', '<br/>')
        for m in assertmsgs:
            js_print('  %s' % m, '', '<br/>')
    
    if not allfails and not allunpass:
        js_print('\ntest run PASSED!')
    else:
        js_print('\ntest run FAILED!')
    
    if timestamps:
        end_time = datetime.today()
        js_print('Tests complete at %s' % end_time, '<hr><tt>', '</tt>')
        js_print('Start Date: %s' % start_time, '<tt><br>', '')
        js_print('End Date  : %s' % end_time, '<br>', '')
        js_print('Test Time : %s' % (end_time-start_time), '<br>', '')
    js_print('passes               : %d' % allpasses, '<br>', '')
    js_print('failures             : %d' % allfails, '<br>', '')
    if allunpass>0:
        js_print('unexpected passes    : %d' % allunpass, '<br>', '')
    if allexpfails>0:
        js_print('expected failures    : %d' % allexpfails, '<br>', '')
    if allskips>0:
        js_print('tests skipped        : %d' % allskips, '<br>', '')
    if allexceptions>0:
        js_print('test exceptions      : %d' % allexceptions, '<br>', '')
    if alltimeouts>0:
        js_print('test timeouts        : %d' % alltimeouts, '<br>', '')
    if allasserts>0:
        js_print('assertions           : %d' % allasserts, '<br>', '')
        
    
    print 'Results were written to %s' % js_output

