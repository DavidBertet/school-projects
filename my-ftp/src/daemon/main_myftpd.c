#include "const_myftpd.h"

static void	my_uppercase_cmd(char	*string)
{
  int		i = 0;

  for (; ((string[i] != '\0') && (string[i] != ' ')); i++)
    {
      if ((string[i] >= 'a') && (string[i] <= 'z'))
	string[i] += 'A' - 'a';
    }
  return;
}

static void	execute_command(s_server	*server,
				s_client	*client,
				char		*buf)
{
  int		count = 0;

  for (; ftp_asw[count].cmd != NULL; count++)
    {
      if (my_strcmp(ftp_asw[count].cmd, buf) == 0)
	break;
    }
  if (ftp_asw[count].func != NULL)
    ftp_asw[count].func(server, client, buf);
  else
    cmd_nyi_myftpd(server, client, buf);
  return;
}

static void	init_connection(s_network	*net)
{
  net->saddrin = NULL;
  net->saddr = NULL;
  net->port = 0;
  net->listen = 0;
  net->sock = 0;
  net->ip = NULL;
  net->p_sock = 0;
  return;
}

static void	init_server(s_server	*server,
			    s_client	*client)
{
  server->low_port = LOW_PORT;
  server->high_port = HIGH_PORT;
  server->next_port = server->low_port;
  print_log(*server, "    Starting the server...\n\n");
  init_connection(&(client->net[CMD]));
  init_connection(&(client->net[DATA]));
  new_connection(&(client->net[CMD]), server->cmd_port);
  (server->next_port)++;
  return;
}

static void	wd_path(s_client	*client)
{
  client->wd_path = malloc(3);
  client->wd_path[0] = '.';
  client->wd_path[1] = '/';
  client->wd_path[2] = '\0';
}

static void	welcome_default(s_server	s,
				s_client	*c)
{
  answer_raw(s, c, "220-  ################################\r\n", NO_IDENT);
  answer_raw(s, c, "220- #  _      ___   _      ___   _   #\r\n", NO_IDENT);
  answer_raw(s, c, "220- # |=|    [(_)] |=|    [(_)] |=|  #\r\n", NO_IDENT);
  answer_raw(s, c, "220- # |_|     '-`  |_|     '-`  |_|  #\r\n", NO_IDENT);
  answer_raw(s, c, "220- #   /            /            /  #\r\n", NO_IDENT);
  answer_raw(s, c, "220- #  |____________|____________|   #\r\n", NO_IDENT);
  answer_raw(s, c, "220- #           _ _                  #\r\n", NO_IDENT);
  answer_raw(s, c, "220- #  ___ _ __(_) |_ __ _  myFTP &  #\r\n", NO_IDENT);
  answer_raw(s, c, "220- # / -_) '_ \\ |  _/ _` | myFTPd   #\r\n", NO_IDENT);
  answer_raw(s, c, "220- # \\___| .__/_|\\__\\__,_| GLP1 '08 #\r\n", NO_IDENT);
  answer_raw(s, c, "220- #     |_|                 ING1   #\r\n", NO_IDENT);
  answer_raw(s, c, "220- #                                #\r\n", NO_IDENT);
  answer_raw(s, c, "220- #  ralamb_e  bertet_d  gallet_c  #\r\n", NO_IDENT);
  answer_raw(s, c, "220- #                                #\r\n", NO_IDENT);
  answer_raw(s, c, "220-  ################################\r\n", NO_IDENT);
  answer_raw(s, c, "220-\r\n", NO_IDENT);
}

static void	welcome(s_server	s,
			s_client	*c)
{
  s_stream	*stream;
  char		*buf;
  ssize_t	size;
  size_t	size_tmp = 128;

  stream = lbs_fopen("check/hello", "r");
  if (stream == NULL)
    {
      welcome_default(s, c);
    }
  else
    {
      buf = malloc(128);
      while ((size = lbs_getdelim_str(&buf, &size_tmp, '\n',  stream)) > 0)
	{
	  buf[size - 1] = '\r';
	  buf[size] = '\n';
	  answer_raw(s, c, buf, NO_IDENT);
	  memset(buf, 0, 128);
	}
      lbs_fclose(stream);
    }
  return;
}

static void	init_client(s_server	*server,
			    s_client	*c)
{
  unsigned int	size;

  print_log(*server, "   Listening...\n\n");
  size = sizeof (struct sockaddr_in);
  c->net[CMD].sock = accept(c->net[CMD].listen, c->net[CMD].saddr, &size);
  c->name = malloc(1);
  c->is_pasv = -1;
  c->name[0] = '\0';
  c->pass = malloc(1);
  c->pass[0] = '\0';
  c->ident = 0;
  c->type = 'I';
  wd_path(c);
  print_log(*server, "  Here comes a new challenger !\n");
  print_log(*server, "  His/her id : ");
  print_int_log(*server, c->net[CMD].sock);
  print_log(*server, "\n\n");
  welcome(*server, c);
  answer(*server, c, 220, NO_IDENT);
  return;
}

static void	study_command(s_server	*server,
			      s_client	*client)
{
  int           srvr;
  char		buf[128];

  while (1)
    {
      if (recv(client->net[CMD].sock, buf, 128, 0) < 1)
	break;
      print_date_log(*server);
      print_int_log(*server, client->net[CMD].sock);
      print_log(*server, " => Command received.\n");
      for (srvr = 0; buf[srvr] != '\r'; srvr++)
	;
      buf[srvr] = '\0';
      my_uppercase_cmd(buf);
      execute_command(server, client, buf);
      print_log(*server, "\n");
      if (my_strcmp(buf, "QUIT") == 0)
	break;
    }
  close(client->net[CMD].sock);
  return;
}

int		main(int	argc,
		     char	**argv)
{
  s_server	server;
  s_client	neo;

  argc = argc;
  server.cmd_port = 4242;
  server.is_log = 0;
  if (is_option(argv, gopt, &server) == 2)
    exit(0);
  init_server(&server, &neo);
  while (1)
    {
      init_client(&server, &neo);
      study_command(&server, &neo);
    }
  print_log(server, "End of the server. See you !");
  close_log(server);
  return (0);
}
