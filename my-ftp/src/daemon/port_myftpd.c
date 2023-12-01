#include "const_myftpd.h"

static void     my_memcpy(void	*dest,
			  void  *src,
			  int   size)
{
  int           i;
  char          *dest_char;
  char          *src_char;

  dest_char = dest;
  src_char = src;
  for (i = 0; i < size; ++i)
    dest_char[i] = src_char[i];
}

static struct hostent   *get_hostent(const char *server)
{
  struct hostent        *hp;
  char                  *addr_char;
  in_addr_t             addr;
  void                  *tmp;

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

static int		c_socket(unsigned short           port,
				 const char               *server)
{
  int                   sock;
  int                   ret;
  struct hostent        *hp;
  struct sockaddr_in    sockaddrin;
  void                  *tmp;
  struct sockaddr       *sockaddr;

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    return (EXIT_FAILURE);
  if ((hp = get_hostent(server)) == NULL)
    return (EXIT_FAILURE);
  memset(&sockaddrin, 0, sizeof (sockaddrin));
  sockaddrin.sin_family = AF_INET;
  sockaddrin.sin_port = htons(port);
  my_memcpy(&sockaddrin.sin_addr.s_addr, hp->h_addr_list[0], hp->h_length);
  tmp = &sockaddrin;
  sockaddr = tmp;
  if ((ret = connect(sock, sockaddr, sizeof (sockaddrin))) == -1)
    return (EXIT_FAILURE);
  return (sock);
}

static int	read_port(char		*buf,
			  int		*i,
			  s_client	*client)
{
  int		port = 0;
  int		c = 0;

  client->is_pasv = 0;
  for (; ((buf[*i + c] != '\0') && (buf[*i + c] != ',')); c++)
    ;
  if (buf[*i + c] == ',')
    buf[*i + c] = '\0';
  else
    return (0);
  port = my_atoi(buf + *i) * 256 + my_atoi(buf + *i + c + 1);
  return (port);
}

static char	*read_ip(s_client	*client,
			 char		*buf,
			 int		*i)
{
  int		c = 0;
  char		*new_ip = NULL;

  free(client->net[DATA].ip);
  for (; ((buf[*i] != '\0') && (c < 4)); (*i)++)
    {
      if (buf[*i] == ',')
	c++;
    }
  if (buf[*i] == '\0')
    return (NULL);
  else
    {
      new_ip = malloc(*i);
      for (c = 0; c < *i; c++)
	{
	  if (buf[c] == ',')
	    new_ip[c] = '.';
	  else
	    new_ip[c] = buf[c];
	}
      new_ip[*i - 1] = '\0';
      return (new_ip);
    }
}

void	cmd_port_myftpd(s_server	*server,
			s_client	*client,
			char		*buf)
{
  int	i = 0;
  int	p = 0;
  char	*h = NULL;

  print_log(*server, " |_ Command : PORT\n");
  if (my_strlen(buf) <= 6)
    answer(*server, client, 501, NO_IDENT);
  else
    {
      client->net[DATA].ip = read_ip(client, buf + 5, &i);
      if (client->net[DATA].ip == NULL)
	answer(*server, client, 501, NO_IDENT);
      else
	if (verif_ident(*server, client, NEED_IDENT))
	  {
	    client->net[DATA].port = read_port(buf + 5, &i, client);
	    p = client->net[DATA].port;
	    h = client->net[DATA].ip;
	    if ((client->net[DATA].sock = c_socket(p, h)) == EXIT_FAILURE)
	      answer(*server, client, 425, NO_IDENT);
	    else
	      answer(*server, client, 225, NEED_IDENT);
	  }
    }
  return;
}
