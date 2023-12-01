/*
** lbs_fgets.c for libstream
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Thu Oct  2 22:44:08 2008 david bertet
** Last update Tue Oct 21 22:06:37 2008 david bertet
*/

#include <stdlib.h>
#include <errno.h>
#include "../include/libstream.h"

char		*lbs_fgets(char		*str,
			   int		size,
			   s_stream	*stream)
{
  int		i;
  int		tmp;

  errno = 0;
  for (i = 0; i < size - 1; ++i)
    {
      tmp = lbs_fgetc(stream);
      if (tmp == '\n')
	{
	  str[i] = '\n';
	  if (i + 1 < size - 1)
	    str[i + 1] = '\0';
	  return (str);
	}
      if (tmp == LBS_EOF && errno == 0)
	{
	  if (i < size - 1)
	    str[i] = '\0';
	  return (str);
	}
      if (tmp == LBS_EOF)
	return (NULL);
      str[i] = tmp;
    }
  str[i] = '\0';
  return (str);
}
