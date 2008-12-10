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
# Portions created by the Initial Developer are Copyright (C) 2007
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

import optparse, struct, os, sys
from optparse import OptionParser
from struct import *
from os import path
from math import floor
from sys import stderr

parser = OptionParser(usage="usage: %prog [--nativemapname=name] [--uniquethunks] [importfile [, importfile]...] file...")
parser.add_option("-n", "--nativemapname", help="if using explicit maps for native classes and scripts, the name as argument")
parser.add_option("-u", "--uniquethunks", help="generate a unique thunk for every native method (don't recycle thunks with similar signatures)")
opts, args = parser.parse_args()

if not args:
	parser.print_help()
	exit(2)

if opts.uniquethunks and opts.nativemapname:
	raise Error("--uniquethunks cannot be used with --nativemapname")

NEED_ARGUMENTS		= 0x01
NEED_ACTIVATION		= 0x02
NEED_REST			= 0x04
HAS_OPTIONAL		= 0x08
IGNORE_REST			= 0x10
NATIVE				= 0x20
HAS_ParamNames		= 0x80

CONSTANT_Utf8               = 0x01
CONSTANT_Int	            = 0x03
CONSTANT_UInt               = 0x04
CONSTANT_PrivateNs	        = 0x05
CONSTANT_Double             = 0x06
CONSTANT_Qname              = 0x07
CONSTANT_Namespace	        = 0x08
CONSTANT_Multiname          = 0x09
CONSTANT_False              = 0x0A
CONSTANT_True               = 0x0B
CONSTANT_Null               = 0x0C
CONSTANT_QnameA             = 0x0D
CONSTANT_MultinameA         = 0x0E
CONSTANT_RTQname	        = 0x0F
CONSTANT_RTQnameA	        = 0x10
CONSTANT_RTQnameL	        = 0x11
CONSTANT_RTQnameLA	        = 0x12
CONSTANT_NameL				= 0x13
CONSTANT_NameLA				= 0x14
CONSTANT_NamespaceSet       = 0x15
CONSTANT_PackageNs			= 0x16
CONSTANT_PackageInternalNs  = 0x17
CONSTANT_ProtectedNs		= 0x18
CONSTANT_ExplicitNamespace  = 0x19
CONSTANT_StaticProtectedNs  = 0x1A
CONSTANT_MultinameL         = 0x1B
CONSTANT_MultinameLA        = 0x1C
CONSTANT_TypeName	        = 0x1D

TRAIT_Slot			= 0x00
TRAIT_Method		= 0x01
TRAIT_Getter		= 0x02
TRAIT_Setter		= 0x03
TRAIT_Class			= 0x04
TRAIT_Const			= 0x06
TRAIT_mask			= 15

ATTR_final			= 0x10
ATTR_override       = 0x20
ATTR_metadata       = 0x40

CTYPE_VOID			= 0
CTYPE_ATOM			= 1
CTYPE_BOOLEAN		= 2
CTYPE_INT			= 3
CTYPE_UINT			= 4
CTYPE_DOUBLE		= 5
CTYPE_STRING		= 6
CTYPE_NAMESPACE		= 7
CTYPE_OBJECT		= 8

MPL_HEADER = "/* ***** BEGIN LICENSE BLOCK *****\n" \
            " * Version: MPL 1.1/GPL 2.0/LGPL 2.1\n" \
            " *\n" \
            " * The contents of this file are subject to the Mozilla Public License Version\n" \
            " * 1.1 (the \"License\"); you may not use this file except in compliance with\n" \
            " * the License. You may obtain a copy of the License at\n" \
            " * http://www.mozilla.org/MPL/\n" \
            " *\n" \
            " * Software distributed under the License is distributed on an \"AS IS\" basis,\n" \
            " * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License\n" \
            " * for the specific language governing rights and limitations under the\n" \
            " * License.\n" \
            " *\n" \
            " * The Original Code is [Open Source Virtual Machine].\n" \
            " *\n" \
            " * The Initial Developer of the Original Code is\n" \
            " * Adobe System Incorporated.\n" \
            " * Portions created by the Initial Developer are Copyright (C) 2008\n" \
            " * the Initial Developer. All Rights Reserved.\n" \
            " *\n" \
            " * Contributor(s):\n" \
            " *   Adobe AS3 Team\n" \
            " *\n" \
            " * Alternatively, the contents of this file may be used under the terms of\n" \
            " * either the GNU General Public License Version 2 or later (the \"GPL\"), or\n" \
            " * the GNU Lesser General Public License Version 2.1 or later (the \"LGPL\"),\n" \
            " * in which case the provisions of the GPL or the LGPL are applicable instead\n" \
            " * of those above. If you wish to allow use of your version of this file only\n" \
            " * under the terms of either the GPL or the LGPL, and not to allow others to\n" \
            " * use your version of this file under the terms of the MPL, indicate your\n" \
            " * decision by deleting the provisions above and replace them with the notice\n" \
            " * and other provisions required by the GPL or the LGPL. If you do not delete\n" \
            " * the provisions above, a recipient may use your version of this file under\n" \
            " * the terms of any one of the MPL, the GPL or the LGPL.\n" \
            " *\n" \
            " * ***** END LICENSE BLOCK ***** */" 


# Python 2.5 and earlier didn't reliably handle float("nan") and friends uniformly
# across all platforms. This is a workaround that appears to be more reliable.
# if/when we require Python 2.6 or later we can use a less hack-prone approach
kPosInf = 1e300000
kNegInf = -1e300000
kNaN = kPosInf / kPosInf

def is_nan(val):
	strValLower = str(val).lower()
	return strValLower == "nan"

def is_pos_inf(val):
	# [-]1.#INF on Windows in Python 2.5.2!
	strValLower = str(val).lower()
	return strValLower.endswith("inf") and not strValLower.startswith("-")

def is_neg_inf(val):
	# [-]1.#INF on Windows in Python 2.5.2!
	strValLower = str(val).lower()
	return strValLower.endswith("inf") and strValLower.startswith("-")

class Error(Exception):
	nm = ""
	def __init__(self, n):
		self.nm = n
	def __str__(self):
		return self.nm

