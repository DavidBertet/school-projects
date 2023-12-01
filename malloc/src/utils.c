/*
** utils.c for malloc
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Tue Oct  7 16:13:04 2008 david bertet
** Last update Sun Oct 12 01:04:19 2008 david bertet
*/

#include <unistd.h>
#include "utils.h"

int	log2i(int nb)
{
  int	tmp = 0;

  --nb;
  while (nb > 0)
    {
      nb >>= 1;
      tmp++;
    }

  return (tmp - 2);
}

void	print_hexa(int n)
{
  char	buf[8];
  char	finish[8];
  char	char_num;
  int	i;
  int	j;
  int	count = 0;

  for (i = 0; i < 8; ++i)
    buf[i] = '0';

  while (n != 0)
    {
      i = (n % 16);
      if (i < 10)
	char_num = i + '0';
      else
	char_num = i - 10 + 'a';
      n = (int) n / 16;
      buf[count++] = char_num;
    }

  for (i = 0, j = 7; i < 8; ++i, --j)
    finish[j] = buf[i];

  for (i = 0; i < 8; ++i)
    write(STDOUT_FILENO, &finish[i], 1);
}

void	print_int(int n)
{
  char	buf[20];
  char	finish[20];
  char	char_num;
  int	i;
  int	j;
  int	count = 0;

  if (n < 0)
    {
      write(STDOUT_FILENO, "-", 1);
      n = -n;
    }
  if (n == 0)
    buf[count++] = '0';
  while (n != 0)
    {
      char_num = (n % 10) + '0';
      n = (int) n / 10;
      buf[count++] = char_num;
    }
  for (i = 0, j = count - 1; i < count; ++i, --j)
    finish[j] = buf[i];
  for (i = 0; i < count; ++i)
    write(STDOUT_FILENO, &finish[i], 1);
}

void			my_show_mem(void)
{
  union u_cast_sbrk	ptr;
  union u_cast_sbrk	tmp;

  ptr.ptr_char = g_free_list[0];
  while (ptr.ptr_void < sbrk(0))
    {
      tmp.ptr_char = ptr.ptr_char + 4;
      write (STDOUT_FILENO, "0x", 2);
      print_hexa(ptr.i);
      ptr.ui += 1 << ((*(ptr.ptr_int) + 2));
      write (STDOUT_FILENO, "-Ox", 3);
      print_hexa(ptr.ui);
      write (STDOUT_FILENO, "\n", 1);
    }
}
