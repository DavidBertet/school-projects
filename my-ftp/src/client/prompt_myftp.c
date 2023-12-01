#include "const_myftp.h"

char	*print_prompt(void)
{
  if (isatty(STDIN_FILENO))
    return ("\033[0;32mmyFTP\033[0;31m>\033[0;37m ");

  return (NULL);
}