TMAP = {
	CTYPE_OBJECT:		("o", "AvmObject"),
	CTYPE_ATOM:			("a", "AvmBox"),
	CTYPE_VOID:			("v", "void"),
	CTYPE_BOOLEAN:		("b", "AvmBool32"),
	CTYPE_INT:			("i", "int32_t"),
	CTYPE_UINT:			("u", "uint32_t"),
	CTYPE_DOUBLE:		("d", "double"),
	CTYPE_STRING:		("s", "AvmString"),
	CTYPE_NAMESPACE:	("n", "AvmNamespace")
};

def uint(i):
	return int(i) & 0xffffffff

def sigchar_from_enum(ct, allowObject):
	if ct == CTYPE_OBJECT and not allowObject:
		ct = CTYPE_ATOM
	return TMAP[ct][0]

def sigchar_from_traits(t, allowObject):
	return sigchar_from_enum(t.ctype, allowObject)

def ctype_from_enum(ct, allowObject):
	if ct == CTYPE_OBJECT and not allowObject:
		ct = CTYPE_ATOM
	return TMAP[ct][1]

def ctype_from_traits(t, allowObject):
	return ctype_from_enum(t.ctype, allowObject)

def to_cname(nm):
	nm = str(nm)
	nm = nm.replace("+", "_");
	nm = nm.replace("-", "_");
	nm = nm.replace("?", "_");
	nm = nm.replace("!", "_");
	nm = nm.replace("<", "_");
	nm = nm.replace(">", "_");
	nm = nm.replace("=", "_");
	nm = nm.replace("(", "_");
	nm = nm.replace(")", "_");
	nm = nm.replace("\"", "_");
	nm = nm.replace("'", "_");
	nm = nm.replace("*", "_");
	nm = nm.replace(" ", "_");
	nm = nm.replace(".", "_");
	nm = nm.replace("$", "_");
	nm = nm.replace("::", "_");
	nm = nm.replace(":", "_");
	nm = nm.replace("/", "_");
	return nm

def ns_prefix(ns, iscls):
	if not ns.isPublic() and not ns.isInternal():
		if ns.isPrivate() and not iscls:
			return "private_";
		if ns.isProtected():
			return "protected_";
		if ns.srcname != None:
			return to_cname(str(ns.srcname)) + "_"
	p = to_cname(ns.uri);
	if len(p) > 0:
		p += "_"
	return p

class Namespace:
	uri = ""
	kind = 0
	srcname = None
	def __init__(self, uri, kind):
		self.uri = uri
		self.kind = kind
	def __str__(self):
		return self.uri
	def isPublic(self):
		return self.kind in [CONSTANT_Namespace, CONSTANT_PackageNs] and self.uri == ""
	def isInternal(self):
		return self.kind in [CONSTANT_PackageInternalNs]
	def isPrivate(self):
		return self.kind in [CONSTANT_PrivateNs]
	def isProtected(self):
		return self.kind in [CONSTANT_ProtectedNs, CONSTANT_StaticProtectedNs]

class QName:
	ns = None
	name = ""
	def __init__(self, ns, name):
		self.ns = ns
		self.name = name
	def __str__(self):
		if str(self.ns) == "":
			return self.name
		if self.ns == None:
			return "*::" + self.name
		return str(self.ns) + "::" + self.name

class Multiname:
	nsset = None
	name = ""
	def __init__(self, nsset, name):
		self.nsset = nsset
		self.name = name
	def __str__(self):
		assert(0)
		return "FOO"

class TypeName:
	name = ""
	types = None
	def __init__(self, name, types):
		self.name = name
		self.types = types
	def __str__(self):
		return str(self.name)

class MetaData:
	name = ""
	attrs = {}
	def __init__(self, name):
		self.name = name
		self.attrs = {}

class MemberInfo:
	id = -1
	kind = -1
	name = ""
	metadata = None

class MethodInfo(MemberInfo):
	flags = 0
	debugName = ""
	paramTypes = None
	paramNames = None
	optional_count = 0
	optionalValues = None
	returnType = None
	local_count = 0
	max_scope = 0
	max_stack = 0
	code_length = 0
	code = None
	activation = None
	native_id_name = None
	native_method_name = None
	final = False
	override = False
	gen_method_map = False
	receiver = None

	def isNative(self):
		return (self.flags & NATIVE) != 0

	def needRest(self):
		return (self.flags & NEED_REST) != 0

	def hasOptional(self):
		return (self.flags & HAS_OPTIONAL) != 0

	def assign_names(self, traits, prefix):
		
		self.receiver = traits
		self.gen_method_map = traits.ni.gen_method_map
		
		if not self.isNative():
			return
		
		if self == traits.init:
			self.native_id_name = prefix + to_cname(traits.name.name) 
			if traits.niname != None:
				self.native_method_name = "#error illegal name, ctors cannot be native"

		else:
			assert(isinstance(self.name, QName))
			self.native_id_name = prefix + ns_prefix(self.name.ns, False) + self.name.name
			self.native_method_name = self.name.name

			if self.kind == TRAIT_Getter:
				self.native_id_name += "_get"
				self.native_method_name = "get_" + self.native_method_name
			elif self.kind == TRAIT_Setter:
				self.native_id_name += "_set"		
				self.native_method_name = "set_" + self.native_method_name

			if self.name.ns.srcname != None:
				self.native_method_name = str(self.name.ns.srcname) + "_" + self.native_method_name

			# if we are an override, prepend the classname to the C method name.
			# (native method implementations must not be virtual, and some compilers
			# will be unhappy if a subclass overrides a method with the same name and signature
			# without it being virtual.) Note that we really only need to do this if the ancestor
			# implementation is native, rather than pure AS3, but we currently do it regardless.
			if self.override:
				self.native_method_name = traits.name.name + "_" + self.native_method_name

			self.native_method_name = to_cname(self.native_method_name)
					
class SlotInfo(MemberInfo):
	type = ""
	value = ""

