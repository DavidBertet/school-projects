/*
** lbs_utils.c for libstream
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Wed Oct  1 15:30:38 2008 david bertet
** Last update Tue Oct 21 22:04:56 2008 david bertet
*/

#include <fcntl.h>
#include "lbs_utils.h"

int	find_mode_sec(const char	*flag, int	res)
{
  int	i;

  for (i = 0; *++flag; ++i)
    {
      switch (*flag)
	{
	  case SEOF:
	    break;
	  case SPLUS:
	    res = O_RDWR;
	    break;
	  case SBINARY:
	    break;
	  default:
	    return (-1);
	}
    }

  return (res);
}

int	find_mode_princ(const char	*flag)
{
  int	res = 0;
  int	res_right = 0;

  switch (*flag)
    {
      case SREAD:
	res_right = O_RDONLY;
	break;
      case SWRITE:
	res_right = O_WRONLY;
	res = O_CREAT | O_TRUNC;
	break;
      case SAPPEND:
	res_right = O_WRONLY;
	res = O_APPEND | O_CREAT;
	break;
      default:
	return (-1);
    }
  res_right = find_mode_sec(flag, res_right);

  res |= res_right;
  return (res);
}
