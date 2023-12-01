/*
** lbs_getdelim.c for libstream
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Sat Oct  4 15:35:14 2008 david bertet
** Last update Sun Oct 26 08:15:09 2008 david bertet
*/

#include <errno.h>
#include <stdlib.h>
#include "../include/libstream.h"

static int	resize(char	**lineptr,
		       int	size,
		       size_t	*n,
		       int	*pos)
{
  if (!(*lineptr = realloc(*lineptr, *n + size)))
    {
      *pos = -1;
      return (1);
    }
  *n += size;
  return (0);
}

static void	nice_coding_style(char		***lineptr,
				  size_t	**n,
				  int		*p)
{
  if (!**lineptr)
    **n = 0;
  *p = 1;
  return;
}

ssize_t		lbs_getdelim(char	**lineptr,
			     size_t	*n,
			     int	delimiter,
			     s_stream	*stream)
{
  int		p = -1;
  int		size = 50;
  char		c;
  int		mycast;

  if (!lineptr || !n || !stream)
    errno = EINVAL;
  else
    {
      nice_coding_style(&lineptr, &n, &p);
      while (1)
	{
	  mycast = *n;
	  if (p >= mycast)
	    if (resize(lineptr, size, n, &p))
	      break;
	  if ((c = lbs_fgetc(stream)) > 0 && ((*lineptr)[++p - 2] = c))
	    if (c != delimiter)
	      continue;
	  if ((p -= 2) >= 0)
	    (*lineptr)[++p] = '\0';
	  break;
	}
    }
  return (p);
}

ssize_t		lbs_getdelim_str(char		**lineptr,
				 size_t		*n,
				 int		delimiter,
				 s_stream	*stream)
{
  int		p = -1;
  int		size = 50;
  char		c;
  int		mycast;

  if (!lineptr || !n || !stream)
    errno = EINVAL;
  else
    {
      nice_coding_style(&lineptr, &n, &p);
      while (1)
	{
	  mycast = *n;
	  if (p >= mycast)
	    if (resize(lineptr, size, n, &p))
	      break;
	  if ((c = lbs_fgetc_str(stream)) > LBS_EOF && ((*lineptr)[++p - 2] = c))
	    if (c != delimiter)
	      continue;
	  if ((p -= 2) >= 0)
	    (*lineptr)[++p] = '\0';
	  break;
	}
    }
  return (p);
}
