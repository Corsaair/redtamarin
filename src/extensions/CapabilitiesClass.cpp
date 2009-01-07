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
 * Portions created by the Initial Developer are Copyright (C) 2004-2006
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *   Zwetan Kjukov <zwetan@gmail.com>.
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


#ifdef AVMPLUS_SHELL
#include "avmshell.h"
#else
// player
#include "platformbuild.h"
#include "avmplayer.h"
#endif

/*
#include <sys/utsname.h>
*/

#ifdef WIN32
#include <windows.h>
#else
#include <stdlib.h>
#endif


namespace avmshell
{
    CapabilitiesClass::CapabilitiesClass(VTable *cvtable)
	: ClassClosure(cvtable)
	{		
		createVanillaPrototype();
        
	}
    
    CapabilitiesClass::~CapabilitiesClass()
    {
        
    }
        
    Stringp CapabilitiesClass::__getOSname()
    {
        AvmCore* core = this->core();
        
        #ifdef AVMPLUS_WIN32
        return core->newString("Windows");
        #elif AVMPLUS_MAC
        return core->newString("Macintosh");
        #elif AVMPLUS_UNIX
        return core->newString("Linux");
        #endif
        
    }
    
    /*
    Stringp CapabilitiesClass::__getInfos()
    {
        struct utsname uts;
        AvmCore* core = this->core();
        Stringp s = core->kEmptyString;
        //uts.sysname, uts.machine
        
        if( uname(&uts) < 0 )
        {
            s = core->concatStrings( s, core->newString( "no infos" ) );
        }
        else
        {
            s = core->concatStrings( s, core->newString( "sysname: " ) );
            s = core->concatStrings( s, core->newString( uts.sysname ) );
            s = core->concatStrings( s, core->newString( ", nodename: " ) );
            s = core->concatStrings( s, core->newString( uts.nodename ) );
            s = core->concatStrings( s, core->newString( ", release: " ) );
            s = core->concatStrings( s, core->newString( uts.release ) );
            s = core->concatStrings( s, core->newString( ", version: " ) );
            s = core->concatStrings( s, core->newString( uts.version ) );
            s = core->concatStrings( s, core->newString( ", machine: " ) );
            s = core->concatStrings( s, core->newString( uts.machine ) );
        }
        
        return s;
    }
    */
    
