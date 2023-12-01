/*
** utils.c for minishell
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Mon Oct 13 16:17:32 2008 david bertet
** Last update Sat Oct 18 03:36:29 2008 david bertet
*/

#include <stdlib.h>
#include <unistd.h>
#include "lib_string.h"
#include "utils.h"

void	print_int(int n)
{
  char	buf[20], finish[20], char_num;
  int	i, j;
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

char	*my_atoi(int n)
{
  char	buf[20];
  char	*finish;
  char	char_num;
  int	i;
  int	j;
  int	count = 0;

  finish = malloc(20);
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
  finish[i] = '\0';
  return (finish);
}

void	start_color(int	color)
{
  write(STDOUT_FILENO, "\033[0;3", 5);
  print_int(color);
  write(STDOUT_FILENO, "m", 1);
}

char	*rm_space(char	*str)
{
  while (*str == ' ')
    ++str;

  return (str);
}

void	rm_newline(char	*str)
{
  int	size;

  size = my_strlen(str);
  if (str[size - 1] == '\n')
    str[size - 1] = '\0';
}
