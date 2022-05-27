#include <md4c-html.h>

#include <stddef.h>
#include <string.h>

/* Callback.
 */
static void
process_output (const MD_CHAR* data, MD_SIZE size, void* userdata)
{
  /* Suppress warnings.
   */
  (void)data;
  (void)size;
  (void)userdata;
}

int
main ()
{
  const char* md = "**Hello World**";
  if (md_html (md, strlen (md), process_output, NULL, 0, 0) != 0)
    return 1;

  return 0;
}
