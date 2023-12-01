/*
** lbs_rewind.c for libstream
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Wed Oct  1 17:32:01 2008 david bertet
** Last update Fri Oct  3 23:35:38 2008 david bertet
*/

#include <stdio.h>
#include <errno.h>
#include "../include/libstream.h"

void	lbs_rewind(s_stream	*stream)
{
  errno = 0;
  lbs_fseek(stream, 0, SEEK_SET);
}
