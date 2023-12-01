#ifndef FUNC_MYFTP_H_
# define FUNC_MYFTP_H_

# include "struct_myftp.h"

/*
** Header : func_myftp.h
** Here are the exported functions of the client.
*/

/*
** func_auto() : connect an anonymous user.
*/
void    func_auto(char          *arg,
                  struct s_user *user);

/*
** func_cd() : sends cd command.
*/
void    func_cd(char            *arg,
                struct s_user   *user);

/*
** is_valid_cmd() : indicates if a command is valid.
*/
int     is_valid_cmd(char       *str);

/*
** send_cmd() : sends a commands.
*/
void    send_cmd(int    sock,
                 char   *cmd);

/*
** func_delete() : sends delete command.
*/
void    func_delete(char                *arg,
                    struct s_user       *user);

/*
** func_get() : sends get command.
*/
void    func_get(char           *arg,
                 struct s_user  *user);

/*
** func_help() : sends help command.
*/
void    func_help(char          *arg,
                  struct s_user *user);

/*
** get_host_ip() : gets host ip in a table.
*/
char    **get_host_ip(void);

/*
** init_user() : inits struct user.
*/
struct s_user   *init_user(void);

/*
** func_ls() : sends ls command.
*/
void            func_ls(char            *arg,
                        struct s_user   *user);

/*
** func_mkdir() : sends mkdir command.
*/
void    func_mkdir(char                 *arg,
                   struct s_user        *user);

/*
** func_noop() : sends noop command.
*/
void    func_noop(char          *arg,
                  struct s_user *user);

/*
** func_pass() : sends pass command.
*/
void    func_pass(char          *arg,
                  struct s_user *user);

/*
** func_pasv() : sends pasv command.
*/
void    func_pasv(char          *arg,
                  struct s_user *user);

/*
** func_port() : sends port command.
*/
void    func_port(char          *arg,
                  struct s_user *user);

/*
** print_prompt() : prints a prompt.
*/
char    *print_prompt(void);

/*
** func_put() : sends put command.
*/
void    func_put(char           *arg,
                 struct s_user  *user);

/*
** func_pwd() : sends pwd command.
*/
void    func_pwd(char           *arg,
                 struct s_user  *user);

/*
** func_quit() : sends quit command.
*/
void    func_quit(char          *arg,
                  struct s_user *user);

/*
** func_retr() : sends retr command.
*/
void    func_retr(char          *arg,
                  struct s_user *user);

/*
** func_rmdir() : sends rmdir command.
*/
void    func_rmdir(char                 *arg,
                   struct s_user        *user);

/*
** connect_socket() : creates a client side socket.
*/
int     connect_socket(unsigned short           port,
                       const char               *serveur);

/*
** deconnect_socket() : deconnects a socket.
*/
int     deconnect_socket(int    sock);

/*
** socket_server() : creates a server side socket.
*/
void    socket_server(struct s_user     *user,
                      int               port);

/*
** func_stor() : sends stor command.
*/
void    func_stor(char          *arg,
                  struct s_user *user);

/*
** func_syst() : sends syst command.
*/
void    func_syst(char          *arg,
                  struct s_user *user);

/*
** func_type() : sends type command.
*/
void    func_type(char          *arg,
                  struct s_user *user);

/*
** func_user() : sends user command.
*/
void    func_user(char          *arg,
                  struct s_user *user);

/*
** print_cmd() : put a string before the command and print it on screen.
*/
void    print_cmd(char  *cmd);

/*
** read_socket() : reads in a socket.
*/
char	*read_socket(int        sock);

/*
** get_state() : gets state in server response.
*/
int     get_state(char  *response);

/*
** my_uppercase_cmd() : uppercase command like cmd arg in CMD arg.
*/
void    my_uppercase_cmd(char   *str);

/*
** print_string() : prints a string.
*/
void    print_string(char       *str,
                     int        fd,
                     int        size);

/*
** prep_port() :
*/
char    *prep_port(struct s_user        *user);

/*
** get_filename() : find filename in XXX /xx/xx/file.
*/
char    *get_filename(char      *str);

/*
** manage_arg() : treats -p.
*/
void	manage_arg(int                  argc,
		   char                 **argv,
		   struct s_user        *user);

/*
** is_end_cmd() : find string like xxx(SP) where x = number.
*/
int     is_end_cmd(char *str);

/*
** End of the header func_myftp.h
*/

#endif /* !FUNC_MYFTP_H_ */
