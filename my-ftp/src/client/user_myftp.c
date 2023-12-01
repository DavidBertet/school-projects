#include "const_myftp.h"

void	func_user(char		*arg,
		  struct s_user	*user)
{
  print_cmd(arg);

  send_cmd(user->cmd_sock, arg);

  user->last_state = get_state(read_socket(user->cmd_sock));

  return;
}
