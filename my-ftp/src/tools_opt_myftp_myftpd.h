#ifndef TOOLS_OPT_MYFTP_MYFTPD_H_
# define TOOLS_OPT_MYFTP_MYFTPD_H_

# include "inc_myftp_myftpd.h"

/*
** Header : tools_opt_myftp_myftpd.h
** Here are the exported functions for the options in
** the FTP server.
*/

/*
** s_server : all the variables for the server.
*/
struct	server
{
  int	cmd_port;
  int	next_port;
  int	fd_log;
  int	is_log;
  int	low_port;
  int	high_port;
};

typedef struct server	s_server;

typedef int (*f_my_func)(char	*arg, s_server	*server);

/*
** s_opt : the options of the binaries.
*/
typedef struct s_opt	s_opt;

struct		s_opt
{
  char		*opt_name;
  int		nb_arg;
  f_my_func	my_func;
  char		*description;
};

/*
** is_opt() :  indicates if an options is present in a command and.
*/

int	is_option(char		**command,
		  const s_opt	*g_opt,
		  s_server	*server);


#endif /* !TOOLS_OPT_MYFTP_MYFTPD_H_ */
