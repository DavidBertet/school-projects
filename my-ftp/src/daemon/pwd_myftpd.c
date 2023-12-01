#include "const_myftpd.h"

void	cmd_pwd_myftpd(s_server	*server,
		       s_client	*client,
		       char	*buf)
{
  char	*line;

  buf = buf;
  print_log(*server, " |_ Command : PWD\n");
  print_log(*server, "   |_ ");
  print_log(*server, client->wd_path);
  print_log(*server, "\n");

  line = malloc(my_strlen(client->wd_path + 1) + 7);
  my_strcpy(line + 4, client->wd_path + 1);

  line[0] = '2';
  line[1] = '5';
  line[2] = '7';
  line[3] = ' ';
  line[my_strlen(client->wd_path + 1) + 4] = '\r';
  line[my_strlen(client->wd_path + 1) + 5] = '\n';
  line[my_strlen(client->wd_path + 1) + 6] = '\0';
  answer_raw(*server, client, line, NEED_IDENT);
  return;
}