    Stringp CapabilitiesClass::__getLocale()
    {
        AvmCore* core = this->core();
        Stringp s = core->kEmptyString;
        
        #ifdef WIN32
        LCID lcid;
        LANGID langid;
        int primary_lang;
        int sub_lang;
        char *lang = NULL;
        char *country = NULL;
        
        lcid         = GetThreadLocale();
        langid       = LANGIDFROMLCID( lcid );
        primary_lang = PRIMARYLANGID( langid );
        sub_lang     = SUBLANGID( langid );
        
        switch( primary_lang )
        {
            case LANG_CZECH:
            lang = "cs";
            country = "CZ";
            break;
            
            case LANG_DANISH:
            lang = "da";
            country = "DK";
            break;
            
            case LANG_DUTCH:
            lang = "nl";
            switch( sub_lang )
            {
                case SUBLANG_DUTCH:
                country = "NL";
                break;
                
                case SUBLANG_DUTCH_BELGIAN:
                country = "BE";
                break;
            }
            break;

            case LANG_ENGLISH:
            lang = "en";
            switch( sub_lang )
            {
                case SUBLANG_ENGLISH_US:
                country = "US";
                break;
                
                case SUBLANG_ENGLISH_UK:
                country = "GB";
                break;
                
                case SUBLANG_ENGLISH_AUS:
                country = "AU";
                break;
                
                case SUBLANG_ENGLISH_CAN:
                country = "CA";
                break;
                
                case SUBLANG_ENGLISH_NZ:
                country = "NZ";
                break;
                
                case SUBLANG_ENGLISH_EIRE:
                country = "IE";
                break;
                
                case SUBLANG_ENGLISH_SOUTH_AFRICA:
                country = "ZA";
                break;
                
                case SUBLANG_ENGLISH_JAMAICA:
                country = "JM";
                break;
                
                case SUBLANG_ENGLISH_CARIBBEAN:
                country = "GD";
                break;
                
                case SUBLANG_ENGLISH_BELIZE:
                country = "BZ";
                break;
                
                case SUBLANG_ENGLISH_TRINIDAD:
                country = "TT";
                break;
            }
            break;

            case LANG_FINNISH:
            lang = "fi";
            country = "FI";
            break;
            
            case LANG_FRENCH:
            lang = "fr";
            switch( sub_lang )
            {
                case SUBLANG_FRENCH:
                country = "FR";
                break;
                
                case SUBLANG_FRENCH_BELGIAN:
                country = "BE";
                break;
                
                case SUBLANG_FRENCH_CANADIAN:
                country = "CA";
                break;
                
                case SUBLANG_FRENCH_SWISS:
                country = "CH";
                break;
                
                case SUBLANG_FRENCH_LUXEMBOURG:
                country = "LU";
                break;
            }
            break;
            
            case LANG_GERMAN:
            lang = "de";
            switch( sub_lang )
            {
                case SUBLANG_GERMAN:
                country = "DE";
                break;
                
                case SUBLANG_GERMAN_SWISS:
                country = "CH";
                break;
                
                case SUBLANG_GERMAN_AUSTRIAN:
                country = "AT";
                break;
                
                case SUBLANG_GERMAN_LUXEMBOURG:
                country = "LU";
                break;
                
                case SUBLANG_GERMAN_LIECHTENSTEIN:
                country = "LI";
                break;
            }
            break;
            
            case LANG_HUNGARIAN:
            lang = "hu";
            country = "HU";
            break;
            
            case LANG_ITALIAN:
            lang = "it";
            switch( sub_lang )
            {
                case SUBLANG_ITALIAN:
                country = "IT";
                break;
                
                case SUBLANG_ITALIAN_SWISS:
                country = "CH";
                break;
            }
            break;
            
            case LANG_JAPANESE:
            lang = "ja";
            country = "JP";
            break;
            
            case LANG_KOREAN:
            lang = "ko";
            country = "KR";
            break;
            
            case LANG_NORWEGIAN:
            lang = "no";
            switch( sub_lang )
            {
                case SUBLANG_NORWEGIAN_BOKMAL:
                country = "NO";
                break;
                
                case SUBLANG_NORWEGIAN_NYNORSK:
                lang = "nn";
                country = "NO";
                break;
            }
            break;
            
            case LANG_POLISH:
            lang = "pl";
            country = "PL";
            break;
            
            case LANG_PORTUGUESE:
            lang = "pt";
            switch( sub_lang )
            {
                case SUBLANG_PORTUGUESE:
                country = "PT";
                break;
                
                case SUBLANG_PORTUGUESE_BRAZILIAN:
                country = "BR";
                break;
            }
            break;
            
            case LANG_RUSSIAN:
            lang = "ru";
            country = "RU";
            break;
            
            case LANG_CHINESE:
            lang = "zh";
            switch( sub_lang )
            {
                case SUBLANG_CHINESE_TRADITIONAL:
                country = "TW";
                break;
                
                case SUBLANG_CHINESE_SIMPLIFIED:
                country = "CN";
                break;
                
                case SUBLANG_CHINESE_HONGKONG:
                country = "HK";
                break;
                
                case SUBLANG_CHINESE_SINGAPORE:
                country = "SG";
                break;
            }
            break;
            
            case LANG_SPANISH:
            lang = "es";
            switch (sub)
            {
                case SUBLANG_SPANISH:
                country = "ES";
                break;
                
                case SUBLANG_SPANISH_MEXICAN:
                country = "MX";
                break;
                
                case SUBLANG_SPANISH_MODERN:
                country = "ES@modern";
                break;
                
                case SUBLANG_SPANISH_GUATEMALA:
                country = "GT";
                break;
                
                case SUBLANG_SPANISH_COSTA_RICA:
                country = "CR";
                break;
                
                case SUBLANG_SPANISH_PANAMA:
                country = "PA";
                break;
                
                case SUBLANG_SPANISH_DOMINICAN_REPUBLIC:
                country = "DO";
                break;
                
                case SUBLANG_SPANISH_VENEZUELA:
                country = "VE";
                break;
                
                case SUBLANG_SPANISH_COLOMBIA:
                country = "CO";
                break;
                
                case SUBLANG_SPANISH_PERU:
                country = "PE";
                break;
                
                case SUBLANG_SPANISH_ARGENTINA:
                country = "AR";
                break;
                
                case SUBLANG_SPANISH_ECUADOR:
                country = "EC";
                break;
                
                case SUBLANG_SPANISH_CHILE:
                country = "CL";
                break;
                
                case SUBLANG_SPANISH_URUGUAY:
                country = "UY";
                break;
                
                case SUBLANG_SPANISH_PARAGUAY:
                country = "PY";
                break;
                
                case SUBLANG_SPANISH_BOLIVIA:
                country = "BO";
                break;
                
                case SUBLANG_SPANISH_EL_SALVADOR:
                country = "SV";
                break;
                
                case SUBLANG_SPANISH_HONDURAS:
                country = "HN";
                break;
                
                case SUBLANG_SPANISH_NICARAGUA:
                country = "NI";
                break;
                
                case SUBLANG_SPANISH_PUERTO_RICO:
                country = "PR";
                break;
            }
            break;
            
            case LANG_SWEDISH:
            lang = "sv";
            switch( sub_lang )
            {
                case SUBLANG_DEFAULT:
                country = "SE";
                break;
                
                case SUBLANG_SWEDISH_FINLAND:
                country = "FI";
                break;
            }
            break;
            
            case LANG_TURKISH:
            lang = "tr";
            country = "TR";
            break;
        }
        
        s = core->concatStrings( s, core->newString( lang ) );
        s = core->concatStrings( s, core->newString( "_" ) );
        s = core->concatStrings( s, core->newString( country ) );
        
        return s;
        #else
        char *locale = NULL;
        locale = getenv( "LC_ALL" );
        
        if( locale == 0 )
        {
            locale = getenv( "LANG" );
        }
        
        s = core->concatStrings( s, core->newString( locale ) );
        
        return s;
        #endif
        
    }
    
    
}	


