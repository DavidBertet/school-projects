/*
** malloc.c for malloc
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Thu Oct  2 17:02:16 2008 david bertet
** Last update Sun Oct 12 09:51:34 2008 david bertet
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

void	*g_free_list[31] = {0};

static void		init_malloc(void)
{
  int			mv = 0;
  union u_cast_sbrk	tmp;

  g_free_list[0] = sbrk(0); /* keep the head of heap*/
  tmp.ptr_void = sbrk(0);
  if ((tmp.ui % 4) != 0)
    mv = 4 - (tmp.ui % 4);
  sbrk(mv); /* align the break */
}

static void		*use_free(int	log2)
{
  union u_cast_sbrk	tmp;
  union u_cast_sbrk	tmp1;

  tmp.ptr_void = g_free_list[log2];
  tmp1.ui = *(tmp.ptr_ui);
  g_free_list[log2] = tmp1.ptr_void;
  return (tmp.ptr_void);
}

static void		*new_allocation(int	log2)
{
  union u_cast_sbrk	tmp;
  int			*new;

  tmp.i = -1;
  new = sbrk((1 << (log2 + 2)));
  if (new == tmp.ptr_int)
    return (0);
  *new = log2;

  return (new + 1); /* int = 4 so it move new ptr at right on 4 bytes */
}

void			*malloc(int size)
{
  int			log2size;

  if (g_free_list[0] == 0)
    init_malloc();

  if (size < 4) /* we can't allocate less than 4 bytes */
    size = 4;
  size = (size + 3) & ~ 3; /* we search multiple of 4 */

  log2size = log2i(size + 4);

  if (g_free_list[log2size])
    return (use_free(log2size));

  else
    return (new_allocation(log2size));
}
