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
 * The Original Code is [Open Source Virtual Machine].
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
/* machine generated file -- do not edit */
#define AVMTHUNK_VERSION 4
extern const uint32_t builtin_abc_class_count;
extern const uint32_t builtin_abc_script_count;
extern const uint32_t builtin_abc_method_count;
extern const uint32_t builtin_abc_length;
extern const uint8_t builtin_abc_data[];
AVMTHUNK_DECLARE_NATIVE_INITIALIZER(builtin)
/* classes */
const uint32_t abcclass_Object = 0;
const uint32_t abcclass_Class = 1;
const uint32_t abcclass_Function = 2;
const uint32_t abcclass_Namespace = 3;
const uint32_t abcclass_Boolean = 4;
const uint32_t abcclass_Number = 5;
const uint32_t abcclass_int = 6;
const uint32_t abcclass_uint = 7;
const uint32_t abcclass_String = 8;
const uint32_t abcclass_Array = 9;
const uint32_t abcclass___AS3___vec_Vector = 10;
const uint32_t abcclass___AS3___vec_Vector_object = 11;
const uint32_t abcclass___AS3___vec_Vector_int = 12;
const uint32_t abcclass___AS3___vec_Vector_uint = 13;
const uint32_t abcclass___AS3___vec_Vector_double = 14;
const uint32_t abcclass_avmplus_DescribeType = 15;
const uint32_t abcclass_private_MethodClosure = 16;
const uint32_t abcclass_Math = 17;
const uint32_t abcclass_Error = 18;
const uint32_t abcclass_DefinitionError = 19;
const uint32_t abcclass_EvalError = 20;
const uint32_t abcclass_RangeError = 21;
const uint32_t abcclass_ReferenceError = 22;
const uint32_t abcclass_SecurityError = 23;
const uint32_t abcclass_SyntaxError = 24;
const uint32_t abcclass_TypeError = 25;
const uint32_t abcclass_URIError = 26;
const uint32_t abcclass_VerifyError = 27;
const uint32_t abcclass_UninitializedError = 28;
const uint32_t abcclass_ArgumentError = 29;
const uint32_t abcclass_Date = 30;
const uint32_t abcclass_RegExp = 31;
const uint32_t abcclass_XML = 32;
const uint32_t abcclass_XMLList = 33;
const uint32_t abcclass_QName = 34;
/* methods */
const uint32_t isXMLName = 7;
const uint32_t unescape = 8;
const uint32_t escape = 9;
const uint32_t parseFloat = 10;
const uint32_t parseInt = 11;
const uint32_t isFinite = 12;
const uint32_t isNaN = 13;
const uint32_t encodeURIComponent = 14;
const uint32_t encodeURI = 15;
const uint32_t decodeURIComponent = 16;
const uint32_t decodeURI = 17;
const uint32_t Object_private__hasOwnProperty = 19;
const uint32_t Object_private__propertyIsEnumerable = 20;
const uint32_t Object_protected__setPropertyIsEnumerable = 21;
const uint32_t Object_private__isPrototypeOf = 22;
const uint32_t Object_private__toString = 23;
const uint32_t Class_prototype_get = 37;
const uint32_t Function_prototype_get = 45;
const uint32_t Function_prototype_set = 46;
const uint32_t Function_length_get = 47;
const uint32_t Function_AS3_call = 48;
const uint32_t Function_AS3_apply = 49;
const uint32_t Namespace_prefix_get = 54;
const uint32_t Namespace_uri_get = 55;
const uint32_t Number_private__numberToString = 71;
const uint32_t Number_private__convert = 72;
const uint32_t String_AS3_fromCharCode = 122;
const uint32_t String_private__match = 123;
const uint32_t String_private__replace = 124;
const uint32_t String_private__search = 125;
const uint32_t String_private__split = 126;
const uint32_t String_length_get = 127;
const uint32_t String_private__indexOf = 128;
const uint32_t String_AS3_indexOf = 129;
const uint32_t String_private__lastIndexOf = 130;
const uint32_t String_AS3_lastIndexOf = 131;
const uint32_t String_private__charAt = 132;
const uint32_t String_AS3_charAt = 133;
const uint32_t String_private__charCodeAt = 134;
const uint32_t String_AS3_charCodeAt = 135;
const uint32_t String_AS3_localeCompare = 137;
const uint32_t String_private__slice = 141;
const uint32_t String_AS3_slice = 142;
const uint32_t String_private__substring = 144;
const uint32_t String_AS3_substring = 145;
const uint32_t String_private__substr = 146;
const uint32_t String_AS3_substr = 147;
const uint32_t String_AS3_toLowerCase = 148;
const uint32_t String_AS3_toUpperCase = 150;
const uint32_t Array_private__pop = 177;
const uint32_t Array_private__reverse = 178;
const uint32_t Array_private__concat = 179;
const uint32_t Array_private__shift = 180;
const uint32_t Array_private__slice = 181;
const uint32_t Array_private__splice = 182;
const uint32_t Array_private__sort = 183;
const uint32_t Array_private__sortOn = 184;
const uint32_t Array_private__indexOf = 185;
const uint32_t Array_private__lastIndexOf = 186;
const uint32_t Array_private__every = 187;
const uint32_t Array_private__filter = 188;
const uint32_t Array_private__forEach = 189;
const uint32_t Array_private__map = 190;
const uint32_t Array_private__some = 191;
const uint32_t Array_length_get = 192;
const uint32_t Array_length_set = 193;
const uint32_t Array_AS3_pop = 196;
const uint32_t Array_AS3_push = 197;
const uint32_t Array_AS3_unshift = 202;
const uint32_t __AS3___vec_Vector_object_private__every = 236;
const uint32_t __AS3___vec_Vector_object_private__forEach = 237;
const uint32_t __AS3___vec_Vector_object_private__some = 238;
const uint32_t __AS3___vec_Vector_object_private__sort = 239;
const uint32_t __AS3___vec_Vector_object_private_type_set = 241;
const uint32_t __AS3___vec_Vector_object_private_type_get = 242;
const uint32_t __AS3___vec_Vector_object_length_get = 244;
const uint32_t __AS3___vec_Vector_object_length_set = 245;
const uint32_t __AS3___vec_Vector_object_fixed_set = 246;
const uint32_t __AS3___vec_Vector_object_fixed_get = 247;
const uint32_t __AS3___vec_Vector_object_AS3_push = 255;
const uint32_t __AS3___vec_Vector_object_private__reverse = 256;
const uint32_t __AS3___vec_Vector_object_private__spliceHelper = 260;
const uint32_t __AS3___vec_Vector_object_AS3_unshift = 262;
const uint32_t __AS3___vec_Vector_object_private__filter = 263;
const uint32_t __AS3___vec_Vector_object_private__map = 264;
const uint32_t __AS3___vec_Vector_object_AS3_pop = 268;
const uint32_t __AS3___vec_Vector_int_private__every = 298;
const uint32_t __AS3___vec_Vector_int_private__forEach = 299;
const uint32_t __AS3___vec_Vector_int_private__some = 300;
const uint32_t __AS3___vec_Vector_int_private__sort = 301;
const uint32_t __AS3___vec_Vector_int_length_get = 303;
const uint32_t __AS3___vec_Vector_int_length_set = 304;
const uint32_t __AS3___vec_Vector_int_fixed_set = 305;
const uint32_t __AS3___vec_Vector_int_fixed_get = 306;
const uint32_t __AS3___vec_Vector_int_AS3_push = 314;
const uint32_t __AS3___vec_Vector_int_private__reverse = 315;
const uint32_t __AS3___vec_Vector_int_private__spliceHelper = 319;
const uint32_t __AS3___vec_Vector_int_AS3_unshift = 321;
const uint32_t __AS3___vec_Vector_int_private__filter = 322;
const uint32_t __AS3___vec_Vector_int_private__map = 323;
const uint32_t __AS3___vec_Vector_int_AS3_pop = 327;
const uint32_t __AS3___vec_Vector_uint_private__every = 357;
const uint32_t __AS3___vec_Vector_uint_private__forEach = 358;
const uint32_t __AS3___vec_Vector_uint_private__some = 359;
const uint32_t __AS3___vec_Vector_uint_private__sort = 360;
const uint32_t __AS3___vec_Vector_uint_length_get = 362;
const uint32_t __AS3___vec_Vector_uint_length_set = 363;
const uint32_t __AS3___vec_Vector_uint_fixed_set = 364;
const uint32_t __AS3___vec_Vector_uint_fixed_get = 365;
const uint32_t __AS3___vec_Vector_uint_AS3_push = 373;
const uint32_t __AS3___vec_Vector_uint_private__reverse = 374;
const uint32_t __AS3___vec_Vector_uint_private__spliceHelper = 378;
const uint32_t __AS3___vec_Vector_uint_AS3_unshift = 380;
const uint32_t __AS3___vec_Vector_uint_private__filter = 381;
const uint32_t __AS3___vec_Vector_uint_private__map = 382;
const uint32_t __AS3___vec_Vector_uint_AS3_pop = 386;
const uint32_t __AS3___vec_Vector_double_private__every = 416;
const uint32_t __AS3___vec_Vector_double_private__forEach = 417;
const uint32_t __AS3___vec_Vector_double_private__some = 418;
const uint32_t __AS3___vec_Vector_double_private__sort = 419;
const uint32_t __AS3___vec_Vector_double_length_get = 421;
const uint32_t __AS3___vec_Vector_double_length_set = 422;
const uint32_t __AS3___vec_Vector_double_fixed_set = 423;
const uint32_t __AS3___vec_Vector_double_fixed_get = 424;
const uint32_t __AS3___vec_Vector_double_AS3_push = 432;
const uint32_t __AS3___vec_Vector_double_private__reverse = 433;
const uint32_t __AS3___vec_Vector_double_private__spliceHelper = 437;
const uint32_t __AS3___vec_Vector_double_AS3_unshift = 439;
const uint32_t __AS3___vec_Vector_double_private__filter = 440;
const uint32_t __AS3___vec_Vector_double_private__map = 441;
const uint32_t __AS3___vec_Vector_double_AS3_pop = 445;
const uint32_t avmplus_DescribeType_avmplus_describeTypeJSON = 454;
const uint32_t private_MethodClosure_length_get = 459;
const uint32_t private_MethodClosure_private_savedThis_get = 460;
const uint32_t Math_private__min = 464;
const uint32_t Math_private__max = 465;
const uint32_t Math_abs = 466;
const uint32_t Math_acos = 467;
const uint32_t Math_asin = 468;
const uint32_t Math_atan = 469;
const uint32_t Math_ceil = 470;
const uint32_t Math_cos = 471;
const uint32_t Math_exp = 472;
const uint32_t Math_floor = 473;
const uint32_t Math_log = 474;
const uint32_t Math_round = 475;
const uint32_t Math_sin = 476;
const uint32_t Math_sqrt = 477;
const uint32_t Math_tan = 478;
const uint32_t Math_atan2 = 479;
const uint32_t Math_pow = 480;
const uint32_t Math_max = 481;
const uint32_t Math_min = 482;
const uint32_t Math_random = 483;
const uint32_t Error_getErrorMessage = 488;
const uint32_t Error_getStackTrace = 492;
const uint32_t Date_parse = 559;
const uint32_t Date_UTC = 560;
const uint32_t Date_AS3_valueOf = 561;
const uint32_t Date_private__toString = 562;
const uint32_t Date_private__setTime = 563;
const uint32_t Date_private__get = 564;
const uint32_t Date_AS3_getUTCFullYear = 573;
const uint32_t Date_AS3_getUTCMonth = 574;
const uint32_t Date_AS3_getUTCDate = 575;
const uint32_t Date_AS3_getUTCDay = 576;
const uint32_t Date_AS3_getUTCHours = 577;
const uint32_t Date_AS3_getUTCMinutes = 578;
const uint32_t Date_AS3_getUTCSeconds = 579;
const uint32_t Date_AS3_getUTCMilliseconds = 580;
const uint32_t Date_AS3_getFullYear = 581;
const uint32_t Date_AS3_getMonth = 582;
const uint32_t Date_AS3_getDate = 583;
const uint32_t Date_AS3_getDay = 584;
const uint32_t Date_AS3_getHours = 585;
const uint32_t Date_AS3_getMinutes = 586;
const uint32_t Date_AS3_getSeconds = 587;
const uint32_t Date_AS3_getMilliseconds = 588;
const uint32_t Date_AS3_getTimezoneOffset = 589;
const uint32_t Date_AS3_getTime = 590;
const uint32_t Date_private__setFullYear = 591;
const uint32_t Date_private__setMonth = 592;
const uint32_t Date_private__setDate = 593;
const uint32_t Date_private__setHours = 594;
const uint32_t Date_private__setMinutes = 595;
const uint32_t Date_private__setSeconds = 596;
const uint32_t Date_private__setMilliseconds = 597;
const uint32_t Date_private__setUTCFullYear = 598;
const uint32_t Date_private__setUTCMonth = 599;
const uint32_t Date_private__setUTCDate = 600;
const uint32_t Date_private__setUTCHours = 601;
const uint32_t Date_private__setUTCMinutes = 602;
const uint32_t Date_private__setUTCSeconds = 603;
const uint32_t Date_private__setUTCMilliseconds = 604;
const uint32_t RegExp_source_get = 658;
const uint32_t RegExp_global_get = 659;
const uint32_t RegExp_ignoreCase_get = 660;
const uint32_t RegExp_multiline_get = 661;
const uint32_t RegExp_lastIndex_get = 662;
const uint32_t RegExp_lastIndex_set = 663;
const uint32_t RegExp_dotall_get = 664;
const uint32_t RegExp_extended_get = 665;
const uint32_t RegExp_AS3_exec = 666;
const uint32_t XML_ignoreComments_get = 712;
const uint32_t XML_ignoreComments_set = 713;
const uint32_t XML_ignoreProcessingInstructions_get = 714;
const uint32_t XML_ignoreProcessingInstructions_set = 715;
const uint32_t XML_ignoreWhitespace_get = 716;
const uint32_t XML_ignoreWhitespace_set = 717;
const uint32_t XML_prettyPrinting_get = 718;
const uint32_t XML_prettyPrinting_set = 719;
const uint32_t XML_prettyIndent_get = 720;
const uint32_t XML_prettyIndent_set = 721;
const uint32_t XML_AS3_toString = 725;
const uint32_t XML_AS3_hasOwnProperty = 726;
const uint32_t XML_AS3_propertyIsEnumerable = 727;
const uint32_t XML_AS3_addNamespace = 728;
const uint32_t XML_AS3_appendChild = 729;
const uint32_t XML_AS3_attribute = 730;
const uint32_t XML_AS3_attributes = 731;
const uint32_t XML_AS3_child = 732;
const uint32_t XML_AS3_childIndex = 733;
const uint32_t XML_AS3_children = 734;
const uint32_t XML_AS3_comments = 735;
const uint32_t XML_AS3_contains = 736;
const uint32_t XML_AS3_copy = 737;
const uint32_t XML_AS3_descendants = 738;
const uint32_t XML_AS3_elements = 739;
const uint32_t XML_AS3_hasComplexContent = 740;
const uint32_t XML_AS3_hasSimpleContent = 741;
const uint32_t XML_AS3_inScopeNamespaces = 742;
const uint32_t XML_AS3_insertChildAfter = 743;
const uint32_t XML_AS3_insertChildBefore = 744;
const uint32_t XML_AS3_localName = 746;
const uint32_t XML_AS3_name = 747;
const uint32_t XML_private__namespace = 748;
const uint32_t XML_AS3_namespaceDeclarations = 750;
const uint32_t XML_AS3_nodeKind = 751;
const uint32_t XML_AS3_normalize = 752;
const uint32_t XML_AS3_parent = 753;
const uint32_t XML_AS3_processingInstructions = 754;
const uint32_t XML_AS3_prependChild = 755;
const uint32_t XML_AS3_removeNamespace = 756;
const uint32_t XML_AS3_replace = 757;
const uint32_t XML_AS3_setChildren = 758;
const uint32_t XML_AS3_setLocalName = 759;
const uint32_t XML_AS3_setName = 760;
const uint32_t XML_AS3_setNamespace = 761;
const uint32_t XML_AS3_text = 762;
const uint32_t XML_AS3_toXMLString = 763;
const uint32_t XML_AS3_notification = 764;
const uint32_t XML_AS3_setNotification = 765;
const uint32_t XMLList_AS3_toString = 807;
const uint32_t XMLList_AS3_hasOwnProperty = 809;
const uint32_t XMLList_AS3_propertyIsEnumerable = 810;
const uint32_t XMLList_AS3_attribute = 811;
const uint32_t XMLList_AS3_attributes = 812;
const uint32_t XMLList_AS3_child = 813;
const uint32_t XMLList_AS3_children = 814;
const uint32_t XMLList_AS3_comments = 815;
const uint32_t XMLList_AS3_contains = 816;
const uint32_t XMLList_AS3_copy = 817;
const uint32_t XMLList_AS3_descendants = 818;
const uint32_t XMLList_AS3_elements = 819;
const uint32_t XMLList_AS3_hasComplexContent = 820;
const uint32_t XMLList_AS3_hasSimpleContent = 821;
const uint32_t XMLList_AS3_length = 822;
const uint32_t XMLList_AS3_name = 823;
const uint32_t XMLList_AS3_normalize = 824;
const uint32_t XMLList_AS3_parent = 825;
const uint32_t XMLList_AS3_processingInstructions = 826;
const uint32_t XMLList_AS3_text = 827;
const uint32_t XMLList_AS3_toXMLString = 828;
const uint32_t XMLList_AS3_addNamespace = 829;
const uint32_t XMLList_AS3_appendChild = 830;
const uint32_t XMLList_AS3_childIndex = 831;
const uint32_t XMLList_AS3_inScopeNamespaces = 832;
const uint32_t XMLList_AS3_insertChildAfter = 833;
const uint32_t XMLList_AS3_insertChildBefore = 834;
const uint32_t XMLList_AS3_nodeKind = 835;
const uint32_t XMLList_private__namespace = 836;
const uint32_t XMLList_AS3_localName = 838;
const uint32_t XMLList_AS3_namespaceDeclarations = 839;
const uint32_t XMLList_AS3_prependChild = 840;
const uint32_t XMLList_AS3_removeNamespace = 841;
const uint32_t XMLList_AS3_replace = 842;
const uint32_t XMLList_AS3_setChildren = 843;
const uint32_t XMLList_AS3_setLocalName = 844;
const uint32_t XMLList_AS3_setName = 845;
const uint32_t XMLList_AS3_setNamespace = 846;
const uint32_t QName_localName_get = 850;
const uint32_t QName_uri_get = 851;
extern AvmBox builtin_a2a_oaoa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Array_private__filter_thunk  builtin_a2a_oaoa_thunk
#define Array_private__map_thunk  builtin_a2a_oaoa_thunk

