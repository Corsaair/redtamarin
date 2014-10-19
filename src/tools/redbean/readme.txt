redbean
=======

build tool for RedTamarin projects

here a list of basic functionalities

- compile()
  compile AS3 source code as ABC file

- shell()
  execute ABC file(s)

- projector()
  create executable projectors from ABC file(s)

- generateIncludes()
  generate the include files(s) from your AS3 sources tree


Usage
-----
redbean -- [-h] [-i] [-e] [-q] [-v] [-dd] [-f buildfile]

Options:
  -h              display this help
  -i              display informations
  -e              display environment variables
  -q              quiet mode
  -v              verbose mode
  -dd             use debug debugger
  -f buildfile    run buildfile

Example:

#to build with mybuild.as3
$ ./redbean -- -f mybuild.as3

#display informations
$ ./redbean -- -i


Installation
------------

redbean is dependant on the RedTamarin SDK
- you need to have the SDK deployed on your local machine
- you need to have an environement variable pointing to the SDK root path
  ex: REDTAMARIN_SDK=/sdk/redtamarin
- and/or you need to have 'redbean.cfg' file in your HOME directory
- and/or you need to have 'redbean.cfg' file in your current directory

By default, redbean will try to locate the RedTamarin SDK in this order

1) first, it will look for the REDTAMARIN_SDK
   environment variable

2) then it will look for a 'redbean.cfg' config file
   in your HOME directory

3) finally it will look for a local config file 'redbean.cfg'
   in its current working directory

example of 'redbean.cfg' file
----
var REDTAMARIN_SDK = "/some/path/RedTamarinSDK";
----

If the RedTamarin SDK can not be found,
redbean will throw an error and stop.
----
[error] RedTamarin SDK Not Found!!
----

Now, that you have defined the REDTAMARIN_SDK
that's about it, redbean reside in the 'bin' folder of the SDK
you just need to point your command line to it

under Mac OS X
----
export PATH=$REDTAMARIN_SDK/bin/:$PATH
----
or
----
$ ./$REDTAMARIN_SDK/bin/redbean -- -h
----


Also, any steps 1), 2), or 3) can append or override to the preceding step

for example,
if you have defined in your environment variables
----
REDTAMARIN_SDK=/sdk/redtamarin/1.0
----

but your local config also defines
----
var REDTAMARIN_SDK = "/sdk/redtamarin/2.0";
----
then the last one found will be taken into account
because it override the preceding setup


another example,
the configuration by default defines
----
var verboseMode = false;
var useDebugger = false;
----

if your HOME config defines
----
var useDebugger = true;
----

and if your local config defines
----
var verboseMode = true;
----

then redbean will be setup to use
----
var verboseMode = true;
var useDebugger = true;
----
because it appended the settings of the
HOME config to the local config

That way you can have a global config in your HOME directory
that will affect all the projects and customise the config
for each projects from their local directory.

It can also help you in some particular case to
to be sure the REDTAMARIN_SDK env var is defined,
for example: if you define this env var in your .profile or .bashrc
and then launch Flash Builder, because it is a GUI application
it will not find the environment variable.

Alternatives:

- Under Mac OS X, you can use
  $ launchctl setenv REDTAMARIN_SDK /some/path/RedTamarinSDK

- In Flash Builder
  in Project properties, Builders
  when you create a launch task (to add redbean)
  select the tab "Environment"
  and create the variable REDTAMARIN_SDK


Documentation
-------------

See [Usage] for the command line options.

You can also use a local 'redbean.cfg' file
to override any command line arguments
----
var showHelp = false; // -h
var showInformations = true; // -i
var showEnvironment = true; // -e
var quietMode = false; // -q
var verboseMode = true; // -v
var buildFile = "local.as3" // -f local.as3
var useDebugger = true; // -dd
----

Some configuration can only be defined in a 'redbean.cfg'
----
var REDTAMARIN_SDK = "/some/path/RedTamarinSDK"; //the RedTamarin SDK can not be defined on the command line
var buildFile = "local.as3" //will override the default build file "build.as3"
----

By default redbean will try to load 'build.as3'
from its current directory

either create 'build.as3'
and run $ ./redbean without any other arguments

