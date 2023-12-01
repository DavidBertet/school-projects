#include "const_myftpd.h"

void	cmd_noop_myftpd(s_server	*server,
			s_client	*client,
			char		*buf)
{
  buf = buf;
  print_log(*server, " |_ Command : NOOP\n");
  answer(*server, client, 200, NO_IDENT);
  return;
}
