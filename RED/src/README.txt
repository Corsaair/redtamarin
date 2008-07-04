= how to setup =

create a working directory

$ mkdir working-directory
$ cd working-directory

then checkout tamarin with mercurial

$ hg clone http://hg.mozilla.org/tamarin-central tamarin-central
$ cd tamarin-central

then checkout redTamarin inside tamarin-central

$ svn checkout http://redtamarin.googlecode.com/svn/trunk/RED/src/ red

the goal is to have this structure

..
  |_ tamarin-central
         |_ axscript
         |_ build
         |_ codegen
         |_ core
         |_ ...
         |_ red  <- here our code from svn




