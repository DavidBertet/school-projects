#include "const_myftp.h"

static int	find_port(char	*port1,
			  char	*port2)
{
  return (my_atoi(port1) * 256 + my_atoi(port2));
}

static char	*find_host(char	*response,
			   int	*i)
{
  char		*host = NULL;
  int		j = 0;
  int		k = 0;

  host = malloc(16);
  for (k = 1; k <= 4; ++k)
    {
      for (++*i; response[*i] && response[*i] != ','; ++*i, ++j)
	host[j] = response[*i];
      if (k != 4)
	host[j++] = '.';
    }
  host[j] = '\0';

  return (host);
}

static void	find_port_pasv(char	*response,
			       char	*port1,
			       char	*port2,
			       int	*i)
{
  int		j = 0;

  for (++*i, j = 0; response[*i] && response[*i] != ','; ++*i, ++j)
    port1[j] = response[*i];
  port1[j] = '\0';
  for (++*i, j = 0; response[*i] && response[*i] != ')'; ++*i, ++j)
    port2[j] = response[*i];
  port2[j] = '\0';

  return;
}

void	func_pasv(char		*arg,
		  struct s_user	*user)
{
  char	*response;
  int	i;
  char	*host;
  int	data_sock = -1;
  char	*port1;
  char	*port2;

  print_cmd(arg);

  send_cmd(user->cmd_sock, arg);

  response = read_socket(user->cmd_sock);

  for (i = 0; response[i] && response[i] != '('; ++i)
    continue;

  host = find_host(response, &i);

  port1 = malloc(3);
  port2 = malloc(3);

  find_port_pasv(response, port1, port2, &i);

  if (*port2 != '\0')
    data_sock = connect_socket(find_port(port1, port2), host);

  user->data_sock = data_sock;
  return;
}
