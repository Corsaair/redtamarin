/* -*- c-basic-offset: 4; indent-tabs-mode: nil; tab-width: 4 -*- */
/* vi: set ts=4 sw=4 expandtab: (add to ~/.vimrc: set modeline modelines=5) */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

package flash.utils
{

    import flash.errors.IllegalOperationError;

    /**
     * Defines methods of the Proxy class.
     * The Proxy class methods are in their own namespace to avoid name conflicts in situations
     * where your Proxy subclass contains instance method names that match any of the Proxy class method names.
     * 
     * @langversion 3.0
     * @playerversion Flash 9
     * @playerversion AIR 1.0
     * 
     * @see flash.utils.Proxy
     */
    public namespace flash_proxy = "http://www.adobe.com/2006/actionscript/flash/proxy";

    /**
     * The Proxy class lets you override the default behavior of ActionScript operations
     * (such as retrieving and modifying properties) on an object.
     *
     * <p>
     * The Proxy class has no constructor, and you should not attempt to instantiate Proxy.
     * Instead, subclass the Proxy class to override methods such as getProperty and
     * provide custom behavior.
     * If you try to use a method of the Proxy class without overriding the method,
     * an exception is thrown.
     * </p>
     *
     * <p>
     * And, keep in mind, your own code overriding the methods of the Proxy class can
     * throw exceptions unintentionally.
     * Throwing exceptions when using these methods causes problems because the calling code
     * (using operators like in, is, delete and others) does not expect exceptions.
     * Unless you're already sure your overriding method does not throw exceptions,
     * Adobe recommends using try..catch statements around your implementation of the Proxy class
     * to avoid fatal errors when operators call your methods.
     *
     * For example:
     * <pre>
     * dynamic class MyProxy extends Proxy
     * {
     *      flash_proxy override function callProperty( name:&#42;, ...rest ):&#42;
     *      {
     *          try
     *          {
     *              // custom code here
     *          }
     *          catch( e:Error )
     *          {
     *              // respond to error here
     *          }
     *      }
     * }
     * </pre>
     * </p>
     *
     * <p>
     * The Proxy class is a replacement for the <code>Object.__resolve</code> and
     * <code>Object.addProperty</code> features of ActionScript 2.0,
     * which are no longer available in ActionScript 3.0.
     * The <code>Object.addProperty()</code> feature allowed you to dynamically create
     * get and set methods in ActionScript 2.0.
     * Although ActionScript 3.0 provides get and set methods at compile time,
     * you cannot dynamically assign one to an object unless you use the Proxy class.
     * </p>
     *
     * <p>
     * To avoid collisions with the <code>public</code> namespace,
     * the methods of the Proxy class are in the <code>flash_proxy</code> namespace.
     * </p>
     *
     * <p>
     * Where methods of the Proxy class take a <code>name</code> argument,
     * <code>name</code> can be either a String or a QName object (if namespaces are being used).
     * </p>
     *
     * <p>
     * <b>Note:</b> Prior to Flash 11 and AIR 3.0, the Proxy class was a member of the
     * <code>flash.utils</code> package. It is now a top-level class.
     * </p>
     *
     * <p>
     * <b>Note:</b> RedTamarin keep the Proxy class in the <code>flash.utils</code> package.
     * reason: inconsistency in Adobe documentation
     * (we use last known doc for the Proxy class from "Mon Nov 28 2011, 06:48 AM -08:00").
     * </p>
     *
     * @example Usage
     * <listing>
     * package
     * {
     *      import flash.display.Sprite;
     * 
     *      public class ProxyExample extends Sprite
     *      {
     *          public function ProxyExample()
     *          {
     *              var arr:ProxyArray = new ProxyArray();
     *                  arr.push( 1 );
     *                  arr.psuh( -2 );
     *                  arr.push( 3 );
     *                  arr.push( 4 );
     *                  arr.push( "five" );
     * 
     *              trace( arr.length ); // 5
     *              trace( arr[0] );     // 1
     *              trace( arr[1] );     // -2
     *              trace( arr[2] );     // 3
     *              trace( arr[3] );     // 4
     * 
     *              trace( arr.sum() );  // 6
     * 
     *              arr.clear();
     *              trace( arr );        // (empty string)
     * 
     *              arr[0] = "zero";
     *              trace( arr );       // zero
     *          }
     *      }
     * 
     * 
     *      import flash.utils.Proxy;
     *      import flash.utils.flash_proxy;
     * 
     *      dynamic class ProxyArray extends Proxy
     *      {
     *          private var _item:Array;
     * 
     *          public function ProxyArray()
     *          {
     *              _item = new Array();
     *          }
     * 
     *          override flash_proxy function callProperty( methodName:&#42;, ... args ):&#42;
     *          {
     *              var res:&#42;;
     *              switch( methodName.toString() )
     *              {
     *                  case "clear":
     *                      _item = new Array();
     *                      break;
     *
     *                  case "sum":
     *                      var sum:Number = 0;
     *                      for each( var i:&#42; in _item )
     *                      {
     *                          // ignore non-numeric values
     *                          if( !isNaN(i) )
     *                          {
     *                              sum += i;
     *                          }
     *                      }
     *                      res = sum;
     *                      break;
     *
     *                  default:
     *                      res = _item[methodName].apply( _item, args );
     *                      break;
     *              }
     *              return res;
     *          }
     * 
     *          override flash_proxy function getProperty( name:&#42; ):&#42;
     *          {
     *              return _item[name];
     *          }
     * 
     *          override flash_proxy function setProperty( name:&#42;, value:&#42; ):void
     *          {
     *              _item[name] = value;
     *          }
     *      }
     * 
     * }
     * </listing>
     * 
     * @langversion 3.0
     * @playerversion Flash 9
     * @playerversion AIR 1.0
     * 
     * @see http://help.adobe.com/en_US/FlashPlatform/reference/actionscript/3/flash/utils/Proxy.html AS3LCR Flash Platform flash.utils.Proxy
     * @see flash_proxy 
     */
    [native(cls="ProxyClass", gc="exact", instance="ProxyObject", methods="auto")]
    public class Proxy
    {

        /**
         * Overrides any request for a property's value.
         * If the property can't be found, the method returns <code>undefined</code>.
         * For more information on this behavior, see the ECMA-262 Language Specification, 3rd Edition,
         * section 8.6.2.1.
         *
         * @param name The name of the property to retrieve.
         * @return The specified property or <code>undefined</code> if the property is not found.
         * 
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         *
         * @see http://www.ecma-international.org/publications/standards/Ecma-262.htm ECMA-262 Language Specification, 3rd Edition, section 8.6.2.1
         */
        flash_proxy function getProperty( name:* ):*
        {
            Error.throwError(IllegalOperationError, 2088  /* kProxyGetPropertyError */);
            return null; // compiler doesn't realize this is unreachable (strict mode)
        }

        /**
         * Overrides a call to change a property's value.
         * If the property can't be found, this method creates a property with the specified name and value.
         *
         * @param name The name of the property to modify.
         * @param value The value to set the property to.
         * 
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         *
         * @see http://www.ecma-international.org/publications/standards/Ecma-262.htm ECMA-262 Language Specification, 3rd Edition, section 8.6.2.2
         */
        flash_proxy function setProperty( name:*, value:* ):void
        {
            Error.throwError(IllegalOperationError, 2089  /* kProxySetPropertyError */);
        }

        /**
         * Overrides the behavior of an object property that can be called as a function.
         * When a method of the object is invoked, this method is called.
         * While some objects can be called as functions,
         * some object properties can also be called as functions.
         *
         * @param name The name of the method being invoked.
         * @param rest An array specifying the arguments to the called method.
         * @return The return value of the called method.
         * 
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         *
         * @see http://www.ecma-international.org/publications/standards/Ecma-262.htm ECMA-262 Language Specification, 3rd Edition, section 15
         */
        flash_proxy function callProperty( name:*, ...rest ):*
        {
            Error.throwError(IllegalOperationError, 2090 /* kProxyCallPropertyError */);
            return null; // unreachable
        }

        /**
         * Overrides a request to check whether an object has a particular property by name.
         *
         * @param name The name of the property to check for.
         * @return If the property exists, <code>true</code>; otherwise <code>false</code>.
         * 
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         *
         * @see http://www.ecma-international.org/publications/standards/Ecma-262.htm ECMA-262 Language Specification, 3rd Edition, section 8.6.2.4
         */
        flash_proxy function hasProperty(name:*):Boolean
        {
            Error.throwError(IllegalOperationError, 2091 /* kProxyHasPropertyError */);
            return null; // unreachable
        }

        /**
         * Overrides the request to delete a property.
         * When a property is deleted with the delete operator,
         * this method is called to perform the deletion.
         *
         * @param name The name of the property to delete.
         * @return  If the property was deleted, <code>true</code>; otherwise <code>false</code>.
         * 
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         * 
         * @see http://www.ecma-international.org/publications/standards/Ecma-262.htm ECMA-262 Language Specification, 3rd Edition, 8.6.2.5
         * @see delete operator
         */
        flash_proxy function deleteProperty(name:*):Boolean
        {
            Error.throwError(IllegalOperationError, 2092 /* kProxyDeletePropertyError */);
            return null; // unreachable
        }
    
        /**
         * Overrides the use of the <code>descendant</code> operator.
         * When the <code>descendant</code> operator is used, this method is invoked.
         *
         * @param name The name of the property to descend into the object and search for.
         * @return The results of the <code>descendant</code> operator.
         * 
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         *
         * @see http://www.ecma-international.org/publications/standards/Ecma-357.htm E4X Specification
         * @see descendant operator
         */
        flash_proxy function getDescendants(name:*):*
        {
            Error.throwError(IllegalOperationError, 2093 /* kProxyGetDescendantsError */);
            return null; // unreachable
        }

        /**
         * Allows enumeration of the proxied object's properties by index number.
         * However, you cannot enumerate the properties of the Proxy class themselves.
         * This function supports implementing <code>for...in</code> and <code>for each..in</code> loops
         * on the object to retrieve property index values.
         * 
         * <p>
         * For example:
         *
         * <pre>
         * protected var _item:Array; // array of object's properties
         * 
         * override flash_proxy function nextNameIndex( index:int ):int
         * {
         *      // initial call
         *      if( index == 0 )
         *      {
         *          _item = new Array();
         *          for (var x:&#42; in _target)
         *          {
         *              _item.push( x );
         *          }
         *      }
         * 
         *      if( index &lt; _item.length )
         *      {
         *          return index + 1;
         *      }
         *      else
         *      {
         *          return 0;
         *      }
         * }
         * 
         * override flash_proxy function nextName( index:int ):String
         * {
         *      return _item[index - 1];
         * }
         * </pre>
         * </p>
         *
         * @param index The zero-based index value where the enumeration begins.
         * @return The property's index value.
         * 
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         *
         * @see Proxy#nextName()
         * @see Proxy#nextValue()
         */
        flash_proxy function nextNameIndex(index:int):int
        {
            Error.throwError(IllegalOperationError, 2105 /* kProxyNextNameIndexError */);
            return null; // unreachable
        }

        /**
         * Allows enumeration of the proxied object's properties by index number to retrieve property names.
         * However, you cannot enumerate the properties of the Proxy class themselves.
         * This function supports implementing <code>for...in</code> and <code>for each..in</code> loops
         * on the object to retrieve the desired names.
         *
         * <p>
         * For example (with code from <code>Proxy.nextNameIndex()</code>):
         *
         * <pre>
         * protected var _item:Array; // array of object's properties
         * 
         * override flash_proxy function nextNameIndex( index:int ):int
         * {
         *      // initial call
         *      if( index == 0 )
         *      {
         *          _item = new Array();
         *          for (var x:&#42; in _target)
         *          {
         *              _item.push( x );
         *          }
         *      }
         * 
         *      if( index &lt; _item.length )
         *      {
         *          return index + 1;
         *      }
         *      else
         *      {
         *          return 0;
         *      }
         * }
         * 
         * override flash_proxy function nextName( index:int ):String
         * {
         *      return _item[index - 1];
         * }
         * </pre>
         * </p>
         * 
         * @param index The zero-based index value of the object's property.
         * @return The property's name.
         * 
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         *
         * @see Proxy#nextNameIndex()
         * @see Proxy#nextValue()
         */
        flash_proxy function nextName( index:int ):String
        {
            Error.throwError(IllegalOperationError, 2106 /* kProxyNextNameError */);
            return null; // unreachable
        }

        /**
         * Allows enumeration of the proxied object's properties by index number to retrieve property values.
         * However, you cannot enumerate the properties of the Proxy class themselves.
         * This function supports implementing <code>for...in</code> and <code>for each..in</code> loops
         * on the object to retrieve the desired values.
         *
         * <p>
         * For example (with code from <code>Proxy.nextNameIndex()</code>):
         *
         * <pre>
         * protected var _item:Array; // array of object's properties
         * 
         * override flash_proxy function nextNameIndex( index:int ):int
         * {
         *      // initial call
         *      if( index == 0 )
         *      {
         *          _item = new Array();
         *          for (var x:&#42; in _target)
         *          {
         *              _item.push( x );
         *          }
         *      }
         * 
         *      if( index &lt; _item.length )
         *      {
         *          return index + 1;
         *      }
         *      else
         *      {
         *          return 0;
         *      }
         * }
         * 
         * override flash_proxy function nextName( index:int ):String
         * {
         *      return _item[index - 1];
         * }
         * </pre>
         * </p>
         *
         * @param index The zero-based index value of the object's property.
         * @return The property's value.
         * 
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         *
         * @see Proxy#nextNameIndex()
         * @see Proxy#nextName()
         */
        flash_proxy function nextValue( index:int ):*
        {
            Error.throwError(IllegalOperationError, 2107 /* kProxyNextValueError */);
            return null; // unreachable
        }

        /**
         * Checks whether a supplied QName is also marked as an attribute.
         * 
         * @param name The name of the property to check.
         * @return Returns <code>true</code> if the argument for <code>name</code> is a QName that is also marked as an attribute.
         * 
         * @langversion 3.0
         * @playerversion Flash 9
         * @playerversion AIR 1.0
         * 
         * @see QName
         */
        flash_proxy native function isAttribute( name:* ):Boolean;

    }

}
