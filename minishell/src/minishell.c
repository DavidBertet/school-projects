/*
** minishell.c for minishell
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Mon Oct 13 16:17:32 2008 david bertet
** Last update Sun Oct 19 03:56:34 2008 david bertet
*/

#include <unistd.h>
#include <stdlib.h>
#include "libstream.h"
#include "lib_string.h"
#include "utils.h"
#include "utils_app.h"
#include "parse_cmd.h"

static void	print_prompt(void)
{
  char		*ps1;

  if (isatty(STDIN_FILENO))
    {
      ps1 = getenv("PS1");
      if (ps1)
	{
	  start_color(2);
	  write(STDOUT_FILENO, ps1, my_strlen(ps1));
	  start_color(7);
	}
      else
	write(STDOUT_FILENO, "minishell$ ", 11);
    }
}

static int	exec_cmd(char	*cmd, char	*op, int	*stop, int	last_status)
{
  int		status;

  if (!my_strcmp(op, "&") && !*stop)
    status = treat_app(cmd, 0, last_status);
  else if (!*stop)
    status = treat_app(cmd, 1, last_status);
  else
    status = last_status;

 if (!my_strcmp(op, "&&") && status)
    *stop = 1;
  else if (!my_strcmp(op, "||") && !status)
    *stop = 1;
  else
    *stop = 0;

  return (status);
}

static s_stream	*init(void)
{
  s_stream	*stream;

  stream = lbs_fdopen(STDIN_FILENO, "r");
  putenv("PS1=\033[0;31mmini\033[0;33mshell\033[0;32m$ \033[0;37m");
  return (stream);
}

int		main(void)
{
  char		*buf;
  s_stream	*stream;
  size_t	size = 20;
  int		i;
  char		*cmd;
  char		*op;
  int		status = 0;
  int		stop = 0;

  stream = init();

  buf = malloc(20);
  while (1)
    {
      print_prompt();

      if (lbs_getline(&buf, &size, stream) == -1)
	return (status);

      rm_newline(buf);
      for (i = 0, stop = 0; buf[i]; ++i)
	{
	  cmd = get_cmd(buf + i, &i);
	  op = get_op(buf + i, &i);
	  status = exec_cmd(cmd, op, &stop, status);
	}
      lbs_fpurge(stream);
    }
}
