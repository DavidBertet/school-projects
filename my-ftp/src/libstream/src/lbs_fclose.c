/*
** lbs_fclose.c for libstream
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Tue Sep 30 20:28:59 2008 david bertet
** Last update Sun Oct  5 04:41:44 2008 david bertet
*/

#include <stdlib.h>
#include <unistd.h>
#include "../include/libstream.h"

void	rm_stream(s_stream	*stream)
{
  s_g	*tmp = NULL;
  s_g	*tmp_prec = NULL;

  tmp = g_s;
  while (tmp)
    {
      if (tmp->stream->fd == stream->fd)
	{
	  if (tmp_prec == NULL) /* head */
	    {
	      g_s = tmp->next;
	      free(tmp);
	      return;
	    }
	  else
	    {
	      tmp_prec->next = tmp->next;
	      free(tmp);
	      return;
	    }
	}
      tmp_prec = tmp;
      tmp = tmp->next;
    }
}

int	lbs_fclose(s_stream	*stream)
{
  lbs_fflush(stream);

  if (close(stream->fd) == -1)
    return (LBS_EOF);

  rm_stream(stream);

  free(stream);

  return (0);
}
