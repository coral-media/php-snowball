--TEST--
snowball_stem() stems words (defaults to English + UTF_8)
--SKIPIF--
<?php
if (!extension_loaded('snowball')) {
    echo 'skip snowball not loaded';
}
?>
--FILE--
<?php
var_dump(snowball_stem('running'));
?>
--EXPECT--
string(3) "run"
