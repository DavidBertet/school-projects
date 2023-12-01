#include "const_myftpd.h"

void	cmd_syst_myftpd(s_server	*server,
			s_client	*client,
			char		*buf)
{
  client = client;
  buf = buf;
  print_log(*server, " |_ Command : SYST\n");
  answer(*server, client, 215, NEED_IDENT);
  return;
}
