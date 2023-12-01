#include "const_myftpd.h"

void	cmd_unknown_myftpd(s_server	*server,
			   s_client	*client,
			   char		*buf)
{
  buf = buf;
  print_log(*server, " |_ Command : unknown\n");
  answer(*server, client, 500, NO_IDENT);
  return;
}
