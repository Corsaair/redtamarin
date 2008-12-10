/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1/GPL 2.0/LGPL 2.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is [Open Source Virtual Machine.].
 *
 * The Initial Developer of the Original Code is
 * Adobe System Incorporated.
 * Portions created by the Initial Developer are Copyright (C) 2008
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Adobe AS3 Team
 *
 * Alternatively, the contents of this file may be used under the terms of
 * either the GNU General Public License Version 2 or later (the "GPL"), or
 * the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),
 * in which case the provisions of the GPL or the LGPL are applicable instead
 * of those above. If you wish to allow use of your version of this file only
 * under the terms of either the GPL or the LGPL, and not to allow others to
 * use your version of this file under the terms of the MPL, indicate your
 * decision by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL or the LGPL. If you do not delete
 * the provisions above, a recipient may use your version of this file under
 * the terms of any one of the MPL, the GPL or the LGPL.
 *
 * ***** END LICENSE BLOCK ***** */

package avmplus
{
	// -------------- internal --------------
	
	[native(cls="DescribeTypeClass", methods="auto")]
	// no instance
	internal class DescribeType
	{
		internal native static function describeTypeJSON(o:*, flags:uint):Object;
	}
	
	internal function describeParams(x:XML, parameters:Object):void
	{
		for (var i in parameters)
		{
			var p = parameters[i];
			var f:XML = <parameter index={i+1} type={p.type} optional={p.optional}/>
			x.appendChild(f);
		}
	}

	internal function describeMetadata(x:XML, metadata:Array):void
	{
		for each (var md in metadata)
		{
			var m:XML = <metadata name={md.name}/>
			for each (var i in md.value)
			{
				var a:XML = <arg key={i.key} value={i.value}/>
				m.appendChild(a);
			}
			x.appendChild(m);
		}
	}

	internal function finish(x:XML, e:XML, i:Object):void
	{
		e.@name = i.name;
		if (i.uri !== null) e.@uri = i.uri;
		if (i.metadata !== null) describeMetadata(e, i.metadata);
		x.appendChild(e);
	}
	
	internal function describeTraits(x:XML, traits:Object):void
	{
		for each (var i in traits.bases)
		{
			var e:XML = <extendsClass type={i}/>
			x.appendChild(e);
		}
		for each (var i in traits.interfaces)
		{
			var e:XML = <implementsInterface type={i}/>
			x.appendChild(e);
		}
		for each (var i in traits.variables)
		{
			var e:XML = (i.access == "readonly") ? <constant/> : <variable/>
			e.@type= i.type;
			finish(x, e, i);
		}
		for each (var i in traits.accessors)
		{
			var e:XML = <accessor access={i.access} type={i.type} declaredBy={i.declaredBy}/>
			finish(x, e, i);
		}
		for each (var i in traits.methods)
		{
			var e:XML = <method returnType={i.returnType} declaredBy={i.declaredBy}/>
			describeParams(e, i.parameters);
			finish(x, e, i);
		}
		describeMetadata(x, traits.metadata);
		if (traits.constructor !== null)
		{
			var e:XML = <constructor/>
			describeParams(e, traits.constructor);
			x.appendChild(e);
		}
	}

	// -------------- public --------------

	// this bit replicates a bug in Flash9/10, where a method that uses a custom namespace
	// won't be in the output if any of its base classes (or interfaces) also define a method
	// in that custom namespace.
	public const HIDE_NSURI_METHODS:uint	= 0x0001;
	public const INCLUDE_BASES:uint			= 0x0002;
	public const INCLUDE_INTERFACES:uint	= 0x0004;
	public const INCLUDE_VARIABLES:uint		= 0x0008;
	public const INCLUDE_ACCESSORS:uint		= 0x0010;
	public const INCLUDE_METHODS:uint		= 0x0020;
	public const INCLUDE_METADATA:uint		= 0x0040;
	public const INCLUDE_CONSTRUCTOR:uint	= 0x0080;
	public const INCLUDE_TRAITS:uint		= 0x0100;
	public const USE_ITRAITS:uint			= 0x0200;
	// if set, hide everything from the base Object class
	public const HIDE_OBJECT:uint			= 0x0400;

	// set of flags that replicates the behavior of flash.util.describeType in FlashPlayer 9 & 10
	public const FLASH10_FLAGS:uint =	INCLUDE_BASES |
										INCLUDE_INTERFACES |
										INCLUDE_VARIABLES |
										INCLUDE_ACCESSORS |
										INCLUDE_METHODS |
										INCLUDE_METADATA |
										INCLUDE_CONSTRUCTOR |
										INCLUDE_TRAITS |
										// include this buggy behavior by default, to match legacy Flash behavior
										HIDE_NSURI_METHODS |
										// Flash hides everything in class Object
										HIDE_OBJECT;

	public function describeType(value:*, flags:uint):XML
	{
		var o:Object = DescribeType.describeTypeJSON(value, flags);
		var x:XML = <type name={o.name} isDynamic={o.isDynamic} isFinal={o.isFinal} isStatic={o.isStatic}/>
		if (o.traits.bases.length)
			x.@base = o.traits.bases[0];
		describeTraits(x, o.traits);
		
		var oi:Object = DescribeType.describeTypeJSON(value, flags | USE_ITRAITS);
		if (oi !== null)
		{
			var e:XML = <factory type={oi.name}/>
			describeTraits(e, oi.traits);
			x.appendChild(e);
		}

		return x;
	}
	
	public function getQualifiedClassName(value:*):String
	{
		return DescribeType.describeTypeJSON(value, 0).name;
	}
	
	public function getQualifiedSuperclassName(value:*):String
	{
		// getQualifiedSuperclassName explicitly allows us to pass Class or Instance,
		// and either should resolve to super of Instance
		var o = DescribeType.describeTypeJSON(value, USE_ITRAITS | INCLUDE_TRAITS | INCLUDE_BASES);
		if (!o)
			o = DescribeType.describeTypeJSON(value, INCLUDE_TRAITS | INCLUDE_BASES);
		var bases = o.traits.bases;
		var base = bases.length ? bases[0] : null;
		if (base == "Class")
			base = null;
		return base;
	}
}
