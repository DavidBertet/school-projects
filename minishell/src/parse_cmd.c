/*
** parse_cmd.c for minishell
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Mon Oct 13 16:17:32 2008 david bertet
** Last update Sat Oct 18 03:09:55 2008 david bertet
*/

#include <stdlib.h>
#include "lib_string.h"
#include "parse_cmd.h"

int	get_size_cmd(char	*str)
{
  int	i;

  for (i = 0;
       *str && !my_strchr(";&", *str) && my_strncmp(str, "||", 2);
       ++i, ++str)
    continue;

  return (i);
}

char	*get_cmd(char	*str, int	*i)
{
  int	size_cmd;
  char	*cmd;

  size_cmd = get_size_cmd(str);
  cmd = malloc(size_cmd + 1);
  cmd = my_strncpy(cmd, str, size_cmd);
  cmd[size_cmd] = '\0';

  *i += size_cmd;

  return (cmd);
}

int	get_size_op(char	*str)
{
  int	i;

  for (i = 0; *str && my_strchr(";&|", *str); ++i, ++str)
    continue;

  return (i);
}

char	*get_op(char	*str, int	*i)
{
  int	size_op;
  char	*op;

  size_op = get_size_op(str);
  if (size_op)
    {
      op = malloc(size_op + 1);
      op = my_strncpy(op, str, size_op);
      op[size_op] = '\0';
    }
  else
    {
      op = malloc(size_op + 1);
      op = my_strncpy(op, ";\0", 2);
    }
  *i += size_op - 1;

  return (op);
}
