/*
** lbs_freopen.c for libstream
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Wed Oct  1 13:59:29 2008 david bertet
** Last update Sun Oct  5 04:48:11 2008 david bertet
*/

#include <stdlib.h>
#include "../include/libstream.h"

s_stream	*lbs_freopen(const char	*path,
			     const char	*mode,
			     s_stream	*stream)
{
  s_stream	*stream_tmp = NULL;

  lbs_fflush(stream);

  if (!path)
    {
      stream_tmp = lbs_fopen(stream->path, mode);
      lbs_fclose(stream);
      return (stream_tmp);
    }
  else
    {
      lbs_fclose(stream);
      return (lbs_fopen(path, mode));
    }
}