class NativeInfo:
	class_name = None
	instance_name = None
	script_name = None
	gen_method_map = False
	
	def set_script(self, name):
		if self.script_name != None:
			raise Error("native(script) may not be specified multiple times for the same script: %s %s" % (self.script_name, name) )
		self.script_name = name

	def set_class(self, name):
		if self.class_name != None:
			raise Error("native(cls) may not be specified multiple times for the same class: %s %s" % (self.class_name, name))
		self.class_name = name

	def set_instance(self, name):
		if self.instance_name != None:
			raise Error("native(instance) may not be specified multiple times for the same class: %s %s" % (self.instance_name, name))
		self.instance_name = name
		
	def validate(self):
		if (self.script_name != None) and (self.class_name != None or self.instance_name != None):
			raise Error("cannot mix script and class/instance attributes")
		if self.gen_method_map and self.script_name == None and self.class_name == None and self.instance_name == None:
			raise Error("cannot specify native(methods) without native(script) or native(cls)")
		if self.class_name != None or self.instance_name != None:
			# if nothing specified, use ClassClosure/ScriptObject.
			if self.class_name == None:
				self.class_name = "ClassClosure"
			if self.instance_name == None:
				self.instance_name = "ScriptObject"
			

BMAP = {
	"Object": CTYPE_ATOM, # yes, items of exactly class "Object" are stored as Atom; subclasses are stored as pointer-to-Object
	"null": CTYPE_ATOM,
	"*": CTYPE_ATOM,
	"void": CTYPE_VOID,
	"int": CTYPE_INT,
	"uint": CTYPE_UINT,
	"Number": CTYPE_DOUBLE,
	"Boolean": CTYPE_BOOLEAN,
	"String": CTYPE_STRING,
	"Namespace": CTYPE_NAMESPACE
};

class Traits:
	name = ""
	qname = None
	init = None
	itraits = None
	base = None
	flags = 0
	protectedNs = 0
	is_interface = False
	interfaces = None
	names = None
	slots = None
	tmethods = None
	members = None
	class_id = -1
	ctype = CTYPE_OBJECT
	metadata = None
	ni = None
	niname = None
	def __init__(self, name):
		self.names = {}
		self.slots = []
		self.tmethods = []
		self.name = name
		if BMAP.has_key(str(name)):
			self.ctype = BMAP[str(name)]
	def __str__(self):
		return str(self.name)

NULL = Traits("*")
UNDEFINED = Traits("void")

class ByteArray:
	data = None
	pos = 0
	def __init__(self, data):
		self.data = data
		self.pos = 0
		
	def readU8(self):
		r = unpack_from("B", self.data, self.pos)[0]
		self.pos += 1
		assert(r >= 0 and r <= 255)
		return r

	def readU16(self):
		r = unpack_from("<h", self.data, self.pos)[0]
		self.pos += 2
		assert(r >= 0 and r <= 65535)
		return r

	def readDouble(self):
		r = unpack_from("<d", self.data, self.pos)[0]
		self.pos += 8
		return r

	def readBytes(self, lenbytes):
		r = self.data[self.pos:self.pos+lenbytes]
		self.pos += lenbytes
		return r

	def readUTF8(self):
		lenbytes = self.readU30()
		return self.readBytes(lenbytes)

	def readU30(self):
		result = self.readU8()
		if not result & 0x00000080:
			return result
		result = (result & 0x0000007f) | (self.readU8() << 7)
		if not result & 0x00004000:
			return result
		result = (result & 0x00003fff) | (self.readU8() << 14)
		if not result & 0x00200000:
			return result
		result = (result & 0x001fffff) | (self.readU8() << 21)
		if not result & 0x10000000:
			return result
		result = (result & 0x0fffffff) | (self.readU8() << 28)
		return result
		