extern AvmBox builtin_v2a_ouuuai_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define __AS3___vec_Vector_object_private__spliceHelper_thunk  builtin_v2a_ouuuai_thunk
#define __AS3___vec_Vector_uint_private__spliceHelper_thunk  builtin_v2a_ouuuai_thunk
#define __AS3___vec_Vector_int_private__spliceHelper_thunk  builtin_v2a_ouuuai_thunk
#define __AS3___vec_Vector_double_private__spliceHelper_thunk  builtin_v2a_ouuuai_thunk

extern double builtin_d2d_si_opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_private__charCodeAt_thunk  builtin_d2d_si_opti0_thunk

extern double builtin_d2d_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Date_AS3_getUTCDate_thunk  builtin_d2d_o_thunk
#define __AS3___vec_Vector_double_AS3_pop_thunk  builtin_d2d_o_thunk
#define Date_AS3_valueOf_thunk  builtin_d2d_o_thunk
#define Date_AS3_getDay_thunk  builtin_d2d_o_thunk
#define Date_AS3_getSeconds_thunk  builtin_d2d_o_thunk
#define Date_AS3_getUTCFullYear_thunk  builtin_d2d_o_thunk
#define Date_AS3_getMilliseconds_thunk  builtin_d2d_o_thunk
#define Date_AS3_getUTCDay_thunk  builtin_d2d_o_thunk
#define Date_AS3_getMonth_thunk  builtin_d2d_o_thunk
#define Date_AS3_getUTCHours_thunk  builtin_d2d_o_thunk
#define Date_AS3_getMinutes_thunk  builtin_d2d_o_thunk
#define Date_AS3_getUTCMilliseconds_thunk  builtin_d2d_o_thunk
#define Date_AS3_getUTCMonth_thunk  builtin_d2d_o_thunk
#define Date_AS3_getTime_thunk  builtin_d2d_o_thunk
#define Date_AS3_getTimezoneOffset_thunk  builtin_d2d_o_thunk
#define Date_AS3_getFullYear_thunk  builtin_d2d_o_thunk
#define Math_random_thunk  builtin_d2d_o_thunk
#define Date_AS3_getUTCSeconds_thunk  builtin_d2d_o_thunk
#define Date_AS3_getDate_thunk  builtin_d2d_o_thunk
#define Date_AS3_getUTCMinutes_thunk  builtin_d2d_o_thunk
#define Date_AS3_getHours_thunk  builtin_d2d_o_thunk

