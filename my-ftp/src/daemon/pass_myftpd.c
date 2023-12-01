#include "const_myftpd.h"

void	cmd_pass_myftpd(s_server	*server,
			s_client	*client,
			char		*buf)
{
  print_log(*server, " |_ Command : PASS\n");
  if (my_strlen(buf) <= 5)
    {
      print_log(*server, "   |_ Password too short\n");
      answer(*server, client, 501, NO_IDENT);
    }
  else
    {
      client->ident = 0;
      client->pass = realloc(client->pass, my_strlen(buf + 5) + 1);
      my_strcpy(client->pass, buf + 5);
      print_log(*server, "   |_ ");
      print_log(*server, client->pass);
      print_log(*server, "\n");
      answer(*server, client, 230, NEED_IDENT);
    }
  return;
}
