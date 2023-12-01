/*
** lbs_fopen.c for libstream
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Tue Sep 30 18:08:44 2008 david bertet
** Last update Fri Oct 24 01:25:51 2008 david bertet
*/

#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include "../include/libstream.h"
#include "lbs_utils.h"

s_g	*g_s = NULL;

void	add_stream(s_stream	*stream)
{
  s_g	*tmp = NULL;

  tmp = malloc(sizeof (s_g));
  tmp->stream = stream;
  tmp->next = g_s;

  g_s = tmp;
}

s_stream	*lbs_fopen(const char	*path,
			   const char	*mode)
{
  s_stream	*stream = NULL;
  int		flag;
  int		fd;

  if ((flag = find_mode_princ(mode)) == -1)
    {
      errno = EINVAL;
      return (NULL);
    }

  if ((fd = open(path, flag, 0644)) == -1)
    return (NULL);

  stream = malloc(sizeof (s_stream));
  stream->mode = flag;
  stream->path = path; /* strcpy a faire */
  stream->fd = fd;
  stream->size_rd = 0;
  stream->pos_wr = 0;
  stream->pos_rd = LBS_READ_SIZE;

  add_stream(stream);

  return (stream);
}
