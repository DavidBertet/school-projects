#include "const_myftpd.h"

static void	type_gtfo(s_server	*server,
			  s_client	*client,
			  char		*buf)
{
  print_log(*server, "   |_ Error : wrong type\n");
  print_log(*server, "     |_ TYPE : <");
  print_log(*server, &(buf[5]));
  print_log(*server, ">\n");
  answer(*server, client, 504, NO_IDENT);
  return;
}

static void     type_ok(s_server      *server,
			s_client      *client,
			char          *buf)
{
  print_log(*server, "   |_ TYPE : <");
  print_log(*server, &(buf[5]));
  print_log(*server, ">\n");
  client->type = buf[5];
  answer(*server, client, 200, NEED_IDENT);
  return;
}

void	cmd_type_myftpd(s_server	*server,
			s_client	*client,
			char		*buf)
{
  print_log(*server, " |_ Command : TYPE\n");
  if (my_strlen(buf) != 6)
    {
      print_log(*server, "   |_ Error : wrong argument\n");
      answer(*server, client, 501, NO_IDENT);
    }
  else
    {
      if (verif_ident(*server, client, ROOT_IDENT))
	{
	  if ((buf[5] >= 'a') && (buf[5] <= 'z'))
	    buf[5] += 'A' - 'a';
	  if ((buf[5] != 'A') && (buf[5] != 'I'))
	    type_gtfo(server, client, buf);
	  else
	    type_ok(server, client, buf);
	}
    }
  return;
}
