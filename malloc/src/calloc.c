/*
** calloc.c for malloc
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Thu Oct  2 17:02:16 2008 david bertet
** Last update Sun Oct 12 00:49:25 2008 david bertet
*/

#include "malloc.h"

void		*calloc(size_t count, size_t size)
{
  char		*ptr;
  size_t	i;

#ifdef DEBUG
  write(STDOUT_FILENO, "calloc\n", 7);
#endif
  ptr = malloc(size * count);

  for (i = 0; i < (size * count); ++i)
    ptr[i] = '\0';

  return (ptr);
}
