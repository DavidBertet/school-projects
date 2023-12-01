#include "const_myftpd.h"

static char		**get_host_ip(void)
{
  char                  **ret;
  char                  *hostname;
  struct hostent        *hp;
  int                   i;

  ret = malloc(4);
  hostname = malloc(255);
  gethostname(hostname, 255);
  if ((hp = gethostbyname(hostname)) == NULL)
    return (NULL);
  for (i = 0; i < 4; ++i)
    ret[i] = my_itoa(hp->h_addr_list[0][i]);
  return (ret);
}

static int      print_port(char                 *port,
                           int                  nb,
                           s_server		*server,
			   s_client		*client)
{
  char          *tmp_port;
  int           k;

  if (server->next_port >= server->high_port)
    server->next_port = server->low_port;
  client->net[DATA].port = ++(server->next_port);
  tmp_port = my_itoa(client->net[DATA].port / 256);
  for (k = 0; tmp_port[k]; ++k, ++nb)
    port[nb] = tmp_port[k];
  port[nb++] = ',';
  free(tmp_port);
  tmp_port = my_itoa(client->net[DATA].port % 256);
  for (k = 0; tmp_port[k]; ++k, ++nb)
    port[nb] = tmp_port[k];
  free(tmp_port);

  return (nb);
}

static char	*prep_port(s_server	*server,
			   s_client	*client)
{
  char          **ip;
  char          *port;
  int           i;
  int           j;
  int           k;

  ip = get_host_ip();
  port = malloc(37);
  my_strcpy(port, "227 PASV (");
  for (i = 10, j = 0; j < 4; ++i, ++j)
    {
      for (k = 0; ip[j][k]; ++k, ++i)
        port[i] = ip[j][k];
      port[i] = ',';
    }
  i = print_port(port, i, server, client);
  port[i] = ')';
  port[i + 1] = '\r';
  port[i + 2] = '\n';
  port[i + 3] = '\0';
  free(ip);
  return (port);
}

static void             socket_server(s_client	*client)
{
  void                  *tmp;
  struct sockaddr_in    *sockaddrin;
  int			i;

  client->net[DATA].p_sock = socket(AF_INET, SOCK_STREAM, 0);

  sockaddrin = malloc(sizeof (struct sockaddr_in));
  sockaddrin->sin_family = AF_INET;
  sockaddrin->sin_port = htons(client->net[DATA].port);
  sockaddrin->sin_addr.s_addr = htonl(INADDR_ANY);
  tmp = sockaddrin;
  client->net[DATA].saddr = tmp;
  i = sizeof (struct sockaddr_in);
  bind(client->net[DATA].p_sock, client->net[DATA].saddr, i);
  listen(client->net[DATA].p_sock, 0);
  return;
}

void	cmd_pasv_myftpd(s_server	*server,
			s_client	*client,
			char		*buf)
{
  char	*line = NULL;

  buf = buf;
  print_log(*server, " |_ Command : PASV\n");
  if (verif_ident(*server, client, NEED_IDENT))
    {
      client->is_pasv = 1;
      line = prep_port(server, client);
      socket_server(client);
      answer_raw(*server, client, line, NEED_IDENT);
      free(line);
    }
  return;
}
