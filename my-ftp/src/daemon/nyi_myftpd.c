#include "const_myftpd.h"

void	cmd_nyi_myftpd(s_server	*server,
		       s_client	*client,
		       char	*buf)
{
  buf = buf;
  print_log(*server, " |_ Command : Not Yet Implemanted !\n");
  answer(*server, client, 502, NO_IDENT);
  return;
}