extern AvmBox builtin_i2a_ss_optakAvmThunkUndefined_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_AS3_localeCompare_thunk  builtin_i2a_ss_optakAvmThunkUndefined_thunk

extern AvmBox builtin_a2a_osa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_private__match_thunk  builtin_a2a_osa_thunk

extern AvmBox builtin_a2a_ou_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define __AS3___vec_Vector_uint_length_set_thunk  builtin_a2a_ou_thunk
#define __AS3___vec_Vector_object_length_set_thunk  builtin_a2a_ou_thunk
#define __AS3___vec_Vector_int_length_set_thunk  builtin_a2a_ou_thunk
#define __AS3___vec_Vector_double_length_set_thunk  builtin_a2a_ou_thunk
#define Array_length_set_thunk  builtin_a2a_ou_thunk

extern AvmBox builtin_s2a_odi_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Number_private__numberToString_thunk  builtin_s2a_odi_thunk

extern AvmBox builtin_a2a_oi_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define XML_prettyIndent_set_thunk  builtin_a2a_oi_thunk
#define RegExp_lastIndex_set_thunk  builtin_a2a_oi_thunk

extern double builtin_d2d_osi_optsAvmThunkConstant_AvmString_68_____NaN_____opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define parseInt_thunk  builtin_d2d_osi_optsAvmThunkConstant_AvmString_68_____NaN_____opti0_thunk