class Abc:
	data = None
	major = 0
	minor = 0
	ints = None
	uints = None
	doubles = None
	strings = None
	namespaces = None
	nssets = None
	names = None
	defaults = None
	methods = None
	instances = None
	metadata = None
	classes = None
	scripts = None
	scriptName = ""
	publicNs = Namespace("", CONSTANT_Namespace)
	anyNs = Namespace("*", CONSTANT_Namespace)
	magic = 0
		
	def __init__(self, data, scriptName):
		self.scriptName = scriptName
		self.data = ByteArray(data)

		if self.data.readU16() != 16 or self.data.readU16() != 46:
			raise Error("Bad Abc Version")

		self.parseCpool()
		
		self.defaults = [ (None, 0) ] * 32
		self.defaults[CONSTANT_Utf8] = (self.strings, CTYPE_STRING)
		self.defaults[CONSTANT_Int] = (self.ints, CTYPE_INT)
		self.defaults[CONSTANT_UInt] = (self.uints, CTYPE_UINT)
		self.defaults[CONSTANT_Double] = (self.doubles, CTYPE_DOUBLE)
		self.defaults[CONSTANT_False] = ({ CONSTANT_False: False }, CTYPE_BOOLEAN)
		self.defaults[CONSTANT_True] = ({ CONSTANT_True: True }, CTYPE_BOOLEAN)
		self.defaults[CONSTANT_Namespace] = (self.namespaces, CTYPE_NAMESPACE)
		self.defaults[CONSTANT_PrivateNs] = (self.namespaces, CTYPE_NAMESPACE)
		self.defaults[CONSTANT_PackageNs] = (self.namespaces, CTYPE_NAMESPACE)
		self.defaults[CONSTANT_PackageInternalNs] = (self.namespaces, CTYPE_NAMESPACE)
		self.defaults[CONSTANT_ProtectedNs] = (self.namespaces, CTYPE_NAMESPACE)
		self.defaults[CONSTANT_StaticProtectedNs] = (self.namespaces, CTYPE_NAMESPACE)
		self.defaults[CONSTANT_ExplicitNamespace] = (self.namespaces, CTYPE_NAMESPACE)
		self.defaults[CONSTANT_Null] = ({ CONSTANT_Null: None }, CTYPE_ATOM)	
		
		self.parseMethodInfos()
		self.parseMetadataInfos()
		self.parseInstanceInfos()
		self.parseClassInfos()
		self.parseScriptInfos()
		self.parseMethodBodies()

		for i in range(0, len(self.classes)):
			c = self.classes[i]
			assert(isinstance(c.name, QName))
			prefix = ns_prefix(c.name.ns, True) + to_cname(c.name.name)
			c.class_id = i
			c.ni = self.find_class_nativeinfo(c)
			c.niname = c.ni.class_name
			self.assign_names(c, prefix)
			if c.itraits:
				c.itraits.ni = c.ni
				c.itraits.niname = c.ni.instance_name
				self.assign_names(c.itraits, prefix)

		for i in range(0, len(self.scripts)):
			script = self.scripts[i]
			if script != None:
				prefix = ""
				script.ni = self.find_script_nativeinfo(script)
				script.niname = script.ni.script_name
				self.assign_names(script, prefix)

	def assign_names(self, traits, prefix):
		if traits.init != None:
			traits.init.assign_names(traits, prefix)
		for j in range(0, len(traits.tmethods)):
			traits.tmethods[j].assign_names(traits, prefix)

	def default_ctype_and_value(self,d):
		kind, index = d
		deftable = self.defaults[kind]
		if deftable[0] != None:
			val = str(deftable[0][index])
			ct = deftable[1]
		else:
			assert(kind == 0 and index == 0)
			val = "kAvmThunkUndefined"
			ct = CTYPE_ATOM # yes, not void
		rawval = val
		if ct == CTYPE_DOUBLE:
			# Python apparently doesn't have isNaN, isInf
			if is_nan(val):
				val = "kAvmThunkNaN"
			elif is_neg_inf(val):
				val = "kAvmThunkNegInfinity"
			elif is_pos_inf(val):
				val = "kAvmThunkInfinity"
			elif float(val) >= -2147483648.0 and float(val) <= 2147483647.0 and float(val) == floor(float(val)):
				ct = CTYPE_INT
				val = "%.0f" % float(val)
			elif float(val) >= 0.0 and float(val) <= 4294967295.0 and float(val) == floor(float(val)):
				ct = CTYPE_UINT
				val = "%.0fU" % float(val)
		elif ct == CTYPE_STRING:
			for i in range(0, len(self.strings)):
				if (self.strings[i] == str(val)):
					val = "AvmThunkConstant_AvmString("+str(i)+")/* \""+self.strings[i]+"\" */";
					break
		elif ct == CTYPE_BOOLEAN:
			assert(str(val) == "False" or str(val) == "True")
			if str(val) == "False":
				val = "false"
			else:
				val = "true"
		if str(val) == "None":
			val = "kAvmThunkNull"
		return ct,val,rawval
	
	def parseCpool(self):
		
		n = self.data.readU30()
		self.ints = [0] * max(1,n)
		for i in range(1, n):
			ii = self.data.readU30()
			if float(ii) > 2147483647.0:
				ii = int(ii - 4294967296.0)
			assert(int(ii) >= -2147483648 and int(ii) <= 2147483647)
			self.ints[i] = int(ii)
			
		n = self.data.readU30()
		self.uints = [0] * max(1,n)
		for i in range(1, n):
			self.uints[i] = uint(self.data.readU30())
			
		n = self.data.readU30()
		self.doubles = [ kNaN ] * max(1,n)
		for i in range(1, n):
			self.doubles[i] = self.data.readDouble()

		n = self.data.readU30()
		self.strings = [""] * max(1,n)
		for i in range(1, n):
			self.strings[i] = self.data.readUTF8()

		n = self.data.readU30()
		self.namespaces = [self.anyNs] * max(1,n)
		for i in range(1, n):
			nskind = self.data.readU8()
			if nskind in [CONSTANT_Namespace, 
							CONSTANT_PackageNs, 
							CONSTANT_PackageInternalNs,
							CONSTANT_ProtectedNs,
							CONSTANT_ExplicitNamespace,
							CONSTANT_StaticProtectedNs]:
				self.namespaces[i] = Namespace(self.strings[self.data.readU30()], nskind)

			elif nskind in [CONSTANT_PrivateNs]:
				self.data.readU30() # skip
				self.namespaces[i] = Namespace("private", CONSTANT_PrivateNs)

		n = self.data.readU30()
		self.nssets = [ None ] * max(1,n)
		for i in range(1, n):
			count = self.data.readU30()
			self.nssets[i] = []
			for j in range(0, count):
				self.nssets[i].append(self.namespaces[self.data.readU30()])

		n = self.data.readU30()
		self.names = [ None ] * max(1,n)
		for i in range(1, n):
			namekind = self.data.readU8()
			if namekind in [CONSTANT_Qname, CONSTANT_QnameA]:
				self.names[i] = QName(self.namespaces[self.data.readU30()], self.strings[self.data.readU30()])

			elif namekind in [CONSTANT_RTQname, CONSTANT_RTQnameA]:
				self.names[i] = QName(self.anyNs, self.strings[self.data.readU30()])

			elif namekind in [CONSTANT_RTQnameL, CONSTANT_RTQnameLA]:
				self.names[i] = None

			elif namekind in [CONSTANT_NameL, CONSTANT_NameLA]:
				self.names[i] = QName(Namespace(""), None)

			elif namekind in [CONSTANT_Multiname, CONSTANT_MultinameA]:
				name = self.strings[self.data.readU30()]
				nsset = self.nssets[self.data.readU30()]
				self.names[i] = Multiname(nsset, name)

			elif namekind in [CONSTANT_MultinameL, CONSTANT_MultinameLA]:
				nsset = self.nssets[self.data.readU30()]
				self.names[i] = Multiname(nsset, None)

			elif namekind in [CONSTANT_TypeName]:
				name = self.names[self.data.readU30()];
				count = self.data.readU30();
				types = []
				for j in range(0, count):
					types.append(self.names[self.data.readU30()]);
				self.names[i] = TypeName(name, types);
			else:
				raise Error("Bad Kind")

	def parseMethodInfos(self):
		self.names[0] = QName(self.publicNs,"*")
		method_count = self.data.readU30()
		self.methods = [ None ] * method_count
		for i in range(0, method_count):
			m = MethodInfo()
			self.methods[i] = m
			param_count = self.data.readU30()
			m.returnType = self.names[self.data.readU30()]
			m.paramTypes = [ None ] * param_count
			m.paramNames = [ "" ] * param_count
			m.optional_count = 0
			for j in range(0, param_count):
				m.paramTypes[j] = self.names[self.data.readU30()]
			m.debugName = self.strings[self.data.readU30()]
			m.flags = self.data.readU8()
			if m.hasOptional():
				m.optional_count = self.data.readU30();
				m.optionalValues = [ (-1, -1) ] * param_count
				for k in range(param_count-m.optional_count, param_count):
					index = self.data.readU30()
					kind = self.data.readU8()
					m.optionalValues[k] = (kind, index)
			if (m.flags & HAS_ParamNames) != 0:
				for j in range(0, param_count):
					m.paramNames[j] = self.strings[self.data.readU30()]

	def parseMetadataInfos(self):
		count = self.data.readU30()
		self.metadata = [ None ] * count
		for i in range (0, count):
			mname = self.strings[self.data.readU30()]
			m = MetaData(mname)
			self.metadata[i] = m
			values_count = self.data.readU30()
			names = [ None ] * values_count
			for q in range(0, values_count):
				names[q] = self.strings[self.data.readU30()]
			for q in range(0, values_count):
				m.attrs[names[q]] = self.strings[self.data.readU30()] 

	def parseInstanceInfos(self):
		count = self.data.readU30()
		self.instances = [ None ] * count
		for i in range (0, count):
			tname = self.names[self.data.readU30()]
			t = Traits(tname)
			self.instances[i] = t
			t.base = self.names[self.data.readU30()]
			t.flags = self.data.readU8()
			if (t.flags & 4) != 0:
				t.is_interface = True
			if (t.flags & 8) != 0:
				t.protectedNs = self.namespaces[self.data.readU30()]
			interface_count = self.data.readU30()
			t.interfaces = [None] * interface_count
			for j in range(0, interface_count):
				t.interfaces[j] = self.names[self.data.readU30()]
			methid = self.data.readU30()
			t.init = self.methods[methid]
			t.init.name = t.name
			t.init.kind = TRAIT_Method
			t.init.id = methid
			self.parseTraits(t)
	
	def parseTraits(self, t):
		namecount = self.data.readU30()
		t.members = [ None ] * namecount
		for i in range(0, namecount):
			name = self.names[self.data.readU30()]
			tag = self.data.readU8()
			kind = tag & 0xf
			member = None
			if kind in [TRAIT_Slot, TRAIT_Const, TRAIT_Class]:
				member = SlotInfo()
				member.id = self.data.readU30()
				while len(t.slots) <= member.id:
					t.slots.append(None)
				t.slots[member.id] = member
				if kind in [TRAIT_Slot, TRAIT_Const]:
					member.type = self.names[self.data.readU30()]
					index = self.data.readU30()
					if index:
						deftable = self.defaults[self.data.readU8()]
						member.value = deftable[0][index]
						if deftable[1] == CTYPE_NAMESPACE:
							assert(isinstance(member.value, Namespace))
							member.value.srcname = name.name
				else:
					member.value = self.classes[self.data.readU30()]
					member.value.qname = name
			elif kind in [TRAIT_Method, TRAIT_Getter, TRAIT_Setter]:
				self.data.readU30()	# disp_id, ignored
				methid = self.data.readU30()
				member = self.methods[methid]
				t.tmethods.append(member)
				member.id = methid
				member.final = (tag & ATTR_final) != 0
				member.override = (tag & ATTR_override) != 0
			member.kind = kind
			member.name = name
			t.members[i] = member
			t.names[str(name)] = member
			
			if (tag & ATTR_metadata) != 0:
				mdCount = self.data.readU30()
				member.metadata = [ None ] * mdCount
				for j in range(0, mdCount):
					member.metadata[j] = self.metadata[self.data.readU30()]
				# stash class metadata in the ctraits and itraits too, makes it much easier later
				if kind == TRAIT_Class:
					member.value.metadata = member.metadata
					member.value.itraits.metadata = member.metadata

	def find_nativeinfo(self, m, ni):
		if m != None:
			for md in m:
				if md.name == "native":
					if md.attrs.has_key("script"):
						ni.set_script(md.attrs["script"])
					if md.attrs.has_key("cls"):
						ni.set_class(md.attrs["cls"])
					if md.attrs.has_key("instance"):
						ni.set_instance(md.attrs["instance"])
					if md.attrs.has_key("methods"):
						v = md.attrs["methods"]
						if v != "auto":
							raise Error("the only legal value for native(methods) is auto")
						ni.gen_method_map = True
					if (ni.script_name == None) and (ni.class_name == None) and (ni.instance_name == None):
						raise Error("native metadata must specify (script) or (cls,instance)")

	def find_script_nativeinfo(self, t):
		ni = NativeInfo()
		# since asc doesn't allow us to put metadata on scripts, look for it on methods of the script. 
		for j in range(0, len(t.tmethods)):
			self.find_nativeinfo(t.tmethods[j].metadata, ni)
		ni.validate()
		return ni

	def find_class_nativeinfo(self, t):
		ni = NativeInfo()
		self.find_nativeinfo(t.metadata, ni)
		if ni.instance_name != None and t.itraits.is_interface:
			raise Error("interfaces may not specify native(instance)")
		ni.validate()
		return ni
		
	def parseClassInfos(self):
		count = len(self.instances)
		self.classes = [ None ] * count
		for i in range(0, count):
			itraits = self.instances[i]
			tname = QName(itraits.name.ns, (str(itraits.name.name) + "$"))
			t = Traits(tname)
			self.classes[i] = t
			t.init = self.methods[self.data.readU30()]
			t.base = "Class"
			t.itraits = itraits
			t.init.name = str(t.itraits.name) + "$cinit"
			t.init.kind = TRAIT_Method
			self.parseTraits(t)

	def parseScriptInfos(self):
		count = self.data.readU30()
		self.scripts = [ None ] * count
		for i in range(0, count):
			tname = self.scriptName + "_script_" + str(i)
			t = Traits(tname)
			self.scripts[i] = t
			t.init = self.methods[self.data.readU30()]
			t.base = self.names[0]
			t.itraits = None
			t.init.name = t.name + "$init"
			t.init.kind = TRAIT_Method	    
			self.parseTraits(t)

	def parseMethodBodies(self):
		count = self.data.readU30()
		for i in range(0, count):
			m = self.methods[self.data.readU30()]
			m.max_stack = self.data.readU30()
			m.local_count = self.data.readU30()
			initScopeDepth = self.data.readU30()
			maxScopeDepth = self.data.readU30()
			m.max_scope = maxScopeDepth - initScopeDepth
			code_length = self.data.readU30()
			m.code = self.data.readBytes(code_length)
			ex_count = self.data.readU30()
			for j in range(0, ex_count):
				frm = self.data.readU30()
				to = self.data.readU30()
				target = self.data.readU30()
				type = self.names[self.data.readU30()]
				name = self.names[self.data.readU30()];
			m.activation = Traits(None)
			self.parseTraits(m.activation)


