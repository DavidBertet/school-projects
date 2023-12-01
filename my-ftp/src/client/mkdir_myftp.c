#include "const_myftp.h"

static char	*mkdir_to_mkd(char	*arg)
{
  char		*ret;
  int		i;
  int		j;

  ret = malloc(my_strlen(arg) + 2);
  my_strcpy(ret, "MKD ");
  for (i = 6, j = 4; arg[i]; ++i, ++j)
    ret[j] = arg[i];
  ret[j] = '\0';

  return (ret);
}

void	func_mkdir(char			*arg,
		   struct s_user	*user)
{
  char	*cmd;

  cmd = mkdir_to_mkd(arg);

  print_cmd(cmd);

  send_cmd(user->cmd_sock, cmd);

  user->last_state = get_state(read_socket(user->cmd_sock));

  free(cmd);

  return;
}