extern AvmBox builtin_a2a_oo_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define XML_AS3_setNotification_thunk  builtin_a2a_oo_thunk

extern AvmBox builtin_s2a_n_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Namespace_uri_get_thunk  builtin_s2a_n_thunk

extern AvmBox builtin_s2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define XML_AS3_toXMLString_thunk  builtin_s2a_o_thunk
#define XML_AS3_toString_thunk  builtin_s2a_o_thunk
#define Error_getStackTrace_thunk  builtin_s2a_o_thunk
#define QName_localName_get_thunk  builtin_s2a_o_thunk
#define XMLList_AS3_toString_thunk  builtin_s2a_o_thunk
#define XML_AS3_nodeKind_thunk  builtin_s2a_o_thunk
#define RegExp_source_get_thunk  builtin_s2a_o_thunk
#define XMLList_AS3_toXMLString_thunk  builtin_s2a_o_thunk
#define XMLList_AS3_nodeKind_thunk  builtin_s2a_o_thunk

extern AvmBox builtin_a2a_ob_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define __AS3___vec_Vector_uint_fixed_set_thunk  builtin_a2a_ob_thunk
#define XML_prettyPrinting_set_thunk  builtin_a2a_ob_thunk
#define __AS3___vec_Vector_object_fixed_set_thunk  builtin_a2a_ob_thunk
#define XML_ignoreComments_set_thunk  builtin_a2a_ob_thunk
#define XML_ignoreWhitespace_set_thunk  builtin_a2a_ob_thunk
#define __AS3___vec_Vector_double_fixed_set_thunk  builtin_a2a_ob_thunk
#define XML_ignoreProcessingInstructions_set_thunk  builtin_a2a_ob_thunk
#define __AS3___vec_Vector_int_fixed_set_thunk  builtin_a2a_ob_thunk

