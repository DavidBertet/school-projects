#include "const_myftpd.h"

static void     send_file(s_client	*client)
{
  unsigned int	t;
  int		i;

  if (client->is_pasv == 1)
    {
      i = accept(client->net[DATA].p_sock, client->net[DATA].saddr, &t);
      client->net[DATA].sock = i;
    }
  my_listdir(client->wd_path, client->net[DATA].sock);
  if (client->is_pasv)
    close(client->net[DATA].p_sock);
  close(client->net[DATA].sock);
  client->net[DATA].sock = -1;
  return;
}

void	cmd_list_myftpd(s_server	*server,
			s_client	*client,
			char		*buf)
{
  buf = buf;
  print_log(*server, " |_ Command : LIST\n");
  if (verif_ident(*server, client, NEED_IDENT))
    {
      answer(*server, client, 150, NEED_IDENT);
      send_file(client);
      answer(*server, client, 200, NEED_IDENT);
    }
  return;
}
