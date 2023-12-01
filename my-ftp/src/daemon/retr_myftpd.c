#include "const_myftpd.h"

static void     send_file(s_client	*c,
                          char          *filename)
{
  s_stream      *stream;
  char          buf[128];
  int           size;
  int           end = 1;
  unsigned int	t;
  char		*line;

  line = malloc(my_strlen(filename) + my_strlen(c->wd_path) + 1);
  strcpy(strcpy(line, c->wd_path) + my_strlen(c->wd_path), filename);
  if (c->is_pasv == 1)
    c->net[DATA].sock  = accept(c->net[DATA].p_sock, c->net[DATA].saddr, &t);
  stream = lbs_fopen(line, "r");
  while (end > 0)
    {
      size = lbs_fread(buf, 1, 128, stream);
      end = send(c->net[DATA].sock, buf, size, 0);
    }
  free(line);
  lbs_fclose(stream);
  if (c->is_pasv)
    close(c->net[DATA].p_sock);
  close(c->net[DATA].sock);
  c->net[DATA].sock = -1;
  return;
}

void	cmd_retr_myftpd(s_server	*server,
			s_client	*client,
			char		*buf)
{
  print_log(*server, " |_ Command : RETR\n");
  if (my_strlen(buf) <= 6)
    {
      answer(*server, client, 501, NO_IDENT);
      return;
    }
  if (verif_ident(*server, client, ROOT_IDENT))
    {
      answer(*server, client, 150, ROOT_IDENT);
      send_file(client, buf + 5);
      answer(*server, client, 226, ROOT_IDENT);
    }
  return;
}
