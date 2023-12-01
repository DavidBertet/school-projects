#include "const_myftpd.h"

void	cmd_user_myftpd(s_server	*server,
			s_client	*client,
			char		*buf)
{
  print_log(*server, " |_ Command : USER\n");
  if (my_strlen(buf) <= 5)
    {
      print_log(*server, "   |_ Name too short\n");
      answer(*server, client, 501, NO_IDENT);
    }
  else
    {
      client->ident = 0;
      client->name = realloc(client->name, my_strlen(buf + 5) + 1);
      my_strcpy(client->name, buf + 5);
      print_log(*server, "   |_ ");
      print_log(*server, client->name);
      print_log(*server, "\n");
      answer(*server, client, 331, NO_IDENT);
    }
  return;
}