extern double builtin_d2d_odd_optdkAvmThunkNegInfinity_optdkAvmThunkNegInfinity_rest_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Math_max_thunk  builtin_d2d_odd_optdkAvmThunkNegInfinity_optdkAvmThunkNegInfinity_rest_thunk

extern AvmBox builtin_a2a_oa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define XML_AS3_addNamespace_thunk  builtin_a2a_oa_thunk
#define Array_private__pop_thunk  builtin_a2a_oa_thunk
#define XML_AS3_removeNamespace_thunk  builtin_a2a_oa_thunk
#define Array_private__reverse_thunk  builtin_a2a_oa_thunk
#define XMLList_AS3_setChildren_thunk  builtin_a2a_oa_thunk
#define XMLList_AS3_prependChild_thunk  builtin_a2a_oa_thunk
#define XML_AS3_appendChild_thunk  builtin_a2a_oa_thunk
#define XMLList_AS3_appendChild_thunk  builtin_a2a_oa_thunk
#define XML_AS3_prependChild_thunk  builtin_a2a_oa_thunk
#define XMLList_AS3_child_thunk  builtin_a2a_oa_thunk
#define Function_prototype_set_thunk  builtin_a2a_oa_thunk
#define XMLList_AS3_attribute_thunk  builtin_a2a_oa_thunk
#define XMLList_AS3_addNamespace_thunk  builtin_a2a_oa_thunk
#define XML_AS3_child_thunk  builtin_a2a_oa_thunk
#define XML_AS3_attribute_thunk  builtin_a2a_oa_thunk
#define XMLList_AS3_removeNamespace_thunk  builtin_a2a_oa_thunk
#define Array_private__shift_thunk  builtin_a2a_oa_thunk
#define XML_AS3_setChildren_thunk  builtin_a2a_oa_thunk

extern AvmBox builtin_s2a_sd_opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_AS3_charAt_thunk  builtin_s2a_sd_opti0_thunk

extern double builtin_d2d_o_rest_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Date_private__setUTCDate_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setFullYear_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setMinutes_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setUTCMonth_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setUTCSeconds_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setHours_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setDate_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setUTCMinutes_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setMonth_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setUTCHours_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setSeconds_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setUTCFullYear_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setMilliseconds_thunk  builtin_d2d_o_rest_thunk
#define Date_private__setUTCMilliseconds_thunk  builtin_d2d_o_rest_thunk

extern double builtin_d2d_oaaaaaaa_opti1_opti0_opti0_opti0_opti0_rest_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Date_UTC_thunk  builtin_d2d_oaaaaaaa_opti1_opti0_opti0_opti0_opti0_rest_thunk

extern AvmBox builtin_s2a_os_optsAvmThunkConstant_AvmString_66_____undefined_____thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define unescape_thunk  builtin_s2a_os_optsAvmThunkConstant_AvmString_66_____undefined_____thunk
#define decodeURI_thunk  builtin_s2a_os_optsAvmThunkConstant_AvmString_66_____undefined_____thunk
#define decodeURIComponent_thunk  builtin_s2a_os_optsAvmThunkConstant_AvmString_66_____undefined_____thunk
#define escape_thunk  builtin_s2a_os_optsAvmThunkConstant_AvmString_66_____undefined_____thunk
#define encodeURIComponent_thunk  builtin_s2a_os_optsAvmThunkConstant_AvmString_66_____undefined_____thunk
#define encodeURI_thunk  builtin_s2a_os_optsAvmThunkConstant_AvmString_66_____undefined_____thunk

extern AvmBox builtin_i2a_s_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_length_get_thunk  builtin_i2a_s_thunk

extern AvmBox builtin_i2a_ssd_optsAvmThunkConstant_AvmString_66_____undefined_____opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_AS3_indexOf_thunk  builtin_i2a_ssd_optsAvmThunkConstant_AvmString_66_____undefined_____opti0_thunk

extern AvmBox builtin_b2a_oaa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Object_private__isPrototypeOf_thunk  builtin_b2a_oaa_thunk

extern AvmBox builtin_a2a_oaaa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Array_private__sortOn_thunk  builtin_a2a_oaaa_thunk

extern AvmBox builtin_u2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define __AS3___vec_Vector_uint_length_get_thunk  builtin_u2a_o_thunk
#define __AS3___vec_Vector_int_length_get_thunk  builtin_u2a_o_thunk
#define Array_length_get_thunk  builtin_u2a_o_thunk
#define __AS3___vec_Vector_uint_AS3_pop_thunk  builtin_u2a_o_thunk
#define __AS3___vec_Vector_object_length_get_thunk  builtin_u2a_o_thunk
#define __AS3___vec_Vector_double_length_get_thunk  builtin_u2a_o_thunk

extern AvmBox builtin_a2a_oa_optakAvmThunkUndefined_rest_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Function_AS3_call_thunk  builtin_a2a_oa_optakAvmThunkUndefined_rest_thunk

extern AvmBox builtin_s2a_si_opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_private__charAt_thunk  builtin_s2a_si_opti0_thunk

extern double builtin_d2d_os_optsAvmThunkConstant_AvmString_68_____NaN_____thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define parseFloat_thunk  builtin_d2d_os_optsAvmThunkConstant_AvmString_68_____NaN_____thunk

