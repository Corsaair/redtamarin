# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

# For the moment, pretend that nothing but mac exists, and we can always
# use gcc automatic dependencies.

# A "thing" is any static library, DLL, or program.
# things are made up of CXXSRCS and CSRCS.
#
# By default, we use CPPFLAGS/CFLAGS/CXXFLAGS/LDFLAGS.
# This can be overridden using thingname_CPPFLAGS
#
# If you want to *add* flags (without overriding the defaults), use
# thingname_EXTRA_CPPFLAGS
#
# the default target is "all::". Individual manifest.mk should add
# all:: dependencies for any object that should be made by default.

# STATIC_LIBRARIES:
# By default, the library base name is the thingname. To override, set
# thingname_BASENAME

THINGS = \
  $(STATIC_LIBRARIES) \
  $(DLLS) \
  $(PROGRAMS) \
  $(NULL)

$(foreach thing,$(THINGS),$(eval $(call THING_SRCS,$(thing))))
$(foreach lib,$(STATIC_LIBRARIES),$(eval $(call STATIC_LIBRARY_RULES,$(lib))))
$(foreach lib,$(DLLS),$(eval $(call DLL_RULES,$(lib))))
$(foreach program,$(PROGRAMS),$(eval $(call PROGRAM_RULES,$(program))))

clean::
	rm -f $(GARBAGE)
