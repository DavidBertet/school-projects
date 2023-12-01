#include "const_myftp.h"

char    *get_filename(char      *str)
{
  int   i;

  for (i = my_strlen(str) - 1; i >= 0 &&
         str[i] != '/' && str[i] != ' '; --i)
    continue;

  return (str + i + 1);
}

void    print_string(char       *str,
                     int        fd,
                     int        size)
{
  if (size == 0)
    write(fd, str, my_strlen(str));
  else
    write(fd, str, size);

  return;
}

void    my_uppercase_cmd(char   *str)
{
  int   i;

  for (i = 0; str[i] && str[i] != ' '; ++i)
    if (str[i] >= 'a' && str[i] <= 'z')
      str[i] = str[i] + 'A' - 'a';

  return;
}

int     is_number(char  c)
{
  if (c >= '0' && c <= '9')
    return (1);
  else
    return (0);
}

int     is_end_cmd(char *str)
{
  int   i;

  for (i = 0; str[i] && i < 3; ++i)
    if (!is_number(str[i]))
      return (0);

  if (str[i] == ' ')
    return (1);
  else
    return (0);
}
