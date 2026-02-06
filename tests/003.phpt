--TEST--
Snowball encoding constants exist
--SKIPIF--
<?php
if (!extension_loaded('snowball')) {
    echo 'skip snowball not loaded';
}
?>
--FILE--
<?php
var_dump(
    SNOWBALL_ENCODING_UTF_8,
    SNOWBALL_ENCODING_ISO_8859_1,
    SNOWBALL_ENCODING_ISO_8859_2,
    SNOWBALL_ENCODING_KOI8_R
);
?>
--EXPECT--
string(5) "UTF_8"
string(10) "ISO_8859_1"
string(10) "ISO_8859_2"
string(6) "KOI8_R"
