/*
** lbs_fputs.c for libstream
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Thu Oct  2 23:34:28 2008 david bertet
** Last update Fri Oct  3 21:39:21 2008 david bertet
*/

#include "../include/libstream.h"

int	lbs_fputs(const char	*str,
		  s_stream	*stream)
{
  int	i;

  for (i = 0; str[i] != '\0'; ++i)
    if (lbs_fputc(str[i], stream) == LBS_EOF)
      return (LBS_EOF);

  return (0);
}
