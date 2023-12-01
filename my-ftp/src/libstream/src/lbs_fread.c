/*
** lbs_fread.c for libstream
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Thu Oct  2 17:02:16 2008 david bertet
** Last update Sun Oct 26 00:58:03 2008 david bertet
*/

#include <stdio.h>
#include "../include/libstream.h"

size_t			lbs_fread(void		*ptr,
				  size_t	size,
				  size_t	nmemb,
				  s_stream	*stream)
{
  size_t		i;
  size_t		j;
  int			pos;
  unsigned char*	res = NULL;
  int			tmp;

  res = ptr;
  if (!size || !nmemb)
    return (0);

  for (i = 0; i < nmemb; ++i)
    for (j = 0; j < size; ++j)
      {
	pos = i * size + j;
	tmp = lbs_fgetc_str(stream);
	if (tmp == LBS_EOF)
	  return (i);
	res[pos] = tmp;
      }

  return (nmemb);
}
