/*
** lbs_write.c for libstream
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Thu Oct  2 17:02:16 2008 david bertet
** Last update Tue Oct 21 22:05:47 2008 david bertet
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/libstream.h"

size_t			lbs_fwrite(const void	*ptr,
				   size_t	size,
				   size_t	nmemb,
				   s_stream	*stream)
{
  size_t		i;
  size_t		j;
  int			pos;
  const unsigned char*	res = NULL;

  res = ptr;
  if (!size || !nmemb)
    return (0);

  for (i = 0; i < nmemb; ++i)
      for (j = 0; j < size; ++j)
	{
	  pos = i * size + j;
	  if (lbs_fputc(res[pos], stream) == LBS_EOF)
	    return (i);
	}
  return (nmemb);
}
