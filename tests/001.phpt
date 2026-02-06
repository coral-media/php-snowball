--TEST--
snowball_version() returns a string
--SKIPIF--
<?php
if (!extension_loaded('snowball')) {
    echo 'skip snowball not loaded';
}
?>
--FILE--
<?php
var_dump(is_string(snowball_version()));
?>
--EXPECT--
bool(true)
