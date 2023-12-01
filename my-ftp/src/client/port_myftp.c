#include "const_myftp.h"

static int	print_port(char			*port,
			   int			nb,
			   struct s_user	*user)
{
  char		*tmp_port;
  int		k;

  if (user->data_port == MAX_PORT)
    user->data_port = MIN_PORT;

  user->current_data_port = user->data_port;

  tmp_port = my_itoa(user->data_port / 256);

  for (k = 0; tmp_port[k]; ++k, ++nb)
    port[nb] = tmp_port[k];
  port[nb++] = ',';
  free(tmp_port);

  tmp_port = my_itoa(user->data_port++ % 256);
  for (k = 0; tmp_port[k]; ++k, ++nb)
    port[nb] = tmp_port[k];
  free(tmp_port);

  return (nb);
}

char		*prep_port(struct s_user	*user)
{
  char		**ip;
  char		*port;
  int		i;
  int		j;
  int		k;

  user = user;
  ip = get_host_ip();
  port = malloc(29);

  my_strcpy(port, "PORT ");

  for (i = 5, j = 0; j < 4; ++i, ++j)
    {
      for (k = 0; ip[j][k]; ++k, ++i)
	port[i] = ip[j][k];
      port[i] = ',';
    }

  i = print_port(port, i, user);

  port[i] = '\0';
  free(ip);
  return (port);
}

void	func_port(char		*arg,
		  struct s_user	*user)
{
  char	*port;

  arg = arg;
  port = prep_port(user);

  socket_server(user, user->current_data_port);

  print_cmd(port);

  send_cmd(user->cmd_sock, port);

  user->last_state = get_state(read_socket(user->cmd_sock));

  free(port);

  return;
}
