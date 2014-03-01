/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.display
{
	/**
	 * The Scene class includes properties for identifying the name, labels, and number of frames in a scene.
	 * A Scene object instance is created in Flash Professional, not by writing ActionScript code.
	 * The MovieClip class includes a <code>currentScene</code> property,
	 * which is a Scene object that identifies the scene in which the playhead is located
	 * in the timeline of the MovieClip instance.
	 * The <code>scenes</code> property of the MovieClip class is an array of Scene objects.
	 * Also, the <code>gotoAndPlay()</code> and <code>gotoAndStop()</code> methods of the
	 * MovieClip class use Scene objects as parameters.
	 * 
     * @langversion 3.0
     * @playerversion Flash 9
     * @playerversion AIR 1.0
     * 
     * @see MovieClip.currentScene
     * @see MovieClip.scenes
     * @see MovieClip.gotoAndPlay()
     * @see MovieClip.gotoAndStop()
	 */
	public final class Scene
	{
        private var _name:String;
        private var _labels:Array;
        private var _numFrames:int;

		public function Scene( name:String, labels:Array, numFrames:int )
		{
			super();
			_name      = name;
			_labels    = labels;
			_numFrames = numFrames;
		}

		/**
		 * The name of the scene.
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 1.0
		 */
		public function get name():String { return _name; }

		/**
		 * An array of FrameLabel objects for the scene.
		 * Each FrameLabel object contains a <code>frame</code> property,
		 * which specifies the frame number corresponding to the label, and a <code>name</code> property.
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 1.0
	     * 
	     * @see FrameLabel
		 */
		public function get labels():Array { return _labels; }

		/**
		 * The number of frames in the scene.
		 * 
	     * @langversion 3.0
	     * @playerversion Flash 9
	     * @playerversion AIR 1.0
		 */
		public function get numFrames():int { return _numFrames; }
	}
}
