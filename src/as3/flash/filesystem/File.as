/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.filesystem
{
	
     /**
      * A File object represents a path to a file or directory.
      * This can be an existing file or directory, or it can be one
      * that does not yet exist; for instance, it can represent the path
      * to a file or directory that you plan to create.
      * 
      * @langversion 3.0
      * @playerversion AIR 1.0
      */
     [API(AVMGLUE::AIR_1_0)]
     [native(cls="::avmshell::FileGlueClass", instance="::avmshell::FileGlueObject", methods="auto")]
     public class File
	{
          
          /**
           * Native dummy function.
           *
           * @langversion 3.0
           * @playerversion AVM 0.4
           */
          public native static function isDummy():Boolean;

          /**
           * Native dummy function.
           *
           * @langversion 3.0
           * @playerversion AVM 0.4
           */
          public native function isLocalDummy():Boolean;
          
          private static const pathIsURL:RegExp = /^ (file | app | app-storage ) : /xi;

          /**
           * The constructor function for the File class.
           * 
           * @param path The path to the file.
           *             You can specify the path by using either a URL
           *             or native path (platform-specific) notation.
           *
           * @langversion 3.0
           * @playerversion AIR 1.0
           */
          [API(AVMGLUE::AIR_1_0)]
          public function File( path:String = null )
          {
               super();

               if( path != null )
               {
                    if( pathIsURL.test( path ) )
                    {
                         url = path;
                    }
                    else
                    {
                         nativePath = path;
                    }
               }
          }

          private var _url:String = "";

          /**
           * The URL for this file path.
           *
           * @langversion 3.0
           * @playerversion AIR 1.0
           */
          [API(AVMGLUE::AIR_1_0)]
          public function get url():String
          {
               return _url;
          }

          /** @private */
          [API(AVMGLUE::AIR_1_0)]
          public function set url( value:String ):void
          {
               _url = value;
          }

          private var _nativePath:String = "";

          /**
           * The full path in the host operating system representation.
           *
           * @langversion 3.0
           * @playerversion AIR 1.0
           */
          [API(AVMGLUE::AIR_1_0)]
          public function get nativePath():String
          {
               return _nativePath;
          }

          /** @private */
          [API(AVMGLUE::AIR_1_0)]
          public function set nativePath( value:String ):void
          {
               _nativePath = value;
          }

     }

}