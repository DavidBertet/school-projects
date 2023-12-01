/*
** realloc.c for malloc
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Thu Oct  2 17:02:16 2008 david bertet
** Last update Sun Oct 12 09:54:29 2008 david bertet
*/

#include "malloc.h"

static void	my_memcpy(void *ptr_src, void *ptr_dest, int size)
{
  int		i;
  char		*ptr_char_src;
  char		*ptr_char_dest;

  ptr_char_src = ptr_src;
  ptr_char_dest = ptr_dest;
  for (i = 0; i < size; ++i)
    ptr_char_dest[i] = ptr_char_src[i];
}

void	*realloc(void	*ptr, int	size)
{
  int	*ptr_int;
  void	*ptr_void;
  int	real_size;

  if (!ptr)
    return (malloc(size));

  ptr_int = ptr;

  real_size = 1 << (*(ptr_int - 1) + 2);

  if (real_size - 4 >= size)
    return (ptr);

  ptr_void = malloc(size);
  my_memcpy(ptr, ptr_void, real_size - 4);
  free(ptr);
  return (ptr_void);
}
