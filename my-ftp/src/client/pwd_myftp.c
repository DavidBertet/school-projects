#include "const_myftp.h"

void	func_pwd(char		*arg,
		 struct s_user	*user)
{
  arg = arg;

  print_cmd("PWD");

  send_cmd(user->cmd_sock, "PWD");

  user->last_state = get_state(read_socket(user->cmd_sock));

  return;
}
