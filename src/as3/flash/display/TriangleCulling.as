/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.display
{
	/**
	 * Defines codes for culling algorithms that determine which triangles
	 * not to render when drawing triangle paths.
	 * 
	 * <p>
	 * The terms <code>POSITIVE</code> and <code>NEGATIVE</code> refer to the sign
	 * of a triangle's normal along the z-axis.
	 * The normal is a 3D vector that is perpendicular to the surface of the triangle.
	 * </p>
	 * 
	 * <p>
	 * A triangle whose vertices 0, 1, and 2 are arranged in a clockwise order
	 * has a positive normal value.
	 * That is, its normal points in a positive z-axis direction,
	 * away from the current view point.
	 * When the <code>TriangleCulling.POSITIVE</code> algorithm is used,
	 * triangles with positive normals are not rendered.
	 * Another term for this is backface culling.
	 * </p>
	 * 
	 * <p>
	 * A triangle whose vertices are arranged in a counter-clockwise order
	 * has a negative normal value.
	 * That is, its normal points in a negative z-axis direction,
	 * toward the current view point.
	 * When the <code>TriangleCulling.NEGATIVE</code> algorithm is used,
	 * triangles with negative normals will not be rendered.
	 * </p>
	 * 
     * @langversion 3.0
     * @playerversion Flash 10
     * @playerversion AIR 1.5
     * 
     * @see flash.display.Graphics#drawTriangles()
     * @see flash.display.GraphicsTrianglePath
     * @see Introduction to 3D Vectors
     * @see 3D Backface Culling
	 */
	[API(AVMGLUE::FP_10_0,AVMGLUE::AIR_1_5)]
	public final class TriangleCulling
	{
		/**
		 * Specifies no culling.
		 * All triangles in the path are rendered.
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 10
	     * @playerversion AIR 1.5
		 */
        public static const NONE:String = "none";

		/**
		 * Specifies culling of all triangles facing away from the current view point.
		 * This is also known as backface culling.
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 10
	     * @playerversion AIR 1.5
		 */
        public static const POSITIVE:String = "positive";

		/**
		 * Specifies culling of all triangles facing toward the current view point.
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 10
	     * @playerversion AIR 1.5
		 */
        public static const NEGATIVE:String = "negative";
	}
}
