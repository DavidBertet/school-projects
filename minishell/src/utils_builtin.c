/*
** utils_builtin.c for minishell
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Sun Oct 19 04:25:08 2008 david bertet
** Last update Sun Oct 19 04:25:15 2008 david bertet
*/

#include <stdlib.h>
#include <unistd.h>
#include "lib_string.h"
#include "builtin.h"
#include "utils_builtin.h"

void	treat_builtin(char	**argv)
{
  int	status = 0;

  if (!my_strncmp(argv[0], "pwd", 4))
    {
      status = my_pwd(argv);
      exit(status);
    }
  else if (!my_strncmp(argv[0], "cd", 3))
    {
      status = my_cd(argv, 1);
      exit(status);
    }
  else if (!my_strncmp(argv[0], "echo", 5))
    {
      status = my_echo(argv);
      exit(status);
    }
  else
    execvp(argv[0], argv);
}
