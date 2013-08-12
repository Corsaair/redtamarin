package flash.xml
{

/**
 * @private Internal only
 * This class is package internal and only intended for
 * use by internal Flash Player code.
 *
 * The <code>XMLParser</code> class is an XML pull parser.
 * It differs from the XML (E4X) and XMLDocument ("classic" XML)
 * classes in that XML tags are parsed and returned one at a time.
 * The <code>XML</code> and <code>XMLDocument</code> classes,
 * in contrast, parse an entire XML document and produce
 * a document tree structure describing the full document.
 */
internal final class XMLParser
{
	/**
	 * Starts a parse operation.
	 *
	 * @param source The XML source text to parse.
	 *
	 * @param ignoreWhite Indicates whether whitespace
	 *                    should be ignored.
	 */
    public function startParse(source:String,ignoreWhite:Boolean):void {
      trace("XMLParse.startParse() source="+source);
      try {
        throw new Error();
      } catch (e) {
        print(e.getStackTrace());
      }
    }

	/**
	 * Returns the next tag in the XML document
	 * stream.
	 *
	 * @param tag An <code>XMLTag</code> object that
	 *            will receive the next XML tag in the
	 *            document stream.
	 * @return An integer code indicating the
	 *         success or failure of the parse
	 *         operation.  The constants returned
	 *         are specified in the <code>XMLDocument</code>
	 *         class.
	 */
    public function getNext(tag:XMLTag):int  {
      trace("XMLParse.getNext()");
    }

/*
 * [ggrossman 04/07/05] API SCRUB
 * - _XMLParser_ is now marked package internal instead of public.
 *   It is an internal class and should not be documented.
 */

}
}