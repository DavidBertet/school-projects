#include "const_myftp.h"

int			main(int	argc,
			     char	**argv)
{
  struct s_user		*user = NULL;
  int			cmd;
  char			*line;

  user = init_user();
  manage_arg(argc, argv, user);
  if ((user->cmd_sock = connect_socket(user->port, user->host)) ==
      EXIT_FAILURE)
    return (2);
  read_socket(user->cmd_sock);

  while (1)
    {
      line = readline(print_prompt());

      if ((cmd = is_valid_cmd(line)) != -1)
	(*(ftp_cmd[cmd].func))(line, user);
      else
	  print_string("\033[0;31m/!\\\033[0;37m Unknown command\n",
		       STDOUT_FILENO, 0);
    }

  deconnect_socket(user->cmd_sock);
  return (0);
}
