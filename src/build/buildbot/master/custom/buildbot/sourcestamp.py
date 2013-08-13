# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.


from zope.interface import implements
from buildbot import util, interfaces

class SourceStamp(util.ComparableMixin):
    """This is a tuple of (branch, revision, patchspec, changes).

    C{branch} is always valid, although it may be None to let the Source
    step use its default branch. There are three possibilities for the
    remaining elements:
     - (revision=REV, patchspec=None, changes=None): build REV. If REV is
       None, build the HEAD revision from the given branch.
     - (revision=REV, patchspec=(LEVEL, DIFF), changes=None): checkout REV,
       then apply a patch to the source, with C{patch -pPATCHLEVEL <DIFF}.
       If REV is None, checkout HEAD and patch it.
     - (revision=None, patchspec=None, changes=[CHANGES]): let the Source
       step check out the latest revision indicated by the given Changes.
       CHANGES is a tuple of L{buildbot.changes.changes.Change} instances,
       and all must be on the same branch.
    """

    # all four of these are publically visible attributes
    branch = None
    revision = None
    patch = None
    changes = ()

    compare_attrs = ('branch', 'revision', 'patch', 'changes')

    implements(interfaces.ISourceStamp)

    def __init__(self, branch=None, revision=None, patch=None,
                 changes=None):
        self.branch = branch
        self.revision = revision
        self.patch = patch
        if changes:
            self.changes = tuple(changes)
            # set branch and revision to last change instead of first
            self.branch = changes[-1].branch
            self.revision = changes[-1].revision

    def canBeMergedWith(self, other):
        if other.branch != self.branch:
            return False # the builds are completely unrelated

        if self.changes and other.changes:
            # TODO: consider not merging these. It's a tradeoff between
            # minimizing the number of builds and obtaining finer-grained
            # results.
            return True
        elif self.changes and not other.changes:
            return False # we're using changes, they aren't
        elif not self.changes and other.changes:
            return False # they're using changes, we aren't

        if self.patch or other.patch:
            return False # you can't merge patched builds with anything
        if self.revision == other.revision:
            # both builds are using the same specific revision, so they can
            # be merged. It might be the case that revision==None, so they're
            # both building HEAD.
            return True

        return False

    def mergeWith(self, others):
        """Generate a SourceStamp for the merger of me and all the other
        BuildRequests. This is called by a Build when it starts, to figure
        out what its sourceStamp should be."""

        # either we're all building the same thing (changes==None), or we're
        # all building changes (which can be merged)
        changes = []
        changes.extend(self.changes)
        for req in others:
            assert self.canBeMergedWith(req) # should have been checked already
            changes.extend(req.changes)
        newsource = SourceStamp(branch=self.branch,
                                revision=self.revision,
                                patch=self.patch,
                                changes=changes)
        return newsource

    def getAbsoluteSourceStamp(self, got_revision):
        return SourceStamp(branch=self.branch, revision=got_revision, patch=self.patch)

    def getText(self):
        # TODO: this won't work for VC's with huge 'revision' strings
        if self.revision is None:
            return [ "latest" ]
        text = [ str(self.revision) ]
        if self.branch:
            text.append("in '%s'" % self.branch)
        if self.patch:
            text.append("[patch]")
        return text
