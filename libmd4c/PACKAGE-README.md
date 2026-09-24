# libmd4c - Markdown parser C library

This is a `build2` package for the [MD4C](https://github.com/mity/md4c)
C library. It provides a Markdown parser implementation in C.

MD4C parses the complete document and calls callback functions provided
by the application to inform it about a start/end of every block, a
start/end of every span, and about any textual contents.


## Usage

To start using `libmd4c` in your project, add the following `depends`
value to your `manifest`, adjusting the version constraint as appropriate:

```
depends: libmd4c ^0.6.0
```

Then import the library in your `buildfile`:

```
import libs = libmd4c%lib{md4c}
import libs += libmd4c%lib{md4c-html}
```


## Importable targets

This package provides the following importable targets:

```
lib{md4c}
lib{md4c-html}
```

`lib{md4c}` is the Markdown parser. Include `<md4c.h>`.

`lib{md4c-html}` renders Markdown to HTML. Include `<md4c-html.h>`.
It links `lib{md4c}`.


## Configuration variables

This package provides the following configuration variables:

```
[bool]   config.libmd4c.debug    ?= false
[string] config.libmd4c.encoding ?= 'utf8'
```

If `config.libmd4c.debug` is true, compile with `-DDEBUG`.

`config.libmd4c.encoding` selects the input encoding the parser expects:

* `utf8`: UTF-8 input (default).

* `ascii`: ASCII-only input. Non-ASCII whitespace and punctuation are not
  recognized as such, and link reference matching is case-insensitive only
  for ASCII letters.

* `utf16`: UTF-16 input, with `MD_CHAR` defined as `WCHAR`. This is only
  supported on Windows. It changes the types in `<md4c.h>`, so
  `MD4C_USE_UTF16` is also defined for consumers of `lib{md4c}`. The HTML
  renderer does not support it, so `lib{md4c-html}` is not available.

A dependent can request a specific encoding in its `manifest`, for example:

```
depends: libmd4c ^0.6.0 { require { config.libmd4c.encoding = 'ascii' } }
```
