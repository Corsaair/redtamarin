// Generated from ST_avmplus_basics.st
// -*- mode: c; c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*-
// vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
//
// ***** BEGIN LICENSE BLOCK *****
// Version: MPL 1.1/GPL 2.0/LGPL 2.1
//
// The contents of this file are subject to the Mozilla Public License Version
// 1.1 (the "License"); you may not use this file except in compliance with
// the License. You may obtain a copy of the License at
// http://www.mozilla.org/MPL/
//
// Software distributed under the License is distributed on an "AS IS" basis,
// WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
// for the specific language governing rights and limitations under the
// License.
//
// The Original Code is [Open Source Virtual Machine.].
//
// The Initial Developer of the Original Code is
// Adobe System Incorporated.
// Portions created by the Initial Developer are Copyright (C) 2004-2006
// the Initial Developer. All Rights Reserved.
//
// Contributor(s):
//   Adobe AS3 Team
//
// Alternatively, the contents of this file may be used under the terms of
// either the GNU General Public License Version 2 or later (the "GPL"), or
// the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
// in which case the provisions of the GPL or the LGPL are applicable instead
// of those above. If you wish to allow use of your version of this file only
// under the terms of either the GPL or the LGPL, and not to allow others to
// use your version of this file under the terms of the MPL, indicate your
// decision by deleting the provisions above and replace them with the notice
// and other provisions required by the GPL or the LGPL. If you do not delete
// the provisions above, a recipient may use your version of this file under
// the terms of any one of the MPL, the GPL or the LGPL.
//
// ***** END LICENSE BLOCK ***** */

#include "avmshell.h"
#ifdef VMCFG_SELFTEST
namespace avmplus {
class ST_avmplus_basics : public Selftest {
public:
ST_avmplus_basics(AvmCore* core);
virtual void run(int n);
private:
static const char* ST_names[];
static const bool ST_explicits[];
void test0();
void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();
void test8();
};
ST_avmplus_basics::ST_avmplus_basics(AvmCore* core)
    : Selftest(core, "avmplus", "basics", ST_avmplus_basics::ST_names,ST_avmplus_basics::ST_explicits)
{}
const char* ST_avmplus_basics::ST_names[] = {"unsigned_int","signed_int","equalsLatin1","containsLatin1","indexOfLatin1","matchesLatin1","matchesLatin1_caseless","bug562101","bug610022", NULL };
const bool ST_avmplus_basics::ST_explicits[] = {false,false,false,false,false,false,false,false,false, false };
void ST_avmplus_basics::run(int n) {
switch(n) {
case 0: test0(); return;
case 1: test1(); return;
case 2: test2(); return;
case 3: test3(); return;
case 4: test4(); return;
case 5: test5(); return;
case 6: test6(); return;
case 7: test7(); return;
case 8: test8(); return;
}
}
void ST_avmplus_basics::test0() {

// Does right shift of unsigned quantities work?
#line 47 "ST_avmplus_basics.st"
verifyPass((int)(~0U >> 1) > 0, "(int)(~0U >> 1) > 0", __FILE__, __LINE__);

}
void ST_avmplus_basics::test1() {

// Does right shift of signed quantities work?
#line 52 "ST_avmplus_basics.st"
verifyPass((-1 >> 1) == -1, "(-1 >> 1) == -1", __FILE__, __LINE__);

// verify that the "latin1" literal string calls work properly for hi-bit latin1 chars
}
void ST_avmplus_basics::test2() {
    Stringp s = core->newConstantStringLatin1("ev\xADident");
    bool equals = s->equalsLatin1("ev\xADident");
#line 58 "ST_avmplus_basics.st"
verifyPass(equals == true, "equals == true", __FILE__, __LINE__);

}
void ST_avmplus_basics::test3() {
    Stringp s = core->newConstantStringLatin1("ev\xADident");
    bool found = s->containsLatin1("\xAD");
#line 63 "ST_avmplus_basics.st"
verifyPass(found == true, "found == true", __FILE__, __LINE__);

}
void ST_avmplus_basics::test4() {
    Stringp s = core->newConstantStringLatin1("ev\xADident");
    int index = s->indexOfLatin1("\xAD");
#line 68 "ST_avmplus_basics.st"
verifyPass(index == 2, "index == 2", __FILE__, __LINE__);

}
void ST_avmplus_basics::test5() {
    Stringp s = core->newConstantStringLatin1("ev\xADident");
    bool matches1 = s->matchesLatin1("\xADi", 2, 2);
#line 73 "ST_avmplus_basics.st"
verifyPass(matches1 == true, "matches1 == true", __FILE__, __LINE__);

}
void ST_avmplus_basics::test6() {
    Stringp s = core->newConstantStringLatin1("ev\xADident");
    bool matches2 = s->matchesLatin1_caseless("\xADIDENT", 2, 2);
#line 78 "ST_avmplus_basics.st"
verifyPass(matches2 == true, "matches2 == true", __FILE__, __LINE__);


}
void ST_avmplus_basics::test7() {
// XMLParser omits the last char of a DOCTYPE node
Stringp str = core->newConstantStringLatin1("<?xml version=\"1.0\"?><!DOCTYPE greeting SYSTEM><greeting>Hello, world!</greeting>");
XMLParser parser(core, str);
MMgc::GC *gc = core->GetGC();
XMLTag tag(gc);
int m_status;
bool pass = false;
while ((m_status = parser.getNext(tag)) == XMLParser::kNoError)
{
    switch (tag.nodeType)
    {
        case XMLTag::kDocTypeDeclaration:
        {
            pass = false;
            pass = tag.text->equalsLatin1("<!DOCTYPE greeting SYSTEM>");
        }
    break;
    }
}
#line 101 "ST_avmplus_basics.st"
verifyPass(pass == true, "pass == true", __FILE__, __LINE__);

}
void ST_avmplus_basics::test8() {
    Stringp str = core->newConstantStringLatin1("some string that is likely to be unique");
    WeakRefList<String> list(core->GetGC(), 0);
    // We are going to skip scanning the stack (so that "str" won't hold the string in place)
    // but that means we need a root to ensure that "list" doesn't also get collected.
    MMgc::GCRoot root(core->GetGC(), &list, sizeof(list));
    list.add(str);
    str = NULL;
    core->GetGC()->Collect(/*scanStack*/false);
    int removed = list.removeCollectedItems();
    int count = list.length();
#line 111 "ST_avmplus_basics.st"
verifyPass(removed == 1 && count == 0, "removed == 1 && count == 0", __FILE__, __LINE__);



}
void create_avmplus_basics(AvmCore* core) { new ST_avmplus_basics(core); }
}
#endif
