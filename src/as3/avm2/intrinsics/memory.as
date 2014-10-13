/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

// DOCUMENTATION ONLY - DO NOT COMPILE IN ABC/SWC
package avm2.intrinsics.memory
{
    /**
     * @internal
     * DO NOT TRY TO COMPILE THIS FILE
     * THIS IS A MOCKUP TO DOCUMENT AN INTERNAL API OF THE AVM2
     */

    /**
     * @name The XC API.
     *
     * <p>
     * <b>XC</b> stands for "cross C", previously know as <b>Alchemy</b>,
     * and also known as <b>fast memory opcodes</b>, <b>fast mem ops</b>, <b>mops</b>, etc.
     * </p>
     *
     * @langversion 3.0
     * @playerversion Flash 11.6
     * @playerversion AIR 11.6
     * 
     * @see http://obtw.wordpress.com/2013/04/03/making-bytearray-faster/ Making ByteArray faster
     * @see http://www.adobe.com/devnet/air/articles/faster-byte-array-operations.html Faster byte array operations with ASC2
     * @see http://plus.google.com/117271975527324598054/posts/GABhwnhkupF fast mem ops a bit more details
     * @see http://makc3d.wordpress.com/2013/04/11/as3-and-alchemy/ Can AS3 and Alchemy be friends?
     * @see http://jacksondunstan.com/articles/2314 An ASC 2.0 Domain Memory Opcodes Primer
     * @see http://pastebin.com/dPjcqT34 Alchemy vs AS3 member access
     * @see http://pastie.org/7422818 xctest
     */

    /**
     * Load 8 bit <code>integer</code>.
     * 
     * <p>
     * Load a 8 bit, little-endian, unsigned integer from global memory.
     * </p>
     * 
     * <p>
     * The MOPS opcodes all access the backing store of the ByteArray represented
     * by the current app domain's <code>ApplicationDomain.domainMemory</code> property.
     * </p>
     * 
     * <p>
     * Address ranges for accesses will be range checked using standard comparisons.
     * No address alignment is necessary.
     * </p>
     * 
     * <p>
     * opcode <b>li8</b> = <code>53</code> (<code>0x35</code>).
     * </p>
     * 
     * @langversion 3.0
     * @playerversion Flash 11.6
     * @playerversion AIR 11.6
     * 
     * @throws RangeError Range check failures will result in an <code>InvalidRangeError</code> exception.
     */
	public native function li8( addr:int ):int;

    /**
     * Load 16 bit <code>integer</code>.
     *
     * <p>
     * Load a 16 bit, little-endian, unsigned integer from global memory.
     * </p>
     * 
     * <p>
     * The MOPS opcodes all access the backing store of the ByteArray represented
     * by the current app domain's <code>ApplicationDomain.domainMemory</code> property.
     * </p>
     * 
     * <p>
     * Address ranges for accesses will be range checked using standard comparisons.
     * No address alignment is necessary.
     * </p>
     * 
     * <p>
     * opcode <b>li16</b> = <code>54</code> (<code>0x36</code>).
     * </p>
     * 
     * @langversion 3.0
     * @playerversion Flash 11.6
     * @playerversion AIR 11.6
     * 
     * @throws RangeError Range check failures will result in an <code>InvalidRangeError</code> exception.
     */
	public native function li16( addr:int ):int;

    /**
     * Load 32 bit <code>integer</code>.
     *
     * <p>
     * Load a 32 bit, little-endian, signed integer from global memory.
     * </p>
     * 
     * <p>
     * The MOPS opcodes all access the backing store of the ByteArray represented
     * by the current app domain's <code>ApplicationDomain.domainMemory</code> property.
     * </p>
     * 
     * <p>
     * Address ranges for accesses will be range checked using standard comparisons.
     * No address alignment is necessary.
     * </p>
     * 
     * <p>
     * opcode <b>li32</b> = <code>55</code> (<code>0x37</code>).
     * </p>
     * 
     * @langversion 3.0
     * @playerversion Flash 11.6
     * @playerversion AIR 11.6
     * 
     * @throws RangeError Range check failures will result in an <code>InvalidRangeError</code> exception.
     */
	public native function li32( addr:int ):int;

    /**
     * Load 32 bit <code>float</code>.
     *
     * <p>
     * Load a 32 bit (IEEE 754), little-endian, float from global memory
     * and promote to 64 bit (IEEE 754) double/Number.
     * </p>
     * 
     * <p>
     * The MOPS opcodes all access the backing store of the ByteArray represented
     * by the current app domain's <code>ApplicationDomain.domainMemory</code> property.
     * </p>
     * 
     * <p>
     * Address ranges for accesses will be range checked using standard comparisons.
     * No address alignment is necessary.
     * </p>
     * 
     * <p>
     * opcode <b>lf32</b> = <code>56</code> (<code>0x38</code>).
     * </p>
     * 
     * @langversion 3.0
     * @playerversion Flash 11.6
     * @playerversion AIR 11.6
     * 
     * @throws RangeError Range check failures will result in an <code>InvalidRangeError</code> exception.
     */
	public native function lf32( addr:int ):Number;

    /**
     * Load 64 bit <code>float</code>.
     * 
     * <p>
     * Load a 64 bit (IEEE 754), little-endian, float from global memory
     * and promote to 64 bit (IEEE 754) double/Number.
     * </p>
     * 
     * <p>
     * The MOPS opcodes all access the backing store of the ByteArray represented
     * by the current app domain's <code>ApplicationDomain.domainMemory</code> property.
     * </p>
     * 
     * <p>
     * Address ranges for accesses will be range checked using standard comparisons.
     * No address alignment is necessary.
     * </p>
     * 
     * <p>
     * opcode <b>lf64</b> = <code>57</code> (<code>0x39</code>).
     * </p>
     * 
     * @langversion 3.0
     * @playerversion Flash 11.6
     * @playerversion AIR 11.6
     * 
     * @throws RangeError Range check failures will result in an <code>InvalidRangeError</code> exception.
     */
	public native function lf64( addr:int ):Number;

    /**
     * Store 8 bit <code>integer</code>.
     * 
     * <p>
     * Store a 8 bit integer to global memory.
     * </p>
     * 
     * <p>
     * The value is converted to integer using the equivalent of <code>convert_i</code>,
     * then the least significant 8 bits are stored.
     * </p>
     * 
     * <p>
     * The MOPS opcodes all access the backing store of the ByteArray represented
     * by the current app domain's <code>ApplicationDomain.domainMemory</code> property.
     * </p>
     * 
     * <p>
     * Address ranges for accesses will be range checked using standard comparisons.
     * </p>
     * 
     * <p>
     * opcode <b>si8</b> = <code>58</code> (<code>0x3A</code>).
     * </p>
     * 
     * @langversion 3.0
     * @playerversion Flash 11.6
     * @playerversion AIR 11.6
     * 
     * @throws RangeError Range check failures will result in an <code>InvalidRangeError</code> exception.
     */
	public native function si8(value:int, addr:int):void;

    /**
     * Store 16 bit <code>integer</code>.
     * 
     * <p>
     * Store a 16 bit integer to global memory.
     * </p>
     * 
     * <p>
     * The value is converted to integer using the equivalent of <code>convert_i</code>,
     * then the least significant 16 bits are stored as two bytes in little-endian order.
     * </p>
     * 
     * <p>
     * The MOPS opcodes all access the backing store of the ByteArray represented
     * by the current app domain's <code>ApplicationDomain.domainMemory</code> property.
     * </p>
     * 
     * <p>
     * Address ranges for accesses will be range checked using standard comparisons.
     * </p>
     * 
     * <p>
     * opcode <b>si16</b> = <code>59</code> (<code>0x3B</code>).
     * </p>
     * 
     * @langversion 3.0
     * @playerversion Flash 11.6
     * @playerversion AIR 11.6
     * 
     * @throws RangeError Range check failures will result in an <code>InvalidRangeError</code> exception.
     */
	public native function si16(value:int, addr:int):void;

    /**
     * Store 32 bit <code>integer</code>.
     * 
     * <p>
     * Store a 32 bit integer to global memory.
     * </p>
     * 
     * <p>
     * The value is converted to integer using the equivalent of <code>convert_i</code>,
     * then the 32 bits are stored as four bytes in little-endian order.
     * </p>
     * 
     * <p>
     * The MOPS opcodes all access the backing store of the ByteArray represented
     * by the current app domain's <code>ApplicationDomain.domainMemory</code> property.
     * </p>
     * 
     * <p>
     * Address ranges for accesses will be range checked using standard comparisons.
     * </p>
     * 
     * <p>
     * opcode <b>si32</b> = <code>60</code> (<code>0x3C</code>).
     * </p>
     * 
     * @langversion 3.0
     * @playerversion Flash 11.6
     * @playerversion AIR 11.6
     * 
     * @throws RangeError Range check failures will result in an <code>InvalidRangeError</code> exception.
     */
	public native function si32(value:int, addr:int):void;

    /**
     * Store 32 bit <code>float</code>.
     * 
     * <p>
     * Store a 32 bit (IEEE 754) float to global memory.
     * </p>
     * 
     * <p>
     * The input value is converted to Number using the equivalent of <code>convert_d</code>,
     * truncated to 32-bit float, then stored as four bytes in little-endian order.
     * </p>
     * 
     * <p>
     * The MOPS opcodes all access the backing store of the ByteArray represented
     * by the current app domain's <code>ApplicationDomain.domainMemory</code> property.
     * </p>
     * 
     * <p>
     * Address ranges for accesses will be range checked using standard comparisons.
     * </p>
     * 
     * <p>
     * opcode <b>sf32</b> = <code>61</code> (<code>0x3D</code>).
     * </p>
     * 
     * @langversion 3.0
     * @playerversion Flash 11.6
     * @playerversion AIR 11.6
     * 
     * @throws RangeError Range check failures will result in an <code>InvalidRangeError</code> exception.
     */
	public native function sf32(value:Number, addr:int):void;

    /**
     * Store 64 bit <code>float</code>.
     * 
     * <p>
     * Store a 64 bit (IEEE 754) float to global memory.
     * </p>
     * 
     * <p>
     * The input value is converted to Number using the equivalent of <code>convert_d</code>,
     * then stored as eight bytes in little endian order.
     * </p>
     * 
     * <p>
     * The MOPS opcodes all access the backing store of the ByteArray represented
     * by the current app domain's <code>ApplicationDomain.domainMemory</code> property.
     * </p>
     * 
     * <p>
     * Address ranges for accesses will be range checked using standard comparisons.
     * </p>
     * 
     * <p>
     * opcode <b>sf64</b> = <code>62</code> (<code>0x3E</code>).
     * </p>
     * 
     * @langversion 3.0
     * @playerversion Flash 11.6
     * @playerversion AIR 11.6
     * 
     * @throws RangeError Range check failures will result in an <code>InvalidRangeError</code> exception.
     */
	public native function sf64(value:Number, addr:int):void;



    /**
     * Sign extend a <code>1 bit</code> value to <code>32 bits</code>.
     * 
     * <p>
     * Convert value to integer using the equivalent of <code>convert_i</code>,
     * then copy bit 0 to bits 1-31.
     * </p>
     * 
     * <p>
     * The result is a signed 32-bit integer.
     * </p>
     * 
     * <p>
     * opcode <b>sxi1</b> = <code>80</code> (<code>0x50</code>).
     * </p>
     * 
     * @langversion 3.0
     * @playerversion Flash 11.6
     * @playerversion AIR 11.6
     */
	public native function sxi1(value:int):int;

    /**
     * Sign extend a <code>8 bit</code> value to <code>32 bits</code>.
     * 
     * <p>
     * Convert value to integer using the equivalent of <code>convert_i</code>,
     * then copy bit 7 to bits 8-31.
     * </p>
     * 
     * <p>
     * The result is a signed 32-bit integer.
     * </p>
     * 
     * <p>
     * opcode <b>sxi8</b> = <code>81</code> (<code>0x51</code>).
     * </p>
     * 
     * @langversion 3.0
     * @playerversion Flash 11.6
     * @playerversion AIR 11.6
     */
	public native function sxi8(value:int):int;

    /**
     * Sign extend a <code>16 bit</code> value to <code>32 bits</code>.
     * 
     * <p>
     * Convert value to integer using the equivalent of <code>convert_i</code>,
     * then copy bit 15 to bits 16-31.
     * </p>
     * 
     * <p>
     * The result is a signed 32-bit integer.
     * </p>
     * 
     * <p>
     * opcode <b>sxi16</b> = <code>82</code> (<code>0x52</code>).
     * </p>
     * 
     * @langversion 3.0
     * @playerversion Flash 11.6
     * @playerversion AIR 11.6
     */
	public native function sxi16(value:int):int;

    /**
     * A complete memory barrier for domainMemory (for both load and store instructions).
     *
     * @langversion 3.0
     * @playerversion Flash 11.6
     * @playerversion AIR 11.6
     */
	public native function mfence():void;

    /**
     * A compare and swap for domainMemory.
     * 
     * <p>
     * Behaves like <code>ByteArray.atomicCompareAndSwapIntAt</code> but operates on the current domainMemory.
     * </p>
     *
     * @langversion 3.0
     * @playerversion Flash 11.6
     * @playerversion AIR 11.6
     */
	public native function casi32( addr:int, expectedVal:int, newVal:int ):int;

}