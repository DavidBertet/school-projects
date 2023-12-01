#include "const_myftpd.h"

int    display_help(char	*arg,
		    s_server	*server)
{
  int  i = 0;

  arg = arg;
  server = server;
  write(STDOUT_FILENO, "\n", 1);
  write(STDOUT_FILENO, "\033[33m", 5);
  write(STDOUT_FILENO, " s e r v e r   h e l p \n\n\n", 26);
  write(STDOUT_FILENO, "\033[0m", 5);
  write(STDOUT_FILENO, "Options disponibles pour le serveur:\n\n", 38);
  while (gopt[i].description != NULL)
    {
      write(STDOUT_FILENO, "\033[31m", 5);
      write(STDOUT_FILENO, gopt[i].opt_name, my_strlen(gopt[i].opt_name));
      write(STDOUT_FILENO, ": ", 2);
      write(STDOUT_FILENO, "\033[0;37m", 7);
      write(STDOUT_FILENO, gopt[i].description,
	    my_strlen(gopt[i].description));
      write(STDOUT_FILENO, "\n", 1);
      i++;
    }
  write(STDOUT_FILENO, "\n", 1);
  return (0);
}

int	get_port(char		*arg,
		 s_server	*server)
{
  int	port;

  port = my_atoi(arg);
  if (port < 1024)
    port = 1024;
  server->cmd_port = port;
  return (server->cmd_port);
}

int     become_a_daemon(char           *arg,
			s_server       *server)
{
  int	kpid;

  arg = arg;
  server = server;
  kpid = fork();
  if (kpid != 0)
    exit(0);
  setsid();
  kpid = fork();
  if (kpid != 0)
    exit(0);
  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);
  return (0);
}

int	write_a_log(char	*arg,
		    s_server    *server)
{
  server->is_log = 1;
  server->fd_log = open_log(*server, arg);
  return (0);
}
