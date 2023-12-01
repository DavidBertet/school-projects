#include "const_myftpd.h"

void	cmd_quit_myftpd(s_server	*server,
			s_client	*client,
			char		*buf)
{
  buf = buf;
  print_log(*server, " |_ Command : QUIT\n");
  answer(*server, client, 221, NO_IDENT);
  return;
}
