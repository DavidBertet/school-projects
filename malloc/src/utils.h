/*
** utils.h for malloc
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Tue Oct  7 16:14:42 2008 david bertet
** Last update Sun Oct 12 01:06:58 2008 david bertet
*/

#include <sys/types.h>

extern void *g_free_list[31];

union		u_cast_sbrk {
  size_t	ui;
  int		i;
  void		*ptr_void;
  size_t	*ptr_ui;
  int		*ptr_int;
  char		*ptr_char;
};

int	log2i(int nb);
void	print_hexa(int n);
void	print_int(int n);
void	my_show_mem(void);
