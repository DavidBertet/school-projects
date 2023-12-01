#ifndef STRUCT_MYFTPD_H_
# define STRUCT_MYFTPD_H_

# include "../inc_myftp_myftpd.h"
# include "../tools_str_myftp_myftpd.h"
# include "../tools_opt_myftp_myftpd.h"

/*
** Header : struct_myftpd.h
** Here are the structures made for this tiny FTP server.
*/

/*
** s_network : handles a connection.
*/
struct	network
{
  struct sockaddr_in    *saddrin;
  struct sockaddr       *saddr;
  int                   port;
  int			listen;
  int			sock;
  int			p_sock;
  char			*ip;
};

typedef struct network	s_network;

/*
** s_client : registers a client.
*/
struct	client
{
  s_network	net[2];
  int		ident;
  int		is_pasv;
  char		*name;
  char		*pass;
  char		*wd_path;
  char		type;
};

typedef struct client	s_client;

/*
** s_asw : handles an answer from the server.
*/
struct		asw
{
  char          *cmd;
  void          (*func)(s_server *, s_client *, char *);
};

typedef struct asw	s_asw;

/*
** s_msg : handles the list of the messages.
*/
struct		msg
{
  int           number;
  char          *text;
};

typedef struct msg	s_msg;

/*
** End of the header struct_myftpd.h
*/

#endif /* !STRUCT_MYFTPD_H_ */
