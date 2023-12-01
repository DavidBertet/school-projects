#include "const_myftp.h"

static void	my_memcpy(void	*dest, void	*src, int	size)
{
  int		i;
  char		*dest_char;
  char		*src_char;

  dest_char = dest;
  src_char = src;
  for (i = 0; i < size; ++i)
    dest_char[i] = src_char[i];
}

static struct hostent	*get_hostent(const char	*server)
{
  struct hostent	*hp;
  char			*addr_char;
  in_addr_t		addr;
  void			*tmp;

  if (inet_addr(server) == INADDR_NONE)
    {
      hp = gethostbyname(server);
      if (hp == NULL)
	perror("gethostbyname");
    }
  else
    {
      addr = inet_addr(server);
      tmp = &addr;
      addr_char = tmp;
      hp = gethostbyaddr(addr_char, sizeof (addr), AF_INET);
      if (hp == NULL)
	perror("gethostbyaddr");
    }
  return (hp);
}

static void	print_hello(char	*hname,
			    int		port)
{
  print_string(">> Log in on server: ", STDOUT_FILENO, 0);
  print_string(hname, STDOUT_FILENO, 0);
  print_string(" on port: ", STDOUT_FILENO, 0);
  print_string(my_itoa(port), STDOUT_FILENO, 0);
  print_string("\n", STDOUT_FILENO, 0);

  return;
}

int			connect_socket(unsigned short		port,
				       const char		*server)
{
  int			sock;
  int			ret;
  struct hostent	*hp;
  struct sockaddr_in	sockaddrin;
  void			*tmp;
  struct sockaddr	*sockaddr;

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    return (EXIT_FAILURE);

  if ((hp = get_hostent(server)) == NULL)
    return (EXIT_FAILURE);
  memset(&sockaddrin, 0, sizeof (sockaddrin));

  sockaddrin.sin_family = AF_INET;
  sockaddrin.sin_port = htons(port);
  my_memcpy(&sockaddrin.sin_addr.s_addr, hp->h_addr_list[0], hp->h_length);
  print_hello(hp->h_name, port);
  tmp = &sockaddrin;
  sockaddr = tmp;

  if ((ret = connect(sock, sockaddr, sizeof (sockaddrin))) == -1)
    return (EXIT_FAILURE);

  return (sock);
}

int	deconnect_socket(int	sock)
{
  close(sock);

  print_string(">> Log off\nShutdown now!\n", STDOUT_FILENO, 0);

  return (0);
}

void			socket_server(struct s_user	*user,
				      int		port)
{
  void			*tmp;
  struct sockaddr_in	*sockaddrin;

  user->data_sock_actif = socket(AF_INET, SOCK_STREAM, 0);

  sockaddrin = malloc(sizeof (struct sockaddr_in));
  sockaddrin->sin_family = AF_INET;
  sockaddrin->sin_port = htons(port);
  sockaddrin->sin_addr.s_addr = htonl(INADDR_ANY);

  tmp = sockaddrin;
  user->sockaddr = tmp;

  bind(user->data_sock_actif, user->sockaddr, sizeof (struct sockaddr_in));
  listen(user->data_sock_actif, 0);

  return;
}
