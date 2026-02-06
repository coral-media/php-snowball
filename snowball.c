#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_snowball.h"
#include <libstemmer.h>
#include "snowball_arginfo.h"

PHP_FUNCTION(snowball_version)
{
#ifdef HAVE_SNOWBALL
  RETURN_STRING(PHP_SNOWBALL_VERSION);
#else
  RETURN_STRING("no-libstemmer");
#endif
}

PHP_FUNCTION(snowball_stem)
{
  char *word = NULL;
  char *language = NULL;
  char *encoding = NULL;
  size_t word_len = 0;
  size_t language_len = 0;
  size_t encoding_len = 0;

  ZEND_PARSE_PARAMETERS_START(1, 3)
    Z_PARAM_STRING(word, word_len)
    Z_PARAM_OPTIONAL
    Z_PARAM_STRING(language, language_len)
    Z_PARAM_OPTIONAL
    Z_PARAM_STRING(encoding, encoding_len)
  ZEND_PARSE_PARAMETERS_END();

#ifdef HAVE_SNOWBALL
  const char *language_cstr = "english";
  if (language != NULL && language_len > 0) {
    language_cstr = language;
  }

  const char *encoding_cstr = "UTF_8";
  if (encoding != NULL && encoding_len > 0) {
    encoding_cstr = encoding;
  }

  struct sb_stemmer *stemmer = sb_stemmer_new(language_cstr, encoding_cstr);
  if (stemmer == NULL) {
    zend_throw_error(NULL, "Unknown or unsupported language '%s'", language_cstr);
    RETURN_THROWS();
  }

  const sb_symbol *result = sb_stemmer_stem(stemmer, (const sb_symbol *) word, (int) word_len);
  if (result == NULL) {
    sb_stemmer_delete(stemmer);
    zend_throw_error(NULL, "Snowball stemming failed");
    RETURN_THROWS();
  }

  int result_len = sb_stemmer_length(stemmer);
  RETVAL_STRINGL((const char *) result, result_len);
  sb_stemmer_delete(stemmer);
#else
  zend_throw_error(NULL, "Snowball library not available");
  RETURN_THROWS();
#endif
}

static const zend_function_entry snowball_functions[] = {
  PHP_FE(snowball_version, arginfo_snowball_version)
  PHP_FE(snowball_stem, arginfo_snowball_stem)
  PHP_FE_END
};

