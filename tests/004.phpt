--TEST--
Snowball language constants and aliases exist
--SKIPIF--
<?php
if (!extension_loaded('snowball')) {
    echo 'skip snowball not loaded';
}
?>
--FILE--
<?php
var_dump(
    SNOWBALL_LANG_DA,
    SNOWBALL_LANG_DANISH,
    SNOWBALL_LANG_NL,
    SNOWBALL_LANG_DUTCH,
    SNOWBALL_LANG_EN,
    SNOWBALL_LANG_ENGLISH,
    SNOWBALL_LANG_FI,
    SNOWBALL_LANG_FINNISH,
    SNOWBALL_LANG_FR,
    SNOWBALL_LANG_FRENCH,
    SNOWBALL_LANG_DE,
    SNOWBALL_LANG_GERMAN,
    SNOWBALL_LANG_HU,
    SNOWBALL_LANG_HUNGARIAN,
    SNOWBALL_LANG_IT,
    SNOWBALL_LANG_ITALIAN,
    SNOWBALL_LANG_NO,
    SNOWBALL_LANG_NORWEGIAN,
    SNOWBALL_LANG_PT,
    SNOWBALL_LANG_PORTUGUESE,
    SNOWBALL_LANG_RO,
    SNOWBALL_LANG_ROMANIAN,
    SNOWBALL_LANG_RU,
    SNOWBALL_LANG_RUSSIAN,
    SNOWBALL_LANG_ES,
    SNOWBALL_LANG_SPANISH,
    SNOWBALL_LANG_SV,
    SNOWBALL_LANG_SWEDISH,
    SNOWBALL_LANG_TR,
    SNOWBALL_LANG_TURKISH
);
?>
--EXPECT--
string(6) "danish"
string(6) "danish"
string(5) "dutch"
string(5) "dutch"
string(7) "english"
string(7) "english"
string(7) "finnish"
string(7) "finnish"
string(6) "french"
string(6) "french"
string(6) "german"
string(6) "german"
string(9) "hungarian"
string(9) "hungarian"
string(7) "italian"
string(7) "italian"
string(9) "norwegian"
string(9) "norwegian"
string(10) "portuguese"
string(10) "portuguese"
string(8) "romanian"
string(8) "romanian"
string(7) "russian"
string(7) "russian"
string(7) "spanish"
string(7) "spanish"
string(7) "swedish"
string(7) "swedish"
string(7) "turkish"
string(7) "turkish"
