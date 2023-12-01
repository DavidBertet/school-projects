#include "const_myftp.h"

void	func_syst(char		*arg,
		  struct s_user	*user)
{
  arg = arg;

  print_cmd("SYST");

  send_cmd(user->cmd_sock, "SYST");

  user->last_state = get_state(read_socket(user->cmd_sock));

  return;
}
