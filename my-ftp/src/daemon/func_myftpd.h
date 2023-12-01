#ifndef FUNC_MYFTPD_H_
# define FUNC_MYFTPD_H_

# include "struct_myftpd.h"

/*
** Header : func_myftpd.h
** Here are the exported functions of the server.
*/

/*
** open_log() : Starts the server log.
*/
int      open_log(s_server       s,
                  char           *file);
/*
** close_log() : Ends the server log.
*/
void     close_log(s_server      s);

/*
** print_log() : Prints some lines in the log.
*/
void     print_log(s_server      s,
                   char          *text);

/*
** print_date_log() : Prints the current date in the log.
*/
void     print_date_log(s_server      s);

/*
** print_int_log() : Prints a pretty integer in the log.
*/
void     print_int_log(s_server  s,
		       int       i);

/*
** answer() : Sends a message to the client.
*/
void    answer(s_server s,
               s_client *neo,
               int      numb,
               int      id);

/*
** answer_raw() : Sends a line to the client.
*/
void    answer_raw(s_server     s,
                   s_client     *neo,
                   char         *line,
                   int          id);

/*
** verif_ident() : Does a verification of the client with the level of the
** current security.
*/
int     verif_ident(s_server    s,
                    s_client    *neo,
		    int		secu);

/*
** new_connection() : Creates a new connection.
*/
void    new_connection(s_network        *nw,
                       int              port);

/*
** cmd_noop_myftpd() : Does the server command NOOP.
*/
void    cmd_noop_myftpd(s_server        *server,
                        s_client        *client,
                        char            *buf);

/*
** cmd_quit_myftpd() : Does the server command QUIT.
*/
void    cmd_quit_myftpd(s_server        *server,
                        s_client        *client,
                        char            *buf);

/*
** cmd_help_myftpd() : Does the server command HELP.
*/
void    cmd_help_myftpd(s_server        *server,
                        s_client        *client,
                        char            *buf);

/*
** cmd_syst_myftpd() : Does the server command SYST.
*/
void    cmd_syst_myftpd(s_server        *server,
                        s_client        *client,
                        char            *buf);

/*
** cmd_pwd_myftpd() : Does the server comand PWD.
*/
void	cmd_pwd_myftpd(s_server		*server,
		       s_client		*client,
		       char		*buf);

/*
** cmd_pwd_myftpd() : Does the server comand CWD.
*/
void    cmd_cwd_myftpd(s_server         *server,
                       s_client         *client,
                       char             *buf);

/*
** cmd_user_myftpd() : Does the server command USER.
*/
void    cmd_user_myftpd(s_server         *server,
			s_client         *client,
			char             *buf);

/*
** cmd_pass_myftpd() : Does the server command PASS.
*/
void    cmd_pass_myftpd(s_server         *server,
                        s_client         *client,
                        char             *buf);

/*
** cmd_type_myftp() : Does the server command TYPE.
*/
void    cmd_type_myftpd(s_server         *server,
                        s_client         *client,
                        char             *buf);

/*
** cmd_port_myftp() : Does the server command PORT.
*/
void    cmd_port_myftpd(s_server         *server,
                        s_client         *client,
                        char             *buf);

/*
** cmd_list_myftp() : Does the server command LIST.
*/
void    cmd_list_myftpd(s_server         *server,
                        s_client         *client,
                        char             *buf);

/*
** cmd_pasv_myftp() : Does the server command PASV.
*/
void    cmd_pasv_myftpd(s_server         *server,
                        s_client         *client,
                        char             *buf);

/*
** cmd_stor_myftpd() : Does the server command STOR.
*/
void    cmd_stor_myftpd(s_server         *server,
                        s_client         *client,
                        char             *buf);

/*
** cmd_retr_myftpd() : Does the server command RETR.
*/
void    cmd_retr_myftpd(s_server         *server,
                        s_client         *client,
                        char             *buf);

/*
** cmd_unknown_myftpd() : Does the error message.
*/
void    cmd_unknown_myftpd(s_server         *server,
			   s_client         *client,
			   char             *buf);

/*
** cmd_nyi_myftpd() : Does the Not Yet Implemanted message.
*/
void    cmd_nyi_myftpd(s_server         *server,
		       s_client         *client,
		       char             *buf);

/*
** display_help() : displays the server help.
*/
int    display_help(char	*arg,
		    s_server	*server);

/*
** get_port() : specify the port where the server has to listen to.
*/
int	get_port(char		*arg,
		 s_server	*server);

/*
** become_a_daemon() : Becomes a little imp !
*/
int     become_a_daemon(char           *arg,
                        s_server       *server);

/*
** write_a_log() : Write what's going on in the log.
*/
int     write_a_log(char        *arg,
                    s_server    *server);

/*
** my_listdir() : Sends the list of the files.
*/
int             my_listdir(char *dirname,
                           int  sock);

/*
** End of the header func_myftpd.h
*/

#endif /* !FUNC_MYFTPD_H_ */
