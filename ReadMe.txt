
RedTamarin

This project is a fork of the Tamarin project
(see http://www.mozilla.org/projects/tamarin/).

Tamarin comes with very few access to the system,
File I/O, etc. and that's normal because Tamarin
is mainly a Virtual Machine and access to the
subsystem are (I suppose) secondary.

RedTamarin is not here to replace the VM but to
extend its access to the system by providing
low-level native libraries.

example:
If you can use the standard C function getwcd()
on most operating systems, then RedTamarin will
implement a native access to that function trying
to keep the same function signature.

project page: http://code.google.com/p/redtamarin/

