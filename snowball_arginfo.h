/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 1e276bd4cfb743ddacaaebfbc209a336c719ddbb */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_snowball_version, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_snowball_stem, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, word, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, language, IS_STRING, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, encoding, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_snowball_stem_array, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, words, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, language, IS_STRING, 1, "null")
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, encoding, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()
