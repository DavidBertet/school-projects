/*
** lbs_fputc.c for libstream
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Tue Sep 30 21:33:48 2008 david bertet
** Last update Sat Oct  4 02:21:12 2008 david bertet
*/

#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/libstream.h"

int	lbs_fputc(int		c,
		  s_stream	*stream)
{
  if (!(stream->mode & O_RDWR) && !(stream->mode & O_WRONLY))
    {
      errno = EBADF;
      return (LBS_EOF);
    }

  stream->pos_rd = LBS_READ_SIZE;
  stream->size_rd = 0;

  if (stream->pos_wr == LBS_WRITE_SIZE)
    {
      write(stream->fd, stream->buf_wr, LBS_WRITE_SIZE);
      stream->pos_wr = 0;
    }

  stream->buf_wr[stream->pos_wr++] = c;

  return (c);
}
