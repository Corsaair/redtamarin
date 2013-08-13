#!/bin/bash
#  This Source Code Form is subject to the terms of the Mozilla Public
#  License, v. 2.0. If a copy of the MPL was not distributed with this
#  file, You can obtain one at http://mozilla.org/MPL/2.0/.
(set -o igncr) 2>/dev/null && set -o igncr; # comment is needed

##
# Set any variables that my be needed higher up the chain
##
export shell_extension=

##
# Bring in the BRANCH environment variables
##
. ../all/environment.sh

export platform=linux

export shell_release=${shell_release}_64
export shell_release_wordcode=${shell_release_wordcode}_64
export shell_debug=${shell_debug}_64
export shell_release_debugger=${shell_release_debugger}_64
export shell_debug_debugger=${shell_debug_debugger}_64
export shell_selftest=${shell_selftest}_64

# List of processes that should NEVER be running when the build is not
# currently running any tests. This list of process will be killed if the
# process is found. Process must not contain extension as cygwin will return
# the process without the extension. Used in all/util-process-clean.sh
export proc_names="avmshell.*_64$"
