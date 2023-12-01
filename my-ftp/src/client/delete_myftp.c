#include "const_myftp.h"

static char	*delete_to_dele(char	*arg)
{
  char		*ret;
  int		i;
  int		j;

  ret = malloc(my_strlen(arg) + 2);
  my_strcpy(ret, "DELE ");
  for (i = 7, j = 5; arg[i]; ++i, ++j)
    ret[j] = arg[i];
  ret[j] = '\0';

  return (ret);
}

void	func_delete(char		*arg,
		    struct s_user	*user)
{
  char	*cmd;

  cmd = delete_to_dele(arg);

  print_cmd(cmd);

  send_cmd(user->cmd_sock, cmd);

  user->last_state = get_state(read_socket(user->cmd_sock));

  free(cmd);

  return;
}