PHP_MINIT_FUNCTION(snowball)
{
  REGISTER_STRING_CONSTANT("SNOWBALL_ENCODING_UTF_8", "UTF_8", CONST_CS | CONST_PERSISTENT);
  REGISTER_STRING_CONSTANT("SNOWBALL_ENCODING_ISO_8859_1", "ISO_8859_1", CONST_CS | CONST_PERSISTENT);
  REGISTER_STRING_CONSTANT("SNOWBALL_ENCODING_ISO_8859_2", "ISO_8859_2", CONST_CS | CONST_PERSISTENT);
  REGISTER_STRING_CONSTANT("SNOWBALL_ENCODING_KOI8_R", "KOI8_R", CONST_CS | CONST_PERSISTENT);

  REGISTER_STRING_CONSTANT("SNOWBALL_LANG_DA", "danish", CONST_CS | CONST_PERSISTENT);
  REGISTER_STRING_CONSTANT("SNOWBALL_LANG_DANISH", "danish", CONST_CS | CONST_PERSISTENT);
  REGISTER_STRING_CONSTANT("SNOWBALL_LANG_NL", "dutch", CONST_CS | CONST_PERSISTENT);
  REGISTER_STRING_CONSTANT("SNOWBALL_LANG_DUTCH", "dutch", CONST_CS | CONST_PERSISTENT);
  REGISTER_STRING_CONSTANT("SNOWBALL_LANG_EN", "english", CONST_CS | CONST_PERSISTENT);
  REGISTER_STRING_CONSTANT("SNOWBALL_LANG_ENGLISH", "english", CONST_CS | CONST_PERSISTENT);
  REGISTER_STRING_CONSTANT("SNOWBALL_LANG_FI", "finnish", CONST_CS | CONST_PERSISTENT);
  REGISTER_STRING_CONSTANT("SNOWBALL_LANG_FINNISH", "finnish", CONST_CS | CONST_PERSISTENT);
  REGISTER_STRING_CONSTANT("SNOWBALL_LANG_FR", "french", CONST_CS | CONST_PERSISTENT);
  REGISTER_STRING_CONSTANT("SNOWBALL_LANG_FRENCH", "french", CONST_CS | CONST_PERSISTENT);
  REGISTER_STRING_CONSTANT("SNOWBALL_LANG_DE", "german", CONST_CS | CONST_PERSISTENT);
  REGISTER_STRING_CONSTANT("SNOWBALL_LANG_GERMAN", "german", CONST_CS | CONST_PERSISTENT);
  REGISTER_STRING_CONSTANT("SNOWBALL_LANG_HU", "hungarian", CONST_CS | CONST_PERSISTENT);
  REGISTER_STRING_CONSTANT("SNOWBALL_LANG_HUNGARIAN", "hungarian", CONST_CS | CONST_PERSISTENT);
  REGISTER_STRING_CONSTANT("SNOWBALL_LANG_IT", "italian", CONST_CS | CONST_PERSISTENT);
  REGISTER_STRING_CONSTANT("SNOWBALL_LANG_ITALIAN", "italian", CONST_CS | CONST_PERSISTENT);
  REGISTER_STRING_CONSTANT("SNOWBALL_LANG_NO", "norwegian", CONST_CS | CONST_PERSISTENT);
  REGISTER_STRING_CONSTANT("SNOWBALL_LANG_NORWEGIAN", "norwegian", CONST_CS | CONST_PERSISTENT);
  REGISTER_STRING_CONSTANT("SNOWBALL_LANG_PT", "portuguese", CONST_CS | CONST_PERSISTENT);
  REGISTER_STRING_CONSTANT("SNOWBALL_LANG_PORTUGUESE", "portuguese", CONST_CS | CONST_PERSISTENT);
  REGISTER_STRING_CONSTANT("SNOWBALL_LANG_RO", "romanian", CONST_CS | CONST_PERSISTENT);
  REGISTER_STRING_CONSTANT("SNOWBALL_LANG_ROMANIAN", "romanian", CONST_CS | CONST_PERSISTENT);
  REGISTER_STRING_CONSTANT("SNOWBALL_LANG_RU", "russian", CONST_CS | CONST_PERSISTENT);
  REGISTER_STRING_CONSTANT("SNOWBALL_LANG_RUSSIAN", "russian", CONST_CS | CONST_PERSISTENT);
  REGISTER_STRING_CONSTANT("SNOWBALL_LANG_ES", "spanish", CONST_CS | CONST_PERSISTENT);
  REGISTER_STRING_CONSTANT("SNOWBALL_LANG_SPANISH", "spanish", CONST_CS | CONST_PERSISTENT);
  REGISTER_STRING_CONSTANT("SNOWBALL_LANG_SV", "swedish", CONST_CS | CONST_PERSISTENT);
  REGISTER_STRING_CONSTANT("SNOWBALL_LANG_SWEDISH", "swedish", CONST_CS | CONST_PERSISTENT);
  REGISTER_STRING_CONSTANT("SNOWBALL_LANG_TR", "turkish", CONST_CS | CONST_PERSISTENT);
  REGISTER_STRING_CONSTANT("SNOWBALL_LANG_TURKISH", "turkish", CONST_CS | CONST_PERSISTENT);
  return SUCCESS;
}

PHP_MINFO_FUNCTION(snowball)
{
  php_info_print_table_start();
  php_info_print_table_header(2, "snowball support", "enabled");
#ifdef HAVE_SNOWBALL
  php_info_print_table_row(2, "libstemmer", "available");
#else
  php_info_print_table_row(2, "libstemmer", "not available");
#endif
  php_info_print_table_end();
}

zend_module_entry snowball_module_entry = {
  STANDARD_MODULE_HEADER,
  "snowball",
  snowball_functions,
  PHP_MINIT(snowball),
  NULL,
  NULL,
  NULL,
  PHP_MINFO(snowball),
  PHP_SNOWBALL_VERSION,
  STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_SNOWBALL
ZEND_GET_MODULE(snowball)
#endif
