redtamarin
==========

Simply put, redtamarin is based on the [Tamarin project](http://www.mozilla.org/projects/tamarin/)
 (eg. the Flash Player Virtual Machine) and allow to run AS3 code on the command-line.

But because Tamarin only support the AS3 builtins (Object, Array, etc.),
redtamarin add numerous native functionalities, so you can test if your program
run under Windows or Linux, or read/write files, or send data with sockets, etc.

Put another way, if Adobe AIR allow you to build desktop executable with a GUI,
redtamarin allow you to build desktop executable with a CLI.


Mission Statement
-----------------

> To support the use of the AS3 language for cross-platform command-line executable,  
> as single exe either for the desktop or the server, as scripts for automation,  
> as tools for the Flash Platform community.


Status
------

This project is **active** even if the sources have not been updated recently.

One of the first questions people ask when discovering redtamarin are

  - Why ?
  - Why still use ActionScript 3 ?
  - Why the command line / server side ?
  - What can you do with it ?

Because of that we decided to stop implementing new native functionalities for a while
and focus instead on "building things with it", and here what we got so far:

  - The Redtamarin SDK  
    Contains the redshell executable for Windows, Mac OS X and Linux (32-bit and 64-bit)  
    the documentation, and tools.  
    [download.redtamarin.com](http://download.redtamarin.com/)
  - redbean (part of the SDK for now)  
    A tool that allows to build, compile, run, manipulate, organise, etc.  
    ActionScript 3.0 projects for RedTamarin
  - [as3shebang](https://github.com/Corsaair/as3shebang)  
    Run ActionScript 3.0 shell scripts
  - [www.burrrn.com](http://www.burrrn.com/)  
    A prototype website programmed entirely in AS3
  - [www.as3lang.org](http://as3lang.org/)  
    A community website about the ActionScript 3.0 language  
    based on the prototype above and refactored to nicer/cleaner code  
    [full sources code available](https://github.com/as3lang/www.as3lang.org)  
    as well as libraries: [ansilib](https://github.com/Corsaair/ansilib), [httplib](https://github.com/Corsaair/httplib), etc.


Communication
-------------

Official Website  
http://redtamarin.com

RedTamarin Google+ Community  
https://plus.google.com/communities/111596731002136630496

File a Bug Report or a Feature Request  
https://github.com/Corsaair/redtamarin/issues


GitHub
------

Our original repository was hosted on Google Code  
http://code.google.com/p/redtamarin/

Now we host the sources on our own server and mirror on Github.

Not that we don't trust Github but we have been burned too many times
by open source repositories closing down on us

