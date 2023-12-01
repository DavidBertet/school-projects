#include "const_myftpd.h"

static char     *msg(int        numb)
{
  int           i = 0;

  for (; ftp_msg[i].number != -1; i++)
    {
      if (ftp_msg[i].number == numb)
        break;
    }
  return (ftp_msg[i].text);
}

static void	ident_ok(s_server	s,
			 s_client	*neo,
			 int		secu)
{
  print_log(s, "     |_ Success of the identification\n");
  print_log(s, "       |_ Security level : ");
  print_int_log(s, secu);
  print_log(s, "\n");
  print_log(s, "         |_ <");
  print_log(s, neo->name);
  print_log(s, " / ");
  print_log(s, neo->pass);
  print_log(s, ">\n");
  return;
}

static void	ident_nope(s_server	s,
			   s_client	*neo,
			   int		secu)
{
  print_log(s, "     |_ Fail of the identification\n");
  print_log(s, "       |_ Security level : ");
  print_int_log(s, secu);
  print_log(s, "\n");
  print_log(s, "         |_ <");
  print_log(s, neo->name);
  print_log(s, " / ");
  print_log(s, neo->pass);
  print_log(s, ">\n");
  return;
}

int     verif_ident(s_server    s,
                    s_client    *neo,
		    int		secu)
{
  if (neo->ident < secu)
    {
      if (!strcmp(neo->name, "anonymous"))
        neo->ident = NEED_IDENT;
      if ((!strcmp(neo->name, "Tigrou")) && (!strcmp(neo->pass, "acu")))
        neo->ident = ROOT_IDENT;
      if ((!strcmp(neo->name, "root")) && (!strcmp(neo->pass, "lol")))
        neo->ident = ROOT_IDENT;
      if (neo->ident >= secu)
	ident_ok(s, neo, secu);
      else
        {
          ident_nope(s, neo, secu);
	  send((*neo).net[CMD].sock, msg(530), my_strlen(msg(530)), 0);
          return (0);
        }
    }
  return (1);
}

void    answer(s_server s,
               s_client *neo,
               int      numb,
               int      id)
{
  if (neo->ident < id)
    {
      if (!verif_ident(s, neo, id))
	return;
    }
  send((*neo).net[CMD].sock, msg(numb), my_strlen(msg(numb)), 0);
  return;
}

void    answer_raw(s_server	s,
		   s_client	*neo,
		   char		*line,
		   int		id)
{
  if (neo->ident < id)
    {
      if (!verif_ident(s, neo, id))
	return;
    }
  send(neo->net[CMD].sock, line, my_strlen(line), 0);
  return;
}

void	new_connection(s_network        *nw,
		       int              port)
{
  void	*tmp;

  nw->port = port;
  nw->listen = socket(AF_INET, SOCK_STREAM, 0);
  nw->saddrin = malloc(sizeof (struct sockaddr_in));
  nw->saddrin->sin_family = AF_INET;
  nw->saddrin->sin_port = htons(nw->port);
  nw->saddrin->sin_addr.s_addr = INADDR_ANY;
  tmp = nw->saddrin;
  nw->saddr = tmp;
  bind(nw->listen, nw->saddr, sizeof (struct sockaddr_in));
  listen(nw->listen, 0);
  return;
}
