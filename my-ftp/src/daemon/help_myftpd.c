#include "const_myftpd.h"

void	cmd_help_myftpd(s_server	*server,
			s_client	*client,
			char		*buf)
{
  buf = buf;
  print_log(*server, " |_ Command : HELP\n");
  answer_raw(*server, client, "214-SECURITY LEVEL 0:\r\n", NO_IDENT);
  answer_raw(*server, client, "214-HELP NOOP PASS QUIT USER\r\n", NO_IDENT);
  answer_raw(*server, client, "214-\r\n", NO_IDENT);
  answer_raw(*server, client, "214-SECURITY LEVEL 1:\r\n", NO_IDENT);
  answer_raw(*server, client, "214-CWD LIST PASV PORT PWD SYST\r\n", NO_IDENT);
  answer_raw(*server, client, "214-\r\n", NO_IDENT);
  answer_raw(*server, client, "214-SECURITY LEVEL 2:\r\n", NO_IDENT);
  answer_raw(*server, client, "214-RETR STOR TYPE\r\n", NO_IDENT);
  answer(*server, client, 214, NO_IDENT);
  return;
}
