/*
** lbs_fflush.c for libstream
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Tue Sep 30 22:59:57 2008 david bertet
** Last update Sun Oct  5 07:08:10 2008 david bertet
*/

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include "../include/libstream.h"

int	lbs_fflush_all(void)
{
  s_g	*tmp = NULL;

  tmp = g_s;
  while (tmp)
    {
      lbs_fflush(tmp->stream);
      tmp = tmp->next;
    }
  return (0);
}

int	lbs_fflush(s_stream	*stream)
{
  if (!stream)
    return (lbs_fflush_all());

  if (!(stream->mode & O_RDWR) && !(stream->mode & O_WRONLY))
    return (LBS_EOF);

  if (stream->pos_wr != 0)
    {
      if (write(stream->fd, stream->buf_wr, stream->pos_wr) == -1)
	return (LBS_EOF);
      stream->pos_wr = 0;
    }

  return (0);
}
