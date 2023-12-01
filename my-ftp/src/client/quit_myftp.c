#include "const_myftp.h"

void	func_quit(char		*arg,
		  struct s_user	*user)
{
  arg = arg;

  print_cmd("QUIT");

  send_cmd(user->cmd_sock, "QUIT");

  user->last_state = get_state(read_socket(user->cmd_sock));

  deconnect_socket(user->cmd_sock);
  exit(0);
}
