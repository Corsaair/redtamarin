/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.net
{
	/**
	 * A URLRequestHeader object encapsulates a single HTTP request header
	 * and consists of a name/value pair.
	 * URLRequestHeader objects are used in the <code>requestHeaders</code> property of the URLRequest class.
	 *
	 * <p>
	 * In Adobe&#xAE; AIR&#xAE;, content in the application security sandbox
	 * (such as content installed with the AIR application) can use any request headers, without error.
	 * However, for content running in Adobe AIR that is in a different security sandbox,
	 * or for content running in Flash&#xAE; Player, using following request headers cause
	 * a runtime error to be thrown, and the restricted terms are not case-sensitive
	 * (for example, <code>Get</code>, <code>get</code>, and <code>GET</code> are each not allowed):
	 * </p>
	 *
	 * <p>
	 * In Flash Player and in Adobe AIR content outside of the application security sandbox,
	 * the following request headers cannot be used, and the restricted terms are not case-sensitive
	 * (for example, <code>Get</code>, <code>get</code>, and <code>GET</code> are all not allowed).
	 * Also, hyphenated terms apply if an underscore character is used
	 * (for example, both <code>Content-Length</code> and <code>Content_Length</code> are not allowed):
	 * </p>
	 *
	 * <p>
	 * <code>Accept-Charset</code>, <code>Accept-Encoding</code>, <code>Accept-Ranges</code>, <code>Age</code>,
	 * <code>Allow</code>, <code>Allowed</code>, <code>Authorization</code>, <code>Charge-To</code>,
	 * <code>Connect</code>, <code>Connection</code>, <code>Content-Length</code>, <code>Content-Location</code>, 
	 * <code>Content-Range</code>, <code>Cookie</code>, <code>Date</code>, <code>Delete</code>, <code>ETag</code>,
	 * <code>Expect</code>, <code>Get</code>, <code>Head</code>, <code>Host</code>, <code>If-Modified-Since</code>,
	 * <code>Keep-Alive</code>, <code>Last-Modified</code>, <code>Location</code>, <code>Max-Forwards</code>,
	 * <code>Options</code>, <code>Origin</code>, <code>Post</code>, <code>Proxy-Authenticate</code>,
	 * <code>Proxy-Authorization</code>, <code>Proxy-Connection</code>, <code>Public</code>, <code>Put</code>,
	 * <code>Range</code>, <code>Referer</code>, <code>Request-Range</code>, <code>Retry-After</code>,
	 * <code>Server</code>, <code>TE</code>, <code>Trace</code>, <code>Trailer</code>, <code>Transfer-Encoding</code>,
	 * <code>Upgrade</code>, <code>URI</code>, <code>User-Agent</code>, <code>Vary</code>, <code>Via</code>,
	 * <code>Warning</code>, <code>WWW-Authenticate</code>, <code>x-flash-version</code>.
	 * </p>
	 * 
	 * <p>
	 * URLRequestHeader objects are restricted in length.
	 * If the cumulative length of a URLRequestHeader object
	 * (the length of the <code>name</code> property plus the <code>value</code> property)
	 * or an array of URLRequestHeader objects used in the <code>URLRequest.requestHeaders</code>
	 * property exceeds the acceptable length, an exception is thrown.
	 * </p>
	 *
	 * <p>
	 * Content running in Adobe AIR sets the <code>ACCEPT</code> header to the following,
	 * unless you specify a setting for the <code>ACCEPT</code> header in the <code>requestHeaders</code>
	 * property of the URLRequest class:
	 * </p>
	 *
	 * <p>
	 * <code>text/xml</code>, <code>application/xml</code>, <code>application/xhtml+xml</code>,
	 * <code>text/html;q=0.9</code>, <code>text/plain;q=0.8</code>, <code>image/png</code>,
	 * <code>application/x-shockwave-flash</code>, <code>video/mp4;q=0.9</code>,
	 * <code>flv-application/octet-stream;q=0.8</code>, <code>video/x-flv;q=0.7</code>,
	 * <code>audio/mp4</code>, <code>&#42;/&#42;;q=0.5</code>
	 * </p>
	 *
	 * <p>
	 * Not all methods that accept URLRequest parameters support the <code>requestHeaders</code> property,
	 * consult the documentation for the method you are calling.
	 * For example, the <code>FileReference.upload()</code> and <code>FileReference.download()</code> methods
	 * do not support the <code>URLRequest.requestHeaders</code> property.
	 * </p>
	 *
	 * <p>
	 * Due to browser limitations, custom HTTP request headers are only supported
	 * for <code>POST</code> requests, not for <code>GET</code> requests.
	 * </p>
	 * 
	 * @example
	 * The following example adds a single HTTP request header <code>header</code> to the array
	 * for the <code>requestHeaders</code> property.
	 * The header indicates that the application should forward the request to the origin server
	 * even if it has a cached copy of what is being requested.
	 * 
	 * <listing>
	 * package
	 * {
	 * 		import flash.display.Sprite;
	 * 		import flash.events.*;
	 * 		import flash.net.URLLoader;
	 * 		import flash.net.URLRequest;
	 * 		import flash.net.URLRequestHeader;
	 * 		import flash.net.URLRequestMethod;
	 * 		import flash.net.URLVariables;
	 *
	 * 		public class URLRequestHeaderExample extends Sprite
	 * 		{
	 * 			private var loader:URLLoader;
	 *			
	 * 			public function URLRequestHeaderExample()
	 * 			{
	 * 				loader = new URLLoader();
	 * 				configureListeners( loader );
	 * 
	 * 				var header:URLRequestHeader = new URLRequestHeader( "pragma", "no-cache" );
	 * 				var request:URLRequest = new URLRequest( "http://www.[yourdomain].com/greeting.cfm" );
	 * 				request.data = new URLVariables( "name=John+Doe" );
	 * 				request.method = URLRequestMethod.POST;
	 * 				request.requestHeaders.push( header );
	 * 
	 * 				try
	 * 				{
	 * 					loader.load( request );
	 * 				}
	 * 				catch( error:Error )
	 * 				{
	 * 					trace( "Unable to load requested document." );
	 * 				}
	 * 			}
	 * 
	 * 			private function configureListeners( dispatcher:IEventDispatcher ):void
	 * 			{
	 * 				dispatcher.addEventListener( Event.COMPLETE, completeHandler );
	 * 				dispatcher.addEventListener( Event.OPEN, openHandler );
	 * 				dispatcher.addEventListener( ProgressEvent.PROGRESS, progressHandler );
	 * 				dispatcher.addEventListener( SecurityErrorEvent.SECURITY_ERROR, securityErrorHandler );
	 * 				dispatcher.addEventListener( HTTPStatusEvent.HTTP_STATUS, httpStatusHandler );
	 * 				dispatcher.addEventListener( IOErrorEvent.IO_ERROR, ioErrorHandler );
	 * 			}
	 * 
	 * 			private function completeHandler( event:Event ):void
	 * 			{
	 * 				var loader:URLLoader = URLLoader( event.target );
	 * 				trace( "completeHandler: " + loader.data );
	 * 			}
	 * 
	 * 			private function openHandler( event:Event ):void
	 * 			{
	 * 				trace( "openHandler: " + event );
	 * 			}
	 * 
	 * 			private function progressHandler( event:ProgressEvent ):void
	 * 			{
	 * 				trace( "progressHandler loaded:" + event.bytesLoaded + " total: " + event.bytesTotal );
	 * 			}
	 * 
	 * 			private function securityErrorHandler( event:SecurityErrorEvent ):void
	 * 			{
	 * 				trace( "securityErrorHandler: " + event );
	 * 			}
	 * 
	 * 			private function httpStatusHandler( event:HTTPStatusEvent ):void
	 * 			{
	 * 				trace( "httpStatusHandler: " + event );
	 * 			}
	 * 
	 * 			private function ioErrorHandler( event:IOErrorEvent ):void
	 * 			{
	 * 				trace( "ioErrorHandler: " + event );
	 * 			}
	 * 		}
	 * }
	 * </listing>
	 *
	 * @playerversion Flash 9
	 * @playerversion AIR 1.0
	 * @langversion 3.0
	 * 
	 * @see URLRequest
	 * @see URLLoader
	 */
	public final class URLRequestHeader
	{
		/**
		 * An HTTP request header name (such as <code>Content-Type</code> or <code>SOAPAction</code>).
		 * 
		 * @playerversion Flash 9
		 * @playerversion AIR 1.0
		 * @langversion 3.0
		 */
		public var name:String;

		/**
		 * The value associated with the name property (such as <code>text/plain</code>).
		 * 
		 * @playerversion Flash 9
		 * @playerversion AIR 1.0
		 * @langversion 3.0
		 */
		public var value:String;

		/**
		 * Creates a new URLRequestHeader object that encapsulates a single HTTP request header.
		 * URLRequestHeader objects are used in the requestHeaders property of the URLRequest class.
		 *
		 * @param name An HTTP request header name (such as <code>Content-Type</code> or <code>SOAPAction</code>).
		 * @param value The value associated with the <code>name</code> property (such as <code>text/plain</code>).
		 * 
		 * @playerversion Flash 9
		 * @playerversion AIR 1.0
		 * @langversion 3.0
		 */
		public function URLRequestHeader( name:String = "", value:String = "" )
		{
			super();
			this.name  = name;
			this.value = value;
		}
	}
}
