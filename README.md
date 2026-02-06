# coral-media/php-snowball (PHP extension)

Minimal PECL-style scaffold for a Snowball (libstemmer) extension with vendored sources.

## Install using PIE

From sources

```sh
pie install --with-snowball
```

From [Packagist](https://packagist.org)

```sh
pie install coral-media/php-snowball --with-snowball
```

Further info [PIE official repository](https://github.com/php/pie)

## Build (from source)

```sh
phpize
./configure --with-snowball
make -j"$(nproc)"
make install
```

## Windows support

Check the [releases](https://github.com/coral-media/php-snowball/releases/) page. Download the compatible asset with your PHP version and make sure you load the extension in `php.ini`.

## Usage

Basic stemming (defaults to English + UTF_8):

```php
<?php
echo snowball_stem('running'); // run
```

Explicit language + encoding:

```php
<?php
echo snowball_stem('corriendo', SNOWBALL_LANG_ES, SNOWBALL_ENCODING_UTF_8); // corr
```

## Documentation

- Generated [API docs](https://coral-media.github.io/php-snowball/docs/api/Home)
- Official [Snowball Website](https://snowballstem.org/)

## Notes

- Vendored libstemmer sources live under `lib/libstemmer`.
- If PIE install or building from source fails with `'make' '-j10'" failed` try `--make-parallel-jobs 1`. Same procedure with `make -j` if building from sources. Adjust to any convenient value.
