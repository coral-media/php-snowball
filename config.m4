PHP_ARG_WITH([snowball],
  [for Snowball stemming support],
  [AS_HELP_STRING([--with-snowball], [Include vendored Snowball (libstemmer) support])],
  [yes],
  [yes])

if test "$PHP_SNOWBALL" != "no"; then
  SNOWBALL_SRC_DIR=""

  if test -d "$ext_srcdir/lib/libstemmer"; then
    SNOWBALL_SRC_DIR="$ext_srcdir/lib/libstemmer"
  elif test -d "$srcdir/lib/libstemmer"; then
    SNOWBALL_SRC_DIR="$srcdir/lib/libstemmer"
  elif test -d "./lib/libstemmer"; then
    SNOWBALL_SRC_DIR="./lib/libstemmer"
  else
    AC_MSG_ERROR([Vendored libstemmer not found in lib/libstemmer.])
  fi

  PHP_ADD_INCLUDE("$SNOWBALL_SRC_DIR")
  PHP_ADD_INCLUDE("$SNOWBALL_SRC_DIR/include")
  PHP_ADD_INCLUDE("$SNOWBALL_SRC_DIR/runtime")
  PHP_ADD_INCLUDE("$SNOWBALL_SRC_DIR/src_c")

  SNOWBALL_SOURCES="\
lib/libstemmer/src_c/stem_ISO_8859_1_danish.c \
lib/libstemmer/src_c/stem_UTF_8_danish.c \
lib/libstemmer/src_c/stem_ISO_8859_1_dutch.c \
lib/libstemmer/src_c/stem_UTF_8_dutch.c \
lib/libstemmer/src_c/stem_ISO_8859_1_english.c \
lib/libstemmer/src_c/stem_UTF_8_english.c \
lib/libstemmer/src_c/stem_ISO_8859_1_finnish.c \
lib/libstemmer/src_c/stem_UTF_8_finnish.c \
lib/libstemmer/src_c/stem_ISO_8859_1_french.c \
lib/libstemmer/src_c/stem_UTF_8_french.c \
lib/libstemmer/src_c/stem_ISO_8859_1_german.c \
lib/libstemmer/src_c/stem_UTF_8_german.c \
lib/libstemmer/src_c/stem_ISO_8859_1_hungarian.c \
lib/libstemmer/src_c/stem_UTF_8_hungarian.c \
lib/libstemmer/src_c/stem_ISO_8859_1_italian.c \
lib/libstemmer/src_c/stem_UTF_8_italian.c \
lib/libstemmer/src_c/stem_ISO_8859_1_norwegian.c \
lib/libstemmer/src_c/stem_UTF_8_norwegian.c \
lib/libstemmer/src_c/stem_ISO_8859_1_porter.c \
lib/libstemmer/src_c/stem_UTF_8_porter.c \
lib/libstemmer/src_c/stem_ISO_8859_1_portuguese.c \
lib/libstemmer/src_c/stem_UTF_8_portuguese.c \
lib/libstemmer/src_c/stem_ISO_8859_2_romanian.c \
lib/libstemmer/src_c/stem_UTF_8_romanian.c \
lib/libstemmer/src_c/stem_KOI8_R_russian.c \
lib/libstemmer/src_c/stem_UTF_8_russian.c \
lib/libstemmer/src_c/stem_ISO_8859_1_spanish.c \
lib/libstemmer/src_c/stem_UTF_8_spanish.c \
lib/libstemmer/src_c/stem_ISO_8859_1_swedish.c \
lib/libstemmer/src_c/stem_UTF_8_swedish.c \
lib/libstemmer/src_c/stem_UTF_8_turkish.c \
lib/libstemmer/runtime/api.c \
lib/libstemmer/runtime/utilities.c \
lib/libstemmer/libstemmer/libstemmer.c"

  AC_DEFINE(HAVE_SNOWBALL, 1, [Have Snowball (libstemmer)])
  PHP_NEW_EXTENSION(snowball, snowball.c $SNOWBALL_SOURCES, $ext_shared)
fi
