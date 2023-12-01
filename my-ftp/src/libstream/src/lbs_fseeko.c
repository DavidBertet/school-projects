/*
** lbs_fseeko.c for libstream
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Wed Oct  1 15:51:42 2008 david bertet
** Last update Sun Oct 26 06:54:18 2008 david bertet
*/

#include <unistd.h>
#include "../include/libstream.h"

int	lbs_fseeko(s_stream	*stream,
		   t_offset	offset,
		   int		whence)
{
  stream = stream;
  offset = offset;
  whence = whence;
  return (1);
}