extern AvmBox builtin_a2a_oau_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define avmplus_DescribeType_avmplus_describeTypeJSON_thunk  builtin_a2a_oau_thunk

extern AvmBox builtin_b2a_oas_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Object_private__hasOwnProperty_thunk  builtin_b2a_oas_thunk
#define Object_private__propertyIsEnumerable_thunk  builtin_b2a_oas_thunk

extern AvmBox builtin_i2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define XML_AS3_childIndex_thunk  builtin_i2a_o_thunk
#define XML_prettyIndent_get_thunk  builtin_i2a_o_thunk
#define private_MethodClosure_length_get_thunk  builtin_i2a_o_thunk
#define __AS3___vec_Vector_int_AS3_pop_thunk  builtin_i2a_o_thunk
#define XMLList_AS3_length_thunk  builtin_i2a_o_thunk
#define RegExp_lastIndex_get_thunk  builtin_i2a_o_thunk
#define XMLList_AS3_childIndex_thunk  builtin_i2a_o_thunk
#define Function_length_get_thunk  builtin_i2a_o_thunk

extern AvmBox builtin_b2a_od_optakAvmThunkUndefined_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define isNaN_thunk  builtin_b2a_od_optakAvmThunkUndefined_thunk
#define isFinite_thunk  builtin_b2a_od_optakAvmThunkUndefined_thunk

extern AvmBox builtin_a2a_oa_optsAvmThunkConstant_AvmString_472___________thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define XMLList_AS3_elements_thunk  builtin_a2a_oa_optsAvmThunkConstant_AvmString_472___________thunk
#define XMLList_AS3_descendants_thunk  builtin_a2a_oa_optsAvmThunkConstant_AvmString_472___________thunk
#define XML_AS3_processingInstructions_thunk  builtin_a2a_oa_optsAvmThunkConstant_AvmString_472___________thunk
#define XML_AS3_elements_thunk  builtin_a2a_oa_optsAvmThunkConstant_AvmString_472___________thunk
#define XML_AS3_descendants_thunk  builtin_a2a_oa_optsAvmThunkConstant_AvmString_472___________thunk
#define XMLList_AS3_processingInstructions_thunk  builtin_a2a_oa_optsAvmThunkConstant_AvmString_472___________thunk

extern double builtin_d2d_sd_opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_AS3_charCodeAt_thunk  builtin_d2d_sd_opti0_thunk

extern AvmBox builtin_s2a_oa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Object_private__toString_thunk  builtin_s2a_oa_thunk

extern AvmBox builtin_b2a_oaoa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define __AS3___vec_Vector_double_private__every_thunk  builtin_b2a_oaoa_thunk
#define __AS3___vec_Vector_int_private__some_thunk  builtin_b2a_oaoa_thunk
#define __AS3___vec_Vector_int_private__every_thunk  builtin_b2a_oaoa_thunk
#define Array_private__some_thunk  builtin_b2a_oaoa_thunk
#define __AS3___vec_Vector_double_private__some_thunk  builtin_b2a_oaoa_thunk
#define __AS3___vec_Vector_uint_private__some_thunk  builtin_b2a_oaoa_thunk
#define __AS3___vec_Vector_object_private__every_thunk  builtin_b2a_oaoa_thunk
#define Array_private__every_thunk  builtin_b2a_oaoa_thunk
#define __AS3___vec_Vector_uint_private__every_thunk  builtin_b2a_oaoa_thunk
#define __AS3___vec_Vector_object_private__some_thunk  builtin_b2a_oaoa_thunk

extern AvmBox builtin_i2a_ssi_opti2147483647_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_private__lastIndexOf_thunk  builtin_i2a_ssi_opti2147483647_thunk

extern AvmBox builtin_b2a_oa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define XMLList_AS3_contains_thunk  builtin_b2a_oa_thunk
#define XML_AS3_contains_thunk  builtin_b2a_oa_thunk

extern AvmBox builtin_s2a_s_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_AS3_toLowerCase_thunk  builtin_s2a_s_thunk
#define String_AS3_toUpperCase_thunk  builtin_s2a_s_thunk

extern AvmBox builtin_v2a_oaoa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define __AS3___vec_Vector_double_private__forEach_thunk  builtin_v2a_oaoa_thunk
#define __AS3___vec_Vector_object_private__forEach_thunk  builtin_v2a_oaoa_thunk
#define __AS3___vec_Vector_int_private__forEach_thunk  builtin_v2a_oaoa_thunk
#define __AS3___vec_Vector_uint_private__forEach_thunk  builtin_v2a_oaoa_thunk
#define Array_private__forEach_thunk  builtin_v2a_oaoa_thunk

extern AvmBox builtin_a2a_ooa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define __AS3___vec_Vector_object_private__map_thunk  builtin_a2a_ooa_thunk
#define __AS3___vec_Vector_double_private__filter_thunk  builtin_a2a_ooa_thunk
#define __AS3___vec_Vector_object_private__filter_thunk  builtin_a2a_ooa_thunk
#define __AS3___vec_Vector_int_private__map_thunk  builtin_a2a_ooa_thunk
#define __AS3___vec_Vector_uint_private__map_thunk  builtin_a2a_ooa_thunk
#define __AS3___vec_Vector_int_private__filter_thunk  builtin_a2a_ooa_thunk
#define __AS3___vec_Vector_double_private__map_thunk  builtin_a2a_ooa_thunk
#define __AS3___vec_Vector_uint_private__filter_thunk  builtin_a2a_ooa_thunk

extern AvmBox builtin_s2a_sdd_opti0_opti2147483647_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_AS3_substr_thunk  builtin_s2a_sdd_opti0_opti2147483647_thunk
#define String_AS3_substring_thunk  builtin_s2a_sdd_opti0_opti2147483647_thunk
#define String_AS3_slice_thunk  builtin_s2a_sdd_opti0_opti2147483647_thunk

