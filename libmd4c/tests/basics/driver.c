#include <md4c.h>

#include <stddef.h>
#include <string.h>

#ifdef MD4C_USE_UTF16
#  include <wchar.h>
#  define MD_TEXT(s) L##s
#  define md_strlen wcslen
#else
#  define MD_TEXT(s) s
#  define md_strlen strlen
#endif

/* Callbacks. */

static int
block (MD_BLOCKTYPE type, void* detail, void* userdata)
{
  /* Suppress warnings.
   */
  (void)type;
  (void)detail;
  (void)userdata;

  return 0;
}

static int
span (MD_SPANTYPE type, void* detail, void* userdata)
{
  (void)type;
  (void)detail;
  (void)userdata;

  return 0;
}

static int
text (MD_TEXTTYPE type, const MD_CHAR* text, MD_SIZE size, void* userdata)
{
  (void)type;
  (void)text;
  (void)size;
  (void)userdata;

  return 0;
}

int
main (void)
{
  MD_PARSER callbacks = {0, 0, block, block, span, span, text, NULL, NULL};
  const MD_CHAR* md = MD_TEXT ("**Hello World**");
  if (md_parse (md, (MD_SIZE) md_strlen (md), &callbacks, NULL) != 0)
    return 1;

  return 0;
}
