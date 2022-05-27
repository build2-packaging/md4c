#include <md4c.h>

#include <stddef.h>
#include <string.h>

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
main ()
{
  MD_PARSER callbacks = {0, 0, block, block, span, span, text, NULL, NULL};
  const char* md = "**Hello World**";
  if (md_parse (md, strlen (md), &callbacks, NULL) != 0)
    return 1;

  return 0;
}
