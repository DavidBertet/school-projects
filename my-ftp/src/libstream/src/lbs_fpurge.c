/*
** lbs_fpurge.c for libstream
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Tue Sep 30 23:15:45 2008 david bertet
** Last update Sun Oct  5 07:07:58 2008 david bertet
*/

#include "../include/libstream.h"

int	lbs_fpurge(s_stream	*stream)
{
  if (!stream)
    return (-1);

  stream->pos_wr = 0;
  stream->pos_rd = LBS_READ_SIZE;
  stream->size_rd = 0;

  return (0);
}
