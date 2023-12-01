/*
** lbs_fdopen.c for libstream
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Wed Oct  1 14:24:53 2008 david bertet
** Last update Sun Oct  5 04:39:04 2008 david bertet
*/

#include <stdlib.h>
#include "../include/libstream.h"
#include "lbs_utils.h"

s_stream	*lbs_fdopen(int		fildes,
			    const char	*mode)
{
  s_stream	*stream = NULL;
  int		flag;

  if ((flag = find_mode_princ(mode)) == -1)
    return (NULL);

  stream = malloc(sizeof (s_stream));
  stream->mode = flag;
  stream->path = "";
  stream->fd = fildes;
  stream->size_rd = 0;
  stream->pos_wr = 0;
  stream->pos_rd = LBS_READ_SIZE;

  return (stream);
}
