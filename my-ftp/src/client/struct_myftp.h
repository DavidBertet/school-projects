#ifndef STRUCT_MYFTP_H_
# define STRUCT_MYFTP_H_

# include "../inc_myftp_myftpd.h"
# include "../tools_str_myftp_myftpd.h"
# include "../tools_opt_myftp_myftpd.h"

/*
** Header : struct_myftp.h
** Here are the structures made for this tiny FTP client.
*/

struct                  s_user
{
  int                   data_sock;
  int                   data_sock_actif;
  int                   cmd_sock;
  int                   port;
  int                   data_port;
  int                   current_data_port;
  int                   pasv;
  int                   last_state;
  char                  *host;
  char                  *type;
  struct sockaddr       *sockaddr;
};

struct		s_cmd
{
  char          *cmd;
  int           nb_args;
  void          (*func)(char	*, struct s_user	*);
};

/*
** End of the header struct_myftp.h
*/

#endif /* !STRUCT_MYFTP_H_ */
