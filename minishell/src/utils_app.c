/*
** utils_app.c for minishell
**
** Made by david bertet
** Login   <bertet_d@epitech.net>
**
** Started on  Mon Oct 13 16:17:32 2008 david bertet
** Last update Sun Oct 19 03:58:31 2008 david bertet
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "utils_str.h"
#include "lib_string.h"
#include "utils_app.h"
#include "builtin.h"
#include "utils_redir.h"
#include "utils_builtin.h"

#define ERR_CMD(Prog)						\
  write(STDERR_FILENO, "minishell: ", 11);			\
  write(STDERR_FILENO, Prog, my_strlen(Prog));			\
  write(STDERR_FILENO, ": command not found\n", 20);		\
  exit(127); /* ERROR: COMMAND NOT FOUND */

static int	launch_app_pipe(char	**argv, int	i, int	last_status)
{
  int		p[2];
  int		pid;
  int		size;

  size = size_tab(argv) - 1;
  if (!pipe(p))
    {
      if ((pid = fork()))
	{
	  close(p[1]);
	  dup2(p[0], 0);
	  if (i < size - 1)
	    launch_app_pipe(argv, ++i, last_status);
	  else
	    exit (treat_app(argv[i + 1], 1, last_status));
	  exit(0);
	}
      else
	{
	  close(p[0]);
	  dup2(p[1], 1);
	  exit(treat_app(argv[i], 1, last_status));
	}
    }
  return (1);
}

static int	treat_pipe(char	*str, int	last_status)
{
  int		status;
  int		pid;

  if ((pid = fork()))
    {
      pid = waitpid(-1, &status, 0);
    }
  else
    {
      launch_app_pipe(my_split(str, '|', last_status), 0, last_status);
    }
  return (WEXITSTATUS(status));
}

static void	prepare_child(char	**argv, int	wait_bool)
{
  int		devnull;
  int		file;
  int		fd;
  int		type;
  int		pos;

  treat_redir(argv, &pos, &type);
  if (type == REDIR_IN && argv[pos] != NULL && !(fd = STDIN_FILENO))
    file = open(argv[pos], O_RDONLY);

  if ((type == REDIR_OUT || type == REDIR_OUT_ERR) && argv[pos] != NULL)
    file = open(argv[pos], O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (type == DOUBLE_REDIR_OUT && argv[pos] != NULL)
    file = open(argv[pos], O_WRONLY | O_CREAT | O_APPEND);
  if (type == REDIR_OUT || type == DOUBLE_REDIR_OUT)
    fd = STDOUT_FILENO;
  if (type == REDIR_OUT_ERR)
    fd = STDERR_FILENO;

  if (type && argv[pos] != NULL)
    {
      rm_redir(argv, pos - 1);
      close(fd);
      dup2(file, fd);
      prepare_child(argv, wait_bool);
    }
  else if (!wait_bool && (devnull = open("/dev/null", O_RDONLY)))
      dup2(devnull, 0);
}

int	treat_app(char	*argv, int	wait_bool, int	last_status)
{
  int	status = 0;

  if (my_strchr(argv, '|'))
    status = treat_pipe(argv, last_status);

  else if (!my_strncmp(argv, "exit", 4))
    my_exit(my_split(argv, ' ', last_status));

  else if (!my_strncmp(argv, "export ", 7))
    status = my_export(my_split(argv, ' ', last_status));

  else if (!my_strncmp(argv, "cd", 2))
      status = my_cd(my_split(argv, ' ', last_status), 0);

  else
    status = launch_app(my_split(argv, ' ', last_status), wait_bool);

  return (status);
}

int	launch_app(char	**argv, int	wait_bool)
{
  int	pid;
  int	status = 0;

  if ((pid = fork())) /* FATHER */
    {
      if (wait_bool)
	waitpid(pid, &status, 0);
      else
	waitpid(-1, NULL, WNOHANG);
    }
  else /* BROTHER */
    {
      prepare_child(argv, wait_bool);
      treat_builtin(argv);
      ERR_CMD(argv[0])
    }
  return (WEXITSTATUS(status));
}
