--TEST--
snowball_stem_array() stems arrays
--SKIPIF--
<?php
if (!extension_loaded('snowball')) {
    echo 'skip snowball not loaded';
}
?>
--FILE--
<?php
$words = ['running', 'jumps'];
var_dump(snowball_stem_array($words));
?>
--EXPECT--
array(2) {
  [0]=>
  string(3) "run"
  [1]=>
  string(4) "jump"
}