class IndentingPrintWriter:
	f = None
	indent = 0
	do_indent = True

	def __init__(self, file):
		self.f = file

	def dent(self):
		if self.do_indent:
			for i in range(0, self.indent):
				self.f.write("    ")
			self.do_indent = False

	def prnt(self, s):
		self.dent();
		self.f.write(s)

	def println(self, s):
		self.dent();
		self.f.write(s)
		self.f.write("\n")
		self.do_indent = True

class AbcThunkGen:
	abc = None
	abcs = []
	out_h = None
	out_c = None
	all_thunks = []
	lookup_traits = None

	def addAbc(self, a):
		self.abcs.append(a)
		self.lookup_traits = None

	def class_native_name(self, c):
		return ns_prefix(c.qname.ns, True) + to_cname(c.qname.name)

	def class_id_name(self, c):
		return "abcclass_" + self.class_native_name(c)

	def emit(self, abc, name, out_h, out_c):
		self.abc = abc;
		self.out_h = out_h;
		self.out_c = out_c;
		self.all_thunks = []
		self.lookup_traits = None

		for i in range(0, len(abc.scripts)):
			script = abc.scripts[i]
			if script != None:
				self.processTraits(script)

		out_h.println(MPL_HEADER);
		out_c.println(MPL_HEADER);

		out_h.println("/* machine generated file -- do not edit */");
		out_c.println("/* machine generated file -- do not edit */");

		out_h.println("#define AVMTHUNK_VERSION 4");
		
		out_h.println("extern const uint32_t "+name+"_abc_class_count;")
		out_h.println("extern const uint32_t "+name+"_abc_script_count;")
		out_h.println("extern const uint32_t "+name+"_abc_method_count;")
		out_h.println("extern const uint32_t "+name+"_abc_length;")
		out_h.println("extern const uint8_t "+name+"_abc_data[];");

		out_c.println("const uint32_t "+name+"_abc_class_count = "+str(len(abc.classes))+";");
		out_c.println("const uint32_t "+name+"_abc_script_count = "+str(len(abc.scripts))+";");
		out_c.println("const uint32_t "+name+"_abc_method_count = "+str(len(abc.methods))+";");
		out_c.println("const uint32_t "+name+"_abc_length = "+str(len(abc.data.data))+";");

		if opts.nativemapname:
			out_c.println("DECLARE_EXTERN_NATIVE_MAPS(%s)" % (opts.nativemapname));
			out_h.println("DECLARE_NATIVE_INITIALIZER(%s, %s)" % (name, opts.nativemapname));
			# this section is only needed for legacy glue code that is specifying its native maps
			# manually; it can be eliminated someday (but does no real harm)
			out_h.println("/* scripts */");
			for i in range(0, len(abc.scripts)):
				script = abc.scripts[i]
				if script == None:
					continue
				# not enough info in the ABC to recover the original name (eg abcpackage_Foo_as) 
				# so output identifiers based on the native script functions found
				for j in range(0, len(script.tmethods)):
					m = script.tmethods[j]
					if (m != None) and m.isNative():
						out_h.println("const uint32_t abcscript_"+ to_cname(m.name) + " = " + str(i) + ";") # yes, i, not j
		else:
			out_h.println("AVMTHUNK_DECLARE_NATIVE_INITIALIZER(%s)" % (name));
		
		out_h.println("/* classes */");
		for i in range(0, len(abc.classes)):
			c = abc.classes[i]
			self.out_h.println("const uint32_t " + self.class_id_name(c) + " = " + str(c.class_id) + ";");

		out_h.println("/* methods */");
		for i in range(0, len(abc.methods)):
			m = abc.methods[i]
			if m.native_id_name != None:
				assert(m.id == i)
				if m.isNative():
					out_h.println("const uint32_t "+m.native_id_name+" = "+str(m.id)+";");
				else:
					# not sure if we want to expose method id's for non-native methods; emit as comments for now
					out_h.println("/* const uint32_t "+m.native_id_name+" = "+str(m.id)+"; */");

		unique_thunk_sigs = {}
		for receiver,m in self.all_thunks:
			sig = self.thunkSig(receiver, m)
			if not unique_thunk_sigs.has_key(sig):
				unique_thunk_sigs[sig] = {}
			unique_thunk_sigs[sig][m.native_id_name] = (receiver, m)
		out_c.println("");
		out_c.println("/* thunks (%d unique signatures, %d total) */" % (len(unique_thunk_sigs.keys()), len(self.all_thunks)));
		if opts.uniquethunks:
			for receiver,m in self.all_thunks:
				thunkname = m.native_id_name;
				self.emitThunkProto(thunkname, receiver, m, False);
				self.emitThunkBody(thunkname, receiver, m, False, True);
		else:
			for sig in unique_thunk_sigs:
				users = unique_thunk_sigs[sig]
				receiver = None;
				m = None;
				for native_name in users:
					out_c.println("// "+native_name);
					receiver = users[native_name][0];
					m = users[native_name][1];
				thunkname = name+"_"+sig;
				self.emitThunkProto(thunkname, receiver, m, False);
				if opts.nativemapname:
					# emit both with-cookie and without-cookie versions, since we can't tell at this point which
					# might be used for a particular method. rely on linker to strip the unused ones. 
					self.emitThunkProto(thunkname, receiver, m, True);
				for native_name in users:
					# use #define here (rather than constants) to avoid the linker including them and thus preventing dead-stripping
					# (sad but true, happens in some environments)
					out_h.println("#define "+native_name+"_thunk  "+thunkname+"_thunk")
					if opts.nativemapname:
						out_h.println("#define "+native_name+"_thunkc "+thunkname+"_thunkc")
				out_h.println("")
				self.emitThunkBody(thunkname, receiver, m, False, False);
				if opts.nativemapname:
					self.emitThunkBody(thunkname, receiver, m, True, False);

		out_c.println("");
		for i in range(0, len(abc.classes)):
			c = abc.classes[i]
			if c.ni.gen_method_map:
				out_c.println("AVMTHUNK_NATIVE_CLASS_GLUE(%s)" % c.ni.class_name)

		out_c.println("");
		for i in range(0, len(abc.scripts)):
			script = abc.scripts[i]
			if script.ni.gen_method_map:
				out_c.println("AVMTHUNK_NATIVE_SCRIPT_GLUE(%s)" % script.ni.script_name)

		out_c.println("");
		out_c.println("AVMTHUNK_BEGIN_NATIVE_TABLES(%s)" % self.abc.scriptName)
		out_c.indent += 1

		out_c.println("");
		out_c.println("AVMTHUNK_BEGIN_NATIVE_METHODS(%s)" % self.abc.scriptName)
		out_c.indent += 1
		for i in range(0, len(abc.methods)):
			m = abc.methods[i]
			if m.isNative() and m.gen_method_map:
				assert(m.native_method_name != None)
				assert(m.native_id_name != None)
				# special-case the two oddballs of the group: String and Namespace
				# don't descend from ScriptObject and so need a little extra love.
				if str(m.receiver.name) == "String":
					nmout = "AVMTHUNK_NATIVE_METHOD_STRING"
				elif str(m.receiver.name) == "Namespace":
					nmout = "AVMTHUNK_NATIVE_METHOD_NAMESPACE"
				else:
					nmout = "AVMTHUNK_NATIVE_METHOD"
				self.out_c.println("%s(%s, %s::%s)" % (nmout, m.native_id_name, m.receiver.niname, m.native_method_name))
		out_c.indent -= 1
		out_c.println("AVMTHUNK_END_NATIVE_METHODS()")

		out_c.println("");
		out_c.println("AVMTHUNK_BEGIN_NATIVE_SCRIPTS(%s)" % self.abc.scriptName)
		out_c.indent += 1
		for i in range(0, len(abc.scripts)):
			script = abc.scripts[i]
			if script.ni.script_name != None:
				if script.ni.gen_method_map:
					out_c.println("AVMTHUNK_NATIVE_SCRIPT(%d, %s)" % (i, script.ni.script_name))
				else:
					out_c.println("NATIVE_SCRIPT(%d, %s)" % (i, script.ni.script_name))
		out_c.indent -= 1
		out_c.println("AVMTHUNK_END_NATIVE_SCRIPTS()")

		out_c.println("");
		out_c.println("AVMTHUNK_BEGIN_NATIVE_CLASSES(%s)" % self.abc.scriptName)
		out_c.indent += 1
		for i in range(0, len(abc.classes)):
			c = abc.classes[i]
			if c.ni.class_name != None or c.ni.instance_name != None:
				if c.ni.gen_method_map:
					out_c.println("AVMTHUNK_NATIVE_CLASS(%s, %s, %s)" % (self.class_id_name(c), c.ni.class_name, c.ni.instance_name))
				else:
					out_c.println("NATIVE_CLASS(%s, %s, %s)" % (self.class_id_name(c), c.ni.class_name, c.ni.instance_name))
		out_c.indent -= 1
		out_c.println("AVMTHUNK_END_NATIVE_CLASSES()")

		out_c.println("");
		out_c.indent -= 1
		out_c.println("AVMTHUNK_END_NATIVE_TABLES()")

		out_c.println("");
		if opts.nativemapname:
			out_c.println("DEFINE_NATIVE_INITIALIZER(%s, %s)" % (name, opts.nativemapname));
		else:
			out_c.println("AVMTHUNK_DEFINE_NATIVE_INITIALIZER(%s)" % (name));

		out_c.println("");
		out_c.println("/* abc */");
		n = len(abc.data.data)
		out_c.println("const uint8_t "+name+"_abc_data["+str(n)+"] = {");
		for i in range(0, n):
			x = ord(abc.data.data[i]) & 255;
			out_c.prnt("%3d" % x)
			if i+1 < n: 
				out_c.prnt(", ")
			if i%16 == 15:
				out_c.println("");
		out_c.println("};");

	def argTraits(self, receiver, m):
		argtraits = [ receiver ]
		for i in range(0, len(m.paramTypes)):
			argtraits.append(self.lookupTraits(m.paramTypes[i]))
		return argtraits

	def thunkDecl(self, name, cookie, ret):
		cstr = ""
		if cookie:
			cstr = "c"
		assert(ret != "AvmObject")
		if ret != "double":
			ret = "AvmBox"
		decl = ret+" "+name+"_thunk"+cstr+"(AvmMethodEnv env, uint32_t argc, AvmBox* argv)"
		return decl

	def emitThunkProto(self, name, receiver, m, cookie):
		ret = ctype_from_traits(self.lookupTraits(m.returnType), False);
		decl = self.thunkDecl(name, cookie, ret)
		self.out_h.println("extern "+decl+";");

	def emitThunkBody(self, name, receiver, m, cookie, directcall):
		ret = ctype_from_traits(self.lookupTraits(m.returnType), False);
		decl = self.thunkDecl(name, cookie, ret)

		self.out_c.println(decl);
		self.out_c.println("{");
		self.out_c.indent += 1;

		param_count = len(m.paramTypes);
		optional_count = m.optional_count;

		argtraits = self.argTraits(receiver, m)

		argszprev = "0"
		for i in range(0, len(argtraits)):
			cts = ctype_from_traits(argtraits[i], True);
			if i == 0:
				self.out_c.println("const uint32_t argoff0 = 0;");
			else:
				self.out_c.println("const uint32_t argoff"+str(i)+" = argoff"+str(i-1)+" + "+argszprev+";");
			argszprev = "AvmThunkArgSize_"+cts;
	
		if m.needRest():
			self.out_c.println("const uint32_t argoffV = argoff"+str(len(argtraits)-1)+" + "+argszprev+";");
		
		args = []

		for i in range(0, len(argtraits)):
			cts = ctype_from_traits(argtraits[i], True)
			val = "AvmThunkUnbox_"+cts+"(argv[argoff" + str(i) + "])";
			if directcall and cts == "AvmObject" and argtraits[i].niname != None:
				val = "(%s*)%s" % (argtraits[i].niname, val)
			# argtraits includes receiver at 0, optionalValues does not
			if i > param_count - optional_count:
				dct,defval,defvalraw = self.abc.default_ctype_and_value(m.optionalValues[i-1]);
				dts = ctype_from_enum(dct, True)
				if dts != cts:
					defval = "AvmThunkCoerce_"+dts+"_"+cts+"("+defval+")";
				val = "(argc < "+str(i)+" ? "+defval+" : "+val+")";
			args.append((val, cts))
			if i == 0 and cookie:
				assert(opts.nativemapname)
				assert(not directcall)
				args.append(("AVMTHUNK_GET_COOKIE(env)", "int32_t"))

		if m.needRest():
			args.append(("(argc <= "+str(param_count)+" ? NULL : argv + argoffV)", "AvmBox*"))
			args.append(("(argc <= "+str(param_count)+" ? 0 : argc - "+str(param_count)+")", "uint32_t"))

		if not m.hasOptional() and not m.needRest():
			self.out_c.println("(void)argc;");

		self.out_c.println("AVMTHUNK_DEBUG_ENTER(env)");
		
		if directcall:
			self.out_c.println("(void)env;") # avoid "unreferenced formal parameter" in non-debugger builds
			self.out_c.println("%s* obj = %s;" % (m.receiver.niname, args[0][0]))
			# many setters are declared as returning "undefined" in as3 but return "void" in C++.
			# quietly ignore the C++ result. likewise, native ctors always return "undefined" in AS3
			# but typically are void in C++. (can't do this for non-directcall as sig might be shared between
			# a setter and nonsetter)
			if m.kind == TRAIT_Setter or m == m.receiver.init:
				ret = "void"
			if ret != "void":
				self.out_c.prnt("const %s ret = (%s)" % (ret, ret))
			self.out_c.println("obj->%s(" % m.native_method_name)
			self.out_c.indent += 1
			for i in range(1, len(args)):
				if i > 1:
					self.out_c.prnt(", ")
				self.out_c.println(args[i][0]);
			self.out_c.indent -= 1
			self.out_c.println(");")
		else:
			self.out_c.prnt("typedef AvmRetType_%s (%sT::*FuncType)(" % (ret, args[0][1]))
			for i in range(1, len(args)):
				if i > 1:
					self.out_c.prnt(", ")
				self.out_c.prnt(args[i][1]);
			self.out_c.println(");");
			self.out_c.println("const FuncType func = reinterpret_cast<FuncType>(AVMTHUNK_GET_HANDLER(env));")
			if ret != "void":
				self.out_c.prnt("const %s ret = " % ret)
			self.out_c.println("(*(%s).*(func))(" % (args[0][0]))
			self.out_c.indent += 1
			for i in range(1, len(args)):
				if i > 1:
					self.out_c.prnt(", ")
				self.out_c.println(args[i][0]);
			self.out_c.indent -= 1
			self.out_c.println(");")

		self.out_c.println("AVMTHUNK_DEBUG_EXIT(env)")

		if ret == "void":
			self.out_c.println("return kAvmThunkUndefined;")
		elif ret == "double":
			self.out_c.println("return ret;")
		else:
			self.out_c.println("return AvmBox(ret);")
		self.out_c.indent -= 1
		self.out_c.println("}")

	def lookupTraits(self, name):
		name = str(name)
		if self.lookup_traits == None:
			self.lookup_traits = {}
			self.lookup_traits["*"] = NULL
			self.lookup_traits["void"] = UNDEFINED
			for a in self.abcs:
				for t in a.scripts:
					if self.lookup_traits.has_key(str(t)):
						raise Error("duplicate name found: " + name)
					self.lookup_traits[str(t)] = t
				for t in a.classes:
					if self.lookup_traits.has_key(str(t)):
						raise Error("duplicate name found: " + name)
					self.lookup_traits[str(t)] = t
				for t in a.instances:
					if self.lookup_traits.has_key(str(t)):
						raise Error("duplicate name found: " + name)
					self.lookup_traits[str(t)] = t
		if not self.lookup_traits.has_key(name):
			raise Error("name not found: " + name)
		return self.lookup_traits[name]
		
	def thunkSig(self, receiver, m):
		sig = sigchar_from_traits(self.lookupTraits(m.returnType), False)+"2";
		if m.returnType.name == "Number":
			sig += "d"
		else:
			sig += "a"
		sig += "_";
		argtraits = self.argTraits(receiver, m)
		for i in range(0, len(argtraits)):
			sig += sigchar_from_traits(argtraits[i], True)
		if m.hasOptional():
			param_count = len(m.paramTypes)
			for i in range(param_count - m.optional_count, param_count):
				dct,defval,defvalraw = self.abc.default_ctype_and_value(m.optionalValues[i]);
				sig += "_opt" + sigchar_from_enum(dct, True) + to_cname(defval)
		if m.needRest():
			sig += "_rest"
		return sig;

	def gatherThunk(self, receiver, m):
		assert(m.native_id_name != None)
		self.all_thunks.append((receiver, m))	

	def processClass(self, b):
		c = b.value
		self.processTraits(c)
		self.processTraits(c.itraits)

	def processMethod(self, receiver, m):
		if m.isNative():
			self.gatherThunk(receiver, m)

	def processTraits(self, s):
		if s.init != None:
			if s.init.isNative():
				raise Error("native constructors are not allowed: " + str(s))
			self.processMethod(s, s.init)
		for i in range(0, len(s.members)):
			if s.members[i].kind in [TRAIT_Method,TRAIT_Getter,TRAIT_Setter]:
				self.processMethod(s, s.members[i])
			elif s.members[i].kind in [TRAIT_Class]:
				self.processClass(s.members[i]);
	
ngen = AbcThunkGen();
abcGenFor = None
abcGenName = ""
for file in args:
	try:
		f = open(file,"rb")
		data = f.read()
	finally:
		f.close()

	abcScriptName = os.path.splitext(os.path.split(file)[1])[0]
	#print "read %s" % abcScriptName
	abcGenFor = Abc(data, abcScriptName)
	ngen.addAbc(abcGenFor)
	abcGenName = os.path.splitext(file)[0]

if abcGenFor:
	hf = None
	hc = None
	try:
		hf = open(abcGenName+".h2","w")
		hc = open(abcGenName+".cpp2","w")
		h = IndentingPrintWriter(hf)
		c = IndentingPrintWriter(hc)
		ngen.emit(abcGenFor, abcScriptName, h, c);
	except Exception, e:
		sys.stderr.write("ERROR: "+str(e)+"\n")
		exit(1)
	finally:
		if hf != None:
			hf.close()
		if hc != None:
			hc.close()