extern double builtin_d2d_odd_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Math_private__min_thunk  builtin_d2d_odd_thunk
#define Math_private__max_thunk  builtin_d2d_odd_thunk
#define Math_pow_thunk  builtin_d2d_odd_thunk
#define Math_atan2_thunk  builtin_d2d_odd_thunk

extern AvmBox builtin_a2a_n_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Namespace_prefix_get_thunk  builtin_a2a_n_thunk

extern AvmBox builtin_a2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define private_MethodClosure_private_savedThis_get_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_inScopeNamespaces_thunk  builtin_a2a_o_thunk
#define XML_AS3_notification_thunk  builtin_a2a_o_thunk
#define XML_AS3_inScopeNamespaces_thunk  builtin_a2a_o_thunk
#define QName_uri_get_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_children_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_text_thunk  builtin_a2a_o_thunk
#define XML_AS3_attributes_thunk  builtin_a2a_o_thunk
#define __AS3___vec_Vector_object_AS3_pop_thunk  builtin_a2a_o_thunk
#define Class_prototype_get_thunk  builtin_a2a_o_thunk
#define XML_AS3_name_thunk  builtin_a2a_o_thunk
#define XML_AS3_namespaceDeclarations_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_name_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_copy_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_normalize_thunk  builtin_a2a_o_thunk
#define XML_AS3_text_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_namespaceDeclarations_thunk  builtin_a2a_o_thunk
#define Function_prototype_get_thunk  builtin_a2a_o_thunk
#define XML_AS3_children_thunk  builtin_a2a_o_thunk
#define XML_AS3_parent_thunk  builtin_a2a_o_thunk
#define __AS3___vec_Vector_object_private_type_get_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_comments_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_attributes_thunk  builtin_a2a_o_thunk
#define XML_AS3_copy_thunk  builtin_a2a_o_thunk
#define XML_AS3_normalize_thunk  builtin_a2a_o_thunk
#define Array_AS3_pop_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_parent_thunk  builtin_a2a_o_thunk
#define XML_AS3_localName_thunk  builtin_a2a_o_thunk
#define XMLList_AS3_localName_thunk  builtin_a2a_o_thunk
#define XML_AS3_comments_thunk  builtin_a2a_o_thunk

extern AvmBox builtin_a2a_osau_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_private__split_thunk  builtin_a2a_osau_thunk

extern AvmBox builtin_s2a_osaa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_private__replace_thunk  builtin_s2a_osaa_thunk

extern AvmBox builtin_v2a_oasb_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Object_protected__setPropertyIsEnumerable_thunk  builtin_v2a_oasb_thunk

extern AvmBox builtin_a2a_os_optsAvmThunkConstant_AvmString_0__________thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define RegExp_AS3_exec_thunk  builtin_a2a_os_optsAvmThunkConstant_AvmString_0__________thunk

extern AvmBox builtin_u2a_o_rest_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define __AS3___vec_Vector_double_AS3_push_thunk  builtin_u2a_o_rest_thunk
#define __AS3___vec_Vector_object_AS3_push_thunk  builtin_u2a_o_rest_thunk
#define __AS3___vec_Vector_uint_AS3_push_thunk  builtin_u2a_o_rest_thunk
#define Array_AS3_push_thunk  builtin_u2a_o_rest_thunk
#define Array_AS3_unshift_thunk  builtin_u2a_o_rest_thunk
#define __AS3___vec_Vector_int_AS3_unshift_thunk  builtin_u2a_o_rest_thunk
#define __AS3___vec_Vector_uint_AS3_unshift_thunk  builtin_u2a_o_rest_thunk
#define __AS3___vec_Vector_double_AS3_unshift_thunk  builtin_u2a_o_rest_thunk
#define __AS3___vec_Vector_object_AS3_unshift_thunk  builtin_u2a_o_rest_thunk
#define __AS3___vec_Vector_int_AS3_push_thunk  builtin_u2a_o_rest_thunk

extern AvmBox builtin_s2a_oi_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Date_private__toString_thunk  builtin_s2a_oi_thunk
#define Error_getErrorMessage_thunk  builtin_s2a_oi_thunk

extern AvmBox builtin_i2a_ssi_opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_private__indexOf_thunk  builtin_i2a_ssi_opti0_thunk

extern AvmBox builtin_i2a_ssd_optsAvmThunkConstant_AvmString_66_____undefined_____opti2147483647_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_AS3_lastIndexOf_thunk  builtin_i2a_ssd_optsAvmThunkConstant_AvmString_66_____undefined_____opti2147483647_thunk

extern AvmBox builtin_i2a_oaai_opti0_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Array_private__lastIndexOf_thunk  builtin_i2a_oaai_opti0_thunk

extern double builtin_d2d_od_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Date_private__setTime_thunk  builtin_d2d_od_thunk
#define Math_cos_thunk  builtin_d2d_od_thunk
#define Math_ceil_thunk  builtin_d2d_od_thunk
#define Math_acos_thunk  builtin_d2d_od_thunk
#define Math_abs_thunk  builtin_d2d_od_thunk
#define Math_atan_thunk  builtin_d2d_od_thunk
#define Math_asin_thunk  builtin_d2d_od_thunk
#define Math_exp_thunk  builtin_d2d_od_thunk
#define Math_log_thunk  builtin_d2d_od_thunk
#define Math_round_thunk  builtin_d2d_od_thunk
#define Math_tan_thunk  builtin_d2d_od_thunk
#define Math_sin_thunk  builtin_d2d_od_thunk
#define Math_sqrt_thunk  builtin_d2d_od_thunk
#define Math_floor_thunk  builtin_d2d_od_thunk

extern AvmBox builtin_a2a_oaa_optakAvmThunkUndefined_optakAvmThunkUndefined_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Function_AS3_apply_thunk  builtin_a2a_oaa_optakAvmThunkUndefined_optakAvmThunkUndefined_thunk

extern AvmBox builtin_s2a_sii_opti0_opti2147483647_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_private__substr_thunk  builtin_s2a_sii_opti0_opti2147483647_thunk
#define String_private__slice_thunk  builtin_s2a_sii_opti0_opti2147483647_thunk
#define String_private__substring_thunk  builtin_s2a_sii_opti0_opti2147483647_thunk

