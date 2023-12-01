/*
** builtin.c for minishell
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Sun Oct 19 04:27:51 2008 david bertet
** Last update Sun Oct 19 04:29:23 2008 david bertet
*/

#include <stdlib.h>
#include <unistd.h>
#include "utils_str.h"
#include "lib_string.h"
#include "builtin.h"

/* ERROR DIRECTORY FOR CD*/
#define ERR_DIR(Dir)							\
  do									\
    {									\
      write(STDERR_FILENO, "minishell: cd: ", 15);			\
      write(STDERR_FILENO, Dir, my_strlen(Dir));			\
      write(STDERR_FILENO, ": No such file or directory\n", 28);	\
    }									\
  while (0);

/* ERROR MODE FOR CD*/
#define ERR_PWD(Opt)							\
  do									\
    {									\
      write(STDERR_FILENO, "minishell: pwd: ", 16);			\
      write(STDERR_FILENO, Opt, my_strlen(Opt));			\
      write(STDERR_FILENO, ": invalid option\n", 17);			\
      write(STDERR_FILENO, "pwd: usage: pwd [-P]\n", 21);		\
      return (1);							\
    }									\
  while (0);

int		my_pwd(char	**str)
{
  char		*res = NULL;

  if (str && str[1] != NULL && my_strncmp(str[1], "-P", 3))
    ERR_PWD(str[1])
  res = getcwd(res, 0);
  write(STDOUT_FILENO, res, my_strlen(res));
  write(STDOUT_FILENO, "\n", 1);
  return (0);
}

int	my_echo(char	**str)
{
  if (str[1] && str[2] && !my_strcmp(str[1], "-n"))
      write(STDOUT_FILENO, str[2], my_strlen(str[2]));
  else
    {
      if (str[1])
	write(STDOUT_FILENO, str[1], my_strlen(str[1]));
      write(STDOUT_FILENO, "\n", 1);
    }

  return (0);
}

int	my_cd(char	**str, int	brother)
{
  int	res;

  if (my_strncmp(str[0], "cd", 3))
    return (0);
  if (str[1] && !my_strncmp(str[1], "-", 2))
    {
      brother = brother;
      return (my_pwd(NULL));
    }
  if (str[1] == NULL || !my_strncmp(str[1], "-P", 3))
    res = chdir(getenv("HOME"));
  else
    res = chdir(str[1]);

  if (!res)
    return (0);

  if (str[1] == NULL || !my_strncmp(str[1], "-P", 3))
    ERR_DIR(getenv("HOME"))
  else
    ERR_DIR(str[1])

  return (1);
}

int	my_export(char	**str)
{
  putenv(str[1]);

  return (0);
}

void	my_exit(char	**str)
{
  str = str;
  /*  if - (*str - [1])
    exit - (*str - [1]);*/ /* TODO IS NUMBER */

  exit(0);
}
