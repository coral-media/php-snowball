<?php
/** @generate-arginfo */
/**
 * Returns coral-media/php-snowball version
 * 
 * @return string
 */
function snowball_version(): string {}

/**
 * Stem a word using Snowball.
 *
 * @param string $word
 * @param string|null $language Defaults to "english" when omitted or empty.
 * @param string|null $encoding Defaults to "UTF_8" when omitted or empty.
 * @return string
 */
function snowball_stem(string $word, ?string $language = null, ?string $encoding = null): string {}

/**
 * Stem an array of words using Snowball.
 *
 * @param string[] $words
 * @param string|null $language Defaults to "english" when omitted or empty.
 * @param string|null $encoding Defaults to "UTF_8" when omitted or empty.
 * @return string[]
 */
function snowball_stem_array(array $words, ?string $language = null, ?string $encoding = null): array {}

/**
 * Snowball encoding constants.
 */
/** @var string */
const SNOWBALL_ENCODING_UTF_8 = "UTF_8";
/** @var string */
const SNOWBALL_ENCODING_ISO_8859_1 = "ISO_8859_1";
/** @var string */
const SNOWBALL_ENCODING_ISO_8859_2 = "ISO_8859_2";
/** @var string */
const SNOWBALL_ENCODING_KOI8_R = "KOI8_R";

/**
 * Snowball language constants (primary).
 */
/** @var string */
const SNOWBALL_LANG_DA = "danish";
/** @var string */
const SNOWBALL_LANG_NL = "dutch";
/** @var string */
const SNOWBALL_LANG_EN = "english";
/** @var string */
const SNOWBALL_LANG_FI = "finnish";
/** @var string */
const SNOWBALL_LANG_FR = "french";
/** @var string */
const SNOWBALL_LANG_DE = "german";
/** @var string */
const SNOWBALL_LANG_HU = "hungarian";
/** @var string */
const SNOWBALL_LANG_IT = "italian";
/** @var string */
const SNOWBALL_LANG_NO = "norwegian";
/** @var string */
const SNOWBALL_LANG_PT = "portuguese";
/** @var string */
const SNOWBALL_LANG_RO = "romanian";
/** @var string */
const SNOWBALL_LANG_RU = "russian";
/** @var string */
const SNOWBALL_LANG_ES = "spanish";
/** @var string */
const SNOWBALL_LANG_SV = "swedish";
/** @var string */
const SNOWBALL_LANG_TR = "turkish";

/**
 * Snowball language constants (aliases).
 */
/** @var string */
const SNOWBALL_LANG_DANISH = "danish";
/** @var string */
const SNOWBALL_LANG_DUTCH = "dutch";
/** @var string */
const SNOWBALL_LANG_ENGLISH = "english";
/** @var string */
const SNOWBALL_LANG_FINNISH = "finnish";
/** @var string */
const SNOWBALL_LANG_FRENCH = "french";
/** @var string */
const SNOWBALL_LANG_GERMAN = "german";
/** @var string */
const SNOWBALL_LANG_HUNGARIAN = "hungarian";
/** @var string */
const SNOWBALL_LANG_ITALIAN = "italian";
/** @var string */
const SNOWBALL_LANG_NORWEGIAN = "norwegian";
/** @var string */
const SNOWBALL_LANG_PORTUGUESE = "portuguese";
/** @var string */
const SNOWBALL_LANG_ROMANIAN = "romanian";
/** @var string */
const SNOWBALL_LANG_RUSSIAN = "russian";
/** @var string */
const SNOWBALL_LANG_SPANISH = "spanish";
/** @var string */
const SNOWBALL_LANG_SWEDISH = "swedish";
/** @var string */
const SNOWBALL_LANG_TURKISH = "turkish";