extern AvmBox builtin_s2a_o_rest_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_AS3_fromCharCode_thunk  builtin_s2a_o_rest_thunk

extern AvmBox builtin_v2a_oa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define XMLList_AS3_setName_thunk  builtin_v2a_oa_thunk
#define __AS3___vec_Vector_object_private_type_set_thunk  builtin_v2a_oa_thunk
#define XMLList_AS3_setLocalName_thunk  builtin_v2a_oa_thunk
#define XMLList_AS3_setNamespace_thunk  builtin_v2a_oa_thunk
#define XML_AS3_setName_thunk  builtin_v2a_oa_thunk
#define XML_AS3_setNamespace_thunk  builtin_v2a_oa_thunk
#define XML_AS3_setLocalName_thunk  builtin_v2a_oa_thunk

extern double builtin_d2d_oa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Date_parse_thunk  builtin_d2d_oa_thunk

extern AvmBox builtin_b2a_oa_optakAvmThunkUndefined_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define XMLList_AS3_propertyIsEnumerable_thunk  builtin_b2a_oa_optakAvmThunkUndefined_thunk
#define XML_AS3_propertyIsEnumerable_thunk  builtin_b2a_oa_optakAvmThunkUndefined_thunk
#define isXMLName_thunk  builtin_b2a_oa_optakAvmThunkUndefined_thunk
#define XMLList_AS3_hasOwnProperty_thunk  builtin_b2a_oa_optakAvmThunkUndefined_thunk
#define XML_AS3_hasOwnProperty_thunk  builtin_b2a_oa_optakAvmThunkUndefined_thunk

extern AvmBox builtin_v2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define __AS3___vec_Vector_double_private__reverse_thunk  builtin_v2a_o_thunk
#define __AS3___vec_Vector_uint_private__reverse_thunk  builtin_v2a_o_thunk
#define __AS3___vec_Vector_object_private__reverse_thunk  builtin_v2a_o_thunk
#define __AS3___vec_Vector_int_private__reverse_thunk  builtin_v2a_o_thunk

extern double builtin_d2d_oi_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Date_private__get_thunk  builtin_d2d_oi_thunk

extern AvmBox builtin_a2a_oaa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define XML_AS3_insertChildAfter_thunk  builtin_a2a_oaa_thunk
#define XMLList_AS3_insertChildBefore_thunk  builtin_a2a_oaa_thunk
#define XMLList_AS3_insertChildAfter_thunk  builtin_a2a_oaa_thunk
#define XML_AS3_insertChildBefore_thunk  builtin_a2a_oaa_thunk
#define XMLList_AS3_replace_thunk  builtin_a2a_oaa_thunk
#define XML_AS3_replace_thunk  builtin_a2a_oaa_thunk

extern AvmBox builtin_b2a_o_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define RegExp_multiline_get_thunk  builtin_b2a_o_thunk
#define __AS3___vec_Vector_double_fixed_get_thunk  builtin_b2a_o_thunk
#define RegExp_dotall_get_thunk  builtin_b2a_o_thunk
#define XMLList_AS3_hasComplexContent_thunk  builtin_b2a_o_thunk
#define XML_prettyPrinting_get_thunk  builtin_b2a_o_thunk
#define __AS3___vec_Vector_uint_fixed_get_thunk  builtin_b2a_o_thunk
#define XML_ignoreComments_get_thunk  builtin_b2a_o_thunk
#define __AS3___vec_Vector_int_fixed_get_thunk  builtin_b2a_o_thunk
#define RegExp_global_get_thunk  builtin_b2a_o_thunk
#define RegExp_ignoreCase_get_thunk  builtin_b2a_o_thunk
#define __AS3___vec_Vector_object_fixed_get_thunk  builtin_b2a_o_thunk
#define XML_AS3_hasSimpleContent_thunk  builtin_b2a_o_thunk
#define XMLList_AS3_hasSimpleContent_thunk  builtin_b2a_o_thunk
#define XML_ignoreWhitespace_get_thunk  builtin_b2a_o_thunk
#define RegExp_extended_get_thunk  builtin_b2a_o_thunk
#define XML_AS3_hasComplexContent_thunk  builtin_b2a_o_thunk
#define XML_ignoreProcessingInstructions_get_thunk  builtin_b2a_o_thunk

extern AvmBox builtin_i2a_osa_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define String_private__search_thunk  builtin_i2a_osa_thunk

extern AvmBox builtin_a2a_oadd_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Array_private__slice_thunk  builtin_a2a_oadd_thunk

extern AvmBox builtin_a2a_oai_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define XMLList_private__namespace_thunk  builtin_a2a_oai_thunk
#define XML_private__namespace_thunk  builtin_a2a_oai_thunk

extern AvmBox builtin_i2a_oaai_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Array_private__indexOf_thunk  builtin_i2a_oaai_thunk

extern AvmBox builtin_s2a_odii_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Number_private__convert_thunk  builtin_s2a_odii_thunk

extern double builtin_d2d_odd_optdkAvmThunkInfinity_optdkAvmThunkInfinity_rest_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define Math_min_thunk  builtin_d2d_odd_optdkAvmThunkInfinity_optdkAvmThunkInfinity_rest_thunk

extern AvmBox builtin_a2a_oao_thunk(AvmMethodEnv env, uint32_t argc, AvmBox* argv);
#define __AS3___vec_Vector_uint_private__sort_thunk  builtin_a2a_oao_thunk
#define __AS3___vec_Vector_object_private__sort_thunk  builtin_a2a_oao_thunk
#define Array_private__splice_thunk  builtin_a2a_oao_thunk
#define __AS3___vec_Vector_int_private__sort_thunk  builtin_a2a_oao_thunk
#define __AS3___vec_Vector_double_private__sort_thunk  builtin_a2a_oao_thunk
#define Array_private__concat_thunk  builtin_a2a_oao_thunk
#define Array_private__sort_thunk  builtin_a2a_oao_thunk