or create a custom build file 'mybuild.as3'
and run $ ./redbean -- -f mybuild.as3

mybuild.as3
----
import redbean.*;

compile( "src/test.as" );
shell( "src/test.abc" );
----

By default, redbean will produce a moderate output
----
$ ./redbean
[redbean 1.0.0] macintosh 32-bit
[run] build.as3
[compile] src/test.as
[shell] src/test.abc

hello world

[done] in 01s.234ms
----

you can increase the level of output
with '-v' to use "verbose mode"
----
$ ./redbean -- -v
[redbean 1.0.0] macintosh 32-bit
[exe] /some/path/RedTamarinSDK/bin/redbean
[args] -v
[cwd] /my/current/path
[config]
REDTAMARIN_SDK = "/some/path/RedTamarinSDK";
showHelp = false;
showInformation = true;
quietMode = false;
verboseMode = true;
buildFile = "build.as3";
useDebugger = false;
[strings]
asc = "/some/path/RedTamarinSDK/lib/asc.jar";
redshell = "/some/path/RedTamarinSDK/runtimes/redshell/macintosh/32/redshell";
redtamarin_abc = "/some/path/RedTamarinSDK/lib-abc/redtamarin.abc";
...
[run] build.as3
[compile] src/test.as
[java] -jar ${asc} -AS3 -md -import ${redtamarin_abc} src/test.as
[written] test.abc, 123456 bytes
[shell] src/test.abc
[redshell_d] src/test.abc

hello world

[done] in 01s.234ms
----

'-i' options
----
$ ./redbean -- -v -i
...
[informations]
Operating System: Mac OS X 10.8.4
Architecture: x86_64
Processors: 2
Language: English
etc.
...
----

'-e' option
----
$ ./redbean -- -v -e
...
[environment]
A=/path/to/stuff
B=/path/to/stuff
C=/path/to/stuff
...
----

or you can mute redbean completely
with '-q' to use "quiet mode"
----
$ ./redbean -- -q
hello world
----
here "hello world" is the outpout
of the program ran by the shell


Extras
------

You can open those build files in your AS3 IDE
and use the redbean.swc to have syntax completion.

You don't need to compile the build files.

Wether redbean is 32-bit or 64-bit it can build
any Windows/Macintosh/Linux binaries in 32-bit or 64-bit.

You can write any AS3 code logic in those build files,
you are not limited to the redbean functionalities,
you can also import ANY RedTamarin native functionalities
like 'FileSystem' for example.

program32.as3
----
/* Build and Release
   'program' as 32-bit executables
   for Windows/Macintosh/Linux
*/
import redbean.*;
import shell.FileSystem;

trace( "Build program" );
compile( "src/program.as" );
FileSystem.move( "src/program.abc", "program.abc", true );

trace( "Creating program projectors" );
FileSystem.removeDirectory( "release", true );
FileSystem.createDirectory( "release/windows" );
FileSystem.createDirectory( "release/macintosh" );
FileSystem.createDirectory( "release/linux" );

trace( "WIN" );
projector( "program.exe", false, OS.windows32, "program.abc" );
FileSystem.move( "program.exe", "release/windows", true );

trace( "MAC" );
projector( "program", false, OS.macintosh32, "program.abc" );
FileSystem.move( "program", "release/macintosh", true );

trace( "LINUX" );
projector( "program", false, OS.linux32, "program.abc" );
FileSystem.move( "program", "release/linux", true );

trace( "Cleanup" );
FileSystem.removeFile( "program.abc" );
----

You could build the redbean executable with redbean itself :)



How to build
------------

just run the ant build
----
$ ant
----

or manually
----
#!/bin/bash

ASC=build/asc.jar
redtamarin=lib-abc/redtamarin.abc

java -jar ${ASC} -AS3 -md -import ${redtamarin} src/redbean.as
----


Support
-------

documentation
local: documentation.zip
or online: http://docs.redtamarin.com/redbean/latest

Forum
http://www.redtamarin.com/forum


Communication
-------------

Project page
http://www.redtamarin.com/tools/redbean

File a Bug Report or a Feature Request
https://code.google.com/p/redtamarin/issues/list
