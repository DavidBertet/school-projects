/*
** lbs_fgetc.c for libstream
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Wed Oct  1 11:47:07 2008 david bertet
** Last update Sun Oct 26 00:59:01 2008 david bertet
*/

#include <stdio.h>

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/socket.h>
#include "../include/libstream.h"

int	lbs_fgetc(s_stream	*stream)
{
  if ((!(stream->mode & O_RDWR) && stream->mode != 0))
    {
      errno = EBADF;
      return (LBS_EOF);
    }

  lbs_fflush(stream);

  if (stream->pos_rd >= stream->size_rd || stream->pos_rd == LBS_READ_SIZE)
    {
      stream->size_rd = recv(stream->fd, stream->buf_rd, LBS_READ_SIZE, 0);
      stream->pos_rd = 0;
    }
  if (stream->pos_rd < stream->size_rd)
    return (stream->buf_rd[stream->pos_rd++]);
  else
    return (LBS_EOF);
}

int	lbs_fgetc_str(s_stream	*stream)
{
  if ((!(stream->mode & O_RDWR) && stream->mode != 0))
    {
      errno = EBADF;
      return (LBS_EOF);
    }

  lbs_fflush(stream);

  if (stream->pos_rd >= stream->size_rd || stream->pos_rd == LBS_READ_SIZE)
    {
      stream->size_rd = read(stream->fd, stream->buf_rd, LBS_READ_SIZE);
      stream->pos_rd = 0;
    }
  if (stream->pos_rd < stream->size_rd)
    return (stream->buf_rd[stream->pos_rd++]);
  else
    return (LBS_EOF);
}
