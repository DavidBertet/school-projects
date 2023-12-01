#include "const_myftpd.h"

static void     recv_file(s_client	*c,
                          char          *filename)
{
  char          buf[128];
  s_stream      *stream;
  int           size;
  unsigned int	t;
  char		*line;

  if (c->is_pasv == 1)
    c->net[DATA].sock = accept(c->net[DATA].p_sock, c->net[DATA].saddr, &t);
  line = malloc(my_strlen(filename) + my_strlen(c->wd_path) + 1);
  strcpy(strcpy(line, c->wd_path) + my_strlen(c->wd_path), filename);
  stream = lbs_fopen(line, "w");
  do
    {
      size = recv(c->net[DATA].sock, buf, 128, 0);
      if (size > 0)
        lbs_fwrite(buf, 1, size, stream);
    }
  while (size > 0);
  free(line);
  lbs_fclose(stream);
  close(c->net[DATA].sock);
  if (c->is_pasv == 1)
    close(c->net[DATA].p_sock);
  return;
}


void	cmd_stor_myftpd(s_server	*server,
			s_client	*client,
			char		*buf)
{
  print_log(*server, " |_ Command : STOR\n");
  if (my_strlen(buf) <= 6)
    {
      answer(*server, client, 501, NO_IDENT);
      return;
    }
  if (verif_ident(*server, client, ROOT_IDENT))
    {
      answer(*server, client, 150, ROOT_IDENT);
      recv_file(client, buf + 5);
      answer(*server, client, 226, ROOT_IDENT);
    }
  return;
}
