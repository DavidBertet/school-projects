/*
** free.c for malloc
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Thu Oct  2 17:02:16 2008 david bertet
** Last update Sun Oct 12 09:51:43 2008 david bertet
*/

#include <unistd.h>
#include "malloc.h"

#define ERR_RET(C, NB)				\
  do						\
    {						\
      write(STDOUT_FILENO, C, NB);		\
      return;					\
    }						\
  while (0);

void			free(void *ptr_void)
{
  int			log2;
  int			*ptr;
  union u_cast_sbrk	tmp;
  union u_cast_sbrk	tmp1;

  if (!ptr_void)
    return;

  if (ptr_void < g_free_list[0])
    ERR_RET("warning: junk pointer, too low to make sense.\n", 46);
  if (ptr_void > sbrk(0))
    ERR_RET("warning: junk pointer, too high to make sense.\n", 47);

  ptr = ptr_void;
  log2 = *(ptr - 1);
  tmp.ptr_void = sbrk(0);
  tmp1.ptr_void = ptr_void;
  if (tmp1.ui + (1 << (log2 + 2)) - 4 == tmp.ui)
    sbrk(-(1 << (log2 + 2)));
  else
    if (log2 < 32)
      {
	tmp.ptr_void = g_free_list[log2];
	*(ptr) = tmp.ui;
	g_free_list[log2] = ptr_void;
      }
}
