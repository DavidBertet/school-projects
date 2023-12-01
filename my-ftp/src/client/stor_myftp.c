#include "const_myftp.h"

static char	*put_to_stor(char	*arg)
{
  char		*file;
  int		i;
  int		j;

  file = malloc(my_strlen(arg) + 2);
  my_strcpy(file, "STOR ");
  for (i = 4, j = 5; arg[i]; ++i, ++j)
    file[j] = arg[i];
  file[j] = '\0';

  return (file);
}

void	func_stor(char		*arg,
		  struct s_user	*user)
{
  char	*cmd;

  cmd = put_to_stor(arg);

  print_cmd(cmd);

  send_cmd(user->cmd_sock, cmd);

  user->last_state = get_state(read_socket(user->cmd_sock));

  free(cmd);

  return;
}
