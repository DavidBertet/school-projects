#include "const_myftp.h"

void	func_auto(char		*arg,
		  struct s_user	*user)
{
  arg = arg;

  print_cmd("USER anonymous");
  send_cmd(user->cmd_sock, "USER anonymous");
  user->last_state = get_state(read_socket(user->cmd_sock));

  print_cmd("PASS myFTP@");
  send_cmd(user->cmd_sock, "PASS myFTP@");
  user->last_state = get_state(read_socket(user->cmd_sock));

  return;
}
