/*
** lbs_getline.c for libstream
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Sat Oct  4 15:28:35 2008 david bertet
** Last update Sun Oct 26 07:53:30 2008 david bertet
*/

#include "../include/libstream.h"

ssize_t	lbs_getline(char	**lineptr,
		    size_t	*n,
		    s_stream	*stream)
{
  return (lbs_getdelim_str(lineptr, n, '\n', stream));
}
