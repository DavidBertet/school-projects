#include "const_myftp.h"

struct s_user	*init_user(void)
{
  struct s_user	*user = NULL;

  user = malloc(sizeof (struct s_user));
  user->port = INIT_PORT;
  user->pasv = 0;
  user->data_sock = -1;
  user->data_sock_actif = -1;
  user->cmd_sock = -1;
  user->data_port = MIN_PORT;
  user->current_data_port = MIN_PORT;
  user->type = malloc(7);
  my_strcpy(user->type, "TYPE i");

  return (user);
}
