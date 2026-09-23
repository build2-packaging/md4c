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
[bool] config.libmd4c.debug ?= false
```

If true, compile with `-DDEBUG`.
